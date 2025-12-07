#include "DebugLog.h"
#include "Peve/Condition.h"
#include "Peve/Event.h"
#include "Peve/IO.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("peve")

/*
 * --INFO--
 * Address:	80125540
 * Size:	000010
 */
PeveCondition::PeveCondition()
{
}

/*
 * --INFO--
 * Address:	80125550
 * Size:	000048
 */
PeveEvent::PeveEvent(int count)
    : NNode(count)
{
	mCondition    = nullptr;
	mEventOptions = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
PeveParallelEvent::PeveParallelEvent(int count)
    : PeveEvent(count)
{
}

/*
 * --INFO--
 * Address:	80125598
 * Size:	000084
 */
void PeveParallelEvent::reset()
{
	PeveEvent::reset();
	for (int i = 0; i < mNodeArray->getSize(); i++) {
		getEvent(i)->reset();
	}
}

/*
 * --INFO--
 * Address:	8012561C
 * Size:	000084
 */
void PeveParallelEvent::update()
{
	PeveEvent::update();
	for (int i = 0; i < mNodeArray->getSize(); i++) {
		getEvent(i)->update();
	}
}

/*
 * --INFO--
 * Address:	801256A0
 * Size:	00007C
 */
bool PeveParallelEvent::isFinished()
{
	for (int i = 0; i < mNodeArray->getSize(); i++) {
		PeveEvent* event = getEvent(i);
		if (!event->isFinished()) {
			return false;
		}
	}
	return true;
}

/*
 * --INFO--
 * Address:	8012571C
 * Size:	000054
 */
PeveSerialEvent::PeveSerialEvent(int count)
    : PeveEvent(count)
{
}

/*
 * --INFO--
 * Address:	80125770
 * Size:	000068
 */
void PeveSerialEvent::reset()
{
	PeveEvent::reset();
	mEventIdx            = 0;
	PeveEvent* currEvent = getCurrentEvent();
	currEvent->reset();
}

/*
 * --INFO--
 * Address:	801257D8
 * Size:	0000CC
 */
void PeveSerialEvent::update()
{
	PeveEvent* currEvent = getCurrentEvent();
	if (currEvent->isFinished()) {
		PRINT_NAKATA("isFinished:%d\n", mEventIdx);
		if (mEventIdx + 1 < getChildCount()) {
			mEventIdx++;
			PeveEvent* newEvent = getCurrentEvent();
			newEvent->reset();
			newEvent->update();
		}
		return;
	}
	currEvent->update();
}

/*
 * --INFO--
 * Address:	801258A4
 * Size:	000074
 */
bool PeveSerialEvent::isFinished()
{
	if (mEventIdx < getChildCount() - 1) {
		return false;
	}

	if (!getCurrentEvent()->isFinished()) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
PeveCameraViewpointIO::PeveCameraViewpointIO()
{
	construct(nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveCameraViewpointIO::construct(PcamCamera* camera)
{
	mCamera = camera;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
PeveCameraWatchpointIO::PeveCameraWatchpointIO()
{
	construct(nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveCameraWatchpointIO::construct(PcamCamera* camera)
{
	mCamera = camera;
}

/*
 * --INFO--
 * Address:	80125918
 * Size:	000050
 */
PeveCameraPostureIO::PeveCameraPostureIO()
{
	construct(nullptr);
}

/*
 * --INFO--
 * Address:	80125968
 * Size:	000008
 */
void PeveCameraPostureIO::construct(PcamCamera* camera)
{
	mCamera = camera;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
PeveCreaturePositionIO::PeveCreaturePositionIO()
{
	construct(nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveCreaturePositionIO::construct(Creature* creature)
{
	mCreature = creature;
}

/*
 * --INFO--
 * Address:	80125970
 * Size:	000060
 */
PeveClampVector3fIO::PeveClampVector3fIO()
{
	construct();
}

/*
 * --INFO--
 * Address:	801259D0
 * Size:	00000C
 */
void PeveClampVector3fIO::construct()
{
	mMaxLength = 1.0f;
}

/*
 * --INFO--
 * Address:	801259DC
 * Size:	0000DC
 */
void PeveClampVector3fIO::input(immut NVector3f& vec)
{
	_04.input(vec);
	f32 len = _04.length();
	if (len > mMaxLength) {
		_04.scale(mMaxLength / len);
	}
}
