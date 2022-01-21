

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void __OSIsDebuggerPresent(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void __OSInitFPRs(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F59A8
 * Size:	000028
 */
void OSGetConsoleType(void)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x31C8(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x18
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x24

	.loc_0x18:
	  lis       r3, 0x1000
	  addi      r3, r3, 0x2
	  b         .loc_0x24

	.loc_0x24:
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F59D0
 * Size:	0002DC
 */
void OSInit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  stw       r30, 0x8(r1)
	  lwz       r0, 0x31D0(r13)
	  lis       r3, 0x802E
	  addi      r31, r3, 0x72A8
	  cmpwi     r0, 0
	  bne-      .loc_0x2C4
	  li        r0, 0x1
	  stw       r0, 0x31D0(r13)
	  bl        0x357C
	  li        r0, 0
	  lis       r3, 0x8000
	  stw       r0, 0x31CC(r13)
	  stw       r3, 0x31C8(r13)
	  stw       r0, 0x32AC(r13)
	  lwz       r3, 0xF4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  addi      r0, r3, 0xC
	  stw       r0, 0x31CC(r13)
	  lwz       r0, 0x20(r3)
	  stw       r0, 0x32AC(r13)
	  lwz       r0, 0x24(r3)
	  stw       r0, 0x337C(r13)

	.loc_0x6C:
	  lis       r3, 0x8000
	  lwz       r3, 0x30(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x88
	  lis       r3, 0x8040
	  subi      r3, r3, 0x17C0
	  b         .loc_0x88

	.loc_0x88:
	  bl        0xED8
	  lwz       r3, 0x31C8(r13)
	  lwz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xC8
	  lwz       r3, 0x31CC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xC8
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0x2
	  bge-      .loc_0xC8
	  lis       r3, 0x8040
	  subi      r3, r3, 0x37C0
	  addi      r0, r3, 0x1F
	  rlwinm    r3,r0,0,0,26
	  bl        0xE9C

	.loc_0xC8:
	  lwz       r3, 0x31C8(r13)
	  lwz       r3, 0x34(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0xE4
	  lis       r3, 0x8170
	  addi      r3, r3, 0
	  b         .loc_0xE4

	.loc_0xE4:
	  bl        0xE74
	  bl        .loc_0x2DC
	  bl        0x5E8C
	  bl        0x3CDC
	  bl        0x3534
	  lis       r3, 0x8020
	  subi      r4, r3, 0x5C4C
	  li        r3, 0x16
	  bl        0x34F4
	  bl        0x1D70
	  bl        0x1458
	  bl        0x3158
	  bl        0x5840
	  bl        0x4D2C
	  bl        0x5EC0
	  bl        0xE48
	  lwz       r3, 0x31C8(r13)
	  addi      r4, r3, 0x2C
	  lwz       r0, 0x0(r4)
	  rlwinm    r0,r0,0,3,3
	  cmplwi    r0, 0
	  beq-      .loc_0x14C
	  lis       r3, 0x1000
	  addi      r0, r3, 0x4
	  stw       r0, 0x0(r4)
	  b         .loc_0x154

	.loc_0x14C:
	  li        r0, 0x1
	  stw       r0, 0x0(r4)

	.loc_0x154:
	  lis       r3, 0xCC00
	  lwz       r5, 0x31C8(r13)
	  addi      r3, r3, 0x3000
	  crclr     6, 0x6
	  lwz       r0, 0x2C(r3)
	  mr        r3, r31
	  lwz       r4, 0x2C(r5)
	  rlwinm    r0,r0,0,0,3
	  rlwinm    r0,r0,4,28,31
	  add       r0, r4, r0
	  stw       r0, 0x2C(r5)
	  bl        0x1D40
	  addi      r3, r31, 0x20
	  crclr     6, 0x6
	  addi      r4, r31, 0x38
	  addi      r5, r31, 0x44
	  bl        0x1D2C
	  addi      r3, r31, 0x50
	  crclr     6, 0x6
	  bl        0x1D20
	  lwz       r3, 0x31C8(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x1BC
	  lwz       r4, 0x2C(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x1C8

	.loc_0x1BC:
	  lis       r3, 0x1000
	  addi      r4, r3, 0x2
	  b         .loc_0x1C8

	.loc_0x1C8:
	  rlwinm    r0,r4,0,3,3
	  cmplwi    r0, 0
	  bne-      .loc_0x1E4
	  crclr     6, 0x6
	  addi      r3, r31, 0x60
	  bl        0x1CE4
	  b         .loc_0x26C

	.loc_0x1E4:
	  lis       r3, 0x1000
	  addi      r0, r3, 0x2
	  cmpw      r4, r0
	  beq-      .loc_0x238
	  bge-      .loc_0x208
	  cmpw      r4, r3
	  beq-      .loc_0x218
	  bge-      .loc_0x228
	  b         .loc_0x258

	.loc_0x208:
	  addi      r0, r3, 0x4
	  cmpw      r4, r0
	  bge-      .loc_0x258
	  b         .loc_0x248

	.loc_0x218:
	  addi      r3, r31, 0x6C
	  crclr     6, 0x6
	  bl        0x1CA0
	  b         .loc_0x26C

	.loc_0x228:
	  addi      r3, r31, 0x7C
	  crclr     6, 0x6
	  bl        0x1C90
	  b         .loc_0x26C

	.loc_0x238:
	  addi      r3, r31, 0x8C
	  crclr     6, 0x6
	  bl        0x1C80
	  b         .loc_0x26C

	.loc_0x248:
	  addi      r3, r31, 0x9C
	  crclr     6, 0x6
	  bl        0x1C70
	  b         .loc_0x26C

	.loc_0x258:
	  subis     r4, r4, 0x1000
	  crclr     6, 0x6
	  addi      r3, r31, 0xAC
	  subi      r4, r4, 0x3
	  bl        0x1C58

	.loc_0x26C:
	  lwz       r4, 0x31C8(r13)
	  addi      r3, r31, 0xC0
	  crclr     6, 0x6
	  lwz       r0, 0x28(r4)
	  rlwinm    r4,r0,12,20,31
	  bl        0x1C40
	  bl        0xCC4
	  mr        r30, r3
	  bl        0xCC4
	  mr        r4, r3
	  crclr     6, 0x6
	  mr        r5, r30
	  addi      r3, r31, 0xD0
	  bl        0x1C20
	  lwz       r3, 0x31CC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C0
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0x2
	  blt-      .loc_0x2C0
	  bl        0x2A268

	.loc_0x2C0:
	  bl        0x3300

	.loc_0x2C4:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  lwz       r30, 0x8(r1)
	  mtlr      r0
	  addi      r1, r1, 0x10
	  blr

	.loc_0x2DC:
	*/
}

/*
 * --INFO--
 * Address:	801F5CAC
 * Size:	000280
 */
void OSExceptionInit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r20, 0x8(r1)
	  lis       r3, 0x8000
	  lwz       r0, 0x60(r3)
	  lis       r4, 0x801F
	  addi      r30, r4, 0x5FEC
	  lis       r5, 0x801F
	  lwz       r25, 0x0(r30)
	  lis       r4, 0x801F
	  addi      r5, r5, 0x5F84
	  addi      r4, r4, 0x601C
	  lis       r6, 0x802E
	  cmplwi    r0, 0
	  mr        r24, r5
	  addi      r29, r6, 0x72A8
	  sub       r23, r4, r5
	  addi      r20, r3, 0x60
	  bne-      .loc_0x98
	  addi      r3, r29, 0x124
	  crclr     6, 0x6
	  bl        0x7E40
	  lis       r4, 0x801F
	  lis       r3, 0x801F
	  addi      r0, r3, 0x5F50
	  addi      r4, r4, 0x5F2C
	  sub       r21, r0, r4
	  mr        r3, r20
	  mr        r5, r21
	  bl        -0x1F2910
	  mr        r3, r20
	  mr        r4, r21
	  bl        0xF20
	  sync
	  mr        r3, r20
	  mr        r4, r21
	  bl        0xFA0

	.loc_0x98:
	  lis       r4, 0x801F
	  lis       r3, 0x801F
	  addi      r31, r4, 0x5F50
	  addi      r0, r3, 0x5F54
	  addi      r28, r29, 0xE8
	  sub       r27, r0, r31
	  li        r26, 0
	  b         .loc_0xB8

	.loc_0xB8:
	  lis       r3, 0x801F
	  addi      r21, r3, 0x5FDC
	  lis       r22, 0x6000
	  b         .loc_0xC8

	.loc_0xC8:
	  b         .loc_0x210

	.loc_0xCC:
	  lwz       r3, 0x31CC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x108
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0x2
	  blt-      .loc_0x108
	  mr        r3, r26
	  bl        0x7D94
	  cmpwi     r3, 0
	  beq-      .loc_0x108
	  addi      r3, r29, 0x140
	  crclr     6, 0x6
	  rlwinm    r4,r26,0,24,31
	  bl        0x7D98
	  b         .loc_0x208

	.loc_0x108:
	  rlwinm    r20,r26,0,24,31
	  or        r0, r25, r20
	  stw       r0, 0x0(r30)
	  mr        r3, r26
	  bl        0x7D64
	  cmpwi     r3, 0
	  beq-      .loc_0x148
	  mr        r4, r20
	  crclr     6, 0x6
	  addi      r3, r29, 0x170
	  bl        0x7D68
	  mr        r3, r21
	  mr        r4, r31
	  mr        r5, r27
	  bl        -0x1F29D8
	  b         .loc_0x1D4

	.loc_0x148:
	  mr        r4, r21
	  b         .loc_0x150

	.loc_0x150:
	  cmplwi    r27, 0
	  addi      r3, r27, 0x3
	  rlwinm    r3,r3,30,2,31
	  ble-      .loc_0x1D4
	  rlwinm    r0,r3,29,3,31
	  cmplwi    r0, 0
	  mtctr     r0
	  beq-      .loc_0x1C0
	  b         .loc_0x174

	.loc_0x174:
	  stw       r22, 0x0(r4)
	  addi      r4, r4, 0x4
	  stw       r22, 0x0(r4)
	  addi      r4, r4, 0x4
	  stw       r22, 0x0(r4)
	  addi      r4, r4, 0x4
	  stw       r22, 0x0(r4)
	  addi      r4, r4, 0x4
	  stw       r22, 0x0(r4)
	  addi      r4, r4, 0x4
	  stw       r22, 0x0(r4)
	  addi      r4, r4, 0x4
	  stw       r22, 0x0(r4)
	  addi      r4, r4, 0x4
	  stw       r22, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x174
	  andi.     r3, r3, 0x7
	  beq-      .loc_0x1D4

	.loc_0x1C0:
	  mtctr     r3
	  b         .loc_0x1C8

	.loc_0x1C8:
	  stw       r22, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x1C8

	.loc_0x1D4:
	  lwz       r3, 0x0(r28)
	  mr        r4, r24
	  mr        r5, r23
	  subis     r20, r3, 0x8000
	  mr        r3, r20
	  bl        -0x1F2A80
	  mr        r3, r20
	  mr        r4, r23
	  bl        0xDB0
	  sync
	  mr        r3, r20
	  mr        r4, r23
	  bl        0xE30

	.loc_0x208:
	  addi      r28, r28, 0x4
	  addi      r26, r26, 0x1

	.loc_0x210:
	  rlwinm    r0,r26,0,24,31
	  cmplwi    r0, 0xF
	  blt+      .loc_0xCC
	  lis       r3, 0x8000
	  addi      r0, r3, 0x3000
	  stw       r0, 0x31D4(r13)
	  li        r20, 0
	  b         .loc_0x230

	.loc_0x230:
	  lis       r3, 0x801F
	  addi      r23, r3, 0x6020
	  b         .loc_0x23C

	.loc_0x23C:
	  b         .loc_0x250

	.loc_0x240:
	  mr        r3, r20
	  mr        r4, r23
	  bl        0x60
	  addi      r20, r20, 0x1

	.loc_0x250:
	  rlwinm    r0,r20,0,24,31
	  cmplwi    r0, 0xF
	  blt+      .loc_0x240
	  stw       r25, 0x0(r30)
	  addi      r3, r29, 0x1A0
	  crclr     6, 0x6
	  bl        0x7C30
	  lmw       r20, 0x8(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F5F2C
 * Size:	000024
 */
void __OSDBIntegrator(void)
{
	/*
	.loc_0x0:
	  li        r5, 0x40
	  mflr      r3
	  stw       r3, 0xC(r5)
	  lwz       r3, 0x8(r5)
	  oris      r3, r3, 0x8000
	  mtlr      r3
	  li        r3, 0x30
	  mtmsr     r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F5F50
 * Size:	000004
 */
void __OSDBJump(void)
{
	/*
	.loc_0x0:
	  bla       0x60
	*/
}

/*
 * --INFO--
 * Address:	801F5F54
 * Size:	00001C
 */
void __OSSetExceptionHandler(void)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lwz       r3, 0x31D4(r13)
	  rlwinm    r0,r0,2,0,29
	  add       r5, r3, r0
	  lwz       r3, 0x0(r5)
	  stw       r4, 0x0(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F5F70
 * Size:	000014
 */
void __OSGetExceptionHandler(void)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lwz       r3, 0x31D4(r13)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F5F84
 * Size:	00009C
 */
void OSExceptionVector(void)
{
	/*
	.loc_0x0:
	  mtsprg    0, r4
	  lwz       r4, 0xC0(r0)
	  stw       r3, 0xC(r4)
	  mfsprg    r3, 0
	  stw       r3, 0x10(r4)
	  stw       r5, 0x14(r4)
	  lhz       r3, 0x1A2(r4)
	  ori       r3, r3, 0x2
	  sth       r3, 0x1A2(r4)
	  mfcr      r3
	  stw       r3, 0x80(r4)
	  mflr      r3
	  stw       r3, 0x84(r4)
	  mfctr     r3
	  stw       r3, 0x88(r4)
	  mfxer     r3
	  stw       r3, 0x8C(r4)
	  mfsrr0    r3
	  stw       r3, 0x198(r4)
	  mfsrr1    r3
	  stw       r3, 0x19C(r4)
	  mr        r5, r3
	  nop
	  mfmsr     r3
	  ori       r3, r3, 0x30
	  mtsrr1    r3
	  li        r3, 0
	  lwz       r4, 0xD4(r0)
	  rlwinm.   r5,r5,0,30,30
	  bne-      .loc_0x88
	  lis       r5, 0x801F
	  addi      r5, r5, 0x6020
	  mtsrr0    r5
	  rfi

	.loc_0x88:
	  rlwinm    r5,r3,2,22,29
	  lwz       r5, 0x3000(r5)
	  mtsrr0    r5
	  rfi
	  nop
	*/
}

/*
 * --INFO--
 * Address:	801F6020
 * Size:	000054
 */
void OSDefaultExceptionHandler(void)
{
	/*
	.loc_0x0:
	  stw       r0, 0x0(r4)
	  stw       r1, 0x4(r4)
	  stw       r2, 0x8(r4)
	  stmw      r6, 0x18(r4)
	  mfspr     r0, 0x391
	  stw       r0, 0x1A8(r4)
	  mfspr     r0, 0x392
	  stw       r0, 0x1AC(r4)
	  mfspr     r0, 0x393
	  stw       r0, 0x1B0(r4)
	  mfspr     r0, 0x394
	  stw       r0, 0x1B4(r4)
	  mfspr     r0, 0x395
	  stw       r0, 0x1B8(r4)
	  mfspr     r0, 0x396
	  stw       r0, 0x1BC(r4)
	  mfspr     r0, 0x397
	  stw       r0, 0x1C0(r4)
	  mfdsisr   r5
	  mfdar     r6
	  b         0x19E8
	*/
}

/*
 * --INFO--
 * Address:	801F6074
 * Size:	000038
 */
void __OSPSInit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x6F0
	  oris      r3, r3, 0xA000
	  bl        -0x6F0
	  bl        0xC8C
	  sync
	  li        r3, 0
	  mtspr     912, r3
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F60AC
 * Size:	000014
 */
void __OSGetDIConfig(void)
{
	/*
	.loc_0x0:
	  lis       r3, 0xCC00
	  addi      r3, r3, 0x6000
	  lwz       r0, 0x24(r3)
	  rlwinm    r3,r0,0,24,31
	  blr
	*/
}
