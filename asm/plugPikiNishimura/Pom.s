.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__7PomPropFv
__ct__7PomPropFv:
/* 80177DE0 00174D40  7C 08 02 A6 */	mflr r0
/* 80177DE4 00174D44  90 01 00 04 */	stw r0, 4(r1)
/* 80177DE8 00174D48  94 21 FF 20 */	stwu r1, -0xe0(r1)
/* 80177DEC 00174D4C  93 E1 00 DC */	stw r31, 0xdc(r1)
/* 80177DF0 00174D50  93 C1 00 D8 */	stw r30, 0xd8(r1)
/* 80177DF4 00174D54  93 A1 00 D4 */	stw r29, 0xd4(r1)
/* 80177DF8 00174D58  7C 7D 1B 78 */	mr r29, r3
/* 80177DFC 00174D5C  93 81 00 D0 */	stw r28, 0xd0(r1)
/* 80177E00 00174D60  4B FD 5A CD */	bl __ct__8BossPropFv
/* 80177E04 00174D64  3C 60 80 22 */	lis r3, __vt__5ANode@ha
/* 80177E08 00174D68  38 03 73 8C */	addi r0, r3, __vt__5ANode@l
/* 80177E0C 00174D6C  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 80177E10 00174D70  90 1D 01 EC */	stw r0, 0x1ec(r29)
/* 80177E14 00174D74  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 80177E18 00174D78  90 1D 01 EC */	stw r0, 0x1ec(r29)
/* 80177E1C 00174D7C  3B C0 00 00 */	li r30, 0
/* 80177E20 00174D80  3C 60 80 2D */	lis r3, __vt__7PomProp@ha
/* 80177E24 00174D84  93 DD 01 FC */	stw r30, 0x1fc(r29)
/* 80177E28 00174D88  38 C3 0C E0 */	addi r6, r3, __vt__7PomProp@l
/* 80177E2C 00174D8C  3C 80 80 2D */	lis r4, lbl_802D0A78@ha
/* 80177E30 00174D90  93 DD 01 F8 */	stw r30, 0x1f8(r29)
/* 80177E34 00174D94  38 64 0A 78 */	addi r3, r4, lbl_802D0A78@l
/* 80177E38 00174D98  38 06 00 0C */	addi r0, r6, 0xc
/* 80177E3C 00174D9C  93 DD 01 F4 */	stw r30, 0x1f4(r29)
/* 80177E40 00174DA0  38 A1 00 68 */	addi r5, r1, 0x68
/* 80177E44 00174DA4  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177E48 00174DA8  90 7D 01 F0 */	stw r3, 0x1f0(r29)
/* 80177E4C 00174DAC  38 7D 02 04 */	addi r3, r29, 0x204
/* 80177E50 00174DB0  90 DD 00 54 */	stw r6, 0x54(r29)
/* 80177E54 00174DB4  90 1D 01 EC */	stw r0, 0x1ec(r29)
/* 80177E58 00174DB8  93 DD 02 00 */	stw r30, 0x200(r29)
/* 80177E5C 00174DBC  80 0D 05 AC */	lwz r0, lbl_803E52CC@sda21(r13)
/* 80177E60 00174DC0  90 01 00 70 */	stw r0, 0x70(r1)
/* 80177E64 00174DC4  80 01 00 70 */	lwz r0, 0x70(r1)
/* 80177E68 00174DC8  90 01 00 68 */	stw r0, 0x68(r1)
/* 80177E6C 00174DCC  4B EE 6C 15 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80177E70 00174DD0  3C 60 80 2A */	lis r3, "__vt__7Parm<f>"@ha
/* 80177E74 00174DD4  3B 83 60 98 */	addi r28, r3, "__vt__7Parm<f>"@l
/* 80177E78 00174DD8  93 9D 02 0C */	stw r28, 0x20c(r29)
/* 80177E7C 00174DDC  38 A1 00 64 */	addi r5, r1, 0x64
/* 80177E80 00174DE0  38 7D 02 14 */	addi r3, r29, 0x214
/* 80177E84 00174DE4  C0 02 AD B0 */	lfs f0, lbl_803EAFB0@sda21(r2)
/* 80177E88 00174DE8  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177E8C 00174DEC  D0 1D 02 10 */	stfs f0, 0x210(r29)
/* 80177E90 00174DF0  80 0D 05 B0 */	lwz r0, lbl_803E52D0@sda21(r13)
/* 80177E94 00174DF4  90 01 00 78 */	stw r0, 0x78(r1)
/* 80177E98 00174DF8  80 01 00 78 */	lwz r0, 0x78(r1)
/* 80177E9C 00174DFC  90 01 00 64 */	stw r0, 0x64(r1)
/* 80177EA0 00174E00  4B EE 6B E1 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80177EA4 00174E04  93 9D 02 1C */	stw r28, 0x21c(r29)
/* 80177EA8 00174E08  38 A1 00 60 */	addi r5, r1, 0x60
/* 80177EAC 00174E0C  38 7D 02 24 */	addi r3, r29, 0x224
/* 80177EB0 00174E10  C0 02 AD B4 */	lfs f0, lbl_803EAFB4@sda21(r2)
/* 80177EB4 00174E14  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177EB8 00174E18  D0 1D 02 20 */	stfs f0, 0x220(r29)
/* 80177EBC 00174E1C  80 0D 05 B4 */	lwz r0, lbl_803E52D4@sda21(r13)
/* 80177EC0 00174E20  90 01 00 80 */	stw r0, 0x80(r1)
/* 80177EC4 00174E24  80 01 00 80 */	lwz r0, 0x80(r1)
/* 80177EC8 00174E28  90 01 00 60 */	stw r0, 0x60(r1)
/* 80177ECC 00174E2C  4B EE 6B B5 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80177ED0 00174E30  93 9D 02 2C */	stw r28, 0x22c(r29)
/* 80177ED4 00174E34  38 A1 00 5C */	addi r5, r1, 0x5c
/* 80177ED8 00174E38  38 7D 02 34 */	addi r3, r29, 0x234
/* 80177EDC 00174E3C  C0 02 AD B8 */	lfs f0, lbl_803EAFB8@sda21(r2)
/* 80177EE0 00174E40  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177EE4 00174E44  D0 1D 02 30 */	stfs f0, 0x230(r29)
/* 80177EE8 00174E48  80 0D 05 B8 */	lwz r0, lbl_803E52D8@sda21(r13)
/* 80177EEC 00174E4C  90 01 00 88 */	stw r0, 0x88(r1)
/* 80177EF0 00174E50  80 01 00 88 */	lwz r0, 0x88(r1)
/* 80177EF4 00174E54  90 01 00 5C */	stw r0, 0x5c(r1)
/* 80177EF8 00174E58  4B EE 6B 89 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80177EFC 00174E5C  93 9D 02 3C */	stw r28, 0x23c(r29)
/* 80177F00 00174E60  38 A1 00 58 */	addi r5, r1, 0x58
/* 80177F04 00174E64  38 7D 02 44 */	addi r3, r29, 0x244
/* 80177F08 00174E68  C0 02 AD BC */	lfs f0, lbl_803EAFBC@sda21(r2)
/* 80177F0C 00174E6C  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177F10 00174E70  D0 1D 02 40 */	stfs f0, 0x240(r29)
/* 80177F14 00174E74  80 0D 05 BC */	lwz r0, lbl_803E52DC@sda21(r13)
/* 80177F18 00174E78  90 01 00 90 */	stw r0, 0x90(r1)
/* 80177F1C 00174E7C  80 01 00 90 */	lwz r0, 0x90(r1)
/* 80177F20 00174E80  90 01 00 58 */	stw r0, 0x58(r1)
/* 80177F24 00174E84  4B EE 6B 5D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80177F28 00174E88  93 9D 02 4C */	stw r28, 0x24c(r29)
/* 80177F2C 00174E8C  38 A1 00 54 */	addi r5, r1, 0x54
/* 80177F30 00174E90  38 7D 02 54 */	addi r3, r29, 0x254
/* 80177F34 00174E94  C0 02 AD C0 */	lfs f0, lbl_803EAFC0@sda21(r2)
/* 80177F38 00174E98  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177F3C 00174E9C  D0 1D 02 50 */	stfs f0, 0x250(r29)
/* 80177F40 00174EA0  80 0D 05 C0 */	lwz r0, lbl_803E52E0@sda21(r13)
/* 80177F44 00174EA4  90 01 00 98 */	stw r0, 0x98(r1)
/* 80177F48 00174EA8  80 01 00 98 */	lwz r0, 0x98(r1)
/* 80177F4C 00174EAC  90 01 00 54 */	stw r0, 0x54(r1)
/* 80177F50 00174EB0  4B EE 6B 31 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80177F54 00174EB4  3C 60 80 2A */	lis r3, "__vt__7Parm<i>"@ha
/* 80177F58 00174EB8  3B E3 60 C4 */	addi r31, r3, "__vt__7Parm<i>"@l
/* 80177F5C 00174EBC  93 FD 02 5C */	stw r31, 0x25c(r29)
/* 80177F60 00174EC0  3B 80 00 0A */	li r28, 0xa
/* 80177F64 00174EC4  38 A1 00 50 */	addi r5, r1, 0x50
/* 80177F68 00174EC8  93 9D 02 60 */	stw r28, 0x260(r29)
/* 80177F6C 00174ECC  38 7D 02 64 */	addi r3, r29, 0x264
/* 80177F70 00174ED0  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177F74 00174ED4  80 0D 05 C4 */	lwz r0, lbl_803E52E4@sda21(r13)
/* 80177F78 00174ED8  90 01 00 A0 */	stw r0, 0xa0(r1)
/* 80177F7C 00174EDC  80 01 00 A0 */	lwz r0, 0xa0(r1)
/* 80177F80 00174EE0  90 01 00 50 */	stw r0, 0x50(r1)
/* 80177F84 00174EE4  4B EE 6A FD */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80177F88 00174EE8  93 FD 02 6C */	stw r31, 0x26c(r29)
/* 80177F8C 00174EEC  38 A1 00 4C */	addi r5, r1, 0x4c
/* 80177F90 00174EF0  38 7D 02 74 */	addi r3, r29, 0x274
/* 80177F94 00174EF4  93 9D 02 70 */	stw r28, 0x270(r29)
/* 80177F98 00174EF8  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177F9C 00174EFC  80 0D 05 C8 */	lwz r0, lbl_803E52E8@sda21(r13)
/* 80177FA0 00174F00  90 01 00 A8 */	stw r0, 0xa8(r1)
/* 80177FA4 00174F04  80 01 00 A8 */	lwz r0, 0xa8(r1)
/* 80177FA8 00174F08  90 01 00 4C */	stw r0, 0x4c(r1)
/* 80177FAC 00174F0C  4B EE 6A D5 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80177FB0 00174F10  93 FD 02 7C */	stw r31, 0x27c(r29)
/* 80177FB4 00174F14  38 A1 00 48 */	addi r5, r1, 0x48
/* 80177FB8 00174F18  38 7D 02 84 */	addi r3, r29, 0x284
/* 80177FBC 00174F1C  93 9D 02 80 */	stw r28, 0x280(r29)
/* 80177FC0 00174F20  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177FC4 00174F24  80 0D 05 CC */	lwz r0, lbl_803E52EC@sda21(r13)
/* 80177FC8 00174F28  90 01 00 B0 */	stw r0, 0xb0(r1)
/* 80177FCC 00174F2C  80 01 00 B0 */	lwz r0, 0xb0(r1)
/* 80177FD0 00174F30  90 01 00 48 */	stw r0, 0x48(r1)
/* 80177FD4 00174F34  4B EE 6A AD */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80177FD8 00174F38  93 FD 02 8C */	stw r31, 0x28c(r29)
/* 80177FDC 00174F3C  38 A1 00 44 */	addi r5, r1, 0x44
/* 80177FE0 00174F40  38 7D 02 94 */	addi r3, r29, 0x294
/* 80177FE4 00174F44  93 DD 02 90 */	stw r30, 0x290(r29)
/* 80177FE8 00174F48  38 9D 02 00 */	addi r4, r29, 0x200
/* 80177FEC 00174F4C  80 0D 05 D0 */	lwz r0, lbl_803E52F0@sda21(r13)
/* 80177FF0 00174F50  90 01 00 B8 */	stw r0, 0xb8(r1)
/* 80177FF4 00174F54  80 01 00 B8 */	lwz r0, 0xb8(r1)
/* 80177FF8 00174F58  90 01 00 44 */	stw r0, 0x44(r1)
/* 80177FFC 00174F5C  4B EE 6A 85 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80178000 00174F60  93 FD 02 9C */	stw r31, 0x29c(r29)
/* 80178004 00174F64  38 A1 00 40 */	addi r5, r1, 0x40
/* 80178008 00174F68  38 7D 02 A4 */	addi r3, r29, 0x2a4
/* 8017800C 00174F6C  93 DD 02 A0 */	stw r30, 0x2a0(r29)
/* 80178010 00174F70  38 9D 02 00 */	addi r4, r29, 0x200
/* 80178014 00174F74  80 0D 05 D4 */	lwz r0, lbl_803E52F4@sda21(r13)
/* 80178018 00174F78  90 01 00 C0 */	stw r0, 0xc0(r1)
/* 8017801C 00174F7C  80 01 00 C0 */	lwz r0, 0xc0(r1)
/* 80178020 00174F80  90 01 00 40 */	stw r0, 0x40(r1)
/* 80178024 00174F84  4B EE 6A 5D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80178028 00174F88  93 FD 02 AC */	stw r31, 0x2ac(r29)
/* 8017802C 00174F8C  38 00 00 01 */	li r0, 1
/* 80178030 00174F90  38 A1 00 3C */	addi r5, r1, 0x3c
/* 80178034 00174F94  90 1D 02 B0 */	stw r0, 0x2b0(r29)
/* 80178038 00174F98  38 7D 02 B4 */	addi r3, r29, 0x2b4
/* 8017803C 00174F9C  38 9D 02 00 */	addi r4, r29, 0x200
/* 80178040 00174FA0  80 0D 05 D8 */	lwz r0, lbl_803E52F8@sda21(r13)
/* 80178044 00174FA4  90 01 00 C8 */	stw r0, 0xc8(r1)
/* 80178048 00174FA8  80 01 00 C8 */	lwz r0, 0xc8(r1)
/* 8017804C 00174FAC  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80178050 00174FB0  4B EE 6A 31 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80178054 00174FB4  93 FD 02 BC */	stw r31, 0x2bc(r29)
/* 80178058 00174FB8  7F A3 EB 78 */	mr r3, r29
/* 8017805C 00174FBC  93 DD 02 C0 */	stw r30, 0x2c0(r29)
/* 80178060 00174FC0  C0 22 AD C4 */	lfs f1, lbl_803EAFC4@sda21(r2)
/* 80178064 00174FC4  D0 3D 00 10 */	stfs f1, 0x10(r29)
/* 80178068 00174FC8  C0 02 AD C8 */	lfs f0, lbl_803EAFC8@sda21(r2)
/* 8017806C 00174FCC  D0 1D 00 30 */	stfs f0, 0x30(r29)
/* 80178070 00174FD0  D0 3D 00 40 */	stfs f1, 0x40(r29)
/* 80178074 00174FD4  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 80178078 00174FD8  83 E1 00 DC */	lwz r31, 0xdc(r1)
/* 8017807C 00174FDC  83 C1 00 D8 */	lwz r30, 0xd8(r1)
/* 80178080 00174FE0  83 A1 00 D4 */	lwz r29, 0xd4(r1)
/* 80178084 00174FE4  83 81 00 D0 */	lwz r28, 0xd0(r1)
/* 80178088 00174FE8  38 21 00 E0 */	addi r1, r1, 0xe0
/* 8017808C 00174FEC  7C 08 03 A6 */	mtlr r0
/* 80178090 00174FF0  4E 80 00 20 */	blr 

