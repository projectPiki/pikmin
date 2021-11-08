.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
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

.global __ct__8MizuItemFiP12CreaturePropP15ItemShapeObjectP8SimpleAI
__ct__8MizuItemFiP12CreaturePropP15ItemShapeObjectP8SimpleAI:
/* 800F7CB0 000F4C10  7C 08 02 A6 */	mflr r0
/* 800F7CB4 000F4C14  90 01 00 04 */	stw r0, 4(r1)
/* 800F7CB8 000F4C18  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F7CBC 000F4C1C  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800F7CC0 000F4C20  3B E7 00 00 */	addi r31, r7, 0
/* 800F7CC4 000F4C24  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800F7CC8 000F4C28  3B C6 00 00 */	addi r30, r6, 0
/* 800F7CCC 000F4C2C  38 C0 00 00 */	li r6, 0
/* 800F7CD0 000F4C30  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800F7CD4 000F4C34  3B A3 00 00 */	addi r29, r3, 0
/* 800F7CD8 000F4C38  4B FF DB D5 */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800F7CDC 000F4C3C  3C 60 80 2C */	lis r3, __vt__8MizuItem@ha
/* 800F7CE0 000F4C40  38 63 FD 80 */	addi r3, r3, __vt__8MizuItem@l
/* 800F7CE4 000F4C44  90 7D 00 00 */	stw r3, 0(r29)
/* 800F7CE8 000F4C48  38 03 01 14 */	addi r0, r3, 0x114
/* 800F7CEC 000F4C4C  38 7D 00 00 */	addi r3, r29, 0
/* 800F7CF0 000F4C50  90 1D 02 B8 */	stw r0, 0x2b8(r29)
/* 800F7CF4 000F4C54  93 DD 03 C0 */	stw r30, 0x3c0(r29)
/* 800F7CF8 000F4C58  93 FD 02 E8 */	stw r31, 0x2e8(r29)
/* 800F7CFC 000F4C5C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F7D00 000F4C60  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800F7D04 000F4C64  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800F7D08 000F4C68  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800F7D0C 000F4C6C  38 21 00 30 */	addi r1, r1, 0x30
/* 800F7D10 000F4C70  7C 08 03 A6 */	mtlr r0
/* 800F7D14 000F4C74  4E 80 00 20 */	blr 

.global update__8MizuItemFv
update__8MizuItemFv:
/* 800F7D18 000F4C78  7C 08 02 A6 */	mflr r0
/* 800F7D1C 000F4C7C  90 01 00 04 */	stw r0, 4(r1)
/* 800F7D20 000F4C80  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F7D24 000F4C84  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F7D28 000F4C88  7C 7F 1B 78 */	mr r31, r3
/* 800F7D2C 000F4C8C  4B FF DE C9 */	bl update__12ItemCreatureFv
/* 800F7D30 000F4C90  80 1F 02 8C */	lwz r0, 0x28c(r31)
/* 800F7D34 000F4C94  28 00 00 00 */	cmplwi r0, 0
/* 800F7D38 000F4C98  41 82 00 3C */	beq lbl_800F7D74
/* 800F7D3C 000F4C9C  80 1F 00 6C */	lwz r0, 0x6c(r31)
/* 800F7D40 000F4CA0  2C 00 00 06 */	cmpwi r0, 6
/* 800F7D44 000F4CA4  40 82 00 30 */	bne lbl_800F7D74
/* 800F7D48 000F4CA8  38 00 00 09 */	li r0, 9
/* 800F7D4C 000F4CAC  90 01 00 0C */	stw r0, 0xc(r1)
/* 800F7D50 000F4CB0  80 7F 02 E8 */	lwz r3, 0x2e8(r31)
/* 800F7D54 000F4CB4  28 03 00 00 */	cmplwi r3, 0
/* 800F7D58 000F4CB8  41 82 00 1C */	beq lbl_800F7D74
/* 800F7D5C 000F4CBC  81 83 00 00 */	lwz r12, 0(r3)
/* 800F7D60 000F4CC0  38 9F 00 00 */	addi r4, r31, 0
/* 800F7D64 000F4CC4  38 A1 00 0C */	addi r5, r1, 0xc
/* 800F7D68 000F4CC8  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800F7D6C 000F4CCC  7D 88 03 A6 */	mtlr r12
/* 800F7D70 000F4CD0  4E 80 00 21 */	blrl 
lbl_800F7D74:
/* 800F7D74 000F4CD4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F7D78 000F4CD8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F7D7C 000F4CDC  38 21 00 18 */	addi r1, r1, 0x18
/* 800F7D80 000F4CE0  7C 08 03 A6 */	mtlr r0
/* 800F7D84 000F4CE4  4E 80 00 20 */	blr 

