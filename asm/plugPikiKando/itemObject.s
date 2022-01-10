.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global startAI__8ItemBallFi
startAI__8ItemBallFi:
/* 800F7958 000F48B8  7C 08 02 A6 */	mflr r0
/* 800F795C 000F48BC  38 83 00 00 */	addi r4, r3, 0
/* 800F7960 000F48C0  90 01 00 04 */	stw r0, 4(r1)
/* 800F7964 000F48C4  38 04 03 C8 */	addi r0, r4, 0x3c8
/* 800F7968 000F48C8  38 A4 03 DC */	addi r5, r4, 0x3dc
/* 800F796C 000F48CC  94 21 FF F8 */	stwu r1, -8(r1)
/* 800F7970 000F48D0  38 C4 07 EC */	addi r6, r4, 0x7ec
/* 800F7974 000F48D4  90 03 02 20 */	stw r0, 0x220(r3)
/* 800F7978 000F48D8  80 63 02 20 */	lwz r3, 0x220(r3)
/* 800F797C 000F48DC  80 84 03 08 */	lwz r4, 0x308(r4)
/* 800F7980 000F48E0  4B F9 21 E5 */	bl initInfo__8CollInfoFP5ShapeP8CollPartPUl
/* 800F7984 000F48E4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800F7988 000F48E8  38 21 00 08 */	addi r1, r1, 8
/* 800F798C 000F48EC  7C 08 03 A6 */	mtlr r0
/* 800F7990 000F48F0  4E 80 00 20 */	blr 

.global isAlive__8ItemBallFv
isAlive__8ItemBallFv:
/* 800F7994 000F48F4  38 60 00 01 */	li r3, 1
/* 800F7998 000F48F8  4E 80 00 20 */	blr 

.global isVisible__8ItemBallFv
isVisible__8ItemBallFv:
/* 800F799C 000F48FC  38 60 00 01 */	li r3, 1
/* 800F79A0 000F4900  4E 80 00 20 */	blr 

.global update__10ItemObjectFv
update__10ItemObjectFv:
/* 800F79A4 000F4904  4E 80 00 20 */	blr 

.global __ct__11BombGenItemFP5Shape
__ct__11BombGenItemFP5Shape:
/* 800F79A8 000F4908  7C 08 02 A6 */	mflr r0
/* 800F79AC 000F490C  38 C4 00 00 */	addi r6, r4, 0
/* 800F79B0 000F4910  90 01 00 04 */	stw r0, 4(r1)
/* 800F79B4 000F4914  38 80 00 0D */	li r4, 0xd
/* 800F79B8 000F4918  38 A0 00 00 */	li r5, 0
/* 800F79BC 000F491C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F79C0 000F4920  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F79C4 000F4924  3B E3 00 00 */	addi r31, r3, 0
/* 800F79C8 000F4928  4B FF DE E5 */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800F79CC 000F492C  3C 60 80 2C */	lis r3, __vt__10ItemObject@ha
/* 800F79D0 000F4930  38 63 F9 6C */	addi r3, r3, __vt__10ItemObject@l
/* 800F79D4 000F4934  90 7F 00 00 */	stw r3, 0(r31)
/* 800F79D8 000F4938  38 03 01 14 */	addi r0, r3, 0x114
/* 800F79DC 000F493C  3C 60 80 2C */	lis r3, __vt__11BombGenItem@ha
/* 800F79E0 000F4940  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800F79E4 000F4944  38 00 00 0D */	li r0, 0xd
/* 800F79E8 000F4948  38 63 F8 10 */	addi r3, r3, __vt__11BombGenItem@l
/* 800F79EC 000F494C  90 1F 00 6C */	stw r0, 0x6c(r31)
/* 800F79F0 000F4950  38 A3 01 14 */	addi r5, r3, 0x114
/* 800F79F4 000F4954  38 80 FF FF */	li r4, -1
/* 800F79F8 000F4958  90 7F 00 00 */	stw r3, 0(r31)
/* 800F79FC 000F495C  38 00 00 01 */	li r0, 1
/* 800F7A00 000F4960  38 7F 00 00 */	addi r3, r31, 0
/* 800F7A04 000F4964  90 BF 02 B8 */	stw r5, 0x2b8(r31)
/* 800F7A08 000F4968  B0 9F 03 C8 */	sth r4, 0x3c8(r31)
/* 800F7A0C 000F496C  B0 1F 03 CA */	sth r0, 0x3ca(r31)
/* 800F7A10 000F4970  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F7A14 000F4974  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F7A18 000F4978  38 21 00 18 */	addi r1, r1, 0x18
/* 800F7A1C 000F497C  7C 08 03 A6 */	mtlr r0
/* 800F7A20 000F4980  4E 80 00 20 */	blr 

