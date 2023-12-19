.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__7ActFreeFP4Piki, global
/* 800BA600 000B7560  7C 08 02 A6 */	mflr r0
/* 800BA604 000B7564  90 01 00 04 */	stw r0, 4(r1)
/* 800BA608 000B7568  7C 80 07 35 */	extsh. r0, r4
/* 800BA60C 000B756C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BA610 000B7570  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BA614 000B7574  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800BA618 000B7578  7C BE 2B 78 */	mr r30, r5
/* 800BA61C 000B757C  90 61 00 08 */	stw r3, 8(r1)
/* 800BA620 000B7580  41 82 00 1C */	beq .L_800BA63C
/* 800BA624 000B7584  80 81 00 08 */	lwz r4, 8(r1)
/* 800BA628 000B7588  3C 60 80 2B */	lis r3, __vt__19PaniAnimKeyListener@ha
/* 800BA62C 000B758C  38 03 DB 94 */	addi r0, r3, __vt__19PaniAnimKeyListener@l
/* 800BA630 000B7590  38 64 00 48 */	addi r3, r4, 0x48
/* 800BA634 000B7594  90 64 00 14 */	stw r3, 0x14(r4)
/* 800BA638 000B7598  90 04 00 48 */	stw r0, 0x48(r4)
.L_800BA63C:
/* 800BA63C 000B759C  80 61 00 08 */	lwz r3, 8(r1)
/* 800BA640 000B75A0  38 9E 00 00 */	addi r4, r30, 0
/* 800BA644 000B75A4  38 A0 00 01 */	li r5, 1
/* 800BA648 000B75A8  48 00 97 89 */	bl __ct__6ActionFP4Pikib
/* 800BA64C 000B75AC  80 E1 00 08 */	lwz r7, 8(r1)
/* 800BA650 000B75B0  3C 60 80 2B */	lis r3, __vt__7ActFree@ha
/* 800BA654 000B75B4  38 63 6A C8 */	addi r3, r3, __vt__7ActFree@l
/* 800BA658 000B75B8  90 67 00 00 */	stw r3, 0(r7)
/* 800BA65C 000B75BC  38 C3 00 68 */	addi r6, r3, 0x68
/* 800BA660 000B75C0  38 87 00 48 */	addi r4, r7, 0x48
/* 800BA664 000B75C4  80 A7 00 14 */	lwz r5, 0x14(r7)
/* 800BA668 000B75C8  38 0D B7 40 */	addi r0, r13, lbl_803E0460@sda21
/* 800BA66C 000B75CC  38 60 00 20 */	li r3, 0x20
/* 800BA670 000B75D0  90 C5 00 00 */	stw r6, 0(r5)
/* 800BA674 000B75D4  80 A7 00 14 */	lwz r5, 0x14(r7)
/* 800BA678 000B75D8  7C 85 20 50 */	subf r4, r5, r4
/* 800BA67C 000B75DC  90 85 00 04 */	stw r4, 4(r5)
/* 800BA680 000B75E0  C0 02 93 00 */	lfs f0, lbl_803E9500@sda21(r2)
/* 800BA684 000B75E4  D0 07 00 38 */	stfs f0, 0x38(r7)
/* 800BA688 000B75E8  D0 07 00 34 */	stfs f0, 0x34(r7)
/* 800BA68C 000B75EC  D0 07 00 30 */	stfs f0, 0x30(r7)
/* 800BA690 000B75F0  90 07 00 10 */	stw r0, 0x10(r7)
/* 800BA694 000B75F4  4B F8 C9 71 */	bl alloc__6SystemFUl
/* 800BA698 000B75F8  3B E3 00 00 */	addi r31, r3, 0
/* 800BA69C 000B75FC  7F E3 FB 79 */	or. r3, r31, r31
/* 800BA6A0 000B7600  41 82 00 0C */	beq .L_800BA6AC
/* 800BA6A4 000B7604  7F C4 F3 78 */	mr r4, r30
/* 800BA6A8 000B7608  4B FE FE 75 */	bl __ct__13ActFreeSelectFP4Piki
.L_800BA6AC:
/* 800BA6AC 000B760C  80 61 00 08 */	lwz r3, 8(r1)
/* 800BA6B0 000B7610  93 E3 00 18 */	stw r31, 0x18(r3)
/* 800BA6B4 000B7614  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BA6B8 000B7618  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BA6BC 000B761C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800BA6C0 000B7620  38 21 00 20 */	addi r1, r1, 0x20
/* 800BA6C4 000B7624  7C 08 03 A6 */	mtlr r0
/* 800BA6C8 000B7628  4E 80 00 20 */	blr 
.endfn __ct__7ActFreeFP4Piki

.fn initBoid__7ActFreeFR8Vector3ff, global
/* 800BA6CC 000B762C  7C 08 02 A6 */	mflr r0
/* 800BA6D0 000B7630  90 01 00 04 */	stw r0, 4(r1)
/* 800BA6D4 000B7634  38 00 00 01 */	li r0, 1
/* 800BA6D8 000B7638  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 800BA6DC 000B763C  93 E1 00 44 */	stw r31, 0x44(r1)
/* 800BA6E0 000B7640  93 C1 00 40 */	stw r30, 0x40(r1)
/* 800BA6E4 000B7644  3B C3 00 00 */	addi r30, r3, 0
/* 800BA6E8 000B7648  98 03 00 46 */	stb r0, 0x46(r3)
/* 800BA6EC 000B764C  80 64 00 00 */	lwz r3, 0(r4)
/* 800BA6F0 000B7650  80 04 00 04 */	lwz r0, 4(r4)
/* 800BA6F4 000B7654  90 7E 00 30 */	stw r3, 0x30(r30)
/* 800BA6F8 000B7658  90 1E 00 34 */	stw r0, 0x34(r30)
/* 800BA6FC 000B765C  80 04 00 08 */	lwz r0, 8(r4)
/* 800BA700 000B7660  90 1E 00 38 */	stw r0, 0x38(r30)
/* 800BA704 000B7664  D0 3E 00 3C */	stfs f1, 0x3c(r30)
/* 800BA708 000B7668  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BA70C 000B766C  80 03 02 AC */	lwz r0, 0x2ac(r3)
/* 800BA710 000B7670  28 00 00 00 */	cmplwi r0, 0
/* 800BA714 000B7674  41 82 00 3C */	beq .L_800BA750
/* 800BA718 000B7678  38 61 00 2C */	addi r3, r1, 0x2c
/* 800BA71C 000B767C  38 80 00 04 */	li r4, 4
/* 800BA720 000B7680  48 06 48 39 */	bl __ct__14PaniMotionInfoFi
/* 800BA724 000B7684  3B E3 00 00 */	addi r31, r3, 0
/* 800BA728 000B7688  38 61 00 34 */	addi r3, r1, 0x34
/* 800BA72C 000B768C  38 80 00 04 */	li r4, 4
/* 800BA730 000B7690  48 06 48 29 */	bl __ct__14PaniMotionInfoFi
/* 800BA734 000B7694  7C 64 1B 78 */	mr r4, r3
/* 800BA738 000B7698  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BA73C 000B769C  7F E5 FB 78 */	mr r5, r31
/* 800BA740 000B76A0  48 01 02 99 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800BA744 000B76A4  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BA748 000B76A8  48 01 04 C5 */	bl enableMotionBlend__4PikiFv
/* 800BA74C 000B76AC  48 00 00 30 */	b .L_800BA77C
.L_800BA750:
/* 800BA750 000B76B0  38 61 00 1C */	addi r3, r1, 0x1c
/* 800BA754 000B76B4  38 80 00 02 */	li r4, 2
/* 800BA758 000B76B8  48 06 48 01 */	bl __ct__14PaniMotionInfoFi
/* 800BA75C 000B76BC  3B E3 00 00 */	addi r31, r3, 0
/* 800BA760 000B76C0  38 61 00 24 */	addi r3, r1, 0x24
/* 800BA764 000B76C4  38 80 00 02 */	li r4, 2
/* 800BA768 000B76C8  48 06 47 F1 */	bl __ct__14PaniMotionInfoFi
/* 800BA76C 000B76CC  7C 64 1B 78 */	mr r4, r3
/* 800BA770 000B76D0  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BA774 000B76D4  7F E5 FB 78 */	mr r5, r31
/* 800BA778 000B76D8  48 01 02 61 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
.L_800BA77C:
/* 800BA77C 000B76DC  C0 02 93 04 */	lfs f0, lbl_803E9504@sda21(r2)
/* 800BA780 000B76E0  D0 1E 00 28 */	stfs f0, 0x28(r30)
/* 800BA784 000B76E4  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 800BA788 000B76E8  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 800BA78C 000B76EC  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 800BA790 000B76F0  38 21 00 48 */	addi r1, r1, 0x48
/* 800BA794 000B76F4  7C 08 03 A6 */	mtlr r0
/* 800BA798 000B76F8  4E 80 00 20 */	blr 
.endfn initBoid__7ActFreeFR8Vector3ff

