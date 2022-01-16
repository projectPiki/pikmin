.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global actByEvent__22TAIAhitCheckFlyingPikiFR9TekiEvent
actByEvent__22TAIAhitCheckFlyingPikiFR9TekiEvent:
/* 801A8490 001A53F0  7C 08 02 A6 */	mflr r0
/* 801A8494 001A53F4  90 01 00 04 */	stw r0, 4(r1)
/* 801A8498 001A53F8  94 21 FF F8 */	stwu r1, -8(r1)
/* 801A849C 001A53FC  80 04 00 00 */	lwz r0, 0(r4)
/* 801A84A0 001A5400  2C 00 00 01 */	cmpwi r0, 1
/* 801A84A4 001A5404  40 82 00 28 */	bne lbl_801A84CC
/* 801A84A8 001A5408  80 64 00 08 */	lwz r3, 8(r4)
/* 801A84AC 001A540C  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 801A84B0 001A5410  2C 00 00 00 */	cmpwi r0, 0
/* 801A84B4 001A5414  40 82 00 18 */	bne lbl_801A84CC
/* 801A84B8 001A5418  4B F2 00 9D */	bl getState__4PikiFv
/* 801A84BC 001A541C  2C 03 00 0E */	cmpwi r3, 0xe
/* 801A84C0 001A5420  40 82 00 0C */	bne lbl_801A84CC
/* 801A84C4 001A5424  38 60 00 01 */	li r3, 1
/* 801A84C8 001A5428  48 00 00 08 */	b lbl_801A84D0
lbl_801A84CC:
/* 801A84CC 001A542C  38 60 00 00 */	li r3, 0
lbl_801A84D0:
/* 801A84D0 001A5430  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801A84D4 001A5434  38 21 00 08 */	addi r1, r1, 8
/* 801A84D8 001A5438  7C 08 03 A6 */	mtlr r0
/* 801A84DC 001A543C  4E 80 00 20 */	blr 

.global act__13TAIAdeadCheckFR4Teki
act__13TAIAdeadCheckFR4Teki:
/* 801A84E0 001A5440  C0 24 00 58 */	lfs f1, 0x58(r4)
/* 801A84E4 001A5444  C0 02 B5 88 */	lfs f0, lbl_803EB788@sda21(r2)
/* 801A84E8 001A5448  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A84EC 001A544C  4C 40 13 82 */	cror 2, 0, 2
/* 801A84F0 001A5450  7C 00 00 26 */	mfcr r0
/* 801A84F4 001A5454  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 801A84F8 001A5458  4E 80 00 20 */	blr 

.global start__7TAIAdieFR4Teki
start__7TAIAdieFR4Teki:
/* 801A84FC 001A545C  7C 08 02 A6 */	mflr r0
/* 801A8500 001A5460  7C 83 23 78 */	mr r3, r4
/* 801A8504 001A5464  90 01 00 04 */	stw r0, 4(r1)
/* 801A8508 001A5468  94 21 FF F8 */	stwu r1, -8(r1)
/* 801A850C 001A546C  81 84 00 00 */	lwz r12, 0(r4)
/* 801A8510 001A5470  81 8C 01 78 */	lwz r12, 0x178(r12)
/* 801A8514 001A5474  7D 88 03 A6 */	mtlr r12
/* 801A8518 001A5478  4E 80 00 21 */	blrl 
/* 801A851C 001A547C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801A8520 001A5480  38 21 00 08 */	addi r1, r1, 8
/* 801A8524 001A5484  7C 08 03 A6 */	mtlr r0
/* 801A8528 001A5488  4E 80 00 20 */	blr 

