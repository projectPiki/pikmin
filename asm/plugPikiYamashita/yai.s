.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__11YaiStrategyFii
__ct__11YaiStrategyFii:
/* 801E9654 001E65B4  7C 08 02 A6 */	mflr r0
/* 801E9658 001E65B8  90 01 00 04 */	stw r0, 4(r1)
/* 801E965C 001E65BC  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 801E9660 001E65C0  93 E1 00 24 */	stw r31, 0x24(r1)
/* 801E9664 001E65C4  3B E5 00 00 */	addi r31, r5, 0
/* 801E9668 001E65C8  93 C1 00 20 */	stw r30, 0x20(r1)
/* 801E966C 001E65CC  3B C4 00 00 */	addi r30, r4, 0
/* 801E9670 001E65D0  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 801E9674 001E65D4  3B A3 00 00 */	addi r29, r3, 0
/* 801E9678 001E65D8  4B F6 3B 2D */	bl __ct__12TekiStrategyFv
/* 801E967C 001E65DC  3C 60 80 2E */	lis r3, __vt__11YaiStrategy@ha
/* 801E9680 001E65E0  38 03 5A A8 */	addi r0, r3, __vt__11YaiStrategy@l
/* 801E9684 001E65E4  90 1D 00 00 */	stw r0, 0(r29)
/* 801E9688 001E65E8  38 7D 00 00 */	addi r3, r29, 0
/* 801E968C 001E65EC  38 9E 00 00 */	addi r4, r30, 0
/* 801E9690 001E65F0  38 BF 00 00 */	addi r5, r31, 0
/* 801E9694 001E65F4  48 00 00 25 */	bl init__11YaiStrategyFii
/* 801E9698 001E65F8  7F A3 EB 78 */	mr r3, r29
/* 801E969C 001E65FC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 801E96A0 001E6600  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 801E96A4 001E6604  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 801E96A8 001E6608  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 801E96AC 001E660C  38 21 00 28 */	addi r1, r1, 0x28
/* 801E96B0 001E6610  7C 08 03 A6 */	mtlr r0
/* 801E96B4 001E6614  4E 80 00 20 */	blr 

.global init__11YaiStrategyFii
init__11YaiStrategyFii:
/* 801E96B8 001E6618  7C 08 02 A6 */	mflr r0
/* 801E96BC 001E661C  90 01 00 04 */	stw r0, 4(r1)
/* 801E96C0 001E6620  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801E96C4 001E6624  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801E96C8 001E6628  7C BF 2B 78 */	mr r31, r5
/* 801E96CC 001E662C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801E96D0 001E6630  7C 7E 1B 78 */	mr r30, r3
/* 801E96D4 001E6634  90 83 00 04 */	stw r4, 4(r3)
/* 801E96D8 001E6638  80 03 00 04 */	lwz r0, 4(r3)
/* 801E96DC 001E663C  54 03 10 3A */	slwi r3, r0, 2
/* 801E96E0 001E6640  4B E5 D9 25 */	bl alloc__6SystemFUl
/* 801E96E4 001E6644  90 7E 00 08 */	stw r3, 8(r30)
/* 801E96E8 001E6648  93 FE 00 0C */	stw r31, 0xc(r30)
/* 801E96EC 001E664C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801E96F0 001E6650  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801E96F4 001E6654  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801E96F8 001E6658  38 21 00 20 */	addi r1, r1, 0x20
/* 801E96FC 001E665C  7C 08 03 A6 */	mtlr r0
/* 801E9700 001E6660  4E 80 00 20 */	blr 

.global start__11YaiStrategyFR4Teki
start__11YaiStrategyFR4Teki:
/* 801E9704 001E6664  7C 08 02 A6 */	mflr r0
/* 801E9708 001E6668  90 01 00 04 */	stw r0, 4(r1)
/* 801E970C 001E666C  94 21 FF F8 */	stwu r1, -8(r1)
/* 801E9710 001E6670  80 03 00 0C */	lwz r0, 0xc(r3)
/* 801E9714 001E6674  90 04 03 24 */	stw r0, 0x324(r4)
/* 801E9718 001E6678  80 04 03 24 */	lwz r0, 0x324(r4)
/* 801E971C 001E667C  80 63 00 08 */	lwz r3, 8(r3)
/* 801E9720 001E6680  54 00 10 3A */	slwi r0, r0, 2
/* 801E9724 001E6684  7C 63 00 2E */	lwzx r3, r3, r0
/* 801E9728 001E6688  81 83 00 00 */	lwz r12, 0(r3)
/* 801E972C 001E668C  81 8C 00 08 */	lwz r12, 8(r12)
/* 801E9730 001E6690  7D 88 03 A6 */	mtlr r12
/* 801E9734 001E6694  4E 80 00 21 */	blrl 
/* 801E9738 001E6698  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801E973C 001E669C  38 21 00 08 */	addi r1, r1, 8
/* 801E9740 001E66A0  7C 08 03 A6 */	mtlr r0
/* 801E9744 001E66A4  4E 80 00 20 */	blr 

