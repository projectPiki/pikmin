.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__4TekiFv
__ct__4TekiFv:
/* 80143BF0 00140B50  7C 08 02 A6 */	mflr r0
/* 80143BF4 00140B54  90 01 00 04 */	stw r0, 4(r1)
/* 80143BF8 00140B58  7C 80 07 35 */	extsh. r0, r4
/* 80143BFC 00140B5C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80143C00 00140B60  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80143C04 00140B64  3B E3 00 00 */	addi r31, r3, 0
/* 80143C08 00140B68  41 82 00 18 */	beq lbl_80143C20
/* 80143C0C 00140B6C  38 1F 05 38 */	addi r0, r31, 0x538
/* 80143C10 00140B70  3C 60 80 2B */	lis r3, __vt__19PaniAnimKeyListener@ha
/* 80143C14 00140B74  90 1F 02 C0 */	stw r0, 0x2c0(r31)
/* 80143C18 00140B78  38 03 DB 94 */	addi r0, r3, __vt__19PaniAnimKeyListener@l
/* 80143C1C 00140B7C  90 1F 05 38 */	stw r0, 0x538(r31)
lbl_80143C20:
/* 80143C20 00140B80  38 7F 00 00 */	addi r3, r31, 0
/* 80143C24 00140B84  38 80 00 00 */	li r4, 0
/* 80143C28 00140B88  48 05 EB 2D */	bl __ct__5YTekiFv
/* 80143C2C 00140B8C  3C 60 80 2D */	lis r3, __vt__4Teki@ha
/* 80143C30 00140B90  38 63 CC 28 */	addi r3, r3, __vt__4Teki@l
/* 80143C34 00140B94  90 7F 00 00 */	stw r3, 0(r31)
/* 80143C38 00140B98  38 C3 01 F4 */	addi r6, r3, 0x1f4
/* 80143C3C 00140B9C  38 83 01 14 */	addi r4, r3, 0x114
/* 80143C40 00140BA0  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
/* 80143C44 00140BA4  38 1F 05 38 */	addi r0, r31, 0x538
/* 80143C48 00140BA8  38 7F 00 00 */	addi r3, r31, 0
/* 80143C4C 00140BAC  90 C5 00 00 */	stw r6, 0(r5)
/* 80143C50 00140BB0  90 9F 02 B8 */	stw r4, 0x2b8(r31)
/* 80143C54 00140BB4  80 9F 02 C0 */	lwz r4, 0x2c0(r31)
/* 80143C58 00140BB8  7C 04 00 50 */	subf r0, r4, r0
/* 80143C5C 00140BBC  90 04 00 04 */	stw r0, 4(r4)
/* 80143C60 00140BC0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80143C64 00140BC4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80143C68 00140BC8  38 21 00 18 */	addi r1, r1, 0x18
/* 80143C6C 00140BCC  7C 08 03 A6 */	mtlr r0
/* 80143C70 00140BD0  4E 80 00 20 */	blr 

