.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn PSMTXIdentity, global
/* 801FDB94 001FAAF4  C0 02 C2 DC */	lfs f0, lbl_803EC4DC@sda21(r2)
/* 801FDB98 001FAAF8  C0 22 C2 D8 */	lfs f1, lbl_803EC4D8@sda21(r2)
/* 801FDB9C 001FAAFC  F0 03 00 08 */	psq_st f0, 8(r3), 0, qr0
/* 801FDBA0 001FAB00  10 40 0C 60 */	ps_merge01 f2, f0, f1
/* 801FDBA4 001FAB04  F0 03 00 18 */	psq_st f0, 24(r3), 0, qr0
/* 801FDBA8 001FAB08  10 21 04 A0 */	ps_merge10 f1, f1, f0
/* 801FDBAC 001FAB0C  F0 03 00 20 */	psq_st f0, 32(r3), 0, qr0
/* 801FDBB0 001FAB10  F0 43 00 10 */	psq_st f2, 16(r3), 0, qr0
/* 801FDBB4 001FAB14  F0 23 00 00 */	psq_st f1, 0(r3), 0, qr0
/* 801FDBB8 001FAB18  F0 23 00 28 */	psq_st f1, 40(r3), 0, qr0
/* 801FDBBC 001FAB1C  4E 80 00 20 */	blr 
.endfn PSMTXIdentity