.global __ct__3PomFP12CreatureProp
__ct__3PomFP12CreatureProp:
/* 80178094 00174FF4  7C 08 02 A6 */	mflr r0
/* 80178098 00174FF8  90 01 00 04 */	stw r0, 4(r1)
/* 8017809C 00174FFC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801780A0 00175000  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801780A4 00175004  93 C1 00 10 */	stw r30, 0x10(r1)
/* 801780A8 00175008  7C 7E 1B 78 */	mr r30, r3
/* 801780AC 0017500C  4B FD 5D CD */	bl __ct__4BossFP12CreatureProp
/* 801780B0 00175010  3C 60 80 2D */	lis r3, __vt__3Pom@ha
/* 801780B4 00175014  38 03 0B 00 */	addi r0, r3, __vt__3Pom@l
/* 801780B8 00175018  90 1E 00 00 */	stw r0, 0(r30)
/* 801780BC 0017501C  38 00 00 00 */	li r0, 0
/* 801780C0 00175020  38 60 00 14 */	li r3, 0x14
/* 801780C4 00175024  90 1E 03 C4 */	stw r0, 0x3c4(r30)
/* 801780C8 00175028  90 1E 03 C8 */	stw r0, 0x3c8(r30)
/* 801780CC 0017502C  90 1E 03 CC */	stw r0, 0x3cc(r30)
/* 801780D0 00175030  90 1E 03 D0 */	stw r0, 0x3d0(r30)
/* 801780D4 00175034  4B EC EF 31 */	bl alloc__6SystemFUl
/* 801780D8 00175038  3B E3 00 00 */	addi r31, r3, 0
/* 801780DC 0017503C  7F E3 FB 79 */	or. r3, r31, r31
/* 801780E0 00175040  41 82 00 0C */	beq lbl_801780EC
/* 801780E4 00175044  38 80 00 10 */	li r4, 0x10
/* 801780E8 00175048  4B F1 0B 49 */	bl __ct__8CollInfoFi
lbl_801780EC:
/* 801780EC 0017504C  93 FE 02 20 */	stw r31, 0x220(r30)
/* 801780F0 00175050  38 60 00 24 */	li r3, 0x24
/* 801780F4 00175054  4B EC EF 11 */	bl alloc__6SystemFUl
/* 801780F8 00175058  3B E3 00 00 */	addi r31, r3, 0
/* 801780FC 0017505C  7F E3 FB 79 */	or. r3, r31, r31
/* 80178100 00175060  41 82 00 0C */	beq lbl_8017810C
/* 80178104 00175064  7F C4 F3 78 */	mr r4, r30
/* 80178108 00175068  48 00 04 51 */	bl __ct__5PomAiFP3Pom
lbl_8017810C:
/* 8017810C 0017506C  93 FE 03 C0 */	stw r31, 0x3c0(r30)
/* 80178110 00175070  7F C3 F3 78 */	mr r3, r30
/* 80178114 00175074  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80178118 00175078  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017811C 0017507C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80178120 00175080  38 21 00 18 */	addi r1, r1, 0x18
/* 80178124 00175084  7C 08 03 A6 */	mtlr r0
/* 80178128 00175088  4E 80 00 20 */	blr 

