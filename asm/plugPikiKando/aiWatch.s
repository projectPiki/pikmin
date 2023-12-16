.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn animationKeyUpdated__Q28ActWatch12AnimListenerFR16PaniAnimKeyEvent, global
/* 800C2C54 000BFBB4  4E 80 00 20 */	blr 
.endfn animationKeyUpdated__Q28ActWatch12AnimListenerFR16PaniAnimKeyEvent

.fn __ct__8ActWatchFP4Piki, global
/* 800C2C58 000BFBB8  7C 08 02 A6 */	mflr r0
/* 800C2C5C 000BFBBC  38 A0 00 01 */	li r5, 1
/* 800C2C60 000BFBC0  90 01 00 04 */	stw r0, 4(r1)
/* 800C2C64 000BFBC4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800C2C68 000BFBC8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800C2C6C 000BFBCC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800C2C70 000BFBD0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800C2C74 000BFBD4  7C 9D 23 78 */	mr r29, r4
/* 800C2C78 000BFBD8  90 61 00 08 */	stw r3, 8(r1)
/* 800C2C7C 000BFBDC  80 61 00 08 */	lwz r3, 8(r1)
/* 800C2C80 000BFBE0  48 00 11 51 */	bl __ct__6ActionFP4Pikib
/* 800C2C84 000BFBE4  3C 60 80 2B */	lis r3, __vt__8ActWatch@ha
/* 800C2C88 000BFBE8  83 C1 00 08 */	lwz r30, 8(r1)
/* 800C2C8C 000BFBEC  38 03 7C 8C */	addi r0, r3, __vt__8ActWatch@l
/* 800C2C90 000BFBF0  90 1E 00 00 */	stw r0, 0(r30)
/* 800C2C94 000BFBF4  3B E0 00 00 */	li r31, 0
/* 800C2C98 000BFBF8  93 FE 00 14 */	stw r31, 0x14(r30)
/* 800C2C9C 000BFBFC  C0 02 95 28 */	lfs f0, lbl_803E9728@sda21(r2)
/* 800C2CA0 000BFC00  D0 1E 00 28 */	stfs f0, 0x28(r30)
/* 800C2CA4 000BFC04  D0 1E 00 24 */	stfs f0, 0x24(r30)
/* 800C2CA8 000BFC08  D0 1E 00 20 */	stfs f0, 0x20(r30)
/* 800C2CAC 000BFC0C  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 800C2CB0 000BFC10  28 03 00 00 */	cmplwi r3, 0
/* 800C2CB4 000BFC14  41 82 00 0C */	beq .L_800C2CC0
/* 800C2CB8 000BFC18  48 02 16 B5 */	bl subCnt__12RefCountableFv
/* 800C2CBC 000BFC1C  93 FE 00 14 */	stw r31, 0x14(r30)
.L_800C2CC0:
/* 800C2CC0 000BFC20  38 60 00 0C */	li r3, 0xc
/* 800C2CC4 000BFC24  4B F8 43 41 */	bl alloc__6SystemFUl
/* 800C2CC8 000BFC28  28 03 00 00 */	cmplwi r3, 0
/* 800C2CCC 000BFC2C  41 82 00 28 */	beq .L_800C2CF4
/* 800C2CD0 000BFC30  3C 80 80 2B */	lis r4, __vt__19PaniAnimKeyListener@ha
/* 800C2CD4 000BFC34  38 04 DB 94 */	addi r0, r4, __vt__19PaniAnimKeyListener@l
/* 800C2CD8 000BFC38  3C 80 80 2B */	lis r4, __vt__Q28ActWatch12AnimListener@ha
/* 800C2CDC 000BFC3C  90 03 00 00 */	stw r0, 0(r3)
/* 800C2CE0 000BFC40  38 04 7D 78 */	addi r0, r4, __vt__Q28ActWatch12AnimListener@l
/* 800C2CE4 000BFC44  90 03 00 00 */	stw r0, 0(r3)
/* 800C2CE8 000BFC48  80 01 00 08 */	lwz r0, 8(r1)
/* 800C2CEC 000BFC4C  90 03 00 04 */	stw r0, 4(r3)
/* 800C2CF0 000BFC50  93 A3 00 08 */	stw r29, 8(r3)
.L_800C2CF4:
/* 800C2CF4 000BFC54  80 81 00 08 */	lwz r4, 8(r1)
/* 800C2CF8 000BFC58  90 64 00 1C */	stw r3, 0x1c(r4)
/* 800C2CFC 000BFC5C  7C 83 23 78 */	mr r3, r4
/* 800C2D00 000BFC60  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800C2D04 000BFC64  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800C2D08 000BFC68  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800C2D0C 000BFC6C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800C2D10 000BFC70  38 21 00 20 */	addi r1, r1, 0x20
/* 800C2D14 000BFC74  7C 08 03 A6 */	mtlr r0
/* 800C2D18 000BFC78  4E 80 00 20 */	blr 
.endfn __ct__8ActWatchFP4Piki

