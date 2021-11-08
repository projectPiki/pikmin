.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800BB4D0 000B8430  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BB4D4 000B8434  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BB4D8 000B8438  41 82 00 2C */	beq lbl_800BB504
/* 800BB4DC 000B843C  3C 60 80 2B */	lis r3, __vt__7ActGoto@ha
/* 800BB4E0 000B8440  38 03 6B B4 */	addi r0, r3, __vt__7ActGoto@l
/* 800BB4E4 000B8444  90 1E 00 00 */	stw r0, 0(r30)
/* 800BB4E8 000B8448  38 7E 00 00 */	addi r3, r30, 0
/* 800BB4EC 000B844C  38 80 00 00 */	li r4, 0
/* 800BB4F0 000B8450  48 00 89 19 */	bl __dt__6ActionFv
/* 800BB4F4 000B8454  7F E0 07 35 */	extsh. r0, r31
/* 800BB4F8 000B8458  40 81 00 0C */	ble lbl_800BB504
/* 800BB4FC 000B845C  7F C3 F3 78 */	mr r3, r30
/* 800BB500 000B8460  4B F8 BC AD */	bl __dl__FPv
lbl_800BB504:
/* 800BB504 000B8464  7F C3 F3 78 */	mr r3, r30
/* 800BB508 000B8468  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BB50C 000B846C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BB510 000B8470  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BB514 000B8474  38 21 00 18 */	addi r1, r1, 0x18
/* 800BB518 000B8478  7C 08 03 A6 */	mtlr r0
/* 800BB51C 000B847C  4E 80 00 20 */	blr 

.global defaultInitialiser__7ActGotoFv
defaultInitialiser__7ActGotoFv:
/* 800BB520 000B8480  C0 02 93 44 */	lfs f0, lbl_803E9544@sda21(r2)
/* 800BB524 000B8484  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 800BB528 000B8488  C0 02 93 5C */	lfs f0, lbl_803E955C@sda21(r2)
/* 800BB52C 000B848C  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 800BB530 000B8490  4E 80 00 20 */	blr 

.global __ct__8ActGuardFP4Piki
__ct__8ActGuardFP4Piki:
/* 800BB534 000B8494  7C 08 02 A6 */	mflr r0
/* 800BB538 000B8498  38 A0 00 01 */	li r5, 1
/* 800BB53C 000B849C  90 01 00 04 */	stw r0, 4(r1)
/* 800BB540 000B84A0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BB544 000B84A4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BB548 000B84A8  3B E3 00 00 */	addi r31, r3, 0
/* 800BB54C 000B84AC  48 00 88 85 */	bl __ct__6ActionFP4Pikib
/* 800BB550 000B84B0  3C 60 80 2B */	lis r3, __vt__8ActGuard@ha
/* 800BB554 000B84B4  38 03 6C D0 */	addi r0, r3, __vt__8ActGuard@l
/* 800BB558 000B84B8  90 1F 00 00 */	stw r0, 0(r31)
/* 800BB55C 000B84BC  38 00 00 00 */	li r0, 0
/* 800BB560 000B84C0  38 7F 00 00 */	addi r3, r31, 0
/* 800BB564 000B84C4  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800BB568 000B84C8  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800BB56C 000B84CC  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 800BB570 000B84D0  C0 02 93 60 */	lfs f0, lbl_803E9560@sda21(r2)
/* 800BB574 000B84D4  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 800BB578 000B84D8  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 800BB57C 000B84DC  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 800BB580 000B84E0  D0 1F 00 38 */	stfs f0, 0x38(r31)
/* 800BB584 000B84E4  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 800BB588 000B84E8  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 800BB58C 000B84EC  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800BB590 000B84F0  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800BB594 000B84F4  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 800BB598 000B84F8  98 1F 00 49 */	stb r0, 0x49(r31)
/* 800BB59C 000B84FC  C0 02 93 64 */	lfs f0, lbl_803E9564@sda21(r2)
/* 800BB5A0 000B8500  D0 1F 00 3C */	stfs f0, 0x3c(r31)
/* 800BB5A4 000B8504  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BB5A8 000B8508  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BB5AC 000B850C  38 21 00 18 */	addi r1, r1, 0x18
/* 800BB5B0 000B8510  7C 08 03 A6 */	mtlr r0
/* 800BB5B4 000B8514  4E 80 00 20 */	blr 

