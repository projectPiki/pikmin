.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__7BaseAppFv, global
/* 80024DFC 00021D5C  7C 08 02 A6 */	mflr r0
/* 80024E00 00021D60  3C 80 80 22 */	lis r4, __vt__5ANode@ha
/* 80024E04 00021D64  90 01 00 04 */	stw r0, 4(r1)
/* 80024E08 00021D68  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80024E0C 00021D6C  BF 61 00 1C */	stmw r27, 0x1c(r1)
/* 80024E10 00021D70  3B 63 00 00 */	addi r27, r3, 0
/* 80024E14 00021D74  3B 84 73 8C */	addi r28, r4, __vt__5ANode@l
/* 80024E18 00021D78  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 80024E1C 00021D7C  3B A3 73 7C */	addi r29, r3, __vt__8CoreNode@l
/* 80024E20 00021D80  3B C0 00 00 */	li r30, 0
/* 80024E24 00021D84  38 7B 00 00 */	addi r3, r27, 0
/* 80024E28 00021D88  38 8D 81 50 */	addi r4, r13, lbl_803DCE70@sda21
/* 80024E2C 00021D8C  93 9B 00 00 */	stw r28, 0(r27)
/* 80024E30 00021D90  93 BB 00 00 */	stw r29, 0(r27)
/* 80024E34 00021D94  93 DB 00 10 */	stw r30, 0x10(r27)
/* 80024E38 00021D98  93 DB 00 0C */	stw r30, 0xc(r27)
/* 80024E3C 00021D9C  93 DB 00 08 */	stw r30, 8(r27)
/* 80024E40 00021DA0  48 00 00 95 */	bl setName__8CoreNodeFPc
/* 80024E44 00021DA4  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 80024E48 00021DA8  3B E3 8E 20 */	addi r31, r3, __vt__4Node@l
/* 80024E4C 00021DAC  93 FB 00 00 */	stw r31, 0(r27)
/* 80024E50 00021DB0  38 7B 00 00 */	addi r3, r27, 0
/* 80024E54 00021DB4  38 8D 81 50 */	addi r4, r13, lbl_803DCE70@sda21
/* 80024E58 00021DB8  48 01 B8 E5 */	bl init__4NodeFPc
/* 80024E5C 00021DBC  3C 60 80 22 */	lis r3, __vt__7BaseApp@ha
/* 80024E60 00021DC0  38 03 73 30 */	addi r0, r3, __vt__7BaseApp@l
/* 80024E64 00021DC4  90 1B 00 00 */	stw r0, 0(r27)
/* 80024E68 00021DC8  38 7B 00 30 */	addi r3, r27, 0x30
/* 80024E6C 00021DCC  38 8D 81 50 */	addi r4, r13, lbl_803DCE70@sda21
/* 80024E70 00021DD0  93 9B 00 30 */	stw r28, 0x30(r27)
/* 80024E74 00021DD4  93 BB 00 30 */	stw r29, 0x30(r27)
/* 80024E78 00021DD8  93 DB 00 40 */	stw r30, 0x40(r27)
/* 80024E7C 00021DDC  93 DB 00 3C */	stw r30, 0x3c(r27)
/* 80024E80 00021DE0  93 DB 00 38 */	stw r30, 0x38(r27)
/* 80024E84 00021DE4  48 00 00 51 */	bl setName__8CoreNodeFPc
/* 80024E88 00021DE8  93 FB 00 30 */	stw r31, 0x30(r27)
/* 80024E8C 00021DEC  38 7B 00 30 */	addi r3, r27, 0x30
/* 80024E90 00021DF0  38 8D 81 50 */	addi r4, r13, lbl_803DCE70@sda21
/* 80024E94 00021DF4  48 01 B8 A9 */	bl init__4NodeFPc
/* 80024E98 00021DF8  93 DB 00 2C */	stw r30, 0x2c(r27)
/* 80024E9C 00021DFC  38 00 00 01 */	li r0, 1
/* 80024EA0 00021E00  38 9B 00 00 */	addi r4, r27, 0
/* 80024EA4 00021E04  93 DB 00 20 */	stw r30, 0x20(r27)
/* 80024EA8 00021E08  93 DB 00 24 */	stw r30, 0x24(r27)
/* 80024EAC 00021E0C  98 1B 00 28 */	stb r0, 0x28(r27)
/* 80024EB0 00021E10  80 6D 2D D8 */	lwz r3, nodeMgr@sda21(r13)
/* 80024EB4 00021E14  38 63 00 04 */	addi r3, r3, 4
/* 80024EB8 00021E18  48 01 B7 21 */	bl add__8CoreNodeFP8CoreNode
/* 80024EBC 00021E1C  7F 63 DB 78 */	mr r3, r27
/* 80024EC0 00021E20  BB 61 00 1C */	lmw r27, 0x1c(r1)
/* 80024EC4 00021E24  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80024EC8 00021E28  38 21 00 30 */	addi r1, r1, 0x30
/* 80024ECC 00021E2C  7C 08 03 A6 */	mtlr r0
/* 80024ED0 00021E30  4E 80 00 20 */	blr 
.endfn __ct__7BaseAppFv

