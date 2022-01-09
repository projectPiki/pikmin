.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global exitCourse__11GlobalShapeFv
exitCourse__11GlobalShapeFv:
/* 8007F2B4 0007C214  38 00 00 00 */	li r0, 0
/* 8007F2B8 0007C218  90 0D 2F 50 */	stw r0, arrowShape__11GlobalShape@sda21(r13)
/* 8007F2BC 0007C21C  90 0D 2F 54 */	stw r0, markerShape__11GlobalShape@sda21(r13)
/* 8007F2C0 0007C220  90 0D 2F 58 */	stw r0, axisShape__11GlobalShape@sda21(r13)
/* 8007F2C4 0007C224  90 0D 2F 5C */	stw r0, enShape__11GlobalShape@sda21(r13)
/* 8007F2C8 0007C228  90 0D 2F 60 */	stw r0, markerShape2__11GlobalShape@sda21(r13)
/* 8007F2CC 0007C22C  90 0D 2F 64 */	stw r0, cursorShape__11GlobalShape@sda21(r13)
/* 8007F2D0 0007C230  4E 80 00 20 */	blr 

.global init__11GlobalShapeFv
init__11GlobalShapeFv:
/* 8007F2D4 0007C234  7C 08 02 A6 */	mflr r0
/* 8007F2D8 0007C238  3C 80 80 2B */	lis r4, lbl_802ADCD8@ha
/* 8007F2DC 0007C23C  90 01 00 04 */	stw r0, 4(r1)
/* 8007F2E0 0007C240  3C 60 80 3A */	lis r3, gameflow@ha
/* 8007F2E4 0007C244  38 A0 00 01 */	li r5, 1
/* 8007F2E8 0007C248  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8007F2EC 0007C24C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8007F2F0 0007C250  3B E3 D7 B8 */	addi r31, r3, gameflow@l
/* 8007F2F4 0007C254  38 7F 00 00 */	addi r3, r31, 0
/* 8007F2F8 0007C258  93 C1 00 08 */	stw r30, 8(r1)
/* 8007F2FC 0007C25C  3B C4 DC D8 */	addi r30, r4, lbl_802ADCD8@l
/* 8007F300 0007C260  38 9E 00 20 */	addi r4, r30, 0x20
/* 8007F304 0007C264  4B FD 3A 0D */	bl loadShape__8GameFlowFPcb
/* 8007F308 0007C268  90 6D 2F 60 */	stw r3, markerShape2__11GlobalShape@sda21(r13)
/* 8007F30C 0007C26C  38 7F 00 00 */	addi r3, r31, 0
/* 8007F310 0007C270  38 9E 00 3C */	addi r4, r30, 0x3c
/* 8007F314 0007C274  38 A0 00 01 */	li r5, 1
/* 8007F318 0007C278  4B FD 39 F9 */	bl loadShape__8GameFlowFPcb
/* 8007F31C 0007C27C  90 6D 2F 64 */	stw r3, cursorShape__11GlobalShape@sda21(r13)
/* 8007F320 0007C280  38 7F 00 00 */	addi r3, r31, 0
/* 8007F324 0007C284  38 9E 00 58 */	addi r4, r30, 0x58
/* 8007F328 0007C288  38 A0 00 01 */	li r5, 1
/* 8007F32C 0007C28C  4B FD 39 E5 */	bl loadShape__8GameFlowFPcb
/* 8007F330 0007C290  38 7F 00 00 */	addi r3, r31, 0
/* 8007F334 0007C294  38 9E 00 58 */	addi r4, r30, 0x58
/* 8007F338 0007C298  38 A0 00 01 */	li r5, 1
/* 8007F33C 0007C29C  4B FD 39 D5 */	bl loadShape__8GameFlowFPcb
/* 8007F340 0007C2A0  38 7F 00 00 */	addi r3, r31, 0
/* 8007F344 0007C2A4  38 9E 00 58 */	addi r4, r30, 0x58
/* 8007F348 0007C2A8  38 A0 00 01 */	li r5, 1
/* 8007F34C 0007C2AC  4B FD 39 C5 */	bl loadShape__8GameFlowFPcb
/* 8007F350 0007C2B0  38 7F 00 00 */	addi r3, r31, 0
/* 8007F354 0007C2B4  38 9E 00 70 */	addi r4, r30, 0x70
/* 8007F358 0007C2B8  38 A0 00 01 */	li r5, 1
/* 8007F35C 0007C2BC  4B FD 39 B5 */	bl loadShape__8GameFlowFPcb
/* 8007F360 0007C2C0  38 7F 00 00 */	addi r3, r31, 0
/* 8007F364 0007C2C4  38 9E 00 88 */	addi r4, r30, 0x88
/* 8007F368 0007C2C8  38 A0 00 01 */	li r5, 1
/* 8007F36C 0007C2CC  4B FD 39 A5 */	bl loadShape__8GameFlowFPcb
/* 8007F370 0007C2D0  38 7F 00 00 */	addi r3, r31, 0
/* 8007F374 0007C2D4  38 9E 00 58 */	addi r4, r30, 0x58
/* 8007F378 0007C2D8  38 A0 00 01 */	li r5, 1
/* 8007F37C 0007C2DC  4B FD 39 95 */	bl loadShape__8GameFlowFPcb
/* 8007F380 0007C2E0  38 7F 00 00 */	addi r3, r31, 0
/* 8007F384 0007C2E4  38 9E 00 58 */	addi r4, r30, 0x58
/* 8007F388 0007C2E8  38 A0 00 01 */	li r5, 1
/* 8007F38C 0007C2EC  4B FD 39 85 */	bl loadShape__8GameFlowFPcb
/* 8007F390 0007C2F0  38 7F 00 00 */	addi r3, r31, 0
/* 8007F394 0007C2F4  38 9E 00 58 */	addi r4, r30, 0x58
/* 8007F398 0007C2F8  38 A0 00 01 */	li r5, 1
/* 8007F39C 0007C2FC  4B FD 39 75 */	bl loadShape__8GameFlowFPcb
/* 8007F3A0 0007C300  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8007F3A4 0007C304  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8007F3A8 0007C308  83 C1 00 08 */	lwz r30, 8(r1)
/* 8007F3AC 0007C30C  38 21 00 10 */	addi r1, r1, 0x10
/* 8007F3B0 0007C310  7C 08 03 A6 */	mtlr r0
/* 8007F3B4 0007C314  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802ADCD8:
	.asciz "globalShapes.cpp"
.balign 4
lbl_802ADCEC:
	.asciz "globalShape"
.balign 4
lbl_802ADCF8:
	.asciz "shapes/cursor/marker.mod"
.balign 4
lbl_802ADD14:
	.asciz "shapes/cursor/cursor.mod"
.balign 4
lbl_802ADD30:
	.asciz "pikis/happas/leaf.mod"
.balign 4
lbl_802ADD48:
	.asciz "pikis/happas/bud.mod"
.balign 4
lbl_802ADD60:
	.asciz "pikis/happas/flower.mod"

.section .sbss, "wa"
.balign 8
.global arrowShape__11GlobalShape
arrowShape__11GlobalShape:
	.skip 4
.global markerShape__11GlobalShape
markerShape__11GlobalShape:
	.skip 4
.global axisShape__11GlobalShape
axisShape__11GlobalShape:
	.skip 4
.global enShape__11GlobalShape
enShape__11GlobalShape:
	.skip 4
.global markerShape2__11GlobalShape
markerShape2__11GlobalShape:
	.skip 4
.global cursorShape__11GlobalShape
cursorShape__11GlobalShape:
	.skip 4
