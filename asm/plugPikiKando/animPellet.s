.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__14PelletAnimInfoFv, global
/* 80099548 000964A8  7C 08 02 A6 */	mflr r0
/* 8009954C 000964AC  3C A0 80 2B */	lis r5, lbl_802B0764@ha
/* 80099550 000964B0  90 01 00 04 */	stw r0, 4(r1)
/* 80099554 000964B4  38 A5 07 64 */	addi r5, r5, lbl_802B0764@l
/* 80099558 000964B8  94 21 FF 48 */	stwu r1, -0xb8(r1)
/* 8009955C 000964BC  93 E1 00 B4 */	stw r31, 0xb4(r1)
/* 80099560 000964C0  3B E0 00 00 */	li r31, 0
/* 80099564 000964C4  93 C1 00 B0 */	stw r30, 0xb0(r1)
/* 80099568 000964C8  3B C3 00 00 */	addi r30, r3, 0
/* 8009956C 000964CC  3C 60 80 22 */	lis r3, __vt__5ANode@ha
/* 80099570 000964D0  93 A1 00 AC */	stw r29, 0xac(r1)
/* 80099574 000964D4  38 03 73 8C */	addi r0, r3, __vt__5ANode@l
/* 80099578 000964D8  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 8009957C 000964DC  93 81 00 A8 */	stw r28, 0xa8(r1)
/* 80099580 000964E0  93 FE 00 00 */	stw r31, 0(r30)
/* 80099584 000964E4  90 1E 00 04 */	stw r0, 4(r30)
/* 80099588 000964E8  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 8009958C 000964EC  3C 60 80 2B */	lis r3, __vt__14PelletAnimInfo@ha
/* 80099590 000964F0  90 1E 00 04 */	stw r0, 4(r30)
/* 80099594 000964F4  38 83 08 70 */	addi r4, r3, __vt__14PelletAnimInfo@l
/* 80099598 000964F8  38 04 00 08 */	addi r0, r4, 8
/* 8009959C 000964FC  93 FE 00 14 */	stw r31, 0x14(r30)
/* 800995A0 00096500  38 7E 00 18 */	addi r3, r30, 0x18
/* 800995A4 00096504  93 FE 00 10 */	stw r31, 0x10(r30)
/* 800995A8 00096508  93 FE 00 0C */	stw r31, 0xc(r30)
/* 800995AC 0009650C  90 BE 00 08 */	stw r5, 8(r30)
/* 800995B0 00096510  90 9E 00 58 */	stw r4, 0x58(r30)
/* 800995B4 00096514  90 1E 00 04 */	stw r0, 4(r30)
/* 800995B8 00096518  4B FA A8 A5 */	bl __ct__4ID32Fv
/* 800995BC 0009651C  80 6D A9 50 */	lwz r3, lbl_803DF670@sda21(r13)
/* 800995C0 00096520  38 0D A9 54 */	addi r0, r13, lbl_803DF674@sda21
/* 800995C4 00096524  90 01 00 98 */	stw r0, 0x98(r1)
/* 800995C8 00096528  38 A1 00 30 */	addi r5, r1, 0x30
/* 800995CC 0009652C  38 9E 00 00 */	addi r4, r30, 0
/* 800995D0 00096530  90 61 00 6C */	stw r3, 0x6c(r1)
/* 800995D4 00096534  38 7E 00 2C */	addi r3, r30, 0x2c
/* 800995D8 00096538  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 800995DC 0009653C  93 E1 00 94 */	stw r31, 0x94(r1)
/* 800995E0 00096540  90 01 00 30 */	stw r0, 0x30(r1)
/* 800995E4 00096544  4B FC 54 9D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800995E8 00096548  3C 60 80 2A */	lis r3, "__vt__13Parm<6String>"@ha
/* 800995EC 0009654C  3B 83 60 6C */	addi r28, r3, "__vt__13Parm<6String>"@l
/* 800995F0 00096550  93 9E 00 34 */	stw r28, 0x34(r30)
/* 800995F4 00096554  38 60 00 41 */	li r3, 0x41
/* 800995F8 00096558  4B FA DA 0D */	bl alloc__6SystemFUl
/* 800995FC 0009655C  90 7E 00 3C */	stw r3, 0x3c(r30)
/* 80099600 00096560  3B A0 00 40 */	li r29, 0x40
/* 80099604 00096564  38 0D A9 60 */	addi r0, r13, lbl_803DF680@sda21
/* 80099608 00096568  93 BE 00 38 */	stw r29, 0x38(r30)
/* 8009960C 0009656C  38 A1 00 2C */	addi r5, r1, 0x2c
/* 80099610 00096570  38 9E 00 00 */	addi r4, r30, 0
/* 80099614 00096574  80 E1 00 94 */	lwz r7, 0x94(r1)
/* 80099618 00096578  38 7E 00 40 */	addi r3, r30, 0x40
/* 8009961C 0009657C  80 C1 00 98 */	lwz r6, 0x98(r1)
/* 80099620 00096580  90 FE 00 38 */	stw r7, 0x38(r30)
/* 80099624 00096584  90 DE 00 3C */	stw r6, 0x3c(r30)
/* 80099628 00096588  80 CD A9 5C */	lwz r6, lbl_803DF67C@sda21(r13)
/* 8009962C 0009658C  90 01 00 60 */	stw r0, 0x60(r1)
/* 80099630 00096590  90 C1 00 34 */	stw r6, 0x34(r1)
/* 80099634 00096594  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80099638 00096598  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 8009963C 0009659C  90 01 00 2C */	stw r0, 0x2c(r1)
/* 80099640 000965A0  4B FC 54 41 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80099644 000965A4  93 9E 00 48 */	stw r28, 0x48(r30)
/* 80099648 000965A8  38 60 00 41 */	li r3, 0x41
/* 8009964C 000965AC  4B FA D9 B9 */	bl alloc__6SystemFUl
/* 80099650 000965B0  90 7E 00 50 */	stw r3, 0x50(r30)
/* 80099654 000965B4  3C 80 6E 6F */	lis r4, 0x6E6F6E65@ha
/* 80099658 000965B8  38 7E 00 18 */	addi r3, r30, 0x18
/* 8009965C 000965BC  93 BE 00 4C */	stw r29, 0x4c(r30)
/* 80099660 000965C0  38 84 6E 65 */	addi r4, r4, 0x6E6F6E65@l
/* 80099664 000965C4  80 A1 00 5C */	lwz r5, 0x5c(r1)
/* 80099668 000965C8  80 01 00 60 */	lwz r0, 0x60(r1)
/* 8009966C 000965CC  90 BE 00 4C */	stw r5, 0x4c(r30)
/* 80099670 000965D0  90 1E 00 50 */	stw r0, 0x50(r30)
/* 80099674 000965D4  4B FA A8 51 */	bl setID__4ID32FUl
/* 80099678 000965D8  93 FE 00 24 */	stw r31, 0x24(r30)
/* 8009967C 000965DC  38 80 FF FF */	li r4, -1
/* 80099680 000965E0  3C 60 80 2B */	lis r3, lbl_802B0770@ha
/* 80099684 000965E4  90 9E 00 28 */	stw r4, 0x28(r30)
/* 80099688 000965E8  38 03 07 70 */	addi r0, r3, lbl_802B0770@l
/* 8009968C 000965EC  38 7E 00 00 */	addi r3, r30, 0
/* 80099690 000965F0  90 9E 00 54 */	stw r4, 0x54(r30)
/* 80099694 000965F4  93 FE 00 14 */	stw r31, 0x14(r30)
/* 80099698 000965F8  93 FE 00 10 */	stw r31, 0x10(r30)
/* 8009969C 000965FC  93 FE 00 0C */	stw r31, 0xc(r30)
/* 800996A0 00096600  90 1E 00 08 */	stw r0, 8(r30)
/* 800996A4 00096604  93 FE 00 5C */	stw r31, 0x5c(r30)
/* 800996A8 00096608  80 01 00 BC */	lwz r0, 0xbc(r1)
/* 800996AC 0009660C  83 E1 00 B4 */	lwz r31, 0xb4(r1)
/* 800996B0 00096610  83 C1 00 B0 */	lwz r30, 0xb0(r1)
/* 800996B4 00096614  83 A1 00 AC */	lwz r29, 0xac(r1)
/* 800996B8 00096618  83 81 00 A8 */	lwz r28, 0xa8(r1)
/* 800996BC 0009661C  38 21 00 B8 */	addi r1, r1, 0xb8
/* 800996C0 00096620  7C 08 03 A6 */	mtlr r0
/* 800996C4 00096624  4E 80 00 20 */	blr 
.endfn __ct__14PelletAnimInfoFv

