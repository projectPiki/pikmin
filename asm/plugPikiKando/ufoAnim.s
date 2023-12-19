.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__14UfoShapeObjectFP5Shape, global
/* 800E97AC 000E670C  7C 08 02 A6 */	mflr r0
/* 800E97B0 000E6710  90 01 00 04 */	stw r0, 4(r1)
/* 800E97B4 000E6714  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800E97B8 000E6718  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800E97BC 000E671C  3B E3 00 00 */	addi r31, r3, 0
/* 800E97C0 000E6720  38 60 00 88 */	li r3, 0x88
/* 800E97C4 000E6724  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800E97C8 000E6728  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800E97CC 000E672C  93 81 00 10 */	stw r28, 0x10(r1)
/* 800E97D0 000E6730  3B 84 00 00 */	addi r28, r4, 0
/* 800E97D4 000E6734  4B F5 D8 31 */	bl alloc__6SystemFUl
/* 800E97D8 000E6738  3C 80 80 0F */	lis r4, __ct__11AnimContextFv@ha
/* 800E97DC 000E673C  38 84 99 04 */	addi r4, r4, __ct__11AnimContextFv@l
/* 800E97E0 000E6740  38 A0 00 00 */	li r5, 0
/* 800E97E4 000E6744  38 C0 00 10 */	li r6, 0x10
/* 800E97E8 000E6748  38 E0 00 08 */	li r7, 8
/* 800E97EC 000E674C  48 12 B4 3D */	bl __construct_new_array
/* 800E97F0 000E6750  90 7F 00 08 */	stw r3, 8(r31)
/* 800E97F4 000E6754  3C 60 80 2C */	lis r3, lbl_802BC4B4@ha
/* 800E97F8 000E6758  38 03 C4 B4 */	addi r0, r3, lbl_802BC4B4@l
/* 800E97FC 000E675C  93 9F 00 00 */	stw r28, 0(r31)
/* 800E9800 000E6760  7C 1D 03 78 */	mr r29, r0
/* 800E9804 000E6764  38 60 00 B8 */	li r3, 0xb8
/* 800E9808 000E6768  4B F5 D7 FD */	bl alloc__6SystemFUl
/* 800E980C 000E676C  3B C3 00 00 */	addi r30, r3, 0
/* 800E9810 000E6770  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9814 000E6774  41 82 00 1C */	beq .L_800E9830
/* 800E9818 000E6778  3C C0 00 01 */	lis r6, 0x00008000@ha
/* 800E981C 000E677C  38 9C 00 00 */	addi r4, r28, 0
/* 800E9820 000E6780  38 BD 00 00 */	addi r5, r29, 0
/* 800E9824 000E6784  38 C6 80 00 */	addi r6, r6, 0x00008000@l
/* 800E9828 000E6788  38 E0 00 00 */	li r7, 0
/* 800E982C 000E678C  4B F6 70 79 */	bl __ct__7AnimMgrFP5ShapePciPc
.L_800E9830:
/* 800E9830 000E6790  93 DF 00 04 */	stw r30, 4(r31)
/* 800E9834 000E6794  3C 60 80 2C */	lis r3, lbl_802BC4CC@ha
/* 800E9838 000E6798  38 03 C4 CC */	addi r0, r3, lbl_802BC4CC@l
/* 800E983C 000E679C  80 7F 00 04 */	lwz r3, 4(r31)
/* 800E9840 000E67A0  38 80 00 00 */	li r4, 0
/* 800E9844 000E67A4  90 03 00 04 */	stw r0, 4(r3)
/* 800E9848 000E67A8  80 7F 00 00 */	lwz r3, 0(r31)
/* 800E984C 000E67AC  80 BF 00 08 */	lwz r5, 8(r31)
/* 800E9850 000E67B0  4B F4 B8 15 */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 800E9854 000E67B4  80 BF 00 08 */	lwz r5, 8(r31)
/* 800E9858 000E67B8  38 80 00 26 */	li r4, 0x26
/* 800E985C 000E67BC  80 7F 00 00 */	lwz r3, 0(r31)
/* 800E9860 000E67C0  38 A5 00 10 */	addi r5, r5, 0x10
/* 800E9864 000E67C4  4B F4 B8 01 */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 800E9868 000E67C8  80 BF 00 08 */	lwz r5, 8(r31)
/* 800E986C 000E67CC  38 80 00 24 */	li r4, 0x24
/* 800E9870 000E67D0  80 7F 00 00 */	lwz r3, 0(r31)
/* 800E9874 000E67D4  38 A5 00 20 */	addi r5, r5, 0x20
/* 800E9878 000E67D8  4B F4 B7 ED */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 800E987C 000E67DC  80 BF 00 08 */	lwz r5, 8(r31)
/* 800E9880 000E67E0  38 80 00 13 */	li r4, 0x13
/* 800E9884 000E67E4  80 7F 00 00 */	lwz r3, 0(r31)
/* 800E9888 000E67E8  38 A5 00 30 */	addi r5, r5, 0x30
/* 800E988C 000E67EC  4B F4 B7 D9 */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 800E9890 000E67F0  80 BF 00 08 */	lwz r5, 8(r31)
/* 800E9894 000E67F4  38 80 00 20 */	li r4, 0x20
/* 800E9898 000E67F8  80 7F 00 00 */	lwz r3, 0(r31)
/* 800E989C 000E67FC  38 A5 00 40 */	addi r5, r5, 0x40
/* 800E98A0 000E6800  4B F4 B7 C5 */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 800E98A4 000E6804  80 BF 00 08 */	lwz r5, 8(r31)
/* 800E98A8 000E6808  38 80 00 25 */	li r4, 0x25
/* 800E98AC 000E680C  80 7F 00 00 */	lwz r3, 0(r31)
/* 800E98B0 000E6810  38 A5 00 50 */	addi r5, r5, 0x50
/* 800E98B4 000E6814  4B F4 B7 B1 */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 800E98B8 000E6818  80 BF 00 08 */	lwz r5, 8(r31)
/* 800E98BC 000E681C  38 80 00 1D */	li r4, 0x1d
/* 800E98C0 000E6820  80 7F 00 00 */	lwz r3, 0(r31)
/* 800E98C4 000E6824  38 A5 00 60 */	addi r5, r5, 0x60
/* 800E98C8 000E6828  4B F4 B7 9D */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 800E98CC 000E682C  80 BF 00 08 */	lwz r5, 8(r31)
/* 800E98D0 000E6830  38 80 00 35 */	li r4, 0x35
/* 800E98D4 000E6834  80 7F 00 00 */	lwz r3, 0(r31)
/* 800E98D8 000E6838  38 A5 00 70 */	addi r5, r5, 0x70
/* 800E98DC 000E683C  4B F4 B7 89 */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 800E98E0 000E6840  7F E3 FB 78 */	mr r3, r31
/* 800E98E4 000E6844  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800E98E8 000E6848  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800E98EC 000E684C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800E98F0 000E6850  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800E98F4 000E6854  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800E98F8 000E6858  38 21 00 20 */	addi r1, r1, 0x20
/* 800E98FC 000E685C  7C 08 03 A6 */	mtlr r0
/* 800E9900 000E6860  4E 80 00 20 */	blr 
.endfn __ct__14UfoShapeObjectFP5Shape