.fn PSMTXConcat, global
/* 801FDBC0 001FAB20  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 801FDBC4 001FAB24  E0 03 00 00 */	psq_l f0, 0(r3), 0, qr0
/* 801FDBC8 001FAB28  D9 C1 00 08 */	stfd f14, 8(r1)
/* 801FDBCC 001FAB2C  E0 C4 00 00 */	psq_l f6, 0(r4), 0, qr0
/* 801FDBD0 001FAB30  3C C0 80 3E */	lis r6, Unit01@ha
/* 801FDBD4 001FAB34  E0 E4 00 08 */	psq_l f7, 8(r4), 0, qr0
/* 801FDBD8 001FAB38  D9 E1 00 10 */	stfd f15, 0x10(r1)
/* 801FDBDC 001FAB3C  38 C6 77 20 */	addi r6, r6, Unit01@l
/* 801FDBE0 001FAB40  DB E1 00 28 */	stfd f31, 0x28(r1)
/* 801FDBE4 001FAB44  E1 04 00 10 */	psq_l f8, 16(r4), 0, qr0
/* 801FDBE8 001FAB48  11 86 00 18 */	ps_muls0 f12, f6, f0
/* 801FDBEC 001FAB4C  E0 43 00 10 */	psq_l f2, 16(r3), 0, qr0
/* 801FDBF0 001FAB50  11 A7 00 18 */	ps_muls0 f13, f7, f0
/* 801FDBF4 001FAB54  E3 E6 00 00 */	psq_l f31, 0(r6), 0, qr0
/* 801FDBF8 001FAB58  11 C6 00 98 */	ps_muls0 f14, f6, f2
/* 801FDBFC 001FAB5C  E1 24 00 18 */	psq_l f9, 24(r4), 0, qr0
/* 801FDC00 001FAB60  11 E7 00 98 */	ps_muls0 f15, f7, f2
/* 801FDC04 001FAB64  E0 23 00 08 */	psq_l f1, 8(r3), 0, qr0
/* 801FDC08 001FAB68  11 88 60 1E */	ps_madds1 f12, f8, f0, f12
/* 801FDC0C 001FAB6C  E0 63 00 18 */	psq_l f3, 24(r3), 0, qr0
/* 801FDC10 001FAB70  11 C8 70 9E */	ps_madds1 f14, f8, f2, f14
/* 801FDC14 001FAB74  E1 44 00 20 */	psq_l f10, 32(r4), 0, qr0
/* 801FDC18 001FAB78  11 A9 68 1E */	ps_madds1 f13, f9, f0, f13
/* 801FDC1C 001FAB7C  E1 64 00 28 */	psq_l f11, 40(r4), 0, qr0
/* 801FDC20 001FAB80  11 E9 78 9E */	ps_madds1 f15, f9, f2, f15
/* 801FDC24 001FAB84  E0 83 00 20 */	psq_l f4, 32(r3), 0, qr0
/* 801FDC28 001FAB88  E0 A3 00 28 */	psq_l f5, 40(r3), 0, qr0
/* 801FDC2C 001FAB8C  11 8A 60 5C */	ps_madds0 f12, f10, f1, f12
/* 801FDC30 001FAB90  11 AB 68 5C */	ps_madds0 f13, f11, f1, f13
/* 801FDC34 001FAB94  11 CA 70 DC */	ps_madds0 f14, f10, f3, f14
/* 801FDC38 001FAB98  11 EB 78 DC */	ps_madds0 f15, f11, f3, f15
/* 801FDC3C 001FAB9C  F1 85 00 00 */	psq_st f12, 0(r5), 0, qr0
/* 801FDC40 001FABA0  10 46 01 18 */	ps_muls0 f2, f6, f4
/* 801FDC44 001FABA4  11 BF 68 5E */	ps_madds1 f13, f31, f1, f13
/* 801FDC48 001FABA8  10 07 01 18 */	ps_muls0 f0, f7, f4
/* 801FDC4C 001FABAC  F1 C5 00 10 */	psq_st f14, 16(r5), 0, qr0
/* 801FDC50 001FABB0  11 FF 78 DE */	ps_madds1 f15, f31, f3, f15
/* 801FDC54 001FABB4  F1 A5 00 08 */	psq_st f13, 8(r5), 0, qr0
/* 801FDC58 001FABB8  10 48 11 1E */	ps_madds1 f2, f8, f4, f2
/* 801FDC5C 001FABBC  10 09 01 1E */	ps_madds1 f0, f9, f4, f0
/* 801FDC60 001FABC0  10 4A 11 5C */	ps_madds0 f2, f10, f5, f2
/* 801FDC64 001FABC4  C9 C1 00 08 */	lfd f14, 8(r1)
/* 801FDC68 001FABC8  F1 E5 00 18 */	psq_st f15, 24(r5), 0, qr0
/* 801FDC6C 001FABCC  10 0B 01 5C */	ps_madds0 f0, f11, f5, f0
/* 801FDC70 001FABD0  F0 45 00 20 */	psq_st f2, 32(r5), 0, qr0
/* 801FDC74 001FABD4  10 1F 01 5E */	ps_madds1 f0, f31, f5, f0
/* 801FDC78 001FABD8  C9 E1 00 10 */	lfd f15, 0x10(r1)
/* 801FDC7C 001FABDC  F0 05 00 28 */	psq_st f0, 40(r5), 0, qr0
/* 801FDC80 001FABE0  CB E1 00 28 */	lfd f31, 0x28(r1)
/* 801FDC84 001FABE4  38 21 00 40 */	addi r1, r1, 0x40
/* 801FDC88 001FABE8  4E 80 00 20 */	blr 
.endfn PSMTXConcat

