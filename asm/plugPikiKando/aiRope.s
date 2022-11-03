.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__7ActRopeFP4Piki
__ct__7ActRopeFP4Piki:
/* 800C1E24 000BED84  7C 08 02 A6 */	mflr r0
/* 800C1E28 000BED88  38 A0 00 01 */	li r5, 1
/* 800C1E2C 000BED8C  90 01 00 04 */	stw r0, 4(r1)
/* 800C1E30 000BED90  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800C1E34 000BED94  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800C1E38 000BED98  3B E3 00 00 */	addi r31, r3, 0
/* 800C1E3C 000BED9C  48 00 1F 95 */	bl __ct__6ActionFP4Pikib
/* 800C1E40 000BEDA0  3C 60 80 2B */	lis r3, __vt__7ActRope@ha
/* 800C1E44 000BEDA4  38 03 79 BC */	addi r0, r3, __vt__7ActRope@l
/* 800C1E48 000BEDA8  90 1F 00 00 */	stw r0, 0(r31)
/* 800C1E4C 000BEDAC  38 8D BA F0 */	addi r4, r13, lbl_803E0810@sda21
/* 800C1E50 000BEDB0  38 00 FF FF */	li r0, -1
/* 800C1E54 000BEDB4  C0 02 94 D8 */	lfs f0, lbl_803E96D8@sda21(r2)
/* 800C1E58 000BEDB8  7F E3 FB 78 */	mr r3, r31
/* 800C1E5C 000BEDBC  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 800C1E60 000BEDC0  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 800C1E64 000BEDC4  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 800C1E68 000BEDC8  90 9F 00 10 */	stw r4, 0x10(r31)
/* 800C1E6C 000BEDCC  B0 1F 00 08 */	sth r0, 8(r31)
/* 800C1E70 000BEDD0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800C1E74 000BEDD4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800C1E78 000BEDD8  38 21 00 18 */	addi r1, r1, 0x18
/* 800C1E7C 000BEDDC  7C 08 03 A6 */	mtlr r0
/* 800C1E80 000BEDE0  4E 80 00 20 */	blr 