.global getiMass__3PomFv
getiMass__3PomFv:
/* 8017812C 0017508C  C0 22 AD CC */	lfs f1, lbl_803EAFCC@sda21(r2)
/* 80178130 00175090  4E 80 00 20 */	blr 

.global init__3PomFR8Vector3f
init__3PomFR8Vector3f:
/* 80178134 00175094  7C 08 02 A6 */	mflr r0
/* 80178138 00175098  38 A0 00 00 */	li r5, 0
/* 8017813C 0017509C  90 01 00 04 */	stw r0, 4(r1)
/* 80178140 001750A0  38 00 00 01 */	li r0, 1
/* 80178144 001750A4  38 83 00 00 */	addi r4, r3, 0
/* 80178148 001750A8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017814C 001750AC  C0 02 AD D0 */	lfs f0, lbl_803EAFD0@sda21(r2)
/* 80178150 001750B0  D0 03 02 70 */	stfs f0, 0x270(r3)
/* 80178154 001750B4  98 A3 02 BB */	stb r5, 0x2bb(r3)
/* 80178158 001750B8  98 03 02 BC */	stb r0, 0x2bc(r3)
/* 8017815C 001750BC  98 03 02 BE */	stb r0, 0x2be(r3)
/* 80178160 001750C0  C0 02 AD D4 */	lfs f0, lbl_803EAFD4@sda21(r2)
/* 80178164 001750C4  D0 03 02 E0 */	stfs f0, 0x2e0(r3)
/* 80178168 001750C8  98 A3 03 B8 */	stb r5, 0x3b8(r3)
/* 8017816C 001750CC  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 80178170 001750D0  48 00 04 5D */	bl initAI__5PomAiFP3Pom
/* 80178174 001750D4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80178178 001750D8  38 21 00 08 */	addi r1, r1, 8
/* 8017817C 001750DC  7C 08 03 A6 */	mtlr r0
/* 80178180 001750E0  4E 80 00 20 */	blr 

