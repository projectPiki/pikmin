.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__8ActChaseFP4Piki, global
/* 800B5688 000B25E8  7C 08 02 A6 */	mflr r0
/* 800B568C 000B25EC  38 A0 00 01 */	li r5, 1
/* 800B5690 000B25F0  90 01 00 04 */	stw r0, 4(r1)
/* 800B5694 000B25F4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B5698 000B25F8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B569C 000B25FC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800B56A0 000B2600  90 61 00 08 */	stw r3, 8(r1)
/* 800B56A4 000B2604  80 61 00 08 */	lwz r3, 8(r1)
/* 800B56A8 000B2608  48 00 E7 29 */	bl __ct__6ActionFP4Pikib
/* 800B56AC 000B260C  3C 60 80 2B */	lis r3, __vt__8ActChase@ha
/* 800B56B0 000B2610  83 C1 00 08 */	lwz r30, 8(r1)
/* 800B56B4 000B2614  38 03 61 E0 */	addi r0, r3, __vt__8ActChase@l
/* 800B56B8 000B2618  90 1E 00 00 */	stw r0, 0(r30)
/* 800B56BC 000B261C  3B E0 00 00 */	li r31, 0
/* 800B56C0 000B2620  93 FE 00 14 */	stw r31, 0x14(r30)
/* 800B56C4 000B2624  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 800B56C8 000B2628  28 03 00 00 */	cmplwi r3, 0
/* 800B56CC 000B262C  41 82 00 0C */	beq .L_800B56D8
/* 800B56D0 000B2630  48 02 EC 9D */	bl subCnt__12RefCountableFv
/* 800B56D4 000B2634  93 FE 00 14 */	stw r31, 0x14(r30)
.L_800B56D8:
/* 800B56D8 000B2638  80 61 00 08 */	lwz r3, 8(r1)
/* 800B56DC 000B263C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B56E0 000B2640  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B56E4 000B2644  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800B56E8 000B2648  38 21 00 18 */	addi r1, r1, 0x18
/* 800B56EC 000B264C  7C 08 03 A6 */	mtlr r0
/* 800B56F0 000B2650  4E 80 00 20 */	blr 
.endfn __ct__8ActChaseFP4Piki

.fn initialise__Q28ActChase11InitialiserFP6Action, global
/* 800B56F4 000B2654  4E 80 00 20 */	blr 
.endfn initialise__Q28ActChase11InitialiserFP6Action

