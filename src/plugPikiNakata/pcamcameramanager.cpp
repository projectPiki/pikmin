#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80123C54
 * Size:	0001F8
 */
PcamCameraManager::PcamCameraManager(Camera *, Controller *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r6, 0x738C
  li        r7, 0
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r3, 0
  lis       r3, 0x8022
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  addi      r29, r5, 0
  stw       r28, 0x28(r1)
  addi      r28, r4, 0
  stw       r0, 0x0(r31)
  addi      r0, r3, 0x737C
  lis       r3, 0x802C
  stw       r0, 0x0(r31)
  addi      r6, r3, 0x5274
  lis       r3, 0x8023
  stw       r7, 0x10(r31)
  subi      r0, r3, 0x71E0
  addi      r3, r31, 0
  stw       r7, 0xC(r31)
  addi      r4, r6, 0
  stw       r7, 0x8(r31)
  stw       r6, 0x4(r31)
  stw       r0, 0x0(r31)
  bl        -0xE3588
  lis       r3, 0x802C
  addi      r0, r3, 0x52D0
  stw       r0, 0x0(r31)
  li        r3, 0x170
  bl        -0xDCCD4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x9C
  mr        r4, r28
  bl        -0x20E0

.loc_0x9C:
  stw       r30, 0x20(r31)
  li        r3, 0x14
  stw       r29, 0x24(r31)
  bl        -0xDCCF8
  stw       r3, 0x2C(r31)
  li        r3, 0x60
  bl        -0xDCD04
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xCC
  lwz       r4, 0x20(r31)
  bl        0x630

.loc_0xCC:
  lfs       f0, -0x5F00(r2)
  li        r3, 0x60
  stfs      f0, 0x48(r30)
  lfs       f0, -0x5EFC(r2)
  stfs      f0, 0x4C(r30)
  lfs       f0, -0x5EF8(r2)
  stfs      f0, 0x50(r30)
  lwz       r4, 0x2C(r31)
  stw       r30, 0x8(r4)
  bl        -0xDCD40
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x108
  lwz       r4, 0x20(r31)
  bl        0x5F4

.loc_0x108:
  lfs       f0, -0x5F00(r2)
  li        r3, 0x28
  stfs      f0, 0x48(r30)
  lfs       f0, -0x5EFC(r2)
  stfs      f0, 0x4C(r30)
  lfs       f0, -0x5EF4(r2)
  stfs      f0, 0x50(r30)
  lwz       r4, 0x2C(r31)
  stw       r30, 0xC(r4)
  bl        -0xDCD7C
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x144
  lwz       r4, 0x20(r31)
  bl        0x414

.loc_0x144:
  lwz       r4, 0x2C(r31)
  li        r3, 0x60
  stw       r29, 0x10(r4)
  bl        -0xDCDA0
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x168
  lwz       r4, 0x20(r31)
  bl        0x690

.loc_0x168:
  lfs       f0, -0x5F00(r2)
  li        r3, 0x48
  stfs      f0, 0x48(r30)
  lfs       f0, -0x5EFC(r2)
  stfs      f0, 0x4C(r30)
  lfs       f0, -0x5EF0(r2)
  stfs      f0, 0x50(r29)
  lwz       r4, 0x2C(r31)
  stw       r29, 0x4(r4)
  bl        -0xDCDDC
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x1A4
  lwz       r4, 0x20(r31)
  bl        0x9CC

.loc_0x1A4:
  lfs       f0, -0x5F00(r2)
  li        r0, -0x1
  addi      r3, r31, 0
  stfs      f0, 0x48(r30)
  lfs       f0, -0x5EFC(r2)
  stfs      f0, 0x4C(r30)
  lfs       f1, -0x1CA4(r13)
  lfs       f0, -0x5EEC(r2)
  fdivs     f0, f1, f0
  stfs      f0, 0x18(r29)
  lwz       r4, 0x2C(r31)
  stw       r29, 0x0(r4)
  stw       r0, 0x28(r31)
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  lwz       r28, 0x28(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80123E4C
 * Size:	000024
 */
void PcamCameraManager::startCamera(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x20(r3)
  bl        -0x211C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80123E70
 * Size:	000050
 */
void PcamCameraManager::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lwz       r3, 0x20(r3)
  lwz       r4, 0x24(r31)
  bl        -0x19A8
  lwz       r3, 0x20(r31)
  lwz       r12, 0x50(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  bl        .loc_0x50
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0x50:
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PcamCameraManager::startMotion(PcamMotionInfo &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PcamCameraManager::finishMotion()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80123EC0
 * Size:	000098
 */
void PcamCameraManager::updateVibrationEvent()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r0, 0x28(r3)
  cmpwi     r0, 0
  blt-      .loc_0x80
  lwz       r3, 0x2C(r30)
  rlwinm    r0,r0,2,0,29
  lwzx      r31, r3, r0
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x6C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  li        r0, -0x1
  stw       r0, 0x28(r30)
  b         .loc_0x80

.loc_0x6C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      

.loc_0x80:
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
 * Address:	80123F58
 * Size:	000038
 */
void PeveEvent::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x8(r3)
  cmplwi    r3, 0
  beq-      .loc_0x28
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      

.loc_0x28:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80123F90
 * Size:	000004
 */
void PeveCondition::update()
{
}

/*
 * --INFO--
 * Address:	80123F94
 * Size:	000004
 */
void PeveEvent::finish()
{
}

/*
 * --INFO--
 * Address:	80123F98
 * Size:	000040
 */
void PeveEvent::isFinished()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x8(r3)
  cmplwi    r3, 0
  bne-      .loc_0x20
  li        r3, 0x1
  b         .loc_0x30

.loc_0x20:
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x30:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80123FD8
 * Size:	000148
 */
void PcamCameraManager::startVibrationEvent(int, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x70(r1)
  stw       r31, 0x6C(r1)
  addi      r31, r5, 0
  stw       r30, 0x68(r1)
  addi      r30, r4, 0
  stw       r29, 0x64(r1)
  mr        r29, r3
  lwz       r0, 0x28(r3)
  cmpwi     r0, 0
  blt-      .loc_0x38
  cmpw      r0, r30
  blt-      .loc_0x12C

.loc_0x38:
  addi      r3, r1, 0x50
  bl        -0x71C0
  addi      r3, r29, 0
  addi      r4, r1, 0x50
  bl        0x13C
  lfs       f3, 0x58(r1)
  lfs       f2, 0x8(r31)
  lfs       f1, 0x50(r1)
  lfs       f0, 0x0(r31)
  fsubs     f2, f3, f2
  fsubs     f1, f1, f0
  fmuls     f0, f2, f2
  fmuls     f1, f1, f1
  fadds     f1, f1, f0
  bl        -0x116408
  lwz       r3, 0x20(r29)
  lwz       r3, 0xD0(r3)
  lwz       r3, 0x24(r3)
  lwz       r3, 0x4(r3)
  lwz       r3, 0x0(r3)
  lfs       f0, 0xD4(r3)
  fcmpo     cr0, f1, f0
  bgt-      .loc_0x12C
  stw       r30, 0x28(r29)
  lwz       r4, 0x28(r29)
  lwz       r3, 0x2C(r29)
  rlwinm    r0,r4,2,0,29
  cmpwi     r4, 0x2
  lwzx      r31, r3, r0
  bne-      .loc_0xBC
  mr        r3, r31
  bl        0x338
  b         .loc_0x118

.loc_0xBC:
  cmpwi     r4, 0x3
  bne-      .loc_0xD0
  mr        r3, r31
  bl        0x324
  b         .loc_0x118

.loc_0xD0:
  cmpwi     r4, 0x4
  bne-      .loc_0xF4
  lfs       f1, -0x5EE8(r2)
  mr        r3, r31
  lfs       f2, -0x5F00(r2)
  lfs       f3, -0x5EFC(r2)
  lfs       f4, -0x5EE4(r2)
  bl        0x1B0
  b         .loc_0x118

.loc_0xF4:
  cmpwi     r4, 0x1
  bne-      .loc_0x108
  mr        r3, r31
  bl        0x3E8
  b         .loc_0x118

.loc_0x108:
  cmpwi     r4, 0
  bne-      .loc_0x118
  mr        r3, r31
  bl        0x798

.loc_0x118:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      

.loc_0x12C:
  lwz       r0, 0x74(r1)
  lwz       r31, 0x6C(r1)
  lwz       r30, 0x68(r1)
  lwz       r29, 0x64(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80124120
 * Size:	000038
 */
void PeveEvent::reset()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x8(r3)
  cmplwi    r3, 0
  beq-      .loc_0x28
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      

.loc_0x28:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80124158
 * Size:	000004
 */
void PeveCondition::reset()
{
}

/*
 * --INFO--
 * Address:	8012415C
 * Size:	00004C
 */
void PcamCameraManager::outputNaviPosition(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  li        r4, 0
  lwz       r3, 0x3120(r13)
  bl        -0xCD40
  lfsu      f0, 0x94(r3)
  stfs      f0, 0x0(r31)
  lfs       f0, 0x4(r3)
  stfs      f0, 0x4(r31)
  lfs       f0, 0x8(r3)
  stfs      f0, 0x8(r31)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}