.fn __ct__11AnimContextFv, weak
/* 800E9904 000E6864  3C 80 80 23 */	lis r4, __vt__11AnimContext@ha
/* 800E9908 000E6868  38 04 88 D0 */	addi r0, r4, __vt__11AnimContext@l
/* 800E990C 000E686C  90 03 00 0C */	stw r0, 0xc(r3)
/* 800E9910 000E6870  38 00 00 00 */	li r0, 0
/* 800E9914 000E6874  90 03 00 00 */	stw r0, 0(r3)
/* 800E9918 000E6878  C0 02 9A 10 */	lfs f0, lbl_803E9C10@sda21(r2)
/* 800E991C 000E687C  D0 03 00 04 */	stfs f0, 4(r3)
/* 800E9920 000E6880  C0 02 9A 14 */	lfs f0, lbl_803E9C14@sda21(r2)
/* 800E9924 000E6884  D0 03 00 08 */	stfs f0, 8(r3)
/* 800E9928 000E6888  4E 80 00 20 */	blr 
.endfn __ct__11AnimContextFv

.fn createMotionTable__15PaniUfoAnimatorFv, global
/* 800E992C 000E688C  7C 08 02 A6 */	mflr r0
/* 800E9930 000E6890  38 60 00 08 */	li r3, 8
/* 800E9934 000E6894  90 01 00 04 */	stw r0, 4(r1)
/* 800E9938 000E6898  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800E993C 000E689C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800E9940 000E68A0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800E9944 000E68A4  4B F5 D6 C1 */	bl alloc__6SystemFUl
/* 800E9948 000E68A8  3B E3 00 00 */	addi r31, r3, 0
/* 800E994C 000E68AC  7F E3 FB 79 */	or. r3, r31, r31
/* 800E9950 000E68B0  41 82 00 0C */	beq .L_800E995C
/* 800E9954 000E68B4  38 80 00 11 */	li r4, 0x11
/* 800E9958 000E68B8  48 03 56 B1 */	bl __ct__15PaniMotionTableFi
.L_800E995C:
/* 800E995C 000E68BC  38 60 00 08 */	li r3, 8
/* 800E9960 000E68C0  4B F5 D6 A5 */	bl alloc__6SystemFUl
/* 800E9964 000E68C4  3B C3 00 00 */	addi r30, r3, 0
/* 800E9968 000E68C8  7F C3 F3 79 */	or. r3, r30, r30
/* 800E996C 000E68CC  41 82 00 0C */	beq .L_800E9978
/* 800E9970 000E68D0  38 80 00 00 */	li r4, 0
/* 800E9974 000E68D4  48 03 56 55 */	bl __ct__10PaniMotionFi
.L_800E9978:
/* 800E9978 000E68D8  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E997C 000E68DC  38 60 00 08 */	li r3, 8
/* 800E9980 000E68E0  93 C4 00 00 */	stw r30, 0(r4)
/* 800E9984 000E68E4  4B F5 D6 81 */	bl alloc__6SystemFUl
/* 800E9988 000E68E8  3B C3 00 00 */	addi r30, r3, 0
/* 800E998C 000E68EC  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9990 000E68F0  41 82 00 0C */	beq .L_800E999C
/* 800E9994 000E68F4  38 80 00 01 */	li r4, 1
/* 800E9998 000E68F8  48 03 56 31 */	bl __ct__10PaniMotionFi
.L_800E999C:
/* 800E999C 000E68FC  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E99A0 000E6900  38 60 00 08 */	li r3, 8
/* 800E99A4 000E6904  93 C4 00 04 */	stw r30, 4(r4)
/* 800E99A8 000E6908  4B F5 D6 5D */	bl alloc__6SystemFUl
/* 800E99AC 000E690C  3B C3 00 00 */	addi r30, r3, 0
/* 800E99B0 000E6910  7F C3 F3 79 */	or. r3, r30, r30
/* 800E99B4 000E6914  41 82 00 0C */	beq .L_800E99C0
/* 800E99B8 000E6918  38 80 00 02 */	li r4, 2
/* 800E99BC 000E691C  48 03 56 0D */	bl __ct__10PaniMotionFi
.L_800E99C0:
/* 800E99C0 000E6920  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E99C4 000E6924  38 60 00 08 */	li r3, 8
/* 800E99C8 000E6928  93 C4 00 08 */	stw r30, 8(r4)
/* 800E99CC 000E692C  4B F5 D6 39 */	bl alloc__6SystemFUl
/* 800E99D0 000E6930  3B C3 00 00 */	addi r30, r3, 0
/* 800E99D4 000E6934  7F C3 F3 79 */	or. r3, r30, r30
/* 800E99D8 000E6938  41 82 00 0C */	beq .L_800E99E4
/* 800E99DC 000E693C  38 80 00 03 */	li r4, 3
/* 800E99E0 000E6940  48 03 55 E9 */	bl __ct__10PaniMotionFi
.L_800E99E4:
/* 800E99E4 000E6944  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E99E8 000E6948  38 60 00 08 */	li r3, 8
/* 800E99EC 000E694C  93 C4 00 0C */	stw r30, 0xc(r4)
/* 800E99F0 000E6950  4B F5 D6 15 */	bl alloc__6SystemFUl
/* 800E99F4 000E6954  3B C3 00 00 */	addi r30, r3, 0
/* 800E99F8 000E6958  7F C3 F3 79 */	or. r3, r30, r30
/* 800E99FC 000E695C  41 82 00 0C */	beq .L_800E9A08
/* 800E9A00 000E6960  38 80 00 04 */	li r4, 4
/* 800E9A04 000E6964  48 03 55 C5 */	bl __ct__10PaniMotionFi
.L_800E9A08:
/* 800E9A08 000E6968  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9A0C 000E696C  38 60 00 08 */	li r3, 8
/* 800E9A10 000E6970  93 C4 00 10 */	stw r30, 0x10(r4)
/* 800E9A14 000E6974  4B F5 D5 F1 */	bl alloc__6SystemFUl
/* 800E9A18 000E6978  3B C3 00 00 */	addi r30, r3, 0
/* 800E9A1C 000E697C  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9A20 000E6980  41 82 00 0C */	beq .L_800E9A2C
/* 800E9A24 000E6984  38 80 00 05 */	li r4, 5
/* 800E9A28 000E6988  48 03 55 A1 */	bl __ct__10PaniMotionFi
.L_800E9A2C:
/* 800E9A2C 000E698C  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9A30 000E6990  38 60 00 08 */	li r3, 8
/* 800E9A34 000E6994  93 C4 00 14 */	stw r30, 0x14(r4)
/* 800E9A38 000E6998  4B F5 D5 CD */	bl alloc__6SystemFUl
/* 800E9A3C 000E699C  3B C3 00 00 */	addi r30, r3, 0
/* 800E9A40 000E69A0  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9A44 000E69A4  41 82 00 0C */	beq .L_800E9A50
/* 800E9A48 000E69A8  38 80 00 06 */	li r4, 6
/* 800E9A4C 000E69AC  48 03 55 7D */	bl __ct__10PaniMotionFi
.L_800E9A50:
/* 800E9A50 000E69B0  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9A54 000E69B4  38 60 00 08 */	li r3, 8
/* 800E9A58 000E69B8  93 C4 00 18 */	stw r30, 0x18(r4)
/* 800E9A5C 000E69BC  4B F5 D5 A9 */	bl alloc__6SystemFUl
/* 800E9A60 000E69C0  3B C3 00 00 */	addi r30, r3, 0
/* 800E9A64 000E69C4  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9A68 000E69C8  41 82 00 0C */	beq .L_800E9A74
/* 800E9A6C 000E69CC  38 80 00 07 */	li r4, 7
/* 800E9A70 000E69D0  48 03 55 59 */	bl __ct__10PaniMotionFi
.L_800E9A74:
/* 800E9A74 000E69D4  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9A78 000E69D8  38 60 00 08 */	li r3, 8
/* 800E9A7C 000E69DC  93 C4 00 1C */	stw r30, 0x1c(r4)
/* 800E9A80 000E69E0  4B F5 D5 85 */	bl alloc__6SystemFUl
/* 800E9A84 000E69E4  3B C3 00 00 */	addi r30, r3, 0
/* 800E9A88 000E69E8  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9A8C 000E69EC  41 82 00 0C */	beq .L_800E9A98
/* 800E9A90 000E69F0  38 80 00 08 */	li r4, 8
/* 800E9A94 000E69F4  48 03 55 35 */	bl __ct__10PaniMotionFi
.L_800E9A98:
/* 800E9A98 000E69F8  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9A9C 000E69FC  38 60 00 08 */	li r3, 8
/* 800E9AA0 000E6A00  93 C4 00 20 */	stw r30, 0x20(r4)
/* 800E9AA4 000E6A04  4B F5 D5 61 */	bl alloc__6SystemFUl
/* 800E9AA8 000E6A08  3B C3 00 00 */	addi r30, r3, 0
/* 800E9AAC 000E6A0C  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9AB0 000E6A10  41 82 00 0C */	beq .L_800E9ABC
/* 800E9AB4 000E6A14  38 80 00 09 */	li r4, 9
/* 800E9AB8 000E6A18  48 03 55 11 */	bl __ct__10PaniMotionFi
.L_800E9ABC:
/* 800E9ABC 000E6A1C  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9AC0 000E6A20  38 60 00 08 */	li r3, 8
/* 800E9AC4 000E6A24  93 C4 00 24 */	stw r30, 0x24(r4)
/* 800E9AC8 000E6A28  4B F5 D5 3D */	bl alloc__6SystemFUl
/* 800E9ACC 000E6A2C  3B C3 00 00 */	addi r30, r3, 0
/* 800E9AD0 000E6A30  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9AD4 000E6A34  41 82 00 0C */	beq .L_800E9AE0
/* 800E9AD8 000E6A38  38 80 00 0A */	li r4, 0xa
/* 800E9ADC 000E6A3C  48 03 54 ED */	bl __ct__10PaniMotionFi
.L_800E9AE0:
/* 800E9AE0 000E6A40  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9AE4 000E6A44  38 60 00 08 */	li r3, 8
/* 800E9AE8 000E6A48  93 C4 00 28 */	stw r30, 0x28(r4)
/* 800E9AEC 000E6A4C  4B F5 D5 19 */	bl alloc__6SystemFUl
/* 800E9AF0 000E6A50  3B C3 00 00 */	addi r30, r3, 0
/* 800E9AF4 000E6A54  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9AF8 000E6A58  41 82 00 0C */	beq .L_800E9B04
/* 800E9AFC 000E6A5C  38 80 00 0B */	li r4, 0xb
/* 800E9B00 000E6A60  48 03 54 C9 */	bl __ct__10PaniMotionFi
.L_800E9B04:
/* 800E9B04 000E6A64  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9B08 000E6A68  38 60 00 08 */	li r3, 8
/* 800E9B0C 000E6A6C  93 C4 00 2C */	stw r30, 0x2c(r4)
/* 800E9B10 000E6A70  4B F5 D4 F5 */	bl alloc__6SystemFUl
/* 800E9B14 000E6A74  3B C3 00 00 */	addi r30, r3, 0
/* 800E9B18 000E6A78  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9B1C 000E6A7C  41 82 00 0C */	beq .L_800E9B28
/* 800E9B20 000E6A80  38 80 00 0C */	li r4, 0xc
/* 800E9B24 000E6A84  48 03 54 A5 */	bl __ct__10PaniMotionFi
.L_800E9B28:
/* 800E9B28 000E6A88  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9B2C 000E6A8C  38 60 00 08 */	li r3, 8
/* 800E9B30 000E6A90  93 C4 00 30 */	stw r30, 0x30(r4)
/* 800E9B34 000E6A94  4B F5 D4 D1 */	bl alloc__6SystemFUl
/* 800E9B38 000E6A98  3B C3 00 00 */	addi r30, r3, 0
/* 800E9B3C 000E6A9C  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9B40 000E6AA0  41 82 00 0C */	beq .L_800E9B4C
/* 800E9B44 000E6AA4  38 80 00 0D */	li r4, 0xd
/* 800E9B48 000E6AA8  48 03 54 81 */	bl __ct__10PaniMotionFi
.L_800E9B4C:
/* 800E9B4C 000E6AAC  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9B50 000E6AB0  38 60 00 08 */	li r3, 8
/* 800E9B54 000E6AB4  93 C4 00 34 */	stw r30, 0x34(r4)
/* 800E9B58 000E6AB8  4B F5 D4 AD */	bl alloc__6SystemFUl
/* 800E9B5C 000E6ABC  3B C3 00 00 */	addi r30, r3, 0
/* 800E9B60 000E6AC0  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9B64 000E6AC4  41 82 00 0C */	beq .L_800E9B70
/* 800E9B68 000E6AC8  38 80 00 0E */	li r4, 0xe
/* 800E9B6C 000E6ACC  48 03 54 5D */	bl __ct__10PaniMotionFi
.L_800E9B70:
/* 800E9B70 000E6AD0  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9B74 000E6AD4  38 60 00 08 */	li r3, 8
/* 800E9B78 000E6AD8  93 C4 00 38 */	stw r30, 0x38(r4)
/* 800E9B7C 000E6ADC  4B F5 D4 89 */	bl alloc__6SystemFUl
/* 800E9B80 000E6AE0  3B C3 00 00 */	addi r30, r3, 0
/* 800E9B84 000E6AE4  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9B88 000E6AE8  41 82 00 0C */	beq .L_800E9B94
/* 800E9B8C 000E6AEC  38 80 00 0F */	li r4, 0xf
/* 800E9B90 000E6AF0  48 03 54 39 */	bl __ct__10PaniMotionFi
.L_800E9B94:
/* 800E9B94 000E6AF4  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9B98 000E6AF8  38 60 00 08 */	li r3, 8
/* 800E9B9C 000E6AFC  93 C4 00 3C */	stw r30, 0x3c(r4)
/* 800E9BA0 000E6B00  4B F5 D4 65 */	bl alloc__6SystemFUl
/* 800E9BA4 000E6B04  3B C3 00 00 */	addi r30, r3, 0
/* 800E9BA8 000E6B08  7F C3 F3 79 */	or. r3, r30, r30
/* 800E9BAC 000E6B0C  41 82 00 0C */	beq .L_800E9BB8
/* 800E9BB0 000E6B10  38 80 00 10 */	li r4, 0x10
/* 800E9BB4 000E6B14  48 03 54 15 */	bl __ct__10PaniMotionFi
.L_800E9BB8:
/* 800E9BB8 000E6B18  80 9F 00 04 */	lwz r4, 4(r31)
/* 800E9BBC 000E6B1C  7F E3 FB 78 */	mr r3, r31
/* 800E9BC0 000E6B20  93 C4 00 40 */	stw r30, 0x40(r4)
/* 800E9BC4 000E6B24  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800E9BC8 000E6B28  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800E9BCC 000E6B2C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800E9BD0 000E6B30  38 21 00 18 */	addi r1, r1, 0x18
/* 800E9BD4 000E6B34  7C 08 03 A6 */	mtlr r0
/* 800E9BD8 000E6B38  4E 80 00 20 */	blr 
.endfn createMotionTable__15PaniUfoAnimatorFv

