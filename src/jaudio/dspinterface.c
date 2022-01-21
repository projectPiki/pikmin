

/*
 * --INFO--
 * Address:	8000B560
 * Size:	000018
 */
void GetDspHandle(unsigned char)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r4, r0, 0x180
	  addi      r0, r3, 0x6A60
	  add       r3, r0, r4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GetDspHandleNc(unsigned char)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000B580
 * Size:	000014
 */
void GetFxHandle(unsigned char)
{
	/*
	.loc_0x0:
	  lis       r4, 0x8031
	  rlwinm    r3,r3,5,19,26
	  subi      r0, r4, 0x35A0
	  add       r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void GetFxHandleNc(unsigned char)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000B5A0
 * Size:	00002C
 */
void DSP_SetPitch(unsigned char, unsigned short)
{
	/*
	.loc_0x0:
	  rlwinm    r5,r3,0,24,31
	  rlwinm    r0,r4,0,16,31
	  mulli     r5, r5, 0x180
	  lis       r3, 0x8030
	  cmplwi    r0, 0x7FFF
	  addi      r0, r3, 0x6A60
	  add       r3, r0, r5
	  blt-      .loc_0x24
	  li        r4, 0x7FFF

	.loc_0x24:
	  sth       r4, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void DSP_SetPitch_Indirect(unsigned char, float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000B5E0
 * Size:	000020
 */
void DSP_SetMixerInitDelayMax(unsigned char, unsigned char)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r5, r0, 0x180
	  addi      r0, r3, 0x6A60
	  rlwinm    r4,r4,0,24,31
	  add       r3, r0, r5
	  sth       r4, 0xE(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B600
 * Size:	00004C
 */
void DSP_SetMixerInitVolume(unsigned char, unsigned char, short, unsigned char)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  rlwinm    r0,r6,8,16,23
	  rlwimi    r0,r6,0,24,31
	  stb       r3, 0x8(r1)
	  lis       r3, 0x8030
	  addi      r7, r3, 0x6A60
	  lbz       r3, 0x8(r1)
	  stb       r4, 0x9(r1)
	  mulli     r4, r3, 0x180
	  lbz       r3, 0x9(r1)
	  add       r4, r7, r4
	  rlwinm    r3,r3,3,0,28
	  add       r3, r4, r3
	  addi      r3, r3, 0x10
	  sth       r5, 0x4(r3)
	  sth       r5, 0x2(r3)
	  sth       r0, 0x6(r3)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B660
 * Size:	000044
 */
void DSP_SetMixerVolume(unsigned char, unsigned char, short, unsigned char)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r7, r0, 0x180
	  addi      r0, r3, 0x6A60
	  rlwinm    r3,r4,3,21,28
	  addi      r3, r3, 0x10
	  add       r4, r0, r7
	  lhz       r0, 0x10A(r4)
	  add       r3, r4, r3
	  cmplwi    r0, 0
	  bnelr-
	  sth       r5, 0x2(r3)
	  lhz       r0, 0x6(r3)
	  rlwinm    r0,r0,0,24,31
	  rlwimi    r0,r6,8,16,23
	  sth       r0, 0x6(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B6C0
 * Size:	00002C
 */
void DSP_SetOscInfo(unsigned char, unsigned long)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r6, r0, 0x180
	  addi      r5, r3, 0x6A60
	  li        r3, 0
	  li        r0, 0x10
	  add       r5, r5, r6
	  stw       r3, 0x118(r5)
	  sth       r0, 0x64(r5)
	  sth       r4, 0x100(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B700
 * Size:	000020
 */
void DSP_SetPauseFlag(unsigned char, unsigned char)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r5, r0, 0x180
	  addi      r0, r3, 0x6A60
	  rlwinm    r4,r4,0,24,31
	  add       r3, r0, r5
	  sth       r4, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B720
 * Size:	0000B0
 */
void DSP_SetWaveInfo(unsigned char, Wave_*, unsigned long)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r7, r0, 0x180
	  addi      r0, r3, 0x6A60
	  subi      r6, r13, 0x7FE0
	  subi      r3, r13, 0x7FD8
	  add       r7, r0, r7
	  stw       r5, 0x118(r7)
	  lbz       r0, 0x1(r4)
	  lbzx      r0, r6, r0
	  sth       r0, 0x64(r7)
	  lbz       r0, 0x1(r4)
	  lbzx      r0, r3, r0
	  sth       r0, 0x100(r7)
	  lhz       r0, 0x100(r7)
	  cmplwi    r0, 0x4
	  bltlr-
	  lwz       r0, 0x1C(r4)
	  stw       r0, 0x11C(r7)
	  lwz       r0, 0x10(r4)
	  sth       r0, 0x102(r7)
	  lhz       r0, 0x102(r7)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  lwz       r0, 0x14(r4)
	  stw       r0, 0x110(r7)
	  lwz       r0, 0x18(r4)
	  stw       r0, 0x114(r7)
	  lha       r0, 0x20(r4)
	  sth       r0, 0x104(r7)
	  lha       r0, 0x22(r4)
	  sth       r0, 0x106(r7)
	  b         .loc_0x8C

	.loc_0x84:
	  lwz       r0, 0x11C(r7)
	  stw       r0, 0x114(r7)

	.loc_0x8C:
	  li        r3, 0
	  li        r0, 0x10
	  addi      r4, r3, 0
	  mtctr     r0

	.loc_0x9C:
	  addi      r0, r3, 0xB0
	  addi      r3, r3, 0x2
	  sthx      r4, r7, r0
	  bdnz+     .loc_0x9C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B7E0
 * Size:	000038
 */
void DSP_SetBusConnect(unsigned char, unsigned char, unsigned char)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r7, 0x8022
	  mulli     r6, r0, 0x180
	  lis       r3, 0x8030
	  rlwinm    r5,r5,1,23,30
	  addi      r0, r7, 0x49A0
	  add       r5, r0, r5
	  addi      r0, r3, 0x6A60
	  add       r3, r0, r6
	  rlwinm    r0,r4,3,21,28
	  lhz       r4, 0x0(r5)
	  add       r3, r3, r0
	  sth       r4, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B820
 * Size:	000020
 */
void DSP_PlayStop(unsigned char)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r4, r0, 0x180
	  addi      r0, r3, 0x6A60
	  li        r5, 0
	  add       r3, r0, r4
	  sth       r5, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B840
 * Size:	000060
 */
void DSP_AllocInit(unsigned char)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  rlwinm    r0,r31,0,24,31
	  lis       r3, 0x8030
	  mulli     r5, r0, 0x180
	  addi      r4, r3, 0x6A60
	  li        r0, 0
	  addi      r3, r31, 0
	  add       r4, r4, r5
	  sth       r0, 0xC(r4)
	  sth       r0, 0x2(r4)
	  sth       r0, 0x10A(r4)
	  sth       r0, 0x0(r4)
	  bl        0x1E0
	  mr        r3, r31
	  bl        0x298
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B8A0
 * Size:	00007C
 */
void DSP_PlayStart(unsigned char)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r6, r0, 0x180
	  addi      r0, r3, 0x6A60
	  li        r5, 0
	  li        r4, 0x1
	  add       r6, r0, r6
	  li        r0, 0x4
	  stw       r5, 0x10C(r6)
	  mr        r3, r5
	  stw       r5, 0x68(r6)
	  sth       r5, 0x60(r6)
	  sth       r4, 0x8(r6)
	  sth       r5, 0x66(r6)
	  mtctr     r0

	.loc_0x3C:
	  add       r4, r6, r3
	  addi      r3, r3, 0x2
	  sth       r5, 0x78(r4)
	  sth       r5, 0xA8(r4)
	  bdnz+     .loc_0x3C
	  li        r0, 0x14
	  li        r4, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0x60:
	  addi      r0, r3, 0x80
	  addi      r3, r3, 0x2
	  sthx      r4, r6, r0
	  bdnz+     .loc_0x60
	  li        r0, 0x1
	  sth       r0, 0x0(r6)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B920
 * Size:	00001C
 */
void DSP_SetDistFilter(unsigned char, short)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r5, r0, 0x180
	  addi      r0, r3, 0x6A60
	  add       r3, r0, r5
	  sth       r4, 0x150(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B940
 * Size:	000024
 */
void DSP_SetFilterTable(short*, short*, unsigned long)
{
	/*
	.loc_0x0:
	  mtctr     r5
	  cmplwi    r5, 0
	  blelr-

	.loc_0xC:
	  lha       r0, 0x0(r4)
	  addi      r4, r4, 0x2
	  sth       r0, 0x0(r3)
	  addi      r3, r3, 0x2
	  bdnz+     .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B980
 * Size:	00003C
 */
void DSP_SetIIRFilterParam(unsigned char, short*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r3,0,24,31
	  mulli     r5, r0, 0x180
	  lis       r3, 0x8030
	  addi      r0, r3, 0x6A60
	  stwu      r1, -0x8(r1)
	  add       r3, r0, r5
	  li        r5, 0x4
	  addi      r3, r3, 0x148
	  bl        -0x68
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B9C0
 * Size:	00003C
 */
void DSP_SetFIR8FilterParam(unsigned char, short*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r3,0,24,31
	  mulli     r5, r0, 0x180
	  lis       r3, 0x8030
	  addi      r0, r3, 0x6A60
	  stwu      r1, -0x8(r1)
	  add       r3, r0, r5
	  li        r5, 0x8
	  addi      r3, r3, 0x120
	  bl        -0xA8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000BA00
 * Size:	000054
 */
void DSP_SetFilterMode(unsigned char, unsigned short)
{
	/*
	.loc_0x0:
	  rlwinm    r5,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r5, r5, 0x180
	  rlwinm.   r0,r4,0,26,26
	  addi      r3, r3, 0x6A60
	  rlwinm    r6,r4,0,26,26
	  rlwinm    r0,r4,0,27,31
	  add       r4, r3, r5
	  beq-      .loc_0x34
	  cmplwi    r0, 0x14
	  ble-      .loc_0x40
	  li        r0, 0x14
	  b         .loc_0x40

	.loc_0x34:
	  cmplwi    r0, 0x18
	  ble-      .loc_0x40
	  li        r0, 0x18

	.loc_0x40:
	  rlwinm    r3,r6,0,24,31
	  rlwinm    r0,r0,0,24,31
	  add       r0, r3, r0
	  sth       r0, 0x108(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000BA60
 * Size:	000070
 */
void DSP_InitFilter(unsigned char)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x8030
	  mulli     r6, r0, 0x180
	  addi      r5, r3, 0x6A60
	  li        r3, 0
	  li        r0, 0x8
	  addi      r4, r3, 0
	  add       r5, r5, r6
	  mtctr     r0

	.loc_0x24:
	  addi      r0, r3, 0x120
	  addi      r3, r3, 0x2
	  sthx      r4, r5, r0
	  bdnz+     .loc_0x24
	  li        r3, 0x7FFF
	  li        r0, 0x4
	  sth       r3, 0x120(r5)
	  li        r4, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0x4C:
	  addi      r0, r3, 0x148
	  addi      r3, r3, 0x2
	  sthx      r4, r5, r0
	  bdnz+     .loc_0x4C
	  li        r3, 0x7FFF
	  li        r0, 0
	  sth       r3, 0x148(r5)
	  sth       r0, 0x150(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000BAE0
 * Size:	00003C
 */
void DSP_FlushBuffer()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8030
	  stw       r0, 0x4(r1)
	  li        r4, 0x6000
	  addi      r3, r3, 0x6A60
	  stwu      r1, -0x8(r1)
	  bl        0x1EB0F0
	  lis       r3, 0x8031
	  li        r4, 0x80
	  subi      r3, r3, 0x35A0
	  bl        0x1EB0E0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000BB20
 * Size:	000038
 */
void DSP_FlushChannel(unsigned char)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x180
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r3,0,24,31
	  mulli     r5, r0, 0x180
	  lis       r3, 0x8030
	  addi      r0, r3, 0x6A60
	  stwu      r1, -0x8(r1)
	  add       r3, r0, r5
	  bl        0x1EB10C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void DSP_CacheChannel(unsigned char)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void DSP_FlushChannelAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void DSP_CacheChannelAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000BB60
 * Size:	00002C
 */
void DSP_InvalChannelAll()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8030
	  stw       r0, 0x4(r1)
	  li        r4, 0x6000
	  addi      r3, r3, 0x6A60
	  stwu      r1, -0x8(r1)
	  bl        0x1EB040
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000BBA0
 * Size:	000050
 */
void DSP_ClearBuffer()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8030
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r29, 0xC(r1)
	  li        r29, 0
	  addi      r30, r3, 0x6A60
	  li        r31, 0

	.loc_0x20:
	  add       r3, r30, r31
	  li        r4, 0x180
	  bl        -0x5B08
	  addi      r29, r29, 0x1
	  addi      r31, r31, 0x180
	  cmpwi     r29, 0x40
	  blt+      .loc_0x20
	  lmw       r29, 0xC(r1)
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000BC00
 * Size:	000044
 */
void DSP_SetupBuffer()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8030
	  stw       r0, 0x4(r1)
	  lis       r5, 0x8022
	  lis       r6, 0x8022
	  lis       r3, 0x8031
	  stwu      r1, -0x8(r1)
	  subi      r7, r3, 0x35A0
	  addi      r4, r4, 0x6A60
	  addi      r5, r5, 0x4A00
	  addi      r6, r6, 0x49C0
	  li        r3, 0x40
	  bl        -0x33F0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000BC60
 * Size:	000058
 */
void DSP_InitBuffer()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0

	.loc_0x14:
	  rlwinm    r3,r31,0,24,31
	  li        r4, 0
	  li        r5, 0
	  bl        0x40
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x4
	  blt+      .loc_0x14
	  bl        -0xF0
	  bl        -0x94
	  bl        -0xF98
	  bl        -0x20BC
	  bl        -0x1C0
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
