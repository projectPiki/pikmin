.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ptmf_scall
__ptmf_scall:
/* 80214D30 00211C90  80 0C 00 00 */	lwz r0, 0(r12)
/* 80214D34 00211C94  81 6C 00 04 */	lwz r11, 4(r12)
/* 80214D38 00211C98  81 8C 00 08 */	lwz r12, 8(r12)
/* 80214D3C 00211C9C  7C 63 02 14 */	add r3, r3, r0
/* 80214D40 00211CA0  2C 0B 00 00 */	cmpwi r11, 0
/* 80214D44 00211CA4  41 80 00 0C */	blt lbl_80214D50
/* 80214D48 00211CA8  7D 83 60 2E */	lwzx r12, r3, r12
/* 80214D4C 00211CAC  7D 8C 58 2E */	lwzx r12, r12, r11
lbl_80214D50:
/* 80214D50 00211CB0  7D 89 03 A6 */	mtctr r12
/* 80214D54 00211CB4  4E 80 04 20 */	bctr 

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.balign 0x8
.global __ptmf_null
__ptmf_null:
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
