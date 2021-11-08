.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800BBA30 000B8990  C0 63 00 78 */	lfs f3, 0x78(r3)
/* 800BBA34 000B8994  C0 43 00 74 */	lfs f2, 0x74(r3)
/* 800BBA38 000B8998  EC 00 40 2A */	fadds f0, f0, f8
/* 800BBA3C 000B899C  EC 63 20 2A */	fadds f3, f3, f4
/* 800BBA40 000B89A0  EC 42 38 2A */	fadds f2, f2, f7
/* 800BBA44 000B89A4  D0 01 01 84 */	stfs f0, 0x184(r1)
/* 800BBA48 000B89A8  C0 01 01 84 */	lfs f0, 0x184(r1)
/* 800BBA4C 000B89AC  D0 01 02 18 */	stfs f0, 0x218(r1)
/* 800BBA50 000B89B0  D0 41 02 1C */	stfs f2, 0x21c(r1)
/* 800BBA54 000B89B4  D0 61 02 20 */	stfs f3, 0x220(r1)
/* 800BBA58 000B89B8  C0 41 02 18 */	lfs f2, 0x218(r1)
/* 800BBA5C 000B89BC  C0 01 02 0C */	lfs f0, 0x20c(r1)
/* 800BBA60 000B89C0  EC 02 00 28 */	fsubs f0, f2, f0
/* 800BBA64 000B89C4  D0 01 01 60 */	stfs f0, 0x160(r1)
/* 800BBA68 000B89C8  C0 01 01 60 */	lfs f0, 0x160(r1)
/* 800BBA6C 000B89CC  D0 01 02 24 */	stfs f0, 0x224(r1)
/* 800BBA70 000B89D0  C0 41 02 1C */	lfs f2, 0x21c(r1)
/* 800BBA74 000B89D4  C0 01 02 10 */	lfs f0, 0x210(r1)
/* 800BBA78 000B89D8  EC 02 00 28 */	fsubs f0, f2, f0
/* 800BBA7C 000B89DC  D0 01 02 28 */	stfs f0, 0x228(r1)
/* 800BBA80 000B89E0  C0 41 02 20 */	lfs f2, 0x220(r1)
/* 800BBA84 000B89E4  C0 01 02 14 */	lfs f0, 0x214(r1)
/* 800BBA88 000B89E8  EC 02 00 28 */	fsubs f0, f2, f0
/* 800BBA8C 000B89EC  D0 01 02 2C */	stfs f0, 0x22c(r1)
/* 800BBA90 000B89F0  80 61 02 24 */	lwz r3, 0x224(r1)
/* 800BBA94 000B89F4  80 01 02 28 */	lwz r0, 0x228(r1)
/* 800BBA98 000B89F8  90 65 00 00 */	stw r3, 0(r5)
/* 800BBA9C 000B89FC  90 05 00 04 */	stw r0, 4(r5)
/* 800BBAA0 000B8A00  80 01 02 2C */	lwz r0, 0x22c(r1)
/* 800BBAA4 000B8A04  90 05 00 08 */	stw r0, 8(r5)
/* 800BBAA8 000B8A08  C0 5E 00 A0 */	lfs f2, 0xa0(r30)
/* 800BBAAC 000B8A0C  4B F7 CB 09 */	bl angDist__Fff
/* 800BBAB0 000B8A10  C0 02 93 60 */	lfs f0, lbl_803E9560@sda21(r2)
/* 800BBAB4 000B8A14  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800BBAB8 000B8A18  40 81 00 44 */	ble lbl_800BBAFC
/* 800BBABC 000B8A1C  C0 02 93 84 */	lfs f0, lbl_803E9584@sda21(r2)
/* 800BBAC0 000B8A20  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800BBAC4 000B8A24  EC 3F 00 28 */	fsubs f1, f31, f0
/* 800BBAC8 000B8A28  C3 C3 02 8C */	lfs f30, 0x28c(r3)
/* 800BBACC 000B8A2C  4B F7 CA BD */	bl roundAng__Ff
/* 800BBAD0 000B8A30  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BBAD4 000B8A34  C0 43 00 A0 */	lfs f2, 0xa0(r3)
/* 800BBAD8 000B8A38  4B F7 CA DD */	bl angDist__Fff
/* 800BBADC 000B8A3C  EC 21 07 B2 */	fmuls f1, f1, f30
/* 800BBAE0 000B8A40  C0 02 93 88 */	lfs f0, lbl_803E9588@sda21(r2)
/* 800BBAE4 000B8A44  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BBAE8 000B8A48  EC 21 00 24 */	fdivs f1, f1, f0
/* 800BBAEC 000B8A4C  C0 03 00 A0 */	lfs f0, 0xa0(r3)
/* 800BBAF0 000B8A50  EC 00 08 2A */	fadds f0, f0, f1
/* 800BBAF4 000B8A54  D0 03 00 A0 */	stfs f0, 0xa0(r3)
/* 800BBAF8 000B8A58  48 00 00 40 */	b lbl_800BBB38
lbl_800BBAFC:
/* 800BBAFC 000B8A5C  C0 02 93 84 */	lfs f0, lbl_803E9584@sda21(r2)
/* 800BBB00 000B8A60  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800BBB04 000B8A64  EC 20 F8 2A */	fadds f1, f0, f31
/* 800BBB08 000B8A68  C3 C3 02 8C */	lfs f30, 0x28c(r3)
/* 800BBB0C 000B8A6C  4B F7 CA 7D */	bl roundAng__Ff
/* 800BBB10 000B8A70  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BBB14 000B8A74  C0 43 00 A0 */	lfs f2, 0xa0(r3)
/* 800BBB18 000B8A78  4B F7 CA 9D */	bl angDist__Fff
/* 800BBB1C 000B8A7C  EC 21 07 B2 */	fmuls f1, f1, f30
/* 800BBB20 000B8A80  C0 02 93 88 */	lfs f0, lbl_803E9588@sda21(r2)
/* 800BBB24 000B8A84  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BBB28 000B8A88  EC 21 00 24 */	fdivs f1, f1, f0
/* 800BBB2C 000B8A8C  C0 03 00 A0 */	lfs f0, 0xa0(r3)
/* 800BBB30 000B8A90  EC 00 08 2A */	fadds f0, f0, f1
/* 800BBB34 000B8A94  D0 03 00 A0 */	stfs f0, 0xa0(r3)
lbl_800BBB38:
/* 800BBB38 000B8A98  80 9F 00 1C */	lwz r4, 0x1c(r31)
/* 800BBB3C 000B8A9C  28 04 00 00 */	cmplwi r4, 0
/* 800BBB40 000B8AA0  41 82 02 48 */	beq lbl_800BBD88
/* 800BBB44 000B8AA4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BBB48 000B8AA8  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 800BBB4C 000B8AAC  C0 24 00 94 */	lfs f1, 0x94(r4)
/* 800BBB50 000B8AB0  C0 64 00 98 */	lfs f3, 0x98(r4)
/* 800BBB54 000B8AB4  C0 43 00 04 */	lfs f2, 4(r3)
/* 800BBB58 000B8AB8  EC 01 00 28 */	fsubs f0, f1, f0
/* 800BBB5C 000B8ABC  C0 84 00 9C */	lfs f4, 0x9c(r4)
/* 800BBB60 000B8AC0  C0 23 00 08 */	lfs f1, 8(r3)
/* 800BBB64 000B8AC4  EC 43 10 28 */	fsubs f2, f3, f2
/* 800BBB68 000B8AC8  D0 01 02 78 */	stfs f0, 0x278(r1)
/* 800BBB6C 000B8ACC  EC 04 08 28 */	fsubs f0, f4, f1
/* 800BBB70 000B8AD0  D0 41 02 7C */	stfs f2, 0x27c(r1)
/* 800BBB74 000B8AD4  D0 01 02 80 */	stfs f0, 0x280(r1)
/* 800BBB78 000B8AD8  C0 21 02 78 */	lfs f1, 0x278(r1)
/* 800BBB7C 000B8ADC  C0 61 02 80 */	lfs f3, 0x280(r1)
/* 800BBB80 000B8AE0  C0 01 02 7C */	lfs f0, 0x27c(r1)
/* 800BBB84 000B8AE4  EC 41 00 72 */	fmuls f2, f1, f1
/* 800BBB88 000B8AE8  EC 63 00 F2 */	fmuls f3, f3, f3
/* 800BBB8C 000B8AEC  EC 20 00 32 */	fmuls f1, f0, f0
/* 800BBB90 000B8AF0  C0 02 93 60 */	lfs f0, lbl_803E9560@sda21(r2)
/* 800BBB94 000B8AF4  EC 22 08 2A */	fadds f1, f2, f1
/* 800BBB98 000B8AF8  EC A3 08 2A */	fadds f5, f3, f1
/* 800BBB9C 000B8AFC  FC 05 00 40 */	fcmpo cr0, f5, f0
/* 800BBBA0 000B8B00  40 81 00 5C */	ble lbl_800BBBFC
/* 800BBBA4 000B8B04  FC 20 28 34 */	frsqrte f1, f5
/* 800BBBA8 000B8B08  C8 62 93 70 */	lfd f3, "@1867"@sda21(r2)
/* 800BBBAC 000B8B0C  C8 42 93 78 */	lfd f2, "@1868"@sda21(r2)
/* 800BBBB0 000B8B10  FC 01 00 72 */	fmul f0, f1, f1
/* 800BBBB4 000B8B14  FC 23 00 72 */	fmul f1, f3, f1
/* 800BBBB8 000B8B18  FC 05 00 32 */	fmul f0, f5, f0
/* 800BBBBC 000B8B1C  FC 02 00 28 */	fsub f0, f2, f0
/* 800BBBC0 000B8B20  FC 21 00 32 */	fmul f1, f1, f0
/* 800BBBC4 000B8B24  FC 01 00 72 */	fmul f0, f1, f1
/* 800BBBC8 000B8B28  FC 23 00 72 */	fmul f1, f3, f1
/* 800BBBCC 000B8B2C  FC 05 00 32 */	fmul f0, f5, f0
/* 800BBBD0 000B8B30  FC 02 00 28 */	fsub f0, f2, f0
/* 800BBBD4 000B8B34  FC 21 00 32 */	fmul f1, f1, f0
/* 800BBBD8 000B8B38  FC 01 00 72 */	fmul f0, f1, f1
/* 800BBBDC 000B8B3C  FC 23 00 72 */	fmul f1, f3, f1
/* 800BBBE0 000B8B40  FC 05 00 32 */	fmul f0, f5, f0
/* 800BBBE4 000B8B44  FC 02 00 28 */	fsub f0, f2, f0
/* 800BBBE8 000B8B48  FC 01 00 32 */	fmul f0, f1, f0
/* 800BBBEC 000B8B4C  FC 05 00 32 */	fmul f0, f5, f0
/* 800BBBF0 000B8B50  FC 00 00 18 */	frsp f0, f0
/* 800BBBF4 000B8B54  D0 01 01 1C */	stfs f0, 0x11c(r1)
/* 800BBBF8 000B8B58  C0 A1 01 1C */	lfs f5, 0x11c(r1)
lbl_800BBBFC:
/* 800BBBFC 000B8B5C  C0 22 93 80 */	lfs f1, lbl_803E9580@sda21(r2)
/* 800BBC00 000B8B60  38 61 01 CC */	addi r3, r1, 0x1cc
/* 800BBC04 000B8B64  C0 01 02 78 */	lfs f0, 0x278(r1)
/* 800BBC08 000B8B68  38 81 02 78 */	addi r4, r1, 0x278
/* 800BBC0C 000B8B6C  EC 61 28 24 */	fdivs f3, f1, f5
/* 800BBC10 000B8B70  C0 21 02 7C */	lfs f1, 0x27c(r1)
/* 800BBC14 000B8B74  38 A1 01 C8 */	addi r5, r1, 0x1c8
/* 800BBC18 000B8B78  C0 41 02 80 */	lfs f2, 0x280(r1)
/* 800BBC1C 000B8B7C  EC 00 00 F2 */	fmuls f0, f0, f3
/* 800BBC20 000B8B80  EC 81 00 F2 */	fmuls f4, f1, f3
/* 800BBC24 000B8B84  EC 22 00 F2 */	fmuls f1, f2, f3
/* 800BBC28 000B8B88  D0 01 02 78 */	stfs f0, 0x278(r1)
/* 800BBC2C 000B8B8C  D0 81 02 7C */	stfs f4, 0x27c(r1)
/* 800BBC30 000B8B90  D0 21 02 80 */	stfs f1, 0x280(r1)
/* 800BBC34 000B8B94  C0 1F 00 3C */	lfs f0, 0x3c(r31)
/* 800BBC38 000B8B98  80 CD 2D EC */	lwz r6, gsys@sda21(r13)
/* 800BBC3C 000B8B9C  EC 05 00 28 */	fsubs f0, f5, f0
/* 800BBC40 000B8BA0  C3 C6 02 8C */	lfs f30, 0x28c(r6)
/* 800BBC44 000B8BA4  D0 01 01 C8 */	stfs f0, 0x1c8(r1)
/* 800BBC48 000B8BA8  4B FE 38 8D */	bl __ml__FRC8Vector3fRCf
/* 800BBC4C 000B8BAC  C0 41 01 D4 */	lfs f2, 0x1d4(r1)
/* 800BBC50 000B8BB0  38 C1 01 0C */	addi r6, r1, 0x10c
/* 800BBC54 000B8BB4  C0 21 01 D0 */	lfs f1, 0x1d0(r1)
/* 800BBC58 000B8BB8  38 A1 01 08 */	addi r5, r1, 0x108
/* 800BBC5C 000B8BBC  C0 01 01 CC */	lfs f0, 0x1cc(r1)
/* 800BBC60 000B8BC0  EC 42 07 B2 */	fmuls f2, f2, f30
/* 800BBC64 000B8BC4  38 81 01 04 */	addi r4, r1, 0x104
/* 800BBC68 000B8BC8  EC 21 07 B2 */	fmuls f1, f1, f30
/* 800BBC6C 000B8BCC  38 61 01 D8 */	addi r3, r1, 0x1d8
/* 800BBC70 000B8BD0  EC 00 07 B2 */	fmuls f0, f0, f30
/* 800BBC74 000B8BD4  D0 41 01 0C */	stfs f2, 0x10c(r1)
/* 800BBC78 000B8BD8  D0 21 01 08 */	stfs f1, 0x108(r1)
/* 800BBC7C 000B8BDC  D0 01 01 04 */	stfs f0, 0x104(r1)
/* 800BBC80 000B8BE0  4B F7 B4 9D */	bl __ct__8Vector3fFRCfRCfRCf
/* 800BBC84 000B8BE4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BBC88 000B8BE8  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 800BBC8C 000B8BEC  C0 03 00 70 */	lfs f0, 0x70(r3)
/* 800BBC90 000B8BF0  38 A3 00 70 */	addi r5, r3, 0x70
/* 800BBC94 000B8BF4  C0 A4 02 8C */	lfs f5, 0x28c(r4)
/* 800BBC98 000B8BF8  C0 43 00 78 */	lfs f2, 0x78(r3)
/* 800BBC9C 000B8BFC  EC 00 01 72 */	fmuls f0, f0, f5
/* 800BBCA0 000B8C00  C0 23 00 74 */	lfs f1, 0x74(r3)
/* 800BBCA4 000B8C04  EC 82 01 72 */	fmuls f4, f2, f5
/* 800BBCA8 000B8C08  C0 61 01 E0 */	lfs f3, 0x1e0(r1)
/* 800BBCAC 000B8C0C  EC A1 01 72 */	fmuls f5, f1, f5
/* 800BBCB0 000B8C10  D0 01 01 44 */	stfs f0, 0x144(r1)
/* 800BBCB4 000B8C14  C0 ED B7 F4 */	lfs f7, lbl_803E0514@sda21(r13)
/* 800BBCB8 000B8C18  C0 01 01 44 */	lfs f0, 0x144(r1)
/* 800BBCBC 000B8C1C  C0 21 01 D8 */	lfs f1, 0x1d8(r1)
/* 800BBCC0 000B8C20  EC 63 01 F2 */	fmuls f3, f3, f7
/* 800BBCC4 000B8C24  C0 41 01 DC */	lfs f2, 0x1dc(r1)
/* 800BBCC8 000B8C28  D0 01 01 94 */	stfs f0, 0x194(r1)
/* 800BBCCC 000B8C2C  EC C1 01 F2 */	fmuls f6, f1, f7
/* 800BBCD0 000B8C30  D0 A1 01 98 */	stfs f5, 0x198(r1)
/* 800BBCD4 000B8C34  EC A2 01 F2 */	fmuls f5, f2, f7
/* 800BBCD8 000B8C38  D0 81 01 9C */	stfs f4, 0x19c(r1)
/* 800BBCDC 000B8C3C  C0 01 01 94 */	lfs f0, 0x194(r1)
/* 800BBCE0 000B8C40  C0 2D B7 F8 */	lfs f1, lbl_803E0518@sda21(r13)
/* 800BBCE4 000B8C44  EC 00 00 72 */	fmuls f0, f0, f1
/* 800BBCE8 000B8C48  D0 01 01 38 */	stfs f0, 0x138(r1)
/* 800BBCEC 000B8C4C  C0 01 01 38 */	lfs f0, 0x138(r1)
/* 800BBCF0 000B8C50  D0 01 01 A0 */	stfs f0, 0x1a0(r1)
/* 800BBCF4 000B8C54  C0 01 01 98 */	lfs f0, 0x198(r1)
/* 800BBCF8 000B8C58  EC 00 00 72 */	fmuls f0, f0, f1
/* 800BBCFC 000B8C5C  D0 01 01 A4 */	stfs f0, 0x1a4(r1)
/* 800BBD00 000B8C60  C0 01 01 9C */	lfs f0, 0x19c(r1)
/* 800BBD04 000B8C64  EC 00 00 72 */	fmuls f0, f0, f1
/* 800BBD08 000B8C68  D0 01 01 A8 */	stfs f0, 0x1a8(r1)
/* 800BBD0C 000B8C6C  C0 03 00 70 */	lfs f0, 0x70(r3)
/* 800BBD10 000B8C70  C0 43 00 78 */	lfs f2, 0x78(r3)
/* 800BBD14 000B8C74  C0 23 00 74 */	lfs f1, 0x74(r3)
/* 800BBD18 000B8C78  EC 00 30 2A */	fadds f0, f0, f6
/* 800BBD1C 000B8C7C  EC 42 18 2A */	fadds f2, f2, f3
/* 800BBD20 000B8C80  EC 21 28 2A */	fadds f1, f1, f5
/* 800BBD24 000B8C84  D0 01 01 50 */	stfs f0, 0x150(r1)
/* 800BBD28 000B8C88  C0 01 01 50 */	lfs f0, 0x150(r1)
/* 800BBD2C 000B8C8C  D0 01 01 AC */	stfs f0, 0x1ac(r1)
/* 800BBD30 000B8C90  D0 21 01 B0 */	stfs f1, 0x1b0(r1)
/* 800BBD34 000B8C94  D0 41 01 B4 */	stfs f2, 0x1b4(r1)
/* 800BBD38 000B8C98  C0 21 01 AC */	lfs f1, 0x1ac(r1)
/* 800BBD3C 000B8C9C  C0 01 01 A0 */	lfs f0, 0x1a0(r1)
/* 800BBD40 000B8CA0  EC 01 00 28 */	fsubs f0, f1, f0
/* 800BBD44 000B8CA4  D0 01 01 2C */	stfs f0, 0x12c(r1)
/* 800BBD48 000B8CA8  C0 01 01 2C */	lfs f0, 0x12c(r1)
/* 800BBD4C 000B8CAC  D0 01 01 B8 */	stfs f0, 0x1b8(r1)
/* 800BBD50 000B8CB0  C0 21 01 B0 */	lfs f1, 0x1b0(r1)
/* 800BBD54 000B8CB4  C0 01 01 A4 */	lfs f0, 0x1a4(r1)
/* 800BBD58 000B8CB8  EC 01 00 28 */	fsubs f0, f1, f0
/* 800BBD5C 000B8CBC  D0 01 01 BC */	stfs f0, 0x1bc(r1)
/* 800BBD60 000B8CC0  C0 21 01 B4 */	lfs f1, 0x1b4(r1)
/* 800BBD64 000B8CC4  C0 01 01 A8 */	lfs f0, 0x1a8(r1)
/* 800BBD68 000B8CC8  EC 01 00 28 */	fsubs f0, f1, f0
/* 800BBD6C 000B8CCC  D0 01 01 C0 */	stfs f0, 0x1c0(r1)
/* 800BBD70 000B8CD0  80 61 01 B8 */	lwz r3, 0x1b8(r1)
/* 800BBD74 000B8CD4  80 01 01 BC */	lwz r0, 0x1bc(r1)
/* 800BBD78 000B8CD8  90 65 00 00 */	stw r3, 0(r5)
/* 800BBD7C 000B8CDC  90 05 00 04 */	stw r0, 4(r5)
/* 800BBD80 000B8CE0  80 01 01 C0 */	lwz r0, 0x1c0(r1)
/* 800BBD84 000B8CE4  90 05 00 08 */	stw r0, 8(r5)
lbl_800BBD88:
/* 800BBD88 000B8CE8  38 60 00 00 */	li r3, 0
/* 800BBD8C 000B8CEC  48 00 01 14 */	b lbl_800BBEA0
lbl_800BBD90:
/* 800BBD90 000B8CF0  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 800BBD94 000B8CF4  28 00 00 00 */	cmplwi r0, 0
/* 800BBD98 000B8CF8  40 82 00 0C */	bne lbl_800BBDA4
/* 800BBD9C 000B8CFC  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 800BBDA0 000B8D00  28 00 00 00 */	cmplwi r0, 0
lbl_800BBDA4:
/* 800BBDA4 000B8D04  7F E3 FB 78 */	mr r3, r31
/* 800BBDA8 000B8D08  48 00 06 61 */	bl setGoal__8ActGuardFv
/* 800BBDAC 000B8D0C  80 1F 00 44 */	lwz r0, 0x44(r31)
/* 800BBDB0 000B8D10  2C 00 00 01 */	cmpwi r0, 1
/* 800BBDB4 000B8D14  40 82 00 10 */	bne lbl_800BBDC4
/* 800BBDB8 000B8D18  7F E3 FB 78 */	mr r3, r31
/* 800BBDBC 000B8D1C  48 00 0B 19 */	bl setRight__8ActGuardFv
/* 800BBDC0 000B8D20  48 00 00 0C */	b lbl_800BBDCC
lbl_800BBDC4:
/* 800BBDC4 000B8D24  7F E3 FB 78 */	mr r3, r31
/* 800BBDC8 000B8D28  48 00 09 49 */	bl setLeft__8ActGuardFv
lbl_800BBDCC:
/* 800BBDCC 000B8D2C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BBDD0 000B8D30  41 82 00 98 */	beq lbl_800BBE68
/* 800BBDD4 000B8D34  38 60 00 01 */	li r3, 1
/* 800BBDD8 000B8D38  98 7F 00 48 */	stb r3, 0x48(r31)
/* 800BBDDC 000B8D3C  C0 02 93 64 */	lfs f0, lbl_803E9564@sda21(r2)
/* 800BBDE0 000B8D40  D0 1F 00 3C */	stfs f0, 0x3c(r31)
/* 800BBDE4 000B8D44  80 1F 00 44 */	lwz r0, 0x44(r31)
/* 800BBDE8 000B8D48  2C 00 00 01 */	cmpwi r0, 1
/* 800BBDEC 000B8D4C  40 82 00 10 */	bne lbl_800BBDFC
/* 800BBDF0 000B8D50  38 00 00 00 */	li r0, 0
/* 800BBDF4 000B8D54  90 1F 00 44 */	stw r0, 0x44(r31)
/* 800BBDF8 000B8D58  48 00 00 08 */	b lbl_800BBE00
lbl_800BBDFC:
/* 800BBDFC 000B8D5C  90 7F 00 44 */	stw r3, 0x44(r31)
lbl_800BBE00:
/* 800BBE00 000B8D60  7F E3 FB 78 */	mr r3, r31
/* 800BBE04 000B8D64  80 9F 00 44 */	lwz r4, 0x44(r31)
/* 800BBE08 000B8D68  48 00 03 A9 */	bl findFriend__8ActGuardFi
/* 800BBE0C 000B8D6C  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BBE10 000B8D70  41 82 00 70 */	beq lbl_800BBE80
/* 800BBE14 000B8D74  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 800BBE18 000B8D78  28 03 00 00 */	cmplwi r3, 0
/* 800BBE1C 000B8D7C  41 82 00 14 */	beq lbl_800BBE30
/* 800BBE20 000B8D80  41 82 00 10 */	beq lbl_800BBE30
/* 800BBE24 000B8D84  48 02 85 49 */	bl subCnt__12RefCountableFv
/* 800BBE28 000B8D88  38 00 00 00 */	li r0, 0
/* 800BBE2C 000B8D8C  90 1F 00 14 */	stw r0, 0x14(r31)
lbl_800BBE30:
/* 800BBE30 000B8D90  93 DF 00 14 */	stw r30, 0x14(r31)
/* 800BBE34 000B8D94  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 800BBE38 000B8D98  28 03 00 00 */	cmplwi r3, 0
/* 800BBE3C 000B8D9C  41 82 00 08 */	beq lbl_800BBE44
/* 800BBE40 000B8DA0  48 02 85 1D */	bl addCnt__12RefCountableFv
lbl_800BBE44:
/* 800BBE44 000B8DA4  80 1F 00 44 */	lwz r0, 0x44(r31)
/* 800BBE48 000B8DA8  2C 00 00 01 */	cmpwi r0, 1
/* 800BBE4C 000B8DAC  40 82 00 10 */	bne lbl_800BBE5C
/* 800BBE50 000B8DB0  7F E3 FB 78 */	mr r3, r31
/* 800BBE54 000B8DB4  48 00 0A 81 */	bl setRight__8ActGuardFv
/* 800BBE58 000B8DB8  48 00 00 28 */	b lbl_800BBE80
lbl_800BBE5C:
/* 800BBE5C 000B8DBC  7F E3 FB 78 */	mr r3, r31
/* 800BBE60 000B8DC0  48 00 08 B1 */	bl setLeft__8ActGuardFv
/* 800BBE64 000B8DC4  48 00 00 1C */	b lbl_800BBE80
lbl_800BBE68:
/* 800BBE68 000B8DC8  80 7F 00 14 */	lwz r3, 0x14(r31)
/* 800BBE6C 000B8DCC  28 03 00 00 */	cmplwi r3, 0
/* 800BBE70 000B8DD0  41 82 00 10 */	beq lbl_800BBE80
/* 800BBE74 000B8DD4  48 02 84 F9 */	bl subCnt__12RefCountableFv
/* 800BBE78 000B8DD8  38 00 00 00 */	li r0, 0
/* 800BBE7C 000B8DDC  90 1F 00 14 */	stw r0, 0x14(r31)
lbl_800BBE80:
/* 800BBE80 000B8DE0  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800BBE84 000B8DE4  38 60 00 00 */	li r3, 0
/* 800BBE88 000B8DE8  C0 0D B7 FC */	lfs f0, lbl_803E051C@sda21(r13)
/* 800BBE8C 000B8DEC  D4 04 00 A4 */	stfsu f0, 0xa4(r4)
/* 800BBE90 000B8DF0  C0 0D B8 00 */	lfs f0, lbl_803E0520@sda21(r13)
/* 800BBE94 000B8DF4  D0 04 00 04 */	stfs f0, 4(r4)
/* 800BBE98 000B8DF8  C0 0D B8 04 */	lfs f0, lbl_803E0524@sda21(r13)
/* 800BBE9C 000B8DFC  D0 04 00 08 */	stfs f0, 8(r4)

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 801D1B60 001CEAC0  7E A5 01 2E */	stwx r21, r5, r0
/* 801D1B64 001CEAC4  54 80 10 3A */	slwi r0, r4, 2
/* 801D1B68 001CEAC8  54 65 10 3A */	slwi r5, r3, 2
/* 801D1B6C 001CEACC  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1B70 001CEAD0  38 60 00 0C */	li r3, 0xc
/* 801D1B74 001CEAD4  7F A4 01 2E */	stwx r29, r4, r0
/* 801D1B78 001CEAD8  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1B7C 001CEADC  7F C4 29 2E */	stwx r30, r4, r5
/* 801D1B80 001CEAE0  80 9F 00 08 */	lwz r4, 8(r31)
/* 801D1B84 001CEAE4  93 84 00 00 */	stw r28, 0(r4)
/* 801D1B88 001CEAE8  4B E7 54 7D */	bl alloc__6SystemFUl
/* 801D1B8C 001CEAEC  3B 83 00 00 */	addi r28, r3, 0
/* 801D1B90 001CEAF0  7F 83 E3 79 */	or. r3, r28, r28
/* 801D1B94 001CEAF4  41 82 00 0C */	beq lbl_801D1BA0
/* 801D1B98 001CEAF8  38 80 00 03 */	li r4, 3
/* 801D1B9C 001CEAFC  4B F5 54 FD */	bl __ct__8TaiStateFi
lbl_801D1BA0:
/* 801D1BA0 001CEB00  38 00 00 00 */	li r0, 0
/* 801D1BA4 001CEB04  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1BA8 001CEB08  54 00 10 3A */	slwi r0, r0, 2
/* 801D1BAC 001CEB0C  7F 63 01 2E */	stwx r27, r3, r0
/* 801D1BB0 001CEB10  38 80 00 01 */	li r4, 1
/* 801D1BB4 001CEB14  38 00 00 02 */	li r0, 2
/* 801D1BB8 001CEB18  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1BBC 001CEB1C  54 84 10 3A */	slwi r4, r4, 2
/* 801D1BC0 001CEB20  54 00 10 3A */	slwi r0, r0, 2
/* 801D1BC4 001CEB24  7F A3 21 2E */	stwx r29, r3, r4
/* 801D1BC8 001CEB28  38 60 00 0C */	li r3, 0xc
/* 801D1BCC 001CEB2C  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1BD0 001CEB30  7E C4 01 2E */	stwx r22, r4, r0
/* 801D1BD4 001CEB34  80 9F 00 08 */	lwz r4, 8(r31)
/* 801D1BD8 001CEB38  93 84 00 08 */	stw r28, 8(r4)
/* 801D1BDC 001CEB3C  4B E7 54 29 */	bl alloc__6SystemFUl
/* 801D1BE0 001CEB40  3B 83 00 00 */	addi r28, r3, 0
/* 801D1BE4 001CEB44  7F 83 E3 79 */	or. r3, r28, r28
/* 801D1BE8 001CEB48  41 82 00 0C */	beq lbl_801D1BF4
/* 801D1BEC 001CEB4C  38 80 00 08 */	li r4, 8
/* 801D1BF0 001CEB50  4B F5 54 A9 */	bl __ct__8TaiStateFi
lbl_801D1BF4:
/* 801D1BF4 001CEB54  38 00 00 00 */	li r0, 0
/* 801D1BF8 001CEB58  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1BFC 001CEB5C  54 00 10 3A */	slwi r0, r0, 2
/* 801D1C00 001CEB60  7F 43 01 2E */	stwx r26, r3, r0
/* 801D1C04 001CEB64  38 80 00 01 */	li r4, 1
/* 801D1C08 001CEB68  38 00 00 02 */	li r0, 2
/* 801D1C0C 001CEB6C  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1C10 001CEB70  54 84 10 3A */	slwi r4, r4, 2
/* 801D1C14 001CEB74  38 A0 00 03 */	li r5, 3
/* 801D1C18 001CEB78  7E 83 21 2E */	stwx r20, r3, r4
/* 801D1C1C 001CEB7C  38 C0 00 04 */	li r6, 4
/* 801D1C20 001CEB80  38 E0 00 05 */	li r7, 5
/* 801D1C24 001CEB84  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1C28 001CEB88  54 00 10 3A */	slwi r0, r0, 2
/* 801D1C2C 001CEB8C  38 60 00 06 */	li r3, 6
/* 801D1C30 001CEB90  7E E4 01 2E */	stwx r23, r4, r0
/* 801D1C34 001CEB94  38 80 00 07 */	li r4, 7
/* 801D1C38 001CEB98  54 A0 10 3A */	slwi r0, r5, 2
/* 801D1C3C 001CEB9C  80 BC 00 08 */	lwz r5, 8(r28)
/* 801D1C40 001CEBA0  54 C6 10 3A */	slwi r6, r6, 2
/* 801D1C44 001CEBA4  54 E7 10 3A */	slwi r7, r7, 2
/* 801D1C48 001CEBA8  7F 65 01 2E */	stwx r27, r5, r0
/* 801D1C4C 001CEBAC  54 65 10 3A */	slwi r5, r3, 2
/* 801D1C50 001CEBB0  54 80 10 3A */	slwi r0, r4, 2
/* 801D1C54 001CEBB4  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1C58 001CEBB8  38 60 00 0C */	li r3, 0xc
/* 801D1C5C 001CEBBC  7F 24 31 2E */	stwx r25, r4, r6
/* 801D1C60 001CEBC0  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1C64 001CEBC4  7E 64 39 2E */	stwx r19, r4, r7
/* 801D1C68 001CEBC8  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1C6C 001CEBCC  7F A4 29 2E */	stwx r29, r4, r5
/* 801D1C70 001CEBD0  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1C74 001CEBD4  7F C4 01 2E */	stwx r30, r4, r0
/* 801D1C78 001CEBD8  80 9F 00 08 */	lwz r4, 8(r31)
/* 801D1C7C 001CEBDC  93 84 00 0C */	stw r28, 0xc(r4)
/* 801D1C80 001CEBE0  4B E7 53 85 */	bl alloc__6SystemFUl
/* 801D1C84 001CEBE4  3B 83 00 00 */	addi r28, r3, 0
/* 801D1C88 001CEBE8  7F 83 E3 79 */	or. r3, r28, r28
/* 801D1C8C 001CEBEC  41 82 00 0C */	beq lbl_801D1C98
/* 801D1C90 001CEBF0  38 80 00 03 */	li r4, 3
/* 801D1C94 001CEBF4  4B F5 54 05 */	bl __ct__8TaiStateFi
lbl_801D1C98:
/* 801D1C98 001CEBF8  38 00 00 00 */	li r0, 0
/* 801D1C9C 001CEBFC  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1CA0 001CEC00  54 04 10 3A */	slwi r4, r0, 2
/* 801D1CA4 001CEC04  80 01 00 78 */	lwz r0, 0x78(r1)
/* 801D1CA8 001CEC08  7C 03 21 2E */	stwx r0, r3, r4
/* 801D1CAC 001CEC0C  38 80 00 01 */	li r4, 1
/* 801D1CB0 001CEC10  38 00 00 02 */	li r0, 2
/* 801D1CB4 001CEC14  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1CB8 001CEC18  54 84 10 3A */	slwi r4, r4, 2
/* 801D1CBC 001CEC1C  54 00 10 3A */	slwi r0, r0, 2
/* 801D1CC0 001CEC20  7F A3 21 2E */	stwx r29, r3, r4
/* 801D1CC4 001CEC24  38 60 00 0C */	li r3, 0xc
/* 801D1CC8 001CEC28  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1CCC 001CEC2C  7F C4 01 2E */	stwx r30, r4, r0
/* 801D1CD0 001CEC30  80 9F 00 08 */	lwz r4, 8(r31)
/* 801D1CD4 001CEC34  93 84 00 10 */	stw r28, 0x10(r4)
/* 801D1CD8 001CEC38  4B E7 53 2D */	bl alloc__6SystemFUl
/* 801D1CDC 001CEC3C  3B 83 00 00 */	addi r28, r3, 0
/* 801D1CE0 001CEC40  7F 83 E3 79 */	or. r3, r28, r28
/* 801D1CE4 001CEC44  41 82 00 0C */	beq lbl_801D1CF0
/* 801D1CE8 001CEC48  38 80 00 09 */	li r4, 9
/* 801D1CEC 001CEC4C  4B F5 53 AD */	bl __ct__8TaiStateFi
lbl_801D1CF0:
/* 801D1CF0 001CEC50  38 00 00 00 */	li r0, 0
/* 801D1CF4 001CEC54  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1CF8 001CEC58  54 00 10 3A */	slwi r0, r0, 2
/* 801D1CFC 001CEC5C  7E A3 01 2E */	stwx r21, r3, r0
/* 801D1D00 001CEC60  38 00 00 01 */	li r0, 1
/* 801D1D04 001CEC64  38 80 00 02 */	li r4, 2
/* 801D1D08 001CEC68  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1D0C 001CEC6C  54 05 10 3A */	slwi r5, r0, 2
/* 801D1D10 001CEC70  38 00 00 03 */	li r0, 3
/* 801D1D14 001CEC74  7F 43 29 2E */	stwx r26, r3, r5
/* 801D1D18 001CEC78  38 E0 00 04 */	li r7, 4
/* 801D1D1C 001CEC7C  38 A0 00 05 */	li r5, 5
/* 801D1D20 001CEC80  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1D24 001CEC84  54 84 10 3A */	slwi r4, r4, 2
/* 801D1D28 001CEC88  38 C0 00 06 */	li r6, 6
/* 801D1D2C 001CEC8C  7E 83 21 2E */	stwx r20, r3, r4
/* 801D1D30 001CEC90  38 80 00 07 */	li r4, 7
/* 801D1D34 001CEC94  39 20 00 08 */	li r9, 8
/* 801D1D38 001CEC98  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1D3C 001CEC9C  54 00 10 3A */	slwi r0, r0, 2
/* 801D1D40 001CECA0  54 E8 10 3A */	slwi r8, r7, 2
/* 801D1D44 001CECA4  7E E3 01 2E */	stwx r23, r3, r0
/* 801D1D48 001CECA8  54 A5 10 3A */	slwi r5, r5, 2
/* 801D1D4C 001CECAC  54 C0 10 3A */	slwi r0, r6, 2
/* 801D1D50 001CECB0  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1D54 001CECB4  54 86 10 3A */	slwi r6, r4, 2
/* 801D1D58 001CECB8  55 27 10 3A */	slwi r7, r9, 2
/* 801D1D5C 001CECBC  7F 63 41 2E */	stwx r27, r3, r8
/* 801D1D60 001CECC0  38 60 00 0C */	li r3, 0xc
/* 801D1D64 001CECC4  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1D68 001CECC8  7E 44 29 2E */	stwx r18, r4, r5
/* 801D1D6C 001CECCC  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1D70 001CECD0  7E 64 01 2E */	stwx r19, r4, r0
/* 801D1D74 001CECD4  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1D78 001CECD8  7F A4 31 2E */	stwx r29, r4, r6
/* 801D1D7C 001CECDC  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1D80 001CECE0  7F C4 39 2E */	stwx r30, r4, r7
/* 801D1D84 001CECE4  80 9F 00 08 */	lwz r4, 8(r31)
/* 801D1D88 001CECE8  93 84 00 14 */	stw r28, 0x14(r4)
/* 801D1D8C 001CECEC  4B E7 52 79 */	bl alloc__6SystemFUl
/* 801D1D90 001CECF0  3B 83 00 00 */	addi r28, r3, 0
/* 801D1D94 001CECF4  7F 83 E3 79 */	or. r3, r28, r28
/* 801D1D98 001CECF8  41 82 00 0C */	beq lbl_801D1DA4
/* 801D1D9C 001CECFC  38 80 00 03 */	li r4, 3
/* 801D1DA0 001CED00  4B F5 52 F9 */	bl __ct__8TaiStateFi
lbl_801D1DA4:
/* 801D1DA4 001CED04  38 00 00 00 */	li r0, 0
/* 801D1DA8 001CED08  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1DAC 001CED0C  54 00 10 3A */	slwi r0, r0, 2
/* 801D1DB0 001CED10  7F C3 01 2E */	stwx r30, r3, r0
/* 801D1DB4 001CED14  38 80 00 01 */	li r4, 1
/* 801D1DB8 001CED18  38 00 00 02 */	li r0, 2
/* 801D1DBC 001CED1C  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1DC0 001CED20  54 84 10 3A */	slwi r4, r4, 2
/* 801D1DC4 001CED24  54 00 10 3A */	slwi r0, r0, 2
/* 801D1DC8 001CED28  7E 03 21 2E */	stwx r16, r3, r4
/* 801D1DCC 001CED2C  38 60 00 0C */	li r3, 0xc
/* 801D1DD0 001CED30  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1DD4 001CED34  7E 24 01 2E */	stwx r17, r4, r0
/* 801D1DD8 001CED38  80 9F 00 08 */	lwz r4, 8(r31)
/* 801D1DDC 001CED3C  93 84 00 18 */	stw r28, 0x18(r4)
/* 801D1DE0 001CED40  4B E7 52 25 */	bl alloc__6SystemFUl
/* 801D1DE4 001CED44  3B 83 00 00 */	addi r28, r3, 0
/* 801D1DE8 001CED48  7F 83 E3 79 */	or. r3, r28, r28
/* 801D1DEC 001CED4C  41 82 00 0C */	beq lbl_801D1DF8
/* 801D1DF0 001CED50  38 80 00 07 */	li r4, 7
/* 801D1DF4 001CED54  4B F5 52 A5 */	bl __ct__8TaiStateFi
lbl_801D1DF8:
/* 801D1DF8 001CED58  38 00 00 00 */	li r0, 0
/* 801D1DFC 001CED5C  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1E00 001CED60  54 00 10 3A */	slwi r0, r0, 2
/* 801D1E04 001CED64  7F C3 01 2E */	stwx r30, r3, r0
/* 801D1E08 001CED68  38 00 00 01 */	li r0, 1
/* 801D1E0C 001CED6C  38 60 00 02 */	li r3, 2
/* 801D1E10 001CED70  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1E14 001CED74  54 00 10 3A */	slwi r0, r0, 2
/* 801D1E18 001CED78  38 E0 00 05 */	li r7, 5
/* 801D1E1C 001CED7C  7E A4 01 2E */	stwx r21, r4, r0
/* 801D1E20 001CED80  54 63 10 3A */	slwi r3, r3, 2
/* 801D1E24 001CED84  38 A0 00 03 */	li r5, 3
/* 801D1E28 001CED88  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1E2C 001CED8C  38 00 00 04 */	li r0, 4
/* 801D1E30 001CED90  54 E7 10 3A */	slwi r7, r7, 2
/* 801D1E34 001CED94  7F 44 19 2E */	stwx r26, r4, r3
/* 801D1E38 001CED98  54 A4 10 3A */	slwi r4, r5, 2
/* 801D1E3C 001CED9C  54 05 10 3A */	slwi r5, r0, 2
/* 801D1E40 001CEDA0  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1E44 001CEDA4  38 C0 00 06 */	li r6, 6
/* 801D1E48 001CEDA8  54 C0 10 3A */	slwi r0, r6, 2
/* 801D1E4C 001CEDAC  7E 83 21 2E */	stwx r20, r3, r4
/* 801D1E50 001CEDB0  38 60 00 0C */	li r3, 0xc
/* 801D1E54 001CEDB4  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1E58 001CEDB8  7F 64 29 2E */	stwx r27, r4, r5
/* 801D1E5C 001CEDBC  80 A1 00 6C */	lwz r5, 0x6c(r1)
/* 801D1E60 001CEDC0  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1E64 001CEDC4  7C A4 39 2E */	stwx r5, r4, r7
/* 801D1E68 001CEDC8  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1E6C 001CEDCC  7F A4 01 2E */	stwx r29, r4, r0
/* 801D1E70 001CEDD0  80 9F 00 08 */	lwz r4, 8(r31)
/* 801D1E74 001CEDD4  93 84 00 2C */	stw r28, 0x2c(r4)
/* 801D1E78 001CEDD8  4B E7 51 8D */	bl alloc__6SystemFUl
/* 801D1E7C 001CEDDC  3B 83 00 00 */	addi r28, r3, 0
/* 801D1E80 001CEDE0  7F 83 E3 79 */	or. r3, r28, r28
/* 801D1E84 001CEDE4  41 82 00 0C */	beq lbl_801D1E90
/* 801D1E88 001CEDE8  38 80 00 07 */	li r4, 7
/* 801D1E8C 001CEDEC  4B F5 52 0D */	bl __ct__8TaiStateFi
lbl_801D1E90:
/* 801D1E90 001CEDF0  38 00 00 00 */	li r0, 0
/* 801D1E94 001CEDF4  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1E98 001CEDF8  54 00 10 3A */	slwi r0, r0, 2
/* 801D1E9C 001CEDFC  7F C3 01 2E */	stwx r30, r3, r0
/* 801D1EA0 001CEE00  38 60 00 01 */	li r3, 1
/* 801D1EA4 001CEE04  54 65 10 3A */	slwi r5, r3, 2
/* 801D1EA8 001CEE08  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1EAC 001CEE0C  38 00 00 02 */	li r0, 2
/* 801D1EB0 001CEE10  38 E0 00 05 */	li r7, 5
/* 801D1EB4 001CEE14  7F 44 29 2E */	stwx r26, r4, r5
/* 801D1EB8 001CEE18  54 00 10 3A */	slwi r0, r0, 2
/* 801D1EBC 001CEE1C  38 60 00 03 */	li r3, 3
/* 801D1EC0 001CEE20  80 DC 00 08 */	lwz r6, 8(r28)
/* 801D1EC4 001CEE24  38 80 00 04 */	li r4, 4
/* 801D1EC8 001CEE28  38 A0 00 06 */	li r5, 6
/* 801D1ECC 001CEE2C  7E 86 01 2E */	stwx r20, r6, r0
/* 801D1ED0 001CEE30  54 60 10 3A */	slwi r0, r3, 2
/* 801D1ED4 001CEE34  54 86 10 3A */	slwi r6, r4, 2
/* 801D1ED8 001CEE38  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1EDC 001CEE3C  54 A4 10 3A */	slwi r4, r5, 2
/* 801D1EE0 001CEE40  54 E7 10 3A */	slwi r7, r7, 2
/* 801D1EE4 001CEE44  7F 63 01 2E */	stwx r27, r3, r0
/* 801D1EE8 001CEE48  38 60 00 0C */	li r3, 0xc
/* 801D1EEC 001CEE4C  80 01 00 74 */	lwz r0, 0x74(r1)
/* 801D1EF0 001CEE50  80 BC 00 08 */	lwz r5, 8(r28)
/* 801D1EF4 001CEE54  7C 05 31 2E */	stwx r0, r5, r6
/* 801D1EF8 001CEE58  80 BC 00 08 */	lwz r5, 8(r28)
/* 801D1EFC 001CEE5C  7E 65 39 2E */	stwx r19, r5, r7
/* 801D1F00 001CEE60  80 BC 00 08 */	lwz r5, 8(r28)
/* 801D1F04 001CEE64  7F A5 21 2E */	stwx r29, r5, r4
/* 801D1F08 001CEE68  80 9F 00 08 */	lwz r4, 8(r31)
/* 801D1F0C 001CEE6C  93 84 00 1C */	stw r28, 0x1c(r4)
/* 801D1F10 001CEE70  4B E7 50 F5 */	bl alloc__6SystemFUl
/* 801D1F14 001CEE74  3B 83 00 00 */	addi r28, r3, 0
/* 801D1F18 001CEE78  7F 83 E3 79 */	or. r3, r28, r28
/* 801D1F1C 001CEE7C  41 82 00 0C */	beq lbl_801D1F28
/* 801D1F20 001CEE80  38 80 00 04 */	li r4, 4
/* 801D1F24 001CEE84  4B F5 51 75 */	bl __ct__8TaiStateFi
lbl_801D1F28:
/* 801D1F28 001CEE88  38 00 00 00 */	li r0, 0
/* 801D1F2C 001CEE8C  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1F30 001CEE90  54 00 10 3A */	slwi r0, r0, 2
/* 801D1F34 001CEE94  80 C1 00 70 */	lwz r6, 0x70(r1)
/* 801D1F38 001CEE98  7F C3 01 2E */	stwx r30, r3, r0
/* 801D1F3C 001CEE9C  38 00 00 01 */	li r0, 1
/* 801D1F40 001CEEA0  38 A0 00 03 */	li r5, 3
/* 801D1F44 001CEEA4  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1F48 001CEEA8  54 00 10 3A */	slwi r0, r0, 2
/* 801D1F4C 001CEEAC  38 80 00 02 */	li r4, 2
/* 801D1F50 001CEEB0  7C C3 01 2E */	stwx r6, r3, r0
/* 801D1F54 001CEEB4  54 80 10 3A */	slwi r0, r4, 2
/* 801D1F58 001CEEB8  54 A5 10 3A */	slwi r5, r5, 2
/* 801D1F5C 001CEEBC  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1F60 001CEEC0  38 60 00 0C */	li r3, 0xc
/* 801D1F64 001CEEC4  7E A4 01 2E */	stwx r21, r4, r0
/* 801D1F68 001CEEC8  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1F6C 001CEECC  7F A4 29 2E */	stwx r29, r4, r5
/* 801D1F70 001CEED0  80 9F 00 08 */	lwz r4, 8(r31)
/* 801D1F74 001CEED4  93 84 00 20 */	stw r28, 0x20(r4)
/* 801D1F78 001CEED8  4B E7 50 8D */	bl alloc__6SystemFUl
/* 801D1F7C 001CEEDC  3B 83 00 00 */	addi r28, r3, 0
/* 801D1F80 001CEEE0  7F 83 E3 79 */	or. r3, r28, r28
/* 801D1F84 001CEEE4  41 82 00 0C */	beq lbl_801D1F90
/* 801D1F88 001CEEE8  38 80 00 07 */	li r4, 7
/* 801D1F8C 001CEEEC  4B F5 51 0D */	bl __ct__8TaiStateFi
lbl_801D1F90:
/* 801D1F90 001CEEF0  38 00 00 00 */	li r0, 0
/* 801D1F94 001CEEF4  80 7C 00 08 */	lwz r3, 8(r28)
/* 801D1F98 001CEEF8  54 00 10 3A */	slwi r0, r0, 2
/* 801D1F9C 001CEEFC  7F C3 01 2E */	stwx r30, r3, r0
/* 801D1FA0 001CEF00  38 00 00 01 */	li r0, 1
/* 801D1FA4 001CEF04  38 60 00 02 */	li r3, 2
/* 801D1FA8 001CEF08  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1FAC 001CEF0C  54 00 10 3A */	slwi r0, r0, 2
/* 801D1FB0 001CEF10  38 C0 00 03 */	li r6, 3
/* 801D1FB4 001CEF14  7F 44 01 2E */	stwx r26, r4, r0
/* 801D1FB8 001CEF18  38 00 00 04 */	li r0, 4
/* 801D1FBC 001CEF1C  38 A0 00 05 */	li r5, 5
/* 801D1FC0 001CEF20  80 9C 00 08 */	lwz r4, 8(r28)
/* 801D1FC4 001CEF24  54 63 10 3A */	slwi r3, r3, 2
/* 801D1FC8 001CEF28  38 E0 00 06 */	li r7, 6
/* 801D1FCC 001CEF2C  7E 84 19 2E */	stwx r20, r4, r3

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x73616945
	.4byte 0x76656e74
	.4byte 0x732e6370
	.4byte 0x70000000
	.4byte 0x73616945
	.4byte 0x76656e74
	.4byte 0
	.4byte 0x53414955
	.4byte 0x73657245
	.4byte 0x76656e74
	.4byte 0
	.4byte 0x52656365
	.4byte 0x69766572
	.4byte 0x3c414943
	.4byte 0x72656174
	.4byte 0x7572653e
	.4byte 0
	.4byte 0x53414945
	.4byte 0x76656e74
	.4byte 0
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte 0
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__12SAIUserEvent
__vt__12SAIUserEvent:
	.4byte __RTTI__12SAIUserEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte procUserMsg__12SAIUserEventFP10AICreatureP7MsgUser
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
	.4byte 0x53414947
	.4byte 0x726f756e
	.4byte 0x64457665
	.4byte 0x6e740000
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__14SAIGroundEvent
__vt__14SAIGroundEvent:
	.4byte __RTTI__14SAIGroundEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte procGroundMsg__14SAIGroundEventFP10AICreatureP9MsgGround
	.4byte 0x53414943
	.4byte 0x6f6c6c69
	.4byte 0x64654576
	.4byte 0x656e7400
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__15SAICollideEvent
__vt__15SAICollideEvent:
	.4byte __RTTI__15SAICollideEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte procCollideMsg__15SAICollideEventFP10AICreatureP10MsgCollide
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
	.4byte 0x53414942
	.4byte 0x6f756e63
	.4byte 0x65457665
	.4byte 0x6e740000
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__14SAIBounceEvent
__vt__14SAIBounceEvent:
	.4byte __RTTI__14SAIBounceEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte procBounceMsg__14SAIBounceEventFP10AICreatureP9MsgBounce
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
	.4byte 0x5341494d
	.4byte 0x6f74696f
	.4byte 0x6e4c6f6f
	.4byte 0x70456e64
	.4byte 0x4576656e
	.4byte 0x74000000
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__21SAIMotionLoopEndEvent
__vt__21SAIMotionLoopEndEvent:
	.4byte __RTTI__21SAIMotionLoopEndEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte procAnimMsg__21SAIMotionLoopEndEventFP10AICreatureP7MsgAnim
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
	.4byte 0x5341494d
	.4byte 0x6f74696f
	.4byte 0x6e4c6f6f
	.4byte 0x70537461
	.4byte 0x72744576
	.4byte 0x656e7400
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__23SAIMotionLoopStartEvent
__vt__23SAIMotionLoopStartEvent:
	.4byte __RTTI__23SAIMotionLoopStartEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte procAnimMsg__23SAIMotionLoopStartEventFP10AICreatureP7MsgAnim
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
	.4byte 0x5341494d
	.4byte 0x6f74696f
	.4byte 0x6e416374
	.4byte 0x696f6e30
	.4byte 0x4576656e
	.4byte 0x74000000
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__21SAIMotionAction0Event
__vt__21SAIMotionAction0Event:
	.4byte __RTTI__21SAIMotionAction0Event
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte procAnimMsg__21SAIMotionAction0EventFP10AICreatureP7MsgAnim
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
	.4byte 0x5341494d
	.4byte 0x6f74696f
	.4byte 0x6e446f6e
	.4byte 0x65457665
	.4byte 0x6e740000
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte 0
.global __vt__18SAIMotionDoneEvent
__vt__18SAIMotionDoneEvent:
	.4byte __RTTI__18SAIMotionDoneEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte procAnimMsg__18SAIMotionDoneEventFP10AICreatureP7MsgAnim
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.global __vt__8SAIEvent
__vt__8SAIEvent:
	.4byte __RTTI__8SAIEvent
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.global "__vt__22Receiver<10AICreature>"
"__vt__22Receiver<10AICreature>":
	.4byte "__RTTI__22Receiver<10AICreature>"
	.4byte 0
	.4byte "procMsg__22Receiver<10AICreature>FP10AICreatureP3Msg"
	.4byte "procBounceMsg__22Receiver<10AICreature>FP10AICreatureP9MsgBounce"
	.4byte "procStickMsg__22Receiver<10AICreature>FP10AICreatureP8MsgStick"
	.4byte "procHangMsg__22Receiver<10AICreature>FP10AICreatureP7MsgHang"
	.4byte "procTargetMsg__22Receiver<10AICreature>FP10AICreatureP9MsgTarget"
	.4byte "procCollideMsg__22Receiver<10AICreature>FP10AICreatureP10MsgCollide"
	.4byte "procAnimMsg__22Receiver<10AICreature>FP10AICreatureP7MsgAnim"
	.4byte "procDamageMsg__22Receiver<10AICreature>FP10AICreatureP9MsgDamage"
	.4byte "procWallMsg__22Receiver<10AICreature>FP10AICreatureP7MsgWall"
	.4byte "procOffWallMsg__22Receiver<10AICreature>FP10AICreatureP10MsgOffWall"
	.4byte "procUserMsg__22Receiver<10AICreature>FP10AICreatureP7MsgUser"
	.4byte "procGroundMsg__22Receiver<10AICreature>FP10AICreatureP9MsgGround"
