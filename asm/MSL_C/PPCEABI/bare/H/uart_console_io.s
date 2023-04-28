.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __close_console, global
/* 8021A510 00217470  38 60 00 00 */	li r3, 0
/* 8021A514 00217474  4E 80 00 20 */	blr 
.endfn __close_console

.fn __write_console, global
/* 8021A518 00217478  7C 08 02 A6 */	mflr r0
/* 8021A51C 0021747C  38 60 00 00 */	li r3, 0
/* 8021A520 00217480  90 01 00 04 */	stw r0, 4(r1)
/* 8021A524 00217484  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8021A528 00217488  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8021A52C 0021748C  3B E5 00 00 */	addi r31, r5, 0
/* 8021A530 00217490  93 C1 00 20 */	stw r30, 0x20(r1)
/* 8021A534 00217494  3B C4 00 00 */	addi r30, r4, 0
/* 8021A538 00217498  80 0D 34 98 */	lwz r0, initialized$16@sda21(r13)
/* 8021A53C 0021749C  2C 00 00 00 */	cmpwi r0, 0
/* 8021A540 002174A0  40 82 00 20 */	bne .L_8021A560
/* 8021A544 002174A4  3C 60 00 01 */	lis r3, 0x0000E100@ha
/* 8021A548 002174A8  38 63 E1 00 */	addi r3, r3, 0x0000E100@l
/* 8021A54C 002174AC  4B FE 32 79 */	bl InitializeUART
/* 8021A550 002174B0  2C 03 00 00 */	cmpwi r3, 0
/* 8021A554 002174B4  40 82 00 0C */	bne .L_8021A560
/* 8021A558 002174B8  38 00 00 01 */	li r0, 1
/* 8021A55C 002174BC  90 0D 34 98 */	stw r0, initialized$16@sda21(r13)
.L_8021A560:
/* 8021A560 002174C0  2C 03 00 00 */	cmpwi r3, 0
/* 8021A564 002174C4  41 82 00 0C */	beq .L_8021A570
/* 8021A568 002174C8  38 60 00 01 */	li r3, 1
/* 8021A56C 002174CC  48 00 00 2C */	b .L_8021A598
.L_8021A570:
/* 8021A570 002174D0  7F C3 F3 78 */	mr r3, r30
/* 8021A574 002174D4  80 9F 00 00 */	lwz r4, 0(r31)
/* 8021A578 002174D8  4B FE 32 9D */	bl WriteUARTN
/* 8021A57C 002174DC  2C 03 00 00 */	cmpwi r3, 0
/* 8021A580 002174E0  41 82 00 14 */	beq .L_8021A594
/* 8021A584 002174E4  38 00 00 00 */	li r0, 0
/* 8021A588 002174E8  90 1F 00 00 */	stw r0, 0(r31)
/* 8021A58C 002174EC  38 60 00 01 */	li r3, 1
/* 8021A590 002174F0  48 00 00 08 */	b .L_8021A598
.L_8021A594:
/* 8021A594 002174F4  38 60 00 00 */	li r3, 0
.L_8021A598:
/* 8021A598 002174F8  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8021A59C 002174FC  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8021A5A0 00217500  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 8021A5A4 00217504  7C 08 03 A6 */	mtlr r0
/* 8021A5A8 00217508  38 21 00 28 */	addi r1, r1, 0x28
/* 8021A5AC 0021750C  4E 80 00 20 */	blr 
.endfn __write_console