.global start__9TAIAdyingFR4Teki
start__9TAIAdyingFR4Teki:
/* 801A852C 001A548C  7C 08 02 A6 */	mflr r0
/* 801A8530 001A5490  90 01 00 04 */	stw r0, 4(r1)
/* 801A8534 001A5494  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A8538 001A5498  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A853C 001A549C  7C 9F 23 78 */	mr r31, r4
/* 801A8540 001A54A0  48 00 47 39 */	bl start__10TAIAmotionFR4Teki
/* 801A8544 001A54A4  7F E3 FB 78 */	mr r3, r31
/* 801A8548 001A54A8  80 8D F6 3C */	lwz r4, TEKI_OPTION_ALIVE__5BTeki@sda21(r13)
/* 801A854C 001A54AC  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A8550 001A54B0  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 801A8554 001A54B4  7D 88 03 A6 */	mtlr r12
/* 801A8558 001A54B8  4E 80 00 21 */	blrl 
/* 801A855C 001A54BC  C0 02 B5 88 */	lfs f0, lbl_803EB788@sda21(r2)
/* 801A8560 001A54C0  D0 1F 00 58 */	stfs f0, 0x58(r31)
/* 801A8564 001A54C4  80 1F 03 20 */	lwz r0, 0x320(r31)
/* 801A8568 001A54C8  2C 00 00 16 */	cmpwi r0, 0x16
/* 801A856C 001A54CC  41 82 00 38 */	beq lbl_801A85A4
/* 801A8570 001A54D0  40 80 00 70 */	bge lbl_801A85E0
/* 801A8574 001A54D4  2C 00 00 10 */	cmpwi r0, 0x10
/* 801A8578 001A54D8  41 82 00 08 */	beq lbl_801A8580
/* 801A857C 001A54DC  48 00 00 64 */	b lbl_801A85E0
lbl_801A8580:
/* 801A8580 001A54E0  7F E3 FB 78 */	mr r3, r31
/* 801A8584 001A54E4  80 8D F6 34 */	lwz r4, TEKI_OPTION_LIFE_GAUGE_VISIBLE__5BTeki@sda21(r13)
/* 801A8588 001A54E8  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A858C 001A54EC  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 801A8590 001A54F0  7D 88 03 A6 */	mtlr r12
/* 801A8594 001A54F4  4E 80 00 21 */	blrl 
/* 801A8598 001A54F8  7F E3 FB 78 */	mr r3, r31
/* 801A859C 001A54FC  4B F9 D6 C9 */	bl createDeadEffect__5BTekiFv
/* 801A85A0 001A5500  48 00 00 68 */	b lbl_801A8608
lbl_801A85A4:
/* 801A85A4 001A5504  7F E3 FB 78 */	mr r3, r31
/* 801A85A8 001A5508  80 8D F6 34 */	lwz r4, TEKI_OPTION_LIFE_GAUGE_VISIBLE__5BTeki@sda21(r13)
/* 801A85AC 001A550C  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A85B0 001A5510  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 801A85B4 001A5514  7D 88 03 A6 */	mtlr r12
/* 801A85B8 001A5518  4E 80 00 21 */	blrl 
/* 801A85BC 001A551C  7F E3 FB 78 */	mr r3, r31
/* 801A85C0 001A5520  80 8D F6 30 */	lwz r4, TEKI_OPTION_SHADOW_VISIBLE__5BTeki@sda21(r13)
/* 801A85C4 001A5524  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A85C8 001A5528  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 801A85CC 001A552C  7D 88 03 A6 */	mtlr r12
/* 801A85D0 001A5530  4E 80 00 21 */	blrl 
/* 801A85D4 001A5534  7F E3 FB 78 */	mr r3, r31
/* 801A85D8 001A5538  4B F9 D6 8D */	bl createDeadEffect__5BTekiFv
/* 801A85DC 001A553C  48 00 00 2C */	b lbl_801A8608
lbl_801A85E0:
/* 801A85E0 001A5540  7F E3 FB 78 */	mr r3, r31
/* 801A85E4 001A5544  80 8D F6 30 */	lwz r4, TEKI_OPTION_SHADOW_VISIBLE__5BTeki@sda21(r13)
/* 801A85E8 001A5548  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A85EC 001A554C  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 801A85F0 001A5550  7D 88 03 A6 */	mtlr r12
/* 801A85F4 001A5554  4E 80 00 21 */	blrl 
/* 801A85F8 001A5558  7F E3 FB 78 */	mr r3, r31
/* 801A85FC 001A555C  4B F9 D6 69 */	bl createDeadEffect__5BTekiFv
/* 801A8600 001A5560  7F E3 FB 78 */	mr r3, r31
/* 801A8604 001A5564  4B F9 D8 65 */	bl spawnItems__5BTekiFv
lbl_801A8608:
/* 801A8608 001A5568  7F E3 FB 78 */	mr r3, r31
/* 801A860C 001A556C  4B F9 D6 35 */	bl releasePlatCollisions__5BTekiFv
/* 801A8610 001A5570  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A8614 001A5574  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A8618 001A5578  38 21 00 18 */	addi r1, r1, 0x18
/* 801A861C 001A557C  7C 08 03 A6 */	mtlr r0
/* 801A8620 001A5580  4E 80 00 20 */	blr 

.global act__9TAIAdyingFR4Teki
act__9TAIAdyingFR4Teki:
/* 801A8624 001A5584  7C 08 02 A6 */	mflr r0
/* 801A8628 001A5588  90 01 00 04 */	stw r0, 4(r1)
/* 801A862C 001A558C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801A8630 001A5590  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801A8634 001A5594  7C 9F 23 78 */	mr r31, r4
/* 801A8638 001A5598  80 64 02 CC */	lwz r3, 0x2cc(r4)
/* 801A863C 001A559C  80 03 00 38 */	lwz r0, 0x38(r3)
/* 801A8640 001A55A0  2C 00 00 00 */	cmpwi r0, 0
/* 801A8644 001A55A4  40 80 00 74 */	bge lbl_801A86B8
/* 801A8648 001A55A8  80 1F 03 20 */	lwz r0, 0x320(r31)
/* 801A864C 001A55AC  2C 00 00 16 */	cmpwi r0, 0x16
/* 801A8650 001A55B0  41 82 00 38 */	beq lbl_801A8688
/* 801A8654 001A55B4  40 80 00 10 */	bge lbl_801A8664
/* 801A8658 001A55B8  2C 00 00 10 */	cmpwi r0, 0x10
/* 801A865C 001A55BC  41 82 00 14 */	beq lbl_801A8670
/* 801A8660 001A55C0  48 00 00 3C */	b lbl_801A869C
lbl_801A8664:
/* 801A8664 001A55C4  2C 00 00 18 */	cmpwi r0, 0x18
/* 801A8668 001A55C8  41 82 00 2C */	beq lbl_801A8694
/* 801A866C 001A55CC  48 00 00 30 */	b lbl_801A869C
lbl_801A8670:
/* 801A8670 001A55D0  7F E3 FB 78 */	mr r3, r31
/* 801A8674 001A55D4  80 8D F6 30 */	lwz r4, TEKI_OPTION_SHADOW_VISIBLE__5BTeki@sda21(r13)
/* 801A8678 001A55D8  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A867C 001A55DC  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 801A8680 001A55E0  7D 88 03 A6 */	mtlr r12
/* 801A8684 001A55E4  4E 80 00 21 */	blrl 
lbl_801A8688:
/* 801A8688 001A55E8  7F E3 FB 78 */	mr r3, r31
/* 801A868C 001A55EC  4B F9 D7 DD */	bl spawnItems__5BTekiFv
/* 801A8690 001A55F0  48 00 00 0C */	b lbl_801A869C
lbl_801A8694:
/* 801A8694 001A55F4  7F E3 FB 78 */	mr r3, r31
/* 801A8698 001A55F8  4B F9 D5 CD */	bl createDeadEffect__5BTekiFv
lbl_801A869C:
/* 801A869C 001A55FC  7F E3 FB 78 */	mr r3, r31
/* 801A86A0 001A5600  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A86A4 001A5604  81 8C 01 78 */	lwz r12, 0x178(r12)
/* 801A86A8 001A5608  7D 88 03 A6 */	mtlr r12
/* 801A86AC 001A560C  4E 80 00 21 */	blrl 
/* 801A86B0 001A5610  38 60 00 01 */	li r3, 1
/* 801A86B4 001A5614  48 00 00 08 */	b lbl_801A86BC
lbl_801A86B8:
/* 801A86B8 001A5618  38 60 00 00 */	li r3, 0
lbl_801A86BC:
/* 801A86BC 001A561C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801A86C0 001A5620  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801A86C4 001A5624  38 21 00 20 */	addi r1, r1, 0x20
/* 801A86C8 001A5628  7C 08 03 A6 */	mtlr r0
/* 801A86CC 001A562C  4E 80 00 20 */	blr 

