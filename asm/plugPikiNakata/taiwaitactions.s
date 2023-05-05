.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn start__20TaiWaitTurningActionFR4Teki, global
/* 80143A9C 001409FC  7C 08 02 A6 */	mflr r0
/* 80143AA0 00140A00  90 01 00 04 */	stw r0, 4(r1)
/* 80143AA4 00140A04  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80143AA8 00140A08  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80143AAC 00140A0C  7C 9F 23 78 */	mr r31, r4
/* 80143AB0 00140A10  4B FF 05 69 */	bl start__15TaiMotionActionFR4Teki
/* 80143AB4 00140A14  48 0D 45 BD */	bl rand
/* 80143AB8 00140A18  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 80143ABC 00140A1C  C8 82 A7 38 */	lfd f4, lbl_803EA938@sda21(r2)
/* 80143AC0 00140A20  90 01 00 1C */	stw r0, 0x1c(r1)
/* 80143AC4 00140A24  3C 00 43 30 */	lis r0, 0x4330
/* 80143AC8 00140A28  C0 62 A7 2C */	lfs f3, lbl_803EA92C@sda21(r2)
/* 80143ACC 00140A2C  90 01 00 18 */	stw r0, 0x18(r1)
/* 80143AD0 00140A30  C0 42 A7 28 */	lfs f2, lbl_803EA928@sda21(r2)
/* 80143AD4 00140A34  C8 21 00 18 */	lfd f1, 0x18(r1)
/* 80143AD8 00140A38  C0 02 A7 30 */	lfs f0, lbl_803EA930@sda21(r2)
/* 80143ADC 00140A3C  EC 81 20 28 */	fsubs f4, f1, f4
/* 80143AE0 00140A40  C0 2D E3 5C */	lfs f1, pi__6NMathF@sda21(r13)
/* 80143AE4 00140A44  EC 64 18 24 */	fdivs f3, f4, f3
/* 80143AE8 00140A48  EC 42 00 F2 */	fmuls f2, f2, f3
/* 80143AEC 00140A4C  EC 00 00 B2 */	fmuls f0, f0, f2
/* 80143AF0 00140A50  EC 01 00 32 */	fmuls f0, f1, f0
/* 80143AF4 00140A54  D0 1F 03 94 */	stfs f0, 0x394(r31)
/* 80143AF8 00140A58  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80143AFC 00140A5C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80143B00 00140A60  38 21 00 28 */	addi r1, r1, 0x28
/* 80143B04 00140A64  7C 08 03 A6 */	mtlr r0
/* 80143B08 00140A68  4E 80 00 20 */	blr 
.endfn start__20TaiWaitTurningActionFR4Teki

