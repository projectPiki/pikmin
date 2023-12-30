.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn satisfy__22TekiPikiStateConditionFP8Creature, global
/* 80149BC0 00146B20  7C 08 02 A6 */	mflr r0
/* 80149BC4 00146B24  90 01 00 04 */	stw r0, 4(r1)
/* 80149BC8 00146B28  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80149BCC 00146B2C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80149BD0 00146B30  3B E3 00 00 */	addi r31, r3, 0
/* 80149BD4 00146B34  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 80149BD8 00146B38  2C 00 00 00 */	cmpwi r0, 0
/* 80149BDC 00146B3C  41 82 00 0C */	beq .L_80149BE8
/* 80149BE0 00146B40  38 60 00 00 */	li r3, 0
/* 80149BE4 00146B44  48 00 00 1C */	b .L_80149C00
.L_80149BE8:
/* 80149BE8 00146B48  7C 83 23 78 */	mr r3, r4
/* 80149BEC 00146B4C  4B F7 E9 69 */	bl getState__4PikiFv
/* 80149BF0 00146B50  80 1F 00 04 */	lwz r0, 4(r31)
/* 80149BF4 00146B54  7C 00 18 50 */	subf r0, r0, r3
/* 80149BF8 00146B58  7C 00 00 34 */	cntlzw r0, r0
/* 80149BFC 00146B5C  54 03 D9 7E */	srwi r3, r0, 5
.L_80149C00:
/* 80149C00 00146B60  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80149C04 00146B64  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80149C08 00146B68  38 21 00 20 */	addi r1, r1, 0x20
/* 80149C0C 00146B6C  7C 08 03 A6 */	mtlr r0
/* 80149C10 00146B70  4E 80 00 20 */	blr 
.endfn satisfy__22TekiPikiStateConditionFP8Creature

.fn satisfy__18TekiStateConditionFP8Creature, global
/* 80149C14 00146B74  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 80149C18 00146B78  2C 00 00 37 */	cmpwi r0, 0x37
/* 80149C1C 00146B7C  41 82 00 0C */	beq .L_80149C28
/* 80149C20 00146B80  38 60 00 00 */	li r3, 0
/* 80149C24 00146B84  4E 80 00 20 */	blr 
.L_80149C28:
/* 80149C28 00146B88  80 84 03 24 */	lwz r4, 0x324(r4)
/* 80149C2C 00146B8C  80 03 00 04 */	lwz r0, 4(r3)
/* 80149C30 00146B90  7C 04 00 50 */	subf r0, r4, r0
/* 80149C34 00146B94  7C 00 00 34 */	cntlzw r0, r0
/* 80149C38 00146B98  54 03 D9 7E */	srwi r3, r0, 5
/* 80149C3C 00146B9C  4E 80 00 20 */	blr 
.endfn satisfy__18TekiStateConditionFP8Creature

.fn satisfy__17TekiTypeConditionFP8Creature, global
/* 80149C40 00146BA0  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 80149C44 00146BA4  2C 00 00 37 */	cmpwi r0, 0x37
/* 80149C48 00146BA8  41 82 00 0C */	beq .L_80149C54
/* 80149C4C 00146BAC  38 60 00 00 */	li r3, 0
/* 80149C50 00146BB0  4E 80 00 20 */	blr 
.L_80149C54:
/* 80149C54 00146BB4  80 84 03 20 */	lwz r4, 0x320(r4)
/* 80149C58 00146BB8  80 03 00 04 */	lwz r0, 4(r3)
/* 80149C5C 00146BBC  7C 04 00 50 */	subf r0, r4, r0
/* 80149C60 00146BC0  7C 00 00 34 */	cntlzw r0, r0
/* 80149C64 00146BC4  54 03 D9 7E */	srwi r3, r0, 5
/* 80149C68 00146BC8  4E 80 00 20 */	blr 
.endfn satisfy__17TekiTypeConditionFP8Creature

.fn satisfy__17TekiFreeConditionFP8Creature, global
/* 80149C6C 00146BCC  7C 08 02 A6 */	mflr r0
/* 80149C70 00146BD0  7C 83 23 78 */	mr r3, r4
/* 80149C74 00146BD4  90 01 00 04 */	stw r0, 4(r1)
/* 80149C78 00146BD8  94 21 FF F8 */	stwu r1, -8(r1)
/* 80149C7C 00146BDC  81 84 00 00 */	lwz r12, 0(r4)
/* 80149C80 00146BE0  81 8C 00 9C */	lwz r12, 0x9c(r12)
/* 80149C84 00146BE4  7D 88 03 A6 */	mtlr r12
/* 80149C88 00146BE8  4E 80 00 21 */	blrl 
/* 80149C8C 00146BEC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80149C90 00146BF0  38 21 00 08 */	addi r1, r1, 8
/* 80149C94 00146BF4  7C 08 03 A6 */	mtlr r0
/* 80149C98 00146BF8  4E 80 00 20 */	blr 
.endfn satisfy__17TekiFreeConditionFP8Creature

.fn satisfy__17TekiNaviConditionFP8Creature, global
/* 80149C9C 00146BFC  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 80149CA0 00146C00  20 00 00 36 */	subfic r0, r0, 0x36
/* 80149CA4 00146C04  7C 00 00 34 */	cntlzw r0, r0
/* 80149CA8 00146C08  54 03 D9 7E */	srwi r3, r0, 5
/* 80149CAC 00146C0C  4E 80 00 20 */	blr 
.endfn satisfy__17TekiNaviConditionFP8Creature

.fn satisfy__21TekiNaviPikiConditionFP8Creature, global
/* 80149CB0 00146C10  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 80149CB4 00146C14  38 60 00 01 */	li r3, 1
/* 80149CB8 00146C18  2C 00 00 36 */	cmpwi r0, 0x36
/* 80149CBC 00146C1C  4D 82 00 20 */	beqlr 
/* 80149CC0 00146C20  2C 00 00 00 */	cmpwi r0, 0
/* 80149CC4 00146C24  4D 82 00 20 */	beqlr 
/* 80149CC8 00146C28  38 60 00 00 */	li r3, 0
/* 80149CCC 00146C2C  4E 80 00 20 */	blr 
.endfn satisfy__21TekiNaviPikiConditionFP8Creature

.fn satisfy__19TekiPelletConditionFP8Creature, global
/* 80149CD0 00146C30  7C 08 02 A6 */	mflr r0
/* 80149CD4 00146C34  90 01 00 04 */	stw r0, 4(r1)
/* 80149CD8 00146C38  94 21 FF F8 */	stwu r1, -8(r1)
/* 80149CDC 00146C3C  80 64 00 6C */	lwz r3, 0x6c(r4)
/* 80149CE0 00146C40  4B FF A5 3D */	bl isPellet__5BTekiFi
/* 80149CE4 00146C44  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80149CE8 00146C48  38 21 00 08 */	addi r1, r1, 8
/* 80149CEC 00146C4C  7C 08 03 A6 */	mtlr r0
/* 80149CF0 00146C50  4E 80 00 20 */	blr 
.endfn satisfy__19TekiPelletConditionFP8Creature