.fn PSMTXTranspose, global
/* 801FDC8C 001FABEC  C0 02 C2 DC */	lfs f0, lbl_803EC4DC@sda21(r2)
/* 801FDC90 001FABF0  E0 23 00 00 */	psq_l f1, 0(r3), 0, qr0
/* 801FDC94 001FABF4  D0 04 00 2C */	stfs f0, 0x2c(r4)
/* 801FDC98 001FABF8  E0 43 00 10 */	psq_l f2, 16(r3), 0, qr0
/* 801FDC9C 001FABFC  10 81 14 20 */	ps_merge00 f4, f1, f2
/* 801FDCA0 001FAC00  E0 63 80 08 */	psq_l f3, 8(r3), 1, qr0
/* 801FDCA4 001FAC04  10 A1 14 E0 */	ps_merge11 f5, f1, f2
/* 801FDCA8 001FAC08  E0 43 80 18 */	psq_l f2, 24(r3), 1, qr0
/* 801FDCAC 001FAC0C  F0 84 00 00 */	psq_st f4, 0(r4), 0, qr0
/* 801FDCB0 001FAC10  E0 23 00 20 */	psq_l f1, 32(r3), 0, qr0
/* 801FDCB4 001FAC14  10 43 14 20 */	ps_merge00 f2, f3, f2
/* 801FDCB8 001FAC18  F0 A4 00 10 */	psq_st f5, 16(r4), 0, qr0
/* 801FDCBC 001FAC1C  10 81 04 20 */	ps_merge00 f4, f1, f0
/* 801FDCC0 001FAC20  F0 44 00 20 */	psq_st f2, 32(r4), 0, qr0
/* 801FDCC4 001FAC24  10 A1 04 A0 */	ps_merge10 f5, f1, f0
/* 801FDCC8 001FAC28  F0 84 00 08 */	psq_st f4, 8(r4), 0, qr0
/* 801FDCCC 001FAC2C  C0 63 00 28 */	lfs f3, 0x28(r3)
/* 801FDCD0 001FAC30  F0 A4 00 18 */	psq_st f5, 24(r4), 0, qr0
/* 801FDCD4 001FAC34  D0 64 00 28 */	stfs f3, 0x28(r4)
/* 801FDCD8 001FAC38  4E 80 00 20 */	blr 
.endfn PSMTXTranspose

