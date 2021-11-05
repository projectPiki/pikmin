.include "macros.inc"

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global cmdCalibrate
cmdCalibrate:
	.4byte 0x42000000
.global lbl_803E7774
lbl_803E7774:
	.4byte 0x5061642E
	.4byte 0x63000000
	.4byte 0x00000000
.global Chan
Chan:
	.4byte 0xFFFFFFFF
	.4byte 0x00000000
.global gx
gx:
	.4byte 0x803D3650
	.4byte 0x00000000
.global tbl1$208
tbl1$208:
	.4byte 0x00040102
.global tbl2$209
tbl2$209:
	.4byte 0x00080102
.global tbl3$210
tbl3$210:
	.4byte 0x000C0102
	.4byte 0x00000000
.global GXTexMode0Ids
GXTexMode0Ids:
	.4byte 0x80818283
	.4byte 0xA0A1A2A3
.global GXTexMode1Ids
GXTexMode1Ids:
	.4byte 0x84858687
	.4byte 0xA4A5A6A7
