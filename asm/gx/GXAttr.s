.include "macros.inc"

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global AnalogMode
AnalogMode:
	.4byte 0x00000300
.global Spec
Spec:
	.4byte 0x00000005
.global MakeStatus
MakeStatus:
	.4byte 0x80205AF0
.global cmdReadOrigin
cmdReadOrigin:
	.4byte 0x41000000
