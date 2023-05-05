.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__10TAIAmotionFii, global
/* 801ACC54 001A9BB4  3C C0 80 2C */	lis r6, __vt__9TaiAction@ha
/* 801ACC58 001A9BB8  38 06 66 20 */	addi r0, r6, __vt__9TaiAction@l
/* 801ACC5C 001A9BBC  90 03 00 04 */	stw r0, 4(r3)
/* 801ACC60 001A9BC0  3C C0 80 2E */	lis r6, __vt__10TAIAmotion@ha
/* 801ACC64 001A9BC4  38 06 FC E4 */	addi r0, r6, __vt__10TAIAmotion@l
/* 801ACC68 001A9BC8  90 83 00 00 */	stw r4, 0(r3)
/* 801ACC6C 001A9BCC  90 03 00 04 */	stw r0, 4(r3)
/* 801ACC70 001A9BD0  90 A3 00 08 */	stw r5, 8(r3)
/* 801ACC74 001A9BD4  4E 80 00 20 */	blr 
.endfn __ct__10TAIAmotionFii

.fn start__10TAIAmotionFR4Teki, global
/* 801ACC78 001A9BD8  7C 08 02 A6 */	mflr r0
/* 801ACC7C 001A9BDC  90 01 00 04 */	stw r0, 4(r1)
/* 801ACC80 001A9BE0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801ACC84 001A9BE4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801ACC88 001A9BE8  7C 9F 23 79 */	or. r31, r4, r4
/* 801ACC8C 001A9BEC  38 BF 00 00 */	addi r5, r31, 0
/* 801ACC90 001A9BF0  41 82 00 08 */	beq .L_801ACC98
/* 801ACC94 001A9BF4  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
.L_801ACC98:
/* 801ACC98 001A9BF8  80 83 00 08 */	lwz r4, 8(r3)
/* 801ACC9C 001A9BFC  38 61 00 10 */	addi r3, r1, 0x10
/* 801ACCA0 001A9C00  4B F7 22 ED */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801ACCA4 001A9C04  7C 64 1B 78 */	mr r4, r3
/* 801ACCA8 001A9C08  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACCAC 001A9C0C  4B F7 25 15 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 801ACCB0 001A9C10  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801ACCB4 001A9C14  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801ACCB8 001A9C18  38 21 00 20 */	addi r1, r1, 0x20
/* 801ACCBC 001A9C1C  7C 08 03 A6 */	mtlr r0
/* 801ACCC0 001A9C20  4E 80 00 20 */	blr 
.endfn start__10TAIAmotionFR4Teki

.fn act__10TAIAmotionFR4Teki, global
/* 801ACCC4 001A9C24  80 04 03 A8 */	lwz r0, 0x3a8(r4)
/* 801ACCC8 001A9C28  2C 00 00 00 */	cmpwi r0, 0
/* 801ACCCC 001A9C2C  40 82 00 0C */	bne .L_801ACCD8
/* 801ACCD0 001A9C30  38 60 00 01 */	li r3, 1
/* 801ACCD4 001A9C34  4E 80 00 20 */	blr 
.L_801ACCD8:
/* 801ACCD8 001A9C38  38 60 00 00 */	li r3, 0
/* 801ACCDC 001A9C3C  4E 80 00 20 */	blr 
.endfn act__10TAIAmotionFR4Teki

.fn __ct__17TAIAreserveMotionFii, global
/* 801ACCE0 001A9C40  3C C0 80 2C */	lis r6, __vt__9TaiAction@ha
/* 801ACCE4 001A9C44  38 06 66 20 */	addi r0, r6, __vt__9TaiAction@l
/* 801ACCE8 001A9C48  90 03 00 04 */	stw r0, 4(r3)
/* 801ACCEC 001A9C4C  3C C0 80 2E */	lis r6, __vt__17TAIAreserveMotion@ha
/* 801ACCF0 001A9C50  38 06 FC BC */	addi r0, r6, __vt__17TAIAreserveMotion@l
/* 801ACCF4 001A9C54  90 83 00 00 */	stw r4, 0(r3)
/* 801ACCF8 001A9C58  90 03 00 04 */	stw r0, 4(r3)
/* 801ACCFC 001A9C5C  90 A3 00 08 */	stw r5, 8(r3)
/* 801ACD00 001A9C60  4E 80 00 20 */	blr 
.endfn __ct__17TAIAreserveMotionFii