.global start__16TAIAdyingKabekuiFR4Teki
start__16TAIAdyingKabekuiFR4Teki:
/* 801A86D0 001A5630  7C 08 02 A6 */	mflr r0
/* 801A86D4 001A5634  90 01 00 04 */	stw r0, 4(r1)
/* 801A86D8 001A5638  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A86DC 001A563C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A86E0 001A5640  7C 9F 23 78 */	mr r31, r4
/* 801A86E4 001A5644  4B FF FE 49 */	bl start__9TAIAdyingFR4Teki
/* 801A86E8 001A5648  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 801A86EC 001A564C  54 00 06 B0 */	rlwinm r0, r0, 0, 0x1a, 0x18
/* 801A86F0 001A5650  90 1F 00 C8 */	stw r0, 0xc8(r31)
/* 801A86F4 001A5654  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 801A86F8 001A5658  60 00 00 02 */	ori r0, r0, 2
/* 801A86FC 001A565C  90 1F 00 C8 */	stw r0, 0xc8(r31)
/* 801A8700 001A5660  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A8704 001A5664  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A8708 001A5668  38 21 00 18 */	addi r1, r1, 0x18
/* 801A870C 001A566C  7C 08 03 A6 */	mtlr r0
/* 801A8710 001A5670  4E 80 00 20 */	blr 

.global act__16TAIAdyingKabekuiFR4Teki
act__16TAIAdyingKabekuiFR4Teki:
/* 801A8714 001A5674  7C 08 02 A6 */	mflr r0
/* 801A8718 001A5678  90 01 00 04 */	stw r0, 4(r1)
/* 801A871C 001A567C  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 801A8720 001A5680  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 801A8724 001A5684  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 801A8728 001A5688  7C 9F 23 78 */	mr r31, r4
/* 801A872C 001A568C  93 C1 00 38 */	stw r30, 0x38(r1)
/* 801A8730 001A5690  7C 7E 1B 78 */	mr r30, r3
/* 801A8734 001A5694  C0 24 00 94 */	lfs f1, 0x94(r4)
/* 801A8738 001A5698  C0 44 00 9C */	lfs f2, 0x9c(r4)
/* 801A873C 001A569C  38 80 00 01 */	li r4, 1
/* 801A8740 001A56A0  C3 FF 00 98 */	lfs f31, 0x98(r31)
/* 801A8744 001A56A4  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 801A8748 001A56A8  4B EB F7 BD */	bl getMinY__6MapMgrFffb
/* 801A874C 001A56AC  EC 21 F8 28 */	fsubs f1, f1, f31
/* 801A8750 001A56B0  C0 02 B5 88 */	lfs f0, lbl_803EB788@sda21(r2)
/* 801A8754 001A56B4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A8758 001A56B8  40 80 00 08 */	bge lbl_801A8760
/* 801A875C 001A56BC  FC 20 08 50 */	fneg f1, f1
lbl_801A8760:
/* 801A8760 001A56C0  C0 02 B5 8C */	lfs f0, lbl_803EB78C@sda21(r2)
/* 801A8764 001A56C4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A8768 001A56C8  40 80 00 50 */	bge lbl_801A87B8
/* 801A876C 001A56CC  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 801A8770 001A56D0  7F E3 FB 78 */	mr r3, r31
/* 801A8774 001A56D4  C3 E4 02 8C */	lfs f31, 0x28c(r4)
/* 801A8778 001A56D8  4B FA 01 B1 */	bl getGravity__5BTekiFv
/* 801A877C 001A56DC  C0 42 B5 90 */	lfs f2, lbl_803EB790@sda21(r2)
/* 801A8780 001A56E0  C0 1F 00 74 */	lfs f0, 0x74(r31)
/* 801A8784 001A56E4  EC 22 00 72 */	fmuls f1, f2, f1
/* 801A8788 001A56E8  EC 21 07 F2 */	fmuls f1, f1, f31
/* 801A878C 001A56EC  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 801A8790 001A56F0  41 80 00 10 */	blt lbl_801A87A0
/* 801A8794 001A56F4  80 1F 03 A8 */	lwz r0, 0x3a8(r31)
/* 801A8798 001A56F8  2C 00 00 01 */	cmpwi r0, 1
/* 801A879C 001A56FC  40 82 00 1C */	bne lbl_801A87B8
lbl_801A87A0:
/* 801A87A0 001A5700  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801A87A4 001A5704  38 BF 00 94 */	addi r5, r31, 0x94
/* 801A87A8 001A5708  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 801A87AC 001A570C  38 C0 00 00 */	li r6, 0
/* 801A87B0 001A5710  38 E0 00 00 */	li r7, 0
/* 801A87B4 001A5714  4B FF 43 85 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
lbl_801A87B8:
/* 801A87B8 001A5718  80 7F 02 CC */	lwz r3, 0x2cc(r31)
/* 801A87BC 001A571C  80 03 00 38 */	lwz r0, 0x38(r3)
/* 801A87C0 001A5720  2C 00 00 00 */	cmpwi r0, 0
/* 801A87C4 001A5724  40 80 00 74 */	bge lbl_801A8838
/* 801A87C8 001A5728  80 1F 03 20 */	lwz r0, 0x320(r31)
/* 801A87CC 001A572C  2C 00 00 16 */	cmpwi r0, 0x16
/* 801A87D0 001A5730  41 82 00 38 */	beq lbl_801A8808
/* 801A87D4 001A5734  40 80 00 10 */	bge lbl_801A87E4
/* 801A87D8 001A5738  2C 00 00 10 */	cmpwi r0, 0x10
/* 801A87DC 001A573C  41 82 00 14 */	beq lbl_801A87F0
/* 801A87E0 001A5740  48 00 00 3C */	b lbl_801A881C
lbl_801A87E4:
/* 801A87E4 001A5744  2C 00 00 18 */	cmpwi r0, 0x18
/* 801A87E8 001A5748  41 82 00 2C */	beq lbl_801A8814
/* 801A87EC 001A574C  48 00 00 30 */	b lbl_801A881C
lbl_801A87F0:
/* 801A87F0 001A5750  7F E3 FB 78 */	mr r3, r31
/* 801A87F4 001A5754  80 8D F6 30 */	lwz r4, TEKI_OPTION_SHADOW_VISIBLE__5BTeki@sda21(r13)
/* 801A87F8 001A5758  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A87FC 001A575C  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 801A8800 001A5760  7D 88 03 A6 */	mtlr r12
/* 801A8804 001A5764  4E 80 00 21 */	blrl 
lbl_801A8808:
/* 801A8808 001A5768  7F E3 FB 78 */	mr r3, r31
/* 801A880C 001A576C  4B F9 D6 5D */	bl spawnItems__5BTekiFv
/* 801A8810 001A5770  48 00 00 0C */	b lbl_801A881C
lbl_801A8814:
/* 801A8814 001A5774  7F E3 FB 78 */	mr r3, r31
/* 801A8818 001A5778  4B F9 D4 4D */	bl createDeadEffect__5BTekiFv
lbl_801A881C:
/* 801A881C 001A577C  7F E3 FB 78 */	mr r3, r31
/* 801A8820 001A5780  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A8824 001A5784  81 8C 01 78 */	lwz r12, 0x178(r12)
/* 801A8828 001A5788  7D 88 03 A6 */	mtlr r12
/* 801A882C 001A578C  4E 80 00 21 */	blrl 
/* 801A8830 001A5790  38 60 00 01 */	li r3, 1
/* 801A8834 001A5794  48 00 00 08 */	b lbl_801A883C
lbl_801A8838:
/* 801A8838 001A5798  38 60 00 00 */	li r3, 0
lbl_801A883C:
/* 801A883C 001A579C  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 801A8840 001A57A0  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 801A8844 001A57A4  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 801A8848 001A57A8  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 801A884C 001A57AC  38 21 00 48 */	addi r1, r1, 0x48
/* 801A8850 001A57B0  7C 08 03 A6 */	mtlr r0
/* 801A8854 001A57B4  4E 80 00 20 */	blr 

