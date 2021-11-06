.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global abs
abs:
/* 80215CA0 00212C00  2C 03 00 00 */	cmpwi r3, 0
/* 80215CA4 00212C04  4C 80 00 20 */	bgelr 
/* 80215CA8 00212C08  7C 63 00 D0 */	neg r3, r3
/* 80215CAC 00212C0C  4E 80 00 20 */	blr 
