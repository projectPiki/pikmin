.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__8PikiInfoFv
__ct__8PikiInfoFv:
/* 80119CE4 00116C44  38 00 00 00 */	li r0, 0
/* 80119CE8 00116C48  90 03 00 04 */	stw r0, 4(r3)
/* 80119CEC 00116C4C  90 03 00 00 */	stw r0, 0(r3)
/* 80119CF0 00116C50  90 03 00 08 */	stw r0, 8(r3)
/* 80119CF4 00116C54  90 03 00 18 */	stw r0, 0x18(r3)
/* 80119CF8 00116C58  90 03 00 14 */	stw r0, 0x14(r3)
/* 80119CFC 00116C5C  90 03 00 10 */	stw r0, 0x10(r3)
/* 80119D00 00116C60  90 03 00 0C */	stw r0, 0xc(r3)
/* 80119D04 00116C64  4E 80 00 20 */	blr 

.global addFormationPiki__8PikiInfoFv
addFormationPiki__8PikiInfoFv:
/* 80119D08 00116C68  80 83 00 00 */	lwz r4, 0(r3)
/* 80119D0C 00116C6C  38 04 00 01 */	addi r0, r4, 1
/* 80119D10 00116C70  90 03 00 00 */	stw r0, 0(r3)
/* 80119D14 00116C74  80 03 00 04 */	lwz r0, 4(r3)
/* 80119D18 00116C78  80 83 00 00 */	lwz r4, 0(r3)
/* 80119D1C 00116C7C  7C 00 20 00 */	cmpw r0, r4
/* 80119D20 00116C80  4C 80 00 20 */	bgelr 
/* 80119D24 00116C84  90 83 00 04 */	stw r4, 4(r3)
/* 80119D28 00116C88  4E 80 00 20 */	blr 

.global subFormationPiki__8PikiInfoFv
subFormationPiki__8PikiInfoFv:
/* 80119D2C 00116C8C  80 A3 00 00 */	lwz r5, 0(r3)
/* 80119D30 00116C90  38 05 FF FF */	addi r0, r5, -1
/* 80119D34 00116C94  90 03 00 00 */	stw r0, 0(r3)
/* 80119D38 00116C98  4E 80 00 20 */	blr 

.section .sbss, "wa"
.balign 8
.global pikiInfo
pikiInfo:
	.skip 0x4
