.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__7KeyItemFP12CreaturePropP5Shape
__ct__7KeyItemFP12CreaturePropP5Shape:
/* 800ED204 000EA164  7C 08 02 A6 */	mflr r0
/* 800ED208 000EA168  90 01 00 04 */	stw r0, 4(r1)
/* 800ED20C 000EA16C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800ED210 000EA170  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800ED214 000EA174  3B E5 00 00 */	addi r31, r5, 0
/* 800ED218 000EA178  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800ED21C 000EA17C  3B C3 00 00 */	addi r30, r3, 0
/* 800ED220 000EA180  4B F9 DC B9 */	bl __ct__8CreatureFP12CreatureProp
/* 800ED224 000EA184  3C 60 80 2C */	lis r3, __vt__7KeyItem@ha
/* 800ED228 000EA188  38 03 D3 20 */	addi r0, r3, __vt__7KeyItem@l
/* 800ED22C 000EA18C  3C 60 80 09 */	lis r3, __ct__10SearchDataFv@ha
/* 800ED230 000EA190  90 1E 00 00 */	stw r0, 0(r30)
/* 800ED234 000EA194  38 83 A7 F8 */	addi r4, r3, __ct__10SearchDataFv@l
/* 800ED238 000EA198  38 7E 02 BC */	addi r3, r30, 0x2bc
/* 800ED23C 000EA19C  38 A0 00 00 */	li r5, 0
/* 800ED240 000EA1A0  38 C0 00 0C */	li r6, 0xc
/* 800ED244 000EA1A4  38 E0 00 03 */	li r7, 3
/* 800ED248 000EA1A8  48 12 78 29 */	bl __construct_array
/* 800ED24C 000EA1AC  93 FE 02 E0 */	stw r31, 0x2e0(r30)
/* 800ED250 000EA1B0  38 00 00 04 */	li r0, 4
/* 800ED254 000EA1B4  38 7E 01 B8 */	addi r3, r30, 0x1b8
/* 800ED258 000EA1B8  90 1E 00 68 */	stw r0, 0x68(r30)
/* 800ED25C 000EA1BC  38 9E 02 BC */	addi r4, r30, 0x2bc
/* 800ED260 000EA1C0  38 A0 00 03 */	li r5, 3
/* 800ED264 000EA1C4  4B FF 6A 1D */	bl init__12SearchBufferFP10SearchDatai
/* 800ED268 000EA1C8  80 7E 00 C8 */	lwz r3, 0xc8(r30)
/* 800ED26C 000EA1CC  38 80 00 03 */	li r4, 3
/* 800ED270 000EA1D0  38 00 00 02 */	li r0, 2
/* 800ED274 000EA1D4  54 63 05 EA */	rlwinm r3, r3, 0, 0x17, 0x15
/* 800ED278 000EA1D8  90 7E 00 C8 */	stw r3, 0xc8(r30)
/* 800ED27C 000EA1DC  7F C3 F3 78 */	mr r3, r30
/* 800ED280 000EA1E0  80 BE 00 C8 */	lwz r5, 0xc8(r30)
/* 800ED284 000EA1E4  60 A5 00 01 */	ori r5, r5, 1
/* 800ED288 000EA1E8  90 BE 00 C8 */	stw r5, 0xc8(r30)
/* 800ED28C 000EA1EC  90 9E 00 6C */	stw r4, 0x6c(r30)
/* 800ED290 000EA1F0  90 1E 02 B8 */	stw r0, 0x2b8(r30)
/* 800ED294 000EA1F4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800ED298 000EA1F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800ED29C 000EA1FC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800ED2A0 000EA200  38 21 00 20 */	addi r1, r1, 0x20
/* 800ED2A4 000EA204  7C 08 03 A6 */	mtlr r0
/* 800ED2A8 000EA208  4E 80 00 20 */	blr 

.global getSize__7KeyItemFv
getSize__7KeyItemFv:
/* 800ED2AC 000EA20C  C0 22 9A D8 */	lfs f1, lbl_803E9CD8@sda21(r2)
/* 800ED2B0 000EA210  4E 80 00 20 */	blr 

.global init__7KeyItemFR8Vector3f
init__7KeyItemFR8Vector3f:
/* 800ED2B4 000EA214  7C 08 02 A6 */	mflr r0
/* 800ED2B8 000EA218  90 01 00 04 */	stw r0, 4(r1)
/* 800ED2BC 000EA21C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800ED2C0 000EA220  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800ED2C4 000EA224  7C 7F 1B 78 */	mr r31, r3
/* 800ED2C8 000EA228  C0 02 9A DC */	lfs f0, lbl_803E9CDC@sda21(r2)
/* 800ED2CC 000EA22C  D0 03 00 7C */	stfs f0, 0x7c(r3)
/* 800ED2D0 000EA230  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 800ED2D4 000EA234  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 800ED2D8 000EA238  4B F9 D9 2D */	bl init__8CreatureFR8Vector3f
/* 800ED2DC 000EA23C  38 7F 01 B8 */	addi r3, r31, 0x1b8
/* 800ED2E0 000EA240  38 9F 02 BC */	addi r4, r31, 0x2bc
/* 800ED2E4 000EA244  38 A0 00 03 */	li r5, 3
/* 800ED2E8 000EA248  4B FF 69 99 */	bl init__12SearchBufferFP10SearchDatai
/* 800ED2EC 000EA24C  38 00 00 02 */	li r0, 2
/* 800ED2F0 000EA250  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800ED2F4 000EA254  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800ED2F8 000EA258  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800ED2FC 000EA25C  38 21 00 20 */	addi r1, r1, 0x20
/* 800ED300 000EA260  7C 08 03 A6 */	mtlr r0
/* 800ED304 000EA264  4E 80 00 20 */	blr 

.global startAI__7KeyItemFi
startAI__7KeyItemFi:
/* 800ED308 000EA268  38 00 00 00 */	li r0, 0
/* 800ED30C 000EA26C  90 03 02 B8 */	stw r0, 0x2b8(r3)
/* 800ED310 000EA270  4E 80 00 20 */	blr 

