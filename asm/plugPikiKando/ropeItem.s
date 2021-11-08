.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8012C610 00129570  D0 1E 00 10 */	stfs f0, 0x10(r30)
lbl_8012C614:
/* 8012C614 00129574  38 60 00 10 */	li r3, 0x10
/* 8012C618 00129578  4B F1 A9 ED */	bl alloc__6SystemFUl
/* 8012C61C 0012957C  3B A3 00 00 */	addi r29, r3, 0
/* 8012C620 00129580  7F A0 EB 79 */	or. r0, r29, r29
/* 8012C624 00129584  41 82 00 2C */	beq lbl_8012C650
/* 8012C628 00129588  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C62C 0012958C  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C630 00129590  90 1D 00 04 */	stw r0, 4(r29)
/* 8012C634 00129594  38 00 00 08 */	li r0, 8
/* 8012C638 00129598  3C 60 80 2C */	lis r3, __vt__19TaiDependenceAction@ha
/* 8012C63C 0012959C  90 1D 00 00 */	stw r0, 0(r29)
/* 8012C640 001295A0  38 03 7B B0 */	addi r0, r3, __vt__19TaiDependenceAction@l
/* 8012C644 001295A4  90 1D 00 04 */	stw r0, 4(r29)
/* 8012C648 001295A8  92 5D 00 08 */	stw r18, 8(r29)
/* 8012C64C 001295AC  93 DD 00 0C */	stw r30, 0xc(r29)
lbl_8012C650:
/* 8012C650 001295B0  38 60 00 08 */	li r3, 8
/* 8012C654 001295B4  4B F1 A9 B1 */	bl alloc__6SystemFUl
/* 8012C658 001295B8  3B 63 00 00 */	addi r27, r3, 0
/* 8012C65C 001295BC  7F 60 DB 79 */	or. r0, r27, r27
/* 8012C660 001295C0  41 82 00 24 */	beq lbl_8012C684
/* 8012C664 001295C4  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C668 001295C8  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C66C 001295CC  90 1B 00 04 */	stw r0, 4(r27)
/* 8012C670 001295D0  38 00 FF FF */	li r0, -1
/* 8012C674 001295D4  3C 60 80 2C */	lis r3, __vt__25TaiCollecRoundCarryAction@ha
/* 8012C678 001295D8  90 1B 00 00 */	stw r0, 0(r27)
/* 8012C67C 001295DC  38 03 74 D4 */	addi r0, r3, __vt__25TaiCollecRoundCarryAction@l
/* 8012C680 001295E0  90 1B 00 04 */	stw r0, 4(r27)
lbl_8012C684:
/* 8012C684 001295E4  38 60 00 0C */	li r3, 0xc
/* 8012C688 001295E8  4B F1 A9 7D */	bl alloc__6SystemFUl
/* 8012C68C 001295EC  3B E3 00 00 */	addi r31, r3, 0
/* 8012C690 001295F0  7F E3 FB 79 */	or. r3, r31, r31
/* 8012C694 001295F4  41 82 00 0C */	beq lbl_8012C6A0
/* 8012C698 001295F8  38 80 00 0A */	li r4, 0xa
/* 8012C69C 001295FC  4B FF A9 FD */	bl __ct__8TaiStateFi
lbl_8012C6A0:
/* 8012C6A0 00129600  38 00 00 00 */	li r0, 0
/* 8012C6A4 00129604  80 7F 00 08 */	lwz r3, 8(r31)
/* 8012C6A8 00129608  80 81 02 24 */	lwz r4, 0x224(r1)
/* 8012C6AC 0012960C  54 00 10 3A */	slwi r0, r0, 2
/* 8012C6B0 00129610  39 00 00 04 */	li r8, 4
/* 8012C6B4 00129614  7C 83 01 2E */	stwx r4, r3, r0
/* 8012C6B8 00129618  38 80 00 01 */	li r4, 1
/* 8012C6BC 0012961C  54 85 10 3A */	slwi r5, r4, 2
/* 8012C6C0 00129620  80 7F 00 08 */	lwz r3, 8(r31)
/* 8012C6C4 00129624  38 00 00 02 */	li r0, 2
/* 8012C6C8 00129628  38 80 00 03 */	li r4, 3
/* 8012C6CC 0012962C  7E 23 29 2E */	stwx r17, r3, r5
/* 8012C6D0 00129630  54 86 10 3A */	slwi r6, r4, 2
/* 8012C6D4 00129634  54 00 10 3A */	slwi r0, r0, 2
/* 8012C6D8 00129638  80 7F 00 08 */	lwz r3, 8(r31)
/* 8012C6DC 0012963C  38 80 00 09 */	li r4, 9
/* 8012C6E0 00129640  38 A0 00 05 */	li r5, 5
/* 8012C6E4 00129644  7D C3 01 2E */	stwx r14, r3, r0
/* 8012C6E8 00129648  38 00 00 07 */	li r0, 7
/* 8012C6EC 0012964C  39 20 00 06 */	li r9, 6
/* 8012C6F0 00129650  80 FF 00 08 */	lwz r7, 8(r31)
/* 8012C6F4 00129654  54 00 10 3A */	slwi r0, r0, 2
/* 8012C6F8 00129658  38 60 00 08 */	li r3, 8
/* 8012C6FC 0012965C  7D E7 31 2E */	stwx r15, r7, r6
/* 8012C700 00129660  55 07 10 3A */	slwi r7, r8, 2
/* 8012C704 00129664  54 A6 10 3A */	slwi r6, r5, 2
/* 8012C708 00129668  81 1F 00 08 */	lwz r8, 8(r31)
/* 8012C70C 0012966C  55 25 10 3A */	slwi r5, r9, 2
/* 8012C710 00129670  7E 08 39 2E */	stwx r16, r8, r7
/* 8012C714 00129674  54 88 10 3A */	slwi r8, r4, 2
/* 8012C718 00129678  54 67 10 3A */	slwi r7, r3, 2
/* 8012C71C 0012967C  80 9F 00 08 */	lwz r4, 8(r31)
/* 8012C720 00129680  7E E3 BB 78 */	mr r3, r23
/* 8012C724 00129684  7E 84 31 2E */	stwx r20, r4, r6
/* 8012C728 00129688  80 9F 00 08 */	lwz r4, 8(r31)
/* 8012C72C 0012968C  7F 04 29 2E */	stwx r24, r4, r5
/* 8012C730 00129690  80 9F 00 08 */	lwz r4, 8(r31)
/* 8012C734 00129694  7F 64 01 2E */	stwx r27, r4, r0
/* 8012C738 00129698  80 9F 00 08 */	lwz r4, 8(r31)
/* 8012C73C 0012969C  7E C4 39 2E */	stwx r22, r4, r7
/* 8012C740 001296A0  80 9F 00 08 */	lwz r4, 8(r31)
/* 8012C744 001296A4  7F A4 41 2E */	stwx r29, r4, r8
/* 8012C748 001296A8  80 97 00 08 */	lwz r4, 8(r23)
/* 8012C74C 001296AC  93 E4 00 38 */	stw r31, 0x38(r4)
/* 8012C750 001296B0  B9 C1 02 38 */	lmw r14, 0x238(r1)
/* 8012C754 001296B4  80 01 02 84 */	lwz r0, 0x284(r1)
/* 8012C758 001296B8  38 21 02 80 */	addi r1, r1, 0x280
/* 8012C75C 001296BC  7C 08 03 A6 */	mtlr r0
/* 8012C760 001296C0  4E 80 00 20 */	blr 

