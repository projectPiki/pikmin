#include "TAIanimation.h"

/*
 * --INFO--
 * Address:	801A3594
 * Size:	00003C
 */
AnimInfo* TAIanimation::addAnimation(char* param_1)
{
	m_animinfo = m_animmgr->addAnimation(param_1, true);
	return m_animinfo;
}
