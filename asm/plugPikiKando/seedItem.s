.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__8SeedItemFP12CreaturePropPP5Shape
__ct__8SeedItemFP12CreaturePropPP5Shape:
/* 800EDDD0 000EAD30  7C 08 02 A6 */	mflr r0
/* 800EDDD4 000EAD34  90 01 00 04 */	stw r0, 4(r1)
/* 800EDDD8 000EAD38  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800EDDDC 000EAD3C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800EDDE0 000EAD40  3B E5 00 00 */	addi r31, r5, 0
/* 800EDDE4 000EAD44  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800EDDE8 000EAD48  3B C3 00 00 */	addi r30, r3, 0
/* 800EDDEC 000EAD4C  4B F9 D0 ED */	bl __ct__8CreatureFP12CreatureProp
/* 800EDDF0 000EAD50  3C 60 80 2C */	lis r3, __vt__8SeedItem@ha
/* 800EDDF4 000EAD54  38 03 D6 80 */	addi r0, r3, __vt__8SeedItem@l
/* 800EDDF8 000EAD58  3C 60 80 09 */	lis r3, __ct__10SearchDataFv@ha
/* 800EDDFC 000EAD5C  90 1E 00 00 */	stw r0, 0(r30)
/* 800EDE00 000EAD60  38 83 A7 F8 */	addi r4, r3, __ct__10SearchDataFv@l
/* 800EDE04 000EAD64  38 7E 02 BC */	addi r3, r30, 0x2bc
/* 800EDE08 000EAD68  38 A0 00 00 */	li r5, 0
/* 800EDE0C 000EAD6C  38 C0 00 0C */	li r6, 0xc
/* 800EDE10 000EAD70  38 E0 00 03 */	li r7, 3
/* 800EDE14 000EAD74  48 12 6C 5D */	bl __construct_array
/* 800EDE18 000EAD78  C0 02 9B 38 */	lfs f0, lbl_803E9D38@sda21(r2)
/* 800EDE1C 000EAD7C  38 00 00 04 */	li r0, 4
/* 800EDE20 000EAD80  38 7E 01 B8 */	addi r3, r30, 0x1b8
/* 800EDE24 000EAD84  D0 1E 02 F8 */	stfs f0, 0x2f8(r30)
/* 800EDE28 000EAD88  38 9E 02 BC */	addi r4, r30, 0x2bc
/* 800EDE2C 000EAD8C  38 A0 00 03 */	li r5, 3
/* 800EDE30 000EAD90  D0 1E 02 F4 */	stfs f0, 0x2f4(r30)
/* 800EDE34 000EAD94  D0 1E 02 F0 */	stfs f0, 0x2f0(r30)
/* 800EDE38 000EAD98  80 DF 00 00 */	lwz r6, 0(r31)
/* 800EDE3C 000EAD9C  90 DE 02 E8 */	stw r6, 0x2e8(r30)
/* 800EDE40 000EADA0  80 DF 00 04 */	lwz r6, 4(r31)
/* 800EDE44 000EADA4  90 DE 02 EC */	stw r6, 0x2ec(r30)
/* 800EDE48 000EADA8  80 DE 02 E8 */	lwz r6, 0x2e8(r30)
/* 800EDE4C 000EADAC  90 DE 02 E4 */	stw r6, 0x2e4(r30)
/* 800EDE50 000EADB0  C0 02 9B 3C */	lfs f0, lbl_803E9D3C@sda21(r2)
/* 800EDE54 000EADB4  D0 1E 00 7C */	stfs f0, 0x7c(r30)
/* 800EDE58 000EADB8  D0 1E 00 80 */	stfs f0, 0x80(r30)
/* 800EDE5C 000EADBC  D0 1E 00 84 */	stfs f0, 0x84(r30)
/* 800EDE60 000EADC0  90 1E 00 68 */	stw r0, 0x68(r30)
/* 800EDE64 000EADC4  80 1E 00 C8 */	lwz r0, 0xc8(r30)
/* 800EDE68 000EADC8  54 00 05 EA */	rlwinm r0, r0, 0, 0x17, 0x15
/* 800EDE6C 000EADCC  90 1E 00 C8 */	stw r0, 0xc8(r30)
/* 800EDE70 000EADD0  80 1E 00 C8 */	lwz r0, 0xc8(r30)
/* 800EDE74 000EADD4  60 00 00 11 */	ori r0, r0, 0x11
/* 800EDE78 000EADD8  90 1E 00 C8 */	stw r0, 0xc8(r30)
/* 800EDE7C 000EADDC  4B FF 5E 05 */	bl init__12SearchBufferFP10SearchDatai
/* 800EDE80 000EADE0  38 00 00 02 */	li r0, 2
/* 800EDE84 000EADE4  90 1E 00 6C */	stw r0, 0x6c(r30)
/* 800EDE88 000EADE8  38 00 00 03 */	li r0, 3
/* 800EDE8C 000EADEC  38 7E 00 00 */	addi r3, r30, 0
/* 800EDE90 000EADF0  90 1E 02 B8 */	stw r0, 0x2b8(r30)
/* 800EDE94 000EADF4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800EDE98 000EADF8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800EDE9C 000EADFC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800EDEA0 000EAE00  38 21 00 20 */	addi r1, r1, 0x20
/* 800EDEA4 000EAE04  7C 08 03 A6 */	mtlr r0
/* 800EDEA8 000EAE08  4E 80 00 20 */	blr 

