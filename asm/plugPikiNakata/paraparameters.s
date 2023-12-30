.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn read__15ParaParametersIFR6Stream, global
/* 801215A4 0011E504  7C 08 02 A6 */	mflr r0
/* 801215A8 0011E508  90 01 00 04 */	stw r0, 4(r1)
/* 801215AC 0011E50C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801215B0 0011E510  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801215B4 0011E514  3B E0 00 00 */	li r31, 0
/* 801215B8 0011E518  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801215BC 0011E51C  3B C0 00 00 */	li r30, 0
/* 801215C0 0011E520  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801215C4 0011E524  3B A4 00 00 */	addi r29, r4, 0
/* 801215C8 0011E528  93 81 00 10 */	stw r28, 0x10(r1)
/* 801215CC 0011E52C  3B 83 00 00 */	addi r28, r3, 0
/* 801215D0 0011E530  48 00 00 28 */	b .L_801215F8
.L_801215D4:
/* 801215D4 0011E534  7F A3 EB 78 */	mr r3, r29
/* 801215D8 0011E538  81 9D 00 04 */	lwz r12, 4(r29)
/* 801215DC 0011E53C  81 8C 00 08 */	lwz r12, 8(r12)
/* 801215E0 0011E540  7D 88 03 A6 */	mtlr r12
/* 801215E4 0011E544  4E 80 00 21 */	blrl 
/* 801215E8 0011E548  80 9C 00 00 */	lwz r4, 0(r28)
/* 801215EC 0011E54C  3B DE 00 01 */	addi r30, r30, 1
/* 801215F0 0011E550  7C 64 F9 2E */	stwx r3, r4, r31
/* 801215F4 0011E554  3B FF 00 04 */	addi r31, r31, 4
.L_801215F8:
/* 801215F8 0011E558  80 1C 00 04 */	lwz r0, 4(r28)
/* 801215FC 0011E55C  7C 1E 00 00 */	cmpw r30, r0
/* 80121600 0011E560  41 80 FF D4 */	blt .L_801215D4
/* 80121604 0011E564  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80121608 0011E568  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8012160C 0011E56C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80121610 0011E570  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80121614 0011E574  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80121618 0011E578  38 21 00 20 */	addi r1, r1, 0x20
/* 8012161C 0011E57C  7C 08 03 A6 */	mtlr r0
/* 80121620 0011E580  4E 80 00 20 */	blr 
.endfn read__15ParaParametersIFR6Stream

.fn write__15ParaParametersIFR6Stream, global
/* 80121624 0011E584  7C 08 02 A6 */	mflr r0
/* 80121628 0011E588  90 01 00 04 */	stw r0, 4(r1)
/* 8012162C 0011E58C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80121630 0011E590  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80121634 0011E594  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80121638 0011E598  3B C0 00 00 */	li r30, 0
/* 8012163C 0011E59C  57 DF 10 3A */	slwi r31, r30, 2
/* 80121640 0011E5A0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80121644 0011E5A4  3B A4 00 00 */	addi r29, r4, 0
/* 80121648 0011E5A8  93 81 00 10 */	stw r28, 0x10(r1)
/* 8012164C 0011E5AC  3B 83 00 00 */	addi r28, r3, 0
/* 80121650 0011E5B0  48 00 00 28 */	b .L_80121678
.L_80121654:
/* 80121654 0011E5B4  7F A3 EB 78 */	mr r3, r29
/* 80121658 0011E5B8  80 9C 00 00 */	lwz r4, 0(r28)
/* 8012165C 0011E5BC  81 9D 00 04 */	lwz r12, 4(r29)
/* 80121660 0011E5C0  7C 84 F8 2E */	lwzx r4, r4, r31
/* 80121664 0011E5C4  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80121668 0011E5C8  7D 88 03 A6 */	mtlr r12
/* 8012166C 0011E5CC  4E 80 00 21 */	blrl 
/* 80121670 0011E5D0  3B FF 00 04 */	addi r31, r31, 4
/* 80121674 0011E5D4  3B DE 00 01 */	addi r30, r30, 1
.L_80121678:
/* 80121678 0011E5D8  80 1C 00 04 */	lwz r0, 4(r28)
/* 8012167C 0011E5DC  7C 1E 00 00 */	cmpw r30, r0
/* 80121680 0011E5E0  41 80 FF D4 */	blt .L_80121654
/* 80121684 0011E5E4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80121688 0011E5E8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8012168C 0011E5EC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80121690 0011E5F0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80121694 0011E5F4  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80121698 0011E5F8  38 21 00 20 */	addi r1, r1, 0x20
/* 8012169C 0011E5FC  7C 08 03 A6 */	mtlr r0
/* 801216A0 0011E600  4E 80 00 20 */	blr 
.endfn write__15ParaParametersIFR6Stream

