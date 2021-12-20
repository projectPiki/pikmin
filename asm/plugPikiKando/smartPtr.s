.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__12RefCountableFv
__ct__12RefCountableFv:
/* 800E4338 000E1298  3C 80 80 2C */	lis r4, __vt__12RefCountable@ha
/* 800E433C 000E129C  38 04 B1 9C */	addi r0, r4, __vt__12RefCountable@l
/* 800E4340 000E12A0  90 03 00 00 */	stw r0, 0(r3)
/* 800E4344 000E12A4  38 00 00 00 */	li r0, 0
/* 800E4348 000E12A8  90 03 00 04 */	stw r0, 4(r3)
/* 800E434C 000E12AC  4E 80 00 20 */	blr 

.global clearCnt__12RefCountableFv
clearCnt__12RefCountableFv:
/* 800E4350 000E12B0  38 00 00 00 */	li r0, 0
/* 800E4354 000E12B4  90 03 00 04 */	stw r0, 4(r3)
/* 800E4358 000E12B8  4E 80 00 20 */	blr 

.global addCnt__12RefCountableFv
addCnt__12RefCountableFv:
/* 800E435C 000E12BC  80 83 00 04 */	lwz r4, 4(r3)
/* 800E4360 000E12C0  38 04 00 01 */	addi r0, r4, 1
/* 800E4364 000E12C4  90 03 00 04 */	stw r0, 4(r3)
/* 800E4368 000E12C8  4E 80 00 20 */	blr 

.global subCnt__12RefCountableFv
subCnt__12RefCountableFv:
/* 800E436C 000E12CC  80 83 00 04 */	lwz r4, 4(r3)
/* 800E4370 000E12D0  38 04 FF FF */	addi r0, r4, -1
/* 800E4374 000E12D4  90 03 00 04 */	stw r0, 4(r3)
/* 800E4378 000E12D8  80 03 00 04 */	lwz r0, 4(r3)
/* 800E437C 000E12DC  2C 00 00 00 */	cmpwi r0, 0
/* 800E4380 000E12E0  4C 80 00 20 */	bgelr 
/* 800E4384 000E12E4  38 00 00 00 */	li r0, 0
/* 800E4388 000E12E8  90 03 00 04 */	stw r0, 4(r3)
/* 800E438C 000E12EC  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BB170:
	.asciz "smartPtr.cpp"
.balign 4
lbl_802BB180:
	.asciz "smartPtr"
.balign 4
lbl_802BB18C:
	.asciz "RefCountable"
.balign 4
.global __vt__12RefCountable
__vt__12RefCountable:
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__12RefCountable:
	.4byte lbl_802BB18C
	.4byte 0
