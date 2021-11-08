.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800F745C 000F43BC  4B FA 15 E5 */	bl "__ct__7Parm<f>FP10Parametersfff5ayuIDPc"
/* 800F7460 000F43C0  38 61 00 38 */	addi r3, r1, 0x38
/* 800F7464 000F43C4  38 8D CF E8 */	addi r4, r13, lbl_803E1D08@sda21
/* 800F7468 000F43C8  4B F5 96 71 */	bl Set__5ayuIDFPc
/* 800F746C 000F43CC  80 01 00 38 */	lwz r0, 0x38(r1)
/* 800F7470 000F43D0  38 A1 00 34 */	addi r5, r1, 0x34
/* 800F7474 000F43D4  C0 22 9C 1C */	lfs f1, lbl_803E9E1C@sda21(r2)
/* 800F7478 000F43D8  7F C4 F3 78 */	mr r4, r30
/* 800F747C 000F43DC  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F7480 000F43E0  C0 42 9C 0C */	lfs f2, lbl_803E9E0C@sda21(r2)
/* 800F7484 000F43E4  38 7E 00 24 */	addi r3, r30, 0x24
/* 800F7488 000F43E8  C0 62 9C 18 */	lfs f3, lbl_803E9E18@sda21(r2)
/* 800F748C 000F43EC  38 C0 00 00 */	li r6, 0
/* 800F7490 000F43F0  4B FA 15 B1 */	bl "__ct__7Parm<f>FP10Parametersfff5ayuIDPc"
/* 800F7494 000F43F4  38 61 00 40 */	addi r3, r1, 0x40
/* 800F7498 000F43F8  38 8D CF EC */	addi r4, r13, lbl_803E1D0C@sda21
/* 800F749C 000F43FC  4B F5 96 3D */	bl Set__5ayuIDFPc
/* 800F74A0 000F4400  80 01 00 40 */	lwz r0, 0x40(r1)
/* 800F74A4 000F4404  38 A1 00 3C */	addi r5, r1, 0x3c
/* 800F74A8 000F4408  C0 22 9C 20 */	lfs f1, lbl_803E9E20@sda21(r2)
/* 800F74AC 000F440C  7F C4 F3 78 */	mr r4, r30
/* 800F74B0 000F4410  90 01 00 3C */	stw r0, 0x3c(r1)
/* 800F74B4 000F4414  C0 42 9C 24 */	lfs f2, lbl_803E9E24@sda21(r2)
/* 800F74B8 000F4418  38 7E 00 34 */	addi r3, r30, 0x34
/* 800F74BC 000F441C  C0 62 9C 28 */	lfs f3, lbl_803E9E28@sda21(r2)
/* 800F74C0 000F4420  38 C0 00 00 */	li r6, 0
/* 800F74C4 000F4424  4B FA 15 7D */	bl "__ct__7Parm<f>FP10Parametersfff5ayuIDPc"
/* 800F74C8 000F4428  38 61 00 48 */	addi r3, r1, 0x48
/* 800F74CC 000F442C  38 8D CF F0 */	addi r4, r13, lbl_803E1D10@sda21
/* 800F74D0 000F4430  4B F5 96 09 */	bl Set__5ayuIDFPc
/* 800F74D4 000F4434  80 01 00 48 */	lwz r0, 0x48(r1)
/* 800F74D8 000F4438  38 A1 00 44 */	addi r5, r1, 0x44
/* 800F74DC 000F443C  C0 22 9C 2C */	lfs f1, lbl_803E9E2C@sda21(r2)
/* 800F74E0 000F4440  7F C4 F3 78 */	mr r4, r30
/* 800F74E4 000F4444  90 01 00 44 */	stw r0, 0x44(r1)
/* 800F74E8 000F4448  C0 42 9C 24 */	lfs f2, lbl_803E9E24@sda21(r2)
/* 800F74EC 000F444C  38 7E 00 44 */	addi r3, r30, 0x44
/* 800F74F0 000F4450  C0 62 9C 28 */	lfs f3, lbl_803E9E28@sda21(r2)
/* 800F74F4 000F4454  38 C0 00 00 */	li r6, 0
/* 800F74F8 000F4458  4B FA 15 49 */	bl "__ct__7Parm<f>FP10Parametersfff5ayuIDPc"
/* 800F74FC 000F445C  3C 60 80 2C */	lis r3, __vt__16PikiHeadItemProp@ha
/* 800F7500 000F4460  38 03 E9 5C */	addi r0, r3, __vt__16PikiHeadItemProp@l
/* 800F7504 000F4464  90 1F 00 54 */	stw r0, 0x54(r31)
/* 800F7508 000F4468  C0 02 9C 20 */	lfs f0, lbl_803E9E20@sda21(r2)
/* 800F750C 000F446C  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 800F7510 000F4470  C0 02 9C 30 */	lfs f0, lbl_803E9E30@sda21(r2)
/* 800F7514 000F4474  D0 1F 00 50 */	stfs f0, 0x50(r31)
lbl_800F7518:
/* 800F7518 000F4478  80 81 00 08 */	lwz r4, 8(r1)
/* 800F751C 000F447C  38 60 00 1C */	li r3, 0x1c
/* 800F7520 000F4480  93 E4 00 40 */	stw r31, 0x40(r4)
/* 800F7524 000F4484  4B F4 FA E1 */	bl alloc__6SystemFUl
/* 800F7528 000F4488  3B C3 00 00 */	addi r30, r3, 0
/* 800F752C 000F448C  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7530 000F4490  41 82 00 08 */	beq lbl_800F7538
/* 800F7534 000F4494  4B FF 7D 2D */	bl __ct__10PikiHeadAIFv
lbl_800F7538:
/* 800F7538 000F4498  83 E1 00 08 */	lwz r31, 8(r1)
/* 800F753C 000F449C  38 80 00 64 */	li r4, 0x64
/* 800F7540 000F44A0  93 DF 00 44 */	stw r30, 0x44(r31)
/* 800F7544 000F44A4  7F E3 FB 78 */	mr r3, r31
/* 800F7548 000F44A8  4B FE 9B A9 */	bl create__13MonoObjectMgrFi
/* 800F754C 000F44AC  7F E3 FB 78 */	mr r3, r31
/* 800F7550 000F44B0  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 800F7554 000F44B4  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 800F7558 000F44B8  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 800F755C 000F44BC  38 21 00 58 */	addi r1, r1, 0x58
/* 800F7560 000F44C0  7C 08 03 A6 */	mtlr r0
/* 800F7564 000F44C4  4E 80 00 20 */	blr 