.fn start__17TAIAreserveMotionFR4Teki, global
/* 801ACD04 001A9C64  7C 08 02 A6 */	mflr r0
/* 801ACD08 001A9C68  90 01 00 04 */	stw r0, 4(r1)
/* 801ACD0C 001A9C6C  94 21 FF 88 */	stwu r1, -0x78(r1)
/* 801ACD10 001A9C70  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 801ACD14 001A9C74  93 E1 00 6C */	stw r31, 0x6c(r1)
/* 801ACD18 001A9C78  7C 9F 23 78 */	mr r31, r4
/* 801ACD1C 001A9C7C  93 C1 00 68 */	stw r30, 0x68(r1)
/* 801ACD20 001A9C80  7C 7E 1B 78 */	mr r30, r3
/* 801ACD24 001A9C84  80 A4 02 CC */	lwz r5, 0x2cc(r4)
/* 801ACD28 001A9C88  80 83 00 08 */	lwz r4, 8(r3)
/* 801ACD2C 001A9C8C  80 05 00 44 */	lwz r0, 0x44(r5)
/* 801ACD30 001A9C90  7C 04 00 00 */	cmpw r4, r0
/* 801ACD34 001A9C94  41 82 00 C4 */	beq .L_801ACDF8
/* 801ACD38 001A9C98  2C 00 00 00 */	cmpwi r0, 0
/* 801ACD3C 001A9C9C  40 80 00 2C */	bge .L_801ACD68
/* 801ACD40 001A9CA0  28 1F 00 00 */	cmplwi r31, 0
/* 801ACD44 001A9CA4  38 BF 00 00 */	addi r5, r31, 0
/* 801ACD48 001A9CA8  41 82 00 08 */	beq .L_801ACD50
/* 801ACD4C 001A9CAC  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
.L_801ACD50:
/* 801ACD50 001A9CB0  38 61 00 54 */	addi r3, r1, 0x54
/* 801ACD54 001A9CB4  4B F7 22 39 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801ACD58 001A9CB8  7C 64 1B 78 */	mr r4, r3
/* 801ACD5C 001A9CBC  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACD60 001A9CC0  4B F7 24 61 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 801ACD64 001A9CC4  48 00 01 38 */	b .L_801ACE9C
.L_801ACD68:
/* 801ACD68 001A9CC8  80 65 00 28 */	lwz r3, 0x28(r5)
/* 801ACD6C 001A9CCC  3C 00 43 30 */	lis r0, 0x4330
/* 801ACD70 001A9CD0  C8 22 B6 10 */	lfd f1, lbl_803EB810@sda21(r2)
/* 801ACD74 001A9CD4  80 63 00 68 */	lwz r3, 0x68(r3)
/* 801ACD78 001A9CD8  C0 45 00 2C */	lfs f2, 0x2c(r5)
/* 801ACD7C 001A9CDC  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801ACD80 001A9CE0  38 63 FF FE */	addi r3, r3, -2
/* 801ACD84 001A9CE4  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 801ACD88 001A9CE8  90 61 00 64 */	stw r3, 0x64(r1)
/* 801ACD8C 001A9CEC  90 01 00 60 */	stw r0, 0x60(r1)
/* 801ACD90 001A9CF0  C8 01 00 60 */	lfd f0, 0x60(r1)
/* 801ACD94 001A9CF4  EC 00 08 28 */	fsubs f0, f0, f1
/* 801ACD98 001A9CF8  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 801ACD9C 001A9CFC  4C 41 13 82 */	cror 2, 1, 2
/* 801ACDA0 001A9D00  40 82 00 2C */	bne .L_801ACDCC
/* 801ACDA4 001A9D04  28 1F 00 00 */	cmplwi r31, 0
/* 801ACDA8 001A9D08  38 BF 00 00 */	addi r5, r31, 0
/* 801ACDAC 001A9D0C  41 82 00 08 */	beq .L_801ACDB4
/* 801ACDB0 001A9D10  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
.L_801ACDB4:
/* 801ACDB4 001A9D14  38 61 00 4C */	addi r3, r1, 0x4c
/* 801ACDB8 001A9D18  4B F7 21 D5 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801ACDBC 001A9D1C  7C 64 1B 78 */	mr r4, r3
/* 801ACDC0 001A9D20  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACDC4 001A9D24  4B F7 23 FD */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 801ACDC8 001A9D28  48 00 00 D4 */	b .L_801ACE9C
.L_801ACDCC:
/* 801ACDCC 001A9D2C  28 1F 00 00 */	cmplwi r31, 0
/* 801ACDD0 001A9D30  38 BF 00 00 */	addi r5, r31, 0
/* 801ACDD4 001A9D34  41 82 00 08 */	beq .L_801ACDDC
/* 801ACDD8 001A9D38  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
.L_801ACDDC:
/* 801ACDDC 001A9D3C  38 61 00 44 */	addi r3, r1, 0x44
/* 801ACDE0 001A9D40  38 80 FF FF */	li r4, -1
/* 801ACDE4 001A9D44  4B F7 21 A9 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801ACDE8 001A9D48  7C 64 1B 78 */	mr r4, r3
/* 801ACDEC 001A9D4C  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACDF0 001A9D50  4B F7 24 41 */	bl finishMotion__12PaniAnimatorFR14PaniMotionInfo
/* 801ACDF4 001A9D54  48 00 00 A8 */	b .L_801ACE9C
.L_801ACDF8:
/* 801ACDF8 001A9D58  80 65 00 28 */	lwz r3, 0x28(r5)
/* 801ACDFC 001A9D5C  3C 00 43 30 */	lis r0, 0x4330
/* 801ACE00 001A9D60  C8 22 B6 10 */	lfd f1, lbl_803EB810@sda21(r2)
/* 801ACE04 001A9D64  80 63 00 68 */	lwz r3, 0x68(r3)
/* 801ACE08 001A9D68  C0 45 00 2C */	lfs f2, 0x2c(r5)
/* 801ACE0C 001A9D6C  80 63 00 30 */	lwz r3, 0x30(r3)
/* 801ACE10 001A9D70  38 63 FF FE */	addi r3, r3, -2
/* 801ACE14 001A9D74  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 801ACE18 001A9D78  90 61 00 64 */	stw r3, 0x64(r1)
/* 801ACE1C 001A9D7C  90 01 00 60 */	stw r0, 0x60(r1)
/* 801ACE20 001A9D80  C8 01 00 60 */	lfd f0, 0x60(r1)
/* 801ACE24 001A9D84  EC 00 08 28 */	fsubs f0, f0, f1
/* 801ACE28 001A9D88  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 801ACE2C 001A9D8C  4C 41 13 82 */	cror 2, 1, 2
/* 801ACE30 001A9D90  40 82 00 28 */	bne .L_801ACE58
/* 801ACE34 001A9D94  28 1F 00 00 */	cmplwi r31, 0
/* 801ACE38 001A9D98  38 BF 00 00 */	addi r5, r31, 0
/* 801ACE3C 001A9D9C  41 82 00 08 */	beq .L_801ACE44
/* 801ACE40 001A9DA0  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
.L_801ACE44:
/* 801ACE44 001A9DA4  38 61 00 3C */	addi r3, r1, 0x3c
/* 801ACE48 001A9DA8  4B F7 21 45 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801ACE4C 001A9DAC  7C 64 1B 78 */	mr r4, r3
/* 801ACE50 001A9DB0  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACE54 001A9DB4  4B F7 23 6D */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
.L_801ACE58:
/* 801ACE58 001A9DB8  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACE5C 001A9DBC  88 03 00 48 */	lbz r0, 0x48(r3)
/* 801ACE60 001A9DC0  28 00 00 00 */	cmplwi r0, 0
/* 801ACE64 001A9DC4  41 82 00 38 */	beq .L_801ACE9C
/* 801ACE68 001A9DC8  28 1F 00 00 */	cmplwi r31, 0
/* 801ACE6C 001A9DCC  C3 E3 00 2C */	lfs f31, 0x2c(r3)
/* 801ACE70 001A9DD0  7F E5 FB 78 */	mr r5, r31
/* 801ACE74 001A9DD4  41 82 00 08 */	beq .L_801ACE7C
/* 801ACE78 001A9DD8  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
.L_801ACE7C:
/* 801ACE7C 001A9DDC  80 9E 00 08 */	lwz r4, 8(r30)
/* 801ACE80 001A9DE0  38 61 00 34 */	addi r3, r1, 0x34
/* 801ACE84 001A9DE4  4B F7 21 09 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801ACE88 001A9DE8  7C 64 1B 78 */	mr r4, r3
/* 801ACE8C 001A9DEC  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACE90 001A9DF0  4B F7 23 31 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 801ACE94 001A9DF4  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACE98 001A9DF8  D3 E3 00 2C */	stfs f31, 0x2c(r3)
.L_801ACE9C:
/* 801ACE9C 001A9DFC  80 01 00 7C */	lwz r0, 0x7c(r1)
/* 801ACEA0 001A9E00  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 801ACEA4 001A9E04  83 E1 00 6C */	lwz r31, 0x6c(r1)
/* 801ACEA8 001A9E08  83 C1 00 68 */	lwz r30, 0x68(r1)
/* 801ACEAC 001A9E0C  38 21 00 78 */	addi r1, r1, 0x78
/* 801ACEB0 001A9E10  7C 08 03 A6 */	mtlr r0
/* 801ACEB4 001A9E14  4E 80 00 20 */	blr 
.endfn start__17TAIAreserveMotionFR4Teki

