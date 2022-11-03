.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global collisionCallback__8BombItemFR9CollEvent
collisionCallback__8BombItemFR9CollEvent:
/* 800EA190 000E70F0  7C 08 02 A6 */	mflr r0
/* 800EA194 000E70F4  90 01 00 04 */	stw r0, 4(r1)
/* 800EA198 000E70F8  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800EA19C 000E70FC  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800EA1A0 000E7100  93 C1 00 30 */	stw r30, 0x30(r1)
/* 800EA1A4 000E7104  7C 9E 23 78 */	mr r30, r4
/* 800EA1A8 000E7108  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 800EA1AC 000E710C  7C 7D 1B 78 */	mr r29, r3
/* 800EA1B0 000E7110  81 9D 00 00 */	lwz r12, 0(r29)
/* 800EA1B4 000E7114  83 E4 00 00 */	lwz r31, 0(r4)
/* 800EA1B8 000E7118  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800EA1BC 000E711C  7D 88 03 A6 */	mtlr r12
/* 800EA1C0 000E7120  4E 80 00 21 */	blrl 
/* 800EA1C4 000E7124  80 1F 00 6C */	lwz r0, 0x6c(r31)
/* 800EA1C8 000E7128  80 63 00 04 */	lwz r3, 4(r3)
/* 800EA1CC 000E712C  2C 00 00 00 */	cmpwi r0, 0
/* 800EA1D0 000E7130  41 82 00 4C */	beq .L_800EA21C
/* 800EA1D4 000E7134  2C 03 00 01 */	cmpwi r3, 1
/* 800EA1D8 000E7138  40 82 00 44 */	bne .L_800EA21C
/* 800EA1DC 000E713C  38 61 00 14 */	addi r3, r1, 0x14
/* 800EA1E0 000E7140  80 9E 00 04 */	lwz r4, 4(r30)
/* 800EA1E4 000E7144  4B F9 DC BD */	bl getID__8CollPartFv
/* 800EA1E8 000E7148  80 61 00 14 */	lwz r3, 0x14(r1)
/* 800EA1EC 000E714C  3C 03 9D 9B */	addis r0, r3, 0x9d9b
/* 800EA1F0 000E7150  28 00 61 74 */	cmplwi r0, 0x6174
/* 800EA1F4 000E7154  40 82 00 18 */	bne .L_800EA20C
/* 800EA1F8 000E7158  80 7D 02 E8 */	lwz r3, 0x2e8(r29)
/* 800EA1FC 000E715C  38 9D 00 00 */	addi r4, r29, 0
/* 800EA200 000E7160  38 A0 00 04 */	li r5, 4
/* 800EA204 000E7164  4B F9 35 55 */	bl start__8SimpleAIFP10AICreaturei
/* 800EA208 000E7168  48 00 00 14 */	b .L_800EA21C
.L_800EA20C:
/* 800EA20C 000E716C  80 7D 02 E8 */	lwz r3, 0x2e8(r29)
/* 800EA210 000E7170  38 9D 00 00 */	addi r4, r29, 0
/* 800EA214 000E7174  38 A0 00 03 */	li r5, 3
/* 800EA218 000E7178  4B F9 35 41 */	bl start__8SimpleAIFP10AICreaturei
.L_800EA21C:
/* 800EA21C 000E717C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800EA220 000E7180  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800EA224 000E7184  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 800EA228 000E7188  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 800EA22C 000E718C  38 21 00 38 */	addi r1, r1, 0x38
/* 800EA230 000E7190  7C 08 03 A6 */	mtlr r0
/* 800EA234 000E7194  4E 80 00 20 */	blr 