.global setColor__3PomFi
setColor__3PomFi:
/* 80178184 001750E4  7C 08 02 A6 */	mflr r0
/* 80178188 001750E8  90 01 00 04 */	stw r0, 4(r1)
/* 8017818C 001750EC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80178190 001750F0  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80178194 001750F4  7C 7F 1B 78 */	mr r31, r3
/* 80178198 001750F8  90 83 03 BC */	stw r4, 0x3bc(r3)
/* 8017819C 001750FC  80 03 03 BC */	lwz r0, 0x3bc(r3)
/* 801781A0 00175100  2C 00 00 00 */	cmpwi r0, 0
/* 801781A4 00175104  41 80 00 0C */	blt lbl_801781B0
/* 801781A8 00175108  2C 00 00 02 */	cmpwi r0, 2
/* 801781AC 0017510C  40 81 00 4C */	ble lbl_801781F8
lbl_801781B0:
/* 801781B0 00175110  48 09 FE C1 */	bl rand
/* 801781B4 00175114  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 801781B8 00175118  C8 82 AD E0 */	lfd f4, lbl_803EAFE0@sda21(r2)
/* 801781BC 0017511C  90 01 00 24 */	stw r0, 0x24(r1)
/* 801781C0 00175120  3C 00 43 30 */	lis r0, 0x4330
/* 801781C4 00175124  C0 42 AD D8 */	lfs f2, lbl_803EAFD8@sda21(r2)
/* 801781C8 00175128  90 01 00 20 */	stw r0, 0x20(r1)
/* 801781CC 0017512C  C0 22 AD C4 */	lfs f1, lbl_803EAFC4@sda21(r2)
/* 801781D0 00175130  C8 61 00 20 */	lfd f3, 0x20(r1)
/* 801781D4 00175134  C0 02 AD DC */	lfs f0, lbl_803EAFDC@sda21(r2)
/* 801781D8 00175138  EC 63 20 28 */	fsubs f3, f3, f4
/* 801781DC 0017513C  EC 43 10 24 */	fdivs f2, f3, f2
/* 801781E0 00175140  EC 21 00 B2 */	fmuls f1, f1, f2
/* 801781E4 00175144  EC 00 00 72 */	fmuls f0, f0, f1
/* 801781E8 00175148  FC 00 00 1E */	fctiwz f0, f0
/* 801781EC 0017514C  D8 01 00 18 */	stfd f0, 0x18(r1)
/* 801781F0 00175150  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801781F4 00175154  90 1F 03 BC */	stw r0, 0x3bc(r31)
lbl_801781F8:
/* 801781F8 00175158  80 7F 03 90 */	lwz r3, 0x390(r31)
/* 801781FC 0017515C  38 9F 03 C4 */	addi r4, r31, 0x3c4
/* 80178200 00175160  38 A0 00 00 */	li r5, 0
/* 80178204 00175164  80 63 00 00 */	lwz r3, 0(r3)
/* 80178208 00175168  4B EB 77 25 */	bl makeInstance__9BaseShapeFR17ShapeDynMaterialsi
/* 8017820C 0017516C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80178210 00175170  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80178214 00175174  38 21 00 30 */	addi r1, r1, 0x30
/* 80178218 00175178  7C 08 03 A6 */	mtlr r0
/* 8017821C 0017517C  4E 80 00 20 */	blr 

