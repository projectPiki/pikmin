.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn atanf, global
/* 8021B730 00218690  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8021B734 00218694  3C 60 80 22 */	lis r3, atan_coeff$96@ha
/* 8021B738 00218698  38 83 2C 40 */	addi r4, r3, atan_coeff$96@l
/* 8021B73C 0021869C  D0 21 00 08 */	stfs f1, 8(r1)
/* 8021B740 002186A0  38 C0 FF FF */	li r6, -1
/* 8021B744 002186A4  C0 02 C5 F0 */	lfs f0, lbl_803EC7F0@sda21(r2)
/* 8021B748 002186A8  38 E0 00 00 */	li r7, 0
/* 8021B74C 002186AC  80 61 00 08 */	lwz r3, 8(r1)
/* 8021B750 002186B0  54 60 00 7E */	clrlwi r0, r3, 1
/* 8021B754 002186B4  90 01 00 08 */	stw r0, 8(r1)
/* 8021B758 002186B8  54 68 00 00 */	rlwinm r8, r3, 0, 0, 0
/* 8021B75C 002186BC  C0 41 00 08 */	lfs f2, 8(r1)
/* 8021B760 002186C0  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8021B764 002186C4  4C 41 13 82 */	cror 2, 1, 2
/* 8021B768 002186C8  40 82 00 18 */	bne .L_8021B780
/* 8021B76C 002186CC  C0 02 C5 F4 */	lfs f0, lbl_803EC7F4@sda21(r2)
/* 8021B770 002186D0  38 E0 00 01 */	li r7, 1
/* 8021B774 002186D4  EC 00 10 24 */	fdivs f0, f0, f2
/* 8021B778 002186D8  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8021B77C 002186DC  48 00 00 F4 */	b .L_8021B870
.L_8021B780:
/* 8021B780 002186E0  C0 02 C5 F8 */	lfs f0, lbl_803EC7F8@sda21(r2)
/* 8021B784 002186E4  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 8021B788 002186E8  40 80 00 E4 */	bge .L_8021B86C
/* 8021B78C 002186EC  80 A1 00 08 */	lwz r5, 8(r1)
/* 8021B790 002186F0  3C 00 3F 80 */	lis r0, 0x3f80
/* 8021B794 002186F4  38 C0 00 00 */	li r6, 0
/* 8021B798 002186F8  54 A3 00 50 */	rlwinm r3, r5, 0, 1, 8
/* 8021B79C 002186FC  7C 03 00 00 */	cmpw r3, r0
/* 8021B7A0 00218700  41 82 00 54 */	beq .L_8021B7F4
/* 8021B7A4 00218704  40 80 00 14 */	bge .L_8021B7B8
/* 8021B7A8 00218708  3C 00 3F 00 */	lis r0, 0x3f00
/* 8021B7AC 0021870C  7C 03 00 00 */	cmpw r3, r0
/* 8021B7B0 00218710  41 82 00 18 */	beq .L_8021B7C8
/* 8021B7B4 00218714  48 00 00 74 */	b .L_8021B828
.L_8021B7B8:
/* 8021B7B8 00218718  3C 00 40 00 */	lis r0, 0x4000
/* 8021B7BC 0021871C  7C 03 00 00 */	cmpw r3, r0
/* 8021B7C0 00218720  41 82 00 64 */	beq .L_8021B824
/* 8021B7C4 00218724  48 00 00 64 */	b .L_8021B828
.L_8021B7C8:
/* 8021B7C8 00218728  3C 60 3F 09 */	lis r3, 0x3F08D5B9@ha
/* 8021B7CC 0021872C  38 03 D5 B9 */	addi r0, r3, 0x3F08D5B9@l
/* 8021B7D0 00218730  7C 05 00 00 */	cmpw r5, r0
/* 8021B7D4 00218734  41 80 00 08 */	blt .L_8021B7DC
/* 8021B7D8 00218738  38 C0 00 01 */	li r6, 1
.L_8021B7DC:
/* 8021B7DC 0021873C  3C 60 3F 52 */	lis r3, 0x3F521801@ha
/* 8021B7E0 00218740  38 03 18 01 */	addi r0, r3, 0x3F521801@l
/* 8021B7E4 00218744  7C 05 00 00 */	cmpw r5, r0
/* 8021B7E8 00218748  41 80 00 40 */	blt .L_8021B828
/* 8021B7EC 0021874C  38 C6 00 01 */	addi r6, r6, 1
/* 8021B7F0 00218750  48 00 00 38 */	b .L_8021B828
.L_8021B7F4:
/* 8021B7F4 00218754  3C 60 3F 9C */	lis r3, 0x3F9BF7EC@ha
/* 8021B7F8 00218758  38 03 F7 EC */	addi r0, r3, 0x3F9BF7EC@l
/* 8021B7FC 0021875C  7C 05 00 00 */	cmpw r5, r0
/* 8021B800 00218760  38 C0 00 02 */	li r6, 2
/* 8021B804 00218764  41 80 00 08 */	blt .L_8021B80C
/* 8021B808 00218768  38 C0 00 03 */	li r6, 3
.L_8021B80C:
/* 8021B80C 0021876C  3C 60 3F EF */	lis r3, 0x3FEF789E@ha
/* 8021B810 00218770  38 03 78 9E */	addi r0, r3, 0x3FEF789E@l
/* 8021B814 00218774  7C 05 00 00 */	cmpw r5, r0
/* 8021B818 00218778  41 80 00 10 */	blt .L_8021B828
/* 8021B81C 0021877C  38 C6 00 01 */	addi r6, r6, 1
/* 8021B820 00218780  48 00 00 08 */	b .L_8021B828
.L_8021B824:
/* 8021B824 00218784  38 C0 00 04 */	li r6, 4
.L_8021B828:
/* 8021B828 00218788  54 C0 10 3A */	slwi r0, r6, 2
/* 8021B82C 0021878C  C0 22 C5 F4 */	lfs f1, lbl_803EC7F4@sda21(r2)
/* 8021B830 00218790  7C 64 02 14 */	add r3, r4, r0
/* 8021B834 00218794  C0 63 00 9C */	lfs f3, 0x9c(r3)
/* 8021B838 00218798  C0 83 00 84 */	lfs f4, 0x84(r3)
/* 8021B83C 0021879C  EC 02 18 2A */	fadds f0, f2, f3
/* 8021B840 002187A0  EC 04 00 2A */	fadds f0, f4, f0
/* 8021B844 002187A4  EC 01 00 24 */	fdivs f0, f1, f0
/* 8021B848 002187A8  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8021B84C 002187AC  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8021B850 002187B0  C0 23 00 1C */	lfs f1, 0x1c(r3)
/* 8021B854 002187B4  C0 03 00 34 */	lfs f0, 0x34(r3)
/* 8021B858 002187B8  EC 22 20 7C */	fnmsubs f1, f2, f1, f4
/* 8021B85C 002187BC  EC 02 18 3C */	fnmsubs f0, f2, f0, f3
/* 8021B860 002187C0  EC 01 00 2A */	fadds f0, f1, f0
/* 8021B864 002187C4  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8021B868 002187C8  48 00 00 08 */	b .L_8021B870
.L_8021B86C:
/* 8021B86C 002187CC  D0 41 00 0C */	stfs f2, 0xc(r1)
.L_8021B870:
/* 8021B870 002187D0  C0 A1 00 0C */	lfs f5, 0xc(r1)
/* 8021B874 002187D4  54 C0 10 3A */	slwi r0, r6, 2
/* 8021B878 002187D8  C0 44 00 18 */	lfs f2, 0x18(r4)
/* 8021B87C 002187DC  7C 64 02 14 */	add r3, r4, r0
/* 8021B880 002187E0  EC C5 01 72 */	fmuls f6, f5, f5
/* 8021B884 002187E4  C0 24 00 14 */	lfs f1, 0x14(r4)
/* 8021B888 002187E8  2C 07 00 00 */	cmpwi r7, 0
/* 8021B88C 002187EC  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8021B890 002187F0  EC 66 08 BA */	fmadds f3, f6, f2, f1
/* 8021B894 002187F4  C0 44 00 0C */	lfs f2, 0xc(r4)
/* 8021B898 002187F8  EC 85 01 B2 */	fmuls f4, f5, f6
/* 8021B89C 002187FC  C0 24 00 08 */	lfs f1, 8(r4)
/* 8021B8A0 00218800  EC 66 00 FA */	fmadds f3, f6, f3, f0
/* 8021B8A4 00218804  C0 04 00 04 */	lfs f0, 4(r4)
/* 8021B8A8 00218808  EC 46 10 FA */	fmadds f2, f6, f3, f2
/* 8021B8AC 0021880C  EC 26 08 BA */	fmadds f1, f6, f2, f1
/* 8021B8B0 00218810  EC 06 00 7A */	fmadds f0, f6, f1, f0
/* 8021B8B4 00218814  EC 04 28 3A */	fmadds f0, f4, f0, f5
/* 8021B8B8 00218818  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8021B8BC 0021881C  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8021B8C0 00218820  C0 03 00 6C */	lfs f0, 0x6c(r3)
/* 8021B8C4 00218824  EC 01 00 2A */	fadds f0, f1, f0
/* 8021B8C8 00218828  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8021B8CC 0021882C  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8021B8D0 00218830  C0 03 00 50 */	lfs f0, 0x50(r3)
/* 8021B8D4 00218834  EC 01 00 2A */	fadds f0, f1, f0
/* 8021B8D8 00218838  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8021B8DC 0021883C  41 82 00 30 */	beq .L_8021B90C
/* 8021B8E0 00218840  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8021B8E4 00218844  2C 08 00 00 */	cmpwi r8, 0
/* 8021B8E8 00218848  C0 02 C5 FC */	lfs f0, lbl_803EC7FC@sda21(r2)
/* 8021B8EC 0021884C  EC 01 00 28 */	fsubs f0, f1, f0
/* 8021B8F0 00218850  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8021B8F4 00218854  41 82 00 0C */	beq .L_8021B900
/* 8021B8F8 00218858  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8021B8FC 0021885C  48 00 00 20 */	b .L_8021B91C
.L_8021B900:
/* 8021B900 00218860  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8021B904 00218864  FC 20 00 50 */	fneg f1, f0
/* 8021B908 00218868  48 00 00 14 */	b .L_8021B91C
.L_8021B90C:
/* 8021B90C 0021886C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021B910 00218870  7C 00 43 78 */	or r0, r0, r8
/* 8021B914 00218874  90 01 00 0C */	stw r0, 0xc(r1)
/* 8021B918 00218878  C0 21 00 0C */	lfs f1, 0xc(r1)
.L_8021B91C:
/* 8021B91C 0021887C  38 21 00 10 */	addi r1, r1, 0x10
/* 8021B920 00218880  4E 80 00 20 */	blr 
.endfn atanf