.global pickable__11BombGenItemFv
pickable__11BombGenItemFv:
/* 800F7A24 000F4984  A8 03 03 C8 */	lha r0, 0x3c8(r3)
/* 800F7A28 000F4988  2C 00 FF FF */	cmpwi r0, -1
/* 800F7A2C 000F498C  40 82 00 0C */	bne lbl_800F7A38
/* 800F7A30 000F4990  38 60 00 01 */	li r3, 1
/* 800F7A34 000F4994  4E 80 00 20 */	blr 
lbl_800F7A38:
/* 800F7A38 000F4998  A8 03 03 CA */	lha r0, 0x3ca(r3)
/* 800F7A3C 000F499C  2C 00 00 00 */	cmpwi r0, 0
/* 800F7A40 000F49A0  40 81 00 0C */	ble lbl_800F7A4C
/* 800F7A44 000F49A4  38 60 00 01 */	li r3, 1
/* 800F7A48 000F49A8  4E 80 00 20 */	blr 
lbl_800F7A4C:
/* 800F7A4C 000F49AC  38 60 00 00 */	li r3, 0
/* 800F7A50 000F49B0  4E 80 00 20 */	blr 

.global pick__11BombGenItemFv
pick__11BombGenItemFv:
/* 800F7A54 000F49B4  A8 83 03 C8 */	lha r4, 0x3c8(r3)
/* 800F7A58 000F49B8  2C 04 FF FF */	cmpwi r4, -1
/* 800F7A5C 000F49BC  40 82 00 0C */	bne lbl_800F7A68
/* 800F7A60 000F49C0  38 00 00 01 */	li r0, 1
/* 800F7A64 000F49C4  48 00 00 1C */	b lbl_800F7A80
lbl_800F7A68:
/* 800F7A68 000F49C8  A8 03 03 CA */	lha r0, 0x3ca(r3)
/* 800F7A6C 000F49CC  2C 00 00 00 */	cmpwi r0, 0
/* 800F7A70 000F49D0  40 81 00 0C */	ble lbl_800F7A7C
/* 800F7A74 000F49D4  38 00 00 01 */	li r0, 1
/* 800F7A78 000F49D8  48 00 00 08 */	b lbl_800F7A80
lbl_800F7A7C:
/* 800F7A7C 000F49DC  38 00 00 00 */	li r0, 0
lbl_800F7A80:
/* 800F7A80 000F49E0  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 800F7A84 000F49E4  40 82 00 0C */	bne lbl_800F7A90
/* 800F7A88 000F49E8  38 60 00 00 */	li r3, 0
/* 800F7A8C 000F49EC  4E 80 00 20 */	blr 
lbl_800F7A90:
/* 800F7A90 000F49F0  7C 80 07 35 */	extsh. r0, r4
/* 800F7A94 000F49F4  40 81 00 24 */	ble lbl_800F7AB8
/* 800F7A98 000F49F8  A8 83 03 CA */	lha r4, 0x3ca(r3)
/* 800F7A9C 000F49FC  2C 04 00 00 */	cmpwi r4, 0
/* 800F7AA0 000F4A00  40 81 00 10 */	ble lbl_800F7AB0
/* 800F7AA4 000F4A04  38 04 FF FF */	addi r0, r4, -1
/* 800F7AA8 000F4A08  B0 03 03 CA */	sth r0, 0x3ca(r3)
/* 800F7AAC 000F4A0C  48 00 00 0C */	b lbl_800F7AB8
lbl_800F7AB0:
/* 800F7AB0 000F4A10  38 60 00 00 */	li r3, 0
/* 800F7AB4 000F4A14  4E 80 00 20 */	blr 
lbl_800F7AB8:
/* 800F7AB8 000F4A18  38 60 00 01 */	li r3, 1
/* 800F7ABC 000F4A1C  4E 80 00 20 */	blr 

