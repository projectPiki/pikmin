.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__10ActPulloutFP4Piki, global
/* 800BD670 000BA5D0  7C 08 02 A6 */	mflr r0
/* 800BD674 000BA5D4  38 A0 00 01 */	li r5, 1
/* 800BD678 000BA5D8  90 01 00 04 */	stw r0, 4(r1)
/* 800BD67C 000BA5DC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BD680 000BA5E0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BD684 000BA5E4  7C 9F 23 78 */	mr r31, r4
/* 800BD688 000BA5E8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800BD68C 000BA5EC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800BD690 000BA5F0  93 81 00 10 */	stw r28, 0x10(r1)
/* 800BD694 000BA5F4  90 61 00 08 */	stw r3, 8(r1)
/* 800BD698 000BA5F8  83 C1 00 08 */	lwz r30, 8(r1)
/* 800BD69C 000BA5FC  38 7E 00 00 */	addi r3, r30, 0
/* 800BD6A0 000BA600  48 00 67 31 */	bl __ct__6ActionFP4Pikib
/* 800BD6A4 000BA604  3C 60 80 2C */	lis r3, __vt__9AndAction@ha
/* 800BD6A8 000BA608  38 03 81 30 */	addi r0, r3, __vt__9AndAction@l
/* 800BD6AC 000BA60C  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD6B0 000BA610  38 80 00 00 */	li r4, 0
/* 800BD6B4 000BA614  3C 60 80 2B */	lis r3, __vt__10ActPullout@ha
/* 800BD6B8 000BA618  90 9E 00 14 */	stw r4, 0x14(r30)
/* 800BD6BC 000BA61C  38 03 72 DC */	addi r0, r3, __vt__10ActPullout@l
/* 800BD6C0 000BA620  38 60 00 24 */	li r3, 0x24
/* 800BD6C4 000BA624  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD6C8 000BA628  90 9E 00 18 */	stw r4, 0x18(r30)
/* 800BD6CC 000BA62C  4B F8 99 39 */	bl alloc__6SystemFUl
/* 800BD6D0 000BA630  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BD6D4 000BA634  41 82 00 10 */	beq .L_800BD6E4
/* 800BD6D8 000BA638  38 7E 00 00 */	addi r3, r30, 0
/* 800BD6DC 000BA63C  38 9F 00 00 */	addi r4, r31, 0
/* 800BD6E0 000BA640  4B FF D8 89 */	bl __ct__7ActGotoFP4Piki
.L_800BD6E4:
/* 800BD6E4 000BA644  38 60 00 40 */	li r3, 0x40
/* 800BD6E8 000BA648  4B F8 99 1D */	bl alloc__6SystemFUl
/* 800BD6EC 000BA64C  7C 7D 1B 79 */	or. r29, r3, r3
/* 800BD6F0 000BA650  41 82 00 10 */	beq .L_800BD700
/* 800BD6F4 000BA654  38 7D 00 00 */	addi r3, r29, 0
/* 800BD6F8 000BA658  38 9F 00 00 */	addi r4, r31, 0
/* 800BD6FC 000BA65C  4B FE A6 ED */	bl __ct__9ActAdjustFP4Piki
.L_800BD700:
/* 800BD700 000BA660  38 60 00 28 */	li r3, 0x28
/* 800BD704 000BA664  4B F8 99 01 */	bl alloc__6SystemFUl
/* 800BD708 000BA668  7C 7C 1B 79 */	or. r28, r3, r3
/* 800BD70C 000BA66C  41 82 00 10 */	beq .L_800BD71C
/* 800BD710 000BA670  38 7C 00 00 */	addi r3, r28, 0
/* 800BD714 000BA674  38 9F 00 00 */	addi r4, r31, 0
/* 800BD718 000BA678  48 00 04 C1 */	bl __ct__18ActPulloutCreatureFP4Piki
.L_800BD71C:
/* 800BD71C 000BA67C  80 61 00 08 */	lwz r3, 8(r1)
/* 800BD720 000BA680  38 BE 00 00 */	addi r5, r30, 0
/* 800BD724 000BA684  38 FD 00 00 */	addi r7, r29, 0
/* 800BD728 000BA688  4C C6 31 82 */	crclr 6
/* 800BD72C 000BA68C  39 3C 00 00 */	addi r9, r28, 0
/* 800BD730 000BA690  38 80 00 03 */	li r4, 3
/* 800BD734 000BA694  38 C0 00 00 */	li r6, 0
/* 800BD738 000BA698  39 00 00 00 */	li r8, 0
/* 800BD73C 000BA69C  39 40 00 00 */	li r10, 0
/* 800BD740 000BA6A0  48 00 6C 31 */	bl setChildren__6ActionFie
/* 800BD744 000BA6A4  80 61 00 08 */	lwz r3, 8(r1)
/* 800BD748 000BA6A8  38 00 00 00 */	li r0, 0
/* 800BD74C 000BA6AC  90 03 00 18 */	stw r0, 0x18(r3)
/* 800BD750 000BA6B0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BD754 000BA6B4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BD758 000BA6B8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800BD75C 000BA6BC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800BD760 000BA6C0  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800BD764 000BA6C4  38 21 00 20 */	addi r1, r1, 0x20
/* 800BD768 000BA6C8  7C 08 03 A6 */	mtlr r0
/* 800BD76C 000BA6CC  4E 80 00 20 */	blr 
.endfn __ct__10ActPulloutFP4Piki

