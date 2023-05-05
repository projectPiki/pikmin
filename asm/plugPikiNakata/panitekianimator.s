.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn createMotionTable__16PaniTekiAnimatorFv, global
/* 8011FC54 0011CBB4  7C 08 02 A6 */	mflr r0
/* 8011FC58 0011CBB8  38 60 00 08 */	li r3, 8
/* 8011FC5C 0011CBBC  90 01 00 04 */	stw r0, 4(r1)
/* 8011FC60 0011CBC0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011FC64 0011CBC4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011FC68 0011CBC8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8011FC6C 0011CBCC  4B F2 73 99 */	bl alloc__6SystemFUl
/* 8011FC70 0011CBD0  3B E3 00 00 */	addi r31, r3, 0
/* 8011FC74 0011CBD4  7F E3 FB 79 */	or. r3, r31, r31
/* 8011FC78 0011CBD8  41 82 00 0C */	beq .L_8011FC84
/* 8011FC7C 0011CBDC  38 80 00 0F */	li r4, 0xf
/* 8011FC80 0011CBE0  4B FF F3 89 */	bl __ct__15PaniMotionTableFi
.L_8011FC84:
/* 8011FC84 0011CBE4  38 60 00 08 */	li r3, 8
/* 8011FC88 0011CBE8  4B F2 73 7D */	bl alloc__6SystemFUl
/* 8011FC8C 0011CBEC  3B C3 00 00 */	addi r30, r3, 0
/* 8011FC90 0011CBF0  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FC94 0011CBF4  41 82 00 0C */	beq .L_8011FCA0
/* 8011FC98 0011CBF8  38 80 00 00 */	li r4, 0
/* 8011FC9C 0011CBFC  4B FF F3 2D */	bl __ct__10PaniMotionFi
.L_8011FCA0:
/* 8011FCA0 0011CC00  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FCA4 0011CC04  38 60 00 08 */	li r3, 8
/* 8011FCA8 0011CC08  93 C4 00 00 */	stw r30, 0(r4)
/* 8011FCAC 0011CC0C  4B F2 73 59 */	bl alloc__6SystemFUl
/* 8011FCB0 0011CC10  3B C3 00 00 */	addi r30, r3, 0
/* 8011FCB4 0011CC14  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FCB8 0011CC18  41 82 00 0C */	beq .L_8011FCC4
/* 8011FCBC 0011CC1C  38 80 00 01 */	li r4, 1
/* 8011FCC0 0011CC20  4B FF F3 09 */	bl __ct__10PaniMotionFi
.L_8011FCC4:
/* 8011FCC4 0011CC24  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FCC8 0011CC28  38 60 00 08 */	li r3, 8
/* 8011FCCC 0011CC2C  93 C4 00 04 */	stw r30, 4(r4)
/* 8011FCD0 0011CC30  4B F2 73 35 */	bl alloc__6SystemFUl
/* 8011FCD4 0011CC34  3B C3 00 00 */	addi r30, r3, 0
/* 8011FCD8 0011CC38  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FCDC 0011CC3C  41 82 00 0C */	beq .L_8011FCE8
/* 8011FCE0 0011CC40  38 80 00 02 */	li r4, 2
/* 8011FCE4 0011CC44  4B FF F2 E5 */	bl __ct__10PaniMotionFi
.L_8011FCE8:
/* 8011FCE8 0011CC48  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FCEC 0011CC4C  38 60 00 08 */	li r3, 8
/* 8011FCF0 0011CC50  93 C4 00 08 */	stw r30, 8(r4)
/* 8011FCF4 0011CC54  4B F2 73 11 */	bl alloc__6SystemFUl
/* 8011FCF8 0011CC58  3B C3 00 00 */	addi r30, r3, 0
/* 8011FCFC 0011CC5C  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FD00 0011CC60  41 82 00 0C */	beq .L_8011FD0C
/* 8011FD04 0011CC64  38 80 00 03 */	li r4, 3
/* 8011FD08 0011CC68  4B FF F2 C1 */	bl __ct__10PaniMotionFi
.L_8011FD0C:
/* 8011FD0C 0011CC6C  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FD10 0011CC70  38 60 00 08 */	li r3, 8
/* 8011FD14 0011CC74  93 C4 00 0C */	stw r30, 0xc(r4)
/* 8011FD18 0011CC78  4B F2 72 ED */	bl alloc__6SystemFUl
/* 8011FD1C 0011CC7C  3B C3 00 00 */	addi r30, r3, 0
/* 8011FD20 0011CC80  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FD24 0011CC84  41 82 00 0C */	beq .L_8011FD30
/* 8011FD28 0011CC88  38 80 00 04 */	li r4, 4
/* 8011FD2C 0011CC8C  4B FF F2 9D */	bl __ct__10PaniMotionFi
.L_8011FD30:
/* 8011FD30 0011CC90  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FD34 0011CC94  38 60 00 08 */	li r3, 8
/* 8011FD38 0011CC98  93 C4 00 10 */	stw r30, 0x10(r4)
/* 8011FD3C 0011CC9C  4B F2 72 C9 */	bl alloc__6SystemFUl
/* 8011FD40 0011CCA0  3B C3 00 00 */	addi r30, r3, 0
/* 8011FD44 0011CCA4  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FD48 0011CCA8  41 82 00 0C */	beq .L_8011FD54
/* 8011FD4C 0011CCAC  38 80 00 05 */	li r4, 5
/* 8011FD50 0011CCB0  4B FF F2 79 */	bl __ct__10PaniMotionFi
.L_8011FD54:
/* 8011FD54 0011CCB4  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FD58 0011CCB8  38 60 00 08 */	li r3, 8
/* 8011FD5C 0011CCBC  93 C4 00 14 */	stw r30, 0x14(r4)
/* 8011FD60 0011CCC0  4B F2 72 A5 */	bl alloc__6SystemFUl
/* 8011FD64 0011CCC4  3B C3 00 00 */	addi r30, r3, 0
/* 8011FD68 0011CCC8  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FD6C 0011CCCC  41 82 00 0C */	beq .L_8011FD78
/* 8011FD70 0011CCD0  38 80 00 06 */	li r4, 6
/* 8011FD74 0011CCD4  4B FF F2 55 */	bl __ct__10PaniMotionFi
.L_8011FD78:
/* 8011FD78 0011CCD8  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FD7C 0011CCDC  38 60 00 08 */	li r3, 8
/* 8011FD80 0011CCE0  93 C4 00 18 */	stw r30, 0x18(r4)
/* 8011FD84 0011CCE4  4B F2 72 81 */	bl alloc__6SystemFUl
/* 8011FD88 0011CCE8  3B C3 00 00 */	addi r30, r3, 0
/* 8011FD8C 0011CCEC  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FD90 0011CCF0  41 82 00 0C */	beq .L_8011FD9C
/* 8011FD94 0011CCF4  38 80 00 07 */	li r4, 7
/* 8011FD98 0011CCF8  4B FF F2 31 */	bl __ct__10PaniMotionFi
.L_8011FD9C:
/* 8011FD9C 0011CCFC  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FDA0 0011CD00  38 60 00 08 */	li r3, 8
/* 8011FDA4 0011CD04  93 C4 00 1C */	stw r30, 0x1c(r4)
/* 8011FDA8 0011CD08  4B F2 72 5D */	bl alloc__6SystemFUl
/* 8011FDAC 0011CD0C  3B C3 00 00 */	addi r30, r3, 0
/* 8011FDB0 0011CD10  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FDB4 0011CD14  41 82 00 0C */	beq .L_8011FDC0
/* 8011FDB8 0011CD18  38 80 00 08 */	li r4, 8
/* 8011FDBC 0011CD1C  4B FF F2 0D */	bl __ct__10PaniMotionFi
.L_8011FDC0:
/* 8011FDC0 0011CD20  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FDC4 0011CD24  38 60 00 08 */	li r3, 8
/* 8011FDC8 0011CD28  93 C4 00 20 */	stw r30, 0x20(r4)
/* 8011FDCC 0011CD2C  4B F2 72 39 */	bl alloc__6SystemFUl
/* 8011FDD0 0011CD30  3B C3 00 00 */	addi r30, r3, 0
/* 8011FDD4 0011CD34  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FDD8 0011CD38  41 82 00 0C */	beq .L_8011FDE4
/* 8011FDDC 0011CD3C  38 80 00 09 */	li r4, 9
/* 8011FDE0 0011CD40  4B FF F1 E9 */	bl __ct__10PaniMotionFi
.L_8011FDE4:
/* 8011FDE4 0011CD44  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FDE8 0011CD48  38 60 00 08 */	li r3, 8
/* 8011FDEC 0011CD4C  93 C4 00 24 */	stw r30, 0x24(r4)
/* 8011FDF0 0011CD50  4B F2 72 15 */	bl alloc__6SystemFUl
/* 8011FDF4 0011CD54  3B C3 00 00 */	addi r30, r3, 0
/* 8011FDF8 0011CD58  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FDFC 0011CD5C  41 82 00 0C */	beq .L_8011FE08
/* 8011FE00 0011CD60  38 80 00 0A */	li r4, 0xa
/* 8011FE04 0011CD64  4B FF F1 C5 */	bl __ct__10PaniMotionFi
.L_8011FE08:
/* 8011FE08 0011CD68  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FE0C 0011CD6C  38 60 00 08 */	li r3, 8
/* 8011FE10 0011CD70  93 C4 00 28 */	stw r30, 0x28(r4)
/* 8011FE14 0011CD74  4B F2 71 F1 */	bl alloc__6SystemFUl
/* 8011FE18 0011CD78  3B C3 00 00 */	addi r30, r3, 0
/* 8011FE1C 0011CD7C  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FE20 0011CD80  41 82 00 0C */	beq .L_8011FE2C
/* 8011FE24 0011CD84  38 80 00 0B */	li r4, 0xb
/* 8011FE28 0011CD88  4B FF F1 A1 */	bl __ct__10PaniMotionFi
.L_8011FE2C:
/* 8011FE2C 0011CD8C  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FE30 0011CD90  38 60 00 08 */	li r3, 8
/* 8011FE34 0011CD94  93 C4 00 2C */	stw r30, 0x2c(r4)
/* 8011FE38 0011CD98  4B F2 71 CD */	bl alloc__6SystemFUl
/* 8011FE3C 0011CD9C  3B C3 00 00 */	addi r30, r3, 0
/* 8011FE40 0011CDA0  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FE44 0011CDA4  41 82 00 0C */	beq .L_8011FE50
/* 8011FE48 0011CDA8  38 80 00 0C */	li r4, 0xc
/* 8011FE4C 0011CDAC  4B FF F1 7D */	bl __ct__10PaniMotionFi
.L_8011FE50:
/* 8011FE50 0011CDB0  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FE54 0011CDB4  38 60 00 08 */	li r3, 8
/* 8011FE58 0011CDB8  93 C4 00 30 */	stw r30, 0x30(r4)
/* 8011FE5C 0011CDBC  4B F2 71 A9 */	bl alloc__6SystemFUl
/* 8011FE60 0011CDC0  3B C3 00 00 */	addi r30, r3, 0
/* 8011FE64 0011CDC4  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FE68 0011CDC8  41 82 00 0C */	beq .L_8011FE74
/* 8011FE6C 0011CDCC  38 80 00 0D */	li r4, 0xd
/* 8011FE70 0011CDD0  4B FF F1 59 */	bl __ct__10PaniMotionFi
.L_8011FE74:
/* 8011FE74 0011CDD4  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FE78 0011CDD8  38 60 00 08 */	li r3, 8
/* 8011FE7C 0011CDDC  93 C4 00 34 */	stw r30, 0x34(r4)
/* 8011FE80 0011CDE0  4B F2 71 85 */	bl alloc__6SystemFUl
/* 8011FE84 0011CDE4  3B C3 00 00 */	addi r30, r3, 0
/* 8011FE88 0011CDE8  7F C3 F3 79 */	or. r3, r30, r30
/* 8011FE8C 0011CDEC  41 82 00 0C */	beq .L_8011FE98
/* 8011FE90 0011CDF0  38 80 00 0E */	li r4, 0xe
/* 8011FE94 0011CDF4  4B FF F1 35 */	bl __ct__10PaniMotionFi
.L_8011FE98:
/* 8011FE98 0011CDF8  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011FE9C 0011CDFC  7F E3 FB 78 */	mr r3, r31
/* 8011FEA0 0011CE00  93 C4 00 38 */	stw r30, 0x38(r4)
/* 8011FEA4 0011CE04  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011FEA8 0011CE08  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011FEAC 0011CE0C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8011FEB0 0011CE10  38 21 00 18 */	addi r1, r1, 0x18
/* 8011FEB4 0011CE14  7C 08 03 A6 */	mtlr r0
/* 8011FEB8 0011CE18  4E 80 00 20 */	blr 
.endfn createMotionTable__16PaniTekiAnimatorFv

