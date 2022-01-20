.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global renderall__7GameAppFv
renderall__7GameAppFv:
/* 8004C908 00049868  7C 08 02 A6 */	mflr r0
/* 8004C90C 0004986C  90 01 00 04 */	stw r0, 4(r1)
/* 8004C910 00049870  94 21 FF F8 */	stwu r1, -8(r1)
/* 8004C914 00049874  81 83 00 00 */	lwz r12, 0(r3)
/* 8004C918 00049878  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8004C91C 0004987C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8004C920 00049880  80 84 02 4C */	lwz r4, 0x24c(r4)
/* 8004C924 00049884  7D 88 03 A6 */	mtlr r12
/* 8004C928 00049888  4E 80 00 21 */	blrl 
/* 8004C92C 0004988C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8004C930 00049890  38 21 00 08 */	addi r1, r1, 8
/* 8004C934 00049894  7C 08 03 A6 */	mtlr r0
/* 8004C938 00049898  4E 80 00 20 */	blr 
