.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__5YTekiFv
__ct__5YTekiFv:
/* 801A2754 0019F6B4  7C 08 02 A6 */	mflr r0
/* 801A2758 0019F6B8  90 01 00 04 */	stw r0, 4(r1)
/* 801A275C 0019F6BC  7C 80 07 35 */	extsh. r0, r4
/* 801A2760 0019F6C0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A2764 0019F6C4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A2768 0019F6C8  3B E3 00 00 */	addi r31, r3, 0
/* 801A276C 0019F6CC  41 82 00 18 */	beq lbl_801A2784
/* 801A2770 0019F6D0  38 1F 05 38 */	addi r0, r31, 0x538
/* 801A2774 0019F6D4  3C 60 80 2B */	lis r3, __vt__19PaniAnimKeyListener@ha
/* 801A2778 0019F6D8  90 1F 02 C0 */	stw r0, 0x2c0(r31)
/* 801A277C 0019F6DC  38 03 DB 94 */	addi r0, r3, __vt__19PaniAnimKeyListener@l
/* 801A2780 0019F6E0  90 1F 05 38 */	stw r0, 0x538(r31)
lbl_801A2784:
/* 801A2784 0019F6E4  38 7F 00 00 */	addi r3, r31, 0
/* 801A2788 0019F6E8  38 80 00 00 */	li r4, 0
/* 801A278C 0019F6EC  4B FA 92 6D */	bl __ct__5NTekiFv
/* 801A2790 0019F6F0  3C 60 80 2E */	lis r3, __vt__5YTeki@ha
/* 801A2794 0019F6F4  38 83 D9 E4 */	addi r4, r3, __vt__5YTeki@l
/* 801A2798 0019F6F8  90 9F 00 00 */	stw r4, 0(r31)
/* 801A279C 0019F6FC  3C 60 80 2E */	lis r3, __vt__28TAIeffectAttackEventCallBack@ha
/* 801A27A0 0019F700  38 04 01 F4 */	addi r0, r4, 0x1f4
/* 801A27A4 0019F704  80 DF 02 C0 */	lwz r6, 0x2c0(r31)
/* 801A27A8 0019F708  38 A4 01 14 */	addi r5, r4, 0x114
/* 801A27AC 0019F70C  38 9F 05 38 */	addi r4, r31, 0x538
/* 801A27B0 0019F710  90 06 00 00 */	stw r0, 0(r6)
/* 801A27B4 0019F714  38 03 DC 3C */	addi r0, r3, __vt__28TAIeffectAttackEventCallBack@l
/* 801A27B8 0019F718  38 7F 04 CC */	addi r3, r31, 0x4cc
/* 801A27BC 0019F71C  90 BF 02 B8 */	stw r5, 0x2b8(r31)
/* 801A27C0 0019F720  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
/* 801A27C4 0019F724  7C 85 20 50 */	subf r4, r5, r4
/* 801A27C8 0019F728  90 85 00 04 */	stw r4, 4(r5)
/* 801A27CC 0019F72C  C0 02 B4 30 */	lfs f0, lbl_803EB630@sda21(r2)
/* 801A27D0 0019F730  D0 1F 04 E4 */	stfs f0, 0x4e4(r31)
/* 801A27D4 0019F734  D0 1F 04 E0 */	stfs f0, 0x4e0(r31)
/* 801A27D8 0019F738  D0 1F 04 DC */	stfs f0, 0x4dc(r31)
/* 801A27DC 0019F73C  D0 1F 04 F0 */	stfs f0, 0x4f0(r31)
/* 801A27E0 0019F740  D0 1F 04 EC */	stfs f0, 0x4ec(r31)
/* 801A27E4 0019F744  D0 1F 04 E8 */	stfs f0, 0x4e8(r31)
/* 801A27E8 0019F748  D0 1F 04 FC */	stfs f0, 0x4fc(r31)
/* 801A27EC 0019F74C  D0 1F 04 F8 */	stfs f0, 0x4f8(r31)
/* 801A27F0 0019F750  D0 1F 04 F4 */	stfs f0, 0x4f4(r31)
/* 801A27F4 0019F754  90 1F 05 14 */	stw r0, 0x514(r31)
/* 801A27F8 0019F758  48 00 00 55 */	bl init__20TAIeffectAttackParamFv
/* 801A27FC 0019F75C  3C 60 80 2B */	lis r3, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 801A2800 0019F760  38 A3 06 00 */	addi r5, r3, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 801A2804 0019F764  3C 60 80 2E */	lis r3, __vt__16ConeTypeCallBack@ha
/* 801A2808 0019F768  90 BF 05 1C */	stw r5, 0x51c(r31)
/* 801A280C 0019F76C  38 03 17 E8 */	addi r0, r3, __vt__16ConeTypeCallBack@l
/* 801A2810 0019F770  90 1F 05 1C */	stw r0, 0x51c(r31)
/* 801A2814 0019F774  3C 80 80 2E */	lis r4, __vt__20CylinderTypeCallBack@ha
/* 801A2818 0019F778  3C 60 80 2E */	lis r3, __vt__17EventTypeCallBack@ha
/* 801A281C 0019F77C  90 BF 05 28 */	stw r5, 0x528(r31)
/* 801A2820 0019F780  38 84 18 18 */	addi r4, r4, __vt__20CylinderTypeCallBack@l
/* 801A2824 0019F784  38 03 18 44 */	addi r0, r3, __vt__17EventTypeCallBack@l
/* 801A2828 0019F788  90 9F 05 28 */	stw r4, 0x528(r31)
/* 801A282C 0019F78C  7F E3 FB 78 */	mr r3, r31
/* 801A2830 0019F790  90 BF 05 30 */	stw r5, 0x530(r31)
/* 801A2834 0019F794  90 1F 05 30 */	stw r0, 0x530(r31)
/* 801A2838 0019F798  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A283C 0019F79C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A2840 0019F7A0  38 21 00 18 */	addi r1, r1, 0x18
/* 801A2844 0019F7A4  7C 08 03 A6 */	mtlr r0
/* 801A2848 0019F7A8  4E 80 00 20 */	blr 

.global init__20TAIeffectAttackParamFv
init__20TAIeffectAttackParamFv:
/* 801A284C 0019F7AC  38 80 00 00 */	li r4, 0
/* 801A2850 0019F7B0  90 83 00 38 */	stw r4, 0x38(r3)
/* 801A2854 0019F7B4  38 03 00 48 */	addi r0, r3, 0x48
/* 801A2858 0019F7B8  C0 22 B4 30 */	lfs f1, lbl_803EB630@sda21(r2)
/* 801A285C 0019F7BC  D0 23 00 00 */	stfs f1, 0(r3)
/* 801A2860 0019F7C0  D0 23 00 04 */	stfs f1, 4(r3)
/* 801A2864 0019F7C4  D0 23 00 0C */	stfs f1, 0xc(r3)
/* 801A2868 0019F7C8  C0 0D 11 68 */	lfs f0, lbl_803E5E88@sda21(r13)
/* 801A286C 0019F7CC  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 801A2870 0019F7D0  C0 0D 11 6C */	lfs f0, lbl_803E5E8C@sda21(r13)
/* 801A2874 0019F7D4  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 801A2878 0019F7D8  C0 0D 11 70 */	lfs f0, lbl_803E5E90@sda21(r13)
/* 801A287C 0019F7DC  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 801A2880 0019F7E0  C0 0D 11 74 */	lfs f0, lbl_803E5E94@sda21(r13)
/* 801A2884 0019F7E4  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 801A2888 0019F7E8  C0 0D 11 78 */	lfs f0, lbl_803E5E98@sda21(r13)
/* 801A288C 0019F7EC  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 801A2890 0019F7F0  C0 0D 11 7C */	lfs f0, lbl_803E5E9C@sda21(r13)
/* 801A2894 0019F7F4  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 801A2898 0019F7F8  C0 0D 11 80 */	lfs f0, lbl_803E5EA0@sda21(r13)
/* 801A289C 0019F7FC  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 801A28A0 0019F800  C0 0D 11 84 */	lfs f0, lbl_803E5EA4@sda21(r13)
/* 801A28A4 0019F804  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 801A28A8 0019F808  C0 0D 11 88 */	lfs f0, lbl_803E5EA8@sda21(r13)
/* 801A28AC 0019F80C  D0 03 00 30 */	stfs f0, 0x30(r3)
/* 801A28B0 0019F810  D0 23 00 34 */	stfs f1, 0x34(r3)
/* 801A28B4 0019F814  90 83 00 40 */	stw r4, 0x40(r3)
/* 801A28B8 0019F818  90 83 00 3C */	stw r4, 0x3c(r3)
/* 801A28BC 0019F81C  90 03 00 44 */	stw r0, 0x44(r3)
/* 801A28C0 0019F820  98 83 00 4C */	stb r4, 0x4c(r3)
/* 801A28C4 0019F824  C0 02 B4 34 */	lfs f0, lbl_803EB634@sda21(r2)
/* 801A28C8 0019F828  D0 03 00 08 */	stfs f0, 8(r3)
/* 801A28CC 0019F82C  4E 80 00 20 */	blr 

