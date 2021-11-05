.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800BB62C 000B858C  38 61 00 10 */	addi r3, r1, 0x10
/* 800BB630 000B8590  38 80 00 03 */	li r4, 3
/* 800BB634 000B8594  98 BD 00 48 */	stb r5, 0x48(r29)
/* 800BB638 000B8598  98 1D 00 49 */	stb r0, 0x49(r29)
/* 800BB63C 000B859C  48 06 39 1D */	bl __ct__14PaniMotionInfoFi
/* 800BB640 000B85A0  3B E3 00 00 */	addi r31, r3, 0
/* 800BB644 000B85A4  38 61 00 18 */	addi r3, r1, 0x18
/* 800BB648 000B85A8  38 80 00 03 */	li r4, 3
/* 800BB64C 000B85AC  48 06 39 0D */	bl __ct__14PaniMotionInfoFi
/* 800BB650 000B85B0  7C 64 1B 78 */	mr r4, r3
/* 800BB654 000B85B4  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800BB658 000B85B8  7F E5 FB 78 */	mr r5, r31
/* 800BB65C 000B85BC  48 00 F3 7D */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800BB660 000B85C0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800BB664 000B85C4  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800BB668 000B85C8  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800BB66C 000B85CC  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800BB670 000B85D0  38 21 00 30 */	addi r1, r1, 0x30
/* 800BB674 000B85D4  7C 08 03 A6 */	mtlr r0
/* 800BB678 000B85D8  4E 80 00 20 */	blr 

