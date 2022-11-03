.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global DBInit
DBInit:
/* 801FDAA8 001FAA08  3C 80 80 00 */	lis r4, 0x80000040@ha
/* 801FDAAC 001FAA0C  38 04 00 40 */	addi r0, r4, 0x80000040@l
/* 801FDAB0 001FAA10  3C 60 80 20 */	lis r3, __DBExceptionDestination@ha
/* 801FDAB4 001FAA14  90 0D 32 48 */	stw r0, __DBInterface@sda21(r13)
/* 801FDAB8 001FAA18  38 63 DB 18 */	addi r3, r3, __DBExceptionDestination@l
/* 801FDABC 001FAA1C  3C 03 80 00 */	addis r0, r3, 0x8000
/* 801FDAC0 001FAA20  90 04 00 48 */	stw r0, 0x48(r4)
/* 801FDAC4 001FAA24  38 00 00 01 */	li r0, 1
/* 801FDAC8 001FAA28  90 0D 32 4C */	stw r0, DBVerbose@sda21(r13)
/* 801FDACC 001FAA2C  4E 80 00 20 */	blr 

.global __DBExceptionDestinationAux
__DBExceptionDestinationAux:
/* 801FDAD0 001FAA30  7C 08 02 A6 */	mflr r0
/* 801FDAD4 001FAA34  3C 60 80 2F */	lis r3, lbl_802E8448@ha
/* 801FDAD8 001FAA38  90 01 00 04 */	stw r0, 4(r1)
/* 801FDADC 001FAA3C  38 63 84 48 */	addi r3, r3, lbl_802E8448@l
/* 801FDAE0 001FAA40  4C C6 31 82 */	crclr 6
/* 801FDAE4 001FAA44  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801FDAE8 001FAA48  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801FDAEC 001FAA4C  80 80 00 C0 */	lwz r4, 0xc0(0)
/* 801FDAF0 001FAA50  3F E4 80 00 */	addis r31, r4, 0x8000
/* 801FDAF4 001FAA54  4B FF 9D 9D */	bl OSReport
/* 801FDAF8 001FAA58  7F E3 FB 78 */	mr r3, r31
/* 801FDAFC 001FAA5C  4B FF 9A 21 */	bl OSDumpContext
/* 801FDB00 001FAA60  4B FF 7E 7D */	bl PPCHalt
/* 801FDB04 001FAA64  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801FDB08 001FAA68  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801FDB0C 001FAA6C  38 21 00 18 */	addi r1, r1, 0x18
/* 801FDB10 001FAA70  7C 08 03 A6 */	mtlr r0
/* 801FDB14 001FAA74  4E 80 00 20 */	blr 

.global __DBExceptionDestination
__DBExceptionDestination:
/* 801FDB18 001FAA78  7C 60 00 A6 */	mfmsr r3
/* 801FDB1C 001FAA7C  60 63 00 30 */	ori r3, r3, 0x30
/* 801FDB20 001FAA80  7C 60 01 24 */	mtmsr r3
/* 801FDB24 001FAA84  4B FF FF AC */	b __DBExceptionDestinationAux

.global __DBIsExceptionMarked
__DBIsExceptionMarked:
/* 801FDB28 001FAA88  80 8D 32 48 */	lwz r4, __DBInterface@sda21(r13)
/* 801FDB2C 001FAA8C  54 60 06 3E */	clrlwi r0, r3, 0x18
/* 801FDB30 001FAA90  38 60 00 01 */	li r3, 1
/* 801FDB34 001FAA94  80 84 00 04 */	lwz r4, 4(r4)
/* 801FDB38 001FAA98  7C 60 00 30 */	slw r0, r3, r0
/* 801FDB3C 001FAA9C  7C 83 00 38 */	and r3, r4, r0
/* 801FDB40 001FAAA0  4E 80 00 20 */	blr 

.global DBPrintf
DBPrintf:
/* 801FDB44 001FAAA4  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 801FDB48 001FAAA8  40 86 00 24 */	bne cr1, .L_801FDB6C
/* 801FDB4C 001FAAAC  D8 21 00 28 */	stfd f1, 0x28(r1)
/* 801FDB50 001FAAB0  D8 41 00 30 */	stfd f2, 0x30(r1)
/* 801FDB54 001FAAB4  D8 61 00 38 */	stfd f3, 0x38(r1)
/* 801FDB58 001FAAB8  D8 81 00 40 */	stfd f4, 0x40(r1)
/* 801FDB5C 001FAABC  D8 A1 00 48 */	stfd f5, 0x48(r1)
/* 801FDB60 001FAAC0  D8 C1 00 50 */	stfd f6, 0x50(r1)
/* 801FDB64 001FAAC4  D8 E1 00 58 */	stfd f7, 0x58(r1)
/* 801FDB68 001FAAC8  D9 01 00 60 */	stfd f8, 0x60(r1)
.L_801FDB6C:
/* 801FDB6C 001FAACC  90 61 00 08 */	stw r3, 8(r1)
/* 801FDB70 001FAAD0  90 81 00 0C */	stw r4, 0xc(r1)
/* 801FDB74 001FAAD4  90 A1 00 10 */	stw r5, 0x10(r1)
/* 801FDB78 001FAAD8  90 C1 00 14 */	stw r6, 0x14(r1)
/* 801FDB7C 001FAADC  90 E1 00 18 */	stw r7, 0x18(r1)
/* 801FDB80 001FAAE0  91 01 00 1C */	stw r8, 0x1c(r1)
/* 801FDB84 001FAAE4  91 21 00 20 */	stw r9, 0x20(r1)
/* 801FDB88 001FAAE8  91 41 00 24 */	stw r10, 0x24(r1)
/* 801FDB8C 001FAAEC  38 21 00 70 */	addi r1, r1, 0x70
/* 801FDB90 001FAAF0  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802E8448:
	.asciz "DBExceptionDestination\n"
.balign 4

.section .sbss, "wa"
.balign 8
.global __DBInterface
__DBInterface:
	.skip 0x4
.global DBVerbose
DBVerbose:
	.skip 0x4
