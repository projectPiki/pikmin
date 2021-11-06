.include "macros.inc"
.section .sbss, "wa"
.balign 0x8
.global errno
errno:
	.skip 0x4
