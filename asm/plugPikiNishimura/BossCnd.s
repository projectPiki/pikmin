.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global satisfy__10CndIsAliveFP8Creature
satisfy__10CndIsAliveFP8Creature:
/* 8014FAFC 0014CA5C  7C 08 02 A6 */	mflr r0
/* 8014FB00 0014CA60  28 04 00 00 */	cmplwi r4, 0
/* 8014FB04 0014CA64  90 01 00 04 */	stw r0, 4(r1)
/* 8014FB08 0014CA68  94 21 FF F8 */	stwu r1, -8(r1)
/* 8014FB0C 0014CA6C  41 82 00 1C */	beq .L_8014FB28
/* 8014FB10 0014CA70  7C 83 23 78 */	mr r3, r4
/* 8014FB14 0014CA74  81 84 00 00 */	lwz r12, 0(r4)
/* 8014FB18 0014CA78  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 8014FB1C 0014CA7C  7D 88 03 A6 */	mtlr r12
/* 8014FB20 0014CA80  4E 80 00 21 */	blrl 
/* 8014FB24 0014CA84  48 00 00 08 */	b .L_8014FB2C
.L_8014FB28:
/* 8014FB28 0014CA88  38 60 00 00 */	li r3, 0
.L_8014FB2C:
/* 8014FB2C 0014CA8C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8014FB30 0014CA90  38 21 00 08 */	addi r1, r1, 8
/* 8014FB34 0014CA94  7C 08 03 A6 */	mtlr r0
/* 8014FB38 0014CA98  4E 80 00 20 */	blr 

.global satisfy__12CndBossFlickFP8Creature
satisfy__12CndBossFlickFP8Creature:
/* 8014FB3C 0014CA9C  7C 08 02 A6 */	mflr r0
/* 8014FB40 0014CAA0  90 01 00 04 */	stw r0, 4(r1)
/* 8014FB44 0014CAA4  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8014FB48 0014CAA8  93 E1 00 34 */	stw r31, 0x34(r1)
/* 8014FB4C 0014CAAC  7C 9F 23 79 */	or. r31, r4, r4
/* 8014FB50 0014CAB0  93 C1 00 30 */	stw r30, 0x30(r1)
/* 8014FB54 0014CAB4  3B C3 00 00 */	addi r30, r3, 0
/* 8014FB58 0014CAB8  41 82 00 90 */	beq .L_8014FBE8
/* 8014FB5C 0014CABC  7F E3 FB 78 */	mr r3, r31
/* 8014FB60 0014CAC0  81 9F 00 00 */	lwz r12, 0(r31)
/* 8014FB64 0014CAC4  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 8014FB68 0014CAC8  7D 88 03 A6 */	mtlr r12
/* 8014FB6C 0014CACC  4E 80 00 21 */	blrl 
/* 8014FB70 0014CAD0  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8014FB74 0014CAD4  41 82 00 74 */	beq .L_8014FBE8
/* 8014FB78 0014CAD8  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 8014FB7C 0014CADC  54 00 04 21 */	rlwinm. r0, r0, 0, 0x10, 0x10
/* 8014FB80 0014CAE0  40 82 00 68 */	bne .L_8014FBE8
/* 8014FB84 0014CAE4  80 1F 01 84 */	lwz r0, 0x184(r31)
/* 8014FB88 0014CAE8  80 7E 00 04 */	lwz r3, 4(r30)
/* 8014FB8C 0014CAEC  7C 00 18 40 */	cmplw r0, r3
/* 8014FB90 0014CAF0  40 82 00 58 */	bne .L_8014FBE8
/* 8014FB94 0014CAF4  80 63 02 24 */	lwz r3, 0x224(r3)
/* 8014FB98 0014CAF8  3B E3 01 18 */	addi r31, r3, 0x118
/* 8014FB9C 0014CAFC  48 0C 84 D5 */	bl rand
/* 8014FBA0 0014CB00  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 8014FBA4 0014CB04  C8 82 A8 70 */	lfd f4, lbl_803EAA70@sda21(r2)
/* 8014FBA8 0014CB08  90 01 00 2C */	stw r0, 0x2c(r1)
/* 8014FBAC 0014CB0C  3C 00 43 30 */	lis r0, 0x4330
/* 8014FBB0 0014CB10  C0 62 A8 64 */	lfs f3, lbl_803EAA64@sda21(r2)
/* 8014FBB4 0014CB14  90 01 00 28 */	stw r0, 0x28(r1)
/* 8014FBB8 0014CB18  C0 42 A8 60 */	lfs f2, lbl_803EAA60@sda21(r2)
/* 8014FBBC 0014CB1C  C8 01 00 28 */	lfd f0, 0x28(r1)
/* 8014FBC0 0014CB20  C0 22 A8 68 */	lfs f1, lbl_803EAA68@sda21(r2)
/* 8014FBC4 0014CB24  EC 80 20 28 */	fsubs f4, f0, f4
/* 8014FBC8 0014CB28  C0 1F 00 00 */	lfs f0, 0(r31)
/* 8014FBCC 0014CB2C  EC 64 18 24 */	fdivs f3, f4, f3
/* 8014FBD0 0014CB30  EC 42 00 F2 */	fmuls f2, f2, f3
/* 8014FBD4 0014CB34  EC 21 00 B2 */	fmuls f1, f1, f2
/* 8014FBD8 0014CB38  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8014FBDC 0014CB3C  40 80 00 0C */	bge .L_8014FBE8
/* 8014FBE0 0014CB40  38 60 00 01 */	li r3, 1
/* 8014FBE4 0014CB44  48 00 00 08 */	b .L_8014FBEC
.L_8014FBE8:
/* 8014FBE8 0014CB48  38 60 00 00 */	li r3, 0
.L_8014FBEC:
/* 8014FBEC 0014CB4C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8014FBF0 0014CB50  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 8014FBF4 0014CB54  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 8014FBF8 0014CB58  38 21 00 38 */	addi r1, r1, 0x38
/* 8014FBFC 0014CB5C  7C 08 03 A6 */	mtlr r0
/* 8014FC00 0014CB60  4E 80 00 20 */	blr 