.global doKill__5YTekiFv
doKill__5YTekiFv:
/* 801A28D0 0019F830  7C 08 02 A6 */	mflr r0
/* 801A28D4 0019F834  90 01 00 04 */	stw r0, 4(r1)
/* 801A28D8 0019F838  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A28DC 0019F83C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A28E0 0019F840  7C 7F 1B 78 */	mr r31, r3
/* 801A28E4 0019F844  4B FA 2E 55 */	bl doKill__5BTekiFv
/* 801A28E8 0019F848  80 9F 04 98 */	lwz r4, 0x498(r31)
/* 801A28EC 0019F84C  28 04 00 00 */	cmplwi r4, 0
/* 801A28F0 0019F850  41 82 00 10 */	beq lbl_801A2900
/* 801A28F4 0019F854  80 04 00 80 */	lwz r0, 0x80(r4)
/* 801A28F8 0019F858  60 00 00 02 */	ori r0, r0, 2
/* 801A28FC 0019F85C  90 04 00 80 */	stw r0, 0x80(r4)
lbl_801A2900:
/* 801A2900 0019F860  38 7F 00 04 */	addi r3, r31, 4
/* 801A2904 0019F864  80 9F 04 9C */	lwz r4, 0x49c(r31)
/* 801A2908 0019F868  28 04 00 00 */	cmplwi r4, 0
/* 801A290C 0019F86C  41 82 00 10 */	beq lbl_801A291C
/* 801A2910 0019F870  80 04 00 80 */	lwz r0, 0x80(r4)
/* 801A2914 0019F874  60 00 00 02 */	ori r0, r0, 2
/* 801A2918 0019F878  90 04 00 80 */	stw r0, 0x80(r4)
lbl_801A291C:
/* 801A291C 0019F87C  80 83 04 9C */	lwz r4, 0x49c(r3)
/* 801A2920 0019F880  38 63 00 04 */	addi r3, r3, 4
/* 801A2924 0019F884  28 04 00 00 */	cmplwi r4, 0
/* 801A2928 0019F888  41 82 00 10 */	beq lbl_801A2938
/* 801A292C 0019F88C  80 04 00 80 */	lwz r0, 0x80(r4)
/* 801A2930 0019F890  60 00 00 02 */	ori r0, r0, 2
/* 801A2934 0019F894  90 04 00 80 */	stw r0, 0x80(r4)
lbl_801A2938:
/* 801A2938 0019F898  80 83 04 9C */	lwz r4, 0x49c(r3)
/* 801A293C 0019F89C  38 63 00 04 */	addi r3, r3, 4
/* 801A2940 0019F8A0  28 04 00 00 */	cmplwi r4, 0
/* 801A2944 0019F8A4  41 82 00 10 */	beq lbl_801A2954
/* 801A2948 0019F8A8  80 04 00 80 */	lwz r0, 0x80(r4)
/* 801A294C 0019F8AC  60 00 00 02 */	ori r0, r0, 2
/* 801A2950 0019F8B0  90 04 00 80 */	stw r0, 0x80(r4)
lbl_801A2954:
/* 801A2954 0019F8B4  80 83 04 9C */	lwz r4, 0x49c(r3)
/* 801A2958 0019F8B8  38 63 00 04 */	addi r3, r3, 4
/* 801A295C 0019F8BC  28 04 00 00 */	cmplwi r4, 0
/* 801A2960 0019F8C0  41 82 00 10 */	beq lbl_801A2970
/* 801A2964 0019F8C4  80 04 00 80 */	lwz r0, 0x80(r4)
/* 801A2968 0019F8C8  60 00 00 02 */	ori r0, r0, 2
/* 801A296C 0019F8CC  90 04 00 80 */	stw r0, 0x80(r4)
lbl_801A2970:
/* 801A2970 0019F8D0  80 83 04 9C */	lwz r4, 0x49c(r3)
/* 801A2974 0019F8D4  38 63 00 04 */	addi r3, r3, 4
/* 801A2978 0019F8D8  28 04 00 00 */	cmplwi r4, 0
/* 801A297C 0019F8DC  41 82 00 10 */	beq lbl_801A298C
/* 801A2980 0019F8E0  80 04 00 80 */	lwz r0, 0x80(r4)
/* 801A2984 0019F8E4  60 00 00 02 */	ori r0, r0, 2
/* 801A2988 0019F8E8  90 04 00 80 */	stw r0, 0x80(r4)
lbl_801A298C:
/* 801A298C 0019F8EC  80 83 04 9C */	lwz r4, 0x49c(r3)
/* 801A2990 0019F8F0  38 63 00 04 */	addi r3, r3, 4
/* 801A2994 0019F8F4  28 04 00 00 */	cmplwi r4, 0
/* 801A2998 0019F8F8  41 82 00 10 */	beq lbl_801A29A8
/* 801A299C 0019F8FC  80 04 00 80 */	lwz r0, 0x80(r4)
/* 801A29A0 0019F900  60 00 00 02 */	ori r0, r0, 2
/* 801A29A4 0019F904  90 04 00 80 */	stw r0, 0x80(r4)
lbl_801A29A8:
/* 801A29A8 0019F908  80 83 04 9C */	lwz r4, 0x49c(r3)
/* 801A29AC 0019F90C  38 63 00 04 */	addi r3, r3, 4
/* 801A29B0 0019F910  28 04 00 00 */	cmplwi r4, 0
/* 801A29B4 0019F914  41 82 00 10 */	beq lbl_801A29C4
/* 801A29B8 0019F918  80 04 00 80 */	lwz r0, 0x80(r4)
/* 801A29BC 0019F91C  60 00 00 02 */	ori r0, r0, 2
/* 801A29C0 0019F920  90 04 00 80 */	stw r0, 0x80(r4)
lbl_801A29C4:
/* 801A29C4 0019F924  80 83 04 9C */	lwz r4, 0x49c(r3)
/* 801A29C8 0019F928  28 04 00 00 */	cmplwi r4, 0
/* 801A29CC 0019F92C  41 82 00 10 */	beq lbl_801A29DC
/* 801A29D0 0019F930  80 04 00 80 */	lwz r0, 0x80(r4)
/* 801A29D4 0019F934  60 00 00 02 */	ori r0, r0, 2
/* 801A29D8 0019F938  90 04 00 80 */	stw r0, 0x80(r4)
lbl_801A29DC:
/* 801A29DC 0019F93C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A29E0 0019F940  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A29E4 0019F944  38 21 00 18 */	addi r1, r1, 0x18
/* 801A29E8 0019F948  7C 08 03 A6 */	mtlr r0
/* 801A29EC 0019F94C  4E 80 00 20 */	blr 

.global exitCourse__5YTekiFv
exitCourse__5YTekiFv:
/* 801A29F0 0019F950  7C 08 02 A6 */	mflr r0
/* 801A29F4 0019F954  90 01 00 04 */	stw r0, 4(r1)
/* 801A29F8 0019F958  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A29FC 0019F95C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A2A00 0019F960  7C 7F 1B 78 */	mr r31, r3
/* 801A2A04 0019F964  93 C1 00 10 */	stw r30, 0x10(r1)
/* 801A2A08 0019F968  4B FA 2E 81 */	bl exitCourse__5BTekiFv
/* 801A2A0C 0019F96C  3B C0 00 00 */	li r30, 0
lbl_801A2A10:
/* 801A2A10 0019F970  80 7F 04 98 */	lwz r3, 0x498(r31)
/* 801A2A14 0019F974  28 03 00 00 */	cmplwi r3, 0
/* 801A2A18 0019F978  41 82 00 08 */	beq lbl_801A2A20
/* 801A2A1C 0019F97C  4B FF E1 E1 */	bl forceFinish__Q23zen17particleGeneratorFv
lbl_801A2A20:
/* 801A2A20 0019F980  3B DE 00 01 */	addi r30, r30, 1
/* 801A2A24 0019F984  2C 1E 00 09 */	cmpwi r30, 9
/* 801A2A28 0019F988  3B FF 00 04 */	addi r31, r31, 4
/* 801A2A2C 0019F98C  41 80 FF E4 */	blt lbl_801A2A10
/* 801A2A30 0019F990  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A2A34 0019F994  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A2A38 0019F998  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 801A2A3C 0019F99C  38 21 00 18 */	addi r1, r1, 0x18
/* 801A2A40 0019F9A0  7C 08 03 A6 */	mtlr r0
/* 801A2A44 0019F9A4  4E 80 00 20 */	blr 

