.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__10KoganePropFv
__ct__10KoganePropFv:
/* 80175A30 00172990  7C 08 02 A6 */	mflr r0
/* 80175A34 00172994  90 01 00 04 */	stw r0, 4(r1)
/* 80175A38 00172998  94 21 FE F8 */	stwu r1, -0x108(r1)
/* 80175A3C 0017299C  93 E1 01 04 */	stw r31, 0x104(r1)
/* 80175A40 001729A0  93 C1 01 00 */	stw r30, 0x100(r1)
/* 80175A44 001729A4  7C 7E 1B 78 */	mr r30, r3
/* 80175A48 001729A8  4B FD 7E 85 */	bl __ct__8BossPropFv
/* 80175A4C 001729AC  3C 60 80 22 */	lis r3, __vt__5ANode@ha
/* 80175A50 001729B0  38 03 73 8C */	addi r0, r3, __vt__5ANode@l
/* 80175A54 001729B4  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 80175A58 001729B8  90 1E 01 EC */	stw r0, 0x1ec(r30)
/* 80175A5C 001729BC  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 80175A60 001729C0  90 1E 01 EC */	stw r0, 0x1ec(r30)
/* 80175A64 001729C4  38 E0 00 00 */	li r7, 0
/* 80175A68 001729C8  3C 60 80 2D */	lis r3, __vt__10KoganeProp@ha
/* 80175A6C 001729CC  90 FE 01 FC */	stw r7, 0x1fc(r30)
/* 80175A70 001729D0  38 C3 09 64 */	addi r6, r3, __vt__10KoganeProp@l
/* 80175A74 001729D4  3C 80 80 2D */	lis r4, lbl_802D071C@ha
/* 80175A78 001729D8  90 FE 01 F8 */	stw r7, 0x1f8(r30)
/* 80175A7C 001729DC  38 64 07 1C */	addi r3, r4, lbl_802D071C@l
/* 80175A80 001729E0  38 06 00 0C */	addi r0, r6, 0xc
/* 80175A84 001729E4  90 FE 01 F4 */	stw r7, 0x1f4(r30)
/* 80175A88 001729E8  38 A1 00 80 */	addi r5, r1, 0x80
/* 80175A8C 001729EC  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175A90 001729F0  90 7E 01 F0 */	stw r3, 0x1f0(r30)
/* 80175A94 001729F4  38 7E 02 04 */	addi r3, r30, 0x204
/* 80175A98 001729F8  90 DE 00 54 */	stw r6, 0x54(r30)
/* 80175A9C 001729FC  90 1E 01 EC */	stw r0, 0x1ec(r30)
/* 80175AA0 00172A00  90 FE 02 00 */	stw r7, 0x200(r30)
/* 80175AA4 00172A04  80 0D 04 50 */	lwz r0, lbl_803E5170@sda21(r13)
/* 80175AA8 00172A08  90 01 00 88 */	stw r0, 0x88(r1)
/* 80175AAC 00172A0C  80 01 00 88 */	lwz r0, 0x88(r1)
/* 80175AB0 00172A10  90 01 00 80 */	stw r0, 0x80(r1)
/* 80175AB4 00172A14  4B EE 8F CD */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175AB8 00172A18  3C 60 80 2A */	lis r3, "__vt__7Parm<f>"@ha
/* 80175ABC 00172A1C  3B E3 60 98 */	addi r31, r3, "__vt__7Parm<f>"@l
/* 80175AC0 00172A20  93 FE 02 0C */	stw r31, 0x20c(r30)
/* 80175AC4 00172A24  38 A1 00 7C */	addi r5, r1, 0x7c
/* 80175AC8 00172A28  38 7E 02 14 */	addi r3, r30, 0x214
/* 80175ACC 00172A2C  C0 02 AD 20 */	lfs f0, lbl_803EAF20@sda21(r2)
/* 80175AD0 00172A30  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175AD4 00172A34  D0 1E 02 10 */	stfs f0, 0x210(r30)
/* 80175AD8 00172A38  80 0D 04 54 */	lwz r0, lbl_803E5174@sda21(r13)
/* 80175ADC 00172A3C  90 01 00 90 */	stw r0, 0x90(r1)
/* 80175AE0 00172A40  80 01 00 90 */	lwz r0, 0x90(r1)
/* 80175AE4 00172A44  90 01 00 7C */	stw r0, 0x7c(r1)
/* 80175AE8 00172A48  4B EE 8F 99 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175AEC 00172A4C  93 FE 02 1C */	stw r31, 0x21c(r30)
/* 80175AF0 00172A50  38 A1 00 78 */	addi r5, r1, 0x78
/* 80175AF4 00172A54  38 7E 02 24 */	addi r3, r30, 0x224
/* 80175AF8 00172A58  C0 02 AD 24 */	lfs f0, lbl_803EAF24@sda21(r2)
/* 80175AFC 00172A5C  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175B00 00172A60  D0 1E 02 20 */	stfs f0, 0x220(r30)
/* 80175B04 00172A64  80 0D 04 58 */	lwz r0, lbl_803E5178@sda21(r13)
/* 80175B08 00172A68  90 01 00 98 */	stw r0, 0x98(r1)
/* 80175B0C 00172A6C  80 01 00 98 */	lwz r0, 0x98(r1)
/* 80175B10 00172A70  90 01 00 78 */	stw r0, 0x78(r1)
/* 80175B14 00172A74  4B EE 8F 6D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175B18 00172A78  93 FE 02 2C */	stw r31, 0x22c(r30)
/* 80175B1C 00172A7C  38 A1 00 74 */	addi r5, r1, 0x74
/* 80175B20 00172A80  38 7E 02 34 */	addi r3, r30, 0x234
/* 80175B24 00172A84  C0 02 AD 24 */	lfs f0, lbl_803EAF24@sda21(r2)
/* 80175B28 00172A88  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175B2C 00172A8C  D0 1E 02 30 */	stfs f0, 0x230(r30)
/* 80175B30 00172A90  80 0D 04 5C */	lwz r0, lbl_803E517C@sda21(r13)
/* 80175B34 00172A94  90 01 00 A0 */	stw r0, 0xa0(r1)
/* 80175B38 00172A98  80 01 00 A0 */	lwz r0, 0xa0(r1)
/* 80175B3C 00172A9C  90 01 00 74 */	stw r0, 0x74(r1)
/* 80175B40 00172AA0  4B EE 8F 41 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175B44 00172AA4  93 FE 02 3C */	stw r31, 0x23c(r30)
/* 80175B48 00172AA8  38 A1 00 70 */	addi r5, r1, 0x70
/* 80175B4C 00172AAC  38 7E 02 44 */	addi r3, r30, 0x244
/* 80175B50 00172AB0  C0 02 AD 28 */	lfs f0, lbl_803EAF28@sda21(r2)
/* 80175B54 00172AB4  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175B58 00172AB8  D0 1E 02 40 */	stfs f0, 0x240(r30)
/* 80175B5C 00172ABC  80 0D 04 60 */	lwz r0, lbl_803E5180@sda21(r13)
/* 80175B60 00172AC0  90 01 00 A8 */	stw r0, 0xa8(r1)
/* 80175B64 00172AC4  80 01 00 A8 */	lwz r0, 0xa8(r1)
/* 80175B68 00172AC8  90 01 00 70 */	stw r0, 0x70(r1)
/* 80175B6C 00172ACC  4B EE 8F 15 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175B70 00172AD0  93 FE 02 4C */	stw r31, 0x24c(r30)
/* 80175B74 00172AD4  38 A1 00 6C */	addi r5, r1, 0x6c
/* 80175B78 00172AD8  38 7E 02 54 */	addi r3, r30, 0x254
/* 80175B7C 00172ADC  C0 02 AD 2C */	lfs f0, lbl_803EAF2C@sda21(r2)
/* 80175B80 00172AE0  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175B84 00172AE4  D0 1E 02 50 */	stfs f0, 0x250(r30)
/* 80175B88 00172AE8  80 0D 04 64 */	lwz r0, lbl_803E5184@sda21(r13)
/* 80175B8C 00172AEC  90 01 00 B0 */	stw r0, 0xb0(r1)
/* 80175B90 00172AF0  80 01 00 B0 */	lwz r0, 0xb0(r1)
/* 80175B94 00172AF4  90 01 00 6C */	stw r0, 0x6c(r1)
/* 80175B98 00172AF8  4B EE 8E E9 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175B9C 00172AFC  93 FE 02 5C */	stw r31, 0x25c(r30)
/* 80175BA0 00172B00  38 A1 00 68 */	addi r5, r1, 0x68
/* 80175BA4 00172B04  38 7E 02 64 */	addi r3, r30, 0x264
/* 80175BA8 00172B08  C0 02 AD 20 */	lfs f0, lbl_803EAF20@sda21(r2)
/* 80175BAC 00172B0C  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175BB0 00172B10  D0 1E 02 60 */	stfs f0, 0x260(r30)
/* 80175BB4 00172B14  80 0D 04 68 */	lwz r0, lbl_803E5188@sda21(r13)
/* 80175BB8 00172B18  90 01 00 B8 */	stw r0, 0xb8(r1)
/* 80175BBC 00172B1C  80 01 00 B8 */	lwz r0, 0xb8(r1)
/* 80175BC0 00172B20  90 01 00 68 */	stw r0, 0x68(r1)
/* 80175BC4 00172B24  4B EE 8E BD */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175BC8 00172B28  93 FE 02 6C */	stw r31, 0x26c(r30)
/* 80175BCC 00172B2C  38 A1 00 64 */	addi r5, r1, 0x64
/* 80175BD0 00172B30  38 7E 02 74 */	addi r3, r30, 0x274
/* 80175BD4 00172B34  C0 02 AD 30 */	lfs f0, lbl_803EAF30@sda21(r2)
/* 80175BD8 00172B38  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175BDC 00172B3C  D0 1E 02 70 */	stfs f0, 0x270(r30)
/* 80175BE0 00172B40  80 0D 04 6C */	lwz r0, lbl_803E518C@sda21(r13)
/* 80175BE4 00172B44  90 01 00 C0 */	stw r0, 0xc0(r1)
/* 80175BE8 00172B48  80 01 00 C0 */	lwz r0, 0xc0(r1)
/* 80175BEC 00172B4C  90 01 00 64 */	stw r0, 0x64(r1)
/* 80175BF0 00172B50  4B EE 8E 91 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175BF4 00172B54  93 FE 02 7C */	stw r31, 0x27c(r30)
/* 80175BF8 00172B58  38 A1 00 60 */	addi r5, r1, 0x60
/* 80175BFC 00172B5C  38 7E 02 84 */	addi r3, r30, 0x284
/* 80175C00 00172B60  C0 02 AD 34 */	lfs f0, lbl_803EAF34@sda21(r2)
/* 80175C04 00172B64  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175C08 00172B68  D0 1E 02 80 */	stfs f0, 0x280(r30)
/* 80175C0C 00172B6C  80 0D 04 70 */	lwz r0, lbl_803E5190@sda21(r13)
/* 80175C10 00172B70  90 01 00 C8 */	stw r0, 0xc8(r1)
/* 80175C14 00172B74  80 01 00 C8 */	lwz r0, 0xc8(r1)
/* 80175C18 00172B78  90 01 00 60 */	stw r0, 0x60(r1)
/* 80175C1C 00172B7C  4B EE 8E 65 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175C20 00172B80  93 FE 02 8C */	stw r31, 0x28c(r30)
/* 80175C24 00172B84  38 A1 00 5C */	addi r5, r1, 0x5c
/* 80175C28 00172B88  38 7E 02 94 */	addi r3, r30, 0x294
/* 80175C2C 00172B8C  C0 02 AD 38 */	lfs f0, lbl_803EAF38@sda21(r2)
/* 80175C30 00172B90  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175C34 00172B94  D0 1E 02 90 */	stfs f0, 0x290(r30)
/* 80175C38 00172B98  80 0D 04 74 */	lwz r0, lbl_803E5194@sda21(r13)
/* 80175C3C 00172B9C  90 01 00 D0 */	stw r0, 0xd0(r1)
/* 80175C40 00172BA0  80 01 00 D0 */	lwz r0, 0xd0(r1)
/* 80175C44 00172BA4  90 01 00 5C */	stw r0, 0x5c(r1)
/* 80175C48 00172BA8  4B EE 8E 39 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175C4C 00172BAC  93 FE 02 9C */	stw r31, 0x29c(r30)
/* 80175C50 00172BB0  38 A1 00 58 */	addi r5, r1, 0x58
/* 80175C54 00172BB4  38 7E 02 A4 */	addi r3, r30, 0x2a4
/* 80175C58 00172BB8  C0 02 AD 3C */	lfs f0, lbl_803EAF3C@sda21(r2)
/* 80175C5C 00172BBC  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175C60 00172BC0  D0 1E 02 A0 */	stfs f0, 0x2a0(r30)
/* 80175C64 00172BC4  80 0D 04 78 */	lwz r0, lbl_803E5198@sda21(r13)
/* 80175C68 00172BC8  90 01 00 D8 */	stw r0, 0xd8(r1)
/* 80175C6C 00172BCC  80 01 00 D8 */	lwz r0, 0xd8(r1)
/* 80175C70 00172BD0  90 01 00 58 */	stw r0, 0x58(r1)
/* 80175C74 00172BD4  4B EE 8E 0D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175C78 00172BD8  93 FE 02 AC */	stw r31, 0x2ac(r30)
/* 80175C7C 00172BDC  38 A1 00 54 */	addi r5, r1, 0x54
/* 80175C80 00172BE0  38 7E 02 B4 */	addi r3, r30, 0x2b4
/* 80175C84 00172BE4  C0 02 AD 20 */	lfs f0, lbl_803EAF20@sda21(r2)
/* 80175C88 00172BE8  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175C8C 00172BEC  D0 1E 02 B0 */	stfs f0, 0x2b0(r30)
/* 80175C90 00172BF0  80 0D 04 7C */	lwz r0, lbl_803E519C@sda21(r13)
/* 80175C94 00172BF4  90 01 00 E0 */	stw r0, 0xe0(r1)
/* 80175C98 00172BF8  80 01 00 E0 */	lwz r0, 0xe0(r1)
/* 80175C9C 00172BFC  90 01 00 54 */	stw r0, 0x54(r1)
/* 80175CA0 00172C00  4B EE 8D E1 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175CA4 00172C04  93 FE 02 BC */	stw r31, 0x2bc(r30)
/* 80175CA8 00172C08  38 A1 00 50 */	addi r5, r1, 0x50
/* 80175CAC 00172C0C  38 7E 02 C4 */	addi r3, r30, 0x2c4
/* 80175CB0 00172C10  C0 02 AD 40 */	lfs f0, lbl_803EAF40@sda21(r2)
/* 80175CB4 00172C14  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175CB8 00172C18  D0 1E 02 C0 */	stfs f0, 0x2c0(r30)
/* 80175CBC 00172C1C  80 0D 04 80 */	lwz r0, lbl_803E51A0@sda21(r13)
/* 80175CC0 00172C20  90 01 00 E8 */	stw r0, 0xe8(r1)
/* 80175CC4 00172C24  80 01 00 E8 */	lwz r0, 0xe8(r1)
/* 80175CC8 00172C28  90 01 00 50 */	stw r0, 0x50(r1)
/* 80175CCC 00172C2C  4B EE 8D B5 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175CD0 00172C30  93 FE 02 CC */	stw r31, 0x2cc(r30)
/* 80175CD4 00172C34  38 A1 00 4C */	addi r5, r1, 0x4c
/* 80175CD8 00172C38  38 7E 02 D4 */	addi r3, r30, 0x2d4
/* 80175CDC 00172C3C  C0 02 AD 44 */	lfs f0, lbl_803EAF44@sda21(r2)
/* 80175CE0 00172C40  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175CE4 00172C44  D0 1E 02 D0 */	stfs f0, 0x2d0(r30)
/* 80175CE8 00172C48  80 0D 04 84 */	lwz r0, lbl_803E51A4@sda21(r13)
/* 80175CEC 00172C4C  90 01 00 F0 */	stw r0, 0xf0(r1)
/* 80175CF0 00172C50  80 01 00 F0 */	lwz r0, 0xf0(r1)
/* 80175CF4 00172C54  90 01 00 4C */	stw r0, 0x4c(r1)
/* 80175CF8 00172C58  4B EE 8D 89 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175CFC 00172C5C  93 FE 02 DC */	stw r31, 0x2dc(r30)
/* 80175D00 00172C60  38 A1 00 48 */	addi r5, r1, 0x48
/* 80175D04 00172C64  38 7E 02 E4 */	addi r3, r30, 0x2e4
/* 80175D08 00172C68  C0 02 AD 48 */	lfs f0, lbl_803EAF48@sda21(r2)
/* 80175D0C 00172C6C  38 9E 02 00 */	addi r4, r30, 0x200
/* 80175D10 00172C70  D0 1E 02 E0 */	stfs f0, 0x2e0(r30)
/* 80175D14 00172C74  80 0D 04 88 */	lwz r0, lbl_803E51A8@sda21(r13)
/* 80175D18 00172C78  90 01 00 F8 */	stw r0, 0xf8(r1)
/* 80175D1C 00172C7C  80 01 00 F8 */	lwz r0, 0xf8(r1)
/* 80175D20 00172C80  90 01 00 48 */	stw r0, 0x48(r1)
/* 80175D24 00172C84  4B EE 8D 5D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80175D28 00172C88  93 FE 02 EC */	stw r31, 0x2ec(r30)
/* 80175D2C 00172C8C  7F C3 F3 78 */	mr r3, r30
/* 80175D30 00172C90  C0 22 AD 4C */	lfs f1, lbl_803EAF4C@sda21(r2)
/* 80175D34 00172C94  D0 3E 02 F0 */	stfs f1, 0x2f0(r30)
/* 80175D38 00172C98  D0 3E 00 10 */	stfs f1, 0x10(r30)
/* 80175D3C 00172C9C  C0 02 AD 50 */	lfs f0, lbl_803EAF50@sda21(r2)
/* 80175D40 00172CA0  D0 1E 00 30 */	stfs f0, 0x30(r30)
/* 80175D44 00172CA4  D0 3E 00 40 */	stfs f1, 0x40(r30)
/* 80175D48 00172CA8  80 01 01 0C */	lwz r0, 0x10c(r1)
/* 80175D4C 00172CAC  83 E1 01 04 */	lwz r31, 0x104(r1)
/* 80175D50 00172CB0  83 C1 01 00 */	lwz r30, 0x100(r1)
/* 80175D54 00172CB4  38 21 01 08 */	addi r1, r1, 0x108
/* 80175D58 00172CB8  7C 08 03 A6 */	mtlr r0
/* 80175D5C 00172CBC  4E 80 00 20 */	blr 

