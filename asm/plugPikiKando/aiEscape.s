.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__9ActEscapeFP4Piki, global
/* 800B8828 000B5788  7C 08 02 A6 */	mflr r0
/* 800B882C 000B578C  38 A0 00 00 */	li r5, 0
/* 800B8830 000B5790  90 01 00 04 */	stw r0, 4(r1)
/* 800B8834 000B5794  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B8838 000B5798  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B883C 000B579C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800B8840 000B57A0  90 61 00 08 */	stw r3, 8(r1)
/* 800B8844 000B57A4  80 61 00 08 */	lwz r3, 8(r1)
/* 800B8848 000B57A8  48 00 B5 89 */	bl __ct__6ActionFP4Pikib
/* 800B884C 000B57AC  3C 60 80 2B */	lis r3, __vt__9ActEscape@ha
/* 800B8850 000B57B0  83 C1 00 08 */	lwz r30, 8(r1)
/* 800B8854 000B57B4  38 03 66 54 */	addi r0, r3, __vt__9ActEscape@l
/* 800B8858 000B57B8  90 1E 00 00 */	stw r0, 0(r30)
/* 800B885C 000B57BC  3B E0 00 00 */	li r31, 0
/* 800B8860 000B57C0  93 FE 00 14 */	stw r31, 0x14(r30)
/* 800B8864 000B57C4  C0 02 92 10 */	lfs f0, lbl_803E9410@sda21(r2)
/* 800B8868 000B57C8  D0 1E 00 2C */	stfs f0, 0x2c(r30)
/* 800B886C 000B57CC  D0 1E 00 28 */	stfs f0, 0x28(r30)
/* 800B8870 000B57D0  D0 1E 00 24 */	stfs f0, 0x24(r30)
/* 800B8874 000B57D4  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 800B8878 000B57D8  28 03 00 00 */	cmplwi r3, 0
/* 800B887C 000B57DC  41 82 00 0C */	beq .L_800B8888
/* 800B8880 000B57E0  48 02 BA ED */	bl subCnt__12RefCountableFv
/* 800B8884 000B57E4  93 FE 00 14 */	stw r31, 0x14(r30)
.L_800B8888:
/* 800B8888 000B57E8  80 61 00 08 */	lwz r3, 8(r1)
/* 800B888C 000B57EC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B8890 000B57F0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B8894 000B57F4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800B8898 000B57F8  38 21 00 18 */	addi r1, r1, 0x18
/* 800B889C 000B57FC  7C 08 03 A6 */	mtlr r0
/* 800B88A0 000B5800  4E 80 00 20 */	blr 
.endfn __ct__9ActEscapeFP4Piki

.fn initialise__Q29ActEscape11InitialiserFP6Action, global
/* 800B88A4 000B5804  4E 80 00 20 */	blr 
.endfn initialise__Q29ActEscape11InitialiserFP6Action