.fn __ct__16PaniTekiAnimatorFv, global
/* 8011FEBC 0011CE1C  7C 08 02 A6 */	mflr r0
/* 8011FEC0 0011CE20  90 01 00 04 */	stw r0, 4(r1)
/* 8011FEC4 0011CE24  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011FEC8 0011CE28  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011FECC 0011CE2C  7C 7F 1B 78 */	mr r31, r3
/* 8011FED0 0011CE30  4B FF F2 11 */	bl __ct__12PaniAnimatorFv
/* 8011FED4 0011CE34  3C 60 80 2C */	lis r3, __vt__16PaniTekiAnimator@ha
/* 8011FED8 0011CE38  38 03 4E 28 */	addi r0, r3, __vt__16PaniTekiAnimator@l
/* 8011FEDC 0011CE3C  90 1F 00 30 */	stw r0, 0x30(r31)
/* 8011FEE0 0011CE40  7F E3 FB 78 */	mr r3, r31
/* 8011FEE4 0011CE44  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011FEE8 0011CE48  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011FEEC 0011CE4C  38 21 00 18 */	addi r1, r1, 0x18
/* 8011FEF0 0011CE50  7C 08 03 A6 */	mtlr r0
/* 8011FEF4 0011CE54  4E 80 00 20 */	blr 
.endfn __ct__16PaniTekiAnimatorFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802C4D50, local
	.asciz "panitekianimator.cpp"
