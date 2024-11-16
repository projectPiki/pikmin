#ifndef _CMDSTREAM_H
#define _CMDSTREAM_H

#include "Stream.h"

/**
 * @struct CmdStream
 * @brief Represents a command stream.
 *
 * @note Size: 0x11C.
 */
struct CmdStream {
	/**
	 * @brief Default constructor.
	 */
	CmdStream();

	/**
	 * @brief Constructor that takes a Stream object.
	 * @param stream The Stream object to initialize the CmdStream with.
	 */
	CmdStream(Stream* stream);

	/**
	 * @brief Skips the current line in the command stream.
	 * @return A pointer to the next line in the command stream.
	 */
	char* skipLine();

	/**
	 * @brief Retrieves the next token from the command stream.
	 * @param skipWhitespace Flag indicating whether to skip whitespace characters.
	 * @return A pointer to the next token in the command stream.
	 */
	char* getToken(bool skipWhitespace);

	/**
	 * @brief Retrieves the next character from the command stream.
	 * @return The next character in the command stream.
	 */
	char nextChar();

	/**
	 * @brief Fills the buffer with data from the command stream.
	 * @param copyToToken Flag indicating whether to copy data to the current token.
	 */
	void fillBuffer(bool copyToToken);

	/**
	 * @brief Copies data from the buffer to the current token.
	 * @param size The number of bytes to copy.
	 */
	void copyToToken(int size);

	/**
	 * @brief Checks if a character is a whitespace character.
	 * @param c The character to check.
	 * @return True if the character is a whitespace character, false otherwise.
	 */
	bool whiteSpace(char c);

	/**
	 * @brief Checks if the command stream has reached the end of commands.
	 * @return True if the end of commands has been reached, false otherwise.
	 */
	bool endOfCmds();

	/**
	 * @brief Checks if a token matches a given string.
	 * @param token The token to check.
	 * @return True if the token matches the given string, false otherwise.
	 */
	bool isToken(char* token);

	/**
	 * @brief Checks if the current line in the command stream is a comment.
	 * @return True if the current line is a comment, false otherwise.
	 */
	bool LineIsComment();

	/**
	 * @brief Checks if the command stream has reached the end of a section.
	 * @return True if the end of a section has been reached, false otherwise.
	 */
	bool endOfSection();

	/**
	 * @brief Initializes the CmdStream with a Stream object.
	 * @param stream The Stream object to initialize the CmdStream with.
	 */
	inline void init(Stream* stream);

	/**
	 * @brief The static buffer used by the CmdStream.
	 */
	static u8* statbuff;

	Stream* mStream;           // _00
	u8* mBuffer;               // _04
	char mCurrentToken[0x100]; // _08
	int mTotalStreamSize;      // _108
	int mBufferUsed;           // _10C
	int mBufferOffset;         // _110
	int mCurrentPosition;      // _114
	u8 _118[0x4];              // _118, unknown
};

#endif
