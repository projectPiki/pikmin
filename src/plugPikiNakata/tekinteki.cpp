#include "teki.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Peve/MotionEvents.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("tekinakata")

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
TekiMessage::TekiMessage(int p1, NTeki* teki)
{
	_00   = p1;
	mTeki = teki;
}

/**
 * @TODO: Documentation
 */
NTeki::NTeki()
{
	mParabolaEvent   = new PeveParabolaEvent();
	mAccelEvent      = new PeveAccelerationEvent();
	mCircleMoveEvent = new PeveCircleMoveEvent();
	mSinWaveEvent    = new PeveHorizontalSinWaveEvent();
}

/**
 * @TODO: Documentation
 */
void NTeki::sendMessage(int msg)
{
	PRINT_NAKATA("sendMessage:%08x:%d\n", this, msg);
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

/**
 * @TODO: Documentation
 */
void NTeki::receiveMessage(immut TekiMessage& msg)
{
	eventPerformed(TekiEvent(TekiEventType::WakeUpCall, static_cast<Teki*>(this), msg.mTeki));
}