.fn init__9ActEscapeFP8Creature, global
/* 800B88A8 000B5808  7C 08 02 A6 */	mflr r0
/* 800B88AC 000B580C  90 01 00 04 */	stw r0, 4(r1)
/* 800B88B0 000B5810  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800B88B4 000B5814  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800B88B8 000B5818  3B E4 00 00 */	addi r31, r4, 0
/* 800B88BC 000B581C  93 C1 00 30 */	stw r30, 0x30(r1)
/* 800B88C0 000B5820  3B C3 00 00 */	addi r30, r3, 0
/* 800B88C4 000B5824  48 15 F7 AD */	bl rand
/* 800B88C8 000B5828  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800B88CC 000B582C  C8 82 92 28 */	lfd f4, lbl_803E9428@sda21(r2)
/* 800B88D0 000B5830  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800B88D4 000B5834  3C 00 43 30 */	lis r0, 0x4330
/* 800B88D8 000B5838  C0 62 92 18 */	lfs f3, lbl_803E9418@sda21(r2)
/* 800B88DC 000B583C  90 01 00 28 */	stw r0, 0x28(r1)
/* 800B88E0 000B5840  C0 42 92 14 */	lfs f2, lbl_803E9414@sda21(r2)
/* 800B88E4 000B5844  C8 21 00 28 */	lfd f1, 0x28(r1)
/* 800B88E8 000B5848  C0 02 92 20 */	lfs f0, lbl_803E9420@sda21(r2)
/* 800B88EC 000B584C  EC 81 20 28 */	fsubs f4, f1, f4
/* 800B88F0 000B5850  C0 22 92 1C */	lfs f1, lbl_803E941C@sda21(r2)
/* 800B88F4 000B5854  EC 64 18 24 */	fdivs f3, f4, f3
/* 800B88F8 000B5858  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800B88FC 000B585C  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800B8900 000B5860  EC 01 00 2A */	fadds f0, f1, f0
/* 800B8904 000B5864  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 800B8908 000B5868  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 800B890C 000B586C  28 03 00 00 */	cmplwi r3, 0
/* 800B8910 000B5870  41 82 00 14 */	beq .L_800B8924
/* 800B8914 000B5874  41 82 00 10 */	beq .L_800B8924
/* 800B8918 000B5878  48 02 BA 55 */	bl subCnt__12RefCountableFv
/* 800B891C 000B587C  38 00 00 00 */	li r0, 0
/* 800B8920 000B5880  90 1E 00 14 */	stw r0, 0x14(r30)
.L_800B8924:
/* 800B8924 000B5884  93 FE 00 14 */	stw r31, 0x14(r30)
/* 800B8928 000B5888  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 800B892C 000B588C  28 03 00 00 */	cmplwi r3, 0
/* 800B8930 000B5890  41 82 00 08 */	beq .L_800B8938
/* 800B8934 000B5894  48 02 BA 29 */	bl addCnt__12RefCountableFv
.L_800B8938:
/* 800B8938 000B5898  38 00 00 00 */	li r0, 0
/* 800B893C 000B589C  90 1E 00 20 */	stw r0, 0x20(r30)
/* 800B8940 000B58A0  38 61 00 14 */	addi r3, r1, 0x14
/* 800B8944 000B58A4  38 80 00 01 */	li r4, 1
/* 800B8948 000B58A8  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 800B894C 000B58AC  C0 0D B5 D0 */	lfs f0, lbl_803E02F0@sda21(r13)
/* 800B8950 000B58B0  D4 05 00 A4 */	stfsu f0, 0xa4(r5)
/* 800B8954 000B58B4  C0 0D B5 D4 */	lfs f0, lbl_803E02F4@sda21(r13)
/* 800B8958 000B58B8  D0 05 00 04 */	stfs f0, 4(r5)
/* 800B895C 000B58BC  C0 0D B5 D8 */	lfs f0, lbl_803E02F8@sda21(r13)
/* 800B8960 000B58C0  D0 05 00 08 */	stfs f0, 8(r5)
/* 800B8964 000B58C4  48 06 65 F5 */	bl __ct__14PaniMotionInfoFi
/* 800B8968 000B58C8  3B E3 00 00 */	addi r31, r3, 0
/* 800B896C 000B58CC  38 61 00 1C */	addi r3, r1, 0x1c
/* 800B8970 000B58D0  38 80 00 01 */	li r4, 1
/* 800B8974 000B58D4  48 06 65 E5 */	bl __ct__14PaniMotionInfoFi
/* 800B8978 000B58D8  7C 64 1B 78 */	mr r4, r3
/* 800B897C 000B58DC  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B8980 000B58E0  7F E5 FB 78 */	mr r5, r31
/* 800B8984 000B58E4  48 01 20 55 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800B8988 000B58E8  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800B898C 000B58EC  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800B8990 000B58F0  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 800B8994 000B58F4  38 21 00 38 */	addi r1, r1, 0x38
/* 800B8998 000B58F8  7C 08 03 A6 */	mtlr r0
/* 800B899C 000B58FC  4E 80 00 20 */	blr 
.endfn init__9ActEscapeFP8Creature

.fn cleanup__9ActEscapeFv, global
/* 800B89A0 000B5900  7C 08 02 A6 */	mflr r0
/* 800B89A4 000B5904  90 01 00 04 */	stw r0, 4(r1)
/* 800B89A8 000B5908  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B89AC 000B590C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B89B0 000B5910  7C 7F 1B 78 */	mr r31, r3
/* 800B89B4 000B5914  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800B89B8 000B5918  28 03 00 00 */	cmplwi r3, 0
/* 800B89BC 000B591C  41 82 00 10 */	beq .L_800B89CC
/* 800B89C0 000B5920  48 02 B9 AD */	bl subCnt__12RefCountableFv
/* 800B89C4 000B5924  38 00 00 00 */	li r0, 0
/* 800B89C8 000B5928  90 1F 00 14 */	stw r0, 0x14(r31)
.L_800B89CC:
/* 800B89CC 000B592C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B89D0 000B5930  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B89D4 000B5934  38 21 00 18 */	addi r1, r1, 0x18
/* 800B89D8 000B5938  7C 08 03 A6 */	mtlr r0
/* 800B89DC 000B593C  4E 80 00 20 */	blr 
.endfn cleanup__9ActEscapeFv

