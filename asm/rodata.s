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
.balign 8
.global lbl_80222108
lbl_80222108:
	.4byte 0x20202020
.global lbl_8022210C
lbl_8022210C:
	.4byte 0x20202020
.global lbl_80222110
lbl_80222110:
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
.global lbl_80222118
lbl_80222118:
	.asciz "/Seqs/pikiseq.hed"
.balign 4
.global lbl_8022212C
lbl_8022212C:
	.asciz "Banks/pikibank.bx"
.balign 4
.global lbl_80222140
lbl_80222140:
	.asciz "/Seqs/pikiseq.arc"
.balign 4
.global lbl_80222154
lbl_80222154:
	.asciz "/Banks/demose_0.aw"
.balign 4
.global lbl_80222168
lbl_80222168:
	.asciz "/Banks/demose_1.aw"
.balign 4
.global lbl_8022217C
lbl_8022217C:
	.asciz "/Banks/demo_0.aw"
.balign 4
.global lbl_80222190
lbl_80222190:
	.asciz "/Banks/demo_1.aw"
.balign 4
.global lbl_802221A4
lbl_802221A4:
	.asciz "/Banks/demo_2.aw"
.balign 4
.global lbl_802221B8
lbl_802221B8:
	.asciz "/Banks/demo_3.aw"
.balign 4
.global lbl_802221CC
lbl_802221CC:
	.asciz "/Banks/demo_4.aw"
.balign 4
.global lbl_802221E0
lbl_802221E0:
	.asciz "/Banks/demo_5.aw"
.balign 4
.global lbl_802221F4
lbl_802221F4:
	.asciz "/Banks/demo_6.aw"
.balign 4
.global lbl_80222208
lbl_80222208:
	.asciz "/Banks/demo_7.aw"
.balign 4
.global lbl_8022221C
lbl_8022221C:
	.asciz "/Banks/demo_8.aw"
.balign 4
.global lbl_80222230
lbl_80222230:
	.asciz "/d_end1.stx"
.balign 4
.global lbl_8022223C
lbl_8022223C:
	.asciz "/d_end3.stx"
.balign 4
.global lbl_80222248
lbl_80222248:
	.asciz "/fanf5.stx"
.balign 4
.global lbl_80222254
lbl_80222254:
	.asciz "/badend0.stx"
.balign 4
.global lbl_80222264
lbl_80222264:
	.asciz "/badend1.stx"
.balign 8
.global lbl_80222278
lbl_80222278:
	.4byte 0x00
	.4byte 0x01
	.4byte 0x0B
	.4byte 0x0D
	.4byte 0x10
.global lbl_8022228C
lbl_8022228C:
	.4byte 0
	.4byte 1
	.4byte 0xFFFFFFFF
	.4byte 2
	.4byte 0xFFFFFFFF
.global mcbtypetrans$1481
mcbtypetrans$1481:
	.4byte 1
	.4byte 2
	.4byte 0
	.4byte 2
	.4byte 0
	.4byte 1
.global lbl_802222B8
lbl_802222B8:
	.4byte 0
	.4byte 1
	.4byte 2
	.4byte 0
	.4byte 1
	.4byte 5
	.4byte 0
	.4byte 4
	.4byte 2
	.4byte 0
	.4byte 4
	.4byte 5
	.4byte 3
	.4byte 1
	.4byte 2
	.4byte 3
	.4byte 1
	.4byte 5
	.4byte 3
	.4byte 4
	.4byte 2
	.4byte 3
	.4byte 4
	.4byte 5
.global lbl_80222318
lbl_80222318:
	.4byte 0
	.4byte 1
	.4byte 1
	.4byte 5
	.4byte 5
	.4byte 4
	.4byte 4
	.4byte 0
	.4byte 2
	.4byte 3
	.4byte 3
	.4byte 7
	.4byte 7
	.4byte 6
	.4byte 6
	.4byte 2
	.4byte 0
	.4byte 2
	.4byte 1
	.4byte 3
	.4byte 5
	.4byte 7
	.4byte 4
	.4byte 6
.global lbl_80222378
lbl_80222378:
	.4byte 1
	.4byte 2
	.4byte 0
.global lbl_80222384
lbl_80222384:
	.4byte 1
	.4byte 2
	.4byte 0
.global lbl_80222390
lbl_80222390:
	.4byte 1
	.4byte 2
	.4byte 0
.balign 8
.global lbl_802223A0
lbl_802223A0:
	.4byte 0x11
	.4byte 0x12
	.4byte 0x13
	.4byte 0x19
	.4byte 0x1A
.global lbl_802223B4
lbl_802223B4:
	.4byte lbl_803DEBE8
	.4byte lbl_803DEBF0
	.4byte lbl_803DEBF8
	.4byte lbl_803DEC00
	.4byte lbl_803DEC08
	.4byte lbl_803DEC10
.balign 8
.global lbl_802223D0
lbl_802223D0:
	.4byte lbl_803DECD8
	.4byte lbl_803DECDC
	.4byte lbl_803DECE0
.balign 8
.global lbl_802223E0
lbl_802223E0:
	.4byte lbl_803DEE20
	.4byte lbl_803DEE28
	.4byte lbl_803DEE30
.global lbl_802223EC
lbl_802223EC:
	.4byte lbl_803DEE20
	.4byte lbl_803DEE28
	.4byte lbl_803DEE30
.global lbl_802223F8
lbl_802223F8:
	.float 3.3
	.float 7.0
	.float 13.0
	.float 18.0
.global lbl_80222408
lbl_80222408:
	.4byte 0xD6
	.4byte 0xD5
	.4byte 0xD4
	.4byte 0xD3
.global lbl_80222418
lbl_80222418:
	.4byte lbl_803DFB00
	.4byte lbl_803DFB08
	.4byte lbl_803DFB10
	.4byte lbl_803DFB18
	.4byte lbl_803DFB20
	.4byte lbl_803DFB28
	.4byte lbl_803DFB30
	.4byte lbl_803DFB38
	.4byte lbl_803DFB40
.balign 8
.global lbl_80222440
lbl_80222440:
	.4byte 0
	.float 0.2
	.4byte 1
	.float 0.1
	.4byte 2
	.float 0.3
	.4byte 3
	.float 0.3
.global lbl_80222460
lbl_80222460:
	.4byte 0
	.float 0.1
	.4byte 1
	.float 0.5
	.4byte 2
	.float 0.3
	.4byte 3
	.float 0.1
.global lbl_80222480
lbl_80222480:
	.4byte 0x27
	.float 0.35
	.4byte 0x28
	.float 0.35
	.4byte 0x41
	.float 0.2
	.4byte 0x29
	.float 0.1