.fn initialise__Q28ActWatch11InitialiserFP6Action, global
/* 800C2D1C 000BFC7C  4E 80 00 20 */	blr 
.endfn initialise__Q28ActWatch11InitialiserFP6Action

.fn init__8ActWatchFP8Creature, global
/* 800C2D20 000BFC80  7C 08 02 A6 */	mflr r0
/* 800C2D24 000BFC84  90 01 00 04 */	stw r0, 4(r1)
/* 800C2D28 000BFC88  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800C2D2C 000BFC8C  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 800C2D30 000BFC90  93 C1 00 48 */	stw r30, 0x48(r1)
/* 800C2D34 000BFC94  7C 9E 23 79 */	or. r30, r4, r4
/* 800C2D38 000BFC98  93 A1 00 44 */	stw r29, 0x44(r1)
/* 800C2D3C 000BFC9C  3B A3 00 00 */	addi r29, r3, 0
/* 800C2D40 000BFCA0  41 82 01 0C */	beq .L_800C2E4C
/* 800C2D44 000BFCA4  48 15 53 2D */	bl rand
/* 800C2D48 000BFCA8  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C2D4C 000BFCAC  C8 82 95 40 */	lfd f4, lbl_803E9740@sda21(r2)
/* 800C2D50 000BFCB0  90 01 00 3C */	stw r0, 0x3c(r1)
/* 800C2D54 000BFCB4  3C 00 43 30 */	lis r0, 0x4330
/* 800C2D58 000BFCB8  C0 42 95 30 */	lfs f2, lbl_803E9730@sda21(r2)
/* 800C2D5C 000BFCBC  90 01 00 38 */	stw r0, 0x38(r1)
/* 800C2D60 000BFCC0  C0 22 95 2C */	lfs f1, lbl_803E972C@sda21(r2)
/* 800C2D64 000BFCC4  C8 61 00 38 */	lfd f3, 0x38(r1)
/* 800C2D68 000BFCC8  C0 02 95 34 */	lfs f0, lbl_803E9734@sda21(r2)
/* 800C2D6C 000BFCCC  EC 63 20 28 */	fsubs f3, f3, f4
/* 800C2D70 000BFCD0  EC 43 10 24 */	fdivs f2, f3, f2
/* 800C2D74 000BFCD4  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C2D78 000BFCD8  EC 00 00 72 */	fmuls f0, f0, f1
/* 800C2D7C 000BFCDC  FC 00 00 1E */	fctiwz f0, f0
/* 800C2D80 000BFCE0  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 800C2D84 000BFCE4  80 61 00 34 */	lwz r3, 0x34(r1)
/* 800C2D88 000BFCE8  38 03 00 32 */	addi r0, r3, 0x32
/* 800C2D8C 000BFCEC  90 1D 00 18 */	stw r0, 0x18(r29)
/* 800C2D90 000BFCF0  80 7D 00 14 */	lwz r3, 0x14(r29)
/* 800C2D94 000BFCF4  28 03 00 00 */	cmplwi r3, 0
/* 800C2D98 000BFCF8  41 82 00 14 */	beq .L_800C2DAC
/* 800C2D9C 000BFCFC  41 82 00 10 */	beq .L_800C2DAC
/* 800C2DA0 000BFD00  48 02 15 CD */	bl subCnt__12RefCountableFv
/* 800C2DA4 000BFD04  38 00 00 00 */	li r0, 0
/* 800C2DA8 000BFD08  90 1D 00 14 */	stw r0, 0x14(r29)
.L_800C2DAC:
/* 800C2DAC 000BFD0C  93 DD 00 14 */	stw r30, 0x14(r29)
/* 800C2DB0 000BFD10  80 7D 00 14 */	lwz r3, 0x14(r29)
/* 800C2DB4 000BFD14  28 03 00 00 */	cmplwi r3, 0
/* 800C2DB8 000BFD18  41 82 00 08 */	beq .L_800C2DC0
/* 800C2DBC 000BFD1C  48 02 15 A1 */	bl addCnt__12RefCountableFv
.L_800C2DC0:
/* 800C2DC0 000BFD20  38 61 00 20 */	addi r3, r1, 0x20
/* 800C2DC4 000BFD24  38 80 00 03 */	li r4, 3
/* 800C2DC8 000BFD28  48 05 C1 91 */	bl __ct__14PaniMotionInfoFi
/* 800C2DCC 000BFD2C  3B E3 00 00 */	addi r31, r3, 0
/* 800C2DD0 000BFD30  38 61 00 28 */	addi r3, r1, 0x28
/* 800C2DD4 000BFD34  38 80 00 03 */	li r4, 3
/* 800C2DD8 000BFD38  48 05 C1 81 */	bl __ct__14PaniMotionInfoFi
/* 800C2DDC 000BFD3C  7C 64 1B 78 */	mr r4, r3
/* 800C2DE0 000BFD40  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800C2DE4 000BFD44  7F E5 FB 78 */	mr r5, r31
/* 800C2DE8 000BFD48  48 00 7B F1 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800C2DEC 000BFD4C  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800C2DF0 000BFD50  48 00 7E 1D */	bl enableMotionBlend__4PikiFv
/* 800C2DF4 000BFD54  7F C4 F3 78 */	mr r4, r30
/* 800C2DF8 000BFD58  81 9E 00 00 */	lwz r12, 0(r30)
/* 800C2DFC 000BFD5C  38 61 00 14 */	addi r3, r1, 0x14
/* 800C2E00 000BFD60  81 8C 00 58 */	lwz r12, 0x58(r12)
/* 800C2E04 000BFD64  7D 88 03 A6 */	mtlr r12
/* 800C2E08 000BFD68  4E 80 00 21 */	blrl 
/* 800C2E0C 000BFD6C  80 81 00 14 */	lwz r4, 0x14(r1)
/* 800C2E10 000BFD70  7F C3 F3 78 */	mr r3, r30
/* 800C2E14 000BFD74  80 01 00 18 */	lwz r0, 0x18(r1)
/* 800C2E18 000BFD78  90 9D 00 20 */	stw r4, 0x20(r29)
/* 800C2E1C 000BFD7C  90 1D 00 24 */	stw r0, 0x24(r29)
/* 800C2E20 000BFD80  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800C2E24 000BFD84  90 1D 00 28 */	stw r0, 0x28(r29)
/* 800C2E28 000BFD88  81 9E 00 00 */	lwz r12, 0(r30)
/* 800C2E2C 000BFD8C  81 8C 00 64 */	lwz r12, 0x64(r12)
/* 800C2E30 000BFD90  7D 88 03 A6 */	mtlr r12
/* 800C2E34 000BFD94  4E 80 00 21 */	blrl 
/* 800C2E38 000BFD98  C0 42 95 38 */	lfs f2, lbl_803E9738@sda21(r2)
/* 800C2E3C 000BFD9C  C0 1D 00 24 */	lfs f0, 0x24(r29)
/* 800C2E40 000BFDA0  EC 22 00 72 */	fmuls f1, f2, f1
/* 800C2E44 000BFDA4  EC 00 08 2A */	fadds f0, f0, f1
/* 800C2E48 000BFDA8  D0 1D 00 24 */	stfs f0, 0x24(r29)
.L_800C2E4C:
/* 800C2E4C 000BFDAC  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800C2E50 000BFDB0  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 800C2E54 000BFDB4  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 800C2E58 000BFDB8  83 A1 00 44 */	lwz r29, 0x44(r1)
/* 800C2E5C 000BFDBC  38 21 00 50 */	addi r1, r1, 0x50
/* 800C2E60 000BFDC0  7C 08 03 A6 */	mtlr r0
/* 800C2E64 000BFDC4  4E 80 00 20 */	blr 
.endfn init__8ActWatchFP8Creature

