.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global construct__19NPolynomialFunctionFPfi
construct__19NPolynomialFunctionFPfi:
/* 8011B6E4 00118644  7C 08 02 A6 */	mflr r0
/* 8011B6E8 00118648  38 63 00 04 */	addi r3, r3, 4
/* 8011B6EC 0011864C  90 01 00 04 */	stw r0, 4(r1)
/* 8011B6F0 00118650  38 A5 00 01 */	addi r5, r5, 1
/* 8011B6F4 00118654  94 21 FF F8 */	stwu r1, -8(r1)
/* 8011B6F8 00118658  48 00 16 D9 */	bl construct__7NVectorFPfi
/* 8011B6FC 0011865C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8011B700 00118660  38 21 00 08 */	addi r1, r1, 8
/* 8011B704 00118664  7C 08 03 A6 */	mtlr r0
/* 8011B708 00118668  4E 80 00 20 */	blr 

.global getValue__19NPolynomialFunctionFf
getValue__19NPolynomialFunctionFf:
/* 8011B70C 0011866C  80 C3 00 08 */	lwz r6, 8(r3)
/* 8011B710 00118670  38 E0 00 00 */	li r7, 0
/* 8011B714 00118674  C0 E2 A0 04 */	lfs f7, lbl_803EA204@sda21(r2)
/* 8011B718 00118678  2C 06 00 00 */	cmpwi r6, 0
/* 8011B71C 0011867C  C1 02 A0 00 */	lfs f8, lbl_803EA200@sda21(r2)
/* 8011B720 00118680  40 81 00 EC */	ble lbl_8011B80C
/* 8011B724 00118684  2C 06 00 08 */	cmpwi r6, 8
/* 8011B728 00118688  38 86 FF F8 */	addi r4, r6, -8
/* 8011B72C 0011868C  40 81 00 E8 */	ble lbl_8011B814
/* 8011B730 00118690  38 04 00 07 */	addi r0, r4, 7
/* 8011B734 00118694  54 00 E8 FE */	srwi r0, r0, 3
/* 8011B738 00118698  2C 04 00 00 */	cmpwi r4, 0
/* 8011B73C 0011869C  7C 09 03 A6 */	mtctr r0
/* 8011B740 001186A0  38 80 00 00 */	li r4, 0
/* 8011B744 001186A4  40 81 00 D0 */	ble lbl_8011B814
lbl_8011B748:
/* 8011B748 001186A8  80 03 00 04 */	lwz r0, 4(r3)
/* 8011B74C 001186AC  38 E7 00 08 */	addi r7, r7, 8
/* 8011B750 001186B0  7C A0 22 14 */	add r5, r0, r4
/* 8011B754 001186B4  C0 45 00 00 */	lfs f2, 0(r5)
/* 8011B758 001186B8  38 84 00 20 */	addi r4, r4, 0x20
/* 8011B75C 001186BC  C0 05 00 04 */	lfs f0, 4(r5)
/* 8011B760 001186C0  EC 47 00 B2 */	fmuls f2, f7, f2
/* 8011B764 001186C4  C0 C5 00 08 */	lfs f6, 8(r5)
/* 8011B768 001186C8  EC E7 00 72 */	fmuls f7, f7, f1
/* 8011B76C 001186CC  C0 A5 00 0C */	lfs f5, 0xc(r5)
/* 8011B770 001186D0  C0 85 00 10 */	lfs f4, 0x10(r5)
/* 8011B774 001186D4  EC 07 00 32 */	fmuls f0, f7, f0
/* 8011B778 001186D8  C0 65 00 14 */	lfs f3, 0x14(r5)
/* 8011B77C 001186DC  ED 08 10 2A */	fadds f8, f8, f2
/* 8011B780 001186E0  C0 45 00 18 */	lfs f2, 0x18(r5)
/* 8011B784 001186E4  EC E7 00 72 */	fmuls f7, f7, f1
/* 8011B788 001186E8  ED 08 00 2A */	fadds f8, f8, f0
/* 8011B78C 001186EC  C0 05 00 1C */	lfs f0, 0x1c(r5)
/* 8011B790 001186F0  EC C7 01 B2 */	fmuls f6, f7, f6
/* 8011B794 001186F4  EC E7 00 72 */	fmuls f7, f7, f1
/* 8011B798 001186F8  ED 08 30 2A */	fadds f8, f8, f6
/* 8011B79C 001186FC  EC A7 01 72 */	fmuls f5, f7, f5
/* 8011B7A0 00118700  EC E7 00 72 */	fmuls f7, f7, f1
/* 8011B7A4 00118704  ED 08 28 2A */	fadds f8, f8, f5
/* 8011B7A8 00118708  EC 87 01 32 */	fmuls f4, f7, f4
/* 8011B7AC 0011870C  EC E7 00 72 */	fmuls f7, f7, f1
/* 8011B7B0 00118710  ED 08 20 2A */	fadds f8, f8, f4
/* 8011B7B4 00118714  EC 67 00 F2 */	fmuls f3, f7, f3
/* 8011B7B8 00118718  EC E7 00 72 */	fmuls f7, f7, f1
/* 8011B7BC 0011871C  ED 08 18 2A */	fadds f8, f8, f3
/* 8011B7C0 00118720  EC 47 00 B2 */	fmuls f2, f7, f2
/* 8011B7C4 00118724  EC E7 00 72 */	fmuls f7, f7, f1
/* 8011B7C8 00118728  ED 08 10 2A */	fadds f8, f8, f2
/* 8011B7CC 0011872C  EC 07 00 32 */	fmuls f0, f7, f0
/* 8011B7D0 00118730  EC E7 00 72 */	fmuls f7, f7, f1
/* 8011B7D4 00118734  ED 08 00 2A */	fadds f8, f8, f0
/* 8011B7D8 00118738  42 00 FF 70 */	bdnz lbl_8011B748
/* 8011B7DC 0011873C  48 00 00 38 */	b lbl_8011B814
lbl_8011B7E0:
/* 8011B7E0 00118740  7C 07 30 50 */	subf r0, r7, r6
/* 8011B7E4 00118744  7C 07 30 00 */	cmpw r7, r6
/* 8011B7E8 00118748  7C 09 03 A6 */	mtctr r0
/* 8011B7EC 0011874C  40 80 00 20 */	bge lbl_8011B80C
lbl_8011B7F0:
/* 8011B7F0 00118750  80 83 00 04 */	lwz r4, 4(r3)
/* 8011B7F4 00118754  7C 04 2C 2E */	lfsx f0, r4, r5
/* 8011B7F8 00118758  38 A5 00 04 */	addi r5, r5, 4
/* 8011B7FC 0011875C  EC 07 00 32 */	fmuls f0, f7, f0
/* 8011B800 00118760  EC E7 00 72 */	fmuls f7, f7, f1
/* 8011B804 00118764  ED 08 00 2A */	fadds f8, f8, f0
/* 8011B808 00118768  42 00 FF E8 */	bdnz lbl_8011B7F0
lbl_8011B80C:
/* 8011B80C 0011876C  FC 20 40 90 */	fmr f1, f8
/* 8011B810 00118770  4E 80 00 20 */	blr 
lbl_8011B814:
/* 8011B814 00118774  54 E5 10 3A */	slwi r5, r7, 2
/* 8011B818 00118778  4B FF FF C8 */	b lbl_8011B7E0
/* 8011B81C 0011877C  4E 80 00 20 */	blr 

