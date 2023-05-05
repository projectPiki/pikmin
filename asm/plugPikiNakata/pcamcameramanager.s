.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__17PcamCameraManagerFP6CameraP10Controller, global
/* 80123C54 00120BB4  7C 08 02 A6 */	mflr r0
/* 80123C58 00120BB8  3C C0 80 22 */	lis r6, __vt__5ANode@ha
/* 80123C5C 00120BBC  90 01 00 04 */	stw r0, 4(r1)
/* 80123C60 00120BC0  38 06 73 8C */	addi r0, r6, __vt__5ANode@l
/* 80123C64 00120BC4  38 E0 00 00 */	li r7, 0
/* 80123C68 00120BC8  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 80123C6C 00120BCC  93 E1 00 34 */	stw r31, 0x34(r1)
/* 80123C70 00120BD0  3B E3 00 00 */	addi r31, r3, 0
/* 80123C74 00120BD4  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 80123C78 00120BD8  93 C1 00 30 */	stw r30, 0x30(r1)
/* 80123C7C 00120BDC  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 80123C80 00120BE0  3B A5 00 00 */	addi r29, r5, 0
/* 80123C84 00120BE4  93 81 00 28 */	stw r28, 0x28(r1)
/* 80123C88 00120BE8  3B 84 00 00 */	addi r28, r4, 0
/* 80123C8C 00120BEC  90 1F 00 00 */	stw r0, 0(r31)
/* 80123C90 00120BF0  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 80123C94 00120BF4  3C 60 80 2C */	lis r3, lbl_802C5274@ha
/* 80123C98 00120BF8  90 1F 00 00 */	stw r0, 0(r31)
/* 80123C9C 00120BFC  38 C3 52 74 */	addi r6, r3, lbl_802C5274@l
/* 80123CA0 00120C00  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 80123CA4 00120C04  90 FF 00 10 */	stw r7, 0x10(r31)
/* 80123CA8 00120C08  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 80123CAC 00120C0C  38 7F 00 00 */	addi r3, r31, 0
/* 80123CB0 00120C10  90 FF 00 0C */	stw r7, 0xc(r31)
/* 80123CB4 00120C14  38 86 00 00 */	addi r4, r6, 0
/* 80123CB8 00120C18  90 FF 00 08 */	stw r7, 8(r31)
/* 80123CBC 00120C1C  90 DF 00 04 */	stw r6, 4(r31)
/* 80123CC0 00120C20  90 1F 00 00 */	stw r0, 0(r31)
/* 80123CC4 00120C24  4B F1 CA 79 */	bl init__4NodeFPc
/* 80123CC8 00120C28  3C 60 80 2C */	lis r3, __vt__17PcamCameraManager@ha
/* 80123CCC 00120C2C  38 03 52 D0 */	addi r0, r3, __vt__17PcamCameraManager@l
/* 80123CD0 00120C30  90 1F 00 00 */	stw r0, 0(r31)
/* 80123CD4 00120C34  38 60 01 70 */	li r3, 0x170
/* 80123CD8 00120C38  4B F2 33 2D */	bl alloc__6SystemFUl
/* 80123CDC 00120C3C  3B C3 00 00 */	addi r30, r3, 0
/* 80123CE0 00120C40  7F C3 F3 79 */	or. r3, r30, r30
/* 80123CE4 00120C44  41 82 00 0C */	beq .L_80123CF0
/* 80123CE8 00120C48  7F 84 E3 78 */	mr r4, r28
/* 80123CEC 00120C4C  4B FF DF 21 */	bl __ct__10PcamCameraFP6Camera
.L_80123CF0:
/* 80123CF0 00120C50  93 DF 00 20 */	stw r30, 0x20(r31)
/* 80123CF4 00120C54  38 60 00 14 */	li r3, 0x14
/* 80123CF8 00120C58  93 BF 00 24 */	stw r29, 0x24(r31)
/* 80123CFC 00120C5C  4B F2 33 09 */	bl alloc__6SystemFUl
/* 80123D00 00120C60  90 7F 00 2C */	stw r3, 0x2c(r31)
/* 80123D04 00120C64  38 60 00 60 */	li r3, 0x60
/* 80123D08 00120C68  4B F2 32 FD */	bl alloc__6SystemFUl
/* 80123D0C 00120C6C  3B C3 00 00 */	addi r30, r3, 0
/* 80123D10 00120C70  7F C3 F3 79 */	or. r3, r30, r30
/* 80123D14 00120C74  41 82 00 0C */	beq .L_80123D20
/* 80123D18 00120C78  80 9F 00 20 */	lwz r4, 0x20(r31)
/* 80123D1C 00120C7C  48 00 06 31 */	bl __ct__18PcamVibrationEventFP10PcamCamera
.L_80123D20:
/* 80123D20 00120C80  C0 02 A1 00 */	lfs f0, lbl_803EA300@sda21(r2)
/* 80123D24 00120C84  38 60 00 60 */	li r3, 0x60
/* 80123D28 00120C88  D0 1E 00 48 */	stfs f0, 0x48(r30)
/* 80123D2C 00120C8C  C0 02 A1 04 */	lfs f0, lbl_803EA304@sda21(r2)
/* 80123D30 00120C90  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 80123D34 00120C94  C0 02 A1 08 */	lfs f0, lbl_803EA308@sda21(r2)
/* 80123D38 00120C98  D0 1E 00 50 */	stfs f0, 0x50(r30)
/* 80123D3C 00120C9C  80 9F 00 2C */	lwz r4, 0x2c(r31)
/* 80123D40 00120CA0  93 C4 00 08 */	stw r30, 8(r4)
/* 80123D44 00120CA4  4B F2 32 C1 */	bl alloc__6SystemFUl
/* 80123D48 00120CA8  3B C3 00 00 */	addi r30, r3, 0
/* 80123D4C 00120CAC  7F C3 F3 79 */	or. r3, r30, r30
/* 80123D50 00120CB0  41 82 00 0C */	beq .L_80123D5C
/* 80123D54 00120CB4  80 9F 00 20 */	lwz r4, 0x20(r31)
/* 80123D58 00120CB8  48 00 05 F5 */	bl __ct__18PcamVibrationEventFP10PcamCamera
.L_80123D5C:
/* 80123D5C 00120CBC  C0 02 A1 00 */	lfs f0, lbl_803EA300@sda21(r2)
/* 80123D60 00120CC0  38 60 00 28 */	li r3, 0x28
/* 80123D64 00120CC4  D0 1E 00 48 */	stfs f0, 0x48(r30)
/* 80123D68 00120CC8  C0 02 A1 04 */	lfs f0, lbl_803EA304@sda21(r2)
/* 80123D6C 00120CCC  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 80123D70 00120CD0  C0 02 A1 0C */	lfs f0, lbl_803EA30C@sda21(r2)
/* 80123D74 00120CD4  D0 1E 00 50 */	stfs f0, 0x50(r30)
/* 80123D78 00120CD8  80 9F 00 2C */	lwz r4, 0x2c(r31)
/* 80123D7C 00120CDC  93 C4 00 0C */	stw r30, 0xc(r4)
/* 80123D80 00120CE0  4B F2 32 85 */	bl alloc__6SystemFUl
/* 80123D84 00120CE4  3B A3 00 00 */	addi r29, r3, 0
/* 80123D88 00120CE8  7F A3 EB 79 */	or. r3, r29, r29
/* 80123D8C 00120CEC  41 82 00 0C */	beq .L_80123D98
/* 80123D90 00120CF0  80 9F 00 20 */	lwz r4, 0x20(r31)
/* 80123D94 00120CF4  48 00 04 15 */	bl __ct__22PcamLongVibrationEventFP10PcamCamera
.L_80123D98:
/* 80123D98 00120CF8  80 9F 00 2C */	lwz r4, 0x2c(r31)
/* 80123D9C 00120CFC  38 60 00 60 */	li r3, 0x60
/* 80123DA0 00120D00  93 A4 00 10 */	stw r29, 0x10(r4)
/* 80123DA4 00120D04  4B F2 32 61 */	bl alloc__6SystemFUl
/* 80123DA8 00120D08  3B A3 00 00 */	addi r29, r3, 0
/* 80123DAC 00120D0C  7F A3 EB 79 */	or. r3, r29, r29
/* 80123DB0 00120D10  41 82 00 0C */	beq .L_80123DBC
/* 80123DB4 00120D14  80 9F 00 20 */	lwz r4, 0x20(r31)
/* 80123DB8 00120D18  48 00 06 91 */	bl __ct__15PcamDamageEventFP10PcamCamera
.L_80123DBC:
/* 80123DBC 00120D1C  C0 02 A1 00 */	lfs f0, lbl_803EA300@sda21(r2)
/* 80123DC0 00120D20  38 60 00 48 */	li r3, 0x48
/* 80123DC4 00120D24  D0 1E 00 48 */	stfs f0, 0x48(r30)
/* 80123DC8 00120D28  C0 02 A1 04 */	lfs f0, lbl_803EA304@sda21(r2)
/* 80123DCC 00120D2C  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 80123DD0 00120D30  C0 02 A1 10 */	lfs f0, lbl_803EA310@sda21(r2)
/* 80123DD4 00120D34  D0 1D 00 50 */	stfs f0, 0x50(r29)
/* 80123DD8 00120D38  80 9F 00 2C */	lwz r4, 0x2c(r31)
/* 80123DDC 00120D3C  93 A4 00 04 */	stw r29, 4(r4)
/* 80123DE0 00120D40  4B F2 32 25 */	bl alloc__6SystemFUl
/* 80123DE4 00120D44  3B A3 00 00 */	addi r29, r3, 0
/* 80123DE8 00120D48  7F A3 EB 79 */	or. r3, r29, r29
/* 80123DEC 00120D4C  41 82 00 0C */	beq .L_80123DF8
/* 80123DF0 00120D50  80 9F 00 20 */	lwz r4, 0x20(r31)
/* 80123DF4 00120D54  48 00 09 CD */	bl __ct__22PcamSideVibrationEventFP10PcamCamera
.L_80123DF8:
/* 80123DF8 00120D58  C0 02 A1 00 */	lfs f0, lbl_803EA300@sda21(r2)
/* 80123DFC 00120D5C  38 00 FF FF */	li r0, -1
/* 80123E00 00120D60  38 7F 00 00 */	addi r3, r31, 0
/* 80123E04 00120D64  D0 1E 00 48 */	stfs f0, 0x48(r30)
/* 80123E08 00120D68  C0 02 A1 04 */	lfs f0, lbl_803EA304@sda21(r2)
/* 80123E0C 00120D6C  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 80123E10 00120D70  C0 2D E3 5C */	lfs f1, pi__6NMathF@sda21(r13)
/* 80123E14 00120D74  C0 02 A1 14 */	lfs f0, lbl_803EA314@sda21(r2)
/* 80123E18 00120D78  EC 01 00 24 */	fdivs f0, f1, f0
/* 80123E1C 00120D7C  D0 1D 00 18 */	stfs f0, 0x18(r29)
/* 80123E20 00120D80  80 9F 00 2C */	lwz r4, 0x2c(r31)
/* 80123E24 00120D84  93 A4 00 00 */	stw r29, 0(r4)
/* 80123E28 00120D88  90 1F 00 28 */	stw r0, 0x28(r31)
/* 80123E2C 00120D8C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 80123E30 00120D90  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 80123E34 00120D94  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 80123E38 00120D98  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 80123E3C 00120D9C  83 81 00 28 */	lwz r28, 0x28(r1)
/* 80123E40 00120DA0  38 21 00 38 */	addi r1, r1, 0x38
/* 80123E44 00120DA4  7C 08 03 A6 */	mtlr r0
/* 80123E48 00120DA8  4E 80 00 20 */	blr 
.endfn __ct__17PcamCameraManagerFP6CameraP10Controller