.global __ct__6KoganeFP12CreatureProp
__ct__6KoganeFP12CreatureProp:
/* 80175D60 00172CC0  7C 08 02 A6 */	mflr r0
/* 80175D64 00172CC4  90 01 00 04 */	stw r0, 4(r1)
/* 80175D68 00172CC8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80175D6C 00172CCC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80175D70 00172CD0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80175D74 00172CD4  7C 7E 1B 78 */	mr r30, r3
/* 80175D78 00172CD8  4B FD 81 01 */	bl __ct__4BossFP12CreatureProp
/* 80175D7C 00172CDC  3C 60 80 2D */	lis r3, __vt__6Kogane@ha
/* 80175D80 00172CE0  38 03 07 A4 */	addi r0, r3, __vt__6Kogane@l
/* 80175D84 00172CE4  90 1E 00 00 */	stw r0, 0(r30)
/* 80175D88 00172CE8  38 60 00 14 */	li r3, 0x14
/* 80175D8C 00172CEC  4B ED 12 79 */	bl alloc__6SystemFUl
/* 80175D90 00172CF0  3B E3 00 00 */	addi r31, r3, 0
/* 80175D94 00172CF4  7F E3 FB 79 */	or. r3, r31, r31
/* 80175D98 00172CF8  41 82 00 0C */	beq .L_80175DA4
/* 80175D9C 00172CFC  38 80 00 03 */	li r4, 3
/* 80175DA0 00172D00  4B F1 2E 91 */	bl __ct__8CollInfoFi
.L_80175DA4:
/* 80175DA4 00172D04  93 FE 02 20 */	stw r31, 0x220(r30)
/* 80175DA8 00172D08  38 60 00 20 */	li r3, 0x20
/* 80175DAC 00172D0C  4B ED 12 59 */	bl alloc__6SystemFUl
/* 80175DB0 00172D10  3B E3 00 00 */	addi r31, r3, 0
/* 80175DB4 00172D14  7F E3 FB 79 */	or. r3, r31, r31
/* 80175DB8 00172D18  41 82 00 0C */	beq .L_80175DC4
/* 80175DBC 00172D1C  7F C4 F3 78 */	mr r4, r30
/* 80175DC0 00172D20  48 00 05 29 */	bl __ct__8KoganeAiFP6Kogane
.L_80175DC4:
/* 80175DC4 00172D24  93 FE 03 BC */	stw r31, 0x3bc(r30)
/* 80175DC8 00172D28  7F C3 F3 78 */	mr r3, r30
/* 80175DCC 00172D2C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80175DD0 00172D30  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80175DD4 00172D34  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80175DD8 00172D38  38 21 00 18 */	addi r1, r1, 0x18
/* 80175DDC 00172D3C  7C 08 03 A6 */	mtlr r0
/* 80175DE0 00172D40  4E 80 00 20 */	blr 