.fn exec__9ActEscapeFv, global
/* 800B89E0 000B5940  7C 08 02 A6 */	mflr r0
/* 800B89E4 000B5944  90 01 00 04 */	stw r0, 4(r1)
/* 800B89E8 000B5948  94 21 FF 50 */	stwu r1, -0xb0(r1)
/* 800B89EC 000B594C  DB E1 00 A8 */	stfd f31, 0xa8(r1)
/* 800B89F0 000B5950  DB C1 00 A0 */	stfd f30, 0xa0(r1)
/* 800B89F4 000B5954  93 E1 00 9C */	stw r31, 0x9c(r1)
/* 800B89F8 000B5958  93 C1 00 98 */	stw r30, 0x98(r1)
/* 800B89FC 000B595C  7C 7E 1B 78 */	mr r30, r3
/* 800B8A00 000B5960  83 E3 00 14 */	lwz r31, 0x14(r3)
/* 800B8A04 000B5964  81 9F 00 00 */	lwz r12, 0(r31)
/* 800B8A08 000B5968  7F E3 FB 78 */	mr r3, r31
/* 800B8A0C 000B596C  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800B8A10 000B5970  7D 88 03 A6 */	mtlr r12
/* 800B8A14 000B5974  4E 80 00 21 */	blrl 
/* 800B8A18 000B5978  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B8A1C 000B597C  40 82 00 0C */	bne .L_800B8A28
/* 800B8A20 000B5980  38 60 00 01 */	li r3, 1
/* 800B8A24 000B5984  48 00 02 68 */	b .L_800B8C8C
.L_800B8A28:
/* 800B8A28 000B5988  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800B8A2C 000B598C  C0 3E 00 18 */	lfs f1, 0x18(r30)
/* 800B8A30 000B5990  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800B8A34 000B5994  EC 01 00 28 */	fsubs f0, f1, f0
/* 800B8A38 000B5998  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 800B8A3C 000B599C  C0 3E 00 18 */	lfs f1, 0x18(r30)
/* 800B8A40 000B59A0  C0 02 92 10 */	lfs f0, lbl_803E9410@sda21(r2)
/* 800B8A44 000B59A4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B8A48 000B59A8  40 80 00 0C */	bge .L_800B8A54
/* 800B8A4C 000B59AC  38 60 00 02 */	li r3, 2
/* 800B8A50 000B59B0  48 00 02 3C */	b .L_800B8C8C
.L_800B8A54:
/* 800B8A54 000B59B4  C0 02 92 30 */	lfs f0, lbl_803E9430@sda21(r2)
/* 800B8A58 000B59B8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B8A5C 000B59BC  40 81 00 08 */	ble .L_800B8A64
/* 800B8A60 000B59C0  D0 1E 00 18 */	stfs f0, 0x18(r30)
.L_800B8A64:
/* 800B8A64 000B59C4  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 800B8A68 000B59C8  2C 00 00 01 */	cmpwi r0, 1
/* 800B8A6C 000B59CC  41 82 01 CC */	beq .L_800B8C38
/* 800B8A70 000B59D0  40 80 02 18 */	bge .L_800B8C88
/* 800B8A74 000B59D4  2C 00 00 00 */	cmpwi r0, 0
/* 800B8A78 000B59D8  40 80 00 08 */	bge .L_800B8A80
/* 800B8A7C 000B59DC  48 00 02 0C */	b .L_800B8C88
.L_800B8A80:
/* 800B8A80 000B59E0  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B8A84 000B59E4  C4 23 00 94 */	lfsu f1, 0x94(r3)
/* 800B8A88 000B59E8  C0 1F 00 94 */	lfs f0, 0x94(r31)
/* 800B8A8C 000B59EC  C0 63 00 04 */	lfs f3, 4(r3)
/* 800B8A90 000B59F0  C0 5F 00 98 */	lfs f2, 0x98(r31)
/* 800B8A94 000B59F4  EC 01 00 28 */	fsubs f0, f1, f0
/* 800B8A98 000B59F8  C0 83 00 08 */	lfs f4, 8(r3)
/* 800B8A9C 000B59FC  C0 3F 00 9C */	lfs f1, 0x9c(r31)
/* 800B8AA0 000B5A00  EC 43 10 28 */	fsubs f2, f3, f2
/* 800B8AA4 000B5A04  D0 01 00 80 */	stfs f0, 0x80(r1)
/* 800B8AA8 000B5A08  EC 04 08 28 */	fsubs f0, f4, f1
/* 800B8AAC 000B5A0C  D0 41 00 84 */	stfs f2, 0x84(r1)
/* 800B8AB0 000B5A10  D0 01 00 88 */	stfs f0, 0x88(r1)
/* 800B8AB4 000B5A14  C0 21 00 80 */	lfs f1, 0x80(r1)
/* 800B8AB8 000B5A18  C0 61 00 88 */	lfs f3, 0x88(r1)
/* 800B8ABC 000B5A1C  C0 01 00 84 */	lfs f0, 0x84(r1)
/* 800B8AC0 000B5A20  EC 41 00 72 */	fmuls f2, f1, f1
/* 800B8AC4 000B5A24  EC 63 00 F2 */	fmuls f3, f3, f3
/* 800B8AC8 000B5A28  EC 20 00 32 */	fmuls f1, f0, f0
/* 800B8ACC 000B5A2C  C0 02 92 10 */	lfs f0, lbl_803E9410@sda21(r2)
/* 800B8AD0 000B5A30  EC 22 08 2A */	fadds f1, f2, f1
/* 800B8AD4 000B5A34  EC 83 08 2A */	fadds f4, f3, f1
/* 800B8AD8 000B5A38  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 800B8ADC 000B5A3C  40 81 00 5C */	ble .L_800B8B38
/* 800B8AE0 000B5A40  FC 20 20 34 */	frsqrte f1, f4
/* 800B8AE4 000B5A44  C8 62 92 38 */	lfd f3, lbl_803E9438@sda21(r2)
/* 800B8AE8 000B5A48  C8 42 92 40 */	lfd f2, lbl_803E9440@sda21(r2)
/* 800B8AEC 000B5A4C  FC 01 00 72 */	fmul f0, f1, f1
/* 800B8AF0 000B5A50  FC 23 00 72 */	fmul f1, f3, f1
/* 800B8AF4 000B5A54  FC 04 00 32 */	fmul f0, f4, f0
/* 800B8AF8 000B5A58  FC 02 00 28 */	fsub f0, f2, f0
/* 800B8AFC 000B5A5C  FC 21 00 32 */	fmul f1, f1, f0
/* 800B8B00 000B5A60  FC 01 00 72 */	fmul f0, f1, f1
/* 800B8B04 000B5A64  FC 23 00 72 */	fmul f1, f3, f1
/* 800B8B08 000B5A68  FC 04 00 32 */	fmul f0, f4, f0
/* 800B8B0C 000B5A6C  FC 02 00 28 */	fsub f0, f2, f0
/* 800B8B10 000B5A70  FC 21 00 32 */	fmul f1, f1, f0
/* 800B8B14 000B5A74  FC 01 00 72 */	fmul f0, f1, f1
/* 800B8B18 000B5A78  FC 23 00 72 */	fmul f1, f3, f1
/* 800B8B1C 000B5A7C  FC 04 00 32 */	fmul f0, f4, f0
/* 800B8B20 000B5A80  FC 02 00 28 */	fsub f0, f2, f0
/* 800B8B24 000B5A84  FC 01 00 32 */	fmul f0, f1, f0
/* 800B8B28 000B5A88  FC 04 00 32 */	fmul f0, f4, f0
/* 800B8B2C 000B5A8C  FC 00 00 18 */	frsp f0, f0
/* 800B8B30 000B5A90  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 800B8B34 000B5A94  C0 81 00 38 */	lfs f4, 0x38(r1)
.L_800B8B38:
/* 800B8B38 000B5A98  C0 02 92 10 */	lfs f0, lbl_803E9410@sda21(r2)
/* 800B8B3C 000B5A9C  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 800B8B40 000B5AA0  40 81 00 34 */	ble .L_800B8B74
/* 800B8B44 000B5AA4  C0 22 92 14 */	lfs f1, lbl_803E9414@sda21(r2)
/* 800B8B48 000B5AA8  C0 01 00 80 */	lfs f0, 0x80(r1)
/* 800B8B4C 000B5AAC  EC 61 20 24 */	fdivs f3, f1, f4
/* 800B8B50 000B5AB0  C0 21 00 84 */	lfs f1, 0x84(r1)
/* 800B8B54 000B5AB4  C0 41 00 88 */	lfs f2, 0x88(r1)
/* 800B8B58 000B5AB8  EC 00 00 F2 */	fmuls f0, f0, f3
/* 800B8B5C 000B5ABC  EC 81 00 F2 */	fmuls f4, f1, f3
/* 800B8B60 000B5AC0  EC 22 00 F2 */	fmuls f1, f2, f3
/* 800B8B64 000B5AC4  D0 01 00 80 */	stfs f0, 0x80(r1)
/* 800B8B68 000B5AC8  D0 81 00 84 */	stfs f4, 0x84(r1)
/* 800B8B6C 000B5ACC  D0 21 00 88 */	stfs f1, 0x88(r1)
/* 800B8B70 000B5AD0  48 00 00 68 */	b .L_800B8BD8
.L_800B8B74:
/* 800B8B74 000B5AD4  48 15 F4 FD */	bl rand
/* 800B8B78 000B5AD8  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800B8B7C 000B5ADC  C8 82 92 28 */	lfd f4, lbl_803E9428@sda21(r2)
/* 800B8B80 000B5AE0  90 01 00 94 */	stw r0, 0x94(r1)
/* 800B8B84 000B5AE4  3C 00 43 30 */	lis r0, 0x4330
/* 800B8B88 000B5AE8  C0 62 92 18 */	lfs f3, lbl_803E9418@sda21(r2)
/* 800B8B8C 000B5AEC  90 01 00 90 */	stw r0, 0x90(r1)
/* 800B8B90 000B5AF0  C0 42 92 14 */	lfs f2, lbl_803E9414@sda21(r2)
/* 800B8B94 000B5AF4  C8 21 00 90 */	lfd f1, 0x90(r1)
/* 800B8B98 000B5AF8  C0 02 92 48 */	lfs f0, lbl_803E9448@sda21(r2)
/* 800B8B9C 000B5AFC  EC 81 20 28 */	fsubs f4, f1, f4
/* 800B8BA0 000B5B00  C0 22 92 20 */	lfs f1, lbl_803E9420@sda21(r2)
/* 800B8BA4 000B5B04  EC 64 18 24 */	fdivs f3, f4, f3
/* 800B8BA8 000B5B08  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800B8BAC 000B5B0C  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800B8BB0 000B5B10  EF C1 00 32 */	fmuls f30, f1, f0
/* 800B8BB4 000B5B14  FC 20 F0 90 */	fmr f1, f30
/* 800B8BB8 000B5B18  48 16 31 31 */	bl sinf
/* 800B8BBC 000B5B1C  FF E0 08 90 */	fmr f31, f1
/* 800B8BC0 000B5B20  FC 20 F0 90 */	fmr f1, f30
/* 800B8BC4 000B5B24  48 16 2F 91 */	bl cosf
/* 800B8BC8 000B5B28  D0 21 00 80 */	stfs f1, 0x80(r1)
/* 800B8BCC 000B5B2C  C0 0D B5 DC */	lfs f0, lbl_803E02FC@sda21(r13)
/* 800B8BD0 000B5B30  D0 01 00 84 */	stfs f0, 0x84(r1)
/* 800B8BD4 000B5B34  D3 E1 00 88 */	stfs f31, 0x88(r1)
.L_800B8BD8:
/* 800B8BD8 000B5B38  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B8BDC 000B5B3C  38 81 00 80 */	addi r4, r1, 0x80
/* 800B8BE0 000B5B40  C0 22 92 14 */	lfs f1, lbl_803E9414@sda21(r2)
/* 800B8BE4 000B5B44  48 01 31 F5 */	bl setSpeed__4PikiFfR8Vector3f
/* 800B8BE8 000B5B48  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B8BEC 000B5B4C  38 BE 00 24 */	addi r5, r30, 0x24
/* 800B8BF0 000B5B50  38 83 00 A4 */	addi r4, r3, 0xa4
/* 800B8BF4 000B5B54  4B FD 49 49 */	bl getAvoid__8CreatureFR8Vector3fR8Vector3f
/* 800B8BF8 000B5B58  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B8BFC 000B5B5C  41 82 00 8C */	beq .L_800B8C88
/* 800B8C00 000B5B60  38 00 00 01 */	li r0, 1
/* 800B8C04 000B5B64  90 1E 00 20 */	stw r0, 0x20(r30)
/* 800B8C08 000B5B68  38 81 00 64 */	addi r4, r1, 0x64
/* 800B8C0C 000B5B6C  C0 3E 00 2C */	lfs f1, 0x2c(r30)
/* 800B8C10 000B5B70  C0 0D B5 E0 */	lfs f0, lbl_803E0300@sda21(r13)
/* 800B8C14 000B5B74  FC 40 08 50 */	fneg f2, f1
/* 800B8C18 000B5B78  C0 22 92 14 */	lfs f1, lbl_803E9414@sda21(r2)
/* 800B8C1C 000B5B7C  D0 41 00 64 */	stfs f2, 0x64(r1)
/* 800B8C20 000B5B80  D0 01 00 68 */	stfs f0, 0x68(r1)
/* 800B8C24 000B5B84  C0 1E 00 24 */	lfs f0, 0x24(r30)
/* 800B8C28 000B5B88  D0 01 00 6C */	stfs f0, 0x6c(r1)
/* 800B8C2C 000B5B8C  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B8C30 000B5B90  48 01 31 A9 */	bl setSpeed__4PikiFfR8Vector3f
/* 800B8C34 000B5B94  48 00 00 54 */	b .L_800B8C88
.L_800B8C38:
/* 800B8C38 000B5B98  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B8C3C 000B5B9C  38 BE 00 24 */	addi r5, r30, 0x24
/* 800B8C40 000B5BA0  38 83 00 A4 */	addi r4, r3, 0xa4
/* 800B8C44 000B5BA4  4B FD 48 F9 */	bl getAvoid__8CreatureFR8Vector3fR8Vector3f
/* 800B8C48 000B5BA8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B8C4C 000B5BAC  41 82 00 34 */	beq .L_800B8C80
/* 800B8C50 000B5BB0  C0 3E 00 2C */	lfs f1, 0x2c(r30)
/* 800B8C54 000B5BB4  38 81 00 58 */	addi r4, r1, 0x58
/* 800B8C58 000B5BB8  C0 0D B5 E4 */	lfs f0, lbl_803E0304@sda21(r13)
/* 800B8C5C 000B5BBC  FC 40 08 50 */	fneg f2, f1
/* 800B8C60 000B5BC0  C0 22 92 14 */	lfs f1, lbl_803E9414@sda21(r2)
/* 800B8C64 000B5BC4  D0 41 00 58 */	stfs f2, 0x58(r1)
/* 800B8C68 000B5BC8  D0 01 00 5C */	stfs f0, 0x5c(r1)
/* 800B8C6C 000B5BCC  C0 1E 00 24 */	lfs f0, 0x24(r30)
/* 800B8C70 000B5BD0  D0 01 00 60 */	stfs f0, 0x60(r1)
/* 800B8C74 000B5BD4  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B8C78 000B5BD8  48 01 31 61 */	bl setSpeed__4PikiFfR8Vector3f
/* 800B8C7C 000B5BDC  48 00 00 0C */	b .L_800B8C88
.L_800B8C80:
/* 800B8C80 000B5BE0  38 00 00 00 */	li r0, 0
/* 800B8C84 000B5BE4  90 1E 00 20 */	stw r0, 0x20(r30)
.L_800B8C88:
/* 800B8C88 000B5BE8  38 60 00 00 */	li r3, 0
.L_800B8C8C:
/* 800B8C8C 000B5BEC  80 01 00 B4 */	lwz r0, 0xb4(r1)
/* 800B8C90 000B5BF0  CB E1 00 A8 */	lfd f31, 0xa8(r1)
/* 800B8C94 000B5BF4  CB C1 00 A0 */	lfd f30, 0xa0(r1)
/* 800B8C98 000B5BF8  83 E1 00 9C */	lwz r31, 0x9c(r1)
/* 800B8C9C 000B5BFC  83 C1 00 98 */	lwz r30, 0x98(r1)
/* 800B8CA0 000B5C00  38 21 00 B0 */	addi r1, r1, 0xb0
/* 800B8CA4 000B5C04  7C 08 03 A6 */	mtlr r0
/* 800B8CA8 000B5C08  4E 80 00 20 */	blr 
.endfn exec__9ActEscapeFv

