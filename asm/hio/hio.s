.include "macros.inc"

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global ClampRegion
ClampRegion:
	.4byte 0x1EB40F48
	.4byte 0x280F3B1F
