.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global init__19BufferedInputStreamFP6StreamPUci
init__19BufferedInputStreamFP6StreamPUci:
/* 80025500 00022460  7C 08 02 A6 */	mflr r0
/* 80025504 00022464  90 01 00 04 */	stw r0, 4(r1)
/* 80025508 00022468  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8002550C 0002246C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80025510 00022470  3B E6 00 00 */	addi r31, r6, 0
/* 80025514 00022474  93 C1 00 20 */	stw r30, 0x20(r1)
/* 80025518 00022478  3B C5 00 00 */	addi r30, r5, 0
/* 8002551C 0002247C  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 80025520 00022480  3B A4 00 00 */	addi r29, r4, 0
/* 80025524 00022484  93 81 00 18 */	stw r28, 0x18(r1)
/* 80025528 00022488  3B 83 00 00 */	addi r28, r3, 0
/* 8002552C 0002248C  80 64 00 00 */	lwz r3, 0(r4)
/* 80025530 00022490  48 01 AE 11 */	bl stringDup__9StdSystemFPc
/* 80025534 00022494  90 7C 00 00 */	stw r3, 0(r28)
/* 80025538 00022498  28 1E 00 00 */	cmplwi r30, 0
/* 8002553C 0002249C  93 FC 00 0C */	stw r31, 0xc(r28)
/* 80025540 000224A0  41 82 00 0C */	beq lbl_8002554C
/* 80025544 000224A4  7F C3 F3 78 */	mr r3, r30
/* 80025548 000224A8  48 00 00 10 */	b lbl_80025558
lbl_8002554C:
/* 8002554C 000224AC  80 7C 00 0C */	lwz r3, 0xc(r28)
/* 80025550 000224B0  38 80 00 20 */	li r4, 0x20
/* 80025554 000224B4  48 02 1C 15 */	bl __nwa__FUli
lbl_80025558:
/* 80025558 000224B8  90 7C 00 08 */	stw r3, 8(r28)
/* 8002555C 000224BC  38 00 00 00 */	li r0, 0
/* 80025560 000224C0  38 7C 00 00 */	addi r3, r28, 0
/* 80025564 000224C4  90 1C 00 18 */	stw r0, 0x18(r28)
/* 80025568 000224C8  90 1C 00 14 */	stw r0, 0x14(r28)
/* 8002556C 000224CC  90 1C 00 10 */	stw r0, 0x10(r28)
/* 80025570 000224D0  93 BC 00 1C */	stw r29, 0x1c(r28)
/* 80025574 000224D4  48 00 00 E5 */	bl fillBuffer__19BufferedInputStreamFv
/* 80025578 000224D8  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8002557C 000224DC  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80025580 000224E0  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 80025584 000224E4  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 80025588 000224E8  83 81 00 18 */	lwz r28, 0x18(r1)
/* 8002558C 000224EC  38 21 00 28 */	addi r1, r1, 0x28
/* 80025590 000224F0  7C 08 03 A6 */	mtlr r0
/* 80025594 000224F4  4E 80 00 20 */	blr 

