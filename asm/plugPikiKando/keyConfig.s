.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn createInstance__9KeyConfigFv, global
/* 800846C0 00081620  7C 08 02 A6 */	mflr r0
/* 800846C4 00081624  90 01 00 04 */	stw r0, 4(r1)
/* 800846C8 00081628  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800846CC 0008162C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800846D0 00081630  80 0D 2F 98 */	lwz r0, _instance__9KeyConfig@sda21(r13)
/* 800846D4 00081634  28 00 00 00 */	cmplwi r0, 0
/* 800846D8 00081638  40 82 00 20 */	bne .L_800846F8
/* 800846DC 0008163C  38 60 00 F8 */	li r3, 0xf8
/* 800846E0 00081640  4B FC 29 25 */	bl alloc__6SystemFUl
/* 800846E4 00081644  3B E3 00 00 */	addi r31, r3, 0
/* 800846E8 00081648  7F E3 FB 79 */	or. r3, r31, r31
/* 800846EC 0008164C  41 82 00 08 */	beq .L_800846F4
/* 800846F0 00081650  48 00 00 1D */	bl __ct__9KeyConfigFv
.L_800846F4:
/* 800846F4 00081654  93 ED 2F 98 */	stw r31, _instance__9KeyConfig@sda21(r13)
.L_800846F8:
/* 800846F8 00081658  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800846FC 0008165C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80084700 00081660  38 21 00 10 */	addi r1, r1, 0x10
/* 80084704 00081664  7C 08 03 A6 */	mtlr r0
/* 80084708 00081668  4E 80 00 20 */	blr 
.endfn createInstance__9KeyConfigFv

