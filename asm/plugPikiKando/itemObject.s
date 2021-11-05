.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8013658C 001334EC  41 82 00 38 */	beq lbl_801365C4
/* 80136590 001334F0  80 B6 00 84 */	lwz r5, 0x84(r22)
/* 80136594 001334F4  3C 80 80 2C */	lis r4, __vt__9TaiAction@ha
/* 80136598 001334F8  3C 60 80 2D */	lis r3, __vt__21TaiNapkidFlyingAction@ha
/* 8013659C 001334FC  80 A5 00 04 */	lwz r5, 4(r5)
/* 801365A0 00133500  38 84 66 20 */	addi r4, r4, __vt__9TaiAction@l
/* 801365A4 00133504  38 00 FF FF */	li r0, -1
/* 801365A8 00133508  80 A5 00 00 */	lwz r5, 0(r5)
/* 801365AC 0013350C  38 63 A5 94 */	addi r3, r3, __vt__21TaiNapkidFlyingAction@l
/* 801365B0 00133510  C0 05 00 74 */	lfs f0, 0x74(r5)
/* 801365B4 00133514  90 97 00 04 */	stw r4, 4(r23)
/* 801365B8 00133518  90 17 00 00 */	stw r0, 0(r23)
/* 801365BC 0013351C  90 77 00 04 */	stw r3, 4(r23)
/* 801365C0 00133520  D0 17 00 08 */	stfs f0, 8(r23)
lbl_801365C4:
/* 801365C4 00133524  38 60 00 0C */	li r3, 0xc
/* 801365C8 00133528  4B F1 0A 3D */	bl alloc__6SystemFUl
/* 801365CC 0013352C  39 E3 00 00 */	addi r15, r3, 0
/* 801365D0 00133530  7D E0 7B 79 */	or. r0, r15, r15
/* 801365D4 00133534  41 82 00 38 */	beq lbl_8013660C
/* 801365D8 00133538  80 B6 00 84 */	lwz r5, 0x84(r22)
/* 801365DC 0013353C  3C 80 80 2C */	lis r4, __vt__9TaiAction@ha
/* 801365E0 00133540  3C 60 80 2D */	lis r3, __vt__21TaiNapkidFlyingAction@ha
/* 801365E4 00133544  80 A5 00 04 */	lwz r5, 4(r5)
/* 801365E8 00133548  38 84 66 20 */	addi r4, r4, __vt__9TaiAction@l
/* 801365EC 0013354C  38 00 FF FF */	li r0, -1
/* 801365F0 00133550  80 A5 00 00 */	lwz r5, 0(r5)
/* 801365F4 00133554  38 63 A5 94 */	addi r3, r3, __vt__21TaiNapkidFlyingAction@l
/* 801365F8 00133558  C0 05 00 CC */	lfs f0, 0xcc(r5)
/* 801365FC 0013355C  90 8F 00 04 */	stw r4, 4(r15)
/* 80136600 00133560  90 0F 00 00 */	stw r0, 0(r15)
/* 80136604 00133564  90 6F 00 04 */	stw r3, 4(r15)
/* 80136608 00133568  D0 0F 00 08 */	stfs f0, 8(r15)
lbl_8013660C:
/* 8013660C 0013356C  38 60 00 0C */	li r3, 0xc
/* 80136610 00133570  4B F1 09 F5 */	bl alloc__6SystemFUl
/* 80136614 00133574  3B A3 00 00 */	addi r29, r3, 0
/* 80136618 00133578  7F A0 EB 79 */	or. r0, r29, r29
/* 8013661C 0013357C  41 82 00 38 */	beq lbl_80136654
/* 80136620 00133580  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136624 00133584  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136628 00133588  90 1D 00 04 */	stw r0, 4(r29)
/* 8013662C 0013358C  38 00 FF FF */	li r0, -1
/* 80136630 00133590  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 80136634 00133594  90 1D 00 00 */	stw r0, 0(r29)
/* 80136638 00133598  38 03 95 94 */	addi r0, r3, __vt__15TaiMotionAction@l
/* 8013663C 0013359C  3C 60 80 2D */	lis r3, __vt__14TaiDyingAction@ha
/* 80136640 001335A0  90 1D 00 04 */	stw r0, 4(r29)
/* 80136644 001335A4  38 00 00 00 */	li r0, 0
/* 80136648 001335A8  38 63 BB 84 */	addi r3, r3, __vt__14TaiDyingAction@l
/* 8013664C 001335AC  90 1D 00 08 */	stw r0, 8(r29)
/* 80136650 001335B0  90 7D 00 04 */	stw r3, 4(r29)
lbl_80136654:
/* 80136654 001335B4  38 60 00 08 */	li r3, 8
/* 80136658 001335B8  4B F1 09 AD */	bl alloc__6SystemFUl
/* 8013665C 001335BC  3B C3 00 00 */	addi r30, r3, 0
/* 80136660 001335C0  7F C0 F3 79 */	or. r0, r30, r30
/* 80136664 001335C4  41 82 00 24 */	beq lbl_80136688
/* 80136668 001335C8  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8013666C 001335CC  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136670 001335D0  90 1E 00 04 */	stw r0, 4(r30)
/* 80136674 001335D4  38 00 FF FF */	li r0, -1
/* 80136678 001335D8  3C 60 80 2D */	lis r3, __vt__19TaiStartDyingAction@ha
/* 8013667C 001335DC  90 1E 00 00 */	stw r0, 0(r30)
/* 80136680 001335E0  38 03 BC 40 */	addi r0, r3, __vt__19TaiStartDyingAction@l
/* 80136684 001335E4  90 1E 00 04 */	stw r0, 4(r30)
lbl_80136688:
/* 80136688 001335E8  38 60 00 0C */	li r3, 0xc
/* 8013668C 001335EC  4B F1 09 79 */	bl alloc__6SystemFUl
/* 80136690 001335F0  3B 83 00 00 */	addi r28, r3, 0
/* 80136694 001335F4  7F 83 E3 79 */	or. r3, r28, r28
/* 80136698 001335F8  41 82 00 0C */	beq lbl_801366A4
/* 8013669C 001335FC  38 80 00 03 */	li r4, 3
/* 801366A0 00133600  4B FF 09 F9 */	bl __ct__8TaiStateFi
lbl_801366A4:
/* 801366A4 00133604  38 00 00 00 */	li r0, 0
/* 801366A8 00133608  80 7C 00 08 */	lwz r3, 8(r28)
/* 801366AC 0013360C  54 00 10 3A */	slwi r0, r0, 2
/* 801366B0 00133610  7D C3 01 2E */	stwx r14, r3, r0
/* 801366B4 00133614  38 80 00 01 */	li r4, 1
/* 801366B8 00133618  38 00 00 02 */	li r0, 2
/* 801366BC 0013361C  80 7C 00 08 */	lwz r3, 8(r28)
/* 801366C0 00133620  54 84 10 3A */	slwi r4, r4, 2
/* 801366C4 00133624  54 00 10 3A */	slwi r0, r0, 2
/* 801366C8 00133628  7F C3 21 2E */	stwx r30, r3, r4
/* 801366CC 0013362C  38 60 00 10 */	li r3, 0x10
/* 801366D0 00133630  80 9C 00 08 */	lwz r4, 8(r28)
/* 801366D4 00133634  7F A4 01 2E */	stwx r29, r4, r0
/* 801366D8 00133638  80 99 00 08 */	lwz r4, 8(r25)
/* 801366DC 0013363C  93 84 00 00 */	stw r28, 0(r4)
/* 801366E0 00133640  4B F1 09 25 */	bl alloc__6SystemFUl
/* 801366E4 00133644  3B A3 00 00 */	addi r29, r3, 0
/* 801366E8 00133648  7F A0 EB 79 */	or. r0, r29, r29
/* 801366EC 0013364C  41 82 00 58 */	beq lbl_80136744
/* 801366F0 00133650  80 76 00 84 */	lwz r3, 0x84(r22)
/* 801366F4 00133654  3C E0 80 2C */	lis r7, __vt__9TaiAction@ha
/* 801366F8 00133658  3C C0 80 2D */	lis r6, __vt__15TaiMotionAction@ha
/* 801366FC 0013365C  80 63 00 04 */	lwz r3, 4(r3)
/* 80136700 00133660  3C A0 80 2D */	lis r5, __vt__25TaiContinuousMotionAction@ha
/* 80136704 00133664  3C 80 80 2D */	lis r4, __vt__29TaiNapkidWanderingRouteAction@ha
/* 80136708 00133668  80 63 00 00 */	lwz r3, 0(r3)
/* 8013670C 0013366C  38 E7 66 20 */	addi r7, r7, __vt__9TaiAction@l
/* 80136710 00133670  38 00 FF FF */	li r0, -1
/* 80136714 00133674  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 80136718 00133678  38 C6 95 94 */	addi r6, r6, __vt__15TaiMotionAction@l
/* 8013671C 0013367C  38 60 00 06 */	li r3, 6
/* 80136720 00133680  90 FD 00 04 */	stw r7, 4(r29)
/* 80136724 00133684  38 A5 95 74 */	addi r5, r5, __vt__25TaiContinuousMotionAction@l
/* 80136728 00133688  38 84 A7 88 */	addi r4, r4, __vt__29TaiNapkidWanderingRouteAction@l
/* 8013672C 0013368C  90 1D 00 00 */	stw r0, 0(r29)
/* 80136730 00133690  90 DD 00 04 */	stw r6, 4(r29)
/* 80136734 00133694  90 7D 00 08 */	stw r3, 8(r29)
/* 80136738 00133698  90 BD 00 04 */	stw r5, 4(r29)
/* 8013673C 0013369C  90 9D 00 04 */	stw r4, 4(r29)
/* 80136740 001336A0  D0 1D 00 0C */	stfs f0, 0xc(r29)
lbl_80136744:
/* 80136744 001336A4  38 60 00 18 */	li r3, 0x18
/* 80136748 001336A8  4B F1 08 BD */	bl alloc__6SystemFUl
/* 8013674C 001336AC  3B C3 00 00 */	addi r30, r3, 0
/* 80136750 001336B0  7F C0 F3 79 */	or. r0, r30, r30
/* 80136754 001336B4  41 82 00 5C */	beq lbl_801367B0
/* 80136758 001336B8  80 96 00 84 */	lwz r4, 0x84(r22)
/* 8013675C 001336BC  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136760 001336C0  3C C0 80 2D */	lis r6, __vt__14TaiTimerAction@ha
/* 80136764 001336C4  80 84 00 04 */	lwz r4, 4(r4)
/* 80136768 001336C8  3C A0 80 2D */	lis r5, __vt__22TaiStartingTimerAction@ha
/* 8013676C 001336CC  38 63 66 20 */	addi r3, r3, __vt__9TaiAction@l
/* 80136770 001336D0  80 84 00 00 */	lwz r4, 0(r4)
/* 80136774 001336D4  38 00 00 02 */	li r0, 2
/* 80136778 001336D8  38 E6 CA 28 */	addi r7, r6, __vt__14TaiTimerAction@l
/* 8013677C 001336DC  C0 24 00 D8 */	lfs f1, 0xd8(r4)
/* 80136780 001336E0  38 C0 00 00 */	li r6, 0
/* 80136784 001336E4  C0 04 00 D4 */	lfs f0, 0xd4(r4)
/* 80136788 001336E8  38 85 C9 90 */	addi r4, r5, __vt__22TaiStartingTimerAction@l
/* 8013678C 001336EC  90 7E 00 04 */	stw r3, 4(r30)
/* 80136790 001336F0  90 1E 00 00 */	stw r0, 0(r30)
/* 80136794 001336F4  90 FE 00 04 */	stw r7, 4(r30)
/* 80136798 001336F8  90 DE 00 08 */	stw r6, 8(r30)
/* 8013679C 001336FC  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 801367A0 00133700  C0 02 A4 CC */	lfs f0, lbl_803EA6CC@sda21(r2)
/* 801367A4 00133704  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 801367A8 00133708  90 9E 00 04 */	stw r4, 4(r30)
/* 801367AC 0013370C  D0 3E 00 14 */	stfs f1, 0x14(r30)
lbl_801367B0:
/* 801367B0 00133710  38 60 00 0C */	li r3, 0xc
/* 801367B4 00133714  4B F1 08 51 */	bl alloc__6SystemFUl
/* 801367B8 00133718  3B 83 00 00 */	addi r28, r3, 0
/* 801367BC 0013371C  7F 80 E3 79 */	or. r0, r28, r28
/* 801367C0 00133720  41 82 00 2C */	beq lbl_801367EC
/* 801367C4 00133724  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801367C8 00133728  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801367CC 0013372C  90 1C 00 04 */	stw r0, 4(r28)
/* 801367D0 00133730  38 00 FF FF */	li r0, -1
/* 801367D4 00133734  3C 60 80 2D */	lis r3, __vt__33TaiHeadOnCollisionAvoidanceAction@ha
/* 801367D8 00133738  90 1C 00 00 */	stw r0, 0(r28)
/* 801367DC 0013373C  38 03 96 10 */	addi r0, r3, __vt__33TaiHeadOnCollisionAvoidanceAction@l
/* 801367E0 00133740  90 1C 00 04 */	stw r0, 4(r28)
/* 801367E4 00133744  C0 02 A4 A8 */	lfs f0, lbl_803EA6A8@sda21(r2)
/* 801367E8 00133748  D0 1C 00 08 */	stfs f0, 8(r28)
lbl_801367EC:
/* 801367EC 0013374C  38 60 00 0C */	li r3, 0xc
/* 801367F0 00133750  4B F1 08 15 */	bl alloc__6SystemFUl
/* 801367F4 00133754  3B E3 00 00 */	addi r31, r3, 0
/* 801367F8 00133758  7F E3 FB 79 */	or. r3, r31, r31
/* 801367FC 0013375C  41 82 00 0C */	beq lbl_80136808
/* 80136800 00133760  38 80 00 09 */	li r4, 9
/* 80136804 00133764  4B FF 08 95 */	bl __ct__8TaiStateFi
lbl_80136808:
/* 80136808 00133768  38 00 00 00 */	li r0, 0
/* 8013680C 0013376C  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136810 00133770  54 04 10 3A */	slwi r4, r0, 2
/* 80136814 00133774  80 01 03 78 */	lwz r0, 0x378(r1)
/* 80136818 00133778  38 E0 00 04 */	li r7, 4
/* 8013681C 0013377C  7C 03 21 2E */	stwx r0, r3, r4
/* 80136820 00133780  38 80 00 01 */	li r4, 1
/* 80136824 00133784  54 85 10 3A */	slwi r5, r4, 2
/* 80136828 00133788  80 7F 00 08 */	lwz r3, 8(r31)
/* 8013682C 0013378C  38 00 00 02 */	li r0, 2
/* 80136830 00133790  38 80 00 03 */	li r4, 3
/* 80136834 00133794  7F 03 29 2E */	stwx r24, r3, r5
/* 80136838 00133798  38 A0 00 05 */	li r5, 5
/* 8013683C 0013379C  54 00 10 3A */	slwi r0, r0, 2
/* 80136840 001337A0  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136844 001337A4  54 84 10 3A */	slwi r4, r4, 2
/* 80136848 001337A8  54 E8 10 3A */	slwi r8, r7, 2
/* 8013684C 001337AC  7E A3 01 2E */	stwx r21, r3, r0
/* 80136850 001337B0  38 C0 00 06 */	li r6, 6
/* 80136854 001337B4  38 00 00 07 */	li r0, 7
/* 80136858 001337B8  80 7F 00 08 */	lwz r3, 8(r31)
/* 8013685C 001337BC  54 A5 10 3A */	slwi r5, r5, 2
/* 80136860 001337C0  54 C7 10 3A */	slwi r7, r6, 2
/* 80136864 001337C4  7E 83 21 2E */	stwx r20, r3, r4
/* 80136868 001337C8  39 20 00 08 */	li r9, 8
/* 8013686C 001337CC  54 00 10 3A */	slwi r0, r0, 2
/* 80136870 001337D0  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136874 001337D4  55 26 10 3A */	slwi r6, r9, 2
/* 80136878 001337D8  7F 43 41 2E */	stwx r26, r3, r8
/* 8013687C 001337DC  38 60 00 0C */	li r3, 0xc
/* 80136880 001337E0  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136884 001337E4  7E E4 29 2E */	stwx r23, r4, r5
/* 80136888 001337E8  80 9F 00 08 */	lwz r4, 8(r31)
/* 8013688C 001337EC  7F C4 39 2E */	stwx r30, r4, r7
/* 80136890 001337F0  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136894 001337F4  7F A4 01 2E */	stwx r29, r4, r0
/* 80136898 001337F8  80 9F 00 08 */	lwz r4, 8(r31)
/* 8013689C 001337FC  7F 84 31 2E */	stwx r28, r4, r6
/* 801368A0 00133800  80 99 00 08 */	lwz r4, 8(r25)
/* 801368A4 00133804  93 E4 00 04 */	stw r31, 4(r4)
/* 801368A8 00133808  4B F1 07 5D */	bl alloc__6SystemFUl
/* 801368AC 0013380C  3B 83 00 00 */	addi r28, r3, 0
/* 801368B0 00133810  7F 80 E3 79 */	or. r0, r28, r28
/* 801368B4 00133814  41 82 00 38 */	beq lbl_801368EC
/* 801368B8 00133818  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801368BC 0013381C  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801368C0 00133820  90 1C 00 04 */	stw r0, 4(r28)
/* 801368C4 00133824  38 00 FF FF */	li r0, -1
/* 801368C8 00133828  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 801368CC 0013382C  90 1C 00 00 */	stw r0, 0(r28)
/* 801368D0 00133830  38 03 95 94 */	addi r0, r3, __vt__15TaiMotionAction@l
/* 801368D4 00133834  3C 60 80 2D */	lis r3, __vt__25TaiContinuousMotionAction@ha
/* 801368D8 00133838  90 1C 00 04 */	stw r0, 4(r28)
/* 801368DC 0013383C  38 00 00 06 */	li r0, 6
/* 801368E0 00133840  38 63 95 74 */	addi r3, r3, __vt__25TaiContinuousMotionAction@l

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x6974656d
  .4byte 0x4f626a65
  .4byte 0x63742e63
  .4byte 0x70700000
  .4byte 0x6974656d
  .4byte 0x4f626a65
  .4byte 0x63740000
  .4byte 0x4e617669
  .4byte 0x44656d6f
  .4byte 0x53756e73
  .4byte 0x6574476f
  .4byte 0x616c0000
  .4byte 0x50616e69
  .4byte 0x416e696d
  .4byte 0x4b65794c
  .4byte 0x69737465
  .4byte 0x6e657200
  .4byte 0x4576656e
  .4byte 0x7454616c
  .4byte 0x6b657200
  .4byte 0x52656643
  .4byte 0x6f756e74
  .4byte 0x61626c65
  .4byte 0
  .4byte 0x43726561
  .4byte 0x74757265
  .4byte 0
  .4byte 0x803e1e88
  .4byte 0x8
  .4byte 0x803e1e90
  .4byte 0
  .4byte 0
  .4byte 0x41494372
  .4byte 0x65617475
  .4byte 0x72650000
  .4byte 0x803e1e80
  .4byte 0x2b8
  .4byte 0x803e1e88
  .4byte 0x8
  .4byte 0x803e1e90
  .4byte 0
  .4byte 0x803e1e98
  .4byte 0
  .4byte 0
  .4byte 0x4974656d
  .4byte 0x43726561
  .4byte 0x74757265
  .4byte 0
  .4byte 0x803e1e80
  .4byte 0x2b8
  .4byte 0x803e1e88
  .4byte 0x8
  .4byte 0x803e1e90
  .4byte 0
  .4byte 0x803e1e98
  .4byte 0
  .4byte 0x803e1ea0
  .4byte 0
  .4byte 0
  .4byte 0x4974656d
  .4byte 0x4f626a65
  .4byte 0x63740000
  .4byte 0x803e1e80
  .4byte 0x2b8
  .4byte 0x803e1e88
  .4byte 0x8
  .4byte 0x803e1e90
  .4byte 0
  .4byte 0x803e1e98
  .4byte 0
  .4byte 0x803e1ea0
  .4byte 0
  .4byte 0x803e1ea8
  .4byte 0
  .4byte 0
  .4byte 0x803e1e80
  .4byte 0x2b8
  .4byte 0x803e1e88
  .4byte 0x8
  .4byte 0x803e1e90
  .4byte 0
  .4byte 0x803e1e98
  .4byte 0
  .4byte 0x803e1ea0
  .4byte 0
  .4byte 0x803e1ea8
  .4byte 0
  .4byte __RTTI__10ItemObject
  .4byte 0
  .4byte 0