.fn startCamera__17PcamCameraManagerFP8Creature, global
/* 80123E4C 00120DAC  7C 08 02 A6 */	mflr r0
/* 80123E50 00120DB0  90 01 00 04 */	stw r0, 4(r1)
/* 80123E54 00120DB4  94 21 FF F8 */	stwu r1, -8(r1)
/* 80123E58 00120DB8  80 63 00 20 */	lwz r3, 0x20(r3)
/* 80123E5C 00120DBC  4B FF DE E5 */	bl startCamera__10PcamCameraFP8Creature
/* 80123E60 00120DC0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80123E64 00120DC4  38 21 00 08 */	addi r1, r1, 8
/* 80123E68 00120DC8  7C 08 03 A6 */	mtlr r0
/* 80123E6C 00120DCC  4E 80 00 20 */	blr 
.endfn startCamera__17PcamCameraManagerFP8Creature

.fn update__17PcamCameraManagerFv, global
/* 80123E70 00120DD0  7C 08 02 A6 */	mflr r0
/* 80123E74 00120DD4  90 01 00 04 */	stw r0, 4(r1)
/* 80123E78 00120DD8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80123E7C 00120DDC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80123E80 00120DE0  7C 7F 1B 78 */	mr r31, r3
/* 80123E84 00120DE4  80 63 00 20 */	lwz r3, 0x20(r3)
/* 80123E88 00120DE8  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 80123E8C 00120DEC  4B FF E6 59 */	bl control__10PcamCameraFR10Controller
/* 80123E90 00120DF0  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 80123E94 00120DF4  81 83 00 50 */	lwz r12, 0x50(r3)
/* 80123E98 00120DF8  81 8C 00 08 */	lwz r12, 8(r12)
/* 80123E9C 00120DFC  7D 88 03 A6 */	mtlr r12
/* 80123EA0 00120E00  4E 80 00 21 */	blrl 
/* 80123EA4 00120E04  7F E3 FB 78 */	mr r3, r31
/* 80123EA8 00120E08  48 00 00 19 */	bl updateVibrationEvent__17PcamCameraManagerFv
/* 80123EAC 00120E0C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80123EB0 00120E10  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80123EB4 00120E14  38 21 00 18 */	addi r1, r1, 0x18
/* 80123EB8 00120E18  7C 08 03 A6 */	mtlr r0
/* 80123EBC 00120E1C  4E 80 00 20 */	blr 
.endfn update__17PcamCameraManagerFv

