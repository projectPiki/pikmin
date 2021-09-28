

/*
 * --INFO--
 * Address:	802140E8
 * Size:	0000C8
 */
void GXBeginDisplayList(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r5, 0x3BC8
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r4, 0
  stw       r28, 0x10(r1)
  addi      r28, r3, 0
  bl        -0x4E74
  lwz       r4, 0x2A68(r13)
  mr        r30, r3
  lwz       r0, 0x4F0(r4)
  cmplwi    r0, 0
  beq-      .loc_0x48
  bl        -0x35E4

.loc_0x48:
  lwz       r4, 0x2A68(r13)
  lbz       r0, 0x4ED(r4)
  cmplwi    r0, 0
  beq-      .loc_0x64
  addi      r3, r31, 0x24
  li        r5, 0x4F4
  bl        -0x210D34

.loc_0x64:
  subi      r0, r29, 0x4
  stw       r28, 0x0(r31)
  add       r0, r28, r0
  stw       r0, 0x4(r31)
  li        r4, 0
  li        r0, 0x1
  stw       r29, 0x8(r31)
  mr        r3, r30
  stw       r4, 0x1C(r31)
  stw       r28, 0x14(r31)
  stw       r28, 0x18(r31)
  lwz       r4, 0x2A68(r13)
  stb       r0, 0x4EC(r4)
  bl        -0x5194
  stw       r30, 0x3468(r13)
  mr        r3, r31
  bl        -0x5428
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	802141B0
 * Size:	0000D4
 */
void GXEndDisplayList(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0x3BC8
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  stw       r28, 0x10(r1)
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x4F0(r3)
  cmplwi    r0, 0
  beq-      .loc_0x38
  bl        -0x369C

.loc_0x38:
  lwz       r4, 0x3420(r13)
  mr        r3, r31
  lwz       r0, 0x14(r4)
  rlwinm    r30,r0,6,31,31
  bl        -0x51EC
  lwz       r3, 0x3468(r13)
  bl        -0x549C
  lwz       r3, 0x2A68(r13)
  lbz       r0, 0x4ED(r3)
  cmplwi    r0, 0
  beq-      .loc_0x94
  bl        -0x1B298
  lwz       r4, 0x2A68(r13)
  mr        r29, r3
  li        r5, 0x4F4
  lwz       r28, 0x8(r4)
  addi      r3, r4, 0
  addi      r4, r31, 0x24
  bl        -0x210E1C
  lwz       r4, 0x2A68(r13)
  mr        r3, r29
  stw       r28, 0x8(r4)
  bl        -0x1B29C

.loc_0x94:
  lwz       r3, 0x2A68(r13)
  li        r0, 0
  cmplwi    r30, 0
  stb       r0, 0x4EC(r3)
  bne-      .loc_0xB0
  lwz       r3, 0x1C(r31)
  b         .loc_0xB4

.loc_0xB0:
  li        r3, 0

.loc_0xB4:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	80214284
 * Size:	000070
 */
void GXCallDisplayList(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  lwz       r5, 0x2A68(r13)
  lwz       r0, 0x4F0(r5)
  cmplwi    r0, 0
  beq-      .loc_0x30
  bl        -0x3768

.loc_0x30:
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x0(r3)
  cmplwi    r0, 0
  beq-      .loc_0x44
  bl        -0x3614

.loc_0x44:
  li        r0, 0x40
  lis       r3, 0xCC01
  stb       r0, -0x8000(r3)
  stw       r30, -0x8000(r3)
  stw       r31, -0x8000(r3)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}