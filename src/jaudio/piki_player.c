

/*
 * --INFO--
 * Address:	80018120
 * Size:	0000DC
 */
void Jac_Orima_Walk(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  lbz       r0, 0x2C98(r13)
  extsb.    r0, r0
  bne-      .loc_0x30
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2C94(r13)
  stb       r0, 0x2C98(r13)

.loc_0x30:
  lbz       r0, 0x2C9A(r13)
  extsb.    r0, r0
  bne-      .loc_0x4C
  li        r3, 0
  li        r0, 0x1
  stb       r3, 0x2C99(r13)
  stb       r0, 0x2C9A(r13)

.loc_0x4C:
  lwz       r0, 0x2C94(r13)
  li        r3, 0
  stw       r3, 0x2C90(r13)
  cmplwi    r0, 0
  bne-      .loc_0x7C
  lis       r3, 0x1
  addi      r3, r3, 0x8
  bl        -0x7B28
  stw       r3, 0x2C94(r13)
  lwz       r0, 0x2C94(r13)
  cmplwi    r0, 0
  beq-      .loc_0xC8

.loc_0x7C:
  bl        0x2044
  cmpwi     r3, 0
  beq-      .loc_0xC8
  lbz       r0, 0x2C99(r13)
  cmplwi    r0, 0
  bne-      .loc_0xB0
  lwz       r3, 0x2C94(r13)
  rlwinm    r5,r31,0,16,31
  li        r4, 0
  bl        -0x7E40
  li        r0, 0x1
  stb       r0, 0x2C99(r13)
  b         .loc_0xC8

.loc_0xB0:
  lwz       r3, 0x2C94(r13)
  rlwinm    r5,r31,0,16,31
  li        r4, 0
  bl        -0x7E5C
  li        r0, 0
  stb       r0, 0x2C99(r13)

.loc_0xC8:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80018200
 * Size:	000190
 */
void Jac_Orima_Formation(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r30, 0x28(r1)
  addi      r30, r3, 0
  addi      r31, r4, 0
  lbz       r0, 0x2CA4(r13)
  extsb.    r0, r0
  bne-      .loc_0x34
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2CA0(r13)
  stb       r0, 0x2CA4(r13)

.loc_0x34:
  lwz       r0, 0x2C9C(r13)
  cmplwi    r0, 0
  bne-      .loc_0x5C
  lis       r3, 0x1
  addi      r3, r3, 0x7
  bl        -0x7BE8
  stw       r3, 0x2C9C(r13)
  lwz       r0, 0x2C9C(r13)
  cmplwi    r0, 0
  beq-      .loc_0x17C

.loc_0x5C:
  bl        0x1F24
  cmpwi     r3, 0x1
  bne-      .loc_0x70
  li        r30, 0
  li        r31, 0

.loc_0x70:
  bl        -0x1770
  cmpwi     r3, 0x1
  bne-      .loc_0x84
  li        r30, 0
  li        r31, 0

.loc_0x84:
  cmpwi     r30, -0x7F
  bge-      .loc_0x90
  li        r30, -0x7F

.loc_0x90:
  cmpwi     r30, 0x7F
  ble-      .loc_0x9C
  li        r30, 0x7F

.loc_0x9C:
  cmpwi     r31, -0x7F
  bge-      .loc_0xA8
  li        r31, -0x7F

.loc_0xA8:
  cmpwi     r31, 0x7F
  ble-      .loc_0xB4
  li        r31, 0x7F

.loc_0xB4:
  cmpwi     r31, 0
  bge-      .loc_0xC0
  neg       r31, r31

.loc_0xC0:
  mullw     r4, r30, r30
  lis       r0, 0x4330
  lfd       f1, -0x7E48(r2)
  mullw     r3, r31, r31
  add       r3, r4, r3
  xoris     r3, r3, 0x8000
  stw       r3, 0x24(r1)
  stw       r0, 0x20(r1)
  lfd       f0, 0x20(r1)
  fsubs     f1, f0, f1
  bl        -0xA6C8
  fctiwz    f0, f1
  lwz       r3, 0x2C9C(r13)
  rlwinm    r5,r30,0,16,31
  li        r4, 0x2
  stfd      f0, 0x18(r1)
  lwz       r31, 0x1C(r1)
  bl        -0x7F84
  lwz       r3, 0x2C9C(r13)
  rlwinm    r5,r31,0,16,31
  li        r4, 0x3
  bl        -0x7F94
  cmpwi     r30, 0
  bne-      .loc_0x150
  cmpwi     r31, 0
  bne-      .loc_0x150
  lwz       r0, 0x2CA0(r13)
  cmpwi     r0, 0
  beq-      .loc_0x17C
  lwz       r3, 0x2C9C(r13)
  li        r4, 0
  li        r5, 0
  bl        -0x7FC0
  li        r0, 0
  stw       r0, 0x2CA0(r13)
  b         .loc_0x17C

.loc_0x150:
  lwz       r0, 0x2CA0(r13)
  cmpwi     r0, 0
  bne-      .loc_0x174
  lwz       r3, 0x2C9C(r13)
  li        r4, 0
  li        r5, 0x1
  bl        -0x7FE8
  li        r0, 0x1
  stw       r0, 0x2CA0(r13)

.loc_0x174:
  li        r0, 0
  stw       r0, 0x2C90(r13)

.loc_0x17C:
  lwz       r0, 0x34(r1)
  lmw       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800183A0
 * Size:	000250
 */
void Jac_PlayOrimaSe(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  lbz       r0, 0x2CAD(r13)
  extsb.    r0, r0
  bne-      .loc_0x30
  li        r3, 0
  li        r0, 0x1
  stb       r3, 0x2CAC(r13)
  stb       r0, 0x2CAD(r13)

.loc_0x30:
  lbz       r0, 0x2CB4(r13)
  extsb.    r0, r0
  bne-      .loc_0x4C
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2CB0(r13)
  stb       r0, 0x2CB4(r13)

.loc_0x4C:
  lwz       r0, 0x2CA8(r13)
  cmplwi    r0, 0
  bne-      .loc_0x74
  lis       r3, 0x1
  addi      r3, r3, 0xA
  bl        -0x7DA0
  stw       r3, 0x2CA8(r13)
  lwz       r0, 0x2CA8(r13)
  cmplwi    r0, 0
  beq-      .loc_0x23C

.loc_0x74:
  lwz       r0, 0x2CB0(r13)
  cmpwi     r0, 0
  bne-      .loc_0x9C
  lis       r3, 0x8036
  lwz       r4, 0x2CA8(r13)
  addi      r3, r3, 0x37C8
  li        r5, 0
  bl        0x3570
  li        r0, 0x1
  stw       r0, 0x2CB0(r13)

.loc_0x9C:
  rlwinm.   r0,r31,0,16,16
  beq-      .loc_0x114
  lbz       r0, 0x2CBC(r13)
  extsb.    r0, r0
  bne-      .loc_0xC0
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2CB8(r13)
  stb       r0, 0x2CBC(r13)

.loc_0xC0:
  bl        0x1D20
  cmpwi     r3, 0x1
  beq-      .loc_0x23C
  lwz       r0, 0x2CB8(r13)
  cmpwi     r0, 0
  beq-      .loc_0xE0
  cmplwi    r31, 0x8004
  beq-      .loc_0x23C

.loc_0xE0:
  lwz       r3, 0x2CA8(r13)
  rlwinm    r5,r31,0,17,31
  li        r4, 0x1
  bl        -0x810C
  cmplwi    r31, 0x8002
  bne-      .loc_0x100
  li        r0, 0
  stw       r0, 0x2CB8(r13)

.loc_0x100:
  cmplwi    r31, 0x8004
  bne-      .loc_0x23C
  li        r0, 0x1
  stw       r0, 0x2CB8(r13)
  b         .loc_0x23C

.loc_0x114:
  lis       r3, 0x8036
  rlwinm    r4,r31,0,16,31
  addi      r3, r3, 0x37C8
  bl        0x3540
  cmplwi    r31, 0x4
  bne-      .loc_0x214
  li        r3, 0x4
  bl        -0xACD0
  lbz       r0, 0x2CC0(r13)
  lis       r4, 0x1
  rlwinm    r5,r3,0,16,31
  subi      r6, r4, 0x7FF5
  extsb.    r0, r0
  bne-      .loc_0x15C
  li        r3, 0x4
  li        r0, 0x1
  sth       r3, 0x2CBE(r13)
  stb       r0, 0x2CC0(r13)

.loc_0x15C:
  lbz       r0, 0x2CC4(r13)
  extsb.    r0, r0
  bne-      .loc_0x178
  li        r3, 0x5
  li        r0, 0x1
  sth       r3, 0x2CC2(r13)
  stb       r0, 0x2CC4(r13)

.loc_0x178:
  lbz       r0, 0x2CC8(r13)
  extsb.    r0, r0
  bne-      .loc_0x194
  li        r3, 0x6
  li        r0, 0x1
  sth       r3, 0x2CC6(r13)
  stb       r0, 0x2CC8(r13)

.loc_0x194:
  rlwinm    r0,r5,0,30,31
  sth       r0, 0x10(r1)
  lhz       r4, 0x10(r1)
  cmpwi     r4, 0x3
  beq-      .loc_0x1B0
  addis     r6, r4, 0x1
  subi      r6, r6, 0x7FF3

.loc_0x1B0:
  lhz       r0, 0x2CC6(r13)
  lhz       r3, 0x2CC2(r13)
  cmplw     r0, r3
  bne-      .loc_0x1F4
  lhz       r0, 0x2CBE(r13)
  cmplw     r3, r0
  bne-      .loc_0x1F4
  cmplw     r0, r4
  beq-      .loc_0x1E0
  addis     r6, r4, 0x1
  subi      r6, r6, 0x7FF0
  b         .loc_0x1E8

.loc_0x1E0:
  lis       r3, 0x1
  subi      r6, r3, 0x7FEC

.loc_0x1E8:
  li        r0, 0x5
  sth       r0, 0x2CBE(r13)
  b         .loc_0x204

.loc_0x1F4:
  lhz       r0, 0x2CBE(r13)
  sth       r3, 0x2CC6(r13)
  sth       r0, 0x2CC2(r13)
  sth       r4, 0x2CBE(r13)

.loc_0x204:
  lwz       r3, 0x2CA8(r13)
  rlwinm    r5,r6,0,17,31
  li        r4, 0x1
  bl        -0x8230

.loc_0x214:
  cmplwi    r31, 0xC
  bne-      .loc_0x23C
  li        r3, 0
  li        r4, 0x64
  bl        0x57C
  li        r3, 0x1
  li        r4, 0x64
  bl        0x570
  li        r3, 0x28
  bl        -0x1A38

.loc_0x23C:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80018600
 * Size:	000030
 */
void Jac_PauseOrimaSe()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x2CA8(r13)
  cmplwi    r3, 0
  beq-      .loc_0x20
  li        r4, 0x1
  bl        -0x713C

.loc_0x20:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80018640
 * Size:	000030
 */
void Jac_UnPauseOrimaSe()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x2CA8(r13)
  cmplwi    r3, 0
  beq-      .loc_0x20
  li        r4, 0x1
  bl        -0x703C

.loc_0x20:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80018680
 * Size:	0000B8
 */
void Jac_StopOrimaSe(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  lbz       r0, 0x2CD0(r13)
  extsb.    r0, r0
  bne-      .loc_0x30
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2CCC(r13)
  stb       r0, 0x2CD0(r13)

.loc_0x30:
  lbz       r0, 0x2CD8(r13)
  extsb.    r0, r0
  bne-      .loc_0x4C
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2CD4(r13)
  stb       r0, 0x2CD8(r13)

.loc_0x4C:
  lwz       r0, 0x2CD4(r13)
  cmpwi     r0, 0
  bne-      .loc_0x8C
  lis       r3, 0x1
  addi      r3, r3, 0xA
  bl        -0x8080
  stw       r3, 0x2CCC(r13)
  lwz       r4, 0x2CCC(r13)
  cmplwi    r4, 0
  beq-      .loc_0xA4
  lis       r3, 0x8036
  li        r5, 0x2
  addi      r3, r3, 0x3834
  bl        0x32A0
  li        r0, 0x1
  stw       r0, 0x2CD4(r13)

.loc_0x8C:
  rlwinm.   r0,r31,0,16,16
  bne-      .loc_0xA4
  lis       r3, 0x8036
  rlwinm    r4,r31,0,16,31
  addi      r3, r3, 0x3834
  bl        0x32E0

.loc_0xA4:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80018740
 * Size:	000078
 */
void Jac_Piki_Number(void)
{
/*
.loc_0x0:
  cmplwi    r3, 0x64
  blt-      .loc_0x14
  li        r0, 0x1D
  stw       r0, 0x2CDC(r13)
  blr       

.loc_0x14:
  cmplwi    r3, 0x32
  blt-      .loc_0x34
  subi      r3, r3, 0x32
  li        r0, 0xA
  divwu     r3, r3, r0
  addi      r0, r3, 0x19
  stw       r0, 0x2CDC(r13)
  blr       

.loc_0x34:
  cmplwi    r3, 0x19
  blt-      .loc_0x54
  subi      r3, r3, 0x19
  li        r0, 0x5
  divwu     r3, r3, r0
  addi      r0, r3, 0x14
  stw       r0, 0x2CDC(r13)
  blr       

.loc_0x54:
  cmplwi    r3, 0xF
  blt-      .loc_0x70
  subi      r0, r3, 0xF
  rlwinm    r3,r0,31,1,31
  addi      r0, r3, 0xF
  stw       r0, 0x2CDC(r13)
  blr       

.loc_0x70:
  stw       r3, 0x2CDC(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	800187C0
 * Size:	0001B4
 */
void Jac_UpdatePikiGaya()
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x8036
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0x37C8
  lbz       r0, 0x2CE8(r13)
  extsb.    r0, r0
  bne-      .loc_0x34
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2CE4(r13)
  stb       r0, 0x2CE8(r13)

.loc_0x34:
  lbz       r0, 0x2CF0(r13)
  extsb.    r0, r0
  bne-      .loc_0x50
  lfs       f0, -0x7E40(r2)
  li        r0, 0x1
  stb       r0, 0x2CF0(r13)
  stfs      f0, 0x2CEC(r13)

.loc_0x50:
  bl        0x1030
  cmplwi    r3, 0x5
  beq-      .loc_0x70
  lfs       f1, -0x7E40(r2)
  addi      r3, r31, 0xD8
  li        r4, 0x1
  bl        -0x8048
  b         .loc_0x1A0

.loc_0x70:
  bl        0x1950
  cmpwi     r3, 0x1
  bne-      .loc_0x90
  lfs       f1, -0x7E40(r2)
  addi      r3, r31, 0xD8
  li        r4, 0x1
  bl        -0x8068
  b         .loc_0x1A0

.loc_0x90:
  lwz       r0, 0x2CE4(r13)
  cmpwi     r0, 0
  bne-      .loc_0xDC
  lis       r3, 0x1
  addi      r3, r3, 0x3
  bl        -0x8204
  stw       r3, 0x2CE0(r13)
  addi      r3, r31, 0xD8
  bl        -0x81B0
  lwz       r3, 0x2CE0(r13)
  addi      r4, r31, 0xD8
  bl        -0x819C
  stw       r3, 0x2CE4(r13)
  lwz       r0, 0x2CE4(r13)
  cmpwi     r0, 0
  beq-      .loc_0x1A0
  addi      r3, r31, 0xD8
  li        r4, 0x1
  bl        -0x7FF8

.loc_0xDC:
  lwz       r0, 0x2C90(r13)
  cmplwi    r0, 0x96
  blt-      .loc_0xF4
  lwz       r4, 0x2CDC(r13)
  cmplwi    r4, 0x1
  bge-      .loc_0x148

.loc_0xF4:
  lfs       f1, 0x2CEC(r13)
  addi      r3, r31, 0xD8
  li        r4, 0x1
  bl        -0x80E0
  lfs       f2, 0x2CEC(r13)
  lfs       f1, -0x7E3C(r2)
  lfs       f0, -0x7E40(r2)
  fsubs     f1, f2, f1
  stfs      f1, 0x2CEC(r13)
  lfs       f1, 0x2CEC(r13)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x128
  stfs      f0, 0x2CEC(r13)

.loc_0x128:
  lwz       r0, 0x2CDC(r13)
  cmplwi    r0, 0
  bne-      .loc_0x194
  lwz       r3, 0x2CE0(r13)
  rlwinm    r5,r0,0,16,31
  li        r4, 0
  bl        -0x8580
  b         .loc_0x194

.loc_0x148:
  cmplwi    r0, 0xF0
  blt-      .loc_0x194
  lwz       r3, 0x2CE0(r13)
  rlwinm    r5,r4,0,16,31
  li        r4, 0
  bl        -0x859C
  lfs       f2, 0x2CEC(r13)
  lfs       f1, -0x7E3C(r2)
  lfs       f0, -0x7E38(r2)
  fadds     f1, f2, f1
  stfs      f1, 0x2CEC(r13)
  lfs       f1, 0x2CEC(r13)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x184
  stfs      f0, 0x2CEC(r13)

.loc_0x184:
  lfs       f1, 0x2CEC(r13)
  addi      r3, r31, 0xD8
  li        r4, 0x1
  bl        -0x8170

.loc_0x194:
  lwz       r3, 0x2C90(r13)
  addi      r0, r3, 0x1
  stw       r0, 0x2C90(r13)

.loc_0x1A0:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}