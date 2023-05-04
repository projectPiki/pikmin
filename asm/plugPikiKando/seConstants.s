.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__10SeConstantFv, global
/* 800A3B04 000A0A64  7C 08 02 A6 */	mflr r0
/* 800A3B08 000A0A68  3C 80 80 22 */	lis r4, __vt__5ANode@ha
/* 800A3B0C 000A0A6C  90 01 00 04 */	stw r0, 4(r1)
/* 800A3B10 000A0A70  38 04 73 8C */	addi r0, r4, __vt__5ANode@l
/* 800A3B14 000A0A74  38 8D AD 08 */	addi r4, r13, lbl_803DFA28@sda21
/* 800A3B18 000A0A78  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 800A3B1C 000A0A7C  93 E1 00 44 */	stw r31, 0x44(r1)
/* 800A3B20 000A0A80  3B E3 00 00 */	addi r31, r3, 0
/* 800A3B24 000A0A84  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 800A3B28 000A0A88  93 C1 00 40 */	stw r30, 0x40(r1)
/* 800A3B2C 000A0A8C  3B C0 00 00 */	li r30, 0
/* 800A3B30 000A0A90  90 1F 00 00 */	stw r0, 0(r31)
/* 800A3B34 000A0A94  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 800A3B38 000A0A98  38 7F 00 00 */	addi r3, r31, 0
/* 800A3B3C 000A0A9C  90 1F 00 00 */	stw r0, 0(r31)
/* 800A3B40 000A0AA0  93 DF 00 10 */	stw r30, 0x10(r31)
/* 800A3B44 000A0AA4  93 DF 00 0C */	stw r30, 0xc(r31)
/* 800A3B48 000A0AA8  93 DF 00 08 */	stw r30, 8(r31)
/* 800A3B4C 000A0AAC  4B F8 13 89 */	bl setName__8CoreNodeFPc
/* 800A3B50 000A0AB0  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 800A3B54 000A0AB4  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 800A3B58 000A0AB8  90 1F 00 00 */	stw r0, 0(r31)
/* 800A3B5C 000A0ABC  38 7F 00 00 */	addi r3, r31, 0
/* 800A3B60 000A0AC0  38 8D AD 08 */	addi r4, r13, lbl_803DFA28@sda21
/* 800A3B64 000A0AC4  4B F9 CB D9 */	bl init__4NodeFPc
/* 800A3B68 000A0AC8  3C 60 80 2B */	lis r3, __vt__10SeConstant@ha
/* 800A3B6C 000A0ACC  38 03 1D C4 */	addi r0, r3, __vt__10SeConstant@l
/* 800A3B70 000A0AD0  90 1F 00 00 */	stw r0, 0(r31)
/* 800A3B74 000A0AD4  38 A1 00 20 */	addi r5, r1, 0x20
/* 800A3B78 000A0AD8  38 7F 00 24 */	addi r3, r31, 0x24
/* 800A3B7C 000A0ADC  93 DF 00 20 */	stw r30, 0x20(r31)
/* 800A3B80 000A0AE0  38 9F 00 20 */	addi r4, r31, 0x20
/* 800A3B84 000A0AE4  80 0D AD 10 */	lwz r0, lbl_803DFA30@sda21(r13)
/* 800A3B88 000A0AE8  90 01 00 28 */	stw r0, 0x28(r1)
/* 800A3B8C 000A0AEC  80 01 00 28 */	lwz r0, 0x28(r1)
/* 800A3B90 000A0AF0  90 01 00 20 */	stw r0, 0x20(r1)
/* 800A3B94 000A0AF4  4B FB AE ED */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800A3B98 000A0AF8  3C 60 80 2A */	lis r3, "__vt__7Parm<f>"@ha
/* 800A3B9C 000A0AFC  3B C3 60 98 */	addi r30, r3, "__vt__7Parm<f>"@l
/* 800A3BA0 000A0B00  93 DF 00 2C */	stw r30, 0x2c(r31)
/* 800A3BA4 000A0B04  38 A1 00 1C */	addi r5, r1, 0x1c
/* 800A3BA8 000A0B08  38 7F 00 34 */	addi r3, r31, 0x34
/* 800A3BAC 000A0B0C  C0 02 8D 88 */	lfs f0, lbl_803E8F88@sda21(r2)
/* 800A3BB0 000A0B10  38 9F 00 20 */	addi r4, r31, 0x20
/* 800A3BB4 000A0B14  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 800A3BB8 000A0B18  80 0D AD 14 */	lwz r0, lbl_803DFA34@sda21(r13)
/* 800A3BBC 000A0B1C  90 01 00 30 */	stw r0, 0x30(r1)
/* 800A3BC0 000A0B20  80 01 00 30 */	lwz r0, 0x30(r1)
/* 800A3BC4 000A0B24  90 01 00 1C */	stw r0, 0x1c(r1)
/* 800A3BC8 000A0B28  4B FB AE B9 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800A3BCC 000A0B2C  93 DF 00 3C */	stw r30, 0x3c(r31)
/* 800A3BD0 000A0B30  38 A1 00 18 */	addi r5, r1, 0x18
/* 800A3BD4 000A0B34  38 7F 00 44 */	addi r3, r31, 0x44
/* 800A3BD8 000A0B38  C0 02 8D 8C */	lfs f0, lbl_803E8F8C@sda21(r2)
/* 800A3BDC 000A0B3C  38 9F 00 20 */	addi r4, r31, 0x20
/* 800A3BE0 000A0B40  D0 1F 00 40 */	stfs f0, 0x40(r31)
/* 800A3BE4 000A0B44  80 0D AD 18 */	lwz r0, lbl_803DFA38@sda21(r13)
/* 800A3BE8 000A0B48  90 01 00 38 */	stw r0, 0x38(r1)
/* 800A3BEC 000A0B4C  80 01 00 38 */	lwz r0, 0x38(r1)
/* 800A3BF0 000A0B50  90 01 00 18 */	stw r0, 0x18(r1)
/* 800A3BF4 000A0B54  4B FB AE 8D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800A3BF8 000A0B58  93 DF 00 4C */	stw r30, 0x4c(r31)
/* 800A3BFC 000A0B5C  3C 60 80 2B */	lis r3, lbl_802B1D2C@ha
/* 800A3C00 000A0B60  38 A3 1D 2C */	addi r5, r3, lbl_802B1D2C@l
/* 800A3C04 000A0B64  C0 02 8D 90 */	lfs f0, lbl_803E8F90@sda21(r2)
/* 800A3C08 000A0B68  7F E3 FB 78 */	mr r3, r31
/* 800A3C0C 000A0B6C  38 8D AD 1C */	addi r4, r13, lbl_803DFA3C@sda21
/* 800A3C10 000A0B70  D0 1F 00 50 */	stfs f0, 0x50(r31)
/* 800A3C14 000A0B74  38 C0 00 01 */	li r6, 1
/* 800A3C18 000A0B78  4B F9 CA 89 */	bl load__8CoreNodeFPcPcUl
/* 800A3C1C 000A0B7C  7F E3 FB 78 */	mr r3, r31
/* 800A3C20 000A0B80  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 800A3C24 000A0B84  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 800A3C28 000A0B88  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 800A3C2C 000A0B8C  38 21 00 48 */	addi r1, r1, 0x48
/* 800A3C30 000A0B90  7C 08 03 A6 */	mtlr r0
/* 800A3C34 000A0B94  4E 80 00 20 */	blr 
.endfn __ct__10SeConstantFv

