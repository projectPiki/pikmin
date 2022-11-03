.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__17PeveTimeConditionFv
__ct__17PeveTimeConditionFv:
/* 80125C68 00122BC8  7C 08 02 A6 */	mflr r0
/* 80125C6C 00122BCC  90 01 00 04 */	stw r0, 4(r1)
/* 80125C70 00122BD0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80125C74 00122BD4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80125C78 00122BD8  7C 7F 1B 78 */	mr r31, r3
/* 80125C7C 00122BDC  4B FF F8 C5 */	bl __ct__13PeveConditionFv
/* 80125C80 00122BE0  3C 60 80 2C */	lis r3, __vt__17PeveTimeCondition@ha
/* 80125C84 00122BE4  38 03 5F 34 */	addi r0, r3, __vt__17PeveTimeCondition@l
/* 80125C88 00122BE8  90 1F 00 00 */	stw r0, 0(r31)
/* 80125C8C 00122BEC  7F E3 FB 78 */	mr r3, r31
/* 80125C90 00122BF0  C0 22 A2 00 */	lfs f1, lbl_803EA400@sda21(r2)
/* 80125C94 00122BF4  48 00 00 1D */	bl construct__17PeveTimeConditionFf
/* 80125C98 00122BF8  7F E3 FB 78 */	mr r3, r31
/* 80125C9C 00122BFC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80125CA0 00122C00  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80125CA4 00122C04  38 21 00 18 */	addi r1, r1, 0x18
/* 80125CA8 00122C08  7C 08 03 A6 */	mtlr r0
/* 80125CAC 00122C0C  4E 80 00 20 */	blr 

.global construct__17PeveTimeConditionFf
construct__17PeveTimeConditionFf:
/* 80125CB0 00122C10  C0 02 A2 00 */	lfs f0, lbl_803EA400@sda21(r2)
/* 80125CB4 00122C14  D0 03 00 04 */	stfs f0, 4(r3)
/* 80125CB8 00122C18  D0 23 00 08 */	stfs f1, 8(r3)
/* 80125CBC 00122C1C  4E 80 00 20 */	blr 

