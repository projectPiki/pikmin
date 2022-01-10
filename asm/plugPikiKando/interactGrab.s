.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global actCommon__12InteractGrabFP8Creature
actCommon__12InteractGrabFP8Creature:
/* 8007C89C 000797FC  7C 08 02 A6 */	mflr r0
/* 8007C8A0 00079800  90 01 00 04 */	stw r0, 4(r1)
/* 8007C8A4 00079804  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8007C8A8 00079808  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8007C8AC 0007980C  7C 9F 23 78 */	mr r31, r4
/* 8007C8B0 00079810  80 83 00 04 */	lwz r4, 4(r3)
/* 8007C8B4 00079814  7F E3 FB 78 */	mr r3, r31
/* 8007C8B8 00079818  48 00 DF E5 */	bl setStateGrabbed__8CreatureFP8Creature
/* 8007C8BC 0007981C  80 1F 00 6C */	lwz r0, 0x6c(r31)
/* 8007C8C0 00079820  2C 00 00 0E */	cmpwi r0, 0xe
/* 8007C8C4 00079824  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8007C8C8 00079828  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8007C8CC 0007982C  38 21 00 18 */	addi r1, r1, 0x18
/* 8007C8D0 00079830  7C 08 03 A6 */	mtlr r0
/* 8007C8D4 00079834  4E 80 00 20 */	blr 

