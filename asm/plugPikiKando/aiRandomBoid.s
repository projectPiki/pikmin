.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn animationKeyUpdated__Q213ActRandomBoid12AnimListenerFR16PaniAnimKeyEvent, global
/* 800C0A10 000BD970  7C 08 02 A6 */	mflr r0
/* 800C0A14 000BD974  90 01 00 04 */	stw r0, 4(r1)
/* 800C0A18 000BD978  94 21 FF 38 */	stwu r1, -0xc8(r1)
/* 800C0A1C 000BD97C  DB E1 00 C0 */	stfd f31, 0xc0(r1)
/* 800C0A20 000BD980  DB C1 00 B8 */	stfd f30, 0xb8(r1)
/* 800C0A24 000BD984  93 E1 00 B4 */	stw r31, 0xb4(r1)
/* 800C0A28 000BD988  3B E3 00 00 */	addi r31, r3, 0
/* 800C0A2C 000BD98C  93 C1 00 B0 */	stw r30, 0xb0(r1)
/* 800C0A30 000BD990  80 04 00 00 */	lwz r0, 0(r4)
/* 800C0A34 000BD994  2C 00 00 01 */	cmpwi r0, 1
/* 800C0A38 000BD998  41 82 02 B0 */	beq .L_800C0CE8
/* 800C0A3C 000BD99C  40 80 02 AC */	bge .L_800C0CE8
/* 800C0A40 000BD9A0  2C 00 00 00 */	cmpwi r0, 0
/* 800C0A44 000BD9A4  40 80 00 08 */	bge .L_800C0A4C
/* 800C0A48 000BD9A8  48 00 02 A0 */	b .L_800C0CE8
.L_800C0A4C:
/* 800C0A4C 000BD9AC  80 7F 00 04 */	lwz r3, 4(r31)
/* 800C0A50 000BD9B0  38 00 00 00 */	li r0, 0
/* 800C0A54 000BD9B4  98 03 00 1C */	stb r0, 0x1c(r3)
/* 800C0A58 000BD9B8  80 7F 00 04 */	lwz r3, 4(r31)
/* 800C0A5C 000BD9BC  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800C0A60 000BD9C0  2C 00 00 01 */	cmpwi r0, 1
/* 800C0A64 000BD9C4  41 82 00 20 */	beq .L_800C0A84
/* 800C0A68 000BD9C8  40 80 00 10 */	bge .L_800C0A78
/* 800C0A6C 000BD9CC  2C 00 00 00 */	cmpwi r0, 0
/* 800C0A70 000BD9D0  40 80 02 28 */	bge .L_800C0C98
/* 800C0A74 000BD9D4  48 00 02 74 */	b .L_800C0CE8
.L_800C0A78:
/* 800C0A78 000BD9D8  2C 00 00 03 */	cmpwi r0, 3
/* 800C0A7C 000BD9DC  40 80 02 6C */	bge .L_800C0CE8
/* 800C0A80 000BD9E0  48 00 01 E4 */	b .L_800C0C64
.L_800C0A84:
/* 800C0A84 000BD9E4  48 15 75 ED */	bl rand
/* 800C0A88 000BD9E8  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C0A8C 000BD9EC  C8 82 94 78 */	lfd f4, lbl_803E9678@sda21(r2)
/* 800C0A90 000BD9F0  90 01 00 AC */	stw r0, 0xac(r1)
/* 800C0A94 000BD9F4  3F C0 43 30 */	lis r30, 0x4330
/* 800C0A98 000BD9F8  C0 62 94 5C */	lfs f3, lbl_803E965C@sda21(r2)
/* 800C0A9C 000BD9FC  93 C1 00 A8 */	stw r30, 0xa8(r1)
/* 800C0AA0 000BDA00  C0 42 94 58 */	lfs f2, lbl_803E9658@sda21(r2)
/* 800C0AA4 000BDA04  C8 21 00 A8 */	lfd f1, 0xa8(r1)
/* 800C0AA8 000BDA08  C0 02 94 64 */	lfs f0, lbl_803E9664@sda21(r2)
/* 800C0AAC 000BDA0C  EC 81 20 28 */	fsubs f4, f1, f4
/* 800C0AB0 000BDA10  C0 22 94 60 */	lfs f1, lbl_803E9660@sda21(r2)
/* 800C0AB4 000BDA14  EC 64 18 24 */	fdivs f3, f4, f3
/* 800C0AB8 000BDA18  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800C0ABC 000BDA1C  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800C0AC0 000BDA20  EF E1 00 32 */	fmuls f31, f1, f0
/* 800C0AC4 000BDA24  48 15 75 AD */	bl rand
/* 800C0AC8 000BDA28  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C0ACC 000BDA2C  C8 82 94 78 */	lfd f4, lbl_803E9678@sda21(r2)
/* 800C0AD0 000BDA30  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 800C0AD4 000BDA34  C0 42 94 5C */	lfs f2, lbl_803E965C@sda21(r2)
/* 800C0AD8 000BDA38  93 C1 00 A0 */	stw r30, 0xa0(r1)
/* 800C0ADC 000BDA3C  C0 22 94 58 */	lfs f1, lbl_803E9658@sda21(r2)
/* 800C0AE0 000BDA40  C8 61 00 A0 */	lfd f3, 0xa0(r1)
/* 800C0AE4 000BDA44  C0 02 94 68 */	lfs f0, lbl_803E9668@sda21(r2)
/* 800C0AE8 000BDA48  EC 63 20 28 */	fsubs f3, f3, f4
/* 800C0AEC 000BDA4C  EC 43 10 24 */	fdivs f2, f3, f2
/* 800C0AF0 000BDA50  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C0AF4 000BDA54  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800C0AF8 000BDA58  40 81 00 74 */	ble .L_800C0B6C
/* 800C0AFC 000BDA5C  38 61 00 8C */	addi r3, r1, 0x8c
/* 800C0B00 000BDA60  38 80 00 00 */	li r4, 0
/* 800C0B04 000BDA64  48 05 E4 55 */	bl __ct__14PaniMotionInfoFi
/* 800C0B08 000BDA68  3B C3 00 00 */	addi r30, r3, 0
/* 800C0B0C 000BDA6C  38 BF 00 00 */	addi r5, r31, 0
/* 800C0B10 000BDA70  38 61 00 94 */	addi r3, r1, 0x94
/* 800C0B14 000BDA74  38 80 00 00 */	li r4, 0
/* 800C0B18 000BDA78  48 05 E4 75 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800C0B1C 000BDA7C  7C 64 1B 78 */	mr r4, r3
/* 800C0B20 000BDA80  80 7F 00 08 */	lwz r3, 8(r31)
/* 800C0B24 000BDA84  7F C5 F3 78 */	mr r5, r30
/* 800C0B28 000BDA88  48 00 9E B1 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800C0B2C 000BDA8C  FC 20 F8 90 */	fmr f1, f31
/* 800C0B30 000BDA90  48 15 B1 B9 */	bl sinf
/* 800C0B34 000BDA94  FF C0 08 90 */	fmr f30, f1
/* 800C0B38 000BDA98  FC 20 F8 90 */	fmr f1, f31
/* 800C0B3C 000BDA9C  48 15 B0 19 */	bl cosf
/* 800C0B40 000BDAA0  D0 21 00 7C */	stfs f1, 0x7c(r1)
/* 800C0B44 000BDAA4  38 81 00 80 */	addi r4, r1, 0x80
/* 800C0B48 000BDAA8  C0 0D B9 E8 */	lfs f0, lbl_803E0708@sda21(r13)
/* 800C0B4C 000BDAAC  C0 41 00 7C */	lfs f2, 0x7c(r1)
/* 800C0B50 000BDAB0  C0 22 94 6C */	lfs f1, lbl_803E966C@sda21(r2)
/* 800C0B54 000BDAB4  D0 41 00 80 */	stfs f2, 0x80(r1)
/* 800C0B58 000BDAB8  D0 01 00 84 */	stfs f0, 0x84(r1)
/* 800C0B5C 000BDABC  D3 C1 00 88 */	stfs f30, 0x88(r1)
/* 800C0B60 000BDAC0  80 7F 00 08 */	lwz r3, 8(r31)
/* 800C0B64 000BDAC4  48 00 B2 75 */	bl setSpeed__4PikiFfR8Vector3f
/* 800C0B68 000BDAC8  48 00 01 80 */	b .L_800C0CE8
.L_800C0B6C:
/* 800C0B6C 000BDACC  48 15 75 05 */	bl rand
/* 800C0B70 000BDAD0  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C0B74 000BDAD4  C8 82 94 78 */	lfd f4, lbl_803E9678@sda21(r2)
/* 800C0B78 000BDAD8  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 800C0B7C 000BDADC  C0 42 94 5C */	lfs f2, lbl_803E965C@sda21(r2)
/* 800C0B80 000BDAE0  93 C1 00 A0 */	stw r30, 0xa0(r1)
/* 800C0B84 000BDAE4  C0 22 94 58 */	lfs f1, lbl_803E9658@sda21(r2)
/* 800C0B88 000BDAE8  C8 61 00 A0 */	lfd f3, 0xa0(r1)
/* 800C0B8C 000BDAEC  C0 02 94 68 */	lfs f0, lbl_803E9668@sda21(r2)
/* 800C0B90 000BDAF0  EC 63 20 28 */	fsubs f3, f3, f4
/* 800C0B94 000BDAF4  EC 43 10 24 */	fdivs f2, f3, f2
/* 800C0B98 000BDAF8  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C0B9C 000BDAFC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800C0BA0 000BDB00  40 81 00 54 */	ble .L_800C0BF4
/* 800C0BA4 000BDB04  38 61 00 6C */	addi r3, r1, 0x6c
/* 800C0BA8 000BDB08  38 80 00 00 */	li r4, 0
/* 800C0BAC 000BDB0C  48 05 E3 AD */	bl __ct__14PaniMotionInfoFi
/* 800C0BB0 000BDB10  3B C3 00 00 */	addi r30, r3, 0
/* 800C0BB4 000BDB14  38 BF 00 00 */	addi r5, r31, 0
/* 800C0BB8 000BDB18  38 61 00 74 */	addi r3, r1, 0x74
/* 800C0BBC 000BDB1C  38 80 00 00 */	li r4, 0
/* 800C0BC0 000BDB20  48 05 E3 CD */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800C0BC4 000BDB24  7C 64 1B 78 */	mr r4, r3
/* 800C0BC8 000BDB28  80 7F 00 08 */	lwz r3, 8(r31)
/* 800C0BCC 000BDB2C  7F C5 F3 78 */	mr r5, r30
/* 800C0BD0 000BDB30  48 00 9E 09 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800C0BD4 000BDB34  80 7F 00 08 */	lwz r3, 8(r31)
/* 800C0BD8 000BDB38  C0 0D B9 EC */	lfs f0, lbl_803E070C@sda21(r13)
/* 800C0BDC 000BDB3C  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800C0BE0 000BDB40  C0 0D B9 F0 */	lfs f0, lbl_803E0710@sda21(r13)
/* 800C0BE4 000BDB44  D0 03 00 04 */	stfs f0, 4(r3)
/* 800C0BE8 000BDB48  C0 0D B9 F4 */	lfs f0, lbl_803E0714@sda21(r13)
/* 800C0BEC 000BDB4C  D0 03 00 08 */	stfs f0, 8(r3)
/* 800C0BF0 000BDB50  48 00 00 F8 */	b .L_800C0CE8
.L_800C0BF4:
/* 800C0BF4 000BDB54  38 61 00 5C */	addi r3, r1, 0x5c
/* 800C0BF8 000BDB58  38 80 00 00 */	li r4, 0
/* 800C0BFC 000BDB5C  48 05 E3 5D */	bl __ct__14PaniMotionInfoFi
/* 800C0C00 000BDB60  3B C3 00 00 */	addi r30, r3, 0
/* 800C0C04 000BDB64  38 BF 00 00 */	addi r5, r31, 0
/* 800C0C08 000BDB68  38 61 00 64 */	addi r3, r1, 0x64
/* 800C0C0C 000BDB6C  38 80 00 00 */	li r4, 0
/* 800C0C10 000BDB70  48 05 E3 7D */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800C0C14 000BDB74  7C 64 1B 78 */	mr r4, r3
/* 800C0C18 000BDB78  80 7F 00 08 */	lwz r3, 8(r31)
/* 800C0C1C 000BDB7C  7F C5 F3 78 */	mr r5, r30
/* 800C0C20 000BDB80  48 00 9D B9 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800C0C24 000BDB84  FC 20 F8 90 */	fmr f1, f31
/* 800C0C28 000BDB88  48 15 B0 C1 */	bl sinf
/* 800C0C2C 000BDB8C  FF C0 08 90 */	fmr f30, f1
/* 800C0C30 000BDB90  FC 20 F8 90 */	fmr f1, f31
/* 800C0C34 000BDB94  48 15 AF 21 */	bl cosf
/* 800C0C38 000BDB98  D0 21 00 4C */	stfs f1, 0x4c(r1)
/* 800C0C3C 000BDB9C  38 81 00 50 */	addi r4, r1, 0x50
/* 800C0C40 000BDBA0  C0 0D B9 F8 */	lfs f0, lbl_803E0718@sda21(r13)
/* 800C0C44 000BDBA4  C0 41 00 4C */	lfs f2, 0x4c(r1)
/* 800C0C48 000BDBA8  C0 22 94 70 */	lfs f1, lbl_803E9670@sda21(r2)
/* 800C0C4C 000BDBAC  D0 41 00 50 */	stfs f2, 0x50(r1)
/* 800C0C50 000BDBB0  D0 01 00 54 */	stfs f0, 0x54(r1)
/* 800C0C54 000BDBB4  D3 C1 00 58 */	stfs f30, 0x58(r1)
/* 800C0C58 000BDBB8  80 7F 00 08 */	lwz r3, 8(r31)
/* 800C0C5C 000BDBBC  48 00 B1 7D */	bl setSpeed__4PikiFfR8Vector3f
/* 800C0C60 000BDBC0  48 00 00 88 */	b .L_800C0CE8
.L_800C0C64:
/* 800C0C64 000BDBC4  38 61 00 3C */	addi r3, r1, 0x3c
/* 800C0C68 000BDBC8  38 80 00 00 */	li r4, 0
/* 800C0C6C 000BDBCC  48 05 E2 ED */	bl __ct__14PaniMotionInfoFi
/* 800C0C70 000BDBD0  3B C3 00 00 */	addi r30, r3, 0
/* 800C0C74 000BDBD4  38 BF 00 00 */	addi r5, r31, 0
/* 800C0C78 000BDBD8  38 61 00 44 */	addi r3, r1, 0x44
/* 800C0C7C 000BDBDC  38 80 00 00 */	li r4, 0
/* 800C0C80 000BDBE0  48 05 E3 0D */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800C0C84 000BDBE4  7C 64 1B 78 */	mr r4, r3
/* 800C0C88 000BDBE8  80 7F 00 08 */	lwz r3, 8(r31)
/* 800C0C8C 000BDBEC  7F C5 F3 78 */	mr r5, r30
/* 800C0C90 000BDBF0  48 00 9D 49 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800C0C94 000BDBF4  48 00 00 54 */	b .L_800C0CE8
.L_800C0C98:
/* 800C0C98 000BDBF8  38 61 00 2C */	addi r3, r1, 0x2c
/* 800C0C9C 000BDBFC  38 80 00 00 */	li r4, 0
/* 800C0CA0 000BDC00  48 05 E2 B9 */	bl __ct__14PaniMotionInfoFi
/* 800C0CA4 000BDC04  3B C3 00 00 */	addi r30, r3, 0
/* 800C0CA8 000BDC08  38 BF 00 00 */	addi r5, r31, 0
/* 800C0CAC 000BDC0C  38 61 00 34 */	addi r3, r1, 0x34
/* 800C0CB0 000BDC10  38 80 00 00 */	li r4, 0
/* 800C0CB4 000BDC14  48 05 E2 D9 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800C0CB8 000BDC18  7C 64 1B 78 */	mr r4, r3
/* 800C0CBC 000BDC1C  80 7F 00 08 */	lwz r3, 8(r31)
/* 800C0CC0 000BDC20  7F C5 F3 78 */	mr r5, r30
/* 800C0CC4 000BDC24  48 00 9D 15 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800C0CC8 000BDC28  48 15 73 A9 */	bl rand
/* 800C0CCC 000BDC2C  80 7F 00 08 */	lwz r3, 8(r31)
/* 800C0CD0 000BDC30  C0 0D B9 FC */	lfs f0, lbl_803E071C@sda21(r13)
/* 800C0CD4 000BDC34  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800C0CD8 000BDC38  C0 0D BA 00 */	lfs f0, lbl_803E0720@sda21(r13)
/* 800C0CDC 000BDC3C  D0 03 00 04 */	stfs f0, 4(r3)
/* 800C0CE0 000BDC40  C0 0D BA 04 */	lfs f0, lbl_803E0724@sda21(r13)
/* 800C0CE4 000BDC44  D0 03 00 08 */	stfs f0, 8(r3)
.L_800C0CE8:
/* 800C0CE8 000BDC48  80 01 00 CC */	lwz r0, 0xcc(r1)
/* 800C0CEC 000BDC4C  CB E1 00 C0 */	lfd f31, 0xc0(r1)
/* 800C0CF0 000BDC50  CB C1 00 B8 */	lfd f30, 0xb8(r1)
/* 800C0CF4 000BDC54  83 E1 00 B4 */	lwz r31, 0xb4(r1)
/* 800C0CF8 000BDC58  83 C1 00 B0 */	lwz r30, 0xb0(r1)
/* 800C0CFC 000BDC5C  38 21 00 C8 */	addi r1, r1, 0xc8
/* 800C0D00 000BDC60  7C 08 03 A6 */	mtlr r0
/* 800C0D04 000BDC64  4E 80 00 20 */	blr 
.endfn animationKeyUpdated__Q213ActRandomBoid12AnimListenerFR16PaniAnimKeyEvent