.global birth__11PikiHeadMgrFv
birth__11PikiHeadMgrFv:
/* 800F7568 000F44C8  7C 08 02 A6 */	mflr r0
/* 800F756C 000F44CC  3C 80 80 3D */	lis r4, mapPikis__8GameStat@ha
/* 800F7570 000F44D0  90 01 00 04 */	stw r0, 4(r1)
/* 800F7574 000F44D4  38 84 1E C4 */	addi r4, r4, mapPikis__8GameStat@l
/* 800F7578 000F44D8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F757C 000F44DC  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800F7580 000F44E0  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800F7584 000F44E4  7C 7E 1B 78 */	mr r30, r3
/* 800F7588 000F44E8  80 A4 00 08 */	lwz r5, 8(r4)
/* 800F758C 000F44EC  80 04 00 04 */	lwz r0, 4(r4)
/* 800F7590 000F44F0  80 84 00 00 */	lwz r4, 0(r4)
/* 800F7594 000F44F4  7F E0 2A 14 */	add r31, r0, r5
/* 800F7598 000F44F8  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 800F759C 000F44FC  7F E4 FA 14 */	add r31, r4, r31
/* 800F75A0 000F4500  48 00 00 C9 */	bl getContainerExitCount__7ItemMgrFv
/* 800F75A4 000F4504  88 0D 30 A8 */	lbz r0, buryMode__11PikiHeadMgr@sda21(r13)
/* 800F75A8 000F4508  7F FF 1A 14 */	add r31, r31, r3
/* 800F75AC 000F450C  28 00 00 00 */	cmplwi r0, 0
/* 800F75B0 000F4510  41 82 00 20 */	beq lbl_800F75D0
/* 800F75B4 000F4514  80 6D 2F 80 */	lwz r3, _instance__10AIConstant@sda21(r13)
/* 800F75B8 000F4518  80 63 01 20 */	lwz r3, 0x120(r3)
/* 800F75BC 000F451C  38 03 00 01 */	addi r0, r3, 1
/* 800F75C0 000F4520  7C 1F 00 00 */	cmpw r31, r0
/* 800F75C4 000F4524  41 80 00 24 */	blt lbl_800F75E8
/* 800F75C8 000F4528  38 60 00 00 */	li r3, 0
/* 800F75CC 000F452C  48 00 00 24 */	b lbl_800F75F0
lbl_800F75D0:
/* 800F75D0 000F4530  80 6D 2F 80 */	lwz r3, _instance__10AIConstant@sda21(r13)
/* 800F75D4 000F4534  80 03 01 20 */	lwz r0, 0x120(r3)
/* 800F75D8 000F4538  7C 1F 00 00 */	cmpw r31, r0
/* 800F75DC 000F453C  41 80 00 0C */	blt lbl_800F75E8
/* 800F75E0 000F4540  38 60 00 00 */	li r3, 0
/* 800F75E4 000F4544  48 00 00 0C */	b lbl_800F75F0
lbl_800F75E8:
/* 800F75E8 000F4548  7F C3 F3 78 */	mr r3, r30
/* 800F75EC 000F454C  4B FE 9E 89 */	bl birth__13MonoObjectMgrFv
lbl_800F75F0:
/* 800F75F0 000F4550  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F75F4 000F4554  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800F75F8 000F4558  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800F75FC 000F455C  38 21 00 30 */	addi r1, r1, 0x30
/* 800F7600 000F4560  7C 08 03 A6 */	mtlr r0
/* 800F7604 000F4564  4E 80 00 20 */	blr 