.fn exeBoid__7ActFreeFv, global
/* 800BA79C 000B76FC  7C 08 02 A6 */	mflr r0
/* 800BA7A0 000B7700  90 01 00 04 */	stw r0, 4(r1)
/* 800BA7A4 000B7704  94 21 FF 50 */	stwu r1, -0xb0(r1)
/* 800BA7A8 000B7708  93 E1 00 AC */	stw r31, 0xac(r1)
/* 800BA7AC 000B770C  7C 7F 1B 78 */	mr r31, r3
/* 800BA7B0 000B7710  93 C1 00 A8 */	stw r30, 0xa8(r1)
/* 800BA7B4 000B7714  93 A1 00 A4 */	stw r29, 0xa4(r1)
/* 800BA7B8 000B7718  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800BA7BC 000B771C  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 800BA7C0 000B7720  C0 3F 00 30 */	lfs f1, 0x30(r31)
/* 800BA7C4 000B7724  C0 7F 00 34 */	lfs f3, 0x34(r31)
/* 800BA7C8 000B7728  C0 43 00 04 */	lfs f2, 4(r3)
/* 800BA7CC 000B772C  EC 01 00 28 */	fsubs f0, f1, f0
/* 800BA7D0 000B7730  C0 9F 00 38 */	lfs f4, 0x38(r31)
/* 800BA7D4 000B7734  C0 23 00 08 */	lfs f1, 8(r3)
/* 800BA7D8 000B7738  EC 43 10 28 */	fsubs f2, f3, f2
/* 800BA7DC 000B773C  D0 01 00 90 */	stfs f0, 0x90(r1)
/* 800BA7E0 000B7740  EC 04 08 28 */	fsubs f0, f4, f1
/* 800BA7E4 000B7744  D0 41 00 94 */	stfs f2, 0x94(r1)
/* 800BA7E8 000B7748  D0 01 00 98 */	stfs f0, 0x98(r1)
/* 800BA7EC 000B774C  C0 21 00 90 */	lfs f1, 0x90(r1)
/* 800BA7F0 000B7750  C0 01 00 94 */	lfs f0, 0x94(r1)
/* 800BA7F4 000B7754  C0 41 00 98 */	lfs f2, 0x98(r1)
/* 800BA7F8 000B7758  EC 21 00 72 */	fmuls f1, f1, f1
/* 800BA7FC 000B775C  EC 00 00 32 */	fmuls f0, f0, f0
/* 800BA800 000B7760  EC 42 00 B2 */	fmuls f2, f2, f2
/* 800BA804 000B7764  EC 01 00 2A */	fadds f0, f1, f0
/* 800BA808 000B7768  EC 22 00 2A */	fadds f1, f2, f0
/* 800BA80C 000B776C  4B F5 34 35 */	bl sqrtf__3stdFf
/* 800BA810 000B7770  C0 02 93 00 */	lfs f0, lbl_803E9500@sda21(r2)
/* 800BA814 000B7774  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800BA818 000B7778  41 82 00 28 */	beq .L_800BA840
/* 800BA81C 000B777C  C0 01 00 90 */	lfs f0, 0x90(r1)
/* 800BA820 000B7780  EC 00 08 24 */	fdivs f0, f0, f1
/* 800BA824 000B7784  D0 01 00 90 */	stfs f0, 0x90(r1)
/* 800BA828 000B7788  C0 01 00 94 */	lfs f0, 0x94(r1)
/* 800BA82C 000B778C  EC 00 08 24 */	fdivs f0, f0, f1
/* 800BA830 000B7790  D0 01 00 94 */	stfs f0, 0x94(r1)
/* 800BA834 000B7794  C0 01 00 98 */	lfs f0, 0x98(r1)
/* 800BA838 000B7798  EC 00 08 24 */	fdivs f0, f0, f1
/* 800BA83C 000B779C  D0 01 00 98 */	stfs f0, 0x98(r1)
.L_800BA840:
/* 800BA840 000B77A0  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800BA844 000B77A4  C0 5F 00 28 */	lfs f2, 0x28(r31)
/* 800BA848 000B77A8  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800BA84C 000B77AC  EC 02 00 28 */	fsubs f0, f2, f0
/* 800BA850 000B77B0  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 800BA854 000B77B4  C0 42 93 08 */	lfs f2, lbl_803E9508@sda21(r2)
/* 800BA858 000B77B8  C0 1F 00 3C */	lfs f0, 0x3c(r31)
/* 800BA85C 000B77BC  EC 02 00 32 */	fmuls f0, f2, f0
/* 800BA860 000B77C0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800BA864 000B77C4  41 80 00 18 */	blt .L_800BA87C
/* 800BA868 000B77C8  C0 3F 00 28 */	lfs f1, 0x28(r31)
/* 800BA86C 000B77CC  C0 02 93 00 */	lfs f0, lbl_803E9500@sda21(r2)
/* 800BA870 000B77D0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800BA874 000B77D4  4C 40 13 82 */	cror 2, 0, 2
/* 800BA878 000B77D8  40 82 00 BC */	bne .L_800BA934
.L_800BA87C:
/* 800BA87C 000B77DC  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800BA880 000B77E0  38 00 00 00 */	li r0, 0
/* 800BA884 000B77E4  80 64 00 C8 */	lwz r3, 0xc8(r4)
/* 800BA888 000B77E8  64 63 00 40 */	oris r3, r3, 0x40
/* 800BA88C 000B77EC  90 64 00 C8 */	stw r3, 0xc8(r4)
/* 800BA890 000B77F0  C0 02 93 04 */	lfs f0, lbl_803E9504@sda21(r2)
/* 800BA894 000B77F4  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 800BA898 000B77F8  98 1F 00 46 */	stb r0, 0x46(r31)
/* 800BA89C 000B77FC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BA8A0 000B7800  C0 0D B7 4C */	lfs f0, lbl_803E046C@sda21(r13)
/* 800BA8A4 000B7804  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800BA8A8 000B7808  C0 0D B7 50 */	lfs f0, lbl_803E0470@sda21(r13)
/* 800BA8AC 000B780C  D0 03 00 04 */	stfs f0, 4(r3)
/* 800BA8B0 000B7810  C0 0D B7 54 */	lfs f0, lbl_803E0474@sda21(r13)
/* 800BA8B4 000B7814  D0 03 00 08 */	stfs f0, 8(r3)
/* 800BA8B8 000B7818  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BA8BC 000B781C  80 03 02 AC */	lwz r0, 0x2ac(r3)
/* 800BA8C0 000B7820  28 00 00 00 */	cmplwi r0, 0
/* 800BA8C4 000B7824  41 82 00 80 */	beq .L_800BA944
/* 800BA8C8 000B7828  80 03 03 9C */	lwz r0, 0x39c(r3)
/* 800BA8CC 000B782C  2C 00 00 04 */	cmpwi r0, 4
/* 800BA8D0 000B7830  41 82 00 74 */	beq .L_800BA944
/* 800BA8D4 000B7834  28 1F 00 00 */	cmplwi r31, 0
/* 800BA8D8 000B7838  3B BF 00 00 */	addi r29, r31, 0
/* 800BA8DC 000B783C  41 82 00 08 */	beq .L_800BA8E4
/* 800BA8E0 000B7840  83 BF 00 14 */	lwz r29, 0x14(r31)
.L_800BA8E4:
/* 800BA8E4 000B7844  38 61 00 70 */	addi r3, r1, 0x70
/* 800BA8E8 000B7848  38 80 00 04 */	li r4, 4
/* 800BA8EC 000B784C  48 06 46 6D */	bl __ct__14PaniMotionInfoFi
/* 800BA8F0 000B7850  3B C3 00 00 */	addi r30, r3, 0
/* 800BA8F4 000B7854  38 BD 00 00 */	addi r5, r29, 0
/* 800BA8F8 000B7858  38 61 00 78 */	addi r3, r1, 0x78
/* 800BA8FC 000B785C  38 80 00 04 */	li r4, 4
/* 800BA900 000B7860  48 06 46 8D */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800BA904 000B7864  7C 64 1B 78 */	mr r4, r3
/* 800BA908 000B7868  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BA90C 000B786C  7F C5 F3 78 */	mr r5, r30
/* 800BA910 000B7870  48 01 00 C9 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800BA914 000B7874  C0 02 93 0C */	lfs f0, lbl_803E950C@sda21(r2)
/* 800BA918 000B7878  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BA91C 000B787C  D0 03 03 84 */	stfs f0, 0x384(r3)
/* 800BA920 000B7880  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BA924 000B7884  D0 03 03 D8 */	stfs f0, 0x3d8(r3)
/* 800BA928 000B7888  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BA92C 000B788C  48 01 02 E1 */	bl enableMotionBlend__4PikiFv
/* 800BA930 000B7890  48 00 00 14 */	b .L_800BA944
.L_800BA934:
/* 800BA934 000B7894  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BA938 000B7898  38 81 00 90 */	addi r4, r1, 0x90
/* 800BA93C 000B789C  C0 22 93 10 */	lfs f1, lbl_803E9510@sda21(r2)
/* 800BA940 000B78A0  48 01 14 99 */	bl setSpeed__4PikiFfR8Vector3f
.L_800BA944:
/* 800BA944 000B78A4  80 01 00 B4 */	lwz r0, 0xb4(r1)
/* 800BA948 000B78A8  83 E1 00 AC */	lwz r31, 0xac(r1)
/* 800BA94C 000B78AC  83 C1 00 A8 */	lwz r30, 0xa8(r1)
/* 800BA950 000B78B0  83 A1 00 A4 */	lwz r29, 0xa4(r1)
/* 800BA954 000B78B4  38 21 00 B0 */	addi r1, r1, 0xb0
/* 800BA958 000B78B8  7C 08 03 A6 */	mtlr r0
/* 800BA95C 000B78BC  4E 80 00 20 */	blr 
.endfn exeBoid__7ActFreeFv