.fn updateVibrationEvent__17PcamCameraManagerFv, global
/* 80123EC0 00120E20  7C 08 02 A6 */	mflr r0
/* 80123EC4 00120E24  90 01 00 04 */	stw r0, 4(r1)
/* 80123EC8 00120E28  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80123ECC 00120E2C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80123ED0 00120E30  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80123ED4 00120E34  7C 7E 1B 78 */	mr r30, r3
/* 80123ED8 00120E38  80 03 00 28 */	lwz r0, 0x28(r3)
/* 80123EDC 00120E3C  2C 00 00 00 */	cmpwi r0, 0
/* 80123EE0 00120E40  41 80 00 60 */	blt .L_80123F40
/* 80123EE4 00120E44  80 7E 00 2C */	lwz r3, 0x2c(r30)
/* 80123EE8 00120E48  54 00 10 3A */	slwi r0, r0, 2
/* 80123EEC 00120E4C  7F E3 00 2E */	lwzx r31, r3, r0
/* 80123EF0 00120E50  7F E3 FB 78 */	mr r3, r31
/* 80123EF4 00120E54  81 9F 00 00 */	lwz r12, 0(r31)
/* 80123EF8 00120E58  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 80123EFC 00120E5C  7D 88 03 A6 */	mtlr r12
/* 80123F00 00120E60  4E 80 00 21 */	blrl 
/* 80123F04 00120E64  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80123F08 00120E68  41 82 00 24 */	beq .L_80123F2C
/* 80123F0C 00120E6C  7F E3 FB 78 */	mr r3, r31
/* 80123F10 00120E70  81 9F 00 00 */	lwz r12, 0(r31)
/* 80123F14 00120E74  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 80123F18 00120E78  7D 88 03 A6 */	mtlr r12
/* 80123F1C 00120E7C  4E 80 00 21 */	blrl 
/* 80123F20 00120E80  38 00 FF FF */	li r0, -1
/* 80123F24 00120E84  90 1E 00 28 */	stw r0, 0x28(r30)
/* 80123F28 00120E88  48 00 00 18 */	b .L_80123F40
.L_80123F2C:
/* 80123F2C 00120E8C  7F E3 FB 78 */	mr r3, r31
/* 80123F30 00120E90  81 9F 00 00 */	lwz r12, 0(r31)
/* 80123F34 00120E94  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80123F38 00120E98  7D 88 03 A6 */	mtlr r12
/* 80123F3C 00120E9C  4E 80 00 21 */	blrl 
.L_80123F40:
/* 80123F40 00120EA0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80123F44 00120EA4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80123F48 00120EA8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80123F4C 00120EAC  38 21 00 18 */	addi r1, r1, 0x18
/* 80123F50 00120EB0  7C 08 03 A6 */	mtlr r0
/* 80123F54 00120EB4  4E 80 00 20 */	blr 
.endfn updateVibrationEvent__17PcamCameraManagerFv