.fn init__10ActPulloutFP8Creature, global
/* 800BD770 000BA6D0  7C 08 02 A6 */	mflr r0
/* 800BD774 000BA6D4  90 01 00 04 */	stw r0, 4(r1)
/* 800BD778 000BA6D8  94 21 FD F0 */	stwu r1, -0x210(r1)
/* 800BD77C 000BA6DC  DB E1 02 08 */	stfd f31, 0x208(r1)
/* 800BD780 000BA6E0  DB C1 02 00 */	stfd f30, 0x200(r1)
/* 800BD784 000BA6E4  BF 21 01 E4 */	stmw r25, 0x1e4(r1)
/* 800BD788 000BA6E8  7C 9E 23 79 */	or. r30, r4, r4
/* 800BD78C 000BA6EC  3B A3 00 00 */	addi r29, r3, 0
/* 800BD790 000BA6F0  40 82 01 B4 */	bne .L_800BD944
/* 800BD794 000BA6F4  83 6D 30 68 */	lwz r27, pikiMgr@sda21(r13)
/* 800BD798 000BA6F8  3B E0 00 00 */	li r31, 0
/* 800BD79C 000BA6FC  38 7B 00 00 */	addi r3, r27, 0
/* 800BD7A0 000BA700  81 9B 00 00 */	lwz r12, 0(r27)
/* 800BD7A4 000BA704  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800BD7A8 000BA708  7D 88 03 A6 */	mtlr r12
/* 800BD7AC 000BA70C  4E 80 00 21 */	blrl 
/* 800BD7B0 000BA710  C3 E2 93 B8 */	lfs f31, lbl_803E95B8@sda21(r2)
/* 800BD7B4 000BA714  3B 43 00 00 */	addi r26, r3, 0
/* 800BD7B8 000BA718  3B 81 00 20 */	addi r28, r1, 0x20
/* 800BD7BC 000BA71C  48 00 00 B0 */	b .L_800BD86C
.L_800BD7C0:
/* 800BD7C0 000BA720  2C 1A FF FF */	cmpwi r26, -1
/* 800BD7C4 000BA724  40 82 00 20 */	bne .L_800BD7E4
/* 800BD7C8 000BA728  7F 63 DB 78 */	mr r3, r27
/* 800BD7CC 000BA72C  81 9B 00 00 */	lwz r12, 0(r27)
/* 800BD7D0 000BA730  38 80 00 00 */	li r4, 0
/* 800BD7D4 000BA734  81 8C 00 08 */	lwz r12, 8(r12)
/* 800BD7D8 000BA738  7D 88 03 A6 */	mtlr r12
/* 800BD7DC 000BA73C  4E 80 00 21 */	blrl 
/* 800BD7E0 000BA740  48 00 00 1C */	b .L_800BD7FC
.L_800BD7E4:
/* 800BD7E4 000BA744  7F 63 DB 78 */	mr r3, r27
/* 800BD7E8 000BA748  81 9B 00 00 */	lwz r12, 0(r27)
/* 800BD7EC 000BA74C  7F 44 D3 78 */	mr r4, r26
/* 800BD7F0 000BA750  81 8C 00 08 */	lwz r12, 8(r12)
/* 800BD7F4 000BA754  7D 88 03 A6 */	mtlr r12
/* 800BD7F8 000BA758  4E 80 00 21 */	blrl 
.L_800BD7FC:
/* 800BD7FC 000BA75C  7C 79 1B 78 */	mr r25, r3
/* 800BD800 000BA760  80 9D 00 0C */	lwz r4, 0xc(r29)
/* 800BD804 000BA764  4B FC F6 79 */	bl qdist2__FP8CreatureP8Creature
/* 800BD808 000BA768  80 1D 00 0C */	lwz r0, 0xc(r29)
/* 800BD80C 000BA76C  FF C0 08 90 */	fmr f30, f1
/* 800BD810 000BA770  7C 19 00 40 */	cmplw r25, r0
/* 800BD814 000BA774  41 82 00 3C */	beq .L_800BD850
/* 800BD818 000BA778  7F 23 CB 78 */	mr r3, r25
/* 800BD81C 000BA77C  81 99 00 00 */	lwz r12, 0(r25)
/* 800BD820 000BA780  81 8C 00 80 */	lwz r12, 0x80(r12)
/* 800BD824 000BA784  7D 88 03 A6 */	mtlr r12
/* 800BD828 000BA788  4E 80 00 21 */	blrl 
/* 800BD82C 000BA78C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BD830 000BA790  41 82 00 20 */	beq .L_800BD850
/* 800BD834 000BA794  FC 1E F8 40 */	fcmpo cr0, f30, f31
/* 800BD838 000BA798  40 80 00 18 */	bge .L_800BD850
/* 800BD83C 000BA79C  2C 1F 00 64 */	cmpwi r31, 0x64
/* 800BD840 000BA7A0  40 80 00 10 */	bge .L_800BD850
/* 800BD844 000BA7A4  57 E0 10 3A */	slwi r0, r31, 2
/* 800BD848 000BA7A8  7F 3C 01 2E */	stwx r25, r28, r0
/* 800BD84C 000BA7AC  3B FF 00 01 */	addi r31, r31, 1
.L_800BD850:
/* 800BD850 000BA7B0  7F 63 DB 78 */	mr r3, r27
/* 800BD854 000BA7B4  81 9B 00 00 */	lwz r12, 0(r27)
/* 800BD858 000BA7B8  7F 44 D3 78 */	mr r4, r26
/* 800BD85C 000BA7BC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800BD860 000BA7C0  7D 88 03 A6 */	mtlr r12
/* 800BD864 000BA7C4  4E 80 00 21 */	blrl 
/* 800BD868 000BA7C8  7C 7A 1B 78 */	mr r26, r3
.L_800BD86C:
/* 800BD86C 000BA7CC  7F 63 DB 78 */	mr r3, r27
/* 800BD870 000BA7D0  81 9B 00 00 */	lwz r12, 0(r27)
/* 800BD874 000BA7D4  7F 44 D3 78 */	mr r4, r26
/* 800BD878 000BA7D8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800BD87C 000BA7DC  7D 88 03 A6 */	mtlr r12
/* 800BD880 000BA7E0  4E 80 00 21 */	blrl 
/* 800BD884 000BA7E4  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BD888 000BA7E8  41 82 00 0C */	beq .L_800BD894
/* 800BD88C 000BA7EC  38 00 00 01 */	li r0, 1
/* 800BD890 000BA7F0  48 00 00 30 */	b .L_800BD8C0
.L_800BD894:
/* 800BD894 000BA7F4  7F 63 DB 78 */	mr r3, r27
/* 800BD898 000BA7F8  81 9B 00 00 */	lwz r12, 0(r27)
/* 800BD89C 000BA7FC  7F 44 D3 78 */	mr r4, r26
/* 800BD8A0 000BA800  81 8C 00 08 */	lwz r12, 8(r12)
/* 800BD8A4 000BA804  7D 88 03 A6 */	mtlr r12
/* 800BD8A8 000BA808  4E 80 00 21 */	blrl 
/* 800BD8AC 000BA80C  28 03 00 00 */	cmplwi r3, 0
/* 800BD8B0 000BA810  40 82 00 0C */	bne .L_800BD8BC
/* 800BD8B4 000BA814  38 00 00 01 */	li r0, 1
/* 800BD8B8 000BA818  48 00 00 08 */	b .L_800BD8C0
.L_800BD8BC:
/* 800BD8BC 000BA81C  38 00 00 00 */	li r0, 0
.L_800BD8C0:
/* 800BD8C0 000BA820  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 800BD8C4 000BA824  41 82 FE FC */	beq .L_800BD7C0
/* 800BD8C8 000BA828  2C 1F 00 00 */	cmpwi r31, 0
/* 800BD8CC 000BA82C  40 81 00 78 */	ble .L_800BD944
/* 800BD8D0 000BA830  48 15 A7 A1 */	bl rand
/* 800BD8D4 000BA834  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800BD8D8 000BA838  C8 62 93 C8 */	lfd f3, lbl_803E95C8@sda21(r2)
/* 800BD8DC 000BA83C  90 01 01 DC */	stw r0, 0x1dc(r1)
/* 800BD8E0 000BA840  3C 60 43 30 */	lis r3, 0x4330
/* 800BD8E4 000BA844  6F E0 80 00 */	xoris r0, r31, 0x8000
/* 800BD8E8 000BA848  C0 02 93 C0 */	lfs f0, lbl_803E95C0@sda21(r2)
/* 800BD8EC 000BA84C  90 61 01 D8 */	stw r3, 0x1d8(r1)
/* 800BD8F0 000BA850  C0 22 93 BC */	lfs f1, lbl_803E95BC@sda21(r2)
/* 800BD8F4 000BA854  C8 41 01 D8 */	lfd f2, 0x1d8(r1)
/* 800BD8F8 000BA858  90 01 01 D4 */	stw r0, 0x1d4(r1)
/* 800BD8FC 000BA85C  EC 42 18 28 */	fsubs f2, f2, f3
/* 800BD900 000BA860  90 61 01 D0 */	stw r3, 0x1d0(r1)
/* 800BD904 000BA864  EC 42 00 24 */	fdivs f2, f2, f0
/* 800BD908 000BA868  C8 01 01 D0 */	lfd f0, 0x1d0(r1)
/* 800BD90C 000BA86C  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800BD910 000BA870  EC 00 18 28 */	fsubs f0, f0, f3
/* 800BD914 000BA874  EC 00 00 72 */	fmuls f0, f0, f1
/* 800BD918 000BA878  FC 00 00 1E */	fctiwz f0, f0
/* 800BD91C 000BA87C  D8 01 01 C0 */	stfd f0, 0x1c0(r1)
/* 800BD920 000BA880  80 01 01 C4 */	lwz r0, 0x1c4(r1)
/* 800BD924 000BA884  D8 01 01 C8 */	stfd f0, 0x1c8(r1)
/* 800BD928 000BA888  7C 00 F8 00 */	cmpw r0, r31
/* 800BD92C 000BA88C  80 01 01 CC */	lwz r0, 0x1cc(r1)
/* 800BD930 000BA890  41 80 00 08 */	blt .L_800BD938
/* 800BD934 000BA894  38 1F FF FF */	addi r0, r31, -1
.L_800BD938:
/* 800BD938 000BA898  54 00 10 3A */	slwi r0, r0, 2
/* 800BD93C 000BA89C  38 61 00 20 */	addi r3, r1, 0x20
/* 800BD940 000BA8A0  7F C3 00 2E */	lwzx r30, r3, r0
.L_800BD944:
/* 800BD944 000BA8A4  28 1E 00 00 */	cmplwi r30, 0
/* 800BD948 000BA8A8  41 82 00 44 */	beq .L_800BD98C
/* 800BD94C 000BA8AC  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 800BD950 000BA8B0  28 03 00 00 */	cmplwi r3, 0
/* 800BD954 000BA8B4  41 82 00 14 */	beq .L_800BD968
/* 800BD958 000BA8B8  41 82 00 10 */	beq .L_800BD968
/* 800BD95C 000BA8BC  48 02 6A 11 */	bl subCnt__12RefCountableFv
/* 800BD960 000BA8C0  38 00 00 00 */	li r0, 0
/* 800BD964 000BA8C4  90 1D 00 18 */	stw r0, 0x18(r29)
.L_800BD968:
/* 800BD968 000BA8C8  93 DD 00 18 */	stw r30, 0x18(r29)
/* 800BD96C 000BA8CC  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 800BD970 000BA8D0  28 03 00 00 */	cmplwi r3, 0
/* 800BD974 000BA8D4  41 82 00 08 */	beq .L_800BD97C
/* 800BD978 000BA8D8  48 02 69 E5 */	bl addCnt__12RefCountableFv
.L_800BD97C:
/* 800BD97C 000BA8DC  38 7D 00 00 */	addi r3, r29, 0
/* 800BD980 000BA8E0  38 9E 00 00 */	addi r4, r30, 0
/* 800BD984 000BA8E4  48 00 65 91 */	bl init__9AndActionFP8Creature
/* 800BD988 000BA8E8  48 00 00 1C */	b .L_800BD9A4
.L_800BD98C:
/* 800BD98C 000BA8EC  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 800BD990 000BA8F0  28 03 00 00 */	cmplwi r3, 0
/* 800BD994 000BA8F4  41 82 00 10 */	beq .L_800BD9A4
/* 800BD998 000BA8F8  48 02 69 D5 */	bl subCnt__12RefCountableFv
/* 800BD99C 000BA8FC  38 00 00 00 */	li r0, 0
/* 800BD9A0 000BA900  90 1D 00 18 */	stw r0, 0x18(r29)
.L_800BD9A4:
/* 800BD9A4 000BA904  BB 21 01 E4 */	lmw r25, 0x1e4(r1)
/* 800BD9A8 000BA908  80 01 02 14 */	lwz r0, 0x214(r1)
/* 800BD9AC 000BA90C  CB E1 02 08 */	lfd f31, 0x208(r1)
/* 800BD9B0 000BA910  CB C1 02 00 */	lfd f30, 0x200(r1)
/* 800BD9B4 000BA914  38 21 02 10 */	addi r1, r1, 0x210
/* 800BD9B8 000BA918  7C 08 03 A6 */	mtlr r0
/* 800BD9BC 000BA91C  4E 80 00 20 */	blr 
.endfn init__10ActPulloutFP8Creature