.fn act__17TAIAreserveMotionFR4Teki, global
/* 801ACEB8 001A9E18  7C 08 02 A6 */	mflr r0
/* 801ACEBC 001A9E1C  90 01 00 04 */	stw r0, 4(r1)
/* 801ACEC0 001A9E20  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 801ACEC4 001A9E24  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 801ACEC8 001A9E28  7C 9F 23 78 */	mr r31, r4
/* 801ACECC 001A9E2C  80 83 00 08 */	lwz r4, 8(r3)
/* 801ACED0 001A9E30  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACED4 001A9E34  80 03 00 44 */	lwz r0, 0x44(r3)
/* 801ACED8 001A9E38  7C 04 00 00 */	cmpw r4, r0
/* 801ACEDC 001A9E3C  41 82 00 4C */	beq .L_801ACF28
/* 801ACEE0 001A9E40  80 03 00 38 */	lwz r0, 0x38(r3)
/* 801ACEE4 001A9E44  2C 00 00 00 */	cmpwi r0, 0
/* 801ACEE8 001A9E48  40 80 00 38 */	bge .L_801ACF20
/* 801ACEEC 001A9E4C  28 1F 00 00 */	cmplwi r31, 0
/* 801ACEF0 001A9E50  38 BF 00 00 */	addi r5, r31, 0
/* 801ACEF4 001A9E54  41 82 00 08 */	beq .L_801ACEFC
/* 801ACEF8 001A9E58  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
.L_801ACEFC:
/* 801ACEFC 001A9E5C  38 61 00 1C */	addi r3, r1, 0x1c
/* 801ACF00 001A9E60  4B F7 20 8D */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801ACF04 001A9E64  7C 64 1B 78 */	mr r4, r3
/* 801ACF08 001A9E68  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801ACF0C 001A9E6C  4B F7 22 B5 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 801ACF10 001A9E70  38 00 00 09 */	li r0, 9
/* 801ACF14 001A9E74  90 1F 03 A8 */	stw r0, 0x3a8(r31)
/* 801ACF18 001A9E78  38 60 00 01 */	li r3, 1
/* 801ACF1C 001A9E7C  48 00 00 10 */	b .L_801ACF2C
.L_801ACF20:
/* 801ACF20 001A9E80  38 60 00 00 */	li r3, 0
/* 801ACF24 001A9E84  48 00 00 08 */	b .L_801ACF2C
.L_801ACF28:
/* 801ACF28 001A9E88  38 60 00 01 */	li r3, 1
.L_801ACF2C:
/* 801ACF2C 001A9E8C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801ACF30 001A9E90  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 801ACF34 001A9E94  38 21 00 30 */	addi r1, r1, 0x30
/* 801ACF38 001A9E98  7C 08 03 A6 */	mtlr r0
/* 801ACF3C 001A9E9C  4E 80 00 20 */	blr 
.endfn act__17TAIAreserveMotionFR4Teki