.fn update__9PeveEventFv, weak
/* 80123F58 00120EB8  7C 08 02 A6 */	mflr r0
/* 80123F5C 00120EBC  90 01 00 04 */	stw r0, 4(r1)
/* 80123F60 00120EC0  94 21 FF F8 */	stwu r1, -8(r1)
/* 80123F64 00120EC4  80 63 00 08 */	lwz r3, 8(r3)
/* 80123F68 00120EC8  28 03 00 00 */	cmplwi r3, 0
/* 80123F6C 00120ECC  41 82 00 14 */	beq .L_80123F80
/* 80123F70 00120ED0  81 83 00 00 */	lwz r12, 0(r3)
/* 80123F74 00120ED4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80123F78 00120ED8  7D 88 03 A6 */	mtlr r12
/* 80123F7C 00120EDC  4E 80 00 21 */	blrl 
.L_80123F80:
/* 80123F80 00120EE0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80123F84 00120EE4  38 21 00 08 */	addi r1, r1, 8
/* 80123F88 00120EE8  7C 08 03 A6 */	mtlr r0
/* 80123F8C 00120EEC  4E 80 00 20 */	blr 
.endfn update__9PeveEventFv

.fn update__13PeveConditionFv, weak
/* 80123F90 00120EF0  4E 80 00 20 */	blr 
.endfn update__13PeveConditionFv