.global update__21PeveDistanceConditionFv
update__21PeveDistanceConditionFv:
/* 80125CC0 00122C20  7C 08 02 A6 */	mflr r0
/* 80125CC4 00122C24  90 01 00 04 */	stw r0, 4(r1)
/* 80125CC8 00122C28  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 80125CCC 00122C2C  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 80125CD0 00122C30  93 C1 00 58 */	stw r30, 0x58(r1)
/* 80125CD4 00122C34  93 A1 00 54 */	stw r29, 0x54(r1)
/* 80125CD8 00122C38  3B A3 00 00 */	addi r29, r3, 0
/* 80125CDC 00122C3C  38 61 00 3C */	addi r3, r1, 0x3c
/* 80125CE0 00122C40  4B FF 71 75 */	bl __ct__9NVector3fFv
/* 80125CE4 00122C44  7C 60 1B 78 */	mr r0, r3
/* 80125CE8 00122C48  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 80125CEC 00122C4C  7C 1F 03 78 */	mr r31, r0
/* 80125CF0 00122C50  81 83 00 00 */	lwz r12, 0(r3)
/* 80125CF4 00122C54  7F E4 FB 78 */	mr r4, r31
/* 80125CF8 00122C58  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80125CFC 00122C5C  7D 88 03 A6 */	mtlr r12
/* 80125D00 00122C60  4E 80 00 21 */	blrl 
/* 80125D04 00122C64  38 61 00 30 */	addi r3, r1, 0x30
/* 80125D08 00122C68  4B FF 71 4D */	bl __ct__9NVector3fFv
/* 80125D0C 00122C6C  7C 60 1B 78 */	mr r0, r3
/* 80125D10 00122C70  80 7D 00 10 */	lwz r3, 0x10(r29)
/* 80125D14 00122C74  7C 1E 03 78 */	mr r30, r0
/* 80125D18 00122C78  81 83 00 00 */	lwz r12, 0(r3)
/* 80125D1C 00122C7C  7F C4 F3 78 */	mr r4, r30
/* 80125D20 00122C80  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80125D24 00122C84  7D 88 03 A6 */	mtlr r12
/* 80125D28 00122C88  4E 80 00 21 */	blrl 
/* 80125D2C 00122C8C  C0 02 A2 00 */	lfs f0, lbl_803EA400@sda21(r2)
/* 80125D30 00122C90  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 80125D34 00122C94  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 80125D38 00122C98  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 80125D3C 00122C9C  C0 3E 00 00 */	lfs f1, 0(r30)
/* 80125D40 00122CA0  C0 1F 00 00 */	lfs f0, 0(r31)
/* 80125D44 00122CA4  C0 9E 00 08 */	lfs f4, 8(r30)
/* 80125D48 00122CA8  EC 01 00 28 */	fsubs f0, f1, f0
/* 80125D4C 00122CAC  C0 7F 00 08 */	lfs f3, 8(r31)
/* 80125D50 00122CB0  C0 5E 00 04 */	lfs f2, 4(r30)
/* 80125D54 00122CB4  C0 3F 00 04 */	lfs f1, 4(r31)
/* 80125D58 00122CB8  EC 64 18 28 */	fsubs f3, f4, f3
/* 80125D5C 00122CBC  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 80125D60 00122CC0  EC 22 08 28 */	fsubs f1, f2, f1
/* 80125D64 00122CC4  C0 01 00 20 */	lfs f0, 0x20(r1)
/* 80125D68 00122CC8  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 80125D6C 00122CCC  D0 21 00 28 */	stfs f1, 0x28(r1)
/* 80125D70 00122CD0  D0 61 00 2C */	stfs f3, 0x2c(r1)
/* 80125D74 00122CD4  C0 21 00 24 */	lfs f1, 0x24(r1)
/* 80125D78 00122CD8  C0 01 00 28 */	lfs f0, 0x28(r1)
/* 80125D7C 00122CDC  C0 41 00 2C */	lfs f2, 0x2c(r1)
/* 80125D80 00122CE0  EC 21 00 72 */	fmuls f1, f1, f1
/* 80125D84 00122CE4  EC 00 00 32 */	fmuls f0, f0, f0
/* 80125D88 00122CE8  EC 42 00 B2 */	fmuls f2, f2, f2
/* 80125D8C 00122CEC  EC 01 00 2A */	fadds f0, f1, f0
/* 80125D90 00122CF0  EC 22 00 2A */	fadds f1, f2, f0
/* 80125D94 00122CF4  4B EE 7E AD */	bl sqrtf__3stdFf
/* 80125D98 00122CF8  C0 1D 00 08 */	lfs f0, 8(r29)
/* 80125D9C 00122CFC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80125DA0 00122D00  4C 40 13 82 */	cror 2, 0, 2
/* 80125DA4 00122D04  40 82 00 0C */	bne .L_80125DB0
/* 80125DA8 00122D08  38 00 00 01 */	li r0, 1
/* 80125DAC 00122D0C  98 1D 00 04 */	stb r0, 4(r29)
.L_80125DB0:
/* 80125DB0 00122D10  80 01 00 64 */	lwz r0, 0x64(r1)
/* 80125DB4 00122D14  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 80125DB8 00122D18  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 80125DBC 00122D1C  83 A1 00 54 */	lwz r29, 0x54(r1)
/* 80125DC0 00122D20  38 21 00 60 */	addi r1, r1, 0x60
/* 80125DC4 00122D24  7C 08 03 A6 */	mtlr r0
/* 80125DC8 00122D28  4E 80 00 20 */	blr 

.global update__24PeveComparisonYConditionFv
update__24PeveComparisonYConditionFv:
/* 80125DCC 00122D2C  7C 08 02 A6 */	mflr r0
/* 80125DD0 00122D30  90 01 00 04 */	stw r0, 4(r1)
/* 80125DD4 00122D34  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 80125DD8 00122D38  93 E1 00 34 */	stw r31, 0x34(r1)
/* 80125DDC 00122D3C  93 C1 00 30 */	stw r30, 0x30(r1)
/* 80125DE0 00122D40  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 80125DE4 00122D44  3B A3 00 00 */	addi r29, r3, 0
/* 80125DE8 00122D48  38 61 00 18 */	addi r3, r1, 0x18
/* 80125DEC 00122D4C  4B FF 70 69 */	bl __ct__9NVector3fFv
/* 80125DF0 00122D50  7C 60 1B 78 */	mr r0, r3
/* 80125DF4 00122D54  80 7D 00 08 */	lwz r3, 8(r29)
/* 80125DF8 00122D58  7C 1F 03 78 */	mr r31, r0
/* 80125DFC 00122D5C  81 83 00 00 */	lwz r12, 0(r3)
/* 80125E00 00122D60  7F E4 FB 78 */	mr r4, r31
/* 80125E04 00122D64  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80125E08 00122D68  7D 88 03 A6 */	mtlr r12
/* 80125E0C 00122D6C  4E 80 00 21 */	blrl 
/* 80125E10 00122D70  38 61 00 0C */	addi r3, r1, 0xc
/* 80125E14 00122D74  4B FF 70 41 */	bl __ct__9NVector3fFv
/* 80125E18 00122D78  7C 60 1B 78 */	mr r0, r3
/* 80125E1C 00122D7C  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 80125E20 00122D80  7C 1E 03 78 */	mr r30, r0
/* 80125E24 00122D84  81 83 00 00 */	lwz r12, 0(r3)
/* 80125E28 00122D88  7F C4 F3 78 */	mr r4, r30
/* 80125E2C 00122D8C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80125E30 00122D90  7D 88 03 A6 */	mtlr r12
/* 80125E34 00122D94  4E 80 00 21 */	blrl 
/* 80125E38 00122D98  C0 3F 00 04 */	lfs f1, 4(r31)
/* 80125E3C 00122D9C  C0 1E 00 04 */	lfs f0, 4(r30)
/* 80125E40 00122DA0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80125E44 00122DA4  40 81 00 0C */	ble .L_80125E50
/* 80125E48 00122DA8  38 00 00 01 */	li r0, 1
/* 80125E4C 00122DAC  98 1D 00 04 */	stb r0, 4(r29)
.L_80125E50:
/* 80125E50 00122DB0  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 80125E54 00122DB4  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 80125E58 00122DB8  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 80125E5C 00122DBC  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 80125E60 00122DC0  38 21 00 38 */	addi r1, r1, 0x38
/* 80125E64 00122DC4  7C 08 03 A6 */	mtlr r0
/* 80125E68 00122DC8  4E 80 00 20 */	blr 

