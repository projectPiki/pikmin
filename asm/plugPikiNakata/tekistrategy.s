.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__12TekiStrategyFv
__ct__12TekiStrategyFv:
/* 8014D1A4 0014A104  3C 80 80 2D */	lis r4, __vt__12TekiStrategy@ha
/* 8014D1A8 0014A108  38 04 E6 E4 */	addi r0, r4, __vt__12TekiStrategy@l
/* 8014D1AC 0014A10C  90 03 00 00 */	stw r0, 0(r3)
/* 8014D1B0 0014A110  4E 80 00 20 */	blr 

.global start__12TekiStrategyFR4Teki
start__12TekiStrategyFR4Teki:
/* 8014D1B4 0014A114  4E 80 00 20 */	blr 

.global act__12TekiStrategyFR4Teki
act__12TekiStrategyFR4Teki:
/* 8014D1B8 0014A118  4E 80 00 20 */	blr 

.global eventPerformed__12TekiStrategyFR9TekiEvent
eventPerformed__12TekiStrategyFR9TekiEvent:
/* 8014D1BC 0014A11C  4E 80 00 20 */	blr 

.global createEffect__12TekiStrategyFR4Tekii
createEffect__12TekiStrategyFR4Tekii:
/* 8014D1C0 0014A120  4E 80 00 20 */	blr 

.global draw__12TekiStrategyFR4TekiR8Graphics
draw__12TekiStrategyFR4TekiR8Graphics:
/* 8014D1C4 0014A124  7C 08 02 A6 */	mflr r0
/* 8014D1C8 0014A128  7C 83 23 78 */	mr r3, r4
/* 8014D1CC 0014A12C  90 01 00 04 */	stw r0, 4(r1)
/* 8014D1D0 0014A130  94 21 FF F8 */	stwu r1, -8(r1)
/* 8014D1D4 0014A134  81 84 00 00 */	lwz r12, 0(r4)
/* 8014D1D8 0014A138  7C A4 2B 78 */	mr r4, r5
/* 8014D1DC 0014A13C  81 8C 01 AC */	lwz r12, 0x1ac(r12)
/* 8014D1E0 0014A140  7D 88 03 A6 */	mtlr r12
/* 8014D1E4 0014A144  4E 80 00 21 */	blrl 
/* 8014D1E8 0014A148  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8014D1EC 0014A14C  38 21 00 08 */	addi r1, r1, 8
/* 8014D1F0 0014A150  7C 08 03 A6 */	mtlr r0
/* 8014D1F4 0014A154  4E 80 00 20 */	blr 

.global drawDebugInfo__12TekiStrategyFR4TekiR8Graphics
drawDebugInfo__12TekiStrategyFR4TekiR8Graphics:
/* 8014D1F8 0014A158  7C 08 02 A6 */	mflr r0
/* 8014D1FC 0014A15C  7C 83 23 78 */	mr r3, r4
/* 8014D200 0014A160  90 01 00 04 */	stw r0, 4(r1)
/* 8014D204 0014A164  94 21 FF F8 */	stwu r1, -8(r1)
/* 8014D208 0014A168  81 84 00 00 */	lwz r12, 0(r4)
/* 8014D20C 0014A16C  7C A4 2B 78 */	mr r4, r5
/* 8014D210 0014A170  81 8C 01 B8 */	lwz r12, 0x1b8(r12)
/* 8014D214 0014A174  7D 88 03 A6 */	mtlr r12
/* 8014D218 0014A178  4E 80 00 21 */	blrl 
/* 8014D21C 0014A17C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8014D220 0014A180  38 21 00 08 */	addi r1, r1, 8
/* 8014D224 0014A184  7C 08 03 A6 */	mtlr r0
/* 8014D228 0014A188  4E 80 00 20 */	blr 

