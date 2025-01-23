#include "TAI/WaitActions.h"
#include "teki.h"
#include "Dolphin/os.h"
#include "system.h"
#include "nlib/Math.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	80143A9C
 * Size:	000070
 */
void TaiWaitTurningAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.mTargetAngle = NMathF::getRandomAngle();
}

/*
 * --INFO--
 * Address:	80143B0C
 * Size:	0000E4
 */
bool TaiWaitTurningAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x58C0(r2)
	  lfs       f6, 0xA0(r4)
	  lfs       f1, -0x58D0(r2)
	  lfs       f5, -0x1CA4(r13)
	  fcmpo     cr0, f6, f0
	  fmuls     f4, f1, f5
	  bge-      .loc_0x30
	  fadds     f6, f6, f4
	  b         .loc_0x40

	.loc_0x30:
	  fcmpo     cr0, f6, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x40
	  fsubs     f6, f6, f4

	.loc_0x40:
	  lfs       f1, 0x394(r4)
	  fcmpo     cr0, f1, f6
	  fmr       f3, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x6C
	  fsubs     f2, f3, f6
	  fsubs     f0, f4, f2
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x80
	  fsubs     f3, f3, f4
	  b         .loc_0x80

	.loc_0x6C:
	  fsubs     f2, f6, f3
	  fsubs     f0, f4, f2
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x80
	  fadds     f3, f3, f4

	.loc_0x80:
	  fsubs     f2, f3, f6
	  lfs       f0, -0x58C0(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x94
	  b         .loc_0x98

	.loc_0x94:
	  fneg      f2, f2

	.loc_0x98:
	  lfs       f0, -0x58BC(r2)
	  fmuls     f0, f0, f5
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB4
	  li        r3, 0x1
	  b         .loc_0xD4

	.loc_0xB4:
	  lwz       r5, 0x2C4(r4)
	  mr        r3, r4
	  lwz       r4, 0x84(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f2, 0x14(r4)
	  bl        0x39F4
	  li        r3, 0

	.loc_0xD4:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