.fn act__20TaiWaitTurningActionFR4Teki, global
/* 80143B0C 00140A6C  7C 08 02 A6 */	mflr r0
/* 80143B10 00140A70  90 01 00 04 */	stw r0, 4(r1)
/* 80143B14 00140A74  94 21 FF F8 */	stwu r1, -8(r1)
/* 80143B18 00140A78  C0 02 A7 40 */	lfs f0, lbl_803EA940@sda21(r2)
/* 80143B1C 00140A7C  C0 C4 00 A0 */	lfs f6, 0xa0(r4)
/* 80143B20 00140A80  C0 22 A7 30 */	lfs f1, lbl_803EA930@sda21(r2)
/* 80143B24 00140A84  C0 AD E3 5C */	lfs f5, pi__6NMathF@sda21(r13)
/* 80143B28 00140A88  FC 06 00 40 */	fcmpo cr0, f6, f0
/* 80143B2C 00140A8C  EC 81 01 72 */	fmuls f4, f1, f5
/* 80143B30 00140A90  40 80 00 0C */	bge .L_80143B3C
/* 80143B34 00140A94  EC C6 20 2A */	fadds f6, f6, f4
/* 80143B38 00140A98  48 00 00 14 */	b .L_80143B4C
.L_80143B3C:
/* 80143B3C 00140A9C  FC 06 20 40 */	fcmpo cr0, f6, f4
/* 80143B40 00140AA0  4C 41 13 82 */	cror 2, 1, 2
/* 80143B44 00140AA4  40 82 00 08 */	bne .L_80143B4C
/* 80143B48 00140AA8  EC C6 20 28 */	fsubs f6, f6, f4
.L_80143B4C:
/* 80143B4C 00140AAC  C0 24 03 94 */	lfs f1, 0x394(r4)
/* 80143B50 00140AB0  FC 01 30 40 */	fcmpo cr0, f1, f6
/* 80143B54 00140AB4  FC 60 08 90 */	fmr f3, f1
/* 80143B58 00140AB8  4C 41 13 82 */	cror 2, 1, 2
/* 80143B5C 00140ABC  40 82 00 1C */	bne .L_80143B78
/* 80143B60 00140AC0  EC 43 30 28 */	fsubs f2, f3, f6
/* 80143B64 00140AC4  EC 04 10 28 */	fsubs f0, f4, f2
/* 80143B68 00140AC8  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 80143B6C 00140ACC  40 80 00 20 */	bge .L_80143B8C
/* 80143B70 00140AD0  EC 63 20 28 */	fsubs f3, f3, f4
/* 80143B74 00140AD4  48 00 00 18 */	b .L_80143B8C
.L_80143B78:
/* 80143B78 00140AD8  EC 46 18 28 */	fsubs f2, f6, f3
/* 80143B7C 00140ADC  EC 04 10 28 */	fsubs f0, f4, f2
/* 80143B80 00140AE0  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 80143B84 00140AE4  40 80 00 08 */	bge .L_80143B8C
/* 80143B88 00140AE8  EC 63 20 2A */	fadds f3, f3, f4
.L_80143B8C:
/* 80143B8C 00140AEC  EC 43 30 28 */	fsubs f2, f3, f6
/* 80143B90 00140AF0  C0 02 A7 40 */	lfs f0, lbl_803EA940@sda21(r2)
/* 80143B94 00140AF4  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80143B98 00140AF8  40 81 00 08 */	ble .L_80143BA0
/* 80143B9C 00140AFC  48 00 00 08 */	b .L_80143BA4
.L_80143BA0:
/* 80143BA0 00140B00  FC 40 10 50 */	fneg f2, f2
.L_80143BA4:
/* 80143BA4 00140B04  C0 02 A7 44 */	lfs f0, lbl_803EA944@sda21(r2)
/* 80143BA8 00140B08  EC 00 01 72 */	fmuls f0, f0, f5
/* 80143BAC 00140B0C  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80143BB0 00140B10  4C 40 13 82 */	cror 2, 0, 2
/* 80143BB4 00140B14  40 82 00 0C */	bne .L_80143BC0
/* 80143BB8 00140B18  38 60 00 01 */	li r3, 1
/* 80143BBC 00140B1C  48 00 00 24 */	b .L_80143BE0
.L_80143BC0:
/* 80143BC0 00140B20  80 A4 02 C4 */	lwz r5, 0x2c4(r4)
/* 80143BC4 00140B24  7C 83 23 78 */	mr r3, r4
/* 80143BC8 00140B28  80 85 00 84 */	lwz r4, 0x84(r5)
/* 80143BCC 00140B2C  80 84 00 04 */	lwz r4, 4(r4)
/* 80143BD0 00140B30  80 84 00 00 */	lwz r4, 0(r4)
/* 80143BD4 00140B34  C0 44 00 14 */	lfs f2, 0x14(r4)
/* 80143BD8 00140B38  48 00 39 F5 */	bl turnToward__5BTekiFff
/* 80143BDC 00140B3C  38 60 00 00 */	li r3, 0
.L_80143BE0:
/* 80143BE0 00140B40  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80143BE4 00140B44  38 21 00 08 */	addi r1, r1, 8
/* 80143BE8 00140B48  7C 08 03 A6 */	mtlr r0
/* 80143BEC 00140B4C  4E 80 00 20 */	blr 
.endfn act__20TaiWaitTurningActionFR4Teki

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802CCA48, local
	.asciz "taiwaitactions.cpp"
.endobj lbl_802CCA48
.balign 4
.obj lbl_802CCA5C, local
	.asciz "taiwaitactions"
.endobj lbl_802CCA5C
.balign 4
.obj lbl_802CCA6C, local
	.asciz "TaiWaitTurningAction"
.endobj lbl_802CCA6C
.balign 4
.obj lbl_802CCA84, local
	.asciz "TaiAction"
.endobj lbl_802CCA84
.balign 4
.obj lbl_802CCA90, local
	.asciz "TaiMotionAction"
.endobj lbl_802CCA90
.balign 4
.obj lbl_802CCAA0, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802CCAA0
.obj lbl_802CCAAC, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__15TaiMotionAction
	.4byte 0
	.4byte 0
.endobj lbl_802CCAAC
.obj __vt__20TaiWaitTurningAction, global
	.4byte __RTTI__20TaiWaitTurningAction
	.4byte 0
	.4byte start__20TaiWaitTurningActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__20TaiWaitTurningActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__20TaiWaitTurningAction

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__9TaiAction, local
	.4byte lbl_802CCA84
	.4byte 0
.endobj __RTTI__9TaiAction
.obj __RTTI__15TaiMotionAction, local
	.4byte lbl_802CCA90
	.4byte lbl_802CCAA0
.endobj __RTTI__15TaiMotionAction
.obj __RTTI__20TaiWaitTurningAction, local
	.4byte lbl_802CCA6C
	.4byte lbl_802CCAAC
.endobj __RTTI__20TaiWaitTurningAction

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA928, local
	.float 1.0
.endobj lbl_803EA928
.obj lbl_803EA92C, local
	.float 32767.0
.endobj lbl_803EA92C
.obj lbl_803EA930, local
	.float 2.0
.endobj lbl_803EA930
.balign 8
.obj lbl_803EA938, local
	.8byte 0x4330000080000000
.endobj lbl_803EA938
.obj lbl_803EA940, local
	.float 0.0
.endobj lbl_803EA940
.obj lbl_803EA944, local
	.float 0.1
.endobj lbl_803EA944
