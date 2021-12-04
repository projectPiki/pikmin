.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800F9B9C 000F6AFC  BF 41 00 30 */	stmw r26, 0x30(r1)
/* 800F9BA0 000F6B00  3B E3 00 00 */	addi r31, r3, 0
/* 800F9BA4 000F6B04  3B A4 00 00 */	addi r29, r4, 0
/* 800F9BA8 000F6B08  3B 85 00 00 */	addi r28, r5, 0
/* 800F9BAC 000F6B0C  3B C6 00 98 */	addi r30, r6, lbl_802C0098@l
/* 800F9BB0 000F6B10  4B F9 13 29 */	bl __ct__8CreatureFP12CreatureProp
/* 800F9BB4 000F6B14  3C 60 80 2B */	lis r3, __vt__19PaniAnimKeyListener@ha
/* 800F9BB8 000F6B18  38 03 DB 94 */	addi r0, r3, __vt__19PaniAnimKeyListener@l
/* 800F9BBC 000F6B1C  3C 60 80 2C */	lis r3, __vt__10PelletView@ha
/* 800F9BC0 000F6B20  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800F9BC4 000F6B24  38 03 03 B0 */	addi r0, r3, __vt__10PelletView@l
/* 800F9BC8 000F6B28  90 1F 02 BC */	stw r0, 0x2bc(r31)
/* 800F9BCC 000F6B2C  3B 60 00 00 */	li r27, 0
/* 800F9BD0 000F6B30  3C 60 80 2C */	lis r3, __vt__4Navi@ha
/* 800F9BD4 000F6B34  93 7F 02 C0 */	stw r27, 0x2c0(r31)
/* 800F9BD8 000F6B38  38 63 05 10 */	addi r3, r3, __vt__4Navi@l
/* 800F9BDC 000F6B3C  38 83 01 14 */	addi r4, r3, 0x114
/* 800F9BE0 000F6B40  90 7F 00 00 */	stw r3, 0(r31)
/* 800F9BE4 000F6B44  38 03 01 20 */	addi r0, r3, 0x120
/* 800F9BE8 000F6B48  38 7F 02 C4 */	addi r3, r31, 0x2c4
/* 800F9BEC 000F6B4C  90 9F 02 B8 */	stw r4, 0x2b8(r31)
/* 800F9BF0 000F6B50  90 1F 02 BC */	stw r0, 0x2bc(r31)
/* 800F9BF4 000F6B54  4B FD 3C 11 */	bl __ct__8OdoMeterFv
/* 800F9BF8 000F6B58  38 7F 03 24 */	addi r3, r31, 0x324
/* 800F9BFC 000F6B5C  4B F6 F9 35 */	bl __ct__12ShadowCasterFv
/* 800F9C00 000F6B60  93 7F 06 C4 */	stw r27, 0x6c4(r31)
/* 800F9C04 000F6B64  38 7F 08 34 */	addi r3, r31, 0x834
/* 800F9C08 000F6B68  93 7F 06 C8 */	stw r27, 0x6c8(r31)
/* 800F9C0C 000F6B6C  93 7F 06 CC */	stw r27, 0x6cc(r31)
/* 800F9C10 000F6B70  93 7F 06 D0 */	stw r27, 0x6d0(r31)
/* 800F9C14 000F6B74  C1 02 9C 60 */	lfs f8, lbl_803E9E60@sda21(r2)
/* 800F9C18 000F6B78  D1 1F 06 DC */	stfs f8, 0x6dc(r31)
/* 800F9C1C 000F6B7C  FC E0 40 90 */	fmr f7, f8
/* 800F9C20 000F6B80  FC C0 40 90 */	fmr f6, f8
/* 800F9C24 000F6B84  D1 1F 06 D8 */	stfs f8, 0x6d8(r31)
/* 800F9C28 000F6B88  FC A0 40 90 */	fmr f5, f8
/* 800F9C2C 000F6B8C  FC 80 40 90 */	fmr f4, f8
/* 800F9C30 000F6B90  D1 1F 06 D4 */	stfs f8, 0x6d4(r31)
/* 800F9C34 000F6B94  FC 60 40 90 */	fmr f3, f8
/* 800F9C38 000F6B98  D1 1F 06 EC */	stfs f8, 0x6ec(r31)
/* 800F9C3C 000F6B9C  FC 40 40 90 */	fmr f2, f8
/* 800F9C40 000F6BA0  FC 20 40 90 */	fmr f1, f8
/* 800F9C44 000F6BA4  D1 1F 06 E8 */	stfs f8, 0x6e8(r31)
/* 800F9C48 000F6BA8  FC 00 40 90 */	fmr f0, f8
/* 800F9C4C 000F6BAC  D1 1F 06 E4 */	stfs f8, 0x6e4(r31)
/* 800F9C50 000F6BB0  D0 FF 06 F8 */	stfs f7, 0x6f8(r31)
/* 800F9C54 000F6BB4  D0 FF 06 F4 */	stfs f7, 0x6f4(r31)
/* 800F9C58 000F6BB8  D0 FF 06 F0 */	stfs f7, 0x6f0(r31)
/* 800F9C5C 000F6BBC  D0 DF 07 48 */	stfs f6, 0x748(r31)
/* 800F9C60 000F6BC0  D0 DF 07 44 */	stfs f6, 0x744(r31)
/* 800F9C64 000F6BC4  D0 DF 07 40 */	stfs f6, 0x740(r31)
/* 800F9C68 000F6BC8  D0 BF 07 54 */	stfs f5, 0x754(r31)
/* 800F9C6C 000F6BCC  D0 BF 07 50 */	stfs f5, 0x750(r31)
/* 800F9C70 000F6BD0  D0 BF 07 4C */	stfs f5, 0x74c(r31)
/* 800F9C74 000F6BD4  D0 9F 07 60 */	stfs f4, 0x760(r31)
/* 800F9C78 000F6BD8  D0 9F 07 5C */	stfs f4, 0x75c(r31)
/* 800F9C7C 000F6BDC  D0 9F 07 58 */	stfs f4, 0x758(r31)
/* 800F9C80 000F6BE0  D0 7F 07 6C */	stfs f3, 0x76c(r31)
/* 800F9C84 000F6BE4  D0 7F 07 68 */	stfs f3, 0x768(r31)
/* 800F9C88 000F6BE8  D0 7F 07 64 */	stfs f3, 0x764(r31)
/* 800F9C8C 000F6BEC  D0 5F 07 8C */	stfs f2, 0x78c(r31)
/* 800F9C90 000F6BF0  D0 5F 07 88 */	stfs f2, 0x788(r31)
/* 800F9C94 000F6BF4  D0 5F 07 84 */	stfs f2, 0x784(r31)
/* 800F9C98 000F6BF8  D0 3F 07 98 */	stfs f1, 0x798(r31)
/* 800F9C9C 000F6BFC  D0 3F 07 94 */	stfs f1, 0x794(r31)
/* 800F9CA0 000F6C00  D0 3F 07 90 */	stfs f1, 0x790(r31)
/* 800F9CA4 000F6C04  D1 1F 07 A4 */	stfs f8, 0x7a4(r31)
/* 800F9CA8 000F6C08  D1 1F 07 A0 */	stfs f8, 0x7a0(r31)
/* 800F9CAC 000F6C0C  D1 1F 07 9C */	stfs f8, 0x79c(r31)
/* 800F9CB0 000F6C10  D0 1F 07 CC */	stfs f0, 0x7cc(r31)
/* 800F9CB4 000F6C14  D0 1F 07 C8 */	stfs f0, 0x7c8(r31)
/* 800F9CB8 000F6C18  D0 1F 07 C4 */	stfs f0, 0x7c4(r31)
/* 800F9CBC 000F6C1C  93 7F 07 D8 */	stw r27, 0x7d8(r31)
/* 800F9CC0 000F6C20  D1 1F 08 24 */	stfs f8, 0x824(r31)
/* 800F9CC4 000F6C24  D1 1F 08 20 */	stfs f8, 0x820(r31)
/* 800F9CC8 000F6C28  D1 1F 08 1C */	stfs f8, 0x81c(r31)
/* 800F9CCC 000F6C2C  48 02 5B D5 */	bl __ct__15PaniPikiAnimMgrFv
/* 800F9CD0 000F6C30  3C 60 80 09 */	lis r3, __ct__10SearchDataFv@ha
/* 800F9CD4 000F6C34  38 83 A7 F8 */	addi r4, r3, __ct__10SearchDataFv@l
/* 800F9CD8 000F6C38  38 7F 08 E0 */	addi r3, r31, 0x8e0
/* 800F9CDC 000F6C3C  38 A0 00 00 */	li r5, 0
/* 800F9CE0 000F6C40  38 C0 00 0C */	li r6, 0xc
/* 800F9CE4 000F6C44  38 E0 00 06 */	li r7, 6
/* 800F9CE8 000F6C48  48 11 AD 89 */	bl __construct_array
/* 800F9CEC 000F6C4C  3C 60 80 03 */	lis r3, __ct__8Vector3fFv@ha
/* 800F9CF0 000F6C50  38 83 5B 24 */	addi r4, r3, __ct__8Vector3fFv@l
/* 800F9CF4 000F6C54  38 7F 09 38 */	addi r3, r31, 0x938
/* 800F9CF8 000F6C58  38 A0 00 00 */	li r5, 0
/* 800F9CFC 000F6C5C  38 C0 00 0C */	li r6, 0xc
/* 800F9D00 000F6C60  38 E0 00 20 */	li r7, 0x20
/* 800F9D04 000F6C64  48 11 AD 6D */	bl __construct_array
/* 800F9D08 000F6C68  38 00 00 04 */	li r0, 4
/* 800F9D0C 000F6C6C  90 1F 07 00 */	stw r0, 0x700(r31)
/* 800F9D10 000F6C70  38 9E 00 28 */	addi r4, r30, 0x28
/* 800F9D14 000F6C74  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 800F9D18 000F6C78  4B F8 CA 21 */	bl start__7MemStatFPc
/* 800F9D1C 000F6C7C  93 7F 03 34 */	stw r27, 0x334(r31)
/* 800F9D20 000F6C80  38 0D D3 D4 */	addi r0, r13, lbl_803E20F4@sda21
/* 800F9D24 000F6C84  38 60 00 24 */	li r3, 0x24
/* 800F9D28 000F6C88  93 7F 03 30 */	stw r27, 0x330(r31)
/* 800F9D2C 000F6C8C  93 7F 03 2C */	stw r27, 0x32c(r31)
/* 800F9D30 000F6C90  90 1F 03 28 */	stw r0, 0x328(r31)
/* 800F9D34 000F6C94  4B F4 D2 D1 */	bl alloc__6SystemFUl
/* 800F9D38 000F6C98  7C 7A 1B 79 */	or. r26, r3, r3
/* 800F9D3C 000F6C9C  41 82 00 5C */	beq lbl_800F9D98
/* 800F9D40 000F6CA0  3C 60 80 22 */	lis r3, __vt__5ANode@ha
/* 800F9D44 000F6CA4  38 03 73 8C */	addi r0, r3, __vt__5ANode@l
/* 800F9D48 000F6CA8  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 800F9D4C 000F6CAC  90 1A 00 00 */	stw r0, 0(r26)
/* 800F9D50 000F6CB0  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 800F9D54 000F6CB4  90 1A 00 00 */	stw r0, 0(r26)
/* 800F9D58 000F6CB8  38 7A 00 00 */	addi r3, r26, 0
/* 800F9D5C 000F6CBC  38 8D D3 D4 */	addi r4, r13, lbl_803E20F4@sda21
/* 800F9D60 000F6CC0  93 7A 00 10 */	stw r27, 0x10(r26)
/* 800F9D64 000F6CC4  93 7A 00 0C */	stw r27, 0xc(r26)
/* 800F9D68 000F6CC8  93 7A 00 08 */	stw r27, 8(r26)
/* 800F9D6C 000F6CCC  4B F2 B1 69 */	bl setName__8CoreNodeFPc
/* 800F9D70 000F6CD0  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 800F9D74 000F6CD4  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 800F9D78 000F6CD8  90 1A 00 00 */	stw r0, 0(r26)
/* 800F9D7C 000F6CDC  38 7A 00 00 */	addi r3, r26, 0
/* 800F9D80 000F6CE0  38 8D D3 D4 */	addi r4, r13, lbl_803E20F4@sda21
/* 800F9D84 000F6CE4  4B F4 69 B9 */	bl init__4NodeFPc
/* 800F9D88 000F6CE8  3C 60 80 2C */	lis r3, __vt__10NaviDrawer@ha
/* 800F9D8C 000F6CEC  38 03 03 58 */	addi r0, r3, __vt__10NaviDrawer@l
/* 800F9D90 000F6CF0  90 1A 00 00 */	stw r0, 0(r26)
/* 800F9D94 000F6CF4  93 FA 00 20 */	stw r31, 0x20(r26)
lbl_800F9D98:
/* 800F9D98 000F6CF8  93 5F 06 B8 */	stw r26, 0x6b8(r31)
/* 800F9D9C 000F6CFC  38 9E 00 28 */	addi r4, r30, 0x28
/* 800F9DA0 000F6D00  C0 02 9D 20 */	lfs f0, lbl_803E9F20@sda21(r2)
/* 800F9DA4 000F6D04  D0 1F 05 04 */	stfs f0, 0x504(r31)
/* 800F9DA8 000F6D08  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 800F9DAC 000F6D0C  4B F8 CA 9D */	bl end__7MemStatFPc
/* 800F9DB0 000F6D10  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 800F9DB4 000F6D14  38 8D D3 D8 */	addi r4, r13, lbl_803E20F8@sda21
/* 800F9DB8 000F6D18  4B F8 C9 81 */	bl start__7MemStatFPc
/* 800F9DBC 000F6D1C  38 60 00 18 */	li r3, 0x18
/* 800F9DC0 000F6D20  4B F4 D2 45 */	bl alloc__6SystemFUl
/* 800F9DC4 000F6D24  28 03 00 00 */	cmplwi r3, 0
/* 800F9DC8 000F6D28  41 82 00 74 */	beq lbl_800F9E3C
/* 800F9DCC 000F6D2C  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 800F9DD0 000F6D30  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 800F9DD4 000F6D34  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 800F9DD8 000F6D38  90 03 00 00 */	stw r0, 0(r3)
/* 800F9DDC 000F6D3C  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 800F9DE0 000F6D40  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 800F9DE4 000F6D44  90 03 00 04 */	stw r0, 4(r3)
/* 800F9DE8 000F6D48  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 800F9DEC 000F6D4C  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 800F9DF0 000F6D50  90 03 00 08 */	stw r0, 8(r3)
/* 800F9DF4 000F6D54  38 A4 05 AC */	addi r5, r4, __vt__7KEffect@l
/* 800F9DF8 000F6D58  90 A3 00 00 */	stw r5, 0(r3)
/* 800F9DFC 000F6D5C  38 05 00 0C */	addi r0, r5, 0xc
/* 800F9E00 000F6D60  3C 80 80 2C */	lis r4, __vt__10BurnEffect@ha
/* 800F9E04 000F6D64  90 03 00 04 */	stw r0, 4(r3)
/* 800F9E08 000F6D68  38 84 25 F0 */	addi r4, r4, __vt__10BurnEffect@l
/* 800F9E0C 000F6D6C  38 05 00 18 */	addi r0, r5, 0x18
/* 800F9E10 000F6D70  90 03 00 08 */	stw r0, 8(r3)
/* 800F9E14 000F6D74  38 C4 00 0C */	addi r6, r4, 0xc
/* 800F9E18 000F6D78  38 A4 00 18 */	addi r5, r4, 0x18
/* 800F9E1C 000F6D7C  90 83 00 00 */	stw r4, 0(r3)
/* 800F9E20 000F6D80  38 9F 00 70 */	addi r4, r31, 0x70
/* 800F9E24 000F6D84  38 00 00 00 */	li r0, 0
/* 800F9E28 000F6D88  90 C3 00 04 */	stw r6, 4(r3)
/* 800F9E2C 000F6D8C  90 A3 00 08 */	stw r5, 8(r3)
/* 800F9E30 000F6D90  90 83 00 0C */	stw r4, 0xc(r3)
/* 800F9E34 000F6D94  90 03 00 10 */	stw r0, 0x10(r3)
/* 800F9E38 000F6D98  90 03 00 14 */	stw r0, 0x14(r3)
lbl_800F9E3C:
/* 800F9E3C 000F6D9C  90 7F 03 14 */	stw r3, 0x314(r31)
/* 800F9E40 000F6DA0  38 60 00 18 */	li r3, 0x18
/* 800F9E44 000F6DA4  4B F4 D1 C1 */	bl alloc__6SystemFUl
/* 800F9E48 000F6DA8  28 03 00 00 */	cmplwi r3, 0
/* 800F9E4C 000F6DAC  41 82 00 70 */	beq lbl_800F9EBC
/* 800F9E50 000F6DB0  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 800F9E54 000F6DB4  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 800F9E58 000F6DB8  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 800F9E5C 000F6DBC  90 03 00 00 */	stw r0, 0(r3)
/* 800F9E60 000F6DC0  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 800F9E64 000F6DC4  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 800F9E68 000F6DC8  90 03 00 04 */	stw r0, 4(r3)
/* 800F9E6C 000F6DCC  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 800F9E70 000F6DD0  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 800F9E74 000F6DD4  90 03 00 08 */	stw r0, 8(r3)
/* 800F9E78 000F6DD8  38 A4 05 AC */	addi r5, r4, __vt__7KEffect@l
/* 800F9E7C 000F6DDC  90 A3 00 00 */	stw r5, 0(r3)
/* 800F9E80 000F6DE0  38 05 00 0C */	addi r0, r5, 0xc
/* 800F9E84 000F6DE4  3C 80 80 2C */	lis r4, __vt__12RippleEffect@ha
/* 800F9E88 000F6DE8  90 03 00 04 */	stw r0, 4(r3)
/* 800F9E8C 000F6DEC  38 C4 26 60 */	addi r6, r4, __vt__12RippleEffect@l
/* 800F9E90 000F6DF0  38 05 00 18 */	addi r0, r5, 0x18
/* 800F9E94 000F6DF4  90 03 00 08 */	stw r0, 8(r3)
/* 800F9E98 000F6DF8  38 A6 00 0C */	addi r5, r6, 0xc
/* 800F9E9C 000F6DFC  38 86 00 18 */	addi r4, r6, 0x18
/* 800F9EA0 000F6E00  90 C3 00 00 */	stw r6, 0(r3)
/* 800F9EA4 000F6E04  38 00 00 00 */	li r0, 0
/* 800F9EA8 000F6E08  90 A3 00 04 */	stw r5, 4(r3)
/* 800F9EAC 000F6E0C  90 83 00 08 */	stw r4, 8(r3)
/* 800F9EB0 000F6E10  90 03 00 0C */	stw r0, 0xc(r3)
/* 800F9EB4 000F6E14  90 03 00 14 */	stw r0, 0x14(r3)
/* 800F9EB8 000F6E18  90 03 00 10 */	stw r0, 0x10(r3)
lbl_800F9EBC:
/* 800F9EBC 000F6E1C  90 7F 03 18 */	stw r3, 0x318(r31)
/* 800F9EC0 000F6E20  38 60 00 10 */	li r3, 0x10
/* 800F9EC4 000F6E24  4B F4 D1 41 */	bl alloc__6SystemFUl
/* 800F9EC8 000F6E28  3B 43 00 00 */	addi r26, r3, 0
/* 800F9ECC 000F6E2C  7F 43 D3 79 */	or. r3, r26, r26
/* 800F9ED0 000F6E30  41 82 00 08 */	beq lbl_800F9ED8
/* 800F9ED4 000F6E34  48 01 A4 95 */	bl __ct__15PermanentEffectFv
lbl_800F9ED8:
/* 800F9ED8 000F6E38  93 5F 07 74 */	stw r26, 0x774(r31)
/* 800F9EDC 000F6E3C  38 60 00 10 */	li r3, 0x10
/* 800F9EE0 000F6E40  4B F4 D1 25 */	bl alloc__6SystemFUl
/* 800F9EE4 000F6E44  3B 43 00 00 */	addi r26, r3, 0
/* 800F9EE8 000F6E48  7F 43 D3 79 */	or. r3, r26, r26
/* 800F9EEC 000F6E4C  41 82 00 08 */	beq lbl_800F9EF4
/* 800F9EF0 000F6E50  48 01 A4 79 */	bl __ct__15PermanentEffectFv
lbl_800F9EF4:
/* 800F9EF4 000F6E54  93 5F 07 78 */	stw r26, 0x778(r31)
/* 800F9EF8 000F6E58  38 60 00 10 */	li r3, 0x10
/* 800F9EFC 000F6E5C  4B F4 D1 09 */	bl alloc__6SystemFUl
/* 800F9F00 000F6E60  3B 43 00 00 */	addi r26, r3, 0
/* 800F9F04 000F6E64  7F 43 D3 79 */	or. r3, r26, r26
/* 800F9F08 000F6E68  41 82 00 08 */	beq lbl_800F9F10
/* 800F9F0C 000F6E6C  48 01 A4 5D */	bl __ct__15PermanentEffectFv
lbl_800F9F10:
/* 800F9F10 000F6E70  93 5F 07 7C */	stw r26, 0x77c(r31)
/* 800F9F14 000F6E74  38 60 00 10 */	li r3, 0x10
/* 800F9F18 000F6E78  4B F4 D0 ED */	bl alloc__6SystemFUl
/* 800F9F1C 000F6E7C  3B 43 00 00 */	addi r26, r3, 0
/* 800F9F20 000F6E80  7F 43 D3 79 */	or. r3, r26, r26
/* 800F9F24 000F6E84  41 82 00 08 */	beq lbl_800F9F2C
/* 800F9F28 000F6E88  48 01 A4 41 */	bl __ct__15PermanentEffectFv
lbl_800F9F2C:
/* 800F9F2C 000F6E8C  93 5F 07 80 */	stw r26, 0x780(r31)
/* 800F9F30 000F6E90  38 60 00 14 */	li r3, 0x14
/* 800F9F34 000F6E94  4B F4 D0 D1 */	bl alloc__6SystemFUl
/* 800F9F38 000F6E98  3B 43 00 00 */	addi r26, r3, 0
/* 800F9F3C 000F6E9C  7F 43 D3 79 */	or. r3, r26, r26
/* 800F9F40 000F6EA0  41 82 00 08 */	beq lbl_800F9F48
/* 800F9F44 000F6EA4  48 01 92 21 */	bl __ct__11SlimeEffectFv
lbl_800F9F48:
/* 800F9F48 000F6EA8  93 5F 03 1C */	stw r26, 0x31c(r31)
/* 800F9F4C 000F6EAC  38 8D D3 D8 */	addi r4, r13, lbl_803E20F8@sda21
/* 800F9F50 000F6EB0  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 800F9F54 000F6EB4  4B F8 C8 F5 */	bl end__7MemStatFPc
/* 800F9F58 000F6EB8  38 00 00 00 */	li r0, 0
/* 800F9F5C 000F6EBC  90 1F 07 10 */	stw r0, 0x710(r31)
/* 800F9F60 000F6EC0  38 60 00 14 */	li r3, 0x14
/* 800F9F64 000F6EC4  C0 02 9C 60 */	lfs f0, lbl_803E9E60@sda21(r2)
/* 800F9F68 000F6EC8  D0 1F 0A D8 */	stfs f0, 0xad8(r31)
/* 800F9F6C 000F6ECC  93 9F 09 2C */	stw r28, 0x92c(r31)
/* 800F9F70 000F6ED0  98 1F 0A CC */	stb r0, 0xacc(r31)
/* 800F9F74 000F6ED4  90 1F 0A D0 */	stw r0, 0xad0(r31)
/* 800F9F78 000F6ED8  D0 1F 07 38 */	stfs f0, 0x738(r31)
/* 800F9F7C 000F6EDC  98 1F 07 18 */	stb r0, 0x718(r31)
/* 800F9F80 000F6EE0  90 1F 07 20 */	stw r0, 0x720(r31)
/* 800F9F84 000F6EE4  90 1F 07 1C */	stw r0, 0x71c(r31)
/* 800F9F88 000F6EE8  90 1F 0A DC */	stw r0, 0xadc(r31)
/* 800F9F8C 000F6EEC  80 1F 09 2C */	lwz r0, 0x92c(r31)
/* 800F9F90 000F6EF0  80 8D 31 20 */	lwz r4, naviMgr@sda21(r13)
/* 800F9F94 000F6EF4  54 00 10 3A */	slwi r0, r0, 2
/* 800F9F98 000F6EF8  7C 84 02 14 */	add r4, r4, r0
/* 800F9F9C 000F6EFC  80 04 00 48 */	lwz r0, 0x48(r4)
/* 800F9FA0 000F6F00  90 1F 08 2C */	stw r0, 0x82c(r31)
/* 800F9FA4 000F6F04  4B F4 D0 61 */	bl alloc__6SystemFUl
/* 800F9FA8 000F6F08  3B 43 00 00 */	addi r26, r3, 0
/* 800F9FAC 000F6F0C  7F 43 D3 79 */	or. r3, r26, r26
/* 800F9FB0 000F6F10  41 82 00 0C */	beq lbl_800F9FBC
/* 800F9FB4 000F6F14  38 80 00 05 */	li r4, 5
/* 800F9FB8 000F6F18  4B F8 EC 79 */	bl __ct__8CollInfoFi
lbl_800F9FBC:
/* 800F9FBC 000F6F1C  93 5F 02 20 */	stw r26, 0x220(r31)
/* 800F9FC0 000F6F20  38 A0 00 00 */	li r5, 0
/* 800F9FC4 000F6F24  38 C0 00 00 */	li r6, 0
/* 800F9FC8 000F6F28  80 9F 08 2C */	lwz r4, 0x82c(r31)
/* 800F9FCC 000F6F2C  80 7F 02 20 */	lwz r3, 0x220(r31)
/* 800F9FD0 000F6F30  80 84 00 00 */	lwz r4, 0(r4)
/* 800F9FD4 000F6F34  4B F8 FB 91 */	bl initInfo__8CollInfoFP5ShapeP8CollPartPUl
/* 800F9FD8 000F6F38  81 1F 08 2C */	lwz r8, 0x82c(r31)
/* 800F9FDC 000F6F3C  38 7F 08 34 */	addi r3, r31, 0x834
/* 800F9FE0 000F6F40  80 CD 31 20 */	lwz r6, naviMgr@sda21(r13)
/* 800F9FE4 000F6F44  80 88 00 24 */	lwz r4, 0x24(r8)
/* 800F9FE8 000F6F48  38 A8 00 14 */	addi r5, r8, 0x14
/* 800F9FEC 000F6F4C  80 E6 00 50 */	lwz r7, 0x50(r6)
/* 800F9FF0 000F6F50  38 C8 00 04 */	addi r6, r8, 4
/* 800F9FF4 000F6F54  48 02 58 E9 */	bl init__15PaniPikiAnimMgrFP7AnimMgrP11AnimContextP11AnimContextP15PaniMotionTable
/* 800F9FF8 000F6F58  38 00 00 00 */	li r0, 0
/* 800F9FFC 000F6F5C  90 1F 0A BC */	stw r0, 0xabc(r31)
/* 800FA000 000F6F60  28 1F 00 00 */	cmplwi r31, 0
/* 800FA004 000F6F64  3B 5F 00 00 */	addi r26, r31, 0
/* 800FA008 000F6F68  C0 22 9C 60 */	lfs f1, lbl_803E9E60@sda21(r2)
/* 800FA00C 000F6F6C  D0 3F 0A B8 */	stfs f1, 0xab8(r31)
/* 800FA010 000F6F70  D0 3F 0A C4 */	stfs f1, 0xac4(r31)
/* 800FA014 000F6F74  C0 1D 03 C8 */	lfs f0, 0x3c8(r29)
/* 800FA018 000F6F78  D0 1F 00 58 */	stfs f0, 0x58(r31)
/* 800FA01C 000F6F7C  C0 0D D3 98 */	lfs f0, lbl_803E20B8@sda21(r13)
/* 800FA020 000F6F80  D0 1F 07 90 */	stfs f0, 0x790(r31)
/* 800FA024 000F6F84  C0 0D D3 9C */	lfs f0, lbl_803E20BC@sda21(r13)
/* 800FA028 000F6F88  D0 1F 07 94 */	stfs f0, 0x794(r31)
/* 800FA02C 000F6F8C  C0 0D D3 A0 */	lfs f0, lbl_803E20C0@sda21(r13)
/* 800FA030 000F6F90  D0 1F 07 98 */	stfs f0, 0x798(r31)
/* 800FA034 000F6F94  D0 3F 08 14 */	stfs f1, 0x814(r31)
/* 800FA038 000F6F98  C0 02 9C 78 */	lfs f0, lbl_803E9E78@sda21(r2)
/* 800FA03C 000F6F9C  D0 1F 08 18 */	stfs f0, 0x818(r31)
/* 800FA040 000F6FA0  90 1F 08 10 */	stw r0, 0x810(r31)
/* 800FA044 000F6FA4  90 1F 08 0C */	stw r0, 0x80c(r31)
/* 800FA048 000F6FA8  41 82 00 08 */	beq lbl_800FA050
/* 800FA04C 000F6FAC  3B 5A 02 B8 */	addi r26, r26, 0x2b8
lbl_800FA050:
/* 800FA050 000F6FB0  38 61 00 18 */	addi r3, r1, 0x18
/* 800FA054 000F6FB4  38 80 00 02 */	li r4, 2
/* 800FA058 000F6FB8  48 02 4F 01 */	bl __ct__14PaniMotionInfoFi
/* 800FA05C 000F6FBC  3B 63 00 00 */	addi r27, r3, 0
/* 800FA060 000F6FC0  38 BA 00 00 */	addi r5, r26, 0
/* 800FA064 000F6FC4  38 61 00 20 */	addi r3, r1, 0x20
/* 800FA068 000F6FC8  38 80 00 02 */	li r4, 2
/* 800FA06C 000F6FCC  48 02 4F 21 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800FA070 000F6FD0  38 83 00 00 */	addi r4, r3, 0
/* 800FA074 000F6FD4  38 7F 00 00 */	addi r3, r31, 0
/* 800FA078 000F6FD8  38 BB 00 00 */	addi r5, r27, 0
/* 800FA07C 000F6FDC  48 00 07 F5 */	bl startMotion__4NaviFR14PaniMotionInfoR14PaniMotionInfo
/* 800FA080 000F6FE0  C0 02 9C 78 */	lfs f0, lbl_803E9E78@sda21(r2)
/* 800FA084 000F6FE4  38 60 00 60 */	li r3, 0x60
/* 800FA088 000F6FE8  D0 1F 00 7C */	stfs f0, 0x7c(r31)
/* 800FA08C 000F6FEC  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 800FA090 000F6FF0  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 800FA094 000F6FF4  C0 0D D3 A4 */	lfs f0, lbl_803E20C4@sda21(r13)
/* 800FA098 000F6FF8  D0 1F 00 88 */	stfs f0, 0x88(r31)
/* 800FA09C 000F6FFC  C0 0D D3 A8 */	lfs f0, lbl_803E20C8@sda21(r13)
/* 800FA0A0 000F7000  D0 1F 00 8C */	stfs f0, 0x8c(r31)
/* 800FA0A4 000F7004  C0 0D D3 AC */	lfs f0, lbl_803E20CC@sda21(r13)
/* 800FA0A8 000F7008  D0 1F 00 90 */	stfs f0, 0x90(r31)
/* 800FA0AC 000F700C  C0 0D D3 B0 */	lfs f0, lbl_803E20D0@sda21(r13)
/* 800FA0B0 000F7010  D0 1F 00 94 */	stfs f0, 0x94(r31)
/* 800FA0B4 000F7014  C0 0D D3 B4 */	lfs f0, lbl_803E20D4@sda21(r13)
/* 800FA0B8 000F7018  D0 1F 00 98 */	stfs f0, 0x98(r31)
/* 800FA0BC 000F701C  C0 0D D3 B8 */	lfs f0, lbl_803E20D8@sda21(r13)
/* 800FA0C0 000F7020  D0 1F 00 9C */	stfs f0, 0x9c(r31)
/* 800FA0C4 000F7024  C0 0D D3 BC */	lfs f0, lbl_803E20DC@sda21(r13)
/* 800FA0C8 000F7028  D0 1F 00 70 */	stfs f0, 0x70(r31)
/* 800FA0CC 000F702C  C0 0D D3 C0 */	lfs f0, lbl_803E20E0@sda21(r13)
/* 800FA0D0 000F7030  D0 1F 00 74 */	stfs f0, 0x74(r31)
/* 800FA0D4 000F7034  C0 0D D3 C4 */	lfs f0, lbl_803E20E4@sda21(r13)
/* 800FA0D8 000F7038  D0 1F 00 78 */	stfs f0, 0x78(r31)
/* 800FA0DC 000F703C  C0 0D D3 C8 */	lfs f0, lbl_803E20E8@sda21(r13)
/* 800FA0E0 000F7040  D0 1F 00 A4 */	stfs f0, 0xa4(r31)
/* 800FA0E4 000F7044  C0 0D D3 CC */	lfs f0, lbl_803E20EC@sda21(r13)
/* 800FA0E8 000F7048  D0 1F 00 A8 */	stfs f0, 0xa8(r31)
/* 800FA0EC 000F704C  C0 0D D3 D0 */	lfs f0, lbl_803E20F0@sda21(r13)
/* 800FA0F0 000F7050  D0 1F 00 AC */	stfs f0, 0xac(r31)
/* 800FA0F4 000F7054  C0 02 9C 60 */	lfs f0, lbl_803E9E60@sda21(r2)
/* 800FA0F8 000F7058  D0 1F 02 68 */	stfs f0, 0x268(r31)
/* 800FA0FC 000F705C  4B F4 CF 09 */	bl alloc__6SystemFUl
/* 800FA100 000F7060  3B 43 00 00 */	addi r26, r3, 0
/* 800FA104 000F7064  7F 43 D3 79 */	or. r3, r26, r26
/* 800FA108 000F7068  41 82 00 0C */	beq lbl_800FA114
/* 800FA10C 000F706C  38 9C 00 01 */	addi r4, r28, 1
/* 800FA110 000F7070  48 01 BA 7D */	bl __ct__10KontrollerFi
lbl_800FA114:
/* 800FA114 000F7074  93 5F 02 E4 */	stw r26, 0x2e4(r31)
/* 800FA118 000F7078  38 9E 00 34 */	addi r4, r30, 0x34
/* 800FA11C 000F707C  C0 02 9D 20 */	lfs f0, lbl_803E9F20@sda21(r2)
/* 800FA120 000F7080  D0 1F 02 6C */	stfs f0, 0x26c(r31)
/* 800FA124 000F7084  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 800FA128 000F7088  4B F8 C6 11 */	bl start__7MemStatFPc
/* 800FA12C 000F708C  38 60 00 1C */	li r3, 0x1c
/* 800FA130 000F7090  4B F4 CE D5 */	bl alloc__6SystemFUl
/* 800FA134 000F7094  28 03 00 00 */	cmplwi r3, 0
/* 800FA138 000F7098  41 82 00 24 */	beq lbl_800FA15C
/* 800FA13C 000F709C  3C 80 80 2C */	lis r4, "__vt__19StateMachine<4Navi>"@ha
/* 800FA140 000F70A0  38 04 01 E0 */	addi r0, r4, "__vt__19StateMachine<4Navi>"@l
/* 800FA144 000F70A4  90 03 00 00 */	stw r0, 0(r3)
/* 800FA148 000F70A8  38 00 FF FF */	li r0, -1
/* 800FA14C 000F70AC  3C 80 80 2C */	lis r4, __vt__16NaviStateMachine@ha
/* 800FA150 000F70B0  90 03 00 18 */	stw r0, 0x18(r3)
/* 800FA154 000F70B4  38 04 1A 64 */	addi r0, r4, __vt__16NaviStateMachine@l
/* 800FA158 000F70B8  90 03 00 00 */	stw r0, 0(r3)
lbl_800FA15C:
/* 800FA15C 000F70BC  90 7F 03 20 */	stw r3, 0x320(r31)
/* 800FA160 000F70C0  7F E4 FB 78 */	mr r4, r31
/* 800FA164 000F70C4  80 7F 03 20 */	lwz r3, 0x320(r31)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x6169476f
	.4byte 0x746f2e63
	.4byte 0x70700000
	.4byte 0x52656365
	.4byte 0x69766572
	.4byte 0x3c50696b
	.4byte 0x693e0000
	.4byte 0x803E04d0
	.4byte 0
	.4byte 0
	.4byte 0x803E04d0
	.4byte 0
	.4byte 0x803E04e0
	.4byte 0
	.4byte 0