.fn finish__9PeveEventFv, weak
/* 80123F94 00120EF4  4E 80 00 20 */	blr 
.endfn finish__9PeveEventFv

.fn isFinished__9PeveEventFv, weak
/* 80123F98 00120EF8  7C 08 02 A6 */	mflr r0
/* 80123F9C 00120EFC  90 01 00 04 */	stw r0, 4(r1)
/* 80123FA0 00120F00  94 21 FF F8 */	stwu r1, -8(r1)
/* 80123FA4 00120F04  80 63 00 08 */	lwz r3, 8(r3)
/* 80123FA8 00120F08  28 03 00 00 */	cmplwi r3, 0
/* 80123FAC 00120F0C  40 82 00 0C */	bne .L_80123FB8
/* 80123FB0 00120F10  38 60 00 01 */	li r3, 1
/* 80123FB4 00120F14  48 00 00 14 */	b .L_80123FC8
.L_80123FB8:
/* 80123FB8 00120F18  81 83 00 00 */	lwz r12, 0(r3)
/* 80123FBC 00120F1C  81 8C 00 08 */	lwz r12, 8(r12)
/* 80123FC0 00120F20  7D 88 03 A6 */	mtlr r12
/* 80123FC4 00120F24  4E 80 00 21 */	blrl 
.L_80123FC8:
/* 80123FC8 00120F28  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80123FCC 00120F2C  38 21 00 08 */	addi r1, r1, 8
/* 80123FD0 00120F30  7C 08 03 A6 */	mtlr r0
/* 80123FD4 00120F34  4E 80 00 20 */	blr 
.endfn isFinished__9PeveEventFv

