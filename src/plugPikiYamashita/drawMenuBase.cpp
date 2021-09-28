

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
 * Address:	801F014C
 * Size:	000438
 */
void zen::DrawMenuBase::DrawMenuBase(char *, bool, bool)
{
/*
.loc_0x0:
  mflr      r0
  mr        r7, r6
  stw       r0, 0x4(r1)
  addi      r6, r5, 0
  li        r5, 0
  stwu      r1, -0x68(r1)
  stmw      r27, 0x54(r1)
  stw       r3, 0x8(r1)
  lwz       r3, 0x8(r1)
  bl        -0x30BFC
  lwz       r28, 0x8(r1)
  lis       r3, 0x802E
  addi      r0, r3, 0x7100
  stw       r0, 0x0(r28)
  li        r0, 0
  lis       r4, 0x726F
  stw       r0, 0x114(r28)
  addi      r3, r28, 0x4
  addi      r4, r4, 0x6F74
  stw       r0, 0x118(r28)
  li        r5, 0x1
  lfs       f1, -0x3E18(r2)
  stfs      f1, 0x120(r28)
  stfs      f1, 0x11C(r28)
  lfs       f0, -0x3E14(r2)
  stfs      f0, 0x130(r28)
  stfs      f0, 0x12C(r28)
  stfs      f0, 0x128(r28)
  stfs      f0, 0x124(r28)
  stfs      f1, 0x138(r28)
  stfs      f1, 0x134(r28)
  stfs      f1, 0x140(r28)
  stfs      f1, 0x13C(r28)
  stw       r0, 0x144(r28)
  stw       r0, 0x148(r28)
  stfs      f1, 0x150(r28)
  stfs      f1, 0x14C(r28)
  stfs      f0, 0x160(r28)
  stfs      f0, 0x15C(r28)
  stfs      f0, 0x158(r28)
  stfs      f0, 0x154(r28)
  stfs      f1, 0x168(r28)
  stfs      f1, 0x164(r28)
  stfs      f1, 0x170(r28)
  stfs      f1, 0x16C(r28)
  lwz       r12, 0x4(r28)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  lha       r7, 0x1A(r3)
  lha       r6, 0x1E(r3)
  lis       r4, 0x7365
  lha       r5, 0x18(r29)
  addi      r3, r28, 0x4
  lha       r0, 0x1C(r29)
  sub       r6, r6, r7
  sub       r0, r0, r5
  srawi     r6, r6, 0x1
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r29)
  extsh     r0, r6
  addi      r4, r4, 0x5F63
  sth       r0, 0xBA(r29)
  li        r5, 0x1
  lwz       r12, 0x4(r28)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lhz       r0, 0x8(r3)
  cmplwi    r0, 0x13
  bne-      .loc_0x134
  lwz       r0, 0xF4(r3)
  stw       r0, 0x178(r28)
  lwz       r0, 0xF8(r3)
  stw       r0, 0x17C(r28)

.loc_0x134:
  addi      r3, r1, 0x44
  crclr     6, 0x6
  li        r27, 0
  addi      r4, r13, 0x2930
  li        r5, 0
  bl        0x26304
  b         .loc_0x168

.loc_0x150:
  addi      r27, r27, 0x1
  crclr     6, 0x6
  addi      r5, r27, 0
  addi      r3, r1, 0x44
  addi      r4, r13, 0x2930
  bl        0x262E8

.loc_0x168:
  lwz       r28, 0x8(r1)
  li        r5, 0
  lbz       r0, 0x45(r1)
  lwz       r12, 0x4(r28)
  addi      r3, r28, 0x4
  lbz       r4, 0x44(r1)
  rlwinm    r0,r0,16,0,15
  lwz       r12, 0x34(r12)
  rlwimi    r0,r4,24,0,7
  lbz       r6, 0x46(r1)
  lbz       r4, 0x47(r1)
  mtlr      r12
  rlwimi    r0,r6,8,16,23
  or        r4, r4, r0
  blrl      
  cmplwi    r3, 0
  bne+      .loc_0x150
  stw       r27, 0x10C(r28)
  lwz       r30, 0x10C(r28)
  mulli     r3, r30, 0xC
  addi      r3, r3, 0x8
  bl        -0x1A9304
  lis       r4, 0x801C
  lis       r5, 0x801C
  addi      r4, r4, 0x3C4C
  addi      r5, r5, 0x3BF8
  addi      r7, r30, 0
  li        r6, 0xC
  bl        0x24904
  li        r31, 0
  stw       r3, 0x174(r28)
  mr        r30, r31
  b         .loc_0x3B8

.loc_0x1EC:
  addi      r5, r31, 0
  crclr     6, 0x6
  addi      r3, r1, 0x44
  addi      r4, r13, 0x2930
  bl        0x26250
  lwz       r28, 0x8(r1)
  li        r5, 0x1
  lbz       r0, 0x45(r1)
  lwz       r12, 0x4(r28)
  addi      r3, r28, 0x4
  lbz       r4, 0x44(r1)
  rlwinm    r0,r0,16,0,15
  lwz       r12, 0x34(r12)
  rlwimi    r0,r4,24,0,7
  lbz       r6, 0x46(r1)
  lbz       r4, 0x47(r1)
  mtlr      r12
  rlwimi    r0,r6,8,16,23
  or        r4, r4, r0
  blrl      
  addi      r27, r3, 0
  crclr     6, 0x6
  addi      r5, r31, 0
  addi      r3, r1, 0x44
  addi      r4, r13, 0x2938
  bl        0x261FC
  lwz       r12, 0x4(r28)
  addi      r3, r28, 0x4
  lbz       r0, 0x45(r1)
  li        r5, 0
  lwz       r12, 0x34(r12)
  lbz       r4, 0x44(r1)
  rlwinm    r0,r0,16,0,15
  lbz       r6, 0x46(r1)
  mtlr      r12
  rlwimi    r0,r4,24,0,7
  lbz       r7, 0x47(r1)
  rlwimi    r0,r6,8,16,23
  or        r4, r7, r0
  blrl      
  lwz       r0, 0x174(r28)
  addi      r5, r3, 0
  mr        r4, r27
  add       r3, r0, r30
  lwz       r3, 0x0(r3)
  bl        -0x2DBC4
  addi      r5, r31, 0
  crclr     6, 0x6
  addi      r3, r1, 0x44
  addi      r4, r13, 0x2940
  bl        0x26198
  lwz       r12, 0x4(r28)
  addi      r3, r28, 0x4
  lbz       r0, 0x45(r1)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  lbz       r4, 0x44(r1)
  rlwinm    r0,r0,16,0,15
  lbz       r6, 0x46(r1)
  mtlr      r12
  rlwimi    r0,r4,24,0,7
  lbz       r7, 0x47(r1)
  rlwimi    r0,r6,8,16,23
  or        r4, r7, r0
  blrl      
  lhz       r0, 0x8(r3)
  lwz       r4, 0x174(r28)
  cmplwi    r0, 0x12
  add       r6, r4, r30
  bne-      .loc_0x328
  stw       r3, 0x4(r6)
  li        r5, 0
  addi      r4, r29, 0
  lwz       r3, 0x4(r6)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x4(r6)
  bl        -0x308D0

.loc_0x328:
  addi      r5, r31, 0
  crclr     6, 0x6
  addi      r3, r1, 0x44
  addi      r4, r13, 0x2948
  bl        0x26114
  lwz       r28, 0x8(r1)
  li        r5, 0x1
  lbz       r0, 0x45(r1)
  lwz       r12, 0x4(r28)
  addi      r3, r28, 0x4
  lbz       r4, 0x44(r1)
  rlwinm    r0,r0,16,0,15
  lwz       r12, 0x34(r12)
  rlwimi    r0,r4,24,0,7
  lbz       r6, 0x46(r1)
  lbz       r4, 0x47(r1)
  mtlr      r12
  rlwimi    r0,r6,8,16,23
  or        r4, r4, r0
  blrl      
  lhz       r0, 0x8(r3)
  lwz       r4, 0x174(r28)
  cmplwi    r0, 0x12
  add       r6, r4, r30
  bne-      .loc_0x3B0
  stw       r3, 0x8(r6)
  li        r5, 0
  addi      r4, r29, 0
  lwz       r3, 0x8(r6)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x8(r6)
  bl        -0x30958

.loc_0x3B0:
  addi      r30, r30, 0xC
  addi      r31, r31, 0x1

.loc_0x3B8:
  lwz       r27, 0x8(r1)
  lwz       r0, 0x10C(r27)
  cmpw      r31, r0
  blt+      .loc_0x1EC
  lis       r28, 0x7A2A
  lfs       f1, -0x3E10(r2)
  lfs       f2, -0x3E0C(r2)
  addi      r5, r29, 0
  addi      r3, r27, 0x114
  addi      r4, r27, 0x4
  addi      r6, r28, 0x2A6C
  bl        -0x158F4
  lfs       f1, -0x3E08(r2)
  mr        r5, r29
  lfs       f2, -0x3E0C(r2)
  addi      r3, r27, 0x144
  addi      r4, r27, 0x4
  addi      r6, r28, 0x2A72
  bl        -0x15910
  li        r0, 0x1000
  stw       r0, 0x190(r27)
  li        r0, 0x2000
  addi      r3, r27, 0
  stw       r0, 0x194(r27)
  li        r4, 0
  bl        0xAC
  mr        r3, r27
  lmw       r27, 0x54(r1)
  lwz       r0, 0x6C(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F0584
 * Size:	000070
 */
void zen::DrawMenuBase::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r12, r30, 0x180
  stw       r0, 0x18C(r3)
  bl        0x24784
  nop       
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x3C
  li        r31, 0x1

.loc_0x3C:
  addi      r3, r30, 0x4
  bl        -0x3DA74
  addi      r3, r30, 0x114
  bl        -0x15DB8
  addi      r3, r30, 0x144
  bl        -0x15DC0
  mr        r3, r31
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
 * Address:	801F05F4
 * Size:	000020
 */
void zen::DrawMenuBase::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x30F60
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F0614
 * Size:	0001A0
 */
void zen::DrawMenuBase::init(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x90(r1)
  stw       r31, 0x8C(r1)
  stw       r30, 0x88(r1)
  mr        r30, r4
  stw       r29, 0x84(r1)
  mr        r29, r3
  stw       r28, 0x80(r1)
  lwz       r12, 0x0(r29)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  li        r31, 0
  stw       r31, 0x18C(r29)
  addi      r3, r29, 0x4
  li        r4, 0
  stw       r31, 0x104(r29)
  li        r5, 0
  stw       r31, 0x108(r29)
  lwz       r12, 0x4(r29)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lfs       f0, -0x3E18(r2)
  li        r4, 0x1
  lis       r28, 0x4330
  stfs      f0, 0xC4(r29)
  addi      r3, r29, 0x114
  stfs      f0, 0xC8(r29)
  stfs      f0, 0xCC(r29)
  lbz       r0, 0x10(r29)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0x10(r29)
  lwz       r0, 0x104(r29)
  lwz       r5, 0x174(r29)
  mulli     r4, r0, 0xC
  lfd       f2, -0x3E00(r2)
  addi      r0, r4, 0x4
  lwzx      r4, r5, r0
  lha       r0, 0x1A(r4)
  lha       r4, 0x18(r4)
  xoris     r0, r0, 0x8000
  xoris     r4, r4, 0x8000
  stw       r0, 0x74(r1)
  stw       r4, 0x7C(r1)
  stw       r28, 0x78(r1)
  stw       r28, 0x70(r1)
  lfd       f1, 0x78(r1)
  lfd       f0, 0x70(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        -0x15734
  lwz       r0, 0x104(r29)
  addi      r3, r29, 0x144
  lwz       r5, 0x174(r29)
  mulli     r4, r0, 0xC
  lfd       f2, -0x3E00(r2)
  addi      r0, r4, 0x8
  lwzx      r4, r5, r0
  lha       r0, 0x1A(r4)
  lha       r4, 0x18(r4)
  xoris     r0, r0, 0x8000
  xoris     r4, r4, 0x8000
  stw       r0, 0x64(r1)
  stw       r4, 0x6C(r1)
  stw       r28, 0x68(r1)
  stw       r28, 0x60(r1)
  lfd       f1, 0x68(r1)
  lfd       f0, 0x60(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        -0x15784
  li        r28, 0
  b         .loc_0x15C

.loc_0x12C:
  lwz       r3, 0x104(r29)
  addi      r5, r29, 0x178
  lwz       r0, 0x174(r29)
  addi      r6, r29, 0x17C
  sub       r3, r3, r28
  cntlzw    r3, r3
  add       r7, r0, r31
  rlwinm    r4,r3,27,5,31
  lwz       r3, 0x0(r7)
  bl        -0x2DFE8
  addi      r31, r31, 0xC
  addi      r28, r28, 0x1

.loc_0x15C:
  lwz       r0, 0x10C(r29)
  cmpw      r28, r0
  blt+      .loc_0x12C
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x94(r1)
  lwz       r31, 0x8C(r1)
  lwz       r30, 0x88(r1)
  lwz       r29, 0x84(r1)
  lwz       r28, 0x80(r1)
  addi      r1, r1, 0x90
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F07B4
 * Size:	000034
 */
void zen::DrawMenuBase::start()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x1
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x8(r1)
  stw       r0, 0x104(r3)
  lwz       r0, 0x104(r3)
  stw       r0, 0x108(r3)
  bl        -0x1C0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F07E8
 * Size:	000008
 */
void zen::DrawMenuBase::modeSleep(Controller *)
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F07F0
 * Size:	000214
 */
void zen::DrawMenuBase::modeOperation(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stmw      r25, 0x6C(r1)
  mr        r28, r4
  mr        r27, r3
  li        r31, 0
  lwz       r5, 0x28(r4)
  lwz       r29, 0x104(r3)
  rlwinm    r0,r5,0,12,12
  neg       r4, r0
  subic     r3, r4, 0x1
  rlwinm    r0,r5,0,10,10
  subfe     r4, r3, r4
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r0, r0, r3
  rlwinm    r3,r4,0,24,31
  rlwinm    r0,r0,0,24,31
  sub.      r5, r0, r3
  beq-      .loc_0xB4
  li        r4, 0

.loc_0x58:
  lwz       r0, 0x104(r27)
  add       r0, r0, r5
  stw       r0, 0x104(r27)
  lwz       r0, 0x104(r27)
  cmpwi     r0, 0
  bge-      .loc_0x7C
  lwz       r3, 0x10C(r27)
  subi      r0, r3, 0x1
  stw       r0, 0x104(r27)

.loc_0x7C:
  lwz       r3, 0x104(r27)
  lwz       r0, 0x10C(r27)
  cmpw      r3, r0
  blt-      .loc_0x90
  stw       r4, 0x104(r27)

.loc_0x90:
  lwz       r0, 0x104(r27)
  lwz       r3, 0x174(r27)
  mulli     r0, r0, 0xC
  add       r6, r3, r0
  lwz       r3, 0x0(r6)
  mr        r30, r6
  lbz       r0, 0x14(r3)
  cmplwi    r0, 0
  beq+      .loc_0x58

.loc_0xB4:
  li        r25, 0
  li        r26, 0
  b         .loc_0xF0

.loc_0xC0:
  lwz       r3, 0x104(r27)
  addi      r5, r27, 0x178
  lwz       r0, 0x174(r27)
  addi      r6, r27, 0x17C
  sub       r3, r3, r25
  cntlzw    r3, r3
  add       r7, r0, r26
  rlwinm    r4,r3,27,5,31
  lwz       r3, 0x0(r7)
  bl        -0x2DFB8
  addi      r26, r26, 0xC
  addi      r25, r25, 0x1

.loc_0xF0:
  lwz       r0, 0x10C(r27)
  cmpw      r25, r0
  blt+      .loc_0xC0
  lwz       r0, 0x104(r27)
  cmpw      r29, r0
  beq-      .loc_0x1A8
  li        r3, 0x112
  bl        -0x14B588
  lwz       r4, 0x4(r30)
  lis       r29, 0x4330
  lfd       f2, -0x3E00(r2)
  addi      r3, r27, 0x114
  lha       r0, 0x1A(r4)
  lha       r4, 0x18(r4)
  xoris     r0, r0, 0x8000
  lfs       f3, -0x3DF8(r2)
  xoris     r4, r4, 0x8000
  stw       r0, 0x5C(r1)
  stw       r4, 0x64(r1)
  stw       r29, 0x60(r1)
  stw       r29, 0x58(r1)
  lfd       f1, 0x60(r1)
  lfd       f0, 0x58(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        -0x15D9C
  lwz       r4, 0x8(r30)
  addi      r3, r27, 0x144
  lfd       f2, -0x3E00(r2)
  lha       r0, 0x1A(r4)
  lha       r4, 0x18(r4)
  xoris     r0, r0, 0x8000
  lfs       f3, -0x3DF8(r2)
  xoris     r4, r4, 0x8000
  stw       r0, 0x4C(r1)
  stw       r4, 0x54(r1)
  stw       r29, 0x50(r1)
  stw       r29, 0x48(r1)
  lfd       f1, 0x50(r1)
  lfd       f0, 0x48(r1)
  fsubs     f1, f1, f2
  fsubs     f2, f0, f2
  bl        -0x15DE0
  lwz       r0, 0x18C(r27)
  ori       r0, r0, 0x1
  stw       r0, 0x18C(r27)

.loc_0x1A8:
  lwz       r3, 0x28(r28)
  lwz       r0, 0x194(r27)
  and.      r0, r3, r0
  beq-      .loc_0x1D0
  li        r3, 0x11D
  bl        -0x14B638
  lwz       r0, 0x2950(r13)
  li        r31, 0x1
  stw       r0, 0x108(r27)
  b         .loc_0x1FC

.loc_0x1D0:
  lwz       r0, 0x190(r27)
  and.      r0, r3, r0
  beq-      .loc_0x1F4
  li        r3, 0x111
  bl        -0x14B65C
  lwz       r0, 0x104(r27)
  li        r31, 0x1
  stw       r0, 0x108(r27)
  b         .loc_0x1FC

.loc_0x1F4:
  lwz       r0, 0x104(r27)
  stw       r0, 0x108(r27)

.loc_0x1FC:
  mr        r3, r31
  lmw       r25, 0x6C(r1)
  lwz       r0, 0x8C(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F0A04
 * Size:	00007C
 */
void zen::DrawMenuBase::setModeFunc(int)
{
/*
.loc_0x0:
  stw       r4, 0x100(r3)
  lis       r4, 0x802E
  addi      r5, r4, 0x7088
  lwz       r0, 0x100(r3)
  cmpwi     r0, 0x1
  beq-      .loc_0x44
  bge-      .loc_0x60
  cmpwi     r0, 0
  bge-      .loc_0x28
  b         .loc_0x60

.loc_0x28:
  lwz       r4, 0x24(r5)
  lwz       r0, 0x28(r5)
  stw       r4, 0x180(r3)
  stw       r0, 0x184(r3)
  lwz       r0, 0x2C(r5)
  stw       r0, 0x188(r3)
  blr       

.loc_0x44:
  lwz       r4, 0x30(r5)
  lwz       r0, 0x34(r5)
  stw       r4, 0x180(r3)
  stw       r0, 0x184(r3)
  lwz       r0, 0x38(r5)
  stw       r0, 0x188(r3)
  blr       

.loc_0x60:
  lwz       r4, 0x3C(r5)
  lwz       r0, 0x40(r5)
  stw       r4, 0x180(r3)
  stw       r0, 0x184(r3)
  lwz       r0, 0x44(r5)
  stw       r0, 0x188(r3)
  blr
*/
}