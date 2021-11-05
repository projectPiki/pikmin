.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 801368E4 00133844  90 1C 00 08 */	stw r0, 8(r28)
/* 801368E8 00133848  90 7C 00 04 */	stw r3, 4(r28)
lbl_801368EC:
/* 801368EC 0013384C  38 60 00 18 */	li r3, 0x18
/* 801368F0 00133850  4B F1 07 15 */	bl alloc__6SystemFUl
/* 801368F4 00133854  3B A3 00 00 */	addi r29, r3, 0
/* 801368F8 00133858  7F A0 EB 79 */	or. r0, r29, r29
/* 801368FC 0013385C  41 82 00 5C */	beq lbl_80136958
/* 80136900 00133860  80 96 00 84 */	lwz r4, 0x84(r22)
/* 80136904 00133864  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136908 00133868  3C C0 80 2D */	lis r6, __vt__14TaiTimerAction@ha
/* 8013690C 0013386C  80 84 00 04 */	lwz r4, 4(r4)
/* 80136910 00133870  3C A0 80 2D */	lis r5, __vt__22TaiStartingTimerAction@ha
/* 80136914 00133874  38 63 66 20 */	addi r3, r3, __vt__9TaiAction@l
/* 80136918 00133878  80 84 00 00 */	lwz r4, 0(r4)
/* 8013691C 0013387C  38 00 00 01 */	li r0, 1
/* 80136920 00133880  38 E6 CA 28 */	addi r7, r6, __vt__14TaiTimerAction@l
/* 80136924 00133884  C0 24 00 E0 */	lfs f1, 0xe0(r4)
/* 80136928 00133888  38 C0 00 00 */	li r6, 0
/* 8013692C 0013388C  C0 04 00 DC */	lfs f0, 0xdc(r4)
/* 80136930 00133890  38 85 C9 90 */	addi r4, r5, __vt__22TaiStartingTimerAction@l
/* 80136934 00133894  90 7D 00 04 */	stw r3, 4(r29)
/* 80136938 00133898  90 1D 00 00 */	stw r0, 0(r29)
/* 8013693C 0013389C  90 FD 00 04 */	stw r7, 4(r29)
/* 80136940 001338A0  90 DD 00 08 */	stw r6, 8(r29)
/* 80136944 001338A4  D0 1D 00 0C */	stfs f0, 0xc(r29)
/* 80136948 001338A8  C0 02 A4 CC */	lfs f0, lbl_803EA6CC@sda21(r2)
/* 8013694C 001338AC  D0 1D 00 10 */	stfs f0, 0x10(r29)
/* 80136950 001338B0  90 9D 00 04 */	stw r4, 4(r29)
/* 80136954 001338B4  D0 3D 00 14 */	stfs f1, 0x14(r29)
lbl_80136958:
/* 80136958 001338B8  38 60 00 18 */	li r3, 0x18
/* 8013695C 001338BC  4B F1 06 A9 */	bl alloc__6SystemFUl
/* 80136960 001338C0  3B C3 00 00 */	addi r30, r3, 0
/* 80136964 001338C4  7F C0 F3 79 */	or. r0, r30, r30
/* 80136968 001338C8  41 82 00 5C */	beq lbl_801369C4
/* 8013696C 001338CC  80 96 00 84 */	lwz r4, 0x84(r22)
/* 80136970 001338D0  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136974 001338D4  3C A0 80 2D */	lis r5, __vt__14TaiTimerAction@ha
/* 80136978 001338D8  80 84 00 04 */	lwz r4, 4(r4)
/* 8013697C 001338DC  3C E0 80 2D */	lis r7, __vt__22TaiStartingTimerAction@ha
/* 80136980 001338E0  38 63 66 20 */	addi r3, r3, __vt__9TaiAction@l
/* 80136984 001338E4  80 84 00 00 */	lwz r4, 0(r4)
/* 80136988 001338E8  38 00 00 03 */	li r0, 3
/* 8013698C 001338EC  38 C5 CA 28 */	addi r6, r5, __vt__14TaiTimerAction@l
/* 80136990 001338F0  C0 24 00 E8 */	lfs f1, 0xe8(r4)
/* 80136994 001338F4  38 A0 00 01 */	li r5, 1
/* 80136998 001338F8  C0 04 00 E4 */	lfs f0, 0xe4(r4)
/* 8013699C 001338FC  38 87 C9 90 */	addi r4, r7, __vt__22TaiStartingTimerAction@l
/* 801369A0 00133900  90 7E 00 04 */	stw r3, 4(r30)
/* 801369A4 00133904  90 1E 00 00 */	stw r0, 0(r30)
/* 801369A8 00133908  90 DE 00 04 */	stw r6, 4(r30)
/* 801369AC 0013390C  90 BE 00 08 */	stw r5, 8(r30)
/* 801369B0 00133910  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 801369B4 00133914  C0 02 A4 CC */	lfs f0, lbl_803EA6CC@sda21(r2)
/* 801369B8 00133918  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 801369BC 0013391C  90 9E 00 04 */	stw r4, 4(r30)
/* 801369C0 00133920  D0 3E 00 14 */	stfs f1, 0x14(r30)
lbl_801369C4:
/* 801369C4 00133924  38 60 00 0C */	li r3, 0xc
/* 801369C8 00133928  4B F1 06 3D */	bl alloc__6SystemFUl
/* 801369CC 0013392C  3B E3 00 00 */	addi r31, r3, 0
/* 801369D0 00133930  7F E3 FB 79 */	or. r3, r31, r31
/* 801369D4 00133934  41 82 00 0C */	beq lbl_801369E0
/* 801369D8 00133938  38 80 00 09 */	li r4, 9
/* 801369DC 0013393C  4B FF 06 BD */	bl __ct__8TaiStateFi
lbl_801369E0:
/* 801369E0 00133940  38 00 00 00 */	li r0, 0
/* 801369E4 00133944  80 7F 00 08 */	lwz r3, 8(r31)
/* 801369E8 00133948  54 00 10 3A */	slwi r0, r0, 2
/* 801369EC 0013394C  7D C3 01 2E */	stwx r14, r3, r0
/* 801369F0 00133950  38 80 00 01 */	li r4, 1
/* 801369F4 00133954  38 00 00 02 */	li r0, 2
/* 801369F8 00133958  80 7F 00 08 */	lwz r3, 8(r31)
/* 801369FC 0013395C  54 85 10 3A */	slwi r5, r4, 2
/* 80136A00 00133960  38 80 00 03 */	li r4, 3
/* 80136A04 00133964  7F 03 29 2E */	stwx r24, r3, r5
/* 80136A08 00133968  38 E0 00 04 */	li r7, 4
/* 80136A0C 0013396C  38 A0 00 05 */	li r5, 5
/* 80136A10 00133970  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136A14 00133974  54 00 10 3A */	slwi r0, r0, 2
/* 80136A18 00133978  38 C0 00 06 */	li r6, 6
/* 80136A1C 0013397C  7E A3 01 2E */	stwx r21, r3, r0
/* 80136A20 00133980  38 00 00 07 */	li r0, 7
/* 80136A24 00133984  39 20 00 08 */	li r9, 8
/* 80136A28 00133988  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136A2C 0013398C  54 84 10 3A */	slwi r4, r4, 2
/* 80136A30 00133990  54 E8 10 3A */	slwi r8, r7, 2
/* 80136A34 00133994  7E 83 21 2E */	stwx r20, r3, r4
/* 80136A38 00133998  54 A5 10 3A */	slwi r5, r5, 2
/* 80136A3C 0013399C  54 C7 10 3A */	slwi r7, r6, 2
/* 80136A40 001339A0  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136A44 001339A4  54 00 10 3A */	slwi r0, r0, 2
/* 80136A48 001339A8  55 26 10 3A */	slwi r6, r9, 2
/* 80136A4C 001339AC  7F 43 41 2E */	stwx r26, r3, r8
/* 80136A50 001339B0  38 60 00 18 */	li r3, 0x18
/* 80136A54 001339B4  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136A58 001339B8  7E E4 29 2E */	stwx r23, r4, r5
/* 80136A5C 001339BC  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136A60 001339C0  7F A4 39 2E */	stwx r29, r4, r7
/* 80136A64 001339C4  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136A68 001339C8  7F C4 01 2E */	stwx r30, r4, r0
/* 80136A6C 001339CC  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136A70 001339D0  7F 84 31 2E */	stwx r28, r4, r6
/* 80136A74 001339D4  80 99 00 08 */	lwz r4, 8(r25)
/* 80136A78 001339D8  93 E4 00 08 */	stw r31, 8(r4)
/* 80136A7C 001339DC  4B F1 05 89 */	bl alloc__6SystemFUl
/* 80136A80 001339E0  3B E3 00 00 */	addi r31, r3, 0
/* 80136A84 001339E4  7F E0 FB 79 */	or. r0, r31, r31
/* 80136A88 001339E8  41 82 00 5C */	beq lbl_80136AE4
/* 80136A8C 001339EC  80 96 00 84 */	lwz r4, 0x84(r22)
/* 80136A90 001339F0  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136A94 001339F4  3C C0 80 2D */	lis r6, __vt__14TaiTimerAction@ha
/* 80136A98 001339F8  80 84 00 04 */	lwz r4, 4(r4)
/* 80136A9C 001339FC  3C A0 80 2D */	lis r5, __vt__22TaiStartingTimerAction@ha
/* 80136AA0 00133A00  38 63 66 20 */	addi r3, r3, __vt__9TaiAction@l
/* 80136AA4 00133A04  80 84 00 00 */	lwz r4, 0(r4)
/* 80136AA8 00133A08  38 00 00 01 */	li r0, 1
/* 80136AAC 00133A0C  38 E6 CA 28 */	addi r7, r6, __vt__14TaiTimerAction@l
/* 80136AB0 00133A10  C0 24 00 F0 */	lfs f1, 0xf0(r4)
/* 80136AB4 00133A14  38 C0 00 00 */	li r6, 0
/* 80136AB8 00133A18  C0 04 00 EC */	lfs f0, 0xec(r4)
/* 80136ABC 00133A1C  38 85 C9 90 */	addi r4, r5, __vt__22TaiStartingTimerAction@l

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x6d697a75
  .4byte 0x4974656d
  .4byte 0x2e637070
  .4byte 0
  .4byte 0x6d61746f
  .4byte 0x4974656d
  .4byte 0
  .4byte 0x4d697a75
  .4byte 0x4974656d
  .4byte 0
  .4byte 0x50616e69
  .4byte 0x416e696d
  .4byte 0x4b65794c
  .4byte 0x69737465
  .4byte 0x6e657200
  .4byte 0x4576656e
  .4byte 0x7454616c
  .4byte 0x6b657200
  .4byte 0x52656643
  .4byte 0x6f756e74
  .4byte 0x61626c65
  .4byte 0
  .4byte 0x43726561
  .4byte 0x74757265
  .4byte 0
  .4byte 0x803e1ef0
  .4byte 0x8
  .4byte 0x803e1ef8
  .4byte 0
  .4byte 0
  .4byte 0x41494372
  .4byte 0x65617475
  .4byte 0x72650000
  .4byte 0x803e1ee8
  .4byte 0x2b8
  .4byte 0x803e1ef0
  .4byte 0x8
  .4byte 0x803e1ef8
  .4byte 0
  .4byte 0x803e1f00
  .4byte 0
  .4byte 0
  .4byte 0x4974656d
  .4byte 0x43726561
  .4byte 0x74757265
  .4byte 0
  .4byte 0x803e1ee8
  .4byte 0x2b8
  .4byte 0x803e1ef0
  .4byte 0x8
  .4byte 0x803e1ef8
  .4byte 0
  .4byte 0x803e1f00
  .4byte 0
  .4byte 0x803e1f08
  .4byte 0
  .4byte 0
  .4byte 0x803e1ee8
  .4byte 0x2b8
  .4byte 0x803e1ef0
  .4byte 0x8
  .4byte 0x803e1ef8
  .4byte 0
  .4byte 0x803e1f00
  .4byte 0
  .4byte 0x803e1f08
  .4byte 0
  .4byte 0x803e1f10
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
  .4byte 0xfffffd48
  .4byte 0x8007df54
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
  .4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global __RTTI__18NaviDemoSunsetGoal
__RTTI__18NaviDemoSunsetGoal:
  .4byte 0x802bf1dc
  .4byte 0x802bf2ec
.global __RTTI__19NaviDemoSunsetStart
__RTTI__19NaviDemoSunsetStart:
  .4byte 0x802bf484
  .4byte 0x802bf498
  .4byte 0x46756c63
  .4byte 0x72756d00
.global __RTTI__7Fulcrum
__RTTI__7Fulcrum:
  .4byte 0x803e1ec8
  .4byte 0x802bf630
.global __RTTI__11BombGenItem
__RTTI__11BombGenItem:
  .4byte 0x802bf7c8
  .4byte 0x802bf7d4
.global __RTTI__8ItemBall
__RTTI__8ItemBall:
  .4byte 0x802bfac8
  .4byte 0x802bfad4
  .4byte 0x802bfc90
  .4byte 0