.fn exec__10ActPulloutFv, global
/* 800BD9C0 000BA920  7C 08 02 A6 */	mflr r0
/* 800BD9C4 000BA924  90 01 00 04 */	stw r0, 4(r1)
/* 800BD9C8 000BA928  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800BD9CC 000BA92C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800BD9D0 000BA930  7C 7F 1B 78 */	mr r31, r3
/* 800BD9D4 000BA934  80 03 00 18 */	lwz r0, 0x18(r3)
/* 800BD9D8 000BA938  28 00 00 00 */	cmplwi r0, 0
/* 800BD9DC 000BA93C  40 82 00 0C */	bne .L_800BD9E8
/* 800BD9E0 000BA940  38 60 00 02 */	li r3, 2
/* 800BD9E4 000BA944  48 00 00 A4 */	b .L_800BDA88
.L_800BD9E8:
/* 800BD9E8 000BA948  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BD9EC 000BA94C  88 03 05 18 */	lbz r0, 0x518(r3)
/* 800BD9F0 000BA950  28 00 00 00 */	cmplwi r0, 0
/* 800BD9F4 000BA954  41 82 00 5C */	beq .L_800BDA50
/* 800BD9F8 000BA958  80 83 05 04 */	lwz r4, 0x504(r3)
/* 800BD9FC 000BA95C  80 84 0A DC */	lwz r4, 0xadc(r4)
/* 800BDA00 000BA960  28 04 00 00 */	cmplwi r4, 0
/* 800BDA04 000BA964  41 82 00 0C */	beq .L_800BDA10
/* 800BDA08 000BA968  80 04 00 04 */	lwz r0, 4(r4)
/* 800BDA0C 000BA96C  48 00 00 08 */	b .L_800BDA14
.L_800BDA10:
/* 800BDA10 000BA970  38 00 FF FF */	li r0, -1
.L_800BDA14:
/* 800BDA14 000BA974  2C 00 00 05 */	cmpwi r0, 5
/* 800BDA18 000BA978  41 82 00 0C */	beq .L_800BDA24
/* 800BDA1C 000BA97C  38 60 00 01 */	li r3, 1
/* 800BDA20 000BA980  48 00 00 68 */	b .L_800BDA88
.L_800BDA24:
/* 800BDA24 000BA984  C0 0D B8 C0 */	lfs f0, lbl_803E05E0@sda21(r13)
/* 800BDA28 000BA988  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800BDA2C 000BA98C  C0 0D B8 C4 */	lfs f0, lbl_803E05E4@sda21(r13)
/* 800BDA30 000BA990  D0 03 00 04 */	stfs f0, 4(r3)
/* 800BDA34 000BA994  C0 0D B8 C8 */	lfs f0, lbl_803E05E8@sda21(r13)
/* 800BDA38 000BA998  D0 03 00 08 */	stfs f0, 8(r3)
/* 800BDA3C 000BA99C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDA40 000BA9A0  80 83 05 04 */	lwz r4, 0x504(r3)
/* 800BDA44 000BA9A4  38 84 00 94 */	addi r4, r4, 0x94
/* 800BDA48 000BA9A8  4B FC CF F5 */	bl turnTo__8CreatureFR8Vector3f
/* 800BDA4C 000BA9AC  48 00 00 38 */	b .L_800BDA84
.L_800BDA50:
/* 800BDA50 000BA9B0  7F E3 FB 78 */	mr r3, r31
/* 800BDA54 000BA9B4  48 00 65 A1 */	bl exec__9AndActionFv
/* 800BDA58 000BA9B8  2C 03 00 00 */	cmpwi r3, 0
/* 800BDA5C 000BA9BC  41 82 00 2C */	beq .L_800BDA88
/* 800BDA60 000BA9C0  7F E3 FB 78 */	mr r3, r31
/* 800BDA64 000BA9C4  81 9F 00 00 */	lwz r12, 0(r31)
/* 800BDA68 000BA9C8  38 80 00 00 */	li r4, 0
/* 800BDA6C 000BA9CC  81 8C 00 48 */	lwz r12, 0x48(r12)
/* 800BDA70 000BA9D0  7D 88 03 A6 */	mtlr r12
/* 800BDA74 000BA9D4  4E 80 00 21 */	blrl 
/* 800BDA78 000BA9D8  38 60 00 00 */	li r3, 0
/* 800BDA7C 000BA9DC  48 00 00 0C */	b .L_800BDA88
/* 800BDA80 000BA9E0  48 00 00 08 */	b .L_800BDA88
.L_800BDA84:
/* 800BDA84 000BA9E4  38 60 00 00 */	li r3, 0
.L_800BDA88:
/* 800BDA88 000BA9E8  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800BDA8C 000BA9EC  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800BDA90 000BA9F0  38 21 00 28 */	addi r1, r1, 0x28
/* 800BDA94 000BA9F4  7C 08 03 A6 */	mtlr r0
/* 800BDA98 000BA9F8  4E 80 00 20 */	blr 
.endfn exec__10ActPulloutFv