.fn createShapeObject__14PelletAnimInfoFv, global
/* 800996C8 00096628  7C 08 02 A6 */	mflr r0
/* 800996CC 0009662C  90 01 00 04 */	stw r0, 4(r1)
/* 800996D0 00096630  4C C6 31 82 */	crclr 6
/* 800996D4 00096634  94 21 FD E0 */	stwu r1, -0x220(r1)
/* 800996D8 00096638  93 E1 02 1C */	stw r31, 0x21c(r1)
/* 800996DC 0009663C  93 C1 02 18 */	stw r30, 0x218(r1)
/* 800996E0 00096640  93 A1 02 14 */	stw r29, 0x214(r1)
/* 800996E4 00096644  93 81 02 10 */	stw r28, 0x210(r1)
/* 800996E8 00096648  3B 83 00 00 */	addi r28, r3, 0
/* 800996EC 0009664C  3B FC 00 4C */	addi r31, r28, 0x4c
/* 800996F0 00096650  80 C3 00 50 */	lwz r6, 0x50(r3)
/* 800996F4 00096654  3C 60 80 2B */	lis r3, lbl_802B0780@ha
/* 800996F8 00096658  38 83 07 80 */	addi r4, r3, lbl_802B0780@l
/* 800996FC 0009665C  80 BC 00 3C */	lwz r5, 0x3c(r28)
/* 80099700 00096660  3B DC 00 38 */	addi r30, r28, 0x38
/* 80099704 00096664  38 61 01 0C */	addi r3, r1, 0x10c
/* 80099708 00096668  48 17 CE 91 */	bl sprintf
/* 8009970C 0009666C  3C 60 80 3A */	lis r3, gameflow@ha
/* 80099710 00096670  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 80099714 00096674  38 81 01 0C */	addi r4, r1, 0x10c
/* 80099718 00096678  38 A0 00 01 */	li r5, 1
/* 8009971C 0009667C  4B FB 95 F5 */	bl loadShape__8GameFlowFPcb
/* 80099720 00096680  7C 7D 1B 79 */	or. r29, r3, r3
/* 80099724 00096684  41 82 00 4C */	beq .L_80099770
/* 80099728 00096688  80 BF 00 04 */	lwz r5, 4(r31)
/* 8009972C 0009668C  38 61 00 0C */	addi r3, r1, 0xc
/* 80099730 00096690  4C C6 31 82 */	crclr 6
/* 80099734 00096694  38 8D A9 68 */	addi r4, r13, lbl_803DF688@sda21
/* 80099738 00096698  48 17 CE 61 */	bl sprintf
/* 8009973C 0009669C  38 60 00 2C */	li r3, 0x2c
/* 80099740 000966A0  4B FA D8 C5 */	bl alloc__6SystemFUl
/* 80099744 000966A4  3B E3 00 00 */	addi r31, r3, 0
/* 80099748 000966A8  7F E3 FB 79 */	or. r3, r31, r31
/* 8009974C 000966AC  41 82 00 1C */	beq .L_80099768
/* 80099750 000966B0  80 DE 00 04 */	lwz r6, 4(r30)
/* 80099754 000966B4  38 BD 00 00 */	addi r5, r29, 0
/* 80099758 000966B8  81 1C 00 54 */	lwz r8, 0x54(r28)
/* 8009975C 000966BC  38 9C 00 1C */	addi r4, r28, 0x1c
/* 80099760 000966C0  38 E1 00 0C */	addi r7, r1, 0xc
/* 80099764 000966C4  48 00 00 C9 */	bl __ct__17PelletShapeObjectFPcP5ShapePcPci
.L_80099768:
/* 80099768 000966C8  93 FC 00 5C */	stw r31, 0x5c(r28)
/* 8009976C 000966CC  48 00 00 0C */	b .L_80099778
.L_80099770:
/* 80099770 000966D0  38 00 00 00 */	li r0, 0
/* 80099774 000966D4  90 1C 00 5C */	stw r0, 0x5c(r28)
.L_80099778:
/* 80099778 000966D8  80 7C 00 5C */	lwz r3, 0x5c(r28)
/* 8009977C 000966DC  80 01 02 24 */	lwz r0, 0x224(r1)
/* 80099780 000966E0  83 E1 02 1C */	lwz r31, 0x21c(r1)
/* 80099784 000966E4  83 C1 02 18 */	lwz r30, 0x218(r1)
/* 80099788 000966E8  83 A1 02 14 */	lwz r29, 0x214(r1)
/* 8009978C 000966EC  83 81 02 10 */	lwz r28, 0x210(r1)
/* 80099790 000966F0  38 21 02 20 */	addi r1, r1, 0x220
/* 80099794 000966F4  7C 08 03 A6 */	mtlr r0
/* 80099798 000966F8  4E 80 00 20 */	blr 
.endfn createShapeObject__14PelletAnimInfoFv

