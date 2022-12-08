.include "macros.inc"
.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.balign 4
.global lbl_80221FE0
lbl_80221FE0:
	.asciz "MONO-MIX"
.balign 4
.global lbl_80221FEC
lbl_80221FEC:
	.asciz "MONO(W)-MIX"
.balign 4
.global lbl_80221FF8
lbl_80221FF8:
	.asciz "UPDATE-DAC"
.balign 8
.global lbl_80222008
lbl_80222008:
	.asciz "DSP-MAIN"
.balign 4
.global lbl_80222014
lbl_80222014:
	.asciz "SFR-UPDATE"
.balign 4
.global lbl_80222020
lbl_80222020:
	.asciz "DSPInit(): MXIC Boot failed."
.balign 4
.global lbl_80222040
lbl_80222040:
.asciz "DSP Err:not received mail (to DSP) is remained \n"
.balign 4
.global lbl_80222074
lbl_80222074:
	.asciz "DSP Err:not received mail (from DSP) is remained \n"
.balign 4
.global lbl_802220A8
lbl_802220A8:
	.asciz "Error: DSP now in framework\n"
.balign 4
.global lbl_802220C8
lbl_802220C8:
	.asciz "dsp_cardunlock.c"
.balign 4
.global lbl_802220DC
lbl_802220DC:
	.asciz "Failed assertion 0 <= chan && chan < 2"
