.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.global V3D_GetAngle__FP9Vector3D_
V3D_GetAngle__FP9Vector3D_:
/* 8001BB60 00018AC0  7C 08 02 A6 */	mflr r0
/* 8001BB64 00018AC4  90 01 00 04 */	stw r0, 4(r1)
/* 8001BB68 00018AC8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8001BB6C 00018ACC  C0 23 00 00 */	lfs f1, 0(r3)
/* 8001BB70 00018AD0  C0 43 00 04 */	lfs f2, 4(r3)
/* 8001BB74 00018AD4  4B FF 21 4D */	bl atanf2__Fff
/* 8001BB78 00018AD8  C8 02 82 00 */	lfd f0, lbl_803E8400@sda21(r2)
/* 8001BB7C 00018ADC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8001BB80 00018AE0  FC 20 08 2A */	fadd f1, f0, f1
/* 8001BB84 00018AE4  FC 20 08 18 */	frsp f1, f1
/* 8001BB88 00018AE8  38 21 00 08 */	addi r1, r1, 8
/* 8001BB8C 00018AEC  7C 08 03 A6 */	mtlr r0
/* 8001BB90 00018AF0  4E 80 00 20 */	blr 

.balign 32, 0
.global V3D_Abs__FP9Vector3D_
V3D_Abs__FP9Vector3D_:
/* 8001BBA0 00018B00  7C 08 02 A6 */	mflr r0
/* 8001BBA4 00018B04  90 01 00 04 */	stw r0, 4(r1)
/* 8001BBA8 00018B08  94 21 FF F8 */	stwu r1, -8(r1)
/* 8001BBAC 00018B0C  C0 23 00 00 */	lfs f1, 0(r3)
/* 8001BBB0 00018B10  C0 03 00 04 */	lfs f0, 4(r3)
/* 8001BBB4 00018B14  EC 21 00 72 */	fmuls f1, f1, f1
/* 8001BBB8 00018B18  C0 43 00 08 */	lfs f2, 8(r3)
/* 8001BBBC 00018B1C  EC 00 00 32 */	fmuls f0, f0, f0
/* 8001BBC0 00018B20  EC 42 00 B2 */	fmuls f2, f2, f2
/* 8001BBC4 00018B24  EC 01 00 2A */	fadds f0, f1, f0
/* 8001BBC8 00018B28  EC 22 00 2A */	fadds f1, f2, f0
/* 8001BBCC 00018B2C  4B FF 20 55 */	bl sqrtf2__Ff
/* 8001BBD0 00018B30  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8001BBD4 00018B34  38 21 00 08 */	addi r1, r1, 8
/* 8001BBD8 00018B38  7C 08 03 A6 */	mtlr r0
/* 8001BBDC 00018B3C  4E 80 00 20 */	blr 

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E8400: #pi as double
	.double 3.141592
