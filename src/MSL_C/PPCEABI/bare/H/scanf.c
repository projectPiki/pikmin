

/*
 * --INFO--
 * Address:	80218094
 * Size:	0000BC
 */
void sscanf(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
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
  lis       r0, 0x200
  cmplwi    r3, 0
  stw       r4, 0xC(r1)
  stw       r5, 0x10(r1)
  addi      r5, r1, 0x90
  stw       r6, 0x14(r1)
  addi      r6, r1, 0x78
  stw       r7, 0x18(r1)
  stw       r8, 0x1C(r1)
  stw       r9, 0x20(r1)
  stw       r10, 0x24(r1)
  stw       r0, 0x78(r1)
  addi      r0, r1, 0x8
  stw       r5, 0x7C(r1)
  stw       r0, 0x80(r1)
  stw       r3, 0x70(r1)
  beq-      .loc_0x88
  lwz       r3, 0x70(r1)
  lbz       r0, 0x0(r3)
  extsb.    r0, r0
  bne-      .loc_0x90

.loc_0x88:
  li        r3, -0x1
  b         .loc_0xAC

.loc_0x90:
  li        r0, 0
  lis       r3, 0x8022
  stw       r0, 0x74(r1)
  addi      r5, r4, 0
  subi      r3, r3, 0x7EB0
  addi      r4, r1, 0x70
  bl        0xA4

.loc_0xAC:
  lwz       r0, 0x8C(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void __vsscanf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void scanf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void fscanf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80218150
 * Size:	000090
 */
void __StringRead(void)
{
/*
.loc_0x0:
  cmpwi     r5, 0x1
  beq-      .loc_0x54
  bge-      .loc_0x18
  cmpwi     r5, 0
  bge-      .loc_0x24
  b         .loc_0x88

.loc_0x18:
  cmpwi     r5, 0x3
  bge-      .loc_0x88
  b         .loc_0x80

.loc_0x24:
  lwz       r4, 0x0(r3)
  lbz       r5, 0x0(r4)
  extsb.    r0, r5
  bne-      .loc_0x44
  li        r0, 0x1
  stw       r0, 0x4(r3)
  li        r3, -0x1
  blr       

.loc_0x44:
  addi      r0, r4, 0x1
  stw       r0, 0x0(r3)
  extsb     r3, r5
  blr       

.loc_0x54:
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  bne-      .loc_0x70
  lwz       r5, 0x0(r3)
  subi      r0, r5, 0x1
  stw       r0, 0x0(r3)
  b         .loc_0x78

.loc_0x70:
  li        r0, 0
  stw       r0, 0x4(r3)

.loc_0x78:
  mr        r3, r4
  blr       

.loc_0x80:
  lwz       r3, 0x4(r3)
  blr       

.loc_0x88:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void (int, long, ..., ... &, double)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802181E0
 * Size:	0009A4
 */
void __sformatter(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x8022
  stw       r0, 0x4(r1)
  stwu      r1, -0x98(r1)
  stmw      r16, 0x58(r1)
  addi      r30, r3, 0
  addi      r31, r4, 0
  addi      r16, r6, 0
  addi      r25, r5, 0
  addi      r29, r1, 0x1C
  addi      r28, r7, 0x2808
  li        r27, 0
  li        r22, 0
  li        r26, 0
  b         .loc_0x950

.loc_0x3C:
  add       r3, r28, r23
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,29,30
  beq-      .loc_0xBC

.loc_0x4C:
  lbzu      r0, 0x1(r25)
  add       r3, r28, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,29,30
  bne+      .loc_0x4C
  b         .loc_0x68

.loc_0x64:
  addi      r27, r27, 0x1

.loc_0x68:
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  blrl      
  extsb     r3, r3
  rlwinm    r0,r3,0,24,31
  stb       r3, 0x44(r1)
  add       r3, r28, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,29,30
  bne+      .loc_0x64
  mr        r12, r30
  lbz       r4, 0x44(r1)
  mtlr      r12
  addi      r3, r31, 0
  extsb     r4, r4
  li        r5, 0x1
  blrl      
  b         .loc_0x950

.loc_0xBC:
  extsb     r0, r23
  cmpwi     r0, 0x25
  beq-      .loc_0x11C
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  blrl      
  extsb     r0, r3
  cmpw      r23, r0
  stb       r0, 0x44(r1)
  beq-      .loc_0x110
  mr        r12, r30
  lbz       r4, 0x44(r1)
  mtlr      r12
  addi      r3, r31, 0
  extsb     r4, r4
  li        r5, 0x1
  blrl      
  b         .loc_0x95C

.loc_0x110:
  addi      r27, r27, 0x1
  addi      r25, r25, 0x1
  b         .loc_0x950

.loc_0x11C:
  addi      r3, r25, 0
  addi      r4, r1, 0x1C
  bl        .loc_0x9A4
  lbz       r0, 0x1C(r1)
  addi      r25, r3, 0
  cmplwi    r0, 0
  bne-      .loc_0x158
  lbz       r0, 0x1F(r1)
  cmplwi    r0, 0x25
  beq-      .loc_0x158
  addi      r3, r16, 0
  li        r4, 0x1
  bl        -0x3ABC
  lwz       r23, 0x0(r3)
  b         .loc_0x15C

.loc_0x158:
  li        r23, 0

.loc_0x15C:
  lbz       r0, 0x1F(r1)
  cmplwi    r0, 0x6E
  beq-      .loc_0x188
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0x2
  blrl      
  cmpwi     r3, 0
  bne-      .loc_0x95C

.loc_0x188:
  lbz       r0, 0x1F(r1)
  cmpwi     r0, 0x64
  beq-      .loc_0x24C
  bge-      .loc_0x1EC
  cmpwi     r0, 0x58
  beq-      .loc_0x390
  bge-      .loc_0x1C8
  cmpwi     r0, 0x45
  beq-      .loc_0x48C
  bge-      .loc_0x1BC
  cmpwi     r0, 0x25
  beq-      .loc_0x630
  b         .loc_0x95C

.loc_0x1BC:
  cmpwi     r0, 0x47
  beq-      .loc_0x48C
  b         .loc_0x95C

.loc_0x1C8:
  cmpwi     r0, 0x61
  beq-      .loc_0x48C
  bge-      .loc_0x1E0
  cmpwi     r0, 0x5B
  beq-      .loc_0x708
  b         .loc_0x95C

.loc_0x1E0:
  cmpwi     r0, 0x63
  bge-      .loc_0x508
  b         .loc_0x95C

.loc_0x1EC:
  cmpwi     r0, 0x73
  beq-      .loc_0x694
  bge-      .loc_0x228
  cmpwi     r0, 0x6E
  beq-      .loc_0x8E4
  bge-      .loc_0x21C
  cmpwi     r0, 0x69
  beq-      .loc_0x254
  bge-      .loc_0x95C
  cmpwi     r0, 0x68
  bge-      .loc_0x95C
  b         .loc_0x48C

.loc_0x21C:
  cmpwi     r0, 0x70
  bge-      .loc_0x95C
  b         .loc_0x380

.loc_0x228:
  cmpwi     r0, 0x78
  beq-      .loc_0x390
  bge-      .loc_0x240
  cmpwi     r0, 0x75
  beq-      .loc_0x388
  b         .loc_0x95C

.loc_0x240:
  cmpwi     r0, 0xFF
  beq-      .loc_0x95C
  b         .loc_0x95C

.loc_0x24C:
  li        r3, 0xA
  b         .loc_0x258

.loc_0x254:
  li        r3, 0

.loc_0x258:
  lbz       r0, 0x1E(r1)
  cmplwi    r0, 0x4
  bne-      .loc_0x28C
  lwz       r4, 0x20(r1)
  addi      r5, r30, 0
  addi      r6, r31, 0
  addi      r7, r1, 0x50
  addi      r8, r1, 0x4C
  addi      r9, r1, 0x48
  bl        0x19A0
  addi      r20, r4, 0
  addi      r21, r3, 0
  b         .loc_0x2AC

.loc_0x28C:
  lwz       r4, 0x20(r1)
  addi      r5, r30, 0
  addi      r6, r31, 0
  addi      r7, r1, 0x50
  addi      r8, r1, 0x4C
  addi      r9, r1, 0x48
  bl        0x1D44
  mr        r24, r3

.loc_0x2AC:
  lwz       r0, 0x50(r1)
  cmpwi     r0, 0
  beq-      .loc_0x95C
  lbz       r4, 0x1E(r1)
  add       r27, r27, r0
  cmplwi    r4, 0x4
  bne-      .loc_0x2F4
  lwz       r0, 0x4C(r1)
  cmpwi     r0, 0
  beq-      .loc_0x2E0
  subfic    r3, r20, 0
  subfze    r0, r21
  b         .loc_0x2E8

.loc_0x2E0:
  addi      r3, r20, 0
  addi      r0, r21, 0

.loc_0x2E8:
  addi      r18, r3, 0
  mr        r17, r0
  b         .loc_0x310

.loc_0x2F4:
  lwz       r0, 0x4C(r1)
  cmpwi     r0, 0
  beq-      .loc_0x308
  neg       r0, r24
  b         .loc_0x30C

.loc_0x308:
  mr        r0, r24

.loc_0x30C:
  mr        r19, r0

.loc_0x310:
  cmplwi    r23, 0
  beq-      .loc_0x378
  cmpwi     r4, 0x2
  beq-      .loc_0x358
  bge-      .loc_0x334
  cmpwi     r4, 0
  beq-      .loc_0x344
  bge-      .loc_0x34C
  b         .loc_0x374

.loc_0x334:
  cmpwi     r4, 0x4
  beq-      .loc_0x36C
  bge-      .loc_0x374
  b         .loc_0x364

.loc_0x344:
  stw       r19, 0x0(r23)
  b         .loc_0x374

.loc_0x34C:
  extsb     r0, r19
  stb       r0, 0x0(r23)
  b         .loc_0x374

.loc_0x358:
  extsh     r0, r19
  sth       r0, 0x0(r23)
  b         .loc_0x374

.loc_0x364:
  stw       r19, 0x0(r23)
  b         .loc_0x374

.loc_0x36C:
  stw       r18, 0x4(r23)
  stw       r17, 0x0(r23)

.loc_0x374:
  addi      r22, r22, 0x1

.loc_0x378:
  addi      r26, r26, 0x1
  b         .loc_0x950

.loc_0x380:
  li        r3, 0x8
  b         .loc_0x394

.loc_0x388:
  li        r3, 0xA
  b         .loc_0x394

.loc_0x390:
  li        r3, 0x10

.loc_0x394:
  lbz       r0, 0x1E(r1)
  cmplwi    r0, 0x4
  bne-      .loc_0x3C8
  lwz       r4, 0x20(r1)
  addi      r5, r30, 0
  addi      r6, r31, 0
  addi      r7, r1, 0x50
  addi      r8, r1, 0x4C
  addi      r9, r1, 0x48
  bl        0x1864
  addi      r20, r4, 0
  addi      r21, r3, 0
  b         .loc_0x3E8

.loc_0x3C8:
  lwz       r4, 0x20(r1)
  addi      r5, r30, 0
  addi      r6, r31, 0
  addi      r7, r1, 0x50
  addi      r8, r1, 0x4C
  addi      r9, r1, 0x48
  bl        0x1C08
  mr        r24, r3

.loc_0x3E8:
  lwz       r3, 0x50(r1)
  cmpwi     r3, 0
  beq-      .loc_0x95C
  lwz       r0, 0x4C(r1)
  add       r27, r27, r3
  cmpwi     r0, 0
  beq-      .loc_0x420
  lbz       r0, 0x1E(r1)
  cmplwi    r0, 0x4
  bne-      .loc_0x41C
  subfic    r20, r20, 0
  subfze    r21, r21
  b         .loc_0x420

.loc_0x41C:
  neg       r24, r24

.loc_0x420:
  cmplwi    r23, 0
  beq-      .loc_0x484
  lbz       r0, 0x1E(r1)
  cmpwi     r0, 0x2
  beq-      .loc_0x468
  bge-      .loc_0x448
  cmpwi     r0, 0
  beq-      .loc_0x458
  bge-      .loc_0x460
  b         .loc_0x480

.loc_0x448:
  cmpwi     r0, 0x4
  beq-      .loc_0x478
  bge-      .loc_0x480
  b         .loc_0x470

.loc_0x458:
  stw       r24, 0x0(r23)
  b         .loc_0x480

.loc_0x460:
  stb       r24, 0x0(r23)
  b         .loc_0x480

.loc_0x468:
  sth       r24, 0x0(r23)
  b         .loc_0x480

.loc_0x470:
  stw       r24, 0x0(r23)
  b         .loc_0x480

.loc_0x478:
  stw       r20, 0x4(r23)
  stw       r21, 0x0(r23)

.loc_0x480:
  addi      r22, r22, 0x1

.loc_0x484:
  addi      r26, r26, 0x1
  b         .loc_0x950

.loc_0x48C:
  lwz       r3, 0x20(r1)
  addi      r4, r30, 0
  addi      r5, r31, 0
  addi      r6, r1, 0x50
  addi      r7, r1, 0x48
  bl        0xE38
  lwz       r0, 0x50(r1)
  cmpwi     r0, 0
  beq-      .loc_0x95C
  cmplwi    r23, 0
  add       r27, r27, r0
  beq-      .loc_0x500
  lbz       r0, 0x1E(r1)
  cmpwi     r0, 0x5
  beq-      .loc_0x4F0
  bge-      .loc_0x4D8
  cmpwi     r0, 0
  beq-      .loc_0x4E4
  b         .loc_0x4FC

.loc_0x4D8:
  cmpwi     r0, 0x7
  bge-      .loc_0x4FC
  b         .loc_0x4F8

.loc_0x4E4:
  frsp      f0, f1
  stfs      f0, 0x0(r23)
  b         .loc_0x4FC

.loc_0x4F0:
  stfd      f1, 0x0(r23)
  b         .loc_0x4FC

.loc_0x4F8:
  stfd      f1, 0x0(r23)

.loc_0x4FC:
  addi      r22, r22, 0x1

.loc_0x500:
  addi      r26, r26, 0x1
  b         .loc_0x950

.loc_0x508:
  lbz       r0, 0x1D(r1)
  cmplwi    r0, 0
  bne-      .loc_0x51C
  li        r0, 0x1
  stw       r0, 0x20(r1)

.loc_0x51C:
  cmplwi    r23, 0
  beq-      .loc_0x5C0
  li        r0, 0
  stw       r0, 0x50(r1)
  b         .loc_0x56C

.loc_0x530:
  lbz       r0, 0x1E(r1)
  cmplwi    r0, 0x7
  bne-      .loc_0x554
  addi      r3, r23, 0
  addi      r4, r1, 0x44
  li        r5, 0x1
  bl        -0x260C
  addi      r23, r23, 0x1
  b         .loc_0x560

.loc_0x554:
  lbz       r0, 0x44(r1)
  stb       r0, 0x0(r23)
  addi      r23, r23, 0x1

.loc_0x560:
  lwz       r3, 0x50(r1)
  addi      r0, r3, 0x1
  stw       r0, 0x50(r1)

.loc_0x56C:
  lwz       r3, 0x20(r1)
  subi      r0, r3, 0x1
  cmpwi     r3, 0
  stw       r0, 0x20(r1)
  beq-      .loc_0x5A8
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  blrl      
  extsb     r0, r3
  cmpwi     r0, -0x1
  stb       r0, 0x44(r1)
  bne+      .loc_0x530

.loc_0x5A8:
  lwz       r0, 0x50(r1)
  cmpwi     r0, 0
  beq-      .loc_0x95C
  add       r27, r27, r0
  addi      r22, r22, 0x1
  b         .loc_0x620

.loc_0x5C0:
  li        r0, 0
  stw       r0, 0x50(r1)
  b         .loc_0x5D8

.loc_0x5CC:
  lwz       r3, 0x50(r1)
  addi      r0, r3, 0x1
  stw       r0, 0x50(r1)

.loc_0x5D8:
  lwz       r3, 0x20(r1)
  subi      r0, r3, 0x1
  cmpwi     r3, 0
  stw       r0, 0x20(r1)
  beq-      .loc_0x614
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  blrl      
  extsb     r0, r3
  cmpwi     r0, -0x1
  stb       r0, 0x44(r1)
  bne+      .loc_0x5CC

.loc_0x614:
  lwz       r0, 0x50(r1)
  cmpwi     r0, 0
  beq-      .loc_0x95C

.loc_0x620:
  addi      r26, r26, 0x1
  b         .loc_0x950
  b         .loc_0x630

.loc_0x62C:
  addi      r27, r27, 0x1

.loc_0x630:
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  blrl      
  extsb     r3, r3
  rlwinm    r0,r3,0,24,31
  stb       r3, 0x44(r1)
  add       r3, r28, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,29,30
  bne+      .loc_0x62C
  lbz       r0, 0x44(r1)
  extsb     r4, r0
  cmpwi     r4, 0x25
  beq-      .loc_0x68C
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r5, 0x1
  blrl      
  b         .loc_0x95C

.loc_0x68C:
  addi      r27, r27, 0x1
  b         .loc_0x950

.loc_0x694:
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  blrl      
  extsb     r0, r3
  stb       r0, 0x44(r1)
  b         .loc_0x6DC

.loc_0x6B8:
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  addi      r27, r27, 0x1
  blrl      
  extsb     r0, r3
  stb       r0, 0x44(r1)

.loc_0x6DC:
  lbz       r4, 0x44(r1)
  add       r3, r28, r4
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,29,30
  bne+      .loc_0x6B8
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  extsb     r4, r4
  li        r5, 0x1
  blrl      

.loc_0x708:
  cmplwi    r23, 0
  beq-      .loc_0x80C
  li        r0, 0
  stw       r0, 0x50(r1)
  b         .loc_0x754

.loc_0x71C:
  lbz       r0, 0x1E(r1)
  cmplwi    r0, 0x7
  bne-      .loc_0x740
  addi      r3, r23, 0
  addi      r4, r1, 0x44
  li        r5, 0x1
  bl        -0x27F8
  addi      r23, r23, 0x2
  b         .loc_0x748

.loc_0x740:
  stb       r5, 0x0(r23)
  addi      r23, r23, 0x1

.loc_0x748:
  lwz       r3, 0x50(r1)
  addi      r0, r3, 0x1
  stw       r0, 0x50(r1)

.loc_0x754:
  lwz       r3, 0x20(r1)
  subi      r0, r3, 0x1
  cmpwi     r3, 0
  stw       r0, 0x20(r1)
  beq-      .loc_0x7B4
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  blrl      
  extsb     r0, r3
  cmpwi     r0, -0x1
  stb       r0, 0x44(r1)
  beq-      .loc_0x7B4
  lbz       r5, 0x44(r1)
  li        r3, 0x1
  srawi     r4, r5, 0x3
  addi      r4, r4, 0x8
  rlwinm    r0,r5,0,29,31
  lbzx      r4, r29, r4
  slw       r0, r3, r0
  and.      r0, r4, r0
  bne+      .loc_0x71C

.loc_0x7B4:
  lwz       r3, 0x50(r1)
  cmpwi     r3, 0
  bne-      .loc_0x7E0
  mr        r12, r30
  lbz       r4, 0x44(r1)
  mtlr      r12
  addi      r3, r31, 0
  extsb     r4, r4
  li        r5, 0x1
  blrl      
  b         .loc_0x95C

.loc_0x7E0:
  lbz       r0, 0x1E(r1)
  add       r27, r27, r3
  cmplwi    r0, 0x7
  bne-      .loc_0x7FC
  li        r0, 0
  sth       r0, 0x0(r23)
  b         .loc_0x804

.loc_0x7FC:
  li        r0, 0
  stb       r0, 0x0(r23)

.loc_0x804:
  addi      r22, r22, 0x1
  b         .loc_0x8B4

.loc_0x80C:
  li        r0, 0
  stw       r0, 0x50(r1)
  b         .loc_0x824

.loc_0x818:
  lwz       r3, 0x50(r1)
  addi      r0, r3, 0x1
  stw       r0, 0x50(r1)

.loc_0x824:
  lwz       r3, 0x20(r1)
  subi      r0, r3, 0x1
  cmpwi     r3, 0
  stw       r0, 0x20(r1)
  beq-      .loc_0x884
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  blrl      
  extsb     r0, r3
  cmpwi     r0, -0x1
  stb       r0, 0x44(r1)
  beq-      .loc_0x884
  lbz       r0, 0x44(r1)
  li        r3, 0x1
  srawi     r4, r0, 0x3
  addi      r4, r4, 0x8
  rlwinm    r0,r0,0,29,31
  lbzx      r4, r29, r4
  slw       r0, r3, r0
  and.      r0, r4, r0
  bne+      .loc_0x818

.loc_0x884:
  lwz       r0, 0x50(r1)
  cmpwi     r0, 0
  bne-      .loc_0x8B0
  mr        r12, r30
  lbz       r4, 0x44(r1)
  mtlr      r12
  addi      r3, r31, 0
  extsb     r4, r4
  li        r5, 0x1
  blrl      
  b         .loc_0x95C

.loc_0x8B0:
  add       r27, r27, r0

.loc_0x8B4:
  lwz       r0, 0x20(r1)
  cmpwi     r0, 0
  blt-      .loc_0x8DC
  mr        r12, r30
  lbz       r4, 0x44(r1)
  mtlr      r12
  addi      r3, r31, 0
  extsb     r4, r4
  li        r5, 0x1
  blrl      

.loc_0x8DC:
  addi      r26, r26, 0x1
  b         .loc_0x950

.loc_0x8E4:
  cmplwi    r23, 0
  beq-      .loc_0x950
  lbz       r0, 0x1E(r1)
  cmpwi     r0, 0x2
  beq-      .loc_0x924
  bge-      .loc_0x90C
  cmpwi     r0, 0
  beq-      .loc_0x91C
  bge-      .loc_0x938
  b         .loc_0x950

.loc_0x90C:
  cmpwi     r0, 0x4
  beq-      .loc_0x944
  bge-      .loc_0x950
  b         .loc_0x930

.loc_0x91C:
  stw       r27, 0x0(r23)
  b         .loc_0x950

.loc_0x924:
  extsh     r0, r27
  sth       r0, 0x0(r23)
  b         .loc_0x950

.loc_0x930:
  stw       r27, 0x0(r23)
  b         .loc_0x950

.loc_0x938:
  extsb     r0, r27
  stb       r0, 0x0(r23)
  b         .loc_0x950

.loc_0x944:
  stw       r27, 0x4(r23)
  srawi     r0, r27, 0x1F
  stw       r0, 0x0(r23)

.loc_0x950:
  lbz       r23, 0x0(r25)
  extsb.    r0, r23
  bne+      .loc_0x3C

.loc_0x95C:
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0x2
  blrl      
  cmpwi     r3, 0
  beq-      .loc_0x98C
  cmpwi     r26, 0
  bne-      .loc_0x98C
  li        r3, -0x1
  b         .loc_0x990

.loc_0x98C:
  mr        r3, r22

.loc_0x990:
  lmw       r16, 0x58(r1)
  lwz       r0, 0x9C(r1)
  addi      r1, r1, 0x98
  mtlr      r0
  blr       

.loc_0x9A4:
*/
}

/*
 * --INFO--
 * Address:	80218B84
 * Size:	000564
 */
void parse_format(void)
{
/*
.loc_0x0:
  lis       r5, 0x8022
  stwu      r1, -0x38(r1)
  addi      r6, r5, 0x2B20
  lwz       r5, 0x0(r6)
  lwz       r0, 0x4(r6)
  stw       r5, 0x10(r1)
  stw       r0, 0x14(r1)
  lwz       r5, 0x8(r6)
  lwz       r0, 0xC(r6)
  stw       r5, 0x18(r1)
  stw       r0, 0x1C(r1)
  lwz       r5, 0x10(r6)
  lwz       r0, 0x14(r6)
  stw       r5, 0x20(r1)
  stw       r0, 0x24(r1)
  lwz       r5, 0x18(r6)
  lwz       r0, 0x1C(r6)
  stw       r5, 0x28(r1)
  stw       r0, 0x2C(r1)
  lwz       r5, 0x20(r6)
  lwz       r0, 0x24(r6)
  stw       r5, 0x30(r1)
  stw       r0, 0x34(r1)
  lbzu      r7, 0x1(r3)
  extsb     r7, r7
  cmpwi     r7, 0x25
  bne-      .loc_0xC8
  stb       r7, 0x13(r1)
  addi      r3, r3, 0x1
  lwz       r5, 0x10(r1)
  lwz       r0, 0x14(r1)
  stw       r5, 0x0(r4)
  stw       r0, 0x4(r4)
  lwz       r5, 0x18(r1)
  lwz       r0, 0x1C(r1)
  stw       r5, 0x8(r4)
  stw       r0, 0xC(r4)
  lwz       r5, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r5, 0x10(r4)
  stw       r0, 0x14(r4)
  lwz       r5, 0x28(r1)
  lwz       r0, 0x2C(r1)
  stw       r5, 0x18(r4)
  stw       r0, 0x1C(r4)
  lwz       r5, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r5, 0x20(r4)
  stw       r0, 0x24(r4)
  b         .loc_0x55C

.loc_0xC8:
  cmpwi     r7, 0x2A
  bne-      .loc_0xE0
  li        r0, 0x1
  stb       r0, 0x10(r1)
  lbzu      r7, 0x1(r3)
  extsb     r7, r7

.loc_0xE0:
  lis       r5, 0x8022
  rlwinm    r0,r7,0,24,31
  addi      r6, r5, 0x2808
  add       r5, r6, r0
  lbz       r0, 0x0(r5)
  rlwinm.   r0,r0,0,27,27
  beq-      .loc_0x1A8
  li        r0, 0
  stw       r0, 0x14(r1)

.loc_0x104:
  lwz       r0, 0x14(r1)
  mulli     r0, r0, 0xA
  add       r5, r7, r0
  subi      r0, r5, 0x30
  stw       r0, 0x14(r1)
  lbzu      r7, 0x1(r3)
  extsb     r7, r7
  rlwinm    r0,r7,0,24,31
  add       r5, r6, r0
  lbz       r0, 0x0(r5)
  rlwinm.   r0,r0,0,27,27
  bne+      .loc_0x104
  lwz       r0, 0x14(r1)
  cmpwi     r0, 0
  bne-      .loc_0x1A0
  li        r0, 0xFF
  stb       r0, 0x13(r1)
  addi      r3, r3, 0x1
  lwz       r5, 0x10(r1)
  lwz       r0, 0x14(r1)
  stw       r5, 0x0(r4)
  stw       r0, 0x4(r4)
  lwz       r5, 0x18(r1)
  lwz       r0, 0x1C(r1)
  stw       r5, 0x8(r4)
  stw       r0, 0xC(r4)
  lwz       r5, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r5, 0x10(r4)
  stw       r0, 0x14(r4)
  lwz       r5, 0x28(r1)
  lwz       r0, 0x2C(r1)
  stw       r5, 0x18(r4)
  stw       r0, 0x1C(r4)
  lwz       r5, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r5, 0x20(r4)
  stw       r0, 0x24(r4)
  b         .loc_0x55C

.loc_0x1A0:
  li        r0, 0x1
  stb       r0, 0x11(r1)

.loc_0x1A8:
  cmpwi     r7, 0x68
  li        r5, 0x1
  beq-      .loc_0x1D0
  bge-      .loc_0x1C4
  cmpwi     r7, 0x4C
  beq-      .loc_0x220
  b         .loc_0x22C

.loc_0x1C4:
  cmpwi     r7, 0x6C
  beq-      .loc_0x1F8
  b         .loc_0x22C

.loc_0x1D0:
  li        r0, 0x2
  stb       r0, 0x12(r1)
  lbz       r0, 0x1(r3)
  cmpwi     r0, 0x68
  bne-      .loc_0x230
  li        r0, 0x1
  stb       r0, 0x12(r1)
  lbzu      r7, 0x1(r3)
  extsb     r7, r7
  b         .loc_0x230

.loc_0x1F8:
  li        r0, 0x3
  stb       r0, 0x12(r1)
  lbz       r0, 0x1(r3)
  cmpwi     r0, 0x6C
  bne-      .loc_0x230
  li        r0, 0x4
  stb       r0, 0x12(r1)
  lbzu      r7, 0x1(r3)
  extsb     r7, r7
  b         .loc_0x230

.loc_0x220:
  li        r0, 0x6
  stb       r0, 0x12(r1)
  b         .loc_0x230

.loc_0x22C:
  li        r5, 0

.loc_0x230:
  cmpwi     r5, 0
  beq-      .loc_0x240
  lbzu      r7, 0x1(r3)
  extsb     r7, r7

.loc_0x240:
  subi      r0, r7, 0x45
  stb       r7, 0x13(r1)
  cmplwi    r0, 0x33
  bgt-      .loc_0x500
  lis       r5, 0x802F
  subi      r5, r5, 0x6CE0
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r5, r0
  mtctr     r0
  bctr      
  lbz       r0, 0x12(r1)
  cmplwi    r0, 0x6
  bne-      .loc_0x508
  li        r0, 0xFF
  stb       r0, 0x13(r1)
  b         .loc_0x508
  lbz       r0, 0x12(r1)
  cmplwi    r0, 0x1
  beq-      .loc_0x29C
  cmplwi    r0, 0x2
  beq-      .loc_0x29C
  cmplwi    r0, 0x4
  bne-      .loc_0x2A8

.loc_0x29C:
  li        r0, 0xFF
  stb       r0, 0x13(r1)
  b         .loc_0x508

.loc_0x2A8:
  cmplwi    r0, 0x3
  bne-      .loc_0x508
  li        r0, 0x5
  stb       r0, 0x12(r1)
  b         .loc_0x508
  li        r0, 0x3
  stb       r0, 0x12(r1)
  li        r0, 0x78
  stb       r0, 0x13(r1)
  b         .loc_0x508
  lbz       r0, 0x12(r1)
  cmplwi    r0, 0x3
  bne-      .loc_0x2E8
  li        r0, 0x7
  stb       r0, 0x12(r1)
  b         .loc_0x508

.loc_0x2E8:
  cmplwi    r0, 0
  beq-      .loc_0x508
  li        r0, 0xFF
  stb       r0, 0x13(r1)
  b         .loc_0x508
  lbz       r0, 0x12(r1)
  cmplwi    r0, 0x3
  bne-      .loc_0x314
  li        r0, 0x7
  stb       r0, 0x12(r1)
  b         .loc_0x324

.loc_0x314:
  cmplwi    r0, 0
  beq-      .loc_0x324
  li        r0, 0xFF
  stb       r0, 0x13(r1)

.loc_0x324:
  li        r0, 0x4
  mtctr     r0
  addi      r5, r1, 0x18
  li        r0, 0xFF

.loc_0x334:
  stb       r0, 0x0(r5)
  stb       r0, 0x1(r5)
  stb       r0, 0x2(r5)
  stb       r0, 0x3(r5)
  stb       r0, 0x4(r5)
  stb       r0, 0x5(r5)
  stb       r0, 0x6(r5)
  stb       r0, 0x7(r5)
  addi      r5, r5, 0x8
  bdnz+     .loc_0x334
  li        r0, 0xC1
  stb       r0, 0x19(r1)
  li        r0, 0xFE
  stb       r0, 0x1C(r1)
  b         .loc_0x508
  lbz       r0, 0x12(r1)
  cmplwi    r0, 0x3
  bne-      .loc_0x388
  li        r0, 0x7
  stb       r0, 0x12(r1)
  b         .loc_0x398

.loc_0x388:
  cmplwi    r0, 0
  beq-      .loc_0x398
  li        r0, 0xFF
  stb       r0, 0x13(r1)

.loc_0x398:
  lbzu      r9, 0x1(r3)
  li        r10, 0
  extsb     r9, r9
  cmpwi     r9, 0x5E
  bne-      .loc_0x3B8
  lbzu      r9, 0x1(r3)
  li        r10, 0x1
  extsb     r9, r9

.loc_0x3B8:
  cmpwi     r9, 0x5D
  bne-      .loc_0x3D4
  lbz       r0, 0x23(r1)
  ori       r0, r0, 0x20
  stb       r0, 0x23(r1)
  lbzu      r9, 0x1(r3)
  extsb     r9, r9

.loc_0x3D4:
  addi      r7, r1, 0x10
  b         .loc_0x45C

.loc_0x3DC:
  rlwinm    r5,r9,29,27,31
  addi      r6, r5, 0x8
  rlwinm    r0,r9,0,29,31
  lbzx      r5, r7, r6
  li        r8, 0x1
  slw       r0, r8, r0
  or        r0, r5, r0
  stbx      r0, r7, r6
  lbz       r0, 0x1(r3)
  cmpwi     r0, 0x2D
  bne-      .loc_0x454
  lbz       r11, 0x2(r3)
  extsb.    r11, r11
  beq-      .loc_0x454
  cmpwi     r11, 0x5D
  beq-      .loc_0x454
  b         .loc_0x43C

.loc_0x420:
  rlwinm    r5,r9,29,27,31
  addi      r6, r5, 0x8
  rlwinm    r0,r9,0,29,31
  lbzx      r5, r7, r6
  slw       r0, r8, r0
  or        r0, r5, r0
  stbx      r0, r7, r6

.loc_0x43C:
  addi      r9, r9, 0x1
  cmpw      r9, r11
  ble+      .loc_0x420
  lbzu      r9, 0x3(r3)
  extsb     r9, r9
  b         .loc_0x45C

.loc_0x454:
  lbzu      r9, 0x1(r3)
  extsb     r9, r9

.loc_0x45C:
  cmpwi     r9, 0
  beq-      .loc_0x46C
  cmpwi     r9, 0x5D
  bne+      .loc_0x3DC

.loc_0x46C:
  cmpwi     r9, 0
  bne-      .loc_0x480
  li        r0, 0xFF
  stb       r0, 0x13(r1)
  b         .loc_0x508

.loc_0x480:
  cmpwi     r10, 0
  beq-      .loc_0x508
  li        r0, 0x4
  mtctr     r0
  addi      r5, r1, 0x18

.loc_0x494:
  lbz       r0, 0x0(r5)
  not       r0, r0
  stb       r0, 0x0(r5)
  lbz       r0, 0x1(r5)
  not       r0, r0
  stb       r0, 0x1(r5)
  lbz       r0, 0x2(r5)
  not       r0, r0
  stb       r0, 0x2(r5)
  lbz       r0, 0x3(r5)
  not       r0, r0
  stb       r0, 0x3(r5)
  lbz       r0, 0x4(r5)
  not       r0, r0
  stb       r0, 0x4(r5)
  lbz       r0, 0x5(r5)
  not       r0, r0
  stb       r0, 0x5(r5)
  lbz       r0, 0x6(r5)
  not       r0, r0
  stb       r0, 0x6(r5)
  lbz       r0, 0x7(r5)
  not       r0, r0
  stb       r0, 0x7(r5)
  addi      r5, r5, 0x8
  bdnz+     .loc_0x494
  b         .loc_0x508

.loc_0x500:
  li        r0, 0xFF
  stb       r0, 0x13(r1)

.loc_0x508:
  lwz       r5, 0x10(r1)
  addi      r3, r3, 0x1
  lwz       r0, 0x14(r1)
  stw       r5, 0x0(r4)
  stw       r0, 0x4(r4)
  lwz       r5, 0x18(r1)
  lwz       r0, 0x1C(r1)
  stw       r5, 0x8(r4)
  stw       r0, 0xC(r4)
  lwz       r5, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r5, 0x10(r4)
  stw       r0, 0x14(r4)
  lwz       r5, 0x28(r1)
  lwz       r0, 0x2C(r1)
  stw       r5, 0x18(r4)
  stw       r0, 0x1C(r4)
  lwz       r5, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r5, 0x20(r4)
  stw       r0, 0x24(r4)

.loc_0x55C:
  addi      r1, r1, 0x38
  blr
*/
}