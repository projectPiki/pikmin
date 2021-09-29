.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60

.global main
main:
/* 80005560 000024C0  7C 08 02 A6 */	mflr r0
/* 80005564 000024C4  90 01 00 04 */	stw r0, 4(r1)
/* 80005568 000024C8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000556C 000024CC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80005570 000024D0  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80005574 000024D4  48 04 07 A9 */	bl Initialise__6SystemFv
/* 80005578 000024D8  38 60 00 18 */	li r3, 0x18
/* 8000557C 000024DC  48 04 1A 89 */	bl alloc__6SystemFUl
/* 80005580 000024E0  3B E3 00 00 */	addi r31, r3, 0
/* 80005584 000024E4  7F E3 FB 79 */	or. r3, r31, r31
/* 80005588 000024E8  41 82 00 08 */	beq lbl_80005590
/* 8000558C 000024EC  48 03 B3 AD */	bl __ct__7NodeMgrFv
lbl_80005590:
/* 80005590 000024F0  93 ED 2D D8 */	stw r31, nodeMgr@sda21(r13)
/* 80005594 000024F4  38 60 00 54 */	li r3, 0x54
/* 80005598 000024F8  48 04 1A 6D */	bl alloc__6SystemFUl
/* 8000559C 000024FC  7C 7F 1B 79 */	or. r31, r3, r3
/* 800055A0 00002500  41 82 00 0C */	beq lbl_800055AC
/* 800055A4 00002504  7F E3 FB 78 */	mr r3, r31
/* 800055A8 00002508  48 05 A0 35 */	bl __ct__11PlugPikiAppFv
lbl_800055AC:
/* 800055AC 0000250C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800055B0 00002510  7F E4 FB 78 */	mr r4, r31
/* 800055B4 00002514  48 03 F6 01 */	bl run__6SystemFP7BaseApp
/* 800055B8 00002518  3C 60 80 22 */	lis r3, lbl_80222DC0@ha
/* 800055BC 0000251C  4C C6 31 82 */	crclr 6
/* 800055C0 00002520  3C 80 80 22 */	lis r4, lbl_80222DD0@ha
/* 800055C4 00002524  38 A4 2D D0 */	addi r5, r4, lbl_80222DD0@l
/* 800055C8 00002528  38 63 2D C0 */	addi r3, r3, lbl_80222DC0@l
/* 800055CC 0000252C  38 80 00 1D */	li r4, 0x1d
/* 800055D0 00002530  48 1F 23 41 */	bl OSPanic
/* 800055D4 00002534  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800055D8 00002538  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800055DC 0000253C  38 21 00 18 */	addi r1, r1, 0x18
/* 800055E0 00002540  7C 08 03 A6 */	mtlr r0
/* 800055E4 00002544  4E 80 00 20 */	blr 
/* 800055E8 00002548  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055EC 0000254C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055F0 00002550  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055F4 00002554  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055F8 00002558  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800055FC 0000255C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