.fn read__14PelletAnimInfoFR18RandomAccessStream, global
/* 8009979C 000966FC  7C 08 02 A6 */	mflr r0
/* 800997A0 00096700  90 01 00 04 */	stw r0, 4(r1)
/* 800997A4 00096704  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800997A8 00096708  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800997AC 0009670C  3B E4 00 00 */	addi r31, r4, 0
/* 800997B0 00096710  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800997B4 00096714  3B C3 00 00 */	addi r30, r3, 0
/* 800997B8 00096718  38 7E 00 18 */	addi r3, r30, 0x18
/* 800997BC 0009671C  4B FA A8 E1 */	bl read__4ID32FR18RandomAccessStream
/* 800997C0 00096720  7F E3 FB 78 */	mr r3, r31
/* 800997C4 00096724  81 9F 00 04 */	lwz r12, 4(r31)
/* 800997C8 00096728  81 8C 00 08 */	lwz r12, 8(r12)
/* 800997CC 0009672C  7D 88 03 A6 */	mtlr r12
/* 800997D0 00096730  4E 80 00 21 */	blrl 
/* 800997D4 00096734  90 7E 00 24 */	stw r3, 0x24(r30)
/* 800997D8 00096738  7F E3 FB 78 */	mr r3, r31
/* 800997DC 0009673C  81 9F 00 04 */	lwz r12, 4(r31)
/* 800997E0 00096740  81 8C 00 08 */	lwz r12, 8(r12)
/* 800997E4 00096744  7D 88 03 A6 */	mtlr r12
/* 800997E8 00096748  4E 80 00 21 */	blrl 
/* 800997EC 0009674C  90 7E 00 28 */	stw r3, 0x28(r30)
/* 800997F0 00096750  7F E3 FB 78 */	mr r3, r31
/* 800997F4 00096754  81 9F 00 04 */	lwz r12, 4(r31)
/* 800997F8 00096758  81 8C 00 08 */	lwz r12, 8(r12)
/* 800997FC 0009675C  7D 88 03 A6 */	mtlr r12
/* 80099800 00096760  4E 80 00 21 */	blrl 
/* 80099804 00096764  90 7E 00 54 */	stw r3, 0x54(r30)
/* 80099808 00096768  38 7E 00 00 */	addi r3, r30, 0
/* 8009980C 0009676C  38 9F 00 00 */	addi r4, r31, 0
/* 80099810 00096770  4B FC 53 89 */	bl read__10ParametersFR18RandomAccessStream
/* 80099814 00096774  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80099818 00096778  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8009981C 0009677C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80099820 00096780  38 21 00 18 */	addi r1, r1, 0x18
/* 80099824 00096784  7C 08 03 A6 */	mtlr r0
/* 80099828 00096788  4E 80 00 20 */	blr 
.endfn read__14PelletAnimInfoFR18RandomAccessStream

