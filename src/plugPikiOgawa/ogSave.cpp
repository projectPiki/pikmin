

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80195740
 * Size:	00073C
 */
void zen::ogSaveMgr::ogSaveMgr()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE0(r1)
  stw       r31, 0xDC(r1)
  addi      r31, r3, 0
  stw       r30, 0xD8(r1)
  stw       r29, 0xD4(r1)
  li        r29, 0
  stw       r28, 0xD0(r1)
  stw       r29, 0x90(r3)
  lis       r3, 0x802D
  addi      r30, r3, 0x6070
  stb       r29, 0x30(r31)
  li        r3, 0xF8
  bl        -0x14E774
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x98
  addi      r3, r1, 0xC8
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x1DE8C
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0xC8
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x1B210
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  stb       r29, 0xEC(r28)
  stw       r29, 0xF0(r28)
  stw       r29, 0xF4(r28)

.loc_0x98:
  stw       r28, 0x8(r31)
  addi      r4, r30, 0x1C
  li        r5, 0x1
  lwz       r3, 0x8(r31)
  li        r6, 0x1
  li        r7, 0x1
  bl        0x1D410
  li        r0, -0x1
  stw       r0, 0x0(r31)
  lis       r29, 0x6865
  addi      r4, r29, 0x3030
  lwz       r3, 0x8(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x34(r31)
  addi      r4, r29, 0x3031
  li        r5, 0x1
  lwz       r3, 0x8(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x38(r31)
  lis       r29, 0x6873
  addi      r4, r29, 0x3030
  lwz       r3, 0x8(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3C(r31)
  addi      r4, r29, 0x3031
  li        r5, 0x1
  lwz       r3, 0x8(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x40(r31)
  lis       r3, 0x7365
  addi      r4, r3, 0x5F63
  lwz       r3, 0x8(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x4C(r31)
  lis       r3, 0x6261
  addi      r4, r3, 0x636B
  lwz       r3, 0x8(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x70(r31)
  lis       r29, 0x7361
  addi      r4, r29, 0x5F63
  lwz       r3, 0x8(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x50(r31)
  addi      r4, r29, 0x5F73
  li        r5, 0x1
  lwz       r3, 0x8(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x54(r31)
  addi      r4, r29, 0x6B63
  li        r5, 0x1
  lwz       r3, 0x8(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x58(r31)
  addi      r4, r29, 0x6B73
  li        r5, 0x1
  lwz       r3, 0x8(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x5C(r31)
  lis       r3, 0x3177
  li        r29, 0x1
  lwz       r6, 0x34(r31)
  li        r0, 0
  addi      r4, r3, 0x696E
  lbz       r3, 0xC(r6)
  rlwimi    r3,r29,7,24,24
  li        r5, 0x1
  stb       r3, 0xC(r6)
  lwz       r6, 0x38(r31)
  lbz       r3, 0xC(r6)
  rlwimi    r3,r29,7,24,24
  stb       r3, 0xC(r6)
  lwz       r6, 0x3C(r31)
  lbz       r3, 0xC(r6)
  rlwimi    r3,r29,7,24,24
  stb       r3, 0xC(r6)
  lwz       r6, 0x40(r31)
  lbz       r3, 0xC(r6)
  rlwimi    r3,r29,7,24,24
  stb       r3, 0xC(r6)
  lwz       r3, 0x70(r31)
  stb       r0, 0xF0(r3)
  lwz       r3, 0x8(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x78(r31)
  li        r3, 0xC4
  lwz       r4, 0x78(r31)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r29,7,24,24
  stb       r0, 0xC(r4)
  lwz       r6, 0x78(r31)
  lha       r4, 0x18(r6)
  lha       r0, 0x1C(r6)
  lha       r5, 0x1A(r6)
  sub       r0, r0, r4
  lha       r4, 0x1E(r6)
  srawi     r0, r0, 0x1
  addze     r0, r0
  sub       r5, r4, r5
  extsh     r4, r0
  srawi     r0, r5, 0x1
  sth       r4, 0xB8(r6)
  addze     r0, r0
  extsh     r0, r0
  sth       r0, 0xBA(r6)
  lfs       f1, -0x4DC8(r2)
  lwz       r4, 0x78(r31)
  fmr       f0, f1
  stfs      f1, 0xC0(r4)
  stfs      f1, 0xC4(r4)
  stfs      f0, 0xC8(r4)
  bl        -0x14EA28
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x318
  lwz       r4, 0x8(r31)
  li        r8, 0x1
  lwz       r5, 0x34(r31)
  li        r9, 0x1
  lwz       r6, 0x38(r31)
  lwz       r7, 0x4C(r31)
  bl        0xE10

.loc_0x318:
  stw       r28, 0x18(r31)
  lis       r3, 0x6368
  addi      r4, r3, 0x7569
  lwz       r3, 0x8(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x80(r31)
  li        r5, 0x1
  li        r3, 0x20
  lwz       r4, 0x80(r31)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  lwz       r6, 0x80(r31)
  lha       r4, 0x18(r6)
  lha       r0, 0x1C(r6)
  lha       r5, 0x1A(r6)
  sub       r0, r0, r4
  lha       r4, 0x1E(r6)
  srawi     r0, r0, 0x1
  addze     r0, r0
  sub       r5, r4, r5
  extsh     r4, r0
  srawi     r0, r5, 0x1
  sth       r4, 0xB8(r6)
  addze     r0, r0
  extsh     r0, r0
  sth       r0, 0xBA(r6)
  lfs       f1, -0x4DC8(r2)
  lwz       r4, 0x80(r31)
  fmr       f0, f1
  stfs      f1, 0xC0(r4)
  stfs      f1, 0xC4(r4)
  stfs      f0, 0xC8(r4)
  bl        -0x14EAE8
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x3C8
  lwz       r4, 0x50(r31)
  lbz       r5, 0xF7(r4)
  bl        -0x16064

.loc_0x3C8:
  stw       r28, 0x60(r31)
  li        r3, 0x20
  bl        -0x14EB0C
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x3EC
  lwz       r4, 0x54(r31)
  lbz       r5, 0xF7(r4)
  bl        -0x16088

.loc_0x3EC:
  stw       r28, 0x64(r31)
  li        r3, 0x20
  bl        -0x14EB30
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x410
  lwz       r4, 0x58(r31)
  li        r5, 0xFF
  bl        -0x160AC

.loc_0x410:
  stw       r28, 0x68(r31)
  li        r3, 0x20
  bl        -0x14EB54
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x434
  lwz       r4, 0x5C(r31)
  li        r5, 0xFF
  bl        -0x160D0

.loc_0x434:
  stw       r28, 0x6C(r31)
  li        r3, 0xF8
  bl        -0x14EB78
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x4A0
  addi      r3, r1, 0x7C
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x1DA88
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x7C
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x1AE0C
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x4A0:
  stw       r28, 0x24(r31)
  addi      r4, r30, 0x34
  li        r5, 0
  lwz       r3, 0x24(r31)
  li        r6, 0
  li        r7, 0x1
  bl        0x1D008
  lwz       r3, 0x24(r31)
  lis       r4, 0x626C
  addi      r4, r4, 0x636B
  lwz       r12, 0x0(r3)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x28(r31)
  li        r0, 0xFF
  li        r3, 0xF8
  lwz       r4, 0x28(r31)
  stb       r0, 0xF0(r4)
  bl        -0x14EC2C
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x554
  addi      r3, r1, 0x70
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x1D9D4
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x70
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x1AD58
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  li        r0, 0
  stb       r0, 0xEC(r28)
  stw       r0, 0xF0(r28)
  stw       r0, 0xF4(r28)

.loc_0x554:
  stw       r28, 0xC(r31)
  addi      r4, r30, 0x4C
  li        r5, 0x1
  lwz       r3, 0xC(r31)
  li        r6, 0x1
  li        r7, 0x1
  bl        0x1CF54
  lwz       r3, 0xC(r31)
  lis       r30, 0x6865
  addi      r4, r30, 0x3030
  lwz       r12, 0x0(r3)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x44(r31)
  addi      r4, r30, 0x3031
  li        r5, 0x1
  lwz       r3, 0xC(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x48(r31)
  lis       r3, 0x3277
  addi      r4, r3, 0x696E
  lwz       r3, 0xC(r31)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x7C(r31)
  lis       r3, 0x6261
  li        r7, 0x1
  lwz       r6, 0x7C(r31)
  addi      r4, r3, 0x636B
  li        r5, 0x1
  lbz       r0, 0xC(r6)
  rlwimi    r0,r7,7,24,24
  stb       r0, 0xC(r6)
  lwz       r7, 0x7C(r31)
  lha       r3, 0x18(r7)
  lha       r0, 0x1C(r7)
  lha       r6, 0x1A(r7)
  sub       r0, r0, r3
  lha       r3, 0x1E(r7)
  srawi     r0, r0, 0x1
  addze     r0, r0
  sub       r6, r3, r6
  extsh     r3, r0
  srawi     r0, r6, 0x1
  sth       r3, 0xB8(r7)
  addze     r0, r0
  extsh     r0, r0
  sth       r0, 0xBA(r7)
  lfs       f1, -0x4DC8(r2)
  lwz       r3, 0x7C(r31)
  fmr       f0, f1
  stfs      f1, 0xC0(r3)
  stfs      f1, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lwz       r3, 0xC(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x74(r31)
  li        r0, 0
  li        r3, 0xC4
  lwz       r4, 0x74(r31)
  stb       r0, 0xF0(r4)
  bl        -0x14EDB0
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x6A0
  lwz       r4, 0xC(r31)
  li        r8, 0x1
  lwz       r5, 0x44(r31)
  li        r9, 0x1
  lwz       r6, 0x48(r31)
  lwz       r7, 0x4C(r31)
  bl        0xA88

.loc_0x6A0:
  stw       r28, 0x1C(r31)
  li        r3, 0x10C
  bl        -0x14EDE4
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x6BC
  bl        -0x8DAC

.loc_0x6BC:
  stw       r28, 0x20(r31)
  li        r3, 0x18
  bl        -0x14EE00
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x6D8
  bl        0x5D74C

.loc_0x6D8:
  stw       r28, 0x2C(r31)
  lwz       r3, 0x2C(r31)
  bl        0x5DB80
  li        r3, 0x18
  bl        -0x14EE24
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x6FC
  bl        -0x28A4

.loc_0x6FC:
  stw       r28, 0x84(r31)
  li        r4, -0x1
  li        r0, 0
  lfs       f0, -0x4DC8(r2)
  mr        r3, r31
  stfs      f0, 0x10(r31)
  stw       r4, 0x4(r31)
  sth       r0, 0x14(r31)
  lwz       r0, 0xE4(r1)
  lwz       r31, 0xDC(r1)
  lwz       r30, 0xD8(r1)
  lwz       r29, 0xD4(r1)
  lwz       r28, 0xD0(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80195E7C
 * Size:	0000C0
 */
void zen::ogSaveMgr::start()
{
/*
.loc_0x0:
  li        r6, 0x1
  stw       r6, 0x0(r3)
  li        r5, 0
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r3)
  lwz       r4, 0x78(r3)
  stfs      f0, 0xC0(r4)
  stfs      f0, 0xC4(r4)
  stfs      f0, 0xC8(r4)
  lwz       r4, 0x78(r3)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r4)
  lwz       r4, 0x7C(r3)
  stfs      f0, 0xC0(r4)
  stfs      f0, 0xC4(r4)
  stfs      f0, 0xC8(r4)
  lwz       r4, 0x7C(r3)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r4)
  lwz       r4, 0x34(r3)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r4)
  lwz       r4, 0x38(r3)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r4)
  lwz       r4, 0x3C(r3)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r4)
  lwz       r4, 0x40(r3)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r4)
  lwz       r4, 0x50(r3)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  lwz       r4, 0x54(r3)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  lwz       r3, 0x70(r3)
  stb       r5, 0xF0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
void zen::ogSaveMgr::startDirectSave(short)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80195F3C
 * Size:	000834
 */
void zen::ogSaveMgr::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xD0(r1)
  stmw      r27, 0xBC(r1)
  mr        r29, r3
  addi      r30, r4, 0
  lwz       r3, 0x0(r3)
  cmpwi     r3, -0x1
  bne-      .loc_0x28
  b         .loc_0x820

.loc_0x28:
  cmpwi     r3, 0xC
  blt-      .loc_0x40
  li        r0, -0x1
  stw       r0, 0x0(r29)
  lwz       r3, 0x0(r29)
  b         .loc_0x820

.loc_0x40:
  lwz       r3, 0x24(r29)
  bl        0x1CBD0
  lwz       r3, 0x2C(r29)
  mr        r4, r30
  bl        0x5D6C8
  rlwinm.   r0,r3,0,24,31
  addi      r31, r3, 0
  bne-      .loc_0x68
  lwz       r3, 0x0(r29)
  b         .loc_0x820

.loc_0x68:
  lwz       r3, 0x84(r29)
  addi      r4, r30, 0
  addi      r5, r29, 0x88
  bl        -0x2868
  subi      r0, r3, 0x2
  cmplwi    r0, 0x2
  bgt-      .loc_0xBC
  lis       r3, 0x803A
  lwz       r0, 0x8C(r29)
  subi      r5, r3, 0x2848
  stb       r0, 0x1C7(r5)
  li        r3, 0x3
  li        r0, 0
  lwz       r4, 0x88(r29)
  addi      r4, r4, 0x1
  stb       r4, 0xB5(r5)
  stw       r3, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  stb       r0, 0x30(r29)
  b         .loc_0x114

.loc_0xBC:
  cmpwi     r3, 0x5
  bne-      .loc_0xDC
  li        r0, 0xD
  stw       r0, 0x0(r29)
  li        r0, 0
  stb       r0, 0x30(r29)
  lwz       r3, 0x0(r29)
  b         .loc_0x820

.loc_0xDC:
  cmpwi     r3, 0x1
  bne-      .loc_0xFC
  li        r0, 0xC
  stw       r0, 0x0(r29)
  li        r0, 0
  stb       r0, 0x30(r29)
  lwz       r3, 0x0(r29)
  b         .loc_0x820

.loc_0xFC:
  cmpwi     r3, -0x1
  beq-      .loc_0x114
  li        r0, 0x1
  stb       r0, 0x30(r29)
  lwz       r3, 0x0(r29)
  b         .loc_0x820

.loc_0x114:
  lwz       r3, 0x20(r29)
  mr        r4, r30
  bl        -0x7F7C
  cmpwi     r3, 0x15
  bne-      .loc_0x14C
  lwz       r3, 0x84(r29)
  bl        -0x2974
  li        r0, 0x1
  stb       r0, 0x30(r29)
  li        r0, 0x3
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  b         .loc_0x18C

.loc_0x14C:
  cmpwi     r3, 0x14
  bne-      .loc_0x164
  li        r0, 0xD
  stw       r0, 0x0(r29)
  lwz       r3, 0x0(r29)
  b         .loc_0x820

.loc_0x164:
  cmpwi     r3, 0x13
  bne-      .loc_0x17C
  li        r0, 0xC
  stw       r0, 0x0(r29)
  lwz       r3, 0x0(r29)
  b         .loc_0x820

.loc_0x17C:
  cmpwi     r3, -0x1
  beq-      .loc_0x18C
  lwz       r3, 0x0(r29)
  b         .loc_0x820

.loc_0x18C:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x10(r29)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x10(r29)
  lwz       r3, 0x8(r29)
  bl        0x1CA70
  lwz       r3, 0x18(r29)
  mr        r4, r30
  bl        0xD6C
  mr        r27, r3
  lwz       r3, 0xC(r29)
  bl        0x1CA58
  lwz       r3, 0x1C(r29)
  mr        r4, r30
  bl        0xD54
  mr        r28, r3
  lwz       r3, 0x60(r29)
  bl        -0x16510
  lwz       r3, 0x64(r29)
  bl        -0x16518
  lwz       r3, 0x68(r29)
  bl        -0x16520
  lwz       r3, 0x6C(r29)
  bl        -0x16528
  lwz       r0, 0x0(r29)
  cmplwi    r0, 0xB
  bgt-      .loc_0x81C
  lis       r3, 0x802D
  addi      r3, r3, 0x60D4
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lfs       f1, 0x10(r29)
  lfs       f0, -0x4DC4(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x24C
  li        r0, 0
  stw       r0, 0x0(r29)
  lwz       r3, 0x78(r29)
  lfs       f0, -0x4DC0(r2)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lwz       r3, 0x18(r29)
  bl        0xAC8
  b         .loc_0x81C

.loc_0x24C:
  fdivs     f2, f1, f0
  lwz       r3, 0x78(r29)
  lis       r0, 0x4330
  stfs      f2, 0xC0(r3)
  stfs      f2, 0xC4(r3)
  stfs      f2, 0xC8(r3)
  lwz       r3, 0x4C(r29)
  lfd       f1, -0x4DB8(r2)
  lbz       r4, 0xF7(r3)
  lwz       r3, 0x70(r29)
  stw       r4, 0xB4(r1)
  stw       r0, 0xB0(r1)
  lfd       f0, 0xB0(r1)
  fsubs     f0, f0, f1
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0xA8(r1)
  lwz       r0, 0xAC(r1)
  stfd      f0, 0xA0(r1)
  stb       r0, 0xF0(r3)
  b         .loc_0x81C
  lfs       f0, 0x10(r29)
  lfs       f1, -0x4DC4(r2)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x318
  li        r0, 0x4
  stw       r0, 0x0(r29)
  li        r5, 0x1
  li        r4, 0x1
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  lwz       r3, 0x78(r29)
  lfs       f0, -0x4DC0(r2)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lwz       r3, 0x50(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x54(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x60(r29)
  bl        -0x1671C
  lwz       r3, 0x68(r29)
  li        r4, 0x1
  lfs       f1, -0x4DC4(r2)
  bl        -0x1672C
  b         .loc_0x81C

.loc_0x318:
  fdivs     f2, f0, f1
  lwz       r3, 0x78(r29)
  lis       r0, 0x4330
  stfs      f2, 0xC0(r3)
  stfs      f2, 0xC4(r3)
  stfs      f2, 0xC8(r3)
  lwz       r3, 0x4C(r29)
  lfd       f1, -0x4DB8(r2)
  lbz       r4, 0xF7(r3)
  lwz       r3, 0x70(r29)
  stw       r4, 0xA4(r1)
  stw       r0, 0xA0(r1)
  lfd       f0, 0xA0(r1)
  fsubs     f0, f0, f1
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0xA8(r1)
  lwz       r0, 0xAC(r1)
  stb       r0, 0xF0(r3)
  b         .loc_0x81C
  lfs       f1, 0x10(r29)
  lfs       f0, -0x4DC4(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x398
  lwz       r0, 0x4(r29)
  stw       r0, 0x0(r29)
  lwz       r3, 0x78(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  b         .loc_0x81C

.loc_0x398:
  fdivs     f0, f1, f0
  lfs       f1, -0x4DC0(r2)
  lwz       r3, 0x78(r29)
  lis       r0, 0x4330
  fsubs     f2, f1, f0
  stfs      f2, 0xC0(r3)
  stfs      f2, 0xC4(r3)
  stfs      f2, 0xC8(r3)
  lwz       r3, 0x4C(r29)
  lfd       f1, -0x4DB8(r2)
  lbz       r4, 0xF7(r3)
  lwz       r3, 0x70(r29)
  stw       r4, 0xA4(r1)
  stw       r0, 0xA0(r1)
  lfd       f0, 0xA0(r1)
  fsubs     f0, f0, f1
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0xA8(r1)
  lwz       r0, 0xAC(r1)
  stb       r0, 0xF0(r3)
  b         .loc_0x81C
  cmpwi     r27, 0x5
  bne-      .loc_0x4E8
  li        r0, 0x4
  stw       r0, 0x0(r29)
  li        r6, 0
  li        r5, 0x1
  lfs       f0, -0x4DC8(r2)
  li        r4, 0x1
  stfs      f0, 0x10(r29)
  lwz       r3, 0x34(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x38(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x3C(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x40(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r6,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x50(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x54(r29)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x60(r29)
  lfs       f1, -0x4DC4(r2)
  bl        -0x16898
  lwz       r3, 0x68(r29)
  li        r4, 0x1
  lfs       f1, -0x4DC4(r2)
  bl        -0x168A8
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r3, r3, 0x24
  bl        -0x12071C
  rlwinm    r0,r3,0,24,31
  cntlzw    r0, r0
  rlwinm.   r0,r0,27,24,31
  bne-      .loc_0x81C
  lwz       r3, 0x20(r29)
  bl        -0x86C8
  lwz       r3, 0x20(r29)
  mr        r4, r30
  bl        -0x8320
  cmpwi     r3, 0x15
  bne-      .loc_0x81C
  lwz       r3, 0x84(r29)
  bl        -0x2D18
  li        r0, 0x3
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  b         .loc_0x81C

.loc_0x4E8:
  cmpwi     r27, 0x6
  bne-      .loc_0x504
  li        r0, 0x7
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  b         .loc_0x81C

.loc_0x504:
  cmpwi     r27, 0x4
  bne-      .loc_0x81C
  li        r3, 0x11D
  bl        -0xF10D8
  li        r0, 0xC
  stw       r0, 0x4(r29)
  li        r0, 0x2
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  b         .loc_0x81C
  lfs       f2, 0x10(r29)
  lfs       f1, -0x4DC0(r2)
  fcmpo     cr0, f2, f1
  bge-      .loc_0x568
  lfs       f0, -0x4DBC(r2)
  fmuls     f0, f0, f2
  fcmpo     cr0, f0, f1
  ble-      .loc_0x554
  fmr       f0, f1

.loc_0x554:
  lwz       r3, 0x80(r29)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  b         .loc_0x81C

.loc_0x568:
  li        r0, 0x5
  stw       r0, 0x0(r29)
  li        r3, 0x128
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  bl        -0xF1144
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r3, r3, 0x24
  bl        -0x121FB4
  b         .loc_0x81C
  lwz       r4, 0x80(r29)
  li        r3, 0x129
  lfs       f0, -0x4DC0(r2)
  stfs      f0, 0xC0(r4)
  stfs      f0, 0xC4(r4)
  stfs      f0, 0xC8(r4)
  bl        -0xF1174
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r3, r3, 0x24
  bl        -0x11FAD0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x5F0
  lwz       r3, 0x2C(r29)
  lfs       f1, -0x4DC0(r2)
  bl        0x5D374
  li        r0, 0xC
  stw       r0, 0x4(r29)
  li        r0, 0x2
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  b         .loc_0x81C

.loc_0x5F0:
  li        r0, 0x6
  stw       r0, 0x0(r29)
  li        r4, 0x2
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  lwz       r3, 0x60(r29)
  lfs       f1, -0x4DC4(r2)
  bl        -0x16A28
  lwz       r3, 0x68(r29)
  li        r4, 0x2
  lfs       f1, -0x4DC4(r2)
  bl        -0x16A38
  lwz       r3, 0x64(r29)
  li        r4, 0x1
  lfs       f1, -0x4DC4(r2)
  bl        -0x16A48
  lwz       r3, 0x6C(r29)
  li        r4, 0x1
  lfs       f1, -0x4DC4(r2)
  bl        -0x16A58
  b         .loc_0x81C
  lfs       f1, 0x10(r29)
  lfs       f0, -0x4DC0(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x81C
  li        r0, 0xE
  stw       r0, 0x4(r29)
  li        r0, 0x2
  li        r4, 0x2
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  lwz       r3, 0x64(r29)
  lfs       f1, -0x4DC4(r2)
  bl        -0x16A94
  lwz       r3, 0x6C(r29)
  li        r4, 0x2
  lfs       f1, -0x4DC4(r2)
  bl        -0x16AA4
  b         .loc_0x81C
  lfs       f1, 0x10(r29)
  lfs       f0, -0x4DC4(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x6C4
  lwz       r3, 0x78(r29)
  li        r0, 0x8
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  stw       r0, 0x0(r29)
  stfs      f0, 0x10(r29)
  b         .loc_0x81C

.loc_0x6C4:
  fdivs     f0, f1, f0
  lfs       f1, -0x4DC0(r2)
  lwz       r3, 0x78(r29)
  fsubs     f0, f1, f0
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  b         .loc_0x81C
  lfs       f1, 0x10(r29)
  lfs       f0, -0x4DC4(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x71C
  li        r0, 0x9
  stw       r0, 0x0(r29)
  lwz       r3, 0x7C(r29)
  lfs       f0, -0x4DC0(r2)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lwz       r3, 0x1C(r29)
  bl        0x5F8
  b         .loc_0x81C

.loc_0x71C:
  fdivs     f0, f1, f0
  lwz       r3, 0x7C(r29)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  b         .loc_0x81C
  cmpwi     r28, 0x5
  bne-      .loc_0x758
  li        r0, 0xD
  stw       r0, 0x4(r29)
  li        r0, 0xA
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  b         .loc_0x81C

.loc_0x758:
  cmpwi     r28, 0x6
  bne-      .loc_0x77C
  li        r0, 0xF
  stw       r0, 0x4(r29)
  li        r0, 0xA
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  b         .loc_0x81C

.loc_0x77C:
  cmpwi     r28, 0x4
  bne-      .loc_0x81C
  li        r3, 0x11D
  bl        -0xF1350
  li        r0, 0x1
  stw       r0, 0x4(r29)
  li        r0, 0xA
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)
  b         .loc_0x81C
  lfs       f1, 0x10(r29)
  lfs       f0, -0x4DC4(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x7DC
  lwz       r3, 0x7C(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  lwz       r0, 0x4(r29)
  stw       r0, 0x0(r29)
  stfs      f0, 0x10(r29)
  b         .loc_0x81C

.loc_0x7DC:
  fdivs     f0, f1, f0
  lfs       f1, -0x4DC0(r2)
  lwz       r3, 0x7C(r29)
  fsubs     f0, f1, f0
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  b         .loc_0x81C
  rlwinm.   r0,r31,0,24,31
  bne-      .loc_0x81C
  li        r0, 0xC
  stw       r0, 0x4(r29)
  li        r0, 0x2
  stw       r0, 0x0(r29)
  lfs       f0, -0x4DC8(r2)
  stfs      f0, 0x10(r29)

.loc_0x81C:
  lwz       r3, 0x0(r29)

.loc_0x820:
  lmw       r27, 0xBC(r1)
  lwz       r0, 0xD4(r1)
  addi      r1, r1, 0xD0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80196770
 * Size:	0000F4
 */
void zen::ogSaveMgr::draw(Graphics &)
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
  lwz       r0, 0x0(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0xDC
  lfs       f1, -0x4DB0(r2)
  addi      r3, r1, 0x10
  lfs       f2, -0x4DC0(r2)
  li        r4, 0
  lfs       f3, -0x4DAC(r2)
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x199D8
  addi      r3, r1, 0x10
  bl        0x19AE0
  lbz       r0, 0x30(r30)
  cmplwi    r0, 0
  beq-      .loc_0x84
  lwz       r3, 0x24(r30)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x1C6F4
  lwz       r3, 0x84(r30)
  mr        r4, r31
  bl        -0x2F0C
  b         .loc_0xC4

.loc_0x84:
  lwz       r3, 0x8(r30)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x1C6D0
  lwz       r3, 0xC(r30)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x1C6BC
  lwz       r3, 0x20(r30)
  mr        r4, r31
  bl        -0x7884
  lwz       r3, 0x2C(r30)
  mr        r4, r31
  bl        0x5D014

.loc_0xC4:
  lis       r3, 0x802E
  addi      r0, r3, 0x698
  lis       r3, 0x802E
  stw       r0, 0x10(r1)
  addi      r0, r3, 0x5D4
  stw       r0, 0x10(r1)

.loc_0xDC:
  lwz       r0, 0x104(r1)
  lwz       r31, 0xFC(r1)
  lwz       r30, 0xF8(r1)
  addi      r1, r1, 0x100
  mtlr      r0
  blr
*/
}