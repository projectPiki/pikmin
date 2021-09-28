

/*
 * --INFO--
 * Address:	8001DA80
 * Size:	000090
 */
void Jac_SendStreamData(unsigned char *, unsigned long)
{
/*
.loc_0x0:
  lwz       r5, -0x7EC8(r13)
  lwz       r0, 0x18(r5)
  cmplw     r0, r4
  bge-      .loc_0x18
  li        r3, 0
  blr       

.loc_0x18:
  li        r0, 0
  mtctr     r4
  cmplwi    r4, 0
  ble-      .loc_0x68

.loc_0x28:
  lwz       r9, -0x7EC8(r13)
  lbz       r8, 0x0(r3)
  lwz       r6, 0xC(r9)
  lwz       r7, 0x4(r9)
  addi      r5, r6, 0x1
  stw       r5, 0xC(r9)
  stbx      r8, r7, r6
  lwz       r5, -0x7EC8(r13)
  addi      r7, r5, 0xC
  lwz       r5, 0x8(r5)
  lwz       r6, 0x0(r7)
  cmplw     r6, r5
  bne-      .loc_0x60
  stw       r0, 0x0(r7)

.loc_0x60:
  addi      r3, r3, 0x1
  bdnz+     .loc_0x28

.loc_0x68:
  lwz       r5, -0x7EC8(r13)
  li        r3, 0x1
  lwz       r0, 0x18(r5)
  sub       r0, r0, r4
  stw       r0, 0x18(r5)
  lwz       r5, -0x7EC8(r13)
  lwz       r0, 0x14(r5)
  add       r0, r0, r4
  stw       r0, 0x14(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001DB20
 * Size:	000020
 */
void Jac_CheckStreamFree(unsigned long)
{
/*
.loc_0x0:
  lwz       r4, -0x7EC8(r13)
  lwz       r0, 0x18(r4)
  cmplw     r0, r3
  blt-      .loc_0x18
  li        r3, 0x1
  blr       

.loc_0x18:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001DB40
 * Size:	000020
 */
void Jac_CheckStreamRemain(unsigned long)
{
/*
.loc_0x0:
  lwz       r4, -0x7EC8(r13)
  lwz       r0, 0x14(r4)
  cmplw     r0, r3
  bge-      .loc_0x18
  li        r3, 0
  blr       

.loc_0x18:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void Jac_GetStreamRemain()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001DB60
 * Size:	0000C0
 */
void Jac_GetStreamData(unsigned char *, unsigned long)
{
/*
.loc_0x0:
  lwz       r6, -0x7EC8(r13)
  lwz       r0, 0x0(r6)
  cmpwi     r0, 0
  beq-      .loc_0x34
  lwz       r0, 0x8(r6)
  lwz       r5, 0x14(r6)
  rlwinm    r0,r0,31,1,31
  cmplw     r5, r0
  bge-      .loc_0x2C
  li        r3, 0
  blr       

.loc_0x2C:
  li        r0, 0
  stw       r0, 0x0(r6)

.loc_0x34:
  lwz       r5, -0x7EC8(r13)
  lwz       r0, 0x14(r5)
  cmplw     r0, r4
  bge-      .loc_0x48
  mr        r4, r0

.loc_0x48:
  li        r0, 0
  mtctr     r4
  cmplwi    r4, 0
  ble-      .loc_0x98

.loc_0x58:
  lwz       r8, -0x7EC8(r13)
  lwz       r6, 0x10(r8)
  lwz       r7, 0x4(r8)
  addi      r5, r6, 0x1
  stw       r5, 0x10(r8)
  lbzx      r5, r7, r6
  stb       r5, 0x0(r3)
  lwz       r5, -0x7EC8(r13)
  addi      r7, r5, 0x10
  lwz       r5, 0x8(r5)
  lwz       r6, 0x0(r7)
  cmplw     r6, r5
  bne-      .loc_0x90
  stw       r0, 0x0(r7)

.loc_0x90:
  addi      r3, r3, 0x1
  bdnz+     .loc_0x58

.loc_0x98:
  lwz       r5, -0x7EC8(r13)
  mr        r3, r4
  lwz       r0, 0x14(r5)
  sub       r0, r0, r4
  stw       r0, 0x14(r5)
  lwz       r5, -0x7EC8(r13)
  lwz       r0, 0x18(r5)
  add       r0, r0, r4
  stw       r0, 0x18(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001DC20
 * Size:	000044
 */
void Jac_InitStreamData(unsigned char *, unsigned long)
{
/*
.loc_0x0:
  lwz       r6, -0x7EC8(r13)
  li        r5, 0
  li        r0, 0x1
  stw       r3, 0x4(r6)
  lwz       r3, -0x7EC8(r13)
  stw       r4, 0x8(r3)
  lwz       r3, -0x7EC8(r13)
  stw       r5, 0xC(r3)
  lwz       r3, -0x7EC8(r13)
  stw       r5, 0x10(r3)
  lwz       r3, -0x7EC8(r13)
  stw       r5, 0x14(r3)
  lwz       r3, -0x7EC8(r13)
  stw       r4, 0x18(r3)
  lwz       r3, -0x7EC8(r13)
  stw       r0, 0x0(r3)
  blr
*/
}