.fn init__8ActChaseFP8Creature, global
/* 800B56F8 000B2658  7C 08 02 A6 */	mflr r0
/* 800B56FC 000B265C  90 01 00 04 */	stw r0, 4(r1)
/* 800B5700 000B2660  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800B5704 000B2664  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800B5708 000B2668  3B E4 00 00 */	addi r31, r4, 0
/* 800B570C 000B266C  93 C1 00 30 */	stw r30, 0x30(r1)
/* 800B5710 000B2670  3B C3 00 00 */	addi r30, r3, 0
/* 800B5714 000B2674  48 16 29 5D */	bl rand
/* 800B5718 000B2678  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800B571C 000B267C  C8 82 90 E8 */	lfd f4, lbl_803E92E8@sda21(r2)
/* 800B5720 000B2680  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800B5724 000B2684  3C 00 43 30 */	lis r0, 0x4330
/* 800B5728 000B2688  C0 62 90 DC */	lfs f3, lbl_803E92DC@sda21(r2)
/* 800B572C 000B268C  90 01 00 28 */	stw r0, 0x28(r1)
/* 800B5730 000B2690  C0 42 90 D8 */	lfs f2, lbl_803E92D8@sda21(r2)
/* 800B5734 000B2694  C8 21 00 28 */	lfd f1, 0x28(r1)
/* 800B5738 000B2698  C0 02 90 E4 */	lfs f0, lbl_803E92E4@sda21(r2)
/* 800B573C 000B269C  EC 81 20 28 */	fsubs f4, f1, f4
/* 800B5740 000B26A0  C0 22 90 E0 */	lfs f1, lbl_803E92E0@sda21(r2)
/* 800B5744 000B26A4  EC 64 18 24 */	fdivs f3, f4, f3
/* 800B5748 000B26A8  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800B574C 000B26AC  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800B5750 000B26B0  EC 01 00 2A */	fadds f0, f1, f0
/* 800B5754 000B26B4  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 800B5758 000B26B8  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 800B575C 000B26BC  28 03 00 00 */	cmplwi r3, 0
/* 800B5760 000B26C0  41 82 00 14 */	beq .L_800B5774
/* 800B5764 000B26C4  41 82 00 10 */	beq .L_800B5774
/* 800B5768 000B26C8  48 02 EC 05 */	bl subCnt__12RefCountableFv
/* 800B576C 000B26CC  38 00 00 00 */	li r0, 0
/* 800B5770 000B26D0  90 1E 00 14 */	stw r0, 0x14(r30)
.L_800B5774:
/* 800B5774 000B26D4  93 FE 00 14 */	stw r31, 0x14(r30)
/* 800B5778 000B26D8  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 800B577C 000B26DC  28 03 00 00 */	cmplwi r3, 0
/* 800B5780 000B26E0  41 82 00 08 */	beq .L_800B5788
/* 800B5784 000B26E4  48 02 EB D9 */	bl addCnt__12RefCountableFv
.L_800B5788:
/* 800B5788 000B26E8  38 61 00 14 */	addi r3, r1, 0x14
/* 800B578C 000B26EC  38 80 00 00 */	li r4, 0
/* 800B5790 000B26F0  48 06 97 C9 */	bl __ct__14PaniMotionInfoFi
/* 800B5794 000B26F4  3B E3 00 00 */	addi r31, r3, 0
/* 800B5798 000B26F8  38 61 00 1C */	addi r3, r1, 0x1c
/* 800B579C 000B26FC  38 80 00 00 */	li r4, 0
/* 800B57A0 000B2700  48 06 97 B9 */	bl __ct__14PaniMotionInfoFi
/* 800B57A4 000B2704  7C 64 1B 78 */	mr r4, r3
/* 800B57A8 000B2708  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B57AC 000B270C  7F E5 FB 78 */	mr r5, r31
/* 800B57B0 000B2710  48 01 52 29 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800B57B4 000B2714  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800B57B8 000B2718  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800B57BC 000B271C  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 800B57C0 000B2720  38 21 00 38 */	addi r1, r1, 0x38
/* 800B57C4 000B2724  7C 08 03 A6 */	mtlr r0
/* 800B57C8 000B2728  4E 80 00 20 */	blr 
.endfn init__8ActChaseFP8Creature

.fn cleanup__8ActChaseFv, global
/* 800B57CC 000B272C  7C 08 02 A6 */	mflr r0
/* 800B57D0 000B2730  90 01 00 04 */	stw r0, 4(r1)
/* 800B57D4 000B2734  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800B57D8 000B2738  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800B57DC 000B273C  7C 7F 1B 78 */	mr r31, r3
/* 800B57E0 000B2740  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800B57E4 000B2744  28 03 00 00 */	cmplwi r3, 0
/* 800B57E8 000B2748  41 82 00 10 */	beq .L_800B57F8
/* 800B57EC 000B274C  48 02 EB 81 */	bl subCnt__12RefCountableFv
/* 800B57F0 000B2750  38 00 00 00 */	li r0, 0
/* 800B57F4 000B2754  90 1F 00 14 */	stw r0, 0x14(r31)
.L_800B57F8:
/* 800B57F8 000B2758  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800B57FC 000B275C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800B5800 000B2760  38 21 00 20 */	addi r1, r1, 0x20
/* 800B5804 000B2764  7C 08 03 A6 */	mtlr r0
/* 800B5808 000B2768  4E 80 00 20 */	blr 
.endfn cleanup__8ActChaseFv

