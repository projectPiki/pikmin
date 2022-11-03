.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global hardReset__11PlugPikiAppFv
hardReset__11PlugPikiAppFv:
/* 8005EDF0 0005BD50  7C 08 02 A6 */	mflr r0
/* 8005EDF4 0005BD54  38 80 00 00 */	li r4, 0
/* 8005EDF8 0005BD58  90 01 00 04 */	stw r0, 4(r1)
/* 8005EDFC 0005BD5C  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8005EE00 0005BD60  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8005EE04 0005BD64  7C 7F 1B 78 */	mr r31, r3
/* 8005EE08 0005BD68  93 C1 00 38 */	stw r30, 0x38(r1)
/* 8005EE0C 0005BD6C  93 A1 00 34 */	stw r29, 0x34(r1)
/* 8005EE10 0005BD70  93 81 00 30 */	stw r28, 0x30(r1)
/* 8005EE14 0005BD74  81 9F 00 00 */	lwz r12, 0(r31)
/* 8005EE18 0005BD78  81 8C 00 44 */	lwz r12, 0x44(r12)
/* 8005EE1C 0005BD7C  7D 88 03 A6 */	mtlr r12
/* 8005EE20 0005BD80  4E 80 00 21 */	blrl 
/* 8005EE24 0005BD84  38 60 00 0C */	li r3, 0xc
/* 8005EE28 0005BD88  4B FE 81 DD */	bl alloc__6SystemFUl
/* 8005EE2C 0005BD8C  28 03 00 00 */	cmplwi r3, 0
/* 8005EE30 0005BD90  41 82 00 18 */	beq .L_8005EE48
/* 8005EE34 0005BD94  38 80 00 00 */	li r4, 0
/* 8005EE38 0005BD98  90 83 00 00 */	stw r4, 0(r3)
/* 8005EE3C 0005BD9C  38 00 FF FF */	li r0, -1
/* 8005EE40 0005BDA0  90 83 00 08 */	stw r4, 8(r3)
/* 8005EE44 0005BDA4  90 03 00 04 */	stw r0, 4(r3)
.L_8005EE48:
/* 8005EE48 0005BDA8  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005EE4C 0005BDAC  3C 80 80 3A */	lis r4, gameflow@ha
/* 8005EE50 0005BDB0  38 04 D7 B8 */	addi r0, r4, gameflow@l
/* 8005EE54 0005BDB4  90 65 00 34 */	stw r3, 0x34(r5)
/* 8005EE58 0005BDB8  7C 03 03 78 */	mr r3, r0
/* 8005EE5C 0005BDBC  38 9F 00 00 */	addi r4, r31, 0
/* 8005EE60 0005BDC0  4B FF 32 29 */	bl hardReset__8GameFlowFP7BaseApp
/* 8005EE64 0005BDC4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005EE68 0005BDC8  38 80 00 00 */	li r4, 0
/* 8005EE6C 0005BDCC  4B FE 01 B5 */	bl getHeap__9StdSystemFi
/* 8005EE70 0005BDD0  7C 7E 1B 78 */	mr r30, r3
/* 8005EE74 0005BDD4  80 63 00 08 */	lwz r3, 8(r3)
/* 8005EE78 0005BDD8  80 1E 00 04 */	lwz r0, 4(r30)
/* 8005EE7C 0005BDDC  7C 03 00 50 */	subf r0, r3, r0
/* 8005EE80 0005BDE0  34 60 FF F8 */	addic. r3, r0, -8
/* 8005EE84 0005BDE4  40 81 00 08 */	ble .L_8005EE8C
/* 8005EE88 0005BDE8  48 00 00 08 */	b .L_8005EE90
.L_8005EE8C:
/* 8005EE8C 0005BDEC  38 60 00 00 */	li r3, 0
.L_8005EE90:
/* 8005EE90 0005BDF0  83 BE 00 00 */	lwz r29, 0(r30)
/* 8005EE94 0005BDF4  38 00 00 02 */	li r0, 2
/* 8005EE98 0005BDF8  3B 83 00 00 */	addi r28, r3, 0
/* 8005EE9C 0005BDFC  90 1E 00 00 */	stw r0, 0(r30)
/* 8005EEA0 0005BE00  80 7E 00 08 */	lwz r3, 8(r30)
/* 8005EEA4 0005BE04  80 1E 00 04 */	lwz r0, 4(r30)
/* 8005EEA8 0005BE08  7C 03 00 50 */	subf r0, r3, r0
/* 8005EEAC 0005BE0C  34 60 FF F8 */	addic. r3, r0, -8
/* 8005EEB0 0005BE10  40 81 00 08 */	ble .L_8005EEB8
/* 8005EEB4 0005BE14  48 00 00 08 */	b .L_8005EEBC
.L_8005EEB8:
/* 8005EEB8 0005BE18  38 60 00 00 */	li r3, 0
.L_8005EEBC:
/* 8005EEBC 0005BE1C  4B FE 81 49 */	bl alloc__6SystemFUl
/* 8005EEC0 0005BE20  93 BE 00 00 */	stw r29, 0(r30)
/* 8005EEC4 0005BE24  7C 60 1B 78 */	mr r0, r3
/* 8005EEC8 0005BE28  7C 1D 03 78 */	mr r29, r0
/* 8005EECC 0005BE2C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005EED0 0005BE30  38 80 00 01 */	li r4, 1
/* 8005EED4 0005BE34  4B FE 01 4D */	bl getHeap__9StdSystemFi
/* 8005EED8 0005BE38  38 DD 00 00 */	addi r6, r29, 0
/* 8005EEDC 0005BE3C  38 FC 00 00 */	addi r7, r28, 0
/* 8005EEE0 0005BE40  38 8D 91 18 */	addi r4, r13, lbl_803DDE38@sda21
/* 8005EEE4 0005BE44  38 A0 00 02 */	li r5, 2
/* 8005EEE8 0005BE48  4B FC 5A 21 */	bl init__7AyuHeapFPciPvi
/* 8005EEEC 0005BE4C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005EEF0 0005BE50  38 80 00 01 */	li r4, 1
/* 8005EEF4 0005BE54  38 A0 00 01 */	li r5, 1
/* 8005EEF8 0005BE58  4B FE 01 3D */	bl resetHeap__9StdSystemFii
/* 8005EEFC 0005BE5C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005EF00 0005BE60  38 80 00 01 */	li r4, 1
/* 8005EF04 0005BE64  4B FE 01 1D */	bl getHeap__9StdSystemFi
/* 8005EF08 0005BE68  3B C0 00 01 */	li r30, 1
/* 8005EF0C 0005BE6C  93 C3 00 00 */	stw r30, 0(r3)
/* 8005EF10 0005BE70  38 7F 00 00 */	addi r3, r31, 0
/* 8005EF14 0005BE74  38 80 00 01 */	li r4, 1
/* 8005EF18 0005BE78  81 9F 00 00 */	lwz r12, 0(r31)
/* 8005EF1C 0005BE7C  81 8C 00 44 */	lwz r12, 0x44(r12)
/* 8005EF20 0005BE80  7D 88 03 A6 */	mtlr r12
/* 8005EF24 0005BE84  4E 80 00 21 */	blrl 
/* 8005EF28 0005BE88  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005EF2C 0005BE8C  9B C3 00 00 */	stb r30, 0(r3)
/* 8005EF30 0005BE90  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8005EF34 0005BE94  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8005EF38 0005BE98  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 8005EF3C 0005BE9C  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 8005EF40 0005BEA0  83 81 00 30 */	lwz r28, 0x30(r1)
/* 8005EF44 0005BEA4  38 21 00 40 */	addi r1, r1, 0x40
/* 8005EF48 0005BEA8  7C 08 03 A6 */	mtlr r0
/* 8005EF4C 0005BEAC  4E 80 00 20 */	blr 

