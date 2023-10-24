.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__7ActExitFP4Piki, global
/* 800B8D68 000B5CC8  7C 08 02 A6 */	mflr r0
/* 800B8D6C 000B5CCC  38 A0 00 01 */	li r5, 1
/* 800B8D70 000B5CD0  90 01 00 04 */	stw r0, 4(r1)
/* 800B8D74 000B5CD4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B8D78 000B5CD8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B8D7C 000B5CDC  3B E3 00 00 */	addi r31, r3, 0
/* 800B8D80 000B5CE0  48 00 B0 51 */	bl __ct__6ActionFP4Pikib
/* 800B8D84 000B5CE4  3C 60 80 2B */	lis r3, __vt__7ActExit@ha
/* 800B8D88 000B5CE8  38 03 67 64 */	addi r0, r3, __vt__7ActExit@l
/* 800B8D8C 000B5CEC  90 1F 00 00 */	stw r0, 0(r31)
/* 800B8D90 000B5CF0  38 8D B6 28 */	addi r4, r13, lbl_803E0348@sda21
/* 800B8D94 000B5CF4  38 00 FF FF */	li r0, -1
/* 800B8D98 000B5CF8  C0 02 92 50 */	lfs f0, lbl_803E9450@sda21(r2)
/* 800B8D9C 000B5CFC  7F E3 FB 78 */	mr r3, r31
/* 800B8DA0 000B5D00  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 800B8DA4 000B5D04  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 800B8DA8 000B5D08  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 800B8DAC 000B5D0C  90 9F 00 10 */	stw r4, 0x10(r31)
/* 800B8DB0 000B5D10  B0 1F 00 08 */	sth r0, 8(r31)
/* 800B8DB4 000B5D14  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B8DB8 000B5D18  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B8DBC 000B5D1C  38 21 00 18 */	addi r1, r1, 0x18
/* 800B8DC0 000B5D20  7C 08 03 A6 */	mtlr r0
/* 800B8DC4 000B5D24  4E 80 00 20 */	blr 
.endfn __ct__7ActExitFP4Piki

.fn init__7ActExitFP8Creature, global
/* 800B8DC8 000B5D28  7C 08 02 A6 */	mflr r0
/* 800B8DCC 000B5D2C  90 01 00 04 */	stw r0, 4(r1)
/* 800B8DD0 000B5D30  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800B8DD4 000B5D34  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800B8DD8 000B5D38  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800B8DDC 000B5D3C  3B C0 00 00 */	li r30, 0
/* 800B8DE0 000B5D40  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800B8DE4 000B5D44  7C 7D 1B 78 */	mr r29, r3
/* 800B8DE8 000B5D48  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800B8DEC 000B5D4C  38 61 00 10 */	addi r3, r1, 0x10
/* 800B8DF0 000B5D50  9B C4 04 08 */	stb r30, 0x408(r4)
/* 800B8DF4 000B5D54  38 80 00 3E */	li r4, 0x3e
/* 800B8DF8 000B5D58  48 06 61 61 */	bl __ct__14PaniMotionInfoFi
/* 800B8DFC 000B5D5C  3B E3 00 00 */	addi r31, r3, 0
/* 800B8E00 000B5D60  38 61 00 18 */	addi r3, r1, 0x18
/* 800B8E04 000B5D64  38 80 00 3E */	li r4, 0x3e
/* 800B8E08 000B5D68  48 06 61 51 */	bl __ct__14PaniMotionInfoFi
/* 800B8E0C 000B5D6C  7C 64 1B 78 */	mr r4, r3
/* 800B8E10 000B5D70  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800B8E14 000B5D74  7F E5 FB 78 */	mr r5, r31
/* 800B8E18 000B5D78  48 01 1B C1 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800B8E1C 000B5D7C  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800B8E20 000B5D80  C0 0D B6 30 */	lfs f0, lbl_803E0350@sda21(r13)
/* 800B8E24 000B5D84  D4 03 00 7C */	stfsu f0, 0x7c(r3)
/* 800B8E28 000B5D88  C0 0D B6 34 */	lfs f0, lbl_803E0354@sda21(r13)
/* 800B8E2C 000B5D8C  D0 03 00 04 */	stfs f0, 4(r3)
/* 800B8E30 000B5D90  C0 0D B6 38 */	lfs f0, lbl_803E0358@sda21(r13)
/* 800B8E34 000B5D94  D0 03 00 08 */	stfs f0, 8(r3)
/* 800B8E38 000B5D98  80 9D 00 0C */	lwz r4, 0xc(r29)
/* 800B8E3C 000B5D9C  80 64 00 94 */	lwz r3, 0x94(r4)
/* 800B8E40 000B5DA0  80 04 00 98 */	lwz r0, 0x98(r4)
/* 800B8E44 000B5DA4  90 7D 00 14 */	stw r3, 0x14(r29)
/* 800B8E48 000B5DA8  90 1D 00 18 */	stw r0, 0x18(r29)
/* 800B8E4C 000B5DAC  80 04 00 9C */	lwz r0, 0x9c(r4)
/* 800B8E50 000B5DB0  90 1D 00 1C */	stw r0, 0x1c(r29)
/* 800B8E54 000B5DB4  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800B8E58 000B5DB8  C0 22 92 54 */	lfs f1, lbl_803E9454@sda21(r2)
/* 800B8E5C 000B5DBC  C0 42 92 58 */	lfs f2, lbl_803E9458@sda21(r2)
/* 800B8E60 000B5DC0  38 63 02 BC */	addi r3, r3, 0x2bc
/* 800B8E64 000B5DC4  48 01 49 B1 */	bl start__8OdoMeterFff
/* 800B8E68 000B5DC8  9B DD 00 20 */	stb r30, 0x20(r29)
/* 800B8E6C 000B5DCC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800B8E70 000B5DD0  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800B8E74 000B5DD4  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800B8E78 000B5DD8  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800B8E7C 000B5DDC  38 21 00 30 */	addi r1, r1, 0x30
/* 800B8E80 000B5DE0  7C 08 03 A6 */	mtlr r0
/* 800B8E84 000B5DE4  4E 80 00 20 */	blr 
.endfn init__7ActExitFP8Creature