.global println__19NPolynomialFunctionFv
println__19NPolynomialFunctionFv:
/* 8011B820 00118780  80 A3 00 08 */	lwz r5, 8(r3)
/* 8011B824 00118784  38 C0 00 00 */	li r6, 0
/* 8011B828 00118788  2C 05 00 00 */	cmpwi r5, 0
/* 8011B82C 0011878C  4C 81 00 20 */	blelr 
/* 8011B830 00118790  2C 05 00 08 */	cmpwi r5, 8
/* 8011B834 00118794  38 85 FF F8 */	addi r4, r5, -8
/* 8011B838 00118798  40 81 00 20 */	ble lbl_8011B858
/* 8011B83C 0011879C  38 04 00 07 */	addi r0, r4, 7
/* 8011B840 001187A0  54 00 E8 FE */	srwi r0, r0, 3
/* 8011B844 001187A4  2C 04 00 00 */	cmpwi r4, 0
/* 8011B848 001187A8  7C 09 03 A6 */	mtctr r0
/* 8011B84C 001187AC  40 81 00 0C */	ble lbl_8011B858
lbl_8011B850:
/* 8011B850 001187B0  38 C6 00 08 */	addi r6, r6, 8
/* 8011B854 001187B4  42 00 FF FC */	bdnz lbl_8011B850
lbl_8011B858:
/* 8011B858 001187B8  7C 06 28 50 */	subf r0, r6, r5
/* 8011B85C 001187BC  7C 06 28 00 */	cmpw r6, r5
/* 8011B860 001187C0  7C 09 03 A6 */	mtctr r0
/* 8011B864 001187C4  4C 80 00 20 */	bgelr 
lbl_8011B868:
/* 8011B868 001187C8  42 00 00 00 */	bdnz lbl_8011B868
/* 8011B86C 001187CC  4E 80 00 20 */	blr 
/* 8011B870 001187D0  4B FF FF E8 */	b lbl_8011B858
/* 8011B874 001187D4  4E 80 00 20 */	blr 

