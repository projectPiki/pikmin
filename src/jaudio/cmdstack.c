

/*
 * --INFO--
 * Address:	8000E300
 * Size:	000028
 */
void Add_PortcmdOnce(void)
{
/*
.loc_0x0:
  mflr      r0
  addi      r4, r3, 0
  stw       r0, 0x4(r1)
  addi      r3, r13, 0x2C00
  stwu      r1, -0x8(r1)
  bl        0x4C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void Add_PortcmdStay(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E340
 * Size:	000018
 */
void Set_Portcmd(void)
{
/*
.loc_0x0:
  stw       r4, 0x14(r3)
  li        r0, 0
  stw       r5, 0x18(r3)
  stw       r0, 0xC(r3)
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8000E360
 * Size:	000078
 */
void Add_Portcmd(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stmw      r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r31, r4, 0
  bl        0x1EAC04
  lwz       r0, 0xC(r31)
  cmplwi    r0, 0
  beq-      .loc_0x34
  bl        0x1EAC1C
  li        r3, 0
  b         .loc_0x64

.loc_0x34:
  lwz       r4, 0x4(r30)
  cmplwi    r4, 0
  beq-      .loc_0x48
  stw       r31, 0x10(r4)
  b         .loc_0x4C

.loc_0x48:
  stw       r31, 0x0(r30)

.loc_0x4C:
  stw       r31, 0x4(r30)
  li        r0, 0
  stw       r0, 0x10(r31)
  stw       r30, 0xC(r31)
  bl        0x1EABE8
  li        r3, 0x1

.loc_0x64:
  lwz       r0, 0x1C(r1)
  lmw       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000E3E0
 * Size:	000040
 */
void Get_Portcmd(JPorthead_ *)
{
/*
.loc_0x0:
  lwz       r4, 0x0(r3)
  cmplwi    r4, 0
  beq-      .loc_0x34
  lwz       r0, 0x10(r4)
  stw       r0, 0x0(r3)
  lwz       r0, 0x0(r3)
  cmplwi    r0, 0
  bne-      .loc_0x28
  li        r0, 0
  stw       r0, 0x4(r3)

.loc_0x28:
  li        r0, 0
  stw       r0, 0xC(r4)
  b         .loc_0x38

.loc_0x34:
  li        r4, 0

.loc_0x38:
  mr        r3, r4
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void Cancel_Portcmd(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void Cancel_PortcmdStay(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E420
 * Size:	000050
 */
void Jac_Portcmd_Proc_Once(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3

.loc_0x14:
  mr        r3, r31
  bl        -0x58
  cmplwi    r3, 0
  beq-      .loc_0x38
  lwz       r12, 0x14(r3)
  lwz       r3, 0x18(r3)
  mtlr      r12
  blrl      
  b         .loc_0x14

.loc_0x38:
  lwz       r0, 0x1C(r1)
  li        r3, 0
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000E480
 * Size:	00004C
 */
void Jac_Portcmd_Proc_Stay(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  lwz       r31, 0x0(r3)

.loc_0x14:
  cmplwi    r31, 0
  beq-      .loc_0x34
  lwz       r12, 0x14(r31)
  lwz       r3, 0x18(r31)
  mtlr      r12
  blrl      
  lwz       r31, 0x10(r31)
  b         .loc_0x14

.loc_0x34:
  lwz       r0, 0x1C(r1)
  li        r3, 0
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000E4E0
 * Size:	000030
 */
void Portcmd_Main(void *)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r13, 0x2C00
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0xD0
  addi      r3, r13, 0x2C08
  bl        -0x78
  li        r3, 0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000E520
 * Size:	000010
 */
void Jac_Porthead_Init(void)
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x0(r3)
  stw       r0, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8000E540
 * Size:	00003C
 */
void Jac_Portcmd_Init(void)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r13, 0x2C00
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x30
  addi      r3, r13, 0x2C08
  bl        -0x38
  lis       r3, 0x8001
  li        r4, 0
  subi      r3, r3, 0x1B20
  bl        -0x7348
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void JP_Pitch1Shot(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void JP_Start1Shot(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void JP_Stop1Shot(void)
{
	// UNUSED FUNCTION
}