.fn startVibrationEvent__17PcamCameraManagerFiR8Vector3f, global
/* 80123FD8 00120F38  7C 08 02 A6 */	mflr r0
/* 80123FDC 00120F3C  90 01 00 04 */	stw r0, 4(r1)
/* 80123FE0 00120F40  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 80123FE4 00120F44  93 E1 00 6C */	stw r31, 0x6c(r1)
/* 80123FE8 00120F48  3B E5 00 00 */	addi r31, r5, 0
/* 80123FEC 00120F4C  93 C1 00 68 */	stw r30, 0x68(r1)
/* 80123FF0 00120F50  3B C4 00 00 */	addi r30, r4, 0
/* 80123FF4 00120F54  93 A1 00 64 */	stw r29, 0x64(r1)
/* 80123FF8 00120F58  7C 7D 1B 78 */	mr r29, r3
/* 80123FFC 00120F5C  80 03 00 28 */	lwz r0, 0x28(r3)
/* 80124000 00120F60  2C 00 00 00 */	cmpwi r0, 0
/* 80124004 00120F64  41 80 00 0C */	blt .L_80124010
/* 80124008 00120F68  7C 00 F0 00 */	cmpw r0, r30
/* 8012400C 00120F6C  41 80 00 F8 */	blt .L_80124104
.L_80124010:
/* 80124010 00120F70  38 61 00 50 */	addi r3, r1, 0x50
/* 80124014 00120F74  4B FF 8E 41 */	bl __ct__9NVector3fFv
/* 80124018 00120F78  38 7D 00 00 */	addi r3, r29, 0
/* 8012401C 00120F7C  38 81 00 50 */	addi r4, r1, 0x50
/* 80124020 00120F80  48 00 01 3D */	bl outputNaviPosition__17PcamCameraManagerFR8Vector3f
/* 80124024 00120F84  C0 61 00 58 */	lfs f3, 0x58(r1)
/* 80124028 00120F88  C0 5F 00 08 */	lfs f2, 8(r31)
/* 8012402C 00120F8C  C0 21 00 50 */	lfs f1, 0x50(r1)
/* 80124030 00120F90  C0 1F 00 00 */	lfs f0, 0(r31)
/* 80124034 00120F94  EC 43 10 28 */	fsubs f2, f3, f2
/* 80124038 00120F98  EC 21 00 28 */	fsubs f1, f1, f0
/* 8012403C 00120F9C  EC 02 00 B2 */	fmuls f0, f2, f2
/* 80124040 00120FA0  EC 21 00 72 */	fmuls f1, f1, f1
/* 80124044 00120FA4  EC 21 00 2A */	fadds f1, f1, f0
/* 80124048 00120FA8  4B EE 9B F9 */	bl sqrtf__3stdFf
/* 8012404C 00120FAC  80 7D 00 20 */	lwz r3, 0x20(r29)
/* 80124050 00120FB0  80 63 00 D0 */	lwz r3, 0xd0(r3)
/* 80124054 00120FB4  80 63 00 24 */	lwz r3, 0x24(r3)
/* 80124058 00120FB8  80 63 00 04 */	lwz r3, 4(r3)
/* 8012405C 00120FBC  80 63 00 00 */	lwz r3, 0(r3)
/* 80124060 00120FC0  C0 03 00 D4 */	lfs f0, 0xd4(r3)
/* 80124064 00120FC4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80124068 00120FC8  41 81 00 9C */	bgt .L_80124104
/* 8012406C 00120FCC  93 DD 00 28 */	stw r30, 0x28(r29)
/* 80124070 00120FD0  80 9D 00 28 */	lwz r4, 0x28(r29)
/* 80124074 00120FD4  80 7D 00 2C */	lwz r3, 0x2c(r29)
/* 80124078 00120FD8  54 80 10 3A */	slwi r0, r4, 2
/* 8012407C 00120FDC  2C 04 00 02 */	cmpwi r4, 2
/* 80124080 00120FE0  7F E3 00 2E */	lwzx r31, r3, r0
/* 80124084 00120FE4  40 82 00 10 */	bne .L_80124094
/* 80124088 00120FE8  7F E3 FB 78 */	mr r3, r31
/* 8012408C 00120FEC  48 00 03 39 */	bl makePcamVibrationEvent__18PcamVibrationEventFv
/* 80124090 00120FF0  48 00 00 60 */	b .L_801240F0
.L_80124094:
/* 80124094 00120FF4  2C 04 00 03 */	cmpwi r4, 3
/* 80124098 00120FF8  40 82 00 10 */	bne .L_801240A8
/* 8012409C 00120FFC  7F E3 FB 78 */	mr r3, r31
/* 801240A0 00121000  48 00 03 25 */	bl makePcamVibrationEvent__18PcamVibrationEventFv
/* 801240A4 00121004  48 00 00 4C */	b .L_801240F0
.L_801240A8:
/* 801240A8 00121008  2C 04 00 04 */	cmpwi r4, 4
/* 801240AC 0012100C  40 82 00 20 */	bne .L_801240CC
/* 801240B0 00121010  C0 22 A1 18 */	lfs f1, lbl_803EA318@sda21(r2)
/* 801240B4 00121014  7F E3 FB 78 */	mr r3, r31
/* 801240B8 00121018  C0 42 A1 00 */	lfs f2, lbl_803EA300@sda21(r2)
/* 801240BC 0012101C  C0 62 A1 04 */	lfs f3, lbl_803EA304@sda21(r2)
/* 801240C0 00121020  C0 82 A1 1C */	lfs f4, lbl_803EA31C@sda21(r2)
/* 801240C4 00121024  48 00 01 B1 */	bl makePcamLongVibrationEvent__22PcamLongVibrationEventFffff
/* 801240C8 00121028  48 00 00 28 */	b .L_801240F0
.L_801240CC:
/* 801240CC 0012102C  2C 04 00 01 */	cmpwi r4, 1
/* 801240D0 00121030  40 82 00 10 */	bne .L_801240E0
/* 801240D4 00121034  7F E3 FB 78 */	mr r3, r31
/* 801240D8 00121038  48 00 03 E9 */	bl makePcamDamageEvent__15PcamDamageEventFv
/* 801240DC 0012103C  48 00 00 14 */	b .L_801240F0
.L_801240E0:
/* 801240E0 00121040  2C 04 00 00 */	cmpwi r4, 0
/* 801240E4 00121044  40 82 00 0C */	bne .L_801240F0
/* 801240E8 00121048  7F E3 FB 78 */	mr r3, r31
/* 801240EC 0012104C  48 00 07 99 */	bl makePcamSideVibrationEvent__22PcamSideVibrationEventFv
.L_801240F0:
/* 801240F0 00121050  7F E3 FB 78 */	mr r3, r31
/* 801240F4 00121054  81 9F 00 00 */	lwz r12, 0(r31)
/* 801240F8 00121058  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 801240FC 0012105C  7D 88 03 A6 */	mtlr r12
/* 80124100 00121060  4E 80 00 21 */	blrl 
.L_80124104:
/* 80124104 00121064  80 01 00 74 */	lwz r0, 0x74(r1)
/* 80124108 00121068  83 E1 00 6C */	lwz r31, 0x6c(r1)
/* 8012410C 0012106C  83 C1 00 68 */	lwz r30, 0x68(r1)
/* 80124110 00121070  83 A1 00 64 */	lwz r29, 0x64(r1)
/* 80124114 00121074  38 21 00 70 */	addi r1, r1, 0x70
/* 80124118 00121078  7C 08 03 A6 */	mtlr r0
/* 8012411C 0012107C  4E 80 00 20 */	blr 
.endfn startVibrationEvent__17PcamCameraManagerFiR8Vector3f