.fn cleanup__10ActPulloutFv, global
/* 800BDA9C 000BA9FC  7C 08 02 A6 */	mflr r0
/* 800BDAA0 000BAA00  90 01 00 04 */	stw r0, 4(r1)
/* 800BDAA4 000BAA04  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BDAA8 000BAA08  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BDAAC 000BAA0C  7C 7F 1B 78 */	mr r31, r3
/* 800BDAB0 000BAA10  48 00 69 F5 */	bl cleanup__6ActionFv
/* 800BDAB4 000BAA14  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDAB8 000BAA18  38 00 00 01 */	li r0, 1
/* 800BDABC 000BAA1C  98 03 05 18 */	stb r0, 0x518(r3)
/* 800BDAC0 000BAA20  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800BDAC4 000BAA24  28 03 00 00 */	cmplwi r3, 0
/* 800BDAC8 000BAA28  41 82 00 10 */	beq .L_800BDAD8
/* 800BDACC 000BAA2C  48 02 68 A1 */	bl subCnt__12RefCountableFv
/* 800BDAD0 000BAA30  38 00 00 00 */	li r0, 0
/* 800BDAD4 000BAA34  90 1F 00 18 */	stw r0, 0x18(r31)
.L_800BDAD8:
/* 800BDAD8 000BAA38  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BDADC 000BAA3C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BDAE0 000BAA40  38 21 00 18 */	addi r1, r1, 0x18
/* 800BDAE4 000BAA44  7C 08 03 A6 */	mtlr r0
/* 800BDAE8 000BAA48  4E 80 00 20 */	blr 
.endfn cleanup__10ActPulloutFv

.fn cleanup__18ActPulloutCreatureFv, global
/* 800BDAEC 000BAA4C  7C 08 02 A6 */	mflr r0
/* 800BDAF0 000BAA50  90 01 00 04 */	stw r0, 4(r1)
/* 800BDAF4 000BAA54  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BDAF8 000BAA58  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BDAFC 000BAA5C  7C 7F 1B 78 */	mr r31, r3
/* 800BDB00 000BAA60  88 03 00 24 */	lbz r0, 0x24(r3)
/* 800BDB04 000BAA64  28 00 00 00 */	cmplwi r0, 0
/* 800BDB08 000BAA68  40 82 00 2C */	bne .L_800BDB34
/* 800BDB0C 000BAA6C  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 800BDB10 000BAA70  28 00 00 00 */	cmplwi r0, 0
/* 800BDB14 000BAA74  7C 04 03 78 */	mr r4, r0
/* 800BDB18 000BAA78  41 82 00 1C */	beq .L_800BDB34
/* 800BDB1C 000BAA7C  80 64 04 90 */	lwz r3, 0x490(r4)
/* 800BDB20 000BAA80  38 A0 00 02 */	li r5, 2
/* 800BDB24 000BAA84  81 83 00 00 */	lwz r12, 0(r3)
/* 800BDB28 000BAA88  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800BDB2C 000BAA8C  7D 88 03 A6 */	mtlr r12
/* 800BDB30 000BAA90  4E 80 00 21 */	blrl 
.L_800BDB34:
/* 800BDB34 000BAA94  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 800BDB38 000BAA98  28 03 00 00 */	cmplwi r3, 0
/* 800BDB3C 000BAA9C  41 82 00 10 */	beq .L_800BDB4C
/* 800BDB40 000BAAA0  48 02 68 2D */	bl subCnt__12RefCountableFv
/* 800BDB44 000BAAA4  38 00 00 00 */	li r0, 0
/* 800BDB48 000BAAA8  90 1F 00 20 */	stw r0, 0x20(r31)
.L_800BDB4C:
/* 800BDB4C 000BAAAC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BDB50 000BAAB0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BDB54 000BAAB4  38 21 00 18 */	addi r1, r1, 0x18
/* 800BDB58 000BAAB8  7C 08 03 A6 */	mtlr r0
/* 800BDB5C 000BAABC  4E 80 00 20 */	blr 
.endfn cleanup__18ActPulloutCreatureFv

.fn animationKeyUpdated__18ActPulloutCreatureFR16PaniAnimKeyEvent, global
/* 800BDB60 000BAAC0  7C 08 02 A6 */	mflr r0
/* 800BDB64 000BAAC4  90 01 00 04 */	stw r0, 4(r1)
/* 800BDB68 000BAAC8  94 21 FF F8 */	stwu r1, -8(r1)
/* 800BDB6C 000BAACC  80 04 00 00 */	lwz r0, 0(r4)
/* 800BDB70 000BAAD0  2C 00 00 01 */	cmpwi r0, 1
/* 800BDB74 000BAAD4  41 82 00 54 */	beq .L_800BDBC8
/* 800BDB78 000BAAD8  40 80 00 10 */	bge .L_800BDB88
/* 800BDB7C 000BAADC  2C 00 00 00 */	cmpwi r0, 0
/* 800BDB80 000BAAE0  40 80 00 40 */	bge .L_800BDBC0
/* 800BDB84 000BAAE4  48 00 00 44 */	b .L_800BDBC8
.L_800BDB88:
/* 800BDB88 000BAAE8  2C 00 00 03 */	cmpwi r0, 3
/* 800BDB8C 000BAAEC  40 80 00 3C */	bge .L_800BDBC8
/* 800BDB90 000BAAF0  38 00 00 01 */	li r0, 1
/* 800BDB94 000BAAF4  98 03 00 24 */	stb r0, 0x24(r3)
/* 800BDB98 000BAAF8  80 03 00 20 */	lwz r0, 0x20(r3)
/* 800BDB9C 000BAAFC  28 00 00 00 */	cmplwi r0, 0
/* 800BDBA0 000BAB00  7C 03 03 78 */	mr r3, r0
/* 800BDBA4 000BAB04  41 82 00 24 */	beq .L_800BDBC8
/* 800BDBA8 000BAB08  81 83 00 00 */	lwz r12, 0(r3)
/* 800BDBAC 000BAB0C  80 83 04 B8 */	lwz r4, 0x4b8(r3)
/* 800BDBB0 000BAB10  81 8C 01 2C */	lwz r12, 0x12c(r12)
/* 800BDBB4 000BAB14  7D 88 03 A6 */	mtlr r12
/* 800BDBB8 000BAB18  4E 80 00 21 */	blrl 
/* 800BDBBC 000BAB1C  48 00 00 0C */	b .L_800BDBC8
.L_800BDBC0:
/* 800BDBC0 000BAB20  38 00 00 02 */	li r0, 2
/* 800BDBC4 000BAB24  90 03 00 18 */	stw r0, 0x18(r3)
.L_800BDBC8:
/* 800BDBC8 000BAB28  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800BDBCC 000BAB2C  38 21 00 08 */	addi r1, r1, 8
/* 800BDBD0 000BAB30  7C 08 03 A6 */	mtlr r0
/* 800BDBD4 000BAB34  4E 80 00 20 */	blr 
.endfn animationKeyUpdated__18ActPulloutCreatureFR16PaniAnimKeyEvent