.global satisfy__16CndStickBossKillFP8Creature
satisfy__16CndStickBossKillFP8Creature:
/* 8014FC04 0014CB64  7C 08 02 A6 */	mflr r0
/* 8014FC08 0014CB68  90 01 00 04 */	stw r0, 4(r1)
/* 8014FC0C 0014CB6C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8014FC10 0014CB70  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8014FC14 0014CB74  7C 9F 23 79 */	or. r31, r4, r4
/* 8014FC18 0014CB78  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8014FC1C 0014CB7C  3B C3 00 00 */	addi r30, r3, 0
/* 8014FC20 0014CB80  41 82 00 38 */	beq .L_8014FC58
/* 8014FC24 0014CB84  7F E3 FB 78 */	mr r3, r31
/* 8014FC28 0014CB88  81 9F 00 00 */	lwz r12, 0(r31)
/* 8014FC2C 0014CB8C  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 8014FC30 0014CB90  7D 88 03 A6 */	mtlr r12
/* 8014FC34 0014CB94  4E 80 00 21 */	blrl 
/* 8014FC38 0014CB98  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8014FC3C 0014CB9C  41 82 00 1C */	beq .L_8014FC58
/* 8014FC40 0014CBA0  80 7F 01 84 */	lwz r3, 0x184(r31)
/* 8014FC44 0014CBA4  80 1E 00 04 */	lwz r0, 4(r30)
/* 8014FC48 0014CBA8  7C 03 00 40 */	cmplw r3, r0
/* 8014FC4C 0014CBAC  40 82 00 0C */	bne .L_8014FC58
/* 8014FC50 0014CBB0  38 60 00 01 */	li r3, 1
/* 8014FC54 0014CBB4  48 00 00 08 */	b .L_8014FC5C
.L_8014FC58:
/* 8014FC58 0014CBB8  38 60 00 00 */	li r3, 0
.L_8014FC5C:
/* 8014FC5C 0014CBBC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8014FC60 0014CBC0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8014FC64 0014CBC4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8014FC68 0014CBC8  38 21 00 20 */	addi r1, r1, 0x20
/* 8014FC6C 0014CBCC  7C 08 03 A6 */	mtlr r0
/* 8014FC70 0014CBD0  4E 80 00 20 */	blr 

