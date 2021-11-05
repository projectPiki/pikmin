.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80136D64 00133CC4  54 E8 10 3A */	slwi r8, r7, 2
/* 80136D68 00133CC8  7F 45 01 2E */	stwx r26, r5, r0
/* 80136D6C 00133CCC  54 C6 10 3A */	slwi r6, r6, 2
/* 80136D70 00133CD0  54 67 10 3A */	slwi r7, r3, 2
/* 80136D74 00133CD4  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136D78 00133CD8  54 80 10 3A */	slwi r0, r4, 2
/* 80136D7C 00133CDC  55 25 10 3A */	slwi r5, r9, 2
/* 80136D80 00133CE0  7F C3 41 2E */	stwx r30, r3, r8
/* 80136D84 00133CE4  38 60 00 0C */	li r3, 0xc
/* 80136D88 00133CE8  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136D8C 00133CEC  7F 84 31 2E */	stwx r28, r4, r6
/* 80136D90 00133CF0  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136D94 00133CF4  7E E4 39 2E */	stwx r23, r4, r7
/* 80136D98 00133CF8  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136D9C 00133CFC  7F 64 01 2E */	stwx r27, r4, r0
/* 80136DA0 00133D00  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136DA4 00133D04  7F A4 29 2E */	stwx r29, r4, r5
/* 80136DA8 00133D08  80 99 00 08 */	lwz r4, 8(r25)
/* 80136DAC 00133D0C  93 E4 00 10 */	stw r31, 0x10(r4)
/* 80136DB0 00133D10  4B F1 02 55 */	bl alloc__6SystemFUl
/* 80136DB4 00133D14  3B 83 00 00 */	addi r28, r3, 0
/* 80136DB8 00133D18  7F 80 E3 79 */	or. r0, r28, r28
/* 80136DBC 00133D1C  41 82 00 2C */	beq lbl_80136DE8
/* 80136DC0 00133D20  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136DC4 00133D24  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136DC8 00133D28  90 1C 00 04 */	stw r0, 4(r28)
/* 80136DCC 00133D2C  38 00 00 06 */	li r0, 6
/* 80136DD0 00133D30  3C 60 80 2D */	lis r3, __vt__29TaiNapkidStraightFlyingAction@ha
/* 80136DD4 00133D34  90 1C 00 00 */	stw r0, 0(r28)
/* 80136DD8 00133D38  38 03 A6 1C */	addi r0, r3, __vt__29TaiNapkidStraightFlyingAction@l
/* 80136DDC 00133D3C  90 1C 00 04 */	stw r0, 4(r28)
/* 80136DE0 00133D40  C0 02 A4 D8 */	lfs f0, lbl_803EA6D8@sda21(r2)
/* 80136DE4 00133D44  D0 1C 00 08 */	stfs f0, 8(r28)
lbl_80136DE8:
/* 80136DE8 00133D48  38 60 00 14 */	li r3, 0x14
/* 80136DEC 00133D4C  4B F1 02 19 */	bl alloc__6SystemFUl
/* 80136DF0 00133D50  3B A3 00 00 */	addi r29, r3, 0
/* 80136DF4 00133D54  7F A0 EB 79 */	or. r0, r29, r29
/* 80136DF8 00133D58  41 82 00 3C */	beq lbl_80136E34
/* 80136DFC 00133D5C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136E00 00133D60  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136E04 00133D64  90 1D 00 04 */	stw r0, 4(r29)
/* 80136E08 00133D68  38 00 00 06 */	li r0, 6
/* 80136E0C 00133D6C  3C 60 80 2D */	lis r3, __vt__14TaiTimerAction@ha
/* 80136E10 00133D70  90 1D 00 00 */	stw r0, 0(r29)
/* 80136E14 00133D74  38 63 CA 28 */	addi r3, r3, __vt__14TaiTimerAction@l
/* 80136E18 00133D78  38 00 00 00 */	li r0, 0
/* 80136E1C 00133D7C  90 7D 00 04 */	stw r3, 4(r29)
/* 80136E20 00133D80  90 1D 00 08 */	stw r0, 8(r29)
/* 80136E24 00133D84  C0 02 A4 DC */	lfs f0, lbl_803EA6DC@sda21(r2)
/* 80136E28 00133D88  D0 1D 00 0C */	stfs f0, 0xc(r29)
/* 80136E2C 00133D8C  C0 02 A4 68 */	lfs f0, lbl_803EA668@sda21(r2)
/* 80136E30 00133D90  D0 1D 00 10 */	stfs f0, 0x10(r29)
lbl_80136E34:
/* 80136E34 00133D94  38 60 00 0C */	li r3, 0xc
/* 80136E38 00133D98  4B F1 01 CD */	bl alloc__6SystemFUl
/* 80136E3C 00133D9C  3B C3 00 00 */	addi r30, r3, 0
/* 80136E40 00133DA0  7F C0 F3 79 */	or. r0, r30, r30
/* 80136E44 00133DA4  41 82 00 38 */	beq lbl_80136E7C
/* 80136E48 00133DA8  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80136E4C 00133DAC  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80136E50 00133DB0  90 1E 00 04 */	stw r0, 4(r30)
/* 80136E54 00133DB4  38 00 FF FF */	li r0, -1
/* 80136E58 00133DB8  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 80136E5C 00133DBC  90 1E 00 00 */	stw r0, 0(r30)
/* 80136E60 00133DC0  38 03 95 94 */	addi r0, r3, __vt__15TaiMotionAction@l
/* 80136E64 00133DC4  3C 60 80 2D */	lis r3, __vt__25TaiContinuousMotionAction@ha
/* 80136E68 00133DC8  90 1E 00 04 */	stw r0, 4(r30)
/* 80136E6C 00133DCC  38 00 00 06 */	li r0, 6
/* 80136E70 00133DD0  38 63 95 74 */	addi r3, r3, __vt__25TaiContinuousMotionAction@l
/* 80136E74 00133DD4  90 1E 00 08 */	stw r0, 8(r30)
/* 80136E78 00133DD8  90 7E 00 04 */	stw r3, 4(r30)
lbl_80136E7C:
/* 80136E7C 00133DDC  38 60 00 0C */	li r3, 0xc
/* 80136E80 00133DE0  4B F1 01 85 */	bl alloc__6SystemFUl
/* 80136E84 00133DE4  3B E3 00 00 */	addi r31, r3, 0
/* 80136E88 00133DE8  7F E3 FB 79 */	or. r3, r31, r31
/* 80136E8C 00133DEC  41 82 00 0C */	beq lbl_80136E98
/* 80136E90 00133DF0  38 80 00 08 */	li r4, 8
/* 80136E94 00133DF4  4B FF 02 05 */	bl __ct__8TaiStateFi
lbl_80136E98:
/* 80136E98 00133DF8  38 00 00 00 */	li r0, 0
/* 80136E9C 00133DFC  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136EA0 00133E00  54 00 10 3A */	slwi r0, r0, 2
/* 80136EA4 00133E04  7F 03 01 2E */	stwx r24, r3, r0
/* 80136EA8 00133E08  38 80 00 01 */	li r4, 1
/* 80136EAC 00133E0C  38 00 00 02 */	li r0, 2
/* 80136EB0 00133E10  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136EB4 00133E14  54 84 10 3A */	slwi r4, r4, 2
/* 80136EB8 00133E18  38 A0 00 03 */	li r5, 3
/* 80136EBC 00133E1C  7E A3 21 2E */	stwx r21, r3, r4
/* 80136EC0 00133E20  38 80 00 04 */	li r4, 4
/* 80136EC4 00133E24  38 E0 00 05 */	li r7, 5
/* 80136EC8 00133E28  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136ECC 00133E2C  54 00 10 3A */	slwi r0, r0, 2
/* 80136ED0 00133E30  38 C0 00 06 */	li r6, 6
/* 80136ED4 00133E34  7E 83 01 2E */	stwx r20, r3, r0
/* 80136ED8 00133E38  38 00 00 07 */	li r0, 7
/* 80136EDC 00133E3C  54 A5 10 3A */	slwi r5, r5, 2
/* 80136EE0 00133E40  80 7F 00 08 */	lwz r3, 8(r31)
/* 80136EE4 00133E44  54 84 10 3A */	slwi r4, r4, 2
/* 80136EE8 00133E48  54 E7 10 3A */	slwi r7, r7, 2
/* 80136EEC 00133E4C  7F 43 29 2E */	stwx r26, r3, r5
/* 80136EF0 00133E50  54 C5 10 3A */	slwi r5, r6, 2
/* 80136EF4 00133E54  54 00 10 3A */	slwi r0, r0, 2
/* 80136EF8 00133E58  80 DF 00 08 */	lwz r6, 8(r31)
/* 80136EFC 00133E5C  38 60 00 08 */	li r3, 8
/* 80136F00 00133E60  7E E6 21 2E */	stwx r23, r6, r4
/* 80136F04 00133E64  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136F08 00133E68  7F 84 39 2E */	stwx r28, r4, r7
/* 80136F0C 00133E6C  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136F10 00133E70  7F A4 29 2E */	stwx r29, r4, r5
/* 80136F14 00133E74  80 9F 00 08 */	lwz r4, 8(r31)
/* 80136F18 00133E78  7F C4 01 2E */	stwx r30, r4, r0

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x67656e4e
  .4byte 0x6176692e
  .4byte 0x63707000