.endobj lbl_802C4D50
.balign 4
.obj lbl_802C4D68, local
	.asciz "panitekianimator"
.endobj lbl_802C4D68
.balign 4
.obj lbl_802C4D7C, local
	.asciz "WAITACTION_1"
.endobj lbl_802C4D7C
.balign 4
.obj lbl_802C4D8C, local
	.asciz "WAITACTION_2"
.endobj lbl_802C4D8C
.balign 4
.obj motionLabels__16PaniTekiAnimator, global
	.4byte lbl_803E30C0
	.4byte lbl_803E30C8
	.4byte lbl_803E30D0
	.4byte lbl_803E30D8
	.4byte lbl_802C4D7C
	.4byte lbl_802C4D8C
	.4byte lbl_803E30E0
	.4byte lbl_803E30E8
	.4byte lbl_803E30F0
	.4byte lbl_803E30F8
	.4byte lbl_803E3100
	.4byte lbl_803E3108
	.4byte lbl_803E3110
	.4byte lbl_803E3118
	.4byte lbl_803E3120
.endobj motionLabels__16PaniTekiAnimator
.balign 4
.obj lbl_802C4DD8, local
	.asciz "PaniTekiAnimator"
.endobj lbl_802C4DD8
.balign 4
.obj lbl_802C4DEC, local
	.asciz "Animator"