.global __vt__18NaviDemoSunsetGoal
__vt__18NaviDemoSunsetGoal:
  .4byte __RTTI__18NaviDemoSunsetGoal
  .4byte 0
  .4byte addCntCallback__12RefCountableFv
  .4byte subCntCallback__12RefCountableFv
  .4byte insideSafeArea__8CreatureFR8Vector3f
  .4byte platAttachable__8CreatureFv
  .4byte alwaysUpdatePlatform__8CreatureFv
  .4byte doDoAI__8CreatureFv
  .4byte setRouteTracer__8CreatureFP11RouteTracer
  .4byte init__8CreatureFv
  .4byte init__12ItemCreatureFR8Vector3f
  .4byte resetPosition__8CreatureFR8Vector3f
  .4byte initParam__8CreatureFi
  .4byte startAI__8CreatureFi
  .4byte getiMass__8CreatureFv
  .4byte getSize__8CreatureFv
  .4byte getHeight__12ItemCreatureFv
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
  .4byte isVisible__8CreatureFv
  .4byte isOrganic__8CreatureFv
  .4byte isTerrible__8CreatureFv
  .4byte isBuried__8CreatureFv
  .4byte isAtari__10ItemObjectFv
  .4byte isAlive__8CreatureFv
  .4byte isFixed__8CreatureFv
  .4byte needShadow__10ItemObjectFv
  .4byte needFlick__8CreatureFP8Creature
  .4byte ignoreAtari__8CreatureFP8Creature
  .4byte isFree__8CreatureFv
  .4byte stimulate__12ItemCreatureFR11Interaction
  .4byte sendMsg__8CreatureFP3Msg
  .4byte collisionCallback__10AICreatureFR9CollEvent
  .4byte bounceCallback__10AICreatureFv
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
  .4byte update__10ItemObjectFv
  .4byte postUpdate__10ItemObjectFif
  .4byte stickUpdate__8CreatureFv
  .4byte refresh__12ItemCreatureFR8Graphics
  .4byte refresh2d__8CreatureFR8Graphics
  .4byte renderAtari__8CreatureFR8Graphics
  .4byte drawShadow__8CreatureFR8Graphics
  .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
  .4byte getCatchPos__8CreatureFP8Creature
  .4byte doAI__12ItemCreatureFv
  .4byte doAnimation__12ItemCreatureFv
  .4byte doKill__12ItemCreatureFv
  .4byte exitCourse__8CreatureFv
  .4byte __RTTI__18NaviDemoSunsetGoal
  .4byte 0xfffffd48
  .4byte 0x8007df54
  .4byte getCurrState__10AICreatureFv
  .4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
  .4byte playSound__10AICreatureFi
  .4byte playEffect__10AICreatureFi
  .4byte startMotion__12ItemCreatureFi
  .4byte finishMotion__12ItemCreatureFv
  .4byte finishMotion__12ItemCreatureFf
  .4byte startMotion__12ItemCreatureFif
  .4byte getCurrentMotionName__12ItemCreatureFv
  .4byte getCurrentMotionCounter__12ItemCreatureFv
  .4byte getMotionSpeed__12ItemCreatureFv
  .4byte setMotionSpeed__12ItemCreatureFf
  .4byte stopMotion__12ItemCreatureFv
  .4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
  .4byte finalSetup__12ItemCreatureFv
  .4byte 0x4e617669
  .4byte 0x44656d6f
  .4byte 0x53756e73
  .4byte 0x65745374
  .4byte 0x61727400
  .4byte 0x803e1e80
  .4byte 0x2b8
  .4byte 0x803e1e88
  .4byte 0x8
  .4byte 0x803e1e90
  .4byte 0
  .4byte 0x803e1e98
  .4byte 0
  .4byte 0x803e1ea0
  .4byte 0
  .4byte 0x803e1ea8
  .4byte 0
  .4byte __RTTI__10ItemObject
  .4byte 0
  .4byte 0