.global start__21TAIAdyingCrushKabekuiFR4Teki
start__21TAIAdyingCrushKabekuiFR4Teki:
/* 801A8858 001A57B8  7C 08 02 A6 */	mflr r0
/* 801A885C 001A57BC  90 01 00 04 */	stw r0, 4(r1)
/* 801A8860 001A57C0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A8864 001A57C4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A8868 001A57C8  7C 9F 23 78 */	mr r31, r4
/* 801A886C 001A57CC  4B FF FC C1 */	bl start__9TAIAdyingFR4Teki
/* 801A8870 001A57D0  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 801A8874 001A57D4  54 00 06 B0 */	rlwinm r0, r0, 0, 0x1a, 0x18
/* 801A8878 001A57D8  90 1F 00 C8 */	stw r0, 0xc8(r31)
/* 801A887C 001A57DC  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 801A8880 001A57E0  60 00 00 02 */	ori r0, r0, 2
/* 801A8884 001A57E4  90 1F 00 C8 */	stw r0, 0xc8(r31)
/* 801A8888 001A57E8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A888C 001A57EC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A8890 001A57F0  38 21 00 18 */	addi r1, r1, 0x18
/* 801A8894 001A57F4  7C 08 03 A6 */	mtlr r0
/* 801A8898 001A57F8  4E 80 00 20 */	blr 

