.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global TRK_flush_cache
TRK_flush_cache:
/* 8021E788 0021B6E8  3C A0 FF FF */	lis r5, 0xFFFFFFF1@h
/* 8021E78C 0021B6EC  60 A5 FF F1 */	ori r5, r5, 0xFFFFFFF1@l
/* 8021E790 0021B6F0  7C A5 18 38 */	and r5, r5, r3
/* 8021E794 0021B6F4  7C 65 18 50 */	subf r3, r5, r3
/* 8021E798 0021B6F8  7C 84 1A 14 */	add r4, r4, r3
lbl_8021E79C:
/* 8021E79C 0021B6FC  7C 00 28 6C */	dcbst 0, r5
/* 8021E7A0 0021B700  7C 00 28 AC */	dcbf 0, r5
/* 8021E7A4 0021B704  7C 00 04 AC */	sync 0
/* 8021E7A8 0021B708  7C 00 2F AC */	icbi 0, r5
/* 8021E7AC 0021B70C  30 A5 00 08 */	addic r5, r5, 8
/* 8021E7B0 0021B710  34 84 FF F8 */	addic. r4, r4, -8
/* 8021E7B4 0021B714  40 80 FF E8 */	bge lbl_8021E79C
/* 8021E7B8 0021B718  4C 00 01 2C */	isync 
/* 8021E7BC 0021B71C  4E 80 00 20 */	blr 