.fn init__7ActFreeFP8Creature, global
/* 800BA960 000B78C0  7C 08 02 A6 */	mflr r0
/* 800BA964 000B78C4  90 01 00 04 */	stw r0, 4(r1)
/* 800BA968 000B78C8  38 00 00 00 */	li r0, 0
/* 800BA96C 000B78CC  94 21 FF 40 */	stwu r1, -0xc0(r1)
/* 800BA970 000B78D0  93 E1 00 BC */	stw r31, 0xbc(r1)
/* 800BA974 000B78D4  3B E3 00 00 */	addi r31, r3, 0
/* 800BA978 000B78D8  93 C1 00 B8 */	stw r30, 0xb8(r1)
/* 800BA97C 000B78DC  93 A1 00 B4 */	stw r29, 0xb4(r1)
/* 800BA980 000B78E0  98 03 00 46 */	stb r0, 0x46(r3)
/* 800BA984 000B78E4  C0 02 93 14 */	lfs f0, lbl_803E9514@sda21(r2)
/* 800BA988 000B78E8  D0 03 00 40 */	stfs f0, 0x40(r3)
/* 800BA98C 000B78EC  48 15 D6 E5 */	bl rand
/* 800BA990 000B78F0  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800BA994 000B78F4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BA998 000B78F8  90 01 00 AC */	stw r0, 0xac(r1)
/* 800BA99C 000B78FC  3F C0 43 30 */	lis r30, 0x4330
/* 800BA9A0 000B7900  C8 22 93 20 */	lfd f1, lbl_803E9520@sda21(r2)
/* 800BA9A4 000B7904  93 C1 00 A8 */	stw r30, 0xa8(r1)
/* 800BA9A8 000B7908  C0 62 93 18 */	lfs f3, lbl_803E9518@sda21(r2)
/* 800BA9AC 000B790C  C8 01 00 A8 */	lfd f0, 0xa8(r1)
/* 800BA9B0 000B7910  C0 42 93 14 */	lfs f2, lbl_803E9514@sda21(r2)
/* 800BA9B4 000B7914  EC 80 08 28 */	fsubs f4, f0, f1
/* 800BA9B8 000B7918  80 63 02 24 */	lwz r3, 0x224(r3)
/* 800BA9BC 000B791C  C0 02 93 04 */	lfs f0, lbl_803E9504@sda21(r2)
/* 800BA9C0 000B7920  C0 23 02 F8 */	lfs f1, 0x2f8(r3)
/* 800BA9C4 000B7924  EC 64 18 24 */	fdivs f3, f4, f3
/* 800BA9C8 000B7928  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800BA9CC 000B792C  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800BA9D0 000B7930  EC 01 00 2A */	fadds f0, f1, f0
/* 800BA9D4 000B7934  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 800BA9D8 000B7938  C0 22 93 08 */	lfs f1, lbl_803E9508@sda21(r2)
/* 800BA9DC 000B793C  C0 1F 00 28 */	lfs f0, 0x28(r31)
/* 800BA9E0 000B7940  EC 01 00 32 */	fmuls f0, f1, f0
/* 800BA9E4 000B7944  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 800BA9E8 000B7948  C0 22 93 1C */	lfs f1, lbl_803E951C@sda21(r2)
/* 800BA9EC 000B794C  C0 1F 00 28 */	lfs f0, 0x28(r31)
/* 800BA9F0 000B7950  EC 01 00 32 */	fmuls f0, f1, f0
/* 800BA9F4 000B7954  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 800BA9F8 000B7958  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BA9FC 000B795C  C0 0D B7 58 */	lfs f0, lbl_803E0478@sda21(r13)
/* 800BAA00 000B7960  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800BAA04 000B7964  C0 0D B7 5C */	lfs f0, lbl_803E047C@sda21(r13)
/* 800BAA08 000B7968  D0 03 00 04 */	stfs f0, 4(r3)
/* 800BAA0C 000B796C  C0 0D B7 60 */	lfs f0, lbl_803E0480@sda21(r13)
/* 800BAA10 000B7970  D0 03 00 08 */	stfs f0, 8(r3)
/* 800BAA14 000B7974  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BAA18 000B7978  80 03 02 AC */	lwz r0, 0x2ac(r3)
/* 800BAA1C 000B797C  28 00 00 00 */	cmplwi r0, 0
/* 800BAA20 000B7980  41 82 00 48 */	beq .L_800BAA68
/* 800BAA24 000B7984  28 1F 00 00 */	cmplwi r31, 0
/* 800BAA28 000B7988  3B BF 00 00 */	addi r29, r31, 0
/* 800BAA2C 000B798C  41 82 00 08 */	beq .L_800BAA34
/* 800BAA30 000B7990  83 BF 00 14 */	lwz r29, 0x14(r31)
.L_800BAA34:
/* 800BAA34 000B7994  38 61 00 50 */	addi r3, r1, 0x50
/* 800BAA38 000B7998  38 80 00 03 */	li r4, 3
/* 800BAA3C 000B799C  48 06 45 1D */	bl __ct__14PaniMotionInfoFi
/* 800BAA40 000B79A0  3B C3 00 00 */	addi r30, r3, 0
/* 800BAA44 000B79A4  38 BD 00 00 */	addi r5, r29, 0
/* 800BAA48 000B79A8  38 61 00 58 */	addi r3, r1, 0x58
/* 800BAA4C 000B79AC  38 80 00 03 */	li r4, 3
/* 800BAA50 000B79B0  48 06 45 3D */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800BAA54 000B79B4  7C 64 1B 78 */	mr r4, r3
/* 800BAA58 000B79B8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BAA5C 000B79BC  7F C5 F3 78 */	mr r5, r30
/* 800BAA60 000B79C0  48 00 FF 79 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800BAA64 000B79C4  48 00 00 BC */	b .L_800BAB20
.L_800BAA68:
/* 800BAA68 000B79C8  48 15 D6 09 */	bl rand
/* 800BAA6C 000B79CC  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800BAA70 000B79D0  80 6D B7 48 */	lwz r3, numMotions@sda21(r13)
/* 800BAA74 000B79D4  90 01 00 AC */	stw r0, 0xac(r1)
/* 800BAA78 000B79D8  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800BAA7C 000B79DC  C8 62 93 20 */	lfd f3, lbl_803E9520@sda21(r2)
/* 800BAA80 000B79E0  93 C1 00 A8 */	stw r30, 0xa8(r1)
/* 800BAA84 000B79E4  C0 02 93 18 */	lfs f0, lbl_803E9518@sda21(r2)
/* 800BAA88 000B79E8  C8 21 00 A8 */	lfd f1, 0xa8(r1)
/* 800BAA8C 000B79EC  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 800BAA90 000B79F0  EC 41 18 28 */	fsubs f2, f1, f3
/* 800BAA94 000B79F4  C0 22 93 14 */	lfs f1, lbl_803E9514@sda21(r2)
/* 800BAA98 000B79F8  93 C1 00 A0 */	stw r30, 0xa0(r1)
/* 800BAA9C 000B79FC  EC 42 00 24 */	fdivs f2, f2, f0
/* 800BAAA0 000B7A00  C8 01 00 A0 */	lfd f0, 0xa0(r1)
/* 800BAAA4 000B7A04  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800BAAA8 000B7A08  EC 00 18 28 */	fsubs f0, f0, f3
/* 800BAAAC 000B7A0C  EC 00 00 72 */	fmuls f0, f0, f1
/* 800BAAB0 000B7A10  FC 00 00 1E */	fctiwz f0, f0
/* 800BAAB4 000B7A14  D8 01 00 90 */	stfd f0, 0x90(r1)
/* 800BAAB8 000B7A18  80 01 00 94 */	lwz r0, 0x94(r1)
/* 800BAABC 000B7A1C  D8 01 00 98 */	stfd f0, 0x98(r1)
/* 800BAAC0 000B7A20  7C 00 18 00 */	cmpw r0, r3
/* 800BAAC4 000B7A24  80 01 00 9C */	lwz r0, 0x9c(r1)
/* 800BAAC8 000B7A28  41 80 00 08 */	blt .L_800BAAD0
/* 800BAACC 000B7A2C  38 00 00 00 */	li r0, 0
.L_800BAAD0:
/* 800BAAD0 000B7A30  28 1F 00 00 */	cmplwi r31, 0
/* 800BAAD4 000B7A34  3B BF 00 00 */	addi r29, r31, 0
/* 800BAAD8 000B7A38  41 82 00 08 */	beq .L_800BAAE0
/* 800BAADC 000B7A3C  83 BF 00 14 */	lwz r29, 0x14(r31)
.L_800BAAE0:
/* 800BAAE0 000B7A40  3C 60 80 2B */	lis r3, motions@ha
/* 800BAAE4 000B7A44  54 04 10 3A */	slwi r4, r0, 2
/* 800BAAE8 000B7A48  38 03 6A 6C */	addi r0, r3, motions@l
/* 800BAAEC 000B7A4C  7F C0 22 14 */	add r30, r0, r4
/* 800BAAF0 000B7A50  80 9E 00 00 */	lwz r4, 0(r30)
/* 800BAAF4 000B7A54  38 61 00 40 */	addi r3, r1, 0x40
/* 800BAAF8 000B7A58  48 06 44 61 */	bl __ct__14PaniMotionInfoFi
/* 800BAAFC 000B7A5C  80 9E 00 00 */	lwz r4, 0(r30)
/* 800BAB00 000B7A60  3B C3 00 00 */	addi r30, r3, 0
/* 800BAB04 000B7A64  38 BD 00 00 */	addi r5, r29, 0
/* 800BAB08 000B7A68  38 61 00 48 */	addi r3, r1, 0x48
/* 800BAB0C 000B7A6C  48 06 44 81 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800BAB10 000B7A70  7C 64 1B 78 */	mr r4, r3
/* 800BAB14 000B7A74  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BAB18 000B7A78  7F C5 F3 78 */	mr r5, r30
/* 800BAB1C 000B7A7C  48 00 FE BD */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
.L_800BAB20:
/* 800BAB20 000B7A80  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BAB24 000B7A84  48 00 EF 45 */	bl setPastel__4PikiFv
/* 800BAB28 000B7A88  38 00 00 00 */	li r0, 0
/* 800BAB2C 000B7A8C  B0 1F 00 1C */	sth r0, 0x1c(r31)
/* 800BAB30 000B7A90  38 80 00 00 */	li r4, 0
/* 800BAB34 000B7A94  98 1F 00 45 */	stb r0, 0x45(r31)
/* 800BAB38 000B7A98  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800BAB3C 000B7A9C  81 83 00 00 */	lwz r12, 0(r3)
/* 800BAB40 000B7AA0  81 8C 00 48 */	lwz r12, 0x48(r12)
/* 800BAB44 000B7AA4  7D 88 03 A6 */	mtlr r12
/* 800BAB48 000B7AA8  4E 80 00 21 */	blrl 
/* 800BAB4C 000B7AAC  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800BAB50 000B7AB0  3C 80 80 3D */	lis r4, workPikis__8GameStat@ha
/* 800BAB54 000B7AB4  3C 60 80 3D */	lis r3, freePikis__8GameStat@ha
/* 800BAB58 000B7AB8  A0 A5 05 10 */	lhz r5, 0x510(r5)
/* 800BAB5C 000B7ABC  38 84 1E 88 */	addi r4, r4, workPikis__8GameStat@l
/* 800BAB60 000B7AC0  38 03 1E 7C */	addi r0, r3, freePikis__8GameStat@l
/* 800BAB64 000B7AC4  54 A3 10 3A */	slwi r3, r5, 2
/* 800BAB68 000B7AC8  7C 84 1A 14 */	add r4, r4, r3
/* 800BAB6C 000B7ACC  80 64 00 00 */	lwz r3, 0(r4)
/* 800BAB70 000B7AD0  38 63 FF FF */	addi r3, r3, -1
/* 800BAB74 000B7AD4  90 64 00 00 */	stw r3, 0(r4)
/* 800BAB78 000B7AD8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BAB7C 000B7ADC  A0 63 05 10 */	lhz r3, 0x510(r3)
/* 800BAB80 000B7AE0  54 63 10 3A */	slwi r3, r3, 2
/* 800BAB84 000B7AE4  7C 80 1A 14 */	add r4, r0, r3
/* 800BAB88 000B7AE8  80 64 00 00 */	lwz r3, 0(r4)
/* 800BAB8C 000B7AEC  38 03 00 01 */	addi r0, r3, 1
/* 800BAB90 000B7AF0  90 04 00 00 */	stw r0, 0(r4)
/* 800BAB94 000B7AF4  48 05 79 CD */	bl update__8GameStatFv
/* 800BAB98 000B7AF8  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800BAB9C 000B7AFC  80 04 00 C8 */	lwz r0, 0xc8(r4)
/* 800BABA0 000B7B00  54 00 03 19 */	rlwinm. r0, r0, 0, 0xc, 0xc
/* 800BABA4 000B7B04  40 82 00 20 */	bne .L_800BABC4
/* 800BABA8 000B7B08  88 0D 30 6E */	lbz r0, meNukiMode__7PikiMgr@sda21(r13)
/* 800BABAC 000B7B0C  28 00 00 00 */	cmplwi r0, 0
/* 800BABB0 000B7B10  40 82 00 14 */	bne .L_800BABC4
/* 800BABB4 000B7B14  80 6D 30 38 */	lwz r3, seSystem@sda21(r13)
/* 800BABB8 000B7B18  38 A4 00 94 */	addi r5, r4, 0x94
/* 800BABBC 000B7B1C  38 80 00 FF */	li r4, 0xff
/* 800BABC0 000B7B20  4B FE 98 49 */	bl playPikiSound__8SeSystemFiR8Vector3f
.L_800BABC4:
/* 800BABC4 000B7B24  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BABC8 000B7B28  38 81 00 60 */	addi r4, r1, 0x60
/* 800BABCC 000B7B2C  C0 22 93 00 */	lfs f1, lbl_803E9500@sda21(r2)
/* 800BABD0 000B7B30  38 03 04 64 */	addi r0, r3, 0x464
/* 800BABD4 000B7B34  C0 02 93 14 */	lfs f0, lbl_803E9514@sda21(r2)
/* 800BABD8 000B7B38  D0 21 00 68 */	stfs f1, 0x68(r1)
/* 800BABDC 000B7B3C  D0 21 00 64 */	stfs f1, 0x64(r1)
/* 800BABE0 000B7B40  D0 21 00 60 */	stfs f1, 0x60(r1)
/* 800BABE4 000B7B44  D0 21 00 74 */	stfs f1, 0x74(r1)
/* 800BABE8 000B7B48  D0 21 00 70 */	stfs f1, 0x70(r1)
/* 800BABEC 000B7B4C  D0 21 00 6C */	stfs f1, 0x6c(r1)
/* 800BABF0 000B7B50  90 01 00 80 */	stw r0, 0x80(r1)
/* 800BABF4 000B7B54  D0 01 00 84 */	stfs f0, 0x84(r1)
/* 800BABF8 000B7B58  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BABFC 000B7B5C  A0 03 05 10 */	lhz r0, 0x510(r3)
/* 800BAC00 000B7B60  80 63 04 34 */	lwz r3, 0x434(r3)
/* 800BAC04 000B7B64  B0 03 00 0C */	sth r0, 0xc(r3)
/* 800BAC08 000B7B68  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BAC0C 000B7B6C  80 63 04 34 */	lwz r3, 0x434(r3)
/* 800BAC10 000B7B70  81 83 00 00 */	lwz r12, 0(r3)
/* 800BAC14 000B7B74  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 800BAC18 000B7B78  7D 88 03 A6 */	mtlr r12
/* 800BAC1C 000B7B7C  4E 80 00 21 */	blrl 
/* 800BAC20 000B7B80  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BAC24 000B7B84  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 800BAC28 000B7B88  64 00 00 40 */	oris r0, r0, 0x40
/* 800BAC2C 000B7B8C  90 03 00 C8 */	stw r0, 0xc8(r3)
/* 800BAC30 000B7B90  C0 02 93 04 */	lfs f0, lbl_803E9504@sda21(r2)
/* 800BAC34 000B7B94  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 800BAC38 000B7B98  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 800BAC3C 000B7B9C  83 E1 00 BC */	lwz r31, 0xbc(r1)
/* 800BAC40 000B7BA0  83 C1 00 B8 */	lwz r30, 0xb8(r1)
/* 800BAC44 000B7BA4  83 A1 00 B4 */	lwz r29, 0xb4(r1)
/* 800BAC48 000B7BA8  38 21 00 C0 */	addi r1, r1, 0xc0
/* 800BAC4C 000B7BAC  7C 08 03 A6 */	mtlr r0
/* 800BAC50 000B7BB0  4E 80 00 20 */	blr 
.endfn init__7ActFreeFP8Creature

