.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__9NucleusAiFP7Nucleus, global
/* 8017A544 001774A4  3C A0 80 2B */	lis r5, __vt__19PaniAnimKeyListener@ha
/* 8017A548 001774A8  38 05 DB 94 */	addi r0, r5, __vt__19PaniAnimKeyListener@l
/* 8017A54C 001774AC  3C A0 80 2D */	lis r5, __vt__9NucleusAi@ha
/* 8017A550 001774B0  90 03 00 00 */	stw r0, 0(r3)
/* 8017A554 001774B4  38 05 13 14 */	addi r0, r5, __vt__9NucleusAi@l
/* 8017A558 001774B8  90 03 00 00 */	stw r0, 0(r3)
/* 8017A55C 001774BC  90 83 00 08 */	stw r4, 8(r3)
/* 8017A560 001774C0  4E 80 00 20 */	blr 
.endfn __ct__9NucleusAiFP7Nucleus

.fn initAI__9NucleusAiFP7Nucleus, global
/* 8017A564 001774C4  7C 08 02 A6 */	mflr r0
/* 8017A568 001774C8  90 01 00 04 */	stw r0, 4(r1)
/* 8017A56C 001774CC  38 00 00 02 */	li r0, 2
/* 8017A570 001774D0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8017A574 001774D4  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8017A578 001774D8  7C 7F 1B 78 */	mr r31, r3
/* 8017A57C 001774DC  38 BF 00 00 */	addi r5, r31, 0
/* 8017A580 001774E0  90 83 00 08 */	stw r4, 8(r3)
/* 8017A584 001774E4  38 80 00 02 */	li r4, 2
/* 8017A588 001774E8  80 C3 00 08 */	lwz r6, 8(r3)
/* 8017A58C 001774EC  38 61 00 1C */	addi r3, r1, 0x1c
/* 8017A590 001774F0  90 06 02 E4 */	stw r0, 0x2e4(r6)
/* 8017A594 001774F4  80 DF 00 08 */	lwz r6, 8(r31)
/* 8017A598 001774F8  90 06 02 E8 */	stw r0, 0x2e8(r6)
/* 8017A59C 001774FC  4B FA 49 F1 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 8017A5A0 00177500  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A5A4 00177504  38 83 00 00 */	addi r4, r3, 0
/* 8017A5A8 00177508  38 65 03 3C */	addi r3, r5, 0x33c
/* 8017A5AC 0017750C  4B FA 4C 15 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 8017A5B0 00177510  C0 02 AE 60 */	lfs f0, lbl_803EB060@sda21(r2)
/* 8017A5B4 00177514  38 00 00 00 */	li r0, 0
/* 8017A5B8 00177518  80 7F 00 08 */	lwz r3, 8(r31)
/* 8017A5BC 0017751C  D0 03 02 D8 */	stfs f0, 0x2d8(r3)
/* 8017A5C0 00177520  90 1F 00 04 */	stw r0, 4(r31)
/* 8017A5C4 00177524  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8017A5C8 00177528  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8017A5CC 0017752C  38 21 00 30 */	addi r1, r1, 0x30
/* 8017A5D0 00177530  7C 08 03 A6 */	mtlr r0
/* 8017A5D4 00177534  4E 80 00 20 */	blr 
.endfn initAI__9NucleusAiFP7Nucleus

