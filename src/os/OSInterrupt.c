

/*
 * --INFO--
 * Address:	801F8F7C
 * Size:	000014
 */
void OSDisableInterrupts(void)
{
/*
.loc_0x0:
  mfmsr     r3
  rlwinm    r4,r3,0,17,15
  mtmsr     r4
  rlwinm    r3,r3,17,31,31
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8F90
 * Size:	000014
 */
void OSEnableInterrupts(void)
{
/*
.loc_0x0:
  mfmsr     r3
  ori       r4, r3, 0x8000
  mtmsr     r4
  rlwinm    r3,r3,17,31,31
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8FA4
 * Size:	000024
 */
void OSRestoreInterrupts(void)
{
/*
.loc_0x0:
  cmpwi     r3, 0
  mfmsr     r4
  beq-      .loc_0x14
  ori       r5, r4, 0x8000
  b         .loc_0x18

.loc_0x14:
  rlwinm    r5,r4,0,17,15

.loc_0x18:
  mtmsr     r5
  rlwinm    r4,r4,17,31,31
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8FC8
 * Size:	00001C
 */
void __OSSetInterruptHandler(void)
{
/*
.loc_0x0:
  extsh     r0, r3
  lwz       r3, 0x31F8(r13)
  rlwinm    r0,r0,2,0,29
  add       r5, r3, r0
  lwz       r3, 0x0(r5)
  stw       r4, 0x0(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8FE4
 * Size:	000014
 */
void __OSGetInterruptHandler(void)
{
/*
.loc_0x0:
  extsh     r0, r3
  lwz       r3, 0x31F8(r13)
  rlwinm    r0,r0,2,0,29
  lwzx      r3, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8FF8
 * Size:	000074
 */
void __OSInterruptInit(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  lis       r31, 0x8000
  addi      r0, r31, 0x3040
  stw       r0, 0x31F8(r13)
  li        r4, 0
  li        r5, 0x80
  lwz       r3, 0x31F8(r13)
  bl        -0x1F5D00
  li        r0, 0
  stw       r0, 0xC4(r31)
  lis       r3, 0xCC00
  addi      r4, r3, 0x3000
  stw       r0, 0xC8(r31)
  li        r0, 0xF0
  li        r3, -0x20
  stw       r0, 0x4(r4)
  bl        0x2D8
  lis       r3, 0x8020
  subi      r4, r3, 0x68B0
  li        r3, 0x4
  bl        -0x3100
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F906C
 * Size:	0002B0
 */
void SetInterruptMask(void)
{
/*
.loc_0x0:
  cntlzw    r0, r3
  cmplwi    r0, 0x1A
  bgt-      .loc_0x2AC
  lis       r5, 0x802E
  addi      r5, r5, 0x7B54
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r5, r0
  mtctr     r0
  bctr      
  rlwinm    r0,r4,0,0,0
  cmplwi    r0, 0
  li        r5, 0
  bne-      .loc_0x38
  ori       r5, r5, 0x1

.loc_0x38:
  rlwinm    r0,r4,0,1,1
  cmplwi    r0, 0
  bne-      .loc_0x48
  ori       r5, r5, 0x2

.loc_0x48:
  rlwinm    r0,r4,0,2,2
  cmplwi    r0, 0
  bne-      .loc_0x58
  ori       r5, r5, 0x4

.loc_0x58:
  rlwinm    r0,r4,0,3,3
  cmplwi    r0, 0
  bne-      .loc_0x68
  ori       r5, r5, 0x8

.loc_0x68:
  rlwinm    r0,r4,0,4,4
  cmplwi    r0, 0
  bne-      .loc_0x78
  ori       r5, r5, 0x10

.loc_0x78:
  lis       r4, 0xCC00
  rlwinm    r0,r5,0,16,31
  addi      r4, r4, 0x4000
  sth       r0, 0x1C(r4)
  rlwinm    r3,r3,0,5,31
  b         .loc_0x2AC
  lis       r5, 0xCC00
  addi      r5, r5, 0x5000
  addi      r5, r5, 0xA
  rlwinm    r0,r4,0,5,5
  lhz       r6, 0x0(r5)
  cmplwi    r0, 0
  rlwinm    r6,r6,0,29,22
  bne-      .loc_0xB4
  ori       r6, r6, 0x10

.loc_0xB4:
  rlwinm    r0,r4,0,6,6
  cmplwi    r0, 0
  bne-      .loc_0xC4
  ori       r6, r6, 0x40

.loc_0xC4:
  rlwinm    r0,r4,0,7,7
  cmplwi    r0, 0
  bne-      .loc_0xD4
  ori       r6, r6, 0x100

.loc_0xD4:
  rlwinm    r0,r6,0,16,31
  sth       r0, 0x0(r5)
  rlwinm    r3,r3,0,8,4
  b         .loc_0x2AC
  rlwinm    r0,r4,0,8,8
  lis       r4, 0xCC00
  cmplwi    r0, 0
  lwz       r5, 0x6C00(r4)
  li        r0, -0x2D
  and       r5, r5, r0
  bne-      .loc_0x104
  ori       r5, r5, 0x4

.loc_0x104:
  lis       r4, 0xCC00
  stw       r5, 0x6C00(r4)
  rlwinm    r3,r3,0,9,7
  b         .loc_0x2AC
  rlwinm    r0,r4,0,9,9
  lis       r5, 0xCC00
  cmplwi    r0, 0
  lwz       r5, 0x6800(r5)
  li        r0, -0x2C10
  and       r5, r5, r0
  bne-      .loc_0x134
  ori       r5, r5, 0x1

.loc_0x134:
  rlwinm    r0,r4,0,10,10
  cmplwi    r0, 0
  bne-      .loc_0x144
  ori       r5, r5, 0x4

.loc_0x144:
  rlwinm    r0,r4,0,11,11
  cmplwi    r0, 0
  bne-      .loc_0x154
  ori       r5, r5, 0x400

.loc_0x154:
  lis       r4, 0xCC00
  stw       r5, 0x6800(r4)
  rlwinm    r3,r3,0,12,8
  b         .loc_0x2AC
  lis       r5, 0xCC00
  addi      r6, r5, 0x6800
  addi      r6, r6, 0x14
  rlwinm    r0,r4,0,12,12
  lwz       r7, 0x0(r6)
  li        r5, -0xC10
  cmplwi    r0, 0
  and       r7, r7, r5
  bne-      .loc_0x18C
  ori       r7, r7, 0x1

.loc_0x18C:
  rlwinm    r0,r4,0,13,13
  cmplwi    r0, 0
  bne-      .loc_0x19C
  ori       r7, r7, 0x4

.loc_0x19C:
  rlwinm    r0,r4,0,14,14
  cmplwi    r0, 0
  bne-      .loc_0x1AC
  ori       r7, r7, 0x400

.loc_0x1AC:
  stw       r7, 0x0(r6)
  rlwinm    r3,r3,0,15,11
  b         .loc_0x2AC
  lis       r5, 0xCC00
  addi      r5, r5, 0x6800
  addi      r5, r5, 0x28
  rlwinm    r0,r4,0,15,15
  lwz       r6, 0x0(r5)
  cmplwi    r0, 0
  rlwinm    r6,r6,0,0,27
  bne-      .loc_0x1DC
  ori       r6, r6, 0x1

.loc_0x1DC:
  rlwinm    r0,r4,0,16,16
  cmplwi    r0, 0
  bne-      .loc_0x1EC
  ori       r6, r6, 0x4

.loc_0x1EC:
  stw       r6, 0x0(r5)
  rlwinm    r3,r3,0,17,14
  b         .loc_0x2AC
  rlwinm    r0,r4,0,17,17
  cmplwi    r0, 0
  li        r5, 0xF0
  bne-      .loc_0x20C
  ori       r5, r5, 0x800

.loc_0x20C:
  rlwinm    r0,r4,0,20,20
  cmplwi    r0, 0
  bne-      .loc_0x21C
  ori       r5, r5, 0x8

.loc_0x21C:
  rlwinm    r0,r4,0,21,21
  cmplwi    r0, 0
  bne-      .loc_0x22C
  ori       r5, r5, 0x4

.loc_0x22C:
  rlwinm    r0,r4,0,22,22
  cmplwi    r0, 0
  bne-      .loc_0x23C
  ori       r5, r5, 0x2

.loc_0x23C:
  rlwinm    r0,r4,0,23,23
  cmplwi    r0, 0
  bne-      .loc_0x24C
  ori       r5, r5, 0x1

.loc_0x24C:
  rlwinm    r0,r4,0,24,24
  cmplwi    r0, 0
  bne-      .loc_0x25C
  ori       r5, r5, 0x100

.loc_0x25C:
  rlwinm    r0,r4,0,25,25
  cmplwi    r0, 0
  bne-      .loc_0x26C
  ori       r5, r5, 0x1000

.loc_0x26C:
  rlwinm    r0,r4,0,18,18
  cmplwi    r0, 0
  bne-      .loc_0x27C
  ori       r5, r5, 0x200

.loc_0x27C:
  rlwinm    r0,r4,0,19,19
  cmplwi    r0, 0
  bne-      .loc_0x28C
  ori       r5, r5, 0x400

.loc_0x28C:
  rlwinm    r0,r4,0,26,26
  cmplwi    r0, 0
  bne-      .loc_0x29C
  ori       r5, r5, 0x2000

.loc_0x29C:
  lis       r4, 0xCC00
  addi      r4, r4, 0x3000
  stw       r5, 0x4(r4)
  rlwinm    r3,r3,0,27,16

.loc_0x2AC:
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void OSGetInterruptMask(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void OSSetInterruptMask(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F931C
 * Size:	000088
 */
void __OSMaskInterrupts(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  mr        r31, r3
  bl        -0x3BC
  lis       r4, 0x8000
  lwz       r29, 0xC4(r4)
  mr        r30, r3
  lwz       r5, 0xC8(r4)
  or        r0, r29, r5
  andc      r3, r31, r0
  or        r31, r31, r29
  stw       r31, 0xC4(r4)
  or        r31, r31, r5
  b         .loc_0x48

.loc_0x48:
  b         .loc_0x4C

.loc_0x4C:
  b         .loc_0x58

.loc_0x50:
  mr        r4, r31
  bl        -0x304

.loc_0x58:
  cmplwi    r3, 0
  bne+      .loc_0x50
  mr        r3, r30
  bl        -0x3DC
  mr        r3, r29
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801F93A4
 * Size:	000088
 */
void __OSUnmaskInterrupts(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  mr        r31, r3
  bl        -0x444
  lis       r4, 0x8000
  lwz       r29, 0xC4(r4)
  mr        r30, r3
  lwz       r5, 0xC8(r4)
  or        r0, r29, r5
  and       r3, r31, r0
  andc      r31, r29, r31
  stw       r31, 0xC4(r4)
  or        r31, r31, r5
  b         .loc_0x48

.loc_0x48:
  b         .loc_0x4C

.loc_0x4C:
  b         .loc_0x58

.loc_0x50:
  mr        r4, r31
  bl        -0x38C

.loc_0x58:
  cmplwi    r3, 0
  bne+      .loc_0x50
  mr        r3, r30
  bl        -0x464
  mr        r3, r29
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801F942C
 * Size:	000324
 */
void __OSDispatchInterrupt(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  mr        r30, r4
  lis       r3, 0xCC00
  lwz       r31, 0x3000(r3)
  rlwinm    r31,r31,0,16,14
  cmplwi    r31, 0
  beq-      .loc_0x44
  addi      r3, r3, 0x3000
  lwz       r0, 0x4(r3)
  and       r0, r31, r0
  cmplwi    r0, 0
  bne-      .loc_0x4C

.loc_0x44:
  mr        r3, r30
  bl        -0x2118

.loc_0x4C:
  rlwinm    r0,r31,0,24,24
  cmplwi    r0, 0
  li        r0, 0
  beq-      .loc_0xB8
  lis       r3, 0xCC00
  addi      r3, r3, 0x4000
  lhz       r4, 0x1E(r3)
  rlwinm    r3,r4,0,31,31
  cmplwi    r3, 0
  beq-      .loc_0x78
  oris      r0, r0, 0x8000

.loc_0x78:
  rlwinm    r3,r4,0,30,30
  cmplwi    r3, 0
  beq-      .loc_0x88
  oris      r0, r0, 0x4000

.loc_0x88:
  rlwinm    r3,r4,0,29,29
  cmplwi    r3, 0
  beq-      .loc_0x98
  oris      r0, r0, 0x2000

.loc_0x98:
  rlwinm    r3,r4,0,28,28
  cmplwi    r3, 0
  beq-      .loc_0xA8
  oris      r0, r0, 0x1000

.loc_0xA8:
  rlwinm    r3,r4,0,27,27
  cmplwi    r3, 0
  beq-      .loc_0xB8
  oris      r0, r0, 0x800

.loc_0xB8:
  rlwinm    r3,r31,0,25,25
  cmplwi    r3, 0
  beq-      .loc_0x100
  lis       r3, 0xCC00
  addi      r3, r3, 0x5000
  lhz       r4, 0xA(r3)
  rlwinm    r3,r4,0,28,28
  cmplwi    r3, 0
  beq-      .loc_0xE0
  oris      r0, r0, 0x400

.loc_0xE0:
  rlwinm    r3,r4,0,26,26
  cmplwi    r3, 0
  beq-      .loc_0xF0
  oris      r0, r0, 0x200

.loc_0xF0:
  rlwinm    r3,r4,0,24,24
  cmplwi    r3, 0
  beq-      .loc_0x100
  oris      r0, r0, 0x100

.loc_0x100:
  rlwinm    r3,r31,0,26,26
  cmplwi    r3, 0
  beq-      .loc_0x124
  lis       r3, 0xCC00
  lwz       r3, 0x6C00(r3)
  rlwinm    r3,r3,0,28,28
  cmplwi    r3, 0
  beq-      .loc_0x124
  oris      r0, r0, 0x80

.loc_0x124:
  rlwinm    r3,r31,0,27,27
  cmplwi    r3, 0
  beq-      .loc_0x1D0
  lis       r3, 0xCC00
  lwz       r4, 0x6800(r3)
  rlwinm    r3,r4,0,30,30
  cmplwi    r3, 0
  beq-      .loc_0x148
  oris      r0, r0, 0x40

.loc_0x148:
  rlwinm    r3,r4,0,28,28
  cmplwi    r3, 0
  beq-      .loc_0x158
  oris      r0, r0, 0x20

.loc_0x158:
  rlwinm    r3,r4,0,20,20
  cmplwi    r3, 0
  beq-      .loc_0x168
  oris      r0, r0, 0x10

.loc_0x168:
  lis       r3, 0xCC00
  addi      r3, r3, 0x6800
  lwz       r4, 0x14(r3)
  rlwinm    r3,r4,0,30,30
  cmplwi    r3, 0
  beq-      .loc_0x184
  oris      r0, r0, 0x8

.loc_0x184:
  rlwinm    r3,r4,0,28,28
  cmplwi    r3, 0
  beq-      .loc_0x194
  oris      r0, r0, 0x4

.loc_0x194:
  rlwinm    r3,r4,0,20,20
  cmplwi    r3, 0
  beq-      .loc_0x1A4
  oris      r0, r0, 0x2

.loc_0x1A4:
  lis       r3, 0xCC00
  addi      r3, r3, 0x6800
  lwz       r4, 0x28(r3)
  rlwinm    r3,r4,0,30,30
  cmplwi    r3, 0
  beq-      .loc_0x1C0
  oris      r0, r0, 0x1

.loc_0x1C0:
  rlwinm    r3,r4,0,28,28
  cmplwi    r3, 0
  beq-      .loc_0x1D0
  ori       r0, r0, 0x8000

.loc_0x1D0:
  rlwinm    r3,r31,0,18,18
  cmplwi    r3, 0
  beq-      .loc_0x1E0
  ori       r0, r0, 0x20

.loc_0x1E0:
  rlwinm    r3,r31,0,19,19
  cmplwi    r3, 0
  beq-      .loc_0x1F0
  ori       r0, r0, 0x40

.loc_0x1F0:
  rlwinm    r3,r31,0,21,21
  cmplwi    r3, 0
  beq-      .loc_0x200
  ori       r0, r0, 0x1000

.loc_0x200:
  rlwinm    r3,r31,0,22,22
  cmplwi    r3, 0
  beq-      .loc_0x210
  ori       r0, r0, 0x2000

.loc_0x210:
  rlwinm    r3,r31,0,23,23
  cmplwi    r3, 0
  beq-      .loc_0x220
  ori       r0, r0, 0x80

.loc_0x220:
  rlwinm    r3,r31,0,28,28
  cmplwi    r3, 0
  beq-      .loc_0x230
  ori       r0, r0, 0x800

.loc_0x230:
  rlwinm    r3,r31,0,29,29
  cmplwi    r3, 0
  beq-      .loc_0x240
  ori       r0, r0, 0x400

.loc_0x240:
  rlwinm    r3,r31,0,30,30
  cmplwi    r3, 0
  beq-      .loc_0x250
  ori       r0, r0, 0x200

.loc_0x250:
  rlwinm    r3,r31,0,20,20
  cmplwi    r3, 0
  beq-      .loc_0x260
  ori       r0, r0, 0x4000

.loc_0x260:
  rlwinm    r3,r31,0,31,31
  cmplwi    r3, 0
  beq-      .loc_0x270
  ori       r0, r0, 0x100

.loc_0x270:
  lis       r3, 0x8000
  lwz       r4, 0xC4(r3)
  lwz       r3, 0xC8(r3)
  or        r3, r4, r3
  andc      r4, r0, r3
  cmplwi    r4, 0
  beq-      .loc_0x300
  lis       r3, 0x802E
  addi      r0, r3, 0x7B28
  mr        r3, r0
  b         .loc_0x29C

.loc_0x29C:
  b         .loc_0x2A0

.loc_0x2A0:
  lwz       r0, 0x0(r3)
  and       r0, r4, r0
  cmplwi    r0, 0
  beq-      .loc_0x2BC
  cntlzw    r0, r0
  extsh     r29, r0
  b         .loc_0x2C4

.loc_0x2BC:
  addi      r3, r3, 0x4
  b         .loc_0x2A0

.loc_0x2C4:
  lwz       r3, 0x31F8(r13)
  rlwinm    r0,r29,2,0,29
  lwzx      r31, r3, r0
  cmplwi    r31, 0
  beq-      .loc_0x300
  bl        0x2420
  mr        r3, r29
  mr        r4, r30
  mr        r12, r31
  mtlr      r12
  blrl      
  bl        0x2448
  bl        0x2938
  mr        r3, r30
  bl        -0x23CC

.loc_0x300:
  mr        r3, r30
  bl        -0x23D4
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	801F9750
 * Size:	00004C
 */
void ExternalInterruptHandler(void)
{
/*
.loc_0x0:
  stw       r0, 0x0(r4)
  stw       r1, 0x4(r4)
  stw       r2, 0x8(r4)
  stmw      r6, 0x18(r4)
  mfspr     r0, 0x391
  stw       r0, 0x1A8(r4)
  mfspr     r0, 0x392
  stw       r0, 0x1AC(r4)
  mfspr     r0, 0x393
  stw       r0, 0x1B0(r4)
  mfspr     r0, 0x394
  stw       r0, 0x1B4(r4)
  mfspr     r0, 0x395
  stw       r0, 0x1B8(r4)
  mfspr     r0, 0x396
  stw       r0, 0x1BC(r4)
  mfspr     r0, 0x397
  stw       r0, 0x1C0(r4)
  b         -0x36C
*/
}
