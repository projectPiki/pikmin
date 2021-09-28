

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void GetWirelessID(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void SetWirelessID(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80203E04
 * Size:	0000D4
 */
void DoReset(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0x33B0
  li        r3, 0x1
  lwz       r0, 0x3360(r13)
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0xBC
  cmpwi     r0, 0x4
  bge-      .loc_0xBC
  mulli     r0, r0, 0xC
  add       r3, r30, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x200B38
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r31, 0
  add       r6, r30, r0
  stwu      r31, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r31, r30, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x86A4
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0xBC
  li        r0, 0x20
  stw       r31, 0x3360(r13)
  stw       r0, 0x2A38(r13)

.loc_0xBC:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void PADEnable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void ProbeWireless(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80203ED8
 * Size:	0001DC
 */
void PADProbeCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm.   r0,r4,0,28,31
  lis       r4, 0x803D
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r31, r4, 0x33B0
  stw       r30, 0x38(r1)
  stw       r29, 0x34(r1)
  bne-      .loc_0x124
  rlwinm    r0,r3,2,0,29
  add       r3, r31, r0
  lwz       r3, 0x10(r3)
  rlwinm.   r0,r3,0,12,12
  bne-      .loc_0x98
  rlwinm.   r0,r3,0,13,13
  bne-      .loc_0x98
  lwz       r30, 0x2A38(r13)
  lis       r29, 0x8000
  lwz       r3, 0x335C(r13)
  addi      r4, r1, 0x24
  srw       r0, r29, r30
  or        r0, r3, r0
  stw       r0, 0x335C(r13)
  mr        r3, r30
  bl        -0x8800
  lwz       r0, 0x2A40(r13)
  addi      r3, r30, 0
  oris      r4, r0, 0x40
  bl        -0x899C
  lwz       r3, 0x335C(r13)
  bl        -0x8920
  lwz       r0, 0x2A38(r13)
  lwz       r3, 0x336C(r13)
  srw       r0, r29, r0
  or        r0, r3, r0
  stw       r0, 0x336C(r13)
  b         .loc_0x124

.loc_0x98:
  lwz       r30, 0x2A38(r13)
  lis       r29, 0x8000
  lwz       r3, 0x335C(r13)
  addi      r4, r1, 0x18
  srw       r5, r29, r30
  lwz       r0, 0x3364(r13)
  or        r3, r3, r5
  stw       r3, 0x335C(r13)
  mr        r3, r30
  or        r0, r0, r5
  stw       r0, 0x3364(r13)
  bl        -0x8860
  rlwinm    r0,r30,2,0,29
  add       r3, r31, r0
  lwz       r4, 0x10(r3)
  rlwinm.   r0,r4,0,6,6
  bne-      .loc_0xF4
  lhz       r0, 0x30E0(r29)
  rlwinm    r3,r30,14,0,17
  oris      r3, r3, 0x4D
  rlwinm    r0,r0,0,18,31
  or        r4, r3, r0
  b         .loc_0x114

.loc_0xF4:
  rlwinm    r3,r4,0,12,13
  subis     r0, r3, 0x4
  cmplwi    r0, 0
  bne-      .loc_0x10C
  lis       r4, 0x50
  b         .loc_0x114

.loc_0x10C:
  rlwinm    r3,r4,0,13,15
  addis     r4, r3, 0x44

.loc_0x114:
  mr        r3, r30
  bl        -0x8A40
  lwz       r3, 0x335C(r13)
  bl        -0x89C4

.loc_0x124:
  lwz       r0, 0x3360(r13)
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x1C0
  cmpwi     r0, 0x4
  bge-      .loc_0x1C0
  mulli     r0, r0, 0xC
  add       r3, r31, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x200D10
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r30, 0
  add       r6, r31, r0
  stwu      r30, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r30, r31, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x887C
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x1C0
  li        r0, 0x20
  stw       r30, 0x3360(r13)
  stw       r0, 0x2A38(r13)

.loc_0x1C0:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  mtlr      r0
  lwz       r29, 0x34(r1)
  addi      r1, r1, 0x40
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void PADDisable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802040B4
 * Size:	000194
 */
void UpdateOrigin(void)
{
/*
.loc_0x0:
  lwz       r0, 0x2A40(r13)
  lis       r4, 0x803D
  lis       r7, 0x8000
  rlwinm    r5,r0,0,21,23
  mulli     r6, r3, 0xC
  addi      r4, r4, 0x33D0
  cmpwi     r5, 0x400
  srw       r0, r7, r3
  add       r4, r4, r6
  beq-      .loc_0x118
  bge-      .loc_0x5C
  cmpwi     r5, 0x200
  beq-      .loc_0xE8
  bge-      .loc_0x50
  cmpwi     r5, 0x100
  beq-      .loc_0xB4
  bge-      .loc_0x118
  cmpwi     r5, 0
  beq-      .loc_0x80
  b         .loc_0x118

.loc_0x50:
  cmpwi     r5, 0x300
  beq-      .loc_0x118
  b         .loc_0x118

.loc_0x5C:
  cmpwi     r5, 0x600
  beq-      .loc_0x80
  bge-      .loc_0x74
  cmpwi     r5, 0x500
  beq-      .loc_0x80
  b         .loc_0x118

.loc_0x74:
  cmpwi     r5, 0x700
  beq-      .loc_0x80
  b         .loc_0x118

.loc_0x80:
  lbz       r5, 0x6(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x6(r4)
  lbz       r5, 0x7(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x7(r4)
  lbz       r5, 0x8(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x8(r4)
  lbz       r5, 0x9(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x9(r4)
  b         .loc_0x118

.loc_0xB4:
  lbz       r5, 0x4(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x4(r4)
  lbz       r5, 0x5(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x5(r4)
  lbz       r5, 0x8(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x8(r4)
  lbz       r5, 0x9(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x9(r4)
  b         .loc_0x118

.loc_0xE8:
  lbz       r5, 0x4(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x4(r4)
  lbz       r5, 0x5(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x5(r4)
  lbz       r5, 0x6(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x6(r4)
  lbz       r5, 0x7(r4)
  rlwinm    r5,r5,0,0,27
  stb       r5, 0x7(r4)

.loc_0x118:
  lbz       r5, 0x2(r4)
  subi      r5, r5, 0x80
  stb       r5, 0x2(r4)
  lbz       r5, 0x3(r4)
  subi      r5, r5, 0x80
  stb       r5, 0x3(r4)
  lbz       r5, 0x4(r4)
  subi      r5, r5, 0x80
  stb       r5, 0x4(r4)
  lbz       r5, 0x5(r4)
  subi      r5, r5, 0x80
  stb       r5, 0x5(r4)
  lwz       r5, 0x2A3C(r13)
  and.      r0, r5, r0
  beqlr-    
  lbz       r0, 0x2(r4)
  extsb     r0, r0
  cmpwi     r0, 0x40
  blelr-    
  lis       r5, 0x803D
  rlwinm    r3,r3,2,0,29
  addi      r0, r5, 0x33C0
  add       r3, r0, r3
  lwz       r0, 0x0(r3)
  rlwinm    r3,r0,0,0,15
  subis     r0, r3, 0x900
  cmplwi    r0, 0
  bnelr-    
  li        r0, 0
  stb       r0, 0x2(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	80204248
 * Size:	00011C
 */
void PADOriginCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  rlwinm.   r0,r4,0,28,31
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  addi      r30, r3, 0x33B0
  bne-      .loc_0x68
  lwz       r3, 0x2A38(r13)
  bl        -0x1BC
  lwz       r31, 0x2A38(r13)
  lis       r0, 0x8000
  lwz       r3, 0x335C(r13)
  addi      r4, r1, 0x1C
  srw       r0, r0, r31
  or        r0, r3, r0
  stw       r0, 0x335C(r13)
  mr        r3, r31
  bl        -0x8B58
  lwz       r0, 0x2A40(r13)
  addi      r3, r31, 0
  oris      r4, r0, 0x40
  bl        -0x8CF4
  lwz       r3, 0x335C(r13)
  bl        -0x8C78

.loc_0x68:
  lwz       r0, 0x3360(r13)
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x104
  cmpwi     r0, 0x4
  bge-      .loc_0x104
  mulli     r0, r0, 0xC
  add       r3, r30, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x200FC4
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r31, 0
  add       r6, r30, r0
  stwu      r31, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r31, r30, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x8B30
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x104
  li        r0, 0x20
  stw       r31, 0x3360(r13)
  stw       r0, 0x2A38(r13)

.loc_0x104:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  mtlr      r0
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	80204364
 * Size:	00003C
 */
void PADOriginUpdateCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  lis       r0, 0x8000
  srw       r0, r0, r3
  stwu      r1, -0x8(r1)
  lwz       r5, 0x335C(r13)
  and.      r0, r5, r0
  beq-      .loc_0x2C
  rlwinm.   r0,r4,0,28,31
  bne-      .loc_0x2C
  bl        -0x2D8

.loc_0x2C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	802043A0
 * Size:	000254
 */
void PADFixCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  rlwinm.   r0,r4,0,28,31
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r3, 0x33B0
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  bne-      .loc_0x19C
  lwz       r30, 0x2A38(r13)
  rlwinm    r0,r30,2,0,29
  add       r3, r31, r0
  lwz       r29, 0x10(r3)
  bl        -0x9A34
  rlwinm    r0,r30,1,0,30
  add       r3, r3, r0
  lhz       r30, 0x1C(r3)
  li        r3, 0
  bl        -0x96C0
  rlwinm.   r0,r29,0,11,11
  rlwinm    r4,r30,8,0,23
  beq-      .loc_0x74
  lis       r3, 0xD0
  subi      r0, r3, 0x100
  and       r3, r4, r0
  and       r0, r29, r0
  cmplw     r3, r0
  beq-      .loc_0x114

.loc_0x74:
  lwz       r0, 0x3360(r13)
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x238
  cmpwi     r0, 0x4
  bge-      .loc_0x238
  mulli     r0, r0, 0xC
  add       r3, r31, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x201128
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r30, 0
  add       r6, r31, r0
  stwu      r30, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r30, r31, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x8C94
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x238
  li        r0, 0x20
  stw       r30, 0x3360(r13)
  stw       r0, 0x2A38(r13)
  b         .loc_0x238

.loc_0x114:
  rlwinm.   r0,r29,0,1,1
  beq-      .loc_0x160
  rlwinm.   r0,r29,0,12,12
  bne-      .loc_0x160
  rlwinm.   r0,r29,0,13,13
  bne-      .loc_0x160
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x4248
  mulli     r0, r3, 0xC
  add       r6, r31, r0
  addi      r4, r13, 0x2A4C
  li        r5, 0x1
  li        r7, 0xA
  li        r10, 0
  li        r9, 0
  addi      r6, r6, 0x20
  bl        -0x8D0C
  b         .loc_0x238

.loc_0x160:
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x3ED8
  mulli     r0, r3, 0xC
  rlwinm    r4,r3,2,0,29
  add       r4, r31, r4
  add       r6, r31, r0
  li        r5, 0x3
  li        r7, 0x8
  li        r10, 0
  li        r9, 0
  addi      r4, r4, 0x50
  addi      r6, r6, 0x20
  bl        -0x8D48
  b         .loc_0x238

.loc_0x19C:
  lwz       r0, 0x3360(r13)
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x238
  cmpwi     r0, 0x4
  bge-      .loc_0x238
  mulli     r0, r0, 0xC
  add       r3, r31, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x201250
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r30, 0
  add       r6, r31, r0
  stwu      r30, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r30, r31, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x8DBC
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x238
  li        r0, 0x20
  stw       r30, 0x3360(r13)
  stw       r0, 0x2A38(r13)

.loc_0x238:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  mtlr      r0
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  blr
*/
}

/*
 * --INFO--
 * Address:	802045F4
 * Size:	000730
 */
void PADResetCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  rlwinm.   r5,r4,0,28,31
  stw       r0, 0x4(r1)
  lis       r3, 0x803D
  stwu      r1, -0x60(r1)
  stmw      r26, 0x48(r1)
  addi      r31, r3, 0x33B0
  beq-      .loc_0x34
  lwz       r0, 0x2A38(r13)
  li        r4, 0
  rlwinm    r0,r0,2,0,29
  add       r3, r31, r0
  stw       r4, 0x10(r3)

.loc_0x34:
  lwz       r29, 0x2A38(r13)
  lis       r30, 0x8000
  cmplwi    r5, 0
  rlwinm    r0,r29,2,0,29
  add       r3, r31, r0
  lwz       r28, 0x10(r3)
  srw       r7, r30, r29
  not       r6, r7
  stwx      r28, r31, r0
  lwz       r5, 0x3368(r13)
  lwz       r3, 0x3380(r13)
  and       r4, r5, r6
  and       r0, r3, r6
  stw       r4, 0x3368(r13)
  and       r27, r5, r7
  stw       r0, 0x3380(r13)
  and       r26, r3, r7
  bne-      .loc_0x8C
  rlwinm    r3,r28,0,3,4
  subis     r0, r3, 0x800
  cmplwi    r0, 0
  beq-      .loc_0x160

.loc_0x8C:
  bl        -0x9CDC
  rlwinm    r0,r29,1,0,30
  add       r3, r3, r0
  lhzu      r0, 0x1C(r3)
  cmplwi    r0, 0
  beq-      .loc_0xB8
  li        r0, 0
  sth       r0, 0x0(r3)
  li        r3, 0x1
  bl        -0x9978
  b         .loc_0xC0

.loc_0xB8:
  li        r3, 0
  bl        -0x9984

.loc_0xC0:
  lwz       r0, 0x3360(r13)
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x71C
  cmpwi     r0, 0x4
  bge-      .loc_0x71C
  mulli     r0, r0, 0xC
  add       r3, r31, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x2013C8
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r27, 0
  add       r6, r31, r0
  stwu      r27, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r27, r31, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x8F34
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x71C
  li        r0, 0x20
  stw       r27, 0x3360(r13)
  stw       r0, 0x2A38(r13)
  b         .loc_0x71C

.loc_0x160:
  lwz       r0, 0x2A44(r13)
  cmplwi    r0, 0x2
  bge-      .loc_0x238
  lwz       r0, 0x335C(r13)
  addi      r3, r29, 0
  addi      r4, r1, 0x38
  or        r0, r0, r7
  stw       r0, 0x335C(r13)
  bl        -0x9038
  lwz       r0, 0x2A40(r13)
  addi      r3, r29, 0
  oris      r4, r0, 0x40
  bl        -0x91D4
  lwz       r3, 0x335C(r13)
  bl        -0x9158
  lwz       r0, 0x3360(r13)
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x71C
  cmpwi     r0, 0x4
  bge-      .loc_0x71C
  mulli     r0, r0, 0xC
  add       r3, r31, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x2014A4
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r27, 0
  add       r6, r31, r0
  stwu      r27, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r27, r31, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x9010
  lwz       r0, 0x2A38(r13)
  cmpwi     r3, 0
  lwz       r3, 0x3360(r13)
  srw       r0, r30, r0
  andc      r0, r3, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x71C
  li        r0, 0x20
  stw       r27, 0x3360(r13)
  stw       r0, 0x2A38(r13)
  b         .loc_0x71C

.loc_0x238:
  rlwinm.   r0,r28,0,0,0
  beq-      .loc_0x248
  rlwinm.   r0,r28,0,5,5
  beq-      .loc_0x394

.loc_0x248:
  bl        -0x9E98
  rlwinm    r0,r29,1,0,30
  add       r3, r3, r0
  lhzu      r0, 0x1C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x274
  li        r0, 0
  sth       r0, 0x0(r3)
  li        r3, 0x1
  bl        -0x9B34
  b         .loc_0x27C

.loc_0x274:
  li        r3, 0
  bl        -0x9B40

.loc_0x27C:
  rlwinm.   r0,r28,0,7,7
  bne-      .loc_0x324
  lwz       r0, 0x3360(r13)
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x71C
  cmpwi     r0, 0x4
  bge-      .loc_0x71C
  mulli     r0, r0, 0xC
  add       r3, r31, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x20158C
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r27, 0
  add       r6, r31, r0
  stwu      r27, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r27, r31, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x90F8
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x71C
  li        r0, 0x20
  stw       r27, 0x3360(r13)
  stw       r0, 0x2A38(r13)
  b         .loc_0x71C

.loc_0x324:
  cmplwi    r27, 0
  beq-      .loc_0x360
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x4248
  mulli     r0, r3, 0xC
  add       r6, r31, r0
  addi      r4, r13, 0x2A50
  li        r5, 0x3
  li        r7, 0xA
  li        r10, 0
  li        r9, 0
  addi      r6, r6, 0x20
  bl        -0x9160
  b         .loc_0x71C

.loc_0x360:
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x4248
  mulli     r0, r3, 0xC
  add       r6, r31, r0
  addi      r4, r13, 0x2A4C
  li        r5, 0x1
  li        r7, 0xA
  li        r10, 0
  li        r9, 0
  addi      r6, r6, 0x20
  bl        -0x9194
  b         .loc_0x71C

.loc_0x394:
  bl        -0x9FE4
  rlwinm    r0,r29,1,0,30
  add       r3, r3, r0
  lhz       r27, 0x1C(r3)
  li        r3, 0
  bl        -0x9C70
  cmpwi     r26, 0
  rlwinm    r29,r27,8,0,23
  beq-      .loc_0x408
  rlwinm.   r0,r29,0,11,11
  beq-      .loc_0x408
  lis       r4, 0xD0
  lwz       r3, 0x2A38(r13)
  subi      r0, r4, 0x100
  and       r0, r29, r0
  rlwinm    r6,r3,2,0,29
  add       r4, r31, r6
  oris      r0, r0, 0x4E10
  lis       r5, 0x8020
  stwu      r0, 0x60(r4)
  add       r6, r31, r6
  addi      r8, r5, 0x43A0
  li        r5, 0x3
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  addi      r6, r6, 0x10
  bl        -0x9208
  b         .loc_0x71C

.loc_0x408:
  rlwinm.   r0,r28,0,11,11
  beq-      .loc_0x530
  lis       r3, 0xD0
  subi      r3, r3, 0x100
  and       r0, r29, r3
  and       r3, r28, r3
  cmplw     r0, r3
  beq-      .loc_0x4A8
  rlwinm.   r0,r29,0,11,11
  bne-      .loc_0x46C
  oris      r29, r3, 0x10
  lwz       r27, 0x2A38(r13)
  bl        -0xA088
  rlwinm    r0,r27,1,0,30
  add       r4, r3, r0
  lhzu      r0, 0x1C(r4)
  rlwinm    r3,r29,24,16,31
  cmplw     r0, r3
  beq-      .loc_0x464
  sth       r3, 0x0(r4)
  li        r3, 0x1
  bl        -0x9D24
  b         .loc_0x46C

.loc_0x464:
  li        r3, 0
  bl        -0x9D30

.loc_0x46C:
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  oris      r0, r29, 0x4E00
  rlwinm    r5,r3,2,0,29
  addi      r8, r4, 0x43A0
  add       r4, r31, r5
  stwu      r0, 0x60(r4)
  add       r6, r31, r5
  li        r5, 0x3
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  addi      r6, r6, 0x10
  bl        -0x92A8
  b         .loc_0x71C

.loc_0x4A8:
  rlwinm.   r0,r28,0,1,1
  beq-      .loc_0x4F4
  rlwinm.   r0,r28,0,12,12
  bne-      .loc_0x4F4
  rlwinm.   r0,r28,0,13,13
  bne-      .loc_0x4F4
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x4248
  mulli     r0, r3, 0xC
  add       r6, r31, r0
  addi      r4, r13, 0x2A4C
  li        r5, 0x1
  li        r7, 0xA
  li        r10, 0
  li        r9, 0
  addi      r6, r6, 0x20
  bl        -0x92F4
  b         .loc_0x71C

.loc_0x4F4:
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x3ED8
  mulli     r0, r3, 0xC
  rlwinm    r4,r3,2,0,29
  add       r4, r31, r4
  add       r6, r31, r0
  li        r5, 0x3
  li        r7, 0x8
  li        r10, 0
  li        r9, 0
  addi      r4, r4, 0x50
  addi      r6, r6, 0x20
  bl        -0x9330
  b         .loc_0x71C

.loc_0x530:
  rlwinm.   r0,r28,0,1,1
  beq-      .loc_0x5BC
  lis       r3, 0xD0
  lwz       r27, 0x2A38(r13)
  subi      r0, r3, 0x100
  and       r26, r28, r0
  oris      r26, r26, 0x10
  bl        -0xA19C
  rlwinm    r0,r27,1,0,30
  add       r4, r3, r0
  lhzu      r0, 0x1C(r4)
  rlwinm    r3,r26,24,16,31
  cmplw     r0, r3
  beq-      .loc_0x578
  sth       r3, 0x0(r4)
  li        r3, 0x1
  bl        -0x9E38
  b         .loc_0x580

.loc_0x578:
  li        r3, 0
  bl        -0x9E44

.loc_0x580:
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  oris      r0, r26, 0x4E00
  rlwinm    r5,r3,2,0,29
  addi      r8, r4, 0x43A0
  add       r4, r31, r5
  stwu      r0, 0x60(r4)
  add       r6, r31, r5
  li        r5, 0x3
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  addi      r6, r6, 0x10
  bl        -0x93BC
  b         .loc_0x71C

.loc_0x5BC:
  lwz       r27, 0x2A38(r13)
  bl        -0xA210
  rlwinm    r0,r27,1,0,30
  add       r3, r3, r0
  lhzu      r0, 0x1C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x5EC
  li        r0, 0
  sth       r0, 0x0(r3)
  li        r3, 0x1
  bl        -0x9EAC
  b         .loc_0x5F4

.loc_0x5EC:
  li        r3, 0
  bl        -0x9EB8

.loc_0x5F4:
  lwz       r29, 0x2A38(r13)
  lis       r27, 0x8000
  lwz       r3, 0x335C(r13)
  addi      r4, r1, 0x1C
  srw       r5, r27, r29
  lwz       r0, 0x3364(r13)
  or        r3, r3, r5
  stw       r3, 0x335C(r13)
  mr        r3, r29
  or        r0, r0, r5
  stw       r0, 0x3364(r13)
  bl        -0x94D8
  rlwinm    r0,r29,2,0,29
  add       r3, r31, r0
  lwz       r4, 0x10(r3)
  rlwinm.   r0,r4,0,6,6
  bne-      .loc_0x650
  lhz       r0, 0x30E0(r27)
  rlwinm    r3,r29,14,0,17
  oris      r3, r3, 0x4D
  rlwinm    r0,r0,0,18,31
  or        r4, r3, r0
  b         .loc_0x670

.loc_0x650:
  rlwinm    r3,r4,0,12,13
  subis     r0, r3, 0x4
  cmplwi    r0, 0
  bne-      .loc_0x668
  lis       r4, 0x50
  b         .loc_0x670

.loc_0x668:
  rlwinm    r3,r4,0,13,15
  addis     r4, r3, 0x44

.loc_0x670:
  mr        r3, r29
  bl        -0x96B8
  lwz       r3, 0x335C(r13)
  bl        -0x963C
  lwz       r0, 0x3360(r13)
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x71C
  cmpwi     r0, 0x4
  bge-      .loc_0x71C
  mulli     r0, r0, 0xC
  add       r3, r31, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x201988
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r27, 0
  add       r6, r31, r0
  stwu      r27, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r27, r31, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x94F4
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x71C
  li        r0, 0x20
  stw       r27, 0x3360(r13)
  stw       r0, 0x2A38(r13)

.loc_0x71C:
  lmw       r26, 0x48(r1)
  lwz       r0, 0x64(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80204D24
 * Size:	00016C
 */
void PADReset(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0x33B0
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  li        r29, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  bl        -0xBDD4
  lwz       r0, 0x3364(r13)
  mr        r30, r3
  lwz       r6, 0x336C(r13)
  lwz       r4, 0x3370(r13)
  or        r3, r0, r6
  lwz       r0, 0x2A44(r13)
  or        r3, r4, r3
  lwz       r4, 0x3360(r13)
  andc      r28, r28, r3
  lwz       r3, 0x335C(r13)
  or        r5, r4, r28
  not       r7, r28
  stw       r5, 0x3360(r13)
  and       r4, r3, r7
  and       r3, r6, r7
  stw       r4, 0x335C(r13)
  cmplwi    r0, 0x4
  stw       r3, 0x336C(r13)
  bne-      .loc_0x88
  lwz       r0, 0x3368(r13)
  or        r0, r0, r28
  stw       r0, 0x3368(r13)

.loc_0x88:
  lwz       r3, 0x3360(r13)
  bl        -0x96E0
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0x20
  bne-      .loc_0x140
  lwz       r0, 0x3360(r13)
  li        r3, 0x1
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x13C
  cmpwi     r0, 0x4
  bge-      .loc_0x13C
  mulli     r0, r0, 0xC
  add       r3, r31, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x201AD8
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r28, 0
  add       r6, r31, r0
  stwu      r28, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r28, r31, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x9644
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x13C
  li        r0, 0x20
  stw       r28, 0x3360(r13)
  stw       r0, 0x2A38(r13)

.loc_0x13C:
  mr        r29, r3

.loc_0x140:
  mr        r3, r30
  bl        -0xBEC4
  lwz       r0, 0x2C(r1)
  mr        r3, r29
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	80204E90
 * Size:	000154
 */
void PADRecalibrate(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0x33B0
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  li        r29, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  bl        -0xBF40
  lwz       r4, 0x3364(r13)
  mr        r30, r3
  lwz       r0, 0x336C(r13)
  lwz       r3, 0x3370(r13)
  or        r0, r4, r0
  lwz       r4, 0x3360(r13)
  or        r0, r3, r0
  lwz       r3, 0x335C(r13)
  andc      r28, r28, r0
  lwz       r0, 0x3368(r13)
  or        r4, r4, r28
  andc      r3, r3, r28
  stw       r4, 0x3360(r13)
  or        r0, r0, r28
  stw       r3, 0x335C(r13)
  lwz       r3, 0x3360(r13)
  stw       r0, 0x3368(r13)
  bl        -0x9834
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0x20
  bne-      .loc_0x128
  lwz       r0, 0x3360(r13)
  li        r3, 0x1
  cntlzw    r0, r0
  stw       r0, 0x2A38(r13)
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0
  blt-      .loc_0x124
  cmpwi     r0, 0x4
  bge-      .loc_0x124
  mulli     r0, r0, 0xC
  add       r3, r31, r0
  li        r4, 0
  li        r5, 0xC
  addi      r3, r3, 0x20
  bl        -0x201C2C
  lwz       r3, 0x2A38(r13)
  lis       r4, 0x8020
  addi      r8, r4, 0x45F4
  rlwinm    r0,r3,2,0,29
  li        r29, 0
  add       r6, r31, r0
  stwu      r29, 0x10(r6)
  addi      r4, r13, 0x3374
  stwx      r29, r31, r0
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x9798
  lwz       r0, 0x2A38(r13)
  lis       r4, 0x8000
  lwz       r5, 0x3360(r13)
  cmpwi     r3, 0
  srw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3360(r13)
  bne-      .loc_0x124
  li        r0, 0x20
  stw       r29, 0x3360(r13)
  stw       r0, 0x2A38(r13)

.loc_0x124:
  mr        r29, r3

.loc_0x128:
  mr        r3, r30
  bl        -0xC018
  lwz       r0, 0x2C(r1)
  mr        r3, r29
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	80204FE4
 * Size:	0001C4
 */
void PADInit(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r25, 0x1C(r1)
  addi      r31, r3, 0x33B0
  lwz       r0, 0x3358(r13)
  cmpwi     r0, 0
  bne-      .loc_0x124
  lwz       r3, 0x337C(r13)
  cmplwi    r3, 0
  beq-      .loc_0x34
  bl        0x794

.loc_0x34:
  lwz       r3, 0x3380(r13)
  addis     r0, r3, 0x1
  cmplwi    r0, 0xFFFF
  bne-      .loc_0xC4
  bl        -0x7C88
  addi      r25, r4, 0
  addi      r26, r3, 0
  li        r5, 0x10
  bl        0x102E0
  lis       r5, 0x1
  subi      r27, r5, 0x1
  li        r28, 0
  and       r6, r4, r27
  and       r4, r25, r27
  and       r5, r3, r28
  and       r0, r26, r28
  addc      r29, r4, r6
  addi      r3, r26, 0
  addi      r4, r25, 0
  adde      r30, r0, r5
  li        r5, 0x20
  bl        0x102AC
  and       r4, r4, r27
  and       r0, r3, r28
  addc      r29, r4, r29
  addi      r3, r26, 0
  addi      r4, r25, 0
  adde      r30, r0, r30
  li        r5, 0x30
  bl        0x1028C
  and       r0, r4, r27
  addc      r4, r0, r29
  li        r0, 0x3FFF
  and       r0, r4, r0
  lis       r3, 0x8000
  sth       r0, 0x30E0(r3)

.loc_0xC4:
  lis       r5, 0x8000
  lhz       r4, 0x30E0(r5)
  li        r0, 0x1
  li        r3, 0
  rlwinm    r4,r4,8,10,23
  oris      r4, r4, 0x4D00
  stw       r4, 0x50(r31)
  lhz       r4, 0x30E0(r5)
  rlwinm    r4,r4,8,10,23
  oris      r4, r4, 0x4D40
  stw       r4, 0x54(r31)
  lhz       r4, 0x30E0(r5)
  rlwinm    r4,r4,8,10,23
  oris      r4, r4, 0x4D80
  stw       r4, 0x58(r31)
  lhz       r4, 0x30E0(r5)
  rlwinm    r4,r4,8,10,23
  oris      r4, r4, 0x4DC0
  stw       r4, 0x5C(r31)
  stw       r0, 0x3358(r13)
  bl        0x544
  lis       r3, 0x802F
  subi      r3, r3, 0x74B8
  bl        -0xB044

.loc_0x124:
  lis       r29, 0xF000
  li        r27, 0
  bl        -0xC194
  lwz       r0, 0x3364(r13)
  mr        r28, r3
  lwz       r6, 0x336C(r13)
  lwz       r4, 0x3370(r13)
  or        r3, r0, r6
  lwz       r0, 0x2A44(r13)
  or        r3, r4, r3
  lwz       r4, 0x3360(r13)
  andc      r29, r29, r3
  lwz       r3, 0x335C(r13)
  or        r5, r4, r29
  not       r7, r29
  stw       r5, 0x3360(r13)
  and       r4, r3, r7
  and       r3, r6, r7
  stw       r4, 0x335C(r13)
  cmplwi    r0, 0x4
  stw       r3, 0x336C(r13)
  bne-      .loc_0x188
  lwz       r0, 0x3368(r13)
  or        r0, r0, r29
  stw       r0, 0x3368(r13)

.loc_0x188:
  lwz       r3, 0x3360(r13)
  bl        -0x9AA0
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0x20
  bne-      .loc_0x1A4
  bl        -0x137C
  mr        r27, r3

.loc_0x1A4:
  mr        r3, r28
  bl        -0xC1E8
  mr        r3, r27
  lmw       r25, 0x1C(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	802051A8
 * Size:	00015C
 */
void PADReceiveCheckCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x803D
  stw       r0, 0x4(r1)
  lis       r6, 0x8000
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  mr        r30, r3
  srw       r31, r6, r30
  stw       r29, 0x1C(r1)
  rlwinm    r8,r30,2,0,29
  addi      r6, r7, 0x33C0
  lwz       r0, 0x335C(r13)
  add       r6, r6, r8
  lwz       r5, 0x336C(r13)
  not       r9, r31
  lwz       r3, 0x3370(r13)
  lwz       r6, 0x0(r6)
  and       r5, r5, r9
  and       r3, r3, r9
  and.      r0, r0, r31
  stw       r5, 0x336C(r13)
  stw       r3, 0x3370(r13)
  beq-      .loc_0x140
  rlwinm.   r0,r4,0,28,31
  bne-      .loc_0xC0
  rlwinm.   r0,r6,0,0,0
  beq-      .loc_0xC0
  rlwinm.   r0,r6,0,6,6
  beq-      .loc_0xC0
  rlwinm.   r0,r6,0,1,1
  beq-      .loc_0xC0
  rlwinm.   r0,r6,0,5,5
  bne-      .loc_0xC0
  mulli     r4, r30, 0xC
  lis       r3, 0x803D
  addi      r0, r3, 0x33D0
  lis       r3, 0x8020
  add       r6, r0, r4
  addi      r8, r3, 0x4364
  addi      r3, r30, 0
  addi      r4, r13, 0x2A4C
  li        r5, 0x1
  li        r7, 0xA
  li        r10, 0
  li        r9, 0
  bl        -0x9A74
  b         .loc_0x140

.loc_0xC0:
  bl        -0xC2EC
  addi      r29, r3, 0
  addi      r3, r31, 0
  bl        -0x9BA4
  lwz       r0, 0x335C(r13)
  not       r6, r31
  lwz       r4, 0x336C(r13)
  lwz       r3, 0x3370(r13)
  and       r5, r0, r6
  lwz       r0, 0x3364(r13)
  and       r4, r4, r6
  and       r3, r3, r6
  and       r0, r0, r6
  stw       r5, 0x335C(r13)
  stw       r4, 0x336C(r13)
  stw       r3, 0x3370(r13)
  stw       r0, 0x3364(r13)
  bl        -0xA908
  rlwinm    r0,r30,1,0,30
  add       r3, r3, r0
  lhzu      r0, 0x1C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x130
  li        r0, 0
  sth       r0, 0x0(r3)
  li        r3, 0x1
  bl        -0xA5A4
  b         .loc_0x138

.loc_0x130:
  li        r3, 0
  bl        -0xA5B0

.loc_0x138:
  mr        r3, r29
  bl        -0xC340

.loc_0x140:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	80205304
 * Size:	000338
 */
void PADRead(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x33D0
  lis       r6, 0x803D
  stwu      r1, -0x48(r1)
  lis       r4, 0x8020
  stmw      r21, 0x1C(r1)
  li        r23, 0
  mulli     r5, r23, 0xC
  add       r25, r0, r5
  lis       r5, 0x8020
  rlwinm    r7,r23,2,0,29
  addi      r0, r6, 0x33C0
  add       r27, r0, r7
  addi      r21, r3, 0
  addi      r31, r4, 0x4364
  addi      r30, r5, 0x51A8
  li        r22, 0
  li        r26, 0
  lis       r29, 0x8000

.loc_0x54:
  lwz       r0, 0x3360(r13)
  srw       r24, r29, r23
  subfic    r3, r23, 0x3
  and.      r0, r0, r24
  rlwinm    r28,r3,3,0,28
  bne-      .loc_0x78
  lwz       r0, 0x2A38(r13)
  cmpw      r0, r23
  bne-      .loc_0x94

.loc_0x78:
  li        r0, -0x2
  stb       r0, 0xA(r21)
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0xA
  bl        -0x202070
  b         .loc_0x304

.loc_0x94:
  lwz       r0, 0x335C(r13)
  and.      r0, r0, r24
  bne-      .loc_0xBC
  li        r0, -0x1
  stb       r0, 0xA(r21)
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0xA
  bl        -0x202098
  b         .loc_0x304

.loc_0xBC:
  bl        -0x9E20
  li        r0, 0x8
  slw       r0, r0, r28
  and.      r0, r3, r0
  beq-      .loc_0x1E8
  lwz       r0, 0x336C(r13)
  and.      r0, r0, r24
  beq-      .loc_0x14C
  li        r0, 0
  stb       r0, 0xA(r21)
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0xA
  bl        -0x2020D4
  lwz       r0, 0x3370(r13)
  and.      r0, r0, r24
  bne-      .loc_0x304
  bl        -0xC488
  addi      r28, r3, 0
  addi      r3, r23, 0
  addi      r6, r27, 0
  addi      r8, r30, 0
  addi      r4, r13, 0x3374
  li        r5, 0x1
  li        r7, 0x3
  li        r10, 0
  li        r9, 0
  bl        -0x9C40
  cmpwi     r3, 0
  beq-      .loc_0x140
  lwz       r0, 0x3370(r13)
  or        r0, r0, r24
  stw       r0, 0x3370(r13)

.loc_0x140:
  mr        r3, r28
  bl        -0xC4A4
  b         .loc_0x304

.loc_0x14C:
  bl        -0xC4D4
  addi      r28, r3, 0
  addi      r3, r24, 0
  bl        -0x9D8C
  lwz       r0, 0x335C(r13)
  not       r6, r24
  lwz       r4, 0x336C(r13)
  lwz       r3, 0x3370(r13)
  and       r5, r0, r6
  lwz       r0, 0x3364(r13)
  and       r4, r4, r6
  and       r3, r3, r6
  and       r0, r0, r6
  stw       r5, 0x335C(r13)
  stw       r4, 0x336C(r13)
  stw       r3, 0x3370(r13)
  stw       r0, 0x3364(r13)
  bl        -0xAAF0
  addi      r4, r26, 0x1C
  add       r4, r3, r4
  lhz       r0, 0x0(r4)
  cmplwi    r0, 0
  beq-      .loc_0x1BC
  li        r0, 0
  sth       r0, 0x0(r4)
  li        r3, 0x1
  bl        -0xA78C
  b         .loc_0x1C4

.loc_0x1BC:
  li        r3, 0
  bl        -0xA798

.loc_0x1C4:
  mr        r3, r28
  bl        -0xC528
  li        r0, -0x1
  stb       r0, 0xA(r21)
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0xA
  bl        -0x2021C4
  b         .loc_0x304

.loc_0x1E8:
  lwz       r0, 0x3364(r13)
  and.      r0, r0, r24
  bne-      .loc_0x204
  lwz       r0, 0x0(r27)
  rlwinm.   r0,r0,0,2,2
  bne-      .loc_0x204
  or        r22, r22, r24

.loc_0x204:
  li        r0, 0x20
  slw       r0, r0, r28
  and.      r0, r3, r0
  bne-      .loc_0x230
  li        r0, -0x3
  stb       r0, 0xA(r21)
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0xA
  bl        -0x20220C
  b         .loc_0x304

.loc_0x230:
  addi      r3, r23, 0
  addi      r4, r1, 0xC
  bl        -0x9E00
  lwz       r0, 0xC(r1)
  rlwinm.   r0,r0,0,0,0
  beq-      .loc_0x264
  li        r0, -0x3
  stb       r0, 0xA(r21)
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0xA
  bl        -0x202240
  b         .loc_0x304

.loc_0x264:
  lwz       r0, 0x3364(r13)
  and.      r0, r0, r24
  beq-      .loc_0x28C
  li        r0, -0x1
  stb       r0, 0xA(r21)
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0xA
  bl        -0x202268
  b         .loc_0x304

.loc_0x28C:
  lwz       r12, 0x2A48(r13)
  addi      r3, r23, 0
  addi      r4, r21, 0
  mtlr      r12
  addi      r5, r1, 0xC
  blrl      
  lhz       r0, 0x0(r21)
  rlwinm.   r0,r0,0,18,18
  beq-      .loc_0x2F0
  li        r0, -0x3
  stb       r0, 0xA(r21)
  addi      r3, r21, 0
  li        r4, 0
  li        r5, 0xA
  bl        -0x2022A8
  addi      r3, r23, 0
  addi      r6, r25, 0
  addi      r8, r31, 0
  addi      r4, r13, 0x2A4C
  li        r5, 0x1
  li        r7, 0xA
  li        r10, 0
  li        r9, 0
  bl        -0x9E00
  b         .loc_0x304

.loc_0x2F0:
  li        r0, 0
  stb       r0, 0xA(r21)
  lhz       r0, 0x0(r21)
  rlwinm    r0,r0,0,25,23
  sth       r0, 0x0(r21)

.loc_0x304:
  addi      r23, r23, 0x1
  cmpwi     r23, 0x4
  addi      r27, r27, 0x4
  addi      r26, r26, 0x2
  addi      r25, r25, 0xC
  addi      r21, r21, 0xC
  blt+      .loc_0x54
  mr        r3, r22
  lmw       r21, 0x1C(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020563C
 * Size:	0000B0
 */
void PADSetSamplingRate(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  cmplwi    r29, 0xB
  lis       r3, 0x802F
  subi      r31, r3, 0x74B8
  ble-      .loc_0x30
  li        r29, 0xB

.loc_0x30:
  bl        -0x1AE8
  cmpwi     r3, 0x1
  beq-      .loc_0x5C
  bge-      .loc_0x4C
  cmpwi     r3, 0
  bge-      .loc_0x54
  b         .loc_0x64

.loc_0x4C:
  cmpwi     r3, 0x3
  bge-      .loc_0x64

.loc_0x54:
  addi      r30, r31, 0x10
  b         .loc_0x78

.loc_0x5C:
  addi      r30, r31, 0x28
  b         .loc_0x78

.loc_0x64:
  addi      r5, r31, 0x40
  crclr     6, 0x6
  addi      r3, r13, 0x2A54
  li        r4, 0x510
  bl        -0xDDA0

.loc_0x78:
  rlwinm    r0,r29,1,0,30
  add       r4, r30, r0
  lbzx      r3, r30, r0
  lbz       r4, 0x1(r4)
  bl        -0xA0F0
  lwz       r3, 0x335C(r13)
  bl        -0xA098
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void PADControlAllMotors(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802056EC
 * Size:	0000BC
 */
void PADControlMotor(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r4, 0
  bl        -0xC790
  lis       r4, 0x8000
  lwz       r0, 0x335C(r13)
  srw       r4, r4, r31
  and.      r0, r0, r4
  addi      r30, r3, 0
  beq-      .loc_0x98
  lwz       r0, 0x3364(r13)
  and.      r0, r0, r4
  bne-      .loc_0x98
  lis       r3, 0x803D
  rlwinm    r4,r31,2,0,29
  addi      r0, r3, 0x33C0
  add       r3, r0, r4
  lwz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,2,2
  bne-      .loc_0x98
  lwz       r0, 0x2A44(r13)
  cmplwi    r0, 0x2
  bge-      .loc_0x7C
  cmplwi    r29, 0x2
  bne-      .loc_0x7C
  li        r29, 0

.loc_0x7C:
  lwz       r4, 0x2A40(r13)
  rlwinm    r0,r29,0,30,31
  addi      r3, r31, 0
  oris      r4, r4, 0x40
  or        r4, r4, r0
  bl        -0xA1CC
  bl        -0xA1BC

.loc_0x98:
  mr        r3, r30
  bl        -0xC7E4
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	802057A8
 * Size:	000060
 */
void PADSetSpec(void)
{
/*
.loc_0x0:
  li        r0, 0
  cmpwi     r3, 0x1
  stw       r0, 0x337C(r13)
  beq-      .loc_0x3C
  bge-      .loc_0x20
  cmpwi     r3, 0
  bge-      .loc_0x2C
  b         .loc_0x58

.loc_0x20:
  cmpwi     r3, 0x6
  bge-      .loc_0x58
  b         .loc_0x4C

.loc_0x2C:
  lis       r4, 0x8020
  addi      r0, r4, 0x5808
  stw       r0, 0x2A48(r13)
  b         .loc_0x58

.loc_0x3C:
  lis       r4, 0x8020
  addi      r0, r4, 0x597C
  stw       r0, 0x2A48(r13)
  b         .loc_0x58

.loc_0x4C:
  lis       r4, 0x8020
  addi      r0, r4, 0x5AF0
  stw       r0, 0x2A48(r13)

.loc_0x58:
  stw       r3, 0x2A44(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PADGetSpec(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80205808
 * Size:	000174
 */
void SPEC0_MakeStatus(void)
{
/*
.loc_0x0:
  li        r3, 0
  sth       r3, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,28,28
  beq-      .loc_0x18
  li        r3, 0x100

.loc_0x18:
  lhz       r0, 0x0(r4)
  or        r0, r0, r3
  sth       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,26,26
  beq-      .loc_0x38
  li        r3, 0x200
  b         .loc_0x3C

.loc_0x38:
  li        r3, 0

.loc_0x3C:
  lhz       r0, 0x0(r4)
  or        r0, r0, r3
  sth       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,23,23
  beq-      .loc_0x5C
  li        r3, 0x400
  b         .loc_0x60

.loc_0x5C:
  li        r3, 0

.loc_0x60:
  lhz       r0, 0x0(r4)
  or        r0, r0, r3
  sth       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,31,31
  beq-      .loc_0x80
  li        r3, 0x800
  b         .loc_0x84

.loc_0x80:
  li        r3, 0

.loc_0x84:
  lhz       r0, 0x0(r4)
  or        r0, r0, r3
  sth       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,27,27
  beq-      .loc_0xA4
  li        r6, 0x1000
  b         .loc_0xA8

.loc_0xA4:
  li        r6, 0

.loc_0xA8:
  lhz       r3, 0x0(r4)
  li        r0, 0
  or        r3, r3, r6
  sth       r3, 0x0(r4)
  lwz       r3, 0x4(r5)
  rlwinm    r3,r3,16,16,31
  extsb     r3, r3
  stb       r3, 0x2(r4)
  lwz       r3, 0x4(r5)
  rlwinm    r3,r3,8,24,31
  extsb     r3, r3
  stb       r3, 0x3(r4)
  lwz       r3, 0x4(r5)
  extsb     r3, r3
  stb       r3, 0x4(r4)
  lwz       r3, 0x4(r5)
  rlwinm    r3,r3,24,8,31
  extsb     r3, r3
  stb       r3, 0x5(r4)
  lwz       r3, 0x0(r5)
  rlwinm    r3,r3,24,24,31
  stb       r3, 0x6(r4)
  lwz       r3, 0x0(r5)
  stb       r3, 0x7(r4)
  stb       r0, 0x8(r4)
  stb       r0, 0x9(r4)
  lbz       r0, 0x6(r4)
  cmplwi    r0, 0xAA
  blt-      .loc_0x128
  lhz       r0, 0x0(r4)
  ori       r0, r0, 0x40
  sth       r0, 0x0(r4)

.loc_0x128:
  lbz       r0, 0x7(r4)
  cmplwi    r0, 0xAA
  blt-      .loc_0x140
  lhz       r0, 0x0(r4)
  ori       r0, r0, 0x20
  sth       r0, 0x0(r4)

.loc_0x140:
  lbz       r3, 0x2(r4)
  subi      r0, r3, 0x80
  stb       r0, 0x2(r4)
  lbz       r3, 0x3(r4)
  subi      r0, r3, 0x80
  stb       r0, 0x3(r4)
  lbz       r3, 0x4(r4)
  subi      r0, r3, 0x80
  stb       r0, 0x4(r4)
  lbz       r3, 0x5(r4)
  subi      r0, r3, 0x80
  stb       r0, 0x5(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	8020597C
 * Size:	000174
 */
void SPEC1_MakeStatus(void)
{
/*
.loc_0x0:
  li        r3, 0
  sth       r3, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,24,24
  beq-      .loc_0x18
  li        r3, 0x100

.loc_0x18:
  lhz       r0, 0x0(r4)
  or        r0, r0, r3
  sth       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,23,23
  beq-      .loc_0x38
  li        r3, 0x200
  b         .loc_0x3C

.loc_0x38:
  li        r3, 0

.loc_0x3C:
  lhz       r0, 0x0(r4)
  or        r0, r0, r3
  sth       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,26,26
  beq-      .loc_0x5C
  li        r3, 0x400
  b         .loc_0x60

.loc_0x5C:
  li        r3, 0

.loc_0x60:
  lhz       r0, 0x0(r4)
  or        r0, r0, r3
  sth       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,27,27
  beq-      .loc_0x80
  li        r3, 0x800
  b         .loc_0x84

.loc_0x80:
  li        r3, 0

.loc_0x84:
  lhz       r0, 0x0(r4)
  or        r0, r0, r3
  sth       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm.   r0,r0,16,22,22
  beq-      .loc_0xA4
  li        r6, 0x1000
  b         .loc_0xA8

.loc_0xA4:
  li        r6, 0

.loc_0xA8:
  lhz       r3, 0x0(r4)
  li        r0, 0
  or        r3, r3, r6
  sth       r3, 0x0(r4)
  lwz       r3, 0x4(r5)
  rlwinm    r3,r3,16,16,31
  extsb     r3, r3
  stb       r3, 0x2(r4)
  lwz       r3, 0x4(r5)
  rlwinm    r3,r3,8,24,31
  extsb     r3, r3
  stb       r3, 0x3(r4)
  lwz       r3, 0x4(r5)
  extsb     r3, r3
  stb       r3, 0x4(r4)
  lwz       r3, 0x4(r5)
  rlwinm    r3,r3,24,8,31
  extsb     r3, r3
  stb       r3, 0x5(r4)
  lwz       r3, 0x0(r5)
  rlwinm    r3,r3,24,24,31
  stb       r3, 0x6(r4)
  lwz       r3, 0x0(r5)
  stb       r3, 0x7(r4)
  stb       r0, 0x8(r4)
  stb       r0, 0x9(r4)
  lbz       r0, 0x6(r4)
  cmplwi    r0, 0xAA
  blt-      .loc_0x128
  lhz       r0, 0x0(r4)
  ori       r0, r0, 0x40
  sth       r0, 0x0(r4)

.loc_0x128:
  lbz       r0, 0x7(r4)
  cmplwi    r0, 0xAA
  blt-      .loc_0x140
  lhz       r0, 0x0(r4)
  ori       r0, r0, 0x20
  sth       r0, 0x0(r4)

.loc_0x140:
  lbz       r3, 0x2(r4)
  subi      r0, r3, 0x80
  stb       r0, 0x2(r4)
  lbz       r3, 0x3(r4)
  subi      r0, r3, 0x80
  stb       r0, 0x3(r4)
  lbz       r3, 0x4(r4)
  subi      r0, r3, 0x80
  stb       r0, 0x4(r4)
  lbz       r3, 0x5(r4)
  subi      r0, r3, 0x80
  stb       r0, 0x5(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void ClampS8(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void ClampU8(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80205AF0
 * Size:	0003F8
 */
void SPEC2_MakeStatus(void)
{
/*
.loc_0x0:
  lwz       r0, 0x0(r5)
  rlwinm    r0,r0,16,18,31
  sth       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm    r0,r0,24,8,31
  extsb     r0, r0
  stb       r0, 0x2(r4)
  lwz       r0, 0x0(r5)
  extsb     r0, r0
  stb       r0, 0x3(r4)
  lwz       r0, 0x2A40(r13)
  rlwinm    r0,r0,0,21,23
  cmpwi     r0, 0x400
  beq-      .loc_0x1CC
  bge-      .loc_0x6C
  cmpwi     r0, 0x200
  beq-      .loc_0x138
  bge-      .loc_0x60
  cmpwi     r0, 0x100
  beq-      .loc_0xE4
  bge-      .loc_0x20C
  cmpwi     r0, 0
  beq-      .loc_0x90
  b         .loc_0x20C

.loc_0x60:
  cmpwi     r0, 0x300
  beq-      .loc_0x188
  b         .loc_0x20C

.loc_0x6C:
  cmpwi     r0, 0x600
  beq-      .loc_0x90
  bge-      .loc_0x84
  cmpwi     r0, 0x500
  beq-      .loc_0x90
  b         .loc_0x20C

.loc_0x84:
  cmpwi     r0, 0x700
  beq-      .loc_0x90
  b         .loc_0x20C

.loc_0x90:
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,8,24,31
  extsb     r0, r0
  stb       r0, 0x4(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,16,16,31
  extsb     r0, r0
  stb       r0, 0x5(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,24,24,27
  stb       r0, 0x6(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,28,24,27
  stb       r0, 0x7(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,0,24,27
  stb       r0, 0x8(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,4,24,27
  stb       r0, 0x9(r4)
  b         .loc_0x20C

.loc_0xE4:
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,8,24,27
  extsb     r0, r0
  stb       r0, 0x4(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,12,24,27
  extsb     r0, r0
  stb       r0, 0x5(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,16,24,31
  stb       r0, 0x6(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,24,24,31
  stb       r0, 0x7(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,0,24,27
  stb       r0, 0x8(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,4,24,27
  stb       r0, 0x9(r4)
  b         .loc_0x20C

.loc_0x138:
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,8,24,27
  extsb     r0, r0
  stb       r0, 0x4(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,12,24,27
  extsb     r0, r0
  stb       r0, 0x5(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,16,24,27
  stb       r0, 0x6(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,20,24,27
  stb       r0, 0x7(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,24,24,31
  stb       r0, 0x8(r4)
  lwz       r0, 0x4(r5)
  stb       r0, 0x9(r4)
  b         .loc_0x20C

.loc_0x188:
  lwz       r6, 0x4(r5)
  li        r0, 0
  rlwinm    r6,r6,8,24,31
  extsb     r6, r6
  stb       r6, 0x4(r4)
  lwz       r6, 0x4(r5)
  rlwinm    r6,r6,16,16,31
  extsb     r6, r6
  stb       r6, 0x5(r4)
  lwz       r6, 0x4(r5)
  rlwinm    r6,r6,24,24,31
  stb       r6, 0x6(r4)
  lwz       r5, 0x4(r5)
  stb       r5, 0x7(r4)
  stb       r0, 0x8(r4)
  stb       r0, 0x9(r4)
  b         .loc_0x20C

.loc_0x1CC:
  lwz       r6, 0x4(r5)
  li        r0, 0
  rlwinm    r6,r6,8,24,31
  extsb     r6, r6
  stb       r6, 0x4(r4)
  lwz       r6, 0x4(r5)
  rlwinm    r6,r6,16,16,31
  extsb     r6, r6
  stb       r6, 0x5(r4)
  stb       r0, 0x6(r4)
  stb       r0, 0x7(r4)
  lwz       r0, 0x4(r5)
  rlwinm    r0,r0,24,24,31
  stb       r0, 0x8(r4)
  lwz       r0, 0x4(r5)
  stb       r0, 0x9(r4)

.loc_0x20C:
  lbz       r6, 0x2(r4)
  lis       r5, 0x803D
  mulli     r3, r3, 0xC
  subi      r0, r6, 0x80
  stb       r0, 0x2(r4)
  addi      r0, r5, 0x33D0
  add       r3, r0, r3
  lbz       r5, 0x3(r4)
  subi      r0, r5, 0x80
  stb       r0, 0x3(r4)
  lbz       r5, 0x4(r4)
  subi      r0, r5, 0x80
  stb       r0, 0x4(r4)
  lbz       r5, 0x5(r4)
  subi      r0, r5, 0x80
  stb       r0, 0x5(r4)
  lbz       r7, 0x2(r3)
  lbz       r6, 0x2(r4)
  extsb.    r0, r7
  ble-      .loc_0x27C
  extsb     r5, r7
  subi      r0, r5, 0x80
  extsb     r5, r0
  extsb     r0, r6
  cmpw      r0, r5
  bge-      .loc_0x2A0
  mr        r6, r5
  b         .loc_0x2A0

.loc_0x27C:
  extsb.    r0, r7
  bge-      .loc_0x2A0
  extsb     r5, r7
  addi      r0, r5, 0x7F
  extsb     r5, r0
  extsb     r0, r6
  cmpw      r5, r0
  bge-      .loc_0x2A0
  mr        r6, r5

.loc_0x2A0:
  sub       r6, r6, r7
  stb       r6, 0x2(r4)
  lbz       r7, 0x3(r3)
  lbz       r6, 0x3(r4)
  extsb.    r0, r7
  ble-      .loc_0x2D8
  extsb     r5, r7
  subi      r0, r5, 0x80
  extsb     r5, r0
  extsb     r0, r6
  cmpw      r0, r5
  bge-      .loc_0x2FC
  mr        r6, r5
  b         .loc_0x2FC

.loc_0x2D8:
  extsb.    r0, r7
  bge-      .loc_0x2FC
  extsb     r5, r7
  addi      r0, r5, 0x7F
  extsb     r5, r0
  extsb     r0, r6
  cmpw      r5, r0
  bge-      .loc_0x2FC
  mr        r6, r5

.loc_0x2FC:
  sub       r6, r6, r7
  stb       r6, 0x3(r4)
  lbz       r7, 0x4(r3)
  lbz       r6, 0x4(r4)
  extsb.    r0, r7
  ble-      .loc_0x334
  extsb     r5, r7
  subi      r0, r5, 0x80
  extsb     r5, r0
  extsb     r0, r6
  cmpw      r0, r5
  bge-      .loc_0x358
  mr        r6, r5
  b         .loc_0x358

.loc_0x334:
  extsb.    r0, r7
  bge-      .loc_0x358
  extsb     r5, r7
  addi      r0, r5, 0x7F
  extsb     r5, r0
  extsb     r0, r6
  cmpw      r5, r0
  bge-      .loc_0x358
  mr        r6, r5

.loc_0x358:
  sub       r6, r6, r7
  stb       r6, 0x4(r4)
  lbz       r7, 0x5(r3)
  lbz       r6, 0x5(r4)
  extsb.    r0, r7
  ble-      .loc_0x390
  extsb     r5, r7
  subi      r0, r5, 0x80
  extsb     r5, r0
  extsb     r0, r6
  cmpw      r0, r5
  bge-      .loc_0x3B4
  mr        r6, r5
  b         .loc_0x3B4

.loc_0x390:
  extsb.    r0, r7
  bge-      .loc_0x3B4
  extsb     r5, r7
  addi      r0, r5, 0x7F
  extsb     r5, r0
  extsb     r0, r6
  cmpw      r5, r0
  bge-      .loc_0x3B4
  mr        r6, r5

.loc_0x3B4:
  sub       r6, r6, r7
  stb       r6, 0x5(r4)
  lbz       r0, 0x6(r3)
  lbz       r5, 0x6(r4)
  cmplw     r5, r0
  bge-      .loc_0x3D0
  mr        r5, r0

.loc_0x3D0:
  sub       r5, r5, r0
  stb       r5, 0x6(r4)
  lbz       r0, 0x7(r3)
  lbz       r3, 0x7(r4)
  cmplw     r3, r0
  bge-      .loc_0x3EC
  mr        r3, r0

.loc_0x3EC:
  sub       r3, r3, r0
  stb       r3, 0x7(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void PADGetType(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void PADSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void PADSetAnalogMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80205EE8
 * Size:	00011C
 */
void OnReset(void)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  bne-      .loc_0xF4
  lwz       r0, 0x3360(r13)
  li        r29, 0
  addi      r3, r29, 0
  cmplwi    r0, 0
  bne-      .loc_0x44
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0x20
  bne-      .loc_0x44
  li        r3, 0x1

.loc_0x44:
  cmpwi     r3, 0
  beq-      .loc_0x5C
  bl        -0xAF8C
  cmpwi     r3, 0
  bne-      .loc_0x5C
  li        r29, 0x1

.loc_0x5C:
  lwz       r0, 0x3378(r13)
  cmpwi     r0, 0
  bne-      .loc_0xEC
  cmpwi     r29, 0
  beq-      .loc_0xEC
  lis       r29, 0xF000
  li        r31, 0
  bl        -0xCFE4
  lwz       r4, 0x3364(r13)
  mr        r30, r3
  lwz       r0, 0x336C(r13)
  lwz       r3, 0x3370(r13)
  or        r0, r4, r0
  lwz       r4, 0x3360(r13)
  or        r0, r3, r0
  lwz       r3, 0x335C(r13)
  andc      r29, r29, r0
  lwz       r0, 0x3368(r13)
  or        r4, r4, r29
  andc      r3, r3, r29
  stw       r4, 0x3360(r13)
  or        r0, r0, r29
  stw       r3, 0x335C(r13)
  lwz       r3, 0x3360(r13)
  stw       r0, 0x3368(r13)
  bl        -0xA8D8
  lwz       r0, 0x2A38(r13)
  cmpwi     r0, 0x20
  bne-      .loc_0xD8
  bl        -0x21B4
  mr        r31, r3

.loc_0xD8:
  mr        r3, r30
  bl        -0xD020
  stw       r31, 0x3378(r13)
  li        r3, 0
  b         .loc_0x100

.loc_0xEC:
  mr        r3, r29
  b         .loc_0x100

.loc_0xF4:
  li        r0, 0
  stw       r0, 0x3378(r13)
  li        r3, 0x1

.loc_0x100:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void __PADDisableXPatch(void)
{
	// UNUSED FUNCTION
}