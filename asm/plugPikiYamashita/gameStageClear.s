.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__21GameStageClearSectionFv
__ct__21GameStageClearSectionFv:
/* 8019B804 00198764  7C 08 02 A6 */	mflr r0
/* 8019B808 00198768  38 8D 0F 90 */	addi r4, r13, lbl_803E5CB0@sda21
/* 8019B80C 0019876C  90 01 00 04 */	stw r0, 4(r1)
/* 8019B810 00198770  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8019B814 00198774  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8019B818 00198778  3B E3 00 00 */	addi r31, r3, 0
/* 8019B81C 0019877C  4B E9 97 9D */	bl __ct__8CoreNodeFPc
/* 8019B820 00198780  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 8019B824 00198784  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 8019B828 00198788  90 1F 00 00 */	stw r0, 0(r31)
/* 8019B82C 0019878C  38 7F 00 00 */	addi r3, r31, 0
/* 8019B830 00198790  38 8D 0F 90 */	addi r4, r13, lbl_803E5CB0@sda21
/* 8019B834 00198794  4B EA 4F 09 */	bl init__4NodeFPc
/* 8019B838 00198798  3C 60 80 2A */	lis r3, __vt__7Section@ha
/* 8019B83C 0019879C  38 03 64 2C */	addi r0, r3, __vt__7Section@l
/* 8019B840 001987A0  3C 60 80 2D */	lis r3, __vt__21GameStageClearSection@ha
/* 8019B844 001987A4  90 1F 00 00 */	stw r0, 0(r31)
/* 8019B848 001987A8  38 03 6B 24 */	addi r0, r3, __vt__21GameStageClearSection@l
/* 8019B84C 001987AC  3C 60 80 2D */	lis r3, lbl_802D6A84@ha
/* 8019B850 001987B0  90 1F 00 00 */	stw r0, 0(r31)
/* 8019B854 001987B4  38 83 6A 84 */	addi r4, r3, lbl_802D6A84@l
/* 8019B858 001987B8  38 7F 00 00 */	addi r3, r31, 0
/* 8019B85C 001987BC  4B EA 4E E1 */	bl init__4NodeFPc
/* 8019B860 001987C0  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8019B864 001987C4  38 00 00 01 */	li r0, 1
/* 8019B868 001987C8  38 7F 00 00 */	addi r3, r31, 0
/* 8019B86C 001987CC  90 04 00 14 */	stw r0, 0x14(r4)
/* 8019B870 001987D0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8019B874 001987D4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8019B878 001987D8  38 21 00 18 */	addi r1, r1, 0x18
/* 8019B87C 001987DC  7C 08 03 A6 */	mtlr r0
/* 8019B880 001987E0  4E 80 00 20 */	blr 

.global init__21GameStageClearSectionFv
init__21GameStageClearSectionFv:
/* 8019B884 001987E4  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802D6A58:
	.asciz "gameStageClear.cpp"
.balign 4
lbl_802D6A6C:
	.asciz "GameStageClearSection"
.balign 4
lbl_802D6A84:
	.asciz "<GameStageClearSection>"
.balign 4
lbl_802D6A9C:
	.asciz "CoreNode"
.balign 4
lbl_802D6AA8:
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
lbl_802D6AD0:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D6AE4:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte __RTTI__4Node
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D6B00:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte __RTTI__4Node
	.4byte 0x00000000
	.4byte __RTTI__7Section
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__21GameStageClearSection
__vt__21GameStageClearSection:
	.4byte __RTTI__21GameStageClearSection
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
	.4byte init__21GameStageClearSectionFv
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
lbl_803E5CB0:
	.asciz "<Node>"
.balign 4
lbl_803E5CB8:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E5CB8
	.4byte 0x00000000
__RTTI__8CoreNode:
	.4byte lbl_802D6A9C
	.4byte lbl_802D6AA8
.balign 4
lbl_803E5CD0:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803E5CD0
	.4byte lbl_802D6AD0
.balign 4
lbl_803E5CE0:
	.asciz "Section"
.balign 4
__RTTI__7Section:
	.4byte lbl_803E5CE0
	.4byte lbl_802D6AE4
__RTTI__21GameStageClearSection:
	.4byte lbl_802D6A6C
	.4byte lbl_802D6B00