.global doKill__3PomFv
doKill__3PomFv:
/* 80178220 00175180  7C 08 02 A6 */	mflr r0
/* 80178224 00175184  38 80 00 00 */	li r4, 0
/* 80178228 00175188  90 01 00 04 */	stw r0, 4(r1)
/* 8017822C 0017518C  38 00 00 00 */	li r0, 0
/* 80178230 00175190  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80178234 00175194  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80178238 00175198  3B E3 00 00 */	addi r31, r3, 0
/* 8017823C 0017519C  98 03 02 B8 */	stb r0, 0x2b8(r3)
/* 80178240 001751A0  98 03 02 B9 */	stb r0, 0x2b9(r3)
/* 80178244 001751A4  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 80178248 001751A8  48 00 07 15 */	bl killCallBackEffect__5PomAiFb
/* 8017824C 001751AC  80 6D 31 68 */	lwz r3, bossMgr@sda21(r13)
/* 80178250 001751B0  7F E4 FB 78 */	mr r4, r31
/* 80178254 001751B4  4B FD 9F 45 */	bl kill__7BossMgrFP8Creature
/* 80178258 001751B8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017825C 001751BC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80178260 001751C0  38 21 00 18 */	addi r1, r1, 0x18
/* 80178264 001751C4  7C 08 03 A6 */	mtlr r0
/* 80178268 001751C8  4E 80 00 20 */	blr 

.global exitCourse__3PomFv
exitCourse__3PomFv:
/* 8017826C 001751CC  7C 08 02 A6 */	mflr r0
/* 80178270 001751D0  38 80 00 01 */	li r4, 1
/* 80178274 001751D4  90 01 00 04 */	stw r0, 4(r1)
/* 80178278 001751D8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017827C 001751DC  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 80178280 001751E0  48 00 06 DD */	bl killCallBackEffect__5PomAiFb
/* 80178284 001751E4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80178288 001751E8  38 21 00 08 */	addi r1, r1, 8
/* 8017828C 001751EC  7C 08 03 A6 */	mtlr r0
/* 80178290 001751F0  4E 80 00 20 */	blr 

.global update__3PomFv
update__3PomFv:
/* 80178294 001751F4  7C 08 02 A6 */	mflr r0
/* 80178298 001751F8  90 01 00 04 */	stw r0, 4(r1)
/* 8017829C 001751FC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801782A0 00175200  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801782A4 00175204  7C 7F 1B 78 */	mr r31, r3
/* 801782A8 00175208  81 9F 00 00 */	lwz r12, 0(r31)
/* 801782AC 0017520C  81 8C 01 04 */	lwz r12, 0x104(r12)
/* 801782B0 00175210  7D 88 03 A6 */	mtlr r12
/* 801782B4 00175214  4E 80 00 21 */	blrl 
/* 801782B8 00175218  7F E3 FB 78 */	mr r3, r31
/* 801782BC 0017521C  81 9F 00 00 */	lwz r12, 0(r31)
/* 801782C0 00175220  81 8C 01 08 */	lwz r12, 0x108(r12)
/* 801782C4 00175224  7D 88 03 A6 */	mtlr r12
/* 801782C8 00175228  4E 80 00 21 */	blrl 
/* 801782CC 0017522C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801782D0 00175230  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801782D4 00175234  38 21 00 18 */	addi r1, r1, 0x18
/* 801782D8 00175238  7C 08 03 A6 */	mtlr r0
/* 801782DC 0017523C  4E 80 00 20 */	blr 

