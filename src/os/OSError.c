

/*
 * --INFO--
 * Address:	801F7890
 * Size:	000080
 */
void OSReport(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  bne-      cr1, .loc_0x30
  stfd      f1, 0x28(r1)
  stfd      f2, 0x30(r1)
  stfd      f3, 0x38(r1)
  stfd      f4, 0x40(r1)
  stfd      f5, 0x48(r1)
  stfd      f6, 0x50(r1)
  stfd      f7, 0x58(r1)
  stfd      f8, 0x60(r1)

.loc_0x30:
  stw       r3, 0x8(r1)
  lis       r0, 0x100
  stw       r4, 0xC(r1)
  addi      r4, r1, 0x6C
  stw       r5, 0x10(r1)
  stw       r6, 0x14(r1)
  stw       r7, 0x18(r1)
  stw       r8, 0x1C(r1)
  stw       r9, 0x20(r1)
  stw       r10, 0x24(r1)
  stw       r0, 0x6C(r1)
  addi      r0, r1, 0x80
  stw       r0, 0x70(r1)
  addi      r0, r1, 0x8
  stw       r0, 0x74(r1)
  bl        0x1EDE8
  lwz       r0, 0x7C(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F7910
 * Size:	00012C
 */
void OSPanic(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x90(r1)
  stw       r31, 0x8C(r1)
  stw       r30, 0x88(r1)
  stw       r29, 0x84(r1)
  stw       r28, 0x80(r1)
  bne-      cr1, .loc_0x40
  stfd      f1, 0x28(r1)
  stfd      f2, 0x30(r1)
  stfd      f3, 0x38(r1)
  stfd      f4, 0x40(r1)
  stfd      f5, 0x48(r1)
  stfd      f6, 0x50(r1)
  stfd      f7, 0x58(r1)
  stfd      f8, 0x60(r1)

.loc_0x40:
  stw       r3, 0x8(r1)
  addi      r28, r3, 0
  addi      r30, r4, 0
  stw       r4, 0xC(r1)
  addi      r29, r5, 0
  stw       r5, 0x10(r1)
  stw       r6, 0x14(r1)
  lis       r6, 0x802E
  addi      r31, r6, 0x78F0
  stw       r7, 0x18(r1)
  stw       r8, 0x1C(r1)
  stw       r9, 0x20(r1)
  stw       r10, 0x24(r1)
  bl        0x15F8
  lis       r0, 0x300
  stw       r0, 0x74(r1)
  addi      r0, r1, 0x98
  addi      r4, r1, 0x74
  stw       r0, 0x78(r1)
  addi      r0, r1, 0x8
  addi      r3, r29, 0
  stw       r0, 0x7C(r1)
  bl        0x1ED3C
  addi      r3, r31, 0
  crclr     6, 0x6
  addi      r4, r28, 0
  addi      r5, r30, 0
  bl        -0x12C
  addi      r3, r31, 0x18
  crclr     6, 0x6
  bl        -0x138
  li        r30, 0
  bl        -0x59C
  mr        r29, r3
  b         .loc_0xE8

.loc_0xCC:
  lwz       r5, 0x0(r29)
  mr        r4, r29
  lwz       r6, 0x4(r29)
  addi      r3, r31, 0x40
  crclr     6, 0x6
  bl        -0x160
  lwz       r29, 0x0(r29)

.loc_0xE8:
  cmplwi    r29, 0
  beq-      .loc_0x108
  addis     r0, r29, 0x1
  cmplwi    r0, 0xFFFF
  beq-      .loc_0x108
  cmplwi    r30, 0x10
  addi      r30, r30, 0x1
  blt+      .loc_0xCC

.loc_0x108:
  bl        -0x209C
  lwz       r0, 0x94(r1)
  lwz       r31, 0x8C(r1)
  lwz       r30, 0x88(r1)
  mtlr      r0
  lwz       r29, 0x84(r1)
  lwz       r28, 0x80(r1)
  addi      r1, r1, 0x90
  blr
*/
}

/*
 * --INFO--
 * Address:	801F7A3C
 * Size:	00001C
 */
void OSSetErrorHandler(void)
{
/*
.loc_0x0:
  lis       r5, 0x803D
  rlwinm    r3,r3,2,14,29
  addi      r0, r5, 0x23B0
  add       r5, r0, r3
  lwz       r3, 0x0(r5)
  stw       r4, 0x0(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	801F7A58
 * Size:	000174
 */
void __OSUnhandledException(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  mr        r28, r4
  addi      r27, r3, 0
  addi      r29, r5, 0
  addi      r30, r6, 0
  lwz       r0, 0x19C(r4)
  lis       r4, 0x802E
  addi      r31, r4, 0x78F0
  rlwinm.   r0,r0,0,30,30
  bne-      .loc_0x48
  addi      r3, r31, 0x5C
  crclr     6, 0x6
  rlwinm    r4,r27,0,24,31
  bl        -0x208
  b         .loc_0xAC

.loc_0x48:
  rlwinm    r3,r27,0,24,31
  lis       r4, 0x803D
  rlwinm    r5,r27,2,22,29
  addi      r0, r4, 0x23B0
  add       r4, r0, r5
  lwz       r12, 0x0(r4)
  cmplwi    r12, 0
  beq-      .loc_0x88
  mtlr      r12
  addi      r4, r28, 0
  addi      r5, r29, 0
  crclr     6, 0x6
  addi      r6, r30, 0
  blrl      
  mr        r3, r28
  bl        -0x780

.loc_0x88:
  rlwinm    r0,r27,0,24,31
  cmplwi    r0, 0x8
  bne-      .loc_0x9C
  mr        r3, r28
  bl        -0x794

.loc_0x9C:
  addi      r3, r31, 0x7C
  crclr     6, 0x6
  rlwinm    r4,r27,0,24,31
  bl        -0x270

.loc_0xAC:
  addi      r3, r13, 0x29E8
  crclr     6, 0x6
  bl        -0x27C
  mr        r3, r28
  bl        -0x5F8
  addi      r4, r29, 0
  crclr     6, 0x6
  addi      r5, r30, 0
  addi      r3, r31, 0x94
  bl        -0x298
  rlwinm    r0,r27,0,24,31
  cmpwi     r0, 0x4
  beq-      .loc_0x15C
  bge-      .loc_0xF4
  cmpwi     r0, 0x2
  beq-      .loc_0x104
  bge-      .loc_0x11C
  b         .loc_0x15C

.loc_0xF4:
  cmpwi     r0, 0x6
  beq-      .loc_0x148
  bge-      .loc_0x15C
  b         .loc_0x130

.loc_0x104:
  lwz       r4, 0x198(r28)
  addi      r5, r30, 0
  addi      r3, r31, 0xC4
  crclr     6, 0x6
  bl        -0x2DC
  b         .loc_0x15C

.loc_0x11C:
  lwz       r4, 0x198(r28)
  addi      r3, r31, 0x124
  crclr     6, 0x6
  bl        -0x2F0
  b         .loc_0x15C

.loc_0x130:
  lwz       r4, 0x198(r28)
  addi      r5, r30, 0
  addi      r3, r31, 0x170
  crclr     6, 0x6
  bl        -0x308
  b         .loc_0x15C

.loc_0x148:
  lwz       r4, 0x198(r28)
  addi      r5, r30, 0
  addi      r3, r31, 0x1D4
  crclr     6, 0x6
  bl        -0x320

.loc_0x15C:
  bl        -0x2238
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}