.global getiMass__6KoganeFv
getiMass__6KoganeFv:
/* 80175DE4 00172D44  C0 22 AD 54 */	lfs f1, lbl_803EAF54@sda21(r2)
/* 80175DE8 00172D48  4E 80 00 20 */	blr 

.global init__6KoganeFR8Vector3f
init__6KoganeFR8Vector3f:
/* 80175DEC 00172D4C  7C 08 02 A6 */	mflr r0
/* 80175DF0 00172D50  38 A0 00 00 */	li r5, 0
/* 80175DF4 00172D54  90 01 00 04 */	stw r0, 4(r1)
/* 80175DF8 00172D58  38 00 00 01 */	li r0, 1
/* 80175DFC 00172D5C  38 83 00 00 */	addi r4, r3, 0
/* 80175E00 00172D60  94 21 FF F8 */	stwu r1, -8(r1)
/* 80175E04 00172D64  C0 02 AD 58 */	lfs f0, lbl_803EAF58@sda21(r2)
/* 80175E08 00172D68  D0 03 02 70 */	stfs f0, 0x270(r3)
/* 80175E0C 00172D6C  98 A3 02 BB */	stb r5, 0x2bb(r3)
/* 80175E10 00172D70  98 03 02 BC */	stb r0, 0x2bc(r3)
/* 80175E14 00172D74  98 A3 02 BE */	stb r5, 0x2be(r3)
/* 80175E18 00172D78  C0 02 AD 3C */	lfs f0, lbl_803EAF3C@sda21(r2)
/* 80175E1C 00172D7C  D0 03 02 E0 */	stfs f0, 0x2e0(r3)
/* 80175E20 00172D80  98 A3 03 B9 */	stb r5, 0x3b9(r3)
/* 80175E24 00172D84  98 A3 03 B8 */	stb r5, 0x3b8(r3)
/* 80175E28 00172D88  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 80175E2C 00172D8C  48 00 05 31 */	bl initAI__8KoganeAiFP6Kogane
/* 80175E30 00172D90  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80175E34 00172D94  38 21 00 08 */	addi r1, r1, 8
/* 80175E38 00172D98  7C 08 03 A6 */	mtlr r0
/* 80175E3C 00172D9C  4E 80 00 20 */	blr 

