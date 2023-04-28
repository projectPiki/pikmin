.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn ldexp, global
/* 8021B570 002184D0  7C 08 02 A6 */	mflr r0
/* 8021B574 002184D4  90 01 00 04 */	stw r0, 4(r1)
/* 8021B578 002184D8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8021B57C 002184DC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8021B580 002184E0  7C 7F 1B 78 */	mr r31, r3
/* 8021B584 002184E4  D8 21 00 08 */	stfd f1, 8(r1)
/* 8021B588 002184E8  C8 21 00 08 */	lfd f1, 8(r1)
/* 8021B58C 002184EC  4B FF FC 5D */	bl __fpclassifyd__Fd
/* 8021B590 002184F0  2C 03 00 02 */	cmpwi r3, 2
/* 8021B594 002184F4  40 81 00 14 */	ble .L_8021B5A8
/* 8021B598 002184F8  C8 02 C5 C8 */	lfd f0, lbl_803EC7C8@sda21(r2)
/* 8021B59C 002184FC  C8 21 00 08 */	lfd f1, 8(r1)
/* 8021B5A0 00218500  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 8021B5A4 00218504  40 82 00 0C */	bne .L_8021B5B0
.L_8021B5A8:
/* 8021B5A8 00218508  C8 21 00 08 */	lfd f1, 8(r1)
/* 8021B5AC 0021850C  48 00 01 28 */	b .L_8021B6D4
.L_8021B5B0:
/* 8021B5B0 00218510  80 01 00 08 */	lwz r0, 8(r1)
/* 8021B5B4 00218514  80 C1 00 0C */	lwz r6, 0xc(r1)
/* 8021B5B8 00218518  54 03 65 7F */	rlwinm. r3, r0, 0xc, 0x15, 0x1f
/* 8021B5BC 0021851C  7C 05 03 78 */	mr r5, r0
/* 8021B5C0 00218520  38 83 00 00 */	addi r4, r3, 0
/* 8021B5C4 00218524  40 82 00 50 */	bne .L_8021B614
/* 8021B5C8 00218528  54 A0 00 7E */	clrlwi r0, r5, 1
/* 8021B5CC 0021852C  7C C0 03 79 */	or. r0, r6, r0
/* 8021B5D0 00218530  40 82 00 08 */	bne .L_8021B5D8
/* 8021B5D4 00218534  48 00 01 00 */	b .L_8021B6D4
.L_8021B5D8:
/* 8021B5D8 00218538  C8 02 C5 D0 */	lfd f0, lbl_803EC7D0@sda21(r2)
/* 8021B5DC 0021853C  3C 60 FF FF */	lis r3, 0xFFFF3CB0@ha
/* 8021B5E0 00218540  38 03 3C B0 */	addi r0, r3, 0xFFFF3CB0@l
/* 8021B5E4 00218544  FC 01 00 32 */	fmul f0, f1, f0
/* 8021B5E8 00218548  7C 1F 00 00 */	cmpw r31, r0
/* 8021B5EC 0021854C  D8 01 00 08 */	stfd f0, 8(r1)
/* 8021B5F0 00218550  80 01 00 08 */	lwz r0, 8(r1)
/* 8021B5F4 00218554  54 03 65 7E */	rlwinm r3, r0, 0xc, 0x15, 0x1f
/* 8021B5F8 00218558  7C 05 03 78 */	mr r5, r0
/* 8021B5FC 0021855C  38 83 FF CA */	addi r4, r3, -54
/* 8021B600 00218560  40 80 00 14 */	bge .L_8021B614
/* 8021B604 00218564  C8 22 C5 D8 */	lfd f1, lbl_803EC7D8@sda21(r2)
/* 8021B608 00218568  C8 01 00 08 */	lfd f0, 8(r1)
/* 8021B60C 0021856C  FC 21 00 32 */	fmul f1, f1, f0
/* 8021B610 00218570  48 00 00 C4 */	b .L_8021B6D4
.L_8021B614:
/* 8021B614 00218574  2C 04 07 FF */	cmpwi r4, 0x7ff
/* 8021B618 00218578  40 82 00 10 */	bne .L_8021B628
/* 8021B61C 0021857C  C8 01 00 08 */	lfd f0, 8(r1)
/* 8021B620 00218580  FC 20 00 2A */	fadd f1, f0, f0
/* 8021B624 00218584  48 00 00 B0 */	b .L_8021B6D4
.L_8021B628:
/* 8021B628 00218588  7C 84 FA 14 */	add r4, r4, r31
/* 8021B62C 0021858C  2C 04 07 FE */	cmpwi r4, 0x7fe
/* 8021B630 00218590  40 81 00 1C */	ble .L_8021B64C
/* 8021B634 00218594  C8 22 C5 E0 */	lfd f1, lbl_803EC7E0@sda21(r2)
/* 8021B638 00218598  C8 41 00 08 */	lfd f2, 8(r1)
/* 8021B63C 0021859C  4B FF FE 6D */	bl copysign
/* 8021B640 002185A0  C8 02 C5 E0 */	lfd f0, lbl_803EC7E0@sda21(r2)
/* 8021B644 002185A4  FC 20 00 72 */	fmul f1, f0, f1
/* 8021B648 002185A8  48 00 00 8C */	b .L_8021B6D4
.L_8021B64C:
/* 8021B64C 002185AC  2C 04 00 00 */	cmpwi r4, 0
/* 8021B650 002185B0  40 81 00 1C */	ble .L_8021B66C
/* 8021B654 002185B4  54 A3 03 00 */	rlwinm r3, r5, 0, 0xc, 0
/* 8021B658 002185B8  54 80 A0 16 */	slwi r0, r4, 0x14
/* 8021B65C 002185BC  7C 60 03 78 */	or r0, r3, r0
/* 8021B660 002185C0  90 01 00 08 */	stw r0, 8(r1)
/* 8021B664 002185C4  C8 21 00 08 */	lfd f1, 8(r1)
/* 8021B668 002185C8  48 00 00 6C */	b .L_8021B6D4
.L_8021B66C:
/* 8021B66C 002185CC  2C 04 FF CA */	cmpwi r4, -54
/* 8021B670 002185D0  41 81 00 44 */	bgt .L_8021B6B4
/* 8021B674 002185D4  3C 60 00 01 */	lis r3, 0x0000C350@ha
/* 8021B678 002185D8  38 03 C3 50 */	addi r0, r3, 0x0000C350@l
/* 8021B67C 002185DC  7C 1F 00 00 */	cmpw r31, r0
/* 8021B680 002185E0  40 81 00 1C */	ble .L_8021B69C
/* 8021B684 002185E4  C8 22 C5 E0 */	lfd f1, lbl_803EC7E0@sda21(r2)
/* 8021B688 002185E8  C8 41 00 08 */	lfd f2, 8(r1)
/* 8021B68C 002185EC  4B FF FE 1D */	bl copysign
/* 8021B690 002185F0  C8 02 C5 E0 */	lfd f0, lbl_803EC7E0@sda21(r2)
/* 8021B694 002185F4  FC 20 00 72 */	fmul f1, f0, f1
/* 8021B698 002185F8  48 00 00 3C */	b .L_8021B6D4
.L_8021B69C:
/* 8021B69C 002185FC  C8 22 C5 D8 */	lfd f1, lbl_803EC7D8@sda21(r2)
/* 8021B6A0 00218600  C8 41 00 08 */	lfd f2, 8(r1)
/* 8021B6A4 00218604  4B FF FE 05 */	bl copysign
/* 8021B6A8 00218608  C8 02 C5 D8 */	lfd f0, lbl_803EC7D8@sda21(r2)
/* 8021B6AC 0021860C  FC 20 00 72 */	fmul f1, f0, f1
/* 8021B6B0 00218610  48 00 00 24 */	b .L_8021B6D4
.L_8021B6B4:
/* 8021B6B4 00218614  38 04 00 36 */	addi r0, r4, 0x36
/* 8021B6B8 00218618  C8 22 C5 E8 */	lfd f1, lbl_803EC7E8@sda21(r2)
/* 8021B6BC 0021861C  54 A3 03 00 */	rlwinm r3, r5, 0, 0xc, 0
/* 8021B6C0 00218620  54 00 A0 16 */	slwi r0, r0, 0x14
/* 8021B6C4 00218624  7C 60 03 78 */	or r0, r3, r0
/* 8021B6C8 00218628  90 01 00 08 */	stw r0, 8(r1)
/* 8021B6CC 0021862C  C8 01 00 08 */	lfd f0, 8(r1)
/* 8021B6D0 00218630  FC 21 00 32 */	fmul f1, f1, f0
.L_8021B6D4:
/* 8021B6D4 00218634  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8021B6D8 00218638  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8021B6DC 0021863C  38 21 00 20 */	addi r1, r1, 0x20
/* 8021B6E0 00218640  7C 08 03 A6 */	mtlr r0
/* 8021B6E4 00218644  4E 80 00 20 */	blr 
.endfn ldexp

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EC7C8, local
	.double 0.0
.endobj lbl_803EC7C8
.balign 8
.obj lbl_803EC7D0, local
	.double 1.8014398509481984E16
.endobj lbl_803EC7D0
.balign 8
.obj lbl_803EC7D8, local
	.double 1.0E-300
.endobj lbl_803EC7D8
.balign 8
.obj lbl_803EC7E0, local
	.double 1.0E300
.endobj lbl_803EC7E0
.balign 8
.obj lbl_803EC7E8, local
	.double 5.551115123125783E-17
.endobj lbl_803EC7E8