.global satisfy__17CndStickMouthKillFP8Creature
satisfy__17CndStickMouthKillFP8Creature:
/* 8014FC74 0014CBD4  7C 08 02 A6 */	mflr r0
/* 8014FC78 0014CBD8  90 01 00 04 */	stw r0, 4(r1)
/* 8014FC7C 0014CBDC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8014FC80 0014CBE0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8014FC84 0014CBE4  7C 9F 23 79 */	or. r31, r4, r4
/* 8014FC88 0014CBE8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8014FC8C 0014CBEC  3B C3 00 00 */	addi r30, r3, 0
/* 8014FC90 0014CBF0  41 82 00 44 */	beq .L_8014FCD4
/* 8014FC94 0014CBF4  7F E3 FB 78 */	mr r3, r31
/* 8014FC98 0014CBF8  81 9F 00 00 */	lwz r12, 0(r31)
/* 8014FC9C 0014CBFC  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 8014FCA0 0014CC00  7D 88 03 A6 */	mtlr r12
/* 8014FCA4 0014CC04  4E 80 00 21 */	blrl 
/* 8014FCA8 0014CC08  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8014FCAC 0014CC0C  41 82 00 28 */	beq .L_8014FCD4
/* 8014FCB0 0014CC10  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 8014FCB4 0014CC14  54 00 04 21 */	rlwinm. r0, r0, 0, 0x10, 0x10
/* 8014FCB8 0014CC18  41 82 00 1C */	beq .L_8014FCD4
/* 8014FCBC 0014CC1C  80 7F 01 84 */	lwz r3, 0x184(r31)
/* 8014FCC0 0014CC20  80 1E 00 04 */	lwz r0, 4(r30)
/* 8014FCC4 0014CC24  7C 03 00 40 */	cmplw r3, r0
/* 8014FCC8 0014CC28  40 82 00 0C */	bne .L_8014FCD4
/* 8014FCCC 0014CC2C  38 60 00 01 */	li r3, 1
/* 8014FCD0 0014CC30  48 00 00 08 */	b .L_8014FCD8
.L_8014FCD4:
/* 8014FCD4 0014CC34  38 60 00 00 */	li r3, 0
.L_8014FCD8:
/* 8014FCD8 0014CC38  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8014FCDC 0014CC3C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8014FCE0 0014CC40  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8014FCE4 0014CC44  38 21 00 20 */	addi r1, r1, 0x20
/* 8014FCE8 0014CC48  7C 08 03 A6 */	mtlr r0
/* 8014FCEC 0014CC4C  4E 80 00 20 */	blr 