.global getSize__8SeedItemFv
getSize__8SeedItemFv:
/* 800EDEAC 000EAE0C  C0 22 9B 40 */	lfs f1, lbl_803E9D40@sda21(r2)
/* 800EDEB0 000EAE10  4E 80 00 20 */	blr 

.global init__8SeedItemFR8Vector3f
init__8SeedItemFR8Vector3f:
/* 800EDEB4 000EAE14  7C 08 02 A6 */	mflr r0
/* 800EDEB8 000EAE18  90 01 00 04 */	stw r0, 4(r1)
/* 800EDEBC 000EAE1C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800EDEC0 000EAE20  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800EDEC4 000EAE24  7C 7F 1B 78 */	mr r31, r3
/* 800EDEC8 000EAE28  4B F9 CD 3D */	bl init__8CreatureFR8Vector3f
/* 800EDECC 000EAE2C  38 7F 01 B8 */	addi r3, r31, 0x1b8
/* 800EDED0 000EAE30  38 9F 02 BC */	addi r4, r31, 0x2bc
/* 800EDED4 000EAE34  38 A0 00 03 */	li r5, 3
/* 800EDED8 000EAE38  4B FF 5D A9 */	bl init__12SearchBufferFP10SearchDatai
/* 800EDEDC 000EAE3C  38 00 00 03 */	li r0, 3
/* 800EDEE0 000EAE40  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800EDEE4 000EAE44  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800EDEE8 000EAE48  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800EDEEC 000EAE4C  38 21 00 18 */	addi r1, r1, 0x18
/* 800EDEF0 000EAE50  7C 08 03 A6 */	mtlr r0
/* 800EDEF4 000EAE54  4E 80 00 20 */	blr 

.global isVisible__8SeedItemFv
isVisible__8SeedItemFv:
/* 800EDEF8 000EAE58  80 03 02 B8 */	lwz r0, 0x2b8(r3)
/* 800EDEFC 000EAE5C  20 60 00 02 */	subfic r3, r0, 2
/* 800EDF00 000EAE60  30 03 FF FF */	addic r0, r3, -1
/* 800EDF04 000EAE64  7C 60 19 10 */	subfe r3, r0, r3
/* 800EDF08 000EAE68  4E 80 00 20 */	blr 

.global isAtari__8SeedItemFv
isAtari__8SeedItemFv:
/* 800EDF0C 000EAE6C  38 60 00 00 */	li r3, 0
/* 800EDF10 000EAE70  4E 80 00 20 */	blr 

.global doKill__8SeedItemFv
doKill__8SeedItemFv:
/* 800EDF14 000EAE74  7C 08 02 A6 */	mflr r0
/* 800EDF18 000EAE78  7C 64 1B 78 */	mr r4, r3
/* 800EDF1C 000EAE7C  90 01 00 04 */	stw r0, 4(r1)
/* 800EDF20 000EAE80  38 00 00 02 */	li r0, 2
/* 800EDF24 000EAE84  94 21 FF F8 */	stwu r1, -8(r1)
/* 800EDF28 000EAE88  90 03 02 B8 */	stw r0, 0x2b8(r3)
/* 800EDF2C 000EAE8C  80 6D 30 AC */	lwz r3, itemMgr@sda21(r13)
/* 800EDF30 000EAE90  81 83 00 00 */	lwz r12, 0(r3)
/* 800EDF34 000EAE94  81 8C 00 7C */	lwz r12, 0x7c(r12)
/* 800EDF38 000EAE98  7D 88 03 A6 */	mtlr r12
/* 800EDF3C 000EAE9C  4E 80 00 21 */	blrl 
/* 800EDF40 000EAEA0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800EDF44 000EAEA4  38 21 00 08 */	addi r1, r1, 8
/* 800EDF48 000EAEA8  7C 08 03 A6 */	mtlr r0
/* 800EDF4C 000EAEAC  4E 80 00 20 */	blr 