.global isVisible__7KeyItemFv
isVisible__7KeyItemFv:
/* 800ED314 000EA274  80 03 02 B8 */	lwz r0, 0x2b8(r3)
/* 800ED318 000EA278  38 60 00 00 */	li r3, 0
/* 800ED31C 000EA27C  2C 00 00 01 */	cmpwi r0, 1
/* 800ED320 000EA280  4D 82 00 20 */	beqlr 
/* 800ED324 000EA284  2C 00 00 02 */	cmpwi r0, 2
/* 800ED328 000EA288  4D 82 00 20 */	beqlr 
/* 800ED32C 000EA28C  38 60 00 01 */	li r3, 1
/* 800ED330 000EA290  4E 80 00 20 */	blr 

.global doKill__7KeyItemFv
doKill__7KeyItemFv:
/* 800ED334 000EA294  7C 08 02 A6 */	mflr r0
/* 800ED338 000EA298  7C 64 1B 78 */	mr r4, r3
/* 800ED33C 000EA29C  90 01 00 04 */	stw r0, 4(r1)
/* 800ED340 000EA2A0  38 00 00 01 */	li r0, 1
/* 800ED344 000EA2A4  94 21 FF F8 */	stwu r1, -8(r1)
/* 800ED348 000EA2A8  90 03 02 B8 */	stw r0, 0x2b8(r3)
/* 800ED34C 000EA2AC  80 6D 30 AC */	lwz r3, itemMgr@sda21(r13)
/* 800ED350 000EA2B0  81 83 00 00 */	lwz r12, 0(r3)
/* 800ED354 000EA2B4  81 8C 00 7C */	lwz r12, 0x7c(r12)
/* 800ED358 000EA2B8  7D 88 03 A6 */	mtlr r12
/* 800ED35C 000EA2BC  4E 80 00 21 */	blrl 
/* 800ED360 000EA2C0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800ED364 000EA2C4  38 21 00 08 */	addi r1, r1, 8
/* 800ED368 000EA2C8  7C 08 03 A6 */	mtlr r0
/* 800ED36C 000EA2CC  4E 80 00 20 */	blr 

.global update__7KeyItemFv
update__7KeyItemFv:
/* 800ED370 000EA2D0  7C 08 02 A6 */	mflr r0
/* 800ED374 000EA2D4  90 01 00 04 */	stw r0, 4(r1)
/* 800ED378 000EA2D8  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800ED37C 000EA2DC  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800ED380 000EA2E0  7C 7F 1B 78 */	mr r31, r3
/* 800ED384 000EA2E4  C0 43 00 70 */	lfs f2, 0x70(r3)
/* 800ED388 000EA2E8  C0 23 00 74 */	lfs f1, 0x74(r3)
/* 800ED38C 000EA2EC  EC 42 00 B2 */	fmuls f2, f2, f2
/* 800ED390 000EA2F0  C0 63 00 78 */	lfs f3, 0x78(r3)
/* 800ED394 000EA2F4  EC 21 00 72 */	fmuls f1, f1, f1
/* 800ED398 000EA2F8  C0 02 9A E0 */	lfs f0, lbl_803E9CE0@sda21(r2)
/* 800ED39C 000EA2FC  EC 63 00 F2 */	fmuls f3, f3, f3
/* 800ED3A0 000EA300  EC 22 08 2A */	fadds f1, f2, f1
/* 800ED3A4 000EA304  EC 83 08 2A */	fadds f4, f3, f1
/* 800ED3A8 000EA308  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 800ED3AC 000EA30C  40 81 00 5C */	ble .L_800ED408
/* 800ED3B0 000EA310  FC 20 20 34 */	frsqrte f1, f4
/* 800ED3B4 000EA314  C8 62 9A E8 */	lfd f3, lbl_803E9CE8@sda21(r2)
/* 800ED3B8 000EA318  C8 42 9A F0 */	lfd f2, lbl_803E9CF0@sda21(r2)
/* 800ED3BC 000EA31C  FC 01 00 72 */	fmul f0, f1, f1
/* 800ED3C0 000EA320  FC 23 00 72 */	fmul f1, f3, f1
/* 800ED3C4 000EA324  FC 04 00 32 */	fmul f0, f4, f0
/* 800ED3C8 000EA328  FC 02 00 28 */	fsub f0, f2, f0
/* 800ED3CC 000EA32C  FC 21 00 32 */	fmul f1, f1, f0
/* 800ED3D0 000EA330  FC 01 00 72 */	fmul f0, f1, f1
/* 800ED3D4 000EA334  FC 23 00 72 */	fmul f1, f3, f1
/* 800ED3D8 000EA338  FC 04 00 32 */	fmul f0, f4, f0
/* 800ED3DC 000EA33C  FC 02 00 28 */	fsub f0, f2, f0
/* 800ED3E0 000EA340  FC 21 00 32 */	fmul f1, f1, f0
/* 800ED3E4 000EA344  FC 01 00 72 */	fmul f0, f1, f1
/* 800ED3E8 000EA348  FC 23 00 72 */	fmul f1, f3, f1
/* 800ED3EC 000EA34C  FC 04 00 32 */	fmul f0, f4, f0
/* 800ED3F0 000EA350  FC 02 00 28 */	fsub f0, f2, f0
/* 800ED3F4 000EA354  FC 01 00 32 */	fmul f0, f1, f0
/* 800ED3F8 000EA358  FC 04 00 32 */	fmul f0, f4, f0
/* 800ED3FC 000EA35C  FC 00 00 18 */	frsp f0, f0
/* 800ED400 000EA360  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 800ED404 000EA364  C0 81 00 10 */	lfs f4, 0x10(r1)
.L_800ED408:
/* 800ED408 000EA368  C0 02 9B 00 */	lfs f0, lbl_803E9D00@sda21(r2)
/* 800ED40C 000EA36C  C0 42 9A FC */	lfs f2, lbl_803E9CFC@sda21(r2)
/* 800ED410 000EA370  EC 24 00 24 */	fdivs f1, f4, f0
/* 800ED414 000EA374  C0 62 9A F8 */	lfs f3, lbl_803E9CF8@sda21(r2)
/* 800ED418 000EA378  C0 02 9B 04 */	lfs f0, lbl_803E9D04@sda21(r2)
/* 800ED41C 000EA37C  EC 22 00 72 */	fmuls f1, f2, f1
/* 800ED420 000EA380  EC 23 08 2A */	fadds f1, f3, f1
/* 800ED424 000EA384  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800ED428 000EA388  FC 40 08 90 */	fmr f2, f1
/* 800ED42C 000EA38C  40 81 00 08 */	ble .L_800ED434
/* 800ED430 000EA390  FC 40 00 90 */	fmr f2, f0
.L_800ED434:
/* 800ED434 000EA394  C0 02 9B 08 */	lfs f0, lbl_803E9D08@sda21(r2)
/* 800ED438 000EA398  C0 3F 00 A0 */	lfs f1, 0xa0(r31)
/* 800ED43C 000EA39C  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800ED440 000EA3A0  EC 01 00 2A */	fadds f0, f1, f0
/* 800ED444 000EA3A4  D0 1F 00 A0 */	stfs f0, 0xa0(r31)
/* 800ED448 000EA3A8  C0 3F 00 A0 */	lfs f1, 0xa0(r31)
/* 800ED44C 000EA3AC  4B F4 B1 3D */	bl roundAng__Ff
/* 800ED450 000EA3B0  D0 3F 00 A0 */	stfs f1, 0xa0(r31)
/* 800ED454 000EA3B4  38 7F 00 40 */	addi r3, r31, 0x40
/* 800ED458 000EA3B8  38 9F 00 94 */	addi r4, r31, 0x94
/* 800ED45C 000EA3BC  4B FA 70 C5 */	bl updateGrid__8FastGridFRC8Vector3f
/* 800ED460 000EA3C0  7F E3 FB 78 */	mr r3, r31
/* 800ED464 000EA3C4  4B F9 E5 19 */	bl updateAI__8CreatureFv
/* 800ED468 000EA3C8  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800ED46C 000EA3CC  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800ED470 000EA3D0  38 21 00 28 */	addi r1, r1, 0x28
/* 800ED474 000EA3D4  7C 08 03 A6 */	mtlr r0
/* 800ED478 000EA3D8  4E 80 00 20 */	blr 

