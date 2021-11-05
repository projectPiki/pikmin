.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global TRKTargetContinue
TRKTargetContinue:
/* 802207B8 0021D718  7C 08 02 A6 */	mflr r0
/* 802207BC 0021D71C  38 60 00 00 */	li r3, 0
/* 802207C0 0021D720  90 01 00 04 */	stw r0, 4(r1)
/* 802207C4 0021D724  94 21 FF F8 */	stwu r1, -8(r1)
/* 802207C8 0021D728  4B FF F3 41 */	bl TRKTargetSetStopped
/* 802207CC 0021D72C  4B FF FF 99 */	bl UnreserveEXI2Port
/* 802207D0 0021D730  4B FF ED 35 */	bl TRKSwapAndGo
/* 802207D4 0021D734  4B FF FF 61 */	bl ReserveEXI2Port
/* 802207D8 0021D738  38 60 00 00 */	li r3, 0
/* 802207DC 0021D73C  38 21 00 08 */	addi r1, r1, 8
/* 802207E0 0021D740  80 01 00 04 */	lwz r0, 4(r1)
/* 802207E4 0021D744  7C 08 03 A6 */	mtlr r0
/* 802207E8 0021D748  4E 80 00 20 */	blr 