.global refresh__3PomFR8Graphics
refresh__3PomFR8Graphics:
/* 801782E0 00175240  7C 08 02 A6 */	mflr r0
/* 801782E4 00175244  90 01 00 04 */	stw r0, 4(r1)
/* 801782E8 00175248  94 21 FF 98 */	stwu r1, -0x68(r1)
/* 801782EC 0017524C  93 E1 00 64 */	stw r31, 0x64(r1)
/* 801782F0 00175250  7C 9F 23 78 */	mr r31, r4
/* 801782F4 00175254  93 C1 00 60 */	stw r30, 0x60(r1)
/* 801782F8 00175258  7C 7E 1B 78 */	mr r30, r3
/* 801782FC 0017525C  81 9E 00 00 */	lwz r12, 0(r30)
/* 80178300 00175260  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 80178304 00175264  7D 88 03 A6 */	mtlr r12
/* 80178308 00175268  4E 80 00 21 */	blrl 
/* 8017830C 0017526C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80178310 00175270  41 82 00 98 */	beq lbl_801783A8
/* 80178314 00175274  38 7E 02 28 */	addi r3, r30, 0x228
/* 80178318 00175278  38 9E 00 7C */	addi r4, r30, 0x7c
/* 8017831C 0017527C  38 BE 00 88 */	addi r5, r30, 0x88
/* 80178320 00175280  38 DE 00 94 */	addi r6, r30, 0x94
/* 80178324 00175284  4B EC 5D D1 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 80178328 00175288  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 8017832C 0017528C  38 9E 02 28 */	addi r4, r30, 0x228
/* 80178330 00175290  38 A1 00 14 */	addi r5, r1, 0x14
/* 80178334 00175294  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 80178338 00175298  4B EC 5D 9D */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 8017833C 0017529C  38 7E 03 3C */	addi r3, r30, 0x33c
/* 80178340 001752A0  81 9E 03 6C */	lwz r12, 0x36c(r30)
/* 80178344 001752A4  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80178348 001752A8  7D 88 03 A6 */	mtlr r12
/* 8017834C 001752AC  4E 80 00 21 */	blrl 
/* 80178350 001752B0  80 9E 03 BC */	lwz r4, 0x3bc(r30)
/* 80178354 001752B4  3C 00 43 30 */	lis r0, 0x4330
/* 80178358 001752B8  C8 22 AD E0 */	lfd f1, lbl_803EAFE0@sda21(r2)
/* 8017835C 001752BC  38 7E 03 C4 */	addi r3, r30, 0x3c4
/* 80178360 001752C0  6C 84 80 00 */	xoris r4, r4, 0x8000
/* 80178364 001752C4  90 81 00 5C */	stw r4, 0x5c(r1)
/* 80178368 001752C8  38 81 00 10 */	addi r4, r1, 0x10
/* 8017836C 001752CC  90 01 00 58 */	stw r0, 0x58(r1)
/* 80178370 001752D0  C8 01 00 58 */	lfd f0, 0x58(r1)
/* 80178374 001752D4  EC 00 08 28 */	fsubs f0, f0, f1
/* 80178378 001752D8  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8017837C 001752DC  4B EB 6D 21 */	bl animate__17ShapeDynMaterialsFPf
/* 80178380 001752E0  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 80178384 001752E4  38 9F 00 00 */	addi r4, r31, 0
/* 80178388 001752E8  38 A1 00 14 */	addi r5, r1, 0x14
/* 8017838C 001752EC  80 63 00 00 */	lwz r3, 0(r3)
/* 80178390 001752F0  38 C0 00 00 */	li r6, 0
/* 80178394 001752F4  4B EB CF 81 */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 80178398 001752F8  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 8017839C 001752FC  38 9F 00 00 */	addi r4, r31, 0
/* 801783A0 00175300  38 A0 00 00 */	li r5, 0
/* 801783A4 00175304  4B F1 17 49 */	bl updateInfo__8CollInfoFR8Graphicsb
lbl_801783A8:
/* 801783A8 00175308  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 801783AC 0017530C  83 E1 00 64 */	lwz r31, 0x64(r1)
/* 801783B0 00175310  83 C1 00 60 */	lwz r30, 0x60(r1)
/* 801783B4 00175314  38 21 00 68 */	addi r1, r1, 0x68
/* 801783B8 00175318  7C 08 03 A6 */	mtlr r0
/* 801783BC 0017531C  4E 80 00 20 */	blr 

.global drawShape__3PomFR8Graphics
drawShape__3PomFR8Graphics:
/* 801783C0 00175320  7C 08 02 A6 */	mflr r0
/* 801783C4 00175324  90 01 00 04 */	stw r0, 4(r1)
/* 801783C8 00175328  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801783CC 0017532C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801783D0 00175330  7C 9F 23 78 */	mr r31, r4
/* 801783D4 00175334  93 C1 00 10 */	stw r30, 0x10(r1)
/* 801783D8 00175338  7C 7E 1B 78 */	mr r30, r3
/* 801783DC 0017533C  81 9E 00 00 */	lwz r12, 0(r30)
/* 801783E0 00175340  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 801783E4 00175344  7D 88 03 A6 */	mtlr r12
/* 801783E8 00175348  4E 80 00 21 */	blrl 
/* 801783EC 0017534C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801783F0 00175350  41 82 00 3C */	beq lbl_8017842C
/* 801783F4 00175354  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 801783F8 00175358  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 801783FC 0017535C  7F E3 FB 78 */	mr r3, r31
/* 80178400 00175360  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 80178404 00175364  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 80178408 00175368  38 A0 00 00 */	li r5, 0
/* 8017840C 0017536C  7D 88 03 A6 */	mtlr r12
/* 80178410 00175370  4E 80 00 21 */	blrl 
/* 80178414 00175374  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 80178418 00175378  7F E4 FB 78 */	mr r4, r31
/* 8017841C 0017537C  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 80178420 00175380  38 DE 03 C4 */	addi r6, r30, 0x3c4
/* 80178424 00175384  80 63 00 00 */	lwz r3, 0(r3)
/* 80178428 00175388  4B EB 80 45 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
lbl_8017842C:
/* 8017842C 0017538C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80178430 00175390  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80178434 00175394  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80178438 00175398  38 21 00 18 */	addi r1, r1, 0x18
/* 8017843C 0017539C  7C 08 03 A6 */	mtlr r0
/* 80178440 001753A0  4E 80 00 20 */	blr 