.fn cleanup__7ActFreeFv, global
/* 800BAC54 000B7BB4  7C 08 02 A6 */	mflr r0
/* 800BAC58 000B7BB8  90 01 00 04 */	stw r0, 4(r1)
/* 800BAC5C 000B7BBC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BAC60 000B7BC0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BAC64 000B7BC4  7C 7F 1B 78 */	mr r31, r3
/* 800BAC68 000B7BC8  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800BAC6C 000B7BCC  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 800BAC70 000B7BD0  54 00 02 90 */	rlwinm r0, r0, 0, 0xa, 8
/* 800BAC74 000B7BD4  90 03 00 C8 */	stw r0, 0xc8(r3)
/* 800BAC78 000B7BD8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BAC7C 000B7BDC  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 800BAC80 000B7BE0  54 00 02 D2 */	rlwinm r0, r0, 0, 0xb, 9
/* 800BAC84 000B7BE4  90 03 00 C8 */	stw r0, 0xc8(r3)
/* 800BAC88 000B7BE8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BAC8C 000B7BEC  80 63 04 34 */	lwz r3, 0x434(r3)
/* 800BAC90 000B7BF0  81 83 00 00 */	lwz r12, 0(r3)
/* 800BAC94 000B7BF4  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 800BAC98 000B7BF8  7D 88 03 A6 */	mtlr r12
/* 800BAC9C 000B7BFC  4E 80 00 21 */	blrl 
/* 800BACA0 000B7C00  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800BACA4 000B7C04  3C 80 80 3D */	lis r4, workPikis__8GameStat@ha
/* 800BACA8 000B7C08  3C 60 80 3D */	lis r3, freePikis__8GameStat@ha
/* 800BACAC 000B7C0C  A0 A5 05 10 */	lhz r5, 0x510(r5)
/* 800BACB0 000B7C10  38 84 1E 88 */	addi r4, r4, workPikis__8GameStat@l
/* 800BACB4 000B7C14  38 03 1E 7C */	addi r0, r3, freePikis__8GameStat@l
/* 800BACB8 000B7C18  54 A3 10 3A */	slwi r3, r5, 2
/* 800BACBC 000B7C1C  7C 84 1A 14 */	add r4, r4, r3
/* 800BACC0 000B7C20  80 64 00 00 */	lwz r3, 0(r4)
/* 800BACC4 000B7C24  38 63 00 01 */	addi r3, r3, 1
/* 800BACC8 000B7C28  90 64 00 00 */	stw r3, 0(r4)
/* 800BACCC 000B7C2C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BACD0 000B7C30  A0 63 05 10 */	lhz r3, 0x510(r3)
/* 800BACD4 000B7C34  54 63 10 3A */	slwi r3, r3, 2
/* 800BACD8 000B7C38  7C 80 1A 14 */	add r4, r0, r3
/* 800BACDC 000B7C3C  80 64 00 00 */	lwz r3, 0(r4)
/* 800BACE0 000B7C40  38 03 FF FF */	addi r0, r3, -1
/* 800BACE4 000B7C44  90 04 00 00 */	stw r0, 0(r4)
/* 800BACE8 000B7C48  48 05 78 79 */	bl update__8GameStatFv
/* 800BACEC 000B7C4C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BACF0 000B7C50  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BACF4 000B7C54  38 21 00 20 */	addi r1, r1, 0x20
/* 800BACF8 000B7C58  7C 08 03 A6 */	mtlr r0
/* 800BACFC 000B7C5C  4E 80 00 20 */	blr 
.endfn cleanup__7ActFreeFv