.global act__10TAIAdamageFR4Teki
act__10TAIAdamageFR4Teki:
/* 801A889C 001A57FC  7C 08 02 A6 */	mflr r0
/* 801A88A0 001A5800  90 01 00 04 */	stw r0, 4(r1)
/* 801A88A4 001A5804  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 801A88A8 001A5808  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 801A88AC 001A580C  7C 9F 23 78 */	mr r31, r4
/* 801A88B0 001A5810  93 C1 00 58 */	stw r30, 0x58(r1)
/* 801A88B4 001A5814  7C 7E 1B 78 */	mr r30, r3
/* 801A88B8 001A5818  C0 02 B5 88 */	lfs f0, lbl_803EB788@sda21(r2)
/* 801A88BC 001A581C  C0 24 03 3C */	lfs f1, 0x33c(r4)
/* 801A88C0 001A5820  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A88C4 001A5824  4C 40 13 82 */	cror 2, 0, 2
/* 801A88C8 001A5828  40 82 00 0C */	bne lbl_801A88D4
/* 801A88CC 001A582C  38 60 00 00 */	li r3, 0
/* 801A88D0 001A5830  48 00 00 94 */	b lbl_801A8964
lbl_801A88D4:
/* 801A88D4 001A5834  7F C3 F3 78 */	mr r3, r30
/* 801A88D8 001A5838  81 9E 00 04 */	lwz r12, 4(r30)
/* 801A88DC 001A583C  7F E4 FB 78 */	mr r4, r31
/* 801A88E0 001A5840  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 801A88E4 001A5844  7D 88 03 A6 */	mtlr r12
/* 801A88E8 001A5848  4E 80 00 21 */	blrl 
/* 801A88EC 001A584C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801A88F0 001A5850  41 82 00 70 */	beq lbl_801A8960
/* 801A88F4 001A5854  7F E3 FB 78 */	mr r3, r31
/* 801A88F8 001A5858  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A88FC 001A585C  81 8C 01 8C */	lwz r12, 0x18c(r12)
/* 801A8900 001A5860  7D 88 03 A6 */	mtlr r12
/* 801A8904 001A5864  4E 80 00 21 */	blrl 
/* 801A8908 001A5868  88 1E 00 08 */	lbz r0, 8(r30)
/* 801A890C 001A586C  28 00 00 00 */	cmplwi r0, 0
/* 801A8910 001A5870  41 82 00 50 */	beq lbl_801A8960
/* 801A8914 001A5874  80 9F 02 C4 */	lwz r4, 0x2c4(r31)
/* 801A8918 001A5878  7F E3 FB 78 */	mr r3, r31
/* 801A891C 001A587C  81 9F 00 00 */	lwz r12, 0(r31)
/* 801A8920 001A5880  80 84 00 84 */	lwz r4, 0x84(r4)
/* 801A8924 001A5884  81 8C 01 90 */	lwz r12, 0x190(r12)
/* 801A8928 001A5888  80 84 00 04 */	lwz r4, 4(r4)
/* 801A892C 001A588C  7D 88 03 A6 */	mtlr r12
/* 801A8930 001A5890  80 84 00 00 */	lwz r4, 0(r4)
/* 801A8934 001A5894  C0 44 00 7C */	lfs f2, 0x7c(r4)
/* 801A8938 001A5898  C0 24 00 78 */	lfs f1, 0x78(r4)
/* 801A893C 001A589C  4E 80 00 21 */	blrl 
/* 801A8940 001A58A0  80 1F 03 20 */	lwz r0, 0x320(r31)
/* 801A8944 001A58A4  2C 00 00 0F */	cmpwi r0, 0xf
/* 801A8948 001A58A8  41 82 00 08 */	beq lbl_801A8950
/* 801A894C 001A58AC  48 00 00 14 */	b lbl_801A8960
lbl_801A8950:
/* 801A8950 001A58B0  38 7F 00 00 */	addi r3, r31, 0
/* 801A8954 001A58B4  38 9F 00 00 */	addi r4, r31, 0
/* 801A8958 001A58B8  38 A0 00 40 */	li r5, 0x40
/* 801A895C 001A58BC  4B EE 1C 59 */	bl playEventSound__8CreatureFP8Creaturei
lbl_801A8960:
/* 801A8960 001A58C0  38 60 00 01 */	li r3, 1
lbl_801A8964:
/* 801A8964 001A58C4  80 01 00 64 */	lwz r0, 0x64(r1)
/* 801A8968 001A58C8  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 801A896C 001A58CC  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 801A8970 001A58D0  38 21 00 60 */	addi r1, r1, 0x60
/* 801A8974 001A58D4  7C 08 03 A6 */	mtlr r0
/* 801A8978 001A58D8  4E 80 00 20 */	blr 

.global judgeDamage__10TAIAdamageFR4Teki
judgeDamage__10TAIAdamageFR4Teki:
/* 801A897C 001A58DC  38 60 00 01 */	li r3, 1
/* 801A8980 001A58E0  4E 80 00 20 */	blr 

.global act__11TAIAinWaterFR4Teki
act__11TAIAinWaterFR4Teki:
/* 801A8984 001A58E4  7C 08 02 A6 */	mflr r0
/* 801A8988 001A58E8  90 01 00 04 */	stw r0, 4(r1)
/* 801A898C 001A58EC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A8990 001A58F0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A8994 001A58F4  3B E0 00 00 */	li r31, 0
/* 801A8998 001A58F8  80 64 02 8C */	lwz r3, 0x28c(r4)
/* 801A899C 001A58FC  28 03 00 00 */	cmplwi r3, 0
/* 801A89A0 001A5900  41 82 00 14 */	beq lbl_801A89B4
/* 801A89A4 001A5904  4B F6 D6 DD */	bl getAttribute__7MapCodeFP11CollTriInfo
/* 801A89A8 001A5908  2C 03 00 05 */	cmpwi r3, 5
/* 801A89AC 001A590C  40 82 00 08 */	bne lbl_801A89B4
/* 801A89B0 001A5910  3B E0 00 01 */	li r31, 1
lbl_801A89B4:
/* 801A89B4 001A5914  7F E3 FB 78 */	mr r3, r31
/* 801A89B8 001A5918  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A89BC 001A591C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A89C0 001A5920  38 21 00 18 */	addi r1, r1, 0x18
/* 801A89C4 001A5924  7C 08 03 A6 */	mtlr r0
/* 801A89C8 001A5928  4E 80 00 20 */	blr 

.global actByEvent__11TAIAinWaterFR9TekiEvent
actByEvent__11TAIAinWaterFR9TekiEvent:
/* 801A89CC 001A592C  7C 08 02 A6 */	mflr r0
/* 801A89D0 001A5930  90 01 00 04 */	stw r0, 4(r1)
/* 801A89D4 001A5934  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A89D8 001A5938  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A89DC 001A593C  3B E0 00 00 */	li r31, 0
/* 801A89E0 001A5940  80 04 00 00 */	lwz r0, 0(r4)
/* 801A89E4 001A5944  2C 00 00 00 */	cmpwi r0, 0
/* 801A89E8 001A5948  40 82 00 34 */	bne lbl_801A8A1C
/* 801A89EC 001A594C  80 A4 00 04 */	lwz r5, 4(r4)
/* 801A89F0 001A5950  38 80 00 01 */	li r4, 1
/* 801A89F4 001A5954  C4 25 00 94 */	lfsu f1, 0x94(r5)
/* 801A89F8 001A5958  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 801A89FC 001A595C  C0 45 00 08 */	lfs f2, 8(r5)
/* 801A8A00 001A5960  4B EB F7 D9 */	bl getCurrTri__6MapMgrFffb
/* 801A8A04 001A5964  28 03 00 00 */	cmplwi r3, 0
/* 801A8A08 001A5968  41 82 00 14 */	beq lbl_801A8A1C
/* 801A8A0C 001A596C  4B F6 D6 75 */	bl getAttribute__7MapCodeFP11CollTriInfo
/* 801A8A10 001A5970  2C 03 00 05 */	cmpwi r3, 5
/* 801A8A14 001A5974  40 82 00 08 */	bne lbl_801A8A1C
/* 801A8A18 001A5978  3B E0 00 01 */	li r31, 1
lbl_801A8A1C:
/* 801A8A1C 001A597C  7F E3 FB 78 */	mr r3, r31
/* 801A8A20 001A5980  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A8A24 001A5984  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A8A28 001A5988  38 21 00 18 */	addi r1, r1, 0x18
/* 801A8A2C 001A598C  7C 08 03 A6 */	mtlr r0
/* 801A8A30 001A5990  4E 80 00 20 */	blr 

