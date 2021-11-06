.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global fabs__Fd
fabs__Fd:
/* 8021A710 00217670  FC 20 0A 10 */	fabs f1, f1
/* 8021A714 00217674  4E 80 00 20 */	blr 