.global init__7ActRopeFP8Creature
init__7ActRopeFP8Creature:
/* 800C1E84 000BEDE4  7C 08 02 A6 */	mflr r0
/* 800C1E88 000BEDE8  38 80 00 3E */	li r4, 0x3e
/* 800C1E8C 000BEDEC  90 01 00 04 */	stw r0, 4(r1)
/* 800C1E90 000BEDF0  94 21 FF 88 */	stwu r1, -0x78(r1)
/* 800C1E94 000BEDF4  93 E1 00 74 */	stw r31, 0x74(r1)
/* 800C1E98 000BEDF8  3B E3 00 00 */	addi r31, r3, 0
/* 800C1E9C 000BEDFC  38 61 00 20 */	addi r3, r1, 0x20
/* 800C1EA0 000BEE00  93 C1 00 70 */	stw r30, 0x70(r1)
/* 800C1EA4 000BEE04  48 05 D0 B5 */	bl __ct__14PaniMotionInfoFi
/* 800C1EA8 000BEE08  3B C3 00 00 */	addi r30, r3, 0
/* 800C1EAC 000BEE0C  38 61 00 28 */	addi r3, r1, 0x28
/* 800C1EB0 000BEE10  38 80 00 3E */	li r4, 0x3e
/* 800C1EB4 000BEE14  48 05 D0 A5 */	bl __ct__14PaniMotionInfoFi
/* 800C1EB8 000BEE18  7C 64 1B 78 */	mr r4, r3
/* 800C1EBC 000BEE1C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C1EC0 000BEE20  7F C5 F3 78 */	mr r5, r30
/* 800C1EC4 000BEE24  48 00 8B 15 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800C1EC8 000BEE28  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C1ECC 000BEE2C  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 800C1ED0 000BEE30  60 00 00 80 */	ori r0, r0, 0x80
/* 800C1ED4 000BEE34  90 03 00 C8 */	stw r0, 0xc8(r3)
/* 800C1ED8 000BEE38  48 15 61 99 */	bl rand
/* 800C1EDC 000BEE3C  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800C1EE0 000BEE40  C8 42 94 F0 */	lfd f2, lbl_803E96F0@sda21(r2)
/* 800C1EE4 000BEE44  90 01 00 6C */	stw r0, 0x6c(r1)
/* 800C1EE8 000BEE48  3C 00 43 30 */	lis r0, 0x4330
/* 800C1EEC 000BEE4C  C0 82 94 E0 */	lfs f4, lbl_803E96E0@sda21(r2)
/* 800C1EF0 000BEE50  90 01 00 68 */	stw r0, 0x68(r1)
/* 800C1EF4 000BEE54  C0 62 94 DC */	lfs f3, lbl_803E96DC@sda21(r2)
/* 800C1EF8 000BEE58  C8 21 00 68 */	lfd f1, 0x68(r1)
/* 800C1EFC 000BEE5C  C0 02 94 EC */	lfs f0, lbl_803E96EC@sda21(r2)
/* 800C1F00 000BEE60  EC A1 10 28 */	fsubs f5, f1, f2
/* 800C1F04 000BEE64  C0 22 94 E8 */	lfs f1, lbl_803E96E8@sda21(r2)
/* 800C1F08 000BEE68  C0 42 94 E4 */	lfs f2, lbl_803E96E4@sda21(r2)
/* 800C1F0C 000BEE6C  EC 85 20 24 */	fdivs f4, f5, f4
/* 800C1F10 000BEE70  EC 63 01 32 */	fmuls f3, f3, f4
/* 800C1F14 000BEE74  EC 03 00 28 */	fsubs f0, f3, f0
/* 800C1F18 000BEE78  EC 01 00 32 */	fmuls f0, f1, f0
/* 800C1F1C 000BEE7C  EC 02 00 2A */	fadds f0, f2, f0
/* 800C1F20 000BEE80  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 800C1F24 000BEE84  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C1F28 000BEE88  80 03 02 AC */	lwz r0, 0x2ac(r3)
/* 800C1F2C 000BEE8C  28 00 00 00 */	cmplwi r0, 0
/* 800C1F30 000BEE90  41 82 00 0C */	beq .L_800C1F3C
/* 800C1F34 000BEE94  38 00 00 03 */	li r0, 3
/* 800C1F38 000BEE98  98 03 04 08 */	stb r0, 0x408(r3)
.L_800C1F3C:
/* 800C1F3C 000BEE9C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C1F40 000BEEA0  80 03 01 88 */	lwz r0, 0x188(r3)
/* 800C1F44 000BEEA4  28 00 00 00 */	cmplwi r0, 0
/* 800C1F48 000BEEA8  41 82 00 84 */	beq .L_800C1FCC
/* 800C1F4C 000BEEAC  C0 02 94 D8 */	lfs f0, lbl_803E96D8@sda21(r2)
/* 800C1F50 000BEEB0  38 81 00 48 */	addi r4, r1, 0x48
/* 800C1F54 000BEEB4  D0 01 00 50 */	stfs f0, 0x50(r1)
/* 800C1F58 000BEEB8  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 800C1F5C 000BEEBC  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 800C1F60 000BEEC0  D0 01 00 5C */	stfs f0, 0x5c(r1)
/* 800C1F64 000BEEC4  D0 01 00 58 */	stfs f0, 0x58(r1)
/* 800C1F68 000BEEC8  D0 01 00 54 */	stfs f0, 0x54(r1)
/* 800C1F6C 000BEECC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800C1F70 000BEED0  80 63 01 88 */	lwz r3, 0x188(r3)
/* 800C1F74 000BEED4  4B FC 6C 19 */	bl makeTube__8CollPartFR4Tube
/* 800C1F78 000BEED8  C0 02 94 D8 */	lfs f0, lbl_803E96D8@sda21(r2)
/* 800C1F7C 000BEEDC  38 61 00 48 */	addi r3, r1, 0x48
/* 800C1F80 000BEEE0  38 A1 00 3C */	addi r5, r1, 0x3c
/* 800C1F84 000BEEE4  D0 01 00 44 */	stfs f0, 0x44(r1)
/* 800C1F88 000BEEE8  38 C1 00 30 */	addi r6, r1, 0x30
/* 800C1F8C 000BEEEC  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 800C1F90 000BEEF0  D0 01 00 40 */	stfs f0, 0x40(r1)
/* 800C1F94 000BEEF4  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 800C1F98 000BEEF8  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 800C1F9C 000BEEFC  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 800C1FA0 000BEF00  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800C1FA4 000BEF04  C0 24 01 94 */	lfs f1, 0x194(r4)
/* 800C1FA8 000BEF08  38 84 00 94 */	addi r4, r4, 0x94
/* 800C1FAC 000BEF0C  4B FC 58 E5 */	bl getPosGradient__4TubeFR8Vector3ffR8Vector3fR8Vector3f
/* 800C1FB0 000BEF10  80 61 00 30 */	lwz r3, 0x30(r1)
/* 800C1FB4 000BEF14  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800C1FB8 000BEF18  90 7F 00 18 */	stw r3, 0x18(r31)
/* 800C1FBC 000BEF1C  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 800C1FC0 000BEF20  80 01 00 38 */	lwz r0, 0x38(r1)
/* 800C1FC4 000BEF24  90 1F 00 20 */	stw r0, 0x20(r31)
/* 800C1FC8 000BEF28  48 00 00 1C */	b .L_800C1FE4
.L_800C1FCC:
/* 800C1FCC 000BEF2C  C0 0D BA F8 */	lfs f0, lbl_803E0818@sda21(r13)
/* 800C1FD0 000BEF30  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 800C1FD4 000BEF34  C0 0D BA FC */	lfs f0, lbl_803E081C@sda21(r13)
/* 800C1FD8 000BEF38  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 800C1FDC 000BEF3C  C0 0D BB 00 */	lfs f0, lbl_803E0820@sda21(r13)
/* 800C1FE0 000BEF40  D0 1F 00 20 */	stfs f0, 0x20(r31)
.L_800C1FE4:
/* 800C1FE4 000BEF44  80 01 00 7C */	lwz r0, 0x7c(r1)
/* 800C1FE8 000BEF48  83 E1 00 74 */	lwz r31, 0x74(r1)
/* 800C1FEC 000BEF4C  83 C1 00 70 */	lwz r30, 0x70(r1)
/* 800C1FF0 000BEF50  38 21 00 78 */	addi r1, r1, 0x78
/* 800C1FF4 000BEF54  7C 08 03 A6 */	mtlr r0
/* 800C1FF8 000BEF58  4E 80 00 20 */	blr 

