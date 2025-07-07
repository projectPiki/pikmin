#include "Kontroller.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "KIO.h"

RamStream* controllerBuffer;

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
DEFINE_PRINT("Kontroller")

/*
 * --INFO--
 * Address:	80115B8C
 * Size:	0000CC
 */
Kontroller::Kontroller(int p1)
    : Controller(p1)
{
	mState      = 0;
	mDuration   = 0;
	mDataStream = nullptr;
}

/*
 * --INFO--
 * Address:	80115C58
 * Size:	000050
 */
void Kontroller::save(RamStream* stream, int p2)
{
	PRINT("************ save start\n");
	mDuration   = p2;
	mDataStream = stream;
	stream->setPosition(0);
	mState = 1;
}

/*
 * --INFO--
 * Address:	80115CA8
 * Size:	000050
 */
void Kontroller::load(RamStream* stream, int p2)
{
	PRINT("************ load start\n");
	mDuration   = p2;
	mDataStream = stream;
	stream->setPosition(0);
	mState = 2;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void Kontroller::stop()
{
	PRINT("************ stopped\n");
	mState      = 0;
	mDataStream = nullptr;
	mDuration   = 0;
}

/*
 * --INFO--
 * Address:	80115CF8
 * Size:	000168
 */
void Kontroller::update()
{
	switch (mState) {
	case 2:
		read(*mDataStream);
		if (--mDuration <= 0) {
			stop();
		}
		updateCont(_5C);
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
			kio->startWrite(1, (u8*)mDataStream->mBufferAddr, mDataStream->getPosition());
			stop();
		}
		break;
	case 0:
		Controller::update();
		break;
	}

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	80115E60
 * Size:	000008
 */
u32 Kontroller::getSaveSize(int p1)
{
	return p1 * 12;
}

/*
 * --INFO--
 * Address:	80115E68
 * Size:	00010C
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

/*
 * --INFO--
 * Address:	80115F74
 * Size:	00010C
 */
void Kontroller::read(RandomAccessStream& stream)
{
	_5C         = stream.readInt();
	mMainStickX = stream.readByte();
	mMainStickY = stream.readByte();
	mSubStickX  = stream.readByte();
	mSubStickY  = stream.readByte();
	mAnalogA    = stream.readByte();
	mAnalogB    = stream.readByte();
	mTriggerL   = stream.readByte();
	mTriggerR   = stream.readByte();
}
