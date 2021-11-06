

/*
 * --INFO--
 * Address:	8021616C
 * Size:	000044
 */
void memcmp(void)
{
/*
.loc_0x0:
  subi      r6, r3, 0x1
  subi      r4, r4, 0x1
  addi      r5, r5, 0x1
  b         .loc_0x34

.loc_0x10:
  lbzu      r3, 0x1(r6)
  lbzu      r0, 0x1(r4)
  cmplw     r3, r0
  beq-      .loc_0x34
  bge-      .loc_0x2C
  li        r3, -0x1
  blr       

.loc_0x2C:
  li        r3, 0x1
  blr       

.loc_0x34:
  subic.    r5, r5, 0x1
  bne+      .loc_0x10
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void __memrchr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802161B0
 * Size:	00002C
 */
void memchr(void)
{
/*
.loc_0x0:
  rlwinm    r4,r4,0,24,31
  subi      r3, r3, 0x1
  addi      r5, r5, 0x1
  b         .loc_0x1C

.loc_0x10:
  lbzu      r0, 0x1(r3)
  cmplw     r0, r4
  beqlr-    

.loc_0x1C:
  subic.    r5, r5, 0x1
  bne+      .loc_0x10
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	802161DC
 * Size:	0000DC
 */
void memmove(void)
{
/*
.loc_0x0:
  mflr      r0
  cmplwi    r5, 0x20
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  subc      r3, r4, r31
  subfe     r0, r0, r0
  neg       r3, r0
  blt-      .loc_0x78
  xor       r0, r31, r4
  rlwinm.   r0,r0,0,30,31
  beq-      .loc_0x54
  cmpwi     r3, 0
  bne-      .loc_0x48
  mr        r3, r31
  bl        0x14C
  b         .loc_0x70

.loc_0x48:
  mr        r3, r31
  bl        .loc_0xDC
  b         .loc_0x70

.loc_0x54:
  cmpwi     r3, 0
  bne-      .loc_0x68
  mr        r3, r31
  bl        0x29C
  b         .loc_0x70

.loc_0x68:
  mr        r3, r31
  bl        0x1E4

.loc_0x70:
  mr        r3, r31
  b         .loc_0xC8

.loc_0x78:
  cmpwi     r3, 0
  bne-      .loc_0xA4
  subi      r3, r4, 0x1
  subi      r4, r31, 0x1
  addi      r5, r5, 0x1
  b         .loc_0x98

.loc_0x90:
  lbzu      r0, 0x1(r3)
  stbu      r0, 0x1(r4)

.loc_0x98:
  subic.    r5, r5, 0x1
  bne+      .loc_0x90
  b         .loc_0xC4

.loc_0xA4:
  add       r3, r4, r5
  add       r4, r31, r5
  addi      r5, r5, 0x1
  b         .loc_0xBC

.loc_0xB4:
  lbzu      r0, -0x1(r3)
  stbu      r0, -0x1(r4)

.loc_0xBC:
  subic.    r5, r5, 0x1
  bne+      .loc_0xB4

.loc_0xC4:
  mr        r3, r31

.loc_0xC8:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr       

.loc_0xDC:
*/
}