.global act__17TAIAinWaterDamageFR4Teki
act__17TAIAinWaterDamageFR4Teki:
/* 801A8A34 001A5994  7C 08 02 A6 */	mflr r0
/* 801A8A38 001A5998  90 01 00 04 */	stw r0, 4(r1)
/* 801A8A3C 001A599C  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 801A8A40 001A59A0  93 E1 00 34 */	stw r31, 0x34(r1)
/* 801A8A44 001A59A4  93 C1 00 30 */	stw r30, 0x30(r1)
/* 801A8A48 001A59A8  3B C0 00 00 */	li r30, 0
/* 801A8A4C 001A59AC  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 801A8A50 001A59B0  7C 9D 23 78 */	mr r29, r4
/* 801A8A54 001A59B4  93 81 00 28 */	stw r28, 0x28(r1)
/* 801A8A58 001A59B8  3B 83 00 00 */	addi r28, r3, 0
/* 801A8A5C 001A59BC  80 04 02 8C */	lwz r0, 0x28c(r4)
/* 801A8A60 001A59C0  28 00 00 00 */	cmplwi r0, 0
/* 801A8A64 001A59C4  41 82 00 18 */	beq lbl_801A8A7C
/* 801A8A68 001A59C8  7C 03 03 78 */	mr r3, r0
/* 801A8A6C 001A59CC  4B F6 D6 15 */	bl getAttribute__7MapCodeFP11CollTriInfo
/* 801A8A70 001A59D0  2C 03 00 05 */	cmpwi r3, 5
/* 801A8A74 001A59D4  40 82 00 08 */	bne lbl_801A8A7C
/* 801A8A78 001A59D8  3B C0 00 01 */	li r30, 1
lbl_801A8A7C:
/* 801A8A7C 001A59DC  57 C0 06 3F */	clrlwi. r0, r30, 0x18
/* 801A8A80 001A59E0  41 82 00 20 */	beq lbl_801A8AA0
/* 801A8A84 001A59E4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801A8A88 001A59E8  C0 3C 00 08 */	lfs f1, 8(r28)
/* 801A8A8C 001A59EC  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801A8A90 001A59F0  C0 5D 00 58 */	lfs f2, 0x58(r29)
/* 801A8A94 001A59F4  EC 01 00 32 */	fmuls f0, f1, f0
/* 801A8A98 001A59F8  EC 02 00 28 */	fsubs f0, f2, f0
/* 801A8A9C 001A59FC  D0 1D 00 58 */	stfs f0, 0x58(r29)
lbl_801A8AA0:
/* 801A8AA0 001A5A00  88 1C 00 0C */	lbz r0, 0xc(r28)
/* 801A8AA4 001A5A04  28 00 00 00 */	cmplwi r0, 0
/* 801A8AA8 001A5A08  41 82 00 68 */	beq lbl_801A8B10
/* 801A8AAC 001A5A0C  80 7D 02 8C */	lwz r3, 0x28c(r29)
/* 801A8AB0 001A5A10  28 03 00 00 */	cmplwi r3, 0
/* 801A8AB4 001A5A14  41 82 00 54 */	beq lbl_801A8B08
/* 801A8AB8 001A5A18  4B F6 D5 C9 */	bl getAttribute__7MapCodeFP11CollTriInfo
/* 801A8ABC 001A5A1C  3B E3 00 00 */	addi r31, r3, 0
/* 801A8AC0 001A5A20  2C 1F 00 05 */	cmpwi r31, 5
/* 801A8AC4 001A5A24  41 82 00 08 */	beq lbl_801A8ACC
/* 801A8AC8 001A5A28  48 00 00 20 */	b lbl_801A8AE8
lbl_801A8ACC:
/* 801A8ACC 001A5A2C  80 1D 04 74 */	lwz r0, 0x474(r29)
/* 801A8AD0 001A5A30  2C 00 00 05 */	cmpwi r0, 5
/* 801A8AD4 001A5A34  41 82 00 2C */	beq lbl_801A8B00
/* 801A8AD8 001A5A38  38 7C 00 00 */	addi r3, r28, 0
/* 801A8ADC 001A5A3C  38 9D 00 00 */	addi r4, r29, 0
/* 801A8AE0 001A5A40  48 00 00 FD */	bl createEffect__17TAIAinWaterDamageFR4Teki
/* 801A8AE4 001A5A44  48 00 00 1C */	b lbl_801A8B00
lbl_801A8AE8:
/* 801A8AE8 001A5A48  80 1D 04 74 */	lwz r0, 0x474(r29)
/* 801A8AEC 001A5A4C  2C 00 00 05 */	cmpwi r0, 5
/* 801A8AF0 001A5A50  40 82 00 10 */	bne lbl_801A8B00
/* 801A8AF4 001A5A54  38 7C 00 00 */	addi r3, r28, 0
/* 801A8AF8 001A5A58  38 9D 00 00 */	addi r4, r29, 0
/* 801A8AFC 001A5A5C  48 00 00 E1 */	bl createEffect__17TAIAinWaterDamageFR4Teki
lbl_801A8B00:
/* 801A8B00 001A5A60  93 FD 04 74 */	stw r31, 0x474(r29)
/* 801A8B04 001A5A64  48 00 00 0C */	b lbl_801A8B10
lbl_801A8B08:
/* 801A8B08 001A5A68  38 00 FF FF */	li r0, -1
/* 801A8B0C 001A5A6C  90 1D 04 74 */	stw r0, 0x474(r29)
lbl_801A8B10:
/* 801A8B10 001A5A70  7F C3 F3 78 */	mr r3, r30
/* 801A8B14 001A5A74  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 801A8B18 001A5A78  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 801A8B1C 001A5A7C  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 801A8B20 001A5A80  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 801A8B24 001A5A84  83 81 00 28 */	lwz r28, 0x28(r1)
/* 801A8B28 001A5A88  38 21 00 38 */	addi r1, r1, 0x38
/* 801A8B2C 001A5A8C  7C 08 03 A6 */	mtlr r0
/* 801A8B30 001A5A90  4E 80 00 20 */	blr 