.global collisionCallback__7KeyItemFR9CollEvent
collisionCallback__7KeyItemFR9CollEvent:
/* 800ED47C 000EA3DC  4E 80 00 20 */	blr 

.global getiMass__7KeyItemFv
getiMass__7KeyItemFv:
/* 800ED480 000EA3E0  C0 22 9B 0C */	lfs f1, lbl_803E9D0C@sda21(r2)
/* 800ED484 000EA3E4  4E 80 00 20 */	blr 

.global refresh__7KeyItemFR8Graphics
refresh__7KeyItemFR8Graphics:
/* 800ED488 000EA3E8  7C 08 02 A6 */	mflr r0
/* 800ED48C 000EA3EC  90 01 00 04 */	stw r0, 4(r1)
/* 800ED490 000EA3F0  94 21 FF 58 */	stwu r1, -0xa8(r1)
/* 800ED494 000EA3F4  93 E1 00 A4 */	stw r31, 0xa4(r1)
/* 800ED498 000EA3F8  38 C1 00 10 */	addi r6, r1, 0x10
/* 800ED49C 000EA3FC  7C 9F 23 78 */	mr r31, r4
/* 800ED4A0 000EA400  93 C1 00 A0 */	stw r30, 0xa0(r1)
/* 800ED4A4 000EA404  7C 7E 1B 78 */	mr r30, r3
/* 800ED4A8 000EA408  38 9E 00 7C */	addi r4, r30, 0x7c
/* 800ED4AC 000EA40C  C0 42 9B 10 */	lfs f2, lbl_803E9D10@sda21(r2)
/* 800ED4B0 000EA410  38 BE 00 88 */	addi r5, r30, 0x88
/* 800ED4B4 000EA414  C0 23 00 98 */	lfs f1, 0x98(r3)
/* 800ED4B8 000EA418  C0 03 00 94 */	lfs f0, 0x94(r3)
/* 800ED4BC 000EA41C  38 7E 02 28 */	addi r3, r30, 0x228
/* 800ED4C0 000EA420  EC 22 08 2A */	fadds f1, f2, f1
/* 800ED4C4 000EA424  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 800ED4C8 000EA428  D0 21 00 14 */	stfs f1, 0x14(r1)
/* 800ED4CC 000EA42C  C0 1E 00 9C */	lfs f0, 0x9c(r30)
/* 800ED4D0 000EA430  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 800ED4D4 000EA434  4B F5 0C 21 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 800ED4D8 000EA438  7F E3 FB 78 */	mr r3, r31
/* 800ED4DC 000EA43C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800ED4E0 000EA440  38 9E 02 28 */	addi r4, r30, 0x228
/* 800ED4E4 000EA444  38 A1 00 20 */	addi r5, r1, 0x20
/* 800ED4E8 000EA448  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 800ED4EC 000EA44C  7D 88 03 A6 */	mtlr r12
/* 800ED4F0 000EA450  4E 80 00 21 */	blrl 
/* 800ED4F4 000EA454  7F E3 FB 78 */	mr r3, r31
/* 800ED4F8 000EA458  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800ED4FC 000EA45C  38 81 00 20 */	addi r4, r1, 0x20
/* 800ED500 000EA460  38 A0 00 00 */	li r5, 0
/* 800ED504 000EA464  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800ED508 000EA468  7D 88 03 A6 */	mtlr r12
/* 800ED50C 000EA46C  4E 80 00 21 */	blrl 
/* 800ED510 000EA470  38 1E 00 94 */	addi r0, r30, 0x94
/* 800ED514 000EA474  80 9F 02 E4 */	lwz r4, 0x2e4(r31)
/* 800ED518 000EA478  7C 60 00 D0 */	neg r3, r0
/* 800ED51C 000EA47C  30 03 FF FF */	addic r0, r3, -1
/* 800ED520 000EA480  7C 00 19 10 */	subfe r0, r0, r3
/* 800ED524 000EA484  98 04 01 54 */	stb r0, 0x154(r4)
/* 800ED528 000EA488  88 04 01 54 */	lbz r0, 0x154(r4)
/* 800ED52C 000EA48C  28 00 00 00 */	cmplwi r0, 0
/* 800ED530 000EA490  41 82 00 1C */	beq .L_800ED54C
/* 800ED534 000EA494  80 7E 00 94 */	lwz r3, 0x94(r30)
/* 800ED538 000EA498  80 1E 00 98 */	lwz r0, 0x98(r30)
/* 800ED53C 000EA49C  90 64 01 58 */	stw r3, 0x158(r4)
/* 800ED540 000EA4A0  90 04 01 5C */	stw r0, 0x15c(r4)
/* 800ED544 000EA4A4  80 1E 00 9C */	lwz r0, 0x9c(r30)
/* 800ED548 000EA4A8  90 04 01 60 */	stw r0, 0x160(r4)
.L_800ED54C:
/* 800ED54C 000EA4AC  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 800ED550 000EA4B0  C0 3E 00 94 */	lfs f1, 0x94(r30)
/* 800ED554 000EA4B4  C0 5E 00 9C */	lfs f2, 0x9c(r30)
/* 800ED558 000EA4B8  4B F7 A8 41 */	bl getLight__6MapMgrFff
/* 800ED55C 000EA4BC  7F E3 FB 78 */	mr r3, r31
/* 800ED560 000EA4C0  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800ED564 000EA4C4  38 80 00 01 */	li r4, 1
/* 800ED568 000EA4C8  38 A0 00 00 */	li r5, 0
/* 800ED56C 000EA4CC  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 800ED570 000EA4D0  7D 88 03 A6 */	mtlr r12
/* 800ED574 000EA4D4  4E 80 00 21 */	blrl 
/* 800ED578 000EA4D8  80 7E 02 E0 */	lwz r3, 0x2e0(r30)
/* 800ED57C 000EA4DC  7F E4 FB 78 */	mr r4, r31
/* 800ED580 000EA4E0  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 800ED584 000EA4E4  38 C0 00 00 */	li r6, 0
/* 800ED588 000EA4E8  4B F4 2E E5 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 800ED58C 000EA4EC  80 9F 02 E4 */	lwz r4, 0x2e4(r31)
/* 800ED590 000EA4F0  38 00 00 00 */	li r0, 0
/* 800ED594 000EA4F4  98 04 01 54 */	stb r0, 0x154(r4)
/* 800ED598 000EA4F8  88 04 01 54 */	lbz r0, 0x154(r4)
/* 800ED59C 000EA4FC  28 00 00 00 */	cmplwi r0, 0
/* 800ED5A0 000EA500  41 82 00 1C */	beq .L_800ED5BC
/* 800ED5A4 000EA504  80 60 00 00 */	lwz r3, 0(0)
/* 800ED5A8 000EA508  80 00 00 04 */	lwz r0, 4(0)
/* 800ED5AC 000EA50C  90 64 01 58 */	stw r3, 0x158(r4)
/* 800ED5B0 000EA510  90 04 01 5C */	stw r0, 0x15c(r4)
/* 800ED5B4 000EA514  80 00 00 08 */	lwz r0, 8(0)
/* 800ED5B8 000EA518  90 04 01 60 */	stw r0, 0x160(r4)
.L_800ED5BC:
/* 800ED5BC 000EA51C  80 01 00 AC */	lwz r0, 0xac(r1)
/* 800ED5C0 000EA520  83 E1 00 A4 */	lwz r31, 0xa4(r1)
/* 800ED5C4 000EA524  83 C1 00 A0 */	lwz r30, 0xa0(r1)
/* 800ED5C8 000EA528  38 21 00 A8 */	addi r1, r1, 0xa8
/* 800ED5CC 000EA52C  7C 08 03 A6 */	mtlr r0
/* 800ED5D0 000EA530  4E 80 00 20 */	blr 