.global createObject__11PikiHeadMgrFv
createObject__11PikiHeadMgrFv:
/* 800F7608 000F4568  7C 08 02 A6 */	mflr r0
/* 800F760C 000F456C  90 01 00 04 */	stw r0, 4(r1)
/* 800F7610 000F4570  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F7614 000F4574  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F7618 000F4578  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800F761C 000F457C  3B C3 00 00 */	addi r30, r3, 0
/* 800F7620 000F4580  38 60 03 F8 */	li r3, 0x3f8
/* 800F7624 000F4584  4B F4 F9 E1 */	bl alloc__6SystemFUl
/* 800F7628 000F4588  3B E3 00 00 */	addi r31, r3, 0
/* 800F762C 000F458C  7F E3 FB 79 */	or. r3, r31, r31
/* 800F7630 000F4590  41 82 00 1C */	beq lbl_800F764C
/* 800F7634 000F4594  80 BE 00 3C */	lwz r5, 0x3c(r30)
/* 800F7638 000F4598  80 9E 00 40 */	lwz r4, 0x40(r30)
/* 800F763C 000F459C  80 A5 00 88 */	lwz r5, 0x88(r5)
/* 800F7640 000F45A0  80 DE 00 44 */	lwz r6, 0x44(r30)
/* 800F7644 000F45A4  80 A5 00 0C */	lwz r5, 0xc(r5)
/* 800F7648 000F45A8  4B FF 50 55 */	bl __ct__12PikiHeadItemFP12CreaturePropP15ItemShapeObjectP8SimpleAI
lbl_800F764C:
/* 800F764C 000F45AC  7F E3 FB 78 */	mr r3, r31
/* 800F7650 000F45B0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F7654 000F45B4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F7658 000F45B8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800F765C 000F45BC  38 21 00 18 */	addi r1, r1, 0x18
/* 800F7660 000F45C0  7C 08 03 A6 */	mtlr r0
/* 800F7664 000F45C4  4E 80 00 20 */	blr 

