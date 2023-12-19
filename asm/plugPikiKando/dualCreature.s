.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__12DualCreatureFv, global
/* 80091EC0 0008EE20  7C 08 02 A6 */	mflr r0
/* 80091EC4 0008EE24  90 01 00 04 */	stw r0, 4(r1)
/* 80091EC8 0008EE28  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80091ECC 0008EE2C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80091ED0 0008EE30  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80091ED4 0008EE34  7C 7E 1B 78 */	mr r30, r3
/* 80091ED8 0008EE38  48 00 0C 15 */	bl __ct__11DynCreatureFv
/* 80091EDC 0008EE3C  3C 60 80 2B */	lis r3, __vt__12DualCreature@ha
/* 80091EE0 0008EE40  38 03 F6 0C */	addi r0, r3, __vt__12DualCreature@l
/* 80091EE4 0008EE44  90 1E 00 00 */	stw r0, 0(r30)
/* 80091EE8 0008EE48  3B E0 00 00 */	li r31, 0
/* 80091EEC 0008EE4C  38 7E 00 00 */	addi r3, r30, 0
/* 80091EF0 0008EE50  9B FE 04 3D */	stb r31, 0x43d(r30)
/* 80091EF4 0008EE54  80 1E 00 C8 */	lwz r0, 0xc8(r30)
/* 80091EF8 0008EE58  60 00 02 01 */	ori r0, r0, 0x201
/* 80091EFC 0008EE5C  90 1E 00 C8 */	stw r0, 0xc8(r30)
/* 80091F00 0008EE60  C0 0D A4 48 */	lfs f0, lbl_803DF168@sda21(r13)
/* 80091F04 0008EE64  D0 1E 00 D4 */	stfs f0, 0xd4(r30)
/* 80091F08 0008EE68  C0 0D A4 4C */	lfs f0, lbl_803DF16C@sda21(r13)
/* 80091F0C 0008EE6C  D0 1E 00 D8 */	stfs f0, 0xd8(r30)
/* 80091F10 0008EE70  C0 0D A4 50 */	lfs f0, lbl_803DF170@sda21(r13)
/* 80091F14 0008EE74  D0 1E 00 DC */	stfs f0, 0xdc(r30)
/* 80091F18 0008EE78  C0 0D A4 54 */	lfs f0, lbl_803DF174@sda21(r13)
/* 80091F1C 0008EE7C  D0 1E 02 B8 */	stfs f0, 0x2b8(r30)
/* 80091F20 0008EE80  C0 0D A4 58 */	lfs f0, lbl_803DF178@sda21(r13)
/* 80091F24 0008EE84  D0 1E 02 BC */	stfs f0, 0x2bc(r30)
/* 80091F28 0008EE88  C0 0D A4 5C */	lfs f0, lbl_803DF17C@sda21(r13)
/* 80091F2C 0008EE8C  D0 1E 02 C0 */	stfs f0, 0x2c0(r30)
/* 80091F30 0008EE90  48 00 01 5D */	bl useRealDynamics__12DualCreatureFv
/* 80091F34 0008EE94  9B FE 04 3F */	stb r31, 0x43f(r30)
/* 80091F38 0008EE98  7F C3 F3 78 */	mr r3, r30
/* 80091F3C 0008EE9C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80091F40 0008EEA0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80091F44 0008EEA4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80091F48 0008EEA8  38 21 00 18 */	addi r1, r1, 0x18
/* 80091F4C 0008EEAC  7C 08 03 A6 */	mtlr r0
/* 80091F50 0008EEB0  4E 80 00 20 */	blr 
.endfn __ct__12DualCreatureFv

.fn doKill__12DualCreatureFv, global
/* 80091F54 0008EEB4  7C 08 02 A6 */	mflr r0
/* 80091F58 0008EEB8  90 01 00 04 */	stw r0, 4(r1)
/* 80091F5C 0008EEBC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80091F60 0008EEC0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80091F64 0008EEC4  7C 7F 1B 78 */	mr r31, r3
/* 80091F68 0008EEC8  48 00 1F A5 */	bl doKill__11DynCreatureFv
/* 80091F6C 0008EECC  38 00 00 00 */	li r0, 0
/* 80091F70 0008EED0  98 1F 04 3D */	stb r0, 0x43d(r31)
/* 80091F74 0008EED4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80091F78 0008EED8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80091F7C 0008EEDC  38 21 00 18 */	addi r1, r1, 0x18
/* 80091F80 0008EEE0  7C 08 03 A6 */	mtlr r0
/* 80091F84 0008EEE4  4E 80 00 20 */	blr 
.endfn doKill__12DualCreatureFv

.fn isFrontFace__12DualCreatureFv, global
/* 80091F88 0008EEE8  7C 08 02 A6 */	mflr r0
/* 80091F8C 0008EEEC  90 01 00 04 */	stw r0, 4(r1)
/* 80091F90 0008EEF0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80091F94 0008EEF4  88 03 04 3C */	lbz r0, 0x43c(r3)
/* 80091F98 0008EEF8  28 00 00 00 */	cmplwi r0, 0
/* 80091F9C 0008EEFC  41 82 00 38 */	beq .L_80091FD4
/* 80091FA0 0008EF00  C0 02 8B 60 */	lfs f0, lbl_803E8D60@sda21(r2)
/* 80091FA4 0008EF04  38 63 00 E0 */	addi r3, r3, 0xe0
/* 80091FA8 0008EF08  38 81 00 0C */	addi r4, r1, 0xc
/* 80091FAC 0008EF0C  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 80091FB0 0008EF10  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 80091FB4 0008EF14  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 80091FB8 0008EF18  4B FA 60 CD */	bl genVectorY__4QuatFR8Vector3f
/* 80091FBC 0008EF1C  C0 21 00 10 */	lfs f1, 0x10(r1)
/* 80091FC0 0008EF20  C0 02 8B 64 */	lfs f0, lbl_803E8D64@sda21(r2)
/* 80091FC4 0008EF24  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80091FC8 0008EF28  7C 00 00 26 */	mfcr r0
/* 80091FCC 0008EF2C  54 03 17 FE */	rlwinm r3, r0, 2, 0x1f, 0x1f
/* 80091FD0 0008EF30  48 00 00 08 */	b .L_80091FD8
.L_80091FD4:
/* 80091FD4 0008EF34  38 60 00 01 */	li r3, 1
.L_80091FD8:
/* 80091FD8 0008EF38  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80091FDC 0008EF3C  38 21 00 18 */	addi r1, r1, 0x18
/* 80091FE0 0008EF40  7C 08 03 A6 */	mtlr r0
/* 80091FE4 0008EF44  4E 80 00 20 */	blr 
.endfn isFrontFace__12DualCreatureFv

.fn getY__12DualCreatureFv, global
/* 80091FE8 0008EF48  7C 08 02 A6 */	mflr r0
/* 80091FEC 0008EF4C  90 01 00 04 */	stw r0, 4(r1)
/* 80091FF0 0008EF50  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80091FF4 0008EF54  88 03 04 3C */	lbz r0, 0x43c(r3)
/* 80091FF8 0008EF58  28 00 00 00 */	cmplwi r0, 0
/* 80091FFC 0008EF5C  41 82 00 28 */	beq .L_80092024
/* 80092000 0008EF60  C0 02 8B 60 */	lfs f0, lbl_803E8D60@sda21(r2)
/* 80092004 0008EF64  38 63 00 E0 */	addi r3, r3, 0xe0
/* 80092008 0008EF68  38 81 00 0C */	addi r4, r1, 0xc
/* 8009200C 0008EF6C  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 80092010 0008EF70  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 80092014 0008EF74  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 80092018 0008EF78  4B FA 60 6D */	bl genVectorY__4QuatFR8Vector3f
/* 8009201C 0008EF7C  C0 21 00 10 */	lfs f1, 0x10(r1)
/* 80092020 0008EF80  48 00 00 08 */	b .L_80092028
.L_80092024:
/* 80092024 0008EF84  C0 22 8B 68 */	lfs f1, lbl_803E8D68@sda21(r2)
.L_80092028:
/* 80092028 0008EF88  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8009202C 0008EF8C  38 21 00 18 */	addi r1, r1, 0x18
/* 80092030 0008EF90  7C 08 03 A6 */	mtlr r0
/* 80092034 0008EF94  4E 80 00 20 */	blr 
.endfn getY__12DualCreatureFv

