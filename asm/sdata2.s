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
.global "@32"
"@32":
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
.global "@346"
"@346":
	.4byte 0x43300000
	.4byte 0x00000000
.global lbl_803E8258
lbl_803E8258:
	.float 1.1
.balign 8
.global "@264"
"@264":
	.4byte 0x43300000
	.4byte 0x00000000
.global lbl_803E8268
lbl_803E8268:
	.float 1.0
.global lbl_803E826C
lbl_803E826C:
	.float 127.0
.balign 8
.global "@125"
"@125":
	.4byte 0x43300000
	.4byte 0x00000000
.balign 8
.global "@127"
"@127":
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
.global lbl_803E8290
lbl_803E8290:
	.float 1.6777215E7
.balign 8
.global "@58"
"@58":
	.4byte 0x43300000
	.4byte 0x80000000
.global lbl_803E82A0
lbl_803E82A0:
	.float 0.0
.balign 8
.global "@110"
"@110":
	.double 0.5
.balign 8
.global "@111"
"@111":
	.double 3.0
.global lbl_803E82B8
lbl_803E82B8: #half pi
	.float 1.5707964
.global lbl_803E82BC
lbl_803E82BC:
	.float 0.00390625
.balign 8
.global "@124"
"@124":
	.4byte 0x43300000
	.4byte 0x00000000
.global lbl_803E82C8
lbl_803E82C8:
	.float 256.0
.balign 8
.global lbl_803E82D0
lbl_803E82D0:
	.asciz "/"
.balign 8
.global lbl_803E82D8
lbl_803E82D8:
	.float 100.0
.global lbl_803E82DC
lbl_803E82DC:
	.float 120.0
.balign 8
.global "@119"
"@119":
	.4byte 0x43300000
	.4byte 0x80000000
.balign 8
.global "@121"
"@121":
	.4byte 0x43300000
	.4byte 0x00000000
.global lbl_803E82F0
lbl_803E82F0:
	.float 32768.0
.global lbl_803E82F4
lbl_803E82F4:
	.float 0.0
.global lbl_803E82F8
lbl_803E82F8:
	.float 1.0
.global lbl_803E82FC
lbl_803E82FC:
	.float 32767.0
.global lbl_803E8300
lbl_803E8300:
	.float 128.0
.global lbl_803E8304
lbl_803E8304:
	.float 60.0
.global lbl_803E8308
lbl_803E8308:
	.float 80.0
.global lbl_803E830C
lbl_803E830C:
	.float 327.67
.global lbl_803E8310
lbl_803E8310:
	.4byte 0x00000001
	.2byte 0x0102
	.byte 0x02
.balign 4
.global lbl_803E8318
lbl_803E8318:
	.4byte 0x00010200
	.2byte 0x0200
	.byte 0x02
