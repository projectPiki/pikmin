#ifndef _ID32_H
#define _ID32_H

#include "types.h"

/**
 * @brief Represents a 32-bit identifier with associated string ID.
 * @size 0xC bytes
 */
struct ID32 {
	/**
	 * @brief Default constructor.
	 */
	ID32(void);

	/**
	 * @brief Constructor that initializes the ID32 with the given value.
	 * @param id The initial value for the ID32.
	 */
	ID32(u32 id);

	/**
	 * @brief Assignment operator that sets the ID32 to the given value.
	 * @param id The value to assign to the ID32.
	 */
	void operator=(u32 id);

	/**
	 * @brief Equality operator that checks if the ID32 is equal to the given value.
	 * @param id The value to compare with the ID32.
	 * @return True if the ID32 is equal to the given value, false otherwise.
	 */
	bool operator==(u32 id);

	/**
	 * @brief Inequality operator that checks if the ID32 is not equal to the given value.
	 * @param id The value to compare with the ID32.
	 * @return True if the ID32 is not equal to the given value, false otherwise.
	 */
	bool operator!=(u32 id);

	/**
	 * @brief Checks if the ID32 matches the given value and character.
	 * @param id The value to compare with the ID32.
	 * @param c The character to compare with the ID32's string ID.
	 * @return True if the ID32 matches the given value and character, false otherwise.
	 */
	bool match(u32 id, char c);

	/**
	 * @brief Prints the ID32's value and string ID to the console.
	 */
	void print(void);

	/**
	 * @brief Reads the ID32's value and string ID from the given random access stream.
	 * @param stream The random access stream to read from.
	 */
	void read(struct RandomAccessStream& stream);

	/**
	 * @brief Sets the ID32's value to the given value.
	 * @param id The value to set as the ID32's value.
	 */
	void setID(u32 id);

	/**
	 * @brief Formats the ID32's string ID into the given character array.
	 * @param str The character array to store the formatted string ID.
	 */
	void sprint(char* str);

	/**
	 * @brief Updates the ID32's value based on its string ID.
	 */
	void updateID(void);

	/**
	 * @brief Updates the ID32's string ID based on its value.
	 */
	void updateString(void);

	/**
	 * @brief Writes the ID32's value and string ID to the given random access stream.
	 * @param stream The random access stream to write to.
	 */
	void write(RandomAccessStream& stream);

	u32 mId;           // _00
	char mStringID[5]; // _04
};

#endif
