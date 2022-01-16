.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__Q23zen11EffectMgr2DFiii
__ct__Q23zen11EffectMgr2DFiii:
/* 801E98C0 001E6820  7C 08 02 A6 */	mflr r0
/* 801E98C4 001E6824  90 01 00 04 */	stw r0, 4(r1)
/* 801E98C8 001E6828  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 801E98CC 001E682C  DB E1 00 58 */	stfd f31, 0x58(r1)
/* 801E98D0 001E6830  BF 21 00 3C */	stmw r25, 0x3c(r1)
/* 801E98D4 001E6834  3B A5 00 00 */	addi r29, r5, 0
/* 801E98D8 001E6838  3B C6 00 00 */	addi r30, r6, 0
/* 801E98DC 001E683C  3B 84 00 00 */	addi r28, r4, 0
/* 801E98E0 001E6840  3B E0 00 00 */	li r31, 0
/* 801E98E4 001E6844  90 61 00 08 */	stw r3, 8(r1)
/* 801E98E8 001E6848  3C 60 80 2D */	lis r3, __vt__Q23zen7zenList@ha
/* 801E98EC 001E684C  39 63 68 DC */	addi r11, r3, __vt__Q23zen7zenList@l
/* 801E98F0 001E6850  80 61 00 08 */	lwz r3, 8(r1)
/* 801E98F4 001E6854  91 63 00 04 */	stw r11, 4(r3)
/* 801E98F8 001E6858  3B 63 00 10 */	addi r27, r3, 0x10
/* 801E98FC 001E685C  38 03 00 04 */	addi r0, r3, 4
/* 801E9900 001E6860  90 03 00 0C */	stw r0, 0xc(r3)
/* 801E9904 001E6864  38 9B 00 34 */	addi r4, r27, 0x34
/* 801E9908 001E6868  39 5B 00 04 */	addi r10, r27, 4
/* 801E990C 001E686C  90 03 00 08 */	stw r0, 8(r3)
/* 801E9910 001E6870  3B 5B 00 14 */	addi r26, r27, 0x14
/* 801E9914 001E6874  3B 3B 00 24 */	addi r25, r27, 0x24
/* 801E9918 001E6878  90 03 00 00 */	stw r0, 0(r3)
/* 801E991C 001E687C  39 24 00 04 */	addi r9, r4, 4
/* 801E9920 001E6880  38 04 00 14 */	addi r0, r4, 0x14
/* 801E9924 001E6884  81 83 00 00 */	lwz r12, 0(r3)
/* 801E9928 001E6888  39 1B 00 64 */	addi r8, r27, 0x64
/* 801E992C 001E688C  91 8C 00 08 */	stw r12, 8(r12)
/* 801E9930 001E6890  80 A3 00 00 */	lwz r5, 0(r3)
/* 801E9934 001E6894  38 63 01 7C */	addi r3, r3, 0x17c
/* 801E9938 001E6898  91 85 00 04 */	stw r12, 4(r5)
/* 801E993C 001E689C  91 7B 00 04 */	stw r11, 4(r27)
/* 801E9940 001E68A0  91 5B 00 0C */	stw r10, 0xc(r27)
/* 801E9944 001E68A4  91 5B 00 08 */	stw r10, 8(r27)
/* 801E9948 001E68A8  91 5B 00 00 */	stw r10, 0(r27)
/* 801E994C 001E68AC  80 DB 00 00 */	lwz r6, 0(r27)
/* 801E9950 001E68B0  90 C6 00 08 */	stw r6, 8(r6)
/* 801E9954 001E68B4  80 BB 00 00 */	lwz r5, 0(r27)
/* 801E9958 001E68B8  90 C5 00 04 */	stw r6, 4(r5)
/* 801E995C 001E68BC  91 7B 00 14 */	stw r11, 0x14(r27)
/* 801E9960 001E68C0  93 5B 00 1C */	stw r26, 0x1c(r27)
/* 801E9964 001E68C4  93 5B 00 18 */	stw r26, 0x18(r27)
/* 801E9968 001E68C8  93 5B 00 10 */	stw r26, 0x10(r27)
/* 801E996C 001E68CC  80 DB 00 10 */	lwz r6, 0x10(r27)
/* 801E9970 001E68D0  90 C6 00 08 */	stw r6, 8(r6)
/* 801E9974 001E68D4  80 BB 00 10 */	lwz r5, 0x10(r27)
/* 801E9978 001E68D8  90 C5 00 04 */	stw r6, 4(r5)
/* 801E997C 001E68DC  91 7B 00 24 */	stw r11, 0x24(r27)
/* 801E9980 001E68E0  93 3B 00 2C */	stw r25, 0x2c(r27)
/* 801E9984 001E68E4  93 3B 00 28 */	stw r25, 0x28(r27)
/* 801E9988 001E68E8  93 3B 00 20 */	stw r25, 0x20(r27)
/* 801E998C 001E68EC  80 DB 00 20 */	lwz r6, 0x20(r27)
/* 801E9990 001E68F0  90 C6 00 08 */	stw r6, 8(r6)
/* 801E9994 001E68F4  80 BB 00 20 */	lwz r5, 0x20(r27)
/* 801E9998 001E68F8  90 C5 00 04 */	stw r6, 4(r5)
/* 801E999C 001E68FC  91 7B 00 38 */	stw r11, 0x38(r27)
/* 801E99A0 001E6900  91 3B 00 40 */	stw r9, 0x40(r27)
/* 801E99A4 001E6904  91 3B 00 3C */	stw r9, 0x3c(r27)
/* 801E99A8 001E6908  91 3B 00 34 */	stw r9, 0x34(r27)
/* 801E99AC 001E690C  80 DB 00 34 */	lwz r6, 0x34(r27)
/* 801E99B0 001E6910  90 C6 00 08 */	stw r6, 8(r6)
/* 801E99B4 001E6914  80 BB 00 34 */	lwz r5, 0x34(r27)
/* 801E99B8 001E6918  90 C5 00 04 */	stw r6, 4(r5)
/* 801E99BC 001E691C  91 7B 00 48 */	stw r11, 0x48(r27)
/* 801E99C0 001E6920  90 1B 00 50 */	stw r0, 0x50(r27)
/* 801E99C4 001E6924  90 1B 00 4C */	stw r0, 0x4c(r27)
/* 801E99C8 001E6928  90 1B 00 44 */	stw r0, 0x44(r27)
/* 801E99CC 001E692C  80 DB 00 44 */	lwz r6, 0x44(r27)
/* 801E99D0 001E6930  90 C6 00 08 */	stw r6, 8(r6)
/* 801E99D4 001E6934  80 BB 00 44 */	lwz r5, 0x44(r27)
/* 801E99D8 001E6938  90 C5 00 04 */	stw r6, 4(r5)
/* 801E99DC 001E693C  93 FB 00 54 */	stw r31, 0x54(r27)
/* 801E99E0 001E6940  93 FB 00 58 */	stw r31, 0x58(r27)
/* 801E99E4 001E6944  91 7B 00 64 */	stw r11, 0x64(r27)
/* 801E99E8 001E6948  91 1B 00 6C */	stw r8, 0x6c(r27)
/* 801E99EC 001E694C  91 1B 00 68 */	stw r8, 0x68(r27)
/* 801E99F0 001E6950  91 1B 00 60 */	stw r8, 0x60(r27)
/* 801E99F4 001E6954  80 BB 00 60 */	lwz r5, 0x60(r27)
/* 801E99F8 001E6958  90 A5 00 08 */	stw r5, 8(r5)
/* 801E99FC 001E695C  80 9B 00 60 */	lwz r4, 0x60(r27)
/* 801E9A00 001E6960  90 A4 00 04 */	stw r5, 4(r4)
/* 801E9A04 001E6964  93 FB 00 70 */	stw r31, 0x70(r27)
/* 801E9A08 001E6968  93 FB 00 30 */	stw r31, 0x30(r27)
/* 801E9A0C 001E696C  93 FB 00 5C */	stw r31, 0x5c(r27)
/* 801E9A10 001E6970  4B E5 97 B5 */	bl __ct__6CameraFv
/* 801E9A14 001E6974  C0 22 C0 18 */	lfs f1, lbl_803EC218@sda21(r2)
/* 801E9A18 001E6978  38 7B 00 00 */	addi r3, r27, 0
/* 801E9A1C 001E697C  38 9C 00 00 */	addi r4, r28, 0
/* 801E9A20 001E6980  38 BD 00 00 */	addi r5, r29, 0
/* 801E9A24 001E6984  38 DE 00 00 */	addi r6, r30, 0
/* 801E9A28 001E6988  4B FB 76 D9 */	bl init__Q23zen15particleManagerFUlUlUlf
/* 801E9A2C 001E698C  3C 60 80 2E */	lis r3, "ptclInfo__9@unnamed@"@ha
/* 801E9A30 001E6990  3B C3 61 44 */	addi r30, r3, "ptclInfo__9@unnamed@"@l
/* 801E9A34 001E6994  3B 20 00 00 */	li r25, 0
lbl_801E9A38:
/* 801E9A38 001E6998  38 60 00 0C */	li r3, 0xc
/* 801E9A3C 001E699C  4B E5 D5 C9 */	bl alloc__6SystemFUl
/* 801E9A40 001E69A0  3B A3 00 00 */	addi r29, r3, 0
/* 801E9A44 001E69A4  7F A0 EB 79 */	or. r0, r29, r29
/* 801E9A48 001E69A8  41 82 00 5C */	beq lbl_801E9AA4
/* 801E9A4C 001E69AC  80 9E 00 00 */	lwz r4, 0(r30)
/* 801E9A50 001E69B0  38 A0 00 01 */	li r5, 1
/* 801E9A54 001E69B4  83 9E 00 08 */	lwz r28, 8(r30)
/* 801E9A58 001E69B8  83 7E 00 04 */	lwz r27, 4(r30)
/* 801E9A5C 001E69BC  80 61 00 08 */	lwz r3, 8(r1)
/* 801E9A60 001E69C0  4B FB 74 C5 */	bl load__Q23zen14particleLoaderFPcb
/* 801E9A64 001E69C4  90 7D 00 00 */	stw r3, 0(r29)
/* 801E9A68 001E69C8  38 9B 00 00 */	addi r4, r27, 0
/* 801E9A6C 001E69CC  38 A0 00 01 */	li r5, 1
/* 801E9A70 001E69D0  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801E9A74 001E69D4  4B E5 56 95 */	bl loadTexture__9StdSystemFPcb
/* 801E9A78 001E69D8  28 1C 00 00 */	cmplwi r28, 0
/* 801E9A7C 001E69DC  90 7D 00 04 */	stw r3, 4(r29)
/* 801E9A80 001E69E0  41 82 00 1C */	beq lbl_801E9A9C
/* 801E9A84 001E69E4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801E9A88 001E69E8  38 9C 00 00 */	addi r4, r28, 0
/* 801E9A8C 001E69EC  38 A0 00 01 */	li r5, 1
/* 801E9A90 001E69F0  4B E5 56 79 */	bl loadTexture__9StdSystemFPcb
/* 801E9A94 001E69F4  90 7D 00 08 */	stw r3, 8(r29)
/* 801E9A98 001E69F8  48 00 00 0C */	b lbl_801E9AA4
lbl_801E9A9C:
/* 801E9A9C 001E69FC  38 00 00 00 */	li r0, 0
/* 801E9AA0 001E6A00  90 1D 00 08 */	stw r0, 8(r29)
lbl_801E9AA4:
/* 801E9AA4 001E6A04  3B 39 00 01 */	addi r25, r25, 1
/* 801E9AA8 001E6A08  83 61 00 08 */	lwz r27, 8(r1)
/* 801E9AAC 001E6A0C  38 1F 00 AC */	addi r0, r31, 0xac
/* 801E9AB0 001E6A10  2C 19 00 34 */	cmpwi r25, 0x34
/* 801E9AB4 001E6A14  7F BB 01 2E */	stwx r29, r27, r0
/* 801E9AB8 001E6A18  3B DE 00 0C */	addi r30, r30, 0xc
/* 801E9ABC 001E6A1C  3B FF 00 04 */	addi r31, r31, 4
/* 801E9AC0 001E6A20  41 80 FF 78 */	blt lbl_801E9A38
/* 801E9AC4 001E6A24  C0 22 C0 1C */	lfs f1, lbl_803EC21C@sda21(r2)
/* 801E9AC8 001E6A28  48 03 22 21 */	bl sinf
/* 801E9ACC 001E6A2C  FF E0 08 90 */	fmr f31, f1
/* 801E9AD0 001E6A30  C0 22 C0 1C */	lfs f1, lbl_803EC21C@sda21(r2)
/* 801E9AD4 001E6A34  48 03 20 81 */	bl cosf
/* 801E9AD8 001E6A38  C0 4D 26 A0 */	lfs f2, lbl_803E73C0@sda21(r13)
/* 801E9ADC 001E6A3C  38 7B 01 7C */	addi r3, r27, 0x17c
/* 801E9AE0 001E6A40  C0 0D 26 A8 */	lfs f0, lbl_803E73C8@sda21(r13)
/* 801E9AE4 001E6A44  38 81 00 28 */	addi r4, r1, 0x28
/* 801E9AE8 001E6A48  D0 41 00 28 */	stfs f2, 0x28(r1)
/* 801E9AEC 001E6A4C  EC 41 F8 24 */	fdivs f2, f1, f31
/* 801E9AF0 001E6A50  C0 62 C0 20 */	lfs f3, lbl_803EC220@sda21(r2)
/* 801E9AF4 001E6A54  C0 8D 26 A4 */	lfs f4, lbl_803E73C4@sda21(r13)
/* 801E9AF8 001E6A58  38 A1 00 1C */	addi r5, r1, 0x1c
/* 801E9AFC 001E6A5C  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 801E9B00 001E6A60  C0 2D 26 AC */	lfs f1, lbl_803E73CC@sda21(r13)
/* 801E9B04 001E6A64  EC 43 00 B2 */	fmuls f2, f3, f2
/* 801E9B08 001E6A68  D0 81 00 2C */	stfs f4, 0x2c(r1)
/* 801E9B0C 001E6A6C  C0 0D 26 B0 */	lfs f0, lbl_803E73D0@sda21(r13)
/* 801E9B10 001E6A70  D0 21 00 20 */	stfs f1, 0x20(r1)
/* 801E9B14 001E6A74  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 801E9B18 001E6A78  D0 41 00 30 */	stfs f2, 0x30(r1)
/* 801E9B1C 001E6A7C  4B E5 92 89 */	bl calcVectors__11CullFrustumFR8Vector3fR8Vector3f
/* 801E9B20 001E6A80  7F 63 DB 78 */	mr r3, r27
/* 801E9B24 001E6A84  BB 21 00 3C */	lmw r25, 0x3c(r1)
/* 801E9B28 001E6A88  80 01 00 64 */	lwz r0, 0x64(r1)
/* 801E9B2C 001E6A8C  CB E1 00 58 */	lfd f31, 0x58(r1)
/* 801E9B30 001E6A90  38 21 00 60 */	addi r1, r1, 0x60
/* 801E9B34 001E6A94  7C 08 03 A6 */	mtlr r0
/* 801E9B38 001E6A98  4E 80 00 20 */	blr 