.fn __ct__15PaniUfoAnimatorFv, global
/* 800E9BDC 000E6B3C  7C 08 02 A6 */	mflr r0
/* 800E9BE0 000E6B40  90 01 00 04 */	stw r0, 4(r1)
/* 800E9BE4 000E6B44  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800E9BE8 000E6B48  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800E9BEC 000E6B4C  7C 7F 1B 78 */	mr r31, r3
/* 800E9BF0 000E6B50  48 03 54 F1 */	bl __ct__12PaniAnimatorFv
/* 800E9BF4 000E6B54  3C 60 80 2C */	lis r3, __vt__15PaniUfoAnimator@ha
/* 800E9BF8 000E6B58  38 03 C5 BC */	addi r0, r3, __vt__15PaniUfoAnimator@l
/* 800E9BFC 000E6B5C  90 1F 00 30 */	stw r0, 0x30(r31)
/* 800E9C00 000E6B60  7F E3 FB 78 */	mr r3, r31
/* 800E9C04 000E6B64  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800E9C08 000E6B68  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800E9C0C 000E6B6C  38 21 00 18 */	addi r1, r1, 0x18
/* 800E9C10 000E6B70  7C 08 03 A6 */	mtlr r0
/* 800E9C14 000E6B74  4E 80 00 20 */	blr 
.endfn __ct__15PaniUfoAnimatorFv