.global __ct__19BufferedInputStreamFP6StreamPUci
__ct__19BufferedInputStreamFP6StreamPUci:
/* 80025598 000224F8  7C 08 02 A6 */	mflr r0
/* 8002559C 000224FC  3C E0 80 22 */	lis r7, __vt__6Stream@ha
/* 800255A0 00022500  90 01 00 04 */	stw r0, 4(r1)
/* 800255A4 00022504  38 07 73 98 */	addi r0, r7, __vt__6Stream@l
/* 800255A8 00022508  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800255AC 0002250C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800255B0 00022510  7C DF 33 78 */	mr r31, r6
/* 800255B4 00022514  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800255B8 00022518  3B C5 00 00 */	addi r30, r5, 0
/* 800255BC 0002251C  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 800255C0 00022520  3B A4 00 00 */	addi r29, r4, 0
/* 800255C4 00022524  93 81 00 18 */	stw r28, 0x18(r1)
/* 800255C8 00022528  3B 83 00 00 */	addi r28, r3, 0
/* 800255CC 0002252C  3C 60 80 22 */	lis r3, __vt__18RandomAccessStream@ha
/* 800255D0 00022530  90 1C 00 04 */	stw r0, 4(r28)
/* 800255D4 00022534  38 03 74 C8 */	addi r0, r3, __vt__18RandomAccessStream@l
/* 800255D8 00022538  3C 60 80 22 */	lis r3, __vt__19BufferedInputStream@ha
/* 800255DC 0002253C  90 1C 00 04 */	stw r0, 4(r28)
/* 800255E0 00022540  38 03 74 64 */	addi r0, r3, __vt__19BufferedInputStream@l
/* 800255E4 00022544  90 1C 00 04 */	stw r0, 4(r28)
/* 800255E8 00022548  80 64 00 00 */	lwz r3, 0(r4)
/* 800255EC 0002254C  48 01 AD 55 */	bl stringDup__9StdSystemFPc
/* 800255F0 00022550  90 7C 00 00 */	stw r3, 0(r28)
/* 800255F4 00022554  28 1E 00 00 */	cmplwi r30, 0
/* 800255F8 00022558  93 FC 00 0C */	stw r31, 0xc(r28)
/* 800255FC 0002255C  41 82 00 0C */	beq lbl_80025608
/* 80025600 00022560  7F C3 F3 78 */	mr r3, r30
/* 80025604 00022564  48 00 00 10 */	b lbl_80025614
lbl_80025608:
/* 80025608 00022568  80 7C 00 0C */	lwz r3, 0xc(r28)
/* 8002560C 0002256C  38 80 00 20 */	li r4, 0x20
/* 80025610 00022570  48 02 1B 59 */	bl __nwa__FUli
lbl_80025614:
/* 80025614 00022574  90 7C 00 08 */	stw r3, 8(r28)
/* 80025618 00022578  38 00 00 00 */	li r0, 0
/* 8002561C 0002257C  38 7C 00 00 */	addi r3, r28, 0
/* 80025620 00022580  90 1C 00 18 */	stw r0, 0x18(r28)
/* 80025624 00022584  90 1C 00 14 */	stw r0, 0x14(r28)
/* 80025628 00022588  90 1C 00 10 */	stw r0, 0x10(r28)
/* 8002562C 0002258C  93 BC 00 1C */	stw r29, 0x1c(r28)
/* 80025630 00022590  48 00 00 29 */	bl fillBuffer__19BufferedInputStreamFv
/* 80025634 00022594  7F 83 E3 78 */	mr r3, r28
/* 80025638 00022598  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8002563C 0002259C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80025640 000225A0  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 80025644 000225A4  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 80025648 000225A8  83 81 00 18 */	lwz r28, 0x18(r1)
/* 8002564C 000225AC  38 21 00 28 */	addi r1, r1, 0x28
/* 80025650 000225B0  7C 08 03 A6 */	mtlr r0
/* 80025654 000225B4  4E 80 00 20 */	blr 

.global fillBuffer__19BufferedInputStreamFv
fillBuffer__19BufferedInputStreamFv:
/* 80025658 000225B8  7C 08 02 A6 */	mflr r0
/* 8002565C 000225BC  90 01 00 04 */	stw r0, 4(r1)
/* 80025660 000225C0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80025664 000225C4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80025668 000225C8  7C 7F 1B 78 */	mr r31, r3
/* 8002566C 000225CC  80 63 00 14 */	lwz r3, 0x14(r3)
/* 80025670 000225D0  80 1F 00 10 */	lwz r0, 0x10(r31)
/* 80025674 000225D4  7C 03 00 51 */	subf. r0, r3, r0
/* 80025678 000225D8  40 82 00 54 */	bne lbl_800256CC
/* 8002567C 000225DC  7F E3 FB 78 */	mr r3, r31
/* 80025680 000225E0  81 9F 00 04 */	lwz r12, 4(r31)
/* 80025684 000225E4  81 8C 00 44 */	lwz r12, 0x44(r12)
/* 80025688 000225E8  7D 88 03 A6 */	mtlr r12
/* 8002568C 000225EC  4E 80 00 21 */	blrl 
/* 80025690 000225F0  90 7F 00 10 */	stw r3, 0x10(r31)
/* 80025694 000225F4  80 1F 00 10 */	lwz r0, 0x10(r31)
/* 80025698 000225F8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8002569C 000225FC  7C 00 18 00 */	cmpw r0, r3
/* 800256A0 00022600  40 81 00 08 */	ble lbl_800256A8
/* 800256A4 00022604  90 7F 00 10 */	stw r3, 0x10(r31)
lbl_800256A8:
/* 800256A8 00022608  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 800256AC 0002260C  80 9F 00 08 */	lwz r4, 8(r31)
/* 800256B0 00022610  81 83 00 04 */	lwz r12, 4(r3)
/* 800256B4 00022614  80 BF 00 10 */	lwz r5, 0x10(r31)
/* 800256B8 00022618  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 800256BC 0002261C  7D 88 03 A6 */	mtlr r12
/* 800256C0 00022620  4E 80 00 21 */	blrl 
/* 800256C4 00022624  38 00 00 00 */	li r0, 0
/* 800256C8 00022628  90 1F 00 14 */	stw r0, 0x14(r31)
lbl_800256CC:
/* 800256CC 0002262C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800256D0 00022630  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800256D4 00022634  38 21 00 18 */	addi r1, r1, 0x18
/* 800256D8 00022638  7C 08 03 A6 */	mtlr r0
/* 800256DC 0002263C  4E 80 00 20 */	blr 

