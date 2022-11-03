.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global createMotionTable__16PaniItemAnimatorFv
createMotionTable__16PaniItemAnimatorFv:
/* 800F7E8C 000F4DEC  7C 08 02 A6 */	mflr r0
/* 800F7E90 000F4DF0  38 60 00 08 */	li r3, 8
/* 800F7E94 000F4DF4  90 01 00 04 */	stw r0, 4(r1)
/* 800F7E98 000F4DF8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F7E9C 000F4DFC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F7EA0 000F4E00  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800F7EA4 000F4E04  4B F4 F1 61 */	bl alloc__6SystemFUl
/* 800F7EA8 000F4E08  3B E3 00 00 */	addi r31, r3, 0
/* 800F7EAC 000F4E0C  7F E3 FB 79 */	or. r3, r31, r31
/* 800F7EB0 000F4E10  41 82 00 0C */	beq .L_800F7EBC
/* 800F7EB4 000F4E14  38 80 00 0F */	li r4, 0xf
/* 800F7EB8 000F4E18  48 02 71 51 */	bl __ct__15PaniMotionTableFi
.L_800F7EBC:
/* 800F7EBC 000F4E1C  38 60 00 08 */	li r3, 8
/* 800F7EC0 000F4E20  4B F4 F1 45 */	bl alloc__6SystemFUl
/* 800F7EC4 000F4E24  3B C3 00 00 */	addi r30, r3, 0
/* 800F7EC8 000F4E28  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7ECC 000F4E2C  41 82 00 0C */	beq .L_800F7ED8
/* 800F7ED0 000F4E30  38 80 00 00 */	li r4, 0
/* 800F7ED4 000F4E34  48 02 70 F5 */	bl __ct__10PaniMotionFi
.L_800F7ED8:
/* 800F7ED8 000F4E38  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7EDC 000F4E3C  38 60 00 08 */	li r3, 8
/* 800F7EE0 000F4E40  93 C4 00 00 */	stw r30, 0(r4)
/* 800F7EE4 000F4E44  4B F4 F1 21 */	bl alloc__6SystemFUl
/* 800F7EE8 000F4E48  3B C3 00 00 */	addi r30, r3, 0
/* 800F7EEC 000F4E4C  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7EF0 000F4E50  41 82 00 0C */	beq .L_800F7EFC
/* 800F7EF4 000F4E54  38 80 00 01 */	li r4, 1
/* 800F7EF8 000F4E58  48 02 70 D1 */	bl __ct__10PaniMotionFi
.L_800F7EFC:
/* 800F7EFC 000F4E5C  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F00 000F4E60  38 60 00 08 */	li r3, 8
/* 800F7F04 000F4E64  93 C4 00 04 */	stw r30, 4(r4)
/* 800F7F08 000F4E68  4B F4 F0 FD */	bl alloc__6SystemFUl
/* 800F7F0C 000F4E6C  3B C3 00 00 */	addi r30, r3, 0
/* 800F7F10 000F4E70  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7F14 000F4E74  41 82 00 0C */	beq .L_800F7F20
/* 800F7F18 000F4E78  38 80 00 02 */	li r4, 2
/* 800F7F1C 000F4E7C  48 02 70 AD */	bl __ct__10PaniMotionFi
.L_800F7F20:
/* 800F7F20 000F4E80  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F24 000F4E84  38 60 00 08 */	li r3, 8
/* 800F7F28 000F4E88  93 C4 00 08 */	stw r30, 8(r4)
/* 800F7F2C 000F4E8C  4B F4 F0 D9 */	bl alloc__6SystemFUl
/* 800F7F30 000F4E90  3B C3 00 00 */	addi r30, r3, 0
/* 800F7F34 000F4E94  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7F38 000F4E98  41 82 00 0C */	beq .L_800F7F44
/* 800F7F3C 000F4E9C  38 80 00 03 */	li r4, 3
/* 800F7F40 000F4EA0  48 02 70 89 */	bl __ct__10PaniMotionFi
.L_800F7F44:
/* 800F7F44 000F4EA4  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F48 000F4EA8  38 60 00 08 */	li r3, 8
/* 800F7F4C 000F4EAC  93 C4 00 0C */	stw r30, 0xc(r4)
/* 800F7F50 000F4EB0  4B F4 F0 B5 */	bl alloc__6SystemFUl
/* 800F7F54 000F4EB4  3B C3 00 00 */	addi r30, r3, 0
/* 800F7F58 000F4EB8  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7F5C 000F4EBC  41 82 00 0C */	beq .L_800F7F68
/* 800F7F60 000F4EC0  38 80 00 04 */	li r4, 4
/* 800F7F64 000F4EC4  48 02 70 65 */	bl __ct__10PaniMotionFi
.L_800F7F68:
/* 800F7F68 000F4EC8  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F6C 000F4ECC  38 60 00 08 */	li r3, 8
/* 800F7F70 000F4ED0  93 C4 00 10 */	stw r30, 0x10(r4)
/* 800F7F74 000F4ED4  4B F4 F0 91 */	bl alloc__6SystemFUl
/* 800F7F78 000F4ED8  3B C3 00 00 */	addi r30, r3, 0
/* 800F7F7C 000F4EDC  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7F80 000F4EE0  41 82 00 0C */	beq .L_800F7F8C
/* 800F7F84 000F4EE4  38 80 00 05 */	li r4, 5
/* 800F7F88 000F4EE8  48 02 70 41 */	bl __ct__10PaniMotionFi
.L_800F7F8C:
/* 800F7F8C 000F4EEC  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F90 000F4EF0  38 60 00 08 */	li r3, 8
/* 800F7F94 000F4EF4  93 C4 00 14 */	stw r30, 0x14(r4)
/* 800F7F98 000F4EF8  4B F4 F0 6D */	bl alloc__6SystemFUl
/* 800F7F9C 000F4EFC  3B C3 00 00 */	addi r30, r3, 0
/* 800F7FA0 000F4F00  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7FA4 000F4F04  41 82 00 0C */	beq .L_800F7FB0
/* 800F7FA8 000F4F08  38 80 00 06 */	li r4, 6
/* 800F7FAC 000F4F0C  48 02 70 1D */	bl __ct__10PaniMotionFi
.L_800F7FB0:
/* 800F7FB0 000F4F10  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7FB4 000F4F14  38 60 00 08 */	li r3, 8
/* 800F7FB8 000F4F18  93 C4 00 18 */	stw r30, 0x18(r4)
/* 800F7FBC 000F4F1C  4B F4 F0 49 */	bl alloc__6SystemFUl
/* 800F7FC0 000F4F20  3B C3 00 00 */	addi r30, r3, 0
/* 800F7FC4 000F4F24  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7FC8 000F4F28  41 82 00 0C */	beq .L_800F7FD4
/* 800F7FCC 000F4F2C  38 80 00 07 */	li r4, 7
/* 800F7FD0 000F4F30  48 02 6F F9 */	bl __ct__10PaniMotionFi
.L_800F7FD4:
/* 800F7FD4 000F4F34  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7FD8 000F4F38  38 60 00 08 */	li r3, 8
/* 800F7FDC 000F4F3C  93 C4 00 1C */	stw r30, 0x1c(r4)
/* 800F7FE0 000F4F40  4B F4 F0 25 */	bl alloc__6SystemFUl
/* 800F7FE4 000F4F44  3B C3 00 00 */	addi r30, r3, 0
/* 800F7FE8 000F4F48  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7FEC 000F4F4C  41 82 00 0C */	beq .L_800F7FF8
/* 800F7FF0 000F4F50  38 80 00 08 */	li r4, 8
/* 800F7FF4 000F4F54  48 02 6F D5 */	bl __ct__10PaniMotionFi
.L_800F7FF8:
/* 800F7FF8 000F4F58  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7FFC 000F4F5C  38 60 00 08 */	li r3, 8
/* 800F8000 000F4F60  93 C4 00 20 */	stw r30, 0x20(r4)
/* 800F8004 000F4F64  4B F4 F0 01 */	bl alloc__6SystemFUl
/* 800F8008 000F4F68  3B C3 00 00 */	addi r30, r3, 0
/* 800F800C 000F4F6C  7F C3 F3 79 */	or. r3, r30, r30
/* 800F8010 000F4F70  41 82 00 0C */	beq .L_800F801C
/* 800F8014 000F4F74  38 80 00 09 */	li r4, 9
/* 800F8018 000F4F78  48 02 6F B1 */	bl __ct__10PaniMotionFi
.L_800F801C:
/* 800F801C 000F4F7C  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F8020 000F4F80  38 60 00 08 */	li r3, 8
/* 800F8024 000F4F84  93 C4 00 24 */	stw r30, 0x24(r4)
/* 800F8028 000F4F88  4B F4 EF DD */	bl alloc__6SystemFUl
/* 800F802C 000F4F8C  3B C3 00 00 */	addi r30, r3, 0
/* 800F8030 000F4F90  7F C3 F3 79 */	or. r3, r30, r30
/* 800F8034 000F4F94  41 82 00 0C */	beq .L_800F8040
/* 800F8038 000F4F98  38 80 00 0A */	li r4, 0xa
/* 800F803C 000F4F9C  48 02 6F 8D */	bl __ct__10PaniMotionFi
.L_800F8040:
/* 800F8040 000F4FA0  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F8044 000F4FA4  38 60 00 08 */	li r3, 8
/* 800F8048 000F4FA8  93 C4 00 28 */	stw r30, 0x28(r4)
/* 800F804C 000F4FAC  4B F4 EF B9 */	bl alloc__6SystemFUl
/* 800F8050 000F4FB0  3B C3 00 00 */	addi r30, r3, 0
/* 800F8054 000F4FB4  7F C3 F3 79 */	or. r3, r30, r30
/* 800F8058 000F4FB8  41 82 00 0C */	beq .L_800F8064
/* 800F805C 000F4FBC  38 80 00 0B */	li r4, 0xb
/* 800F8060 000F4FC0  48 02 6F 69 */	bl __ct__10PaniMotionFi
.L_800F8064:
/* 800F8064 000F4FC4  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F8068 000F4FC8  38 60 00 08 */	li r3, 8
/* 800F806C 000F4FCC  93 C4 00 2C */	stw r30, 0x2c(r4)
/* 800F8070 000F4FD0  4B F4 EF 95 */	bl alloc__6SystemFUl
/* 800F8074 000F4FD4  3B C3 00 00 */	addi r30, r3, 0
/* 800F8078 000F4FD8  7F C3 F3 79 */	or. r3, r30, r30
/* 800F807C 000F4FDC  41 82 00 0C */	beq .L_800F8088
/* 800F8080 000F4FE0  38 80 00 0C */	li r4, 0xc
/* 800F8084 000F4FE4  48 02 6F 45 */	bl __ct__10PaniMotionFi
.L_800F8088:
/* 800F8088 000F4FE8  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F808C 000F4FEC  38 60 00 08 */	li r3, 8
/* 800F8090 000F4FF0  93 C4 00 30 */	stw r30, 0x30(r4)
/* 800F8094 000F4FF4  4B F4 EF 71 */	bl alloc__6SystemFUl
/* 800F8098 000F4FF8  3B C3 00 00 */	addi r30, r3, 0
/* 800F809C 000F4FFC  7F C3 F3 79 */	or. r3, r30, r30
/* 800F80A0 000F5000  41 82 00 0C */	beq .L_800F80AC
/* 800F80A4 000F5004  38 80 00 0D */	li r4, 0xd
/* 800F80A8 000F5008  48 02 6F 21 */	bl __ct__10PaniMotionFi
.L_800F80AC:
/* 800F80AC 000F500C  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F80B0 000F5010  38 60 00 08 */	li r3, 8
/* 800F80B4 000F5014  93 C4 00 34 */	stw r30, 0x34(r4)
/* 800F80B8 000F5018  4B F4 EF 4D */	bl alloc__6SystemFUl
/* 800F80BC 000F501C  3B C3 00 00 */	addi r30, r3, 0
/* 800F80C0 000F5020  7F C3 F3 79 */	or. r3, r30, r30
/* 800F80C4 000F5024  41 82 00 0C */	beq .L_800F80D0
/* 800F80C8 000F5028  38 80 00 0E */	li r4, 0xe
/* 800F80CC 000F502C  48 02 6E FD */	bl __ct__10PaniMotionFi
.L_800F80D0:
/* 800F80D0 000F5030  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F80D4 000F5034  7F E3 FB 78 */	mr r3, r31
/* 800F80D8 000F5038  93 C4 00 38 */	stw r30, 0x38(r4)
/* 800F80DC 000F503C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F80E0 000F5040  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F80E4 000F5044  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800F80E8 000F5048  38 21 00 18 */	addi r1, r1, 0x18
/* 800F80EC 000F504C  7C 08 03 A6 */	mtlr r0
/* 800F80F0 000F5050  4E 80 00 20 */	blr 