.fn __ct__17PelletShapeObjectFPcP5ShapePcPci, global
/* 8009982C 0009678C  7C 08 02 A6 */	mflr r0
/* 80099830 00096790  3D 20 80 23 */	lis r9, __vt__11AnimContext@ha
/* 80099834 00096794  90 01 00 04 */	stw r0, 4(r1)
/* 80099838 00096798  38 00 00 00 */	li r0, 0
/* 8009983C 0009679C  28 06 00 00 */	cmplwi r6, 0
/* 80099840 000967A0  94 21 FF 48 */	stwu r1, -0xb8(r1)
/* 80099844 000967A4  BF 61 00 A4 */	stmw r27, 0xa4(r1)
/* 80099848 000967A8  3B C3 00 00 */	addi r30, r3, 0
/* 8009984C 000967AC  38 69 88 D0 */	addi r3, r9, __vt__11AnimContext@l
/* 80099850 000967B0  3B 85 00 00 */	addi r28, r5, 0
/* 80099854 000967B4  7C 9B 23 78 */	mr r27, r4
/* 80099858 000967B8  7D 1F 43 78 */	mr r31, r8
/* 8009985C 000967BC  90 7E 00 14 */	stw r3, 0x14(r30)
/* 80099860 000967C0  90 1E 00 08 */	stw r0, 8(r30)
/* 80099864 000967C4  C0 22 8C 90 */	lfs f1, lbl_803E8E90@sda21(r2)
/* 80099868 000967C8  D0 3E 00 0C */	stfs f1, 0xc(r30)
/* 8009986C 000967CC  C0 02 8C 94 */	lfs f0, lbl_803E8E94@sda21(r2)
/* 80099870 000967D0  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 80099874 000967D4  90 7E 00 24 */	stw r3, 0x24(r30)
/* 80099878 000967D8  90 1E 00 18 */	stw r0, 0x18(r30)
/* 8009987C 000967DC  D0 3E 00 1C */	stfs f1, 0x1c(r30)
/* 80099880 000967E0  D0 1E 00 20 */	stfs f0, 0x20(r30)
/* 80099884 000967E4  93 9E 00 00 */	stw r28, 0(r30)
/* 80099888 000967E8  80 7E 00 00 */	lwz r3, 0(r30)
/* 8009988C 000967EC  90 03 00 24 */	stw r0, 0x24(r3)
/* 80099890 000967F0  41 82 00 5C */	beq .L_800998EC
/* 80099894 000967F4  3C 60 80 2B */	lis r3, lbl_802B0794@ha
/* 80099898 000967F8  4C C6 31 82 */	crclr 6
/* 8009989C 000967FC  38 83 07 94 */	addi r4, r3, lbl_802B0794@l
/* 800998A0 00096800  38 A6 00 00 */	addi r5, r6, 0
/* 800998A4 00096804  38 C7 00 00 */	addi r6, r7, 0
/* 800998A8 00096808  38 61 00 20 */	addi r3, r1, 0x20
/* 800998AC 0009680C  48 17 CC ED */	bl sprintf
/* 800998B0 00096810  38 60 00 B8 */	li r3, 0xb8
/* 800998B4 00096814  4B FA D7 51 */	bl alloc__6SystemFUl
/* 800998B8 00096818  3B A3 00 00 */	addi r29, r3, 0
/* 800998BC 0009681C  7F A3 EB 79 */	or. r3, r29, r29
/* 800998C0 00096820  41 82 00 1C */	beq .L_800998DC
/* 800998C4 00096824  3C C0 00 01 */	lis r6, 0x00008000@ha
/* 800998C8 00096828  38 9C 00 00 */	addi r4, r28, 0
/* 800998CC 0009682C  38 A1 00 20 */	addi r5, r1, 0x20
/* 800998D0 00096830  38 C6 80 00 */	addi r6, r6, 0x00008000@l
/* 800998D4 00096834  38 E0 00 00 */	li r7, 0
/* 800998D8 00096838  4B FB 6F CD */	bl __ct__7AnimMgrFP5ShapePciPc
.L_800998DC:
/* 800998DC 0009683C  93 BE 00 04 */	stw r29, 4(r30)
/* 800998E0 00096840  80 7E 00 04 */	lwz r3, 4(r30)
/* 800998E4 00096844  93 63 00 04 */	stw r27, 4(r3)
/* 800998E8 00096848  48 00 00 30 */	b .L_80099918
.L_800998EC:
/* 800998EC 0009684C  38 60 00 B8 */	li r3, 0xb8
/* 800998F0 00096850  4B FA D7 15 */	bl alloc__6SystemFUl
/* 800998F4 00096854  3B A3 00 00 */	addi r29, r3, 0
/* 800998F8 00096858  7F A3 EB 79 */	or. r3, r29, r29
/* 800998FC 0009685C  41 82 00 18 */	beq .L_80099914
/* 80099900 00096860  38 9C 00 00 */	addi r4, r28, 0
/* 80099904 00096864  38 A0 00 00 */	li r5, 0
/* 80099908 00096868  38 C0 00 00 */	li r6, 0
/* 8009990C 0009686C  38 E0 00 00 */	li r7, 0
/* 80099910 00096870  4B FB 6F 95 */	bl __ct__7AnimMgrFP5ShapePciPc
.L_80099914:
/* 80099914 00096874  93 BE 00 04 */	stw r29, 4(r30)
.L_80099918:
/* 80099918 00096878  80 7E 00 00 */	lwz r3, 0(r30)
/* 8009991C 0009687C  38 BE 00 08 */	addi r5, r30, 8
/* 80099920 00096880  38 80 00 00 */	li r4, 0
/* 80099924 00096884  4B F9 B7 41 */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 80099928 00096888  38 00 00 01 */	li r0, 1
/* 8009992C 0009688C  2C 1F FF FF */	cmpwi r31, -1
/* 80099930 00096890  98 1E 00 28 */	stb r0, 0x28(r30)
/* 80099934 00096894  41 82 00 20 */	beq .L_80099954
/* 80099938 00096898  80 7E 00 00 */	lwz r3, 0(r30)
/* 8009993C 0009689C  38 9F 00 00 */	addi r4, r31, 0
/* 80099940 000968A0  38 BE 00 18 */	addi r5, r30, 0x18
/* 80099944 000968A4  4B F9 B7 21 */	bl overrideAnim__9BaseShapeFiP11AnimContext
/* 80099948 000968A8  88 1E 00 28 */	lbz r0, 0x28(r30)
/* 8009994C 000968AC  60 00 00 02 */	ori r0, r0, 2
/* 80099950 000968B0  98 1E 00 28 */	stb r0, 0x28(r30)
.L_80099954:
/* 80099954 000968B4  7F C3 F3 78 */	mr r3, r30
/* 80099958 000968B8  BB 61 00 A4 */	lmw r27, 0xa4(r1)
/* 8009995C 000968BC  80 01 00 BC */	lwz r0, 0xbc(r1)
/* 80099960 000968C0  38 21 00 B8 */	addi r1, r1, 0xb8
/* 80099964 000968C4  7C 08 03 A6 */	mtlr r0
/* 80099968 000968C8  4E 80 00 20 */	blr 
.endfn __ct__17PelletShapeObjectFPcP5ShapePcPci

.fn __ct__14PelletAnimatorFv, global
/* 8009996C 000968CC  7C 08 02 A6 */	mflr r0
/* 80099970 000968D0  90 01 00 04 */	stw r0, 4(r1)
/* 80099974 000968D4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80099978 000968D8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8009997C 000968DC  7C 7F 1B 78 */	mr r31, r3
/* 80099980 000968E0  48 00 03 59 */	bl __ct__18PaniPelletAnimatorFv
/* 80099984 000968E4  38 7F 00 54 */	addi r3, r31, 0x54
/* 80099988 000968E8  48 00 03 51 */	bl __ct__18PaniPelletAnimatorFv
/* 8009998C 000968EC  7F E3 FB 78 */	mr r3, r31
/* 80099990 000968F0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80099994 000968F4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80099998 000968F8  38 21 00 18 */	addi r1, r1, 0x18
/* 8009999C 000968FC  7C 08 03 A6 */	mtlr r0
/* 800999A0 00096900  4E 80 00 20 */	blr 
.endfn __ct__14PelletAnimatorFv

