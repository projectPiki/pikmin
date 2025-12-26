#include "Kontroller.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "KIO.h"

RamStream* controllerBuffer;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("Kontroller")

/**
 * @todo: Documentation
 */
Kontroller::Kontroller(int controllerId)
    : Controller(controllerId)
{
	mState      = 0;
	mDuration   = 0;
	mDataStream = nullptr;
}

/**
 * @todo: Documentation
 */
void Kontroller::save(RamStream* stream, int duration)
{
	PRINT("************ save start\n");
	mDuration   = duration;
	mDataStream = stream;
	stream->setPosition(0);
	mState = 1;
}

/**
 * @todo: Documentation
 */
void Kontroller::load(RamStream* stream, int duration)
{
	PRINT("************ load start\n");
	mDuration   = duration;
	mDataStream = stream;
	stream->setPosition(0);
	mState = 2;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014
 */
void Kontroller::stop()
{
	PRINT("************ stopped\n");
	mState      = 0;
	mDataStream = nullptr;
	mDuration   = 0;
}

/**
 * @todo: Documentation
 */
void Kontroller::update()
{
	switch (mState) {
	case 2:
		read(*mDataStream);
		if (--mDuration <= 0) {
			stop();
		}
		updateCont(mCurrentKeyStatus);
		break;
	case 1:
		Controller::update();
		write(*mDataStream);
		if (--mDuration <= 0) {
			void* addr = mDataStream->mBufferAddr;
			DCFlushRange(addr, mDataStream->getPosition());

			//! What the actual fuck is this?
			//! Seriously, all to generate 4 instructions.
			u32 test = 0;
			for (int i = 0; i != 16; i++) {
				!(test += 0x8);
			}

			mDataStream->close();
			mDataStream->getPosition();
			kio->startWrite(KIOWRITE_ControllerStream, (u8*)mDataStream->mBufferAddr, mDataStream->getPosition());
			stop();
		}
		break;
	case 0:
		Controller::update();
		break;
	}

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
u32 Kontroller::getSaveSize(int duration)
{
	return duration * 12;
}

/**
 * @todo: Documentation
 */
void Kontroller::write(RandomAccessStream& stream)
{
	stream.writeInt(mCurrentInput);
	stream.writeByte(mMainStickX);
	stream.writeByte(mMainStickY);
	stream.writeByte(mSubStickX);
	stream.writeByte(mSubStickY);
	stream.writeByte(mAnalogA);
	stream.writeByte(mAnalogB);
	stream.writeByte(mTriggerL);
	stream.writeByte(mTriggerR);
}

/**
 * @todo: Documentation
 */
void Kontroller::read(RandomAccessStream& stream)
{
	mCurrentKeyStatus = stream.readInt();
	mMainStickX = stream.readByte();
	mMainStickY = stream.readByte();
	mSubStickX  = stream.readByte();
	mSubStickY  = stream.readByte();
	mAnalogA    = stream.readByte();
	mAnalogB    = stream.readByte();
	mTriggerL   = stream.readByte();
	mTriggerR   = stream.readByte();
}