.global cleanup__8ActGuardFv
cleanup__8ActGuardFv:
/* 800BB67C 000B85DC  7C 08 02 A6 */	mflr r0
/* 800BB680 000B85E0  90 01 00 04 */	stw r0, 4(r1)
/* 800BB684 000B85E4  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800BB688 000B85E8  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 800BB68C 000B85EC  7C 7F 1B 78 */	mr r31, r3
/* 800BB690 000B85F0  93 C1 00 38 */	stw r30, 0x38(r1)
/* 800BB694 000B85F4  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800BB698 000B85F8  28 03 00 00 */	cmplwi r3, 0
/* 800BB69C 000B85FC  41 82 00 10 */	beq lbl_800BB6AC
/* 800BB6A0 000B8600  48 02 8C CD */	bl subCnt__12RefCountableFv
/* 800BB6A4 000B8604  38 00 00 00 */	li r0, 0
/* 800BB6A8 000B8608  90 1F 00 14 */	stw r0, 0x14(r31)
lbl_800BB6AC:
/* 800BB6AC 000B860C  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 800BB6B0 000B8610  28 03 00 00 */	cmplwi r3, 0
/* 800BB6B4 000B8614  41 82 00 5C */	beq lbl_800BB710
/* 800BB6B8 000B8618  80 63 04 F8 */	lwz r3, 0x4f8(r3)
/* 800BB6BC 000B861C  A8 03 00 08 */	lha r0, 8(r3)
/* 800BB6C0 000B8620  2C 00 FF FF */	cmpwi r0, -1
/* 800BB6C4 000B8624  40 82 00 0C */	bne lbl_800BB6D0
/* 800BB6C8 000B8628  38 60 00 00 */	li r3, 0
/* 800BB6CC 000B862C  48 00 00 10 */	b lbl_800BB6DC
lbl_800BB6D0:
/* 800BB6D0 000B8630  80 63 00 04 */	lwz r3, 4(r3)
/* 800BB6D4 000B8634  54 00 18 38 */	slwi r0, r0, 3
/* 800BB6D8 000B8638  7C 63 00 2E */	lwzx r3, r3, r0
lbl_800BB6DC:
/* 800BB6DC 000B863C  3B C3 00 18 */	addi r30, r3, 0x18
/* 800BB6E0 000B8640  80 63 00 18 */	lwz r3, 0x18(r3)
/* 800BB6E4 000B8644  28 03 00 00 */	cmplwi r3, 0
/* 800BB6E8 000B8648  41 82 00 10 */	beq lbl_800BB6F8
/* 800BB6EC 000B864C  48 02 8C 81 */	bl subCnt__12RefCountableFv
/* 800BB6F0 000B8650  38 00 00 00 */	li r0, 0
/* 800BB6F4 000B8654  90 1E 00 00 */	stw r0, 0(r30)
lbl_800BB6F8:
/* 800BB6F8 000B8658  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 800BB6FC 000B865C  28 03 00 00 */	cmplwi r3, 0
/* 800BB700 000B8660  41 82 00 10 */	beq lbl_800BB710
/* 800BB704 000B8664  48 02 8C 69 */	bl subCnt__12RefCountableFv
/* 800BB708 000B8668  38 00 00 00 */	li r0, 0
/* 800BB70C 000B866C  90 1F 00 1C */	stw r0, 0x1c(r31)
lbl_800BB710:
/* 800BB710 000B8670  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800BB714 000B8674  28 03 00 00 */	cmplwi r3, 0
/* 800BB718 000B8678  41 82 00 5C */	beq lbl_800BB774
/* 800BB71C 000B867C  80 63 04 F8 */	lwz r3, 0x4f8(r3)
/* 800BB720 000B8680  A8 03 00 08 */	lha r0, 8(r3)
/* 800BB724 000B8684  2C 00 FF FF */	cmpwi r0, -1
/* 800BB728 000B8688  40 82 00 0C */	bne lbl_800BB734
/* 800BB72C 000B868C  38 60 00 00 */	li r3, 0
/* 800BB730 000B8690  48 00 00 10 */	b lbl_800BB740
lbl_800BB734:
/* 800BB734 000B8694  80 63 00 04 */	lwz r3, 4(r3)
/* 800BB738 000B8698  54 00 18 38 */	slwi r0, r0, 3
/* 800BB73C 000B869C  7C 63 00 2E */	lwzx r3, r3, r0
lbl_800BB740:
/* 800BB740 000B86A0  3B C3 00 1C */	addi r30, r3, 0x1c
/* 800BB744 000B86A4  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 800BB748 000B86A8  28 03 00 00 */	cmplwi r3, 0
/* 800BB74C 000B86AC  41 82 00 10 */	beq lbl_800BB75C
/* 800BB750 000B86B0  48 02 8C 1D */	bl subCnt__12RefCountableFv
/* 800BB754 000B86B4  38 00 00 00 */	li r0, 0
/* 800BB758 000B86B8  90 1E 00 00 */	stw r0, 0(r30)
lbl_800BB75C:
/* 800BB75C 000B86BC  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800BB760 000B86C0  28 03 00 00 */	cmplwi r3, 0
/* 800BB764 000B86C4  41 82 00 10 */	beq lbl_800BB774
/* 800BB768 000B86C8  48 02 8C 05 */	bl subCnt__12RefCountableFv

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 801D175C 001CE6BC  90 1B 00 04 */	stw r0, 4(r27)
lbl_801D1760:
/* 801D1760 001CE6C0  38 60 00 0C */	li r3, 0xc
/* 801D1764 001CE6C4  4B E7 58 A1 */	bl alloc__6SystemFUl
/* 801D1768 001CE6C8  3B 23 00 00 */	addi r25, r3, 0
/* 801D176C 001CE6CC  7F 23 CB 79 */	or. r3, r25, r25
/* 801D1770 001CE6D0  41 82 00 34 */	beq lbl_801D17A4
/* 801D1774 001CE6D4  38 80 00 09 */	li r4, 9
/* 801D1778 001CE6D8  38 A0 00 06 */	li r5, 6
/* 801D177C 001CE6DC  4B FD B5 65 */	bl __ct__17TAIAreserveMotionFii
/* 801D1780 001CE6E0  3C 60 80 2E */	lis r3, __vt__27TAIAgoTargetPriorityFaceDir@ha
/* 801D1784 001CE6E4  38 03 FA 18 */	addi r0, r3, __vt__27TAIAgoTargetPriorityFaceDir@l
/* 801D1788 001CE6E8  3C 60 80 2E */	lis r3, __vt__14TAIAgoGoalPath@ha
/* 801D178C 001CE6EC  90 19 00 04 */	stw r0, 4(r25)
/* 801D1790 001CE6F0  38 03 FB 38 */	addi r0, r3, __vt__14TAIAgoGoalPath@l
/* 801D1794 001CE6F4  3C 60 80 2E */	lis r3, __vt__20TAIAgoGoalPathDororo@ha
/* 801D1798 001CE6F8  90 19 00 04 */	stw r0, 4(r25)
/* 801D179C 001CE6FC  38 03 44 14 */	addi r0, r3, __vt__20TAIAgoGoalPathDororo@l
/* 801D17A0 001CE700  90 19 00 04 */	stw r0, 4(r25)
lbl_801D17A4:
/* 801D17A4 001CE704  38 60 00 0C */	li r3, 0xc
/* 801D17A8 001CE708  4B E7 58 5D */	bl alloc__6SystemFUl
/* 801D17AC 001CE70C  3A 63 00 00 */	addi r19, r3, 0
/* 801D17B0 001CE710  7E 60 9B 79 */	or. r0, r19, r19
/* 801D17B4 001CE714  41 82 00 2C */	beq lbl_801D17E0
/* 801D17B8 001CE718  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801D17BC 001CE71C  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801D17C0 001CE720  90 13 00 04 */	stw r0, 4(r19)
/* 801D17C4 001CE724  38 00 00 04 */	li r0, 4
/* 801D17C8 001CE728  3C 60 80 2E */	lis r3, __vt__14TAIAflickCheck@ha
/* 801D17CC 001CE72C  90 13 00 00 */	stw r0, 0(r19)
/* 801D17D0 001CE730  38 63 03 CC */	addi r3, r3, __vt__14TAIAflickCheck@l
/* 801D17D4 001CE734  38 00 FF FF */	li r0, -1
/* 801D17D8 001CE738  90 73 00 04 */	stw r3, 4(r19)
/* 801D17DC 001CE73C  90 13 00 08 */	stw r0, 8(r19)
lbl_801D17E0:
/* 801D17E0 001CE740  38 60 00 0C */	li r3, 0xc
/* 801D17E4 001CE744  4B E7 58 21 */	bl alloc__6SystemFUl
/* 801D17E8 001CE748  90 61 00 78 */	stw r3, 0x78(r1)
/* 801D17EC 001CE74C  80 61 00 78 */	lwz r3, 0x78(r1)
/* 801D17F0 001CE750  28 03 00 00 */	cmplwi r3, 0
/* 801D17F4 001CE754  41 82 00 30 */	beq lbl_801D1824
/* 801D17F8 001CE758  38 80 FF FE */	li r4, -2
/* 801D17FC 001CE75C  38 A0 00 09 */	li r5, 9
/* 801D1800 001CE760  4B FD B4 55 */	bl __ct__10TAIAmotionFii
/* 801D1804 001CE764  3C 60 80 2E */	lis r3, __vt__12TAIAflicking@ha
/* 801D1808 001CE768  38 03 03 4C */	addi r0, r3, __vt__12TAIAflicking@l
/* 801D180C 001CE76C  80 61 00 78 */	lwz r3, 0x78(r1)
/* 801D1810 001CE770  3C 80 80 2E */	lis r4, __vt__18TAIAflickingDororo@ha
/* 801D1814 001CE774  90 03 00 04 */	stw r0, 4(r3)
/* 801D1818 001CE778  38 04 43 88 */	addi r0, r4, __vt__18TAIAflickingDororo@l
/* 801D181C 001CE77C  80 61 00 78 */	lwz r3, 0x78(r1)
/* 801D1820 001CE780  90 03 00 04 */	stw r0, 4(r3)
lbl_801D1824:
/* 801D1824 001CE784  38 60 00 10 */	li r3, 0x10
/* 801D1828 001CE788  4B E7 57 DD */	bl alloc__6SystemFUl
/* 801D182C 001CE78C  3A 43 00 00 */	addi r18, r3, 0
/* 801D1830 001CE790  7E 43 93 79 */	or. r3, r18, r18
/* 801D1834 001CE794  41 82 00 30 */	beq lbl_801D1864
/* 801D1838 001CE798  38 80 00 06 */	li r4, 6
/* 801D183C 001CE79C  38 A0 00 02 */	li r5, 2
/* 801D1840 001CE7A0  4B FD B4 A1 */	bl __ct__17TAIAreserveMotionFii
/* 801D1844 001CE7A4  3C 60 80 2E */	lis r3, __vt__8TAIAwait@ha
/* 801D1848 001CE7A8  38 03 F8 2C */	addi r0, r3, __vt__8TAIAwait@l
/* 801D184C 001CE7AC  90 12 00 04 */	stw r0, 4(r18)
/* 801D1850 001CE7B0  3C 60 80 2E */	lis r3, __vt__14TAIAwaitDororo@ha
/* 801D1854 001CE7B4  38 03 42 FC */	addi r0, r3, __vt__14TAIAwaitDororo@l
/* 801D1858 001CE7B8  C0 02 BC A0 */	lfs f0, lbl_803EBEA0@sda21(r2)
/* 801D185C 001CE7BC  D0 12 00 0C */	stfs f0, 0xc(r18)
/* 801D1860 001CE7C0  90 12 00 04 */	stw r0, 4(r18)
lbl_801D1864:
/* 801D1864 001CE7C4  38 60 00 08 */	li r3, 8
/* 801D1868 001CE7C8  4B E7 57 9D */	bl alloc__6SystemFUl
/* 801D186C 001CE7CC  3A 03 00 00 */	addi r16, r3, 0
/* 801D1870 001CE7D0  7E 00 83 79 */	or. r0, r16, r16
/* 801D1874 001CE7D4  41 82 00 24 */	beq lbl_801D1898
/* 801D1878 001CE7D8  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801D187C 001CE7DC  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801D1880 001CE7E0  90 10 00 04 */	stw r0, 4(r16)
/* 801D1884 001CE7E4  38 00 00 07 */	li r0, 7
/* 801D1888 001CE7E8  3C 60 80 2E */	lis r3, __vt__15TAIAvisiblePiki@ha
/* 801D188C 001CE7EC  90 10 00 00 */	stw r0, 0(r16)
/* 801D1890 001CE7F0  38 03 FE DC */	addi r0, r3, __vt__15TAIAvisiblePiki@l
/* 801D1894 001CE7F4  90 10 00 04 */	stw r0, 4(r16)
lbl_801D1898:
/* 801D1898 001CE7F8  38 60 00 08 */	li r3, 8

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x696e7465
  .4byte 0x72616374
  .4byte 0x4574632e
  .4byte 0x63707000
  .4byte 0x696e7465
  .4byte 0x72616374
  .4byte 0x45746300
  .4byte 0x496e7465
  .4byte 0x72616374
  .4byte 0x5761726e
  .4byte 0
  .4byte 0x496e7465
  .4byte 0x72616374
  .4byte 0x696f6e00
  .4byte 0x803de9f8
  .4byte 0
  .4byte 0