.global doKill__6KoganeFv
doKill__6KoganeFv:
/* 80175E40 00172DA0  7C 08 02 A6 */	mflr r0
/* 80175E44 00172DA4  38 80 00 00 */	li r4, 0
/* 80175E48 00172DA8  90 01 00 04 */	stw r0, 4(r1)
/* 80175E4C 00172DAC  38 00 00 00 */	li r0, 0
/* 80175E50 00172DB0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80175E54 00172DB4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80175E58 00172DB8  3B E3 00 00 */	addi r31, r3, 0
/* 80175E5C 00172DBC  98 03 02 B8 */	stb r0, 0x2b8(r3)
/* 80175E60 00172DC0  98 03 02 B9 */	stb r0, 0x2b9(r3)
/* 80175E64 00172DC4  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 80175E68 00172DC8  48 00 04 49 */	bl killCallBackEffect__8KoganeAiFb
/* 80175E6C 00172DCC  80 6D 31 68 */	lwz r3, bossMgr@sda21(r13)
/* 80175E70 00172DD0  7F E4 FB 78 */	mr r4, r31
/* 80175E74 00172DD4  4B FD C3 25 */	bl kill__7BossMgrFP8Creature
/* 80175E78 00172DD8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80175E7C 00172DDC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80175E80 00172DE0  38 21 00 18 */	addi r1, r1, 0x18
/* 80175E84 00172DE4  7C 08 03 A6 */	mtlr r0
/* 80175E88 00172DE8  4E 80 00 20 */	blr 