.global __ct__8DoorItemFiP12CreaturePropP5Shape
__ct__8DoorItemFiP12CreaturePropP5Shape:
/* 800ED5D4 000EA534  7C 08 02 A6 */	mflr r0
/* 800ED5D8 000EA538  90 01 00 04 */	stw r0, 4(r1)
/* 800ED5DC 000EA53C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800ED5E0 000EA540  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800ED5E4 000EA544  7C 7F 1B 78 */	mr r31, r3
/* 800ED5E8 000EA548  48 00 82 C5 */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800ED5EC 000EA54C  3C 60 80 2C */	lis r3, __vt__8DoorItem@ha
/* 800ED5F0 000EA550  38 63 D1 A8 */	addi r3, r3, __vt__8DoorItem@l
/* 800ED5F4 000EA554  90 7F 00 00 */	stw r3, 0(r31)
/* 800ED5F8 000EA558  38 03 01 14 */	addi r0, r3, 0x114
/* 800ED5FC 000EA55C  38 80 00 02 */	li r4, 2
/* 800ED600 000EA560  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800ED604 000EA564  38 00 00 00 */	li r0, 0
/* 800ED608 000EA568  38 7F 00 00 */	addi r3, r31, 0
/* 800ED60C 000EA56C  90 9F 03 CC */	stw r4, 0x3cc(r31)
/* 800ED610 000EA570  C0 02 9A E0 */	lfs f0, lbl_803E9CE0@sda21(r2)
/* 800ED614 000EA574  D0 1F 03 C8 */	stfs f0, 0x3c8(r31)
/* 800ED618 000EA578  90 1F 03 D0 */	stw r0, 0x3d0(r31)
/* 800ED61C 000EA57C  90 1F 03 D4 */	stw r0, 0x3d4(r31)
/* 800ED620 000EA580  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800ED624 000EA584  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800ED628 000EA588  38 21 00 20 */	addi r1, r1, 0x20
/* 800ED62C 000EA58C  7C 08 03 A6 */	mtlr r0
/* 800ED630 000EA590  4E 80 00 20 */	blr 