.fn exec__8ActChaseFv, global
/* 800B580C 000B276C  7C 08 02 A6 */	mflr r0
/* 800B5810 000B2770  90 01 00 04 */	stw r0, 4(r1)
/* 800B5814 000B2774  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 800B5818 000B2778  DB E1 00 88 */	stfd f31, 0x88(r1)
/* 800B581C 000B277C  DB C1 00 80 */	stfd f30, 0x80(r1)
/* 800B5820 000B2780  93 E1 00 7C */	stw r31, 0x7c(r1)
/* 800B5824 000B2784  93 C1 00 78 */	stw r30, 0x78(r1)
/* 800B5828 000B2788  7C 7E 1B 78 */	mr r30, r3
/* 800B582C 000B278C  83 E3 00 14 */	lwz r31, 0x14(r3)
/* 800B5830 000B2790  81 9F 00 00 */	lwz r12, 0(r31)
/* 800B5834 000B2794  7F E3 FB 78 */	mr r3, r31
/* 800B5838 000B2798  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800B583C 000B279C  7D 88 03 A6 */	mtlr r12
/* 800B5840 000B27A0  4E 80 00 21 */	blrl 
/* 800B5844 000B27A4  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B5848 000B27A8  40 82 00 0C */	bne .L_800B5854
/* 800B584C 000B27AC  38 60 00 01 */	li r3, 1
/* 800B5850 000B27B0  48 00 01 D8 */	b .L_800B5A28
.L_800B5854:
/* 800B5854 000B27B4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800B5858 000B27B8  C0 3E 00 18 */	lfs f1, 0x18(r30)
/* 800B585C 000B27BC  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800B5860 000B27C0  EC 01 00 28 */	fsubs f0, f1, f0
/* 800B5864 000B27C4  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 800B5868 000B27C8  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800B586C 000B27CC  80 64 05 00 */	lwz r3, 0x500(r4)
/* 800B5870 000B27D0  28 03 00 00 */	cmplwi r3, 0
/* 800B5874 000B27D4  41 82 00 18 */	beq .L_800B588C
/* 800B5878 000B27D8  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800B587C 000B27DC  7C 03 00 40 */	cmplw r3, r0
/* 800B5880 000B27E0  40 82 00 0C */	bne .L_800B588C
/* 800B5884 000B27E4  38 60 00 02 */	li r3, 2
/* 800B5888 000B27E8  48 00 01 A0 */	b .L_800B5A28
.L_800B588C:
/* 800B588C 000B27EC  C0 1E 00 18 */	lfs f0, 0x18(r30)
/* 800B5890 000B27F0  C0 A2 90 F0 */	lfs f5, lbl_803E92F0@sda21(r2)
/* 800B5894 000B27F4  FC 00 28 40 */	fcmpo cr0, f0, f5
/* 800B5898 000B27F8  40 80 00 0C */	bge .L_800B58A4
/* 800B589C 000B27FC  38 60 00 01 */	li r3, 1
/* 800B58A0 000B2800  48 00 01 88 */	b .L_800B5A28
.L_800B58A4:
/* 800B58A4 000B2804  C0 0D B4 68 */	lfs f0, lbl_803E0188@sda21(r13)
/* 800B58A8 000B2808  D0 04 00 A4 */	stfs f0, 0xa4(r4)
/* 800B58AC 000B280C  C0 0D B4 6C */	lfs f0, lbl_803E018C@sda21(r13)
/* 800B58B0 000B2810  D0 04 00 A8 */	stfs f0, 0xa8(r4)
/* 800B58B4 000B2814  C0 0D B4 70 */	lfs f0, lbl_803E0190@sda21(r13)
/* 800B58B8 000B2818  D0 04 00 AC */	stfs f0, 0xac(r4)
/* 800B58BC 000B281C  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B58C0 000B2820  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 800B58C4 000B2824  C0 3F 00 94 */	lfs f1, 0x94(r31)
/* 800B58C8 000B2828  C0 7F 00 98 */	lfs f3, 0x98(r31)
/* 800B58CC 000B282C  C0 43 00 04 */	lfs f2, 4(r3)
/* 800B58D0 000B2830  EC 01 00 28 */	fsubs f0, f1, f0
/* 800B58D4 000B2834  C0 9F 00 9C */	lfs f4, 0x9c(r31)
/* 800B58D8 000B2838  C0 23 00 08 */	lfs f1, 8(r3)
/* 800B58DC 000B283C  EC 43 10 28 */	fsubs f2, f3, f2
/* 800B58E0 000B2840  D0 01 00 5C */	stfs f0, 0x5c(r1)
/* 800B58E4 000B2844  EC 04 08 28 */	fsubs f0, f4, f1
/* 800B58E8 000B2848  D0 41 00 60 */	stfs f2, 0x60(r1)
/* 800B58EC 000B284C  D0 01 00 64 */	stfs f0, 0x64(r1)
/* 800B58F0 000B2850  D0 A1 00 60 */	stfs f5, 0x60(r1)
/* 800B58F4 000B2854  C0 21 00 5C */	lfs f1, 0x5c(r1)
/* 800B58F8 000B2858  C0 01 00 60 */	lfs f0, 0x60(r1)
/* 800B58FC 000B285C  C0 41 00 64 */	lfs f2, 0x64(r1)
/* 800B5900 000B2860  EC 21 00 72 */	fmuls f1, f1, f1
/* 800B5904 000B2864  EC 00 00 32 */	fmuls f0, f0, f0
/* 800B5908 000B2868  EC 42 00 B2 */	fmuls f2, f2, f2
/* 800B590C 000B286C  EC 01 00 2A */	fadds f0, f1, f0
/* 800B5910 000B2870  EC 82 00 2A */	fadds f4, f2, f0
/* 800B5914 000B2874  FC 04 28 40 */	fcmpo cr0, f4, f5
/* 800B5918 000B2878  40 81 00 5C */	ble .L_800B5974
/* 800B591C 000B287C  FC 20 20 34 */	frsqrte f1, f4
/* 800B5920 000B2880  C8 62 90 F8 */	lfd f3, lbl_803E92F8@sda21(r2)
/* 800B5924 000B2884  C8 42 91 00 */	lfd f2, lbl_803E9300@sda21(r2)
/* 800B5928 000B2888  FC 01 00 72 */	fmul f0, f1, f1
/* 800B592C 000B288C  FC 23 00 72 */	fmul f1, f3, f1
/* 800B5930 000B2890  FC 04 00 32 */	fmul f0, f4, f0
/* 800B5934 000B2894  FC 02 00 28 */	fsub f0, f2, f0
/* 800B5938 000B2898  FC 21 00 32 */	fmul f1, f1, f0
/* 800B593C 000B289C  FC 01 00 72 */	fmul f0, f1, f1
/* 800B5940 000B28A0  FC 23 00 72 */	fmul f1, f3, f1
/* 800B5944 000B28A4  FC 04 00 32 */	fmul f0, f4, f0
/* 800B5948 000B28A8  FC 02 00 28 */	fsub f0, f2, f0
/* 800B594C 000B28AC  FC 21 00 32 */	fmul f1, f1, f0
/* 800B5950 000B28B0  FC 01 00 72 */	fmul f0, f1, f1
/* 800B5954 000B28B4  FC 23 00 72 */	fmul f1, f3, f1
/* 800B5958 000B28B8  FC 04 00 32 */	fmul f0, f4, f0
/* 800B595C 000B28BC  FC 02 00 28 */	fsub f0, f2, f0
/* 800B5960 000B28C0  FC 01 00 32 */	fmul f0, f1, f0
/* 800B5964 000B28C4  FC 04 00 32 */	fmul f0, f4, f0
/* 800B5968 000B28C8  FC 00 00 18 */	frsp f0, f0
/* 800B596C 000B28CC  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 800B5970 000B28D0  C0 81 00 38 */	lfs f4, 0x38(r1)
.L_800B5974:
/* 800B5974 000B28D4  C0 02 90 F0 */	lfs f0, lbl_803E92F0@sda21(r2)
/* 800B5978 000B28D8  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 800B597C 000B28DC  40 81 00 34 */	ble .L_800B59B0
/* 800B5980 000B28E0  C0 22 90 D8 */	lfs f1, lbl_803E92D8@sda21(r2)
/* 800B5984 000B28E4  C0 01 00 5C */	lfs f0, 0x5c(r1)
/* 800B5988 000B28E8  EC 61 20 24 */	fdivs f3, f1, f4
/* 800B598C 000B28EC  C0 21 00 60 */	lfs f1, 0x60(r1)
/* 800B5990 000B28F0  C0 41 00 64 */	lfs f2, 0x64(r1)
/* 800B5994 000B28F4  EC 00 00 F2 */	fmuls f0, f0, f3
/* 800B5998 000B28F8  EC 81 00 F2 */	fmuls f4, f1, f3
/* 800B599C 000B28FC  EC 22 00 F2 */	fmuls f1, f2, f3
/* 800B59A0 000B2900  D0 01 00 5C */	stfs f0, 0x5c(r1)
/* 800B59A4 000B2904  D0 81 00 60 */	stfs f4, 0x60(r1)
/* 800B59A8 000B2908  D0 21 00 64 */	stfs f1, 0x64(r1)
/* 800B59AC 000B290C  48 00 00 68 */	b .L_800B5A14
.L_800B59B0:
/* 800B59B0 000B2910  48 16 26 C1 */	bl rand
/* 800B59B4 000B2914  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800B59B8 000B2918  C8 82 90 E8 */	lfd f4, lbl_803E92E8@sda21(r2)
/* 800B59BC 000B291C  90 01 00 74 */	stw r0, 0x74(r1)
/* 800B59C0 000B2920  3C 00 43 30 */	lis r0, 0x4330
/* 800B59C4 000B2924  C0 62 90 DC */	lfs f3, lbl_803E92DC@sda21(r2)
/* 800B59C8 000B2928  90 01 00 70 */	stw r0, 0x70(r1)
/* 800B59CC 000B292C  C0 42 90 D8 */	lfs f2, lbl_803E92D8@sda21(r2)
/* 800B59D0 000B2930  C8 21 00 70 */	lfd f1, 0x70(r1)
/* 800B59D4 000B2934  C0 02 91 08 */	lfs f0, lbl_803E9308@sda21(r2)
/* 800B59D8 000B2938  EC 81 20 28 */	fsubs f4, f1, f4
/* 800B59DC 000B293C  C0 22 90 E4 */	lfs f1, lbl_803E92E4@sda21(r2)
/* 800B59E0 000B2940  EC 64 18 24 */	fdivs f3, f4, f3
/* 800B59E4 000B2944  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800B59E8 000B2948  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800B59EC 000B294C  EF C1 00 32 */	fmuls f30, f1, f0
/* 800B59F0 000B2950  FC 20 F0 90 */	fmr f1, f30
/* 800B59F4 000B2954  48 16 62 F5 */	bl sinf
/* 800B59F8 000B2958  FF E0 08 90 */	fmr f31, f1
/* 800B59FC 000B295C  FC 20 F0 90 */	fmr f1, f30
/* 800B5A00 000B2960  48 16 61 55 */	bl cosf
/* 800B5A04 000B2964  D0 21 00 5C */	stfs f1, 0x5c(r1)
/* 800B5A08 000B2968  C0 0D B4 74 */	lfs f0, lbl_803E0194@sda21(r13)
/* 800B5A0C 000B296C  D0 01 00 60 */	stfs f0, 0x60(r1)
/* 800B5A10 000B2970  D3 E1 00 64 */	stfs f31, 0x64(r1)
.L_800B5A14:
/* 800B5A14 000B2974  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B5A18 000B2978  38 81 00 5C */	addi r4, r1, 0x5c
/* 800B5A1C 000B297C  C0 22 90 D8 */	lfs f1, lbl_803E92D8@sda21(r2)
/* 800B5A20 000B2980  48 01 63 B9 */	bl setSpeed__4PikiFfR8Vector3f
/* 800B5A24 000B2984  38 60 00 00 */	li r3, 0
.L_800B5A28:
/* 800B5A28 000B2988  80 01 00 94 */	lwz r0, 0x94(r1)
/* 800B5A2C 000B298C  CB E1 00 88 */	lfd f31, 0x88(r1)
/* 800B5A30 000B2990  CB C1 00 80 */	lfd f30, 0x80(r1)
/* 800B5A34 000B2994  83 E1 00 7C */	lwz r31, 0x7c(r1)
/* 800B5A38 000B2998  83 C1 00 78 */	lwz r30, 0x78(r1)
/* 800B5A3C 000B299C  38 21 00 90 */	addi r1, r1, 0x90
/* 800B5A40 000B29A0  7C 08 03 A6 */	mtlr r0
/* 800B5A44 000B29A4  4E 80 00 20 */	blr 
.endfn exec__8ActChaseFv