.fn procCollideMsg__7ActExitFP4PikiP10MsgCollide, global
/* 800B8E88 000B5DE8  80 85 00 04 */	lwz r4, 4(r5)
/* 800B8E8C 000B5DEC  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 800B8E90 000B5DF0  2C 00 00 10 */	cmpwi r0, 0x10
/* 800B8E94 000B5DF4  4D 82 00 20 */	beqlr 
/* 800B8E98 000B5DF8  2C 00 00 00 */	cmpwi r0, 0
/* 800B8E9C 000B5DFC  4D 82 00 20 */	beqlr 
/* 800B8EA0 000B5E00  2C 00 00 36 */	cmpwi r0, 0x36
/* 800B8EA4 000B5E04  4D 82 00 20 */	beqlr 
/* 800B8EA8 000B5E08  38 00 00 01 */	li r0, 1
/* 800B8EAC 000B5E0C  98 03 00 20 */	stb r0, 0x20(r3)
/* 800B8EB0 000B5E10  4E 80 00 20 */	blr 
.endfn procCollideMsg__7ActExitFP4PikiP10MsgCollide

.fn exec__7ActExitFv, global
/* 800B8EB4 000B5E14  7C 08 02 A6 */	mflr r0
/* 800B8EB8 000B5E18  90 01 00 04 */	stw r0, 4(r1)
/* 800B8EBC 000B5E1C  94 21 FE D0 */	stwu r1, -0x130(r1)
/* 800B8EC0 000B5E20  DB E1 01 28 */	stfd f31, 0x128(r1)
/* 800B8EC4 000B5E24  DB C1 01 20 */	stfd f30, 0x120(r1)
/* 800B8EC8 000B5E28  DB A1 01 18 */	stfd f29, 0x118(r1)
/* 800B8ECC 000B5E2C  DB 81 01 10 */	stfd f28, 0x110(r1)
/* 800B8ED0 000B5E30  DB 61 01 08 */	stfd f27, 0x108(r1)
/* 800B8ED4 000B5E34  DB 41 01 00 */	stfd f26, 0x100(r1)
/* 800B8ED8 000B5E38  DB 21 00 F8 */	stfd f25, 0xf8(r1)
/* 800B8EDC 000B5E3C  93 E1 00 F4 */	stw r31, 0xf4(r1)
/* 800B8EE0 000B5E40  7C 7F 1B 78 */	mr r31, r3
/* 800B8EE4 000B5E44  88 03 00 20 */	lbz r0, 0x20(r3)
/* 800B8EE8 000B5E48  28 00 00 00 */	cmplwi r0, 0
/* 800B8EEC 000B5E4C  40 82 00 14 */	bne .L_800B8F00
/* 800B8EF0 000B5E50  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B8EF4 000B5E54  80 04 01 58 */	lwz r0, 0x158(r4)
/* 800B8EF8 000B5E58  28 00 00 00 */	cmplwi r0, 0
/* 800B8EFC 000B5E5C  40 82 00 28 */	bne .L_800B8F24
.L_800B8F00:
/* 800B8F00 000B5E60  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B8F04 000B5E64  38 60 00 01 */	li r3, 1
/* 800B8F08 000B5E68  C0 0D B6 3C */	lfs f0, lbl_803E035C@sda21(r13)
/* 800B8F0C 000B5E6C  D4 04 00 7C */	stfsu f0, 0x7c(r4)
/* 800B8F10 000B5E70  C0 0D B6 40 */	lfs f0, lbl_803E0360@sda21(r13)
/* 800B8F14 000B5E74  D0 04 00 04 */	stfs f0, 4(r4)
/* 800B8F18 000B5E78  C0 0D B6 44 */	lfs f0, lbl_803E0364@sda21(r13)
/* 800B8F1C 000B5E7C  D0 04 00 08 */	stfs f0, 8(r4)
/* 800B8F20 000B5E80  48 00 02 4C */	b .L_800B916C
.L_800B8F24:
/* 800B8F24 000B5E84  38 64 02 BC */	addi r3, r4, 0x2bc
/* 800B8F28 000B5E88  38 84 00 94 */	addi r4, r4, 0x94
/* 800B8F2C 000B5E8C  38 BF 00 14 */	addi r5, r31, 0x14
/* 800B8F30 000B5E90  48 01 48 FD */	bl moving__8OdoMeterFR8Vector3fR8Vector3f
/* 800B8F34 000B5E94  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B8F38 000B5E98  40 82 00 30 */	bne .L_800B8F68
/* 800B8F3C 000B5E9C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B8F40 000B5EA0  4B FD 7C AD */	bl endRope__8CreatureFv
/* 800B8F44 000B5EA4  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B8F48 000B5EA8  38 60 00 01 */	li r3, 1
/* 800B8F4C 000B5EAC  C0 0D B6 48 */	lfs f0, lbl_803E0368@sda21(r13)
/* 800B8F50 000B5EB0  D4 04 00 7C */	stfsu f0, 0x7c(r4)
/* 800B8F54 000B5EB4  C0 0D B6 4C */	lfs f0, lbl_803E036C@sda21(r13)
/* 800B8F58 000B5EB8  D0 04 00 04 */	stfs f0, 4(r4)
/* 800B8F5C 000B5EBC  C0 0D B6 50 */	lfs f0, lbl_803E0370@sda21(r13)
/* 800B8F60 000B5EC0  D0 04 00 08 */	stfs f0, 8(r4)
/* 800B8F64 000B5EC4  48 00 02 08 */	b .L_800B916C
.L_800B8F68:
/* 800B8F68 000B5EC8  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B8F6C 000B5ECC  80 64 00 94 */	lwz r3, 0x94(r4)
/* 800B8F70 000B5ED0  80 04 00 98 */	lwz r0, 0x98(r4)
/* 800B8F74 000B5ED4  90 7F 00 14 */	stw r3, 0x14(r31)
/* 800B8F78 000B5ED8  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800B8F7C 000B5EDC  80 04 00 9C */	lwz r0, 0x9c(r4)
/* 800B8F80 000B5EE0  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 800B8F84 000B5EE4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B8F88 000B5EE8  C0 02 92 5C */	lfs f0, lbl_803E945C@sda21(r2)
/* 800B8F8C 000B5EEC  C0 23 01 5C */	lfs f1, 0x15c(r3)
/* 800B8F90 000B5EF0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B8F94 000B5EF4  40 81 00 44 */	ble .L_800B8FD8
/* 800B8F98 000B5EF8  38 00 00 00 */	li r0, 0
/* 800B8F9C 000B5EFC  98 03 04 09 */	stb r0, 0x409(r3)
/* 800B8FA0 000B5F00  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B8FA4 000B5F04  C0 42 92 54 */	lfs f2, lbl_803E9454@sda21(r2)
/* 800B8FA8 000B5F08  C0 03 01 5C */	lfs f0, 0x15c(r3)
/* 800B8FAC 000B5F0C  C0 22 92 60 */	lfs f1, lbl_803E9460@sda21(r2)
/* 800B8FB0 000B5F10  EC 42 00 28 */	fsubs f2, f2, f0
/* 800B8FB4 000B5F14  C0 02 92 50 */	lfs f0, lbl_803E9450@sda21(r2)
/* 800B8FB8 000B5F18  EC 22 08 24 */	fdivs f1, f2, f1
/* 800B8FBC 000B5F1C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B8FC0 000B5F20  40 80 00 08 */	bge .L_800B8FC8
/* 800B8FC4 000B5F24  FC 20 00 90 */	fmr f1, f0
.L_800B8FC8:
/* 800B8FC8 000B5F28  D4 23 00 7C */	stfsu f1, 0x7c(r3)
/* 800B8FCC 000B5F2C  D0 23 00 04 */	stfs f1, 4(r3)
/* 800B8FD0 000B5F30  D0 23 00 08 */	stfs f1, 8(r3)
/* 800B8FD4 000B5F34  48 00 00 1C */	b .L_800B8FF0
.L_800B8FD8:
/* 800B8FD8 000B5F38  C0 0D B6 54 */	lfs f0, lbl_803E0374@sda21(r13)
/* 800B8FDC 000B5F3C  D4 03 00 7C */	stfsu f0, 0x7c(r3)
/* 800B8FE0 000B5F40  C0 0D B6 58 */	lfs f0, lbl_803E0378@sda21(r13)
/* 800B8FE4 000B5F44  D0 03 00 04 */	stfs f0, 4(r3)
/* 800B8FE8 000B5F48  C0 0D B6 5C */	lfs f0, lbl_803E037C@sda21(r13)
/* 800B8FEC 000B5F4C  D0 03 00 08 */	stfs f0, 8(r3)
.L_800B8FF0:
/* 800B8FF0 000B5F50  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B8FF4 000B5F54  80 03 02 8C */	lwz r0, 0x28c(r3)
/* 800B8FF8 000B5F58  28 00 00 00 */	cmplwi r0, 0
/* 800B8FFC 000B5F5C  41 82 00 0C */	beq .L_800B9008
/* 800B9000 000B5F60  38 60 00 02 */	li r3, 2
/* 800B9004 000B5F64  48 00 01 68 */	b .L_800B916C
.L_800B9008:
/* 800B9008 000B5F68  C0 23 01 5C */	lfs f1, 0x15c(r3)
/* 800B900C 000B5F6C  C0 02 92 50 */	lfs f0, lbl_803E9450@sda21(r2)
/* 800B9010 000B5F70  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B9014 000B5F74  40 80 00 0C */	bge .L_800B9020
/* 800B9018 000B5F78  38 60 00 02 */	li r3, 2
/* 800B901C 000B5F7C  48 00 01 50 */	b .L_800B916C
.L_800B9020:
/* 800B9020 000B5F80  48 15 F0 51 */	bl rand
/* 800B9024 000B5F84  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800B9028 000B5F88  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B902C 000B5F8C  90 01 00 EC */	stw r0, 0xec(r1)
/* 800B9030 000B5F90  3C 00 43 30 */	lis r0, 0x4330
/* 800B9034 000B5F94  80 64 01 58 */	lwz r3, 0x158(r4)
/* 800B9038 000B5F98  90 01 00 E8 */	stw r0, 0xe8(r1)
/* 800B903C 000B5F9C  C7 E3 02 C4 */	lfsu f31, 0x2c4(r3)
/* 800B9040 000B5FA0  C8 42 92 78 */	lfd f2, lbl_803E9478@sda21(r2)
/* 800B9044 000B5FA4  C8 01 00 E8 */	lfd f0, 0xe8(r1)
/* 800B9048 000B5FA8  C0 22 92 64 */	lfs f1, lbl_803E9464@sda21(r2)
/* 800B904C 000B5FAC  EC 80 10 28 */	fsubs f4, f0, f2
/* 800B9050 000B5FB0  C0 62 92 54 */	lfs f3, lbl_803E9454@sda21(r2)
/* 800B9054 000B5FB4  C0 02 92 6C */	lfs f0, lbl_803E946C@sda21(r2)
/* 800B9058 000B5FB8  C0 42 92 68 */	lfs f2, lbl_803E9468@sda21(r2)
/* 800B905C 000B5FBC  EC 84 08 24 */	fdivs f4, f4, f1
/* 800B9060 000B5FC0  C3 C3 00 04 */	lfs f30, 4(r3)
/* 800B9064 000B5FC4  C3 A3 00 08 */	lfs f29, 8(r3)
/* 800B9068 000B5FC8  C0 24 00 A0 */	lfs f1, 0xa0(r4)
/* 800B906C 000B5FCC  EC 63 01 32 */	fmuls f3, f3, f4
/* 800B9070 000B5FD0  EC 03 00 28 */	fsubs f0, f3, f0
/* 800B9074 000B5FD4  EF 82 00 32 */	fmuls f28, f2, f0
/* 800B9078 000B5FD8  48 16 2A DD */	bl cosf
/* 800B907C 000B5FDC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B9080 000B5FE0  FF 60 08 90 */	fmr f27, f1
/* 800B9084 000B5FE4  C0 23 00 A0 */	lfs f1, 0xa0(r3)
/* 800B9088 000B5FE8  48 16 2C 61 */	bl sinf
/* 800B908C 000B5FEC  C0 CD B6 60 */	lfs f6, lbl_803E0380@sda21(r13)
/* 800B9090 000B5FF0  EC 9B 07 B2 */	fmuls f4, f27, f30
/* 800B9094 000B5FF4  EC 5B 07 F2 */	fmuls f2, f27, f31
/* 800B9098 000B5FF8  EC A6 07 72 */	fmuls f5, f6, f29
/* 800B909C 000B5FFC  EC 01 07 72 */	fmuls f0, f1, f29
/* 800B90A0 000B6000  EC 61 07 B2 */	fmuls f3, f1, f30
/* 800B90A4 000B6004  EF 65 20 28 */	fsubs f27, f5, f4
/* 800B90A8 000B6008  EF 42 00 28 */	fsubs f26, f2, f0
/* 800B90AC 000B600C  EC 46 07 F2 */	fmuls f2, f6, f31
/* 800B90B0 000B6010  EC 3B 06 F2 */	fmuls f1, f27, f27
/* 800B90B4 000B6014  EC 1A 06 B2 */	fmuls f0, f26, f26
/* 800B90B8 000B6018  EF 23 10 28 */	fsubs f25, f3, f2
/* 800B90BC 000B601C  EC 01 00 2A */	fadds f0, f1, f0
/* 800B90C0 000B6020  EC 39 06 72 */	fmuls f1, f25, f25
/* 800B90C4 000B6024  EC 21 00 2A */	fadds f1, f1, f0
/* 800B90C8 000B6028  4B F5 4B 79 */	bl sqrtf__3stdFf
/* 800B90CC 000B602C  C0 02 92 50 */	lfs f0, lbl_803E9450@sda21(r2)
/* 800B90D0 000B6030  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800B90D4 000B6034  41 82 00 10 */	beq .L_800B90E4
/* 800B90D8 000B6038  EF 7B 08 24 */	fdivs f27, f27, f1
/* 800B90DC 000B603C  EF 5A 08 24 */	fdivs f26, f26, f1
/* 800B90E0 000B6040  EF 39 08 24 */	fdivs f25, f25, f1
.L_800B90E4:
/* 800B90E4 000B6044  C0 02 92 70 */	lfs f0, lbl_803E9470@sda21(r2)
/* 800B90E8 000B6048  EC 5B 07 32 */	fmuls f2, f27, f28
/* 800B90EC 000B604C  EC 3A 07 32 */	fmuls f1, f26, f28
/* 800B90F0 000B6050  38 60 00 00 */	li r3, 0
/* 800B90F4 000B6054  FC 80 00 50 */	fneg f4, f0
/* 800B90F8 000B6058  D0 41 00 6C */	stfs f2, 0x6c(r1)
/* 800B90FC 000B605C  EC 19 07 32 */	fmuls f0, f25, f28
/* 800B9100 000B6060  EC 5F 01 32 */	fmuls f2, f31, f4
/* 800B9104 000B6064  EC 7E 01 32 */	fmuls f3, f30, f4
/* 800B9108 000B6068  D0 41 00 78 */	stfs f2, 0x78(r1)
/* 800B910C 000B606C  EC 5D 01 32 */	fmuls f2, f29, f4
/* 800B9110 000B6070  C0 81 00 78 */	lfs f4, 0x78(r1)
/* 800B9114 000B6074  D0 81 00 A0 */	stfs f4, 0xa0(r1)
/* 800B9118 000B6078  D0 61 00 A4 */	stfs f3, 0xa4(r1)
/* 800B911C 000B607C  D0 41 00 A8 */	stfs f2, 0xa8(r1)
/* 800B9120 000B6080  C0 61 00 A0 */	lfs f3, 0xa0(r1)
/* 800B9124 000B6084  C0 41 00 6C */	lfs f2, 0x6c(r1)
/* 800B9128 000B6088  EC 43 10 2A */	fadds f2, f3, f2
/* 800B912C 000B608C  D0 41 00 60 */	stfs f2, 0x60(r1)
/* 800B9130 000B6090  C0 41 00 60 */	lfs f2, 0x60(r1)
/* 800B9134 000B6094  D0 41 00 AC */	stfs f2, 0xac(r1)
/* 800B9138 000B6098  C0 41 00 A4 */	lfs f2, 0xa4(r1)
/* 800B913C 000B609C  EC 22 08 2A */	fadds f1, f2, f1
/* 800B9140 000B60A0  D0 21 00 B0 */	stfs f1, 0xb0(r1)
/* 800B9144 000B60A4  C0 21 00 A8 */	lfs f1, 0xa8(r1)
/* 800B9148 000B60A8  EC 01 00 2A */	fadds f0, f1, f0
/* 800B914C 000B60AC  D0 01 00 B4 */	stfs f0, 0xb4(r1)
/* 800B9150 000B60B0  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800B9154 000B60B4  80 81 00 AC */	lwz r4, 0xac(r1)
/* 800B9158 000B60B8  80 01 00 B0 */	lwz r0, 0xb0(r1)
/* 800B915C 000B60BC  90 85 00 70 */	stw r4, 0x70(r5)
/* 800B9160 000B60C0  90 05 00 74 */	stw r0, 0x74(r5)
/* 800B9164 000B60C4  80 01 00 B4 */	lwz r0, 0xb4(r1)
/* 800B9168 000B60C8  90 05 00 78 */	stw r0, 0x78(r5)
.L_800B916C:
/* 800B916C 000B60CC  80 01 01 34 */	lwz r0, 0x134(r1)
/* 800B9170 000B60D0  CB E1 01 28 */	lfd f31, 0x128(r1)
/* 800B9174 000B60D4  CB C1 01 20 */	lfd f30, 0x120(r1)
/* 800B9178 000B60D8  CB A1 01 18 */	lfd f29, 0x118(r1)
/* 800B917C 000B60DC  CB 81 01 10 */	lfd f28, 0x110(r1)
/* 800B9180 000B60E0  CB 61 01 08 */	lfd f27, 0x108(r1)
/* 800B9184 000B60E4  CB 41 01 00 */	lfd f26, 0x100(r1)
/* 800B9188 000B60E8  CB 21 00 F8 */	lfd f25, 0xf8(r1)
/* 800B918C 000B60EC  83 E1 00 F4 */	lwz r31, 0xf4(r1)
/* 800B9190 000B60F0  38 21 01 30 */	addi r1, r1, 0x130
/* 800B9194 000B60F4  7C 08 03 A6 */	mtlr r0
/* 800B9198 000B60F8  4E 80 00 20 */	blr 
.endfn exec__7ActExitFv

