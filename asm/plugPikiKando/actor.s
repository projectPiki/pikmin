.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn setType__5ActorFiP15PikiShapeObjectP12CreaturePropP8SimpleAI, global
/* 80119A10 00116970  7C 08 02 A6 */	mflr r0
/* 80119A14 00116974  90 01 00 04 */	stw r0, 4(r1)
/* 80119A18 00116978  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80119A1C 0011697C  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 80119A20 00116980  93 C1 00 38 */	stw r30, 0x38(r1)
/* 80119A24 00116984  7C FE 3B 78 */	mr r30, r7
/* 80119A28 00116988  93 A1 00 34 */	stw r29, 0x34(r1)
/* 80119A2C 0011698C  7C 7D 1B 78 */	mr r29, r3
/* 80119A30 00116990  90 C3 02 24 */	stw r6, 0x224(r3)
/* 80119A34 00116994  90 A3 03 B0 */	stw r5, 0x3b0(r3)
/* 80119A38 00116998  4B FB EE AD */	bl getAnimMgr__15PikiShapeObjectFv
/* 80119A3C 0011699C  80 9D 03 B0 */	lwz r4, 0x3b0(r29)
/* 80119A40 001169A0  90 64 00 24 */	stw r3, 0x24(r4)
/* 80119A44 001169A4  38 7D 03 04 */	addi r3, r29, 0x304
/* 80119A48 001169A8  81 1D 03 B0 */	lwz r8, 0x3b0(r29)
/* 80119A4C 001169AC  80 CD 31 30 */	lwz r6, actorMgr@sda21(r13)
/* 80119A50 001169B0  80 88 00 24 */	lwz r4, 0x24(r8)
/* 80119A54 001169B4  38 A8 00 14 */	addi r5, r8, 0x14
/* 80119A58 001169B8  80 E6 00 3C */	lwz r7, 0x3c(r6)
/* 80119A5C 001169BC  38 C8 00 04 */	addi r6, r8, 4
/* 80119A60 001169C0  48 00 5E 7D */	bl init__15PaniPikiAnimMgrFP7AnimMgrP11AnimContextP11AnimContextP15PaniMotionTable
/* 80119A64 001169C4  38 61 00 1C */	addi r3, r1, 0x1c
/* 80119A68 001169C8  38 80 00 03 */	li r4, 3
/* 80119A6C 001169CC  48 00 54 ED */	bl __ct__14PaniMotionInfoFi
/* 80119A70 001169D0  3B E3 00 00 */	addi r31, r3, 0
/* 80119A74 001169D4  38 61 00 24 */	addi r3, r1, 0x24
/* 80119A78 001169D8  38 80 00 03 */	li r4, 3
/* 80119A7C 001169DC  38 A0 00 00 */	li r5, 0
/* 80119A80 001169E0  48 00 55 0D */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 80119A84 001169E4  38 83 00 00 */	addi r4, r3, 0
/* 80119A88 001169E8  38 BF 00 00 */	addi r5, r31, 0
/* 80119A8C 001169EC  38 7D 03 04 */	addi r3, r29, 0x304
/* 80119A90 001169F0  48 00 5F D9 */	bl startMotion__15PaniPikiAnimMgrFR14PaniMotionInfoR14PaniMotionInfo
/* 80119A94 001169F4  93 DD 02 E8 */	stw r30, 0x2e8(r29)
/* 80119A98 001169F8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80119A9C 001169FC  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 80119AA0 00116A00  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 80119AA4 00116A04  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 80119AA8 00116A08  38 21 00 40 */	addi r1, r1, 0x40
/* 80119AAC 00116A0C  7C 08 03 A6 */	mtlr r0
/* 80119AB0 00116A10  4E 80 00 20 */	blr 
.endfn setType__5ActorFiP15PikiShapeObjectP12CreaturePropP8SimpleAI
