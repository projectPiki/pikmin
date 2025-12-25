#include "Common/String.h"
#include <Stream.h>

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
bool String::isSame(immut char* str) immut
{
	// UNUSED FUNCTION (Matching by size)
	const char* currentChar = mString;
	while (*currentChar && *str) {
		if (*currentChar++ != *str++) {
			return false;
		}
	}

	bool failed;
	if (*currentChar == '\0' && *str == '\0') {
		failed = false;
	} else {
		failed = true;
	}
	return !failed;
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
 * @brief This function was never implemented; it just returns 0.0f.
 * @note UNUSED Size: 000008
 */
float String::toFloat() immut
{
	// UNUSED FUNCTION (Matching by size)
	return 0.0f;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00012C
 */
int String::toInt() immut
{
	// UNUSED FUNCTION (Matching by size)
	char c;
	int result;

	const char* str = mString;
	int prevResult  = 0;
	bool isNegative = false;

	// Check for hexadecimal prefix "0x"
	if (str[0] == '0' && str[1] == 'x') {
		result = 0;
		str += 2; // Skip "0x"

		// Parse hexadecimal number
		while ((c = *str++)) {
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

			result += digitValue;
			if (*str != '\0') {
				// The DLL says a left-shift was used, and it wouldn't lie, right?
				result <<= 4; // Multiply by 16
			}
		}
	} else {
		// Parse decimal number
		while (true) { // Did you know MSVC without optimizations will write `while (true)` as `MOV EAX, 1`, `TEST EAX, EAX`, and `JZ`?
			c = *str++;

			// Check if it's a digit
			if ((c < '0' || c > '9') && c != '-') {
				return 0; // Invalid character
			}

			// Check for minus sign
			if (c == '-') {
				isNegative = true;
				continue;
			}

			// The pointless updating of `prevResult` is what was missing to match by size (and is shown in the assembly of the DLL).
			result = (prevResult += c - '0');
			if (*str == '\0' || *str == '.' || *str < '0' || *str > '9') {
				break;
			}
			prevResult = result * 10;
		}
		if (isNegative) {
			result = -result;
		}
	}
	return result;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
int String::getLength(immut char* str)
{
	// UNUSED FUNCTION (Matching by size)
	String tempStr(const_cast<char*>(str), 0);
	return tempStr.getLength();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
bool String::isSame(immut char* a, immut char* b)
{
	// UNUSED FUNCTION (Matching by size)
	String aStr(const_cast<char*>(a), 0);
	return aStr.isSame(b);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00005C
 */
char* String::dup(immut char* str)
{
	// UNUSED FUNCTION (Matching by size)
	char* newStr = new char[getLength(str) + 1];
	copy(newStr, str);
	return newStr;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000058
 */
bool String::contains(immut char* str, immut char* substr)
{
	// UNUSED FUNCTION (Matching by size)
#if defined(BUGFIX)
	const char* submatchStart = str;
#endif
	const char* substrBackup = substr;
	while (*str && *substr) {
		if (*str++ == *substr++) {
			if (*substr == '\0') {
				return true;
			}
		} else {
			// Consider `str` = "112" and `substr` = "12".  The character at index 1 of `str` is skipped, so the submatch isn't found.
#if defined(BUGFIX)
			str = ++submatchStart;
#endif
			substr = substrBackup;
		}
	}

	// This is to handle the case in which `substr` = "".
	return TERNARY_BUGFIX(*substrBackup == '\0', false);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
char* String::copy(char* out, immut char* str)
{
	// UNUSED FUNCTION (Matching by size)
	while ((*out++ = *str++)) { }
	return out;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000058
 */
bool String::copyUntil(char* out, immut char* str, char delim, immut char** end)
{
	// UNUSED FUNCTION (Matching by size)
	while (*str != delim && *str != '\0') {
		*out++ = *str++;
	}
	*out = '\0';
	if (end != nullptr) {
		*end = str;
	}
	return *str == delim;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
void String::concat(char* out, immut char* str)
{
	// UNUSED FUNCTION (Matching by size)
	while (*out++) { }          // Loop until one-past-end of `out`.
	out--;                      // Backtrack by one character.
	while (*out++ = *str++) { } // Concatenate.
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
u32 String::calcHash(immut char* str)
{
	// UNUSED FUNCTION (Matching by size)
	String tempStr(const_cast<char*>(str), 0);
	return tempStr.calcHash();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
u32 String::calcHash() immut
{
	// UNUSED FUNCTION (Matching by size)
	u32 hash                = 0;
	const char* currentChar = mString;
	while (*currentChar) {
		hash = (hash << 4) + *currentChar++;

		u32 highNibble = hash & 0xf0000000;
		if (highNibble != 0) {
			hash ^= highNibble >> 24;
		}
		hash &= ~highNibble;
	}
	return hash;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
int String::toInt(immut char* str)
{
	// UNUSED FUNCTION (Matching by size)
	String tempStr(const_cast<char*>(str), 0);
	return tempStr.toInt();
}

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