.fn cleanup__8ActWatchFv, global
/* 800C2E68 000BFDC8  7C 08 02 A6 */	mflr r0
/* 800C2E6C 000BFDCC  90 01 00 04 */	stw r0, 4(r1)
/* 800C2E70 000BFDD0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800C2E74 000BFDD4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800C2E78 000BFDD8  7C 7F 1B 78 */	mr r31, r3
/* 800C2E7C 000BFDDC  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800C2E80 000BFDE0  28 03 00 00 */	cmplwi r3, 0
/* 800C2E84 000BFDE4  41 82 00 10 */	beq .L_800C2E94
/* 800C2E88 000BFDE8  48 02 14 E5 */	bl subCnt__12RefCountableFv
/* 800C2E8C 000BFDEC  38 00 00 00 */	li r0, 0
/* 800C2E90 000BFDF0  90 1F 00 14 */	stw r0, 0x14(r31)
.L_800C2E94:
/* 800C2E94 000BFDF4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C2E98 000BFDF8  48 01 68 2D */	bl finishLook__4PikiFv
/* 800C2E9C 000BFDFC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800C2EA0 000BFE00  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800C2EA4 000BFE04  38 21 00 18 */	addi r1, r1, 0x18
/* 800C2EA8 000BFE08  7C 08 03 A6 */	mtlr r0
/* 800C2EAC 000BFE0C  4E 80 00 20 */	blr 
.endfn cleanup__8ActWatchFv

