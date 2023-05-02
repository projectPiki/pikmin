.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__7ActPickFP4Piki
__ct__7ActPickFP4Piki:
/* 800A79F8 000A4958  7C 08 02 A6 */	mflr r0
/* 800A79FC 000A495C  38 A0 00 01 */	li r5, 1
/* 800A7A00 000A4960  90 01 00 04 */	stw r0, 4(r1)
/* 800A7A04 000A4964  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800A7A08 000A4968  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800A7A0C 000A496C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800A7A10 000A4970  90 61 00 08 */	stw r3, 8(r1)
/* 800A7A14 000A4974  80 61 00 08 */	lwz r3, 8(r1)
/* 800A7A18 000A4978  48 01 C3 B9 */	bl __ct__6ActionFP4Pikib
/* 800A7A1C 000A497C  3C 60 80 2B */	lis r3, __vt__19PaniAnimKeyListener@ha
/* 800A7A20 000A4980  83 C1 00 08 */	lwz r30, 8(r1)
/* 800A7A24 000A4984  38 03 DB 94 */	addi r0, r3, __vt__19PaniAnimKeyListener@l
/* 800A7A28 000A4988  3C 60 80 2B */	lis r3, __vt__7ActPick@ha
/* 800A7A2C 000A498C  90 1E 00 14 */	stw r0, 0x14(r30)
/* 800A7A30 000A4990  38 63 52 7C */	addi r3, r3, __vt__7ActPick@l
/* 800A7A34 000A4994  90 7E 00 00 */	stw r3, 0(r30)
/* 800A7A38 000A4998  38 03 00 64 */	addi r0, r3, 0x64
/* 800A7A3C 000A499C  3B E0 00 00 */	li r31, 0
/* 800A7A40 000A49A0  90 1E 00 14 */	stw r0, 0x14(r30)
/* 800A7A44 000A49A4  93 FE 00 18 */	stw r31, 0x18(r30)
/* 800A7A48 000A49A8  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800A7A4C 000A49AC  28 03 00 00 */	cmplwi r3, 0
/* 800A7A50 000A49B0  41 82 00 0C */	beq .L_800A7A5C
/* 800A7A54 000A49B4  48 03 C9 19 */	bl subCnt__12RefCountableFv
/* 800A7A58 000A49B8  93 FE 00 18 */	stw r31, 0x18(r30)
.L_800A7A5C:
/* 800A7A5C 000A49BC  80 61 00 08 */	lwz r3, 8(r1)
/* 800A7A60 000A49C0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800A7A64 000A49C4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800A7A68 000A49C8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800A7A6C 000A49CC  38 21 00 18 */	addi r1, r1, 0x18
/* 800A7A70 000A49D0  7C 08 03 A6 */	mtlr r0
/* 800A7A74 000A49D4  4E 80 00 20 */	blr 

.global initialise__Q27ActPick11InitialiserFP6Action
initialise__Q27ActPick11InitialiserFP6Action:
/* 800A7A78 000A49D8  4E 80 00 20 */	blr 

.global animationKeyUpdated__7ActPickFR16PaniAnimKeyEvent
animationKeyUpdated__7ActPickFR16PaniAnimKeyEvent:
/* 800A7A7C 000A49DC  7C 08 02 A6 */	mflr r0
/* 800A7A80 000A49E0  90 01 00 04 */	stw r0, 4(r1)
/* 800A7A84 000A49E4  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800A7A88 000A49E8  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800A7A8C 000A49EC  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800A7A90 000A49F0  3B C3 00 00 */	addi r30, r3, 0
/* 800A7A94 000A49F4  80 04 00 00 */	lwz r0, 0(r4)
/* 800A7A98 000A49F8  2C 00 00 01 */	cmpwi r0, 1
/* 800A7A9C 000A49FC  41 82 00 14 */	beq .L_800A7AB0
/* 800A7AA0 000A4A00  40 80 00 98 */	bge .L_800A7B38
/* 800A7AA4 000A4A04  2C 00 00 00 */	cmpwi r0, 0
/* 800A7AA8 000A4A08  40 80 00 88 */	bge .L_800A7B30
/* 800A7AAC 000A4A0C  48 00 00 8C */	b .L_800A7B38
.L_800A7AB0:
/* 800A7AB0 000A4A10  80 1E 00 18 */	lwz r0, 0x18(r30)
/* 800A7AB4 000A4A14  28 00 00 00 */	cmplwi r0, 0
/* 800A7AB8 000A4A18  7C 1F 03 78 */	mr r31, r0
/* 800A7ABC 000A4A1C  41 82 00 7C */	beq .L_800A7B38
/* 800A7AC0 000A4A20  7F E3 FB 78 */	mr r3, r31
/* 800A7AC4 000A4A24  81 9F 00 00 */	lwz r12, 0(r31)
/* 800A7AC8 000A4A28  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800A7ACC 000A4A2C  7D 88 03 A6 */	mtlr r12
/* 800A7AD0 000A4A30  4E 80 00 21 */	blrl 
/* 800A7AD4 000A4A34  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800A7AD8 000A4A38  41 82 00 60 */	beq .L_800A7B38
/* 800A7ADC 000A4A3C  7F E3 FB 78 */	mr r3, r31
/* 800A7AE0 000A4A40  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800A7AE4 000A4A44  4B FE 53 99 */	bl qdist2__FP8CreatureP8Creature
/* 800A7AE8 000A4A48  C0 02 8E 60 */	lfs f0, lbl_803E9060@sda21(r2)
/* 800A7AEC 000A4A4C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800A7AF0 000A4A50  40 80 00 48 */	bge .L_800A7B38
/* 800A7AF4 000A4A54  3C 60 80 2B */	lis r3, __vt__11Interaction@ha
/* 800A7AF8 000A4A58  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 800A7AFC 000A4A5C  38 03 CF 9C */	addi r0, r3, __vt__11Interaction@l
/* 800A7B00 000A4A60  90 01 00 18 */	stw r0, 0x18(r1)
/* 800A7B04 000A4A64  3C 60 80 2B */	lis r3, __vt__12InteractGrab@ha
/* 800A7B08 000A4A68  38 03 D1 D4 */	addi r0, r3, __vt__12InteractGrab@l
/* 800A7B0C 000A4A6C  90 A1 00 1C */	stw r5, 0x1c(r1)
/* 800A7B10 000A4A70  38 81 00 18 */	addi r4, r1, 0x18
/* 800A7B14 000A4A74  38 7F 00 00 */	addi r3, r31, 0
/* 800A7B18 000A4A78  90 01 00 18 */	stw r0, 0x18(r1)
/* 800A7B1C 000A4A7C  81 9F 00 00 */	lwz r12, 0(r31)
/* 800A7B20 000A4A80  81 8C 00 A0 */	lwz r12, 0xa0(r12)
/* 800A7B24 000A4A84  7D 88 03 A6 */	mtlr r12
/* 800A7B28 000A4A88  4E 80 00 21 */	blrl 
/* 800A7B2C 000A4A8C  48 00 00 0C */	b .L_800A7B38
.L_800A7B30:
/* 800A7B30 000A4A90  38 00 00 01 */	li r0, 1
/* 800A7B34 000A4A94  98 1E 00 1C */	stb r0, 0x1c(r30)
.L_800A7B38:
/* 800A7B38 000A4A98  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800A7B3C 000A4A9C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800A7B40 000A4AA0  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800A7B44 000A4AA4  38 21 00 28 */	addi r1, r1, 0x28
/* 800A7B48 000A4AA8  7C 08 03 A6 */	mtlr r0
/* 800A7B4C 000A4AAC  4E 80 00 20 */	blr 

