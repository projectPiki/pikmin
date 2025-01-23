#include "zen/ogMakeDefault.h"
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
 * Address:	8019399C
 * Size:	000360
 */
zen::ogScrMakeDefaultMgr::ogScrMakeDefaultMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  li        r3, 0xF8
	  stw       r30, 0x28(r1)
	  bl        -0x14C9B4
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x80
	  addi      r3, r1, 0x1C
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1FC4C
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x1C
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x1CFD0
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r0, 0xEC(r30)
	  stw       r0, 0xF0(r30)
	  stw       r0, 0xF4(r30)

	.loc_0x80:
	  stw       r30, 0x8(r31)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x6028
	  lwz       r3, 0x8(r31)
	  li        r5, 0x1
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        0x1F1C8
	  li        r3, 0xF8
	  bl        -0x14CA3C
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x108
	  addi      r3, r1, 0x14
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1FBC4
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x14
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x1CF48
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r0, 0xEC(r30)
	  stw       r0, 0xF0(r30)
	  stw       r0, 0xF4(r30)

	.loc_0x108:
	  stw       r30, 0xC(r31)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x6040
	  lwz       r3, 0xC(r31)
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x1F140
	  lwz       r3, 0xC(r31)
	  lis       r4, 0x626C
	  addi      r4, r4, 0x636B
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x10(r31)
	  lis       r3, 0x6162
	  li        r0, 0xFF
	  lwz       r6, 0x10(r31)
	  addi      r4, r3, 0x746E
	  li        r5, 0x1
	  stb       r0, 0xF0(r6)
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x1C(r31)
	  li        r3, 0x12C
	  bl        -0x14CB18
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x19C
	  lwz       r4, 0x1C(r31)
	  lfs       f1, -0x4E08(r2)
	  bl        -0x14910

	.loc_0x19C:
	  stw       r30, 0x24(r31)
	  lis       r3, 0x7478
	  li        r7, 0
	  lwz       r6, 0x1C(r31)
	  addi      r4, r3, 0x3030
	  li        r5, 0x1
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r6)
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x3C(r31)
	  li        r3, 0x418
	  bl        -0x14CB74
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1F4
	  lwz       r4, 0x3C(r31)
	  bl        -0x137FC

	.loc_0x1F4:
	  stw       r30, 0x40(r31)
	  lis       r30, 0x7478
	  addi      r4, r30, 0x3031
	  lwz       r0, 0x40(r31)
	  li        r5, 0x1
	  stw       r0, 0x28(r31)
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x44(r31)
	  addi      r4, r30, 0x3032
	  li        r5, 0x1
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x48(r31)
	  addi      r4, r30, 0x3033
	  li        r5, 0x1
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r31)
	  lis       r3, 0x6375
	  addi      r4, r3, 0x7273
	  lwz       r3, 0x8(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x18(r31)
	  li        r3, 0x12C
	  bl        -0x14CC24
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2A8
	  lwz       r4, 0x18(r31)
	  lfs       f1, -0x4E04(r2)
	  bl        -0x14A1C

	.loc_0x2A8:
	  stw       r30, 0x20(r31)
	  lis       r3, 0x7066
	  addi      r4, r3, 0x6F6B
	  lwz       r3, 0x8(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x2C(r31)
	  li        r3, 0x418
	  bl        -0x14CC6C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2EC
	  lwz       r4, 0x2C(r31)
	  bl        -0x138F4

	.loc_0x2EC:
	  stw       r30, 0x30(r31)
	  lis       r3, 0x7066
	  addi      r4, r3, 0x7878
	  lwz       r3, 0x8(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x34(r31)
	  li        r3, 0x418
	  bl        -0x14CCB0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x330
	  lwz       r4, 0x34(r31)
	  bl        -0x13938

	.loc_0x330:
	  stw       r30, 0x38(r31)
	  li        r0, -0x1
	  addi      r3, r31, 0
	  lfs       f0, -0x4E00(r2)
	  stfs      f0, 0x50(r31)
	  stw       r0, 0x0(r31)
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
 * Address:	80193CFC
 * Size:	0000EC
 */
void zen::ogScrMakeDefaultMgr::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x2
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  li        r31, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x4E00(r2)
	  stfs      f0, 0x50(r3)
	  lwz       r3, 0x1C(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x44(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x48(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x4C(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r30)
	  bl        -0x146F0
	  lwz       r4, 0x28(r30)
	  lwz       r3, 0x8(r4)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r31, 0x0(r4)
	  lwz       r0, 0x40(r30)
	  stw       r0, 0x28(r30)
	  lwz       r3, 0x28(r30)
	  bl        -0x13974
	  lwz       r4, 0x28(r30)
	  lwz       r3, 0x18(r30)
	  lwz       r7, 0x8(r4)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x116(r7)
	  lwz       r12, 0x14(r12)
	  subi      r5, r4, 0x18
	  lha       r0, 0x1A(r7)
	  lha       r6, 0x114(r7)
	  mtlr      r12
	  lha       r4, 0x18(r7)
	  add       r5, r0, r5
	  add       r4, r4, r6
	  blrl
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80193DE8
 * Size:	000354
 */
zen::ogScrMakeDefaultMgr::MakeDefaultStatus zen::ogScrMakeDefaultMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x88(r1)
	  mr        r30, r3
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x2C
	  b         .loc_0x33C

	.loc_0x2C:
	  cmpwi     r3, 0x4
	  blt-      .loc_0x44
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x33C

	.loc_0x44:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x50(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x50(r30)
	  lfs       f1, 0x50(r30)
	  lfs       f0, -0x4E08(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7C
	  lwz       r3, 0x44(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x7C:
	  lfs       f1, 0x50(r30)
	  lfs       f0, -0x4DFC(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xA0
	  lwz       r3, 0x48(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xA0:
	  lfs       f1, 0x50(r30)
	  lfs       f0, -0x4DF8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xC4
	  lwz       r3, 0x4C(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xC4:
	  lwz       r3, 0x8(r30)
	  bl        0x1ECA0
	  lwz       r3, 0xC(r30)
	  bl        0x1EC98
	  lwz       r3, 0x20(r30)
	  bl        -0x14778
	  lwz       r3, 0x24(r30)
	  bl        -0x14780
	  lwz       r3, 0x28(r30)
	  bl        -0x13534
	  lwz       r4, 0x28(r30)
	  lwz       r3, 0x18(r30)
	  lwz       r7, 0x8(r4)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x116(r7)
	  lwz       r12, 0x14(r12)
	  subi      r5, r4, 0x18
	  lha       r0, 0x1A(r7)
	  lha       r6, 0x114(r7)
	  mtlr      r12
	  lha       r4, 0x18(r7)
	  add       r5, r0, r5
	  add       r4, r4, r6
	  blrl
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x198
	  lfs       f2, 0x50(r30)
	  lfs       f1, -0x4E04(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x168
	  lfs       f0, -0x4DF4(r2)
	  lwz       r3, 0x10(r30)
	  fmuls     f0, f0, f2
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  subfic    r0, r0, 0xFF
	  stb       r0, 0xF0(r3)
	  b         .loc_0x190

	.loc_0x168:
	  li        r31, 0
	  stw       r31, 0x0(r30)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lfs       f0, -0x4E00(r2)
	  addi      r3, r3, 0x24
	  stfs      f0, 0x50(r30)
	  bl        -0x11EEDC
	  lwz       r3, 0x10(r30)
	  stb       r31, 0xF0(r3)

	.loc_0x190:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x33C

	.loc_0x198:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x1F8
	  lfs       f2, 0x50(r30)
	  lfs       f1, -0x4E04(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x1D4
	  lfs       f0, -0x4DF4(r2)
	  lwz       r3, 0x10(r30)
	  fmuls     f0, f0, f2
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x1F0

	.loc_0x1D4:
	  lwz       r3, 0x10(r30)
	  li        r0, 0xFF
	  stb       r0, 0xF0(r3)
	  lwz       r0, 0x4(r30)
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4E00(r2)
	  stfs      f0, 0x50(r30)

	.loc_0x1F0:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x33C

	.loc_0x1F8:
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2F0
	  bge-      .loc_0x338
	  cmpwi     r0, 0
	  bge-      .loc_0x210
	  b         .loc_0x338

	.loc_0x210:
	  lfs       f1, 0x50(r30)
	  lfs       f0, -0x4DFC(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x338
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r31, r3, 0x24
	  addi      r3, r31, 0
	  bl        -0x1205BC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x338
	  mr        r3, r31
	  bl        -0x11D600
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm.   r0,r0,27,24,31
	  beq-      .loc_0x28C
	  lwz       r5, 0x28(r30)
	  li        r4, 0
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r5)
	  lwz       r0, 0x30(r30)
	  stw       r0, 0x28(r30)
	  lwz       r3, 0x28(r30)
	  bl        -0x13C44
	  li        r0, 0x4
	  stw       r0, 0x4(r30)
	  b         .loc_0x2C0

	.loc_0x28C:
	  lwz       r5, 0x28(r30)
	  li        r4, 0
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r5)
	  lwz       r0, 0x38(r30)
	  stw       r0, 0x28(r30)
	  lwz       r3, 0x28(r30)
	  bl        -0x13C7C
	  li        r0, 0x5
	  stw       r0, 0x4(r30)

	.loc_0x2C0:
	  lwz       r4, 0x3C(r30)
	  li        r5, 0
	  li        r0, 0x1
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4E00(r2)
	  stfs      f0, 0x50(r30)
	  lwz       r3, 0x24(r30)
	  bl        -0x14A54
	  b         .loc_0x338

	.loc_0x2F0:
	  mr        r3, r30
	  bl        0x108
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x338
	  lwz       r3, 0x1C(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0x28(r31)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x338
	  li        r3, 0x111
	  bl        -0xEED98
	  li        r0, 0x3
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4E00(r2)
	  stfs      f0, 0x50(r30)

	.loc_0x338:
	  lwz       r3, 0x0(r30)

	.loc_0x33C:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019413C
 * Size:	0000A8
 */
void zen::ogScrMakeDefaultMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  mr        r31, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x94
	  cmpwi     r0, 0x4
	  bge-      .loc_0x94
	  lfs       f1, -0x4DF0(r2)
	  addi      r3, r1, 0x10
	  lfs       f2, -0x4E08(r2)
	  li        r4, 0
	  lfs       f3, -0x4DEC(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1C00C
	  addi      r3, r1, 0x10
	  bl        0x1C114
	  lwz       r3, 0x8(r31)
	  addi      r6, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  bl        0x1ED34
	  lwz       r3, 0xC(r31)
	  addi      r6, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  bl        0x1ED20
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x10(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x10(r1)

	.loc_0x94:
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801941E4
 * Size:	000020
 */
bool zen::ogScrMakeDefaultMgr::checkTypingAll()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x28(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x18
	  li        r3, 0x1
	  blr

	.loc_0x18:
	  li        r3, 0
	  blr
	*/
}
