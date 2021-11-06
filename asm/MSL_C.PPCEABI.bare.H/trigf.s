.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global tanf
tanf:
/* 8021BAD0 00218A30  7C 08 02 A6 */	mflr r0
/* 8021BAD4 00218A34  90 01 00 04 */	stw r0, 4(r1)
/* 8021BAD8 00218A38  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8021BADC 00218A3C  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 8021BAE0 00218A40  DB C1 00 10 */	stfd f30, 0x10(r1)
/* 8021BAE4 00218A44  FF C0 08 90 */	fmr f30, f1
/* 8021BAE8 00218A48  48 00 00 2D */	bl cos__Ff
/* 8021BAEC 00218A4C  FF E0 08 90 */	fmr f31, f1
/* 8021BAF0 00218A50  FC 20 F0 90 */	fmr f1, f30
/* 8021BAF4 00218A54  48 00 00 41 */	bl sin__Ff
/* 8021BAF8 00218A58  EC 21 F8 24 */	fdivs f1, f1, f31
/* 8021BAFC 00218A5C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8021BB00 00218A60  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 8021BB04 00218A64  CB C1 00 10 */	lfd f30, 0x10(r1)
/* 8021BB08 00218A68  7C 08 03 A6 */	mtlr r0
/* 8021BB0C 00218A6C  38 21 00 20 */	addi r1, r1, 0x20
/* 8021BB10 00218A70  4E 80 00 20 */	blr 

.global cos__Ff
cos__Ff:
/* 8021BB14 00218A74  7C 08 02 A6 */	mflr r0
/* 8021BB18 00218A78  90 01 00 04 */	stw r0, 4(r1)
/* 8021BB1C 00218A7C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021BB20 00218A80  48 00 00 35 */	bl cosf
/* 8021BB24 00218A84  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021BB28 00218A88  38 21 00 08 */	addi r1, r1, 8
/* 8021BB2C 00218A8C  7C 08 03 A6 */	mtlr r0
/* 8021BB30 00218A90  4E 80 00 20 */	blr 

.global sin__Ff
sin__Ff:
/* 8021BB34 00218A94  7C 08 02 A6 */	mflr r0
/* 8021BB38 00218A98  90 01 00 04 */	stw r0, 4(r1)
/* 8021BB3C 00218A9C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021BB40 00218AA0  48 00 01 A9 */	bl sinf
/* 8021BB44 00218AA4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021BB48 00218AA8  38 21 00 08 */	addi r1, r1, 8
/* 8021BB4C 00218AAC  7C 08 03 A6 */	mtlr r0
/* 8021BB50 00218AB0  4E 80 00 20 */	blr 