.fn reset__9PeveEventFv, weak
/* 80124120 00121080  7C 08 02 A6 */	mflr r0
/* 80124124 00121084  90 01 00 04 */	stw r0, 4(r1)
/* 80124128 00121088  94 21 FF F8 */	stwu r1, -8(r1)
/* 8012412C 0012108C  80 63 00 08 */	lwz r3, 8(r3)
/* 80124130 00121090  28 03 00 00 */	cmplwi r3, 0
/* 80124134 00121094  41 82 00 14 */	beq .L_80124148
/* 80124138 00121098  81 83 00 00 */	lwz r12, 0(r3)
/* 8012413C 0012109C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80124140 001210A0  7D 88 03 A6 */	mtlr r12
/* 80124144 001210A4  4E 80 00 21 */	blrl 
.L_80124148:
/* 80124148 001210A8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8012414C 001210AC  38 21 00 08 */	addi r1, r1, 8
/* 80124150 001210B0  7C 08 03 A6 */	mtlr r0
/* 80124154 001210B4  4E 80 00 20 */	blr 
.endfn reset__9PeveEventFv

.fn reset__13PeveConditionFv, weak
/* 80124158 001210B8  4E 80 00 20 */	blr 
.endfn reset__13PeveConditionFv

.fn outputNaviPosition__17PcamCameraManagerFR8Vector3f, global
/* 8012415C 001210BC  7C 08 02 A6 */	mflr r0
/* 80124160 001210C0  90 01 00 04 */	stw r0, 4(r1)
/* 80124164 001210C4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80124168 001210C8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8012416C 001210CC  3B E4 00 00 */	addi r31, r4, 0
/* 80124170 001210D0  38 80 00 00 */	li r4, 0
/* 80124174 001210D4  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 80124178 001210D8  4B FF 32 C1 */	bl getNavi__7NaviMgrFi
/* 8012417C 001210DC  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 80124180 001210E0  D0 1F 00 00 */	stfs f0, 0(r31)
/* 80124184 001210E4  C0 03 00 04 */	lfs f0, 4(r3)
/* 80124188 001210E8  D0 1F 00 04 */	stfs f0, 4(r31)
/* 8012418C 001210EC  C0 03 00 08 */	lfs f0, 8(r3)
/* 80124190 001210F0  D0 1F 00 08 */	stfs f0, 8(r31)
/* 80124194 001210F4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80124198 001210F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8012419C 001210FC  38 21 00 20 */	addi r1, r1, 0x20
/* 801241A0 00121100  7C 08 03 A6 */	mtlr r0
/* 801241A4 00121104  4E 80 00 20 */	blr 
.endfn outputNaviPosition__17PcamCameraManagerFR8Vector3f

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802C5248, local
	.asciz "pcamcameramanager.cpp"
