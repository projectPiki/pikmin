.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80122F6C 0011FECC  40 81 00 1C */	ble lbl_80122F88
/* 80122F70 0011FED0  EC 00 10 28 */	fsubs f0, f0, f2
/* 80122F74 0011FED4  D0 03 00 D4 */	stfs f0, 0xd4(r3)
/* 80122F78 0011FED8  C0 03 00 D4 */	lfs f0, 0xd4(r3)
/* 80122F7C 0011FEDC  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 80122F80 0011FEE0  40 80 00 08 */	bge lbl_80122F88
/* 80122F84 0011FEE4  D0 23 00 D4 */	stfs f1, 0xd4(r3)
lbl_80122F88:
/* 80122F88 0011FEE8  C0 03 00 D8 */	lfs f0, 0xd8(r3)
/* 80122F8C 0011FEEC  38 63 00 04 */	addi r3, r3, 4
/* 80122F90 0011FEF0  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 80122F94 0011FEF4  4C 81 00 20 */	blelr 
/* 80122F98 0011FEF8  EC 00 10 28 */	fsubs f0, f0, f2
/* 80122F9C 0011FEFC  D0 03 00 D4 */	stfs f0, 0xd4(r3)
/* 80122FA0 0011FF00  C0 03 00 D4 */	lfs f0, 0xd4(r3)
/* 80122FA4 0011FF04  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 80122FA8 0011FF08  4C 80 00 20 */	bgelr 
/* 80122FAC 0011FF0C  D0 23 00 D4 */	stfs f1, 0xd4(r3)
/* 80122FB0 0011FF10  4E 80 00 20 */	blr 

.global startMotion__10PcamCameraFii
startMotion__10PcamCameraFii:
/* 80122FB4 0011FF14  7C 08 02 A6 */	mflr r0
/* 80122FB8 0011FF18  90 01 00 04 */	stw r0, 4(r1)
/* 80122FBC 0011FF1C  94 21 FF F8 */	stwu r1, -8(r1)
/* 80122FC0 0011FF20  90 83 00 88 */	stw r4, 0x88(r3)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x736d6172
	.4byte 0x74507472
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x736d6172
	.4byte 0x74507472
	.4byte 0
	.4byte 0x52656643
	.4byte 0x6f756e74
	.4byte 0x61626c65
	.4byte 0
.global __vt__12RefCountable
__vt__12RefCountable:
	.4byte 0x803E14b0
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x802BADFC
	.4byte 0x802BAE08
