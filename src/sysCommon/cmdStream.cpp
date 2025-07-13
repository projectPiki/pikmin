#include "CmdStream.h"

#include "DebugLog.h"
#include "stl/mem.h"
#include "stl/string.h"
#include "sysNew.h"

u8* CmdStream::statbuff;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("cmdStream")

/**
 * @brief Initializes the CmdStream with the given Stream object.
 *
 * @param stream The Stream object to be used by the CmdStream.
 *
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void CmdStream::init(Stream* stream)
{
	mBuffer = nullptr;

	if (!CmdStream::statbuff) {
		CmdStream::statbuff = new u8[0x8000];
	}

	memset(CmdStream::statbuff, 0, 0x8000);

	mStream          = stream;
	mTotalStreamSize = mStream->getPending();
	mCurrentPosition = 0;
	mBufferUsed      = 0;
	mBufferOffset    = 0;
	mBuffer          = CmdStream::statbuff;
	fillBuffer(true);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
CmdStream::CmdStream()
{
}

/*
 * --INFO--
 * Address:	80040B7C
 * Size:	0000B0
 */
CmdStream::CmdStream(Stream* stream)
{
	init(stream);
}

/**
 * @brief Fills the buffer of the command stream.
 *
 * This function is responsible for filling the buffer of the command stream.
 * If the 'force' parameter is set to true, the buffer will be filled regardless of its current state.
 *
 * @param force Indicates whether to force the buffer to be filled.
 *
 * --INFO--
 * Address:	80040C2C
 * Size:	0000EC
 */
void CmdStream::fillBuffer(bool force)
{
	if (force || mCurrentPosition - mBufferOffset >= 0x4000) {
		if (mBufferUsed) {
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
 * Checks if the given character is a white space.
 *
 * @param toCheck The character to be checked.
 * @return True if the character is a white space, false otherwise.
 *
 * --INFO--
 * Address:	80040D18
 * Size:	000040
 */
bool CmdStream::whiteSpace(char toCheck)
{
	if (toCheck == '\0' || toCheck == '\r' || toCheck == '\n' || toCheck == '\t' || toCheck == ' ' || toCheck == ',') {
		return true;
	}

	return false;
}

/**
 * @brief Checks if the end of the commands in the stream has been reached.
 *
 * This function fills the buffer and then skips any whitespace characters in the stream.
 *
 * @return true if the end of the commands has been reached, false otherwise.
 *
 * --INFO--
 * Address:	80040D58
 * Size:	000174
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
 * Checks if the current line in the command stream is a comment.
 * A line is considered a comment if it starts with '#' or '//' characters.
 *
 * @return true if the line is a comment, false otherwise.
 *
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
bool CmdStream::LineIsComment()
{
	if (mBuffer[mCurrentPosition] == '#' || mBuffer[mCurrentPosition] == '/' && mBuffer[mCurrentPosition + 1] == '/') {
		return true;
	}

	return false;
}

/**
 * Copies a specified number of characters from the buffer to the current token.
 * Replaces any tab characters with spaces.
 *
 * @param length The number of characters to copy.
 *
 * --INFO--
 * Address:	80040ECC
 * Size:	000050
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
 * Skips the current line in the command stream and returns a pointer to the next line.
 *
 * @return A pointer to the next line in the command stream.
 *
 * --INFO--
 * Address:	80040F1C
 * Size:	000194
 */
char* CmdStream::skipLine()
{
	fillBuffer(false);

	int currentPos = mCurrentPosition;
	while (currentPos < mTotalStreamSize && mBuffer[currentPos] != '\n' && mBuffer[currentPos] != '\r') {
		currentPos++;
	}

	copyToToken(currentPos - mCurrentPosition);

	while (mBuffer[currentPos] == '\n' || mBuffer[currentPos] == '\r') {
		currentPos++;
	}

	mCurrentPosition = currentPos;

	return mCurrentToken;
}

/**
 * Retrieves the next token from the command stream.
 *
 * @param hasComments Flag indicating whether to skip comment lines.
 * @return Pointer to the next token in the command stream.
 *
 * --INFO--
 * Address:	800410B0
 * Size:	000324
 */
char* CmdStream::getToken(bool skipComments)
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

	while (currChar < mTotalStreamSize && whiteSpace(mBuffer[currChar])) {
		currChar++;
	}

	mCurrentPosition = currChar;
	return mCurrentToken;
}

/**
 * Returns the current character in the command stream buffer.
 *
 * @return The current character in the buffer.
 *
 * --INFO--
 * Address:	........
 * Size:	000010
 */
char CmdStream::nextChar()
{
	return mBuffer[mCurrentPosition];
}

/**
 * Checks if the given string matches the current token.
 *
 * @param str The string to compare with the current token.
 * @return True if the string matches the current token, false otherwise.
 *
 * --INFO--
 * Address:	800413D4
 * Size:	0000B4
 */
bool CmdStream::isToken(char* str)
{
	if (!strlen(mCurrentToken) || strlen(mCurrentToken) != strlen(str)) {
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
 * Checks if the current position in the command stream buffer is at the end of a section.
 *
 * @return true if the current position is at the end of a section, false otherwise.
 *
 * --INFO--
 * Address:	80041488
 * Size:	0000FC
 */
bool CmdStream::endOfSection()
{
	fillBuffer(false);

	if (mBuffer[mCurrentPosition] == '}') {
		return true;
	}

	return false;
}
