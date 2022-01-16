.include "macros.inc"

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.balign 8
"@stringBase0":
	.4byte 0x2E000043
	.byte 0

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.global __lconv
__lconv:
	.4byte "@stringBase0"
	.4byte "@stringBase0"+2
	.4byte "@stringBase0"+2
	.4byte "@stringBase0"+2
	.4byte "@stringBase0"+2
	.4byte "@stringBase0"+2
	.4byte "@stringBase0"+2
	.4byte "@stringBase0"+2
	.4byte "@stringBase0"+2
	.4byte "@stringBase0"+2
	.4byte 0x7F7F7F7F
	.4byte 0x7F7F7F7F
