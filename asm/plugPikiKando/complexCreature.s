.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800C8C60 000C5BC0  38 60 00 01 */	li r3, 1
/* 800C8C64 000C5BC4  38 83 00 00 */	addi r4, r3, 0
/* 800C8C68 000C5BC8  2C 05 00 16 */	cmpwi r5, 0x16
/* 800C8C6C 000C5BCC  38 03 00 00 */	addi r0, r3, 0
/* 800C8C70 000C5BD0  41 82 00 10 */	beq lbl_800C8C80

.section .text, "ax"  # 0x80005560 - 0x80221F60
lbl_801DED90:
/* 801DED90 001DBCF0  EC 01 F0 28 */	fsubs f0, f1, f30
lbl_801DED94:
/* 801DED94 001DBCF4  FC 00 00 1E */	fctiwz f0, f0
/* 801DED98 001DBCF8  80 73 00 24 */	lwz r3, 0x24(r19)
/* 801DED9C 001DBCFC  38 63 00 18 */	addi r3, r3, 0x18
/* 801DEDA0 001DBD00  D8 01 01 50 */	stfd f0, 0x150(r1)