.global __ct__7FulcrumFv
__ct__7FulcrumFv:
/* 800F7AC0 000F4A20  7C 08 02 A6 */	mflr r0
/* 800F7AC4 000F4A24  38 80 00 11 */	li r4, 0x11
/* 800F7AC8 000F4A28  90 01 00 04 */	stw r0, 4(r1)
/* 800F7ACC 000F4A2C  38 A0 00 00 */	li r5, 0
/* 800F7AD0 000F4A30  38 C0 00 00 */	li r6, 0
/* 800F7AD4 000F4A34  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F7AD8 000F4A38  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F7ADC 000F4A3C  3B E3 00 00 */	addi r31, r3, 0
/* 800F7AE0 000F4A40  4B FF DD CD */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800F7AE4 000F4A44  3C 60 80 2C */	lis r3, __vt__10ItemObject@ha
/* 800F7AE8 000F4A48  38 63 F9 6C */	addi r3, r3, __vt__10ItemObject@l
/* 800F7AEC 000F4A4C  90 7F 00 00 */	stw r3, 0(r31)
/* 800F7AF0 000F4A50  38 03 01 14 */	addi r0, r3, 0x114
/* 800F7AF4 000F4A54  3C 60 80 2C */	lis r3, __vt__7Fulcrum@ha
/* 800F7AF8 000F4A58  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800F7AFC 000F4A5C  38 00 00 11 */	li r0, 0x11
/* 800F7B00 000F4A60  38 83 F6 6C */	addi r4, r3, __vt__7Fulcrum@l
/* 800F7B04 000F4A64  90 1F 00 6C */	stw r0, 0x6c(r31)
/* 800F7B08 000F4A68  38 04 01 14 */	addi r0, r4, 0x114
/* 800F7B0C 000F4A6C  38 7F 00 00 */	addi r3, r31, 0
/* 800F7B10 000F4A70  90 9F 00 00 */	stw r4, 0(r31)
/* 800F7B14 000F4A74  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800F7B18 000F4A78  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F7B1C 000F4A7C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F7B20 000F4A80  38 21 00 18 */	addi r1, r1, 0x18
/* 800F7B24 000F4A84  7C 08 03 A6 */	mtlr r0
/* 800F7B28 000F4A88  4E 80 00 20 */	blr 

.global __ct__19NaviDemoSunsetStartFv
__ct__19NaviDemoSunsetStartFv:
/* 800F7B2C 000F4A8C  7C 08 02 A6 */	mflr r0
/* 800F7B30 000F4A90  38 80 00 1B */	li r4, 0x1b
/* 800F7B34 000F4A94  90 01 00 04 */	stw r0, 4(r1)
/* 800F7B38 000F4A98  38 A0 00 00 */	li r5, 0
/* 800F7B3C 000F4A9C  38 C0 00 00 */	li r6, 0
/* 800F7B40 000F4AA0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F7B44 000F4AA4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F7B48 000F4AA8  3B E3 00 00 */	addi r31, r3, 0
/* 800F7B4C 000F4AAC  4B FF DD 61 */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800F7B50 000F4AB0  3C 60 80 2C */	lis r3, __vt__10ItemObject@ha
/* 800F7B54 000F4AB4  38 63 F9 6C */	addi r3, r3, __vt__10ItemObject@l
/* 800F7B58 000F4AB8  90 7F 00 00 */	stw r3, 0(r31)
/* 800F7B5C 000F4ABC  38 03 01 14 */	addi r0, r3, 0x114
/* 800F7B60 000F4AC0  3C 60 80 2C */	lis r3, __vt__19NaviDemoSunsetStart@ha
/* 800F7B64 000F4AC4  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800F7B68 000F4AC8  38 00 00 1B */	li r0, 0x1b
/* 800F7B6C 000F4ACC  38 83 F4 D4 */	addi r4, r3, __vt__19NaviDemoSunsetStart@l
/* 800F7B70 000F4AD0  90 1F 00 6C */	stw r0, 0x6c(r31)
/* 800F7B74 000F4AD4  38 04 01 14 */	addi r0, r4, 0x114
/* 800F7B78 000F4AD8  38 7F 00 00 */	addi r3, r31, 0
/* 800F7B7C 000F4ADC  90 9F 00 00 */	stw r4, 0(r31)
/* 800F7B80 000F4AE0  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800F7B84 000F4AE4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F7B88 000F4AE8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F7B8C 000F4AEC  38 21 00 18 */	addi r1, r1, 0x18
/* 800F7B90 000F4AF0  7C 08 03 A6 */	mtlr r0
/* 800F7B94 000F4AF4  4E 80 00 20 */	blr 