.global needFlick__8MizuItemFP8Creature
needFlick__8MizuItemFP8Creature:
/* 800F7D88 000F4CE8  38 60 00 00 */	li r3, 0
/* 800F7D8C 000F4CEC  4E 80 00 20 */	blr 

.global startAI__8MizuItemFi
startAI__8MizuItemFi:
/* 800F7D90 000F4CF0  7C 08 02 A6 */	mflr r0
/* 800F7D94 000F4CF4  38 80 00 00 */	li r4, 0
/* 800F7D98 000F4CF8  90 01 00 04 */	stw r0, 4(r1)
/* 800F7D9C 000F4CFC  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800F7DA0 000F4D00  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800F7DA4 000F4D04  3B E3 00 00 */	addi r31, r3, 0
/* 800F7DA8 000F4D08  38 61 00 10 */	addi r3, r1, 0x10
/* 800F7DAC 000F4D0C  C0 02 9C 50 */	lfs f0, lbl_803E9E50@sda21(r2)
/* 800F7DB0 000F4D10  D0 1F 00 7C */	stfs f0, 0x7c(r31)
/* 800F7DB4 000F4D14  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 800F7DB8 000F4D18  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 800F7DBC 000F4D1C  48 02 71 9D */	bl __ct__14PaniMotionInfoFi
/* 800F7DC0 000F4D20  38 83 00 00 */	addi r4, r3, 0
/* 800F7DC4 000F4D24  38 7F 03 6C */	addi r3, r31, 0x36c
/* 800F7DC8 000F4D28  48 02 73 F9 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 800F7DCC 000F4D2C  80 1F 00 6C */	lwz r0, 0x6c(r31)
/* 800F7DD0 000F4D30  2C 00 00 06 */	cmpwi r0, 6
/* 800F7DD4 000F4D34  41 82 00 28 */	beq lbl_800F7DFC
/* 800F7DD8 000F4D38  40 80 00 34 */	bge lbl_800F7E0C
/* 800F7DDC 000F4D3C  2C 00 00 01 */	cmpwi r0, 1
/* 800F7DE0 000F4D40  41 82 00 08 */	beq lbl_800F7DE8
/* 800F7DE4 000F4D44  48 00 00 28 */	b lbl_800F7E0C
lbl_800F7DE8:
/* 800F7DE8 000F4D48  80 7F 02 E8 */	lwz r3, 0x2e8(r31)
/* 800F7DEC 000F4D4C  38 9F 00 00 */	addi r4, r31, 0
/* 800F7DF0 000F4D50  38 A0 00 03 */	li r5, 3
/* 800F7DF4 000F4D54  4B F8 59 65 */	bl start__8SimpleAIFP10AICreaturei
/* 800F7DF8 000F4D58  48 00 00 14 */	b lbl_800F7E0C
lbl_800F7DFC:
/* 800F7DFC 000F4D5C  80 7F 02 E8 */	lwz r3, 0x2e8(r31)
/* 800F7E00 000F4D60  38 9F 00 00 */	addi r4, r31, 0
/* 800F7E04 000F4D64  38 A0 00 00 */	li r5, 0
/* 800F7E08 000F4D68  4B F8 59 51 */	bl start__8SimpleAIFP10AICreaturei
lbl_800F7E0C:
/* 800F7E0C 000F4D6C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800F7E10 000F4D70  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800F7E14 000F4D74  38 21 00 28 */	addi r1, r1, 0x28
/* 800F7E18 000F4D78  7C 08 03 A6 */	mtlr r0
/* 800F7E1C 000F4D7C  4E 80 00 20 */	blr 

