.include "macros.inc"

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.global atan_coeff$96
atan_coeff$96:
	.4byte 0x3F800000
	.4byte 0xBEAAAAAA
	.4byte 0x3E4CCC81
	.4byte 0xBE123E7D
	.4byte 0x3DE21F95
	.4byte 0xBDAD417C
	.4byte 0x3D41186D
.global onep_one_over_xisqr_hi$97
onep_one_over_xisqr_hi$97:
	.4byte 0x40DA826B
	.4byte 0x404F5958
	.4byte 0x40000000
	.4byte 0x3FB925AB
	.4byte 0x3F95F61A
	.4byte 0x3F851081
.global onep_one_over_xisqr_lo$98
onep_one_over_xisqr_lo$98:
	.4byte 0x36EF692F
	.4byte 0x355C1DF9
	.4byte 0x00000000
	.4byte 0x35291D45
	.4byte 0x00000000
	.4byte 0x00000000
.global atan_xi_hi$99
atan_xi_hi$99:
	.4byte 0x00000000
	.4byte 0x3EC90EAA
	.4byte 0x3F16CBE4
	.4byte 0x3F490FDA
	.4byte 0x3F7B53C5
	.4byte 0x3F96CBE2
	.4byte 0x3FAFEDD9
.global atan_xi_lo$100
atan_xi_lo$100:
	.4byte 0x00000000
	.4byte 0x37185D99
	.4byte 0x32C59189
	.4byte 0x33874A9E
	.4byte 0x353CFA83
	.4byte 0x348637BD
	.4byte 0x35541063
.global one_over_xi_hi$101
one_over_xi_hi$101:
	.4byte 0x401A8277
	.4byte 0x3FBF90C7
	.4byte 0x3F800000
	.4byte 0x3F2B0DC1
	.4byte 0x3ED413CD
	.4byte 0x3E4BAFAF
.global one_over_xi_lo$102
one_over_xi_lo$102:
	.4byte 0x3516DC59
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