.fn atan__Ff, weak
/* 8021B924 00218884  7C 08 02 A6 */	mflr r0
/* 8021B928 00218888  90 01 00 04 */	stw r0, 4(r1)
/* 8021B92C 0021888C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021B930 00218890  4B FF FE 01 */	bl atanf
/* 8021B934 00218894  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8021B938 00218898  38 21 00 08 */	addi r1, r1, 8
/* 8021B93C 0021889C  7C 08 03 A6 */	mtlr r0
/* 8021B940 002188A0  4E 80 00 20 */	blr 
.endfn atan__Ff

.fn _inv_sqrtf, weak
/* 8021B944 002188A4  C0 02 C6 00 */	lfs f0, lbl_803EC800@sda21(r2)
/* 8021B948 002188A8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8021B94C 002188AC  40 81 00 48 */	ble .L_8021B994
/* 8021B950 002188B0  FC 40 08 34 */	frsqrte f2, f1
/* 8021B954 002188B4  C0 82 C6 04 */	lfs f4, lbl_803EC804@sda21(r2)
/* 8021B958 002188B8  C0 62 C6 08 */	lfs f3, lbl_803EC808@sda21(r2)
/* 8021B95C 002188BC  FC 40 10 18 */	frsp f2, f2
/* 8021B960 002188C0  EC 02 00 B2 */	fmuls f0, f2, f2
/* 8021B964 002188C4  EC 44 00 B2 */	fmuls f2, f4, f2
/* 8021B968 002188C8  EC 01 18 3C */	fnmsubs f0, f1, f0, f3
/* 8021B96C 002188CC  EC 42 00 32 */	fmuls f2, f2, f0
/* 8021B970 002188D0  EC 02 00 B2 */	fmuls f0, f2, f2
/* 8021B974 002188D4  EC 44 00 B2 */	fmuls f2, f4, f2
/* 8021B978 002188D8  EC 01 18 3C */	fnmsubs f0, f1, f0, f3
/* 8021B97C 002188DC  EC 42 00 32 */	fmuls f2, f2, f0
/* 8021B980 002188E0  EC 02 00 B2 */	fmuls f0, f2, f2
/* 8021B984 002188E4  EC 44 00 B2 */	fmuls f2, f4, f2
/* 8021B988 002188E8  EC 01 18 3C */	fnmsubs f0, f1, f0, f3
/* 8021B98C 002188EC  EC 22 00 32 */	fmuls f1, f2, f0
/* 8021B990 002188F0  4E 80 00 20 */	blr 
.L_8021B994:
/* 8021B994 002188F4  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 8021B998 002188F8  41 82 00 10 */	beq .L_8021B9A8
/* 8021B99C 002188FC  3C 60 80 2F */	lis r3, __float_nan@ha
/* 8021B9A0 00218900  C0 23 94 78 */	lfs f1, __float_nan@l(r3)
/* 8021B9A4 00218904  4E 80 00 20 */	blr 
.L_8021B9A8:
/* 8021B9A8 00218908  3C 60 80 2F */	lis r3, __float_huge@ha
/* 8021B9AC 0021890C  C0 23 94 7C */	lfs f1, __float_huge@l(r3)
/* 8021B9B0 00218910  4E 80 00 20 */	blr 
.endfn _inv_sqrtf