.global exec__7ActRopeFv
exec__7ActRopeFv:
/* 800C1FFC 000BEF5C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800C2000 000BEF60  80 A3 00 0C */	lwz r5, 0xc(r3)
/* 800C2004 000BEF64  80 05 01 88 */	lwz r0, 0x188(r5)
/* 800C2008 000BEF68  28 00 00 00 */	cmplwi r0, 0
/* 800C200C 000BEF6C  40 82 00 0C */	bne .L_800C2018
/* 800C2010 000BEF70  38 60 00 01 */	li r3, 1
/* 800C2014 000BEF74  48 00 00 50 */	b .L_800C2064
.L_800C2018:
/* 800C2018 000BEF78  C0 43 00 14 */	lfs f2, 0x14(r3)
/* 800C201C 000BEF7C  C0 03 00 18 */	lfs f0, 0x18(r3)
/* 800C2020 000BEF80  C0 23 00 20 */	lfs f1, 0x20(r3)
/* 800C2024 000BEF84  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800C2028 000BEF88  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C202C 000BEF8C  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 800C2030 000BEF90  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 800C2034 000BEF94  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 800C2038 000BEF98  C0 03 00 1C */	lfs f0, 0x1c(r3)
/* 800C203C 000BEF9C  38 60 00 00 */	li r3, 0
/* 800C2040 000BEFA0  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800C2044 000BEFA4  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 800C2048 000BEFA8  D0 21 00 28 */	stfs f1, 0x28(r1)
/* 800C204C 000BEFAC  80 81 00 20 */	lwz r4, 0x20(r1)
/* 800C2050 000BEFB0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800C2054 000BEFB4  90 85 00 70 */	stw r4, 0x70(r5)
/* 800C2058 000BEFB8  90 05 00 74 */	stw r0, 0x74(r5)
/* 800C205C 000BEFBC  80 01 00 28 */	lwz r0, 0x28(r1)
/* 800C2060 000BEFC0  90 05 00 78 */	stw r0, 0x78(r5)
.L_800C2064:
/* 800C2064 000BEFC4  38 21 00 30 */	addi r1, r1, 0x30
/* 800C2068 000BEFC8  4E 80 00 20 */	blr 