.global isNaviWatch__5YTekiFv
isNaviWatch__5YTekiFv:
/* 801A2A48 0019F9A8  7C 08 02 A6 */	mflr r0
/* 801A2A4C 0019F9AC  90 01 00 04 */	stw r0, 4(r1)
/* 801A2A50 0019F9B0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 801A2A54 0019F9B4  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 801A2A58 0019F9B8  3B E0 00 00 */	li r31, 0
/* 801A2A5C 0019F9BC  93 C1 00 38 */	stw r30, 0x38(r1)
/* 801A2A60 0019F9C0  7C 7E 1B 78 */	mr r30, r3
/* 801A2A64 0019F9C4  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 801A2A68 0019F9C8  4B F7 49 5D */	bl getNavi__7NaviMgrFv
/* 801A2A6C 0019F9CC  C4 63 00 94 */	lfsu f3, 0x94(r3)
/* 801A2A70 0019F9D0  C0 3E 00 94 */	lfs f1, 0x94(r30)
/* 801A2A74 0019F9D4  C0 5E 00 9C */	lfs f2, 0x9c(r30)
/* 801A2A78 0019F9D8  C0 83 00 08 */	lfs f4, 8(r3)
/* 801A2A7C 0019F9DC  4B E9 5B AD */	bl qdist2__Fffff
/* 801A2A80 0019F9E0  80 7E 02 C4 */	lwz r3, 0x2c4(r30)
/* 801A2A84 0019F9E4  80 63 00 84 */	lwz r3, 0x84(r3)
/* 801A2A88 0019F9E8  80 63 00 04 */	lwz r3, 4(r3)
/* 801A2A8C 0019F9EC  80 63 00 00 */	lwz r3, 0(r3)
/* 801A2A90 0019F9F0  C0 03 00 18 */	lfs f0, 0x18(r3)
/* 801A2A94 0019F9F4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A2A98 0019F9F8  40 80 00 14 */	bge lbl_801A2AAC
/* 801A2A9C 0019F9FC  80 1E 00 C8 */	lwz r0, 0xc8(r30)
/* 801A2AA0 0019FA00  54 00 03 19 */	rlwinm. r0, r0, 0, 0xc, 0xc
/* 801A2AA4 0019FA04  40 82 00 08 */	bne lbl_801A2AAC
/* 801A2AA8 0019FA08  3B E0 00 01 */	li r31, 1
lbl_801A2AAC:
/* 801A2AAC 0019FA0C  7F E3 FB 78 */	mr r3, r31
/* 801A2AB0 0019FA10  80 01 00 44 */	lwz r0, 0x44(r1)
/* 801A2AB4 0019FA14  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 801A2AB8 0019FA18  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 801A2ABC 0019FA1C  38 21 00 40 */	addi r1, r1, 0x40
/* 801A2AC0 0019FA20  7C 08 03 A6 */	mtlr r0
/* 801A2AC4 0019FA24  4E 80 00 20 */	blr 

.global moveTowardPriorityFaceDir__5YTekiFR8Vector3ff
moveTowardPriorityFaceDir__5YTekiFR8Vector3ff:
/* 801A2AC8 0019FA28  7C 08 02 A6 */	mflr r0
/* 801A2ACC 0019FA2C  90 01 00 04 */	stw r0, 4(r1)
/* 801A2AD0 0019FA30  94 21 FF F8 */	stwu r1, -8(r1)
/* 801A2AD4 0019FA34  80 A3 02 C4 */	lwz r5, 0x2c4(r3)
/* 801A2AD8 0019FA38  80 A5 00 84 */	lwz r5, 0x84(r5)
/* 801A2ADC 0019FA3C  80 A5 00 04 */	lwz r5, 4(r5)
/* 801A2AE0 0019FA40  80 A5 00 00 */	lwz r5, 0(r5)
/* 801A2AE4 0019FA44  C0 45 00 14 */	lfs f2, 0x14(r5)
/* 801A2AE8 0019FA48  48 00 00 15 */	bl moveTowardPriorityFaceDir__5YTekiFR8Vector3fff
/* 801A2AEC 0019FA4C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801A2AF0 0019FA50  38 21 00 08 */	addi r1, r1, 8
/* 801A2AF4 0019FA54  7C 08 03 A6 */	mtlr r0
/* 801A2AF8 0019FA58  4E 80 00 20 */	blr 

