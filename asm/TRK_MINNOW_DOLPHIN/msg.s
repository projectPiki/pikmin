.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global TRKMessageSend
TRKMessageSend:
/* 8021C4A4 00219404  7C 08 02 A6 */	mflr r0
/* 8021C4A8 00219408  90 01 00 04 */	stw r0, 4(r1)
/* 8021C4AC 0021940C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021C4B0 00219410  80 83 00 08 */	lwz r4, 8(r3)
/* 8021C4B4 00219414  38 63 00 10 */	addi r3, r3, 0x10
/* 8021C4B8 00219418  48 00 42 39 */	bl TRKWriteUARTN
/* 8021C4BC 0021941C  38 21 00 08 */	addi r1, r1, 8
/* 8021C4C0 00219420  80 01 00 04 */	lwz r0, 4(r1)
/* 8021C4C4 00219424  7C 08 03 A6 */	mtlr r0
/* 8021C4C8 00219428  4E 80 00 20 */	blr 