.fn acosf, global
/* 8021B9B4 00218914  7C 08 02 A6 */	mflr r0
/* 8021B9B8 00218918  90 01 00 04 */	stw r0, 4(r1)
/* 8021B9BC 0021891C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8021B9C0 00218920  DB E1 00 10 */	stfd f31, 0x10(r1)
/* 8021B9C4 00218924  FF E0 08 90 */	fmr f31, f1
/* 8021B9C8 00218928  C0 02 C5 F4 */	lfs f0, lbl_803EC7F4@sda21(r2)
/* 8021B9CC 0021892C  EC 3F 07 FC */	fnmsubs f1, f31, f31, f0
/* 8021B9D0 00218930  4B FF FF 75 */	bl _inv_sqrtf
/* 8021B9D4 00218934  EC 3F 00 72 */	fmuls f1, f31, f1
/* 8021B9D8 00218938  4B FF FF 4D */	bl atan__Ff
/* 8021B9DC 0021893C  C0 02 C5 FC */	lfs f0, lbl_803EC7FC@sda21(r2)
/* 8021B9E0 00218940  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8021B9E4 00218944  EC 20 08 28 */	fsubs f1, f0, f1
/* 8021B9E8 00218948  CB E1 00 10 */	lfd f31, 0x10(r1)
/* 8021B9EC 0021894C  7C 08 03 A6 */	mtlr r0
/* 8021B9F0 00218950  38 21 00 18 */	addi r1, r1, 0x18
/* 8021B9F4 00218954  4E 80 00 20 */	blr 
.endfn acosf