.fn __ct__13ActRandomBoidFP4Piki, global
/* 800C0D08 000BDC68  7C 08 02 A6 */	mflr r0
/* 800C0D0C 000BDC6C  38 A0 00 01 */	li r5, 1
/* 800C0D10 000BDC70  90 01 00 04 */	stw r0, 4(r1)
/* 800C0D14 000BDC74  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800C0D18 000BDC78  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800C0D1C 000BDC7C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800C0D20 000BDC80  7C 9E 23 78 */	mr r30, r4
/* 800C0D24 000BDC84  90 61 00 08 */	stw r3, 8(r1)
/* 800C0D28 000BDC88  80 61 00 08 */	lwz r3, 8(r1)
/* 800C0D2C 000BDC8C  48 00 30 A5 */	bl __ct__6ActionFP4Pikib
/* 800C0D30 000BDC90  3C 60 80 2B */	lis r3, __vt__13ActRandomBoid@ha
/* 800C0D34 000BDC94  83 E1 00 08 */	lwz r31, 8(r1)
/* 800C0D38 000BDC98  38 03 77 34 */	addi r0, r3, __vt__13ActRandomBoid@l
/* 800C0D3C 000BDC9C  90 1F 00 00 */	stw r0, 0(r31)
/* 800C0D40 000BDCA0  38 60 00 10 */	li r3, 0x10
/* 800C0D44 000BDCA4  4B F8 62 C1 */	bl alloc__6SystemFUl
/* 800C0D48 000BDCA8  28 03 00 00 */	cmplwi r3, 0
/* 800C0D4C 000BDCAC  41 82 00 24 */	beq .L_800C0D70
/* 800C0D50 000BDCB0  3C 80 80 2B */	lis r4, __vt__19PaniAnimKeyListener@ha
/* 800C0D54 000BDCB4  38 04 DB 94 */	addi r0, r4, __vt__19PaniAnimKeyListener@l
/* 800C0D58 000BDCB8  3C 80 80 2B */	lis r4, __vt__Q213ActRandomBoid12AnimListener@ha
/* 800C0D5C 000BDCBC  90 03 00 00 */	stw r0, 0(r3)
/* 800C0D60 000BDCC0  38 04 78 28 */	addi r0, r4, __vt__Q213ActRandomBoid12AnimListener@l
/* 800C0D64 000BDCC4  90 03 00 00 */	stw r0, 0(r3)
/* 800C0D68 000BDCC8  93 E3 00 04 */	stw r31, 4(r3)
/* 800C0D6C 000BDCCC  93 C3 00 08 */	stw r30, 8(r3)
.L_800C0D70:
/* 800C0D70 000BDCD0  80 81 00 08 */	lwz r4, 8(r1)
/* 800C0D74 000BDCD4  90 64 00 24 */	stw r3, 0x24(r4)
/* 800C0D78 000BDCD8  7C 83 23 78 */	mr r3, r4
/* 800C0D7C 000BDCDC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800C0D80 000BDCE0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800C0D84 000BDCE4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800C0D88 000BDCE8  38 21 00 18 */	addi r1, r1, 0x18
/* 800C0D8C 000BDCEC  7C 08 03 A6 */	mtlr r0
/* 800C0D90 000BDCF0  4E 80 00 20 */	blr 
.endfn __ct__13ActRandomBoidFP4Piki