.global init__7ActPickFP8Creature
init__7ActPickFP8Creature:
/* 800A7B50 000A4AB0  7C 08 02 A6 */	mflr r0
/* 800A7B54 000A4AB4  90 01 00 04 */	stw r0, 4(r1)
/* 800A7B58 000A4AB8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800A7B5C 000A4ABC  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800A7B60 000A4AC0  3B E0 00 00 */	li r31, 0
/* 800A7B64 000A4AC4  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800A7B68 000A4AC8  7C 9E 23 78 */	mr r30, r4
/* 800A7B6C 000A4ACC  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800A7B70 000A4AD0  3B A3 00 00 */	addi r29, r3, 0
/* 800A7B74 000A4AD4  9B E3 00 1C */	stb r31, 0x1c(r3)
/* 800A7B78 000A4AD8  80 63 00 18 */	lwz r3, 0x18(r3)
/* 800A7B7C 000A4ADC  28 03 00 00 */	cmplwi r3, 0
/* 800A7B80 000A4AE0  41 82 00 10 */	beq .L_800A7B90
/* 800A7B84 000A4AE4  41 82 00 0C */	beq .L_800A7B90
/* 800A7B88 000A4AE8  48 03 C7 E5 */	bl subCnt__12RefCountableFv
/* 800A7B8C 000A4AEC  93 FD 00 18 */	stw r31, 0x18(r29)
.L_800A7B90:
/* 800A7B90 000A4AF0  93 DD 00 18 */	stw r30, 0x18(r29)
/* 800A7B94 000A4AF4  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 800A7B98 000A4AF8  28 03 00 00 */	cmplwi r3, 0
/* 800A7B9C 000A4AFC  41 82 00 08 */	beq .L_800A7BA4
/* 800A7BA0 000A4B00  48 03 C7 BD */	bl addCnt__12RefCountableFv
.L_800A7BA4:
/* 800A7BA4 000A4B04  28 1D 00 00 */	cmplwi r29, 0
/* 800A7BA8 000A4B08  3B DD 00 00 */	addi r30, r29, 0
/* 800A7BAC 000A4B0C  41 82 00 08 */	beq .L_800A7BB4
/* 800A7BB0 000A4B10  3B DE 00 14 */	addi r30, r30, 0x14
.L_800A7BB4:
/* 800A7BB4 000A4B14  38 61 00 10 */	addi r3, r1, 0x10
/* 800A7BB8 000A4B18  38 80 00 04 */	li r4, 4
/* 800A7BBC 000A4B1C  48 07 73 9D */	bl __ct__14PaniMotionInfoFi
/* 800A7BC0 000A4B20  3B E3 00 00 */	addi r31, r3, 0
/* 800A7BC4 000A4B24  38 BE 00 00 */	addi r5, r30, 0
/* 800A7BC8 000A4B28  38 61 00 18 */	addi r3, r1, 0x18
/* 800A7BCC 000A4B2C  38 80 00 04 */	li r4, 4
/* 800A7BD0 000A4B30  48 07 73 BD */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800A7BD4 000A4B34  7C 64 1B 78 */	mr r4, r3
/* 800A7BD8 000A4B38  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800A7BDC 000A4B3C  7F E5 FB 78 */	mr r5, r31
/* 800A7BE0 000A4B40  48 02 2D F9 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800A7BE4 000A4B44  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800A7BE8 000A4B48  48 02 30 25 */	bl enableMotionBlend__4PikiFv
/* 800A7BEC 000A4B4C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800A7BF0 000A4B50  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800A7BF4 000A4B54  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800A7BF8 000A4B58  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800A7BFC 000A4B5C  38 21 00 30 */	addi r1, r1, 0x30
/* 800A7C00 000A4B60  7C 08 03 A6 */	mtlr r0
/* 800A7C04 000A4B64  4E 80 00 20 */	blr 

.global cleanup__7ActPickFv
cleanup__7ActPickFv:
/* 800A7C08 000A4B68  7C 08 02 A6 */	mflr r0
/* 800A7C0C 000A4B6C  90 01 00 04 */	stw r0, 4(r1)
/* 800A7C10 000A4B70  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800A7C14 000A4B74  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800A7C18 000A4B78  7C 7F 1B 78 */	mr r31, r3
/* 800A7C1C 000A4B7C  80 63 00 18 */	lwz r3, 0x18(r3)
/* 800A7C20 000A4B80  28 03 00 00 */	cmplwi r3, 0
/* 800A7C24 000A4B84  41 82 00 10 */	beq .L_800A7C34
/* 800A7C28 000A4B88  48 03 C7 45 */	bl subCnt__12RefCountableFv
/* 800A7C2C 000A4B8C  38 00 00 00 */	li r0, 0
/* 800A7C30 000A4B90  90 1F 00 18 */	stw r0, 0x18(r31)
.L_800A7C34:
/* 800A7C34 000A4B94  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800A7C38 000A4B98  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800A7C3C 000A4B9C  38 21 00 20 */	addi r1, r1, 0x20
/* 800A7C40 000A4BA0  7C 08 03 A6 */	mtlr r0
/* 800A7C44 000A4BA4  4E 80 00 20 */	blr 