.global softReset__11PlugPikiAppFv
softReset__11PlugPikiAppFv:
/* 8005EF50 0005BEB0  7C 08 02 A6 */	mflr r0
/* 8005EF54 0005BEB4  90 01 00 04 */	stw r0, 4(r1)
/* 8005EF58 0005BEB8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8005EF5C 0005BEBC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8005EF60 0005BEC0  7C 7F 1B 78 */	mr r31, r3
/* 8005EF64 0005BEC4  4B FC 5F 79 */	bl softReset__7BaseAppFv
/* 8005EF68 0005BEC8  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005EF6C 0005BECC  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 8005EF70 0005BED0  4B FF 37 ED */	bl softReset__8GameFlowFv
/* 8005EF74 0005BED4  38 00 00 01 */	li r0, 1
/* 8005EF78 0005BED8  90 1F 00 2C */	stw r0, 0x2c(r31)
/* 8005EF7C 0005BEDC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8005EF80 0005BEE0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8005EF84 0005BEE4  38 21 00 18 */	addi r1, r1, 0x18
/* 8005EF88 0005BEE8  7C 08 03 A6 */	mtlr r0
/* 8005EF8C 0005BEEC  4E 80 00 20 */	blr 

.global update__11PlugPikiAppFv
update__11PlugPikiAppFv:
/* 8005EF90 0005BEF0  7C 08 02 A6 */	mflr r0
/* 8005EF94 0005BEF4  3C 80 80 3A */	lis r4, gameflow@ha
/* 8005EF98 0005BEF8  90 01 00 04 */	stw r0, 4(r1)
/* 8005EF9C 0005BEFC  38 A4 D7 B8 */	addi r5, r4, gameflow@l
/* 8005EFA0 0005BF00  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8005EFA4 0005BF04  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8005EFA8 0005BF08  3B E3 00 00 */	addi r31, r3, 0
/* 8005EFAC 0005BF0C  7C A3 2B 78 */	mr r3, r5
/* 8005EFB0 0005BF10  80 85 02 D0 */	lwz r4, 0x2d0(r5)
/* 8005EFB4 0005BF14  38 04 00 01 */	addi r0, r4, 1
/* 8005EFB8 0005BF18  90 05 02 D0 */	stw r0, 0x2d0(r5)
/* 8005EFBC 0005BF1C  4B FF 3D 79 */	bl update__8GameFlowFv
/* 8005EFC0 0005BF20  7F E3 FB 78 */	mr r3, r31
/* 8005EFC4 0005BF24  4B FE 17 A1 */	bl update__4NodeFv
/* 8005EFC8 0005BF28  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8005EFCC 0005BF2C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8005EFD0 0005BF30  38 21 00 18 */	addi r1, r1, 0x18
/* 8005EFD4 0005BF34  7C 08 03 A6 */	mtlr r0
/* 8005EFD8 0005BF38  4E 80 00 20 */	blr 