.fn __ct__11UfoAnimatorFv, global
/* 800E9C18 000E6B78  7C 08 02 A6 */	mflr r0
/* 800E9C1C 000E6B7C  90 01 00 04 */	stw r0, 4(r1)
/* 800E9C20 000E6B80  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800E9C24 000E6B84  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800E9C28 000E6B88  3B E3 00 00 */	addi r31, r3, 0
/* 800E9C2C 000E6B8C  38 60 02 A8 */	li r3, 0x2a8
/* 800E9C30 000E6B90  4B F5 D3 D5 */	bl alloc__6SystemFUl
/* 800E9C34 000E6B94  3C 80 80 0F */	lis r4, __ct__15PaniUfoAnimatorFv@ha
/* 800E9C38 000E6B98  38 84 9B DC */	addi r4, r4, __ct__15PaniUfoAnimatorFv@l
/* 800E9C3C 000E6B9C  38 A0 00 00 */	li r5, 0
/* 800E9C40 000E6BA0  38 C0 00 54 */	li r6, 0x54
/* 800E9C44 000E6BA4  38 E0 00 08 */	li r7, 8
/* 800E9C48 000E6BA8  48 12 AF E1 */	bl __construct_new_array
/* 800E9C4C 000E6BAC  90 7F 00 00 */	stw r3, 0(r31)
/* 800E9C50 000E6BB0  38 60 00 20 */	li r3, 0x20
/* 800E9C54 000E6BB4  4B F5 D3 B1 */	bl alloc__6SystemFUl
/* 800E9C58 000E6BB8  90 7F 00 04 */	stw r3, 4(r31)
/* 800E9C5C 000E6BBC  7F E3 FB 78 */	mr r3, r31
/* 800E9C60 000E6BC0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800E9C64 000E6BC4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800E9C68 000E6BC8  38 21 00 18 */	addi r1, r1, 0x18
/* 800E9C6C 000E6BCC  7C 08 03 A6 */	mtlr r0
/* 800E9C70 000E6BD0  4E 80 00 20 */	blr 
.endfn __ct__11UfoAnimatorFv

.fn init__11UfoAnimatorFP14UfoShapeObjectP15PaniMotionTable, global
/* 800E9C74 000E6BD4  7C 08 02 A6 */	mflr r0
/* 800E9C78 000E6BD8  90 01 00 04 */	stw r0, 4(r1)
/* 800E9C7C 000E6BDC  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 800E9C80 000E6BE0  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 800E9C84 000E6BE4  BF 21 00 24 */	stmw r25, 0x24(r1)
/* 800E9C88 000E6BE8  3B 80 00 00 */	li r28, 0
/* 800E9C8C 000E6BEC  1F DC 00 54 */	mulli r30, r28, 0x54
/* 800E9C90 000E6BF0  3B 23 00 00 */	addi r25, r3, 0
/* 800E9C94 000E6BF4  3B 44 00 00 */	addi r26, r4, 0
/* 800E9C98 000E6BF8  3B 65 00 00 */	addi r27, r5, 0
/* 800E9C9C 000E6BFC  57 9F 20 36 */	slwi r31, r28, 4
/* 800E9CA0 000E6C00  3B A0 00 00 */	li r29, 0
/* 800E9CA4 000E6C04  C3 E2 9A 10 */	lfs f31, lbl_803E9C10@sda21(r2)
.L_800E9CA8:
/* 800E9CA8 000E6C08  80 79 00 00 */	lwz r3, 0(r25)
/* 800E9CAC 000E6C0C  7F 66 DB 78 */	mr r6, r27
/* 800E9CB0 000E6C10  80 1A 00 08 */	lwz r0, 8(r26)
/* 800E9CB4 000E6C14  80 BA 00 04 */	lwz r5, 4(r26)
/* 800E9CB8 000E6C18  7C 63 F2 14 */	add r3, r3, r30
/* 800E9CBC 000E6C1C  7C 80 FA 14 */	add r4, r0, r31
/* 800E9CC0 000E6C20  48 03 54 65 */	bl init__12PaniAnimatorFP11AnimContextP7AnimMgrP15PaniMotionTable
/* 800E9CC4 000E6C24  80 B9 00 04 */	lwz r5, 4(r25)
/* 800E9CC8 000E6C28  38 61 00 14 */	addi r3, r1, 0x14
/* 800E9CCC 000E6C2C  38 80 00 00 */	li r4, 0
/* 800E9CD0 000E6C30  7F E5 ED 2E */	stfsx f31, r5, r29
/* 800E9CD4 000E6C34  48 03 52 85 */	bl __ct__14PaniMotionInfoFi
/* 800E9CD8 000E6C38  80 19 00 00 */	lwz r0, 0(r25)
/* 800E9CDC 000E6C3C  38 83 00 00 */	addi r4, r3, 0
/* 800E9CE0 000E6C40  7C 60 F2 14 */	add r3, r0, r30
/* 800E9CE4 000E6C44  48 03 54 DD */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 800E9CE8 000E6C48  3B 9C 00 01 */	addi r28, r28, 1
/* 800E9CEC 000E6C4C  2C 1C 00 08 */	cmpwi r28, 8
/* 800E9CF0 000E6C50  3B FF 00 10 */	addi r31, r31, 0x10
/* 800E9CF4 000E6C54  3B DE 00 54 */	addi r30, r30, 0x54
/* 800E9CF8 000E6C58  3B BD 00 04 */	addi r29, r29, 4
/* 800E9CFC 000E6C5C  41 80 FF AC */	blt .L_800E9CA8
/* 800E9D00 000E6C60  BB 21 00 24 */	lmw r25, 0x24(r1)
/* 800E9D04 000E6C64  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 800E9D08 000E6C68  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 800E9D0C 000E6C6C  38 21 00 48 */	addi r1, r1, 0x48
/* 800E9D10 000E6C70  7C 08 03 A6 */	mtlr r0
/* 800E9D14 000E6C74  4E 80 00 20 */	blr 
.endfn init__11UfoAnimatorFP14UfoShapeObjectP15PaniMotionTable

.fn startMotion__11UfoAnimatorFiP14PaniMotionInfo, global
/* 800E9D18 000E6C78  7C 08 02 A6 */	mflr r0
/* 800E9D1C 000E6C7C  28 05 00 00 */	cmplwi r5, 0
/* 800E9D20 000E6C80  90 01 00 04 */	stw r0, 4(r1)
/* 800E9D24 000E6C84  94 21 FF F8 */	stwu r1, -8(r1)
/* 800E9D28 000E6C88  41 82 00 18 */	beq .L_800E9D40
/* 800E9D2C 000E6C8C  1C 04 00 54 */	mulli r0, r4, 0x54
/* 800E9D30 000E6C90  80 63 00 00 */	lwz r3, 0(r3)
/* 800E9D34 000E6C94  38 85 00 00 */	addi r4, r5, 0
/* 800E9D38 000E6C98  7C 63 02 14 */	add r3, r3, r0
/* 800E9D3C 000E6C9C  48 03 54 85 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
.L_800E9D40:
/* 800E9D40 000E6CA0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800E9D44 000E6CA4  38 21 00 08 */	addi r1, r1, 8
/* 800E9D48 000E6CA8  7C 08 03 A6 */	mtlr r0
/* 800E9D4C 000E6CAC  4E 80 00 20 */	blr 
.endfn startMotion__11UfoAnimatorFiP14PaniMotionInfo