.global doAI__3PomFv
doAI__3PomFv:
/* 80178444 001753A4  7C 08 02 A6 */	mflr r0
/* 80178448 001753A8  90 01 00 04 */	stw r0, 4(r1)
/* 8017844C 001753AC  94 21 FF F8 */	stwu r1, -8(r1)
/* 80178450 001753B0  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 80178454 001753B4  48 00 10 F9 */	bl update__5PomAiFv
/* 80178458 001753B8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017845C 001753BC  38 21 00 08 */	addi r1, r1, 8
/* 80178460 001753C0  7C 08 03 A6 */	mtlr r0
/* 80178464 001753C4  4E 80 00 20 */	blr 

.global doAnimation__3PomFv
doAnimation__3PomFv:
/* 80178468 001753C8  7C 08 02 A6 */	mflr r0
/* 8017846C 001753CC  7C 64 1B 78 */	mr r4, r3
/* 80178470 001753D0  90 01 00 04 */	stw r0, 4(r1)
/* 80178474 001753D4  94 21 FF F8 */	stwu r1, -8(r1)
/* 80178478 001753D8  80 03 03 90 */	lwz r0, 0x390(r3)
/* 8017847C 001753DC  28 00 00 00 */	cmplwi r0, 0
/* 80178480 001753E0  41 82 00 1C */	beq lbl_8017849C
/* 80178484 001753E4  81 84 03 6C */	lwz r12, 0x36c(r4)
/* 80178488 001753E8  38 64 03 3C */	addi r3, r4, 0x33c
/* 8017848C 001753EC  C0 24 02 D8 */	lfs f1, 0x2d8(r4)
/* 80178490 001753F0  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80178494 001753F4  7D 88 03 A6 */	mtlr r12
/* 80178498 001753F8  4E 80 00 21 */	blrl 
lbl_8017849C:
/* 8017849C 001753FC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801784A0 00175400  38 21 00 08 */	addi r1, r1, 8
/* 801784A4 00175404  7C 08 03 A6 */	mtlr r0
/* 801784A8 00175408  4E 80 00 20 */	blr 

.global collisionCallback__3PomFR9CollEvent
collisionCallback__3PomFR9CollEvent:
/* 801784AC 0017540C  7C 08 02 A6 */	mflr r0
/* 801784B0 00175410  90 01 00 04 */	stw r0, 4(r1)
/* 801784B4 00175414  94 21 FF F8 */	stwu r1, -8(r1)
/* 801784B8 00175418  80 A4 00 00 */	lwz r5, 0(r4)
/* 801784BC 0017541C  80 05 00 6C */	lwz r0, 0x6c(r5)
/* 801784C0 00175420  2C 00 00 00 */	cmpwi r0, 0
/* 801784C4 00175424  41 82 00 0C */	beq lbl_801784D0
/* 801784C8 00175428  2C 00 00 36 */	cmpwi r0, 0x36
/* 801784CC 0017542C  40 82 00 24 */	bne lbl_801784F0
lbl_801784D0:
/* 801784D0 00175430  88 03 03 B8 */	lbz r0, 0x3b8(r3)
/* 801784D4 00175434  28 00 00 00 */	cmplwi r0, 0
/* 801784D8 00175438  40 82 00 0C */	bne lbl_801784E4
/* 801784DC 0017543C  38 00 00 01 */	li r0, 1
/* 801784E0 00175440  98 03 03 B8 */	stb r0, 0x3b8(r3)
lbl_801784E4:
/* 801784E4 00175444  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 801784E8 00175448  80 84 00 00 */	lwz r4, 0(r4)
/* 801784EC 0017544C  48 00 04 A9 */	bl collidePetal__5PomAiFP8Creature
lbl_801784F0:
/* 801784F0 00175450  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801784F4 00175454  38 21 00 08 */	addi r1, r1, 8
/* 801784F8 00175458  7C 08 03 A6 */	mtlr r0
/* 801784FC 0017545C  4E 80 00 20 */	blr 

.global read__7PomPropFR18RandomAccessStream
read__7PomPropFR18RandomAccessStream:
/* 80178500 00175460  7C 08 02 A6 */	mflr r0
/* 80178504 00175464  90 01 00 04 */	stw r0, 4(r1)
/* 80178508 00175468  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017850C 0017546C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80178510 00175470  3B E4 00 00 */	addi r31, r4, 0
/* 80178514 00175474  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80178518 00175478  3B C3 00 00 */	addi r30, r3, 0
/* 8017851C 0017547C  4B EE 66 7D */	bl read__10ParametersFR18RandomAccessStream
/* 80178520 00175480  38 7E 00 58 */	addi r3, r30, 0x58
/* 80178524 00175484  38 9F 00 00 */	addi r4, r31, 0
/* 80178528 00175488  4B EE 66 71 */	bl read__10ParametersFR18RandomAccessStream
/* 8017852C 0017548C  38 7E 02 00 */	addi r3, r30, 0x200
/* 80178530 00175490  38 9F 00 00 */	addi r4, r31, 0
/* 80178534 00175494  4B EE 66 65 */	bl read__10ParametersFR18RandomAccessStream
/* 80178538 00175498  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017853C 0017549C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80178540 001754A0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80178544 001754A4  38 21 00 18 */	addi r1, r1, 0x18
/* 80178548 001754A8  7C 08 03 A6 */	mtlr r0
/* 8017854C 001754AC  4E 80 00 20 */	blr 

"@492@read__7PomPropFR18RandomAccessStream":
/* 80178550 001754B0  38 63 FE 14 */	addi r3, r3, -492
/* 80178554 001754B4  4B FF FF AC */	b read__7PomPropFR18RandomAccessStream

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802D0A78:
	.asciz "CoreNode"
.balign 4
lbl_802D0A84:
	.asciz "EventTalker"
.balign 4
lbl_802D0A90:
	.asciz "RefCountable"