.fn cleanup__7ActExitFv, global
/* 800B919C 000B60FC  7C 08 02 A6 */	mflr r0
/* 800B91A0 000B6100  90 01 00 04 */	stw r0, 4(r1)
/* 800B91A4 000B6104  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800B91A8 000B6108  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 800B91AC 000B610C  DB C1 00 18 */	stfd f30, 0x18(r1)
/* 800B91B0 000B6110  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B91B4 000B6114  7C 7F 1B 78 */	mr r31, r3
/* 800B91B8 000B6118  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800B91BC 000B611C  81 83 00 00 */	lwz r12, 0(r3)
/* 800B91C0 000B6120  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 800B91C4 000B6124  7D 88 03 A6 */	mtlr r12
/* 800B91C8 000B6128  4E 80 00 21 */	blrl 
/* 800B91CC 000B612C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B91D0 000B6130  41 82 00 20 */	beq .L_800B91F0
/* 800B91D4 000B6134  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B91D8 000B6138  C0 0D B6 64 */	lfs f0, lbl_803E0384@sda21(r13)
/* 800B91DC 000B613C  D4 03 00 7C */	stfsu f0, 0x7c(r3)
/* 800B91E0 000B6140  C0 0D B6 68 */	lfs f0, lbl_803E0388@sda21(r13)
/* 800B91E4 000B6144  D0 03 00 04 */	stfs f0, 4(r3)
/* 800B91E8 000B6148  C0 0D B6 6C */	lfs f0, lbl_803E038C@sda21(r13)
/* 800B91EC 000B614C  D0 03 00 08 */	stfs f0, 8(r3)
.L_800B91F0:
/* 800B91F0 000B6150  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B91F4 000B6154  38 00 00 01 */	li r0, 1
/* 800B91F8 000B6158  98 03 04 09 */	stb r0, 0x409(r3)
/* 800B91FC 000B615C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B9200 000B6160  4B FD 79 ED */	bl endRope__8CreatureFv
/* 800B9204 000B6164  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B9208 000B6168  C3 C3 00 A0 */	lfs f30, 0xa0(r3)
/* 800B920C 000B616C  FC 20 F0 90 */	fmr f1, f30
/* 800B9210 000B6170  48 16 29 45 */	bl cosf
/* 800B9214 000B6174  C0 02 92 80 */	lfs f0, lbl_803E9480@sda21(r2)
/* 800B9218 000B6178  EF E0 00 72 */	fmuls f31, f0, f1
/* 800B921C 000B617C  FC 20 F0 90 */	fmr f1, f30
/* 800B9220 000B6180  48 16 2A C9 */	bl sinf
/* 800B9224 000B6184  C0 02 92 80 */	lfs f0, lbl_803E9480@sda21(r2)
/* 800B9228 000B6188  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B922C 000B618C  EC 00 00 72 */	fmuls f0, f0, f1
/* 800B9230 000B6190  D4 03 00 70 */	stfsu f0, 0x70(r3)
/* 800B9234 000B6194  C0 0D B6 70 */	lfs f0, lbl_803E0390@sda21(r13)
/* 800B9238 000B6198  D0 03 00 04 */	stfs f0, 4(r3)
/* 800B923C 000B619C  D3 E3 00 08 */	stfs f31, 8(r3)
/* 800B9240 000B61A0  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800B9244 000B61A4  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 800B9248 000B61A8  CB C1 00 18 */	lfd f30, 0x18(r1)
/* 800B924C 000B61AC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B9250 000B61B0  38 21 00 28 */	addi r1, r1, 0x28
/* 800B9254 000B61B4  7C 08 03 A6 */	mtlr r0
/* 800B9258 000B61B8  4E 80 00 20 */	blr 
.endfn cleanup__7ActExitFv