.fn print__15ParaParametersIFv, global
/* 801216A4 0011E604  80 A3 00 04 */	lwz r5, 4(r3)
/* 801216A8 0011E608  38 C0 00 00 */	li r6, 0
/* 801216AC 0011E60C  2C 05 00 00 */	cmpwi r5, 0
/* 801216B0 0011E610  4C 81 00 20 */	blelr 
/* 801216B4 0011E614  2C 05 00 08 */	cmpwi r5, 8
/* 801216B8 0011E618  38 85 FF F8 */	addi r4, r5, -8
/* 801216BC 0011E61C  40 81 00 20 */	ble .L_801216DC
/* 801216C0 0011E620  38 04 00 07 */	addi r0, r4, 7
/* 801216C4 0011E624  54 00 E8 FE */	srwi r0, r0, 3
/* 801216C8 0011E628  2C 04 00 00 */	cmpwi r4, 0
/* 801216CC 0011E62C  7C 09 03 A6 */	mtctr r0
/* 801216D0 0011E630  40 81 00 0C */	ble .L_801216DC
.L_801216D4:
/* 801216D4 0011E634  38 C6 00 08 */	addi r6, r6, 8
/* 801216D8 0011E638  42 00 FF FC */	bdnz .L_801216D4
.L_801216DC:
/* 801216DC 0011E63C  7C 06 28 50 */	subf r0, r6, r5
/* 801216E0 0011E640  7C 06 28 00 */	cmpw r6, r5
/* 801216E4 0011E644  7C 09 03 A6 */	mtctr r0
/* 801216E8 0011E648  4C 80 00 20 */	bgelr 
.L_801216EC:
/* 801216EC 0011E64C  42 00 00 00 */	bdnz .L_801216EC
/* 801216F0 0011E650  4E 80 00 20 */	blr 
/* 801216F4 0011E654  4B FF FF E8 */	b .L_801216DC
/* 801216F8 0011E658  4E 80 00 20 */	blr 
.endfn print__15ParaParametersIFv

.fn read__15ParaParametersFFR6Stream, global
/* 801216FC 0011E65C  7C 08 02 A6 */	mflr r0
/* 80121700 0011E660  90 01 00 04 */	stw r0, 4(r1)
/* 80121704 0011E664  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80121708 0011E668  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8012170C 0011E66C  3B E0 00 00 */	li r31, 0
/* 80121710 0011E670  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80121714 0011E674  3B C0 00 00 */	li r30, 0
/* 80121718 0011E678  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8012171C 0011E67C  3B A4 00 00 */	addi r29, r4, 0
/* 80121720 0011E680  93 81 00 10 */	stw r28, 0x10(r1)
/* 80121724 0011E684  3B 83 00 00 */	addi r28, r3, 0
/* 80121728 0011E688  48 00 00 28 */	b .L_80121750
.L_8012172C:
/* 8012172C 0011E68C  7F A3 EB 78 */	mr r3, r29
/* 80121730 0011E690  81 9D 00 04 */	lwz r12, 4(r29)
/* 80121734 0011E694  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80121738 0011E698  7D 88 03 A6 */	mtlr r12
/* 8012173C 0011E69C  4E 80 00 21 */	blrl 
/* 80121740 0011E6A0  80 7C 00 00 */	lwz r3, 0(r28)
/* 80121744 0011E6A4  3B DE 00 01 */	addi r30, r30, 1
/* 80121748 0011E6A8  7C 23 FD 2E */	stfsx f1, r3, r31
/* 8012174C 0011E6AC  3B FF 00 04 */	addi r31, r31, 4
.L_80121750:
/* 80121750 0011E6B0  80 1C 00 04 */	lwz r0, 4(r28)
/* 80121754 0011E6B4  7C 1E 00 00 */	cmpw r30, r0
/* 80121758 0011E6B8  41 80 FF D4 */	blt .L_8012172C
/* 8012175C 0011E6BC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80121760 0011E6C0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80121764 0011E6C4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80121768 0011E6C8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8012176C 0011E6CC  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80121770 0011E6D0  38 21 00 20 */	addi r1, r1, 0x20
/* 80121774 0011E6D4  7C 08 03 A6 */	mtlr r0
/* 80121778 0011E6D8  4E 80 00 20 */	blr 
.endfn read__15ParaParametersFFR6Stream

