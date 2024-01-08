#include "String.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
// void String::isSame(char *)
//{
// UNUSED FUNCTION
//}

/*
 * --INFO--
 * Address:	800258F0
 * Size:	000024
 */
int String::getLength()
{
	u8* str = (u8*)this->mStr;
	int len = 0;
	while (*(str++)) {
		len++;
	}
	return len;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
// void String::toFloat()
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	........
 * Size:	00012C
 */
// void String::toInt()
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000024
//  */
// void String::getLength(char *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00006C
//  */
// void String::isSame(char *, char *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00005C
//  */
// void String::dup(char *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000058
//  */
// void String::contains(char *, char *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00001C
//  */
// void String::copy(char *, char *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000058
//  */
// void String::copyUntil(char *, char *, char, char **)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000030
//  */
// void String::concat(char *, char *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000030
//  */
// void String::calcHash(char *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000040
//  */
// void String::calcHash()
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	000030
//  */
// void String::toInt(char *)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	0000A0
//  */
// void StringArray::read(Stream &)
// {
// 	// UNUSED FUNCTION
// }

// /*
//  * --INFO--
//  * Address:	........
//  * Size:	00009C
//  */
// void StringArray::write(Stream &)
// {
// 	// UNUSED FUNCTION
// }
