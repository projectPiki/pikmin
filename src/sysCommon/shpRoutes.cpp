#include "types.h"

#include "Vector3f.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
/*
void _Error(char *, ...)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
/*
void _Print(char *, ...)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
/*
RoutePoint::RoutePoint()
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	0001D4
 */
/*
void RoutePoint::refresh(Graphics &)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	80036474
 * Size:	000184
 */
/*
void RoutePoint::loadini(CmdStream *)
{

.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  b         .loc_0x130

.loc_0x20:
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xAC14
  addi      r3, r31, 0
  subi      r4, r13, 0x7ABC
  bl        0xAF2C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x60
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xABF4
  crclr     6, 0x6
  addi      r5, r30, 0x38
  subi      r4, r13, 0x7AC0
  bl        0x1E1BC8
  b         .loc_0x130

.loc_0x60:
  addi      r3, r31, 0
  subi      r4, r13, 0x7AB4
  bl        0xAEF8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xCC
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xABC0
  crclr     6, 0x6
  addi      r5, r30, 0x28
  subi      r4, r13, 0x7AB0
  bl        0x1E1B94
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xABA4
  crclr     6, 0x6
  addi      r5, r30, 0x2C
  subi      r4, r13, 0x7AB0
  bl        0x1E1B78
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xAB88
  crclr     6, 0x6
  addi      r5, r30, 0x30
  subi      r4, r13, 0x7AB0
  bl        0x1E1B5C
  b         .loc_0x130

.loc_0xCC:
  addi      r3, r31, 0
  subi      r4, r13, 0x7AAC
  bl        0xAE8C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x100
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xAB54
  crclr     6, 0x6
  addi      r5, r30, 0x34
  subi      r4, r13, 0x7AC0
  bl        0x1E1B28
  b         .loc_0x130

.loc_0x100:
  addi      r3, r31, 0
  subi      r4, r13, 0x7AA4
  bl        0xAE58
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x130
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xAB20
  crclr     6, 0x6
  addi      r5, r30, 0x24
  subi      r4, r13, 0x7AB0
  bl        0x1E1AF4

.loc_0x130:
  mr        r3, r31
  bl        0xA7B0
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x150
  mr        r3, r31
  bl        0xAED0
  rlwinm.   r0,r3,0,24,31
  beq+      .loc_0x20

.loc_0x150:
  mr        r3, r31
  bl        0xA790
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x16C
  addi      r3, r31, 0
  li        r4, 0x1
  bl        0xAAD4

.loc_0x16C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr

}
*/
/*
 * --INFO--
 * Address:	800365F8
 * Size:	000184
 */
/*
RouteGroup::RouteGroup()
{

.loc_0x0:
  mflr      r0
  lis       r4, 0x8022
  stw       r0, 0x4(r1)
  addi      r9, r4, 0x738C
  lis       r5, 0x8023
  stwu      r1, -0x28(r1)
  subi      r7, r5, 0x74A4
  lis       r4, 0x8023
  stw       r31, 0x24(r1)
  subi      r6, r4, 0x74BC
  subi      r31, r13, 0x7AC4
  stw       r30, 0x20(r1)
  li        r30, 0
  subi      r5, r13, 0x7AC8
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lis       r3, 0x8022
  stw       r9, 0x0(r29)
  addi      r8, r3, 0x737C
  lis       r3, 0x8023
  stw       r8, 0x0(r29)
  subi      r0, r3, 0x743C
  addi      r3, r29, 0xA4
  stw       r30, 0x10(r29)
  subi      r4, r13, 0x7AC8
  stw       r30, 0xC(r29)
  stw       r30, 0x8(r29)
  stw       r31, 0x4(r29)
  stw       r7, 0x0(r29)
  stw       r6, 0x0(r29)
  stw       r9, 0x68(r29)
  stw       r8, 0x68(r29)
  stw       r30, 0x78(r29)
  stw       r30, 0x74(r29)
  stw       r30, 0x70(r29)
  stw       r5, 0x6C(r29)
  stw       r0, 0x68(r29)
  lfs       f0, -0x7C88(r2)
  stfs      f0, 0x98(r29)
  stfs      f0, 0x94(r29)
  stfs      f0, 0x90(r29)
  stw       r9, 0xA4(r29)
  stw       r8, 0xA4(r29)
  stw       r30, 0xB4(r29)
  stw       r30, 0xB0(r29)
  stw       r30, 0xAC(r29)
  bl        -0x117DC
  lis       r3, 0x8023
  crclr     6, 0x6
  subi      r0, r3, 0x746C
  stw       r0, 0xA4(r29)
  lis       r5, 0x6E6F
  lis       r3, 0x8023
  stw       r30, 0xB8(r29)
  subi      r4, r3, 0x75E4
  li        r6, 0x1
  stw       r30, 0xB4(r29)
  addi      r0, r5, 0x6E65
  addi      r3, r29, 0x18
  stw       r30, 0xB0(r29)
  stw       r30, 0xAC(r29)
  stw       r31, 0xA8(r29)
  lfs       f0, -0x7C84(r2)
  stfs      f0, 0x88(r29)
  stw       r30, 0xA0(r29)
  stw       r6, 0x9C(r29)
  lfs       f0, -0x7C80(r2)
  stfs      f0, 0x8C(r29)
  stw       r0, 0x58(r29)
  lbz       r0, 0x58(r29)
  stb       r0, 0x5C(r29)
  lbz       r0, 0x59(r29)
  stb       r0, 0x5D(r29)
  lbz       r0, 0x5A(r29)
  stb       r0, 0x5E(r29)
  lbz       r0, 0x5B(r29)
  stb       r0, 0x5F(r29)
  stb       r30, 0x60(r29)
  bl        0x1DFE68
  stw       r30, 0x78(r29)
  li        r4, 0xFF
  li        r0, 0xC0
  stw       r30, 0x74(r29)
  mr        r3, r29
  stw       r30, 0x70(r29)
  stw       r31, 0x6C(r29)
  stb       r4, 0x14(r29)
  stb       r4, 0x15(r29)
  stb       r4, 0x16(r29)
  stb       r0, 0x17(r29)
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr

}
*/
/*
 * --INFO--
 * Address:	8003677C
 * Size:	0009A0
 */