.global moveTowardPriorityFaceDir__5YTekiFR8Vector3fff
moveTowardPriorityFaceDir__5YTekiFR8Vector3fff:
/* 801A2AFC 0019FA5C  7C 08 02 A6 */	mflr r0
/* 801A2B00 0019FA60  90 01 00 04 */	stw r0, 4(r1)
/* 801A2B04 0019FA64  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 801A2B08 0019FA68  DB E1 00 58 */	stfd f31, 0x58(r1)
/* 801A2B0C 0019FA6C  DB C1 00 50 */	stfd f30, 0x50(r1)
/* 801A2B10 0019FA70  FF C0 08 90 */	fmr f30, f1
/* 801A2B14 0019FA74  DB A1 00 48 */	stfd f29, 0x48(r1)
/* 801A2B18 0019FA78  DB 81 00 40 */	stfd f28, 0x40(r1)
/* 801A2B1C 0019FA7C  FF 80 10 90 */	fmr f28, f2
/* 801A2B20 0019FA80  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 801A2B24 0019FA84  7C 7F 1B 78 */	mr r31, r3
/* 801A2B28 0019FA88  C0 A4 00 00 */	lfs f5, 0(r4)
/* 801A2B2C 0019FA8C  C0 83 00 94 */	lfs f4, 0x94(r3)
/* 801A2B30 0019FA90  C0 64 00 08 */	lfs f3, 8(r4)
/* 801A2B34 0019FA94  C0 1F 00 9C */	lfs f0, 0x9c(r31)
/* 801A2B38 0019FA98  EC 25 20 28 */	fsubs f1, f5, f4
/* 801A2B3C 0019FA9C  C3 FF 00 A8 */	lfs f31, 0xa8(r31)
/* 801A2B40 0019FAA0  EC 43 00 28 */	fsubs f2, f3, f0
/* 801A2B44 0019FAA4  4B F7 B2 C5 */	bl atan2__6NMathFFff
/* 801A2B48 0019FAA8  D0 3F 03 94 */	stfs f1, 0x394(r31)
/* 801A2B4C 0019FAAC  C0 3F 03 94 */	lfs f1, 0x394(r31)
/* 801A2B50 0019FAB0  C0 5F 00 A0 */	lfs f2, 0xa0(r31)
/* 801A2B54 0019FAB4  4B E9 5A 61 */	bl angDist__Fff
/* 801A2B58 0019FAB8  FF A0 08 90 */	fmr f29, f1
/* 801A2B5C 0019FABC  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801A2B60 0019FAC0  C0 5F 00 A0 */	lfs f2, 0xa0(r31)
/* 801A2B64 0019FAC4  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801A2B68 0019FAC8  EC 3D 07 32 */	fmuls f1, f29, f28
/* 801A2B6C 0019FACC  EC 01 00 32 */	fmuls f0, f1, f0
/* 801A2B70 0019FAD0  EC 02 00 2A */	fadds f0, f2, f0
/* 801A2B74 0019FAD4  D0 1F 00 A0 */	stfs f0, 0xa0(r31)
/* 801A2B78 0019FAD8  C0 3F 00 A0 */	lfs f1, 0xa0(r31)
/* 801A2B7C 0019FADC  4B E9 5A 0D */	bl roundAng__Ff
/* 801A2B80 0019FAE0  D0 3F 00 A0 */	stfs f1, 0xa0(r31)
/* 801A2B84 0019FAE4  C0 0D 11 8C */	lfs f0, lbl_803E5EAC@sda21(r13)
/* 801A2B88 0019FAE8  D0 1F 00 88 */	stfs f0, 0x88(r31)
/* 801A2B8C 0019FAEC  C0 1F 00 A0 */	lfs f0, 0xa0(r31)
/* 801A2B90 0019FAF0  D0 1F 00 8C */	stfs f0, 0x8c(r31)
/* 801A2B94 0019FAF4  C0 0D 11 90 */	lfs f0, lbl_803E5EB0@sda21(r13)
/* 801A2B98 0019FAF8  D0 1F 00 90 */	stfs f0, 0x90(r31)
/* 801A2B9C 0019FAFC  C0 02 B4 30 */	lfs f0, lbl_803EB630@sda21(r2)
/* 801A2BA0 0019FB00  FC 1D 00 40 */	fcmpo cr0, f29, f0
/* 801A2BA4 0019FB04  40 80 00 0C */	bge lbl_801A2BB0
/* 801A2BA8 0019FB08  FC 20 E8 50 */	fneg f1, f29
/* 801A2BAC 0019FB0C  48 00 00 08 */	b lbl_801A2BB4
lbl_801A2BB0:
/* 801A2BB0 0019FB10  FC 20 E8 90 */	fmr f1, f29
lbl_801A2BB4:
/* 801A2BB4 0019FB14  C0 02 B4 3C */	lfs f0, lbl_803EB63C@sda21(r2)
/* 801A2BB8 0019FB18  C0 42 B4 38 */	lfs f2, lbl_803EB638@sda21(r2)
/* 801A2BBC 0019FB1C  EC 21 00 24 */	fdivs f1, f1, f0
/* 801A2BC0 0019FB20  C0 02 B4 40 */	lfs f0, lbl_803EB640@sda21(r2)
/* 801A2BC4 0019FB24  EC 22 00 72 */	fmuls f1, f2, f1
/* 801A2BC8 0019FB28  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A2BCC 0019FB2C  41 81 00 0C */	bgt lbl_801A2BD8
/* 801A2BD0 0019FB30  EC 00 08 28 */	fsubs f0, f0, f1
/* 801A2BD4 0019FB34  EF DE 00 32 */	fmuls f30, f30, f0
lbl_801A2BD8:
/* 801A2BD8 0019FB38  C0 3F 00 A0 */	lfs f1, 0xa0(r31)
/* 801A2BDC 0019FB3C  48 07 8F 79 */	bl cosf
/* 801A2BE0 0019FB40  C0 1F 00 A0 */	lfs f0, 0xa0(r31)
/* 801A2BE4 0019FB44  FF A0 08 90 */	fmr f29, f1
/* 801A2BE8 0019FB48  FC 20 00 90 */	fmr f1, f0
/* 801A2BEC 0019FB4C  48 07 90 FD */	bl sinf
/* 801A2BF0 0019FB50  D0 3F 00 A4 */	stfs f1, 0xa4(r31)
/* 801A2BF4 0019FB54  C0 0D 11 94 */	lfs f0, lbl_803E5EB4@sda21(r13)
/* 801A2BF8 0019FB58  D0 1F 00 A8 */	stfs f0, 0xa8(r31)
/* 801A2BFC 0019FB5C  D3 BF 00 AC */	stfs f29, 0xac(r31)
/* 801A2C00 0019FB60  C0 1F 00 A4 */	lfs f0, 0xa4(r31)
/* 801A2C04 0019FB64  EC 00 07 B2 */	fmuls f0, f0, f30
/* 801A2C08 0019FB68  D0 1F 00 A4 */	stfs f0, 0xa4(r31)
/* 801A2C0C 0019FB6C  C0 1F 00 A8 */	lfs f0, 0xa8(r31)
/* 801A2C10 0019FB70  EC 00 07 B2 */	fmuls f0, f0, f30
/* 801A2C14 0019FB74  D0 1F 00 A8 */	stfs f0, 0xa8(r31)
/* 801A2C18 0019FB78  C0 1F 00 AC */	lfs f0, 0xac(r31)
/* 801A2C1C 0019FB7C  EC 00 07 B2 */	fmuls f0, f0, f30
/* 801A2C20 0019FB80  D0 1F 00 AC */	stfs f0, 0xac(r31)
/* 801A2C24 0019FB84  D3 FF 00 A8 */	stfs f31, 0xa8(r31)
/* 801A2C28 0019FB88  80 01 00 64 */	lwz r0, 0x64(r1)
/* 801A2C2C 0019FB8C  CB E1 00 58 */	lfd f31, 0x58(r1)
/* 801A2C30 0019FB90  CB C1 00 50 */	lfd f30, 0x50(r1)
/* 801A2C34 0019FB94  CB A1 00 48 */	lfd f29, 0x48(r1)
/* 801A2C38 0019FB98  CB 81 00 40 */	lfd f28, 0x40(r1)
/* 801A2C3C 0019FB9C  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 801A2C40 0019FBA0  38 21 00 60 */	addi r1, r1, 0x60
/* 801A2C44 0019FBA4  7C 08 03 A6 */	mtlr r0
/* 801A2C48 0019FBA8  4E 80 00 20 */	blr 

.global turnToTarget__5YTekiFv
turnToTarget__5YTekiFv:
/* 801A2C4C 0019FBAC  7C 08 02 A6 */	mflr r0
/* 801A2C50 0019FBB0  90 01 00 04 */	stw r0, 4(r1)
/* 801A2C54 0019FBB4  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 801A2C58 0019FBB8  DB E1 00 58 */	stfd f31, 0x58(r1)
/* 801A2C5C 0019FBBC  93 E1 00 54 */	stw r31, 0x54(r1)
/* 801A2C60 0019FBC0  7C 7F 1B 78 */	mr r31, r3
/* 801A2C64 0019FBC4  80 83 04 18 */	lwz r4, 0x418(r3)
/* 801A2C68 0019FBC8  28 04 00 00 */	cmplwi r4, 0
/* 801A2C6C 0019FBCC  41 82 00 C0 */	beq lbl_801A2D2C
/* 801A2C70 0019FBD0  C4 64 00 94 */	lfsu f3, 0x94(r4)
/* 801A2C74 0019FBD4  C0 3F 00 94 */	lfs f1, 0x94(r31)
/* 801A2C78 0019FBD8  C0 44 00 08 */	lfs f2, 8(r4)
/* 801A2C7C 0019FBDC  C0 1F 00 9C */	lfs f0, 0x9c(r31)
/* 801A2C80 0019FBE0  EC 23 08 28 */	fsubs f1, f3, f1
/* 801A2C84 0019FBE4  EC 42 00 28 */	fsubs f2, f2, f0
/* 801A2C88 0019FBE8  4B F7 B1 81 */	bl atan2__6NMathFFff
/* 801A2C8C 0019FBEC  D0 3F 03 94 */	stfs f1, 0x394(r31)
/* 801A2C90 0019FBF0  C0 3F 03 94 */	lfs f1, 0x394(r31)
/* 801A2C94 0019FBF4  C0 5F 00 A0 */	lfs f2, 0xa0(r31)
/* 801A2C98 0019FBF8  4B E9 59 1D */	bl angDist__Fff
/* 801A2C9C 0019FBFC  80 9F 02 24 */	lwz r4, 0x224(r31)
/* 801A2CA0 0019FC00  FF E0 08 90 */	fmr f31, f1
/* 801A2CA4 0019FC04  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801A2CA8 0019FC08  C0 24 00 30 */	lfs f1, 0x30(r4)
/* 801A2CAC 0019FC0C  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801A2CB0 0019FC10  EC 3F 00 72 */	fmuls f1, f31, f1
/* 801A2CB4 0019FC14  C0 42 B4 44 */	lfs f2, lbl_803EB644@sda21(r2)
/* 801A2CB8 0019FC18  C0 7F 00 A0 */	lfs f3, 0xa0(r31)
/* 801A2CBC 0019FC1C  EC 01 00 32 */	fmuls f0, f1, f0
/* 801A2CC0 0019FC20  EC 02 00 32 */	fmuls f0, f2, f0
/* 801A2CC4 0019FC24  EC 03 00 2A */	fadds f0, f3, f0
/* 801A2CC8 0019FC28  D0 1F 00 A0 */	stfs f0, 0xa0(r31)
/* 801A2CCC 0019FC2C  C0 3F 00 A0 */	lfs f1, 0xa0(r31)
/* 801A2CD0 0019FC30  4B E9 58 B9 */	bl roundAng__Ff
/* 801A2CD4 0019FC34  D0 3F 00 A0 */	stfs f1, 0xa0(r31)
/* 801A2CD8 0019FC38  C0 0D 11 98 */	lfs f0, lbl_803E5EB8@sda21(r13)
/* 801A2CDC 0019FC3C  D0 1F 00 88 */	stfs f0, 0x88(r31)
/* 801A2CE0 0019FC40  C0 1F 00 A0 */	lfs f0, 0xa0(r31)
/* 801A2CE4 0019FC44  D0 1F 00 8C */	stfs f0, 0x8c(r31)
/* 801A2CE8 0019FC48  C0 0D 11 9C */	lfs f0, lbl_803E5EBC@sda21(r13)
/* 801A2CEC 0019FC4C  D0 1F 00 90 */	stfs f0, 0x90(r31)
/* 801A2CF0 0019FC50  80 7F 02 C4 */	lwz r3, 0x2c4(r31)
/* 801A2CF4 0019FC54  C0 42 B4 3C */	lfs f2, lbl_803EB63C@sda21(r2)
/* 801A2CF8 0019FC58  80 63 00 84 */	lwz r3, 0x84(r3)
/* 801A2CFC 0019FC5C  C0 02 B4 48 */	lfs f0, lbl_803EB648@sda21(r2)
/* 801A2D00 0019FC60  80 63 00 04 */	lwz r3, 4(r3)
/* 801A2D04 0019FC64  80 63 00 00 */	lwz r3, 0(r3)
/* 801A2D08 0019FC68  C0 23 00 24 */	lfs f1, 0x24(r3)
/* 801A2D0C 0019FC6C  EC 22 00 72 */	fmuls f1, f2, f1
/* 801A2D10 0019FC70  EC 01 00 24 */	fdivs f0, f1, f0
/* 801A2D14 0019FC74  FC 1F 00 40 */	fcmpo cr0, f31, f0
/* 801A2D18 0019FC78  40 80 00 0C */	bge lbl_801A2D24
/* 801A2D1C 0019FC7C  38 60 00 01 */	li r3, 1
/* 801A2D20 0019FC80  48 00 00 10 */	b lbl_801A2D30
lbl_801A2D24:
/* 801A2D24 0019FC84  38 60 00 00 */	li r3, 0
/* 801A2D28 0019FC88  48 00 00 08 */	b lbl_801A2D30
lbl_801A2D2C:
/* 801A2D2C 0019FC8C  38 60 00 01 */	li r3, 1
lbl_801A2D30:
/* 801A2D30 0019FC90  80 01 00 64 */	lwz r0, 0x64(r1)
/* 801A2D34 0019FC94  CB E1 00 58 */	lfd f31, 0x58(r1)
/* 801A2D38 0019FC98  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 801A2D3C 0019FC9C  38 21 00 60 */	addi r1, r1, 0x60
/* 801A2D40 0019FCA0  7C 08 03 A6 */	mtlr r0
/* 801A2D44 0019FCA4  4E 80 00 20 */	blr 