.global actCommon__15InteractReleaseFP8Creature
actCommon__15InteractReleaseFP8Creature:
/* 8007C8D8 00079838  7C 08 02 A6 */	mflr r0
/* 8007C8DC 0007983C  90 01 00 04 */	stw r0, 4(r1)
/* 8007C8E0 00079840  94 21 FF 48 */	stwu r1, -0xb8(r1)
/* 8007C8E4 00079844  DB E1 00 B0 */	stfd f31, 0xb0(r1)
/* 8007C8E8 00079848  DB C1 00 A8 */	stfd f30, 0xa8(r1)
/* 8007C8EC 0007984C  DB A1 00 A0 */	stfd f29, 0xa0(r1)
/* 8007C8F0 00079850  93 E1 00 9C */	stw r31, 0x9c(r1)
/* 8007C8F4 00079854  3B E4 00 00 */	addi r31, r4, 0
/* 8007C8F8 00079858  93 C1 00 98 */	stw r30, 0x98(r1)
/* 8007C8FC 0007985C  3B C3 00 00 */	addi r30, r3, 0
/* 8007C900 00079860  38 7F 00 00 */	addi r3, r31, 0
/* 8007C904 00079864  48 00 E0 D1 */	bl resetStateGrabbed__8CreatureFv
/* 8007C908 00079868  80 9E 00 04 */	lwz r4, 4(r30)
/* 8007C90C 0007986C  7F E5 FB 78 */	mr r5, r31
/* 8007C910 00079870  C0 0D 9C A8 */	lfs f0, lbl_803DE9C8@sda21(r13)
/* 8007C914 00079874  38 61 00 60 */	addi r3, r1, 0x60
/* 8007C918 00079878  C4 24 00 70 */	lfsu f1, 0x70(r4)
/* 8007C91C 0007987C  C0 42 89 58 */	lfs f2, lbl_803E8B58@sda21(r2)
/* 8007C920 00079880  EC 21 00 2A */	fadds f1, f1, f0
/* 8007C924 00079884  C0 0D 9C AC */	lfs f0, lbl_803DE9CC@sda21(r13)
/* 8007C928 00079888  D0 21 00 48 */	stfs f1, 0x48(r1)
/* 8007C92C 0007988C  C0 21 00 48 */	lfs f1, 0x48(r1)
/* 8007C930 00079890  D0 21 00 88 */	stfs f1, 0x88(r1)
/* 8007C934 00079894  C0 3E 00 08 */	lfs f1, 8(r30)
/* 8007C938 00079898  C0 64 00 04 */	lfs f3, 4(r4)
/* 8007C93C 0007989C  EC 22 00 72 */	fmuls f1, f2, f1
/* 8007C940 000798A0  EC 23 08 2A */	fadds f1, f3, f1
/* 8007C944 000798A4  D0 21 00 8C */	stfs f1, 0x8c(r1)
/* 8007C948 000798A8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8007C94C 000798AC  EC 01 00 2A */	fadds f0, f1, f0
/* 8007C950 000798B0  D0 01 00 90 */	stfs f0, 0x90(r1)
/* 8007C954 000798B4  80 81 00 88 */	lwz r4, 0x88(r1)
/* 8007C958 000798B8  80 01 00 8C */	lwz r0, 0x8c(r1)
/* 8007C95C 000798BC  90 9F 00 70 */	stw r4, 0x70(r31)
/* 8007C960 000798C0  90 1F 00 74 */	stw r0, 0x74(r31)
/* 8007C964 000798C4  80 01 00 90 */	lwz r0, 0x90(r1)
/* 8007C968 000798C8  90 1F 00 78 */	stw r0, 0x78(r31)
/* 8007C96C 000798CC  80 9E 00 04 */	lwz r4, 4(r30)
/* 8007C970 000798D0  C3 ED 9C B0 */	lfs f31, lbl_803DE9D0@sda21(r13)
/* 8007C974 000798D4  81 84 00 00 */	lwz r12, 0(r4)
/* 8007C978 000798D8  C3 CD 9C B4 */	lfs f30, lbl_803DE9D4@sda21(r13)
/* 8007C97C 000798DC  81 8C 01 00 */	lwz r12, 0x100(r12)
/* 8007C980 000798E0  C3 AD 9C B8 */	lfs f29, lbl_803DE9D8@sda21(r13)
/* 8007C984 000798E4  7D 88 03 A6 */	mtlr r12
/* 8007C988 000798E8  4E 80 00 21 */	blrl 
/* 8007C98C 000798EC  C0 01 00 60 */	lfs f0, 0x60(r1)
/* 8007C990 000798F0  38 60 00 01 */	li r3, 1
/* 8007C994 000798F4  C0 21 00 64 */	lfs f1, 0x64(r1)
/* 8007C998 000798F8  EC 40 F8 2A */	fadds f2, f0, f31
/* 8007C99C 000798FC  C0 01 00 68 */	lfs f0, 0x68(r1)
/* 8007C9A0 00079900  EC 21 F0 2A */	fadds f1, f1, f30
/* 8007C9A4 00079904  EC 00 E8 2A */	fadds f0, f0, f29
/* 8007C9A8 00079908  D0 41 00 3C */	stfs f2, 0x3c(r1)
/* 8007C9AC 0007990C  C0 41 00 3C */	lfs f2, 0x3c(r1)
/* 8007C9B0 00079910  D0 41 00 6C */	stfs f2, 0x6c(r1)
/* 8007C9B4 00079914  D0 21 00 70 */	stfs f1, 0x70(r1)
/* 8007C9B8 00079918  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 8007C9BC 0007991C  80 81 00 6C */	lwz r4, 0x6c(r1)
/* 8007C9C0 00079920  80 01 00 70 */	lwz r0, 0x70(r1)
/* 8007C9C4 00079924  90 9F 00 94 */	stw r4, 0x94(r31)
/* 8007C9C8 00079928  90 1F 00 98 */	stw r0, 0x98(r31)
/* 8007C9CC 0007992C  80 01 00 74 */	lwz r0, 0x74(r1)
/* 8007C9D0 00079930  90 1F 00 9C */	stw r0, 0x9c(r31)
/* 8007C9D4 00079934  80 01 00 BC */	lwz r0, 0xbc(r1)
/* 8007C9D8 00079938  CB E1 00 B0 */	lfd f31, 0xb0(r1)
/* 8007C9DC 0007993C  CB C1 00 A8 */	lfd f30, 0xa8(r1)
/* 8007C9E0 00079940  CB A1 00 A0 */	lfd f29, 0xa0(r1)
/* 8007C9E4 00079944  83 E1 00 9C */	lwz r31, 0x9c(r1)
/* 8007C9E8 00079948  83 C1 00 98 */	lwz r30, 0x98(r1)
/* 8007C9EC 0007994C  38 21 00 B8 */	addi r1, r1, 0xb8
/* 8007C9F0 00079950  7C 08 03 A6 */	mtlr r0
/* 8007C9F4 00079954  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802AD140:
	.asciz "interactGrab.cpp"
.balign 4
lbl_802AD154:
	.asciz "interactGrab"
.balign 4
lbl_802AD164:
	.asciz "InteractRelease"
.balign 4
lbl_802AD174:
	.asciz "Interaction"
.balign 4
lbl_802AD180:
	.4byte __RTTI__11Interaction
	.4byte 0
	.4byte 0
.global __vt__15InteractRelease
__vt__15InteractRelease:
	.4byte __RTTI__15InteractRelease
	.4byte 0
	.4byte actCommon__15InteractReleaseFP8Creature
	.4byte actPiki__11InteractionFP4Piki
	.4byte actTeki__11InteractionFP4Teki
	.4byte actNavi__11InteractionFP4Navi
	.4byte actBoss__11InteractionFP4Boss
	.4byte actPellet__11InteractionFP6Pellet
	.4byte actHinderRock__11InteractionFP10HinderRock
	.4byte actBridge__11InteractionFP6Bridge
	.4byte actItem__11InteractionFP12ItemCreature
.balign 4
lbl_802AD1B8:
	.asciz "InteractGrab"
.balign 4
lbl_802AD1C8:
	.4byte __RTTI__11Interaction
	.4byte 0
	.4byte 0
.global __vt__12InteractGrab
__vt__12InteractGrab:
	.4byte __RTTI__12InteractGrab
	.4byte 0
	.4byte actCommon__12InteractGrabFP8Creature
	.4byte actPiki__11InteractionFP4Piki
	.4byte actTeki__11InteractionFP4Teki
	.4byte actNavi__11InteractionFP4Navi
	.4byte actBoss__11InteractionFP4Boss
	.4byte actPellet__11InteractionFP6Pellet
	.4byte actHinderRock__11InteractionFP10HinderRock
	.4byte actBridge__11InteractionFP6Bridge
	.4byte actItem__11InteractionFP12ItemCreature

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DE9C8:
	.float 0.0
lbl_803DE9CC:
	.float 0.0
lbl_803DE9D0:
	.float 0.0
lbl_803DE9D4:
	.float 8.0
lbl_803DE9D8:
	.float 0.0
__RTTI__11Interaction:
	.4byte lbl_802AD174
	.4byte 0
__RTTI__15InteractRelease:
	.4byte lbl_802AD164
	.4byte lbl_802AD180
__RTTI__12InteractGrab:
	.4byte lbl_802AD1B8
	.4byte lbl_802AD1C8

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E8B58:
	.float 100.0