.global exitCourse__6KoganeFv
exitCourse__6KoganeFv:
/* 80175E8C 00172DEC  7C 08 02 A6 */	mflr r0
/* 80175E90 00172DF0  38 80 00 01 */	li r4, 1
/* 80175E94 00172DF4  90 01 00 04 */	stw r0, 4(r1)
/* 80175E98 00172DF8  94 21 FF F8 */	stwu r1, -8(r1)
/* 80175E9C 00172DFC  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 80175EA0 00172E00  48 00 04 11 */	bl killCallBackEffect__8KoganeAiFb
/* 80175EA4 00172E04  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80175EA8 00172E08  38 21 00 08 */	addi r1, r1, 8
/* 80175EAC 00172E0C  7C 08 03 A6 */	mtlr r0
/* 80175EB0 00172E10  4E 80 00 20 */	blr 

.global update__6KoganeFv
update__6KoganeFv:
/* 80175EB4 00172E14  7C 08 02 A6 */	mflr r0
/* 80175EB8 00172E18  90 01 00 04 */	stw r0, 4(r1)
/* 80175EBC 00172E1C  94 21 FF F8 */	stwu r1, -8(r1)
/* 80175EC0 00172E20  4B F1 53 49 */	bl update__8CreatureFv
/* 80175EC4 00172E24  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80175EC8 00172E28  38 21 00 08 */	addi r1, r1, 8
/* 80175ECC 00172E2C  7C 08 03 A6 */	mtlr r0
/* 80175ED0 00172E30  4E 80 00 20 */	blr 

