

/*
 * --INFO--
 * Address:	8001BBE0
 * Size:	000038
 */
void Stop_DirectPCM(dspch_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lbz       r3, 0x0(r3)
  bl        -0x103D8
  lbz       r3, 0x0(r31)
  bl        -0x100E0
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001BC20
 * Size:	0000DC
 */
void Play_DirectPCM(dspch_ *, short *, unsigned short, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r28, 0x18(r1)
  addi      r28, r3, 0
  addi      r29, r4, 0
  addi      r30, r5, 0
  addi      r31, r6, 0
  lbz       r3, 0x0(r3)
  bl        -0x106E4
  stw       r29, 0x118(r3)
  li        r0, 0
  li        r5, 0x21
  li        r4, 0
  sth       r0, 0x102(r3)
  rlwinm    r0,r30,16,0,15
  sth       r5, 0x100(r3)
  stw       r31, 0x74(r3)
  stw       r29, 0x110(r3)
  stw       r0, 0x114(r3)
  lbz       r3, 0x0(r28)
  bl        -0x10694
  li        r31, 0

.loc_0x5C:
  cmplwi    r31, 0x2
  bge-      .loc_0x7C
  lbz       r3, 0x0(r28)
  rlwinm    r4,r31,0,24,31
  li        r5, 0x7FFF
  li        r6, 0
  bl        -0x10694
  b         .loc_0x90

.loc_0x7C:
  lbz       r3, 0x0(r28)
  rlwinm    r4,r31,0,24,31
  li        r5, 0
  li        r6, 0
  bl        -0x106AC

.loc_0x90:
  lbz       r3, 0x0(r28)
  rlwinm    r4,r31,0,24,31
  addi      r5, r31, 0x1
  bl        -0x104DC
  addi      r31, r31, 0x1
  cmplwi    r31, 0x6
  blt+      .loc_0x5C
  lbz       r3, 0x0(r28)
  li        r4, 0x800
  bl        -0x10734
  lbz       r3, 0x0(r28)
  bl        -0x1043C
  lbz       r3, 0x0(r28)
  bl        -0x101C4
  lmw       r28, 0x18(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void Get_DirectPCM_LoopRemain(DSPchannel_ *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001BD00
 * Size:	00000C
 */
void Get_DirectPCM_Counter(DSPchannel_ *)
{
/*
.loc_0x0:
  lwz       r0, 0x68(r3)
  rlwinm    r3,r0,16,16,31
  blr
*/
}

/*
 * --INFO--
 * Address:	8001BD20
 * Size:	000008
 */
void Get_DirectPCM_Remain(DSPchannel_ *)
{
/*
.loc_0x0:
  lwz       r3, 0x74(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001BD40
 * Size:	00003C
 */
void __DVDReadAsyncRetry()
{
/*
.loc_0x0:
  mflr      r0
  li        r8, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r7, -0x7ED0(r13)
  lwz       r3, 0x0(r7)
  lwz       r4, 0x4(r7)
  lwz       r5, 0x8(r7)
  lwz       r6, 0xC(r7)
  lwz       r7, 0x10(r7)
  bl        0x1E38B4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001BD80
 * Size:	000048
 */
void DVDReadAsyncPrio2(DVDFileInfo *, void *, long, long, void (*) (long, DVDFileInfo *), long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r8, -0x7ED0(r13)
  stw       r3, 0x0(r8)
  lwz       r3, -0x7ED0(r13)
  stw       r4, 0x4(r3)
  lwz       r3, -0x7ED0(r13)
  stw       r5, 0x8(r3)
  lwz       r3, -0x7ED0(r13)
  stw       r6, 0xC(r3)
  lwz       r3, -0x7ED0(r13)
  stw       r7, 0x10(r3)
  bl        -0x74
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001BDE0
 * Size:	00014C
 */
void __LoadFin(long, DVDFileInfo *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x2
  stw       r0, 0x4(r1)
  addi      r0, r5, 0x1A50
  li        r5, 0
  lis       r3, 0x8037
  mullw     r5, r5, r0
  stwu      r1, -0x28(r1)
  subi      r0, r3, 0x7160
  stmw      r28, 0x18(r1)
  add       r5, r0, r5
  addis     r3, r5, 0x2
  addi      r0, r3, 0x19B8
  cmplw     r4, r0
  bne-      .loc_0x40
  mr        r31, r5

.loc_0x40:
  addis     r3, r31, 0x2
  li        r0, 0
  stw       r0, 0x1A48(r3)
  lbz       r30, 0x1942(r3)
  lbz       r0, 0x1A34(r3)
  rlwinm    r3,r30,4,0,27
  addis     r29, r3, 0x2
  cmplwi    r0, 0x1
  addi      r29, r29, 0x18C0
  add       r29, r31, r29
  bne-      .loc_0xE4
  lwz       r28, 0xC(r29)
  li        r4, 0x20
  addi      r3, r28, 0
  bl        0x1DAD60
  lbz       r0, 0x0(r28)
  cmplwi    r0, 0xFF
  bne-      .loc_0xE4
  lbz       r0, 0x1(r28)
  cmplwi    r0, 0xAD
  bne-      .loc_0xE4
  lbz       r0, 0x2(r28)
  cmplwi    r0, 0xBE
  bne-      .loc_0xE4
  lbz       r0, 0x3(r28)
  cmplwi    r0, 0xEF
  bne-      .loc_0xE4
  lbz       r0, 0x4(r28)
  cmplwi    r0, 0xDE
  bne-      .loc_0xE4
  lbz       r0, 0x5(r28)
  cmplwi    r0, 0xAD
  bne-      .loc_0xE4
  lbz       r0, 0x6(r28)
  cmplwi    r0, 0xBE
  bne-      .loc_0xE4
  lbz       r0, 0x7(r28)
  cmplwi    r0, 0xEF
  bne-      .loc_0xE4
  bl        -0x17C
  b         .loc_0x138

.loc_0xE4:
  li        r0, 0x2
  addis     r4, r31, 0x2
  stb       r0, 0x0(r29)
  addi      r5, r30, 0x1
  lbz       r3, 0x1941(r4)
  divwu     r0, r5, r3
  mullw     r0, r0, r3
  sub       r0, r5, r0
  stb       r0, 0x1942(r4)
  lwz       r0, 0x1970(r4)
  cmplwi    r0, 0
  bne-      .loc_0x120
  li        r0, 0x1
  stw       r0, 0x1A44(r4)
  b         .loc_0x138

.loc_0x120:
  lbz       r0, 0x1A34(r4)
  cmplwi    r0, 0
  beq-      .loc_0x138
  addi      r3, r31, 0
  li        r4, 0
  bl        0x2C

.loc_0x138:
  lmw       r28, 0x18(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001BF40
 * Size:	000190
 */
void LoadADPCM(StreamCtrl_ *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r28, 0x20(r1)
  addi      r29, r3, 0
  addi      r28, r4, 0
  addis     r4, r29, 0x2
  lbz       r3, 0x1942(r4)
  lwz       r0, 0x1A48(r4)
  rlwinm    r3,r3,4,0,27
  addis     r30, r3, 0x2
  cmpwi     r0, 0
  addi      r30, r30, 0x18C0
  add       r30, r29, r30
  bne-      .loc_0x17C
  lbz       r0, 0x0(r30)
  cmplwi    r0, 0
  bne-      .loc_0x17C
  lwz       r3, 0x1970(r4)
  cmplwi    r3, 0
  beq-      .loc_0x17C
  lwz       r0, 0x1978(r4)
  cmplw     r3, r0
  mr        r31, r0
  bge-      .loc_0x68
  mr        r31, r3

.loc_0x68:
  addis     r3, r29, 0x2
  lbz       r0, 0x1A34(r3)
  cmplwi    r0, 0
  bne-      .loc_0x88
  mr        r3, r31
  bl        0x1B84
  cmpwi     r3, 0
  beq-      .loc_0x17C

.loc_0x88:
  li        r4, 0
  cmpwi     r28, 0
  stw       r4, 0x4(r30)
  li        r0, 0x1
  stw       r31, 0x8(r30)
  stb       r0, 0x0(r30)
  beq-      .loc_0xB0
  addis     r3, r29, 0x2
  stw       r31, 0x194C(r3)
  stw       r4, 0x1948(r3)

.loc_0xB0:
  addis     r29, r29, 0x2
  lwz       r28, 0x1974(r29)
  add       r0, r28, r31
  stw       r0, 0x1974(r29)
  lwz       r0, 0x1970(r29)
  sub       r0, r0, r31
  stw       r0, 0x1970(r29)
  stw       r31, 0x197C(r29)
  lbz       r0, 0x1A34(r29)
  cmpwi     r0, 0x1
  beq-      .loc_0x10C
  bge-      .loc_0x17C
  cmpwi     r0, 0
  bge-      .loc_0xEC
  b         .loc_0x17C

.loc_0xEC:
  lwz       r3, 0xC(r30)
  mr        r4, r31
  bl        0x1B2C
  addi      r4, r29, 0
  addi      r3, r31, 0
  addi      r4, r4, 0x19B8
  bl        -0x264
  b         .loc_0x17C

.loc_0x10C:
  lwz       r7, 0xC(r30)
  li        r0, 0xFF
  li        r6, 0xAD
  li        r5, 0xBE
  stb       r0, 0x0(r7)
  li        r3, 0xEF
  li        r0, 0xDE
  addi      r4, r31, 0
  stb       r6, 0x1(r7)
  stb       r5, 0x2(r7)
  stb       r3, 0x3(r7)
  stb       r0, 0x4(r7)
  stb       r6, 0x5(r7)
  stb       r5, 0x6(r7)
  stb       r3, 0x7(r7)
  lwz       r3, 0xC(r30)
  bl        0x1DAB90
  li        r0, 0x1
  lis       r4, 0x8002
  stw       r0, 0x1A48(r29)
  addi      r3, r29, 0
  subi      r7, r4, 0x4220
  addi      r5, r31, 0
  lwz       r4, 0xC(r30)
  addi      r6, r28, 0
  li        r8, 0x1
  addi      r3, r3, 0x19B8
  bl        -0x338

.loc_0x17C:
  lmw       r28, 0x20(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001C0E0
 * Size:	000020
 */
void BufContInit(BufControl_ *, unsigned char, unsigned char, unsigned char, unsigned char, unsigned long, unsigned long, unsigned long)
{
/*
.loc_0x0:
  stb       r4, 0x0(r3)
  stb       r5, 0x1(r3)
  stb       r6, 0x2(r3)
  stb       r7, 0x3(r3)
  stw       r8, 0x4(r3)
  stw       r9, 0x8(r3)
  stw       r10, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001C100
 * Size:	000030
 */
void Init_StreamAudio(void)
{
/*
.loc_0x0:
  lis       r4, 0x2
  lis       r3, 0x8037
  addi      r0, r4, 0x1A50
  li        r6, 0
  mullw     r4, r6, r0
  subi      r0, r3, 0x7160
  li        r5, 0x4
  add       r3, r0, r4
  addis     r3, r3, 0x2
  stw       r5, 0x1984(r3)
  stw       r6, 0x1A0C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Get_StreamAudio_Handle(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001C140
 * Size:	000318
 */
void StreamAudio_Start(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x8037
  stw       r0, 0x4(r1)
  lis       r9, 0x2
  addi      r0, r9, 0x1A50
  subi      r7, r7, 0x7160
  stwu      r1, -0x40(r1)
  mullw     r9, r3, r0
  li        r0, 0
  stmw      r27, 0x2C(r1)
  cmplwi    r5, 0
  addi      r30, r6, 0
  addi      r27, r8, 0
  add       r31, r7, r9
  addis     r29, r31, 0x2
  stw       r3, 0x1A0C(r29)
  stw       r4, 0x1A10(r29)
  stw       r0, 0x19AC(r29)
  stw       r0, 0x19B4(r29)
  stw       r0, 0x19B0(r29)
  beq-      .loc_0x70
  addi      r4, r29, 0
  addi      r3, r5, 0
  addi      r4, r4, 0x19B8
  bl        -0x140A0
  li        r0, 0x1
  stb       r0, 0x1A34(r29)
  b         .loc_0x74

.loc_0x70:
  stb       r0, 0x1A34(r29)

.loc_0x74:
  cmplwi    r27, 0
  bne-      .loc_0xE4
  addis     r29, r31, 0x2
  lbz       r0, 0x1A34(r29)
  cmplwi    r0, 0
  bne-      .loc_0x94
  li        r3, 0
  b         .loc_0x304

.loc_0x94:
  addi      r3, r29, 0
  addi      r4, r31, 0
  li        r5, 0x20
  li        r6, 0
  li        r7, 0x1
  addi      r3, r3, 0x19B8
  bl        0x1E3520
  li        r0, 0x4
  addi      r5, r29, 0x1980
  subi      r4, r31, 0x8
  mtctr     r0

.loc_0xC0:
  lwzu      r3, 0x8(r4)
  lwz       r0, 0x4(r4)
  stwu      r3, 0x8(r5)
  stw       r0, 0x4(r5)
  bdnz+     .loc_0xC0
  addis     r3, r31, 0x2
  li        r0, 0x20
  stw       r0, 0x1974(r3)
  b         .loc_0x118

.loc_0xE4:
  addis     r3, r31, 0x2
  li        r0, 0x4
  addi      r5, r3, 0x1980
  subi      r4, r27, 0x8
  mtctr     r0

.loc_0xF8:
  lwzu      r3, 0x8(r4)
  lwz       r0, 0x4(r4)
  stwu      r3, 0x8(r5)
  stw       r0, 0x4(r5)
  bdnz+     .loc_0xF8
  addis     r3, r31, 0x2
  li        r0, 0
  stw       r0, 0x1974(r3)

.loc_0x118:
  addis     r7, r31, 0x2
  li        r6, 0
  lwz       r3, 0x1988(r7)
  li        r0, 0x6
  addi      r4, r6, 0
  stw       r3, 0x1970(r7)
  li        r3, 0
  lwz       r5, 0x198C(r7)
  stw       r5, 0x19FC(r7)
  stw       r6, 0x1980(r7)
  stw       r6, 0x1A40(r7)
  stw       r6, 0x1A44(r7)
  stw       r6, 0x1A08(r7)
  stw       r6, 0x1984(r7)
  mtctr     r0

.loc_0x154:
  add       r5, r31, r4
  add       r0, r31, r3
  addis     r5, r5, 0x2
  addi      r3, r3, 0x2420
  stb       r6, 0x18C0(r5)
  addi      r4, r4, 0x10
  stw       r0, 0x18CC(r5)
  bdnz+     .loc_0x154
  li        r0, 0x2
  li        r5, 0
  li        r3, 0
  mtctr     r0

.loc_0x184:
  addis     r4, r3, 0x2
  addi      r3, r3, 0x10
  addi      r4, r4, 0x1920
  stbx      r5, r31, r4
  bdnz+     .loc_0x184
  addis     r29, r31, 0x2
  li        r0, 0x1000
  addi      r3, r29, 0
  stw       r0, 0x1A00(r29)
  li        r4, 0x1
  li        r5, 0x6
  li        r6, 0
  li        r7, 0
  li        r8, 0x2400
  li        r9, 0
  li        r10, 0
  addi      r3, r3, 0x1940
  bl        -0x228
  addi      r3, r29, 0
  li        r4, 0x2
  li        r5, 0x2
  li        r6, 0
  li        r7, 0
  li        r8, 0x2000
  li        r9, 0
  li        r10, 0
  addi      r3, r3, 0x1950
  bl        -0x250
  addi      r3, r29, 0
  li        r4, 0x2
  li        r5, 0x4
  li        r6, 0
  li        r7, 0x3
  li        r8, 0x400
  li        r9, 0
  li        r10, 0
  addi      r3, r3, 0x1960
  bl        -0x278
  lhz       r0, 0x1992(r29)
  cmpwi     r0, 0x4
  beq-      .loc_0x260
  bge-      .loc_0x23C
  cmpwi     r0, 0x2
  beq-      .loc_0x248
  bge-      .loc_0x254
  b         .loc_0x274

.loc_0x23C:
  cmpwi     r0, 0x6
  bge-      .loc_0x274
  b         .loc_0x26C

.loc_0x248:
  li        r0, 0x2400
  stw       r0, 0x1978(r29)
  b         .loc_0x274

.loc_0x254:
  li        r0, 0x1200
  stw       r0, 0x1978(r29)
  b         .loc_0x274

.loc_0x260:
  li        r0, 0x2400
  stw       r0, 0x1978(r29)
  b         .loc_0x274

.loc_0x26C:
  li        r0, 0x2400
  stw       r0, 0x1978(r29)

.loc_0x274:
  addis     r5, r31, 0x2
  li        r29, 0
  stw       r30, 0x19A8(r5)
  addi      r3, r31, 0
  li        r4, 0x1
  stw       r29, 0x1A48(r5)
  bl        -0x48C
  li        r27, 0
  li        r30, 0

.loc_0x298:
  addis     r28, r30, 0x2
  addi      r28, r28, 0x19F4
  add       r28, r31, r28
  lwz       r3, 0x0(r28)
  mr        r4, r28
  bl        -0x1156C
  addi      r27, r27, 0x1
  stw       r29, 0x0(r28)
  cmplwi    r27, 0x2
  addi      r30, r30, 0x4
  blt+      .loc_0x298
  lfs       f0, -0x7DF8(r2)
  addis     r6, r31, 0x2
  lis       r3, 0x8002
  li        r5, 0x3FFF
  stfs      f0, 0x1A30(r6)
  li        r0, 0x5FFF
  subi      r3, r3, 0x3BA0
  mr        r4, r31
  sth       r5, 0x1A28(r6)
  sth       r5, 0x1A2A(r6)
  sth       r0, 0x1A2C(r6)
  sth       r0, 0x1A2E(r6)
  lwz       r0, 0x2D60(r13)
  stw       r0, 0x1A14(r6)
  bl        -0x1527C
  li        r3, 0x1

.loc_0x304:
  lmw       r27, 0x2C(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001C460
 * Size:	0008A8
 */
void StreamAudio_Callback(void *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  addi      r11, r1, 0x68
  bl        0x1F89F4
  stmw      r20, 0x28(r1)
  addis     r4, r3, 0x2
  li        r25, 0
  lwz       r0, 0x19F4(r4)
  addi      r31, r3, 0
  cmplwi    r0, 0
  bne-      .loc_0x70
  li        r20, 0
  li        r21, 0
  li        r22, 0x7F

.loc_0x3C:
  addis     r23, r21, 0x2
  li        r3, 0
  addi      r23, r23, 0x19F4
  add       r23, r31, r23
  addi      r4, r23, 0
  bl        -0x11750
  stw       r3, 0x0(r23)
  addi      r20, r20, 0x1
  cmplwi    r20, 0x2
  addi      r21, r21, 0x4
  lwz       r3, 0x0(r23)
  stb       r22, 0x3(r3)
  blt+      .loc_0x3C

.loc_0x70:
  addis     r21, r31, 0x2
  lwz       r0, 0x1A08(r21)
  cmplwi    r0, 0
  beq-      .loc_0x200
  lwz       r3, 0x19F4(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10F88
  lhz       r0, 0x2(r3)
  mr        r20, r3
  cmplwi    r0, 0
  beq-      .loc_0xA4
  li        r0, 0x1
  stw       r0, 0x19B4(r21)

.loc_0xA4:
  addis     r21, r31, 0x2
  lwz       r0, 0x19B4(r21)
  cmpwi     r0, 0
  beq-      .loc_0x164
  lbz       r0, 0x1942(r21)
  rlwinm    r0,r0,4,0,27
  add       r3, r21, r0
  lbz       r0, 0x18C0(r3)
  cmplwi    r0, 0x1
  bne-      .loc_0xD4
  li        r3, 0
  b         .loc_0x88C

.loc_0xD4:
  li        r20, 0
  li        r21, 0
  addi      r22, r20, 0

.loc_0xE0:
  addis     r23, r21, 0x2
  addi      r23, r23, 0x19F4
  add       r23, r31, r23
  lwz       r3, 0x0(r23)
  bl        -0x970
  lwz       r3, 0x0(r23)
  mr        r4, r23
  bl        -0x116DC
  addi      r20, r20, 0x1
  stw       r22, 0x0(r23)
  cmplwi    r20, 0x2
  addi      r21, r21, 0x4
  blt+      .loc_0xE0
  addis     r3, r31, 0x2
  lwz       r12, 0x1A14(r3)
  cmplwi    r12, 0
  beq-      .loc_0x134
  lwz       r3, 0x1A0C(r3)
  li        r4, -0x1
  mtlr      r12
  blrl      

.loc_0x134:
  addis     r3, r31, 0x2
  li        r0, 0x4
  stw       r0, 0x1984(r3)
  li        r0, -0x1
  stw       r0, 0x1A10(r3)
  lbz       r0, 0x1A34(r3)
  cmplwi    r0, 0
  beq-      .loc_0x15C
  addi      r3, r3, 0x19B8
  bl        0x1E2E1C

.loc_0x15C:
  li        r3, -0x1
  b         .loc_0x88C

.loc_0x164:
  lwz       r3, 0x1980(r21)
  lhz       r0, 0x1996(r21)
  lwz       r12, 0x1A14(r21)
  mullw     r3, r3, r0
  lhz       r0, 0x1990(r21)
  cmplwi    r12, 0
  divwu     r4, r3, r0
  beq-      .loc_0x1A0
  lwz       r3, 0x1A0C(r21)
  mtlr      r12
  blrl      
  cmpwi     r3, -0x1
  bne-      .loc_0x1A0
  li        r0, 0x1
  stw       r0, 0x19AC(r21)

.loc_0x1A0:
  addis     r21, r31, 0x2
  addi      r3, r20, 0
  lwz       r4, 0x1A08(r21)
  addi      r0, r4, 0x1
  stw       r0, 0x1A08(r21)
  bl        -0x914
  lwz       r4, 0x1A00(r21)
  rlwinm    r0,r3,0,16,31
  sub       r3, r4, r0
  rlwinm.   r0,r3,0,16,31
  bne-      .loc_0x1D0
  rlwinm    r3,r4,0,16,31

.loc_0x1D0:
  rlwinm    r0,r3,0,16,31
  addis     r3, r31, 0x2
  sub       r0, r4, r0
  rlwinm    r4,r0,22,10,31
  rlwinm    r0,r0,22,24,31
  stb       r0, 0x1963(r3)
  lbz       r0, 0x1962(r3)
  cmplw     r0, r4
  beq-      .loc_0x1FC
  li        r25, 0x1
  b         .loc_0x200

.loc_0x1FC:
  li        r25, 0

.loc_0x200:
  addis     r3, r31, 0x2
  lwz       r0, 0x1A38(r3)
  cmplwi    r0, 0
  beq-      .loc_0x25C
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x220
  mr        r3, r31
  bl        0xF44

.loc_0x220:
  addis     r3, r31, 0x2
  lwz       r0, 0x1A38(r3)
  rlwinm.   r0,r0,0,30,30
  beq-      .loc_0x238
  mr        r3, r31
  bl        0xE6C

.loc_0x238:
  addis     r21, r31, 0x2
  li        r0, 0
  stw       r0, 0x1A38(r21)
  lwz       r3, 0x19F4(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10B8C
  lwz       r3, 0x19F8(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10B98

.loc_0x25C:
  addis     r21, r31, 0x2
  lwz       r3, 0x19B0(r21)
  cmpwi     r3, 0
  beq-      .loc_0x2B4
  lwz       r3, 0x19F4(r21)
  li        r4, 0x1
  lbz       r3, 0x0(r3)
  bl        -0x10FD8
  lwz       r3, 0x19F8(r21)
  li        r4, 0x1
  lbz       r3, 0x0(r3)
  bl        -0x10FE8
  lwz       r3, 0x19F4(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10BD4
  lwz       r3, 0x19F8(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10BE0
  li        r0, 0x6
  li        r3, 0
  stw       r0, 0x1984(r21)
  b         .loc_0x88C

.loc_0x2B4:
  lwz       r0, 0x1984(r21)
  cmplwi    r0, 0x6
  bne-      .loc_0x314
  cmpwi     r3, 0
  bne-      .loc_0x30C
  li        r0, 0x1
  li        r4, 0
  stw       r0, 0x1984(r21)
  lwz       r3, 0x19F4(r21)
  lbz       r3, 0x0(r3)
  bl        -0x1103C
  lwz       r3, 0x19F8(r21)
  li        r4, 0
  lbz       r3, 0x0(r3)
  bl        -0x1104C
  lwz       r3, 0x19F4(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10C38
  lwz       r3, 0x19F8(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10C44
  b         .loc_0x314

.loc_0x30C:
  li        r3, 0
  b         .loc_0x88C

.loc_0x314:
  addis     r27, r31, 0x2
  lwz       r0, 0x1A44(r27)
  cmpwi     r0, 0
  bne-      .loc_0x3AC
  lwz       r0, 0x1984(r27)
  cmplwi    r0, 0x5
  beq-      .loc_0x3AC
  lwz       r0, 0x1A08(r27)
  cmplwi    r0, 0
  beq-      .loc_0x3AC
  lwz       r3, 0x19F4(r27)
  lbz       r3, 0x0(r3)
  bl        -0x11244
  bl        -0xA88
  lwz       r4, 0x19FC(r27)
  lwz       r0, 0x1A40(r27)
  sub       r3, r4, r3
  sub       r0, r0, r3
  stw       r0, 0x1A4C(r27)
  lwz       r0, 0x1A4C(r27)
  cmpwi     r0, 0x400
  bge-      .loc_0x3AC
  lwz       r3, 0x19F4(r27)
  li        r4, 0x1
  lbz       r3, 0x0(r3)
  bl        -0x110D8
  lwz       r3, 0x19F8(r27)
  li        r4, 0x1
  lbz       r3, 0x0(r3)
  bl        -0x110E8
  lwz       r3, 0x19F4(r27)
  lbz       r3, 0x0(r3)
  bl        -0x10CD4
  lwz       r3, 0x19F8(r27)
  lbz       r3, 0x0(r3)
  bl        -0x10CE0
  li        r0, 0x5
  stw       r0, 0x1984(r27)

.loc_0x3AC:
  addis     r21, r31, 0x2
  lwz       r0, 0x1984(r21)
  cmplwi    r0, 0x5
  bne-      .loc_0x470
  lwz       r3, 0x19F4(r21)
  lbz       r3, 0x0(r3)
  bl        -0x112C4
  bl        -0xB08
  lwz       r4, 0x19FC(r21)
  lwz       r0, 0x1A40(r21)
  sub       r3, r4, r3
  sub       r0, r0, r3
  cmplwi    r0, 0xC00
  bgt-      .loc_0x3F0
  lwz       r0, 0x1A44(r21)
  cmpwi     r0, 0x1
  bne-      .loc_0x438

.loc_0x3F0:
  addis     r21, r31, 0x2
  li        r4, 0
  lwz       r3, 0x19F4(r21)
  lbz       r3, 0x0(r3)
  bl        -0x11160
  lwz       r3, 0x19F8(r21)
  li        r4, 0
  lbz       r3, 0x0(r3)
  bl        -0x11170
  lwz       r3, 0x19F4(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10D5C
  lwz       r3, 0x19F8(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10D68
  li        r0, 0x1
  stw       r0, 0x1984(r21)
  b         .loc_0x470

.loc_0x438:
  lwz       r3, 0x19F4(r21)
  li        r4, 0x1
  lbz       r3, 0x0(r3)
  bl        -0x111A4
  lwz       r3, 0x19F8(r21)
  li        r4, 0x1
  lbz       r3, 0x0(r3)
  bl        -0x111B4
  lwz       r3, 0x19F4(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10DA0
  lwz       r3, 0x19F8(r21)
  lbz       r3, 0x0(r3)
  bl        -0x10DAC

.loc_0x470:
  addis     r27, r31, 0x2
  lbz       r0, 0x1943(r27)
  rlwinm    r0,r0,4,0,27
  add       r3, r27, r0
  lbz       r0, 0x18C0(r3)
  cmplwi    r0, 0x2
  bne-      .loc_0x538
  lbz       r0, 0x1952(r27)
  rlwinm    r0,r0,4,0,27
  add       r3, r27, r0
  lbz       r0, 0x1920(r3)
  cmplwi    r0, 0
  bne-      .loc_0x538
  mr        r3, r31
  bl        0x898
  lbz       r0, 0x1943(r27)
  li        r7, 0
  li        r6, 0x2
  li        r4, 0x6
  rlwinm    r0,r0,4,0,27
  add       r5, r27, r0
  stb       r7, 0x18C0(r5)
  lbz       r0, 0x1952(r27)
  rlwinm    r0,r0,4,0,27
  add       r5, r27, r0
  stb       r6, 0x1920(r5)
  lbz       r0, 0x1952(r27)
  rlwinm    r0,r0,4,0,27
  add       r5, r27, r0
  stw       r7, 0x1924(r5)
  lbz       r0, 0x1952(r27)
  rlwinm    r0,r0,4,0,27
  add       r5, r27, r0
  stw       r3, 0x1928(r5)
  lbz       r5, 0x1943(r27)
  addi      r5, r5, 0x1
  divw      r0, r5, r4
  mullw     r0, r0, r4
  sub       r0, r5, r0
  stb       r0, 0x1943(r27)
  lbz       r4, 0x1952(r27)
  addi      r4, r4, 0x1
  srawi     r0, r4, 0x1
  addze     r0, r0
  rlwinm    r0,r0,1,0,30
  subc      r0, r4, r0
  stb       r0, 0x1952(r27)
  lwz       r0, 0x195C(r27)
  add       r0, r0, r3
  stw       r0, 0x195C(r27)

.loc_0x538:
  cmpwi     r25, 0x1
  beq-      .loc_0x550
  addis     r3, r31, 0x2
  lwz       r0, 0x1A08(r3)
  cmplwi    r0, 0
  bne-      .loc_0x7B4

.loc_0x550:
  addis     r27, r31, 0x2
  lbz       r3, 0x1962(r27)
  lbz       r0, 0x1963(r27)
  cmplw     r3, r0
  beq-      .loc_0x5C4
  lbz       r0, 0x1953(r27)
  rlwinm    r0,r0,4,0,27
  add       r3, r27, r0
  lbz       r0, 0x1920(r3)
  cmplwi    r0, 0x2
  bne-      .loc_0x7B4
  lwz       r3, 0x195C(r27)
  lwz       r0, 0x1964(r27)
  cmplw     r3, r0
  blt-      .loc_0x7B4
  mr        r3, r31
  bl        0x810
  lbz       r3, 0x1962(r27)
  addi      r3, r3, 0x1
  srawi     r0, r3, 0x2
  addze     r0, r0
  rlwinm    r0,r0,2,0,29
  subc      r0, r3, r0
  stb       r0, 0x1962(r27)
  lwz       r3, 0x1964(r27)
  lwz       r0, 0x195C(r27)
  sub       r0, r0, r3
  stw       r0, 0x195C(r27)
  b         .loc_0x7B4

.loc_0x5C4:
  lwz       r0, 0x1A08(r27)
  cmplwi    r0, 0
  bne-      .loc_0x7B4
  lwz       r0, 0x19A8(r27)
  cmpwi     r0, 0x1
  bne-      .loc_0x63C
  lwz       r12, 0x1A14(r27)
  cmplwi    r12, 0
  beq-      .loc_0x61C
  lwz       r3, 0x1A0C(r27)
  li        r4, 0
  mtlr      r12
  blrl      
  cmpwi     r3, -0x1
  bne-      .loc_0x608
  li        r0, 0x1
  stw       r0, 0x19AC(r27)

.loc_0x608:
  cmpwi     r3, 0x1
  bne-      .loc_0x61C
  addis     r3, r31, 0x2
  li        r0, 0
  stw       r0, 0x19A8(r3)

.loc_0x61C:
  addis     r3, r31, 0x2
  li        r0, 0x2
  stw       r0, 0x1984(r3)
  lwz       r0, 0x19AC(r3)
  cmpwi     r0, 0
  bne-      .loc_0x7B4
  li        r3, 0
  b         .loc_0x88C

.loc_0x63C:
  li        r0, 0x1
  stw       r0, 0x1984(r27)
  lwz       r3, 0x1A08(r27)
  addi      r0, r3, 0x1
  stw       r0, 0x1A08(r27)
  bl        -0x16C10
  lis       r4, 0x1
  lfs       f30, -0x7DF4(r2)
  lfd       f31, -0x7DF0(r2)
  addi      r28, r3, 0
  subi      r30, r4, 0x4003
  li        r25, 0
  li        r23, 0
  li        r22, 0
  li        r21, 0
  lis       r29, 0x4330

.loc_0x67C:
  lhz       r0, 0x1990(r27)
  addis     r26, r21, 0x2
  addi      r26, r26, 0x19F4
  addis     r4, r22, 0x2
  stw       r0, 0x24(r1)
  add       r26, r31, r26
  lwz       r0, 0x1A00(r27)
  subi      r4, r4, 0x2740
  stw       r29, 0x20(r1)
  add       r4, r31, r4
  lfs       f1, 0x1A30(r27)
  rlwinm    r5,r0,0,16,31
  lfd       f2, 0x20(r1)
  lfs       f0, -0x8000(r13)
  fsubs     f2, f2, f31
  lwz       r3, 0x0(r26)
  lwz       r6, 0x19FC(r27)
  fmuls     f2, f30, f2
  fmuls     f1, f2, f1
  fdivs     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x18(r1)
  lwz       r24, 0x1C(r1)
  bl        -0xF18
  cmpwi     r28, 0
  beq-      .loc_0x6E8
  b         .loc_0x748

.loc_0x6E8:
  addis     r20, r23, 0x2
  lwz       r3, 0x0(r26)
  addi      r20, r20, 0x1A28
  rlwinm    r4,r25,0,24,31
  add       r20, r31, r20
  lbz       r3, 0x0(r3)
  lhz       r0, 0x0(r20)
  li        r6, 0
  mullw     r0, r0, r30
  srawi     r0, r0, 0x10
  addze     r0, r0
  extsh     r5, r0
  bl        -0x11578
  lhz       r0, 0x0(r20)
  subfic    r4, r25, 0x1
  lwz       r3, 0x0(r26)
  li        r6, 0
  mullw     r0, r0, r30
  lbz       r3, 0x0(r3)
  srawi     r0, r0, 0x10
  addze     r0, r0
  extsh     r5, r0
  bl        -0x115A0
  b         .loc_0x780

.loc_0x748:
  addis     r5, r23, 0x2
  lwz       r3, 0x0(r26)
  addi      r5, r5, 0x1A28
  rlwinm    r4,r25,0,24,31
  lbz       r3, 0x0(r3)
  li        r6, 0
  lhax      r5, r31, r5
  bl        -0x115C4
  lwz       r3, 0x0(r26)
  subfic    r4, r25, 0x1
  li        r5, 0
  li        r6, 0
  lbz       r3, 0x0(r3)
  bl        -0x115DC

.loc_0x780:
  lwz       r3, 0x0(r26)
  mr        r4, r24
  lbz       r3, 0x0(r3)
  bl        -0x1164C
  lwz       r3, 0x0(r26)
  lbz       r3, 0x0(r3)
  bl        -0x110D8
  addi      r25, r25, 0x1
  addi      r22, r22, 0x2000
  cmplwi    r25, 0x2
  addi      r21, r21, 0x4
  addi      r23, r23, 0x2
  blt+      .loc_0x67C

.loc_0x7B4:
  addis     r4, r31, 0x2
  lwz       r0, 0x1984(r4)
  cmplwi    r0, 0x3
  bne-      .loc_0x7CC
  li        r3, 0
  b         .loc_0x88C

.loc_0x7CC:
  lwz       r0, 0x19AC(r4)
  cmpwi     r0, 0
  beq-      .loc_0x87C
  lwz       r0, 0x1A08(r4)
  cmplwi    r0, 0
  bne-      .loc_0x844
  lbz       r0, 0x1942(r4)
  rlwinm    r0,r0,4,0,27
  add       r3, r4, r0
  lbz       r0, 0x18C0(r3)
  cmplwi    r0, 0x1
  bne-      .loc_0x804
  li        r3, 0
  b         .loc_0x88C

.loc_0x804:
  li        r0, 0
  stw       r0, 0x19AC(r4)
  lwz       r12, 0x1A14(r4)
  cmplwi    r12, 0
  beq-      .loc_0x828
  lwz       r3, 0x1A0C(r4)
  li        r4, -0x1
  mtlr      r12
  blrl      

.loc_0x828:
  addis     r4, r31, 0x2
  li        r0, 0x4
  stw       r0, 0x1984(r4)
  li        r0, -0x1
  li        r3, -0x1
  stw       r0, 0x1A10(r4)
  b         .loc_0x88C

.loc_0x844:
  li        r20, 0
  li        r0, 0x3
  stw       r20, 0x19AC(r4)
  li        r24, 0
  stw       r0, 0x1984(r4)

.loc_0x858:
  addis     r3, r24, 0x2
  addi      r3, r3, 0x19F4
  lwzx      r3, r31, r3
  bl        -0x11B64
  addi      r20, r20, 0x1
  addi      r24, r24, 0x4
  cmplwi    r20, 0x2
  blt+      .loc_0x858
  b         .loc_0x888

.loc_0x87C:
  addi      r3, r31, 0
  li        r4, 0
  bl        -0xDA4

.loc_0x888:
  li        r3, 0

.loc_0x88C:
  lwz       r0, 0x6C(r1)
  addi      r11, r1, 0x68
  bl        0x1F81BC
  lmw       r20, 0x28(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001CD20
 * Size:	000008
 */
void RegisterStreamCallback(void)
{
/*
.loc_0x0:
  stw       r3, 0x2D60(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001CD40
 * Size:	000194
 */
void Jac_Decode_ADPCM(void)
{
/*
.loc_0x0:
  stwu      r1, -0x48(r1)
  lis       r9, 0x8022
  addi      r9, r9, 0x6F70
  rlwinm    r0,r7,0,24,31
  stmw      r24, 0x28(r1)
  li        r27, 0
  lha       r31, 0x0(r8)
  lha       r30, 0x2(r8)
  lha       r29, 0x4(r8)
  lha       r28, 0x6(r8)
  b         .loc_0x170

.loc_0x2C:
  lbz       r7, 0x0(r3)
  li        r10, 0x8
  rlwinm    r12,r7,28,28,31
  rlwinm    r7,r7,2,26,29
  add       r7, r9, r7
  lha       r11, 0x0(r7)
  lha       r7, 0x2(r7)
  mtctr     r10
  addi      r3, r3, 0x1

.loc_0x50:
  lbz       r25, 0x0(r3)
  extsh     r10, r31
  mullw     r31, r11, r10
  extsh     r30, r30
  srawi     r24, r25, 0x4
  rlwinm    r25,r25,1,27,30
  add       r26, r9, r25
  rlwinm    r24,r24,1,23,30
  mullw     r25, r7, r30
  add       r24, r9, r24
  lha       r24, 0x40(r24)
  addi      r3, r3, 0x1
  slw       r24, r24, r12
  add       r25, r31, r25
  srawi     r25, r25, 0xB
  add       r24, r24, r25
  extsh     r30, r24
  sth       r30, 0x0(r4)
  mullw     r25, r11, r30
  lha       r26, 0x40(r26)
  slw       r26, r26, r12
  mullw     r10, r7, r10
  add       r10, r25, r10
  srawi     r10, r10, 0xB
  add       r10, r26, r10
  extsh     r10, r10
  sth       r10, 0x2(r4)
  addi      r31, r10, 0
  addi      r4, r4, 0x4
  bdnz+     .loc_0x50
  cmplwi    r0, 0
  beq-      .loc_0x16C
  lbz       r7, 0x0(r3)
  li        r10, 0x8
  rlwinm    r11,r7,28,28,31
  rlwinm    r7,r7,2,26,29
  add       r7, r9, r7
  lha       r12, 0x0(r7)
  lha       r7, 0x2(r7)
  mtctr     r10
  addi      r3, r3, 0x1

.loc_0xF4:
  lbz       r24, 0x0(r3)
  extsh     r10, r29
  extsh     r28, r28
  addi      r3, r3, 0x1
  mullw     r29, r12, r10
  srawi     r25, r24, 0x4
  rlwinm    r25,r25,1,23,30
  add       r25, r9, r25
  lha       r25, 0x40(r25)
  rlwinm    r26,r24,1,27,30
  add       r26, r9, r26
  mullw     r28, r7, r28
  slw       r25, r25, r11
  add       r28, r29, r28
  srawi     r28, r28, 0xB
  add       r24, r25, r28
  extsh     r28, r24
  sth       r28, 0x0(r5)
  mullw     r29, r12, r28
  lha       r26, 0x40(r26)
  slw       r26, r26, r11
  mullw     r10, r7, r10
  add       r10, r29, r10
  srawi     r10, r10, 0xB
  add       r10, r26, r10
  extsh     r10, r10
  sth       r10, 0x2(r5)
  addi      r29, r10, 0
  addi      r5, r5, 0x4
  bdnz+     .loc_0xF4

.loc_0x16C:
  addi      r27, r27, 0x1

.loc_0x170:
  cmplw     r27, r6
  blt+      .loc_0x2C
  sth       r31, 0x0(r8)
  sth       r30, 0x2(r8)
  sth       r29, 0x4(r8)
  sth       r28, 0x6(r8)
  lmw       r24, 0x28(r1)
  addi      r1, r1, 0x48
  blr
*/
}

/*
 * --INFO--
 * Address:	8001CEE0
 * Size:	0000D0
 */
void __DecodeADPCM(StreamCtrl_ *)
{
/*
.loc_0x0:
  mflr      r0
  addis     r4, r3, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r30, 0x20(r1)
  lwz       r0, 0x1A08(r4)
  lbz       r7, 0x1952(r4)
  cmplwi    r0, 0
  lbz       r8, 0x1943(r4)
  bne-      .loc_0x54
  cmplwi    r8, 0
  bne-      .loc_0x54
  li        r4, 0
  li        r0, 0x4
  addi      r6, r4, 0
  mtctr     r0

.loc_0x40:
  addis     r5, r4, 0x2
  addi      r4, r4, 0x2
  addi      r5, r5, 0x1A18
  sthx      r6, r3, r5
  bdnz+     .loc_0x40

.loc_0x54:
  addis     r31, r3, 0x2
  rlwinm    r0,r8,4,0,27
  add       r4, r31, r0
  rlwinm    r0,r7,14,0,17
  lwz       r7, 0x18C4(r4)
  add       r5, r3, r0
  lwz       r4, 0x18C8(r4)
  mulli     r6, r8, 0x2420
  li        r0, 0x12
  sub       r4, r4, r7
  divwu     r30, r4, r0
  addis     r4, r5, 0x1
  add       r3, r3, r6
  addis     r5, r5, 0x1
  addi      r8, r31, 0
  add       r3, r3, r7
  subi      r4, r4, 0x2740
  addi      r5, r5, 0x58C0
  addi      r6, r30, 0
  li        r7, 0x1
  addi      r8, r8, 0x1A18
  bl        -0x248
  lwz       r0, 0x1980(r31)
  rlwinm    r3,r30,4,1,27
  add       r0, r0, r3
  stw       r0, 0x1980(r31)
  lmw       r30, 0x20(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001CFC0
 * Size:	000024
 */
void Clamp16(long)
{
/*
.loc_0x0:
  cmpwi     r3, 0x7FFF
  blt-      .loc_0x10
  li        r3, 0x7FFF
  b         .loc_0x1C

.loc_0x10:
  cmpwi     r3, -0x8000
  bge-      .loc_0x1C
  li        r3, -0x8000

.loc_0x1C:
  extsh     r3, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D000
 * Size:	00019C
 */
void __DecodeADPCM4X(StreamCtrl_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE8(r1)
  stmw      r17, 0xAC(r1)
  addi      r19, r3, 0
  addis     r3, r19, 0x2
  li        r18, 0
  lwz       r0, 0x1A08(r3)
  lbz       r6, 0x1952(r3)
  cmplwi    r0, 0
  lbz       r8, 0x1943(r3)
  bne-      .loc_0x5C
  cmplwi    r8, 0
  bne-      .loc_0x5C
  li        r3, 0
  li        r0, 0x4
  addi      r5, r3, 0
  mtctr     r0

.loc_0x48:
  addis     r4, r3, 0x2
  addi      r3, r3, 0x2
  addi      r4, r4, 0x1A18
  sthx      r5, r19, r4
  bdnz+     .loc_0x48

.loc_0x5C:
  addis     r4, r19, 0x2
  rlwinm    r0,r8,4,0,27
  add       r3, r4, r0
  rlwinm    r0,r6,14,0,17
  lwz       r7, 0x18C4(r3)
  add       r6, r19, r0
  lwz       r3, 0x18C8(r3)
  mulli     r5, r8, 0x2420
  li        r0, 0x24
  lhz       r21, 0x1A2C(r4)
  sub       r3, r3, r7
  lhz       r20, 0x1A2E(r4)
  divwu     r27, r3, r0
  addis     r25, r6, 0x1
  addis     r24, r6, 0x1
  add       r23, r19, r5
  add       r23, r23, r7
  addi      r28, r1, 0x6C
  addi      r29, r1, 0x2C
  addi      r30, r1, 0x4C
  addi      r31, r1, 0xC
  li        r26, 0
  subi      r25, r25, 0x2740
  addi      r24, r24, 0x58C0
  b         .loc_0x16C

.loc_0xC0:
  addis     r8, r19, 0x2
  addi      r3, r23, 0
  addi      r4, r1, 0x6C
  addi      r5, r1, 0x4C
  li        r6, 0x1
  li        r7, 0x1
  addi      r8, r8, 0x1A18
  bl        -0x39C
  addis     r8, r19, 0x2
  addi      r3, r23, 0x12
  addi      r4, r1, 0x2C
  addi      r5, r1, 0xC
  li        r6, 0x1
  li        r7, 0x1
  addi      r8, r8, 0x1A20
  bl        -0x3BC
  li        r22, 0
  li        r17, 0
  addi      r23, r23, 0x24

.loc_0x10C:
  lhax      r3, r28, r17
  lhax      r0, r29, r17
  mullw     r3, r21, r3
  mullw     r0, r20, r0
  srawi     r3, r3, 0xF
  srawi     r0, r0, 0xF
  add       r3, r3, r0
  bl        -0x168
  sthx      r3, r25, r18
  lhax      r3, r30, r17
  lhax      r0, r31, r17
  mullw     r3, r21, r3
  mullw     r0, r20, r0
  srawi     r3, r3, 0xF
  srawi     r0, r0, 0xF
  add       r3, r3, r0
  bl        -0x18C
  addi      r22, r22, 0x1
  sthx      r3, r24, r18
  cmplwi    r22, 0x10
  addi      r18, r18, 0x2
  addi      r17, r17, 0x2
  blt+      .loc_0x10C
  addi      r26, r26, 0x1

.loc_0x16C:
  cmplw     r26, r27
  blt+      .loc_0xC0
  addis     r4, r19, 0x2
  rlwinm    r3,r27,4,1,27
  lwz       r0, 0x1980(r4)
  add       r0, r0, r3
  stw       r0, 0x1980(r4)
  lmw       r17, 0xAC(r1)
  lwz       r0, 0xEC(r1)
  addi      r1, r1, 0xE8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D1A0
 * Size:	000054
 */
void __Decode(StreamCtrl_ *)
{
/*
.loc_0x0:
  mflr      r0
  addis     r4, r3, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lhz       r0, 0x1992(r4)
  cmpwi     r0, 0x5
  beq-      .loc_0x38
  bge-      .loc_0x40
  cmpwi     r0, 0x4
  bge-      .loc_0x2C
  b         .loc_0x40

.loc_0x2C:
  bl        -0x2EC
  mr        r5, r3
  b         .loc_0x40

.loc_0x38:
  bl        -0x1D8
  mr        r5, r3

.loc_0x40:
  mr        r3, r5
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D200
 * Size:	00013C
 */
void __PcmToLoop(StreamCtrl_ *)
{
/*
.loc_0x0:
  mflr      r0
  addis     r7, r3, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  lbz       r0, 0x1962(r7)
  lwz       r4, 0x1964(r7)
  rlwinm    r0,r0,11,0,20
  add       r5, r3, r0
  addis     r6, r5, 0x2
  addis     r5, r5, 0x2
  subi      r6, r6, 0x2740
  subi      r5, r5, 0x740
  addi      r11, r6, 0
  addi      r12, r5, 0
  addi      r29, r6, 0
  addi      r31, r5, 0
  b         .loc_0xEC

.loc_0x48:
  lbz       r30, 0x1953(r7)
  lwz       r6, 0x1958(r7)
  rlwinm    r5,r30,4,0,27
  rlwinm    r0,r30,14,0,17
  add       r9, r3, r5
  add       r8, r3, r0
  addis     r10, r9, 0x2
  lwzu      r0, 0x1924(r10)
  addis     r5, r9, 0x2
  lwz       r27, 0x1928(r5)
  add       r28, r6, r0
  rlwinm    r5,r28,1,0,30
  b         .loc_0xA8

.loc_0x7C:
  add       r6, r8, r5
  addi      r28, r28, 0x1
  addis     r6, r6, 0x1
  addi      r5, r5, 0x2
  lha       r0, -0x2740(r6)
  subi      r4, r4, 0x1
  sth       r0, 0x0(r11)
  addi      r11, r11, 0x2
  lha       r0, 0x58C0(r6)
  sth       r0, 0x0(r12)
  addi      r12, r12, 0x2

.loc_0xA8:
  cmplw     r28, r27
  bge-      .loc_0xB8
  cmpwi     r4, 0
  bgt+      .loc_0x7C

.loc_0xB8:
  cmplw     r28, r27
  bne-      .loc_0xE0
  addis     r5, r9, 0x2
  li        r6, 0
  addi      r0, r30, 0x1
  stb       r6, 0x1920(r5)
  rlwinm    r0,r0,0,31,31
  stb       r0, 0x1953(r7)
  stw       r6, 0x1958(r7)
  b         .loc_0xEC

.loc_0xE0:
  lwz       r0, 0x0(r10)
  sub       r0, r28, r0
  stw       r0, 0x1958(r7)

.loc_0xEC:
  cmpwi     r4, 0
  bgt+      .loc_0x48
  addis     r30, r3, 0x2
  addi      r3, r29, 0
  lwz       r0, 0x1964(r30)
  rlwinm    r4,r0,1,0,30
  bl        0x1D997C
  lwz       r0, 0x1964(r30)
  addi      r3, r31, 0
  rlwinm    r4,r0,1,0,30
  bl        0x1D996C
  lwz       r3, 0x1A40(r30)
  lwz       r0, 0x1964(r30)
  add       r0, r3, r0
  stw       r0, 0x1A40(r30)
  lwz       r0, 0x2C(r1)
  lmw       r27, 0x14(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D340
 * Size:	000038
 */
void StreamSyncCheckReady(void)
{
/*
.loc_0x0:
  lis       r5, 0x2
  lis       r4, 0x8037
  addi      r5, r5, 0x1A50
  subi      r0, r4, 0x7160
  mullw     r3, r3, r5
  add       r3, r0, r3
  addis     r3, r3, 0x2
  lwz       r0, 0x1984(r3)
  cmplwi    r0, 0x2
  bne-      .loc_0x30
  li        r3, 0x1
  blr       

.loc_0x30:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D380
 * Size:	00005C
 */
void StreamSyncCheckReadyID(void)
{
/*
.loc_0x0:
  lis       r6, 0x2
  lis       r5, 0x8037
  addi      r6, r6, 0x1A50
  subi      r0, r5, 0x7160
  mullw     r3, r3, r6
  add       r3, r0, r3
  addis     r3, r3, 0x2
  lwz       r0, 0x1A10(r3)
  cmplw     r0, r4
  bne-      .loc_0x54
  lwz       r0, 0x1984(r3)
  cmpwi     r0, 0x1
  beq-      .loc_0x54
  bge-      .loc_0x44
  cmpwi     r0, 0
  bge-      .loc_0x4C
  b         .loc_0x54

.loc_0x44:
  cmpwi     r0, 0x3
  bge-      .loc_0x54

.loc_0x4C:
  li        r3, 0x1
  blr       

.loc_0x54:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D3E0
 * Size:	000054
 */
void StreamSyncCheckBusy(void)
{
/*
.loc_0x0:
  lis       r6, 0x2
  lis       r5, 0x8037
  addi      r6, r6, 0x1A50
  subi      r0, r5, 0x7160
  mullw     r3, r3, r6
  add       r3, r0, r3
  addis     r5, r3, 0x2
  lwz       r3, 0x1984(r5)
  cmplwi    r3, 0x4
  bne-      .loc_0x30
  li        r3, 0
  blr       

.loc_0x30:
  lwz       r0, 0x1A10(r5)
  cmplw     r0, r4
  bne-      .loc_0x4C
  cmplwi    r3, 0x2
  bne-      .loc_0x4C
  li        r3, 0
  blr       

.loc_0x4C:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D440
 * Size:	000060
 */
void StreamSyncPlayAudio(void)
{
/*
.loc_0x0:
  lis       r7, 0x2
  lis       r6, 0x8037
  addi      r7, r7, 0x1A50
  subi      r0, r6, 0x7160
  mullw     r3, r3, r7
  add       r3, r0, r3
  addis     r6, r3, 0x2
  lwz       r0, 0x1984(r6)
  cmplwi    r0, 0x2
  bne-      .loc_0x58
  lwz       r0, 0x19F4(r6)
  cmplwi    r0, 0
  bne-      .loc_0x3C
  li        r3, 0
  blr       

.loc_0x3C:
  stfs      f1, 0x1A30(r6)
  li        r0, 0
  li        r3, 0x1
  sth       r4, 0x1A28(r6)
  sth       r5, 0x1A2A(r6)
  stw       r0, 0x19A8(r6)
  blr       

.loc_0x58:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D4A0
 * Size:	000050
 */
void StreamSyncStopAudio(void)
{
/*
.loc_0x0:
  lis       r5, 0x2
  lis       r4, 0x8037
  addi      r5, r5, 0x1A50
  subi      r0, r4, 0x7160
  mullw     r3, r3, r5
  add       r3, r0, r3
  addis     r4, r3, 0x2
  lwz       r0, 0x1984(r4)
  cmplwi    r0, 0x4
  bne-      .loc_0x30
  li        r3, 0
  blr       

.loc_0x30:
  cmplwi    r0, 0x3
  bne-      .loc_0x40
  li        r3, 0
  blr       

.loc_0x40:
  li        r0, 0x1
  li        r3, 0x1
  stw       r0, 0x19AC(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D500
 * Size:	0000A8
 */
void __StreamChgPitch(StreamCtrl_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r28, 0x20(r1)
  addi      r28, r3, 0
  addis     r4, r28, 0x2
  lwz       r0, 0x19F4(r4)
  cmplwi    r0, 0
  beq-      .loc_0x94
  lhz       r3, 0x1990(r4)
  lis       r0, 0x4330
  lfd       f3, -0x7DF0(r2)
  li        r29, 0
  stw       r3, 0x1C(r1)
  li        r31, 0
  lfs       f4, -0x7DF4(r2)
  stw       r0, 0x18(r1)
  lfs       f1, 0x1A30(r4)
  lfd       f2, 0x18(r1)
  lfs       f0, -0x8000(r13)
  fsubs     f2, f2, f3
  fmuls     f2, f4, f2
  fmuls     f1, f2, f1
  fdivs     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x10(r1)
  lwz       r30, 0x14(r1)

.loc_0x6C:
  addis     r3, r31, 0x2
  addi      r4, r30, 0
  addi      r3, r3, 0x19F4
  lwzx      r3, r28, r3
  lbz       r3, 0x0(r3)
  bl        -0x11FE0
  addi      r29, r29, 0x1
  addi      r31, r31, 0x4
  cmplwi    r29, 0x2
  blt+      .loc_0x6C

.loc_0x94:
  lmw       r28, 0x20(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void StreamChgPitch(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001D5C0
 * Size:	000124
 */
void __StreamChgVolume(StreamCtrl_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r24, 0x10(r1)
  addi      r29, r3, 0
  addis     r3, r29, 0x2
  lwz       r0, 0x19F4(r3)
  cmplwi    r0, 0
  beq-      .loc_0x110
  bl        -0x17744
  lis       r4, 0x1
  rlwinm    r30,r3,0,24,31
  subi      r26, r4, 0x4003
  li        r31, 0
  li        r28, 0
  li        r27, 0

.loc_0x40:
  cmpwi     r30, 0
  beq-      .loc_0x4C
  b         .loc_0xB8

.loc_0x4C:
  addis     r25, r28, 0x2
  addis     r24, r27, 0x2
  addi      r25, r25, 0x1A28
  addi      r24, r24, 0x19F4
  add       r25, r29, r25
  add       r24, r29, r24
  lhz       r0, 0x0(r25)
  rlwinm    r4,r31,0,24,31
  lwz       r3, 0x0(r24)
  li        r6, 0
  mullw     r0, r0, r26
  lbz       r3, 0x0(r3)
  srawi     r0, r0, 0x10
  addze     r0, r0
  extsh     r5, r0
  bl        -0x11FE8
  lhz       r0, 0x0(r25)
  subfic    r4, r31, 0x1
  lwz       r3, 0x0(r24)
  li        r6, 0
  mullw     r0, r0, r26
  lbz       r3, 0x0(r3)
  srawi     r0, r0, 0x10
  addze     r0, r0
  extsh     r5, r0
  bl        -0x12010
  b         .loc_0xFC

.loc_0xB8:
  addis     r24, r27, 0x2
  addis     r3, r28, 0x2
  addi      r24, r24, 0x19F4
  addi      r3, r3, 0x1A28
  add       r24, r29, r24
  lhax      r5, r29, r3
  lwz       r3, 0x0(r24)
  rlwinm    r4,r31,0,24,31
  li        r6, 0
  lbz       r3, 0x0(r3)
  bl        -0x12040
  lwz       r3, 0x0(r24)
  subfic    r4, r31, 0x1
  li        r5, 0
  li        r6, 0
  lbz       r3, 0x0(r3)
  bl        -0x12058

.loc_0xFC:
  addi      r31, r31, 0x1
  addi      r27, r27, 0x4
  cmplwi    r31, 0x2
  addi      r28, r28, 0x2
  blt+      .loc_0x40

.loc_0x110:
  lmw       r24, 0x10(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D700
 * Size:	000034
 */
void StreamChgVolume(void)
{
/*
.loc_0x0:
  lis       r7, 0x2
  lis       r6, 0x8037
  addi      r7, r7, 0x1A50
  subi      r0, r6, 0x7160
  mullw     r3, r3, r7
  add       r3, r0, r3
  addis     r3, r3, 0x2
  sth       r4, 0x1A28(r3)
  sth       r5, 0x1A2A(r3)
  lwz       r0, 0x1A38(r3)
  ori       r0, r0, 0x1
  stw       r0, 0x1A38(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D740
 * Size:	000034
 */
void StreamChgMixLevel(void)
{
/*
.loc_0x0:
  lis       r7, 0x2
  lis       r6, 0x8037
  addi      r7, r7, 0x1A50
  subi      r0, r6, 0x7160
  mullw     r3, r3, r7
  add       r3, r0, r3
  addis     r3, r3, 0x2
  lwz       r0, 0x19F4(r3)
  cmplwi    r0, 0
  beqlr-    
  sth       r4, 0x1A2C(r3)
  sth       r5, 0x1A2E(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D780
 * Size:	000190
 */
void StreamGetCurrentFrame(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x2
  lis       r5, 0x8037
  addi      r6, r6, 0x1A50
  stw       r0, 0x4(r1)
  subi      r0, r5, 0x7160
  mullw     r5, r3, r6
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  add       r5, r0, r5
  addis     r31, r5, 0x2
  lwz       r5, 0x19F4(r31)
  cmplwi    r5, 0
  bne-      .loc_0x40
  li        r3, -0x1
  b         .loc_0x17C

.loc_0x40:
  cmpwi     r4, 0x1
  beq-      .loc_0x7C
  bge-      .loc_0x58
  cmpwi     r4, 0
  bge-      .loc_0x64
  b         .loc_0x17C

.loc_0x58:
  cmpwi     r4, 0x3
  bge-      .loc_0x17C
  b         .loc_0xF8

.loc_0x64:
  lwz       r4, 0x1980(r31)
  lhz       r3, 0x1996(r31)
  lhz       r0, 0x1990(r31)
  mullw     r3, r4, r3
  divwu     r3, r3, r0
  b         .loc_0x17C

.loc_0x7C:
  lwz       r3, -0x7FFC(r13)
  lis       r4, 0x4330
  lwz       r0, -0x7FF8(r13)
  stw       r3, 0x34(r1)
  lhz       r3, 0x1996(r31)
  stw       r4, 0x30(r1)
  lwz       r5, 0x1A08(r31)
  stw       r0, 0x2C(r1)
  lfd       f4, -0x7DF0(r2)
  lfd       f0, 0x30(r1)
  stw       r4, 0x28(r1)
  fsubs     f1, f0, f4
  lfs       f2, -0x8000(r13)
  lfd       f0, 0x28(r1)
  stw       r3, 0x3C(r1)
  fmuls     f1, f2, f1
  fsubs     f0, f0, f4
  stw       r4, 0x38(r1)
  lfd       f2, 0x38(r1)
  fdivs     f0, f1, f0
  stw       r5, 0x44(r1)
  stw       r4, 0x40(r1)
  lfd       f3, 0x40(r1)
  fsubs     f1, f2, f4
  fsubs     f2, f3, f4
  fdivs     f0, f1, f0
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r3, 0x24(r1)
  b         .loc_0x17C

.loc_0xF8:
  lwz       r0, 0x1A08(r31)
  cmplwi    r0, 0
  bne-      .loc_0x10C
  li        r3, 0
  b         .loc_0x17C

.loc_0x10C:
  lbz       r3, 0x0(r5)
  bl        -0x12330
  bl        -0x1B74
  lwz       r0, 0x19FC(r31)
  lis       r5, 0x4330
  lhz       r4, 0x1996(r31)
  sub       r3, r0, r3
  lhz       r0, 0x1990(r31)
  stw       r3, 0x24(r1)
  lfd       f3, -0x7DF0(r2)
  stw       r4, 0x2C(r1)
  lfs       f4, -0x7DE8(r2)
  stw       r5, 0x20(r1)
  stw       r5, 0x28(r1)
  lfd       f1, 0x20(r1)
  stw       r0, 0x34(r1)
  lfd       f0, 0x28(r1)
  fsubs     f2, f1, f3
  stw       r5, 0x30(r1)
  fsubs     f1, f0, f3
  lfd       f0, 0x30(r1)
  fmuls     f1, f2, f1
  fsubs     f0, f0, f3
  fdivs     f0, f1, f0
  fadds     f0, f4, f0
  fctiwz    f0, f0
  stfd      f0, 0x38(r1)
  lwz       r3, 0x3C(r1)

.loc_0x17C:
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001D920
 * Size:	00003C
 */
void StreamSetDVDPause(void)
{
/*
.loc_0x0:
  lis       r6, 0x2
  lis       r5, 0x8037
  addi      r6, r6, 0x1A50
  subi      r0, r5, 0x7160
  mullw     r3, r3, r6
  add       r3, r0, r3
  addis     r5, r3, 0x2
  lwz       r0, 0x19F4(r5)
  cmplwi    r0, 0
  bne-      .loc_0x30
  li        r3, 0
  blr       

.loc_0x30:
  lwz       r3, 0x19B0(r5)
  stw       r4, 0x19B0(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void StreamCheckRemainBuffers(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001D960
 * Size:	000028
 */
void StreamCheckAudioFormat(void)
{
/*
.loc_0x0:
  lis       r5, 0x2
  lis       r4, 0x8037
  addi      r5, r5, 0x1A50
  subi      r0, r4, 0x7160
  mullw     r3, r3, r5
  add       r3, r0, r3
  addis     r3, r3, 0x2
  lhz       r0, 0x1992(r3)
  rlwinm    r3,r0,0,24,31
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void StreamCheckBufferEmpty(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void StreamCheckBufferRemainSize(void)
{
	// UNUSED FUNCTION
}
