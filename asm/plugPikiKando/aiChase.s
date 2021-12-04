.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800F42BC 000F121C  38 A0 00 01 */	li r5, 1
/* 800F42C0 000F1220  4B F5 EA 51 */	bl loadShape__8GameFlowFPcb
/* 800F42C4 000F1224  90 7D 00 4C */	stw r3, 0x4c(r29)
/* 800F42C8 000F1228  38 7E 00 00 */	addi r3, r30, 0
/* 800F42CC 000F122C  38 9F 00 F0 */	addi r4, r31, 0xf0
/* 800F42D0 000F1230  38 A0 00 01 */	li r5, 1
/* 800F42D4 000F1234  4B F5 EA 3D */	bl loadShape__8GameFlowFPcb
/* 800F42D8 000F1238  90 7D 00 50 */	stw r3, 0x50(r29)
/* 800F42DC 000F123C  38 7E 00 00 */	addi r3, r30, 0
/* 800F42E0 000F1240  38 9F 01 0C */	addi r4, r31, 0x10c
/* 800F42E4 000F1244  38 A0 00 01 */	li r5, 1
/* 800F42E8 000F1248  4B F5 EA 29 */	bl loadShape__8GameFlowFPcb
/* 800F42EC 000F124C  90 7D 00 54 */	stw r3, 0x54(r29)
/* 800F42F0 000F1250  38 7E 00 00 */	addi r3, r30, 0
/* 800F42F4 000F1254  38 9F 01 28 */	addi r4, r31, 0x128
/* 800F42F8 000F1258  38 A0 00 01 */	li r5, 1
/* 800F42FC 000F125C  4B F5 EA 15 */	bl loadShape__8GameFlowFPcb
/* 800F4300 000F1260  90 7D 00 58 */	stw r3, 0x58(r29)
/* 800F4304 000F1264  38 7E 00 00 */	addi r3, r30, 0
/* 800F4308 000F1268  38 9F 01 28 */	addi r4, r31, 0x128
/* 800F430C 000F126C  38 A0 00 01 */	li r5, 1
/* 800F4310 000F1270  4B F5 EA 01 */	bl loadShape__8GameFlowFPcb
/* 800F4314 000F1274  90 7D 00 5C */	stw r3, 0x5c(r29)
/* 800F4318 000F1278  38 7E 00 00 */	addi r3, r30, 0
/* 800F431C 000F127C  38 9F 01 28 */	addi r4, r31, 0x128
/* 800F4320 000F1280  38 A0 00 01 */	li r5, 1
/* 800F4324 000F1284  4B F5 E9 ED */	bl loadShape__8GameFlowFPcb
/* 800F4328 000F1288  90 7D 00 60 */	stw r3, 0x60(r29)
/* 800F432C 000F128C  38 00 00 00 */	li r0, 0
/* 800F4330 000F1290  38 7D 00 00 */	addi r3, r29, 0
/* 800F4334 000F1294  90 1D 00 68 */	stw r0, 0x68(r29)
/* 800F4338 000F1298  90 1D 00 64 */	stw r0, 0x64(r29)
/* 800F433C 000F129C  48 00 00 0C */	b lbl_800F4348
lbl_800F4340:
/* 800F4340 000F12A0  54 C5 10 3A */	slwi r5, r6, 2
/* 800F4344 000F12A4  4B FF F7 7C */	b lbl_800F3AC0
lbl_800F4348:
/* 800F4348 000F12A8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F434C 000F12AC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F4350 000F12B0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F4354 000F12B4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F4358 000F12B8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800F435C 000F12BC  38 21 00 20 */	addi r1, r1, 0x20
/* 800F4360 000F12C0  7C 08 03 A6 */	mtlr r0
/* 800F4364 000F12C4  4E 80 00 20 */	blr 