.fn onGround__12DualCreatureFv, global
/* 80092038 0008EF98  88 03 04 3C */	lbz r0, 0x43c(r3)
/* 8009203C 0008EF9C  28 00 00 00 */	cmplwi r0, 0
/* 80092040 0008EFA0  41 82 00 34 */	beq .L_80092074
/* 80092044 0008EFA4  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 80092048 0008EFA8  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8009204C 0008EFAC  41 82 00 0C */	beq .L_80092058
/* 80092050 0008EFB0  38 60 00 01 */	li r3, 1
/* 80092054 0008EFB4  4E 80 00 20 */	blr 
.L_80092058:
/* 80092058 0008EFB8  88 03 04 39 */	lbz r0, 0x439(r3)
/* 8009205C 0008EFBC  28 00 00 00 */	cmplwi r0, 0
/* 80092060 0008EFC0  41 82 00 0C */	beq .L_8009206C
/* 80092064 0008EFC4  38 60 00 01 */	li r3, 1
/* 80092068 0008EFC8  4E 80 00 20 */	blr 
.L_8009206C:
/* 8009206C 0008EFCC  38 60 00 00 */	li r3, 0
/* 80092070 0008EFD0  4E 80 00 20 */	blr 
.L_80092074:
/* 80092074 0008EFD4  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 80092078 0008EFD8  54 00 07 7A */	rlwinm r0, r0, 0, 0x1d, 0x1d
/* 8009207C 0008EFDC  7C 60 00 D0 */	neg r3, r0
/* 80092080 0008EFE0  30 03 FF FF */	addic r0, r3, -1
/* 80092084 0008EFE4  7C 60 19 10 */	subfe r3, r0, r3
/* 80092088 0008EFE8  4E 80 00 20 */	blr 
.endfn onGround__12DualCreatureFv

.fn useRealDynamics__12DualCreatureFv, global
/* 8009208C 0008EFEC  7C 08 02 A6 */	mflr r0
/* 80092090 0008EFF0  7C 65 1B 78 */	mr r5, r3
/* 80092094 0008EFF4  90 01 00 04 */	stw r0, 4(r1)
/* 80092098 0008EFF8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8009209C 0008EFFC  88 03 04 3F */	lbz r0, 0x43f(r3)
/* 800920A0 0008F000  28 00 00 00 */	cmplwi r0, 0
/* 800920A4 0008F004  40 82 00 20 */	bne .L_800920C4
/* 800920A8 0008F008  38 00 00 01 */	li r0, 1
/* 800920AC 0008F00C  98 05 04 3E */	stb r0, 0x43e(r5)
/* 800920B0 0008F010  38 65 00 E0 */	addi r3, r5, 0xe0
/* 800920B4 0008F014  38 85 00 88 */	addi r4, r5, 0x88
/* 800920B8 0008F018  98 05 04 3C */	stb r0, 0x43c(r5)
/* 800920BC 0008F01C  4B FA 62 2D */	bl fromEuler__4QuatFR8Vector3f
/* 800920C0 0008F020  48 00 00 0C */	b .L_800920CC
.L_800920C4:
/* 800920C4 0008F024  7C A3 2B 78 */	mr r3, r5
/* 800920C8 0008F028  48 00 00 15 */	bl useSimpleDynamics__12DualCreatureFv
.L_800920CC:
/* 800920CC 0008F02C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800920D0 0008F030  38 21 00 08 */	addi r1, r1, 8
/* 800920D4 0008F034  7C 08 03 A6 */	mtlr r0
/* 800920D8 0008F038  4E 80 00 20 */	blr 
.endfn useRealDynamics__12DualCreatureFv

.fn useSimpleDynamics__12DualCreatureFv, global
/* 800920DC 0008F03C  38 00 00 01 */	li r0, 1
/* 800920E0 0008F040  98 03 04 3E */	stb r0, 0x43e(r3)
/* 800920E4 0008F044  38 00 00 00 */	li r0, 0
/* 800920E8 0008F048  98 03 04 3C */	stb r0, 0x43c(r3)
/* 800920EC 0008F04C  C0 0D A4 60 */	lfs f0, lbl_803DF180@sda21(r13)
/* 800920F0 0008F050  D0 03 00 D4 */	stfs f0, 0xd4(r3)
/* 800920F4 0008F054  C0 0D A4 64 */	lfs f0, lbl_803DF184@sda21(r13)
/* 800920F8 0008F058  D0 03 00 D8 */	stfs f0, 0xd8(r3)
/* 800920FC 0008F05C  C0 0D A4 68 */	lfs f0, lbl_803DF188@sda21(r13)
/* 80092100 0008F060  D0 03 00 DC */	stfs f0, 0xdc(r3)
/* 80092104 0008F064  C0 0D A4 6C */	lfs f0, lbl_803DF18C@sda21(r13)
/* 80092108 0008F068  D0 03 02 B8 */	stfs f0, 0x2b8(r3)
/* 8009210C 0008F06C  C0 0D A4 70 */	lfs f0, lbl_803DF190@sda21(r13)
/* 80092110 0008F070  D0 03 02 BC */	stfs f0, 0x2bc(r3)
/* 80092114 0008F074  C0 0D A4 74 */	lfs f0, lbl_803DF194@sda21(r13)
/* 80092118 0008F078  D0 03 02 C0 */	stfs f0, 0x2c0(r3)
/* 8009211C 0008F07C  4E 80 00 20 */	blr 
.endfn useSimpleDynamics__12DualCreatureFv