.global exec__7ActPickFv
exec__7ActPickFv:
/* 800A7C48 000A4BA8  7C 08 02 A6 */	mflr r0
/* 800A7C4C 000A4BAC  90 01 00 04 */	stw r0, 4(r1)
/* 800A7C50 000A4BB0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800A7C54 000A4BB4  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800A7C58 000A4BB8  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800A7C5C 000A4BBC  7C 7E 1B 78 */	mr r30, r3
/* 800A7C60 000A4BC0  C0 0D AF 70 */	lfs f0, lbl_803DFC90@sda21(r13)
/* 800A7C64 000A4BC4  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800A7C68 000A4BC8  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800A7C6C 000A4BCC  C0 0D AF 74 */	lfs f0, lbl_803DFC94@sda21(r13)
/* 800A7C70 000A4BD0  D0 03 00 04 */	stfs f0, 4(r3)
/* 800A7C74 000A4BD4  C0 0D AF 78 */	lfs f0, lbl_803DFC98@sda21(r13)
/* 800A7C78 000A4BD8  D0 03 00 08 */	stfs f0, 8(r3)
/* 800A7C7C 000A4BDC  88 1E 00 1C */	lbz r0, 0x1c(r30)
/* 800A7C80 000A4BE0  28 00 00 00 */	cmplwi r0, 0
/* 800A7C84 000A4BE4  41 82 00 5C */	beq .L_800A7CE0
/* 800A7C88 000A4BE8  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800A7C8C 000A4BEC  80 03 02 AC */	lwz r0, 0x2ac(r3)
/* 800A7C90 000A4BF0  28 00 00 00 */	cmplwi r0, 0
/* 800A7C94 000A4BF4  40 82 00 44 */	bne .L_800A7CD8
/* 800A7C98 000A4BF8  38 61 00 14 */	addi r3, r1, 0x14
/* 800A7C9C 000A4BFC  38 80 00 02 */	li r4, 2
/* 800A7CA0 000A4C00  48 07 72 B9 */	bl __ct__14PaniMotionInfoFi
/* 800A7CA4 000A4C04  3B E3 00 00 */	addi r31, r3, 0
/* 800A7CA8 000A4C08  38 61 00 1C */	addi r3, r1, 0x1c
/* 800A7CAC 000A4C0C  38 80 00 02 */	li r4, 2
/* 800A7CB0 000A4C10  48 07 72 A9 */	bl __ct__14PaniMotionInfoFi
/* 800A7CB4 000A4C14  7C 64 1B 78 */	mr r4, r3
/* 800A7CB8 000A4C18  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800A7CBC 000A4C1C  7F E5 FB 78 */	mr r5, r31
/* 800A7CC0 000A4C20  48 02 2D 19 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800A7CC4 000A4C24  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800A7CC8 000A4C28  38 00 00 01 */	li r0, 1
/* 800A7CCC 000A4C2C  38 60 00 01 */	li r3, 1
/* 800A7CD0 000A4C30  98 04 04 00 */	stb r0, 0x400(r4)
/* 800A7CD4 000A4C34  48 00 00 10 */	b .L_800A7CE4
.L_800A7CD8:
/* 800A7CD8 000A4C38  38 60 00 02 */	li r3, 2
/* 800A7CDC 000A4C3C  48 00 00 08 */	b .L_800A7CE4
.L_800A7CE0:
/* 800A7CE0 000A4C40  38 60 00 00 */	li r3, 0
.L_800A7CE4:
/* 800A7CE4 000A4C44  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800A7CE8 000A4C48  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800A7CEC 000A4C4C  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800A7CF0 000A4C50  38 21 00 30 */	addi r1, r1, 0x30
/* 800A7CF4 000A4C54  7C 08 03 A6 */	mtlr r0
/* 800A7CF8 000A4C58  4E 80 00 20 */	blr 

.global initialise__Q26ActPut11InitialiserFP6Action
initialise__Q26ActPut11InitialiserFP6Action:
/* 800A7CFC 000A4C5C  4E 80 00 20 */	blr 

.global init__6ActPutFP8Creature
init__6ActPutFP8Creature:
/* 800A7D00 000A4C60  C0 02 8E 64 */	lfs f0, lbl_803E9064@sda21(r2)
/* 800A7D04 000A4C64  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 800A7D08 000A4C68  4E 80 00 20 */	blr 

.global cleanup__6ActPutFv
cleanup__6ActPutFv:
/* 800A7D0C 000A4C6C  4E 80 00 20 */	blr 

.global exec__6ActPutFv
exec__6ActPutFv:
/* 800A7D10 000A4C70  7C 08 02 A6 */	mflr r0
/* 800A7D14 000A4C74  90 01 00 04 */	stw r0, 4(r1)
/* 800A7D18 000A4C78  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800A7D1C 000A4C7C  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 800A7D20 000A4C80  7C 7F 1B 78 */	mr r31, r3
/* 800A7D24 000A4C84  C0 0D AF 7C */	lfs f0, lbl_803DFC9C@sda21(r13)
/* 800A7D28 000A4C88  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800A7D2C 000A4C8C  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800A7D30 000A4C90  C0 0D AF 80 */	lfs f0, lbl_803DFCA0@sda21(r13)
/* 800A7D34 000A4C94  D0 03 00 04 */	stfs f0, 4(r3)
/* 800A7D38 000A4C98  C0 0D AF 84 */	lfs f0, lbl_803DFCA4@sda21(r13)
/* 800A7D3C 000A4C9C  D0 03 00 08 */	stfs f0, 8(r3)
/* 800A7D40 000A4CA0  80 DF 00 0C */	lwz r6, 0xc(r31)
/* 800A7D44 000A4CA4  80 06 02 AC */	lwz r0, 0x2ac(r6)
/* 800A7D48 000A4CA8  28 00 00 00 */	cmplwi r0, 0
/* 800A7D4C 000A4CAC  7C 03 03 78 */	mr r3, r0
/* 800A7D50 000A4CB0  40 82 00 0C */	bne .L_800A7D5C
/* 800A7D54 000A4CB4  38 60 00 01 */	li r3, 1
/* 800A7D58 000A4CB8  48 00 00 7C */	b .L_800A7DD4
.L_800A7D5C:
/* 800A7D5C 000A4CBC  3C 80 80 2B */	lis r4, __vt__11Interaction@ha
/* 800A7D60 000A4CC0  C0 02 8E 68 */	lfs f0, lbl_803E9068@sda21(r2)
/* 800A7D64 000A4CC4  38 04 CF 9C */	addi r0, r4, __vt__11Interaction@l
/* 800A7D68 000A4CC8  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800A7D6C 000A4CCC  3C A0 80 2B */	lis r5, __vt__15InteractRelease@ha
/* 800A7D70 000A4CD0  38 05 D1 8C */	addi r0, r5, __vt__15InteractRelease@l
/* 800A7D74 000A4CD4  90 C1 00 30 */	stw r6, 0x30(r1)
/* 800A7D78 000A4CD8  38 81 00 2C */	addi r4, r1, 0x2c
/* 800A7D7C 000A4CDC  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800A7D80 000A4CE0  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 800A7D84 000A4CE4  81 83 00 00 */	lwz r12, 0(r3)
/* 800A7D88 000A4CE8  81 8C 00 A0 */	lwz r12, 0xa0(r12)
/* 800A7D8C 000A4CEC  7D 88 03 A6 */	mtlr r12
/* 800A7D90 000A4CF0  4E 80 00 21 */	blrl 
/* 800A7D94 000A4CF4  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800A7D98 000A4CF8  41 82 00 0C */	beq .L_800A7DA4
/* 800A7D9C 000A4CFC  38 60 00 02 */	li r3, 2
/* 800A7DA0 000A4D00  48 00 00 34 */	b .L_800A7DD4
.L_800A7DA4:
/* 800A7DA4 000A4D04  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800A7DA8 000A4D08  C0 3F 00 14 */	lfs f1, 0x14(r31)
/* 800A7DAC 000A4D0C  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800A7DB0 000A4D10  EC 01 00 28 */	fsubs f0, f1, f0
/* 800A7DB4 000A4D14  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 800A7DB8 000A4D18  C0 3F 00 14 */	lfs f1, 0x14(r31)
/* 800A7DBC 000A4D1C  C0 02 8E 6C */	lfs f0, lbl_803E906C@sda21(r2)
/* 800A7DC0 000A4D20  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800A7DC4 000A4D24  40 80 00 0C */	bge .L_800A7DD0
/* 800A7DC8 000A4D28  38 60 00 01 */	li r3, 1
/* 800A7DCC 000A4D2C  48 00 00 08 */	b .L_800A7DD4
.L_800A7DD0:
/* 800A7DD0 000A4D30  38 60 00 00 */	li r3, 0
.L_800A7DD4:
/* 800A7DD4 000A4D34  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800A7DD8 000A4D38  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 800A7DDC 000A4D3C  38 21 00 40 */	addi r1, r1, 0x40
/* 800A7DE0 000A4D40  7C 08 03 A6 */	mtlr r0
/* 800A7DE4 000A4D44  4E 80 00 20 */	blr 

