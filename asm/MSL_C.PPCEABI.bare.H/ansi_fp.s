.include "macros.inc"

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.global bit_values
bit_values:
	.4byte 0x40240000
	.4byte 0x00000000
	.4byte 0x40590000
	.4byte 0x00000000
	.4byte 0x40C38800
	.4byte 0x00000000
	.4byte 0x4197D784
	.4byte 0x00000000
	.4byte 0x4341C379
	.4byte 0x37E08000
	.4byte 0x4693B8B5
	.4byte 0xB5056E17
	.4byte 0x4D384F03
	.4byte 0xE93FF9F5
	.4byte 0x5A827748
	.4byte 0xF9301D32
	.4byte 0x75154FDD
	.4byte 0x7F73BF3C
.global digit_values
digit_values:
	.4byte 0x40240000
	.4byte 0x00000000
	.4byte 0x40590000
	.4byte 0x00000000
	.4byte 0x408F4000
	.4byte 0x00000000
	.4byte 0x40C38800
	.4byte 0x00000000
	.4byte 0x40F86A00
	.4byte 0x00000000
	.4byte 0x412E8480
	.4byte 0x00000000
	.4byte 0x416312D0
	.4byte 0x00000000
	.4byte 0x4197D784
	.4byte 0x00000000

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global GXTexImage1Ids
GXTexImage1Ids:
	.4byte 0x8C8D8E8F
	.4byte 0xACADAEAF
