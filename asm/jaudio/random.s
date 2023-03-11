.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.fn GetRandom_s32, global
/* 8000D740 0000A6A0  7C 08 02 A6 */	mflr r0
/* 8000D744 0000A6A4  90 01 00 04 */	stw r0, 4(r1)
/* 8000D748 0000A6A8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8000D74C 0000A6AC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8000D750 0000A6B0  48 1E B8 2D */	bl OSDisableInterrupts
/* 8000D754 0000A6B4  3C 80 13 58 */	lis r4, 0x13579BDE@ha
/* 8000D758 0000A6B8  80 AD 80 30 */	lwz r5, v0@sda21(r13)
/* 8000D75C 0000A6BC  38 04 9B DE */	addi r0, r4, 0x13579BDE@l
/* 8000D760 0000A6C0  80 CD 80 34 */	lwz r6, v1@sda21(r13)
/* 8000D764 0000A6C4  3C 80 98 76 */	lis r4, 0x98765432@ha
/* 8000D768 0000A6C8  38 84 54 32 */	addi r4, r4, 0x98765432@l
/* 8000D76C 0000A6CC  90 CD 80 30 */	stw r6, v0@sda21(r13)
/* 8000D770 0000A6D0  7C 05 01 D6 */	mullw r0, r5, r0
/* 8000D774 0000A6D4  7C 86 21 D6 */	mullw r4, r6, r4
/* 8000D778 0000A6D8  7C 00 26 70 */	srawi r0, r0, 4
/* 8000D77C 0000A6DC  7F E4 02 14 */	add r31, r4, r0
/* 8000D780 0000A6E0  3B FF 00 01 */	addi r31, r31, 1
/* 8000D784 0000A6E4  93 ED 80 34 */	stw r31, v1@sda21(r13)
/* 8000D788 0000A6E8  48 1E B8 1D */	bl OSRestoreInterrupts
/* 8000D78C 0000A6EC  7F E3 FB 78 */	mr r3, r31
/* 8000D790 0000A6F0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8000D794 0000A6F4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8000D798 0000A6F8  38 21 00 10 */	addi r1, r1, 0x10
/* 8000D79C 0000A6FC  7C 08 03 A6 */	mtlr r0
/* 8000D7A0 0000A700  4E 80 00 20 */	blr 
.endfn GetRandom_s32

.balign 32, 0
.fn GetRandom_u32, global
/* 8000D7C0 0000A720  7C 08 02 A6 */	mflr r0
/* 8000D7C4 0000A724  90 01 00 04 */	stw r0, 4(r1)
/* 8000D7C8 0000A728  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000D7CC 0000A72C  4B FF FF 75 */	bl GetRandom_s32
/* 8000D7D0 0000A730  54 63 00 7E */	clrlwi r3, r3, 1
/* 8000D7D4 0000A734  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000D7D8 0000A738  38 21 00 08 */	addi r1, r1, 8
/* 8000D7DC 0000A73C  7C 08 03 A6 */	mtlr r0
/* 8000D7E0 0000A740  4E 80 00 20 */	blr 
.endfn GetRandom_u32

.balign 32, 0
.fn GetRandom_ulimit, global
/* 8000D800 0000A760  7C 08 02 A6 */	mflr r0
/* 8000D804 0000A764  90 01 00 04 */	stw r0, 4(r1)
/* 8000D808 0000A768  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000D80C 0000A76C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8000D810 0000A770  7C 7F 1B 78 */	mr r31, r3
/* 8000D814 0000A774  4B FF FF AD */	bl GetRandom_u32
/* 8000D818 0000A778  7C 03 FB 96 */	divwu r0, r3, r31
/* 8000D81C 0000A77C  7C 00 F9 D6 */	mullw r0, r0, r31
/* 8000D820 0000A780  7C 60 18 50 */	subf r3, r0, r3
/* 8000D824 0000A784  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8000D828 0000A788  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8000D82C 0000A78C  38 21 00 18 */	addi r1, r1, 0x18
/* 8000D830 0000A790  7C 08 03 A6 */	mtlr r0
/* 8000D834 0000A794  4E 80 00 20 */	blr 
.endfn GetRandom_ulimit

.balign 32, 0
.fn GetRandom_sf32, global
/* 8000D840 0000A7A0  7C 08 02 A6 */	mflr r0
/* 8000D844 0000A7A4  90 01 00 04 */	stw r0, 4(r1)
/* 8000D848 0000A7A8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000D84C 0000A7AC  4B FF FE F5 */	bl GetRandom_s32
/* 8000D850 0000A7B0  54 64 02 3E */	clrlwi r4, r3, 8
/* 8000D854 0000A7B4  3C 00 43 30 */	lis r0, 0x4330
/* 8000D858 0000A7B8  6C 84 80 00 */	xoris r4, r4, 0x8000
/* 8000D85C 0000A7BC  C8 42 80 98 */	lfd f2, lbl_803E8298@sda21(r2)
/* 8000D860 0000A7C0  90 81 00 14 */	stw r4, 0x14(r1)
/* 8000D864 0000A7C4  2C 03 00 00 */	cmpwi r3, 0
/* 8000D868 0000A7C8  C0 02 80 90 */	lfs f0, lbl_803E8290@sda21(r2)
/* 8000D86C 0000A7CC  90 01 00 10 */	stw r0, 0x10(r1)
/* 8000D870 0000A7D0  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 8000D874 0000A7D4  EC 21 10 28 */	fsubs f1, f1, f2
/* 8000D878 0000A7D8  EC 21 00 24 */	fdivs f1, f1, f0
/* 8000D87C 0000A7DC  40 80 00 08 */	bge .L_8000D884
/* 8000D880 0000A7E0  FC 20 08 50 */	fneg f1, f1
.L_8000D884:
/* 8000D884 0000A7E4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8000D888 0000A7E8  38 21 00 18 */	addi r1, r1, 0x18
/* 8000D88C 0000A7EC  7C 08 03 A6 */	mtlr r0
/* 8000D890 0000A7F0  4E 80 00 20 */	blr 
.endfn GetRandom_sf32

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj v0, local
	.4byte 0x00001000
.endobj v0
.obj v1, local
	.4byte 0x00005555
.endobj v1

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E8290, local
	.float 1.6777215E7
.endobj lbl_803E8290
.balign 8
.obj lbl_803E8298, local
	.8byte 0x4330000080000000
.endobj lbl_803E8298