.global __ct__9ActAdjustFP4Piki
__ct__9ActAdjustFP4Piki:
/* 800A7DE8 000A4D48  7C 08 02 A6 */	mflr r0
/* 800A7DEC 000A4D4C  38 A0 00 01 */	li r5, 1
/* 800A7DF0 000A4D50  90 01 00 04 */	stw r0, 4(r1)
/* 800A7DF4 000A4D54  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800A7DF8 000A4D58  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800A7DFC 000A4D5C  3B E3 00 00 */	addi r31, r3, 0
/* 800A7E00 000A4D60  48 01 BF D1 */	bl __ct__6ActionFP4Pikib
/* 800A7E04 000A4D64  3C 60 80 2B */	lis r3, __vt__9ActAdjust@ha
/* 800A7E08 000A4D68  38 03 50 C8 */	addi r0, r3, __vt__9ActAdjust@l
/* 800A7E0C 000A4D6C  90 1F 00 00 */	stw r0, 0(r31)
/* 800A7E10 000A4D70  38 00 00 08 */	li r0, 8
/* 800A7E14 000A4D74  38 7F 00 00 */	addi r3, r31, 0
/* 800A7E18 000A4D78  C0 02 8E 6C */	lfs f0, lbl_803E906C@sda21(r2)
/* 800A7E1C 000A4D7C  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 800A7E20 000A4D80  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 800A7E24 000A4D84  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 800A7E28 000A4D88  D0 1F 00 38 */	stfs f0, 0x38(r31)
/* 800A7E2C 000A4D8C  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 800A7E30 000A4D90  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 800A7E34 000A4D94  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800A7E38 000A4D98  C0 02 8E 70 */	lfs f0, lbl_803E9070@sda21(r2)
/* 800A7E3C 000A4D9C  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 800A7E40 000A4DA0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800A7E44 000A4DA4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800A7E48 000A4DA8  38 21 00 18 */	addi r1, r1, 0x18
/* 800A7E4C 000A4DAC  7C 08 03 A6 */	mtlr r0
/* 800A7E50 000A4DB0  4E 80 00 20 */	blr 

.global initialise__Q29ActAdjust11InitialiserFP6Action
initialise__Q29ActAdjust11InitialiserFP6Action:
/* 800A7E54 000A4DB4  C0 03 00 04 */	lfs f0, 4(r3)
/* 800A7E58 000A4DB8  D0 04 00 14 */	stfs f0, 0x14(r4)
/* 800A7E5C 000A4DBC  80 03 00 08 */	lwz r0, 8(r3)
/* 800A7E60 000A4DC0  90 04 00 18 */	stw r0, 0x18(r4)
/* 800A7E64 000A4DC4  4E 80 00 20 */	blr 