.global reset__24PeveComparisonYConditionFv
reset__24PeveComparisonYConditionFv:
/* 80125E6C 00122DCC  38 00 00 00 */	li r0, 0
/* 80125E70 00122DD0  98 03 00 04 */	stb r0, 4(r3)
/* 80125E74 00122DD4  4E 80 00 20 */	blr 

.global isMet__20PeveBooleanConditionFv
isMet__20PeveBooleanConditionFv:
/* 80125E78 00122DD8  88 63 00 04 */	lbz r3, 4(r3)
/* 80125E7C 00122DDC  4E 80 00 20 */	blr 

.global reset__21PeveDistanceConditionFv
reset__21PeveDistanceConditionFv:
/* 80125E80 00122DE0  38 00 00 00 */	li r0, 0
/* 80125E84 00122DE4  98 03 00 04 */	stb r0, 4(r3)
/* 80125E88 00122DE8  4E 80 00 20 */	blr 

.global isMet__17PeveTimeConditionFv
isMet__17PeveTimeConditionFv:
/* 80125E8C 00122DEC  C0 23 00 04 */	lfs f1, 4(r3)
/* 80125E90 00122DF0  C0 03 00 08 */	lfs f0, 8(r3)
/* 80125E94 00122DF4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80125E98 00122DF8  4C 41 13 82 */	cror 2, 1, 2
/* 80125E9C 00122DFC  7C 00 00 26 */	mfcr r0
/* 80125EA0 00122E00  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 80125EA4 00122E04  4E 80 00 20 */	blr 

.global reset__17PeveTimeConditionFv
reset__17PeveTimeConditionFv:
/* 80125EA8 00122E08  C0 02 A2 00 */	lfs f0, lbl_803EA400@sda21(r2)
/* 80125EAC 00122E0C  D0 03 00 04 */	stfs f0, 4(r3)
/* 80125EB0 00122E10  4E 80 00 20 */	blr 

.global update__17PeveTimeConditionFv
update__17PeveTimeConditionFv:
/* 80125EB4 00122E14  80 8D 31 50 */	lwz r4, system__7NSystem@sda21(r13)
/* 80125EB8 00122E18  C0 23 00 04 */	lfs f1, 4(r3)
/* 80125EBC 00122E1C  C0 04 02 8C */	lfs f0, 0x28c(r4)
/* 80125EC0 00122E20  EC 01 00 2A */	fadds f0, f1, f0
/* 80125EC4 00122E24  D0 03 00 04 */	stfs f0, 4(r3)
/* 80125EC8 00122E28  4E 80 00 20 */	blr 

.global isMet__23PeveDependenceConditionFv
isMet__23PeveDependenceConditionFv:
/* 80125ECC 00122E2C  7C 08 02 A6 */	mflr r0
/* 80125ED0 00122E30  90 01 00 04 */	stw r0, 4(r1)
/* 80125ED4 00122E34  94 21 FF F8 */	stwu r1, -8(r1)
/* 80125ED8 00122E38  80 63 00 04 */	lwz r3, 4(r3)
/* 80125EDC 00122E3C  81 83 00 00 */	lwz r12, 0(r3)
/* 80125EE0 00122E40  81 8C 00 08 */	lwz r12, 8(r12)
/* 80125EE4 00122E44  7D 88 03 A6 */	mtlr r12
/* 80125EE8 00122E48  4E 80 00 21 */	blrl 
/* 80125EEC 00122E4C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80125EF0 00122E50  38 21 00 08 */	addi r1, r1, 8
/* 80125EF4 00122E54  7C 08 03 A6 */	mtlr r0
/* 80125EF8 00122E58  4E 80 00 20 */	blr 

