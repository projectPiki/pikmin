

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
 * Address:	801A17D4
 * Size:	000130
 */
void zen::particleMdlManager::init(unsigned long, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r26, 0x28(r1)
  addi      r26, r4, 0
  rlwinm    r4,r4,7,0,24
  addi      r30, r3, 0
  addi      r29, r26, 0
  addi      r31, r5, 0
  addi      r3, r4, 0x8
  bl        -0x15A7F8
  lis       r4, 0x801A
  lis       r5, 0x801A
  addi      r4, r4, 0x1A64
  addi      r5, r5, 0x1A08
  addi      r7, r29, 0
  li        r6, 0x80
  bl        0x73410
  stw       r3, 0x20(r30)
  li        r27, 0
  li        r28, 0
  b         .loc_0x94

.loc_0x58:
  lwz       r0, 0x20(r30)
  add       r29, r0, r28
  addi      r3, r29, 0
  lwz       r12, 0x0(r29)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r28, r28, 0x80
  addi      r27, r27, 0x1

.loc_0x94:
  cmplw     r27, r26
  blt+      .loc_0x58
  addi      r29, r31, 0
  mulli     r3, r29, 0x34
  addi      r3, r3, 0x8
  bl        -0x15A878
  lis       r4, 0x801A
  lis       r5, 0x801A
  addi      r4, r4, 0x1960
  addi      r5, r5, 0x1904
  addi      r7, r29, 0
  li        r6, 0x34
  bl        0x73390
  li        r27, 0
  stw       r3, 0x24(r30)
  mr        r28, r27
  b         .loc_0x114

.loc_0xD8:
  lwz       r0, 0x24(r30)
  add       r29, r0, r28
  addi      r3, r29, 0
  lwz       r12, 0x0(r29)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x10(r30)
  mr        r4, r29
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r28, r28, 0x34
  addi      r27, r27, 0x1

.loc_0x114:
  cmplw     r27, r31
  blt+      .loc_0xD8
  lmw       r26, 0x28(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801A1904
 * Size:	00005C
 */
void zen::particleChildMdl::~particleChildMdl()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  beq-      .loc_0x44
  lis       r3, 0x802E
  subi      r0, r3, 0x277C
  stw       r0, 0x0(r31)
  beq-      .loc_0x34
  lis       r3, 0x802E
  subi      r0, r3, 0x27B8
  stw       r0, 0x0(r31)

.loc_0x34:
  extsh.    r0, r4
  ble-      .loc_0x44
  mr        r3, r31
  bl        -0x15A798

.loc_0x44:
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801A1960
 * Size:	0000A8
 */
void zen::particleChildMdl::particleChildMdl()
{
/*
.loc_0x0:
  lis       r4, 0x802D
  addi      r0, r4, 0x68DC
  stw       r0, 0x0(r3)
  lis       r5, 0x802E
  subi      r6, r5, 0x27B8
  stw       r3, 0x8(r3)
  lis       r4, 0x802E
  li        r5, 0
  stw       r3, 0x4(r3)
  subi      r0, r4, 0x277C
  stw       r6, 0x0(r3)
  lfs       f1, -0x4C18(r2)
  stfs      f1, 0x14(r3)
  stfs      f1, 0x10(r3)
  stfs      f1, 0xC(r3)
  stfs      f1, 0x20(r3)
  stfs      f1, 0x1C(r3)
  stfs      f1, 0x18(r3)
  lfs       f0, 0x1118(r13)
  stfs      f0, 0xC(r3)
  lfs       f0, 0x111C(r13)
  stfs      f0, 0x10(r3)
  lfs       f0, 0x1120(r13)
  stfs      f0, 0x14(r3)
  lfs       f0, 0x1124(r13)
  stfs      f0, 0x18(r3)
  lfs       f0, 0x1128(r13)
  stfs      f0, 0x1C(r3)
  lfs       f0, 0x112C(r13)
  stfs      f0, 0x20(r3)
  lfs       f0, -0x4C14(r2)
  stfs      f0, 0x24(r3)
  stb       r5, 0x28(r3)
  stb       r5, 0x29(r3)
  stb       r5, 0x2A(r3)
  stb       r5, 0x2B(r3)
  stw       r0, 0x0(r3)
  stfs      f1, 0x2C(r3)
  stb       r5, 0x31(r3)
  stb       r5, 0x30(r3)
  stb       r5, 0x32(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void zen::particleMdlBase::~particleMdlBase()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A1A08
 * Size:	00005C
 */
void zen::particleMdl::~particleMdl()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  beq-      .loc_0x44
  lis       r3, 0x802E
  subi      r0, r3, 0x27D8
  stw       r0, 0x0(r31)
  beq-      .loc_0x34
  lis       r3, 0x802E
  subi      r0, r3, 0x27B8
  stw       r0, 0x0(r31)

.loc_0x34:
  extsh.    r0, r4
  ble-      .loc_0x44
  mr        r3, r31
  bl        -0x15A89C

.loc_0x44:
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801A1A64
 * Size:	000180
 */
void zen::particleMdl::particleMdl()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802E
  stw       r0, 0x4(r1)
  subi      r5, r4, 0x27B8
  li        r4, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  stw       r3, 0x8(r1)
  lis       r3, 0x802D
  addi      r0, r3, 0x68DC
  lwz       r30, 0x8(r1)
  lis       r3, 0x802E
  subi      r6, r3, 0x27D8
  stw       r0, 0x0(r30)
  li        r0, 0x1
  addi      r3, r30, 0x6C
  stw       r30, 0x8(r30)
  stw       r30, 0x4(r30)
  stw       r5, 0x0(r30)
  li        r5, 0x1
  lfs       f2, -0x4C18(r2)
  stfs      f2, 0x14(r30)
  stfs      f2, 0x10(r30)
  stfs      f2, 0xC(r30)
  stfs      f2, 0x20(r30)
  stfs      f2, 0x1C(r30)
  stfs      f2, 0x18(r30)
  lfs       f0, 0x1118(r13)
  stfs      f0, 0xC(r30)
  lfs       f0, 0x111C(r13)
  stfs      f0, 0x10(r30)
  lfs       f0, 0x1120(r13)
  stfs      f0, 0x14(r30)
  lfs       f0, 0x1124(r13)
  stfs      f0, 0x18(r30)
  lfs       f0, 0x1128(r13)
  stfs      f0, 0x1C(r30)
  lfs       f0, 0x112C(r13)
  stfs      f0, 0x20(r30)
  lfs       f1, -0x4C14(r2)
  stfs      f1, 0x24(r30)
  stb       r31, 0x28(r30)
  stb       r31, 0x29(r30)
  stb       r31, 0x2A(r30)
  stb       r31, 0x2B(r30)
  stw       r6, 0x0(r30)
  stfs      f2, 0x3C(r30)
  stfs      f2, 0x38(r30)
  stfs      f2, 0x34(r30)
  stfs      f2, 0x48(r30)
  stfs      f2, 0x44(r30)
  stfs      f2, 0x40(r30)
  stfs      f2, 0x64(r30)
  stfs      f2, 0x60(r30)
  stfs      f2, 0x5C(r30)
  stfs      f2, 0x6C(r30)
  stb       r31, 0x70(r30)
  sth       r0, 0x72(r30)
  stw       r31, 0x74(r30)
  sth       r31, 0x2E(r30)
  sth       r31, 0x2C(r30)
  stfs      f2, 0x30(r30)
  lfs       f0, 0x1130(r13)
  stfs      f0, 0x34(r30)
  lfs       f0, 0x1134(r13)
  stfs      f0, 0x38(r30)
  lfs       f0, 0x1138(r13)
  stfs      f0, 0x3C(r30)
  stfs      f2, 0x54(r30)
  stfs      f2, 0x50(r30)
  stfs      f2, 0x50(r30)
  lfs       f0, 0x113C(r13)
  stfs      f0, 0x5C(r30)
  lfs       f0, 0x1140(r13)
  stfs      f0, 0x60(r30)
  lfs       f0, 0x1144(r13)
  stfs      f0, 0x64(r30)
  sth       r31, 0x58(r30)
  sth       r31, 0x5A(r30)
  stfs      f1, 0x64(r30)
  stb       r31, 0x4C(r30)
  stb       r31, 0x68(r30)
  stb       r31, 0x69(r30)
  stb       r31, 0x6A(r30)
  stb       r31, 0x6B(r30)
  bl        .loc_0x180
  stw       r31, 0x78(r30)
  mr        r3, r30
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0x180:
*/
}

/*
 * --INFO--
 * Address:	801A1BE4
 * Size:	000048
 */
void zen::bBoardColourAnim::init(zen::bBoardColourAnimData *, short)
{
/*
.loc_0x0:
  lfs       f0, -0x4C18(r2)
  li        r0, 0
  stfs      f0, 0x0(r3)
  stb       r0, 0x4(r3)
  stw       r4, 0x8(r3)
  lwz       r4, 0x8(r3)
  cmplwi    r4, 0
  beq-      .loc_0x40
  lbz       r0, 0x2(r4)
  cmplwi    r0, 0
  beq-      .loc_0x34
  sth       r5, 0x6(r3)
  blr       

.loc_0x34:
  lbz       r0, 0x1(r4)
  sth       r0, 0x6(r3)
  blr       

.loc_0x40:
  sth       r5, 0x6(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801A1C2C
 * Size:	000114
 */
void zen::particleMdl::remove()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r0, 0x4(r3)
  lwz       r5, 0x8(r3)
  addi      r3, r30, 0x6C
  stw       r0, 0x4(r5)
  li        r5, 0x1
  lwz       r0, 0x8(r30)
  lwz       r6, 0x4(r30)
  stw       r0, 0x8(r6)
  lfs       f0, 0x1118(r13)
  stfs      f0, 0xC(r30)
  lfs       f0, 0x111C(r13)
  stfs      f0, 0x10(r30)
  lfs       f0, 0x1120(r13)
  stfs      f0, 0x14(r30)
  lfs       f0, 0x1124(r13)
  stfs      f0, 0x18(r30)
  lfs       f0, 0x1128(r13)
  stfs      f0, 0x1C(r30)
  lfs       f0, 0x112C(r13)
  stfs      f0, 0x20(r30)
  lfs       f2, -0x4C14(r2)
  stfs      f2, 0x24(r30)
  stb       r31, 0x28(r30)
  stb       r31, 0x29(r30)
  stb       r31, 0x2A(r30)
  stb       r31, 0x2B(r30)
  sth       r31, 0x2E(r30)
  sth       r31, 0x2C(r30)
  lfs       f1, -0x4C18(r2)
  stfs      f1, 0x30(r30)
  lfs       f0, 0x1130(r13)
  stfs      f0, 0x34(r30)
  lfs       f0, 0x1134(r13)
  stfs      f0, 0x38(r30)
  lfs       f0, 0x1138(r13)
  stfs      f0, 0x3C(r30)
  stfs      f1, 0x54(r30)
  stfs      f1, 0x50(r30)
  stfs      f1, 0x50(r30)
  lfs       f0, 0x113C(r13)
  stfs      f0, 0x5C(r30)
  lfs       f0, 0x1140(r13)
  stfs      f0, 0x60(r30)
  lfs       f0, 0x1144(r13)
  stfs      f0, 0x64(r30)
  sth       r31, 0x58(r30)
  sth       r31, 0x5A(r30)
  stfs      f2, 0x64(r30)
  stb       r31, 0x4C(r30)
  stb       r31, 0x68(r30)
  stb       r31, 0x69(r30)
  stb       r31, 0x6A(r30)
  stb       r31, 0x6B(r30)
  bl        -0x13C
  stw       r31, 0x78(r30)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801A1D40
 * Size:	000068
 */
void zen::particleMdlBase::remove()
{
/*
.loc_0x0:
  lwz       r5, 0x4(r3)
  li        r0, 0
  lwz       r4, 0x8(r3)
  stw       r5, 0x4(r4)
  lwz       r5, 0x8(r3)
  lwz       r4, 0x4(r3)
  stw       r5, 0x8(r4)
  lfs       f0, 0x1118(r13)
  stfs      f0, 0xC(r3)
  lfs       f0, 0x111C(r13)
  stfs      f0, 0x10(r3)
  lfs       f0, 0x1120(r13)
  stfs      f0, 0x14(r3)
  lfs       f0, 0x1124(r13)
  stfs      f0, 0x18(r3)
  lfs       f0, 0x1128(r13)
  stfs      f0, 0x1C(r3)
  lfs       f0, 0x112C(r13)
  stfs      f0, 0x20(r3)
  lfs       f0, -0x4C14(r2)
  stfs      f0, 0x24(r3)
  stb       r0, 0x28(r3)
  stb       r0, 0x29(r3)
  stb       r0, 0x2A(r3)
  stb       r0, 0x2B(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801A1DA8
 * Size:	000068
 */
void zen::particleChildMdl::remove()
{
/*
.loc_0x0:
  lwz       r5, 0x4(r3)
  li        r0, 0
  lwz       r4, 0x8(r3)
  stw       r5, 0x4(r4)
  lwz       r5, 0x8(r3)
  lwz       r4, 0x4(r3)
  stw       r5, 0x8(r4)
  lfs       f0, 0x1118(r13)
  stfs      f0, 0xC(r3)
  lfs       f0, 0x111C(r13)
  stfs      f0, 0x10(r3)
  lfs       f0, 0x1120(r13)
  stfs      f0, 0x14(r3)
  lfs       f0, 0x1124(r13)
  stfs      f0, 0x18(r3)
  lfs       f0, 0x1128(r13)
  stfs      f0, 0x1C(r3)
  lfs       f0, 0x112C(r13)
  stfs      f0, 0x20(r3)
  lfs       f0, -0x4C14(r2)
  stfs      f0, 0x24(r3)
  stb       r0, 0x28(r3)
  stb       r0, 0x29(r3)
  stb       r0, 0x2A(r3)
  stb       r0, 0x2B(r3)
  blr
*/
}