.fn start__14TAIAmotionLoopFR4Teki, global
/* 801ACF40 001A9EA0  7C 08 02 A6 */	mflr r0
/* 801ACF44 001A9EA4  90 01 00 04 */	stw r0, 4(r1)
/* 801ACF48 001A9EA8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801ACF4C 001A9EAC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801ACF50 001A9EB0  7C 9F 23 78 */	mr r31, r4
/* 801ACF54 001A9EB4  4B FF FD B1 */	bl start__17TAIAreserveMotionFR4Teki
/* 801ACF58 001A9EB8  C0 02 B6 18 */	lfs f0, lbl_803EB818@sda21(r2)
/* 801ACF5C 001A9EBC  D0 1F 04 78 */	stfs f0, 0x478(r31)
/* 801ACF60 001A9EC0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801ACF64 001A9EC4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801ACF68 001A9EC8  38 21 00 18 */	addi r1, r1, 0x18
/* 801ACF6C 001A9ECC  7C 08 03 A6 */	mtlr r0
/* 801ACF70 001A9ED0  4E 80 00 20 */	blr 
.endfn start__14TAIAmotionLoopFR4Teki

.fn act__14TAIAmotionLoopFR4Teki, global
/* 801ACF74 001A9ED4  7C 08 02 A6 */	mflr r0
/* 801ACF78 001A9ED8  90 01 00 04 */	stw r0, 4(r1)
/* 801ACF7C 001A9EDC  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 801ACF80 001A9EE0  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 801ACF84 001A9EE4  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 801ACF88 001A9EE8  3B E0 00 00 */	li r31, 0
/* 801ACF8C 001A9EEC  93 C1 00 48 */	stw r30, 0x48(r1)
/* 801ACF90 001A9EF0  7C 9E 23 78 */	mr r30, r4
/* 801ACF94 001A9EF4  93 A1 00 44 */	stw r29, 0x44(r1)
/* 801ACF98 001A9EF8  7C 7D 1B 78 */	mr r29, r3
/* 801ACF9C 001A9EFC  80 A4 02 CC */	lwz r5, 0x2cc(r4)
/* 801ACFA0 001A9F00  80 83 00 08 */	lwz r4, 8(r3)
/* 801ACFA4 001A9F04  80 05 00 44 */	lwz r0, 0x44(r5)
/* 801ACFA8 001A9F08  7C 04 00 00 */	cmpw r4, r0
/* 801ACFAC 001A9F0C  41 82 00 4C */	beq .L_801ACFF8
/* 801ACFB0 001A9F10  80 05 00 38 */	lwz r0, 0x38(r5)
/* 801ACFB4 001A9F14  2C 00 00 00 */	cmpwi r0, 0
/* 801ACFB8 001A9F18  40 80 00 38 */	bge .L_801ACFF0
/* 801ACFBC 001A9F1C  28 1E 00 00 */	cmplwi r30, 0
/* 801ACFC0 001A9F20  38 BE 00 00 */	addi r5, r30, 0
/* 801ACFC4 001A9F24  41 82 00 08 */	beq .L_801ACFCC
/* 801ACFC8 001A9F28  80 BE 02 C0 */	lwz r5, 0x2c0(r30)
.L_801ACFCC:
/* 801ACFCC 001A9F2C  38 61 00 2C */	addi r3, r1, 0x2c
/* 801ACFD0 001A9F30  4B F7 1F BD */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801ACFD4 001A9F34  7C 64 1B 78 */	mr r4, r3
/* 801ACFD8 001A9F38  80 7E 02 CC */	lwz r3, 0x2cc(r30)
/* 801ACFDC 001A9F3C  4B F7 21 E5 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 801ACFE0 001A9F40  38 00 00 09 */	li r0, 9
/* 801ACFE4 001A9F44  90 1E 03 A8 */	stw r0, 0x3a8(r30)
/* 801ACFE8 001A9F48  38 00 00 01 */	li r0, 1
/* 801ACFEC 001A9F4C  48 00 00 10 */	b .L_801ACFFC
.L_801ACFF0:
/* 801ACFF0 001A9F50  38 00 00 00 */	li r0, 0
/* 801ACFF4 001A9F54  48 00 00 08 */	b .L_801ACFFC
.L_801ACFF8:
/* 801ACFF8 001A9F58  38 00 00 01 */	li r0, 1
.L_801ACFFC:
/* 801ACFFC 001A9F5C  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 801AD000 001A9F60  41 82 00 68 */	beq .L_801AD068
/* 801AD004 001A9F64  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 801AD008 001A9F68  7F A3 EB 78 */	mr r3, r29
/* 801AD00C 001A9F6C  C0 3E 04 78 */	lfs f1, 0x478(r30)
/* 801AD010 001A9F70  7F C4 F3 78 */	mr r4, r30
/* 801AD014 001A9F74  C0 05 02 8C */	lfs f0, 0x28c(r5)
/* 801AD018 001A9F78  EC 01 00 2A */	fadds f0, f1, f0
/* 801AD01C 001A9F7C  D0 1E 04 78 */	stfs f0, 0x478(r30)
/* 801AD020 001A9F80  81 9D 00 04 */	lwz r12, 4(r29)
/* 801AD024 001A9F84  C3 FE 04 78 */	lfs f31, 0x478(r30)
/* 801AD028 001A9F88  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 801AD02C 001A9F8C  7D 88 03 A6 */	mtlr r12
/* 801AD030 001A9F90  4E 80 00 21 */	blrl 
/* 801AD034 001A9F94  FC 1F 08 40 */	fcmpo cr0, f31, f1
/* 801AD038 001A9F98  40 81 00 30 */	ble .L_801AD068
/* 801AD03C 001A9F9C  28 1E 00 00 */	cmplwi r30, 0
/* 801AD040 001A9FA0  38 BE 00 00 */	addi r5, r30, 0
/* 801AD044 001A9FA4  3B E0 00 01 */	li r31, 1
/* 801AD048 001A9FA8  41 82 00 08 */	beq .L_801AD050
/* 801AD04C 001A9FAC  80 BE 02 C0 */	lwz r5, 0x2c0(r30)
.L_801AD050:
/* 801AD050 001A9FB0  38 61 00 34 */	addi r3, r1, 0x34
/* 801AD054 001A9FB4  38 80 FF FF */	li r4, -1
/* 801AD058 001A9FB8  4B F7 1F 35 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801AD05C 001A9FBC  7C 64 1B 78 */	mr r4, r3
/* 801AD060 001A9FC0  80 7E 02 CC */	lwz r3, 0x2cc(r30)
/* 801AD064 001A9FC4  4B F7 21 CD */	bl finishMotion__12PaniAnimatorFR14PaniMotionInfo
.L_801AD068:
/* 801AD068 001A9FC8  7F E3 FB 78 */	mr r3, r31
/* 801AD06C 001A9FCC  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 801AD070 001A9FD0  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 801AD074 001A9FD4  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 801AD078 001A9FD8  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 801AD07C 001A9FDC  83 A1 00 44 */	lwz r29, 0x44(r1)
/* 801AD080 001A9FE0  38 21 00 58 */	addi r1, r1, 0x58
/* 801AD084 001A9FE4  7C 08 03 A6 */	mtlr r0
/* 801AD088 001A9FE8  4E 80 00 20 */	blr 
.endfn act__14TAIAmotionLoopFR4Teki

