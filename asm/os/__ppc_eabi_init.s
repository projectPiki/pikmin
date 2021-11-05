.include "macros.inc"

.section .init, "ax"  # 0x80003100 - 0x800054C0
.global __init_hardware
__init_hardware:
/* 800032CC 000002CC  7C 00 00 A6 */	mfmsr r0
/* 800032D0 000002D0  60 00 20 00 */	ori r0, r0, 0x2000
/* 800032D4 000002D4  7C 00 01 24 */	mtmsr r0
/* 800032D8 000002D8  7F E8 02 A6 */	mflr r31
/* 800032DC 000002DC  48 1F 2D 99 */	bl __OSPSInit
/* 800032E0 000002E0  48 1F 3C 55 */	bl __OSCacheInit
/* 800032E4 000002E4  7F E8 03 A6 */	mtlr r31
/* 800032E8 000002E8  4E 80 00 20 */	blr 

.global __flush_cache
__flush_cache:
/* 800032EC 000002EC  3C A0 FF FF */	lis r5, 0xFFFFFFF1@h
/* 800032F0 000002F0  60 A5 FF F1 */	ori r5, r5, 0xFFFFFFF1@l
/* 800032F4 000002F4  7C A5 18 38 */	and r5, r5, r3
/* 800032F8 000002F8  7C 65 18 50 */	subf r3, r5, r3
/* 800032FC 000002FC  7C 84 1A 14 */	add r4, r4, r3
lbl_80003300:
/* 80003300 00000300  7C 00 28 6C */	dcbst 0, r5
/* 80003304 00000304  7C 00 04 AC */	sync 0
/* 80003308 00000308  7C 00 2F AC */	icbi 0, r5
/* 8000330C 0000030C  30 A5 00 08 */	addic r5, r5, 8
/* 80003310 00000310  34 84 FF F8 */	addic. r4, r4, -8
/* 80003314 00000314  40 80 FF EC */	bge lbl_80003300
/* 80003318 00000318  4C 00 01 2C */	isync 
/* 8000331C 0000031C  4E 80 00 20 */	blr 