.global refresh__6KoganeFR8Graphics
refresh__6KoganeFR8Graphics:
/* 80175ED4 00172E34  7C 08 02 A6 */	mflr r0
/* 80175ED8 00172E38  90 01 00 04 */	stw r0, 4(r1)
/* 80175EDC 00172E3C  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 80175EE0 00172E40  93 E1 00 54 */	stw r31, 0x54(r1)
/* 80175EE4 00172E44  3B E4 00 00 */	addi r31, r4, 0
/* 80175EE8 00172E48  93 C1 00 50 */	stw r30, 0x50(r1)
/* 80175EEC 00172E4C  3B C3 00 00 */	addi r30, r3, 0
/* 80175EF0 00172E50  38 7E 02 28 */	addi r3, r30, 0x228
/* 80175EF4 00172E54  38 9E 00 7C */	addi r4, r30, 0x7c
/* 80175EF8 00172E58  38 BE 00 88 */	addi r5, r30, 0x88
/* 80175EFC 00172E5C  38 DE 00 94 */	addi r6, r30, 0x94
/* 80175F00 00172E60  4B EC 81 F5 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 80175F04 00172E64  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 80175F08 00172E68  38 9E 02 28 */	addi r4, r30, 0x228
/* 80175F0C 00172E6C  38 A1 00 10 */	addi r5, r1, 0x10
/* 80175F10 00172E70  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 80175F14 00172E74  4B EC 81 C1 */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 80175F18 00172E78  38 7E 03 3C */	addi r3, r30, 0x33c
/* 80175F1C 00172E7C  81 9E 03 6C */	lwz r12, 0x36c(r30)
/* 80175F20 00172E80  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80175F24 00172E84  7D 88 03 A6 */	mtlr r12
/* 80175F28 00172E88  4E 80 00 21 */	blrl 
/* 80175F2C 00172E8C  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 80175F30 00172E90  38 9F 00 00 */	addi r4, r31, 0
/* 80175F34 00172E94  38 A1 00 10 */	addi r5, r1, 0x10
/* 80175F38 00172E98  80 63 00 00 */	lwz r3, 0(r3)
/* 80175F3C 00172E9C  38 C0 00 00 */	li r6, 0
/* 80175F40 00172EA0  4B EB F3 D5 */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 80175F44 00172EA4  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 80175F48 00172EA8  38 9F 00 00 */	addi r4, r31, 0
/* 80175F4C 00172EAC  38 A0 00 00 */	li r5, 0
/* 80175F50 00172EB0  4B F1 3B 9D */	bl updateInfo__8CollInfoFR8Graphicsb
/* 80175F54 00172EB4  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 80175F58 00172EB8  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 80175F5C 00172EBC  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 80175F60 00172EC0  38 21 00 58 */	addi r1, r1, 0x58
/* 80175F64 00172EC4  7C 08 03 A6 */	mtlr r0
/* 80175F68 00172EC8  4E 80 00 20 */	blr 

.global drawShape__6KoganeFR8Graphics
drawShape__6KoganeFR8Graphics:
/* 80175F6C 00172ECC  7C 08 02 A6 */	mflr r0
/* 80175F70 00172ED0  38 A0 00 00 */	li r5, 0
/* 80175F74 00172ED4  90 01 00 04 */	stw r0, 4(r1)
/* 80175F78 00172ED8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80175F7C 00172EDC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80175F80 00172EE0  3B E4 00 00 */	addi r31, r4, 0
/* 80175F84 00172EE4  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 80175F88 00172EE8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80175F8C 00172EEC  3B C3 00 00 */	addi r30, r3, 0
/* 80175F90 00172EF0  38 7F 00 00 */	addi r3, r31, 0
/* 80175F94 00172EF4  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80175F98 00172EF8  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 80175F9C 00172EFC  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 80175FA0 00172F00  7D 88 03 A6 */	mtlr r12
/* 80175FA4 00172F04  4E 80 00 21 */	blrl 
/* 80175FA8 00172F08  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 80175FAC 00172F0C  7F E4 FB 78 */	mr r4, r31
/* 80175FB0 00172F10  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 80175FB4 00172F14  38 C0 00 00 */	li r6, 0
/* 80175FB8 00172F18  80 63 00 00 */	lwz r3, 0(r3)
/* 80175FBC 00172F1C  4B EB A4 B1 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 80175FC0 00172F20  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80175FC4 00172F24  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80175FC8 00172F28  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80175FCC 00172F2C  38 21 00 18 */	addi r1, r1, 0x18
/* 80175FD0 00172F30  7C 08 03 A6 */	mtlr r0
/* 80175FD4 00172F34  4E 80 00 20 */	blr 

.global doAI__6KoganeFv
doAI__6KoganeFv:
/* 80175FD8 00172F38  7C 08 02 A6 */	mflr r0
/* 80175FDC 00172F3C  90 01 00 04 */	stw r0, 4(r1)
/* 80175FE0 00172F40  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80175FE4 00172F44  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80175FE8 00172F48  7C 7F 1B 78 */	mr r31, r3
/* 80175FEC 00172F4C  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 80175FF0 00172F50  48 00 15 25 */	bl update__8KoganeAiFv
/* 80175FF4 00172F54  38 00 00 00 */	li r0, 0
/* 80175FF8 00172F58  98 1F 02 BF */	stb r0, 0x2bf(r31)
/* 80175FFC 00172F5C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80176000 00172F60  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80176004 00172F64  38 21 00 18 */	addi r1, r1, 0x18
/* 80176008 00172F68  7C 08 03 A6 */	mtlr r0
/* 8017600C 00172F6C  4E 80 00 20 */	blr 