.global init__5YTekiFi
init__5YTekiFi:
/* 80143C74 00140BD4  7C 08 02 A6 */	mflr r0
/* 80143C78 00140BD8  90 01 00 04 */	stw r0, 4(r1)
/* 80143C7C 00140BDC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80143C80 00140BE0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80143C84 00140BE4  7C 7F 1B 78 */	mr r31, r3
/* 80143C88 00140BE8  48 00 0C A9 */	bl init__5BTekiFi
/* 80143C8C 00140BEC  C0 02 A7 48 */	lfs f0, lbl_803EA948@sda21(r2)
/* 80143C90 00140BF0  38 60 00 00 */	li r3, 0
/* 80143C94 00140BF4  38 A0 00 08 */	li r5, 8
/* 80143C98 00140BF8  D0 1F 04 78 */	stfs f0, 0x478(r31)
/* 80143C9C 00140BFC  90 7F 04 98 */	stw r3, 0x498(r31)
/* 80143CA0 00140C00  90 7F 04 9C */	stw r3, 0x49c(r31)
/* 80143CA4 00140C04  90 7F 04 A0 */	stw r3, 0x4a0(r31)
/* 80143CA8 00140C08  90 7F 04 A4 */	stw r3, 0x4a4(r31)
/* 80143CAC 00140C0C  90 7F 04 A8 */	stw r3, 0x4a8(r31)
/* 80143CB0 00140C10  90 7F 04 AC */	stw r3, 0x4ac(r31)
/* 80143CB4 00140C14  90 7F 04 B0 */	stw r3, 0x4b0(r31)
/* 80143CB8 00140C18  90 7F 04 B4 */	stw r3, 0x4b4(r31)
/* 80143CBC 00140C1C  48 00 00 24 */	b lbl_80143CE0
lbl_80143CC0:
/* 80143CC0 00140C20  20 05 00 09 */	subfic r0, r5, 9
/* 80143CC4 00140C24  2C 05 00 09 */	cmpwi r5, 9
/* 80143CC8 00140C28  7C 09 03 A6 */	mtctr r0
/* 80143CCC 00140C2C  40 80 00 20 */	bge lbl_80143CEC
lbl_80143CD0:
/* 80143CD0 00140C30  90 64 04 98 */	stw r3, 0x498(r4)
/* 80143CD4 00140C34  38 84 00 04 */	addi r4, r4, 4
/* 80143CD8 00140C38  42 00 FF F8 */	bdnz lbl_80143CD0
/* 80143CDC 00140C3C  48 00 00 10 */	b lbl_80143CEC
lbl_80143CE0:
/* 80143CE0 00140C40  54 A0 10 3A */	slwi r0, r5, 2
/* 80143CE4 00140C44  7C 9F 02 14 */	add r4, r31, r0
/* 80143CE8 00140C48  4B FF FF D8 */	b lbl_80143CC0
lbl_80143CEC:
/* 80143CEC 00140C4C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80143CF0 00140C50  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80143CF4 00140C54  38 21 00 20 */	addi r1, r1, 0x20
/* 80143CF8 00140C58  7C 08 03 A6 */	mtlr r0
/* 80143CFC 00140C5C  4E 80 00 20 */	blr 

.global setTekiOptions__5BTekiFi
setTekiOptions__5BTekiFi:
/* 80143D00 00140C60  90 83 04 10 */	stw r4, 0x410(r3)
/* 80143D04 00140C64  4E 80 00 20 */	blr 

.global clearTekiOptions__5BTekiFv
clearTekiOptions__5BTekiFv:
/* 80143D08 00140C68  38 00 00 00 */	li r0, 0
/* 80143D0C 00140C6C  90 03 04 10 */	stw r0, 0x410(r3)
/* 80143D10 00140C70  4E 80 00 20 */	blr 

.global setAnimationKeyOption__5BTekiFi
setAnimationKeyOption__5BTekiFi:
/* 80143D14 00140C74  80 03 04 14 */	lwz r0, 0x414(r3)
/* 80143D18 00140C78  7C 00 23 78 */	or r0, r0, r4
/* 80143D1C 00140C7C  90 03 04 14 */	stw r0, 0x414(r3)
/* 80143D20 00140C80  4E 80 00 20 */	blr 

.global clearAnimationKeyOption__5BTekiFi
clearAnimationKeyOption__5BTekiFi:
/* 80143D24 00140C84  80 03 04 14 */	lwz r0, 0x414(r3)
/* 80143D28 00140C88  7C 00 20 78 */	andc r0, r0, r4
/* 80143D2C 00140C8C  90 03 04 14 */	stw r0, 0x414(r3)
/* 80143D30 00140C90  4E 80 00 20 */	blr 

.global setAnimationKeyOptions__5BTekiFi
setAnimationKeyOptions__5BTekiFi:
/* 80143D34 00140C94  90 83 04 14 */	stw r4, 0x414(r3)
/* 80143D38 00140C98  4E 80 00 20 */	blr 