.fn initialise__Q213ActRandomBoid11InitialiserFP6Action, global
/* 800C0D94 000BDCF4  4E 80 00 20 */	blr 
.endfn initialise__Q213ActRandomBoid11InitialiserFP6Action

.fn init__13ActRandomBoidFP8Creature, global
/* 800C0D98 000BDCF8  7C 08 02 A6 */	mflr r0
/* 800C0D9C 000BDCFC  90 01 00 04 */	stw r0, 4(r1)
/* 800C0DA0 000BDD00  38 00 00 01 */	li r0, 1
/* 800C0DA4 000BDD04  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 800C0DA8 000BDD08  93 E1 00 44 */	stw r31, 0x44(r1)
/* 800C0DAC 000BDD0C  93 C1 00 40 */	stw r30, 0x40(r1)
/* 800C0DB0 000BDD10  3B C3 00 00 */	addi r30, r3, 0
/* 800C0DB4 000BDD14  90 03 00 14 */	stw r0, 0x14(r3)
/* 800C0DB8 000BDD18  48 15 72 B9 */	bl rand
/* 800C0DBC 000BDD1C  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C0DC0 000BDD20  C8 82 94 78 */	lfd f4, lbl_803E9678@sda21(r2)
/* 800C0DC4 000BDD24  90 01 00 3C */	stw r0, 0x3c(r1)
/* 800C0DC8 000BDD28  3C 00 43 30 */	lis r0, 0x4330
/* 800C0DCC 000BDD2C  C0 42 94 5C */	lfs f2, lbl_803E965C@sda21(r2)
/* 800C0DD0 000BDD30  90 01 00 38 */	stw r0, 0x38(r1)
/* 800C0DD4 000BDD34  C0 22 94 58 */	lfs f1, lbl_803E9658@sda21(r2)
/* 800C0DD8 000BDD38  C8 61 00 38 */	lfd f3, 0x38(r1)
/* 800C0DDC 000BDD3C  C0 02 94 80 */	lfs f0, lbl_803E9680@sda21(r2)
/* 800C0DE0 000BDD40  EC 63 20 28 */	fsubs f3, f3, f4
/* 800C0DE4 000BDD44  EC 43 10 24 */	fdivs f2, f3, f2
/* 800C0DE8 000BDD48  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C0DEC 000BDD4C  EC 00 00 72 */	fmuls f0, f0, f1
/* 800C0DF0 000BDD50  FC 00 00 1E */	fctiwz f0, f0
/* 800C0DF4 000BDD54  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 800C0DF8 000BDD58  80 61 00 34 */	lwz r3, 0x34(r1)
/* 800C0DFC 000BDD5C  38 03 00 14 */	addi r0, r3, 0x14
/* 800C0E00 000BDD60  90 1E 00 18 */	stw r0, 0x18(r30)
/* 800C0E04 000BDD64  48 15 72 6D */	bl rand
/* 800C0E08 000BDD68  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 800C0E0C 000BDD6C  38 61 00 1C */	addi r3, r1, 0x1c
/* 800C0E10 000BDD70  C0 0D BA 08 */	lfs f0, lbl_803E0728@sda21(r13)
/* 800C0E14 000BDD74  38 80 00 00 */	li r4, 0
/* 800C0E18 000BDD78  D4 05 00 A4 */	stfsu f0, 0xa4(r5)
/* 800C0E1C 000BDD7C  C0 0D BA 0C */	lfs f0, lbl_803E072C@sda21(r13)
/* 800C0E20 000BDD80  D0 05 00 04 */	stfs f0, 4(r5)
/* 800C0E24 000BDD84  C0 0D BA 10 */	lfs f0, lbl_803E0730@sda21(r13)
/* 800C0E28 000BDD88  D0 05 00 08 */	stfs f0, 8(r5)
/* 800C0E2C 000BDD8C  80 BE 00 24 */	lwz r5, 0x24(r30)
/* 800C0E30 000BDD90  48 05 E1 5D */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800C0E34 000BDD94  80 BE 00 24 */	lwz r5, 0x24(r30)
/* 800C0E38 000BDD98  3B E3 00 00 */	addi r31, r3, 0
/* 800C0E3C 000BDD9C  38 61 00 24 */	addi r3, r1, 0x24
/* 800C0E40 000BDDA0  38 80 00 00 */	li r4, 0
/* 800C0E44 000BDDA4  48 05 E1 49 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800C0E48 000BDDA8  7C 64 1B 78 */	mr r4, r3
/* 800C0E4C 000BDDAC  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800C0E50 000BDDB0  7F E5 FB 78 */	mr r5, r31
/* 800C0E54 000BDDB4  48 00 9B 85 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800C0E58 000BDDB8  80 7E 00 24 */	lwz r3, 0x24(r30)
/* 800C0E5C 000BDDBC  38 00 00 00 */	li r0, 0
/* 800C0E60 000BDDC0  98 03 00 0C */	stb r0, 0xc(r3)
/* 800C0E64 000BDDC4  98 1E 00 1C */	stb r0, 0x1c(r30)
/* 800C0E68 000BDDC8  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 800C0E6C 000BDDCC  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 800C0E70 000BDDD0  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 800C0E74 000BDDD4  38 21 00 48 */	addi r1, r1, 0x48
/* 800C0E78 000BDDD8  7C 08 03 A6 */	mtlr r0
/* 800C0E7C 000BDDDC  4E 80 00 20 */	blr 
.endfn init__13ActRandomBoidFP8Creature

