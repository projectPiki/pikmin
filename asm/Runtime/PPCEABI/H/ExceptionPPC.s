.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __unregister_fragment
__unregister_fragment:
/* 80214D58 00211CB8  2C 03 00 00 */	cmpwi r3, 0
/* 80214D5C 00211CBC  41 80 00 2C */	blt .L_80214D88
/* 80214D60 00211CC0  2C 03 00 01 */	cmpwi r3, 1
/* 80214D64 00211CC4  40 80 00 24 */	bge .L_80214D88
/* 80214D68 00211CC8  1C 83 00 0C */	mulli r4, r3, 0xc
/* 80214D6C 00211CCC  3C 60 80 3D */	lis r3, fragmentinfo@ha
/* 80214D70 00211CD0  38 03 40 E0 */	addi r0, r3, fragmentinfo@l
/* 80214D74 00211CD4  7C 60 22 14 */	add r3, r0, r4
/* 80214D78 00211CD8  38 00 00 00 */	li r0, 0
/* 80214D7C 00211CDC  90 03 00 00 */	stw r0, 0(r3)
/* 80214D80 00211CE0  90 03 00 04 */	stw r0, 4(r3)
/* 80214D84 00211CE4  90 03 00 08 */	stw r0, 8(r3)
.L_80214D88:
/* 80214D88 00211CE8  4E 80 00 20 */	blr 

.global __register_fragment
__register_fragment:
/* 80214D8C 00211CEC  3C A0 80 3D */	lis r5, fragmentinfo@ha
/* 80214D90 00211CF0  38 A5 40 E0 */	addi r5, r5, fragmentinfo@l
/* 80214D94 00211CF4  48 00 00 04 */	b .L_80214D98
.L_80214D98:
/* 80214D98 00211CF8  48 00 00 04 */	b .L_80214D9C
.L_80214D9C:
/* 80214D9C 00211CFC  80 05 00 08 */	lwz r0, 8(r5)
/* 80214DA0 00211D00  2C 00 00 00 */	cmpwi r0, 0
/* 80214DA4 00211D04  40 82 00 1C */	bne .L_80214DC0
/* 80214DA8 00211D08  90 65 00 00 */	stw r3, 0(r5)
/* 80214DAC 00211D0C  38 00 00 01 */	li r0, 1
/* 80214DB0 00211D10  38 60 00 00 */	li r3, 0
/* 80214DB4 00211D14  90 85 00 04 */	stw r4, 4(r5)
/* 80214DB8 00211D18  90 05 00 08 */	stw r0, 8(r5)
/* 80214DBC 00211D1C  48 00 00 08 */	b .L_80214DC4
.L_80214DC0:
/* 80214DC0 00211D20  38 60 FF FF */	li r3, -1
.L_80214DC4:
/* 80214DC4 00211D24  4E 80 00 20 */	blr 