.global clearAnimationKeyOptions__5BTekiFv
clearAnimationKeyOptions__5BTekiFv:
/* 80143D3C 00140C9C  38 00 00 00 */	li r0, 0
/* 80143D40 00140CA0  90 03 04 14 */	stw r0, 0x414(r3)
/* 80143D44 00140CA4  4E 80 00 20 */	blr 

.global getShadowSize__5BTekiFv
getShadowSize__5BTekiFv:
/* 80143D48 00140CA8  80 63 02 C4 */	lwz r3, 0x2c4(r3)
/* 80143D4C 00140CAC  80 63 00 84 */	lwz r3, 0x84(r3)
/* 80143D50 00140CB0  80 63 00 04 */	lwz r3, 4(r3)
/* 80143D54 00140CB4  80 63 00 00 */	lwz r3, 0(r3)
/* 80143D58 00140CB8  C0 23 00 48 */	lfs f1, 0x48(r3)
/* 80143D5C 00140CBC  4E 80 00 20 */	blr 

.global isVisible__5BTekiFv
isVisible__5BTekiFv:
/* 80143D60 00140CC0  80 63 04 10 */	lwz r3, 0x410(r3)
/* 80143D64 00140CC4  80 0D F6 2C */	lwz r0, TEKI_OPTION_VISIBLE__5BTeki@sda21(r13)
/* 80143D68 00140CC8  7C 60 00 38 */	and r0, r3, r0
/* 80143D6C 00140CCC  7C 60 00 D0 */	neg r3, r0
/* 80143D70 00140CD0  30 03 FF FF */	addic r0, r3, -1
/* 80143D74 00140CD4  7C 60 19 10 */	subfe r3, r0, r3
/* 80143D78 00140CD8  4E 80 00 20 */	blr 

.global isOrganic__5BTekiFv
isOrganic__5BTekiFv:
/* 80143D7C 00140CDC  80 63 04 10 */	lwz r3, 0x410(r3)
/* 80143D80 00140CE0  80 0D F6 40 */	lwz r0, TEKI_OPTION_ORGANIC__5BTeki@sda21(r13)
/* 80143D84 00140CE4  7C 60 00 38 */	and r0, r3, r0
/* 80143D88 00140CE8  7C 60 00 D0 */	neg r3, r0
/* 80143D8C 00140CEC  30 03 FF FF */	addic r0, r3, -1
/* 80143D90 00140CF0  7C 60 19 10 */	subfe r3, r0, r3
/* 80143D94 00140CF4  4E 80 00 20 */	blr 

.global isAtari__5BTekiFv
isAtari__5BTekiFv:
/* 80143D98 00140CF8  80 63 04 10 */	lwz r3, 0x410(r3)
/* 80143D9C 00140CFC  80 0D F6 38 */	lwz r0, TEKI_OPTION_ATARI__5BTeki@sda21(r13)
/* 80143DA0 00140D00  7C 60 00 38 */	and r0, r3, r0
/* 80143DA4 00140D04  7C 60 00 D0 */	neg r3, r0
/* 80143DA8 00140D08  30 03 FF FF */	addic r0, r3, -1
/* 80143DAC 00140D0C  7C 60 19 10 */	subfe r3, r0, r3
/* 80143DB0 00140D10  4E 80 00 20 */	blr 

.global isAlive__5BTekiFv
isAlive__5BTekiFv:
/* 80143DB4 00140D14  80 63 04 10 */	lwz r3, 0x410(r3)
/* 80143DB8 00140D18  80 0D F6 3C */	lwz r0, TEKI_OPTION_ALIVE__5BTeki@sda21(r13)
/* 80143DBC 00140D1C  7C 60 00 38 */	and r0, r3, r0
/* 80143DC0 00140D20  7C 60 00 D0 */	neg r3, r0
/* 80143DC4 00140D24  30 03 FF FF */	addic r0, r3, -1
/* 80143DC8 00140D28  7C 60 19 10 */	subfe r3, r0, r3
/* 80143DCC 00140D2C  4E 80 00 20 */	blr 