.fn __ct__9KeyConfigFv, global
/* 8008470C 0008166C  7C 08 02 A6 */	mflr r0
/* 80084710 00081670  3C 80 80 22 */	lis r4, __vt__5ANode@ha
/* 80084714 00081674  90 01 00 04 */	stw r0, 4(r1)
/* 80084718 00081678  38 04 73 8C */	addi r0, r4, __vt__5ANode@l
/* 8008471C 0008167C  3C 80 80 2B */	lis r4, lbl_802AE7E0@ha
/* 80084720 00081680  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80084724 00081684  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80084728 00081688  3B E3 00 00 */	addi r31, r3, 0
/* 8008472C 0008168C  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 80084730 00081690  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80084734 00081694  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80084738 00081698  93 81 00 10 */	stw r28, 0x10(r1)
/* 8008473C 0008169C  3B 84 E7 E0 */	addi r28, r4, lbl_802AE7E0@l
/* 80084740 000816A0  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 80084744 000816A4  90 1F 00 00 */	stw r0, 0(r31)
/* 80084748 000816A8  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 8008474C 000816AC  38 7F 00 00 */	addi r3, r31, 0
/* 80084750 000816B0  90 1F 00 00 */	stw r0, 0(r31)
/* 80084754 000816B4  38 00 00 00 */	li r0, 0
/* 80084758 000816B8  90 1F 00 10 */	stw r0, 0x10(r31)
/* 8008475C 000816BC  90 1F 00 0C */	stw r0, 0xc(r31)
/* 80084760 000816C0  90 1F 00 08 */	stw r0, 8(r31)
/* 80084764 000816C4  4B FA 07 71 */	bl setName__8CoreNodeFPc
/* 80084768 000816C8  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 8008476C 000816CC  3B A3 8E 20 */	addi r29, r3, __vt__4Node@l
/* 80084770 000816D0  93 BF 00 00 */	stw r29, 0(r31)
/* 80084774 000816D4  38 7F 00 00 */	addi r3, r31, 0
/* 80084778 000816D8  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 8008477C 000816DC  4B FB BF C1 */	bl init__4NodeFPc
/* 80084780 000816E0  3C 60 80 2B */	lis r3, __vt__9KeyConfig@ha
/* 80084784 000816E4  38 03 E8 D4 */	addi r0, r3, __vt__9KeyConfig@l
/* 80084788 000816E8  90 1F 00 00 */	stw r0, 0(r31)
/* 8008478C 000816EC  38 7F 00 20 */	addi r3, r31, 0x20
/* 80084790 000816F0  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 80084794 000816F4  4B FB 08 25 */	bl __ct__8CoreNodeFPc
/* 80084798 000816F8  93 BF 00 20 */	stw r29, 0x20(r31)
/* 8008479C 000816FC  38 7F 00 20 */	addi r3, r31, 0x20
/* 800847A0 00081700  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 800847A4 00081704  4B FB BF 99 */	bl init__4NodeFPc
/* 800847A8 00081708  3C 60 80 2B */	lis r3, __vt__Q29KeyConfig3Key@ha
/* 800847AC 0008170C  3B C3 E8 7C */	addi r30, r3, __vt__Q29KeyConfig3Key@l
/* 800847B0 00081710  93 DF 00 20 */	stw r30, 0x20(r31)
/* 800847B4 00081714  38 7F 00 44 */	addi r3, r31, 0x44
/* 800847B8 00081718  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 800847BC 0008171C  4B FB 07 FD */	bl __ct__8CoreNodeFPc
/* 800847C0 00081720  93 BF 00 44 */	stw r29, 0x44(r31)
/* 800847C4 00081724  38 7F 00 44 */	addi r3, r31, 0x44
/* 800847C8 00081728  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 800847CC 0008172C  4B FB BF 71 */	bl init__4NodeFPc
/* 800847D0 00081730  93 DF 00 44 */	stw r30, 0x44(r31)
/* 800847D4 00081734  38 7F 00 68 */	addi r3, r31, 0x68
/* 800847D8 00081738  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 800847DC 0008173C  4B FB 07 DD */	bl __ct__8CoreNodeFPc
/* 800847E0 00081740  93 BF 00 68 */	stw r29, 0x68(r31)
/* 800847E4 00081744  38 7F 00 68 */	addi r3, r31, 0x68
/* 800847E8 00081748  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 800847EC 0008174C  4B FB BF 51 */	bl init__4NodeFPc
/* 800847F0 00081750  93 DF 00 68 */	stw r30, 0x68(r31)
/* 800847F4 00081754  38 7F 00 8C */	addi r3, r31, 0x8c
/* 800847F8 00081758  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 800847FC 0008175C  4B FB 07 BD */	bl __ct__8CoreNodeFPc
/* 80084800 00081760  93 BF 00 8C */	stw r29, 0x8c(r31)
/* 80084804 00081764  38 7F 00 8C */	addi r3, r31, 0x8c
/* 80084808 00081768  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 8008480C 0008176C  4B FB BF 31 */	bl init__4NodeFPc
/* 80084810 00081770  93 DF 00 8C */	stw r30, 0x8c(r31)
/* 80084814 00081774  38 7F 00 B0 */	addi r3, r31, 0xb0
/* 80084818 00081778  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 8008481C 0008177C  4B FB 07 9D */	bl __ct__8CoreNodeFPc
/* 80084820 00081780  93 BF 00 B0 */	stw r29, 0xb0(r31)
/* 80084824 00081784  38 7F 00 B0 */	addi r3, r31, 0xb0
/* 80084828 00081788  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 8008482C 0008178C  4B FB BF 11 */	bl init__4NodeFPc
/* 80084830 00081790  93 DF 00 B0 */	stw r30, 0xb0(r31)
/* 80084834 00081794  38 7F 00 D4 */	addi r3, r31, 0xd4
/* 80084838 00081798  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 8008483C 0008179C  4B FB 07 7D */	bl __ct__8CoreNodeFPc
/* 80084840 000817A0  93 BF 00 D4 */	stw r29, 0xd4(r31)
/* 80084844 000817A4  38 7F 00 D4 */	addi r3, r31, 0xd4
/* 80084848 000817A8  38 8D A0 80 */	addi r4, r13, lbl_803DEDA0@sda21
/* 8008484C 000817AC  4B FB BE F1 */	bl init__4NodeFPc
/* 80084850 000817B0  93 DF 00 D4 */	stw r30, 0xd4(r31)
/* 80084854 000817B4  38 0D A0 88 */	addi r0, r13, lbl_803DEDA8@sda21
/* 80084858 000817B8  3C 60 00 01 */	lis r3, 0x00008000@ha
/* 8008485C 000817BC  90 1F 00 24 */	stw r0, 0x24(r31)
/* 80084860 000817C0  39 40 10 00 */	li r10, 0x1000
/* 80084864 000817C4  38 BC 00 1C */	addi r5, r28, 0x1c
/* 80084868 000817C8  91 5F 00 40 */	stw r10, 0x40(r31)
/* 8008486C 000817CC  38 80 20 00 */	li r4, 0x2000
/* 80084870 000817D0  38 0D A0 90 */	addi r0, r13, lbl_803DEDB0@sda21
/* 80084874 000817D4  90 BF 00 48 */	stw r5, 0x48(r31)
/* 80084878 000817D8  38 DC 00 2C */	addi r6, r28, 0x2c
/* 8008487C 000817DC  39 2D A0 98 */	addi r9, r13, lbl_803DEDB8@sda21
/* 80084880 000817E0  90 9F 00 64 */	stw r4, 0x64(r31)
/* 80084884 000817E4  39 00 40 00 */	li r8, 0x4000
/* 80084888 000817E8  38 FC 00 38 */	addi r7, r28, 0x38
/* 8008488C 000817EC  90 1F 00 6C */	stw r0, 0x6c(r31)
/* 80084890 000817F0  38 03 80 00 */	addi r0, r3, 0x00008000@l
/* 80084894 000817F4  38 7F 00 00 */	addi r3, r31, 0
/* 80084898 000817F8  90 9F 00 88 */	stw r4, 0x88(r31)
/* 8008489C 000817FC  38 8D A0 A0 */	addi r4, r13, lbl_803DEDC0@sda21
/* 800848A0 00081800  38 AD A0 A8 */	addi r5, r13, lbl_803DEDC8@sda21
/* 800848A4 00081804  90 DF 00 90 */	stw r6, 0x90(r31)
/* 800848A8 00081808  38 C0 00 01 */	li r6, 1
/* 800848AC 0008180C  91 5F 00 AC */	stw r10, 0xac(r31)
/* 800848B0 00081810  91 3F 00 D8 */	stw r9, 0xd8(r31)
/* 800848B4 00081814  91 1F 00 F4 */	stw r8, 0xf4(r31)
/* 800848B8 00081818  90 FF 00 B4 */	stw r7, 0xb4(r31)
/* 800848BC 0008181C  90 1F 00 D0 */	stw r0, 0xd0(r31)
/* 800848C0 00081820  4B FB BD E1 */	bl load__8CoreNodeFPcPcUl
/* 800848C4 00081824  7F E3 FB 78 */	mr r3, r31
/* 800848C8 00081828  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800848CC 0008182C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800848D0 00081830  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800848D4 00081834  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800848D8 00081838  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800848DC 0008183C  38 21 00 20 */	addi r1, r1, 0x20
/* 800848E0 00081840  7C 08 03 A6 */	mtlr r0
/* 800848E4 00081844  4E 80 00 20 */	blr 
.endfn __ct__9KeyConfigFv

