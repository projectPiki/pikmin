#include "DebugLog.h"
#include "Peve/Condition.h"
#include "Peve/Event.h"
#include "Peve/IO.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("peve")

/**
 * @TODO: Documentation
 */
PeveCondition::PeveCondition()
{
}

/**
 * @TODO: Documentation
 */
PeveEvent::PeveEvent(int count)
    : NNode(count)
{
	mCondition    = nullptr;
	mEventOptions = 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000054
 */
PeveParallelEvent::PeveParallelEvent(int count)
    : PeveEvent(count)
{
}

/**
 * @TODO: Documentation
 */
void PeveParallelEvent::reset()
{
	PeveEvent::reset();
	for (int i = 0; i < mNodeArray->getSize(); i++) {
		getEvent(i)->reset();
	}
}

/**
 * @TODO: Documentation
 */
void PeveParallelEvent::update()
{
	PeveEvent::update();
	for (int i = 0; i < mNodeArray->getSize(); i++) {
		getEvent(i)->update();
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
PeveSerialEvent::PeveSerialEvent(int count)
    : PeveEvent(count)
{
}

/**
 * @TODO: Documentation
 */
void PeveSerialEvent::reset()
{
	PeveEvent::reset();
	mEventIdx            = 0;
	PeveEvent* currEvent = getCurrentEvent();
	currEvent->reset();
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
 */
PeveCameraViewpointIO::PeveCameraViewpointIO()
{
	construct(nullptr);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PeveCameraViewpointIO::construct(PcamCamera* camera)
{
	mCamera = camera;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
 */
PeveCameraWatchpointIO::PeveCameraWatchpointIO()
{
	construct(nullptr);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PeveCameraWatchpointIO::construct(PcamCamera* camera)
{
	mCamera = camera;
}

/**
 * @TODO: Documentation
 */
PeveCameraPostureIO::PeveCameraPostureIO()
{
	construct(nullptr);
}

/**
 * @TODO: Documentation
 */
void PeveCameraPostureIO::construct(PcamCamera* camera)
{
	mCamera = camera;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
 */
PeveCreaturePositionIO::PeveCreaturePositionIO()
{
	construct(nullptr);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void PeveCreaturePositionIO::construct(Creature* creature)
{
	mCreature = creature;
}

/**
 * @TODO: Documentation
 */
PeveClampVector3fIO::PeveClampVector3fIO()
{
	construct();
}

/**
 * @TODO: Documentation
 */
void PeveClampVector3fIO::construct()
{
	mMaxLength = 1.0f;
}

/**
 * @TODO: Documentation
 */
void PeveClampVector3fIO::input(immut NVector3f& vec)
{
	_04.input(vec);
	f32 len = _04.length();
	if (len > mMaxLength) {
		_04.scale(mMaxLength / len);
	}
}