.global update__8SeedItemFv
update__8SeedItemFv:
/* 800EDF50 000EAEB0  7C 08 02 A6 */	mflr r0
/* 800EDF54 000EAEB4  90 01 00 04 */	stw r0, 4(r1)
/* 800EDF58 000EAEB8  94 21 FF 50 */	stwu r1, -0xb0(r1)
/* 800EDF5C 000EAEBC  DB E1 00 A8 */	stfd f31, 0xa8(r1)
/* 800EDF60 000EAEC0  DB C1 00 A0 */	stfd f30, 0xa0(r1)
/* 800EDF64 000EAEC4  DB A1 00 98 */	stfd f29, 0x98(r1)
/* 800EDF68 000EAEC8  DB 81 00 90 */	stfd f28, 0x90(r1)
/* 800EDF6C 000EAECC  DB 61 00 88 */	stfd f27, 0x88(r1)
/* 800EDF70 000EAED0  93 E1 00 84 */	stw r31, 0x84(r1)
/* 800EDF74 000EAED4  93 C1 00 80 */	stw r30, 0x80(r1)
/* 800EDF78 000EAED8  7C 7E 1B 78 */	mr r30, r3
/* 800EDF7C 000EAEDC  80 03 02 B8 */	lwz r0, 0x2b8(r3)
/* 800EDF80 000EAEE0  2C 00 00 00 */	cmpwi r0, 0
/* 800EDF84 000EAEE4  40 82 01 D4 */	bne lbl_800EE158
/* 800EDF88 000EAEE8  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 800EDF8C 000EAEEC  48 02 94 39 */	bl getNavi__7NaviMgrFv
/* 800EDF90 000EAEF0  C0 1E 00 94 */	lfs f0, 0x94(r30)
/* 800EDF94 000EAEF4  7C 7F 1B 78 */	mr r31, r3
/* 800EDF98 000EAEF8  C0 23 00 94 */	lfs f1, 0x94(r3)
/* 800EDF9C 000EAEFC  C0 43 00 9C */	lfs f2, 0x9c(r3)
/* 800EDFA0 000EAF00  EF C1 00 28 */	fsubs f30, f1, f0
/* 800EDFA4 000EAF04  C0 1E 00 9C */	lfs f0, 0x9c(r30)
/* 800EDFA8 000EAF08  C0 22 9B 38 */	lfs f1, lbl_803E9D38@sda21(r2)
/* 800EDFAC 000EAF0C  EF E2 00 28 */	fsubs f31, f2, f0
/* 800EDFB0 000EAF10  EC 1E 07 B2 */	fmuls f0, f30, f30
/* 800EDFB4 000EAF14  EC 5F 07 F2 */	fmuls f2, f31, f31
/* 800EDFB8 000EAF18  EC 00 08 2A */	fadds f0, f0, f1
/* 800EDFBC 000EAF1C  EF A2 00 2A */	fadds f29, f2, f0
/* 800EDFC0 000EAF20  FC 1D 08 40 */	fcmpo cr0, f29, f1
/* 800EDFC4 000EAF24  40 81 00 5C */	ble lbl_800EE020
/* 800EDFC8 000EAF28  FC 20 E8 34 */	frsqrte f1, f29
/* 800EDFCC 000EAF2C  C8 62 9B 48 */	lfd f3, lbl_803E9D48@sda21(r2)
/* 800EDFD0 000EAF30  C8 42 9B 50 */	lfd f2, lbl_803E9D50@sda21(r2)
/* 800EDFD4 000EAF34  FC 01 00 72 */	fmul f0, f1, f1
/* 800EDFD8 000EAF38  FC 23 00 72 */	fmul f1, f3, f1
/* 800EDFDC 000EAF3C  FC 1D 00 32 */	fmul f0, f29, f0
/* 800EDFE0 000EAF40  FC 02 00 28 */	fsub f0, f2, f0
/* 800EDFE4 000EAF44  FC 21 00 32 */	fmul f1, f1, f0
/* 800EDFE8 000EAF48  FC 01 00 72 */	fmul f0, f1, f1
/* 800EDFEC 000EAF4C  FC 23 00 72 */	fmul f1, f3, f1
/* 800EDFF0 000EAF50  FC 1D 00 32 */	fmul f0, f29, f0
/* 800EDFF4 000EAF54  FC 02 00 28 */	fsub f0, f2, f0
/* 800EDFF8 000EAF58  FC 21 00 32 */	fmul f1, f1, f0
/* 800EDFFC 000EAF5C  FC 01 00 72 */	fmul f0, f1, f1
/* 800EE000 000EAF60  FC 23 00 72 */	fmul f1, f3, f1
/* 800EE004 000EAF64  FC 1D 00 32 */	fmul f0, f29, f0
/* 800EE008 000EAF68  FC 02 00 28 */	fsub f0, f2, f0
/* 800EE00C 000EAF6C  FC 01 00 32 */	fmul f0, f1, f0
/* 800EE010 000EAF70  FC 1D 00 32 */	fmul f0, f29, f0
/* 800EE014 000EAF74  FC 00 00 18 */	frsp f0, f0
/* 800EE018 000EAF78  D0 01 00 40 */	stfs f0, 0x40(r1)
/* 800EE01C 000EAF7C  C3 A1 00 40 */	lfs f29, 0x40(r1)
lbl_800EE020:
/* 800EE020 000EAF80  C0 02 9B 58 */	lfs f0, lbl_803E9D58@sda21(r2)
/* 800EE024 000EAF84  FC 1D 00 40 */	fcmpo cr0, f29, f0
/* 800EE028 000EAF88  40 80 00 14 */	bge lbl_800EE03C
/* 800EE02C 000EAF8C  C3 62 9B 5C */	lfs f27, lbl_803E9D5C@sda21(r2)
/* 800EE030 000EAF90  C3 82 9B 44 */	lfs f28, lbl_803E9D44@sda21(r2)
/* 800EE034 000EAF94  C0 62 9B 60 */	lfs f3, lbl_803E9D60@sda21(r2)
/* 800EE038 000EAF98  48 00 00 58 */	b lbl_800EE090
lbl_800EE03C:
/* 800EE03C 000EAF9C  C0 A2 9B 44 */	lfs f5, lbl_803E9D44@sda21(r2)
/* 800EE040 000EAFA0  FC 1D 28 40 */	fcmpo cr0, f29, f5
/* 800EE044 000EAFA4  40 80 00 40 */	bge lbl_800EE084
/* 800EE048 000EAFA8  EC 3D 00 28 */	fsubs f1, f29, f0
/* 800EE04C 000EAFAC  C0 02 9B 68 */	lfs f0, lbl_803E9D68@sda21(r2)
/* 800EE050 000EAFB0  C0 62 9B 64 */	lfs f3, lbl_803E9D64@sda21(r2)
/* 800EE054 000EAFB4  C0 42 9B 6C */	lfs f2, lbl_803E9D6C@sda21(r2)
/* 800EE058 000EAFB8  EC C1 00 24 */	fdivs f6, f1, f0
/* 800EE05C 000EAFBC  C0 02 9B 70 */	lfs f0, lbl_803E9D70@sda21(r2)
/* 800EE060 000EAFC0  C0 82 9B 5C */	lfs f4, lbl_803E9D5C@sda21(r2)
/* 800EE064 000EAFC4  C0 22 9B 60 */	lfs f1, lbl_803E9D60@sda21(r2)
/* 800EE068 000EAFC8  EC 63 01 B2 */	fmuls f3, f3, f6
/* 800EE06C 000EAFCC  EC 42 01 B2 */	fmuls f2, f2, f6
/* 800EE070 000EAFD0  EC 00 01 B2 */	fmuls f0, f0, f6
/* 800EE074 000EAFD4  EF 64 18 2A */	fadds f27, f4, f3
/* 800EE078 000EAFD8  EF 85 10 2A */	fadds f28, f5, f2
/* 800EE07C 000EAFDC  EC 61 00 2A */	fadds f3, f1, f0
/* 800EE080 000EAFE0  48 00 00 10 */	b lbl_800EE090
lbl_800EE084:
/* 800EE084 000EAFE4  C3 62 9B 74 */	lfs f27, lbl_803E9D74@sda21(r2)
/* 800EE088 000EAFE8  C3 82 9B 78 */	lfs f28, lbl_803E9D78@sda21(r2)
/* 800EE08C 000EAFEC  C0 62 9B 7C */	lfs f3, lbl_803E9D7C@sda21(r2)
lbl_800EE090:
/* 800EE090 000EAFF0  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800EE094 000EAFF4  C0 22 9B 80 */	lfs f1, lbl_803E9D80@sda21(r2)
/* 800EE098 000EAFF8  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800EE09C 000EAFFC  C0 5E 00 A0 */	lfs f2, 0xa0(r30)
/* 800EE0A0 000EB000  EC 01 00 32 */	fmuls f0, f1, f0
/* 800EE0A4 000EB004  EC 03 00 32 */	fmuls f0, f3, f0
/* 800EE0A8 000EB008  EC 02 00 2A */	fadds f0, f2, f0
/* 800EE0AC 000EB00C  D0 1E 00 A0 */	stfs f0, 0xa0(r30)
/* 800EE0B0 000EB010  C0 3E 00 A0 */	lfs f1, 0xa0(r30)
/* 800EE0B4 000EB014  4B F4 A4 D5 */	bl roundAng__Ff
/* 800EE0B8 000EB018  D0 3E 00 A0 */	stfs f1, 0xa0(r30)
/* 800EE0BC 000EB01C  C0 0D CD 10 */	lfs f0, lbl_803E1A30@sda21(r13)
/* 800EE0C0 000EB020  D0 1E 00 88 */	stfs f0, 0x88(r30)
/* 800EE0C4 000EB024  C0 1E 00 A0 */	lfs f0, 0xa0(r30)
/* 800EE0C8 000EB028  D0 1E 00 8C */	stfs f0, 0x8c(r30)
/* 800EE0CC 000EB02C  C0 0D CD 14 */	lfs f0, lbl_803E1A34@sda21(r13)
/* 800EE0D0 000EB030  D0 1E 00 90 */	stfs f0, 0x90(r30)
/* 800EE0D4 000EB034  C0 02 9B 60 */	lfs f0, lbl_803E9D60@sda21(r2)
/* 800EE0D8 000EB038  EC 00 E8 24 */	fdivs f0, f0, f29
/* 800EE0DC 000EB03C  EC 3E 00 32 */	fmuls f1, f30, f0
/* 800EE0E0 000EB040  EC 1F 00 32 */	fmuls f0, f31, f0
/* 800EE0E4 000EB044  EC 3C 00 72 */	fmuls f1, f28, f1
/* 800EE0E8 000EB048  EC 1C 00 32 */	fmuls f0, f28, f0
/* 800EE0EC 000EB04C  D0 3E 00 70 */	stfs f1, 0x70(r30)
/* 800EE0F0 000EB050  D0 1E 00 78 */	stfs f0, 0x78(r30)
/* 800EE0F4 000EB054  C0 1E 00 98 */	lfs f0, 0x98(r30)
/* 800EE0F8 000EB058  FC 00 D8 40 */	fcmpo cr0, f0, f27
/* 800EE0FC 000EB05C  40 80 00 38 */	bge lbl_800EE134
/* 800EE100 000EB060  C0 7E 00 74 */	lfs f3, 0x74(r30)
/* 800EE104 000EB064  C0 02 9B 74 */	lfs f0, lbl_803E9D74@sda21(r2)
/* 800EE108 000EB068  FC 03 00 40 */	fcmpo cr0, f3, f0
/* 800EE10C 000EB06C  40 80 00 28 */	bge lbl_800EE134
/* 800EE110 000EB070  80 8D 2F 80 */	lwz r4, _instance__10AIConstant@sda21(r13)
/* 800EE114 000EB074  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800EE118 000EB078  C0 24 00 30 */	lfs f1, 0x30(r4)
/* 800EE11C 000EB07C  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800EE120 000EB080  C0 42 9B 84 */	lfs f2, lbl_803E9D84@sda21(r2)
/* 800EE124 000EB084  EC 01 00 32 */	fmuls f0, f1, f0
/* 800EE128 000EB088  EC 02 00 32 */	fmuls f0, f2, f0
/* 800EE12C 000EB08C  EC 03 00 2A */	fadds f0, f3, f0
/* 800EE130 000EB090  D0 1E 00 74 */	stfs f0, 0x74(r30)
lbl_800EE134:
/* 800EE134 000EB094  C0 02 9B 88 */	lfs f0, lbl_803E9D88@sda21(r2)
/* 800EE138 000EB098  FC 1D 00 40 */	fcmpo cr0, f29, f0
/* 800EE13C 000EB09C  40 80 00 1C */	bge lbl_800EE158
/* 800EE140 000EB0A0  80 BF 07 2C */	lwz r5, 0x72c(r31)
/* 800EE144 000EB0A4  38 7E 00 00 */	addi r3, r30, 0
/* 800EE148 000EB0A8  38 80 00 00 */	li r4, 0
/* 800EE14C 000EB0AC  38 05 00 01 */	addi r0, r5, 1
/* 800EE150 000EB0B0  90 1F 07 2C */	stw r0, 0x72c(r31)
/* 800EE154 000EB0B4  4B F9 CB 8D */	bl kill__8CreatureFb
lbl_800EE158:
/* 800EE158 000EB0B8  7F C3 F3 78 */	mr r3, r30
/* 800EE15C 000EB0BC  4B F9 D8 21 */	bl updateAI__8CreatureFv
/* 800EE160 000EB0C0  80 01 00 B4 */	lwz r0, 0xb4(r1)
/* 800EE164 000EB0C4  CB E1 00 A8 */	lfd f31, 0xa8(r1)
/* 800EE168 000EB0C8  CB C1 00 A0 */	lfd f30, 0xa0(r1)
/* 800EE16C 000EB0CC  CB A1 00 98 */	lfd f29, 0x98(r1)
/* 800EE170 000EB0D0  CB 81 00 90 */	lfd f28, 0x90(r1)
/* 800EE174 000EB0D4  CB 61 00 88 */	lfd f27, 0x88(r1)
/* 800EE178 000EB0D8  83 E1 00 84 */	lwz r31, 0x84(r1)
/* 800EE17C 000EB0DC  83 C1 00 80 */	lwz r30, 0x80(r1)
/* 800EE180 000EB0E0  38 21 00 B0 */	addi r1, r1, 0xb0
/* 800EE184 000EB0E4  7C 08 03 A6 */	mtlr r0
/* 800EE188 000EB0E8  4E 80 00 20 */	blr 