.global __vt__19NaviDemoSunsetStart
__vt__19NaviDemoSunsetStart:
  .4byte __RTTI__19NaviDemoSunsetStart
  .4byte 0
  .4byte addCntCallback__12RefCountableFv
  .4byte subCntCallback__12RefCountableFv
  .4byte insideSafeArea__8CreatureFR8Vector3f
  .4byte platAttachable__8CreatureFv
  .4byte alwaysUpdatePlatform__8CreatureFv
  .4byte doDoAI__8CreatureFv
  .4byte setRouteTracer__8CreatureFP11RouteTracer
  .4byte init__8CreatureFv
  .4byte init__12ItemCreatureFR8Vector3f
  .4byte resetPosition__8CreatureFR8Vector3f
  .4byte initParam__8CreatureFi
  .4byte startAI__8CreatureFi
  .4byte getiMass__8CreatureFv
  .4byte getSize__8CreatureFv
  .4byte getHeight__12ItemCreatureFv
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
  .4byte isVisible__8CreatureFv
  .4byte isOrganic__8CreatureFv
  .4byte isTerrible__8CreatureFv
  .4byte isBuried__8CreatureFv
  .4byte isAtari__10ItemObjectFv
  .4byte isAlive__8CreatureFv
  .4byte isFixed__8CreatureFv
  .4byte needShadow__10ItemObjectFv
  .4byte needFlick__8CreatureFP8Creature
  .4byte ignoreAtari__8CreatureFP8Creature
  .4byte isFree__8CreatureFv
  .4byte stimulate__12ItemCreatureFR11Interaction
  .4byte sendMsg__8CreatureFP3Msg
  .4byte collisionCallback__10AICreatureFR9CollEvent
  .4byte bounceCallback__10AICreatureFv
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
  .4byte update__10ItemObjectFv
  .4byte postUpdate__10ItemObjectFif
  .4byte stickUpdate__8CreatureFv
  .4byte refresh__12ItemCreatureFR8Graphics
  .4byte refresh2d__8CreatureFR8Graphics
  .4byte renderAtari__8CreatureFR8Graphics
  .4byte drawShadow__8CreatureFR8Graphics
  .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
  .4byte getCatchPos__8CreatureFP8Creature
  .4byte doAI__12ItemCreatureFv
  .4byte doAnimation__12ItemCreatureFv
  .4byte doKill__12ItemCreatureFv
  .4byte exitCourse__8CreatureFv
  .4byte __RTTI__19NaviDemoSunsetStart
  .4byte 0xfffffd48
  .4byte 0x8007df54
  .4byte getCurrState__10AICreatureFv
  .4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
  .4byte playSound__10AICreatureFi
  .4byte playEffect__10AICreatureFi
  .4byte startMotion__12ItemCreatureFi
  .4byte finishMotion__12ItemCreatureFv
  .4byte finishMotion__12ItemCreatureFf
  .4byte startMotion__12ItemCreatureFif
  .4byte getCurrentMotionName__12ItemCreatureFv
  .4byte getCurrentMotionCounter__12ItemCreatureFv
  .4byte getMotionSpeed__12ItemCreatureFv
  .4byte setMotionSpeed__12ItemCreatureFf
  .4byte stopMotion__12ItemCreatureFv
  .4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
  .4byte finalSetup__12ItemCreatureFv
  .4byte 0x803e1e80
  .4byte 0x2b8
  .4byte 0x803e1e88
  .4byte 0x8
  .4byte 0x803e1e90
  .4byte 0
  .4byte 0x803e1e98
  .4byte 0
  .4byte 0x803e1ea0
  .4byte 0
  .4byte 0x803e1ea8
  .4byte 0
  .4byte __RTTI__10ItemObject
  .4byte 0
  .4byte 0