.fn __dt__7ActExitFv, weak
/* 800B925C 000B61BC  7C 08 02 A6 */	mflr r0
/* 800B9260 000B61C0  90 01 00 04 */	stw r0, 4(r1)
/* 800B9264 000B61C4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B9268 000B61C8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B926C 000B61CC  3B E4 00 00 */	addi r31, r4, 0
/* 800B9270 000B61D0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800B9274 000B61D4  7C 7E 1B 79 */	or. r30, r3, r3
/* 800B9278 000B61D8  41 82 00 2C */	beq .L_800B92A4
/* 800B927C 000B61DC  3C 60 80 2B */	lis r3, __vt__7ActExit@ha
/* 800B9280 000B61E0  38 03 67 64 */	addi r0, r3, __vt__7ActExit@l
/* 800B9284 000B61E4  90 1E 00 00 */	stw r0, 0(r30)
/* 800B9288 000B61E8  38 7E 00 00 */	addi r3, r30, 0
/* 800B928C 000B61EC  38 80 00 00 */	li r4, 0
/* 800B9290 000B61F0  48 00 AB 79 */	bl __dt__6ActionFv
/* 800B9294 000B61F4  7F E0 07 35 */	extsh. r0, r31
/* 800B9298 000B61F8  40 81 00 0C */	ble .L_800B92A4
/* 800B929C 000B61FC  7F C3 F3 78 */	mr r3, r30
/* 800B92A0 000B6200  4B F8 DF 0D */	bl __dl__FPv
.L_800B92A4:
/* 800B92A4 000B6204  7F C3 F3 78 */	mr r3, r30
/* 800B92A8 000B6208  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B92AC 000B620C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B92B0 000B6210  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800B92B4 000B6214  38 21 00 18 */	addi r1, r1, 0x18
/* 800B92B8 000B6218  7C 08 03 A6 */	mtlr r0
/* 800B92BC 000B621C  4E 80 00 20 */	blr 
.endfn __dt__7ActExitFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B6728, local
	.asciz "aiExit.cpp"
