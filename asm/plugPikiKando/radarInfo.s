.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__9RadarInfoFv, global
/* 8007B564 000784C4  7C 08 02 A6 */	mflr r0
/* 8007B568 000784C8  3C 80 80 22 */	lis r4, __vt__5ANode@ha
/* 8007B56C 000784CC  90 01 00 04 */	stw r0, 4(r1)
/* 8007B570 000784D0  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8007B574 000784D4  BF 41 00 10 */	stmw r26, 0x10(r1)
/* 8007B578 000784D8  3B 43 00 00 */	addi r26, r3, 0
/* 8007B57C 000784DC  3B 64 73 8C */	addi r27, r4, __vt__5ANode@l
/* 8007B580 000784E0  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 8007B584 000784E4  3B 83 73 7C */	addi r28, r3, __vt__8CoreNode@l
/* 8007B588 000784E8  3C 60 80 2B */	lis r3, lbl_802ACC24@ha
/* 8007B58C 000784EC  3B C3 CC 24 */	addi r30, r3, lbl_802ACC24@l
/* 8007B590 000784F0  3B A0 00 00 */	li r29, 0
/* 8007B594 000784F4  38 7A 00 00 */	addi r3, r26, 0
/* 8007B598 000784F8  93 7A 00 00 */	stw r27, 0(r26)
/* 8007B59C 000784FC  7F C4 F3 78 */	mr r4, r30
/* 8007B5A0 00078500  93 9A 00 00 */	stw r28, 0(r26)
/* 8007B5A4 00078504  93 BA 00 10 */	stw r29, 0x10(r26)
/* 8007B5A8 00078508  93 BA 00 0C */	stw r29, 0xc(r26)
/* 8007B5AC 0007850C  93 BA 00 08 */	stw r29, 8(r26)
/* 8007B5B0 00078510  4B FA 99 25 */	bl setName__8CoreNodeFPc
/* 8007B5B4 00078514  3C 60 80 2B */	lis r3, __vt__Q29RadarInfo9PartsInfo@ha
/* 8007B5B8 00078518  3B E3 CC 68 */	addi r31, r3, __vt__Q29RadarInfo9PartsInfo@l
/* 8007B5BC 0007851C  93 FA 00 00 */	stw r31, 0(r26)
/* 8007B5C0 00078520  7F C4 F3 78 */	mr r4, r30
/* 8007B5C4 00078524  38 7A 00 18 */	addi r3, r26, 0x18
/* 8007B5C8 00078528  93 BA 00 14 */	stw r29, 0x14(r26)
/* 8007B5CC 0007852C  93 7A 00 18 */	stw r27, 0x18(r26)
/* 8007B5D0 00078530  93 9A 00 18 */	stw r28, 0x18(r26)
/* 8007B5D4 00078534  93 BA 00 28 */	stw r29, 0x28(r26)
/* 8007B5D8 00078538  93 BA 00 24 */	stw r29, 0x24(r26)
/* 8007B5DC 0007853C  93 BA 00 20 */	stw r29, 0x20(r26)
/* 8007B5E0 00078540  4B FA 98 F5 */	bl setName__8CoreNodeFPc
/* 8007B5E4 00078544  93 FA 00 18 */	stw r31, 0x18(r26)
/* 8007B5E8 00078548  38 8D 9B D0 */	addi r4, r13, lbl_803DE8F0@sda21
/* 8007B5EC 0007854C  38 0D 9B D8 */	addi r0, r13, lbl_803DE8F8@sda21
/* 8007B5F0 00078550  93 BA 00 2C */	stw r29, 0x2c(r26)
/* 8007B5F4 00078554  7F 43 D3 78 */	mr r3, r26
/* 8007B5F8 00078558  93 BA 00 10 */	stw r29, 0x10(r26)
/* 8007B5FC 0007855C  93 BA 00 0C */	stw r29, 0xc(r26)
/* 8007B600 00078560  93 BA 00 08 */	stw r29, 8(r26)
/* 8007B604 00078564  90 9A 00 04 */	stw r4, 4(r26)
/* 8007B608 00078568  93 BA 00 28 */	stw r29, 0x28(r26)
/* 8007B60C 0007856C  93 BA 00 24 */	stw r29, 0x24(r26)
/* 8007B610 00078570  93 BA 00 20 */	stw r29, 0x20(r26)
/* 8007B614 00078574  90 1A 00 1C */	stw r0, 0x1c(r26)
/* 8007B618 00078578  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8007B61C 0007857C  BB 41 00 10 */	lmw r26, 0x10(r1)
/* 8007B620 00078580  38 21 00 28 */	addi r1, r1, 0x28
/* 8007B624 00078584  7C 08 03 A6 */	mtlr r0
/* 8007B628 00078588  4E 80 00 20 */	blr 
.endfn __ct__9RadarInfoFv