.fn animationKeyUpdated__7ActFreeFR16PaniAnimKeyEvent, global
/* 800BAD00 000B7C60  4E 80 00 20 */	blr 
.endfn animationKeyUpdated__7ActFreeFR16PaniAnimKeyEvent

.fn exec__7ActFreeFv, global
/* 800BAD04 000B7C64  7C 08 02 A6 */	mflr r0
/* 800BAD08 000B7C68  90 01 00 04 */	stw r0, 4(r1)
/* 800BAD0C 000B7C6C  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 800BAD10 000B7C70  93 E1 00 7C */	stw r31, 0x7c(r1)
/* 800BAD14 000B7C74  93 C1 00 78 */	stw r30, 0x78(r1)
/* 800BAD18 000B7C78  7C 7E 1B 78 */	mr r30, r3
/* 800BAD1C 000B7C7C  C0 02 93 00 */	lfs f0, lbl_803E9500@sda21(r2)
/* 800BAD20 000B7C80  C0 23 00 40 */	lfs f1, 0x40(r3)
/* 800BAD24 000B7C84  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800BAD28 000B7C88  40 81 00 14 */	ble .L_800BAD3C
/* 800BAD2C 000B7C8C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800BAD30 000B7C90  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800BAD34 000B7C94  EC 01 00 28 */	fsubs f0, f1, f0
/* 800BAD38 000B7C98  D0 1E 00 40 */	stfs f0, 0x40(r30)
.L_800BAD3C:
/* 800BAD3C 000B7C9C  88 1E 00 45 */	lbz r0, 0x45(r30)
/* 800BAD40 000B7CA0  28 00 00 00 */	cmplwi r0, 0
/* 800BAD44 000B7CA4  41 82 00 28 */	beq .L_800BAD6C
/* 800BAD48 000B7CA8  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800BAD4C 000B7CAC  38 A0 00 1A */	li r5, 0x1a
/* 800BAD50 000B7CB0  80 64 04 90 */	lwz r3, 0x490(r4)
/* 800BAD54 000B7CB4  81 83 00 00 */	lwz r12, 0(r3)
/* 800BAD58 000B7CB8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800BAD5C 000B7CBC  7D 88 03 A6 */	mtlr r12
/* 800BAD60 000B7CC0  4E 80 00 21 */	blrl 
/* 800BAD64 000B7CC4  38 60 00 00 */	li r3, 0
/* 800BAD68 000B7CC8  48 00 00 74 */	b .L_800BADDC
.L_800BAD6C:
/* 800BAD6C 000B7CCC  88 1E 00 46 */	lbz r0, 0x46(r30)
/* 800BAD70 000B7CD0  28 00 00 00 */	cmplwi r0, 0
/* 800BAD74 000B7CD4  41 82 00 14 */	beq .L_800BAD88
/* 800BAD78 000B7CD8  7F C3 F3 78 */	mr r3, r30
/* 800BAD7C 000B7CDC  4B FF FA 21 */	bl exeBoid__7ActFreeFv
/* 800BAD80 000B7CE0  38 60 00 00 */	li r3, 0
/* 800BAD84 000B7CE4  48 00 00 58 */	b .L_800BADDC
.L_800BAD88:
/* 800BAD88 000B7CE8  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800BAD8C 000B7CEC  81 83 00 00 */	lwz r12, 0(r3)
/* 800BAD90 000B7CF0  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 800BAD94 000B7CF4  7D 88 03 A6 */	mtlr r12
/* 800BAD98 000B7CF8  4E 80 00 21 */	blrl 
/* 800BAD9C 000B7CFC  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800BADA0 000B7D00  3B E3 00 00 */	addi r31, r3, 0
/* 800BADA4 000B7D04  38 64 04 0C */	addi r3, r4, 0x40c
/* 800BADA8 000B7D08  4B FE A6 B1 */	bl updatable__13UpdateContextFv
/* 800BADAC 000B7D0C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BADB0 000B7D10  40 82 00 0C */	bne .L_800BADBC
/* 800BADB4 000B7D14  38 60 00 00 */	li r3, 0
/* 800BADB8 000B7D18  48 00 00 24 */	b .L_800BADDC
.L_800BADBC:
/* 800BADBC 000B7D1C  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BADC0 000B7D20  38 81 00 74 */	addi r4, r1, 0x74
/* 800BADC4 000B7D24  48 00 D7 B5 */	bl graspSituation__4PikiFPP8Creature
/* 800BADC8 000B7D28  2C 03 00 00 */	cmpwi r3, 0
/* 800BADCC 000B7D2C  41 82 00 0C */	beq .L_800BADD8
/* 800BADD0 000B7D30  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800BADD4 000B7D34  4B FE F9 45 */	bl finishRest__13ActFreeSelectFv
.L_800BADD8:
/* 800BADD8 000B7D38  7F E3 FB 78 */	mr r3, r31
.L_800BADDC:
/* 800BADDC 000B7D3C  80 01 00 84 */	lwz r0, 0x84(r1)
/* 800BADE0 000B7D40  83 E1 00 7C */	lwz r31, 0x7c(r1)
/* 800BADE4 000B7D44  83 C1 00 78 */	lwz r30, 0x78(r1)
/* 800BADE8 000B7D48  38 21 00 80 */	addi r1, r1, 0x80
/* 800BADEC 000B7D4C  7C 08 03 A6 */	mtlr r0
/* 800BADF0 000B7D50  4E 80 00 20 */	blr 
.endfn exec__7ActFreeFv