.global cosf
cosf:
/* 8021BB54 00218AB4  7C 08 02 A6 */	mflr r0
/* 8021BB58 00218AB8  3C 60 80 2F */	lis r3, __four_over_pi_m1@ha
/* 8021BB5C 00218ABC  90 01 00 04 */	stw r0, 4(r1)
/* 8021BB60 00218AC0  38 63 94 B0 */	addi r3, r3, __four_over_pi_m1@l
/* 8021BB64 00218AC4  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8021BB68 00218AC8  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 8021BB6C 00218ACC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8021BB70 00218AD0  D0 21 00 08 */	stfs f1, 8(r1)
/* 8021BB74 00218AD4  C0 02 C6 10 */	lfs f0, lbl_803EC810@sda21(r2)
/* 8021BB78 00218AD8  80 01 00 08 */	lwz r0, 8(r1)
/* 8021BB7C 00218ADC  C0 C1 00 08 */	lfs f6, 8(r1)
/* 8021BB80 00218AE0  54 00 00 01 */	rlwinm. r0, r0, 0, 0, 0
/* 8021BB84 00218AE4  EC 20 01 B2 */	fmuls f1, f0, f6
/* 8021BB88 00218AE8  41 82 00 1C */	beq lbl_8021BBA4
/* 8021BB8C 00218AEC  C0 02 C6 14 */	lfs f0, lbl_803EC814@sda21(r2)
/* 8021BB90 00218AF0  EC 01 00 28 */	fsubs f0, f1, f0
/* 8021BB94 00218AF4  FC 00 00 1E */	fctiwz f0, f0
/* 8021BB98 00218AF8  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 8021BB9C 00218AFC  80 81 00 14 */	lwz r4, 0x14(r1)
/* 8021BBA0 00218B00  48 00 00 18 */	b lbl_8021BBB8
lbl_8021BBA4:
/* 8021BBA4 00218B04  C0 02 C6 14 */	lfs f0, lbl_803EC814@sda21(r2)
/* 8021BBA8 00218B08  EC 00 08 2A */	fadds f0, f0, f1
/* 8021BBAC 00218B0C  FC 00 00 1E */	fctiwz f0, f0
/* 8021BBB0 00218B10  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 8021BBB4 00218B14  80 81 00 14 */	lwz r4, 0x14(r1)
lbl_8021BBB8:
/* 8021BBB8 00218B18  54 80 08 3C */	slwi r0, r4, 1
/* 8021BBBC 00218B1C  C8 22 C6 20 */	lfd f1, "@110_1"@sda21(r2)
/* 8021BBC0 00218B20  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8021BBC4 00218B24  C0 43 00 00 */	lfs f2, 0(r3)
/* 8021BBC8 00218B28  90 01 00 14 */	stw r0, 0x14(r1)
/* 8021BBCC 00218B2C  3C 00 43 30 */	lis r0, 0x4330
/* 8021BBD0 00218B30  C0 63 00 04 */	lfs f3, 4(r3)
/* 8021BBD4 00218B34  54 9F 07 BE */	clrlwi r31, r4, 0x1e
/* 8021BBD8 00218B38  90 01 00 10 */	stw r0, 0x10(r1)
/* 8021BBDC 00218B3C  C0 83 00 08 */	lfs f4, 8(r3)
/* 8021BBE0 00218B40  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8021BBE4 00218B44  C0 A3 00 0C */	lfs f5, 0xc(r3)
/* 8021BBE8 00218B48  EC 00 08 28 */	fsubs f0, f0, f1
/* 8021BBEC 00218B4C  EC 06 00 28 */	fsubs f0, f6, f0
/* 8021BBF0 00218B50  EC 02 01 BA */	fmadds f0, f2, f6, f0
/* 8021BBF4 00218B54  EC 03 01 BA */	fmadds f0, f3, f6, f0
/* 8021BBF8 00218B58  EC 04 01 BA */	fmadds f0, f4, f6, f0
/* 8021BBFC 00218B5C  EF E5 01 BA */	fmadds f31, f5, f6, f0
/* 8021BC00 00218B60  FC 20 F8 90 */	fmr f1, f31
/* 8021BC04 00218B64  4B FF FB 25 */	bl fabsf__Ff
/* 8021BC08 00218B68  C0 02 C6 18 */	lfs f0, lbl_803EC818@sda21(r2)
/* 8021BC0C 00218B6C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8021BC10 00218B70  40 80 00 24 */	bge lbl_8021BC34
/* 8021BC14 00218B74  3C 60 80 22 */	lis r3, __sincos_on_quadrant@ha
/* 8021BC18 00218B78  57 E4 18 38 */	slwi r4, r31, 3
/* 8021BC1C 00218B7C  38 03 2D 08 */	addi r0, r3, __sincos_on_quadrant@l
/* 8021BC20 00218B80  7C 60 22 14 */	add r3, r0, r4
/* 8021BC24 00218B84  C0 23 00 00 */	lfs f1, 0(r3)
/* 8021BC28 00218B88  C0 03 00 04 */	lfs f0, 4(r3)
/* 8021BC2C 00218B8C  EC 3F 00 7C */	fnmsubs f1, f31, f1, f0
/* 8021BC30 00218B90  48 00 00 A0 */	b lbl_8021BCD0
lbl_8021BC34:
/* 8021BC34 00218B94  57 E0 07 FF */	clrlwi. r0, r31, 0x1f
/* 8021BC38 00218B98  EC 9F 07 F2 */	fmuls f4, f31, f31
/* 8021BC3C 00218B9C  41 82 00 50 */	beq lbl_8021BC8C
/* 8021BC40 00218BA0  3C 60 80 22 */	lis r3, __sincos_poly@ha
/* 8021BC44 00218BA4  38 83 2D 28 */	addi r4, r3, __sincos_poly@l
/* 8021BC48 00218BA8  C0 44 00 04 */	lfs f2, 4(r4)
/* 8021BC4C 00218BAC  3C 60 80 22 */	lis r3, __sincos_on_quadrant@ha
/* 8021BC50 00218BB0  C0 24 00 0C */	lfs f1, 0xc(r4)
/* 8021BC54 00218BB4  38 03 2D 08 */	addi r0, r3, __sincos_on_quadrant@l
/* 8021BC58 00218BB8  C0 04 00 14 */	lfs f0, 0x14(r4)
/* 8021BC5C 00218BBC  EC 62 09 3A */	fmadds f3, f2, f4, f1
/* 8021BC60 00218BC0  C0 44 00 1C */	lfs f2, 0x1c(r4)
/* 8021BC64 00218BC4  C0 24 00 24 */	lfs f1, 0x24(r4)
/* 8021BC68 00218BC8  57 E4 18 38 */	slwi r4, r31, 3
/* 8021BC6C 00218BCC  7C 60 22 14 */	add r3, r0, r4
/* 8021BC70 00218BD0  EC 64 00 FA */	fmadds f3, f4, f3, f0
/* 8021BC74 00218BD4  C0 03 00 00 */	lfs f0, 0(r3)
/* 8021BC78 00218BD8  EC 44 10 FA */	fmadds f2, f4, f3, f2
/* 8021BC7C 00218BDC  EC 24 08 BE */	fnmadds f1, f4, f2, f1
/* 8021BC80 00218BE0  EC 3F 00 72 */	fmuls f1, f31, f1
/* 8021BC84 00218BE4  EC 21 00 32 */	fmuls f1, f1, f0
/* 8021BC88 00218BE8  48 00 00 48 */	b lbl_8021BCD0
lbl_8021BC8C:
/* 8021BC8C 00218BEC  3C 60 80 22 */	lis r3, __sincos_poly@ha
/* 8021BC90 00218BF0  38 83 2D 28 */	addi r4, r3, __sincos_poly@l
/* 8021BC94 00218BF4  C0 44 00 00 */	lfs f2, 0(r4)
/* 8021BC98 00218BF8  3C 60 80 22 */	lis r3, __sincos_on_quadrant@ha
/* 8021BC9C 00218BFC  C0 24 00 08 */	lfs f1, 8(r4)
/* 8021BCA0 00218C00  38 63 2D 08 */	addi r3, r3, __sincos_on_quadrant@l
/* 8021BCA4 00218C04  57 E0 18 38 */	slwi r0, r31, 3
/* 8021BCA8 00218C08  EC 62 09 3A */	fmadds f3, f2, f4, f1
/* 8021BCAC 00218C0C  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8021BCB0 00218C10  C0 44 00 18 */	lfs f2, 0x18(r4)
/* 8021BCB4 00218C14  7C 63 02 14 */	add r3, r3, r0
/* 8021BCB8 00218C18  C0 24 00 20 */	lfs f1, 0x20(r4)
/* 8021BCBC 00218C1C  EC 64 00 FA */	fmadds f3, f4, f3, f0
/* 8021BCC0 00218C20  C0 03 00 04 */	lfs f0, 4(r3)
/* 8021BCC4 00218C24  EC 44 10 FA */	fmadds f2, f4, f3, f2
/* 8021BCC8 00218C28  EC 24 08 BA */	fmadds f1, f4, f2, f1
/* 8021BCCC 00218C2C  EC 21 00 32 */	fmuls f1, f1, f0
lbl_8021BCD0:
/* 8021BCD0 00218C30  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8021BCD4 00218C34  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 8021BCD8 00218C38  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8021BCDC 00218C3C  7C 08 03 A6 */	mtlr r0
/* 8021BCE0 00218C40  38 21 00 28 */	addi r1, r1, 0x28
/* 8021BCE4 00218C44  4E 80 00 20 */	blr 