/*
void RouteGroup::refresh(Graphics &, EditNode *)
{

.loc_0x0:
  mflr      r0
  li        r5, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x5C0(r1)
  stfd      f31, 0x5B8(r1)
  stfd      f30, 0x5B0(r1)
  stfd      f29, 0x5A8(r1)
  stfd      f28, 0x5A0(r1)
  stfd      f27, 0x598(r1)
  stfd      f26, 0x590(r1)
  stfd      f25, 0x588(r1)
  stfd      f24, 0x580(r1)
  stfd      f23, 0x578(r1)
  stfd      f22, 0x570(r1)
  stfd      f21, 0x568(r1)
  stfd      f20, 0x560(r1)
  stfd      f19, 0x558(r1)
  stfd      f18, 0x550(r1)
  stfd      f17, 0x548(r1)
  stfd      f16, 0x540(r1)
  stfd      f15, 0x538(r1)
  stfd      f14, 0x530(r1)
  stmw      r14, 0x4E8(r1)
  addi      r31, r4, 0
  addi      r28, r3, 0
  addi      r3, r31, 0
  li        r4, 0
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl
  lwz       r12, 0x3B4(r31)
  mr        r0, r3
  lbz       r26, 0x17(r28)
  mr        r3, r31
  lwz       r12, 0x60(r12)
  stb       r0, 0x4A0(r1)
  li        r4, 0
  mtlr      r12
  blrl
  addi      r0, r1, 0x3E8
  lwz       r29, 0x78(r28)
  stw       r0, 0x4AC(r1)
  addi      r0, r1, 0x3D0
  lfs       f16, -0x7C84(r2)
  addi      r14, r1, 0x3CC
  stw       r0, 0x4A8(r1)
  addi      r0, r1, 0x3DC
  lfd       f15, -0x7C68(r2)
  lfs       f31, -0x7C88(r2)
  addi      r15, r1, 0xF0
  stw       r0, 0x4A4(r1)
  addi      r16, r1, 0xEC
  lfs       f14, -0x7C70(r2)
  addi      r17, r1, 0xE8
  addi      r18, r1, 0xFC
  addi      r19, r1, 0xF8
  addi      r20, r1, 0xF4
  addi      r21, r1, 0x36C
  addi      r22, r1, 0x33C
  addi      r23, r1, 0x360
  addi      r24, r1, 0x324
  addi      r25, r1, 0x330
  lis       r27, 0x4330
  b         .loc_0x64C

.loc_0x104:
  lwz       r30, 0x4C(r29)
  b         .loc_0x640

.loc_0x10C:
  lwz       r6, 0x14(r30)
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0
  lfs       f1, 0x2C(r29)
  lfs       f0, 0x2C(r6)
  li        r5, 0
  lwz       r12, 0xCC(r12)
  fadds     f19, f16, f1
  fadds     f20, f16, f0
  mtlr      r12
  lfs       f21, 0x28(r29)
  lfs       f22, 0x30(r29)
  lfs       f23, 0x28(r6)
  lfs       f24, 0x30(r6)
  lfs       f18, -0x7A9C(r13)
  lfs       f29, -0x7A98(r13)
  lfs       f28, -0x7A94(r13)
  blrl
  li        r0, 0xFF
  lwz       r4, 0x4AC(r1)
  stb       r0, 0x3E8(r1)
  mr        r3, r31
  li        r5, 0x1
  stb       r0, 0x3E9(r1)
  stb       r0, 0x3EA(r1)
  stb       r26, 0x3EB(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl
  fadds     f1, f23, f18
  lwz       r4, 0x4A4(r1)
  fadds     f0, f21, f18
  lwz       r5, 0x4A8(r1)
  fadds     f4, f20, f29
  stfs      f1, 0x2D4(r1)
  fadds     f1, f19, f29
  fadds     f3, f24, f28
  mr        r3, r31
  stfs      f0, 0x2E0(r1)
  lfs       f0, 0x2D4(r1)
  lfs       f2, 0x2E0(r1)
  stfs      f0, 0x3D0(r1)
  fadds     f0, f22, f28
  stfs      f2, 0x3DC(r1)
  stfs      f4, 0x3D4(r1)
  stfs      f1, 0x3E0(r1)
  stfs      f3, 0x3D8(r1)
  stfs      f0, 0x3E4(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x98(r12)
  mtlr      r12
  blrl
  lwz       r3, 0x34(r29)
  li        r0, 0x1
  cmpwi     r3, 0
  beq-      .loc_0x204
  lwz       r3, 0x14(r30)
  cmplwi    r3, 0
  beq-      .loc_0x204
  li        r0, 0

.loc_0x204:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x214
  lfs       f1, -0x7C78(r2)
  b         .loc_0x218

.loc_0x214:
  lfs       f1, -0x7C74(r2)

.loc_0x218:
  lbz       r5, 0x14(r28)
  mr        r3, r31
  lbz       r0, 0x15(r28)
  mr        r4, r14
  stw       r5, 0x4C4(r1)
  lbz       r6, 0x16(r28)
  li        r5, 0x1
  stw       r0, 0x4D4(r1)
  stw       r27, 0x4C0(r1)
  stw       r6, 0x4E4(r1)
  lfd       f0, 0x4C0(r1)
  stw       r27, 0x4D0(r1)
  fsubs     f2, f0, f15
  stw       r27, 0x4E0(r1)
  lfd       f3, 0x4D0(r1)
  lfd       f0, 0x4E0(r1)
  fmuls     f2, f2, f1
  fsubs     f3, f3, f15
  fsubs     f0, f0, f15
  fctiwz    f2, f2
  fmuls     f3, f3, f1
  fmuls     f0, f0, f1
  stfd      f2, 0x4B8(r1)
  fctiwz    f1, f3
  fctiwz    f0, f0
  lwz       r0, 0x4BC(r1)
  stfd      f1, 0x4C8(r1)
  stfd      f0, 0x4D8(r1)
  lwz       r6, 0x4CC(r1)
  stb       r0, 0x3CC(r1)
  lwz       r7, 0x4DC(r1)
  stb       r6, 0x3CD(r1)
  stb       r7, 0x3CE(r1)
  stb       r26, 0x3CF(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl
  fadds     f2, f22, f24
  mr        r4, r17
  fadds     f1, f19, f20
  mr        r5, r16
  fadds     f0, f21, f23
  stfs      f2, 0xF0(r1)
  addi      r6, r15, 0
  addi      r3, r1, 0x3A8
  stfs      f1, 0xEC(r1)
  stfs      f0, 0xE8(r1)
  bl        .loc_0x9A0
  lfs       f0, 0x3B0(r1)
  mr        r4, r20
  lfs       f1, -0x7A90(r13)
  mr        r5, r19
  lfs       f3, 0x3AC(r1)
  lfs       f2, 0x3A8(r1)
  fmuls     f0, f0, f1
  fmuls     f3, f3, f1
  mr        r6, r18
  fmuls     f1, f2, f1
  stfs      f0, 0xFC(r1)
  addi      r3, r1, 0x3B4
  stfs      f3, 0xF8(r1)
  stfs      f1, 0xF4(r1)
  bl        .loc_0x9A0
  fsubs     f30, f23, f21
  lfs       f0, 0x3BC(r1)
  fsubs     f17, f24, f22
  lfs       f2, 0x3B8(r1)
  fsubs     f26, f20, f19
  fadds     f0, f0, f28
  lfs       f4, 0x3B4(r1)
  fmr       f25, f30
  fmr       f27, f17
  stfs      f0, 0x4B4(r1)
  fmuls     f3, f26, f26
  fmuls     f0, f25, f25
  fadds     f2, f2, f29
  fmuls     f1, f27, f27
  fadds     f0, f0, f3
  fadds     f18, f4, f18
  stfs      f2, 0x4B0(r1)
  fadds     f1, f1, f0
  bl        -0x28E9C
  fcmpu     cr0, f31, f1
  beq-      .loc_0x378
  fdivs     f25, f25, f1
  fdivs     f26, f26, f1
  fdivs     f27, f27, f1

.loc_0x378:
  fneg      f28, f17
  lfs       f29, -0x7A8C(r13)
  fmuls     f2, f30, f30
  fmuls     f1, f29, f29
  fmuls     f0, f28, f28
  fmuls     f25, f25, f16
  fmuls     f26, f26, f16
  fadds     f0, f0, f1
  fmuls     f27, f27, f16
  fadds     f1, f2, f0
  bl        -0x28EDC
  fcmpu     cr0, f31, f1
  beq-      .loc_0x3B8
  fdivs     f28, f28, f1
  fdivs     f29, f29, f1
  fdivs     f30, f30, f1

.loc_0x3B8:
  lwz       r5, 0x14(r30)
  mr        r3, r31
  lfs       f0, 0x24(r29)
  addi      r4, r1, 0x40C
  lfs       f1, 0x24(r5)
  fmuls     f6, f28, f0
  addi      r6, r1, 0x3EC
  stfs      f31, 0x414(r1)
  fmuls     f5, f29, f0
  fmuls     f4, f30, f0
  stfs      f31, 0x410(r1)
  fmuls     f3, f28, f1
  fmuls     f2, f29, f1
  li        r5, 0
  stfs      f31, 0x40C(r1)
  fmuls     f0, f30, f1
  stfs      f31, 0x420(r1)
  fadds     f9, f21, f6
  li        r7, 0x4
  stfs      f31, 0x41C(r1)
  fadds     f10, f19, f5
  stfs      f31, 0x418(r1)
  fadds     f11, f22, f4
  stfs      f31, 0x3EC(r1)
  fsubs     f6, f21, f6
  fsubs     f8, f19, f5
  stfs      f31, 0x42C(r1)
  fsubs     f7, f23, f3
  stfs      f31, 0x3F0(r1)
  fsubs     f1, f22, f4
  fsubs     f5, f20, f2
  stfs      f31, 0x428(r1)
  fadds     f3, f23, f3
  stfs      f31, 0x3F4(r1)
  fsubs     f4, f24, f0
  fadds     f2, f20, f2
  stfs      f31, 0x424(r1)
  fadds     f0, f24, f0
  stfs      f31, 0x3F8(r1)
  stfs      f31, 0x438(r1)
  stfs      f31, 0x3FC(r1)
  stfs      f31, 0x434(r1)
  stfs      f31, 0x400(r1)
  stfs      f31, 0x430(r1)
  stfs      f31, 0x404(r1)
  stfs      f31, 0x408(r1)
  stfs      f9, 0x40C(r1)
  stfs      f10, 0x410(r1)
  stfs      f11, 0x414(r1)
  stfs      f6, 0x2B0(r1)
  lfs       f6, 0x2B0(r1)
  stfs      f7, 0x2A4(r1)
  stfs      f6, 0x388(r1)
  lfs       f6, 0x2A4(r1)
  stfs      f8, 0x38C(r1)
  stfs      f1, 0x390(r1)
  stfs      f6, 0x37C(r1)
  lwz       r0, 0x388(r1)
  stfs      f5, 0x380(r1)
  lwz       r8, 0x38C(r1)
  stfs      f4, 0x384(r1)
  lwz       r9, 0x390(r1)
  stw       r0, 0x418(r1)
  lwz       r10, 0x37C(r1)
  stfs      f3, 0x298(r1)
  lwz       r11, 0x380(r1)
  stw       r8, 0x41C(r1)
  lfs       f1, 0x298(r1)
  stw       r9, 0x420(r1)
  lwz       r0, 0x384(r1)
  stfs      f1, 0x370(r1)
  stw       r10, 0x424(r1)
  stfs      f2, 0x374(r1)
  stfs      f0, 0x378(r1)
  stw       r11, 0x428(r1)
  lwz       r8, 0x370(r1)
  stw       r0, 0x42C(r1)
  lwz       r9, 0x374(r1)
  stw       r8, 0x430(r1)
  lwz       r0, 0x378(r1)
  stw       r9, 0x434(r1)
  stw       r0, 0x438(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl
  li        r0, 0xFF
  fmuls     f28, f28, f14
  stb       r0, 0x36C(r1)
  mr        r3, r31
  fmuls     f29, f29, f14
  mr        r4, r21
  stb       r0, 0x36D(r1)
  fmuls     f30, f30, f14
  li        r5, 0x1
  stb       r0, 0x36E(r1)
  stb       r0, 0x36F(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl
  fsubs     f19, f18, f25
  lfs       f0, 0x4B0(r1)
  mr        r3, r31
  fsubs     f20, f0, f26
  lfs       f0, 0x4B4(r1)
  fsubs     f24, f19, f25
  stfs      f19, 0x268(r1)
  fsubs     f21, f0, f27
  lfs       f0, 0x268(r1)
  fsubs     f23, f20, f26
  stfs      f0, 0x33C(r1)
  fsubs     f22, f21, f27
  mr        r4, r23
  stfs      f24, 0x280(r1)
  mr        r5, r22
  lfs       f0, 0x280(r1)
  stfs      f20, 0x340(r1)
  stfs      f21, 0x344(r1)
  stfs      f0, 0x354(r1)
  stfs      f23, 0x358(r1)
  stfs      f22, 0x35C(r1)
  lfs       f0, 0x354(r1)
  fsubs     f0, f0, f28
  stfs      f0, 0x274(r1)
  lfs       f0, 0x274(r1)
  stfs      f0, 0x360(r1)
  lfs       f0, 0x358(r1)
  fsubs     f0, f0, f29
  stfs      f0, 0x364(r1)
  lfs       f0, 0x35C(r1)
  fsubs     f0, f0, f30
  stfs      f0, 0x368(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x98(r12)
  mtlr      r12
  blrl
  stfs      f24, 0x318(r1)
  addi      r3, r31, 0
  addi      r4, r25, 0
  stfs      f23, 0x31C(r1)
  mr        r5, r24
  stfs      f22, 0x320(r1)
  lfs       f0, 0x318(r1)
  fadds     f0, f0, f28
  stfs      f0, 0x238(r1)
  lfs       f0, 0x238(r1)
  stfs      f0, 0x324(r1)
  lfs       f0, 0x31C(r1)
  fadds     f0, f0, f29
  stfs      f0, 0x328(r1)
  lfs       f0, 0x320(r1)
  stfs      f19, 0x330(r1)
  fadds     f0, f0, f30
  stfs      f20, 0x334(r1)
  stfs      f0, 0x32C(r1)
  stfs      f21, 0x338(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x98(r12)
  mtlr      r12
  blrl
  lwz       r30, 0xC(r30)

.loc_0x640:
  cmplwi    r30, 0
  bne+      .loc_0x10C
  lwz       r29, 0xC(r29)

.loc_0x64C:
  cmplwi    r29, 0
  bne+      .loc_0x104
  lbz       r7, 0x16(r28)
  addi      r4, r1, 0x308
  lbz       r6, 0x15(r28)
  mr        r3, r31
  lbz       r0, 0x14(r28)
  li        r5, 0x1
  stb       r0, 0x308(r1)
  stb       r6, 0x309(r1)
  stb       r7, 0x30A(r1)
  stb       r26, 0x30B(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl
  lis       r3, 0x803A
  lwz       r29, 0x78(r28)
  lfs       f14, -0x7C7C(r2)
  addi      r15, r1, 0x224
  lfs       f15, -0x7C84(r2)
  addi      r18, r1, 0x304
  addi      r17, r1, 0x2F8
  addi      r16, r1, 0x2F4
  subi      r19, r3, 0x77C0
  addi      r14, r1, 0x230
  b         .loc_0x920

.loc_0x6B8:
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0xCC(r12)
  mtlr      r12
  blrl
  li        r27, 0xFF
  stb       r27, 0x304(r1)
  li        r5, 0
  li        r0, 0x40
  stb       r27, 0x305(r1)
  addi      r3, r31, 0
  addi      r4, r18, 0
  stb       r5, 0x306(r1)
  li        r5, 0x1
  stb       r0, 0x307(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl
  lfs       f1, 0x2C(r29)
  mr        r3, r31
  lfs       f0, 0x28(r29)
  mr        r5, r17
  fadds     f1, f15, f1
  stfs      f0, 0x2F8(r1)
  addi      r4, r29, 0x28
  stfs      f1, 0x2FC(r1)
  lfs       f0, 0x30(r29)
  stfs      f0, 0x300(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x98(r12)
  mtlr      r12
  blrl
  stb       r27, 0x2F4(r1)
  addi      r3, r31, 0
  addi      r4, r16, 0
  stb       r27, 0x2F5(r1)
  li        r5, 0x1
  stb       r27, 0x2F6(r1)
  stb       r26, 0x2F7(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl
  mr        r3, r31
  lwz       r4, 0xBC(r28)
  lwz       r12, 0x3B4(r31)
  li        r5, 0
  lwz       r12, 0xCC(r12)
  mtlr      r12
  blrl
  mr        r3, r31
  lwz       r4, 0x2E4(r31)
  lwz       r12, 0x3B4(r31)
  li        r5, 0
  addi      r4, r4, 0x1E0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0x1
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x808
  lfs       f1, 0x2C(r29)
  mr        r3, r31
  lfs       f0, 0x28(r29)
  mr        r5, r15
  fadds     f1, f14, f1
  stfs      f0, 0x224(r1)
  stfs      f1, 0x228(r1)
  lfs       f0, 0x30(r29)
  stfs      f0, 0x22C(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r4, 0x2E4(r31)
  lwz       r12, 0x8C(r12)
  lfs       f1, 0x20(r29)
  mtlr      r12
  blrl

.loc_0x808:
  lfs       f1, 0x2C(r29)
  mr        r4, r31
  lfs       f0, 0x28(r29)
  addi      r5, r1, 0x10C
  fadds     f1, f14, f1
  stfs      f0, 0x10C(r1)
  stfs      f1, 0x110(r1)
  lfs       f0, 0x30(r29)
  stfs      f0, 0x114(r1)
  lwz       r3, 0x2E4(r31)
  bl        0xC09C
  stfs      f1, 0x1C(r29)
  addi      r3, r31, 0
  addi      r4, r19, 0
  lfs       f0, 0x10C(r1)
  li        r5, 0
  stfs      f0, 0x14(r29)
  lfs       f0, 0x110(r1)
  stfs      f0, 0x18(r29)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl
  li        r0, 0xFF
  stb       r0, 0x230(r1)
  addi      r3, r31, 0
  addi      r4, r14, 0
  stb       r0, 0x231(r1)
  li        r5, 0x1
  stb       r0, 0x232(r1)
  stb       r0, 0x233(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl
  lfs       f1, 0x2C(r29)
  addi      r3, r1, 0x118
  lfs       f0, 0x28(r29)
  fadds     f1, f14, f1
  stfs      f0, 0x118(r1)
  stfs      f1, 0x11C(r1)
  lfs       f0, 0x30(r29)
  stfs      f0, 0x120(r1)
  lwz       r4, 0x2E4(r31)
  addi      r4, r4, 0x1E0
  bl        0x714
  lwz       r5, 0x38(r29)
  addi      r3, r1, 0x124
  crclr     6, 0x6
  subi      r4, r13, 0x7AC0
  bl        0x1DF54C
  lwz       r3, 0x2DEC(r13)
  addi      r4, r1, 0x124
  lwz       r3, 0x10(r3)
  bl        -0xEF28
  lwz       r12, 0x3B4(r31)
  srawi     r0, r3, 0x1
  lwz       r4, 0x2DEC(r13)
  addze     r0, r0
  lwz       r12, 0xF0(r12)
  lwz       r4, 0x10(r4)
  addi      r3, r31, 0
  mtlr      r12
  neg       r6, r0
  addi      r5, r1, 0x118
  crclr     6, 0x6
  addi      r8, r1, 0x124
  li        r7, 0
  blrl
  lwz       r29, 0xC(r29)

.loc_0x920:
  cmplwi    r29, 0
  bne+      .loc_0x6B8
  lwz       r12, 0x3B4(r31)
  mr        r3, r31
  lbz       r4, 0x4A0(r1)
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl
  lmw       r14, 0x4E8(r1)
  lwz       r0, 0x5C4(r1)
  lfd       f31, 0x5B8(r1)
  lfd       f30, 0x5B0(r1)
  lfd       f29, 0x5A8(r1)
  lfd       f28, 0x5A0(r1)
  lfd       f27, 0x598(r1)
  lfd       f26, 0x590(r1)
  lfd       f25, 0x588(r1)
  lfd       f24, 0x580(r1)
  lfd       f23, 0x578(r1)
  lfd       f22, 0x570(r1)
  lfd       f21, 0x568(r1)
  lfd       f20, 0x560(r1)
  lfd       f19, 0x558(r1)
  lfd       f18, 0x550(r1)
  lfd       f17, 0x548(r1)
  lfd       f16, 0x540(r1)
  lfd       f15, 0x538(r1)
  lfd       f14, 0x530(r1)
  addi      r1, r1, 0x5C0
  mtlr      r0
  blr

.loc_0x9A0:

}
*/
/*
 * --INFO--
 * Address:	8003711C
 * Size:	00001C
 * Weak Function
 */