.fn rotateY__12DualCreatureFf, global
/* 80092120 0008F080  7C 08 02 A6 */	mflr r0
/* 80092124 0008F084  90 01 00 04 */	stw r0, 4(r1)
/* 80092128 0008F088  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8009212C 0008F08C  93 E1 00 34 */	stw r31, 0x34(r1)
/* 80092130 0008F090  7C 7F 1B 78 */	mr r31, r3
/* 80092134 0008F094  88 03 04 3C */	lbz r0, 0x43c(r3)
/* 80092138 0008F098  28 00 00 00 */	cmplwi r0, 0
/* 8009213C 0008F09C  41 82 00 6C */	beq .L_800921A8
/* 80092140 0008F0A0  C0 62 8B 60 */	lfs f3, lbl_803E8D60@sda21(r2)
/* 80092144 0008F0A4  38 81 00 10 */	addi r4, r1, 0x10
/* 80092148 0008F0A8  C0 4D A4 78 */	lfs f2, lbl_803DF198@sda21(r13)
/* 8009214C 0008F0AC  38 61 00 1C */	addi r3, r1, 0x1c
/* 80092150 0008F0B0  D0 61 00 24 */	stfs f3, 0x24(r1)
/* 80092154 0008F0B4  C0 0D A4 7C */	lfs f0, lbl_803DF19C@sda21(r13)
/* 80092158 0008F0B8  D0 41 00 10 */	stfs f2, 0x10(r1)
/* 8009215C 0008F0BC  D0 61 00 20 */	stfs f3, 0x20(r1)
/* 80092160 0008F0C0  D0 21 00 14 */	stfs f1, 0x14(r1)
/* 80092164 0008F0C4  D0 61 00 1C */	stfs f3, 0x1c(r1)
/* 80092168 0008F0C8  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 8009216C 0008F0CC  4B FA 61 7D */	bl fromEuler__4QuatFR8Vector3f
/* 80092170 0008F0D0  38 61 00 1C */	addi r3, r1, 0x1c
/* 80092174 0008F0D4  38 9F 00 E0 */	addi r4, r31, 0xe0
/* 80092178 0008F0D8  4B FA 5C CD */	bl multiply__4QuatFR4Quat
/* 8009217C 0008F0DC  80 81 00 1C */	lwz r4, 0x1c(r1)
/* 80092180 0008F0E0  38 7F 00 E0 */	addi r3, r31, 0xe0
/* 80092184 0008F0E4  80 01 00 20 */	lwz r0, 0x20(r1)
/* 80092188 0008F0E8  90 9F 00 E0 */	stw r4, 0xe0(r31)
/* 8009218C 0008F0EC  90 1F 00 E4 */	stw r0, 0xe4(r31)
/* 80092190 0008F0F0  80 81 00 24 */	lwz r4, 0x24(r1)
/* 80092194 0008F0F4  80 01 00 28 */	lwz r0, 0x28(r1)
/* 80092198 0008F0F8  90 9F 00 E8 */	stw r4, 0xe8(r31)
/* 8009219C 0008F0FC  90 1F 00 EC */	stw r0, 0xec(r31)
/* 800921A0 0008F100  4B FA 5D 91 */	bl normalise__4QuatFv
/* 800921A4 0008F104  48 00 00 2C */	b .L_800921D0
.L_800921A8:
/* 800921A8 0008F108  C0 1F 00 A0 */	lfs f0, 0xa0(r31)
/* 800921AC 0008F10C  EC 20 08 2A */	fadds f1, f0, f1
/* 800921B0 0008F110  4B FA 63 D9 */	bl roundAng__Ff
/* 800921B4 0008F114  D0 3F 00 A0 */	stfs f1, 0xa0(r31)
/* 800921B8 0008F118  C0 0D A4 80 */	lfs f0, lbl_803DF1A0@sda21(r13)
/* 800921BC 0008F11C  D0 1F 00 88 */	stfs f0, 0x88(r31)
/* 800921C0 0008F120  C0 1F 00 A0 */	lfs f0, 0xa0(r31)
/* 800921C4 0008F124  D0 1F 00 8C */	stfs f0, 0x8c(r31)
/* 800921C8 0008F128  C0 0D A4 84 */	lfs f0, lbl_803DF1A4@sda21(r13)
/* 800921CC 0008F12C  D0 1F 00 90 */	stfs f0, 0x90(r31)
.L_800921D0:
/* 800921D0 0008F130  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800921D4 0008F134  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800921D8 0008F138  38 21 00 38 */	addi r1, r1, 0x38
/* 800921DC 0008F13C  7C 08 03 A6 */	mtlr r0
/* 800921E0 0008F140  4E 80 00 20 */	blr 
.endfn rotateY__12DualCreatureFf

.fn update__12DualCreatureFv, global
/* 800921E4 0008F144  7C 08 02 A6 */	mflr r0
/* 800921E8 0008F148  90 01 00 04 */	stw r0, 4(r1)
/* 800921EC 0008F14C  94 21 FF F8 */	stwu r1, -8(r1)
/* 800921F0 0008F150  88 03 04 3C */	lbz r0, 0x43c(r3)
/* 800921F4 0008F154  28 00 00 00 */	cmplwi r0, 0
/* 800921F8 0008F158  41 82 00 0C */	beq .L_80092204
/* 800921FC 0008F15C  48 00 0D 0D */	bl update__11DynCreatureFv
/* 80092200 0008F160  48 00 00 08 */	b .L_80092208
.L_80092204:
/* 80092204 0008F164  4B FF 90 05 */	bl update__8CreatureFv
.L_80092208:
/* 80092208 0008F168  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8009220C 0008F16C  38 21 00 08 */	addi r1, r1, 8
/* 80092210 0008F170  7C 08 03 A6 */	mtlr r0
/* 80092214 0008F174  4E 80 00 20 */	blr 
.endfn update__12DualCreatureFv