.fn read__9KeyConfigFR18RandomAccessStream, global
/* 800848E8 00081848  7C 08 02 A6 */	mflr r0
/* 800848EC 0008184C  90 01 00 04 */	stw r0, 4(r1)
/* 800848F0 00081850  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800848F4 00081854  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800848F8 00081858  7C 9F 23 78 */	mr r31, r4
/* 800848FC 0008185C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80084900 00081860  3B C3 00 00 */	addi r30, r3, 0
/* 80084904 00081864  38 7E 00 20 */	addi r3, r30, 0x20
/* 80084908 00081868  81 9E 00 20 */	lwz r12, 0x20(r30)
/* 8008490C 0008186C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80084910 00081870  7D 88 03 A6 */	mtlr r12
/* 80084914 00081874  4E 80 00 21 */	blrl 
/* 80084918 00081878  38 7E 00 44 */	addi r3, r30, 0x44
/* 8008491C 0008187C  81 9E 00 44 */	lwz r12, 0x44(r30)
/* 80084920 00081880  7F E4 FB 78 */	mr r4, r31
/* 80084924 00081884  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80084928 00081888  7D 88 03 A6 */	mtlr r12
/* 8008492C 0008188C  4E 80 00 21 */	blrl 
/* 80084930 00081890  38 7E 00 68 */	addi r3, r30, 0x68
/* 80084934 00081894  81 9E 00 68 */	lwz r12, 0x68(r30)
/* 80084938 00081898  7F E4 FB 78 */	mr r4, r31
/* 8008493C 0008189C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80084940 000818A0  7D 88 03 A6 */	mtlr r12
/* 80084944 000818A4  4E 80 00 21 */	blrl 
/* 80084948 000818A8  38 7E 00 8C */	addi r3, r30, 0x8c
/* 8008494C 000818AC  81 9E 00 8C */	lwz r12, 0x8c(r30)
/* 80084950 000818B0  7F E4 FB 78 */	mr r4, r31
/* 80084954 000818B4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80084958 000818B8  7D 88 03 A6 */	mtlr r12
/* 8008495C 000818BC  4E 80 00 21 */	blrl 
/* 80084960 000818C0  38 7E 00 D4 */	addi r3, r30, 0xd4
/* 80084964 000818C4  81 9E 00 D4 */	lwz r12, 0xd4(r30)
/* 80084968 000818C8  7F E4 FB 78 */	mr r4, r31
/* 8008496C 000818CC  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80084970 000818D0  7D 88 03 A6 */	mtlr r12
/* 80084974 000818D4  4E 80 00 21 */	blrl 
/* 80084978 000818D8  38 7E 00 B0 */	addi r3, r30, 0xb0
/* 8008497C 000818DC  81 9E 00 B0 */	lwz r12, 0xb0(r30)
/* 80084980 000818E0  7F E4 FB 78 */	mr r4, r31
/* 80084984 000818E4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80084988 000818E8  7D 88 03 A6 */	mtlr r12
/* 8008498C 000818EC  4E 80 00 21 */	blrl 
/* 80084990 000818F0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80084994 000818F4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80084998 000818F8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8008499C 000818FC  38 21 00 18 */	addi r1, r1, 0x18
/* 800849A0 00081900  7C 08 03 A6 */	mtlr r0
/* 800849A4 00081904  4E 80 00 20 */	blr 
.endfn read__9KeyConfigFR18RandomAccessStream

