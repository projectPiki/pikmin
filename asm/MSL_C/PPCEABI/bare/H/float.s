.include "macros.inc"
.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 0x8
.global __float_nan
__float_nan:
	.4byte 0x7FFFFFFF
.global __float_huge
__float_huge:
	.4byte 0x7F800000
.global __double_min
__double_min:
	.4byte 0x00100000
	.4byte 0x00000000
.global __double_max
__double_max:
	.4byte 0x7FEFFFFF
	.4byte 0xFFFFFFFF
.global __double_huge
__double_huge:
	.4byte 0x7FF00000
	.4byte 0x00000000
.global __double_nan
__double_nan:
	.4byte 0x7FFFFFFF
	.4byte 0xFFFFFFFF
.global __extended_min
__extended_min:
	.4byte 0x00100000
	.4byte 0x00000000
.global __extended_max
__extended_max:
	.4byte 0x7FEFFFFF
	.4byte 0xFFFFFFFF