.fn __dt__8ActChaseFv, weak
/* 800B5A48 000B29A8  7C 08 02 A6 */	mflr r0
/* 800B5A4C 000B29AC  90 01 00 04 */	stw r0, 4(r1)
/* 800B5A50 000B29B0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B5A54 000B29B4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B5A58 000B29B8  3B E4 00 00 */	addi r31, r4, 0
/* 800B5A5C 000B29BC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800B5A60 000B29C0  7C 7E 1B 79 */	or. r30, r3, r3
/* 800B5A64 000B29C4  41 82 00 2C */	beq .L_800B5A90
/* 800B5A68 000B29C8  3C 60 80 2B */	lis r3, __vt__8ActChase@ha
/* 800B5A6C 000B29CC  38 03 61 E0 */	addi r0, r3, __vt__8ActChase@l
/* 800B5A70 000B29D0  90 1E 00 00 */	stw r0, 0(r30)
/* 800B5A74 000B29D4  38 7E 00 00 */	addi r3, r30, 0
/* 800B5A78 000B29D8  38 80 00 00 */	li r4, 0
/* 800B5A7C 000B29DC  48 00 E3 8D */	bl __dt__6ActionFv
/* 800B5A80 000B29E0  7F E0 07 35 */	extsh. r0, r31
/* 800B5A84 000B29E4  40 81 00 0C */	ble .L_800B5A90
/* 800B5A88 000B29E8  7F C3 F3 78 */	mr r3, r30
/* 800B5A8C 000B29EC  4B F9 17 21 */	bl __dl__FPv
.L_800B5A90:
/* 800B5A90 000B29F0  7F C3 F3 78 */	mr r3, r30
/* 800B5A94 000B29F4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B5A98 000B29F8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B5A9C 000B29FC  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800B5AA0 000B2A00  38 21 00 18 */	addi r1, r1, 0x18
/* 800B5AA4 000B2A04  7C 08 03 A6 */	mtlr r0
/* 800B5AA8 000B2A08  4E 80 00 20 */	blr 
.endfn __dt__8ActChaseFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B6188, local
	.asciz "aiChase.cpp"