.fn init__14PelletAnimatorFP11AnimContextP11AnimContextP7AnimMgrP15PaniMotionTable, global
/* 800999A4 00096904  7C 08 02 A6 */	mflr r0
/* 800999A8 00096908  90 01 00 04 */	stw r0, 4(r1)
/* 800999AC 0009690C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800999B0 00096910  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800999B4 00096914  3B E7 00 00 */	addi r31, r7, 0
/* 800999B8 00096918  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800999BC 0009691C  3B C6 00 00 */	addi r30, r6, 0
/* 800999C0 00096920  38 DF 00 00 */	addi r6, r31, 0
/* 800999C4 00096924  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800999C8 00096928  3B A5 00 00 */	addi r29, r5, 0
/* 800999CC 0009692C  38 BE 00 00 */	addi r5, r30, 0
/* 800999D0 00096930  93 81 00 20 */	stw r28, 0x20(r1)
/* 800999D4 00096934  3B 83 00 00 */	addi r28, r3, 0
/* 800999D8 00096938  48 08 57 4D */	bl init__12PaniAnimatorFP11AnimContextP7AnimMgrP15PaniMotionTable
/* 800999DC 0009693C  38 9D 00 00 */	addi r4, r29, 0
/* 800999E0 00096940  38 BE 00 00 */	addi r5, r30, 0
/* 800999E4 00096944  38 DF 00 00 */	addi r6, r31, 0
/* 800999E8 00096948  38 7C 00 54 */	addi r3, r28, 0x54
/* 800999EC 0009694C  48 08 57 39 */	bl init__12PaniAnimatorFP11AnimContextP7AnimMgrP15PaniMotionTable
/* 800999F0 00096950  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800999F4 00096954  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800999F8 00096958  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800999FC 0009695C  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 80099A00 00096960  83 81 00 20 */	lwz r28, 0x20(r1)
/* 80099A04 00096964  38 21 00 30 */	addi r1, r1, 0x30
/* 80099A08 00096968  7C 08 03 A6 */	mtlr r0
/* 80099A0C 0009696C  4E 80 00 20 */	blr 
.endfn init__14PelletAnimatorFP11AnimContextP11AnimContextP7AnimMgrP15PaniMotionTable

.fn finishMotion__14PelletAnimatorFP14PaniMotionInfoP14PaniMotionInfo, global
/* 80099A10 00096970  7C 08 02 A6 */	mflr r0
/* 80099A14 00096974  28 04 00 00 */	cmplwi r4, 0
/* 80099A18 00096978  90 01 00 04 */	stw r0, 4(r1)
/* 80099A1C 0009697C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80099A20 00096980  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80099A24 00096984  3B E5 00 00 */	addi r31, r5, 0
/* 80099A28 00096988  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80099A2C 0009698C  3B C3 00 00 */	addi r30, r3, 0
/* 80099A30 00096990  41 82 00 0C */	beq .L_80099A3C
/* 80099A34 00096994  7F C3 F3 78 */	mr r3, r30
/* 80099A38 00096998  48 08 57 F9 */	bl finishMotion__12PaniAnimatorFR14PaniMotionInfo
.L_80099A3C:
/* 80099A3C 0009699C  28 1F 00 00 */	cmplwi r31, 0
/* 80099A40 000969A0  41 82 00 10 */	beq .L_80099A50
/* 80099A44 000969A4  38 7E 00 54 */	addi r3, r30, 0x54
/* 80099A48 000969A8  38 9F 00 00 */	addi r4, r31, 0
/* 80099A4C 000969AC  48 08 57 E5 */	bl finishMotion__12PaniAnimatorFR14PaniMotionInfo
.L_80099A50:
/* 80099A50 000969B0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80099A54 000969B4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80099A58 000969B8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80099A5C 000969BC  38 21 00 20 */	addi r1, r1, 0x20
/* 80099A60 000969C0  7C 08 03 A6 */	mtlr r0
/* 80099A64 000969C4  4E 80 00 20 */	blr 
.endfn finishMotion__14PelletAnimatorFP14PaniMotionInfoP14PaniMotionInfo

.fn startMotion__14PelletAnimatorFR14PaniMotionInfoR14PaniMotionInfo, global
/* 80099A68 000969C8  7C 08 02 A6 */	mflr r0
/* 80099A6C 000969CC  28 04 00 00 */	cmplwi r4, 0
/* 80099A70 000969D0  90 01 00 04 */	stw r0, 4(r1)
/* 80099A74 000969D4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80099A78 000969D8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80099A7C 000969DC  3B E5 00 00 */	addi r31, r5, 0
/* 80099A80 000969E0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80099A84 000969E4  3B C3 00 00 */	addi r30, r3, 0
/* 80099A88 000969E8  41 82 00 0C */	beq .L_80099A94
/* 80099A8C 000969EC  7F C3 F3 78 */	mr r3, r30
/* 80099A90 000969F0  48 08 57 31 */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
.L_80099A94:
/* 80099A94 000969F4  28 1F 00 00 */	cmplwi r31, 0
/* 80099A98 000969F8  41 82 00 10 */	beq .L_80099AA8
/* 80099A9C 000969FC  38 7E 00 54 */	addi r3, r30, 0x54
/* 80099AA0 00096A00  38 9F 00 00 */	addi r4, r31, 0
/* 80099AA4 00096A04  48 08 57 1D */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
.L_80099AA8:
/* 80099AA8 00096A08  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80099AAC 00096A0C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80099AB0 00096A10  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80099AB4 00096A14  38 21 00 20 */	addi r1, r1, 0x20
/* 80099AB8 00096A18  7C 08 03 A6 */	mtlr r0
/* 80099ABC 00096A1C  4E 80 00 20 */	blr 
.endfn startMotion__14PelletAnimatorFR14PaniMotionInfoR14PaniMotionInfo

.fn startMotion__14PelletAnimatorFR14PaniMotionInfo, global
/* 80099AC0 00096A20  7C 08 02 A6 */	mflr r0
/* 80099AC4 00096A24  28 04 00 00 */	cmplwi r4, 0
/* 80099AC8 00096A28  90 01 00 04 */	stw r0, 4(r1)
/* 80099ACC 00096A2C  94 21 FF F8 */	stwu r1, -8(r1)
/* 80099AD0 00096A30  41 82 00 08 */	beq .L_80099AD8
/* 80099AD4 00096A34  48 08 56 ED */	bl startMotion__12PaniAnimatorFR14PaniMotionInfo
.L_80099AD8:
/* 80099AD8 00096A38  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80099ADC 00096A3C  38 21 00 08 */	addi r1, r1, 8
/* 80099AE0 00096A40  7C 08 03 A6 */	mtlr r0
/* 80099AE4 00096A44  4E 80 00 20 */	blr 
.endfn startMotion__14PelletAnimatorFR14PaniMotionInfo