.global disappear__8DoorItemFv
disappear__8DoorItemFv:
/* 800ED634 000EA594  80 03 03 CC */	lwz r0, 0x3cc(r3)
/* 800ED638 000EA598  2C 00 00 03 */	cmpwi r0, 3
/* 800ED63C 000EA59C  4D 82 00 20 */	beqlr 
/* 800ED640 000EA5A0  38 00 00 03 */	li r0, 3
/* 800ED644 000EA5A4  90 03 03 CC */	stw r0, 0x3cc(r3)
/* 800ED648 000EA5A8  C0 02 9B 14 */	lfs f0, lbl_803E9D14@sda21(r2)
/* 800ED64C 000EA5AC  D0 03 03 C8 */	stfs f0, 0x3c8(r3)
/* 800ED650 000EA5B0  4E 80 00 20 */	blr 

.global getSize__8DoorItemFv
getSize__8DoorItemFv:
/* 800ED654 000EA5B4  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 800ED658 000EA5B8  2C 00 00 05 */	cmpwi r0, 5
/* 800ED65C 000EA5BC  40 82 00 0C */	bne .L_800ED668
/* 800ED660 000EA5C0  C0 22 9B 18 */	lfs f1, lbl_803E9D18@sda21(r2)
/* 800ED664 000EA5C4  4E 80 00 20 */	blr 
.L_800ED668:
/* 800ED668 000EA5C8  C0 22 9B 1C */	lfs f1, lbl_803E9D1C@sda21(r2)
/* 800ED66C 000EA5CC  4E 80 00 20 */	blr 

.global init__8DoorItemFR8Vector3f
init__8DoorItemFR8Vector3f:
/* 800ED670 000EA5D0  7C 08 02 A6 */	mflr r0
/* 800ED674 000EA5D4  90 01 00 04 */	stw r0, 4(r1)
/* 800ED678 000EA5D8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800ED67C 000EA5DC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800ED680 000EA5E0  7C 7F 1B 78 */	mr r31, r3
/* 800ED684 000EA5E4  48 00 82 F1 */	bl init__12ItemCreatureFR8Vector3f
/* 800ED688 000EA5E8  80 1F 00 6C */	lwz r0, 0x6c(r31)
/* 800ED68C 000EA5EC  C0 02 9A DC */	lfs f0, lbl_803E9CDC@sda21(r2)
/* 800ED690 000EA5F0  2C 00 00 05 */	cmpwi r0, 5
/* 800ED694 000EA5F4  40 82 00 08 */	bne .L_800ED69C
/* 800ED698 000EA5F8  C0 02 9B 04 */	lfs f0, lbl_803E9D04@sda21(r2)
.L_800ED69C:
/* 800ED69C 000EA5FC  D0 1F 00 7C */	stfs f0, 0x7c(r31)
/* 800ED6A0 000EA600  38 00 00 02 */	li r0, 2
/* 800ED6A4 000EA604  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 800ED6A8 000EA608  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 800ED6AC 000EA60C  90 1F 03 CC */	stw r0, 0x3cc(r31)
/* 800ED6B0 000EA610  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800ED6B4 000EA614  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800ED6B8 000EA618  38 21 00 18 */	addi r1, r1, 0x18
/* 800ED6BC 000EA61C  7C 08 03 A6 */	mtlr r0
/* 800ED6C0 000EA620  4E 80 00 20 */	blr 

.global startAI__8DoorItemFi
startAI__8DoorItemFi:
/* 800ED6C4 000EA624  38 00 00 00 */	li r0, 0
/* 800ED6C8 000EA628  90 03 03 CC */	stw r0, 0x3cc(r3)
/* 800ED6CC 000EA62C  4E 80 00 20 */	blr 

.global update__8DoorItemFv
update__8DoorItemFv:
/* 800ED6D0 000EA630  7C 08 02 A6 */	mflr r0
/* 800ED6D4 000EA634  90 01 00 04 */	stw r0, 4(r1)
/* 800ED6D8 000EA638  94 21 FF F8 */	stwu r1, -8(r1)
/* 800ED6DC 000EA63C  80 03 03 CC */	lwz r0, 0x3cc(r3)
/* 800ED6E0 000EA640  2C 00 00 03 */	cmpwi r0, 3
/* 800ED6E4 000EA644  40 82 00 80 */	bne .L_800ED764
/* 800ED6E8 000EA648  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 800ED6EC 000EA64C  C0 23 03 C8 */	lfs f1, 0x3c8(r3)
/* 800ED6F0 000EA650  C0 04 02 8C */	lfs f0, 0x28c(r4)
/* 800ED6F4 000EA654  EC 01 00 28 */	fsubs f0, f1, f0
/* 800ED6F8 000EA658  D0 03 03 C8 */	stfs f0, 0x3c8(r3)
/* 800ED6FC 000EA65C  C0 23 03 C8 */	lfs f1, 0x3c8(r3)
/* 800ED700 000EA660  C0 02 9B 14 */	lfs f0, lbl_803E9D14@sda21(r2)
/* 800ED704 000EA664  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 800ED708 000EA668  EC 61 00 24 */	fdivs f3, f1, f0
/* 800ED70C 000EA66C  C0 82 9B 04 */	lfs f4, lbl_803E9D04@sda21(r2)
/* 800ED710 000EA670  C0 22 9B 20 */	lfs f1, lbl_803E9D20@sda21(r2)
/* 800ED714 000EA674  C0 04 02 8C */	lfs f0, 0x28c(r4)
/* 800ED718 000EA678  C0 43 00 98 */	lfs f2, 0x98(r3)
/* 800ED71C 000EA67C  EC 01 00 32 */	fmuls f0, f1, f0
/* 800ED720 000EA680  EC 24 00 F2 */	fmuls f1, f4, f3
/* 800ED724 000EA684  EC 02 00 28 */	fsubs f0, f2, f0
/* 800ED728 000EA688  D0 03 00 98 */	stfs f0, 0x98(r3)
/* 800ED72C 000EA68C  C0 0D CC 88 */	lfs f0, lbl_803E19A8@sda21(r13)
/* 800ED730 000EA690  D0 03 00 7C */	stfs f0, 0x7c(r3)
/* 800ED734 000EA694  D0 23 00 80 */	stfs f1, 0x80(r3)
/* 800ED738 000EA698  C0 0D CC 8C */	lfs f0, lbl_803E19AC@sda21(r13)
/* 800ED73C 000EA69C  D0 03 00 84 */	stfs f0, 0x84(r3)
/* 800ED740 000EA6A0  C0 23 03 C8 */	lfs f1, 0x3c8(r3)
/* 800ED744 000EA6A4  C0 02 9A E0 */	lfs f0, lbl_803E9CE0@sda21(r2)
/* 800ED748 000EA6A8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800ED74C 000EA6AC  40 80 00 1C */	bge .L_800ED768
/* 800ED750 000EA6B0  38 00 00 01 */	li r0, 1
/* 800ED754 000EA6B4  90 03 03 CC */	stw r0, 0x3cc(r3)
/* 800ED758 000EA6B8  38 80 00 00 */	li r4, 0
/* 800ED75C 000EA6BC  4B F9 D5 85 */	bl kill__8CreatureFb
/* 800ED760 000EA6C0  48 00 00 08 */	b .L_800ED768
.L_800ED764:
/* 800ED764 000EA6C4  48 00 84 91 */	bl update__12ItemCreatureFv
.L_800ED768:
/* 800ED768 000EA6C8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800ED76C 000EA6CC  38 21 00 08 */	addi r1, r1, 8
/* 800ED770 000EA6D0  7C 08 03 A6 */	mtlr r0
/* 800ED774 000EA6D4  4E 80 00 20 */	blr 

