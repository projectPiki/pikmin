.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__8KusaItemFP12CreaturePropP5Shape
__ct__8KusaItemFP12CreaturePropP5Shape:
/* 800E5DD8 000E2D38  7C 08 02 A6 */	mflr r0
/* 800E5DDC 000E2D3C  38 C5 00 00 */	addi r6, r5, 0
/* 800E5DE0 000E2D40  90 01 00 04 */	stw r0, 4(r1)
/* 800E5DE4 000E2D44  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800E5DE8 000E2D48  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800E5DEC 000E2D4C  3B E4 00 00 */	addi r31, r4, 0
/* 800E5DF0 000E2D50  38 80 00 1D */	li r4, 0x1d
/* 800E5DF4 000E2D54  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800E5DF8 000E2D58  3B C3 00 00 */	addi r30, r3, 0
/* 800E5DFC 000E2D5C  80 A3 02 24 */	lwz r5, 0x224(r3)
/* 800E5E00 000E2D60  48 00 FA AD */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800E5E04 000E2D64  3C 60 80 2C */	lis r3, __vt__8KusaItem@ha
/* 800E5E08 000E2D68  38 63 BC 10 */	addi r3, r3, __vt__8KusaItem@l
/* 800E5E0C 000E2D6C  90 7E 00 00 */	stw r3, 0(r30)
/* 800E5E10 000E2D70  38 03 01 14 */	addi r0, r3, 0x114
/* 800E5E14 000E2D74  38 7E 03 C8 */	addi r3, r30, 0x3c8
/* 800E5E18 000E2D78  90 1E 02 B8 */	stw r0, 0x2b8(r30)
/* 800E5E1C 000E2D7C  38 80 00 00 */	li r4, 0
/* 800E5E20 000E2D80  4B FA 2E 11 */	bl __ct__8CollInfoFi
/* 800E5E24 000E2D84  3C 60 80 08 */	lis r3, __ct__8CollPartFv@ha
/* 800E5E28 000E2D88  38 83 7E 48 */	addi r4, r3, __ct__8CollPartFv@l
/* 800E5E2C 000E2D8C  38 7E 03 DC */	addi r3, r30, 0x3dc
/* 800E5E30 000E2D90  38 A0 00 00 */	li r5, 0
/* 800E5E34 000E2D94  38 C0 00 68 */	li r6, 0x68
/* 800E5E38 000E2D98  38 E0 00 0A */	li r7, 0xa
/* 800E5E3C 000E2D9C  48 12 EC 35 */	bl __construct_array
/* 800E5E40 000E2DA0  C0 02 99 78 */	lfs f0, lbl_803E9B78@sda21(r2)
/* 800E5E44 000E2DA4  7F C3 F3 78 */	mr r3, r30
/* 800E5E48 000E2DA8  D0 1E 08 1C */	stfs f0, 0x81c(r30)
/* 800E5E4C 000E2DAC  D0 1E 08 18 */	stfs f0, 0x818(r30)
/* 800E5E50 000E2DB0  D0 1E 08 14 */	stfs f0, 0x814(r30)
/* 800E5E54 000E2DB4  93 FE 02 24 */	stw r31, 0x224(r30)
/* 800E5E58 000E2DB8  80 1E 00 C8 */	lwz r0, 0xc8(r30)
/* 800E5E5C 000E2DBC  60 00 02 00 */	ori r0, r0, 0x200
/* 800E5E60 000E2DC0  90 1E 00 C8 */	stw r0, 0xc8(r30)
/* 800E5E64 000E2DC4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800E5E68 000E2DC8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800E5E6C 000E2DCC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800E5E70 000E2DD0  38 21 00 20 */	addi r1, r1, 0x20
/* 800E5E74 000E2DD4  7C 08 03 A6 */	mtlr r0
/* 800E5E78 000E2DD8  4E 80 00 20 */	blr 