Vector3f::Vector3f(f32 const& _x, f32 const& _y, f32 const& _z)
    : x(_x)
    , y(_y)
    , z(_z)
{
	/*
  .loc_0x0:
	lfs       f0, 0x0(r4)
	stfs      f0, 0x0(r3)
	lfs       f0, 0x0(r5)
	stfs      f0, 0x4(r3)
	lfs       f0, 0x0(r6)
	stfs      f0, 0x8(r3)
	blr
  */
}

/*
 * --INFO--
 * Address:	80037138
 * Size:	000060
 */
/*
void RouteGroup::render2d(Graphics &, int &)
{

.loc_0x0:
  mflr      r0
  addi      r8, r3, 0
  stw       r0, 0x4(r1)
  mr        r0, r4
  mr        r3, r0
  crclr     6, 0x6
  stwu      r1, -0x8(r1)
  addi      r8, r8, 0x18
  lwz       r7, 0x2DEC(r13)
  lwz       r6, 0x0(r5)
  lwz       r4, 0x10(r7)
  addi      r6, r6, 0xC
  stw       r6, 0x0(r5)
  lis       r5, 0x8023
  subi      r7, r5, 0x75D4
  lwz       r12, 0x3B4(r3)
  li        r5, 0
  lwz       r12, 0xEC(r12)
  mtlr      r12
  blrl
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr

}
*/
/*
 * --INFO--
 * Address:	80037198
 * Size:	0003CC
 */