.fn satisfy__29TekiPositionDistanceConditionFP8Creature, global
/* 80149CF4 00146C54  7C 08 02 A6 */	mflr r0
/* 80149CF8 00146C58  90 01 00 04 */	stw r0, 4(r1)
/* 80149CFC 00146C5C  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 80149D00 00146C60  93 E1 00 44 */	stw r31, 0x44(r1)
/* 80149D04 00146C64  7C 7F 1B 78 */	mr r31, r3
/* 80149D08 00146C68  C0 02 A7 98 */	lfs f0, lbl_803EA998@sda21(r2)
/* 80149D0C 00146C6C  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 80149D10 00146C70  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 80149D14 00146C74  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 80149D18 00146C78  C0 24 00 94 */	lfs f1, 0x94(r4)
/* 80149D1C 00146C7C  C0 1F 00 04 */	lfs f0, 4(r31)
/* 80149D20 00146C80  C0 84 00 9C */	lfs f4, 0x9c(r4)
/* 80149D24 00146C84  EC 01 00 28 */	fsubs f0, f1, f0
/* 80149D28 00146C88  C0 7F 00 0C */	lfs f3, 0xc(r31)
/* 80149D2C 00146C8C  C0 44 00 98 */	lfs f2, 0x98(r4)
/* 80149D30 00146C90  C0 3F 00 08 */	lfs f1, 8(r31)
/* 80149D34 00146C94  EC 64 18 28 */	fsubs f3, f4, f3
/* 80149D38 00146C98  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 80149D3C 00146C9C  EC 22 08 28 */	fsubs f1, f2, f1
/* 80149D40 00146CA0  C0 01 00 28 */	lfs f0, 0x28(r1)
/* 80149D44 00146CA4  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 80149D48 00146CA8  D0 21 00 34 */	stfs f1, 0x34(r1)
/* 80149D4C 00146CAC  D0 61 00 38 */	stfs f3, 0x38(r1)
/* 80149D50 00146CB0  C0 21 00 30 */	lfs f1, 0x30(r1)
/* 80149D54 00146CB4  C0 01 00 34 */	lfs f0, 0x34(r1)
/* 80149D58 00146CB8  C0 41 00 38 */	lfs f2, 0x38(r1)
/* 80149D5C 00146CBC  EC 21 00 72 */	fmuls f1, f1, f1
/* 80149D60 00146CC0  EC 00 00 32 */	fmuls f0, f0, f0
/* 80149D64 00146CC4  EC 42 00 B2 */	fmuls f2, f2, f2
/* 80149D68 00146CC8  EC 01 00 2A */	fadds f0, f1, f0
/* 80149D6C 00146CCC  EC 22 00 2A */	fadds f1, f2, f0
/* 80149D70 00146CD0  4B EC 3E D1 */	bl sqrtf__3stdFf
/* 80149D74 00146CD4  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 80149D78 00146CD8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80149D7C 00146CDC  4C 40 13 82 */	cror 2, 0, 2
/* 80149D80 00146CE0  7C 00 00 26 */	mfcr r0
/* 80149D84 00146CE4  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 80149D88 00146CE8  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80149D8C 00146CEC  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 80149D90 00146CF0  38 21 00 48 */	addi r1, r1, 0x48
/* 80149D94 00146CF4  7C 08 03 A6 */	mtlr r0
/* 80149D98 00146CF8  4E 80 00 20 */	blr 
.endfn satisfy__29TekiPositionDistanceConditionFP8Creature

.fn satisfy__35TekiPositionCircleDistanceConditionFP8Creature, global
/* 80149D9C 00146CFC  7C 08 02 A6 */	mflr r0
/* 80149DA0 00146D00  90 01 00 04 */	stw r0, 4(r1)
/* 80149DA4 00146D04  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80149DA8 00146D08  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80149DAC 00146D0C  3B E4 00 94 */	addi r31, r4, 0x94
/* 80149DB0 00146D10  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80149DB4 00146D14  3B C3 00 00 */	addi r30, r3, 0
/* 80149DB8 00146D18  38 64 00 00 */	addi r3, r4, 0
/* 80149DBC 00146D1C  81 84 00 00 */	lwz r12, 0(r4)
/* 80149DC0 00146D20  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 80149DC4 00146D24  7D 88 03 A6 */	mtlr r12
/* 80149DC8 00146D28  4E 80 00 21 */	blrl 
/* 80149DCC 00146D2C  FC 40 08 90 */	fmr f2, f1
/* 80149DD0 00146D30  C0 3E 00 10 */	lfs f1, 0x10(r30)
/* 80149DD4 00146D34  38 9F 00 00 */	addi r4, r31, 0
/* 80149DD8 00146D38  38 7E 00 04 */	addi r3, r30, 4
/* 80149DDC 00146D3C  4B FF A4 51 */	bl calcCircleDistanceStatic__5BTekiFR8Vector3ffR8Vector3ff
/* 80149DE0 00146D40  C0 02 A7 98 */	lfs f0, lbl_803EA998@sda21(r2)
/* 80149DE4 00146D44  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80149DE8 00146D48  4C 40 13 82 */	cror 2, 0, 2
/* 80149DEC 00146D4C  7C 00 00 26 */	mfcr r0
/* 80149DF0 00146D50  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 80149DF4 00146D54  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80149DF8 00146D58  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80149DFC 00146D5C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80149E00 00146D60  38 21 00 18 */	addi r1, r1, 0x18
/* 80149E04 00146D64  7C 08 03 A6 */	mtlr r0
/* 80149E08 00146D68  4E 80 00 20 */	blr 
.endfn satisfy__35TekiPositionCircleDistanceConditionFP8Creature

.fn satisfy__35TekiPositionSphereDistanceConditionFP8Creature, global
/* 80149E0C 00146D6C  7C 08 02 A6 */	mflr r0
/* 80149E10 00146D70  90 01 00 04 */	stw r0, 4(r1)
/* 80149E14 00146D74  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80149E18 00146D78  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80149E1C 00146D7C  3B E4 00 94 */	addi r31, r4, 0x94
/* 80149E20 00146D80  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80149E24 00146D84  3B C3 00 00 */	addi r30, r3, 0
/* 80149E28 00146D88  38 64 00 00 */	addi r3, r4, 0
/* 80149E2C 00146D8C  81 84 00 00 */	lwz r12, 0(r4)
/* 80149E30 00146D90  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 80149E34 00146D94  7D 88 03 A6 */	mtlr r12
/* 80149E38 00146D98  4E 80 00 21 */	blrl 
/* 80149E3C 00146D9C  FC 40 08 90 */	fmr f2, f1
/* 80149E40 00146DA0  C0 3E 00 10 */	lfs f1, 0x10(r30)
/* 80149E44 00146DA4  38 9F 00 00 */	addi r4, r31, 0
/* 80149E48 00146DA8  38 7E 00 04 */	addi r3, r30, 4
/* 80149E4C 00146DAC  4B FF A4 45 */	bl calcSphereDistanceStatic__5BTekiFR8Vector3ffR8Vector3ff
/* 80149E50 00146DB0  C0 02 A7 98 */	lfs f0, lbl_803EA998@sda21(r2)
/* 80149E54 00146DB4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80149E58 00146DB8  4C 40 13 82 */	cror 2, 0, 2
/* 80149E5C 00146DBC  7C 00 00 26 */	mfcr r0
/* 80149E60 00146DC0  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 80149E64 00146DC4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80149E68 00146DC8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80149E6C 00146DCC  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80149E70 00146DD0  38 21 00 18 */	addi r1, r1, 0x18
/* 80149E74 00146DD4  7C 08 03 A6 */	mtlr r0
/* 80149E78 00146DD8  4E 80 00 20 */	blr 
.endfn satisfy__35TekiPositionSphereDistanceConditionFP8Creature