.fn cleanup__13ActRandomBoidFv, global
/* 800C0E80 000BDDE0  4E 80 00 20 */	blr 
.endfn cleanup__13ActRandomBoidFv

.fn exec__13ActRandomBoidFv, global
/* 800C0E84 000BDDE4  7C 08 02 A6 */	mflr r0
/* 800C0E88 000BDDE8  90 01 00 04 */	stw r0, 4(r1)
/* 800C0E8C 000BDDEC  94 21 FE 38 */	stwu r1, -0x1c8(r1)
/* 800C0E90 000BDDF0  93 E1 01 C4 */	stw r31, 0x1c4(r1)
/* 800C0E94 000BDDF4  7C 7F 1B 78 */	mr r31, r3
/* 800C0E98 000BDDF8  93 C1 01 C0 */	stw r30, 0x1c0(r1)
/* 800C0E9C 000BDDFC  93 A1 01 BC */	stw r29, 0x1bc(r1)
/* 800C0EA0 000BDE00  88 03 00 1C */	lbz r0, 0x1c(r3)
/* 800C0EA4 000BDE04  28 00 00 00 */	cmplwi r0, 0
/* 800C0EA8 000BDE08  41 82 00 28 */	beq .L_800C0ED0
/* 800C0EAC 000BDE0C  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800C0EB0 000BDE10  38 60 00 00 */	li r3, 0
/* 800C0EB4 000BDE14  C0 0D BA 14 */	lfs f0, lbl_803E0734@sda21(r13)
/* 800C0EB8 000BDE18  D4 04 00 A4 */	stfsu f0, 0xa4(r4)
/* 800C0EBC 000BDE1C  C0 0D BA 18 */	lfs f0, lbl_803E0738@sda21(r13)
/* 800C0EC0 000BDE20  D0 04 00 04 */	stfs f0, 4(r4)
/* 800C0EC4 000BDE24  C0 0D BA 1C */	lfs f0, lbl_803E073C@sda21(r13)
/* 800C0EC8 000BDE28  D0 04 00 08 */	stfs f0, 8(r4)
/* 800C0ECC 000BDE2C  48 00 03 58 */	b .L_800C1224
.L_800C0ED0:
/* 800C0ED0 000BDE30  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800C0ED4 000BDE34  34 03 FF FF */	addic. r0, r3, -1
/* 800C0ED8 000BDE38  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800C0EDC 000BDE3C  40 80 02 50 */	bge .L_800C112C
/* 800C0EE0 000BDE40  48 15 71 91 */	bl rand
/* 800C0EE4 000BDE44  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C0EE8 000BDE48  C8 82 94 78 */	lfd f4, lbl_803E9678@sda21(r2)
/* 800C0EEC 000BDE4C  90 01 01 B4 */	stw r0, 0x1b4(r1)
/* 800C0EF0 000BDE50  3F C0 43 30 */	lis r30, 0x4330
/* 800C0EF4 000BDE54  C0 42 94 5C */	lfs f2, lbl_803E965C@sda21(r2)
/* 800C0EF8 000BDE58  93 C1 01 B0 */	stw r30, 0x1b0(r1)
/* 800C0EFC 000BDE5C  C0 22 94 58 */	lfs f1, lbl_803E9658@sda21(r2)
/* 800C0F00 000BDE60  C8 61 01 B0 */	lfd f3, 0x1b0(r1)
/* 800C0F04 000BDE64  C0 02 94 84 */	lfs f0, lbl_803E9684@sda21(r2)
/* 800C0F08 000BDE68  EC 63 20 28 */	fsubs f3, f3, f4
/* 800C0F0C 000BDE6C  EC 43 10 24 */	fdivs f2, f3, f2
/* 800C0F10 000BDE70  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C0F14 000BDE74  EC 00 00 72 */	fmuls f0, f0, f1
/* 800C0F18 000BDE78  FC 00 00 1E */	fctiwz f0, f0
/* 800C0F1C 000BDE7C  D8 01 01 A8 */	stfd f0, 0x1a8(r1)
/* 800C0F20 000BDE80  80 61 01 AC */	lwz r3, 0x1ac(r1)
/* 800C0F24 000BDE84  38 03 00 26 */	addi r0, r3, 0x26
/* 800C0F28 000BDE88  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800C0F2C 000BDE8C  83 BF 00 14 */	lwz r29, 0x14(r31)
/* 800C0F30 000BDE90  2C 1D 00 01 */	cmpwi r29, 1
/* 800C0F34 000BDE94  40 82 00 B0 */	bne .L_800C0FE4
/* 800C0F38 000BDE98  48 15 71 39 */	bl rand
/* 800C0F3C 000BDE9C  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C0F40 000BDEA0  C8 82 94 78 */	lfd f4, lbl_803E9678@sda21(r2)
/* 800C0F44 000BDEA4  90 01 01 AC */	stw r0, 0x1ac(r1)
/* 800C0F48 000BDEA8  C0 42 94 5C */	lfs f2, lbl_803E965C@sda21(r2)
/* 800C0F4C 000BDEAC  93 C1 01 A8 */	stw r30, 0x1a8(r1)
/* 800C0F50 000BDEB0  C0 22 94 58 */	lfs f1, lbl_803E9658@sda21(r2)
/* 800C0F54 000BDEB4  C8 61 01 A8 */	lfd f3, 0x1a8(r1)
/* 800C0F58 000BDEB8  C0 02 94 88 */	lfs f0, lbl_803E9688@sda21(r2)
/* 800C0F5C 000BDEBC  EC 63 20 28 */	fsubs f3, f3, f4
/* 800C0F60 000BDEC0  EC 43 10 24 */	fdivs f2, f3, f2
/* 800C0F64 000BDEC4  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C0F68 000BDEC8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800C0F6C 000BDECC  40 81 00 78 */	ble .L_800C0FE4
/* 800C0F70 000BDED0  38 00 00 03 */	li r0, 3
/* 800C0F74 000BDED4  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800C0F78 000BDED8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C0F7C 000BDEDC  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 800C0F80 000BDEE0  38 63 03 54 */	addi r3, r3, 0x354
/* 800C0F84 000BDEE4  48 05 EB 3D */	bl finishMotion__15PaniPikiAnimMgrFP19PaniAnimKeyListener
/* 800C0F88 000BDEE8  38 00 00 01 */	li r0, 1
/* 800C0F8C 000BDEEC  98 1F 00 1C */	stb r0, 0x1c(r31)
/* 800C0F90 000BDEF0  48 15 70 E1 */	bl rand
/* 800C0F94 000BDEF4  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C0F98 000BDEF8  C8 82 94 78 */	lfd f4, lbl_803E9678@sda21(r2)
/* 800C0F9C 000BDEFC  90 01 01 AC */	stw r0, 0x1ac(r1)
/* 800C0FA0 000BDF00  C0 42 94 5C */	lfs f2, lbl_803E965C@sda21(r2)
/* 800C0FA4 000BDF04  93 C1 01 A8 */	stw r30, 0x1a8(r1)
/* 800C0FA8 000BDF08  C0 22 94 58 */	lfs f1, lbl_803E9658@sda21(r2)
/* 800C0FAC 000BDF0C  C8 61 01 A8 */	lfd f3, 0x1a8(r1)
/* 800C0FB0 000BDF10  C0 02 94 8C */	lfs f0, lbl_803E968C@sda21(r2)
/* 800C0FB4 000BDF14  EC 63 20 28 */	fsubs f3, f3, f4
/* 800C0FB8 000BDF18  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800C0FBC 000BDF1C  EC 43 10 24 */	fdivs f2, f3, f2
/* 800C0FC0 000BDF20  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C0FC4 000BDF24  EC 00 00 72 */	fmuls f0, f0, f1
/* 800C0FC8 000BDF28  FC 00 00 1E */	fctiwz f0, f0
/* 800C0FCC 000BDF2C  D8 01 01 B0 */	stfd f0, 0x1b0(r1)
/* 800C0FD0 000BDF30  80 01 01 B4 */	lwz r0, 0x1b4(r1)
/* 800C0FD4 000BDF34  7C 60 1A 14 */	add r3, r0, r3
/* 800C0FD8 000BDF38  38 03 00 1E */	addi r0, r3, 0x1e
/* 800C0FDC 000BDF3C  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800C0FE0 000BDF40  48 00 01 44 */	b .L_800C1124
.L_800C0FE4:
/* 800C0FE4 000BDF44  48 15 70 8D */	bl rand
/* 800C0FE8 000BDF48  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C0FEC 000BDF4C  C8 82 94 78 */	lfd f4, lbl_803E9678@sda21(r2)
/* 800C0FF0 000BDF50  90 01 01 AC */	stw r0, 0x1ac(r1)
/* 800C0FF4 000BDF54  3F C0 43 30 */	lis r30, 0x4330
/* 800C0FF8 000BDF58  C0 42 94 5C */	lfs f2, lbl_803E965C@sda21(r2)
/* 800C0FFC 000BDF5C  93 C1 01 A8 */	stw r30, 0x1a8(r1)
/* 800C1000 000BDF60  C0 22 94 58 */	lfs f1, lbl_803E9658@sda21(r2)
/* 800C1004 000BDF64  C8 61 01 A8 */	lfd f3, 0x1a8(r1)
/* 800C1008 000BDF68  C0 02 94 90 */	lfs f0, lbl_803E9690@sda21(r2)
/* 800C100C 000BDF6C  EC 63 20 28 */	fsubs f3, f3, f4
/* 800C1010 000BDF70  EC 43 10 24 */	fdivs f2, f3, f2
/* 800C1014 000BDF74  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C1018 000BDF78  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800C101C 000BDF7C  40 81 00 C4 */	ble .L_800C10E0
/* 800C1020 000BDF80  48 15 70 51 */	bl rand
/* 800C1024 000BDF84  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C1028 000BDF88  C8 82 94 78 */	lfd f4, lbl_803E9678@sda21(r2)
/* 800C102C 000BDF8C  90 01 01 AC */	stw r0, 0x1ac(r1)
/* 800C1030 000BDF90  C0 42 94 5C */	lfs f2, lbl_803E965C@sda21(r2)
/* 800C1034 000BDF94  93 C1 01 A8 */	stw r30, 0x1a8(r1)
/* 800C1038 000BDF98  C0 22 94 58 */	lfs f1, lbl_803E9658@sda21(r2)
/* 800C103C 000BDF9C  C8 61 01 A8 */	lfd f3, 0x1a8(r1)
/* 800C1040 000BDFA0  C0 02 94 94 */	lfs f0, lbl_803E9694@sda21(r2)
/* 800C1044 000BDFA4  EC 63 20 28 */	fsubs f3, f3, f4
/* 800C1048 000BDFA8  EC 43 10 24 */	fdivs f2, f3, f2
/* 800C104C 000BDFAC  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C1050 000BDFB0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800C1054 000BDFB4  40 81 00 30 */	ble .L_800C1084
/* 800C1058 000BDFB8  38 00 00 00 */	li r0, 0
/* 800C105C 000BDFBC  2C 1D 00 00 */	cmpwi r29, 0
/* 800C1060 000BDFC0  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800C1064 000BDFC4  41 82 00 4C */	beq .L_800C10B0
/* 800C1068 000BDFC8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C106C 000BDFCC  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 800C1070 000BDFD0  38 63 03 54 */	addi r3, r3, 0x354
/* 800C1074 000BDFD4  48 05 EA 4D */	bl finishMotion__15PaniPikiAnimMgrFP19PaniAnimKeyListener
/* 800C1078 000BDFD8  38 00 00 01 */	li r0, 1
/* 800C107C 000BDFDC  98 1F 00 1C */	stb r0, 0x1c(r31)
/* 800C1080 000BDFE0  48 00 00 30 */	b .L_800C10B0
.L_800C1084:
/* 800C1084 000BDFE4  3B C0 00 01 */	li r30, 1
/* 800C1088 000BDFE8  2C 1D 00 02 */	cmpwi r29, 2
/* 800C108C 000BDFEC  93 DF 00 14 */	stw r30, 0x14(r31)
/* 800C1090 000BDFF0  41 82 00 20 */	beq .L_800C10B0
/* 800C1094 000BDFF4  2C 1D 00 01 */	cmpwi r29, 1
/* 800C1098 000BDFF8  41 82 00 18 */	beq .L_800C10B0
/* 800C109C 000BDFFC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C10A0 000BE000  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 800C10A4 000BE004  38 63 03 54 */	addi r3, r3, 0x354
/* 800C10A8 000BE008  48 05 EA 19 */	bl finishMotion__15PaniPikiAnimMgrFP19PaniAnimKeyListener
/* 800C10AC 000BE00C  9B DF 00 1C */	stb r30, 0x1c(r31)
.L_800C10B0:
/* 800C10B0 000BE010  48 15 6F C1 */	bl rand
/* 800C10B4 000BE014  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C10B8 000BE018  C0 0D BA 20 */	lfs f0, lbl_803E0740@sda21(r13)
/* 800C10BC 000BE01C  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800C10C0 000BE020  C0 0D BA 24 */	lfs f0, lbl_803E0744@sda21(r13)
/* 800C10C4 000BE024  D0 03 00 04 */	stfs f0, 4(r3)
/* 800C10C8 000BE028  C0 0D BA 28 */	lfs f0, lbl_803E0748@sda21(r13)
/* 800C10CC 000BE02C  D0 03 00 08 */	stfs f0, 8(r3)
/* 800C10D0 000BE030  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800C10D4 000BE034  38 03 00 78 */	addi r0, r3, 0x78
/* 800C10D8 000BE038  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800C10DC 000BE03C  48 00 00 48 */	b .L_800C1124
.L_800C10E0:
/* 800C10E0 000BE040  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800C10E4 000BE044  2C 1D 00 02 */	cmpwi r29, 2
/* 800C10E8 000BE048  38 00 00 02 */	li r0, 2
/* 800C10EC 000BE04C  38 63 00 78 */	addi r3, r3, 0x78
/* 800C10F0 000BE050  90 7F 00 18 */	stw r3, 0x18(r31)
/* 800C10F4 000BE054  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800C10F8 000BE058  40 82 00 0C */	bne .L_800C1104
/* 800C10FC 000BE05C  2C 1D 00 01 */	cmpwi r29, 1
/* 800C1100 000BE060  41 82 00 24 */	beq .L_800C1124
.L_800C1104:
/* 800C1104 000BE064  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C1108 000BE068  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 800C110C 000BE06C  38 63 03 54 */	addi r3, r3, 0x354
/* 800C1110 000BE070  48 05 E9 B1 */	bl finishMotion__15PaniPikiAnimMgrFP19PaniAnimKeyListener
/* 800C1114 000BE074  38 00 00 01 */	li r0, 1
/* 800C1118 000BE078  98 1F 00 1C */	stb r0, 0x1c(r31)
/* 800C111C 000BE07C  38 60 00 00 */	li r3, 0
/* 800C1120 000BE080  48 00 01 04 */	b .L_800C1224
.L_800C1124:
/* 800C1124 000BE084  38 60 00 00 */	li r3, 0
/* 800C1128 000BE088  48 00 00 FC */	b .L_800C1224
.L_800C112C:
/* 800C112C 000BE08C  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 800C1130 000BE090  2C 00 00 02 */	cmpwi r0, 2
/* 800C1134 000BE094  40 82 00 0C */	bne .L_800C1140
/* 800C1138 000BE098  38 00 00 01 */	li r0, 1
/* 800C113C 000BE09C  90 1F 00 18 */	stw r0, 0x18(r31)
.L_800C1140:
/* 800C1140 000BE0A0  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 800C1144 000BE0A4  2C 00 00 03 */	cmpwi r0, 3
/* 800C1148 000BE0A8  40 82 00 20 */	bne .L_800C1168
/* 800C114C 000BE0AC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C1150 000BE0B0  C0 0D BA 2C */	lfs f0, lbl_803E074C@sda21(r13)
/* 800C1154 000BE0B4  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800C1158 000BE0B8  C0 0D BA 30 */	lfs f0, lbl_803E0750@sda21(r13)
/* 800C115C 000BE0BC  D0 03 00 04 */	stfs f0, 4(r3)
/* 800C1160 000BE0C0  C0 0D BA 34 */	lfs f0, lbl_803E0754@sda21(r13)
/* 800C1164 000BE0C4  D0 03 00 08 */	stfs f0, 8(r3)
.L_800C1168:
/* 800C1168 000BE0C8  C0 02 94 70 */	lfs f0, lbl_803E9670@sda21(r2)
/* 800C116C 000BE0CC  38 A1 01 5C */	addi r5, r1, 0x15c
/* 800C1170 000BE0D0  D0 01 01 64 */	stfs f0, 0x164(r1)
/* 800C1174 000BE0D4  D0 01 01 60 */	stfs f0, 0x160(r1)
/* 800C1178 000BE0D8  D0 01 01 5C */	stfs f0, 0x15c(r1)
/* 800C117C 000BE0DC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C1180 000BE0E0  38 83 00 A4 */	addi r4, r3, 0xa4
/* 800C1184 000BE0E4  4B FC C3 B9 */	bl getAvoid__8CreatureFR8Vector3fR8Vector3f
/* 800C1188 000BE0E8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800C118C 000BE0EC  41 82 00 94 */	beq .L_800C1220
/* 800C1190 000BE0F0  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C1194 000BE0F4  C0 22 94 88 */	lfs f1, lbl_803E9688@sda21(r2)
/* 800C1198 000BE0F8  48 00 AB CD */	bl getSpeed__4PikiFf
/* 800C119C 000BE0FC  C0 01 01 5C */	lfs f0, 0x15c(r1)
/* 800C11A0 000BE100  EC 00 00 72 */	fmuls f0, f0, f1
/* 800C11A4 000BE104  D0 01 00 78 */	stfs f0, 0x78(r1)
/* 800C11A8 000BE108  C0 01 00 78 */	lfs f0, 0x78(r1)
/* 800C11AC 000BE10C  D0 01 01 10 */	stfs f0, 0x110(r1)
/* 800C11B0 000BE110  C0 01 01 60 */	lfs f0, 0x160(r1)
/* 800C11B4 000BE114  EC 00 00 72 */	fmuls f0, f0, f1
/* 800C11B8 000BE118  D0 01 01 14 */	stfs f0, 0x114(r1)
/* 800C11BC 000BE11C  C0 01 01 64 */	lfs f0, 0x164(r1)
/* 800C11C0 000BE120  EC 00 00 72 */	fmuls f0, f0, f1
/* 800C11C4 000BE124  D0 01 01 18 */	stfs f0, 0x118(r1)
/* 800C11C8 000BE128  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C11CC 000BE12C  C0 01 01 10 */	lfs f0, 0x110(r1)
/* 800C11D0 000BE130  C0 23 00 A4 */	lfs f1, 0xa4(r3)
/* 800C11D4 000BE134  38 83 00 A4 */	addi r4, r3, 0xa4
/* 800C11D8 000BE138  EC 01 00 2A */	fadds f0, f1, f0
/* 800C11DC 000BE13C  D0 01 00 F8 */	stfs f0, 0xf8(r1)
/* 800C11E0 000BE140  C0 01 00 F8 */	lfs f0, 0xf8(r1)
/* 800C11E4 000BE144  D0 01 01 1C */	stfs f0, 0x11c(r1)
/* 800C11E8 000BE148  C0 23 00 A8 */	lfs f1, 0xa8(r3)
/* 800C11EC 000BE14C  C0 01 01 14 */	lfs f0, 0x114(r1)
/* 800C11F0 000BE150  EC 01 00 2A */	fadds f0, f1, f0
/* 800C11F4 000BE154  D0 01 01 20 */	stfs f0, 0x120(r1)
/* 800C11F8 000BE158  C0 23 00 AC */	lfs f1, 0xac(r3)
/* 800C11FC 000BE15C  C0 01 01 18 */	lfs f0, 0x118(r1)
/* 800C1200 000BE160  EC 01 00 2A */	fadds f0, f1, f0
/* 800C1204 000BE164  D0 01 01 24 */	stfs f0, 0x124(r1)
/* 800C1208 000BE168  80 61 01 1C */	lwz r3, 0x11c(r1)
/* 800C120C 000BE16C  80 01 01 20 */	lwz r0, 0x120(r1)
/* 800C1210 000BE170  90 64 00 00 */	stw r3, 0(r4)
/* 800C1214 000BE174  90 04 00 04 */	stw r0, 4(r4)
/* 800C1218 000BE178  80 01 01 24 */	lwz r0, 0x124(r1)
/* 800C121C 000BE17C  90 04 00 08 */	stw r0, 8(r4)
.L_800C1220:
/* 800C1220 000BE180  38 60 00 00 */	li r3, 0
.L_800C1224:
/* 800C1224 000BE184  80 01 01 CC */	lwz r0, 0x1cc(r1)
/* 800C1228 000BE188  83 E1 01 C4 */	lwz r31, 0x1c4(r1)
/* 800C122C 000BE18C  83 C1 01 C0 */	lwz r30, 0x1c0(r1)
/* 800C1230 000BE190  83 A1 01 BC */	lwz r29, 0x1bc(r1)
/* 800C1234 000BE194  38 21 01 C8 */	addi r1, r1, 0x1c8
/* 800C1238 000BE198  7C 08 03 A6 */	mtlr r0
/* 800C123C 000BE19C  4E 80 00 20 */	blr 
.endfn exec__13ActRandomBoidFv