.global init__9ActAdjustFP8Creature
init__9ActAdjustFP8Creature:
/* 800A7E68 000A4DC8  7C 08 02 A6 */	mflr r0
/* 800A7E6C 000A4DCC  28 04 00 00 */	cmplwi r4, 0
/* 800A7E70 000A4DD0  90 01 00 04 */	stw r0, 4(r1)
/* 800A7E74 000A4DD4  94 21 FF 48 */	stwu r1, -0xb8(r1)
/* 800A7E78 000A4DD8  DB E1 00 B0 */	stfd f31, 0xb0(r1)
/* 800A7E7C 000A4DDC  DB C1 00 A8 */	stfd f30, 0xa8(r1)
/* 800A7E80 000A4DE0  DB A1 00 A0 */	stfd f29, 0xa0(r1)
/* 800A7E84 000A4DE4  DB 81 00 98 */	stfd f28, 0x98(r1)
/* 800A7E88 000A4DE8  93 E1 00 94 */	stw r31, 0x94(r1)
/* 800A7E8C 000A4DEC  93 C1 00 90 */	stw r30, 0x90(r1)
/* 800A7E90 000A4DF0  3B C3 00 00 */	addi r30, r3, 0
/* 800A7E94 000A4DF4  41 82 01 A4 */	beq .L_800A8038
/* 800A7E98 000A4DF8  38 00 00 00 */	li r0, 0
/* 800A7E9C 000A4DFC  98 1E 00 3C */	stb r0, 0x3c(r30)
/* 800A7EA0 000A4E00  3C 00 43 30 */	lis r0, 0x4330
/* 800A7EA4 000A4E04  80 A4 00 94 */	lwz r5, 0x94(r4)
/* 800A7EA8 000A4E08  80 64 00 98 */	lwz r3, 0x98(r4)
/* 800A7EAC 000A4E0C  90 BE 00 1C */	stw r5, 0x1c(r30)
/* 800A7EB0 000A4E10  90 7E 00 20 */	stw r3, 0x20(r30)
/* 800A7EB4 000A4E14  80 64 00 9C */	lwz r3, 0x9c(r4)
/* 800A7EB8 000A4E18  90 7E 00 24 */	stw r3, 0x24(r30)
/* 800A7EBC 000A4E1C  83 FE 00 0C */	lwz r31, 0xc(r30)
/* 800A7EC0 000A4E20  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800A7EC4 000A4E24  C0 3E 00 24 */	lfs f1, 0x24(r30)
/* 800A7EC8 000A4E28  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 800A7ECC 000A4E2C  C0 1F 00 9C */	lfs f0, 0x9c(r31)
/* 800A7ED0 000A4E30  90 61 00 8C */	stw r3, 0x8c(r1)
/* 800A7ED4 000A4E34  EF A1 00 28 */	fsubs f29, f1, f0
/* 800A7ED8 000A4E38  C0 5E 00 1C */	lfs f2, 0x1c(r30)
/* 800A7EDC 000A4E3C  C0 1F 00 94 */	lfs f0, 0x94(r31)
/* 800A7EE0 000A4E40  90 01 00 88 */	stw r0, 0x88(r1)
/* 800A7EE4 000A4E44  EF C2 00 28 */	fsubs f30, f2, f0
/* 800A7EE8 000A4E48  C8 22 8E 88 */	lfd f1, lbl_803E9088@sda21(r2)
/* 800A7EEC 000A4E4C  FC 40 E8 90 */	fmr f2, f29
/* 800A7EF0 000A4E50  C8 01 00 88 */	lfd f0, 0x88(r1)
/* 800A7EF4 000A4E54  C0 BE 00 20 */	lfs f5, 0x20(r30)
/* 800A7EF8 000A4E58  EC 00 08 28 */	fsubs f0, f0, f1
/* 800A7EFC 000A4E5C  C0 9F 00 98 */	lfs f4, 0x98(r31)
/* 800A7F00 000A4E60  C0 62 8E 74 */	lfs f3, lbl_803E9074@sda21(r2)
/* 800A7F04 000A4E64  FC 20 F0 90 */	fmr f1, f30
/* 800A7F08 000A4E68  EF E5 20 28 */	fsubs f31, f5, f4
/* 800A7F0C 000A4E6C  EF 83 00 32 */	fmuls f28, f3, f0
/* 800A7F10 000A4E70  48 17 3A E9 */	bl atan2f
/* 800A7F14 000A4E74  C0 5F 00 A0 */	lfs f2, 0xa0(r31)
/* 800A7F18 000A4E78  4B F9 06 9D */	bl angDist__Fff
/* 800A7F1C 000A4E7C  EC 01 E0 24 */	fdivs f0, f1, f28
/* 800A7F20 000A4E80  D0 1E 00 2C */	stfs f0, 0x2c(r30)
/* 800A7F24 000A4E84  EC 5E 07 B2 */	fmuls f2, f30, f30
/* 800A7F28 000A4E88  EC 3F 07 F2 */	fmuls f1, f31, f31
/* 800A7F2C 000A4E8C  EC 7D 07 72 */	fmuls f3, f29, f29
/* 800A7F30 000A4E90  C0 02 8E 6C */	lfs f0, lbl_803E906C@sda21(r2)
/* 800A7F34 000A4E94  EC 22 08 2A */	fadds f1, f2, f1
/* 800A7F38 000A4E98  EC 83 08 2A */	fadds f4, f3, f1
/* 800A7F3C 000A4E9C  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 800A7F40 000A4EA0  40 81 00 5C */	ble .L_800A7F9C
/* 800A7F44 000A4EA4  FC 20 20 34 */	frsqrte f1, f4
/* 800A7F48 000A4EA8  C8 62 8E 78 */	lfd f3, lbl_803E9078@sda21(r2)
/* 800A7F4C 000A4EAC  C8 42 8E 80 */	lfd f2, lbl_803E9080@sda21(r2)
/* 800A7F50 000A4EB0  FC 01 00 72 */	fmul f0, f1, f1
/* 800A7F54 000A4EB4  FC 23 00 72 */	fmul f1, f3, f1
/* 800A7F58 000A4EB8  FC 04 00 32 */	fmul f0, f4, f0
/* 800A7F5C 000A4EBC  FC 02 00 28 */	fsub f0, f2, f0
/* 800A7F60 000A4EC0  FC 21 00 32 */	fmul f1, f1, f0
/* 800A7F64 000A4EC4  FC 01 00 72 */	fmul f0, f1, f1
/* 800A7F68 000A4EC8  FC 23 00 72 */	fmul f1, f3, f1
/* 800A7F6C 000A4ECC  FC 04 00 32 */	fmul f0, f4, f0
/* 800A7F70 000A4ED0  FC 02 00 28 */	fsub f0, f2, f0
/* 800A7F74 000A4ED4  FC 21 00 32 */	fmul f1, f1, f0
/* 800A7F78 000A4ED8  FC 01 00 72 */	fmul f0, f1, f1
/* 800A7F7C 000A4EDC  FC 23 00 72 */	fmul f1, f3, f1
/* 800A7F80 000A4EE0  FC 04 00 32 */	fmul f0, f4, f0
/* 800A7F84 000A4EE4  FC 02 00 28 */	fsub f0, f2, f0
/* 800A7F88 000A4EE8  FC 01 00 32 */	fmul f0, f1, f0
/* 800A7F8C 000A4EEC  FC 04 00 32 */	fmul f0, f4, f0
/* 800A7F90 000A4EF0  FC 00 00 18 */	frsp f0, f0
/* 800A7F94 000A4EF4  D0 01 00 40 */	stfs f0, 0x40(r1)
/* 800A7F98 000A4EF8  C0 81 00 40 */	lfs f4, 0x40(r1)
.L_800A7F9C:
/* 800A7F9C 000A4EFC  C0 22 8E 68 */	lfs f1, lbl_803E9068@sda21(r2)
/* 800A7FA0 000A4F00  38 61 00 48 */	addi r3, r1, 0x48
/* 800A7FA4 000A4F04  C0 5E 00 14 */	lfs f2, 0x14(r30)
/* 800A7FA8 000A4F08  38 80 00 0B */	li r4, 0xb
/* 800A7FAC 000A4F0C  EC 01 20 24 */	fdivs f0, f1, f4
/* 800A7FB0 000A4F10  EC 44 10 28 */	fsubs f2, f4, f2
/* 800A7FB4 000A4F14  EC 21 E0 24 */	fdivs f1, f1, f28
/* 800A7FB8 000A4F18  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800A7FBC 000A4F1C  EC 01 00 32 */	fmuls f0, f1, f0
/* 800A7FC0 000A4F20  EC 5E 00 32 */	fmuls f2, f30, f0
/* 800A7FC4 000A4F24  EC 3F 00 32 */	fmuls f1, f31, f0
/* 800A7FC8 000A4F28  EC 1D 00 32 */	fmuls f0, f29, f0
/* 800A7FCC 000A4F2C  D0 41 00 34 */	stfs f2, 0x34(r1)
/* 800A7FD0 000A4F30  C0 41 00 34 */	lfs f2, 0x34(r1)
/* 800A7FD4 000A4F34  D0 41 00 58 */	stfs f2, 0x58(r1)
/* 800A7FD8 000A4F38  D0 21 00 5C */	stfs f1, 0x5c(r1)
/* 800A7FDC 000A4F3C  D0 01 00 60 */	stfs f0, 0x60(r1)
/* 800A7FE0 000A4F40  80 A1 00 58 */	lwz r5, 0x58(r1)
/* 800A7FE4 000A4F44  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 800A7FE8 000A4F48  90 BE 00 30 */	stw r5, 0x30(r30)
/* 800A7FEC 000A4F4C  90 1E 00 34 */	stw r0, 0x34(r30)
/* 800A7FF0 000A4F50  80 01 00 60 */	lwz r0, 0x60(r1)
/* 800A7FF4 000A4F54  90 1E 00 38 */	stw r0, 0x38(r30)
/* 800A7FF8 000A4F58  C0 02 8E 6C */	lfs f0, lbl_803E906C@sda21(r2)
/* 800A7FFC 000A4F5C  D0 1E 00 28 */	stfs f0, 0x28(r30)
/* 800A8000 000A4F60  48 07 6F 59 */	bl __ct__14PaniMotionInfoFi
/* 800A8004 000A4F64  3B E3 00 00 */	addi r31, r3, 0
/* 800A8008 000A4F68  38 61 00 50 */	addi r3, r1, 0x50
/* 800A800C 000A4F6C  38 80 00 0B */	li r4, 0xb
/* 800A8010 000A4F70  48 07 6F 49 */	bl __ct__14PaniMotionInfoFi
/* 800A8014 000A4F74  7C 64 1B 78 */	mr r4, r3
/* 800A8018 000A4F78  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800A801C 000A4F7C  7F E5 FB 78 */	mr r5, r31
/* 800A8020 000A4F80  48 02 29 B9 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800A8024 000A4F84  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800A8028 000A4F88  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 800A802C 000A4F8C  60 00 04 00 */	ori r0, r0, 0x400
/* 800A8030 000A4F90  90 03 00 C8 */	stw r0, 0xc8(r3)
/* 800A8034 000A4F94  48 00 00 0C */	b .L_800A8040
.L_800A8038:
/* 800A8038 000A4F98  38 00 00 01 */	li r0, 1
/* 800A803C 000A4F9C  98 1E 00 3C */	stb r0, 0x3c(r30)
.L_800A8040:
/* 800A8040 000A4FA0  80 01 00 BC */	lwz r0, 0xbc(r1)
/* 800A8044 000A4FA4  CB E1 00 B0 */	lfd f31, 0xb0(r1)
/* 800A8048 000A4FA8  CB C1 00 A8 */	lfd f30, 0xa8(r1)
/* 800A804C 000A4FAC  CB A1 00 A0 */	lfd f29, 0xa0(r1)
/* 800A8050 000A4FB0  CB 81 00 98 */	lfd f28, 0x98(r1)
/* 800A8054 000A4FB4  83 E1 00 94 */	lwz r31, 0x94(r1)
/* 800A8058 000A4FB8  83 C1 00 90 */	lwz r30, 0x90(r1)
/* 800A805C 000A4FBC  38 21 00 B8 */	addi r1, r1, 0xb8
/* 800A8060 000A4FC0  7C 08 03 A6 */	mtlr r0
/* 800A8064 000A4FC4  4E 80 00 20 */	blr 