.global lbl_802BFFC4
lbl_802BFFC4:
	.4byte 0x6F626A65
	.4byte 0x63742074
	.4byte 0x79706500
.global lbl_802BFFD0
lbl_802BFFD0:
	.4byte 0x8376838C
	.4byte 0x83438384
	.4byte 0x815B8251
	.4byte 0x82F090B6
	.4byte 0x82DE0000
.global lbl_802BFFE4
lbl_802BFFE4:
	.4byte 0x67656E65
	.4byte 0x72617465
	.4byte 0x204E4156
	.4byte 0x49202870
	.4byte 0x6C617965
	.4byte 0x72322900
	.4byte 0x47656E4F
	.4byte 0x626A6563
	.4byte 0x744E6176
	.4byte 0x69000000
	.4byte 0x50617261
	.4byte 0x6D657465
	.4byte 0x72730000
	.4byte 0x803E1F78
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x47656E4F
	.4byte 0x626A6563
	.4byte 0x74000000
	.4byte 0x803E1F78
	.4byte 0x00000000
	.4byte 0x803E1F88
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x803E1F78
	.4byte 0x00000000
	.4byte 0x803E1F88
	.4byte 0x00000000
	.4byte 0x803E1F90
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__13GenObjectNavi
__vt__13GenObjectNavi:
  .4byte __RTTI__13GenObjectNavi
  .4byte 0
  .4byte doWrite__7GenBaseFR18RandomAccessStream
  .4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
  .4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
  .4byte doRead__13GenObjectNaviFR18RandomAccessStream
  .4byte update__7GenBaseFv
  .4byte render__7GenBaseFR8Graphics
  .4byte getLatestVersion__9GenObjectFv
  .4byte updateUseList__9GenObjectFP9Generatori
  .4byte init__9GenObjectFP9Generator
  .4byte update__9GenObjectFP9Generator
  .4byte render__9GenObjectFR8GraphicsP9Generator
  .4byte birth__13GenObjectNaviFR9BirthInfo

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
  .4byte 0x31310000
  .4byte 0x31320000
  .4byte 0x31330000
  .4byte 0x31340000
  .4byte 0x31350000
  .4byte 0x802bff5c
  .4byte 0
  .4byte 0x802bff68
  .4byte 0x802bff78
.global __RTTI__16PaniItemAnimator
__RTTI__16PaniItemAnimator:
  .4byte 0x802bff48