.global getPending__19BufferedInputStreamFv
getPending__19BufferedInputStreamFv:
/* 800256E0 00022640  7C 08 02 A6 */	mflr r0
/* 800256E4 00022644  90 01 00 04 */	stw r0, 4(r1)
/* 800256E8 00022648  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800256EC 0002264C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800256F0 00022650  7C 7F 1B 78 */	mr r31, r3
/* 800256F4 00022654  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 800256F8 00022658  81 83 00 04 */	lwz r12, 4(r3)
/* 800256FC 0002265C  81 8C 00 44 */	lwz r12, 0x44(r12)
/* 80025700 00022660  7D 88 03 A6 */	mtlr r12
/* 80025704 00022664  4E 80 00 21 */	blrl 
/* 80025708 00022668  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 8002570C 0002266C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80025710 00022670  7C 60 18 50 */	subf r3, r0, r3
/* 80025714 00022674  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80025718 00022678  38 21 00 18 */	addi r1, r1, 0x18
/* 8002571C 0002267C  7C 08 03 A6 */	mtlr r0
/* 80025720 00022680  4E 80 00 20 */	blr 

.global read__19BufferedInputStreamFPvi
read__19BufferedInputStreamFPvi:
/* 80025724 00022684  7C 08 02 A6 */	mflr r0
/* 80025728 00022688  90 01 00 04 */	stw r0, 4(r1)
/* 8002572C 0002268C  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80025730 00022690  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80025734 00022694  3B E5 00 00 */	addi r31, r5, 0
/* 80025738 00022698  93 C1 00 20 */	stw r30, 0x20(r1)
/* 8002573C 0002269C  3B C3 00 00 */	addi r30, r3, 0
/* 80025740 000226A0  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 80025744 000226A4  3B A4 00 00 */	addi r29, r4, 0
/* 80025748 000226A8  93 81 00 18 */	stw r28, 0x18(r1)
/* 8002574C 000226AC  48 00 00 B4 */	b lbl_80025800
lbl_80025750:
/* 80025750 000226B0  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 80025754 000226B4  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 80025758 000226B8  7C 03 00 51 */	subf. r0, r3, r0
/* 8002575C 000226BC  40 82 00 54 */	bne lbl_800257B0
/* 80025760 000226C0  7F C3 F3 78 */	mr r3, r30
/* 80025764 000226C4  81 9E 00 04 */	lwz r12, 4(r30)
/* 80025768 000226C8  81 8C 00 44 */	lwz r12, 0x44(r12)
/* 8002576C 000226CC  7D 88 03 A6 */	mtlr r12
/* 80025770 000226D0  4E 80 00 21 */	blrl 
/* 80025774 000226D4  90 7E 00 10 */	stw r3, 0x10(r30)
/* 80025778 000226D8  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 8002577C 000226DC  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 80025780 000226E0  7C 00 18 00 */	cmpw r0, r3
/* 80025784 000226E4  40 81 00 08 */	ble lbl_8002578C
/* 80025788 000226E8  90 7E 00 10 */	stw r3, 0x10(r30)
lbl_8002578C:
/* 8002578C 000226EC  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 80025790 000226F0  80 9E 00 08 */	lwz r4, 8(r30)
/* 80025794 000226F4  81 83 00 04 */	lwz r12, 4(r3)
/* 80025798 000226F8  80 BE 00 10 */	lwz r5, 0x10(r30)
/* 8002579C 000226FC  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 800257A0 00022700  7D 88 03 A6 */	mtlr r12
/* 800257A4 00022704  4E 80 00 21 */	blrl 
/* 800257A8 00022708  38 00 00 00 */	li r0, 0
/* 800257AC 0002270C  90 1E 00 14 */	stw r0, 0x14(r30)
lbl_800257B0:
/* 800257B0 00022710  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 800257B4 00022714  7F FC FB 78 */	mr r28, r31
/* 800257B8 00022718  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 800257BC 0002271C  7C 04 00 50 */	subf r0, r4, r0
/* 800257C0 00022720  7C 1F 00 00 */	cmpw r31, r0
/* 800257C4 00022724  40 81 00 08 */	ble lbl_800257CC
/* 800257C8 00022728  7C 1C 03 78 */	mr r28, r0
lbl_800257CC:
/* 800257CC 0002272C  80 1E 00 08 */	lwz r0, 8(r30)
/* 800257D0 00022730  38 7D 00 00 */	addi r3, r29, 0
/* 800257D4 00022734  38 BC 00 00 */	addi r5, r28, 0
/* 800257D8 00022738  7C 80 22 14 */	add r4, r0, r4
/* 800257DC 0002273C  4B FD DC 39 */	bl memcpy
/* 800257E0 00022740  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800257E4 00022744  7F BD E2 14 */	add r29, r29, r28
/* 800257E8 00022748  7F FC F8 50 */	subf r31, r28, r31
/* 800257EC 0002274C  7C 00 E2 14 */	add r0, r0, r28
/* 800257F0 00022750  90 1E 00 14 */	stw r0, 0x14(r30)
/* 800257F4 00022754  80 1E 00 18 */	lwz r0, 0x18(r30)
/* 800257F8 00022758  7C 00 E2 14 */	add r0, r0, r28
/* 800257FC 0002275C  90 1E 00 18 */	stw r0, 0x18(r30)
lbl_80025800:
/* 80025800 00022760  2C 1F 00 00 */	cmpwi r31, 0
/* 80025804 00022764  40 82 FF 4C */	bne lbl_80025750
/* 80025808 00022768  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8002580C 0002276C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80025810 00022770  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 80025814 00022774  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 80025818 00022778  83 81 00 18 */	lwz r28, 0x18(r1)
/* 8002581C 0002277C  38 21 00 28 */	addi r1, r1, 0x28
/* 80025820 00022780  7C 08 03 A6 */	mtlr r0
/* 80025824 00022784  4E 80 00 20 */	blr 