.fn refresh__12DualCreatureFR8Graphics, global
/* 80092218 0008F178  7C 08 02 A6 */	mflr r0
/* 8009221C 0008F17C  90 01 00 04 */	stw r0, 4(r1)
/* 80092220 0008F180  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 80092224 0008F184  93 E1 00 54 */	stw r31, 0x54(r1)
/* 80092228 0008F188  7C 9F 23 78 */	mr r31, r4
/* 8009222C 0008F18C  93 C1 00 50 */	stw r30, 0x50(r1)
/* 80092230 0008F190  7C 7E 1B 78 */	mr r30, r3
/* 80092234 0008F194  81 9E 00 00 */	lwz r12, 0(r30)
/* 80092238 0008F198  81 8C 00 64 */	lwz r12, 0x64(r12)
/* 8009223C 0008F19C  7D 88 03 A6 */	mtlr r12
/* 80092240 0008F1A0  4E 80 00 21 */	blrl 
/* 80092244 0008F1A4  C0 02 8B 6C */	lfs f0, lbl_803E8D6C@sda21(r2)
/* 80092248 0008F1A8  38 9E 00 94 */	addi r4, r30, 0x94
/* 8009224C 0008F1AC  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 80092250 0008F1B0  EC 20 00 72 */	fmuls f1, f0, f1
/* 80092254 0008F1B4  4B FA F3 31 */	bl isPointVisible__11CullFrustumFR8Vector3ff
/* 80092258 0008F1B8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8009225C 0008F1BC  41 82 00 14 */	beq .L_80092270
/* 80092260 0008F1C0  80 1E 00 C8 */	lwz r0, 0xc8(r30)
/* 80092264 0008F1C4  54 00 03 56 */	rlwinm r0, r0, 0, 0xd, 0xb
/* 80092268 0008F1C8  90 1E 00 C8 */	stw r0, 0xc8(r30)
/* 8009226C 0008F1CC  48 00 00 10 */	b .L_8009227C
.L_80092270:
/* 80092270 0008F1D0  80 1E 00 C8 */	lwz r0, 0xc8(r30)
/* 80092274 0008F1D4  64 00 00 08 */	oris r0, r0, 8
/* 80092278 0008F1D8  90 1E 00 C8 */	stw r0, 0xc8(r30)
.L_8009227C:
/* 8009227C 0008F1DC  88 1E 04 3E */	lbz r0, 0x43e(r30)
/* 80092280 0008F1E0  28 00 00 00 */	cmplwi r0, 0
/* 80092284 0008F1E4  40 82 00 D8 */	bne .L_8009235C
/* 80092288 0008F1E8  88 9E 04 3F */	lbz r4, 0x43f(r30)
/* 8009228C 0008F1EC  28 04 00 00 */	cmplwi r4, 0
/* 80092290 0008F1F0  40 82 00 80 */	bne .L_80092310
/* 80092294 0008F1F4  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80092298 0008F1F8  41 82 00 78 */	beq .L_80092310
/* 8009229C 0008F1FC  88 1E 04 3C */	lbz r0, 0x43c(r30)
/* 800922A0 0008F200  28 00 00 00 */	cmplwi r0, 0
/* 800922A4 0008F204  40 82 00 B8 */	bne .L_8009235C
/* 800922A8 0008F208  28 04 00 00 */	cmplwi r4, 0
/* 800922AC 0008F20C  40 82 00 20 */	bne .L_800922CC
/* 800922B0 0008F210  38 00 00 01 */	li r0, 1
/* 800922B4 0008F214  98 1E 04 3E */	stb r0, 0x43e(r30)
/* 800922B8 0008F218  38 7E 00 E0 */	addi r3, r30, 0xe0
/* 800922BC 0008F21C  38 9E 00 88 */	addi r4, r30, 0x88
/* 800922C0 0008F220  98 1E 04 3C */	stb r0, 0x43c(r30)
/* 800922C4 0008F224  4B FA 60 25 */	bl fromEuler__4QuatFR8Vector3f
/* 800922C8 0008F228  48 00 00 94 */	b .L_8009235C
.L_800922CC:
/* 800922CC 0008F22C  38 00 00 01 */	li r0, 1
/* 800922D0 0008F230  98 1E 04 3E */	stb r0, 0x43e(r30)
/* 800922D4 0008F234  38 00 00 00 */	li r0, 0
/* 800922D8 0008F238  98 1E 04 3C */	stb r0, 0x43c(r30)
/* 800922DC 0008F23C  C0 0D A4 60 */	lfs f0, lbl_803DF180@sda21(r13)
/* 800922E0 0008F240  D0 1E 00 D4 */	stfs f0, 0xd4(r30)
/* 800922E4 0008F244  C0 0D A4 64 */	lfs f0, lbl_803DF184@sda21(r13)
/* 800922E8 0008F248  D0 1E 00 D8 */	stfs f0, 0xd8(r30)
/* 800922EC 0008F24C  C0 0D A4 68 */	lfs f0, lbl_803DF188@sda21(r13)
/* 800922F0 0008F250  D0 1E 00 DC */	stfs f0, 0xdc(r30)
/* 800922F4 0008F254  C0 0D A4 6C */	lfs f0, lbl_803DF18C@sda21(r13)
/* 800922F8 0008F258  D0 1E 02 B8 */	stfs f0, 0x2b8(r30)
/* 800922FC 0008F25C  C0 0D A4 70 */	lfs f0, lbl_803DF190@sda21(r13)
/* 80092300 0008F260  D0 1E 02 BC */	stfs f0, 0x2bc(r30)
/* 80092304 0008F264  C0 0D A4 74 */	lfs f0, lbl_803DF194@sda21(r13)
/* 80092308 0008F268  D0 1E 02 C0 */	stfs f0, 0x2c0(r30)
/* 8009230C 0008F26C  48 00 00 50 */	b .L_8009235C
.L_80092310:
/* 80092310 0008F270  88 1E 04 3C */	lbz r0, 0x43c(r30)
/* 80092314 0008F274  28 00 00 00 */	cmplwi r0, 0
/* 80092318 0008F278  41 82 00 44 */	beq .L_8009235C
/* 8009231C 0008F27C  38 00 00 01 */	li r0, 1
/* 80092320 0008F280  98 1E 04 3E */	stb r0, 0x43e(r30)
/* 80092324 0008F284  38 00 00 00 */	li r0, 0
/* 80092328 0008F288  98 1E 04 3C */	stb r0, 0x43c(r30)
/* 8009232C 0008F28C  C0 0D A4 60 */	lfs f0, lbl_803DF180@sda21(r13)
/* 80092330 0008F290  D0 1E 00 D4 */	stfs f0, 0xd4(r30)
/* 80092334 0008F294  C0 0D A4 64 */	lfs f0, lbl_803DF184@sda21(r13)
/* 80092338 0008F298  D0 1E 00 D8 */	stfs f0, 0xd8(r30)
/* 8009233C 0008F29C  C0 0D A4 68 */	lfs f0, lbl_803DF188@sda21(r13)
/* 80092340 0008F2A0  D0 1E 00 DC */	stfs f0, 0xdc(r30)
/* 80092344 0008F2A4  C0 0D A4 6C */	lfs f0, lbl_803DF18C@sda21(r13)
/* 80092348 0008F2A8  D0 1E 02 B8 */	stfs f0, 0x2b8(r30)
/* 8009234C 0008F2AC  C0 0D A4 70 */	lfs f0, lbl_803DF190@sda21(r13)
/* 80092350 0008F2B0  D0 1E 02 BC */	stfs f0, 0x2bc(r30)
/* 80092354 0008F2B4  C0 0D A4 74 */	lfs f0, lbl_803DF194@sda21(r13)
/* 80092358 0008F2B8  D0 1E 02 C0 */	stfs f0, 0x2c0(r30)
.L_8009235C:
/* 8009235C 0008F2BC  88 1E 04 3C */	lbz r0, 0x43c(r30)
/* 80092360 0008F2C0  28 00 00 00 */	cmplwi r0, 0
/* 80092364 0008F2C4  41 82 00 1C */	beq .L_80092380
/* 80092368 0008F2C8  38 7E 02 28 */	addi r3, r30, 0x228
/* 8009236C 0008F2CC  38 9E 00 94 */	addi r4, r30, 0x94
/* 80092370 0008F2D0  38 BE 00 E0 */	addi r5, r30, 0xe0
/* 80092374 0008F2D4  38 DE 00 7C */	addi r6, r30, 0x7c
/* 80092378 0008F2D8  4B FA C9 8D */	bl makeVQS__8Matrix4fFR8Vector3fR4QuatR8Vector3f
/* 8009237C 0008F2DC  48 00 00 18 */	b .L_80092394
.L_80092380:
/* 80092380 0008F2E0  38 7E 02 28 */	addi r3, r30, 0x228
/* 80092384 0008F2E4  38 9E 00 7C */	addi r4, r30, 0x7c
/* 80092388 0008F2E8  38 BE 00 88 */	addi r5, r30, 0x88
/* 8009238C 0008F2EC  38 DE 00 94 */	addi r6, r30, 0x94
/* 80092390 0008F2F0  4B FA BD 65 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
.L_80092394:
/* 80092394 0008F2F4  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 80092398 0008F2F8  38 9E 02 28 */	addi r4, r30, 0x228
/* 8009239C 0008F2FC  38 A1 00 10 */	addi r5, r1, 0x10
/* 800923A0 0008F300  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 800923A4 0008F304  4B FA BD 31 */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 800923A8 0008F308  7F C3 F3 78 */	mr r3, r30
/* 800923AC 0008F30C  81 9E 00 00 */	lwz r12, 0(r30)
/* 800923B0 0008F310  38 9F 00 00 */	addi r4, r31, 0
/* 800923B4 0008F314  38 A1 00 10 */	addi r5, r1, 0x10
/* 800923B8 0008F318  81 8C 01 18 */	lwz r12, 0x118(r12)
/* 800923BC 0008F31C  7D 88 03 A6 */	mtlr r12
/* 800923C0 0008F320  4E 80 00 21 */	blrl 
/* 800923C4 0008F324  88 1E 04 3C */	lbz r0, 0x43c(r30)
/* 800923C8 0008F328  28 00 00 00 */	cmplwi r0, 0
/* 800923CC 0008F32C  41 82 00 48 */	beq .L_80092414
/* 800923D0 0008F330  88 1E 04 3D */	lbz r0, 0x43d(r30)
/* 800923D4 0008F334  28 00 00 00 */	cmplwi r0, 0
/* 800923D8 0008F338  40 82 00 3C */	bne .L_80092414
/* 800923DC 0008F33C  7F C3 F3 78 */	mr r3, r30
/* 800923E0 0008F340  48 00 09 35 */	bl releaseAllParticles__11DynCreatureFv
/* 800923E4 0008F344  38 00 00 01 */	li r0, 1
/* 800923E8 0008F348  98 1E 04 3D */	stb r0, 0x43d(r30)
/* 800923EC 0008F34C  38 7E 00 00 */	addi r3, r30, 0
/* 800923F0 0008F350  38 9F 00 00 */	addi r4, r31, 0
/* 800923F4 0008F354  C0 02 8B 60 */	lfs f0, lbl_803E8D60@sda21(r2)
/* 800923F8 0008F358  D0 1E 02 F4 */	stfs f0, 0x2f4(r30)
/* 800923FC 0008F35C  81 9E 00 00 */	lwz r12, 0(r30)
/* 80092400 0008F360  81 8C 01 1C */	lwz r12, 0x11c(r12)
/* 80092404 0008F364  7D 88 03 A6 */	mtlr r12
/* 80092408 0008F368  4E 80 00 21 */	blrl 
/* 8009240C 0008F36C  7F C3 F3 78 */	mr r3, r30
/* 80092410 0008F370  48 00 09 6D */	bl initialiseSystem__11DynCreatureFv
.L_80092414:
/* 80092414 0008F374  38 00 00 00 */	li r0, 0
/* 80092418 0008F378  98 1E 04 3E */	stb r0, 0x43e(r30)
/* 8009241C 0008F37C  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 80092420 0008F380  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 80092424 0008F384  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 80092428 0008F388  38 21 00 58 */	addi r1, r1, 0x58
/* 8009242C 0008F38C  7C 08 03 A6 */	mtlr r0
/* 80092430 0008F390  4E 80 00 20 */	blr 
.endfn refresh__12DualCreatureFR8Graphics