.global __ct__20NClampLinearFunctionFPf
__ct__20NClampLinearFunctionFPf:
/* 8011B878 001187D8  7C 08 02 A6 */	mflr r0
/* 8011B87C 001187DC  3C A0 80 2C */	lis r5, __vt__9NFunction@ha
/* 8011B880 001187E0  90 01 00 04 */	stw r0, 4(r1)
/* 8011B884 001187E4  38 05 42 5C */	addi r0, r5, __vt__9NFunction@l
/* 8011B888 001187E8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011B88C 001187EC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011B890 001187F0  3B E4 00 00 */	addi r31, r4, 0
/* 8011B894 001187F4  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8011B898 001187F8  3B C3 00 00 */	addi r30, r3, 0
/* 8011B89C 001187FC  3C 60 80 2C */	lis r3, __vt__19NPolynomialFunction@ha
/* 8011B8A0 00118800  90 1E 00 00 */	stw r0, 0(r30)
/* 8011B8A4 00118804  38 03 42 4C */	addi r0, r3, __vt__19NPolynomialFunction@l
/* 8011B8A8 00118808  38 7E 00 04 */	addi r3, r30, 4
/* 8011B8AC 0011880C  90 1E 00 00 */	stw r0, 0(r30)
/* 8011B8B0 00118810  48 00 15 11 */	bl __ct__7NVectorFv
/* 8011B8B4 00118814  3C 60 80 2C */	lis r3, __vt__15NLinearFunction@ha
/* 8011B8B8 00118818  38 03 42 3C */	addi r0, r3, __vt__15NLinearFunction@l
/* 8011B8BC 0011881C  3C 60 80 2C */	lis r3, __vt__20NClampLinearFunction@ha
/* 8011B8C0 00118820  90 1E 00 00 */	stw r0, 0(r30)
/* 8011B8C4 00118824  38 03 42 2C */	addi r0, r3, __vt__20NClampLinearFunction@l
/* 8011B8C8 00118828  90 1E 00 00 */	stw r0, 0(r30)
/* 8011B8CC 0011882C  38 7E 00 00 */	addi r3, r30, 0
/* 8011B8D0 00118830  38 9F 00 00 */	addi r4, r31, 0
/* 8011B8D4 00118834  48 00 00 21 */	bl construct__20NClampLinearFunctionFPf
/* 8011B8D8 00118838  7F C3 F3 78 */	mr r3, r30
/* 8011B8DC 0011883C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011B8E0 00118840  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011B8E4 00118844  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8011B8E8 00118848  38 21 00 18 */	addi r1, r1, 0x18
/* 8011B8EC 0011884C  7C 08 03 A6 */	mtlr r0
/* 8011B8F0 00118850  4E 80 00 20 */	blr 

.global construct__20NClampLinearFunctionFPf
construct__20NClampLinearFunctionFPf:
/* 8011B8F4 00118854  7C 08 02 A6 */	mflr r0
/* 8011B8F8 00118858  38 63 00 04 */	addi r3, r3, 4
/* 8011B8FC 0011885C  90 01 00 04 */	stw r0, 4(r1)
/* 8011B900 00118860  38 A0 00 02 */	li r5, 2
/* 8011B904 00118864  94 21 FF F8 */	stwu r1, -8(r1)
/* 8011B908 00118868  48 00 14 C9 */	bl construct__7NVectorFPfi
/* 8011B90C 0011886C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8011B910 00118870  38 21 00 08 */	addi r1, r1, 8
/* 8011B914 00118874  7C 08 03 A6 */	mtlr r0
/* 8011B918 00118878  4E 80 00 20 */	blr 