.global start__17TaiCollecStrategyFR4Teki
start__17TaiCollecStrategyFR4Teki:
/* 8012C764 001296C4  7C 08 02 A6 */	mflr r0
/* 8012C768 001296C8  38 C0 00 00 */	li r6, 0
/* 8012C76C 001296CC  90 01 00 04 */	stw r0, 4(r1)
/* 8012C770 001296D0  38 E0 00 00 */	li r7, 0
/* 8012C774 001296D4  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 8012C778 001296D8  93 E1 00 44 */	stw r31, 0x44(r1)
/* 8012C77C 001296DC  7C 9F 23 78 */	mr r31, r4
/* 8012C780 001296E0  38 A1 00 34 */	addi r5, r1, 0x34
/* 8012C784 001296E4  93 C1 00 40 */	stw r30, 0x40(r1)
/* 8012C788 001296E8  3B C3 00 00 */	addi r30, r3, 0
/* 8012C78C 001296EC  38 80 00 61 */	li r4, 0x61
/* 8012C790 001296F0  C0 0D E8 B4 */	lfs f0, lbl_803E35D4@sda21(r13)
/* 8012C794 001296F4  C0 2D E8 B8 */	lfs f1, lbl_803E35D8@sda21(r13)
/* 8012C798 001296F8  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 8012C79C 001296FC  C0 0D E8 BC */	lfs f0, lbl_803E35DC@sda21(r13)
/* 8012C7A0 00129700  D0 21 00 38 */	stfs f1, 0x38(r1)
/* 8012C7A4 00129704  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8012C7A8 00129708  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 8012C7AC 0012970C  48 07 03 8D */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8012C7B0 00129710  80 BF 03 D8 */	lwz r5, 0x3d8(r31)
/* 8012C7B4 00129714  38 80 00 00 */	li r4, 0
/* 8012C7B8 00129718  90 65 00 00 */	stw r3, 0(r5)
/* 8012C7BC 0012971C  7F E3 FB 78 */	mr r3, r31
/* 8012C7C0 00129720  48 01 D2 5D */	bl stopParticleGenerator__5BTekiFi
/* 8012C7C4 00129724  C0 0D E8 C0 */	lfs f0, lbl_803E35E0@sda21(r13)
/* 8012C7C8 00129728  38 A1 00 28 */	addi r5, r1, 0x28
/* 8012C7CC 0012972C  C0 2D E8 C4 */	lfs f1, lbl_803E35E4@sda21(r13)
/* 8012C7D0 00129730  38 80 00 62 */	li r4, 0x62
/* 8012C7D4 00129734  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 8012C7D8 00129738  C0 0D E8 C8 */	lfs f0, lbl_803E35E8@sda21(r13)
/* 8012C7DC 0012973C  38 C0 00 00 */	li r6, 0
/* 8012C7E0 00129740  D0 21 00 2C */	stfs f1, 0x2c(r1)
/* 8012C7E4 00129744  38 E0 00 00 */	li r7, 0
/* 8012C7E8 00129748  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8012C7EC 0012974C  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 8012C7F0 00129750  48 07 03 49 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8012C7F4 00129754  80 BF 03 D8 */	lwz r5, 0x3d8(r31)
/* 8012C7F8 00129758  38 80 00 01 */	li r4, 1
/* 8012C7FC 0012975C  90 65 00 04 */	stw r3, 4(r5)
/* 8012C800 00129760  7F E3 FB 78 */	mr r3, r31
/* 8012C804 00129764  48 01 D2 19 */	bl stopParticleGenerator__5BTekiFi
/* 8012C808 00129768  C0 0D E8 CC */	lfs f0, lbl_803E35EC@sda21(r13)
/* 8012C80C 0012976C  38 A1 00 1C */	addi r5, r1, 0x1c
/* 8012C810 00129770  C0 2D E8 D0 */	lfs f1, lbl_803E35F0@sda21(r13)
/* 8012C814 00129774  38 80 00 5E */	li r4, 0x5e
/* 8012C818 00129778  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 8012C81C 0012977C  C0 0D E8 D4 */	lfs f0, lbl_803E35F4@sda21(r13)
/* 8012C820 00129780  38 C0 00 00 */	li r6, 0
/* 8012C824 00129784  D0 21 00 20 */	stfs f1, 0x20(r1)
/* 8012C828 00129788  38 E0 00 00 */	li r7, 0
/* 8012C82C 0012978C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8012C830 00129790  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 8012C834 00129794  48 07 03 05 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8012C838 00129798  80 BF 03 D8 */	lwz r5, 0x3d8(r31)
/* 8012C83C 0012979C  38 80 00 02 */	li r4, 2
/* 8012C840 001297A0  90 65 00 08 */	stw r3, 8(r5)
/* 8012C844 001297A4  7F E3 FB 78 */	mr r3, r31
/* 8012C848 001297A8  48 01 D1 D5 */	bl stopParticleGenerator__5BTekiFi
/* 8012C84C 001297AC  C0 0D E8 D8 */	lfs f0, lbl_803E35F8@sda21(r13)
/* 8012C850 001297B0  38 A1 00 10 */	addi r5, r1, 0x10
/* 8012C854 001297B4  C0 2D E8 DC */	lfs f1, lbl_803E35FC@sda21(r13)
/* 8012C858 001297B8  38 80 00 5D */	li r4, 0x5d
/* 8012C85C 001297BC  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8012C860 001297C0  C0 0D E8 E0 */	lfs f0, lbl_803E3600@sda21(r13)
/* 8012C864 001297C4  38 C0 00 00 */	li r6, 0
/* 8012C868 001297C8  D0 21 00 14 */	stfs f1, 0x14(r1)
/* 8012C86C 001297CC  38 E0 00 00 */	li r7, 0
/* 8012C870 001297D0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8012C874 001297D4  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 8012C878 001297D8  48 07 02 C1 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8012C87C 001297DC  80 BF 03 D8 */	lwz r5, 0x3d8(r31)
/* 8012C880 001297E0  38 80 00 03 */	li r4, 3
/* 8012C884 001297E4  90 65 00 0C */	stw r3, 0xc(r5)
/* 8012C888 001297E8  7F E3 FB 78 */	mr r3, r31
/* 8012C88C 001297EC  48 01 D1 91 */	bl stopParticleGenerator__5BTekiFi
/* 8012C890 001297F0  38 7E 00 00 */	addi r3, r30, 0
/* 8012C894 001297F4  38 9F 00 00 */	addi r4, r31, 0
/* 8012C898 001297F8  4B FF AB FD */	bl start__11TaiStrategyFR4Teki
/* 8012C89C 001297FC  7F E3 FB 78 */	mr r3, r31
/* 8012C8A0 00129800  80 8D F6 40 */	lwz r4, TEKI_OPTION_ORGANIC__5BTeki@sda21(r13)
/* 8012C8A4 00129804  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012C8A8 00129808  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 8012C8AC 0012980C  7D 88 03 A6 */	mtlr r12
/* 8012C8B0 00129810  4E 80 00 21 */	blrl 
/* 8012C8B4 00129814  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 8012C8B8 00129818  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 8012C8BC 0012981C  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 8012C8C0 00129820  38 21 00 48 */	addi r1, r1, 0x48
/* 8012C8C4 00129824  7C 08 03 A6 */	mtlr r0
/* 8012C8C8 00129828  4E 80 00 20 */	blr 

