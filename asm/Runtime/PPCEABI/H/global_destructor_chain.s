.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __destroy_global_chain
__destroy_global_chain:
/* 80214964 002118C4  7C 08 02 A6 */	mflr r0
/* 80214968 002118C8  90 01 00 04 */	stw r0, 4(r1)
/* 8021496C 002118CC  94 21 FF F8 */	stwu r1, -8(r1)
/* 80214970 002118D0  48 00 00 20 */	b .L_80214990
.L_80214974:
/* 80214974 002118D4  80 03 00 00 */	lwz r0, 0(r3)
/* 80214978 002118D8  38 80 FF FF */	li r4, -1
/* 8021497C 002118DC  90 0D 34 70 */	stw r0, __global_destructor_chain@sda21(r13)
/* 80214980 002118E0  81 83 00 04 */	lwz r12, 4(r3)
/* 80214984 002118E4  80 63 00 08 */	lwz r3, 8(r3)
/* 80214988 002118E8  7D 88 03 A6 */	mtlr r12
/* 8021498C 002118EC  4E 80 00 21 */	blrl 
.L_80214990:
/* 80214990 002118F0  80 6D 34 70 */	lwz r3, __global_destructor_chain@sda21(r13)
/* 80214994 002118F4  28 03 00 00 */	cmplwi r3, 0
/* 80214998 002118F8  40 82 FF DC */	bne .L_80214974
/* 8021499C 002118FC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 802149A0 00211900  38 21 00 08 */	addi r1, r1, 8
/* 802149A4 00211904  7C 08 03 A6 */	mtlr r0
/* 802149A8 00211908  4E 80 00 20 */	blr 

.global __register_global_object
__register_global_object:
/* 802149AC 0021190C  80 0D 34 70 */	lwz r0, __global_destructor_chain@sda21(r13)
/* 802149B0 00211910  90 05 00 00 */	stw r0, 0(r5)
/* 802149B4 00211914  90 85 00 04 */	stw r4, 4(r5)
/* 802149B8 00211918  90 65 00 08 */	stw r3, 8(r5)
/* 802149BC 0021191C  90 AD 34 70 */	stw r5, __global_destructor_chain@sda21(r13)
/* 802149C0 00211920  4E 80 00 20 */	blr 

.section .sbss, "wa"
.balign 8
.global __global_destructor_chain
__global_destructor_chain:
	.skip 0x4
