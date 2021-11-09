.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __OSModuleInit
__OSModuleInit:
/* 801F979C 001F66FC  3C 80 80 00 */	lis r4, 0x800030CC@ha
/* 801F97A0 001F6700  38 00 00 00 */	li r0, 0
/* 801F97A4 001F6704  90 04 30 CC */	stw r0, 0x800030CC@l(r4)
/* 801F97A8 001F6708  90 04 30 C8 */	stw r0, 0x30c8(r4)
/* 801F97AC 001F670C  90 04 30 D0 */	stw r0, 0x30d0(r4)
/* 801F97B0 001F6710  4E 80 00 20 */	blr 