.endobj lbl_802B6728
.balign 4
.obj lbl_802B6734, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B6734
.balign 4
.obj lbl_802B6744, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.endobj lbl_802B6744
.balign 4
.obj lbl_802B6750, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B6750
.balign 4
.obj __vt__7ActExit, global
	.4byte __RTTI__7ActExit
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte procCollideMsg__7ActExitFP4PikiP10MsgCollide
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__6ActionFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__7ActExitFv
	.4byte init__7ActExitFP8Creature
	.4byte exec__7ActExitFv
	.4byte cleanup__7ActExitFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
.endobj __vt__7ActExit
.balign 4
.obj lbl_802B67C8, local
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
.endobj lbl_802B67C8

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E0348, local
	.asciz "Exit"
.endobj lbl_803E0348
.balign 4
.obj lbl_803E0350, local
	.float 0.0
.endobj lbl_803E0350
.obj lbl_803E0354, local
	.float 0.0
.endobj lbl_803E0354
.obj lbl_803E0358, local
	.float 0.0
.endobj lbl_803E0358
.obj lbl_803E035C, local
	.float 1.0
.endobj lbl_803E035C
.obj lbl_803E0360, local
	.float 1.0
.endobj lbl_803E0360
.obj lbl_803E0364, local
	.float 1.0
