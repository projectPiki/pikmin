.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global srand
srand:
/* 80218068 00214FC8  90 6D 2A D8 */	stw r3, next@sda21(r13)
/* 8021806C 00214FCC  4E 80 00 20 */	blr 

.global rand
rand:
/* 80218070 00214FD0  3C 60 41 C6 */	lis r3, 0x41C64E6D@ha
/* 80218074 00214FD4  80 8D 2A D8 */	lwz r4, next@sda21(r13)
/* 80218078 00214FD8  38 03 4E 6D */	addi r0, r3, 0x41C64E6D@l
/* 8021807C 00214FDC  7C 64 01 D6 */	mullw r3, r4, r0
/* 80218080 00214FE0  38 03 30 39 */	addi r0, r3, 0x3039
/* 80218084 00214FE4  90 0D 2A D8 */	stw r0, next@sda21(r13)
/* 80218088 00214FE8  80 0D 2A D8 */	lwz r0, next@sda21(r13)
/* 8021808C 00214FEC  54 03 84 7E */	rlwinm r3, r0, 0x10, 0x11, 0x1f
/* 80218090 00214FF0  4E 80 00 20 */	blr 

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 0x8
.global next
next:
	.4byte 0x00000001
	.4byte 0x00000000