.fn read__10SeConstantFR18RandomAccessStream, weak
/* 800A3C38 000A0B98  7C 08 02 A6 */	mflr r0
/* 800A3C3C 000A0B9C  38 63 00 20 */	addi r3, r3, 0x20
/* 800A3C40 000A0BA0  90 01 00 04 */	stw r0, 4(r1)
/* 800A3C44 000A0BA4  94 21 FF F8 */	stwu r1, -8(r1)
/* 800A3C48 000A0BA8  4B FB AF 51 */	bl read__10ParametersFR18RandomAccessStream
/* 800A3C4C 000A0BAC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800A3C50 000A0BB0  38 21 00 08 */	addi r1, r1, 8
/* 800A3C54 000A0BB4  7C 08 03 A6 */	mtlr r0
/* 800A3C58 000A0BB8  4E 80 00 20 */	blr 
.endfn read__10SeConstantFR18RandomAccessStream

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B1D10, local
	.asciz "seConstants.cpp"
.endobj lbl_802B1D10
.balign 4
.obj lbl_802B1D20, local
	.asciz "seConstant"
.endobj lbl_802B1D20
.balign 4
.obj lbl_802B1D2C, local
	.asciz "sound.bin"
.endobj lbl_802B1D2C
.balign 4
.obj lbl_802B1D38, local
	.asciz "Parm<float>"
