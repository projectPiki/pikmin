.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global actTeki__14InteractAttackFP4Teki
actTeki__14InteractAttackFP4Teki:
/* 8014A40C 0014736C  7C 08 02 A6 */	mflr r0
/* 8014A410 00147370  90 01 00 04 */	stw r0, 4(r1)
/* 8014A414 00147374  38 00 00 00 */	li r0, 0
/* 8014A418 00147378  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8014A41C 0014737C  90 01 00 10 */	stw r0, 0x10(r1)
/* 8014A420 00147380  38 01 00 10 */	addi r0, r1, 0x10
/* 8014A424 00147384  90 61 00 14 */	stw r3, 0x14(r1)
/* 8014A428 00147388  38 64 00 00 */	addi r3, r4, 0
/* 8014A42C 0014738C  7C 04 03 78 */	mr r4, r0
/* 8014A430 00147390  81 83 00 00 */	lwz r12, 0(r3)
/* 8014A434 00147394  81 8C 01 A4 */	lwz r12, 0x1a4(r12)
/* 8014A438 00147398  7D 88 03 A6 */	mtlr r12
/* 8014A43C 0014739C  4E 80 00 21 */	blrl 
/* 8014A440 001473A0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8014A444 001473A4  38 21 00 18 */	addi r1, r1, 0x18
/* 8014A448 001473A8  7C 08 03 A6 */	mtlr r0
/* 8014A44C 001473AC  4E 80 00 20 */	blr 

.global actTeki__12InteractBombFP4Teki
actTeki__12InteractBombFP4Teki:
/* 8014A450 001473B0  7C 08 02 A6 */	mflr r0
/* 8014A454 001473B4  3C A0 80 2B */	lis r5, __vt__11Interaction@ha
/* 8014A458 001473B8  90 01 00 04 */	stw r0, 4(r1)
/* 8014A45C 001473BC  38 E5 CF 9C */	addi r7, r5, __vt__11Interaction@l
/* 8014A460 001473C0  38 A0 00 00 */	li r5, 0
/* 8014A464 001473C4  94 21 FF 98 */	stwu r1, -0x68(r1)
/* 8014A468 001473C8  80 C4 02 C4 */	lwz r6, 0x2c4(r4)
/* 8014A46C 001473CC  38 01 00 48 */	addi r0, r1, 0x48
/* 8014A470 001473D0  C0 23 00 08 */	lfs f1, 8(r3)
/* 8014A474 001473D4  39 41 00 5C */	addi r10, r1, 0x5c
/* 8014A478 001473D8  80 C6 00 84 */	lwz r6, 0x84(r6)
/* 8014A47C 001473DC  81 23 00 04 */	lwz r9, 4(r3)
/* 8014A480 001473E0  3C 60 80 2B */	lis r3, __vt__14InteractAttack@ha
/* 8014A484 001473E4  81 06 00 04 */	lwz r8, 4(r6)
/* 8014A488 001473E8  38 C3 CE 04 */	addi r6, r3, __vt__14InteractAttack@l
/* 8014A48C 001473EC  80 68 00 00 */	lwz r3, 0(r8)
/* 8014A490 001473F0  C0 03 00 AC */	lfs f0, 0xac(r3)
/* 8014A494 001473F4  38 64 00 00 */	addi r3, r4, 0
/* 8014A498 001473F8  38 8A 00 00 */	addi r4, r10, 0
/* 8014A49C 001473FC  90 E1 00 48 */	stw r7, 0x48(r1)
/* 8014A4A0 00147400  EC 01 00 32 */	fmuls f0, f1, f0
/* 8014A4A4 00147404  91 21 00 4C */	stw r9, 0x4c(r1)
/* 8014A4A8 00147408  90 C1 00 48 */	stw r6, 0x48(r1)
/* 8014A4AC 0014740C  D0 01 00 50 */	stfs f0, 0x50(r1)
/* 8014A4B0 00147410  90 A1 00 54 */	stw r5, 0x54(r1)
/* 8014A4B4 00147414  90 A1 00 5C */	stw r5, 0x5c(r1)
/* 8014A4B8 00147418  98 A1 00 58 */	stb r5, 0x58(r1)
/* 8014A4BC 0014741C  90 01 00 60 */	stw r0, 0x60(r1)
/* 8014A4C0 00147420  81 83 00 00 */	lwz r12, 0(r3)
/* 8014A4C4 00147424  81 8C 01 A4 */	lwz r12, 0x1a4(r12)
/* 8014A4C8 00147428  7D 88 03 A6 */	mtlr r12
/* 8014A4CC 0014742C  4E 80 00 21 */	blrl 
/* 8014A4D0 00147430  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 8014A4D4 00147434  38 21 00 68 */	addi r1, r1, 0x68
/* 8014A4D8 00147438  7C 08 03 A6 */	mtlr r0
/* 8014A4DC 0014743C  4E 80 00 20 */	blr 