.global isVisible__8DoorItemFv
isVisible__8DoorItemFv:
/* 800ED778 000EA6D8  80 03 03 CC */	lwz r0, 0x3cc(r3)
/* 800ED77C 000EA6DC  38 60 00 00 */	li r3, 0
/* 800ED780 000EA6E0  2C 00 00 01 */	cmpwi r0, 1
/* 800ED784 000EA6E4  4D 82 00 20 */	beqlr 
/* 800ED788 000EA6E8  2C 00 00 02 */	cmpwi r0, 2
/* 800ED78C 000EA6EC  4D 82 00 20 */	beqlr 
/* 800ED790 000EA6F0  38 60 00 01 */	li r3, 1
/* 800ED794 000EA6F4  4E 80 00 20 */	blr 

.global getiMass__8DoorItemFv
getiMass__8DoorItemFv:
/* 800ED798 000EA6F8  C0 22 9A E0 */	lfs f1, lbl_803E9CE0@sda21(r2)
/* 800ED79C 000EA6FC  4E 80 00 20 */	blr 

.global isAtari__8DoorItemFv
isAtari__8DoorItemFv:
/* 800ED7A0 000EA700  80 03 03 CC */	lwz r0, 0x3cc(r3)
/* 800ED7A4 000EA704  38 60 00 01 */	li r3, 1
/* 800ED7A8 000EA708  2C 00 00 00 */	cmpwi r0, 0
/* 800ED7AC 000EA70C  4D 82 00 20 */	beqlr 
/* 800ED7B0 000EA710  2C 00 00 03 */	cmpwi r0, 3
/* 800ED7B4 000EA714  4D 82 00 20 */	beqlr 
/* 800ED7B8 000EA718  38 60 00 00 */	li r3, 0
/* 800ED7BC 000EA71C  4E 80 00 20 */	blr 