.global sinf
sinf:
/* 8021BCE8 00218C48  7C 08 02 A6 */	mflr r0
/* 8021BCEC 00218C4C  3C 60 80 2F */	lis r3, __four_over_pi_m1@ha
/* 8021BCF0 00218C50  90 01 00 04 */	stw r0, 4(r1)
/* 8021BCF4 00218C54  38 63 94 B0 */	addi r3, r3, __four_over_pi_m1@l
/* 8021BCF8 00218C58  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8021BCFC 00218C5C  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 8021BD00 00218C60  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8021BD04 00218C64  D0 21 00 08 */	stfs f1, 8(r1)
/* 8021BD08 00218C68  C0 02 C6 10 */	lfs f0, lbl_803EC810@sda21(r2)
/* 8021BD0C 00218C6C  80 01 00 08 */	lwz r0, 8(r1)
/* 8021BD10 00218C70  C0 C1 00 08 */	lfs f6, 8(r1)
/* 8021BD14 00218C74  54 00 00 01 */	rlwinm. r0, r0, 0, 0, 0
/* 8021BD18 00218C78  EC 20 01 B2 */	fmuls f1, f0, f6
/* 8021BD1C 00218C7C  41 82 00 1C */	beq lbl_8021BD38
/* 8021BD20 00218C80  C0 02 C6 14 */	lfs f0, lbl_803EC814@sda21(r2)
/* 8021BD24 00218C84  EC 01 00 28 */	fsubs f0, f1, f0
/* 8021BD28 00218C88  FC 00 00 1E */	fctiwz f0, f0
/* 8021BD2C 00218C8C  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 8021BD30 00218C90  80 81 00 14 */	lwz r4, 0x14(r1)
/* 8021BD34 00218C94  48 00 00 18 */	b lbl_8021BD4C
lbl_8021BD38:
/* 8021BD38 00218C98  C0 02 C6 14 */	lfs f0, lbl_803EC814@sda21(r2)
/* 8021BD3C 00218C9C  EC 00 08 2A */	fadds f0, f0, f1
/* 8021BD40 00218CA0  FC 00 00 1E */	fctiwz f0, f0
/* 8021BD44 00218CA4  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 8021BD48 00218CA8  80 81 00 14 */	lwz r4, 0x14(r1)
lbl_8021BD4C:
/* 8021BD4C 00218CAC  54 80 08 3C */	slwi r0, r4, 1
/* 8021BD50 00218CB0  C8 22 C6 20 */	lfd f1, "@110_1"@sda21(r2)
/* 8021BD54 00218CB4  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8021BD58 00218CB8  C0 43 00 00 */	lfs f2, 0(r3)
/* 8021BD5C 00218CBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8021BD60 00218CC0  3C 00 43 30 */	lis r0, 0x4330
/* 8021BD64 00218CC4  C0 63 00 04 */	lfs f3, 4(r3)
/* 8021BD68 00218CC8  54 9F 07 BE */	clrlwi r31, r4, 0x1e
/* 8021BD6C 00218CCC  90 01 00 10 */	stw r0, 0x10(r1)
/* 8021BD70 00218CD0  C0 83 00 08 */	lfs f4, 8(r3)
/* 8021BD74 00218CD4  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8021BD78 00218CD8  C0 A3 00 0C */	lfs f5, 0xc(r3)
/* 8021BD7C 00218CDC  EC 00 08 28 */	fsubs f0, f0, f1
/* 8021BD80 00218CE0  EC 06 00 28 */	fsubs f0, f6, f0
/* 8021BD84 00218CE4  EC 02 01 BA */	fmadds f0, f2, f6, f0
/* 8021BD88 00218CE8  EC 03 01 BA */	fmadds f0, f3, f6, f0
/* 8021BD8C 00218CEC  EC 04 01 BA */	fmadds f0, f4, f6, f0
/* 8021BD90 00218CF0  EF E5 01 BA */	fmadds f31, f5, f6, f0
/* 8021BD94 00218CF4  FC 20 F8 90 */	fmr f1, f31
/* 8021BD98 00218CF8  4B FF F9 91 */	bl fabsf__Ff
/* 8021BD9C 00218CFC  C0 02 C6 18 */	lfs f0, lbl_803EC818@sda21(r2)
/* 8021BDA0 00218D00  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8021BDA4 00218D04  40 80 00 34 */	bge lbl_8021BDD8
/* 8021BDA8 00218D08  3C 60 80 22 */	lis r3, __sincos_on_quadrant@ha
/* 8021BDAC 00218D0C  57 E4 18 38 */	slwi r4, r31, 3
/* 8021BDB0 00218D10  38 03 2D 08 */	addi r0, r3, __sincos_on_quadrant@l
/* 8021BDB4 00218D14  7C 60 22 14 */	add r3, r0, r4
/* 8021BDB8 00218D18  C0 23 00 04 */	lfs f1, 4(r3)
/* 8021BDBC 00218D1C  3C 80 80 22 */	lis r4, __sincos_poly@ha
/* 8021BDC0 00218D20  38 84 2D 28 */	addi r4, r4, __sincos_poly@l
/* 8021BDC4 00218D24  C0 03 00 00 */	lfs f0, 0(r3)
/* 8021BDC8 00218D28  EC 3F 00 72 */	fmuls f1, f31, f1
/* 8021BDCC 00218D2C  C0 44 00 24 */	lfs f2, 0x24(r4)
/* 8021BDD0 00218D30  EC 22 00 7A */	fmadds f1, f2, f1, f0
/* 8021BDD4 00218D34  48 00 00 A0 */	b lbl_8021BE74
lbl_8021BDD8:
/* 8021BDD8 00218D38  57 E0 07 FF */	clrlwi. r0, r31, 0x1f
/* 8021BDDC 00218D3C  EC 9F 07 F2 */	fmuls f4, f31, f31
/* 8021BDE0 00218D40  41 82 00 4C */	beq lbl_8021BE2C
/* 8021BDE4 00218D44  3C 60 80 22 */	lis r3, __sincos_poly@ha
/* 8021BDE8 00218D48  38 83 2D 28 */	addi r4, r3, __sincos_poly@l
/* 8021BDEC 00218D4C  C0 44 00 00 */	lfs f2, 0(r4)
/* 8021BDF0 00218D50  3C 60 80 22 */	lis r3, __sincos_on_quadrant@ha
/* 8021BDF4 00218D54  C0 24 00 08 */	lfs f1, 8(r4)
/* 8021BDF8 00218D58  38 03 2D 08 */	addi r0, r3, __sincos_on_quadrant@l
/* 8021BDFC 00218D5C  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8021BE00 00218D60  EC 62 09 3A */	fmadds f3, f2, f4, f1
/* 8021BE04 00218D64  C0 44 00 18 */	lfs f2, 0x18(r4)
/* 8021BE08 00218D68  C0 24 00 20 */	lfs f1, 0x20(r4)
/* 8021BE0C 00218D6C  57 E4 18 38 */	slwi r4, r31, 3
/* 8021BE10 00218D70  7C 60 22 14 */	add r3, r0, r4
/* 8021BE14 00218D74  EC 64 00 FA */	fmadds f3, f4, f3, f0
/* 8021BE18 00218D78  C0 03 00 00 */	lfs f0, 0(r3)
/* 8021BE1C 00218D7C  EC 44 10 FA */	fmadds f2, f4, f3, f2
/* 8021BE20 00218D80  EC 24 08 BA */	fmadds f1, f4, f2, f1
/* 8021BE24 00218D84  EC 21 00 32 */	fmuls f1, f1, f0
/* 8021BE28 00218D88  48 00 00 4C */	b lbl_8021BE74
lbl_8021BE2C:
/* 8021BE2C 00218D8C  3C 60 80 22 */	lis r3, __sincos_poly@ha
/* 8021BE30 00218D90  38 83 2D 28 */	addi r4, r3, __sincos_poly@l
/* 8021BE34 00218D94  C0 44 00 04 */	lfs f2, 4(r4)
/* 8021BE38 00218D98  3C 60 80 22 */	lis r3, __sincos_on_quadrant@ha
/* 8021BE3C 00218D9C  C0 24 00 0C */	lfs f1, 0xc(r4)
/* 8021BE40 00218DA0  38 63 2D 08 */	addi r3, r3, __sincos_on_quadrant@l
/* 8021BE44 00218DA4  57 E0 18 38 */	slwi r0, r31, 3
/* 8021BE48 00218DA8  EC 62 09 3A */	fmadds f3, f2, f4, f1
/* 8021BE4C 00218DAC  C0 04 00 14 */	lfs f0, 0x14(r4)
/* 8021BE50 00218DB0  C0 44 00 1C */	lfs f2, 0x1c(r4)
/* 8021BE54 00218DB4  7C 63 02 14 */	add r3, r3, r0
/* 8021BE58 00218DB8  C0 24 00 24 */	lfs f1, 0x24(r4)
/* 8021BE5C 00218DBC  EC 64 00 FA */	fmadds f3, f4, f3, f0
/* 8021BE60 00218DC0  C0 03 00 04 */	lfs f0, 4(r3)
/* 8021BE64 00218DC4  EC 44 10 FA */	fmadds f2, f4, f3, f2
/* 8021BE68 00218DC8  EC 24 08 BA */	fmadds f1, f4, f2, f1
/* 8021BE6C 00218DCC  EC 3F 00 72 */	fmuls f1, f31, f1
/* 8021BE70 00218DD0  EC 21 00 32 */	fmuls f1, f1, f0
lbl_8021BE74:
/* 8021BE74 00218DD4  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8021BE78 00218DD8  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 8021BE7C 00218DDC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8021BE80 00218DE0  7C 08 03 A6 */	mtlr r0
/* 8021BE84 00218DE4  38 21 00 28 */	addi r1, r1, 0x28
/* 8021BE88 00218DE8  4E 80 00 20 */	blr 

