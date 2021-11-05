.include "macros.inc"

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global fragmentID
fragmentID:
	.4byte 0xFFFFFFFE
	.4byte 0x00000000