.global __ct__18NaviDemoSunsetGoalFv
__ct__18NaviDemoSunsetGoalFv:
/* 800F7B98 000F4AF8  7C 08 02 A6 */	mflr r0
/* 800F7B9C 000F4AFC  38 80 00 1C */	li r4, 0x1c
/* 800F7BA0 000F4B00  90 01 00 04 */	stw r0, 4(r1)
/* 800F7BA4 000F4B04  38 A0 00 00 */	li r5, 0
/* 800F7BA8 000F4B08  38 C0 00 00 */	li r6, 0
/* 800F7BAC 000F4B0C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F7BB0 000F4B10  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F7BB4 000F4B14  3B E3 00 00 */	addi r31, r3, 0
/* 800F7BB8 000F4B18  4B FF DC F5 */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800F7BBC 000F4B1C  3C 60 80 2C */	lis r3, __vt__10ItemObject@ha
/* 800F7BC0 000F4B20  38 63 F9 6C */	addi r3, r3, __vt__10ItemObject@l
/* 800F7BC4 000F4B24  90 7F 00 00 */	stw r3, 0(r31)
/* 800F7BC8 000F4B28  38 03 01 14 */	addi r0, r3, 0x114
/* 800F7BCC 000F4B2C  3C 60 80 2C */	lis r3, __vt__18NaviDemoSunsetGoal@ha
/* 800F7BD0 000F4B30  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800F7BD4 000F4B34  38 00 00 1C */	li r0, 0x1c
/* 800F7BD8 000F4B38  38 83 F3 28 */	addi r4, r3, __vt__18NaviDemoSunsetGoal@l
/* 800F7BDC 000F4B3C  90 1F 00 6C */	stw r0, 0x6c(r31)
/* 800F7BE0 000F4B40  38 04 01 14 */	addi r0, r4, 0x114
/* 800F7BE4 000F4B44  38 7F 00 00 */	addi r3, r31, 0
/* 800F7BE8 000F4B48  90 9F 00 00 */	stw r4, 0(r31)
/* 800F7BEC 000F4B4C  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800F7BF0 000F4B50  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F7BF4 000F4B54  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F7BF8 000F4B58  38 21 00 18 */	addi r1, r1, 0x18
/* 800F7BFC 000F4B5C  7C 08 03 A6 */	mtlr r0
/* 800F7C00 000F4B60  4E 80 00 20 */	blr 

.global needShadow__10ItemObjectFv
needShadow__10ItemObjectFv:
/* 800F7C04 000F4B64  38 60 00 00 */	li r3, 0
/* 800F7C08 000F4B68  4E 80 00 20 */	blr 

.global postUpdate__10ItemObjectFif
postUpdate__10ItemObjectFif:
/* 800F7C0C 000F4B6C  4E 80 00 20 */	blr 

.global isAtari__10ItemObjectFv
isAtari__10ItemObjectFv:
/* 800F7C10 000F4B70  38 60 00 00 */	li r3, 0
/* 800F7C14 000F4B74  4E 80 00 20 */	blr 

.global isAtari__11BombGenItemFv
isAtari__11BombGenItemFv:
/* 800F7C18 000F4B78  A8 03 03 C8 */	lha r0, 0x3c8(r3)
/* 800F7C1C 000F4B7C  2C 00 FF FF */	cmpwi r0, -1
/* 800F7C20 000F4B80  40 82 00 0C */	bne lbl_800F7C2C
/* 800F7C24 000F4B84  38 60 00 01 */	li r3, 1
/* 800F7C28 000F4B88  4E 80 00 20 */	blr 
lbl_800F7C2C:
/* 800F7C2C 000F4B8C  A8 03 03 CA */	lha r0, 0x3ca(r3)
/* 800F7C30 000F4B90  2C 00 00 00 */	cmpwi r0, 0
/* 800F7C34 000F4B94  40 81 00 0C */	ble lbl_800F7C40
/* 800F7C38 000F4B98  38 60 00 01 */	li r3, 1
/* 800F7C3C 000F4B9C  4E 80 00 20 */	blr 
lbl_800F7C40:
/* 800F7C40 000F4BA0  38 60 00 00 */	li r3, 0
/* 800F7C44 000F4BA4  4E 80 00 20 */	blr 