.fn read__Q29KeyConfig3KeyFR18RandomAccessStream, global
/* 800849A8 00081908  7C 08 02 A6 */	mflr r0
/* 800849AC 0008190C  90 01 00 04 */	stw r0, 4(r1)
/* 800849B0 00081910  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800849B4 00081914  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800849B8 00081918  3B E3 00 00 */	addi r31, r3, 0
/* 800849BC 0008191C  38 64 00 00 */	addi r3, r4, 0
/* 800849C0 00081920  81 84 00 04 */	lwz r12, 4(r4)
/* 800849C4 00081924  81 8C 00 08 */	lwz r12, 8(r12)
/* 800849C8 00081928  7D 88 03 A6 */	mtlr r12
/* 800849CC 0008192C  4E 80 00 21 */	blrl 
/* 800849D0 00081930  90 7F 00 20 */	stw r3, 0x20(r31)
/* 800849D4 00081934  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800849D8 00081938  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800849DC 0008193C  38 21 00 18 */	addi r1, r1, 0x18
/* 800849E0 00081940  7C 08 03 A6 */	mtlr r0
/* 800849E4 00081944  4E 80 00 20 */	blr 
.endfn read__Q29KeyConfig3KeyFR18RandomAccessStream

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802AE7E0, local
	.asciz "keyConfig.cpp"