.global makeClampLinearFunction__20NClampLinearFunctionFffff
makeClampLinearFunction__20NClampLinearFunctionFffff:
/* 8011B91C 0011887C  EC A3 08 28 */	fsubs f5, f3, f1
/* 8011B920 00118880  C0 02 A0 00 */	lfs f0, lbl_803EA200@sda21(r2)
/* 8011B924 00118884  FC 05 00 40 */	fcmpo cr0, f5, f0
/* 8011B928 00118888  40 81 00 0C */	ble lbl_8011B934
/* 8011B92C 0011888C  FC 60 28 90 */	fmr f3, f5
/* 8011B930 00118890  48 00 00 08 */	b lbl_8011B938
lbl_8011B934:
/* 8011B934 00118894  FC 60 28 50 */	fneg f3, f5
lbl_8011B938:
/* 8011B938 00118898  C0 0D E3 50 */	lfs f0, error__6NMathF@sda21(r13)
/* 8011B93C 0011889C  FC 03 00 40 */	fcmpo cr0, f3, f0
/* 8011B940 001188A0  4C 40 13 82 */	cror 2, 0, 2
/* 8011B944 001188A4  40 82 00 14 */	bne lbl_8011B958
/* 8011B948 001188A8  C0 02 A0 04 */	lfs f0, lbl_803EA204@sda21(r2)
/* 8011B94C 001188AC  80 83 00 04 */	lwz r4, 4(r3)
/* 8011B950 001188B0  D0 04 00 04 */	stfs f0, 4(r4)
/* 8011B954 001188B4  48 00 00 14 */	b lbl_8011B968
lbl_8011B958:
/* 8011B958 001188B8  EC 04 10 28 */	fsubs f0, f4, f2
/* 8011B95C 001188BC  80 83 00 04 */	lwz r4, 4(r3)
/* 8011B960 001188C0  EC 00 28 24 */	fdivs f0, f0, f5
/* 8011B964 001188C4  D0 04 00 04 */	stfs f0, 4(r4)
lbl_8011B968:
/* 8011B968 001188C8  80 83 00 04 */	lwz r4, 4(r3)
/* 8011B96C 001188CC  FC 02 20 40 */	fcmpo cr0, f2, f4
/* 8011B970 001188D0  C0 04 00 04 */	lfs f0, 4(r4)
/* 8011B974 001188D4  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011B978 001188D8  EC 02 00 28 */	fsubs f0, f2, f0
/* 8011B97C 001188DC  D0 04 00 00 */	stfs f0, 0(r4)
/* 8011B980 001188E0  40 80 00 0C */	bge lbl_8011B98C
/* 8011B984 001188E4  FC 00 10 90 */	fmr f0, f2
/* 8011B988 001188E8  48 00 00 08 */	b lbl_8011B990
lbl_8011B98C:
/* 8011B98C 001188EC  FC 00 20 90 */	fmr f0, f4
lbl_8011B990:
/* 8011B990 001188F0  FC 02 20 40 */	fcmpo cr0, f2, f4
/* 8011B994 001188F4  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 8011B998 001188F8  40 80 00 08 */	bge lbl_8011B9A0
/* 8011B99C 001188FC  48 00 00 08 */	b lbl_8011B9A4
lbl_8011B9A0:
/* 8011B9A0 00118900  FC 80 10 90 */	fmr f4, f2
lbl_8011B9A4:
/* 8011B9A4 00118904  D0 83 00 10 */	stfs f4, 0x10(r3)
/* 8011B9A8 00118908  4E 80 00 20 */	blr 