.global needShadow__5BTekiFv
needShadow__5BTekiFv:
/* 80143DD0 00140D30  80 63 04 10 */	lwz r3, 0x410(r3)
/* 80143DD4 00140D34  80 0D F6 30 */	lwz r0, TEKI_OPTION_SHADOW_VISIBLE__5BTeki@sda21(r13)
/* 80143DD8 00140D38  7C 60 00 38 */	and r0, r3, r0
/* 80143DDC 00140D3C  7C 60 00 D0 */	neg r3, r0
/* 80143DE0 00140D40  30 03 FF FF */	addic r0, r3, -1
/* 80143DE4 00140D44  7C 60 19 10 */	subfe r3, r0, r3
/* 80143DE8 00140D48  4E 80 00 20 */	blr 

.global "@1336@4@animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent"
"@1336@4@animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent":
/* 80143DEC 00140D4C  39 60 00 04 */	li r11, 4
/* 80143DF0 00140D50  7D 63 58 2E */	lwzx r11, r3, r11
/* 80143DF4 00140D54  7C 63 5A 14 */	add r3, r3, r11
/* 80143DF8 00140D58  38 63 FA C8 */	addi r3, r3, -1336
/* 80143DFC 00140D5C  48 00 13 E4 */	b animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent

.global "@696@viewGetScale__5BTekiFv"
"@696@viewGetScale__5BTekiFv":
/* 80143E00 00140D60  38 84 FD 48 */	addi r4, r4, -696
/* 80143E04 00140D64  48 00 02 3C */	b viewGetScale__5BTekiFv

.global "@696@viewGetHeight__5BTekiFv"
"@696@viewGetHeight__5BTekiFv":
/* 80143E08 00140D68  38 63 FD 48 */	addi r3, r3, -696
/* 80143E0C 00140D6C  48 00 02 68 */	b viewGetHeight__5BTekiFv

.global "@696@viewGetBottomRadius__5BTekiFv"
"@696@viewGetBottomRadius__5BTekiFv":
/* 80143E10 00140D70  38 63 FD 48 */	addi r3, r3, -696
/* 80143E14 00140D74  48 00 02 48 */	b viewGetBottomRadius__5BTekiFv

.global "@696@viewDoAnimation__5BTekiFv"
"@696@viewDoAnimation__5BTekiFv":
/* 80143E18 00140D78  38 63 FD 48 */	addi r3, r3, -696
/* 80143E1C 00140D7C  48 00 01 AC */	b viewDoAnimation__5BTekiFv

.global "@696@viewFinishMotion__5BTekiFv"
"@696@viewFinishMotion__5BTekiFv":
/* 80143E20 00140D80  38 63 FD 48 */	addi r3, r3, -696
/* 80143E24 00140D84  48 00 01 D0 */	b viewFinishMotion__5BTekiFv

.global "@696@viewSetMotionSpeed__5BTekiFf"
"@696@viewSetMotionSpeed__5BTekiFf":
/* 80143E28 00140D88  38 63 FD 48 */	addi r3, r3, -696
/* 80143E2C 00140D8C  48 00 01 94 */	b viewSetMotionSpeed__5BTekiFf

.global "@696@viewStartTrembleMotion__5BTekiFf"
"@696@viewStartTrembleMotion__5BTekiFf":
/* 80143E30 00140D90  38 63 FD 48 */	addi r3, r3, -696
/* 80143E34 00140D94  48 00 01 28 */	b viewStartTrembleMotion__5BTekiFf

