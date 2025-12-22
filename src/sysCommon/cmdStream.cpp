#include "CmdStream.h"

#include "DebugLog.h"
#include "stl/mem.h"
#include "stl/string.h"
#include "sysNew.h"

char* CmdStream::statbuff;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("cmdStream")

/**
 * --INFO--
 * Address:	........
 * Size:	0000AC
 * @param stream Backing stream to read from.
 */
void CmdStream::init(Stream* stream)
{
	mBuffer = nullptr;

	if (!CmdStream::statbuff) {
		CmdStream::statbuff = new char[0x8000];
	}

	// One shared static buffer is used for all CmdStream instances.
	memset(CmdStream::statbuff, 0, 0x8000);

	mStream          = stream;
	mTotalStreamSize = mStream->getPending();
	mCurrentPosition = 0;
	mBufferUsed      = 0;
	mBufferOffset    = 0;
	mBuffer          = CmdStream::statbuff;
	fillBuffer(true);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
CmdStream::CmdStream()
{
}

/**
 * @param stream Backing stream to read from.
 */
CmdStream::CmdStream(Stream* stream)
{
	init(stream);
}

/**
 * @brief Refills the internal buffer if needed.
 * @param force When true, always refill; otherwise refill when the read cursor crosses the half-buffer boundary.
 */
void CmdStream::fillBuffer(bool force)
{
	if (force || mCurrentPosition - mBufferOffset >= 0x4000) {
		if (mBufferUsed) {
			// Keep the newest 0x4000 bytes and make room for more.
			memcpy(&mBuffer[mBufferOffset], &mBuffer[mBufferOffset + 0x4000], 0x4000);
			mBuffer -= 0x4000;
			mBufferOffset += 0x4000;
		}

		s32 size = mBufferUsed ? 0x4000 : 0x8000;
		if (mTotalStreamSize - mBufferUsed < size) {
			size = mTotalStreamSize - mBufferUsed;
		}

		mStream->read(&mBuffer[mBufferUsed], size);
		mBufferUsed += size;
	}
}

/**
 * @brief Checks whether a character is treated as a token separator.
 * @param toCheck Character to test.
 * @return True if the character is treated as whitespace/separator.
 */
bool CmdStream::whiteSpace(char toCheck)
{
	if (toCheck == '\0' || toCheck == '\r' || toCheck == '\n' || toCheck == '\t' || toCheck == ' ' || toCheck == ',') {
		return true;
	}

	return false;
}

/**
 * @brief Advances past whitespace and checks for end-of-commands sentinel.
 * @return True if at end of stream or a terminator byte is encountered.
 */
bool CmdStream::endOfCmds()
{
	fillBuffer(false);

	while (mCurrentPosition < mTotalStreamSize && whiteSpace(mBuffer[mCurrentPosition])) {
		mCurrentPosition++;
	}

	if (mCurrentPosition < mTotalStreamSize) {
		if (mBuffer[mCurrentPosition] == -1) {
			return true;
		}

		return false;
	}

	return true;
}

/**
 * --INFO--
 * Address:	........
 * Size:	00003C
 * @brief Checks whether the current line starts with a comment marker ('#' or '//').
 * @return True if the current line is a comment.
 */
bool CmdStream::LineIsComment()
{
	if (mBuffer[mCurrentPosition] == '#' || mBuffer[mCurrentPosition] == '/' && mBuffer[mCurrentPosition + 1] == '/') {
		return true;
	}

	return false;
}

/**
 * @brief Copies a span from the buffer into the token buffer, normalizing tabs.
 * @param length Number of characters to copy.
 */
void CmdStream::copyToToken(int length)
{
	int i = 0;
	for (; i < length; i++) {
		char currCharOfToken = mBuffer[mCurrentPosition + i];
		if (currCharOfToken == '\t') {
			currCharOfToken = ' ';
		}

		mCurrentToken[i] = currCharOfToken;
	}

	mCurrentToken[i] = '\0';
}

/**
 * @brief Copies the remainder of the current line into the token buffer and advances to the next line.
 * @return Pointer to the token buffer containing the skipped line.
 */
immut char* CmdStream::skipLine()
{
	fillBuffer(false);

	int currentPos = mCurrentPosition;
	while (currentPos < mTotalStreamSize && mBuffer[currentPos] != '\n' && mBuffer[currentPos] != '\r') {
		currentPos++;
	}

	copyToToken(currentPos - mCurrentPosition);

	// Skip line terminators (handles both '\n' and '\r').
	while (mBuffer[currentPos] == '\n' || mBuffer[currentPos] == '\r') {
		currentPos++;
	}

	mCurrentPosition = currentPos;

	return mCurrentToken;
}

/**
 * @brief Parses and returns the next token from the stream.
 * @param skipComments When true, comment lines are skipped before tokenization.
 * @return Pointer to the token buffer containing the next token.
 */
immut char* CmdStream::getToken(bool skipComments)
{
	fillBuffer(false);

	if (skipComments) {
		while (LineIsComment()) {
			skipLine();
		}
	}

	int currChar            = mCurrentPosition;
	bool tokenInParenthesis = 0;

	if (mBuffer[currChar] == '"' || mBuffer[currChar] == '\'') {
		// Quoted token: consume until the matching quote.
		tokenInParenthesis = true;
		++currChar;
		++mCurrentPosition;
	}

	for (; tokenInParenthesis ? (mBuffer[currChar] != '"' && mBuffer[currChar] != '\'') : !whiteSpace(mBuffer[currChar]);) {
		currChar++;
	}

	copyToToken(currChar - mCurrentPosition);

	if (tokenInParenthesis) {
		mCurrentToken[currChar - mCurrentPosition] = 0;
		currChar++;
	}

	// Consume separators after the token.
	while (currChar < mTotalStreamSize && whiteSpace(mBuffer[currChar])) {
		currChar++;
	}

	mCurrentPosition = currChar;
	return mCurrentToken;
}

/**
 * --INFO--
 * Address:	........
 * Size:	000010
 * @brief Returns the current character without advancing.
 * @return Current character at the read cursor.
 */
char CmdStream::nextChar()
{
	return mBuffer[mCurrentPosition];
}

/**
 * @brief Compares the current token buffer to a string.
 * @param str String to compare against the current token.
 * @return True if the token matches exactly.
 */
bool CmdStream::isToken(immut char* str)
{
	if (strlen(mCurrentToken) == 0 || strlen(mCurrentToken) != strlen(str)) {
		return false;
	}

	for (s32 i = 0; i < (s32)strlen(mCurrentToken); i++) {
		if (mCurrentToken[i] != str[i]) {
			return false;
		}
	}

	return true;
}

/**
 * @brief Checks whether the next non-buffer-refill character ends a section.
 * @return True if the next character is '}'.
 */
bool CmdStream::endOfSection()
{
	fillBuffer(false);

	if (mBuffer[mCurrentPosition] == '}') {
		return true;
	}

	return false;
}