.global act__11YaiStrategyFR4Teki
act__11YaiStrategyFR4Teki:
/* 801E9748 001E66A8  7C 08 02 A6 */	mflr r0
/* 801E974C 001E66AC  90 01 00 04 */	stw r0, 4(r1)
/* 801E9750 001E66B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801E9754 001E66B4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801E9758 001E66B8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801E975C 001E66BC  3B C4 00 00 */	addi r30, r4, 0
/* 801E9760 001E66C0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801E9764 001E66C4  3B A3 00 00 */	addi r29, r3, 0
/* 801E9768 001E66C8  80 04 03 24 */	lwz r0, 0x324(r4)
/* 801E976C 001E66CC  80 63 00 08 */	lwz r3, 8(r3)
/* 801E9770 001E66D0  54 00 10 3A */	slwi r0, r0, 2
/* 801E9774 001E66D4  83 FE 03 24 */	lwz r31, 0x324(r30)
/* 801E9778 001E66D8  7C 63 00 2E */	lwzx r3, r3, r0
/* 801E977C 001E66DC  81 83 00 00 */	lwz r12, 0(r3)
/* 801E9780 001E66E0  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801E9784 001E66E4  7D 88 03 A6 */	mtlr r12
/* 801E9788 001E66E8  4E 80 00 21 */	blrl 
/* 801E978C 001E66EC  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801E9790 001E66F0  41 82 00 48 */	beq lbl_801E97D8
/* 801E9794 001E66F4  80 7D 00 08 */	lwz r3, 8(r29)
/* 801E9798 001E66F8  57 E0 10 3A */	slwi r0, r31, 2
/* 801E979C 001E66FC  38 9E 00 00 */	addi r4, r30, 0
/* 801E97A0 001E6700  7C 63 00 2E */	lwzx r3, r3, r0
/* 801E97A4 001E6704  81 83 00 00 */	lwz r12, 0(r3)
/* 801E97A8 001E6708  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801E97AC 001E670C  7D 88 03 A6 */	mtlr r12
/* 801E97B0 001E6710  4E 80 00 21 */	blrl 
/* 801E97B4 001E6714  80 1E 03 24 */	lwz r0, 0x324(r30)
/* 801E97B8 001E6718  7F C4 F3 78 */	mr r4, r30
/* 801E97BC 001E671C  80 7D 00 08 */	lwz r3, 8(r29)
/* 801E97C0 001E6720  54 00 10 3A */	slwi r0, r0, 2
/* 801E97C4 001E6724  7C 63 00 2E */	lwzx r3, r3, r0
/* 801E97C8 001E6728  81 83 00 00 */	lwz r12, 0(r3)
/* 801E97CC 001E672C  81 8C 00 08 */	lwz r12, 8(r12)
/* 801E97D0 001E6730  7D 88 03 A6 */	mtlr r12
/* 801E97D4 001E6734  4E 80 00 21 */	blrl 
lbl_801E97D8:
/* 801E97D8 001E6738  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801E97DC 001E673C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801E97E0 001E6740  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801E97E4 001E6744  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801E97E8 001E6748  38 21 00 20 */	addi r1, r1, 0x20
/* 801E97EC 001E674C  7C 08 03 A6 */	mtlr r0
/* 801E97F0 001E6750  4E 80 00 20 */	blr 