.global isVisible__8BombItemFv
isVisible__8BombItemFv:
/* 800EA238 000E7198  7C 08 02 A6 */	mflr r0
/* 800EA23C 000E719C  90 01 00 04 */	stw r0, 4(r1)
/* 800EA240 000E71A0  94 21 FF F8 */	stwu r1, -8(r1)
/* 800EA244 000E71A4  81 83 00 00 */	lwz r12, 0(r3)
/* 800EA248 000E71A8  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800EA24C 000E71AC  7D 88 03 A6 */	mtlr r12
/* 800EA250 000E71B0  4E 80 00 21 */	blrl 
/* 800EA254 000E71B4  80 63 00 04 */	lwz r3, 4(r3)
/* 800EA258 000E71B8  2C 03 00 04 */	cmpwi r3, 4
/* 800EA25C 000E71BC  41 82 00 18 */	beq .L_800EA274
/* 800EA260 000E71C0  2C 03 00 05 */	cmpwi r3, 5
/* 800EA264 000E71C4  41 82 00 10 */	beq .L_800EA274
/* 800EA268 000E71C8  38 03 FF FF */	addi r0, r3, -1
/* 800EA26C 000E71CC  28 00 00 01 */	cmplwi r0, 1
/* 800EA270 000E71D0  41 81 00 0C */	bgt .L_800EA27C
.L_800EA274:
/* 800EA274 000E71D4  38 60 00 00 */	li r3, 0
/* 800EA278 000E71D8  48 00 00 08 */	b .L_800EA280
.L_800EA27C:
/* 800EA27C 000E71DC  38 60 00 01 */	li r3, 1
.L_800EA280:
/* 800EA280 000E71E0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800EA284 000E71E4  38 21 00 08 */	addi r1, r1, 8
/* 800EA288 000E71E8  7C 08 03 A6 */	mtlr r0
/* 800EA28C 000E71EC  4E 80 00 20 */	blr 

.global needShadow__8BombItemFv
needShadow__8BombItemFv:
/* 800EA290 000E71F0  38 60 00 00 */	li r3, 0
/* 800EA294 000E71F4  4E 80 00 20 */	blr 

.global isAlive__8BombItemFv
isAlive__8BombItemFv:
/* 800EA298 000E71F8  7C 08 02 A6 */	mflr r0
/* 800EA29C 000E71FC  90 01 00 04 */	stw r0, 4(r1)
/* 800EA2A0 000E7200  94 21 FF F8 */	stwu r1, -8(r1)
/* 800EA2A4 000E7204  81 83 00 00 */	lwz r12, 0(r3)
/* 800EA2A8 000E7208  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800EA2AC 000E720C  7D 88 03 A6 */	mtlr r12
/* 800EA2B0 000E7210  4E 80 00 21 */	blrl 
/* 800EA2B4 000E7214  80 63 00 04 */	lwz r3, 4(r3)
/* 800EA2B8 000E7218  2C 03 00 04 */	cmpwi r3, 4
/* 800EA2BC 000E721C  41 82 00 18 */	beq .L_800EA2D4
/* 800EA2C0 000E7220  2C 03 00 05 */	cmpwi r3, 5
/* 800EA2C4 000E7224  41 82 00 10 */	beq .L_800EA2D4
/* 800EA2C8 000E7228  38 03 FF FF */	addi r0, r3, -1
/* 800EA2CC 000E722C  28 00 00 01 */	cmplwi r0, 1
/* 800EA2D0 000E7230  41 81 00 0C */	bgt .L_800EA2DC
.L_800EA2D4:
/* 800EA2D4 000E7234  38 60 00 00 */	li r3, 0
/* 800EA2D8 000E7238  48 00 00 08 */	b .L_800EA2E0
.L_800EA2DC:
/* 800EA2DC 000E723C  38 60 00 01 */	li r3, 1
.L_800EA2E0:
/* 800EA2E0 000E7240  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800EA2E4 000E7244  38 21 00 08 */	addi r1, r1, 8
/* 800EA2E8 000E7248  7C 08 03 A6 */	mtlr r0
/* 800EA2EC 000E724C  4E 80 00 20 */	blr 

