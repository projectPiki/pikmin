.include "macros.inc"

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global ResettingChan
ResettingChan:
	.4byte 0x00000020
.global XPatchBits
XPatchBits:
	.4byte 0xF0000000