.global getContainerExitCount__7ItemMgrFv
getContainerExitCount__7ItemMgrFv:
/* 800F7668 000F45C8  7C 08 02 A6 */	mflr r0
/* 800F766C 000F45CC  90 01 00 04 */	stw r0, 4(r1)
/* 800F7670 000F45D0  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800F7674 000F45D4  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800F7678 000F45D8  3B E0 00 00 */	li r31, 0
/* 800F767C 000F45DC  93 C1 00 30 */	stw r30, 0x30(r1)
/* 800F7680 000F45E0  3B C0 00 00 */	li r30, 0
/* 800F7684 000F45E4  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 800F7688 000F45E8  3B A3 00 00 */	addi r29, r3, 0
lbl_800F768C:
/* 800F768C 000F45EC  80 1D 00 68 */	lwz r0, 0x68(r29)
/* 800F7690 000F45F0  28 00 00 00 */	cmplwi r0, 0
/* 800F7694 000F45F4  40 82 00 0C */	bne lbl_800F76A0
/* 800F7698 000F45F8  38 60 00 00 */	li r3, 0
/* 800F769C 000F45FC  48 00 00 DC */	b lbl_800F7778
lbl_800F76A0:
/* 800F76A0 000F4600  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F76A4 000F4604  38 00 00 00 */	li r0, 0
/* 800F76A8 000F4608  38 61 00 10 */	addi r3, r1, 0x10
/* 800F76AC 000F460C  90 01 00 18 */	stw r0, 0x18(r1)
/* 800F76B0 000F4610  4B F9 87 0D */	bl first__8IteratorFv
/* 800F76B4 000F4614  48 00 00 64 */	b lbl_800F7718
lbl_800F76B8:
/* 800F76B8 000F4618  80 81 00 10 */	lwz r4, 0x10(r1)
/* 800F76BC 000F461C  2C 04 FF FF */	cmpwi r4, -1
/* 800F76C0 000F4620  40 82 00 20 */	bne lbl_800F76E0
/* 800F76C4 000F4624  80 61 00 14 */	lwz r3, 0x14(r1)
/* 800F76C8 000F4628  38 80 00 00 */	li r4, 0
/* 800F76CC 000F462C  81 83 00 00 */	lwz r12, 0(r3)
/* 800F76D0 000F4630  81 8C 00 08 */	lwz r12, 8(r12)
/* 800F76D4 000F4634  7D 88 03 A6 */	mtlr r12
/* 800F76D8 000F4638  4E 80 00 21 */	blrl 
/* 800F76DC 000F463C  48 00 00 18 */	b lbl_800F76F4
lbl_800F76E0:
/* 800F76E0 000F4640  80 61 00 14 */	lwz r3, 0x14(r1)
/* 800F76E4 000F4644  81 83 00 00 */	lwz r12, 0(r3)
/* 800F76E8 000F4648  81 8C 00 08 */	lwz r12, 8(r12)
/* 800F76EC 000F464C  7D 88 03 A6 */	mtlr r12
/* 800F76F0 000F4650  4E 80 00 21 */	blrl 
lbl_800F76F4:
/* 800F76F4 000F4654  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 800F76F8 000F4658  2C 00 00 10 */	cmpwi r0, 0x10
/* 800F76FC 000F465C  40 82 00 14 */	bne lbl_800F7710
/* 800F7700 000F4660  A0 03 04 28 */	lhz r0, 0x428(r3)
/* 800F7704 000F4664  7C 00 F0 00 */	cmpw r0, r30
/* 800F7708 000F4668  40 82 00 08 */	bne lbl_800F7710
/* 800F770C 000F466C  48 00 00 6C */	b lbl_800F7778
lbl_800F7710:
/* 800F7710 000F4670  38 61 00 10 */	addi r3, r1, 0x10
/* 800F7714 000F4674  4B F9 85 85 */	bl next__8IteratorFv
lbl_800F7718:
/* 800F7718 000F4678  80 61 00 14 */	lwz r3, 0x14(r1)
/* 800F771C 000F467C  80 81 00 10 */	lwz r4, 0x10(r1)
/* 800F7720 000F4680  81 83 00 00 */	lwz r12, 0(r3)
/* 800F7724 000F4684  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800F7728 000F4688  7D 88 03 A6 */	mtlr r12
/* 800F772C 000F468C  4E 80 00 21 */	blrl 
/* 800F7730 000F4690  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800F7734 000F4694  41 82 00 0C */	beq lbl_800F7740
/* 800F7738 000F4698  38 00 00 01 */	li r0, 1
/* 800F773C 000F469C  48 00 00 30 */	b lbl_800F776C
lbl_800F7740:
/* 800F7740 000F46A0  80 61 00 14 */	lwz r3, 0x14(r1)
/* 800F7744 000F46A4  80 81 00 10 */	lwz r4, 0x10(r1)
/* 800F7748 000F46A8  81 83 00 00 */	lwz r12, 0(r3)
/* 800F774C 000F46AC  81 8C 00 08 */	lwz r12, 8(r12)
/* 800F7750 000F46B0  7D 88 03 A6 */	mtlr r12
/* 800F7754 000F46B4  4E 80 00 21 */	blrl 
/* 800F7758 000F46B8  28 03 00 00 */	cmplwi r3, 0
/* 800F775C 000F46BC  40 82 00 0C */	bne lbl_800F7768
/* 800F7760 000F46C0  38 00 00 01 */	li r0, 1
/* 800F7764 000F46C4  48 00 00 08 */	b lbl_800F776C
lbl_800F7768:
/* 800F7768 000F46C8  38 00 00 00 */	li r0, 0
lbl_800F776C:
/* 800F776C 000F46CC  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 800F7770 000F46D0  41 82 FF 48 */	beq lbl_800F76B8
/* 800F7774 000F46D4  38 60 00 00 */	li r3, 0
lbl_800F7778:
/* 800F7778 000F46D8  28 03 00 00 */	cmplwi r3, 0
/* 800F777C 000F46DC  41 82 00 0C */	beq lbl_800F7788
/* 800F7780 000F46E0  80 03 04 14 */	lwz r0, 0x414(r3)
/* 800F7784 000F46E4  7F FF 02 14 */	add r31, r31, r0
lbl_800F7788:
/* 800F7788 000F46E8  3B DE 00 01 */	addi r30, r30, 1
/* 800F778C 000F46EC  2C 1E 00 03 */	cmpwi r30, 3
/* 800F7790 000F46F0  41 80 FE FC */	blt lbl_800F768C
/* 800F7794 000F46F4  7F E3 FB 78 */	mr r3, r31
/* 800F7798 000F46F8  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800F779C 000F46FC  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800F77A0 000F4700  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 800F77A4 000F4704  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 800F77A8 000F4708  38 21 00 38 */	addi r1, r1, 0x38
/* 800F77AC 000F470C  7C 08 03 A6 */	mtlr r0
/* 800F77B0 000F4710  4E 80 00 20 */	blr 