.global __ct__8BombItemFP12CreaturePropP15ItemShapeObjectP8SimpleAI
__ct__8BombItemFP12CreaturePropP15ItemShapeObjectP8SimpleAI:
/* 800EA2F0 000E7250  7C 08 02 A6 */	mflr r0
/* 800EA2F4 000E7254  90 01 00 04 */	stw r0, 4(r1)
/* 800EA2F8 000E7258  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800EA2FC 000E725C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800EA300 000E7260  3B E6 00 00 */	addi r31, r6, 0
/* 800EA304 000E7264  38 C0 00 00 */	li r6, 0
/* 800EA308 000E7268  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800EA30C 000E726C  3B C5 00 00 */	addi r30, r5, 0
/* 800EA310 000E7270  38 A4 00 00 */	addi r5, r4, 0
/* 800EA314 000E7274  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 800EA318 000E7278  3B A3 00 00 */	addi r29, r3, 0
/* 800EA31C 000E727C  38 80 00 0E */	li r4, 0xe
/* 800EA320 000E7280  48 00 B5 8D */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800EA324 000E7284  3C 60 80 2C */	lis r3, __vt__8BombItem@ha
/* 800EA328 000E7288  38 63 C6 F0 */	addi r3, r3, __vt__8BombItem@l
/* 800EA32C 000E728C  90 7D 00 00 */	stw r3, 0(r29)
/* 800EA330 000E7290  38 03 01 14 */	addi r0, r3, 0x114
/* 800EA334 000E7294  38 7D 03 CC */	addi r3, r29, 0x3cc
/* 800EA338 000E7298  90 1D 02 B8 */	stw r0, 0x2b8(r29)
/* 800EA33C 000E729C  4B FB 99 21 */	bl __ct__9SeContextFv
/* 800EA340 000E72A0  38 7D 03 F4 */	addi r3, r29, 0x3f4
/* 800EA344 000E72A4  38 80 00 00 */	li r4, 0
/* 800EA348 000E72A8  4B F9 E8 E9 */	bl __ct__8CollInfoFi
/* 800EA34C 000E72AC  3C 60 80 08 */	lis r3, __ct__8CollPartFv@ha
/* 800EA350 000E72B0  38 83 7E 48 */	addi r4, r3, __ct__8CollPartFv@l
/* 800EA354 000E72B4  38 7D 04 08 */	addi r3, r29, 0x408
/* 800EA358 000E72B8  38 A0 00 00 */	li r5, 0
/* 800EA35C 000E72BC  38 C0 00 68 */	li r6, 0x68
/* 800EA360 000E72C0  38 E0 00 0A */	li r7, 0xa
/* 800EA364 000E72C4  48 12 A7 0D */	bl __construct_array
/* 800EA368 000E72C8  38 00 00 01 */	li r0, 1
/* 800EA36C 000E72CC  98 1D 02 00 */	stb r0, 0x200(r29)
/* 800EA370 000E72D0  7F A3 EB 78 */	mr r3, r29
/* 800EA374 000E72D4  93 DD 03 C0 */	stw r30, 0x3c0(r29)
/* 800EA378 000E72D8  93 FD 02 E8 */	stw r31, 0x2e8(r29)
/* 800EA37C 000E72DC  90 1D 01 FC */	stw r0, 0x1fc(r29)
/* 800EA380 000E72E0  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800EA384 000E72E4  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800EA388 000E72E8  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800EA38C 000E72EC  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 800EA390 000E72F0  38 21 00 28 */	addi r1, r1, 0x28
/* 800EA394 000E72F4  7C 08 03 A6 */	mtlr r0
/* 800EA398 000E72F8  4E 80 00 20 */	blr 

