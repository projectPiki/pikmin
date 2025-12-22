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

PeveCondition::PeveCondition()
{
}

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

void PeveParallelEvent::reset()
{
	PeveEvent::reset();
	for (int i = 0; i < mNodeArray->getSize(); i++) {
		getEvent(i)->reset();
	}
}

void PeveParallelEvent::update()
{
	PeveEvent::update();
	for (int i = 0; i < mNodeArray->getSize(); i++) {
		getEvent(i)->update();
	}
}

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

PeveSerialEvent::PeveSerialEvent(int count)
    : PeveEvent(count)
{
}

void PeveSerialEvent::reset()
{
	PeveEvent::reset();
	mEventIdx            = 0;
	PeveEvent* currEvent = getCurrentEvent();
	currEvent->reset();
}

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

PeveCameraPostureIO::PeveCameraPostureIO()
{
	construct(nullptr);
}

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

PeveClampVector3fIO::PeveClampVector3fIO()
{
	construct();
}

void PeveClampVector3fIO::construct()
{
	mMaxLength = 1.0f;
}

void PeveClampVector3fIO::input(immut NVector3f& vec)
{
	_04.input(vec);
	f32 len = _04.length();
	if (len > mMaxLength) {
		_04.scale(mMaxLength / len);
	}
}