.global cleanup__9ActAdjustFv
cleanup__9ActAdjustFv:
/* 800A8068 000A4FC8  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800A806C 000A4FCC  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 800A8070 000A4FD0  54 00 05 A8 */	rlwinm r0, r0, 0, 0x16, 0x14
/* 800A8074 000A4FD4  90 03 00 C8 */	stw r0, 0xc8(r3)
/* 800A8078 000A4FD8  4E 80 00 20 */	blr 

.global exec__9ActAdjustFv
exec__9ActAdjustFv:
/* 800A807C 000A4FDC  7C 08 02 A6 */	mflr r0
/* 800A8080 000A4FE0  90 01 00 04 */	stw r0, 4(r1)
/* 800A8084 000A4FE4  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800A8088 000A4FE8  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800A808C 000A4FEC  7C 7F 1B 78 */	mr r31, r3
/* 800A8090 000A4FF0  88 03 00 3C */	lbz r0, 0x3c(r3)
/* 800A8094 000A4FF4  28 00 00 00 */	cmplwi r0, 0
/* 800A8098 000A4FF8  41 82 00 0C */	beq .L_800A80A4
/* 800A809C 000A4FFC  38 60 00 01 */	li r3, 1
/* 800A80A0 000A5000  48 00 00 E4 */	b .L_800A8184
.L_800A80A4:
/* 800A80A4 000A5004  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800A80A8 000A5008  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 800A80AC 000A500C  80 1F 00 34 */	lwz r0, 0x34(r31)
/* 800A80B0 000A5010  90 64 00 70 */	stw r3, 0x70(r4)
/* 800A80B4 000A5014  90 04 00 74 */	stw r0, 0x74(r4)
/* 800A80B8 000A5018  80 1F 00 38 */	lwz r0, 0x38(r31)
/* 800A80BC 000A501C  90 04 00 78 */	stw r0, 0x78(r4)
/* 800A80C0 000A5020  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800A80C4 000A5024  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 800A80C8 000A5028  80 1F 00 34 */	lwz r0, 0x34(r31)
/* 800A80CC 000A502C  90 64 00 A4 */	stw r3, 0xa4(r4)
/* 800A80D0 000A5030  90 04 00 A8 */	stw r0, 0xa8(r4)
/* 800A80D4 000A5034  80 1F 00 38 */	lwz r0, 0x38(r31)
/* 800A80D8 000A5038  90 04 00 AC */	stw r0, 0xac(r4)
/* 800A80DC 000A503C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800A80E0 000A5040  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800A80E4 000A5044  C0 3F 00 2C */	lfs f1, 0x2c(r31)
/* 800A80E8 000A5048  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800A80EC 000A504C  C0 44 00 A0 */	lfs f2, 0xa0(r4)
/* 800A80F0 000A5050  EC 01 00 32 */	fmuls f0, f1, f0
/* 800A80F4 000A5054  EC 02 00 2A */	fadds f0, f2, f0
/* 800A80F8 000A5058  D0 04 00 A0 */	stfs f0, 0xa0(r4)
/* 800A80FC 000A505C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800A8100 000A5060  C0 23 00 A0 */	lfs f1, 0xa0(r3)
/* 800A8104 000A5064  4B F9 04 85 */	bl roundAng__Ff
/* 800A8108 000A5068  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800A810C 000A506C  3C 00 43 30 */	lis r0, 0x4330
/* 800A8110 000A5070  D0 23 00 A0 */	stfs f1, 0xa0(r3)
/* 800A8114 000A5074  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800A8118 000A5078  C0 0D AF 88 */	lfs f0, lbl_803DFCA8@sda21(r13)
/* 800A811C 000A507C  38 64 00 88 */	addi r3, r4, 0x88
/* 800A8120 000A5080  D0 04 00 88 */	stfs f0, 0x88(r4)
/* 800A8124 000A5084  C0 04 00 A0 */	lfs f0, 0xa0(r4)
/* 800A8128 000A5088  D0 03 00 04 */	stfs f0, 4(r3)
/* 800A812C 000A508C  C0 0D AF 8C */	lfs f0, lbl_803DFCAC@sda21(r13)
/* 800A8130 000A5090  D0 03 00 08 */	stfs f0, 8(r3)
/* 800A8134 000A5094  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800A8138 000A5098  C0 3F 00 28 */	lfs f1, 0x28(r31)
/* 800A813C 000A509C  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800A8140 000A50A0  EC 01 00 2A */	fadds f0, f1, f0
/* 800A8144 000A50A4  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 800A8148 000A50A8  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800A814C 000A50AC  C8 22 8E 88 */	lfd f1, lbl_803E9088@sda21(r2)
/* 800A8150 000A50B0  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 800A8154 000A50B4  C0 42 8E 74 */	lfs f2, lbl_803E9074@sda21(r2)
/* 800A8158 000A50B8  90 61 00 2C */	stw r3, 0x2c(r1)
/* 800A815C 000A50BC  C0 7F 00 28 */	lfs f3, 0x28(r31)
/* 800A8160 000A50C0  90 01 00 28 */	stw r0, 0x28(r1)
/* 800A8164 000A50C4  C8 01 00 28 */	lfd f0, 0x28(r1)
/* 800A8168 000A50C8  EC 00 08 28 */	fsubs f0, f0, f1
/* 800A816C 000A50CC  EC 02 00 32 */	fmuls f0, f2, f0
/* 800A8170 000A50D0  FC 03 00 40 */	fcmpo cr0, f3, f0
/* 800A8174 000A50D4  40 81 00 0C */	ble .L_800A8180
/* 800A8178 000A50D8  38 60 00 02 */	li r3, 2
/* 800A817C 000A50DC  48 00 00 08 */	b .L_800A8184
.L_800A8180:
/* 800A8180 000A50E0  38 60 00 00 */	li r3, 0
.L_800A8184:
/* 800A8184 000A50E4  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800A8188 000A50E8  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800A818C 000A50EC  38 21 00 38 */	addi r1, r1, 0x38
/* 800A8190 000A50F0  7C 08 03 A6 */	mtlr r0
/* 800A8194 000A50F4  4E 80 00 20 */	blr 