.global startAI__8KusaItemFi
startAI__8KusaItemFi:
/* 800E5E7C 000E2DDC  7C 08 02 A6 */	mflr r0
/* 800E5E80 000E2DE0  90 01 00 04 */	stw r0, 4(r1)
/* 800E5E84 000E2DE4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800E5E88 000E2DE8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800E5E8C 000E2DEC  7C 7F 1B 78 */	mr r31, r3
/* 800E5E90 000E2DF0  38 1F 03 C8 */	addi r0, r31, 0x3c8
/* 800E5E94 000E2DF4  80 63 00 C8 */	lwz r3, 0xc8(r3)
/* 800E5E98 000E2DF8  38 BF 03 DC */	addi r5, r31, 0x3dc
/* 800E5E9C 000E2DFC  38 DF 07 EC */	addi r6, r31, 0x7ec
/* 800E5EA0 000E2E00  60 63 02 00 */	ori r3, r3, 0x200
/* 800E5EA4 000E2E04  90 7F 00 C8 */	stw r3, 0xc8(r31)
/* 800E5EA8 000E2E08  90 1F 02 20 */	stw r0, 0x220(r31)
/* 800E5EAC 000E2E0C  80 7F 02 20 */	lwz r3, 0x220(r31)
/* 800E5EB0 000E2E10  80 9F 03 08 */	lwz r4, 0x308(r31)
/* 800E5EB4 000E2E14  4B FA 3C B1 */	bl initInfo__8CollInfoFP5ShapeP8CollPartPUl
/* 800E5EB8 000E2E18  3C 80 72 6F */	lis r4, 0x726F7065@ha
/* 800E5EBC 000E2E1C  80 7F 02 20 */	lwz r3, 0x220(r31)
/* 800E5EC0 000E2E20  38 84 70 65 */	addi r4, r4, 0x726F7065@l
/* 800E5EC4 000E2E24  38 A0 00 01 */	li r5, 1
/* 800E5EC8 000E2E28  4B FA 3D 41 */	bl makeTubesChild__8CollInfoFUli
/* 800E5ECC 000E2E2C  C0 0D C8 48 */	lfs f0, lbl_803E1568@sda21(r13)
/* 800E5ED0 000E2E30  38 80 00 01 */	li r4, 1
/* 800E5ED4 000E2E34  D0 1F 00 7C */	stfs f0, 0x7c(r31)
/* 800E5ED8 000E2E38  C0 0D C8 4C */	lfs f0, lbl_803E156C@sda21(r13)
/* 800E5EDC 000E2E3C  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 800E5EE0 000E2E40  C0 0D C8 50 */	lfs f0, lbl_803E1570@sda21(r13)
/* 800E5EE4 000E2E44  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 800E5EE8 000E2E48  80 7F 00 94 */	lwz r3, 0x94(r31)
/* 800E5EEC 000E2E4C  80 1F 00 98 */	lwz r0, 0x98(r31)
/* 800E5EF0 000E2E50  90 7F 08 14 */	stw r3, 0x814(r31)
/* 800E5EF4 000E2E54  90 1F 08 18 */	stw r0, 0x818(r31)
/* 800E5EF8 000E2E58  80 1F 00 9C */	lwz r0, 0x9c(r31)
/* 800E5EFC 000E2E5C  90 1F 08 1C */	stw r0, 0x81c(r31)
/* 800E5F00 000E2E60  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 800E5F04 000E2E64  C0 3F 00 94 */	lfs f1, 0x94(r31)
/* 800E5F08 000E2E68  C0 5F 00 9C */	lfs f2, 0x9c(r31)
/* 800E5F0C 000E2E6C  4B F8 1F F9 */	bl getMinY__6MapMgrFffb
/* 800E5F10 000E2E70  D0 3F 08 18 */	stfs f1, 0x818(r31)
/* 800E5F14 000E2E74  38 80 00 23 */	li r4, 0x23
/* 800E5F18 000E2E78  C0 02 99 7C */	lfs f0, lbl_803E9B7C@sda21(r2)
/* 800E5F1C 000E2E7C  D0 1F 00 58 */	stfs f0, 0x58(r31)
/* 800E5F20 000E2E80  C0 02 99 80 */	lfs f0, lbl_803E9B80@sda21(r2)
/* 800E5F24 000E2E84  D0 1F 00 5C */	stfs f0, 0x5c(r31)
/* 800E5F28 000E2E88  80 6D 30 AC */	lwz r3, itemMgr@sda21(r13)
/* 800E5F2C 000E2E8C  81 83 00 00 */	lwz r12, 0(r3)
/* 800E5F30 000E2E90  81 8C 00 78 */	lwz r12, 0x78(r12)
/* 800E5F34 000E2E94  7D 88 03 A6 */	mtlr r12
/* 800E5F38 000E2E98  4E 80 00 21 */	blrl 
/* 800E5F3C 000E2E9C  90 7F 08 20 */	stw r3, 0x820(r31)
/* 800E5F40 000E2EA0  80 7F 08 20 */	lwz r3, 0x820(r31)
/* 800E5F44 000E2EA4  28 03 00 00 */	cmplwi r3, 0
/* 800E5F48 000E2EA8  41 82 00 38 */	beq .L_800E5F80
/* 800E5F4C 000E2EAC  81 83 00 00 */	lwz r12, 0(r3)
/* 800E5F50 000E2EB0  38 9F 08 14 */	addi r4, r31, 0x814
/* 800E5F54 000E2EB4  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 800E5F58 000E2EB8  7D 88 03 A6 */	mtlr r12
/* 800E5F5C 000E2EBC  4E 80 00 21 */	blrl 
/* 800E5F60 000E2EC0  80 7F 08 20 */	lwz r3, 0x820(r31)
/* 800E5F64 000E2EC4  38 80 00 00 */	li r4, 0
/* 800E5F68 000E2EC8  93 E3 08 20 */	stw r31, 0x820(r3)
/* 800E5F6C 000E2ECC  80 7F 08 20 */	lwz r3, 0x820(r31)
/* 800E5F70 000E2ED0  81 83 00 00 */	lwz r12, 0(r3)
/* 800E5F74 000E2ED4  81 8C 00 34 */	lwz r12, 0x34(r12)
/* 800E5F78 000E2ED8  7D 88 03 A6 */	mtlr r12
/* 800E5F7C 000E2EDC  4E 80 00 21 */	blrl 
.L_800E5F80:
/* 800E5F80 000E2EE0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800E5F84 000E2EE4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800E5F88 000E2EE8  38 21 00 18 */	addi r1, r1, 0x18
/* 800E5F8C 000E2EEC  7C 08 03 A6 */	mtlr r0
/* 800E5F90 000E2EF0  4E 80 00 20 */	blr 

.global doLoad__8KusaItemFR18RandomAccessStream
doLoad__8KusaItemFR18RandomAccessStream:
/* 800E5F94 000E2EF4  7C 08 02 A6 */	mflr r0
/* 800E5F98 000E2EF8  90 01 00 04 */	stw r0, 4(r1)
/* 800E5F9C 000E2EFC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800E5FA0 000E2F00  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800E5FA4 000E2F04  3B E3 00 00 */	addi r31, r3, 0
/* 800E5FA8 000E2F08  38 64 00 00 */	addi r3, r4, 0
/* 800E5FAC 000E2F0C  81 84 00 04 */	lwz r12, 4(r4)
/* 800E5FB0 000E2F10  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800E5FB4 000E2F14  7D 88 03 A6 */	mtlr r12
/* 800E5FB8 000E2F18  4E 80 00 21 */	blrl 
/* 800E5FBC 000E2F1C  D0 3F 00 58 */	stfs f1, 0x58(r31)
/* 800E5FC0 000E2F20  C0 3F 00 58 */	lfs f1, 0x58(r31)
/* 800E5FC4 000E2F24  C0 1F 00 5C */	lfs f0, 0x5c(r31)
/* 800E5FC8 000E2F28  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800E5FCC 000E2F2C  4C 41 13 82 */	cror 2, 1, 2
/* 800E5FD0 000E2F30  40 82 00 10 */	bne .L_800E5FE0
/* 800E5FD4 000E2F34  80 7F 08 20 */	lwz r3, 0x820(r31)
/* 800E5FD8 000E2F38  38 00 00 00 */	li r0, 0
/* 800E5FDC 000E2F3C  98 03 08 24 */	stb r0, 0x824(r3)
.L_800E5FE0:
/* 800E5FE0 000E2F40  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800E5FE4 000E2F44  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800E5FE8 000E2F48  38 21 00 18 */	addi r1, r1, 0x18
/* 800E5FEC 000E2F4C  7C 08 03 A6 */	mtlr r0
/* 800E5FF0 000E2F50  4E 80 00 20 */	blr 

.global doSave__8KusaItemFR18RandomAccessStream
doSave__8KusaItemFR18RandomAccessStream:
/* 800E5FF4 000E2F54  7C 08 02 A6 */	mflr r0
/* 800E5FF8 000E2F58  38 A3 00 00 */	addi r5, r3, 0
/* 800E5FFC 000E2F5C  90 01 00 04 */	stw r0, 4(r1)
/* 800E6000 000E2F60  38 64 00 00 */	addi r3, r4, 0
/* 800E6004 000E2F64  94 21 FF F8 */	stwu r1, -8(r1)
/* 800E6008 000E2F68  81 84 00 04 */	lwz r12, 4(r4)
/* 800E600C 000E2F6C  C0 25 00 58 */	lfs f1, 0x58(r5)
/* 800E6010 000E2F70  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 800E6014 000E2F74  7D 88 03 A6 */	mtlr r12
/* 800E6018 000E2F78  4E 80 00 21 */	blrl 
/* 800E601C 000E2F7C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800E6020 000E2F80  38 21 00 08 */	addi r1, r1, 8
/* 800E6024 000E2F84  7C 08 03 A6 */	mtlr r0
/* 800E6028 000E2F88  4E 80 00 20 */	blr 