.fn write__15ParaParametersFFR6Stream, global
/* 8012177C 0011E6DC  7C 08 02 A6 */	mflr r0
/* 80121780 0011E6E0  90 01 00 04 */	stw r0, 4(r1)
/* 80121784 0011E6E4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80121788 0011E6E8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8012178C 0011E6EC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80121790 0011E6F0  3B C0 00 00 */	li r30, 0
/* 80121794 0011E6F4  57 DF 10 3A */	slwi r31, r30, 2
/* 80121798 0011E6F8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8012179C 0011E6FC  3B A4 00 00 */	addi r29, r4, 0
/* 801217A0 0011E700  93 81 00 10 */	stw r28, 0x10(r1)
/* 801217A4 0011E704  3B 83 00 00 */	addi r28, r3, 0
/* 801217A8 0011E708  48 00 00 28 */	b .L_801217D0
.L_801217AC:
/* 801217AC 0011E70C  7F A3 EB 78 */	mr r3, r29
/* 801217B0 0011E710  80 9C 00 00 */	lwz r4, 0(r28)
/* 801217B4 0011E714  81 9D 00 04 */	lwz r12, 4(r29)
/* 801217B8 0011E718  7C 24 FC 2E */	lfsx f1, r4, r31
/* 801217BC 0011E71C  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 801217C0 0011E720  7D 88 03 A6 */	mtlr r12
/* 801217C4 0011E724  4E 80 00 21 */	blrl 
/* 801217C8 0011E728  3B FF 00 04 */	addi r31, r31, 4
/* 801217CC 0011E72C  3B DE 00 01 */	addi r30, r30, 1
.L_801217D0:
/* 801217D0 0011E730  80 1C 00 04 */	lwz r0, 4(r28)
/* 801217D4 0011E734  7C 1E 00 00 */	cmpw r30, r0
/* 801217D8 0011E738  41 80 FF D4 */	blt .L_801217AC
/* 801217DC 0011E73C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801217E0 0011E740  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801217E4 0011E744  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801217E8 0011E748  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801217EC 0011E74C  83 81 00 10 */	lwz r28, 0x10(r1)
/* 801217F0 0011E750  38 21 00 20 */	addi r1, r1, 0x20
/* 801217F4 0011E754  7C 08 03 A6 */	mtlr r0
/* 801217F8 0011E758  4E 80 00 20 */	blr 
.endfn write__15ParaParametersFFR6Stream

.fn print__15ParaParametersFFv, global
/* 801217FC 0011E75C  80 A3 00 04 */	lwz r5, 4(r3)
/* 80121800 0011E760  38 C0 00 00 */	li r6, 0
/* 80121804 0011E764  2C 05 00 00 */	cmpwi r5, 0
/* 80121808 0011E768  4C 81 00 20 */	blelr 
/* 8012180C 0011E76C  2C 05 00 08 */	cmpwi r5, 8
/* 80121810 0011E770  38 85 FF F8 */	addi r4, r5, -8
/* 80121814 0011E774  40 81 00 20 */	ble .L_80121834
/* 80121818 0011E778  38 04 00 07 */	addi r0, r4, 7
/* 8012181C 0011E77C  54 00 E8 FE */	srwi r0, r0, 3
/* 80121820 0011E780  2C 04 00 00 */	cmpwi r4, 0
/* 80121824 0011E784  7C 09 03 A6 */	mtctr r0
/* 80121828 0011E788  40 81 00 0C */	ble .L_80121834
.L_8012182C:
/* 8012182C 0011E78C  38 C6 00 08 */	addi r6, r6, 8
/* 80121830 0011E790  42 00 FF FC */	bdnz .L_8012182C
.L_80121834:
/* 80121834 0011E794  7C 06 28 50 */	subf r0, r6, r5
/* 80121838 0011E798  7C 06 28 00 */	cmpw r6, r5
/* 8012183C 0011E79C  7C 09 03 A6 */	mtctr r0
/* 80121840 0011E7A0  4C 80 00 20 */	bgelr 
.L_80121844:
/* 80121844 0011E7A4  42 00 00 00 */	bdnz .L_80121844
/* 80121848 0011E7A8  4E 80 00 20 */	blr 
/* 8012184C 0011E7AC  4B FF FF E8 */	b .L_80121834
/* 80121850 0011E7B0  4E 80 00 20 */	blr 
.endfn print__15ParaParametersFFv