.global doAnimation__6KoganeFv
doAnimation__6KoganeFv:
/* 80176010 00172F70  7C 08 02 A6 */	mflr r0
/* 80176014 00172F74  7C 64 1B 78 */	mr r4, r3
/* 80176018 00172F78  90 01 00 04 */	stw r0, 4(r1)
/* 8017601C 00172F7C  94 21 FF F8 */	stwu r1, -8(r1)
/* 80176020 00172F80  80 03 03 90 */	lwz r0, 0x390(r3)
/* 80176024 00172F84  28 00 00 00 */	cmplwi r0, 0
/* 80176028 00172F88  41 82 00 1C */	beq .L_80176044
/* 8017602C 00172F8C  81 84 03 6C */	lwz r12, 0x36c(r4)
/* 80176030 00172F90  38 64 03 3C */	addi r3, r4, 0x33c
/* 80176034 00172F94  C0 24 02 D8 */	lfs f1, 0x2d8(r4)
/* 80176038 00172F98  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8017603C 00172F9C  7D 88 03 A6 */	mtlr r12
/* 80176040 00172FA0  4E 80 00 21 */	blrl 
.L_80176044:
/* 80176044 00172FA4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80176048 00172FA8  38 21 00 08 */	addi r1, r1, 8
/* 8017604C 00172FAC  7C 08 03 A6 */	mtlr r0
/* 80176050 00172FB0  4E 80 00 20 */	blr 

.global collisionCallback__6KoganeFR9CollEvent
collisionCallback__6KoganeFR9CollEvent:
/* 80176054 00172FB4  7C 08 02 A6 */	mflr r0
/* 80176058 00172FB8  90 01 00 04 */	stw r0, 4(r1)
/* 8017605C 00172FBC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80176060 00172FC0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80176064 00172FC4  7C 7F 1B 78 */	mr r31, r3
/* 80176068 00172FC8  88 03 03 B9 */	lbz r0, 0x3b9(r3)
/* 8017606C 00172FCC  28 00 00 00 */	cmplwi r0, 0
/* 80176070 00172FD0  40 82 00 28 */	bne .L_80176098
/* 80176074 00172FD4  80 64 00 00 */	lwz r3, 0(r4)
/* 80176078 00172FD8  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 8017607C 00172FDC  2C 00 00 00 */	cmpwi r0, 0
/* 80176080 00172FE0  40 82 00 18 */	bne .L_80176098
/* 80176084 00172FE4  4B F5 24 D1 */	bl getState__4PikiFv
/* 80176088 00172FE8  2C 03 00 0E */	cmpwi r3, 0xe
/* 8017608C 00172FEC  40 82 00 0C */	bne .L_80176098
/* 80176090 00172FF0  38 00 00 01 */	li r0, 1
/* 80176094 00172FF4  98 1F 03 B9 */	stb r0, 0x3b9(r31)
.L_80176098:
/* 80176098 00172FF8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017609C 00172FFC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801760A0 00173000  38 21 00 18 */	addi r1, r1, 0x18
/* 801760A4 00173004  7C 08 03 A6 */	mtlr r0
/* 801760A8 00173008  4E 80 00 20 */	blr 

.global read__10KoganePropFR18RandomAccessStream
read__10KoganePropFR18RandomAccessStream:
/* 801760AC 0017300C  7C 08 02 A6 */	mflr r0
/* 801760B0 00173010  90 01 00 04 */	stw r0, 4(r1)
/* 801760B4 00173014  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801760B8 00173018  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801760BC 0017301C  3B E4 00 00 */	addi r31, r4, 0
/* 801760C0 00173020  93 C1 00 10 */	stw r30, 0x10(r1)
/* 801760C4 00173024  3B C3 00 00 */	addi r30, r3, 0
/* 801760C8 00173028  4B EE 8A D1 */	bl read__10ParametersFR18RandomAccessStream
/* 801760CC 0017302C  38 7E 00 58 */	addi r3, r30, 0x58
/* 801760D0 00173030  38 9F 00 00 */	addi r4, r31, 0
/* 801760D4 00173034  4B EE 8A C5 */	bl read__10ParametersFR18RandomAccessStream
/* 801760D8 00173038  38 7E 02 00 */	addi r3, r30, 0x200
/* 801760DC 0017303C  38 9F 00 00 */	addi r4, r31, 0
/* 801760E0 00173040  4B EE 8A B9 */	bl read__10ParametersFR18RandomAccessStream
/* 801760E4 00173044  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801760E8 00173048  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801760EC 0017304C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 801760F0 00173050  38 21 00 18 */	addi r1, r1, 0x18
/* 801760F4 00173054  7C 08 03 A6 */	mtlr r0
/* 801760F8 00173058  4E 80 00 20 */	blr 

"@492@read__10KoganePropFR18RandomAccessStream":
/* 801760FC 0017305C  38 63 FE 14 */	addi r3, r3, -492
/* 80176100 00173060  4B FF FF AC */	b read__10KoganePropFR18RandomAccessStream

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802D0710:
	.asciz "Kogane.cpp"