.fn getInfo__9ActEscapeFPc, global
/* 800B8CAC 000B5C0C  7C 08 02 A6 */	mflr r0
/* 800B8CB0 000B5C10  90 01 00 04 */	stw r0, 4(r1)
/* 800B8CB4 000B5C14  94 21 FF F8 */	stwu r1, -8(r1)
/* 800B8CB8 000B5C18  80 03 00 20 */	lwz r0, 0x20(r3)
/* 800B8CBC 000B5C1C  2C 00 00 00 */	cmpwi r0, 0
/* 800B8CC0 000B5C20  40 82 00 0C */	bne .L_800B8CCC
/* 800B8CC4 000B5C24  38 AD B5 E8 */	addi r5, r13, lbl_803E0308@sda21
/* 800B8CC8 000B5C28  48 00 00 08 */	b .L_800B8CD0
.L_800B8CCC:
/* 800B8CCC 000B5C2C  38 AD B5 F0 */	addi r5, r13, lbl_803E0310@sda21
.L_800B8CD0:
/* 800B8CD0 000B5C30  80 C3 00 0C */	lwz r6, 0xc(r3)
/* 800B8CD4 000B5C34  3C 60 80 2B */	lis r3, lbl_802B6604@ha
/* 800B8CD8 000B5C38  38 03 66 04 */	addi r0, r3, lbl_802B6604@l
/* 800B8CDC 000B5C3C  4C C6 32 42 */	crset 6
/* 800B8CE0 000B5C40  C0 26 00 A4 */	lfs f1, 0xa4(r6)
/* 800B8CE4 000B5C44  38 64 00 00 */	addi r3, r4, 0
/* 800B8CE8 000B5C48  C0 46 00 AC */	lfs f2, 0xac(r6)
/* 800B8CEC 000B5C4C  7C 04 03 78 */	mr r4, r0
/* 800B8CF0 000B5C50  48 15 D8 A9 */	bl sprintf
/* 800B8CF4 000B5C54  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800B8CF8 000B5C58  38 21 00 08 */	addi r1, r1, 8
/* 800B8CFC 000B5C5C  7C 08 03 A6 */	mtlr r0
/* 800B8D00 000B5C60  4E 80 00 20 */	blr 
.endfn getInfo__9ActEscapeFPc