.global cleanup__7ActRopeFv
cleanup__7ActRopeFv:
/* 800C206C 000BEFCC  7C 08 02 A6 */	mflr r0
/* 800C2070 000BEFD0  90 01 00 04 */	stw r0, 4(r1)
/* 800C2074 000BEFD4  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800C2078 000BEFD8  C0 4D BB 04 */	lfs f2, lbl_803E0824@sda21(r13)
/* 800C207C 000BEFDC  C0 03 00 18 */	lfs f0, 0x18(r3)
/* 800C2080 000BEFE0  C0 23 00 20 */	lfs f1, 0x20(r3)
/* 800C2084 000BEFE4  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800C2088 000BEFE8  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800C208C 000BEFEC  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 800C2090 000BEFF0  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 800C2094 000BEFF4  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 800C2098 000BEFF8  C0 03 00 1C */	lfs f0, 0x1c(r3)
/* 800C209C 000BEFFC  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800C20A0 000BF000  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 800C20A4 000BF004  D0 21 00 28 */	stfs f1, 0x28(r1)
/* 800C20A8 000BF008  80 A3 00 0C */	lwz r5, 0xc(r3)
/* 800C20AC 000BF00C  80 81 00 20 */	lwz r4, 0x20(r1)
/* 800C20B0 000BF010  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800C20B4 000BF014  90 85 00 70 */	stw r4, 0x70(r5)
/* 800C20B8 000BF018  90 05 00 74 */	stw r0, 0x74(r5)
/* 800C20BC 000BF01C  80 01 00 28 */	lwz r0, 0x28(r1)
/* 800C20C0 000BF020  90 05 00 78 */	stw r0, 0x78(r5)
/* 800C20C4 000BF024  80 A3 00 0C */	lwz r5, 0xc(r3)
/* 800C20C8 000BF028  80 85 00 70 */	lwz r4, 0x70(r5)
/* 800C20CC 000BF02C  80 05 00 74 */	lwz r0, 0x74(r5)
/* 800C20D0 000BF030  90 85 00 A4 */	stw r4, 0xa4(r5)
/* 800C20D4 000BF034  90 05 00 A8 */	stw r0, 0xa8(r5)
/* 800C20D8 000BF038  80 05 00 78 */	lwz r0, 0x78(r5)
/* 800C20DC 000BF03C  90 05 00 AC */	stw r0, 0xac(r5)
/* 800C20E0 000BF040  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800C20E4 000BF044  80 04 00 C8 */	lwz r0, 0xc8(r4)
/* 800C20E8 000BF048  54 00 06 6E */	rlwinm r0, r0, 0, 0x19, 0x17
/* 800C20EC 000BF04C  90 04 00 C8 */	stw r0, 0xc8(r4)
/* 800C20F0 000BF050  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800C20F4 000BF054  4B FC E7 85 */	bl endStickObject__8CreatureFv
/* 800C20F8 000BF058  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800C20FC 000BF05C  38 21 00 30 */	addi r1, r1, 0x30
/* 800C2100 000BF060  7C 08 03 A6 */	mtlr r0
/* 800C2104 000BF064  4E 80 00 20 */	blr 

