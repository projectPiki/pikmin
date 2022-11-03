.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__13FishGeneratorFv
__ct__13FishGeneratorFv:
/* 800E6668 000E35C8  7C 08 02 A6 */	mflr r0
/* 800E666C 000E35CC  38 80 00 25 */	li r4, 0x25
/* 800E6670 000E35D0  90 01 00 04 */	stw r0, 4(r1)
/* 800E6674 000E35D4  38 A0 00 00 */	li r5, 0
/* 800E6678 000E35D8  38 C0 00 00 */	li r6, 0
/* 800E667C 000E35DC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800E6680 000E35E0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800E6684 000E35E4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800E6688 000E35E8  3B C3 00 00 */	addi r30, r3, 0
/* 800E668C 000E35EC  48 00 F2 21 */	bl __ct__12ItemCreatureFiP12CreaturePropP5Shape
/* 800E6690 000E35F0  3C 60 80 2C */	lis r3, __vt__13FishGenerator@ha
/* 800E6694 000E35F4  38 63 BE 80 */	addi r3, r3, __vt__13FishGenerator@l
/* 800E6698 000E35F8  90 7E 00 00 */	stw r3, 0(r30)
/* 800E669C 000E35FC  38 03 01 14 */	addi r0, r3, 0x114
/* 800E66A0 000E3600  38 60 00 20 */	li r3, 0x20
/* 800E66A4 000E3604  90 1E 02 B8 */	stw r0, 0x2b8(r30)
/* 800E66A8 000E3608  38 00 00 00 */	li r0, 0
/* 800E66AC 000E360C  C0 02 99 90 */	lfs f0, lbl_803E9B90@sda21(r2)
/* 800E66B0 000E3610  D0 1E 03 DC */	stfs f0, 0x3dc(r30)
/* 800E66B4 000E3614  D0 1E 03 D8 */	stfs f0, 0x3d8(r30)
/* 800E66B8 000E3618  D0 1E 03 D4 */	stfs f0, 0x3d4(r30)
/* 800E66BC 000E361C  D0 1E 03 E8 */	stfs f0, 0x3e8(r30)
/* 800E66C0 000E3620  D0 1E 03 E4 */	stfs f0, 0x3e4(r30)
/* 800E66C4 000E3624  D0 1E 03 E0 */	stfs f0, 0x3e0(r30)
/* 800E66C8 000E3628  90 7E 03 CC */	stw r3, 0x3cc(r30)
/* 800E66CC 000E362C  90 1E 03 C8 */	stw r0, 0x3c8(r30)
/* 800E66D0 000E3630  83 FE 03 CC */	lwz r31, 0x3cc(r30)
/* 800E66D4 000E3634  1C 7F 00 1C */	mulli r3, r31, 0x1c
/* 800E66D8 000E3638  38 63 00 08 */	addi r3, r3, 8
/* 800E66DC 000E363C  4B F6 09 29 */	bl alloc__6SystemFUl
/* 800E66E0 000E3640  3C 80 80 0E */	lis r4, __ct__4FishFv@ha
/* 800E66E4 000E3644  38 84 67 18 */	addi r4, r4, __ct__4FishFv@l
/* 800E66E8 000E3648  38 FF 00 00 */	addi r7, r31, 0
/* 800E66EC 000E364C  38 A0 00 00 */	li r5, 0
/* 800E66F0 000E3650  38 C0 00 1C */	li r6, 0x1c
/* 800E66F4 000E3654  48 12 E5 35 */	bl __construct_new_array
/* 800E66F8 000E3658  90 7E 03 D0 */	stw r3, 0x3d0(r30)
/* 800E66FC 000E365C  7F C3 F3 78 */	mr r3, r30
/* 800E6700 000E3660  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800E6704 000E3664  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800E6708 000E3668  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800E670C 000E366C  38 21 00 20 */	addi r1, r1, 0x20
/* 800E6710 000E3670  7C 08 03 A6 */	mtlr r0
/* 800E6714 000E3674  4E 80 00 20 */	blr 

.global __ct__4FishFv
__ct__4FishFv:
/* 800E6718 000E3678  C0 02 99 90 */	lfs f0, lbl_803E9B90@sda21(r2)
/* 800E671C 000E367C  D0 03 00 08 */	stfs f0, 8(r3)
/* 800E6720 000E3680  D0 03 00 04 */	stfs f0, 4(r3)
/* 800E6724 000E3684  D0 03 00 00 */	stfs f0, 0(r3)
/* 800E6728 000E3688  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 800E672C 000E368C  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 800E6730 000E3690  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 800E6734 000E3694  4E 80 00 20 */	blr 