.fn __dt__9ActEscapeFv, weak
/* 800B8D04 000B5C64  7C 08 02 A6 */	mflr r0
/* 800B8D08 000B5C68  90 01 00 04 */	stw r0, 4(r1)
/* 800B8D0C 000B5C6C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B8D10 000B5C70  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B8D14 000B5C74  3B E4 00 00 */	addi r31, r4, 0
/* 800B8D18 000B5C78  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800B8D1C 000B5C7C  7C 7E 1B 79 */	or. r30, r3, r3
/* 800B8D20 000B5C80  41 82 00 2C */	beq .L_800B8D4C
/* 800B8D24 000B5C84  3C 60 80 2B */	lis r3, __vt__9ActEscape@ha
/* 800B8D28 000B5C88  38 03 66 54 */	addi r0, r3, __vt__9ActEscape@l
/* 800B8D2C 000B5C8C  90 1E 00 00 */	stw r0, 0(r30)
/* 800B8D30 000B5C90  38 7E 00 00 */	addi r3, r30, 0
/* 800B8D34 000B5C94  38 80 00 00 */	li r4, 0
/* 800B8D38 000B5C98  48 00 B0 D1 */	bl __dt__6ActionFv
/* 800B8D3C 000B5C9C  7F E0 07 35 */	extsh. r0, r31
/* 800B8D40 000B5CA0  40 81 00 0C */	ble .L_800B8D4C
/* 800B8D44 000B5CA4  7F C3 F3 78 */	mr r3, r30
/* 800B8D48 000B5CA8  4B F8 E4 65 */	bl __dl__FPv
.L_800B8D4C:
/* 800B8D4C 000B5CAC  7F C3 F3 78 */	mr r3, r30
/* 800B8D50 000B5CB0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B8D54 000B5CB4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B8D58 000B5CB8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800B8D5C 000B5CBC  38 21 00 18 */	addi r1, r1, 0x18
/* 800B8D60 000B5CC0  7C 08 03 A6 */	mtlr r0
/* 800B8D64 000B5CC4  4E 80 00 20 */	blr 
.endfn __dt__9ActEscapeFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B65E8, local
	.asciz "aiEscape.cpp"