.endobj lbl_802AE7E0
.balign 4
.obj lbl_802AE7F0, local
	.asciz "keyConfig"
.endobj lbl_802AE7F0
.balign 4
.obj lbl_802AE7FC, local # Shift-JIS
	.4byte 0x8F578D87
	.4byte 0x834A815B
	.4byte 0x835C838B
	.byte 0
.endobj lbl_802AE7FC
.balign 4
.obj lbl_802AE80C, local # Shift-JIS
	.4byte 0x8341835E
	.4byte 0x8362834E
	.byte 0
.endobj lbl_802AE80C
.balign 4
.obj lbl_802AE818, local # Shift-JIS
	.4byte 0x8381836A
	.4byte 0x8385815B
	.byte 0
.endobj lbl_802AE818
.balign 4
.obj lbl_802AE824, local
	.asciz "KeyConfig::Key"
.endobj lbl_802AE824
.balign 4
.obj lbl_802AE834, local
	.asciz "CoreNode"
.endobj lbl_802AE834
.balign 4
.obj lbl_802AE840, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.endobj lbl_802AE840
.obj lbl_802AE84C, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.endobj lbl_802AE84C
.obj lbl_802AE860, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.endobj lbl_802AE860
.obj __vt__Q29KeyConfig3Key, global
	.4byte __RTTI__Q29KeyConfig3Key
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__Q29KeyConfig3KeyFR18RandomAccessStream
	.4byte update__4NodeFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
.endobj __vt__Q29KeyConfig3Key
.balign 4
.obj lbl_802AE8AC, local
	.asciz "KeyConfig"
.endobj lbl_802AE8AC
.balign 4
.obj lbl_802AE8B8, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.endobj lbl_802AE8B8
.obj __vt__9KeyConfig, global
	.4byte __RTTI__9KeyConfig
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__9KeyConfigFR18RandomAccessStream
	.4byte update__4NodeFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
.endobj __vt__9KeyConfig
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DEDA0, local
	.asciz "<Node>"
.endobj lbl_803DEDA0
.balign 4
.obj lbl_803DEDA8, local # Shift-JIS
	.4byte 0x938A82B0
	.byte 0
.endobj lbl_803DEDA8
.balign 4
.obj lbl_803DEDB0, local # Shift-JIS
	.4byte 0x94B282AB
	.byte 0
.endobj lbl_803DEDB0
.balign 4
.obj lbl_803DEDB8, local # Shift-JIS
	.4byte 0x89F08E55
	.byte 0
.endobj lbl_803DEDB8
.balign 4
.obj lbl_803DEDC0, local
	.asciz "parms/"
.endobj lbl_803DEDC0
.balign 4
.obj lbl_803DEDC8, local
	.asciz "key.bin"
.endobj lbl_803DEDC8
.balign 4
.obj lbl_803DEDD0, local
	.asciz "ANode"
.endobj lbl_803DEDD0
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803DEDD0
	.4byte 0
.endobj __RTTI__5ANode
.obj __RTTI__8CoreNode, local
	.4byte lbl_802AE834
	.4byte lbl_802AE840
.endobj __RTTI__8CoreNode
.balign 4
.obj lbl_803DEDE8, local
	.asciz "Node"
.endobj lbl_803DEDE8
.balign 4
.obj __RTTI__4Node, local
	.4byte lbl_803DEDE8
	.4byte lbl_802AE84C
.endobj __RTTI__4Node
.obj __RTTI__Q29KeyConfig3Key, local
	.4byte lbl_802AE824
	.4byte lbl_802AE860
.endobj __RTTI__Q29KeyConfig3Key
.obj __RTTI__9KeyConfig, local
	.4byte lbl_802AE8AC
	.4byte lbl_802AE8B8
.endobj __RTTI__9KeyConfig

.section .sbss, "wa"
.balign 8
.obj _instance__9KeyConfig, global
	.skip 4
.endobj _instance__9KeyConfig
