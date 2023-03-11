.include "macros.inc"
.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj JAC_DAC_RATE, global
	.float 32028.5
.endobj JAC_DAC_RATE
.obj JAC_SUBFRAMES, global
	.4byte 7
.endobj JAC_SUBFRAMES
.obj JAC_FRAMESAMPLES, global
	.4byte 0x00000230
.endobj JAC_FRAMESAMPLES
.obj DAC_SIZE, global
	.4byte 0x00000460
.endobj DAC_SIZE

.section .sbss, "wa"
.balign 8
.obj JAC_AI_SETTING, global
	.skip 4
.endobj JAC_AI_SETTING
