#include "Kontroller.h"
#include "Dolphin/os.h"
#include "DebugLog.h"
#include "KIO.h"

RamStream* controllerBuffer;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

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
	_50         = 0;
	_54         = 0;
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
	_54         = p2;
	mDataStream = stream;
	stream->setPosition(0);
	_50 = 1;
}

/*
 * --INFO--
 * Address:	80115CA8
 * Size:	000050
 */
void Kontroller::load(RamStream* stream, int p2)
{
	PRINT("************ load start\n");
	_54         = p2;
	mDataStream = stream;
	stream->setPosition(0);
	_50 = 2;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void Kontroller::stop()
{
	PRINT("************ stopped\n");
	_50         = 0;
	mDataStream = nullptr;
	_54         = 0;
}

/*
 * --INFO--
 * Address:	80115CF8
 * Size:	000168
 */
void Kontroller::update()
{
	switch (_50) {
	case 2:
		read(*mDataStream);
		if (--_54 <= 0) {
			stop();
		}
		updateCont(_5C);
		break;
	case 1:
		Controller::update();
		write(*mDataStream);
		if (--_54 <= 0) {
			void* addr = mDataStream->mBufferAddr;
			DCFlushRange(addr, mDataStream->getPosition());

			// AAAAAAAAAAAAAAAAAAAAAA
			int test = 0;
			for (int i = 20; i > 0; i--) {
				test += 6;
			}
			PRINT("%i\n", getSaveSize(test));

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

	f32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r0, 0x50(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x84
	  bge-      .loc_0x34
	  cmpwi     r0, 0
	  bge-      .loc_0x148
	  b         .loc_0x150

	.loc_0x34:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x150
	  mr        r3, r30
	  lwz       r4, 0x58(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x54(r30)
	  subic.    r0, r3, 0x1
	  stw       r0, 0x54(r30)
	  bgt-      .loc_0x74
	  li        r0, 0
	  stw       r0, 0x50(r30)
	  stw       r0, 0x58(r30)
	  stw       r0, 0x54(r30)

	.loc_0x74:
	  mr        r3, r30
	  lwz       r4, 0x5C(r30)
	  bl        -0xD53A0
	  b         .loc_0x150

	.loc_0x84:
	  mr        r3, r30
	  bl        -0xD5310
	  mr        r3, r30
	  lwz       r4, 0x58(r30)
	  bl        0xDC
	  lwz       r3, 0x54(r30)
	  subic.    r0, r3, 0x1
	  stw       r0, 0x54(r30)
	  bgt-      .loc_0x150
	  lwz       r3, 0x58(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r31, 0x8(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0xE0E28
	  li        r0, 0x2
	  mtctr     r0
	  li        r3, 0

	.loc_0xD8:
	  addi      r3, r3, 0x40
	  bdnz+     .loc_0xD8
	  lwz       r3, 0x58(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x58(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x58(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x58(r30)
	  mr        r6, r3
	  lwz       r3, 0x2F88(r13)
	  lwz       r5, 0x8(r4)
	  li        r4, 0x1
	  bl        -0x91908
	  li        r0, 0
	  stw       r0, 0x50(r30)
	  stw       r0, 0x58(r30)
	  stw       r0, 0x54(r30)
	  b         .loc_0x150

	.loc_0x148:
	  mr        r3, r30
	  bl        -0xD53D4

	.loc_0x150:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115E60
 * Size:	000008
 */
int Kontroller::getSaveSize(int p1)
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