.fn animationKeyUpdated__9NucleusAiFR16PaniAnimKeyEvent, global
/* 8017A5D8 00177538  7C 08 02 A6 */	mflr r0
/* 8017A5DC 0017753C  90 01 00 04 */	stw r0, 4(r1)
/* 8017A5E0 00177540  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017A5E4 00177544  80 04 00 00 */	lwz r0, 0(r4)
/* 8017A5E8 00177548  2C 00 00 02 */	cmpwi r0, 2
/* 8017A5EC 0017754C  41 82 00 38 */	beq .L_8017A624
/* 8017A5F0 00177550  40 80 00 14 */	bge .L_8017A604
/* 8017A5F4 00177554  2C 00 00 00 */	cmpwi r0, 0
/* 8017A5F8 00177558  41 82 00 3C */	beq .L_8017A634
/* 8017A5FC 0017755C  40 80 00 20 */	bge .L_8017A61C
/* 8017A600 00177560  48 00 00 44 */	b .L_8017A644
.L_8017A604:
/* 8017A604 00177564  2C 00 00 07 */	cmpwi r0, 7
/* 8017A608 00177568  41 82 00 34 */	beq .L_8017A63C
/* 8017A60C 0017756C  40 80 00 38 */	bge .L_8017A644
/* 8017A610 00177570  2C 00 00 06 */	cmpwi r0, 6
/* 8017A614 00177574  40 80 00 18 */	bge .L_8017A62C
/* 8017A618 00177578  48 00 00 2C */	b .L_8017A644
.L_8017A61C:
/* 8017A61C 0017757C  48 00 00 39 */	bl keyAction0__9NucleusAiFv
/* 8017A620 00177580  48 00 00 24 */	b .L_8017A644
.L_8017A624:
/* 8017A624 00177584  48 00 00 35 */	bl keyAction1__9NucleusAiFv
/* 8017A628 00177588  48 00 00 1C */	b .L_8017A644
.L_8017A62C:
/* 8017A62C 0017758C  48 00 00 31 */	bl keyLoopEnd__9NucleusAiFv
/* 8017A630 00177590  48 00 00 14 */	b .L_8017A644
.L_8017A634:
/* 8017A634 00177594  48 00 00 3D */	bl keyFinished__9NucleusAiFv
/* 8017A638 00177598  48 00 00 0C */	b .L_8017A644
.L_8017A63C:
/* 8017A63C 0017759C  80 84 00 04 */	lwz r4, 4(r4)
/* 8017A640 001775A0  48 00 00 41 */	bl playSound__9NucleusAiFi
.L_8017A644:
/* 8017A644 001775A4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017A648 001775A8  38 21 00 08 */	addi r1, r1, 8
/* 8017A64C 001775AC  7C 08 03 A6 */	mtlr r0
/* 8017A650 001775B0  4E 80 00 20 */	blr 
.endfn animationKeyUpdated__9NucleusAiFR16PaniAnimKeyEvent

.fn keyAction0__9NucleusAiFv, global
/* 8017A654 001775B4  4E 80 00 20 */	blr 
.endfn keyAction0__9NucleusAiFv

.fn keyAction1__9NucleusAiFv, global
/* 8017A658 001775B8  4E 80 00 20 */	blr 
.endfn keyAction1__9NucleusAiFv

.fn keyLoopEnd__9NucleusAiFv, global
/* 8017A65C 001775BC  80 83 00 08 */	lwz r4, 8(r3)
/* 8017A660 001775C0  80 64 02 EC */	lwz r3, 0x2ec(r4)
/* 8017A664 001775C4  38 03 00 01 */	addi r0, r3, 1
/* 8017A668 001775C8  90 04 02 EC */	stw r0, 0x2ec(r4)
/* 8017A66C 001775CC  4E 80 00 20 */	blr 
.endfn keyLoopEnd__9NucleusAiFv

.fn keyFinished__9NucleusAiFv, global
/* 8017A670 001775D0  80 63 00 08 */	lwz r3, 8(r3)
/* 8017A674 001775D4  38 00 00 01 */	li r0, 1
/* 8017A678 001775D8  98 03 02 BD */	stb r0, 0x2bd(r3)
/* 8017A67C 001775DC  4E 80 00 20 */	blr 
.endfn keyFinished__9NucleusAiFv

.fn playSound__9NucleusAiFi, global
/* 8017A680 001775E0  4E 80 00 20 */	blr 
.endfn playSound__9NucleusAiFi