.fn setMotionSpeed__11UfoAnimatorFif, global
/* 800E9D50 000E6CB0  80 63 00 04 */	lwz r3, 4(r3)
/* 800E9D54 000E6CB4  54 80 10 3A */	slwi r0, r4, 2
/* 800E9D58 000E6CB8  7C 23 05 2E */	stfsx f1, r3, r0
/* 800E9D5C 000E6CBC  4E 80 00 20 */	blr 
.endfn setMotionSpeed__11UfoAnimatorFif

.fn getMotionIndex__11UfoAnimatorFi, global
/* 800E9D60 000E6CC0  1C 84 00 54 */	mulli r4, r4, 0x54
/* 800E9D64 000E6CC4  80 63 00 00 */	lwz r3, 0(r3)
/* 800E9D68 000E6CC8  38 04 00 44 */	addi r0, r4, 0x44
/* 800E9D6C 000E6CCC  7C 63 00 2E */	lwzx r3, r3, r0
/* 800E9D70 000E6CD0  4E 80 00 20 */	blr 
.endfn getMotionIndex__11UfoAnimatorFi

.fn stopAllMotions__11UfoAnimatorFv, global
/* 800E9D74 000E6CD4  C0 02 9A 10 */	lfs f0, lbl_803E9C10@sda21(r2)
/* 800E9D78 000E6CD8  80 83 00 04 */	lwz r4, 4(r3)
/* 800E9D7C 000E6CDC  D0 04 00 00 */	stfs f0, 0(r4)
/* 800E9D80 000E6CE0  80 83 00 04 */	lwz r4, 4(r3)
/* 800E9D84 000E6CE4  D0 04 00 04 */	stfs f0, 4(r4)
/* 800E9D88 000E6CE8  80 83 00 04 */	lwz r4, 4(r3)
/* 800E9D8C 000E6CEC  D0 04 00 08 */	stfs f0, 8(r4)
/* 800E9D90 000E6CF0  80 83 00 04 */	lwz r4, 4(r3)
/* 800E9D94 000E6CF4  D0 04 00 0C */	stfs f0, 0xc(r4)
/* 800E9D98 000E6CF8  80 83 00 04 */	lwz r4, 4(r3)
/* 800E9D9C 000E6CFC  D0 04 00 10 */	stfs f0, 0x10(r4)
/* 800E9DA0 000E6D00  80 83 00 04 */	lwz r4, 4(r3)
/* 800E9DA4 000E6D04  D0 04 00 14 */	stfs f0, 0x14(r4)
/* 800E9DA8 000E6D08  80 83 00 04 */	lwz r4, 4(r3)
/* 800E9DAC 000E6D0C  D0 04 00 18 */	stfs f0, 0x18(r4)
/* 800E9DB0 000E6D10  80 63 00 04 */	lwz r3, 4(r3)
/* 800E9DB4 000E6D14  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 800E9DB8 000E6D18  4E 80 00 20 */	blr 
.endfn stopAllMotions__11UfoAnimatorFv

.fn initFlagMotions__11UfoAnimatorFi, global
/* 800E9DBC 000E6D1C  7C 08 02 A6 */	mflr r0
/* 800E9DC0 000E6D20  90 01 00 04 */	stw r0, 4(r1)
/* 800E9DC4 000E6D24  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800E9DC8 000E6D28  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 800E9DCC 000E6D2C  BF 61 00 1C */	stmw r27, 0x1c(r1)
/* 800E9DD0 000E6D30  3B A0 00 01 */	li r29, 1
/* 800E9DD4 000E6D34  1F FD 00 54 */	mulli r31, r29, 0x54
/* 800E9DD8 000E6D38  3B 63 00 00 */	addi r27, r3, 0
/* 800E9DDC 000E6D3C  3B 84 00 00 */	addi r28, r4, 0
/* 800E9DE0 000E6D40  3B C0 00 04 */	li r30, 4
/* 800E9DE4 000E6D44  C3 E2 9A 10 */	lfs f31, lbl_803E9C10@sda21(r2)
.L_800E9DE8:
/* 800E9DE8 000E6D48  38 61 00 10 */	addi r3, r1, 0x10
/* 800E9DEC 000E6D4C  38 9D 00 02 */	addi r4, r29, 2
/* 800E9DF0 000E6D50  48 03 51 69 */	bl __ct__14PaniMotionInfoFi
/* 800E9DF4 000E6D54  28 03 00 00 */	cmplwi r3, 0
/* 800E9DF8 000E6D58  41 82 00 14 */	beq .L_800E9E0C
/* 800E9DFC 000E6D5C  80 1B 00 00 */	lwz r0, 0(r27)
/* 800E9E00 000E6D60  38 83 00 00 */	addi r4, r3, 0
/* 800E9E04 000E6D64  7C 60 FA 14 */	add r3, r0, r31
/* 800E9E08 000E6D68  48 03 53 B9 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
.L_800E9E0C:
/* 800E9E0C 000E6D6C  80 7B 00 04 */	lwz r3, 4(r27)
/* 800E9E10 000E6D70  3B BD 00 01 */	addi r29, r29, 1
/* 800E9E14 000E6D74  2C 1D 00 08 */	cmpwi r29, 8
/* 800E9E18 000E6D78  7F E3 F5 2E */	stfsx f31, r3, r30
/* 800E9E1C 000E6D7C  3B FF 00 54 */	addi r31, r31, 0x54
/* 800E9E20 000E6D80  3B DE 00 04 */	addi r30, r30, 4
/* 800E9E24 000E6D84  41 80 FF C4 */	blt .L_800E9DE8
/* 800E9E28 000E6D88  38 7B 00 00 */	addi r3, r27, 0
/* 800E9E2C 000E6D8C  38 9C 00 00 */	addi r4, r28, 0
/* 800E9E30 000E6D90  48 00 00 AD */	bl startFlagMotions__11UfoAnimatorFi
/* 800E9E34 000E6D94  2C 1C 00 03 */	cmpwi r28, 3
/* 800E9E38 000E6D98  41 82 00 2C */	beq .L_800E9E64
/* 800E9E3C 000E6D9C  40 80 00 14 */	bge .L_800E9E50
/* 800E9E40 000E6DA0  2C 1C 00 01 */	cmpwi r28, 1
/* 800E9E44 000E6DA4  41 82 00 50 */	beq .L_800E9E94
/* 800E9E48 000E6DA8  40 80 00 34 */	bge .L_800E9E7C
/* 800E9E4C 000E6DAC  48 00 00 60 */	b .L_800E9EAC
.L_800E9E50:
/* 800E9E50 000E6DB0  2C 1C 00 06 */	cmpwi r28, 6
/* 800E9E54 000E6DB4  40 80 00 58 */	bge .L_800E9EAC
/* 800E9E58 000E6DB8  38 7B 00 00 */	addi r3, r27, 0
/* 800E9E5C 000E6DBC  38 80 00 06 */	li r4, 6
/* 800E9E60 000E6DC0  48 00 01 C1 */	bl setMotionLastFrame__11UfoAnimatorFi
.L_800E9E64:
/* 800E9E64 000E6DC4  38 7B 00 00 */	addi r3, r27, 0
/* 800E9E68 000E6DC8  38 80 00 07 */	li r4, 7
/* 800E9E6C 000E6DCC  48 00 01 B5 */	bl setMotionLastFrame__11UfoAnimatorFi
/* 800E9E70 000E6DD0  38 7B 00 00 */	addi r3, r27, 0
/* 800E9E74 000E6DD4  38 80 00 03 */	li r4, 3
/* 800E9E78 000E6DD8  48 00 01 A9 */	bl setMotionLastFrame__11UfoAnimatorFi
.L_800E9E7C:
/* 800E9E7C 000E6DDC  38 7B 00 00 */	addi r3, r27, 0
/* 800E9E80 000E6DE0  38 80 00 04 */	li r4, 4
/* 800E9E84 000E6DE4  48 00 01 9D */	bl setMotionLastFrame__11UfoAnimatorFi
/* 800E9E88 000E6DE8  38 7B 00 00 */	addi r3, r27, 0
/* 800E9E8C 000E6DEC  38 80 00 05 */	li r4, 5
/* 800E9E90 000E6DF0  48 00 01 91 */	bl setMotionLastFrame__11UfoAnimatorFi
.L_800E9E94:
/* 800E9E94 000E6DF4  38 7B 00 00 */	addi r3, r27, 0
/* 800E9E98 000E6DF8  38 80 00 01 */	li r4, 1
/* 800E9E9C 000E6DFC  48 00 01 85 */	bl setMotionLastFrame__11UfoAnimatorFi
/* 800E9EA0 000E6E00  38 7B 00 00 */	addi r3, r27, 0
/* 800E9EA4 000E6E04  38 80 00 02 */	li r4, 2
/* 800E9EA8 000E6E08  48 00 01 79 */	bl setMotionLastFrame__11UfoAnimatorFi
.L_800E9EAC:
/* 800E9EAC 000E6E0C  80 6D 2F 6C */	lwz r3, playerState@sda21(r13)
/* 800E9EB0 000E6E10  4B F9 72 95 */	bl startAfterMotions__11PlayerStateFv
/* 800E9EB4 000E6E14  2C 1C 00 05 */	cmpwi r28, 5
/* 800E9EB8 000E6E18  40 82 00 0C */	bne .L_800E9EC4
/* 800E9EBC 000E6E1C  80 6D 2F 6C */	lwz r3, playerState@sda21(r13)
/* 800E9EC0 000E6E20  4B F9 72 01 */	bl startSpecialMotions__11PlayerStateFv
.L_800E9EC4:
/* 800E9EC4 000E6E24  BB 61 00 1C */	lmw r27, 0x1c(r1)
/* 800E9EC8 000E6E28  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800E9ECC 000E6E2C  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 800E9ED0 000E6E30  38 21 00 38 */	addi r1, r1, 0x38
/* 800E9ED4 000E6E34  7C 08 03 A6 */	mtlr r0
/* 800E9ED8 000E6E38  4E 80 00 20 */	blr 
.endfn initFlagMotions__11UfoAnimatorFi