.fn __ct__19ParaMultiParametersFiP18ParaParameterInfoIiP18ParaParameterInfoF, global
/* 80121854 0011E7B4  7C 08 02 A6 */	mflr r0
/* 80121858 0011E7B8  3D 00 80 2C */	lis r8, __vt__19ParaMultiParameters@ha
/* 8012185C 0011E7BC  90 01 00 04 */	stw r0, 4(r1)
/* 80121860 0011E7C0  38 08 50 B0 */	addi r0, r8, __vt__19ParaMultiParameters@l
/* 80121864 0011E7C4  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 80121868 0011E7C8  BF 41 00 20 */	stmw r26, 0x20(r1)
/* 8012186C 0011E7CC  3B 43 00 00 */	addi r26, r3, 0
/* 80121870 0011E7D0  3B 64 00 00 */	addi r27, r4, 0
/* 80121874 0011E7D4  3B 85 00 00 */	addi r28, r5, 0
/* 80121878 0011E7D8  3B A6 00 00 */	addi r29, r6, 0
/* 8012187C 0011E7DC  3B C7 00 00 */	addi r30, r7, 0
/* 80121880 0011E7E0  90 03 00 08 */	stw r0, 8(r3)
/* 80121884 0011E7E4  38 60 00 10 */	li r3, 0x10
/* 80121888 0011E7E8  4B F2 57 7D */	bl alloc__6SystemFUl
/* 8012188C 0011E7EC  3B E3 00 00 */	addi r31, r3, 0
/* 80121890 0011E7F0  7F E3 FB 79 */	or. r3, r31, r31
/* 80121894 0011E7F4  41 82 00 1C */	beq .L_801218B0
/* 80121898 0011E7F8  38 9B 00 00 */	addi r4, r27, 0
/* 8012189C 0011E7FC  38 BC 00 00 */	addi r5, r28, 0
/* 801218A0 0011E800  48 00 00 ED */	bl "__ct__17ParaParameters<i>FiP20ParaParameterInfo<i>"
/* 801218A4 0011E804  3C 60 80 2C */	lis r3, __vt__15ParaParametersI@ha
/* 801218A8 0011E808  38 03 51 50 */	addi r0, r3, __vt__15ParaParametersI@l
/* 801218AC 0011E80C  90 1F 00 0C */	stw r0, 0xc(r31)
.L_801218B0:
/* 801218B0 0011E810  93 FA 00 00 */	stw r31, 0(r26)
/* 801218B4 0011E814  38 60 00 10 */	li r3, 0x10
/* 801218B8 0011E818  4B F2 57 4D */	bl alloc__6SystemFUl
/* 801218BC 0011E81C  3B E3 00 00 */	addi r31, r3, 0
/* 801218C0 0011E820  7F E3 FB 79 */	or. r3, r31, r31
/* 801218C4 0011E824  41 82 00 1C */	beq .L_801218E0
/* 801218C8 0011E828  38 9D 00 00 */	addi r4, r29, 0
/* 801218CC 0011E82C  38 BE 00 00 */	addi r5, r30, 0
/* 801218D0 0011E830  48 00 00 2D */	bl "__ct__17ParaParameters<f>FiP20ParaParameterInfo<f>"
/* 801218D4 0011E834  3C 60 80 2C */	lis r3, __vt__15ParaParametersF@ha
/* 801218D8 0011E838  38 03 50 F8 */	addi r0, r3, __vt__15ParaParametersF@l
/* 801218DC 0011E83C  90 1F 00 0C */	stw r0, 0xc(r31)
.L_801218E0:
/* 801218E0 0011E840  93 FA 00 04 */	stw r31, 4(r26)
/* 801218E4 0011E844  7F 43 D3 78 */	mr r3, r26
/* 801218E8 0011E848  BB 41 00 20 */	lmw r26, 0x20(r1)
/* 801218EC 0011E84C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 801218F0 0011E850  38 21 00 38 */	addi r1, r1, 0x38
/* 801218F4 0011E854  7C 08 03 A6 */	mtlr r0
/* 801218F8 0011E858  4E 80 00 20 */	blr 
.endfn __ct__19ParaMultiParametersFiP18ParaParameterInfoIiP18ParaParameterInfoF