.balign 4
lbl_802D0AA0:
	.asciz "Creature"
.balign 4
lbl_802D0AAC:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D0AC0:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D0ADC:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte __RTTI__4Boss
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__3Pom
__vt__3Pom:
	.4byte __RTTI__3Pom
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__3PomFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__3PomFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__4BossFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__4BossFv
	.4byte isVisible__4BossFv
	.4byte isOrganic__4BossFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__4BossFv
	.4byte isAlive__4BossFv
	.4byte isFixed__4BossFv
	.4byte needShadow__4BossFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__4BossFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__4BossFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__3PomFR9CollEvent
	.4byte bounceCallback__8CreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__4BossFR5PlaneP13DynCollObject
	.4byte offwallCallback__8CreatureFP13DynCollObject
	.4byte stickCallback__8CreatureFP8Creature
	.4byte offstickCallback__8CreatureFP8Creature
	.4byte stickToCallback__8CreatureFP8Creature
	.4byte dump__8CreatureFv
	.4byte startWaterEffect__8CreatureFv
	.4byte finishWaterEffect__8CreatureFv
	.4byte isRopable__8CreatureFv
	.4byte mayIstick__8CreatureFv
	.4byte getFormationPri__8CreatureFv
	.4byte update__3PomFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__3PomFR8Graphics
	.4byte refresh2d__4BossFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__3PomFv
	.4byte doAnimation__3PomFv
	.4byte doKill__3PomFv
	.4byte exitCourse__3PomFv
	.4byte isBossBgm__4BossFv
	.4byte attackDefaultPortion__4BossFv
	.4byte bombDamageCounter__4BossFP8CollPart
	.4byte drawShape__3PomFR8Graphics
.balign 4
lbl_802D0C24:
	.asciz "Parm<int>"
.balign 4
lbl_802D0C30:
	.asciz "BaseParm"
.balign 4
lbl_802D0C3C:
	.4byte __RTTI__8BaseParm
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
lbl_802D0C5C:
	.asciz "Parm<float>"
.balign 4
lbl_802D0C68:
	.4byte __RTTI__8BaseParm
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
lbl_802D0C88:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.balign 4
lbl_802D0C94:
	.asciz "CreatureProp"
.balign 4
lbl_802D0CA4:
	.asciz "BossProp"
.balign 4
lbl_802D0CB0:
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte 0
lbl_802D0CBC:
	.4byte __RTTI__5ANode
	.4byte 0x1ec
	.4byte __RTTI__8CoreNode
	.4byte 0x1ec
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte __RTTI__8BossProp
	.4byte 0
	.4byte 0
.global __vt__7PomProp
__vt__7PomProp:
	.4byte __RTTI__7PomProp
	.4byte 0
	.4byte read__7PomPropFR18RandomAccessStream
	.4byte __RTTI__7PomProp
	.4byte 0xfffffe14
	.4byte getAgeNodeType__5ANodeFv
	.4byte "@492@read__7PomPropFR18RandomAccessStream"
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E52C8:
	.asciz "Pom"
.balign 4
lbl_803E52CC:
	.asciz "s00"
.balign 4
lbl_803E52D0:
	.asciz "s01"
.balign 4
lbl_803E52D4:
	.asciz "s02"
.balign 4
lbl_803E52D8:
	.asciz "p00"
.balign 4
lbl_803E52DC:
	.asciz "p10"
.balign 4
lbl_803E52E0:
	.asciz "i00"
.balign 4
lbl_803E52E4:
	.asciz "i10"
.balign 4
lbl_803E52E8:
	.asciz "i11"
.balign 4
lbl_803E52EC:
	.asciz "i20"
.balign 4
lbl_803E52F0:
	.asciz "i90"
.balign 4
lbl_803E52F4:
	.asciz "i91"
.balign 4
lbl_803E52F8:
	.asciz "i92"
.balign 4
__RTTI__11EventTalker:
	.4byte lbl_802D0A84
	.4byte 0x00000000
__RTTI__12RefCountable:
	.4byte lbl_802D0A90
	.4byte 0x00000000
__RTTI__8Creature:
	.4byte lbl_802D0AA0
	.4byte lbl_802D0AAC
.balign 4
lbl_803E5314:
	.asciz "Boss"
.balign 4
__RTTI__4Boss:
	.4byte lbl_803E5314
	.4byte lbl_802D0AC0
__RTTI__3Pom:
	.4byte lbl_803E52C8
	.4byte lbl_802D0ADC
__RTTI__8BaseParm:
	.4byte lbl_802D0C30
	.4byte 0
.balign 4
lbl_803E5334:
	.asciz "PomProp"
.balign 4
lbl_803E533C:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E533C
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802D0A78
	.4byte lbl_802D0C88
__RTTI__12CreatureProp:
	.4byte lbl_802D0C94
	.4byte 0
__RTTI__8BossProp:
	.4byte lbl_802D0CA4
	.4byte lbl_802D0CB0
__RTTI__7PomProp:
	.4byte lbl_803E5334
	.4byte lbl_802D0CBC

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EAFB0:
	.4byte 0x3E4CCCCD
lbl_803EAFB4:
	.float 0.5
lbl_803EAFB8:
	.4byte 0x3E19999A
lbl_803EAFBC:
	.4byte 0x41200000
lbl_803EAFC0:
	.4byte 0x43340000
lbl_803EAFC4:
	.float 1.0
lbl_803EAFC8:
	.float 0.0
lbl_803EAFCC:
	.float 0.0001
lbl_803EAFD0:
	.float 20.0
lbl_803EAFD4:
	.4byte 0x42480000
lbl_803EAFD8:
	.4byte 0x46FFFE00
lbl_803EAFDC:
	.4byte 0x403FFFF3
lbl_803EAFE0:
	.4byte 0x43300000
	.4byte 0x80000000