.fn procCollideMsg__7ActFreeFP4PikiP10MsgCollide, global
/* 800BADF4 000B7D54  7C 08 02 A6 */	mflr r0
/* 800BADF8 000B7D58  90 01 00 04 */	stw r0, 4(r1)
/* 800BADFC 000B7D5C  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800BAE00 000B7D60  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800BAE04 000B7D64  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800BAE08 000B7D68  7C 9E 23 78 */	mr r30, r4
/* 800BAE0C 000B7D6C  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 800BAE10 000B7D70  7C 7D 1B 78 */	mr r29, r3
/* 800BAE14 000B7D74  C0 02 93 00 */	lfs f0, lbl_803E9500@sda21(r2)
/* 800BAE18 000B7D78  C0 23 00 40 */	lfs f1, 0x40(r3)
/* 800BAE1C 000B7D7C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800BAE20 000B7D80  41 81 00 90 */	bgt .L_800BAEB0
/* 800BAE24 000B7D84  88 1D 00 46 */	lbz r0, 0x46(r29)
/* 800BAE28 000B7D88  28 00 00 00 */	cmplwi r0, 0
/* 800BAE2C 000B7D8C  41 82 00 08 */	beq .L_800BAE34
/* 800BAE30 000B7D90  48 00 00 80 */	b .L_800BAEB0
.L_800BAE34:
/* 800BAE34 000B7D94  83 E5 00 04 */	lwz r31, 4(r5)
/* 800BAE38 000B7D98  80 1F 00 6C */	lwz r0, 0x6c(r31)
/* 800BAE3C 000B7D9C  2C 00 00 36 */	cmpwi r0, 0x36
/* 800BAE40 000B7DA0  40 82 00 70 */	bne .L_800BAEB0
/* 800BAE44 000B7DA4  7F C3 F3 78 */	mr r3, r30
/* 800BAE48 000B7DA8  81 9E 00 00 */	lwz r12, 0(r30)
/* 800BAE4C 000B7DAC  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800BAE50 000B7DB0  7D 88 03 A6 */	mtlr r12
/* 800BAE54 000B7DB4  4E 80 00 21 */	blrl 
/* 800BAE58 000B7DB8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BAE5C 000B7DBC  40 82 00 54 */	bne .L_800BAEB0
/* 800BAE60 000B7DC0  80 1F 01 80 */	lwz r0, 0x180(r31)
/* 800BAE64 000B7DC4  28 00 00 00 */	cmplwi r0, 0
/* 800BAE68 000B7DC8  40 82 00 48 */	bne .L_800BAEB0
/* 800BAE6C 000B7DCC  88 1D 00 45 */	lbz r0, 0x45(r29)
/* 800BAE70 000B7DD0  28 00 00 00 */	cmplwi r0, 0
/* 800BAE74 000B7DD4  40 82 00 3C */	bne .L_800BAEB0
/* 800BAE78 000B7DD8  80 7E 04 3C */	lwz r3, 0x43c(r30)
/* 800BAE7C 000B7DDC  2C 03 FF FF */	cmpwi r3, -1
/* 800BAE80 000B7DE0  41 82 00 10 */	beq .L_800BAE90
/* 800BAE84 000B7DE4  80 1F 09 2C */	lwz r0, 0x92c(r31)
/* 800BAE88 000B7DE8  7C 00 18 00 */	cmpw r0, r3
/* 800BAE8C 000B7DEC  40 82 00 24 */	bne .L_800BAEB0
.L_800BAE90:
/* 800BAE90 000B7DF0  80 6D 31 78 */	lwz r3, rumbleMgr@sda21(r13)
/* 800BAE94 000B7DF4  38 80 00 02 */	li r4, 2
/* 800BAE98 000B7DF8  38 A0 00 00 */	li r5, 0
/* 800BAE9C 000B7DFC  38 C0 00 00 */	li r6, 0
/* 800BAEA0 000B7E00  48 0C 1E A9 */	bl start__9RumbleMgrFiiPf
/* 800BAEA4 000B7E04  38 00 00 01 */	li r0, 1
/* 800BAEA8 000B7E08  98 1D 00 45 */	stb r0, 0x45(r29)
/* 800BAEAC 000B7E0C  93 FE 05 04 */	stw r31, 0x504(r30)
.L_800BAEB0:
/* 800BAEB0 000B7E10  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800BAEB4 000B7E14  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800BAEB8 000B7E18  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800BAEBC 000B7E1C  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 800BAEC0 000B7E20  38 21 00 28 */	addi r1, r1, 0x28
/* 800BAEC4 000B7E24  7C 08 03 A6 */	mtlr r0
/* 800BAEC8 000B7E28  4E 80 00 20 */	blr 
.endfn procCollideMsg__7ActFreeFP4PikiP10MsgCollide

