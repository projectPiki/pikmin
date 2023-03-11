.include "macros.inc"
.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E8200
lbl_803E8200:
	.asciz "DSPMIX"
.balign 4
.global lbl_803E8208
lbl_803E8208:
	.asciz "MIXING"
.balign 4
.global lbl_803E8210
lbl_803E8210:
	.asciz "SFR_DSP"
.balign 8
.global lbl_803E8218
lbl_803E8218:
	.4byte 0x43300000
	.4byte 0x80000000
.global lbl_803E8220
lbl_803E8220:
	.float 0.0
.balign 8
.global lbl_803E8228
lbl_803E8228:
	.asciz "mxic.c"
.balign 4
.global lbl_803E8230
lbl_803E8230:
	.float 4096.0
.balign 8
.global lbl_803E8238
lbl_803E8238:
	.float 16384.0
.global lbl_803E823C
lbl_803E823C:
	.float 0.0
.global lbl_803E8240
lbl_803E8240:
	.float 1.0
.global lbl_803E8244
lbl_803E8244:
	.float 0.5
.global lbl_803E8248
lbl_803E8248:
	.float 4096.0
.balign 8
.global lbl_803E8250
lbl_803E8250:
	.4byte 0x43300000
	.4byte 0x00000000
.global lbl_803E8258
lbl_803E8258:
	.float 1.1
.balign 8
.global lbl_803E8260
lbl_803E8260:
	.4byte 0x43300000
	.4byte 0x00000000
.global lbl_803E8268
lbl_803E8268:
	.float 1.0
.global lbl_803E826C
lbl_803E826C:
	.float 127.0
.balign 8
.global lbl_803E8270
lbl_803E8270:
	.4byte 0x43300000
	.4byte 0x00000000
.balign 8
.global lbl_803E8278
lbl_803E8278:
	.4byte 0x43300000
	.4byte 0x80000000
.global lbl_803E8280
lbl_803E8280:
	.float 0.0
.global lbl_803E8284
lbl_803E8284:
	.float 80.0
.global lbl_803E8288
lbl_803E8288:
	.float 600.0
.global lbl_803E828C
lbl_803E828C:
	.float 32768.0
