.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.fn sqrtf2__Ff, global
/* 8000DC20 0000AB80  7C 08 02 A6 */	mflr r0
/* 8000DC24 0000AB84  90 01 00 04 */	stw r0, 4(r1)
/* 8000DC28 0000AB88  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000DC2C 0000AB8C  48 00 00 15 */	bl sqrtf__3stdFf
/* 8000DC30 0000AB90  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000DC34 0000AB94  38 21 00 08 */	addi r1, r1, 8
/* 8000DC38 0000AB98  7C 08 03 A6 */	mtlr r0
/* 8000DC3C 0000AB9C  4E 80 00 20 */	blr 
.endfn sqrtf2__Ff

.balign 32, 0
.fn sqrtf__3stdFf, weak
/* 8000DC40 0000ABA0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8000DC44 0000ABA4  C0 02 80 A0 */	lfs f0, lbl_803E82A0@sda21(r2)
/* 8000DC48 0000ABA8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8000DC4C 0000ABAC  40 81 00 50 */	ble .L_8000DC9C
/* 8000DC50 0000ABB0  FC 40 08 34 */	frsqrte f2, f1
/* 8000DC54 0000ABB4  C8 82 80 A8 */	lfd f4, lbl_803E82A8@sda21(r2)
/* 8000DC58 0000ABB8  C8 62 80 B0 */	lfd f3, lbl_803E82B0@sda21(r2)
/* 8000DC5C 0000ABBC  FC 02 00 B2 */	fmul f0, f2, f2
/* 8000DC60 0000ABC0  FC 44 00 B2 */	fmul f2, f4, f2
/* 8000DC64 0000ABC4  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 8000DC68 0000ABC8  FC 42 00 32 */	fmul f2, f2, f0
/* 8000DC6C 0000ABCC  FC 02 00 B2 */	fmul f0, f2, f2
/* 8000DC70 0000ABD0  FC 44 00 B2 */	fmul f2, f4, f2
/* 8000DC74 0000ABD4  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 8000DC78 0000ABD8  FC 42 00 32 */	fmul f2, f2, f0
/* 8000DC7C 0000ABDC  FC 02 00 B2 */	fmul f0, f2, f2
/* 8000DC80 0000ABE0  FC 44 00 B2 */	fmul f2, f4, f2
/* 8000DC84 0000ABE4  FC 01 18 3C */	fnmsub f0, f1, f0, f3
/* 8000DC88 0000ABE8  FC 02 00 32 */	fmul f0, f2, f0
/* 8000DC8C 0000ABEC  FC 01 00 32 */	fmul f0, f1, f0
/* 8000DC90 0000ABF0  FC 00 00 18 */	frsp f0, f0
/* 8000DC94 0000ABF4  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8000DC98 0000ABF8  C0 21 00 0C */	lfs f1, 0xc(r1)
.L_8000DC9C:
/* 8000DC9C 0000ABFC  38 21 00 10 */	addi r1, r1, 0x10
/* 8000DCA0 0000AC00  4E 80 00 20 */	blr 
.endfn sqrtf__3stdFf

.balign 32, 0
.fn atanf2__Fff, global
/* 8000DCC0 0000AC20  7C 08 02 A6 */	mflr r0
/* 8000DCC4 0000AC24  90 01 00 04 */	stw r0, 4(r1)
/* 8000DCC8 0000AC28  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000DCCC 0000AC2C  48 20 DA 1D */	bl atan2
/* 8000DCD0 0000AC30  FC 20 08 18 */	frsp f1, f1
/* 8000DCD4 0000AC34  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000DCD8 0000AC38  38 21 00 08 */	addi r1, r1, 8
/* 8000DCDC 0000AC3C  7C 08 03 A6 */	mtlr r0
/* 8000DCE0 0000AC40  4E 80 00 20 */	blr 
.endfn atanf2__Fff