.global __dt__9ActAdjustFv
__dt__9ActAdjustFv:
/* 800A8198 000A50F8  7C 08 02 A6 */	mflr r0
/* 800A819C 000A50FC  90 01 00 04 */	stw r0, 4(r1)
/* 800A81A0 000A5100  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800A81A4 000A5104  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800A81A8 000A5108  3B E4 00 00 */	addi r31, r4, 0
/* 800A81AC 000A510C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800A81B0 000A5110  7C 7E 1B 79 */	or. r30, r3, r3
/* 800A81B4 000A5114  41 82 00 2C */	beq .L_800A81E0
/* 800A81B8 000A5118  3C 60 80 2B */	lis r3, __vt__9ActAdjust@ha
/* 800A81BC 000A511C  38 03 50 C8 */	addi r0, r3, __vt__9ActAdjust@l
/* 800A81C0 000A5120  90 1E 00 00 */	stw r0, 0(r30)
/* 800A81C4 000A5124  38 7E 00 00 */	addi r3, r30, 0
/* 800A81C8 000A5128  38 80 00 00 */	li r4, 0
/* 800A81CC 000A512C  48 01 BC 3D */	bl __dt__6ActionFv
/* 800A81D0 000A5130  7F E0 07 35 */	extsh. r0, r31
/* 800A81D4 000A5134  40 81 00 0C */	ble .L_800A81E0
/* 800A81D8 000A5138  7F C3 F3 78 */	mr r3, r30
/* 800A81DC 000A513C  4B F9 EF D1 */	bl __dl__FPv
.L_800A81E0:
/* 800A81E0 000A5140  7F C3 F3 78 */	mr r3, r30
/* 800A81E4 000A5144  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800A81E8 000A5148  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800A81EC 000A514C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800A81F0 000A5150  38 21 00 18 */	addi r1, r1, 0x18
/* 800A81F4 000A5154  7C 08 03 A6 */	mtlr r0
/* 800A81F8 000A5158  4E 80 00 20 */	blr 

.global defaultInitialiser__9ActAdjustFv
defaultInitialiser__9ActAdjustFv:
/* 800A81FC 000A515C  C0 02 8E 90 */	lfs f0, lbl_803E9090@sda21(r2)
/* 800A8200 000A5160  38 00 00 08 */	li r0, 8
/* 800A8204 000A5164  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 800A8208 000A5168  90 03 00 18 */	stw r0, 0x18(r3)
/* 800A820C 000A516C  4E 80 00 20 */	blr 

.global __dt__6ActPutFv
__dt__6ActPutFv:
/* 800A8210 000A5170  7C 08 02 A6 */	mflr r0
/* 800A8214 000A5174  90 01 00 04 */	stw r0, 4(r1)
/* 800A8218 000A5178  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800A821C 000A517C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800A8220 000A5180  3B E4 00 00 */	addi r31, r4, 0
/* 800A8224 000A5184  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800A8228 000A5188  7C 7E 1B 79 */	or. r30, r3, r3
/* 800A822C 000A518C  41 82 00 2C */	beq .L_800A8258
/* 800A8230 000A5190  3C 60 80 2B */	lis r3, __vt__6ActPut@ha
/* 800A8234 000A5194  38 03 51 84 */	addi r0, r3, __vt__6ActPut@l
/* 800A8238 000A5198  90 1E 00 00 */	stw r0, 0(r30)
/* 800A823C 000A519C  38 7E 00 00 */	addi r3, r30, 0
/* 800A8240 000A51A0  38 80 00 00 */	li r4, 0
/* 800A8244 000A51A4  48 01 BB C5 */	bl __dt__6ActionFv
/* 800A8248 000A51A8  7F E0 07 35 */	extsh. r0, r31
/* 800A824C 000A51AC  40 81 00 0C */	ble .L_800A8258
/* 800A8250 000A51B0  7F C3 F3 78 */	mr r3, r30
/* 800A8254 000A51B4  4B F9 EF 59 */	bl __dl__FPv
.L_800A8258:
/* 800A8258 000A51B8  7F C3 F3 78 */	mr r3, r30
/* 800A825C 000A51BC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800A8260 000A51C0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800A8264 000A51C4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800A8268 000A51C8  38 21 00 18 */	addi r1, r1, 0x18
/* 800A826C 000A51CC  7C 08 03 A6 */	mtlr r0
/* 800A8270 000A51D0  4E 80 00 20 */	blr 

