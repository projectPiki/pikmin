.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8009A2C4 00097224  80 1E 00 04 */	lwz r0, 4(r30)
/* 8009A2C8 00097228  80 9F 00 08 */	lwz r4, 8(r31)
/* 8009A2CC 0009722C  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 8009A2D0 00097230  54 00 10 3A */	slwi r0, r0, 2
/* 8009A2D4 00097234  7C 83 01 2E */	stwx r4, r3, r0
/* 8009A2D8 00097238  80 7F 00 08 */	lwz r3, 8(r31)
/* 8009A2DC 0009723C  38 03 00 01 */	addi r0, r3, 1
/* 8009A2E0 00097240  90 1F 00 08 */	stw r0, 8(r31)
lbl_8009A2E4:
/* 8009A2E4 00097244  38 60 00 10 */	li r3, 0x10
/* 8009A2E8 00097248  4B FA CD 1D */	bl alloc__6SystemFUl
/* 8009A2EC 0009724C  3B C3 00 00 */	addi r30, r3, 0
/* 8009A2F0 00097250  7F C3 F3 79 */	or. r3, r30, r30
/* 8009A2F4 00097254  41 82 00 08 */	beq lbl_8009A2FC
/* 8009A2F8 00097258  48 00 02 49 */	bl __ct__15PelletDeadStateFv
lbl_8009A2FC:
/* 8009A2FC 0009725C  80 9F 00 08 */	lwz r4, 8(r31)
/* 8009A300 00097260  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8009A304 00097264  7C 04 00 00 */	cmpw r4, r0
/* 8009A308 00097268  40 80 00 74 */	bge lbl_8009A37C
/* 8009A30C 0009726C  80 7F 00 04 */	lwz r3, 4(r31)
/* 8009A310 00097270  54 80 10 3A */	slwi r0, r4, 2
/* 8009A314 00097274  7F C3 01 2E */	stwx r30, r3, r0
/* 8009A318 00097278  80 7E 00 04 */	lwz r3, 4(r30)
/* 8009A31C 0009727C  2C 03 00 00 */	cmpwi r3, 0
/* 8009A320 00097280  41 80 00 10 */	blt lbl_8009A330
/* 8009A324 00097284  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8009A328 00097288  7C 03 00 00 */	cmpw r3, r0
/* 8009A32C 0009728C  41 80 00 0C */	blt lbl_8009A338
lbl_8009A330:
/* 8009A330 00097290  38 00 00 00 */	li r0, 0
/* 8009A334 00097294  48 00 00 08 */	b lbl_8009A33C
lbl_8009A338:
/* 8009A338 00097298  38 00 00 01 */	li r0, 1
lbl_8009A33C:
/* 8009A33C 0009729C  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8009A340 000972A0  41 82 00 3C */	beq lbl_8009A37C
/* 8009A344 000972A4  93 FE 00 08 */	stw r31, 8(r30)
/* 8009A348 000972A8  80 1F 00 08 */	lwz r0, 8(r31)
/* 8009A34C 000972AC  80 9E 00 04 */	lwz r4, 4(r30)
/* 8009A350 000972B0  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 8009A354 000972B4  54 00 10 3A */	slwi r0, r0, 2
/* 8009A358 000972B8  7C 83 01 2E */	stwx r4, r3, r0
/* 8009A35C 000972BC  80 1E 00 04 */	lwz r0, 4(r30)
/* 8009A360 000972C0  80 9F 00 08 */	lwz r4, 8(r31)
/* 8009A364 000972C4  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 8009A368 000972C8  54 00 10 3A */	slwi r0, r0, 2
/* 8009A36C 000972CC  7C 83 01 2E */	stwx r4, r3, r0
/* 8009A370 000972D0  80 7F 00 08 */	lwz r3, 8(r31)
/* 8009A374 000972D4  38 03 00 01 */	addi r0, r3, 1
/* 8009A378 000972D8  90 1F 00 08 */	stw r0, 8(r31)
lbl_8009A37C:
/* 8009A37C 000972DC  38 60 00 14 */	li r3, 0x14
/* 8009A380 000972E0  4B FA CC 85 */	bl alloc__6SystemFUl
/* 8009A384 000972E4  3B C3 00 00 */	addi r30, r3, 0
/* 8009A388 000972E8  7F C3 F3 79 */	or. r3, r30, r30
/* 8009A38C 000972EC  41 82 00 08 */	beq lbl_8009A394
/* 8009A390 000972F0  48 00 00 9D */	bl __ct__18PelletUfoLoadStateFv
lbl_8009A394:
/* 8009A394 000972F4  80 9F 00 08 */	lwz r4, 8(r31)
/* 8009A398 000972F8  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8009A39C 000972FC  7C 04 00 00 */	cmpw r4, r0
/* 8009A3A0 00097300  40 80 00 74 */	bge lbl_8009A414
/* 8009A3A4 00097304  80 7F 00 04 */	lwz r3, 4(r31)
/* 8009A3A8 00097308  54 80 10 3A */	slwi r0, r4, 2
/* 8009A3AC 0009730C  7F C3 01 2E */	stwx r30, r3, r0
/* 8009A3B0 00097310  80 7E 00 04 */	lwz r3, 4(r30)

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 801B03F4 001AD354  48 06 39 DD */	bl GXSetZMode
/* 801B03F8 001AD358  80 01 00 7C */	lwz r0, 0x7c(r1)
/* 801B03FC 001AD35C  83 E1 00 74 */	lwz r31, 0x74(r1)
/* 801B0400 001AD360  38 21 00 78 */	addi r1, r1, 0x78
/* 801B0404 001AD364  7C 08 03 A6 */	mtlr r0
/* 801B0408 001AD368  4E 80 00 20 */	blr 

