

/*
 * --INFO--
 * Address:	801FEF80
 * Size:	000038
 */
void __DVDFSInit(void)
{
/*
.loc_0x0:
  lis       r3, 0x8000
  stw       r3, 0x3298(r13)
  lwz       r0, 0x38(r3)
  stw       r0, 0x329C(r13)
  lwz       r3, 0x329C(r13)
  cmplwi    r3, 0
  beqlr-    
  lwz       r0, 0x8(r3)
  stw       r0, 0x32A4(r13)
  lwz       r0, 0x32A4(r13)
  mulli     r0, r0, 0xC
  add       r0, r3, r0
  stw       r0, 0x32A0(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void isSame(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FEFB8
 * Size:	0002E0
 */
void DVDConvertPathToEntrynum(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stmw      r20, 0x18(r1)
  mr        r23, r3
  lis       r3, 0x802F
  addi      r25, r23, 0
  subi      r31, r3, 0x7BA0
  lwz       r28, 0x32A8(r13)

.loc_0x24:
  lbz       r0, 0x0(r23)
  cmplwi    r0, 0
  bne-      .loc_0x38
  mr        r3, r28
  b         .loc_0x2CC

.loc_0x38:
  cmplwi    r0, 0x2F
  bne-      .loc_0x4C
  li        r28, 0
  addi      r23, r23, 0x1
  b         .loc_0x24

.loc_0x4C:
  cmplwi    r0, 0x2E
  bne-      .loc_0xC0
  lbz       r0, 0x1(r23)
  cmplwi    r0, 0x2E
  bne-      .loc_0xA0
  lbz       r0, 0x2(r23)
  cmplwi    r0, 0x2F
  bne-      .loc_0x84
  mulli     r3, r28, 0xC
  lwz       r4, 0x329C(r13)
  addi      r0, r3, 0x4
  lwzx      r28, r4, r0
  addi      r23, r23, 0x3
  b         .loc_0x24

.loc_0x84:
  cmplwi    r0, 0
  bne-      .loc_0xC0
  mulli     r0, r28, 0xC
  lwz       r3, 0x329C(r13)
  add       r3, r3, r0
  lwz       r3, 0x4(r3)
  b         .loc_0x2CC

.loc_0xA0:
  cmplwi    r0, 0x2F
  bne-      .loc_0xB0
  addi      r23, r23, 0x2
  b         .loc_0x24

.loc_0xB0:
  cmplwi    r0, 0
  bne-      .loc_0xC0
  mr        r3, r28
  b         .loc_0x2CC

.loc_0xC0:
  lwz       r0, 0x32AC(r13)
  cmplwi    r0, 0
  bne-      .loc_0x16C
  addi      r20, r23, 0
  li        r4, 0
  li        r3, 0
  b         .loc_0x11C

.loc_0xDC:
  cmplwi    r0, 0x2E
  bne-      .loc_0x10C
  sub       r0, r20, r23
  cmpwi     r0, 0x8
  bgt-      .loc_0xF8
  cmpwi     r4, 0x1
  bne-      .loc_0x100

.loc_0xF8:
  li        r3, 0x1
  b         .loc_0x130

.loc_0x100:
  addi      r24, r20, 0x1
  li        r4, 0x1
  b         .loc_0x118

.loc_0x10C:
  cmplwi    r0, 0x20
  bne-      .loc_0x118
  li        r3, 0x1

.loc_0x118:
  addi      r20, r20, 0x1

.loc_0x11C:
  lbz       r0, 0x0(r20)
  cmplwi    r0, 0
  beq-      .loc_0x130
  cmplwi    r0, 0x2F
  bne+      .loc_0xDC

.loc_0x130:
  cmpwi     r4, 0x1
  bne-      .loc_0x148
  sub       r0, r20, r24
  cmpwi     r0, 0x3
  ble-      .loc_0x148
  li        r3, 0x1

.loc_0x148:
  cmpwi     r3, 0
  beq-      .loc_0x18C
  addi      r5, r31, 0
  crclr     6, 0x6
  addi      r6, r25, 0
  addi      r3, r13, 0x2A10
  li        r4, 0x175
  bl        -0x780C
  b         .loc_0x18C

.loc_0x16C:
  mr        r20, r23
  b         .loc_0x178

.loc_0x174:
  addi      r20, r20, 0x1

.loc_0x178:
  lbz       r0, 0x0(r20)
  cmplwi    r0, 0
  beq-      .loc_0x18C
  cmplwi    r0, 0x2F
  bne+      .loc_0x174

.loc_0x18C:
  lbz       r0, 0x0(r20)
  cmplwi    r0, 0
  bne-      .loc_0x1A0
  li        r30, 0
  b         .loc_0x1A4

.loc_0x1A0:
  li        r30, 0x1

.loc_0x1A4:
  mulli     r29, r28, 0xC
  sub       r27, r20, r23
  addi      r26, r28, 0x1
  b         .loc_0x290

.loc_0x1B4:
  mulli     r28, r26, 0xC
  lwzx      r4, r3, r28
  rlwinm.   r0,r4,0,0,7
  bne-      .loc_0x1CC
  li        r0, 0
  b         .loc_0x1D0

.loc_0x1CC:
  li        r0, 0x1

.loc_0x1D0:
  cmpwi     r0, 0
  bne-      .loc_0x1E0
  cmpwi     r30, 0x1
  beq-      .loc_0x258

.loc_0x1E0:
  lwz       r3, 0x32A0(r13)
  rlwinm    r0,r4,0,8,31
  addi      r21, r23, 0
  add       r20, r3, r0
  b         .loc_0x224

.loc_0x1F4:
  lbz       r3, 0x0(r20)
  addi      r20, r20, 0x1
  bl        0x16C28
  lbz       r0, 0x0(r21)
  addi      r22, r3, 0
  addi      r21, r21, 0x1
  mr        r3, r0
  bl        0x16C14
  cmpw      r3, r22
  beq-      .loc_0x224
  li        r0, 0
  b         .loc_0x250

.loc_0x224:
  lbz       r0, 0x0(r20)
  cmplwi    r0, 0
  bne+      .loc_0x1F4
  lbz       r0, 0x0(r21)
  cmplwi    r0, 0x2F
  beq-      .loc_0x244
  cmplwi    r0, 0
  bne-      .loc_0x24C

.loc_0x244:
  li        r0, 0x1
  b         .loc_0x250

.loc_0x24C:
  li        r0, 0

.loc_0x250:
  cmpwi     r0, 0x1
  beq-      .loc_0x2AC

.loc_0x258:
  lwz       r0, 0x329C(r13)
  add       r3, r0, r28
  lwz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,0,7
  bne-      .loc_0x274
  li        r0, 0
  b         .loc_0x278

.loc_0x274:
  li        r0, 0x1

.loc_0x278:
  cmpwi     r0, 0
  beq-      .loc_0x288
  lwz       r0, 0x8(r3)
  b         .loc_0x28C

.loc_0x288:
  addi      r0, r26, 0x1

.loc_0x28C:
  mr        r26, r0

.loc_0x290:
  lwz       r3, 0x329C(r13)
  addi      r0, r3, 0x8
  lwzx      r0, r29, r0
  cmplw     r26, r0
  blt+      .loc_0x1B4
  li        r3, -0x1
  b         .loc_0x2CC

.loc_0x2AC:
  cmpwi     r30, 0
  bne-      .loc_0x2BC
  mr        r3, r26
  b         .loc_0x2CC

.loc_0x2BC:
  add       r23, r27, r23
  addi      r28, r26, 0
  addi      r23, r23, 0x1
  b         .loc_0x24

.loc_0x2CC:
  lmw       r20, 0x18(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FF298
 * Size:	000074
 */
void DVDFastOpen(void)
{
/*
.loc_0x0:
  cmpwi     r3, 0
  blt-      .loc_0x3C
  lwz       r0, 0x32A4(r13)
  cmplw     r3, r0
  bge-      .loc_0x3C
  mulli     r6, r3, 0xC
  lwz       r3, 0x329C(r13)
  lwzx      r0, r3, r6
  rlwinm.   r0,r0,0,0,7
  bne-      .loc_0x30
  li        r0, 0
  b         .loc_0x34

.loc_0x30:
  li        r0, 0x1

.loc_0x34:
  cmpwi     r0, 0
  beq-      .loc_0x44

.loc_0x3C:
  li        r3, 0
  blr       

.loc_0x44:
  add       r3, r3, r6
  lwz       r5, 0x4(r3)
  li        r0, 0
  li        r3, 0x1
  stw       r5, 0x30(r4)
  lwz       r5, 0x329C(r13)
  add       r5, r5, r6
  lwz       r5, 0x8(r5)
  stw       r5, 0x34(r4)
  stw       r0, 0x38(r4)
  stw       r0, 0xC(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	801FF30C
 * Size:	0000C8
 */
void DVDOpen(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x98(r1)
  stw       r31, 0x94(r1)
  addi      r31, r4, 0
  stw       r30, 0x90(r1)
  addi      r30, r3, 0
  bl        -0x370
  cmpwi     r3, 0
  bge-      .loc_0x54
  addi      r3, r1, 0x10
  li        r4, 0x80
  bl        0x21C
  lis       r3, 0x802F
  crclr     6, 0x6
  subi      r3, r3, 0x7AD8
  addi      r4, r30, 0
  addi      r5, r1, 0x10
  bl        -0x7AC4
  li        r3, 0
  b         .loc_0xB0

.loc_0x54:
  mulli     r5, r3, 0xC
  lwz       r3, 0x329C(r13)
  lwzx      r0, r3, r5
  rlwinm.   r0,r0,0,0,7
  bne-      .loc_0x70
  li        r0, 0
  b         .loc_0x74

.loc_0x70:
  li        r0, 0x1

.loc_0x74:
  cmpwi     r0, 0
  beq-      .loc_0x84
  li        r3, 0
  b         .loc_0xB0

.loc_0x84:
  add       r3, r3, r5
  lwz       r4, 0x4(r3)
  li        r0, 0
  li        r3, 0x1
  stw       r4, 0x30(r31)
  lwz       r4, 0x329C(r13)
  add       r4, r4, r5
  lwz       r4, 0x8(r4)
  stw       r4, 0x34(r31)
  stw       r0, 0x38(r31)
  stw       r0, 0xC(r31)

.loc_0xB0:
  lwz       r0, 0x9C(r1)
  lwz       r31, 0x94(r1)
  lwz       r30, 0x90(r1)
  mtlr      r0
  addi      r1, r1, 0x98
  blr
*/
}

/*
 * --INFO--
 * Address:	801FF3D4
 * Size:	000024
 */
void DVDClose(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x284C
  lwz       r0, 0xC(r1)
  li        r3, 0x1
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void myStrncpy(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FF3F8
 * Size:	000160
 */
void entryToPath(void)
{
/*
.loc_0x0:
  mflr      r0
  cmplwi    r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  addi      r30, r5, 0
  stw       r29, 0x24(r1)
  addi      r29, r4, 0
  stw       r28, 0x20(r1)
  bne-      .loc_0x34
  li        r3, 0
  b         .loc_0x140

.loc_0x34:
  lwz       r4, 0x329C(r13)
  mulli     r3, r3, 0xC
  lwz       r6, 0x32A0(r13)
  addi      r5, r4, 0x4
  lwzx      r0, r4, r3
  lwzx      r3, r5, r3
  rlwinm    r0,r0,0,8,31
  cmplwi    r3, 0
  add       r31, r6, r0
  bne-      .loc_0x64
  li        r3, 0
  b         .loc_0xE0

.loc_0x64:
  mulli     r3, r3, 0xC
  lwzx      r0, r4, r3
  mr        r4, r29
  lwzx      r3, r5, r3
  addi      r5, r30, 0
  rlwinm    r0,r0,0,8,31
  add       r28, r6, r0
  bl        .loc_0x0
  cmplw     r3, r30
  bne-      .loc_0x90
  b         .loc_0xE0

.loc_0x90:
  addi      r0, r3, 0
  addi      r3, r3, 0x1
  li        r4, 0x2F
  sub       r6, r30, r3
  stbx      r4, r29, r0
  addi      r4, r6, 0
  add       r5, r29, r3
  b         .loc_0xC4

.loc_0xB0:
  lbz       r0, 0x0(r28)
  addi      r28, r28, 0x1
  subi      r4, r4, 0x1
  stb       r0, 0x0(r5)
  addi      r5, r5, 0x1

.loc_0xC4:
  cmplwi    r4, 0
  beq-      .loc_0xD8
  lbz       r0, 0x0(r28)
  cmplwi    r0, 0
  bne+      .loc_0xB0

.loc_0xD8:
  sub       r0, r6, r4
  add       r3, r3, r0

.loc_0xE0:
  cmplw     r3, r30
  bne-      .loc_0xEC
  b         .loc_0x140

.loc_0xEC:
  addi      r0, r3, 0
  addi      r3, r3, 0x1
  li        r4, 0x2F
  sub       r7, r30, r3
  stbx      r4, r29, r0
  addi      r6, r31, 0
  addi      r4, r7, 0
  add       r5, r29, r3
  b         .loc_0x124

.loc_0x110:
  lbz       r0, 0x0(r6)
  addi      r6, r6, 0x1
  subi      r4, r4, 0x1
  stb       r0, 0x0(r5)
  addi      r5, r5, 0x1

.loc_0x124:
  cmplwi    r4, 0
  beq-      .loc_0x138
  lbz       r0, 0x0(r6)
  cmplwi    r0, 0
  bne+      .loc_0x110

.loc_0x138:
  sub       r0, r7, r4
  add       r3, r3, r0

.loc_0x140:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  mtlr      r0
  lwz       r29, 0x24(r1)
  lwz       r28, 0x20(r1)
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
void DVDConvertEntrynumToPath(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FF558
 * Size:	0000C4
 */
void DVDGetCurrentDir(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  addi      r30, r4, 0
  addi      r5, r30, 0
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  addi      r4, r29, 0
  lwz       r31, 0x32A8(r13)
  addi      r3, r31, 0
  bl        -0x190
  cmplw     r3, r30
  bne-      .loc_0x4C
  li        r0, 0
  add       r3, r29, r30
  stb       r0, -0x1(r3)
  b         .loc_0xA4

.loc_0x4C:
  mulli     r0, r31, 0xC
  lwz       r4, 0x329C(r13)
  lwzx      r0, r4, r0
  rlwinm.   r0,r0,0,0,7
  bne-      .loc_0x68
  li        r0, 0
  b         .loc_0x6C

.loc_0x68:
  li        r0, 0x1

.loc_0x6C:
  cmpwi     r0, 0
  beq-      .loc_0x98
  subi      r0, r30, 0x1
  cmplw     r3, r0
  bne-      .loc_0x8C
  li        r0, 0
  stbx      r0, r29, r3
  b         .loc_0xA4

.loc_0x8C:
  li        r0, 0x2F
  stbx      r0, r29, r3
  addi      r3, r3, 0x1

.loc_0x98:
  li        r0, 0
  stbx      r0, r29, r3
  li        r0, 0x1

.loc_0xA4:
  mr        r3, r0
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
 * Size:	000060
 */
void DVDChangeDir(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FF61C
 * Size:	0000C0
 */
void DVDReadAsyncPrio(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r26, 0x20(r1)
  mr.       r29, r6
  addi      r26, r3, 0
  addi      r27, r4, 0
  addi      r28, r5, 0
  addi      r30, r7, 0
  addi      r31, r8, 0
  blt-      .loc_0x38
  lwz       r0, 0x34(r26)
  cmplw     r29, r0
  blt-      .loc_0x50

.loc_0x38:
  lis       r3, 0x802F
  crclr     6, 0x6
  subi      r5, r3, 0x7AA0
  addi      r3, r13, 0x2A10
  li        r4, 0x2DF
  bl        -0x7D58

.loc_0x50:
  add.      r4, r29, r28
  blt-      .loc_0x68
  lwz       r3, 0x34(r26)
  addi      r0, r3, 0x20
  cmplw     r4, r0
  blt-      .loc_0x80

.loc_0x68:
  lis       r3, 0x802F
  crclr     6, 0x6
  subi      r5, r3, 0x7AA0
  addi      r3, r13, 0x2A10
  li        r4, 0x2E5
  bl        -0x7D88

.loc_0x80:
  stw       r30, 0x38(r26)
  lis       r3, 0x8020
  subi      r7, r3, 0x924
  lwz       r0, 0x30(r26)
  addi      r3, r26, 0
  addi      r4, r27, 0
  addi      r5, r28, 0
  addi      r8, r31, 0
  add       r6, r0, r29
  bl        0x1E00
  lmw       r26, 0x20(r1)
  li        r3, 0x1
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FF6DC
 * Size:	000030
 */
void cbForReadAsync(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x38(r4)
  cmplwi    r12, 0
  beq-      .loc_0x20
  mtlr      r12
  blrl      

.loc_0x20:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FF70C
 * Size:	000118
 */
void DVDReadPrio(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  mr.       r29, r6
  addi      r31, r3, 0
  addi      r27, r4, 0
  addi      r28, r5, 0
  addi      r30, r7, 0
  blt-      .loc_0x34
  lwz       r0, 0x34(r31)
  cmplw     r29, r0
  blt-      .loc_0x4C

.loc_0x34:
  lis       r3, 0x802F
  crclr     6, 0x6
  subi      r5, r3, 0x7A6C
  addi      r3, r13, 0x2A10
  li        r4, 0x325
  bl        -0x7E44

.loc_0x4C:
  add.      r4, r29, r28
  blt-      .loc_0x64
  lwz       r3, 0x34(r31)
  addi      r0, r3, 0x20
  cmplw     r4, r0
  blt-      .loc_0x7C

.loc_0x64:
  lis       r3, 0x802F
  crclr     6, 0x6
  subi      r5, r3, 0x7A6C
  addi      r3, r13, 0x2A10
  li        r4, 0x32B
  bl        -0x7E74

.loc_0x7C:
  lwz       r0, 0x30(r31)
  lis       r4, 0x8020
  subi      r7, r4, 0x7DC
  addi      r3, r31, 0
  addi      r4, r27, 0
  addi      r5, r28, 0
  addi      r8, r30, 0
  add       r6, r0, r29
  bl        0x1D18
  cmpwi     r3, 0
  bne-      .loc_0xB0
  li        r3, -0x1
  b         .loc_0x104

.loc_0xB0:
  bl        -0x6840
  mr        r30, r3

.loc_0xB8:
  lwz       r0, 0xC(r31)
  cmpwi     r0, 0
  bne-      .loc_0xCC
  lwz       r31, 0x20(r31)
  b         .loc_0xF8

.loc_0xCC:
  cmpwi     r0, -0x1
  bne-      .loc_0xDC
  li        r31, -0x1
  b         .loc_0xF8

.loc_0xDC:
  cmpwi     r0, 0xA
  bne-      .loc_0xEC
  li        r31, -0x3
  b         .loc_0xF8

.loc_0xEC:
  addi      r3, r13, 0x32B0
  bl        -0x2E40
  b         .loc_0xB8

.loc_0xF8:
  mr        r3, r30
  bl        -0x6864
  mr        r3, r31

.loc_0x104:
  lmw       r27, 0x24(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FF824
 * Size:	000024
 */
void cbForReadSync(void)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r13, 0x32B0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x2D8C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void DVDSeekAsyncPrio(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void cbForSeekAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void DVDSeekPrio(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void cbForSeekSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void DVDGetFileInfoStatus(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void DVDOpenDir(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void DVDReadDir(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DVDCloseDir(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void DVDGetFSTLocation(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FF848
 * Size:	0000EC
 */
void DVDPrepareStreamAsync(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  addi      r29, r5, 0
  mr        r27, r3
  addi      r28, r4, 0
  addi      r30, r6, 0
  lwz       r7, 0x30(r3)
  lis       r3, 0x802F
  subi      r31, r3, 0x7BA0
  add       r0, r7, r29
  rlwinm.   r0,r0,0,17,31
  beq-      .loc_0x54
  addi      r6, r7, 0
  crclr     6, 0x6
  addi      r7, r29, 0
  addi      r5, r31, 0x18C
  addi      r3, r13, 0x2A10
  li        r4, 0x47E
  bl        -0x7F88

.loc_0x54:
  cmplwi    r28, 0
  bne-      .loc_0x64
  lwz       r0, 0x34(r27)
  sub       r28, r0, r29

.loc_0x64:
  rlwinm.   r0,r28,0,17,31
  beq-      .loc_0x84
  addi      r6, r28, 0
  crclr     6, 0x6
  addi      r5, r31, 0x1F4
  addi      r3, r13, 0x2A10
  li        r4, 0x488
  bl        -0x7FB8

.loc_0x84:
  lwz       r3, 0x34(r27)
  cmplw     r29, r3
  bge-      .loc_0x9C
  add       r0, r29, r28
  cmplw     r0, r3
  ble-      .loc_0xB8

.loc_0x9C:
  addi      r6, r29, 0
  crclr     6, 0x6
  addi      r7, r28, 0
  addi      r5, r31, 0x24C
  addi      r3, r13, 0x2A10
  li        r4, 0x490
  bl        -0x7FEC

.loc_0xB8:
  stw       r30, 0x38(r27)
  lis       r3, 0x8020
  subi      r6, r3, 0x6CC
  lwz       r0, 0x30(r27)
  addi      r3, r27, 0
  addi      r4, r28, 0
  add       r5, r0, r29
  bl        0x1E24
  lmw       r27, 0x24(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FF934
 * Size:	000030
 */
void cbForPrepareStreamAsync(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x38(r4)
  cmplwi    r12, 0
  beq-      .loc_0x20
  mtlr      r12
  blrl      

.loc_0x20:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000144
 */
void DVDPrepareStream(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void cbForPrepareStreamSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void DVDGetTransferredSize(void)
{
	// UNUSED FUNCTION
}