.global isAlive__8MizuItemFv
isAlive__8MizuItemFv:
/* 800F7E20 000F4D80  7C 08 02 A6 */	mflr r0
/* 800F7E24 000F4D84  90 01 00 04 */	stw r0, 4(r1)
/* 800F7E28 000F4D88  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F7E2C 000F4D8C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F7E30 000F4D90  7C 7F 1B 78 */	mr r31, r3
/* 800F7E34 000F4D94  81 9F 00 00 */	lwz r12, 0(r31)
/* 800F7E38 000F4D98  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800F7E3C 000F4D9C  7D 88 03 A6 */	mtlr r12
/* 800F7E40 000F4DA0  4E 80 00 21 */	blrl 
/* 800F7E44 000F4DA4  80 1F 00 6C */	lwz r0, 0x6c(r31)
/* 800F7E48 000F4DA8  80 63 00 04 */	lwz r3, 4(r3)
/* 800F7E4C 000F4DAC  2C 00 00 06 */	cmpwi r0, 6
/* 800F7E50 000F4DB0  40 82 00 0C */	bne lbl_800F7E5C
/* 800F7E54 000F4DB4  38 60 00 00 */	li r3, 0
/* 800F7E58 000F4DB8  48 00 00 20 */	b lbl_800F7E78
lbl_800F7E5C:
/* 800F7E5C 000F4DBC  2C 03 00 04 */	cmpwi r3, 4
/* 800F7E60 000F4DC0  41 82 00 0C */	beq lbl_800F7E6C
/* 800F7E64 000F4DC4  2C 03 00 02 */	cmpwi r3, 2
/* 800F7E68 000F4DC8  40 82 00 0C */	bne lbl_800F7E74
lbl_800F7E6C:
/* 800F7E6C 000F4DCC  38 60 00 00 */	li r3, 0
/* 800F7E70 000F4DD0  48 00 00 08 */	b lbl_800F7E78
lbl_800F7E74:
/* 800F7E74 000F4DD4  38 60 00 01 */	li r3, 1
lbl_800F7E78:
/* 800F7E78 000F4DD8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F7E7C 000F4DDC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F7E80 000F4DE0  38 21 00 20 */	addi r1, r1, 0x20
/* 800F7E84 000F4DE4  7C 08 03 A6 */	mtlr r0
/* 800F7E88 000F4DE8  4E 80 00 20 */	blr 

.global createMotionTable__16PaniItemAnimatorFv
createMotionTable__16PaniItemAnimatorFv:
/* 800F7E8C 000F4DEC  7C 08 02 A6 */	mflr r0
/* 800F7E90 000F4DF0  38 60 00 08 */	li r3, 8
/* 800F7E94 000F4DF4  90 01 00 04 */	stw r0, 4(r1)
/* 800F7E98 000F4DF8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F7E9C 000F4DFC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F7EA0 000F4E00  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800F7EA4 000F4E04  4B F4 F1 61 */	bl alloc__6SystemFUl
/* 800F7EA8 000F4E08  3B E3 00 00 */	addi r31, r3, 0
/* 800F7EAC 000F4E0C  7F E3 FB 79 */	or. r3, r31, r31
/* 800F7EB0 000F4E10  41 82 00 0C */	beq lbl_800F7EBC
/* 800F7EB4 000F4E14  38 80 00 0F */	li r4, 0xf
/* 800F7EB8 000F4E18  48 02 71 51 */	bl __ct__15PaniMotionTableFi
lbl_800F7EBC:
/* 800F7EBC 000F4E1C  38 60 00 08 */	li r3, 8
/* 800F7EC0 000F4E20  4B F4 F1 45 */	bl alloc__6SystemFUl
/* 800F7EC4 000F4E24  3B C3 00 00 */	addi r30, r3, 0
/* 800F7EC8 000F4E28  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7ECC 000F4E2C  41 82 00 0C */	beq lbl_800F7ED8
/* 800F7ED0 000F4E30  38 80 00 00 */	li r4, 0
/* 800F7ED4 000F4E34  48 02 70 F5 */	bl __ct__10PaniMotionFi
lbl_800F7ED8:
/* 800F7ED8 000F4E38  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7EDC 000F4E3C  38 60 00 08 */	li r3, 8
/* 800F7EE0 000F4E40  93 C4 00 00 */	stw r30, 0(r4)
/* 800F7EE4 000F4E44  4B F4 F1 21 */	bl alloc__6SystemFUl
/* 800F7EE8 000F4E48  3B C3 00 00 */	addi r30, r3, 0
/* 800F7EEC 000F4E4C  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7EF0 000F4E50  41 82 00 0C */	beq lbl_800F7EFC

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x61694578
	.4byte 0x69742e63
	.4byte 0x70700000
	.4byte 0x52656365
	.4byte 0x69766572
	.4byte 0x3c50696b
	.4byte 0x693e0000
	.4byte 0x803e039c
	.4byte 0
	.4byte 0
	.4byte 0x803e039c
	.4byte 0
	.4byte 0x803e03ac
	.4byte 0
	.4byte 0
