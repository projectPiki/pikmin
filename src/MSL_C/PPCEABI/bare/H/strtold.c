

/*
 * --INFO--
 * Address:	8021942C
 * Size:	00008C
 */
void atof(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x30(r1)
  stw       r3, 0x28(r1)
  lis       r3, 0x8022
  subi      r4, r3, 0x7EB0
  lis       r3, 0x8000
  stw       r0, 0x2C(r1)
  subi      r3, r3, 0x1
  addi      r5, r1, 0x28
  addi      r6, r1, 0x20
  addi      r7, r1, 0x24
  bl        .loc_0x8C
  lwz       r0, 0x24(r1)
  fabs      f2, f1
  cmpwi     r0, 0
  bne-      .loc_0x74
  lfd       f0, -0x3BE0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x7C
  lis       r3, 0x802F
  lfd       f0, -0x6B80(r3)
  fcmpo     cr0, f2, f0
  blt-      .loc_0x74
  lis       r3, 0x802F
  lfd       f0, -0x6B78(r3)
  fcmpo     cr0, f2, f0
  ble-      .loc_0x7C

.loc_0x74:
  li        r0, 0x22
  stw       r0, 0x3490(r13)

.loc_0x7C:
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr       

.loc_0x8C:
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void strtod(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802194B8
 * Size:	0006E4
 */
void __strtold(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r8, 0x802F
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stmw      r17, 0x4C(r1)
  mr        r29, r4
  mr        r12, r29
  addi      r28, r5, 0
  mtlr      r12
  addi      r20, r3, 0
  addi      r22, r7, 0
  addi      r17, r6, 0
  mr        r3, r28
  li        r31, 0x1
  li        r21, 0
  li        r18, 0
  li        r19, 0
  li        r26, 0
  li        r25, 0
  li        r30, 0x1
  lwz       r9, -0x6F30(r8)
  lis       r8, 0x8022
  lwzu      r4, 0x2B48(r8)
  lbz       r23, 0x0(r9)
  lwz       r0, 0x4(r8)
  stw       r4, 0x1C(r1)
  stw       r0, 0x20(r1)
  li        r0, 0
  lwz       r5, 0x8(r8)
  lwz       r4, 0xC(r8)
  stw       r5, 0x24(r1)
  li        r5, 0
  stw       r4, 0x28(r1)
  li        r4, 0
  lwz       r7, 0x10(r8)
  lwz       r6, 0x14(r8)
  stw       r7, 0x2C(r1)
  stw       r6, 0x30(r1)
  lwz       r7, 0x18(r8)
  lwz       r6, 0x1C(r8)
  stw       r7, 0x34(r1)
  stw       r6, 0x38(r1)
  lwz       r7, 0x20(r8)
  lwz       r6, 0x24(r8)
  stw       r7, 0x3C(r1)
  stw       r6, 0x40(r1)
  lhz       r6, 0x28(r8)
  sth       r6, 0x44(r1)
  stw       r0, 0x0(r22)
  blrl      
  lis       r5, 0x8022
  addi      r4, r3, 0
  addi      r27, r5, 0x2808
  addi      r24, r1, 0x1C
  b         .loc_0x55C

.loc_0xDC:
  cmpwi     r31, 0x20
  beq-      .loc_0x368
  bge-      .loc_0x124
  cmpwi     r31, 0x4
  beq-      .loc_0x27C
  bge-      .loc_0x10C
  cmpwi     r31, 0x2
  beq-      .loc_0x1F8
  bge-      .loc_0x55C
  cmpwi     r31, 0x1
  bge-      .loc_0x160
  b         .loc_0x55C

.loc_0x10C:
  cmpwi     r31, 0x10
  beq-      .loc_0x344
  bge-      .loc_0x55C
  cmpwi     r31, 0x8
  beq-      .loc_0x2B0
  b         .loc_0x55C

.loc_0x124:
  cmpwi     r31, 0x100
  beq-      .loc_0x47C
  bge-      .loc_0x148
  cmpwi     r31, 0x80
  beq-      .loc_0x41C
  bge-      .loc_0x55C
  cmpwi     r31, 0x40
  beq-      .loc_0x3DC
  b         .loc_0x55C

.loc_0x148:
  cmpwi     r31, 0x400
  beq-      .loc_0x504
  bge-      .loc_0x55C
  cmpwi     r31, 0x200
  beq-      .loc_0x4D0
  b         .loc_0x55C

.loc_0x160:
  rlwinm    r0,r4,0,24,31
  add       r3, r27, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,29,30
  beq-      .loc_0x198
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  blrl      
  addi      r4, r3, 0
  addi      r21, r21, 0x1
  b         .loc_0x55C

.loc_0x198:
  cmpwi     r4, 0x2B
  bne-      .loc_0x1C4
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x1F0

.loc_0x1C4:
  cmpwi     r4, 0x2D
  bne-      .loc_0x1F0
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  addi      r4, r3, 0
  li        r18, 0x1

.loc_0x1F0:
  li        r31, 0x2
  b         .loc_0x55C

.loc_0x1F8:
  cmpw      r4, r23
  bne-      .loc_0x228
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r31, 0x10
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x55C

.loc_0x228:
  rlwinm    r0,r4,0,24,31
  add       r3, r27, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,27,27
  bne-      .loc_0x244
  li        r31, 0x1000
  b         .loc_0x55C

.loc_0x244:
  cmpwi     r4, 0x30
  bne-      .loc_0x274
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r31, 0x4
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x55C

.loc_0x274:
  li        r31, 0x8
  b         .loc_0x55C

.loc_0x27C:
  cmpwi     r4, 0x30
  bne-      .loc_0x2A8
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x55C

.loc_0x2A8:
  li        r31, 0x8
  b         .loc_0x55C

.loc_0x2B0:
  rlwinm    r5,r4,0,24,31
  add       r3, r27, r5
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,27,27
  bne-      .loc_0x2FC
  cmpw      r4, r23
  bne-      .loc_0x2F4
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r31, 0x20
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x55C

.loc_0x2F4:
  li        r31, 0x40
  b         .loc_0x55C

.loc_0x2FC:
  lbz       r3, 0x20(r1)
  cmplwi    r3, 0x14
  bge-      .loc_0x31C
  addi      r0, r3, 0x1
  stb       r0, 0x20(r1)
  addi      r0, r3, 0x5
  stbx      r5, r24, r0
  b         .loc_0x320

.loc_0x31C:
  addi      r25, r25, 0x1

.loc_0x320:
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x55C

.loc_0x344:
  rlwinm    r0,r4,0,24,31
  add       r3, r27, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,27,27
  bne-      .loc_0x360
  li        r31, 0x1000
  b         .loc_0x55C

.loc_0x360:
  li        r31, 0x20
  b         .loc_0x55C

.loc_0x368:
  rlwinm    r0,r4,0,24,31
  add       r3, r27, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,27,27
  bne-      .loc_0x384
  li        r31, 0x40
  b         .loc_0x55C

.loc_0x384:
  lbz       r0, 0x20(r1)
  cmplwi    r0, 0x14
  bge-      .loc_0x3B8
  cmpwi     r4, 0x30
  bne-      .loc_0x3A0
  cmplwi    r0, 0
  beq-      .loc_0x3B4

.loc_0x3A0:
  lbz       r3, 0x20(r1)
  addi      r0, r3, 0x1
  stb       r0, 0x20(r1)
  addi      r0, r3, 0x5
  stbx      r4, r24, r0

.loc_0x3B4:
  subi      r25, r25, 0x1

.loc_0x3B8:
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x55C

.loc_0x3DC:
  cmpwi     r4, 0x45
  beq-      .loc_0x3EC
  cmpwi     r4, 0x65
  bne-      .loc_0x414

.loc_0x3EC:
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r31, 0x80
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x55C

.loc_0x414:
  li        r31, 0x800
  b         .loc_0x55C

.loc_0x41C:
  cmpwi     r4, 0x2B
  bne-      .loc_0x448
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x474

.loc_0x448:
  cmpwi     r4, 0x2D
  bne-      .loc_0x474
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  addi      r4, r3, 0
  li        r19, 0x1

.loc_0x474:
  li        r31, 0x100
  b         .loc_0x55C

.loc_0x47C:
  rlwinm    r0,r4,0,24,31
  add       r3, r27, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,27,27
  bne-      .loc_0x498
  li        r31, 0x1000
  b         .loc_0x55C

.loc_0x498:
  cmpwi     r4, 0x30
  bne-      .loc_0x4C8
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r31, 0x200
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x55C

.loc_0x4C8:
  li        r31, 0x400
  b         .loc_0x55C

.loc_0x4D0:
  cmpwi     r4, 0x30
  bne-      .loc_0x4FC
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3
  b         .loc_0x55C

.loc_0x4FC:
  li        r31, 0x400
  b         .loc_0x55C

.loc_0x504:
  rlwinm    r0,r4,0,24,31
  add       r3, r27, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,27,27
  bne-      .loc_0x520
  li        r31, 0x800
  b         .loc_0x55C

.loc_0x520:
  mulli     r0, r26, 0xA
  add       r26, r4, r0
  subi      r26, r26, 0x30
  cmpwi     r26, 0x7FFF
  ble-      .loc_0x53C
  li        r0, 0x1
  stw       r0, 0x0(r22)

.loc_0x53C:
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0
  addi      r30, r30, 0x1
  blrl      
  mr        r4, r3

.loc_0x55C:
  cmpw      r30, r20
  bgt-      .loc_0x574
  cmpwi     r4, -0x1
  beq-      .loc_0x574
  rlwinm.   r0,r31,0,19,20
  beq+      .loc_0xDC

.loc_0x574:
  andi.     r0, r31, 0xE2C
  bne-      .loc_0x588
  li        r0, 0
  stw       r0, 0x0(r17)
  b         .loc_0x594

.loc_0x588:
  add       r3, r30, r21
  subi      r0, r3, 0x1
  stw       r0, 0x0(r17)

.loc_0x594:
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r5, 0x1
  blrl      
  cmpwi     r19, 0
  beq-      .loc_0x5B4
  neg       r26, r26

.loc_0x5B4:
  lbz       r3, 0x20(r1)
  addi      r0, r1, 0x1C
  addi      r4, r3, 0x5
  add       r4, r0, r4
  b         .loc_0x5CC

.loc_0x5C8:
  addi      r25, r25, 0x1

.loc_0x5CC:
  cmpwi     r3, 0
  subi      r3, r3, 0x1
  beq-      .loc_0x5E4
  lbzu      r0, -0x1(r4)
  cmplwi    r0, 0x30
  beq+      .loc_0x5C8

.loc_0x5E4:
  addi      r0, r3, 0x1
  stb       r0, 0x20(r1)
  lbz       r4, 0x20(r1)
  cmplwi    r4, 0
  bne-      .loc_0x60C
  addi      r0, r4, 0x1
  stb       r0, 0x20(r1)
  addi      r3, r1, 0x21
  li        r0, 0x30
  stbx      r0, r3, r4

.loc_0x60C:
  add       r26, r26, r25
  cmpwi     r26, -0x8000
  blt-      .loc_0x620
  cmpwi     r26, 0x7FFF
  ble-      .loc_0x628

.loc_0x620:
  li        r0, 0x1
  stw       r0, 0x0(r22)

.loc_0x628:
  lwz       r0, 0x0(r22)
  cmpwi     r0, 0
  beq-      .loc_0x668
  cmpwi     r19, 0
  beq-      .loc_0x644
  lfd       f1, -0x3BD8(r2)
  b         .loc_0x6D0

.loc_0x644:
  cmpwi     r18, 0
  beq-      .loc_0x65C
  lis       r3, 0x802F
  lfd       f0, -0x6B70(r3)
  fneg      f1, f0
  b         .loc_0x6D0

.loc_0x65C:
  lis       r3, 0x802F
  lfd       f1, -0x6B70(r3)
  b         .loc_0x6D0

.loc_0x668:
  extsh     r0, r26
  sth       r0, 0x1E(r1)
  addi      r3, r1, 0x1C
  bl        -0x44E4
  lfd       f0, -0x3BE0(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x6A4
  lis       r3, 0x802F
  lfd       f0, -0x6B60(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x6A4
  li        r0, 0x1
  stw       r0, 0x0(r22)
  lfd       f1, -0x3BD8(r2)
  b         .loc_0x6C4

.loc_0x6A4:
  lis       r3, 0x802F
  lfd       f0, -0x6B58(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x6C4
  li        r0, 0x1
  stw       r0, 0x0(r22)
  lis       r3, 0x802F
  lfd       f1, -0x6B70(r3)

.loc_0x6C4:
  cmpwi     r18, 0
  beq-      .loc_0x6D0
  fneg      f1, f1

.loc_0x6D0:
  lmw       r17, 0x4C(r1)
  lwz       r0, 0x8C(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}
