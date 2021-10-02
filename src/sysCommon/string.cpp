#include "string.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
//void String::isSame(char *)
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
	u8 *str = this->m_str;
	int len = 0;
	while (*(str++))
		len++;
	return len;

	/*
.loc_0x0:
  lwz       r4, 0x4(r3)
  li        r3, 0
  b         .loc_0x10

.loc_0xC:
  addi      r3, r3, 0x1

.loc_0x10:
  lbz       r0, 0x0(r4)
  addi      r4, r4, 0x1
  cmplwi    r0, 0
  bne+      .loc_0xC
  blr
*/
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