.global __sinit_trigf_c
__sinit_trigf_c:
/* 8021BE8C 00218DEC  3C 60 80 22 */	lis r3, tmp_float@ha
/* 8021BE90 00218DF0  38 83 2C F8 */	addi r4, r3, tmp_float@l
/* 8021BE94 00218DF4  C0 04 00 00 */	lfs f0, 0(r4)
/* 8021BE98 00218DF8  3C 60 80 2F */	lis r3, __four_over_pi_m1@ha
/* 8021BE9C 00218DFC  D4 03 94 B0 */	stfsu f0, __four_over_pi_m1@l(r3)
/* 8021BEA0 00218E00  C0 04 00 04 */	lfs f0, 4(r4)
/* 8021BEA4 00218E04  D0 03 00 04 */	stfs f0, 4(r3)
/* 8021BEA8 00218E08  C0 04 00 08 */	lfs f0, 8(r4)
/* 8021BEAC 00218E0C  D0 03 00 08 */	stfs f0, 8(r3)
/* 8021BEB0 00218E10  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 8021BEB4 00218E14  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 8021BEB8 00218E18  4E 80 00 20 */	blr 

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.balign 0x8
.global tmp_float
tmp_float:
	.4byte 0x3E800000
	.4byte 0x3CBE6080
	.4byte 0x34372200
	.4byte 0x2DA44152

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 0x8
.global __four_over_pi_m1
__four_over_pi_m1:
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 0x8
.global lbl_803EC810
lbl_803EC810:
	.4byte 0x3F22F983
.global lbl_803EC814
lbl_803EC814:
	.4byte 0x3F000000
.global lbl_803EC818
lbl_803EC818:
	.4byte 0x39B504F3
	.4byte 0x00000000
.global "@110_1"
"@110_1":
	.4byte 0x43300000
	.4byte 0x80000000