.global __vt__12InteractWarn
__vt__12InteractWarn:
  .4byte __RTTI__12InteractWarn
  .4byte 0
  .4byte actCommon__11InteractionFP8Creature
  .4byte actPiki__12InteractWarnFP4Piki
  .4byte actTeki__11InteractionFP4Teki
  .4byte actNavi__11InteractionFP4Navi
  .4byte actBoss__11InteractionFP4Boss
  .4byte actPellet__11InteractionFP6Pellet
  .4byte actHinderRock__11InteractionFP10HinderRock
  .4byte actBridge__11InteractionFP6Bridge
  .4byte actItem__11InteractionFP12ItemCreature
  .4byte 0x496e7465
  .4byte 0x72616374
  .4byte 0x54616c6b
  .4byte 0
  .4byte 0x803de9f8
  .4byte 0
  .4byte 0
.global __vt__12InteractTalk
__vt__12InteractTalk:
  .4byte __RTTI__12InteractTalk
  .4byte 0
  .4byte actCommon__11InteractionFP8Creature
  .4byte actPiki__12InteractTalkFP4Piki
  .4byte actTeki__11InteractionFP4Teki
  .4byte actNavi__11InteractionFP4Navi
  .4byte actBoss__11InteractionFP4Boss
  .4byte actPellet__11InteractionFP6Pellet
  .4byte actHinderRock__11InteractionFP10HinderRock
  .4byte actBridge__11InteractionFP6Bridge
  .4byte actItem__11InteractionFP12ItemCreature

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x00000000
.global __RTTI__15InteractRelease
__RTTI__15InteractRelease:
  .4byte 0x802ad164
  .4byte 0x802ad180
.global __RTTI__12InteractGrab
__RTTI__12InteractGrab:
  .4byte 0x802ad1b8
  .4byte 0x802ad1c8
  .4byte 0