.global "create__Q23zen11EffectMgr2DFUlR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
"create__Q23zen11EffectMgr2DFUlR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>":
/* 801E9B3C 001E6A9C  7C 08 02 A6 */	mflr r0
/* 801E9B40 001E6AA0  39 06 00 00 */	addi r8, r6, 0
/* 801E9B44 001E6AA4  90 01 00 04 */	stw r0, 4(r1)
/* 801E9B48 001E6AA8  54 80 10 3A */	slwi r0, r4, 2
/* 801E9B4C 001E6AAC  7C 83 02 14 */	add r4, r3, r0
/* 801E9B50 001E6AB0  94 21 FF F8 */	stwu r1, -8(r1)
/* 801E9B54 001E6AB4  38 05 00 00 */	addi r0, r5, 0
/* 801E9B58 001E6AB8  39 27 00 00 */	addi r9, r7, 0
/* 801E9B5C 001E6ABC  81 44 00 AC */	lwz r10, 0xac(r4)
/* 801E9B60 001E6AC0  7C 07 03 78 */	mr r7, r0
/* 801E9B64 001E6AC4  38 63 00 10 */	addi r3, r3, 0x10
/* 801E9B68 001E6AC8  80 8A 00 00 */	lwz r4, 0(r10)
/* 801E9B6C 001E6ACC  80 AA 00 04 */	lwz r5, 4(r10)
/* 801E9B70 001E6AD0  80 CA 00 08 */	lwz r6, 8(r10)
/* 801E9B74 001E6AD4  4B FB 77 15 */	bl "createGenerator__Q23zen15particleManagerFPUcP7TextureP7TextureR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801E9B78 001E6AD8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801E9B7C 001E6ADC  38 21 00 08 */	addi r1, r1, 8
/* 801E9B80 001E6AE0  7C 08 03 A6 */	mtlr r0
/* 801E9B84 001E6AE4  4E 80 00 20 */	blr 