.global setLookat__13P2DPerspGraphFv
setLookat__13P2DPerspGraphFv:
/* 801B040C 001AD36C  7C 08 02 A6 */	mflr r0
/* 801B0410 001AD370  90 01 00 04 */	stw r0, 4(r1)
/* 801B0414 001AD374  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 801B0418 001AD378  93 E1 00 24 */	stw r31, 0x24(r1)
/* 801B041C 001AD37C  7C 7F 1B 78 */	mr r31, r3
/* 801B0420 001AD380  C0 42 B6 98 */	lfs f2, lbl_803EB898@sda21(r2)
/* 801B0424 001AD384  C0 23 00 D4 */	lfs f1, 0xd4(r3)
/* 801B0428 001AD388  C0 02 B6 9C */	lfs f0, lbl_803EB89C@sda21(r2)
/* 801B042C 001AD38C  EC 22 00 72 */	fmuls f1, f2, f1
/* 801B0430 001AD390  EC 21 00 24 */	fdivs f1, f1, f0
/* 801B0434 001AD394  48 06 B6 9D */	bl tanf
/* 801B0438 001AD398  A8 BF 00 0E */	lha r5, 0xe(r31)
/* 801B043C 001AD39C  3C 80 43 30 */	lis r4, 0x4330
/* 801B0440 001AD3A0  A8 1F 00 0A */	lha r0, 0xa(r31)
/* 801B0444 001AD3A4  38 7F 00 00 */	addi r3, r31, 0
/* 801B0448 001AD3A8  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 801B044C 001AD3AC  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 801B0450 001AD3B0  90 A1 00 1C */	stw r5, 0x1c(r1)
/* 801B0454 001AD3B4  C8 82 B6 88 */	lfd f4, "@612"@sda21(r2)
/* 801B0458 001AD3B8  90 01 00 14 */	stw r0, 0x14(r1)
/* 801B045C 001AD3BC  C0 02 B6 94 */	lfs f0, lbl_803EB894@sda21(r2)
/* 801B0460 001AD3C0  90 81 00 18 */	stw r4, 0x18(r1)
/* 801B0464 001AD3C4  90 81 00 10 */	stw r4, 0x10(r1)
/* 801B0468 001AD3C8  C8 61 00 18 */	lfd f3, 0x18(r1)
/* 801B046C 001AD3CC  C8 41 00 10 */	lfd f2, 0x10(r1)
/* 801B0470 001AD3D0  EC 63 20 28 */	fsubs f3, f3, f4
/* 801B0474 001AD3D4  EC 42 20 28 */	fsubs f2, f2, f4
/* 801B0478 001AD3D8  EC 43 10 28 */	fsubs f2, f3, f2
/* 801B047C 001AD3DC  EC 02 00 32 */	fmuls f0, f2, f0
/* 801B0480 001AD3E0  EC 00 08 24 */	fdivs f0, f0, f1
/* 801B0484 001AD3E4  D0 1F 00 E0 */	stfs f0, 0xe0(r31)
/* 801B0488 001AD3E8  48 00 00 19 */	bl makeLookat__13P2DPerspGraphFv
/* 801B048C 001AD3EC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 801B0490 001AD3F0  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 801B0494 001AD3F4  38 21 00 28 */	addi r1, r1, 0x28
/* 801B0498 001AD3F8  7C 08 03 A6 */	mtlr r0
/* 801B049C 001AD3FC  4E 80 00 20 */	blr 