.global startAI__8BombItemFi
startAI__8BombItemFi:
/* 800EA39C 000E72FC  7C 08 02 A6 */	mflr r0
/* 800EA3A0 000E7300  38 A0 00 01 */	li r5, 1
/* 800EA3A4 000E7304  90 01 00 04 */	stw r0, 4(r1)
/* 800EA3A8 000E7308  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800EA3AC 000E730C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800EA3B0 000E7310  7C 7F 1B 78 */	mr r31, r3
/* 800EA3B4 000E7314  38 1F 03 CC */	addi r0, r31, 0x3cc
/* 800EA3B8 000E7318  80 63 00 C8 */	lwz r3, 0xc8(r3)
/* 800EA3BC 000E731C  38 9F 00 00 */	addi r4, r31, 0
/* 800EA3C0 000E7320  64 63 00 40 */	oris r3, r3, 0x40
/* 800EA3C4 000E7324  90 7F 00 C8 */	stw r3, 0xc8(r31)
/* 800EA3C8 000E7328  80 7F 00 C8 */	lwz r3, 0xc8(r31)
/* 800EA3CC 000E732C  64 63 00 10 */	oris r3, r3, 0x10
/* 800EA3D0 000E7330  90 7F 00 C8 */	stw r3, 0xc8(r31)
/* 800EA3D4 000E7334  90 1F 00 2C */	stw r0, 0x2c(r31)
/* 800EA3D8 000E7338  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 800EA3DC 000E733C  4B FB 99 59 */	bl setContext__9SeContextFP8Creaturei
/* 800EA3E0 000E7340  38 1F 03 F4 */	addi r0, r31, 0x3f4
/* 800EA3E4 000E7344  90 1F 02 20 */	stw r0, 0x220(r31)
/* 800EA3E8 000E7348  38 BF 04 08 */	addi r5, r31, 0x408
/* 800EA3EC 000E734C  38 DF 08 18 */	addi r6, r31, 0x818
/* 800EA3F0 000E7350  80 9F 03 C0 */	lwz r4, 0x3c0(r31)
/* 800EA3F4 000E7354  80 7F 02 20 */	lwz r3, 0x220(r31)
/* 800EA3F8 000E7358  80 84 00 00 */	lwz r4, 0(r4)
/* 800EA3FC 000E735C  4B F9 F7 69 */	bl initInfo__8CollInfoFP5ShapeP8CollPartPUl
/* 800EA400 000E7360  38 61 00 10 */	addi r3, r1, 0x10
/* 800EA404 000E7364  38 80 00 00 */	li r4, 0
/* 800EA408 000E7368  48 03 4B 51 */	bl __ct__14PaniMotionInfoFi
/* 800EA40C 000E736C  38 83 00 00 */	addi r4, r3, 0
/* 800EA410 000E7370  38 7F 03 6C */	addi r3, r31, 0x36c
/* 800EA414 000E7374  48 03 4D AD */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 800EA418 000E7378  C0 02 9A 28 */	lfs f0, lbl_803E9C28@sda21(r2)
/* 800EA41C 000E737C  38 9F 00 00 */	addi r4, r31, 0
/* 800EA420 000E7380  38 A0 00 00 */	li r5, 0
/* 800EA424 000E7384  D0 1F 03 04 */	stfs f0, 0x304(r31)
/* 800EA428 000E7388  C0 02 9A 2C */	lfs f0, lbl_803E9C2C@sda21(r2)
/* 800EA42C 000E738C  D0 1F 00 7C */	stfs f0, 0x7c(r31)
/* 800EA430 000E7390  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 800EA434 000E7394  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 800EA438 000E7398  80 7F 02 E8 */	lwz r3, 0x2e8(r31)
/* 800EA43C 000E739C  4B F9 33 1D */	bl start__8SimpleAIFP10AICreaturei
/* 800EA440 000E73A0  80 7F 00 94 */	lwz r3, 0x94(r31)
/* 800EA444 000E73A4  80 1F 00 98 */	lwz r0, 0x98(r31)
/* 800EA448 000E73A8  90 7F 01 E0 */	stw r3, 0x1e0(r31)
/* 800EA44C 000E73AC  90 1F 01 E4 */	stw r0, 0x1e4(r31)
/* 800EA450 000E73B0  80 1F 00 9C */	lwz r0, 0x9c(r31)
/* 800EA454 000E73B4  90 1F 01 E8 */	stw r0, 0x1e8(r31)
/* 800EA458 000E73B8  C0 0D CB 08 */	lfs f0, lbl_803E1828@sda21(r13)
/* 800EA45C 000E73BC  D0 1F 01 EC */	stfs f0, 0x1ec(r31)
/* 800EA460 000E73C0  C0 0D CB 0C */	lfs f0, lbl_803E182C@sda21(r13)
/* 800EA464 000E73C4  D0 1F 01 F0 */	stfs f0, 0x1f0(r31)
/* 800EA468 000E73C8  C0 0D CB 10 */	lfs f0, lbl_803E1830@sda21(r13)
/* 800EA46C 000E73CC  D0 1F 01 F4 */	stfs f0, 0x1f4(r31)
/* 800EA470 000E73D0  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800EA474 000E73D4  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800EA478 000E73D8  38 21 00 28 */	addi r1, r1, 0x28
/* 800EA47C 000E73DC  7C 08 03 A6 */	mtlr r0
/* 800EA480 000E73E0  4E 80 00 20 */	blr 