.global getValue__20NClampLinearFunctionFf
getValue__20NClampLinearFunctionFf:
/* 8011B9AC 0011890C  80 C3 00 08 */	lwz r6, 8(r3)
/* 8011B9B0 00118910  38 80 00 00 */	li r4, 0
/* 8011B9B4 00118914  C1 02 A0 04 */	lfs f8, lbl_803EA204@sda21(r2)
/* 8011B9B8 00118918  2C 06 00 00 */	cmpwi r6, 0
/* 8011B9BC 0011891C  C0 E2 A0 00 */	lfs f7, lbl_803EA200@sda21(r2)
/* 8011B9C0 00118920  40 81 00 EC */	ble lbl_8011BAAC
/* 8011B9C4 00118924  2C 06 00 08 */	cmpwi r6, 8
/* 8011B9C8 00118928  38 A6 FF F8 */	addi r5, r6, -8
/* 8011B9CC 0011892C  40 81 01 08 */	ble lbl_8011BAD4
/* 8011B9D0 00118930  38 05 00 07 */	addi r0, r5, 7
/* 8011B9D4 00118934  54 00 E8 FE */	srwi r0, r0, 3
/* 8011B9D8 00118938  2C 05 00 00 */	cmpwi r5, 0
/* 8011B9DC 0011893C  7C 09 03 A6 */	mtctr r0
/* 8011B9E0 00118940  38 A4 00 00 */	addi r5, r4, 0
/* 8011B9E4 00118944  40 81 00 F0 */	ble lbl_8011BAD4
lbl_8011B9E8:
/* 8011B9E8 00118948  80 03 00 04 */	lwz r0, 4(r3)
/* 8011B9EC 0011894C  38 84 00 08 */	addi r4, r4, 8
/* 8011B9F0 00118950  7C E0 2A 14 */	add r7, r0, r5
/* 8011B9F4 00118954  C0 47 00 00 */	lfs f2, 0(r7)
/* 8011B9F8 00118958  38 A5 00 20 */	addi r5, r5, 0x20
/* 8011B9FC 0011895C  C0 07 00 04 */	lfs f0, 4(r7)
/* 8011BA00 00118960  EC 48 00 B2 */	fmuls f2, f8, f2
/* 8011BA04 00118964  C0 C7 00 08 */	lfs f6, 8(r7)
/* 8011BA08 00118968  ED 08 00 72 */	fmuls f8, f8, f1
/* 8011BA0C 0011896C  C0 A7 00 0C */	lfs f5, 0xc(r7)
/* 8011BA10 00118970  C0 87 00 10 */	lfs f4, 0x10(r7)
/* 8011BA14 00118974  EC 08 00 32 */	fmuls f0, f8, f0
/* 8011BA18 00118978  C0 67 00 14 */	lfs f3, 0x14(r7)
/* 8011BA1C 0011897C  EC E7 10 2A */	fadds f7, f7, f2
/* 8011BA20 00118980  C0 47 00 18 */	lfs f2, 0x18(r7)
/* 8011BA24 00118984  ED 08 00 72 */	fmuls f8, f8, f1
/* 8011BA28 00118988  EC E7 00 2A */	fadds f7, f7, f0
/* 8011BA2C 0011898C  C0 07 00 1C */	lfs f0, 0x1c(r7)
/* 8011BA30 00118990  EC C8 01 B2 */	fmuls f6, f8, f6
/* 8011BA34 00118994  ED 08 00 72 */	fmuls f8, f8, f1
/* 8011BA38 00118998  EC E7 30 2A */	fadds f7, f7, f6
/* 8011BA3C 0011899C  EC A8 01 72 */	fmuls f5, f8, f5
/* 8011BA40 001189A0  ED 08 00 72 */	fmuls f8, f8, f1
/* 8011BA44 001189A4  EC E7 28 2A */	fadds f7, f7, f5
/* 8011BA48 001189A8  EC 88 01 32 */	fmuls f4, f8, f4
/* 8011BA4C 001189AC  ED 08 00 72 */	fmuls f8, f8, f1
/* 8011BA50 001189B0  EC E7 20 2A */	fadds f7, f7, f4
/* 8011BA54 001189B4  EC 68 00 F2 */	fmuls f3, f8, f3
/* 8011BA58 001189B8  ED 08 00 72 */	fmuls f8, f8, f1
/* 8011BA5C 001189BC  EC E7 18 2A */	fadds f7, f7, f3
/* 8011BA60 001189C0  EC 48 00 B2 */	fmuls f2, f8, f2
/* 8011BA64 001189C4  ED 08 00 72 */	fmuls f8, f8, f1
/* 8011BA68 001189C8  EC E7 10 2A */	fadds f7, f7, f2
/* 8011BA6C 001189CC  EC 08 00 32 */	fmuls f0, f8, f0
/* 8011BA70 001189D0  ED 08 00 72 */	fmuls f8, f8, f1
/* 8011BA74 001189D4  EC E7 00 2A */	fadds f7, f7, f0
/* 8011BA78 001189D8  42 00 FF 70 */	bdnz lbl_8011B9E8
/* 8011BA7C 001189DC  48 00 00 58 */	b lbl_8011BAD4
lbl_8011BA80:
/* 8011BA80 001189E0  7C 04 30 50 */	subf r0, r4, r6
/* 8011BA84 001189E4  7C 04 30 00 */	cmpw r4, r6
/* 8011BA88 001189E8  7C 09 03 A6 */	mtctr r0
/* 8011BA8C 001189EC  40 80 00 20 */	bge lbl_8011BAAC
lbl_8011BA90:
/* 8011BA90 001189F0  80 83 00 04 */	lwz r4, 4(r3)
/* 8011BA94 001189F4  7C 04 2C 2E */	lfsx f0, r4, r5
/* 8011BA98 001189F8  38 A5 00 04 */	addi r5, r5, 4
/* 8011BA9C 001189FC  EC 08 00 32 */	fmuls f0, f8, f0
/* 8011BAA0 00118A00  ED 08 00 72 */	fmuls f8, f8, f1
/* 8011BAA4 00118A04  EC E7 00 2A */	fadds f7, f7, f0
/* 8011BAA8 00118A08  42 00 FF E8 */	bdnz lbl_8011BA90
lbl_8011BAAC:
/* 8011BAAC 00118A0C  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 8011BAB0 00118A10  C0 03 00 10 */	lfs f0, 0x10(r3)
/* 8011BAB4 00118A14  FC 07 08 40 */	fcmpo cr0, f7, f1
/* 8011BAB8 00118A18  4D 80 00 20 */	bltlr 
/* 8011BABC 00118A1C  FC 07 00 40 */	fcmpo cr0, f7, f0
/* 8011BAC0 00118A20  40 81 00 0C */	ble lbl_8011BACC
/* 8011BAC4 00118A24  FC 20 00 90 */	fmr f1, f0
/* 8011BAC8 00118A28  4E 80 00 20 */	blr 
lbl_8011BACC:
/* 8011BACC 00118A2C  FC 20 38 90 */	fmr f1, f7
/* 8011BAD0 00118A30  4E 80 00 20 */	blr 
lbl_8011BAD4:
/* 8011BAD4 00118A34  54 85 10 3A */	slwi r5, r4, 2
/* 8011BAD8 00118A38  4B FF FF A8 */	b lbl_8011BA80
/* 8011BADC 00118A3C  4E 80 00 20 */	blr 