.global __vt__7ActGoto
__vt__7ActGoto:
	.4byte __RTTI__7ActGoto
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
	.4byte defaultInitialiser__7ActGotoFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__7ActGotoFv
	.4byte init__7ActGotoFP8Creature
	.4byte exec__7ActGotoFv
	.4byte cleanup__7ActGotoFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
	.4byte 0x41637447
	.4byte 0x6f746f3a
	.4byte 0x3a496e69
	.4byte 0x7469616c
	.4byte 0x69736572
	.4byte 0
	.4byte 0x41637469
	.4byte 0x6f6e3a3a
	.4byte 0x496e6974
	.4byte 0x69616c69
	.4byte 0x73657200
	.4byte 0x803E04f0
	.4byte 0
	.4byte 0
.global __vt__Q27ActGoto11Initialiser
__vt__Q27ActGoto11Initialiser:
	.4byte __RTTI__Q27ActGoto11Initialiser
	.4byte 0
	.4byte initialise__Q27ActGoto11InitialiserFP6Action
	.4byte lbl_800A7908
	.4byte lbl_800A7930
	.4byte lbl_800A7944
	.4byte lbl_800A7958
	.4byte lbl_800A796C
	.4byte lbl_800A7980
	.4byte lbl_800A7994
	.4byte lbl_800A79A8
	.4byte lbl_800A791C
	.4byte lbl_800A79D0
	.4byte lbl_800A79BC

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x72656500
	.4byte 0x802B6A7C
	.4byte 0x00000000
	.4byte 0x802B6A90
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E049C
	.4byte 0x802B6AA0
