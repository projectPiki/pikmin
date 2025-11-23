#ifndef _ID32_H
#define _ID32_H

#include "types.h"

struct AgeServer;
struct RandomAccessStream;

/**
 * @brief Represents a 32-bit identifier with associated string ID.
 *
 * @note Size: 0xC.
 */
struct ID32 {
	/**
	 * @brief Default constructor.
	 */
	ID32();

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
	 * @brief Checks if the given ID matches the ID stored in the ID32 object.
	 * @param id The value to compare against the ID32.
	 * @param wild The alternative "wildcard" character to compare against.  Default is '*'.
	 * @return true if the given ID matches the stored ID, false otherwise.
	 */
	bool match(u32 id, char wild = '*');

	/**
	 * @brief Prints the ID32's value and string ID to the console.
	 */
	void print();

	/**
	 * @brief Reads the ID32's value and string ID from the given random access stream.
	 * @param stream The random access stream to read from.
	 */
	void read(RandomAccessStream& stream);

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
	void updateID();

	/**
	 * @brief Updates the ID32's string ID based on its value.
	 */
	void updateString();

	/**
	 * @brief Writes the ID32's value and string ID to the given random access stream.
	 * @param stream The random access stream to write to.
	 */
	void write(RandomAccessStream& stream);

	void genAge(AgeServer&, char*);
	void ageChangeID() { updateID(); }

	u32 mId;           // _00
	char mStringID[5]; // _04
};

#endif