.global eventPerformed__11YaiStrategyFR9TekiEvent
eventPerformed__11YaiStrategyFR9TekiEvent:
/* 801E97F4 001E6754  7C 08 02 A6 */	mflr r0
/* 801E97F8 001E6758  90 01 00 04 */	stw r0, 4(r1)
/* 801E97FC 001E675C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801E9800 001E6760  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801E9804 001E6764  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801E9808 001E6768  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801E980C 001E676C  7C 7D 1B 78 */	mr r29, r3
/* 801E9810 001E6770  83 E4 00 04 */	lwz r31, 4(r4)
/* 801E9814 001E6774  80 63 00 08 */	lwz r3, 8(r3)
/* 801E9818 001E6778  80 1F 03 24 */	lwz r0, 0x324(r31)
/* 801E981C 001E677C  83 DF 03 24 */	lwz r30, 0x324(r31)
/* 801E9820 001E6780  54 00 10 3A */	slwi r0, r0, 2
/* 801E9824 001E6784  7C 63 00 2E */	lwzx r3, r3, r0
/* 801E9828 001E6788  81 83 00 00 */	lwz r12, 0(r3)
/* 801E982C 001E678C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 801E9830 001E6790  7D 88 03 A6 */	mtlr r12
/* 801E9834 001E6794  4E 80 00 21 */	blrl 
/* 801E9838 001E6798  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801E983C 001E679C  41 82 00 48 */	beq lbl_801E9884
/* 801E9840 001E67A0  80 7D 00 08 */	lwz r3, 8(r29)
/* 801E9844 001E67A4  57 C0 10 3A */	slwi r0, r30, 2
/* 801E9848 001E67A8  38 9F 00 00 */	addi r4, r31, 0
/* 801E984C 001E67AC  7C 63 00 2E */	lwzx r3, r3, r0
/* 801E9850 001E67B0  81 83 00 00 */	lwz r12, 0(r3)
/* 801E9854 001E67B4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801E9858 001E67B8  7D 88 03 A6 */	mtlr r12
/* 801E985C 001E67BC  4E 80 00 21 */	blrl 
/* 801E9860 001E67C0  80 1F 03 24 */	lwz r0, 0x324(r31)
/* 801E9864 001E67C4  7F E4 FB 78 */	mr r4, r31
/* 801E9868 001E67C8  80 7D 00 08 */	lwz r3, 8(r29)
/* 801E986C 001E67CC  54 00 10 3A */	slwi r0, r0, 2
/* 801E9870 001E67D0  7C 63 00 2E */	lwzx r3, r3, r0
/* 801E9874 001E67D4  81 83 00 00 */	lwz r12, 0(r3)
/* 801E9878 001E67D8  81 8C 00 08 */	lwz r12, 8(r12)
/* 801E987C 001E67DC  7D 88 03 A6 */	mtlr r12
/* 801E9880 001E67E0  4E 80 00 21 */	blrl 
lbl_801E9884:
/* 801E9884 001E67E4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801E9888 001E67E8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801E988C 001E67EC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801E9890 001E67F0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801E9894 001E67F4  38 21 00 20 */	addi r1, r1, 0x20
/* 801E9898 001E67F8  7C 08 03 A6 */	mtlr r0
/* 801E989C 001E67FC  4E 80 00 20 */	blr 

.global draw__11YaiStrategyFR4TekiR8Graphics
draw__11YaiStrategyFR4TekiR8Graphics:
/* 801E98A0 001E6800  7C 08 02 A6 */	mflr r0
/* 801E98A4 001E6804  90 01 00 04 */	stw r0, 4(r1)
/* 801E98A8 001E6808  94 21 FF F8 */	stwu r1, -8(r1)
/* 801E98AC 001E680C  4B F6 39 19 */	bl draw__12TekiStrategyFR4TekiR8Graphics
/* 801E98B0 001E6810  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801E98B4 001E6814  38 21 00 08 */	addi r1, r1, 8
/* 801E98B8 001E6818  7C 08 03 A6 */	mtlr r0
/* 801E98BC 001E681C  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 0x8
lbl_802E5A80:
	.asciz "YaiStrategy"
	.balign 4
lbl_802E5A8C:
	.asciz "TekiStrategy"
	.balign 4
lbl_802E5A9C:
	.4byte __RTTI__12TekiStrategy
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__11YaiStrategy
__vt__11YaiStrategy:
	.4byte __RTTI__11YaiStrategy
	.4byte 0
	.4byte start__11YaiStrategyFR4Teki
	.4byte act__11YaiStrategyFR4Teki
	.4byte eventPerformed__11YaiStrategyFR9TekiEvent
	.4byte createEffect__12TekiStrategyFR4Tekii
	.4byte draw__11YaiStrategyFR4TekiR8Graphics
	.4byte drawDebugInfo__12TekiStrategyFR4TekiR8Graphics
	.4byte interact__12TekiStrategyFR4TekiR18TekiInteractionKey
	.4byte spawnCorpseParts__12TekiStrategyFR4Teki

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 0x8
__RTTI__12TekiStrategy:
	.4byte lbl_802E5A8C
	.4byte 0x00000000
__RTTI__11YaiStrategy:
	.4byte lbl_802E5A80
	.4byte lbl_802E5A9C