.balign 4
lbl_802D071C:
	.asciz "CoreNode"
.balign 4
lbl_802D0728:
	.asciz "EventTalker"
.balign 4
lbl_802D0734:
	.asciz "RefCountable"
.balign 4
lbl_802D0744:
	.asciz "Creature"
.balign 4
lbl_802D0750:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D0764:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D0780:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte __RTTI__4Boss
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__6Kogane
__vt__6Kogane:
	.4byte __RTTI__6Kogane
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__6KoganeFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__6KoganeFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__4BossFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__4BossFv
	.4byte isVisible__4BossFv
	.4byte isOrganic__4BossFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__4BossFv
	.4byte isAlive__4BossFv
	.4byte isFixed__4BossFv
	.4byte needShadow__4BossFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__4BossFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__4BossFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__6KoganeFR9CollEvent
	.4byte bounceCallback__8CreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__4BossFR5PlaneP13DynCollObject
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
	.4byte update__6KoganeFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__6KoganeFR8Graphics
	.4byte refresh2d__4BossFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__6KoganeFv
	.4byte doAnimation__6KoganeFv
	.4byte doKill__6KoganeFv
	.4byte exitCourse__6KoganeFv
	.4byte isBossBgm__4BossFv
	.4byte attackDefaultPortion__4BossFv
	.4byte bombDamageCounter__4BossFP8CollPart
	.4byte drawShape__6KoganeFR8Graphics
.balign 4
lbl_802D08C8:
	.asciz "Parm<float>"
.balign 4
lbl_802D08D4:
	.asciz "BaseParm"
.balign 4
lbl_802D08E0:
	.4byte __RTTI__8BaseParm
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
lbl_802D0900:
	.asciz "KoganeProp"
.balign 4
lbl_802D090C:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.balign 4
lbl_802D0918:
	.asciz "CreatureProp"
.balign 4
lbl_802D0928:
	.asciz "BossProp"
.balign 4
lbl_802D0934:
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte 0
lbl_802D0940:
	.4byte __RTTI__5ANode
	.4byte 0x1ec
	.4byte __RTTI__8CoreNode
	.4byte 0x1ec
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte __RTTI__8BossProp
	.4byte 0
	.4byte 0
.global __vt__10KoganeProp
__vt__10KoganeProp:
	.4byte __RTTI__10KoganeProp
	.4byte 0
	.4byte read__10KoganePropFR18RandomAccessStream
	.4byte __RTTI__10KoganeProp
	.4byte 0xfffffe14
	.4byte getAgeNodeType__5ANodeFv
	.4byte "@492@read__10KoganePropFR18RandomAccessStream"
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E5168:
	.asciz "Kogane"
.balign 4
lbl_803E5170:
	.asciz "o00"
.balign 4
lbl_803E5174:
	.asciz "o01"
.balign 4
lbl_803E5178:
	.asciz "o02"
.balign 4
lbl_803E517C:
	.asciz "p00"
.balign 4
lbl_803E5180:
	.asciz "p10"
.balign 4
lbl_803E5184:
	.asciz "p50"
.balign 4
lbl_803E5188:
	.asciz "p51"
.balign 4
lbl_803E518C:
	.asciz "p52"
.balign 4
lbl_803E5190:
	.asciz "p53"
.balign 4
lbl_803E5194:
	.asciz "t00"
.balign 4
lbl_803E5198:
	.asciz "t01"
.balign 4
lbl_803E519C:
	.asciz "t10"
.balign 4
lbl_803E51A0:
	.asciz "t11"
.balign 4
lbl_803E51A4:
	.asciz "t50"
.balign 4
lbl_803E51A8:
	.asciz "s00"
.balign 4
__RTTI__11EventTalker:
	.4byte lbl_802D0728
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802D0734
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802D0744
	.4byte lbl_802D0750
.balign 4
lbl_803E51C4:
	.asciz "Boss"
.balign 4
__RTTI__4Boss:
	.4byte lbl_803E51C4
	.4byte lbl_802D0764
__RTTI__6Kogane:
	.4byte lbl_803E5168
	.4byte lbl_802D0780
__RTTI__8BaseParm:
	.4byte lbl_802D08D4
	.4byte 0
.balign 4
lbl_803E51E4:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E51E4
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802D071C
	.4byte lbl_802D090C
__RTTI__12CreatureProp:
	.4byte lbl_802D0918
	.4byte 0
__RTTI__8BossProp:
	.4byte lbl_802D0928
	.4byte lbl_802D0934
__RTTI__10KoganeProp:
	.4byte lbl_802D0900
	.4byte lbl_802D0940

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EAF20:
	.float 30.0
lbl_803EAF24:
	.4byte 0x40C00000
lbl_803EAF28:
	.4byte 0x437A0000
lbl_803EAF2C:
	.4byte 0x41200000
lbl_803EAF30:
	.4byte 0x42B40000
lbl_803EAF34:
	.4byte 0x42C80000
lbl_803EAF38:
	.4byte 0x43480000
lbl_803EAF3C:
	.float 20.0
lbl_803EAF40:
	.float 0.5
lbl_803EAF44:
	.4byte 0x40400000
lbl_803EAF48:
	.4byte 0x3FC00000
lbl_803EAF4C:
	.float 1.0
lbl_803EAF50:
	.float 0.0
lbl_803EAF54:
	.4byte 0x3DCCCCCD
lbl_803EAF58:
	.4byte 0x41C80000