.endobj lbl_802C4DEC
.balign 4
.obj lbl_802C4DF8, local
	.asciz "PaniAnimator"
.endobj lbl_802C4DF8
.balign 4
.obj lbl_802C4E08, local
	.4byte __RTTI__8Animator
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802C4E08
.obj lbl_802C4E14, local
	.4byte __RTTI__8Animator
	.4byte 0x00000000
	.4byte __RTTI__12PaniAnimator
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802C4E14
.obj __vt__16PaniTekiAnimator, weak
	.4byte __RTTI__16PaniTekiAnimator
	.4byte 0
	.4byte changeContext__12PaniAnimatorFP11AnimContext
	.4byte animate__12PaniAnimatorFf
	.4byte finishOneShot__8AnimatorFv
	.4byte finishLoop__8AnimatorFv
	.4byte updateContext__12PaniAnimatorFv
.endobj __vt__16PaniTekiAnimator

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E30C0, local
	.asciz "DEAD"
.endobj lbl_803E30C0
.balign 4
.obj lbl_803E30C8, local
	.asciz "DAMAGE"
.endobj lbl_803E30C8
.balign 4
.obj lbl_803E30D0, local
	.asciz "WAIT_1"
.endobj lbl_803E30D0
.balign 4
.obj lbl_803E30D8, local
	.asciz "WAIT_2"
.endobj lbl_803E30D8
.balign 4
.obj lbl_803E30E0, local
	.asciz "MOVE_1"
.endobj lbl_803E30E0
.balign 4
.obj lbl_803E30E8, local
	.asciz "MOVE_2"
.endobj lbl_803E30E8
.balign 4
.obj lbl_803E30F0, local
	.asciz "ATTACK"
.endobj lbl_803E30F0
.balign 4
.obj lbl_803E30F8, local
	.asciz "FLICK"
.endobj lbl_803E30F8
.balign 4
.obj lbl_803E3100, local
	.asciz "TYPE_1"
.endobj lbl_803E3100
.balign 4
.obj lbl_803E3108, local
	.asciz "TYPE_2"
.endobj lbl_803E3108
.balign 4
.obj lbl_803E3110, local
	.asciz "TYPE_3"
.endobj lbl_803E3110
.balign 4
.obj lbl_803E3118, local
	.asciz "TYPE_4"
.endobj lbl_803E3118
.balign 4
.obj lbl_803E3120, local
	.asciz "TYPE_5"
.endobj lbl_803E3120
.balign 4
.obj __RTTI__8Animator, local
	.4byte lbl_802C4DEC
	.4byte 0
.endobj __RTTI__8Animator
.obj __RTTI__12PaniAnimator, local
	.4byte lbl_802C4DF8
	.4byte lbl_802C4E08
.endobj __RTTI__12PaniAnimator
.obj __RTTI__16PaniTekiAnimator, local
	.4byte lbl_802C4DD8
	.4byte lbl_802C4E14
.endobj __RTTI__16PaniTekiAnimator
