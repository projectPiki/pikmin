.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global fabsf__Ff
fabsf__Ff:
/* 8021B728 00218688  FC 20 0A 10 */	fabs f1, f1
/* 8021B72C 0021868C  4E 80 00 20 */	blr 