.global draw__11PlugPikiAppFR8Graphics
draw__11PlugPikiAppFR8Graphics:
/* 8005EFDC 0005BF3C  7C 08 02 A6 */	mflr r0
/* 8005EFE0 0005BF40  3C A0 80 2B */	lis r5, lbl_802A86B0@ha
/* 8005EFE4 0005BF44  90 01 00 04 */	stw r0, 4(r1)
/* 8005EFE8 0005BF48  94 21 FE 28 */	stwu r1, -0x1d8(r1)
/* 8005EFEC 0005BF4C  BF 61 01 C4 */	stmw r27, 0x1c4(r1)
/* 8005EFF0 0005BF50  3B A4 00 00 */	addi r29, r4, 0
/* 8005EFF4 0005BF54  3B E5 86 B0 */	addi r31, r5, lbl_802A86B0@l
/* 8005EFF8 0005BF58  80 03 00 2C */	lwz r0, 0x2c(r3)
/* 8005EFFC 0005BF5C  2C 00 00 00 */	cmpwi r0, 0
/* 8005F000 0005BF60  41 82 04 84 */	beq .L_8005F484
/* 8005F004 0005BF64  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8005F008 0005BF68  3B 60 00 00 */	li r27, 0
/* 8005F00C 0005BF6C  93 64 01 AC */	stw r27, 0x1ac(r4)
/* 8005F010 0005BF70  7F A4 EB 78 */	mr r4, r29
/* 8005F014 0005BF74  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F018 0005BF78  93 65 01 A8 */	stw r27, 0x1a8(r5)
/* 8005F01C 0005BF7C  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F020 0005BF80  93 65 01 A4 */	stw r27, 0x1a4(r5)
/* 8005F024 0005BF84  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F028 0005BF88  93 65 01 B4 */	stw r27, 0x1b4(r5)
/* 8005F02C 0005BF8C  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F030 0005BF90  93 65 01 B0 */	stw r27, 0x1b0(r5)
/* 8005F034 0005BF94  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F038 0005BF98  93 65 01 B8 */	stw r27, 0x1b8(r5)
/* 8005F03C 0005BF9C  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F040 0005BFA0  93 65 01 BC */	stw r27, 0x1bc(r5)
/* 8005F044 0005BFA4  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F048 0005BFA8  93 65 01 C0 */	stw r27, 0x1c0(r5)
/* 8005F04C 0005BFAC  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F050 0005BFB0  93 65 01 C4 */	stw r27, 0x1c4(r5)
/* 8005F054 0005BFB4  4B FE 17 7D */	bl draw__4NodeFR8Graphics
/* 8005F058 0005BFB8  80 DD 03 10 */	lwz r6, 0x310(r29)
/* 8005F05C 0005BFBC  38 A1 00 60 */	addi r5, r1, 0x60
/* 8005F060 0005BFC0  80 1D 03 0C */	lwz r0, 0x30c(r29)
/* 8005F064 0005BFC4  7F A3 EB 78 */	mr r3, r29
/* 8005F068 0005BFC8  38 81 01 70 */	addi r4, r1, 0x170
/* 8005F06C 0005BFCC  93 61 00 60 */	stw r27, 0x60(r1)
/* 8005F070 0005BFD0  93 61 00 64 */	stw r27, 0x64(r1)
/* 8005F074 0005BFD4  90 01 00 68 */	stw r0, 0x68(r1)
/* 8005F078 0005BFD8  90 C1 00 6C */	stw r6, 0x6c(r1)
/* 8005F07C 0005BFDC  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F080 0005BFE0  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 8005F084 0005BFE4  7D 88 03 A6 */	mtlr r12
/* 8005F088 0005BFE8  4E 80 00 21 */	blrl 
/* 8005F08C 0005BFEC  7F A3 EB 78 */	mr r3, r29
/* 8005F090 0005BFF0  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F094 0005BFF4  38 80 00 00 */	li r4, 0
/* 8005F098 0005BFF8  38 A0 00 00 */	li r5, 0
/* 8005F09C 0005BFFC  81 8C 00 CC */	lwz r12, 0xcc(r12)
/* 8005F0A0 0005C000  7D 88 03 A6 */	mtlr r12
/* 8005F0A4 0005C004  4E 80 00 21 */	blrl 
/* 8005F0A8 0005C008  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F0AC 0005C00C  80 03 00 18 */	lwz r0, 0x18(r3)
/* 8005F0B0 0005C010  28 00 00 00 */	cmplwi r0, 0
/* 8005F0B4 0005C014  41 82 01 BC */	beq .L_8005F270
/* 8005F0B8 0005C018  38 00 00 FF */	li r0, 0xff
/* 8005F0BC 0005C01C  98 01 00 5C */	stb r0, 0x5c(r1)
/* 8005F0C0 0005C020  38 81 00 5C */	addi r4, r1, 0x5c
/* 8005F0C4 0005C024  38 7D 00 00 */	addi r3, r29, 0
/* 8005F0C8 0005C028  98 01 00 5D */	stb r0, 0x5d(r1)
/* 8005F0CC 0005C02C  38 A0 00 01 */	li r5, 1
/* 8005F0D0 0005C030  98 01 00 5E */	stb r0, 0x5e(r1)
/* 8005F0D4 0005C034  98 01 00 5F */	stb r0, 0x5f(r1)
/* 8005F0D8 0005C038  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F0DC 0005C03C  81 8C 00 A8 */	lwz r12, 0xa8(r12)
/* 8005F0E0 0005C040  7D 88 03 A6 */	mtlr r12
/* 8005F0E4 0005C044  4E 80 00 21 */	blrl 
/* 8005F0E8 0005C048  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F0EC 0005C04C  3C 00 43 30 */	lis r0, 0x4330
/* 8005F0F0 0005C050  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F0F4 0005C054  7F A3 EB 78 */	mr r3, r29
/* 8005F0F8 0005C058  81 05 01 A4 */	lwz r8, 0x1a4(r5)
/* 8005F0FC 0005C05C  81 8C 00 EC */	lwz r12, 0xec(r12)
/* 8005F100 0005C060  38 FF 00 1C */	addi r7, r31, 0x1c
/* 8005F104 0005C064  6D 04 80 00 */	xoris r4, r8, 0x8000
/* 8005F108 0005C068  C8 22 86 C8 */	lfd f1, lbl_803E88C8@sda21(r2)
/* 8005F10C 0005C06C  90 81 01 BC */	stw r4, 0x1bc(r1)
/* 8005F110 0005C070  C0 45 02 90 */	lfs f2, 0x290(r5)
/* 8005F114 0005C074  7D 88 03 A6 */	mtlr r12
/* 8005F118 0005C078  90 01 01 B8 */	stw r0, 0x1b8(r1)
/* 8005F11C 0005C07C  38 C0 00 20 */	li r6, 0x20
/* 8005F120 0005C080  80 85 00 10 */	lwz r4, 0x10(r5)
/* 8005F124 0005C084  C8 01 01 B8 */	lfd f0, 0x1b8(r1)
/* 8005F128 0005C088  4C C6 31 82 */	crclr 6
/* 8005F12C 0005C08C  38 A0 00 20 */	li r5, 0x20
/* 8005F130 0005C090  EC 00 08 28 */	fsubs f0, f0, f1
/* 8005F134 0005C094  EC 00 00 B2 */	fmuls f0, f0, f2
/* 8005F138 0005C098  FC 00 00 1E */	fctiwz f0, f0
/* 8005F13C 0005C09C  D8 01 01 B0 */	stfd f0, 0x1b0(r1)
/* 8005F140 0005C0A0  81 21 01 B4 */	lwz r9, 0x1b4(r1)
/* 8005F144 0005C0A4  4E 80 00 21 */	blrl 
/* 8005F148 0005C0A8  7F A3 EB 78 */	mr r3, r29
/* 8005F14C 0005C0AC  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F150 0005C0B0  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F154 0005C0B4  38 FF 00 30 */	addi r7, r31, 0x30
/* 8005F158 0005C0B8  80 85 00 10 */	lwz r4, 0x10(r5)
/* 8005F15C 0005C0BC  4C C6 31 82 */	crclr 6
/* 8005F160 0005C0C0  81 8C 00 EC */	lwz r12, 0xec(r12)
/* 8005F164 0005C0C4  81 05 01 B8 */	lwz r8, 0x1b8(r5)
/* 8005F168 0005C0C8  38 A0 00 20 */	li r5, 0x20
/* 8005F16C 0005C0CC  7D 88 03 A6 */	mtlr r12
/* 8005F170 0005C0D0  38 C0 00 2C */	li r6, 0x2c
/* 8005F174 0005C0D4  4E 80 00 21 */	blrl 
/* 8005F178 0005C0D8  7F A3 EB 78 */	mr r3, r29
/* 8005F17C 0005C0DC  80 CD 2D EC */	lwz r6, gsys@sda21(r13)
/* 8005F180 0005C0E0  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F184 0005C0E4  4C C6 31 82 */	crclr 6
/* 8005F188 0005C0E8  80 86 00 10 */	lwz r4, 0x10(r6)
/* 8005F18C 0005C0EC  38 A0 00 20 */	li r5, 0x20
/* 8005F190 0005C0F0  81 8C 00 EC */	lwz r12, 0xec(r12)
/* 8005F194 0005C0F4  81 06 01 A8 */	lwz r8, 0x1a8(r6)
/* 8005F198 0005C0F8  38 C0 00 38 */	li r6, 0x38
/* 8005F19C 0005C0FC  7D 88 03 A6 */	mtlr r12
/* 8005F1A0 0005C100  38 ED 91 1C */	addi r7, r13, lbl_803DDE3C@sda21
/* 8005F1A4 0005C104  4E 80 00 21 */	blrl 
/* 8005F1A8 0005C108  7F A3 EB 78 */	mr r3, r29
/* 8005F1AC 0005C10C  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F1B0 0005C110  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F1B4 0005C114  38 FF 00 3C */	addi r7, r31, 0x3c
/* 8005F1B8 0005C118  80 85 00 10 */	lwz r4, 0x10(r5)
/* 8005F1BC 0005C11C  4C C6 31 82 */	crclr 6
/* 8005F1C0 0005C120  81 8C 00 EC */	lwz r12, 0xec(r12)
/* 8005F1C4 0005C124  81 05 01 AC */	lwz r8, 0x1ac(r5)
/* 8005F1C8 0005C128  38 A0 00 20 */	li r5, 0x20
/* 8005F1CC 0005C12C  7D 88 03 A6 */	mtlr r12
/* 8005F1D0 0005C130  38 C0 00 44 */	li r6, 0x44
/* 8005F1D4 0005C134  4E 80 00 21 */	blrl 
/* 8005F1D8 0005C138  7F A3 EB 78 */	mr r3, r29
/* 8005F1DC 0005C13C  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8005F1E0 0005C140  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F1E4 0005C144  4C C6 31 82 */	crclr 6
/* 8005F1E8 0005C148  80 E4 02 4C */	lwz r7, 0x24c(r4)
/* 8005F1EC 0005C14C  38 A0 00 20 */	li r5, 0x20
/* 8005F1F0 0005C150  81 8C 00 EC */	lwz r12, 0xec(r12)
/* 8005F1F4 0005C154  80 84 00 10 */	lwz r4, 0x10(r4)
/* 8005F1F8 0005C158  38 C0 00 50 */	li r6, 0x50
/* 8005F1FC 0005C15C  7D 88 03 A6 */	mtlr r12
/* 8005F200 0005C160  81 07 03 8C */	lwz r8, 0x38c(r7)
/* 8005F204 0005C164  38 ED 91 24 */	addi r7, r13, lbl_803DDE44@sda21
/* 8005F208 0005C168  4E 80 00 21 */	blrl 
/* 8005F20C 0005C16C  7F A3 EB 78 */	mr r3, r29
/* 8005F210 0005C170  80 CD 2D EC */	lwz r6, gsys@sda21(r13)
/* 8005F214 0005C174  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F218 0005C178  38 FF 00 48 */	addi r7, r31, 0x48
/* 8005F21C 0005C17C  80 86 00 10 */	lwz r4, 0x10(r6)
/* 8005F220 0005C180  4C C6 31 82 */	crclr 6
/* 8005F224 0005C184  81 8C 00 EC */	lwz r12, 0xec(r12)
/* 8005F228 0005C188  81 06 01 BC */	lwz r8, 0x1bc(r6)
/* 8005F22C 0005C18C  38 A0 00 20 */	li r5, 0x20
/* 8005F230 0005C190  7D 88 03 A6 */	mtlr r12
/* 8005F234 0005C194  81 26 01 C0 */	lwz r9, 0x1c0(r6)
/* 8005F238 0005C198  38 C0 00 5C */	li r6, 0x5c
/* 8005F23C 0005C19C  4E 80 00 21 */	blrl 
/* 8005F240 0005C1A0  7F A3 EB 78 */	mr r3, r29
/* 8005F244 0005C1A4  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F248 0005C1A8  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F24C 0005C1AC  38 FF 00 68 */	addi r7, r31, 0x68
/* 8005F250 0005C1B0  80 85 00 10 */	lwz r4, 0x10(r5)
/* 8005F254 0005C1B4  4C C6 31 82 */	crclr 6
/* 8005F258 0005C1B8  81 8C 00 EC */	lwz r12, 0xec(r12)
/* 8005F25C 0005C1BC  81 05 01 C4 */	lwz r8, 0x1c4(r5)
/* 8005F260 0005C1C0  38 A0 00 20 */	li r5, 0x20
/* 8005F264 0005C1C4  7D 88 03 A6 */	mtlr r12
/* 8005F268 0005C1C8  38 C0 00 68 */	li r6, 0x68
/* 8005F26C 0005C1CC  4E 80 00 21 */	blrl 
.L_8005F270:
/* 8005F270 0005C1D0  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005F274 0005C1D4  C0 22 86 C0 */	lfs f1, lbl_803E88C0@sda21(r2)
/* 8005F278 0005C1D8  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 8005F27C 0005C1DC  3B C3 02 C4 */	addi r30, r3, 0x2c4
/* 8005F280 0005C1E0  C0 03 02 C4 */	lfs f0, 0x2c4(r3)
/* 8005F284 0005C1E4  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8005F288 0005C1E8  41 81 00 10 */	bgt .L_8005F298
/* 8005F28C 0005C1EC  C0 03 02 C8 */	lfs f0, 0x2c8(r3)
/* 8005F290 0005C1F0  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8005F294 0005C1F4  40 81 01 28 */	ble .L_8005F3BC
.L_8005F298:
/* 8005F298 0005C1F8  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8005F29C 0005C1FC  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005F2A0 0005C200  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 8005F2A4 0005C204  C0 24 02 8C */	lfs f1, 0x28c(r4)
/* 8005F2A8 0005C208  38 A4 02 8C */	addi r5, r4, 0x28c
/* 8005F2AC 0005C20C  C0 03 02 CC */	lfs f0, 0x2cc(r3)
/* 8005F2B0 0005C210  EC 00 08 28 */	fsubs f0, f0, f1
/* 8005F2B4 0005C214  D0 03 02 CC */	stfs f0, 0x2cc(r3)
/* 8005F2B8 0005C218  C0 23 02 CC */	lfs f1, 0x2cc(r3)
/* 8005F2BC 0005C21C  C0 02 86 C0 */	lfs f0, lbl_803E88C0@sda21(r2)
/* 8005F2C0 0005C220  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8005F2C4 0005C224  40 80 00 08 */	bge .L_8005F2CC
/* 8005F2C8 0005C228  D0 03 02 C8 */	stfs f0, 0x2c8(r3)
.L_8005F2CC:
/* 8005F2CC 0005C22C  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005F2D0 0005C230  C0 5E 00 00 */	lfs f2, 0(r30)
/* 8005F2D4 0005C234  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 8005F2D8 0005C238  C4 23 02 C8 */	lfsu f1, 0x2c8(r3)
/* 8005F2DC 0005C23C  C0 05 00 00 */	lfs f0, 0(r5)
/* 8005F2E0 0005C240  EC 21 10 28 */	fsubs f1, f1, f2
/* 8005F2E4 0005C244  EC 01 00 32 */	fmuls f0, f1, f0
/* 8005F2E8 0005C248  EC 02 00 2A */	fadds f0, f2, f0
/* 8005F2EC 0005C24C  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8005F2F0 0005C250  C0 5E 00 00 */	lfs f2, 0(r30)
/* 8005F2F4 0005C254  C0 23 00 00 */	lfs f1, 0(r3)
/* 8005F2F8 0005C258  C0 02 86 C4 */	lfs f0, lbl_803E88C4@sda21(r2)
/* 8005F2FC 0005C25C  EC 22 08 28 */	fsubs f1, f2, f1
/* 8005F300 0005C260  D0 21 00 44 */	stfs f1, 0x44(r1)
/* 8005F304 0005C264  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8005F308 0005C268  54 00 00 7E */	clrlwi r0, r0, 1
/* 8005F30C 0005C26C  90 01 00 44 */	stw r0, 0x44(r1)
/* 8005F310 0005C270  C0 21 00 44 */	lfs f1, 0x44(r1)
/* 8005F314 0005C274  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8005F318 0005C278  40 80 00 0C */	bge .L_8005F324
/* 8005F31C 0005C27C  C0 03 00 00 */	lfs f0, 0(r3)
/* 8005F320 0005C280  D0 1E 00 00 */	stfs f0, 0(r30)
.L_8005F324:
/* 8005F324 0005C284  3B 60 00 C0 */	li r27, 0xc0
/* 8005F328 0005C288  9B 61 00 58 */	stb r27, 0x58(r1)
/* 8005F32C 0005C28C  3B 80 00 FF */	li r28, 0xff
/* 8005F330 0005C290  38 81 00 58 */	addi r4, r1, 0x58
/* 8005F334 0005C294  9B 81 00 59 */	stb r28, 0x59(r1)
/* 8005F338 0005C298  7F A3 EB 78 */	mr r3, r29
/* 8005F33C 0005C29C  38 A0 00 01 */	li r5, 1
/* 8005F340 0005C2A0  9B 81 00 5A */	stb r28, 0x5a(r1)
/* 8005F344 0005C2A4  C0 1E 00 00 */	lfs f0, 0(r30)
/* 8005F348 0005C2A8  FC 00 00 1E */	fctiwz f0, f0
/* 8005F34C 0005C2AC  D8 01 01 B0 */	stfd f0, 0x1b0(r1)
/* 8005F350 0005C2B0  80 01 01 B4 */	lwz r0, 0x1b4(r1)
/* 8005F354 0005C2B4  98 01 00 5B */	stb r0, 0x5b(r1)
/* 8005F358 0005C2B8  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F35C 0005C2BC  81 8C 00 A8 */	lwz r12, 0xa8(r12)
/* 8005F360 0005C2C0  7D 88 03 A6 */	mtlr r12
/* 8005F364 0005C2C4  4E 80 00 21 */	blrl 
/* 8005F368 0005C2C8  9B 61 00 54 */	stb r27, 0x54(r1)
/* 8005F36C 0005C2CC  38 81 00 54 */	addi r4, r1, 0x54
/* 8005F370 0005C2D0  38 7D 00 00 */	addi r3, r29, 0
/* 8005F374 0005C2D4  9B 61 00 55 */	stb r27, 0x55(r1)
/* 8005F378 0005C2D8  9B 81 00 56 */	stb r28, 0x56(r1)
/* 8005F37C 0005C2DC  C0 1E 00 00 */	lfs f0, 0(r30)
/* 8005F380 0005C2E0  FC 00 00 1E */	fctiwz f0, f0
/* 8005F384 0005C2E4  D8 01 01 B8 */	stfd f0, 0x1b8(r1)
/* 8005F388 0005C2E8  80 01 01 BC */	lwz r0, 0x1bc(r1)
/* 8005F38C 0005C2EC  98 01 00 57 */	stb r0, 0x57(r1)
/* 8005F390 0005C2F0  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F394 0005C2F4  81 8C 00 AC */	lwz r12, 0xac(r12)
/* 8005F398 0005C2F8  7D 88 03 A6 */	mtlr r12
/* 8005F39C 0005C2FC  4E 80 00 21 */	blrl 
/* 8005F3A0 0005C300  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005F3A4 0005C304  4C C6 32 42 */	crset 6
/* 8005F3A8 0005C308  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 8005F3AC 0005C30C  C0 23 02 C0 */	lfs f1, 0x2c0(r3)
/* 8005F3B0 0005C310  38 61 00 70 */	addi r3, r1, 0x70
/* 8005F3B4 0005C314  38 9F 00 78 */	addi r4, r31, 0x78
/* 8005F3B8 0005C318  48 1B 71 E1 */	bl sprintf
.L_8005F3BC:
/* 8005F3BC 0005C31C  7F A3 EB 78 */	mr r3, r29
/* 8005F3C0 0005C320  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8005F3C4 0005C324  38 80 00 00 */	li r4, 0
/* 8005F3C8 0005C328  38 A0 00 00 */	li r5, 0
/* 8005F3CC 0005C32C  81 8C 00 CC */	lwz r12, 0xcc(r12)
/* 8005F3D0 0005C330  7D 88 03 A6 */	mtlr r12
/* 8005F3D4 0005C334  4E 80 00 21 */	blrl 
/* 8005F3D8 0005C338  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F3DC 0005C33C  38 83 00 04 */	addi r4, r3, 4
/* 8005F3E0 0005C340  C0 03 00 08 */	lfs f0, 8(r3)
/* 8005F3E4 0005C344  C0 43 00 04 */	lfs f2, 4(r3)
/* 8005F3E8 0005C348  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8005F3EC 0005C34C  40 80 00 38 */	bge .L_8005F424
/* 8005F3F0 0005C350  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 8005F3F4 0005C354  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 8005F3F8 0005C358  EC 01 00 32 */	fmuls f0, f1, f0
/* 8005F3FC 0005C35C  EC 02 00 2A */	fadds f0, f2, f0
/* 8005F400 0005C360  D0 04 00 00 */	stfs f0, 0(r4)
/* 8005F404 0005C364  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F408 0005C368  38 83 00 04 */	addi r4, r3, 4
/* 8005F40C 0005C36C  C0 23 00 08 */	lfs f1, 8(r3)
/* 8005F410 0005C370  C0 03 00 04 */	lfs f0, 4(r3)
/* 8005F414 0005C374  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8005F418 0005C378  40 81 00 4C */	ble .L_8005F464
/* 8005F41C 0005C37C  D0 24 00 00 */	stfs f1, 0(r4)
/* 8005F420 0005C380  48 00 00 44 */	b .L_8005F464
.L_8005F424:
/* 8005F424 0005C384  40 81 00 40 */	ble .L_8005F464
/* 8005F428 0005C388  D0 04 00 00 */	stfs f0, 0(r4)
/* 8005F42C 0005C38C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F430 0005C390  C0 43 02 8C */	lfs f2, 0x28c(r3)
/* 8005F434 0005C394  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 8005F438 0005C398  C0 23 00 04 */	lfs f1, 4(r3)
/* 8005F43C 0005C39C  EC 00 00 B2 */	fmuls f0, f0, f2
/* 8005F440 0005C3A0  EC 01 00 28 */	fsubs f0, f1, f0
/* 8005F444 0005C3A4  D0 03 00 04 */	stfs f0, 4(r3)
/* 8005F448 0005C3A8  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F44C 0005C3AC  38 83 00 04 */	addi r4, r3, 4
/* 8005F450 0005C3B0  C0 23 00 08 */	lfs f1, 8(r3)
/* 8005F454 0005C3B4  C0 03 00 04 */	lfs f0, 4(r3)
/* 8005F458 0005C3B8  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 8005F45C 0005C3BC  40 80 00 08 */	bge .L_8005F464
/* 8005F460 0005C3C0  D0 24 00 00 */	stfs f1, 0(r4)
.L_8005F464:
/* 8005F464 0005C3C4  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005F468 0005C3C8  80 05 00 18 */	lwz r0, 0x18(r5)
/* 8005F46C 0005C3CC  28 00 00 00 */	cmplwi r0, 0
/* 8005F470 0005C3D0  41 82 00 14 */	beq .L_8005F484
/* 8005F474 0005C3D4  80 65 00 34 */	lwz r3, 0x34(r5)
/* 8005F478 0005C3D8  7F A4 EB 78 */	mr r4, r29
/* 8005F47C 0005C3DC  80 A5 00 10 */	lwz r5, 0x10(r5)
/* 8005F480 0005C3E0  4B FE 15 2D */	bl draw__6TimersFR8GraphicsP4Font
.L_8005F484:
/* 8005F484 0005C3E4  BB 61 01 C4 */	lmw r27, 0x1c4(r1)
/* 8005F488 0005C3E8  80 01 01 DC */	lwz r0, 0x1dc(r1)
/* 8005F48C 0005C3EC  38 21 01 D8 */	addi r1, r1, 0x1d8
/* 8005F490 0005C3F0  7C 08 03 A6 */	mtlr r0
/* 8005F494 0005C3F4  4E 80 00 20 */	blr 