.fn "__ct__17ParaParameters<f>FiP20ParaParameterInfo<f>", weak
/* 801218FC 0011E85C  7C 08 02 A6 */	mflr r0
/* 80121900 0011E860  3C C0 80 2C */	lis r6, "__vt__17ParaParameters<f>"@ha
/* 80121904 0011E864  90 01 00 04 */	stw r0, 4(r1)
/* 80121908 0011E868  38 06 51 0C */	addi r0, r6, "__vt__17ParaParameters<f>"@l
/* 8012190C 0011E86C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80121910 0011E870  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80121914 0011E874  3B E3 00 00 */	addi r31, r3, 0
/* 80121918 0011E878  90 03 00 0C */	stw r0, 0xc(r3)
/* 8012191C 0011E87C  90 83 00 04 */	stw r4, 4(r3)
/* 80121920 0011E880  90 A3 00 08 */	stw r5, 8(r3)
/* 80121924 0011E884  80 03 00 04 */	lwz r0, 4(r3)
/* 80121928 0011E888  2C 00 00 00 */	cmpwi r0, 0
/* 8012192C 0011E88C  40 81 00 14 */	ble .L_80121940
/* 80121930 0011E890  54 03 10 3A */	slwi r3, r0, 2
/* 80121934 0011E894  4B F2 56 D1 */	bl alloc__6SystemFUl
/* 80121938 0011E898  90 7F 00 00 */	stw r3, 0(r31)
/* 8012193C 0011E89C  48 00 00 0C */	b .L_80121948
.L_80121940:
/* 80121940 0011E8A0  38 00 00 00 */	li r0, 0
/* 80121944 0011E8A4  90 1F 00 00 */	stw r0, 0(r31)
.L_80121948:
/* 80121948 0011E8A8  C0 02 A0 B8 */	lfs f0, lbl_803EA2B8@sda21(r2)
/* 8012194C 0011E8AC  38 A0 00 00 */	li r5, 0
/* 80121950 0011E8B0  38 80 00 00 */	li r4, 0
/* 80121954 0011E8B4  48 00 00 14 */	b .L_80121968
.L_80121958:
/* 80121958 0011E8B8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8012195C 0011E8BC  38 A5 00 01 */	addi r5, r5, 1
/* 80121960 0011E8C0  7C 03 25 2E */	stfsx f0, r3, r4
/* 80121964 0011E8C4  38 84 00 04 */	addi r4, r4, 4
.L_80121968:
/* 80121968 0011E8C8  80 1F 00 04 */	lwz r0, 4(r31)
/* 8012196C 0011E8CC  7C 05 00 00 */	cmpw r5, r0
/* 80121970 0011E8D0  41 80 FF E8 */	blt .L_80121958
/* 80121974 0011E8D4  7F E3 FB 78 */	mr r3, r31
/* 80121978 0011E8D8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8012197C 0011E8DC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80121980 0011E8E0  38 21 00 20 */	addi r1, r1, 0x20
/* 80121984 0011E8E4  7C 08 03 A6 */	mtlr r0
/* 80121988 0011E8E8  4E 80 00 20 */	blr 
.endfn "__ct__17ParaParameters<f>FiP20ParaParameterInfo<f>"

.fn "__ct__17ParaParameters<i>FiP20ParaParameterInfo<i>", weak
/* 8012198C 0011E8EC  7C 08 02 A6 */	mflr r0
/* 80121990 0011E8F0  3C C0 80 2C */	lis r6, "__vt__17ParaParameters<i>"@ha
/* 80121994 0011E8F4  90 01 00 04 */	stw r0, 4(r1)
/* 80121998 0011E8F8  38 06 51 64 */	addi r0, r6, "__vt__17ParaParameters<i>"@l
/* 8012199C 0011E8FC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801219A0 0011E900  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801219A4 0011E904  3B E3 00 00 */	addi r31, r3, 0
/* 801219A8 0011E908  90 03 00 0C */	stw r0, 0xc(r3)
/* 801219AC 0011E90C  90 83 00 04 */	stw r4, 4(r3)
/* 801219B0 0011E910  90 A3 00 08 */	stw r5, 8(r3)
/* 801219B4 0011E914  80 03 00 04 */	lwz r0, 4(r3)
/* 801219B8 0011E918  2C 00 00 00 */	cmpwi r0, 0
/* 801219BC 0011E91C  40 81 00 14 */	ble .L_801219D0
/* 801219C0 0011E920  54 03 10 3A */	slwi r3, r0, 2
/* 801219C4 0011E924  4B F2 56 41 */	bl alloc__6SystemFUl
/* 801219C8 0011E928  90 7F 00 00 */	stw r3, 0(r31)
/* 801219CC 0011E92C  48 00 00 0C */	b .L_801219D8
.L_801219D0:
/* 801219D0 0011E930  38 00 00 00 */	li r0, 0
/* 801219D4 0011E934  90 1F 00 00 */	stw r0, 0(r31)
.L_801219D8:
/* 801219D8 0011E938  38 A0 00 00 */	li r5, 0
/* 801219DC 0011E93C  38 85 00 00 */	addi r4, r5, 0
/* 801219E0 0011E940  38 C0 00 00 */	li r6, 0
/* 801219E4 0011E944  48 00 00 14 */	b .L_801219F8
.L_801219E8:
/* 801219E8 0011E948  80 7F 00 00 */	lwz r3, 0(r31)
/* 801219EC 0011E94C  38 C6 00 01 */	addi r6, r6, 1
/* 801219F0 0011E950  7C 83 29 2E */	stwx r4, r3, r5
/* 801219F4 0011E954  38 A5 00 04 */	addi r5, r5, 4
.L_801219F8:
/* 801219F8 0011E958  80 1F 00 04 */	lwz r0, 4(r31)
/* 801219FC 0011E95C  7C 06 00 00 */	cmpw r6, r0
/* 80121A00 0011E960  41 80 FF E8 */	blt .L_801219E8
/* 80121A04 0011E964  7F E3 FB 78 */	mr r3, r31
/* 80121A08 0011E968  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80121A0C 0011E96C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80121A10 0011E970  38 21 00 20 */	addi r1, r1, 0x20
/* 80121A14 0011E974  7C 08 03 A6 */	mtlr r0
/* 80121A18 0011E978  4E 80 00 20 */	blr 
.endfn "__ct__17ParaParameters<i>FiP20ParaParameterInfo<i>"