.fn init__11PelCreatureFR8Vector3f, global
/* 80092434 0008F394  7C 08 02 A6 */	mflr r0
/* 80092438 0008F398  90 01 00 04 */	stw r0, 4(r1)
/* 8009243C 0008F39C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80092440 0008F3A0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80092444 0008F3A4  7C 7F 1B 78 */	mr r31, r3
/* 80092448 0008F3A8  4B FF 87 BD */	bl init__8CreatureFR8Vector3f
/* 8009244C 0008F3AC  80 9F 04 94 */	lwz r4, 0x494(r31)
/* 80092450 0008F3B0  28 04 00 00 */	cmplwi r4, 0
/* 80092454 0008F3B4  41 82 00 1C */	beq .L_80092470
/* 80092458 0008F3B8  80 CD 30 AC */	lwz r6, itemMgr@sda21(r13)
/* 8009245C 0008F3BC  38 7F 04 40 */	addi r3, r31, 0x440
/* 80092460 0008F3C0  80 A4 00 04 */	lwz r5, 4(r4)
/* 80092464 0008F3C4  38 84 00 08 */	addi r4, r4, 8
/* 80092468 0008F3C8  80 C6 00 90 */	lwz r6, 0x90(r6)
/* 8009246C 0008F3CC  48 08 CC B9 */	bl init__12PaniAnimatorFP11AnimContextP7AnimMgrP15PaniMotionTable
.L_80092470:
/* 80092470 0008F3D0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80092474 0008F3D4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80092478 0008F3D8  38 21 00 18 */	addi r1, r1, 0x18
/* 8009247C 0008F3DC  7C 08 03 A6 */	mtlr r0
/* 80092480 0008F3E0  4E 80 00 20 */	blr 
.endfn init__11PelCreatureFR8Vector3f

.fn getiMass__11PelCreatureFv, global
/* 80092484 0008F3E4  C0 22 8B 70 */	lfs f1, lbl_803E8D70@sda21(r2)
/* 80092488 0008F3E8  4E 80 00 20 */	blr 
.endfn getiMass__11PelCreatureFv

.fn isAlive__11PelCreatureFv, global
/* 8009248C 0008F3EC  38 60 00 01 */	li r3, 1
/* 80092490 0008F3F0  4E 80 00 20 */	blr 
.endfn isAlive__11PelCreatureFv

.fn startAI__11PelCreatureFi, global
/* 80092494 0008F3F4  7C 08 02 A6 */	mflr r0
/* 80092498 0008F3F8  90 01 00 04 */	stw r0, 4(r1)
/* 8009249C 0008F3FC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800924A0 0008F400  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800924A4 0008F404  3B E3 00 00 */	addi r31, r3, 0
/* 800924A8 0008F408  38 1F 04 98 */	addi r0, r31, 0x498
/* 800924AC 0008F40C  90 03 02 20 */	stw r0, 0x220(r3)
/* 800924B0 0008F410  38 BF 04 AC */	addi r5, r31, 0x4ac
/* 800924B4 0008F414  38 DF 08 BC */	addi r6, r31, 0x8bc
/* 800924B8 0008F418  80 83 04 94 */	lwz r4, 0x494(r3)
/* 800924BC 0008F41C  80 63 02 20 */	lwz r3, 0x220(r3)
/* 800924C0 0008F420  80 84 00 00 */	lwz r4, 0(r4)
/* 800924C4 0008F424  4B FF 76 A1 */	bl initInfo__8CollInfoFP5ShapeP8CollPartPUl
/* 800924C8 0008F428  38 61 00 10 */	addi r3, r1, 0x10
/* 800924CC 0008F42C  38 80 00 00 */	li r4, 0
/* 800924D0 0008F430  48 08 CA 89 */	bl __ct__14PaniMotionInfoFi
/* 800924D4 0008F434  38 83 00 00 */	addi r4, r3, 0
/* 800924D8 0008F438  38 7F 04 40 */	addi r3, r31, 0x440
/* 800924DC 0008F43C  48 08 CC E5 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
/* 800924E0 0008F440  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800924E4 0008F444  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800924E8 0008F448  38 21 00 20 */	addi r1, r1, 0x20
/* 800924EC 0008F44C  7C 08 03 A6 */	mtlr r0
/* 800924F0 0008F450  4E 80 00 20 */	blr 
.endfn startAI__11PelCreatureFi

