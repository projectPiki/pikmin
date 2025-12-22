#include "String.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
bool String::isSame(immut char* str)
{
	const char* currentChar = mString;

	while (*currentChar && *str) {
		if (*currentChar != *str) {
			return false;
		}

		currentChar++;
		str++;
	}

	return !(*currentChar || *str);
}

/**
 * @TODO: Documentation
 */
int String::getLength() immut
{
	const char* str = mString;
	int len         = 0;
	while (*(str++)) {
		len++;
	}

	return len;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
// void String::toFloat()
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00012C
 */
// void String::toInt()
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
// void String::getLength(char *)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
// void String::isSame(char *, char *)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00005C
 */
// void String::dup(char *)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000058
 */
// void String::contains(char *, char *)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
// void String::copy(char *, char *)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000058
 */
// void String::copyUntil(char *, char *, char, char **)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
// void String::concat(char *, char *)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
// void String::calcHash(char *)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
// void String::calcHash()
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
// void String::toInt(char *)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A0
 */
// void StringArray::read(Stream &)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
// void StringArray::write(Stream &)
// {
// 	// UNUSED FUNCTION
// }