.fn input__19ParaMultiParametersFR19ParaMultiParameters, global
/* 80121A1C 0011E97C  38 E0 00 00 */	li r7, 0
/* 80121A20 0011E980  81 24 00 00 */	lwz r9, 0(r4)
/* 80121A24 0011E984  81 03 00 00 */	lwz r8, 0(r3)
/* 80121A28 0011E988  7C EA 3B 78 */	mr r10, r7
/* 80121A2C 0011E98C  48 00 00 1C */	b .L_80121A48
.L_80121A30:
/* 80121A30 0011E990  80 C9 00 00 */	lwz r6, 0(r9)
/* 80121A34 0011E994  38 E7 00 01 */	addi r7, r7, 1
/* 80121A38 0011E998  80 A8 00 00 */	lwz r5, 0(r8)
/* 80121A3C 0011E99C  7C 06 50 2E */	lwzx r0, r6, r10
/* 80121A40 0011E9A0  7C 05 51 2E */	stwx r0, r5, r10
/* 80121A44 0011E9A4  39 4A 00 04 */	addi r10, r10, 4
.L_80121A48:
/* 80121A48 0011E9A8  80 08 00 04 */	lwz r0, 4(r8)
/* 80121A4C 0011E9AC  7C 07 00 00 */	cmpw r7, r0
/* 80121A50 0011E9B0  41 80 FF E0 */	blt .L_80121A30
/* 80121A54 0011E9B4  38 A0 00 00 */	li r5, 0
/* 80121A58 0011E9B8  80 E4 00 04 */	lwz r7, 4(r4)
/* 80121A5C 0011E9BC  80 C3 00 04 */	lwz r6, 4(r3)
/* 80121A60 0011E9C0  7C A8 2B 78 */	mr r8, r5
/* 80121A64 0011E9C4  48 00 00 1C */	b .L_80121A80
.L_80121A68:
/* 80121A68 0011E9C8  80 87 00 00 */	lwz r4, 0(r7)
/* 80121A6C 0011E9CC  38 A5 00 01 */	addi r5, r5, 1
/* 80121A70 0011E9D0  80 66 00 00 */	lwz r3, 0(r6)
/* 80121A74 0011E9D4  7C 04 44 2E */	lfsx f0, r4, r8
/* 80121A78 0011E9D8  7C 03 45 2E */	stfsx f0, r3, r8
/* 80121A7C 0011E9DC  39 08 00 04 */	addi r8, r8, 4
.L_80121A80:
/* 80121A80 0011E9E0  80 06 00 04 */	lwz r0, 4(r6)
/* 80121A84 0011E9E4  7C 05 00 00 */	cmpw r5, r0
/* 80121A88 0011E9E8  41 80 FF E0 */	blt .L_80121A68
/* 80121A8C 0011E9EC  4E 80 00 20 */	blr 
.endfn input__19ParaMultiParametersFR19ParaMultiParameters

.fn read__19ParaMultiParametersFR6Stream, global
/* 80121A90 0011E9F0  7C 08 02 A6 */	mflr r0
/* 80121A94 0011E9F4  90 01 00 04 */	stw r0, 4(r1)
/* 80121A98 0011E9F8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80121A9C 0011E9FC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80121AA0 0011EA00  7C 9F 23 78 */	mr r31, r4
/* 80121AA4 0011EA04  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80121AA8 0011EA08  7C 7E 1B 78 */	mr r30, r3
/* 80121AAC 0011EA0C  80 63 00 00 */	lwz r3, 0(r3)
/* 80121AB0 0011EA10  81 83 00 0C */	lwz r12, 0xc(r3)
/* 80121AB4 0011EA14  81 8C 00 08 */	lwz r12, 8(r12)
/* 80121AB8 0011EA18  7D 88 03 A6 */	mtlr r12
/* 80121ABC 0011EA1C  4E 80 00 21 */	blrl 
/* 80121AC0 0011EA20  80 7E 00 04 */	lwz r3, 4(r30)
/* 80121AC4 0011EA24  7F E4 FB 78 */	mr r4, r31
/* 80121AC8 0011EA28  81 83 00 0C */	lwz r12, 0xc(r3)
/* 80121ACC 0011EA2C  81 8C 00 08 */	lwz r12, 8(r12)
/* 80121AD0 0011EA30  7D 88 03 A6 */	mtlr r12
/* 80121AD4 0011EA34  4E 80 00 21 */	blrl 
/* 80121AD8 0011EA38  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80121ADC 0011EA3C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80121AE0 0011EA40  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80121AE4 0011EA44  38 21 00 18 */	addi r1, r1, 0x18
/* 80121AE8 0011EA48  7C 08 03 A6 */	mtlr r0
/* 80121AEC 0011EA4C  4E 80 00 20 */	blr 
.endfn read__19ParaMultiParametersFR6Stream