.global refresh__8DoorItemFR8Graphics
refresh__8DoorItemFR8Graphics:
/* 800ED7C0 000EA720  7C 08 02 A6 */	mflr r0
/* 800ED7C4 000EA724  90 01 00 04 */	stw r0, 4(r1)
/* 800ED7C8 000EA728  94 21 FE 90 */	stwu r1, -0x170(r1)
/* 800ED7CC 000EA72C  93 E1 01 6C */	stw r31, 0x16c(r1)
/* 800ED7D0 000EA730  93 C1 01 68 */	stw r30, 0x168(r1)
/* 800ED7D4 000EA734  93 A1 01 64 */	stw r29, 0x164(r1)
/* 800ED7D8 000EA738  3B A4 00 00 */	addi r29, r4, 0
/* 800ED7DC 000EA73C  93 81 01 60 */	stw r28, 0x160(r1)
/* 800ED7E0 000EA740  3B 83 00 00 */	addi r28, r3, 0
/* 800ED7E4 000EA744  38 7C 02 28 */	addi r3, r28, 0x228
/* 800ED7E8 000EA748  38 9C 00 7C */	addi r4, r28, 0x7c
/* 800ED7EC 000EA74C  38 BC 00 88 */	addi r5, r28, 0x88
/* 800ED7F0 000EA750  38 DC 00 94 */	addi r6, r28, 0x94
/* 800ED7F4 000EA754  4B F5 09 01 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 800ED7F8 000EA758  7F A3 EB 78 */	mr r3, r29
/* 800ED7FC 000EA75C  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED800 000EA760  38 9C 02 28 */	addi r4, r28, 0x228
/* 800ED804 000EA764  38 A1 01 20 */	addi r5, r1, 0x120
/* 800ED808 000EA768  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 800ED80C 000EA76C  7D 88 03 A6 */	mtlr r12
/* 800ED810 000EA770  4E 80 00 21 */	blrl 
/* 800ED814 000EA774  C0 0D CC 90 */	lfs f0, lbl_803E19B0@sda21(r13)
/* 800ED818 000EA778  38 61 01 14 */	addi r3, r1, 0x114
/* 800ED81C 000EA77C  C0 2D CC 94 */	lfs f1, lbl_803E19B4@sda21(r13)
/* 800ED820 000EA780  38 81 01 20 */	addi r4, r1, 0x120
/* 800ED824 000EA784  D0 01 01 14 */	stfs f0, 0x114(r1)
/* 800ED828 000EA788  C0 0D CC 98 */	lfs f0, lbl_803E19B8@sda21(r13)
/* 800ED82C 000EA78C  D0 21 01 18 */	stfs f1, 0x118(r1)
/* 800ED830 000EA790  D0 01 01 1C */	stfs f0, 0x11c(r1)
/* 800ED834 000EA794  4B F4 9F 19 */	bl multMatrix__8Vector3fFR8Matrix4f
/* 800ED838 000EA798  7F A3 EB 78 */	mr r3, r29
/* 800ED83C 000EA79C  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED840 000EA7A0  38 80 00 00 */	li r4, 0
/* 800ED844 000EA7A4  38 A0 00 00 */	li r5, 0
/* 800ED848 000EA7A8  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 800ED84C 000EA7AC  7D 88 03 A6 */	mtlr r12
/* 800ED850 000EA7B0  4E 80 00 21 */	blrl 
/* 800ED854 000EA7B4  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED858 000EA7B8  38 03 00 00 */	addi r0, r3, 0
/* 800ED85C 000EA7BC  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 800ED860 000EA7C0  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800ED864 000EA7C4  38 7D 00 00 */	addi r3, r29, 0
/* 800ED868 000EA7C8  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 800ED86C 000EA7CC  7D 88 03 A6 */	mtlr r12
/* 800ED870 000EA7D0  7C 1F 03 78 */	mr r31, r0
/* 800ED874 000EA7D4  38 A0 00 00 */	li r5, 0
/* 800ED878 000EA7D8  4E 80 00 21 */	blrl 
/* 800ED87C 000EA7DC  38 00 00 FF */	li r0, 0xff
/* 800ED880 000EA7E0  98 01 00 10 */	stb r0, 0x10(r1)
/* 800ED884 000EA7E4  38 81 00 10 */	addi r4, r1, 0x10
/* 800ED888 000EA7E8  38 7D 00 00 */	addi r3, r29, 0
/* 800ED88C 000EA7EC  98 01 00 11 */	stb r0, 0x11(r1)
/* 800ED890 000EA7F0  38 A0 00 01 */	li r5, 1
/* 800ED894 000EA7F4  98 01 00 12 */	stb r0, 0x12(r1)
/* 800ED898 000EA7F8  98 01 00 13 */	stb r0, 0x13(r1)
/* 800ED89C 000EA7FC  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED8A0 000EA800  81 8C 00 A8 */	lwz r12, 0xa8(r12)
/* 800ED8A4 000EA804  7D 88 03 A6 */	mtlr r12
/* 800ED8A8 000EA808  4E 80 00 21 */	blrl 
/* 800ED8AC 000EA80C  7F A3 EB 78 */	mr r3, r29
/* 800ED8B0 000EA810  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 800ED8B4 000EA814  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED8B8 000EA818  38 A0 00 00 */	li r5, 0
/* 800ED8BC 000EA81C  80 84 00 10 */	lwz r4, 0x10(r4)
/* 800ED8C0 000EA820  81 8C 00 CC */	lwz r12, 0xcc(r12)
/* 800ED8C4 000EA824  80 84 00 00 */	lwz r4, 0(r4)
/* 800ED8C8 000EA828  7D 88 03 A6 */	mtlr r12
/* 800ED8CC 000EA82C  4E 80 00 21 */	blrl 
/* 800ED8D0 000EA830  7F A3 EB 78 */	mr r3, r29
/* 800ED8D4 000EA834  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED8D8 000EA838  38 80 00 00 */	li r4, 0
/* 800ED8DC 000EA83C  81 8C 00 60 */	lwz r12, 0x60(r12)
/* 800ED8E0 000EA840  7D 88 03 A6 */	mtlr r12
/* 800ED8E4 000EA844  4E 80 00 21 */	blrl 
/* 800ED8E8 000EA848  80 BC 03 D4 */	lwz r5, 0x3d4(r28)
/* 800ED8EC 000EA84C  3B C3 00 00 */	addi r30, r3, 0
/* 800ED8F0 000EA850  4C C6 31 82 */	crclr 6
/* 800ED8F4 000EA854  38 61 00 14 */	addi r3, r1, 0x14
/* 800ED8F8 000EA858  38 8D CC 9C */	addi r4, r13, lbl_803E19BC@sda21
/* 800ED8FC 000EA85C  48 12 8C 9D */	bl sprintf
/* 800ED900 000EA860  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800ED904 000EA864  38 81 00 14 */	addi r4, r1, 0x14
/* 800ED908 000EA868  80 63 00 10 */	lwz r3, 0x10(r3)
/* 800ED90C 000EA86C  4B F3 A8 29 */	bl stringWidth__4FontFPc
/* 800ED910 000EA870  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED914 000EA874  7C 60 0E 70 */	srawi r0, r3, 1
/* 800ED918 000EA878  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 800ED91C 000EA87C  7C 00 01 94 */	addze r0, r0
/* 800ED920 000EA880  81 8C 00 F0 */	lwz r12, 0xf0(r12)
/* 800ED924 000EA884  80 84 00 10 */	lwz r4, 0x10(r4)
/* 800ED928 000EA888  38 7D 00 00 */	addi r3, r29, 0
/* 800ED92C 000EA88C  7D 88 03 A6 */	mtlr r12
/* 800ED930 000EA890  7C C0 00 D0 */	neg r6, r0
/* 800ED934 000EA894  38 A1 01 14 */	addi r5, r1, 0x114
/* 800ED938 000EA898  4C C6 31 82 */	crclr 6
/* 800ED93C 000EA89C  39 01 00 14 */	addi r8, r1, 0x14
/* 800ED940 000EA8A0  38 E0 00 00 */	li r7, 0
/* 800ED944 000EA8A4  4E 80 00 21 */	blrl 
/* 800ED948 000EA8A8  7F A3 EB 78 */	mr r3, r29
/* 800ED94C 000EA8AC  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED950 000EA8B0  7F C4 F3 78 */	mr r4, r30
/* 800ED954 000EA8B4  81 8C 00 60 */	lwz r12, 0x60(r12)
/* 800ED958 000EA8B8  7D 88 03 A6 */	mtlr r12
/* 800ED95C 000EA8BC  4E 80 00 21 */	blrl 
/* 800ED960 000EA8C0  7F A3 EB 78 */	mr r3, r29
/* 800ED964 000EA8C4  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED968 000EA8C8  38 9F 00 00 */	addi r4, r31, 0
/* 800ED96C 000EA8CC  38 A0 00 00 */	li r5, 0
/* 800ED970 000EA8D0  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 800ED974 000EA8D4  7D 88 03 A6 */	mtlr r12
/* 800ED978 000EA8D8  4E 80 00 21 */	blrl 
/* 800ED97C 000EA8DC  7F A3 EB 78 */	mr r3, r29
/* 800ED980 000EA8E0  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800ED984 000EA8E4  38 81 01 20 */	addi r4, r1, 0x120
/* 800ED988 000EA8E8  38 A0 00 00 */	li r5, 0
/* 800ED98C 000EA8EC  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800ED990 000EA8F0  7D 88 03 A6 */	mtlr r12
/* 800ED994 000EA8F4  4E 80 00 21 */	blrl 
/* 800ED998 000EA8F8  38 7C 00 00 */	addi r3, r28, 0
/* 800ED99C 000EA8FC  38 9D 00 00 */	addi r4, r29, 0
/* 800ED9A0 000EA900  48 00 82 D9 */	bl refresh__12ItemCreatureFR8Graphics
/* 800ED9A4 000EA904  80 01 01 74 */	lwz r0, 0x174(r1)
/* 800ED9A8 000EA908  83 E1 01 6C */	lwz r31, 0x16c(r1)
/* 800ED9AC 000EA90C  83 C1 01 68 */	lwz r30, 0x168(r1)
/* 800ED9B0 000EA910  83 A1 01 64 */	lwz r29, 0x164(r1)
/* 800ED9B4 000EA914  83 81 01 60 */	lwz r28, 0x160(r1)
/* 800ED9B8 000EA918  38 21 01 70 */	addi r1, r1, 0x170
/* 800ED9BC 000EA91C  7C 08 03 A6 */	mtlr r0
/* 800ED9C0 000EA920  4E 80 00 20 */	blr 