.balign 32, 0
.fn Jac_InitSinTable__Fv, global
/* 8000DD00 0000AC60  7C 08 02 A6 */	mflr r0
/* 8000DD04 0000AC64  90 01 00 04 */	stw r0, 4(r1)
/* 8000DD08 0000AC68  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8000DD0C 0000AC6C  39 61 00 38 */	addi r11, r1, 0x38
/* 8000DD10 0000AC70  48 20 71 51 */	bl _savefpr_29
/* 8000DD14 0000AC74  BF 81 00 10 */	stmw r28, 0x10(r1)
/* 8000DD18 0000AC78  3C 60 80 31 */	lis r3, SINTABLE@ha
/* 8000DD1C 0000AC7C  C3 A2 80 B8 */	lfs f29, lbl_803E82B8@sda21(r2)
/* 8000DD20 0000AC80  CB C2 80 C0 */	lfd f30, lbl_803E82C0@sda21(r2)
/* 8000DD24 0000AC84  3B C3 DA E0 */	addi r30, r3, SINTABLE@l
/* 8000DD28 0000AC88  C3 E2 80 BC */	lfs f31, lbl_803E82BC@sda21(r2)
/* 8000DD2C 0000AC8C  3B 80 00 00 */	li r28, 0
/* 8000DD30 0000AC90  3B E0 00 00 */	li r31, 0
/* 8000DD34 0000AC94  3F A0 43 30 */	lis r29, 0x4330
.L_8000DD38:
/* 8000DD38 0000AC98  93 81 00 0C */	stw r28, 0xc(r1)
/* 8000DD3C 0000AC9C  93 A1 00 08 */	stw r29, 8(r1)
/* 8000DD40 0000ACA0  C8 01 00 08 */	lfd f0, 8(r1)
/* 8000DD44 0000ACA4  EC 00 F0 28 */	fsubs f0, f0, f30
/* 8000DD48 0000ACA8  EC 1D 00 32 */	fmuls f0, f29, f0
/* 8000DD4C 0000ACAC  EC 20 07 F2 */	fmuls f1, f0, f31
/* 8000DD50 0000ACB0  48 20 DF 99 */	bl sinf
/* 8000DD54 0000ACB4  3B 9C 00 01 */	addi r28, r28, 1
/* 8000DD58 0000ACB8  7C 7E FA 14 */	add r3, r30, r31
/* 8000DD5C 0000ACBC  28 1C 01 01 */	cmplwi r28, 0x101
/* 8000DD60 0000ACC0  D0 23 00 00 */	stfs f1, 0(r3)
/* 8000DD64 0000ACC4  3B FF 00 04 */	addi r31, r31, 4
/* 8000DD68 0000ACC8  41 80 FF D0 */	blt .L_8000DD38
/* 8000DD6C 0000ACCC  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8000DD70 0000ACD0  39 61 00 38 */	addi r11, r1, 0x38
/* 8000DD74 0000ACD4  48 20 71 39 */	bl _restfpr_29
/* 8000DD78 0000ACD8  BB 81 00 10 */	lmw r28, 0x10(r1)
/* 8000DD7C 0000ACDC  38 21 00 38 */	addi r1, r1, 0x38
/* 8000DD80 0000ACE0  7C 08 03 A6 */	mtlr r0
/* 8000DD84 0000ACE4  4E 80 00 20 */	blr 
.endfn Jac_InitSinTable__Fv

.balign 32, 0
.fn sinf3__Ff, global
/* 8000DDA0 0000AD00  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000DDA4 0000AD04  3C 60 80 31 */	lis r3, SINTABLE@ha
/* 8000DDA8 0000AD08  38 03 DA E0 */	addi r0, r3, SINTABLE@l
/* 8000DDAC 0000AD0C  C0 02 80 C8 */	lfs f0, lbl_803E82C8@sda21(r2)
/* 8000DDB0 0000AD10  EC 00 00 72 */	fmuls f0, f0, f1
/* 8000DDB4 0000AD14  FC 00 00 1E */	fctiwz f0, f0
/* 8000DDB8 0000AD18  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 8000DDBC 0000AD1C  80 61 00 14 */	lwz r3, 0x14(r1)
/* 8000DDC0 0000AD20  54 63 10 3A */	slwi r3, r3, 2
/* 8000DDC4 0000AD24  7C 60 1A 14 */	add r3, r0, r3
/* 8000DDC8 0000AD28  C0 23 00 00 */	lfs f1, 0(r3)
/* 8000DDCC 0000AD2C  38 21 00 18 */	addi r1, r1, 0x18
/* 8000DDD0 0000AD30  4E 80 00 20 */	blr 
.endfn sinf3__Ff

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E82A0, local
	.float 0.0
.endobj lbl_803E82A0
.balign 8
.obj lbl_803E82A8, local
	.double 0.5
.endobj lbl_803E82A8
.balign 8
.obj lbl_803E82B0, local
	.double 3.0
.endobj lbl_803E82B0
.obj lbl_803E82B8, local # half pi
	.float 1.5707964
.endobj lbl_803E82B8
.obj lbl_803E82BC, local
	.float 0.00390625
.endobj lbl_803E82BC
.balign 8
.obj lbl_803E82C0, local
	.8byte 0x4330000000000000
.endobj lbl_803E82C0
.obj lbl_803E82C8, local
	.float 256.0
.endobj lbl_803E82C8

.section .bss, "wa"  # 0x802E9640 - 0x803E81E5
.balign 8
.obj SINTABLE, local
	.skip 0x404
.endobj SINTABLE
