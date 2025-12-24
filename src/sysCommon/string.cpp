#include "Common/String.h"
#include <Stream.h>

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
f32 String::toFloat()
{
	return 0.0f;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00012C
 */
int String::toInt()
{
	const char* str = mString;
	int result      = 0;
	bool isNegative = false;

	// Check for hexadecimal prefix "0x"
	if (str[0] == '0' && str[1] == 'x') {
		str += 2; // Skip "0x"

		while (*str) {
			char c = *str;
			int digitValue;

			if (c >= '0' && c <= '9') {
				digitValue = c - '0';
			} else if (c >= 'a' && c <= 'f') {
				digitValue = c - 'a' + 10;
			} else if (c >= 'A' && c <= 'F') {
				digitValue = c - 'A' + 10;
			} else {
				return 0; // Invalid character
			}

			result = result * 16 + digitValue;
			str++;
		}

		return result;
	} else {
		// Parse decimal number
		while (*str) {
			char c = *str;

			// Check for minus sign
			if (c == '-') {
				isNegative = true;
				str++;
				continue;
			}

			// Check if it's a digit
			if (c < '0' || c > '9') {
				return 0; // Invalid character
			}

			result = result * 10 + (c - '0');
			str++;
		}

		return isNegative ? -result : result;
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
int String::getLength(char* str)
{
	String tempStr(str, 0);
	return tempStr.getLength();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
bool String::isSame(char* a, char* b)
{
	String aStr(a, 0);
	return aStr.isSame(b);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00005C
 */
char* String::dup(char* s)
{
	char* newStr = new char[String::getLength(s) + 1];
	String::copy(newStr, s);
	return newStr;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000058
 */
// void String::contains(char*, char*)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
char* String::copy(char* a, char* b)
{
	while ((*a++ = *b++))
		;

	return a;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000058
 */
// void String::copyUntil(char*, char*, char, char**)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
void String::concat(char*, char*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
// void String::calcHash(char*)
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
//  void String::toInt(char*)
//  {
// 	 // UNUSED FUNCTION
//  }

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A0
 */
void StringArray::read(Stream&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
 void StringArray::write(Stream&)
 {
	 // UNUSED FUNCTION
 }