.fn setName__8CoreNodeFPc, weak
/* 80024ED4 00021E34  90 83 00 04 */	stw r4, 4(r3)
/* 80024ED8 00021E38  4E 80 00 20 */	blr 
.endfn setName__8CoreNodeFPc

.fn softReset__7BaseAppFv, global
/* 80024EDC 00021E3C  7C 08 02 A6 */	mflr r0
/* 80024EE0 00021E40  3C 80 80 22 */	lis r4, lbl_802272DC@ha
/* 80024EE4 00021E44  90 01 00 04 */	stw r0, 4(r1)
/* 80024EE8 00021E48  38 00 00 00 */	li r0, 0
/* 80024EEC 00021E4C  38 84 72 DC */	addi r4, r4, lbl_802272DC@l
/* 80024EF0 00021E50  94 21 FF F8 */	stwu r1, -8(r1)
/* 80024EF4 00021E54  90 03 00 10 */	stw r0, 0x10(r3)
/* 80024EF8 00021E58  38 63 00 30 */	addi r3, r3, 0x30
/* 80024EFC 00021E5C  48 01 B8 41 */	bl init__4NodeFPc
/* 80024F00 00021E60  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80024F04 00021E64  81 83 01 A0 */	lwz r12, 0x1a0(r3)
/* 80024F08 00021E68  81 8C 00 08 */	lwz r12, 8(r12)
/* 80024F0C 00021E6C  7D 88 03 A6 */	mtlr r12
/* 80024F10 00021E70  4E 80 00 21 */	blrl 
/* 80024F14 00021E74  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80024F18 00021E78  38 21 00 08 */	addi r1, r1, 8
/* 80024F1C 00021E7C  7C 08 03 A6 */	mtlr r0
/* 80024F20 00021E80  4E 80 00 20 */	blr 
.endfn softReset__7BaseAppFv

.fn __dt__7BaseAppFv, global
/* 80024F24 00021E84  7C 08 02 A6 */	mflr r0
/* 80024F28 00021E88  90 01 00 04 */	stw r0, 4(r1)
/* 80024F2C 00021E8C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80024F30 00021E90  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80024F34 00021E94  3B E4 00 00 */	addi r31, r4, 0
/* 80024F38 00021E98  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80024F3C 00021E9C  7C 7E 1B 79 */	or. r30, r3, r3
/* 80024F40 00021EA0  41 82 00 6C */	beq .L_80024FAC
/* 80024F44 00021EA4  3C 60 80 22 */	lis r3, __vt__7BaseApp@ha
/* 80024F48 00021EA8  38 03 73 30 */	addi r0, r3, __vt__7BaseApp@l
/* 80024F4C 00021EAC  90 1E 00 00 */	stw r0, 0(r30)
/* 80024F50 00021EB0  80 7E 00 20 */	lwz r3, 0x20(r30)
/* 80024F54 00021EB4  28 03 00 00 */	cmplwi r3, 0
/* 80024F58 00021EB8  41 82 00 38 */	beq .L_80024F90
/* 80024F5C 00021EBC  80 63 00 08 */	lwz r3, 8(r3)
/* 80024F60 00021EC0  3C 80 00 01 */	lis r4, 0x0000FFFF@ha
/* 80024F64 00021EC4  38 84 FF FF */	addi r4, r4, 0x0000FFFF@l
/* 80024F68 00021EC8  81 83 00 04 */	lwz r12, 4(r3)
/* 80024F6C 00021ECC  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80024F70 00021ED0  7D 88 03 A6 */	mtlr r12
/* 80024F74 00021ED4  4E 80 00 21 */	blrl 
/* 80024F78 00021ED8  80 7E 00 20 */	lwz r3, 0x20(r30)
/* 80024F7C 00021EDC  80 63 00 08 */	lwz r3, 8(r3)
/* 80024F80 00021EE0  81 83 00 04 */	lwz r12, 4(r3)
/* 80024F84 00021EE4  81 8C 00 54 */	lwz r12, 0x54(r12)
/* 80024F88 00021EE8  7D 88 03 A6 */	mtlr r12
/* 80024F8C 00021EEC  4E 80 00 21 */	blrl 
.L_80024F90:
/* 80024F90 00021EF0  80 6D 2D D8 */	lwz r3, nodeMgr@sda21(r13)
/* 80024F94 00021EF4  7F C4 F3 78 */	mr r4, r30
/* 80024F98 00021EF8  48 01 B9 3D */	bl Del__7NodeMgrFP4Node
/* 80024F9C 00021EFC  7F E0 07 35 */	extsh. r0, r31
/* 80024FA0 00021F00  40 81 00 0C */	ble .L_80024FAC
/* 80024FA4 00021F04  7F C3 F3 78 */	mr r3, r30
/* 80024FA8 00021F08  48 02 22 05 */	bl __dl__FPv
.L_80024FAC:
/* 80024FAC 00021F0C  7F C3 F3 78 */	mr r3, r30
/* 80024FB0 00021F10  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80024FB4 00021F14  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80024FB8 00021F18  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80024FBC 00021F1C  38 21 00 18 */	addi r1, r1, 0x18
/* 80024FC0 00021F20  7C 08 03 A6 */	mtlr r0
/* 80024FC4 00021F24  4E 80 00 20 */	blr 
.endfn __dt__7BaseAppFv