.global __RTTI__7ActFree
__RTTI__7ActFree:
	.4byte 0x803E0484
	.4byte 0x802b6aac
	.4byte 0
.global lbl_803E04B8
lbl_803E04B8:
	.4byte 0x00000000
.global lbl_803E04BC
lbl_803E04BC:
	.4byte 0x00000000
.global lbl_803E04C0
lbl_803E04C0:
	.4byte 0x00000000
.global lbl_803E04C4
lbl_803E04C4:
	.4byte 0x00000000
	.4byte 0x41637447
	.4byte 0x6F746F00

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EAB34
lbl_803EAB34:
	.4byte 0x3F800000
.global lbl_803EAB38
lbl_803EAB38:
	.4byte 0x46FFFE00
.global lbl_803EAB3C
lbl_803EAB3C:
	.4byte 0x3F7FFFEF
.global "@2018"
"@2018":
	.4byte 0x43300000
	.4byte 0x80000000
.global lbl_803EAB48
lbl_803EAB48:
	.4byte 0x3FFFFFEF
.global lbl_803EAB4C
lbl_803EAB4C:
	.4byte 0x41F00000
.global lbl_803EAB50
lbl_803EAB50:
	.4byte 0x40490FCE
.global lbl_803EAB54
lbl_803EAB54:
	.4byte 0x3FC90FDB