.fn doRender__11PelCreatureFR8GraphicsR8Matrix4f, global
/* 800924F4 0008F454  7C 08 02 A6 */	mflr r0
/* 800924F8 0008F458  90 01 00 04 */	stw r0, 4(r1)
/* 800924FC 0008F45C  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80092500 0008F460  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80092504 0008F464  3B E5 00 00 */	addi r31, r5, 0
/* 80092508 0008F468  93 C1 00 20 */	stw r30, 0x20(r1)
/* 8009250C 0008F46C  3B C4 00 00 */	addi r30, r4, 0
/* 80092510 0008F470  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 80092514 0008F474  7C 7D 1B 78 */	mr r29, r3
/* 80092518 0008F478  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 8009251C 0008F47C  48 08 4E A9 */	bl getNavi__7NaviMgrFv
/* 80092520 0008F480  80 63 02 E4 */	lwz r3, 0x2e4(r3)
/* 80092524 0008F484  80 03 00 28 */	lwz r0, 0x28(r3)
/* 80092528 0008F488  54 00 04 A5 */	rlwinm. r0, r0, 0, 0x12, 0x12
/* 8009252C 0008F48C  41 82 00 E4 */	beq .L_80092610
/* 80092530 0008F490  C0 3D 00 74 */	lfs f1, 0x74(r29)
/* 80092534 0008F494  C0 02 8B 74 */	lfs f0, lbl_803E8D74@sda21(r2)
/* 80092538 0008F498  EC 01 00 2A */	fadds f0, f1, f0
/* 8009253C 0008F49C  D0 1D 00 74 */	stfs f0, 0x74(r29)
/* 80092540 0008F4A0  88 1D 04 3C */	lbz r0, 0x43c(r29)
/* 80092544 0008F4A4  28 00 00 00 */	cmplwi r0, 0
/* 80092548 0008F4A8  41 82 00 48 */	beq .L_80092590
/* 8009254C 0008F4AC  38 00 00 01 */	li r0, 1
/* 80092550 0008F4B0  98 1D 04 3E */	stb r0, 0x43e(r29)
/* 80092554 0008F4B4  38 00 00 00 */	li r0, 0
/* 80092558 0008F4B8  98 1D 04 3C */	stb r0, 0x43c(r29)
/* 8009255C 0008F4BC  C0 0D A4 60 */	lfs f0, lbl_803DF180@sda21(r13)
/* 80092560 0008F4C0  D0 1D 00 D4 */	stfs f0, 0xd4(r29)
/* 80092564 0008F4C4  C0 0D A4 64 */	lfs f0, lbl_803DF184@sda21(r13)
/* 80092568 0008F4C8  D0 1D 00 D8 */	stfs f0, 0xd8(r29)
/* 8009256C 0008F4CC  C0 0D A4 68 */	lfs f0, lbl_803DF188@sda21(r13)
/* 80092570 0008F4D0  D0 1D 00 DC */	stfs f0, 0xdc(r29)
/* 80092574 0008F4D4  C0 0D A4 6C */	lfs f0, lbl_803DF18C@sda21(r13)
/* 80092578 0008F4D8  D0 1D 02 B8 */	stfs f0, 0x2b8(r29)
/* 8009257C 0008F4DC  C0 0D A4 70 */	lfs f0, lbl_803DF190@sda21(r13)
/* 80092580 0008F4E0  D0 1D 02 BC */	stfs f0, 0x2bc(r29)
/* 80092584 0008F4E4  C0 0D A4 74 */	lfs f0, lbl_803DF194@sda21(r13)
/* 80092588 0008F4E8  D0 1D 02 C0 */	stfs f0, 0x2c0(r29)
/* 8009258C 0008F4EC  48 00 00 84 */	b .L_80092610
.L_80092590:
/* 80092590 0008F4F0  C0 0D A4 88 */	lfs f0, lbl_803DF1A8@sda21(r13)
/* 80092594 0008F4F4  D0 1D 00 88 */	stfs f0, 0x88(r29)
/* 80092598 0008F4F8  C0 0D A4 8C */	lfs f0, lbl_803DF1AC@sda21(r13)
/* 8009259C 0008F4FC  D0 1D 00 8C */	stfs f0, 0x8c(r29)
/* 800925A0 0008F500  C0 0D A4 90 */	lfs f0, lbl_803DF1B0@sda21(r13)
/* 800925A4 0008F504  D0 1D 00 90 */	stfs f0, 0x90(r29)
/* 800925A8 0008F508  88 1D 04 3F */	lbz r0, 0x43f(r29)
/* 800925AC 0008F50C  28 00 00 00 */	cmplwi r0, 0
/* 800925B0 0008F510  40 82 00 20 */	bne .L_800925D0
/* 800925B4 0008F514  38 00 00 01 */	li r0, 1
/* 800925B8 0008F518  98 1D 04 3E */	stb r0, 0x43e(r29)
/* 800925BC 0008F51C  38 7D 00 E0 */	addi r3, r29, 0xe0
/* 800925C0 0008F520  38 9D 00 88 */	addi r4, r29, 0x88
/* 800925C4 0008F524  98 1D 04 3C */	stb r0, 0x43c(r29)
/* 800925C8 0008F528  4B FA 5D 21 */	bl fromEuler__4QuatFR8Vector3f
/* 800925CC 0008F52C  48 00 00 44 */	b .L_80092610
.L_800925D0:
/* 800925D0 0008F530  38 00 00 01 */	li r0, 1
/* 800925D4 0008F534  98 1D 04 3E */	stb r0, 0x43e(r29)
/* 800925D8 0008F538  38 00 00 00 */	li r0, 0
/* 800925DC 0008F53C  98 1D 04 3C */	stb r0, 0x43c(r29)
/* 800925E0 0008F540  C0 0D A4 60 */	lfs f0, lbl_803DF180@sda21(r13)
/* 800925E4 0008F544  D0 1D 00 D4 */	stfs f0, 0xd4(r29)
/* 800925E8 0008F548  C0 0D A4 64 */	lfs f0, lbl_803DF184@sda21(r13)
/* 800925EC 0008F54C  D0 1D 00 D8 */	stfs f0, 0xd8(r29)
/* 800925F0 0008F550  C0 0D A4 68 */	lfs f0, lbl_803DF188@sda21(r13)
/* 800925F4 0008F554  D0 1D 00 DC */	stfs f0, 0xdc(r29)
/* 800925F8 0008F558  C0 0D A4 6C */	lfs f0, lbl_803DF18C@sda21(r13)
/* 800925FC 0008F55C  D0 1D 02 B8 */	stfs f0, 0x2b8(r29)
/* 80092600 0008F560  C0 0D A4 70 */	lfs f0, lbl_803DF190@sda21(r13)
/* 80092604 0008F564  D0 1D 02 BC */	stfs f0, 0x2bc(r29)
/* 80092608 0008F568  C0 0D A4 74 */	lfs f0, lbl_803DF194@sda21(r13)
/* 8009260C 0008F56C  D0 1D 02 C0 */	stfs f0, 0x2c0(r29)
.L_80092610:
/* 80092610 0008F570  7F C3 F3 78 */	mr r3, r30
/* 80092614 0008F574  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80092618 0008F578  38 80 00 01 */	li r4, 1
/* 8009261C 0008F57C  38 A0 00 00 */	li r5, 0
/* 80092620 0008F580  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80092624 0008F584  7D 88 03 A6 */	mtlr r12
/* 80092628 0008F588  4E 80 00 21 */	blrl 
/* 8009262C 0008F58C  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80092630 0008F590  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 80092634 0008F594  7F C3 F3 78 */	mr r3, r30
/* 80092638 0008F598  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8009263C 0008F59C  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 80092640 0008F5A0  38 A0 00 00 */	li r5, 0
/* 80092644 0008F5A4  7D 88 03 A6 */	mtlr r12
/* 80092648 0008F5A8  4E 80 00 21 */	blrl 
/* 8009264C 0008F5AC  38 7D 04 40 */	addi r3, r29, 0x440
/* 80092650 0008F5B0  81 9D 04 70 */	lwz r12, 0x470(r29)
/* 80092654 0008F5B4  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80092658 0008F5B8  7D 88 03 A6 */	mtlr r12
/* 8009265C 0008F5BC  4E 80 00 21 */	blrl 
/* 80092660 0008F5C0  80 7D 04 94 */	lwz r3, 0x494(r29)
/* 80092664 0008F5C4  38 9E 00 00 */	addi r4, r30, 0
/* 80092668 0008F5C8  38 BF 00 00 */	addi r5, r31, 0
/* 8009266C 0008F5CC  80 63 00 00 */	lwz r3, 0(r3)
/* 80092670 0008F5D0  38 C0 00 00 */	li r6, 0
/* 80092674 0008F5D4  4B FA 2C A1 */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 80092678 0008F5D8  80 7D 04 94 */	lwz r3, 0x494(r29)
/* 8009267C 0008F5DC  7F C4 F3 78 */	mr r4, r30
/* 80092680 0008F5E0  80 BE 02 E4 */	lwz r5, 0x2e4(r30)
/* 80092684 0008F5E4  38 C0 00 00 */	li r6, 0
/* 80092688 0008F5E8  80 63 00 00 */	lwz r3, 0(r3)
/* 8009268C 0008F5EC  4B F9 DD E1 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 80092690 0008F5F0  80 7D 02 20 */	lwz r3, 0x220(r29)
/* 80092694 0008F5F4  38 9E 00 00 */	addi r4, r30, 0
/* 80092698 0008F5F8  38 A0 00 00 */	li r5, 0
/* 8009269C 0008F5FC  4B FF 74 51 */	bl updateInfo__8CollInfoFR8Graphicsb
/* 800926A0 0008F600  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800926A4 0008F604  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800926A8 0008F608  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800926AC 0008F60C  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 800926B0 0008F610  38 21 00 28 */	addi r1, r1, 0x28
/* 800926B4 0008F614  7C 08 03 A6 */	mtlr r0
/* 800926B8 0008F618  4E 80 00 20 */	blr 
.endfn doRender__11PelCreatureFR8GraphicsR8Matrix4f

