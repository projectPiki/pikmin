#include "types.h"
#include "RefCountable.h"
char file[] = __FILE__;
char name[] = "smartPtr";

/*
 * --INFO--
 * Address:	800E4338
 * Size:	000018
 */
RefCountable::RefCountable() { m_count = 0; }

/*
 * --INFO--
 * Address:	800E4350
 * Size:	00000C
 */
void RefCountable::clearCnt() { m_count = 0; }

/*
 * --INFO--
 * Address:	800E435C
 * Size:	000010
 */
void RefCountable::addCnt() { m_count++; }

/*
 * --INFO--
 * Address:	800E436C
 * Size:	000024
 */
void RefCountable::subCnt()
{
	m_count--;
	if (m_count >= 0) {
		return;
	}
	m_count = 0;
	return;
}