.fn satisfy__21TekiStickingConditionFP8Creature, global
/* 80149E7C 00146DDC  80 04 01 84 */	lwz r0, 0x184(r4)
/* 80149E80 00146DE0  7C 60 00 D0 */	neg r3, r0
/* 80149E84 00146DE4  30 03 FF FF */	addic r0, r3, -1
/* 80149E88 00146DE8  7C 60 19 10 */	subfe r3, r0, r3
/* 80149E8C 00146DEC  4E 80 00 20 */	blr 
.endfn satisfy__21TekiStickingConditionFP8Creature

.fn satisfy__24TekiRecognitionConditionFP8Creature, global
/* 80149E90 00146DF0  7C 08 02 A6 */	mflr r0
/* 80149E94 00146DF4  90 01 00 04 */	stw r0, 4(r1)
/* 80149E98 00146DF8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80149E9C 00146DFC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80149EA0 00146E00  3B E0 00 00 */	li r31, 0
/* 80149EA4 00146E04  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80149EA8 00146E08  3B DF 00 00 */	addi r30, r31, 0
/* 80149EAC 00146E0C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80149EB0 00146E10  3B A4 00 00 */	addi r29, r4, 0
/* 80149EB4 00146E14  38 7D 00 00 */	addi r3, r29, 0
/* 80149EB8 00146E18  81 9D 00 00 */	lwz r12, 0(r29)
/* 80149EBC 00146E1C  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 80149EC0 00146E20  7D 88 03 A6 */	mtlr r12
/* 80149EC4 00146E24  4E 80 00 21 */	blrl 
/* 80149EC8 00146E28  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80149ECC 00146E2C  41 82 00 24 */	beq .L_80149EF0
/* 80149ED0 00146E30  7F A3 EB 78 */	mr r3, r29
/* 80149ED4 00146E34  81 9D 00 00 */	lwz r12, 0(r29)
/* 80149ED8 00146E38  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 80149EDC 00146E3C  7D 88 03 A6 */	mtlr r12
/* 80149EE0 00146E40  4E 80 00 21 */	blrl 
/* 80149EE4 00146E44  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80149EE8 00146E48  41 82 00 08 */	beq .L_80149EF0
/* 80149EEC 00146E4C  3B C0 00 01 */	li r30, 1
.L_80149EF0:
/* 80149EF0 00146E50  57 C0 06 3F */	clrlwi. r0, r30, 0x18
/* 80149EF4 00146E54  41 82 00 24 */	beq .L_80149F18
/* 80149EF8 00146E58  7F A3 EB 78 */	mr r3, r29
/* 80149EFC 00146E5C  81 9D 00 00 */	lwz r12, 0(r29)
/* 80149F00 00146E60  81 8C 00 80 */	lwz r12, 0x80(r12)
/* 80149F04 00146E64  7D 88 03 A6 */	mtlr r12
/* 80149F08 00146E68  4E 80 00 21 */	blrl 
/* 80149F0C 00146E6C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80149F10 00146E70  40 82 00 08 */	bne .L_80149F18
/* 80149F14 00146E74  3B E0 00 01 */	li r31, 1
.L_80149F18:
/* 80149F18 00146E78  7F E3 FB 78 */	mr r3, r31
/* 80149F1C 00146E7C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80149F20 00146E80  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80149F24 00146E84  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80149F28 00146E88  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80149F2C 00146E8C  38 21 00 20 */	addi r1, r1, 0x20
/* 80149F30 00146E90  7C 08 03 A6 */	mtlr r0
/* 80149F34 00146E94  4E 80 00 20 */	blr 
.endfn satisfy__24TekiRecognitionConditionFP8Creature

.fn satisfy__28TekiCreaturePointerConditionFP8Creature, global
/* 80149F38 00146E98  80 03 00 04 */	lwz r0, 4(r3)
/* 80149F3C 00146E9C  7C 00 20 50 */	subf r0, r0, r4
/* 80149F40 00146EA0  7C 00 00 34 */	cntlzw r0, r0
/* 80149F44 00146EA4  54 03 D9 7E */	srwi r3, r0, 5
/* 80149F48 00146EA8  4E 80 00 20 */	blr 
.endfn satisfy__28TekiCreaturePointerConditionFP8Creature

.fn satisfy__21TekiDistanceConditionFP8Creature, global
/* 80149F4C 00146EAC  7C 08 02 A6 */	mflr r0
/* 80149F50 00146EB0  90 01 00 04 */	stw r0, 4(r1)
/* 80149F54 00146EB4  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 80149F58 00146EB8  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 80149F5C 00146EBC  3B E4 00 00 */	addi r31, r4, 0
/* 80149F60 00146EC0  93 C1 00 48 */	stw r30, 0x48(r1)
/* 80149F64 00146EC4  3B C3 00 00 */	addi r30, r3, 0
/* 80149F68 00146EC8  80 63 00 04 */	lwz r3, 4(r3)
/* 80149F6C 00146ECC  C0 3E 00 08 */	lfs f1, 8(r30)
/* 80149F70 00146ED0  4B FF CC 41 */	bl cullableCenter__5BTekiFR8Creaturef
/* 80149F74 00146ED4  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80149F78 00146ED8  41 82 00 0C */	beq .L_80149F84
/* 80149F7C 00146EDC  38 60 00 00 */	li r3, 0
/* 80149F80 00146EE0  48 00 00 98 */	b .L_8014A018
.L_80149F84:
/* 80149F84 00146EE4  80 7E 00 04 */	lwz r3, 4(r30)
/* 80149F88 00146EE8  38 C1 00 2C */	addi r6, r1, 0x2c
/* 80149F8C 00146EEC  C0 02 A7 98 */	lfs f0, lbl_803EA998@sda21(r2)
/* 80149F90 00146EF0  38 A1 00 28 */	addi r5, r1, 0x28
/* 80149F94 00146EF4  39 03 00 94 */	addi r8, r3, 0x94
/* 80149F98 00146EF8  D0 01 00 40 */	stfs f0, 0x40(r1)
/* 80149F9C 00146EFC  38 81 00 24 */	addi r4, r1, 0x24
/* 80149FA0 00146F00  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 80149FA4 00146F04  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 80149FA8 00146F08  C0 03 00 9C */	lfs f0, 0x9c(r3)
/* 80149FAC 00146F0C  38 61 00 38 */	addi r3, r1, 0x38
/* 80149FB0 00146F10  C0 3F 00 9C */	lfs f1, 0x9c(r31)
/* 80149FB4 00146F14  EC 01 00 28 */	fsubs f0, f1, f0
/* 80149FB8 00146F18  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 80149FBC 00146F1C  C0 3F 00 98 */	lfs f1, 0x98(r31)
/* 80149FC0 00146F20  C0 08 00 04 */	lfs f0, 4(r8)
/* 80149FC4 00146F24  EC 01 00 28 */	fsubs f0, f1, f0
/* 80149FC8 00146F28  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 80149FCC 00146F2C  C0 3F 00 94 */	lfs f1, 0x94(r31)
/* 80149FD0 00146F30  C0 08 00 00 */	lfs f0, 0(r8)
/* 80149FD4 00146F34  EC 01 00 28 */	fsubs f0, f1, f0
/* 80149FD8 00146F38  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 80149FDC 00146F3C  4B F1 36 B1 */	bl set__8Vector3fFRCfRCfRCf
/* 80149FE0 00146F40  C0 21 00 38 */	lfs f1, 0x38(r1)
/* 80149FE4 00146F44  C0 01 00 3C */	lfs f0, 0x3c(r1)
/* 80149FE8 00146F48  EC 21 00 72 */	fmuls f1, f1, f1
/* 80149FEC 00146F4C  C0 41 00 40 */	lfs f2, 0x40(r1)
/* 80149FF0 00146F50  EC 00 00 32 */	fmuls f0, f0, f0
/* 80149FF4 00146F54  EC 42 00 B2 */	fmuls f2, f2, f2
/* 80149FF8 00146F58  EC 01 00 2A */	fadds f0, f1, f0
/* 80149FFC 00146F5C  EC 22 00 2A */	fadds f1, f2, f0
/* 8014A000 00146F60  4B EC 3C 41 */	bl sqrtf__3stdFf
/* 8014A004 00146F64  C0 1E 00 08 */	lfs f0, 8(r30)
/* 8014A008 00146F68  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8014A00C 00146F6C  4C 40 13 82 */	cror 2, 0, 2
/* 8014A010 00146F70  7C 00 00 26 */	mfcr r0
/* 8014A014 00146F74  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
.L_8014A018:
/* 8014A018 00146F78  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8014A01C 00146F7C  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 8014A020 00146F80  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 8014A024 00146F84  38 21 00 50 */	addi r1, r1, 0x50
/* 8014A028 00146F88  7C 08 03 A6 */	mtlr r0
/* 8014A02C 00146F8C  4E 80 00 20 */	blr 
.endfn satisfy__21TekiDistanceConditionFP8Creature

