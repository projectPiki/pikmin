

/*
 * --INFO--
 * Address:	8020BEE8
 * Size:	000130
 */
void CreateCallbackFat(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  addi      r28, r3, 0
  lis       r3, 0x803D
  mulli     r5, r28, 0x108
  addi      r0, r3, 0x3420
  add       r31, r0, r5
  lwz       r29, 0xD0(r31)
  li        r27, 0
  mr.       r30, r4
  stw       r27, 0xD0(r31)
  blt-      .loc_0xF4
  mr        r3, r31
  bl        -0x2674
  lhz       r0, 0xBC(r31)
  li        r5, 0x4
  lwz       r4, 0x3408(r13)
  rlwinm    r0,r0,6,0,25
  add       r30, r3, r0
  addi      r3, r30, 0
  bl        -0x208B2C
  lwz       r4, 0x3408(r13)
  addi      r3, r30, 0x4
  li        r5, 0x2
  addi      r4, r4, 0x4
  bl        -0x208B40
  li        r0, 0x4
  stb       r0, 0x34(r30)
  li        r0, -0x1
  lis       r3, 0x8000
  stb       r27, 0x35(r30)
  lhz       r4, 0xBE(r31)
  sth       r4, 0x36(r30)
  stb       r27, 0x7(r30)
  stw       r0, 0x2C(r30)
  sth       r27, 0x30(r30)
  sth       r27, 0x32(r30)
  stw       r0, 0x3C(r30)
  lhz       r0, 0x32(r30)
  rlwinm    r0,r0,0,0,29
  ori       r0, r0, 0x1
  sth       r0, 0x32(r30)
  lwz       r4, 0xC0(r31)
  stw       r27, 0x8(r4)
  lhz       r0, 0x36(r30)
  lwz       r4, 0xC0(r31)
  sth       r0, 0x10(r4)
  lwz       r0, 0xF8(r3)
  rlwinm    r27,r0,30,2,31
  bl        -0xEC14
  addi      r6, r27, 0
  li        r5, 0
  bl        0x8FE8
  stw       r4, 0x28(r30)
  addi      r3, r28, 0
  addi      r4, r29, 0
  bl        -0x2580
  mr.       r30, r3
  bge-      .loc_0x11C

.loc_0xF4:
  addi      r3, r31, 0
  addi      r4, r30, 0
  bl        -0x30C4
  cmplwi    r29, 0
  beq-      .loc_0x11C
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  addi      r4, r30, 0
  blrl      

.loc_0x11C:
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020C018
 * Size:	000218
 */
void CARDCreateAsync(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stmw      r23, 0x24(r1)
  addi      r26, r4, 0
  addi      r25, r3, 0
  addi      r27, r5, 0
  addi      r28, r6, 0
  addi      r29, r7, 0
  addi      r3, r26, 0
  bl        0xD3CC
  cmplwi    r3, 0x20
  ble-      .loc_0x3C
  li        r3, -0xC
  b         .loc_0x204

.loc_0x3C:
  addi      r3, r25, 0
  addi      r4, r1, 0x1C
  bl        -0x31EC
  cmpwi     r3, 0
  bge-      .loc_0x54
  b         .loc_0x204

.loc_0x54:
  cmplwi    r27, 0
  beq-      .loc_0x74
  lwz       r3, 0x1C(r1)
  lwz       r4, 0xC(r3)
  divwu     r0, r27, r4
  mullw     r0, r0, r4
  sub.      r0, r27, r0
  beq-      .loc_0x7C

.loc_0x74:
  li        r3, -0x80
  b         .loc_0x204

.loc_0x7C:
  lis       r4, 0x1
  subi      r30, r4, 0x1
  bl        -0x27EC
  addi      r31, r3, 0
  addi      r24, r31, 0
  li        r23, 0
  b         .loc_0x118

.loc_0x98:
  lbz       r0, 0x0(r24)
  cmplwi    r0, 0xFF
  bne-      .loc_0xB8
  rlwinm    r0,r30,0,16,31
  cmplwi    r0, 0xFFFF
  bne-      .loc_0x110
  mr        r30, r23
  b         .loc_0x110

.loc_0xB8:
  lwz       r4, 0x3408(r13)
  addi      r3, r24, 0
  li        r5, 0x4
  bl        0xA090
  cmpwi     r3, 0
  bne-      .loc_0x110
  lwz       r4, 0x3408(r13)
  addi      r3, r24, 0x4
  li        r5, 0x2
  addi      r4, r4, 0x4
  bl        0xA074
  cmpwi     r3, 0
  bne-      .loc_0x110
  addi      r3, r24, 0
  addi      r4, r26, 0
  bl        -0x68C
  cmpwi     r3, 0
  beq-      .loc_0x110
  lwz       r3, 0x1C(r1)
  li        r4, -0x7
  bl        -0x3200
  b         .loc_0x204

.loc_0x110:
  addi      r24, r24, 0x40
  addi      r23, r23, 0x1

.loc_0x118:
  rlwinm    r0,r23,0,16,31
  cmplwi    r0, 0x7F
  blt+      .loc_0x98
  rlwinm    r0,r30,0,16,31
  cmplwi    r0, 0xFFFF
  bne-      .loc_0x140
  lwz       r3, 0x1C(r1)
  li        r4, -0x8
  bl        -0x3230
  b         .loc_0x204

.loc_0x140:
  lwz       r3, 0x1C(r1)
  bl        -0x2CB0
  lwz       r4, 0x1C(r1)
  lhz       r0, 0x6(r3)
  lwz       r3, 0xC(r4)
  mullw     r0, r3, r0
  cmplw     r0, r27
  bge-      .loc_0x170
  addi      r3, r4, 0
  li        r4, -0x9
  bl        -0x3260
  b         .loc_0x204

.loc_0x170:
  cmplwi    r29, 0
  beq-      .loc_0x180
  mr        r0, r29
  b         .loc_0x188

.loc_0x180:
  lis       r3, 0x8020
  addi      r0, r3, 0x7E60

.loc_0x188:
  stw       r0, 0xD0(r4)
  rlwinm    r0,r30,6,10,25
  add       r7, r31, r0
  lwz       r3, 0x1C(r1)
  rlwinm    r29,r30,0,16,31
  addi      r4, r26, 0
  sth       r30, 0xBC(r3)
  addi      r3, r7, 0x8
  li        r5, 0x20
  lwz       r6, 0x1C(r1)
  lwz       r0, 0xC(r6)
  divwu     r0, r27, r0
  sth       r0, 0x38(r7)
  bl        0xD140
  lwz       r4, 0x1C(r1)
  lis       r3, 0x8021
  subi      r5, r3, 0x4118
  stw       r28, 0xC0(r4)
  mr        r3, r25
  stw       r25, 0x0(r28)
  stw       r29, 0x4(r28)
  lwz       r4, 0x1C(r1)
  lwz       r0, 0xC(r4)
  divwu     r4, r27, r0
  bl        -0x2BB0
  mr.       r4, r3
  bge-      .loc_0x200
  lwz       r3, 0x1C(r1)
  bl        -0x32F0
  b         .loc_0x204

.loc_0x200:
  mr        r3, r4

.loc_0x204:
  lmw       r23, 0x24(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020C230
 * Size:	000048
 */
void CARDCreate(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x8020
  stw       r0, 0x4(r1)
  addi      r7, r7, 0x7E64
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  bl        -0x234
  cmpwi     r3, 0
  bge-      .loc_0x2C
  b         .loc_0x34

.loc_0x2C:
  mr        r3, r31
  bl        -0x3134

.loc_0x34:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}
