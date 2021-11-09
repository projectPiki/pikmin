.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global PPCMfmsr
PPCMfmsr:
/* 801F5944 001F28A4  7C 60 00 A6 */	mfmsr r3
/* 801F5948 001F28A8  4E 80 00 20 */	blr 

.global PPCMtmsr
PPCMtmsr:
/* 801F594C 001F28AC  7C 60 01 24 */	mtmsr r3
/* 801F5950 001F28B0  4E 80 00 20 */	blr 

.global PPCMfhid0
PPCMfhid0:
/* 801F5954 001F28B4  7C 70 FA A6 */	mfspr r3, 0x3f0
/* 801F5958 001F28B8  4E 80 00 20 */	blr 

.global PPCMfl2cr
PPCMfl2cr:
/* 801F595C 001F28BC  7C 79 FA A6 */	mfspr r3, 0x3f9
/* 801F5960 001F28C0  4E 80 00 20 */	blr 

.global PPCMtl2cr
PPCMtl2cr:
/* 801F5964 001F28C4  7C 79 FB A6 */	mtspr 0x3f9, r3
/* 801F5968 001F28C8  4E 80 00 20 */	blr 

.global PPCMtdec
PPCMtdec:
/* 801F596C 001F28CC  7C 76 03 A6 */	mtspr 0x16, r3
/* 801F5970 001F28D0  4E 80 00 20 */	blr 

.global PPCSync
PPCSync:
/* 801F5974 001F28D4  44 00 00 02 */	sc 
/* 801F5978 001F28D8  4E 80 00 20 */	blr 

.global PPCHalt
PPCHalt:
/* 801F597C 001F28DC  7C 00 04 AC */	sync 0
lbl_801F5980:
/* 801F5980 001F28E0  60 00 00 00 */	nop 
/* 801F5984 001F28E4  38 60 00 00 */	li r3, 0
/* 801F5988 001F28E8  60 00 00 00 */	nop 
/* 801F598C 001F28EC  4B FF FF F4 */	b lbl_801F5980

.global PPCMfhid2
PPCMfhid2:
/* 801F5990 001F28F0  7C 78 E2 A6 */	mfspr r3, 0x398
/* 801F5994 001F28F4  4E 80 00 20 */	blr 

.global PPCMthid2
PPCMthid2:
/* 801F5998 001F28F8  7C 78 E3 A6 */	mtspr 0x398, r3
/* 801F599C 001F28FC  4E 80 00 20 */	blr 

.global PPCMtwpar
PPCMtwpar:
/* 801F59A0 001F2900  7C 79 E3 A6 */	mtspr 0x399, r3
/* 801F59A4 001F2904  4E 80 00 20 */	blr 