.global flyingStay__5YTekiFf
flyingStay__5YTekiFf:
/* 801A2D48 0019FCA8  7C 08 02 A6 */	mflr r0
/* 801A2D4C 0019FCAC  90 01 00 04 */	stw r0, 4(r1)
/* 801A2D50 0019FCB0  94 21 FF 98 */	stwu r1, -0x68(r1)
/* 801A2D54 0019FCB4  DB E1 00 60 */	stfd f31, 0x60(r1)
/* 801A2D58 0019FCB8  FF E0 08 90 */	fmr f31, f1
/* 801A2D5C 0019FCBC  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 801A2D60 0019FCC0  7C 7F 1B 78 */	mr r31, r3
/* 801A2D64 0019FCC4  4B FA 5C 31 */	bl getYFromSeaLevel__5BTekiFv
/* 801A2D68 0019FCC8  80 7F 02 C4 */	lwz r3, 0x2c4(r31)
/* 801A2D6C 0019FCCC  C0 42 B4 4C */	lfs f2, lbl_803EB64C@sda21(r2)
/* 801A2D70 0019FCD0  80 63 00 84 */	lwz r3, 0x84(r3)
/* 801A2D74 0019FCD4  EC 62 07 F2 */	fmuls f3, f2, f31
/* 801A2D78 0019FCD8  C0 02 B4 30 */	lfs f0, lbl_803EB630@sda21(r2)
/* 801A2D7C 0019FCDC  80 63 00 04 */	lwz r3, 4(r3)
/* 801A2D80 0019FCE0  80 63 00 00 */	lwz r3, 0(r3)
/* 801A2D84 0019FCE4  C0 43 00 74 */	lfs f2, 0x74(r3)
/* 801A2D88 0019FCE8  EC 22 08 28 */	fsubs f1, f2, f1
/* 801A2D8C 0019FCEC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A2D90 0019FCF0  40 80 00 0C */	bge lbl_801A2D9C
/* 801A2D94 0019FCF4  FC 00 08 50 */	fneg f0, f1
/* 801A2D98 0019FCF8  48 00 00 08 */	b lbl_801A2DA0
lbl_801A2D9C:
/* 801A2D9C 0019FCFC  FC 00 08 90 */	fmr f0, f1
lbl_801A2DA0:
/* 801A2DA0 0019FD00  FC 00 18 40 */	fcmpo cr0, f0, f3
/* 801A2DA4 0019FD04  40 81 00 20 */	ble lbl_801A2DC4
/* 801A2DA8 0019FD08  C0 02 B4 30 */	lfs f0, lbl_803EB630@sda21(r2)
/* 801A2DAC 0019FD0C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A2DB0 0019FD10  40 81 00 0C */	ble lbl_801A2DBC
/* 801A2DB4 0019FD14  C0 02 B4 40 */	lfs f0, lbl_803EB640@sda21(r2)
/* 801A2DB8 0019FD18  48 00 00 08 */	b lbl_801A2DC0
lbl_801A2DBC:
/* 801A2DBC 0019FD1C  C0 02 B4 50 */	lfs f0, lbl_803EB650@sda21(r2)
lbl_801A2DC0:
/* 801A2DC0 0019FD20  EC 23 00 32 */	fmuls f1, f3, f0
lbl_801A2DC4:
/* 801A2DC4 0019FD24  C0 02 B4 54 */	lfs f0, lbl_803EB654@sda21(r2)
/* 801A2DC8 0019FD28  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801A2DCC 0019FD2C  EC 00 00 72 */	fmuls f0, f0, f1
/* 801A2DD0 0019FD30  C0 3F 00 A8 */	lfs f1, 0xa8(r31)
/* 801A2DD4 0019FD34  C0 43 02 8C */	lfs f2, 0x28c(r3)
/* 801A2DD8 0019FD38  EC 00 00 B2 */	fmuls f0, f0, f2
/* 801A2DDC 0019FD3C  EC 00 00 B2 */	fmuls f0, f0, f2
/* 801A2DE0 0019FD40  EC 01 00 2A */	fadds f0, f1, f0
/* 801A2DE4 0019FD44  D0 1F 00 A8 */	stfs f0, 0xa8(r31)
/* 801A2DE8 0019FD48  C0 3F 00 A8 */	lfs f1, 0xa8(r31)
/* 801A2DEC 0019FD4C  C0 02 B4 30 */	lfs f0, lbl_803EB630@sda21(r2)
/* 801A2DF0 0019FD50  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A2DF4 0019FD54  40 80 00 0C */	bge lbl_801A2E00
/* 801A2DF8 0019FD58  FC 00 08 50 */	fneg f0, f1
/* 801A2DFC 0019FD5C  48 00 00 08 */	b lbl_801A2E04
lbl_801A2E00:
/* 801A2E00 0019FD60  FC 00 08 90 */	fmr f0, f1
lbl_801A2E04:
/* 801A2E04 0019FD64  FC 00 F8 40 */	fcmpo cr0, f0, f31
/* 801A2E08 0019FD68  40 81 00 24 */	ble lbl_801A2E2C
/* 801A2E0C 0019FD6C  C0 02 B4 30 */	lfs f0, lbl_803EB630@sda21(r2)
/* 801A2E10 0019FD70  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801A2E14 0019FD74  40 81 00 0C */	ble lbl_801A2E20
/* 801A2E18 0019FD78  C0 02 B4 40 */	lfs f0, lbl_803EB640@sda21(r2)
/* 801A2E1C 0019FD7C  48 00 00 08 */	b lbl_801A2E24
lbl_801A2E20:
/* 801A2E20 0019FD80  C0 02 B4 50 */	lfs f0, lbl_803EB650@sda21(r2)
lbl_801A2E24:
/* 801A2E24 0019FD84  EC 1F 00 32 */	fmuls f0, f31, f0
/* 801A2E28 0019FD88  D0 1F 00 A8 */	stfs f0, 0xa8(r31)
lbl_801A2E2C:
/* 801A2E2C 0019FD8C  80 7F 00 A4 */	lwz r3, 0xa4(r31)
/* 801A2E30 0019FD90  80 1F 00 A8 */	lwz r0, 0xa8(r31)
/* 801A2E34 0019FD94  90 7F 00 70 */	stw r3, 0x70(r31)
/* 801A2E38 0019FD98  90 1F 00 74 */	stw r0, 0x74(r31)
/* 801A2E3C 0019FD9C  80 1F 00 AC */	lwz r0, 0xac(r31)
/* 801A2E40 0019FDA0  90 1F 00 78 */	stw r0, 0x78(r31)
/* 801A2E44 0019FDA4  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 801A2E48 0019FDA8  CB E1 00 60 */	lfd f31, 0x60(r1)
/* 801A2E4C 0019FDAC  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 801A2E50 0019FDB0  38 21 00 68 */	addi r1, r1, 0x68
/* 801A2E54 0019FDB4  7C 08 03 A6 */	mtlr r0
/* 801A2E58 0019FDB8  4E 80 00 20 */	blr 