.endobj lbl_803E0364
.obj lbl_803E0368, local
	.float 1.0
.endobj lbl_803E0368
.obj lbl_803E036C, local
	.float 1.0
.endobj lbl_803E036C
.obj lbl_803E0370, local
	.float 1.0
.endobj lbl_803E0370
.obj lbl_803E0374, local
	.float 1.0
.endobj lbl_803E0374
.obj lbl_803E0378, local
	.float 1.0
.endobj lbl_803E0378
.obj lbl_803E037C, local
	.float 1.0
.endobj lbl_803E037C
.obj lbl_803E0380, local
	.float 0.0
.endobj lbl_803E0380
.obj lbl_803E0384, local
	.float 1.0
.endobj lbl_803E0384
.obj lbl_803E0388, local
	.float 1.0
.endobj lbl_803E0388
.obj lbl_803E038C, local
	.float 1.0
.endobj lbl_803E038C
.obj lbl_803E0390, local
	.float 200.0
.endobj lbl_803E0390
.balign 4
.obj lbl_803E0394, local
	.asciz "ActExit"
.endobj lbl_803E0394
.balign 4
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B6734
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E03A4, local
	.asciz "Action"
.endobj lbl_803E03A4
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E03A4
	.4byte lbl_802B6744
.endobj __RTTI__6Action
.obj __RTTI__7ActExit, local
	.4byte lbl_803E0394
	.4byte lbl_802B6750
.endobj __RTTI__7ActExit

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9450, local
	.float 0.0
.endobj lbl_803E9450
.obj lbl_803E9454, local
	.float 1.0
.endobj lbl_803E9454
.obj lbl_803E9458, local
	.float 5.0
.endobj lbl_803E9458
.obj lbl_803E945C, local
	.float 0.72
.endobj lbl_803E945C
.obj lbl_803E9460, local
	.float 0.27999997
.endobj lbl_803E9460
.obj lbl_803E9464, local
	.float 32767.0
.endobj lbl_803E9464
.obj lbl_803E9468, local
	.float 8.0
.endobj lbl_803E9468
.obj lbl_803E946C, local
	.float 0.5
.endobj lbl_803E946C
.obj lbl_803E9470, local
	.float 70.0
.endobj lbl_803E9470
.balign 8
.obj lbl_803E9478, local
	.8byte 0x4330000080000000
.endobj lbl_803E9478
.obj lbl_803E9480, local
	.float 50.0
.endobj lbl_803E9480