.fn updateAnimation__14PelletAnimatorFff, global
/* 80099AE8 00096A48  7C 08 02 A6 */	mflr r0
/* 80099AEC 00096A4C  90 01 00 04 */	stw r0, 4(r1)
/* 80099AF0 00096A50  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80099AF4 00096A54  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80099AF8 00096A58  FF E0 10 90 */	fmr f31, f2
/* 80099AFC 00096A5C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80099B00 00096A60  7C 7F 1B 78 */	mr r31, r3
/* 80099B04 00096A64  81 9F 00 30 */	lwz r12, 0x30(r31)
/* 80099B08 00096A68  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80099B0C 00096A6C  7D 88 03 A6 */	mtlr r12
/* 80099B10 00096A70  4E 80 00 21 */	blrl 
/* 80099B14 00096A74  38 7F 00 54 */	addi r3, r31, 0x54
/* 80099B18 00096A78  FC 20 F8 90 */	fmr f1, f31
/* 80099B1C 00096A7C  81 9F 00 84 */	lwz r12, 0x84(r31)
/* 80099B20 00096A80  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80099B24 00096A84  7D 88 03 A6 */	mtlr r12
/* 80099B28 00096A88  4E 80 00 21 */	blrl 
/* 80099B2C 00096A8C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80099B30 00096A90  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80099B34 00096A94  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80099B38 00096A98  38 21 00 28 */	addi r1, r1, 0x28
/* 80099B3C 00096A9C  7C 08 03 A6 */	mtlr r0
/* 80099B40 00096AA0  4E 80 00 20 */	blr 
.endfn updateAnimation__14PelletAnimatorFff

.fn updateContext__14PelletAnimatorFv, global
/* 80099B44 00096AA4  7C 08 02 A6 */	mflr r0
/* 80099B48 00096AA8  90 01 00 04 */	stw r0, 4(r1)
/* 80099B4C 00096AAC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80099B50 00096AB0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80099B54 00096AB4  7C 7F 1B 78 */	mr r31, r3
/* 80099B58 00096AB8  81 9F 00 30 */	lwz r12, 0x30(r31)
/* 80099B5C 00096ABC  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80099B60 00096AC0  7D 88 03 A6 */	mtlr r12
/* 80099B64 00096AC4  4E 80 00 21 */	blrl 
/* 80099B68 00096AC8  38 7F 00 54 */	addi r3, r31, 0x54
/* 80099B6C 00096ACC  81 9F 00 84 */	lwz r12, 0x84(r31)
/* 80099B70 00096AD0  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80099B74 00096AD4  7D 88 03 A6 */	mtlr r12
/* 80099B78 00096AD8  4E 80 00 21 */	blrl 
/* 80099B7C 00096ADC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80099B80 00096AE0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80099B84 00096AE4  38 21 00 18 */	addi r1, r1, 0x18
/* 80099B88 00096AE8  7C 08 03 A6 */	mtlr r0
/* 80099B8C 00096AEC  4E 80 00 20 */	blr 
.endfn updateContext__14PelletAnimatorFv

