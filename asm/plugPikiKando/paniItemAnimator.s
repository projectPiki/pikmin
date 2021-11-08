.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80136AC0 00133A20  90 7F 00 04 */	stw r3, 4(r31)
/* 80136AC4 00133A24  90 1F 00 00 */	stw r0, 0(r31)
/* 80136AC8 00133A28  90 FF 00 04 */	stw r7, 4(r31)
/* 80136ACC 00133A2C  90 DF 00 08 */	stw r6, 8(r31)
/* 80136AD0 00133A30  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 80136AD4 00133A34  C0 02 A4 CC */	lfs f0, lbl_803EA6CC@sda21(r2)
/* 80136AD8 00133A38  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 80136ADC 00133A3C  90 9F 00 04 */	stw r4, 4(r31)
/* 80136AE0 00133A40  D0 3F 00 14 */	stfs f1, 0x14(r31)
lbl_80136AE4:
/* 80136AE4 00133A44  38 60 00 0C */	li r3, 0xc
/* 80136AE8 00133A48  4B F1 05 1D */	bl alloc__6SystemFUl
/* 80136AEC 00133A4C  3B C3 00 00 */	addi r30, r3, 0
/* 80136AF0 00133A50  7F C0 F3 79 */	or. r0, r30, r30
/* 80136AF4 00133A54  41 82 00 38 */	beq lbl_80136B2C
/* 80136AF8 00133A58  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136AFC 00133A5C  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136B00 00133A60  90 1E 00 04 */	stw r0, 4(r30)
/* 80136B04 00133A64  38 00 FF FF */	li r0, -1
/* 80136B08 00133A68  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 80136B0C 00133A6C  90 1E 00 00 */	stw r0, 0(r30)
/* 80136B10 00133A70  38 03 95 94 */	addi r0, r3, __vt__15TaiMotionAction@l
/* 80136B14 00133A74  3C 60 80 2D */	lis r3, __vt__25TaiContinuousMotionAction@ha
/* 80136B18 00133A78  90 1E 00 04 */	stw r0, 4(r30)
/* 80136B1C 00133A7C  38 00 00 02 */	li r0, 2
/* 80136B20 00133A80  38 63 95 74 */	addi r3, r3, __vt__25TaiContinuousMotionAction@l
/* 80136B24 00133A84  90 1E 00 08 */	stw r0, 8(r30)
/* 80136B28 00133A88  90 7E 00 04 */	stw r3, 4(r30)
lbl_80136B2C:
/* 80136B2C 00133A8C  38 60 00 0C */	li r3, 0xc
/* 80136B30 00133A90  4B F1 04 D5 */	bl alloc__6SystemFUl
/* 80136B34 00133A94  3B A3 00 00 */	addi r29, r3, 0
/* 80136B38 00133A98  7F A3 EB 79 */	or. r3, r29, r29
/* 80136B3C 00133A9C  41 82 00 0C */	beq lbl_80136B48
/* 80136B40 00133AA0  38 80 00 07 */	li r4, 7
/* 80136B44 00133AA4  4B FF 05 55 */	bl __ct__8TaiStateFi
lbl_80136B48:
/* 80136B48 00133AA8  38 00 00 00 */	li r0, 0
/* 80136B4C 00133AAC  80 7D 00 08 */	lwz r3, 8(r29)
/* 80136B50 00133AB0  54 00 10 3A */	slwi r0, r0, 2
/* 80136B54 00133AB4  7F 03 01 2E */	stwx r24, r3, r0
/* 80136B58 00133AB8  38 00 00 01 */	li r0, 1
/* 80136B5C 00133ABC  38 60 00 02 */	li r3, 2
/* 80136B60 00133AC0  80 9D 00 08 */	lwz r4, 8(r29)
/* 80136B64 00133AC4  54 00 10 3A */	slwi r0, r0, 2
/* 80136B68 00133AC8  38 C0 00 03 */	li r6, 3
/* 80136B6C 00133ACC  7E A4 01 2E */	stwx r21, r4, r0
/* 80136B70 00133AD0  38 00 00 04 */	li r0, 4
/* 80136B74 00133AD4  38 80 00 05 */	li r4, 5
/* 80136B78 00133AD8  80 BD 00 08 */	lwz r5, 8(r29)
/* 80136B7C 00133ADC  54 63 10 3A */	slwi r3, r3, 2
/* 80136B80 00133AE0  38 E0 00 06 */	li r7, 6
/* 80136B84 00133AE4  7E 85 19 2E */	stwx r20, r5, r3
/* 80136B88 00133AE8  54 C6 10 3A */	slwi r6, r6, 2
/* 80136B8C 00133AEC  54 05 10 3A */	slwi r5, r0, 2
/* 80136B90 00133AF0  80 7D 00 08 */	lwz r3, 8(r29)
/* 80136B94 00133AF4  54 84 10 3A */	slwi r4, r4, 2
/* 80136B98 00133AF8  54 E0 10 3A */	slwi r0, r7, 2
/* 80136B9C 00133AFC  7F 43 31 2E */	stwx r26, r3, r6
/* 80136BA0 00133B00  38 60 00 08 */	li r3, 8
/* 80136BA4 00133B04  80 DD 00 08 */	lwz r6, 8(r29)
/* 80136BA8 00133B08  7E E6 29 2E */	stwx r23, r6, r5
/* 80136BAC 00133B0C  80 BD 00 08 */	lwz r5, 8(r29)
/* 80136BB0 00133B10  7F E5 21 2E */	stwx r31, r5, r4
/* 80136BB4 00133B14  80 9D 00 08 */	lwz r4, 8(r29)
/* 80136BB8 00133B18  7F C4 01 2E */	stwx r30, r4, r0
/* 80136BBC 00133B1C  80 99 00 08 */	lwz r4, 8(r25)
/* 80136BC0 00133B20  93 A4 00 0C */	stw r29, 0xc(r4)
/* 80136BC4 00133B24  4B F1 04 41 */	bl alloc__6SystemFUl
/* 80136BC8 00133B28  3B C3 00 00 */	addi r30, r3, 0
/* 80136BCC 00133B2C  7F C0 F3 79 */	or. r0, r30, r30
/* 80136BD0 00133B30  41 82 00 24 */	beq lbl_80136BF4
/* 80136BD4 00133B34  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136BD8 00133B38  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136BDC 00133B3C  90 1E 00 04 */	stw r0, 4(r30)
/* 80136BE0 00133B40  38 00 FF FF */	li r0, -1
/* 80136BE4 00133B44  3C 60 80 2D */	lis r3, __vt__25TaiNapkidTargetPikiAction@ha
/* 80136BE8 00133B48  90 1E 00 00 */	stw r0, 0(r30)
/* 80136BEC 00133B4C  38 03 A6 E4 */	addi r0, r3, __vt__25TaiNapkidTargetPikiAction@l
/* 80136BF0 00133B50  90 1E 00 04 */	stw r0, 4(r30)
lbl_80136BF4:
/* 80136BF4 00133B54  38 60 00 08 */	li r3, 8
/* 80136BF8 00133B58  4B F1 04 0D */	bl alloc__6SystemFUl
/* 80136BFC 00133B5C  3B 43 00 00 */	addi r26, r3, 0
/* 80136C00 00133B60  7F 40 D3 79 */	or. r0, r26, r26
/* 80136C04 00133B64  41 82 00 24 */	beq lbl_80136C28
/* 80136C08 00133B68  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136C0C 00133B6C  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136C10 00133B70  90 1A 00 04 */	stw r0, 4(r26)
/* 80136C14 00133B74  38 00 00 07 */	li r0, 7
/* 80136C18 00133B78  3C 60 80 2D */	lis r3, __vt__27TaiNapkidApproachPikiAction@ha
/* 80136C1C 00133B7C  90 1A 00 00 */	stw r0, 0(r26)
/* 80136C20 00133B80  38 03 A5 10 */	addi r0, r3, __vt__27TaiNapkidApproachPikiAction@l
/* 80136C24 00133B84  90 1A 00 04 */	stw r0, 4(r26)
lbl_80136C28:
/* 80136C28 00133B88  38 60 00 08 */	li r3, 8
/* 80136C2C 00133B8C  4B F1 03 D9 */	bl alloc__6SystemFUl
/* 80136C30 00133B90  3B 63 00 00 */	addi r27, r3, 0
/* 80136C34 00133B94  7F 60 DB 79 */	or. r0, r27, r27
/* 80136C38 00133B98  41 82 00 24 */	beq lbl_80136C5C
/* 80136C3C 00133B9C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136C40 00133BA0  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136C44 00133BA4  90 1B 00 04 */	stw r0, 4(r27)
/* 80136C48 00133BA8  38 00 00 01 */	li r0, 1
/* 80136C4C 00133BAC  3C 60 80 2D */	lis r3, __vt__23TaiNapkidPikiLostAction@ha
/* 80136C50 00133BB0  90 1B 00 00 */	stw r0, 0(r27)
/* 80136C54 00133BB4  38 03 A6 A0 */	addi r0, r3, __vt__23TaiNapkidPikiLostAction@l
/* 80136C58 00133BB8  90 1B 00 04 */	stw r0, 4(r27)
lbl_80136C5C:
/* 80136C5C 00133BBC  38 60 00 08 */	li r3, 8
/* 80136C60 00133BC0  4B F1 03 A5 */	bl alloc__6SystemFUl
/* 80136C64 00133BC4  3B 83 00 00 */	addi r28, r3, 0
/* 80136C68 00133BC8  7F 80 E3 79 */	or. r0, r28, r28
/* 80136C6C 00133BCC  41 82 00 24 */	beq lbl_80136C90
/* 80136C70 00133BD0  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136C74 00133BD4  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136C78 00133BD8  90 1C 00 04 */	stw r0, 4(r28)
/* 80136C7C 00133BDC  38 00 00 05 */	li r0, 5
/* 80136C80 00133BE0  3C 60 80 2D */	lis r3, __vt__25TaiNapkidShortRangeAction@ha
/* 80136C84 00133BE4  90 1C 00 00 */	stw r0, 0(r28)
/* 80136C88 00133BE8  38 03 A6 60 */	addi r0, r3, __vt__25TaiNapkidShortRangeAction@l
/* 80136C8C 00133BEC  90 1C 00 04 */	stw r0, 4(r28)
lbl_80136C90:
/* 80136C90 00133BF0  38 60 00 10 */	li r3, 0x10
/* 80136C94 00133BF4  4B F1 03 71 */	bl alloc__6SystemFUl
/* 80136C98 00133BF8  3B A3 00 00 */	addi r29, r3, 0
/* 80136C9C 00133BFC  7F A0 EB 79 */	or. r0, r29, r29
/* 80136CA0 00133C00  41 82 00 58 */	beq lbl_80136CF8
/* 80136CA4 00133C04  80 96 00 84 */	lwz r4, 0x84(r22)
/* 80136CA8 00133C08  3C A0 80 2C */	lis r5, __vt__9TaiAction@ha
/* 80136CAC 00133C0C  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 80136CB0 00133C10  80 84 00 04 */	lwz r4, 4(r4)
/* 80136CB4 00133C14  3C E0 80 2D */	lis r7, __vt__25TaiContinuousMotionAction@ha
/* 80136CB8 00133C18  3D 00 80 2D */	lis r8, __vt__16TaiTracingAction@ha
/* 80136CBC 00133C1C  80 84 00 00 */	lwz r4, 0(r4)
/* 80136CC0 00133C20  38 05 66 20 */	addi r0, r5, __vt__9TaiAction@l
/* 80136CC4 00133C24  38 C0 FF FF */	li r6, -1
/* 80136CC8 00133C28  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 80136CCC 00133C2C  38 A3 95 94 */	addi r5, r3, __vt__15TaiMotionAction@l
/* 80136CD0 00133C30  38 80 00 06 */	li r4, 6
/* 80136CD4 00133C34  90 1D 00 04 */	stw r0, 4(r29)
/* 80136CD8 00133C38  38 67 95 74 */	addi r3, r7, __vt__25TaiContinuousMotionAction@l
/* 80136CDC 00133C3C  38 08 9A 8C */	addi r0, r8, __vt__16TaiTracingAction@l
/* 80136CE0 00133C40  90 DD 00 00 */	stw r6, 0(r29)
/* 80136CE4 00133C44  90 BD 00 04 */	stw r5, 4(r29)
/* 80136CE8 00133C48  90 9D 00 08 */	stw r4, 8(r29)
/* 80136CEC 00133C4C  90 7D 00 04 */	stw r3, 4(r29)
/* 80136CF0 00133C50  90 1D 00 04 */	stw r0, 4(r29)
/* 80136CF4 00133C54  D0 1D 00 0C */	stfs f0, 0xc(r29)
lbl_80136CF8:
/* 80136CF8 00133C58  38 60 00 0C */	li r3, 0xc
/* 80136CFC 00133C5C  4B F1 03 09 */	bl alloc__6SystemFUl
/* 80136D00 00133C60  3B E3 00 00 */	addi r31, r3, 0
/* 80136D04 00133C64  7F E3 FB 79 */	or. r3, r31, r31
/* 80136D08 00133C68  41 82 00 0C */	beq lbl_80136D14
/* 80136D0C 00133C6C  38 80 00 09 */	li r4, 9
/* 80136D10 00133C70  4B FF 03 89 */	bl __ct__8TaiStateFi
lbl_80136D14:
/* 80136D14 00133C74  38 00 00 00 */	li r0, 0
/* 80136D18 00133C78  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136D1C 00133C7C  54 00 10 3A */	slwi r0, r0, 2
/* 80136D20 00133C80  7F 03 01 2E */	stwx r24, r3, r0
/* 80136D24 00133C84  38 80 00 01 */	li r4, 1
/* 80136D28 00133C88  38 00 00 02 */	li r0, 2
/* 80136D2C 00133C8C  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136D30 00133C90  54 84 10 3A */	slwi r4, r4, 2
/* 80136D34 00133C94  39 00 00 03 */	li r8, 3
/* 80136D38 00133C98  7E A3 21 2E */	stwx r21, r3, r4
/* 80136D3C 00133C9C  38 E0 00 04 */	li r7, 4
/* 80136D40 00133CA0  38 C0 00 05 */	li r6, 5
/* 80136D44 00133CA4  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136D48 00133CA8  54 00 10 3A */	slwi r0, r0, 2
/* 80136D4C 00133CAC  38 60 00 06 */	li r3, 6
/* 80136D50 00133CB0  7E 84 01 2E */	stwx r20, r4, r0
/* 80136D54 00133CB4  38 80 00 07 */	li r4, 7
/* 80136D58 00133CB8  39 20 00 08 */	li r9, 8
/* 80136D5C 00133CBC  80 BF 00 08 */	lwz r5, 8(r31)
/* 80136D60 00133CC0  55 00 10 3A */	slwi r0, r8, 2

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x70616e69
	.4byte 0x4974656d
	.4byte 0x416e696d
	.4byte 0x61746f72
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x70616e69
	.4byte 0x4974656d
	.4byte 0x416e696d
	.4byte 0x61746f72
	.4byte 0