.global __vt__7Fulcrum
__vt__7Fulcrum:
  .4byte __RTTI__7Fulcrum
  .4byte 0
  .4byte addCntCallback__12RefCountableFv
  .4byte subCntCallback__12RefCountableFv
  .4byte insideSafeArea__8CreatureFR8Vector3f
  .4byte platAttachable__8CreatureFv
  .4byte alwaysUpdatePlatform__8CreatureFv
  .4byte doDoAI__8CreatureFv
  .4byte setRouteTracer__8CreatureFP11RouteTracer
  .4byte init__8CreatureFv
  .4byte init__12ItemCreatureFR8Vector3f
  .4byte resetPosition__8CreatureFR8Vector3f
  .4byte initParam__8CreatureFi
  .4byte startAI__8CreatureFi
  .4byte getiMass__8CreatureFv
  .4byte getSize__8CreatureFv
  .4byte getHeight__12ItemCreatureFv
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
  .4byte isVisible__8CreatureFv
  .4byte isOrganic__8CreatureFv
  .4byte isTerrible__8CreatureFv
  .4byte isBuried__8CreatureFv
  .4byte isAtari__10ItemObjectFv
  .4byte isAlive__8CreatureFv
  .4byte isFixed__8CreatureFv
  .4byte needShadow__10ItemObjectFv
  .4byte needFlick__8CreatureFP8Creature
  .4byte ignoreAtari__8CreatureFP8Creature
  .4byte isFree__8CreatureFv
  .4byte stimulate__12ItemCreatureFR11Interaction
  .4byte sendMsg__8CreatureFP3Msg
  .4byte collisionCallback__10AICreatureFR9CollEvent
  .4byte bounceCallback__10AICreatureFv
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
  .4byte update__10ItemObjectFv
  .4byte postUpdate__10ItemObjectFif
  .4byte stickUpdate__8CreatureFv
  .4byte refresh__12ItemCreatureFR8Graphics
  .4byte refresh2d__8CreatureFR8Graphics
  .4byte renderAtari__8CreatureFR8Graphics
  .4byte drawShadow__8CreatureFR8Graphics
  .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
  .4byte getCatchPos__8CreatureFP8Creature
  .4byte doAI__12ItemCreatureFv
  .4byte doAnimation__12ItemCreatureFv
  .4byte doKill__12ItemCreatureFv
  .4byte exitCourse__8CreatureFv
  .4byte __RTTI__7Fulcrum
  .4byte 0xfffffd48
  .4byte 0x8007df54
  .4byte getCurrState__10AICreatureFv
  .4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
  .4byte playSound__10AICreatureFi
  .4byte playEffect__10AICreatureFi
  .4byte startMotion__12ItemCreatureFi
  .4byte finishMotion__12ItemCreatureFv
  .4byte finishMotion__12ItemCreatureFf
  .4byte startMotion__12ItemCreatureFif
  .4byte getCurrentMotionName__12ItemCreatureFv
  .4byte getCurrentMotionCounter__12ItemCreatureFv
  .4byte getMotionSpeed__12ItemCreatureFv
  .4byte setMotionSpeed__12ItemCreatureFf
  .4byte stopMotion__12ItemCreatureFv
  .4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
  .4byte finalSetup__12ItemCreatureFv
  .4byte 0x426f6d62
  .4byte 0x47656e49
  .4byte 0x74656d00
  .4byte 0x803e1e80
  .4byte 0x2b8
  .4byte 0x803e1e88
  .4byte 0x8
  .4byte 0x803e1e90
  .4byte 0
  .4byte 0x803e1e98
  .4byte 0
  .4byte 0x803e1ea0
  .4byte 0
  .4byte 0x803e1ea8
  .4byte 0
  .4byte __RTTI__10ItemObject
  .4byte 0
  .4byte 0