.global getSize__8BombItemFv
getSize__8BombItemFv:
/* 800EA484 000E73E4  C0 22 9A 30 */	lfs f1, lbl_803E9C30@sda21(r2)
/* 800EA488 000E73E8  4E 80 00 20 */	blr 

.global getiMass__8BombItemFv
getiMass__8BombItemFv:
/* 800EA48C 000E73EC  C0 22 9A 28 */	lfs f1, lbl_803E9C28@sda21(r2)
/* 800EA490 000E73F0  4E 80 00 20 */	blr 

.global update__8BombItemFv
update__8BombItemFv:
/* 800EA494 000E73F4  7C 08 02 A6 */	mflr r0
/* 800EA498 000E73F8  3C 80 80 3A */	lis r4, gameflow@ha
/* 800EA49C 000E73FC  90 01 00 04 */	stw r0, 4(r1)
/* 800EA4A0 000E7400  38 84 D7 B8 */	addi r4, r4, gameflow@l
/* 800EA4A4 000E7404  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800EA4A8 000E7408  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800EA4AC 000E740C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800EA4B0 000E7410  7C 7E 1B 78 */	mr r30, r3
/* 800EA4B4 000E7414  80 84 01 DC */	lwz r4, 0x1dc(r4)
/* 800EA4B8 000E7418  88 04 01 24 */	lbz r0, 0x124(r4)
/* 800EA4BC 000E741C  28 00 00 00 */	cmplwi r0, 0
/* 800EA4C0 000E7420  40 82 00 94 */	bne .L_800EA554
/* 800EA4C4 000E7424  7F C3 F3 78 */	mr r3, r30
/* 800EA4C8 000E7428  48 00 B7 2D */	bl update__12ItemCreatureFv
/* 800EA4CC 000E742C  7F C3 F3 78 */	mr r3, r30
/* 800EA4D0 000E7430  81 9E 00 00 */	lwz r12, 0(r30)
/* 800EA4D4 000E7434  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800EA4D8 000E7438  7D 88 03 A6 */	mtlr r12
/* 800EA4DC 000E743C  4E 80 00 21 */	blrl 
/* 800EA4E0 000E7440  83 E3 00 04 */	lwz r31, 4(r3)
/* 800EA4E4 000E7444  2C 1F 00 05 */	cmpwi r31, 5
/* 800EA4E8 000E7448  41 82 00 48 */	beq .L_800EA530
/* 800EA4EC 000E744C  2C 1F 00 03 */	cmpwi r31, 3
/* 800EA4F0 000E7450  41 82 00 40 */	beq .L_800EA530
/* 800EA4F4 000E7454  2C 1F 00 04 */	cmpwi r31, 4
/* 800EA4F8 000E7458  41 82 00 38 */	beq .L_800EA530
/* 800EA4FC 000E745C  80 7E 02 8C */	lwz r3, 0x28c(r30)
/* 800EA500 000E7460  28 03 00 00 */	cmplwi r3, 0
/* 800EA504 000E7464  41 82 00 2C */	beq .L_800EA530
/* 800EA508 000E7468  48 02 BB 79 */	bl getAttribute__7MapCodeFP11CollTriInfo
/* 800EA50C 000E746C  2C 03 00 05 */	cmpwi r3, 5
/* 800EA510 000E7470  40 82 00 20 */	bne .L_800EA530
/* 800EA514 000E7474  80 7E 02 E8 */	lwz r3, 0x2e8(r30)
/* 800EA518 000E7478  38 9E 00 00 */	addi r4, r30, 0
/* 800EA51C 000E747C  38 A0 00 04 */	li r5, 4
/* 800EA520 000E7480  81 83 00 00 */	lwz r12, 0(r3)
/* 800EA524 000E7484  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800EA528 000E7488  7D 88 03 A6 */	mtlr r12
/* 800EA52C 000E748C  4E 80 00 21 */	blrl 
.L_800EA530:
/* 800EA530 000E7490  2C 1F 00 01 */	cmpwi r31, 1
/* 800EA534 000E7494  40 82 00 20 */	bne .L_800EA554
/* 800EA538 000E7498  80 1E 02 8C */	lwz r0, 0x28c(r30)
/* 800EA53C 000E749C  28 00 00 00 */	cmplwi r0, 0
/* 800EA540 000E74A0  41 82 00 14 */	beq .L_800EA554
/* 800EA544 000E74A4  80 7E 02 E8 */	lwz r3, 0x2e8(r30)
/* 800EA548 000E74A8  38 9E 00 00 */	addi r4, r30, 0
/* 800EA54C 000E74AC  38 A0 00 03 */	li r5, 3
/* 800EA550 000E74B0  4B F9 32 09 */	bl start__8SimpleAIFP10AICreaturei
.L_800EA554:
/* 800EA554 000E74B4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800EA558 000E74B8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800EA55C 000E74BC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800EA560 000E74C0  38 21 00 20 */	addi r1, r1, 0x20
/* 800EA564 000E74C4  7C 08 03 A6 */	mtlr r0
/* 800EA568 000E74C8  4E 80 00 20 */	blr 