.global actByEvent__17TAIAinWaterDamageFR9TekiEvent
actByEvent__17TAIAinWaterDamageFR9TekiEvent:
/* 801A8B34 001A5A94  7C 08 02 A6 */	mflr r0
/* 801A8B38 001A5A98  90 01 00 04 */	stw r0, 4(r1)
/* 801A8B3C 001A5A9C  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 801A8B40 001A5AA0  93 E1 00 44 */	stw r31, 0x44(r1)
/* 801A8B44 001A5AA4  3B E0 00 00 */	li r31, 0
/* 801A8B48 001A5AA8  93 C1 00 40 */	stw r30, 0x40(r1)
/* 801A8B4C 001A5AAC  7C 9E 23 78 */	mr r30, r4
/* 801A8B50 001A5AB0  93 A1 00 3C */	stw r29, 0x3c(r1)
/* 801A8B54 001A5AB4  3B A3 00 00 */	addi r29, r3, 0
/* 801A8B58 001A5AB8  80 04 00 00 */	lwz r0, 0(r4)
/* 801A8B5C 001A5ABC  2C 00 00 00 */	cmpwi r0, 0
/* 801A8B60 001A5AC0  40 82 00 34 */	bne lbl_801A8B94
/* 801A8B64 001A5AC4  80 BE 00 04 */	lwz r5, 4(r30)
/* 801A8B68 001A5AC8  38 80 00 01 */	li r4, 1
/* 801A8B6C 001A5ACC  C4 25 00 94 */	lfsu f1, 0x94(r5)
/* 801A8B70 001A5AD0  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 801A8B74 001A5AD4  C0 45 00 08 */	lfs f2, 8(r5)
/* 801A8B78 001A5AD8  4B EB F6 61 */	bl getCurrTri__6MapMgrFffb
/* 801A8B7C 001A5ADC  28 03 00 00 */	cmplwi r3, 0
/* 801A8B80 001A5AE0  41 82 00 14 */	beq lbl_801A8B94
/* 801A8B84 001A5AE4  4B F6 D4 FD */	bl getAttribute__7MapCodeFP11CollTriInfo
/* 801A8B88 001A5AE8  2C 03 00 05 */	cmpwi r3, 5
/* 801A8B8C 001A5AEC  40 82 00 08 */	bne lbl_801A8B94
/* 801A8B90 001A5AF0  3B E0 00 01 */	li r31, 1
lbl_801A8B94:
/* 801A8B94 001A5AF4  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 801A8B98 001A5AF8  41 82 00 24 */	beq lbl_801A8BBC
/* 801A8B9C 001A5AFC  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801A8BA0 001A5B00  80 9E 00 04 */	lwz r4, 4(r30)
/* 801A8BA4 001A5B04  C0 3D 00 08 */	lfs f1, 8(r29)
/* 801A8BA8 001A5B08  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801A8BAC 001A5B0C  C0 44 00 58 */	lfs f2, 0x58(r4)
/* 801A8BB0 001A5B10  EC 01 00 32 */	fmuls f0, f1, f0
/* 801A8BB4 001A5B14  EC 02 00 28 */	fsubs f0, f2, f0
/* 801A8BB8 001A5B18  D0 04 00 58 */	stfs f0, 0x58(r4)
lbl_801A8BBC:
/* 801A8BBC 001A5B1C  7F E3 FB 78 */	mr r3, r31
/* 801A8BC0 001A5B20  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 801A8BC4 001A5B24  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 801A8BC8 001A5B28  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 801A8BCC 001A5B2C  83 A1 00 3C */	lwz r29, 0x3c(r1)
/* 801A8BD0 001A5B30  38 21 00 48 */	addi r1, r1, 0x48
/* 801A8BD4 001A5B34  7C 08 03 A6 */	mtlr r0
/* 801A8BD8 001A5B38  4E 80 00 20 */	blr 