.global needFlick__11BombGenItemFP8Creature
needFlick__11BombGenItemFP8Creature:
/* 800F7C48 000F4BA8  38 60 00 00 */	li r3, 0
/* 800F7C4C 000F4BAC  4E 80 00 20 */	blr 

.global isVisible__11BombGenItemFv
isVisible__11BombGenItemFv:
/* 800F7C50 000F4BB0  A8 03 03 C8 */	lha r0, 0x3c8(r3)
/* 800F7C54 000F4BB4  2C 00 FF FF */	cmpwi r0, -1
/* 800F7C58 000F4BB8  40 82 00 0C */	bne lbl_800F7C64
/* 800F7C5C 000F4BBC  38 60 00 01 */	li r3, 1
/* 800F7C60 000F4BC0  4E 80 00 20 */	blr 
lbl_800F7C64:
/* 800F7C64 000F4BC4  A8 03 03 CA */	lha r0, 0x3ca(r3)
/* 800F7C68 000F4BC8  2C 00 00 00 */	cmpwi r0, 0
/* 800F7C6C 000F4BCC  40 81 00 0C */	ble lbl_800F7C78
/* 800F7C70 000F4BD0  38 60 00 01 */	li r3, 1
/* 800F7C74 000F4BD4  4E 80 00 20 */	blr 
lbl_800F7C78:
/* 800F7C78 000F4BD8  38 60 00 00 */	li r3, 0
/* 800F7C7C 000F4BDC  4E 80 00 20 */	blr 