.fn __ct__18ActPulloutCreatureFP4Piki, global
/* 800BDBD8 000BAB38  7C 08 02 A6 */	mflr r0
/* 800BDBDC 000BAB3C  38 A0 00 01 */	li r5, 1
/* 800BDBE0 000BAB40  90 01 00 04 */	stw r0, 4(r1)
/* 800BDBE4 000BAB44  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BDBE8 000BAB48  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BDBEC 000BAB4C  3B E3 00 00 */	addi r31, r3, 0
/* 800BDBF0 000BAB50  48 00 61 E1 */	bl __ct__6ActionFP4Pikib
/* 800BDBF4 000BAB54  3C 60 80 2B */	lis r3, __vt__19PaniAnimKeyListener@ha
/* 800BDBF8 000BAB58  38 03 DB 94 */	addi r0, r3, __vt__19PaniAnimKeyListener@l
/* 800BDBFC 000BAB5C  3C 60 80 2B */	lis r3, __vt__18ActPulloutCreature@ha
/* 800BDC00 000BAB60  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800BDC04 000BAB64  38 63 72 00 */	addi r3, r3, __vt__18ActPulloutCreature@l
/* 800BDC08 000BAB68  90 7F 00 00 */	stw r3, 0(r31)
/* 800BDC0C 000BAB6C  38 63 00 64 */	addi r3, r3, 0x64
/* 800BDC10 000BAB70  38 00 00 00 */	li r0, 0
/* 800BDC14 000BAB74  90 7F 00 14 */	stw r3, 0x14(r31)
/* 800BDC18 000BAB78  7F E3 FB 78 */	mr r3, r31
/* 800BDC1C 000BAB7C  90 1F 00 20 */	stw r0, 0x20(r31)
/* 800BDC20 000BAB80  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BDC24 000BAB84  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BDC28 000BAB88  38 21 00 18 */	addi r1, r1, 0x18
/* 800BDC2C 000BAB8C  7C 08 03 A6 */	mtlr r0
/* 800BDC30 000BAB90  4E 80 00 20 */	blr 
.endfn __ct__18ActPulloutCreatureFP4Piki

.fn init__18ActPulloutCreatureFP8Creature, global
/* 800BDC34 000BAB94  7C 08 02 A6 */	mflr r0
/* 800BDC38 000BAB98  90 01 00 04 */	stw r0, 4(r1)
/* 800BDC3C 000BAB9C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BDC40 000BABA0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BDC44 000BABA4  3B E0 00 00 */	li r31, 0
/* 800BDC48 000BABA8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800BDC4C 000BABAC  7C 9E 23 78 */	mr r30, r4
/* 800BDC50 000BABB0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800BDC54 000BABB4  3B A3 00 00 */	addi r29, r3, 0
/* 800BDC58 000BABB8  93 E3 00 18 */	stw r31, 0x18(r3)
/* 800BDC5C 000BABBC  80 63 00 20 */	lwz r3, 0x20(r3)
/* 800BDC60 000BABC0  28 03 00 00 */	cmplwi r3, 0
/* 800BDC64 000BABC4  41 82 00 10 */	beq .L_800BDC74
/* 800BDC68 000BABC8  41 82 00 0C */	beq .L_800BDC74
/* 800BDC6C 000BABCC  48 02 67 01 */	bl subCnt__12RefCountableFv
/* 800BDC70 000BABD0  93 FD 00 20 */	stw r31, 0x20(r29)
.L_800BDC74:
/* 800BDC74 000BABD4  93 DD 00 20 */	stw r30, 0x20(r29)
/* 800BDC78 000BABD8  80 7D 00 20 */	lwz r3, 0x20(r29)
/* 800BDC7C 000BABDC  28 03 00 00 */	cmplwi r3, 0
/* 800BDC80 000BABE0  41 82 00 08 */	beq .L_800BDC88
/* 800BDC84 000BABE4  48 02 66 D9 */	bl addCnt__12RefCountableFv
.L_800BDC88:
/* 800BDC88 000BABE8  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800BDC8C 000BABEC  38 00 00 00 */	li r0, 0
/* 800BDC90 000BABF0  C0 0D B8 CC */	lfs f0, lbl_803E05EC@sda21(r13)
/* 800BDC94 000BABF4  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800BDC98 000BABF8  C0 0D B8 D0 */	lfs f0, lbl_803E05F0@sda21(r13)
/* 800BDC9C 000BABFC  D0 03 00 04 */	stfs f0, 4(r3)
/* 800BDCA0 000BAC00  C0 0D B8 D4 */	lfs f0, lbl_803E05F4@sda21(r13)
/* 800BDCA4 000BAC04  D0 03 00 08 */	stfs f0, 8(r3)
/* 800BDCA8 000BAC08  98 1D 00 24 */	stb r0, 0x24(r29)
/* 800BDCAC 000BAC0C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BDCB0 000BAC10  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BDCB4 000BAC14  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800BDCB8 000BAC18  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800BDCBC 000BAC1C  38 21 00 20 */	addi r1, r1, 0x20
/* 800BDCC0 000BAC20  7C 08 03 A6 */	mtlr r0
/* 800BDCC4 000BAC24  4E 80 00 20 */	blr 
.endfn init__18ActPulloutCreatureFP8Creature