.global "@696@viewDraw__5BTekiFR8GraphicsR8Matrix4f"
"@696@viewDraw__5BTekiFR8GraphicsR8Matrix4f":
/* 80143E38 00140D98  38 63 FD 48 */	addi r3, r3, -696
/* 80143E3C 00140D9C  48 00 02 50 */	b viewDraw__5BTekiFR8GraphicsR8Matrix4f

.global "@696@viewKill__5BTekiFv"
"@696@viewKill__5BTekiFv":
/* 80143E40 00140DA0  38 63 FD 48 */	addi r3, r3, -696
/* 80143E44 00140DA4  48 00 02 EC */	b viewKill__5BTekiFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802CCAE0:
	.asciz "teki.cpp"
.balign 4
lbl_802CCAEC:
	.asciz "PelletView"
.balign 4
lbl_802CCAF8:
	.asciz "PaniAnimKeyListener"
.balign 4
lbl_802CCB0C:
	.asciz "EventTalker"
.balign 4
lbl_802CCB18:
	.asciz "RefCountable"
.balign 4
lbl_802CCB28:
	.asciz "Creature"
.balign 4
lbl_802CCB34:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
lbl_802CCB48:
	.4byte __RTTI__10PelletView
	.4byte 0x2B8
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x454
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
lbl_802CCB74:
	.4byte __RTTI__10PelletView
	.4byte 0x2B8
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x46C
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__5BTeki
	.4byte 0
	.4byte 0
lbl_802CCBA8:
	.4byte __RTTI__10PelletView
	.4byte 0x2B8
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x538
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__5BTeki
	.4byte 0
	.4byte __RTTI__5NTeki
	.4byte 0
	.4byte 0
lbl_802CCBE4:
	.4byte __RTTI__10PelletView
	.4byte 0x2B8
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x538
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__5BTeki
	.4byte 0
	.4byte __RTTI__5NTeki
	.4byte 0
	.4byte __RTTI__5YTeki
	.4byte 0
	.4byte 0
