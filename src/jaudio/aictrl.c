

/*
 * --INFO--
 * Address:	80005720
 * Size:	00004C
 */
void Jac_HeapSetup(void)
{
/*
.loc_0x0:
  mflr      r0
  cmplwi    r3, 0
  stw       r0, 0x4(r1)
  addi      r5, r4, 0
  stwu      r1, -0x8(r1)
  beq-      .loc_0x34
  lis       r6, 0x802F
  addi      r4, r3, 0
  subi      r3, r6, 0x69B4
  bl        -0x84
  li        r0, 0x1
  stw       r0, 0x2B04(r13)
  b         .loc_0x3C

.loc_0x34:
  li        r0, 0
  stw       r0, 0x2B04(r13)

.loc_0x3C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GetAudioHeapRemain(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005780
 * Size:	000080
 */
void OSAlloc2(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stmw      r30, 0x10(r1)
  stw       r3, 0x8(r1)
  bl        0x1F37E8
  lwz       r0, 0x2B04(r13)
  addi      r30, r3, 0
  cmpwi     r0, 0x1
  beq-      .loc_0x4C
  bge-      .loc_0x60
  cmpwi     r0, 0
  bge-      .loc_0x38
  b         .loc_0x60

.loc_0x38:
  lwz       r3, 0x29D8(r13)
  lwz       r4, 0x8(r1)
  bl        0x1F0FEC
  mr        r31, r3
  b         .loc_0x60

.loc_0x4C:
  lis       r3, 0x802F
  lwz       r4, 0x8(r1)
  subi      r3, r3, 0x69B4
  bl        -0x198
  mr        r31, r3

.loc_0x60:
  mr        r3, r30
  bl        0x1F37C0
  mr        r3, r31
  lmw       r30, 0x10(r1)
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void OSFree2(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005800
 * Size:	0000AC
 */
void Jac_Init(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x802F
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x28(r1)
  stmw      r30, 0x20(r1)
  subi      r31, r3, 0x69C0
  stw       r0, 0x18(r1)
  b         .loc_0x6C

.loc_0x24:
  lwz       r0, -0x7FF4(r13)
  rlwinm    r3,r0,1,0,30
  bl        -0xAC
  lwz       r0, 0x18(r1)
  rlwinm    r0,r0,2,0,29
  add       r30, r31, r0
  stw       r3, 0x0(r30)
  lwz       r0, -0x7FF4(r13)
  lwz       r3, 0x0(r30)
  rlwinm    r4,r0,1,0,30
  bl        0x874
  lwz       r0, -0x7FF4(r13)
  lwz       r3, 0x0(r30)
  rlwinm    r4,r0,1,0,30
  bl        0x1F13C0
  lwz       r3, 0x18(r1)
  addi      r0, r3, 0x1
  stw       r0, 0x18(r1)

.loc_0x6C:
  lwz       r0, 0x18(r1)
  cmpwi     r0, 0x3
  blt+      .loc_0x24
  li        r3, 0
  bl        0x200BE4
  lis       r3, 0x802F
  lwz       r0, -0x7FF4(r13)
  subi      r3, r3, 0x69C0
  lwz       r3, 0x8(r3)
  rlwinm    r4,r0,1,0,30
  bl        0x2007B4
  lwz       r0, 0x2C(r1)
  lmw       r30, 0x20(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_GetCurrentVCounter(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void HaltDSPSignal(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void HaltDSP(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void RunDSP(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void CheckHaltDSP(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800058C0
 * Size:	0000DC
 */
void MixMonoTrack(short *, long, short * (*) (long))
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r6, 0x1FE0
  stwu      r1, -0x30(r1)
  stmw      r29, 0x24(r1)
  addi      r29, r3, 0
  addi      r30, r4, 0
  addi      r31, r5, 0
  mr        r4, r0
  li        r3, 0x5
  bl        -0x2EC
  addi      r12, r31, 0
  addi      r3, r30, 0
  mtlr      r12
  blrl      
  mr.       r31, r3
  beq-      .loc_0xC8
  li        r3, 0x5
  bl        -0x2EC
  mr.       r0, r30
  addi      r4, r29, 0
  addi      r5, r31, 0
  mtctr     r0
  ble-      .loc_0xC8

.loc_0x64:
  lha       r3, 0x0(r4)
  lha       r0, 0x0(r5)
  add       r0, r3, r0
  cmpwi     r0, -0x8000
  bge-      .loc_0x7C
  li        r0, -0x7FFF

.loc_0x7C:
  cmpwi     r0, 0x7FFF
  ble-      .loc_0x88
  li        r0, 0x7FFF

.loc_0x88:
  extsh     r0, r0
  sth       r0, 0x0(r4)
  lhau      r3, 0x2(r4)
  lha       r0, 0x0(r5)
  add       r0, r3, r0
  cmpwi     r0, -0x8000
  bge-      .loc_0xA8
  li        r0, -0x7FFF

.loc_0xA8:
  cmpwi     r0, 0x7FFF
  ble-      .loc_0xB4
  li        r0, 0x7FFF

.loc_0xB4:
  extsh     r0, r0
  addi      r5, r5, 0x2
  sth       r0, 0x0(r4)
  addi      r4, r4, 0x2
  bdnz+     .loc_0x64

.loc_0xC8:
  lmw       r29, 0x24(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800059A0
 * Size:	0000DC
 */
void MixMonoTrackWide(short *, long, short * (*) (long))
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r6, 0x1FEC
  stwu      r1, -0x30(r1)
  stmw      r29, 0x24(r1)
  addi      r29, r3, 0
  addi      r30, r4, 0
  addi      r31, r5, 0
  mr        r4, r0
  li        r3, 0x5
  bl        -0x3CC
  addi      r12, r31, 0
  addi      r3, r30, 0
  mtlr      r12
  blrl      
  mr.       r31, r3
  beq-      .loc_0xC8
  li        r3, 0x5
  bl        -0x3CC
  mr.       r0, r30
  addi      r4, r29, 0
  addi      r5, r31, 0
  mtctr     r0
  ble-      .loc_0xC8

.loc_0x64:
  lha       r3, 0x0(r4)
  lha       r0, 0x0(r5)
  add       r0, r3, r0
  cmpwi     r0, -0x8000
  bge-      .loc_0x7C
  li        r0, -0x7FFF

.loc_0x7C:
  cmpwi     r0, 0x7FFF
  ble-      .loc_0x88
  li        r0, 0x7FFF

.loc_0x88:
  extsh     r0, r0
  sth       r0, 0x0(r4)
  lha       r3, 0x0(r5)
  lhau      r0, 0x2(r4)
  sub       r0, r0, r3
  cmpwi     r0, -0x8000
  bge-      .loc_0xA8
  li        r0, -0x7FFF

.loc_0xA8:
  cmpwi     r0, 0x7FFF
  ble-      .loc_0xB4
  li        r0, 0x7FFF

.loc_0xB4:
  extsh     r0, r0
  addi      r5, r5, 0x2
  sth       r0, 0x0(r4)
  addi      r4, r4, 0x2
  bdnz+     .loc_0x64

.loc_0xC8:
  lmw       r29, 0x24(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80005A80
 * Size:	0000F8
 */
void MixExtraTrack(short *, long, short * (*) (long))
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r29, 0x24(r1)
  addi      r29, r3, 0
  addi      r30, r4, 0
  addi      r31, r5, 0
  li        r3, 0x5
  subi      r4, r2, 0x8000
  bl        -0x4A4
  addi      r12, r31, 0
  addi      r3, r30, 0
  mtlr      r12
  blrl      
  mr.       r31, r3
  beq-      .loc_0xE4
  li        r3, 0x5
  bl        -0x4A4
  li        r3, 0x6
  subi      r4, r2, 0x7FF8
  bl        -0x4D0
  lwz       r0, -0x7FF8(r13)
  mr.       r3, r30
  addi      r4, r29, 0
  addi      r6, r31, 0
  rlwinm    r0,r0,1,0,30
  add       r5, r31, r0
  mtctr     r3
  ble-      .loc_0xDC

.loc_0x74:
  lha       r3, 0x0(r4)
  lha       r0, 0x0(r5)
  add       r0, r3, r0
  cmpwi     r0, -0x8000
  bge-      .loc_0x8C
  li        r0, -0x7FFF

.loc_0x8C:
  cmpwi     r0, 0x7FFF
  ble-      .loc_0x98
  li        r0, 0x7FFF

.loc_0x98:
  extsh     r0, r0
  sth       r0, 0x0(r4)
  lhau      r3, 0x2(r4)
  lha       r0, 0x0(r6)
  add       r0, r3, r0
  cmpwi     r0, -0x8000
  bge-      .loc_0xB8
  li        r0, -0x7FFF

.loc_0xB8:
  cmpwi     r0, 0x7FFF
  ble-      .loc_0xC4
  li        r0, 0x7FFF

.loc_0xC4:
  extsh     r0, r0
  addi      r6, r6, 0x2
  sth       r0, 0x0(r4)
  addi      r4, r4, 0x2
  addi      r5, r5, 0x2
  bdnz+     .loc_0x74

.loc_0xDC:
  li        r3, 0x6
  bl        -0x540

.loc_0xE4:
  lmw       r29, 0x24(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80005B80
 * Size:	00008C
 */
void MixInterleaveTrack(short *, long, short * (*) (long))
{
/*
.loc_0x0:
  mflr      r0
  addi      r12, r5, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r30, 0x20(r1)
  addi      r31, r4, 0
  addi      r30, r3, 0
  addi      r3, r31, 0
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  beq-      .loc_0x78
  rlwinm.   r0,r31,1,0,30
  addi      r5, r30, 0
  mtctr     r0
  ble-      .loc_0x78

.loc_0x40:
  lha       r4, 0x0(r5)
  lha       r0, 0x0(r3)
  add       r0, r4, r0
  cmpwi     r0, -0x8000
  bge-      .loc_0x58
  li        r0, -0x7FFF

.loc_0x58:
  cmpwi     r0, 0x7FFF
  ble-      .loc_0x64
  li        r0, 0x7FFF

.loc_0x64:
  extsh     r0, r0
  addi      r3, r3, 0x2
  sth       r0, 0x0(r5)
  addi      r5, r5, 0x2
  bdnz+     .loc_0x40

.loc_0x78:
  lwz       r0, 0x2C(r1)
  lmw       r30, 0x20(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void Jac_GetMixcallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void Jac_RegisterMixcallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005C20
 * Size:	000188
 */
void Jac_VframeWork(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x802F
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stmw      r30, 0x8(r1)
  subi      r31, r3, 0x69C0
  lbz       r0, 0x2B28(r13)
  extsb.    r0, r0
  bne-      .loc_0x34
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2B24(r13)
  stb       r0, 0x2B28(r13)

.loc_0x34:
  lwz       r3, 0x2B18(r13)
  lwz       r0, -0x7FF4(r13)
  addi      r3, r3, 0x1
  stw       r3, 0x2B18(r13)
  rlwinm    r3,r0,31,1,31
  bl        0x11F8
  lwz       r5, 0x2B24(r13)
  addi      r4, r3, 0
  lwz       r0, -0x7FF8(r13)
  rlwinm    r5,r5,2,0,29
  rlwinm    r3,r0,1,0,30
  lwz       r0, -0x7FF4(r13)
  lwzx      r5, r31, r5
  add       r3, r4, r3
  rlwinm    r6,r0,31,1,31
  bl        0x270
  lwz       r5, 0x2B1C(r13)
  cmplwi    r5, 0
  beq-      .loc_0x118
  lbz       r0, 0x2B20(r13)
  cmpwi     r0, 0x2
  beq-      .loc_0xE4
  bge-      .loc_0xA0
  cmpwi     r0, 0
  beq-      .loc_0xAC
  bge-      .loc_0xC8
  b         .loc_0x118

.loc_0xA0:
  cmpwi     r0, 0x4
  bge-      .loc_0x118
  b         .loc_0x100

.loc_0xAC:
  lwz       r3, 0x2B24(r13)
  lwz       r0, -0x7FF4(r13)
  rlwinm    r3,r3,2,0,29
  lwzx      r3, r31, r3
  rlwinm    r4,r0,31,1,31
  bl        -0x420
  b         .loc_0x118

.loc_0xC8:
  lwz       r3, 0x2B24(r13)
  lwz       r0, -0x7FF4(r13)
  rlwinm    r3,r3,2,0,29
  lwzx      r3, r31, r3
  rlwinm    r4,r0,31,1,31
  bl        -0x35C
  b         .loc_0x118

.loc_0xE4:
  lwz       r3, 0x2B24(r13)
  lwz       r0, -0x7FF4(r13)
  rlwinm    r3,r3,2,0,29
  lwzx      r3, r31, r3
  rlwinm    r4,r0,31,1,31
  bl        -0x298
  b         .loc_0x118

.loc_0x100:
  lwz       r3, 0x2B24(r13)
  lwz       r0, -0x7FF4(r13)
  rlwinm    r3,r3,2,0,29
  lwzx      r3, r31, r3
  rlwinm    r4,r0,31,1,31
  bl        -0x1B4

.loc_0x118:
  bl        0x1F3244
  lwz       r4, 0x2B24(r13)
  addi      r30, r3, 0
  lwz       r0, -0x7FF4(r13)
  rlwinm    r3,r4,2,0,29
  lwzx      r3, r31, r3
  rlwinm    r4,r0,1,0,30
  bl        0x1F0EC8
  mr        r3, r30
  bl        0x1F3248
  lwz       r4, 0x2B24(r13)
  rlwinm    r3,r4,2,0,29
  addi      r0, r4, 0x1
  lwzx      r3, r31, r3
  stw       r0, 0x2B24(r13)
  lwz       r0, 0x2B24(r13)
  stw       r3, 0x2B08(r13)
  cmplwi    r0, 0x3
  bne-      .loc_0x16C
  li        r0, 0
  stw       r0, 0x2B24(r13)

.loc_0x16C:
  li        r0, 0
  stw       r0, 0x2B10(r13)
  lmw       r30, 0x8(r1)
  lwz       r0, 0x14(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80005DC0
 * Size:	0000A8
 */
void Jac_UpdateDAC(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x2B0C(r13)
  cmplwi    r0, 0
  bne-      .loc_0x28
  lwz       r3, 0x2B08(r13)
  li        r0, 0
  stw       r3, 0x2B0C(r13)
  stw       r0, 0x2B08(r13)

.loc_0x28:
  lwz       r3, 0x2B0C(r13)
  cmplwi    r3, 0
  beq-      .loc_0x4C
  lwz       r0, -0x7FF4(r13)
  rlwinm    r4,r0,1,0,30
  bl        0x20024C
  li        r0, 0
  stw       r0, 0x2B0C(r13)
  b         .loc_0x58

.loc_0x4C:
  lwz       r3, 0x2B00(r13)
  addi      r0, r3, 0x1
  stw       r0, 0x2B00(r13)

.loc_0x58:
  lwz       r0, 0x2B08(r13)
  cmplwi    r0, 0
  bne-      .loc_0x74
  lwz       r0, 0x2B10(r13)
  cmpwi     r0, 0
  bne-      .loc_0x74
  bl        -0x210

.loc_0x74:
  bl        0x9AC
  lwz       r12, 0x2B14(r13)
  cmplwi    r12, 0
  beq-      .loc_0x98
  lwz       r0, -0x7FF4(r13)
  lwz       r3, 0x2B08(r13)
  rlwinm    r4,r0,31,1,31
  mtlr      r12
  blrl      

.loc_0x98:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_RegisterDacCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005E80
 * Size:	000008
 */
void Jac_SetOutputMode(void)
{
/*
.loc_0x0:
  stw       r3, -0x7FE4(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	80005EA0
 * Size:	000008
 */
void Jac_GetOutputMode(void)
{
/*
.loc_0x0:
  lwz       r3, -0x7FE4(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	80005EC0
 * Size:	000034
 */
void Jac_SetMixerLevel(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stfd      f31, 0x10(r1)
  fmr       f31, f2
  bl        0x352C
  fmr       f1, f31
  bl        0x29C4
  lwz       r0, 0x1C(r1)
  lfd       f31, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
