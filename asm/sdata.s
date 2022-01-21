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
.global lbl_803DCFE0
lbl_803DCFE0:
	.4byte 0x00000000
.global lbl_803DCFE4
lbl_803DCFE4:
	.4byte 0x00000000
.global lbl_803DCFE8
lbl_803DCFE8:
	.4byte 0x00000000
.global lbl_803DCFEC
lbl_803DCFEC:
	.4byte 0x00000000
.global lbl_803DCFF0
lbl_803DCFF0:
	.4byte 0x42C80000
.global lbl_803DCFF4
lbl_803DCFF4:
	.4byte 0x00000000
.global lbl_803DCFF8
lbl_803DCFF8:
	.4byte 0x00000000
.global lbl_803DCFFC
lbl_803DCFFC:
	.4byte 0xBF800000
.global lbl_803DD000
lbl_803DD000:
	.4byte 0x00000000
.global lbl_803DD004
lbl_803DD004:
	.4byte 0x6C696768
	.4byte 0x74000000
	.4byte 0x4C696768
	.4byte 0x74000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD014
	.4byte 0
	.4byte 0x802282C8
	.4byte 0x802282D4
.global __RTTI__5Light
__RTTI__5Light:
	.4byte 0x803DD00C
	.4byte 0x802282E0
	.4byte 0
.global lbl_803DD038
lbl_803DD038:
	.4byte 0x47000000
.global lbl_803DD03C
lbl_803DD03C:
	.4byte 0x47000000
.global lbl_803DD040
lbl_803DD040:
	.4byte 0x47000000
.global lbl_803DD044
lbl_803DD044:
	.4byte 0xC7000000
.global lbl_803DD048
lbl_803DD048:
	.4byte 0xC7000000
.global lbl_803DD04C
lbl_803DD04C:
	.4byte 0xC7000000
.global lbl_803DD050
lbl_803DD050:
	.4byte 0x00000000
.global lbl_803DD054
lbl_803DD054:
	.4byte 0x00000000
.global lbl_803DD058
lbl_803DD058:
	.float 0.0
.balign 4
.global lbl_803DD05C
lbl_803DD05C:
	.asciz "NONE"
.balign 4
.global lbl_803DD064
lbl_803DD064:
	.asciz "OPA"
.balign 4
.global lbl_803DD068
lbl_803DD068:
	.asciz "TEX"
.balign 4
.global lbl_803DD06C
lbl_803DD06C:
	.asciz "XLU"
.balign 4
.global lbl_803DD070
lbl_803DD070:
	.asciz "face"
.balign 4
.global lbl_803DD078
lbl_803DD078:
	.asciz ""
.balign 4
.global lbl_803DD07C
lbl_803DD07C:
	.asciz "matpoly"
.balign 4
.global lbl_803DD084
lbl_803DD084:
	.asciz "size"
.balign 4
.global lbl_803DD08C
lbl_803DD08C:
	.asciz "%d"
.balign 4
.global lbl_803DD090
lbl_803DD090:
	.asciz "%f"
.balign 4
.global lbl_803DD094
lbl_803DD094:
	.asciz "index"
.balign 4
.global lbl_803DD09C
lbl_803DD09C:
	.asciz "name"
.balign 4
.global lbl_803DD0A4
lbl_803DD0A4:
	.asciz "cam_far"
.balign 4
.global lbl_803DD0AC
lbl_803DD0AC:
	.asciz "<JOINT>"
.balign 4
.global lbl_803DD0B4
lbl_803DD0B4:
	.asciz "kind"
.balign 4
.global lbl_803DD0BC
lbl_803DD0BC:
	.asciz "parent"
.balign 4
.global lbl_803DD0C4
lbl_803DD0C4:
	.asciz "child"
.balign 4
.global lbl_803DD0CC
lbl_803DD0CC:
	.asciz "route"
.balign 4
.global lbl_803DD0D4
lbl_803DD0D4:
	.asciz "noname"
.balign 4
.global lbl_803DD0DC
lbl_803DD0DC:
	.asciz "%s%s"
.balign 4
.global lbl_803DD0E4
lbl_803DD0E4:
	.asciz "texattr"
.balign 4
.global lbl_803DD0EC
lbl_803DD0EC:
	.asciz "mesh"