.fn PSMTXInverse, global
/* 801FDCDC 001FAC3C  E0 03 80 00 */	psq_l f0, 0(r3), 1, qr0
/* 801FDCE0 001FAC40  E0 23 00 04 */	psq_l f1, 4(r3), 0, qr0
/* 801FDCE4 001FAC44  E0 43 80 10 */	psq_l f2, 16(r3), 1, qr0
/* 801FDCE8 001FAC48  10 C1 04 A0 */	ps_merge10 f6, f1, f0
/* 801FDCEC 001FAC4C  E0 63 00 14 */	psq_l f3, 20(r3), 0, qr0
/* 801FDCF0 001FAC50  E0 83 80 20 */	psq_l f4, 32(r3), 1, qr0
/* 801FDCF4 001FAC54  10 E3 14 A0 */	ps_merge10 f7, f3, f2
/* 801FDCF8 001FAC58  E0 A3 00 24 */	psq_l f5, 36(r3), 0, qr0
/* 801FDCFC 001FAC5C  11 63 01 B2 */	ps_mul f11, f3, f6
/* 801FDD00 001FAC60  11 A5 01 F2 */	ps_mul f13, f5, f7
/* 801FDD04 001FAC64  11 05 24 A0 */	ps_merge10 f8, f5, f4
/* 801FDD08 001FAC68  11 61 59 F8 */	ps_msub f11, f1, f7, f11
/* 801FDD0C 001FAC6C  11 81 02 32 */	ps_mul f12, f1, f8
/* 801FDD10 001FAC70  11 A3 6A 38 */	ps_msub f13, f3, f8, f13
/* 801FDD14 001FAC74  11 43 01 32 */	ps_mul f10, f3, f4
/* 801FDD18 001FAC78  11 85 61 B8 */	ps_msub f12, f5, f6, f12
/* 801FDD1C 001FAC7C  11 20 01 72 */	ps_mul f9, f0, f5
/* 801FDD20 001FAC80  11 01 00 B2 */	ps_mul f8, f1, f2
/* 801FDD24 001FAC84  10 C6 30 28 */	ps_sub f6, f6, f6
/* 801FDD28 001FAC88  11 42 51 78 */	ps_msub f10, f2, f5, f10
/* 801FDD2C 001FAC8C  10 E0 03 72 */	ps_mul f7, f0, f13
/* 801FDD30 001FAC90  11 21 49 38 */	ps_msub f9, f1, f4, f9
/* 801FDD34 001FAC94  10 E2 3B 3A */	ps_madd f7, f2, f12, f7
/* 801FDD38 001FAC98  11 00 40 F8 */	ps_msub f8, f0, f3, f8
/* 801FDD3C 001FAC9C  10 E4 3A FA */	ps_madd f7, f4, f11, f7
/* 801FDD40 001FACA0  10 07 30 40 */	ps_cmpo0 cr0, f7, f6
/* 801FDD44 001FACA4  40 82 00 0C */	bne .L_801FDD50
/* 801FDD48 001FACA8  38 60 00 00 */	li r3, 0
/* 801FDD4C 001FACAC  4E 80 00 20 */	blr 
.L_801FDD50:
/* 801FDD50 001FACB0  10 00 38 30 */	ps_res f0, f7
/* 801FDD54 001FACB4  10 C0 00 2A */	ps_add f6, f0, f0
/* 801FDD58 001FACB8  10 A0 00 32 */	ps_mul f5, f0, f0
/* 801FDD5C 001FACBC  10 07 31 7C */	ps_nmsub f0, f7, f5, f6
/* 801FDD60 001FACC0  10 C0 00 2A */	ps_add f6, f0, f0
/* 801FDD64 001FACC4  10 A0 00 32 */	ps_mul f5, f0, f0
/* 801FDD68 001FACC8  10 07 31 7C */	ps_nmsub f0, f7, f5, f6
/* 801FDD6C 001FACCC  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 801FDD70 001FACD0  11 AD 00 18 */	ps_muls0 f13, f13, f0
/* 801FDD74 001FACD4  C0 43 00 1C */	lfs f2, 0x1c(r3)
/* 801FDD78 001FACD8  11 8C 00 18 */	ps_muls0 f12, f12, f0
/* 801FDD7C 001FACDC  C0 63 00 2C */	lfs f3, 0x2c(r3)
/* 801FDD80 001FACE0  11 6B 00 18 */	ps_muls0 f11, f11, f0
/* 801FDD84 001FACE4  10 AD 64 20 */	ps_merge00 f5, f13, f12
/* 801FDD88 001FACE8  11 4A 00 18 */	ps_muls0 f10, f10, f0
/* 801FDD8C 001FACEC  10 8D 64 E0 */	ps_merge11 f4, f13, f12
/* 801FDD90 001FACF0  11 29 00 18 */	ps_muls0 f9, f9, f0
/* 801FDD94 001FACF4  F0 A4 00 00 */	psq_st f5, 0(r4), 0, qr0
/* 801FDD98 001FACF8  10 CD 00 72 */	ps_mul f6, f13, f1
/* 801FDD9C 001FACFC  F0 84 00 10 */	psq_st f4, 16(r4), 0, qr0
/* 801FDDA0 001FAD00  11 08 00 18 */	ps_muls0 f8, f8, f0
/* 801FDDA4 001FAD04  10 CC 30 BA */	ps_madd f6, f12, f2, f6
/* 801FDDA8 001FAD08  F1 44 80 20 */	psq_st f10, 32(r4), 1, qr0
/* 801FDDAC 001FAD0C  10 CB 30 FE */	ps_nmadd f6, f11, f3, f6
/* 801FDDB0 001FAD10  F1 24 80 24 */	psq_st f9, 36(r4), 1, qr0
/* 801FDDB4 001FAD14  10 EA 00 72 */	ps_mul f7, f10, f1
/* 801FDDB8 001FAD18  10 AB 34 20 */	ps_merge00 f5, f11, f6
/* 801FDDBC 001FAD1C  F1 04 80 28 */	psq_st f8, 40(r4), 1, qr0
/* 801FDDC0 001FAD20  10 8B 34 E0 */	ps_merge11 f4, f11, f6
/* 801FDDC4 001FAD24  F0 A4 00 08 */	psq_st f5, 8(r4), 0, qr0
/* 801FDDC8 001FAD28  10 E9 38 BA */	ps_madd f7, f9, f2, f7
/* 801FDDCC 001FAD2C  F0 84 00 18 */	psq_st f4, 24(r4), 0, qr0
/* 801FDDD0 001FAD30  10 E8 38 FE */	ps_nmadd f7, f8, f3, f7
/* 801FDDD4 001FAD34  38 60 00 01 */	li r3, 1
/* 801FDDD8 001FAD38  F0 E4 80 2C */	psq_st f7, 44(r4), 1, qr0
/* 801FDDDC 001FAD3C  4E 80 00 20 */	blr 
.endfn PSMTXInverse