.fn doCreateColls__11PelCreatureFR8Graphics, global
/* 800926BC 0008F61C  7C 08 02 A6 */	mflr r0
/* 800926C0 0008F620  90 01 00 04 */	stw r0, 4(r1)
/* 800926C4 0008F624  94 21 FF 88 */	stwu r1, -0x78(r1)
/* 800926C8 0008F628  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 800926CC 0008F62C  DB C1 00 68 */	stfd f30, 0x68(r1)
/* 800926D0 0008F630  DB A1 00 60 */	stfd f29, 0x60(r1)
/* 800926D4 0008F634  DB 81 00 58 */	stfd f28, 0x58(r1)
/* 800926D8 0008F638  DB 61 00 50 */	stfd f27, 0x50(r1)
/* 800926DC 0008F63C  DB 41 00 48 */	stfd f26, 0x48(r1)
/* 800926E0 0008F640  DB 21 00 40 */	stfd f25, 0x40(r1)
/* 800926E4 0008F644  DB 01 00 38 */	stfd f24, 0x38(r1)
/* 800926E8 0008F648  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800926EC 0008F64C  93 C1 00 30 */	stw r30, 0x30(r1)
/* 800926F0 0008F650  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 800926F4 0008F654  7C 7D 1B 78 */	mr r29, r3
/* 800926F8 0008F658  81 9D 00 00 */	lwz r12, 0(r29)
/* 800926FC 0008F65C  81 8C 00 5C */	lwz r12, 0x5c(r12)
/* 80092700 0008F660  7D 88 03 A6 */	mtlr r12
/* 80092704 0008F664  4E 80 00 21 */	blrl 
/* 80092708 0008F668  FF 60 08 90 */	fmr f27, f1
/* 8009270C 0008F66C  C3 02 8B 78 */	lfs f24, lbl_803E8D78@sda21(r2)
/* 80092710 0008F670  C3 82 8B 7C */	lfs f28, lbl_803E8D7C@sda21(r2)
/* 80092714 0008F674  3B C0 00 00 */	li r30, 0
/* 80092718 0008F678  CB A2 8B 88 */	lfd f29, lbl_803E8D88@sda21(r2)
/* 8009271C 0008F67C  C3 C2 8B 80 */	lfs f30, lbl_803E8D80@sda21(r2)
/* 80092720 0008F680  3F E0 43 30 */	lis r31, 0x4330
/* 80092724 0008F684  C3 E2 8B 84 */	lfs f31, lbl_803E8D84@sda21(r2)
.L_80092728:
/* 80092728 0008F688  6F C0 80 00 */	xoris r0, r30, 0x8000
/* 8009272C 0008F68C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80092730 0008F690  93 E1 00 20 */	stw r31, 0x20(r1)
/* 80092734 0008F694  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 80092738 0008F698  EC 00 E8 28 */	fsubs f0, f0, f29
/* 8009273C 0008F69C  EF 3C 00 32 */	fmuls f25, f28, f0
/* 80092740 0008F6A0  FC 20 C8 90 */	fmr f1, f25
/* 80092744 0008F6A4  48 18 95 A5 */	bl sinf
/* 80092748 0008F6A8  EF 5B 00 72 */	fmuls f26, f27, f1
/* 8009274C 0008F6AC  FC 20 C8 90 */	fmr f1, f25
/* 80092750 0008F6B0  48 18 94 05 */	bl cosf
/* 80092754 0008F6B4  EC 5B 00 72 */	fmuls f2, f27, f1
/* 80092758 0008F6B8  C0 0D A4 94 */	lfs f0, lbl_803DF1B4@sda21(r13)
/* 8009275C 0008F6BC  FC 20 C0 90 */	fmr f1, f24
/* 80092760 0008F6C0  38 7D 00 00 */	addi r3, r29, 0
/* 80092764 0008F6C4  38 81 00 10 */	addi r4, r1, 0x10
/* 80092768 0008F6C8  D0 41 00 10 */	stfs f2, 0x10(r1)
/* 8009276C 0008F6CC  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 80092770 0008F6D0  D3 41 00 18 */	stfs f26, 0x18(r1)
/* 80092774 0008F6D4  48 00 04 A1 */	bl addParticle__11DynCreatureFfR8Vector3f
/* 80092778 0008F6D8  EF 3E C8 2A */	fadds f25, f30, f25
/* 8009277C 0008F6DC  FC 20 C8 90 */	fmr f1, f25
/* 80092780 0008F6E0  48 18 95 69 */	bl sinf
/* 80092784 0008F6E4  EF 5B 00 72 */	fmuls f26, f27, f1
/* 80092788 0008F6E8  FC 20 C8 90 */	fmr f1, f25
/* 8009278C 0008F6EC  48 18 93 C9 */	bl cosf
/* 80092790 0008F6F0  EC 3B 00 72 */	fmuls f1, f27, f1
/* 80092794 0008F6F4  C0 0D A4 98 */	lfs f0, lbl_803DF1B8@sda21(r13)
/* 80092798 0008F6F8  38 7D 00 00 */	addi r3, r29, 0
/* 8009279C 0008F6FC  38 81 00 10 */	addi r4, r1, 0x10
/* 800927A0 0008F700  D0 21 00 10 */	stfs f1, 0x10(r1)
/* 800927A4 0008F704  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 800927A8 0008F708  D3 41 00 18 */	stfs f26, 0x18(r1)
/* 800927AC 0008F70C  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 800927B0 0008F710  EC 00 F8 2A */	fadds f0, f0, f31
/* 800927B4 0008F714  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 800927B8 0008F718  C0 22 8B 6C */	lfs f1, lbl_803E8D6C@sda21(r2)
/* 800927BC 0008F71C  48 00 04 59 */	bl addParticle__11DynCreatureFfR8Vector3f
/* 800927C0 0008F720  3B DE 00 01 */	addi r30, r30, 1
/* 800927C4 0008F724  2C 1E 00 04 */	cmpwi r30, 4
/* 800927C8 0008F728  41 80 FF 60 */	blt .L_80092728
/* 800927CC 0008F72C  80 01 00 7C */	lwz r0, 0x7c(r1)
/* 800927D0 0008F730  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 800927D4 0008F734  CB C1 00 68 */	lfd f30, 0x68(r1)
/* 800927D8 0008F738  CB A1 00 60 */	lfd f29, 0x60(r1)
/* 800927DC 0008F73C  CB 81 00 58 */	lfd f28, 0x58(r1)
/* 800927E0 0008F740  CB 61 00 50 */	lfd f27, 0x50(r1)
/* 800927E4 0008F744  CB 41 00 48 */	lfd f26, 0x48(r1)
/* 800927E8 0008F748  CB 21 00 40 */	lfd f25, 0x40(r1)
/* 800927EC 0008F74C  CB 01 00 38 */	lfd f24, 0x38(r1)
/* 800927F0 0008F750  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800927F4 0008F754  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 800927F8 0008F758  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 800927FC 0008F75C  38 21 00 78 */	addi r1, r1, 0x78
/* 80092800 0008F760  7C 08 03 A6 */	mtlr r0
/* 80092804 0008F764  4E 80 00 20 */	blr 
.endfn doCreateColls__11PelCreatureFR8Graphics

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802AF408, local
	.asciz "dualCreature.cpp"
