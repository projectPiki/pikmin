

/*
 * --INFO--
 * Address:	8001B960
 * Size:	00003C
 */
void Add_Queue(cmdqueue_ *)
{
/*
.loc_0x0:
  lwz       r4, 0x2C50(r13)
  li        r0, 0
  stw       r0, 0x68(r3)
  lwz       r0, 0x2C50(r13)
  cmplwi    r0, 0
  bne-      .loc_0x28
  stw       r3, 0x2C50(r13)
  blr       
  b         .loc_0x28

.loc_0x24:
  mr        r4, r0

.loc_0x28:
  lwz       r0, 0x68(r4)
  cmplwi    r0, 0
  bne+      .loc_0x24
  stw       r3, 0x68(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void Del_Queue(cmdqueue_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001B9A0
 * Size:	000060
 */
void Jal_AddCmdQueue(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r29, 0x1C(r1)
  addi      r29, r3, 0
  addi      r31, r4, 0
  addi      r30, r5, 0
  bl        0x1DD5C0
  stw       r31, 0x60(r29)
  addi      r31, r3, 0
  addi      r3, r29, 0
  addi      r4, r29, 0x20
  stb       r30, 0x64(r29)
  li        r5, 0x10
  bl        -0x13878
  mr        r3, r29
  bl        -0x80
  mr        r3, r31
  bl        0x1DD5BC
  lmw       r29, 0x1C(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void Jal_RemoveCmdQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void Jal_SendCmdQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001BA00
 * Size:	000030
 */
void Jal_SendCmdQueue_Noblock(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r3, 0x8(r1)
  sth       r4, 0xC(r1)
  lwz       r3, 0x8(r1)
  lhz       r4, 0xC(r1)
  bl        -0x1389C
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001BA40
 * Size:	000054
 */
void Jal_SendCmdQueue_Force(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stmw      r30, 0x18(r1)
  rlwinm    r31,r4,0,16,31
  addi      r30, r3, 0
  addi      r4, r31, 0
  bl        -0x138DC
  cmpwi     r3, 0
  bne-      .loc_0x40
  addi      r3, r30, 0
  addi      r4, r1, 0x10
  bl        -0x13870
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        -0x138FC

.loc_0x40:
  lwz       r0, 0x24(r1)
  lmw       r30, 0x18(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001BAA0
 * Size:	000078
 */
void Jal_FrameWork(void *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  lwz       r31, 0x2C50(r13)
  b         .loc_0x5C

.loc_0x18:
  lwz       r3, 0x60(r31)
  li        r5, 0x1
  lbz       r4, 0x64(r31)
  bl        -0xB684
  cmpwi     r3, 0x1
  bne-      .loc_0x58
  addi      r3, r31, 0
  addi      r4, r1, 0x10
  bl        -0x13878
  cmpwi     r3, 0x1
  bne-      .loc_0x58
  lwz       r0, 0x10(r1)
  lwz       r3, 0x60(r31)
  lbz       r4, 0x64(r31)
  rlwinm    r5,r0,0,16,31
  bl        -0xB774

.loc_0x58:
  lwz       r31, 0x68(r31)

.loc_0x5C:
  cmplwi    r31, 0
  bne+      .loc_0x18
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001BB20
 * Size:	00002C
 */
void Jal_CmdQueue_Init(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x8002
  stw       r0, 0x4(r1)
  li        r4, 0
  subi      r3, r3, 0x4560
  stwu      r1, -0x8(r1)
  bl        -0x14918
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}