.fn createMotionTable__18PaniPelletAnimatorFv, global
/* 80099B90 00096AF0  7C 08 02 A6 */	mflr r0
/* 80099B94 00096AF4  38 60 00 08 */	li r3, 8
/* 80099B98 00096AF8  90 01 00 04 */	stw r0, 4(r1)
/* 80099B9C 00096AFC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80099BA0 00096B00  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80099BA4 00096B04  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80099BA8 00096B08  4B FA D4 5D */	bl alloc__6SystemFUl
/* 80099BAC 00096B0C  3B E3 00 00 */	addi r31, r3, 0
/* 80099BB0 00096B10  7F E3 FB 79 */	or. r3, r31, r31
/* 80099BB4 00096B14  41 82 00 0C */	beq .L_80099BC0
/* 80099BB8 00096B18  38 80 00 07 */	li r4, 7
/* 80099BBC 00096B1C  48 08 54 4D */	bl __ct__15PaniMotionTableFi
.L_80099BC0:
/* 80099BC0 00096B20  38 60 00 08 */	li r3, 8
/* 80099BC4 00096B24  4B FA D4 41 */	bl alloc__6SystemFUl
/* 80099BC8 00096B28  3B C3 00 00 */	addi r30, r3, 0
/* 80099BCC 00096B2C  7F C3 F3 79 */	or. r3, r30, r30
/* 80099BD0 00096B30  41 82 00 0C */	beq .L_80099BDC
/* 80099BD4 00096B34  38 80 00 00 */	li r4, 0
/* 80099BD8 00096B38  48 08 53 F1 */	bl __ct__10PaniMotionFi
.L_80099BDC:
/* 80099BDC 00096B3C  80 9F 00 04 */	lwz r4, 4(r31)
/* 80099BE0 00096B40  38 60 00 08 */	li r3, 8
/* 80099BE4 00096B44  93 C4 00 00 */	stw r30, 0(r4)
/* 80099BE8 00096B48  4B FA D4 1D */	bl alloc__6SystemFUl
/* 80099BEC 00096B4C  3B C3 00 00 */	addi r30, r3, 0
/* 80099BF0 00096B50  7F C3 F3 79 */	or. r3, r30, r30
/* 80099BF4 00096B54  41 82 00 0C */	beq .L_80099C00
/* 80099BF8 00096B58  38 80 00 01 */	li r4, 1
/* 80099BFC 00096B5C  48 08 53 CD */	bl __ct__10PaniMotionFi
.L_80099C00:
/* 80099C00 00096B60  80 9F 00 04 */	lwz r4, 4(r31)
/* 80099C04 00096B64  38 60 00 08 */	li r3, 8
/* 80099C08 00096B68  93 C4 00 04 */	stw r30, 4(r4)
/* 80099C0C 00096B6C  4B FA D3 F9 */	bl alloc__6SystemFUl
/* 80099C10 00096B70  3B C3 00 00 */	addi r30, r3, 0
/* 80099C14 00096B74  7F C3 F3 79 */	or. r3, r30, r30
/* 80099C18 00096B78  41 82 00 0C */	beq .L_80099C24
/* 80099C1C 00096B7C  38 80 00 02 */	li r4, 2
/* 80099C20 00096B80  48 08 53 A9 */	bl __ct__10PaniMotionFi
.L_80099C24:
/* 80099C24 00096B84  80 9F 00 04 */	lwz r4, 4(r31)
/* 80099C28 00096B88  38 60 00 08 */	li r3, 8
/* 80099C2C 00096B8C  93 C4 00 08 */	stw r30, 8(r4)
/* 80099C30 00096B90  4B FA D3 D5 */	bl alloc__6SystemFUl
/* 80099C34 00096B94  3B C3 00 00 */	addi r30, r3, 0
/* 80099C38 00096B98  7F C3 F3 79 */	or. r3, r30, r30
/* 80099C3C 00096B9C  41 82 00 0C */	beq .L_80099C48
/* 80099C40 00096BA0  38 80 00 03 */	li r4, 3
/* 80099C44 00096BA4  48 08 53 85 */	bl __ct__10PaniMotionFi
.L_80099C48:
/* 80099C48 00096BA8  80 9F 00 04 */	lwz r4, 4(r31)
/* 80099C4C 00096BAC  38 60 00 08 */	li r3, 8
/* 80099C50 00096BB0  93 C4 00 0C */	stw r30, 0xc(r4)
/* 80099C54 00096BB4  4B FA D3 B1 */	bl alloc__6SystemFUl
/* 80099C58 00096BB8  3B C3 00 00 */	addi r30, r3, 0
/* 80099C5C 00096BBC  7F C3 F3 79 */	or. r3, r30, r30
/* 80099C60 00096BC0  41 82 00 0C */	beq .L_80099C6C
/* 80099C64 00096BC4  38 80 00 04 */	li r4, 4
/* 80099C68 00096BC8  48 08 53 61 */	bl __ct__10PaniMotionFi
.L_80099C6C:
/* 80099C6C 00096BCC  80 9F 00 04 */	lwz r4, 4(r31)
/* 80099C70 00096BD0  38 60 00 08 */	li r3, 8
/* 80099C74 00096BD4  93 C4 00 10 */	stw r30, 0x10(r4)
/* 80099C78 00096BD8  4B FA D3 8D */	bl alloc__6SystemFUl
/* 80099C7C 00096BDC  3B C3 00 00 */	addi r30, r3, 0
/* 80099C80 00096BE0  7F C3 F3 79 */	or. r3, r30, r30
/* 80099C84 00096BE4  41 82 00 0C */	beq .L_80099C90
/* 80099C88 00096BE8  38 80 00 05 */	li r4, 5
/* 80099C8C 00096BEC  48 08 53 3D */	bl __ct__10PaniMotionFi
.L_80099C90:
/* 80099C90 00096BF0  80 9F 00 04 */	lwz r4, 4(r31)
/* 80099C94 00096BF4  38 60 00 08 */	li r3, 8
/* 80099C98 00096BF8  93 C4 00 14 */	stw r30, 0x14(r4)
/* 80099C9C 00096BFC  4B FA D3 69 */	bl alloc__6SystemFUl
/* 80099CA0 00096C00  3B C3 00 00 */	addi r30, r3, 0
/* 80099CA4 00096C04  7F C3 F3 79 */	or. r3, r30, r30
/* 80099CA8 00096C08  41 82 00 0C */	beq .L_80099CB4
/* 80099CAC 00096C0C  38 80 00 06 */	li r4, 6
/* 80099CB0 00096C10  48 08 53 19 */	bl __ct__10PaniMotionFi
.L_80099CB4:
/* 80099CB4 00096C14  80 9F 00 04 */	lwz r4, 4(r31)
/* 80099CB8 00096C18  7F E3 FB 78 */	mr r3, r31
/* 80099CBC 00096C1C  93 C4 00 18 */	stw r30, 0x18(r4)
/* 80099CC0 00096C20  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80099CC4 00096C24  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80099CC8 00096C28  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80099CCC 00096C2C  38 21 00 18 */	addi r1, r1, 0x18
/* 80099CD0 00096C30  7C 08 03 A6 */	mtlr r0
/* 80099CD4 00096C34  4E 80 00 20 */	blr 
.endfn createMotionTable__18PaniPelletAnimatorFv

.fn __ct__18PaniPelletAnimatorFv, global
/* 80099CD8 00096C38  7C 08 02 A6 */	mflr r0
/* 80099CDC 00096C3C  90 01 00 04 */	stw r0, 4(r1)
/* 80099CE0 00096C40  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80099CE4 00096C44  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80099CE8 00096C48  7C 7F 1B 78 */	mr r31, r3
/* 80099CEC 00096C4C  48 08 53 F5 */	bl __ct__12PaniAnimatorFv
/* 80099CF0 00096C50  3C 60 80 2B */	lis r3, __vt__18PaniPelletAnimator@ha
/* 80099CF4 00096C54  38 03 08 10 */	addi r0, r3, __vt__18PaniPelletAnimator@l
/* 80099CF8 00096C58  90 1F 00 30 */	stw r0, 0x30(r31)
/* 80099CFC 00096C5C  7F E3 FB 78 */	mr r3, r31
/* 80099D00 00096C60  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80099D04 00096C64  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80099D08 00096C68  38 21 00 18 */	addi r1, r1, 0x18
/* 80099D0C 00096C6C  7C 08 03 A6 */	mtlr r0
/* 80099D10 00096C70  4E 80 00 20 */	blr 
.endfn __ct__18PaniPelletAnimatorFv

.fn "@4@read__14PelletAnimInfoFR18RandomAccessStream", weak
/* 80099D14 00096C74  38 63 FF FC */	addi r3, r3, -4
/* 80099D18 00096C78  4B FF FA 84 */	b read__14PelletAnimInfoFR18RandomAccessStream
.endfn "@4@read__14PelletAnimInfoFR18RandomAccessStream"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B0748, local
	.asciz "animPellet.cpp"
.endobj lbl_802B0748
.balign 4
.obj lbl_802B0758, local
	.asciz "animPellet"
.endobj lbl_802B0758
.balign 4
.obj lbl_802B0764, local
	.asciz "CoreNode"
.endobj lbl_802B0764
.balign 4
.obj lbl_802B0770, local
	.asciz "pelletAnimInfo"
.endobj lbl_802B0770
.balign 4
.obj lbl_802B0780, local
	.asciz "objects/%s/%s.mod"