.global idle__11PlugPikiAppFv
idle__11PlugPikiAppFv:
/* 8005F498 0005C3F8  7C 08 02 A6 */	mflr r0
/* 8005F49C 0005C3FC  90 01 00 04 */	stw r0, 4(r1)
/* 8005F4A0 0005C400  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8005F4A4 0005C404  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8005F4A8 0005C408  7C 7F 1B 78 */	mr r31, r3
/* 8005F4AC 0005C40C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F4B0 0005C410  80 9F 00 50 */	lwz r4, 0x50(r31)
/* 8005F4B4 0005C414  4B FD FB B5 */	bl setHeap__9StdSystemFi
/* 8005F4B8 0005C418  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F4BC 0005C41C  80 63 00 34 */	lwz r3, 0x34(r3)
/* 8005F4C0 0005C420  4B FE 14 D5 */	bl newFrame__6TimersFv
/* 8005F4C4 0005C424  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F4C8 0005C428  38 8D 91 2C */	addi r4, r13, lbl_803DDE4C@sda21
/* 8005F4CC 0005C42C  38 A0 00 00 */	li r5, 0
/* 8005F4D0 0005C430  80 63 00 34 */	lwz r3, 0x34(r3)
/* 8005F4D4 0005C434  4B FE 14 D1 */	bl _start__6TimersFPcb
/* 8005F4D8 0005C438  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F4DC 0005C43C  88 03 00 00 */	lbz r0, 0(r3)
/* 8005F4E0 0005C440  80 83 02 6C */	lwz r4, 0x26c(r3)
/* 8005F4E4 0005C444  28 00 00 00 */	cmplwi r0, 0
/* 8005F4E8 0005C448  41 82 00 44 */	beq .L_8005F52C
/* 8005F4EC 0005C44C  4B FE 02 3D */	bl detachObjs__9StdSystemFv
/* 8005F4F0 0005C450  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F4F4 0005C454  80 63 00 34 */	lwz r3, 0x34(r3)
/* 8005F4F8 0005C458  4B FE 14 8D */	bl reset__6TimersFv
/* 8005F4FC 0005C45C  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8005F500 0005C460  38 00 00 00 */	li r0, 0
/* 8005F504 0005C464  38 7F 00 00 */	addi r3, r31, 0
/* 8005F508 0005C468  98 04 00 00 */	stb r0, 0(r4)
/* 8005F50C 0005C46C  81 9F 00 00 */	lwz r12, 0(r31)
/* 8005F510 0005C470  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 8005F514 0005C474  7D 88 03 A6 */	mtlr r12
/* 8005F518 0005C478  4E 80 00 21 */	blrl 
/* 8005F51C 0005C47C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F520 0005C480  4B FE 01 6D */	bl attachObjs__9StdSystemFv
/* 8005F524 0005C484  38 60 00 01 */	li r3, 1
/* 8005F528 0005C488  48 00 00 A0 */	b .L_8005F5C8
.L_8005F52C:
/* 8005F52C 0005C48C  7F E3 FB 78 */	mr r3, r31
/* 8005F530 0005C490  81 9F 00 00 */	lwz r12, 0(r31)
/* 8005F534 0005C494  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8005F538 0005C498  7D 88 03 A6 */	mtlr r12
/* 8005F53C 0005C49C  4E 80 00 21 */	blrl 
/* 8005F540 0005C4A0  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F544 0005C4A4  4B FE 55 35 */	bl beginRender__6SystemFv
/* 8005F548 0005C4A8  7F E3 FB 78 */	mr r3, r31
/* 8005F54C 0005C4AC  4B FE D3 BD */	bl renderall__7GameAppFv
/* 8005F550 0005C4B0  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8005F554 0005C4B4  80 64 02 54 */	lwz r3, 0x254(r4)
/* 8005F558 0005C4B8  28 03 00 00 */	cmplwi r3, 0
/* 8005F55C 0005C4BC  41 82 00 18 */	beq .L_8005F574
/* 8005F560 0005C4C0  81 83 00 00 */	lwz r12, 0(r3)
/* 8005F564 0005C4C4  80 84 02 4C */	lwz r4, 0x24c(r4)
/* 8005F568 0005C4C8  81 8C 00 08 */	lwz r12, 8(r12)
/* 8005F56C 0005C4CC  7D 88 03 A6 */	mtlr r12
/* 8005F570 0005C4D0  4E 80 00 21 */	blrl 
.L_8005F574:
/* 8005F574 0005C4D4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F578 0005C4D8  4B FE 55 F5 */	bl doneRender__6SystemFv
/* 8005F57C 0005C4DC  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005F580 0005C4E0  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 8005F584 0005C4E4  80 63 01 E8 */	lwz r3, 0x1e8(r3)
/* 8005F588 0005C4E8  28 03 00 00 */	cmplwi r3, 0
/* 8005F58C 0005C4EC  41 82 00 14 */	beq .L_8005F5A0
/* 8005F590 0005C4F0  81 83 00 00 */	lwz r12, 0(r3)
/* 8005F594 0005C4F4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8005F598 0005C4F8  7D 88 03 A6 */	mtlr r12
/* 8005F59C 0005C4FC  4E 80 00 21 */	blrl 
.L_8005F5A0:
/* 8005F5A0 0005C500  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F5A4 0005C504  38 8D 91 2C */	addi r4, r13, lbl_803DDE4C@sda21
/* 8005F5A8 0005C508  80 63 00 34 */	lwz r3, 0x34(r3)
/* 8005F5AC 0005C50C  4B FE 13 FD */	bl _stop__6TimersFPc
/* 8005F5B0 0005C510  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F5B4 0005C514  4B FE 55 DD */	bl waitRetrace__6SystemFv
/* 8005F5B8 0005C518  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F5BC 0005C51C  38 80 FF FF */	li r4, -1
/* 8005F5C0 0005C520  4B FD FA A9 */	bl setHeap__9StdSystemFi
/* 8005F5C4 0005C524  38 60 00 01 */	li r3, 1
.L_8005F5C8:
/* 8005F5C8 0005C528  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8005F5CC 0005C52C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8005F5D0 0005C530  38 21 00 18 */	addi r1, r1, 0x18
/* 8005F5D4 0005C534  7C 08 03 A6 */	mtlr r0
/* 8005F5D8 0005C538  4E 80 00 20 */	blr 