.fn __read_console, global
/* 8021A5B0 00217510  7C 08 02 A6 */	mflr r0
/* 8021A5B4 00217514  38 60 00 00 */	li r3, 0
/* 8021A5B8 00217518  90 01 00 04 */	stw r0, 4(r1)
/* 8021A5BC 0021751C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8021A5C0 00217520  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8021A5C4 00217524  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8021A5C8 00217528  3B C5 00 00 */	addi r30, r5, 0
/* 8021A5CC 0021752C  93 A1 00 24 */	stw r29, 0x24(r1)
/* 8021A5D0 00217530  3B A4 00 00 */	addi r29, r4, 0
/* 8021A5D4 00217534  80 0D 34 98 */	lwz r0, initialized$16@sda21(r13)
/* 8021A5D8 00217538  2C 00 00 00 */	cmpwi r0, 0
/* 8021A5DC 0021753C  40 82 00 20 */	bne .L_8021A5FC
/* 8021A5E0 00217540  3C 60 00 01 */	lis r3, 0x0000E100@ha
/* 8021A5E4 00217544  38 63 E1 00 */	addi r3, r3, 0x0000E100@l
/* 8021A5E8 00217548  4B FE 31 DD */	bl InitializeUART
/* 8021A5EC 0021754C  2C 03 00 00 */	cmpwi r3, 0
/* 8021A5F0 00217550  40 82 00 0C */	bne .L_8021A5FC
/* 8021A5F4 00217554  38 00 00 01 */	li r0, 1
/* 8021A5F8 00217558  90 0D 34 98 */	stw r0, initialized$16@sda21(r13)
.L_8021A5FC:
/* 8021A5FC 0021755C  2C 03 00 00 */	cmpwi r3, 0
/* 8021A600 00217560  41 82 00 0C */	beq .L_8021A60C
/* 8021A604 00217564  38 60 00 01 */	li r3, 1
/* 8021A608 00217568  48 00 00 6C */	b .L_8021A674
.L_8021A60C:
/* 8021A60C 0021756C  83 FE 00 00 */	lwz r31, 0(r30)
/* 8021A610 00217570  38 00 00 00 */	li r0, 0
/* 8021A614 00217574  38 60 00 00 */	li r3, 0
/* 8021A618 00217578  90 1E 00 00 */	stw r0, 0(r30)
/* 8021A61C 0021757C  48 00 00 2C */	b .L_8021A648
.L_8021A620:
/* 8021A620 00217580  38 7D 00 00 */	addi r3, r29, 0
/* 8021A624 00217584  38 80 00 01 */	li r4, 1
/* 8021A628 00217588  4B FE 31 E5 */	bl ReadUARTN
/* 8021A62C 0021758C  80 9E 00 00 */	lwz r4, 0(r30)
/* 8021A630 00217590  38 04 00 01 */	addi r0, r4, 1
/* 8021A634 00217594  90 1E 00 00 */	stw r0, 0(r30)
/* 8021A638 00217598  88 1D 00 00 */	lbz r0, 0(r29)
/* 8021A63C 0021759C  28 00 00 0D */	cmplwi r0, 0xd
/* 8021A640 002175A0  41 82 00 1C */	beq .L_8021A65C
/* 8021A644 002175A4  3B BD 00 01 */	addi r29, r29, 1
.L_8021A648:
/* 8021A648 002175A8  80 1E 00 00 */	lwz r0, 0(r30)
/* 8021A64C 002175AC  7C 00 F8 40 */	cmplw r0, r31
/* 8021A650 002175B0  41 81 00 0C */	bgt .L_8021A65C
/* 8021A654 002175B4  2C 03 00 00 */	cmpwi r3, 0
/* 8021A658 002175B8  41 82 FF C8 */	beq .L_8021A620
.L_8021A65C:
/* 8021A65C 002175BC  2C 03 00 00 */	cmpwi r3, 0
/* 8021A660 002175C0  40 82 00 0C */	bne .L_8021A66C
/* 8021A664 002175C4  38 00 00 00 */	li r0, 0
/* 8021A668 002175C8  48 00 00 08 */	b .L_8021A670
.L_8021A66C:
/* 8021A66C 002175CC  38 00 00 01 */	li r0, 1
.L_8021A670:
/* 8021A670 002175D0  54 03 06 3E */	clrlwi r3, r0, 0x18
.L_8021A674:
/* 8021A674 002175D4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8021A678 002175D8  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8021A67C 002175DC  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8021A680 002175E0  7C 08 03 A6 */	mtlr r0
/* 8021A684 002175E4  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 8021A688 002175E8  38 21 00 30 */	addi r1, r1, 0x30
/* 8021A68C 002175EC  4E 80 00 20 */	blr 
.endfn __read_console

.section .sbss, "wa"
.balign 8
.obj initialized$16, local
	.skip 0x4
.endobj initialized$16
