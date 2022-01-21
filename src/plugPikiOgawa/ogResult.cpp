#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80183408
 * Size:	000DE0
 */
void zen::ogScrResultMgr::ogScrResultMgrSub()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stmw      r19, 0x5C(r1)
	  addi      r31, r3, 0
	  addi      r29, r4, 0x4088
	  li        r3, 0xF8
	  bl        -0x13C424
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x88
	  addi      r19, r20, 0
	  addi      r3, r1, 0x4C
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x301D8
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x4C
	  addi      r3, r19, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x2D55C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r20)
	  li        r0, 0
	  stb       r0, 0xEC(r20)
	  stw       r0, 0xF0(r20)
	  stw       r0, 0xF4(r20)

	.loc_0x88:
	  stw       r20, 0x30(r31)
	  addi      r4, r29, 0xFE4
	  li        r5, 0
	  lwz       r3, 0x30(r31)
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x2F758
	  lwz       r3, 0x30(r31)
	  lis       r4, 0x626C
	  addi      r4, r4, 0x636B
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x34(r31)
	  li        r20, 0
	  li        r3, 0xF8
	  lwz       r4, 0x34(r31)
	  stb       r20, 0xF0(r4)
	  bl        -0x13C4DC
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x13C
	  addi      r19, r21, 0
	  addi      r3, r1, 0x40
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x30120
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x40
	  addi      r3, r19, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x2D4A4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r21)
	  stb       r20, 0xEC(r21)
	  stw       r20, 0xF0(r21)
	  stw       r20, 0xF4(r21)

	.loc_0x13C:
	  stw       r21, 0xC(r31)
	  addi      r4, r29, 0xFFC
	  li        r5, 0
	  lwz       r3, 0xC(r31)
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x2F6A4
	  li        r3, 0x1C
	  bl        -0x13C560
	  cmplwi    r3, 0
	  beq-      .loc_0x19C
	  li        r6, 0
	  stw       r6, 0x0(r3)
	  lis       r4, 0x8022
	  addi      r5, r4, 0x2758
	  stw       r6, 0x4(r3)
	  stw       r6, 0x8(r3)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x10(r3)
	  stw       r0, 0x14(r3)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x18(r3)
	  stw       r6, 0xC(r3)

	.loc_0x19C:
	  stw       r3, 0x2C(r31)
	  lwz       r3, 0x2C(r31)
	  lwz       r4, 0xC(r31)
	  bl        0x6AF64
	  lwz       r3, 0xC(r31)
	  lis       r4, 0x726F
	  addi      r4, r4, 0x6F74
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r31)
	  lis       r20, 0x706F
	  addi      r4, r20, 0x5F31
	  lwz       r3, 0xC(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x38(r31)
	  addi      r4, r20, 0x3275
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x3C(r31)
	  addi      r4, r20, 0x3264
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x40(r31)
	  addi      r4, r20, 0x3375
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x44(r31)
	  addi      r4, r20, 0x3363
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x48(r31)
	  addi      r4, r20, 0x3364
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r31)
	  lis       r20, 0x705F
	  addi      r4, r20, 0x7263
	  lwz       r3, 0xC(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x50(r31)
	  addi      r4, r20, 0x6263
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x54(r31)
	  addi      r4, r20, 0x7963
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x58(r31)
	  lis       r3, 0x675F
	  addi      r4, r3, 0x7370
	  lwz       r3, 0xC(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x5C(r31)
	  lis       r20, 0x6461
	  addi      r4, r20, 0x7461
	  lwz       r3, 0xC(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x84(r31)
	  addi      r4, r20, 0x5F31
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x88(r31)
	  addi      r4, r20, 0x5F32
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8C(r31)
	  addi      r4, r20, 0x5F33
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x90(r31)
	  lis       r3, 0x803A
	  li        r6, 0x1
	  lwz       r4, 0x84(r31)
	  li        r5, 0
	  subi      r3, r3, 0x2848
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x88(r31)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x8C(r31)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x90(r31)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r0, 0x19C(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x42C
	  bge-      .loc_0x40C
	  cmpwi     r0, 0
	  bge-      .loc_0x418
	  b         .loc_0x450

	.loc_0x40C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x450
	  b         .loc_0x440

	.loc_0x418:
	  lwz       r3, 0x88(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x450

	.loc_0x42C:
	  lwz       r3, 0x8C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x450

	.loc_0x440:
	  lwz       r3, 0x90(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x450:
	  lwz       r3, 0xC(r31)
	  lis       r4, 0x6765
	  addi      r4, r4, 0x7470
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x94(r31)
	  lis       r20, 0x345F
	  li        r30, 0
	  lwz       r3, 0x50(r31)
	  addi      r4, r20, 0x7263
	  addi      r5, r31, 0xEC
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  li        r6, 0x3E8
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x54(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x58(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r19, 0xC(r31)
	  mr        r3, r19
	  bl        -0x4FE4
	  lis       r21, 0x7263
	  addi      r3, r19, 0
	  addi      r4, r21, 0x5F6C
	  addi      r5, r31, 0xEC
	  li        r6, 0x64
	  bl        -0x4FFC
	  addi      r3, r19, 0
	  addi      r4, r21, 0x5F63
	  addi      r5, r31, 0xEC
	  li        r6, 0xA
	  bl        -0x5010
	  addi      r3, r19, 0
	  addi      r4, r21, 0x5F72
	  addi      r5, r31, 0xEC
	  li        r6, 0x1
	  bl        -0x5024
	  addi      r3, r19, 0
	  addi      r4, r20, 0x6263
	  addi      r5, r31, 0xF0
	  li        r6, 0x3E8
	  bl        -0x5038
	  lis       r22, 0x6263
	  addi      r3, r19, 0
	  addi      r4, r22, 0x5F6C
	  addi      r5, r31, 0xF0
	  li        r6, 0x64
	  bl        -0x5050
	  addi      r3, r19, 0
	  addi      r4, r22, 0x5F63
	  addi      r5, r31, 0xF0
	  li        r6, 0xA
	  bl        -0x5064
	  addi      r3, r19, 0
	  addi      r4, r22, 0x5F72
	  addi      r5, r31, 0xF0
	  li        r6, 0x1
	  bl        -0x5078
	  addi      r3, r19, 0
	  addi      r4, r20, 0x7963
	  addi      r5, r31, 0xF4
	  li        r6, 0x3E8
	  bl        -0x508C
	  lis       r28, 0x7963
	  addi      r3, r19, 0
	  addi      r4, r28, 0x5F6C
	  addi      r5, r31, 0xF4
	  li        r6, 0x64
	  bl        -0x50A4
	  addi      r3, r19, 0
	  addi      r4, r28, 0x5F63
	  addi      r5, r31, 0xF4
	  li        r6, 0xA
	  bl        -0x50B8
	  addi      r3, r19, 0
	  addi      r4, r28, 0x5F72
	  addi      r5, r31, 0xF4
	  li        r6, 0x1
	  bl        -0x50CC
	  lis       r23, 0x7470
	  addi      r3, r19, 0
	  addi      r4, r23, 0x5F34
	  addi      r5, r31, 0xF8
	  li        r6, 0x3E8
	  bl        -0x50E4
	  addi      r3, r19, 0
	  addi      r4, r23, 0x5F6C
	  addi      r5, r31, 0xF8
	  li        r6, 0x64
	  bl        -0x50F8
	  addi      r3, r19, 0
	  addi      r4, r23, 0x5F63
	  addi      r5, r31, 0xF8
	  li        r6, 0xA
	  bl        -0x510C
	  addi      r3, r19, 0
	  addi      r4, r23, 0x5F72
	  addi      r5, r31, 0xF8
	  li        r6, 0x1
	  bl        -0x5120
	  addi      r3, r19, 0
	  addi      r4, r20, 0x626F
	  addi      r5, r31, 0xFC
	  li        r6, 0x3E8
	  bl        -0x5134
	  lis       r23, 0x626F
	  addi      r3, r19, 0
	  addi      r4, r23, 0x5F6C
	  addi      r5, r31, 0xFC
	  li        r6, 0x64
	  bl        -0x514C
	  addi      r3, r19, 0
	  addi      r4, r23, 0x5F63
	  addi      r5, r31, 0xFC
	  li        r6, 0xA
	  bl        -0x5160
	  addi      r3, r19, 0
	  addi      r4, r23, 0x5F72
	  addi      r5, r31, 0xFC
	  li        r6, 0x1
	  bl        -0x5174
	  addi      r3, r19, 0
	  addi      r4, r20, 0x6261
	  addi      r5, r31, 0x100
	  li        r6, 0x3E8
	  bl        -0x5188
	  lis       r24, 0x6261
	  addi      r3, r19, 0
	  addi      r4, r24, 0x5F6C
	  addi      r5, r31, 0x100
	  li        r6, 0x64
	  bl        -0x51A0
	  addi      r3, r19, 0
	  addi      r4, r24, 0x5F63
	  addi      r5, r31, 0x100
	  li        r6, 0xA
	  bl        -0x51B4
	  addi      r3, r19, 0
	  addi      r4, r24, 0x5F72
	  addi      r5, r31, 0x100
	  li        r6, 0x1
	  bl        -0x51C8
	  addi      r3, r19, 0
	  addi      r4, r20, 0x7364
	  addi      r5, r31, 0x104
	  li        r6, 0x3E8
	  bl        -0x51DC
	  lis       r25, 0x7364
	  addi      r3, r19, 0
	  addi      r4, r25, 0x5F6C
	  addi      r5, r31, 0x104
	  li        r6, 0x64
	  bl        -0x51F4
	  addi      r3, r19, 0
	  addi      r4, r25, 0x5F63
	  addi      r5, r31, 0x104
	  li        r6, 0xA
	  bl        -0x5208
	  addi      r3, r19, 0
	  addi      r4, r25, 0x5F72
	  addi      r5, r31, 0x104
	  li        r6, 0x1
	  bl        -0x521C
	  lis       r27, 0x3462
	  addi      r3, r19, 0
	  addi      r4, r27, 0x6F32
	  addi      r5, r31, 0x108
	  li        r6, 0x3E8
	  bl        -0x5234
	  addi      r3, r19, 0
	  addi      r4, r23, 0x326C
	  addi      r5, r31, 0x108
	  li        r6, 0x64
	  bl        -0x5248
	  addi      r3, r19, 0
	  addi      r4, r23, 0x3263
	  addi      r5, r31, 0x108
	  li        r6, 0xA
	  bl        -0x525C
	  addi      r3, r19, 0
	  addi      r4, r23, 0x3272
	  addi      r5, r31, 0x108
	  li        r6, 0x1
	  bl        -0x5270
	  addi      r3, r19, 0
	  addi      r4, r27, 0x6132
	  addi      r5, r31, 0x10C
	  li        r6, 0x3E8
	  bl        -0x5284
	  addi      r3, r19, 0
	  addi      r4, r24, 0x326C
	  addi      r5, r31, 0x10C
	  li        r6, 0x64
	  bl        -0x5298
	  addi      r3, r19, 0
	  addi      r4, r24, 0x3263
	  addi      r5, r31, 0x10C
	  li        r6, 0xA
	  bl        -0x52AC
	  addi      r3, r19, 0
	  addi      r4, r24, 0x3272
	  addi      r5, r31, 0x10C
	  li        r6, 0x1
	  bl        -0x52C0
	  lis       r26, 0x3473
	  addi      r3, r19, 0
	  addi      r4, r26, 0x6432
	  addi      r5, r31, 0x110
	  li        r6, 0x3E8
	  bl        -0x52D8
	  addi      r3, r19, 0
	  addi      r4, r25, 0x326C
	  addi      r5, r31, 0x110
	  li        r6, 0x64
	  bl        -0x52EC
	  addi      r3, r19, 0
	  addi      r4, r25, 0x3263
	  addi      r5, r31, 0x110
	  li        r6, 0xA
	  bl        -0x5300
	  addi      r3, r19, 0
	  addi      r4, r25, 0x3272
	  addi      r5, r31, 0x110
	  li        r6, 0x1
	  bl        -0x5314
	  lwz       r3, 0xC(r31)
	  addi      r4, r20, 0x626F
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x98(r31)
	  addi      r4, r20, 0x6261
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x9C(r31)
	  addi      r4, r20, 0x7364
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xA0(r31)
	  addi      r4, r27, 0x6F32
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xBC(r31)
	  addi      r4, r27, 0x6132
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC0(r31)
	  addi      r4, r26, 0x6432
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC4(r31)
	  addi      r4, r20, 0x7263
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC8(r31)
	  addi      r4, r20, 0x7963
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xCC(r31)
	  addi      r4, r20, 0x6263
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xD0(r31)
	  addi      r4, r21, 0x5F72
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xD4(r31)
	  addi      r4, r28, 0x5F72
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xDC(r31)
	  addi      r4, r22, 0x5F72
	  li        r5, 0x1
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xD8(r31)
	  lis       r26, 0x6463
	  addi      r3, r19, 0
	  addi      r4, r26, 0x5F6C
	  addi      r5, r31, 0x120
	  li        r6, 0xA
	  bl        -0x54AC
	  addi      r3, r19, 0
	  addi      r4, r26, 0x5F63
	  addi      r5, r31, 0x120
	  li        r6, 0x1
	  bl        -0x54C0
	  addi      r3, r19, 0
	  addi      r4, r26, 0x5F72
	  addi      r5, r31, 0x120
	  li        r6, 0x1
	  bl        -0x54D4
	  lis       r27, 0x726F
	  addi      r3, r19, 0
	  addi      r4, r27, 0x5F6C
	  addi      r5, r31, 0x124
	  li        r6, 0xA
	  bl        -0x54EC
	  addi      r3, r19, 0
	  addi      r4, r27, 0x5F63
	  addi      r5, r31, 0x124
	  li        r6, 0x1
	  bl        -0x5500
	  addi      r3, r19, 0
	  addi      r4, r27, 0x5F72
	  addi      r5, r31, 0x124
	  li        r6, 0x1
	  bl        -0x5514
	  lis       r28, 0x7469
	  addi      r3, r19, 0
	  addi      r4, r28, 0x5F6C
	  addi      r5, r31, 0x128
	  li        r6, 0xA
	  bl        -0x552C
	  addi      r3, r19, 0
	  addi      r4, r28, 0x5F63
	  addi      r5, r31, 0x128
	  li        r6, 0x1
	  bl        -0x5540
	  addi      r3, r19, 0
	  addi      r4, r28, 0x5F72
	  addi      r5, r31, 0x128
	  li        r6, 0x1
	  bl        -0x5554
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  addi      r4, r26, 0x5F6C
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x60(r31)
	  addi      r3, r19, 0
	  addi      r4, r26, 0x5F63
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x64(r31)
	  addi      r3, r19, 0
	  addi      r4, r26, 0x5F72
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x68(r31)
	  addi      r3, r19, 0
	  addi      r4, r23, 0x5F72
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xA4(r31)
	  addi      r3, r19, 0
	  addi      r4, r24, 0x5F72
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xA8(r31)
	  addi      r3, r19, 0
	  addi      r4, r25, 0x5F72
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xAC(r31)
	  addi      r3, r19, 0
	  addi      r4, r23, 0x3272
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB0(r31)
	  addi      r3, r19, 0
	  addi      r4, r24, 0x3272
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB4(r31)
	  addi      r3, r19, 0
	  addi      r4, r25, 0x3272
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB8(r31)
	  addi      r3, r19, 0
	  addi      r4, r28, 0x5F6C
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x6C(r31)
	  addi      r3, r19, 0
	  addi      r4, r28, 0x5F63
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x70(r31)
	  addi      r3, r19, 0
	  addi      r4, r28, 0x5F72
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x74(r31)
	  addi      r3, r19, 0
	  addi      r4, r27, 0x5F6C
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x78(r31)
	  addi      r3, r19, 0
	  addi      r4, r27, 0x5F63
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x7C(r31)
	  addi      r3, r19, 0
	  addi      r4, r27, 0x5F72
	  lwz       r12, 0x0(r19)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x80(r31)
	  li        r3, 0x6F
	  li        r0, 0xDE
	  stw       r3, 0xF0(r31)
	  li        r5, 0x14D
	  li        r4, 0x1BC
	  stw       r0, 0xEC(r31)
	  li        r3, 0x22B
	  li        r0, 0x29A
	  stw       r5, 0xF4(r31)
	  li        r8, 0x309
	  li        r7, 0x3E7
	  stw       r4, 0xF8(r31)
	  li        r6, 0x4D
	  li        r5, 0x58
	  stw       r3, 0xFC(r31)
	  li        r4, 0x63
	  li        r3, 0x1E
	  stw       r0, 0x100(r31)
	  li        r0, 0x37
	  stw       r8, 0x104(r31)
	  stw       r7, 0x114(r31)
	  stw       r30, 0x118(r31)
	  stw       r6, 0x120(r31)
	  stw       r5, 0x128(r31)
	  stw       r4, 0x11C(r31)
	  stw       r3, 0x130(r31)
	  stw       r0, 0x12C(r31)
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  bne-      .loc_0xCA0
	  li        r0, 0x1
	  stb       r0, 0x13A(r31)
	  stb       r0, 0x13B(r31)
	  stb       r0, 0x13C(r31)
	  b         .loc_0xCCC

	.loc_0xCA0:
	  li        r4, 0
	  bl        -0x103AE0
	  stb       r3, 0x13A(r31)
	  li        r4, 0x1
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x103AF0
	  stb       r3, 0x13B(r31)
	  li        r4, 0x2
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x103B00
	  stb       r3, 0x13C(r31)

	.loc_0xCCC:
	  lbz       r0, 0x13A(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xCEC
	  lwz       r3, 0x54(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xCEC:
	  lbz       r0, 0x13B(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xD0C
	  lwz       r3, 0x50(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xD0C:
	  lbz       r0, 0x13C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xD2C
	  lwz       r3, 0x58(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xD2C:
	  addi      r0, r31, 0x150
	  stw       r0, 0x550(r31)
	  li        r0, 0
	  lis       r3, 0x1
	  stw       r0, 0x554(r31)
	  subi      r3, r3, 0x5A10
	  bl        -0x13D148
	  addi      r20, r3, 0
	  mr.       r3, r20
	  beq-      .loc_0xD5C
	  addi      r4, r29, 0x1014
	  bl        0x8444

	.loc_0xD5C:
	  stw       r20, 0x14(r31)
	  li        r3, 0x14
	  bl        -0x13D168
	  addi      r20, r3, 0
	  mr.       r3, r20
	  beq-      .loc_0xD7C
	  lwz       r4, 0xC(r31)
	  bl        0x13DA8

	.loc_0xD7C:
	  stw       r20, 0x28(r31)
	  li        r3, 0x198
	  bl        -0x13D188
	  addi      r20, r3, 0
	  mr.       r3, r20
	  beq-      .loc_0xD9C
	  lwz       r4, 0xC(r31)
	  bl        -0x5620

	.loc_0xD9C:
	  stw       r20, 0x18(r31)
	  li        r3, -0x1
	  li        r0, 0
	  stw       r3, 0x4(r31)
	  li        r3, 0xB0
	  sth       r0, 0xE8(r31)
	  bl        -0x13D1B8
	  addi      r20, r3, 0
	  mr.       r3, r20
	  beq-      .loc_0xDC8
	  bl        0x11574

	.loc_0xDC8:
	  stw       r20, 0x24(r31)
	  lmw       r19, 0x5C(r1)
	  lwz       r0, 0x94(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void zen::ogScrResultMgr::check1000(int, P2DPane*, P2DPane*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void zen::ogScrResultMgr::setEnumResultTable(zen::EnumResult*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801841E8
 * Size:	00017C
 */
zen::ogScrResultMgr::ogScrResultMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  li        r0, 0x20
	  li        r6, 0
	  mtctr     r0
	  stwu      r1, -0x18(r1)
	  addi      r7, r4, 0x5064
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x802D
	  stw       r6, 0x2F6C(r13)
	  addi      r8, r31, 0
	  addi      r4, r3, 0x4E10

	.loc_0x38:
	  lwz       r5, 0x0(r7)
	  rlwinm    r0,r5,2,0,29
	  add       r3, r4, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r5, 0
	  stw       r0, 0x150(r8)
	  beq-      .loc_0x15C
	  lwzu      r5, 0x4(r7)
	  rlwinm    r0,r5,2,0,29
	  add       r3, r4, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r5, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x15C
	  lwzu      r5, 0x4(r7)
	  addi      r6, r6, 0x1
	  rlwinm    r0,r5,2,0,29
	  add       r3, r4, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r5, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x15C
	  lwzu      r5, 0x4(r7)
	  addi      r6, r6, 0x1
	  rlwinm    r0,r5,2,0,29
	  add       r3, r4, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r5, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x15C
	  lwzu      r5, 0x4(r7)
	  addi      r6, r6, 0x1
	  rlwinm    r0,r5,2,0,29
	  add       r3, r4, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r5, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x15C
	  lwzu      r5, 0x4(r7)
	  addi      r6, r6, 0x1
	  rlwinm    r0,r5,2,0,29
	  add       r3, r4, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r5, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x15C
	  lwzu      r5, 0x4(r7)
	  addi      r6, r6, 0x1
	  rlwinm    r0,r5,2,0,29
	  add       r3, r4, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r5, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x15C
	  lwzu      r5, 0x4(r7)
	  addi      r6, r6, 0x1
	  rlwinm    r0,r5,2,0,29
	  add       r3, r4, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r5, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x15C
	  addi      r7, r7, 0x4
	  addi      r8, r8, 0x4
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x38

	.loc_0x15C:
	  mr        r3, r31
	  bl        -0xF40
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80184364
 * Size:	000170
 */
zen::ogScrResultMgr::ogScrResultMgr(zen::EnumResult*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r7, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x20
	  mtctr     r0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x802D
	  addi      r8, r31, 0
	  addi      r5, r3, 0x4E10

	.loc_0x2C:
	  lwz       r6, 0x0(r4)
	  rlwinm    r0,r6,2,0,29
	  add       r3, r5, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r6, 0
	  stw       r0, 0x150(r8)
	  beq-      .loc_0x150
	  lwzu      r6, 0x4(r4)
	  rlwinm    r0,r6,2,0,29
	  add       r3, r5, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r6, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x150
	  lwzu      r6, 0x4(r4)
	  addi      r7, r7, 0x1
	  rlwinm    r0,r6,2,0,29
	  add       r3, r5, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r6, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x150
	  lwzu      r6, 0x4(r4)
	  addi      r7, r7, 0x1
	  rlwinm    r0,r6,2,0,29
	  add       r3, r5, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r6, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x150
	  lwzu      r6, 0x4(r4)
	  addi      r7, r7, 0x1
	  rlwinm    r0,r6,2,0,29
	  add       r3, r5, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r6, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x150
	  lwzu      r6, 0x4(r4)
	  addi      r7, r7, 0x1
	  rlwinm    r0,r6,2,0,29
	  add       r3, r5, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r6, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x150
	  lwzu      r6, 0x4(r4)
	  addi      r7, r7, 0x1
	  rlwinm    r0,r6,2,0,29
	  add       r3, r5, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r6, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x150
	  lwzu      r6, 0x4(r4)
	  addi      r7, r7, 0x1
	  rlwinm    r0,r6,2,0,29
	  add       r3, r5, r0
	  lwz       r0, 0x0(r3)
	  cmpwi     r6, 0
	  stw       r0, 0x154(r8)
	  addi      r8, r8, 0x4
	  beq-      .loc_0x150
	  addi      r4, r4, 0x4
	  addi      r8, r8, 0x4
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0x2C

	.loc_0x150:
	  mr        r3, r31
	  bl        -0x10B0
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801844D4
 * Size:	000744
 */
void zen::ogScrResultMgr::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stw       r31, 0x10C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x108(r1)
	  stw       r29, 0x104(r1)
	  lwz       r0, 0x2F6C(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0xA4
	  li        r3, 0x1
	  li        r4, -0x7B
	  bl        -0x43B8
	  li        r0, 0x1
	  stw       r0, 0x120(r31)
	  li        r3, 0x2
	  li        r0, 0x3
	  stw       r3, 0x128(r31)
	  li        r8, 0x4D
	  li        r7, 0x1E
	  stw       r0, 0x124(r31)
	  li        r6, 0x929
	  li        r5, 0xD80
	  stw       r8, 0x11C(r31)
	  li        r4, 0x11D7
	  li        r3, 0x4D2
	  stw       r7, 0x12C(r31)
	  li        r0, 0x2694
	  stw       r7, 0x130(r31)
	  stw       r6, 0x108(r31)
	  stw       r5, 0x10C(r31)
	  stw       r4, 0x110(r31)
	  stw       r3, 0xF0(r31)
	  stw       r6, 0xEC(r31)
	  stw       r5, 0xF4(r31)
	  stw       r0, 0xF8(r31)
	  stw       r3, 0xFC(r31)
	  stw       r6, 0x100(r31)
	  stw       r5, 0x104(r31)
	  stw       r8, 0x134(r31)
	  b         .loc_0x1F8

	.loc_0xA4:
	  mr        r3, r0
	  bl        -0x1039CC
	  stw       r3, 0x120(r31)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x1039C4
	  stw       r3, 0x130(r31)
	  lwz       r3, 0x120(r31)
	  lwz       r0, 0x130(r31)
	  sub       r0, r0, r3
	  stw       r0, 0x128(r31)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x103934
	  stw       r3, 0x11C(r31)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x103948
	  stw       r3, 0x12C(r31)
	  lis       r3, 0x803D
	  lis       r7, 0x803D
	  lwz       r5, 0x11C(r31)
	  lis       r6, 0x803D
	  lwz       r0, 0x12C(r31)
	  addi      r9, r3, 0x1EB8
	  addi      r10, r7, 0x1EA0
	  sub       r0, r0, r5
	  stw       r0, 0x124(r31)
	  lis       r5, 0x803D
	  addi      r8, r6, 0x1E70
	  lwz       r3, 0x2F6C(r13)
	  lis       r4, 0x803D
	  addi      r6, r4, 0x1EAC
	  lwz       r0, 0x0(r3)
	  addi      r5, r5, 0x1E58
	  addi      r4, r9, 0x8
	  stw       r0, 0x108(r31)
	  lwz       r7, 0x2F6C(r13)
	  lwz       r0, 0x4(r7)
	  stw       r0, 0x10C(r31)
	  lwz       r7, 0x2F6C(r13)
	  lwz       r0, 0x8(r7)
	  stw       r0, 0x110(r31)
	  lwz       r7, 0x0(r10)
	  lwz       r0, 0x0(r8)
	  add       r0, r7, r0
	  stw       r0, 0xF0(r31)
	  lwz       r7, 0x4(r10)
	  lwz       r0, 0x4(r8)
	  add       r0, r7, r0
	  stw       r0, 0xEC(r31)
	  lwz       r7, 0x8(r10)
	  lwz       r0, 0x8(r8)
	  add       r0, r7, r0
	  stw       r0, 0xF4(r31)
	  lwz       r8, 0xF4(r31)
	  lwz       r0, 0xF0(r31)
	  lwz       r7, 0xEC(r31)
	  add       r0, r0, r8
	  add       r0, r7, r0
	  stw       r0, 0xF8(r31)
	  lwz       r7, 0x8(r6)
	  lwz       r0, 0x4(r6)
	  lwz       r6, 0x0(r6)
	  add       r0, r0, r7
	  add       r0, r6, r0
	  stw       r0, 0xFC(r31)
	  lwz       r8, 0x8(r9)
	  lwz       r7, 0x4(r9)
	  lwz       r6, 0x8(r5)
	  lwz       r0, 0x4(r5)
	  add       r7, r7, r8
	  lwz       r8, 0x0(r9)
	  add       r0, r0, r6
	  lwz       r5, 0x0(r5)
	  add       r6, r8, r7
	  add       r0, r5, r0
	  sub       r0, r0, r6
	  stw       r0, 0x100(r31)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x4(r9)
	  lwz       r3, 0x0(r9)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  stw       r0, 0x104(r31)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x102F54
	  stw       r3, 0x134(r31)

	.loc_0x1F8:
	  li        r3, 0x1
	  lwz       r4, 0x120(r31)
	  bl        -0x4588
	  li        r3, 0x2
	  lwz       r4, 0x11C(r31)
	  bl        -0x4594
	  li        r3, 0x3
	  lwz       r4, 0x124(r31)
	  bl        -0x45A0
	  li        r3, 0x4
	  lwz       r4, 0x128(r31)
	  bl        -0x45AC
	  li        r3, 0x5
	  lwz       r4, 0x134(r31)
	  bl        -0x45B8
	  lwz       r4, 0x94(r31)
	  addi      r3, r31, 0x13D
	  lwz       r4, 0x10C(r4)
	  bl        0x94C44
	  addi      r3, r31, 0x13D
	  bl        -0x45A4
	  lwz       r3, 0x94(r31)
	  addi      r0, r31, 0x13D
	  addi      r4, r31, 0x550
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0x14(r31)
	  bl        0x7E28
	  lwz       r3, 0x14(r31)
	  li        r29, 0x1
	  li        r0, 0x3
	  stb       r29, 0x4E0(r3)
	  li        r4, 0
	  stw       r0, 0x4(r31)
	  lwz       r3, 0x14(r31)
	  bl        0x7560
	  lwz       r3, 0x34(r31)
	  li        r30, 0
	  li        r4, 0
	  stb       r30, 0xF0(r3)
	  li        r5, -0x1E0
	  sth       r30, 0xEA(r31)
	  lfs       f0, -0x5060(r2)
	  stfs      f0, 0xE0(r31)
	  sth       r30, 0xE8(r31)
	  lwz       r3, 0x20(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x120(r31)
	  cmpwi     r0, 0xA
	  bge-      .loc_0x2FC
	  lwz       r3, 0x60(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x64(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x68(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x32C

	.loc_0x2FC:
	  lwz       r3, 0x60(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x64(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x68(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x32C:
	  lwz       r0, 0x128(r31)
	  cmpwi     r0, 0xA
	  bge-      .loc_0x374
	  lwz       r3, 0x6C(r31)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x70(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x74(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x3AC

	.loc_0x374:
	  lwz       r3, 0x6C(r31)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x70(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x74(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x3AC:
	  lwz       r0, 0x124(r31)
	  cmpwi     r0, 0xA
	  bge-      .loc_0x3F4
	  lwz       r3, 0x78(r31)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x7C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x80(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x42C

	.loc_0x3F4:
	  lwz       r3, 0x78(r31)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x7C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x80(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x42C:
	  lwz       r0, 0xFC(r31)
	  lwz       r3, 0xA4(r31)
	  cmpwi     r0, 0x3E8
	  lwz       r5, 0x98(r31)
	  blt-      .loc_0x470
	  lbz       r0, 0xC(r5)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0xE
	  mtlr      r12
	  blrl
	  b         .loc_0x480

	.loc_0x470:
	  lbz       r0, 0xC(r5)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r5)

	.loc_0x480:
	  lwz       r0, 0x100(r31)
	  lwz       r3, 0xA8(r31)
	  cmpwi     r0, 0x3E8
	  lwz       r5, 0x9C(r31)
	  blt-      .loc_0x4C4
	  lbz       r0, 0xC(r5)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0xE
	  mtlr      r12
	  blrl
	  b         .loc_0x4D4

	.loc_0x4C4:
	  lbz       r0, 0xC(r5)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r5)

	.loc_0x4D4:
	  lwz       r0, 0x104(r31)
	  lwz       r3, 0xAC(r31)
	  cmpwi     r0, 0x3E8
	  lwz       r5, 0xA0(r31)
	  blt-      .loc_0x518
	  lbz       r0, 0xC(r5)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0xE
	  mtlr      r12
	  blrl
	  b         .loc_0x528

	.loc_0x518:
	  lbz       r0, 0xC(r5)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r5)

	.loc_0x528:
	  lwz       r0, 0x108(r31)
	  lwz       r3, 0xB0(r31)
	  cmpwi     r0, 0x3E8
	  lwz       r5, 0xBC(r31)
	  blt-      .loc_0x56C
	  lbz       r0, 0xC(r5)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0xE
	  mtlr      r12
	  blrl
	  b         .loc_0x57C

	.loc_0x56C:
	  lbz       r0, 0xC(r5)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r5)

	.loc_0x57C:
	  lwz       r0, 0x10C(r31)
	  lwz       r3, 0xB4(r31)
	  cmpwi     r0, 0x3E8
	  lwz       r5, 0xC0(r31)
	  blt-      .loc_0x5C0
	  lbz       r0, 0xC(r5)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0xE
	  mtlr      r12
	  blrl
	  b         .loc_0x5D0

	.loc_0x5C0:
	  lbz       r0, 0xC(r5)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r5)

	.loc_0x5D0:
	  lwz       r0, 0x110(r31)
	  lwz       r3, 0xB8(r31)
	  cmpwi     r0, 0x3E8
	  lwz       r5, 0xC4(r31)
	  blt-      .loc_0x614
	  lbz       r0, 0xC(r5)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0xE
	  mtlr      r12
	  blrl
	  b         .loc_0x624

	.loc_0x614:
	  lbz       r0, 0xC(r5)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r5)

	.loc_0x624:
	  lwz       r0, 0xF0(r31)
	  lwz       r3, 0xD8(r31)
	  cmpwi     r0, 0x3E8
	  lwz       r5, 0xD0(r31)
	  blt-      .loc_0x668
	  lbz       r0, 0xC(r5)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0xC
	  mtlr      r12
	  blrl
	  b         .loc_0x678

	.loc_0x668:
	  lbz       r0, 0xC(r5)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r5)

	.loc_0x678:
	  lwz       r0, 0xEC(r31)
	  lwz       r3, 0xD4(r31)
	  cmpwi     r0, 0x3E8
	  lwz       r5, 0xC8(r31)
	  blt-      .loc_0x6BC
	  lbz       r0, 0xC(r5)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0xC
	  mtlr      r12
	  blrl
	  b         .loc_0x6CC

	.loc_0x6BC:
	  lbz       r0, 0xC(r5)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r5)

	.loc_0x6CC:
	  lwz       r0, 0xF4(r31)
	  lwz       r3, 0xDC(r31)
	  cmpwi     r0, 0x3E8
	  lwz       r5, 0xCC(r31)
	  blt-      .loc_0x710
	  lbz       r0, 0xC(r5)
	  li        r4, 0x1
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r3)
	  addi      r4, r4, 0xC
	  mtlr      r12
	  blrl
	  b         .loc_0x720

	.loc_0x710:
	  lbz       r0, 0xC(r5)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r5)

	.loc_0x720:
	  lwz       r3, 0x2C(r31)
	  bl        0x69B80
	  lwz       r0, 0x114(r1)
	  lwz       r31, 0x10C(r1)
	  lwz       r30, 0x108(r1)
	  lwz       r29, 0x104(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void zen::ogScrResultMgr::StartRESULT()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80184C18
 * Size:	000384
 */
void zen::ogScrResultMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  stw       r30, 0x58(r1)
	  addi      r30, r4, 0
	  lwz       r3, 0x4(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x2C
	  b         .loc_0x36C

	.loc_0x2C:
	  cmpwi     r3, 0x4
	  bne-      .loc_0x70
	  lha       r3, 0x138(r31)
	  subi      r0, r3, 0x1
	  sth       r0, 0x138(r31)
	  lha       r0, 0x138(r31)
	  cmpwi     r0, 0
	  bgt-      .loc_0x68
	  li        r0, 0x5
	  stw       r0, 0x4(r31)
	  lwz       r3, 0x18(r31)
	  lfs       f1, -0x505C(r2)
	  bl        -0x5D60
	  lfs       f0, -0x5060(r2)
	  stfs      f0, 0xE0(r31)

	.loc_0x68:
	  lwz       r3, 0x4(r31)
	  b         .loc_0x36C

	.loc_0x70:
	  lwz       r3, 0xC(r31)
	  bl        0x2DEC4
	  lwz       r3, 0x18(r31)
	  bl        -0x5C78
	  lwz       r3, 0x2C(r31)
	  bl        0x69B00
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0x5
	  bne-      .loc_0x14C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xE0(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE0(r31)
	  lfs       f1, 0xE0(r31)
	  lfs       f0, -0x505C(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xEC
	  li        r0, 0
	  stw       r0, 0x4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r3, 0x20(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r31)
	  bl        0x69B1C
	  b         .loc_0x144

	.loc_0xEC:
	  lfd       f0, -0x5050(r2)
	  li        r4, 0
	  lwz       r3, 0x20(r31)
	  fadd      f0, f0, f1
	  lfd       f1, -0x5058(r2)
	  lwz       r12, 0x0(r3)
	  fmul      f0, f1, f0
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  frsp      f0, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x50(r1)
	  lwz       r5, 0x54(r1)
	  blrl
	  lfs       f1, -0x5048(r2)
	  lfs       f0, 0xE0(r31)
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  rlwinm    r0,r0,0,24,31
	  sth       r0, 0xE8(r31)

	.loc_0x144:
	  lwz       r3, 0x4(r31)
	  b         .loc_0x36C

	.loc_0x14C:
	  cmpwi     r0, 0x6
	  bne-      .loc_0x1D8
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xE0(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE0(r31)
	  lfs       f2, 0xE0(r31)
	  lfs       f0, -0x5044(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x19C
	  li        r0, 0
	  sth       r0, 0xE8(r31)
	  li        r0, 0xFF
	  lwz       r3, 0x34(r31)
	  stb       r0, 0xF0(r3)
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x4(r31)
	  b         .loc_0x1D0

	.loc_0x19C:
	  lfs       f0, -0x505C(r2)
	  lfs       f1, -0x5048(r2)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  rlwinm    r0,r0,0,24,31
	  sth       r0, 0xE8(r31)
	  lha       r0, 0xE8(r31)
	  lwz       r3, 0x34(r31)
	  subfic    r0, r0, 0xFF
	  stb       r0, 0xF0(r3)

	.loc_0x1D0:
	  lwz       r3, 0x4(r31)
	  b         .loc_0x36C

	.loc_0x1D8:
	  cmpwi     r0, 0x7
	  blt-      .loc_0x1F0
	  li        r0, -0x1
	  stw       r0, 0x4(r31)
	  lwz       r3, 0x4(r31)
	  b         .loc_0x36C

	.loc_0x1F0:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x22C
	  lwz       r3, 0x14(r31)
	  mr        r4, r30
	  bl        0x7BB4
	  cmpwi     r3, 0x4
	  bne-      .loc_0x224
	  li        r0, 0x4
	  stw       r0, 0x4(r31)
	  lwz       r3, 0xC(r31)
	  bl        0x3A974
	  li        r0, 0x6
	  sth       r0, 0x138(r31)

	.loc_0x224:
	  lwz       r3, 0x4(r31)
	  b         .loc_0x36C

	.loc_0x22C:
	  cmpwi     r0, 0
	  bne-      .loc_0x360
	  lha       r3, 0xEA(r31)
	  cmpwi     r3, 0xFF
	  bge-      .loc_0x25C
	  addi      r0, r3, 0x8
	  sth       r0, 0xEA(r31)
	  lha       r0, 0xEA(r31)
	  cmpwi     r0, 0xFF
	  ble-      .loc_0x25C
	  li        r0, 0xFF
	  sth       r0, 0xEA(r31)

	.loc_0x25C:
	  lwz       r3, 0x24(r31)
	  mr        r4, r30
	  bl        0x110C0
	  stw       r3, 0x558(r31)
	  lwz       r0, 0x558(r31)
	  cmpwi     r0, 0xE
	  bne-      .loc_0x294
	  lfs       f0, -0x5060(r2)
	  li        r3, 0x7
	  li        r0, 0x6
	  stfs      f0, 0xE0(r31)
	  stw       r3, 0x8(r31)
	  stw       r0, 0x4(r31)
	  b         .loc_0x360

	.loc_0x294:
	  cmpwi     r0, 0xC
	  bne-      .loc_0x2B0
	  lfs       f0, -0x5060(r2)
	  li        r0, 0
	  stfs      f0, 0xE0(r31)
	  stw       r0, 0x4(r31)
	  b         .loc_0x360

	.loc_0x2B0:
	  cmpwi     r0, 0xD
	  bne-      .loc_0x2CC
	  li        r0, 0x7
	  stw       r0, 0x8(r31)
	  li        r0, 0x6
	  stw       r0, 0x4(r31)
	  b         .loc_0x360

	.loc_0x2CC:
	  cmpwi     r0, 0xF
	  bne-      .loc_0x2F0
	  lfs       f0, -0x5060(r2)
	  li        r3, 0x8
	  li        r0, 0x6
	  stfs      f0, 0xE0(r31)
	  stw       r3, 0x8(r31)
	  stw       r0, 0x4(r31)
	  b         .loc_0x360

	.loc_0x2F0:
	  cmpwi     r0, -0x1
	  bne-      .loc_0x360
	  lis       r3, 0x100
	  lwz       r4, 0x28(r30)
	  addi      r0, r3, 0x3000
	  and.      r0, r4, r0
	  beq-      .loc_0x324
	  li        r3, 0x111
	  bl        -0xDFBB4
	  lfs       f0, -0x5060(r2)
	  stfs      f0, 0xE0(r31)
	  lwz       r3, 0x24(r31)
	  bl        0x10F44

	.loc_0x324:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xE4(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE4(r31)
	  lfs       f1, 0xE4(r31)
	  lfs       f0, -0x505C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x350
	  lfs       f0, -0x5060(r2)
	  stfs      f0, 0xE4(r31)

	.loc_0x350:
	  lfs       f1, -0x5040(r2)
	  lfs       f0, 0xE4(r31)
	  fmuls     f1, f1, f0
	  bl        0x96D74

	.loc_0x360:
	  lwz       r3, 0x30(r31)
	  bl        0x2DBD4
	  lwz       r3, 0x4(r31)

	.loc_0x36C:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80184F9C
 * Size:	000104
 */
void zen::ogScrResultMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xF8(r1)
	  mr        r30, r3
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xEC
	  cmpwi     r0, 0x4
	  beq-      .loc_0xEC
	  cmpwi     r0, 0x3
	  bne-      .loc_0x48
	  lwz       r3, 0x14(r30)
	  mr        r4, r31
	  bl        0x7F6C
	  b         .loc_0xEC

	.loc_0x48:
	  lfs       f1, -0x503C(r2)
	  addi      r3, r1, 0x14
	  lfs       f2, -0x505C(r2)
	  li        r4, 0
	  lfs       f3, -0x5038(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x2B18C
	  addi      r3, r1, 0x14
	  bl        0x2B294
	  lwz       r3, 0x24(r30)
	  lbz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x90
	  mr        r4, r31
	  bl        0x1174C
	  b         .loc_0xD4

	.loc_0x90:
	  lwz       r3, 0xC(r30)
	  addi      r6, r1, 0x14
	  li        r4, 0
	  li        r5, 0
	  bl        0x2DE98
	  lha       r0, 0xEA(r30)
	  lwz       r3, 0x28(r30)
	  rlwinm    r4,r0,0,24,31
	  bl        0x13860
	  lwz       r3, 0x24(r30)
	  mr        r4, r31
	  bl        0x11718
	  lwz       r3, 0x30(r30)
	  addi      r6, r1, 0x14
	  li        r4, 0
	  li        r5, 0
	  bl        0x2DE68

	.loc_0xD4:
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x14(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x14(r1)

	.loc_0xEC:
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  lwz       r30, 0xF8(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}
