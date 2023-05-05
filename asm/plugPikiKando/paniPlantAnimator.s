.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn createMotionTable__17PaniPlantAnimatorFv, global
/* 8011B148 001180A8  7C 08 02 A6 */	mflr r0
/* 8011B14C 001180AC  38 60 00 08 */	li r3, 8
/* 8011B150 001180B0  90 01 00 04 */	stw r0, 4(r1)
/* 8011B154 001180B4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011B158 001180B8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011B15C 001180BC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8011B160 001180C0  4B F2 BE A5 */	bl alloc__6SystemFUl
/* 8011B164 001180C4  3B E3 00 00 */	addi r31, r3, 0
/* 8011B168 001180C8  7F E3 FB 79 */	or. r3, r31, r31
/* 8011B16C 001180CC  41 82 00 0C */	beq .L_8011B178
/* 8011B170 001180D0  38 80 00 07 */	li r4, 7
/* 8011B174 001180D4  48 00 3E 95 */	bl __ct__15PaniMotionTableFi
.L_8011B178:
/* 8011B178 001180D8  38 60 00 08 */	li r3, 8
/* 8011B17C 001180DC  4B F2 BE 89 */	bl alloc__6SystemFUl
/* 8011B180 001180E0  3B C3 00 00 */	addi r30, r3, 0
/* 8011B184 001180E4  7F C3 F3 79 */	or. r3, r30, r30
/* 8011B188 001180E8  41 82 00 0C */	beq .L_8011B194
/* 8011B18C 001180EC  38 80 00 00 */	li r4, 0
/* 8011B190 001180F0  48 00 3E 39 */	bl __ct__10PaniMotionFi
.L_8011B194:
/* 8011B194 001180F4  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011B198 001180F8  38 60 00 08 */	li r3, 8
/* 8011B19C 001180FC  93 C4 00 00 */	stw r30, 0(r4)
/* 8011B1A0 00118100  4B F2 BE 65 */	bl alloc__6SystemFUl
/* 8011B1A4 00118104  3B C3 00 00 */	addi r30, r3, 0
/* 8011B1A8 00118108  7F C3 F3 79 */	or. r3, r30, r30
/* 8011B1AC 0011810C  41 82 00 0C */	beq .L_8011B1B8
/* 8011B1B0 00118110  38 80 00 01 */	li r4, 1
/* 8011B1B4 00118114  48 00 3E 15 */	bl __ct__10PaniMotionFi
.L_8011B1B8:
/* 8011B1B8 00118118  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011B1BC 0011811C  38 60 00 08 */	li r3, 8
/* 8011B1C0 00118120  93 C4 00 04 */	stw r30, 4(r4)
/* 8011B1C4 00118124  4B F2 BE 41 */	bl alloc__6SystemFUl
/* 8011B1C8 00118128  3B C3 00 00 */	addi r30, r3, 0
/* 8011B1CC 0011812C  7F C3 F3 79 */	or. r3, r30, r30
/* 8011B1D0 00118130  41 82 00 0C */	beq .L_8011B1DC
/* 8011B1D4 00118134  38 80 00 02 */	li r4, 2
/* 8011B1D8 00118138  48 00 3D F1 */	bl __ct__10PaniMotionFi
.L_8011B1DC:
/* 8011B1DC 0011813C  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011B1E0 00118140  38 60 00 08 */	li r3, 8
/* 8011B1E4 00118144  93 C4 00 08 */	stw r30, 8(r4)
/* 8011B1E8 00118148  4B F2 BE 1D */	bl alloc__6SystemFUl
/* 8011B1EC 0011814C  3B C3 00 00 */	addi r30, r3, 0
/* 8011B1F0 00118150  7F C3 F3 79 */	or. r3, r30, r30
/* 8011B1F4 00118154  41 82 00 0C */	beq .L_8011B200
/* 8011B1F8 00118158  38 80 00 03 */	li r4, 3
/* 8011B1FC 0011815C  48 00 3D CD */	bl __ct__10PaniMotionFi
.L_8011B200:
/* 8011B200 00118160  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011B204 00118164  38 60 00 08 */	li r3, 8
/* 8011B208 00118168  93 C4 00 0C */	stw r30, 0xc(r4)
/* 8011B20C 0011816C  4B F2 BD F9 */	bl alloc__6SystemFUl
/* 8011B210 00118170  3B C3 00 00 */	addi r30, r3, 0
/* 8011B214 00118174  7F C3 F3 79 */	or. r3, r30, r30
/* 8011B218 00118178  41 82 00 0C */	beq .L_8011B224
/* 8011B21C 0011817C  38 80 00 04 */	li r4, 4
/* 8011B220 00118180  48 00 3D A9 */	bl __ct__10PaniMotionFi
.L_8011B224:
/* 8011B224 00118184  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011B228 00118188  38 60 00 08 */	li r3, 8
/* 8011B22C 0011818C  93 C4 00 10 */	stw r30, 0x10(r4)
/* 8011B230 00118190  4B F2 BD D5 */	bl alloc__6SystemFUl
/* 8011B234 00118194  3B C3 00 00 */	addi r30, r3, 0
/* 8011B238 00118198  7F C3 F3 79 */	or. r3, r30, r30
/* 8011B23C 0011819C  41 82 00 0C */	beq .L_8011B248
/* 8011B240 001181A0  38 80 00 05 */	li r4, 5
/* 8011B244 001181A4  48 00 3D 85 */	bl __ct__10PaniMotionFi
.L_8011B248:
/* 8011B248 001181A8  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011B24C 001181AC  38 60 00 08 */	li r3, 8
/* 8011B250 001181B0  93 C4 00 14 */	stw r30, 0x14(r4)
/* 8011B254 001181B4  4B F2 BD B1 */	bl alloc__6SystemFUl
/* 8011B258 001181B8  3B C3 00 00 */	addi r30, r3, 0
/* 8011B25C 001181BC  7F C3 F3 79 */	or. r3, r30, r30
/* 8011B260 001181C0  41 82 00 0C */	beq .L_8011B26C
/* 8011B264 001181C4  38 80 00 06 */	li r4, 6
/* 8011B268 001181C8  48 00 3D 61 */	bl __ct__10PaniMotionFi
.L_8011B26C:
/* 8011B26C 001181CC  80 9F 00 04 */	lwz r4, 4(r31)
/* 8011B270 001181D0  7F E3 FB 78 */	mr r3, r31
/* 8011B274 001181D4  93 C4 00 18 */	stw r30, 0x18(r4)
/* 8011B278 001181D8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011B27C 001181DC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011B280 001181E0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8011B284 001181E4  38 21 00 18 */	addi r1, r1, 0x18
/* 8011B288 001181E8  7C 08 03 A6 */	mtlr r0
/* 8011B28C 001181EC  4E 80 00 20 */	blr 
.endfn createMotionTable__17PaniPlantAnimatorFv