.fn write__19ParaMultiParametersFR6Stream, global
/* 80121AF0 0011EA50  7C 08 02 A6 */	mflr r0
/* 80121AF4 0011EA54  90 01 00 04 */	stw r0, 4(r1)
/* 80121AF8 0011EA58  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80121AFC 0011EA5C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80121B00 0011EA60  7C 9F 23 78 */	mr r31, r4
/* 80121B04 0011EA64  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80121B08 0011EA68  7C 7E 1B 78 */	mr r30, r3
/* 80121B0C 0011EA6C  80 63 00 00 */	lwz r3, 0(r3)
/* 80121B10 0011EA70  81 83 00 0C */	lwz r12, 0xc(r3)
/* 80121B14 0011EA74  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80121B18 0011EA78  7D 88 03 A6 */	mtlr r12
/* 80121B1C 0011EA7C  4E 80 00 21 */	blrl 
/* 80121B20 0011EA80  80 7E 00 04 */	lwz r3, 4(r30)
/* 80121B24 0011EA84  7F E4 FB 78 */	mr r4, r31
/* 80121B28 0011EA88  81 83 00 0C */	lwz r12, 0xc(r3)
/* 80121B2C 0011EA8C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80121B30 0011EA90  7D 88 03 A6 */	mtlr r12
/* 80121B34 0011EA94  4E 80 00 21 */	blrl 
/* 80121B38 0011EA98  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80121B3C 0011EA9C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80121B40 0011EAA0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80121B44 0011EAA4  38 21 00 18 */	addi r1, r1, 0x18
/* 80121B48 0011EAA8  7C 08 03 A6 */	mtlr r0
/* 80121B4C 0011EAAC  4E 80 00 20 */	blr 
.endfn write__19ParaMultiParametersFR6Stream

.fn print__19ParaMultiParametersFv, global
/* 80121B50 0011EAB0  7C 08 02 A6 */	mflr r0
/* 80121B54 0011EAB4  90 01 00 04 */	stw r0, 4(r1)
/* 80121B58 0011EAB8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80121B5C 0011EABC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80121B60 0011EAC0  7C 7F 1B 78 */	mr r31, r3
/* 80121B64 0011EAC4  80 63 00 00 */	lwz r3, 0(r3)
/* 80121B68 0011EAC8  81 83 00 0C */	lwz r12, 0xc(r3)
/* 80121B6C 0011EACC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80121B70 0011EAD0  7D 88 03 A6 */	mtlr r12
/* 80121B74 0011EAD4  4E 80 00 21 */	blrl 
/* 80121B78 0011EAD8  80 7F 00 04 */	lwz r3, 4(r31)
/* 80121B7C 0011EADC  81 83 00 0C */	lwz r12, 0xc(r3)
/* 80121B80 0011EAE0  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80121B84 0011EAE4  7D 88 03 A6 */	mtlr r12
/* 80121B88 0011EAE8  4E 80 00 21 */	blrl 
/* 80121B8C 0011EAEC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80121B90 0011EAF0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80121B94 0011EAF4  38 21 00 18 */	addi r1, r1, 0x18
/* 80121B98 0011EAF8  7C 08 03 A6 */	mtlr r0
/* 80121B9C 0011EAFC  4E 80 00 20 */	blr 
.endfn print__19ParaMultiParametersFv

.fn "read__17ParaParameters<f>FR6Stream", weak
/* 80121BA0 0011EB00  4E 80 00 20 */	blr 
.endfn "read__17ParaParameters<f>FR6Stream"

.fn "write__17ParaParameters<f>FR6Stream", weak
/* 80121BA4 0011EB04  4E 80 00 20 */	blr 
.endfn "write__17ParaParameters<f>FR6Stream"