.global __vt__11BombGenItem
__vt__11BombGenItem:
  .4byte __RTTI__11BombGenItem
  .4byte 0
  .4byte addCntCallback__12RefCountableFv
  .4byte subCntCallback__12RefCountableFv
  .4byte insideSafeArea__8CreatureFR8Vector3f
  .4byte platAttachable__8CreatureFv
  .4byte alwaysUpdatePlatform__8CreatureFv
  .4byte doDoAI__8CreatureFv
  .4byte setRouteTracer__8CreatureFP11RouteTracer
  .4byte init__8CreatureFv
  .4byte init__12ItemCreatureFR8Vector3f
  .4byte resetPosition__8CreatureFR8Vector3f
  .4byte initParam__8CreatureFi
  .4byte startAI__8CreatureFi
  .4byte getiMass__8CreatureFv
  .4byte getSize__8CreatureFv
  .4byte getHeight__12ItemCreatureFv
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
  .4byte isVisible__11BombGenItemFv
  .4byte isOrganic__8CreatureFv
  .4byte isTerrible__8CreatureFv
  .4byte isBuried__8CreatureFv
  .4byte isAtari__11BombGenItemFv
  .4byte isAlive__11BombGenItemFv
  .4byte isFixed__8CreatureFv
  .4byte needShadow__10ItemObjectFv
  .4byte needFlick__11BombGenItemFP8Creature
  .4byte ignoreAtari__8CreatureFP8Creature
  .4byte isFree__8CreatureFv
  .4byte stimulate__12ItemCreatureFR11Interaction
  .4byte sendMsg__8CreatureFP3Msg
  .4byte collisionCallback__10AICreatureFR9CollEvent
  .4byte bounceCallback__10AICreatureFv
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
  .4byte update__10ItemObjectFv
  .4byte postUpdate__10ItemObjectFif
  .4byte stickUpdate__8CreatureFv
  .4byte refresh__12ItemCreatureFR8Graphics
  .4byte refresh2d__8CreatureFR8Graphics
  .4byte renderAtari__8CreatureFR8Graphics
  .4byte drawShadow__8CreatureFR8Graphics
  .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
  .4byte getCatchPos__8CreatureFP8Creature
  .4byte doAI__12ItemCreatureFv
  .4byte doAnimation__12ItemCreatureFv
  .4byte doKill__12ItemCreatureFv
  .4byte exitCourse__8CreatureFv
  .4byte __RTTI__11BombGenItem
  .4byte 0xfffffd48
  .4byte 0x8007df54
  .4byte getCurrState__10AICreatureFv
  .4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
  .4byte playSound__10AICreatureFi
  .4byte playEffect__10AICreatureFi
  .4byte startMotion__12ItemCreatureFi
  .4byte finishMotion__12ItemCreatureFv
  .4byte finishMotion__12ItemCreatureFf
  .4byte startMotion__12ItemCreatureFif
  .4byte getCurrentMotionName__12ItemCreatureFv
  .4byte getCurrentMotionCounter__12ItemCreatureFv
  .4byte getMotionSpeed__12ItemCreatureFv
  .4byte setMotionSpeed__12ItemCreatureFf
  .4byte stopMotion__12ItemCreatureFv
  .4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
  .4byte finalSetup__12ItemCreatureFv