.fn getFrameMax__14TAIAmotionLoopFR4Teki, weak
/* 801AD08C 001A9FEC  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 801AD090 001A9FF0  4E 80 00 20 */	blr 
.endfn getFrameMax__14TAIAmotionLoopFR4Teki

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802DFC30, local
	.asciz "TAIAmotion.cpp"
.endobj lbl_802DFC30
.balign 4
.obj lbl_802DFC40, local
	.asciz "TAIAmotion"
.endobj lbl_802DFC40
.balign 4
.obj lbl_802DFC4C, local
	.asciz "TAIAmotionLoop"
.endobj lbl_802DFC4C
.balign 4
.obj lbl_802DFC5C, local
	.asciz "TaiAction"
.endobj lbl_802DFC5C
.balign 4
.obj lbl_802DFC68, local
	.asciz "TAIAreserveMotion"
.endobj lbl_802DFC68
.balign 4
.obj lbl_802DFC7C, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802DFC7C
.obj lbl_802DFC88, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__17TAIAreserveMotion
	.4byte 0
	.4byte 0
.endobj lbl_802DFC88
.obj __vt__14TAIAmotionLoop, global
	.4byte __RTTI__14TAIAmotionLoop
	.4byte 0
	.4byte start__14TAIAmotionLoopFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__14TAIAmotionLoopFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
	.4byte getFrameMax__14TAIAmotionLoopFR4Teki
