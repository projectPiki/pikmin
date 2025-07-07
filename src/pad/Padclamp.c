#include "Dolphin/math.h"
#include "Dolphin/pad.h"

typedef struct PADClampRegion {
	u8 minTrigger;
	u8 maxTrigger;
	s8 minStick;
	s8 maxStick;
	s8 xyStick;
	s8 minSubstick;
	s8 maxSubstick;
	s8 xySubstick;
} PADClampRegion;

static PADClampRegion ClampRegion = {
	// Triggers
	30,
	180,

	// Left stick
	15,
	72,
	40,

	// Right stick
	15,
	59,
	31,
};

/*
 * --INFO--
 * Address:	80203BCC
 * Size:	000130
 */
static void ClampStick(s8* px, s8* py, s8 max, s8 xy, s8 min)
{
	int x = *px;
	int y = *py;
	int signX;
	int signY;
	int d;

	if (0 <= x) {
		signX = 1;
	} else {
		signX = -1;
		x     = -x;
	}

	if (0 <= y) {
		signY = 1;
	} else {
		signY = -1;
		y     = -y;
	}

	if (x <= min) {
		x = 0;
	} else {
		x -= min;
	}
	if (y <= min) {
		y = 0;
	} else {
		y -= min;
	}

	if (x == 0 && y == 0) {
		*px = *py = 0;
		return;
	}

	if (xy * y <= xy * x) {
		d = xy * x + (max - xy) * y;
		if (xy * max < d) {
			x = (s8)(xy * max * x / d);
			y = (s8)(xy * max * y / d);
		}
	} else {
		d = xy * y + (max - xy) * x;
		if (xy * max < d) {
			x = (s8)(xy * max * x / d);
			y = (s8)(xy * max * y / d);
		}
	}

	*px = (s8)(signX * x);
	*py = (s8)(signY * y);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
static void ClampTrigger(u8* trigger)
{
	if (*trigger <= ClampRegion.minTrigger) {
		*trigger = 0;
	} else {
		if (ClampRegion.maxTrigger < *trigger) {
			*trigger = ClampRegion.maxTrigger;
		}
		*trigger -= ClampRegion.minTrigger;
	}
}

/*
 * --INFO--
 * Address:	80203CFC
 * Size:	000108
 */
void PADClamp(PADStatus* status)
{
	int i;
	for (i = 0; i < SI_MAX_CHAN; i++, status++) {
		if (status->err != PAD_ERR_NONE) {
			continue;
		}

		ClampStick(&status->stickX, &status->stickY, ClampRegion.maxStick, ClampRegion.xyStick, ClampRegion.minStick);
		ClampStick(&status->substickX, &status->substickY, ClampRegion.maxSubstick, ClampRegion.xySubstick, ClampRegion.minSubstick);
		ClampTrigger(&status->triggerLeft);
		ClampTrigger(&status->triggerRight);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x14(r1)

	.loc_0x20:
	  lbz       r0, 0xA(r30)
	  extsb.    r0, r0
	  bne-      .loc_0xDC
	  addi      r29, r13, 0x2A30
	  lbz       r5, 0x3(r29)
	  addi      r3, r30, 0x2
	  lbz       r6, 0x4(r29)
	  addi      r4, r30, 0x3
	  lbz       r7, 0x2(r29)
	  bl        -0x174
	  lbz       r5, 0x6(r29)
	  addi      r3, r30, 0x4
	  lbz       r6, 0x7(r29)
	  addi      r4, r30, 0x5
	  lbz       r7, 0x5(r29)
	  bl        -0x18C
	  lbz       r3, 0x6(r30)
	  lbz       r0, 0x2A30(r13)
	  cmplw     r3, r0
	  bgt-      .loc_0x7C
	  li        r0, 0
	  stb       r0, 0x6(r30)
	  b         .loc_0x9C

	.loc_0x7C:
	  lbz       r0, 0x1(r29)
	  cmplw     r0, r3
	  bge-      .loc_0x8C
	  stb       r0, 0x6(r30)

	.loc_0x8C:
	  lbz       r3, 0x2A30(r13)
	  lbz       r0, 0x6(r30)
	  sub       r0, r0, r3
	  stb       r0, 0x6(r30)

	.loc_0x9C:
	  lbz       r4, 0x7(r30)
	  lbz       r0, 0x2A30(r13)
	  cmplw     r4, r0
	  bgt-      .loc_0xB8
	  li        r0, 0
	  stb       r0, 0x7(r30)
	  b         .loc_0xDC

	.loc_0xB8:
	  addi      r3, r13, 0x2A30
	  lbz       r0, 0x1(r3)
	  cmplw     r0, r4
	  bge-      .loc_0xCC
	  stb       r0, 0x7(r30)

	.loc_0xCC:
	  lbz       r3, 0x2A30(r13)
	  lbz       r0, 0x7(r30)
	  sub       r0, r0, r3
	  stb       r0, 0x7(r30)

	.loc_0xDC:
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x4
	  addi      r30, r30, 0xC
	  blt+      .loc_0x20
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}