.global __vt__10ItemObject
__vt__10ItemObject:
  .4byte __RTTI__10ItemObject
  .4byte 0
  .4byte addCntCallback__12RefCountableFv
  .4byte subCntCallback__12RefCountableFv
  .4byte insideSafeArea__8CreatureFR8Vector3f
  .4byte platAttachable__8CreatureFv
  .4byte alwaysUpdatePlatform__8CreatureFv
  .4byte doDoAI__8CreatureFv
  .4byte setRouteTracer__8CreatureFP11RouteTracer
  .4byte init__8CreatureFv
  .4byte init__12ItemCreatureFR8Vector3f
  .4byte resetPosition__8CreatureFR8Vector3f
  .4byte initParam__8CreatureFi
  .4byte startAI__8CreatureFi
  .4byte getiMass__8CreatureFv
  .4byte getSize__8CreatureFv
  .4byte getHeight__12ItemCreatureFv
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
  .4byte isVisible__8CreatureFv
  .4byte isOrganic__8CreatureFv
  .4byte isTerrible__8CreatureFv
  .4byte isBuried__8CreatureFv
  .4byte isAtari__10ItemObjectFv
  .4byte isAlive__8CreatureFv
  .4byte isFixed__8CreatureFv
  .4byte needShadow__10ItemObjectFv
  .4byte needFlick__8CreatureFP8Creature
  .4byte ignoreAtari__8CreatureFP8Creature
  .4byte isFree__8CreatureFv
  .4byte stimulate__12ItemCreatureFR11Interaction
  .4byte sendMsg__8CreatureFP3Msg
  .4byte collisionCallback__10AICreatureFR9CollEvent
  .4byte bounceCallback__10AICreatureFv
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
  .4byte update__10ItemObjectFv
  .4byte postUpdate__10ItemObjectFif
  .4byte stickUpdate__8CreatureFv
  .4byte refresh__12ItemCreatureFR8Graphics
  .4byte refresh2d__8CreatureFR8Graphics
  .4byte renderAtari__8CreatureFR8Graphics
  .4byte drawShadow__8CreatureFR8Graphics
  .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
  .4byte getCatchPos__8CreatureFP8Creature
  .4byte doAI__12ItemCreatureFv
  .4byte doAnimation__12ItemCreatureFv
  .4byte doKill__12ItemCreatureFv
  .4byte exitCourse__8CreatureFv
  .4byte __RTTI__10ItemObject
  .4byte 0xfffffd48
  .4byte 0x8007df54
  .4byte getCurrState__10AICreatureFv
  .4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
  .4byte playSound__10AICreatureFi
  .4byte playEffect__10AICreatureFi
  .4byte startMotion__12ItemCreatureFi
  .4byte finishMotion__12ItemCreatureFv
  .4byte finishMotion__12ItemCreatureFf
  .4byte startMotion__12ItemCreatureFif
  .4byte getCurrentMotionName__12ItemCreatureFv
  .4byte getCurrentMotionCounter__12ItemCreatureFv
  .4byte getMotionSpeed__12ItemCreatureFv
  .4byte setMotionSpeed__12ItemCreatureFf
  .4byte stopMotion__12ItemCreatureFv
  .4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
  .4byte finalSetup__12ItemCreatureFv
  .4byte 0x4974656d
  .4byte 0x42616c6c
  .4byte 0
  .4byte 0x803e1e80
  .4byte 0x2b8
  .4byte 0x803e1e88
  .4byte 0x8
  .4byte 0x803e1e90
  .4byte 0
  .4byte 0x803e1e98
  .4byte 0
  .4byte 0x803e1ea0
  .4byte 0
  .4byte 0x803e1ea8
  .4byte 0
  .4byte 0