.fn getInfo__8ActWatchFPc, global
/* 800C2EB0 000BFE10  7C 08 02 A6 */	mflr r0
/* 800C2EB4 000BFE14  3C C0 80 2B */	lis r6, lbl_802B7C44@ha
/* 800C2EB8 000BFE18  90 01 00 04 */	stw r0, 4(r1)
/* 800C2EBC 000BFE1C  38 06 7C 44 */	addi r0, r6, lbl_802B7C44@l
/* 800C2EC0 000BFE20  4C C6 31 82 */	crclr 6
/* 800C2EC4 000BFE24  94 21 FF F8 */	stwu r1, -8(r1)
/* 800C2EC8 000BFE28  80 A3 00 18 */	lwz r5, 0x18(r3)
/* 800C2ECC 000BFE2C  38 64 00 00 */	addi r3, r4, 0
/* 800C2ED0 000BFE30  7C 04 03 78 */	mr r4, r0
/* 800C2ED4 000BFE34  48 15 36 C5 */	bl sprintf
/* 800C2ED8 000BFE38  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800C2EDC 000BFE3C  38 21 00 08 */	addi r1, r1, 8
/* 800C2EE0 000BFE40  7C 08 03 A6 */	mtlr r0
/* 800C2EE4 000BFE44  4E 80 00 20 */	blr 
.endfn getInfo__8ActWatchFPc