.global lbl_803EAB58
lbl_803EAB58:
	.4byte 0x40000000
.global lbl_803EAB5C
lbl_803EAB5C:
	.4byte 0x40400000
.global lbl_803EAB60
lbl_803EAB60:
	.4byte 0x3E4CCCCD
.global lbl_803EAB64
lbl_803EAB64:
	.4byte 0x3F000000
.global lbl_803EAB68
lbl_803EAB68:
	.4byte 0x3FC00000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EC20C
lbl_803EC20C:
	.4byte 0x40800000
.global lbl_803EC210
lbl_803EC210:
	.4byte 0x3F800000
.global lbl_803EC214
lbl_803EC214:
	.4byte 0x3F59999A
.global lbl_803EC218
lbl_803EC218:
	.4byte 0x42700000
.global lbl_803EC21C
lbl_803EC21C:
	.4byte 0x3E860A92
.global lbl_803EC220
lbl_803EC220:
	.4byte 0x43700000
.global lbl_803EC224
lbl_803EC224:
	.4byte 0x41F00000
.global lbl_803EC228
lbl_803EC228:
	.4byte 0x3F800000
.global lbl_803EC22C
lbl_803EC22C:
	.4byte 0x459C4000
.global "@880"
"@880":
	.4byte 0x43300000
	.4byte 0x80000000
.global lbl_803EC238
lbl_803EC238:
	.4byte 0x42FE0000
.global lbl_803EC23C
lbl_803EC23C:
	.4byte 0x00000000
.global lbl_803EC240
lbl_803EC240:
	.4byte 0x3F000000