.global init__8ActGuardFP8Creature
init__8ActGuardFP8Creature:
/* 800BB5B8 000B8518  7C 08 02 A6 */	mflr r0
/* 800BB5BC 000B851C  90 01 00 04 */	stw r0, 4(r1)
/* 800BB5C0 000B8520  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800BB5C4 000B8524  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800BB5C8 000B8528  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800BB5CC 000B852C  3B C0 00 00 */	li r30, 0
/* 800BB5D0 000B8530  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800BB5D4 000B8534  3B A3 00 00 */	addi r29, r3, 0
/* 800BB5D8 000B8538  93 C3 00 14 */	stw r30, 0x14(r3)
/* 800BB5DC 000B853C  93 DD 00 18 */	stw r30, 0x18(r29)
/* 800BB5E0 000B8540  93 DD 00 1C */	stw r30, 0x1c(r29)
/* 800BB5E4 000B8544  48 00 08 DD */	bl findFriend__8ActGuardFv
/* 800BB5E8 000B8548  7C 7F 1B 79 */	or. r31, r3, r3
/* 800BB5EC 000B854C  41 82 00 30 */	beq lbl_800BB61C
/* 800BB5F0 000B8550  80 7D 00 14 */	lwz r3, 0x14(r29)
/* 800BB5F4 000B8554  28 03 00 00 */	cmplwi r3, 0
/* 800BB5F8 000B8558  41 82 00 10 */	beq lbl_800BB608
/* 800BB5FC 000B855C  41 82 00 0C */	beq lbl_800BB608
/* 800BB600 000B8560  48 02 8D 6D */	bl subCnt__12RefCountableFv
/* 800BB604 000B8564  93 DD 00 14 */	stw r30, 0x14(r29)
lbl_800BB608:
/* 800BB608 000B8568  93 FD 00 14 */	stw r31, 0x14(r29)
/* 800BB60C 000B856C  80 7D 00 14 */	lwz r3, 0x14(r29)
/* 800BB610 000B8570  28 03 00 00 */	cmplwi r3, 0
/* 800BB614 000B8574  41 82 00 08 */	beq lbl_800BB61C
/* 800BB618 000B8578  48 02 8D 45 */	bl addCnt__12RefCountableFv
lbl_800BB61C:
/* 800BB61C 000B857C  C0 02 93 68 */	lfs f0, lbl_803E9568@sda21(r2)
/* 800BB620 000B8580  38 A0 00 00 */	li r5, 0
/* 800BB624 000B8584  38 00 00 01 */	li r0, 1
/* 800BB628 000B8588  D0 1D 00 40 */	stfs f0, 0x40(r29)

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 801D1600 001CE560  48 01 80 55 */	bl __ct__11YaiStrategyFii
/* 801D1604 001CE564  3C 60 80 2E */	lis r3, __vt__17TAIdororoStrategy@ha
/* 801D1608 001CE568  38 03 3F F4 */	addi r0, r3, __vt__17TAIdororoStrategy@l
/* 801D160C 001CE56C  90 1F 00 00 */	stw r0, 0(r31)
/* 801D1610 001CE570  38 60 00 08 */	li r3, 8
/* 801D1614 001CE574  4B E7 59 F1 */	bl alloc__6SystemFUl
/* 801D1618 001CE578  3B 83 00 00 */	addi r28, r3, 0
/* 801D161C 001CE57C  7F 80 E3 79 */	or. r0, r28, r28
/* 801D1620 001CE580  41 82 00 24 */	beq lbl_801D1644
/* 801D1624 001CE584  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801D1628 001CE588  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801D162C 001CE58C  90 1C 00 04 */	stw r0, 4(r28)
/* 801D1630 001CE590  38 00 00 02 */	li r0, 2
/* 801D1634 001CE594  3C 60 80 2E */	lis r3, __vt__14TAIAinitDororo@ha
/* 801D1638 001CE598  90 1C 00 00 */	stw r0, 0(r28)
/* 801D163C 001CE59C  38 03 45 38 */	addi r0, r3, __vt__14TAIAinitDororo@l
/* 801D1640 001CE5A0  90 1C 00 04 */	stw r0, 4(r28)
lbl_801D1644:
/* 801D1644 001CE5A4  38 60 00 08 */	li r3, 8
/* 801D1648 001CE5A8  4B E7 59 BD */	bl alloc__6SystemFUl
/* 801D164C 001CE5AC  3A 83 00 00 */	addi r20, r3, 0
/* 801D1650 001CE5B0  7E 80 A3 79 */	or. r0, r20, r20
/* 801D1654 001CE5B4  41 82 00 24 */	beq lbl_801D1678
/* 801D1658 001CE5B8  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801D165C 001CE5BC  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801D1660 001CE5C0  90 14 00 04 */	stw r0, 4(r20)
/* 801D1664 001CE5C4  38 00 00 00 */	li r0, 0
/* 801D1668 001CE5C8  3C 60 80 2E */	lis r3, __vt__13TAIAdeadCheck@ha
/* 801D166C 001CE5CC  90 14 00 00 */	stw r0, 0(r20)
/* 801D1670 001CE5D0  38 03 F3 4C */	addi r0, r3, __vt__13TAIAdeadCheck@l
/* 801D1674 001CE5D4  90 14 00 04 */	stw r0, 4(r20)
lbl_801D1678:
/* 801D1678 001CE5D8  38 60 00 0C */	li r3, 0xc
/* 801D167C 001CE5DC  4B E7 59 89 */	bl alloc__6SystemFUl
/* 801D1680 001CE5E0  90 61 00 7C */	stw r3, 0x7c(r1)
/* 801D1684 001CE5E4  80 61 00 7C */	lwz r3, 0x7c(r1)
/* 801D1688 001CE5E8  28 03 00 00 */	cmplwi r3, 0
/* 801D168C 001CE5EC  41 82 00 30 */	beq lbl_801D16BC
/* 801D1690 001CE5F0  38 80 FF FF */	li r4, -1
/* 801D1694 001CE5F4  38 A0 00 00 */	li r5, 0
/* 801D1698 001CE5F8  4B FD B5 BD */	bl __ct__10TAIAmotionFii
/* 801D169C 001CE5FC  3C 60 80 2E */	lis r3, __vt__9TAIAdying@ha
/* 801D16A0 001CE600  38 03 F2 EC */	addi r0, r3, __vt__9TAIAdying@l
/* 801D16A4 001CE604  80 61 00 7C */	lwz r3, 0x7c(r1)
/* 801D16A8 001CE608  3C 80 80 2E */	lis r4, __vt__15TAIAdyingDororo@ha
/* 801D16AC 001CE60C  90 03 00 04 */	stw r0, 4(r3)
/* 801D16B0 001CE610  38 04 45 00 */	addi r0, r4, __vt__15TAIAdyingDororo@l
/* 801D16B4 001CE614  80 61 00 7C */	lwz r3, 0x7c(r1)
/* 801D16B8 001CE618  90 03 00 04 */	stw r0, 4(r3)
lbl_801D16BC:
/* 801D16BC 001CE61C  38 60 00 0C */	li r3, 0xc
/* 801D16C0 001CE620  4B E7 59 45 */	bl alloc__6SystemFUl
/* 801D16C4 001CE624  3B 43 00 00 */	addi r26, r3, 0
/* 801D16C8 001CE628  7F 40 D3 79 */	or. r0, r26, r26
/* 801D16CC 001CE62C  41 82 00 2C */	beq lbl_801D16F8
/* 801D16D0 001CE630  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801D16D4 001CE634  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801D16D8 001CE638  90 1A 00 04 */	stw r0, 4(r26)
/* 801D16DC 001CE63C  38 00 FF FF */	li r0, -1
/* 801D16E0 001CE640  3C 60 80 2E */	lis r3, __vt__10TAIAdamage@ha
/* 801D16E4 001CE644  90 1A 00 00 */	stw r0, 0(r26)
/* 801D16E8 001CE648  38 63 F1 F0 */	addi r3, r3, __vt__10TAIAdamage@l
/* 801D16EC 001CE64C  38 00 00 01 */	li r0, 1
/* 801D16F0 001CE650  90 7A 00 04 */	stw r3, 4(r26)
/* 801D16F4 001CE654  98 1A 00 08 */	stb r0, 8(r26)
lbl_801D16F8:
/* 801D16F8 001CE658  38 60 00 08 */	li r3, 8
/* 801D16FC 001CE65C  4B E7 59 09 */	bl alloc__6SystemFUl
/* 801D1700 001CE660  3A A3 00 00 */	addi r21, r3, 0
/* 801D1704 001CE664  7E A0 AB 79 */	or. r0, r21, r21
/* 801D1708 001CE668  41 82 00 24 */	beq lbl_801D172C
/* 801D170C 001CE66C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801D1710 001CE670  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801D1714 001CE674  90 15 00 04 */	stw r0, 4(r21)
/* 801D1718 001CE678  38 00 FF FF */	li r0, -1
/* 801D171C 001CE67C  3C 60 80 2E */	lis r3, __vt__8TAIAstop@ha
/* 801D1720 001CE680  90 15 00 00 */	stw r0, 0(r21)
/* 801D1724 001CE684  38 03 F9 14 */	addi r0, r3, __vt__8TAIAstop@l
/* 801D1728 001CE688  90 15 00 04 */	stw r0, 4(r21)
lbl_801D172C:
/* 801D172C 001CE68C  38 60 00 08 */	li r3, 8
/* 801D1730 001CE690  4B E7 58 D5 */	bl alloc__6SystemFUl
/* 801D1734 001CE694  3B 63 00 00 */	addi r27, r3, 0
/* 801D1738 001CE698  7F 60 DB 79 */	or. r0, r27, r27
/* 801D173C 001CE69C  41 82 00 24 */	beq lbl_801D1760
/* 801D1740 001CE6A0  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801D1744 001CE6A4  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801D1748 001CE6A8  90 1B 00 04 */	stw r0, 4(r27)
/* 801D174C 001CE6AC  38 00 00 08 */	li r0, 8
/* 801D1750 001CE6B0  3C 60 80 2E */	lis r3, __vt__17TAIAkillTouchPiki@ha
/* 801D1754 001CE6B4  90 1B 00 00 */	stw r0, 0(r27)
/* 801D1758 001CE6B8  38 03 44 98 */	addi r0, r3, __vt__17TAIAkillTouchPiki@l

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x696e7465
	.4byte 0x72616374
	.4byte 0x47726162
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x696e7465
	.4byte 0x72616374
	.4byte 0x47726162
	.4byte 0
	.4byte 0x496e7465
	.4byte 0x72616374
	.4byte 0x52656c65
	.4byte 0x61736500
	.4byte 0x496e7465
	.4byte 0x72616374
	.4byte 0x696f6e00
	.4byte 0x803de9dc
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
	.4byte 0x496e7465
	.4byte 0x72616374
	.4byte 0x47726162
	.4byte 0
	.4byte 0x803de9dc
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
.global __RTTI__19InteractChangeColor
__RTTI__19InteractChangeColor:
	.4byte 0x802ad05c
	.4byte 0x802ad070
.global __RTTI__17InteractThrowAway
__RTTI__17InteractThrowAway:
	.4byte 0x802ad0a8
	.4byte 0x802ad0bc
.global __RTTI__12InteractBury
__RTTI__12InteractBury:
	.4byte 0x802ad0f4
	.4byte 0x802ad104
.global lbl_803DE9C8
lbl_803DE9C8:
	.4byte 0x00000000
.global lbl_803DE9CC
lbl_803DE9CC:
	.4byte 0x00000000
.global lbl_803DE9D0
lbl_803DE9D0:
	.4byte 0x00000000
.global lbl_803DE9D4
lbl_803DE9D4:
	.4byte 0x41000000
.global lbl_803DE9D8
lbl_803DE9D8:
	.4byte 0x00000000
	.4byte 0x802AD174

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EA164
lbl_803EA164:
	.4byte 0x3E99999A
.global lbl_803EA168
lbl_803EA168:
	.4byte 0x43C80000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EB83C
lbl_803EB83C:
	.4byte 0x3F800000
.global lbl_803EB840
lbl_803EB840:
	.4byte 0x46FFFE00