.global __dt__11PikiHeadMgrFv
__dt__11PikiHeadMgrFv:
/* 800F77B4 000F4714  7C 08 02 A6 */	mflr r0
/* 800F77B8 000F4718  90 01 00 04 */	stw r0, 4(r1)
/* 800F77BC 000F471C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F77C0 000F4720  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F77C4 000F4724  7C 7F 1B 79 */	or. r31, r3, r3
/* 800F77C8 000F4728  41 82 00 58 */	beq lbl_800F7820
/* 800F77CC 000F472C  3C 60 80 2C */	lis r3, __vt__11PikiHeadMgr@ha
/* 800F77D0 000F4730  38 63 E8 A8 */	addi r3, r3, __vt__11PikiHeadMgr@l
/* 800F77D4 000F4734  90 7F 00 00 */	stw r3, 0(r31)
/* 800F77D8 000F4738  38 03 00 18 */	addi r0, r3, 0x18
/* 800F77DC 000F473C  90 1F 00 08 */	stw r0, 8(r31)
/* 800F77E0 000F4740  41 82 00 30 */	beq lbl_800F7810
/* 800F77E4 000F4744  3C 60 80 2C */	lis r3, __vt__13MonoObjectMgr@ha
/* 800F77E8 000F4748  38 63 AF C8 */	addi r3, r3, __vt__13MonoObjectMgr@l
/* 800F77EC 000F474C  90 7F 00 00 */	stw r3, 0(r31)
/* 800F77F0 000F4750  38 03 00 18 */	addi r0, r3, 0x18
/* 800F77F4 000F4754  90 1F 00 08 */	stw r0, 8(r31)
/* 800F77F8 000F4758  41 82 00 18 */	beq lbl_800F7810
/* 800F77FC 000F475C  3C 60 80 2C */	lis r3, __vt__9ObjectMgr@ha
/* 800F7800 000F4760  38 63 B0 80 */	addi r3, r3, __vt__9ObjectMgr@l
/* 800F7804 000F4764  90 7F 00 00 */	stw r3, 0(r31)
/* 800F7808 000F4768  38 03 00 18 */	addi r0, r3, 0x18
/* 800F780C 000F476C  90 1F 00 08 */	stw r0, 8(r31)
lbl_800F7810:
/* 800F7810 000F4770  7C 80 07 35 */	extsh. r0, r4
/* 800F7814 000F4774  40 81 00 0C */	ble lbl_800F7820
/* 800F7818 000F4778  7F E3 FB 78 */	mr r3, r31
/* 800F781C 000F477C  4B F4 F9 91 */	bl __dl__FPv
lbl_800F7820:
/* 800F7820 000F4780  7F E3 FB 78 */	mr r3, r31
/* 800F7824 000F4784  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F7828 000F4788  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F782C 000F478C  38 21 00 18 */	addi r1, r1, 0x18
/* 800F7830 000F4790  7C 08 03 A6 */	mtlr r0
/* 800F7834 000F4794  4E 80 00 20 */	blr 