.global __ct__11PlugPikiAppFv
__ct__11PlugPikiAppFv:
/* 8005F5DC 0005C53C  7C 08 02 A6 */	mflr r0
/* 8005F5E0 0005C540  90 01 00 04 */	stw r0, 4(r1)
/* 8005F5E4 0005C544  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8005F5E8 0005C548  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8005F5EC 0005C54C  90 61 00 08 */	stw r3, 8(r1)
/* 8005F5F0 0005C550  83 E1 00 08 */	lwz r31, 8(r1)
/* 8005F5F4 0005C554  7F E3 FB 78 */	mr r3, r31
/* 8005F5F8 0005C558  4B FC 58 05 */	bl __ct__7BaseAppFv
/* 8005F5FC 0005C55C  3C 60 80 2B */	lis r3, __vt__7GameApp@ha
/* 8005F600 0005C560  38 03 88 50 */	addi r0, r3, __vt__7GameApp@l
/* 8005F604 0005C564  3C 60 80 2B */	lis r3, __vt__11PlugPikiApp@ha
/* 8005F608 0005C568  90 1F 00 00 */	stw r0, 0(r31)
/* 8005F60C 0005C56C  38 03 88 D4 */	addi r0, r3, __vt__11PlugPikiApp@l
/* 8005F610 0005C570  3C 60 80 2B */	lis r3, lbl_802A873C@ha
/* 8005F614 0005C574  90 1F 00 00 */	stw r0, 0(r31)
/* 8005F618 0005C578  38 03 87 3C */	addi r0, r3, lbl_802A873C@l
/* 8005F61C 0005C57C  90 1F 00 04 */	stw r0, 4(r31)
/* 8005F620 0005C580  38 80 00 00 */	li r4, 0
/* 8005F624 0005C584  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F628 0005C588  4B FD FA 41 */	bl setHeap__9StdSystemFi
/* 8005F62C 0005C58C  7F E3 FB 78 */	mr r3, r31
/* 8005F630 0005C590  4B FF F7 C1 */	bl hardReset__11PlugPikiAppFv
/* 8005F634 0005C594  38 60 00 14 */	li r3, 0x14
/* 8005F638 0005C598  4B FE 79 CD */	bl alloc__6SystemFUl
/* 8005F63C 0005C59C  28 03 00 00 */	cmplwi r3, 0
/* 8005F640 0005C5A0  41 82 00 34 */	beq .L_8005F674
/* 8005F644 0005C5A4  3C 80 80 22 */	lis r4, __vt__6Stream@ha
/* 8005F648 0005C5A8  38 04 73 98 */	addi r0, r4, __vt__6Stream@l
/* 8005F64C 0005C5AC  3C 80 80 23 */	lis r4, __vt__9AtxStream@ha
/* 8005F650 0005C5B0  90 03 00 04 */	stw r0, 4(r3)
/* 8005F654 0005C5B4  38 04 8F C4 */	addi r0, r4, __vt__9AtxStream@l
/* 8005F658 0005C5B8  90 03 00 04 */	stw r0, 4(r3)
/* 8005F65C 0005C5BC  38 00 00 00 */	li r0, 0
/* 8005F660 0005C5C0  3C 80 80 2B */	lis r4, __vt__16AtxCommandStream@ha
/* 8005F664 0005C5C4  90 03 00 0C */	stw r0, 0xc(r3)
/* 8005F668 0005C5C8  38 04 87 8C */	addi r0, r4, __vt__16AtxCommandStream@l
/* 8005F66C 0005C5CC  90 03 00 04 */	stw r0, 4(r3)
/* 8005F670 0005C5D0  93 E3 00 10 */	stw r31, 0x10(r3)
.L_8005F674:
/* 8005F674 0005C5D4  83 E1 00 08 */	lwz r31, 8(r1)
/* 8005F678 0005C5D8  38 8D 91 30 */	addi r4, r13, lbl_803DDE50@sda21
/* 8005F67C 0005C5DC  38 A0 00 03 */	li r5, 3
/* 8005F680 0005C5E0  90 7F 00 20 */	stw r3, 0x20(r31)
/* 8005F684 0005C5E4  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 8005F688 0005C5E8  4B FE 42 9D */	bl open__9AtxStreamFPci
/* 8005F68C 0005C5EC  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8005F690 0005C5F0  41 82 00 14 */	beq .L_8005F6A4
/* 8005F694 0005C5F4  80 1F 00 04 */	lwz r0, 4(r31)
/* 8005F698 0005C5F8  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 8005F69C 0005C5FC  90 03 00 00 */	stw r0, 0(r3)
/* 8005F6A0 0005C600  48 00 00 0C */	b .L_8005F6AC
.L_8005F6A4:
/* 8005F6A4 0005C604  38 00 00 00 */	li r0, 0
/* 8005F6A8 0005C608  90 1F 00 20 */	stw r0, 0x20(r31)
.L_8005F6AC:
/* 8005F6AC 0005C60C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F6B0 0005C610  38 00 00 01 */	li r0, 1
/* 8005F6B4 0005C614  90 03 00 18 */	stw r0, 0x18(r3)
/* 8005F6B8 0005C618  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F6BC 0005C61C  4B FE 61 65 */	bl hardReset__6SystemFv
/* 8005F6C0 0005C620  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F6C4 0005C624  80 83 01 94 */	lwz r4, 0x194(r3)
/* 8005F6C8 0005C628  4B FD F9 59 */	bl getHeap__9StdSystemFi
/* 8005F6CC 0005C62C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F6D0 0005C630  80 83 01 94 */	lwz r4, 0x194(r3)
/* 8005F6D4 0005C634  4B FD F9 4D */	bl getHeap__9StdSystemFi
/* 8005F6D8 0005C638  80 83 00 08 */	lwz r4, 8(r3)
/* 8005F6DC 0005C63C  38 00 00 00 */	li r0, 0
/* 8005F6E0 0005C640  80 63 00 04 */	lwz r3, 4(r3)
/* 8005F6E4 0005C644  3C A0 43 30 */	lis r5, 0x4330
/* 8005F6E8 0005C648  7C 64 18 50 */	subf r3, r4, r3
/* 8005F6EC 0005C64C  6C 64 80 00 */	xoris r4, r3, 0x8000
/* 8005F6F0 0005C650  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F6F4 0005C654  90 81 00 1C */	stw r4, 0x1c(r1)
/* 8005F6F8 0005C658  38 80 FF FF */	li r4, -1
/* 8005F6FC 0005C65C  90 03 01 98 */	stw r0, 0x198(r3)
/* 8005F700 0005C660  90 A1 00 18 */	stw r5, 0x18(r1)
/* 8005F704 0005C664  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005F708 0005C668  4B FD F9 61 */	bl setHeap__9StdSystemFi
/* 8005F70C 0005C66C  80 61 00 08 */	lwz r3, 8(r1)
/* 8005F710 0005C670  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8005F714 0005C674  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8005F718 0005C678  38 21 00 28 */	addi r1, r1, 0x28
/* 8005F71C 0005C67C  7C 08 03 A6 */	mtlr r0
/* 8005F720 0005C680  4E 80 00 20 */	blr 