.global motionLabels__16PaniItemAnimator
motionLabels__16PaniItemAnimator:
	.4byte 0x803E1F20
	.4byte 0x803E1F24
	.4byte 0x803E1F28
	.4byte 0x803E1F2C
	.4byte 0x803E1F30
	.4byte 0x803E1F34
	.4byte 0x803E1F38
	.4byte 0x803E1F3C
	.4byte 0x803E1F40
	.4byte 0x803E1F44
	.4byte 0x803E1F48
	.4byte 0x803E1F4C
	.4byte 0x803E1F50
	.4byte 0x803E1F54
	.4byte 0x803E1F58
	.4byte 0x50616E69
	.4byte 0x4974656D
	.4byte 0x416E696D
	.4byte 0x61746F72
	.4byte 0x00000000
	.4byte 0x416E696D
	.4byte 0x61746F72
	.4byte 0x00000000
	.4byte 0x50616E69
	.4byte 0x416E696D
	.4byte 0x61746F72
	.4byte 0x00000000
	.4byte 0x803E1F5C
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x803E1F5C
	.4byte 0x00000000
	.4byte 0x803E1F64
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__16PaniItemAnimator
__vt__16PaniItemAnimator:
	.4byte __RTTI__16PaniItemAnimator
	.4byte 0
	.4byte changeContext__12PaniAnimatorFP11AnimContext
	.4byte animate__12PaniAnimatorFf
	.4byte finishOneShot__8AnimatorFv
	.4byte finishLoop__8AnimatorFv
	.4byte updateContext__12PaniAnimatorFv
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x802bfca4
	.4byte 0
	.4byte 0x802bfcb0
	.4byte 0
	.4byte 0x802bfcc0
	.4byte 0x802bfccc
	.4byte 0x802bfce0
	.4byte 0x802bfcec
	.4byte 0x802bfd10
	.4byte 0x802bfd20
.global __RTTI__8MizuItem
__RTTI__8MizuItem:
	.4byte 0x802bfc84
	.4byte 0x802bfd4c
	.4byte 0x31000000
	.4byte 0x32000000
	.4byte 0x33000000
	.4byte 0x34000000
	.4byte 0x35000000
	.4byte 0x36000000
	.4byte 0x37000000
	.4byte 0x38000000
	.4byte 0x39000000
	.4byte 0x31300000
