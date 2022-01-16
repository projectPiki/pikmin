.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global TRKInitializeDispatcher
TRKInitializeDispatcher:
/* 8021CEE0 00219E40  3C 60 80 3D */	lis r3, gTRKDispatchTableSize@ha
/* 8021CEE4 00219E44  38 00 00 20 */	li r0, 0x20
/* 8021CEE8 00219E48  90 03 5C E8 */	stw r0, gTRKDispatchTableSize@l(r3)
/* 8021CEEC 00219E4C  38 60 00 00 */	li r3, 0
/* 8021CEF0 00219E50  4E 80 00 20 */	blr 

.global TRKDispatchMessage
TRKDispatchMessage:
/* 8021CEF4 00219E54  7C 08 02 A6 */	mflr r0
/* 8021CEF8 00219E58  38 80 00 00 */	li r4, 0
/* 8021CEFC 00219E5C  90 01 00 04 */	stw r0, 4(r1)
/* 8021CF00 00219E60  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8021CF04 00219E64  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8021CF08 00219E68  3B E0 05 00 */	li r31, 0x500
/* 8021CF0C 00219E6C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8021CF10 00219E70  3B C3 00 00 */	addi r30, r3, 0
/* 8021CF14 00219E74  4B FF F7 A9 */	bl TRKSetBufferPosition
/* 8021CF18 00219E78  38 7E 00 00 */	addi r3, r30, 0
/* 8021CF1C 00219E7C  38 81 00 08 */	addi r4, r1, 8
/* 8021CF20 00219E80  4B FF FB 21 */	bl TRKReadBuffer1_ui8
/* 8021CF24 00219E84  3C 60 80 3D */	lis r3, gTRKDispatchTableSize@ha
/* 8021CF28 00219E88  88 81 00 08 */	lbz r4, 8(r1)
/* 8021CF2C 00219E8C  80 03 5C E8 */	lwz r0, gTRKDispatchTableSize@l(r3)
/* 8021CF30 00219E90  7C 04 00 40 */	cmplw r4, r0
/* 8021CF34 00219E94  40 80 00 28 */	bge lbl_8021CF5C
/* 8021CF38 00219E98  3C 60 80 2F */	lis r3, gTRKDispatchTable@ha
/* 8021CF3C 00219E9C  54 84 10 3A */	slwi r4, r4, 2
/* 8021CF40 00219EA0  38 03 94 C0 */	addi r0, r3, gTRKDispatchTable@l
/* 8021CF44 00219EA4  7C 60 22 14 */	add r3, r0, r4
/* 8021CF48 00219EA8  81 83 00 00 */	lwz r12, 0(r3)
/* 8021CF4C 00219EAC  38 7E 00 00 */	addi r3, r30, 0
/* 8021CF50 00219EB0  7D 88 03 A6 */	mtlr r12
/* 8021CF54 00219EB4  4E 80 00 21 */	blrl 
/* 8021CF58 00219EB8  7C 7F 1B 78 */	mr r31, r3
lbl_8021CF5C:
/* 8021CF5C 00219EBC  7F E3 FB 78 */	mr r3, r31
/* 8021CF60 00219EC0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8021CF64 00219EC4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8021CF68 00219EC8  38 21 00 18 */	addi r1, r1, 0x18
/* 8021CF6C 00219ECC  80 01 00 04 */	lwz r0, 4(r1)
/* 8021CF70 00219ED0  7C 08 03 A6 */	mtlr r0
/* 8021CF74 00219ED4  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.global gTRKDispatchTable
gTRKDispatchTable:
	.4byte TRKDoUnsupported
	.4byte TRKDoConnect
	.4byte TRKDoDisconnect
	.4byte TRKDoReset
	.4byte TRKDoVersions
	.4byte TRKDoSupportMask
	.4byte TRKDoCPUType
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoReadMemory
	.4byte TRKDoWriteMemory
	.4byte TRKDoReadRegisters
	.4byte TRKDoWriteRegisters
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoFlushCache
	.4byte TRKDoUnsupported
	.4byte TRKDoContinue
	.4byte TRKDoStep
	.4byte TRKDoStop
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte TRKDoUnsupported
	.4byte 0x00000000