.fn "print__17ParaParameters<f>Fv", weak
/* 80121BA8 0011EB08  4E 80 00 20 */	blr 
.endfn "print__17ParaParameters<f>Fv"

.fn "read__17ParaParameters<i>FR6Stream", weak
/* 80121BAC 0011EB0C  4E 80 00 20 */	blr 
.endfn "read__17ParaParameters<i>FR6Stream"

.fn "write__17ParaParameters<i>FR6Stream", weak
/* 80121BB0 0011EB10  4E 80 00 20 */	blr 
.endfn "write__17ParaParameters<i>FR6Stream"

.fn "print__17ParaParameters<i>Fv", weak
/* 80121BB4 0011EB14  4E 80 00 20 */	blr 
.endfn "print__17ParaParameters<i>Fv"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802C5078, local
	.asciz "paraparameters.cpp"
.endobj lbl_802C5078
.balign 4
.obj lbl_802C508C, local
	.asciz "paraparameters"
.endobj lbl_802C508C
.balign 4
.obj lbl_802C509C, local
	.asciz "ParaMultiParameters"
.endobj lbl_802C509C
.balign 4
.obj __vt__19ParaMultiParameters, global
	.4byte __RTTI__19ParaMultiParameters
	.4byte 0
	.4byte read__19ParaMultiParametersFR6Stream
	.4byte write__19ParaMultiParametersFR6Stream
	.4byte print__19ParaMultiParametersFv
.endobj __vt__19ParaMultiParameters
.balign 4
.obj lbl_802C50C4, local
	.asciz "ParaParametersF"
.endobj lbl_802C50C4
.balign 4
.obj lbl_802C50D4, local
	.asciz "ParaParameters<float>"
.endobj lbl_802C50D4
.balign 4
.obj lbl_802C50EC, local
	.4byte "__RTTI__17ParaParameters<f>"
	.4byte 0
	.4byte 0
.endobj lbl_802C50EC
.balign 4
.obj __vt__15ParaParametersF, global
	.4byte __RTTI__15ParaParametersF
	.4byte 0
	.4byte read__15ParaParametersFFR6Stream
	.4byte write__15ParaParametersFFR6Stream
	.4byte print__15ParaParametersFFv
.endobj __vt__15ParaParametersF
.balign 4
.obj "__vt__17ParaParameters<f>", weak
	.4byte "__RTTI__17ParaParameters<f>"
	.4byte 0
	.4byte "read__17ParaParameters<f>FR6Stream"
	.4byte "write__17ParaParameters<f>FR6Stream"
	.4byte "print__17ParaParameters<f>Fv"
.endobj "__vt__17ParaParameters<f>"
.balign 4
.obj lbl_802C5120, local
	.asciz "ParaParametersI"
.endobj lbl_802C5120
.balign 4
.obj lbl_802C5130, local
	.asciz "ParaParameters<int>"
.endobj lbl_802C5130
.balign 4
.obj lbl_802C5144, local
	.4byte "__RTTI__17ParaParameters<i>"
	.4byte 0
	.4byte 0
.endobj lbl_802C5144
.balign 4
.obj __vt__15ParaParametersI, global
	.4byte __RTTI__15ParaParametersI
	.4byte 0
	.4byte read__15ParaParametersIFR6Stream
	.4byte write__15ParaParametersIFR6Stream
	.4byte print__15ParaParametersIFv
.endobj __vt__15ParaParametersI
.balign 4
.obj "__vt__17ParaParameters<i>", weak
	.4byte "__RTTI__17ParaParameters<i>"
	.4byte 0
	.4byte "read__17ParaParameters<i>FR6Stream"
	.4byte "write__17ParaParameters<i>FR6Stream"
	.4byte "print__17ParaParameters<i>Fv"
.endobj "__vt__17ParaParameters<i>"

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__19ParaMultiParameters, local
	.4byte lbl_802C509C
	.4byte 0
.endobj __RTTI__19ParaMultiParameters
.balign 4
.obj "__RTTI__17ParaParameters<f>", local
	.4byte lbl_802C50D4
	.4byte 0
.endobj "__RTTI__17ParaParameters<f>"
.balign 4
.obj __RTTI__15ParaParametersF, local
	.4byte lbl_802C50C4
	.4byte lbl_802C50EC
.endobj __RTTI__15ParaParametersF
.balign 4
.obj "__RTTI__17ParaParameters<i>", local
	.4byte lbl_802C5130
	.4byte 0
.endobj "__RTTI__17ParaParameters<i>"
.balign 4
.obj __RTTI__15ParaParametersI, local
	.4byte lbl_802C5120
	.4byte lbl_802C5144
.endobj __RTTI__15ParaParametersI

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA2B8, local
	.float 0.0
.endobj lbl_803EA2B8