.endobj lbl_802B65E8
.balign 4
.obj lbl_802B65F8, local
	.asciz "aiEscape"
.endobj lbl_802B65F8
.balign 4
.obj lbl_802B6604, local
	.asciz "esc(%s) (%.1f,%.1f)"
.endobj lbl_802B6604
.balign 4
.obj lbl_802B6618, local
	.asciz "ActEscape"
.endobj lbl_802B6618
.balign 4
.obj lbl_802B6624, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B6624
.balign 4
.obj lbl_802B6634, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B6634
.obj lbl_802B6640, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0x00000000
	.4byte __RTTI__6Action
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B6640
.obj __vt__9ActEscape, global
	.4byte __RTTI__9ActEscape
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__6ActionFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__9ActEscapeFv
	.4byte init__9ActEscapeFP8Creature
	.4byte exec__9ActEscapeFv
	.4byte cleanup__9ActEscapeFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__9ActEscapeFPc
.endobj __vt__9ActEscape
.balign 4
.obj lbl_802B66B8, local
	.asciz "ActEscape::Initialiser"
.endobj lbl_802B66B8
.balign 4
.obj lbl_802B66D0, local
	.asciz "Action::Initialiser"
.endobj lbl_802B66D0
.balign 4
.obj lbl_802B66E4, local
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte 0
.endobj lbl_802B66E4
.obj __vt__Q29ActEscape11Initialiser, global
	.4byte __RTTI__Q29ActEscape11Initialiser
	.4byte 0
	.4byte initialise__Q29ActEscape11InitialiserFP6Action