.global close__19BufferedInputStreamFv
close__19BufferedInputStreamFv:
/* 80025828 00022788  7C 08 02 A6 */	mflr r0
/* 8002582C 0002278C  90 01 00 04 */	stw r0, 4(r1)
/* 80025830 00022790  94 21 FF F8 */	stwu r1, -8(r1)
/* 80025834 00022794  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 80025838 00022798  81 83 00 04 */	lwz r12, 4(r3)
/* 8002583C 0002279C  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 80025840 000227A0  7D 88 03 A6 */	mtlr r12
/* 80025844 000227A4  4E 80 00 21 */	blrl 
/* 80025848 000227A8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8002584C 000227AC  38 21 00 08 */	addi r1, r1, 8
/* 80025850 000227B0  7C 08 03 A6 */	mtlr r0
/* 80025854 000227B4  4E 80 00 20 */	blr 

.global getPosition__19BufferedInputStreamFv
getPosition__19BufferedInputStreamFv:
/* 80025858 000227B8  80 63 00 18 */	lwz r3, 0x18(r3)
/* 8002585C 000227BC  4E 80 00 20 */	blr 

.global getLength__18RandomAccessStreamFv
getLength__18RandomAccessStreamFv:
/* 80025860 000227C0  7C 08 02 A6 */	mflr r0
/* 80025864 000227C4  90 01 00 04 */	stw r0, 4(r1)
/* 80025868 000227C8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8002586C 000227CC  81 83 00 04 */	lwz r12, 4(r3)
/* 80025870 000227D0  81 8C 00 48 */	lwz r12, 0x48(r12)
/* 80025874 000227D4  7D 88 03 A6 */	mtlr r12
/* 80025878 000227D8  4E 80 00 21 */	blrl 
/* 8002587C 000227DC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80025880 000227E0  38 21 00 08 */	addi r1, r1, 8
/* 80025884 000227E4  7C 08 03 A6 */	mtlr r0
/* 80025888 000227E8  4E 80 00 20 */	blr 

.global getPosition__18RandomAccessStreamFv
getPosition__18RandomAccessStreamFv:
/* 8002588C 000227EC  38 60 00 00 */	li r3, 0
/* 80025890 000227F0  4E 80 00 20 */	blr 

