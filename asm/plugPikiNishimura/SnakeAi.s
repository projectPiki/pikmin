.include "macros.inc"

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.global lbl_802226F0
lbl_802226F0:
	.4byte 0x42000000
	.4byte 0x42000000
	.4byte 0x42000000
	.4byte 0x41E00000
	.4byte 0x41E00000
	.4byte 0x00000000

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x414e6f64
	.4byte 0x65000000
	.4byte 0x803e4c78
	.4byte 0
	.4byte lbl_802CF6AC
	.4byte 0x802cf920
	.4byte 0x802cf92c
	.4byte 0
	.4byte 0x802cf93c
	.4byte 0x802cf948
.global __RTTI__9SnakeProp
__RTTI__9SnakeProp:
	.4byte 0x802cf914
	.4byte 0x802cf954