.fn exec__18ActPulloutCreatureFv, global
/* 800BDCC8 000BAC28  7C 08 02 A6 */	mflr r0
/* 800BDCCC 000BAC2C  90 01 00 04 */	stw r0, 4(r1)
/* 800BDCD0 000BAC30  94 21 FF 60 */	stwu r1, -0xa0(r1)
/* 800BDCD4 000BAC34  DB E1 00 98 */	stfd f31, 0x98(r1)
/* 800BDCD8 000BAC38  93 E1 00 94 */	stw r31, 0x94(r1)
/* 800BDCDC 000BAC3C  7C 7F 1B 78 */	mr r31, r3
/* 800BDCE0 000BAC40  93 C1 00 90 */	stw r30, 0x90(r1)
/* 800BDCE4 000BAC44  93 A1 00 8C */	stw r29, 0x8c(r1)
/* 800BDCE8 000BAC48  C0 0D B8 D8 */	lfs f0, lbl_803E05F8@sda21(r13)
/* 800BDCEC 000BAC4C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800BDCF0 000BAC50  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800BDCF4 000BAC54  C0 0D B8 DC */	lfs f0, lbl_803E05FC@sda21(r13)
/* 800BDCF8 000BAC58  D0 03 00 04 */	stfs f0, 4(r3)
/* 800BDCFC 000BAC5C  C0 0D B8 E0 */	lfs f0, lbl_803E0600@sda21(r13)
/* 800BDD00 000BAC60  D0 03 00 08 */	stfs f0, 8(r3)
/* 800BDD04 000BAC64  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 800BDD08 000BAC68  2C 00 00 01 */	cmpwi r0, 1
/* 800BDD0C 000BAC6C  41 82 01 40 */	beq .L_800BDE4C
/* 800BDD10 000BAC70  40 80 00 10 */	bge .L_800BDD20
/* 800BDD14 000BAC74  2C 00 00 00 */	cmpwi r0, 0
/* 800BDD18 000BAC78  40 80 00 18 */	bge .L_800BDD30
/* 800BDD1C 000BAC7C  48 00 01 C8 */	b .L_800BDEE4
.L_800BDD20:
/* 800BDD20 000BAC80  2C 00 00 03 */	cmpwi r0, 3
/* 800BDD24 000BAC84  40 80 01 C0 */	bge .L_800BDEE4
/* 800BDD28 000BAC88  38 60 00 02 */	li r3, 2
/* 800BDD2C 000BAC8C  48 00 01 BC */	b .L_800BDEE8
.L_800BDD30:
/* 800BDD30 000BAC90  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800BDD34 000BAC94  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 800BDD38 000BAC98  C4 24 00 94 */	lfsu f1, 0x94(r4)
/* 800BDD3C 000BAC9C  C4 63 00 94 */	lfsu f3, 0x94(r3)
/* 800BDD40 000BACA0  C0 04 00 08 */	lfs f0, 8(r4)
/* 800BDD44 000BACA4  C0 43 00 08 */	lfs f2, 8(r3)
/* 800BDD48 000BACA8  EC 23 08 28 */	fsubs f1, f3, f1
/* 800BDD4C 000BACAC  EC 42 00 28 */	fsubs f2, f2, f0
/* 800BDD50 000BACB0  48 15 DC A9 */	bl atan2f
/* 800BDD54 000BACB4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDD58 000BACB8  FF E0 08 90 */	fmr f31, f1
/* 800BDD5C 000BACBC  C0 43 00 A0 */	lfs f2, 0xa0(r3)
/* 800BDD60 000BACC0  4B F7 A8 55 */	bl angDist__Fff
/* 800BDD64 000BACC4  C0 02 93 D0 */	lfs f0, lbl_803E95D0@sda21(r2)
/* 800BDD68 000BACC8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDD6C 000BACCC  EC 20 00 72 */	fmuls f1, f0, f1
/* 800BDD70 000BACD0  C0 03 00 A0 */	lfs f0, 0xa0(r3)
/* 800BDD74 000BACD4  EC 00 08 2A */	fadds f0, f0, f1
/* 800BDD78 000BACD8  D0 03 00 A0 */	stfs f0, 0xa0(r3)
/* 800BDD7C 000BACDC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDD80 000BACE0  C0 23 00 A0 */	lfs f1, 0xa0(r3)
/* 800BDD84 000BACE4  4B F7 A8 05 */	bl roundAng__Ff
/* 800BDD88 000BACE8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDD8C 000BACEC  D0 23 00 A0 */	stfs f1, 0xa0(r3)
/* 800BDD90 000BACF0  FC 20 F8 90 */	fmr f1, f31
/* 800BDD94 000BACF4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDD98 000BACF8  C0 43 00 A0 */	lfs f2, 0xa0(r3)
/* 800BDD9C 000BACFC  4B F7 A8 19 */	bl angDist__Fff
/* 800BDDA0 000BAD00  D0 21 00 4C */	stfs f1, 0x4c(r1)
/* 800BDDA4 000BAD04  C0 02 93 D4 */	lfs f0, lbl_803E95D4@sda21(r2)
/* 800BDDA8 000BAD08  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 800BDDAC 000BAD0C  54 00 00 7E */	clrlwi r0, r0, 1
/* 800BDDB0 000BAD10  90 01 00 4C */	stw r0, 0x4c(r1)
/* 800BDDB4 000BAD14  C0 21 00 4C */	lfs f1, 0x4c(r1)
/* 800BDDB8 000BAD18  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800BDDBC 000BAD1C  40 80 01 28 */	bge .L_800BDEE4
/* 800BDDC0 000BAD20  38 00 00 01 */	li r0, 1
/* 800BDDC4 000BAD24  28 1F 00 00 */	cmplwi r31, 0
/* 800BDDC8 000BAD28  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800BDDCC 000BAD2C  7F FD FB 78 */	mr r29, r31
/* 800BDDD0 000BAD30  41 82 00 08 */	beq .L_800BDDD8
/* 800BDDD4 000BAD34  3B BD 00 14 */	addi r29, r29, 0x14
.L_800BDDD8:
/* 800BDDD8 000BAD38  38 61 00 58 */	addi r3, r1, 0x58
/* 800BDDDC 000BAD3C  38 80 00 05 */	li r4, 5
/* 800BDDE0 000BAD40  48 06 11 79 */	bl __ct__14PaniMotionInfoFi
/* 800BDDE4 000BAD44  3B C3 00 00 */	addi r30, r3, 0
/* 800BDDE8 000BAD48  38 BD 00 00 */	addi r5, r29, 0
/* 800BDDEC 000BAD4C  38 61 00 60 */	addi r3, r1, 0x60
/* 800BDDF0 000BAD50  38 80 00 05 */	li r4, 5
/* 800BDDF4 000BAD54  48 06 11 99 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800BDDF8 000BAD58  7C 64 1B 78 */	mr r4, r3
/* 800BDDFC 000BAD5C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDE00 000BAD60  7F C5 F3 78 */	mr r5, r30
/* 800BDE04 000BAD64  48 00 CB D5 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800BDE08 000BAD68  3C 60 80 2B */	lis r3, __vt__11Interaction@ha
/* 800BDE0C 000BAD6C  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800BDE10 000BAD70  38 03 CF 9C */	addi r0, r3, __vt__11Interaction@l
/* 800BDE14 000BAD74  90 01 00 50 */	stw r0, 0x50(r1)
/* 800BDE18 000BAD78  3C 60 80 2B */	lis r3, __vt__15InteractPullout@ha
/* 800BDE1C 000BAD7C  38 03 D3 04 */	addi r0, r3, __vt__15InteractPullout@l
/* 800BDE20 000BAD80  90 A1 00 54 */	stw r5, 0x54(r1)
/* 800BDE24 000BAD84  38 81 00 50 */	addi r4, r1, 0x50
/* 800BDE28 000BAD88  90 01 00 50 */	stw r0, 0x50(r1)
/* 800BDE2C 000BAD8C  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 800BDE30 000BAD90  81 83 00 00 */	lwz r12, 0(r3)
/* 800BDE34 000BAD94  81 8C 00 A0 */	lwz r12, 0xa0(r12)
/* 800BDE38 000BAD98  7D 88 03 A6 */	mtlr r12
/* 800BDE3C 000BAD9C  4E 80 00 21 */	blrl 
/* 800BDE40 000BADA0  C0 02 93 D8 */	lfs f0, lbl_803E95D8@sda21(r2)
/* 800BDE44 000BADA4  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 800BDE48 000BADA8  48 00 00 9C */	b .L_800BDEE4
.L_800BDE4C:
/* 800BDE4C 000BADAC  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800BDE50 000BADB0  3C 00 43 30 */	lis r0, 0x4330
/* 800BDE54 000BADB4  C0 3F 00 1C */	lfs f1, 0x1c(r31)
/* 800BDE58 000BADB8  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800BDE5C 000BADBC  83 BF 00 20 */	lwz r29, 0x20(r31)
/* 800BDE60 000BADC0  EC 01 00 2A */	fadds f0, f1, f0
/* 800BDE64 000BADC4  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 800BDE68 000BADC8  80 7D 04 B8 */	lwz r3, 0x4b8(r29)
/* 800BDE6C 000BADCC  C8 22 93 C8 */	lfd f1, lbl_803E95C8@sda21(r2)
/* 800BDE70 000BADD0  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 800BDE74 000BADD4  C0 5F 00 1C */	lfs f2, 0x1c(r31)
/* 800BDE78 000BADD8  90 61 00 84 */	stw r3, 0x84(r1)
/* 800BDE7C 000BADDC  90 01 00 80 */	stw r0, 0x80(r1)
/* 800BDE80 000BADE0  C8 01 00 80 */	lfd f0, 0x80(r1)
/* 800BDE84 000BADE4  EC 00 08 28 */	fsubs f0, f0, f1
/* 800BDE88 000BADE8  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 800BDE8C 000BADEC  4C 41 13 82 */	cror 2, 1, 2
/* 800BDE90 000BADF0  40 82 00 38 */	bne .L_800BDEC8
/* 800BDE94 000BADF4  28 1F 00 00 */	cmplwi r31, 0
/* 800BDE98 000BADF8  38 9F 00 00 */	addi r4, r31, 0
/* 800BDE9C 000BADFC  41 82 00 08 */	beq .L_800BDEA4
/* 800BDEA0 000BAE00  38 84 00 14 */	addi r4, r4, 0x14
.L_800BDEA4:
/* 800BDEA4 000BAE04  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDEA8 000BAE08  38 63 03 54 */	addi r3, r3, 0x354
/* 800BDEAC 000BAE0C  48 06 1C 15 */	bl finishMotion__15PaniPikiAnimMgrFP19PaniAnimKeyListener
/* 800BDEB0 000BAE10  28 1D 00 00 */	cmplwi r29, 0
/* 800BDEB4 000BAE14  38 9D 00 00 */	addi r4, r29, 0
/* 800BDEB8 000BAE18  41 82 00 08 */	beq .L_800BDEC0
/* 800BDEBC 000BAE1C  38 84 02 B8 */	addi r4, r4, 0x2b8
.L_800BDEC0:
/* 800BDEC0 000BAE20  38 7D 03 54 */	addi r3, r29, 0x354
/* 800BDEC4 000BAE24  48 06 1B FD */	bl finishMotion__15PaniPikiAnimMgrFP19PaniAnimKeyListener
.L_800BDEC8:
/* 800BDEC8 000BAE28  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BDECC 000BAE2C  C0 0D B8 E4 */	lfs f0, lbl_803E0604@sda21(r13)
/* 800BDED0 000BAE30  D4 03 00 70 */	stfsu f0, 0x70(r3)
/* 800BDED4 000BAE34  C0 0D B8 E8 */	lfs f0, lbl_803E0608@sda21(r13)
/* 800BDED8 000BAE38  D0 03 00 04 */	stfs f0, 4(r3)
/* 800BDEDC 000BAE3C  C0 0D B8 EC */	lfs f0, lbl_803E060C@sda21(r13)
/* 800BDEE0 000BAE40  D0 03 00 08 */	stfs f0, 8(r3)
.L_800BDEE4:
/* 800BDEE4 000BAE44  38 60 00 00 */	li r3, 0
.L_800BDEE8:
/* 800BDEE8 000BAE48  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 800BDEEC 000BAE4C  CB E1 00 98 */	lfd f31, 0x98(r1)
/* 800BDEF0 000BAE50  83 E1 00 94 */	lwz r31, 0x94(r1)
/* 800BDEF4 000BAE54  83 C1 00 90 */	lwz r30, 0x90(r1)
/* 800BDEF8 000BAE58  83 A1 00 8C */	lwz r29, 0x8c(r1)
/* 800BDEFC 000BAE5C  38 21 00 A0 */	addi r1, r1, 0xa0
/* 800BDF00 000BAE60  7C 08 03 A6 */	mtlr r0
/* 800BDF04 000BAE64  4E 80 00 20 */	blr 
.endfn exec__18ActPulloutCreatureFv

