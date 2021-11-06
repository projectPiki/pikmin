

/*
 * --INFO--
 * Address:	80216598
 * Size:	0000D4
 */
void sprintf(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x90(r1)
  stw       r31, 0x8C(r1)
  stw       r30, 0x88(r1)
  bne-      cr1, .loc_0x38
  stfd      f1, 0x28(r1)
  stfd      f2, 0x30(r1)
  stfd      f3, 0x38(r1)
  stfd      f4, 0x40(r1)
  stfd      f5, 0x48(r1)
  stfd      f6, 0x50(r1)
  stfd      f7, 0x58(r1)
  stfd      f8, 0x60(r1)

.loc_0x38:
  stw       r3, 0x8(r1)
  lis       r0, 0x200
  addi      r30, r3, 0
  stw       r4, 0xC(r1)
  li        r31, -0x1
  stw       r5, 0x10(r1)
  lis       r5, 0x8021
  addi      r3, r5, 0x682C
  stw       r6, 0x14(r1)
  addi      r5, r4, 0
  addi      r6, r1, 0x7C
  stw       r7, 0x18(r1)
  addi      r4, r1, 0x70
  stw       r8, 0x1C(r1)
  stw       r9, 0x20(r1)
  stw       r10, 0x24(r1)
  stw       r0, 0x7C(r1)
  addi      r0, r1, 0x98
  stw       r0, 0x80(r1)
  addi      r0, r1, 0x8
  stw       r0, 0x84(r1)
  li        r0, 0
  stw       r30, 0x70(r1)
  stw       r31, 0x74(r1)
  stw       r0, 0x78(r1)
  bl        0x2BC
  cmplw     r3, r31
  bge-      .loc_0xB0
  mr        r4, r3
  b         .loc_0xB4

.loc_0xB0:
  li        r4, -0x2

.loc_0xB4:
  li        r0, 0
  stbx      r0, r30, r4
  lwz       r0, 0x94(r1)
  lwz       r31, 0x8C(r1)
  lwz       r30, 0x88(r1)
  mtlr      r0
  addi      r1, r1, 0x90
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void snprintf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021666C
 * Size:	000078
 */
void vsprintf(void)
{
/*
.loc_0x0:
  mflr      r0
  addi      r6, r5, 0
  stw       r0, 0x4(r1)
  li        r0, 0
  addi      r5, r4, 0
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, -0x1
  addi      r4, r1, 0x14
  stw       r30, 0x20(r1)
  mr        r30, r3
  lis       r3, 0x8021
  stw       r30, 0x14(r1)
  addi      r3, r3, 0x682C
  stw       r31, 0x18(r1)
  stw       r0, 0x1C(r1)
  bl        0x244
  cmplw     r3, r31
  bge-      .loc_0x54
  mr        r4, r3
  b         .loc_0x58

.loc_0x54:
  li        r4, -0x2

.loc_0x58:
  li        r0, 0
  stbx      r0, r30, r4
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void vsnprintf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void vfprintf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802166E4
 * Size:	00007C
 */
void vprintf(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x802F
  stw       r0, 0x4(r1)
  subi      r5, r5, 0x7008
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r5, 0x48
  stw       r30, 0x18(r1)
  addi      r30, r4, 0
  li        r4, -0x1
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  addi      r3, r31, 0
  bl        0x3F78
  cmpwi     r3, 0
  blt-      .loc_0x48
  li        r3, -0x1
  b         .loc_0x60

.loc_0x48:
  lis       r3, 0x8021
  addi      r3, r3, 0x6898
  addi      r4, r31, 0
  addi      r5, r29, 0
  addi      r6, r30, 0
  bl        0x1B0

.loc_0x60:
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
 * Size:	0000C0
 */
void fprintf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80216760
 * Size:	0000CC
 */
void printf(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stw       r31, 0x7C(r1)
  stw       r30, 0x78(r1)
  bne-      cr1, .loc_0x38
  stfd      f1, 0x28(r1)
  stfd      f2, 0x30(r1)
  stfd      f3, 0x38(r1)
  stfd      f4, 0x40(r1)
  stfd      f5, 0x48(r1)
  stfd      f6, 0x50(r1)
  stfd      f7, 0x58(r1)
  stfd      f8, 0x60(r1)

.loc_0x38:
  stw       r3, 0x8(r1)
  addi      r30, r3, 0
  stw       r4, 0xC(r1)
  lis       r4, 0x802F
  subi      r4, r4, 0x7008
  stw       r5, 0x10(r1)
  addi      r31, r4, 0x48
  addi      r3, r31, 0
  stw       r6, 0x14(r1)
  li        r4, -0x1
  stw       r7, 0x18(r1)
  stw       r8, 0x1C(r1)
  stw       r9, 0x20(r1)
  stw       r10, 0x24(r1)
  bl        0x3EC0
  cmpwi     r3, 0
  blt-      .loc_0x84
  li        r3, -0x1
  b         .loc_0xB4

.loc_0x84:
  lis       r0, 0x100
  stw       r0, 0x6C(r1)
  addi      r0, r1, 0x88
  lis       r3, 0x8021
  stw       r0, 0x70(r1)
  addi      r0, r1, 0x8
  addi      r6, r1, 0x6C
  stw       r0, 0x74(r1)
  addi      r3, r3, 0x6898
  addi      r4, r31, 0
  addi      r5, r30, 0
  bl        0xE0

.loc_0xB4:
  lwz       r0, 0x84(r1)
  lwz       r31, 0x7C(r1)
  lwz       r30, 0x78(r1)
  mtlr      r0
  addi      r1, r1, 0x80
  blr
*/
}

/*
 * --INFO--
 * Address:	8021682C
 * Size:	00006C
 */
void __StringWrite(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r3
  lwz       r3, 0x8(r3)
  lwz       r6, 0x4(r30)
  add       r0, r3, r5
  cmplw     r0, r6
  bgt-      .loc_0x34
  mr        r31, r5
  b         .loc_0x38

.loc_0x34:
  sub       r31, r6, r3

.loc_0x38:
  lwz       r0, 0x0(r30)
  addi      r5, r31, 0
  add       r3, r0, r3
  bl        -0x21345C
  lwz       r0, 0x8(r30)
  add       r0, r0, r31
  stw       r0, 0x8(r30)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	802168F0
 * Size:	000630
 */
void __pformatter(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x8022
  stw       r0, 0x4(r1)
  li        r0, 0x20
  stwu      r1, -0x268(r1)
  stmw      r18, 0x230(r1)
  addi      r31, r3, 0
  addi      r30, r4, 0
  addi      r28, r6, 0
  addi      r25, r5, 0
  addi      r26, r1, 0x21C
  addi      r23, r1, 0x21B
  addi      r20, r7, 0x2B10
  li        r27, 0
  stb       r0, 0x19(r1)
  b         .loc_0x60C

.loc_0x40:
  addi      r3, r25, 0
  li        r4, 0x25
  bl        0x281C
  mr.       r24, r3
  bne-      .loc_0x8C
  mr        r3, r25
  bl        0x2AC4
  mr.       r5, r3
  add       r27, r27, r5
  beq-      .loc_0x618
  addi      r12, r31, 0
  mtlr      r12
  addi      r3, r30, 0
  addi      r4, r25, 0
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x618
  li        r3, -0x1
  b         .loc_0x61C

.loc_0x8C:
  sub.      r5, r24, r25
  add       r27, r27, r5
  beq-      .loc_0xBC
  addi      r12, r31, 0
  mtlr      r12
  addi      r3, r30, 0
  addi      r4, r25, 0
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0xBC
  li        r3, -0x1
  b         .loc_0x61C

.loc_0xBC:
  addi      r3, r24, 0
  addi      r4, r28, 0
  addi      r5, r1, 0x21C
  bl        0x11D8
  lbz       r0, 0x221(r1)
  addi      r25, r3, 0
  cmpwi     r0, 0x69
  beq-      .loc_0x17C
  bge-      .loc_0x134
  cmpwi     r0, 0x58
  beq-      .loc_0x238
  bge-      .loc_0x110
  cmpwi     r0, 0x45
  beq-      .loc_0x2F4
  bge-      .loc_0x104
  cmpwi     r0, 0x25
  beq-      .loc_0x478
  b         .loc_0x48C

.loc_0x104:
  cmpwi     r0, 0x47
  beq-      .loc_0x2F4
  b         .loc_0x48C

.loc_0x110:
  cmpwi     r0, 0x64
  beq-      .loc_0x17C
  bge-      .loc_0x128
  cmpwi     r0, 0x63
  bge-      .loc_0x454
  b         .loc_0x48C

.loc_0x128:
  cmpwi     r0, 0x68
  bge-      .loc_0x48C
  b         .loc_0x2F4

.loc_0x134:
  cmpwi     r0, 0x75
  beq-      .loc_0x238
  bge-      .loc_0x164
  cmpwi     r0, 0x6F
  beq-      .loc_0x238
  bge-      .loc_0x158
  cmpwi     r0, 0x6E
  bge-      .loc_0x3EC
  b         .loc_0x48C

.loc_0x158:
  cmpwi     r0, 0x73
  beq-      .loc_0x318
  b         .loc_0x48C

.loc_0x164:
  cmpwi     r0, 0xFF
  beq-      .loc_0x48C
  bge-      .loc_0x48C
  cmpwi     r0, 0x78
  beq-      .loc_0x238
  b         .loc_0x48C

.loc_0x17C:
  lbz       r0, 0x220(r1)
  cmplwi    r0, 0x3
  bne-      .loc_0x19C
  addi      r3, r28, 0
  li        r4, 0x1
  bl        -0x2210
  lwz       r29, 0x0(r3)
  b         .loc_0x1CC

.loc_0x19C:
  cmplwi    r0, 0x4
  bne-      .loc_0x1BC
  addi      r3, r28, 0
  li        r4, 0x2
  bl        -0x222C
  lwz       r21, 0x0(r3)
  lwz       r22, 0x4(r3)
  b         .loc_0x1CC

.loc_0x1BC:
  addi      r3, r28, 0
  li        r4, 0x1
  bl        -0x2244
  lwz       r29, 0x0(r3)

.loc_0x1CC:
  lbz       r3, 0x220(r1)
  cmplwi    r3, 0x2
  bne-      .loc_0x1E0
  extsh     r0, r29
  mr        r29, r0

.loc_0x1E0:
  cmplwi    r3, 0x1
  bne-      .loc_0x1F0
  extsb     r0, r29
  mr        r29, r0

.loc_0x1F0:
  cmplwi    r3, 0x4
  bne-      .loc_0x218
  addi      r4, r22, 0
  addi      r3, r21, 0
  addi      r5, r26, 0
  addi      r6, r1, 0x21C
  bl        0xB94
  mr.       r19, r3
  beq-      .loc_0x48C
  b         .loc_0x230

.loc_0x218:
  addi      r3, r29, 0
  addi      r4, r26, 0
  addi      r5, r1, 0x21C
  bl        0xE58
  mr.       r19, r3
  beq-      .loc_0x48C

.loc_0x230:
  sub       r24, r23, r19
  b         .loc_0x4CC

.loc_0x238:
  lbz       r0, 0x220(r1)
  cmplwi    r0, 0x3
  bne-      .loc_0x258
  addi      r3, r28, 0
  li        r4, 0x1
  bl        -0x22CC
  lwz       r29, 0x0(r3)
  b         .loc_0x288

.loc_0x258:
  cmplwi    r0, 0x4
  bne-      .loc_0x278
  addi      r3, r28, 0
  li        r4, 0x2
  bl        -0x22E8
  lwz       r21, 0x0(r3)
  lwz       r22, 0x4(r3)
  b         .loc_0x288

.loc_0x278:
  addi      r3, r28, 0
  li        r4, 0x1
  bl        -0x2300
  lwz       r29, 0x0(r3)

.loc_0x288:
  lbz       r3, 0x220(r1)
  cmplwi    r3, 0x2
  bne-      .loc_0x29C
  rlwinm    r0,r29,0,16,31
  mr        r29, r0

.loc_0x29C:
  cmplwi    r3, 0x1
  bne-      .loc_0x2AC
  rlwinm    r0,r29,0,24,31
  mr        r29, r0

.loc_0x2AC:
  cmplwi    r3, 0x4
  bne-      .loc_0x2D4
  addi      r4, r22, 0
  addi      r3, r21, 0
  addi      r5, r26, 0
  addi      r6, r1, 0x21C
  bl        0xAD8
  mr.       r19, r3
  beq-      .loc_0x48C
  b         .loc_0x2EC

.loc_0x2D4:
  addi      r3, r29, 0
  addi      r4, r26, 0
  addi      r5, r1, 0x21C
  bl        0xD9C
  mr.       r19, r3
  beq-      .loc_0x48C

.loc_0x2EC:
  sub       r24, r23, r19
  b         .loc_0x4CC

.loc_0x2F4:
  addi      r3, r28, 0
  addi      r4, r26, 0
  addi      r5, r1, 0x21C
  li        r6, 0
  bl        .loc_0x630
  mr.       r19, r3
  beq-      .loc_0x48C
  sub       r24, r23, r19
  b         .loc_0x4CC

.loc_0x318:
  lbz       r0, 0x220(r1)
  cmplwi    r0, 0x6
  bne-      .loc_0x35C
  addi      r3, r28, 0
  li        r4, 0x1
  bl        -0x23AC
  lwz       r4, 0x0(r3)
  cmplwi    r4, 0
  bne-      .loc_0x340
  addi      r4, r13, 0x2AD0

.loc_0x340:
  addi      r3, r1, 0x1C
  li        r5, 0x200
  bl        -0xB58
  cmpwi     r3, 0
  blt-      .loc_0x48C
  addi      r19, r1, 0x1C
  b         .loc_0x36C

.loc_0x35C:
  addi      r3, r28, 0
  li        r4, 0x1
  bl        -0x23E4
  lwz       r19, 0x0(r3)

.loc_0x36C:
  cmplwi    r19, 0
  bne-      .loc_0x378
  mr        r19, r20

.loc_0x378:
  lbz       r0, 0x21F(r1)
  cmplwi    r0, 0
  beq-      .loc_0x3AC
  lbz       r0, 0x21E(r1)
  lbz       r24, 0x0(r19)
  addi      r19, r19, 0x1
  cmplwi    r0, 0
  beq-      .loc_0x4CC
  lwz       r0, 0x228(r1)
  cmpw      r24, r0
  ble-      .loc_0x4CC
  mr        r24, r0
  b         .loc_0x4CC

.loc_0x3AC:
  lbz       r0, 0x21E(r1)
  cmplwi    r0, 0
  beq-      .loc_0x3DC
  lwz       r24, 0x228(r1)
  addi      r3, r19, 0
  li        r4, 0
  addi      r5, r24, 0
  bl        -0xB08
  cmplwi    r3, 0
  beq-      .loc_0x4CC
  sub       r24, r3, r19
  b         .loc_0x4CC

.loc_0x3DC:
  mr        r3, r19
  bl        0x273C
  mr        r24, r3
  b         .loc_0x4CC

.loc_0x3EC:
  addi      r3, r28, 0
  li        r4, 0x1
  bl        -0x2474
  lbz       r0, 0x220(r1)
  lwz       r3, 0x0(r3)
  cmpwi     r0, 0x2
  beq-      .loc_0x430
  bge-      .loc_0x418
  cmpwi     r0, 0
  beq-      .loc_0x428
  b         .loc_0x60C

.loc_0x418:
  cmpwi     r0, 0x4
  beq-      .loc_0x444
  bge-      .loc_0x60C
  b         .loc_0x43C

.loc_0x428:
  stw       r27, 0x0(r3)
  b         .loc_0x60C

.loc_0x430:
  extsh     r0, r27
  sth       r0, 0x0(r3)
  b         .loc_0x60C

.loc_0x43C:
  stw       r27, 0x0(r3)
  b         .loc_0x60C

.loc_0x444:
  stw       r27, 0x4(r3)
  srawi     r0, r27, 0x1F
  stw       r0, 0x0(r3)
  b         .loc_0x60C

.loc_0x454:
  addi      r3, r28, 0
  addi      r19, r1, 0x1C
  li        r4, 0x1
  bl        -0x24E0
  lwz       r0, 0x0(r3)
  li        r24, 0x1
  extsb     r0, r0
  stb       r0, 0x1C(r1)
  b         .loc_0x4CC

.loc_0x478:
  li        r0, 0x25
  stb       r0, 0x1C(r1)
  addi      r19, r1, 0x1C
  li        r24, 0x1
  b         .loc_0x4CC

.loc_0x48C:
  mr        r3, r24
  bl        0x268C
  mr.       r5, r3
  add       r27, r27, r5
  beq-      .loc_0x4C4
  addi      r12, r31, 0
  mtlr      r12
  addi      r3, r30, 0
  addi      r4, r24, 0
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x4C4
  li        r3, -0x1
  b         .loc_0x61C

.loc_0x4C4:
  mr        r3, r27
  b         .loc_0x61C

.loc_0x4CC:
  lbz       r0, 0x21C(r1)
  addi      r18, r24, 0
  cmplwi    r0, 0
  beq-      .loc_0x588
  cmplwi    r0, 0x2
  bne-      .loc_0x4EC
  li        r0, 0x30
  b         .loc_0x4F0

.loc_0x4EC:
  li        r0, 0x20

.loc_0x4F0:
  extsb     r0, r0
  stb       r0, 0x19(r1)
  lbz       r0, 0x0(r19)
  extsb     r0, r0
  cmpwi     r0, 0x2B
  beq-      .loc_0x510
  cmpwi     r0, 0x2D
  bne-      .loc_0x57C

.loc_0x510:
  lbz       r0, 0x19(r1)
  cmpwi     r0, 0x30
  bne-      .loc_0x57C
  addi      r12, r31, 0
  mtlr      r12
  addi      r3, r30, 0
  addi      r4, r19, 0
  li        r5, 0x1
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x544
  li        r3, -0x1
  b         .loc_0x61C

.loc_0x544:
  addi      r19, r19, 0x1
  subi      r24, r24, 0x1
  b         .loc_0x57C

.loc_0x550:
  addi      r12, r31, 0
  mtlr      r12
  addi      r3, r30, 0
  addi      r4, r1, 0x19
  li        r5, 0x1
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x578
  li        r3, -0x1
  b         .loc_0x61C

.loc_0x578:
  addi      r18, r18, 0x1

.loc_0x57C:
  lwz       r0, 0x224(r1)
  cmpw      r18, r0
  blt+      .loc_0x550

.loc_0x588:
  cmpwi     r24, 0
  beq-      .loc_0x5B8
  addi      r12, r31, 0
  mtlr      r12
  addi      r3, r30, 0
  addi      r4, r19, 0
  addi      r5, r24, 0
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x5B8
  li        r3, -0x1
  b         .loc_0x61C

.loc_0x5B8:
  lbz       r0, 0x21C(r1)
  cmplwi    r0, 0
  bne-      .loc_0x608
  li        r19, 0x20
  b         .loc_0x5FC

.loc_0x5CC:
  mr        r12, r31
  stb       r19, 0x18(r1)
  mtlr      r12
  addi      r3, r30, 0
  addi      r4, r1, 0x18
  li        r5, 0x1
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x5F8
  li        r3, -0x1
  b         .loc_0x61C

.loc_0x5F8:
  addi      r18, r18, 0x1

.loc_0x5FC:
  lwz       r0, 0x224(r1)
  cmpw      r18, r0
  blt+      .loc_0x5CC

.loc_0x608:
  add       r27, r27, r18

.loc_0x60C:
  lbz       r0, 0x0(r25)
  extsb.    r0, r0
  bne+      .loc_0x40

.loc_0x618:
  mr        r3, r27

.loc_0x61C:
  lmw       r18, 0x230(r1)
  lwz       r0, 0x26C(r1)
  addi      r1, r1, 0x268
  mtlr      r0
  blr       

.loc_0x630:
*/
}

/*
 * --INFO--
 * Address:	80216F20
 * Size:	000638
 */
void float2str(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stfd      f31, 0x58(r1)
  stw       r31, 0x54(r1)
  stw       r30, 0x50(r1)
  stw       r29, 0x4C(r1)
  mr        r29, r5
  stw       r28, 0x48(r1)
  addi      r28, r4, 0
  lbz       r0, 0x4(r5)
  cmplwi    r0, 0x5
  bne-      .loc_0x44
  li        r4, 0x3
  bl        -0x26E8
  lfd       f31, 0x0(r3)
  b         .loc_0x50

.loc_0x44:
  li        r4, 0x3
  bl        -0x26F8
  lfd       f31, 0x0(r3)

.loc_0x50:
  lwz       r0, 0xC(r29)
  cmpwi     r0, 0x1FD
  ble-      .loc_0x64
  li        r3, 0
  b         .loc_0x614

.loc_0x64:
  li        r0, 0
  fmr       f1, f31
  stb       r0, 0x18(r1)
  li        r0, 0x20
  addi      r3, r1, 0x18
  sth       r0, 0x1A(r1)
  addi      r4, r1, 0x1C
  bl        -0x16B4
  lbz       r0, 0x20(r1)
  addi      r31, r1, 0x21
  add       r4, r31, r0
  b         .loc_0xAC

.loc_0x94:
  lbz       r3, 0x20(r1)
  subi      r0, r3, 0x1
  stb       r0, 0x20(r1)
  lha       r3, 0x1E(r1)
  addi      r0, r3, 0x1
  sth       r0, 0x1E(r1)

.loc_0xAC:
  lbz       r0, 0x20(r1)
  cmplwi    r0, 0x1
  ble-      .loc_0xC4
  lbzu      r0, -0x1(r4)
  cmpwi     r0, 0x30
  beq+      .loc_0x94

.loc_0xC4:
  lbz       r0, 0x21(r1)
  cmpwi     r0, 0x49
  beq-      .loc_0xF8
  bge-      .loc_0xE0
  cmpwi     r0, 0x30
  beq-      .loc_0xEC
  b         .loc_0x160

.loc_0xE0:
  cmpwi     r0, 0x4E
  beq-      .loc_0x140
  b         .loc_0x160

.loc_0xEC:
  li        r0, 0
  sth       r0, 0x1E(r1)
  b         .loc_0x160

.loc_0xF8:
  lfd       f0, -0x3BE8(r2)
  fcmpo     cr0, f31, f0
  bge-      .loc_0x120
  lis       r3, 0x8022
  subi      r28, r28, 0x5
  addi      r4, r3, 0x2B10
  addi      r3, r28, 0
  addi      r4, r4, 0x1
  bl        0x2320
  b         .loc_0x138

.loc_0x120:
  lis       r3, 0x8022
  subi      r28, r28, 0x4
  addi      r4, r3, 0x2B10
  addi      r3, r28, 0
  addi      r4, r4, 0x6
  bl        0x2304

.loc_0x138:
  mr        r3, r28
  b         .loc_0x614

.loc_0x140:
  lis       r3, 0x8022
  subi      r28, r28, 0x4
  addi      r4, r3, 0x2B10
  addi      r3, r28, 0
  addi      r4, r4, 0xA
  bl        0x22E4
  mr        r3, r28
  b         .loc_0x614

.loc_0x160:
  lha       r4, 0x1E(r1)
  li        r0, 0
  lbz       r3, 0x20(r1)
  subi      r30, r28, 0x1
  add       r3, r3, r4
  subi      r3, r3, 0x1
  sth       r3, 0x1E(r1)
  stb       r0, -0x1(r28)
  lbz       r0, 0x5(r29)
  cmpwi     r0, 0x65
  beq-      .loc_0x27C
  bge-      .loc_0x1B4
  cmpwi     r0, 0x46
  beq-      .loc_0x610
  bge-      .loc_0x1A8
  cmpwi     r0, 0x45
  bge-      .loc_0x27C
  b         .loc_0x610

.loc_0x1A8:
  cmpwi     r0, 0x48
  bge-      .loc_0x610
  b         .loc_0x1C4

.loc_0x1B4:
  cmpwi     r0, 0x67
  beq-      .loc_0x1C4
  bge-      .loc_0x610
  b         .loc_0x3EC

.loc_0x1C4:
  lbz       r0, 0x20(r1)
  lwz       r4, 0xC(r29)
  cmpw      r0, r4
  ble-      .loc_0x1DC
  addi      r3, r1, 0x1C
  bl        .loc_0x638

.loc_0x1DC:
  lha       r4, 0x1E(r1)
  cmpwi     r4, -0x4
  blt-      .loc_0x1F4
  lwz       r3, 0xC(r29)
  cmpw      r4, r3
  blt-      .loc_0x240

.loc_0x1F4:
  lbz       r0, 0x3(r29)
  cmplwi    r0, 0
  beq-      .loc_0x210
  lwz       r3, 0xC(r29)
  subi      r0, r3, 0x1
  stw       r0, 0xC(r29)
  b         .loc_0x21C

.loc_0x210:
  lbz       r3, 0x20(r1)
  subi      r0, r3, 0x1
  stw       r0, 0xC(r29)

.loc_0x21C:
  lbz       r0, 0x5(r29)
  cmplwi    r0, 0x67
  bne-      .loc_0x234
  li        r0, 0x65
  stb       r0, 0x5(r29)
  b         .loc_0x27C

.loc_0x234:
  li        r0, 0x45
  stb       r0, 0x5(r29)
  b         .loc_0x27C

.loc_0x240:
  lbz       r0, 0x3(r29)
  cmplwi    r0, 0
  beq-      .loc_0x25C
  addi      r0, r4, 0x1
  sub       r0, r3, r0
  stw       r0, 0xC(r29)
  b         .loc_0x3EC

.loc_0x25C:
  lbz       r0, 0x20(r1)
  addi      r3, r4, 0x1
  sub.      r0, r0, r3
  stw       r0, 0xC(r29)
  bge-      .loc_0x3EC
  li        r0, 0
  stw       r0, 0xC(r29)
  b         .loc_0x3EC

.loc_0x27C:
  lwz       r3, 0xC(r29)
  lbz       r0, 0x20(r1)
  addi      r4, r3, 0x1
  cmpw      r0, r4
  ble-      .loc_0x298
  addi      r3, r1, 0x1C
  bl        .loc_0x638

.loc_0x298:
  lha       r0, 0x1E(r1)
  li        r8, 0x2B
  cmpwi     r0, 0
  mr        r4, r0
  bge-      .loc_0x2B4
  neg       r4, r4
  li        r8, 0x2D

.loc_0x2B4:
  lis       r3, 0x6666
  addi      r5, r3, 0x6667
  li        r7, 0
  b         .loc_0x2F8

.loc_0x2C4:
  mulhw     r6, r5, r4
  srawi     r0, r6, 0x2
  rlwinm    r3,r0,1,31,31
  add       r0, r0, r3
  mulli     r0, r0, 0xA
  sub       r4, r4, r0
  srawi     r0, r6, 0x2
  addi      r4, r4, 0x30
  stb       r4, -0x1(r30)
  rlwinm    r3,r0,1,31,31
  add       r4, r0, r3
  addi      r7, r7, 0x1
  subi      r30, r30, 0x1

.loc_0x2F8:
  cmpwi     r4, 0
  bne+      .loc_0x2C4
  cmpwi     r7, 0x2
  blt+      .loc_0x2C4
  extsb     r0, r8
  stb       r0, -0x1(r30)
  subi      r30, r30, 0x2
  sub       r0, r28, r30
  lbz       r3, 0x5(r29)
  stb       r3, 0x0(r30)
  lwz       r3, 0xC(r29)
  add       r0, r3, r0
  cmpwi     r0, 0x1FD
  ble-      .loc_0x338
  li        r3, 0
  b         .loc_0x614

.loc_0x338:
  lbz       r4, 0x20(r1)
  addi      r0, r3, 0x1
  cmpw      r4, r0
  bge-      .loc_0x364
  addi      r0, r3, 0x2
  sub       r3, r0, r4
  li        r0, 0x30
  b         .loc_0x35C

.loc_0x358:
  stbu      r0, -0x1(r30)

.loc_0x35C:
  subic.    r3, r3, 0x1
  bne+      .loc_0x358

.loc_0x364:
  lbz       r3, 0x20(r1)
  add       r4, r31, r3
  b         .loc_0x378

.loc_0x370:
  lbzu      r0, -0x1(r4)
  stbu      r0, -0x1(r30)

.loc_0x378:
  subic.    r3, r3, 0x1
  bne+      .loc_0x370
  lwz       r0, 0xC(r29)
  cmpwi     r0, 0
  bne-      .loc_0x398
  lbz       r0, 0x3(r29)
  cmplwi    r0, 0
  beq-      .loc_0x3A0

.loc_0x398:
  li        r0, 0x2E
  stbu      r0, -0x1(r30)

.loc_0x3A0:
  lbz       r0, 0x21(r1)
  stbu      r0, -0x1(r30)
  lbz       r0, 0x1C(r1)
  extsb.    r0, r0
  beq-      .loc_0x3C0
  li        r0, 0x2D
  stbu      r0, -0x1(r30)
  b         .loc_0x610

.loc_0x3C0:
  lbz       r0, 0x1(r29)
  cmplwi    r0, 0x1
  bne-      .loc_0x3D8
  li        r0, 0x2B
  stbu      r0, -0x1(r30)
  b         .loc_0x610

.loc_0x3D8:
  cmplwi    r0, 0x2
  bne-      .loc_0x610
  li        r0, 0x20
  stbu      r0, -0x1(r30)
  b         .loc_0x610

.loc_0x3EC:
  lha       r0, 0x1E(r1)
  lbz       r4, 0x20(r1)
  sub       r0, r4, r0
  subic.    r7, r0, 0x1
  bge-      .loc_0x404
  li        r7, 0

.loc_0x404:
  lwz       r0, 0xC(r29)
  cmpw      r7, r0
  ble-      .loc_0x438
  sub       r0, r7, r0
  addi      r3, r1, 0x1C
  sub       r4, r4, r0
  bl        .loc_0x638
  lha       r3, 0x1E(r1)
  lbz       r0, 0x20(r1)
  sub       r0, r0, r3
  subic.    r7, r0, 0x1
  bge-      .loc_0x438
  li        r7, 0

.loc_0x438:
  lha       r0, 0x1E(r1)
  addic.    r6, r0, 0x1
  bge-      .loc_0x448
  li        r6, 0

.loc_0x448:
  add       r0, r6, r7
  cmpwi     r0, 0x1FD
  ble-      .loc_0x45C
  li        r3, 0
  b         .loc_0x614

.loc_0x45C:
  lbz       r0, 0x20(r1)
  li        r4, 0
  li        r3, 0x30
  add       r5, r31, r0
  b         .loc_0x478

.loc_0x470:
  stbu      r3, -0x1(r30)
  addi      r4, r4, 0x1

.loc_0x478:
  lwz       r0, 0xC(r29)
  sub       r0, r0, r7
  cmpw      r4, r0
  blt+      .loc_0x470
  li        r3, 0
  b         .loc_0x49C

.loc_0x490:
  lbzu      r0, -0x1(r5)
  addi      r3, r3, 0x1
  stbu      r0, -0x1(r30)

.loc_0x49C:
  cmpw      r3, r7
  bge-      .loc_0x4B0
  lbz       r0, 0x20(r1)
  cmpw      r3, r0
  blt+      .loc_0x490

.loc_0x4B0:
  cmpw      r3, r7
  sub       r3, r7, r3
  li        r4, 0x30
  bge-      .loc_0x504
  rlwinm.   r0,r3,29,3,31
  mtctr     r0
  beq-      .loc_0x4F8

.loc_0x4CC:
  stb       r4, -0x1(r30)
  stb       r4, -0x2(r30)
  stb       r4, -0x3(r30)
  stb       r4, -0x4(r30)
  stb       r4, -0x5(r30)
  stb       r4, -0x6(r30)
  stb       r4, -0x7(r30)
  stbu      r4, -0x8(r30)
  bdnz+     .loc_0x4CC
  andi.     r3, r3, 0x7
  beq-      .loc_0x504

.loc_0x4F8:
  mtctr     r3

.loc_0x4FC:
  stbu      r4, -0x1(r30)
  bdnz+     .loc_0x4FC

.loc_0x504:
  lwz       r0, 0xC(r29)
  cmpwi     r0, 0
  bne-      .loc_0x51C
  lbz       r0, 0x3(r29)
  cmplwi    r0, 0
  beq-      .loc_0x524

.loc_0x51C:
  li        r0, 0x2E
  stbu      r0, -0x1(r30)

.loc_0x524:
  cmpwi     r6, 0
  beq-      .loc_0x5C8
  li        r4, 0
  li        r3, 0x30
  b         .loc_0x540

.loc_0x538:
  stbu      r3, -0x1(r30)
  addi      r4, r4, 0x1

.loc_0x540:
  lbz       r0, 0x20(r1)
  sub       r0, r6, r0
  cmpw      r4, r0
  blt+      .loc_0x538
  cmpw      r4, r6
  sub       r3, r6, r4
  bge-      .loc_0x5D0
  rlwinm.   r0,r3,29,3,31
  mtctr     r0
  beq-      .loc_0x5B4

.loc_0x568:
  lbz       r0, -0x1(r5)
  stb       r0, -0x1(r30)
  lbz       r0, -0x2(r5)
  stb       r0, -0x2(r30)
  lbz       r0, -0x3(r5)
  stb       r0, -0x3(r30)
  lbz       r0, -0x4(r5)
  stb       r0, -0x4(r30)
  lbz       r0, -0x5(r5)
  stb       r0, -0x5(r30)
  lbz       r0, -0x6(r5)
  stb       r0, -0x6(r30)
  lbz       r0, -0x7(r5)
  stb       r0, -0x7(r30)
  lbzu      r0, -0x8(r5)
  stbu      r0, -0x8(r30)
  bdnz+     .loc_0x568
  andi.     r3, r3, 0x7
  beq-      .loc_0x5D0

.loc_0x5B4:
  mtctr     r3

.loc_0x5B8:
  lbzu      r0, -0x1(r5)
  stbu      r0, -0x1(r30)
  bdnz+     .loc_0x5B8
  b         .loc_0x5D0

.loc_0x5C8:
  li        r0, 0x30
  stbu      r0, -0x1(r30)

.loc_0x5D0:
  lbz       r0, 0x1C(r1)
  extsb.    r0, r0
  beq-      .loc_0x5E8
  li        r0, 0x2D
  stbu      r0, -0x1(r30)
  b         .loc_0x610

.loc_0x5E8:
  lbz       r0, 0x1(r29)
  cmplwi    r0, 0x1
  bne-      .loc_0x600
  li        r0, 0x2B
  stbu      r0, -0x1(r30)
  b         .loc_0x610

.loc_0x600:
  cmplwi    r0, 0x2
  bne-      .loc_0x610
  li        r0, 0x20
  stbu      r0, -0x1(r30)

.loc_0x610:
  mr        r3, r30

.loc_0x614:
  lwz       r0, 0x64(r1)
  lfd       f31, 0x58(r1)
  lwz       r31, 0x54(r1)
  mtlr      r0
  lwz       r30, 0x50(r1)
  lwz       r29, 0x4C(r1)
  lwz       r28, 0x48(r1)
  addi      r1, r1, 0x60
  blr       

.loc_0x638:
*/
}

/*
 * --INFO--
 * Address:	80217558
 * Size:	000134
 */
void round_decimal(void)
{
/*
.loc_0x0:
  cmpwi     r4, 0
  bge-      .loc_0x28

.loc_0x8:
  li        r5, 0
  stb       r5, 0x0(r3)
  li        r4, 0x1
  li        r0, 0x30
  sth       r5, 0x2(r3)
  stb       r4, 0x4(r3)
  stb       r0, 0x5(r3)
  blr       

.loc_0x28:
  lbz       r0, 0x4(r3)
  cmpw      r4, r0
  bgelr-    
  add       r5, r3, r4
  addi      r8, r5, 0x6
  lbzu      r5, -0x1(r8)
  subi      r5, r5, 0x30
  extsb     r6, r5
  cmpwi     r6, 0x5
  bne-      .loc_0x90
  add       r5, r3, r0
  addi      r5, r5, 0x5

.loc_0x58:
  subi      r5, r5, 0x1
  cmplw     r5, r8
  ble-      .loc_0x70
  lbz       r0, 0x0(r5)
  cmpwi     r0, 0x30
  beq+      .loc_0x58

.loc_0x70:
  cmplw     r5, r8
  bne-      .loc_0x84
  lbz       r0, -0x1(r8)
  rlwinm    r0,r0,0,31,31
  b         .loc_0x88

.loc_0x84:
  li        r0, 0x1

.loc_0x88:
  mr        r5, r0
  b         .loc_0xF0

.loc_0x90:
  li        r5, 0x5
  eqv       r0, r6, r5
  subc      r5, r5, r6
  rlwinm    r0,r0,1,31,31
  addze     r5, r0
  rlwinm    r5,r5,0,31,31
  b         .loc_0xF0

.loc_0xAC:
  lbzu      r0, -0x1(r8)
  add       r7, r0, r5
  subi      r7, r7, 0x30
  extsb     r5, r7
  eqv       r0, r5, r6
  subc      r5, r6, r5
  rlwinm    r0,r0,1,31,31
  addze     r5, r0
  rlwinm.   r5,r5,0,31,31
  bne-      .loc_0xDC
  extsb.    r0, r7
  bne-      .loc_0xE4

.loc_0xDC:
  subi      r4, r4, 0x1
  b         .loc_0xF4

.loc_0xE4:
  addi      r0, r7, 0x30
  stb       r0, 0x0(r8)
  b         .loc_0xFC

.loc_0xF0:
  li        r6, 0x9

.loc_0xF4:
  cmpwi     r4, 0
  bne+      .loc_0xAC

.loc_0xFC:
  cmpwi     r5, 0
  beq-      .loc_0x124
  lha       r5, 0x2(r3)
  li        r4, 0x1
  li        r0, 0x31
  addi      r5, r5, 0x1
  sth       r5, 0x2(r3)
  stb       r4, 0x4(r3)
  stb       r0, 0x5(r3)
  blr       

.loc_0x124:
  cmpwi     r4, 0
  beq+      .loc_0x8
  stb       r4, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8021768C
 * Size:	0002E0
 */
void longlong2str(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x40(r1)
  stmw      r22, 0x18(r1)
  addi      r23, r5, 0
  xor       r5, r4, r0
  subi      r27, r23, 0x1
  addi      r24, r6, 0
  addi      r30, r4, 0
  addi      r31, r3, 0
  li        r25, 0
  li        r26, 0
  stb       r0, -0x1(r23)
  xor       r0, r3, r0
  or.       r0, r5, r0
  bne-      .loc_0x70
  lwz       r0, 0xC(r24)
  cmpwi     r0, 0
  bne-      .loc_0x70
  lbz       r0, 0x3(r24)
  cmplwi    r0, 0
  beq-      .loc_0x68
  lbz       r0, 0x5(r24)
  cmplwi    r0, 0x6F
  beq-      .loc_0x70

.loc_0x68:
  mr        r3, r27
  b         .loc_0x2CC

.loc_0x70:
  lbz       r5, 0x5(r24)
  subi      r0, r5, 0x58
  cmplwi    r0, 0x20
  bgt-      .loc_0x108
  lis       r5, 0x802F
  subi      r5, r5, 0x6F00
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r5, r0
  mtctr     r0
  bctr      
  li        r0, 0
  xoris     r5, r3, 0x8000
  xoris     r3, r0, 0x8000
  subc      r0, r4, r0
  subfe     r3, r3, r5
  subfe     r3, r5, r5
  neg.      r3, r3
  li        r28, 0xA
  li        r29, 0
  beq-      .loc_0x108
  subfic    r30, r30, 0
  subfze    r31, r31
  li        r25, 0x1
  b         .loc_0x108
  li        r0, 0
  stb       r0, 0x1(r24)
  li        r28, 0x8
  li        r29, 0
  b         .loc_0x108
  li        r0, 0
  stb       r0, 0x1(r24)
  li        r28, 0xA
  li        r29, 0
  b         .loc_0x108
  li        r0, 0
  stb       r0, 0x1(r24)
  li        r28, 0x10
  li        r29, 0

.loc_0x108:
  addi      r3, r31, 0
  addi      r4, r30, 0
  addi      r5, r29, 0
  addi      r6, r28, 0
  bl        -0x26C4
  addi      r22, r4, 0
  addi      r3, r31, 0
  addi      r4, r30, 0
  addi      r5, r29, 0
  addi      r6, r28, 0
  bl        -0x2900
  cmpwi     r22, 0xA
  addi      r30, r4, 0
  addi      r31, r3, 0
  bge-      .loc_0x14C
  addi      r5, r22, 0x30
  b         .loc_0x164

.loc_0x14C:
  lbz       r0, 0x5(r24)
  cmplwi    r0, 0x78
  bne-      .loc_0x160
  addi      r5, r22, 0x57
  b         .loc_0x164

.loc_0x160:
  addi      r5, r22, 0x37

.loc_0x164:
  li        r4, 0
  xor       r3, r30, r4
  xor       r0, r31, r4
  or.       r0, r3, r0
  extsb     r0, r5
  addi      r26, r26, 0x1
  stbu      r0, -0x1(r27)
  bne+      .loc_0x108
  li        r0, 0x8
  xor       r3, r28, r0
  xor       r0, r29, r4
  or.       r0, r3, r0
  bne-      .loc_0x1BC
  lbz       r0, 0x3(r24)
  cmplwi    r0, 0
  beq-      .loc_0x1BC
  lbz       r0, 0x0(r27)
  cmpwi     r0, 0x30
  beq-      .loc_0x1BC
  li        r0, 0x30
  stbu      r0, -0x1(r27)
  addi      r26, r26, 0x1

.loc_0x1BC:
  lbz       r0, 0x0(r24)
  cmplwi    r0, 0x2
  bne-      .loc_0x220
  lwz       r0, 0x8(r24)
  cmpwi     r25, 0
  stw       r0, 0xC(r24)
  bne-      .loc_0x1E4
  lbz       r0, 0x1(r24)
  cmplwi    r0, 0
  beq-      .loc_0x1F0

.loc_0x1E4:
  lwz       r3, 0xC(r24)
  subi      r0, r3, 0x1
  stw       r0, 0xC(r24)

.loc_0x1F0:
  li        r3, 0x10
  li        r0, 0
  xor       r3, r28, r3
  xor       r0, r29, r0
  or.       r0, r3, r0
  bne-      .loc_0x220
  lbz       r0, 0x3(r24)
  cmplwi    r0, 0
  beq-      .loc_0x220
  lwz       r3, 0xC(r24)
  subi      r0, r3, 0x2
  stw       r0, 0xC(r24)

.loc_0x220:
  lwz       r3, 0xC(r24)
  sub       r0, r23, r27
  add       r0, r3, r0
  cmpwi     r0, 0x1FD
  ble-      .loc_0x23C
  li        r3, 0
  b         .loc_0x2CC

.loc_0x23C:
  li        r3, 0x30
  b         .loc_0x24C

.loc_0x244:
  stbu      r3, -0x1(r27)
  addi      r26, r26, 0x1

.loc_0x24C:
  lwz       r0, 0xC(r24)
  cmpw      r26, r0
  blt+      .loc_0x244
  li        r3, 0x10
  li        r0, 0
  xor       r3, r28, r3
  xor       r0, r29, r0
  or.       r0, r3, r0
  bne-      .loc_0x28C
  lbz       r0, 0x3(r24)
  cmplwi    r0, 0
  beq-      .loc_0x28C
  lbz       r3, 0x5(r24)
  li        r0, 0x30
  stb       r3, -0x1(r27)
  stbu      r0, -0x2(r27)

.loc_0x28C:
  cmpwi     r25, 0
  beq-      .loc_0x2A0
  li        r0, 0x2D
  stbu      r0, -0x1(r27)
  b         .loc_0x2C8

.loc_0x2A0:
  lbz       r0, 0x1(r24)
  cmplwi    r0, 0x1
  bne-      .loc_0x2B8
  li        r0, 0x2B
  stbu      r0, -0x1(r27)
  b         .loc_0x2C8

.loc_0x2B8:
  cmplwi    r0, 0x2
  bne-      .loc_0x2C8
  li        r0, 0x20
  stbu      r0, -0x1(r27)

.loc_0x2C8:
  mr        r3, r27

.loc_0x2CC:
  lmw       r22, 0x18(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021796C
 * Size:	000224
 */
void long2str(void)
{
/*
.loc_0x0:
  li        r7, 0
  stb       r7, -0x1(r4)
  cmpwi     r3, 0
  subi      r6, r4, 0x1
  li        r8, 0
  li        r7, 0
  bne-      .loc_0x48
  lwz       r9, 0xC(r5)
  cmpwi     r9, 0
  bne-      .loc_0x48
  lbz       r9, 0x3(r5)
  cmplwi    r9, 0
  beq-      .loc_0x40
  lbz       r9, 0x5(r5)
  cmplwi    r9, 0x6F
  beq-      .loc_0x48

.loc_0x40:
  mr        r3, r6
  blr       

.loc_0x48:
  lbz       r9, 0x5(r5)
  subi      r10, r9, 0x58
  cmplwi    r10, 0x20
  bgt-      .loc_0xB4
  lis       r9, 0x802F
  subi      r9, r9, 0x6E7C
  rlwinm    r10,r10,2,0,29
  lwzx      r9, r9, r10
  mtctr     r9
  bctr      
  cmpwi     r3, 0
  li        r0, 0xA
  bge-      .loc_0xB4
  neg       r3, r3
  li        r8, 0x1
  b         .loc_0xB4
  li        r0, 0
  stb       r0, 0x1(r5)
  li        r0, 0x8
  b         .loc_0xB4
  li        r0, 0
  stb       r0, 0x1(r5)
  li        r0, 0xA
  b         .loc_0xB4
  li        r0, 0
  stb       r0, 0x1(r5)
  li        r0, 0x10

.loc_0xB4:
  divwu     r9, r3, r0
  mullw     r9, r9, r0
  sub       r10, r3, r9
  divwu     r3, r3, r0
  cmpwi     r10, 0xA
  bge-      .loc_0xD4
  addi      r10, r10, 0x30
  b         .loc_0xEC

.loc_0xD4:
  lbz       r9, 0x5(r5)
  cmplwi    r9, 0x78
  bne-      .loc_0xE8
  addi      r10, r10, 0x57
  b         .loc_0xEC

.loc_0xE8:
  addi      r10, r10, 0x37

.loc_0xEC:
  extsb     r9, r10
  stb       r9, -0x1(r6)
  cmplwi    r3, 0
  subi      r6, r6, 0x1
  addi      r7, r7, 0x1
  bne+      .loc_0xB4
  cmplwi    r0, 0x8
  bne-      .loc_0x130
  lbz       r3, 0x3(r5)
  cmplwi    r3, 0
  beq-      .loc_0x130
  lbz       r3, 0x0(r6)
  cmpwi     r3, 0x30
  beq-      .loc_0x130
  li        r3, 0x30
  stbu      r3, -0x1(r6)
  addi      r7, r7, 0x1

.loc_0x130:
  lbz       r3, 0x0(r5)
  cmplwi    r3, 0x2
  bne-      .loc_0x184
  lwz       r3, 0x8(r5)
  cmpwi     r8, 0
  stw       r3, 0xC(r5)
  bne-      .loc_0x158
  lbz       r3, 0x1(r5)
  cmplwi    r3, 0
  beq-      .loc_0x164

.loc_0x158:
  lwz       r3, 0xC(r5)
  subi      r3, r3, 0x1
  stw       r3, 0xC(r5)

.loc_0x164:
  cmplwi    r0, 0x10
  bne-      .loc_0x184
  lbz       r3, 0x3(r5)
  cmplwi    r3, 0
  beq-      .loc_0x184
  lwz       r3, 0xC(r5)
  subi      r3, r3, 0x2
  stw       r3, 0xC(r5)

.loc_0x184:
  lwz       r9, 0xC(r5)
  sub       r3, r4, r6
  add       r3, r9, r3
  cmpwi     r3, 0x1FD
  ble-      .loc_0x1A0
  li        r3, 0
  blr       

.loc_0x1A0:
  li        r4, 0x30
  b         .loc_0x1B0

.loc_0x1A8:
  stbu      r4, -0x1(r6)
  addi      r7, r7, 0x1

.loc_0x1B0:
  lwz       r3, 0xC(r5)
  cmpw      r7, r3
  blt+      .loc_0x1A8
  cmplwi    r0, 0x10
  bne-      .loc_0x1E0
  lbz       r0, 0x3(r5)
  cmplwi    r0, 0
  beq-      .loc_0x1E0
  lbz       r3, 0x5(r5)
  li        r0, 0x30
  stb       r3, -0x1(r6)
  stbu      r0, -0x2(r6)

.loc_0x1E0:
  cmpwi     r8, 0
  beq-      .loc_0x1F4
  li        r0, 0x2D
  stbu      r0, -0x1(r6)
  b         .loc_0x21C

.loc_0x1F4:
  lbz       r0, 0x1(r5)
  cmplwi    r0, 0x1
  bne-      .loc_0x20C
  li        r0, 0x2B
  stbu      r0, -0x1(r6)
  b         .loc_0x21C

.loc_0x20C:
  cmplwi    r0, 0x2
  bne-      .loc_0x21C
  li        r0, 0x20
  stbu      r0, -0x1(r6)

.loc_0x21C:
  mr        r3, r6
  blr
*/
}

/*
 * --INFO--
 * Address:	80217B90
 * Size:	0004D8
 */
void parse_format(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r3, 0x1
  stw       r30, 0x30(r1)
  addi      r30, r5, 0
  stw       r29, 0x2C(r1)
  addi      r29, r4, 0
  stb       r0, 0x14(r1)
  li        r0, 0
  stb       r0, 0x15(r1)
  stb       r0, 0x16(r1)
  stb       r0, 0x17(r1)
  stb       r0, 0x18(r1)
  stw       r0, 0x1C(r1)
  stw       r0, 0x20(r1)
  lbz       r3, 0x1(r3)
  extsb     r3, r3
  cmpwi     r3, 0x25
  bne-      .loc_0x84
  stb       r3, 0x19(r1)
  addi      r3, r31, 0x1
  lwz       r4, 0x14(r1)
  lwz       r0, 0x18(r1)
  stw       r4, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r4, 0x1C(r1)
  lwz       r0, 0x20(r1)
  stw       r4, 0x8(r30)
  stw       r0, 0xC(r30)
  b         .loc_0x4BC

.loc_0x84:
  lis       r4, 0x802F
  subi      r4, r4, 0x6D28

.loc_0x8C:
  subi      r0, r3, 0x20
  cmplwi    r0, 0x10
  li        r5, 0x1
  bgt-      .loc_0x100
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r4, r0
  mtctr     r0
  bctr      
  li        r0, 0
  stb       r0, 0x14(r1)
  b         .loc_0x104
  li        r0, 0x1
  stb       r0, 0x15(r1)
  b         .loc_0x104
  lbz       r0, 0x15(r1)
  cmplwi    r0, 0x1
  beq-      .loc_0x104
  li        r0, 0x2
  stb       r0, 0x15(r1)
  b         .loc_0x104
  li        r0, 0x1
  stb       r0, 0x17(r1)
  b         .loc_0x104
  lbz       r0, 0x14(r1)
  cmplwi    r0, 0
  beq-      .loc_0x104
  li        r0, 0x2
  stb       r0, 0x14(r1)
  b         .loc_0x104

.loc_0x100:
  li        r5, 0

.loc_0x104:
  cmpwi     r5, 0
  beq-      .loc_0x118
  lbzu      r3, 0x1(r31)
  extsb     r3, r3
  b         .loc_0x8C

.loc_0x118:
  cmpwi     r3, 0x2A
  bne-      .loc_0x15C
  addi      r3, r29, 0
  li        r4, 0x1
  bl        -0x3448
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0
  stw       r0, 0x1C(r1)
  bge-      .loc_0x150
  li        r0, 0
  stb       r0, 0x14(r1)
  lwz       r0, 0x1C(r1)
  neg       r0, r0
  stw       r0, 0x1C(r1)

.loc_0x150:
  lbzu      r3, 0x1(r31)
  extsb     r3, r3
  b         .loc_0x198

.loc_0x15C:
  lis       r4, 0x8022
  addi      r5, r4, 0x2808
  b         .loc_0x184

.loc_0x168:
  lwz       r0, 0x1C(r1)
  mulli     r0, r0, 0xA
  add       r3, r3, r0
  subi      r0, r3, 0x30
  stw       r0, 0x1C(r1)
  lbzu      r3, 0x1(r31)
  extsb     r3, r3

.loc_0x184:
  rlwinm    r0,r3,0,24,31
  add       r4, r5, r0
  lbz       r0, 0x0(r4)
  rlwinm.   r0,r0,0,27,27
  bne+      .loc_0x168

.loc_0x198:
  lwz       r0, 0x1C(r1)
  cmpwi     r0, 0x1FD
  ble-      .loc_0x1D4
  li        r0, 0xFF
  stb       r0, 0x19(r1)
  addi      r3, r31, 0x1
  lwz       r4, 0x14(r1)
  lwz       r0, 0x18(r1)
  stw       r4, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r4, 0x1C(r1)
  lwz       r0, 0x20(r1)
  stw       r4, 0x8(r30)
  stw       r0, 0xC(r30)
  b         .loc_0x4BC

.loc_0x1D4:
  cmpwi     r3, 0x2E
  bne-      .loc_0x260
  li        r0, 0x1
  stb       r0, 0x16(r1)
  lbzu      r3, 0x1(r31)
  extsb     r3, r3
  cmpwi     r3, 0x2A
  bne-      .loc_0x224
  addi      r3, r29, 0
  li        r4, 0x1
  bl        -0x351C
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0
  stw       r0, 0x20(r1)
  bge-      .loc_0x218
  li        r0, 0
  stb       r0, 0x16(r1)

.loc_0x218:
  lbzu      r3, 0x1(r31)
  extsb     r3, r3
  b         .loc_0x260

.loc_0x224:
  lis       r4, 0x8022
  addi      r5, r4, 0x2808
  b         .loc_0x24C

.loc_0x230:
  lwz       r0, 0x20(r1)
  mulli     r0, r0, 0xA
  add       r3, r3, r0
  subi      r0, r3, 0x30
  stw       r0, 0x20(r1)
  lbzu      r3, 0x1(r31)
  extsb     r3, r3

.loc_0x24C:
  rlwinm    r0,r3,0,24,31
  add       r4, r5, r0
  lbz       r0, 0x0(r4)
  rlwinm.   r0,r0,0,27,27
  bne+      .loc_0x230

.loc_0x260:
  cmpwi     r3, 0x68
  li        r4, 0x1
  beq-      .loc_0x288
  bge-      .loc_0x27C
  cmpwi     r3, 0x4C
  beq-      .loc_0x2D4
  b         .loc_0x2E0

.loc_0x27C:
  cmpwi     r3, 0x6C
  beq-      .loc_0x2AC
  b         .loc_0x2E0

.loc_0x288:
  li        r0, 0x2
  stb       r0, 0x18(r1)
  lbz       r0, 0x1(r31)
  cmpwi     r0, 0x68
  bne-      .loc_0x2E4
  stb       r4, 0x18(r1)
  lbzu      r3, 0x1(r31)
  extsb     r3, r3
  b         .loc_0x2E4

.loc_0x2AC:
  li        r0, 0x3
  stb       r0, 0x18(r1)
  lbz       r0, 0x1(r31)
  cmpwi     r0, 0x6C
  bne-      .loc_0x2E4
  li        r0, 0x4
  stb       r0, 0x18(r1)
  lbzu      r3, 0x1(r31)
  extsb     r3, r3
  b         .loc_0x2E4

.loc_0x2D4:
  li        r0, 0x5
  stb       r0, 0x18(r1)
  b         .loc_0x2E4

.loc_0x2E0:
  li        r4, 0

.loc_0x2E4:
  cmpwi     r4, 0
  beq-      .loc_0x2F4
  lbzu      r3, 0x1(r31)
  extsb     r3, r3

.loc_0x2F4:
  subi      r0, r3, 0x45
  stb       r3, 0x19(r1)
  cmplwi    r0, 0x33
  bgt-      .loc_0x490
  lis       r3, 0x802F
  subi      r3, r3, 0x6DF8
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lbz       r0, 0x18(r1)
  cmplwi    r0, 0x5
  bne-      .loc_0x334
  li        r0, 0xFF
  stb       r0, 0x19(r1)
  b         .loc_0x498

.loc_0x334:
  lbz       r0, 0x16(r1)
  cmplwi    r0, 0
  bne-      .loc_0x34C
  li        r0, 0x1
  stw       r0, 0x20(r1)
  b         .loc_0x498

.loc_0x34C:
  lbz       r0, 0x14(r1)
  cmplwi    r0, 0x2
  bne-      .loc_0x498
  li        r0, 0x1
  stb       r0, 0x14(r1)
  b         .loc_0x498
  lbz       r0, 0x18(r1)
  cmplwi    r0, 0x2
  beq-      .loc_0x378
  cmplwi    r0, 0x4
  bne-      .loc_0x384

.loc_0x378:
  li        r0, 0xFF
  stb       r0, 0x19(r1)
  b         .loc_0x498

.loc_0x384:
  lbz       r0, 0x16(r1)
  cmplwi    r0, 0
  bne-      .loc_0x498
  li        r0, 0x6
  stw       r0, 0x20(r1)
  b         .loc_0x498
  lwz       r0, 0x20(r1)
  cmpwi     r0, 0
  bne-      .loc_0x3B0
  li        r0, 0x1
  stw       r0, 0x20(r1)

.loc_0x3B0:
  lbz       r0, 0x18(r1)
  cmplwi    r0, 0x2
  beq-      .loc_0x3CC
  cmplwi    r0, 0x4
  beq-      .loc_0x3CC
  cmplwi    r0, 0x1
  bne-      .loc_0x3D8

.loc_0x3CC:
  li        r0, 0xFF
  stb       r0, 0x19(r1)
  b         .loc_0x498

.loc_0x3D8:
  lbz       r0, 0x16(r1)
  cmplwi    r0, 0
  bne-      .loc_0x498
  li        r0, 0x6
  stw       r0, 0x20(r1)
  b         .loc_0x498
  li        r0, 0x78
  stb       r0, 0x19(r1)
  li        r0, 0x1
  li        r3, 0x3
  stb       r0, 0x17(r1)
  li        r0, 0x8
  stb       r3, 0x18(r1)
  stw       r0, 0x20(r1)
  b         .loc_0x498
  lbz       r3, 0x18(r1)
  cmplwi    r3, 0x3
  bne-      .loc_0x42C
  li        r0, 0x6
  stb       r0, 0x18(r1)
  b         .loc_0x498

.loc_0x42C:
  lbz       r0, 0x16(r1)
  cmplwi    r0, 0
  bne-      .loc_0x440
  cmplwi    r3, 0
  beq-      .loc_0x498

.loc_0x440:
  li        r0, 0xFF
  stb       r0, 0x19(r1)
  b         .loc_0x498
  lbz       r0, 0x18(r1)
  cmplwi    r0, 0x3
  bne-      .loc_0x464
  li        r0, 0x6
  stb       r0, 0x18(r1)
  b         .loc_0x498

.loc_0x464:
  cmplwi    r0, 0
  beq-      .loc_0x498
  li        r0, 0xFF
  stb       r0, 0x19(r1)
  b         .loc_0x498
  lbz       r0, 0x18(r1)
  cmplwi    r0, 0x5
  bne-      .loc_0x498
  li        r0, 0xFF
  stb       r0, 0x19(r1)
  b         .loc_0x498

.loc_0x490:
  li        r0, 0xFF
  stb       r0, 0x19(r1)

.loc_0x498:
  lwz       r4, 0x14(r1)
  addi      r3, r31, 0x1
  lwz       r0, 0x18(r1)
  stw       r4, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r4, 0x1C(r1)
  lwz       r0, 0x20(r1)
  stw       r4, 0x8(r30)
  stw       r0, 0xC(r30)

.loc_0x4BC:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  mtlr      r0
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  blr
*/
}
