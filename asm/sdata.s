.include "macros.inc"
.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global JAC_DAC_RATE
JAC_DAC_RATE:
	.float 32028.5
.global JAC_SUBFRAMES
JAC_SUBFRAMES:
	.4byte 0x00000007
.global JAC_FRAMESAMPLES
JAC_FRAMESAMPLES:
	.4byte 0x00000230
.global DAC_SIZE
DAC_SIZE:
	.4byte 0x00000460
.global DSP_MIXERLEVEL
DSP_MIXERLEVEL:
	.2byte 0x4000
	.2byte 0x0000
	.4byte 0x00000000
.global MAX_MIXERLEVEL
MAX_MIXERLEVEL:
	.2byte 0x2EE0
	.2byte 0x0000
.global JAC_SYSTEM_OUTPUT_MODE
JAC_SYSTEM_OUTPUT_MODE:
	.4byte 0x00000001
.global COMP_BLOCKSAMPLES$81
COMP_BLOCKSAMPLES$81:
	.4byte 0x10100101
	.4byte 0x01101001
.global COMP_BLOCKBYTES$82
COMP_BLOCKBYTES$82:
	.4byte 0x09050810
	.4byte 0x01010101
.global v0
v0:
	.4byte 0x00001000
.global v1
v1:
	.4byte 0x00005555
.global ARCALL
ARCALL:
	.4byte LoadAram_Default__FPcUlUlPUlP7jaheap_
.global first
first:
	.4byte 0x00000001
.global osc_table
osc_table:
	.4byte 0x01020804
	.4byte 0x10000000
.global OSC_REL
OSC_REL:
	.4byte 0x0001000A
	.4byte 0x0000000F
.global game_bgm_vol
game_bgm_vol:
	.byte 0x8
.global game_se_vol
game_se_vol:
	.byte 0x8
	.byte 0x0
	.byte 0x0
.global current_process
current_process:
	.4byte 0xFFFFFFFF
.global buffer
buffer:
	.4byte 0x00000000
	.4byte 0x00000000
.global buffer_mus
buffer_mus:
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
.global fadeouttime
fadeouttime:
	.4byte 0x0000001E
.global game_bgm_volume
game_bgm_volume:
	.float 1.0
.global bgm0_set
bgm0_set:
	.4byte 0xFFFFFFFF
	.4byte 0xFFFFFFFF
.global bgm1_set
bgm1_set:
	.4byte 0x103C17D8
	.4byte 0x800319C3
.global bgm2_set
bgm2_set:
	.4byte 0x003300F3
	.4byte 0x003C00FC
.global bgm3_set
bgm3_set:
	.4byte 0xC00FF78D
	.4byte 0xC07CFE2C
.global bgm4_set
bgm4_set:
	.4byte 0x00470297
	.4byte 0x002D023D
.global bgm5_set
bgm5_set:
	.4byte 0x057D05FB
	.4byte 0x0A780AFA
.global bgm0_volset
bgm0_volset:
	.float 0.5
	.float 0.15
.global bgm1_volset
bgm1_volset:
	.float 0.5
	.float 0.15
.global bgm2_volset
bgm2_volset:
	.float 0.5
	.float 0.15
.global bgm3_volset
bgm3_volset:
	.float 0.5
	.float 0.15
.global bgm4_volset
bgm4_volset:
	.float 0.5
	.float 0.15
.global bgm5_volset
bgm5_volset:
	.float 0.55
	.float 0.15
.global cresult_volset
cresult_volset:
	.float 0.35
	.float 0.15
.global last_bgm_level
last_bgm_level:
	.byte 0xFF
	.balign 8
.global current_scene
current_scene:
	.4byte 0xFFFFFFFF
.global current_stage
current_stage:
	.4byte 0xFFFFFFFF
.global current_prepare
current_prepare:
	.4byte 0xFFFFFFFF
.global stream_level
stream_level:
	.byte 0x1F
	.byte 0x40
.global stream_se_level
stream_se_level:
	.byte 0x1F
	.byte 0x40
.global current_demo_no
current_demo_no:
	.4byte 0xFFFFFFFF
.global demo_seq_active
demo_seq_active:
	.4byte 0xFFFFFFFF
.global demo_mml_active
demo_mml_active:
	.4byte 0xFFFFFFFF
.global demo1
demo1:
	.4byte 0x0004FFFA
	.4byte 0x07D0FFFF
.global demo2
demo2:
	.4byte 0x07D0FFFF
.global demo3
demo3:
	.4byte 0x017C0001
	.4byte 0x01BCFFFF
.global demo12
demo12:
	.4byte 0x00040000
	.4byte 0x0258FFFF
.global demo27
demo27:
	.4byte 0x00040000
	.4byte 0x0258FFFF
.global demo102
demo102:
	.4byte 0x00A00001
	.4byte 0x0258FFFF
.global first_1
first_1:
	.4byte 0x00000001
	.4byte 0x00000000
.global copy
copy:
	.4byte copyinfo
	.4byte 0x00000000
.global buf
buf:
	.4byte interleavebuf
	.4byte 0x00000000
.global gop_subframe
gop_subframe:
	.4byte 0xFFFFFFFF
.global playback_first_wait
playback_first_wait:
	.4byte 0x00000001