.fn startFlagMotions__11UfoAnimatorFi, global
/* 800E9EDC 000E6E3C  7C 08 02 A6 */	mflr r0
/* 800E9EE0 000E6E40  2C 04 00 03 */	cmpwi r4, 3
/* 800E9EE4 000E6E44  90 01 00 04 */	stw r0, 4(r1)
/* 800E9EE8 000E6E48  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800E9EEC 000E6E4C  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 800E9EF0 000E6E50  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800E9EF4 000E6E54  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800E9EF8 000E6E58  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800E9EFC 000E6E5C  93 81 00 20 */	stw r28, 0x20(r1)
/* 800E9F00 000E6E60  3B 83 00 00 */	addi r28, r3, 0
/* 800E9F04 000E6E64  41 82 00 68 */	beq .L_800E9F6C
/* 800E9F08 000E6E68  40 80 00 1C */	bge .L_800E9F24
/* 800E9F0C 000E6E6C  2C 04 00 01 */	cmpwi r4, 1
/* 800E9F10 000E6E70  41 82 00 84 */	beq .L_800E9F94
/* 800E9F14 000E6E74  40 80 00 6C */	bge .L_800E9F80
/* 800E9F18 000E6E78  2C 04 00 00 */	cmpwi r4, 0
/* 800E9F1C 000E6E7C  40 80 00 90 */	bge .L_800E9FAC
/* 800E9F20 000E6E80  48 00 00 DC */	b .L_800E9FFC
.L_800E9F24:
/* 800E9F24 000E6E84  2C 04 00 05 */	cmpwi r4, 5
/* 800E9F28 000E6E88  41 82 00 0C */	beq .L_800E9F34
/* 800E9F2C 000E6E8C  40 80 00 D0 */	bge .L_800E9FFC
/* 800E9F30 000E6E90  48 00 00 30 */	b .L_800E9F60
.L_800E9F34:
/* 800E9F34 000E6E94  38 61 00 18 */	addi r3, r1, 0x18
/* 800E9F38 000E6E98  38 80 00 0A */	li r4, 0xa
/* 800E9F3C 000E6E9C  48 03 50 1D */	bl __ct__14PaniMotionInfoFi
/* 800E9F40 000E6EA0  28 03 00 00 */	cmplwi r3, 0
/* 800E9F44 000E6EA4  41 82 00 14 */	beq .L_800E9F58
/* 800E9F48 000E6EA8  80 BC 00 00 */	lwz r5, 0(r28)
/* 800E9F4C 000E6EAC  38 83 00 00 */	addi r4, r3, 0
/* 800E9F50 000E6EB0  38 65 02 4C */	addi r3, r5, 0x24c
/* 800E9F54 000E6EB4  48 03 52 6D */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
.L_800E9F58:
/* 800E9F58 000E6EB8  80 6D 2F 6C */	lwz r3, playerState@sda21(r13)
/* 800E9F5C 000E6EBC  4B F9 71 65 */	bl startSpecialMotions__11PlayerStateFv
.L_800E9F60:
/* 800E9F60 000E6EC0  C0 02 9A 14 */	lfs f0, lbl_803E9C14@sda21(r2)
/* 800E9F64 000E6EC4  80 7C 00 04 */	lwz r3, 4(r28)
/* 800E9F68 000E6EC8  D0 03 00 18 */	stfs f0, 0x18(r3)
.L_800E9F6C:
/* 800E9F6C 000E6ECC  C0 02 9A 14 */	lfs f0, lbl_803E9C14@sda21(r2)
/* 800E9F70 000E6ED0  80 7C 00 04 */	lwz r3, 4(r28)
/* 800E9F74 000E6ED4  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 800E9F78 000E6ED8  80 7C 00 04 */	lwz r3, 4(r28)
/* 800E9F7C 000E6EDC  D0 03 00 0C */	stfs f0, 0xc(r3)
.L_800E9F80:
/* 800E9F80 000E6EE0  C0 02 9A 14 */	lfs f0, lbl_803E9C14@sda21(r2)
/* 800E9F84 000E6EE4  80 7C 00 04 */	lwz r3, 4(r28)
/* 800E9F88 000E6EE8  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 800E9F8C 000E6EEC  80 7C 00 04 */	lwz r3, 4(r28)
/* 800E9F90 000E6EF0  D0 03 00 14 */	stfs f0, 0x14(r3)
.L_800E9F94:
/* 800E9F94 000E6EF4  C0 02 9A 14 */	lfs f0, lbl_803E9C14@sda21(r2)
/* 800E9F98 000E6EF8  80 7C 00 04 */	lwz r3, 4(r28)
/* 800E9F9C 000E6EFC  D0 03 00 04 */	stfs f0, 4(r3)
/* 800E9FA0 000E6F00  80 7C 00 04 */	lwz r3, 4(r28)
/* 800E9FA4 000E6F04  D0 03 00 08 */	stfs f0, 8(r3)
/* 800E9FA8 000E6F08  48 00 00 54 */	b .L_800E9FFC
.L_800E9FAC:
/* 800E9FAC 000E6F0C  3B A0 00 01 */	li r29, 1
/* 800E9FB0 000E6F10  C3 E2 9A 10 */	lfs f31, lbl_803E9C10@sda21(r2)
/* 800E9FB4 000E6F14  1F FD 00 54 */	mulli r31, r29, 0x54
/* 800E9FB8 000E6F18  3B C0 00 04 */	li r30, 4
.L_800E9FBC:
/* 800E9FBC 000E6F1C  38 61 00 10 */	addi r3, r1, 0x10
/* 800E9FC0 000E6F20  38 9D 00 02 */	addi r4, r29, 2
/* 800E9FC4 000E6F24  48 03 4F 95 */	bl __ct__14PaniMotionInfoFi
/* 800E9FC8 000E6F28  28 03 00 00 */	cmplwi r3, 0
/* 800E9FCC 000E6F2C  41 82 00 14 */	beq .L_800E9FE0
/* 800E9FD0 000E6F30  80 1C 00 00 */	lwz r0, 0(r28)
/* 800E9FD4 000E6F34  38 83 00 00 */	addi r4, r3, 0
/* 800E9FD8 000E6F38  7C 60 FA 14 */	add r3, r0, r31
/* 800E9FDC 000E6F3C  48 03 51 E5 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
.L_800E9FE0:
/* 800E9FE0 000E6F40  80 7C 00 04 */	lwz r3, 4(r28)
/* 800E9FE4 000E6F44  3B BD 00 01 */	addi r29, r29, 1
/* 800E9FE8 000E6F48  2C 1D 00 08 */	cmpwi r29, 8
/* 800E9FEC 000E6F4C  7F E3 F5 2E */	stfsx f31, r3, r30
/* 800E9FF0 000E6F50  3B FF 00 54 */	addi r31, r31, 0x54
/* 800E9FF4 000E6F54  3B DE 00 04 */	addi r30, r30, 4
/* 800E9FF8 000E6F58  41 80 FF C4 */	blt .L_800E9FBC
.L_800E9FFC:
/* 800E9FFC 000E6F5C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800EA000 000E6F60  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 800EA004 000E6F64  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800EA008 000E6F68  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800EA00C 000E6F6C  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800EA010 000E6F70  83 81 00 20 */	lwz r28, 0x20(r1)
/* 800EA014 000E6F74  38 21 00 38 */	addi r1, r1, 0x38
/* 800EA018 000E6F78  7C 08 03 A6 */	mtlr r0
/* 800EA01C 000E6F7C  4E 80 00 20 */	blr 
.endfn startFlagMotions__11UfoAnimatorFi