.global lbl_802AD6E8
lbl_802AD6E8:
	.4byte lbl_8007D184
	.4byte lbl_8007D1AC
	.4byte lbl_8007D1C0
	.4byte lbl_8007D1D4
	.4byte lbl_8007D1E8
	.4byte lbl_8007D1FC
	.4byte lbl_8007D210
	.4byte lbl_8007D224
	.4byte lbl_8007D198
	.4byte lbl_8007D24C
	.4byte lbl_8007D238
	.4byte 0x00000000

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global lbl_803DEA18
lbl_803DEA18:
	.4byte 0x00000000
.global lbl_803DEA1C
lbl_803DEA1C:
	.4byte 0x00000000
	.4byte 0x802AD2EC
	.4byte 0x00000000
.global __RTTI__15InteractPullout
__RTTI__15InteractPullout:
	.4byte 0x802ad2dc
	.4byte 0x802ad2f8
.global "__RTTI__22Receiver<10AICreature>"
"__RTTI__22Receiver<10AICreature>":
	.4byte 0x802ad35c
	.4byte 0
.global __RTTI__8SAIEvent
__RTTI__8SAIEvent:
	.4byte 0x802ad374
	.4byte 0x802ad380
.global __RTTI__12SAIUserEvent
__RTTI__12SAIUserEvent:
	.4byte 0x802ad34c
	.4byte 0x802ad38c
.global __RTTI__14SAIGroundEvent
__RTTI__14SAIGroundEvent:
	.4byte 0x802ad3d8
	.4byte 0x802ad3e8
.global __RTTI__15SAICollideEvent
__RTTI__15SAICollideEvent:
	.4byte 0x802ad434
	.4byte 0x802ad444
.global __RTTI__14SAIBounceEvent
__RTTI__14SAIBounceEvent:
	.4byte 0x802ad490
	.4byte 0x802ad4a0
.global __RTTI__21SAIMotionLoopEndEvent
__RTTI__21SAIMotionLoopEndEvent:
	.4byte 0x802ad4ec
	.4byte 0x802ad504