.global __dt__7ActPickFv
__dt__7ActPickFv:
/* 800A8274 000A51D4  7C 08 02 A6 */	mflr r0
/* 800A8278 000A51D8  90 01 00 04 */	stw r0, 4(r1)
/* 800A827C 000A51DC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800A8280 000A51E0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800A8284 000A51E4  3B E4 00 00 */	addi r31, r4, 0
/* 800A8288 000A51E8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800A828C 000A51EC  7C 7E 1B 79 */	or. r30, r3, r3
/* 800A8290 000A51F0  41 82 00 34 */	beq .L_800A82C4
/* 800A8294 000A51F4  3C 60 80 2B */	lis r3, __vt__7ActPick@ha
/* 800A8298 000A51F8  38 63 52 7C */	addi r3, r3, __vt__7ActPick@l
/* 800A829C 000A51FC  90 7E 00 00 */	stw r3, 0(r30)
/* 800A82A0 000A5200  38 03 00 64 */	addi r0, r3, 0x64
/* 800A82A4 000A5204  38 7E 00 00 */	addi r3, r30, 0
/* 800A82A8 000A5208  90 1E 00 14 */	stw r0, 0x14(r30)
/* 800A82AC 000A520C  38 80 00 00 */	li r4, 0
/* 800A82B0 000A5210  48 01 BB 59 */	bl __dt__6ActionFv
/* 800A82B4 000A5214  7F E0 07 35 */	extsh. r0, r31
/* 800A82B8 000A5218  40 81 00 0C */	ble .L_800A82C4
/* 800A82BC 000A521C  7F C3 F3 78 */	mr r3, r30
/* 800A82C0 000A5220  4B F9 EE ED */	bl __dl__FPv
.L_800A82C4:
/* 800A82C4 000A5224  7F C3 F3 78 */	mr r3, r30
/* 800A82C8 000A5228  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800A82CC 000A522C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800A82D0 000A5230  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800A82D4 000A5234  38 21 00 18 */	addi r1, r1, 0x18
/* 800A82D8 000A5238  7C 08 03 A6 */	mtlr r0
/* 800A82DC 000A523C  4E 80 00 20 */	blr 

"@20@animationKeyUpdated__7ActPickFR16PaniAnimKeyEvent":
/* 800A82E0 000A5240  38 63 FF EC */	addi r3, r3, -20
/* 800A82E4 000A5244  4B FF F7 98 */	b animationKeyUpdated__7ActPickFR16PaniAnimKeyEvent

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802B5070:
	.asciz "aiActions.cpp"
.balign 4
lbl_802B5080:
	.asciz "aiActions"
.balign 4
lbl_802B508C:
	.asciz "ActAdjust"
.balign 4
lbl_802B5098:
	.asciz "Receiver<Piki>"
.balign 4
lbl_802B50A8:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
lbl_802B50B4:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.global __vt__9ActAdjust
__vt__9ActAdjust:
	.4byte __RTTI__9ActAdjust
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
	.4byte defaultInitialiser__9ActAdjustFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__9ActAdjustFv
	.4byte init__9ActAdjustFP8Creature
	.4byte exec__9ActAdjustFv
	.4byte cleanup__9ActAdjustFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
.balign 4
lbl_802B512C:
	.asciz "ActAdjust::Initialiser"
.balign 4
lbl_802B5144:
	.asciz "Action::Initialiser"
.balign 4
lbl_802B5158:
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte 0
.global __vt__Q29ActAdjust11Initialiser
__vt__Q29ActAdjust11Initialiser:
	.4byte __RTTI__Q29ActAdjust11Initialiser
	.4byte 0
	.4byte initialise__Q29ActAdjust11InitialiserFP6Action
lbl_802B5170:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.global __vt__6ActPut
__vt__6ActPut:
	.4byte __RTTI__6ActPut
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
	.4byte __dt__6ActPutFv
	.4byte init__6ActPutFP8Creature
	.4byte exec__6ActPutFv
	.4byte cleanup__6ActPutFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
.balign 4
lbl_802B51E8:
	.asciz "ActPut::Initialiser"
.balign 4
lbl_802B51FC:
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte 0
.global __vt__Q26ActPut11Initialiser
__vt__Q26ActPut11Initialiser:
	.4byte __RTTI__Q26ActPut11Initialiser
	.4byte 0
	.4byte initialise__Q26ActPut11InitialiserFP6Action
.balign 4
lbl_802B5214:
	.asciz "Interaction"
.balign 4
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
.balign 4
lbl_802B524C:
	.asciz "PaniAnimKeyListener"
.balign 4
lbl_802B5260:
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x14
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.global __vt__7ActPick
__vt__7ActPick:
	.4byte __RTTI__7ActPick
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
	.4byte __dt__7ActPickFv
	.4byte init__7ActPickFP8Creature
	.4byte exec__7ActPickFv
	.4byte cleanup__7ActPickFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
	.4byte __RTTI__7ActPick
	.4byte 0xFFFFFFEC
	.4byte "@20@animationKeyUpdated__7ActPickFR16PaniAnimKeyEvent"
	.4byte animationKeyUpdated__7ActPickFR16PaniAnimKeyEvent
.balign 4
lbl_802B52F0:
	.asciz "ActPick::Initialiser"
.balign 4
lbl_802B5308:
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte 0
.global __vt__Q27ActPick11Initialiser
__vt__Q27ActPick11Initialiser:
	.4byte __RTTI__Q27ActPick11Initialiser
	.4byte 0
	.4byte initialise__Q27ActPick11InitialiserFP6Action
	.4byte 0
	.4byte 0
	.4byte 0
lbl_802B532C:
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

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DFC90:
	.float 0.0
lbl_803DFC94:
	.float 0.0
lbl_803DFC98:
	.float 0.0
lbl_803DFC9C:
	.float 0.0
lbl_803DFCA0:
	.float 0.0
lbl_803DFCA4:
	.float 0.0
lbl_803DFCA8:
	.float 0.0
lbl_803DFCAC:
	.float 0.0
"__RTTI__15Receiver<4Piki>":
	.4byte lbl_802B5098
	.4byte 0
.balign 4
lbl_803DFCB8:
	.asciz "Action"
.balign 4
__RTTI__6Action:
	.4byte lbl_803DFCB8
	.4byte lbl_802B50A8
__RTTI__9ActAdjust:
	.4byte lbl_802B508C
	.4byte lbl_802B50B4
__RTTI__Q26Action11Initialiser:
	.4byte lbl_802B5144
	.4byte 0
__RTTI__Q29ActAdjust11Initialiser:
	.4byte lbl_802B512C
	.4byte lbl_802B5158
.balign 4
lbl_803DFCE0:
	.asciz "ActPut"
.balign 4
__RTTI__6ActPut:
	.4byte lbl_803DFCE0
	.4byte lbl_802B5170
__RTTI__Q26ActPut11Initialiser:
	.4byte lbl_802B51E8
	.4byte lbl_802B51FC
.balign 4
lbl_803DFCF8:
	.asciz "ActPick"
.balign 4
__RTTI__19PaniAnimKeyListener:
	.4byte lbl_802B524C
	.4byte 0
__RTTI__7ActPick:
	.4byte lbl_803DFCF8
	.4byte lbl_802B5260
__RTTI__Q27ActPick11Initialiser:
	.4byte lbl_802B52F0
	.4byte lbl_802B5308

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E9060:
	.float 20.0
lbl_803E9064:
	.float 0.5
lbl_803E9068:
	.float 1.0
lbl_803E906C:
	.float 0.0
lbl_803E9070:
	.float 5.0
lbl_803E9074:
	.float 0.033333335
.balign 8
lbl_803E9078:
	.double 0.5
.balign 8
lbl_803E9080:
	.double 3.0
.balign 8
lbl_803E9088:
	.8byte 0x4330000080000000
lbl_803E9090:
	.float 10.0