.fn __dt__7ActFreeFv, weak
/* 800BAECC 000B7E2C  7C 08 02 A6 */	mflr r0
/* 800BAED0 000B7E30  90 01 00 04 */	stw r0, 4(r1)
/* 800BAED4 000B7E34  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BAED8 000B7E38  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BAEDC 000B7E3C  3B E4 00 00 */	addi r31, r4, 0
/* 800BAEE0 000B7E40  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BAEE4 000B7E44  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BAEE8 000B7E48  41 82 00 48 */	beq .L_800BAF30
/* 800BAEEC 000B7E4C  3C 60 80 2B */	lis r3, __vt__7ActFree@ha
/* 800BAEF0 000B7E50  38 63 6A C8 */	addi r3, r3, __vt__7ActFree@l
/* 800BAEF4 000B7E54  90 7E 00 00 */	stw r3, 0(r30)
/* 800BAEF8 000B7E58  38 C3 00 68 */	addi r6, r3, 0x68
/* 800BAEFC 000B7E5C  38 1E 00 48 */	addi r0, r30, 0x48
/* 800BAF00 000B7E60  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 800BAF04 000B7E64  38 7E 00 00 */	addi r3, r30, 0
/* 800BAF08 000B7E68  38 80 00 00 */	li r4, 0
/* 800BAF0C 000B7E6C  90 C5 00 00 */	stw r6, 0(r5)
/* 800BAF10 000B7E70  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 800BAF14 000B7E74  7C 05 00 50 */	subf r0, r5, r0
/* 800BAF18 000B7E78  90 05 00 04 */	stw r0, 4(r5)
/* 800BAF1C 000B7E7C  48 00 8E ED */	bl __dt__6ActionFv
/* 800BAF20 000B7E80  7F E0 07 35 */	extsh. r0, r31
/* 800BAF24 000B7E84  40 81 00 0C */	ble .L_800BAF30
/* 800BAF28 000B7E88  7F C3 F3 78 */	mr r3, r30
/* 800BAF2C 000B7E8C  4B F8 C2 81 */	bl __dl__FPv
.L_800BAF30:
/* 800BAF30 000B7E90  7F C3 F3 78 */	mr r3, r30
/* 800BAF34 000B7E94  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BAF38 000B7E98  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BAF3C 000B7E9C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BAF40 000B7EA0  38 21 00 18 */	addi r1, r1, 0x18
/* 800BAF44 000B7EA4  7C 08 03 A6 */	mtlr r0
/* 800BAF48 000B7EA8  4E 80 00 20 */	blr 
.endfn __dt__7ActFreeFv

