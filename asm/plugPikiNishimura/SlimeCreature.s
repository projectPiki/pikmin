.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__13SlimeCreatureFP12CreatureProp
__ct__13SlimeCreatureFP12CreatureProp:
/* 8016B278 001681D8  7C 08 02 A6 */	mflr r0
/* 8016B27C 001681DC  90 01 00 04 */	stw r0, 4(r1)
/* 8016B280 001681E0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8016B284 001681E4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8016B288 001681E8  7C 7F 1B 78 */	mr r31, r3
/* 8016B28C 001681EC  4B F1 FC 4D */	bl __ct__8CreatureFP12CreatureProp
/* 8016B290 001681F0  3C 60 80 2D */	lis r3, __vt__13SlimeCreature@ha
/* 8016B294 001681F4  38 03 FF 94 */	addi r0, r3, __vt__13SlimeCreature@l
/* 8016B298 001681F8  90 1F 00 00 */	stw r0, 0(r31)
/* 8016B29C 001681FC  3C 60 80 09 */	lis r3, __ct__10SearchDataFv@ha
/* 8016B2A0 00168200  38 83 A7 F8 */	addi r4, r3, __ct__10SearchDataFv@l
/* 8016B2A4 00168204  C0 02 AB F8 */	lfs f0, lbl_803EADF8@sda21(r2)
/* 8016B2A8 00168208  38 7F 02 C8 */	addi r3, r31, 0x2c8
/* 8016B2AC 0016820C  38 A0 00 00 */	li r5, 0
/* 8016B2B0 00168210  D0 1F 02 C4 */	stfs f0, 0x2c4(r31)
/* 8016B2B4 00168214  38 C0 00 0C */	li r6, 0xc
/* 8016B2B8 00168218  38 E0 00 03 */	li r7, 3
/* 8016B2BC 0016821C  D0 1F 02 C0 */	stfs f0, 0x2c0(r31)
/* 8016B2C0 00168220  D0 1F 02 BC */	stfs f0, 0x2bc(r31)
/* 8016B2C4 00168224  48 0A 97 AD */	bl __construct_array
/* 8016B2C8 00168228  38 7F 01 B8 */	addi r3, r31, 0x1b8
/* 8016B2CC 0016822C  38 9F 02 C8 */	addi r4, r31, 0x2c8
/* 8016B2D0 00168230  38 A0 00 03 */	li r5, 3
/* 8016B2D4 00168234  4B F7 89 AD */	bl init__12SearchBufferFP10SearchDatai
/* 8016B2D8 00168238  7F E3 FB 78 */	mr r3, r31
/* 8016B2DC 0016823C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8016B2E0 00168240  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8016B2E4 00168244  38 21 00 18 */	addi r1, r1, 0x18
/* 8016B2E8 00168248  7C 08 03 A6 */	mtlr r0
/* 8016B2EC 0016824C  4E 80 00 20 */	blr 

.global init__13SlimeCreatureFR8Vector3fP5Slime
init__13SlimeCreatureFR8Vector3fP5Slime:
/* 8016B2F0 00168250  7C 08 02 A6 */	mflr r0
/* 8016B2F4 00168254  90 01 00 04 */	stw r0, 4(r1)
/* 8016B2F8 00168258  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8016B2FC 0016825C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8016B300 00168260  7C 7F 1B 78 */	mr r31, r3
/* 8016B304 00168264  90 A3 02 B8 */	stw r5, 0x2b8(r3)
/* 8016B308 00168268  C0 02 AB FC */	lfs f0, lbl_803EADFC@sda21(r2)
/* 8016B30C 0016826C  D0 1F 02 70 */	stfs f0, 0x270(r31)
/* 8016B310 00168270  80 A4 00 00 */	lwz r5, 0(r4)
/* 8016B314 00168274  80 04 00 04 */	lwz r0, 4(r4)
/* 8016B318 00168278  90 BF 00 94 */	stw r5, 0x94(r31)
/* 8016B31C 0016827C  90 1F 00 98 */	stw r0, 0x98(r31)
/* 8016B320 00168280  80 04 00 08 */	lwz r0, 8(r4)
/* 8016B324 00168284  90 1F 00 9C */	stw r0, 0x9c(r31)
/* 8016B328 00168288  80 A4 00 00 */	lwz r5, 0(r4)
/* 8016B32C 0016828C  80 04 00 04 */	lwz r0, 4(r4)
/* 8016B330 00168290  90 BF 02 BC */	stw r5, 0x2bc(r31)
/* 8016B334 00168294  90 1F 02 C0 */	stw r0, 0x2c0(r31)
/* 8016B338 00168298  80 04 00 08 */	lwz r0, 8(r4)
/* 8016B33C 0016829C  90 1F 02 C4 */	stw r0, 0x2c4(r31)
/* 8016B340 001682A0  4B F1 F7 45 */	bl init__8CreatureFv
/* 8016B344 001682A4  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 8016B348 001682A8  60 00 00 40 */	ori r0, r0, 0x40
/* 8016B34C 001682AC  90 1F 00 C8 */	stw r0, 0xc8(r31)
/* 8016B350 001682B0  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 8016B354 001682B4  54 00 07 FA */	rlwinm r0, r0, 0, 0x1f, 0x1d
/* 8016B358 001682B8  90 1F 00 C8 */	stw r0, 0xc8(r31)
/* 8016B35C 001682BC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8016B360 001682C0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8016B364 001682C4  38 21 00 20 */	addi r1, r1, 0x20
/* 8016B368 001682C8  7C 08 03 A6 */	mtlr r0
/* 8016B36C 001682CC  4E 80 00 20 */	blr 

