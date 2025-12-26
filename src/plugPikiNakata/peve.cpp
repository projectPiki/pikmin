#include "DebugLog.h"
#include "Peve/Condition.h"
#include "Peve/Event.h"
#include "Peve/IO.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("peve")

/**
 * @todo: Documentation
 */
PeveCondition::PeveCondition()
{
}

/**
 * @todo: Documentation
 */
PeveEvent::PeveEvent(int count)
    : NNode(count)
{
	mCondition    = nullptr;
	mEventOptions = 0;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000054
 */
PeveParallelEvent::PeveParallelEvent(int count)
    : PeveEvent(count)
{
}

/**
 * @todo: Documentation
 */
void PeveParallelEvent::reset()
{
	PeveEvent::reset();
	for (int i = 0; i < mNodeArray->getSize(); i++) {
		getEvent(i)->reset();
	}
}

/**
 * @todo: Documentation
 */
void PeveParallelEvent::update()
{
	PeveEvent::update();
	for (int i = 0; i < mNodeArray->getSize(); i++) {
		getEvent(i)->update();
	}
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
PeveSerialEvent::PeveSerialEvent(int count)
    : PeveEvent(count)
{
}

/**
 * @todo: Documentation
 */
void PeveSerialEvent::reset()
{
	PeveEvent::reset();
	mEventIdx            = 0;
	PeveEvent* currEvent = getCurrentEvent();
	currEvent->reset();
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
 * @note UNUSED Size: 000050
 */
PeveCameraViewpointIO::PeveCameraViewpointIO()
{
	construct(nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008
 */
void PeveCameraViewpointIO::construct(PcamCamera* camera)
{
	mCamera = camera;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000050
 */
PeveCameraWatchpointIO::PeveCameraWatchpointIO()
{
	construct(nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008
 */
void PeveCameraWatchpointIO::construct(PcamCamera* camera)
{
	mCamera = camera;
}

/**
 * @todo: Documentation
 */
PeveCameraPostureIO::PeveCameraPostureIO()
{
	construct(nullptr);
}

/**
 * @todo: Documentation
 */
void PeveCameraPostureIO::construct(PcamCamera* camera)
{
	mCamera = camera;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000050
 */
PeveCreaturePositionIO::PeveCreaturePositionIO()
{
	construct(nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008
 */
void PeveCreaturePositionIO::construct(Creature* creature)
{
	mCreature = creature;
}

/**
 * @todo: Documentation
 */
PeveClampVector3fIO::PeveClampVector3fIO()
{
	construct();
}

/**
 * @todo: Documentation
 */
void PeveClampVector3fIO::construct()
{
	mMaxLength = 1.0f;
}

/**
 * @todo: Documentation
 */
void PeveClampVector3fIO::input(immut NVector3f& vec)
{
	_04.input(vec);
	f32 len = _04.length();
	if (len > mMaxLength) {
		_04.scale(mMaxLength / len);
	}
}
