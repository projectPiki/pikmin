.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8011985C 001167BC  7F C3 F3 79 */	or. r3, r30, r30
/* 80119860 001167C0  41 82 00 0C */	beq lbl_8011986C
/* 80119864 001167C4  38 80 00 25 */	li r4, 0x25
/* 80119868 001167C8  48 00 57 61 */	bl __ct__10PaniMotionFi
lbl_8011986C:
/* 8011986C 001167CC  80 9F 00 04 */	lwz r4, 4(r31)
/* 80119870 001167D0  38 60 00 08 */	li r3, 8
/* 80119874 001167D4  93 C4 01 40 */	stw r30, 0x140(r4)
/* 80119878 001167D8  4B F2 D7 8D */	bl alloc__6SystemFUl
/* 8011987C 001167DC  3B C3 00 00 */	addi r30, r3, 0
/* 80119880 001167E0  7F C3 F3 79 */	or. r3, r30, r30
/* 80119884 001167E4  41 82 00 0C */	beq lbl_80119890
/* 80119888 001167E8  38 80 00 16 */	li r4, 0x16
/* 8011988C 001167EC  48 00 57 3D */	bl __ct__10PaniMotionFi
lbl_80119890:
/* 80119890 001167F0  80 9F 00 04 */	lwz r4, 4(r31)
/* 80119894 001167F4  38 60 00 08 */	li r3, 8
/* 80119898 001167F8  93 C4 01 44 */	stw r30, 0x144(r4)
/* 8011989C 001167FC  4B F2 D7 69 */	bl alloc__6SystemFUl
/* 801198A0 00116800  3B C3 00 00 */	addi r30, r3, 0
/* 801198A4 00116804  7F C3 F3 79 */	or. r3, r30, r30
/* 801198A8 00116808  41 82 00 0C */	beq lbl_801198B4
/* 801198AC 0011680C  38 80 00 2B */	li r4, 0x2b
/* 801198B0 00116810  48 00 57 19 */	bl __ct__10PaniMotionFi
lbl_801198B4:
/* 801198B4 00116814  80 9F 00 04 */	lwz r4, 4(r31)
/* 801198B8 00116818  38 60 00 08 */	li r3, 8
/* 801198BC 0011681C  93 C4 01 48 */	stw r30, 0x148(r4)
/* 801198C0 00116820  4B F2 D7 45 */	bl alloc__6SystemFUl
/* 801198C4 00116824  3B C3 00 00 */	addi r30, r3, 0
/* 801198C8 00116828  7F C3 F3 79 */	or. r3, r30, r30
/* 801198CC 0011682C  41 82 00 0C */	beq lbl_801198D8
/* 801198D0 00116830  38 80 00 5D */	li r4, 0x5d
/* 801198D4 00116834  48 00 56 F5 */	bl __ct__10PaniMotionFi
lbl_801198D8:
/* 801198D8 00116838  80 9F 00 04 */	lwz r4, 4(r31)
/* 801198DC 0011683C  38 60 00 08 */	li r3, 8
/* 801198E0 00116840  93 C4 01 4C */	stw r30, 0x14c(r4)
/* 801198E4 00116844  4B F2 D7 21 */	bl alloc__6SystemFUl

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x436e6453
  .4byte 0x7469636b
  .4byte 0x4d6f7574
  .4byte 0x68000000
  .4byte 0x436f6e64
  .4byte 0x6974696f
  .4byte 0x6e000000
  .4byte 0x803e1290
  .4byte 0
  .4byte 0
.global __vt__13CndStickMouth
__vt__13CndStickMouth:
  .4byte __RTTI__13CndStickMouth
  .4byte 0
  .4byte satisfy__13CndStickMouthFP8Creature
  .4byte 0x436e6449
  .4byte 0x73417461
  .4byte 0x72690000
  .4byte 0x803e1290
  .4byte 0
  .4byte 0
.global __vt__10CndIsAtari
__vt__10CndIsAtari:
  .4byte __RTTI__10CndIsAtari
  .4byte 0
  .4byte satisfy__10CndIsAtariFP8Creature
  .4byte 0x436e6449
  .4byte 0x73566973
  .4byte 0x69626c65
  .4byte 0
  .4byte 0x803e1290
  .4byte 0
  .4byte 0
.global __vt__12CndIsVisible
__vt__12CndIsVisible:
  .4byte __RTTI__12CndIsVisible
  .4byte 0
  .4byte satisfy__12CndIsVisibleFP8Creature

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x802BA3DC
	.4byte 0x00000000
	.4byte 0x802BA3E8
	.4byte 0x00000000
	.4byte 0x802BA3F8
	.4byte 0x802BA404
	.4byte 0x50696B69
	.4byte 0x00000000