.fn attachParts__9RadarInfoFP8Creature, global
/* 8007B62C 0007858C  7C 08 02 A6 */	mflr r0
/* 8007B630 00078590  90 01 00 04 */	stw r0, 4(r1)
/* 8007B634 00078594  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8007B638 00078598  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8007B63C 0007859C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8007B640 000785A0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8007B644 000785A4  7C 9D 23 78 */	mr r29, r4
/* 8007B648 000785A8  93 81 00 10 */	stw r28, 0x10(r1)
/* 8007B64C 000785AC  7C 7C 1B 78 */	mr r28, r3
/* 8007B650 000785B0  80 63 00 10 */	lwz r3, 0x10(r3)
/* 8007B654 000785B4  48 00 00 14 */	b .L_8007B668
.L_8007B658:
/* 8007B658 000785B8  80 03 00 14 */	lwz r0, 0x14(r3)
/* 8007B65C 000785BC  7C 00 E8 40 */	cmplw r0, r29
/* 8007B660 000785C0  41 82 00 94 */	beq .L_8007B6F4
/* 8007B664 000785C4  80 63 00 0C */	lwz r3, 0xc(r3)
.L_8007B668:
/* 8007B668 000785C8  28 03 00 00 */	cmplwi r3, 0
/* 8007B66C 000785CC  40 82 FF EC */	bne .L_8007B658
/* 8007B670 000785D0  80 1C 00 28 */	lwz r0, 0x28(r28)
/* 8007B674 000785D4  28 00 00 00 */	cmplwi r0, 0
/* 8007B678 000785D8  41 82 00 14 */	beq .L_8007B68C
/* 8007B67C 000785DC  7C 1E 03 78 */	mr r30, r0
/* 8007B680 000785E0  38 7E 00 00 */	addi r3, r30, 0
/* 8007B684 000785E4  4B FC 4F 8D */	bl del__8CoreNodeFv
/* 8007B688 000785E8  48 00 00 5C */	b .L_8007B6E4
.L_8007B68C:
/* 8007B68C 000785EC  38 60 00 18 */	li r3, 0x18
/* 8007B690 000785F0  4B FC B9 75 */	bl alloc__6SystemFUl
/* 8007B694 000785F4  3B C3 00 00 */	addi r30, r3, 0
/* 8007B698 000785F8  7F C3 F3 79 */	or. r3, r30, r30
/* 8007B69C 000785FC  41 82 00 48 */	beq .L_8007B6E4
/* 8007B6A0 00078600  3C 80 80 22 */	lis r4, __vt__5ANode@ha
/* 8007B6A4 00078604  38 04 73 8C */	addi r0, r4, __vt__5ANode@l
/* 8007B6A8 00078608  3C 80 80 22 */	lis r4, __vt__8CoreNode@ha
/* 8007B6AC 0007860C  90 1E 00 00 */	stw r0, 0(r30)
/* 8007B6B0 00078610  38 04 73 7C */	addi r0, r4, __vt__8CoreNode@l
/* 8007B6B4 00078614  90 1E 00 00 */	stw r0, 0(r30)
/* 8007B6B8 00078618  3B E0 00 00 */	li r31, 0
/* 8007B6BC 0007861C  3C 80 80 2B */	lis r4, lbl_802ACC24@ha
/* 8007B6C0 00078620  93 FE 00 10 */	stw r31, 0x10(r30)
/* 8007B6C4 00078624  38 84 CC 24 */	addi r4, r4, lbl_802ACC24@l
/* 8007B6C8 00078628  93 FE 00 0C */	stw r31, 0xc(r30)
/* 8007B6CC 0007862C  93 FE 00 08 */	stw r31, 8(r30)
/* 8007B6D0 00078630  4B FA 98 05 */	bl setName__8CoreNodeFPc
/* 8007B6D4 00078634  3C 60 80 2B */	lis r3, __vt__Q29RadarInfo9PartsInfo@ha
/* 8007B6D8 00078638  38 03 CC 68 */	addi r0, r3, __vt__Q29RadarInfo9PartsInfo@l
/* 8007B6DC 0007863C  90 1E 00 00 */	stw r0, 0(r30)
/* 8007B6E0 00078640  93 FE 00 14 */	stw r31, 0x14(r30)
.L_8007B6E4:
/* 8007B6E4 00078644  38 7C 00 00 */	addi r3, r28, 0
/* 8007B6E8 00078648  38 9E 00 00 */	addi r4, r30, 0
/* 8007B6EC 0007864C  4B FC 4E ED */	bl add__8CoreNodeFP8CoreNode
/* 8007B6F0 00078650  93 BE 00 14 */	stw r29, 0x14(r30)
.L_8007B6F4:
/* 8007B6F4 00078654  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8007B6F8 00078658  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8007B6FC 0007865C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8007B700 00078660  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8007B704 00078664  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8007B708 00078668  38 21 00 20 */	addi r1, r1, 0x20
/* 8007B70C 0007866C  7C 08 03 A6 */	mtlr r0
/* 8007B710 00078670  4E 80 00 20 */	blr 
.endfn attachParts__9RadarInfoFP8Creature