.fn satisfy__27TekiSphereDistanceConditionFP8Creature, global
/* 8014A030 00146F90  7C 08 02 A6 */	mflr r0
/* 8014A034 00146F94  90 01 00 04 */	stw r0, 4(r1)
/* 8014A038 00146F98  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8014A03C 00146F9C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8014A040 00146FA0  3B E4 00 00 */	addi r31, r4, 0
/* 8014A044 00146FA4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8014A048 00146FA8  3B C3 00 00 */	addi r30, r3, 0
/* 8014A04C 00146FAC  80 63 00 04 */	lwz r3, 4(r3)
/* 8014A050 00146FB0  C0 3E 00 08 */	lfs f1, 8(r30)
/* 8014A054 00146FB4  4B FF CB 7D */	bl cullableSphere__5BTekiFR8Creaturef
/* 8014A058 00146FB8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8014A05C 00146FBC  41 82 00 0C */	beq .L_8014A068
/* 8014A060 00146FC0  38 60 00 00 */	li r3, 0
/* 8014A064 00146FC4  48 00 00 24 */	b .L_8014A088
.L_8014A068:
/* 8014A068 00146FC8  80 7E 00 04 */	lwz r3, 4(r30)
/* 8014A06C 00146FCC  7F E4 FB 78 */	mr r4, r31
/* 8014A070 00146FD0  4B F4 1A B1 */	bl sphereDist__FP8CreatureP8Creature
/* 8014A074 00146FD4  C0 1E 00 08 */	lfs f0, 8(r30)
/* 8014A078 00146FD8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8014A07C 00146FDC  4C 40 13 82 */	cror 2, 0, 2
/* 8014A080 00146FE0  7C 00 00 26 */	mfcr r0
/* 8014A084 00146FE4  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
.L_8014A088:
/* 8014A088 00146FE8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8014A08C 00146FEC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8014A090 00146FF0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8014A094 00146FF4  38 21 00 20 */	addi r1, r1, 0x20
/* 8014A098 00146FF8  7C 08 03 A6 */	mtlr r0
/* 8014A09C 00146FFC  4E 80 00 20 */	blr 
.endfn satisfy__27TekiSphereDistanceConditionFP8Creature

.fn satisfy__20TekiStickerConditionFP8Creature, global
/* 8014A0A0 00147000  80 84 01 84 */	lwz r4, 0x184(r4)
/* 8014A0A4 00147004  80 03 00 04 */	lwz r0, 4(r3)
/* 8014A0A8 00147008  7C 04 00 50 */	subf r0, r4, r0
/* 8014A0AC 0014700C  7C 00 00 34 */	cntlzw r0, r0
/* 8014A0B0 00147010  54 03 D9 7E */	srwi r3, r0, 5
/* 8014A0B4 00147014  4E 80 00 20 */	blr 
.endfn satisfy__20TekiStickerConditionFP8Creature