.endobj lbl_802B6188
.balign 4
.obj lbl_802B6194, local
	.asciz "aiRandomBoid"
.endobj lbl_802B6194
.balign 4
.obj lbl_802B61A4, local
	.asciz "ActChase"
.endobj lbl_802B61A4
.balign 4
.obj lbl_802B61B0, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B61B0
.balign 4
.obj lbl_802B61C0, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.endobj lbl_802B61C0
.obj lbl_802B61CC, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B61CC
.obj __vt__8ActChase, global
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
.endobj __vt__8ActChase
.balign 4
.obj lbl_802B6244, local
	.asciz "ActChase::Initialiser"
.endobj lbl_802B6244
.balign 4
.obj lbl_802B625C, local
	.asciz "Action::Initialiser"
.endobj lbl_802B625C
.balign 4
.obj lbl_802B6270, local
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte 0
.endobj lbl_802B6270
.obj __vt__Q28ActChase11Initialiser, global
	.4byte __RTTI__Q28ActChase11Initialiser
	.4byte 0
	.4byte initialise__Q28ActChase11InitialiserFP6Action
.endobj __vt__Q28ActChase11Initialiser
.obj lbl_802B6288, local
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x30)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x58)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x6C)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x80)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x94)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xA8)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xBC)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xD0)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x44)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xF8)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xE4)
.endobj lbl_802B6288

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E0188, local
	.float 0.0
