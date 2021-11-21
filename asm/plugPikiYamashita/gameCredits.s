.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__18GameCreditsSectionFv
__ct__18GameCreditsSectionFv:
/* 8019B888 001987E8  7C 08 02 A6 */	mflr r0
/* 8019B88C 001987EC  38 8D 0F D8 */	addi r4, r13, lbl_803E5CF8@sda21
/* 8019B890 001987F0  90 01 00 04 */	stw r0, 4(r1)
/* 8019B894 001987F4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8019B898 001987F8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8019B89C 001987FC  3B E3 00 00 */	addi r31, r3, 0
/* 8019B8A0 00198800  4B E9 97 19 */	bl __ct__8CoreNodeFPc
/* 8019B8A4 00198804  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 8019B8A8 00198808  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 8019B8AC 0019880C  90 1F 00 00 */	stw r0, 0(r31)
/* 8019B8B0 00198810  38 7F 00 00 */	addi r3, r31, 0
/* 8019B8B4 00198814  38 8D 0F D8 */	addi r4, r13, lbl_803E5CF8@sda21
/* 8019B8B8 00198818  4B EA 4E 85 */	bl init__4NodeFPc
/* 8019B8BC 0019881C  3C 60 80 2A */	lis r3, __vt__7Section@ha
/* 8019B8C0 00198820  38 03 64 2C */	addi r0, r3, __vt__7Section@l
/* 8019B8C4 00198824  3C 60 80 2D */	lis r3, __vt__18GameCreditsSection@ha
/* 8019B8C8 00198828  90 1F 00 00 */	stw r0, 0(r31)
/* 8019B8CC 0019882C  38 03 6C 54 */	addi r0, r3, __vt__18GameCreditsSection@l
/* 8019B8D0 00198830  3C 60 80 2D */	lis r3, lbl_802D6BB4@ha
/* 8019B8D4 00198834  90 1F 00 00 */	stw r0, 0(r31)
/* 8019B8D8 00198838  38 83 6B B4 */	addi r4, r3, lbl_802D6BB4@l
/* 8019B8DC 0019883C  38 7F 00 00 */	addi r3, r31, 0
/* 8019B8E0 00198840  4B EA 4E 5D */	bl init__4NodeFPc
/* 8019B8E4 00198844  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8019B8E8 00198848  38 00 00 01 */	li r0, 1
/* 8019B8EC 0019884C  3C 60 80 3A */	lis r3, flowCont@ha
/* 8019B8F0 00198850  90 04 00 14 */	stw r0, 0x14(r4)
/* 8019B8F4 00198854  38 83 DB 20 */	addi r4, r3, flowCont@l
/* 8019B8F8 00198858  38 00 00 00 */	li r0, 0
/* 8019B8FC 0019885C  90 04 02 4C */	stw r0, 0x24c(r4)
/* 8019B900 00198860  7F E3 FB 78 */	mr r3, r31
/* 8019B904 00198864  90 04 02 50 */	stw r0, 0x250(r4)
/* 8019B908 00198868  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8019B90C 0019886C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8019B910 00198870  38 21 00 18 */	addi r1, r1, 0x18
/* 8019B914 00198874  7C 08 03 A6 */	mtlr r0
/* 8019B918 00198878  4E 80 00 20 */	blr 

.global init__18GameCreditsSectionFv
init__18GameCreditsSectionFv:
/* 8019B91C 0019887C  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.balign 4
lbl_802D6B90:
	.asciz "gameCredits.cpp"
.balign 4
lbl_802D6BA0:
	.asciz "GameCreditsSection"
.balign 4
lbl_802D6BB4:
	.asciz "<GameCreditsSection>"
.balign 4
lbl_802D6BCC:
	.asciz "CoreNode"
.balign 4
lbl_802D6BD8:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D6C00:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D6C14:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte __RTTI__4Node
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D6C30:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte __RTTI__4Node
	.4byte 0x00000000
	.4byte __RTTI__7Section
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__18GameCreditsSection
__vt__18GameCreditsSection:
	.4byte __RTTI__18GameCreditsSection
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
	.4byte init__18GameCreditsSectionFv
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E5CF8:
	.asciz "<Node>"
.balign 4
lbl_803E5D00:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E5D00
	.4byte 0x00000000
__RTTI__8CoreNode:
	.4byte lbl_802D6BCC
	.4byte lbl_802D6BD8
.balign 4
lbl_803E5D18:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803E5D18
	.4byte lbl_802D6C00
.balign 4
lbl_803E5D28:
	.asciz "Section"
.balign 4
__RTTI__7Section:
	.4byte lbl_803E5D28
	.4byte lbl_802D6C14
__RTTI__18GameCreditsSection:
	.4byte lbl_802D6BA0
	.4byte lbl_802D6C30