.fn satisfy__23TekiLowerRangeConditionFP8Creature, global
/* 8014A0B8 00147018  7C 08 02 A6 */	mflr r0
/* 8014A0BC 0014701C  90 01 00 04 */	stw r0, 4(r1)
/* 8014A0C0 00147020  94 21 FF 68 */	stwu r1, -0x98(r1)
/* 8014A0C4 00147024  DB E1 00 90 */	stfd f31, 0x90(r1)
/* 8014A0C8 00147028  DB C1 00 88 */	stfd f30, 0x88(r1)
/* 8014A0CC 0014702C  93 E1 00 84 */	stw r31, 0x84(r1)
/* 8014A0D0 00147030  93 C1 00 80 */	stw r30, 0x80(r1)
/* 8014A0D4 00147034  3B C4 00 00 */	addi r30, r4, 0
/* 8014A0D8 00147038  38 80 00 00 */	li r4, 0
/* 8014A0DC 0014703C  93 A1 00 7C */	stw r29, 0x7c(r1)
/* 8014A0E0 00147040  7C 7D 1B 78 */	mr r29, r3
/* 8014A0E4 00147044  83 E3 00 04 */	lwz r31, 4(r3)
/* 8014A0E8 00147048  80 7F 02 C8 */	lwz r3, 0x2c8(r31)
/* 8014A0EC 0014704C  80 63 00 34 */	lwz r3, 0x34(r3)
/* 8014A0F0 00147050  4B FD 91 21 */	bl getF__19ParaMultiParametersFi
/* 8014A0F4 00147054  80 7F 02 C4 */	lwz r3, 0x2c4(r31)
/* 8014A0F8 00147058  FF C0 08 90 */	fmr f30, f1
/* 8014A0FC 0014705C  38 80 00 01 */	li r4, 1
/* 8014A100 00147060  80 63 00 84 */	lwz r3, 0x84(r3)
/* 8014A104 00147064  4B FD 91 0D */	bl getF__19ParaMultiParametersFi
/* 8014A108 00147068  80 7F 02 C4 */	lwz r3, 0x2c4(r31)
/* 8014A10C 0014706C  FF E0 08 90 */	fmr f31, f1
/* 8014A110 00147070  38 80 00 2D */	li r4, 0x2d
/* 8014A114 00147074  80 63 00 84 */	lwz r3, 0x84(r3)
/* 8014A118 00147078  80 63 00 04 */	lwz r3, 4(r3)
/* 8014A11C 0014707C  4B FD 83 B9 */	bl "get__17ParaParameters<f>Fi"
/* 8014A120 00147080  EC 1F 07 B2 */	fmuls f0, f31, f30
/* 8014A124 00147084  80 7D 00 04 */	lwz r3, 4(r29)
/* 8014A128 00147088  7F C4 F3 78 */	mr r4, r30
/* 8014A12C 0014708C  EF C1 00 32 */	fmuls f30, f1, f0
/* 8014A130 00147090  FC 20 F0 90 */	fmr f1, f30
/* 8014A134 00147094  4B FF CA 7D */	bl cullableCenter__5BTekiFR8Creaturef
/* 8014A138 00147098  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8014A13C 0014709C  41 82 00 0C */	beq .L_8014A148
/* 8014A140 001470A0  38 60 00 00 */	li r3, 0
/* 8014A144 001470A4  48 00 00 94 */	b .L_8014A1D8
.L_8014A148:
/* 8014A148 001470A8  80 7D 00 04 */	lwz r3, 4(r29)
/* 8014A14C 001470AC  38 C1 00 54 */	addi r6, r1, 0x54
/* 8014A150 001470B0  C0 02 A7 98 */	lfs f0, lbl_803EA998@sda21(r2)
/* 8014A154 001470B4  38 A1 00 50 */	addi r5, r1, 0x50
/* 8014A158 001470B8  39 03 00 94 */	addi r8, r3, 0x94
/* 8014A15C 001470BC  D0 01 00 6C */	stfs f0, 0x6c(r1)
/* 8014A160 001470C0  38 81 00 4C */	addi r4, r1, 0x4c
/* 8014A164 001470C4  D0 01 00 68 */	stfs f0, 0x68(r1)
/* 8014A168 001470C8  D0 01 00 64 */	stfs f0, 0x64(r1)
/* 8014A16C 001470CC  C0 03 00 9C */	lfs f0, 0x9c(r3)
/* 8014A170 001470D0  38 61 00 64 */	addi r3, r1, 0x64
/* 8014A174 001470D4  C0 3E 00 9C */	lfs f1, 0x9c(r30)
/* 8014A178 001470D8  EC 01 00 28 */	fsubs f0, f1, f0
/* 8014A17C 001470DC  D0 01 00 54 */	stfs f0, 0x54(r1)
/* 8014A180 001470E0  C0 3E 00 98 */	lfs f1, 0x98(r30)
/* 8014A184 001470E4  C0 08 00 04 */	lfs f0, 4(r8)
/* 8014A188 001470E8  EC 01 00 28 */	fsubs f0, f1, f0
/* 8014A18C 001470EC  D0 01 00 50 */	stfs f0, 0x50(r1)
/* 8014A190 001470F0  C0 3E 00 94 */	lfs f1, 0x94(r30)
/* 8014A194 001470F4  C0 08 00 00 */	lfs f0, 0(r8)
/* 8014A198 001470F8  EC 01 00 28 */	fsubs f0, f1, f0
/* 8014A19C 001470FC  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 8014A1A0 00147100  4B F1 34 ED */	bl set__8Vector3fFRCfRCfRCf
/* 8014A1A4 00147104  C0 21 00 64 */	lfs f1, 0x64(r1)
/* 8014A1A8 00147108  C0 01 00 68 */	lfs f0, 0x68(r1)
/* 8014A1AC 0014710C  EC 21 00 72 */	fmuls f1, f1, f1
/* 8014A1B0 00147110  C0 41 00 6C */	lfs f2, 0x6c(r1)
/* 8014A1B4 00147114  EC 00 00 32 */	fmuls f0, f0, f0
/* 8014A1B8 00147118  EC 42 00 B2 */	fmuls f2, f2, f2
/* 8014A1BC 0014711C  EC 01 00 2A */	fadds f0, f1, f0
/* 8014A1C0 00147120  EC 22 00 2A */	fadds f1, f2, f0
/* 8014A1C4 00147124  4B EC 3A 7D */	bl sqrtf__3stdFf
/* 8014A1C8 00147128  FC 01 F0 40 */	fcmpo cr0, f1, f30
/* 8014A1CC 0014712C  4C 40 13 82 */	cror 2, 0, 2
/* 8014A1D0 00147130  7C 00 00 26 */	mfcr r0
/* 8014A1D4 00147134  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
.L_8014A1D8:
/* 8014A1D8 00147138  80 01 00 9C */	lwz r0, 0x9c(r1)
/* 8014A1DC 0014713C  CB E1 00 90 */	lfd f31, 0x90(r1)
/* 8014A1E0 00147140  CB C1 00 88 */	lfd f30, 0x88(r1)
/* 8014A1E4 00147144  83 E1 00 84 */	lwz r31, 0x84(r1)
/* 8014A1E8 00147148  83 C1 00 80 */	lwz r30, 0x80(r1)
/* 8014A1EC 0014714C  83 A1 00 7C */	lwz r29, 0x7c(r1)
/* 8014A1F0 00147150  38 21 00 98 */	addi r1, r1, 0x98
/* 8014A1F4 00147154  7C 08 03 A6 */	mtlr r0
/* 8014A1F8 00147158  4E 80 00 20 */	blr 
.endfn satisfy__23TekiLowerRangeConditionFP8Creature

.fn satisfy__23TekiAttackableConditionFP8Creature, global
/* 8014A1FC 0014715C  7C 08 02 A6 */	mflr r0
/* 8014A200 00147160  90 01 00 04 */	stw r0, 4(r1)
/* 8014A204 00147164  94 21 FF F8 */	stwu r1, -8(r1)
/* 8014A208 00147168  80 63 00 04 */	lwz r3, 4(r3)
/* 8014A20C 0014716C  4B FF CF 41 */	bl attackableCreature__5BTekiFR8Creature
/* 8014A210 00147170  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8014A214 00147174  38 21 00 08 */	addi r1, r1, 8
/* 8014A218 00147178  7C 08 03 A6 */	mtlr r0
/* 8014A21C 0014717C  4E 80 00 20 */	blr 
.endfn satisfy__23TekiAttackableConditionFP8Creature

.fn satisfy__20TekiVisibleConditionFP8Creature, global
/* 8014A220 00147180  7C 08 02 A6 */	mflr r0
/* 8014A224 00147184  90 01 00 04 */	stw r0, 4(r1)
/* 8014A228 00147188  94 21 FF F8 */	stwu r1, -8(r1)
/* 8014A22C 0014718C  80 63 00 04 */	lwz r3, 4(r3)
/* 8014A230 00147190  4B FF CA E5 */	bl visibleCreature__5BTekiFR8Creature
/* 8014A234 00147194  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8014A238 00147198  38 21 00 08 */	addi r1, r1, 8
/* 8014A23C 0014719C  7C 08 03 A6 */	mtlr r0
/* 8014A240 001471A0  4E 80 00 20 */	blr 
.endfn satisfy__20TekiVisibleConditionFP8Creature

.fn satisfy__26TekiVisibleHeightConditionFP8Creature, global
/* 8014A244 001471A4  80 A3 00 04 */	lwz r5, 4(r3)
/* 8014A248 001471A8  C0 24 00 98 */	lfs f1, 0x98(r4)
/* 8014A24C 001471AC  80 65 02 C4 */	lwz r3, 0x2c4(r5)
/* 8014A250 001471B0  C0 05 00 98 */	lfs f0, 0x98(r5)
/* 8014A254 001471B4  80 63 00 84 */	lwz r3, 0x84(r3)
/* 8014A258 001471B8  80 63 00 04 */	lwz r3, 4(r3)
/* 8014A25C 001471BC  80 63 00 00 */	lwz r3, 0(r3)
/* 8014A260 001471C0  C0 43 00 70 */	lfs f2, 0x70(r3)
/* 8014A264 001471C4  EC 02 00 2A */	fadds f0, f2, f0
/* 8014A268 001471C8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8014A26C 001471CC  40 81 00 0C */	ble .L_8014A278
/* 8014A270 001471D0  38 60 00 00 */	li r3, 0
/* 8014A274 001471D4  4E 80 00 20 */	blr 
.L_8014A278:
/* 8014A278 001471D8  38 60 00 01 */	li r3, 1
/* 8014A27C 001471DC  4E 80 00 20 */	blr 
.endfn satisfy__26TekiVisibleHeightConditionFP8Creature