.fn resumable__7ActFreeFv, weak
/* 800BAF4C 000B7EAC  38 60 00 01 */	li r3, 1
/* 800BAF50 000B7EB0  4E 80 00 20 */	blr 
.endfn resumable__7ActFreeFv

.fn "@72@4@animationKeyUpdated__7ActFreeFR16PaniAnimKeyEvent", weak
/* 800BAF54 000B7EB4  39 60 00 04 */	li r11, 4
/* 800BAF58 000B7EB8  7D 63 58 2E */	lwzx r11, r3, r11
/* 800BAF5C 000B7EBC  7C 63 5A 14 */	add r3, r3, r11
/* 800BAF60 000B7EC0  38 63 FF B8 */	addi r3, r3, -72
/* 800BAF64 000B7EC4  4B FF FD 9C */	b animationKeyUpdated__7ActFreeFR16PaniAnimKeyEvent
.endfn "@72@4@animationKeyUpdated__7ActFreeFR16PaniAnimKeyEvent"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B6A60, local
	.asciz "aiFree.cpp"
.endobj lbl_802B6A60
.balign 4
.obj motions, local
	.4byte 0x28
	.4byte 0x27
	.4byte 0x41
	.4byte 0x40
.endobj motions
.balign 4
.obj lbl_802B6A7C, local
	.asciz "PaniAnimKeyListener"
.endobj lbl_802B6A7C
.balign 4
.obj lbl_802B6A90, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B6A90
.balign 4
.obj lbl_802B6AA0, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.endobj lbl_802B6AA0
.balign 4
.obj lbl_802B6AAC, local
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x00000048
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B6AAC
.balign 4
.obj __vt__7ActFree, global
	.4byte __RTTI__7ActFree
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte procCollideMsg__7ActFreeFP4PikiP10MsgCollide
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__6ActionFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__7ActFreeFv
	.4byte init__7ActFreeFP8Creature
	.4byte exec__7ActFreeFv
	.4byte cleanup__7ActFreeFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__7ActFreeFv
	.4byte getInfo__6ActionFPc
	.4byte animationKeyUpdated__7ActFreeFR16PaniAnimKeyEvent
	.4byte __RTTI__7ActFree
	.4byte 0xFFFFFFB8
	.4byte "@72@4@animationKeyUpdated__7ActFreeFR16PaniAnimKeyEvent"
.endobj __vt__7ActFree
.balign 4
.skip 0xC # compiler padding
.balign 4
.obj lbl_802B6B48, local
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
.endobj lbl_802B6B48

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E0460, local
	.asciz "free"
.endobj lbl_803E0460
.balign 4
.obj numMotions, global
	.4byte 4
.endobj numMotions
.balign 4
.obj lbl_803E046C, local
	.float 0.0
.endobj lbl_803E046C
.obj lbl_803E0470, local
	.float 0.0
.endobj lbl_803E0470
.obj lbl_803E0474, local
	.float 0.0
.endobj lbl_803E0474
.obj lbl_803E0478, local
	.float 0.0
.endobj lbl_803E0478
.obj lbl_803E047C, local
	.float 0.0
.endobj lbl_803E047C
.obj lbl_803E0480, local
	.float 0.0
.endobj lbl_803E0480
.balign 4
.obj lbl_803E0484, local
	.asciz "ActFree"
.endobj lbl_803E0484
.balign 4
.obj __RTTI__19PaniAnimKeyListener, local
	.4byte lbl_802B6A7C
	.4byte 0
.endobj __RTTI__19PaniAnimKeyListener
.balign 4
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B6A90
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E049C, local
	.asciz "Action"
.endobj lbl_803E049C
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E049C
	.4byte lbl_802B6AA0
.endobj __RTTI__6Action
.balign 4
.obj __RTTI__7ActFree, local
	.4byte lbl_803E0484
	.4byte lbl_802B6AAC
.endobj __RTTI__7ActFree

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9500, local
	.float 0.0
.endobj lbl_803E9500
.obj lbl_803E9504, local
	.float 3.0
.endobj lbl_803E9504
.obj lbl_803E9508, local
	.float 0.9
.endobj lbl_803E9508
.obj lbl_803E950C, local
	.float 18.0
.endobj lbl_803E950C
.obj lbl_803E9510, local
	.float 0.5
.endobj lbl_803E9510
.obj lbl_803E9514, local
	.float 1.0
.endobj lbl_803E9514
.obj lbl_803E9518, local
	.float 32767.0
.endobj lbl_803E9518
.obj lbl_803E951C, local
	.float 0.8
.endobj lbl_803E951C
.balign 8
.obj lbl_803E9520, local
	.8byte 0x4330000080000000
.endobj lbl_803E9520
