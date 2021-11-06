

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void __GXGetTexTileShift(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00015C
 */
void GXGetTexBufferSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80212104
 * Size:	0000C8
 */
void __GetImageTileCount(void)
{
/*
.loc_0x0:
  cmplwi    r3, 0x3C
  bgt-      .loc_0x44
  lis       r9, 0x802F
  subi      r9, r9, 0x7180
  rlwinm    r0,r3,2,0,29
  lwzx      r0, r9, r0
  mtctr     r0
  bctr      
  li        r11, 0x3
  li        r12, 0x3
  b         .loc_0x4C
  li        r11, 0x3
  li        r12, 0x2
  b         .loc_0x4C
  li        r11, 0x2
  li        r12, 0x2
  b         .loc_0x4C

.loc_0x44:
  li        r12, 0
  li        r11, 0

.loc_0x4C:
  rlwinm.   r0,r4,0,16,31
  bne-      .loc_0x58
  li        r4, 0x1

.loc_0x58:
  rlwinm.   r0,r5,0,16,31
  bne-      .loc_0x64
  li        r5, 0x1

.loc_0x64:
  li        r10, 0x1
  slw       r9, r10, r11
  rlwinm    r4,r4,0,16,31
  subi      r0, r9, 0x1
  add       r0, r4, r0
  sraw      r0, r0, r11
  slw       r4, r10, r12
  stw       r0, 0x0(r6)
  rlwinm    r5,r5,0,16,31
  subi      r0, r4, 0x1
  add       r0, r5, r0
  sraw      r0, r0, r12
  cmpwi     r3, 0x6
  stw       r0, 0x0(r7)
  beq-      .loc_0xAC
  cmpwi     r3, 0x16
  beq-      .loc_0xAC
  li        r10, 0

.loc_0xAC:
  cmpwi     r10, 0
  beq-      .loc_0xBC
  li        r0, 0x2
  b         .loc_0xC0

.loc_0xBC:
  li        r0, 0x1

.loc_0xC0:
  stw       r0, 0x0(r8)
  blr
*/
}

/*
 * --INFO--
 * Address:	802121CC
 * Size:	000254
 */
void GXInitTexObj(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stmw      r24, 0x40(r1)
  addi      r27, r4, 0
  addi      r28, r5, 0
  addi      r31, r3, 0
  addi      r29, r6, 0
  addi      r30, r7, 0
  addi      r24, r8, 0
  addi      r25, r9, 0
  addi      r26, r10, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x20EEE4
  lwz       r4, 0x0(r31)
  rlwinm.   r0,r26,0,24,31
  rlwinm    r3,r25,2,0,29
  rlwinm    r4,r4,0,0,29
  or        r4, r4, r24
  stw       r4, 0x0(r31)
  lwz       r0, 0x0(r31)
  rlwinm    r0,r0,0,30,27
  or        r0, r0, r3
  stw       r0, 0x0(r31)
  lwz       r0, 0x0(r31)
  rlwinm    r0,r0,0,28,26
  ori       r0, r0, 0x10
  stw       r0, 0x0(r31)
  beq-      .loc_0xF8
  lbz       r4, 0x1F(r31)
  rlwinm    r3,r28,0,16,31
  rlwinm    r0,r29,0,16,31
  ori       r4, r4, 0x1
  stb       r4, 0x1F(r31)
  cmplw     r3, r0
  lwz       r4, 0x0(r31)
  rlwinm    r4,r4,0,27,23
  ori       r4, r4, 0xC0
  stw       r4, 0x0(r31)
  ble-      .loc_0xB0
  cntlzw    r0, r3
  subfic    r0, r0, 0x1F
  b         .loc_0xB8

.loc_0xB0:
  cntlzw    r0, r0
  subfic    r0, r0, 0x1F

.loc_0xB8:
  stw       r0, 0x3C(r1)
  lis       r0, 0x4330
  lwz       r3, 0x4(r31)
  stw       r0, 0x38(r1)
  lfd       f1, -0x3C78(r2)
  rlwinm    r3,r3,0,24,15
  lfd       f0, 0x38(r1)
  lfs       f2, -0x3C80(r2)
  fsubs     f0, f0, f1
  fmuls     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0x30(r1)
  lwz       r0, 0x34(r1)
  rlwimi    r3,r0,8,16,23
  stw       r3, 0x4(r31)
  b         .loc_0x108

.loc_0xF8:
  lwz       r0, 0x0(r31)
  rlwinm    r0,r0,0,27,23
  ori       r0, r0, 0x80
  stw       r0, 0x0(r31)

.loc_0x108:
  stw       r30, 0x14(r31)
  rlwinm    r3,r29,0,16,31
  rlwinm    r7,r30,0,28,31
  lwz       r5, 0x8(r31)
  rlwinm    r4,r28,0,16,31
  subi      r0, r3, 0x1
  rlwinm    r6,r5,0,0,21
  subi      r5, r4, 0x1
  or        r5, r6, r5
  stw       r5, 0x8(r31)
  rlwinm    r5,r0,10,0,21
  rlwinm    r0,r27,27,7,31
  lwz       r6, 0x8(r31)
  cmplwi    r7, 0xE
  rlwinm    r6,r6,0,22,11
  or        r5, r6, r5
  stw       r5, 0x8(r31)
  lwz       r5, 0x8(r31)
  rlwinm    r5,r5,0,12,7
  rlwimi    r5,r30,20,8,11
  stw       r5, 0x8(r31)
  lwz       r5, 0xC(r31)
  rlwinm    r5,r5,0,0,10
  or        r0, r5, r0
  stw       r0, 0xC(r31)
  bgt-      .loc_0x1EC
  lis       r5, 0x802F
  subi      r5, r5, 0x708C
  rlwinm    r0,r7,2,0,29
  lwzx      r0, r5, r0
  mtctr     r0
  bctr      
  li        r0, 0x1
  stb       r0, 0x1E(r31)
  li        r0, 0x3
  li        r7, 0x3
  b         .loc_0x1FC
  li        r0, 0x2
  stb       r0, 0x1E(r31)
  li        r0, 0x3
  li        r7, 0x2
  b         .loc_0x1FC
  li        r0, 0x2
  stb       r0, 0x1E(r31)
  li        r0, 0x2
  li        r7, 0x2
  b         .loc_0x1FC
  li        r0, 0x3
  stb       r0, 0x1E(r31)
  li        r0, 0x2
  li        r7, 0x2
  b         .loc_0x1FC
  li        r0, 0
  stb       r0, 0x1E(r31)
  li        r0, 0x3
  li        r7, 0x3
  b         .loc_0x1FC

.loc_0x1EC:
  li        r0, 0x2
  stb       r0, 0x1E(r31)
  li        r0, 0x2
  li        r7, 0x2

.loc_0x1FC:
  rlwinm    r8,r0,0,16,31
  li        r6, 0x1
  slw       r5, r6, r8
  rlwinm    r7,r7,0,16,31
  subi      r0, r5, 0x1
  slw       r5, r6, r7
  add       r4, r4, r0
  subi      r0, r5, 0x1
  sraw      r4, r4, r8
  add       r0, r3, r0
  sraw      r0, r0, r7
  mullw     r0, r4, r0
  rlwinm    r0,r0,0,17,31
  sth       r0, 0x1C(r31)
  lbz       r0, 0x1F(r31)
  ori       r0, r0, 0x2
  stb       r0, 0x1F(r31)
  lwz       r0, 0x64(r1)
  lmw       r24, 0x40(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void GXInitTexObjCI(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80212420
 * Size:	000194
 */
void GXInitTexObjLOD(void)
{
/*
.loc_0x0:
  stwu      r1, -0x38(r1)
  lfs       f0, -0x3C70(r2)
  fcmpo     cr0, f3, f0
  bge-      .loc_0x18
  fmr       f3, f0
  b         .loc_0x2C

.loc_0x18:
  lfs       f0, -0x3C6C(r2)
  fcmpo     cr0, f3, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x2C
  lfs       f3, -0x3C68(r2)

.loc_0x2C:
  lfs       f0, -0x3C64(r2)
  cmpwi     r5, 0x1
  lwz       r0, 0x0(r3)
  fmuls     f0, f0, f3
  rlwinm    r5,r0,0,23,14
  fctiwz    f0, f0
  stfd      f0, 0x30(r1)
  lwz       r0, 0x34(r1)
  rlwimi    r5,r0,9,15,22
  stw       r5, 0x0(r3)
  bne-      .loc_0x60
  li        r5, 0x1
  b         .loc_0x64

.loc_0x60:
  li        r5, 0

.loc_0x64:
  lwz       r9, 0x0(r3)
  rlwinm.   r0,r7,0,24,31
  rlwinm    r5,r5,4,0,27
  rlwinm    r7,r9,0,28,26
  or        r5, r7, r5
  stw       r5, 0x0(r3)
  addi      r5, r13, 0x2AB8
  lbzx      r0, r5, r4
  lwz       r7, 0x0(r3)
  rlwinm    r0,r0,5,0,26
  rlwinm    r4,r7,0,27,23
  or        r0, r4, r0
  stw       r0, 0x0(r3)
  beq-      .loc_0xA4
  li        r0, 0
  b         .loc_0xA8

.loc_0xA4:
  li        r0, 0x1

.loc_0xA8:
  lwz       r4, 0x0(r3)
  rlwinm    r0,r0,8,0,23
  rlwinm    r4,r4,0,24,22
  or        r0, r4, r0
  stw       r0, 0x0(r3)
  rlwinm    r4,r8,19,0,12
  rlwinm    r0,r6,21,3,10
  lwz       r5, 0x0(r3)
  rlwinm    r5,r5,0,15,13
  stw       r5, 0x0(r3)
  lwz       r5, 0x0(r3)
  rlwinm    r5,r5,0,14,12
  stw       r5, 0x0(r3)
  lwz       r5, 0x0(r3)
  rlwinm    r5,r5,0,13,10
  or        r4, r5, r4
  stw       r4, 0x0(r3)
  lwz       r4, 0x0(r3)
  rlwinm    r4,r4,0,11,9
  or        r0, r4, r0
  stw       r0, 0x0(r3)
  lfs       f0, -0x3C60(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x110
  fmr       f1, f0
  b         .loc_0x120

.loc_0x110:
  lfs       f0, -0x3C5C(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x120
  fmr       f1, f0

.loc_0x120:
  lfs       f3, -0x3C80(r2)
  lfs       f0, -0x3C60(r2)
  fmuls     f1, f3, f1
  fcmpo     cr0, f2, f0
  fctiwz    f1, f1
  stfd      f1, 0x30(r1)
  lwz       r4, 0x34(r1)
  bge-      .loc_0x148
  fmr       f2, f0
  b         .loc_0x158

.loc_0x148:
  lfs       f0, -0x3C5C(r2)
  fcmpo     cr0, f2, f0
  ble-      .loc_0x158
  fmr       f2, f0

.loc_0x158:
  lwz       r0, 0x4(r3)
  rlwinm    r0,r0,0,0,23
  rlwimi    r0,r4,0,24,31
  stw       r0, 0x4(r3)
  lfs       f0, -0x3C80(r2)
  lwz       r0, 0x4(r3)
  fmuls     f0, f0, f2
  rlwinm    r4,r0,0,24,15
  fctiwz    f0, f0
  stfd      f0, 0x30(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x38
  rlwimi    r4,r0,8,16,23
  stw       r4, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void GXInitTexObjData(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void GXInitTexObjWrapMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXInitTexObjTlut(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXInitTexObjUserData(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXGetTexObjUserData(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void GXGetTexObjAll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GXGetTexObjData(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void GXGetTexObjWidth(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void GXGetTexObjHeight(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802125B4
 * Size:	000008
 */
void GXGetTexObjFmt(void)
{
/*
.loc_0x0:
  lwz       r3, 0x14(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GXGetTexObjWrapS(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GXGetTexObjWrapT(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void GXGetTexObjMipMap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void GXGetTexObjLODAll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void GXGetTexObjMinFilt(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GXGetTexObjMagFilt(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GXGetTexObjMinLOD(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void GXGetTexObjMaxLOD(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void GXGetTexObjLODBias(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GXGetTexObjBiasClamp(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void GXGetTexObjEdgeLOD(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GXGetTexObjMaxAniso(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXGetTexObjTlut(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802125BC
 * Size:	0001A8
 */
void GXLoadTexObjPreLoaded(void)
{
/*
.loc_0x0:
  mflr      r0
  addi      r7, r13, 0x2A90
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  lis       r31, 0xCC01
  stw       r30, 0x20(r1)
  li        r30, 0x61
  stw       r29, 0x1C(r1)
  addi      r29, r5, 0
  addi      r5, r13, 0x2AA0
  stw       r28, 0x18(r1)
  mr        r28, r3
  lwz       r6, 0x0(r3)
  addi      r3, r13, 0x2A80
  lbzx      r0, r3, r29
  addi      r3, r13, 0x2A88
  rlwinm    r0,r0,24,0,7
  rlwimi    r0,r6,0,8,31
  stw       r0, 0x0(r28)
  addi      r6, r13, 0x2A98
  lbzx      r0, r3, r29
  addi      r3, r13, 0x2AA8
  lwz       r8, 0x4(r28)
  rlwinm    r0,r0,24,0,7
  rlwimi    r0,r8,0,8,31
  stw       r0, 0x4(r28)
  lbzx      r0, r7, r29
  lwz       r8, 0x8(r28)
  rlwinm    r0,r0,24,0,7
  rlwimi    r0,r8,0,8,31
  stw       r0, 0x8(r28)
  lbzx      r0, r6, r29
  lwz       r7, 0x0(r4)
  rlwinm    r0,r0,24,0,7
  rlwimi    r0,r7,0,8,31
  stw       r0, 0x0(r4)
  lbzx      r0, r5, r29
  lwz       r6, 0x4(r4)
  rlwinm    r0,r0,24,0,7
  rlwimi    r0,r6,0,8,31
  stw       r0, 0x4(r4)
  lbzx      r0, r3, r29
  lwz       r5, 0xC(r28)
  rlwinm    r0,r0,24,0,7
  rlwimi    r0,r5,0,8,31
  stw       r0, 0xC(r28)
  stb       r30, -0x8000(r31)
  lwz       r0, 0x0(r28)
  stw       r0, -0x8000(r31)
  stb       r30, -0x8000(r31)
  lwz       r0, 0x4(r28)
  stw       r0, -0x8000(r31)
  stb       r30, -0x8000(r31)
  lwz       r0, 0x8(r28)
  stw       r0, -0x8000(r31)
  stb       r30, -0x8000(r31)
  lwz       r0, 0x0(r4)
  stw       r0, -0x8000(r31)
  stb       r30, -0x8000(r31)
  lwz       r0, 0x4(r4)
  stw       r0, -0x8000(r31)
  stb       r30, -0x8000(r31)
  lwz       r0, 0xC(r28)
  stw       r0, -0x8000(r31)
  lbz       r0, 0x1F(r28)
  rlwinm.   r0,r0,0,30,30
  bne-      .loc_0x148
  lwz       r4, 0x2A68(r13)
  lwz       r3, 0x18(r28)
  lwz       r12, 0x414(r4)
  mtlr      r12
  blrl      
  addi      r4, r13, 0x2AB0
  lwz       r5, 0x4(r3)
  lbzx      r0, r4, r29
  rlwinm    r0,r0,24,0,7
  rlwimi    r0,r5,0,8,31
  stw       r0, 0x4(r3)
  stb       r30, -0x8000(r31)
  lwz       r0, 0x4(r3)
  stw       r0, -0x8000(r31)

.loc_0x148:
  lwz       r3, 0x2A68(r13)
  rlwinm    r5,r29,2,0,29
  lwz       r4, 0x8(r28)
  li        r0, 0x1
  add       r3, r3, r5
  stw       r4, 0x45C(r3)
  lwz       r3, 0x2A68(r13)
  lwz       r4, 0x0(r28)
  add       r3, r3, r5
  stw       r4, 0x47C(r3)
  lwz       r4, 0x2A68(r13)
  lwz       r3, 0x4F0(r4)
  ori       r3, r3, 0x1
  stw       r3, 0x4F0(r4)
  lwz       r3, 0x2A68(r13)
  sth       r0, 0x2(r3)
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80212764
 * Size:	000054
 */
void GXLoadTexObj(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  lwz       r5, 0x2A68(r13)
  lwz       r12, 0x410(r5)
  mtlr      r12
  blrl      
  addi      r4, r3, 0
  addi      r3, r30, 0
  addi      r5, r31, 0
  bl        -0x1E0
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void GXInitTlutObj(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void GXGetTlutObjAll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GXGetTlutObjData(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void GXGetTlutObjFmt(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GXGetTlutObjNumEntries(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void GXLoadTlut(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802127B8
 * Size:	000120
 */
void GXInitTexCacheRegion(void)
{
/*
.loc_0x0:
  cmpwi     r6, 0x1
  beq-      .loc_0x2C
  bge-      .loc_0x18
  cmpwi     r6, 0
  bge-      .loc_0x24
  b         .loc_0x38

.loc_0x18:
  cmpwi     r6, 0x3
  bge-      .loc_0x38
  b         .loc_0x34

.loc_0x24:
  li        r10, 0x3
  b         .loc_0x38

.loc_0x2C:
  li        r10, 0x4
  b         .loc_0x38

.loc_0x34:
  li        r10, 0x5

.loc_0x38:
  li        r0, 0
  stw       r0, 0x0(r3)
  rlwinm    r6,r5,27,5,31
  rlwinm    r5,r10,15,0,16
  lwz       r9, 0x0(r3)
  rlwinm    r0,r10,18,0,13
  cmpwi     r8, 0x2
  rlwinm    r9,r9,0,0,16
  or        r6, r9, r6
  stw       r6, 0x0(r3)
  lwz       r6, 0x0(r3)
  rlwinm    r6,r6,0,17,13
  or        r5, r6, r5
  stw       r5, 0x0(r3)
  lwz       r5, 0x0(r3)
  rlwinm    r5,r5,0,14,10
  or        r0, r5, r0
  stw       r0, 0x0(r3)
  lwz       r0, 0x0(r3)
  rlwinm    r0,r0,0,11,9
  stw       r0, 0x0(r3)
  beq-      .loc_0xC0
  bge-      .loc_0xA4
  cmpwi     r8, 0
  beq-      .loc_0xB0
  bge-      .loc_0xB8
  b         .loc_0xCC

.loc_0xA4:
  cmpwi     r8, 0x4
  bge-      .loc_0xCC
  b         .loc_0xC8

.loc_0xB0:
  li        r10, 0x3
  b         .loc_0xCC

.loc_0xB8:
  li        r10, 0x4
  b         .loc_0xCC

.loc_0xC0:
  li        r10, 0x5
  b         .loc_0xCC

.loc_0xC8:
  li        r10, 0

.loc_0xCC:
  li        r0, 0
  stw       r0, 0x4(r3)
  rlwinm    r7,r7,27,5,31
  rlwinm    r6,r10,15,0,16
  lwz       r8, 0x4(r3)
  rlwinm    r5,r10,18,0,13
  li        r0, 0x1
  rlwinm    r8,r8,0,0,16
  or        r7, r8, r7
  stw       r7, 0x4(r3)
  lwz       r7, 0x4(r3)
  rlwinm    r7,r7,0,17,13
  or        r6, r7, r6
  stw       r6, 0x4(r3)
  lwz       r6, 0x4(r3)
  rlwinm    r6,r6,0,14,10
  or        r5, r6, r5
  stw       r5, 0x4(r3)
  stb       r4, 0xC(r3)
  stb       r0, 0xD(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void GXInitTexPreLoadRegion(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void GXGetTexRegionAll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802128D8
 * Size:	000048
 */
void GXInitTlutRegion(void)
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x0(r3)
  subis     r0, r4, 0x8
  rlwinm    r4,r0,23,9,31
  lwz       r6, 0x0(r3)
  rlwinm    r0,r5,10,0,21
  rlwinm    r5,r6,0,0,21
  or        r4, r5, r4
  stw       r4, 0x0(r3)
  lwz       r4, 0x0(r3)
  rlwinm    r4,r4,0,22,10
  or        r0, r4, r0
  stw       r0, 0x0(r3)
  lwz       r0, 0x0(r3)
  rlwinm    r0,r0,0,8,31
  oris      r0, r0, 0x6500
  stw       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void GXGetTlutRegionAll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void GXInvalidateTexRegion(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80212920
 * Size:	000048
 */
void GXInvalidateTexAll(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x64C
  li        r6, 0x61
  lis       r3, 0x6600
  lis       r5, 0xCC01
  stb       r6, -0x8000(r5)
  addi      r4, r3, 0x1000
  addi      r0, r3, 0x1100
  stw       r4, -0x8000(r5)
  stb       r6, -0x8000(r5)
  stw       r0, -0x8000(r5)
  bl        0x624
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80212968
 * Size:	000014
 */
void GXSetTexRegionCallback(void)
{
/*
.loc_0x0:
  lwz       r4, 0x2A68(r13)
  lwzu      r0, 0x410(r4)
  stw       r3, 0x0(r4)
  mr        r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021297C
 * Size:	000014
 */
void GXSetTlutRegionCallback(void)
{
/*
.loc_0x0:
  lwz       r4, 0x2A68(r13)
  lwzu      r0, 0x414(r4)
  stw       r3, 0x0(r4)
  mr        r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000244
 */
void GXPreLoadEntireTexture(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void GXSetTexCoordScaleManually(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void GXSetTexCoordCylWrap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void GXSetTexCoordBias(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80212990
 * Size:	0000CC
 */
void __SetSURegs(void)
{
/*
.loc_0x0:
  lwz       r5, 0x2A68(r13)
  rlwinm    r0,r4,2,0,29
  rlwinm    r9,r3,2,0,29
  add       r4, r5, r0
  add       r3, r5, r9
  lwz       r5, 0x45C(r3)
  li        r7, 0x61
  lwz       r3, 0xB8(r4)
  lis       r6, 0xCC01
  rlwinm    r3,r3,0,0,15
  rlwimi    r3,r5,0,22,31
  stw       r3, 0xB8(r4)
  li        r3, 0x1
  lwz       r4, 0x2A68(r13)
  add       r8, r4, r0
  lwz       r4, 0xD8(r8)
  rlwinm    r4,r4,0,0,15
  rlwimi    r4,r5,22,22,31
  stw       r4, 0xD8(r8)
  lwz       r5, 0x2A68(r13)
  add       r4, r5, r9
  lwz       r9, 0x47C(r4)
  add       r10, r5, r0
  lwz       r5, 0xB8(r10)
  rlwinm    r4,r9,30,30,31
  subfic    r8, r4, 0x1
  rlwinm    r4,r9,0,30,31
  subfic    r4, r4, 0x1
  cntlzw    r4, r4
  rlwinm    r5,r5,0,16,14
  rlwinm    r4,r4,11,8,15
  or        r4, r5, r4
  stw       r4, 0xB8(r10)
  cntlzw    r4, r8
  rlwinm    r4,r4,11,8,15
  lwz       r5, 0x2A68(r13)
  add       r8, r5, r0
  lwz       r5, 0xD8(r8)
  rlwinm    r5,r5,0,16,14
  or        r4, r5, r4
  stw       r4, 0xD8(r8)
  lwz       r5, 0x2A68(r13)
  stb       r7, -0x8000(r6)
  add       r4, r5, r0
  lwz       r0, 0xB8(r4)
  stw       r0, -0x8000(r6)
  stb       r7, -0x8000(r6)
  lwz       r0, 0xD8(r4)
  stw       r0, -0x8000(r6)
  sth       r3, 0x2(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	80212A5C
 * Size:	00016C
 */
void __GXSetSUTexRegs(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x4DC(r3)
  cmplwi    r0, 0xFF
  beq-      .loc_0x158
  lwz       r0, 0x204(r3)
  li        r30, 0
  rlwinm    r3,r0,22,28,31
  addi      r31, r3, 0x1
  rlwinm    r27,r0,16,29,31
  b         .loc_0xD4

.loc_0x38:
  cmpwi     r30, 0x2
  beq-      .loc_0x88
  bge-      .loc_0x54
  cmpwi     r30, 0
  beq-      .loc_0x60
  bge-      .loc_0x74
  b         .loc_0xAC

.loc_0x54:
  cmpwi     r30, 0x4
  bge-      .loc_0xAC
  b         .loc_0x9C

.loc_0x60:
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x120(r3)
  rlwinm    r29,r0,0,29,31
  rlwinm    r28,r0,29,29,31
  b         .loc_0xAC

.loc_0x74:
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x120(r3)
  rlwinm    r29,r0,26,29,31
  rlwinm    r28,r0,23,29,31
  b         .loc_0xAC

.loc_0x88:
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x120(r3)
  rlwinm    r29,r0,20,29,31
  rlwinm    r28,r0,17,29,31
  b         .loc_0xAC

.loc_0x9C:
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x120(r3)
  rlwinm    r29,r0,14,29,31
  rlwinm    r28,r0,11,29,31

.loc_0xAC:
  lwz       r3, 0x2A68(r13)
  li        r0, 0x1
  slw       r0, r0, r28
  lwz       r3, 0x4DC(r3)
  and.      r0, r3, r0
  bne-      .loc_0xD0
  addi      r3, r29, 0
  addi      r4, r28, 0
  bl        -0x198

.loc_0xD0:
  addi      r30, r30, 0x1

.loc_0xD4:
  cmplw     r30, r27
  blt+      .loc_0x38
  li        r27, 0
  addi      r30, r27, 0
  b         .loc_0x150

.loc_0xE8:
  lwz       r5, 0x2A68(r13)
  addi      r3, r30, 0x49C
  rlwinm    r4,r27,1,0,29
  lwzx      r3, r5, r3
  rlwinm.   r0,r27,0,31,31
  addi      r4, r4, 0x100
  add       r4, r5, r4
  rlwinm    r29,r3,0,24,22
  beq-      .loc_0x118
  lwz       r0, 0x0(r4)
  rlwinm    r28,r0,17,29,31
  b         .loc_0x120

.loc_0x118:
  lwz       r0, 0x0(r4)
  rlwinm    r28,r0,29,29,31

.loc_0x120:
  cmplwi    r29, 0xFF
  beq-      .loc_0x148
  li        r0, 0x1
  lwz       r3, 0x4DC(r5)
  slw       r0, r0, r28
  and.      r0, r3, r0
  bne-      .loc_0x148
  addi      r3, r29, 0
  addi      r4, r28, 0
  bl        -0x210

.loc_0x148:
  addi      r30, r30, 0x4
  addi      r27, r27, 0x1

.loc_0x150:
  cmplw     r27, r31
  blt+      .loc_0xE8

.loc_0x158:
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void __GXGetSUTexSize(void)
{
	// UNUSED FUNCTION
}