.fn detachParts__9RadarInfoFP8Creature, global
/* 8007B714 00078674  7C 08 02 A6 */	mflr r0
/* 8007B718 00078678  90 01 00 04 */	stw r0, 4(r1)
/* 8007B71C 0007867C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8007B720 00078680  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8007B724 00078684  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8007B728 00078688  7C 7E 1B 78 */	mr r30, r3
/* 8007B72C 0007868C  83 E3 00 10 */	lwz r31, 0x10(r3)
/* 8007B730 00078690  48 00 00 34 */	b .L_8007B764
.L_8007B734:
/* 8007B734 00078694  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 8007B738 00078698  7C 00 20 40 */	cmplw r0, r4
/* 8007B73C 0007869C  40 82 00 24 */	bne .L_8007B760
/* 8007B740 000786A0  7F E3 FB 78 */	mr r3, r31
/* 8007B744 000786A4  4B FC 4E CD */	bl del__8CoreNodeFv
/* 8007B748 000786A8  38 7E 00 18 */	addi r3, r30, 0x18
/* 8007B74C 000786AC  38 9F 00 00 */	addi r4, r31, 0
/* 8007B750 000786B0  4B FC 4E 89 */	bl add__8CoreNodeFP8CoreNode
/* 8007B754 000786B4  38 00 00 00 */	li r0, 0
/* 8007B758 000786B8  90 1F 00 14 */	stw r0, 0x14(r31)
/* 8007B75C 000786BC  48 00 00 10 */	b .L_8007B76C
.L_8007B760:
/* 8007B760 000786C0  83 FF 00 0C */	lwz r31, 0xc(r31)
.L_8007B764:
/* 8007B764 000786C4  28 1F 00 00 */	cmplwi r31, 0
/* 8007B768 000786C8  40 82 FF CC */	bne .L_8007B734
.L_8007B76C:
/* 8007B76C 000786CC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8007B770 000786D0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8007B774 000786D4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8007B778 000786D8  38 21 00 18 */	addi r1, r1, 0x18
/* 8007B77C 000786DC  7C 08 03 A6 */	mtlr r0
/* 8007B780 000786E0  4E 80 00 20 */	blr 
.endfn detachParts__9RadarInfoFP8Creature

