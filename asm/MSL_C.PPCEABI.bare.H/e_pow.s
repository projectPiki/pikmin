.include "macros.inc"

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.global bp
bp:
	.4byte 0x3FF00000
	.4byte 0x00000000
	.4byte 0x3FF80000
	.4byte 0x00000000
.global dp_h
dp_h:
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x3FE2B803
	.4byte 0x40000000
.global dp_l
dp_l:
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x3E4CFDEB
	.4byte 0x43CFD006