.endobj lbl_802AF408
.balign 4
.obj lbl_802AF41C, local
	.asciz "PelCreature"
.endobj lbl_802AF41C
.balign 4
.obj lbl_802AF428, local
	.asciz "EventTalker"
.endobj lbl_802AF428
.balign 4
.obj lbl_802AF434, local
	.asciz "RefCountable"
.endobj lbl_802AF434
.balign 4
.obj lbl_802AF444, local
	.asciz "Creature"
.endobj lbl_802AF444
.balign 4
.obj lbl_802AF450, local
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
.endobj lbl_802AF450
.balign 4
.obj lbl_802AF464, local
	.asciz "DynCreature"
.endobj lbl_802AF464
.balign 4
.obj lbl_802AF470, local
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
.endobj lbl_802AF470
.balign 4
.obj lbl_802AF48C, local
	.asciz "DualCreature"
.endobj lbl_802AF48C
.balign 4
.obj lbl_802AF49C, local
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__11DynCreature
	.4byte 0
	.4byte 0
.endobj lbl_802AF49C
.balign 4
.obj lbl_802AF4C0, local
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__11DynCreature
	.4byte 0
	.4byte __RTTI__12DualCreature
	.4byte 0
	.4byte 0
.endobj lbl_802AF4C0
.balign 4
.obj __vt__11PelCreature, global
	.4byte __RTTI__11PelCreature
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__11PelCreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__11PelCreatureFi
	.4byte getiMass__11PelCreatureFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__8CreatureFv
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__11PelCreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__8CreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__8CreatureFR9CollEvent
	.4byte bounceCallback__8CreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
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
	.4byte update__12DualCreatureFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12DualCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__8CreatureFv
	.4byte doAnimation__8CreatureFv
	.4byte doKill__12DualCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte onGround__12DualCreatureFv
	.4byte doRender__11PelCreatureFR8GraphicsR8Matrix4f
	.4byte doCreateColls__11PelCreatureFR8Graphics
.endobj __vt__11PelCreature
.balign 4
.obj __vt__12DualCreature, global
	.4byte __RTTI__12DualCreature
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8CreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__8CreatureFv
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__8CreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__8CreatureFR9CollEvent
	.4byte bounceCallback__8CreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
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
	.4byte update__12DualCreatureFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12DualCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__8CreatureFv
	.4byte doAnimation__8CreatureFv
	.4byte doKill__12DualCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte onGround__12DualCreatureFv
.endobj __vt__12DualCreature
.skip 0x8 # compiler padding

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DF168, local
	.float 0.0
.endobj lbl_803DF168
.obj lbl_803DF16C, local
	.float 0.0
.endobj lbl_803DF16C
.obj lbl_803DF170, local
	.float 0.0
.endobj lbl_803DF170
.obj lbl_803DF174, local
	.float 0.0
.endobj lbl_803DF174
.obj lbl_803DF178, local
	.float 0.0
.endobj lbl_803DF178
.obj lbl_803DF17C, local
	.float 0.0
.endobj lbl_803DF17C
.obj lbl_803DF180, local
	.float 0.0
.endobj lbl_803DF180
.obj lbl_803DF184, local
	.float 0.0
.endobj lbl_803DF184
.obj lbl_803DF188, local
	.float 0.0
.endobj lbl_803DF188
.obj lbl_803DF18C, local
	.float 0.0
.endobj lbl_803DF18C
.obj lbl_803DF190, local
	.float 0.0
.endobj lbl_803DF190
.obj lbl_803DF194, local
	.float 0.0
.endobj lbl_803DF194
.obj lbl_803DF198, local
	.float 0.0
.endobj lbl_803DF198
.obj lbl_803DF19C, local
	.float 0.0
.endobj lbl_803DF19C
.obj lbl_803DF1A0, local
	.float 0.0
.endobj lbl_803DF1A0
.obj lbl_803DF1A4, local
	.float 0.0
.endobj lbl_803DF1A4
.obj lbl_803DF1A8, local # pi/10
	.float 0.31415927
.endobj lbl_803DF1A8
.obj lbl_803DF1AC, local
	.float 0.0
.endobj lbl_803DF1AC
.obj lbl_803DF1B0, local
	.float 0.0
.endobj lbl_803DF1B0
.obj lbl_803DF1B4, local
	.float 0.0
.endobj lbl_803DF1B4
.obj lbl_803DF1B8, local
	.float 0.0
.endobj lbl_803DF1B8
.balign 4
.obj __RTTI__11EventTalker, local
	.4byte lbl_802AF428
	.4byte 0
.endobj __RTTI__11EventTalker
.balign 4
.obj __RTTI__12RefCountable, local
	.4byte lbl_802AF434
	.4byte 0
.endobj __RTTI__12RefCountable
.balign 4
.obj __RTTI__8Creature, local
	.4byte lbl_802AF444
	.4byte lbl_802AF450
.endobj __RTTI__8Creature
.balign 4
.obj __RTTI__11DynCreature, local
	.4byte lbl_802AF464
	.4byte lbl_802AF470
.endobj __RTTI__11DynCreature
.balign 4
.obj __RTTI__12DualCreature, local
	.4byte lbl_802AF48C
	.4byte lbl_802AF49C
.endobj __RTTI__12DualCreature
.balign 4
.obj __RTTI__11PelCreature, local
	.4byte lbl_802AF41C
	.4byte lbl_802AF4C0
.endobj __RTTI__11PelCreature

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E8D60, local
	.float 0.0
.endobj lbl_803E8D60
.obj lbl_803E8D64, local
	.float 0.5
.endobj lbl_803E8D64
.obj lbl_803E8D68, local
	.float 1.0
.endobj lbl_803E8D68
.obj lbl_803E8D6C, local
	.float 2.0
.endobj lbl_803E8D6C
.obj lbl_803E8D70, local
	.float 10.0
.endobj lbl_803E8D70
.obj lbl_803E8D74, local
	.float 400.0
.endobj lbl_803E8D74
.obj lbl_803E8D78, local
	.float 4.0
.endobj lbl_803E8D78
.obj lbl_803E8D7C, local # pi/2
	.float 1.5707964
.endobj lbl_803E8D7C
.obj lbl_803E8D80, local # 45 degrees in radians
	.float 0.7853982
.endobj lbl_803E8D80
.obj lbl_803E8D84, local
	.float 25.0
.endobj lbl_803E8D84
.balign 8
.obj lbl_803E8D88, local
	.8byte 0x4330000080000000
.endobj lbl_803E8D88