.endobj lbl_802B0780
.balign 4
.obj lbl_802B0794, local
	.asciz "objects/%s/%s"
.endobj lbl_802B0794
.balign 4
.obj motionLabels__18PaniPelletAnimator, global
	.4byte lbl_803DF690
	.4byte lbl_803DF698
	.4byte lbl_803DF6A0
	.4byte lbl_803DF6A4
	.4byte lbl_803DF6A8
	.4byte lbl_803DF6AC
	.4byte lbl_803DF6B0
.endobj motionLabels__18PaniPelletAnimator
.balign 4
.obj lbl_802B07C0, local
	.asciz "PaniPelletAnimator"
.endobj lbl_802B07C0
.balign 4
.obj lbl_802B07D4, local
	.asciz "Animator"
.endobj lbl_802B07D4
.balign 4
.obj lbl_802B07E0, local
	.asciz "PaniAnimator"
.endobj lbl_802B07E0
.balign 4
.obj lbl_802B07F0, local
	.4byte __RTTI__8Animator
	.4byte 0
	.4byte 0
.endobj lbl_802B07F0
.balign 4
.obj lbl_802B07FC, local
	.4byte __RTTI__8Animator
	.4byte 0
	.4byte __RTTI__12PaniAnimator
	.4byte 0
	.4byte 0
.endobj lbl_802B07FC
.balign 4
.obj __vt__18PaniPelletAnimator, weak
	.4byte __RTTI__18PaniPelletAnimator
	.4byte 0
	.4byte changeContext__12PaniAnimatorFP11AnimContext
	.4byte animate__12PaniAnimatorFf
	.4byte finishOneShot__8AnimatorFv
	.4byte finishLoop__8AnimatorFv
	.4byte updateContext__12PaniAnimatorFv
.endobj __vt__18PaniPelletAnimator
.balign 4
.obj lbl_802B082C, local
	.asciz "PelletAnimInfo"
.endobj lbl_802B082C
.balign 4
.obj lbl_802B083C, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.endobj lbl_802B083C
.balign 4
.obj lbl_802B0848, local
	.asciz "Parameters"
.endobj lbl_802B0848
.balign 4
.obj lbl_802B0854, local
	.4byte __RTTI__5ANode
	.4byte 0x4
	.4byte __RTTI__8CoreNode
	.4byte 0x4
	.4byte __RTTI__10Parameters
	.4byte 0
	.4byte 0
.endobj lbl_802B0854
.balign 4
.obj __vt__14PelletAnimInfo, global
	.4byte __RTTI__14PelletAnimInfo
	.4byte 0
	.4byte __RTTI__14PelletAnimInfo
	.4byte 0xFFFFFFFC
	.4byte getAgeNodeType__5ANodeFv
	.4byte "@4@read__14PelletAnimInfoFR18RandomAccessStream"
	.4byte read__14PelletAnimInfoFR18RandomAccessStream
.endobj __vt__14PelletAnimInfo
.balign 4
.obj lbl_802B088C, local
	.asciz "Parm<String>"
.endobj lbl_802B088C
.balign 4
.obj lbl_802B089C, local
	.asciz "BaseParm"
.endobj lbl_802B089C
.balign 4
.obj lbl_802B08A8, local
	.4byte __RTTI__8BaseParm
	.4byte 0
	.4byte 0
.endobj lbl_802B08A8
.balign 4
.skip 0x34 # compiler padding

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DF670, local
	.asciz "x00"
.endobj lbl_803DF670
.balign 4
.obj lbl_803DF674, local
	.asciz "pellets"
.endobj lbl_803DF674
.balign 4
.obj lbl_803DF67C, local
	.asciz "x01"
.endobj lbl_803DF67C
.balign 4
.obj lbl_803DF680, local
	.asciz "noname"
.endobj lbl_803DF680
.balign 4
.obj lbl_803DF688, local
	.asciz "%s.bin"
.endobj lbl_803DF688
.balign 4
.obj lbl_803DF690, local
	.asciz "Carry"
.endobj lbl_803DF690
.balign 4
.obj lbl_803DF698, local
	.asciz "Appear"
.endobj lbl_803DF698
.balign 4
.obj lbl_803DF6A0, local
	.asciz "3"
.endobj lbl_803DF6A0
.balign 4
.obj lbl_803DF6A4, local
	.asciz "4"
.endobj lbl_803DF6A4
.balign 4
.obj lbl_803DF6A8, local
	.asciz "5"
.endobj lbl_803DF6A8
.balign 4
.obj lbl_803DF6AC, local
	.asciz "6"
.endobj lbl_803DF6AC
.balign 4
.obj lbl_803DF6B0, local
	.asciz "7"
.endobj lbl_803DF6B0
.balign 4
.obj __RTTI__8Animator, local
	.4byte lbl_802B07D4
	.4byte 0
.endobj __RTTI__8Animator
.balign 4
.obj __RTTI__12PaniAnimator, local
	.4byte lbl_802B07E0
	.4byte lbl_802B07F0
.endobj __RTTI__12PaniAnimator
.balign 4
.obj __RTTI__18PaniPelletAnimator, local
	.4byte lbl_802B07C0
	.4byte lbl_802B07FC
.endobj __RTTI__18PaniPelletAnimator
.balign 4
.obj lbl_803DF6CC, local
	.asciz "ANode"
.endobj lbl_803DF6CC
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803DF6CC
	.4byte 0
.endobj __RTTI__5ANode
.balign 4
.obj __RTTI__8CoreNode, local
	.4byte lbl_802B0764
	.4byte lbl_802B083C
.endobj __RTTI__8CoreNode
.balign 4
.obj __RTTI__10Parameters, local
	.4byte lbl_802B0848
	.4byte 0
.endobj __RTTI__10Parameters
.balign 4
.obj __RTTI__14PelletAnimInfo, local
	.4byte lbl_802B082C
	.4byte lbl_802B0854
.endobj __RTTI__14PelletAnimInfo
.balign 4
.obj __RTTI__8BaseParm, local
	.4byte lbl_802B089C
	.4byte 0
.endobj __RTTI__8BaseParm

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E8E90, local
	.float 0.0
.endobj lbl_803E8E90
.balign 4
.obj lbl_803E8E94, local
	.float 30.0
.endobj lbl_803E8E94