.global __ct__16PaniItemAnimatorFv
__ct__16PaniItemAnimatorFv:
/* 800F80F4 000F5054  7C 08 02 A6 */	mflr r0
/* 800F80F8 000F5058  90 01 00 04 */	stw r0, 4(r1)
/* 800F80FC 000F505C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F8100 000F5060  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F8104 000F5064  7C 7F 1B 78 */	mr r31, r3
/* 800F8108 000F5068  48 02 6F D9 */	bl __ct__12PaniAnimatorFv
/* 800F810C 000F506C  3C 60 80 2C */	lis r3, __vt__16PaniItemAnimator@ha
/* 800F8110 000F5070  38 03 FF 98 */	addi r0, r3, __vt__16PaniItemAnimator@l
/* 800F8114 000F5074  90 1F 00 30 */	stw r0, 0x30(r31)
/* 800F8118 000F5078  7F E3 FB 78 */	mr r3, r31
/* 800F811C 000F507C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F8120 000F5080  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F8124 000F5084  38 21 00 18 */	addi r1, r1, 0x18
/* 800F8128 000F5088  7C 08 03 A6 */	mtlr r0
/* 800F812C 000F508C  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BFEE0:
	.asciz "paniItemAnimator.cpp"
.balign 4
lbl_802BFEF8:
	.asciz "paniItemAnimator"
.balign 4
.global motionLabels__16PaniItemAnimator
motionLabels__16PaniItemAnimator:
	.4byte lbl_803E1F20
	.4byte lbl_803E1F24
	.4byte lbl_803E1F28
	.4byte lbl_803E1F2C
	.4byte lbl_803E1F30
	.4byte lbl_803E1F34
	.4byte lbl_803E1F38
	.4byte lbl_803E1F3C
	.4byte lbl_803E1F40
	.4byte lbl_803E1F44
	.4byte lbl_803E1F48
	.4byte lbl_803E1F4C
	.4byte lbl_803E1F50
	.4byte lbl_803E1F54
	.4byte lbl_803E1F58
.balign 4
lbl_802BFF48:
	.asciz "PaniItemAnimator"
.balign 4
lbl_802BFF5C:
	.asciz "Animator"
.balign 4
lbl_802BFF68:
	.asciz "PaniAnimator"
.balign 4
lbl_802BFF78:
	.4byte __RTTI__8Animator
	.4byte 0
	.4byte 0
lbl_802BFF84:
	.4byte __RTTI__8Animator
	.4byte 0
	.4byte __RTTI__12PaniAnimator
	.4byte 0
	.4byte 0
.global __vt__16PaniItemAnimator
__vt__16PaniItemAnimator:
	.4byte __RTTI__16PaniItemAnimator
	.4byte 0
	.4byte changeContext__12PaniAnimatorFP11AnimContext
	.4byte animate__12PaniAnimatorFf
	.4byte finishOneShot__8AnimatorFv
	.4byte finishLoop__8AnimatorFv
	.4byte updateContext__12PaniAnimatorFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E1F20:
	.asciz "1"
.balign 4
lbl_803E1F24:
	.asciz "2"
.balign 4
lbl_803E1F28:
	.asciz "3"
.balign 4
lbl_803E1F2C:
	.asciz "4"
.balign 4
lbl_803E1F30:
	.asciz "5"
.balign 4
lbl_803E1F34:
	.asciz "6"
.balign 4
lbl_803E1F38:
	.asciz "7"
.balign 4
lbl_803E1F3C:
	.asciz "8"
.balign 4
lbl_803E1F40:
	.asciz "9"
.balign 4
lbl_803E1F44:
	.asciz "10"
.balign 4
lbl_803E1F48:
	.asciz "11"
.balign 4
lbl_803E1F4C:
	.asciz "12"
.balign 4
lbl_803E1F50:
	.asciz "13"
.balign 4
lbl_803E1F54:
	.asciz "14"
.balign 4
lbl_803E1F58:
	.asciz "15"
.balign 4
__RTTI__8Animator:
	.4byte lbl_802BFF5C
	.4byte 0
__RTTI__12PaniAnimator:
	.4byte lbl_802BFF68
	.4byte lbl_802BFF78
__RTTI__16PaniItemAnimator:
	.4byte lbl_802BFF48
	.4byte lbl_802BFF84