.global ignoreAtari__8KusaItemFP8Creature
ignoreAtari__8KusaItemFP8Creature:
/* 800E602C 000E2F8C  80 04 01 84 */	lwz r0, 0x184(r4)
/* 800E6030 000E2F90  7C 00 18 40 */	cmplw r0, r3
/* 800E6034 000E2F94  40 82 00 0C */	bne .L_800E6040
/* 800E6038 000E2F98  38 60 00 01 */	li r3, 1
/* 800E603C 000E2F9C  4E 80 00 20 */	blr 
.L_800E6040:
/* 800E6040 000E2FA0  38 60 00 00 */	li r3, 0
/* 800E6044 000E2FA4  4E 80 00 20 */	blr 

.global getSize__8KusaItemFv
getSize__8KusaItemFv:
/* 800E6048 000E2FA8  C0 22 99 84 */	lfs f1, lbl_803E9B84@sda21(r2)
/* 800E604C 000E2FAC  4E 80 00 20 */	blr 

.global getiMass__8KusaItemFv
getiMass__8KusaItemFv:
/* 800E6050 000E2FB0  C0 22 99 78 */	lfs f1, lbl_803E9B78@sda21(r2)
/* 800E6054 000E2FB4  4E 80 00 20 */	blr 

.global update__8KusaItemFv
update__8KusaItemFv:
/* 800E6058 000E2FB8  7C 08 02 A6 */	mflr r0
/* 800E605C 000E2FBC  90 01 00 04 */	stw r0, 4(r1)
/* 800E6060 000E2FC0  94 21 FF F8 */	stwu r1, -8(r1)
/* 800E6064 000E2FC4  80 83 08 14 */	lwz r4, 0x814(r3)
/* 800E6068 000E2FC8  80 03 08 18 */	lwz r0, 0x818(r3)
/* 800E606C 000E2FCC  90 83 00 94 */	stw r4, 0x94(r3)
/* 800E6070 000E2FD0  90 03 00 98 */	stw r0, 0x98(r3)
/* 800E6074 000E2FD4  80 03 08 1C */	lwz r0, 0x81c(r3)
/* 800E6078 000E2FD8  90 03 00 9C */	stw r0, 0x9c(r3)
/* 800E607C 000E2FDC  48 00 FB 79 */	bl update__12ItemCreatureFv
/* 800E6080 000E2FE0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800E6084 000E2FE4  38 21 00 08 */	addi r1, r1, 8
/* 800E6088 000E2FE8  7C 08 03 A6 */	mtlr r0
/* 800E608C 000E2FEC  4E 80 00 20 */	blr 

.global refresh__8KusaItemFR8Graphics
refresh__8KusaItemFR8Graphics:
/* 800E6090 000E2FF0  7C 08 02 A6 */	mflr r0
/* 800E6094 000E2FF4  90 01 00 04 */	stw r0, 4(r1)
/* 800E6098 000E2FF8  94 21 FF 40 */	stwu r1, -0xc0(r1)
/* 800E609C 000E2FFC  93 E1 00 BC */	stw r31, 0xbc(r1)
/* 800E60A0 000E3000  38 01 00 28 */	addi r0, r1, 0x28
/* 800E60A4 000E3004  7C 9F 23 78 */	mr r31, r4
/* 800E60A8 000E3008  93 C1 00 B8 */	stw r30, 0xb8(r1)
/* 800E60AC 000E300C  7C 7E 1B 78 */	mr r30, r3
/* 800E60B0 000E3010  38 C1 00 10 */	addi r6, r1, 0x10
/* 800E60B4 000E3014  C0 83 00 58 */	lfs f4, 0x58(r3)
/* 800E60B8 000E3018  38 A1 00 1C */	addi r5, r1, 0x1c
/* 800E60BC 000E301C  C0 63 00 5C */	lfs f3, 0x5c(r3)
/* 800E60C0 000E3020  7C 04 03 78 */	mr r4, r0
/* 800E60C4 000E3024  C0 4D C8 6C */	lfs f2, lbl_803E158C@sda21(r13)
/* 800E60C8 000E3028  EC A4 18 28 */	fsubs f5, f4, f3
/* 800E60CC 000E302C  C0 2D C8 60 */	lfs f1, lbl_803E1580@sda21(r13)
/* 800E60D0 000E3030  D0 41 00 10 */	stfs f2, 0x10(r1)
/* 800E60D4 000E3034  38 61 00 34 */	addi r3, r1, 0x34
/* 800E60D8 000E3038  C0 0D C8 54 */	lfs f0, lbl_803E1574@sda21(r13)
/* 800E60DC 000E303C  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 800E60E0 000E3040  C0 6D C8 64 */	lfs f3, lbl_803E1584@sda21(r13)
/* 800E60E4 000E3044  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 800E60E8 000E3048  C0 2D C8 58 */	lfs f1, lbl_803E1578@sda21(r13)
/* 800E60EC 000E304C  C0 8D C8 70 */	lfs f4, lbl_803E1590@sda21(r13)
/* 800E60F0 000E3050  D0 A1 00 14 */	stfs f5, 0x14(r1)
/* 800E60F4 000E3054  C0 4D C8 68 */	lfs f2, lbl_803E1588@sda21(r13)
/* 800E60F8 000E3058  D0 61 00 20 */	stfs f3, 0x20(r1)
/* 800E60FC 000E305C  C0 0D C8 5C */	lfs f0, lbl_803E157C@sda21(r13)
/* 800E6100 000E3060  D0 21 00 2C */	stfs f1, 0x2c(r1)
/* 800E6104 000E3064  D0 81 00 18 */	stfs f4, 0x18(r1)
/* 800E6108 000E3068  D0 41 00 24 */	stfs f2, 0x24(r1)
/* 800E610C 000E306C  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 800E6110 000E3070  4B F5 7F E5 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 800E6114 000E3074  38 7E 02 28 */	addi r3, r30, 0x228
/* 800E6118 000E3078  38 9E 00 7C */	addi r4, r30, 0x7c
/* 800E611C 000E307C  38 BE 00 88 */	addi r5, r30, 0x88
/* 800E6120 000E3080  38 DE 00 94 */	addi r6, r30, 0x94
/* 800E6124 000E3084  4B F5 7F D1 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 800E6128 000E3088  38 7E 02 28 */	addi r3, r30, 0x228
/* 800E612C 000E308C  38 81 00 34 */	addi r4, r1, 0x34
/* 800E6130 000E3090  4B F5 7E 05 */	bl multiply__8Matrix4fFR8Matrix4f
/* 800E6134 000E3094  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 800E6138 000E3098  38 9E 02 28 */	addi r4, r30, 0x228
/* 800E613C 000E309C  38 A1 00 74 */	addi r5, r1, 0x74
/* 800E6140 000E30A0  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 800E6144 000E30A4  4B F5 7F 91 */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 800E6148 000E30A8  7F E3 FB 78 */	mr r3, r31
/* 800E614C 000E30AC  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800E6150 000E30B0  38 80 00 01 */	li r4, 1
/* 800E6154 000E30B4  38 A0 00 00 */	li r5, 0
/* 800E6158 000E30B8  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 800E615C 000E30BC  7D 88 03 A6 */	mtlr r12
/* 800E6160 000E30C0  4E 80 00 21 */	blrl 
/* 800E6164 000E30C4  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800E6168 000E30C8  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 800E616C 000E30CC  7F E3 FB 78 */	mr r3, r31
/* 800E6170 000E30D0  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800E6174 000E30D4  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 800E6178 000E30D8  38 A0 00 00 */	li r5, 0
/* 800E617C 000E30DC  7D 88 03 A6 */	mtlr r12
/* 800E6180 000E30E0  4E 80 00 21 */	blrl 
/* 800E6184 000E30E4  80 7E 03 08 */	lwz r3, 0x308(r30)
/* 800E6188 000E30E8  38 9F 00 00 */	addi r4, r31, 0
/* 800E618C 000E30EC  38 A1 00 74 */	addi r5, r1, 0x74
/* 800E6190 000E30F0  38 C0 00 00 */	li r6, 0
/* 800E6194 000E30F4  4B F4 F1 81 */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 800E6198 000E30F8  80 7E 03 08 */	lwz r3, 0x308(r30)
/* 800E619C 000E30FC  7F E4 FB 78 */	mr r4, r31
/* 800E61A0 000E3100  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 800E61A4 000E3104  38 C0 00 00 */	li r6, 0
/* 800E61A8 000E3108  4B F4 A2 C5 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 800E61AC 000E310C  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 800E61B0 000E3110  38 9F 00 00 */	addi r4, r31, 0
/* 800E61B4 000E3114  38 A0 00 00 */	li r5, 0
/* 800E61B8 000E3118  4B FA 39 35 */	bl updateInfo__8CollInfoFR8Graphicsb
/* 800E61BC 000E311C  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 800E61C0 000E3120  83 E1 00 BC */	lwz r31, 0xbc(r1)
/* 800E61C4 000E3124  83 C1 00 B8 */	lwz r30, 0xb8(r1)
/* 800E61C8 000E3128  38 21 00 C0 */	addi r1, r1, 0xc0
/* 800E61CC 000E312C  7C 08 03 A6 */	mtlr r0
/* 800E61D0 000E3130  4E 80 00 20 */	blr 