.fn satisfy__18TekiLowerConditionFP8Creature, global
/* 8014A280 001471E0  7C 08 02 A6 */	mflr r0
/* 8014A284 001471E4  3C A0 80 2B */	lis r5, __vt__9Condition@ha
/* 8014A288 001471E8  90 01 00 04 */	stw r0, 4(r1)
/* 8014A28C 001471EC  39 45 F0 98 */	addi r10, r5, __vt__9Condition@l
/* 8014A290 001471F0  3C A0 80 2C */	lis r5, __vt__13TekiCondition@ha
/* 8014A294 001471F4  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 8014A298 001471F8  39 25 69 64 */	addi r9, r5, __vt__13TekiCondition@l
/* 8014A29C 001471FC  3C C0 80 2D */	lis r6, __vt__20TekiStickerCondition@ha
/* 8014A2A0 00147200  81 63 00 04 */	lwz r11, 4(r3)
/* 8014A2A4 00147204  3C A0 80 2C */	lis r5, __vt__16TekiNotCondition@ha
/* 8014A2A8 00147208  38 05 68 90 */	addi r0, r5, __vt__16TekiNotCondition@l
/* 8014A2AC 0014720C  91 41 00 5C */	stw r10, 0x5c(r1)
/* 8014A2B0 00147210  3C E0 80 2D */	lis r7, __vt__23TekiLowerRangeCondition@ha
/* 8014A2B4 00147214  38 C6 D5 B4 */	addi r6, r6, __vt__20TekiStickerCondition@l
/* 8014A2B8 00147218  91 41 00 64 */	stw r10, 0x64(r1)
/* 8014A2BC 0014721C  39 01 00 5C */	addi r8, r1, 0x5c
/* 8014A2C0 00147220  3C A0 80 2C */	lis r5, __vt__16TekiAndCondition@ha
/* 8014A2C4 00147224  91 21 00 5C */	stw r9, 0x5c(r1)
/* 8014A2C8 00147228  38 E7 D5 7C */	addi r7, r7, __vt__23TekiLowerRangeCondition@l
/* 8014A2CC 0014722C  90 C1 00 5C */	stw r6, 0x5c(r1)
/* 8014A2D0 00147230  38 C5 68 5C */	addi r6, r5, __vt__16TekiAndCondition@l
/* 8014A2D4 00147234  38 A1 00 6C */	addi r5, r1, 0x6c
/* 8014A2D8 00147238  91 21 00 64 */	stw r9, 0x64(r1)
/* 8014A2DC 0014723C  90 01 00 64 */	stw r0, 0x64(r1)
/* 8014A2E0 00147240  38 01 00 64 */	addi r0, r1, 0x64
/* 8014A2E4 00147244  91 61 00 60 */	stw r11, 0x60(r1)
/* 8014A2E8 00147248  39 61 00 74 */	addi r11, r1, 0x74
/* 8014A2EC 0014724C  91 01 00 68 */	stw r8, 0x68(r1)
/* 8014A2F0 00147250  81 03 00 04 */	lwz r8, 4(r3)
/* 8014A2F4 00147254  7D 63 5B 78 */	mr r3, r11
/* 8014A2F8 00147258  91 41 00 74 */	stw r10, 0x74(r1)
/* 8014A2FC 0014725C  91 41 00 6C */	stw r10, 0x6c(r1)
/* 8014A300 00147260  91 21 00 74 */	stw r9, 0x74(r1)
/* 8014A304 00147264  91 21 00 6C */	stw r9, 0x6c(r1)
/* 8014A308 00147268  90 C1 00 74 */	stw r6, 0x74(r1)
/* 8014A30C 0014726C  90 E1 00 6C */	stw r7, 0x6c(r1)
/* 8014A310 00147270  90 A1 00 78 */	stw r5, 0x78(r1)
/* 8014A314 00147274  91 01 00 70 */	stw r8, 0x70(r1)
/* 8014A318 00147278  90 01 00 7C */	stw r0, 0x7c(r1)
/* 8014A31C 0014727C  81 8B 00 00 */	lwz r12, 0(r11)
/* 8014A320 00147280  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014A324 00147284  7D 88 03 A6 */	mtlr r12
/* 8014A328 00147288  4E 80 00 21 */	blrl 
/* 8014A32C 0014728C  80 01 00 84 */	lwz r0, 0x84(r1)
/* 8014A330 00147290  38 21 00 80 */	addi r1, r1, 0x80
/* 8014A334 00147294  7C 08 03 A6 */	mtlr r0
/* 8014A338 00147298  4E 80 00 20 */	blr 
.endfn satisfy__18TekiLowerConditionFP8Creature

.fn satisfy__18TekiAngleConditionFP8Creature, global
/* 8014A33C 0014729C  7C 08 02 A6 */	mflr r0
/* 8014A340 001472A0  38 84 00 94 */	addi r4, r4, 0x94
/* 8014A344 001472A4  90 01 00 04 */	stw r0, 4(r1)
/* 8014A348 001472A8  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8014A34C 001472AC  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8014A350 001472B0  3B E3 00 00 */	addi r31, r3, 0
/* 8014A354 001472B4  80 63 00 04 */	lwz r3, 4(r3)
/* 8014A358 001472B8  4B FF CF A9 */	bl calcTargetAngle__5BTekiFR8Vector3f
/* 8014A35C 001472BC  C0 7F 00 08 */	lfs f3, 8(r31)
/* 8014A360 001472C0  C0 42 A7 9C */	lfs f2, lbl_803EA99C@sda21(r2)
/* 8014A364 001472C4  C0 0D E3 58 */	lfs f0, radianPerDegree__6NMathF@sda21(r13)
/* 8014A368 001472C8  EC 43 00 B2 */	fmuls f2, f3, f2
/* 8014A36C 001472CC  EC 02 00 32 */	fmuls f0, f2, f0
/* 8014A370 001472D0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8014A374 001472D4  40 81 00 0C */	ble .L_8014A380
/* 8014A378 001472D8  38 60 00 00 */	li r3, 0
/* 8014A37C 001472DC  48 00 00 08 */	b .L_8014A384
.L_8014A380:
/* 8014A380 001472E0  38 60 00 01 */	li r3, 1
.L_8014A384:
/* 8014A384 001472E4  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8014A388 001472E8  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8014A38C 001472EC  38 21 00 28 */	addi r1, r1, 0x28
/* 8014A390 001472F0  7C 08 03 A6 */	mtlr r0
/* 8014A394 001472F4  4E 80 00 20 */	blr 
.endfn satisfy__18TekiAngleConditionFP8Creature

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802CD370, local
	.asciz "tekiconditions.cpp"
.endobj lbl_802CD370
.balign 4
.obj lbl_802CD384, local
	.asciz "tekiconditions"
.endobj lbl_802CD384
.balign 4
.obj lbl_802CD394, local
	.asciz "TekiAngleCondition"
.endobj lbl_802CD394
.balign 4
.obj lbl_802CD3A8, local
	.asciz "Condition"
.endobj lbl_802CD3A8
.balign 4
.obj lbl_802CD3B4, local
	.asciz "TekiCondition"
.endobj lbl_802CD3B4
.balign 4
.obj lbl_802CD3C4, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.endobj lbl_802CD3C4
.balign 4
.obj lbl_802CD3D0, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD3D0
.balign 4
.obj __vt__18TekiAngleCondition, global
	.4byte __RTTI__18TekiAngleCondition
	.4byte 0
	.4byte satisfy__18TekiAngleConditionFP8Creature
.endobj __vt__18TekiAngleCondition
.balign 4
.obj lbl_802CD3F0, local
	.asciz "TekiAndCondition"
