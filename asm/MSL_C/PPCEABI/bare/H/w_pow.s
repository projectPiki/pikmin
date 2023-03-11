.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn pow, global
/* 8021B708 00218668  7C 08 02 A6 */	mflr r0
/* 8021B70C 0021866C  90 01 00 04 */	stw r0, 4(r1)
/* 8021B710 00218670  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021B714 00218674  4B FF F2 9D */	bl __ieee754_pow
/* 8021B718 00218678  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021B71C 0021867C  38 21 00 08 */	addi r1, r1, 8
/* 8021B720 00218680  7C 08 03 A6 */	mtlr r0
/* 8021B724 00218684  4E 80 00 20 */	blr 
.endfn pow