.fn atan2f, global
/* 8021B9F8 00218958  7C 08 02 A6 */	mflr r0
/* 8021B9FC 0021895C  90 01 00 04 */	stw r0, 4(r1)
/* 8021BA00 00218960  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8021BA04 00218964  D0 21 00 08 */	stfs f1, 8(r1)
/* 8021BA08 00218968  D0 41 00 0C */	stfs f2, 0xc(r1)
/* 8021BA0C 0021896C  80 01 00 08 */	lwz r0, 8(r1)
/* 8021BA10 00218970  80 61 00 0C */	lwz r3, 0xc(r1)
/* 8021BA14 00218974  54 04 00 00 */	rlwinm r4, r0, 0, 0, 0
/* 8021BA18 00218978  54 60 00 00 */	rlwinm r0, r3, 0, 0, 0
/* 8021BA1C 0021897C  7C 00 20 00 */	cmpw r0, r4
/* 8021BA20 00218980  40 82 00 50 */	bne .L_8021BA70
/* 8021BA24 00218984  2C 00 00 00 */	cmpwi r0, 0
/* 8021BA28 00218988  41 82 00 20 */	beq .L_8021BA48
/* 8021BA2C 0021898C  C0 21 00 08 */	lfs f1, 8(r1)
/* 8021BA30 00218990  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8021BA34 00218994  EC 21 00 24 */	fdivs f1, f1, f0
/* 8021BA38 00218998  4B FF FC F9 */	bl atanf
/* 8021BA3C 0021899C  C0 02 C6 0C */	lfs f0, lbl_803EC80C@sda21(r2)
/* 8021BA40 002189A0  EC 21 00 28 */	fsubs f1, f1, f0
/* 8021BA44 002189A4  48 00 00 7C */	b .L_8021BAC0
.L_8021BA48:
/* 8021BA48 002189A8  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8021BA4C 002189AC  C0 02 C6 00 */	lfs f0, lbl_803EC800@sda21(r2)
/* 8021BA50 002189B0  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 8021BA54 002189B4  41 82 00 14 */	beq .L_8021BA68
/* 8021BA58 002189B8  C0 01 00 08 */	lfs f0, 8(r1)
/* 8021BA5C 002189BC  EC 20 08 24 */	fdivs f1, f0, f1
/* 8021BA60 002189C0  4B FF FC D1 */	bl atanf
/* 8021BA64 002189C4  48 00 00 5C */	b .L_8021BAC0
.L_8021BA68:
/* 8021BA68 002189C8  C0 22 C5 FC */	lfs f1, lbl_803EC7FC@sda21(r2)
/* 8021BA6C 002189CC  48 00 00 54 */	b .L_8021BAC0
.L_8021BA70:
/* 8021BA70 002189D0  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8021BA74 002189D4  C0 02 C6 00 */	lfs f0, lbl_803EC800@sda21(r2)
/* 8021BA78 002189D8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8021BA7C 002189DC  40 80 00 1C */	bge .L_8021BA98
/* 8021BA80 002189E0  C0 01 00 08 */	lfs f0, 8(r1)
/* 8021BA84 002189E4  EC 20 08 24 */	fdivs f1, f0, f1
/* 8021BA88 002189E8  4B FF FC A9 */	bl atanf
/* 8021BA8C 002189EC  C0 02 C6 0C */	lfs f0, lbl_803EC80C@sda21(r2)
/* 8021BA90 002189F0  EC 20 08 2A */	fadds f1, f0, f1
/* 8021BA94 002189F4  48 00 00 2C */	b .L_8021BAC0
.L_8021BA98:
/* 8021BA98 002189F8  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 8021BA9C 002189FC  41 82 00 14 */	beq .L_8021BAB0
/* 8021BAA0 00218A00  C0 01 00 08 */	lfs f0, 8(r1)
/* 8021BAA4 00218A04  EC 20 08 24 */	fdivs f1, f0, f1
/* 8021BAA8 00218A08  4B FF FC 89 */	bl atanf
/* 8021BAAC 00218A0C  48 00 00 14 */	b .L_8021BAC0
.L_8021BAB0:
/* 8021BAB0 00218A10  3C 64 3F C9 */	addis r3, r4, 0x3fc9
/* 8021BAB4 00218A14  38 03 0F DB */	addi r0, r3, 0xfdb
/* 8021BAB8 00218A18  90 01 00 08 */	stw r0, 8(r1)
/* 8021BABC 00218A1C  C0 21 00 08 */	lfs f1, 8(r1)
.L_8021BAC0:
/* 8021BAC0 00218A20  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8021BAC4 00218A24  38 21 00 10 */	addi r1, r1, 0x10
/* 8021BAC8 00218A28  7C 08 03 A6 */	mtlr r0
/* 8021BACC 00218A2C  4E 80 00 20 */	blr 
.endfn atan2f

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.balign 8
.obj atan_coeff$96, local
	.float 1.0
	.float -0.3333333
	.float 0.19999887
	.float -0.1428165
	.float 0.1104118
	.float -0.08459756
	.float 0.047142435
