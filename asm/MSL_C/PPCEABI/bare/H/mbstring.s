.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn wcstombs, global
/* 802160E0 00213040  28 05 00 00 */	cmplwi r5, 0
/* 802160E4 00213044  7C A9 03 A6 */	mtctr r5
/* 802160E8 00213048  38 C0 00 00 */	li r6, 0
/* 802160EC 0021304C  40 81 00 28 */	ble .L_80216114
.L_802160F0:
/* 802160F0 00213050  A0 04 00 00 */	lhz r0, 0(r4)
/* 802160F4 00213054  38 84 00 02 */	addi r4, r4, 2
/* 802160F8 00213058  7C 05 07 74 */	extsb r5, r0
/* 802160FC 0021305C  7C A0 07 75 */	extsb. r0, r5
/* 80216100 00213060  98 A3 00 00 */	stb r5, 0(r3)
/* 80216104 00213064  38 63 00 01 */	addi r3, r3, 1
/* 80216108 00213068  41 82 00 0C */	beq .L_80216114
/* 8021610C 0021306C  38 C6 00 01 */	addi r6, r6, 1
/* 80216110 00213070  42 00 FF E0 */	bdnz .L_802160F0
.L_80216114:
/* 80216114 00213074  7C C3 33 78 */	mr r3, r6
/* 80216118 00213078  4E 80 00 20 */	blr 
.endfn wcstombs

.fn mbtowc, global
/* 8021611C 0021307C  28 04 00 00 */	cmplwi r4, 0
/* 80216120 00213080  40 82 00 0C */	bne .L_8021612C
/* 80216124 00213084  38 60 00 00 */	li r3, 0
/* 80216128 00213088  4E 80 00 20 */	blr 
.L_8021612C:
/* 8021612C 0021308C  28 05 00 00 */	cmplwi r5, 0
/* 80216130 00213090  40 82 00 0C */	bne .L_8021613C
/* 80216134 00213094  38 60 FF FF */	li r3, -1
/* 80216138 00213098  4E 80 00 20 */	blr 
.L_8021613C:
/* 8021613C 0021309C  28 03 00 00 */	cmplwi r3, 0
/* 80216140 002130A0  41 82 00 10 */	beq .L_80216150
/* 80216144 002130A4  88 04 00 00 */	lbz r0, 0(r4)
/* 80216148 002130A8  7C 00 07 74 */	extsb r0, r0
/* 8021614C 002130AC  B0 03 00 00 */	sth r0, 0(r3)
.L_80216150:
/* 80216150 002130B0  88 04 00 00 */	lbz r0, 0(r4)
/* 80216154 002130B4  7C 00 07 75 */	extsb. r0, r0
/* 80216158 002130B8  40 82 00 0C */	bne .L_80216164
/* 8021615C 002130BC  38 60 00 00 */	li r3, 0
/* 80216160 002130C0  4E 80 00 20 */	blr 
.L_80216164:
/* 80216164 002130C4  38 60 00 01 */	li r3, 1
/* 80216168 002130C8  4E 80 00 20 */	blr 
.endfn mbtowc