.global startAI__13FishGeneratorFi
startAI__13FishGeneratorFi:
/* 800E6738 000E3698  7C 08 02 A6 */	mflr r0
/* 800E673C 000E369C  90 01 00 04 */	stw r0, 4(r1)
/* 800E6740 000E36A0  38 00 00 20 */	li r0, 0x20
/* 800E6744 000E36A4  94 21 FF 20 */	stwu r1, -0xe0(r1)
/* 800E6748 000E36A8  DB E1 00 D8 */	stfd f31, 0xd8(r1)
/* 800E674C 000E36AC  DB C1 00 D0 */	stfd f30, 0xd0(r1)
/* 800E6750 000E36B0  DB A1 00 C8 */	stfd f29, 0xc8(r1)
/* 800E6754 000E36B4  DB 81 00 C0 */	stfd f28, 0xc0(r1)
/* 800E6758 000E36B8  DB 61 00 B8 */	stfd f27, 0xb8(r1)
/* 800E675C 000E36BC  DB 41 00 B0 */	stfd f26, 0xb0(r1)
/* 800E6760 000E36C0  DB 21 00 A8 */	stfd f25, 0xa8(r1)
/* 800E6764 000E36C4  DB 01 00 A0 */	stfd f24, 0xa0(r1)
/* 800E6768 000E36C8  DA E1 00 98 */	stfd f23, 0x98(r1)
/* 800E676C 000E36CC  BF 61 00 84 */	stmw r27, 0x84(r1)
/* 800E6770 000E36D0  3B 63 00 00 */	addi r27, r3, 0
/* 800E6774 000E36D4  3B A0 00 00 */	li r29, 0
/* 800E6778 000E36D8  3B C0 00 00 */	li r30, 0
/* 800E677C 000E36DC  3F E0 43 30 */	lis r31, 0x4330
/* 800E6780 000E36E0  90 03 03 C8 */	stw r0, 0x3c8(r3)
/* 800E6784 000E36E4  CB 42 99 A8 */	lfd f26, lbl_803E9BA8@sda21(r2)
/* 800E6788 000E36E8  C3 62 99 98 */	lfs f27, lbl_803E9B98@sda21(r2)
/* 800E678C 000E36EC  C3 82 99 94 */	lfs f28, lbl_803E9B94@sda21(r2)
/* 800E6790 000E36F0  C3 A2 99 9C */	lfs f29, lbl_803E9B9C@sda21(r2)
/* 800E6794 000E36F4  C3 C2 99 A0 */	lfs f30, lbl_803E9BA0@sda21(r2)
/* 800E6798 000E36F8  C3 E2 99 A4 */	lfs f31, lbl_803E9BA4@sda21(r2)
/* 800E679C 000E36FC  48 00 01 0C */	b .L_800E68A8
.L_800E67A0:
/* 800E67A0 000E3700  80 1B 03 D0 */	lwz r0, 0x3d0(r27)
/* 800E67A4 000E3704  7F 80 F2 14 */	add r28, r0, r30
/* 800E67A8 000E3708  48 13 18 C9 */	bl rand
/* 800E67AC 000E370C  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800E67B0 000E3710  90 01 00 7C */	stw r0, 0x7c(r1)
/* 800E67B4 000E3714  93 E1 00 78 */	stw r31, 0x78(r1)
/* 800E67B8 000E3718  C8 01 00 78 */	lfd f0, 0x78(r1)
/* 800E67BC 000E371C  EC 00 D0 28 */	fsubs f0, f0, f26
/* 800E67C0 000E3720  EC 00 D8 24 */	fdivs f0, f0, f27
/* 800E67C4 000E3724  EC 1C 00 32 */	fmuls f0, f28, f0
/* 800E67C8 000E3728  EF 1D 00 32 */	fmuls f24, f29, f0
/* 800E67CC 000E372C  48 13 18 A5 */	bl rand
/* 800E67D0 000E3730  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800E67D4 000E3734  90 01 00 74 */	stw r0, 0x74(r1)
/* 800E67D8 000E3738  93 E1 00 70 */	stw r31, 0x70(r1)
/* 800E67DC 000E373C  C8 01 00 70 */	lfd f0, 0x70(r1)
/* 800E67E0 000E3740  EC 00 D0 28 */	fsubs f0, f0, f26
/* 800E67E4 000E3744  EC 00 D8 24 */	fdivs f0, f0, f27
/* 800E67E8 000E3748  EC 1C 00 32 */	fmuls f0, f28, f0
/* 800E67EC 000E374C  EC 1F 00 32 */	fmuls f0, f31, f0
/* 800E67F0 000E3750  EE FE 00 32 */	fmuls f23, f30, f0
/* 800E67F4 000E3754  FC 20 B8 90 */	fmr f1, f23
/* 800E67F8 000E3758  48 13 53 5D */	bl cosf
/* 800E67FC 000E375C  EF 38 00 72 */	fmuls f25, f24, f1
/* 800E6800 000E3760  FC 20 B8 90 */	fmr f1, f23
/* 800E6804 000E3764  48 13 54 E5 */	bl sinf
/* 800E6808 000E3768  EC 38 00 72 */	fmuls f1, f24, f1
/* 800E680C 000E376C  C0 0D C8 C0 */	lfs f0, lbl_803E15E0@sda21(r13)
/* 800E6810 000E3770  D0 21 00 48 */	stfs f1, 0x48(r1)
/* 800E6814 000E3774  C0 5B 00 94 */	lfs f2, 0x94(r27)
/* 800E6818 000E3778  C0 21 00 48 */	lfs f1, 0x48(r1)
/* 800E681C 000E377C  EC 22 08 2A */	fadds f1, f2, f1
/* 800E6820 000E3780  D0 21 00 3C */	stfs f1, 0x3c(r1)
/* 800E6824 000E3784  C0 21 00 3C */	lfs f1, 0x3c(r1)
/* 800E6828 000E3788  D0 21 00 58 */	stfs f1, 0x58(r1)
/* 800E682C 000E378C  C0 3B 00 98 */	lfs f1, 0x98(r27)
/* 800E6830 000E3790  EC 01 00 2A */	fadds f0, f1, f0
/* 800E6834 000E3794  D0 01 00 5C */	stfs f0, 0x5c(r1)
/* 800E6838 000E3798  C0 1B 00 9C */	lfs f0, 0x9c(r27)
/* 800E683C 000E379C  EC 00 C8 2A */	fadds f0, f0, f25
/* 800E6840 000E37A0  D0 01 00 60 */	stfs f0, 0x60(r1)
/* 800E6844 000E37A4  80 61 00 58 */	lwz r3, 0x58(r1)
/* 800E6848 000E37A8  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 800E684C 000E37AC  90 7C 00 00 */	stw r3, 0(r28)
/* 800E6850 000E37B0  90 1C 00 04 */	stw r0, 4(r28)
/* 800E6854 000E37B4  80 01 00 60 */	lwz r0, 0x60(r1)
/* 800E6858 000E37B8  90 1C 00 08 */	stw r0, 8(r28)
/* 800E685C 000E37BC  C0 0D C8 C4 */	lfs f0, lbl_803E15E4@sda21(r13)
/* 800E6860 000E37C0  D0 1C 00 0C */	stfs f0, 0xc(r28)
/* 800E6864 000E37C4  C0 0D C8 C8 */	lfs f0, lbl_803E15E8@sda21(r13)
/* 800E6868 000E37C8  D0 1C 00 10 */	stfs f0, 0x10(r28)
/* 800E686C 000E37CC  C0 0D C8 CC */	lfs f0, lbl_803E15EC@sda21(r13)
/* 800E6870 000E37D0  D0 1C 00 14 */	stfs f0, 0x14(r28)
/* 800E6874 000E37D4  48 13 17 FD */	bl rand
/* 800E6878 000E37D8  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800E687C 000E37DC  90 01 00 6C */	stw r0, 0x6c(r1)
/* 800E6880 000E37E0  3B DE 00 1C */	addi r30, r30, 0x1c
/* 800E6884 000E37E4  3B BD 00 01 */	addi r29, r29, 1
/* 800E6888 000E37E8  93 E1 00 68 */	stw r31, 0x68(r1)
/* 800E688C 000E37EC  C8 01 00 68 */	lfd f0, 0x68(r1)
/* 800E6890 000E37F0  EC 00 D0 28 */	fsubs f0, f0, f26
/* 800E6894 000E37F4  EC 00 D8 24 */	fdivs f0, f0, f27
/* 800E6898 000E37F8  EC 1C 00 32 */	fmuls f0, f28, f0
/* 800E689C 000E37FC  EC 1F 00 32 */	fmuls f0, f31, f0
/* 800E68A0 000E3800  EC 1E 00 32 */	fmuls f0, f30, f0
/* 800E68A4 000E3804  D0 1C 00 18 */	stfs f0, 0x18(r28)
.L_800E68A8:
/* 800E68A8 000E3808  80 1B 03 C8 */	lwz r0, 0x3c8(r27)
/* 800E68AC 000E380C  7C 1D 00 00 */	cmpw r29, r0
/* 800E68B0 000E3810  41 80 FE F0 */	blt .L_800E67A0
/* 800E68B4 000E3814  BB 61 00 84 */	lmw r27, 0x84(r1)
/* 800E68B8 000E3818  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 800E68BC 000E381C  CB E1 00 D8 */	lfd f31, 0xd8(r1)
/* 800E68C0 000E3820  CB C1 00 D0 */	lfd f30, 0xd0(r1)
/* 800E68C4 000E3824  CB A1 00 C8 */	lfd f29, 0xc8(r1)
/* 800E68C8 000E3828  CB 81 00 C0 */	lfd f28, 0xc0(r1)
/* 800E68CC 000E382C  CB 61 00 B8 */	lfd f27, 0xb8(r1)
/* 800E68D0 000E3830  CB 41 00 B0 */	lfd f26, 0xb0(r1)
/* 800E68D4 000E3834  CB 21 00 A8 */	lfd f25, 0xa8(r1)
/* 800E68D8 000E3838  CB 01 00 A0 */	lfd f24, 0xa0(r1)
/* 800E68DC 000E383C  CA E1 00 98 */	lfd f23, 0x98(r1)
/* 800E68E0 000E3840  38 21 00 E0 */	addi r1, r1, 0xe0
/* 800E68E4 000E3844  7C 08 03 A6 */	mtlr r0
/* 800E68E8 000E3848  4E 80 00 20 */	blr 