.global getPelletShapeObject__7ItemMgrFii
getPelletShapeObject__7ItemMgrFii:
/* 800F4368 000F12C8  38 60 00 00 */	li r3, 0
/* 800F436C 000F12CC  4E 80 00 20 */	blr 

.global initialise__7ItemMgrFv
initialise__7ItemMgrFv:
/* 800F4370 000F12D0  7C 08 02 A6 */	mflr r0
/* 800F4374 000F12D4  3C 80 80 2C */	lis r4, lbl_802BE4F8@ha
/* 800F4378 000F12D8  90 01 00 04 */	stw r0, 4(r1)
/* 800F437C 000F12DC  94 21 FA 98 */	stwu r1, -0x568(r1)
/* 800F4380 000F12E0  BF 01 05 48 */	stmw r24, 0x548(r1)
/* 800F4384 000F12E4  3B E3 00 00 */	addi r31, r3, 0
/* 800F4388 000F12E8  3B C4 E4 F8 */	addi r30, r4, lbl_802BE4F8@l
/* 800F438C 000F12EC  38 60 00 64 */	li r3, 0x64
/* 800F4390 000F12F0  4B F5 2C 75 */	bl alloc__6SystemFUl
/* 800F4394 000F12F4  3B 23 00 00 */	addi r25, r3, 0
/* 800F4398 000F12F8  7F 23 CB 79 */	or. r3, r25, r25
/* 800F439C 000F12FC  41 82 00 0C */	beq lbl_800F43A8
/* 800F43A0 000F1300  7F E4 FB 78 */	mr r4, r31
/* 800F43A4 000F1304  4B FF E9 A9 */	bl __ct__13MeltingPotMgrFP7ItemMgr
lbl_800F43A8:
/* 800F43A8 000F1308  93 3F 00 68 */	stw r25, 0x68(r31)
/* 800F43AC 000F130C  7F E3 FB 78 */	mr r3, r31
/* 800F43B0 000F1310  4B FE DF 69 */	bl beginRegister__13PolyObjectMgrFv
/* 800F43B4 000F1314  38 60 03 C8 */	li r3, 0x3c8
/* 800F43B8 000F1318  4B F5 2C 4D */	bl alloc__6SystemFUl
/* 800F43BC 000F131C  7C 78 1B 79 */	or. r24, r3, r3
/* 800F43C0 000F1320  41 82 00 0C */	beq lbl_800F43CC
/* 800F43C4 000F1324  7F 03 C3 78 */	mr r3, r24
/* 800F43C8 000F1328  48 00 37 65 */	bl __ct__19NaviDemoSunsetStartFv
lbl_800F43CC:
/* 800F43CC 000F132C  38 7F 00 00 */	addi r3, r31, 0
/* 800F43D0 000F1330  38 B8 00 00 */	addi r5, r24, 0
/* 800F43D4 000F1334  38 80 00 1B */	li r4, 0x1b
/* 800F43D8 000F1338  38 C0 03 C8 */	li r6, 0x3c8
/* 800F43DC 000F133C  4B FE DF 41 */	bl registerClass__13PolyObjectMgrFiP8Creaturei
/* 800F43E0 000F1340  38 60 03 C8 */	li r3, 0x3c8
/* 800F43E4 000F1344  4B F5 2C 21 */	bl alloc__6SystemFUl
/* 800F43E8 000F1348  7C 78 1B 79 */	or. r24, r3, r3
/* 800F43EC 000F134C  41 82 00 0C */	beq lbl_800F43F8
/* 800F43F0 000F1350  7F 03 C3 78 */	mr r3, r24
/* 800F43F4 000F1354  48 00 37 A5 */	bl __ct__18NaviDemoSunsetGoalFv
lbl_800F43F8:
/* 800F43F8 000F1358  38 7F 00 00 */	addi r3, r31, 0
/* 800F43FC 000F135C  38 B8 00 00 */	addi r5, r24, 0
/* 800F4400 000F1360  38 80 00 1C */	li r4, 0x1c
/* 800F4404 000F1364  38 C0 03 C8 */	li r6, 0x3c8
/* 800F4408 000F1368  4B FE DF 15 */	bl registerClass__13PolyObjectMgrFiP8Creaturei
/* 800F440C 000F136C  38 60 00 18 */	li r3, 0x18
/* 800F4410 000F1370  4B F5 2B F5 */	bl alloc__6SystemFUl
/* 800F4414 000F1374  3B A3 00 00 */	addi r29, r3, 0
/* 800F4418 000F1378  7F BA EB 79 */	or. r26, r29, r29
/* 800F441C 000F137C  41 82 00 B0 */	beq lbl_800F44CC
/* 800F4420 000F1380  3C 60 80 3A */	lis r3, gameflow@ha
/* 800F4424 000F1384  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800F4428 000F1388  38 9E 01 40 */	addi r4, r30, 0x140
/* 800F442C 000F138C  38 A0 00 01 */	li r5, 1
/* 800F4430 000F1390  4B F5 E8 E1 */	bl loadShape__8GameFlowFPcb
/* 800F4434 000F1394  3C 80 80 23 */	lis r4, __vt__11AnimContext@ha
/* 800F4438 000F1398  4C C6 31 82 */	crclr 6
/* 800F443C 000F139C  38 04 88 D0 */	addi r0, r4, __vt__11AnimContext@l
/* 800F4440 000F13A0  90 1D 00 14 */	stw r0, 0x14(r29)
/* 800F4444 000F13A4  38 00 00 00 */	li r0, 0
/* 800F4448 000F13A8  3B 63 00 00 */	addi r27, r3, 0
/* 800F444C 000F13AC  90 1D 00 08 */	stw r0, 8(r29)
/* 800F4450 000F13B0  38 61 04 B4 */	addi r3, r1, 0x4b4
/* 800F4454 000F13B4  38 9E 00 0C */	addi r4, r30, 0xc
/* 800F4458 000F13B8  C0 02 9C 0C */	lfs f0, lbl_803E9E0C@sda21(r2)
/* 800F445C 000F13BC  38 BE 01 60 */	addi r5, r30, 0x160
/* 800F4460 000F13C0  38 DE 01 6C */	addi r6, r30, 0x16c
/* 800F4464 000F13C4  D0 1D 00 0C */	stfs f0, 0xc(r29)
/* 800F4468 000F13C8  C0 02 9C 10 */	lfs f0, lbl_803E9E10@sda21(r2)
/* 800F446C 000F13CC  D0 1D 00 10 */	stfs f0, 0x10(r29)
/* 800F4470 000F13D0  93 7D 00 00 */	stw r27, 0(r29)
/* 800F4474 000F13D4  80 FD 00 00 */	lwz r7, 0(r29)
/* 800F4478 000F13D8  90 07 00 24 */	stw r0, 0x24(r7)
/* 800F447C 000F13DC  48 12 21 1D */	bl sprintf
/* 800F4480 000F13E0  38 60 00 B8 */	li r3, 0xb8
/* 800F4484 000F13E4  4B F5 2B 81 */	bl alloc__6SystemFUl
/* 800F4488 000F13E8  3B 23 00 00 */	addi r25, r3, 0
/* 800F448C 000F13EC  7F 23 CB 79 */	or. r3, r25, r25
/* 800F4490 000F13F0  41 82 00 1C */	beq lbl_800F44AC
/* 800F4494 000F13F4  3C C0 00 01 */	lis r6, 0x00008000@ha
/* 800F4498 000F13F8  38 9B 00 00 */	addi r4, r27, 0
/* 800F449C 000F13FC  38 A1 04 B4 */	addi r5, r1, 0x4b4
/* 800F44A0 000F1400  38 C6 80 00 */	addi r6, r6, 0x00008000@l
/* 800F44A4 000F1404  38 E0 00 00 */	li r7, 0
/* 800F44A8 000F1408  4B F5 C3 FD */	bl __ct__7AnimMgrFP5ShapePciPc
lbl_800F44AC:
/* 800F44AC 000F140C  93 3D 00 04 */	stw r25, 4(r29)
/* 800F44B0 000F1410  38 1E 01 60 */	addi r0, r30, 0x160
/* 800F44B4 000F1414  38 BA 00 08 */	addi r5, r26, 8
/* 800F44B8 000F1418  80 7D 00 04 */	lwz r3, 4(r29)
/* 800F44BC 000F141C  38 80 00 00 */	li r4, 0
/* 800F44C0 000F1420  90 03 00 04 */	stw r0, 4(r3)
/* 800F44C4 000F1424  80 7A 00 00 */	lwz r3, 0(r26)
/* 800F44C8 000F1428  4B F4 0B 9D */	bl overrideAnim__9BaseShapeFiP11AnimContext
lbl_800F44CC:
/* 800F44CC 000F142C  80 9F 00 88 */	lwz r4, 0x88(r31)
/* 800F44D0 000F1430  38 60 00 18 */	li r3, 0x18
/* 800F44D4 000F1434  93 A4 00 0C */	stw r29, 0xc(r4)
/* 800F44D8 000F1438  4B F5 2B 2D */	bl alloc__6SystemFUl
/* 800F44DC 000F143C  3B A3 00 00 */	addi r29, r3, 0
/* 800F44E0 000F1440  7F BA EB 79 */	or. r26, r29, r29
/* 800F44E4 000F1444  41 82 00 B0 */	beq lbl_800F4594
/* 800F44E8 000F1448  3C 60 80 3A */	lis r3, gameflow@ha
/* 800F44EC 000F144C  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800F44F0 000F1450  38 9E 01 78 */	addi r4, r30, 0x178
/* 800F44F4 000F1454  38 A0 00 01 */	li r5, 1
/* 800F44F8 000F1458  4B F5 E8 19 */	bl loadShape__8GameFlowFPcb
/* 800F44FC 000F145C  3C 80 80 23 */	lis r4, __vt__11AnimContext@ha
/* 800F4500 000F1460  4C C6 31 82 */	crclr 6
/* 800F4504 000F1464  38 04 88 D0 */	addi r0, r4, __vt__11AnimContext@l
/* 800F4508 000F1468  90 1D 00 14 */	stw r0, 0x14(r29)
/* 800F450C 000F146C  38 00 00 00 */	li r0, 0
/* 800F4510 000F1470  3B 63 00 00 */	addi r27, r3, 0
/* 800F4514 000F1474  90 1D 00 08 */	stw r0, 8(r29)
/* 800F4518 000F1478  38 61 04 34 */	addi r3, r1, 0x434
/* 800F451C 000F147C  38 9E 00 0C */	addi r4, r30, 0xc
/* 800F4520 000F1480  C0 02 9C 0C */	lfs f0, lbl_803E9E0C@sda21(r2)
/* 800F4524 000F1484  38 DE 01 6C */	addi r6, r30, 0x16c
/* 800F4528 000F1488  38 AD CF F4 */	addi r5, r13, lbl_803E1D14@sda21
/* 800F452C 000F148C  D0 1D 00 0C */	stfs f0, 0xc(r29)
/* 800F4530 000F1490  C0 02 9C 10 */	lfs f0, lbl_803E9E10@sda21(r2)
/* 800F4534 000F1494  D0 1D 00 10 */	stfs f0, 0x10(r29)
/* 800F4538 000F1498  93 7D 00 00 */	stw r27, 0(r29)
/* 800F453C 000F149C  80 FD 00 00 */	lwz r7, 0(r29)
/* 800F4540 000F14A0  90 07 00 24 */	stw r0, 0x24(r7)
/* 800F4544 000F14A4  48 12 20 55 */	bl sprintf
/* 800F4548 000F14A8  38 60 00 B8 */	li r3, 0xb8
/* 800F454C 000F14AC  4B F5 2A B9 */	bl alloc__6SystemFUl
/* 800F4550 000F14B0  3B 23 00 00 */	addi r25, r3, 0
/* 800F4554 000F14B4  7F 23 CB 79 */	or. r3, r25, r25
/* 800F4558 000F14B8  41 82 00 1C */	beq lbl_800F4574
/* 800F455C 000F14BC  3C C0 00 01 */	lis r6, 0x00008000@ha
/* 800F4560 000F14C0  38 9B 00 00 */	addi r4, r27, 0
/* 800F4564 000F14C4  38 A1 04 34 */	addi r5, r1, 0x434
/* 800F4568 000F14C8  38 C6 80 00 */	addi r6, r6, 0x00008000@l
/* 800F456C 000F14CC  38 E0 00 00 */	li r7, 0
/* 800F4570 000F14D0  4B F5 C3 35 */	bl __ct__7AnimMgrFP5ShapePciPc
lbl_800F4574:
/* 800F4574 000F14D4  93 3D 00 04 */	stw r25, 4(r29)
/* 800F4578 000F14D8  38 0D CF F4 */	addi r0, r13, lbl_803E1D14@sda21
/* 800F457C 000F14DC  38 BA 00 08 */	addi r5, r26, 8
/* 800F4580 000F14E0  80 7D 00 04 */	lwz r3, 4(r29)
/* 800F4584 000F14E4  38 80 00 00 */	li r4, 0
/* 800F4588 000F14E8  90 03 00 04 */	stw r0, 4(r3)
/* 800F458C 000F14EC  80 7A 00 00 */	lwz r3, 0(r26)
/* 800F4590 000F14F0  4B F4 0A D5 */	bl overrideAnim__9BaseShapeFiP11AnimContext
lbl_800F4594:
/* 800F4594 000F14F4  80 9F 00 88 */	lwz r4, 0x88(r31)
/* 800F4598 000F14F8  38 60 00 58 */	li r3, 0x58
/* 800F459C 000F14FC  93 A4 00 08 */	stw r29, 8(r4)
/* 800F45A0 000F1500  4B F5 2A 65 */	bl alloc__6SystemFUl
/* 800F45A4 000F1504  3B A3 00 00 */	addi r29, r3, 0
/* 800F45A8 000F1508  7F BA EB 79 */	or. r26, r29, r29
/* 800F45AC 000F150C  41 82 01 38 */	beq lbl_800F46E4
/* 800F45B0 000F1510  3C 60 80 2B */	lis r3, __vt__12CreatureProp@ha
/* 800F45B4 000F1514  38 03 F9 38 */	addi r0, r3, __vt__12CreatureProp@l
/* 800F45B8 000F1518  90 1D 00 54 */	stw r0, 0x54(r29)
/* 800F45BC 000F151C  38 00 00 00 */	li r0, 0
/* 800F45C0 000F1520  38 61 01 90 */	addi r3, r1, 0x190
/* 800F45C4 000F1524  90 1D 00 00 */	stw r0, 0(r29)
/* 800F45C8 000F1528  38 8D CF E0 */	addi r4, r13, lbl_803E1D00@sda21
/* 800F45CC 000F152C  4B F5 C5 0D */	bl Set__5ayuIDFPc
/* 800F45D0 000F1530  80 01 01 90 */	lwz r0, 0x190(r1)
/* 800F45D4 000F1534  38 A1 01 8C */	addi r5, r1, 0x18c
/* 800F45D8 000F1538  C0 22 9C 14 */	lfs f1, lbl_803E9E14@sda21(r2)
/* 800F45DC 000F153C  7F 44 D3 78 */	mr r4, r26
/* 800F45E0 000F1540  90 01 01 8C */	stw r0, 0x18c(r1)
/* 800F45E4 000F1544  C0 42 9C 0C */	lfs f2, lbl_803E9E0C@sda21(r2)
/* 800F45E8 000F1548  38 7A 00 04 */	addi r3, r26, 4
/* 800F45EC 000F154C  C0 62 9C 18 */	lfs f3, lbl_803E9E18@sda21(r2)
/* 800F45F0 000F1550  38 C0 00 00 */	li r6, 0
/* 800F45F4 000F1554  4B FA 44 4D */	bl "__ct__7Parm<f>FP10Parametersfff5ayuIDPc"
/* 800F45F8 000F1558  38 61 01 98 */	addi r3, r1, 0x198
/* 800F45FC 000F155C  38 8D CF E4 */	addi r4, r13, lbl_803E1D04@sda21
/* 800F4600 000F1560  4B F5 C4 D9 */	bl Set__5ayuIDFPc
/* 800F4604 000F1564  80 01 01 98 */	lwz r0, 0x198(r1)
/* 800F4608 000F1568  38 A1 01 94 */	addi r5, r1, 0x194
/* 800F460C 000F156C  C0 22 9C 14 */	lfs f1, lbl_803E9E14@sda21(r2)
/* 800F4610 000F1570  7F 44 D3 78 */	mr r4, r26
/* 800F4614 000F1574  90 01 01 94 */	stw r0, 0x194(r1)
/* 800F4618 000F1578  C0 42 9C 0C */	lfs f2, lbl_803E9E0C@sda21(r2)
/* 800F461C 000F157C  38 7A 00 14 */	addi r3, r26, 0x14
/* 800F4620 000F1580  C0 62 9C 18 */	lfs f3, lbl_803E9E18@sda21(r2)
/* 800F4624 000F1584  38 C0 00 00 */	li r6, 0
/* 800F4628 000F1588  4B FA 44 19 */	bl "__ct__7Parm<f>FP10Parametersfff5ayuIDPc"
/* 800F462C 000F158C  38 61 01 A0 */	addi r3, r1, 0x1a0
/* 800F4630 000F1590  38 8D CF E8 */	addi r4, r13, lbl_803E1D08@sda21
/* 800F4634 000F1594  4B F5 C4 A5 */	bl Set__5ayuIDFPc
/* 800F4638 000F1598  80 01 01 A0 */	lwz r0, 0x1a0(r1)
/* 800F463C 000F159C  38 A1 01 9C */	addi r5, r1, 0x19c
/* 800F4640 000F15A0  C0 22 9C 1C */	lfs f1, lbl_803E9E1C@sda21(r2)
/* 800F4644 000F15A4  7F 44 D3 78 */	mr r4, r26
/* 800F4648 000F15A8  90 01 01 9C */	stw r0, 0x19c(r1)
/* 800F464C 000F15AC  C0 42 9C 0C */	lfs f2, lbl_803E9E0C@sda21(r2)
/* 800F4650 000F15B0  38 7A 00 24 */	addi r3, r26, 0x24
/* 800F4654 000F15B4  C0 62 9C 18 */	lfs f3, lbl_803E9E18@sda21(r2)
/* 800F4658 000F15B8  38 C0 00 00 */	li r6, 0
/* 800F465C 000F15BC  4B FA 43 E5 */	bl "__ct__7Parm<f>FP10Parametersfff5ayuIDPc"
/* 800F4660 000F15C0  38 61 01 A8 */	addi r3, r1, 0x1a8
/* 800F4664 000F15C4  38 8D CF EC */	addi r4, r13, lbl_803E1D0C@sda21
/* 800F4668 000F15C8  4B F5 C4 71 */	bl Set__5ayuIDFPc
/* 800F466C 000F15CC  80 01 01 A8 */	lwz r0, 0x1a8(r1)
/* 800F4670 000F15D0  38 A1 01 A4 */	addi r5, r1, 0x1a4
/* 800F4674 000F15D4  C0 22 9C 20 */	lfs f1, lbl_803E9E20@sda21(r2)
/* 800F4678 000F15D8  7F 44 D3 78 */	mr r4, r26
/* 800F467C 000F15DC  90 01 01 A4 */	stw r0, 0x1a4(r1)
/* 800F4680 000F15E0  C0 42 9C 24 */	lfs f2, lbl_803E9E24@sda21(r2)
/* 800F4684 000F15E4  38 7A 00 34 */	addi r3, r26, 0x34
/* 800F4688 000F15E8  C0 62 9C 28 */	lfs f3, lbl_803E9E28@sda21(r2)
/* 800F468C 000F15EC  38 C0 00 00 */	li r6, 0
/* 800F4690 000F15F0  4B FA 43 B1 */	bl "__ct__7Parm<f>FP10Parametersfff5ayuIDPc"
/* 800F4694 000F15F4  38 61 01 B0 */	addi r3, r1, 0x1b0
/* 800F4698 000F15F8  38 8D CF F0 */	addi r4, r13, lbl_803E1D10@sda21
/* 800F469C 000F15FC  4B F5 C4 3D */	bl Set__5ayuIDFPc
/* 800F46A0 000F1600  80 01 01 B0 */	lwz r0, 0x1b0(r1)
/* 800F46A4 000F1604  38 A1 01 AC */	addi r5, r1, 0x1ac
/* 800F46A8 000F1608  C0 22 9C 2C */	lfs f1, lbl_803E9E2C@sda21(r2)
/* 800F46AC 000F160C  7F 44 D3 78 */	mr r4, r26
/* 800F46B0 000F1610  90 01 01 AC */	stw r0, 0x1ac(r1)
/* 800F46B4 000F1614  C0 42 9C 24 */	lfs f2, lbl_803E9E24@sda21(r2)
/* 800F46B8 000F1618  38 7A 00 44 */	addi r3, r26, 0x44
/* 800F46BC 000F161C  C0 62 9C 28 */	lfs f3, lbl_803E9E28@sda21(r2)
/* 800F46C0 000F1620  38 C0 00 00 */	li r6, 0
/* 800F46C4 000F1624  4B FA 43 7D */	bl "__ct__7Parm<f>FP10Parametersfff5ayuIDPc"
/* 800F46C8 000F1628  3C 60 80 2C */	lis r3, __vt__12BombItemProp@ha
/* 800F46CC 000F162C  38 03 ED 90 */	addi r0, r3, __vt__12BombItemProp@l
/* 800F46D0 000F1630  90 1D 00 54 */	stw r0, 0x54(r29)
/* 800F46D4 000F1634  C0 02 9C 20 */	lfs f0, lbl_803E9E20@sda21(r2)
/* 800F46D8 000F1638  D0 1D 00 10 */	stfs f0, 0x10(r29)
/* 800F46DC 000F163C  C0 02 9C 30 */	lfs f0, lbl_803E9E30@sda21(r2)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x61694368
	.4byte 0x6173652e
	.4byte 0x63707000
	.4byte 0x61695261
	.4byte 0x6e646f6d
	.4byte 0x426f6964
	.4byte 0
	.4byte 0x41637443
	.4byte 0x68617365
	.4byte 0
	.4byte 0x52656365
	.4byte 0x69766572
	.4byte 0x3c50696b
	.4byte 0x693e0000
	.4byte 0x803E0198
	.4byte 0
	.4byte 0
	.4byte 0x803E0198
	.4byte 0
	.4byte 0x803E01a8
	.4byte 0
	.4byte 0