.fn flush__6StreamFv, weak
/* 80024FC8 00021F28  4E 80 00 20 */	blr 
.endfn flush__6StreamFv

.fn InitApp__7BaseAppFPc, weak
/* 80024FCC 00021F2C  4E 80 00 20 */	blr 
.endfn InitApp__7BaseAppFPc

.fn idle__7BaseAppFv, weak
/* 80024FD0 00021F30  38 60 00 00 */	li r3, 0
/* 80024FD4 00021F34  4E 80 00 20 */	blr 
.endfn idle__7BaseAppFv

.fn keyDown__7BaseAppFiii, weak
/* 80024FD8 00021F38  38 60 00 00 */	li r3, 0
/* 80024FDC 00021F3C  4E 80 00 20 */	blr 
.endfn keyDown__7BaseAppFiii

.fn useHeap__7BaseAppFi, weak
/* 80024FE0 00021F40  7C 08 02 A6 */	mflr r0
/* 80024FE4 00021F44  7C 65 1B 78 */	mr r5, r3
/* 80024FE8 00021F48  90 01 00 04 */	stw r0, 4(r1)
/* 80024FEC 00021F4C  94 21 FF F8 */	stwu r1, -8(r1)
/* 80024FF0 00021F50  90 83 00 50 */	stw r4, 0x50(r3)
/* 80024FF4 00021F54  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80024FF8 00021F58  80 85 00 50 */	lwz r4, 0x50(r5)
/* 80024FFC 00021F5C  48 01 A0 6D */	bl setHeap__9StdSystemFi
/* 80025000 00021F60  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80025004 00021F64  38 21 00 08 */	addi r1, r1, 8
/* 80025008 00021F68  7C 08 03 A6 */	mtlr r0
/* 8002500C 00021F6C  4E 80 00 20 */	blr 
.endfn useHeap__7BaseAppFi

.fn procCmd__7BaseAppFPc, weak
/* 80025010 00021F70  4E 80 00 20 */	blr 
.endfn procCmd__7BaseAppFPc

.fn concat__4NodeFR8Matrix4f, weak
/* 80025014 00021F74  7C 08 02 A6 */	mflr r0
/* 80025018 00021F78  90 01 00 04 */	stw r0, 4(r1)
/* 8002501C 00021F7C  94 21 FF F8 */	stwu r1, -8(r1)
/* 80025020 00021F80  81 83 00 00 */	lwz r12, 0(r3)
/* 80025024 00021F84  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 80025028 00021F88  7D 88 03 A6 */	mtlr r12
/* 8002502C 00021F8C  4E 80 00 21 */	blrl 
/* 80025030 00021F90  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80025034 00021F94  38 21 00 08 */	addi r1, r1, 8
/* 80025038 00021F98  7C 08 03 A6 */	mtlr r0
/* 8002503C 00021F9C  4E 80 00 20 */	blr 
.endfn concat__4NodeFR8Matrix4f