.global __dt__7GameAppFv
__dt__7GameAppFv:
/* 8005F724 0005C684  7C 08 02 A6 */	mflr r0
/* 8005F728 0005C688  90 01 00 04 */	stw r0, 4(r1)
/* 8005F72C 0005C68C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8005F730 0005C690  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8005F734 0005C694  3B E4 00 00 */	addi r31, r4, 0
/* 8005F738 0005C698  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8005F73C 0005C69C  7C 7E 1B 79 */	or. r30, r3, r3
/* 8005F740 0005C6A0  41 82 00 2C */	beq .L_8005F76C
/* 8005F744 0005C6A4  3C 60 80 2B */	lis r3, __vt__7GameApp@ha
/* 8005F748 0005C6A8  38 03 88 50 */	addi r0, r3, __vt__7GameApp@l
/* 8005F74C 0005C6AC  90 1E 00 00 */	stw r0, 0(r30)
/* 8005F750 0005C6B0  38 7E 00 00 */	addi r3, r30, 0
/* 8005F754 0005C6B4  38 80 00 00 */	li r4, 0
/* 8005F758 0005C6B8  4B FC 57 CD */	bl __dt__7BaseAppFv
/* 8005F75C 0005C6BC  7F E0 07 35 */	extsh. r0, r31
/* 8005F760 0005C6C0  40 81 00 0C */	ble .L_8005F76C
/* 8005F764 0005C6C4  7F C3 F3 78 */	mr r3, r30
/* 8005F768 0005C6C8  4B FE 7A 45 */	bl __dl__FPv
.L_8005F76C:
/* 8005F76C 0005C6CC  7F C3 F3 78 */	mr r3, r30
/* 8005F770 0005C6D0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8005F774 0005C6D4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8005F778 0005C6D8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8005F77C 0005C6DC  38 21 00 18 */	addi r1, r1, 0x18
/* 8005F780 0005C6E0  7C 08 03 A6 */	mtlr r0
/* 8005F784 0005C6E4  4E 80 00 20 */	blr 