.global doAI__8SeedItemFv
doAI__8SeedItemFv:
/* 800EE18C 000EB0EC  80 03 02 B8 */	lwz r0, 0x2b8(r3)
/* 800EE190 000EB0F0  2C 00 00 02 */	cmpwi r0, 2
/* 800EE194 000EB0F4  4D 82 00 20 */	beqlr 
/* 800EE198 000EB0F8  4E 80 00 20 */	blr 

.global refresh__8SeedItemFR8Graphics
refresh__8SeedItemFR8Graphics:
/* 800EE19C 000EB0FC  7C 08 02 A6 */	mflr r0
/* 800EE1A0 000EB100  90 01 00 04 */	stw r0, 4(r1)
/* 800EE1A4 000EB104  94 21 FF 60 */	stwu r1, -0xa0(r1)
/* 800EE1A8 000EB108  93 E1 00 9C */	stw r31, 0x9c(r1)
/* 800EE1AC 000EB10C  3B E4 00 00 */	addi r31, r4, 0
/* 800EE1B0 000EB110  93 C1 00 98 */	stw r30, 0x98(r1)
/* 800EE1B4 000EB114  7C 7E 1B 78 */	mr r30, r3
/* 800EE1B8 000EB118  80 03 02 B8 */	lwz r0, 0x2b8(r3)
/* 800EE1BC 000EB11C  2C 00 00 02 */	cmpwi r0, 2
/* 800EE1C0 000EB120  41 82 00 FC */	beq lbl_800EE2BC
/* 800EE1C4 000EB124  38 7E 02 28 */	addi r3, r30, 0x228
/* 800EE1C8 000EB128  38 9E 00 7C */	addi r4, r30, 0x7c
/* 800EE1CC 000EB12C  38 BE 00 88 */	addi r5, r30, 0x88
/* 800EE1D0 000EB130  38 DE 00 94 */	addi r6, r30, 0x94
/* 800EE1D4 000EB134  4B F4 FF 21 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 800EE1D8 000EB138  7F E3 FB 78 */	mr r3, r31
/* 800EE1DC 000EB13C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800EE1E0 000EB140  38 9E 02 28 */	addi r4, r30, 0x228
/* 800EE1E4 000EB144  38 A1 00 14 */	addi r5, r1, 0x14
/* 800EE1E8 000EB148  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 800EE1EC 000EB14C  7D 88 03 A6 */	mtlr r12
/* 800EE1F0 000EB150  4E 80 00 21 */	blrl 
/* 800EE1F4 000EB154  7F E3 FB 78 */	mr r3, r31
/* 800EE1F8 000EB158  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800EE1FC 000EB15C  38 81 00 14 */	addi r4, r1, 0x14
/* 800EE200 000EB160  38 A0 00 00 */	li r5, 0
/* 800EE204 000EB164  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800EE208 000EB168  7D 88 03 A6 */	mtlr r12
/* 800EE20C 000EB16C  4E 80 00 21 */	blrl 
/* 800EE210 000EB170  38 1E 00 94 */	addi r0, r30, 0x94
/* 800EE214 000EB174  80 9F 02 E4 */	lwz r4, 0x2e4(r31)
/* 800EE218 000EB178  7C 60 00 D0 */	neg r3, r0
/* 800EE21C 000EB17C  30 03 FF FF */	addic r0, r3, -1
/* 800EE220 000EB180  7C 00 19 10 */	subfe r0, r0, r3
/* 800EE224 000EB184  98 04 01 54 */	stb r0, 0x154(r4)
/* 800EE228 000EB188  88 04 01 54 */	lbz r0, 0x154(r4)
/* 800EE22C 000EB18C  28 00 00 00 */	cmplwi r0, 0
/* 800EE230 000EB190  41 82 00 1C */	beq lbl_800EE24C
/* 800EE234 000EB194  80 7E 00 94 */	lwz r3, 0x94(r30)
/* 800EE238 000EB198  80 1E 00 98 */	lwz r0, 0x98(r30)
/* 800EE23C 000EB19C  90 64 01 58 */	stw r3, 0x158(r4)
/* 800EE240 000EB1A0  90 04 01 5C */	stw r0, 0x15c(r4)
/* 800EE244 000EB1A4  80 1E 00 9C */	lwz r0, 0x9c(r30)
/* 800EE248 000EB1A8  90 04 01 60 */	stw r0, 0x160(r4)
lbl_800EE24C:
/* 800EE24C 000EB1AC  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 800EE250 000EB1B0  C0 3E 00 94 */	lfs f1, 0x94(r30)
/* 800EE254 000EB1B4  C0 5E 00 9C */	lfs f2, 0x9c(r30)
/* 800EE258 000EB1B8  4B F7 9B 41 */	bl getLight__6MapMgrFff
/* 800EE25C 000EB1BC  7F E3 FB 78 */	mr r3, r31
/* 800EE260 000EB1C0  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800EE264 000EB1C4  38 80 00 01 */	li r4, 1
/* 800EE268 000EB1C8  38 A0 00 00 */	li r5, 0
/* 800EE26C 000EB1CC  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 800EE270 000EB1D0  7D 88 03 A6 */	mtlr r12
/* 800EE274 000EB1D4  4E 80 00 21 */	blrl 
/* 800EE278 000EB1D8  80 7E 02 E4 */	lwz r3, 0x2e4(r30)
/* 800EE27C 000EB1DC  7F E4 FB 78 */	mr r4, r31
/* 800EE280 000EB1E0  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 800EE284 000EB1E4  38 C0 00 00 */	li r6, 0
/* 800EE288 000EB1E8  4B F4 21 E5 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 800EE28C 000EB1EC  80 9F 02 E4 */	lwz r4, 0x2e4(r31)
/* 800EE290 000EB1F0  38 00 00 00 */	li r0, 0
/* 800EE294 000EB1F4  98 04 01 54 */	stb r0, 0x154(r4)
/* 800EE298 000EB1F8  88 04 01 54 */	lbz r0, 0x154(r4)
/* 800EE29C 000EB1FC  28 00 00 00 */	cmplwi r0, 0
/* 800EE2A0 000EB200  41 82 00 1C */	beq lbl_800EE2BC
/* 800EE2A4 000EB204  80 60 00 00 */	lwz r3, 0(0)
/* 800EE2A8 000EB208  80 00 00 04 */	lwz r0, 4(0)
/* 800EE2AC 000EB20C  90 64 01 58 */	stw r3, 0x158(r4)
/* 800EE2B0 000EB210  90 04 01 5C */	stw r0, 0x15c(r4)
/* 800EE2B4 000EB214  80 00 00 08 */	lwz r0, 8(0)
/* 800EE2B8 000EB218  90 04 01 60 */	stw r0, 0x160(r4)
lbl_800EE2BC:
/* 800EE2BC 000EB21C  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 800EE2C0 000EB220  83 E1 00 9C */	lwz r31, 0x9c(r1)
/* 800EE2C4 000EB224  83 C1 00 98 */	lwz r30, 0x98(r1)
/* 800EE2C8 000EB228  38 21 00 A0 */	addi r1, r1, 0xa0
/* 800EE2CC 000EB22C  7C 08 03 A6 */	mtlr r0
/* 800EE2D0 000EB230  4E 80 00 20 */	blr 

