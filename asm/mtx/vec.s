.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn PSVECSquareMag, global
/* 801FE088 001FAFE8  E0 43 00 00 */	psq_l f2, 0(r3), 0, qr0
/* 801FE08C 001FAFEC  10 62 00 B2 */	ps_mul f3, f2, f2
/* 801FE090 001FAFF0  C0 83 00 08 */	lfs f4, 8(r3)
/* 801FE094 001FAFF4  10 A4 19 3A */	ps_madd f5, f4, f4, f3
/* 801FE098 001FAFF8  10 25 18 D4 */	ps_sum0 f1, f5, f3, f3
/* 801FE09C 001FAFFC  4E 80 00 20 */	blr 
/* 801FE0A0 001FB000  4E 80 00 20 */	blr 
.endfn PSVECSquareMag

.fn VECMag, global
/* 801FE0A4 001FB004  7C 08 02 A6 */	mflr r0
/* 801FE0A8 001FB008  90 01 00 04 */	stw r0, 4(r1)
/* 801FE0AC 001FB00C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801FE0B0 001FB010  4B FF FF D9 */	bl PSVECSquareMag
/* 801FE0B4 001FB014  C0 02 C3 08 */	lfs f0, lbl_803EC508@sda21(r2)
/* 801FE0B8 001FB018  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801FE0BC 001FB01C  40 81 00 60 */	ble .L_801FE11C
/* 801FE0C0 001FB020  FC 40 08 34 */	frsqrte f2, f1
/* 801FE0C4 001FB024  C8 82 C3 10 */	lfd f4, lbl_803EC510@sda21(r2)
/* 801FE0C8 001FB028  C8 62 C3 18 */	lfd f3, lbl_803EC518@sda21(r2)
/* 801FE0CC 001FB02C  FC 02 00 B2 */	fmul f0, f2, f2
/* 801FE0D0 001FB030  FC 44 00 B2 */	fmul f2, f4, f2
/* 801FE0D4 001FB034  FC 01 00 32 */	fmul f0, f1, f0
/* 801FE0D8 001FB038  FC 03 00 28 */	fsub f0, f3, f0
/* 801FE0DC 001FB03C  FC 42 00 32 */	fmul f2, f2, f0
/* 801FE0E0 001FB040  FC 02 00 B2 */	fmul f0, f2, f2
/* 801FE0E4 001FB044  FC 44 00 B2 */	fmul f2, f4, f2
/* 801FE0E8 001FB048  FC 01 00 32 */	fmul f0, f1, f0
/* 801FE0EC 001FB04C  FC 03 00 28 */	fsub f0, f3, f0
/* 801FE0F0 001FB050  FC 42 00 32 */	fmul f2, f2, f0
/* 801FE0F4 001FB054  FC 02 00 B2 */	fmul f0, f2, f2
/* 801FE0F8 001FB058  FC 44 00 B2 */	fmul f2, f4, f2
/* 801FE0FC 001FB05C  FC 01 00 32 */	fmul f0, f1, f0
/* 801FE100 001FB060  FC 03 00 28 */	fsub f0, f3, f0
/* 801FE104 001FB064  FC 02 00 32 */	fmul f0, f2, f0
/* 801FE108 001FB068  FC 01 00 32 */	fmul f0, f1, f0
/* 801FE10C 001FB06C  FC 00 00 18 */	frsp f0, f0
/* 801FE110 001FB070  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 801FE114 001FB074  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 801FE118 001FB078  48 00 00 04 */	b .L_801FE11C
.L_801FE11C:
/* 801FE11C 001FB07C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801FE120 001FB080  38 21 00 10 */	addi r1, r1, 0x10
/* 801FE124 001FB084  7C 08 03 A6 */	mtlr r0
/* 801FE128 001FB088  4E 80 00 20 */	blr 
.endfn VECMag

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EC508, local
	.float 0.0
.endobj lbl_803EC508
.balign 8
.obj lbl_803EC510, local
	.double 0.5
.endobj lbl_803EC510
.balign 8
.obj lbl_803EC518, local
	.double 3.0
.endobj lbl_803EC518