.global getPending__18RandomAccessStreamFv
getPending__18RandomAccessStreamFv:
/* 80025894 000227F4  7C 08 02 A6 */	mflr r0
/* 80025898 000227F8  90 01 00 04 */	stw r0, 4(r1)
/* 8002589C 000227FC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800258A0 00022800  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800258A4 00022804  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800258A8 00022808  7C 7E 1B 78 */	mr r30, r3
/* 800258AC 0002280C  81 9E 00 04 */	lwz r12, 4(r30)
/* 800258B0 00022810  81 8C 00 60 */	lwz r12, 0x60(r12)
/* 800258B4 00022814  7D 88 03 A6 */	mtlr r12
/* 800258B8 00022818  4E 80 00 21 */	blrl 
/* 800258BC 0002281C  3B E3 00 00 */	addi r31, r3, 0
/* 800258C0 00022820  38 7E 00 00 */	addi r3, r30, 0
/* 800258C4 00022824  81 9E 00 04 */	lwz r12, 4(r30)
/* 800258C8 00022828  81 8C 00 58 */	lwz r12, 0x58(r12)
/* 800258CC 0002282C  7D 88 03 A6 */	mtlr r12
/* 800258D0 00022830  4E 80 00 21 */	blrl 
/* 800258D4 00022834  7C 63 F8 50 */	subf r3, r3, r31
/* 800258D8 00022838  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800258DC 0002283C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800258E0 00022840  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800258E4 00022844  38 21 00 18 */	addi r1, r1, 0x18
/* 800258E8 00022848  7C 08 03 A6 */	mtlr r0
/* 800258EC 0002284C  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802273F0:
	.asciz "streamBufferedInput.cpp"
.balign 4
lbl_80227408:
	.asciz "streamBufferedInput"
.balign 4
lbl_8022741C:
	.asciz "BufferedInputStream"
.balign 4
lbl_80227430:
	.asciz "RandomAccessStream"
.balign 4
lbl_80227444:
	.4byte __RTTI__6Stream
	.4byte 0
	.4byte 0
lbl_80227450:
	.4byte __RTTI__6Stream
	.4byte 0
	.4byte __RTTI__18RandomAccessStream
	.4byte 0
	.4byte 0
.global __vt__19BufferedInputStream
__vt__19BufferedInputStream:
	.4byte __RTTI__19BufferedInputStream
	.4byte 0
	.4byte readInt__6StreamFv
	.4byte readByte__6StreamFv
	.4byte readShort__6StreamFv
	.4byte readFloat__6StreamFv
	.4byte readString__6StreamFPci
	.4byte readString__6StreamFR6String
	.4byte readString__6StreamFv
	.4byte writeInt__6StreamFi
	.4byte writeByte__6StreamFUc
	.4byte writeShort__6StreamFs
	.4byte writeFloat__6StreamFf
	.4byte writeString__6StreamFPc
	.4byte writeString__6StreamFR6String
	.4byte read__19BufferedInputStreamFPvi
	.4byte write__6StreamFPvi
	.4byte getPending__19BufferedInputStreamFv
	.4byte getAvailable__6StreamFv
	.4byte close__19BufferedInputStreamFv
	.4byte getClosing__6StreamFv
	.4byte flush__6StreamFv
	.4byte getPosition__19BufferedInputStreamFv
	.4byte setPosition__18RandomAccessStreamFi
	.4byte getLength__18RandomAccessStreamFv
.global __vt__18RandomAccessStream
__vt__18RandomAccessStream:
	.4byte __RTTI__18RandomAccessStream
	.4byte 0
	.4byte readInt__6StreamFv
	.4byte readByte__6StreamFv
	.4byte readShort__6StreamFv
	.4byte readFloat__6StreamFv
	.4byte readString__6StreamFPci
	.4byte readString__6StreamFR6String
	.4byte readString__6StreamFv
	.4byte writeInt__6StreamFi
	.4byte writeByte__6StreamFUc
	.4byte writeShort__6StreamFs
	.4byte writeFloat__6StreamFf
	.4byte writeString__6StreamFPc
	.4byte writeString__6StreamFR6String
	.4byte read__6StreamFPvi
	.4byte write__6StreamFPvi
	.4byte getPending__18RandomAccessStreamFv
	.4byte getAvailable__6StreamFv
	.4byte close__6StreamFv
	.4byte getClosing__6StreamFv
	.4byte flush__6StreamFv
	.4byte getPosition__18RandomAccessStreamFv
	.4byte setPosition__18RandomAccessStreamFi
	.4byte getLength__18RandomAccessStreamFv
	.skip 20 # padding

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DCEC0:
	.asciz "Stream"
.balign 4
__RTTI__6Stream:
	.4byte lbl_803DCEC0
	.4byte 0
__RTTI__18RandomAccessStream:
	.4byte lbl_80227430
	.4byte lbl_80227444
__RTTI__19BufferedInputStream:
	.4byte lbl_8022741C
	.4byte lbl_80227450