.global stimulate__8SeedItemFR11Interaction
stimulate__8SeedItemFR11Interaction:
/* 800EE2D4 000EB234  7C 08 02 A6 */	mflr r0
/* 800EE2D8 000EB238  90 01 00 04 */	stw r0, 4(r1)
/* 800EE2DC 000EB23C  38 03 00 00 */	addi r0, r3, 0
/* 800EE2E0 000EB240  38 64 00 00 */	addi r3, r4, 0
/* 800EE2E4 000EB244  94 21 FF F8 */	stwu r1, -8(r1)
/* 800EE2E8 000EB248  81 84 00 00 */	lwz r12, 0(r4)
/* 800EE2EC 000EB24C  7C 04 03 78 */	mr r4, r0
/* 800EE2F0 000EB250  81 8C 00 08 */	lwz r12, 8(r12)
/* 800EE2F4 000EB254  7D 88 03 A6 */	mtlr r12
/* 800EE2F8 000EB258  4E 80 00 21 */	blrl 
/* 800EE2FC 000EB25C  38 60 00 01 */	li r3, 1
/* 800EE300 000EB260  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800EE304 000EB264  38 21 00 08 */	addi r1, r1, 8
/* 800EE308 000EB268  7C 08 03 A6 */	mtlr r0
/* 800EE30C 000EB26C  4E 80 00 20 */	blr 