.global println__20NClampLinearFunctionFv
println__20NClampLinearFunctionFv:
/* 8011BAE0 00118A40  80 C3 00 08 */	lwz r6, 8(r3)
/* 8011BAE4 00118A44  38 80 00 00 */	li r4, 0
/* 8011BAE8 00118A48  2C 06 00 00 */	cmpwi r6, 0
/* 8011BAEC 00118A4C  4C 81 00 20 */	blelr 
/* 8011BAF0 00118A50  2C 06 00 08 */	cmpwi r6, 8
/* 8011BAF4 00118A54  38 A6 FF F8 */	addi r5, r6, -8
/* 8011BAF8 00118A58  40 81 00 20 */	ble lbl_8011BB18
/* 8011BAFC 00118A5C  38 05 00 07 */	addi r0, r5, 7
/* 8011BB00 00118A60  54 00 E8 FE */	srwi r0, r0, 3
/* 8011BB04 00118A64  2C 05 00 00 */	cmpwi r5, 0
/* 8011BB08 00118A68  7C 09 03 A6 */	mtctr r0
/* 8011BB0C 00118A6C  40 81 00 0C */	ble lbl_8011BB18
lbl_8011BB10:
/* 8011BB10 00118A70  38 84 00 08 */	addi r4, r4, 8
/* 8011BB14 00118A74  42 00 FF FC */	bdnz lbl_8011BB10
lbl_8011BB18:
/* 8011BB18 00118A78  7C 04 30 50 */	subf r0, r4, r6
/* 8011BB1C 00118A7C  7C 04 30 00 */	cmpw r4, r6
/* 8011BB20 00118A80  7C 09 03 A6 */	mtctr r0
/* 8011BB24 00118A84  4C 80 00 20 */	bgelr 
lbl_8011BB28:
/* 8011BB28 00118A88  42 00 00 00 */	bdnz lbl_8011BB28
/* 8011BB2C 00118A8C  4E 80 00 20 */	blr 
/* 8011BB30 00118A90  4B FF FF E8 */	b lbl_8011BB18
/* 8011BB34 00118A94  4E 80 00 20 */	blr 

.global __ct__18NVibrationFunctionFv
__ct__18NVibrationFunctionFv:
/* 8011BB38 00118A98  3C 80 80 2C */	lis r4, __vt__9NFunction@ha
/* 8011BB3C 00118A9C  38 04 42 5C */	addi r0, r4, __vt__9NFunction@l
/* 8011BB40 00118AA0  3C 80 80 2C */	lis r4, __vt__18NVibrationFunction@ha
/* 8011BB44 00118AA4  90 03 00 00 */	stw r0, 0(r3)
/* 8011BB48 00118AA8  38 04 41 A8 */	addi r0, r4, __vt__18NVibrationFunction@l
/* 8011BB4C 00118AAC  90 03 00 00 */	stw r0, 0(r3)
/* 8011BB50 00118AB0  C0 02 A0 00 */	lfs f0, lbl_803EA200@sda21(r2)
/* 8011BB54 00118AB4  D0 03 00 04 */	stfs f0, 4(r3)
/* 8011BB58 00118AB8  C0 22 A0 08 */	lfs f1, lbl_803EA208@sda21(r2)
/* 8011BB5C 00118ABC  C0 0D E3 5C */	lfs f0, pi__6NMathF@sda21(r13)
/* 8011BB60 00118AC0  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011BB64 00118AC4  D0 03 00 08 */	stfs f0, 8(r3)
/* 8011BB68 00118AC8  C0 02 A0 04 */	lfs f0, lbl_803EA204@sda21(r2)
/* 8011BB6C 00118ACC  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 8011BB70 00118AD0  4E 80 00 20 */	blr 