.global getSize__13SlimeCreatureFv
getSize__13SlimeCreatureFv:
/* 8016B370 001682D0  C0 22 AB FC */	lfs f1, lbl_803EADFC@sda21(r2)
/* 8016B374 001682D4  4E 80 00 20 */	blr 

.global getiMass__13SlimeCreatureFv
getiMass__13SlimeCreatureFv:
/* 8016B378 001682D8  C0 22 AC 00 */	lfs f1, lbl_803EAE00@sda21(r2)
/* 8016B37C 001682DC  4E 80 00 20 */	blr 

.global getCentre__13SlimeCreatureFv
getCentre__13SlimeCreatureFv:
/* 8016B380 001682E0  C0 04 00 94 */	lfs f0, 0x94(r4)
/* 8016B384 001682E4  D0 03 00 00 */	stfs f0, 0(r3)
/* 8016B388 001682E8  C0 04 00 98 */	lfs f0, 0x98(r4)
/* 8016B38C 001682EC  D0 03 00 04 */	stfs f0, 4(r3)
/* 8016B390 001682F0  C0 04 00 9C */	lfs f0, 0x9c(r4)
/* 8016B394 001682F4  D0 03 00 08 */	stfs f0, 8(r3)
/* 8016B398 001682F8  4E 80 00 20 */	blr 

.global doKill__13SlimeCreatureFv
doKill__13SlimeCreatureFv:
/* 8016B39C 001682FC  7C 08 02 A6 */	mflr r0
/* 8016B3A0 00168300  38 80 00 00 */	li r4, 0
/* 8016B3A4 00168304  90 01 00 04 */	stw r0, 4(r1)
/* 8016B3A8 00168308  94 21 FF F8 */	stwu r1, -8(r1)
/* 8016B3AC 0016830C  4B F1 F9 35 */	bl kill__8CreatureFb
/* 8016B3B0 00168310  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8016B3B4 00168314  38 21 00 08 */	addi r1, r1, 8
/* 8016B3B8 00168318  7C 08 03 A6 */	mtlr r0
/* 8016B3BC 0016831C  4E 80 00 20 */	blr 

.global isAlive__13SlimeCreatureFv
isAlive__13SlimeCreatureFv:
/* 8016B3C0 00168320  7C 08 02 A6 */	mflr r0
/* 8016B3C4 00168324  90 01 00 04 */	stw r0, 4(r1)
/* 8016B3C8 00168328  94 21 FF F8 */	stwu r1, -8(r1)
/* 8016B3CC 0016832C  80 63 02 B8 */	lwz r3, 0x2b8(r3)
/* 8016B3D0 00168330  81 83 00 00 */	lwz r12, 0(r3)
/* 8016B3D4 00168334  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 8016B3D8 00168338  7D 88 03 A6 */	mtlr r12
/* 8016B3DC 0016833C  4E 80 00 21 */	blrl 
/* 8016B3E0 00168340  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8016B3E4 00168344  38 21 00 08 */	addi r1, r1, 8
/* 8016B3E8 00168348  7C 08 03 A6 */	mtlr r0
/* 8016B3EC 0016834C  4E 80 00 20 */	blr 

.global isAtari__13SlimeCreatureFv
isAtari__13SlimeCreatureFv:
/* 8016B3F0 00168350  7C 08 02 A6 */	mflr r0
/* 8016B3F4 00168354  90 01 00 04 */	stw r0, 4(r1)
/* 8016B3F8 00168358  94 21 FF F8 */	stwu r1, -8(r1)
/* 8016B3FC 0016835C  80 63 02 B8 */	lwz r3, 0x2b8(r3)
/* 8016B400 00168360  81 83 00 00 */	lwz r12, 0(r3)
/* 8016B404 00168364  81 8C 00 84 */	lwz r12, 0x84(r12)
/* 8016B408 00168368  7D 88 03 A6 */	mtlr r12
/* 8016B40C 0016836C  4E 80 00 21 */	blrl 
/* 8016B410 00168370  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8016B414 00168374  38 21 00 08 */	addi r1, r1, 8
/* 8016B418 00168378  7C 08 03 A6 */	mtlr r0
/* 8016B41C 0016837C  4E 80 00 20 */	blr 