.global draw__17TaiCollecStrategyFR4TekiR8Graphics
draw__17TaiCollecStrategyFR4TekiR8Graphics:
/* 8012C8CC 0012982C  7C 08 02 A6 */	mflr r0
/* 8012C8D0 00129830  90 01 00 04 */	stw r0, 4(r1)
/* 8012C8D4 00129834  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8012C8D8 00129838  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8012C8DC 0012983C  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8012C8E0 00129840  7C 9E 23 78 */	mr r30, r4
/* 8012C8E4 00129844  48 02 08 E1 */	bl draw__12TekiStrategyFR4TekiR8Graphics
/* 8012C8E8 00129848  80 7E 03 D8 */	lwz r3, 0x3d8(r30)
/* 8012C8EC 0012984C  80 03 00 00 */	lwz r0, 0(r3)
/* 8012C8F0 00129850  28 00 00 00 */	cmplwi r0, 0
/* 8012C8F4 00129854  41 82 00 D0 */	beq lbl_8012C9C4
/* 8012C8F8 00129858  38 BE 00 94 */	addi r5, r30, 0x94
/* 8012C8FC 0012985C  38 7E 00 00 */	addi r3, r30, 0
/* 8012C900 00129860  38 80 00 03 */	li r4, 3
/* 8012C904 00129864  48 01 D1 3D */	bl setParticleGeneratorPosition__5BTekiFiR8Vector3f
/* 8012C908 00129868  7F C3 F3 78 */	mr r3, r30
/* 8012C90C 0012986C  48 01 D0 29 */	bl getPositionMapCode__5BTekiFv
/* 8012C910 00129870  2C 03 00 05 */	cmpwi r3, 5
/* 8012C914 00129874  40 82 00 24 */	bne lbl_8012C938
/* 8012C918 00129878  80 7E 03 D8 */	lwz r3, 0x3d8(r30)
/* 8012C91C 0012987C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8012C920 00129880  28 03 00 00 */	cmplwi r3, 0
/* 8012C924 00129884  41 82 00 30 */	beq lbl_8012C954
/* 8012C928 00129888  80 03 00 80 */	lwz r0, 0x80(r3)
/* 8012C92C 0012988C  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 8012C930 00129890  90 03 00 80 */	stw r0, 0x80(r3)
/* 8012C934 00129894  48 00 00 20 */	b lbl_8012C954
lbl_8012C938:
/* 8012C938 00129898  80 7E 03 D8 */	lwz r3, 0x3d8(r30)
/* 8012C93C 0012989C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8012C940 001298A0  28 03 00 00 */	cmplwi r3, 0
/* 8012C944 001298A4  41 82 00 10 */	beq lbl_8012C954
/* 8012C948 001298A8  80 03 00 80 */	lwz r0, 0x80(r3)
/* 8012C94C 001298AC  60 00 00 10 */	ori r0, r0, 0x10
/* 8012C950 001298B0  90 03 00 80 */	stw r0, 0x80(r3)
lbl_8012C954:
/* 8012C954 001298B4  80 7E 04 20 */	lwz r3, 0x420(r30)
/* 8012C958 001298B8  28 03 00 00 */	cmplwi r3, 0
/* 8012C95C 001298BC  41 82 00 68 */	beq lbl_8012C9C4
/* 8012C960 001298C0  3B E3 00 94 */	addi r31, r3, 0x94
/* 8012C964 001298C4  38 7E 00 00 */	addi r3, r30, 0
/* 8012C968 001298C8  38 BF 00 00 */	addi r5, r31, 0
/* 8012C96C 001298CC  38 80 00 02 */	li r4, 2
/* 8012C970 001298D0  48 01 D0 D1 */	bl setParticleGeneratorPosition__5BTekiFiR8Vector3f
/* 8012C974 001298D4  38 7E 00 00 */	addi r3, r30, 0
/* 8012C978 001298D8  38 9F 00 00 */	addi r4, r31, 0
/* 8012C97C 001298DC  48 01 CF 75 */	bl getPositionMapCode__5BTekiFR8Vector3f
/* 8012C980 001298E0  2C 03 00 05 */	cmpwi r3, 5
/* 8012C984 001298E4  40 82 00 24 */	bne lbl_8012C9A8
/* 8012C988 001298E8  80 7E 03 D8 */	lwz r3, 0x3d8(r30)
/* 8012C98C 001298EC  80 63 00 08 */	lwz r3, 8(r3)
/* 8012C990 001298F0  28 03 00 00 */	cmplwi r3, 0
/* 8012C994 001298F4  41 82 00 30 */	beq lbl_8012C9C4
/* 8012C998 001298F8  80 03 00 80 */	lwz r0, 0x80(r3)
/* 8012C99C 001298FC  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 8012C9A0 00129900  90 03 00 80 */	stw r0, 0x80(r3)
/* 8012C9A4 00129904  48 00 00 20 */	b lbl_8012C9C4
lbl_8012C9A8:
/* 8012C9A8 00129908  80 7E 03 D8 */	lwz r3, 0x3d8(r30)
/* 8012C9AC 0012990C  80 63 00 08 */	lwz r3, 8(r3)
/* 8012C9B0 00129910  28 03 00 00 */	cmplwi r3, 0
/* 8012C9B4 00129914  41 82 00 10 */	beq lbl_8012C9C4
/* 8012C9B8 00129918  80 03 00 80 */	lwz r0, 0x80(r3)
/* 8012C9BC 0012991C  60 00 00 10 */	ori r0, r0, 0x10
/* 8012C9C0 00129920  90 03 00 80 */	stw r0, 0x80(r3)
lbl_8012C9C4:
/* 8012C9C4 00129924  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8012C9C8 00129928  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8012C9CC 0012992C  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8012C9D0 00129930  38 21 00 30 */	addi r1, r1, 0x30
/* 8012C9D4 00129934  7C 08 03 A6 */	mtlr r0
/* 8012C9D8 00129938  4E 80 00 20 */	blr 