.endobj lbl_802B1D38
.balign 4
.obj lbl_802B1D44, local
	.asciz "BaseParm"
.endobj lbl_802B1D44
.balign 4
.obj lbl_802B1D50, local
	.4byte __RTTI__8BaseParm
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B1D50
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
.obj lbl_802B1D70, local
	.asciz "SeConstant"
.endobj lbl_802B1D70
.balign 4
.obj lbl_802B1D7C, local
	.asciz "CoreNode"
.endobj lbl_802B1D7C
.balign 4
.obj lbl_802B1D88, local
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B1D88
.obj lbl_802B1D94, local
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B1D94
.obj lbl_802B1DA8, local
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte __RTTI__4Node
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B1DA8
.obj __vt__10SeConstant, weak
	.4byte __RTTI__10SeConstant
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__10SeConstantFR18RandomAccessStream
	.4byte update__4NodeFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
.endobj __vt__10SeConstant
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DFA28, local
	.asciz "<Node>"
.endobj lbl_803DFA28
.balign 4
.obj lbl_803DFA30, local
	.asciz "p00"
.endobj lbl_803DFA30
.balign 4
.obj lbl_803DFA34, local
	.asciz "p01"
.endobj lbl_803DFA34
.balign 4
.obj lbl_803DFA38, local
	.asciz "p02"
.endobj lbl_803DFA38
.balign 4
.obj lbl_803DFA3C, local
	.asciz "parms/"
.endobj lbl_803DFA3C
.balign 4
.obj __RTTI__8BaseParm, local
	.4byte lbl_802B1D44
	.4byte 0
.endobj __RTTI__8BaseParm
.balign 4
.obj lbl_803DFA4C, local
	.asciz "ANode"
.endobj lbl_803DFA4C
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803DFA4C
	.4byte 0
.endobj __RTTI__5ANode
.obj __RTTI__8CoreNode, local
	.4byte lbl_802B1D7C
	.4byte lbl_802B1D88
.endobj __RTTI__8CoreNode
.balign 4
.obj lbl_803DFA64, local
	.asciz "Node"
.endobj lbl_803DFA64
.balign 4
.obj __RTTI__4Node, local
	.4byte lbl_803DFA64
	.4byte lbl_802B1D94
.endobj __RTTI__4Node
.obj __RTTI__10SeConstant, local
	.4byte lbl_802B1D70
	.4byte lbl_802B1DA8
.endobj __RTTI__10SeConstant

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E8F88, local
	.float 700.0
.endobj lbl_803E8F88
.obj lbl_803E8F8C, local
	.float 400.0
.endobj lbl_803E8F8C
.obj lbl_803E8F90, local
	.float 800.0
.endobj lbl_803E8F90