.balign 4
.global lbl_803DD0F4
lbl_803DD0F4:
	.asciz "texImg"
.balign 4
.global lbl_803DD0FC
lbl_803DD0FC:
	.asciz ".dck"
.balign 4
.global lbl_803DD104
lbl_803DD104:
	.asciz ".dca"
.balign 4
.global lbl_803DD10C
lbl_803DD10C:
	.asciz "root"
.balign 4
	.4byte 0x8022867C
	.4byte 0
.global __RTTI__10MatobjInfo
__RTTI__10MatobjInfo:
	.4byte 0x80228670
	.4byte 0x80228688
	.asciz "ANode"
.balign 4
	.4byte 0x803DD124
	.4byte 0
	.4byte lbl_80228350
	.4byte 0x802286C0
.global __RTTI__9BaseShape
__RTTI__9BaseShape:
	.4byte 0x802286B4
	.4byte 0x802286CC
.global "__RTTI__22IDelegate2<P5Joint,Ul>"
"__RTTI__22IDelegate2<P5Joint,Ul>":
	.4byte 0x80228734
	.4byte 0
.global "__RTTI__32Delegate2<9BaseShape,P5Joint,Ul>"
"__RTTI__32Delegate2<9BaseShape,P5Joint,Ul>":
	.4byte 0x80228704
	.4byte 0x80228758
.global __RTTI__10LightFlare
__RTTI__10LightFlare:
	.4byte 0x8022877C
	.4byte 0x80228788
.global __RTTI__10LightGroup
__RTTI__10LightGroup:
	.4byte 0x802287AC
	.4byte 0x802287B8
.global __RTTI__11ObjCollInfo
__RTTI__11ObjCollInfo:
	.4byte 0x802287DC
	.4byte 0x802287E8
	.4byte 0x416E696D
	.4byte 0x44636B00
.global __RTTI__8AnimData
__RTTI__8AnimData:
	.4byte 0x8022880C
	.4byte 0x80228818
.global __RTTI__7AnimDck
__RTTI__7AnimDck:
	.4byte 0x803DD16C
	.4byte 0x8022882C
	.4byte 0x416E696D
	.4byte 0x44636100
.global __RTTI__7AnimDca
__RTTI__7AnimDca:
	.4byte 0x803DD184
	.4byte 0x80228868
.global __RTTI__11AnimContext
__RTTI__11AnimContext:
	.4byte 0x802288C4
	.4byte 0
.global __RTTI__Q25Joint7MatPoly
__RTTI__Q25Joint7MatPoly:
	.4byte 0x802288DC
	.4byte 0x802288EC
	.4byte 0x4A6F696E
	.4byte 0x74000000
.global __RTTI__5Joint
__RTTI__5Joint:
	.4byte 0x803DD1A4
	.4byte 0x80228910
	.4byte 0x4D657368
	.4byte 0x00000000
.global __RTTI__4Mesh
__RTTI__4Mesh:
	.4byte 0x803DD1B4
	.4byte 0x80228934
.global __RTTI__8FaceNode
__RTTI__8FaceNode:
	.4byte 0x80228958
	.4byte 0x80228964
.global __RTTI__8DispList
__RTTI__8DispList:
	.4byte 0x802289A4
	.4byte 0x802289B0
	.4byte 0
.global lbl_803DD1D8
lbl_803DD1D8:
	.4byte 0x73697A65
	.4byte 0x00000000
.global lbl_803DD1E0
lbl_803DD1E0:
	.4byte 0x25660000
.global lbl_803DD1E4
lbl_803DD1E4:
	.4byte 0x706F7300
.global lbl_803DD1E8
lbl_803DD1E8:
	.4byte 0x4E554C4C
	.4byte 0x00000000
.global lbl_803DD1F0
lbl_803DD1F0:
	.4byte 0x74797065
	.4byte 0x00000000
.global lbl_803DD1F8
lbl_803DD1F8:
	.4byte 0x25640000
.global lbl_803DD1FC
lbl_803DD1FC:
	.4byte 0x666C6167
	.4byte 0x73000000
.global lbl_803DD204
lbl_803DD204:
	.4byte 0x64697200