.global __ct__10BoBaseItemFP12CreaturePropP5Shape
__ct__10BoBaseItemFP12CreaturePropP5Shape:
/* 800E61D4 000E3134  7C 08 02 A6 */	mflr r0
/* 800E61D8 000E3138  38 C5 00 00 */	addi r6, r5, 0
/* 800E61DC 000E313C  90 01 00 04 */	stw r0, 4(r1)
/* 800E61E0 000E3140  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800E61E4 000E3144  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800E61E8 000E3148  3B E4 00 00 */	addi r31, r4, 0
/* 800E61EC 000E314C  38 80 00 23 */	li r4, 0x23
/* 800E61F0 000E3150  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800E61F4 000E3154  3B C3 00 00 */	addi r30, r3, 0
/* 800E61F8 000E3158  80 A3 02 24 */	lwz r5, 0x224(r3)
/* 800E61FC 000E315C  48 00 F6 B1 */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800E6200 000E3160  3C 60 80 2C */	lis r3, __vt__10BoBaseItem@ha
/* 800E6204 000E3164  38 63 BA 74 */	addi r3, r3, __vt__10BoBaseItem@l
/* 800E6208 000E3168  90 7E 00 00 */	stw r3, 0(r30)
/* 800E620C 000E316C  38 03 01 14 */	addi r0, r3, 0x114
/* 800E6210 000E3170  38 7E 03 C8 */	addi r3, r30, 0x3c8
/* 800E6214 000E3174  90 1E 02 B8 */	stw r0, 0x2b8(r30)
/* 800E6218 000E3178  38 80 00 00 */	li r4, 0
/* 800E621C 000E317C  4B FA 2A 15 */	bl __ct__8CollInfoFi
/* 800E6220 000E3180  3C 60 80 08 */	lis r3, __ct__8CollPartFv@ha
/* 800E6224 000E3184  38 83 7E 48 */	addi r4, r3, __ct__8CollPartFv@l
/* 800E6228 000E3188  38 7E 03 DC */	addi r3, r30, 0x3dc
/* 800E622C 000E318C  38 A0 00 00 */	li r5, 0
/* 800E6230 000E3190  38 C0 00 68 */	li r6, 0x68
/* 800E6234 000E3194  38 E0 00 0A */	li r7, 0xa
/* 800E6238 000E3198  48 12 E8 39 */	bl __construct_array
/* 800E623C 000E319C  C0 02 99 78 */	lfs f0, lbl_803E9B78@sda21(r2)
/* 800E6240 000E31A0  38 00 00 00 */	li r0, 0
/* 800E6244 000E31A4  38 60 00 28 */	li r3, 0x28
/* 800E6248 000E31A8  D0 1E 08 1C */	stfs f0, 0x81c(r30)
/* 800E624C 000E31AC  D0 1E 08 18 */	stfs f0, 0x818(r30)
/* 800E6250 000E31B0  D0 1E 08 14 */	stfs f0, 0x814(r30)
/* 800E6254 000E31B4  93 FE 02 24 */	stw r31, 0x224(r30)
/* 800E6258 000E31B8  80 9E 00 C8 */	lwz r4, 0xc8(r30)
/* 800E625C 000E31BC  60 84 02 00 */	ori r4, r4, 0x200
/* 800E6260 000E31C0  90 9E 00 C8 */	stw r4, 0xc8(r30)
/* 800E6264 000E31C4  90 1E 08 20 */	stw r0, 0x820(r30)
/* 800E6268 000E31C8  4B F6 0D 9D */	bl alloc__6SystemFUl
/* 800E626C 000E31CC  3B E3 00 00 */	addi r31, r3, 0
/* 800E6270 000E31D0  7F E3 FB 79 */	or. r3, r31, r31
/* 800E6274 000E31D4  41 82 00 08 */	beq .L_800E627C
/* 800E6278 000E31D8  4B FB D9 E5 */	bl __ct__9SeContextFv
.L_800E627C:
/* 800E627C 000E31DC  93 FE 00 2C */	stw r31, 0x2c(r30)
/* 800E6280 000E31E0  38 9E 00 00 */	addi r4, r30, 0
/* 800E6284 000E31E4  38 A0 00 04 */	li r5, 4
/* 800E6288 000E31E8  80 7E 00 2C */	lwz r3, 0x2c(r30)
/* 800E628C 000E31EC  4B FB DA A9 */	bl setContext__9SeContextFP8Creaturei
/* 800E6290 000E31F0  7F C3 F3 78 */	mr r3, r30
/* 800E6294 000E31F4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800E6298 000E31F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800E629C 000E31FC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800E62A0 000E3200  38 21 00 20 */	addi r1, r1, 0x20
/* 800E62A4 000E3204  7C 08 03 A6 */	mtlr r0
/* 800E62A8 000E3208  4E 80 00 20 */	blr 