.fn exec__8ActWatchFv, global
/* 800C2EE8 000BFE48  7C 08 02 A6 */	mflr r0
/* 800C2EEC 000BFE4C  90 01 00 04 */	stw r0, 4(r1)
/* 800C2EF0 000BFE50  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 800C2EF4 000BFE54  DB E1 00 68 */	stfd f31, 0x68(r1)
/* 800C2EF8 000BFE58  DB C1 00 60 */	stfd f30, 0x60(r1)
/* 800C2EFC 000BFE5C  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 800C2F00 000BFE60  93 C1 00 58 */	stw r30, 0x58(r1)
/* 800C2F04 000BFE64  7C 7E 1B 78 */	mr r30, r3
/* 800C2F08 000BFE68  83 E3 00 14 */	lwz r31, 0x14(r3)
/* 800C2F0C 000BFE6C  28 1F 00 00 */	cmplwi r31, 0
/* 800C2F10 000BFE70  38 7F 00 00 */	addi r3, r31, 0
/* 800C2F14 000BFE74  41 82 00 1C */	beq .L_800C2F30
/* 800C2F18 000BFE78  81 83 00 00 */	lwz r12, 0(r3)
/* 800C2F1C 000BFE7C  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800C2F20 000BFE80  7D 88 03 A6 */	mtlr r12
/* 800C2F24 000BFE84  4E 80 00 21 */	blrl 
/* 800C2F28 000BFE88  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800C2F2C 000BFE8C  40 82 00 0C */	bne .L_800C2F38
.L_800C2F30:
/* 800C2F30 000BFE90  38 60 00 01 */	li r3, 1
/* 800C2F34 000BFE94  48 00 00 F0 */	b .L_800C3024
.L_800C2F38:
/* 800C2F38 000BFE98  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800C2F3C 000BFE9C  34 03 FF FF */	addic. r0, r3, -1
/* 800C2F40 000BFEA0  90 1E 00 18 */	stw r0, 0x18(r30)
/* 800C2F44 000BFEA4  40 80 00 0C */	bge .L_800C2F50
/* 800C2F48 000BFEA8  38 60 00 02 */	li r3, 2
/* 800C2F4C 000BFEAC  48 00 00 D8 */	b .L_800C3024
.L_800C2F50:
/* 800C2F50 000BFEB0  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800C2F54 000BFEB4  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 800C2F58 000BFEB8  C0 3F 00 94 */	lfs f1, 0x94(r31)
/* 800C2F5C 000BFEBC  C0 7F 00 98 */	lfs f3, 0x98(r31)
/* 800C2F60 000BFEC0  C0 43 00 04 */	lfs f2, 4(r3)
/* 800C2F64 000BFEC4  EC 01 00 28 */	fsubs f0, f1, f0
/* 800C2F68 000BFEC8  C0 9F 00 9C */	lfs f4, 0x9c(r31)
/* 800C2F6C 000BFECC  C0 23 00 08 */	lfs f1, 8(r3)
/* 800C2F70 000BFED0  EC 43 10 28 */	fsubs f2, f3, f2
/* 800C2F74 000BFED4  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 800C2F78 000BFED8  EC 04 08 28 */	fsubs f0, f4, f1
/* 800C2F7C 000BFEDC  D0 41 00 50 */	stfs f2, 0x50(r1)
/* 800C2F80 000BFEE0  D0 01 00 54 */	stfs f0, 0x54(r1)
/* 800C2F84 000BFEE4  C0 22 95 28 */	lfs f1, lbl_803E9728@sda21(r2)
/* 800C2F88 000BFEE8  C3 C1 00 4C */	lfs f30, 0x4c(r1)
/* 800C2F8C 000BFEEC  C3 E1 00 54 */	lfs f31, 0x54(r1)
/* 800C2F90 000BFEF0  FC 40 08 90 */	fmr f2, f1
/* 800C2F94 000BFEF4  FC 60 F0 90 */	fmr f3, f30
/* 800C2F98 000BFEF8  FC 80 F8 90 */	fmr f4, f31
/* 800C2F9C 000BFEFC  4B F7 56 8D */	bl qdist2__Fffff
/* 800C2FA0 000BFF00  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800C2FA4 000BFF04  FC 20 F0 90 */	fmr f1, f30
/* 800C2FA8 000BFF08  C0 0D BB 88 */	lfs f0, lbl_803E08A8@sda21(r13)
/* 800C2FAC 000BFF0C  FC 40 F8 90 */	fmr f2, f31
/* 800C2FB0 000BFF10  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800C2FB4 000BFF14  C0 0D BB 8C */	lfs f0, lbl_803E08AC@sda21(r13)
/* 800C2FB8 000BFF18  D0 03 00 04 */	stfs f0, 4(r3)
/* 800C2FBC 000BFF1C  C0 0D BB 90 */	lfs f0, lbl_803E08B0@sda21(r13)
/* 800C2FC0 000BFF20  D0 03 00 08 */	stfs f0, 8(r3)
/* 800C2FC4 000BFF24  48 15 8A 35 */	bl atan2f
/* 800C2FC8 000BFF28  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800C2FCC 000BFF2C  C0 43 00 A0 */	lfs f2, 0xa0(r3)
/* 800C2FD0 000BFF30  4B F7 55 E5 */	bl angDist__Fff
/* 800C2FD4 000BFF34  C0 02 95 48 */	lfs f0, lbl_803E9748@sda21(r2)
/* 800C2FD8 000BFF38  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800C2FDC 000BFF3C  EC 20 00 72 */	fmuls f1, f0, f1
/* 800C2FE0 000BFF40  C0 03 00 A0 */	lfs f0, 0xa0(r3)
/* 800C2FE4 000BFF44  EC 00 08 2A */	fadds f0, f0, f1
/* 800C2FE8 000BFF48  D0 03 00 A0 */	stfs f0, 0xa0(r3)
/* 800C2FEC 000BFF4C  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800C2FF0 000BFF50  C0 23 00 A0 */	lfs f1, 0xa0(r3)
/* 800C2FF4 000BFF54  4B F7 55 95 */	bl roundAng__Ff
/* 800C2FF8 000BFF58  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800C2FFC 000BFF5C  38 60 00 00 */	li r3, 0
/* 800C3000 000BFF60  D0 24 00 A0 */	stfs f1, 0xa0(r4)
/* 800C3004 000BFF64  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 800C3008 000BFF68  C0 0D BB 94 */	lfs f0, lbl_803E08B4@sda21(r13)
/* 800C300C 000BFF6C  38 85 00 88 */	addi r4, r5, 0x88
/* 800C3010 000BFF70  D0 05 00 88 */	stfs f0, 0x88(r5)
/* 800C3014 000BFF74  C0 05 00 A0 */	lfs f0, 0xa0(r5)
/* 800C3018 000BFF78  D0 04 00 04 */	stfs f0, 4(r4)
/* 800C301C 000BFF7C  C0 0D BB 98 */	lfs f0, lbl_803E08B8@sda21(r13)
/* 800C3020 000BFF80  D0 04 00 08 */	stfs f0, 8(r4)
.L_800C3024:
/* 800C3024 000BFF84  80 01 00 74 */	lwz r0, 0x74(r1)
/* 800C3028 000BFF88  CB E1 00 68 */	lfd f31, 0x68(r1)
/* 800C302C 000BFF8C  CB C1 00 60 */	lfd f30, 0x60(r1)
/* 800C3030 000BFF90  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 800C3034 000BFF94  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 800C3038 000BFF98  38 21 00 70 */	addi r1, r1, 0x70
/* 800C303C 000BFF9C  7C 08 03 A6 */	mtlr r0
/* 800C3040 000BFFA0  4E 80 00 20 */	blr 
.endfn exec__8ActWatchFv