.global isAlive__8DoorItemFv
isAlive__8DoorItemFv:
/* 800ED9C4 000EA924  38 60 00 01 */	li r3, 1
/* 800ED9C8 000EA928  4E 80 00 20 */	blr 

.global getHeight__8DoorItemFv
getHeight__8DoorItemFv:
/* 800ED9CC 000EA92C  C0 22 9A E0 */	lfs f1, lbl_803E9CE0@sda21(r2)
/* 800ED9D0 000EA930  4E 80 00 20 */	blr 

.global getHeight__7KeyItemFv
getHeight__7KeyItemFv:
/* 800ED9D4 000EA934  C0 22 9A E0 */	lfs f1, lbl_803E9CE0@sda21(r2)
/* 800ED9D8 000EA938  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BD0A0:
	.asciz "keyItem.cpp"
.balign 4
lbl_802BD0AC:
	.asciz "DoorItem"
.balign 4
lbl_802BD0B8:
	.asciz "PaniAnimKeyListener"
.balign 4
lbl_802BD0CC:
	.asciz "EventTalker"
.balign 4
lbl_802BD0D8:
	.asciz "RefCountable"
.balign 4
lbl_802BD0E8:
	.asciz "Creature"
.balign 4
lbl_802BD0F4:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
.balign 4
lbl_802BD108:
	.asciz "AICreature"
.balign 4
lbl_802BD114:
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
lbl_802BD138:
	.asciz "ItemCreature"
.balign 4
lbl_802BD148:
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
lbl_802BD174:
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
.global __vt__8DoorItem
__vt__8DoorItem:
	.4byte __RTTI__8DoorItem
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8DoorItemFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8DoorItemFi
	.4byte getiMass__8DoorItemFv
	.4byte getSize__8DoorItemFv
	.4byte getHeight__8DoorItemFv
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
	.4byte isVisible__8DoorItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8DoorItemFv
	.4byte isAlive__8DoorItemFv
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
	.4byte update__8DoorItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__8DoorItemFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__8DoorItem
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
lbl_802BD304:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
.global __vt__7KeyItem
__vt__7KeyItem:
	.4byte __RTTI__7KeyItem
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__7KeyItemFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__7KeyItemFi
	.4byte getiMass__7KeyItemFv
	.4byte getSize__7KeyItemFv
	.4byte getHeight__7KeyItemFv
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
	.4byte isVisible__7KeyItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__8CreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__7KeyItemFR9CollEvent
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
	.4byte update__7KeyItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__7KeyItemFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__8CreatureFv
	.4byte doAnimation__8CreatureFv
	.4byte doKill__7KeyItemFv
	.4byte exitCourse__8CreatureFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E19A8:
	.float 2.0
lbl_803E19AC:
	.float 2.0
lbl_803E19B0:
	.float 0.0
lbl_803E19B4:
	.float 40.0
lbl_803E19B8:
	.float 0.0
lbl_803E19BC:
	.asciz "%s"
.balign 4
__RTTI__19PaniAnimKeyListener:
	.4byte lbl_802BD0B8
	.4byte 0
__RTTI__11EventTalker:
	.4byte lbl_802BD0CC
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802BD0D8
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802BD0E8
	.4byte lbl_802BD0F4
__RTTI__10AICreature:
	.4byte lbl_802BD108
	.4byte lbl_802BD114
__RTTI__12ItemCreature:
	.4byte lbl_802BD138
	.4byte lbl_802BD148
__RTTI__8DoorItem:
	.4byte lbl_802BD0AC
	.4byte lbl_802BD174
.balign 4
lbl_803E19F8:
	.asciz "KeyItem"
.balign 4
__RTTI__7KeyItem:
	.4byte lbl_803E19F8
	.4byte lbl_802BD304

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E9CD8:
	.float 25.0
lbl_803E9CDC:
	.float 1.0
lbl_803E9CE0:
	.float 0.0
.balign 8
lbl_803E9CE8:
	.double 0.5
lbl_803E9CF0:
	.double 3.0
lbl_803E9CF8:
	.float 0.025
lbl_803E9CFC:
	.float 0.01
lbl_803E9D00:
	.float 150.0
lbl_803E9D04:
	.float 2.0
lbl_803E9D08:
	.float 6.2831855
lbl_803E9D0C:
	.float 10.0
lbl_803E9D10:
	.float 20.0
lbl_803E9D14:
	.float 2.5
lbl_803E9D18:
	.float 60.0
lbl_803E9D1C:
	.float 30.0
lbl_803E9D20:
	.float 3.0