.endobj atan_coeff$96
.obj onep_one_over_xisqr_hi$97, local
	.float 6.82842
	.float 3.239828
	.float 2.0
	.float 1.446462
	.float 1.1715729
	.float 1.0395662
.endobj onep_one_over_xisqr_hi$97
.obj onep_one_over_xisqr_lo$98, local
	.float 7.135E-6
	.float 8.2E-7
	.float 0.0
	.float 6.3E-7
	.float 0.0
	.float 0.0
.endobj onep_one_over_xisqr_lo$98
.obj atan_xi_hi$99, local
	.float 0.0
	.float 0.39269
	.float 0.5890486
	.float 0.7853981
	.float 0.981747
	.float 1.178097
	.float 1.374446
.endobj atan_xi_hi$99
.obj atan_xi_lo$100, local
	.float 0.0
	.float 9.081698E-6
	.float 2.3E-8
	.float 6.3E-8
	.float 7.04E-7
	.float 2.5E-7
	.float 7.9E-7
.endobj atan_xi_lo$100
.obj one_over_xi_hi$101, local
	.float 2.414213
	.float 1.4966058
	.float 1.0
	.float 0.6681786
	.float 0.41421357
	.float 0.19891237
.endobj one_over_xi_hi$101
.obj one_over_xi_lo$102, local
	.float 5.62E-7
	.float 0.0
	.float 0.0
	.float 0.0
	.float 0.0
	.float 0.0
	.float 0.0
.endobj one_over_xi_lo$102

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EC7F0, local
	.float 2.4142137
.endobj lbl_803EC7F0
.obj lbl_803EC7F4, local
	.float 1.0
.endobj lbl_803EC7F4
.obj lbl_803EC7F8, local
	.float 0.41421357
.endobj lbl_803EC7F8
.obj lbl_803EC7FC, local
	.float 1.5707964
.endobj lbl_803EC7FC
.obj lbl_803EC800, local
	.float 0.0
.endobj lbl_803EC800
.obj lbl_803EC804, local
	.float 0.5
.endobj lbl_803EC804
.obj lbl_803EC808, local
	.float 3.0
.endobj lbl_803EC808
.obj lbl_803EC80C, local
	.float 3.1415927
.endobj lbl_803EC80C