.global isAlive__11BombGenItemFv
isAlive__11BombGenItemFv:
/* 800F7C80 000F4BE0  A8 03 03 C8 */	lha r0, 0x3c8(r3)
/* 800F7C84 000F4BE4  2C 00 FF FF */	cmpwi r0, -1
/* 800F7C88 000F4BE8  40 82 00 0C */	bne lbl_800F7C94
/* 800F7C8C 000F4BEC  38 60 00 01 */	li r3, 1
/* 800F7C90 000F4BF0  4E 80 00 20 */	blr 
lbl_800F7C94:
/* 800F7C94 000F4BF4  A8 03 03 CA */	lha r0, 0x3ca(r3)
/* 800F7C98 000F4BF8  2C 00 00 00 */	cmpwi r0, 0
/* 800F7C9C 000F4BFC  40 81 00 0C */	ble lbl_800F7CA8
/* 800F7CA0 000F4C00  38 60 00 01 */	li r3, 1
/* 800F7CA4 000F4C04  4E 80 00 20 */	blr 
lbl_800F7CA8:
/* 800F7CA8 000F4C08  38 60 00 00 */	li r3, 0
/* 800F7CAC 000F4C0C  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BF1C0:
	.asciz "itemObject.cpp"
.balign 4
lbl_802BF1D0:
	.asciz "itemObject"
.balign 4
lbl_802BF1DC:
	.asciz "NaviDemoSunsetGoal"
.balign 4
lbl_802BF1F0:
	.asciz "PaniAnimKeyListener"
.balign 4
lbl_802BF204:
	.asciz "EventTalker"
.balign 4
lbl_802BF210:
	.asciz "RefCountable"
.balign 4
lbl_802BF220:
	.asciz "Creature"
.balign 4
lbl_802BF22C:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
.balign 4
lbl_802BF240:
	.asciz "AICreature"
.balign 4
lbl_802BF24C:
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
lbl_802BF270:
	.asciz "ItemCreature"
.balign 4
lbl_802BF280:
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
.balign 4
lbl_802BF2AC:
	.asciz "ItemObject"
.balign 4
lbl_802BF2B8:
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
lbl_802BF2EC:
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
	.4byte __RTTI__10ItemObject
	.4byte 0
	.4byte 0
.global __vt__18NaviDemoSunsetGoal
__vt__18NaviDemoSunsetGoal:
	.4byte __RTTI__18NaviDemoSunsetGoal
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
	.4byte startAI__8CreatureFi
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
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
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__10ItemObjectFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__10ItemObjectFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
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
	.4byte update__10ItemObjectFv
	.4byte postUpdate__10ItemObjectFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12ItemCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__18NaviDemoSunsetGoal
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
lbl_802BF484:
	.asciz "NaviDemoSunsetStart"
.balign 4
lbl_802BF498:
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
	.4byte __RTTI__10ItemObject
	.4byte 0
	.4byte 0
.global __vt__19NaviDemoSunsetStart
__vt__19NaviDemoSunsetStart:
	.4byte __RTTI__19NaviDemoSunsetStart
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
	.4byte startAI__8CreatureFi
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
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
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__10ItemObjectFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__10ItemObjectFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
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
	.4byte update__10ItemObjectFv
	.4byte postUpdate__10ItemObjectFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12ItemCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__19NaviDemoSunsetStart
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
lbl_802BF630:
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
	.4byte __RTTI__10ItemObject
	.4byte 0
	.4byte 0
.global __vt__7Fulcrum
__vt__7Fulcrum:
	.4byte __RTTI__7Fulcrum
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
	.4byte startAI__8CreatureFi
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
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
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__10ItemObjectFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__10ItemObjectFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
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
	.4byte update__10ItemObjectFv
	.4byte postUpdate__10ItemObjectFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12ItemCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__7Fulcrum
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
lbl_802BF7C8:
	.asciz "BombGenItem"
.balign 4
lbl_802BF7D4:
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
	.4byte __RTTI__10ItemObject
	.4byte 0
	.4byte 0
.global __vt__11BombGenItem
__vt__11BombGenItem:
	.4byte __RTTI__11BombGenItem
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
	.4byte startAI__8CreatureFi
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
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
	.4byte isVisible__11BombGenItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__11BombGenItemFv
	.4byte isAlive__11BombGenItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__10ItemObjectFv
	.4byte needFlick__11BombGenItemFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
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
	.4byte update__10ItemObjectFv
	.4byte postUpdate__10ItemObjectFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12ItemCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__11BombGenItem
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
.global __vt__10ItemObject
__vt__10ItemObject:
	.4byte __RTTI__10ItemObject
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
	.4byte startAI__8CreatureFi
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
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
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__10ItemObjectFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__10ItemObjectFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
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
	.4byte update__10ItemObjectFv
	.4byte postUpdate__10ItemObjectFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12ItemCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__10ItemObject
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
lbl_802BFAC8:
	.asciz "ItemBall"
.balign 4
lbl_802BFAD4:
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
.global __vt__8ItemBall
__vt__8ItemBall:
	.4byte __RTTI__8ItemBall
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
	.4byte startAI__8ItemBallFi
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
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
	.4byte isVisible__8ItemBallFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8ItemBallFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
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
	.4byte update__12ItemCreatureFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12ItemCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__8ItemBall
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
__RTTI__19PaniAnimKeyListener:
	.4byte lbl_802BF1F0
	.4byte 0
__RTTI__11EventTalker:
	.4byte lbl_802BF204
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802BF210
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802BF220
	.4byte lbl_802BF22C
__RTTI__10AICreature:
	.4byte lbl_802BF240
	.4byte lbl_802BF24C
__RTTI__12ItemCreature:
	.4byte lbl_802BF270
	.4byte lbl_802BF280
__RTTI__10ItemObject:
	.4byte lbl_802BF2AC
	.4byte lbl_802BF2B8
__RTTI__18NaviDemoSunsetGoal:
	.4byte lbl_802BF1DC
	.4byte lbl_802BF2EC
__RTTI__19NaviDemoSunsetStart:
	.4byte lbl_802BF484
	.4byte lbl_802BF498
.balign 4
lbl_803E1EC8:
	.asciz "Fulcrum"
.balign 4
__RTTI__7Fulcrum:
	.4byte lbl_803E1EC8
	.4byte lbl_802BF630
__RTTI__11BombGenItem:
	.4byte lbl_802BF7C8
	.4byte lbl_802BF7D4
__RTTI__8ItemBall:
	.4byte lbl_802BFAC8
	.4byte lbl_802BFAD4