.fn concat__4NodeFR3SRT, weak
/* 80025040 00021FA0  7C 08 02 A6 */	mflr r0
/* 80025044 00021FA4  90 01 00 04 */	stw r0, 4(r1)
/* 80025048 00021FA8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8002504C 00021FAC  81 83 00 00 */	lwz r12, 0(r3)
/* 80025050 00021FB0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 80025054 00021FB4  7D 88 03 A6 */	mtlr r12
/* 80025058 00021FB8  4E 80 00 21 */	blrl 
/* 8002505C 00021FBC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80025060 00021FC0  38 21 00 08 */	addi r1, r1, 8
/* 80025064 00021FC4  7C 08 03 A6 */	mtlr r0
/* 80025068 00021FC8  4E 80 00 20 */	blr 
.endfn concat__4NodeFR3SRT

.fn concat__4NodeFR3VQS, weak
/* 8002506C 00021FCC  7C 08 02 A6 */	mflr r0
/* 80025070 00021FD0  90 01 00 04 */	stw r0, 4(r1)
/* 80025074 00021FD4  94 21 FF F8 */	stwu r1, -8(r1)
/* 80025078 00021FD8  81 83 00 00 */	lwz r12, 0(r3)
/* 8002507C 00021FDC  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 80025080 00021FE0  7D 88 03 A6 */	mtlr r12
/* 80025084 00021FE4  4E 80 00 21 */	blrl 
/* 80025088 00021FE8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8002508C 00021FEC  38 21 00 08 */	addi r1, r1, 8
/* 80025090 00021FF0  7C 08 03 A6 */	mtlr r0
/* 80025094 00021FF4  4E 80 00 20 */	blr 
.endfn concat__4NodeFR3VQS

.fn concat__4NodeFv, weak
/* 80025098 00021FF8  4E 80 00 20 */	blr 
.endfn concat__4NodeFv

.fn getModelMatrix__4NodeFv, weak
/* 8002509C 00021FFC  38 60 00 00 */	li r3, 0
/* 800250A0 00022000  4E 80 00 20 */	blr 
.endfn getModelMatrix__4NodeFv

.fn read__8CoreNodeFR18RandomAccessStream, weak
/* 800250A4 00022004  4E 80 00 20 */	blr 
.endfn read__8CoreNodeFR18RandomAccessStream

.fn getAgeNodeType__5ANodeFv, weak
/* 800250A8 00022008  38 60 00 00 */	li r3, 0
/* 800250AC 0002200C  4E 80 00 20 */	blr 
.endfn getAgeNodeType__5ANodeFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802272D0, local
	.asciz "baseApp.cpp"
.endobj lbl_802272D0
.balign 4
.obj lbl_802272DC, local
	.asciz "[Windows]"
.endobj lbl_802272DC
.balign 4
.obj lbl_802272E8, local
	.asciz "CoreNode"
.endobj lbl_802272E8
.balign 4
.obj lbl_802272F4, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.endobj lbl_802272F4
.obj lbl_80227300, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.endobj lbl_80227300
.obj lbl_80227314, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.endobj lbl_80227314
.obj __vt__7BaseApp, global
	.4byte __RTTI__7BaseApp
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__4NodeFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte __dt__7BaseAppFv
	.4byte InitApp__7BaseAppFPc
	.4byte idle__7BaseAppFv
	.4byte keyDown__7BaseAppFiii
	.4byte softReset__7BaseAppFv
	.4byte useHeap__7BaseAppFi
	.4byte procCmd__7BaseAppFPc
.endobj __vt__7BaseApp
.obj __vt__8CoreNode, weak
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
.endobj __vt__8CoreNode
.obj __vt__5ANode, weak
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
.endobj __vt__5ANode

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DCE70, local
	.asciz "<Node>"
.endobj lbl_803DCE70
.balign 4
.obj lbl_803DCE78, local
	.asciz "BaseApp"
.endobj lbl_803DCE78
.balign 4
.obj lbl_803DCE80, local
	.asciz "ANode"
.endobj lbl_803DCE80
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803DCE80
	.4byte 0
.endobj __RTTI__5ANode
.obj __RTTI__8CoreNode, local
	.4byte lbl_802272E8
	.4byte lbl_802272F4
.endobj __RTTI__8CoreNode
.balign 4
.obj lbl_803DCE98, local
	.asciz "Node"
.endobj lbl_803DCE98
.balign 4
.obj __RTTI__4Node, local
	.4byte lbl_803DCE98
	.4byte lbl_80227300
.endobj __RTTI__4Node
.obj __RTTI__7BaseApp, local
	.4byte lbl_803DCE78
	.4byte lbl_80227314
.endobj __RTTI__7BaseApp
