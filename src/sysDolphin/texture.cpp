#include "types.h"
#include "Texture.h"
#include "Stream.h"
#include "system.h"
#include "sysNew.h"
#include "stl/string.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80044194
 * Size:	000070
 */
Texture::Texture()
{
	_30          = 0;
	_34          = 0;
	_20          = -1;
	mTextureData = nullptr;
	_1C          = 0.0f;
	_24          = new u32[8]; // this is (probably) not a u32 array, it's an object of size 0x20. TODO: work out WHAT object
	                           /*
	                           .loc_0x0:
	                             mflr      r0
	                             lis       r4, 0x8023
	                             stw       r0, 0x4(r1)
	                             subi      r0, r4, 0x6F50
	                             li        r4, 0
	                             stwu      r1, -0x18(r1)
	                             stw       r31, 0x14(r1)
	                             addi      r31, r3, 0
	                             lis       r3, 0x8023
	                             stw       r0, 0x0(r31)
	                             subi      r0, r3, 0x6F98
	                             li        r3, 0x20
	                             stw       r0, 0x0(r31)
	                             li        r0, -0x1
	                             stw       r4, 0x30(r31)
	                             stw       r4, 0x34(r31)
	                             stw       r0, 0x20(r31)
	                             stw       r4, 0x18(r31)
	                             lfs       f0, -0x7BA0(r2)
	                             stfs      f0, 0x1C(r31)
	                             bl        0x2E20
	                             stw       r3, 0x24(r31)
	                             mr        r3, r31
	                             lwz       r0, 0x1C(r1)
	                             lwz       r31, 0x14(r1)
	                             addi      r1, r1, 0x18
	                             mtlr      r0
	                             blr
	                           */
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void Texture::offsetGLtoGX(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80044204
 * Size:	0000D4
 */
u16 Texture::getAlpha(int p1, int p2)
{
	switch (_04) {
	case 5:
		// needs work
		return ((u8*)mPixelData)[(p1 % mTileSizeX) * mTileSizeY + mWidth % mTileSizeX] & 0xF0;
	default:
		// needs work
		u16 alpha = ((u16*)mPixelData)[(p1 % mTileSizeX) * mTileSizeY + mWidth % mTileSizeX];
		if (alpha & 0x8000) {
			return 255;
		}
		return (alpha >> 7) & 0xE0;
	}
	/*
	.loc_0x0:
	  lhz       r0, 0x4(r3)
	  cmpwi     r0, 0x5
	  beq-      .loc_0x10
	  b         .loc_0x68

	.loc_0x10:
	  lwz       r7, 0x10(r3)
	  lwz       r10, 0xC(r3)
	  divwu     r8, r5, r7
	  lhz       r0, 0x8(r3)
	  lwz       r3, 0x14(r3)
	  divwu     r9, r4, r10
	  mullw     r11, r10, r7
	  divwu     r6, r0, r10
	  mullw     r0, r8, r7
	  mullw     r7, r6, r11
	  mullw     r6, r9, r10
	  sub       r0, r5, r0
	  mullw     r0, r10, r0
	  sub       r4, r4, r6
	  mullw     r5, r8, r7
	  add       r4, r4, r0
	  mullw     r0, r9, r11
	  add       r4, r4, r5
	  add       r4, r0, r4
	  lbzx      r0, r3, r4
	  rlwinm    r3,r0,0,24,27
	  blr

	.loc_0x68:
	  lwz       r7, 0x10(r3)
	  lwz       r10, 0xC(r3)
	  divwu     r8, r5, r7
	  lhz       r0, 0x8(r3)
	  lwz       r3, 0x14(r3)
	  divwu     r6, r0, r10
	  mullw     r0, r8, r7
	  mullw     r11, r10, r7
	  sub       r0, r5, r0
	  mullw     r7, r6, r11
	  divwu     r9, r4, r10
	  mullw     r6, r9, r10
	  mullw     r0, r10, r0
	  sub       r4, r4, r6
	  add       r4, r4, r0
	  mullw     r5, r8, r7
	  mullw     r0, r9, r11
	  add       r4, r4, r5
	  add       r4, r0, r4
	  rlwinm    r0,r4,1,0,30
	  lhzx      r3, r3, r0
	  rlwinm.   r0,r3,0,16,16
	  beq-      .loc_0xCC
	  li        r3, 0xFF
	  blr

	.loc_0xCC:
	  rlwinm    r3,r3,25,24,26
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
void Texture::getRed(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800442D8
 * Size:	000168
 */
void Texture::read(RandomAccessStream& input)
{
	if (strcmp(input.mPath + (strlen(input.mPath) - 3), "txe") == 0) {
		TexImg* img = new TexImg;
		img->importTxe(this, input);
	} else if (strcmp(input.mPath + (strlen(input.mPath) - 3), "bti") == 0) {
		TexImg* img = new TexImg;
		img->importBti(this, input, nullptr);
	} else {
		strlen(input.mPath);
	}
	gsys->addTexture(this, input.mPath);
}

/*
 * --INFO--
 * Address:	80044440
 * Size:	00000C
 */
void Texture::detach()
{
	_20 = -1; // needs to use r4?
	          /*
	          .loc_0x0:
	            li        r4, -0x1
	            stw       r4, 0x20(r3)
	            blr
	          */
}

/*
 * --INFO--
 * Address:	8004444C
 * Size:	000118
 */
void Texture::attach()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r3, 0x20(r3)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x104
	  li        r0, 0
	  stw       r0, 0x20(r31)
	  lhz       r3, 0x6(r31)
	  rlwinm.   r0,r3,0,31,31
	  beq-      .loc_0x40
	  li        r8, 0
	  b         .loc_0x54

	.loc_0x40:
	  rlwinm.   r0,r3,0,30,30
	  beq-      .loc_0x50
	  li        r8, 0x2
	  b         .loc_0x54

	.loc_0x50:
	  li        r8, 0x1

	.loc_0x54:
	  rlwinm.   r0,r3,0,23,23
	  beq-      .loc_0x64
	  li        r9, 0
	  b         .loc_0x78

	.loc_0x64:
	  rlwinm.   r0,r3,0,22,22
	  beq-      .loc_0x74
	  li        r9, 0x2
	  b         .loc_0x78

	.loc_0x74:
	  li        r9, 0x1

	.loc_0x78:
	  lhz       r4, 0x4(r31)
	  lis       r3, 0x8023
	  lwz       r0, 0x18(r31)
	  subi      r3, r3, 0x6FD4
	  rlwinm    r4,r4,2,0,29
	  add       r3, r3, r4
	  cmplwi    r0, 0
	  lwz       r7, 0x0(r3)
	  beq-      .loc_0xA4
	  li        r10, 0x1
	  b         .loc_0xA8

	.loc_0xA4:
	  li        r10, 0

	.loc_0xA8:
	  lwz       r3, 0x24(r31)
	  lwz       r4, 0x14(r31)
	  lhz       r5, 0x8(r31)
	  lhz       r6, 0xA(r31)
	  bl        0x1CDCC8
	  lwz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x104
	  stw       r0, 0x14(r1)
	  lis       r0, 0x4330
	  lfd       f2, -0x7B98(r2)
	  li        r4, 0x5
	  stw       r0, 0x10(r1)
	  lwz       r3, 0x24(r31)
	  li        r5, 0x1
	  lfd       f0, 0x10(r1)
	  li        r6, 0
	  lfs       f1, -0x7BA0(r2)
	  fsubs     f2, f0, f2
	  lfs       f3, 0x1C(r31)
	  li        r7, 0
	  li        r8, 0
	  bl        0x1CDED4

	.loc_0x104:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80044564
 * Size:	0000E4
 */
void Texture::createBuffer(int, int, int, void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r7
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  sth       r6, 0x4(r3)
	  sth       r4, 0x8(r3)
	  sth       r5, 0xA(r3)
	  lhz       r3, 0x4(r3)
	  lhz       r4, 0x8(r29)
	  lhz       r5, 0xA(r29)
	  bl        -0x1BE30
	  cmplwi    r30, 0
	  addi      r31, r3, 0
	  beq-      .loc_0x50
	  mr        r3, r30
	  b         .loc_0x64

	.loc_0x50:
	  srawi     r0, r31, 0x1
	  addze     r0, r0
	  rlwinm    r3,r0,1,0,30
	  li        r4, 0x20
	  bl        0x2BA4

	.loc_0x64:
	  stw       r3, 0x14(r29)
	  lis       r3, 0x4330
	  addi      r4, r31, 0
	  lhz       r0, 0x8(r29)
	  lfd       f1, -0x7B98(r2)
	  stw       r0, 0x2C(r1)
	  lfs       f2, -0x7B90(r2)
	  stw       r3, 0x28(r1)
	  lfd       f0, 0x28(r1)
	  fsubs     f0, f0, f1
	  fdivs     f0, f2, f0
	  stfs      f0, 0x28(r29)
	  lhz       r0, 0xA(r29)
	  stw       r0, 0x24(r1)
	  stw       r3, 0x20(r1)
	  lfd       f0, 0x20(r1)
	  fsubs     f0, f0, f1
	  fdivs     f0, f2, f0
	  stfs      f0, 0x2C(r29)
	  lwz       r3, 0x14(r29)
	  bl        0x1B2604
	  lhz       r3, 0x4(r29)
	  addi      r4, r29, 0xC
	  addi      r5, r29, 0x10
	  bl        -0x1BCF0
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80044648
 * Size:	000110
 */
void Texture::grabBuffer(int, int, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r6,0,24,31
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r30, r6, 0
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r31, r7, 0
	  beq-      .loc_0x3C
	  li        r3, 0x1
	  li        r4, 0x3
	  li        r5, 0x1
	  bl        0x1CF750

	.loc_0x3C:
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x84
	  rlwinm    r5,r28,1,16,30
	  rlwinm    r6,r29,1,16,30
	  li        r3, 0
	  li        r4, 0
	  bl        0x1CC924
	  lhz       r4, 0x4(r27)
	  lis       r3, 0x8023
	  subi      r0, r3, 0x6FD4
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r5, 0x0(r3)
	  rlwinm    r3,r28,0,16,31
	  rlwinm    r4,r29,0,16,31
	  li        r6, 0x1
	  bl        0x1CCA00
	  b         .loc_0xC0

	.loc_0x84:
	  rlwinm    r5,r28,0,16,31
	  rlwinm    r6,r29,0,16,31
	  li        r3, 0
	  li        r4, 0
	  bl        0x1CC8E4
	  lhz       r4, 0x4(r27)
	  lis       r3, 0x8023
	  subi      r0, r3, 0x6FD4
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r5, 0x0(r3)
	  rlwinm    r3,r28,0,16,31
	  rlwinm    r4,r29,0,16,31
	  li        r6, 0
	  bl        0x1CC9C0

	.loc_0xC0:
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0xDC
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  bl        0x1CCCE0

	.loc_0xDC:
	  lwz       r3, 0x14(r27)
	  mr        r4, r30
	  bl        0x1CD088
	  bl        0x1CC128
	  li        r3, 0x1
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x1CF690
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80044758
 * Size:	000080
 */
void Texture::decodeData(TexImg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r0, 0x1C(r4)
	  sth       r0, 0x8(r3)
	  lwz       r0, 0x20(r4)
	  sth       r0, 0xA(r3)
	  lwz       r0, 0x18(r4)
	  sth       r0, 0x4(r3)
	  lwz       r0, 0x2C(r4)
	  stw       r0, 0x14(r3)
	  lwz       r0, 0x30(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x68
	  lwz       r0, 0x2C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x68
	  lwz       r3, 0x14(r30)
	  lwz       r4, 0x28(r31)
	  bl        0x1B2468
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x30(r31)

	.loc_0x68:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