.global killStickToMouthPiki__5YTekiFv
killStickToMouthPiki__5YTekiFv:
/* 801A2E5C 0019FDBC  7C 08 02 A6 */	mflr r0
/* 801A2E60 0019FDC0  90 01 00 04 */	stw r0, 4(r1)
/* 801A2E64 0019FDC4  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 801A2E68 0019FDC8  BF 21 00 44 */	stmw r25, 0x44(r1)
/* 801A2E6C 0019FDCC  3B 83 00 00 */	addi r28, r3, 0
/* 801A2E70 0019FDD0  38 9C 00 00 */	addi r4, r28, 0
/* 801A2E74 0019FDD4  38 61 00 30 */	addi r3, r1, 0x30
/* 801A2E78 0019FDD8  4B EE DE 0D */	bl __ct__8StickersFP8Creature
/* 801A2E7C 0019FDDC  3B C1 00 30 */	addi r30, r1, 0x30
/* 801A2E80 0019FDE0  38 7E 00 00 */	addi r3, r30, 0
/* 801A2E84 0019FDE4  81 9E 00 00 */	lwz r12, 0(r30)
/* 801A2E88 0019FDE8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801A2E8C 0019FDEC  7D 88 03 A6 */	mtlr r12
/* 801A2E90 0019FDF0  4E 80 00 21 */	blrl 
/* 801A2E94 0019FDF4  3C A0 80 2B */	lis r5, __vt__11Interaction@ha
/* 801A2E98 0019FDF8  3C 80 80 2B */	lis r4, __vt__12InteractKill@ha
/* 801A2E9C 0019FDFC  3B A3 00 00 */	addi r29, r3, 0
/* 801A2EA0 0019FE00  3B 45 CF 9C */	addi r26, r5, __vt__11Interaction@l
/* 801A2EA4 0019FE04  3B 64 CD 74 */	addi r27, r4, __vt__12InteractKill@l
/* 801A2EA8 0019FE08  3B E1 00 18 */	addi r31, r1, 0x18
/* 801A2EAC 0019FE0C  48 00 00 E4 */	b lbl_801A2F90
lbl_801A2EB0:
/* 801A2EB0 0019FE10  2C 1D FF FF */	cmpwi r29, -1
/* 801A2EB4 0019FE14  40 82 00 24 */	bne lbl_801A2ED8
/* 801A2EB8 0019FE18  7F C3 F3 78 */	mr r3, r30
/* 801A2EBC 0019FE1C  81 9E 00 00 */	lwz r12, 0(r30)
/* 801A2EC0 0019FE20  38 80 00 00 */	li r4, 0
/* 801A2EC4 0019FE24  81 8C 00 08 */	lwz r12, 8(r12)
/* 801A2EC8 0019FE28  7D 88 03 A6 */	mtlr r12
/* 801A2ECC 0019FE2C  4E 80 00 21 */	blrl 
/* 801A2ED0 0019FE30  7C 79 1B 78 */	mr r25, r3
/* 801A2ED4 0019FE34  48 00 00 20 */	b lbl_801A2EF4
lbl_801A2ED8:
/* 801A2ED8 0019FE38  7F C3 F3 78 */	mr r3, r30
/* 801A2EDC 0019FE3C  81 9E 00 00 */	lwz r12, 0(r30)
/* 801A2EE0 0019FE40  7F A4 EB 78 */	mr r4, r29
/* 801A2EE4 0019FE44  81 8C 00 08 */	lwz r12, 8(r12)
/* 801A2EE8 0019FE48  7D 88 03 A6 */	mtlr r12
/* 801A2EEC 0019FE4C  4E 80 00 21 */	blrl 
/* 801A2EF0 0019FE50  7C 79 1B 78 */	mr r25, r3
lbl_801A2EF4:
/* 801A2EF4 0019FE54  28 19 00 00 */	cmplwi r25, 0
/* 801A2EF8 0019FE58  38 79 00 00 */	addi r3, r25, 0
/* 801A2EFC 0019FE5C  41 82 00 78 */	beq lbl_801A2F74
/* 801A2F00 0019FE60  80 19 00 C8 */	lwz r0, 0xc8(r25)
/* 801A2F04 0019FE64  54 00 04 21 */	rlwinm. r0, r0, 0, 0x10, 0x10
/* 801A2F08 0019FE68  41 82 00 6C */	beq lbl_801A2F74
/* 801A2F0C 0019FE6C  93 41 00 18 */	stw r26, 0x18(r1)
/* 801A2F10 0019FE70  38 00 00 00 */	li r0, 0
/* 801A2F14 0019FE74  7F E4 FB 78 */	mr r4, r31
/* 801A2F18 0019FE78  93 81 00 1C */	stw r28, 0x1c(r1)
/* 801A2F1C 0019FE7C  93 61 00 18 */	stw r27, 0x18(r1)
/* 801A2F20 0019FE80  90 01 00 20 */	stw r0, 0x20(r1)
/* 801A2F24 0019FE84  81 83 00 00 */	lwz r12, 0(r3)
/* 801A2F28 0019FE88  81 8C 00 A0 */	lwz r12, 0xa0(r12)
/* 801A2F2C 0019FE8C  7D 88 03 A6 */	mtlr r12
/* 801A2F30 0019FE90  4E 80 00 21 */	blrl 
/* 801A2F34 0019FE94  3B 39 00 94 */	addi r25, r25, 0x94
/* 801A2F38 0019FE98  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801A2F3C 0019FE9C  38 B9 00 00 */	addi r5, r25, 0
/* 801A2F40 0019FEA0  38 80 00 2F */	li r4, 0x2f
/* 801A2F44 0019FEA4  38 C0 00 00 */	li r6, 0
/* 801A2F48 0019FEA8  38 E0 00 00 */	li r7, 0
/* 801A2F4C 0019FEAC  4B FF 9B ED */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801A2F50 0019FEB0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801A2F54 0019FEB4  38 B9 00 00 */	addi r5, r25, 0
/* 801A2F58 0019FEB8  38 80 00 30 */	li r4, 0x30
/* 801A2F5C 0019FEBC  38 C0 00 00 */	li r6, 0
/* 801A2F60 0019FEC0  38 E0 00 00 */	li r7, 0
/* 801A2F64 0019FEC4  4B FF 9B D5 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801A2F68 0019FEC8  2C 1D 00 00 */	cmpwi r29, 0
/* 801A2F6C 0019FECC  41 80 00 08 */	blt lbl_801A2F74
/* 801A2F70 0019FED0  3B BD FF FF */	addi r29, r29, -1
lbl_801A2F74:
/* 801A2F74 0019FED4  7F C3 F3 78 */	mr r3, r30
/* 801A2F78 0019FED8  81 9E 00 00 */	lwz r12, 0(r30)
/* 801A2F7C 0019FEDC  7F A4 EB 78 */	mr r4, r29
/* 801A2F80 0019FEE0  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801A2F84 0019FEE4  7D 88 03 A6 */	mtlr r12
/* 801A2F88 0019FEE8  4E 80 00 21 */	blrl 
/* 801A2F8C 0019FEEC  7C 7D 1B 78 */	mr r29, r3
lbl_801A2F90:
/* 801A2F90 0019FEF0  7F C3 F3 78 */	mr r3, r30
/* 801A2F94 0019FEF4  81 9E 00 00 */	lwz r12, 0(r30)
/* 801A2F98 0019FEF8  7F A4 EB 78 */	mr r4, r29
/* 801A2F9C 0019FEFC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 801A2FA0 0019FF00  7D 88 03 A6 */	mtlr r12
/* 801A2FA4 0019FF04  4E 80 00 21 */	blrl 
/* 801A2FA8 0019FF08  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801A2FAC 0019FF0C  41 82 00 0C */	beq lbl_801A2FB8
/* 801A2FB0 0019FF10  38 00 00 01 */	li r0, 1
/* 801A2FB4 0019FF14  48 00 00 30 */	b lbl_801A2FE4
lbl_801A2FB8:
/* 801A2FB8 0019FF18  7F C3 F3 78 */	mr r3, r30
/* 801A2FBC 0019FF1C  81 9E 00 00 */	lwz r12, 0(r30)
/* 801A2FC0 0019FF20  7F A4 EB 78 */	mr r4, r29
/* 801A2FC4 0019FF24  81 8C 00 08 */	lwz r12, 8(r12)
/* 801A2FC8 0019FF28  7D 88 03 A6 */	mtlr r12
/* 801A2FCC 0019FF2C  4E 80 00 21 */	blrl 
/* 801A2FD0 0019FF30  28 03 00 00 */	cmplwi r3, 0
/* 801A2FD4 0019FF34  40 82 00 0C */	bne lbl_801A2FE0
/* 801A2FD8 0019FF38  38 00 00 01 */	li r0, 1
/* 801A2FDC 0019FF3C  48 00 00 08 */	b lbl_801A2FE4
lbl_801A2FE0:
/* 801A2FE0 0019FF40  38 00 00 00 */	li r0, 0
lbl_801A2FE4:
/* 801A2FE4 0019FF44  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 801A2FE8 0019FF48  41 82 FE C8 */	beq lbl_801A2EB0
/* 801A2FEC 0019FF4C  BB 21 00 44 */	lmw r25, 0x44(r1)
/* 801A2FF0 0019FF50  80 01 00 64 */	lwz r0, 0x64(r1)
/* 801A2FF4 0019FF54  38 21 00 60 */	addi r1, r1, 0x60
/* 801A2FF8 0019FF58  7C 08 03 A6 */	mtlr r0
/* 801A2FFC 0019FF5C  4E 80 00 20 */	blr 