.global startAI__10BoBaseItemFi
startAI__10BoBaseItemFi:
/* 800E62AC 000E320C  7C 08 02 A6 */	mflr r0
/* 800E62B0 000E3210  90 01 00 04 */	stw r0, 4(r1)
/* 800E62B4 000E3214  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800E62B8 000E3218  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800E62BC 000E321C  7C 7F 1B 78 */	mr r31, r3
/* 800E62C0 000E3220  38 1F 03 C8 */	addi r0, r31, 0x3c8
/* 800E62C4 000E3224  80 63 00 C8 */	lwz r3, 0xc8(r3)
/* 800E62C8 000E3228  38 BF 03 DC */	addi r5, r31, 0x3dc
/* 800E62CC 000E322C  38 DF 07 EC */	addi r6, r31, 0x7ec
/* 800E62D0 000E3230  60 63 02 00 */	ori r3, r3, 0x200
/* 800E62D4 000E3234  90 7F 00 C8 */	stw r3, 0xc8(r31)
/* 800E62D8 000E3238  90 1F 02 20 */	stw r0, 0x220(r31)
/* 800E62DC 000E323C  80 7F 02 20 */	lwz r3, 0x220(r31)
/* 800E62E0 000E3240  80 9F 03 08 */	lwz r4, 0x308(r31)
/* 800E62E4 000E3244  4B FA 38 81 */	bl initInfo__8CollInfoFP5ShapeP8CollPartPUl
/* 800E62E8 000E3248  C0 0D C8 74 */	lfs f0, lbl_803E1594@sda21(r13)
/* 800E62EC 000E324C  38 80 00 01 */	li r4, 1
/* 800E62F0 000E3250  D0 1F 00 7C */	stfs f0, 0x7c(r31)
/* 800E62F4 000E3254  C0 0D C8 78 */	lfs f0, lbl_803E1598@sda21(r13)
/* 800E62F8 000E3258  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 800E62FC 000E325C  C0 0D C8 7C */	lfs f0, lbl_803E159C@sda21(r13)
/* 800E6300 000E3260  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 800E6304 000E3264  80 7F 00 94 */	lwz r3, 0x94(r31)
/* 800E6308 000E3268  80 1F 00 98 */	lwz r0, 0x98(r31)
/* 800E630C 000E326C  90 7F 08 14 */	stw r3, 0x814(r31)
/* 800E6310 000E3270  90 1F 08 18 */	stw r0, 0x818(r31)
/* 800E6314 000E3274  80 1F 00 9C */	lwz r0, 0x9c(r31)
/* 800E6318 000E3278  90 1F 08 1C */	stw r0, 0x81c(r31)
/* 800E631C 000E327C  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 800E6320 000E3280  C0 3F 00 94 */	lfs f1, 0x94(r31)
/* 800E6324 000E3284  C0 5F 00 9C */	lfs f2, 0x9c(r31)
/* 800E6328 000E3288  4B F8 1B DD */	bl getMinY__6MapMgrFffb
/* 800E632C 000E328C  D0 3F 08 18 */	stfs f1, 0x818(r31)
/* 800E6330 000E3290  38 60 00 01 */	li r3, 1
/* 800E6334 000E3294  38 00 00 00 */	li r0, 0
/* 800E6338 000E3298  98 7F 08 24 */	stb r3, 0x824(r31)
/* 800E633C 000E329C  90 1F 08 28 */	stw r0, 0x828(r31)
/* 800E6340 000E32A0  98 1F 08 25 */	stb r0, 0x825(r31)
/* 800E6344 000E32A4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800E6348 000E32A8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800E634C 000E32AC  38 21 00 18 */	addi r1, r1, 0x18
/* 800E6350 000E32B0  7C 08 03 A6 */	mtlr r0
/* 800E6354 000E32B4  4E 80 00 20 */	blr 

.global ignoreAtari__10BoBaseItemFP8Creature
ignoreAtari__10BoBaseItemFP8Creature:
/* 800E6358 000E32B8  80 04 01 84 */	lwz r0, 0x184(r4)
/* 800E635C 000E32BC  7C 00 18 40 */	cmplw r0, r3
/* 800E6360 000E32C0  40 82 00 0C */	bne .L_800E636C
/* 800E6364 000E32C4  38 60 00 01 */	li r3, 1
/* 800E6368 000E32C8  4E 80 00 20 */	blr 
.L_800E636C:
/* 800E636C 000E32CC  80 03 08 20 */	lwz r0, 0x820(r3)
/* 800E6370 000E32D0  7C 04 00 40 */	cmplw r4, r0
/* 800E6374 000E32D4  40 82 00 0C */	bne .L_800E6380
/* 800E6378 000E32D8  38 60 00 01 */	li r3, 1
/* 800E637C 000E32DC  4E 80 00 20 */	blr 
.L_800E6380:
/* 800E6380 000E32E0  38 60 00 00 */	li r3, 0
/* 800E6384 000E32E4  4E 80 00 20 */	blr 

.global getSize__10BoBaseItemFv
getSize__10BoBaseItemFv:
/* 800E6388 000E32E8  C0 22 99 84 */	lfs f1, lbl_803E9B84@sda21(r2)
/* 800E638C 000E32EC  4E 80 00 20 */	blr 

.global getiMass__10BoBaseItemFv
getiMass__10BoBaseItemFv:
/* 800E6390 000E32F0  C0 22 99 78 */	lfs f1, lbl_803E9B78@sda21(r2)
/* 800E6394 000E32F4  4E 80 00 20 */	blr 

