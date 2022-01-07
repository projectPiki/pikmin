.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global sqrt
sqrt:
/* 8021BEBC 00218E1C  C8 02 C6 28 */	lfd f0, lbl_803EC828@sda21(r2)
/* 8021BEC0 00218E20  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8021BEC4 00218E24  40 81 00 58 */	ble lbl_8021BF1C
/* 8021BEC8 00218E28  FC 40 08 34 */	frsqrte f2, f1
/* 8021BECC 00218E2C  C8 82 C6 30 */	lfd f4, lbl_803EC830@sda21(r2)
/* 8021BED0 00218E30  C8 62 C6 38 */	lfd f3, lbl_803EC838@sda21(r2)
/* 8021BED4 00218E34  FC 02 00 B2 */	fmul f0, f2, f2
/* 8021BED8 00218E38  FC 44 00 B2 */	fmul f2, f4, f2
/* 8021BEDC 00218E3C  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 8021BEE0 00218E40  FC 42 00 32 */	fmul f2, f2, f0
/* 8021BEE4 00218E44  FC 02 00 B2 */	fmul f0, f2, f2
/* 8021BEE8 00218E48  FC 44 00 B2 */	fmul f2, f4, f2
/* 8021BEEC 00218E4C  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 8021BEF0 00218E50  FC 42 00 32 */	fmul f2, f2, f0
/* 8021BEF4 00218E54  FC 02 00 B2 */	fmul f0, f2, f2
/* 8021BEF8 00218E58  FC 44 00 B2 */	fmul f2, f4, f2
/* 8021BEFC 00218E5C  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 8021BF00 00218E60  FC 42 00 32 */	fmul f2, f2, f0
/* 8021BF04 00218E64  FC 02 00 B2 */	fmul f0, f2, f2
/* 8021BF08 00218E68  FC 44 00 B2 */	fmul f2, f4, f2
/* 8021BF0C 00218E6C  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 8021BF10 00218E70  FC 02 00 32 */	fmul f0, f2, f0
/* 8021BF14 00218E74  FC 21 00 32 */	fmul f1, f1, f0
/* 8021BF18 00218E78  4E 80 00 20 */	blr 
lbl_8021BF1C:
/* 8021BF1C 00218E7C  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 8021BF20 00218E80  40 82 00 0C */	bne lbl_8021BF2C
/* 8021BF24 00218E84  FC 20 00 90 */	fmr f1, f0
/* 8021BF28 00218E88  4E 80 00 20 */	blr 
lbl_8021BF2C:
/* 8021BF2C 00218E8C  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 8021BF30 00218E90  41 82 00 10 */	beq lbl_8021BF40
/* 8021BF34 00218E94  3C 60 80 2F */	lis r3, __float_nan@ha
/* 8021BF38 00218E98  C0 23 94 78 */	lfs f1, __float_nan@l(r3)
/* 8021BF3C 00218E9C  4E 80 00 20 */	blr 
lbl_8021BF40:
/* 8021BF40 00218EA0  3C 60 80 2F */	lis r3, __float_huge@ha
/* 8021BF44 00218EA4  C0 23 94 7C */	lfs f1, __float_huge@l(r3)
/* 8021BF48 00218EA8  4E 80 00 20 */	blr 

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EC828:
	.double 0.0
.balign 8
lbl_803EC830:
	.double 0.5
.balign 8
lbl_803EC838:
	.double 3.0