.global update__13FishGeneratorFv
update__13FishGeneratorFv:
/* 800E68EC 000E384C  7C 08 02 A6 */	mflr r0
/* 800E68F0 000E3850  38 A0 00 00 */	li r5, 0
/* 800E68F4 000E3854  90 01 00 04 */	stw r0, 4(r1)
/* 800E68F8 000E3858  38 80 00 00 */	li r4, 0
/* 800E68FC 000E385C  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800E6900 000E3860  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 800E6904 000E3864  93 C1 00 48 */	stw r30, 0x48(r1)
/* 800E6908 000E3868  93 A1 00 44 */	stw r29, 0x44(r1)
/* 800E690C 000E386C  3B A3 00 00 */	addi r29, r3, 0
/* 800E6910 000E3870  C0 0D C8 D0 */	lfs f0, lbl_803E15F0@sda21(r13)
/* 800E6914 000E3874  D0 03 03 D4 */	stfs f0, 0x3d4(r3)
/* 800E6918 000E3878  C0 0D C8 D4 */	lfs f0, lbl_803E15F4@sda21(r13)
/* 800E691C 000E387C  D0 03 03 D8 */	stfs f0, 0x3d8(r3)
/* 800E6920 000E3880  C0 0D C8 D8 */	lfs f0, lbl_803E15F8@sda21(r13)
/* 800E6924 000E3884  D0 03 03 DC */	stfs f0, 0x3dc(r3)
/* 800E6928 000E3888  48 00 00 64 */	b .L_800E698C
.L_800E692C:
/* 800E692C 000E388C  80 1D 03 D0 */	lwz r0, 0x3d0(r29)
/* 800E6930 000E3890  38 A5 00 01 */	addi r5, r5, 1
/* 800E6934 000E3894  C0 3D 03 D4 */	lfs f1, 0x3d4(r29)
/* 800E6938 000E3898  7C 60 22 14 */	add r3, r0, r4
/* 800E693C 000E389C  C0 03 00 00 */	lfs f0, 0(r3)
/* 800E6940 000E38A0  38 84 00 1C */	addi r4, r4, 0x1c
/* 800E6944 000E38A4  EC 01 00 2A */	fadds f0, f1, f0
/* 800E6948 000E38A8  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 800E694C 000E38AC  C0 01 00 1C */	lfs f0, 0x1c(r1)
/* 800E6950 000E38B0  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 800E6954 000E38B4  C0 3D 03 D8 */	lfs f1, 0x3d8(r29)
/* 800E6958 000E38B8  C0 03 00 04 */	lfs f0, 4(r3)
/* 800E695C 000E38BC  EC 01 00 2A */	fadds f0, f1, f0
/* 800E6960 000E38C0  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 800E6964 000E38C4  C0 3D 03 DC */	lfs f1, 0x3dc(r29)
/* 800E6968 000E38C8  C0 03 00 08 */	lfs f0, 8(r3)
/* 800E696C 000E38CC  EC 01 00 2A */	fadds f0, f1, f0
/* 800E6970 000E38D0  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 800E6974 000E38D4  80 61 00 28 */	lwz r3, 0x28(r1)
/* 800E6978 000E38D8  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800E697C 000E38DC  90 7D 03 D4 */	stw r3, 0x3d4(r29)
/* 800E6980 000E38E0  90 1D 03 D8 */	stw r0, 0x3d8(r29)
/* 800E6984 000E38E4  80 01 00 30 */	lwz r0, 0x30(r1)
/* 800E6988 000E38E8  90 1D 03 DC */	stw r0, 0x3dc(r29)
.L_800E698C:
/* 800E698C 000E38EC  80 1D 03 C8 */	lwz r0, 0x3c8(r29)
/* 800E6990 000E38F0  7C 05 00 00 */	cmpw r5, r0
/* 800E6994 000E38F4  41 80 FF 98 */	blt .L_800E692C
/* 800E6998 000E38F8  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 800E699C 000E38FC  C8 42 99 A8 */	lfd f2, lbl_803E9BA8@sda21(r2)
/* 800E69A0 000E3900  90 01 00 3C */	stw r0, 0x3c(r1)
/* 800E69A4 000E3904  3C 00 43 30 */	lis r0, 0x4330
/* 800E69A8 000E3908  3B C0 00 00 */	li r30, 0
/* 800E69AC 000E390C  C0 62 99 94 */	lfs f3, lbl_803E9B94@sda21(r2)
/* 800E69B0 000E3910  90 01 00 38 */	stw r0, 0x38(r1)
/* 800E69B4 000E3914  C0 1D 03 D4 */	lfs f0, 0x3d4(r29)
/* 800E69B8 000E3918  1F FE 00 1C */	mulli r31, r30, 0x1c
/* 800E69BC 000E391C  C8 21 00 38 */	lfd f1, 0x38(r1)
/* 800E69C0 000E3920  EC 21 10 28 */	fsubs f1, f1, f2
/* 800E69C4 000E3924  EC 23 08 24 */	fdivs f1, f3, f1
/* 800E69C8 000E3928  EC 00 00 72 */	fmuls f0, f0, f1
/* 800E69CC 000E392C  D0 1D 03 D4 */	stfs f0, 0x3d4(r29)
/* 800E69D0 000E3930  C0 1D 03 D8 */	lfs f0, 0x3d8(r29)
/* 800E69D4 000E3934  EC 00 00 72 */	fmuls f0, f0, f1
/* 800E69D8 000E3938  D0 1D 03 D8 */	stfs f0, 0x3d8(r29)
/* 800E69DC 000E393C  C0 1D 03 DC */	lfs f0, 0x3dc(r29)
/* 800E69E0 000E3940  EC 00 00 72 */	fmuls f0, f0, f1
/* 800E69E4 000E3944  D0 1D 03 DC */	stfs f0, 0x3dc(r29)
/* 800E69E8 000E3948  48 00 00 1C */	b .L_800E6A04
.L_800E69EC:
/* 800E69EC 000E394C  80 1D 03 D0 */	lwz r0, 0x3d0(r29)
/* 800E69F0 000E3950  38 7D 00 00 */	addi r3, r29, 0
/* 800E69F4 000E3954  7C 80 FA 14 */	add r4, r0, r31
/* 800E69F8 000E3958  48 00 00 35 */	bl moveFish__13FishGeneratorFP4Fish
/* 800E69FC 000E395C  3B FF 00 1C */	addi r31, r31, 0x1c
/* 800E6A00 000E3960  3B DE 00 01 */	addi r30, r30, 1
.L_800E6A04:
/* 800E6A04 000E3964  80 1D 03 C8 */	lwz r0, 0x3c8(r29)
/* 800E6A08 000E3968  7C 1E 00 00 */	cmpw r30, r0
/* 800E6A0C 000E396C  41 80 FF E0 */	blt .L_800E69EC
/* 800E6A10 000E3970  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800E6A14 000E3974  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 800E6A18 000E3978  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 800E6A1C 000E397C  83 A1 00 44 */	lwz r29, 0x44(r1)
/* 800E6A20 000E3980  38 21 00 50 */	addi r1, r1, 0x50
/* 800E6A24 000E3984  7C 08 03 A6 */	mtlr r0
/* 800E6A28 000E3988  4E 80 00 20 */	blr 