.global makeVibrationFunction__18NVibrationFunctionFfff
makeVibrationFunction__18NVibrationFunctionFfff:
/* 8011BB74 00118AD4  D0 23 00 04 */	stfs f1, 4(r3)
/* 8011BB78 00118AD8  C0 22 A0 08 */	lfs f1, lbl_803EA208@sda21(r2)
/* 8011BB7C 00118ADC  C0 0D E3 5C */	lfs f0, pi__6NMathF@sda21(r13)
/* 8011BB80 00118AE0  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011BB84 00118AE4  EC 00 10 24 */	fdivs f0, f0, f2
/* 8011BB88 00118AE8  D0 03 00 08 */	stfs f0, 8(r3)
/* 8011BB8C 00118AEC  D0 63 00 0C */	stfs f3, 0xc(r3)
/* 8011BB90 00118AF0  4E 80 00 20 */	blr 

.global getValue__18NVibrationFunctionFf
getValue__18NVibrationFunctionFf:
/* 8011BB94 00118AF4  7C 08 02 A6 */	mflr r0
/* 8011BB98 00118AF8  90 01 00 04 */	stw r0, 4(r1)
/* 8011BB9C 00118AFC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8011BBA0 00118B00  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011BBA4 00118B04  7C 7F 1B 78 */	mr r31, r3
/* 8011BBA8 00118B08  C0 03 00 08 */	lfs f0, 8(r3)
/* 8011BBAC 00118B0C  C0 43 00 04 */	lfs f2, 4(r3)
/* 8011BBB0 00118B10  EC 00 00 72 */	fmuls f0, f0, f1
/* 8011BBB4 00118B14  EC 22 00 2A */	fadds f1, f2, f0
/* 8011BBB8 00118B18  48 10 01 31 */	bl sinf
/* 8011BBBC 00118B1C  C0 1F 00 0C */	lfs f0, 0xc(r31)
/* 8011BBC0 00118B20  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011BBC4 00118B24  EC 20 00 72 */	fmuls f1, f0, f1
/* 8011BBC8 00118B28  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8011BBCC 00118B2C  38 21 00 20 */	addi r1, r1, 0x20
/* 8011BBD0 00118B30  7C 08 03 A6 */	mtlr r0
/* 8011BBD4 00118B34  4E 80 00 20 */	blr 