.fn MTXTrans, global
/* 801FDDE0 001FAD40  C0 82 C2 D8 */	lfs f4, lbl_803EC4D8@sda21(r2)
/* 801FDDE4 001FAD44  D0 83 00 00 */	stfs f4, 0(r3)
/* 801FDDE8 001FAD48  C0 02 C2 DC */	lfs f0, lbl_803EC4DC@sda21(r2)
/* 801FDDEC 001FAD4C  D0 03 00 04 */	stfs f0, 4(r3)
/* 801FDDF0 001FAD50  D0 03 00 08 */	stfs f0, 8(r3)
/* 801FDDF4 001FAD54  D0 23 00 0C */	stfs f1, 0xc(r3)
/* 801FDDF8 001FAD58  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 801FDDFC 001FAD5C  D0 83 00 14 */	stfs f4, 0x14(r3)
/* 801FDE00 001FAD60  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 801FDE04 001FAD64  D0 43 00 1C */	stfs f2, 0x1c(r3)
/* 801FDE08 001FAD68  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 801FDE0C 001FAD6C  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 801FDE10 001FAD70  D0 83 00 28 */	stfs f4, 0x28(r3)
/* 801FDE14 001FAD74  D0 63 00 2C */	stfs f3, 0x2c(r3)
/* 801FDE18 001FAD78  4E 80 00 20 */	blr 
.endfn MTXTrans

.fn MTXScale, global
/* 801FDE1C 001FAD7C  D0 23 00 00 */	stfs f1, 0(r3)
/* 801FDE20 001FAD80  C0 02 C2 DC */	lfs f0, lbl_803EC4DC@sda21(r2)
/* 801FDE24 001FAD84  D0 03 00 04 */	stfs f0, 4(r3)
/* 801FDE28 001FAD88  D0 03 00 08 */	stfs f0, 8(r3)
/* 801FDE2C 001FAD8C  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 801FDE30 001FAD90  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 801FDE34 001FAD94  D0 43 00 14 */	stfs f2, 0x14(r3)
/* 801FDE38 001FAD98  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 801FDE3C 001FAD9C  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 801FDE40 001FADA0  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 801FDE44 001FADA4  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 801FDE48 001FADA8  D0 63 00 28 */	stfs f3, 0x28(r3)
/* 801FDE4C 001FADAC  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 801FDE50 001FADB0  4E 80 00 20 */	blr 
.endfn MTXScale