.global ignoreAtari__13SlimeCreatureFP8Creature
ignoreAtari__13SlimeCreatureFP8Creature:
/* 8016B420 00168380  80 84 00 6C */	lwz r4, 0x6c(r4)
/* 8016B424 00168384  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 8016B428 00168388  7C 04 00 00 */	cmpw r4, r0
/* 8016B42C 0016838C  40 82 00 0C */	bne lbl_8016B438
/* 8016B430 00168390  38 60 00 01 */	li r3, 1
/* 8016B434 00168394  4E 80 00 20 */	blr 
lbl_8016B438:
/* 8016B438 00168398  38 60 00 00 */	li r3, 0
/* 8016B43C 0016839C  4E 80 00 20 */	blr 

.global doAI__13SlimeCreatureFv
doAI__13SlimeCreatureFv:
/* 8016B440 001683A0  4E 80 00 20 */	blr 

.global doAnimation__13SlimeCreatureFv
doAnimation__13SlimeCreatureFv:
/* 8016B444 001683A4  4E 80 00 20 */	blr 

.global update__13SlimeCreatureFv
update__13SlimeCreatureFv:
/* 8016B448 001683A8  7C 08 02 A6 */	mflr r0
/* 8016B44C 001683AC  90 01 00 04 */	stw r0, 4(r1)
/* 8016B450 001683B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8016B454 001683B4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8016B458 001683B8  7C 7F 1B 78 */	mr r31, r3
/* 8016B45C 001683BC  C0 02 AC 04 */	lfs f0, lbl_803EAE04@sda21(r2)
/* 8016B460 001683C0  C0 23 00 98 */	lfs f1, 0x98(r3)
/* 8016B464 001683C4  EC 01 00 28 */	fsubs f0, f1, f0
/* 8016B468 001683C8  D0 1F 00 98 */	stfs f0, 0x98(r31)
/* 8016B46C 001683CC  4B F2 1B 91 */	bl moveVelocity__8CreatureFv
/* 8016B470 001683D0  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8016B474 001683D4  7F E3 FB 78 */	mr r3, r31
/* 8016B478 001683D8  C0 24 02 8C */	lfs f1, 0x28c(r4)
/* 8016B47C 001683DC  4B F2 31 61 */	bl moveNew__8CreatureFf
/* 8016B480 001683E0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8016B484 001683E4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8016B488 001683E8  38 21 00 20 */	addi r1, r1, 0x20
/* 8016B48C 001683EC  7C 08 03 A6 */	mtlr r0
/* 8016B490 001683F0  4E 80 00 20 */	blr 

.global refresh__13SlimeCreatureFR8Graphics
refresh__13SlimeCreatureFR8Graphics:
/* 8016B494 001683F4  4E 80 00 20 */	blr 

.global setCentre__13SlimeCreatureFR8Vector3f
setCentre__13SlimeCreatureFR8Vector3f:
/* 8016B498 001683F8  4E 80 00 20 */	blr 

.global isFixed__13SlimeCreatureFv
isFixed__13SlimeCreatureFv:
/* 8016B49C 001683FC  38 60 00 01 */	li r3, 1
/* 8016B4A0 00168400  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802CFF18:
	.asciz "SlimeCreature.cpp"
.balign 4
lbl_802CFF2C:
	.asciz "SlimeCreature"
.balign 4
lbl_802CFF3C:
	.asciz "EventTalker"
.balign 4
lbl_802CFF48:
	.asciz "RefCountable"
.balign 4
lbl_802CFF58:
	.asciz "Creature"
.balign 4
lbl_802CFF64:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802CFF78:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__13SlimeCreature
__vt__13SlimeCreature:
	.4byte __RTTI__13SlimeCreature
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8CreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__13SlimeCreatureFv
	.4byte getSize__13SlimeCreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__13SlimeCreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__13SlimeCreatureFR8Vector3f
	.4byte getShadowSize__8CreatureFv
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__13SlimeCreatureFv
	.4byte isAlive__13SlimeCreatureFv
	.4byte isFixed__13SlimeCreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__13SlimeCreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__8CreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__8CreatureFR9CollEvent
	.4byte bounceCallback__8CreatureFv
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
	.4byte update__13SlimeCreatureFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__13SlimeCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__13SlimeCreatureFv
	.4byte doAnimation__13SlimeCreatureFv
	.4byte doKill__13SlimeCreatureFv
	.4byte exitCourse__8CreatureFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__11EventTalker:
	.4byte lbl_802CFF3C
	.4byte 0x00000000
__RTTI__12RefCountable:
	.4byte lbl_802CFF48
	.4byte 0x00000000
__RTTI__8Creature:
	.4byte lbl_802CFF58
	.4byte lbl_802CFF64
__RTTI__13SlimeCreature:
	.4byte lbl_802CFF2C
	.4byte lbl_802CFF78

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EADF8:
	.float 0.0
lbl_803EADFC:
	.float 20.0
lbl_803EAE00:
	.float 0.01
lbl_803EAE04:
	.float 0.5