.global __vt__8ActChase
__vt__8ActChase:
	.4byte __RTTI__8ActChase
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
	.4byte __dt__8ActChaseFv
	.4byte init__8ActChaseFP8Creature
	.4byte exec__8ActChaseFv
	.4byte cleanup__8ActChaseFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
	.4byte 0x41637443
	.4byte 0x68617365
	.4byte 0x3a3a496e
	.4byte 0x69746961
	.4byte 0x6c697365
	.4byte 0x72000000
	.4byte 0x41637469
	.4byte 0x6f6e3a3a
	.4byte 0x496e6974
	.4byte 0x69616c69
	.4byte 0x73657200
	.4byte 0x803E01b8
	.4byte 0
	.4byte 0
.global __vt__Q28ActChase11Initialiser
__vt__Q28ActChase11Initialiser:
	.4byte __RTTI__Q28ActChase11Initialiser
	.4byte 0
	.4byte initialise__Q28ActChase11InitialiserFP6Action
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
.global lbl_803E0158
lbl_803E0158:
	.4byte 0x3F000000
.global lbl_803E015C
lbl_803E015C:
	.4byte 0x3DCCCCCD
	.4byte 0x802B6090
	.4byte 0x00000000
	.4byte 0x802B60A4
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0170
	.4byte 0x802B60B4