.global moveFish__13FishGeneratorFP4Fish
moveFish__13FishGeneratorFP4Fish:
/* 800E6A2C 000E398C  7C 08 02 A6 */	mflr r0
/* 800E6A30 000E3990  90 01 00 04 */	stw r0, 4(r1)
/* 800E6A34 000E3994  94 21 FC F8 */	stwu r1, -0x308(r1)
/* 800E6A38 000E3998  DB E1 03 00 */	stfd f31, 0x300(r1)
/* 800E6A3C 000E399C  DB C1 02 F8 */	stfd f30, 0x2f8(r1)
/* 800E6A40 000E39A0  DB A1 02 F0 */	stfd f29, 0x2f0(r1)
/* 800E6A44 000E39A4  DB 81 02 E8 */	stfd f28, 0x2e8(r1)
/* 800E6A48 000E39A8  DB 61 02 E0 */	stfd f27, 0x2e0(r1)
/* 800E6A4C 000E39AC  DB 41 02 D8 */	stfd f26, 0x2d8(r1)
/* 800E6A50 000E39B0  DB 21 02 D0 */	stfd f25, 0x2d0(r1)
/* 800E6A54 000E39B4  DB 01 02 C8 */	stfd f24, 0x2c8(r1)
/* 800E6A58 000E39B8  DA E1 02 C0 */	stfd f23, 0x2c0(r1)
/* 800E6A5C 000E39BC  DA C1 02 B8 */	stfd f22, 0x2b8(r1)
/* 800E6A60 000E39C0  DA A1 02 B0 */	stfd f21, 0x2b0(r1)
/* 800E6A64 000E39C4  BF 21 02 94 */	stmw r25, 0x294(r1)
/* 800E6A68 000E39C8  7C 79 1B 78 */	mr r25, r3
/* 800E6A6C 000E39CC  7C 9F 23 78 */	mr r31, r4
/* 800E6A70 000E39D0  3B 80 00 00 */	li r28, 0
/* 800E6A74 000E39D4  3B 60 00 00 */	li r27, 0
/* 800E6A78 000E39D8  3B A0 00 00 */	li r29, 0
/* 800E6A7C 000E39DC  3B C0 00 00 */	li r30, 0
/* 800E6A80 000E39E0  C2 A2 99 B0 */	lfs f21, lbl_803E9BB0@sda21(r2)
/* 800E6A84 000E39E4  C3 AD C8 DC */	lfs f29, lbl_803E15FC@sda21(r13)
/* 800E6A88 000E39E8  FF C0 A8 90 */	fmr f30, f21
/* 800E6A8C 000E39EC  C3 8D C8 E0 */	lfs f28, lbl_803E1600@sda21(r13)
/* 800E6A90 000E39F0  C3 6D C8 E4 */	lfs f27, lbl_803E1604@sda21(r13)
/* 800E6A94 000E39F4  C3 4D C8 E8 */	lfs f26, lbl_803E1608@sda21(r13)
/* 800E6A98 000E39F8  C3 2D C8 EC */	lfs f25, lbl_803E160C@sda21(r13)
/* 800E6A9C 000E39FC  C3 0D C8 F0 */	lfs f24, lbl_803E1610@sda21(r13)
/* 800E6AA0 000E3A00  C3 E2 99 B4 */	lfs f31, lbl_803E9BB4@sda21(r2)
/* 800E6AA4 000E3A04  C2 C2 99 90 */	lfs f22, lbl_803E9B90@sda21(r2)
/* 800E6AA8 000E3A08  48 00 00 C4 */	b .L_800E6B6C
.L_800E6AAC:
/* 800E6AAC 000E3A0C  80 19 03 D0 */	lwz r0, 0x3d0(r25)
/* 800E6AB0 000E3A10  7C 00 F2 14 */	add r0, r0, r30
/* 800E6AB4 000E3A14  7C 00 F8 40 */	cmplw r0, r31
/* 800E6AB8 000E3A18  7C 1A 03 78 */	mr r26, r0
/* 800E6ABC 000E3A1C  41 82 00 A8 */	beq .L_800E6B64
/* 800E6AC0 000E3A20  C0 3A 00 00 */	lfs f1, 0(r26)
/* 800E6AC4 000E3A24  C0 5A 00 08 */	lfs f2, 8(r26)
/* 800E6AC8 000E3A28  C0 7F 00 00 */	lfs f3, 0(r31)
/* 800E6ACC 000E3A2C  C0 9F 00 08 */	lfs f4, 8(r31)
/* 800E6AD0 000E3A30  4B F5 1B 59 */	bl qdist2__Fffff
/* 800E6AD4 000E3A34  FE E0 08 90 */	fmr f23, f1
/* 800E6AD8 000E3A38  FC 17 F0 40 */	fcmpo cr0, f23, f30
/* 800E6ADC 000E3A3C  40 80 00 20 */	bge .L_800E6AFC
/* 800E6AE0 000E3A40  C0 5A 00 0C */	lfs f2, 0xc(r26)
/* 800E6AE4 000E3A44  3B 7B 00 01 */	addi r27, r27, 1
/* 800E6AE8 000E3A48  C0 3A 00 10 */	lfs f1, 0x10(r26)
/* 800E6AEC 000E3A4C  C0 1A 00 14 */	lfs f0, 0x14(r26)
/* 800E6AF0 000E3A50  EF BD 10 2A */	fadds f29, f29, f2
/* 800E6AF4 000E3A54  EF 9C 08 2A */	fadds f28, f28, f1
/* 800E6AF8 000E3A58  EF 7B 00 2A */	fadds f27, f27, f0
.L_800E6AFC:
/* 800E6AFC 000E3A5C  FC 17 A8 40 */	fcmpo cr0, f23, f21
/* 800E6B00 000E3A60  40 80 00 64 */	bge .L_800E6B64
/* 800E6B04 000E3A64  FC 17 F8 40 */	fcmpo cr0, f23, f31
/* 800E6B08 000E3A68  7F 5C D3 78 */	mr r28, r26
/* 800E6B0C 000E3A6C  40 80 00 54 */	bge .L_800E6B60
/* 800E6B10 000E3A70  C0 7F 00 00 */	lfs f3, 0(r31)
/* 800E6B14 000E3A74  C0 5A 00 00 */	lfs f2, 0(r26)
/* 800E6B18 000E3A78  C0 3F 00 04 */	lfs f1, 4(r31)
/* 800E6B1C 000E3A7C  C0 1A 00 04 */	lfs f0, 4(r26)
/* 800E6B20 000E3A80  EF 43 10 28 */	fsubs f26, f3, f2
/* 800E6B24 000E3A84  C0 5F 00 08 */	lfs f2, 8(r31)
/* 800E6B28 000E3A88  EF 21 00 28 */	fsubs f25, f1, f0
/* 800E6B2C 000E3A8C  C0 1A 00 08 */	lfs f0, 8(r26)
/* 800E6B30 000E3A90  EC 3A 06 B2 */	fmuls f1, f26, f26
/* 800E6B34 000E3A94  EF 02 00 28 */	fsubs f24, f2, f0
/* 800E6B38 000E3A98  EC 19 06 72 */	fmuls f0, f25, f25
/* 800E6B3C 000E3A9C  EC 58 06 32 */	fmuls f2, f24, f24
/* 800E6B40 000E3AA0  EC 01 00 2A */	fadds f0, f1, f0
/* 800E6B44 000E3AA4  EC 22 00 2A */	fadds f1, f2, f0
/* 800E6B48 000E3AA8  4B F2 70 F9 */	bl sqrtf__3stdFf
/* 800E6B4C 000E3AAC  FC 16 08 00 */	fcmpu cr0, f22, f1
/* 800E6B50 000E3AB0  41 82 00 10 */	beq .L_800E6B60
/* 800E6B54 000E3AB4  EF 5A 08 24 */	fdivs f26, f26, f1
/* 800E6B58 000E3AB8  EF 39 08 24 */	fdivs f25, f25, f1
/* 800E6B5C 000E3ABC  EF 18 08 24 */	fdivs f24, f24, f1
.L_800E6B60:
/* 800E6B60 000E3AC0  FE A0 B8 90 */	fmr f21, f23
.L_800E6B64:
/* 800E6B64 000E3AC4  3B DE 00 1C */	addi r30, r30, 0x1c
/* 800E6B68 000E3AC8  3B BD 00 01 */	addi r29, r29, 1
.L_800E6B6C:
/* 800E6B6C 000E3ACC  80 19 03 C8 */	lwz r0, 0x3c8(r25)
/* 800E6B70 000E3AD0  7C 1D 00 00 */	cmpw r29, r0
/* 800E6B74 000E3AD4  41 80 FF 38 */	blt .L_800E6AAC
/* 800E6B78 000E3AD8  2C 1B 00 00 */	cmpwi r27, 0
/* 800E6B7C 000E3ADC  40 81 00 34 */	ble .L_800E6BB0
/* 800E6B80 000E3AE0  6F 60 80 00 */	xoris r0, r27, 0x8000
/* 800E6B84 000E3AE4  C8 22 99 A8 */	lfd f1, lbl_803E9BA8@sda21(r2)
/* 800E6B88 000E3AE8  90 01 02 8C */	stw r0, 0x28c(r1)
/* 800E6B8C 000E3AEC  3C 00 43 30 */	lis r0, 0x4330
/* 800E6B90 000E3AF0  C0 42 99 94 */	lfs f2, lbl_803E9B94@sda21(r2)
/* 800E6B94 000E3AF4  90 01 02 88 */	stw r0, 0x288(r1)
/* 800E6B98 000E3AF8  C8 01 02 88 */	lfd f0, 0x288(r1)
/* 800E6B9C 000E3AFC  EC 00 08 28 */	fsubs f0, f0, f1
/* 800E6BA0 000E3B00  EC 02 00 24 */	fdivs f0, f2, f0
/* 800E6BA4 000E3B04  EF BD 00 32 */	fmuls f29, f29, f0
/* 800E6BA8 000E3B08  EF 9C 00 32 */	fmuls f28, f28, f0
/* 800E6BAC 000E3B0C  EF 7B 00 32 */	fmuls f27, f27, f0
.L_800E6BB0:
/* 800E6BB0 000E3B10  28 1C 00 00 */	cmplwi r28, 0
/* 800E6BB4 000E3B14  41 82 01 7C */	beq .L_800E6D30
/* 800E6BB8 000E3B18  48 13 14 B9 */	bl rand
/* 800E6BBC 000E3B1C  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800E6BC0 000E3B20  C8 82 99 A8 */	lfd f4, lbl_803E9BA8@sda21(r2)
/* 800E6BC4 000E3B24  90 01 02 8C */	stw r0, 0x28c(r1)
/* 800E6BC8 000E3B28  3C 00 43 30 */	lis r0, 0x4330
/* 800E6BCC 000E3B2C  C0 42 99 98 */	lfs f2, lbl_803E9B98@sda21(r2)
/* 800E6BD0 000E3B30  90 01 02 88 */	stw r0, 0x288(r1)
/* 800E6BD4 000E3B34  C0 22 99 94 */	lfs f1, lbl_803E9B94@sda21(r2)
/* 800E6BD8 000E3B38  C8 61 02 88 */	lfd f3, 0x288(r1)
/* 800E6BDC 000E3B3C  C0 02 99 B8 */	lfs f0, lbl_803E9BB8@sda21(r2)
/* 800E6BE0 000E3B40  EC 63 20 28 */	fsubs f3, f3, f4
/* 800E6BE4 000E3B44  EC 43 10 24 */	fdivs f2, f3, f2
/* 800E6BE8 000E3B48  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800E6BEC 000E3B4C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800E6BF0 000E3B50  40 81 01 40 */	ble .L_800E6D30
/* 800E6BF4 000E3B54  C0 79 03 D4 */	lfs f3, 0x3d4(r25)
/* 800E6BF8 000E3B58  C0 5F 00 00 */	lfs f2, 0(r31)
/* 800E6BFC 000E3B5C  C0 39 03 D8 */	lfs f1, 0x3d8(r25)
/* 800E6C00 000E3B60  C0 1F 00 04 */	lfs f0, 4(r31)
/* 800E6C04 000E3B64  EF C3 10 28 */	fsubs f30, f3, f2
/* 800E6C08 000E3B68  C0 59 03 DC */	lfs f2, 0x3dc(r25)
/* 800E6C0C 000E3B6C  EF E1 00 28 */	fsubs f31, f1, f0
/* 800E6C10 000E3B70  C0 1F 00 08 */	lfs f0, 8(r31)
/* 800E6C14 000E3B74  EC 3E 07 B2 */	fmuls f1, f30, f30
/* 800E6C18 000E3B78  EE E2 00 28 */	fsubs f23, f2, f0
/* 800E6C1C 000E3B7C  EC 1F 07 F2 */	fmuls f0, f31, f31
/* 800E6C20 000E3B80  EC 57 05 F2 */	fmuls f2, f23, f23
/* 800E6C24 000E3B84  EC 01 00 2A */	fadds f0, f1, f0
/* 800E6C28 000E3B88  EC 22 00 2A */	fadds f1, f2, f0
/* 800E6C2C 000E3B8C  4B F2 70 15 */	bl sqrtf__3stdFf
/* 800E6C30 000E3B90  C0 02 99 90 */	lfs f0, lbl_803E9B90@sda21(r2)
/* 800E6C34 000E3B94  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800E6C38 000E3B98  41 82 00 10 */	beq .L_800E6C48
/* 800E6C3C 000E3B9C  EF DE 08 24 */	fdivs f30, f30, f1
/* 800E6C40 000E3BA0  EF FF 08 24 */	fdivs f31, f31, f1
/* 800E6C44 000E3BA4  EE F7 08 24 */	fdivs f23, f23, f1
.L_800E6C48:
/* 800E6C48 000E3BA8  C1 0D C8 FC */	lfs f8, lbl_803E161C@sda21(r13)
/* 800E6C4C 000E3BAC  C0 8D C8 F4 */	lfs f4, lbl_803E1614@sda21(r13)
/* 800E6C50 000E3BB0  C0 AD C8 F8 */	lfs f5, lbl_803E1618@sda21(r13)
/* 800E6C54 000E3BB4  EC 1D 02 32 */	fmuls f0, f29, f8
/* 800E6C58 000E3BB8  EC 3E 01 32 */	fmuls f1, f30, f4
/* 800E6C5C 000E3BBC  C0 ED C9 00 */	lfs f7, lbl_803E1620@sda21(r13)
/* 800E6C60 000E3BC0  EC 5A 01 72 */	fmuls f2, f26, f5
/* 800E6C64 000E3BC4  D0 01 01 54 */	stfs f0, 0x154(r1)
/* 800E6C68 000E3BC8  C0 CD C9 04 */	lfs f6, lbl_803E1624@sda21(r13)
/* 800E6C6C 000E3BCC  EC 21 01 F2 */	fmuls f1, f1, f7
/* 800E6C70 000E3BD0  C0 61 01 54 */	lfs f3, 0x154(r1)
/* 800E6C74 000E3BD4  EC 42 01 B2 */	fmuls f2, f2, f6
/* 800E6C78 000E3BD8  EC 1C 02 32 */	fmuls f0, f28, f8
/* 800E6C7C 000E3BDC  D0 61 01 E4 */	stfs f3, 0x1e4(r1)
/* 800E6C80 000E3BE0  D0 41 01 38 */	stfs f2, 0x138(r1)
/* 800E6C84 000E3BE4  EC 5B 02 32 */	fmuls f2, f27, f8
/* 800E6C88 000E3BE8  D0 21 01 4C */	stfs f1, 0x14c(r1)
/* 800E6C8C 000E3BEC  EC 3F 01 32 */	fmuls f1, f31, f4
/* 800E6C90 000E3BF0  EC 97 01 32 */	fmuls f4, f23, f4
/* 800E6C94 000E3BF4  D0 01 01 E8 */	stfs f0, 0x1e8(r1)
/* 800E6C98 000E3BF8  EC 19 01 72 */	fmuls f0, f25, f5
/* 800E6C9C 000E3BFC  EC 21 01 F2 */	fmuls f1, f1, f7
/* 800E6CA0 000E3C00  D0 41 01 EC */	stfs f2, 0x1ec(r1)
/* 800E6CA4 000E3C04  EC 84 01 F2 */	fmuls f4, f4, f7
/* 800E6CA8 000E3C08  C0 61 01 E4 */	lfs f3, 0x1e4(r1)
/* 800E6CAC 000E3C0C  EC 00 01 B2 */	fmuls f0, f0, f6
/* 800E6CB0 000E3C10  C0 41 01 4C */	lfs f2, 0x14c(r1)
/* 800E6CB4 000E3C14  EC B8 01 72 */	fmuls f5, f24, f5
/* 800E6CB8 000E3C18  EC 43 10 2A */	fadds f2, f3, f2
/* 800E6CBC 000E3C1C  EC 65 01 B2 */	fmuls f3, f5, f6
/* 800E6CC0 000E3C20  D0 41 01 40 */	stfs f2, 0x140(r1)
/* 800E6CC4 000E3C24  C0 41 01 40 */	lfs f2, 0x140(r1)
/* 800E6CC8 000E3C28  D0 41 01 F0 */	stfs f2, 0x1f0(r1)
/* 800E6CCC 000E3C2C  C0 41 01 E8 */	lfs f2, 0x1e8(r1)
/* 800E6CD0 000E3C30  EC 22 08 2A */	fadds f1, f2, f1
/* 800E6CD4 000E3C34  D0 21 01 F4 */	stfs f1, 0x1f4(r1)
/* 800E6CD8 000E3C38  C0 21 01 EC */	lfs f1, 0x1ec(r1)
/* 800E6CDC 000E3C3C  EC 21 20 2A */	fadds f1, f1, f4
/* 800E6CE0 000E3C40  D0 21 01 F8 */	stfs f1, 0x1f8(r1)
/* 800E6CE4 000E3C44  C0 41 01 F0 */	lfs f2, 0x1f0(r1)
/* 800E6CE8 000E3C48  C0 21 01 38 */	lfs f1, 0x138(r1)
/* 800E6CEC 000E3C4C  EC 22 08 2A */	fadds f1, f2, f1
/* 800E6CF0 000E3C50  D0 21 01 2C */	stfs f1, 0x12c(r1)
/* 800E6CF4 000E3C54  C0 21 01 2C */	lfs f1, 0x12c(r1)
/* 800E6CF8 000E3C58  D0 21 01 FC */	stfs f1, 0x1fc(r1)
/* 800E6CFC 000E3C5C  C0 21 01 F4 */	lfs f1, 0x1f4(r1)
/* 800E6D00 000E3C60  EC 01 00 2A */	fadds f0, f1, f0
/* 800E6D04 000E3C64  D0 01 02 00 */	stfs f0, 0x200(r1)
/* 800E6D08 000E3C68  C0 01 01 F8 */	lfs f0, 0x1f8(r1)
/* 800E6D0C 000E3C6C  EC 00 18 2A */	fadds f0, f0, f3
/* 800E6D10 000E3C70  D0 01 02 04 */	stfs f0, 0x204(r1)
/* 800E6D14 000E3C74  80 61 01 FC */	lwz r3, 0x1fc(r1)
/* 800E6D18 000E3C78  80 01 02 00 */	lwz r0, 0x200(r1)
/* 800E6D1C 000E3C7C  90 7F 00 0C */	stw r3, 0xc(r31)
/* 800E6D20 000E3C80  90 1F 00 10 */	stw r0, 0x10(r31)
/* 800E6D24 000E3C84  80 01 02 04 */	lwz r0, 0x204(r1)
/* 800E6D28 000E3C88  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800E6D2C 000E3C8C  48 00 01 68 */	b .L_800E6E94
.L_800E6D30:
/* 800E6D30 000E3C90  48 13 13 41 */	bl rand
/* 800E6D34 000E3C94  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800E6D38 000E3C98  C8 42 99 A8 */	lfd f2, lbl_803E9BA8@sda21(r2)
/* 800E6D3C 000E3C9C  90 01 02 8C */	stw r0, 0x28c(r1)
/* 800E6D40 000E3CA0  3C 00 43 30 */	lis r0, 0x4330
/* 800E6D44 000E3CA4  C0 A2 99 98 */	lfs f5, lbl_803E9B98@sda21(r2)
/* 800E6D48 000E3CA8  90 01 02 88 */	stw r0, 0x288(r1)
/* 800E6D4C 000E3CAC  C0 82 99 94 */	lfs f4, lbl_803E9B94@sda21(r2)
/* 800E6D50 000E3CB0  C8 01 02 88 */	lfd f0, 0x288(r1)
/* 800E6D54 000E3CB4  C0 22 99 BC */	lfs f1, lbl_803E9BBC@sda21(r2)
/* 800E6D58 000E3CB8  EC C0 10 28 */	fsubs f6, f0, f2
/* 800E6D5C 000E3CBC  C0 42 99 A4 */	lfs f2, lbl_803E9BA4@sda21(r2)
/* 800E6D60 000E3CC0  C0 62 99 B8 */	lfs f3, lbl_803E9BB8@sda21(r2)
/* 800E6D64 000E3CC4  C0 1F 00 18 */	lfs f0, 0x18(r31)
/* 800E6D68 000E3CC8  EC A6 28 24 */	fdivs f5, f6, f5
/* 800E6D6C 000E3CCC  EC 84 01 72 */	fmuls f4, f4, f5
/* 800E6D70 000E3CD0  EC 24 08 28 */	fsubs f1, f4, f1
/* 800E6D74 000E3CD4  EC 22 00 72 */	fmuls f1, f2, f1
/* 800E6D78 000E3CD8  EC 23 00 72 */	fmuls f1, f3, f1
/* 800E6D7C 000E3CDC  EC 20 08 2A */	fadds f1, f0, f1
/* 800E6D80 000E3CE0  4B F5 18 09 */	bl roundAng__Ff
/* 800E6D84 000E3CE4  D0 3F 00 18 */	stfs f1, 0x18(r31)
/* 800E6D88 000E3CE8  C0 79 03 D4 */	lfs f3, 0x3d4(r25)
/* 800E6D8C 000E3CEC  C0 5F 00 00 */	lfs f2, 0(r31)
/* 800E6D90 000E3CF0  C0 39 03 D8 */	lfs f1, 0x3d8(r25)
/* 800E6D94 000E3CF4  C0 1F 00 04 */	lfs f0, 4(r31)
/* 800E6D98 000E3CF8  EF 03 10 28 */	fsubs f24, f3, f2
/* 800E6D9C 000E3CFC  C0 59 03 DC */	lfs f2, 0x3dc(r25)
/* 800E6DA0 000E3D00  EF 21 00 28 */	fsubs f25, f1, f0
/* 800E6DA4 000E3D04  C0 1F 00 08 */	lfs f0, 8(r31)
/* 800E6DA8 000E3D08  EC 38 06 32 */	fmuls f1, f24, f24
/* 800E6DAC 000E3D0C  EE C2 00 28 */	fsubs f22, f2, f0
/* 800E6DB0 000E3D10  EC 19 06 72 */	fmuls f0, f25, f25
/* 800E6DB4 000E3D14  EC 56 05 B2 */	fmuls f2, f22, f22
/* 800E6DB8 000E3D18  EC 01 00 2A */	fadds f0, f1, f0
/* 800E6DBC 000E3D1C  EC 22 00 2A */	fadds f1, f2, f0
/* 800E6DC0 000E3D20  4B F2 6E 81 */	bl sqrtf__3stdFf
/* 800E6DC4 000E3D24  C0 02 99 90 */	lfs f0, lbl_803E9B90@sda21(r2)
/* 800E6DC8 000E3D28  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800E6DCC 000E3D2C  41 82 00 10 */	beq .L_800E6DDC
/* 800E6DD0 000E3D30  EF 18 08 24 */	fdivs f24, f24, f1
/* 800E6DD4 000E3D34  EF 39 08 24 */	fdivs f25, f25, f1
/* 800E6DD8 000E3D38  EE D6 08 24 */	fdivs f22, f22, f1
.L_800E6DDC:
/* 800E6DDC 000E3D3C  C3 4D C9 08 */	lfs f26, lbl_803E1628@sda21(r13)
/* 800E6DE0 000E3D40  C0 3F 00 18 */	lfs f1, 0x18(r31)
/* 800E6DE4 000E3D44  EE D6 06 B2 */	fmuls f22, f22, f26
/* 800E6DE8 000E3D48  48 13 4D 6D */	bl cosf
/* 800E6DEC 000E3D4C  FE E0 08 90 */	fmr f23, f1
/* 800E6DF0 000E3D50  C0 3F 00 18 */	lfs f1, 0x18(r31)
/* 800E6DF4 000E3D54  48 13 4E F5 */	bl sinf
/* 800E6DF8 000E3D58  C0 AD C9 10 */	lfs f5, lbl_803E1630@sda21(r13)
/* 800E6DFC 000E3D5C  EC 78 06 B2 */	fmuls f3, f24, f26
/* 800E6E00 000E3D60  C0 CD C9 18 */	lfs f6, lbl_803E1638@sda21(r13)
/* 800E6E04 000E3D64  EC 19 06 B2 */	fmuls f0, f25, f26
/* 800E6E08 000E3D68  EC 41 01 72 */	fmuls f2, f1, f5
/* 800E6E0C 000E3D6C  C0 ED C9 14 */	lfs f7, lbl_803E1634@sda21(r13)
/* 800E6E10 000E3D70  C0 2D C9 0C */	lfs f1, lbl_803E162C@sda21(r13)
/* 800E6E14 000E3D74  EC 83 01 B2 */	fmuls f4, f3, f6
/* 800E6E18 000E3D78  EC 42 01 F2 */	fmuls f2, f2, f7
/* 800E6E1C 000E3D7C  EC 21 01 72 */	fmuls f1, f1, f5
/* 800E6E20 000E3D80  EC B7 01 72 */	fmuls f5, f23, f5
/* 800E6E24 000E3D84  D0 81 01 04 */	stfs f4, 0x104(r1)
/* 800E6E28 000E3D88  EC 00 01 B2 */	fmuls f0, f0, f6
/* 800E6E2C 000E3D8C  D0 41 01 0C */	stfs f2, 0x10c(r1)
/* 800E6E30 000E3D90  EC 41 01 F2 */	fmuls f2, f1, f7
/* 800E6E34 000E3D94  C0 61 01 0C */	lfs f3, 0x10c(r1)
/* 800E6E38 000E3D98  EC 25 01 F2 */	fmuls f1, f5, f7
/* 800E6E3C 000E3D9C  D0 61 01 A8 */	stfs f3, 0x1a8(r1)
/* 800E6E40 000E3DA0  EC 76 01 B2 */	fmuls f3, f22, f6
/* 800E6E44 000E3DA4  D0 41 01 AC */	stfs f2, 0x1ac(r1)
/* 800E6E48 000E3DA8  D0 21 01 B0 */	stfs f1, 0x1b0(r1)
/* 800E6E4C 000E3DAC  C0 41 01 A8 */	lfs f2, 0x1a8(r1)
/* 800E6E50 000E3DB0  C0 21 01 04 */	lfs f1, 0x104(r1)
/* 800E6E54 000E3DB4  EC 22 08 2A */	fadds f1, f2, f1
/* 800E6E58 000E3DB8  D0 21 00 F8 */	stfs f1, 0xf8(r1)
/* 800E6E5C 000E3DBC  C0 21 00 F8 */	lfs f1, 0xf8(r1)
/* 800E6E60 000E3DC0  D0 21 01 B4 */	stfs f1, 0x1b4(r1)
/* 800E6E64 000E3DC4  C0 21 01 AC */	lfs f1, 0x1ac(r1)
/* 800E6E68 000E3DC8  EC 01 00 2A */	fadds f0, f1, f0
/* 800E6E6C 000E3DCC  D0 01 01 B8 */	stfs f0, 0x1b8(r1)
/* 800E6E70 000E3DD0  C0 01 01 B0 */	lfs f0, 0x1b0(r1)
/* 800E6E74 000E3DD4  EC 00 18 2A */	fadds f0, f0, f3
/* 800E6E78 000E3DD8  D0 01 01 BC */	stfs f0, 0x1bc(r1)
/* 800E6E7C 000E3DDC  80 61 01 B4 */	lwz r3, 0x1b4(r1)
/* 800E6E80 000E3DE0  80 01 01 B8 */	lwz r0, 0x1b8(r1)
/* 800E6E84 000E3DE4  90 7F 00 0C */	stw r3, 0xc(r31)
/* 800E6E88 000E3DE8  90 1F 00 10 */	stw r0, 0x10(r31)
/* 800E6E8C 000E3DEC  80 01 01 BC */	lwz r0, 0x1bc(r1)
/* 800E6E90 000E3DF0  90 1F 00 14 */	stw r0, 0x14(r31)
.L_800E6E94:
/* 800E6E94 000E3DF4  C0 02 99 90 */	lfs f0, lbl_803E9B90@sda21(r2)
/* 800E6E98 000E3DF8  38 E0 00 00 */	li r7, 0
/* 800E6E9C 000E3DFC  38 A1 02 14 */	addi r5, r1, 0x214
/* 800E6EA0 000E3E00  D0 01 02 1C */	stfs f0, 0x21c(r1)
/* 800E6EA4 000E3E04  38 80 00 00 */	li r4, 0
/* 800E6EA8 000E3E08  D0 01 02 18 */	stfs f0, 0x218(r1)
/* 800E6EAC 000E3E0C  D0 01 02 14 */	stfs f0, 0x214(r1)
/* 800E6EB0 000E3E10  D0 01 02 28 */	stfs f0, 0x228(r1)
/* 800E6EB4 000E3E14  D0 01 02 24 */	stfs f0, 0x224(r1)
/* 800E6EB8 000E3E18  D0 01 02 20 */	stfs f0, 0x220(r1)
/* 800E6EBC 000E3E1C  98 E1 02 34 */	stb r7, 0x234(r1)
/* 800E6EC0 000E3E20  80 7F 00 00 */	lwz r3, 0(r31)
/* 800E6EC4 000E3E24  80 1F 00 04 */	lwz r0, 4(r31)
/* 800E6EC8 000E3E28  90 61 02 14 */	stw r3, 0x214(r1)
/* 800E6ECC 000E3E2C  90 01 02 18 */	stw r0, 0x218(r1)
/* 800E6ED0 000E3E30  80 1F 00 08 */	lwz r0, 8(r31)
/* 800E6ED4 000E3E34  90 01 02 1C */	stw r0, 0x21c(r1)
/* 800E6ED8 000E3E38  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800E6EDC 000E3E3C  80 1F 00 10 */	lwz r0, 0x10(r31)
/* 800E6EE0 000E3E40  90 61 02 20 */	stw r3, 0x220(r1)
/* 800E6EE4 000E3E44  90 01 02 24 */	stw r0, 0x224(r1)
/* 800E6EE8 000E3E48  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 800E6EEC 000E3E4C  90 01 02 28 */	stw r0, 0x228(r1)
/* 800E6EF0 000E3E50  C0 02 99 94 */	lfs f0, lbl_803E9B94@sda21(r2)
/* 800E6EF4 000E3E54  80 CD 2D EC */	lwz r6, gsys@sda21(r13)
/* 800E6EF8 000E3E58  D0 01 02 2C */	stfs f0, 0x22c(r1)
/* 800E6EFC 000E3E5C  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 800E6F00 000E3E60  90 E1 02 38 */	stw r7, 0x238(r1)
/* 800E6F04 000E3E64  D0 01 02 30 */	stfs f0, 0x230(r1)
/* 800E6F08 000E3E68  C0 26 02 8C */	lfs f1, 0x28c(r6)
/* 800E6F0C 000E3E6C  4B F8 1F 49 */	bl traceMove__6MapMgrFP8CreatureR9MoveTracef
/* 800E6F10 000E3E70  80 61 02 14 */	lwz r3, 0x214(r1)
/* 800E6F14 000E3E74  80 01 02 18 */	lwz r0, 0x218(r1)
/* 800E6F18 000E3E78  90 7F 00 00 */	stw r3, 0(r31)
/* 800E6F1C 000E3E7C  90 1F 00 04 */	stw r0, 4(r31)
/* 800E6F20 000E3E80  80 01 02 1C */	lwz r0, 0x21c(r1)
/* 800E6F24 000E3E84  90 1F 00 08 */	stw r0, 8(r31)
/* 800E6F28 000E3E88  80 61 02 20 */	lwz r3, 0x220(r1)
/* 800E6F2C 000E3E8C  80 01 02 24 */	lwz r0, 0x224(r1)
/* 800E6F30 000E3E90  90 7F 00 0C */	stw r3, 0xc(r31)
/* 800E6F34 000E3E94  90 1F 00 10 */	stw r0, 0x10(r31)
/* 800E6F38 000E3E98  80 01 02 28 */	lwz r0, 0x228(r1)
/* 800E6F3C 000E3E9C  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800E6F40 000E3EA0  80 01 03 0C */	lwz r0, 0x30c(r1)
/* 800E6F44 000E3EA4  CB E1 03 00 */	lfd f31, 0x300(r1)
/* 800E6F48 000E3EA8  CB C1 02 F8 */	lfd f30, 0x2f8(r1)
/* 800E6F4C 000E3EAC  CB A1 02 F0 */	lfd f29, 0x2f0(r1)
/* 800E6F50 000E3EB0  CB 81 02 E8 */	lfd f28, 0x2e8(r1)
/* 800E6F54 000E3EB4  CB 61 02 E0 */	lfd f27, 0x2e0(r1)
/* 800E6F58 000E3EB8  CB 41 02 D8 */	lfd f26, 0x2d8(r1)
/* 800E6F5C 000E3EBC  CB 21 02 D0 */	lfd f25, 0x2d0(r1)
/* 800E6F60 000E3EC0  CB 01 02 C8 */	lfd f24, 0x2c8(r1)
/* 800E6F64 000E3EC4  CA E1 02 C0 */	lfd f23, 0x2c0(r1)
/* 800E6F68 000E3EC8  CA C1 02 B8 */	lfd f22, 0x2b8(r1)
/* 800E6F6C 000E3ECC  CA A1 02 B0 */	lfd f21, 0x2b0(r1)
/* 800E6F70 000E3ED0  BB 21 02 94 */	lmw r25, 0x294(r1)
/* 800E6F74 000E3ED4  38 21 03 08 */	addi r1, r1, 0x308
/* 800E6F78 000E3ED8  7C 08 03 A6 */	mtlr r0
/* 800E6F7C 000E3EDC  4E 80 00 20 */	blr 