.global __dt__7ItemMgrFv
__dt__7ItemMgrFv:
/* 800F7838 000F4798  7C 08 02 A6 */	mflr r0
/* 800F783C 000F479C  90 01 00 04 */	stw r0, 4(r1)
/* 800F7840 000F47A0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F7844 000F47A4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F7848 000F47A8  7C 7F 1B 79 */	or. r31, r3, r3
/* 800F784C 000F47AC  41 82 00 58 */	beq lbl_800F78A4
/* 800F7850 000F47B0  3C 60 80 2C */	lis r3, __vt__7ItemMgr@ha
/* 800F7854 000F47B4  38 63 E9 D8 */	addi r3, r3, __vt__7ItemMgr@l
/* 800F7858 000F47B8  90 7F 00 00 */	stw r3, 0(r31)
/* 800F785C 000F47BC  38 03 00 18 */	addi r0, r3, 0x18
/* 800F7860 000F47C0  90 1F 00 08 */	stw r0, 8(r31)
/* 800F7864 000F47C4  41 82 00 30 */	beq lbl_800F7894
/* 800F7868 000F47C8  3C 60 80 2C */	lis r3, __vt__13PolyObjectMgr@ha
/* 800F786C 000F47CC  38 63 AF 0C */	addi r3, r3, __vt__13PolyObjectMgr@l
/* 800F7870 000F47D0  90 7F 00 00 */	stw r3, 0(r31)
/* 800F7874 000F47D4  38 03 00 18 */	addi r0, r3, 0x18
/* 800F7878 000F47D8  90 1F 00 08 */	stw r0, 8(r31)
/* 800F787C 000F47DC  41 82 00 18 */	beq lbl_800F7894
/* 800F7880 000F47E0  3C 60 80 2C */	lis r3, __vt__9ObjectMgr@ha
/* 800F7884 000F47E4  38 63 B0 80 */	addi r3, r3, __vt__9ObjectMgr@l
/* 800F7888 000F47E8  90 7F 00 00 */	stw r3, 0(r31)
/* 800F788C 000F47EC  38 03 00 18 */	addi r0, r3, 0x18
/* 800F7890 000F47F0  90 1F 00 08 */	stw r0, 8(r31)
lbl_800F7894:
/* 800F7894 000F47F4  7C 80 07 35 */	extsh. r0, r4
/* 800F7898 000F47F8  40 81 00 0C */	ble lbl_800F78A4
/* 800F789C 000F47FC  7F E3 FB 78 */	mr r3, r31
/* 800F78A0 000F4800  4B F4 F9 0D */	bl __dl__FPv
lbl_800F78A4:
/* 800F78A4 000F4804  7F E3 FB 78 */	mr r3, r31
/* 800F78A8 000F4808  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F78AC 000F480C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F78B0 000F4810  38 21 00 18 */	addi r1, r1, 0x18
/* 800F78B4 000F4814  7C 08 03 A6 */	mtlr r0
/* 800F78B8 000F4818  4E 80 00 20 */	blr 