.global update__10BoBaseItemFv
update__10BoBaseItemFv:
/* 800E6398 000E32F8  7C 08 02 A6 */	mflr r0
/* 800E639C 000E32FC  90 01 00 04 */	stw r0, 4(r1)
/* 800E63A0 000E3300  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800E63A4 000E3304  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800E63A8 000E3308  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800E63AC 000E330C  7C 7E 1B 78 */	mr r30, r3
/* 800E63B0 000E3310  88 03 08 24 */	lbz r0, 0x824(r3)
/* 800E63B4 000E3314  28 00 00 00 */	cmplwi r0, 0
/* 800E63B8 000E3318  41 82 00 68 */	beq .L_800E6420
/* 800E63BC 000E331C  80 9E 08 14 */	lwz r4, 0x814(r30)
/* 800E63C0 000E3320  7F C3 F3 78 */	mr r3, r30
/* 800E63C4 000E3324  80 1E 08 18 */	lwz r0, 0x818(r30)
/* 800E63C8 000E3328  90 9E 00 94 */	stw r4, 0x94(r30)
/* 800E63CC 000E332C  90 1E 00 98 */	stw r0, 0x98(r30)
/* 800E63D0 000E3330  80 1E 08 1C */	lwz r0, 0x81c(r30)
/* 800E63D4 000E3334  90 1E 00 9C */	stw r0, 0x9c(r30)
/* 800E63D8 000E3338  48 00 F8 1D */	bl update__12ItemCreatureFv
/* 800E63DC 000E333C  88 7E 08 25 */	lbz r3, 0x825(r30)
/* 800E63E0 000E3340  38 03 FF FF */	addi r0, r3, -1
/* 800E63E4 000E3344  98 1E 08 25 */	stb r0, 0x825(r30)
/* 800E63E8 000E3348  88 1E 08 25 */	lbz r0, 0x825(r30)
/* 800E63EC 000E334C  7C 00 07 75 */	extsb. r0, r0
/* 800E63F0 000E3350  41 81 00 44 */	bgt .L_800E6434
/* 800E63F4 000E3354  3B E0 00 00 */	li r31, 0
/* 800E63F8 000E3358  9B FE 08 25 */	stb r31, 0x825(r30)
/* 800E63FC 000E335C  80 9E 08 28 */	lwz r4, 0x828(r30)
/* 800E6400 000E3360  28 04 00 00 */	cmplwi r4, 0
/* 800E6404 000E3364  41 82 00 30 */	beq .L_800E6434
/* 800E6408 000E3368  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800E640C 000E336C  38 A0 00 00 */	li r5, 0
/* 800E6410 000E3370  38 63 00 14 */	addi r3, r3, 0x14
/* 800E6414 000E3374  48 0B B1 B1 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 800E6418 000E3378  93 FE 08 28 */	stw r31, 0x828(r30)
/* 800E641C 000E337C  48 00 00 18 */	b .L_800E6434
.L_800E6420:
/* 800E6420 000E3380  88 7E 08 25 */	lbz r3, 0x825(r30)
/* 800E6424 000E3384  7C 60 07 75 */	extsb. r0, r3
/* 800E6428 000E3388  40 81 00 0C */	ble .L_800E6434
/* 800E642C 000E338C  38 03 FF FF */	addi r0, r3, -1
/* 800E6430 000E3390  98 1E 08 25 */	stb r0, 0x825(r30)
.L_800E6434:
/* 800E6434 000E3394  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800E6438 000E3398  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800E643C 000E339C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800E6440 000E33A0  38 21 00 18 */	addi r1, r1, 0x18
/* 800E6444 000E33A4  7C 08 03 A6 */	mtlr r0
/* 800E6448 000E33A8  4E 80 00 20 */	blr 

.global refresh__10BoBaseItemFR8Graphics
refresh__10BoBaseItemFR8Graphics:
/* 800E644C 000E33AC  7C 08 02 A6 */	mflr r0
/* 800E6450 000E33B0  90 01 00 04 */	stw r0, 4(r1)
/* 800E6454 000E33B4  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 800E6458 000E33B8  93 E1 00 54 */	stw r31, 0x54(r1)
/* 800E645C 000E33BC  3B E4 00 00 */	addi r31, r4, 0
/* 800E6460 000E33C0  93 C1 00 50 */	stw r30, 0x50(r1)
/* 800E6464 000E33C4  7C 7E 1B 78 */	mr r30, r3
/* 800E6468 000E33C8  88 03 08 24 */	lbz r0, 0x824(r3)
/* 800E646C 000E33CC  28 00 00 00 */	cmplwi r0, 0
/* 800E6470 000E33D0  40 82 00 14 */	bne .L_800E6484
/* 800E6474 000E33D4  40 82 00 AC */	bne .L_800E6520
/* 800E6478 000E33D8  88 1E 08 25 */	lbz r0, 0x825(r30)
/* 800E647C 000E33DC  7C 00 07 75 */	extsb. r0, r0
/* 800E6480 000E33E0  40 81 00 A0 */	ble .L_800E6520
.L_800E6484:
/* 800E6484 000E33E4  38 7E 02 28 */	addi r3, r30, 0x228
/* 800E6488 000E33E8  38 9E 00 7C */	addi r4, r30, 0x7c
/* 800E648C 000E33EC  38 BE 00 88 */	addi r5, r30, 0x88
/* 800E6490 000E33F0  38 DE 00 94 */	addi r6, r30, 0x94
/* 800E6494 000E33F4  4B F5 7C 61 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 800E6498 000E33F8  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 800E649C 000E33FC  38 9E 02 28 */	addi r4, r30, 0x228
/* 800E64A0 000E3400  38 A1 00 10 */	addi r5, r1, 0x10
/* 800E64A4 000E3404  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 800E64A8 000E3408  4B F5 7C 2D */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 800E64AC 000E340C  7F E3 FB 78 */	mr r3, r31
/* 800E64B0 000E3410  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800E64B4 000E3414  38 80 00 01 */	li r4, 1
/* 800E64B8 000E3418  38 A0 00 00 */	li r5, 0
/* 800E64BC 000E341C  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 800E64C0 000E3420  7D 88 03 A6 */	mtlr r12
/* 800E64C4 000E3424  4E 80 00 21 */	blrl 
/* 800E64C8 000E3428  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800E64CC 000E342C  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 800E64D0 000E3430  7F E3 FB 78 */	mr r3, r31
/* 800E64D4 000E3434  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800E64D8 000E3438  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 800E64DC 000E343C  38 A0 00 00 */	li r5, 0
/* 800E64E0 000E3440  7D 88 03 A6 */	mtlr r12
/* 800E64E4 000E3444  4E 80 00 21 */	blrl 
/* 800E64E8 000E3448  80 7E 03 08 */	lwz r3, 0x308(r30)
/* 800E64EC 000E344C  38 9F 00 00 */	addi r4, r31, 0
/* 800E64F0 000E3450  38 A1 00 10 */	addi r5, r1, 0x10
/* 800E64F4 000E3454  38 C0 00 00 */	li r6, 0
/* 800E64F8 000E3458  4B F4 EE 1D */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 800E64FC 000E345C  80 7E 03 08 */	lwz r3, 0x308(r30)
/* 800E6500 000E3460  7F E4 FB 78 */	mr r4, r31
/* 800E6504 000E3464  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 800E6508 000E3468  38 C0 00 00 */	li r6, 0
/* 800E650C 000E346C  4B F4 9F 61 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 800E6510 000E3470  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 800E6514 000E3474  38 9F 00 00 */	addi r4, r31, 0
/* 800E6518 000E3478  38 A0 00 00 */	li r5, 0
/* 800E651C 000E347C  4B FA 35 D1 */	bl updateInfo__8CollInfoFR8Graphicsb
.L_800E6520:
/* 800E6520 000E3480  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 800E6524 000E3484  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 800E6528 000E3488  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 800E652C 000E348C  38 21 00 58 */	addi r1, r1, 0x58
/* 800E6530 000E3490  7C 08 03 A6 */	mtlr r0
/* 800E6534 000E3494  4E 80 00 20 */	blr 