.fn setMotionLastFrame__11UfoAnimatorFi, global
/* 800EA020 000E6F80  7C 08 02 A6 */	mflr r0
/* 800EA024 000E6F84  90 01 00 04 */	stw r0, 4(r1)
/* 800EA028 000E6F88  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800EA02C 000E6F8C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800EA030 000E6F90  1F E4 00 54 */	mulli r31, r4, 0x54
/* 800EA034 000E6F94  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800EA038 000E6F98  3B C3 00 00 */	addi r30, r3, 0
/* 800EA03C 000E6F9C  80 03 00 00 */	lwz r0, 0(r3)
/* 800EA040 000E6FA0  7C 60 FA 14 */	add r3, r0, r31
/* 800EA044 000E6FA4  80 63 00 28 */	lwz r3, 0x28(r3)
/* 800EA048 000E6FA8  4B F6 63 A1 */	bl countAKeys__8AnimInfoFv
/* 800EA04C 000E6FAC  80 1E 00 00 */	lwz r0, 0(r30)
/* 800EA050 000E6FB0  38 83 FF FF */	addi r4, r3, -1
/* 800EA054 000E6FB4  7C 60 FA 14 */	add r3, r0, r31
/* 800EA058 000E6FB8  80 63 00 28 */	lwz r3, 0x28(r3)
/* 800EA05C 000E6FBC  4B F6 64 69 */	bl getKeyValue__8AnimInfoFi
/* 800EA060 000E6FC0  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 800EA064 000E6FC4  80 1E 00 00 */	lwz r0, 0(r30)
/* 800EA068 000E6FC8  90 61 00 14 */	stw r3, 0x14(r1)
/* 800EA06C 000E6FCC  3C 80 43 30 */	lis r4, 0x4330
/* 800EA070 000E6FD0  C8 42 9A 20 */	lfd f2, lbl_803E9C20@sda21(r2)
/* 800EA074 000E6FD4  7C 60 FA 14 */	add r3, r0, r31
/* 800EA078 000E6FD8  90 81 00 10 */	stw r4, 0x10(r1)
/* 800EA07C 000E6FDC  C0 02 9A 18 */	lfs f0, lbl_803E9C18@sda21(r2)
/* 800EA080 000E6FE0  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 800EA084 000E6FE4  EC 21 10 28 */	fsubs f1, f1, f2
/* 800EA088 000E6FE8  EC 01 00 28 */	fsubs f0, f1, f0
/* 800EA08C 000E6FEC  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 800EA090 000E6FF0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800EA094 000E6FF4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800EA098 000E6FF8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800EA09C 000E6FFC  38 21 00 20 */	addi r1, r1, 0x20
/* 800EA0A0 000E7000  7C 08 03 A6 */	mtlr r0
/* 800EA0A4 000E7004  4E 80 00 20 */	blr 
.endfn setMotionLastFrame__11UfoAnimatorFi

.fn updateAnimation__11UfoAnimatorFv, global
/* 800EA0A8 000E7008  7C 08 02 A6 */	mflr r0
/* 800EA0AC 000E700C  90 01 00 04 */	stw r0, 4(r1)
/* 800EA0B0 000E7010  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800EA0B4 000E7014  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800EA0B8 000E7018  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800EA0BC 000E701C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800EA0C0 000E7020  3B A0 00 00 */	li r29, 0
/* 800EA0C4 000E7024  1F DD 00 54 */	mulli r30, r29, 0x54
/* 800EA0C8 000E7028  93 81 00 10 */	stw r28, 0x10(r1)
/* 800EA0CC 000E702C  3B 83 00 00 */	addi r28, r3, 0
/* 800EA0D0 000E7030  57 BF 10 3A */	slwi r31, r29, 2
.L_800EA0D4:
/* 800EA0D4 000E7034  80 1C 00 00 */	lwz r0, 0(r28)
/* 800EA0D8 000E7038  80 9C 00 04 */	lwz r4, 4(r28)
/* 800EA0DC 000E703C  7C 60 F2 14 */	add r3, r0, r30
/* 800EA0E0 000E7040  81 83 00 30 */	lwz r12, 0x30(r3)
/* 800EA0E4 000E7044  7C 24 FC 2E */	lfsx f1, r4, r31
/* 800EA0E8 000E7048  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800EA0EC 000E704C  7D 88 03 A6 */	mtlr r12
/* 800EA0F0 000E7050  4E 80 00 21 */	blrl 
/* 800EA0F4 000E7054  3B BD 00 01 */	addi r29, r29, 1
/* 800EA0F8 000E7058  2C 1D 00 08 */	cmpwi r29, 8
/* 800EA0FC 000E705C  3B FF 00 04 */	addi r31, r31, 4
/* 800EA100 000E7060  3B DE 00 54 */	addi r30, r30, 0x54
/* 800EA104 000E7064  41 80 FF D0 */	blt .L_800EA0D4
/* 800EA108 000E7068  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800EA10C 000E706C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800EA110 000E7070  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800EA114 000E7074  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800EA118 000E7078  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800EA11C 000E707C  38 21 00 20 */	addi r1, r1, 0x20
/* 800EA120 000E7080  7C 08 03 A6 */	mtlr r0
/* 800EA124 000E7084  4E 80 00 20 */	blr 
.endfn updateAnimation__11UfoAnimatorFv