.endobj lbl_803E0188
.obj lbl_803E018C, local
	.float 0.0
.endobj lbl_803E018C
.obj lbl_803E0190, local
	.float 0.0
.endobj lbl_803E0190
.obj lbl_803E0194, local
	.float 0.0
.endobj lbl_803E0194
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B61B0
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E01A0, local
	.asciz "Action"
.endobj lbl_803E01A0
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E01A0
	.4byte lbl_802B61C0
.endobj __RTTI__6Action
.obj __RTTI__8ActChase, local
	.4byte lbl_802B61A4
	.4byte lbl_802B61CC
.endobj __RTTI__8ActChase
.obj __RTTI__Q26Action11Initialiser, local
	.4byte lbl_802B625C
	.4byte 0
.endobj __RTTI__Q26Action11Initialiser
.obj __RTTI__Q28ActChase11Initialiser, local
	.4byte lbl_802B6244
	.4byte lbl_802B6270
.endobj __RTTI__Q28ActChase11Initialiser

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E92D8, local
	.float 1.0
.endobj lbl_803E92D8
.obj lbl_803E92DC, local
	.float 32767.0
.endobj lbl_803E92DC
.obj lbl_803E92E0, local
	.float 4.0
.endobj lbl_803E92E0
.obj lbl_803E92E4, local
	.float 2.0
.endobj lbl_803E92E4
.balign 8
.obj lbl_803E92E8, local
	.8byte 0x4330000080000000
.endobj lbl_803E92E8
.obj lbl_803E92F0, local
	.float 0.0
.endobj lbl_803E92F0
.balign 8
.obj lbl_803E92F8, local
	.double 0.5
.endobj lbl_803E92F8
.balign 8
.obj lbl_803E9300, local
	.double 3.0
.endobj lbl_803E9300
.obj lbl_803E9308, local
	.float 3.1415927
.endobj lbl_803E9308