.fn update__9NucleusAiFv, global
/* 8017A684 001775E4  7C 08 02 A6 */	mflr r0
/* 8017A688 001775E8  90 01 00 04 */	stw r0, 4(r1)
/* 8017A68C 001775EC  94 21 FF 68 */	stwu r1, -0x98(r1)
/* 8017A690 001775F0  93 E1 00 94 */	stw r31, 0x94(r1)
/* 8017A694 001775F4  7C 7F 1B 78 */	mr r31, r3
/* 8017A698 001775F8  80 63 00 08 */	lwz r3, 8(r3)
/* 8017A69C 001775FC  4B FD 49 B1 */	bl getStickPikiCount__4BossFv
/* 8017A6A0 00177600  90 7F 00 04 */	stw r3, 4(r31)
/* 8017A6A4 00177604  80 9F 00 08 */	lwz r4, 8(r31)
/* 8017A6A8 00177608  80 64 03 B8 */	lwz r3, 0x3b8(r4)
/* 8017A6AC 0017760C  C0 03 03 DC */	lfs f0, 0x3dc(r3)
/* 8017A6B0 00177610  D0 04 00 94 */	stfs f0, 0x94(r4)
/* 8017A6B4 00177614  80 9F 00 08 */	lwz r4, 8(r31)
/* 8017A6B8 00177618  80 64 03 B8 */	lwz r3, 0x3b8(r4)
/* 8017A6BC 0017761C  C0 03 03 E4 */	lfs f0, 0x3e4(r3)
/* 8017A6C0 00177620  D0 04 00 9C */	stfs f0, 0x9c(r4)
/* 8017A6C4 00177624  80 7F 00 08 */	lwz r3, 8(r31)
/* 8017A6C8 00177628  C0 23 02 C0 */	lfs f1, 0x2c0(r3)
/* 8017A6CC 0017762C  80 63 03 B8 */	lwz r3, 0x3b8(r3)
/* 8017A6D0 00177630  80 63 04 00 */	lwz r3, 0x400(r3)
/* 8017A6D4 00177634  4B FE A5 5D */	bl addDamagePoint__7SlimeAiFf
/* 8017A6D8 00177638  80 7F 00 08 */	lwz r3, 8(r31)
/* 8017A6DC 0017763C  80 03 02 E4 */	lwz r0, 0x2e4(r3)
/* 8017A6E0 00177640  2C 00 00 01 */	cmpwi r0, 1
/* 8017A6E4 00177644  41 82 00 18 */	beq .L_8017A6FC
/* 8017A6E8 00177648  40 80 00 08 */	bge .L_8017A6F0
/* 8017A6EC 0017764C  48 00 02 48 */	b .L_8017A934
.L_8017A6F0:
/* 8017A6F0 00177650  2C 00 00 03 */	cmpwi r0, 3
/* 8017A6F4 00177654  40 80 02 40 */	bge .L_8017A934
/* 8017A6F8 00177658  48 00 01 18 */	b .L_8017A810
.L_8017A6FC:
/* 8017A6FC 0017765C  C0 23 02 C4 */	lfs f1, 0x2c4(r3)
/* 8017A700 00177660  C0 02 AE 64 */	lfs f0, lbl_803EB064@sda21(r2)
/* 8017A704 00177664  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8017A708 00177668  7C 00 00 26 */	mfcr r0
/* 8017A70C 0017766C  54 00 17 FF */	rlwinm. r0, r0, 2, 0x1f, 0x1f
/* 8017A710 00177670  40 82 00 B4 */	bne .L_8017A7C4
/* 8017A714 00177674  38 00 00 00 */	li r0, 0
/* 8017A718 00177678  90 03 02 E8 */	stw r0, 0x2e8(r3)
/* 8017A71C 0017767C  38 BF 00 00 */	addi r5, r31, 0
/* 8017A720 00177680  38 61 00 84 */	addi r3, r1, 0x84
/* 8017A724 00177684  80 DF 00 08 */	lwz r6, 8(r31)
/* 8017A728 00177688  38 80 00 01 */	li r4, 1
/* 8017A72C 0017768C  98 06 02 BD */	stb r0, 0x2bd(r6)
/* 8017A730 00177690  80 DF 00 08 */	lwz r6, 8(r31)
/* 8017A734 00177694  90 06 02 EC */	stw r0, 0x2ec(r6)
/* 8017A738 00177698  4B FA 48 55 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 8017A73C 0017769C  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A740 001776A0  38 83 00 00 */	addi r4, r3, 0
/* 8017A744 001776A4  38 65 03 3C */	addi r3, r5, 0x33c
/* 8017A748 001776A8  4B FA 4A 79 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 8017A74C 001776AC  C0 02 AE 64 */	lfs f0, lbl_803EB064@sda21(r2)
/* 8017A750 001776B0  38 80 00 39 */	li r4, 0x39
/* 8017A754 001776B4  80 7F 00 08 */	lwz r3, 8(r31)
/* 8017A758 001776B8  38 C0 00 00 */	li r6, 0
/* 8017A75C 001776BC  38 E0 00 00 */	li r7, 0
/* 8017A760 001776C0  D0 03 02 D4 */	stfs f0, 0x2d4(r3)
/* 8017A764 001776C4  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A768 001776C8  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8017A76C 001776CC  38 A5 00 94 */	addi r5, r5, 0x94
/* 8017A770 001776D0  48 02 23 C9 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8017A774 001776D4  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A778 001776D8  38 80 00 38 */	li r4, 0x38
/* 8017A77C 001776DC  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8017A780 001776E0  38 C0 00 00 */	li r6, 0
/* 8017A784 001776E4  38 A5 00 94 */	addi r5, r5, 0x94
/* 8017A788 001776E8  38 E0 00 00 */	li r7, 0
/* 8017A78C 001776EC  48 02 23 AD */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8017A790 001776F0  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A794 001776F4  38 80 00 37 */	li r4, 0x37
/* 8017A798 001776F8  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8017A79C 001776FC  38 C0 00 00 */	li r6, 0
/* 8017A7A0 00177700  38 A5 00 94 */	addi r5, r5, 0x94
/* 8017A7A4 00177704  38 E0 00 00 */	li r7, 0
/* 8017A7A8 00177708  48 02 23 91 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8017A7AC 0017770C  80 7F 00 08 */	lwz r3, 8(r31)
/* 8017A7B0 00177710  81 83 00 00 */	lwz r12, 0(r3)
/* 8017A7B4 00177714  81 8C 01 0C */	lwz r12, 0x10c(r12)
/* 8017A7B8 00177718  7D 88 03 A6 */	mtlr r12
/* 8017A7BC 0017771C  4E 80 00 21 */	blrl 
/* 8017A7C0 00177720  48 00 01 74 */	b .L_8017A934
.L_8017A7C4:
/* 8017A7C4 00177724  88 03 02 BD */	lbz r0, 0x2bd(r3)
/* 8017A7C8 00177728  28 00 00 00 */	cmplwi r0, 0
/* 8017A7CC 0017772C  41 82 01 68 */	beq .L_8017A934
/* 8017A7D0 00177730  38 00 00 02 */	li r0, 2
/* 8017A7D4 00177734  90 03 02 E8 */	stw r0, 0x2e8(r3)
/* 8017A7D8 00177738  38 00 00 00 */	li r0, 0
/* 8017A7DC 0017773C  38 BF 00 00 */	addi r5, r31, 0
/* 8017A7E0 00177740  80 DF 00 08 */	lwz r6, 8(r31)
/* 8017A7E4 00177744  38 61 00 7C */	addi r3, r1, 0x7c
/* 8017A7E8 00177748  38 80 00 02 */	li r4, 2
/* 8017A7EC 0017774C  98 06 02 BD */	stb r0, 0x2bd(r6)
/* 8017A7F0 00177750  80 DF 00 08 */	lwz r6, 8(r31)
/* 8017A7F4 00177754  90 06 02 EC */	stw r0, 0x2ec(r6)
/* 8017A7F8 00177758  4B FA 47 95 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 8017A7FC 0017775C  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A800 00177760  38 83 00 00 */	addi r4, r3, 0
/* 8017A804 00177764  38 65 03 3C */	addi r3, r5, 0x33c
/* 8017A808 00177768  4B FA 49 B9 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 8017A80C 0017776C  48 00 01 28 */	b .L_8017A934
.L_8017A810:
/* 8017A810 00177770  C0 03 02 C4 */	lfs f0, 0x2c4(r3)
/* 8017A814 00177774  C0 22 AE 64 */	lfs f1, lbl_803EB064@sda21(r2)
/* 8017A818 00177778  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8017A81C 0017777C  7C 00 00 26 */	mfcr r0
/* 8017A820 00177780  54 00 17 FF */	rlwinm. r0, r0, 2, 0x1f, 0x1f
/* 8017A824 00177784  40 82 00 B4 */	bne .L_8017A8D8
/* 8017A828 00177788  38 00 00 00 */	li r0, 0
/* 8017A82C 0017778C  90 03 02 E8 */	stw r0, 0x2e8(r3)
/* 8017A830 00177790  38 BF 00 00 */	addi r5, r31, 0
/* 8017A834 00177794  38 61 00 74 */	addi r3, r1, 0x74
/* 8017A838 00177798  80 DF 00 08 */	lwz r6, 8(r31)
/* 8017A83C 0017779C  38 80 00 01 */	li r4, 1
/* 8017A840 001777A0  98 06 02 BD */	stb r0, 0x2bd(r6)
/* 8017A844 001777A4  80 DF 00 08 */	lwz r6, 8(r31)
/* 8017A848 001777A8  90 06 02 EC */	stw r0, 0x2ec(r6)
/* 8017A84C 001777AC  4B FA 47 41 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 8017A850 001777B0  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A854 001777B4  38 83 00 00 */	addi r4, r3, 0
/* 8017A858 001777B8  38 65 03 3C */	addi r3, r5, 0x33c
/* 8017A85C 001777BC  4B FA 49 65 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 8017A860 001777C0  C0 02 AE 64 */	lfs f0, lbl_803EB064@sda21(r2)
/* 8017A864 001777C4  38 80 00 39 */	li r4, 0x39
/* 8017A868 001777C8  80 7F 00 08 */	lwz r3, 8(r31)
/* 8017A86C 001777CC  38 C0 00 00 */	li r6, 0
/* 8017A870 001777D0  38 E0 00 00 */	li r7, 0
/* 8017A874 001777D4  D0 03 02 D4 */	stfs f0, 0x2d4(r3)
/* 8017A878 001777D8  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A87C 001777DC  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8017A880 001777E0  38 A5 00 94 */	addi r5, r5, 0x94
/* 8017A884 001777E4  48 02 22 B5 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8017A888 001777E8  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A88C 001777EC  38 80 00 38 */	li r4, 0x38
/* 8017A890 001777F0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8017A894 001777F4  38 C0 00 00 */	li r6, 0
/* 8017A898 001777F8  38 A5 00 94 */	addi r5, r5, 0x94
/* 8017A89C 001777FC  38 E0 00 00 */	li r7, 0
/* 8017A8A0 00177800  48 02 22 99 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8017A8A4 00177804  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A8A8 00177808  38 80 00 37 */	li r4, 0x37
/* 8017A8AC 0017780C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8017A8B0 00177810  38 C0 00 00 */	li r6, 0
/* 8017A8B4 00177814  38 A5 00 94 */	addi r5, r5, 0x94
/* 8017A8B8 00177818  38 E0 00 00 */	li r7, 0
/* 8017A8BC 0017781C  48 02 22 7D */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8017A8C0 00177820  80 7F 00 08 */	lwz r3, 8(r31)
/* 8017A8C4 00177824  81 83 00 00 */	lwz r12, 0(r3)
/* 8017A8C8 00177828  81 8C 01 0C */	lwz r12, 0x10c(r12)
/* 8017A8CC 0017782C  7D 88 03 A6 */	mtlr r12
/* 8017A8D0 00177830  4E 80 00 21 */	blrl 
/* 8017A8D4 00177834  48 00 00 60 */	b .L_8017A934
.L_8017A8D8:
/* 8017A8D8 00177838  C0 03 02 C0 */	lfs f0, 0x2c0(r3)
/* 8017A8DC 0017783C  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8017A8E0 00177840  40 81 00 0C */	ble .L_8017A8EC
/* 8017A8E4 00177844  38 00 00 01 */	li r0, 1
/* 8017A8E8 00177848  48 00 00 08 */	b .L_8017A8F0
.L_8017A8EC:
/* 8017A8EC 0017784C  38 00 00 00 */	li r0, 0
.L_8017A8F0:
/* 8017A8F0 00177850  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8017A8F4 00177854  41 82 00 40 */	beq .L_8017A934
/* 8017A8F8 00177858  38 00 00 01 */	li r0, 1
/* 8017A8FC 0017785C  90 03 02 E8 */	stw r0, 0x2e8(r3)
/* 8017A900 00177860  38 00 00 00 */	li r0, 0
/* 8017A904 00177864  38 BF 00 00 */	addi r5, r31, 0
/* 8017A908 00177868  80 DF 00 08 */	lwz r6, 8(r31)
/* 8017A90C 0017786C  38 61 00 6C */	addi r3, r1, 0x6c
/* 8017A910 00177870  38 80 00 01 */	li r4, 1
/* 8017A914 00177874  98 06 02 BD */	stb r0, 0x2bd(r6)
/* 8017A918 00177878  80 DF 00 08 */	lwz r6, 8(r31)
/* 8017A91C 0017787C  90 06 02 EC */	stw r0, 0x2ec(r6)
/* 8017A920 00177880  4B FA 46 6D */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 8017A924 00177884  80 BF 00 08 */	lwz r5, 8(r31)
/* 8017A928 00177888  38 83 00 00 */	addi r4, r3, 0
/* 8017A92C 0017788C  38 65 03 3C */	addi r3, r5, 0x33c
/* 8017A930 00177890  4B FA 48 91 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
.L_8017A934:
/* 8017A934 00177894  C0 02 AE 64 */	lfs f0, lbl_803EB064@sda21(r2)
/* 8017A938 00177898  80 7F 00 08 */	lwz r3, 8(r31)
/* 8017A93C 0017789C  D0 03 02 C0 */	stfs f0, 0x2c0(r3)
/* 8017A940 001778A0  80 01 00 9C */	lwz r0, 0x9c(r1)
/* 8017A944 001778A4  83 E1 00 94 */	lwz r31, 0x94(r1)
/* 8017A948 001778A8  38 21 00 98 */	addi r1, r1, 0x98
/* 8017A94C 001778AC  7C 08 03 A6 */	mtlr r0
/* 8017A950 001778B0  4E 80 00 20 */	blr 
.endfn update__9NucleusAiFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802D12D8, local
	.asciz "NucleusAi.cpp"
.endobj lbl_802D12D8
.balign 4
.obj lbl_802D12E8, local
	.asciz "NucleusAi"
.endobj lbl_802D12E8
.balign 4
.obj lbl_802D12F4, local
	.asciz "PaniAnimKeyListener"
.endobj lbl_802D12F4
.balign 4
.obj lbl_802D1308, local
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0
	.4byte 0
.endobj lbl_802D1308
.balign 4
.obj __vt__9NucleusAi, global
	.4byte __RTTI__9NucleusAi
	.4byte 0
	.4byte animationKeyUpdated__9NucleusAiFR16PaniAnimKeyEvent
.endobj __vt__9NucleusAi
.skip 0x10 # compiler padding

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__19PaniAnimKeyListener, local
	.4byte lbl_802D12F4
	.4byte 0
.endobj __RTTI__19PaniAnimKeyListener
.balign 4
.obj __RTTI__9NucleusAi, local
	.4byte lbl_802D12E8
	.4byte lbl_802D1308
.endobj __RTTI__9NucleusAi

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EB060, local
	.float 30.0
.endobj lbl_803EB060
.obj lbl_803EB064, local
	.float 0.0
.endobj lbl_803EB064