.global __vt__7ActExit
__vt__7ActExit:
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
	.4byte lbl_800A7908
	.4byte lbl_800A7930
	.4byte lbl_800A7944
	.4byte lbl_800A7958
	.4byte lbl_800A796C
	.4byte lbl_800A7980
	.4byte lbl_800A7994
	.4byte lbl_800A79A8
	.4byte lbl_800A791C
	.4byte lbl_800A79D0
	.4byte lbl_800A79BC
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x802B6624
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0320
	.4byte 0x802B6634
.global __RTTI__9ActEscape
__RTTI__9ActEscape:
	.4byte 0x802b6618
	.4byte 0x802b6640
	.4byte 0x802b66d0
	.4byte 0
.global __RTTI__Q29ActEscape11Initialiser
__RTTI__Q29ActEscape11Initialiser:
	.4byte 0x802b66b8
	.4byte 0x802b66e4
.global lbl_803E0348
lbl_803E0348:
	.4byte 0x45786974
	.4byte 0x00000000
.global lbl_803E0350
lbl_803E0350:
	.4byte 0x00000000
.global lbl_803E0354
lbl_803E0354:
	.4byte 0x00000000
.global lbl_803E0358
lbl_803E0358:
	.4byte 0x00000000
.global lbl_803E035C
lbl_803E035C:
	.4byte 0x3F800000
.global lbl_803E0360
lbl_803E0360:
	.4byte 0x3F800000
.global lbl_803E0364
lbl_803E0364:
	.4byte 0x3F800000
.global lbl_803E0368
lbl_803E0368:
	.4byte 0x3F800000
.global lbl_803E036C
lbl_803E036C:
	.4byte 0x3F800000
.global lbl_803E0370
lbl_803E0370:
	.4byte 0x3F800000
.global lbl_803E0374
lbl_803E0374:
	.4byte 0x3F800000
.global lbl_803E0378
lbl_803E0378:
	.4byte 0x3F800000
.global lbl_803E037C
lbl_803E037C:
	.4byte 0x3F800000
.global lbl_803E0380
lbl_803E0380:
	.4byte 0x00000000
.global lbl_803E0384
lbl_803E0384:
	.4byte 0x3F800000
.global lbl_803E0388
lbl_803E0388:
	.4byte 0x3F800000
.global lbl_803E038C
lbl_803E038C:
	.4byte 0x3F800000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EAA5C
lbl_803EAA5C:
	.4byte 0x46480000
.global lbl_803EAA60
lbl_803EAA60:
	.4byte 0x3F800000
.global lbl_803EAA64
lbl_803EAA64:
	.4byte 0x46FFFE00
.global lbl_803EAA68
lbl_803EAA68:
	.4byte 0x3F7FFFEF
	.4byte 0x00000000
.global "@894"
"@894":
	.4byte 0x43300000
	.4byte 0x80000000
.global lbl_803EAA78
lbl_803EAA78:
	.4byte 0x00000000
.global lbl_803EAA7C
lbl_803EAA7C:
	.4byte 0x41F00000
.global lbl_803EAA80
lbl_803EAA80:
	.4byte 0x3FC00000
.global lbl_803EAA84
lbl_803EAA84:
	.4byte 0x3DE76C8B
.global lbl_803EAA88
lbl_803EAA88:
	.4byte 0x3EBD70A4
.global lbl_803EAA8C
lbl_803EAA8C:
	.4byte 0x40E00000
.global lbl_803EAA90
lbl_803EAA90:
	.4byte 0x3DCCCCCD

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EC134
lbl_803EC134:
	.4byte 0x3F7FF972
.global lbl_803EC138
lbl_803EC138:
	.4byte 0x3DB2B8C3
.global lbl_803EC13C
lbl_803EC13C:
	.4byte 0xBDB2B8C3
.global lbl_803EC140
lbl_803EC140:
	.4byte 0x43480000
.global lbl_803EC144
lbl_803EC144:
	.4byte 0xC0000000
.global lbl_803EC148
lbl_803EC148:
	.4byte 0x43160000
.global lbl_803EC14C
lbl_803EC14C:
	.4byte 0x44200000
.global lbl_803EC150
lbl_803EC150:
	.4byte 0x43FA0000
.global lbl_803EC154
lbl_803EC154:
	.4byte 0xC3F00000
.global lbl_803EC158
lbl_803EC158:
	.4byte 0x43A00000
	.4byte 0x00000000
.global lbl_803EC160
lbl_803EC160:
	.4byte 0x41900000
.global lbl_803EC164
lbl_803EC164:
	.4byte 0x41980000
.global lbl_803EC168
lbl_803EC168:
	.4byte 0x3F4CCCCD
