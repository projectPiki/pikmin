#include "types.h"

/*
 * --INFO--
 * Address:	80215648
 * Size:	0002A4
 */
void __dec2num(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stmw      r26, 0x28(r1)
	  lbz       r0, 0x4(r3)
	  lbz       r31, 0x0(r3)
	  cmpwi     r0, 0x1
	  lfd       f31, -0x3C18(r2)
	  mr        r28, r0
	  lha       r29, 0x2(r3)
	  lbz       r0, 0x5(r3)
	  extsb     r31, r31
	  blt-      .loc_0x44
	  extsb     r0, r0
	  cmpwi     r0, 0x30
	  bne-      .loc_0x4C

	.loc_0x44:
	  lfd       f1, -0x3C18(r2)
	  b         .loc_0x28C

	.loc_0x4C:
	  cmpwi     r0, 0x49
	  bne-      .loc_0x78
	  cmpwi     r31, 0
	  beq-      .loc_0x6C
	  lis       r3, 0x802F
	  lfd       f0, -0x6B70(r3)
	  fneg      f1, f0
	  b         .loc_0x28C

	.loc_0x6C:
	  lis       r3, 0x802F
	  lfd       f1, -0x6B70(r3)
	  b         .loc_0x28C

	.loc_0x78:
	  cmpwi     r0, 0x4E
	  bne-      .loc_0x8C
	  lis       r3, 0x802F
	  lfd       f1, -0x6B68(r3)
	  b         .loc_0x28C

	.loc_0x8C:
	  cmpwi     r28, 0x10
	  ble-      .loc_0xA0
	  add       r29, r28, r29
	  li        r28, 0x10
	  subi      r29, r29, 0x10

	.loc_0xA0:
	  srawi     r0, r28, 0x3
	  addze     r0, r0
	  rlwinm    r0,r0,3,0,28
	  subc.     r0, r28, r0
	  addi      r26, r3, 0x5
	  mr        r27, r0
	  bne-      .loc_0xC0
	  li        r27, 0x8

	.loc_0xC0:
	  subi      r0, r28, 0x1
	  lfd       f2, -0x3C00(r2)
	  xoris     r0, r0, 0x8000
	  lfd       f1, 0x2AC8(r13)
	  stw       r0, 0x24(r1)
	  lis       r30, 0x4330
	  add       r29, r28, r29
	  stw       r30, 0x20(r1)
	  subi      r29, r29, 0x1
	  lfd       f0, 0x20(r1)
	  fsub      f2, f0, f2
	  bl        0x5FD4
	  lfd       f3, -0x3C10(r2)
	  lfd       f2, -0x3C00(r2)
	  b         .loc_0x148

	.loc_0xFC:
	  addi      r4, r27, 0x1
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0x108:
	  mulli     r0, r3, 0xA
	  lbz       r3, 0x0(r26)
	  add       r3, r3, r0
	  addi      r26, r26, 0x1
	  subi      r3, r3, 0x30

	.loc_0x11C:
	  subic.    r4, r4, 0x1
	  bne+      .loc_0x108
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x24(r1)
	  sub.      r28, r28, r27
	  stw       r30, 0x20(r1)
	  lfd       f0, 0x20(r1)
	  fsub      f0, f0, f2
	  fmadd     f31, f3, f31, f0
	  beq-      .loc_0x150
	  li        r27, 0x8

	.loc_0x148:
	  cmpwi     r27, 0
	  bne+      .loc_0xFC

	.loc_0x150:
	  fdiv      f31, f31, f1
	  srawi     r0, r29, 0x1F
	  xor       r5, r0, r29
	  sub       r5, r5, r0
	  lis       r3, 0x8022
	  addi      r0, r3, 0x2780
	  cmpwi     r5, 0x1FF
	  mr        r4, r0
	  ble-      .loc_0x1A8
	  cmpwi     r29, 0
	  bge-      .loc_0x184
	  lfd       f1, -0x3C18(r2)
	  b         .loc_0x28C

	.loc_0x184:
	  cmpwi     r31, 0
	  beq-      .loc_0x19C
	  lis       r3, 0x802F
	  lfd       f0, -0x6B70(r3)
	  fneg      f1, f0
	  b         .loc_0x28C

	.loc_0x19C:
	  lis       r3, 0x802F
	  lfd       f1, -0x6B70(r3)
	  b         .loc_0x28C

	.loc_0x1A8:
	  lis       r3, 0x802F
	  lfd       f2, -0x3C08(r2)
	  subi      r3, r3, 0x6B78
	  b         .loc_0x204

	.loc_0x1B8:
	  rlwinm.   r0,r5,0,31,31
	  beq-      .loc_0x1FC
	  lfd       f0, 0x0(r3)
	  lfd       f1, 0x0(r4)
	  fdiv      f0, f0, f1
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x1F8
	  cmpwi     r31, 0
	  beq-      .loc_0x1EC
	  lis       r3, 0x802F
	  lfd       f0, -0x6B70(r3)
	  fneg      f1, f0
	  b         .loc_0x28C

	.loc_0x1EC:
	  lis       r3, 0x802F
	  lfd       f1, -0x6B70(r3)
	  b         .loc_0x28C

	.loc_0x1F8:
	  fmul      f2, f2, f1

	.loc_0x1FC:
	  srawi     r5, r5, 0x1
	  addi      r4, r4, 0x8

	.loc_0x204:
	  cmpwi     r5, 0
	  bne+      .loc_0x1B8
	  cmpwi     r29, 0
	  bge-      .loc_0x238
	  lis       r3, 0x802F
	  lfd       f0, -0x6B80(r3)
	  fmul      f0, f0, f2
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x230
	  lfd       f1, -0x3C18(r2)
	  b         .loc_0x28C

	.loc_0x230:
	  fdiv      f31, f31, f2
	  b         .loc_0x278

	.loc_0x238:
	  ble-      .loc_0x278
	  lis       r3, 0x802F
	  lfd       f0, -0x6B78(r3)
	  fdiv      f0, f0, f2
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x274
	  cmpwi     r31, 0
	  beq-      .loc_0x268
	  lis       r3, 0x802F
	  lfd       f0, -0x6B70(r3)
	  fneg      f1, f0
	  b         .loc_0x28C

	.loc_0x268:
	  lis       r3, 0x802F
	  lfd       f1, -0x6B70(r3)
	  b         .loc_0x28C

	.loc_0x274:
	  fmul      f31, f31, f2

	.loc_0x278:
	  cmpwi     r31, 0
	  beq-      .loc_0x288
	  fneg      f1, f31
	  b         .loc_0x28C

	.loc_0x288:
	  fmr       f1, f31

	.loc_0x28C:
	  lmw       r26, 0x28(r1)
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802158EC
 * Size:	0003B4
 */
void __num2dec(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  fmr       f31, f1
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x54(r1)
	  mr        r29, r3
	  lha       r0, 0x2(r3)
	  cmpwi     r0, 0x10
	  mr        r31, r0
	  ble-      .loc_0x3C
	  li        r31, 0x10

	.loc_0x3C:
	  li        r3, 0
	  stb       r3, 0x0(r30)
	  li        r0, 0x1
	  sth       r3, 0x2(r30)
	  stb       r0, 0x4(r30)
	  lfd       f0, -0x3C18(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x68
	  li        r0, 0x30
	  stb       r0, 0x5(r30)
	  b         .loc_0x394

	.loc_0x68:
	  stfd      f31, 0x28(r1)
	  lis       r0, 0x7FF0
	  lwz       r4, 0x28(r1)
	  rlwinm    r3,r4,0,1,11
	  cmpw      r3, r0
	  beq-      .loc_0x90
	  bge-      .loc_0xD8
	  cmpwi     r3, 0
	  beq-      .loc_0xB4
	  b         .loc_0xD8

	.loc_0x90:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0xA4
	  lwz       r0, 0x2C(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0xAC

	.loc_0xA4:
	  li        r0, 0x1
	  b         .loc_0xDC

	.loc_0xAC:
	  li        r0, 0x2
	  b         .loc_0xDC

	.loc_0xB4:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0xC8
	  lwz       r0, 0x2C(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0xD0

	.loc_0xC8:
	  li        r0, 0x5
	  b         .loc_0xDC

	.loc_0xD0:
	  li        r0, 0x3
	  b         .loc_0xDC

	.loc_0xD8:
	  li        r0, 0x4

	.loc_0xDC:
	  cmpwi     r0, 0x2
	  bgt-      .loc_0x174
	  stfd      f31, 0x20(r1)
	  lis       r0, 0x7FF0
	  lwz       r4, 0x20(r1)
	  rlwinm    r3,r4,0,1,11
	  cmpw      r3, r0
	  beq-      .loc_0x10C
	  bge-      .loc_0x154
	  cmpwi     r3, 0
	  beq-      .loc_0x130
	  b         .loc_0x154

	.loc_0x10C:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0x120
	  lwz       r0, 0x24(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x128

	.loc_0x120:
	  li        r0, 0x1
	  b         .loc_0x158

	.loc_0x128:
	  li        r0, 0x2
	  b         .loc_0x158

	.loc_0x130:
	  rlwinm.   r0,r4,0,12,31
	  bne-      .loc_0x144
	  lwz       r0, 0x24(r1)
	  cmpwi     r0, 0
	  beq-      .loc_0x14C

	.loc_0x144:
	  li        r0, 0x5
	  b         .loc_0x158

	.loc_0x14C:
	  li        r0, 0x3
	  b         .loc_0x158

	.loc_0x154:
	  li        r0, 0x4

	.loc_0x158:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x168
	  li        r0, 0x4E
	  b         .loc_0x16C

	.loc_0x168:
	  li        r0, 0x49

	.loc_0x16C:
	  stb       r0, 0x5(r30)
	  b         .loc_0x394

	.loc_0x174:
	  li        r0, 0
	  stb       r0, 0x4(r30)
	  lfd       f0, -0x3C18(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x194
	  li        r0, 0x1
	  fneg      f31, f31
	  stb       r0, 0x0(r30)

	.loc_0x194:
	  fmr       f1, f31
	  addi      r3, r1, 0x30
	  bl        0x5A4C
	  lis       r3, 0x5
	  lwz       r4, 0x30(r1)
	  subi      r0, r3, 0x681B
	  mullw     r0, r4, r0
	  lis       r3, 0x431C
	  subi      r3, r3, 0x217D
	  mulhw     r0, r3, r0
	  srawi     r0, r0, 0x12
	  rlwinm    r3,r0,1,31,31
	  add.      r4, r0, r3
	  lis       r3, 0x8022
	  addi      r0, r3, 0x2780
	  addi      r3, r4, 0
	  mr        r5, r0
	  bge-      .loc_0x208
	  neg       r4, r4
	  b         .loc_0x1FC

	.loc_0x1E4:
	  rlwinm.   r0,r4,0,31,31
	  beq-      .loc_0x1F4
	  lfd       f0, 0x0(r5)
	  fmul      f31, f31, f0

	.loc_0x1F4:
	  srawi     r4, r4, 0x1
	  addi      r5, r5, 0x8

	.loc_0x1FC:
	  cmpwi     r4, 0
	  bne+      .loc_0x1E4
	  b         .loc_0x238

	.loc_0x208:
	  ble-      .loc_0x238
	  lfd       f1, -0x3C08(r2)
	  b         .loc_0x22C

	.loc_0x214:
	  rlwinm.   r0,r4,0,31,31
	  beq-      .loc_0x224
	  lfd       f0, 0x0(r5)
	  fmul      f1, f1, f0

	.loc_0x224:
	  srawi     r4, r4, 0x1
	  addi      r5, r5, 0x8

	.loc_0x22C:
	  cmpwi     r4, 0
	  bne+      .loc_0x214
	  fdiv      f31, f31, f1

	.loc_0x238:
	  lfd       f1, -0x3BF8(r2)
	  lfd       f0, -0x3C08(r2)
	  b         .loc_0x24C

	.loc_0x244:
	  fmul      f31, f31, f1
	  addi      r3, r3, 0x1

	.loc_0x24C:
	  fcmpo     cr0, f31, f0
	  cror      2, 0x1, 0x2
	  beq+      .loc_0x244
	  lfd       f1, -0x3BF0(r2)
	  lfd       f0, -0x3BF8(r2)
	  b         .loc_0x26C

	.loc_0x264:
	  fmul      f31, f31, f1
	  subi      r3, r3, 0x1

	.loc_0x26C:
	  fcmpo     cr0, f31, f0
	  blt+      .loc_0x264
	  lis       r5, 0x6666
	  lfd       f1, -0x3C00(r2)
	  lis       r6, 0x8022
	  addi      r4, r30, 0x5
	  addi      r7, r5, 0x6667
	  addi      r10, r6, 0x27C8
	  lis       r9, 0x4330
	  b         .loc_0x33C

	.loc_0x294:
	  cmpwi     r31, 0x8
	  addi      r12, r31, 0
	  ble-      .loc_0x2A4
	  li        r12, 0x8

	.loc_0x2A4:
	  lbz       r6, 0x4(r30)
	  rlwinm    r0,r12,3,0,28
	  add       r5, r10, r0
	  add       r0, r6, r12
	  stb       r0, 0x4(r30)
	  sub       r31, r31, r12
	  sub       r3, r3, r12
	  lfd       f0, -0x8(r5)
	  add       r4, r4, r12
	  addi      r11, r12, 0x1
	  fmul      f31, f31, f0
	  fctiwz    f0, f31
	  stfd      f0, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stfd      f0, 0x48(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x3C(r1)
	  lwz       r6, 0x4C(r1)
	  stw       r9, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsub      f0, f0, f1
	  fsub      f31, f31, f0
	  b         .loc_0x330

	.loc_0x300:
	  mulhw     r8, r7, r6
	  srawi     r0, r8, 0x2
	  rlwinm    r5,r0,1,31,31
	  add       r0, r0, r5
	  mulli     r0, r0, 0xA
	  sub       r6, r6, r0
	  srawi     r0, r8, 0x2
	  addi      r6, r6, 0x30
	  stb       r6, -0x1(r4)
	  rlwinm    r5,r0,1,31,31
	  add       r6, r0, r5
	  subi      r4, r4, 0x1

	.loc_0x330:
	  subic.    r11, r11, 0x1
	  bne+      .loc_0x300
	  add       r4, r4, r12

	.loc_0x33C:
	  cmpwi     r31, 0
	  bne+      .loc_0x294
	  lha       r5, 0x2(r29)
	  cmpwi     r5, 0x24
	  ble-      .loc_0x354
	  li        r5, 0x24

	.loc_0x354:
	  lbz       r0, 0x4(r30)
	  sub.      r5, r5, r0
	  ble-      .loc_0x38C
	  addi      r6, r5, 0x1
	  li        r0, 0x30
	  b         .loc_0x374

	.loc_0x36C:
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1

	.loc_0x374:
	  subic.    r6, r6, 0x1
	  bne+      .loc_0x36C
	  lbz       r0, 0x4(r30)
	  sub       r3, r3, r5
	  add       r0, r0, r5
	  stb       r0, 0x4(r30)

	.loc_0x38C:
	  extsh     r0, r3
	  sth       r0, 0x2(r30)

	.loc_0x394:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  mtlr      r0
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x68
	  blr
	*/
}