.fn __dt__8ActWatchFv, weak
/* 800C3044 000BFFA4  7C 08 02 A6 */	mflr r0
/* 800C3048 000BFFA8  90 01 00 04 */	stw r0, 4(r1)
/* 800C304C 000BFFAC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800C3050 000BFFB0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800C3054 000BFFB4  3B E4 00 00 */	addi r31, r4, 0
/* 800C3058 000BFFB8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800C305C 000BFFBC  7C 7E 1B 79 */	or. r30, r3, r3
/* 800C3060 000BFFC0  41 82 00 2C */	beq .L_800C308C
/* 800C3064 000BFFC4  3C 60 80 2B */	lis r3, __vt__8ActWatch@ha
/* 800C3068 000BFFC8  38 03 7C 8C */	addi r0, r3, __vt__8ActWatch@l
/* 800C306C 000BFFCC  90 1E 00 00 */	stw r0, 0(r30)
/* 800C3070 000BFFD0  38 7E 00 00 */	addi r3, r30, 0
/* 800C3074 000BFFD4  38 80 00 00 */	li r4, 0
/* 800C3078 000BFFD8  48 00 0D 91 */	bl __dt__6ActionFv
/* 800C307C 000BFFDC  7F E0 07 35 */	extsh. r0, r31
/* 800C3080 000BFFE0  40 81 00 0C */	ble .L_800C308C
/* 800C3084 000BFFE4  7F C3 F3 78 */	mr r3, r30
/* 800C3088 000BFFE8  4B F8 41 25 */	bl __dl__FPv
.L_800C308C:
/* 800C308C 000BFFEC  7F C3 F3 78 */	mr r3, r30
/* 800C3090 000BFFF0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800C3094 000BFFF4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800C3098 000BFFF8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800C309C 000BFFFC  38 21 00 18 */	addi r1, r1, 0x18
/* 800C30A0 000C0000  7C 08 03 A6 */	mtlr r0
/* 800C30A4 000C0004  4E 80 00 20 */	blr 
.endfn __dt__8ActWatchFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B7C38, local
	.asciz "aiWatch.cpp"
.endobj lbl_802B7C38
.balign 4
.obj lbl_802B7C44, local
	.asciz "watch(%d)"
.endobj lbl_802B7C44
.balign 4
.obj lbl_802B7C50, local
	.asciz "ActWatch"
.endobj lbl_802B7C50
.balign 4
.obj lbl_802B7C5C, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B7C5C
.balign 4
.obj lbl_802B7C6C, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.endobj lbl_802B7C6C
.balign 4
.obj lbl_802B7C78, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B7C78
.balign 4
.obj __vt__8ActWatch, global
	.4byte __RTTI__8ActWatch
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__6ActionFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__8ActWatchFv
	.4byte init__8ActWatchFP8Creature
	.4byte exec__8ActWatchFv
	.4byte cleanup__8ActWatchFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__8ActWatchFPc