.global startNewMotion__5YTekiFi
startNewMotion__5YTekiFi:
/* 801A3000 0019FF60  7C 08 02 A6 */	mflr r0
/* 801A3004 0019FF64  90 01 00 04 */	stw r0, 4(r1)
/* 801A3008 0019FF68  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 801A300C 0019FF6C  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 801A3010 0019FF70  7C 9F 23 78 */	mr r31, r4
/* 801A3014 0019FF74  93 C1 00 38 */	stw r30, 0x38(r1)
/* 801A3018 0019FF78  7C 7E 1B 78 */	mr r30, r3
/* 801A301C 0019FF7C  80 63 02 CC */	lwz r3, 0x2cc(r3)
/* 801A3020 0019FF80  80 03 00 44 */	lwz r0, 0x44(r3)
/* 801A3024 0019FF84  7C 1F 00 00 */	cmpw r31, r0
/* 801A3028 0019FF88  40 82 00 10 */	bne lbl_801A3038
/* 801A302C 0019FF8C  88 03 00 48 */	lbz r0, 0x48(r3)
/* 801A3030 0019FF90  28 00 00 00 */	cmplwi r0, 0
/* 801A3034 0019FF94  41 82 00 78 */	beq lbl_801A30AC
lbl_801A3038:
/* 801A3038 0019FF98  88 03 00 48 */	lbz r0, 0x48(r3)
/* 801A303C 0019FF9C  28 00 00 00 */	cmplwi r0, 0
/* 801A3040 0019FFA0  40 82 00 2C */	bne lbl_801A306C
/* 801A3044 0019FFA4  28 1E 00 00 */	cmplwi r30, 0
/* 801A3048 0019FFA8  38 BE 00 00 */	addi r5, r30, 0
/* 801A304C 0019FFAC  41 82 00 08 */	beq lbl_801A3054
/* 801A3050 0019FFB0  80 BE 02 C0 */	lwz r5, 0x2c0(r30)
lbl_801A3054:
/* 801A3054 0019FFB4  38 61 00 2C */	addi r3, r1, 0x2c
/* 801A3058 0019FFB8  38 80 FF FF */	li r4, -1
/* 801A305C 0019FFBC  4B F7 BF 31 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801A3060 0019FFC0  7C 64 1B 78 */	mr r4, r3
/* 801A3064 0019FFC4  80 7E 02 CC */	lwz r3, 0x2cc(r30)
/* 801A3068 0019FFC8  4B F7 C1 C9 */	bl finishMotion__12PaniAnimatorFR14PaniMotionInfo
lbl_801A306C:
/* 801A306C 0019FFCC  80 7E 02 CC */	lwz r3, 0x2cc(r30)
/* 801A3070 0019FFD0  80 03 00 38 */	lwz r0, 0x38(r3)
/* 801A3074 0019FFD4  2C 00 00 00 */	cmpwi r0, 0
/* 801A3078 0019FFD8  40 80 00 2C */	bge lbl_801A30A4
/* 801A307C 0019FFDC  28 1E 00 00 */	cmplwi r30, 0
/* 801A3080 0019FFE0  38 BE 00 00 */	addi r5, r30, 0
/* 801A3084 0019FFE4  41 82 00 08 */	beq lbl_801A308C
/* 801A3088 0019FFE8  80 BE 02 C0 */	lwz r5, 0x2c0(r30)
lbl_801A308C:
/* 801A308C 0019FFEC  38 9F 00 00 */	addi r4, r31, 0
/* 801A3090 0019FFF0  38 61 00 24 */	addi r3, r1, 0x24
/* 801A3094 0019FFF4  4B F7 BE F9 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 801A3098 0019FFF8  7C 64 1B 78 */	mr r4, r3
/* 801A309C 0019FFFC  80 7E 02 CC */	lwz r3, 0x2cc(r30)
/* 801A30A0 001A0000  4B F7 C1 21 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
lbl_801A30A4:
/* 801A30A4 001A0004  38 60 00 00 */	li r3, 0
/* 801A30A8 001A0008  48 00 00 08 */	b lbl_801A30B0
lbl_801A30AC:
/* 801A30AC 001A000C  38 60 00 01 */	li r3, 1
lbl_801A30B0:
/* 801A30B0 001A0010  80 01 00 44 */	lwz r0, 0x44(r1)
/* 801A30B4 001A0014  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 801A30B8 001A0018  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 801A30BC 001A001C  38 21 00 40 */	addi r1, r1, 0x40
/* 801A30C0 001A0020  7C 08 03 A6 */	mtlr r0
/* 801A30C4 001A0024  4E 80 00 20 */	blr 

.global hitCreature__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature8Vector3f
hitCreature__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature8Vector3f:
/* 801A30C8 001A0028  38 60 00 00 */	li r3, 0
/* 801A30CC 001A002C  4E 80 00 20 */	blr 

.global hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature8Vector3f
hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature8Vector3f:
/* 801A30D0 001A0030  38 60 00 00 */	li r3, 0
/* 801A30D4 001A0034  4E 80 00 20 */	blr 

.global hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature
hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature:
/* 801A30D8 001A0038  38 60 00 00 */	li r3, 0
/* 801A30DC 001A003C  4E 80 00 20 */	blr 

.global hitMap__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParam
hitMap__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParam:
/* 801A30E0 001A0040  38 60 00 00 */	li r3, 0
/* 801A30E4 001A0044  4E 80 00 20 */	blr 

.global playEventSound__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParam
playEventSound__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParam:
/* 801A30E8 001A0048  4E 80 00 20 */	blr 

.global ptclHitMap__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParam
ptclHitMap__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParam:
/* 801A30EC 001A004C  4E 80 00 20 */	blr 

