.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__11EventTalkerFv, global
/* 80093FA8 00090F08  7C 08 02 A6 */	mflr r0
/* 80093FAC 00090F0C  3C 80 80 22 */	lis r4, __vt__5ANode@ha
/* 80093FB0 00090F10  90 01 00 04 */	stw r0, 4(r1)
/* 80093FB4 00090F14  38 04 73 8C */	addi r0, r4, __vt__5ANode@l
/* 80093FB8 00090F18  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80093FBC 00090F1C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80093FC0 00090F20  3B E0 00 00 */	li r31, 0
/* 80093FC4 00090F24  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80093FC8 00090F28  3B C3 00 00 */	addi r30, r3, 0
/* 80093FCC 00090F2C  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 80093FD0 00090F30  90 1E 00 00 */	stw r0, 0(r30)
/* 80093FD4 00090F34  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 80093FD8 00090F38  3C 60 80 2B */	lis r3, lbl_802AF9D4@ha
/* 80093FDC 00090F3C  90 1E 00 00 */	stw r0, 0(r30)
/* 80093FE0 00090F40  38 83 F9 D4 */	addi r4, r3, lbl_802AF9D4@l
/* 80093FE4 00090F44  38 7E 00 00 */	addi r3, r30, 0
/* 80093FE8 00090F48  93 FE 00 10 */	stw r31, 0x10(r30)
/* 80093FEC 00090F4C  93 FE 00 0C */	stw r31, 0xc(r30)
/* 80093FF0 00090F50  93 FE 00 08 */	stw r31, 8(r30)
/* 80093FF4 00090F54  4B F9 0E E1 */	bl setName__8CoreNodeFPc
/* 80093FF8 00090F58  3C 60 80 2B */	lis r3, __vt__13EventListener@ha
/* 80093FFC 00090F5C  38 03 FA 20 */	addi r0, r3, __vt__13EventListener@l
/* 80094000 00090F60  90 1E 00 00 */	stw r0, 0(r30)
/* 80094004 00090F64  3C 60 80 2B */	lis r3, lbl_802AF9E0@ha
/* 80094008 00090F68  38 03 F9 E0 */	addi r0, r3, lbl_802AF9E0@l
/* 8009400C 00090F6C  93 FE 00 10 */	stw r31, 0x10(r30)
/* 80094010 00090F70  7F C3 F3 78 */	mr r3, r30
/* 80094014 00090F74  93 FE 00 0C */	stw r31, 0xc(r30)
/* 80094018 00090F78  93 FE 00 08 */	stw r31, 8(r30)
/* 8009401C 00090F7C  90 1E 00 04 */	stw r0, 4(r30)
/* 80094020 00090F80  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80094024 00090F84  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80094028 00090F88  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8009402C 00090F8C  38 21 00 18 */	addi r1, r1, 0x18
/* 80094030 00090F90  7C 08 03 A6 */	mtlr r0
/* 80094034 00090F94  4E 80 00 20 */	blr 
.endfn __ct__11EventTalkerFv

.fn informEvent__11EventTalkerFR5Event, global
/* 80094038 00090F98  7C 08 02 A6 */	mflr r0
/* 8009403C 00090F9C  90 01 00 04 */	stw r0, 4(r1)
/* 80094040 00090FA0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80094044 00090FA4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80094048 00090FA8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8009404C 00090FAC  7C 9E 23 78 */	mr r30, r4
/* 80094050 00090FB0  83 E3 00 10 */	lwz r31, 0x10(r3)
/* 80094054 00090FB4  48 00 00 20 */	b .L_80094074
.L_80094058:
/* 80094058 00090FB8  7F E3 FB 78 */	mr r3, r31
/* 8009405C 00090FBC  81 9F 00 00 */	lwz r12, 0(r31)
/* 80094060 00090FC0  7F C4 F3 78 */	mr r4, r30
/* 80094064 00090FC4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80094068 00090FC8  7D 88 03 A6 */	mtlr r12
/* 8009406C 00090FCC  4E 80 00 21 */	blrl 
/* 80094070 00090FD0  83 FF 00 0C */	lwz r31, 0xc(r31)
.L_80094074:
/* 80094074 00090FD4  28 1F 00 00 */	cmplwi r31, 0
/* 80094078 00090FD8  40 82 FF E0 */	bne .L_80094058
/* 8009407C 00090FDC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80094080 00090FE0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80094084 00090FE4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80094088 00090FE8  38 21 00 18 */	addi r1, r1, 0x18
/* 8009408C 00090FEC  7C 08 03 A6 */	mtlr r0
/* 80094090 00090FF0  4E 80 00 20 */	blr 
.endfn informEvent__11EventTalkerFR5Event

.fn gotEvent__13EventListenerFR5Event, weak
/* 80094094 00090FF4  4E 80 00 20 */	blr 
.endfn gotEvent__13EventListenerFR5Event

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802AF9B0, local
	.asciz "eventListener.cpp"
.endobj lbl_802AF9B0
.balign 4
.obj lbl_802AF9C4, local
	.asciz "eventListener"
.endobj lbl_802AF9C4
.balign 4
.obj lbl_802AF9D4, local
	.asciz "CoreNode"
.endobj lbl_802AF9D4
.balign 4
.obj lbl_802AF9E0, local
	.asciz "eventListeners"
.endobj lbl_802AF9E0
.balign 4
.obj lbl_802AF9F0, local
	.asciz "EventListener"
.endobj lbl_802AF9F0
.balign 4
.obj lbl_802AFA00, local
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802AFA00
.obj lbl_802AFA0C, local
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802AFA0C
.obj __vt__13EventListener, weak
	.4byte __RTTI__13EventListener
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte gotEvent__13EventListenerFR5Event
.endobj __vt__13EventListener
.skip 0x1C

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DF2F8, local
	.asciz "ANode"
.endobj lbl_803DF2F8
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803DF2F8
	.4byte 0
.endobj __RTTI__5ANode
.obj __RTTI__8CoreNode, local
	.4byte lbl_802AF9D4
	.4byte lbl_802AFA00
.endobj __RTTI__8CoreNode
.obj __RTTI__13EventListener, local
	.4byte lbl_802AF9F0
	.4byte lbl_802AFA0C
.endobj __RTTI__13EventListener