.global refresh__13FishGeneratorFR8Graphics
refresh__13FishGeneratorFR8Graphics:
/* 800E6F80 000E3EE0  7C 08 02 A6 */	mflr r0
/* 800E6F84 000E3EE4  38 A0 00 00 */	li r5, 0
/* 800E6F88 000E3EE8  90 01 00 04 */	stw r0, 4(r1)
/* 800E6F8C 000E3EEC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800E6F90 000E3EF0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800E6F94 000E3EF4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800E6F98 000E3EF8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800E6F9C 000E3EFC  3B A4 00 00 */	addi r29, r4, 0
/* 800E6FA0 000E3F00  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 800E6FA4 000E3F04  93 81 00 10 */	stw r28, 0x10(r1)
/* 800E6FA8 000E3F08  3B 83 00 00 */	addi r28, r3, 0
/* 800E6FAC 000E3F0C  38 7D 00 00 */	addi r3, r29, 0
/* 800E6FB0 000E3F10  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 800E6FB4 000E3F14  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 800E6FB8 000E3F18  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800E6FBC 000E3F1C  7D 88 03 A6 */	mtlr r12
/* 800E6FC0 000E3F20  4E 80 00 21 */	blrl 
/* 800E6FC4 000E3F24  3B C0 00 00 */	li r30, 0
/* 800E6FC8 000E3F28  1F FE 00 1C */	mulli r31, r30, 0x1c
/* 800E6FCC 000E3F2C  48 00 00 20 */	b .L_800E6FEC
.L_800E6FD0:
/* 800E6FD0 000E3F30  80 1C 03 D0 */	lwz r0, 0x3d0(r28)
/* 800E6FD4 000E3F34  7F A3 EB 78 */	mr r3, r29
/* 800E6FD8 000E3F38  C0 22 99 A0 */	lfs f1, lbl_803E9BA0@sda21(r2)
/* 800E6FDC 000E3F3C  7C 80 FA 14 */	add r4, r0, r31
/* 800E6FE0 000E3F40  48 02 F4 41 */	bl drawBatten__FR8GraphicsR8Vector3ff
/* 800E6FE4 000E3F44  3B FF 00 1C */	addi r31, r31, 0x1c
/* 800E6FE8 000E3F48  3B DE 00 01 */	addi r30, r30, 1
.L_800E6FEC:
/* 800E6FEC 000E3F4C  80 1C 03 C8 */	lwz r0, 0x3c8(r28)
/* 800E6FF0 000E3F50  7C 1E 00 00 */	cmpw r30, r0
/* 800E6FF4 000E3F54  41 80 FF DC */	blt .L_800E6FD0
/* 800E6FF8 000E3F58  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800E6FFC 000E3F5C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800E7000 000E3F60  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800E7004 000E3F64  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800E7008 000E3F68  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800E700C 000E3F6C  38 21 00 20 */	addi r1, r1, 0x20
/* 800E7010 000E3F70  7C 08 03 A6 */	mtlr r0
/* 800E7014 000E3F74  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BBD70:
	.asciz "fishItem.cpp"
.balign 4
lbl_802BBD80:
	.asciz "FishGenerator"
.balign 4
lbl_802BBD90:
	.asciz "PaniAnimKeyListener"
.balign 4
lbl_802BBDA4:
	.asciz "EventTalker"
.balign 4
lbl_802BBDB0:
	.asciz "RefCountable"
.balign 4
lbl_802BBDC0:
	.asciz "Creature"
.balign 4
lbl_802BBDCC:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
.balign 4
lbl_802BBDE0:
	.asciz "AICreature"
.balign 4
lbl_802BBDEC:
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x2B8
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
.balign 4
lbl_802BBE10:
	.asciz "ItemCreature"
.balign 4
lbl_802BBE20:
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x2B8
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__10AICreature
	.4byte 0
	.4byte 0
lbl_802BBE4C:
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x2B8
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__10AICreature
	.4byte 0
	.4byte __RTTI__12ItemCreature
	.4byte 0
	.4byte 0
.global __vt__13FishGenerator
__vt__13FishGenerator:
	.4byte __RTTI__13FishGenerator
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__12ItemCreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__13FishGeneratorFi
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__12ItemCreatureFv
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
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__12ItemCreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__10AICreatureFR9CollEvent
	.4byte bounceCallback__10AICreatureFv
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
	.4byte update__13FishGeneratorFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__13FishGeneratorFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__13FishGenerator
	.4byte 0xFFFFFD48
	.4byte "@696@animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent"
	.4byte getCurrState__10AICreatureFv
	.4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
	.4byte playSound__10AICreatureFi
	.4byte playEffect__10AICreatureFi
	.4byte startMotion__12ItemCreatureFi
	.4byte finishMotion__12ItemCreatureFv
	.4byte finishMotion__12ItemCreatureFf
	.4byte startMotion__12ItemCreatureFif
	.4byte getCurrentMotionName__12ItemCreatureFv
	.4byte getCurrentMotionCounter__12ItemCreatureFv
	.4byte getMotionSpeed__12ItemCreatureFv
	.4byte setMotionSpeed__12ItemCreatureFf
	.4byte stopMotion__12ItemCreatureFv
	.4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
	.4byte finalSetup__12ItemCreatureFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E15E0:
	.float 4.0
lbl_803E15E4:
	.float 0.0
lbl_803E15E8:
	.float 0.0
lbl_803E15EC:
	.float 0.0
lbl_803E15F0:
	.float 0.0
lbl_803E15F4:
	.float 0.0
lbl_803E15F8:
	.float 0.0
lbl_803E15FC:
	.float 0.0
lbl_803E1600:
	.float 0.0
lbl_803E1604:
	.float 0.0
lbl_803E1608:
	.float 0.0
lbl_803E160C:
	.float 0.0
lbl_803E1610:
	.float 0.0
lbl_803E1614:
	.float 100.0
lbl_803E1618:
	.float 100.0
lbl_803E161C:
	.float 0.4
lbl_803E1620:
	.float 0.2
lbl_803E1624:
	.float 0.4
lbl_803E1628:
	.float 100.0
lbl_803E162C:
	.float 0.0
lbl_803E1630:
	.float 100.0
lbl_803E1634:
	.float 0.9
lbl_803E1638:
	.float 0.1
__RTTI__19PaniAnimKeyListener:
	.4byte lbl_802BBD90
	.4byte 0
__RTTI__11EventTalker:
	.4byte lbl_802BBDA4
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802BBDB0
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802BBDC0
	.4byte lbl_802BBDCC
__RTTI__10AICreature:
	.4byte lbl_802BBDE0
	.4byte lbl_802BBDEC
__RTTI__12ItemCreature:
	.4byte lbl_802BBE10
	.4byte lbl_802BBE20
__RTTI__13FishGenerator:
	.4byte lbl_802BBD80
	.4byte lbl_802BBE4C

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E9B90:
	.float 0.0
lbl_803E9B94:
	.float 1.0
lbl_803E9B98:
	.float 32767.0
lbl_803E9B9C:
	.float 40.0
lbl_803E9BA0:
	.float 2.0
lbl_803E9BA4:
	.float 3.1415927
lbl_803E9BA8:
	.4byte 0x43300000
	.4byte 0x80000000
lbl_803E9BB0:
	.float 20.0
lbl_803E9BB4:
	.float 4.0
lbl_803E9BB8:
	.float 0.1
lbl_803E9BBC:
	.float 0.5
