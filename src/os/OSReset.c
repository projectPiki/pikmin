

/*
 * --INFO--
 * Address:	801FA0C0
 * Size:	000084
 */
void OSRegisterResetFunction(void)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x3208(r13)
	  b         .loc_0xC

	.loc_0x8:
	  lwz       r5, 0x8(r5)

	.loc_0xC:
	  cmplwi    r5, 0
	  beq-      .loc_0x24
	  lwz       r4, 0x4(r5)
	  lwz       r0, 0x4(r3)
	  cmplw     r4, r0
	  ble+      .loc_0x8

	.loc_0x24:
	  cmplwi    r5, 0
	  bne-      .loc_0x5C
	  addi      r5, r13, 0x3208
	  lwzu      r4, 0x4(r5)
	  cmplwi    r4, 0
	  bne-      .loc_0x44
	  stw       r3, 0x3208(r13)
	  b         .loc_0x48

	.loc_0x44:
	  stw       r3, 0x8(r4)

	.loc_0x48:
	  stw       r4, 0xC(r3)
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  stw       r3, 0x0(r5)
	  blr

	.loc_0x5C:
	  stw       r5, 0x8(r3)
	  lwz       r4, 0xC(r5)
	  stw       r3, 0xC(r5)
	  cmplwi    r4, 0
	  stw       r4, 0xC(r3)
	  bne-      .loc_0x7C
	  stw       r3, 0x3208(r13)
	  blr

	.loc_0x7C:
	  stw       r3, 0x8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void OSUnregisterResetFunction(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void CallResetFunctions(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FA144
 * Size:	000070
 */
void Reset(void)
{
	/*
	.loc_0x0:
	  b         .loc_0x20

	.loc_0x4:
	  mfspr     r8, 0x3F0
	  ori       r8, r8, 0x8
	  mtspr     1008, r8
	  isync
	  sync
	  nop
	  b         .loc_0x24

	.loc_0x20:
	  b         .loc_0x40

	.loc_0x24:
	  mftbl     r5

	.loc_0x28:
	  mftbl     r6
	  sub       r7, r6, r5
	  cmplwi    r7, 0x1124
	  blt+      .loc_0x28
	  nop
	  b         .loc_0x44

	.loc_0x40:
	  b         .loc_0x60

	.loc_0x44:
	  lis       r8, 0xCC00
	  ori       r8, r8, 0x3000
	  li        r4, 0x3
	  stw       r4, 0x24(r8)
	  stw       r3, 0x24(r8)
	  nop
	  b         .loc_0x64

	.loc_0x60:
	  b         .loc_0x6C

	.loc_0x64:
	  nop
	  b         .loc_0x64

	.loc_0x6C:
	  b         .loc_0x4
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void KillThreads(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FA1B4
 * Size:	000048
 */
void __OSDoHotReset(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x124C
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x2000
	  li        r0, 0
	  sth       r0, 0x2(r3)
	  bl        -0x34C4
	  rlwinm    r3,r31,3,0,28
	  bl        -0xA0
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801FA1FC
 * Size:	0001B8
 */
void OSResetSystem(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  mr        r26, r3
	  mr        r30, r4
	  mr        r31, r5
	  bl        0x190C
	  bl        -0x3750
	  b         .loc_0x28

	.loc_0x28:
	  b         .loc_0x2C

	.loc_0x2C:
	  lwz       r28, 0x3208(r13)
	  li        r29, 0
	  b         .loc_0x38

	.loc_0x38:
	  b         .loc_0x3C

	.loc_0x3C:
	  b         .loc_0x60

	.loc_0x40:
	  li        r3, 0
	  lwz       r12, 0x0(r28)
	  mtlr      r12
	  blrl
	  cntlzw    r0, r3
	  lwz       r28, 0x8(r28)
	  rlwinm    r0,r0,27,5,31
	  or        r29, r29, r0

	.loc_0x60:
	  cmplwi    r28, 0
	  bne+      .loc_0x40
	  bl        0xAEC
	  cntlzw    r0, r3
	  rlwinm    r0,r0,27,5,31
	  or        r29, r29, r0
	  cmpwi     r29, 0
	  beq-      .loc_0x88
	  li        r0, 0
	  b         .loc_0x8C

	.loc_0x88:
	  li        r0, 0x1

	.loc_0x8C:
	  cmpwi     r0, 0
	  beq+      .loc_0x2C
	  cmpwi     r26, 0
	  beq-      .loc_0xD0
	  cmpwi     r31, 0
	  beq-      .loc_0xD0
	  bl        0x6A8
	  lbz       r0, 0x13(r3)
	  ori       r0, r0, 0x40
	  stb       r0, 0x13(r3)
	  li        r3, 0x1
	  bl        0xA54
	  b         .loc_0xC0

	.loc_0xC0:
	  b         .loc_0xC4

	.loc_0xC4:
	  bl        0xA90
	  cmpwi     r3, 0
	  beq+      .loc_0xC4

	.loc_0xD0:
	  bl        -0x1350
	  lwz       r29, 0x3208(r13)
	  mr        r27, r3
	  li        r28, 0
	  b         .loc_0xE4

	.loc_0xE4:
	  b         .loc_0xE8

	.loc_0xE8:
	  b         .loc_0x10C

	.loc_0xEC:
	  li        r3, 0x1
	  lwz       r12, 0x0(r29)
	  mtlr      r12
	  blrl
	  cntlzw    r0, r3
	  lwz       r29, 0x8(r29)
	  rlwinm    r0,r0,27,5,31
	  or        r28, r28, r0

	.loc_0x10C:
	  cmplwi    r29, 0
	  bne+      .loc_0xEC
	  bl        0xA40
	  cmpwi     r26, 0x1
	  bne-      .loc_0x144
	  bl        -0x13A0
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x2000
	  li        r0, 0
	  sth       r0, 0x2(r3)
	  bl        -0x3618
	  rlwinm    r3,r30,3,0,28
	  bl        -0x1F4
	  b         .loc_0x198

	.loc_0x144:
	  lis       r3, 0x8000
	  lwz       r3, 0xDC(r3)
	  b         .loc_0x150

	.loc_0x150:
	  b         .loc_0x154

	.loc_0x154:
	  b         .loc_0x180

	.loc_0x158:
	  lhz       r0, 0x2C8(r3)
	  lwz       r28, 0x2FC(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x178
	  bge-      .loc_0x17C
	  cmpwi     r0, 0x1
	  beq-      .loc_0x178
	  b         .loc_0x17C

	.loc_0x178:
	  bl        0x1F54

	.loc_0x17C:
	  mr        r3, r28

	.loc_0x180:
	  cmplwi    r3, 0
	  bne+      .loc_0x158
	  bl        0x17E0
	  mr        r3, r30
	  mr        r4, r31
	  bl        -0x480

	.loc_0x198:
	  mr        r3, r27
	  bl        -0x13F4
	  bl        0x17C8
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void OSGetResetCode(void)
{
	// UNUSED FUNCTION
}