.global __dt__13MeltingPotMgrFv
__dt__13MeltingPotMgrFv:
/* 800F78BC 000F481C  7C 08 02 A6 */	mflr r0
/* 800F78C0 000F4820  90 01 00 04 */	stw r0, 4(r1)
/* 800F78C4 000F4824  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F78C8 000F4828  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F78CC 000F482C  7C 7F 1B 79 */	or. r31, r3, r3
/* 800F78D0 000F4830  41 82 00 58 */	beq lbl_800F7928
/* 800F78D4 000F4834  3C 60 80 2C */	lis r3, __vt__13MeltingPotMgr@ha
/* 800F78D8 000F4838  38 63 EF 38 */	addi r3, r3, __vt__13MeltingPotMgr@l
/* 800F78DC 000F483C  90 7F 00 00 */	stw r3, 0(r31)
/* 800F78E0 000F4840  38 03 00 18 */	addi r0, r3, 0x18
/* 800F78E4 000F4844  90 1F 00 08 */	stw r0, 8(r31)
/* 800F78E8 000F4848  41 82 00 30 */	beq lbl_800F7918
/* 800F78EC 000F484C  3C 60 80 2C */	lis r3, __vt__15CreatureNodeMgr@ha
/* 800F78F0 000F4850  38 63 AE 58 */	addi r3, r3, __vt__15CreatureNodeMgr@l
/* 800F78F4 000F4854  90 7F 00 00 */	stw r3, 0(r31)
/* 800F78F8 000F4858  38 03 00 18 */	addi r0, r3, 0x18
/* 800F78FC 000F485C  90 1F 00 08 */	stw r0, 8(r31)
/* 800F7900 000F4860  41 82 00 18 */	beq lbl_800F7918
/* 800F7904 000F4864  3C 60 80 2C */	lis r3, __vt__9ObjectMgr@ha
/* 800F7908 000F4868  38 63 B0 80 */	addi r3, r3, __vt__9ObjectMgr@l
/* 800F790C 000F486C  90 7F 00 00 */	stw r3, 0(r31)
/* 800F7910 000F4870  38 03 00 18 */	addi r0, r3, 0x18
/* 800F7914 000F4874  90 1F 00 08 */	stw r0, 8(r31)
lbl_800F7918:
/* 800F7918 000F4878  7C 80 07 35 */	extsh. r0, r4
/* 800F791C 000F487C  40 81 00 0C */	ble lbl_800F7928
/* 800F7920 000F4880  7F E3 FB 78 */	mr r3, r31
/* 800F7924 000F4884  4B F4 F8 89 */	bl __dl__FPv
lbl_800F7928:
/* 800F7928 000F4888  7F E3 FB 78 */	mr r3, r31
/* 800F792C 000F488C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F7930 000F4890  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F7934 000F4894  38 21 00 18 */	addi r1, r1, 0x18
/* 800F7938 000F4898  7C 08 03 A6 */	mtlr r0
/* 800F793C 000F489C  4E 80 00 20 */	blr 

.global getiMass__12BuildingItemFv
getiMass__12BuildingItemFv:
/* 800F7940 000F48A0  C0 22 9C 0C */	lfs f1, lbl_803E9E0C@sda21(r2)
/* 800F7944 000F48A4  4E 80 00 20 */	blr 

.global needShadow__12BuildingItemFv
needShadow__12BuildingItemFv:
/* 800F7948 000F48A8  38 60 00 00 */	li r3, 0
/* 800F794C 000F48AC  4E 80 00 20 */	blr 
/* 800F7950 000F48B0  38 63 FF F8 */	addi r3, r3, -8
/* 800F7954 000F48B4  4B FF F9 74 */	b update__7ItemMgrFv

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

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x61694573
	.4byte 0x63617065
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x61694573
	.4byte 0x63617065
	.4byte 0
.global lbl_802B6604
lbl_802B6604:
	.4byte 0x65736328
	.4byte 0x25732920
	.4byte 0x28252E31
	.4byte 0x662C252E
	.4byte 0x31662900
	.4byte 0x41637445
	.4byte 0x73636170
	.4byte 0x65000000
	.4byte 0x52656365
	.4byte 0x69766572
	.4byte 0x3C50696B
	.4byte 0x693E0000
	.4byte 0x803E0318
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x803E0318
	.4byte 0x00000000
	.4byte 0x803E0328
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__9ActEscape
__vt__9ActEscape:
	.4byte __RTTI__9ActEscape
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
	.4byte __dt__9ActEscapeFv
	.4byte init__9ActEscapeFP8Creature
	.4byte exec__9ActEscapeFv
	.4byte cleanup__9ActEscapeFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__9ActEscapeFPc
	.4byte 0x41637445
	.4byte 0x73636170
	.4byte 0x653a3a49
	.4byte 0x6e697469
	.4byte 0x616c6973
	.4byte 0x65720000
	.4byte 0x41637469
	.4byte 0x6f6e3a3a
	.4byte 0x496e6974
	.4byte 0x69616c69
	.4byte 0x73657200
	.4byte 0x803e0338
	.4byte 0
	.4byte 0