.global getHeight__8SeedItemFv
getHeight__8SeedItemFv:
/* 800EE310 000EB270  C0 22 9B 38 */	lfs f1, lbl_803E9D38@sda21(r2)
/* 800EE314 000EB274  4E 80 00 20 */	blr 

.global getiMass__8SeedItemFv
getiMass__8SeedItemFv:
/* 800EE318 000EB278  C0 22 9B 74 */	lfs f1, lbl_803E9D74@sda21(r2)
/* 800EE31C 000EB27C  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BD600:
	.asciz "seedItem.cpp"
.balign 4
lbl_802BD610:
	.asciz "seedItem"
.balign 4
lbl_802BD61C:
	.asciz "SeedItem"
.balign 4
lbl_802BD628:
	.asciz "EventTalker"
.balign 4
lbl_802BD634:
	.asciz "RefCountable"
.balign 4
lbl_802BD644:
	.asciz "Creature"
.balign 4
lbl_802BD650:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
lbl_802BD664:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
.global __vt__8SeedItem
__vt__8SeedItem:
	.4byte __RTTI__8SeedItem
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8SeedItemFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__8SeedItemFv
	.4byte getSize__8SeedItemFv
	.4byte getHeight__8SeedItemFv
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
	.4byte isVisible__8SeedItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8SeedItemFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__8SeedItemFR11Interaction
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
	.4byte update__8SeedItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__8SeedItemFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__8SeedItemFv
	.4byte doAnimation__8CreatureFv
	.4byte doKill__8SeedItemFv
	.4byte exitCourse__8CreatureFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E1A30:
	.float 0.0
lbl_803E1A34:
	.float 0.0
__RTTI__11EventTalker:
	.4byte lbl_802BD628
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802BD634
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802BD644
	.4byte lbl_802BD650
__RTTI__8SeedItem:
	.4byte lbl_802BD61C
	.4byte lbl_802BD664

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E9D38:
	.float 0.0
lbl_803E9D3C:
	.float 0.2
lbl_803E9D40:
	.float 10.0
lbl_803E9D44:
	.float 200.0
lbl_803E9D48:
	.double 0.5
lbl_803E9D50:
	.double 3.0
lbl_803E9D58:
	.float 20.0
lbl_803E9D5C:
	.float 30.0
lbl_803E9D60:
	.float 1.0
lbl_803E9D64:
	.float 70.0
lbl_803E9D68:
	.float 180.0
lbl_803E9D6C:
	.float 150.0
lbl_803E9D70:
	.float 5.0
lbl_803E9D74:
	.float 100.0
lbl_803E9D78:
	.float 350.0
lbl_803E9D7C:
	.float 6.0
lbl_803E9D80:
	.float 3.1415927
lbl_803E9D84:
	.float 2.5
lbl_803E9D88:
	.float 8.0
