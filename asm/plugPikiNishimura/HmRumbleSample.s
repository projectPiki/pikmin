.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__12RumbleSampleFi
__ct__12RumbleSampleFi:
/* 8017D680 0017A5E0  C0 02 AE F0 */	lfs f0, lbl_803EB0F0@sda21(r2)
/* 8017D684 0017A5E4  D0 03 00 00 */	stfs f0, 0(r3)
/* 8017D688 0017A5E8  D0 03 00 04 */	stfs f0, 4(r3)
/* 8017D68C 0017A5EC  90 83 00 08 */	stw r4, 8(r3)
/* 8017D690 0017A5F0  4E 80 00 20 */	blr 

.global simpleStop__12RumbleSampleFv
simpleStop__12RumbleSampleFv:
/* 8017D694 0017A5F4  7C 08 02 A6 */	mflr r0
/* 8017D698 0017A5F8  38 80 00 02 */	li r4, 2
/* 8017D69C 0017A5FC  90 01 00 04 */	stw r0, 4(r1)
/* 8017D6A0 0017A600  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017D6A4 0017A604  80 63 00 08 */	lwz r3, 8(r3)
/* 8017D6A8 0017A608  48 08 80 45 */	bl PADControlMotor
/* 8017D6AC 0017A60C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017D6B0 0017A610  38 21 00 08 */	addi r1, r1, 8
/* 8017D6B4 0017A614  7C 08 03 A6 */	mtlr r0
/* 8017D6B8 0017A618  4E 80 00 20 */	blr 

.global simpleStart__12RumbleSampleFf
simpleStart__12RumbleSampleFf:
/* 8017D6BC 0017A61C  7C 08 02 A6 */	mflr r0
/* 8017D6C0 0017A620  90 01 00 04 */	stw r0, 4(r1)
/* 8017D6C4 0017A624  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017D6C8 0017A628  D0 23 00 00 */	stfs f1, 0(r3)
/* 8017D6CC 0017A62C  C0 23 00 04 */	lfs f1, 4(r3)
/* 8017D6D0 0017A630  C0 03 00 00 */	lfs f0, 0(r3)
/* 8017D6D4 0017A634  EC 01 00 2A */	fadds f0, f1, f0
/* 8017D6D8 0017A638  D0 03 00 04 */	stfs f0, 4(r3)
/* 8017D6DC 0017A63C  C0 23 00 00 */	lfs f1, 0(r3)
/* 8017D6E0 0017A640  C0 02 AE F0 */	lfs f0, lbl_803EB0F0@sda21(r2)
/* 8017D6E4 0017A644  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8017D6E8 0017A648  4C 40 13 82 */	cror 2, 0, 2
/* 8017D6EC 0017A64C  40 82 00 14 */	bne lbl_8017D700
/* 8017D6F0 0017A650  80 63 00 08 */	lwz r3, 8(r3)
/* 8017D6F4 0017A654  38 80 00 02 */	li r4, 2
/* 8017D6F8 0017A658  48 08 7F F5 */	bl PADControlMotor
/* 8017D6FC 0017A65C  48 00 00 38 */	b lbl_8017D734
lbl_8017D700:
/* 8017D700 0017A660  C0 23 00 04 */	lfs f1, 4(r3)
/* 8017D704 0017A664  C0 02 AE F4 */	lfs f0, lbl_803EB0F4@sda21(r2)
/* 8017D708 0017A668  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8017D70C 0017A66C  40 80 00 14 */	bge lbl_8017D720
/* 8017D710 0017A670  80 63 00 08 */	lwz r3, 8(r3)
/* 8017D714 0017A674  38 80 00 00 */	li r4, 0
/* 8017D718 0017A678  48 08 7F D5 */	bl PADControlMotor
/* 8017D71C 0017A67C  48 00 00 18 */	b lbl_8017D734
lbl_8017D720:
/* 8017D720 0017A680  EC 01 00 28 */	fsubs f0, f1, f0
/* 8017D724 0017A684  38 80 00 01 */	li r4, 1
/* 8017D728 0017A688  D0 03 00 04 */	stfs f0, 4(r3)
/* 8017D72C 0017A68C  80 63 00 08 */	lwz r3, 8(r3)
/* 8017D730 0017A690  48 08 7F BD */	bl PADControlMotor
lbl_8017D734:
/* 8017D734 0017A694  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017D738 0017A698  38 21 00 08 */	addi r1, r1, 8
/* 8017D73C 0017A69C  7C 08 03 A6 */	mtlr r0
/* 8017D740 0017A6A0  4E 80 00 20 */	blr 

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EB0F0:
	.float 0.0
lbl_803EB0F4:
	.float 1.0
