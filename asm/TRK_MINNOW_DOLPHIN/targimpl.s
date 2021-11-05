.include "macros.inc"

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.global gTRKMemMap
gTRKMemMap:
	.4byte 0x00000000
	.4byte 0xFFFFFFFF
	.4byte 0x00000001
	.4byte 0x00000001
.global lbl_80222D80
lbl_80222D80:
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x60000000
.global lbl_80222D94
lbl_80222D94:
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x60000000
.global lbl_80222DA8
lbl_80222DA8:
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x60000000
	.4byte 0x00000000