.endobj __vt__Q29ActEscape11Initialiser
.obj lbl_802B66FC, local
	.4byte .L_800A7908
	.4byte .L_800A7930
	.4byte .L_800A7944
	.4byte .L_800A7958
	.4byte .L_800A796C
	.4byte .L_800A7980
	.4byte .L_800A7994
	.4byte .L_800A79A8
	.4byte .L_800A791C
	.4byte .L_800A79D0
	.4byte .L_800A79BC
.endobj lbl_802B66FC

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E02F0, local
	.float 0.0
.endobj lbl_803E02F0
.obj lbl_803E02F4, local
	.float 0.0
.endobj lbl_803E02F4
.obj lbl_803E02F8, local
	.float 0.0
.endobj lbl_803E02F8
.obj lbl_803E02FC, local
	.float 0.0
.endobj lbl_803E02FC
.obj lbl_803E0300, local
	.float 0.0
.endobj lbl_803E0300
.obj lbl_803E0304, local
	.float 0.0
.endobj lbl_803E0304
.balign 4
.obj lbl_803E0308, local
	.asciz "NORMAL"
.endobj lbl_803E0308
.balign 4
.obj lbl_803E0310, local
	.asciz "AVOID"
.endobj lbl_803E0310
.balign 4
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B6624
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E0320, local
	.asciz "Action"