.fn getPos__Q29RadarInfo9PartsInfoFv, global
/* 8007B784 000786E4  80 84 00 14 */	lwz r4, 0x14(r4)
/* 8007B788 000786E8  28 04 00 00 */	cmplwi r4, 0
/* 8007B78C 000786EC  41 82 00 20 */	beq .L_8007B7AC
/* 8007B790 000786F0  C4 04 00 94 */	lfsu f0, 0x94(r4)
/* 8007B794 000786F4  D0 03 00 00 */	stfs f0, 0(r3)
/* 8007B798 000786F8  C0 04 00 04 */	lfs f0, 4(r4)
/* 8007B79C 000786FC  D0 03 00 04 */	stfs f0, 4(r3)
/* 8007B7A0 00078700  C0 04 00 08 */	lfs f0, 8(r4)
/* 8007B7A4 00078704  D0 03 00 08 */	stfs f0, 8(r3)
/* 8007B7A8 00078708  4E 80 00 20 */	blr 
.L_8007B7AC:
/* 8007B7AC 0007870C  C0 2D 9B E4 */	lfs f1, lbl_803DE904@sda21(r13)
/* 8007B7B0 00078710  C0 4D 9B E8 */	lfs f2, lbl_803DE908@sda21(r13)
/* 8007B7B4 00078714  C0 0D 9B E0 */	lfs f0, lbl_803DE900@sda21(r13)
/* 8007B7B8 00078718  D0 03 00 00 */	stfs f0, 0(r3)
/* 8007B7BC 0007871C  D0 23 00 04 */	stfs f1, 4(r3)
/* 8007B7C0 00078720  D0 43 00 08 */	stfs f2, 8(r3)
/* 8007B7C4 00078724  4E 80 00 20 */	blr 
.endfn getPos__Q29RadarInfo9PartsInfoFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802ACC08, local
	.asciz "radarInfo.cpp"
.endobj lbl_802ACC08
.balign 4
.obj lbl_802ACC18, local
	.asciz "radarInfo"
.endobj lbl_802ACC18
.balign 4
.obj lbl_802ACC24, local
	.asciz "CoreNode"
.endobj lbl_802ACC24
.balign 4
.obj lbl_802ACC30, local
	.asciz "RadarInfo::PartsInfo"
.endobj lbl_802ACC30
.balign 4
.obj lbl_802ACC48, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.endobj lbl_802ACC48
.obj lbl_802ACC54, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.endobj lbl_802ACC54
.obj __vt__Q29RadarInfo9PartsInfo, weak
	.4byte __RTTI__Q29RadarInfo9PartsInfo
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
.endobj __vt__Q29RadarInfo9PartsInfo
	.skip 0x20

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DE8F0, local
	.asciz "alive"
.endobj lbl_803DE8F0
.balign 4
.obj lbl_803DE8F8, local
	.asciz "dead "
.endobj lbl_803DE8F8
.balign 4
.obj lbl_803DE900, local
	.float 0.0
.endobj lbl_803DE900
.obj lbl_803DE904, local
	.float 0.0
.endobj lbl_803DE904
.obj lbl_803DE908, local
	.float 0.0
.endobj lbl_803DE908
.balign 4
.obj lbl_803DE90C, local
	.asciz "ANode"
.endobj lbl_803DE90C
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803DE90C
	.4byte 0
.endobj __RTTI__5ANode
.obj __RTTI__8CoreNode, local
	.4byte lbl_802ACC24
	.4byte lbl_802ACC48
.endobj __RTTI__8CoreNode
.obj __RTTI__Q29RadarInfo9PartsInfo, local
	.4byte lbl_802ACC30
	.4byte lbl_802ACC54
.endobj __RTTI__Q29RadarInfo9PartsInfo

.section .sbss, "wa"
.balign 8
.obj radarInfo, global
	.skip 4
.endobj radarInfo