.global __vt__Q29ActEscape11Initialiser
__vt__Q29ActEscape11Initialiser:
	.4byte __RTTI__Q29ActEscape11Initialiser
	.4byte 0
	.4byte initialise__Q29ActEscape11InitialiserFP6Action
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

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global lbl_803E02C0
lbl_803E02C0:
	.4byte 0x00000000
.global lbl_803E02C4
lbl_803E02C4:
	.4byte 0x00000000
.global lbl_803E02C8
lbl_803E02C8:
	.4byte 0x00000000
	.4byte 0x802B6528
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E02D4
	.4byte 0x802B6538
.global __RTTI__8ActEnter
__RTTI__8ActEnter:
	.4byte 0x802b651c
	.4byte 0x802b6544
	.4byte 0
.global lbl_803E02F0
lbl_803E02F0:
	.4byte 0x00000000
.global lbl_803E02F4
lbl_803E02F4:
	.4byte 0x00000000
.global lbl_803E02F8
lbl_803E02F8:
	.4byte 0x00000000
.global lbl_803E02FC
lbl_803E02FC:
	.4byte 0x00000000
.global lbl_803E0300
lbl_803E0300:
	.4byte 0x00000000
.global lbl_803E0304
lbl_803E0304:
	.4byte 0x00000000
.global lbl_803E0308
lbl_803E0308:
	.4byte 0x4E4F524D
	.4byte 0x414C0000
.global lbl_803E0310
lbl_803E0310:
	.4byte 0x41564F49
	.4byte 0x44000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EAA1C
lbl_803EAA1C:
	.4byte 0x447A0000
.global lbl_803EAA20
lbl_803EAA20:
	.4byte 0x3F800000
.global lbl_803EAA24
lbl_803EAA24:
	.4byte 0x00000000
.global lbl_803EAA28
lbl_803EAA28:
	.4byte 0x459C4000
.global lbl_803EAA2C
lbl_803EAA2C:
	.4byte 0x41F00000
.global lbl_803EAA30
lbl_803EAA30:
	.4byte 0x41200000
.global lbl_803EAA34
lbl_803EAA34:
	.4byte 0x40490FDB
.global lbl_803EAA38
lbl_803EAA38:
	.4byte 0xC47A0000
.global lbl_803EAA3C
lbl_803EAA3C:
	.4byte 0x46FFFE00
.global lbl_803EAA40
lbl_803EAA40:
	.4byte 0x40C90FDB
.global lbl_803EAA44
lbl_803EAA44:
	.4byte 0x403FFFF3
.global "@1859"
"@1859":
	.4byte 0x43300000
	.4byte 0x80000000
.global lbl_803EAA50
lbl_803EAA50:
	.4byte 0x40A00000
.global lbl_803EAA54
lbl_803EAA54:
	.4byte 0x40C90FCE
.global lbl_803EAA58
lbl_803EAA58:
	.4byte 0x3F7FFFEF

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EC0F4
lbl_803EC0F4:
	.4byte 0x40400000
.global lbl_803EC0F8
lbl_803EC0F8:
	.4byte 0x40C90FDB
.global lbl_803EC0FC
lbl_803EC0FC:
	.4byte 0x3F666666
.global lbl_803EC100
lbl_803EC100:
	.4byte 0x3DCCCCCD
.global lbl_803EC104
lbl_803EC104:
	.4byte 0x40060A92
.global lbl_803EC108
lbl_803EC108:
	.4byte 0x40860A92
.global lbl_803EC10C
lbl_803EC10C:
	.4byte 0x3FC00000
.global lbl_803EC110
lbl_803EC110:
	.4byte 0x41A00000
.global lbl_803EC114
lbl_803EC114:
	.4byte 0x43340000
.global lbl_803EC118
lbl_803EC118:
	.4byte 0xBF800000
.global lbl_803EC11C
lbl_803EC11C:
	.4byte 0xC2C80000
.global lbl_803EC120
lbl_803EC120:
	.4byte 0x44390000
.global lbl_803EC124
lbl_803EC124:
	.4byte 0x44110000
.global lbl_803EC128
lbl_803EC128:
	.4byte 0x3CA3D70A
.global lbl_803EC12C
lbl_803EC12C:
	.4byte 0x3F6B851F
.global lbl_803EC130
lbl_803EC130:
	.4byte 0x3C8EFA35