.endobj lbl_802C5248
.balign 4
.obj lbl_802C5260, local
	.asciz "pcamcameramanager"
.endobj lbl_802C5260
.balign 4
.obj lbl_802C5274, local
	.asciz "PcamCameraManager"
.endobj lbl_802C5274
.balign 4
.obj lbl_802C5288, local
	.asciz "CoreNode"
.endobj lbl_802C5288
.balign 4
.obj lbl_802C5294, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.endobj lbl_802C5294
.obj lbl_802C52A0, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.endobj lbl_802C52A0
.obj lbl_802C52B4, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.endobj lbl_802C52B4
.obj __vt__17PcamCameraManager, global
	.4byte __RTTI__17PcamCameraManager
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__17PcamCameraManagerFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
.endobj __vt__17PcamCameraManager
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
.obj lbl_803E3258, local
	.asciz "ANode"
.endobj lbl_803E3258
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803E3258
	.4byte 0
.endobj __RTTI__5ANode
.obj __RTTI__8CoreNode, local
	.4byte lbl_802C5288
	.4byte lbl_802C5294
.endobj __RTTI__8CoreNode
.balign 4
.obj lbl_803E3270, local
	.asciz "Node"
.endobj lbl_803E3270
.balign 4
.obj __RTTI__4Node, local
	.4byte lbl_803E3270
	.4byte lbl_802C52A0
.endobj __RTTI__4Node
.obj __RTTI__17PcamCameraManager, local
	.4byte lbl_802C5274
	.4byte lbl_802C52B4
.endobj __RTTI__17PcamCameraManager

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA300, local
	.float 0.6
.endobj lbl_803EA300
.obj lbl_803EA304, local
	.float 0.2
.endobj lbl_803EA304
.obj lbl_803EA308, local
	.float 8.0
.endobj lbl_803EA308
.obj lbl_803EA30C, local
	.float 4.0
.endobj lbl_803EA30C
.obj lbl_803EA310, local
	.float 30.0
.endobj lbl_803EA310
.obj lbl_803EA314, local
	.float 48.0
.endobj lbl_803EA314
.obj lbl_803EA318, local
	.float 0.4
.endobj lbl_803EA318
.obj lbl_803EA31C, local
	.float 3.0
.endobj lbl_803EA31C
