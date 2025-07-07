#include "teki.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Peve/MotionEvents.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("tekinakata")

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
TekiMessage::TekiMessage(int p1, NTeki* teki)
{
	_00   = p1;
	mTeki = teki;
}

/*
 * --INFO--
 * Address:	8014B9F8
 * Size:	000114
 */
NTeki::NTeki()
{
	mParabolaEvent   = new PeveParabolaEvent();
	mAccelEvent      = new PeveAccelerationEvent();
	mCircleMoveEvent = new PeveCircleMoveEvent();
	mSinWaveEvent    = new PeveHorizontalSinWaveEvent();
}

/*
 * --INFO--
 * Address:	8014BB0C
 * Size:	0001D4
 */
void NTeki::sendMessage(int msg)
{
	PRINT("sendMessage:%08x:%d\n", this, msg);
	Iterator iter(tekiMgr);
	CI_LOOP(iter)
	{
		NTeki* target = (NTeki*)*iter;
		if (target != this) {
			f32 dist = calcSphereDistance(*target);
			if (dist <= getParameterF(TPF_MessageRange)) {
				target->receiveMessage(TekiMessage(msg, this));
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8014BCE0
 * Size:	000054
 */
void NTeki::receiveMessage(TekiMessage& msg)
{
	eventPerformed(TekiEvent(4, static_cast<Teki*>(this), msg.mTeki));
}