.global hitCheckCulling__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature
hitCheckCulling__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature:
/* 801A30F0 001A0050  38 60 00 01 */	li r3, 1
/* 801A30F4 001A0054  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802DD898:
	.asciz "tekiyteki.cpp"
.balign 4
lbl_802DD8A8:
	.asciz "tekiyteki"
.balign 4
lbl_802DD8B4:
	.asciz "Interaction"
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
lbl_802DD8EC:
	.asciz "PelletView"
.balign 4
lbl_802DD8F8:
	.asciz "PaniAnimKeyListener"
.balign 4
lbl_802DD90C:
	.asciz "EventTalker"
.balign 4
lbl_802DD918:
	.asciz "RefCountable"
.balign 4
lbl_802DD928:
	.asciz "Creature"
.balign 4
lbl_802DD934:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
lbl_802DD948:
	.4byte __RTTI__10PelletView
	.4byte 0x2b8
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x454
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
lbl_802DD974:
	.4byte __RTTI__10PelletView
	.4byte 0x2b8
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x46c
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__5BTeki
	.4byte 0
	.4byte 0
lbl_802DD9A8:
	.4byte __RTTI__10PelletView
	.4byte 0x2b8
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x538
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__5BTeki
	.4byte 0
	.4byte __RTTI__5NTeki
	.4byte 0
	.4byte 0
.global __vt__5YTeki
__vt__5YTeki:
	.4byte __RTTI__5YTeki
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__5BTekiFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8CreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__5BTekiFi
	.4byte getiMass__5BTekiFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__5BTekiFP11CreatureInf
	.4byte doRestore__5BTekiFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__5BTekiFv
	.4byte isVisible__5BTekiFv
	.4byte isOrganic__5BTekiFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__5BTekiFv
	.4byte isAlive__5BTekiFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__5BTekiFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__5BTekiFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__5BTekiFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__5BTekiFR9CollEvent
	.4byte bounceCallback__5BTekiFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__5BTekiFR5PlaneP13DynCollObject
	.4byte offwallCallback__8CreatureFP13DynCollObject
	.4byte stickCallback__8CreatureFP8Creature
	.4byte offstickCallback__8CreatureFP8Creature
	.4byte stickToCallback__8CreatureFP8Creature
	.4byte dump__5BTekiFv
	.4byte startWaterEffect__8CreatureFv
	.4byte finishWaterEffect__8CreatureFv
	.4byte isRopable__8CreatureFv
	.4byte mayIstick__8CreatureFv
	.4byte getFormationPri__8CreatureFv
	.4byte update__5BTekiFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__5BTekiFR8Graphics
	.4byte refresh2d__5BTekiFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__5BTekiFv
	.4byte doAnimation__5BTekiFv
	.4byte doKill__5YTekiFv
	.4byte exitCourse__5YTekiFv
	.4byte __RTTI__5YTeki
	.4byte 0xFFFFFD48
	.4byte viewInit__10PelletViewFv
	.4byte "@696@viewKill__5BTekiFv"
	.4byte "@696@viewDraw__5BTekiFR8GraphicsR8Matrix4f"
	.4byte "@696@viewStartTrembleMotion__5BTekiFf"
	.4byte viewStartExplodeMotion__10PelletViewFf
	.4byte "@696@viewSetMotionSpeed__5BTekiFf"
	.4byte "@696@viewFinishMotion__5BTekiFv"
	.4byte "@696@viewDoAnimation__5BTekiFv"
	.4byte "@696@viewGetBottomRadius__5BTekiFv"
	.4byte "@696@viewGetHeight__5BTekiFv"
	.4byte "@696@viewGetScale__5BTekiFv"
	.4byte viewStartTrembleMotion__5BTekiFf
	.4byte viewSetMotionSpeed__5BTekiFf
	.4byte viewDoAnimation__5BTekiFv
	.4byte viewFinishMotion__5BTekiFv
	.4byte viewDraw__5BTekiFR8GraphicsR8Matrix4f
	.4byte viewKill__5BTekiFv
	.4byte viewGetScale__5BTekiFv
	.4byte viewGetBottomRadius__5BTekiFv
	.4byte viewGetHeight__5BTekiFv
	.4byte init__5YTekiFi
	.4byte reset__5BTekiFv
	.4byte startMotion__5BTekiFi
	.4byte die__5BTekiFv
	.4byte updateTimers__5BTekiFv
	.4byte gravitate__5BTekiFf
	.4byte animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent
	.4byte getTekiCollisionSize__5BTekiFv
	.4byte makeDamaged__5BTekiFv
	.4byte startDamageMotion__5BTekiFff
	.4byte generateTeki__5BTekiFi
	.4byte spawnTeki__5BTekiFi
	.4byte shootBall__5BTekiFR8Creature
	.4byte eventPerformed__5BTekiFR9TekiEvent
	.4byte interact__5BTekiFR18TekiInteractionKey
	.4byte interactDefault__5BTekiFR18TekiInteractionKey
	.4byte drawDefault__5BTekiFR8Graphics
	.4byte drawTekiShape__5BTekiFR8Graphics
	.4byte drawTekiDebugInfo__5BTekiFR8Graphics
	.4byte drawTekiDebugInfoDefault__5BTekiFR8Graphics
	.4byte playTableSound__5BTekiFi
	.4byte playSound__5BTekiFi
	.4byte stopSound__5BTekiFi
	.4byte createTekiEffect__5BTekiFi
	.4byte setTekiOption__5BTekiFi
	.4byte clearTekiOption__5BTekiFi
	.4byte setTekiOptions__5BTekiFi
	.4byte clearTekiOptions__5BTekiFv
	.4byte setAnimationKeyOption__5BTekiFi
	.4byte clearAnimationKeyOption__5BTekiFi
	.4byte setAnimationKeyOptions__5BTekiFi
	.4byte clearAnimationKeyOptions__5BTekiFv
	.4byte dieSoon__5BTekiFv
	.4byte becomeCorpse__5BTekiFv
	.4byte __RTTI__5YTeki
	.4byte 0xFFFFFAC8
	.4byte "@1336@4@animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent"
lbl_802DDBE4:
	.asciz "zen::CallBack1<zen::particleGenerator *>"
.balign 4
	.4byte 0
	.4byte 0
	.4byte 0
lbl_802DDC1C:
	.asciz "TAIeffectAttackEventCallBack"
.balign 4
.global __vt__28TAIeffectAttackEventCallBack
__vt__28TAIeffectAttackEventCallBack:
	.4byte __RTTI__28TAIeffectAttackEventCallBack
	.4byte 0
	.4byte hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature
	.4byte hitCreature__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParamP8Creature8Vector3f
	.4byte hitCreature__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature8Vector3f
	.4byte hitMap__28TAIeffectAttackEventCallBackFP20TAIeffectAttackParam
	.4byte playEventSound__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParam
	.4byte ptclHitMap__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParam
	.4byte hitCheckCulling__28TAIeffectAttackEventCallBackFPQ23zen17particleGeneratorP20TAIeffectAttackParamP8Creature
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E5E88:
	.4byte 0x00000000
lbl_803E5E8C:
	.4byte 0x00000000
lbl_803E5E90:
	.4byte 0x00000000
lbl_803E5E94:
	.4byte 0x00000000
lbl_803E5E98:
	.4byte 0x00000000
lbl_803E5E9C:
	.4byte 0x00000000
lbl_803E5EA0:
	.4byte 0x00000000
lbl_803E5EA4:
	.4byte 0x00000000
lbl_803E5EA8:
	.4byte 0x00000000
lbl_803E5EAC:
	.4byte 0x00000000
lbl_803E5EB0:
	.4byte 0x00000000
lbl_803E5EB4:
	.4byte 0x00000000
lbl_803E5EB8:
	.4byte 0x00000000
lbl_803E5EBC:
	.4byte 0x00000000
lbl_803E5EC0:
	.asciz "YTeki"
.balign 4
__RTTI__10PelletView:
	.4byte lbl_802DD8EC
	.4byte 0
__RTTI__19PaniAnimKeyListener:
	.4byte lbl_802DD8F8
	.4byte 0
__RTTI__11EventTalker:
	.4byte lbl_802DD90C
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802DD918
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802DD928
	.4byte lbl_802DD934
lbl_803E5EF0:
	.asciz "BTeki"
.balign 4
__RTTI__5BTeki:
	.4byte lbl_803E5EF0
	.4byte lbl_802DD948
lbl_803E5F00:
	.asciz "NTeki"
.balign 4
__RTTI__5NTeki:
	.4byte lbl_803E5F00
	.4byte lbl_802DD974
__RTTI__5YTeki:
	.4byte lbl_803E5EC0
	.4byte lbl_802DD9A8
__RTTI__28TAIeffectAttackEventCallBack:
	.4byte lbl_802DDC1C
	.4byte 0

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EB630:
	.4byte 0x00000000
lbl_803EB634:
	.4byte 0x42C80000
lbl_803EB638:
	.4byte 0x40000000
lbl_803EB63C:
	.4byte 0x40490FDB
lbl_803EB640:
	.4byte 0x3F800000
lbl_803EB644:
	.4byte 0x41200000
lbl_803EB648:
	.4byte 0x43340000
lbl_803EB64C:
	.4byte 0x3D4CCCCD
lbl_803EB650:
	.4byte 0xBF800000
lbl_803EB654:
	.4byte 0x44610000