.global __vt__4Teki
__vt__4Teki:
	.4byte __RTTI__4Teki
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__5BTekiFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8CreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__5BTekiFi
	.4byte getiMass__5BTekiFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__5BTekiFP11CreatureInf
	.4byte doRestore__5BTekiFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__5BTekiFv
	.4byte isVisible__5BTekiFv
	.4byte isOrganic__5BTekiFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__5BTekiFv
	.4byte isAlive__5BTekiFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__5BTekiFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__5BTekiFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__5BTekiFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__5BTekiFR9CollEvent
	.4byte bounceCallback__5BTekiFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__5BTekiFR5PlaneP13DynCollObject
	.4byte offwallCallback__8CreatureFP13DynCollObject
	.4byte stickCallback__8CreatureFP8Creature
	.4byte offstickCallback__8CreatureFP8Creature
	.4byte stickToCallback__8CreatureFP8Creature
	.4byte dump__5BTekiFv
	.4byte startWaterEffect__8CreatureFv
	.4byte finishWaterEffect__8CreatureFv
	.4byte isRopable__8CreatureFv
	.4byte mayIstick__8CreatureFv
	.4byte getFormationPri__8CreatureFv
	.4byte update__5BTekiFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__5BTekiFR8Graphics
	.4byte refresh2d__5BTekiFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__5BTekiFv
	.4byte doAnimation__5BTekiFv
	.4byte doKill__5YTekiFv
	.4byte exitCourse__5YTekiFv
	.4byte __RTTI__4Teki
	.4byte 0xFFFFFD48
	.4byte viewInit__10PelletViewFv
	.4byte "@696@viewKill__5BTekiFv"
	.4byte "@696@viewDraw__5BTekiFR8GraphicsR8Matrix4f"
	.4byte "@696@viewStartTrembleMotion__5BTekiFf"
	.4byte viewStartExplodeMotion__10PelletViewFf
	.4byte "@696@viewSetMotionSpeed__5BTekiFf"
	.4byte "@696@viewFinishMotion__5BTekiFv"
	.4byte "@696@viewDoAnimation__5BTekiFv"
	.4byte "@696@viewGetBottomRadius__5BTekiFv"
	.4byte "@696@viewGetHeight__5BTekiFv"
	.4byte "@696@viewGetScale__5BTekiFv"
	.4byte viewStartTrembleMotion__5BTekiFf
	.4byte viewSetMotionSpeed__5BTekiFf
	.4byte viewDoAnimation__5BTekiFv
	.4byte viewFinishMotion__5BTekiFv
	.4byte viewDraw__5BTekiFR8GraphicsR8Matrix4f
	.4byte viewKill__5BTekiFv
	.4byte viewGetScale__5BTekiFv
	.4byte viewGetBottomRadius__5BTekiFv
	.4byte viewGetHeight__5BTekiFv
	.4byte init__5YTekiFi
	.4byte reset__5BTekiFv
	.4byte startMotion__5BTekiFi
	.4byte die__5BTekiFv
	.4byte updateTimers__5BTekiFv
	.4byte gravitate__5BTekiFf
	.4byte animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent
	.4byte getTekiCollisionSize__5BTekiFv
	.4byte makeDamaged__5BTekiFv
	.4byte startDamageMotion__5BTekiFff
	.4byte generateTeki__5BTekiFi
	.4byte spawnTeki__5BTekiFi
	.4byte shootBall__5BTekiFR8Creature
	.4byte eventPerformed__5BTekiFR9TekiEvent
	.4byte interact__5BTekiFR18TekiInteractionKey
	.4byte interactDefault__5BTekiFR18TekiInteractionKey
	.4byte drawDefault__5BTekiFR8Graphics
	.4byte drawTekiShape__5BTekiFR8Graphics
	.4byte drawTekiDebugInfo__5BTekiFR8Graphics
	.4byte drawTekiDebugInfoDefault__5BTekiFR8Graphics
	.4byte playTableSound__5BTekiFi
	.4byte playSound__5BTekiFi
	.4byte stopSound__5BTekiFi
	.4byte createTekiEffect__5BTekiFi
	.4byte setTekiOption__5BTekiFi
	.4byte clearTekiOption__5BTekiFi
	.4byte setTekiOptions__5BTekiFi
	.4byte clearTekiOptions__5BTekiFv
	.4byte setAnimationKeyOption__5BTekiFi
	.4byte clearAnimationKeyOption__5BTekiFi
	.4byte setAnimationKeyOptions__5BTekiFi
	.4byte clearAnimationKeyOptions__5BTekiFv
	.4byte dieSoon__5BTekiFv
	.4byte becomeCorpse__5BTekiFv
	.4byte __RTTI__4Teki
	.4byte 0xFFFFFAC8
	.4byte "@1336@4@animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent"
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E4298:
	.asciz "Teki"
.balign 4
__RTTI__10PelletView:
	.4byte lbl_802CCAEC
	.4byte 0
__RTTI__19PaniAnimKeyListener:
	.4byte lbl_802CCAF8
	.4byte 0
__RTTI__11EventTalker:
	.4byte lbl_802CCB0C
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802CCB18
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802CCB28
	.4byte lbl_802CCB34
.balign 4
lbl_803E42C8:
	.asciz "BTeki"
.balign 4
__RTTI__5BTeki:
	.4byte lbl_803E42C8
	.4byte lbl_802CCB48
.balign 4
lbl_803E42D8:
	.asciz "NTeki"
.balign 4
__RTTI__5NTeki:
	.4byte lbl_803E42D8
	.4byte lbl_802CCB74
.balign 4
lbl_803E42E8:
	.asciz "YTeki"
.balign 4
__RTTI__5YTeki:
	.4byte lbl_803E42E8
	.4byte lbl_802CCBA8
__RTTI__4Teki:
	.4byte lbl_803E4298
	.4byte lbl_802CCBE4

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EA948:
	.float 0.0