.global interact__12TekiStrategyFR4TekiR18TekiInteractionKey
interact__12TekiStrategyFR4TekiR18TekiInteractionKey:
/* 8014D22C 0014A18C  7C 08 02 A6 */	mflr r0
/* 8014D230 0014A190  7C 83 23 78 */	mr r3, r4
/* 8014D234 0014A194  90 01 00 04 */	stw r0, 4(r1)
/* 8014D238 0014A198  94 21 FF F8 */	stwu r1, -8(r1)
/* 8014D23C 0014A19C  81 84 00 00 */	lwz r12, 0(r4)
/* 8014D240 0014A1A0  7C A4 2B 78 */	mr r4, r5
/* 8014D244 0014A1A4  81 8C 01 A8 */	lwz r12, 0x1a8(r12)
/* 8014D248 0014A1A8  7D 88 03 A6 */	mtlr r12
/* 8014D24C 0014A1AC  4E 80 00 21 */	blrl 
/* 8014D250 0014A1B0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8014D254 0014A1B4  38 21 00 08 */	addi r1, r1, 8
/* 8014D258 0014A1B8  7C 08 03 A6 */	mtlr r0
/* 8014D25C 0014A1BC  4E 80 00 20 */	blr 

.global spawnCorpseParts__12TekiStrategyFR4Teki
spawnCorpseParts__12TekiStrategyFR4Teki:
/* 8014D260 0014A1C0  4E 80 00 20 */	blr 

.global __ct__17TekiStrategyTableFi
__ct__17TekiStrategyTableFi:
/* 8014D264 0014A1C4  7C 08 02 A6 */	mflr r0
/* 8014D268 0014A1C8  90 01 00 04 */	stw r0, 4(r1)
/* 8014D26C 0014A1CC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8014D270 0014A1D0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8014D274 0014A1D4  7C 7F 1B 78 */	mr r31, r3
/* 8014D278 0014A1D8  90 83 00 00 */	stw r4, 0(r3)
/* 8014D27C 0014A1DC  80 03 00 00 */	lwz r0, 0(r3)
/* 8014D280 0014A1E0  54 03 10 3A */	slwi r3, r0, 2
/* 8014D284 0014A1E4  4B EF 9D 81 */	bl alloc__6SystemFUl
/* 8014D288 0014A1E8  38 A0 00 00 */	li r5, 0
/* 8014D28C 0014A1EC  90 7F 00 04 */	stw r3, 4(r31)
/* 8014D290 0014A1F0  38 85 00 00 */	addi r4, r5, 0
/* 8014D294 0014A1F4  38 C0 00 00 */	li r6, 0
/* 8014D298 0014A1F8  48 00 00 14 */	b .L_8014D2AC
.L_8014D29C:
/* 8014D29C 0014A1FC  80 7F 00 04 */	lwz r3, 4(r31)
/* 8014D2A0 0014A200  38 C6 00 01 */	addi r6, r6, 1
/* 8014D2A4 0014A204  7C 83 29 2E */	stwx r4, r3, r5
/* 8014D2A8 0014A208  38 A5 00 04 */	addi r5, r5, 4
.L_8014D2AC:
/* 8014D2AC 0014A20C  80 1F 00 00 */	lwz r0, 0(r31)
/* 8014D2B0 0014A210  7C 06 00 00 */	cmpw r6, r0
/* 8014D2B4 0014A214  41 80 FF E8 */	blt .L_8014D29C
/* 8014D2B8 0014A218  7F E3 FB 78 */	mr r3, r31
/* 8014D2BC 0014A21C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8014D2C0 0014A220  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8014D2C4 0014A224  38 21 00 20 */	addi r1, r1, 0x20
/* 8014D2C8 0014A228  7C 08 03 A6 */	mtlr r0
/* 8014D2CC 0014A22C  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802CE6B0:
	.asciz "tekistrategy.cpp"
.balign 4
lbl_802CE6C4:
	.asciz "tekistrategy"
.balign 4
lbl_802CE6D4:
	.asciz "TekiStrategy"
.balign 4
.global __vt__12TekiStrategy
__vt__12TekiStrategy:
	.4byte __RTTI__12TekiStrategy
	.4byte 0
	.4byte start__12TekiStrategyFR4Teki
	.4byte act__12TekiStrategyFR4Teki
	.4byte eventPerformed__12TekiStrategyFR9TekiEvent
	.4byte createEffect__12TekiStrategyFR4Tekii
	.4byte draw__12TekiStrategyFR4TekiR8Graphics
	.4byte drawDebugInfo__12TekiStrategyFR4TekiR8Graphics
	.4byte interact__12TekiStrategyFR4TekiR18TekiInteractionKey
	.4byte spawnCorpseParts__12TekiStrategyFR4Teki

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__12TekiStrategy:
	.4byte lbl_802CE6D4
	.4byte 0