.global renderTimer__8BombItemFR8Graphics
renderTimer__8BombItemFR8Graphics:
/* 800EA56C 000E74CC  4E 80 00 20 */	blr 

.global refresh2d__8BombItemFR8Graphics
refresh2d__8BombItemFR8Graphics:
/* 800EA570 000E74D0  7C 08 02 A6 */	mflr r0
/* 800EA574 000E74D4  90 01 00 04 */	stw r0, 4(r1)
/* 800EA578 000E74D8  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800EA57C 000E74DC  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800EA580 000E74E0  7C 9F 23 78 */	mr r31, r4
/* 800EA584 000E74E4  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800EA588 000E74E8  7C 7E 1B 78 */	mr r30, r3
/* 800EA58C 000E74EC  81 9E 00 00 */	lwz r12, 0(r30)
/* 800EA590 000E74F0  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800EA594 000E74F4  7D 88 03 A6 */	mtlr r12
/* 800EA598 000E74F8  4E 80 00 21 */	blrl 
/* 800EA59C 000E74FC  80 03 00 04 */	lwz r0, 4(r3)
/* 800EA5A0 000E7500  2C 00 00 02 */	cmpwi r0, 2
/* 800EA5A4 000E7504  40 82 00 4C */	bne .L_800EA5F0
/* 800EA5A8 000E7508  C0 3E 02 D8 */	lfs f1, 0x2d8(r30)
/* 800EA5AC 000E750C  38 7E 01 E0 */	addi r3, r30, 0x1e0
/* 800EA5B0 000E7510  C0 5E 02 E0 */	lfs f2, 0x2e0(r30)
/* 800EA5B4 000E7514  4B F7 1A C1 */	bl updValue__9LifeGaugeFff
/* 800EA5B8 000E7518  80 BE 00 94 */	lwz r5, 0x94(r30)
/* 800EA5BC 000E751C  7F E4 FB 78 */	mr r4, r31
/* 800EA5C0 000E7520  80 1E 00 98 */	lwz r0, 0x98(r30)
/* 800EA5C4 000E7524  38 7E 01 E0 */	addi r3, r30, 0x1e0
/* 800EA5C8 000E7528  90 BE 01 E0 */	stw r5, 0x1e0(r30)
/* 800EA5CC 000E752C  90 1E 01 E4 */	stw r0, 0x1e4(r30)
/* 800EA5D0 000E7530  80 1E 00 9C */	lwz r0, 0x9c(r30)
/* 800EA5D4 000E7534  90 1E 01 E8 */	stw r0, 0x1e8(r30)
/* 800EA5D8 000E7538  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 800EA5DC 000E753C  C0 22 9A 34 */	lfs f1, lbl_803E9C34@sda21(r2)
/* 800EA5E0 000E7540  C0 05 01 D0 */	lfs f0, 0x1d0(r5)
/* 800EA5E4 000E7544  EC 01 00 24 */	fdivs f0, f1, f0
/* 800EA5E8 000E7548  D0 1E 02 14 */	stfs f0, 0x214(r30)
/* 800EA5EC 000E754C  4B F7 1A B9 */	bl refresh__9LifeGaugeFR8Graphics
.L_800EA5F0:
/* 800EA5F0 000E7550  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800EA5F4 000E7554  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800EA5F8 000E7558  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800EA5FC 000E755C  38 21 00 28 */	addi r1, r1, 0x28
/* 800EA600 000E7560  7C 08 03 A6 */	mtlr r0
/* 800EA604 000E7564  4E 80 00 20 */	blr 