.endobj lbl_802CD3F0
.balign 4
.obj lbl_802CD404, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD404
.balign 4
.skip 0xC # compiler padding
.balign 4
.obj lbl_802CD424, local
	.asciz "TekiNotCondition"
.endobj lbl_802CD424
.balign 4
.obj lbl_802CD438, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD438
.balign 4
.skip 0x24 # compiler padding
.balign 4
.obj lbl_802CD470, local
	.asciz "TekiLowerCondition"
.endobj lbl_802CD470
.balign 4
.obj lbl_802CD484, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD484
.balign 4
.obj __vt__18TekiLowerCondition, global
	.4byte __RTTI__18TekiLowerCondition
	.4byte 0
	.4byte satisfy__18TekiLowerConditionFP8Creature
.endobj __vt__18TekiLowerCondition
.balign 4
.obj lbl_802CD4A4, local
	.asciz "TekiVisibleHeightCondition"
.endobj lbl_802CD4A4
.balign 4
.obj lbl_802CD4C0, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD4C0
.balign 4
.obj __vt__26TekiVisibleHeightCondition, global
	.4byte __RTTI__26TekiVisibleHeightCondition
	.4byte 0
	.4byte satisfy__26TekiVisibleHeightConditionFP8Creature
.endobj __vt__26TekiVisibleHeightCondition
.balign 4
.obj lbl_802CD4E0, local
	.asciz "TekiVisibleCondition"
.endobj lbl_802CD4E0
.balign 4
.obj lbl_802CD4F8, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD4F8
.balign 4
.obj __vt__20TekiVisibleCondition, global
	.4byte __RTTI__20TekiVisibleCondition
	.4byte 0
	.4byte satisfy__20TekiVisibleConditionFP8Creature
.endobj __vt__20TekiVisibleCondition
.balign 4
.obj lbl_802CD518, local
	.asciz "TekiAttackableCondition"
.endobj lbl_802CD518
.balign 4
.obj lbl_802CD530, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD530
.balign 4
.obj __vt__23TekiAttackableCondition, global
	.4byte __RTTI__23TekiAttackableCondition
	.4byte 0
	.4byte satisfy__23TekiAttackableConditionFP8Creature
.endobj __vt__23TekiAttackableCondition
.balign 4
.obj lbl_802CD550, local
	.asciz "TekiLowerRangeCondition"
.endobj lbl_802CD550
.balign 4
.obj lbl_802CD568, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD568
.balign 4
.obj __vt__23TekiLowerRangeCondition, global
	.4byte __RTTI__23TekiLowerRangeCondition
	.4byte 0
	.4byte satisfy__23TekiLowerRangeConditionFP8Creature
.endobj __vt__23TekiLowerRangeCondition
.balign 4
.obj lbl_802CD588, local
	.asciz "TekiStickerCondition"
.endobj lbl_802CD588
.balign 4
.obj lbl_802CD5A0, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD5A0
.balign 4
.obj __vt__20TekiStickerCondition, global
	.4byte __RTTI__20TekiStickerCondition
	.4byte 0
	.4byte satisfy__20TekiStickerConditionFP8Creature
.endobj __vt__20TekiStickerCondition
.balign 4
.obj lbl_802CD5C0, local
	.asciz "TekiSphereDistanceCondition"
.endobj lbl_802CD5C0
.balign 4
.obj lbl_802CD5DC, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD5DC
.balign 4
.obj __vt__27TekiSphereDistanceCondition, global
	.4byte __RTTI__27TekiSphereDistanceCondition
	.4byte 0
	.4byte satisfy__27TekiSphereDistanceConditionFP8Creature
.endobj __vt__27TekiSphereDistanceCondition
.balign 4
.obj lbl_802CD5FC, local
	.asciz "TekiDistanceCondition"
.endobj lbl_802CD5FC
.balign 4
.obj lbl_802CD614, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD614
.balign 4
.obj __vt__21TekiDistanceCondition, global
	.4byte __RTTI__21TekiDistanceCondition
	.4byte 0
	.4byte satisfy__21TekiDistanceConditionFP8Creature
.endobj __vt__21TekiDistanceCondition
.balign 4
.obj lbl_802CD634, local
	.asciz "TekiCreaturePointerCondition"
.endobj lbl_802CD634
.balign 4
.obj lbl_802CD654, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD654
.balign 4
.obj __vt__28TekiCreaturePointerCondition, global
	.4byte __RTTI__28TekiCreaturePointerCondition
	.4byte 0
	.4byte satisfy__28TekiCreaturePointerConditionFP8Creature
.endobj __vt__28TekiCreaturePointerCondition
.balign 4
.obj lbl_802CD674, local
	.asciz "TekiRecognitionCondition"
.endobj lbl_802CD674
.balign 4
.obj lbl_802CD690, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD690
.balign 4
.obj __vt__24TekiRecognitionCondition, global
	.4byte __RTTI__24TekiRecognitionCondition
	.4byte 0
	.4byte satisfy__24TekiRecognitionConditionFP8Creature
.endobj __vt__24TekiRecognitionCondition
.balign 4
.obj lbl_802CD6B0, local
	.asciz "TekiStickingCondition"
.endobj lbl_802CD6B0
.balign 4
.obj lbl_802CD6C8, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD6C8
.balign 4
.obj __vt__21TekiStickingCondition, global
	.4byte __RTTI__21TekiStickingCondition
	.4byte 0
	.4byte satisfy__21TekiStickingConditionFP8Creature
.endobj __vt__21TekiStickingCondition
.balign 4
.obj lbl_802CD6E8, local
	.asciz "TekiPositionSphereDistanceCondition"
.endobj lbl_802CD6E8
.balign 4
.obj lbl_802CD70C, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD70C
.balign 4
.obj __vt__35TekiPositionSphereDistanceCondition, global
	.4byte __RTTI__35TekiPositionSphereDistanceCondition
	.4byte 0
	.4byte satisfy__35TekiPositionSphereDistanceConditionFP8Creature
.endobj __vt__35TekiPositionSphereDistanceCondition
.balign 4
.obj lbl_802CD72C, local
	.asciz "TekiPositionCircleDistanceCondition"
.endobj lbl_802CD72C
.balign 4
.obj lbl_802CD750, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD750
.balign 4
.obj __vt__35TekiPositionCircleDistanceCondition, global
	.4byte __RTTI__35TekiPositionCircleDistanceCondition
	.4byte 0
	.4byte satisfy__35TekiPositionCircleDistanceConditionFP8Creature
.endobj __vt__35TekiPositionCircleDistanceCondition
.balign 4
.obj lbl_802CD770, local
	.asciz "TekiPositionDistanceCondition"
.endobj lbl_802CD770
.balign 4
.obj lbl_802CD790, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD790
.balign 4
.obj __vt__29TekiPositionDistanceCondition, global
	.4byte __RTTI__29TekiPositionDistanceCondition
	.4byte 0
	.4byte satisfy__29TekiPositionDistanceConditionFP8Creature
.endobj __vt__29TekiPositionDistanceCondition
.balign 4
.obj lbl_802CD7B0, local
	.asciz "TekiPelletCondition"
.endobj lbl_802CD7B0
.balign 4
.obj lbl_802CD7C4, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD7C4
.balign 4
.obj __vt__19TekiPelletCondition, global
	.4byte __RTTI__19TekiPelletCondition
	.4byte 0
	.4byte satisfy__19TekiPelletConditionFP8Creature
.endobj __vt__19TekiPelletCondition
.balign 4
.obj lbl_802CD7E4, local
	.asciz "TekiNaviPikiCondition"
