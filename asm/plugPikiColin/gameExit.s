.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__15GameExitSectionFv
__ct__15GameExitSectionFv:
/* 8005B690 000585F0  7C 08 02 A6 */	mflr r0
/* 8005B694 000585F4  38 8D 8F A0 */	addi r4, r13, lbl_803DDCC0@sda21
/* 8005B698 000585F8  90 01 00 04 */	stw r0, 4(r1)
/* 8005B69C 000585FC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8005B6A0 00058600  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8005B6A4 00058604  3B E3 00 00 */	addi r31, r3, 0
/* 8005B6A8 00058608  4B FD 99 11 */	bl __ct__8CoreNodeFPc
/* 8005B6AC 0005860C  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 8005B6B0 00058610  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 8005B6B4 00058614  90 1F 00 00 */	stw r0, 0(r31)
/* 8005B6B8 00058618  38 7F 00 00 */	addi r3, r31, 0
/* 8005B6BC 0005861C  38 8D 8F A0 */	addi r4, r13, lbl_803DDCC0@sda21
/* 8005B6C0 00058620  4B FE 50 7D */	bl init__4NodeFPc
/* 8005B6C4 00058624  3C 60 80 2A */	lis r3, __vt__7Section@ha
/* 8005B6C8 00058628  38 03 64 2C */	addi r0, r3, __vt__7Section@l
/* 8005B6CC 0005862C  3C 60 80 2B */	lis r3, __vt__15GameExitSection@ha
/* 8005B6D0 00058630  90 1F 00 00 */	stw r0, 0(r31)
/* 8005B6D4 00058634  38 03 82 58 */	addi r0, r3, __vt__15GameExitSection@l
/* 8005B6D8 00058638  90 1F 00 00 */	stw r0, 0(r31)
/* 8005B6DC 0005863C  38 80 00 02 */	li r4, 2
/* 8005B6E0 00058640  38 A0 00 01 */	li r5, 1
/* 8005B6E4 00058644  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005B6E8 00058648  4B FE 39 4D */	bl resetHeap__9StdSystemFii
/* 8005B6EC 0005864C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005B6F0 00058650  38 A0 00 00 */	li r5, 0
/* 8005B6F4 00058654  38 0D 8F A8 */	addi r0, r13, lbl_803DDCC8@sda21
/* 8005B6F8 00058658  90 A3 01 9C */	stw r5, 0x19c(r3)
/* 8005B6FC 0005865C  7F E3 FB 78 */	mr r3, r31
/* 8005B700 00058660  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8005B704 00058664  38 84 02 14 */	addi r4, r4, 0x214
/* 8005B708 00058668  90 A4 00 10 */	stw r5, 0x10(r4)
/* 8005B70C 0005866C  90 A4 00 0C */	stw r5, 0xc(r4)
/* 8005B710 00058670  90 A4 00 08 */	stw r5, 8(r4)
/* 8005B714 00058674  90 04 00 04 */	stw r0, 4(r4)
/* 8005B718 00058678  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8005B71C 0005867C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8005B720 00058680  38 21 00 18 */	addi r1, r1, 0x18
/* 8005B724 00058684  7C 08 03 A6 */	mtlr r0
/* 8005B728 00058688  4E 80 00 20 */	blr 

.global update__15GameExitSectionFv
update__15GameExitSectionFv:
/* 8005B72C 0005868C  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005B730 00058690  38 83 D7 B8 */	addi r4, r3, gameflow@l
/* 8005B734 00058694  38 00 00 00 */	li r0, 0
/* 8005B738 00058698  3C 60 80 3A */	lis r3, flowCont@ha
/* 8005B73C 0005869C  90 04 01 F4 */	stw r0, 0x1f4(r4)
/* 8005B740 000586A0  38 63 DB 20 */	addi r3, r3, flowCont@l
/* 8005B744 000586A4  80 63 02 44 */	lwz r3, 0x244(r3)
/* 8005B748 000586A8  2C 03 00 00 */	cmpwi r3, 0
/* 8005B74C 000586AC  41 82 00 18 */	beq .L_8005B764
/* 8005B750 000586B0  38 00 00 02 */	li r0, 2
/* 8005B754 000586B4  90 04 01 F0 */	stw r0, 0x1f0(r4)
/* 8005B758 000586B8  38 03 00 03 */	addi r0, r3, 3
/* 8005B75C 000586BC  90 04 02 B0 */	stw r0, 0x2b0(r4)
/* 8005B760 000586C0  48 00 00 0C */	b .L_8005B76C
.L_8005B764:
/* 8005B764 000586C4  38 00 00 01 */	li r0, 1
/* 8005B768 000586C8  90 04 01 F0 */	stw r0, 0x1f0(r4)
.L_8005B76C:
/* 8005B76C 000586CC  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005B770 000586D0  38 00 00 01 */	li r0, 1
/* 8005B774 000586D4  98 03 00 00 */	stb r0, 0(r3)
/* 8005B778 000586D8  4E 80 00 20 */	blr 

.global init__15GameExitSectionFv
init__15GameExitSectionFv:
/* 8005B77C 000586DC  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802A81C0:
	.asciz "gameExit.cpp"
.balign 4
lbl_802A81D0:
	.asciz "GameExit"
.balign 4
lbl_802A81DC:
	.asciz "GameExitSection"
.balign 4
lbl_802A81EC:
	.asciz "CoreNode"
.balign 4
lbl_802A81F8:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
lbl_802A8204:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
lbl_802A8218:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
lbl_802A8234:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__7Section
	.4byte 0
	.4byte 0
.global __vt__15GameExitSection
__vt__15GameExitSection:
	.4byte __RTTI__15GameExitSection
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__15GameExitSectionFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte init__15GameExitSectionFv
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
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DDCC0:
	.asciz "<Node>"
.balign 4
lbl_803DDCC8:
	.asciz ""
.balign 4
lbl_803DDCCC:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803DDCCC
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802A81EC
	.4byte lbl_802A81F8
.balign 4
lbl_803DDCE4:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803DDCE4
	.4byte lbl_802A8204
.balign 4
lbl_803DDCF4:
	.asciz "Section"
.balign 4
__RTTI__7Section:
	.4byte lbl_803DDCF4
	.4byte lbl_802A8218
__RTTI__15GameExitSection:
	.4byte lbl_802A81DC
	.4byte lbl_802A8234
