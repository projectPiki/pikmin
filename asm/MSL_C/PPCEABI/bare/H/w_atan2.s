.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn atan2, global
/* 8021B6E8 00218648  7C 08 02 A6 */	mflr r0
/* 8021B6EC 0021864C  90 01 00 04 */	stw r0, 4(r1)
/* 8021B6F0 00218650  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021B6F4 00218654  4B FF F0 25 */	bl __ieee754_atan2
/* 8021B6F8 00218658  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021B6FC 0021865C  38 21 00 08 */	addi r1, r1, 8
/* 8021B700 00218660  7C 08 03 A6 */	mtlr r0
/* 8021B704 00218664  4E 80 00 20 */	blr 
.endfn atan2
