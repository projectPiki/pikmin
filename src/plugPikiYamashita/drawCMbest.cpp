

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
 * Address:	801EE2E8
 * Size:	000130
 */
void zen::DrawCMBpicObj::modeWait()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stw       r31, 0x74(r1)
  mr        r31, r3
  lwz       r4, 0x2DEC(r13)
  lfs       f1, 0x4(r3)
  lfs       f0, 0x28C(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f0, 0x4(r3)
  lfs       f1, 0x8(r3)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x84
  fsubs     f0, f0, f1
  stfs      f0, 0x4(r31)
  bl        0x29D48
  xoris     r0, r3, 0x8000
  lfd       f4, -0x3E48(r2)
  stw       r0, 0x6C(r1)
  lis       r0, 0x4330
  lfs       f3, -0x3E64(r2)
  stw       r0, 0x68(r1)
  lfs       f2, -0x3E68(r2)
  lfd       f1, 0x68(r1)
  lfs       f0, -0x3E60(r2)
  fsubs     f4, f1, f4
  lfs       f1, 0x1C(r31)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fadds     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x1C(r31)

.loc_0x84:
  lwz       r4, 0x0(r31)
  lwz       r3, 0x2DEC(r13)
  lfs       f2, -0x3E5C(r2)
  lfs       f1, 0xC0(r4)
  lfs       f0, 0x28C(r3)
  fsubs     f1, f2, f1
  lfs       f2, 0x1C(r31)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x1C(r31)
  lfs       f1, 0x1C(r31)
  lfs       f0, -0x3E58(r2)
  fmuls     f0, f1, f0
  stfs      f0, 0x1C(r31)
  lwz       r4, 0x0(r31)
  lfs       f1, 0x1C(r31)
  lfs       f0, 0xC0(r4)
  fadds     f0, f1, f0
  stfs      f0, 0xC0(r4)
  stfs      f0, 0xC4(r4)
  stfs      f0, 0xC8(r4)
  lwz       r4, 0x0(r31)
  lfs       f0, -0x3E54(r2)
  lfs       f1, 0xC0(r4)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xF8
  stfs      f0, 0xC0(r4)
  stfs      f0, 0xC4(r4)
  stfs      f0, 0xC8(r4)

.loc_0xF8:
  lwz       r4, 0x0(r31)
  lfs       f0, -0x3E50(r2)
  lfs       f1, 0xC0(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x118
  stfs      f0, 0xC0(r4)
  stfs      f0, 0xC4(r4)
  stfs      f0, 0xC8(r4)

.loc_0x118:
  lwz       r0, 0x7C(r1)
  li        r3, 0
  lwz       r31, 0x74(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE418
 * Size:	0000F4
 */
void zen::DrawCMBpicObj::modeAppear()
{
/*
.loc_0x0:
  lwz       r4, 0x2DEC(r13)
  lis       r5, 0x802E
  lfs       f1, 0x4(r3)
  addi      r5, r5, 0x6E18
  lfs       f0, 0x28C(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f1, 0x4(r3)
  lfs       f0, 0x8(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xEC
  li        r0, 0x2
  stw       r0, 0x18(r3)
  lwz       r0, 0x18(r3)
  cmpwi     r0, 0x1
  beq-      .loc_0x8C
  bge-      .loc_0x50
  cmpwi     r0, 0
  bge-      .loc_0x5C
  b         .loc_0xEC

.loc_0x50:
  cmpwi     r0, 0x3
  bge-      .loc_0xEC
  b         .loc_0xC4

.loc_0x5C:
  lwz       r4, 0x1C(r5)
  lwz       r0, 0x20(r5)
  stw       r4, 0xC(r3)
  stw       r0, 0x10(r3)
  lwz       r0, 0x24(r5)
  stw       r0, 0x14(r3)
  lwz       r3, 0x0(r3)
  lfs       f0, -0x3E54(r2)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  b         .loc_0xEC

.loc_0x8C:
  lfs       f0, -0x3E54(r2)
  stfs      f0, 0x4(r3)
  stfs      f0, 0x1C(r3)
  lwz       r4, 0x0(r3)
  stfs      f0, 0xC0(r4)
  stfs      f0, 0xC4(r4)
  stfs      f0, 0xC8(r4)
  lwz       r4, 0x28(r5)
  lwz       r0, 0x2C(r5)
  stw       r4, 0xC(r3)
  stw       r0, 0x10(r3)
  lwz       r0, 0x30(r5)
  stw       r0, 0x14(r3)
  b         .loc_0xEC

.loc_0xC4:
  lfs       f0, -0x3E54(r2)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x3E40(r2)
  stfs      f0, 0x8(r3)
  lwz       r4, 0x34(r5)
  lwz       r0, 0x38(r5)
  stw       r4, 0xC(r3)
  stw       r0, 0x10(r3)
  lwz       r0, 0x3C(r5)
  stw       r0, 0x14(r3)

.loc_0xEC:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE50C
 * Size:	000008
 */
void zen::DrawCMBpicObj::modeSleep()
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE514
 * Size:	000224
 */
void zen::DrawCMbest::init(P2DScreen *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x70(r1)
  stmw      r27, 0x5C(r1)
  addi      r29, r4, 0
  lis       r4, 0x6265
  addi      r28, r3, 0
  addi      r3, r29, 0
  addi      r4, r4, 0x7374
  lwz       r12, 0x0(r29)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x4(r28)
  lwz       r0, 0x4(r28)
  cmplwi    r0, 0
  bne-      .loc_0x6C
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lis       r4, 0x726F
  addi      r4, r4, 0x6F74
  lwz       r12, 0x34(r12)
  li        r5, 0x1
  mtlr      r12
  blrl      
  stw       r3, 0x4(r28)

.loc_0x6C:
  lwz       r6, 0x4(r28)
  li        r0, 0
  lha       r4, 0x18(r6)
  lha       r3, 0x1C(r6)
  lha       r5, 0x1A(r6)
  sub       r3, r3, r4
  lha       r4, 0x1E(r6)
  srawi     r3, r3, 0x1
  sub       r5, r4, r5
  extsh     r4, r3
  srawi     r3, r5, 0x1
  sth       r4, 0xB8(r6)
  extsh     r3, r3
  sth       r3, 0xBA(r6)
  stw       r0, 0xC(r28)

.loc_0xA8:
  lwz       r5, 0xC(r28)
  addi      r3, r1, 0x50
  crclr     6, 0x6
  addi      r4, r13, 0x28C8
  bl        0x27FCC
  lwz       r12, 0x0(r29)
  mr        r3, r29
  lbz       r0, 0x51(r1)
  li        r5, 0
  lwz       r12, 0x34(r12)
  lbz       r4, 0x50(r1)
  rlwinm    r0,r0,16,0,15
  lbz       r6, 0x52(r1)
  mtlr      r12
  rlwimi    r0,r4,24,0,7
  lbz       r7, 0x53(r1)
  rlwimi    r0,r6,8,16,23
  or        r4, r7, r0
  blrl      
  cmplwi    r3, 0
  beq-      .loc_0x108
  lwz       r4, 0xC(r28)
  addi      r0, r4, 0x1
  stw       r0, 0xC(r28)

.loc_0x108:
  cmplwi    r3, 0
  bne+      .loc_0xA8
  lwz       r27, 0xC(r28)
  rlwinm    r3,r27,5,0,26
  addi      r3, r3, 0x8
  bl        -0x1A762C
  lis       r4, 0x801F
  subi      r4, r4, 0x18C8
  addi      r7, r27, 0
  li        r5, 0
  li        r6, 0x20
  bl        0x265E0
  lis       r4, 0x802E
  stw       r3, 0x8(r28)
  addi      r27, r4, 0x6E58
  li        r30, 0
  li        r31, 0
  b         .loc_0x1F8

.loc_0x150:
  addi      r5, r30, 0
  crclr     6, 0x6
  addi      r3, r1, 0x50
  addi      r4, r13, 0x28C8
  bl        0x27F24
  lwz       r12, 0x0(r29)
  mr        r3, r29
  lbz       r0, 0x51(r1)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  lbz       r4, 0x50(r1)
  rlwinm    r0,r0,16,0,15
  lbz       r6, 0x52(r1)
  mtlr      r12
  rlwimi    r0,r4,24,0,7
  lbz       r7, 0x53(r1)
  rlwimi    r0,r6,8,16,23
  or        r4, r7, r0
  blrl      
  lha       r6, 0x1A(r3)
  addi      r30, r30, 0x1
  lha       r5, 0x1E(r3)
  lha       r4, 0x18(r3)
  lha       r0, 0x1C(r3)
  sub       r5, r5, r6
  srawi     r5, r5, 0x1
  sub       r0, r0, r4
  srawi     r0, r0, 0x1
  extsh     r0, r0
  sth       r0, 0xB8(r3)
  extsh     r0, r5
  sth       r0, 0xBA(r3)
  lwz       r0, 0x8(r28)
  add       r4, r0, r31
  stw       r3, 0x0(r4)
  addi      r31, r31, 0x20
  lwz       r3, 0x0(r27)
  lwz       r0, 0x4(r27)
  stw       r3, 0xC(r4)
  stw       r0, 0x10(r4)
  lwz       r0, 0x8(r27)
  stw       r0, 0x14(r4)

.loc_0x1F8:
  lwz       r0, 0xC(r28)
  cmpw      r30, r0
  blt+      .loc_0x150
  addi      r3, r28, 0
  li        r4, 0
  bl        0x1AC
  lmw       r27, 0x5C(r1)
  lwz       r0, 0x74(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE738
 * Size:	000040
 */
void zen::DrawCMBpicObj::DrawCMBpicObj()
{
/*
.loc_0x0:
  li        r6, 0
  stw       r6, 0x0(r3)
  lis       r4, 0x8022
  addi      r5, r4, 0x2758
  lfs       f0, -0x3E54(r2)
  stfs      f0, 0x8(r3)
  stfs      f0, 0x4(r3)
  lwz       r4, 0x0(r5)
  lwz       r0, 0x4(r5)
  stw       r4, 0xC(r3)
  stw       r0, 0x10(r3)
  lwz       r0, 0x8(r5)
  stw       r0, 0x14(r3)
  stw       r6, 0x18(r3)
  stfs      f0, 0x1C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE778
 * Size:	000024
 */
void zen::DrawCMbest::sleep()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x144
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE79C
 * Size:	00007C
 */
void zen::DrawCMbest::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  li        r31, 0
  stw       r30, 0x18(r1)
  li        r30, 0
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  b         .loc_0x44

.loc_0x28:
  lwz       r0, 0x8(r29)
  add       r3, r0, r31
  addi      r12, r3, 0xC
  bl        0x26560
  nop       
  addi      r31, r31, 0x20
  addi      r30, r30, 0x1

.loc_0x44:
  lwz       r0, 0xC(r29)
  cmpw      r30, r0
  blt+      .loc_0x28
  addi      r3, r29, 0
  addi      r12, r29, 0x10
  bl        0x2653C
  nop       
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE818
 * Size:	000024
 */
void zen::DrawCMbest::appear()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0xA4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE83C
 * Size:	000024
 */
void zen::DrawCMbest::wait()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x80
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE860
 * Size:	000008
 */
void zen::DrawCMbest::modeSleep()
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE868
 * Size:	000008
 */
void zen::DrawCMbest::modeWait()
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE870
 * Size:	00005C
 */
void zen::DrawCMbest::modeAppear()
{
/*
.loc_0x0:
  lwz       r4, 0xC(r3)
  li        r5, 0
  cmpwi     r4, 0
  ble-      .loc_0x4C
  cmpwi     r4, 0x8
  subi      r3, r4, 0x8
  ble-      .loc_0x38
  addi      r0, r3, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r3, 0
  mtctr     r0
  ble-      .loc_0x38

.loc_0x30:
  addi      r5, r5, 0x8
  bdnz+     .loc_0x30

.loc_0x38:
  sub       r0, r4, r5
  cmpw      r5, r4
  mtctr     r0
  bge-      .loc_0x4C

.loc_0x48:
  bdnz-     .loc_0x48

.loc_0x4C:
  li        r3, 0
  blr       
  b         .loc_0x38
  blr
*/
}

/*
 * --INFO--
 * Address:	801EE8CC
 * Size:	0001D4
 */
void zen::DrawCMbest::setMode(zen::DrawCMbest::modeFlag)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stfd      f31, 0x48(r1)
  stfd      f30, 0x40(r1)
  stmw      r26, 0x28(r1)
  mr        r31, r3
  stw       r4, 0x0(r3)
  lis       r3, 0x802E
  addi      r5, r3, 0x6E18
  lwz       r0, 0x0(r31)
  cmpwi     r0, 0x1
  beq-      .loc_0x130
  bge-      .loc_0x44
  cmpwi     r0, 0
  bge-      .loc_0x50
  b         .loc_0x1B8

.loc_0x44:
  cmpwi     r0, 0x3
  bge-      .loc_0x1B8
  b         .loc_0x9C

.loc_0x50:
  lwz       r3, 0x4C(r5)
  li        r26, 0
  lwz       r0, 0x50(r5)
  li        r29, 0
  stw       r3, 0x10(r31)
  stw       r0, 0x14(r31)
  lwz       r0, 0x54(r5)
  stw       r0, 0x18(r31)
  b         .loc_0x8C

.loc_0x74:
  lwz       r0, 0x8(r31)
  li        r4, 0
  add       r3, r0, r29
  bl        .loc_0x1D4
  addi      r29, r29, 0x20
  addi      r26, r26, 0x1

.loc_0x8C:
  lwz       r0, 0xC(r31)
  cmpw      r26, r0
  blt+      .loc_0x74
  b         .loc_0x1B8

.loc_0x9C:
  lwz       r3, 0x58(r5)
  li        r26, 0
  lwz       r0, 0x5C(r5)
  li        r4, 0x1
  addi      r28, r26, 0
  stw       r3, 0x10(r31)
  lis       r30, 0x4330
  stw       r0, 0x14(r31)
  lwz       r0, 0x60(r5)
  stw       r0, 0x18(r31)
  lwz       r3, 0x4(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lfs       f31, -0x3E3C(r2)
  lfd       f30, -0x3E48(r2)
  b         .loc_0x120

.loc_0xE0:
  lwz       r0, 0x8(r31)
  li        r4, 0x2
  add       r29, r0, r28
  addi      r3, r29, 0
  bl        .loc_0x1D4
  sub       r3, r27, r26
  subi      r0, r3, 0x1
  xoris     r0, r0, 0x8000
  stw       r0, 0x24(r1)
  addi      r28, r28, 0x20
  addi      r26, r26, 0x1
  stw       r30, 0x20(r1)
  lfd       f0, 0x20(r1)
  fsubs     f0, f0, f30
  fmuls     f0, f31, f0
  stfs      f0, 0x4(r29)

.loc_0x120:
  lwz       r27, 0xC(r31)
  cmpw      r26, r27
  blt+      .loc_0xE0
  b         .loc_0x1B8

.loc_0x130:
  lwz       r3, 0x64(r5)
  li        r27, 0
  lwz       r0, 0x68(r5)
  li        r4, 0x1
  addi      r28, r27, 0
  stw       r3, 0x10(r31)
  lis       r30, 0x4330
  stw       r0, 0x14(r31)
  lwz       r0, 0x6C(r5)
  stw       r0, 0x18(r31)
  lwz       r3, 0x4(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lfs       f30, -0x3E3C(r2)
  lfd       f31, -0x3E48(r2)
  b         .loc_0x1AC

.loc_0x174:
  lwz       r0, 0x8(r31)
  li        r4, 0x1
  add       r29, r0, r28
  addi      r3, r29, 0
  bl        .loc_0x1D4
  xoris     r0, r27, 0x8000
  stw       r0, 0x24(r1)
  addi      r28, r28, 0x20
  addi      r27, r27, 0x1
  stw       r30, 0x20(r1)
  lfd       f0, 0x20(r1)
  fsubs     f0, f0, f31
  fmuls     f0, f30, f0
  stfs      f0, 0x8(r29)

.loc_0x1AC:
  lwz       r0, 0xC(r31)
  cmpw      r27, r0
  blt+      .loc_0x174

.loc_0x1B8:
  lmw       r26, 0x28(r1)
  lwz       r0, 0x54(r1)
  lfd       f31, 0x48(r1)
  lfd       f30, 0x40(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr       

.loc_0x1D4:
*/
}

/*
 * --INFO--
 * Address:	801EEAA0
 * Size:	0000C8
 */
void zen::DrawCMBpicObj::setMode(zen::DrawCMBpicObj::modeFlag)
{
/*
.loc_0x0:
  stw       r4, 0x18(r3)
  lis       r4, 0x802E
  addi      r5, r4, 0x6E18
  lwz       r0, 0x18(r3)
  cmpwi     r0, 0x1
  beq-      .loc_0x64
  bge-      .loc_0x28
  cmpwi     r0, 0
  bge-      .loc_0x34
  blr       

.loc_0x28:
  cmpwi     r0, 0x3
  bgelr-    
  b         .loc_0x9C

.loc_0x34:
  lwz       r4, 0x1C(r5)
  lwz       r0, 0x20(r5)
  stw       r4, 0xC(r3)
  stw       r0, 0x10(r3)
  lwz       r0, 0x24(r5)
  stw       r0, 0x14(r3)
  lwz       r3, 0x0(r3)
  lfs       f0, -0x3E54(r2)
  stfs      f0, 0xC0(r3)
  stfs      f0, 0xC4(r3)
  stfs      f0, 0xC8(r3)
  blr       

.loc_0x64:
  lfs       f0, -0x3E54(r2)
  stfs      f0, 0x4(r3)
  stfs      f0, 0x1C(r3)
  lwz       r4, 0x0(r3)
  stfs      f0, 0xC0(r4)
  stfs      f0, 0xC4(r4)
  stfs      f0, 0xC8(r4)
  lwz       r4, 0x28(r5)
  lwz       r0, 0x2C(r5)
  stw       r4, 0xC(r3)
  stw       r0, 0x10(r3)
  lwz       r0, 0x30(r5)
  stw       r0, 0x14(r3)
  blr       

.loc_0x9C:
  lfs       f0, -0x3E54(r2)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x3E40(r2)
  stfs      f0, 0x8(r3)
  lwz       r4, 0x34(r5)
  lwz       r0, 0x38(r5)
  stw       r4, 0xC(r3)
  stw       r0, 0x10(r3)
  lwz       r0, 0x3C(r5)
  stw       r0, 0x14(r3)
  blr
*/
}