.global lbl_803DD208
lbl_803DD208:
	.4byte 0x636F6C6F
	.4byte 0x75720000
.global lbl_803DD210
lbl_803DD210:
	.4byte 0x74657874
	.4byte 0x75726500
.global lbl_803DD218
lbl_803DD218:
	.4byte 0x00000000
	.4byte 0x00000000
.global lbl_803DD220
lbl_803DD220:
	.4byte 0x00000000
.global lbl_803DD224
lbl_803DD224:
	.4byte 0x00000000
.global lbl_803DD228
lbl_803DD228:
	.4byte 0x00000000
.global lbl_803DD22C
lbl_803DD22C:
	.4byte 0x69640000
.global lbl_803DD230
lbl_803DD230:
	.4byte 0x636F6465
	.4byte 0x00000000
.global lbl_803DD238
lbl_803DD238:
	.4byte 0x74797065
	.4byte 0x00000000
.global lbl_803DD240
lbl_803DD240:
	.4byte 0x25640000
.global lbl_803DD244
lbl_803DD244:
	.4byte 0x25660000
.global lbl_803DD248
lbl_803DD248:
	.4byte 0x6765746D
	.4byte 0x696E7900
.global lbl_803DD250
lbl_803DD250:
	.4byte 0x00000000
	.4byte 0x00000000
.global lbl_803DD258
lbl_803DD258:
	.4byte 0x72700000
.global lbl_803DD25C
lbl_803DD25C:
	.4byte 0x00000000
.global lbl_803DD260
lbl_803DD260:
	.4byte 0x25640000
.global lbl_803DD264
lbl_803DD264:
	.4byte 0x696E6465
	.4byte 0x78000000
.global lbl_803DD26C
lbl_803DD26C:
	.4byte 0x706F7300
.global lbl_803DD270
lbl_803DD270:
	.4byte 0x25660000
.global lbl_803DD274
lbl_803DD274:
	.4byte 0x73746174
	.4byte 0x65000000
.global lbl_803DD27C
lbl_803DD27C:
	.4byte 0x77696474
	.4byte 0x68000000
.global lbl_803DD284
lbl_803DD284:
	.4byte 0x00000000
.global lbl_803DD288
lbl_803DD288:
	.4byte 0x40800000
.global lbl_803DD28C
lbl_803DD28C:
	.4byte 0x00000000
.global lbl_803DD290
lbl_803DD290:
	.4byte 0x3F000000
.global lbl_803DD294
lbl_803DD294:
	.4byte 0x00000000
.global lbl_803DD298
lbl_803DD298:
	.4byte 0x69640000
.global lbl_803DD29C
lbl_803DD29C:
	.4byte 0x6E616D65
	.4byte 0x00000000
.global lbl_803DD2A4
lbl_803DD2A4:
	.4byte 0x636F6C6F
	.4byte 0x75720000
.global lbl_803DD2AC
lbl_803DD2AC:
	.4byte 0x706F696E
	.4byte 0x74000000
.global lbl_803DD2B4
lbl_803DD2B4:
	.4byte 0x6C696E6B
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD2BC
	.4byte 0
	.4byte 0x80228AF0
	.4byte 0x80228AFC
.global __RTTI__8EditNode
__RTTI__8EditNode:
	.4byte 0x80228B08
	.4byte 0x80228B14
.global __RTTI__10RouteGroup
__RTTI__10RouteGroup:
	.4byte 0x80228AE4
	.4byte 0x80228B28
.global __RTTI__9RouteLink
__RTTI__9RouteLink:
	.4byte 0x80228B74
	.4byte 0x80228B80
.global __RTTI__10RoutePoint
__RTTI__10RoutePoint:
	.4byte 0x80228BA4
	.4byte 0x80228BB0
	.4byte 0
.global lbl_803DD2F8
lbl_803DD2F8:
	.4byte 0x00000000
.global lbl_803DD2FC
lbl_803DD2FC:
	.4byte 0x00000000
.global lbl_803DD300
lbl_803DD300:
	.4byte 0x00000000
.global lbl_803DD304
lbl_803DD304:
	.4byte 0x00000000
.global lbl_803DD308
lbl_803DD308:
	.4byte 0x00000000
.global gs_fTolerance
gs_fTolerance:
	.4byte 0x3727C5AC