.fn MTXLightPerspective, global
/* 801FDE54 001FADB4  7C 08 02 A6 */	mflr r0
/* 801FDE58 001FADB8  90 01 00 04 */	stw r0, 4(r1)
/* 801FDE5C 001FADBC  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 801FDE60 001FADC0  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 801FDE64 001FADC4  DB C1 00 48 */	stfd f30, 0x48(r1)
/* 801FDE68 001FADC8  DB A1 00 40 */	stfd f29, 0x40(r1)
/* 801FDE6C 001FADCC  DB 81 00 38 */	stfd f28, 0x38(r1)
/* 801FDE70 001FADD0  DB 61 00 30 */	stfd f27, 0x30(r1)
/* 801FDE74 001FADD4  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 801FDE78 001FADD8  FF 60 10 90 */	fmr f27, f2
/* 801FDE7C 001FADDC  7C 7F 1B 78 */	mr r31, r3
/* 801FDE80 001FADE0  FF 80 18 90 */	fmr f28, f3
/* 801FDE84 001FADE4  FF A0 20 90 */	fmr f29, f4
/* 801FDE88 001FADE8  FF C0 28 90 */	fmr f30, f5
/* 801FDE8C 001FADEC  FF E0 30 90 */	fmr f31, f6
/* 801FDE90 001FADF0  C0 42 C2 E4 */	lfs f2, lbl_803EC4E4@sda21(r2)
/* 801FDE94 001FADF4  C0 02 C2 E8 */	lfs f0, lbl_803EC4E8@sda21(r2)
/* 801FDE98 001FADF8  EC 22 00 72 */	fmuls f1, f2, f1
/* 801FDE9C 001FADFC  EC 20 00 72 */	fmuls f1, f0, f1
/* 801FDEA0 001FAE00  48 01 DC 31 */	bl tanf
/* 801FDEA4 001FAE04  C0 62 C2 D8 */	lfs f3, lbl_803EC4D8@sda21(r2)
/* 801FDEA8 001FAE08  FC 40 F0 50 */	fneg f2, f30
/* 801FDEAC 001FAE0C  FC 00 F8 50 */	fneg f0, f31
/* 801FDEB0 001FAE10  EC 83 08 24 */	fdivs f4, f3, f1
/* 801FDEB4 001FAE14  EC 24 D8 24 */	fdivs f1, f4, f27
/* 801FDEB8 001FAE18  EC 7C 00 72 */	fmuls f3, f28, f1
/* 801FDEBC 001FAE1C  EC 24 07 72 */	fmuls f1, f4, f29
/* 801FDEC0 001FAE20  D0 7F 00 00 */	stfs f3, 0(r31)
/* 801FDEC4 001FAE24  C0 62 C2 DC */	lfs f3, lbl_803EC4DC@sda21(r2)
/* 801FDEC8 001FAE28  D0 7F 00 04 */	stfs f3, 4(r31)
/* 801FDECC 001FAE2C  D0 5F 00 08 */	stfs f2, 8(r31)
/* 801FDED0 001FAE30  D0 7F 00 0C */	stfs f3, 0xc(r31)
/* 801FDED4 001FAE34  D0 7F 00 10 */	stfs f3, 0x10(r31)
/* 801FDED8 001FAE38  D0 3F 00 14 */	stfs f1, 0x14(r31)
/* 801FDEDC 001FAE3C  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 801FDEE0 001FAE40  D0 7F 00 1C */	stfs f3, 0x1c(r31)
/* 801FDEE4 001FAE44  D0 7F 00 20 */	stfs f3, 0x20(r31)
/* 801FDEE8 001FAE48  D0 7F 00 24 */	stfs f3, 0x24(r31)
/* 801FDEEC 001FAE4C  C0 02 C2 E0 */	lfs f0, lbl_803EC4E0@sda21(r2)
/* 801FDEF0 001FAE50  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 801FDEF4 001FAE54  D0 7F 00 2C */	stfs f3, 0x2c(r31)
/* 801FDEF8 001FAE58  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 801FDEFC 001FAE5C  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 801FDF00 001FAE60  CB C1 00 48 */	lfd f30, 0x48(r1)
/* 801FDF04 001FAE64  7C 08 03 A6 */	mtlr r0
/* 801FDF08 001FAE68  CB A1 00 40 */	lfd f29, 0x40(r1)
/* 801FDF0C 001FAE6C  CB 81 00 38 */	lfd f28, 0x38(r1)
/* 801FDF10 001FAE70  CB 61 00 30 */	lfd f27, 0x30(r1)
/* 801FDF14 001FAE74  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 801FDF18 001FAE78  38 21 00 58 */	addi r1, r1, 0x58
/* 801FDF1C 001FAE7C  4E 80 00 20 */	blr 
.endfn MTXLightPerspective

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj Unit01, local
	.float 0.0
	.float 1.0
.endobj Unit01

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EC4D8, local
	.float 1.0
.endobj lbl_803EC4D8
.obj lbl_803EC4DC, local
	.float 0.0
.endobj lbl_803EC4DC
.obj lbl_803EC4E0, local
	.float -1.0
.endobj lbl_803EC4E0
.obj lbl_803EC4E4, local
	.float 0.5
.endobj lbl_803EC4E4
.obj lbl_803EC4E8, local
	.float 0.017453292
.endobj lbl_803EC4E8
