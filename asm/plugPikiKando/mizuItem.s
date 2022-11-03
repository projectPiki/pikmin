.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
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
/* 800F7D38 000F4C98  41 82 00 3C */	beq .L_800F7D74
/* 800F7D3C 000F4C9C  80 1F 00 6C */	lwz r0, 0x6c(r31)
/* 800F7D40 000F4CA0  2C 00 00 06 */	cmpwi r0, 6
/* 800F7D44 000F4CA4  40 82 00 30 */	bne .L_800F7D74
/* 800F7D48 000F4CA8  38 00 00 09 */	li r0, 9
/* 800F7D4C 000F4CAC  90 01 00 0C */	stw r0, 0xc(r1)
/* 800F7D50 000F4CB0  80 7F 02 E8 */	lwz r3, 0x2e8(r31)
/* 800F7D54 000F4CB4  28 03 00 00 */	cmplwi r3, 0
/* 800F7D58 000F4CB8  41 82 00 1C */	beq .L_800F7D74
/* 800F7D5C 000F4CBC  81 83 00 00 */	lwz r12, 0(r3)
/* 800F7D60 000F4CC0  38 9F 00 00 */	addi r4, r31, 0
/* 800F7D64 000F4CC4  38 A1 00 0C */	addi r5, r1, 0xc
/* 800F7D68 000F4CC8  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800F7D6C 000F4CCC  7D 88 03 A6 */	mtlr r12
/* 800F7D70 000F4CD0  4E 80 00 21 */	blrl 
.L_800F7D74:
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
/* 800F7DD4 000F4D34  41 82 00 28 */	beq .L_800F7DFC
/* 800F7DD8 000F4D38  40 80 00 34 */	bge .L_800F7E0C
/* 800F7DDC 000F4D3C  2C 00 00 01 */	cmpwi r0, 1
/* 800F7DE0 000F4D40  41 82 00 08 */	beq .L_800F7DE8
/* 800F7DE4 000F4D44  48 00 00 28 */	b .L_800F7E0C
.L_800F7DE8:
/* 800F7DE8 000F4D48  80 7F 02 E8 */	lwz r3, 0x2e8(r31)
/* 800F7DEC 000F4D4C  38 9F 00 00 */	addi r4, r31, 0
/* 800F7DF0 000F4D50  38 A0 00 03 */	li r5, 3
/* 800F7DF4 000F4D54  4B F8 59 65 */	bl start__8SimpleAIFP10AICreaturei
/* 800F7DF8 000F4D58  48 00 00 14 */	b .L_800F7E0C
.L_800F7DFC:
/* 800F7DFC 000F4D5C  80 7F 02 E8 */	lwz r3, 0x2e8(r31)
/* 800F7E00 000F4D60  38 9F 00 00 */	addi r4, r31, 0
/* 800F7E04 000F4D64  38 A0 00 00 */	li r5, 0
/* 800F7E08 000F4D68  4B F8 59 51 */	bl start__8SimpleAIFP10AICreaturei
.L_800F7E0C:
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
/* 800F7E50 000F4DB0  40 82 00 0C */	bne .L_800F7E5C
/* 800F7E54 000F4DB4  38 60 00 00 */	li r3, 0
/* 800F7E58 000F4DB8  48 00 00 20 */	b .L_800F7E78
.L_800F7E5C:
/* 800F7E5C 000F4DBC  2C 03 00 04 */	cmpwi r3, 4
/* 800F7E60 000F4DC0  41 82 00 0C */	beq .L_800F7E6C
/* 800F7E64 000F4DC4  2C 03 00 02 */	cmpwi r3, 2
/* 800F7E68 000F4DC8  40 82 00 0C */	bne .L_800F7E74
.L_800F7E6C:
/* 800F7E6C 000F4DCC  38 60 00 00 */	li r3, 0
/* 800F7E70 000F4DD0  48 00 00 08 */	b .L_800F7E78
.L_800F7E74:
/* 800F7E74 000F4DD4  38 60 00 01 */	li r3, 1
.L_800F7E78:
/* 800F7E78 000F4DD8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F7E7C 000F4DDC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F7E80 000F4DE0  38 21 00 20 */	addi r1, r1, 0x20
/* 800F7E84 000F4DE4  7C 08 03 A6 */	mtlr r0
/* 800F7E88 000F4DE8  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BFC68:
	.asciz "mizuItem.cpp"
.balign 4
lbl_802BFC78:
	.asciz "matoItem"
.balign 4
lbl_802BFC84:
	.asciz "MizuItem"
.balign 4
lbl_802BFC90:
	.asciz "PaniAnimKeyListener"
.balign 4
lbl_802BFCA4:
	.asciz "EventTalker"
.balign 4
lbl_802BFCB0:
	.asciz "RefCountable"
.balign 4
lbl_802BFCC0:
	.asciz "Creature"
.balign 4
lbl_802BFCCC:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
.balign 4
lbl_802BFCE0:
	.asciz "AICreature"
.balign 4
lbl_802BFCEC:
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
lbl_802BFD10:
	.asciz "ItemCreature"
.balign 4
lbl_802BFD20:
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
lbl_802BFD4C:
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
.global __vt__8MizuItem
__vt__8MizuItem:
	.4byte __RTTI__8MizuItem
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
	.4byte startAI__8MizuItemFi
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
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8MizuItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8MizuItemFP8Creature
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
	.4byte update__8MizuItemFv
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
	.4byte __RTTI__8MizuItem
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
	.4byte lbl_802BFC90
	.4byte 0
__RTTI__11EventTalker:
	.4byte lbl_802BFCA4
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802BFCB0
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802BFCC0
	.4byte lbl_802BFCCC
__RTTI__10AICreature:
	.4byte lbl_802BFCE0
	.4byte lbl_802BFCEC
__RTTI__12ItemCreature:
	.4byte lbl_802BFD10
	.4byte lbl_802BFD20
__RTTI__8MizuItem:
	.4byte lbl_802BFC84
	.4byte lbl_802BFD4C

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E9E50:
	.float 1.0