.global satisfy__31TekiCollecTargetPelletConditionFP8Creature
satisfy__31TekiCollecTargetPelletConditionFP8Creature:
/* 8012C9DC 0012993C  7C 08 02 A6 */	mflr r0
/* 8012C9E0 00129940  90 01 00 04 */	stw r0, 4(r1)
/* 8012C9E4 00129944  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 8012C9E8 00129948  93 E1 00 6C */	stw r31, 0x6c(r1)
/* 8012C9EC 0012994C  93 C1 00 68 */	stw r30, 0x68(r1)
/* 8012C9F0 00129950  3B C3 00 00 */	addi r30, r3, 0
/* 8012C9F4 00129954  93 A1 00 64 */	stw r29, 0x64(r1)
/* 8012C9F8 00129958  93 81 00 60 */	stw r28, 0x60(r1)
/* 8012C9FC 0012995C  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 8012CA00 00129960  2C 00 00 34 */	cmpwi r0, 0x34

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x726f7065
	.4byte 0x4974656d
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x726f7065
	.4byte 0x4974656d
	.4byte 0
	.4byte 0x526f7065
	.4byte 0x4974656d
	.4byte 0
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
	.4byte 0x803e1a08
	.4byte 0x8
	.4byte 0x803e1a10
	.4byte 0
	.4byte 0
	.4byte 0x526f7065
	.4byte 0x43726561
	.4byte 0x74757265
	.4byte 0
	.4byte 0x803e1a08
	.4byte 0x8
	.4byte 0x803e1a10
	.4byte 0
	.4byte 0x803e1a18
	.4byte 0
	.4byte 0
	.4byte 0x803e1a08
	.4byte 0x8
	.4byte 0x803e1a10
	.4byte 0
	.4byte 0x803e1a18
	.4byte 0
	.4byte 0x803e1a20
	.4byte 0
	.4byte 0
.global __vt__8RopeItem
__vt__8RopeItem:
	.4byte __RTTI__8RopeItem
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8RopeItemFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8RopeItemFi
	.4byte getiMass__8RopeItemFv
	.4byte getSize__8RopeItemFv
	.4byte getHeight__8CreatureFv
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
	.4byte isVisible__8RopeItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8RopeItemFv
	.4byte isAlive__8RopeItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8RopeItemFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
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
	.4byte update__12RopeCreatureFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12RopeCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__8CreatureFv
	.4byte doAnimation__8CreatureFv
	.4byte doKill__8RopeItemFv
	.4byte exitCourse__8CreatureFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x802BD0E8
	.4byte 0x802BD0F4
	.4byte 0x802BD108
	.4byte 0x802BD114
	.4byte 0x802BD138
	.4byte 0x802BD148
.global __RTTI__8DoorItem
__RTTI__8DoorItem:
	.4byte 0x802bd0ac
	.4byte 0x802bd174
	.4byte 0x4b657949
	.4byte 0x74656d00