.fn getInfo__13ActRandomBoidFPc, global
/* 800C1240 000BE1A0  7C 08 02 A6 */	mflr r0
/* 800C1244 000BE1A4  90 01 00 04 */	stw r0, 4(r1)
/* 800C1248 000BE1A8  4C C6 31 82 */	crclr 6
/* 800C124C 000BE1AC  94 21 FF F8 */	stwu r1, -8(r1)
/* 800C1250 000BE1B0  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800C1254 000BE1B4  3C 60 80 2B */	lis r3, stateName@ha
/* 800C1258 000BE1B8  54 05 10 3A */	slwi r5, r0, 2
/* 800C125C 000BE1BC  38 03 76 E8 */	addi r0, r3, stateName@l
/* 800C1260 000BE1C0  7C 60 2A 14 */	add r3, r0, r5
/* 800C1264 000BE1C4  80 A3 00 00 */	lwz r5, 0(r3)
/* 800C1268 000BE1C8  38 64 00 00 */	addi r3, r4, 0
/* 800C126C 000BE1CC  38 8D BA 48 */	addi r4, r13, lbl_803E0768@sda21
/* 800C1270 000BE1D0  48 15 53 29 */	bl sprintf
/* 800C1274 000BE1D4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800C1278 000BE1D8  38 21 00 08 */	addi r1, r1, 8
/* 800C127C 000BE1DC  7C 08 03 A6 */	mtlr r0
/* 800C1280 000BE1E0  4E 80 00 20 */	blr 
.endfn getInfo__13ActRandomBoidFPc