.global hvqm_first
hvqm_first:
	.4byte 0x00000001
	.4byte 0x00000000
.global lbl_803DCE70
lbl_803DCE70:
	.asciz "<Node>"
.balign 4
lbl_803DCE78:
	.asciz "BaseApp"
.balign 4
lbl_803DCE80:
	.asciz "ANode"
.balign 4
	.4byte lbl_803DCE80
	.4byte 0
	.4byte 0x802272E8
	.4byte 0x802272F4
.balign 4
lbl_803DCE98:
	.asciz "Node"
.balign 4
	.4byte lbl_803DCE98
	.4byte 0x80227300
.global __RTTI__7BaseApp
__RTTI__7BaseApp:
	.4byte lbl_803DCE78
	.4byte 0x80227314
.balign 4
lbl_803DCEB0:
	.asciz "Stream"
.balign 4
	.4byte lbl_803DCEB0
	.4byte 0
.balign 4
lbl_803DCEC0:
	.asciz "Stream"
.balign 4
	.4byte lbl_803DCEC0
	.4byte 0
	.4byte 0x80227430
	.4byte 0x80227444
.global __RTTI__19BufferedInputStream
__RTTI__19BufferedInputStream:
	.4byte 0x8022741C
	.4byte 0x80227450
.global lbl_803DCEE0
lbl_803DCEE0:
	.float 1.0
.global lbl_803DCEE4
lbl_803DCEE4:
	.float 1.0
.global lbl_803DCEE8
lbl_803DCEE8:
	.float 0.0
.global lbl_803DCEEC
lbl_803DCEEC:
	.float 0.0
.global lbl_803DCEF0
lbl_803DCEF0:
	.float 0.0
.global lbl_803DCEF4
lbl_803DCEF4:
	.float 0.0
.global lbl_803DCEF8
lbl_803DCEF8:
	.float 0.0
.global lbl_803DCEFC
lbl_803DCEFC:
	.float 0.0
.global lbl_803DCF00
lbl_803DCF00:
	.float 0.0
.global lbl_803DCF04
lbl_803DCF04:
	.float 0.0
.global lbl_803DCF08
lbl_803DCF08:
	.float 0.0
.global lbl_803DCF0C
lbl_803DCF0C:
	.float 0.0
.global lbl_803DCF10
lbl_803DCF10:
	.float 0.0
.balign 4
.global lbl_803DCF14
lbl_803DCF14:
	.asciz "Normal"
.balign 4
.global lbl_803DCF1C
lbl_803DCF1C:
	.asciz "Environ"
.balign 4
.global lbl_803DCF24
lbl_803DCF24:
	.asciz ""
.balign 4
.global lbl_803DCF28
lbl_803DCF28:
	.asciz "INVALID"
.balign 4
.global lbl_803DCF30
lbl_803DCF30:
	.asciz "%s:%d"
.balign 4
.global lbl_803DCF38
lbl_803DCF38:
	.float 1.0
.global lbl_803DCF3C
lbl_803DCF3C:
	.float 1.0
.global lbl_803DCF40
lbl_803DCF40:
	.float 1.0
.global lbl_803DCF44
lbl_803DCF44:
	.float 0.0
.global lbl_803DCF48
lbl_803DCF48:
	.float 0.0
.global lbl_803DCF4C
lbl_803DCF4C:
	.float 0.0
.global lbl_803DCF50
lbl_803DCF50:
	.float 0.0
.global lbl_803DCF54
lbl_803DCF54:
	.float 1.0
.global lbl_803DCF58
lbl_803DCF58:
	.float 1.0
.global lbl_803DCF5C
lbl_803DCF5C:
	.float 1.0
.global lbl_803DCF60
lbl_803DCF60:
	.float 0.0
.global lbl_803DCF64
lbl_803DCF64:
	.float 0.0
.global lbl_803DCF68
lbl_803DCF68:
	.float 0.0
.global lbl_803DCF6C
lbl_803DCF6C:
	.float 0.0
.global __RTTI__9GfxObject
__RTTI__9GfxObject:
	.4byte lbl_802280B4
	.4byte 0
.balign 4
lbl_803DCF78:
	.asciz "Texture"
.balign 4
.global __RTTI__7Texture
__RTTI__7Texture:
	.4byte lbl_803DCF78
	.4byte lbl_802280C0
.global __RTTI__12CacheTexture
__RTTI__12CacheTexture:
	.4byte lbl_802280A4
	.4byte lbl_802280CC
	.4byte 0x54657841
	.4byte 0x74747200
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DCF98
	.4byte 0
	.4byte 0x802280F4
	.4byte 0x80228100
.global __RTTI__7TexAttr
__RTTI__7TexAttr:
	.4byte 0x803DCF90
	.4byte 0x8022810C
	.4byte 0x54657849
	.4byte 0x6D670000
.global __RTTI__6TexImg
__RTTI__6TexImg:
	.4byte 0x803DCFB8
	.4byte 0x80228130
.global __RTTI__8Graphics
__RTTI__8Graphics:
	.4byte 0x80227550
	.4byte 0
.global __RTTI__15MaterialHandler
__RTTI__15MaterialHandler:
	.4byte 0x80228248
	.4byte 0
.global __RTTI__8Material
__RTTI__8Material:
	.4byte 0x80228268
	.4byte 0x80228274
