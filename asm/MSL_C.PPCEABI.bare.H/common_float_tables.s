.include "macros.inc"

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.global __sincos_on_quadrant
__sincos_on_quadrant:
	.4byte 0x00000000
	.4byte 0x3F800000
	.4byte 0x3F800000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0xBF800000
	.4byte 0xBF800000
	.4byte 0x00000000
.global __sincos_poly
__sincos_poly:
	.4byte 0x366CCFAA
	.4byte 0x34A5E129
	.4byte 0xB9AAE275
	.4byte 0xB8196543
	.4byte 0x3C81E0ED
	.4byte 0x3B2335DD
	.4byte 0xBE9DE9E6
	.4byte 0xBDA55DE7
	.4byte 0x3F800000
	.4byte 0x3F490FDB