.global update__Q23zen11EffectMgr2DFv
update__Q23zen11EffectMgr2DFv:
/* 801E9B88 001E6AE8  7C 08 02 A6 */	mflr r0
/* 801E9B8C 001E6AEC  38 63 00 10 */	addi r3, r3, 0x10
/* 801E9B90 001E6AF0  90 01 00 04 */	stw r0, 4(r1)
/* 801E9B94 001E6AF4  94 21 FF F8 */	stwu r1, -8(r1)
/* 801E9B98 001E6AF8  4B FB 77 65 */	bl update__Q23zen15particleManagerFv
/* 801E9B9C 001E6AFC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801E9BA0 001E6B00  38 21 00 08 */	addi r1, r1, 8
/* 801E9BA4 001E6B04  7C 08 03 A6 */	mtlr r0
/* 801E9BA8 001E6B08  4E 80 00 20 */	blr 

.global draw__Q23zen11EffectMgr2DFR8Graphics
draw__Q23zen11EffectMgr2DFR8Graphics:
/* 801E9BAC 001E6B0C  7C 08 02 A6 */	mflr r0
/* 801E9BB0 001E6B10  90 01 00 04 */	stw r0, 4(r1)
/* 801E9BB4 001E6B14  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 801E9BB8 001E6B18  93 E1 00 34 */	stw r31, 0x34(r1)
/* 801E9BBC 001E6B1C  7C 9F 23 78 */	mr r31, r4
/* 801E9BC0 001E6B20  93 C1 00 30 */	stw r30, 0x30(r1)
/* 801E9BC4 001E6B24  7C 7E 1B 78 */	mr r30, r3
/* 801E9BC8 001E6B28  80 A4 03 0C */	lwz r5, 0x30c(r4)
/* 801E9BCC 001E6B2C  80 04 03 10 */	lwz r0, 0x310(r4)
/* 801E9BD0 001E6B30  3C 80 43 30 */	lis r4, 0x4330
/* 801E9BD4 001E6B34  6C A3 80 00 */	xoris r3, r5, 0x8000
/* 801E9BD8 001E6B38  C8 A2 C0 30 */	lfd f5, "@880"@sda21(r2)
/* 801E9BDC 001E6B3C  90 61 00 2C */	stw r3, 0x2c(r1)
/* 801E9BE0 001E6B40  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 801E9BE4 001E6B44  C0 42 C0 24 */	lfs f2, lbl_803EC224@sda21(r2)
/* 801E9BE8 001E6B48  90 01 00 24 */	stw r0, 0x24(r1)
/* 801E9BEC 001E6B4C  38 7E 01 7C */	addi r3, r30, 0x17c
/* 801E9BF0 001E6B50  C0 62 C0 28 */	lfs f3, lbl_803EC228@sda21(r2)
/* 801E9BF4 001E6B54  90 81 00 28 */	stw r4, 0x28(r1)
/* 801E9BF8 001E6B58  C0 82 C0 2C */	lfs f4, lbl_803EC22C@sda21(r2)
/* 801E9BFC 001E6B5C  90 81 00 20 */	stw r4, 0x20(r1)
/* 801E9C00 001E6B60  C8 21 00 28 */	lfd f1, 0x28(r1)
/* 801E9C04 001E6B64  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 801E9C08 001E6B68  EC 21 28 28 */	fsubs f1, f1, f5
/* 801E9C0C 001E6B6C  EC 00 28 28 */	fsubs f0, f0, f5
/* 801E9C10 001E6B70  EC 21 00 24 */	fdivs f1, f1, f0
/* 801E9C14 001E6B74  4B E5 90 41 */	bl update__11CullFrustumFffff
/* 801E9C18 001E6B78  7F E3 FB 78 */	mr r3, r31
/* 801E9C1C 001E6B7C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 801E9C20 001E6B80  38 9E 01 7C */	addi r4, r30, 0x17c
/* 801E9C24 001E6B84  81 8C 00 6C */	lwz r12, 0x6c(r12)
/* 801E9C28 001E6B88  7D 88 03 A6 */	mtlr r12
/* 801E9C2C 001E6B8C  4E 80 00 21 */	blrl 
/* 801E9C30 001E6B90  7F E3 FB 78 */	mr r3, r31
/* 801E9C34 001E6B94  C0 3E 03 48 */	lfs f1, 0x348(r30)
/* 801E9C38 001E6B98  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 801E9C3C 001E6B9C  38 9E 03 DC */	addi r4, r30, 0x3dc
/* 801E9C40 001E6BA0  C0 5E 03 40 */	lfs f2, 0x340(r30)
/* 801E9C44 001E6BA4  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 801E9C48 001E6BA8  C0 7E 03 4C */	lfs f3, 0x34c(r30)
/* 801E9C4C 001E6BAC  7D 88 03 A6 */	mtlr r12
/* 801E9C50 001E6BB0  C0 9E 03 50 */	lfs f4, 0x350(r30)
/* 801E9C54 001E6BB4  C0 A2 C0 28 */	lfs f5, lbl_803EC228@sda21(r2)
/* 801E9C58 001E6BB8  4E 80 00 21 */	blrl 
/* 801E9C5C 001E6BBC  80 DF 03 10 */	lwz r6, 0x310(r31)
/* 801E9C60 001E6BC0  38 00 00 00 */	li r0, 0
/* 801E9C64 001E6BC4  80 BF 03 0C */	lwz r5, 0x30c(r31)
/* 801E9C68 001E6BC8  38 81 00 10 */	addi r4, r1, 0x10
/* 801E9C6C 001E6BCC  38 7F 00 00 */	addi r3, r31, 0
/* 801E9C70 001E6BD0  90 01 00 10 */	stw r0, 0x10(r1)
/* 801E9C74 001E6BD4  90 01 00 14 */	stw r0, 0x14(r1)
/* 801E9C78 001E6BD8  90 A1 00 18 */	stw r5, 0x18(r1)
/* 801E9C7C 001E6BDC  90 C1 00 1C */	stw r6, 0x1c(r1)
/* 801E9C80 001E6BE0  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 801E9C84 001E6BE4  81 8C 00 50 */	lwz r12, 0x50(r12)
/* 801E9C88 001E6BE8  7D 88 03 A6 */	mtlr r12
/* 801E9C8C 001E6BEC  4E 80 00 21 */	blrl 
/* 801E9C90 001E6BF0  7F E3 FB 78 */	mr r3, r31
/* 801E9C94 001E6BF4  80 9F 02 E4 */	lwz r4, 0x2e4(r31)
/* 801E9C98 001E6BF8  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 801E9C9C 001E6BFC  38 A0 00 00 */	li r5, 0
/* 801E9CA0 001E6C00  38 84 01 E0 */	addi r4, r4, 0x1e0
/* 801E9CA4 001E6C04  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 801E9CA8 001E6C08  7D 88 03 A6 */	mtlr r12
/* 801E9CAC 001E6C0C  4E 80 00 21 */	blrl 
/* 801E9CB0 001E6C10  38 7E 00 10 */	addi r3, r30, 0x10
/* 801E9CB4 001E6C14  38 9F 00 00 */	addi r4, r31, 0
/* 801E9CB8 001E6C18  4B FB 77 55 */	bl draw__Q23zen15particleManagerFR8Graphics
/* 801E9CBC 001E6C1C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 801E9CC0 001E6C20  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 801E9CC4 001E6C24  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 801E9CC8 001E6C28  38 21 00 38 */	addi r1, r1, 0x38
/* 801E9CCC 001E6C2C  7C 08 03 A6 */	mtlr r0
/* 801E9CD0 001E6C30  4E 80 00 20 */	blr 