.fn __dt__13ActRandomBoidFv, weak
/* 800C1284 000BE1E4  7C 08 02 A6 */	mflr r0
/* 800C1288 000BE1E8  90 01 00 04 */	stw r0, 4(r1)
/* 800C128C 000BE1EC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800C1290 000BE1F0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800C1294 000BE1F4  3B E4 00 00 */	addi r31, r4, 0
/* 800C1298 000BE1F8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800C129C 000BE1FC  7C 7E 1B 79 */	or. r30, r3, r3
/* 800C12A0 000BE200  41 82 00 2C */	beq .L_800C12CC
/* 800C12A4 000BE204  3C 60 80 2B */	lis r3, __vt__13ActRandomBoid@ha
/* 800C12A8 000BE208  38 03 77 34 */	addi r0, r3, __vt__13ActRandomBoid@l
/* 800C12AC 000BE20C  90 1E 00 00 */	stw r0, 0(r30)
/* 800C12B0 000BE210  38 7E 00 00 */	addi r3, r30, 0
/* 800C12B4 000BE214  38 80 00 00 */	li r4, 0
/* 800C12B8 000BE218  48 00 2B 51 */	bl __dt__6ActionFv
/* 800C12BC 000BE21C  7F E0 07 35 */	extsh. r0, r31
/* 800C12C0 000BE220  40 81 00 0C */	ble .L_800C12CC
/* 800C12C4 000BE224  7F C3 F3 78 */	mr r3, r30
/* 800C12C8 000BE228  4B F8 5E E5 */	bl __dl__FPv
.L_800C12CC:
/* 800C12CC 000BE22C  7F C3 F3 78 */	mr r3, r30
/* 800C12D0 000BE230  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800C12D4 000BE234  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800C12D8 000BE238  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800C12DC 000BE23C  38 21 00 18 */	addi r1, r1, 0x18
/* 800C12E0 000BE240  7C 08 03 A6 */	mtlr r0
/* 800C12E4 000BE244  4E 80 00 20 */	blr 
.endfn __dt__13ActRandomBoidFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B76B8, local
	.asciz "aiRandomBoid.cpp"
