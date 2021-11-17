.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global addAnimation__12TAIanimationFPc
addAnimation__12TAIanimationFPc:
/* 801A3594 001A04F4  7C 08 02 A6 */	mflr r0
/* 801A3598 001A04F8  38 A0 00 01 */	li r5, 1
/* 801A359C 001A04FC  90 01 00 04 */	stw r0, 4(r1)
/* 801A35A0 001A0500  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A35A4 001A0504  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A35A8 001A0508  7C 7F 1B 78 */	mr r31, r3
/* 801A35AC 001A050C  80 63 00 04 */	lwz r3, 4(r3)
/* 801A35B0 001A0510  4B EA D7 3D */	bl addAnimation__7AnimMgrFPcb
/* 801A35B4 001A0514  90 7F 00 08 */	stw r3, 8(r31)
/* 801A35B8 001A0518  80 7F 00 08 */	lwz r3, 8(r31)
/* 801A35BC 001A051C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A35C0 001A0520  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A35C4 001A0524  38 21 00 18 */	addi r1, r1, 0x18
/* 801A35C8 001A0528  7C 08 03 A6 */	mtlr r0
/* 801A35CC 001A052C  4E 80 00 20 */	blr 