/*
void RouteGroup::loadini(CmdStream *)
{

.loc_0x0:
  mflr      r0
  lis       r6, 0x8022
  stw       r0, 0x4(r1)
  lis       r5, 0x8022
  lis       r7, 0x8023
  stwu      r1, -0x78(r1)
  stfd      f31, 0x70(r1)
  stfd      f30, 0x68(r1)
  stfd      f29, 0x60(r1)
  stmw      r22, 0x38(r1)
  mr        r28, r3
  lis       r3, 0x8023
  addi      r29, r4, 0
  addi      r27, r6, 0x738C
  addi      r26, r5, 0x737C
  subi      r25, r3, 0x746C
  subi      r24, r7, 0x743C
  addi      r31, r28, 0x58
  addi      r30, r28, 0x5C
  lfs       f29, -0x7C88(r2)
  lfs       f30, -0x7C84(r2)
  lfs       f31, -0x7C80(r2)
  b         .loc_0x370

.loc_0x5C:
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9EB4
  addi      r3, r29, 0
  subi      r4, r13, 0x7A88
  bl        0xA1CC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xBC
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9E94
  addi      r4, r3, 0
  crclr     6, 0x6
  addi      r3, r28, 0x5C
  bl        0x1DF36C
  lbz       r0, 0x0(r30)
  stb       r0, 0x0(r31)
  lbz       r0, 0x1(r30)
  stb       r0, 0x1(r31)
  lbz       r0, 0x2(r30)
  stb       r0, 0x2(r31)
  lbz       r0, 0x3(r30)
  stb       r0, 0x3(r31)
  b         .loc_0x370

.loc_0xBC:
  addi      r3, r29, 0
  subi      r4, r13, 0x7A84
  bl        0xA178
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xF0
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9E40
  addi      r4, r3, 0
  crclr     6, 0x6
  addi      r3, r28, 0x18
  bl        0x1DF318
  b         .loc_0x370

.loc_0xF0:
  addi      r3, r29, 0
  subi      r4, r13, 0x7A7C
  bl        0xA144
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x198
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9E0C
  crclr     6, 0x6
  addi      r5, r1, 0x34
  subi      r4, r13, 0x7AC0
  bl        0x1E0DE0
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9DF0
  crclr     6, 0x6
  addi      r5, r1, 0x30
  subi      r4, r13, 0x7AC0
  bl        0x1E0DC4
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9DD4
  crclr     6, 0x6
  addi      r5, r1, 0x2C
  subi      r4, r13, 0x7AC0
  bl        0x1E0DA8
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9DB8
  crclr     6, 0x6
  addi      r5, r1, 0x28
  subi      r4, r13, 0x7AC0
  bl        0x1E0D8C
  lwz       r3, 0x34(r1)
  li        r0, 0x61
  lwz       r5, 0x2C(r1)
  lwz       r4, 0x30(r1)
  stb       r3, 0x14(r28)
  stb       r4, 0x15(r28)
  stb       r5, 0x16(r28)
  stb       r0, 0x17(r28)
  b         .loc_0x370

.loc_0x198:
  addi      r3, r29, 0
  subi      r4, r13, 0x7A74
  bl        0xA09C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x26C
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9D64
  li        r3, 0x54
  bl        0xFCB0
  addi      r23, r3, 0
  mr.       r3, r23
  beq-      .loc_0x24C
  stw       r27, 0x0(r23)
  li        r22, 0
  subi      r0, r13, 0x7AC8
  stw       r26, 0x0(r23)
  addi      r3, r3, 0x3C
  subi      r4, r13, 0x7AC8
  stw       r22, 0x10(r23)
  stw       r22, 0xC(r23)
  stw       r22, 0x8(r23)
  stw       r0, 0x4(r23)
  stw       r24, 0x0(r23)
  stfs      f29, 0x30(r23)
  stfs      f29, 0x2C(r23)
  stfs      f29, 0x28(r23)
  stw       r27, 0x3C(r23)
  stw       r26, 0x3C(r23)
  stw       r22, 0x4C(r23)
  stw       r22, 0x48(r23)
  stw       r22, 0x44(r23)
  bl        -0x124DC
  stw       r25, 0x3C(r23)
  subi      r3, r13, 0x7AC4
  li        r0, 0x1
  stw       r22, 0x50(r23)
  stw       r22, 0x4C(r23)
  stw       r22, 0x48(r23)
  stw       r22, 0x44(r23)
  stw       r3, 0x40(r23)
  stfs      f30, 0x20(r23)
  stw       r22, 0x38(r23)
  stw       r0, 0x34(r23)
  stfs      f31, 0x24(r23)

.loc_0x24C:
  addi      r22, r23, 0
  addi      r3, r22, 0
  addi      r4, r29, 0
  bl        -0xF7C
  addi      r3, r28, 0x68
  addi      r4, r22, 0
  bl        0x91DC
  b         .loc_0x370

.loc_0x26C:
  addi      r3, r29, 0
  subi      r4, r13, 0x7A6C
  bl        0x9FC8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x370
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9C90
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9C84
  crclr     6, 0x6
  addi      r5, r1, 0x24
  subi      r4, r13, 0x7AC0
  bl        0x1E0C58
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9C68
  crclr     6, 0x6
  addi      r5, r1, 0x20
  subi      r4, r13, 0x7AC0
  bl        0x1E0C3C
  lwz       r0, 0x24(r1)
  lwz       r3, 0x20(r1)
  cmpw      r0, r3
  beq-      .loc_0x364
  lwz       r5, 0x78(r28)
  li        r23, 0
  li        r22, 0
  b         .loc_0x304

.loc_0x2E4:
  lwz       r4, 0x38(r5)
  cmpw      r4, r0
  bne-      .loc_0x2F4
  mr        r23, r5

.loc_0x2F4:
  cmpw      r4, r3
  bne-      .loc_0x300
  mr        r22, r5

.loc_0x300:
  lwz       r5, 0xC(r5)

.loc_0x304:
  cmplwi    r5, 0
  bne+      .loc_0x2E4
  cmplwi    r23, 0
  beq-      .loc_0x364
  cmplwi    r22, 0
  beq-      .loc_0x364
  li        r3, 0x18
  bl        0xFB4C
  cmplwi    r3, 0
  beq-      .loc_0x354
  stw       r27, 0x0(r3)
  li        r4, 0
  subi      r0, r13, 0x7AC8
  stw       r26, 0x0(r3)
  stw       r4, 0x10(r3)
  stw       r4, 0xC(r3)
  stw       r4, 0x8(r3)
  stw       r0, 0x4(r3)
  stw       r25, 0x0(r3)
  stw       r4, 0x14(r3)

.loc_0x354:
  stw       r22, 0x14(r3)
  addi      r4, r3, 0
  addi      r3, r23, 0x3C
  bl        0x90E0

.loc_0x364:
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9BAC

.loc_0x370:
  mr        r3, r29
  bl        0x984C
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x390
  mr        r3, r29
  bl        0x9F6C
  rlwinm.   r0,r3,0,24,31
  beq+      .loc_0x5C

.loc_0x390:
  mr        r3, r29
  bl        0x982C
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x3AC
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x9B70

.loc_0x3AC:
  lmw       r22, 0x38(r1)
  lwz       r0, 0x7C(r1)
  lfd       f31, 0x70(r1)
  lfd       f30, 0x68(r1)
  lfd       f29, 0x60(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr

}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	0001C0
 */
/*
void RouteGroup::saveini(char *, RandomAccessStream &)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	80037564
 * Size:	000004
 */
/*
void EditNode::msgCommand(DataMsg &)
{
}
*/

/*
 * --INFO--
 * Address:	80037568
 * Size:	000004
 */
/*
void EditNode::render2d(Graphics &, int &)
{
}
*/