.global refresh__8BombItemFR8Graphics
refresh__8BombItemFR8Graphics:
/* 800EA608 000E7568  7C 08 02 A6 */	mflr r0
/* 800EA60C 000E756C  3C A0 80 3A */	lis r5, gameflow@ha
/* 800EA610 000E7570  90 01 00 04 */	stw r0, 4(r1)
/* 800EA614 000E7574  38 A5 D7 B8 */	addi r5, r5, gameflow@l
/* 800EA618 000E7578  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800EA61C 000E757C  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800EA620 000E7580  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800EA624 000E7584  3B C4 00 00 */	addi r30, r4, 0
/* 800EA628 000E7588  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800EA62C 000E758C  3B A3 00 00 */	addi r29, r3, 0
/* 800EA630 000E7590  80 A5 01 DC */	lwz r5, 0x1dc(r5)
/* 800EA634 000E7594  88 05 01 24 */	lbz r0, 0x124(r5)
/* 800EA638 000E7598  28 00 00 00 */	cmplwi r0, 0
/* 800EA63C 000E759C  40 82 00 58 */	bne .L_800EA694
/* 800EA640 000E75A0  7F A3 EB 78 */	mr r3, r29
/* 800EA644 000E75A4  81 9D 00 00 */	lwz r12, 0(r29)
/* 800EA648 000E75A8  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800EA64C 000E75AC  7D 88 03 A6 */	mtlr r12
/* 800EA650 000E75B0  4E 80 00 21 */	blrl 
/* 800EA654 000E75B4  83 E3 00 04 */	lwz r31, 4(r3)
/* 800EA658 000E75B8  38 7D 00 00 */	addi r3, r29, 0
/* 800EA65C 000E75BC  38 9E 00 00 */	addi r4, r30, 0
/* 800EA660 000E75C0  48 00 B6 19 */	bl refresh__12ItemCreatureFR8Graphics
/* 800EA664 000E75C4  80 7D 02 20 */	lwz r3, 0x220(r29)
/* 800EA668 000E75C8  7F C4 F3 78 */	mr r4, r30
/* 800EA66C 000E75CC  38 A0 00 00 */	li r5, 0
/* 800EA670 000E75D0  4B F9 F4 7D */	bl updateInfo__8CollInfoFR8Graphicsb
/* 800EA674 000E75D4  2C 1F 00 02 */	cmpwi r31, 2
/* 800EA678 000E75D8  40 82 00 1C */	bne .L_800EA694
/* 800EA67C 000E75DC  7F A3 EB 78 */	mr r3, r29
/* 800EA680 000E75E0  81 9D 00 00 */	lwz r12, 0(r29)
/* 800EA684 000E75E4  7F C4 F3 78 */	mr r4, r30
/* 800EA688 000E75E8  81 8C 01 5C */	lwz r12, 0x15c(r12)
/* 800EA68C 000E75EC  7D 88 03 A6 */	mtlr r12
/* 800EA690 000E75F0  4E 80 00 21 */	blrl 
.L_800EA694:
/* 800EA694 000E75F4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800EA698 000E75F8  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800EA69C 000E75FC  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800EA6A0 000E7600  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800EA6A4 000E7604  38 21 00 30 */	addi r1, r1, 0x30
/* 800EA6A8 000E7608  7C 08 03 A6 */	mtlr r0
/* 800EA6AC 000E760C  4E 80 00 20 */	blr 

.global renderBlast__8BombItemFR8Graphics
renderBlast__8BombItemFR8Graphics:
/* 800EA6B0 000E7610  4E 80 00 20 */	blr 