.global __vt__8ItemBall
__vt__8ItemBall:
  .4byte __RTTI__8ItemBall
  .4byte 0
  .4byte addCntCallback__12RefCountableFv
  .4byte subCntCallback__12RefCountableFv
  .4byte insideSafeArea__8CreatureFR8Vector3f
  .4byte platAttachable__8CreatureFv
  .4byte alwaysUpdatePlatform__8CreatureFv
  .4byte doDoAI__8CreatureFv
  .4byte setRouteTracer__8CreatureFP11RouteTracer
  .4byte init__8CreatureFv
  .4byte init__12ItemCreatureFR8Vector3f
  .4byte resetPosition__8CreatureFR8Vector3f
  .4byte initParam__8CreatureFi
  .4byte startAI__8ItemBallFi
  .4byte getiMass__8CreatureFv
  .4byte getSize__8CreatureFv
  .4byte getHeight__12ItemCreatureFv
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
  .4byte isVisible__8ItemBallFv
  .4byte isOrganic__8CreatureFv
  .4byte isTerrible__8CreatureFv
  .4byte isBuried__8CreatureFv
  .4byte isAtari__8CreatureFv
  .4byte isAlive__8ItemBallFv
  .4byte isFixed__8CreatureFv
  .4byte needShadow__8CreatureFv
  .4byte needFlick__8CreatureFP8Creature
  .4byte ignoreAtari__8CreatureFP8Creature
  .4byte isFree__8CreatureFv
  .4byte stimulate__12ItemCreatureFR11Interaction
  .4byte sendMsg__8CreatureFP3Msg
  .4byte collisionCallback__10AICreatureFR9CollEvent
  .4byte bounceCallback__10AICreatureFv
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
  .4byte update__12ItemCreatureFv
  .4byte postUpdate__8CreatureFif
  .4byte stickUpdate__8CreatureFv
  .4byte refresh__12ItemCreatureFR8Graphics
  .4byte refresh2d__8CreatureFR8Graphics
  .4byte renderAtari__8CreatureFR8Graphics
  .4byte drawShadow__8CreatureFR8Graphics
  .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
  .4byte getCatchPos__8CreatureFP8Creature
  .4byte doAI__12ItemCreatureFv
  .4byte doAnimation__12ItemCreatureFv
  .4byte doKill__12ItemCreatureFv
  .4byte exitCourse__8CreatureFv
  .4byte __RTTI__8ItemBall
  .4byte 0xfffffd48
  .4byte 0x8007df54
  .4byte getCurrState__10AICreatureFv
  .4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
  .4byte playSound__10AICreatureFi
  .4byte playEffect__10AICreatureFi
  .4byte startMotion__12ItemCreatureFi
  .4byte finishMotion__12ItemCreatureFv
  .4byte finishMotion__12ItemCreatureFf
  .4byte startMotion__12ItemCreatureFif
  .4byte getCurrentMotionName__12ItemCreatureFv
  .4byte getCurrentMotionCounter__12ItemCreatureFv
  .4byte getMotionSpeed__12ItemCreatureFv
  .4byte setMotionSpeed__12ItemCreatureFf
  .4byte stopMotion__12ItemCreatureFv
  .4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
  .4byte finalSetup__12ItemCreatureFv
  .4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global __RTTI__11UfoItemProp