.global __RTTI__9ActKinoko
__RTTI__9ActKinoko:
	.4byte 0x802b6084
	.4byte 0x802b60c0
.global lbl_803E0188
lbl_803E0188:
	.4byte 0x00000000
.global lbl_803E018C
lbl_803E018C:
	.4byte 0x00000000
.global lbl_803E0190
lbl_803E0190:
	.4byte 0x00000000
.global lbl_803E0194
lbl_803E0194:
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EA8E4
lbl_803EA8E4:
	.4byte 0x447A0000
.global lbl_803EA8E8
lbl_803EA8E8:
	.4byte 0x3E99999A
.global lbl_803EA8EC
lbl_803EA8EC:
	.4byte 0x3E4CCCCD
.global lbl_803EA8F0
lbl_803EA8F0:
	.4byte 0x41C80000
.global lbl_803EA8F4
lbl_803EA8F4:
	.4byte 0x40A00000
.global lbl_803EA8F8
lbl_803EA8F8:
	.4byte 0x43C80000
.global lbl_803EA8FC
lbl_803EA8FC:
	.4byte 0x43960000
.global lbl_803EA900
lbl_803EA900:
	.4byte 0x41800000
	.4byte 0x00000000
.global lbl_803EA908
lbl_803EA908:
	.4byte 0x00000000