.global dump__8BombItemFv
dump__8BombItemFv:
/* 800EA6B4 000E7614  7C 08 02 A6 */	mflr r0
/* 800EA6B8 000E7618  90 01 00 04 */	stw r0, 4(r1)
/* 800EA6BC 000E761C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800EA6C0 000E7620  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800EA6C4 000E7624  7C 7F 1B 78 */	mr r31, r3
/* 800EA6C8 000E7628  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EA6CC 000E762C  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800EA6D0 000E7630  7D 88 03 A6 */	mtlr r12
/* 800EA6D4 000E7634  4E 80 00 21 */	blrl 
/* 800EA6D8 000E7638  7F E3 FB 78 */	mr r3, r31
/* 800EA6DC 000E763C  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EA6E0 000E7640  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 800EA6E4 000E7644  7D 88 03 A6 */	mtlr r12
/* 800EA6E8 000E7648  4E 80 00 21 */	blrl 
/* 800EA6EC 000E764C  7F E3 FB 78 */	mr r3, r31
/* 800EA6F0 000E7650  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EA6F4 000E7654  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800EA6F8 000E7658  7D 88 03 A6 */	mtlr r12
/* 800EA6FC 000E765C  4E 80 00 21 */	blrl 
/* 800EA700 000E7660  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800EA704 000E7664  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800EA708 000E7668  38 21 00 30 */	addi r1, r1, 0x30
/* 800EA70C 000E766C  7C 08 03 A6 */	mtlr r0
/* 800EA710 000E7670  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BC5D8:
	.asciz "bombItem.cpp"
.balign 4
lbl_802BC5E8:
	.asciz "bombItem"
.balign 4
lbl_802BC5F4:
	.asciz "BombItem"
.balign 4
lbl_802BC600:
	.asciz "PaniAnimKeyListener"
.balign 4
lbl_802BC614:
	.asciz "EventTalker"
.balign 4
lbl_802BC620:
	.asciz "RefCountable"
.balign 4
lbl_802BC630:
	.asciz "Creature"
.balign 4
lbl_802BC63C:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
.balign 4
lbl_802BC650:
	.asciz "AICreature"
.balign 4
lbl_802BC65C:
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
lbl_802BC680:
	.asciz "ItemCreature"
.balign 4
lbl_802BC690:
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
lbl_802BC6BC:
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
.global __vt__8BombItem
__vt__8BombItem:
	.4byte __RTTI__8BombItem
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
	.4byte startAI__8BombItemFi
	.4byte getiMass__8BombItemFv
	.4byte getSize__8BombItemFv
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
	.4byte isVisible__8BombItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8BombItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8BombItemFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__12ItemCreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__8BombItemFR9CollEvent
	.4byte bounceCallback__10AICreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
	.4byte offwallCallback__8CreatureFP13DynCollObject
	.4byte stickCallback__8CreatureFP8Creature
	.4byte offstickCallback__8CreatureFP8Creature
	.4byte stickToCallback__8CreatureFP8Creature
	.4byte dump__8BombItemFv
	.4byte startWaterEffect__8CreatureFv
	.4byte finishWaterEffect__8CreatureFv
	.4byte isRopable__8CreatureFv
	.4byte mayIstick__8CreatureFv
	.4byte getFormationPri__8CreatureFv
	.4byte update__8BombItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__8BombItemFR8Graphics
	.4byte refresh2d__8BombItemFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__8BombItem
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
	.4byte renderTimer__8BombItemFR8Graphics
	.4byte renderBlast__8BombItemFR8Graphics

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E1828:
	.float 0.0
lbl_803E182C:
	.float 20.0
lbl_803E1830:
	.float 0.0
__RTTI__19PaniAnimKeyListener:
	.4byte lbl_802BC600
	.4byte 0
__RTTI__11EventTalker:
	.4byte lbl_802BC614
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802BC620
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802BC630
	.4byte lbl_802BC63C
__RTTI__10AICreature:
	.4byte lbl_802BC650
	.4byte lbl_802BC65C
__RTTI__12ItemCreature:
	.4byte lbl_802BC680
	.4byte lbl_802BC690
__RTTI__8BombItem:
	.4byte lbl_802BC5F4
	.4byte lbl_802BC6BC

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E9C28:
	.float 0.0
lbl_803E9C2C:
	.float 1.0
lbl_803E9C30:
	.float 5.0
lbl_803E9C34:
	.float 5000.0
