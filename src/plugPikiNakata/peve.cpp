#include "Peve/Event.h"
#include "Peve/Condition.h"
#include "Peve/IO.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	80125540
 * Size:	000010
 */
PeveCondition::PeveCondition()
{
	/*
	.loc_0x0:
	  lis       r4, 0x802C
	  addi      r0, r4, 0x5E24
	  stw       r0, 0x0(r3)
	  blr
	*/
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  li        r31, 0
	  b         .loc_0x5C

	.loc_0x3C:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x721C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x1

	.loc_0x5C:
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x8(r3)
	  cmpw      r31, r0
	  blt+      .loc_0x3C
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
 * Address:	801256A0
 * Size:	00007C
 */
bool PeveParallelEvent::isFinished()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  b         .loc_0x50

	.loc_0x20:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x7284
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x4C:
	  addi      r31, r31, 0x1

	.loc_0x50:
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x8(r3)
	  cmpw      r31, r0
	  blt+      .loc_0x20
	  li        r3, 0x1

	.loc_0x64:
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lwz       r4, 0x10(r3)
	  bl        -0x73B0
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA0
	  lwz       r3, 0x4(r30)
	  cmplwi    r3, 0
	  bne-      .loc_0x50
	  li        r4, 0
	  b         .loc_0x54

	.loc_0x50:
	  lwz       r4, 0x8(r3)

	.loc_0x54:
	  lwz       r3, 0x10(r30)
	  addi      r0, r3, 0x1
	  cmpw      r0, r4
	  bge-      .loc_0xB4
	  stw       r0, 0x10(r30)
	  mr        r3, r30
	  lwz       r4, 0x10(r30)
	  bl        -0x7404
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xB4

	.loc_0xA0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl

	.loc_0xB4:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801258A4
 * Size:	000074
 */
bool PeveSerialEvent::isFinished()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x4(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x20
	  li        r5, 0
	  b         .loc_0x24

	.loc_0x20:
	  lwz       r5, 0x8(r4)

	.loc_0x24:
	  lwz       r4, 0x10(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  bge-      .loc_0x3C
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x3C:
	  bl        -0x749C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x60
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x60:
	  li        r3, 0x1

	.loc_0x64:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
PeveCameraViewpointIO::PeveCameraViewpointIO()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveCameraViewpointIO::construct(PcamCamera*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
PeveCameraWatchpointIO::PeveCameraWatchpointIO()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveCameraWatchpointIO::construct(PcamCamera*)
{
	// UNUSED FUNCTION
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
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveCreaturePositionIO::construct(Creature*)
{
	// UNUSED FUNCTION
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
	/*
	.loc_0x0:
	  lfs       f0, -0x5E18(r2)
	  stfs      f0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801259DC
 * Size:	0000DC
 */
void PeveClampVector3fIO::input(NVector3f&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0xC(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fmuls     f2, f1, f1
	  lfs       f3, 0xC(r3)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x5E14(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xA0
	  fsqrte    f1, f4
	  lfd       f3, -0x5E10(r2)
	  lfd       f2, -0x5E08(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x14(r1)
	  lfs       f4, 0x14(r1)

	.loc_0xA0:
	  lfs       f0, 0x10(r3)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xD4
	  fdivs     f1, f0, f4
	  lfs       f0, 0x4(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0xC(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC(r3)

	.loc_0xD4:
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125AB8
 * Size:	00001C
 */
void NVector3fIOClass::output(NVector3f&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125AD4
 * Size:	00001C
 */
void NVector3fIOClass::input(NVector3f&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125AF0
 * Size:	000020
 */
void PeveCreaturePositionIO::input(NVector3f&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x94(r5)
	  stw       r0, 0x98(r5)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x9C(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125B10
 * Size:	000020
 */
void PeveCreaturePositionIO::output(NVector3f&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r3)
	  lwz       r3, 0x94(r5)
	  lwz       r0, 0x98(r5)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x9C(r5)
	  stw       r0, 0x8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125B30
 * Size:	00005C
 */
void PeveCameraPostureIO::input(NPosture3D&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  addi      r4, r30, 0x4
	  lwz       r31, 0x4(r3)
	  addi      r5, r4, 0x4
	  addi      r6, r4, 0x8
	  addi      r3, r31, 0x8
	  bl        -0xC84D0
	  addi      r4, r30, 0x10
	  addi      r3, r31, 0x14
	  addi      r5, r4, 0x4
	  addi      r6, r4, 0x8
	  bl        -0xC84E4
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
 * Address:	80125B8C
 * Size:	00005C
 */
void PeveCameraPostureIO::output(NPosture3D&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  lwz       r31, 0x4(r3)
	  addi      r3, r30, 0x4
	  addi      r4, r31, 0x8
	  addi      r5, r31, 0xC
	  addi      r6, r31, 0x10
	  bl        -0xC852C
	  addi      r3, r30, 0x10
	  addi      r4, r31, 0x14
	  addi      r5, r31, 0x18
	  addi      r6, r31, 0x1C
	  bl        -0xC8540
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125BE8
 * Size:	000020
 */
void PeveCameraWatchpointIO::input(NVector3f&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x4(r3)
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x14(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x18(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125C08
 * Size:	000020
 */
void PeveCameraWatchpointIO::output(NVector3f&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x4(r3)
	  lfsu      f0, 0x14(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125C28
 * Size:	000020
 */
void PeveCameraViewpointIO::input(NVector3f&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x4(r3)
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125C48
 * Size:	000020
 */
void PeveCameraViewpointIO::output(NVector3f&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x4(r3)
	  lfsu      f0, 0x8(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x8(r4)
	  blr
	*/
}