.fn __ct__17PaniPlantAnimatorFv, global
/* 8011B290 001181F0  7C 08 02 A6 */	mflr r0
/* 8011B294 001181F4  90 01 00 04 */	stw r0, 4(r1)
/* 8011B298 001181F8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011B29C 001181FC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011B2A0 00118200  7C 7F 1B 78 */	mr r31, r3
/* 8011B2A4 00118204  48 00 3E 3D */	bl __ct__12PaniAnimatorFv
/* 8011B2A8 00118208  3C 60 80 2C */	lis r3, __vt__17PaniPlantAnimator@ha
/* 8011B2AC 0011820C  38 03 40 68 */	addi r0, r3, __vt__17PaniPlantAnimator@l
/* 8011B2B0 00118210  90 1F 00 30 */	stw r0, 0x30(r31)
/* 8011B2B4 00118214  7F E3 FB 78 */	mr r3, r31
/* 8011B2B8 00118218  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011B2BC 0011821C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011B2C0 00118220  38 21 00 18 */	addi r1, r1, 0x18
/* 8011B2C4 00118224  7C 08 03 A6 */	mtlr r0
/* 8011B2C8 00118228  4E 80 00 20 */	blr 
.endfn __ct__17PaniPlantAnimatorFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802C3FD0, local
	.asciz "paniPlantAnimator.cpp"
.endobj lbl_802C3FD0
.balign 4
.obj lbl_802C3FE8, local
	.asciz "paniPlantAnimator"
.endobj lbl_802C3FE8
.balign 4
.obj motionLabels__17PaniPlantAnimator, global
	.4byte lbl_803E2F60
	.4byte lbl_803E2F64
	.4byte lbl_803E2F68
	.4byte lbl_803E2F6C
	.4byte lbl_803E2F70
	.4byte lbl_803E2F74
	.4byte lbl_803E2F78
.endobj motionLabels__17PaniPlantAnimator
.balign 4
.obj lbl_802C4018, local
	.asciz "PaniPlantAnimator"
.endobj lbl_802C4018
.balign 4
.obj lbl_802C402C, local
	.asciz "Animator"
.endobj lbl_802C402C
.balign 4
.obj lbl_802C4038, local
	.asciz "PaniAnimator"
.endobj lbl_802C4038
.balign 4
.obj lbl_802C4048, local
	.4byte __RTTI__8Animator
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802C4048
.obj lbl_802C4054, local
	.4byte __RTTI__8Animator
	.4byte 0x00000000
	.4byte __RTTI__12PaniAnimator
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802C4054
.obj __vt__17PaniPlantAnimator, weak
	.4byte __RTTI__17PaniPlantAnimator
	.4byte 0
	.4byte changeContext__12PaniAnimatorFP11AnimContext
	.4byte animate__12PaniAnimatorFf
	.4byte finishOneShot__8AnimatorFv
	.4byte finishLoop__8AnimatorFv
	.4byte updateContext__12PaniAnimatorFv
.endobj __vt__17PaniPlantAnimator

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E2F60, local
	.asciz "1"
.endobj lbl_803E2F60
.balign 4
.obj lbl_803E2F64, local
	.asciz "2"
.endobj lbl_803E2F64
.balign 4
.obj lbl_803E2F68, local
	.asciz "3"
.endobj lbl_803E2F68
.balign 4
.obj lbl_803E2F6C, local
	.asciz "4"
.endobj lbl_803E2F6C
.balign 4
.obj lbl_803E2F70, local
	.asciz "5"
.endobj lbl_803E2F70
.balign 4
.obj lbl_803E2F74, local
	.asciz "6"
.endobj lbl_803E2F74
.balign 4
.obj lbl_803E2F78, local
	.asciz "7"
.endobj lbl_803E2F78
.balign 4
.obj __RTTI__8Animator, local
	.4byte lbl_802C402C
	.4byte 0
.endobj __RTTI__8Animator
.obj __RTTI__12PaniAnimator, local
	.4byte lbl_802C4038
	.4byte lbl_802C4048
.endobj __RTTI__12PaniAnimator
.obj __RTTI__17PaniPlantAnimator, local
	.4byte lbl_802C4018
	.4byte lbl_802C4054
.endobj __RTTI__17PaniPlantAnimator