.global reset__23PeveDependenceConditionFv
reset__23PeveDependenceConditionFv:
/* 80125EFC 00122E5C  4E 80 00 20 */	blr 

.global update__23PeveDependenceConditionFv
update__23PeveDependenceConditionFv:
/* 80125F00 00122E60  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C5E38:
	.asciz "peveconditions.cpp"
.balign 4
lbl_802C5E4C:
	.asciz "peveconditions"
.balign 4
lbl_802C5E5C:
	.asciz "PeveComparisonYCondition"
.balign 4
lbl_802C5E78:
	.asciz "PeveCondition"
.balign 4
lbl_802C5E88:
	.asciz "PeveBooleanCondition"
.balign 4
lbl_802C5EA0:
	.4byte __RTTI__13PeveCondition
	.4byte 0
	.4byte 0
lbl_802C5EAC:
	.4byte __RTTI__13PeveCondition
	.4byte 0
	.4byte __RTTI__20PeveBooleanCondition
	.4byte 0
	.4byte 0
.global __vt__24PeveComparisonYCondition
__vt__24PeveComparisonYCondition:
	.4byte __RTTI__24PeveComparisonYCondition
	.4byte 0
	.4byte isMet__20PeveBooleanConditionFv
	.4byte reset__24PeveComparisonYConditionFv
	.4byte update__24PeveComparisonYConditionFv
.balign 4
lbl_802C5ED4:
	.asciz "PeveDistanceCondition"
.balign 4
lbl_802C5EEC:
	.4byte __RTTI__13PeveCondition
	.4byte 0
	.4byte __RTTI__20PeveBooleanCondition
	.4byte 0
	.4byte 0
.global __vt__21PeveDistanceCondition
__vt__21PeveDistanceCondition:
	.4byte __RTTI__21PeveDistanceCondition
	.4byte 0
	.4byte isMet__20PeveBooleanConditionFv
	.4byte reset__21PeveDistanceConditionFv
	.4byte update__21PeveDistanceConditionFv
.balign 4
lbl_802C5F14:
	.asciz "PeveTimeCondition"
.balign 4
lbl_802C5F28:
	.4byte __RTTI__13PeveCondition
	.4byte 0
	.4byte 0
.global __vt__17PeveTimeCondition
__vt__17PeveTimeCondition:
	.4byte __RTTI__17PeveTimeCondition
	.4byte 0
	.4byte isMet__17PeveTimeConditionFv
	.4byte reset__17PeveTimeConditionFv
	.4byte update__17PeveTimeConditionFv
.balign 4
lbl_802C5F48:
	.asciz "PeveDependenceCondition"
.balign 4
lbl_802C5F60:
	.4byte __RTTI__13PeveCondition
	.4byte 0
	.4byte 0
.global __vt__23PeveDependenceCondition
__vt__23PeveDependenceCondition:
	.4byte __RTTI__23PeveDependenceCondition
	.4byte 0
	.4byte isMet__23PeveDependenceConditionFv
	.4byte reset__23PeveDependenceConditionFv
	.4byte update__23PeveDependenceConditionFv
.global __vt__20PeveBooleanCondition
__vt__20PeveBooleanCondition:
	.4byte __RTTI__20PeveBooleanCondition
	.4byte 0
	.4byte isMet__20PeveBooleanConditionFv
	.4byte reset__13PeveConditionFv
	.4byte update__13PeveConditionFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__13PeveCondition:
	.4byte lbl_802C5E78
	.4byte 0
__RTTI__20PeveBooleanCondition:
	.4byte lbl_802C5E88
	.4byte lbl_802C5EA0
__RTTI__24PeveComparisonYCondition:
	.4byte lbl_802C5E5C
	.4byte lbl_802C5EAC
__RTTI__21PeveDistanceCondition:
	.4byte lbl_802C5ED4
	.4byte lbl_802C5EEC
__RTTI__17PeveTimeCondition:
	.4byte lbl_802C5F14
	.4byte lbl_802C5F28
__RTTI__23PeveDependenceCondition:
	.4byte lbl_802C5F48
	.4byte lbl_802C5F60

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EA400:
	.float 0.0