.global lbl_803EA90C
lbl_803EA90C:
	.4byte 0x3F800000
.global lbl_803EA910
lbl_803EA910:
	.4byte 0x46FFFE00
.global lbl_803EA914
lbl_803EA914:
	.4byte 0x40000000
.global lbl_803EA918
lbl_803EA918:
	.4byte 0x3F000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EBFBC
lbl_803EBFBC:
	.4byte 0x3F800000
.global lbl_803EBFC0
lbl_803EBFC0:
	.4byte 0x466A6000
.global lbl_803EBFC4
lbl_803EBFC4:
	.4byte 0x41F00000
.global lbl_803EBFC8
lbl_803EBFC8:
	.4byte 0x42F00000
.global lbl_803EBFCC
lbl_803EBFCC:
	.4byte 0x3F5F66F3
.global lbl_803EBFD0
lbl_803EBFD0:
	.4byte 0x43C80000
.global lbl_803EBFD4
lbl_803EBFD4:
	.4byte 0x43340000
.global lbl_803EBFD8
lbl_803EBFD8:
	.4byte 0x428C0000
.global lbl_803EBFDC
lbl_803EBFDC:
	.4byte 0x42200000
.global lbl_803EBFE0
lbl_803EBFE0:
	.4byte 0x41A00000
.global lbl_803EBFE4
lbl_803EBFE4:
	.4byte 0x41100000
.global lbl_803EBFE8
lbl_803EBFE8:
	.4byte 0x40A00000
.global lbl_803EBFEC
lbl_803EBFEC:
	.4byte 0x43960000
.global lbl_803EBFF0
lbl_803EBFF0:
	.4byte 0x43480000