.endobj __vt__8ActWatch
.balign 4
.obj lbl_802B7CF0, local
	.asciz "ActWatch::Initialiser"
.endobj lbl_802B7CF0
.balign 4
.obj lbl_802B7D08, local
	.asciz "Action::Initialiser"
.endobj lbl_802B7D08
.balign 4
.obj lbl_802B7D1C, local
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte 0
.endobj lbl_802B7D1C
.balign 4
.obj __vt__Q28ActWatch11Initialiser, global
	.4byte __RTTI__Q28ActWatch11Initialiser
	.4byte 0
	.4byte initialise__Q28ActWatch11InitialiserFP6Action
.endobj __vt__Q28ActWatch11Initialiser
.balign 4
.obj lbl_802B7D34, local
	.asciz "PaniAnimKeyListener"
.endobj lbl_802B7D34
.balign 4
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
.obj lbl_802B7D54, local
	.asciz "ActWatch::AnimListener"
.endobj lbl_802B7D54
.balign 4
.obj lbl_802B7D6C, local
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0
	.4byte 0
.endobj lbl_802B7D6C
.balign 4
.obj __vt__Q28ActWatch12AnimListener, global
	.4byte __RTTI__Q28ActWatch12AnimListener
	.4byte 0
	.4byte animationKeyUpdated__Q28ActWatch12AnimListenerFR16PaniAnimKeyEvent
.endobj __vt__Q28ActWatch12AnimListener
.balign 4
.obj lbl_802B7D84, local
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x30)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x58)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x6C)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x80)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x94)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xA8)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xBC)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xD0)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x44)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xF8)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xE4)
.endobj lbl_802B7D84

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E08A8, local
	.float 0.0
.endobj lbl_803E08A8
.balign 4
.obj lbl_803E08AC, local
	.float 0.0
.endobj lbl_803E08AC
.balign 4
.obj lbl_803E08B0, local
	.float 0.0
.endobj lbl_803E08B0
.balign 4
.obj lbl_803E08B4, local
	.float 0.0
.endobj lbl_803E08B4
.balign 4
.obj lbl_803E08B8, local
	.float 0.0
.endobj lbl_803E08B8
.balign 4
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B7C5C
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E08C4, local
	.asciz "Action"
.endobj lbl_803E08C4
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E08C4
	.4byte lbl_802B7C6C
.endobj __RTTI__6Action
.balign 4
.obj __RTTI__8ActWatch, local
	.4byte lbl_802B7C50
	.4byte lbl_802B7C78
.endobj __RTTI__8ActWatch
.balign 4
.obj __RTTI__Q26Action11Initialiser, local
	.4byte lbl_802B7D08
	.4byte 0
.endobj __RTTI__Q26Action11Initialiser
.balign 4
.obj __RTTI__Q28ActWatch11Initialiser, local
	.4byte lbl_802B7CF0
	.4byte lbl_802B7D1C
.endobj __RTTI__Q28ActWatch11Initialiser
.balign 4
.obj __RTTI__19PaniAnimKeyListener, local
	.4byte lbl_802B7D34
	.4byte 0
.endobj __RTTI__19PaniAnimKeyListener
.balign 4
.obj __RTTI__Q28ActWatch12AnimListener, local
	.4byte lbl_802B7D54
	.4byte lbl_802B7D6C
.endobj __RTTI__Q28ActWatch12AnimListener

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9728, local
	.float 0.0
.endobj lbl_803E9728
.balign 4
.obj lbl_803E972C, local
	.float 1.0
.endobj lbl_803E972C
.balign 4
.obj lbl_803E9730, local
	.float 32767.0
.endobj lbl_803E9730
.balign 4
.obj lbl_803E9734, local
	.float 20.0
.endobj lbl_803E9734
.balign 4
.obj lbl_803E9738, local
	.float 1.6
.endobj lbl_803E9738
.balign 8
.obj lbl_803E9740, local
	.8byte 0x4330000080000000
.endobj lbl_803E9740
.balign 4
.obj lbl_803E9748, local
	.float 0.4
.endobj lbl_803E9748