.global idle__7GameAppFv
idle__7GameAppFv:
/* 8005F788 0005C6E8  38 60 00 01 */	li r3, 1
/* 8005F78C 0005C6EC  4E 80 00 20 */	blr 

.global __dt__11PlugPikiAppFv
__dt__11PlugPikiAppFv:
/* 8005F790 0005C6F0  7C 08 02 A6 */	mflr r0
/* 8005F794 0005C6F4  90 01 00 04 */	stw r0, 4(r1)
/* 8005F798 0005C6F8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8005F79C 0005C6FC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8005F7A0 0005C700  3B E4 00 00 */	addi r31, r4, 0
/* 8005F7A4 0005C704  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8005F7A8 0005C708  7C 7E 1B 79 */	or. r30, r3, r3
/* 8005F7AC 0005C70C  41 82 00 3C */	beq .L_8005F7E8
/* 8005F7B0 0005C710  3C 60 80 2B */	lis r3, __vt__11PlugPikiApp@ha
/* 8005F7B4 0005C714  38 03 88 D4 */	addi r0, r3, __vt__11PlugPikiApp@l
/* 8005F7B8 0005C718  90 1E 00 00 */	stw r0, 0(r30)
/* 8005F7BC 0005C71C  41 82 00 1C */	beq .L_8005F7D8
/* 8005F7C0 0005C720  3C 60 80 2B */	lis r3, __vt__7GameApp@ha
/* 8005F7C4 0005C724  38 03 88 50 */	addi r0, r3, __vt__7GameApp@l
/* 8005F7C8 0005C728  90 1E 00 00 */	stw r0, 0(r30)
/* 8005F7CC 0005C72C  38 7E 00 00 */	addi r3, r30, 0
/* 8005F7D0 0005C730  38 80 00 00 */	li r4, 0
/* 8005F7D4 0005C734  4B FC 57 51 */	bl __dt__7BaseAppFv
.L_8005F7D8:
/* 8005F7D8 0005C738  7F E0 07 35 */	extsh. r0, r31
/* 8005F7DC 0005C73C  40 81 00 0C */	ble .L_8005F7E8
/* 8005F7E0 0005C740  7F C3 F3 78 */	mr r3, r30
/* 8005F7E4 0005C744  4B FE 79 C9 */	bl __dl__FPv
.L_8005F7E8:
/* 8005F7E8 0005C748  7F C3 F3 78 */	mr r3, r30
/* 8005F7EC 0005C74C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8005F7F0 0005C750  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8005F7F4 0005C754  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8005F7F8 0005C758  38 21 00 18 */	addi r1, r1, 0x18
/* 8005F7FC 0005C75C  7C 08 03 A6 */	mtlr r0
/* 8005F800 0005C760  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802A86B0:
	.asciz "plugPiki.cpp"
.balign 4
lbl_802A86C0:
	.asciz "plugPiki"
.balign 4
lbl_802A86CC:
	.asciz "%d polys = %d pps"
.balign 4
lbl_802A86E0:
	.asciz "%d anims"
.balign 4
lbl_802A86EC:
	.asciz "%d disps"
.balign 4
lbl_802A86F8:
	.asciz "%d / %d lighting skips / sets"
.balign 4
lbl_802A8718:
	.asciz "%d light sets"
.balign 4
lbl_802A8728:
	.asciz "load took %.1f secs"
.balign 4
lbl_802A873C:
	.asciz "Piki the Game"
.balign 4
lbl_802A874C:
	.asciz "AtxCommandStream"
.balign 4
lbl_802A8760:
	.asciz "AtxStream"
.balign 4
lbl_802A876C:
	.4byte __RTTI__6Stream
	.4byte 0
	.4byte 0
lbl_802A8778:
	.4byte __RTTI__6Stream
	.4byte 0
	.4byte __RTTI__9AtxStream
	.4byte 0
	.4byte 0
.global __vt__16AtxCommandStream
__vt__16AtxCommandStream:
	.4byte __RTTI__16AtxCommandStream
	.4byte 0
	.4byte readInt__6StreamFv
	.4byte readByte__6StreamFv
	.4byte readShort__6StreamFv
	.4byte readFloat__6StreamFv
	.4byte readString__6StreamFPci
	.4byte readString__6StreamFR6String
	.4byte readString__6StreamFv
	.4byte writeInt__6StreamFi
	.4byte writeByte__6StreamFUc
	.4byte writeShort__6StreamFs
	.4byte writeFloat__6StreamFf
	.4byte writeString__6StreamFPc
	.4byte writeString__6StreamFR6String
	.4byte read__9AtxStreamFPvi
	.4byte write__9AtxStreamFPvi
	.4byte getPending__9AtxStreamFv
	.4byte getAvailable__6StreamFv
	.4byte close__9AtxStreamFv
	.4byte getClosing__6StreamFv
	.4byte flush__9AtxStreamFv
.balign 4
lbl_802A87E4:
	.asciz "CoreNode"
.balign 4
lbl_802A87F0:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
lbl_802A87FC:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
lbl_802A8810:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
lbl_802A882C:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__7BaseApp
	.4byte 0
	.4byte 0
.global __vt__7GameApp
__vt__7GameApp:
	.4byte __RTTI__7GameApp
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__4NodeFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte __dt__7GameAppFv
	.4byte InitApp__7BaseAppFPc
	.4byte idle__7GameAppFv
	.4byte keyDown__7BaseAppFiii
	.4byte softReset__7BaseAppFv
	.4byte useHeap__7BaseAppFi
	.4byte procCmd__7BaseAppFPc
.balign 4
lbl_802A889C:
	.asciz "PlugPikiApp"
.balign 4
lbl_802A88A8:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__7BaseApp
	.4byte 0
	.4byte __RTTI__7GameApp
	.4byte 0
	.4byte 0
.global __vt__11PlugPikiApp
__vt__11PlugPikiApp:
	.4byte __RTTI__11PlugPikiApp
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__11PlugPikiAppFv
	.4byte draw__11PlugPikiAppFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte __dt__11PlugPikiAppFv
	.4byte InitApp__7BaseAppFPc
	.4byte idle__11PlugPikiAppFv
	.4byte keyDown__7BaseAppFiii
	.4byte softReset__11PlugPikiAppFv
	.4byte useHeap__7BaseAppFi
	.4byte procCmd__7BaseAppFPc

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DDE38:
	.asciz "ovl"
.balign 4
lbl_803DDE3C:
	.asciz "%d mats"
.balign 4
lbl_803DDE44:
	.asciz "%d mtxs"
.balign 4
lbl_803DDE4C:
	.asciz "all"
.balign 4
lbl_803DDE50:
	.asciz "app"
.balign 4
lbl_803DDE54:
	.asciz "Stream"
.balign 4
__RTTI__6Stream:
	.4byte lbl_803DDE54
	.4byte 0
__RTTI__9AtxStream:
	.4byte lbl_802A8760
	.4byte lbl_802A876C
__RTTI__16AtxCommandStream:
	.4byte lbl_802A874C
	.4byte lbl_802A8778
.balign 4
lbl_803DDE74:
	.asciz "GameApp"
.balign 4
lbl_803DDE7C:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803DDE7C
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802A87E4
	.4byte lbl_802A87F0
.balign 4
lbl_803DDE94:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803DDE94
	.4byte lbl_802A87FC
.balign 4
lbl_803DDEA4:
	.asciz "BaseApp"
.balign 4
__RTTI__7BaseApp:
	.4byte lbl_803DDEA4
	.4byte lbl_802A8810
__RTTI__7GameApp:
	.4byte lbl_803DDE74
	.4byte lbl_802A882C
__RTTI__11PlugPikiApp:
	.4byte lbl_802A889C
	.4byte lbl_802A88A8

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E88C0:
	.float 0.0
lbl_803E88C4:
	.float 0.1
.balign 8
lbl_803E88C8:
	.4byte 0x43300000
	.4byte 0x80000000