__RTTI__11UfoItemProp:
  .4byte 0x802bee60
  .4byte 0x802bee6c
.global __RTTI__12GoalItemProp
__RTTI__12GoalItemProp:
  .4byte 0x802bee84
  .4byte 0x802bee94
.global __RTTI__15CreatureNodeMgr_1
__RTTI__15CreatureNodeMgr_1:
  .4byte 0x802beec8
  .4byte 0x802beed8
.global __RTTI__13MeltingPotMgr
__RTTI__13MeltingPotMgr:
  .4byte 0x802beeb8
  .4byte 0x802bef04
.global __RTTI__12CreatureNode
__RTTI__12CreatureNode:
  .4byte 0x802befb0
  .4byte 0x802befc0
.global __RTTI__12BuildingItem
__RTTI__12BuildingItem:
  .4byte 0x802bf018
  .4byte 0x802bf028
  .4byte 0x802bf1f0
  .4byte 0
  .4byte 0x802bf204
  .4byte 0
  .4byte 0x802bf210
  .4byte 0
  .4byte 0x802bf220
  .4byte 0x802bf22c
  .4byte 0x802bf240
  .4byte 0x802bf24c
  .4byte 0x802bf270
  .4byte 0x802bf280
.global __RTTI__10ItemObject
__RTTI__10ItemObject:
  .4byte 0x802bf2ac
  .4byte 0x802bf2b8