.global __dt__7ActRopeFv
__dt__7ActRopeFv:
/* 800C2108 000BF068  7C 08 02 A6 */	mflr r0
/* 800C210C 000BF06C  90 01 00 04 */	stw r0, 4(r1)
/* 800C2110 000BF070  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800C2114 000BF074  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800C2118 000BF078  3B E4 00 00 */	addi r31, r4, 0
/* 800C211C 000BF07C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800C2120 000BF080  7C 7E 1B 79 */	or. r30, r3, r3
/* 800C2124 000BF084  41 82 00 2C */	beq .L_800C2150
/* 800C2128 000BF088  3C 60 80 2B */	lis r3, __vt__7ActRope@ha
/* 800C212C 000BF08C  38 03 79 BC */	addi r0, r3, __vt__7ActRope@l
/* 800C2130 000BF090  90 1E 00 00 */	stw r0, 0(r30)
/* 800C2134 000BF094  38 7E 00 00 */	addi r3, r30, 0
/* 800C2138 000BF098  38 80 00 00 */	li r4, 0
/* 800C213C 000BF09C  48 00 1C CD */	bl __dt__6ActionFv
/* 800C2140 000BF0A0  7F E0 07 35 */	extsh. r0, r31
/* 800C2144 000BF0A4  40 81 00 0C */	ble .L_800C2150
/* 800C2148 000BF0A8  7F C3 F3 78 */	mr r3, r30
/* 800C214C 000BF0AC  4B F8 50 61 */	bl __dl__FPv
.L_800C2150:
/* 800C2150 000BF0B0  7F C3 F3 78 */	mr r3, r30
/* 800C2154 000BF0B4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800C2158 000BF0B8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800C215C 000BF0BC  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800C2160 000BF0C0  38 21 00 18 */	addi r1, r1, 0x18
/* 800C2164 000BF0C4  7C 08 03 A6 */	mtlr r0
/* 800C2168 000BF0C8  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802B7980:
	.asciz "aiRope.cpp"
.balign 4
lbl_802B798C:
	.asciz "Receiver<Piki>"
.balign 4
lbl_802B799C:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
lbl_802B79A8:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.global __vt__7ActRope
__vt__7ActRope:
	.4byte __RTTI__7ActRope
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
	.4byte __dt__7ActRopeFv
	.4byte init__7ActRopeFP8Creature
	.4byte exec__7ActRopeFv
	.4byte cleanup__7ActRopeFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
lbl_802B7A20:
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

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E0810:
	.asciz "rope"
.balign 4
lbl_803E0818:
	.float 0.0
lbl_803E081C:
	.float 1.0
lbl_803E0820:
	.float 0.0
lbl_803E0824:
	.float 150.0
.balign 4
lbl_803E0828:
	.asciz "ActRope"
.balign 4
"__RTTI__15Receiver<4Piki>":
	.4byte lbl_802B798C
	.4byte 0
.balign 4
lbl_803E0838:
	.asciz "Action"
.balign 4
__RTTI__6Action:
	.4byte lbl_803E0838
	.4byte lbl_802B799C
__RTTI__7ActRope:
	.4byte lbl_803E0828
	.4byte lbl_802B79A8

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E96D8:
	.float 0.0
lbl_803E96DC:
	.float 1.0
lbl_803E96E0:
	.float 32767.0
lbl_803E96E4:
	.float 22.0
lbl_803E96E8:
	.float 4.0
lbl_803E96EC:
	.float 0.5
lbl_803E96F0:
	.4byte 0x43300000
	.4byte 0x80000000
