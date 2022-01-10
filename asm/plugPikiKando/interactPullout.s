.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global actCommon__15InteractPulloutFP8Creature
actCommon__15InteractPulloutFP8Creature:
/* 8007CB38 00079A98  38 60 00 01 */	li r3, 1
/* 8007CB3C 00079A9C  4E 80 00 20 */	blr 

.global actPiki__15InteractPulloutFP4Piki
actPiki__15InteractPulloutFP4Piki:
/* 8007CB40 00079AA0  7C 08 02 A6 */	mflr r0
/* 8007CB44 00079AA4  90 01 00 04 */	stw r0, 4(r1)
/* 8007CB48 00079AA8  94 21 FE A0 */	stwu r1, -0x160(r1)
/* 8007CB4C 00079AAC  DB E1 01 58 */	stfd f31, 0x158(r1)
/* 8007CB50 00079AB0  DB C1 01 50 */	stfd f30, 0x150(r1)
/* 8007CB54 00079AB4  DB A1 01 48 */	stfd f29, 0x148(r1)
/* 8007CB58 00079AB8  DB 81 01 40 */	stfd f28, 0x140(r1)
/* 8007CB5C 00079ABC  DB 61 01 38 */	stfd f27, 0x138(r1)
/* 8007CB60 00079AC0  DB 41 01 30 */	stfd f26, 0x130(r1)
/* 8007CB64 00079AC4  DB 21 01 28 */	stfd f25, 0x128(r1)
/* 8007CB68 00079AC8  93 E1 01 24 */	stw r31, 0x124(r1)
/* 8007CB6C 00079ACC  3B E4 00 00 */	addi r31, r4, 0
/* 8007CB70 00079AD0  93 C1 01 20 */	stw r30, 0x120(r1)
/* 8007CB74 00079AD4  3B C3 00 00 */	addi r30, r3, 0
/* 8007CB78 00079AD8  38 7F 00 00 */	addi r3, r31, 0
/* 8007CB7C 00079ADC  93 A1 01 1C */	stw r29, 0x11c(r1)
/* 8007CB80 00079AE0  93 81 01 18 */	stw r28, 0x118(r1)
/* 8007CB84 00079AE4  48 04 B9 D1 */	bl getState__4PikiFv
/* 8007CB88 00079AE8  2C 03 00 03 */	cmpwi r3, 3
/* 8007CB8C 00079AEC  40 82 00 0C */	bne lbl_8007CB98
/* 8007CB90 00079AF0  38 60 00 00 */	li r3, 0
/* 8007CB94 00079AF4  48 00 02 2C */	b lbl_8007CDC0
lbl_8007CB98:
/* 8007CB98 00079AF8  80 7E 00 04 */	lwz r3, 4(r30)
/* 8007CB9C 00079AFC  C0 23 00 A0 */	lfs f1, 0xa0(r3)
/* 8007CBA0 00079B00  4B FB B9 E9 */	bl roundAng__Ff
/* 8007CBA4 00079B04  D0 3F 00 A0 */	stfs f1, 0xa0(r31)
/* 8007CBA8 00079B08  7F E4 FB 78 */	mr r4, r31
/* 8007CBAC 00079B0C  38 A0 00 03 */	li r5, 3
/* 8007CBB0 00079B10  C0 0D 9C F0 */	lfs f0, lbl_803DEA10@sda21(r13)
/* 8007CBB4 00079B14  D0 1F 00 88 */	stfs f0, 0x88(r31)
/* 8007CBB8 00079B18  C0 1F 00 A0 */	lfs f0, 0xa0(r31)
/* 8007CBBC 00079B1C  D0 1F 00 8C */	stfs f0, 0x8c(r31)
/* 8007CBC0 00079B20  C0 0D 9C F4 */	lfs f0, lbl_803DEA14@sda21(r13)
/* 8007CBC4 00079B24  D0 1F 00 90 */	stfs f0, 0x90(r31)
/* 8007CBC8 00079B28  80 7F 04 90 */	lwz r3, 0x490(r31)
/* 8007CBCC 00079B2C  81 83 00 00 */	lwz r12, 0(r3)
/* 8007CBD0 00079B30  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8007CBD4 00079B34  7D 88 03 A6 */	mtlr r12
/* 8007CBD8 00079B38  4E 80 00 21 */	blrl 
/* 8007CBDC 00079B3C  80 7F 05 04 */	lwz r3, 0x504(r31)
/* 8007CBE0 00079B40  88 03 07 E5 */	lbz r0, 0x7e5(r3)
/* 8007CBE4 00079B44  28 00 00 00 */	cmplwi r0, 0
/* 8007CBE8 00079B48  41 82 00 48 */	beq lbl_8007CC30
/* 8007CBEC 00079B4C  28 1F 00 00 */	cmplwi r31, 0
/* 8007CBF0 00079B50  3B 9F 00 00 */	addi r28, r31, 0
/* 8007CBF4 00079B54  41 82 00 08 */	beq lbl_8007CBFC
/* 8007CBF8 00079B58  3B 9C 02 B8 */	addi r28, r28, 0x2b8
lbl_8007CBFC:
/* 8007CBFC 00079B5C  38 61 00 E8 */	addi r3, r1, 0xe8
/* 8007CC00 00079B60  38 80 00 53 */	li r4, 0x53
/* 8007CC04 00079B64  48 0A 23 55 */	bl __ct__14PaniMotionInfoFi
/* 8007CC08 00079B68  3B A3 00 00 */	addi r29, r3, 0
/* 8007CC0C 00079B6C  38 BC 00 00 */	addi r5, r28, 0
/* 8007CC10 00079B70  38 61 00 F0 */	addi r3, r1, 0xf0
/* 8007CC14 00079B74  38 80 00 53 */	li r4, 0x53
/* 8007CC18 00079B78  48 0A 23 75 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 8007CC1C 00079B7C  38 83 00 00 */	addi r4, r3, 0
/* 8007CC20 00079B80  38 BD 00 00 */	addi r5, r29, 0
/* 8007CC24 00079B84  38 7F 03 54 */	addi r3, r31, 0x354
/* 8007CC28 00079B88  48 0A 2E 41 */	bl startMotion__15PaniPikiAnimMgrFR14PaniMotionInfoR14PaniMotionInfo
/* 8007CC2C 00079B8C  48 00 00 44 */	b lbl_8007CC70
lbl_8007CC30:
/* 8007CC30 00079B90  28 1F 00 00 */	cmplwi r31, 0
/* 8007CC34 00079B94  3B 9F 00 00 */	addi r28, r31, 0
/* 8007CC38 00079B98  41 82 00 08 */	beq lbl_8007CC40
/* 8007CC3C 00079B9C  3B 9C 02 B8 */	addi r28, r28, 0x2b8
lbl_8007CC40:
/* 8007CC40 00079BA0  38 61 00 D8 */	addi r3, r1, 0xd8
/* 8007CC44 00079BA4  38 80 00 06 */	li r4, 6
/* 8007CC48 00079BA8  48 0A 23 11 */	bl __ct__14PaniMotionInfoFi
/* 8007CC4C 00079BAC  3B A3 00 00 */	addi r29, r3, 0
/* 8007CC50 00079BB0  38 BC 00 00 */	addi r5, r28, 0
/* 8007CC54 00079BB4  38 61 00 E0 */	addi r3, r1, 0xe0
/* 8007CC58 00079BB8  38 80 00 06 */	li r4, 6
/* 8007CC5C 00079BBC  48 0A 23 31 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 8007CC60 00079BC0  38 83 00 00 */	addi r4, r3, 0
/* 8007CC64 00079BC4  38 BD 00 00 */	addi r5, r29, 0
/* 8007CC68 00079BC8  38 7F 03 54 */	addi r3, r31, 0x354
/* 8007CC6C 00079BCC  48 0A 2D FD */	bl startMotion__15PaniPikiAnimMgrFR14PaniMotionInfoR14PaniMotionInfo
lbl_8007CC70:
/* 8007CC70 00079BD0  80 BE 00 04 */	lwz r5, 4(r30)
/* 8007CC74 00079BD4  C0 7F 00 94 */	lfs f3, 0x94(r31)
/* 8007CC78 00079BD8  C0 45 00 94 */	lfs f2, 0x94(r5)
/* 8007CC7C 00079BDC  C0 9F 00 98 */	lfs f4, 0x98(r31)
/* 8007CC80 00079BE0  EF A3 10 28 */	fsubs f29, f3, f2
/* 8007CC84 00079BE4  C0 05 00 98 */	lfs f0, 0x98(r5)
/* 8007CC88 00079BE8  C3 E5 00 A0 */	lfs f31, 0xa0(r5)
/* 8007CC8C 00079BEC  EF 84 00 28 */	fsubs f28, f4, f0
/* 8007CC90 00079BF0  C0 7F 00 9C */	lfs f3, 0x9c(r31)
/* 8007CC94 00079BF4  C0 45 00 9C */	lfs f2, 0x9c(r5)
/* 8007CC98 00079BF8  FC 20 F8 90 */	fmr f1, f31
/* 8007CC9C 00079BFC  C3 42 89 60 */	lfs f26, lbl_803E8B60@sda21(r2)
/* 8007CCA0 00079C00  C0 02 89 68 */	lfs f0, lbl_803E8B68@sda21(r2)
/* 8007CCA4 00079C04  EF 63 10 28 */	fsubs f27, f3, f2
/* 8007CCA8 00079C08  C3 22 89 64 */	lfs f25, lbl_803E8B64@sda21(r2)
/* 8007CCAC 00079C0C  EF 5A 00 32 */	fmuls f26, f26, f0
/* 8007CCB0 00079C10  EF 39 00 32 */	fmuls f25, f25, f0
/* 8007CCB4 00079C14  48 19 F0 35 */	bl sinf
/* 8007CCB8 00079C18  EF D9 00 72 */	fmuls f30, f25, f1
/* 8007CCBC 00079C1C  FC 20 F8 90 */	fmr f1, f31
/* 8007CCC0 00079C20  48 19 EE 95 */	bl cosf
/* 8007CCC4 00079C24  FC 40 C8 50 */	fneg f2, f25
/* 8007CCC8 00079C28  C0 0D 9C F8 */	lfs f0, lbl_803DEA18@sda21(r13)
/* 8007CCCC 00079C2C  80 1F 04 B8 */	lwz r0, 0x4b8(r31)
/* 8007CCD0 00079C30  EF 7B F0 2A */	fadds f27, f27, f30
/* 8007CCD4 00079C34  EF 9C 00 2A */	fadds f28, f28, f0
/* 8007CCD8 00079C38  EC 02 00 72 */	fmuls f0, f2, f1
/* 8007CCDC 00079C3C  2C 00 00 01 */	cmpwi r0, 1
/* 8007CCE0 00079C40  EF BD 00 2A */	fadds f29, f29, f0
/* 8007CCE4 00079C44  40 82 00 10 */	bne lbl_8007CCF4
/* 8007CCE8 00079C48  80 7F 02 24 */	lwz r3, 0x224(r31)
/* 8007CCEC 00079C4C  C3 23 01 48 */	lfs f25, 0x148(r3)
/* 8007CCF0 00079C50  48 00 00 20 */	b lbl_8007CD10
lbl_8007CCF4:
/* 8007CCF4 00079C54  2C 00 00 02 */	cmpwi r0, 2
/* 8007CCF8 00079C58  40 82 00 10 */	bne lbl_8007CD08
/* 8007CCFC 00079C5C  80 7F 02 24 */	lwz r3, 0x224(r31)
/* 8007CD00 00079C60  C3 23 01 58 */	lfs f25, 0x158(r3)
/* 8007CD04 00079C64  48 00 00 0C */	b lbl_8007CD10
lbl_8007CD08:
/* 8007CD08 00079C68  80 7F 02 24 */	lwz r3, 0x224(r31)
/* 8007CD0C 00079C6C  C3 23 01 38 */	lfs f25, 0x138(r3)
lbl_8007CD10:
/* 8007CD10 00079C70  EF 5A 06 72 */	fmuls f26, f26, f25
/* 8007CD14 00079C74  FC 20 F8 90 */	fmr f1, f31
/* 8007CD18 00079C78  48 19 EE 3D */	bl cosf
/* 8007CD1C 00079C7C  FF 40 D0 50 */	fneg f26, f26
/* 8007CD20 00079C80  EF DA 00 72 */	fmuls f30, f26, f1
/* 8007CD24 00079C84  FC 20 F8 90 */	fmr f1, f31
/* 8007CD28 00079C88  48 19 EF C1 */	bl sinf
/* 8007CD2C 00079C8C  EC 1A 00 72 */	fmuls f0, f26, f1
/* 8007CD30 00079C90  C0 AD 9C FC */	lfs f5, lbl_803DEA1C@sda21(r13)
/* 8007CD34 00079C94  EC 5D 06 72 */	fmuls f2, f29, f25
/* 8007CD38 00079C98  38 60 00 01 */	li r3, 1
/* 8007CD3C 00079C9C  EC 3C 06 72 */	fmuls f1, f28, f25
/* 8007CD40 00079CA0  D0 01 00 A4 */	stfs f0, 0xa4(r1)
/* 8007CD44 00079CA4  EC 1B 06 72 */	fmuls f0, f27, f25
/* 8007CD48 00079CA8  80 9E 00 04 */	lwz r4, 4(r30)
/* 8007CD4C 00079CAC  C4 84 00 94 */	lfsu f4, 0x94(r4)
/* 8007CD50 00079CB0  C0 61 00 A4 */	lfs f3, 0xa4(r1)
/* 8007CD54 00079CB4  C0 C4 00 04 */	lfs f6, 4(r4)
/* 8007CD58 00079CB8  EC 64 18 2A */	fadds f3, f4, f3
/* 8007CD5C 00079CBC  C0 E4 00 08 */	lfs f7, 8(r4)
/* 8007CD60 00079CC0  EC A6 28 2A */	fadds f5, f6, f5
/* 8007CD64 00079CC4  EC 87 F0 2A */	fadds f4, f7, f30
/* 8007CD68 00079CC8  D0 61 00 84 */	stfs f3, 0x84(r1)
/* 8007CD6C 00079CCC  C0 61 00 84 */	lfs f3, 0x84(r1)
/* 8007CD70 00079CD0  D0 61 00 B4 */	stfs f3, 0xb4(r1)
/* 8007CD74 00079CD4  D0 A1 00 B8 */	stfs f5, 0xb8(r1)
/* 8007CD78 00079CD8  D0 81 00 BC */	stfs f4, 0xbc(r1)
/* 8007CD7C 00079CDC  C0 61 00 B4 */	lfs f3, 0xb4(r1)
/* 8007CD80 00079CE0  EC 43 10 2A */	fadds f2, f3, f2
/* 8007CD84 00079CE4  D0 41 00 78 */	stfs f2, 0x78(r1)
/* 8007CD88 00079CE8  C0 41 00 78 */	lfs f2, 0x78(r1)
/* 8007CD8C 00079CEC  D0 41 00 C0 */	stfs f2, 0xc0(r1)
/* 8007CD90 00079CF0  C0 41 00 B8 */	lfs f2, 0xb8(r1)
/* 8007CD94 00079CF4  EC 22 08 2A */	fadds f1, f2, f1
/* 8007CD98 00079CF8  D0 21 00 C4 */	stfs f1, 0xc4(r1)
/* 8007CD9C 00079CFC  C0 21 00 BC */	lfs f1, 0xbc(r1)
/* 8007CDA0 00079D00  EC 01 00 2A */	fadds f0, f1, f0
/* 8007CDA4 00079D04  D0 01 00 C8 */	stfs f0, 0xc8(r1)
/* 8007CDA8 00079D08  80 81 00 C0 */	lwz r4, 0xc0(r1)
/* 8007CDAC 00079D0C  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 8007CDB0 00079D10  90 9F 04 AC */	stw r4, 0x4ac(r31)
/* 8007CDB4 00079D14  90 1F 04 B0 */	stw r0, 0x4b0(r31)
/* 8007CDB8 00079D18  80 01 00 C8 */	lwz r0, 0xc8(r1)
/* 8007CDBC 00079D1C  90 1F 04 B4 */	stw r0, 0x4b4(r31)
lbl_8007CDC0:
/* 8007CDC0 00079D20  80 01 01 64 */	lwz r0, 0x164(r1)
/* 8007CDC4 00079D24  CB E1 01 58 */	lfd f31, 0x158(r1)
/* 8007CDC8 00079D28  CB C1 01 50 */	lfd f30, 0x150(r1)
/* 8007CDCC 00079D2C  CB A1 01 48 */	lfd f29, 0x148(r1)
/* 8007CDD0 00079D30  CB 81 01 40 */	lfd f28, 0x140(r1)
/* 8007CDD4 00079D34  CB 61 01 38 */	lfd f27, 0x138(r1)
/* 8007CDD8 00079D38  CB 41 01 30 */	lfd f26, 0x130(r1)
/* 8007CDDC 00079D3C  CB 21 01 28 */	lfd f25, 0x128(r1)
/* 8007CDE0 00079D40  83 E1 01 24 */	lwz r31, 0x124(r1)
/* 8007CDE4 00079D44  83 C1 01 20 */	lwz r30, 0x120(r1)
/* 8007CDE8 00079D48  83 A1 01 1C */	lwz r29, 0x11c(r1)
/* 8007CDEC 00079D4C  83 81 01 18 */	lwz r28, 0x118(r1)
/* 8007CDF0 00079D50  38 21 01 60 */	addi r1, r1, 0x160
/* 8007CDF4 00079D54  7C 08 03 A6 */	mtlr r0
/* 8007CDF8 00079D58  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802AD2B8:
	.asciz "interactPullout.cpp"
.balign 4
lbl_802AD2CC:
	.asciz "interactPullout"
.balign 4
lbl_802AD2DC:
	.asciz "InteractPullout"
.balign 4
lbl_802AD2EC:
	.asciz "Interaction"
.balign 4
lbl_802AD2F8:
	.4byte __RTTI__11Interaction
	.4byte 0
	.4byte 0
.global __vt__15InteractPullout
__vt__15InteractPullout:
	.4byte __RTTI__15InteractPullout
	.4byte 0
	.4byte actCommon__15InteractPulloutFP8Creature
	.4byte actPiki__15InteractPulloutFP4Piki
	.4byte actTeki__11InteractionFP4Teki
	.4byte actNavi__11InteractionFP4Navi
	.4byte actBoss__11InteractionFP4Boss
	.4byte actPellet__11InteractionFP6Pellet
	.4byte actHinderRock__11InteractionFP10HinderRock
	.4byte actBridge__11InteractionFP6Bridge
	.4byte actItem__15InteractPulloutFP12ItemCreature

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DEA10:
	.float 0.0
lbl_803DEA14:
	.float 0.0
lbl_803DEA18:
	.float 0.0
lbl_803DEA1C:
	.float 0.0
__RTTI__11Interaction:
	.4byte lbl_802AD2EC
	.4byte 0
__RTTI__15InteractPullout:
	.4byte lbl_802AD2DC
	.4byte lbl_802AD2F8

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E8B60:
	.float 43.8384
lbl_803E8B64:
	.float 15.0
lbl_803E8B68:
	.float 1.0