.global outputPosition__11NFunction3DFfR9NVector3f
outputPosition__11NFunction3DFfR9NVector3f:
/* 8011BBD8 00118B38  7C 08 02 A6 */	mflr r0
/* 8011BBDC 00118B3C  90 01 00 04 */	stw r0, 4(r1)
/* 8011BBE0 00118B40  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8011BBE4 00118B44  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 8011BBE8 00118B48  DB C1 00 28 */	stfd f30, 0x28(r1)
/* 8011BBEC 00118B4C  DB A1 00 20 */	stfd f29, 0x20(r1)
/* 8011BBF0 00118B50  FF A0 08 90 */	fmr f29, f1
/* 8011BBF4 00118B54  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011BBF8 00118B58  7C 9F 23 78 */	mr r31, r4
/* 8011BBFC 00118B5C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8011BC00 00118B60  7C 7E 1B 78 */	mr r30, r3
/* 8011BC04 00118B64  80 63 00 08 */	lwz r3, 8(r3)
/* 8011BC08 00118B68  81 83 00 00 */	lwz r12, 0(r3)
/* 8011BC0C 00118B6C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8011BC10 00118B70  7D 88 03 A6 */	mtlr r12
/* 8011BC14 00118B74  4E 80 00 21 */	blrl 
/* 8011BC18 00118B78  80 7E 00 04 */	lwz r3, 4(r30)
/* 8011BC1C 00118B7C  FF C0 08 90 */	fmr f30, f1
/* 8011BC20 00118B80  FC 20 E8 90 */	fmr f1, f29
/* 8011BC24 00118B84  81 83 00 00 */	lwz r12, 0(r3)
/* 8011BC28 00118B88  81 8C 00 08 */	lwz r12, 8(r12)
/* 8011BC2C 00118B8C  7D 88 03 A6 */	mtlr r12
/* 8011BC30 00118B90  4E 80 00 21 */	blrl 
/* 8011BC34 00118B94  80 7E 00 00 */	lwz r3, 0(r30)
/* 8011BC38 00118B98  FF E0 08 90 */	fmr f31, f1
/* 8011BC3C 00118B9C  FC 20 E8 90 */	fmr f1, f29
/* 8011BC40 00118BA0  81 83 00 00 */	lwz r12, 0(r3)
/* 8011BC44 00118BA4  81 8C 00 08 */	lwz r12, 8(r12)
/* 8011BC48 00118BA8  7D 88 03 A6 */	mtlr r12
/* 8011BC4C 00118BAC  4E 80 00 21 */	blrl 
/* 8011BC50 00118BB0  D0 3F 00 00 */	stfs f1, 0(r31)
/* 8011BC54 00118BB4  D3 FF 00 04 */	stfs f31, 4(r31)
/* 8011BC58 00118BB8  D3 DF 00 08 */	stfs f30, 8(r31)
/* 8011BC5C 00118BBC  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8011BC60 00118BC0  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 8011BC64 00118BC4  CB C1 00 28 */	lfd f30, 0x28(r1)
/* 8011BC68 00118BC8  CB A1 00 20 */	lfd f29, 0x20(r1)
/* 8011BC6C 00118BCC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8011BC70 00118BD0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8011BC74 00118BD4  38 21 00 38 */	addi r1, r1, 0x38
/* 8011BC78 00118BD8  7C 08 03 A6 */	mtlr r0
/* 8011BC7C 00118BDC  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C4158:
	.asciz "nlibfunction.cpp"
.balign 4
lbl_802C416C:
	.asciz "nlibfunction"
.balign 4
lbl_802C417C:
	.asciz "NVibrationFunction"
.balign 4
lbl_802C4190:
	.asciz "NFunction"
.balign 4
lbl_802C419C:
	.4byte __RTTI__9NFunction
	.4byte 0
	.4byte 0
.global __vt__18NVibrationFunction
__vt__18NVibrationFunction:
	.4byte __RTTI__18NVibrationFunction
	.4byte 0
	.4byte getValue__18NVibrationFunctionFf
.balign 4
lbl_802C41B4:
	.asciz "NClampLinearFunction"
.balign 4
lbl_802C41CC:
	.asciz "NPolynomialFunction"
.balign 4
lbl_802C41E0:
	.4byte __RTTI__9NFunction
	.4byte 0
	.4byte 0
.balign 4
lbl_802C41EC:
	.asciz "NLinearFunction"
.balign 4
lbl_802C41FC:
	.4byte __RTTI__9NFunction
	.4byte 0
	.4byte __RTTI__19NPolynomialFunction
	.4byte 0
	.4byte 0
lbl_802C4210:
	.4byte __RTTI__9NFunction
	.4byte 0
	.4byte __RTTI__19NPolynomialFunction
	.4byte 0
	.4byte __RTTI__15NLinearFunction
	.4byte 0
	.4byte 0
.global __vt__20NClampLinearFunction
__vt__20NClampLinearFunction:
	.4byte __RTTI__20NClampLinearFunction
	.4byte 0
	.4byte getValue__20NClampLinearFunctionFf
	.4byte println__20NClampLinearFunctionFv
.global __vt__15NLinearFunction
__vt__15NLinearFunction:
	.4byte __RTTI__15NLinearFunction
	.4byte 0
	.4byte getValue__19NPolynomialFunctionFf
	.4byte println__19NPolynomialFunctionFv
.global __vt__19NPolynomialFunction
__vt__19NPolynomialFunction:
	.4byte __RTTI__19NPolynomialFunction
	.4byte 0
	.4byte getValue__19NPolynomialFunctionFf
	.4byte println__19NPolynomialFunctionFv
.global __vt__9NFunction
__vt__9NFunction:
	.4byte __RTTI__9NFunction
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__9NFunction:
	.4byte lbl_802C4190
	.4byte 0
__RTTI__18NVibrationFunction:
	.4byte lbl_802C417C
	.4byte lbl_802C419C
__RTTI__19NPolynomialFunction:
	.4byte lbl_802C41CC
	.4byte lbl_802C41E0
__RTTI__15NLinearFunction:
	.4byte lbl_802C41EC
	.4byte lbl_802C41FC
__RTTI__20NClampLinearFunction:
	.4byte lbl_802C41B4
	.4byte lbl_802C4210

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EA200:
	.float 0.0
lbl_803EA204:
	.float 1.0
lbl_803EA208:
	.float 2.0