.global interactBuild__10BoBaseItemFR13InteractBuild
interactBuild__10BoBaseItemFR13InteractBuild:
/* 800E6538 000E3498  7C 08 02 A6 */	mflr r0
/* 800E653C 000E349C  90 01 00 04 */	stw r0, 4(r1)
/* 800E6540 000E34A0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800E6544 000E34A4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800E6548 000E34A8  7C 7F 1B 78 */	mr r31, r3
/* 800E654C 000E34AC  80 63 08 20 */	lwz r3, 0x820(r3)
/* 800E6550 000E34B0  28 03 00 00 */	cmplwi r3, 0
/* 800E6554 000E34B4  41 82 00 DC */	beq .L_800E6630
/* 800E6558 000E34B8  C0 22 99 88 */	lfs f1, lbl_803E9B88@sda21(r2)
/* 800E655C 000E34BC  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 800E6560 000E34C0  C4 43 00 58 */	lfsu f2, 0x58(r3)
/* 800E6564 000E34C4  EC 01 00 32 */	fmuls f0, f1, f0
/* 800E6568 000E34C8  EC 02 00 2A */	fadds f0, f2, f0
/* 800E656C 000E34CC  D0 03 00 00 */	stfs f0, 0(r3)
/* 800E6570 000E34D0  80 7F 08 20 */	lwz r3, 0x820(r31)
/* 800E6574 000E34D4  C0 23 00 5C */	lfs f1, 0x5c(r3)
/* 800E6578 000E34D8  38 83 00 58 */	addi r4, r3, 0x58
/* 800E657C 000E34DC  C0 03 00 58 */	lfs f0, 0x58(r3)
/* 800E6580 000E34E0  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 800E6584 000E34E4  4C 41 13 82 */	cror 2, 1, 2
/* 800E6588 000E34E8  40 82 00 60 */	bne .L_800E65E8
/* 800E658C 000E34EC  D0 24 00 00 */	stfs f1, 0(r4)
/* 800E6590 000E34F0  38 00 00 00 */	li r0, 0
/* 800E6594 000E34F4  38 BF 00 94 */	addi r5, r31, 0x94
/* 800E6598 000E34F8  98 1F 08 24 */	stb r0, 0x824(r31)
/* 800E659C 000E34FC  38 80 00 C7 */	li r4, 0xc7
/* 800E65A0 000E3500  38 C0 00 00 */	li r6, 0
/* 800E65A4 000E3504  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800E65A8 000E3508  38 E0 00 00 */	li r7, 0
/* 800E65AC 000E350C  48 0B 65 8D */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 800E65B0 000E3510  38 7F 00 00 */	addi r3, r31, 0
/* 800E65B4 000E3514  38 9F 00 00 */	addi r4, r31, 0
/* 800E65B8 000E3518  38 A0 00 AB */	li r5, 0xab
/* 800E65BC 000E351C  4B FA 3F F9 */	bl playEventSound__8CreatureFP8Creaturei
/* 800E65C0 000E3520  38 00 00 1E */	li r0, 0x1e
/* 800E65C4 000E3524  98 1F 08 25 */	stb r0, 0x825(r31)
/* 800E65C8 000E3528  80 9F 08 28 */	lwz r4, 0x828(r31)
/* 800E65CC 000E352C  28 04 00 00 */	cmplwi r4, 0
/* 800E65D0 000E3530  41 82 00 58 */	beq .L_800E6628
/* 800E65D4 000E3534  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800E65D8 000E3538  38 A0 00 00 */	li r5, 0
/* 800E65DC 000E353C  38 63 00 14 */	addi r3, r3, 0x14
/* 800E65E0 000E3540  48 0B AF E5 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 800E65E4 000E3544  48 00 00 44 */	b .L_800E6628
.L_800E65E8:
/* 800E65E8 000E3548  38 7F 00 00 */	addi r3, r31, 0
/* 800E65EC 000E354C  38 9F 00 00 */	addi r4, r31, 0
/* 800E65F0 000E3550  38 A0 00 AD */	li r5, 0xad
/* 800E65F4 000E3554  4B FA 3F C1 */	bl playEventSound__8CreatureFP8Creaturei
/* 800E65F8 000E3558  38 00 00 1E */	li r0, 0x1e
/* 800E65FC 000E355C  98 1F 08 25 */	stb r0, 0x825(r31)
/* 800E6600 000E3560  80 1F 08 28 */	lwz r0, 0x828(r31)
/* 800E6604 000E3564  28 00 00 00 */	cmplwi r0, 0
/* 800E6608 000E3568  40 82 00 20 */	bne .L_800E6628
/* 800E660C 000E356C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800E6610 000E3570  38 BF 00 94 */	addi r5, r31, 0x94
/* 800E6614 000E3574  38 80 00 C6 */	li r4, 0xc6
/* 800E6618 000E3578  38 C0 00 00 */	li r6, 0
/* 800E661C 000E357C  38 E0 00 00 */	li r7, 0
/* 800E6620 000E3580  48 0B 65 19 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 800E6624 000E3584  90 7F 08 28 */	stw r3, 0x828(r31)
.L_800E6628:
/* 800E6628 000E3588  38 60 00 01 */	li r3, 1
/* 800E662C 000E358C  48 00 00 08 */	b .L_800E6634
.L_800E6630:
/* 800E6630 000E3590  38 60 00 00 */	li r3, 0
.L_800E6634:
/* 800E6634 000E3594  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800E6638 000E3598  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800E663C 000E359C  38 21 00 18 */	addi r1, r1, 0x18
/* 800E6640 000E35A0  7C 08 03 A6 */	mtlr r0
/* 800E6644 000E35A4  4E 80 00 20 */	blr 

