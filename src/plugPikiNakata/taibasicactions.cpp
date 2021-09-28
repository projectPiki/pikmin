

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
 * Address:	801283A8
 * Size:	00000C
 */
void TaiActionStateAction::start(Teki &)
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x338(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	801283B4
 * Size:	000020
 */
void TaiActionStateAction::act(Teki &)
{
/*
.loc_0x0:
  lwz       r4, 0x338(r4)
  lwz       r0, 0x8(r3)
  cmpw      r4, r0
  bne-      .loc_0x18
  li        r3, 0x1
  blr       

.loc_0x18:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801283D4
 * Size:	000060
 */
void TaiSetOptionAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  mr        r5, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lbz       r0, 0xC(r3)
  cmplwi    r0, 0
  beq-      .loc_0x38
  mr        r3, r4
  lwz       r4, 0x8(r5)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x1CC(r12)
  mtlr      r12
  blrl      
  b         .loc_0x50

.loc_0x38:
  mr        r3, r4
  lwz       r4, 0x8(r5)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x1D0(r12)
  mtlr      r12
  blrl      

.loc_0x50:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80128434
 * Size:	000038
 */
void TaiPlaySoundAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r5, r3, 0
  stw       r0, 0x4(r1)
  addi      r3, r4, 0
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r3)
  lwz       r4, 0x8(r5)
  lwz       r12, 0x1C0(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012846C
 * Size:	000038
 */
void TaiStopSoundAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r5, r3, 0
  stw       r0, 0x4(r1)
  addi      r3, r4, 0
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r3)
  lwz       r4, 0x8(r5)
  lwz       r12, 0x1C4(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801284A4
 * Size:	000044
 */
void TaiTypeNaviWatchResultOnAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0xC8(r4)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x34
  lwz       r3, 0x3160(r13)
  lwz       r4, 0x320(r4)
  bl        0x22B80
  lwz       r5, 0x2F6C(r13)
  addi      r4, r3, 0
  addi      r3, r5, 0x70
  bl        -0xA4AD4

.loc_0x34:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801284E8
 * Size:	000038
 */
void TaiNaviWatchResultOnAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0xC8(r4)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x28
  lwz       r5, 0x2F6C(r13)
  lwz       r4, 0x8(r3)
  addi      r3, r5, 0x70
  bl        -0xA4B0C

.loc_0x28:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}