.global killAll__Q23zen11EffectMgr2DFb
killAll__Q23zen11EffectMgr2DFb:
/* 801E9CD4 001E6C34  7C 08 02 A6 */	mflr r0
/* 801E9CD8 001E6C38  38 63 00 10 */	addi r3, r3, 0x10
/* 801E9CDC 001E6C3C  90 01 00 04 */	stw r0, 4(r1)
/* 801E9CE0 001E6C40  94 21 FF F8 */	stwu r1, -8(r1)
/* 801E9CE4 001E6C44  4B FB 78 45 */	bl killAllGenarator__Q23zen15particleManagerFb
/* 801E9CE8 001E6C48  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801E9CEC 001E6C4C  38 21 00 08 */	addi r1, r1, 8
/* 801E9CF0 001E6C50  7C 08 03 A6 */	mtlr r0
/* 801E9CF4 001E6C54  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802E5AD0:
	.asciz "effectMgr2D.cpp"
lbl_802E5AE0:
	.asciz "effectMgr2D"
lbl_802E5AEC:
	.asciz "effects/pcr/frt_l.pcr"
	.skip 2
lbl_802E5B04:
	.asciz "effects/tex/waku02.bti"
	.skip 1
lbl_802E5B1C:
	.asciz "effects/pcr/frt_h_l.pcr"
lbl_802E5B34:
	.asciz "effects/pcr/frt_s.pcr"
	.skip 2
lbl_802E5B4C:
	.asciz "effects/tex/waku03.bti"
	.skip 1
lbl_802E5B64:
	.asciz "effects/pcr/frt_h_s.pcr"
lbl_802E5B7C:
	.asciz "effects/pcr/bg_od01.pcr"
lbl_802E5B94:
	.asciz "effects/tex/star4_i.bti"
lbl_802E5BAC:
	.asciz "effects/pcr/bg_od01r.pcr"
	.skip 3
lbl_802E5BC8:
	.asciz "effects/pcr/bg_od01g.pcr"
	.skip 3
lbl_802E5BE4:
	.asciz "effects/pcr/bg_od01b.pcr"
	.skip 3
lbl_802E5C00:
	.asciz "effects/pcr/bg_od02.pcr"
lbl_802E5C18:
	.asciz "effects/pcr/bg_od02r.pcr"
	.skip 3
lbl_802E5C34:
	.asciz "effects/pcr/bg_od02g.pcr"
	.skip 3
lbl_802E5C50:
	.asciz "effects/pcr/bg_od02b.pcr"
	.skip 3
lbl_802E5C6C:
	.asciz "effects/pcr/record_l.pcr"
	.skip 3
lbl_802E5C88:
	.asciz "effects/tex/waku.bti"
	.skip 3
lbl_802E5CA0:
	.asciz "effects/pcr/rec_h_l.pcr"
lbl_802E5CB8:
	.asciz "effects/pcr/star.pcr"
	.skip 3
lbl_802E5CD0:
	.asciz "effects/pcr/record_s.pcr"
	.skip 3
lbl_802E5CEC:
	.asciz "effects/pcr/rec_h_s.pcr"
lbl_802E5D04:
	.asciz "effects/pcr/bg_ds01.pcr"
lbl_802E5D1C:
	.asciz "effects/pcr/bg_ds01r.pcr"
	.skip 3
lbl_802E5D38:
	.asciz "effects/pcr/bg_ds01g.pcr"
	.skip 3
lbl_802E5D54:
	.asciz "effects/pcr/bg_ds01b.pcr"
	.skip 3
lbl_802E5D70:
	.asciz "effects/pcr/bg_ds02.pcr"
lbl_802E5D88:
	.asciz "effects/pcr/bg_ds02r.pcr"
	.skip 3
lbl_802E5DA4:
	.asciz "effects/pcr/bg_ds02g.pcr"
	.skip 3
lbl_802E5DC0:
	.asciz "effects/pcr/bg_ds02b.pcr"
	.skip 3
lbl_802E5DDC:
	.asciz "effects/pcr/bg_cms01.pcr"
	.skip 3
lbl_802E5DF8:
	.asciz "effects/pcr/bg_cms01r.pcr"
	.skip 2
lbl_802E5E14:
	.asciz "effects/pcr/bg_cms01g.pcr"
	.skip 2
lbl_802E5E30:
	.asciz "effects/pcr/bg_cms01b.pcr"
	.skip 2
lbl_802E5E4C:
	.asciz "effects/pcr/bg_cms02.pcr"
	.skip 3
lbl_802E5E68:
	.asciz "effects/pcr/bg_cms02r.pcr"
	.skip 2
lbl_802E5E84:
	.asciz "effects/pcr/bg_cms02g.pcr"
	.skip 2
lbl_802E5EA0:
	.asciz "effects/pcr/bg_cms02b.pcr"
	.skip 2
lbl_802E5EBC:
	.asciz "effects/pcr/selec_tm.pcr"
	.skip 3
lbl_802E5ED8:
	.asciz "effects/tex/ps_glow.bti"
lbl_802E5EF0:
	.asciz "effects/pcr/selec_km.pcr"
	.skip 3
lbl_802E5F0C:
	.asciz "effects/pcr/file_slm.pcr"
	.skip 3
lbl_802E5F28:
	.asciz "effects/tex/fuchibal.bti"
	.skip 3
lbl_802E5F44:
	.asciz "effects/pcr/file_sel.pcr"
	.skip 3
lbl_802E5F60:
	.asciz "effects/pcr/select_k.pcr"
	.skip 3
lbl_802E5F7C:
	.asciz "effects/pcr/select_t.pcr"
	.skip 3
lbl_802E5F98:
	.asciz "effects/pcr/syokika2.pcr"
	.skip 3
lbl_802E5FB4:
	.asciz "effects/pcr/syokika.pcr"
lbl_802E5FCC:
	.asciz "effects/pcr/file_cpm.pcr"
	.skip 3
lbl_802E5FE8:
	.asciz "effects/pcr/file_cp.pcr"
lbl_802E6000:
	.asciz "effects/pcr/file_dlm.pcr"
	.skip 3
lbl_802E601C:
	.asciz "effects/pcr/file_del.pcr"
	.skip 3
lbl_802E6038:
	.asciz "effects/pcr/rktin1.pcr"
	.skip 1
lbl_802E6050:
	.asciz "effects/pcr/mapap1.pcr"
	.skip 1
lbl_802E6068:
	.asciz "effects/tex/p_hsbs3.bti"
lbl_802E6080:
	.asciz "effects/pcr/mapap2.pcr"
	.skip 1
lbl_802E6098:
	.asciz "effects/pcr/z_ufoF.pcr"
	.skip 1
lbl_802E60B0:
	.asciz "effects/tex/kaen_ok.bti"
lbl_802E60C8:
	.asciz "effects/pcr/z_ufoS.pcr"
	.skip 1
lbl_802E60E0:
	.asciz "effects/tex/ice_smok.bti"
	.skip 3
lbl_802E60FC:
	.asciz "effects/pcr/z_ony.pcr"
	.skip 2
lbl_802E6114:
	.asciz "effects/pcr/z_sstar.pcr"
lbl_802E612C:
	.asciz "effects/tex/ps_ball.bti"
"ptclInfo__9@unnamed@":
	.4byte lbl_802E5AEC
	.4byte lbl_802E5B04
	.4byte 0x00000000
	.4byte lbl_802E5B1C
	.4byte lbl_802E5B04
	.4byte 0x00000000
	.4byte lbl_802E5B34
	.4byte lbl_802E5B4C
	.4byte 0x00000000
	.4byte lbl_802E5B64
	.4byte lbl_802E5B4C
	.4byte 0x00000000
	.4byte lbl_802E5B7C
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5BAC
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5BC8
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5BE4
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5C00
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5C18
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5C34
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5C50
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5C6C
	.4byte lbl_802E5C88
	.4byte lbl_802E5C88
	.4byte lbl_802E5CA0
	.4byte lbl_802E5C88
	.4byte lbl_802E5C88
	.4byte lbl_802E5CB8
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5CD0
	.4byte lbl_802E5C88
	.4byte lbl_802E5C88
	.4byte lbl_802E5CEC
	.4byte lbl_802E5C88
	.4byte lbl_802E5C88
	.4byte lbl_802E5D04
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5D1C
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5D38
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5D54
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5D70
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5D88
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5DA4
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5DC0
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5DDC
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5DF8
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5E14
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5E30
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5E4C
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5E68
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5E84
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5EA0
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E5EBC
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E5EF0
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E5F0C
	.4byte lbl_802E5F28
	.4byte 0x00000000
	.4byte lbl_802E5F44
	.4byte lbl_802E5F28
	.4byte 0x00000000
	.4byte lbl_802E5F60
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E5F7C
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E5F98
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E5FB4
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E5FCC
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E5FE8
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E6000
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E601C
	.4byte lbl_802E5ED8
	.4byte 0x00000000
	.4byte lbl_802E6038
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E6050
	.4byte lbl_802E6068
	.4byte 0x00000000
	.4byte lbl_802E6080
	.4byte lbl_802E5F28
	.4byte 0x00000000
	.4byte lbl_802E6098
	.4byte lbl_802E60B0
	.4byte 0x00000000
	.4byte lbl_802E60C8
	.4byte lbl_802E60E0
	.4byte 0x00000000
	.4byte lbl_802E60FC
	.4byte lbl_802E5B94
	.4byte 0x00000000
	.4byte lbl_802E6114
	.4byte lbl_802E5B94
	.4byte lbl_802E612C
lbl_802E63B4:
	.asciz "zen::zenList"
	.skip 3
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E73C0:
	.4byte 0x43A00000
lbl_803E73C4:
	.4byte 0x43700000
lbl_803E73C8:
	.4byte 0x43A00000
lbl_803E73CC:
	.4byte 0x43700000
lbl_803E73D0:
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EC218:
	.4byte 0x42700000
lbl_803EC21C:
	.4byte 0x3E860A92
lbl_803EC220:
	.4byte 0x43700000
lbl_803EC224:
	.4byte 0x41F00000
lbl_803EC228:
	.4byte 0x3F800000
lbl_803EC22C:
	.4byte 0x459C4000
"@880":
	.4byte 0x43300000
	.4byte 0x80000000