.endobj __vt__14TAIAmotionLoop
.obj __vt__17TAIAreserveMotion, global
	.4byte __RTTI__17TAIAreserveMotion
	.4byte 0
	.4byte start__17TAIAreserveMotionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__17TAIAreserveMotionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__17TAIAreserveMotion
.obj lbl_802DFCD8, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802DFCD8
.obj __vt__10TAIAmotion, global
	.4byte __RTTI__10TAIAmotion
	.4byte 0
	.4byte start__10TAIAmotionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__10TAIAmotionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__10TAIAmotion
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__9TaiAction, local
	.4byte lbl_802DFC5C
	.4byte 0
.endobj __RTTI__9TaiAction
.obj __RTTI__17TAIAreserveMotion, local
	.4byte lbl_802DFC68
	.4byte lbl_802DFC7C
.endobj __RTTI__17TAIAreserveMotion
.obj __RTTI__14TAIAmotionLoop, local
	.4byte lbl_802DFC4C
	.4byte lbl_802DFC88
.endobj __RTTI__14TAIAmotionLoop
.obj __RTTI__10TAIAmotion, local
	.4byte lbl_802DFC40
	.4byte lbl_802DFCD8
.endobj __RTTI__10TAIAmotion

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EB810, local
	.8byte 0x4330000080000000
.endobj lbl_803EB810
.obj lbl_803EB818, local
	.float 0.0
.endobj lbl_803EB818
