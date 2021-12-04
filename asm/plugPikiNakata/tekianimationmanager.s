.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__20TekiAnimationManagerFP7TekiMgr
__ct__20TekiAnimationManagerFP7TekiMgr:
/* 80143E48 00140DA8  7C 08 02 A6 */	mflr r0
/* 80143E4C 00140DAC  3C A0 80 22 */	lis r5, __vt__5ANode@ha
/* 80143E50 00140DB0  90 01 00 04 */	stw r0, 4(r1)
/* 80143E54 00140DB4  38 05 73 8C */	addi r0, r5, __vt__5ANode@l
/* 80143E58 00140DB8  38 C0 00 00 */	li r6, 0
/* 80143E5C 00140DBC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80143E60 00140DC0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80143E64 00140DC4  3B E4 00 00 */	addi r31, r4, 0
/* 80143E68 00140DC8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80143E6C 00140DCC  3B C3 00 00 */	addi r30, r3, 0
/* 80143E70 00140DD0  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 80143E74 00140DD4  90 1E 00 00 */	stw r0, 0(r30)
/* 80143E78 00140DD8  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 80143E7C 00140DDC  3C 60 80 2D */	lis r3, lbl_802CCE6C@ha
/* 80143E80 00140DE0  90 1E 00 00 */	stw r0, 0(r30)
/* 80143E84 00140DE4  38 A3 CE 6C */	addi r5, r3, lbl_802CCE6C@l
/* 80143E88 00140DE8  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 80143E8C 00140DEC  90 DE 00 10 */	stw r6, 0x10(r30)
/* 80143E90 00140DF0  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 80143E94 00140DF4  38 7E 00 00 */	addi r3, r30, 0
/* 80143E98 00140DF8  90 DE 00 0C */	stw r6, 0xc(r30)
/* 80143E9C 00140DFC  7C A4 2B 78 */	mr r4, r5
/* 80143EA0 00140E00  90 DE 00 08 */	stw r6, 8(r30)
/* 80143EA4 00140E04  90 BE 00 04 */	stw r5, 4(r30)
/* 80143EA8 00140E08  90 1E 00 00 */	stw r0, 0(r30)
/* 80143EAC 00140E0C  4B EF C8 91 */	bl init__4NodeFPc
/* 80143EB0 00140E10  3C 60 80 2D */	lis r3, __vt__20TekiAnimationManager@ha
/* 80143EB4 00140E14  38 03 CE CC */	addi r0, r3, __vt__20TekiAnimationManager@l
/* 80143EB8 00140E18  90 1E 00 00 */	stw r0, 0(r30)
/* 80143EBC 00140E1C  7F C3 F3 78 */	mr r3, r30
/* 80143EC0 00140E20  93 FE 00 20 */	stw r31, 0x20(r30)
/* 80143EC4 00140E24  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80143EC8 00140E28  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80143ECC 00140E2C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80143ED0 00140E30  38 21 00 18 */	addi r1, r1, 0x18
/* 80143ED4 00140E34  7C 08 03 A6 */	mtlr r0
/* 80143ED8 00140E38  4E 80 00 20 */	blr 

.global read__20TekiAnimationManagerFR18RandomAccessStream
read__20TekiAnimationManagerFR18RandomAccessStream:
/* 80143EDC 00140E3C  7C 08 02 A6 */	mflr r0
/* 80143EE0 00140E40  90 01 00 04 */	stw r0, 4(r1)
/* 80143EE4 00140E44  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80143EE8 00140E48  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80143EEC 00140E4C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80143EF0 00140E50  3B C0 00 00 */	li r30, 0
/* 80143EF4 00140E54  57 DF 10 3A */	slwi r31, r30, 2
/* 80143EF8 00140E58  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80143EFC 00140E5C  3B A4 00 00 */	addi r29, r4, 0
/* 80143F00 00140E60  93 81 00 10 */	stw r28, 0x10(r1)
/* 80143F04 00140E64  3B 83 00 00 */	addi r28, r3, 0
lbl_80143F08:
/* 80143F08 00140E68  80 7C 00 20 */	lwz r3, 0x20(r28)
/* 80143F0C 00140E6C  38 1F 00 D8 */	addi r0, r31, 0xd8
/* 80143F10 00140E70  38 9D 00 00 */	addi r4, r29, 0
/* 80143F14 00140E74  7C 63 00 2E */	lwzx r3, r3, r0
/* 80143F18 00140E78  80 63 00 14 */	lwz r3, 0x14(r3)
/* 80143F1C 00140E7C  81 83 00 00 */	lwz r12, 0(r3)
/* 80143F20 00140E80  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80143F24 00140E84  7D 88 03 A6 */	mtlr r12
/* 80143F28 00140E88  4E 80 00 21 */	blrl 
/* 80143F2C 00140E8C  3B DE 00 01 */	addi r30, r30, 1
/* 80143F30 00140E90  2C 1E 00 23 */	cmpwi r30, 0x23
/* 80143F34 00140E94  3B FF 00 04 */	addi r31, r31, 4
/* 80143F38 00140E98  41 80 FF D0 */	blt lbl_80143F08
/* 80143F3C 00140E9C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80143F40 00140EA0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80143F44 00140EA4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80143F48 00140EA8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80143F4C 00140EAC  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80143F50 00140EB0  38 21 00 20 */	addi r1, r1, 0x20
/* 80143F54 00140EB4  7C 08 03 A6 */	mtlr r0
/* 80143F58 00140EB8  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802CCE38:
	.asciz "tekianimationmanager.cpp"
.balign 4
lbl_802CCE54:
	.asciz "tekianimationmanager"
.balign 4
lbl_802CCE6C:
	.asciz "TekiAnimationManager"
.balign 4
lbl_802CCE84:
	.asciz "CoreNode"
.balign 4
lbl_802CCE90:
	.4byte 0x803E4308
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802CCE9C:
	.4byte 0x803E4308
	.4byte 0x00000000
	.4byte 0x803E4310
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802CCEB0:
	.4byte 0x803E4308
	.4byte 0x00000000
	.4byte 0x803E4310
	.4byte 0x00000000
	.4byte 0x803E4320
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__20TekiAnimationManager
__vt__20TekiAnimationManager:
	.4byte __RTTI__20TekiAnimationManager
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__20TekiAnimationManagerFR18RandomAccessStream
	.4byte update__4NodeFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E4300:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E4300
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802CCE84
	.4byte lbl_802CCE90
.balign 4
lbl_803E4318:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803E4318
	.4byte lbl_802CCE9C
__RTTI__20TekiAnimationManager:
	.4byte lbl_802CCE6C
	.4byte lbl_802CCEB0
