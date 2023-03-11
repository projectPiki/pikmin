.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.fn Jam_PitchToCent, global
/* 80014BC0 00011B20  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80014BC4 00011B24  3C 00 43 30 */	lis r0, 0x4330
/* 80014BC8 00011B28  C0 02 81 38 */	lfs f0, lbl_803E8338@sda21(r2)
/* 80014BCC 00011B2C  C8 62 81 48 */	lfd f3, lbl_803E8348@sda21(r2)
/* 80014BD0 00011B30  EC 20 00 72 */	fmuls f1, f0, f1
/* 80014BD4 00011B34  C0 02 81 3C */	lfs f0, lbl_803E833C@sda21(r2)
/* 80014BD8 00011B38  EC 41 00 B2 */	fmuls f2, f1, f2
/* 80014BDC 00011B3C  FC 20 10 1E */	fctiwz f1, f2
/* 80014BE0 00011B40  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80014BE4 00011B44  D8 21 00 20 */	stfd f1, 0x20(r1)
/* 80014BE8 00011B48  80 61 00 24 */	lwz r3, 0x24(r1)
/* 80014BEC 00011B4C  D8 21 00 28 */	stfd f1, 0x28(r1)
/* 80014BF0 00011B50  7C 63 07 34 */	extsh r3, r3
/* 80014BF4 00011B54  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80014BF8 00011B58  80 81 00 2C */	lwz r4, 0x2c(r1)
/* 80014BFC 00011B5C  90 61 00 1C */	stw r3, 0x1c(r1)
/* 80014C00 00011B60  90 01 00 18 */	stw r0, 0x18(r1)
/* 80014C04 00011B64  C8 21 00 18 */	lfd f1, 0x18(r1)
/* 80014C08 00011B68  EC 21 18 28 */	fsubs f1, f1, f3
/* 80014C0C 00011B6C  EC 22 08 28 */	fsubs f1, f2, f1
/* 80014C10 00011B70  40 80 00 18 */	bge .L_80014C28
/* 80014C14 00011B74  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 80014C18 00011B78  41 82 00 10 */	beq .L_80014C28
/* 80014C1C 00011B7C  C0 02 81 40 */	lfs f0, lbl_803E8340@sda21(r2)
/* 80014C20 00011B80  38 84 FF FF */	addi r4, r4, -1
/* 80014C24 00011B84  EC 21 00 2A */	fadds f1, f1, f0
.L_80014C28:
/* 80014C28 00011B88  C0 02 81 40 */	lfs f0, lbl_803E8340@sda21(r2)
/* 80014C2C 00011B8C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80014C30 00011B90  4C 41 13 82 */	cror 2, 1, 2
/* 80014C34 00011B94  40 82 00 0C */	bne .L_80014C40
/* 80014C38 00011B98  EC 21 00 28 */	fsubs f1, f1, f0
/* 80014C3C 00011B9C  38 84 00 01 */	addi r4, r4, 1
.L_80014C40:
/* 80014C40 00011BA0  C0 02 81 44 */	lfs f0, lbl_803E8344@sda21(r2)
/* 80014C44 00011BA4  7C 80 07 34 */	extsh r0, r4
/* 80014C48 00011BA8  3C 80 80 22 */	lis r4, C5BASE_PITCHTABLE@ha
/* 80014C4C 00011BAC  3C 60 80 22 */	lis r3, KEY_TABLE@ha
/* 80014C50 00011BB0  EC 00 00 72 */	fmuls f0, f0, f1
/* 80014C54 00011BB4  38 A4 4E 18 */	addi r5, r4, C5BASE_PITCHTABLE@l
/* 80014C58 00011BB8  54 04 10 3A */	slwi r4, r0, 2
/* 80014C5C 00011BBC  38 03 57 28 */	addi r0, r3, KEY_TABLE@l
/* 80014C60 00011BC0  7C 65 22 14 */	add r3, r5, r4
/* 80014C64 00011BC4  FC 00 00 1E */	fctiwz f0, f0
/* 80014C68 00011BC8  C0 23 00 F0 */	lfs f1, 0xf0(r3)
/* 80014C6C 00011BCC  D8 01 00 18 */	stfd f0, 0x18(r1)
/* 80014C70 00011BD0  80 61 00 1C */	lwz r3, 0x1c(r1)
/* 80014C74 00011BD4  54 63 13 BA */	rlwinm r3, r3, 2, 0xe, 0x1d
/* 80014C78 00011BD8  7C 60 1A 14 */	add r3, r0, r3
/* 80014C7C 00011BDC  C0 03 00 00 */	lfs f0, 0(r3)
/* 80014C80 00011BE0  EC 21 00 32 */	fmuls f1, f1, f0
/* 80014C84 00011BE4  38 21 00 30 */	addi r1, r1, 0x30
/* 80014C88 00011BE8  4E 80 00 20 */	blr 
.endfn Jam_PitchToCent

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj KEY_TABLE, local
	.float 1.0
	.float 1.00091
	.float 1.001821
	.float 1.002733
	.float 1.003645
	.float 1.004559
	.float 1.005473
	.float 1.006388
	.float 1.007304
	.float 1.00822
	.float 1.009138
	.float 1.010056
	.float 1.010975
	.float 1.011896
	.float 1.012816
	.float 1.013738
	.float 1.014661
	.float 1.015584
	.float 1.016508
	.float 1.017433
	.float 1.018359
	.float 1.019286
	.float 1.020214
	.float 1.021142
	.float 1.022071
	.float 1.023002
	.float 1.023933
	.float 1.024864
	.float 1.025797
	.float 1.026731
	.float 1.027665
	.float 1.0286
	.float 1.029536
	.float 1.030473
	.float 1.031411
	.float 1.03235
	.float 1.033289
	.float 1.03423
	.float 1.035171
	.float 1.036113
	.float 1.037056
	.float 1.038
	.float 1.038944
	.float 1.03989
	.float 1.040836
	.float 1.041783
	.float 1.042731
	.float 1.04368
	.float 1.04463
	.float 1.045581
	.float 1.046532
	.float 1.047485
	.float 1.048438
	.float 1.049392
	.float 1.050347
	.float 1.051303
	.float 1.05226
	.float 1.053217
	.float 1.054176
	.float 1.055135
	.float 1.056095
	.float 1.057056
	.float 1.058018
	.float 1.058981
.endobj KEY_TABLE

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E8338, local
	.float 4.0
.endobj lbl_803E8338
.obj lbl_803E833C, local
	.float 0.0
.endobj lbl_803E833C
.obj lbl_803E8340, local
	.float 1.0
.endobj lbl_803E8340
.obj lbl_803E8344, local
	.float 64.0
.endobj lbl_803E8344
.balign 8
.obj lbl_803E8348, local
	.8byte 0x4330000080000000
.endobj lbl_803E8348
