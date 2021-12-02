.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__9TekiEventFiP4Teki
__ct__9TekiEventFiP4Teki:
/* 8014A398 001472F8  7C 08 02 A6 */	mflr r0
/* 8014A39C 001472FC  38 C0 00 00 */	li r6, 0
/* 8014A3A0 00147300  90 01 00 04 */	stw r0, 4(r1)
/* 8014A3A4 00147304  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8014A3A8 00147308  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8014A3AC 0014730C  3B E3 00 00 */	addi r31, r3, 0
/* 8014A3B0 00147310  48 00 00 4D */	bl init__9TekiEventFiP4TekiP8Creature
/* 8014A3B4 00147314  7F E3 FB 78 */	mr r3, r31
/* 8014A3B8 00147318  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8014A3BC 0014731C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8014A3C0 00147320  38 21 00 20 */	addi r1, r1, 0x20
/* 8014A3C4 00147324  7C 08 03 A6 */	mtlr r0
/* 8014A3C8 00147328  4E 80 00 20 */	blr 

.global __ct__9TekiEventFiP4TekiP8Creature
__ct__9TekiEventFiP4TekiP8Creature:
/* 8014A3CC 0014732C  7C 08 02 A6 */	mflr r0
/* 8014A3D0 00147330  90 01 00 04 */	stw r0, 4(r1)
/* 8014A3D4 00147334  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8014A3D8 00147338  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8014A3DC 0014733C  7C 7F 1B 78 */	mr r31, r3
/* 8014A3E0 00147340  48 00 00 1D */	bl init__9TekiEventFiP4TekiP8Creature
/* 8014A3E4 00147344  7F E3 FB 78 */	mr r3, r31
/* 8014A3E8 00147348  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8014A3EC 0014734C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8014A3F0 00147350  38 21 00 20 */	addi r1, r1, 0x20
/* 8014A3F4 00147354  7C 08 03 A6 */	mtlr r0
/* 8014A3F8 00147358  4E 80 00 20 */	blr 

.global init__9TekiEventFiP4TekiP8Creature
init__9TekiEventFiP4TekiP8Creature:
/* 8014A3FC 0014735C  90 83 00 00 */	stw r4, 0(r3)
/* 8014A400 00147360  90 A3 00 04 */	stw r5, 4(r3)
/* 8014A404 00147364  90 C3 00 08 */	stw r6, 8(r3)
/* 8014A408 00147368  4E 80 00 20 */	blr 