.fn updateContext__11UfoAnimatorFv, global
/* 800EA128 000E7088  7C 08 02 A6 */	mflr r0
/* 800EA12C 000E708C  90 01 00 04 */	stw r0, 4(r1)
/* 800EA130 000E7090  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800EA134 000E7094  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800EA138 000E7098  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800EA13C 000E709C  3B C0 00 00 */	li r30, 0
/* 800EA140 000E70A0  1F FE 00 54 */	mulli r31, r30, 0x54
/* 800EA144 000E70A4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800EA148 000E70A8  3B A3 00 00 */	addi r29, r3, 0
.L_800EA14C:
/* 800EA14C 000E70AC  80 1D 00 00 */	lwz r0, 0(r29)
/* 800EA150 000E70B0  7C 60 FA 14 */	add r3, r0, r31
/* 800EA154 000E70B4  81 83 00 30 */	lwz r12, 0x30(r3)
/* 800EA158 000E70B8  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 800EA15C 000E70BC  7D 88 03 A6 */	mtlr r12
/* 800EA160 000E70C0  4E 80 00 21 */	blrl 
/* 800EA164 000E70C4  3B DE 00 01 */	addi r30, r30, 1
/* 800EA168 000E70C8  2C 1E 00 08 */	cmpwi r30, 8
/* 800EA16C 000E70CC  3B FF 00 54 */	addi r31, r31, 0x54
/* 800EA170 000E70D0  41 80 FF DC */	blt .L_800EA14C
/* 800EA174 000E70D4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800EA178 000E70D8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800EA17C 000E70DC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800EA180 000E70E0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800EA184 000E70E4  38 21 00 20 */	addi r1, r1, 0x20
/* 800EA188 000E70E8  7C 08 03 A6 */	mtlr r0
/* 800EA18C 000E70EC  4E 80 00 20 */	blr 
.endfn updateContext__11UfoAnimatorFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802BC4A8, local
	.asciz "ufoAnim.cpp"
.endobj lbl_802BC4A8
.balign 4
.obj lbl_802BC4B4, local
	.asciz "objects/ufo/ufo0705.bin"
.endobj lbl_802BC4B4
.balign 4
.obj lbl_802BC4CC, local
	.asciz "ufo shape"
.endobj lbl_802BC4CC
.balign 4
.obj lbl_802BC4D8, local
	.asciz "wait tut"
.endobj lbl_802BC4D8
.balign 4
.obj lbl_802BC4E4, local
	.asciz "takeoff-1"
.endobj lbl_802BC4E4
.balign 4
.obj lbl_802BC4F0, local
	.asciz "takeoff-2"
.endobj lbl_802BC4F0
.balign 4
.obj lbl_802BC4FC, local
	.asciz "takeoff-3"
.endobj lbl_802BC4FC
.balign 4
.obj lbl_802BC508, local
	.asciz "takeoff-4"
.endobj lbl_802BC508
.balign 4
.obj lbl_802BC514, local
	.asciz "takeoff-5"
.endobj lbl_802BC514
.balign 4
.obj lbl_802BC520, local
	.asciz "open-close"
.endobj lbl_802BC520
.balign 4
.obj motionLabels__15PaniUfoAnimator, global
	.4byte lbl_802BC4D8
	.4byte lbl_803E17C0
	.4byte lbl_803E17C8
	.4byte lbl_803E17D0
	.4byte lbl_803E17D8
	.4byte lbl_803E17E0
	.4byte lbl_803E17E8
	.4byte lbl_803E17F0
	.4byte lbl_803E17F8
	.4byte lbl_803E1800
	.4byte lbl_803E1808
	.4byte lbl_802BC4E4
	.4byte lbl_802BC4F0
	.4byte lbl_802BC4FC
	.4byte lbl_802BC508
	.4byte lbl_802BC514
	.4byte lbl_802BC520
.endobj motionLabels__15PaniUfoAnimator
.balign 4
.obj lbl_802BC570, local
	.asciz "PaniUfoAnimator"
.endobj lbl_802BC570
.balign 4
.obj lbl_802BC580, local
	.asciz "Animator"
.endobj lbl_802BC580
.balign 4
.obj lbl_802BC58C, local
	.asciz "PaniAnimator"
.endobj lbl_802BC58C
.balign 4
.obj lbl_802BC59C, local
	.4byte __RTTI__8Animator
	.4byte 0
	.4byte 0
.endobj lbl_802BC59C
.balign 4
.obj lbl_802BC5A8, local
	.4byte __RTTI__8Animator
	.4byte 0
	.4byte __RTTI__12PaniAnimator
	.4byte 0
	.4byte 0
.endobj lbl_802BC5A8
.balign 4
.obj __vt__15PaniUfoAnimator, weak
	.4byte __RTTI__15PaniUfoAnimator
	.4byte 0
	.4byte changeContext__12PaniAnimatorFP11AnimContext
	.4byte animate__12PaniAnimatorFf
	.4byte finishOneShot__8AnimatorFv
	.4byte finishLoop__8AnimatorFv
	.4byte updateContext__12PaniAnimatorFv
.endobj __vt__15PaniUfoAnimator

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E17C0, local
	.asciz "wait"
.endobj lbl_803E17C0
.balign 4
.obj lbl_803E17C8, local
	.asciz "takeoff"
.endobj lbl_803E17C8
.balign 4
.obj lbl_803E17D0, local
	.asciz "henka1"
.endobj lbl_803E17D0
.balign 4
.obj lbl_803E17D8, local
	.asciz "henka1b"
.endobj lbl_803E17D8
.balign 4
.obj lbl_803E17E0, local
	.asciz "henka1d"
.endobj lbl_803E17E0
.balign 4
.obj lbl_803E17E8, local
	.asciz "henka2"
.endobj lbl_803E17E8
.balign 4
.obj lbl_803E17F0, local
	.asciz "henka2d"
.endobj lbl_803E17F0
.balign 4
.obj lbl_803E17F8, local
	.asciz "henka3"
.endobj lbl_803E17F8
.balign 4
.obj lbl_803E1800, local
	.asciz "henka4a"
.endobj lbl_803E1800
.balign 4
.obj lbl_803E1808, local
	.asciz "henka4b"
.endobj lbl_803E1808
.balign 4
.obj __RTTI__8Animator, local
	.4byte lbl_802BC580
	.4byte 0
.endobj __RTTI__8Animator
.balign 4
.obj __RTTI__12PaniAnimator, local
	.4byte lbl_802BC58C
	.4byte lbl_802BC59C
.endobj __RTTI__12PaniAnimator
.balign 4
.obj __RTTI__15PaniUfoAnimator, local
	.4byte lbl_802BC570
	.4byte lbl_802BC5A8
.endobj __RTTI__15PaniUfoAnimator

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9C10, local
	.float 0.0
.endobj lbl_803E9C10
.obj lbl_803E9C14, local
	.float 30.0
.endobj lbl_803E9C14
.obj lbl_803E9C18, local
	.float 1.0
.endobj lbl_803E9C18
.balign 8
.obj lbl_803E9C20, local
	.8byte 0x4330000080000000
.endobj lbl_803E9C20