.fn __dt__18ActPulloutCreatureFv, weak
/* 800BDF08 000BAE68  7C 08 02 A6 */	mflr r0
/* 800BDF0C 000BAE6C  90 01 00 04 */	stw r0, 4(r1)
/* 800BDF10 000BAE70  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BDF14 000BAE74  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BDF18 000BAE78  3B E4 00 00 */	addi r31, r4, 0
/* 800BDF1C 000BAE7C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BDF20 000BAE80  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BDF24 000BAE84  41 82 00 34 */	beq .L_800BDF58
/* 800BDF28 000BAE88  3C 60 80 2B */	lis r3, __vt__18ActPulloutCreature@ha
/* 800BDF2C 000BAE8C  38 63 72 00 */	addi r3, r3, __vt__18ActPulloutCreature@l
/* 800BDF30 000BAE90  90 7E 00 00 */	stw r3, 0(r30)
/* 800BDF34 000BAE94  38 03 00 64 */	addi r0, r3, 0x64
/* 800BDF38 000BAE98  38 7E 00 00 */	addi r3, r30, 0
/* 800BDF3C 000BAE9C  90 1E 00 14 */	stw r0, 0x14(r30)
/* 800BDF40 000BAEA0  38 80 00 00 */	li r4, 0
/* 800BDF44 000BAEA4  48 00 5E C5 */	bl __dt__6ActionFv
/* 800BDF48 000BAEA8  7F E0 07 35 */	extsh. r0, r31
/* 800BDF4C 000BAEAC  40 81 00 0C */	ble .L_800BDF58
/* 800BDF50 000BAEB0  7F C3 F3 78 */	mr r3, r30
/* 800BDF54 000BAEB4  4B F8 92 59 */	bl __dl__FPv
.L_800BDF58:
/* 800BDF58 000BAEB8  7F C3 F3 78 */	mr r3, r30
/* 800BDF5C 000BAEBC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BDF60 000BAEC0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BDF64 000BAEC4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BDF68 000BAEC8  38 21 00 18 */	addi r1, r1, 0x18
/* 800BDF6C 000BAECC  7C 08 03 A6 */	mtlr r0
/* 800BDF70 000BAED0  4E 80 00 20 */	blr 
.endfn __dt__18ActPulloutCreatureFv