.endobj lbl_802CD7E4
.balign 4
.obj lbl_802CD7FC, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD7FC
.balign 4
.obj __vt__21TekiNaviPikiCondition, global
	.4byte __RTTI__21TekiNaviPikiCondition
	.4byte 0
	.4byte satisfy__21TekiNaviPikiConditionFP8Creature
.endobj __vt__21TekiNaviPikiCondition
.balign 4
.obj lbl_802CD81C, local
	.asciz "TekiNaviCondition"
.endobj lbl_802CD81C
.balign 4
.obj lbl_802CD830, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD830
.balign 4
.obj __vt__17TekiNaviCondition, global
	.4byte __RTTI__17TekiNaviCondition
	.4byte 0
	.4byte satisfy__17TekiNaviConditionFP8Creature
.endobj __vt__17TekiNaviCondition
.balign 4
.obj lbl_802CD850, local
	.asciz "TekiFreeCondition"
.endobj lbl_802CD850
.balign 4
.obj lbl_802CD864, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD864
.balign 4
.obj __vt__17TekiFreeCondition, global
	.4byte __RTTI__17TekiFreeCondition
	.4byte 0
	.4byte satisfy__17TekiFreeConditionFP8Creature
.endobj __vt__17TekiFreeCondition
.balign 4
.obj lbl_802CD884, local
	.asciz "TekiTypeCondition"
.endobj lbl_802CD884
.balign 4
.obj lbl_802CD898, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD898
.balign 4
.obj __vt__17TekiTypeCondition, global
	.4byte __RTTI__17TekiTypeCondition
	.4byte 0
	.4byte satisfy__17TekiTypeConditionFP8Creature
.endobj __vt__17TekiTypeCondition
.balign 4
.obj lbl_802CD8B8, local
	.asciz "TekiStateCondition"
.endobj lbl_802CD8B8
.balign 4
.obj lbl_802CD8CC, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD8CC
.balign 4
.obj __vt__18TekiStateCondition, global
	.4byte __RTTI__18TekiStateCondition
	.4byte 0
	.4byte satisfy__18TekiStateConditionFP8Creature
.endobj __vt__18TekiStateCondition
.balign 4
.obj lbl_802CD8EC, local
	.asciz "TekiPikiStateCondition"
.endobj lbl_802CD8EC
.balign 4
.obj lbl_802CD904, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802CD904
.balign 4
.obj __vt__22TekiPikiStateCondition, global
	.4byte __RTTI__22TekiPikiStateCondition
	.4byte 0
	.4byte satisfy__22TekiPikiStateConditionFP8Creature
.endobj __vt__22TekiPikiStateCondition

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__9Condition, local
	.4byte lbl_802CD3A8
	.4byte 0
.endobj __RTTI__9Condition
.balign 4
.obj __RTTI__13TekiCondition, local
	.4byte lbl_802CD3B4
	.4byte lbl_802CD3C4
.endobj __RTTI__13TekiCondition
.balign 4
.obj __RTTI__18TekiAngleCondition, local
	.4byte lbl_802CD394
	.4byte lbl_802CD3D0
.endobj __RTTI__18TekiAngleCondition
.balign 4
.obj __RTTI__18TekiLowerCondition, local
	.4byte lbl_802CD470
	.4byte lbl_802CD484
.endobj __RTTI__18TekiLowerCondition
.balign 4
.obj __RTTI__26TekiVisibleHeightCondition, local
	.4byte lbl_802CD4A4
	.4byte lbl_802CD4C0
.endobj __RTTI__26TekiVisibleHeightCondition
.balign 4
.obj __RTTI__20TekiVisibleCondition, local
	.4byte lbl_802CD4E0
	.4byte lbl_802CD4F8
.endobj __RTTI__20TekiVisibleCondition
.balign 4
.obj __RTTI__23TekiAttackableCondition, local
	.4byte lbl_802CD518
	.4byte lbl_802CD530
.endobj __RTTI__23TekiAttackableCondition
.balign 4
.obj __RTTI__23TekiLowerRangeCondition, local
	.4byte lbl_802CD550
	.4byte lbl_802CD568
.endobj __RTTI__23TekiLowerRangeCondition
.balign 4
.obj __RTTI__20TekiStickerCondition, local
	.4byte lbl_802CD588
	.4byte lbl_802CD5A0
.endobj __RTTI__20TekiStickerCondition
.balign 4
.obj __RTTI__27TekiSphereDistanceCondition, local
	.4byte lbl_802CD5C0
	.4byte lbl_802CD5DC
.endobj __RTTI__27TekiSphereDistanceCondition
.balign 4
.obj __RTTI__21TekiDistanceCondition, local
	.4byte lbl_802CD5FC
	.4byte lbl_802CD614
.endobj __RTTI__21TekiDistanceCondition
.balign 4
.obj __RTTI__28TekiCreaturePointerCondition, local
	.4byte lbl_802CD634
	.4byte lbl_802CD654
.endobj __RTTI__28TekiCreaturePointerCondition
.balign 4
.obj __RTTI__24TekiRecognitionCondition, local
	.4byte lbl_802CD674
	.4byte lbl_802CD690
.endobj __RTTI__24TekiRecognitionCondition
.balign 4
.obj __RTTI__21TekiStickingCondition, local
	.4byte lbl_802CD6B0
	.4byte lbl_802CD6C8
.endobj __RTTI__21TekiStickingCondition
.balign 4
.obj __RTTI__35TekiPositionSphereDistanceCondition, local
	.4byte lbl_802CD6E8
	.4byte lbl_802CD70C
.endobj __RTTI__35TekiPositionSphereDistanceCondition
.balign 4
.obj __RTTI__35TekiPositionCircleDistanceCondition, local
	.4byte lbl_802CD72C
	.4byte lbl_802CD750
.endobj __RTTI__35TekiPositionCircleDistanceCondition
.balign 4
.obj __RTTI__29TekiPositionDistanceCondition, local
	.4byte lbl_802CD770
	.4byte lbl_802CD790
.endobj __RTTI__29TekiPositionDistanceCondition
.balign 4
.obj __RTTI__19TekiPelletCondition, local
	.4byte lbl_802CD7B0
	.4byte lbl_802CD7C4
.endobj __RTTI__19TekiPelletCondition
.balign 4
.obj __RTTI__21TekiNaviPikiCondition, local
	.4byte lbl_802CD7E4
	.4byte lbl_802CD7FC
.endobj __RTTI__21TekiNaviPikiCondition
.balign 4
.obj __RTTI__17TekiNaviCondition, local
	.4byte lbl_802CD81C
	.4byte lbl_802CD830
.endobj __RTTI__17TekiNaviCondition
.balign 4
.obj __RTTI__17TekiFreeCondition, local
	.4byte lbl_802CD850
	.4byte lbl_802CD864
.endobj __RTTI__17TekiFreeCondition
.balign 4
.obj __RTTI__17TekiTypeCondition, local
	.4byte lbl_802CD884
	.4byte lbl_802CD898
.endobj __RTTI__17TekiTypeCondition
.balign 4
.obj __RTTI__18TekiStateCondition, local
	.4byte lbl_802CD8B8
	.4byte lbl_802CD8CC
.endobj __RTTI__18TekiStateCondition
.balign 4
.obj __RTTI__22TekiPikiStateCondition, local
	.4byte lbl_802CD8EC
	.4byte lbl_802CD904
.endobj __RTTI__22TekiPikiStateCondition

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA998, local
	.float 0.0
.endobj lbl_803EA998
.balign 4
.obj lbl_803EA99C, local
	.float 0.5
.endobj lbl_803EA99C