.global makeLookat__13P2DPerspGraphFv
makeLookat__13P2DPerspGraphFv:
/* 801B04A0 001AD400  7C 08 02 A6 */	mflr r0
/* 801B04A4 001AD404  3C C0 43 30 */	lis r6, 0x4330
/* 801B04A8 001AD408  90 01 00 04 */	stw r0, 4(r1)
/* 801B04AC 001AD40C  94 21 FF 40 */	stwu r1, -0xc0(r1)
/* 801B04B0 001AD410  DB E1 00 B8 */	stfd f31, 0xb8(r1)
/* 801B04B4 001AD414  DB C1 00 B0 */	stfd f30, 0xb0(r1)
/* 801B04B8 001AD418  93 E1 00 AC */	stw r31, 0xac(r1)
/* 801B04BC 001AD41C  7C 7F 1B 78 */	mr r31, r3
/* 801B04C0 001AD420  A8 63 00 0C */	lha r3, 0xc(r3)
/* 801B04C4 001AD424  A8 1F 00 08 */	lha r0, 8(r31)
/* 801B04C8 001AD428  6C 65 80 00 */	xoris r5, r3, 0x8000
/* 801B04CC 001AD42C  A8 7F 00 0E */	lha r3, 0xe(r31)
/* 801B04D0 001AD430  6C 04 80 00 */	xoris r4, r0, 0x8000
/* 801B04D4 001AD434  90 A1 00 A4 */	stw r5, 0xa4(r1)
/* 801B04D8 001AD438  A8 1F 00 0A */	lha r0, 0xa(r31)
/* 801B04DC 001AD43C  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 801B04E0 001AD440  90 81 00 9C */	stw r4, 0x9c(r1)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x67616d65
  .4byte 0x45786974
  .4byte 0x2e637070
  .4byte 0
  .4byte 0x47616d65
  .4byte 0x45786974
  .4byte 0
  .4byte 0x47616d65
  .4byte 0x45786974
  .4byte 0x53656374
  .4byte 0x696f6e00
  .4byte 0x436f7265
  .4byte 0x4e6f6465
  .4byte 0
  .4byte 0x803ddcd4
  .4byte 0
  .4byte 0
  .4byte 0x803ddcd4
  .4byte 0
  .4byte 0x803ddcdc
  .4byte 0
  .4byte 0
  .4byte 0x803ddcd4
  .4byte 0
  .4byte 0x803ddcdc
  .4byte 0
  .4byte 0x803ddcec
  .4byte 0
  .4byte 0
  .4byte 0x803ddcd4
  .4byte 0
  .4byte 0x803ddcdc
  .4byte 0
  .4byte 0x803ddcec
  .4byte 0
  .4byte 0x803ddcfc
  .4byte 0
  .4byte 0
.global __vt__15GameExitSection
__vt__15GameExitSection:
  .4byte __RTTI__15GameExitSection
  .4byte 0
  .4byte getAgeNodeType__5ANodeFv
  .4byte read__8CoreNodeFR18RandomAccessStream
  .4byte update__15GameExitSectionFv
  .4byte draw__4NodeFR8Graphics
  .4byte render__4NodeFR8Graphics
  .4byte concat__4NodeFv
  .4byte concat__4NodeFR3VQS
  .4byte concat__4NodeFR3SRT
  .4byte concat__4NodeFR8Matrix4f
  .4byte getModelMatrix__4NodeFv
  .4byte init__15GameExitSectionFv
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
  .4byte 0x696f6e00
  .4byte 0x803ddca4
  .4byte 0x802a8114
.global __RTTI__16IntroGameSection
__RTTI__16IntroGameSection:
  .4byte 0x802a8100
  .4byte 0x802a8130
  .4byte 0
.global lbl_803DDCC0
lbl_803DDCC0:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DDCC8
lbl_803DDCC8:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDCCC
	.4byte 0x00000000
	.4byte 0x802A81EC
	.4byte 0x802A81F8
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DDCE4
	.4byte 0x802A8204
	.4byte 0x53656374