.endobj lbl_803E0320
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E0320
	.4byte lbl_802B6634
.endobj __RTTI__6Action
.obj __RTTI__9ActEscape, local
	.4byte lbl_802B6618
	.4byte lbl_802B6640
.endobj __RTTI__9ActEscape
.obj __RTTI__Q26Action11Initialiser, local
	.4byte lbl_802B66D0
	.4byte 0
.endobj __RTTI__Q26Action11Initialiser
.obj __RTTI__Q29ActEscape11Initialiser, local
	.4byte lbl_802B66B8
	.4byte lbl_802B66E4
.endobj __RTTI__Q29ActEscape11Initialiser

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9410, local
	.float 0.0
.endobj lbl_803E9410
.obj lbl_803E9414, local
	.float 1.0
.endobj lbl_803E9414
.obj lbl_803E9418, local
	.float 32767.0
.endobj lbl_803E9418
.obj lbl_803E941C, local
	.float 4.0
.endobj lbl_803E941C
.obj lbl_803E9420, local
	.float 2.0
.endobj lbl_803E9420
.balign 8
.obj lbl_803E9428, local
	.8byte 0x4330000080000000
.endobj lbl_803E9428
.obj lbl_803E9430, local
	.float 10.0
.endobj lbl_803E9430
.balign 8
.obj lbl_803E9438, local
	.double 0.5
.endobj lbl_803E9438
.obj lbl_803E9440, local
	.double 3.0
.endobj lbl_803E9440
.obj lbl_803E9448, local
	.float 3.1415927
.endobj lbl_803E9448