.endobj lbl_802B76B8
.balign 4
.obj lbl_802B76CC, local
	.asciz "aiRandomBoid"
.endobj lbl_802B76CC
.balign 4
.obj lbl_802B76DC, local # Shift-JIS
	.4byte 0x83898393
	.4byte 0x835F8380
	.byte 0
.endobj lbl_802B76DC
.balign 4
.obj stateName, local
	.4byte lbl_802B76DC
	.4byte lbl_803E0758
	.4byte lbl_803E0760
.endobj stateName
.balign 4
.obj lbl_802B76F4, local
	.asciz "ActRandomBoid"
.endobj lbl_802B76F4
.balign 4
.obj lbl_802B7704, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B7704
.balign 4
.obj lbl_802B7714, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.endobj lbl_802B7714
.obj lbl_802B7720, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B7720
.obj __vt__13ActRandomBoid, global
	.4byte __RTTI__13ActRandomBoid
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
	.4byte __dt__13ActRandomBoidFv
	.4byte init__13ActRandomBoidFP8Creature
	.4byte exec__13ActRandomBoidFv
	.4byte cleanup__13ActRandomBoidFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__13ActRandomBoidFPc
.endobj __vt__13ActRandomBoid
.balign 4
.obj lbl_802B7798, local
	.asciz "ActRandomBoid::Initialiser"