.global actTeki__17InteractHitEffectFP4Teki
actTeki__17InteractHitEffectFP4Teki:
/* 8014A4E0 00147440  7C 08 02 A6 */	mflr r0
/* 8014A4E4 00147444  90 01 00 04 */	stw r0, 4(r1)
/* 8014A4E8 00147448  38 00 00 01 */	li r0, 1
/* 8014A4EC 0014744C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8014A4F0 00147450  90 01 00 10 */	stw r0, 0x10(r1)
/* 8014A4F4 00147454  38 01 00 10 */	addi r0, r1, 0x10
/* 8014A4F8 00147458  90 61 00 14 */	stw r3, 0x14(r1)
/* 8014A4FC 0014745C  38 64 00 00 */	addi r3, r4, 0
/* 8014A500 00147460  7C 04 03 78 */	mr r4, r0
/* 8014A504 00147464  81 83 00 00 */	lwz r12, 0(r3)
/* 8014A508 00147468  81 8C 01 A4 */	lwz r12, 0x1a4(r12)
/* 8014A50C 0014746C  7D 88 03 A6 */	mtlr r12
/* 8014A510 00147470  4E 80 00 21 */	blrl 
/* 8014A514 00147474  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8014A518 00147478  38 21 00 18 */	addi r1, r1, 0x18
/* 8014A51C 0014747C  7C 08 03 A6 */	mtlr r0
/* 8014A520 00147480  4E 80 00 20 */	blr 

.global actTeki__15InteractSwallowFP4Teki
actTeki__15InteractSwallowFP4Teki:
/* 8014A524 00147484  38 60 00 01 */	li r3, 1
/* 8014A528 00147488  4E 80 00 20 */	blr 

.global actTeki__13InteractPressFP4Teki
actTeki__13InteractPressFP4Teki:
/* 8014A52C 0014748C  7C 08 02 A6 */	mflr r0
/* 8014A530 00147490  90 01 00 04 */	stw r0, 4(r1)
/* 8014A534 00147494  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8014A538 00147498  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8014A53C 0014749C  7C 9F 23 78 */	mr r31, r4
/* 8014A540 001474A0  38 BF 00 00 */	addi r5, r31, 0
/* 8014A544 001474A4  80 C3 00 04 */	lwz r6, 4(r3)
/* 8014A548 001474A8  38 61 00 10 */	addi r3, r1, 0x10
/* 8014A54C 001474AC  38 80 00 03 */	li r4, 3
/* 8014A550 001474B0  4B FF FE 7D */	bl __ct__9TekiEventFiP4TekiP8Creature
/* 8014A554 001474B4  81 9F 00 00 */	lwz r12, 0(r31)
/* 8014A558 001474B8  38 83 00 00 */	addi r4, r3, 0
/* 8014A55C 001474BC  38 7F 00 00 */	addi r3, r31, 0
/* 8014A560 001474C0  81 8C 01 A0 */	lwz r12, 0x1a0(r12)
/* 8014A564 001474C4  7D 88 03 A6 */	mtlr r12
/* 8014A568 001474C8  4E 80 00 21 */	blrl 
/* 8014A56C 001474CC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8014A570 001474D0  38 60 00 01 */	li r3, 1
/* 8014A574 001474D4  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8014A578 001474D8  38 21 00 28 */	addi r1, r1, 0x28
/* 8014A57C 001474DC  7C 08 03 A6 */	mtlr r0
/* 8014A580 001474E0  4E 80 00 20 */	blr 

.global actTeki__13InteractFlickFP4Teki
actTeki__13InteractFlickFP4Teki:
/* 8014A584 001474E4  38 60 00 01 */	li r3, 1
/* 8014A588 001474E8  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802CD928:
	.asciz "tekiinteraction.cpp"
.balign 4
lbl_802CD93C:
	.asciz "tekiinteraction"
.balign 4
lbl_802CD94C:
	.asciz "InteractHitEffect"
.balign 4
lbl_802CD960:
	.asciz "Interaction"
.balign 4
lbl_802CD96C:
	.4byte __RTTI__11Interaction
	.4byte 0
	.4byte 0
.global __vt__17InteractHitEffect
__vt__17InteractHitEffect:
	.4byte __RTTI__17InteractHitEffect
	.4byte 0
	.4byte actCommon__11InteractionFP8Creature
	.4byte actPiki__11InteractionFP4Piki
	.4byte actTeki__17InteractHitEffectFP4Teki
	.4byte actNavi__11InteractionFP4Navi
	.4byte actBoss__17InteractHitEffectFP4Boss
	.4byte actPellet__11InteractionFP6Pellet
	.4byte actHinderRock__11InteractionFP10HinderRock
	.4byte actBridge__11InteractionFP6Bridge
	.4byte actItem__11InteractionFP12ItemCreature
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
lbl_802CD9D0:
	.asciz "InteractBomb"
.balign 4
lbl_802CD9E0:
	.4byte __RTTI__11Interaction
	.4byte 0
	.4byte 0
.global __vt__12InteractBomb
__vt__12InteractBomb:
	.4byte __RTTI__12InteractBomb
	.4byte 0
	.4byte actCommon__11InteractionFP8Creature
	.4byte actPiki__12InteractBombFP4Piki
	.4byte actTeki__12InteractBombFP4Teki
	.4byte actNavi__12InteractBombFP4Navi
	.4byte actBoss__12InteractBombFP4Boss
	.4byte actPellet__11InteractionFP6Pellet
	.4byte actHinderRock__11InteractionFP10HinderRock
	.4byte actBridge__11InteractionFP6Bridge
	.4byte actItem__12InteractBombFP12ItemCreature

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__11Interaction:
	.4byte lbl_802CD960
	.4byte 0
__RTTI__17InteractHitEffect:
	.4byte lbl_802CD94C
	.4byte lbl_802CD96C
__RTTI__12InteractBomb:
	.4byte lbl_802CD9D0
	.4byte lbl_802CD9E0