.global satisfy__15CndBossCollKillFP8Creature
satisfy__15CndBossCollKillFP8Creature:
/* 8014FCF0 0014CC50  7C 08 02 A6 */	mflr r0
/* 8014FCF4 0014CC54  90 01 00 04 */	stw r0, 4(r1)
/* 8014FCF8 0014CC58  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8014FCFC 0014CC5C  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8014FD00 0014CC60  7C 9F 23 79 */	or. r31, r4, r4
/* 8014FD04 0014CC64  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8014FD08 0014CC68  3B C3 00 00 */	addi r30, r3, 0
/* 8014FD0C 0014CC6C  41 82 00 60 */	beq .L_8014FD6C
/* 8014FD10 0014CC70  7F E3 FB 78 */	mr r3, r31
/* 8014FD14 0014CC74  81 9F 00 00 */	lwz r12, 0(r31)
/* 8014FD18 0014CC78  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 8014FD1C 0014CC7C  7D 88 03 A6 */	mtlr r12
/* 8014FD20 0014CC80  4E 80 00 21 */	blrl 
/* 8014FD24 0014CC84  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8014FD28 0014CC88  41 82 00 44 */	beq .L_8014FD6C
/* 8014FD2C 0014CC8C  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 8014FD30 0014CC90  54 00 04 21 */	rlwinm. r0, r0, 0, 0x10, 0x10
/* 8014FD34 0014CC94  40 82 00 38 */	bne .L_8014FD6C
/* 8014FD38 0014CC98  80 7F 01 84 */	lwz r3, 0x184(r31)
/* 8014FD3C 0014CC9C  80 1E 00 04 */	lwz r0, 4(r30)
/* 8014FD40 0014CCA0  7C 03 00 40 */	cmplw r3, r0
/* 8014FD44 0014CCA4  40 82 00 28 */	bne .L_8014FD6C
/* 8014FD48 0014CCA8  80 9F 01 88 */	lwz r4, 0x188(r31)
/* 8014FD4C 0014CCAC  38 61 00 18 */	addi r3, r1, 0x18
/* 8014FD50 0014CCB0  4B F3 81 51 */	bl getID__8CollPartFv
/* 8014FD54 0014CCB4  80 61 00 18 */	lwz r3, 0x18(r1)
/* 8014FD58 0014CCB8  80 1E 00 08 */	lwz r0, 8(r30)
/* 8014FD5C 0014CCBC  7C 00 18 40 */	cmplw r0, r3
/* 8014FD60 0014CCC0  40 82 00 0C */	bne .L_8014FD6C
/* 8014FD64 0014CCC4  38 60 00 01 */	li r3, 1
/* 8014FD68 0014CCC8  48 00 00 08 */	b .L_8014FD70
.L_8014FD6C:
/* 8014FD6C 0014CCCC  38 60 00 00 */	li r3, 0
.L_8014FD70:
/* 8014FD70 0014CCD0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8014FD74 0014CCD4  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8014FD78 0014CCD8  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8014FD7C 0014CCDC  38 21 00 30 */	addi r1, r1, 0x30
/* 8014FD80 0014CCE0  7C 08 03 A6 */	mtlr r0
/* 8014FD84 0014CCE4  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802CEB48:
	.asciz "BossCnd.cpp"
.balign 4
lbl_802CEB54:
	.asciz "CndBossCollKill"
.balign 4
lbl_802CEB64:
	.asciz "Condition"
.balign 4
lbl_802CEB70:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.global __vt__15CndBossCollKill
__vt__15CndBossCollKill:
	.4byte __RTTI__15CndBossCollKill
	.4byte 0
	.4byte satisfy__15CndBossCollKillFP8Creature
.balign 4
lbl_802CEB88:
	.asciz "CndStickMouthKill"
.balign 4
lbl_802CEB9C:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.global __vt__17CndStickMouthKill
__vt__17CndStickMouthKill:
	.4byte __RTTI__17CndStickMouthKill
	.4byte 0
	.4byte satisfy__17CndStickMouthKillFP8Creature
.balign 4
lbl_802CEBB4:
	.asciz "CndStickBossKill"
.balign 4
lbl_802CEBC8:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.global __vt__16CndStickBossKill
__vt__16CndStickBossKill:
	.4byte __RTTI__16CndStickBossKill
	.4byte 0
	.4byte satisfy__16CndStickBossKillFP8Creature
.balign 4
lbl_802CEBE0:
	.asciz "CndBossFlick"
.balign 4
lbl_802CEBF0:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.global __vt__12CndBossFlick
__vt__12CndBossFlick:
	.4byte __RTTI__12CndBossFlick
	.4byte 0
	.4byte satisfy__12CndBossFlickFP8Creature
.balign 4
lbl_802CEC08:
	.asciz "CndIsAlive"
.balign 4
lbl_802CEC14:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.global __vt__10CndIsAlive
__vt__10CndIsAlive:
	.4byte __RTTI__10CndIsAlive
	.4byte 0
	.4byte satisfy__10CndIsAliveFP8Creature

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__9Condition:
	.4byte lbl_802CEB64
	.4byte 0
__RTTI__15CndBossCollKill:
	.4byte lbl_802CEB54
	.4byte lbl_802CEB70
__RTTI__17CndStickMouthKill:
	.4byte lbl_802CEB88
	.4byte lbl_802CEB9C
__RTTI__16CndStickBossKill:
	.4byte lbl_802CEBB4
	.4byte lbl_802CEBC8
__RTTI__12CndBossFlick:
	.4byte lbl_802CEBE0
	.4byte lbl_802CEBF0
__RTTI__10CndIsAlive:
	.4byte lbl_802CEC08
	.4byte lbl_802CEC14

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EAA60:
	.float 1.0
lbl_803EAA64:
	.4byte 0x46FFFE00
lbl_803EAA68:
	.4byte 0x3F7FFFEF
.balign 8
lbl_803EAA70:
	.4byte 0x43300000
	.4byte 0x80000000