.endobj lbl_802B7798
.balign 4
.obj lbl_802B77B4, local
	.asciz "Action::Initialiser"
.endobj lbl_802B77B4
.balign 4
.obj lbl_802B77C8, local
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte 0
.endobj lbl_802B77C8
.obj __vt__Q213ActRandomBoid11Initialiser, global
	.4byte __RTTI__Q213ActRandomBoid11Initialiser
	.4byte 0
	.4byte initialise__Q213ActRandomBoid11InitialiserFP6Action
.endobj __vt__Q213ActRandomBoid11Initialiser
.balign 4
.obj lbl_802B77E0, local
	.asciz "PaniAnimKeyListener"
.endobj lbl_802B77E0
.balign 4
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
.obj lbl_802B7800, local
	.asciz "ActRandomBoid::AnimListener"
.endobj lbl_802B7800
.balign 4
.obj lbl_802B781C, local
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0
	.4byte 0
.endobj lbl_802B781C
.obj __vt__Q213ActRandomBoid12AnimListener, global
	.4byte __RTTI__Q213ActRandomBoid12AnimListener
	.4byte 0
	.4byte animationKeyUpdated__Q213ActRandomBoid12AnimListenerFR16PaniAnimKeyEvent
.endobj __vt__Q213ActRandomBoid12AnimListener
.balign 4
.obj lbl_802B7834, local
	.4byte .L_800A7908
	.4byte .L_800A7930
	.4byte .L_800A7944
	.4byte .L_800A7958
	.4byte .L_800A796C
	.4byte .L_800A7980
	.4byte .L_800A7994
	.4byte .L_800A79A8
	.4byte .L_800A791C
	.4byte .L_800A79D0
	.4byte .L_800A79BC
.endobj lbl_802B7834

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E0708, local
	.float 0.0
.endobj lbl_803E0708
.obj lbl_803E070C, local
	.float 0.0
.endobj lbl_803E070C
.obj lbl_803E0710, local
	.float 0.0
.endobj lbl_803E0710
.obj lbl_803E0714, local
	.float 0.0
.endobj lbl_803E0714
.obj lbl_803E0718, local
	.float 0.0
.endobj lbl_803E0718
.obj lbl_803E071C, local
	.float 0.0
.endobj lbl_803E071C
.obj lbl_803E0720, local
	.float 0.0
.endobj lbl_803E0720
.obj lbl_803E0724, local
	.float 0.0
.endobj lbl_803E0724
.obj lbl_803E0728, local
	.float 0.0
.endobj lbl_803E0728
.obj lbl_803E072C, local
	.float 0.0
.endobj lbl_803E072C
.obj lbl_803E0730, local
	.float 0.0
.endobj lbl_803E0730
.obj lbl_803E0734, local
	.float 0.0
.endobj lbl_803E0734
.obj lbl_803E0738, local
	.float 0.0
.endobj lbl_803E0738
.obj lbl_803E073C, local
	.float 0.0
.endobj lbl_803E073C
.obj lbl_803E0740, local
	.float 0.0
.endobj lbl_803E0740
.obj lbl_803E0744, local
	.float 0.0
.endobj lbl_803E0744
.obj lbl_803E0748, local
	.float 0.0
.endobj lbl_803E0748
.obj lbl_803E074C, local
	.float 0.0
.endobj lbl_803E074C
.obj lbl_803E0750, local
	.float 0.0
.endobj lbl_803E0750
.obj lbl_803E0754, local
	.float 0.0
.endobj lbl_803E0754
.balign 4
.obj lbl_803E0758, local
	.asciz "Boid"
.endobj lbl_803E0758
.balign 4
.obj lbl_803E0760, local # Shift-JIS
	.4byte 0x92E28E7E
	.4byte 0x00000000
.endobj lbl_803E0760
.balign 4
.obj lbl_803E0768, local
	.asciz "%s"
.endobj lbl_803E0768
.balign 4
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B7704
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E0774, local
	.asciz "Action"
.endobj lbl_803E0774
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E0774
	.4byte lbl_802B7714
.endobj __RTTI__6Action
.obj __RTTI__13ActRandomBoid, local
	.4byte lbl_802B76F4
	.4byte lbl_802B7720
.endobj __RTTI__13ActRandomBoid
.obj __RTTI__Q26Action11Initialiser, local
	.4byte lbl_802B77B4
	.4byte 0
.endobj __RTTI__Q26Action11Initialiser
.obj __RTTI__Q213ActRandomBoid11Initialiser, local
	.4byte lbl_802B7798
	.4byte lbl_802B77C8
.endobj __RTTI__Q213ActRandomBoid11Initialiser
.obj __RTTI__19PaniAnimKeyListener, local
	.4byte lbl_802B77E0
	.4byte 0
.endobj __RTTI__19PaniAnimKeyListener
.obj __RTTI__Q213ActRandomBoid12AnimListener, local
	.4byte lbl_802B7800
	.4byte lbl_802B781C
.endobj __RTTI__Q213ActRandomBoid12AnimListener

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9658, local
	.float 1.0
.endobj lbl_803E9658
.obj lbl_803E965C, local
	.float 32767.0
.endobj lbl_803E965C
.obj lbl_803E9660, local
	.float 2.0
.endobj lbl_803E9660
.obj lbl_803E9664, local
	.float 3.1415927
.endobj lbl_803E9664
.obj lbl_803E9668, local
	.float 0.8
.endobj lbl_803E9668
.obj lbl_803E966C, local
	.float -1.2
.endobj lbl_803E966C
.obj lbl_803E9670, local
	.float 0.0
.endobj lbl_803E9670
.balign 8
.obj lbl_803E9678, local
	.8byte 0x4330000080000000
.endobj lbl_803E9678
.obj lbl_803E9680, local
	.float 10.0
.endobj lbl_803E9680
.obj lbl_803E9684, local
	.float 12.0
.endobj lbl_803E9684
.obj lbl_803E9688, local
	.float 0.5
.endobj lbl_803E9688
.obj lbl_803E968C, local
	.float 50.0
.endobj lbl_803E968C
.obj lbl_803E9690, local
	.float 0.65
.endobj lbl_803E9690
.obj lbl_803E9694, local
	.float 0.75
.endobj lbl_803E9694