.global createEffect__17TAIAinWaterDamageFR4Teki
createEffect__17TAIAinWaterDamageFR4Teki:
/* 801A8BDC 001A5B3C  7C 08 02 A6 */	mflr r0
/* 801A8BE0 001A5B40  38 C0 00 00 */	li r6, 0
/* 801A8BE4 001A5B44  90 01 00 04 */	stw r0, 4(r1)
/* 801A8BE8 001A5B48  38 E0 00 00 */	li r7, 0
/* 801A8BEC 001A5B4C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A8BF0 001A5B50  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A8BF4 001A5B54  7C 9F 23 78 */	mr r31, r4
/* 801A8BF8 001A5B58  38 BF 00 94 */	addi r5, r31, 0x94
/* 801A8BFC 001A5B5C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801A8C00 001A5B60  38 80 00 0F */	li r4, 0xf
/* 801A8C04 001A5B64  4B FF 3F 35 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801A8C08 001A5B68  38 7F 00 00 */	addi r3, r31, 0
/* 801A8C0C 001A5B6C  38 9F 00 00 */	addi r4, r31, 0
/* 801A8C10 001A5B70  38 A0 00 A7 */	li r5, 0xa7
/* 801A8C14 001A5B74  4B EE 19 A1 */	bl playEventSound__8CreatureFP8Creaturei
/* 801A8C18 001A5B78  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A8C1C 001A5B7C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A8C20 001A5B80  38 21 00 18 */	addi r1, r1, 0x18
/* 801A8C24 001A5B84  7C 08 03 A6 */	mtlr r0
/* 801A8C28 001A5B88  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802DF130:
	.asciz "TAIAreaction.cpp"
.balign 4
lbl_802DF144:
	.asciz "TAIAreaction"
.balign 4
lbl_802DF154:
	.asciz "TAIAinWaterDamage"
.balign 4
lbl_802DF168:
	.asciz "TaiAction"
.balign 4
lbl_802DF174:
	.asciz "TAIAinWater"
.balign 4
lbl_802DF180:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
lbl_802DF18C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__11TAIAinWater
	.4byte 0
	.4byte 0
.global __vt__17TAIAinWaterDamage
__vt__17TAIAinWaterDamage:
	.4byte __RTTI__17TAIAinWaterDamage
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__17TAIAinWaterDamageFR4Teki
	.4byte actByEvent__17TAIAinWaterDamageFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.global __vt__11TAIAinWater
__vt__11TAIAinWater:
	.4byte __RTTI__11TAIAinWater
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__11TAIAinWaterFR4Teki
	.4byte actByEvent__11TAIAinWaterFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
lbl_802DF1D8:
	.asciz "TAIAdamage"
.balign 4
lbl_802DF1E4:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__10TAIAdamage
__vt__10TAIAdamage:
	.4byte __RTTI__10TAIAdamage
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__10TAIAdamageFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
	.4byte judgeDamage__10TAIAdamageFR4Teki
lbl_802DF210:
	.asciz "TAIAdyingCrushKabekui"
.balign 4
lbl_802DF228:
	.asciz "TAIAmotion"
.balign 4
lbl_802DF234:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
lbl_802DF240:
	.asciz "TAIAdying"
.balign 4
lbl_802DF24C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__10TAIAmotion
	.4byte 0
	.4byte 0
lbl_802DF260:
	.asciz "TAIAdyingKabekui"
.balign 4
lbl_802DF274:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__10TAIAmotion
	.4byte 0
	.4byte __RTTI__9TAIAdying
	.4byte 0
	.4byte 0
lbl_802DF290:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__10TAIAmotion
	.4byte 0
	.4byte __RTTI__9TAIAdying
	.4byte 0
	.4byte __RTTI__16TAIAdyingKabekui
	.4byte 0
	.4byte 0
.global __vt__21TAIAdyingCrushKabekui
__vt__21TAIAdyingCrushKabekui:
	.4byte __RTTI__21TAIAdyingCrushKabekui
	.4byte 0
	.4byte start__21TAIAdyingCrushKabekuiFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__16TAIAdyingKabekuiFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.global __vt__16TAIAdyingKabekui
__vt__16TAIAdyingKabekui:
	.4byte __RTTI__16TAIAdyingKabekui
	.4byte 0
	.4byte start__16TAIAdyingKabekuiFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__16TAIAdyingKabekuiFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.global __vt__9TAIAdying
__vt__9TAIAdying:
	.4byte __RTTI__9TAIAdying
	.4byte 0
	.4byte start__9TAIAdyingFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TAIAdyingFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
lbl_802DF308:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__7TAIAdie
__vt__7TAIAdie:
	.4byte __RTTI__7TAIAdie
	.4byte 0
	.4byte start__7TAIAdieFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
lbl_802DF330:
	.asciz "TAIAdeadCheck"
.balign 4
lbl_802DF340:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__13TAIAdeadCheck
__vt__13TAIAdeadCheck:
	.4byte __RTTI__13TAIAdeadCheck
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__13TAIAdeadCheckFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
lbl_802DF368:
	.asciz "TAIAhitCheckFlyingPiki"
.balign 4
lbl_802DF380:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__22TAIAhitCheckFlyingPiki
__vt__22TAIAhitCheckFlyingPiki:
	.4byte __RTTI__22TAIAhitCheckFlyingPiki
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__22TAIAhitCheckFlyingPikiFR9TekiEvent
	.4byte hasNextState__9TaiActionFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__9TaiAction:
	.4byte lbl_802DF168
	.4byte 0
__RTTI__11TAIAinWater:
	.4byte lbl_802DF174
	.4byte lbl_802DF180
__RTTI__17TAIAinWaterDamage:
	.4byte lbl_802DF154
	.4byte lbl_802DF18C
__RTTI__10TAIAdamage:
	.4byte lbl_802DF1D8
	.4byte lbl_802DF1E4
__RTTI__10TAIAmotion:
	.4byte lbl_802DF228
	.4byte lbl_802DF234
__RTTI__9TAIAdying:
	.4byte lbl_802DF240
	.4byte lbl_802DF24C
__RTTI__16TAIAdyingKabekui:
	.4byte lbl_802DF260
	.4byte lbl_802DF274
__RTTI__21TAIAdyingCrushKabekui:
	.4byte lbl_802DF210
	.4byte lbl_802DF290
lbl_803E6260:
	.asciz "TAIAdie"
.balign 4
__RTTI__7TAIAdie:
	.4byte lbl_803E6260
	.4byte lbl_802DF308
__RTTI__13TAIAdeadCheck:
	.4byte lbl_802DF330
	.4byte lbl_802DF340
__RTTI__22TAIAhitCheckFlyingPiki:
	.4byte lbl_802DF368
	.4byte lbl_802DF380

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EB788:
	.4byte 0x00000000
lbl_803EB78C:
	.4byte 0x3F800000
lbl_803EB790:
	.4byte 0xC0000000