.fn __dt__10ActPulloutFv, weak
/* 800BDF74 000BAED4  7C 08 02 A6 */	mflr r0
/* 800BDF78 000BAED8  90 01 00 04 */	stw r0, 4(r1)
/* 800BDF7C 000BAEDC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BDF80 000BAEE0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BDF84 000BAEE4  3B E4 00 00 */	addi r31, r4, 0
/* 800BDF88 000BAEE8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BDF8C 000BAEEC  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BDF90 000BAEF0  41 82 00 3C */	beq .L_800BDFCC
/* 800BDF94 000BAEF4  3C 60 80 2B */	lis r3, __vt__10ActPullout@ha
/* 800BDF98 000BAEF8  38 03 72 DC */	addi r0, r3, __vt__10ActPullout@l
/* 800BDF9C 000BAEFC  90 1E 00 00 */	stw r0, 0(r30)
/* 800BDFA0 000BAF00  41 82 00 1C */	beq .L_800BDFBC
/* 800BDFA4 000BAF04  3C 60 80 2C */	lis r3, __vt__9AndAction@ha
/* 800BDFA8 000BAF08  38 03 81 30 */	addi r0, r3, __vt__9AndAction@l
/* 800BDFAC 000BAF0C  90 1E 00 00 */	stw r0, 0(r30)
/* 800BDFB0 000BAF10  38 7E 00 00 */	addi r3, r30, 0
/* 800BDFB4 000BAF14  38 80 00 00 */	li r4, 0
/* 800BDFB8 000BAF18  48 00 5E 51 */	bl __dt__6ActionFv
.L_800BDFBC:
/* 800BDFBC 000BAF1C  7F E0 07 35 */	extsh. r0, r31
/* 800BDFC0 000BAF20  40 81 00 0C */	ble .L_800BDFCC
/* 800BDFC4 000BAF24  7F C3 F3 78 */	mr r3, r30
/* 800BDFC8 000BAF28  4B F8 91 E5 */	bl __dl__FPv
.L_800BDFCC:
/* 800BDFCC 000BAF2C  7F C3 F3 78 */	mr r3, r30
/* 800BDFD0 000BAF30  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BDFD4 000BAF34  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BDFD8 000BAF38  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BDFDC 000BAF3C  38 21 00 18 */	addi r1, r1, 0x18
/* 800BDFE0 000BAF40  7C 08 03 A6 */	mtlr r0
/* 800BDFE4 000BAF44  4E 80 00 20 */	blr 
.endfn __dt__10ActPulloutFv

.fn "@20@animationKeyUpdated__18ActPulloutCreatureFR16PaniAnimKeyEvent", weak
/* 800BDFE8 000BAF48  38 63 FF EC */	addi r3, r3, -20
/* 800BDFEC 000BAF4C  4B FF FB 74 */	b animationKeyUpdated__18ActPulloutCreatureFR16PaniAnimKeyEvent
.endfn "@20@animationKeyUpdated__18ActPulloutCreatureFR16PaniAnimKeyEvent"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B7168, local
	.asciz "aiPullout.cpp"
.endobj lbl_802B7168
.balign 4
.obj lbl_802B7178, local
	.asciz "aiPullout"
.endobj lbl_802B7178
.balign 4
.obj lbl_802B7184, local
	.asciz "Interaction"
.endobj lbl_802B7184
.balign 4
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
.obj lbl_802B71BC, local
	.asciz "ActPulloutCreature"
.endobj lbl_802B71BC
.balign 4
.obj lbl_802B71D0, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B71D0
.balign 4
.obj lbl_802B71E0, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.endobj lbl_802B71E0
.balign 4
.obj lbl_802B71EC, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B71EC
.balign 4
.obj __vt__18ActPulloutCreature, global
	.4byte __RTTI__18ActPulloutCreature
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
	.4byte __dt__18ActPulloutCreatureFv
	.4byte init__18ActPulloutCreatureFP8Creature
	.4byte exec__18ActPulloutCreatureFv
	.4byte cleanup__18ActPulloutCreatureFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
	.4byte __RTTI__18ActPulloutCreature
	.4byte 0xFFFFFFEC
	.4byte "@20@animationKeyUpdated__18ActPulloutCreatureFR16PaniAnimKeyEvent"
	.4byte animationKeyUpdated__18ActPulloutCreatureFR16PaniAnimKeyEvent
.endobj __vt__18ActPulloutCreature
.balign 4
.obj lbl_802B7274, local
	.asciz "PaniAnimKeyListener"
.endobj lbl_802B7274
.balign 4
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
.obj lbl_802B7294, local
	.asciz "ActPullout"
.endobj lbl_802B7294
.balign 4
.obj lbl_802B72A0, local
	.asciz "AndAction"
.endobj lbl_802B72A0
.balign 4
.obj lbl_802B72AC, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B72AC
.balign 4
.obj lbl_802B72C0, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte __RTTI__9AndAction
	.4byte 0
	.4byte 0
.endobj lbl_802B72C0
.balign 4
.obj __vt__10ActPullout, global
	.4byte __RTTI__10ActPullout
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
	.4byte __dt__10ActPulloutFv
	.4byte init__10ActPulloutFP8Creature
	.4byte exec__10ActPulloutFv
	.4byte cleanup__10ActPulloutFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
.endobj __vt__10ActPullout
.balign 4
.obj lbl_802B7340, local
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
.endobj lbl_802B7340

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E05E0, local
	.float 0.0
.endobj lbl_803E05E0
.obj lbl_803E05E4, local
	.float 0.0
.endobj lbl_803E05E4
.obj lbl_803E05E8, local
	.float 0.0
.endobj lbl_803E05E8
.obj lbl_803E05EC, local
	.float 0.0
.endobj lbl_803E05EC
.obj lbl_803E05F0, local
	.float 0.0
.endobj lbl_803E05F0
.obj lbl_803E05F4, local
	.float 0.0
.endobj lbl_803E05F4
.obj lbl_803E05F8, local
	.float 0.0
.endobj lbl_803E05F8
.obj lbl_803E05FC, local
	.float 0.0
.endobj lbl_803E05FC
.obj lbl_803E0600, local
	.float 0.0
.endobj lbl_803E0600
.obj lbl_803E0604, local
	.float 0.0
.endobj lbl_803E0604
.obj lbl_803E0608, local
	.float 0.0
.endobj lbl_803E0608
.obj lbl_803E060C, local
	.float 0.0
.endobj lbl_803E060C
.balign 4
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B71D0
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E0618, local
	.asciz "Action"
.endobj lbl_803E0618
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E0618
	.4byte lbl_802B71E0
.endobj __RTTI__6Action
.obj __RTTI__18ActPulloutCreature, local
	.4byte lbl_802B71BC
	.4byte lbl_802B71EC
.endobj __RTTI__18ActPulloutCreature
.obj __RTTI__9AndAction, local
	.4byte lbl_802B72A0
	.4byte lbl_802B72AC
.endobj __RTTI__9AndAction
.obj __RTTI__10ActPullout, local
	.4byte lbl_802B7294
	.4byte lbl_802B72C0
.endobj __RTTI__10ActPullout

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E95B8, local
	.float 300.0
.endobj lbl_803E95B8
.obj lbl_803E95BC, local
	.float 1.0
.endobj lbl_803E95BC
.obj lbl_803E95C0, local
	.float 32767.0
.endobj lbl_803E95C0
.balign 8
.obj lbl_803E95C8, local
	.8byte 0x4330000080000000
.endobj lbl_803E95C8
.obj lbl_803E95D0, local
	.float 0.4
.endobj lbl_803E95D0
.obj lbl_803E95D4, local
	.float 0.1
.endobj lbl_803E95D4
.obj lbl_803E95D8, local
	.float 0.0
.endobj lbl_803E95D8