.global isAlive__10BoBaseItemFv
isAlive__10BoBaseItemFv:
/* 800E6648 000E35A8  88 63 08 24 */	lbz r3, 0x824(r3)
/* 800E664C 000E35AC  4E 80 00 20 */	blr 

.global isVisible__10BoBaseItemFv
isVisible__10BoBaseItemFv:
/* 800E6650 000E35B0  38 60 00 01 */	li r3, 1
/* 800E6654 000E35B4  4E 80 00 20 */	blr 

.global isVisible__8KusaItemFv
isVisible__8KusaItemFv:
/* 800E6658 000E35B8  38 60 00 01 */	li r3, 1
/* 800E665C 000E35BC  4E 80 00 20 */	blr 

.global isAlive__8KusaItemFv
isAlive__8KusaItemFv:
/* 800E6660 000E35C0  38 60 00 01 */	li r3, 1
/* 800E6664 000E35C4  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BB968:
	.asciz "kusaItem.cpp"
.balign 4
lbl_802BB978:
	.asciz "BoBaseItem"
.balign 4
lbl_802BB984:
	.asciz "PaniAnimKeyListener"
.balign 4
lbl_802BB998:
	.asciz "EventTalker"
.balign 4
lbl_802BB9A4:
	.asciz "RefCountable"
.balign 4
lbl_802BB9B4:
	.asciz "Creature"
.balign 4
lbl_802BB9C0:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
.balign 4
lbl_802BB9D4:
	.asciz "AICreature"
.balign 4
lbl_802BB9E0:
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x2B8
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
.balign 4
lbl_802BBA04:
	.asciz "ItemCreature"
.balign 4
lbl_802BBA14:
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x2B8
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__10AICreature
	.4byte 0
	.4byte 0
lbl_802BBA40:
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x2B8
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__10AICreature
	.4byte 0
	.4byte __RTTI__12ItemCreature
	.4byte 0
	.4byte 0
.global __vt__10BoBaseItem
__vt__10BoBaseItem:
	.4byte __RTTI__10BoBaseItem
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__12ItemCreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__10BoBaseItemFi
	.4byte getiMass__10BoBaseItemFv
	.4byte getSize__10BoBaseItemFv
	.4byte getHeight__12ItemCreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__8CreatureFv
	.4byte isVisible__10BoBaseItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__10BoBaseItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__10BoBaseItemFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__12ItemCreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__10AICreatureFR9CollEvent
	.4byte bounceCallback__10AICreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
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
	.4byte update__10BoBaseItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__10BoBaseItemFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__10BoBaseItem
	.4byte 0xFFFFFD48
	.4byte "@696@animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent"
	.4byte getCurrState__10AICreatureFv
	.4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
	.4byte playSound__10AICreatureFi
	.4byte playEffect__10AICreatureFi
	.4byte startMotion__12ItemCreatureFi
	.4byte finishMotion__12ItemCreatureFv
	.4byte finishMotion__12ItemCreatureFf
	.4byte startMotion__12ItemCreatureFif
	.4byte getCurrentMotionName__12ItemCreatureFv
	.4byte getCurrentMotionCounter__12ItemCreatureFv
	.4byte getMotionSpeed__12ItemCreatureFv
	.4byte setMotionSpeed__12ItemCreatureFf
	.4byte stopMotion__12ItemCreatureFv
	.4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
	.4byte finalSetup__12ItemCreatureFv
.balign 4
lbl_802BBBD0:
	.asciz "KusaItem"
.balign 4
lbl_802BBBDC:
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x2B8
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__10AICreature
	.4byte 0
	.4byte __RTTI__12ItemCreature
	.4byte 0
	.4byte 0
.global __vt__8KusaItem
__vt__8KusaItem:
	.4byte __RTTI__8KusaItem
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__12ItemCreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8KusaItemFi
	.4byte getiMass__8KusaItemFv
	.4byte getSize__8KusaItemFv
	.4byte getHeight__12ItemCreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8KusaItemFR18RandomAccessStream
	.4byte doLoad__8KusaItemFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__8CreatureFv
	.4byte isVisible__8KusaItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8KusaItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8KusaItemFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__12ItemCreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__10AICreatureFR9CollEvent
	.4byte bounceCallback__10AICreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
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
	.4byte update__8KusaItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__8KusaItemFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__8KusaItem
	.4byte 0xFFFFFD48
	.4byte "@696@animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent"
	.4byte getCurrState__10AICreatureFv
	.4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
	.4byte playSound__10AICreatureFi
	.4byte playEffect__10AICreatureFi
	.4byte startMotion__12ItemCreatureFi
	.4byte finishMotion__12ItemCreatureFv
	.4byte finishMotion__12ItemCreatureFf
	.4byte startMotion__12ItemCreatureFif
	.4byte getCurrentMotionName__12ItemCreatureFv
	.4byte getCurrentMotionCounter__12ItemCreatureFv
	.4byte getMotionSpeed__12ItemCreatureFv
	.4byte setMotionSpeed__12ItemCreatureFf
	.4byte stopMotion__12ItemCreatureFv
	.4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
	.4byte finalSetup__12ItemCreatureFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E1568:
	.float 1.0
lbl_803E156C:
	.float 1.0
lbl_803E1570:
	.float 1.0
lbl_803E1574:
	.float 1.0
lbl_803E1578:
	.float 1.0
lbl_803E157C:
	.float 1.0
lbl_803E1580:
	.float 0.0
lbl_803E1584:
	.float 0.0
lbl_803E1588:
	.float 0.0
lbl_803E158C:
	.float 0.0
lbl_803E1590:
	.float 0.0
lbl_803E1594:
	.float 1.0
lbl_803E1598:
	.float 1.0
lbl_803E159C:
	.float 1.0
__RTTI__19PaniAnimKeyListener:
	.4byte lbl_802BB984
	.4byte 0
__RTTI__11EventTalker:
	.4byte lbl_802BB998
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802BB9A4
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802BB9B4
	.4byte lbl_802BB9C0
__RTTI__10AICreature:
	.4byte lbl_802BB9D4
	.4byte lbl_802BB9E0
__RTTI__12ItemCreature:
	.4byte lbl_802BBA04
	.4byte lbl_802BBA14
__RTTI__10BoBaseItem:
	.4byte lbl_802BB978
	.4byte lbl_802BBA40
__RTTI__8KusaItem:
	.4byte lbl_802BBBD0
	.4byte lbl_802BBBDC

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E9B78:
	.float 0.0
lbl_803E9B7C:
	.float 50.0
lbl_803E9B80:
	.float 200.0
lbl_803E9B84:
	.float 10.0
lbl_803E9B88:
	.float 0.4
