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
	.4byte 0x00000000
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
lbl_803DCF14:
	.asciz "Normal"
.balign 4
lbl_803DCF1C:
	.asciz "Environ"
.balign 4
.global lbl_803DCF24
lbl_803DCF24:
	.4byte 0x00000000
.balign 4
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
	.4byte 0x00000000
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
	.asciz "NONE"
.balign 4
	.asciz "OPA"
.balign 4
	.asciz "TEX"
.balign 4
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
	.4byte 0x00000000
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
	.4byte 0x00000000
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
.global lbl_803DD310
lbl_803DD310:
	.4byte 0x00000000
	.4byte 0x00000000
.global lbl_803DD318
lbl_803DD318:
	.4byte 0x00000000
.global lbl_803DD31C
lbl_803DD31C:
	.4byte 0x25730000
.global lbl_803DD320
lbl_803DD320:
	.4byte 0x6C666772
	.4byte 0x6F757000
.global lbl_803DD328
lbl_803DD328:
	.4byte 0x74657849
	.4byte 0x6D670000
	.4byte 0x80228C40
	.4byte 0x00000000
.global __RTTI__10BinobjInfo
__RTTI__10BinobjInfo:
	.4byte 0x80228C34
	.4byte 0x80228C4C
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD340
	.4byte 0
	.4byte 0x80228C0C
	.4byte 0x80228C74
.global __RTTI__11LFlareGroup
__RTTI__11LFlareGroup:
	.4byte 0x80228C68
	.4byte 0x80228C80
.global __RTTI__9StdSystem
__RTTI__9StdSystem:
	.4byte 0x80228C00
	.4byte 0
.global __RTTI__10TexobjInfo
__RTTI__10TexobjInfo:
	.4byte 0x80228CD8
	.4byte 0x80228CE4
.global __RTTI__10ShpobjInfo
__RTTI__10ShpobjInfo:
	.4byte 0x80228D00
	.4byte 0x80228D0C
.global __RTTI__10AnmobjInfo
__RTTI__10AnmobjInfo:
	.4byte 0x80228D54
	.4byte 0x80228D60
	.4byte 0x4E6F6465
	.4byte 0
.global lbl_803DD388
lbl_803DD388:
	.4byte 0x25732573
	.4byte 0x00000000
	.4byte 0x5352544E
	.4byte 0x6F646500
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD398
	.4byte 0x00000000
	.4byte 0x80228D8C
	.4byte 0x80228D98
	.4byte 0x803DD380
	.4byte 0x80228DA4
.global __RTTI__7SRTNode
__RTTI__7SRTNode:
	.4byte 0x803DD390
	.4byte 0x80228DB8
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD3C0
	.4byte 0x00000000
	.4byte 0x80228E6C
	.4byte 0x80228E78
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DD3D8
	.4byte 0x80228E84
.global __RTTI__10Controller
__RTTI__10Controller:
	.4byte 0x80228E60
	.4byte 0x80228E98
.global lbl_803DD3F0
lbl_803DD3F0:
	.4byte 0x00000000
.global lbl_803DD3F4
lbl_803DD3F4:
	.4byte 0x00000000
.global lbl_803DD3F8
lbl_803DD3F8:
	.4byte 0x00000000
.global lbl_803DD3FC
lbl_803DD3FC:
	.4byte 0x00000000
.global lbl_803DD400
lbl_803DD400:
	.4byte 0x00000000
.global lbl_803DD404
lbl_803DD404:
	.4byte 0x00000000
.global lbl_803DD408
lbl_803DD408:
	.4byte 0x00000000
.global lbl_803DD40C
lbl_803DD40C:
	.4byte 0x00000000
.global lbl_803DD410
lbl_803DD410:
	.4byte 0x00000000
.global lbl_803DD414
lbl_803DD414:
	.4byte 0x00000000
.global lbl_803DD418
lbl_803DD418:
	.4byte 0x00000000
.global lbl_803DD41C
lbl_803DD41C:
	.4byte 0x00000000
.global lbl_803DD420
lbl_803DD420:
	.4byte 0x00000000
.global lbl_803DD424
lbl_803DD424:
	.4byte 0x00000000
.global lbl_803DD428
lbl_803DD428:
	.4byte 0x00000000
.global lbl_803DD42C
lbl_803DD42C:
	.4byte 0x00000000
.global lbl_803DD430
lbl_803DD430:
	.4byte 0x00000000
.global lbl_803DD434
lbl_803DD434:
	.float 1.0
.global lbl_803DD438
lbl_803DD438:
	.4byte 0x00000000
.global lbl_803DD43C
lbl_803DD43C:
	.4byte 0x00000000
.global lbl_803DD440
lbl_803DD440:
	.4byte 0xBF800000
.global lbl_803DD444
lbl_803DD444:
	.4byte 0x00000000
.global lbl_803DD448
lbl_803DD448:
	.4byte 0x00000000
.global lbl_803DD44C
lbl_803DD44C:
	.4byte 0x00000000
.global lbl_803DD450
lbl_803DD450:
	.4byte 0x00000000
.global lbl_803DD454
lbl_803DD454:
	.4byte 0x00000000
.global lbl_803DD458
lbl_803DD458:
	.4byte 0x408BA058
.global lbl_803DD45C
lbl_803DD45C:
	.4byte 0x00000000
.global lbl_803DD460
lbl_803DD460:
	.4byte 0x00000000
.global lbl_803DD464
lbl_803DD464:
	.4byte 0x00000000
.global lbl_803DD468
lbl_803DD468:
	.4byte 0x00000000
.global lbl_803DD46C
lbl_803DD46C:
	.float 1.0
	.4byte 0x53747265
	.4byte 0x616D0000
	.4byte 0x803DD470
	.4byte 0x00000000
	.4byte 0x80228F10
	.4byte 0x80228F24
.global __RTTI__13AtxFileStream
__RTTI__13AtxFileStream:
	.4byte 0x80228F00
	.4byte 0x80228F30
	.4byte 0x80228FAC
	.4byte 0x80228FB8
	.4byte 0x54657874
	.4byte 0x75726500
.global lbl_803DD4A0
lbl_803DD4A0:
	.4byte 0x74786500
.global lbl_803DD4A4
lbl_803DD4A4:
	.4byte 0x74657849
	.4byte 0x6D670000
.global lbl_803DD4AC
lbl_803DD4AC:
	.4byte 0x62746900
.global __RTTI__9GfxObject_1
__RTTI__9GfxObject_1:
	.4byte 0x80229050
	.4byte 0
.global __RTTI__7Texture_1
__RTTI__7Texture_1:
	.4byte 0x803DD498
	.4byte 0x8022905C
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD4C0
	.4byte 0x00000000
	.4byte 0x53797374
	.4byte 0x656D0000
.global glnWidth
glnWidth:
	.4byte 0x00000280
.global glnHeight
glnHeight:
	.4byte 0x000001E0
.global lbl_803DD4E0
lbl_803DD4E0:
	.4byte 0x00000000
.global lbl_803DD4E4
lbl_803DD4E4:
	.4byte 0x25730000
.global lbl_803DD4E8
lbl_803DD4E8:
	.4byte 0x25732573
	.4byte 0x25730000
.global lbl_803DD4F0
lbl_803DD4F0:
	.4byte 0x2E746578
	.4byte 0x74000000
.global lbl_803DD4F8
lbl_803DD4F8:
	.4byte 0x554E5553
	.4byte 0x45440000
.global lbl_803DD500
lbl_803DD500:
	.4byte 0x25303878
	.4byte 0x00000000
.global lbl_803DD508
lbl_803DD508:
	.4byte 0x25640000
.global lbl_803DD50C
lbl_803DD50C:
	.4byte 0x2E63746F
	.4byte 0x72730000
.global lbl_803DD514
lbl_803DD514:
	.4byte 0x726F6F74
	.4byte 0x00000000
.global lbl_803DD51C
lbl_803DD51C:
	.4byte 0x74657849
	.4byte 0x6D670000
.global lbl_803DD524
lbl_803DD524:
	.4byte 0x73797300
.global "__RTTI__22IDelegate1<R8Graphics>"
"__RTTI__22IDelegate1<R8Graphics>":
	.4byte 0x802A5390
	.4byte 0
.global "__RTTI__29Delegate1<6System,R8Graphics>"
"__RTTI__29Delegate1<6System,R8Graphics>":
	.4byte 0x802A5370
	.4byte 0x802A53A8
	.4byte 0x53747265
	.4byte 0x616D0000
	.4byte 0x803DD538
	.4byte 0
.global __RTTI__9LogStream
__RTTI__9LogStream:
	.4byte 0x802A53CC
	.4byte 0x802A53D8
.global lbl_803DD550
lbl_803DD550:
	.4byte 0x25730A00
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD554
	.4byte 0x00000000
	.4byte 0x802A5448
	.4byte 0x802A5454
.global __RTTI__11AddressNode
__RTTI__11AddressNode:
	.4byte 0x802A543C
	.4byte 0x802A5460
.global __RTTI__8DirEntry
__RTTI__8DirEntry:
	.4byte 0x802A5484
	.4byte 0x802A5490
	.4byte 0x802A54DC
	.4byte 0x802A54F0
.global __RTTI__9DVDStream
__RTTI__9DVDStream:
	.4byte 0x802A54D0
	.4byte 0x802A54FC
.global __RTTI__9StdSystem_1
__RTTI__9StdSystem_1:
	.4byte 0x802A55D8
	.4byte 0
.global __RTTI__6System
__RTTI__6System:
	.4byte 0x803DD4D0
	.4byte 0x802A55E4
.global __RTTI__10AramStream
__RTTI__10AramStream:
	.4byte 0x802A5624
	.4byte 0x802A5630
	.4byte 0
.global __RTTI__13ControllerMgr
__RTTI__13ControllerMgr:
	.4byte 0x802A56BC
	.4byte 0
.global sScreenMode
sScreenMode:
	.4byte 0x802A5740
	.4byte 0x802A5704
.global sFirstFrame
sFirstFrame:
	.4byte 0x00000004
.global kDefaultFifoSize
kDefaultFifoSize:
	.4byte 0x00060000
.global kTempFifoSize
kTempFifoSize:
	.4byte 0x00010000
.global kDefaultDLSize
kDefaultDLSize:
	.4byte 0x00020000
.global sendMtxIndx
sendMtxIndx:
	.4byte 0x01000000
.global sendTxUVIndx
sendTxUVIndx:
	.4byte 0x01000000
	.4byte 0x00000000
.global lbl_803DD5D4
lbl_803DD5D4:
	.4byte 0x00000000
.global lbl_803DD5D8
lbl_803DD5D8:
	.4byte 0x00000000
.global lbl_803DD5DC
lbl_803DD5DC:
	.4byte 0x00000000
.global lbl_803DD5E0
lbl_803DD5E0:
	.4byte 0x00000000
.global lbl_803DD5E4
lbl_803DD5E4:
	.4byte 0x00000000
.global lbl_803DD5E8
lbl_803DD5E8:
	.4byte 0x00000000
.global lbl_803DD5EC
lbl_803DD5EC:
	.4byte 0x00000000
.global lbl_803DD5F0
lbl_803DD5F0:
	.4byte 0x00000000
	.4byte 0x53686170
	.4byte 0x65000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD5FC
	.4byte 0x00000000
	.4byte 0x802A5D24
	.4byte 0x802A5D30
.global __RTTI__9BaseShape_1
__RTTI__9BaseShape_1:
	.4byte 0x802A5D3C
	.4byte 0x802A5D48
.global __RTTI__5Shape
__RTTI__5Shape:
	.4byte 0x803DD5F4
	.4byte 0x802A5D5C
.global __RTTI__8Graphics_1
__RTTI__8Graphics_1:
	.4byte 0x802A5D9C
	.4byte 0
.global __RTTI__11DGXGraphics
__RTTI__11DGXGraphics:
	.4byte 0x802A56F8
	.4byte 0x802A5DA8
	.4byte 0
.global lbl_803DD638
lbl_803DD638:
	.4byte 0x47000000
.global lbl_803DD63C
lbl_803DD63C:
	.4byte 0x47000000
.global lbl_803DD640
lbl_803DD640:
	.4byte 0x47000000
.global lbl_803DD644
lbl_803DD644:
	.4byte 0xC7000000
.global lbl_803DD648
lbl_803DD648:
	.4byte 0xC7000000
.global lbl_803DD64C
lbl_803DD64C:
	.4byte 0xC7000000
.global lbl_803DD650
lbl_803DD650:
	.4byte 0x00000000
.global lbl_803DD654
lbl_803DD654:
	.4byte 0x00000000
.global lbl_803DD658
lbl_803DD658:
	.4byte 0x00000000
.global lbl_803DD65C
lbl_803DD65C:
	.4byte 0x00000000
.global lbl_803DD660
lbl_803DD660:
	.4byte 0x00000000
.global lbl_803DD664
lbl_803DD664:
	.4byte 0x00000000
.global lbl_803DD668
lbl_803DD668:
	.4byte 0x00000000
.global lbl_803DD66C
lbl_803DD66C:
	.4byte 0xC11CF5C3
.global lbl_803DD670
lbl_803DD670:
	.4byte 0x00000000
.global lbl_803DD674
lbl_803DD674:
	.4byte 0x00000000
.global lbl_803DD678
lbl_803DD678:
	.4byte 0x00000000
.global lbl_803DD67C
lbl_803DD67C:
	.4byte 0x00000000
.global lbl_803DD680
lbl_803DD680:
	.4byte 0x00000000
.global lbl_803DD684
lbl_803DD684:
	.4byte 0x00000000
.global lbl_803DD688
lbl_803DD688:
	.4byte 0x00000000
.global lbl_803DD68C
lbl_803DD68C:
	.4byte 0x00000000
.global lbl_803DD690
lbl_803DD690:
	.4byte 0x00000000
.global lbl_803DD694
lbl_803DD694:
	.4byte 0x00000000
.global lbl_803DD698
lbl_803DD698:
	.float 1.0
.global lbl_803DD69C
lbl_803DD69C:
	.float 1.0
.global lbl_803DD6A0
lbl_803DD6A0:
	.float 1.0
.global lbl_803DD6A4
lbl_803DD6A4:
	.4byte 0x00000000
.global lbl_803DD6A8
lbl_803DD6A8:
	.4byte 0x00000000
.global lbl_803DD6AC
lbl_803DD6AC:
	.4byte 0x00000000
.global lbl_803DD6B0
lbl_803DD6B0:
	.4byte 0x00000000
.global lbl_803DD6B4
lbl_803DD6B4:
	.4byte 0x00000000
.global lbl_803DD6B8
lbl_803DD6B8:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD6BC
	.4byte 0x00000000
	.4byte 0x802A5F08
	.4byte 0x802A5F14
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DD6D4
	.4byte 0x802A5F20
.global __RTTI__9RigidBody
__RTTI__9RigidBody:
	.4byte 0x802A5EFC
	.4byte 0x802A5F34
	.4byte 0
.global lbl_803DD6F0
lbl_803DD6F0:
	.4byte 0x416E696D
	.4byte 0x4D677200
.global lbl_803DD6F8
lbl_803DD6F8:
	.4byte 0x00000000
.global lbl_803DD6FC
lbl_803DD6FC:
	.4byte 0x70303000
.global lbl_803DD700
lbl_803DD700:
	.4byte 0x73706400
.global lbl_803DD704
lbl_803DD704:
	.4byte 0x61303000
.global lbl_803DD708
lbl_803DD708:
	.4byte 0x61303100
.global lbl_803DD70C
lbl_803DD70C:
	.4byte 0x616E696D
	.4byte 0x73000000
.global lbl_803DD714
lbl_803DD714:
	.4byte 0x25732F25
	.4byte 0x73000000
.global lbl_803DD71C
lbl_803DD71C:
	.4byte 0x616E6D00
	.4byte 0x802A5FF0
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD728
	.4byte 0x00000000
	.4byte 0x802A5FCC
	.4byte 0x802A6014
.global __RTTI__7AnimMgr
__RTTI__7AnimMgr:
	.4byte lbl_803DD6F0
	.4byte 0x802A6020
	.4byte 0x802A6054
	.4byte 0
.global "__RTTI__13Parm<6String>"
"__RTTI__13Parm<6String>":
	.4byte 0x802A6044
	.4byte 0x802A6060
.global "__RTTI__7Parm<f>"
"__RTTI__7Parm<f>":
	.4byte 0x802A6080
	.4byte 0x802A608C
.global "__RTTI__7Parm<i>"
"__RTTI__7Parm<i>":
	.4byte 0x802A60AC
	.4byte 0x802A60B8
.global __RTTI__8AnimInfo
__RTTI__8AnimInfo:
	.4byte 0x802A60D8
	.4byte 0x802A60E4
	.4byte 0x205B6F66
	.4byte 0x665D0000
	.4byte 0x20205B6F
	.4byte 0x6E5D0000
	.4byte 0x5B66756C
	.4byte 0x6C5D0000
.global lbl_803DD788
lbl_803DD788:
	.4byte 0x205B6F6E
	.4byte 0x5D000000
.global lbl_803DD790
lbl_803DD790:
	.4byte 0x5B6F6666
	.4byte 0x5D000000
	.4byte 0x63757374
	.4byte 0x6F6D0000
	.4byte 0x4446206F
	.4byte 0x66660000
.global filterNames
filterNames:
	.4byte 0x803DD798
	.4byte 0x803DD7A0
.global lbl_803DD7B0
lbl_803DD7B0:
	.4byte 0x00000000
.global lbl_803DD7B4
lbl_803DD7B4:
	.4byte 0x74303000
.global lbl_803DD7B8
lbl_803DD7B8:
	.4byte 0x74303100
.global lbl_803DD7BC
lbl_803DD7BC:
	.4byte 0x70303000
.global lbl_803DD7C0
lbl_803DD7C0:
	.4byte 0x70303100
.global lbl_803DD7C4
lbl_803DD7C4:
	.4byte 0x73303100
.global lbl_803DD7C8
lbl_803DD7C8:
	.4byte 0x70303200
.global lbl_803DD7CC
lbl_803DD7CC:
	.4byte 0x70303300
.global lbl_803DD7D0
lbl_803DD7D0:
	.4byte 0x73303300
.global lbl_803DD7D4
lbl_803DD7D4:
	.4byte 0x70303400
.global lbl_803DD7D8
lbl_803DD7D8:
	.4byte 0x70303500
.global lbl_803DD7DC
lbl_803DD7DC:
	.4byte 0x70303600
.global lbl_803DD7E0
lbl_803DD7E0:
	.4byte 0x78393900
.global lbl_803DD7E4
lbl_803DD7E4:
	.4byte 0x78393800
.global lbl_803DD7E8
lbl_803DD7E8:
	.4byte 0x626C6168
	.4byte 0x00000000
.global lbl_803DD7F0
lbl_803DD7F0:
	.4byte 0x6C6F6164
	.4byte 0x00000000
.global lbl_803DD7F8
lbl_803DD7F8:
	.4byte 0x7061726D
	.4byte 0x732F0000
.global lbl_803DD800
lbl_803DD800:
	.4byte 0x61707000
.global lbl_803DD804
lbl_803DD804:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DD80C
lbl_803DD80C:
	.4byte 0x6C666772
	.4byte 0x6F757000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD814
	.4byte 0x00000000
	.4byte 0x802A6368
	.4byte 0x802A6374
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DD82C
	.4byte 0x802A6380
.global __RTTI__11GameGenNode
__RTTI__11GameGenNode:
	.4byte 0x802A635C
	.4byte 0x802A6394
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DD844
	.4byte 0x802A6410
.global __RTTI__11GameGenFlow
__RTTI__11GameGenFlow:
	.4byte 0x802A6320
	.4byte 0x802A6460
	.4byte 0x802A64D8
	.4byte 0
.global __RTTI__8GameFlow
__RTTI__8GameFlow:
	.4byte lbl_802A6138
	.4byte 0x802A655C
.global "__RTTI__18IDelegate1<R4Menu>"
"__RTTI__18IDelegate1<R4Menu>":
	.4byte 0x802A65C4
	.4byte 0
.global "__RTTI__27Delegate1<8GameFlow,R4Menu>"
"__RTTI__27Delegate1<8GameFlow,R4Menu>":
	.4byte 0x802A65A8
	.4byte 0x802A65D8
.global __RTTI__9LoadIdler
__RTTI__9LoadIdler:
	.4byte 0x802A660C
	.4byte 0x802A6618
.global __RTTI__13GameLoadIdler
__RTTI__13GameLoadIdler:
	.4byte 0x802A65FC
	.4byte 0x802A662C
.global __RTTI__10MemoryCard
__RTTI__10MemoryCard:
	.4byte 0x802A669C
	.4byte 0x802A66A8
	.4byte 0
.global lbl_803DD898
lbl_803DD898:
	.4byte 0x67656E66
	.4byte 0x696C6500
.global lbl_803DD8A0
lbl_803DD8A0:
	.4byte 0x00000000
.global lbl_803DD8A4
lbl_803DD8A4:
	.4byte 0x25640000
.global lbl_803DD8A8
lbl_803DD8A8:
	.4byte 0x25730000
.global lbl_803DD8AC
lbl_803DD8AC:
	.4byte 0x73746167
	.4byte 0x65730000
.global lbl_803DD8B4
lbl_803DD8B4:
	.4byte 0x6E65775F
	.4byte 0x6D617000
.global lbl_803DD8BC
lbl_803DD8BC:
	.4byte 0x76697369
	.4byte 0x626C6500
.global lbl_803DD8C4
lbl_803DD8C4:
	.4byte 0x6E616D65
	.4byte 0x00000000
.global lbl_803DD8CC
lbl_803DD8CC:
	.4byte 0x69640000
.global lbl_803DD8D0
lbl_803DD8D0:
	.4byte 0x63686964
	.4byte 0x00000000
.global lbl_803DD8D8
lbl_803DD8D8:
	.4byte 0x66696C65
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD8E0
	.4byte 0x00000000
	.4byte 0x802A67FC
	.4byte 0x802A6808
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DD8F8
	.4byte 0x802A6814
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DD908
	.4byte 0x802A6828
.global __RTTI__16OnePlayerSection
__RTTI__16OnePlayerSection:
	.4byte 0x802A67E8
	.4byte 0x802A6844
.global __RTTI__11GenFileInfo
__RTTI__11GenFileInfo:
	.4byte 0x802A689C
	.4byte 0x802A68A8
.global __RTTI__9StageInfo
__RTTI__9StageInfo:
	.4byte 0x802A68E8
	.4byte 0x802A68F4
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD930
	.4byte 0
	.4byte 0x802A6940
	.4byte 0x802A694C
.global __RTTI__9PlayState
__RTTI__9PlayState:
	.4byte 0x802A6934
	.4byte 0x802A6958
.global __RTTI__9GamePrefs
__RTTI__9GamePrefs:
	.4byte 0x802A6928
	.4byte 0x802A6980
.global lbl_803DD958
lbl_803DD958:
	.4byte 0x00000000
.global lbl_803DD95C
lbl_803DD95C:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DD964
lbl_803DD964:
	.4byte 0x73657475
	.4byte 0x70000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD96C
	.4byte 0x00000000
	.4byte 0x802A7460
	.4byte 0x802A746C
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DD984
	.4byte 0x802A7478
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DD994
	.4byte 0x802A748C
.global __RTTI__16GameSetupSection
__RTTI__16GameSetupSection:
	.4byte 0x802A744C
	.4byte 0x802A74A8
	.4byte 0x53747265
	.4byte 0x616D0000
	.4byte 0x803DD9AC
	.4byte 0
	.4byte 0x802A7528
	.4byte 0x802A753C
.global __RTTI__9RamStream
__RTTI__9RamStream:
	.4byte 0x802A751C
	.4byte 0x802A7548
	.4byte 0
.global lbl_803DD9D0
lbl_803DD9D0:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DD9D8
	.4byte 0x00000000
	.4byte 0x802A76B4
	.4byte 0x802A76C0
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DD9F0
	.4byte 0x802A7700
.global __RTTI__22CardSelectSetupSection
__RTTI__22CardSelectSetupSection:
	.4byte 0x802A76E8
	.4byte 0x802A7714
.global lbl_803DDA08
lbl_803DDA08:
	.4byte 0x25730000
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DDA0C
	.4byte 0x802A7774
.global __RTTI__17CardSelectSection
__RTTI__17CardSelectSection:
	.4byte 0x802A7760
	.4byte 0x802A7790
	.4byte 0
.global lbl_803DDA28
lbl_803DDA28:
	.4byte 0x25730000
.global lbl_803DDA2C
lbl_803DDA2C:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DDA34
lbl_803DDA34:
	.4byte 0x6D657373
	.4byte 0x61676500
.global lbl_803DDA3C
lbl_803DDA3C:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDA40
	.4byte 0x00000000
	.4byte 0x802A78E0
	.4byte 0x802A78EC
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DDA58
	.4byte 0x802A792C
.global __RTTI__21MapSelectSetupSection
__RTTI__21MapSelectSetupSection:
	.4byte 0x802A7914
	.4byte 0x802A7940
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DDA70
	.4byte 0x802A79A0
.global __RTTI__16MapSelectSection
__RTTI__16MapSelectSection:
	.4byte 0x802A798C
	.4byte 0x802A79BC
.global "__RTTI__18IDelegate1<R4Menu>_1"
"__RTTI__18IDelegate1<R4Menu>_1":
	.4byte 0x802A7A60
	.4byte 0
.global "__RTTI__23Delegate1<4Menu,R4Menu>"
"__RTTI__23Delegate1<4Menu,R4Menu>":
	.4byte 0x802A7A48
	.4byte 0x802A7A74
.global "__RTTI__41Delegate1<21MapSelectSetupSection,R4Menu>"
"__RTTI__41Delegate1<21MapSelectSetupSection,R4Menu>":
	.4byte 0x802A7A8C
	.4byte 0x802A7AB8
.global lbl_803DDAA0
lbl_803DDAA0:
	.4byte 0x00000000
.global lbl_803DDAA4
lbl_803DDAA4:
	.4byte 0x00000000
.global lbl_803DDAA8
lbl_803DDAA8:
	.4byte 0x00000000
.global lbl_803DDAAC
lbl_803DDAAC:
	.4byte 0x00000000
.global lbl_803DDAB0
lbl_803DDAB0:
	.4byte 0x00000000
.global lbl_803DDAB4
lbl_803DDAB4:
	.4byte 0x00000000
.global lbl_803DDAB8
lbl_803DDAB8:
	.4byte 0x00000000
.global lbl_803DDABC
lbl_803DDABC:
	.4byte 0x3DCCCCCD
.global lbl_803DDAC0
lbl_803DDAC0:
	.4byte 0x3DCCCCCD
.global lbl_803DDAC4
lbl_803DDAC4:
	.4byte 0x3DCCCCCD
.global lbl_803DDAC8
lbl_803DDAC8:
	.4byte 0x00000000
.global lbl_803DDACC
lbl_803DDACC:
	.4byte 0x00000000
.global lbl_803DDAD0
lbl_803DDAD0:
	.4byte 0x00000000
.global lbl_803DDAD4
lbl_803DDAD4:
	.4byte 0x00000000
.global lbl_803DDAD8
lbl_803DDAD8:
	.4byte 0x00000000
.global lbl_803DDADC
lbl_803DDADC:
	.4byte 0xC0A00000
.global lbl_803DDAE0
lbl_803DDAE0:
	.4byte 0x3DCCCCCD
.global lbl_803DDAE4
lbl_803DDAE4:
	.4byte 0x3DCCCCCD
.global lbl_803DDAE8
lbl_803DDAE8:
	.4byte 0x3DCCCCCD
.global lbl_803DDAEC
lbl_803DDAEC:
	.4byte 0x00000000
.global lbl_803DDAF0
lbl_803DDAF0:
	.4byte 0x00000000
.global lbl_803DDAF4
lbl_803DDAF4:
	.4byte 0x00000000
.global lbl_803DDAF8
lbl_803DDAF8:
	.4byte 0x00000000
.global lbl_803DDAFC
lbl_803DDAFC:
	.4byte 0x00000000
.global lbl_803DDB00
lbl_803DDB00:
	.4byte 0xC0A00000
.global lbl_803DDB04
lbl_803DDB04:
	.4byte 0x00000000
.global lbl_803DDB08
lbl_803DDB08:
	.4byte 0x00000000
.global lbl_803DDB0C
lbl_803DDB0C:
	.4byte 0x00000000
.global lbl_803DDB10
lbl_803DDB10:
	.4byte 0x00000000
.global lbl_803DDB14
lbl_803DDB14:
	.4byte 0x00000000
.global lbl_803DDB18
lbl_803DDB18:
	.4byte 0x00000000
.global lbl_803DDB1C
lbl_803DDB1C:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DDB24
lbl_803DDB24:
	.4byte 0x616C6C00
.global lbl_803DDB28
lbl_803DDB28:
	.4byte 0x74656B69
	.4byte 0x00000000
.global lbl_803DDB30
lbl_803DDB30:
	.4byte 0x6D6F7669
	.4byte 0x65000000
.global lbl_803DDB38
lbl_803DDB38:
	.4byte 0x6D61704D
	.4byte 0x67720000
.global lbl_803DDB40
lbl_803DDB40:
	.4byte 0x73686170
	.4byte 0x65000000
.global lbl_803DDB48
lbl_803DDB48:
	.4byte 0x65666665
	.4byte 0x63747300
.global lbl_803DDB50
lbl_803DDB50:
	.4byte 0x67756900
.global lbl_803DDB54
lbl_803DDB54:
	.4byte 0x70617573
	.4byte 0x65000000
.global lbl_803DDB5C
lbl_803DDB5C:
	.4byte 0x25730000
.global lbl_803DDB60
lbl_803DDB60:
	.4byte 0x25660000
.global lbl_803DDB64
lbl_803DDB64:
	.4byte 0x6461794D
	.4byte 0x67720000
	.4byte 0x802A7BD0
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDB74
	.4byte 0x00000000
	.4byte 0x802A7C04
	.4byte 0x802A7C10
.global __RTTI__9GaugeInfo
__RTTI__9GaugeInfo:
	.4byte 0x802A7BF8
	.4byte 0x802A7C1C
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803DDB94
	.4byte 0x802A7C58
.global __RTTI__15BaseGameSection
__RTTI__15BaseGameSection:
	.4byte 0x802A7C6C
	.4byte 0x802A7C7C
.global __RTTI__23NewPikiGameSetupSection
__RTTI__23NewPikiGameSetupSection:
	.4byte 0x802A7C40
	.4byte 0x802A7C98
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DDBB4
	.4byte 0x802A7D04
.global __RTTI__18NewPikiGameSection
__RTTI__18NewPikiGameSection:
	.4byte 0x802A7CF0
	.4byte 0x802A7D20
.global __RTTI__18GameMovieInterface
__RTTI__18GameMovieInterface:
	.4byte 0x802A7DAC
	.4byte 0x802A7DC0
.global __RTTI__9ModeState
__RTTI__9ModeState:
	.4byte 0x802A7E00
	.4byte 0
.global __RTTI__16DayOverModeState
__RTTI__16DayOverModeState:
	.4byte 0x802A7DEC
	.4byte 0x802A7E0C
.global __RTTI__16MessageModeState
__RTTI__16MessageModeState:
	.4byte 0x802A7E2C
	.4byte 0x802A7E40
.global __RTTI__16RunningModeState
__RTTI__16RunningModeState:
	.4byte 0x802A7E60
	.4byte 0x802A7E74
.global __RTTI__21QuittingGameModeState
__RTTI__21QuittingGameModeState:
	.4byte 0x802A7E94
	.4byte 0x802A7EAC
.global __RTTI__18IntroGameModeState
__RTTI__18IntroGameModeState:
	.4byte 0x802A7EE0
	.4byte 0x802A7EF4
	.4byte 0
.global lbl_803DDC08
lbl_803DDC08:
	.4byte 0x3DCCCCCD
.global lbl_803DDC0C
lbl_803DDC0C:
	.4byte 0x3DCCCCCD
.global lbl_803DDC10
lbl_803DDC10:
	.4byte 0x3DCCCCCD
.global lbl_803DDC14
lbl_803DDC14:
	.4byte 0x00000000
.global lbl_803DDC18
lbl_803DDC18:
	.4byte 0x00000000
.global lbl_803DDC1C
lbl_803DDC1C:
	.4byte 0x00000000
.global lbl_803DDC20
lbl_803DDC20:
	.4byte 0x00000000
.global lbl_803DDC24
lbl_803DDC24:
	.4byte 0x00000000
.global lbl_803DDC28
lbl_803DDC28:
	.4byte 0xC0A00000
.global lbl_803DDC2C
lbl_803DDC2C:
	.4byte 0x00000000
.global lbl_803DDC30
lbl_803DDC30:
	.4byte 0x00000000
.global lbl_803DDC34
lbl_803DDC34:
	.4byte 0x00000000
.global lbl_803DDC38
lbl_803DDC38:
	.4byte 0x00000000
.global lbl_803DDC3C
lbl_803DDC3C:
	.4byte 0x00000000
.global lbl_803DDC40
lbl_803DDC40:
	.4byte 0x00000000
.global lbl_803DDC44
lbl_803DDC44:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DDC4C
lbl_803DDC4C:
	.4byte 0x6D6F7669
	.4byte 0x65000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDC54
	.4byte 0x00000000
	.4byte 0x802A7F98
	.4byte 0x802A7FA4
.global __RTTI__9ModeState_1
__RTTI__9ModeState_1:
	.4byte 0x802A7FDC
	.4byte 0
.global __RTTI__14IntroModeState
__RTTI__14IntroModeState:
	.4byte 0x802A7FCC
	.4byte 0x802A7FE8
.global __RTTI__17QuittingModeState
__RTTI__17QuittingModeState:
	.4byte 0x802A8008
	.4byte 0x802A801C
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803DDC84
	.4byte 0x802A8068
.global __RTTI__15BaseGameSection_1
__RTTI__15BaseGameSection_1:
	.4byte 0x802A807C
	.4byte 0x802A808C
.global __RTTI__21IntroGameSetupSection
__RTTI__21IntroGameSetupSection:
	.4byte 0x802A8050
	.4byte 0x802A80A8
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DDCA4
	.4byte 0x802A8114
.global __RTTI__16IntroGameSection
__RTTI__16IntroGameSection:
	.4byte 0x802A8100
	.4byte 0x802A8130
	.4byte 0
.global lbl_803DDCC0
lbl_803DDCC0:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DDCC8
lbl_803DDCC8:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDCCC
	.4byte 0x00000000
	.4byte 0x802A81EC
	.4byte 0x802A81F8
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DDCE4
	.4byte 0x802A8204
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DDCF4
	.4byte 0x802A8218
.global __RTTI__15GameExitSection
__RTTI__15GameExitSection:
	.4byte 0x802A81DC
	.4byte 0x802A8234
	.4byte 0
.global lbl_803DDD10
lbl_803DDD10:
	.4byte 0x00000000
.global lbl_803DDD14
lbl_803DDD14:
	.float 1.0
.global lbl_803DDD18
lbl_803DDD18:
	.4byte 0x00000000
.global lbl_803DDD1C
lbl_803DDD1C:
	.float 1.0
.global lbl_803DDD20
lbl_803DDD20:
	.4byte 0x00000000
.global lbl_803DDD24
lbl_803DDD24:
	.4byte 0x00000000
.global lbl_803DDD28
lbl_803DDD28:
	.4byte 0x42C80000
.global lbl_803DDD2C
lbl_803DDD2C:
	.4byte 0x00000000
.global lbl_803DDD30
lbl_803DDD30:
	.4byte 0x00000000
.global lbl_803DDD34
lbl_803DDD34:
	.4byte 0x00000000
.global lbl_803DDD38
lbl_803DDD38:
	.4byte 0x00000000
.global lbl_803DDD3C
lbl_803DDD3C:
	.4byte 0x00000000
.global lbl_803DDD40
lbl_803DDD40:
	.4byte 0x00000000
.global lbl_803DDD44
lbl_803DDD44:
	.4byte 0x00000000
.global lbl_803DDD48
lbl_803DDD48:
	.4byte 0x00000000
.global lbl_803DDD4C
lbl_803DDD4C:
	.4byte 0x00000000
.global lbl_803DDD50
lbl_803DDD50:
	.4byte 0x00000000
.global lbl_803DDD54
lbl_803DDD54:
	.4byte 0x00000000
.global lbl_803DDD58
lbl_803DDD58:
	.4byte 0x00000000
	.4byte 0x00000000
.global lbl_803DDD60
lbl_803DDD60:
	.4byte 0x47000000
.global lbl_803DDD64
lbl_803DDD64:
	.4byte 0x47000000
.global lbl_803DDD68
lbl_803DDD68:
	.4byte 0x47000000
.global lbl_803DDD6C
lbl_803DDD6C:
	.4byte 0xC7000000
.global lbl_803DDD70
lbl_803DDD70:
	.4byte 0xC7000000
.global lbl_803DDD74
lbl_803DDD74:
	.4byte 0xC7000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDD78
	.4byte 0x00000000
	.4byte 0x802A8348
	.4byte 0x802A8354
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DDD90
	.4byte 0x802A838C
.global __RTTI__9RigidBody_1
__RTTI__9RigidBody_1:
	.4byte 0x802A83A0
	.4byte 0x802A83AC
.global __RTTI__10DynObjBody
__RTTI__10DynObjBody:
	.4byte 0x802A83C8
	.4byte 0x802A83D4
.global __RTTI__12DynObjBridge
__RTTI__12DynObjBridge:
	.4byte 0x802A837C
	.4byte 0x802A83F8
	.4byte 0x802A84B0
	.4byte 0
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803DDDC0
	.4byte 0x802A84BC
	.4byte 0x802A84C8
	.4byte 0x802A84D4
.global __RTTI__18GenObjectMapObject
__RTTI__18GenObjectMapObject:
	.4byte 0x802A849C
	.4byte 0x802A84E8
.global lbl_803DDDE0
lbl_803DDDE0:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DDDE8
lbl_803DDDE8:
	.4byte 0x6D656E75
	.4byte 0x00000000
.global lbl_803DDDF0
lbl_803DDDF0:
	.4byte 0x25730000
	.4byte 0x4D656E75
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDDFC
	.4byte 0x00000000
	.4byte 0x802A85C4
	.4byte 0x802A85D0
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DDE14
	.4byte 0x802A85DC
.global __RTTI__4Menu
__RTTI__4Menu:
	.4byte 0x803DDDF4
	.4byte 0x802A85F0
	.4byte 0
	.4byte 0x802A8690
	.4byte 0
.global lbl_803DDE38
lbl_803DDE38:
	.4byte 0x6F766C00
.global lbl_803DDE3C
lbl_803DDE3C:
	.4byte 0x2564206D
	.4byte 0x61747300
.global lbl_803DDE44
lbl_803DDE44:
	.4byte 0x2564206D
	.4byte 0x74787300
.global lbl_803DDE4C
lbl_803DDE4C:
	.4byte 0x616C6C00
.global lbl_803DDE50
lbl_803DDE50:
	.4byte 0x61707000
	.4byte 0x53747265
	.4byte 0x616D0000
	.4byte 0x803DDE54
	.4byte 0x00000000
	.4byte 0x802A8760
	.4byte 0x802A876C
.global __RTTI__16AtxCommandStream
__RTTI__16AtxCommandStream:
	.4byte 0x802A874C
	.4byte 0x802A8778
	.4byte 0x47616D65
	.4byte 0x41707000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDE7C
	.4byte 0
	.4byte 0x802A87E4
	.4byte 0x802A87F0
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803DDE94
	.4byte 0x802A87FC
	.4byte 0x42617365
	.4byte 0x41707000
.global __RTTI__7BaseApp_1
__RTTI__7BaseApp_1:
	.4byte 0x803DDEA4
	.4byte 0x802A8810
.global __RTTI__7GameApp
__RTTI__7GameApp:
	.4byte 0x803DDE74
	.4byte 0x802A882C
.global __RTTI__11PlugPikiApp
__RTTI__11PlugPikiApp:
	.4byte 0x802A889C
	.4byte 0x802A88A8
	.4byte 0
.global lbl_803DDEC8
lbl_803DDEC8:
	.4byte 0x00000000
.global lbl_803DDECC
lbl_803DDECC:
	.4byte 0x00000000
.global lbl_803DDED0
lbl_803DDED0:
	.float 1.0
.global lbl_803DDED4
lbl_803DDED4:
	.4byte 0x00000000
.global lbl_803DDED8
lbl_803DDED8:
	.4byte 0x00000000
.global lbl_803DDEDC
lbl_803DDEDC:
	.4byte 0x00000000
.global lbl_803DDEE0
lbl_803DDEE0:
	.float 1.0
.global lbl_803DDEE4
lbl_803DDEE4:
	.4byte 0x00000000
.global lbl_803DDEE8
lbl_803DDEE8:
	.4byte 0x00000000
.global lbl_803DDEEC
lbl_803DDEEC:
	.4byte 0x41A00000
.global lbl_803DDEF0
lbl_803DDEF0:
	.4byte 0x00000000
.global lbl_803DDEF4
lbl_803DDEF4:
	.4byte 0x43FA0000
.global lbl_803DDEF8
lbl_803DDEF8:
	.4byte 0x43960000
.global lbl_803DDEFC
lbl_803DDEFC:
	.4byte 0xC1C80000
.global lbl_803DDF00
lbl_803DDF00:
	.4byte 0x41C80000
.global lbl_803DDF04
lbl_803DDF04:
	.4byte 0x43960000
.global lbl_803DDF08
lbl_803DDF08:
	.4byte 0xC1400000
.global lbl_803DDF0C
lbl_803DDF0C:
	.4byte 0x43FA0000
.global lbl_803DDF10
lbl_803DDF10:
	.4byte 0x43960000
.global lbl_803DDF14
lbl_803DDF14:
	.4byte 0x43FA0000
.global lbl_803DDF18
lbl_803DDF18:
	.4byte 0x00000000
.global lbl_803DDF1C
lbl_803DDF1C:
	.4byte 0x00000000
.global lbl_803DDF20
lbl_803DDF20:
	.4byte 0x00000000
.global lbl_803DDF24
lbl_803DDF24:
	.4byte 0x00000000
.global lbl_803DDF28
lbl_803DDF28:
	.4byte 0xBF800000
.global lbl_803DDF2C
lbl_803DDF2C:
	.4byte 0x00000000
.global lbl_803DDF30
lbl_803DDF30:
	.4byte 0x43480000
.global lbl_803DDF34
lbl_803DDF34:
	.4byte 0x43480000
.global lbl_803DDF38
lbl_803DDF38:
	.4byte 0x42480000
.global lbl_803DDF3C
lbl_803DDF3C:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DDF44
lbl_803DDF44:
	.4byte 0x6461794D
	.4byte 0x67720000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDF4C
	.4byte 0x00000000
	.4byte 0x802A89D8
	.4byte 0x802A89E4
.global "__RTTI__18IDelegate1<R4Menu>_2"
"__RTTI__18IDelegate1<R4Menu>_2":
	.4byte 0x802A8A24
	.4byte 0
.global "__RTTI__37Delegate1<17TitleSetupSection,R4Menu>"
"__RTTI__37Delegate1<17TitleSetupSection,R4Menu>":
	.4byte 0x802A8A50
	.4byte 0x802A8A78
	.4byte 0x802A8A9C
	.4byte 0
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803DDF7C
	.4byte 0x802A8AD8
.global __RTTI__17TitleSetupSection
__RTTI__17TitleSetupSection:
	.4byte 0x802A8AC4
	.4byte 0x802A8AEC
.global lbl_803DDF94
lbl_803DDF94:
	.4byte 0x00000000
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DDF98
	.4byte 0x802A8B48
.global __RTTI__13TitlesSection
__RTTI__13TitlesSection:
	.4byte 0x802A8B38
	.4byte 0x802A8B64
.global __RTTI__20TitlesMovieInterface
__RTTI__20TitlesMovieInterface:
	.4byte 0x802A8BBC
	.4byte 0x802A8BD4
.global lbl_803DDFB8
lbl_803DDFB8:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DDFC0
	.4byte 0x00000000
	.4byte 0x802A8C38
	.4byte 0x802A8C44
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DDFD8
	.4byte 0x802A8C80
.global __RTTI__19NinLogoSetupSection
__RTTI__19NinLogoSetupSection:
	.4byte 0x802A8C6C
	.4byte 0x802A8C94
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DDFF0
	.4byte 0x802A8CF0
.global __RTTI__14NinLogoSection
__RTTI__14NinLogoSection:
	.4byte 0x802A8CE0
	.4byte 0x802A8D0C
.global lbl_803DE008
lbl_803DE008:
	.4byte 0x47000000
.global lbl_803DE00C
lbl_803DE00C:
	.4byte 0x47000000
.global lbl_803DE010
lbl_803DE010:
	.4byte 0x47000000
.global lbl_803DE014
lbl_803DE014:
	.4byte 0xC7000000
.global lbl_803DE018
lbl_803DE018:
	.4byte 0xC7000000
.global lbl_803DE01C
lbl_803DE01C:
	.4byte 0xC7000000
.global lbl_803DE020
lbl_803DE020:
	.float 1.0
.global lbl_803DE024
lbl_803DE024:
	.float 1.0
.global lbl_803DE028
lbl_803DE028:
	.float 1.0
.global lbl_803DE02C
lbl_803DE02C:
	.4byte 0x00000000
.global lbl_803DE030
lbl_803DE030:
	.4byte 0x00000000
.global lbl_803DE034
lbl_803DE034:
	.4byte 0x00000000
.global lbl_803DE038
lbl_803DE038:
	.float 1.0
.global lbl_803DE03C
lbl_803DE03C:
	.float 1.0
.global lbl_803DE040
lbl_803DE040:
	.float 1.0
.global lbl_803DE044
lbl_803DE044:
	.float 1.0
.global lbl_803DE048
lbl_803DE048:
	.float 1.0
.global lbl_803DE04C
lbl_803DE04C:
	.float 1.0
.global lbl_803DE050
lbl_803DE050:
	.4byte 0x00000000
.global Kdl
Kdl:
	.4byte 0x3FA00000
.global lbl_803DE058
lbl_803DE058:
	.float 1.0
.global lbl_803DE05C
lbl_803DE05C:
	.float 1.0
.global lbl_803DE060
lbl_803DE060:
	.float 1.0
.global lbl_803DE064
lbl_803DE064:
	.4byte 0x00000000
.global lbl_803DE068
lbl_803DE068:
	.4byte 0xC30CCF5C
.global lbl_803DE06C
lbl_803DE06C:
	.4byte 0x00000000
.global lbl_803DE070
lbl_803DE070:
	.4byte 0x6E616D65
	.4byte 0x00000000
.global lbl_803DE078
lbl_803DE078:
	.4byte 0x25660000
.global lbl_803DE07C
lbl_803DE07C:
	.4byte 0x25640000
.global lbl_803DE080
lbl_803DE080:
	.4byte 0x00000000
.global lbl_803DE084
lbl_803DE084:
	.4byte 0x00000000
.global lbl_803DE088
lbl_803DE088:
	.4byte 0x00000000
.global lbl_803DE08C
lbl_803DE08C:
	.4byte 0x00000000
.global lbl_803DE090
lbl_803DE090:
	.4byte 0x00000000
.global lbl_803DE094
lbl_803DE094:
	.4byte 0x00000000
.global lbl_803DE098
lbl_803DE098:
	.4byte 0x00000000
.global lbl_803DE09C
lbl_803DE09C:
	.4byte 0x42B40000
.global lbl_803DE0A0
lbl_803DE0A0:
	.4byte 0x00000000
.global lbl_803DE0A4
lbl_803DE0A4:
	.4byte 0x252E3166
	.4byte 0x00000000
.global lbl_803DE0AC
lbl_803DE0AC:
	.4byte 0x6461794D
	.4byte 0x67720000
.global lbl_803DE0B4
lbl_803DE0B4:
	.4byte 0x726F6F6D
	.4byte 0x73000000
.global lbl_803DE0BC
lbl_803DE0BC:
	.4byte 0x00000000
.global lbl_803DE0C0
lbl_803DE0C0:
	.4byte 0x42700000
.global lbl_803DE0C4
lbl_803DE0C4:
	.4byte 0x42C80000
.global lbl_803DE0C8
lbl_803DE0C8:
	.float 1.0
.global lbl_803DE0CC
lbl_803DE0CC:
	.4byte 0x00000000
.global lbl_803DE0D0
lbl_803DE0D0:
	.4byte 0x00000000
.global lbl_803DE0D4
lbl_803DE0D4:
	.4byte 0x00000000
.global lbl_803DE0D8
lbl_803DE0D8:
	.float 1.0
.global lbl_803DE0DC
lbl_803DE0DC:
	.4byte 0x00000000
.global lbl_803DE0E0
lbl_803DE0E0:
	.4byte 0x00000000
.global lbl_803DE0E4
lbl_803DE0E4:
	.4byte 0x00000000
.global lbl_803DE0E8
lbl_803DE0E8:
	.float 1.0
.global lbl_803DE0EC
lbl_803DE0EC:
	.float 1.0
.global lbl_803DE0F0
lbl_803DE0F0:
	.float 1.0
.global lbl_803DE0F4
lbl_803DE0F4:
	.float 1.0
.global lbl_803DE0F8
lbl_803DE0F8:
	.4byte 0x00000000
.global lbl_803DE0FC
lbl_803DE0FC:
	.4byte 0x00000000
.global lbl_803DE100
lbl_803DE100:
	.4byte 0x00000000
.global lbl_803DE104
lbl_803DE104:
	.4byte 0x00000000
.global lbl_803DE108
lbl_803DE108:
	.4byte 0x00000000
.global lbl_803DE10C
lbl_803DE10C:
	.4byte 0x00000000
.global lbl_803DE110
lbl_803DE110:
	.4byte 0x41800000
.global lbl_803DE114
lbl_803DE114:
	.4byte 0x41800000
.global lbl_803DE118
lbl_803DE118:
	.4byte 0x41800000
.global lbl_803DE11C
lbl_803DE11C:
	.4byte 0x41800000
.global lbl_803DE120
lbl_803DE120:
	.4byte 0x41800000
.global lbl_803DE124
lbl_803DE124:
	.4byte 0x41800000
.global lbl_803DE128
lbl_803DE128:
	.float 1.0
.global lbl_803DE12C
lbl_803DE12C:
	.float 1.0
.global lbl_803DE130
lbl_803DE130:
	.float 1.0
.global lbl_803DE134
lbl_803DE134:
	.4byte 0x00000000
.global lbl_803DE138
lbl_803DE138:
	.4byte 0x00000000
.global lbl_803DE13C
lbl_803DE13C:
	.4byte 0x00000000
.global lbl_803DE140
lbl_803DE140:
	.4byte 0x00000000
.global lbl_803DE144
lbl_803DE144:
	.4byte 0x00000000
.global lbl_803DE148
lbl_803DE148:
	.4byte 0x00000000
.global lbl_803DE14C
lbl_803DE14C:
	.4byte 0x3DCCCCCD
.global lbl_803DE150
lbl_803DE150:
	.4byte 0x3DCCCCCD
.global lbl_803DE154
lbl_803DE154:
	.4byte 0x3DCCCCCD
.global lbl_803DE158
lbl_803DE158:
	.4byte 0x41200000
.global lbl_803DE15C
lbl_803DE15C:
	.4byte 0x2564202F
	.4byte 0x20256400
.global lbl_803DE164
lbl_803DE164:
	.4byte 0x00000000
.global lbl_803DE168
lbl_803DE168:
	.4byte 0x00000000
.global lbl_803DE16C
lbl_803DE16C:
	.4byte 0x00000000
.global lbl_803DE170
lbl_803DE170:
	.4byte 0x00000000
.global lbl_803DE174
lbl_803DE174:
	.4byte 0x00000000
.global lbl_803DE178
lbl_803DE178:
	.4byte 0x00000000
.global lbl_803DE17C
lbl_803DE17C:
	.4byte 0x41200000
.global lbl_803DE180
lbl_803DE180:
	.4byte 0x00000000
.global lbl_803DE184
lbl_803DE184:
	.4byte 0x00000000
.global lbl_803DE188
lbl_803DE188:
	.4byte 0x00000000
.global lbl_803DE18C
lbl_803DE18C:
	.4byte 0x3727C5AC
.global lbl_803DE190
lbl_803DE190:
	.4byte 0x00000000
.global lbl_803DE194
lbl_803DE194:
	.4byte 0x00000000
.global lbl_803DE198
lbl_803DE198:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DE19C
	.4byte 0x00000000
	.4byte 0x802A8E58
	.4byte 0x802A8E64
.global __RTTI__12ShadowCaster
__RTTI__12ShadowCaster:
	.4byte 0x802A8E48
	.4byte 0x802A8E70
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803DE1BC
	.4byte 0x802A8EA4
.global __RTTI__12DynSimulator
__RTTI__12DynSimulator:
	.4byte 0x802A8E94
	.4byte 0x802A8EB8
.global __RTTI__15MaterialHandler_1
__RTTI__15MaterialHandler_1:
	.4byte 0x802A8F18
	.4byte 0
.global __RTTI__17MapProjMatHandler
__RTTI__17MapProjMatHandler:
	.4byte 0x802A8F04
	.4byte 0x802A8F28
.global __RTTI__17MapShadMatHandler
__RTTI__17MapShadMatHandler:
	.4byte 0x802A8F44
	.4byte 0x802A8F58
.global __RTTI__9RigidBody_2
__RTTI__9RigidBody_2:
	.4byte 0x802A8F84
	.4byte 0x802A8F90
.global __RTTI__10DynObjBody_1
__RTTI__10DynObjBody_1:
	.4byte 0x802A8FAC
	.4byte 0x802A8FB8
.global __RTTI__14DynObjPushable
__RTTI__14DynObjPushable:
	.4byte 0x802A8F74
	.4byte 0x802A8FDC
.global __RTTI__12DynObjSeeSaw
__RTTI__12DynObjSeeSaw:
	.4byte 0x802A90F8
	.4byte 0x802A9108
	.4byte 0x802A91BC
	.4byte 0x802A91CC
.global __RTTI__12DynCollShape
__RTTI__12DynCollShape:
	.4byte 0x802A91E8
	.4byte 0x802A91F8
.global __RTTI__14DynCollObjBody
__RTTI__14DynCollObjBody:
	.4byte 0x802A91AC
	.4byte 0x802A921C
.global __RTTI__12DynMapObject
__RTTI__12DynMapObject:
	.4byte 0x802A9290
	.4byte 0x802A92A0
.global __RTTI__13MapObjectPart
__RTTI__13MapObjectPart:
	.4byte 0x802A9330
	.4byte 0x802A9340
	.4byte 0x802A9404
	.4byte 0
.global __RTTI__14MapObjAnimator
__RTTI__14MapObjAnimator:
	.4byte 0x802A93F4
	.4byte 0x802A9410
	.4byte 0
.global lbl_803DE248
lbl_803DE248:
	.4byte 0x00000000
.global lbl_803DE24C
lbl_803DE24C:
	.4byte 0x43EB0000
.global lbl_803DE250
lbl_803DE250:
	.4byte 0x00000000
.global lbl_803DE254
lbl_803DE254:
	.4byte 0x00000000
.global lbl_803DE258
lbl_803DE258:
	.4byte 0xBF800000
.global lbl_803DE25C
lbl_803DE25C:
	.4byte 0x00000000
.global lbl_803DE260
lbl_803DE260:
	.4byte 0xC3870000
.global lbl_803DE264
lbl_803DE264:
	.4byte 0xC3EB0000
.global lbl_803DE268
lbl_803DE268:
	.4byte 0x44200000
.global lbl_803DE26C
lbl_803DE26C:
	.4byte 0x00000000
.global lbl_803DE270
lbl_803DE270:
	.float 1.0
.global lbl_803DE274
lbl_803DE274:
	.4byte 0x00000000
.global lbl_803DE278
lbl_803DE278:
	.4byte 0x00000000
.global lbl_803DE27C
lbl_803DE27C:
	.4byte 0x43EB0000
.global lbl_803DE280
lbl_803DE280:
	.4byte 0x00000000
.global lbl_803DE284
lbl_803DE284:
	.4byte 0x00000000
.global lbl_803DE288
lbl_803DE288:
	.4byte 0xBF800000
.global lbl_803DE28C
lbl_803DE28C:
	.4byte 0x00000000
.global lbl_803DE290
lbl_803DE290:
	.4byte 0xC3870000
.global lbl_803DE294
lbl_803DE294:
	.4byte 0xC3EB0000
.global lbl_803DE298
lbl_803DE298:
	.4byte 0x44200000
.global lbl_803DE29C
lbl_803DE29C:
	.4byte 0x00000000
.global lbl_803DE2A0
lbl_803DE2A0:
	.4byte 0xBF800000
.global lbl_803DE2A4
lbl_803DE2A4:
	.4byte 0x00000000
.global lbl_803DE2A8
lbl_803DE2A8:
	.4byte 0x00000000
.global lbl_803DE2AC
lbl_803DE2AC:
	.4byte 0x43EB0000
.global lbl_803DE2B0
lbl_803DE2B0:
	.4byte 0x00000000
.global lbl_803DE2B4
lbl_803DE2B4:
	.4byte 0x00000000
.global lbl_803DE2B8
lbl_803DE2B8:
	.4byte 0xBF800000
.global lbl_803DE2BC
lbl_803DE2BC:
	.4byte 0x00000000
.global lbl_803DE2C0
lbl_803DE2C0:
	.4byte 0xC3870000
.global lbl_803DE2C4
lbl_803DE2C4:
	.4byte 0xC3EB0000
.global lbl_803DE2C8
lbl_803DE2C8:
	.4byte 0x44200000
.global lbl_803DE2CC
lbl_803DE2CC:
	.4byte 0x00000000
.global lbl_803DE2D0
lbl_803DE2D0:
	.4byte 0xBF800000
.global lbl_803DE2D4
lbl_803DE2D4:
	.4byte 0x00000000
.global lbl_803DE2D8
lbl_803DE2D8:
	.4byte 0x00000000
.global lbl_803DE2DC
lbl_803DE2DC:
	.4byte 0x43EB0000
.global lbl_803DE2E0
lbl_803DE2E0:
	.4byte 0x00000000
.global lbl_803DE2E4
lbl_803DE2E4:
	.4byte 0x00000000
.global lbl_803DE2E8
lbl_803DE2E8:
	.4byte 0xBF800000
.global lbl_803DE2EC
lbl_803DE2EC:
	.4byte 0x00000000
.global lbl_803DE2F0
lbl_803DE2F0:
	.4byte 0x5A000000
.global lbl_803DE2F4
lbl_803DE2F4:
	.4byte 0x59000000
.global lbl_803DE2F8
lbl_803DE2F8:
	.4byte 0x58000000
.global lbl_803DE2FC
lbl_803DE2FC:
	.4byte 0x41000000
.global lbl_803DE300
lbl_803DE300:
	.4byte 0x2573203D
	.4byte 0x20256400
.global lbl_803DE308
lbl_803DE308:
	.4byte 0x42000000
.global lbl_803DE30C
lbl_803DE30C:
	.4byte 0x47000000
.global lbl_803DE310
lbl_803DE310:
	.4byte 0x52000000
.global lbl_803DE314
lbl_803DE314:
	.4byte 0x46617200
.global lbl_803DE318
lbl_803DE318:
	.4byte 0x4E656172
	.4byte 0x00000000
	.4byte 0x4F464600
	.4byte 0x504F494E
	.4byte 0x54000000
	.4byte 0x53504F54
	.4byte 0x00000000
.global lightTypes
lightTypes:
	.4byte 0x00000001
	.4byte 0x00000003
	.4byte 0x676C6F62
	.4byte 0x616C0000
.global lightMoveNames
lightMoveNames:
	.4byte 0x803DE33C
	.4byte 0x802A962C
.global lbl_803DE34C
lbl_803DE34C:
	.4byte 0x636F6C6F
	.4byte 0x75720000
.global lbl_803DE354
lbl_803DE354:
	.4byte 0x466F7600
.global lbl_803DE358
lbl_803DE358:
	.4byte 0x52203D20
	.4byte 0x25640000
.global lbl_803DE360
lbl_803DE360:
	.4byte 0x47203D20
	.4byte 0x25640000
.global lbl_803DE368
lbl_803DE368:
	.4byte 0x42203D20
	.4byte 0x25640000
.global lbl_803DE370
lbl_803DE370:
	.4byte 0x41203D20
	.4byte 0x25640000
.global lbl_803DE378
lbl_803DE378:
	.4byte 0x426C7572
	.4byte 0x00000000
.global lbl_803DE380
lbl_803DE380:
	.4byte 0x666F6700
.global lbl_803DE384
lbl_803DE384:
	.float 1.0
.global lbl_803DE388
lbl_803DE388:
	.float 1.0
.global lbl_803DE38C
lbl_803DE38C:
	.float 1.0
.global lbl_803DE390
lbl_803DE390:
	.4byte 0x00000000
.global lbl_803DE394
lbl_803DE394:
	.4byte 0x00000000
.global lbl_803DE398
lbl_803DE398:
	.4byte 0x00000000
.global lbl_803DE39C
lbl_803DE39C:
	.4byte 0x00000000
.global lbl_803DE3A0
lbl_803DE3A0:
	.4byte 0x00000000
.global lbl_803DE3A4
lbl_803DE3A4:
	.4byte 0x00000000
.global lbl_803DE3A8
lbl_803DE3A8:
	.4byte 0x451C4000
.global lbl_803DE3AC
lbl_803DE3AC:
	.4byte 0x00000000
.global lbl_803DE3B0
lbl_803DE3B0:
	.float 1.0
.global lbl_803DE3B4
lbl_803DE3B4:
	.float 1.0
.global lbl_803DE3B8
lbl_803DE3B8:
	.float 1.0
.global lbl_803DE3BC
lbl_803DE3BC:
	.4byte 0x00000000
.global lbl_803DE3C0
lbl_803DE3C0:
	.4byte 0x00000000
.global lbl_803DE3C4
lbl_803DE3C4:
	.4byte 0x00000000
.global lbl_803DE3C8
lbl_803DE3C8:
	.4byte 0x00000000
.global lbl_803DE3CC
lbl_803DE3CC:
	.4byte 0x00000000
.global lbl_803DE3D0
lbl_803DE3D0:
	.4byte 0x00000000
	.4byte 0x6E696768
	.4byte 0x74000000
	.4byte 0x6D6F726E
	.4byte 0x696E6700
	.4byte 0x64617900
	.4byte 0x6576656E
	.4byte 0x696E6700
	.4byte 0x6D6F7669
	.4byte 0x65000000
	.4byte 0x2B310000
	.4byte 0x2B320000
	.4byte 0x2B330000
	.4byte 0x2B340000
	.4byte 0x2B350000
.global lbl_803DE40C
lbl_803DE40C:
	.4byte 0x25640000
.global lbl_803DE410
lbl_803DE410:
	.4byte 0x6C696768
	.4byte 0x74000000
.global lbl_803DE418
lbl_803DE418:
	.4byte 0x74797065
	.4byte 0x00000000
.global lbl_803DE420
lbl_803DE420:
	.4byte 0x61747461
	.4byte 0x63680000
.global lbl_803DE428
lbl_803DE428:
	.4byte 0x666F7600
.global lbl_803DE42C
lbl_803DE42C:
	.4byte 0x25660000
.global lbl_803DE430
lbl_803DE430:
	.4byte 0x616D6269
	.4byte 0x656E7400
.global lbl_803DE438
lbl_803DE438:
	.4byte 0x64697374
	.4byte 0x00000000
.global "__RTTI__18IDelegate1<R4Menu>_3"
"__RTTI__18IDelegate1<R4Menu>_3":
	.4byte 0x802A98E8
	.4byte 0
.global "__RTTI__26Delegate1<7FogMenu,R4Menu>"
"__RTTI__26Delegate1<7FogMenu,R4Menu>":
	.4byte 0x802A98CC
	.4byte 0x802A98FC
	.4byte 0x466F674D
	.4byte 0x656E7500
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DE458
	.4byte 0
	.4byte 0x802A9914
	.4byte 0x802A9920
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803DE470
	.4byte 0x802A992C
	.4byte 0x4D656E75
	.4byte 0
.global __RTTI__4Menu_1
__RTTI__4Menu_1:
	.4byte 0x803DE480
	.4byte 0x802A9940
.global __RTTI__7FogMenu
__RTTI__7FogMenu:
	.4byte 0x803DE450
	.4byte 0x802A995C
.global __RTTI__9LightMenu
__RTTI__9LightMenu:
	.4byte 0x802A99D4
	.4byte 0x802A99E0
.global __RTTI__10DaySetMenu
__RTTI__10DaySetMenu:
	.4byte 0x802A9A58
	.4byte 0x802A9A64
.global "__RTTI__25Delegate1<6DayMgr,R4Menu>"
"__RTTI__25Delegate1<6DayMgr,R4Menu>":
	.4byte 0x802A9ADC
	.4byte 0x802A9AF8
.global "__RTTI__32Delegate1<12PositionMenu,R4Menu>"
"__RTTI__32Delegate1<12PositionMenu,R4Menu>":
	.4byte 0x802A9B10
	.4byte 0x802A9B30
.global __RTTI__12PositionMenu
__RTTI__12PositionMenu:
	.4byte 0x802A9B48
	.4byte 0x802A9B58
.global "__RTTI__30Delegate1<10ColourMenu,R4Menu>"
"__RTTI__30Delegate1<10ColourMenu,R4Menu>":
	.4byte 0x802A9BD0
	.4byte 0x802A9BF0
.global __RTTI__10ColourMenu
__RTTI__10ColourMenu:
	.4byte 0x802A9C38
	.4byte 0x802A9C44
.global "__RTTI__28Delegate1<9LightMenu,R4Menu>"
"__RTTI__28Delegate1<9LightMenu,R4Menu>":
	.4byte 0x802A9CBC
	.4byte 0x802A9CDC
.global lbl_803DE4D8
lbl_803DE4D8:
	.4byte 0x00000000
.global lbl_803DE4DC
lbl_803DE4DC:
	.4byte 0x74797065
	.4byte 0x00000000
.global lbl_803DE4E4
lbl_803DE4E4:
	.4byte 0x25640000
.global lbl_803DE4E8
lbl_803DE4E8:
	.4byte 0x666C6167
	.4byte 0x73000000
.global lbl_803DE4F0
lbl_803DE4F0:
	.4byte 0x7363656E
	.4byte 0x65000000
.global lbl_803DE4F8
lbl_803DE4F8:
	.4byte 0x73686170
	.4byte 0x65000000
.global lbl_803DE500
lbl_803DE500:
	.4byte 0x62756E64
	.4byte 0x6C650000
.global lbl_803DE508
lbl_803DE508:
	.4byte 0x616E696D
	.4byte 0x73000000
.global lbl_803DE510
lbl_803DE510:
	.4byte 0x61646443
	.4byte 0x75740000
.global lbl_803DE518
lbl_803DE518:
	.4byte 0x63757400
.global lbl_803DE51C
lbl_803DE51C:
	.4byte 0x6163746F
	.4byte 0x72000000
.global lbl_803DE524
lbl_803DE524:
	.4byte 0x6163666C
	.4byte 0x61677300
.global lbl_803DE52C
lbl_803DE52C:
	.4byte 0x616E696D
	.4byte 0x00000000
.global lbl_803DE534
lbl_803DE534:
	.4byte 0x6B657973
	.4byte 0x00000000
.global lbl_803DE53C
lbl_803DE53C:
	.4byte 0x00000000
.global lbl_803DE540
lbl_803DE540:
	.4byte 0x00000000
.global lbl_803DE544
lbl_803DE544:
	.4byte 0x00000000
.global lbl_803DE548
lbl_803DE548:
	.4byte 0x42800000
.global lbl_803DE54C
lbl_803DE54C:
	.4byte 0x42300000
.global lbl_803DE550
lbl_803DE550:
	.4byte 0x44EF2000
.global lbl_803DE554
lbl_803DE554:
	.4byte 0x42540000
.global lbl_803DE558
lbl_803DE558:
	.4byte 0x44918000
.global lbl_803DE55C
lbl_803DE55C:
	.4byte 0x44540000
.global lbl_803DE560
lbl_803DE560:
	.4byte 0xC6C35000
.global lbl_803DE564
lbl_803DE564:
	.4byte 0xC6C35000
.global lbl_803DE568
lbl_803DE568:
	.4byte 0xC6C35000
.global lbl_803DE56C
lbl_803DE56C:
	.float 1.0
.global lbl_803DE570
lbl_803DE570:
	.4byte 0x00000000
.global lbl_803DE574
lbl_803DE574:
	.4byte 0x00000000
.global lbl_803DE578
lbl_803DE578:
	.4byte 0xC6C35000
.global lbl_803DE57C
lbl_803DE57C:
	.4byte 0xC6C35000
.global lbl_803DE580
lbl_803DE580:
	.4byte 0xC6C35000
.global lbl_803DE584
lbl_803DE584:
	.4byte 0xC6C35000
.global lbl_803DE588
lbl_803DE588:
	.4byte 0xC6C35000
.global lbl_803DE58C
lbl_803DE58C:
	.4byte 0xC6C35000
.global lbl_803DE590
lbl_803DE590:
	.4byte 0xC6C35000
.global lbl_803DE594
lbl_803DE594:
	.4byte 0xC6C35000
.global lbl_803DE598
lbl_803DE598:
	.4byte 0xC6C35000
.global lbl_803DE59C
lbl_803DE59C:
	.4byte 0xC6C35000
.global lbl_803DE5A0
lbl_803DE5A0:
	.4byte 0xC6C35000
.global lbl_803DE5A4
lbl_803DE5A4:
	.4byte 0xC6C35000
.global lbl_803DE5A8
lbl_803DE5A8:
	.4byte 0x00000000
.global lbl_803DE5AC
lbl_803DE5AC:
	.float 1.0
.global lbl_803DE5B0
lbl_803DE5B0:
	.4byte 0x00000000
.global lbl_803DE5B4
lbl_803DE5B4:
	.4byte 0xC6C35000
.global lbl_803DE5B8
lbl_803DE5B8:
	.4byte 0xC6C35000
.global lbl_803DE5BC
lbl_803DE5BC:
	.4byte 0xC6C35000
.global lbl_803DE5C0
lbl_803DE5C0:
	.4byte 0xC6C35000
.global lbl_803DE5C4
lbl_803DE5C4:
	.4byte 0xC6C35000
.global lbl_803DE5C8
lbl_803DE5C8:
	.4byte 0xC6C35000
.global lbl_803DE5CC
lbl_803DE5CC:
	.4byte 0xC6C35000
.global lbl_803DE5D0
lbl_803DE5D0:
	.4byte 0xC6C35000
.global lbl_803DE5D4
lbl_803DE5D4:
	.4byte 0xC6C35000
.global lbl_803DE5D8
lbl_803DE5D8:
	.4byte 0xC6C35000
.global lbl_803DE5DC
lbl_803DE5DC:
	.4byte 0xC6C35000
.global lbl_803DE5E0
lbl_803DE5E0:
	.4byte 0xC6C35000
.global lbl_803DE5E4
lbl_803DE5E4:
	.4byte 0x00000000
.global lbl_803DE5E8
lbl_803DE5E8:
	.4byte 0x00000000
.global lbl_803DE5EC
lbl_803DE5EC:
	.4byte 0x00000000
.global lbl_803DE5F0
lbl_803DE5F0:
	.4byte 0x00000000
.global lbl_803DE5F4
lbl_803DE5F4:
	.4byte 0x00000000
.global lbl_803DE5F8
lbl_803DE5F8:
	.4byte 0x00000000
.global lbl_803DE5FC
lbl_803DE5FC:
	.4byte 0x00000000
.global lbl_803DE600
lbl_803DE600:
	.4byte 0x00000000
.global lbl_803DE604
lbl_803DE604:
	.4byte 0x00000000
.global lbl_803DE608
lbl_803DE608:
	.4byte 0x00000000
.global lbl_803DE60C
lbl_803DE60C:
	.4byte 0x00000000
.global lbl_803DE610
lbl_803DE610:
	.4byte 0x00000000
.global lbl_803DE614
lbl_803DE614:
	.4byte 0x00000000
.global lbl_803DE618
lbl_803DE618:
	.float 1.0
.global lbl_803DE61C
lbl_803DE61C:
	.4byte 0x00000000
.global lbl_803DE620
lbl_803DE620:
	.4byte 0x00000000
.global lbl_803DE624
lbl_803DE624:
	.4byte 0x00000000
.global lbl_803DE628
lbl_803DE628:
	.4byte 0x00000000
.global lbl_803DE62C
lbl_803DE62C:
	.4byte 0x00000000
.global lbl_803DE630
lbl_803DE630:
	.4byte 0x00000000
.global lbl_803DE634
lbl_803DE634:
	.4byte 0x00000000
.global lbl_803DE638
lbl_803DE638:
	.4byte 0x00000000
.global lbl_803DE63C
lbl_803DE63C:
	.4byte 0x00000000
.global lbl_803DE640
lbl_803DE640:
	.4byte 0x00000000
.global lbl_803DE644
lbl_803DE644:
	.4byte 0x00000000
.global lbl_803DE648
lbl_803DE648:
	.4byte 0x00000000
.global lbl_803DE64C
lbl_803DE64C:
	.4byte 0x00000000
.global lbl_803DE650
lbl_803DE650:
	.4byte 0x00000000
.global lbl_803DE654
lbl_803DE654:
	.4byte 0x43060000
.global lbl_803DE658
lbl_803DE658:
	.4byte 0x00000000
.global lbl_803DE65C
lbl_803DE65C:
	.4byte 0x00000000
.global lbl_803DE660
lbl_803DE660:
	.4byte 0x40E00000
.global lbl_803DE664
lbl_803DE664:
	.4byte 0x00000000
.global lbl_803DE668
lbl_803DE668:
	.4byte 0xC1666666
.global lbl_803DE66C
lbl_803DE66C:
	.4byte 0x416E6666
.global lbl_803DE670
lbl_803DE670:
	.4byte 0x41666666
.global lbl_803DE674
lbl_803DE674:
	.4byte 0xC1666666
.global lbl_803DE678
lbl_803DE678:
	.4byte 0x416E6666
.global lbl_803DE67C
lbl_803DE67C:
	.4byte 0xC1666666
.global lbl_803DE680
lbl_803DE680:
	.4byte 0x41666666
.global lbl_803DE684
lbl_803DE684:
	.4byte 0x416E6666
.global lbl_803DE688
lbl_803DE688:
	.4byte 0x41666666
.global lbl_803DE68C
lbl_803DE68C:
	.4byte 0x41666666
.global lbl_803DE690
lbl_803DE690:
	.4byte 0x416E6666
.global lbl_803DE694
lbl_803DE694:
	.4byte 0xC1666666
.global lbl_803DE698
lbl_803DE698:
	.4byte 0x00000000
.global lbl_803DE69C
lbl_803DE69C:
	.4byte 0x00000000
.global lbl_803DE6A0
lbl_803DE6A0:
	.4byte 0x00000000
.global lbl_803DE6A4
lbl_803DE6A4:
	.4byte 0x00000000
.global lbl_803DE6A8
lbl_803DE6A8:
	.4byte 0xC1E00000
.global lbl_803DE6AC
lbl_803DE6AC:
	.4byte 0x00000000
.global lbl_803DE6B0
lbl_803DE6B0:
	.4byte 0x00000000
.global lbl_803DE6B4
lbl_803DE6B4:
	.4byte 0x00000000
.global lbl_803DE6B8
lbl_803DE6B8:
	.4byte 0x00000000
.global lbl_803DE6BC
lbl_803DE6BC:
	.4byte 0x00000000
.global lbl_803DE6C0
lbl_803DE6C0:
	.4byte 0x00000000
.global lbl_803DE6C4
lbl_803DE6C4:
	.4byte 0x00000000
.global lbl_803DE6C8
lbl_803DE6C8:
	.4byte 0x00000000
.global lbl_803DE6CC
lbl_803DE6CC:
	.4byte 0x00000000
.global lbl_803DE6D0
lbl_803DE6D0:
	.4byte 0x00000000
.global lbl_803DE6D4
lbl_803DE6D4:
	.4byte 0x00000000
.global lbl_803DE6D8
lbl_803DE6D8:
	.4byte 0x00000000
.global lbl_803DE6DC
lbl_803DE6DC:
	.4byte 0x00000000
.global lbl_803DE6E0
lbl_803DE6E0:
	.4byte 0x00000000
.global lbl_803DE6E4
lbl_803DE6E4:
	.4byte 0x00000000
.global lbl_803DE6E8
lbl_803DE6E8:
	.4byte 0x00000000
.global lbl_803DE6EC
lbl_803DE6EC:
	.4byte 0x00000000
.global lbl_803DE6F0
lbl_803DE6F0:
	.4byte 0x00000000
.global lbl_803DE6F4
lbl_803DE6F4:
	.4byte 0x00000000
.global lbl_803DE6F8
lbl_803DE6F8:
	.4byte 0x00000000
.global lbl_803DE6FC
lbl_803DE6FC:
	.4byte 0x00000000
.global lbl_803DE700
lbl_803DE700:
	.4byte 0x00000000
.global lbl_803DE704
lbl_803DE704:
	.4byte 0x00000000
.global lbl_803DE708
lbl_803DE708:
	.4byte 0x00000000
.global lbl_803DE70C
lbl_803DE70C:
	.4byte 0x00000000
.global lbl_803DE710
lbl_803DE710:
	.4byte 0x00000000
.global lbl_803DE714
lbl_803DE714:
	.4byte 0x00000000
.global lbl_803DE718
lbl_803DE718:
	.4byte 0x00000000
.global lbl_803DE71C
lbl_803DE71C:
	.4byte 0x00000000
.global lbl_803DE720
lbl_803DE720:
	.4byte 0x00000000
.global lbl_803DE724
lbl_803DE724:
	.4byte 0x00000000
.global lbl_803DE728
lbl_803DE728:
	.4byte 0x00000000
.global lbl_803DE72C
lbl_803DE72C:
	.4byte 0x00000000
.global lbl_803DE730
lbl_803DE730:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DE734
	.4byte 0x00000000
	.4byte 0x802A9E70
	.4byte 0x802A9E7C
.global __RTTI__13ActorInstance
__RTTI__13ActorInstance:
	.4byte 0x802A9E60
	.4byte 0x802A9E88
.global __RTTI__8SceneCut
__RTTI__8SceneCut:
	.4byte 0x802A9EAC
	.4byte 0x802A9EB8
.global __RTTI__15CineShapeObject
__RTTI__15CineShapeObject:
	.4byte 0x802A9EDC
	.4byte 0x802A9EEC
.global __RTTI__9SceneData
__RTTI__9SceneData:
	.4byte 0x802A9F10
	.4byte 0x802A9F1C
	.4byte 0
.global lbl_803DE770
lbl_803DE770:
	.4byte 0x00000000
.global lbl_803DE774
lbl_803DE774:
	.4byte 0x42480000
.global lbl_803DE778
lbl_803DE778:
	.4byte 0x00000000
.global lbl_803DE77C
lbl_803DE77C:
	.4byte 0x00000000
.global lbl_803DE780
lbl_803DE780:
	.4byte 0x41200000
.global lbl_803DE784
lbl_803DE784:
	.4byte 0x3727C5AC
.global lbl_803DE788
lbl_803DE788:
	.4byte 0x00000000
.global lbl_803DE78C
lbl_803DE78C:
	.4byte 0x00000000
.global lbl_803DE790
lbl_803DE790:
	.4byte 0x00000000
.global lbl_803DE794
lbl_803DE794:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DE79C
	.4byte 0x00000000
	.4byte 0x802A9F7C
	.4byte 0x802A9F88
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DE7B4
	.4byte 0x802A9F94
.global __RTTI__9LightPool
__RTTI__9LightPool:
	.4byte 0x802A9F70
	.4byte 0x802A9FA8
	.4byte 0
.global icon_pals
icon_pals:
	.4byte 0x802AA060
.global lbl_803DE7D4
lbl_803DE7D4:
	.4byte 0x50696B6D
	.4byte 0x696E0000
.global lbl_803DE7DC
lbl_803DE7DC:
	.4byte 0x7E50696B
	.4byte 0x6D696E00
.global lbl_803DE7E4
lbl_803DE7E4:
	.4byte 0x426C6F63
	.4byte 0x6B730000
.global lbl_803DE7EC
lbl_803DE7EC:
	.4byte 0x25730000
	.4byte 0x62616E6E
	.4byte 0x65720000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DE7F8
	.4byte 0x00000000
	.4byte 0x53747265
	.4byte 0x616D0000
	.4byte 0x803DE808
	.4byte 0x00000000
	.4byte 0x802ABC08
	.4byte 0x802ABC1C
.global lbl_803DE820
lbl_803DE820:
	.4byte 0x00000000
.global lbl_803DE824
lbl_803DE824:
	.float 1.0
.global lbl_803DE828
lbl_803DE828:
	.float 1.0
.global lbl_803DE82C
lbl_803DE82C:
	.float 1.0
.global lbl_803DE830
lbl_803DE830:
	.4byte 0x00000000
.global lbl_803DE834
lbl_803DE834:
	.4byte 0x00000000
.global lbl_803DE838
lbl_803DE838:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DE83C
	.4byte 0x00000000
	.4byte 0x802AC880
	.4byte 0x802AC88C
.global __RTTI__9MovieInfo
__RTTI__9MovieInfo:
	.4byte 0x802AC874
	.4byte 0x802AC898
	.4byte 0
.global lbl_803DE860
lbl_803DE860:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DE868
	.4byte 0x00000000
	.4byte 0x802AC9D4
	.4byte 0x802AC9E0
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DE880
	.4byte 0x802ACA20
.global __RTTI__21MovSampleSetupSection
__RTTI__21MovSampleSetupSection:
	.4byte 0x802ACA08
	.4byte 0x802ACA34
	.4byte 0x53656374
	.4byte 0x696F6E00
	.4byte 0x803DE898
	.4byte 0x802ACA94
.global __RTTI__16MovSampleSection
__RTTI__16MovSampleSection:
	.4byte 0x802ACA80
	.4byte 0x802ACAB0
.global lbl_803DE8B0
lbl_803DE8B0:
	.4byte 0x00000000
.global lbl_803DE8B4
lbl_803DE8B4:
	.4byte 0x43C80000
.global lbl_803DE8B8
lbl_803DE8B8:
	.4byte 0x00000000
.global lbl_803DE8BC
lbl_803DE8BC:
	.4byte 0x00000000
.global lbl_803DE8C0
lbl_803DE8C0:
	.4byte 0x00000000
.global lbl_803DE8C4
lbl_803DE8C4:
	.4byte 0x00000000
.global lbl_803DE8C8
lbl_803DE8C8:
	.4byte 0x00000000
.global lbl_803DE8CC
lbl_803DE8CC:
	.4byte 0x00000000
.global __RTTI__Q215AttentionCamera5Fader
__RTTI__Q215AttentionCamera5Fader:
	.4byte 0x802ACB30
	.4byte 0
.global __RTTI__10ClothFader
__RTTI__10ClothFader:
	.4byte 0x802ACB24
	.4byte 0x802ACB48
.global __RTTI__11SimpleFader
__RTTI__11SimpleFader:
	.4byte 0x802ACB74
	.4byte 0x802ACB80
.global __RTTI__12DefaultFader
__RTTI__12DefaultFader:
	.4byte 0x802ACBAC
	.4byte 0x802ACBBC
.global lbl_803DE8F0
lbl_803DE8F0:
	.4byte 0x616C6976
	.4byte 0x65000000
.global lbl_803DE8F8
lbl_803DE8F8:
	.4byte 0x64656164
	.4byte 0x20000000
.global lbl_803DE900
lbl_803DE900:
	.4byte 0x00000000
.global lbl_803DE904
lbl_803DE904:
	.4byte 0x00000000
.global lbl_803DE908
lbl_803DE908:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DE90C
	.4byte 0x00000000
	.4byte 0x802ACC24
	.4byte 0x802ACC48
.global __RTTI__Q29RadarInfo9PartsInfo
__RTTI__Q29RadarInfo9PartsInfo:
	.4byte 0x802ACC30
	.4byte 0x802ACC54
	.4byte 0
.global lbl_803DE930
lbl_803DE930:
	.4byte 0x00000000
.global lbl_803DE934
lbl_803DE934:
	.4byte 0x00000000
.global lbl_803DE938
lbl_803DE938:
	.4byte 0x00000000
.global lbl_803DE93C
lbl_803DE93C:
	.4byte 0x00000000
.global lbl_803DE940
lbl_803DE940:
	.4byte 0x00000000
.global lbl_803DE944
lbl_803DE944:
	.4byte 0x00000000
	.4byte 0x802ACCCC
	.4byte 0x00000000
.global __RTTI__13InteractFlute
__RTTI__13InteractFlute:
	.4byte 0x802ACCBC
	.4byte 0x802ACCD8
.global __RTTI__13InteractPress
__RTTI__13InteractPress:
	.4byte 0x802ACD10
	.4byte 0x802ACD20
.global __RTTI__12InteractKill
__RTTI__12InteractKill:
	.4byte 0x802ACD58
	.4byte 0x802ACD68
.global __RTTI__15InteractSwallow
__RTTI__15InteractSwallow:
	.4byte 0x802ACDA0
	.4byte 0x802ACDB0
.global __RTTI__14InteractAttack
__RTTI__14InteractAttack:
	.4byte 0x802ACDE8
	.4byte 0x802ACDF8
.global __RTTI__19InteractSlimeAttack
__RTTI__19InteractSlimeAttack:
	.4byte 0x802ACE30
	.4byte 0x802ACE44
.global __RTTI__13InteractFlick
__RTTI__13InteractFlick:
	.4byte 0x802ACE7C
	.4byte 0x802ACE8C
.global __RTTI__12InteractWind
__RTTI__12InteractWind:
	.4byte 0x802ACEC4
	.4byte 0x802ACED4
.global __RTTI__12InteractFire
__RTTI__12InteractFire:
	.4byte 0x802ACF0C
	.4byte 0x802ACF1C
.global __RTTI__14InteractBubble
__RTTI__14InteractBubble:
	.4byte 0x802ACF54
	.4byte 0x802ACF64
.global __RTTI__13InteractSpore
__RTTI__13InteractSpore:
	.4byte 0x802ACFC8
	.4byte 0x802ACFD8
.global __RTTI__19InteractChangeHappa
__RTTI__19InteractChangeHappa:
	.4byte 0x802AD010
	.4byte 0x802AD024
.global __RTTI__19InteractChangeColor
__RTTI__19InteractChangeColor:
	.4byte 0x802AD05C
	.4byte 0x802AD070
.global __RTTI__17InteractThrowAway
__RTTI__17InteractThrowAway:
	.4byte 0x802AD0A8
	.4byte 0x802AD0BC
.global __RTTI__12InteractBury
__RTTI__12InteractBury:
	.4byte 0x802AD0F4
	.4byte 0x802AD104
.global lbl_803DE9C8
lbl_803DE9C8:
	.4byte 0x00000000
.global lbl_803DE9CC
lbl_803DE9CC:
	.4byte 0x00000000
.global lbl_803DE9D0
lbl_803DE9D0:
	.4byte 0x00000000
.global lbl_803DE9D4
lbl_803DE9D4:
	.4byte 0x41000000
.global lbl_803DE9D8
lbl_803DE9D8:
	.4byte 0x00000000
	.4byte 0x802AD174
	.4byte 0x00000000
.global __RTTI__15InteractRelease
__RTTI__15InteractRelease:
	.4byte 0x802AD164
	.4byte 0x802AD180
.global __RTTI__12InteractGrab
__RTTI__12InteractGrab:
	.4byte 0x802AD1B8
	.4byte 0x802AD1C8
	.4byte 0
	.4byte 0x802AD22C
	.4byte 0
.global __RTTI__12InteractWarn
__RTTI__12InteractWarn:
	.4byte 0x802AD21C
	.4byte 0x802AD238
.global __RTTI__12InteractTalk
__RTTI__12InteractTalk:
	.4byte 0x802AD270
	.4byte 0x802AD280
.global lbl_803DEA10
lbl_803DEA10:
	.4byte 0x00000000
.global lbl_803DEA14
lbl_803DEA14:
	.4byte 0x00000000
.global lbl_803DEA18
lbl_803DEA18:
	.4byte 0x00000000
.global lbl_803DEA1C
lbl_803DEA1C:
	.4byte 0x00000000
	.4byte 0x802AD2EC
	.4byte 0x00000000
.global __RTTI__15InteractPullout
__RTTI__15InteractPullout:
	.4byte 0x802AD2DC
	.4byte 0x802AD2F8
.global "__RTTI__22Receiver<10AICreature>"
"__RTTI__22Receiver<10AICreature>":
	.4byte 0x802AD35C
	.4byte 0
.global __RTTI__8SAIEvent
__RTTI__8SAIEvent:
	.4byte 0x802AD374
	.4byte 0x802AD380
.global __RTTI__12SAIUserEvent
__RTTI__12SAIUserEvent:
	.4byte 0x802AD34C
	.4byte 0x802AD38C
.global __RTTI__14SAIGroundEvent
__RTTI__14SAIGroundEvent:
	.4byte 0x802AD3D8
	.4byte 0x802AD3E8
.global __RTTI__15SAICollideEvent
__RTTI__15SAICollideEvent:
	.4byte 0x802AD434
	.4byte 0x802AD444
.global __RTTI__14SAIBounceEvent
__RTTI__14SAIBounceEvent:
	.4byte 0x802AD490
	.4byte 0x802AD4A0
.global __RTTI__21SAIMotionLoopEndEvent
__RTTI__21SAIMotionLoopEndEvent:
	.4byte 0x802AD4EC
	.4byte 0x802AD504
.global __RTTI__23SAIMotionLoopStartEvent
__RTTI__23SAIMotionLoopStartEvent:
	.4byte 0x802AD550
	.4byte 0x802AD568
.global __RTTI__21SAIMotionAction0Event
__RTTI__21SAIMotionAction0Event:
	.4byte 0x802AD5B4
	.4byte 0x802AD5CC
.global __RTTI__18SAIMotionDoneEvent
__RTTI__18SAIMotionDoneEvent:
	.4byte 0x802AD618
	.4byte 0x802AD62C
.global lbl_803DEA80
lbl_803DEA80:
	.4byte 0x00000000
.global lbl_803DEA84
lbl_803DEA84:
	.4byte 0x00000000
.global lbl_803DEA88
lbl_803DEA88:
	.4byte 0x00000000
.global lbl_803DEA8C
lbl_803DEA8C:
	.4byte 0x00000000
.global lbl_803DEA90
lbl_803DEA90:
	.float 1.0
.global lbl_803DEA94
lbl_803DEA94:
	.4byte 0x00000000
.global "__RTTI__22Receiver<10AICreature>_1"
"__RTTI__22Receiver<10AICreature>_1":
	.4byte 0x802AD7B0
	.4byte 0
.global "__RTTI__20AState<10AICreature>"
"__RTTI__20AState<10AICreature>":
	.4byte 0x802AD7C8
	.4byte 0x802AD7DC
.global __RTTI__8SAIState
__RTTI__8SAIState:
	.4byte 0x802AD7A4
	.4byte 0x802AD7E8
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DEAB0
	.4byte 0
	.4byte lbl_802AD740
	.4byte 0x802AD8E4
.global __RTTI__12SAICondition
__RTTI__12SAICondition:
	.4byte 0x802AD8D4
	.4byte 0x802AD8F0
.global __RTTI__8SAIArrow
__RTTI__8SAIArrow:
	.4byte lbl_802AD734
	.4byte 0x802AD918
.global "__RTTI__26StateMachine<10AICreature>"
"__RTTI__26StateMachine<10AICreature>":
	.4byte 0x802AD964
	.4byte 0
.global __RTTI__8SimpleAI
__RTTI__8SimpleAI:
	.4byte 0x802AD958
	.4byte 0x802AD980
	.4byte 0x802AD9C8
	.4byte 0
	.4byte 0x802AD9DC
	.4byte 0
	.4byte 0x802AD9E8
	.4byte 0
	.4byte 0x802AD9F8
	.4byte 0x802ADA04
	.4byte 0x802AD9BC
	.4byte 0x802ADA18
.global lbl_803DEB10
lbl_803DEB10:
	.4byte 0x6E6F6E61
	.4byte 0x6D650000
.global lbl_803DEB18
lbl_803DEB18:
	.4byte 0x00000000
.global lbl_803DEB1C
lbl_803DEB1C:
	.4byte 0x00000000
.global lbl_803DEB20
lbl_803DEB20:
	.float 1.0
.global lbl_803DEB24
lbl_803DEB24:
	.4byte 0x00000000
.global lbl_803DEB28
lbl_803DEB28:
	.4byte 0x00000000
.global lbl_803DEB2C
lbl_803DEB2C:
	.float 1.0
.global lbl_803DEB30
lbl_803DEB30:
	.float 1.0
.global lbl_803DEB34
lbl_803DEB34:
	.4byte 0x00000000
.global lbl_803DEB38
lbl_803DEB38:
	.4byte 0x00000000
.global lbl_803DEB3C
lbl_803DEB3C:
	.4byte 0x00000000
.global lbl_803DEB40
lbl_803DEB40:
	.float 1.0
.global lbl_803DEB44
lbl_803DEB44:
	.4byte 0x00000000
.global lbl_803DEB48
lbl_803DEB48:
	.4byte 0x3F000000
.global lbl_803DEB4C
lbl_803DEB4C:
	.float 1.0
.global lbl_803DEB50
lbl_803DEB50:
	.4byte 0x00000000
.global lbl_803DEB54
lbl_803DEB54:
	.4byte 0x00000000
.global lbl_803DEB58
lbl_803DEB58:
	.4byte 0x00000000
.global lbl_803DEB5C
lbl_803DEB5C:
	.float 1.0
.global lbl_803DEB60
lbl_803DEB60:
	.float 1.0
.global lbl_803DEB64
lbl_803DEB64:
	.float 1.0
.global lbl_803DEB68
lbl_803DEB68:
	.4byte 0x00000000
.global lbl_803DEB6C
lbl_803DEB6C:
	.float 1.0
.global lbl_803DEB70
lbl_803DEB70:
	.4byte 0x00000000
.global lbl_803DEB74
lbl_803DEB74:
	.4byte 0x00000000
.global lbl_803DEB78
lbl_803DEB78:
	.4byte 0x00000000
.global lbl_803DEB7C
lbl_803DEB7C:
	.4byte 0x00000000
.global lbl_803DEB80
lbl_803DEB80:
	.float 1.0
.global lbl_803DEB84
lbl_803DEB84:
	.4byte 0x00000000
.global lbl_803DEB88
lbl_803DEB88:
	.float 1.0
.global lbl_803DEB8C
lbl_803DEB8C:
	.4byte 0x00000000
.global lbl_803DEB90
lbl_803DEB90:
	.float 1.0
.global lbl_803DEB94
lbl_803DEB94:
	.float 1.0
.global lbl_803DEB98
lbl_803DEB98:
	.4byte 0x00000000
.global __RTTI__12FormArranger
__RTTI__12FormArranger:
	.4byte 0x802ADBD0
	.4byte 0
.global __RTTI__12WingArranger
__RTTI__12WingArranger:
	.4byte 0x802ADBC0
	.4byte 0x802ADBE0
.global __RTTI__12LineArranger
__RTTI__12LineArranger:
	.4byte 0x802ADBFC
	.4byte 0x802ADC0C
.global __RTTI__15PyramidArranger
__RTTI__15PyramidArranger:
	.4byte 0x802ADC28
	.4byte 0x802ADC38
.global __RTTI__14CircleArranger
__RTTI__14CircleArranger:
	.4byte 0x802ADC54
	.4byte 0x802ADC64
	.4byte 0x802ADC80
	.4byte 0
.global __RTTI__12FormationMgr
__RTTI__12FormationMgr:
	.4byte 0x802ADCA4
	.4byte 0x802ADCB4
	.4byte 0
.global totalUfoParts__11PlayerState
totalUfoParts__11PlayerState:
	.4byte 30
.global lbl_803DEBDC
lbl_803DEBDC:
	.4byte 0x00000000
.global lbl_803DEBE0
lbl_803DEBE0:
	.4byte 0x00000000
.global lbl_803DEBE4
lbl_803DEBE4:
	.4byte 0x00000000
.global lbl_803DEBE8
lbl_803DEBE8:
	.asciz "carry"
.balign 4
.global lbl_803DEBF0
lbl_803DEBF0:
	.asciz "assign"
.balign 4
.global lbl_803DEBF8
lbl_803DEBF8:
	.asciz "after"
.balign 4
.global lbl_803DEC00
lbl_803DEC00:
	.asciz "piston"
.balign 4
.global lbl_803DEC08
lbl_803DEC08:
	.asciz "special"
.balign 4
.global lbl_803DEC10
lbl_803DEC10:
	.asciz "6"
.balign 4
.global lbl_803DEC14
lbl_803DEC14:
	.4byte 0x00000000
.global lbl_803DEC18
lbl_803DEC18:
	.4byte 0x00000000
.global lbl_803DEC1C
lbl_803DEC1C:
	.4byte 0x00000000
.global lbl_803DEC20
lbl_803DEC20:
	.float 1.0
.global lbl_803DEC24
lbl_803DEC24:
	.float 1.0
.global lbl_803DEC28
lbl_803DEC28:
	.float 1.0
.global lbl_803DEC2C
lbl_803DEC2C:
	.4byte 0x00000000
.global lbl_803DEC30
lbl_803DEC30:
	.4byte 0x40490FDB
.global lbl_803DEC34
lbl_803DEC34:
	.4byte 0x00000000
.global lbl_803DEC38
lbl_803DEC38:
	.4byte 0x00000000
.global lbl_803DEC3C
lbl_803DEC3C:
	.4byte 0xC1200000
.global lbl_803DEC40
lbl_803DEC40:
	.4byte 0x00000000
.global lbl_803DEC44
lbl_803DEC44:
	.4byte 0x40000000
.global lbl_803DEC48
lbl_803DEC48:
	.4byte 0x00000000
.global lbl_803DEC4C
lbl_803DEC4C:
	.4byte 0x00000000
	.4byte 0x802ADDE8
	.4byte 0x00000000
.global __RTTI__Q211PlayerState8UfoParts
__RTTI__Q211PlayerState8UfoParts:
	.4byte 0x802ADDD0
	.4byte 0x802ADDFC
.global lbl_803DEC60
lbl_803DEC60:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DEC68
lbl_803DEC68:
	.4byte 0x7061726D
	.4byte 0x732F0000
.global lbl_803DEC70
lbl_803DEC70:
	.4byte 0x70303000
.global lbl_803DEC74
lbl_803DEC74:
	.4byte 0x70303100
.global lbl_803DEC78
lbl_803DEC78:
	.4byte 0x70303200
.global lbl_803DEC7C
lbl_803DEC7C:
	.4byte 0x70303300
.global lbl_803DEC80
lbl_803DEC80:
	.4byte 0x70303400
.global lbl_803DEC84
lbl_803DEC84:
	.4byte 0x3135204E
	.4byte 0x554B4900
.global lbl_803DEC8C
lbl_803DEC8C:
	.4byte 0x00000000
.global lbl_803DEC90
lbl_803DEC90:
	.4byte 0x00000000
.global lbl_803DEC94
lbl_803DEC94:
	.4byte 0x00000000
.global lbl_803DEC98
lbl_803DEC98:
	.4byte 0x00000000
.global lbl_803DEC9C
lbl_803DEC9C:
	.4byte 0x802AE0D0
	.4byte 0x00000000
.global lbl_803DECA4
lbl_803DECA4:
	.asciz "ANode"
.balign 4
.global lbl_803DECAC
lbl_803DECAC:
	.4byte 0x803DECA4
	.4byte 0x00000000
.global lbl_803DECB4
lbl_803DECB4:
	.4byte 0x802AE108
	.4byte 0x802AE114
.global lbl_803DECBC
lbl_803DECBC:
	.asciz "Node"
.balign 4
.global lbl_803DECC4
lbl_803DECC4:
	.4byte 0x803DECBC
	.4byte 0x802AE120
.global __RTTI__9DemoParms
__RTTI__9DemoParms:
	.4byte 0x802AE0FC
	.4byte 0x802AE134
	.4byte 0
.global lbl_803DECD8
lbl_803DECD8:
	.asciz "OFF"
.balign 4
.global lbl_803DECDC
lbl_803DECDC:
	.asciz "ON"
.balign 4
.global lbl_803DECE0
lbl_803DECE0:
	.asciz "SEEN"
.balign 4
.global lbl_803DECE8
lbl_803DECE8:
	.asciz "<Node>"
.balign 4
.global lbl_803DECF0
lbl_803DECF0:
	.4byte 0x70303000
.global lbl_803DECF4
lbl_803DECF4:
	.4byte 0x70303100
.global lbl_803DECF8
lbl_803DECF8:
	.4byte 0x70303200
.global lbl_803DECFC
lbl_803DECFC:
	.4byte 0x70303300
.global lbl_803DED00
lbl_803DED00:
	.4byte 0x70303400
.global lbl_803DED04
lbl_803DED04:
	.4byte 0x70303500
.global lbl_803DED08
lbl_803DED08:
	.4byte 0x70303700
.global lbl_803DED0C
lbl_803DED0C:
	.4byte 0x70303600
.global lbl_803DED10
lbl_803DED10:
	.4byte 0x70303800
.global lbl_803DED14
lbl_803DED14:
	.4byte 0x70303900
.global lbl_803DED18
lbl_803DED18:
	.4byte 0x70313000
.global lbl_803DED1C
lbl_803DED1C:
	.4byte 0x70313100
.global lbl_803DED20
lbl_803DED20:
	.4byte 0x70313200
.global lbl_803DED24
lbl_803DED24:
	.4byte 0x70313300
.global lbl_803DED28
lbl_803DED28:
	.4byte 0x70313400
.global lbl_803DED2C
lbl_803DED2C:
	.4byte 0x70313500
.global lbl_803DED30
lbl_803DED30:
	.4byte 0x70313600
.global lbl_803DED34
lbl_803DED34:
	.4byte 0x70313700
.global lbl_803DED38
lbl_803DED38:
	.4byte 0x70313800
.global lbl_803DED3C
lbl_803DED3C:
	.4byte 0x70313900
.global lbl_803DED40
lbl_803DED40:
	.4byte 0x70323000
.global lbl_803DED44
lbl_803DED44:
	.4byte 0x70323100
.global lbl_803DED48
lbl_803DED48:
	.4byte 0x70323200
.global lbl_803DED4C
lbl_803DED4C:
	.4byte 0x7061726D
	.4byte 0x732F0000
	.4byte 0x802AE6E8
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DED5C
	.4byte 0x00000000
	.4byte 0x802AE74C
	.4byte 0x802AE758
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DED74
	.4byte 0x802AE764
.global __RTTI__10AIConstant
__RTTI__10AIConstant:
	.4byte 0x802AE740
	.4byte 0x802AE778
	.4byte 0
.global lbl_803DED90
lbl_803DED90:
	.4byte 0x6B696F2E
	.4byte 0x63707000
.global kontMode__3KIO
kontMode__3KIO:
	.4byte 0x00000002
	.4byte 0x00000000
.global lbl_803DEDA0
lbl_803DEDA0:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DEDA8
lbl_803DEDA8:
	.4byte 0x938A82B0
	.4byte 0x00000000
.global lbl_803DEDB0
lbl_803DEDB0:
	.4byte 0x94B282AB
	.4byte 0x00000000
.global lbl_803DEDB8
lbl_803DEDB8:
	.4byte 0x89F08E55
	.4byte 0x00000000
.global lbl_803DEDC0
lbl_803DEDC0:
	.4byte 0x7061726D
	.4byte 0x732F0000
.global lbl_803DEDC8
lbl_803DEDC8:
	.4byte 0x6B65792E
	.4byte 0x62696E00
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DEDD0
	.4byte 0x00000000
	.4byte 0x802AE834
	.4byte 0x802AE840
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DEDE8
	.4byte 0x802AE84C
.global __RTTI__Q29KeyConfig3Key
__RTTI__Q29KeyConfig3Key:
	.4byte 0x802AE824
	.4byte 0x802AE860
.global __RTTI__9KeyConfig
__RTTI__9KeyConfig:
	.4byte 0x802AE8AC
	.4byte 0x802AE8B8
.global useLOD__6AIPerf
useLOD__6AIPerf:
	.byte 0x1
.global showColls__6AIPerf
showColls__6AIPerf:
	.byte 0x1
.global useCollSort__6AIPerf
useCollSort__6AIPerf:
	.byte 0x1
.global bridgeFast__6AIPerf
bridgeFast__6AIPerf:
	.byte 0x1
.global useASync__6AIPerf
useASync__6AIPerf:
	.4byte 0x01000000
.global useGrid__6AIPerf
useGrid__6AIPerf:
	.4byte 0x00000002
.global gridShift__6AIPerf
gridShift__6AIPerf:
	.4byte 0x00000004
.global aiGrid__6AIPerf
aiGrid__6AIPerf:
	.byte 0x1
.global insQuick__6AIPerf
insQuick__6AIPerf:
	.byte 0x1
.global iteratorCull__6AIPerf
iteratorCull__6AIPerf:
	.byte 0x1
.global pikiMabiki__6AIPerf
pikiMabiki__6AIPerf:
	.byte 0x1
.global optLevel__6AIPerf
optLevel__6AIPerf:
	.4byte 2
.global lbl_803DEE20
lbl_803DEE20:
	.asciz "stop"
.balign 4
.global lbl_803DEE28
lbl_803DEE28:
	.asciz "no stop"
.balign 4
.global lbl_803DEE30
lbl_803DEE30:
	.asciz "slip"
.balign 4
.global lbl_803DEE38
lbl_803DEE38:
	.asciz "%s"
.balign 4
.global "__RTTI__18IDelegate1<R4Menu>_4"
"__RTTI__18IDelegate1<R4Menu>_4":
	.4byte 0x802AEDCC
	.4byte 0
.global "__RTTI__25Delegate1<6AIPerf,R4Menu>"
"__RTTI__25Delegate1<6AIPerf,R4Menu>":
	.4byte 0x802AEDB0
	.4byte 0x802AEDE0
	.4byte 0
.global lbl_803DEE50
lbl_803DEE50:
	.4byte 0x70303000
.global lbl_803DEE54
lbl_803DEE54:
	.4byte 0x70303100
.global lbl_803DEE58
lbl_803DEE58:
	.4byte 0x70303200
.global lbl_803DEE5C
lbl_803DEE5C:
	.4byte 0x70303300
	.4byte 0x802AEE80
	.4byte 0x00000000
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803DEE68
	.4byte 0x802AEE8C
	.4byte 0x802AEE98
	.4byte 0x802AEEA4
.global __RTTI__14GenObjectDebug
__RTTI__14GenObjectDebug:
	.4byte 0x802AEE70
	.4byte 0x802AEEB8
	.4byte 0x802AEF18
	.4byte 0
.global lbl_803DEE90
lbl_803DEE90:
	.4byte 0x6D656D69
	.4byte 0x6E666F00
	.4byte 0x4D656D49
	.4byte 0x6E666F00
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DEEA0
	.4byte 0x00000000
	.4byte 0x802AEF60
	.4byte 0x802AEF6C
.global __RTTI__11MemInfoNode
__RTTI__11MemInfoNode:
	.4byte 0x802AEF78
	.4byte 0x802AEF84
.global __RTTI__7MemInfo
__RTTI__7MemInfo:
	.4byte 0x803DEE98
	.4byte 0x802AEF98
	.4byte 0x54554245
	.4byte 0
.global lbl_803DEED0
lbl_803DEED0:
	.4byte 0xBF800000
.global lbl_803DEED4
lbl_803DEED4:
	.4byte 0xBF800000
.global lbl_803DEED8
lbl_803DEED8:
	.4byte 0x00000000
.global lbl_803DEEDC
lbl_803DEEDC:
	.4byte 0x00000000
.global lbl_803DEEE0
lbl_803DEEE0:
	.4byte 0x00000000
.global lbl_803DEEE4
lbl_803DEEE4:
	.4byte 0x3EC90FDB
.global lbl_803DEEE8
lbl_803DEEE8:
	.4byte 0x00000000
.global lbl_803DEEEC
lbl_803DEEEC:
	.4byte 0x00000000
.global lbl_803DEEF0
lbl_803DEEF0:
	.4byte 0x00000000
.global lbl_803DEEF4
lbl_803DEEF4:
	.4byte 0x00000000
.global lbl_803DEEF8
lbl_803DEEF8:
	.4byte 0x00000000
.global lbl_803DEEFC
lbl_803DEEFC:
	.4byte 0x00000000
.global lbl_803DEF00
lbl_803DEF00:
	.4byte 0x00000000
.global lbl_803DEF04
lbl_803DEF04:
	.4byte 0x00000000
.global lbl_803DEF08
lbl_803DEF08:
	.4byte 0x00000000
.global lbl_803DEF0C
lbl_803DEF0C:
	.4byte 0x00000000
.global lbl_803DEF10
lbl_803DEF10:
	.4byte 0x00000000
.global lbl_803DEF14
lbl_803DEF14:
	.4byte 0x00000000
.global lbl_803DEF18
lbl_803DEF18:
	.4byte 0x00000000
.global lbl_803DEF1C
lbl_803DEF1C:
	.4byte 0x00000000
.global lbl_803DEF20
lbl_803DEF20:
	.4byte 0x00000000
.global lbl_803DEF24
lbl_803DEF24:
	.4byte 0x00000000
.global lbl_803DEF28
lbl_803DEF28:
	.4byte 0x00000000
.global lbl_803DEF2C
lbl_803DEF2C:
	.4byte 0x00000000
.global lbl_803DEF30
lbl_803DEF30:
	.4byte 0x00000000
.global lbl_803DEF34
lbl_803DEF34:
	.4byte 0x00000000
.global lbl_803DEF38
lbl_803DEF38:
	.4byte 0x00000000
.global lbl_803DEF3C
lbl_803DEF3C:
	.4byte 0x00000000
.global lbl_803DEF40
lbl_803DEF40:
	.4byte 0x00000000
.global lbl_803DEF44
lbl_803DEF44:
	.float 1.0
.global lbl_803DEF48
lbl_803DEF48:
	.float 1.0
.global lbl_803DEF4C
lbl_803DEF4C:
	.float 1.0
.global lbl_803DEF50
lbl_803DEF50:
	.4byte 0x00000000
.global lbl_803DEF54
lbl_803DEF54:
	.4byte 0x00000000
.global lbl_803DEF58
lbl_803DEF58:
	.4byte 0x00000000
.global lbl_803DEF5C
lbl_803DEF5C:
	.4byte 0x00000000
.global lbl_803DEF60
lbl_803DEF60:
	.4byte 0x00000000
.global lbl_803DEF64
lbl_803DEF64:
	.4byte 0x00000000
.global lbl_803DEF68
lbl_803DEF68:
	.4byte 0x00000000
.global lbl_803DEF6C
lbl_803DEF6C:
	.4byte 0x00000000
.global lbl_803DEF70
lbl_803DEF70:
	.4byte 0x00000000
.global lbl_803DEF74
lbl_803DEF74:
	.4byte 0x00000000
.global lbl_803DEF78
lbl_803DEF78:
	.4byte 0x3DCCCCCD
.global lbl_803DEF7C
lbl_803DEF7C:
	.4byte 0x00000000
.global lbl_803DEF80
lbl_803DEF80:
	.float 1.0
.global lbl_803DEF84
lbl_803DEF84:
	.4byte 0x00000000
.global lbl_803DEF88
lbl_803DEF88:
	.4byte 0x00000000
.global lbl_803DEF8C
lbl_803DEF8C:
	.4byte 0x00000000
.global lbl_803DEF90
lbl_803DEF90:
	.4byte 0x00000000
.global lbl_803DEF94
lbl_803DEF94:
	.4byte 0x00000000
.global lbl_803DEF98
lbl_803DEF98:
	.4byte 0x00000000
.global lbl_803DEF9C
lbl_803DEF9C:
	.4byte 0x00000000
.global lbl_803DEFA0
lbl_803DEFA0:
	.float 1.0
.global lbl_803DEFA4
lbl_803DEFA4:
	.4byte 0x00000000
.global lbl_803DEFA8
lbl_803DEFA8:
	.4byte 0x00000000
.global lbl_803DEFAC
lbl_803DEFAC:
	.float 1.0
.global lbl_803DEFB0
lbl_803DEFB0:
	.float 1.0
.global lbl_803DEFB4
lbl_803DEFB4:
	.float 1.0
.global lbl_803DEFB8
lbl_803DEFB8:
	.4byte 0x00000000
.global lbl_803DEFBC
lbl_803DEFBC:
	.4byte 0x00000000
.global lbl_803DEFC0
lbl_803DEFC0:
	.4byte 0x00000000
.global lbl_803DEFC4
lbl_803DEFC4:
	.4byte 0x00000000
.global lbl_803DEFC8
lbl_803DEFC8:
	.4byte 0x00000000
.global lbl_803DEFCC
lbl_803DEFCC:
	.4byte 0x00000000
.global lbl_803DEFD0
lbl_803DEFD0:
	.4byte 0x00000000
.global lbl_803DEFD4
lbl_803DEFD4:
	.4byte 0x00000000
.global lbl_803DEFD8
lbl_803DEFD8:
	.4byte 0x00000000
.global lbl_803DEFDC
lbl_803DEFDC:
	.4byte 0x00000000
.global lbl_803DEFE0
lbl_803DEFE0:
	.float 1.0
.global lbl_803DEFE4
lbl_803DEFE4:
	.float 1.0
.global lbl_803DEFE8
lbl_803DEFE8:
	.float 1.0
.global lbl_803DEFEC
lbl_803DEFEC:
	.float 1.0
.global lbl_803DEFF0
lbl_803DEFF0:
	.float 1.0
.global lbl_803DEFF4
lbl_803DEFF4:
	.float 1.0
.global lbl_803DEFF8
lbl_803DEFF8:
	.4byte 0x00000000
.global lbl_803DEFFC
lbl_803DEFFC:
	.4byte 0x00000000
.global lbl_803DF000
lbl_803DF000:
	.4byte 0x00000000
.global lbl_803DF004
lbl_803DF004:
	.4byte 0x00000000
.global lbl_803DF008
lbl_803DF008:
	.4byte 0x00000000
.global lbl_803DF00C
lbl_803DF00C:
	.4byte 0x00000000
.global lbl_803DF010
lbl_803DF010:
	.float 1.0
.global lbl_803DF014
lbl_803DF014:
	.float 1.0
.global lbl_803DF018
lbl_803DF018:
	.float 1.0
.global lbl_803DF01C
lbl_803DF01C:
	.4byte 0x00000000
.global lbl_803DF020
lbl_803DF020:
	.4byte 0x00000000
.global lbl_803DF024
lbl_803DF024:
	.4byte 0x00000000
.global lbl_803DF028
lbl_803DF028:
	.4byte 0x00000000
.global lbl_803DF02C
lbl_803DF02C:
	.4byte 0x00000000
	.4byte 0x802AF08C
	.4byte 0x00000000
	.4byte 0x802AF0A4
	.4byte 0x00000000
	.4byte 0x802AF0B0
	.4byte 0x00000000
	.4byte 0x802AF080
	.4byte 0x802AF0C0
.global lbl_803DF050
lbl_803DF050:
	.4byte 0x00000000
.global lbl_803DF054
lbl_803DF054:
	.4byte 0xBF800000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DF058
	.4byte 0x00000000
	.4byte 0x802AF228
	.4byte 0x802AF234
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DF070
	.4byte 0x802AF240
	.4byte 0x802AF254
	.4byte 0x802AF264
.global __RTTI__12DynCollShape_1
__RTTI__12DynCollShape_1:
	.4byte 0x802AF280
	.4byte 0x802AF290
.global __RTTI__16CreatureCollPart
__RTTI__16CreatureCollPart:
	.4byte 0x802AF214
	.4byte 0x802AF2B4
.global lbl_803DF098
lbl_803DF098:
	.4byte 0x47000000
.global lbl_803DF09C
lbl_803DF09C:
	.4byte 0x47000000
.global lbl_803DF0A0
lbl_803DF0A0:
	.4byte 0x47000000
.global lbl_803DF0A4
lbl_803DF0A4:
	.4byte 0xC7000000
.global lbl_803DF0A8
lbl_803DF0A8:
	.4byte 0xC7000000
.global lbl_803DF0AC
lbl_803DF0AC:
	.4byte 0xC7000000
.global lbl_803DF0B0
lbl_803DF0B0:
	.4byte 0x00000000
.global lbl_803DF0B4
lbl_803DF0B4:
	.4byte 0x00000000
.global lbl_803DF0B8
lbl_803DF0B8:
	.4byte 0x00000000
.global lbl_803DF0BC
lbl_803DF0BC:
	.4byte 0x00000000
.global lbl_803DF0C0
lbl_803DF0C0:
	.4byte 0x00000000
.global lbl_803DF0C4
lbl_803DF0C4:
	.4byte 0x00000000
.global lbl_803DF0C8
lbl_803DF0C8:
	.4byte 0x00000000
.global lbl_803DF0CC
lbl_803DF0CC:
	.4byte 0x00000000
.global lbl_803DF0D0
lbl_803DF0D0:
	.4byte 0x00000000
.global lbl_803DF0D4
lbl_803DF0D4:
	.4byte 0x00000000
.global lbl_803DF0D8
lbl_803DF0D8:
	.4byte 0x00000000
.global lbl_803DF0DC
lbl_803DF0DC:
	.float 1.0
.global lbl_803DF0E0
lbl_803DF0E0:
	.float 1.0
.global lbl_803DF0E4
lbl_803DF0E4:
	.float 1.0
.global lbl_803DF0E8
lbl_803DF0E8:
	.4byte 0xBF800000
	.4byte 0x47524F55
	.4byte 0x4E440000
	.4byte 0x504C4154
	.4byte 0x00000000
	.4byte 0x41495200
.global lbl_803DF100
lbl_803DF100:
	.4byte 0xBF800000
.global lbl_803DF104
lbl_803DF104:
	.4byte 0x00000000
.global lbl_803DF108
lbl_803DF108:
	.4byte 0x00000000
.global lbl_803DF10C
lbl_803DF10C:
	.4byte 0x00000000
.global lbl_803DF110
lbl_803DF110:
	.4byte 0x00000000
.global lbl_803DF114
lbl_803DF114:
	.4byte 0x00000000
.global lbl_803DF118
lbl_803DF118:
	.4byte 0x00000000
.global lbl_803DF11C
lbl_803DF11C:
	.4byte 0x00000000
.global lbl_803DF120
lbl_803DF120:
	.4byte 0x00000000
.global lbl_803DF124
lbl_803DF124:
	.4byte 0x00000000
.global lbl_803DF128
lbl_803DF128:
	.4byte 0x00000000
.global lbl_803DF12C
lbl_803DF12C:
	.4byte 0x00000000
.global lbl_803DF130
lbl_803DF130:
	.4byte 0x00000000
.global lbl_803DF134
lbl_803DF134:
	.4byte 0x00000000
.global lbl_803DF138
lbl_803DF138:
	.4byte 0x00000000
.global lbl_803DF13C
lbl_803DF13C:
	.4byte 0x00000000
.global lbl_803DF140
lbl_803DF140:
	.4byte 0x00000000
.global lbl_803DF144
lbl_803DF144:
	.4byte 0x00000000
.global lbl_803DF148
lbl_803DF148:
	.4byte 0xBF800000
.global lbl_803DF14C
lbl_803DF14C:
	.4byte 0x00000000
.global lbl_803DF150
lbl_803DF150:
	.4byte 0xBF800000
	.4byte 0x802AF384
	.4byte 0x00000000
.global __RTTI__8Stickers
__RTTI__8Stickers:
	.4byte 0x802AF378
	.4byte 0x802AF390
	.4byte 0
.global lbl_803DF168
lbl_803DF168:
	.4byte 0x00000000
.global lbl_803DF16C
lbl_803DF16C:
	.4byte 0x00000000
.global lbl_803DF170
lbl_803DF170:
	.4byte 0x00000000
.global lbl_803DF174
lbl_803DF174:
	.4byte 0x00000000
.global lbl_803DF178
lbl_803DF178:
	.4byte 0x00000000
.global lbl_803DF17C
lbl_803DF17C:
	.4byte 0x00000000
.global lbl_803DF180
lbl_803DF180:
	.4byte 0x00000000
.global lbl_803DF184
lbl_803DF184:
	.4byte 0x00000000
.global lbl_803DF188
lbl_803DF188:
	.4byte 0x00000000
.global lbl_803DF18C
lbl_803DF18C:
	.4byte 0x00000000
.global lbl_803DF190
lbl_803DF190:
	.4byte 0x00000000
.global lbl_803DF194
lbl_803DF194:
	.4byte 0x00000000
.global lbl_803DF198
lbl_803DF198:
	.4byte 0x00000000
.global lbl_803DF19C
lbl_803DF19C:
	.4byte 0x00000000
.global lbl_803DF1A0
lbl_803DF1A0:
	.4byte 0x00000000
.global lbl_803DF1A4
lbl_803DF1A4:
	.4byte 0x00000000
.global lbl_803DF1A8
lbl_803DF1A8:
	.4byte 0x3EA0D97C
.global lbl_803DF1AC
lbl_803DF1AC:
	.4byte 0x00000000
.global lbl_803DF1B0
lbl_803DF1B0:
	.4byte 0x00000000
.global lbl_803DF1B4
lbl_803DF1B4:
	.4byte 0x00000000
.global lbl_803DF1B8
lbl_803DF1B8:
	.4byte 0x00000000
	.4byte 0x802AF428
	.4byte 0x00000000
	.4byte 0x802AF434
	.4byte 0x00000000
	.4byte 0x802AF444
	.4byte 0x802AF450
	.4byte 0x802AF464
	.4byte 0x802AF470
.global __RTTI__12DualCreature
__RTTI__12DualCreature:
	.4byte 0x802AF48C
	.4byte 0x802AF49C
.global __RTTI__11PelCreature
__RTTI__11PelCreature:
	.4byte 0x802AF41C
	.4byte 0x802AF4C0
	.4byte 0
.global lbl_803DF1F0
lbl_803DF1F0:
	.4byte 0x00000000
.global lbl_803DF1F4
lbl_803DF1F4:
	.4byte 0x00000000
.global lbl_803DF1F8
lbl_803DF1F8:
	.4byte 0x00000000
.global lbl_803DF1FC
lbl_803DF1FC:
	.4byte 0x73303000
.global lbl_803DF200
lbl_803DF200:
	.4byte 0x73303100
.global lbl_803DF204
lbl_803DF204:
	.4byte 0x73303200
.global lbl_803DF208
lbl_803DF208:
	.4byte 0x73303300
.global lbl_803DF20C
lbl_803DF20C:
	.4byte 0x73303400
.global lbl_803DF210
lbl_803DF210:
	.4byte 0x00000000
.global lbl_803DF214
lbl_803DF214:
	.4byte 0x00000000
.global lbl_803DF218
lbl_803DF218:
	.4byte 0x00000000
.global lbl_803DF21C
lbl_803DF21C:
	.4byte 0x00000000
.global lbl_803DF220
lbl_803DF220:
	.4byte 0x00000000
.global lbl_803DF224
lbl_803DF224:
	.4byte 0x00000000
.global lbl_803DF228
lbl_803DF228:
	.4byte 0x00000000
.global lbl_803DF22C
lbl_803DF22C:
	.4byte 0x00000000
.global lbl_803DF230
lbl_803DF230:
	.4byte 0x00000000
.global lbl_803DF234
lbl_803DF234:
	.4byte 0x00000000
.global lbl_803DF238
lbl_803DF238:
	.4byte 0x00000000
.global lbl_803DF23C
lbl_803DF23C:
	.4byte 0x00000000
.global lbl_803DF240
lbl_803DF240:
	.4byte 0x00000000
.global lbl_803DF244
lbl_803DF244:
	.4byte 0x00000000
.global lbl_803DF248
lbl_803DF248:
	.4byte 0x00000000
.global lbl_803DF24C
lbl_803DF24C:
	.4byte 0x00000000
.global lbl_803DF250
lbl_803DF250:
	.4byte 0x00000000
.global lbl_803DF254
lbl_803DF254:
	.4byte 0x00000000
.global lbl_803DF258
lbl_803DF258:
	.4byte 0x00000000
.global lbl_803DF25C
lbl_803DF25C:
	.4byte 0x00000000
.global lbl_803DF260
lbl_803DF260:
	.4byte 0x00000000
.global lbl_803DF264
lbl_803DF264:
	.float 1.0
.global lbl_803DF268
lbl_803DF268:
	.float 1.0
.global lbl_803DF26C
lbl_803DF26C:
	.float 1.0
.global lbl_803DF270
lbl_803DF270:
	.4byte 0x00000000
.global lbl_803DF274
lbl_803DF274:
	.float 1.0
.global lbl_803DF278
lbl_803DF278:
	.4byte 0x00000000
.global lbl_803DF27C
lbl_803DF27C:
	.4byte 0x00000000
.global lbl_803DF280
lbl_803DF280:
	.float 1.0
.global lbl_803DF284
lbl_803DF284:
	.4byte 0x00000000
.global lbl_803DF288
lbl_803DF288:
	.4byte 0xBE99999A
.global lbl_803DF28C
lbl_803DF28C:
	.float 1.0
.global lbl_803DF290
lbl_803DF290:
	.float 1.0
.global lbl_803DF294
lbl_803DF294:
	.float 1.0
.global lbl_803DF298
lbl_803DF298:
	.4byte 0x00000000
.global lbl_803DF29C
lbl_803DF29C:
	.4byte 0x00000000
.global lbl_803DF2A0
lbl_803DF2A0:
	.4byte 0x00000000
	.4byte 0x802AF784
	.4byte 0x00000000
	.4byte 0x802AF790
	.4byte 0x00000000
	.4byte 0x802AF7A0
	.4byte 0x802AF7AC
	.4byte 0x802AF778
	.4byte 0x802AF7C0
	.4byte 0x802AF8FC
	.4byte 0x00000000
	.4byte 0x802AF928
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DF2D4
	.4byte 0x00000000
	.4byte 0x802AF740
	.4byte 0x802AF950
.global __RTTI__11DynParticle
__RTTI__11DynParticle:
	.4byte 0x802AF944
	.4byte 0x802AF95C
	.4byte 0
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DF2F8
	.4byte 0
	.4byte lbl_802AF9D4
	.4byte 0x802AFA00
.global __RTTI__13EventListener
__RTTI__13EventListener:
	.4byte 0x802AF9F0
	.4byte 0x802AFA0C
.global aiGridShift__8FastGrid
aiGridShift__8FastGrid:
	.4byte 0x000C0000
.global lbl_803DF31C
lbl_803DF31C:
	.4byte 0x61694772
	.4byte 0x69640000
	.4byte 0x00000000
	.4byte 0x802AFA84
	.4byte 0x00000000
	.4byte 0x802AFA90
	.4byte 0x00000000
	.4byte 0x802AFAA0
	.4byte 0x802AFAAC
	.4byte 0x802AFA74
	.4byte 0x802AFAC0
	.4byte 0x70696B69
	.4byte 0x00000000
	.4byte 0x74656B69
	.4byte 0x00000000
	.4byte 0x6E617669
	.4byte 0x00000000
	.4byte 0x77617465
	.4byte 0x72000000
	.4byte 0x73656564
	.4byte 0x00000000
	.4byte 0x6B657900
	.4byte 0x646F6F72
	.4byte 0x00000000
	.4byte 0x67617465
	.4byte 0x00000000
	.4byte 0x67656D35
	.4byte 0x00000000
	.4byte 0x67656D31
	.4byte 0x30000000
	.4byte 0x67656D32
	.4byte 0x30000000
	.4byte 0x67656D35
	.4byte 0x30000000
	.4byte 0x67656D31
	.4byte 0x00000000
	.4byte 0x626F6D62
	.4byte 0x00000000
	.4byte 0x676F616C
	.4byte 0x00000000
	.4byte 0x66756C63
	.4byte 0x72756D00
	.4byte 0x726F7065
	.4byte 0x00000000
	.4byte 0x69767900
	.4byte 0x726F636B
	.4byte 0x65740000
	.4byte 0x6B757361
	.4byte 0x00000000
	.4byte 0x75666F00
	.4byte 0x77656564
	.4byte 0x73000000
	.4byte 0x3C776565
	.4byte 0x643E0000
	.4byte 0x726F636B
	.4byte 0x67656E00
	.4byte 0x66697368
	.4byte 0x00000000
	.4byte 0x73656372
	.4byte 0x65743100
	.4byte 0x504C414E
	.4byte 0x54000000
	.4byte 0x50454C4C
	.4byte 0x45540000
	.4byte 0x00000000
.global lbl_803DF420
lbl_803DF420:
	.float 1.0
.global lbl_803DF424
lbl_803DF424:
	.float 1.0
.global lbl_803DF428
lbl_803DF428:
	.float 1.0
.global lbl_803DF42C
lbl_803DF42C:
	.4byte 0x78393900
.global lbl_803DF430
lbl_803DF430:
	.4byte 0x6E657700
.global lbl_803DF434
lbl_803DF434:
	.4byte 0x70303000
.global lbl_803DF438
lbl_803DF438:
	.4byte 0x70303900
.global lbl_803DF43C
lbl_803DF43C:
	.4byte 0x70303100
.global lbl_803DF440
lbl_803DF440:
	.4byte 0x70303200
.global lbl_803DF444
lbl_803DF444:
	.4byte 0x70303300
.global lbl_803DF448
lbl_803DF448:
	.4byte 0x70303400
.global lbl_803DF44C
lbl_803DF44C:
	.4byte 0x70303500
.global lbl_803DF450
lbl_803DF450:
	.4byte 0x70303800
.global lbl_803DF454
lbl_803DF454:
	.4byte 0x70303600
.global lbl_803DF458
lbl_803DF458:
	.4byte 0x70303700
.global lbl_803DF45C
lbl_803DF45C:
	.4byte 0x70313000
.global lbl_803DF460
lbl_803DF460:
	.4byte 0x70313100
.global lbl_803DF464
lbl_803DF464:
	.4byte 0x70313200
.global lbl_803DF468
lbl_803DF468:
	.4byte 0x70313300
.global lbl_803DF46C
lbl_803DF46C:
	.4byte 0x00000000
.global lbl_803DF470
lbl_803DF470:
	.4byte 0x00000000
.global lbl_803DF474
lbl_803DF474:
	.4byte 0x00000000
.global lbl_803DF478
lbl_803DF478:
	.4byte 0x00000000
.global lbl_803DF47C
lbl_803DF47C:
	.4byte 0x00000000
.global lbl_803DF480
lbl_803DF480:
	.4byte 0x00000000
.global lbl_803DF484
lbl_803DF484:
	.4byte 0x00000000
.global lbl_803DF488
lbl_803DF488:
	.4byte 0x00000000
.global lbl_803DF48C
lbl_803DF48C:
	.4byte 0x00000000
.global lbl_803DF490
lbl_803DF490:
	.4byte 0x00000000
.global lbl_803DF494
lbl_803DF494:
	.4byte 0x00000000
.global lbl_803DF498
lbl_803DF498:
	.4byte 0x00000000
.global lbl_803DF49C
lbl_803DF49C:
	.4byte 0x00000000
.global lbl_803DF4A0
lbl_803DF4A0:
	.4byte 0x00000000
.global lbl_803DF4A4
lbl_803DF4A4:
	.4byte 0x00000000
.global lbl_803DF4A8
lbl_803DF4A8:
	.4byte 0x00000000
.global lbl_803DF4AC
lbl_803DF4AC:
	.4byte 0x00000000
.global lbl_803DF4B0
lbl_803DF4B0:
	.4byte 0x00000000
.global lbl_803DF4B4
lbl_803DF4B4:
	.4byte 0x00000000
.global lbl_803DF4B8
lbl_803DF4B8:
	.4byte 0x00000000
.global lbl_803DF4BC
lbl_803DF4BC:
	.4byte 0x00000000
.global lbl_803DF4C0
lbl_803DF4C0:
	.4byte 0x00000000
.global lbl_803DF4C4
lbl_803DF4C4:
	.4byte 0x00000000
.global lbl_803DF4C8
lbl_803DF4C8:
	.4byte 0x00000000
.global lbl_803DF4CC
lbl_803DF4CC:
	.4byte 0x00000000
.global lbl_803DF4D0
lbl_803DF4D0:
	.4byte 0x00000000
.global lbl_803DF4D4
lbl_803DF4D4:
	.4byte 0x00000000
.global lbl_803DF4D8
lbl_803DF4D8:
	.4byte 0x00000000
.global lbl_803DF4DC
lbl_803DF4DC:
	.4byte 0x00000000
.global lbl_803DF4E0
lbl_803DF4E0:
	.4byte 0x00000000
.global lbl_803DF4E4
lbl_803DF4E4:
	.4byte 0x00000000
.global lbl_803DF4E8
lbl_803DF4E8:
	.4byte 0x3F000000
.global lbl_803DF4EC
lbl_803DF4EC:
	.4byte 0x00000000
.global lbl_803DF4F0
lbl_803DF4F0:
	.4byte 0x00000000
.global lbl_803DF4F4
lbl_803DF4F4:
	.4byte 0x00000000
.global lbl_803DF4F8
lbl_803DF4F8:
	.4byte 0x00000000
.global lbl_803DF4FC
lbl_803DF4FC:
	.4byte 0x00000000
.global lbl_803DF500
lbl_803DF500:
	.4byte 0x00000000
.global lbl_803DF504
lbl_803DF504:
	.4byte 0x00000000
.global lbl_803DF508
lbl_803DF508:
	.4byte 0x00000000
.global lbl_803DF50C
lbl_803DF50C:
	.4byte 0x00000000
.global lbl_803DF510
lbl_803DF510:
	.4byte 0x00000000
.global lbl_803DF514
lbl_803DF514:
	.4byte 0x00000000
.global lbl_803DF518
lbl_803DF518:
	.4byte 0x00000000
.global lbl_803DF51C
lbl_803DF51C:
	.4byte 0x00000000
.global lbl_803DF520
lbl_803DF520:
	.4byte 0x40000000
.global lbl_803DF524
lbl_803DF524:
	.4byte 0x00000000
.global lbl_803DF528
lbl_803DF528:
	.float 1.0
.global lbl_803DF52C
lbl_803DF52C:
	.4byte 0x00000000
.global lbl_803DF530
lbl_803DF530:
	.4byte 0x00000000
.global lbl_803DF534
lbl_803DF534:
	.4byte 0x00000000
.global lbl_803DF538
lbl_803DF538:
	.4byte 0x00000000
.global lbl_803DF53C
lbl_803DF53C:
	.4byte 0x00000000
.global lbl_803DF540
lbl_803DF540:
	.4byte 0x00000000
.global lbl_803DF544
lbl_803DF544:
	.4byte 0x00000000
.global lbl_803DF548
lbl_803DF548:
	.4byte 0x00000000
.global lbl_803DF54C
lbl_803DF54C:
	.4byte 0x00000000
.global lbl_803DF550
lbl_803DF550:
	.4byte 0x7573654E
	.4byte 0x6F646500
.global lbl_803DF558
lbl_803DF558:
	.4byte 0x00000000
.global lbl_803DF55C
lbl_803DF55C:
	.4byte 0x73303000
.global lbl_803DF560
lbl_803DF560:
	.4byte 0x73303100
.global lbl_803DF564
lbl_803DF564:
	.4byte 0x73303200
.global lbl_803DF568
lbl_803DF568:
	.4byte 0x73303300
.global lbl_803DF56C
lbl_803DF56C:
	.4byte 0x73303400
.global lbl_803DF570
lbl_803DF570:
	.4byte 0x7061726D
	.4byte 0x732F0000
.global lbl_803DF578
lbl_803DF578:
	.4byte 0x66726F6E
	.4byte 0x74000000
.global lbl_803DF580
lbl_803DF580:
	.4byte 0x6261636B
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DF588
	.4byte 0x00000000
	.4byte 0x802AFFA4
	.4byte 0x802B00BC
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DF5A0
	.4byte 0x802B00C8
	.4byte 0x802B00DC
	.4byte 0x00000000
	.4byte 0x802B00E8
	.4byte 0x802B00F4
	.4byte 0x802B0118
	.4byte 0x802B0128
.global __RTTI__9PelletMgr
__RTTI__9PelletMgr:
	.4byte 0x802B00B0
	.4byte 0x802B0154
	.4byte 0x802B021C
	.4byte 0
.global __RTTI__10PelletProp
__RTTI__10PelletProp:
	.4byte 0x802B0210
	.4byte 0x802B022C
.global __RTTI__Q29PelletMgr7UseNode
__RTTI__Q29PelletMgr7UseNode:
	.4byte 0x802B0250
	.4byte 0x802B0264
	.4byte 0x50656C6C
	.4byte 0x65740000
	.4byte 0x802B02C0
	.4byte 0
	.4byte 0x802B02D4
	.4byte 0
	.4byte 0x802B02E0
	.4byte 0
	.4byte 0x802B02F0
	.4byte 0x802B02FC
	.4byte 0x802B0310
	.4byte 0x802B031C
.global __RTTI__12DualCreature_1
__RTTI__12DualCreature_1:
	.4byte 0x802B0338
	.4byte 0x802B0348
.global __RTTI__6Pellet
__RTTI__6Pellet:
	.4byte 0x803DF5E8
	.4byte 0x802B036C
.global "__RTTI__21StateMachine<6Pellet>"
"__RTTI__21StateMachine<6Pellet>":
	.4byte 0x802B04D0
	.4byte 0
	.4byte 0x4B456666
	.4byte 0x65637400
	.4byte 0x802B0500
	.4byte 0
	.4byte 0x802B0524
	.4byte 0
	.4byte 0x802B0564
	.4byte 0
.global __RTTI__7KEffect
__RTTI__7KEffect:
	.4byte 0x803DF630
	.4byte 0x802B0590
	.4byte 0x802B0628
	.4byte 0
.global __RTTI__12PelletConfig
__RTTI__12PelletConfig:
	.4byte 0x802B0618
	.4byte 0x802B0634
	.4byte 0x802B0678
	.4byte 0
.global lbl_803DF670
lbl_803DF670:
	.4byte 0x78303000
.global lbl_803DF674
lbl_803DF674:
	.4byte 0x70656C6C
	.4byte 0x65747300
.global lbl_803DF67C
lbl_803DF67C:
	.4byte 0x78303100
.global lbl_803DF680
lbl_803DF680:
	.4byte 0x6E6F6E61
	.4byte 0x6D650000
.global lbl_803DF688
lbl_803DF688:
	.4byte 0x25732E62
	.4byte 0x696E0000
	.4byte 0x43617272
	.4byte 0x79000000
	.4byte 0x41707065
	.4byte 0x61720000
	.4byte 0x33000000
	.4byte 0x34000000
	.4byte 0x35000000
	.4byte 0x36000000
	.4byte 0x37000000
	.4byte 0x802B07D4
	.4byte 0x00000000
	.4byte 0x802B07E0
	.4byte 0x802B07F0
.global __RTTI__18PaniPelletAnimator
__RTTI__18PaniPelletAnimator:
	.4byte 0x802B07C0
	.4byte 0x802B07FC
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DF6CC
	.4byte 0
	.4byte lbl_802B0764
	.4byte 0x802B083C
	.4byte 0x802B0848
	.4byte 0
.global __RTTI__14PelletAnimInfo
__RTTI__14PelletAnimInfo:
	.4byte 0x802B082C
	.4byte 0x802B0854
	.4byte 0x802B089C
	.4byte 0
	.4byte 0
	.4byte 0x802B0930
	.4byte 0
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803DF708
	.4byte 0x802B093C
	.4byte 0x802B0948
	.4byte 0x802B0954
.global __RTTI__15GenObjectPellet
__RTTI__15GenObjectPellet:
	.4byte 0x802B0920
	.4byte 0x802B0968
.global lbl_803DF728
lbl_803DF728:
	.4byte 0x55464F4C
	.4byte 0x4F414400
.global lbl_803DF730
lbl_803DF730:
	.4byte 0x44454144
	.4byte 0x00000000
.global lbl_803DF738
lbl_803DF738:
	.4byte 0x4E4F524D
	.4byte 0x414C0000
.global lbl_803DF740
lbl_803DF740:
	.4byte 0x41505045
	.4byte 0x41520000
.global lbl_803DF748
lbl_803DF748:
	.4byte 0x474F414C
	.4byte 0x00000000
.global lbl_803DF750
lbl_803DF750:
	.4byte 0x42C80000
.global lbl_803DF754
lbl_803DF754:
	.4byte 0x43480000
.global lbl_803DF758
lbl_803DF758:
	.4byte 0x41200000
.global "__RTTI__17Receiver<6Pellet>"
"__RTTI__17Receiver<6Pellet>":
	.4byte 0x802B09F8
	.4byte 0
.global "__RTTI__15AState<6Pellet>"
"__RTTI__15AState<6Pellet>":
	.4byte 0x802B0A0C
	.4byte 0x802B0A1C
.global __RTTI__11PelletState
__RTTI__11PelletState:
	.4byte 0x802B0A28
	.4byte 0x802B0A34
.global __RTTI__15PelletGoalState
__RTTI__15PelletGoalState:
	.4byte 0x802B09E8
	.4byte 0x802B0A48
.global __RTTI__17PelletAppearState
__RTTI__17PelletAppearState:
	.4byte 0x802B0AB4
	.4byte 0x802B0AC8
.global __RTTI__20PelletSwallowedState
__RTTI__20PelletSwallowedState:
	.4byte 0x802B0B34
	.4byte 0x802B0B4C
.global __RTTI__17PelletNormalState
__RTTI__17PelletNormalState:
	.4byte 0x802B0BB8
	.4byte 0x802B0BCC
.global __RTTI__15PelletDeadState
__RTTI__15PelletDeadState:
	.4byte 0x802B0C38
	.4byte 0x802B0C48
.global __RTTI__18PelletUfoLoadState
__RTTI__18PelletUfoLoadState:
	.4byte 0x802B0CB4
	.4byte 0x802B0CC8
.global "__RTTI__21StateMachine<6Pellet>_1"
"__RTTI__21StateMachine<6Pellet>_1":
	.4byte 0x802B0E20
	.4byte 0
.global __RTTI__18PelletStateMachine
__RTTI__18PelletStateMachine:
	.4byte 0x802B0E0C
	.4byte 0x802B0E38
	.4byte 0
	.4byte 0x2E2E2E00
	.4byte 0x6D65636B
	.4byte 0
.global lbl_803DF7C4
lbl_803DF7C4:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DF7CC
lbl_803DF7CC:
	.4byte 0x776F0000
.global lbl_803DF7D0
lbl_803DF7D0:
	.4byte 0x00000000
.global lbl_803DF7D4
lbl_803DF7D4:
	.4byte 0x00000000
.global lbl_803DF7D8
lbl_803DF7D8:
	.4byte 0x00000000
.global lbl_803DF7DC
lbl_803DF7DC:
	.4byte 0x70303000
.global lbl_803DF7E0
lbl_803DF7E0:
	.4byte 0x70303100
.global lbl_803DF7E4
lbl_803DF7E4:
	.4byte 0x70303200
.global lbl_803DF7E8
lbl_803DF7E8:
	.4byte 0x70303300
.global lbl_803DF7EC
lbl_803DF7EC:
	.float 1.0
.global lbl_803DF7F0
lbl_803DF7F0:
	.float 1.0
.global lbl_803DF7F4
lbl_803DF7F4:
	.float 1.0
.global lbl_803DF7F8
lbl_803DF7F8:
	.4byte 0xBF800000
.global lbl_803DF7FC
lbl_803DF7FC:
	.4byte 0xBF800000
.global lbl_803DF800
lbl_803DF800:
	.4byte 0x3F000000
.global lbl_803DF804
lbl_803DF804:
	.4byte 0x3DC49BA6
.global lbl_803DF808
lbl_803DF808:
	.4byte 0x3DC49BA6
.global lbl_803DF80C
lbl_803DF80C:
	.float 1.0
.global lbl_803DF810
lbl_803DF810:
	.float 1.0
.global lbl_803DF814
lbl_803DF814:
	.float 1.0
.global lbl_803DF818
lbl_803DF818:
	.4byte 0x00000000
.global lbl_803DF81C
lbl_803DF81C:
	.4byte 0x00000000
.global lbl_803DF820
lbl_803DF820:
	.float 1.0
.global lbl_803DF824
lbl_803DF824:
	.float 1.0
.global lbl_803DF828
lbl_803DF828:
	.float 1.0
.global lbl_803DF82C
lbl_803DF82C:
	.float 1.0
.global lbl_803DF830
lbl_803DF830:
	.float 1.0
.global lbl_803DF834
lbl_803DF834:
	.float 1.0
.global lbl_803DF838
lbl_803DF838:
	.4byte 0x40A00000
.global lbl_803DF83C
lbl_803DF83C:
	.4byte 0x40A00000
.global lbl_803DF840
lbl_803DF840:
	.4byte 0x00000000
.global lbl_803DF844
lbl_803DF844:
	.4byte 0x00000000
.global lbl_803DF848
lbl_803DF848:
	.4byte 0x41A00000
.global lbl_803DF84C
lbl_803DF84C:
	.4byte 0x41A00000
.global lbl_803DF850
lbl_803DF850:
	.4byte 0x40A00000
	.4byte 0x802B1078
	.4byte 0x00000000
.global __RTTI__13InteractBreak
__RTTI__13InteractBreak:
	.4byte 0x802B1068
	.4byte 0x802B1084
.global __RTTI__13InteractBuild
__RTTI__13InteractBuild:
	.4byte 0x802B10BC
	.4byte 0x802B10CC
	.4byte 0x42726964
	.4byte 0x67650000
	.4byte 0x802B1104
	.4byte 0
	.4byte 0x802B1118
	.4byte 0
	.4byte 0x802B1124
	.4byte 0
	.4byte 0x802B1134
	.4byte 0x802B1140
	.4byte 0x802B1154
	.4byte 0x802B1160
	.4byte 0x802B1184
	.4byte 0x802B1194
.global __RTTI__10WorkObject
__RTTI__10WorkObject:
	.4byte 0x802B11C0
	.4byte 0x802B11CC
.global __RTTI__6Bridge
__RTTI__6Bridge:
	.4byte 0x803DF86C
	.4byte 0x802B1200
.global __RTTI__12InteractPush
__RTTI__12InteractPush:
	.4byte 0x802B13A8
	.4byte 0x802B13B8
.global __RTTI__10HinderRock
__RTTI__10HinderRock:
	.4byte 0x802B13F0
	.4byte 0x802B13FC
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DF8C4
	.4byte 0
	.4byte lbl_802B1024
	.4byte 0x802B15B4
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803DF8DC
	.4byte 0x802B15C0
	.4byte 0x802B15A4
	.4byte 0x802B15D4
.global __RTTI__12DynCollShape_2
__RTTI__12DynCollShape_2:
	.4byte 0x802B1640
	.4byte 0x802B1650
.global __RTTI__13DynBuildShape
__RTTI__13DynBuildShape:
	.4byte 0x802B1630
	.4byte 0x802B1674
	.4byte 0x802B16FC
	.4byte 0
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803DF90C
	.4byte 0x802B1708
	.4byte 0x802B1714
	.4byte 0x802B1720
.global __RTTI__19GenObjectWorkObject
__RTTI__19GenObjectWorkObject:
	.4byte 0x802B16E8
	.4byte 0x802B1734
	.4byte 0x802B1794
	.4byte 0
	.4byte 0x802B17FC
	.4byte 0
	.4byte 0x802B1808
	.4byte 0x802B1814
.global __RTTI__13WorkObjectMgr
__RTTI__13WorkObjectMgr:
	.4byte 0x802B17EC
	.4byte 0x802B1838
.global __RTTI__14WorkObjectNode
__RTTI__14WorkObjectNode:
	.4byte 0x802B18DC
	.4byte 0x802B18EC
	.4byte 0
.global avoidWayPointIndex__10PathFinder
avoidWayPointIndex__10PathFinder:
	.4byte 0xFFFFFFFF
.global lbl_803DF95C
lbl_803DF95C:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DF964
lbl_803DF964:
	.4byte 0x25640000
.global lbl_803DF968
lbl_803DF968:
	.4byte 0x25643A25
	.4byte 0x64000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DF970
	.4byte 0x00000000
	.4byte 0x802B1ACC
	.4byte 0x802B1AD8
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DF988
	.4byte 0x802B1B0C
.global __RTTI__8RouteMgr
__RTTI__8RouteMgr:
	.4byte 0x802B1B00
	.4byte 0x802B1B20
.global lbl_803DF9A0
lbl_803DF9A0:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803DF9A8
lbl_803DF9A8:
	.4byte 0x42726561
	.4byte 0x6B757000
.global lbl_803DF9B0
lbl_803DF9B0:
	.4byte 0x47617468
	.4byte 0x65720000
.global lbl_803DF9B8
lbl_803DF9B8:
	.4byte 0x5468726F
	.4byte 0x77000000
.global lbl_803DF9C0
lbl_803DF9C0:
	.4byte 0x53452025
	.4byte 0x64000000
.global lbl_803DF9C8
lbl_803DF9C8:
	.4byte 0x25730000
	.4byte 0x53655769
	.4byte 0x6E000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DF9D4
	.4byte 0x00000000
	.4byte 0x802B1C04
	.4byte 0x802B1C10
	.4byte 0x476D5769
	.4byte 0x6E000000
.global __RTTI__5GmWin
__RTTI__5GmWin:
	.4byte 0x803DF9EC
	.4byte 0x802B1C1C
.global __RTTI__5SeWin
__RTTI__5SeWin:
	.4byte 0x803DF9CC
	.4byte 0x802B1C30
	.4byte 0x53654D67
	.4byte 0x72000000
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803DFA0C
	.4byte 0x802B1C94
.global __RTTI__5SeMgr
__RTTI__5SeMgr:
	.4byte 0x803DFA04
	.4byte 0x802B1CA8
.balign 8
.global lbl_803DFA28
lbl_803DFA28:
	.asciz "<Node>"
.balign 4
.global lbl_803DFA30
lbl_803DFA30:
	.asciz "p00"
.balign 4
.global lbl_803DFA34
lbl_803DFA34:
	.asciz "p01"
.balign 4
.global lbl_803DFA38
lbl_803DFA38:
	.asciz "p02"
.balign 4
.global lbl_803DFA3C
lbl_803DFA3C:
	.asciz "parms/"
.balign 4
	.4byte 0x802B1D44
	.4byte 0x00000000
.balign 4
	.asciz "ANode"
.balign 4
	.4byte 0x803DFA4C
	.4byte 0x00000000
	.4byte 0x802B1D7C
	.4byte 0x802B1D88
.balign 4
	.asciz "Node"
.balign 4
	.4byte 0x803DFA64
	.4byte 0x802B1D94
.global __RTTI__10SeConstant
__RTTI__10SeConstant:
	.4byte 0x802B1D70
	.4byte 0x802B1DA8
.balign 8
.global lbl_803DFA80
lbl_803DFA80:
	.asciz "SE_BOMB"
.balign 4
	.asciz "dummy 1"
.balign 4
	.asciz "dummy 2"
.balign 4
	.asciz "dummy 3"
.balign 4
	.asciz "dummy 4"
.balign 4
	.asciz "dummy 5"
.balign 4
.global lbl_803DFAB0
lbl_803DFAB0:
	.float 0.0
.global lbl_803DFAB4
lbl_803DFAB4:
	.float 0.0
.global lbl_803DFAB8
lbl_803DFAB8:
	.float 0.0
.global lbl_803DFABC
lbl_803DFABC:
	.float 0.0
.global lbl_803DFAC0
lbl_803DFAC0:
	.float 0.0
.global lbl_803DFAC4
lbl_803DFAC4:
	.float 0.0
.global lbl_803DFAC8
lbl_803DFAC8:
	.float 0.0
.global lbl_803DFACC
lbl_803DFACC:
	.float 0.0
.global lbl_803DFAD0
lbl_803DFAD0:
	.float 0.0
.global lbl_803DFAD4
lbl_803DFAD4:
	.float 0.0
.global lbl_803DFAD8
lbl_803DFAD8:
	.float 0.0
.global lbl_803DFADC
lbl_803DFADC:
	.float 0.0
.global lbl_803DFAE0
lbl_803DFAE0:
	.float 0.0
.global lbl_803DFAE4
lbl_803DFAE4:
	.float 0.0
.global lbl_803DFAE8
lbl_803DFAE8:
	.float 0.0
.global lbl_803DFAEC
lbl_803DFAEC:
	.float 0.0
.global lbl_803DFAF0
lbl_803DFAF0:
	.float 0.0
.global lbl_803DFAF4
lbl_803DFAF4:
	.float 0.0
.balign 4
.global lbl_803DFAF8
lbl_803DFAF8:
	.asciz "SE %d"
.balign 4
.global lbl_803DFB00
lbl_803DFB00:
	.asciz "-----"
.balign 4
.global lbl_803DFB08
lbl_803DFB08:
	.asciz "battle"
.balign 4
.global lbl_803DFB10
lbl_803DFB10:
	.asciz "pellet"
.balign 4
.global lbl_803DFB18
lbl_803DFB18:
	.asciz "onyon"
.balign 4
.global lbl_803DFB20
lbl_803DFB20:
	.asciz "build"
.balign 4
.global lbl_803DFB28
lbl_803DFB28:
	.asciz "water"
.balign 4
.global lbl_803DFB30
lbl_803DFB30:
	.asciz "free"
.balign 4
.global lbl_803DFB38
lbl_803DFB38:
	.asciz "????"
.balign 4
.global lbl_803DFB40
lbl_803DFB40:
	.asciz "DAME"
.balign 4
.global lbl_803DFB48
lbl_803DFB48:
	.asciz "<pos>"
.balign 4
.global lbl_803DFB50
lbl_803DFB50:
	.4byte 0x00000000
.global lbl_803DFB54
lbl_803DFB54:
	.4byte 0x00000000
.global lbl_803DFB58
lbl_803DFB58:
	.4byte 0x00000000
.global lbl_803DFB5C
lbl_803DFB5C:
	.4byte 0x00000000
.global lbl_803DFB60
lbl_803DFB60:
	.4byte 0x00000000
.global lbl_803DFB64
lbl_803DFB64:
	.4byte 0x00000000
.global lbl_803DFB68
lbl_803DFB68:
	.asciz "<Node>"
.balign 4
.global lbl_803DFB70
lbl_803DFB70:
	.4byte 0x70303000
.global lbl_803DFB74
lbl_803DFB74:
	.4byte 0x70303100
.global lbl_803DFB78
lbl_803DFB78:
	.4byte 0x70303200
.global lbl_803DFB7C
lbl_803DFB7C:
	.asciz "parms/"
.balign 4
.global lbl_803DFB84
lbl_803DFB84:
	.4byte 0x00000000
.global lbl_803DFB88
lbl_803DFB88:
	.4byte 0x00000000
.global lbl_803DFB8C
lbl_803DFB8C:
	.4byte 0x00000000
.global lbl_803DFB90
lbl_803DFB90:
	.4byte 0x00000000
.global lbl_803DFB94
lbl_803DFB94:
	.float 1.0
.global lbl_803DFB98
lbl_803DFB98:
	.float 1.0
.global lbl_803DFB9C
lbl_803DFB9C:
	.float 1.0
.global lbl_803DFBA0
lbl_803DFBA0:
	.4byte 0x00000000
.global lbl_803DFBA4
lbl_803DFBA4:
	.4byte 0x00000000
.global lbl_803DFBA8
lbl_803DFBA8:
	.4byte 0x00000000
.global lbl_803DFBAC
lbl_803DFBAC:
	.4byte 0x00000000
.global lbl_803DFBB0
lbl_803DFBB0:
	.4byte 0x00000000
.global lbl_803DFBB4
lbl_803DFBB4:
	.4byte 0x00000000
.global lbl_803DFBB8
lbl_803DFBB8:
	.4byte 0x00000000
.global lbl_803DFBBC
lbl_803DFBBC:
	.4byte 0x00000000
.global lbl_803DFBC0
lbl_803DFBC0:
	.4byte 0x00000000
.global lbl_803DFBC4
lbl_803DFBC4:
	.4byte 0x00000000
.global lbl_803DFBC8
lbl_803DFBC8:
	.4byte 0x00000000
.global lbl_803DFBCC
lbl_803DFBCC:
	.4byte 0x00000000
.global lbl_803DFBD0
lbl_803DFBD0:
	.4byte 0x00000000
.global lbl_803DFBD4
lbl_803DFBD4:
	.4byte 0x00000000
.global lbl_803DFBD8
lbl_803DFBD8:
	.4byte 0x00000000
.global lbl_803DFBDC
lbl_803DFBDC:
	.4byte 0x00000000
.global lbl_803DFBE0
lbl_803DFBE0:
	.4byte 0x40800000
.global lbl_803DFBE4
lbl_803DFBE4:
	.4byte 0x00000000
	.4byte 0x43506C61
	.4byte 0x74650000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DFBF0
	.4byte 0x00000000
	.4byte 0x802B4E48
	.4byte 0x802B4E54
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803DFC08
	.4byte 0x802B4E60
	.4byte 0x802B4E74
	.4byte 0x00000000
.global __RTTI__6CPlate
__RTTI__6CPlate:
	.4byte 0x803DFBE8
	.4byte 0x802B4E80
	.4byte 0x802B4F04
	.4byte 0
.global lbl_803DFC30
lbl_803DFC30:
	.4byte 0x00000000
.global lbl_803DFC34
lbl_803DFC34:
	.4byte 0x00000000
.global lbl_803DFC38
lbl_803DFC38:
	.4byte 0x00000000
.global lbl_803DFC3C
lbl_803DFC3C:
	.4byte 0x00000000
.global lbl_803DFC40
lbl_803DFC40:
	.4byte 0x00000000
.global lbl_803DFC44
lbl_803DFC44:
	.4byte 0x00000000
.global lbl_803DFC48
lbl_803DFC48:
	.4byte 0x00000000
.global lbl_803DFC4C
lbl_803DFC4C:
	.4byte 0x00000000
.global lbl_803DFC50
lbl_803DFC50:
	.4byte 0x00000000
.global lbl_803DFC54
lbl_803DFC54:
	.4byte 0x00000000
.global lbl_803DFC58
lbl_803DFC58:
	.4byte 0x00000000
.global lbl_803DFC5C
lbl_803DFC5C:
	.4byte 0x00000000
.global lbl_803DFC60
lbl_803DFC60:
	.4byte 0x00000000
.global lbl_803DFC64
lbl_803DFC64:
	.4byte 0x40A00000
	.4byte 0x802B4F80
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803DFC70
	.4byte 0x802B4F90
.global __RTTI__8ActStone
__RTTI__8ActStone:
	.4byte 0x802B4F74
	.4byte 0x802B4F9C
.global lbl_803DFC88
lbl_803DFC88:
	.4byte 0x2D000000
	.4byte 0x00000000
.global lbl_803DFC90
lbl_803DFC90:
	.4byte 0x00000000
.global lbl_803DFC94
lbl_803DFC94:
	.4byte 0x00000000
.global lbl_803DFC98
lbl_803DFC98:
	.4byte 0x00000000
.global lbl_803DFC9C
lbl_803DFC9C:
	.4byte 0x00000000
.global lbl_803DFCA0
lbl_803DFCA0:
	.4byte 0x00000000
.global lbl_803DFCA4
lbl_803DFCA4:
	.4byte 0x00000000
.global lbl_803DFCA8
lbl_803DFCA8:
	.4byte 0x00000000
.global lbl_803DFCAC
lbl_803DFCAC:
	.4byte 0x00000000
	.4byte 0x802B5098
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803DFCB8
	.4byte 0x802B50A8
.global __RTTI__9ActAdjust
__RTTI__9ActAdjust:
	.4byte 0x802B508C
	.4byte 0x802B50B4
	.4byte 0x802B5144
	.4byte 0
.global __RTTI__Q29ActAdjust11Initialiser
__RTTI__Q29ActAdjust11Initialiser:
	.4byte 0x802B512C
	.4byte 0x802B5158
	.4byte 0x41637450
	.4byte 0x75740000
.global __RTTI__6ActPut
__RTTI__6ActPut:
	.4byte 0x803DFCE0
	.4byte 0x802B5170
.global __RTTI__Q26ActPut11Initialiser
__RTTI__Q26ActPut11Initialiser:
	.4byte 0x802B51E8
	.4byte 0x802B51FC
	.4byte 0x41637450
	.4byte 0x69636B00
	.4byte 0x802B524C
	.4byte 0
.global __RTTI__7ActPick
__RTTI__7ActPick:
	.4byte 0x803DFCF8
	.4byte 0x802B5260
.global __RTTI__Q27ActPick11Initialiser
__RTTI__Q27ActPick11Initialiser:
	.4byte 0x802B52F0
	.4byte 0x802B5308
.global lbl_803DFD18
lbl_803DFD18:
	.4byte 0x61747461
	.4byte 0x636B0000
.global lbl_803DFD20
lbl_803DFD20:
	.4byte 0x00000000
.global lbl_803DFD24
lbl_803DFD24:
	.4byte 0x00000000
.global lbl_803DFD28
lbl_803DFD28:
	.4byte 0x00000000
.global lbl_803DFD2C
lbl_803DFD2C:
	.4byte 0xBF800000
.global lbl_803DFD30
lbl_803DFD30:
	.4byte 0x00000000
.global lbl_803DFD34
lbl_803DFD34:
	.4byte 0x00000000
.global lbl_803DFD38
lbl_803DFD38:
	.4byte 0x00000000
.global lbl_803DFD3C
lbl_803DFD3C:
	.4byte 0x00000000
.global lbl_803DFD40
lbl_803DFD40:
	.4byte 0x00000000
.global lbl_803DFD44
lbl_803DFD44:
	.4byte 0x00000000
.global lbl_803DFD48
lbl_803DFD48:
	.4byte 0x00000000
.global lbl_803DFD4C
lbl_803DFD4C:
	.4byte 0x00000000
.global lbl_803DFD50
lbl_803DFD50:
	.4byte 0x00000000
.global lbl_803DFD54
lbl_803DFD54:
	.4byte 0x00000000
.global lbl_803DFD58
lbl_803DFD58:
	.4byte 0x00000000
.global lbl_803DFD5C
lbl_803DFD5C:
	.4byte 0x00000000
.global lbl_803DFD60
lbl_803DFD60:
	.4byte 0x00000000
.global lbl_803DFD64
lbl_803DFD64:
	.4byte 0x00000000
.global lbl_803DFD68
lbl_803DFD68:
	.4byte 0x00000000
.global lbl_803DFD6C
lbl_803DFD6C:
	.4byte 0x00000000
.global lbl_803DFD70
lbl_803DFD70:
	.4byte 0x00000000
.global lbl_803DFD74
lbl_803DFD74:
	.4byte 0x00000000
.global lbl_803DFD78
lbl_803DFD78:
	.4byte 0x00000000
.global lbl_803DFD7C
lbl_803DFD7C:
	.4byte 0x00000000
.global lbl_803DFD80
lbl_803DFD80:
	.4byte 0x00000000
.global lbl_803DFD84
lbl_803DFD84:
	.4byte 0x00000000
.global lbl_803DFD88
lbl_803DFD88:
	.float 1.0
.global lbl_803DFD8C
lbl_803DFD8C:
	.4byte 0x00000000
.global lbl_803DFD90
lbl_803DFD90:
	.4byte 0x41A00000
	.4byte 0x802B53D8
	.4byte 0x00000000
	.4byte 0x802B53EC
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803DFDA4
	.4byte 0x802B53FC
.global __RTTI__13ActJumpAttack
__RTTI__13ActJumpAttack:
	.4byte 0x802B53C8
	.4byte 0x802B5408
	.4byte 0x802B54A4
	.4byte 0x802B54B0
.global __RTTI__9ActAttack
__RTTI__9ActAttack:
	.4byte 0x802B5498
	.4byte 0x802B54C4
	.4byte 0
.global lbl_803DFDD0
lbl_803DFDD0:
	.4byte 0x00000000
.global lbl_803DFDD4
lbl_803DFDD4:
	.4byte 0x00000000
.global lbl_803DFDD8
lbl_803DFDD8:
	.4byte 0x00000000
.global lbl_803DFDDC
lbl_803DFDDC:
	.4byte 0x626F7265
	.4byte 0x00000000
.global lbl_803DFDE4
lbl_803DFDE4:
	.4byte 0x00000000
.global lbl_803DFDE8
lbl_803DFDE8:
	.4byte 0x00000000
.global lbl_803DFDEC
lbl_803DFDEC:
	.4byte 0x00000000
	.4byte 0x802B55BC
	.4byte 0x00000000
	.4byte 0x802B55D0
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803DFE00
	.4byte 0x802B55E0
.global __RTTI__11ActBoreRest
__RTTI__11ActBoreRest:
	.4byte 0x802B55B0
	.4byte 0x802B55EC
.global __RTTI__14ActBoreOneshot
__RTTI__14ActBoreOneshot:
	.4byte 0x802B567C
	.4byte 0x802B568C
.global __RTTI__13ActBoreListen
__RTTI__13ActBoreListen:
	.4byte 0x802B571C
	.4byte 0x802B572C
.global __RTTI__11ActBoreTalk
__RTTI__11ActBoreTalk:
	.4byte 0x802B57DC
	.4byte 0x802B57E8
.global __RTTI__13ActBoreSelect
__RTTI__13ActBoreSelect:
	.4byte 0x802B5884
	.4byte 0x802B5894
.global __RTTI__13ActFreeSelect
__RTTI__13ActFreeSelect:
	.4byte 0x802B590C
	.4byte 0x802B591C
	.4byte 0x802B5A20
	.4byte 0
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803DFE48
	.4byte 0x802B5A30
.global __RTTI__9ActBoMake
__RTTI__9ActBoMake:
	.4byte 0x802B5A14
	.4byte 0x802B5A3C
.global lbl_803DFE60
lbl_803DFE60:
	.4byte 0x426F7500
.global lbl_803DFE64
lbl_803DFE64:
	.4byte 0x00000000
.global lbl_803DFE68
lbl_803DFE68:
	.4byte 0x00000000
.global lbl_803DFE6C
lbl_803DFE6C:
	.4byte 0x00000000
.global lbl_803DFE70
lbl_803DFE70:
	.4byte 0x00000000
.global lbl_803DFE74
lbl_803DFE74:
	.4byte 0x00000000
.global lbl_803DFE78
lbl_803DFE78:
	.4byte 0x00000000
.global lbl_803DFE7C
lbl_803DFE7C:
	.4byte 0x43160000
	.4byte 0x41637442
	.4byte 0x6F750000
	.4byte 0x802B5B1C
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803DFE90
	.4byte 0x802B5B2C
.global __RTTI__6ActBou
__RTTI__6ActBou:
	.4byte 0x803DFE80
	.4byte 0x802B5B38
.global lbl_803DFEA8
lbl_803DFEA8:
	.asciz "Bridge"
.balign 4
.global lbl_803DFEB0
lbl_803DFEB0:
	.asciz "detour"
.balign 4
.global lbl_803DFEB8
lbl_803DFEB8:
	.asciz "go"
.balign 4
.global lbl_803DFEBC
lbl_803DFEBC:
	.asciz "work"
.balign 4
.global lbl_803DFEC4
lbl_803DFEC4:
	.4byte 0x00000000
.global lbl_803DFEC8
lbl_803DFEC8:
	.4byte 0x00000000
.global lbl_803DFECC
lbl_803DFECC:
	.4byte 0x00000000
	.4byte 0x802B5C4C
	.4byte 0x00000000
	.4byte 0x802B5C60
	.4byte 0x00000000
	.asciz "Action"
.balign 4
	.4byte 0x803DFEE0
	.4byte lbl_802B5C70
.global __RTTI__9ActBridge
__RTTI__9ActBridge:
	.4byte 0x802B5C40
	.4byte lbl_802B5C7C
.global lbl_803DFEF8
lbl_803DFEF8:
	.4byte 0x00000000
.global lbl_803DFEFC
lbl_803DFEFC:
	.4byte 0x00000000
.global lbl_803DFF00
lbl_803DFF00:
	.4byte 0x00000000
.global lbl_803DFF04
lbl_803DFF04:
	.4byte 0x00000000
.global lbl_803DFF08
lbl_803DFF08:
	.4byte 0x00000000
.global lbl_803DFF0C
lbl_803DFF0C:
	.4byte 0x00000000
	.4byte 0x802B5DB8
	.4byte 0x00000000
	.4byte 0x802B5DCC
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803DFF20
	.4byte 0x802B5DDC
.global __RTTI__12ActBreakWall
__RTTI__12ActBreakWall:
	.4byte 0x802B5DA8
	.4byte 0x802B5DE8
.global lbl_803DFF38
lbl_803DFF38:
	.4byte 0x00000000
.global lbl_803DFF3C
lbl_803DFF3C:
	.4byte 0x00000000
.global lbl_803DFF40
lbl_803DFF40:
	.4byte 0x00000000
.global lbl_803DFF44
lbl_803DFF44:
	.4byte 0x00000000
.global lbl_803DFF48
lbl_803DFF48:
	.4byte 0x00000000
.global lbl_803DFF4C
lbl_803DFF4C:
	.4byte 0x00000000
.global lbl_803DFF50
lbl_803DFF50:
	.4byte 0x00000000
.global lbl_803DFF54
lbl_803DFF54:
	.4byte 0x00000000
.global lbl_803DFF58
lbl_803DFF58:
	.4byte 0x00000000
.global lbl_803DFF5C
lbl_803DFF5C:
	.4byte 0x00000000
.global lbl_803DFF60
lbl_803DFF60:
	.4byte 0x00000000
.global lbl_803DFF64
lbl_803DFF64:
	.4byte 0x00000000
.global lbl_803DFF68
lbl_803DFF68:
	.4byte 0x00000000
.global lbl_803DFF6C
lbl_803DFF6C:
	.4byte 0x00000000
.global lbl_803DFF70
lbl_803DFF70:
	.4byte 0x00000000
.global lbl_803DFF74
lbl_803DFF74:
	.4byte 0x00000000
.global lbl_803DFF78
lbl_803DFF78:
	.4byte 0x00000000
.global lbl_803DFF7C
lbl_803DFF7C:
	.4byte 0x00000000
.global lbl_803DFF80
lbl_803DFF80:
	.4byte 0x00000000
.global lbl_803DFF84
lbl_803DFF84:
	.4byte 0x00000000
.global lbl_803DFF88
lbl_803DFF88:
	.4byte 0x00000000
.global lbl_803DFF8C
lbl_803DFF8C:
	.4byte 0x00000000
.global lbl_803DFF90
lbl_803DFF90:
	.4byte 0x00000000
.global lbl_803DFF94
lbl_803DFF94:
	.4byte 0x00000000
.global lbl_803DFF98
lbl_803DFF98:
	.4byte 0x00000000
.global lbl_803DFF9C
lbl_803DFF9C:
	.4byte 0x00000000
.global lbl_803DFFA0
lbl_803DFFA0:
	.4byte 0x00000000
.global lbl_803DFFA4
lbl_803DFFA4:
	.4byte 0x00000000
.global lbl_803DFFA8
lbl_803DFFA8:
	.4byte 0x00000000
.global lbl_803DFFAC
lbl_803DFFAC:
	.4byte 0x00000000
.global lbl_803DFFB0
lbl_803DFFB0:
	.4byte 0x00000000
.global lbl_803DFFB4
lbl_803DFFB4:
	.4byte 0x00000000
.global lbl_803DFFB8
lbl_803DFFB8:
	.4byte 0x00000000
.global lbl_803DFFBC
lbl_803DFFBC:
	.4byte 0x00000000
.global lbl_803DFFC0
lbl_803DFFC0:
	.4byte 0x00000000
.global lbl_803DFFC4
lbl_803DFFC4:
	.4byte 0x00000000
.global lbl_803DFFC8
lbl_803DFFC8:
	.4byte 0x00000000
.global lbl_803DFFCC
lbl_803DFFCC:
	.4byte 0x00000000
.global lbl_803DFFD0
lbl_803DFFD0:
	.4byte 0x00000000
.global lbl_803DFFD4
lbl_803DFFD4:
	.4byte 0x00000000
.global lbl_803DFFD8
lbl_803DFFD8:
	.4byte 0x00000000
.global lbl_803DFFDC
lbl_803DFFDC:
	.4byte 0x00000000
.global lbl_803DFFE0
lbl_803DFFE0:
	.4byte 0x00000000
.global lbl_803DFFE4
lbl_803DFFE4:
	.4byte 0x00000000
.global lbl_803DFFE8
lbl_803DFFE8:
	.4byte 0x00000000
.global lbl_803DFFEC
lbl_803DFFEC:
	.4byte 0x00000000
.global lbl_803DFFF0
lbl_803DFFF0:
	.4byte 0x00000000
.global lbl_803DFFF4
lbl_803DFFF4:
	.4byte 0x00000000
.global lbl_803DFFF8
lbl_803DFFF8:
	.4byte 0x00000000
.global lbl_803DFFFC
lbl_803DFFFC:
	.4byte 0x00000000
.global lbl_803E0000
lbl_803E0000:
	.4byte 0x00000000
.global lbl_803E0004
lbl_803E0004:
	.4byte 0x00000000
.global lbl_803E0008
lbl_803E0008:
	.4byte 0x00000000
.global lbl_803E000C
lbl_803E000C:
	.4byte 0x00000000
.global lbl_803E0010
lbl_803E0010:
	.4byte 0x00000000
.global lbl_803E0014
lbl_803E0014:
	.4byte 0x00000000
.global lbl_803E0018
lbl_803E0018:
	.4byte 0x00000000
.global lbl_803E001C
lbl_803E001C:
	.4byte 0x00000000
.global lbl_803E0020
lbl_803E0020:
	.4byte 0x00000000
.global lbl_803E0024
lbl_803E0024:
	.4byte 0x00000000
.global lbl_803E0028
lbl_803E0028:
	.4byte 0x00000000
.global lbl_803E002C
lbl_803E002C:
	.4byte 0x00000000
.global lbl_803E0030
lbl_803E0030:
	.4byte 0x00000000
.global lbl_803E0034
lbl_803E0034:
	.4byte 0x00000000
.global lbl_803E0038
lbl_803E0038:
	.4byte 0x00000000
.global lbl_803E003C
lbl_803E003C:
	.asciz "go"
.balign 4
.global lbl_803E0040
lbl_803E0040:
	.asciz "wait"
.balign 4
.global lbl_803E0048
lbl_803E0048:
	.asciz "lift"
.balign 4
.global lbl_803E0050
lbl_803E0050:
	.asciz "move"
.balign 4
.global lbl_803E0058
lbl_803E0058:
	.asciz "guru"
.balign 4
.global lbl_803E0060
lbl_803E0060:
	.asciz "goal"
.balign 4
.global lbl_803E0068
lbl_803E0068:
	.asciz "put"
.balign 4
.global lbl_803E006C
lbl_803E006C:
	.asciz "tube"
.balign 4
.global lbl_803E0074
lbl_803E0074:
	.asciz "vert"
.balign 4
.global lbl_803E007C
lbl_803E007C:
	.asciz "other"
.balign 4
.global lbl_803E0084
lbl_803E0084:
	.asciz " "
.balign 4
.global lbl_803E0088
lbl_803E0088:
	.asciz "%d"
.balign 4
.global lbl_803E008C
lbl_803E008C:
	.4byte 0x00000000
.global lbl_803E0090
lbl_803E0090:
	.4byte 0x00000000
.global lbl_803E0094
lbl_803E0094:
	.4byte 0x00000000
.global lbl_803E0098
lbl_803E0098:
	.4byte 0x00000000
.global lbl_803E009C
lbl_803E009C:
	.4byte 0x00000000
.global lbl_803E00A0
lbl_803E00A0:
	.4byte 0x00000000
.global lbl_803E00A4
lbl_803E00A4:
	.4byte 0x00000000
.global lbl_803E00A8
lbl_803E00A8:
	.4byte 0x00000000
.global lbl_803E00AC
lbl_803E00AC:
	.4byte 0x00000000
.global lbl_803E00B0
lbl_803E00B0:
	.4byte 0x00000000
.global lbl_803E00B4
lbl_803E00B4:
	.4byte 0x00000000
.global lbl_803E00B8
lbl_803E00B8:
	.4byte 0x00000000
.global lbl_803E00BC
lbl_803E00BC:
	.4byte 0x00000000
.global lbl_803E00C0
lbl_803E00C0:
	.4byte 0x00000000
.global lbl_803E00C4
lbl_803E00C4:
	.4byte 0x00000000
.global lbl_803E00C8
lbl_803E00C8:
	.4byte 0x00000000
.global lbl_803E00CC
lbl_803E00CC:
	.4byte 0x00000000
.global lbl_803E00D0
lbl_803E00D0:
	.4byte 0x00000000
.global lbl_803E00D4
lbl_803E00D4:
	.4byte 0x00000000
.global lbl_803E00D8
lbl_803E00D8:
	.4byte 0x00000000
.global lbl_803E00DC
lbl_803E00DC:
	.4byte 0x00000000
.global lbl_803E00E0
lbl_803E00E0:
	.4byte 0x00000000
.global lbl_803E00E4
lbl_803E00E4:
	.4byte 0x00000000
.global lbl_803E00E8
lbl_803E00E8:
	.4byte 0x00000000
	.4byte 0x802B5F38
	.4byte 0x00000000
	.4byte 0x802B5F4C
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E00FC
	.4byte 0x802B5F5C
.global __RTTI__12ActTransport
__RTTI__12ActTransport:
	.4byte 0x802B5F28
	.4byte 0x802B5F68
	.4byte 0
.global lbl_803E0118
lbl_803E0118:
	.4byte 0x6B696E6F
	.4byte 0x6B6F0000
.global lbl_803E0120
lbl_803E0120:
	.4byte 0x00000000
.global lbl_803E0124
lbl_803E0124:
	.4byte 0x00000000
.global lbl_803E0128
lbl_803E0128:
	.4byte 0x00000000
.global lbl_803E012C
lbl_803E012C:
	.4byte 0x00000000
.global lbl_803E0130
lbl_803E0130:
	.4byte 0x00000000
.global lbl_803E0134
lbl_803E0134:
	.4byte 0x00000000
.global lbl_803E0138
lbl_803E0138:
	.4byte 0x00000000
.global lbl_803E013C
lbl_803E013C:
	.4byte 0x00000000
.global lbl_803E0140
lbl_803E0140:
	.4byte 0x00000000
.global lbl_803E0144
lbl_803E0144:
	.4byte 0x00000000
.global lbl_803E0148
lbl_803E0148:
	.4byte 0x00000000
.global lbl_803E014C
lbl_803E014C:
	.4byte 0x3C23D70A
.global lbl_803E0150
lbl_803E0150:
	.4byte 0x3F7D70A4
.global lbl_803E0154
lbl_803E0154:
	.4byte 0x3ECCCCCD
.global lbl_803E0158
lbl_803E0158:
	.4byte 0x3F000000
.global lbl_803E015C
lbl_803E015C:
	.4byte 0x3DCCCCCD
	.4byte 0x802B6090
	.4byte 0x00000000
	.4byte 0x802B60A4
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0170
	.4byte 0x802B60B4
.global __RTTI__9ActKinoko
__RTTI__9ActKinoko:
	.4byte 0x802B6084
	.4byte 0x802B60C0
.global lbl_803E0188
lbl_803E0188:
	.4byte 0x00000000
.global lbl_803E018C
lbl_803E018C:
	.4byte 0x00000000
.global lbl_803E0190
lbl_803E0190:
	.4byte 0x00000000
.global lbl_803E0194
lbl_803E0194:
	.4byte 0x00000000
	.4byte 0x802B61B0
	.4byte 0x00000000
lbl_803E01A0:
	.asciz "Action"
.balign 4
	.4byte 0x803E01A0
	.4byte 0x802B61C0
.global __RTTI__8ActChase
__RTTI__8ActChase:
	.4byte 0x802B61A4
	.4byte 0x802B61CC
	.4byte 0x802B625C
	.4byte 0
.global __RTTI__Q28ActChase11Initialiser
__RTTI__Q28ActChase11Initialiser:
	.4byte 0x802B6244
	.4byte 0x802B6270
.global newVer
newVer:
	.4byte 0x01000000
.global lbl_803E01CC
lbl_803E01CC:
	.asciz "crowd"
.balign 4
.global lbl_803E01D4
lbl_803E01D4:
	.4byte 0x00000000
.global lbl_803E01D8
lbl_803E01D8:
	.4byte 0x00000000
.global lbl_803E01DC
lbl_803E01DC:
	.4byte 0x00000000
.global lbl_803E01E0
lbl_803E01E0:
	.4byte 0x00000000
.global lbl_803E01E4
lbl_803E01E4:
	.4byte 0x00000000
.global lbl_803E01E8
lbl_803E01E8:
	.4byte 0x00000000
.global lbl_803E01EC
lbl_803E01EC:
	.4byte 0x3F747AE1
.global lbl_803E01F0
lbl_803E01F0:
	.4byte 0x00000000
.global lbl_803E01F4
lbl_803E01F4:
	.4byte 0x00000000
.global lbl_803E01F8
lbl_803E01F8:
	.4byte 0x00000000
.global lbl_803E01FC
lbl_803E01FC:
	.4byte 0x00000000
.global lbl_803E0200
lbl_803E0200:
	.4byte 0x00000000
.global lbl_803E0204
lbl_803E0204:
	.4byte 0x00000000
.global lbl_803E0208
lbl_803E0208:
	.4byte 0x00000000
.global lbl_803E020C
lbl_803E020C:
	.4byte 0x00000000
.global lbl_803E0210
lbl_803E0210:
	.4byte 0x00000000
.global lbl_803E0214
lbl_803E0214:
	.4byte 0x00000000
.global lbl_803E0218
lbl_803E0218:
	.4byte 0x00000000
.global lbl_803E021C
lbl_803E021C:
	.4byte 0x00000000
.global lbl_803E0220
lbl_803E0220:
	.4byte 0x00000000
.global lbl_803E0224
lbl_803E0224:
	.4byte 0x00000000
.global lbl_803E0228
lbl_803E0228:
	.4byte 0x00000000
.global lbl_803E022C
lbl_803E022C:
	.4byte 0x00000000
.global lbl_803E0230
lbl_803E0230:
	.4byte 0x00000000
.global __RTTI__17SlotChangeListner
__RTTI__17SlotChangeListner:
	.4byte 0x802B62D0
	.4byte 0
	.4byte 0x802B62E4
	.4byte 0
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0244
	.4byte 0x802B62F4
.global __RTTI__8ActCrowd
__RTTI__8ActCrowd:
	.4byte 0x802B62C4
	.4byte 0x802B6300
	.4byte 0
.global lbl_803E0260
lbl_803E0260:
	.4byte 0x00000000
.global lbl_803E0264
lbl_803E0264:
	.4byte 0x00000000
.global lbl_803E0268
lbl_803E0268:
	.4byte 0x00000000
.global lbl_803E026C
lbl_803E026C:
	.4byte 0x00000000
.global lbl_803E0270
lbl_803E0270:
	.4byte 0x00000000
.global lbl_803E0274
lbl_803E0274:
	.4byte 0x00000000
.global lbl_803E0278
lbl_803E0278:
	.4byte 0x3FA66666
	.4byte 0x802B63E0
	.4byte 0x00000000
	.4byte 0x802B63F4
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E028C
	.4byte 0x802B6404
.global __RTTI__8ActDecoy
__RTTI__8ActDecoy:
	.4byte 0x802B63D4
	.4byte 0x802B6410
	.4byte 0
.global lbl_803E02A8
lbl_803E02A8:
	.4byte 0x456E7465
	.4byte 0x72000000
.global lbl_803E02B0
lbl_803E02B0:
	.4byte 0x00000000
.global lbl_803E02B4
lbl_803E02B4:
	.4byte 0x00000000
.global lbl_803E02B8
lbl_803E02B8:
	.4byte 0x00000000
.global lbl_803E02BC
lbl_803E02BC:
	.4byte 0x00000000
.global lbl_803E02C0
lbl_803E02C0:
	.4byte 0x00000000
.global lbl_803E02C4
lbl_803E02C4:
	.4byte 0x00000000
.global lbl_803E02C8
lbl_803E02C8:
	.4byte 0x00000000
	.4byte 0x802B6528
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E02D4
	.4byte 0x802B6538
.global __RTTI__8ActEnter
__RTTI__8ActEnter:
	.4byte 0x802B651C
	.4byte 0x802B6544
	.4byte 0
.global lbl_803E02F0
lbl_803E02F0:
	.4byte 0x00000000
.global lbl_803E02F4
lbl_803E02F4:
	.4byte 0x00000000
.global lbl_803E02F8
lbl_803E02F8:
	.4byte 0x00000000
.global lbl_803E02FC
lbl_803E02FC:
	.4byte 0x00000000
.global lbl_803E0300
lbl_803E0300:
	.4byte 0x00000000
.global lbl_803E0304
lbl_803E0304:
	.4byte 0x00000000
.global lbl_803E0308
lbl_803E0308:
	.4byte 0x4E4F524D
	.4byte 0x414C0000
.global lbl_803E0310
lbl_803E0310:
	.4byte 0x41564F49
	.4byte 0x44000000
	.4byte 0x802B6624
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0320
	.4byte 0x802B6634
.global __RTTI__9ActEscape
__RTTI__9ActEscape:
	.4byte 0x802B6618
	.4byte 0x802B6640
	.4byte 0x802B66D0
	.4byte 0
.global __RTTI__Q29ActEscape11Initialiser
__RTTI__Q29ActEscape11Initialiser:
	.4byte 0x802B66B8
	.4byte 0x802B66E4
.global lbl_803E0348
lbl_803E0348:
	.4byte 0x45786974
	.4byte 0x00000000
.global lbl_803E0350
lbl_803E0350:
	.4byte 0x00000000
.global lbl_803E0354
lbl_803E0354:
	.4byte 0x00000000
.global lbl_803E0358
lbl_803E0358:
	.4byte 0x00000000
.global lbl_803E035C
lbl_803E035C:
	.float 1.0
.global lbl_803E0360
lbl_803E0360:
	.float 1.0
.global lbl_803E0364
lbl_803E0364:
	.float 1.0
.global lbl_803E0368
lbl_803E0368:
	.float 1.0
.global lbl_803E036C
lbl_803E036C:
	.float 1.0
.global lbl_803E0370
lbl_803E0370:
	.float 1.0
.global lbl_803E0374
lbl_803E0374:
	.float 1.0
.global lbl_803E0378
lbl_803E0378:
	.float 1.0
.global lbl_803E037C
lbl_803E037C:
	.float 1.0
.global lbl_803E0380
lbl_803E0380:
	.4byte 0x00000000
.global lbl_803E0384
lbl_803E0384:
	.float 1.0
.global lbl_803E0388
lbl_803E0388:
	.float 1.0
.global lbl_803E038C
lbl_803E038C:
	.float 1.0
.global lbl_803E0390
lbl_803E0390:
	.4byte 0x43480000
	.4byte 0x41637445
	.4byte 0x78697400
	.4byte 0x802B6734
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E03A4
	.4byte 0x802B6744
.global __RTTI__7ActExit
__RTTI__7ActExit:
	.4byte 0x803E0394
	.4byte 0x802B6750
	.4byte 0
.global lbl_803E03C0
lbl_803E03C0:
	.4byte 0x00000000
.global lbl_803E03C4
lbl_803E03C4:
	.4byte 0x00000000
.global lbl_803E03C8
lbl_803E03C8:
	.4byte 0x00000000
.global lbl_803E03CC
lbl_803E03CC:
	.4byte 0x00000000
.global lbl_803E03D0
lbl_803E03D0:
	.4byte 0x00000000
.global lbl_803E03D4
lbl_803E03D4:
	.4byte 0x00000000
	.4byte 0x4163744D
	.4byte 0x696E6500
	.4byte 0x802B6804
	.4byte 0x00000000
	.4byte 0x802B6818
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E03F0
	.4byte 0x802B6828
.global __RTTI__7ActMine
__RTTI__7ActMine:
	.4byte 0x803E03D8
	.4byte 0x802B6834
.global lbl_803E0408
lbl_803E0408:
	.4byte 0x00000000
.global lbl_803E040C
lbl_803E040C:
	.4byte 0x00000000
.global lbl_803E0410
lbl_803E0410:
	.4byte 0x00000000
.global lbl_803E0414
lbl_803E0414:
	.4byte 0x00000000
.global lbl_803E0418
lbl_803E0418:
	.4byte 0x00000000
.global lbl_803E041C
lbl_803E041C:
	.4byte 0x00000000
.global lbl_803E0420
lbl_803E0420:
	.4byte 0x00000000
.global lbl_803E0424
lbl_803E0424:
	.4byte 0x00000000
.global lbl_803E0428
lbl_803E0428:
	.4byte 0x00000000
.global lbl_803E042C
lbl_803E042C:
	.4byte 0x00000000
.global lbl_803E0430
lbl_803E0430:
	.4byte 0x00000000
	.4byte 0x802B6964
	.4byte 0x00000000
	.4byte 0x802B6978
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0444
	.4byte 0x802B6988
.global __RTTI__12ActFormation
__RTTI__12ActFormation:
	.4byte 0x802B6954
	.4byte 0x802B6994
	.4byte 0
.global lbl_803E0460
lbl_803E0460:
	.4byte 0x66726565
	.4byte 0x00000000
.global numMotions
numMotions:
	.4byte 0x00000004
.global lbl_803E046C
lbl_803E046C:
	.4byte 0x00000000
.global lbl_803E0470
lbl_803E0470:
	.4byte 0x00000000
.global lbl_803E0474
lbl_803E0474:
	.4byte 0x00000000
.global lbl_803E0478
lbl_803E0478:
	.4byte 0x00000000
.global lbl_803E047C
lbl_803E047C:
	.4byte 0x00000000
.global lbl_803E0480
lbl_803E0480:
	.4byte 0x00000000
	.4byte 0x41637446
	.4byte 0x72656500
	.4byte 0x802B6A7C
	.4byte 0x00000000
	.4byte 0x802B6A90
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E049C
	.4byte 0x802B6AA0
.global __RTTI__7ActFree
__RTTI__7ActFree:
	.4byte 0x803E0484
	.4byte 0x802B6AAC
	.4byte 0
.global lbl_803E04B8
lbl_803E04B8:
	.4byte 0x00000000
.global lbl_803E04BC
lbl_803E04BC:
	.4byte 0x00000000
.global lbl_803E04C0
lbl_803E04C0:
	.4byte 0x00000000
.global lbl_803E04C4
lbl_803E04C4:
	.4byte 0x00000000
	.4byte 0x41637447
	.4byte 0x6F746F00
	.4byte 0x802B6B84
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E04D8
	.4byte 0x802B6B94
.global __RTTI__7ActGoto
__RTTI__7ActGoto:
	.4byte 0x803E04C8
	.4byte 0x802B6BA0
	.4byte 0x802B6C30
	.4byte 0
.global __RTTI__Q27ActGoto11Initialiser
__RTTI__Q27ActGoto11Initialiser:
	.4byte 0x802B6C18
	.4byte 0x802B6C44
.global lbl_803E0500
lbl_803E0500:
	.4byte 0x00000000
.global lbl_803E0504
lbl_803E0504:
	.4byte 0x00000000
.global lbl_803E0508
lbl_803E0508:
	.4byte 0x00000000
.global lbl_803E050C
lbl_803E050C:
	.4byte 0x41500000
.global lbl_803E0510
lbl_803E0510:
	.4byte 0x3DCCCCCD
.global lbl_803E0514
lbl_803E0514:
	.4byte 0x41500000
.global lbl_803E0518
lbl_803E0518:
	.4byte 0x3DCCCCCD
.global lbl_803E051C
lbl_803E051C:
	.4byte 0x00000000
.global lbl_803E0520
lbl_803E0520:
	.4byte 0x00000000
.global lbl_803E0524
lbl_803E0524:
	.4byte 0x00000000
.global lbl_803E0528
lbl_803E0528:
	.4byte 0x00000000
	.4byte 0x802B6CA0
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0534
	.4byte 0x802B6CB0
.global __RTTI__8ActGuard
__RTTI__8ActGuard:
	.4byte 0x802B6C94
	.4byte 0x802B6CBC
	.4byte 0
.global lbl_803E0550
lbl_803E0550:
	.4byte 0x00000000
.global lbl_803E0554
lbl_803E0554:
	.4byte 0x00000000
.global lbl_803E0558
lbl_803E0558:
	.4byte 0x00000000
.global lbl_803E055C
lbl_803E055C:
	.4byte 0x00000000
.global lbl_803E0560
lbl_803E0560:
	.4byte 0x00000000
.global lbl_803E0564
lbl_803E0564:
	.4byte 0x00000000
	.4byte 0x802B6DC8
	.4byte 0x00000000
	.4byte 0x802B6DDC
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0578
	.4byte 0x802B6DEC
.global __RTTI__9ActFlower
__RTTI__9ActFlower:
	.4byte 0x802B6DBC
	.4byte 0x802B6DF8
	.4byte 0x802B6EA0
	.4byte 0x802B6EAC
.global __RTTI__11ActPickItem
__RTTI__11ActPickItem:
	.4byte 0x802B6E94
	.4byte 0x802B6EC0
	.4byte 0x802B6FA0
	.4byte 0
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E05A8
	.4byte 0x802B6FB0
	.4byte 0x802B6FBC
	.4byte 0x802B6FC8
.global __RTTI__10ActDeliver
__RTTI__10ActDeliver:
	.4byte 0x802B6F94
	.4byte 0x802B6FDC
	.4byte 0x802B7074
	.4byte 0
.global __RTTI__Q210ActDeliver11Initialiser
__RTTI__Q210ActDeliver11Initialiser:
	.4byte 0x802B705C
	.4byte 0x802B7088
.global __RTTI__15ActPickCreature
__RTTI__15ActPickCreature:
	.4byte 0x802B70AC
	.4byte 0x802B70BC
.global lbl_803E05E0
lbl_803E05E0:
	.4byte 0x00000000
.global lbl_803E05E4
lbl_803E05E4:
	.4byte 0x00000000
.global lbl_803E05E8
lbl_803E05E8:
	.4byte 0x00000000
.global lbl_803E05EC
lbl_803E05EC:
	.4byte 0x00000000
.global lbl_803E05F0
lbl_803E05F0:
	.4byte 0x00000000
.global lbl_803E05F4
lbl_803E05F4:
	.4byte 0x00000000
.global lbl_803E05F8
lbl_803E05F8:
	.4byte 0x00000000
.global lbl_803E05FC
lbl_803E05FC:
	.4byte 0x00000000
.global lbl_803E0600
lbl_803E0600:
	.4byte 0x00000000
.global lbl_803E0604
lbl_803E0604:
	.4byte 0x00000000
.global lbl_803E0608
lbl_803E0608:
	.4byte 0x00000000
.global lbl_803E060C
lbl_803E060C:
	.4byte 0x00000000
	.4byte 0x802B71D0
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0618
	.4byte 0x802B71E0
.global __RTTI__18ActPulloutCreature
__RTTI__18ActPulloutCreature:
	.4byte 0x802B71BC
	.4byte 0x802B71EC
	.4byte 0x802B72A0
	.4byte 0x802B72AC
.global __RTTI__10ActPullout
__RTTI__10ActPullout:
	.4byte 0x802B7294
	.4byte 0x802B72C0
.global lbl_803E0640
lbl_803E0640:
	.4byte 0x50757368
	.4byte 0x00000000
	.4byte 0x41637450
	.4byte 0x75736800
	.4byte 0x802B73E8
	.4byte 0x00000000
	.4byte 0x802B73FC
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0660
	.4byte 0x802B740C
.global __RTTI__7ActPush
__RTTI__7ActPush:
	.4byte 0x803E0648
	.4byte 0x802B7418
.global lbl_803E0678
lbl_803E0678:
	.4byte 0x70757462
	.4byte 0x6F6D6200
.global lbl_803E0680
lbl_803E0680:
	.4byte 0x00000000
.global lbl_803E0684
lbl_803E0684:
	.4byte 0x00000000
.global lbl_803E0688
lbl_803E0688:
	.4byte 0x00000000
.global lbl_803E068C
lbl_803E068C:
	.4byte 0x00000000
.global lbl_803E0690
lbl_803E0690:
	.4byte 0x00000000
.global lbl_803E0694
lbl_803E0694:
	.float 1.0
.global lbl_803E0698
lbl_803E0698:
	.4byte 0x00000000
.global lbl_803E069C
lbl_803E069C:
	.4byte 0x00000000
.global lbl_803E06A0
lbl_803E06A0:
	.4byte 0x00000000
.global lbl_803E06A4
lbl_803E06A4:
	.4byte 0x00000000
.global lbl_803E06A8
lbl_803E06A8:
	.4byte 0x00000000
.global lbl_803E06AC
lbl_803E06AC:
	.4byte 0x00000000
.global lbl_803E06B0
lbl_803E06B0:
	.4byte 0x00000000
.global lbl_803E06B4
lbl_803E06B4:
	.4byte 0x00000000
.global lbl_803E06B8
lbl_803E06B8:
	.4byte 0x00000000
.global lbl_803E06BC
lbl_803E06BC:
	.4byte 0x00000000
.global lbl_803E06C0
lbl_803E06C0:
	.4byte 0x00000000
.global lbl_803E06C4
lbl_803E06C4:
	.4byte 0x00000000
.global lbl_803E06C8
lbl_803E06C8:
	.4byte 0x00000000
.global lbl_803E06CC
lbl_803E06CC:
	.4byte 0x00000000
.global lbl_803E06D0
lbl_803E06D0:
	.4byte 0x00000000
.global lbl_803E06D4
lbl_803E06D4:
	.4byte 0x00000000
	.4byte 0x802B7504
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E06E0
	.4byte 0x802B7514
.global __RTTI__10ActPutItem
__RTTI__10ActPutItem:
	.4byte 0x802B74F8
	.4byte 0x802B7520
	.4byte 0x802B75A4
	.4byte 0
.global __RTTI__10ActPutBomb
__RTTI__10ActPutBomb:
	.4byte 0x802B7598
	.4byte 0x802B75B8
.global lbl_803E0708
lbl_803E0708:
	.4byte 0x00000000
.global lbl_803E070C
lbl_803E070C:
	.4byte 0x00000000
.global lbl_803E0710
lbl_803E0710:
	.4byte 0x00000000
.global lbl_803E0714
lbl_803E0714:
	.4byte 0x00000000
.global lbl_803E0718
lbl_803E0718:
	.4byte 0x00000000
.global lbl_803E071C
lbl_803E071C:
	.4byte 0x00000000
.global lbl_803E0720
lbl_803E0720:
	.4byte 0x00000000
.global lbl_803E0724
lbl_803E0724:
	.4byte 0x00000000
.global lbl_803E0728
lbl_803E0728:
	.4byte 0x00000000
.global lbl_803E072C
lbl_803E072C:
	.4byte 0x00000000
.global lbl_803E0730
lbl_803E0730:
	.4byte 0x00000000
.global lbl_803E0734
lbl_803E0734:
	.4byte 0x00000000
.global lbl_803E0738
lbl_803E0738:
	.4byte 0x00000000
.global lbl_803E073C
lbl_803E073C:
	.4byte 0x00000000
.global lbl_803E0740
lbl_803E0740:
	.4byte 0x00000000
.global lbl_803E0744
lbl_803E0744:
	.4byte 0x00000000
.global lbl_803E0748
lbl_803E0748:
	.4byte 0x00000000
.global lbl_803E074C
lbl_803E074C:
	.4byte 0x00000000
.global lbl_803E0750
lbl_803E0750:
	.4byte 0x00000000
.global lbl_803E0754
lbl_803E0754:
	.4byte 0x00000000
	.4byte 0x426F6964
	.4byte 0x00000000
	.4byte 0x92E28E7E
	.4byte 0x00000000
.global lbl_803E0768
lbl_803E0768:
	.4byte 0x25730000
	.4byte 0x802B7704
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0774
	.4byte 0x802B7714
.global __RTTI__13ActRandomBoid
__RTTI__13ActRandomBoid:
	.4byte 0x802B76F4
	.4byte 0x802B7720
	.4byte 0x802B77B4
	.4byte 0
.global __RTTI__Q213ActRandomBoid11Initialiser
__RTTI__Q213ActRandomBoid11Initialiser:
	.4byte 0x802B7798
	.4byte 0x802B77C8
	.4byte 0x802B77E0
	.4byte 0
.global __RTTI__Q213ActRandomBoid12AnimListener
__RTTI__Q213ActRandomBoid12AnimListener:
	.4byte 0x802B7800
	.4byte 0x802B781C
	.4byte 0
.global lbl_803E07B0
lbl_803E07B0:
	.4byte 0x52657363
	.4byte 0x75650000
.global lbl_803E07B8
lbl_803E07B8:
	.4byte 0x00000000
.global lbl_803E07BC
lbl_803E07BC:
	.4byte 0x00000000
.global lbl_803E07C0
lbl_803E07C0:
	.4byte 0x00000000
.global lbl_803E07C4
lbl_803E07C4:
	.4byte 0x3F4CCCCD
.global lbl_803E07C8
lbl_803E07C8:
	.4byte 0x00000000
.global lbl_803E07CC
lbl_803E07CC:
	.4byte 0x00000000
.global lbl_803E07D0
lbl_803E07D0:
	.4byte 0x00000000
.global lbl_803E07D4
lbl_803E07D4:
	.4byte 0x00000000
.global lbl_803E07D8
lbl_803E07D8:
	.4byte 0x00000000
.global lbl_803E07DC
lbl_803E07DC:
	.4byte 0x00000000
.global lbl_803E07E0
lbl_803E07E0:
	.4byte 0x00000000
	.4byte 0x802B7888
	.4byte 0x00000000
	.4byte 0x802B789C
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E07F4
	.4byte 0x802B78AC
.global __RTTI__9ActRescue
__RTTI__9ActRescue:
	.4byte 0x802B787C
	.4byte 0x802B78B8
	.4byte 0
.global lbl_803E0810
lbl_803E0810:
	.4byte 0x726F7065
	.4byte 0x00000000
.global lbl_803E0818
lbl_803E0818:
	.4byte 0x00000000
.global lbl_803E081C
lbl_803E081C:
	.float 1.0
.global lbl_803E0820
lbl_803E0820:
	.4byte 0x00000000
.global lbl_803E0824
lbl_803E0824:
	.4byte 0x43160000
	.4byte 0x41637452
	.4byte 0x6F706500
	.4byte 0x802B798C
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E0838
	.4byte 0x802B799C
.global __RTTI__7ActRope
__RTTI__7ActRope:
	.4byte 0x803E0828
	.4byte 0x802B79A8
.global lbl_803E0850
lbl_803E0850:
	.4byte 0x00000000
.global lbl_803E0854
lbl_803E0854:
	.4byte 0x00000000
.global lbl_803E0858
lbl_803E0858:
	.4byte 0x00000000
.global lbl_803E085C
lbl_803E085C:
	.4byte 0xBF800000
.global lbl_803E0860
lbl_803E0860:
	.4byte 0x00000000
.global lbl_803E0864
lbl_803E0864:
	.4byte 0x00000000
.global lbl_803E0868
lbl_803E0868:
	.4byte 0x00000000
	.4byte 0x802B7A70
	.4byte 0x00000000
	.4byte 0x802B7A84
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E087C
	.4byte 0x802B7A94
.global __RTTI__16ActShootCreature
__RTTI__16ActShootCreature:
	.4byte 0x802B7A5C
	.4byte 0x802B7AA0
	.4byte 0x802B7B48
	.4byte 0x802B7B54
.global __RTTI__8ActShoot
__RTTI__8ActShoot:
	.4byte 0x802B7B3C
	.4byte 0x802B7B68
	.4byte 0
.global lbl_803E08A8
lbl_803E08A8:
	.4byte 0x00000000
.global lbl_803E08AC
lbl_803E08AC:
	.4byte 0x00000000
.global lbl_803E08B0
lbl_803E08B0:
	.4byte 0x00000000
.global lbl_803E08B4
lbl_803E08B4:
	.4byte 0x00000000
.global lbl_803E08B8
lbl_803E08B8:
	.4byte 0x00000000
	.4byte 0x802B7C5C
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E08C4
	.4byte 0x802B7C6C
.global __RTTI__8ActWatch
__RTTI__8ActWatch:
	.4byte 0x802B7C50
	.4byte 0x802B7C78
	.4byte 0x802B7D08
	.4byte 0
.global __RTTI__Q28ActWatch11Initialiser
__RTTI__Q28ActWatch11Initialiser:
	.4byte 0x802B7CF0
	.4byte 0x802B7D1C
	.4byte 0x802B7D34
	.4byte 0
.global __RTTI__Q28ActWatch12AnimListener
__RTTI__Q28ActWatch12AnimListener:
	.4byte 0x802B7D54
	.4byte 0x802B7D6C
	.4byte 0
.global lbl_803E0900
lbl_803E0900:
	.4byte 0x00000000
.global lbl_803E0904
lbl_803E0904:
	.4byte 0x00000000
.global lbl_803E0908
lbl_803E0908:
	.4byte 0x00000000
.global lbl_803E090C
lbl_803E090C:
	.4byte 0x00000000
.global lbl_803E0910
lbl_803E0910:
	.4byte 0x00000000
.global lbl_803E0914
lbl_803E0914:
	.4byte 0x00000000
.global lbl_803E0918
lbl_803E0918:
	.4byte 0x00000000
.global lbl_803E091C
lbl_803E091C:
	.4byte 0x00000000
.global lbl_803E0920
lbl_803E0920:
	.4byte 0x00000000
.global lbl_803E0924
lbl_803E0924:
	.4byte 0x00000000
.global lbl_803E0928
lbl_803E0928:
	.4byte 0x00000000
.global lbl_803E092C
lbl_803E092C:
	.4byte 0x00000000
.global lbl_803E0930
lbl_803E0930:
	.4byte 0x00000000
.global lbl_803E0934
lbl_803E0934:
	.float 1.0
.global lbl_803E0938
lbl_803E0938:
	.4byte 0x00000000
	.4byte 0x41637457
	.4byte 0x65656400
	.4byte 0x802B7DBC
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E094C
	.4byte 0x802B7DCC
.global __RTTI__7ActWeed
__RTTI__7ActWeed:
	.4byte 0x803E093C
	.4byte 0x802B7DD8
	.4byte 0
	.4byte 0x2D000000
	.4byte 0x57415443
	.4byte 0x48000000
	.4byte 0x45534341
	.4byte 0x50450000
	.4byte 0x43484153
	.4byte 0x45000000
	.4byte 0x474F544F
	.4byte 0
	.4byte 0x5049434B
	.4byte 0
	.4byte 0x50555400
	.4byte 0x4B49434B
	.4byte 0
.global lbl_803E09A0
lbl_803E09A0:
	.4byte 0x6E6F206E
	.4byte 0x616D6500
	.4byte 0x802B7FA4
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E09B0
	.4byte 0x802B7FB4
.global __RTTI__9TopAction
__RTTI__9TopAction:
	.4byte 0x802B7F98
	.4byte 0x802B7FC0
	.4byte 0x802B8038
	.4byte 0
.global __RTTI__Q29TopAction14MotionListener
__RTTI__Q29TopAction14MotionListener:
	.4byte 0x802B8058
	.4byte 0x802B8074
.global __RTTI__8OrAction
__RTTI__8OrAction:
	.4byte 0x802B808C
	.4byte 0x802B8098
	.4byte 0x802B8110
	.4byte 0x802B811C
.global lbl_803E09E8
lbl_803E09E8:
	.4byte 0x00000000
.global lbl_803E09EC
lbl_803E09EC:
	.4byte 0x00000000
.global lbl_803E09F0
lbl_803E09F0:
	.4byte 0x00000000
.global lbl_803E09F4
lbl_803E09F4:
	.4byte 0x00000000
.global lbl_803E09F8
lbl_803E09F8:
	.4byte 0x00000000
.global lbl_803E09FC
lbl_803E09FC:
	.4byte 0x00000000
.global lbl_803E0A00
lbl_803E0A00:
	.4byte 0x62617365
	.4byte 0x496E6600
.global lbl_803E0A08
lbl_803E0A08:
	.4byte 0x00000000
.global lbl_803E0A0C
lbl_803E0A0C:
	.4byte 0x00000000
.global lbl_803E0A10
lbl_803E0A10:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E0A14
	.4byte 0x00000000
	.4byte 0x802B823C
	.4byte 0x802B826C
	.4byte 0x42617365
	.4byte 0x496E6600
.global __RTTI__7BaseInf
__RTTI__7BaseInf:
	.4byte 0x803E0A2C
	.4byte 0x802B8278
.global __RTTI__11CreatureInf
__RTTI__11CreatureInf:
	.4byte 0x802B8260
	.4byte 0x802B828C
	.4byte 0x496E664D
	.4byte 0x67720000
.global __RTTI__6InfMgr
__RTTI__6InfMgr:
	.4byte 0x803E0A44
	.4byte 0
.global __RTTI__10MonoInfMgr
__RTTI__10MonoInfMgr:
	.4byte 0x802B82D8
	.4byte 0x802B82E4
.global __RTTI__14CreatureInfMgr
__RTTI__14CreatureInfMgr:
	.4byte 0x802B82C8
	.4byte 0x802B82F0
.global __RTTI__11BPikiInfMgr
__RTTI__11BPikiInfMgr:
	.4byte 0x802B8324
	.4byte 0x802B8330
.global __RTTI__8BPikiInf
__RTTI__8BPikiInf:
	.4byte 0x802B83A0
	.4byte 0x802B83AC
	.4byte 0
.global lbl_803E0A78
lbl_803E0A78:
	.4byte 0x00000000
.global lbl_803E0A7C
lbl_803E0A7C:
	.4byte 0x00000000
.global lbl_803E0A80
lbl_803E0A80:
	.4byte 0x00000000
.global lbl_803E0A84
lbl_803E0A84:
	.4byte 0x00000000
.global lbl_803E0A88
lbl_803E0A88:
	.float 1.0
.global lbl_803E0A8C
lbl_803E0A8C:
	.4byte 0x00000000
.global lbl_803E0A90
lbl_803E0A90:
	.4byte 0x00000000
.global lbl_803E0A94
lbl_803E0A94:
	.4byte 0x00000000
.global lbl_803E0A98
lbl_803E0A98:
	.4byte 0x00000000
.global lbl_803E0A9C
lbl_803E0A9C:
	.4byte 0x00000000
.global lbl_803E0AA0
lbl_803E0AA0:
	.float 1.0
.global lbl_803E0AA4
lbl_803E0AA4:
	.float 1.0
.global lbl_803E0AA8
lbl_803E0AA8:
	.float 1.0
.global lbl_803E0AAC
lbl_803E0AAC:
	.4byte 0x00000000
.global lbl_803E0AB0
lbl_803E0AB0:
	.4byte 0x00000000
.global lbl_803E0AB4
lbl_803E0AB4:
	.4byte 0x00000000
	.4byte 0x4E4F524D
	.4byte 0x414C0000
	.4byte 0x47524F57
	.4byte 0x00000000
	.4byte 0x42555259
	.4byte 0x00000000
	.4byte 0x4E554B41
	.4byte 0x52450000
	.4byte 0x4459494E
	.4byte 0x47000000
	.4byte 0x44454144
	.4byte 0x00000000
	.4byte 0x47524F57
	.4byte 0x55500000
	.4byte 0x4142534F
	.4byte 0x52420000
	.4byte 0x494C4C45
	.4byte 0x47414C00
	.4byte 0x47524F55
	.4byte 0x4E440000
	.4byte 0x504C4154
	.4byte 0x00000000
	.4byte 0x41495200
	.4byte 0x424F5F4D
	.4byte 0x4F444500
	.4byte 0x626C7565
	.4byte 0x00000000
	.4byte 0x72656400
	.4byte 0x79656C6C
	.4byte 0x6F770000
.global "__RTTI__19StateMachine<4Piki>"
"__RTTI__19StateMachine<4Piki>":
	.4byte 0x802B8760
	.4byte 0
	.4byte 0x802B878C
	.4byte 0
	.4byte 0x802B87B0
	.4byte 0
	.4byte 0x802B87F0
	.4byte 0
	.4byte 0x802B8898
	.4byte 0
	.4byte 0x50696B69
	.4byte 0
	.4byte 0x802B88B8
	.4byte 0
	.4byte 0x802B88C4
	.4byte 0
	.4byte 0x802B88D4
	.4byte 0x802B88E0
.global __RTTI__4Piki
__RTTI__4Piki:
	.4byte 0x803E0B58
	.4byte 0x802B88F4
.global lbl_803E0B80
lbl_803E0B80:
	.4byte 0x73303000
.global lbl_803E0B84
lbl_803E0B84:
	.4byte 0x73303100
.global lbl_803E0B88
lbl_803E0B88:
	.4byte 0x73303200
.global lbl_803E0B8C
lbl_803E0B8C:
	.4byte 0x73303300
.global lbl_803E0B90
lbl_803E0B90:
	.4byte 0x73303400
.global lbl_803E0B94
lbl_803E0B94:
	.4byte 0x7061726D
	.4byte 0x732F0000
.global lbl_803E0B9C
lbl_803E0B9C:
	.4byte 0x70303000
.global lbl_803E0BA0
lbl_803E0BA0:
	.4byte 0x70303100
.global lbl_803E0BA4
lbl_803E0BA4:
	.4byte 0x70353400
.global lbl_803E0BA8
lbl_803E0BA8:
	.4byte 0x70363500
.global lbl_803E0BAC
lbl_803E0BAC:
	.4byte 0x70333800
.global lbl_803E0BB0
lbl_803E0BB0:
	.4byte 0x70303300
.global lbl_803E0BB4
lbl_803E0BB4:
	.4byte 0x70313000
.global lbl_803E0BB8
lbl_803E0BB8:
	.4byte 0x70313100
.global lbl_803E0BBC
lbl_803E0BBC:
	.4byte 0x70303400
.global lbl_803E0BC0
lbl_803E0BC0:
	.4byte 0x70313200
.global lbl_803E0BC4
lbl_803E0BC4:
	.4byte 0x70313300
.global lbl_803E0BC8
lbl_803E0BC8:
	.4byte 0x70303500
.global lbl_803E0BCC
lbl_803E0BCC:
	.4byte 0x70303600
.global lbl_803E0BD0
lbl_803E0BD0:
	.4byte 0x70303700
.global lbl_803E0BD4
lbl_803E0BD4:
	.4byte 0x70303800
.global lbl_803E0BD8
lbl_803E0BD8:
	.4byte 0x70303900
.global lbl_803E0BDC
lbl_803E0BDC:
	.4byte 0x70313400
.global lbl_803E0BE0
lbl_803E0BE0:
	.4byte 0x70313500
.global lbl_803E0BE4
lbl_803E0BE4:
	.4byte 0x70313600
.global lbl_803E0BE8
lbl_803E0BE8:
	.4byte 0x70333700
.global lbl_803E0BEC
lbl_803E0BEC:
	.4byte 0x70313700
.global lbl_803E0BF0
lbl_803E0BF0:
	.4byte 0x70313800
.global lbl_803E0BF4
lbl_803E0BF4:
	.4byte 0x70313900
.global lbl_803E0BF8
lbl_803E0BF8:
	.4byte 0x70323000
.global lbl_803E0BFC
lbl_803E0BFC:
	.4byte 0x70323100
.global lbl_803E0C00
lbl_803E0C00:
	.4byte 0x70323200
.global lbl_803E0C04
lbl_803E0C04:
	.4byte 0x70323300
.global lbl_803E0C08
lbl_803E0C08:
	.4byte 0x70323400
.global lbl_803E0C0C
lbl_803E0C0C:
	.4byte 0x70323500
.global lbl_803E0C10
lbl_803E0C10:
	.4byte 0x70323600
.global lbl_803E0C14
lbl_803E0C14:
	.4byte 0x70323700
.global lbl_803E0C18
lbl_803E0C18:
	.4byte 0x70333400
.global lbl_803E0C1C
lbl_803E0C1C:
	.4byte 0x70323800
.global lbl_803E0C20
lbl_803E0C20:
	.4byte 0x70333900
.global lbl_803E0C24
lbl_803E0C24:
	.4byte 0x70323900
.global lbl_803E0C28
lbl_803E0C28:
	.4byte 0x70333000
.global lbl_803E0C2C
lbl_803E0C2C:
	.4byte 0x70333100
.global lbl_803E0C30
lbl_803E0C30:
	.4byte 0x70333200
.global lbl_803E0C34
lbl_803E0C34:
	.4byte 0x70333300
.global lbl_803E0C38
lbl_803E0C38:
	.4byte 0x70333500
.global lbl_803E0C3C
lbl_803E0C3C:
	.4byte 0x70333600
.global lbl_803E0C40
lbl_803E0C40:
	.4byte 0x70343000
.global lbl_803E0C44
lbl_803E0C44:
	.4byte 0x70343100
.global lbl_803E0C48
lbl_803E0C48:
	.4byte 0x70343200
.global lbl_803E0C4C
lbl_803E0C4C:
	.4byte 0x70343300
.global lbl_803E0C50
lbl_803E0C50:
	.4byte 0x70373400
.global lbl_803E0C54
lbl_803E0C54:
	.4byte 0x70343400
.global lbl_803E0C58
lbl_803E0C58:
	.4byte 0x70343500
.global lbl_803E0C5C
lbl_803E0C5C:
	.4byte 0x70343600
.global lbl_803E0C60
lbl_803E0C60:
	.4byte 0x70343700
.global lbl_803E0C64
lbl_803E0C64:
	.4byte 0x70343800
.global lbl_803E0C68
lbl_803E0C68:
	.4byte 0x70343900
.global lbl_803E0C6C
lbl_803E0C6C:
	.4byte 0x70353000
.global lbl_803E0C70
lbl_803E0C70:
	.4byte 0x70353100
.global lbl_803E0C74
lbl_803E0C74:
	.4byte 0x70353200
.global lbl_803E0C78
lbl_803E0C78:
	.4byte 0x70353300
.global lbl_803E0C7C
lbl_803E0C7C:
	.4byte 0x70353500
.global lbl_803E0C80
lbl_803E0C80:
	.4byte 0x70353600
.global lbl_803E0C84
lbl_803E0C84:
	.4byte 0x70353700
.global lbl_803E0C88
lbl_803E0C88:
	.4byte 0x70353800
.global lbl_803E0C8C
lbl_803E0C8C:
	.4byte 0x70353900
.global lbl_803E0C90
lbl_803E0C90:
	.4byte 0x70373500
.global lbl_803E0C94
lbl_803E0C94:
	.4byte 0x70373600
.global lbl_803E0C98
lbl_803E0C98:
	.4byte 0x70373700
.global lbl_803E0C9C
lbl_803E0C9C:
	.4byte 0x70363000
.global lbl_803E0CA0
lbl_803E0CA0:
	.4byte 0x70363100
.global lbl_803E0CA4
lbl_803E0CA4:
	.4byte 0x70363200
.global lbl_803E0CA8
lbl_803E0CA8:
	.4byte 0x70363300
.global lbl_803E0CAC
lbl_803E0CAC:
	.4byte 0x70363400
.global lbl_803E0CB0
lbl_803E0CB0:
	.4byte 0x70363600
.global lbl_803E0CB4
lbl_803E0CB4:
	.4byte 0x70363700
.global lbl_803E0CB8
lbl_803E0CB8:
	.4byte 0x70363800
.global lbl_803E0CBC
lbl_803E0CBC:
	.4byte 0x70363900
.global lbl_803E0CC0
lbl_803E0CC0:
	.4byte 0x70373000
.global lbl_803E0CC4
lbl_803E0CC4:
	.4byte 0x70373100
.global lbl_803E0CC8
lbl_803E0CC8:
	.4byte 0x70373200
.global lbl_803E0CCC
lbl_803E0CCC:
	.4byte 0x70373300
.global lbl_803E0CD0
lbl_803E0CD0:
	.4byte 0x70696B69
	.4byte 0x4E657700
	.4byte 0x50696B69
	.4byte 0x4D677200
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E0CE0
	.4byte 0x00000000
	.4byte 0x802B8ABC
	.4byte 0x802B8AC8
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803E0CF8
	.4byte 0x802B8AD4
	.4byte 0x802B8AE8
	.4byte 0x00000000
	.4byte 0x802B8AF4
	.4byte 0x802B8B00
	.4byte 0x802B8B24
	.4byte 0x802B8B34
.global __RTTI__7PikiMgr
__RTTI__7PikiMgr:
	.4byte 0x803E0CD8
	.4byte 0x802B8B60
	.4byte 0x802B8C28
	.4byte 0
	.4byte 0x802B8C8C
	.4byte 0
.global __RTTI__8PikiProp
__RTTI__8PikiProp:
	.4byte 0x802B8C80
	.4byte 0x802B8C9C
.global lbl_803E0D40
lbl_803E0D40:
	.4byte 0x4C4F4F4B
	.4byte 0x41540000
.global lbl_803E0D48
lbl_803E0D48:
	.4byte 0x00000000
.global lbl_803E0D4C
lbl_803E0D4C:
	.4byte 0x00000000
.global lbl_803E0D50
lbl_803E0D50:
	.4byte 0x00000000
.global lbl_803E0D54
lbl_803E0D54:
	.4byte 0x00000000
.global lbl_803E0D58
lbl_803E0D58:
	.4byte 0x00000000
.global lbl_803E0D5C
lbl_803E0D5C:
	.4byte 0x4E4F524D
	.4byte 0x414C0000
.global lbl_803E0D64
lbl_803E0D64:
	.4byte 0x4142534F
	.4byte 0x52420000
.global lbl_803E0D6C
lbl_803E0D6C:
	.4byte 0x00000000
.global lbl_803E0D70
lbl_803E0D70:
	.4byte 0x00000000
.global lbl_803E0D74
lbl_803E0D74:
	.4byte 0x00000000
.global lbl_803E0D78
lbl_803E0D78:
	.4byte 0x44524F57
	.4byte 0x4E000000
.global lbl_803E0D80
lbl_803E0D80:
	.4byte 0x00000000
.global lbl_803E0D84
lbl_803E0D84:
	.4byte 0x00000000
.global lbl_803E0D88
lbl_803E0D88:
	.4byte 0x00000000
.global lbl_803E0D8C
lbl_803E0D8C:
	.4byte 0x00000000
.global lbl_803E0D90
lbl_803E0D90:
	.4byte 0x00000000
.global lbl_803E0D94
lbl_803E0D94:
	.4byte 0x00000000
.global lbl_803E0D98
lbl_803E0D98:
	.4byte 0x00000000
.global lbl_803E0D9C
lbl_803E0D9C:
	.4byte 0x00000000
.global lbl_803E0DA0
lbl_803E0DA0:
	.4byte 0x00000000
.global lbl_803E0DA4
lbl_803E0DA4:
	.4byte 0x00000000
.global lbl_803E0DA8
lbl_803E0DA8:
	.4byte 0x00000000
.global lbl_803E0DAC
lbl_803E0DAC:
	.4byte 0x00000000
.global lbl_803E0DB0
lbl_803E0DB0:
	.4byte 0x00000000
.global lbl_803E0DB4
lbl_803E0DB4:
	.4byte 0x4B494E4F
	.4byte 0x4B4F0000
.global lbl_803E0DBC
lbl_803E0DBC:
	.4byte 0x00000000
.global lbl_803E0DC0
lbl_803E0DC0:
	.4byte 0x00000000
.global lbl_803E0DC4
lbl_803E0DC4:
	.4byte 0x00000000
.global lbl_803E0DC8
lbl_803E0DC8:
	.4byte 0x00000000
.global lbl_803E0DCC
lbl_803E0DCC:
	.4byte 0x00000000
.global lbl_803E0DD0
lbl_803E0DD0:
	.4byte 0x00000000
.global lbl_803E0DD4
lbl_803E0DD4:
	.4byte 0x00000000
.global lbl_803E0DD8
lbl_803E0DD8:
	.4byte 0x00000000
.global lbl_803E0DDC
lbl_803E0DDC:
	.4byte 0x00000000
.global lbl_803E0DE0
lbl_803E0DE0:
	.4byte 0x00000000
.global lbl_803E0DE4
lbl_803E0DE4:
	.4byte 0x00000000
.global lbl_803E0DE8
lbl_803E0DE8:
	.4byte 0x3C23D70A
.global lbl_803E0DEC
lbl_803E0DEC:
	.4byte 0x3F7D70A4
.global lbl_803E0DF0
lbl_803E0DF0:
	.4byte 0x3ECCCCCD
.global lbl_803E0DF4
lbl_803E0DF4:
	.4byte 0x3F000000
.global lbl_803E0DF8
lbl_803E0DF8:
	.4byte 0x3DCCCCCD
.global lbl_803E0DFC
lbl_803E0DFC:
	.4byte 0x42554242
	.4byte 0x4C450000
.global lbl_803E0E04
lbl_803E0E04:
	.4byte 0x46495245
	.4byte 0x44000000
.global lbl_803E0E0C
lbl_803E0E0C:
	.4byte 0x42554C4C
	.4byte 0x45540000
.global lbl_803E0E14
lbl_803E0E14:
	.4byte 0x464C4943
	.4byte 0x4B000000
.global lbl_803E0E1C
lbl_803E0E1C:
	.4byte 0x00000000
.global lbl_803E0E20
lbl_803E0E20:
	.4byte 0x00000000
.global lbl_803E0E24
lbl_803E0E24:
	.4byte 0x00000000
.global lbl_803E0E28
lbl_803E0E28:
	.4byte 0x00000000
.global lbl_803E0E2C
lbl_803E0E2C:
	.4byte 0x00000000
.global lbl_803E0E30
lbl_803E0E30:
	.4byte 0x00000000
.global lbl_803E0E34
lbl_803E0E34:
	.4byte 0x00000000
.global lbl_803E0E38
lbl_803E0E38:
	.float 1.0
.global lbl_803E0E3C
lbl_803E0E3C:
	.4byte 0x00000000
.global lbl_803E0E40
lbl_803E0E40:
	.4byte 0x464C4F57
	.4byte 0x4E000000
.global lbl_803E0E48
lbl_803E0E48:
	.4byte 0x00000000
.global lbl_803E0E4C
lbl_803E0E4C:
	.4byte 0x00000000
.global lbl_803E0E50
lbl_803E0E50:
	.4byte 0x00000000
.global lbl_803E0E54
lbl_803E0E54:
	.4byte 0x00000000
.global lbl_803E0E58
lbl_803E0E58:
	.4byte 0x00000000
.global lbl_803E0E5C
lbl_803E0E5C:
	.4byte 0x00000000
.global lbl_803E0E60
lbl_803E0E60:
	.4byte 0x00000000
.global lbl_803E0E64
lbl_803E0E64:
	.float 1.0
.global lbl_803E0E68
lbl_803E0E68:
	.4byte 0x00000000
.global lbl_803E0E6C
lbl_803E0E6C:
	.4byte 0x44070000
.global lbl_803E0E70
lbl_803E0E70:
	.4byte 0x46414C4C
	.4byte 0x00000000
.global lbl_803E0E78
lbl_803E0E78:
	.4byte 0x434C4946
	.4byte 0x46000000
.global lbl_803E0E80
lbl_803E0E80:
	.4byte 0x00000000
.global lbl_803E0E84
lbl_803E0E84:
	.4byte 0x00000000
.global lbl_803E0E88
lbl_803E0E88:
	.4byte 0x00000000
.global lbl_803E0E8C
lbl_803E0E8C:
	.4byte 0x00000000
.global lbl_803E0E90
lbl_803E0E90:
	.4byte 0x474F4841
	.4byte 0x4E470000
.global lbl_803E0E98
lbl_803E0E98:
	.4byte 0x48414E47
	.4byte 0x45440000
.global lbl_803E0EA0
lbl_803E0EA0:
	.4byte 0x00000000
.global lbl_803E0EA4
lbl_803E0EA4:
	.4byte 0x00000000
.global lbl_803E0EA8
lbl_803E0EA8:
	.4byte 0x00000000
.global lbl_803E0EAC
lbl_803E0EAC:
	.4byte 0x00000000
.global lbl_803E0EB0
lbl_803E0EB0:
	.4byte 0x00000000
.global lbl_803E0EB4
lbl_803E0EB4:
	.4byte 0x00000000
.global lbl_803E0EB8
lbl_803E0EB8:
	.4byte 0x00000000
.global lbl_803E0EBC
lbl_803E0EBC:
	.4byte 0x00000000
.global lbl_803E0EC0
lbl_803E0EC0:
	.4byte 0x00000000
.global lbl_803E0EC4
lbl_803E0EC4:
	.4byte 0x00000000
.global lbl_803E0EC8
lbl_803E0EC8:
	.4byte 0x00000000
.global lbl_803E0ECC
lbl_803E0ECC:
	.4byte 0x00000000
.global lbl_803E0ED0
lbl_803E0ED0:
	.4byte 0x454D4954
	.4byte 0x00000000
.global lbl_803E0ED8
lbl_803E0ED8:
	.4byte 0x00000000
.global lbl_803E0EDC
lbl_803E0EDC:
	.4byte 0x00000000
.global lbl_803E0EE0
lbl_803E0EE0:
	.4byte 0x00000000
.global lbl_803E0EE4
lbl_803E0EE4:
	.4byte 0x00000000
.global lbl_803E0EE8
lbl_803E0EE8:
	.4byte 0x00000000
.global lbl_803E0EEC
lbl_803E0EEC:
	.4byte 0x00000000
.global lbl_803E0EF0
lbl_803E0EF0:
	.4byte 0x464C5949
	.4byte 0x4E470000
.global lbl_803E0EF8
lbl_803E0EF8:
	.4byte 0x47524F57
	.4byte 0x00000000
.global lbl_803E0F00
lbl_803E0F00:
	.4byte 0x00000000
.global lbl_803E0F04
lbl_803E0F04:
	.4byte 0x00000000
.global lbl_803E0F08
lbl_803E0F08:
	.4byte 0x00000000
.global lbl_803E0F0C
lbl_803E0F0C:
	.4byte 0x00000000
.global lbl_803E0F10
lbl_803E0F10:
	.4byte 0x00000000
.global lbl_803E0F14
lbl_803E0F14:
	.4byte 0x00000000
.global lbl_803E0F18
lbl_803E0F18:
	.4byte 0x47524F57
	.4byte 0x55500000
.global lbl_803E0F20
lbl_803E0F20:
	.4byte 0x00000000
.global lbl_803E0F24
lbl_803E0F24:
	.4byte 0x00000000
.global lbl_803E0F28
lbl_803E0F28:
	.4byte 0x00000000
.global lbl_803E0F2C
lbl_803E0F2C:
	.4byte 0x00000000
.global lbl_803E0F30
lbl_803E0F30:
	.4byte 0x00000000
.global lbl_803E0F34
lbl_803E0F34:
	.4byte 0x00000000
.global lbl_803E0F38
lbl_803E0F38:
	.4byte 0x57415645
	.4byte 0x00000000
.global lbl_803E0F40
lbl_803E0F40:
	.4byte 0x50555348
	.4byte 0x00000000
.global lbl_803E0F48
lbl_803E0F48:
	.4byte 0x00000000
.global lbl_803E0F4C
lbl_803E0F4C:
	.4byte 0x42555259
	.4byte 0x00000000
.global lbl_803E0F54
lbl_803E0F54:
	.4byte 0x44070000
.global lbl_803E0F58
lbl_803E0F58:
	.4byte 0x00000000
.global lbl_803E0F5C
lbl_803E0F5C:
	.4byte 0x00000000
.global lbl_803E0F60
lbl_803E0F60:
	.4byte 0x00000000
.global lbl_803E0F64
lbl_803E0F64:
	.4byte 0x00000000
.global lbl_803E0F68
lbl_803E0F68:
	.4byte 0x00000000
.global lbl_803E0F6C
lbl_803E0F6C:
	.4byte 0x00000000
.global lbl_803E0F70
lbl_803E0F70:
	.4byte 0x00000000
.global lbl_803E0F74
lbl_803E0F74:
	.4byte 0x00000000
.global lbl_803E0F78
lbl_803E0F78:
	.4byte 0x00000000
.global lbl_803E0F7C
lbl_803E0F7C:
	.4byte 0x00000000
.global lbl_803E0F80
lbl_803E0F80:
	.4byte 0x00000000
.global lbl_803E0F84
lbl_803E0F84:
	.4byte 0x00000000
.global lbl_803E0F88
lbl_803E0F88:
	.4byte 0x4E554B41
	.4byte 0x52450000
.global lbl_803E0F90
lbl_803E0F90:
	.4byte 0x00000000
.global lbl_803E0F94
lbl_803E0F94:
	.4byte 0x00000000
.global lbl_803E0F98
lbl_803E0F98:
	.4byte 0x00000000
.global lbl_803E0F9C
lbl_803E0F9C:
	.4byte 0x00000000
.global lbl_803E0FA0
lbl_803E0FA0:
	.4byte 0x00000000
.global lbl_803E0FA4
lbl_803E0FA4:
	.4byte 0x00000000
.global lbl_803E0FA8
lbl_803E0FA8:
	.4byte 0x00000000
.global lbl_803E0FAC
lbl_803E0FAC:
	.4byte 0x00000000
.global lbl_803E0FB0
lbl_803E0FB0:
	.4byte 0x00000000
.global lbl_803E0FB4
lbl_803E0FB4:
	.4byte 0x00000000
.global lbl_803E0FB8
lbl_803E0FB8:
	.4byte 0x00000000
.global lbl_803E0FBC
lbl_803E0FBC:
	.4byte 0x00000000
.global lbl_803E0FC0
lbl_803E0FC0:
	.4byte 0x00000000
.global lbl_803E0FC4
lbl_803E0FC4:
	.4byte 0x00000000
.global lbl_803E0FC8
lbl_803E0FC8:
	.4byte 0x00000000
.global lbl_803E0FCC
lbl_803E0FCC:
	.4byte 0x00000000
.global lbl_803E0FD0
lbl_803E0FD0:
	.4byte 0x00000000
.global lbl_803E0FD4
lbl_803E0FD4:
	.4byte 0x00000000
.global lbl_803E0FD8
lbl_803E0FD8:
	.4byte 0x50524553
	.4byte 0x53454400
.global lbl_803E0FE0
lbl_803E0FE0:
	.4byte 0x3C23D70A
.global lbl_803E0FE4
lbl_803E0FE4:
	.4byte 0x00000000
.global lbl_803E0FE8
lbl_803E0FE8:
	.4byte 0x00000000
.global lbl_803E0FEC
lbl_803E0FEC:
	.4byte 0x00000000
.global lbl_803E0FF0
lbl_803E0FF0:
	.4byte 0x00000000
.global lbl_803E0FF4
lbl_803E0FF4:
	.4byte 0x00000000
.global lbl_803E0FF8
lbl_803E0FF8:
	.4byte 0x00000000
.global lbl_803E0FFC
lbl_803E0FFC:
	.4byte 0x4459494E
	.4byte 0x47000000
.global lbl_803E1004
lbl_803E1004:
	.4byte 0x00000000
.global lbl_803E1008
lbl_803E1008:
	.4byte 0x00000000
.global lbl_803E100C
lbl_803E100C:
	.4byte 0x00000000
.global lbl_803E1010
lbl_803E1010:
	.4byte 0x00000000
.global lbl_803E1014
lbl_803E1014:
	.4byte 0x00000000
.global lbl_803E1018
lbl_803E1018:
	.4byte 0x00000000
.global lbl_803E101C
lbl_803E101C:
	.4byte 0x44454144
	.4byte 0x00000000
.global lbl_803E1024
lbl_803E1024:
	.4byte 0x00000000
.global lbl_803E1028
lbl_803E1028:
	.4byte 0x00000000
.global lbl_803E102C
lbl_803E102C:
	.4byte 0x00000000
.global lbl_803E1030
lbl_803E1030:
	.4byte 0x00000000
.global lbl_803E1034
lbl_803E1034:
	.4byte 0x00000000
.global lbl_803E1038
lbl_803E1038:
	.4byte 0x00000000
.global lbl_803E103C
lbl_803E103C:
	.4byte 0x00000000
.global lbl_803E1040
lbl_803E1040:
	.4byte 0x00000000
.global lbl_803E1044
lbl_803E1044:
	.4byte 0x00000000
.global lbl_803E1048
lbl_803E1048:
	.4byte 0x454D4F54
	.4byte 0x494F4E00
.global lbl_803E1050
lbl_803E1050:
	.4byte 0x00000000
.global lbl_803E1054
lbl_803E1054:
	.4byte 0x00000000
.global lbl_803E1058
lbl_803E1058:
	.4byte 0x00000000
	.4byte 0x802B8D80
	.4byte 0x00000000
.global "__RTTI__13AState<4Piki>"
"__RTTI__13AState<4Piki>":
	.4byte 0x802B8D90
	.4byte 0x802B8DA0
.global __RTTI__9PikiState
__RTTI__9PikiState:
	.4byte 0x802B8DAC
	.4byte 0x802B8DB8
.global __RTTI__16PikiEmotionState
__RTTI__16PikiEmotionState:
	.4byte 0x802B8D6C
	.4byte 0x802B8DCC
.global __RTTI__13PikiDeadState
__RTTI__13PikiDeadState:
	.4byte 0x802B8E54
	.4byte 0x802B8E64
.global __RTTI__14PikiDyingState
__RTTI__14PikiDyingState:
	.4byte 0x802B8EEC
	.4byte 0x802B8EFC
.global __RTTI__16PikiPressedState
__RTTI__16PikiPressedState:
	.4byte 0x802B8F84
	.4byte 0x802B8F98
.global __RTTI__17PikiAutoNukiState
__RTTI__17PikiAutoNukiState:
	.4byte 0x802B9020
	.4byte 0x802B9034
.global __RTTI__15PikiNukareState
__RTTI__15PikiNukareState:
	.4byte 0x802B90BC
	.4byte 0x802B90CC
.global __RTTI__19PikiNukareWaitState
__RTTI__19PikiNukareWaitState:
	.4byte 0x802B9154
	.4byte 0x802B9168
.global __RTTI__13PikiBuryState
__RTTI__13PikiBuryState:
	.4byte 0x802B91F0
	.4byte 0x802B9200
.global __RTTI__17PikiPushPikiState
__RTTI__17PikiPushPikiState:
	.4byte 0x802B9288
	.4byte 0x802B929C
.global __RTTI__13PikiPushState
__RTTI__13PikiPushState:
	.4byte 0x802B9324
	.4byte 0x802B9334
.global __RTTI__13PikiWaveState
__RTTI__13PikiWaveState:
	.4byte 0x802B93BC
	.4byte 0x802B93CC
.global __RTTI__15PikiGrowupState
__RTTI__15PikiGrowupState:
	.4byte 0x802B9454
	.4byte 0x802B9464
.global __RTTI__21PikiKinokoChangeState
__RTTI__21PikiKinokoChangeState:
	.4byte 0x802B94EC
	.4byte 0x802B9504
.global __RTTI__13PikiGrowState
__RTTI__13PikiGrowState:
	.4byte 0x802B958C
	.4byte 0x802B959C
.global __RTTI__15PikiFlyingState
__RTTI__15PikiFlyingState:
	.4byte 0x802B9624
	.4byte 0x802B9634
.global __RTTI__13PikiEmitState
__RTTI__13PikiEmitState:
	.4byte 0x802B96BC
	.4byte 0x802B96CC
.global __RTTI__20PikiWaterHangedState
__RTTI__20PikiWaterHangedState:
	.4byte 0x802B9754
	.4byte 0x802B976C
.global __RTTI__15PikiHangedState
__RTTI__15PikiHangedState:
	.4byte 0x802B97F4
	.4byte 0x802B9804
.global __RTTI__15PikiGoHangState
__RTTI__15PikiGoHangState:
	.4byte 0x802B988C
	.4byte 0x802B989C
.global __RTTI__14PikiCliffState
__RTTI__14PikiCliffState:
	.4byte 0x802B9924
	.4byte 0x802B9934
.global __RTTI__13PikiFallState
__RTTI__13PikiFallState:
	.4byte 0x802B99BC
	.4byte 0x802B99CC
.global __RTTI__17PikiFallMeckState
__RTTI__17PikiFallMeckState:
	.4byte 0x802B9A54
	.4byte 0x802B9A68
.global __RTTI__14PikiFlownState
__RTTI__14PikiFlownState:
	.4byte 0x802B9AF0
	.4byte 0x802B9B00
.global __RTTI__14PikiFlickState
__RTTI__14PikiFlickState:
	.4byte 0x802B9B88
	.4byte 0x802B9B98
.global __RTTI__15PikiBulletState
__RTTI__15PikiBulletState:
	.4byte 0x802B9C20
	.4byte 0x802B9C30
.global __RTTI__18PikiSwallowedState
__RTTI__18PikiSwallowedState:
	.4byte 0x802B9CB8
	.4byte 0x802B9CCC
.global __RTTI__14PikiFiredState
__RTTI__14PikiFiredState:
	.4byte 0x802B9D54
	.4byte 0x802B9D64
.global __RTTI__15PikiBubbleState
__RTTI__15PikiBubbleState:
	.4byte 0x802B9DEC
	.4byte 0x802B9DFC
.global __RTTI__15PikiKinokoState
__RTTI__15PikiKinokoState:
	.4byte 0x802B9E84
	.4byte 0x802B9E94
.global __RTTI__14PikiDrownState
__RTTI__14PikiDrownState:
	.4byte 0x802B9F54
	.4byte 0x802B9F64
.global __RTTI__15PikiAbsorbState
__RTTI__15PikiAbsorbState:
	.4byte 0x802B9FEC
	.4byte 0x802B9FFC
.global __RTTI__15PikiNormalState
__RTTI__15PikiNormalState:
	.4byte 0x802BA084
	.4byte 0x802BA094
.global __RTTI__15PikiLookAtState
__RTTI__15PikiLookAtState:
	.4byte 0x802BA11C
	.4byte 0x802BA12C
.global "__RTTI__19StateMachine<4Piki>_1"
"__RTTI__19StateMachine<4Piki>_1":
	.4byte 0x802BA2BC
	.4byte 0
.global __RTTI__16PikiStateMachine
__RTTI__16PikiStateMachine:
	.4byte 0x802BA2A8
	.4byte 0x802BA2D0
	.4byte 0
.global firstTime__15PikiShapeObject
firstTime__15PikiShapeObject:
	.4byte 0x01000000
.global lbl_803E1194
lbl_803E1194:
	.float 1.0
.global lbl_803E1198
lbl_803E1198:
	.float 1.0
.global lbl_803E119C
lbl_803E119C:
	.float 1.0
.global lbl_803E11A0
lbl_803E11A0:
	.4byte 0x00000000
.global lbl_803E11A4
lbl_803E11A4:
	.4byte 0x00000000
.global lbl_803E11A8
lbl_803E11A8:
	.4byte 0x00000000
.global lbl_803E11AC
lbl_803E11AC:
	.4byte 0x00000000
.global lbl_803E11B0
lbl_803E11B0:
	.4byte 0x00000000
.global lbl_803E11B4
lbl_803E11B4:
	.4byte 0x00000000
.global lbl_803E11B8
lbl_803E11B8:
	.4byte 0x00000000
.global lbl_803E11BC
lbl_803E11BC:
	.4byte 0x00000000
.global lbl_803E11C0
lbl_803E11C0:
	.4byte 0x00000000
.global lbl_803E11C4
lbl_803E11C4:
	.4byte 0x00000000
.global lbl_803E11C8
lbl_803E11C8:
	.4byte 0x00000000
.global lbl_803E11CC
lbl_803E11CC:
	.4byte 0x00000000
.global lbl_803E11D0
lbl_803E11D0:
	.4byte 0x00000000
.global lbl_803E11D4
lbl_803E11D4:
	.4byte 0x00000000
.global lbl_803E11D8
lbl_803E11D8:
	.4byte 0x00000000
.global lbl_803E11DC
lbl_803E11DC:
	.4byte 0x00000000
.global lbl_803E11E0
lbl_803E11E0:
	.float 1.0
.global lbl_803E11E4
lbl_803E11E4:
	.4byte 0x00000000
.global lbl_803E11E8
lbl_803E11E8:
	.4byte 0x00000000
.global lbl_803E11EC
lbl_803E11EC:
	.4byte 0x00000000
.global lbl_803E11F0
lbl_803E11F0:
	.4byte 0x00000000
.global lbl_803E11F4
lbl_803E11F4:
	.4byte 0x40800000
.global lbl_803E11F8
lbl_803E11F8:
	.4byte 0x00000000
.global lbl_803E11FC
lbl_803E11FC:
	.4byte 0x40800000
.global lbl_803E1200
lbl_803E1200:
	.4byte 0x00000000
.global lbl_803E1204
lbl_803E1204:
	.4byte 0x00000000
.global lbl_803E1208
lbl_803E1208:
	.4byte 0x40400000
.global lbl_803E120C
lbl_803E120C:
	.4byte 0x00000000
.global lbl_803E1210
lbl_803E1210:
	.4byte 0x00000000
.global lbl_803E1214
lbl_803E1214:
	.4byte 0x40C00000
.global lbl_803E1218
lbl_803E1218:
	.4byte 0x00000000
.global lbl_803E121C
lbl_803E121C:
	.4byte 0x00000000
.global lbl_803E1220
lbl_803E1220:
	.asciz "A"
.balign 4
.global lbl_803E1224
lbl_803E1224:
	.asciz "B"
.balign 4
.global lbl_803E1228
lbl_803E1228:
	.asciz "C"
.balign 4
.global lbl_803E122C
lbl_803E122C:
	.asciz "D"
.balign 4
.global lbl_803E1230
lbl_803E1230:
	.asciz "E"
.balign 4
.global lbl_803E1234
lbl_803E1234:
	.asciz "F"
.balign 4
.global lbl_803E1238
lbl_803E1238:
	.asciz "%s%d"
.balign 4
.global lbl_803E1240
lbl_803E1240:
	.4byte 0x00000000
.global lbl_803E1244
lbl_803E1244:
	.4byte 0x00000000
.global lbl_803E1248
lbl_803E1248:
	.4byte 0x3FC90FDB
.global lbl_803E124C
lbl_803E124C:
	.4byte 0x00000000
.global lbl_803E1250
lbl_803E1250:
	.4byte 0x00000000
.global lbl_803E1254
lbl_803E1254:
	.4byte 0x00000000
	.4byte 0x802BA3C8
	.4byte 0x00000000
	.4byte 0x802BA3DC
	.4byte 0x00000000
	.4byte 0x802BA3E8
	.4byte 0x00000000
	.4byte 0x802BA3F8
	.4byte 0x802BA404
	.4byte 0x50696B69
	.4byte 0x00000000
.global __RTTI__4Piki_1
__RTTI__4Piki_1:
	.4byte 0x803E1278
	.4byte 0x802BA418
.global __RTTI__8ViewPiki
__RTTI__8ViewPiki:
	.4byte 0x802BA3BC
	.4byte 0x802BA43C
	.4byte 0x802BA5B0
	.4byte 0
.global __RTTI__13CndStickMouth
__RTTI__13CndStickMouth:
	.4byte 0x802BA5A0
	.4byte 0x802BA5BC
.global __RTTI__10CndIsAtari
__RTTI__10CndIsAtari:
	.4byte 0x802BA5D4
	.4byte 0x802BA5E0
.global __RTTI__12CndIsVisible
__RTTI__12CndIsVisible:
	.4byte 0x802BA5F8
	.4byte 0x802BA608
.global lbl_803E12B0
lbl_803E12B0:
	.4byte 0x70303000
.global lbl_803E12B4
lbl_803E12B4:
	.4byte 0x70303100
.global lbl_803E12B8
lbl_803E12B8:
	.4byte 0x62303000
.global lbl_803E12BC
lbl_803E12BC:
	.4byte 0x62303100
.global lbl_803E12C0
lbl_803E12C0:
	.4byte 0x70303200
.global lbl_803E12C4
lbl_803E12C4:
	.4byte 0x00000000
.global lbl_803E12C8
lbl_803E12C8:
	.4byte 0x00000000
.global lbl_803E12CC
lbl_803E12CC:
	.4byte 0x00000000
.global lbl_803E12D0
lbl_803E12D0:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803E12D8
lbl_803E12D8:
	.4byte 0x756E7365
	.4byte 0x74000000
.global lbl_803E12E0
lbl_803E12E0:
	.4byte 0x00000000
.global lbl_803E12E4
lbl_803E12E4:
	.4byte 0x00000000
.global lbl_803E12E8
lbl_803E12E8:
	.4byte 0x00000000
.global lbl_803E12EC
lbl_803E12EC:
	.4byte 0x00000000
.global lbl_803E12F0
lbl_803E12F0:
	.4byte 0x00000000
.global lbl_803E12F4
lbl_803E12F4:
	.4byte 0x00000000
.global lbl_803E12F8
lbl_803E12F8:
	.4byte 0x00000000
	.4byte 0x82C882B5
	.4byte 0x00000000
	.4byte 0x8FED82C9
	.4byte 0x00000000
.global lbl_803E130C
lbl_803E130C:
	.4byte 0x00000000
.global lbl_803E1310
lbl_803E1310:
	.4byte 0x00000000
.global lbl_803E1314
lbl_803E1314:
	.4byte 0x00000000
.global lbl_803E1318
lbl_803E1318:
	.4byte 0x00000000
.global lbl_803E131C
lbl_803E131C:
	.4byte 0x00000000
.global lbl_803E1320
lbl_803E1320:
	.4byte 0x00000000
.global lbl_803E1324
lbl_803E1324:
	.4byte 0x67656E4D
	.4byte 0x67720000
.global lbl_803E132C
lbl_803E132C:
	.4byte 0x00000000
.global lbl_803E1330
lbl_803E1330:
	.4byte 0x00000000
.global lbl_803E1334
lbl_803E1334:
	.4byte 0x00000000
.global lbl_803E1338
lbl_803E1338:
	.4byte 0x00000000
.global lbl_803E133C
lbl_803E133C:
	.4byte 0x00000000
.global lbl_803E1340
lbl_803E1340:
	.4byte 0x00000000
.global lbl_803E1344
lbl_803E1344:
	.4byte 0x00000000
.global lbl_803E1348
lbl_803E1348:
	.float 1.0
.global lbl_803E134C
lbl_803E134C:
	.4byte 0x00000000
.global lbl_803E1350
lbl_803E1350:
	.4byte 0x00000000
.global lbl_803E1354
lbl_803E1354:
	.4byte 0x00000000
	.4byte 0x802BA738
	.4byte 0x00000000
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803E1360
	.4byte 0x802BA744
	.4byte 0x47656E41
	.4byte 0x72656100
.global __RTTI__7GenArea
__RTTI__7GenArea:
	.4byte 0x803E1370
	.4byte 0x802BA750
.global __RTTI__13GenAreaCircle
__RTTI__13GenAreaCircle:
	.4byte 0x802BA728
	.4byte 0x802BA764
.global __RTTI__12GenAreaPoint
__RTTI__12GenAreaPoint:
	.4byte 0x802BA7B8
	.4byte 0x802BA7C8
	.4byte 0x47656E54
	.4byte 0x79706500
.global __RTTI__7GenType
__RTTI__7GenType:
	.4byte 0x803E1390
	.4byte 0x802BA82C
.global __RTTI__15GenTypeInitRand
__RTTI__15GenTypeInitRand:
	.4byte 0x802BA81C
	.4byte 0x802BA840
.global __RTTI__13GenTypeAtOnce
__RTTI__13GenTypeAtOnce:
	.4byte 0x802BA894
	.4byte 0x802BA8A4
.global __RTTI__10GenTypeOne
__RTTI__10GenTypeOne:
	.4byte 0x802BA8F8
	.4byte 0x802BA904
	.4byte 0x802BA968
	.4byte 0x802BA974
.global __RTTI__13GenObjectPiki
__RTTI__13GenObjectPiki:
	.4byte 0x802BA958
	.4byte 0x802BA988
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E13C8
	.4byte 0
	.4byte 0x802BA9DC
	.4byte 0x802BA9E8
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803E13E0
	.4byte 0x802BA9F4
.global __RTTI__12GeneratorMgr
__RTTI__12GeneratorMgr:
	.4byte 0x802BA718
	.4byte 0x802BAA08
.global __RTTI__9Generator
__RTTI__9Generator:
	.4byte 0x802BAA54
	.4byte 0x802BAA60
	.4byte 0x802BAB0C
	.4byte 0
.global lbl_803E1408
lbl_803E1408:
	.4byte 0x00000000
	.4byte 0x53747265
	.4byte 0x616D0000
	.4byte 0x803E140C
	.4byte 0x00000000
	.4byte 0x802BAC34
	.4byte 0x802BAC48
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E1424
	.4byte 0x00000000
	.4byte 0x802BAC1C
	.4byte 0x802BAD4C
.global __RTTI__Q214GeneratorCache5Cache
__RTTI__Q214GeneratorCache5Cache:
	.4byte 0x802BAD34
	.4byte 0x802BAD58
	.4byte 0
.global lbl_803E1448
lbl_803E1448:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E1450
	.4byte 0x00000000
	.4byte 0x802BADC4
	.4byte 0x802BADD0
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803E1468
	.4byte 0x802BADDC
	.4byte 0x802BADF0
	.4byte 0x00000000
	.4byte 0x802BADFC
	.4byte 0x802BAE08
.global __RTTI__15CreatureNodeMgr
__RTTI__15CreatureNodeMgr:
	.4byte 0x802BADB4
	.4byte 0x802BAE2C
.global __RTTI__13PolyObjectMgr
__RTTI__13PolyObjectMgr:
	.4byte 0x802BAED0
	.4byte 0x802BAEE0
	.4byte 0x802BAF8C
	.4byte 0x802BAF9C
	.4byte 0x802BB128
	.4byte 0
.global __RTTI__12SearchBuffer
__RTTI__12SearchBuffer:
	.4byte 0x802BB118
	.4byte 0x802BB134
	.4byte 0x802BB18C
	.4byte 0
.global lbl_803E14B8
lbl_803E14B8:
	.4byte 0x41700000
.global lbl_803E14BC
lbl_803E14BC:
	.4byte 0x41700000
.global lbl_803E14C0
lbl_803E14C0:
	.4byte 0x00000000
.global lbl_803E14C4
lbl_803E14C4:
	.float 1.0
.global lbl_803E14C8
lbl_803E14C8:
	.float 1.0
.global lbl_803E14CC
lbl_803E14CC:
	.float 1.0
.global lbl_803E14D0
lbl_803E14D0:
	.4byte 0x00000000
.global lbl_803E14D4
lbl_803E14D4:
	.4byte 0x00000000
.global lbl_803E14D8
lbl_803E14D8:
	.4byte 0x00000000
.global lbl_803E14DC
lbl_803E14DC:
	.float 1.0
.global lbl_803E14E0
lbl_803E14E0:
	.float 1.0
.global lbl_803E14E4
lbl_803E14E4:
	.float 1.0
.global lbl_803E14E8
lbl_803E14E8:
	.4byte 0x00000000
.global lbl_803E14EC
lbl_803E14EC:
	.4byte 0x00000000
.global lbl_803E14F0
lbl_803E14F0:
	.4byte 0x00000000
.global lbl_803E14F4
lbl_803E14F4:
	.4byte 0x3DCCCCCD
.global lbl_803E14F8
lbl_803E14F8:
	.4byte 0x3DCCCCCD
.global lbl_803E14FC
lbl_803E14FC:
	.4byte 0x3DCCCCCD
.global lbl_803E1500
lbl_803E1500:
	.4byte 0x43B90000
	.4byte 0x57656564
	.4byte 0x00000000
	.4byte 0x802BB250
	.4byte 0x00000000
	.4byte 0x802BB264
	.4byte 0x00000000
	.4byte 0x802BB270
	.4byte 0x00000000
	.4byte 0x802BB280
	.4byte 0x802BB28C
	.4byte 0x802BB2A0
	.4byte 0x802BB2AC
	.4byte 0x802BB2D0
	.4byte 0x802BB2E0
.global __RTTI__4Weed
__RTTI__4Weed:
	.4byte 0x803E1504
	.4byte 0x802BB30C
.global __RTTI__8WeedsGen
__RTTI__8WeedsGen:
	.4byte 0x802BB49C
	.4byte 0x802BB4A8
.global __RTTI__8GrassGen
__RTTI__8GrassGen:
	.4byte 0x802BB638
	.4byte 0x802BB644
	.4byte 0x526F636B
	.4byte 0x47656E00
.global __RTTI__7RockGen
__RTTI__7RockGen:
	.4byte 0x803E1554
	.4byte 0x802BB7D4
	.4byte 0
.global lbl_803E1568
lbl_803E1568:
	.float 1.0
.global lbl_803E156C
lbl_803E156C:
	.float 1.0
.global lbl_803E1570
lbl_803E1570:
	.float 1.0
.global lbl_803E1574
lbl_803E1574:
	.float 1.0
.global lbl_803E1578
lbl_803E1578:
	.float 1.0
.global lbl_803E157C
lbl_803E157C:
	.float 1.0
.global lbl_803E1580
lbl_803E1580:
	.4byte 0x00000000
.global lbl_803E1584
lbl_803E1584:
	.4byte 0x00000000
.global lbl_803E1588
lbl_803E1588:
	.4byte 0x00000000
.global lbl_803E158C
lbl_803E158C:
	.4byte 0x00000000
.global lbl_803E1590
lbl_803E1590:
	.4byte 0x00000000
.global lbl_803E1594
lbl_803E1594:
	.float 1.0
.global lbl_803E1598
lbl_803E1598:
	.float 1.0
.global lbl_803E159C
lbl_803E159C:
	.float 1.0
	.4byte 0x802BB984
	.4byte 0x00000000
	.4byte 0x802BB998
	.4byte 0x00000000
	.4byte 0x802BB9A4
	.4byte 0x00000000
	.4byte 0x802BB9B4
	.4byte 0x802BB9C0
	.4byte 0x802BB9D4
	.4byte 0x802BB9E0
	.4byte 0x802BBA04
	.4byte 0x802BBA14
.global __RTTI__10BoBaseItem
__RTTI__10BoBaseItem:
	.4byte 0x802BB978
	.4byte 0x802BBA40
.global __RTTI__8KusaItem
__RTTI__8KusaItem:
	.4byte 0x802BBBD0
	.4byte 0x802BBBDC
.global lbl_803E15E0
lbl_803E15E0:
	.4byte 0x40800000
.global lbl_803E15E4
lbl_803E15E4:
	.4byte 0x00000000
.global lbl_803E15E8
lbl_803E15E8:
	.4byte 0x00000000
.global lbl_803E15EC
lbl_803E15EC:
	.4byte 0x00000000
.global lbl_803E15F0
lbl_803E15F0:
	.4byte 0x00000000
.global lbl_803E15F4
lbl_803E15F4:
	.4byte 0x00000000
.global lbl_803E15F8
lbl_803E15F8:
	.4byte 0x00000000
.global lbl_803E15FC
lbl_803E15FC:
	.4byte 0x00000000
.global lbl_803E1600
lbl_803E1600:
	.4byte 0x00000000
.global lbl_803E1604
lbl_803E1604:
	.4byte 0x00000000
.global lbl_803E1608
lbl_803E1608:
	.4byte 0x00000000
.global lbl_803E160C
lbl_803E160C:
	.4byte 0x00000000
.global lbl_803E1610
lbl_803E1610:
	.4byte 0x00000000
.global lbl_803E1614
lbl_803E1614:
	.4byte 0x42C80000
.global lbl_803E1618
lbl_803E1618:
	.4byte 0x42C80000
.global lbl_803E161C
lbl_803E161C:
	.4byte 0x3ECCCCCD
.global lbl_803E1620
lbl_803E1620:
	.4byte 0x3E4CCCCD
.global lbl_803E1624
lbl_803E1624:
	.4byte 0x3ECCCCCD
.global lbl_803E1628
lbl_803E1628:
	.4byte 0x42C80000
.global lbl_803E162C
lbl_803E162C:
	.4byte 0x00000000
.global lbl_803E1630
lbl_803E1630:
	.4byte 0x42C80000
.global lbl_803E1634
lbl_803E1634:
	.4byte 0x3F666666
.global lbl_803E1638
lbl_803E1638:
	.4byte 0x3DCCCCCD
	.4byte 0x802BBD90
	.4byte 0x00000000
	.4byte 0x802BBDA4
	.4byte 0x00000000
	.4byte 0x802BBDB0
	.4byte 0x00000000
	.4byte 0x802BBDC0
	.4byte 0x802BBDCC
	.4byte 0x802BBDE0
	.4byte 0x802BBDEC
	.4byte 0x802BBE10
	.4byte 0x802BBE20
.global __RTTI__13FishGenerator
__RTTI__13FishGenerator:
	.4byte 0x802BBD80
	.4byte 0x802BBE4C
	.4byte 0
.global numKeys
numKeys:
	.4byte 0x00000003
.global lbl_803E167C
lbl_803E167C:
	.4byte 0x00000000
.global lbl_803E1680
lbl_803E1680:
	.4byte 0x00000000
.global lbl_803E1684
lbl_803E1684:
	.float 1.0
.global lbl_803E1688
lbl_803E1688:
	.4byte 0x00000000
.global lbl_803E168C
lbl_803E168C:
	.4byte 0x00000000
.global lbl_803E1690
lbl_803E1690:
	.float 1.0
.global lbl_803E1694
lbl_803E1694:
	.4byte 0x00000000
.global lbl_803E1698
lbl_803E1698:
	.4byte 0x00000000
.global lbl_803E169C
lbl_803E169C:
	.float 1.0
.global lbl_803E16A0
lbl_803E16A0:
	.float 1.0
.global lbl_803E16A4
lbl_803E16A4:
	.4byte 0x00000000
.global lbl_803E16A8
lbl_803E16A8:
	.4byte 0x00000000
.global lbl_803E16AC
lbl_803E16AC:
	.float 1.0
.global lbl_803E16B0
lbl_803E16B0:
	.4byte 0x00000000
.global lbl_803E16B4
lbl_803E16B4:
	.4byte 0x00000000
.global lbl_803E16B8
lbl_803E16B8:
	.4byte 0x00000000
.global lbl_803E16BC
lbl_803E16BC:
	.float 1.0
.global lbl_803E16C0
lbl_803E16C0:
	.4byte 0x00000000
.global lbl_803E16C4
lbl_803E16C4:
	.4byte 0x00000000
.global lbl_803E16C8
lbl_803E16C8:
	.float 1.0
.global lbl_803E16CC
lbl_803E16CC:
	.float 1.0
.global lbl_803E16D0
lbl_803E16D0:
	.float 1.0
.global lbl_803E16D4
lbl_803E16D4:
	.4byte 0x00000000
.global lbl_803E16D8
lbl_803E16D8:
	.4byte 0x00000000
.global lbl_803E16DC
lbl_803E16DC:
	.4byte 0x00000000
.global lbl_803E16E0
lbl_803E16E0:
	.float 1.0
.global lbl_803E16E4
lbl_803E16E4:
	.4byte 0x00000000
.global lbl_803E16E8
lbl_803E16E8:
	.4byte 0x00000000
.global lbl_803E16EC
lbl_803E16EC:
	.4byte 0x00000000
.global lbl_803E16F0
lbl_803E16F0:
	.float 1.0
.global lbl_803E16F4
lbl_803E16F4:
	.4byte 0x00000000
.global lbl_803E16F8
lbl_803E16F8:
	.4byte 0x00000000
.global lbl_803E16FC
lbl_803E16FC:
	.float 1.0
.global lbl_803E1700
lbl_803E1700:
	.4byte 0x00000000
.global lbl_803E1704
lbl_803E1704:
	.4byte 0xBF800000
.global lbl_803E1708
lbl_803E1708:
	.4byte 0x00000000
.global lbl_803E170C
lbl_803E170C:
	.4byte 0x00000000
.global lbl_803E1710
lbl_803E1710:
	.4byte 0x00000000
.global lbl_803E1714
lbl_803E1714:
	.float 1.0
.global lbl_803E1718
lbl_803E1718:
	.4byte 0x00000000
.global lbl_803E171C
lbl_803E171C:
	.4byte 0x00000000
.global lbl_803E1720
lbl_803E1720:
	.float 1.0
.global lbl_803E1724
lbl_803E1724:
	.4byte 0x00000000
.global lbl_803E1728
lbl_803E1728:
	.4byte 0x00000000
.global lbl_803E172C
lbl_803E172C:
	.4byte 0x41600000
.global lbl_803E1730
lbl_803E1730:
	.4byte 0x00000000
.global lbl_803E1734
lbl_803E1734:
	.4byte 0x00000000
.global lbl_803E1738
lbl_803E1738:
	.4byte 0x41600000
.global lbl_803E173C
lbl_803E173C:
	.4byte 0x00000000
.global lbl_803E1740
lbl_803E1740:
	.4byte 0x4151999A
.global lbl_803E1744
lbl_803E1744:
	.4byte 0xC2C4CCCD
.global lbl_803E1748
lbl_803E1748:
	.4byte 0xC0000000
.global lbl_803E174C
lbl_803E174C:
	.4byte 0xC1133333
.global lbl_803E1750
lbl_803E1750:
	.4byte 0xC2883333
.global lbl_803E1754
lbl_803E1754:
	.4byte 0x41E4CCCD
.global lbl_803E1758
lbl_803E1758:
	.4byte 0xC1B1999A
.global lbl_803E175C
lbl_803E175C:
	.4byte 0x409CCCCD
.global lbl_803E1760
lbl_803E1760:
	.4byte 0xC1C80000
.global lbl_803E1764
lbl_803E1764:
	.4byte 0x00000000
.global lbl_803E1768
lbl_803E1768:
	.4byte 0xC2BA0000
.global lbl_803E176C
lbl_803E176C:
	.4byte 0x00000000
.global lbl_803E1770
lbl_803E1770:
	.4byte 0x00000000
	.4byte 0x802BC090
	.4byte 0x00000000
	.4byte 0x802BC0A4
	.4byte 0x00000000
	.4byte 0x802BC0B0
	.4byte 0x00000000
	.4byte 0x802BC0C0
	.4byte 0x802BC0CC
	.4byte 0x802BC0E0
	.4byte 0x802BC0EC
	.4byte 0x802BC110
	.4byte 0x802BC120
	.4byte 0x802BC084
	.4byte 0x802BC14C
	.4byte 0x55666F49
	.4byte 0x74656D00
.global __RTTI__7UfoItem
__RTTI__7UfoItem:
	.4byte 0x803E17AC
	.4byte 0x802BC2F4
	.4byte 0
	.4byte 0x77616974
	.4byte 0
	.4byte 0x74616B65
	.4byte 0x6F666600
	.4byte 0x68656E6B
	.4byte 0x61310000
	.4byte 0x68656E6B
	.4byte 0x61316200
	.4byte 0x68656E6B
	.4byte 0x61316400
	.4byte 0x68656E6B
	.4byte 0x61320000
	.4byte 0x68656E6B
	.4byte 0x61326400
	.4byte 0x68656E6B
	.4byte 0x61330000
	.4byte 0x68656E6B
	.4byte 0x61346100
	.4byte 0x68656E6B
	.4byte 0x61346200
	.4byte 0x802BC580
	.4byte 0
	.4byte 0x802BC58C
	.4byte 0x802BC59C
.global __RTTI__15PaniUfoAnimator
__RTTI__15PaniUfoAnimator:
	.4byte 0x802BC570
	.4byte 0x802BC5A8
.global lbl_803E1828
lbl_803E1828:
	.4byte 0x00000000
.global lbl_803E182C
lbl_803E182C:
	.4byte 0x41A00000
.global lbl_803E1830
lbl_803E1830:
	.4byte 0x00000000
	.4byte 0x802BC600
	.4byte 0x00000000
	.4byte 0x802BC614
	.4byte 0x00000000
	.4byte 0x802BC620
	.4byte 0x00000000
	.4byte 0x802BC630
	.4byte 0x802BC63C
	.4byte 0x802BC650
	.4byte 0x802BC65C
	.4byte 0x802BC680
	.4byte 0x802BC690
.global __RTTI__8BombItem
__RTTI__8BombItem:
	.4byte 0x802BC5F4
	.4byte 0x802BC6BC
	.4byte 0
.global lbl_803E1870
lbl_803E1870:
	.float 1.0
.global lbl_803E1874
lbl_803E1874:
	.float 1.0
.global lbl_803E1878
lbl_803E1878:
	.float 1.0
.global lbl_803E187C
lbl_803E187C:
	.4byte 0x00000000
.global lbl_803E1880
lbl_803E1880:
	.4byte 0x00000000
.global lbl_803E1884
lbl_803E1884:
	.4byte 0x00000000
.global lbl_803E1888
lbl_803E1888:
	.4byte 0xBF800000
.global lbl_803E188C
lbl_803E188C:
	.4byte 0x00000000
.global lbl_803E1890
lbl_803E1890:
	.float 1.0
.global lbl_803E1894
lbl_803E1894:
	.4byte 0x00000000
.global lbl_803E1898
lbl_803E1898:
	.4byte 0x00000000
.global lbl_803E189C
lbl_803E189C:
	.float 1.0
.global lbl_803E18A0
lbl_803E18A0:
	.4byte 0x00000000
.global lbl_803E18A4
lbl_803E18A4:
	.float 1.0
.global lbl_803E18A8
lbl_803E18A8:
	.float 1.0
.global lbl_803E18AC
lbl_803E18AC:
	.float 1.0
.global lbl_803E18B0
lbl_803E18B0:
	.4byte 0x00000000
.global lbl_803E18B4
lbl_803E18B4:
	.4byte 0x00000000
.global lbl_803E18B8
lbl_803E18B8:
	.4byte 0x00000000
.global lbl_803E18BC
lbl_803E18BC:
	.4byte 0x00000000
.global lbl_803E18C0
lbl_803E18C0:
	.4byte 0x00000000
.global lbl_803E18C4
lbl_803E18C4:
	.4byte 0x00000000
.global lbl_803E18C8
lbl_803E18C8:
	.4byte 0x00000000
.global lbl_803E18CC
lbl_803E18CC:
	.4byte 0x00000000
.global lbl_803E18D0
lbl_803E18D0:
	.4byte 0x00000000
	.4byte 0x802BC880
	.4byte 0x00000000
	.4byte 0x802BC8D8
	.4byte 0x00000000
	.4byte 0x802BC8EC
	.4byte 0x00000000
	.4byte 0x802BC8F8
	.4byte 0x00000000
	.4byte 0x802BC908
	.4byte 0x802BC914
	.4byte 0x802BC928
	.4byte 0x802BC934
	.4byte 0x802BC958
	.4byte 0x802BC968
	.4byte 0x802BC8CC
	.4byte 0x802BC994
.global __RTTI__8GoalItem
__RTTI__8GoalItem:
	.4byte 0x802BCB3C
	.4byte 0x802BCB48
	.4byte 0
.global lbl_803E1920
lbl_803E1920:
	.4byte 0xBF800000
.global lbl_803E1924
lbl_803E1924:
	.4byte 0x00000000
.global lbl_803E1928
lbl_803E1928:
	.4byte 0x00000000
.global lbl_803E192C
lbl_803E192C:
	.float 1.0
.global lbl_803E1930
lbl_803E1930:
	.4byte 0x40800000
.global lbl_803E1934
lbl_803E1934:
	.4byte 0x00000000
.global lbl_803E1938
lbl_803E1938:
	.4byte 0x00000000
.global lbl_803E193C
lbl_803E193C:
	.4byte 0x40400000
.global lbl_803E1940
lbl_803E1940:
	.4byte 0x00000000
.global lbl_803E1944
lbl_803E1944:
	.4byte 0x00000000
.global lbl_803E1948
lbl_803E1948:
	.4byte 0x40C00000
.global lbl_803E194C
lbl_803E194C:
	.4byte 0x00000000
.global lbl_803E1950
lbl_803E1950:
	.4byte 0x00000000
	.4byte 0x802BCD44
	.4byte 0x00000000
	.4byte 0x802BCD58
	.4byte 0x00000000
	.4byte 0x802BCD64
	.4byte 0x00000000
	.4byte 0x802BCD74
	.4byte 0x802BCD80
	.4byte 0x802BCD94
	.4byte 0x802BCDA0
	.4byte 0x802BCDC4
	.4byte 0x802BCDD4
.global __RTTI__12PikiHeadItem
__RTTI__12PikiHeadItem:
	.4byte 0x802BCD34
	.4byte 0x802BCE00
	.4byte 0x802BCF90
	.4byte 0
	.4byte 0x802BCFB4
	.4byte 0
	.4byte 0x802BCFF4
	.4byte 0
	.4byte 0
.global lbl_803E19A8
lbl_803E19A8:
	.4byte 0x40000000
.global lbl_803E19AC
lbl_803E19AC:
	.4byte 0x40000000
.global lbl_803E19B0
lbl_803E19B0:
	.4byte 0x00000000
.global lbl_803E19B4
lbl_803E19B4:
	.4byte 0x42200000
.global lbl_803E19B8
lbl_803E19B8:
	.4byte 0x00000000
.global lbl_803E19BC
lbl_803E19BC:
	.4byte 0x25730000
	.4byte 0x802BD0B8
	.4byte 0x00000000
	.4byte 0x802BD0CC
	.4byte 0x00000000
	.4byte 0x802BD0D8
	.4byte 0x00000000
	.4byte 0x802BD0E8
	.4byte 0x802BD0F4
	.4byte 0x802BD108
	.4byte 0x802BD114
	.4byte 0x802BD138
	.4byte 0x802BD148
.global __RTTI__8DoorItem
__RTTI__8DoorItem:
	.4byte 0x802BD0AC
	.4byte 0x802BD174
	.4byte 0x4B657949
	.4byte 0x74656D00
.global __RTTI__7KeyItem
__RTTI__7KeyItem:
	.4byte 0x803E19F8
	.4byte 0x802BD304
	.4byte 0x802BD460
	.4byte 0
	.4byte 0x802BD46C
	.4byte 0
	.4byte 0x802BD47C
	.4byte 0x802BD488
	.4byte 0x802BD49C
	.4byte 0x802BD4AC
.global __RTTI__8RopeItem
__RTTI__8RopeItem:
	.4byte 0x802BD454
	.4byte 0x802BD4C8
.global lbl_803E1A30
lbl_803E1A30:
	.4byte 0x00000000
.global lbl_803E1A34
lbl_803E1A34:
	.4byte 0x00000000
	.4byte 0x802BD628
	.4byte 0x00000000
	.4byte 0x802BD634
	.4byte 0x00000000
	.4byte 0x802BD644
	.4byte 0x802BD650
.global __RTTI__8SeedItem
__RTTI__8SeedItem:
	.4byte 0x802BD61C
	.4byte 0x802BD664
.global lbl_803E1A58
lbl_803E1A58:
	.4byte 0x70303000
.global lbl_803E1A5C
lbl_803E1A5C:
	.4byte 0x70303100
.global lbl_803E1A60
lbl_803E1A60:
	.4byte 0x70303200
.global lbl_803E1A64
lbl_803E1A64:
	.4byte 0x70303300
.global lbl_803E1A68
lbl_803E1A68:
	.4byte 0x20000000
	.4byte 0x802BD83C
	.4byte 0x00000000
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803E1A74
	.4byte 0x802BD848
	.4byte 0x802BD854
	.4byte 0x802BD860
.global __RTTI__13GenObjectItem
__RTTI__13GenObjectItem:
	.4byte 0x802BD82C
	.4byte 0x802BD874
	.4byte 0x802BD8D4
	.4byte 0
	.4byte 0
.global lbl_803E1AA0
lbl_803E1AA0:
	.4byte 0x00000000
.global lbl_803E1AA4
lbl_803E1AA4:
	.4byte 0x00000000
.global lbl_803E1AA8
lbl_803E1AA8:
	.4byte 0x00000000
.global lbl_803E1AAC
lbl_803E1AAC:
	.4byte 0x44480000
.global lbl_803E1AB0
lbl_803E1AB0:
	.4byte 0x44480000
.global lbl_803E1AB4
lbl_803E1AB4:
	.4byte 0x00000000
.global lbl_803E1AB8
lbl_803E1AB8:
	.4byte 0x00000000
.global lbl_803E1ABC
lbl_803E1ABC:
	.4byte 0x00000000
.global lbl_803E1AC0
lbl_803E1AC0:
	.4byte 0x42700000
.global __RTTI__9SAIAction
__RTTI__9SAIAction:
	.4byte 0x802BD944
	.4byte 0
.global __RTTI__Q211FallWaterAI13DisappearInit
__RTTI__Q211FallWaterAI13DisappearInit:
	.4byte 0x802BD928
	.4byte 0x802BD950
.global __RTTI__Q211FallWaterAI8EmitInit
__RTTI__Q211FallWaterAI8EmitInit:
	.4byte 0x802BD968
	.4byte 0x802BD980
.global __RTTI__Q211FallWaterAI11CollideInit
__RTTI__Q211FallWaterAI11CollideInit:
	.4byte 0x802BD998
	.4byte 0x802BD9B4
.global "__RTTI__26StateMachine<10AICreature>_1"
"__RTTI__26StateMachine<10AICreature>_1":
	.4byte 0x802BD9D8
	.4byte 0
.global __RTTI__8SimpleAI_1
__RTTI__8SimpleAI_1:
	.4byte 0x802BD9F4
	.4byte 0x802BDA00
.global __RTTI__11FallWaterAI
__RTTI__11FallWaterAI:
	.4byte 0x802BD9CC
	.4byte 0x802BDA0C
.global __RTTI__Q27WaterAI3Die
__RTTI__Q27WaterAI3Die:
	.4byte 0x802BDA38
	.4byte 0x802BDA48
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E1B04
	.4byte 0
	.4byte lbl_802BD90C
	.4byte 0x802BDA78
.global __RTTI__12SAICondition_1
__RTTI__12SAICondition_1:
	.4byte 0x802BDA84
	.4byte 0x802BDA94
.global __RTTI__Q27WaterAI11CollideChar
__RTTI__Q27WaterAI11CollideChar:
	.4byte 0x802BDA60
	.4byte 0x802BDAA8
	.4byte 0x57617465
	.4byte 0x72414900
.global __RTTI__7WaterAI
__RTTI__7WaterAI:
	.4byte 0x803E1B2C
	.4byte 0x802BDAD8
.global __RTTI__Q25GemAI3Die
__RTTI__Q25GemAI3Die:
	.4byte 0x802BDB04
	.4byte 0x802BDB10
.global __RTTI__Q25GemAI8RiseExec
__RTTI__Q25GemAI8RiseExec:
	.4byte 0x802BDB28
	.4byte 0x802BDB38
.global __RTTI__Q25GemAI8RiseInit
__RTTI__Q25GemAI8RiseInit:
	.4byte 0x802BDB50
	.4byte 0x802BDB60
	.4byte 0x47656D41
	.4byte 0x49000000
.global __RTTI__5GemAI
__RTTI__5GemAI:
	.4byte 0x803E1B54
	.4byte 0x802BDB78
.global __RTTI__Q26GoalAI6Effect
__RTTI__Q26GoalAI6Effect:
	.4byte 0x802BDBA4
	.4byte 0x802BDBB4
.global __RTTI__Q26GoalAI8EmitWait
__RTTI__Q26GoalAI8EmitWait:
	.4byte 0x802BDBCC
	.4byte 0x802BDBE0
.global __RTTI__Q26GoalAI8EmitPiki
__RTTI__Q26GoalAI8EmitPiki:
	.4byte 0x802BDBF8
	.4byte 0x802BDC0C
.global __RTTI__Q26GoalAI8BootDone
__RTTI__Q26GoalAI8BootDone:
	.4byte 0x802BDC24
	.4byte 0x802BDC38
.global __RTTI__Q26GoalAI8BootEmit
__RTTI__Q26GoalAI8BootEmit:
	.4byte 0x802BDC50
	.4byte 0x802BDC64
.global __RTTI__Q26GoalAI8BootInit
__RTTI__Q26GoalAI8BootInit:
	.4byte 0x802BDC7C
	.4byte 0x802BDC90
.global __RTTI__Q26GoalAI8WaitInit
__RTTI__Q26GoalAI8WaitInit:
	.4byte 0x802BDCA8
	.4byte 0x802BDCBC
.global __RTTI__Q26GoalAI11NotFinished
__RTTI__Q26GoalAI11NotFinished:
	.4byte 0x802BDCD4
	.4byte 0x802BDCE8
	.4byte 0x476F616C
	.4byte 0x41490000
.global __RTTI__6GoalAI
__RTTI__6GoalAI:
	.4byte 0x803E1BA4
	.4byte 0x802BDD48
.global __RTTI__Q26BombAI7DieExec
__RTTI__Q26BombAI7DieExec:
	.4byte 0x802BDD74
	.4byte 0x802BDD84
.global __RTTI__Q26BombAI7DieInit
__RTTI__Q26BombAI7DieInit:
	.4byte 0x802BDD9C
	.4byte 0x802BDDAC
.global __RTTI__Q26BombAI8MizuExec
__RTTI__Q26BombAI8MizuExec:
	.4byte 0x802BDDC4
	.4byte 0x802BDDD8
.global __RTTI__Q26BombAI8MizuInit
__RTTI__Q26BombAI8MizuInit:
	.4byte 0x802BDDF0
	.4byte 0x802BDE04
.global __RTTI__Q26BombAI8BombExec
__RTTI__Q26BombAI8BombExec:
	.4byte 0x802BDE1C
	.4byte 0x802BDE30
.global __RTTI__11CndCollPart
__RTTI__11CndCollPart:
	.4byte 0x802BDE8C
	.4byte 0
.global __RTTI__11CndBombable
__RTTI__11CndBombable:
	.4byte 0x802BDE80
	.4byte 0x802BDE98
.global __RTTI__Q26BombAI8BombInit
__RTTI__Q26BombAI8BombInit:
	.4byte 0x802BDEBC
	.4byte 0x802BDED0
.global __RTTI__Q26BombAI7SetExec
__RTTI__Q26BombAI7SetExec:
	.4byte 0x802BDEE8
	.4byte 0x802BDEF8
.global __RTTI__Q26BombAI7SetInit
__RTTI__Q26BombAI7SetInit:
	.4byte 0x802BDF10
	.4byte 0x802BDF20
	.4byte 0x426F6D62
	.4byte 0x41490000
.global __RTTI__6BombAI
__RTTI__6BombAI:
	.4byte 0x803E1C04
	.4byte 0x802BDF38
.global __RTTI__Q210PikiHeadAI4Dead
__RTTI__Q210PikiHeadAI4Dead:
	.4byte 0x802BDF64
	.4byte 0x802BDF78
.global __RTTI__Q210PikiHeadAI10KaretaExec
__RTTI__Q210PikiHeadAI10KaretaExec:
	.4byte 0x802BDF90
	.4byte 0x802BDFA8
.global __RTTI__Q210PikiHeadAI10KaretaInit
__RTTI__Q210PikiHeadAI10KaretaInit:
	.4byte 0x802BDFC0
	.4byte 0x802BDFD8
.global __RTTI__Q210PikiHeadAI10GrowEffect
__RTTI__Q210PikiHeadAI10GrowEffect:
	.4byte 0x802BDFF0
	.4byte 0x802BE008
.global __RTTI__Q210PikiHeadAI12GrowupedExec
__RTTI__Q210PikiHeadAI12GrowupedExec:
	.4byte 0x802BE020
	.4byte 0x802BE03C
.global __RTTI__Q210PikiHeadAI8WaitExec
__RTTI__Q210PikiHeadAI8WaitExec:
	.4byte 0x802BE054
	.4byte 0x802BE06C
.global __RTTI__Q210PikiHeadAI8WaitInit
__RTTI__Q210PikiHeadAI8WaitInit:
	.4byte 0x802BE084
	.4byte 0x802BE09C
.global __RTTI__Q210PikiHeadAI8TaneExec
__RTTI__Q210PikiHeadAI8TaneExec:
	.4byte 0x802BE0B4
	.4byte 0x802BE0CC
.global __RTTI__Q210PikiHeadAI8TaneInit
__RTTI__Q210PikiHeadAI8TaneInit:
	.4byte 0x802BE0E4
	.4byte 0x802BE0FC
.global __RTTI__Q210PikiHeadAI8BuryExec
__RTTI__Q210PikiHeadAI8BuryExec:
	.4byte 0x802BE114
	.4byte 0x802BE12C
.global __RTTI__Q210PikiHeadAI8BuryInit
__RTTI__Q210PikiHeadAI8BuryInit:
	.4byte 0x802BE144
	.4byte 0x802BE15C
.global __RTTI__Q210PikiHeadAI9BuryExec2
__RTTI__Q210PikiHeadAI9BuryExec2:
	.4byte 0x802BE174
	.4byte 0x802BE18C
.global __RTTI__Q210PikiHeadAI9BuryInit2
__RTTI__Q210PikiHeadAI9BuryInit2:
	.4byte 0x802BE1A4
	.4byte 0x802BE1BC
.global __RTTI__Q210PikiHeadAI13FlyingCleanup
__RTTI__Q210PikiHeadAI13FlyingCleanup:
	.4byte 0x802BE1D4
	.4byte 0x802BE1F0
.global __RTTI__Q210PikiHeadAI10FlyingExec
__RTTI__Q210PikiHeadAI10FlyingExec:
	.4byte 0x802BE208
	.4byte 0x802BE220
.global __RTTI__Q210PikiHeadAI12FlyingEffect
__RTTI__Q210PikiHeadAI12FlyingEffect:
	.4byte 0x802BE238
	.4byte 0x802BE254
.global __RTTI__Q210PikiHeadAI11BounceSound
__RTTI__Q210PikiHeadAI11BounceSound:
	.4byte 0x802BE26C
	.4byte 0x802BE284
.global __RTTI__10PikiHeadAI
__RTTI__10PikiHeadAI:
	.4byte 0x802BE29C
	.4byte 0x802BE2A8
.global __RTTI__Q28SluiceAI10DamageInit
__RTTI__Q28SluiceAI10DamageInit:
	.4byte 0x802BE2D4
	.4byte 0x802BE2EC
.global __RTTI__Q28SluiceAI10ChangeInit
__RTTI__Q28SluiceAI10ChangeInit:
	.4byte 0x802BE304
	.4byte 0x802BE31C
.global __RTTI__Q28SluiceAI8WaitInit
__RTTI__Q28SluiceAI8WaitInit:
	.4byte 0x802BE334
	.4byte 0x802BE348
.global __RTTI__Q28SluiceAI8AddCount
__RTTI__Q28SluiceAI8AddCount:
	.4byte 0x802BE360
	.4byte 0x802BE374
.global __RTTI__Q28SluiceAI10MotionDone
__RTTI__Q28SluiceAI10MotionDone:
	.4byte 0x802BE38C
	.4byte 0x802BE3A4
.global __RTTI__Q28SluiceAI4Init
__RTTI__Q28SluiceAI4Init:
	.4byte 0x802BE3BC
	.4byte 0x802BE3CC
.global "__RTTI__22Receiver<10AICreature>_2"
"__RTTI__22Receiver<10AICreature>_2":
	.4byte 0x802BE3FC
	.4byte 0
.global __RTTI__8SluiceAI
__RTTI__8SluiceAI:
	.4byte 0x802BE490
	.4byte 0x802BE49C
	.4byte 0
.global lbl_803E1CE8
lbl_803E1CE8:
	.4byte 0x6974656D
	.4byte 0x4D677200
.global lbl_803E1CF0
lbl_803E1CF0:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803E1CF8
lbl_803E1CF8:
	.4byte 0x636E6F64
	.4byte 0x65000000
.global lbl_803E1D00
lbl_803E1D00:
	.4byte 0x73303000
.global lbl_803E1D04
lbl_803E1D04:
	.4byte 0x73303100
.global lbl_803E1D08
lbl_803E1D08:
	.4byte 0x73303200
.global lbl_803E1D0C
lbl_803E1D0C:
	.4byte 0x73303300
.global lbl_803E1D10
lbl_803E1D10:
	.4byte 0x73303400
.global lbl_803E1D14
lbl_803E1D14:
	.4byte 0x626F6D62
	.4byte 0x00000000
.global lbl_803E1D1C
lbl_803E1D1C:
	.4byte 0x77617465
	.4byte 0x72000000
.global lbl_803E1D24
lbl_803E1D24:
	.4byte 0x67617465
	.4byte 0x00000000
.global lbl_803E1D2C
lbl_803E1D2C:
	.4byte 0x676F616C
	.4byte 0x00000000
.global lbl_803E1D34
lbl_803E1D34:
	.4byte 0x4E554C4C
	.4byte 0x00000000
.global lbl_803E1D3C
lbl_803E1D3C:
	.4byte 0x00000000
.global lbl_803E1D40
lbl_803E1D40:
	.4byte 0x00000000
.global lbl_803E1D44
lbl_803E1D44:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E1D48
	.4byte 0x00000000
	.4byte 0x802BE59C
	.4byte 0x802BE7DC
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803E1D60
	.4byte 0x802BE7E8
	.4byte 0x802BE7FC
	.4byte 0x00000000
	.4byte 0x802BE808
	.4byte 0x802BE814
	.4byte 0x802BE838
	.4byte 0x802BE848
.global __RTTI__11PikiHeadMgr
__RTTI__11PikiHeadMgr:
	.4byte 0x802BE7D0
	.4byte 0x802BE874
	.4byte 0x802BE940
	.4byte 0
.global __RTTI__16PikiHeadItemProp
__RTTI__16PikiHeadItemProp:
	.4byte 0x802BE92C
	.4byte 0x802BE950
	.4byte 0x4974656D
	.4byte 0x4D677200
.global __RTTI__13PolyObjectMgr_1
__RTTI__13PolyObjectMgr_1:
	.4byte 0x802BE968
	.4byte 0x802BE978
.global __RTTI__7ItemMgr
__RTTI__7ItemMgr:
	.4byte 0x803E1DA0
	.4byte 0x802BE9A4
	.4byte 0x802BEA6C
	.4byte 0
.global __RTTI__15InteractBikkuri
__RTTI__15InteractBikkuri:
	.4byte 0x802BEA5C
	.4byte 0x802BEA78
	.4byte 0x802BEAC0
	.4byte 0
	.4byte 0x802BEAD4
	.4byte 0
	.4byte 0x802BEAE0
	.4byte 0
	.4byte 0x802BEAF0
	.4byte 0x802BEAFC
	.4byte 0x802BEB10
	.4byte 0x802BEB1C
	.4byte 0x802BEAB0
	.4byte 0x802BEB40
.global __RTTI__8DoorProp
__RTTI__8DoorProp:
	.4byte 0x802BECC8
	.4byte 0x802BECD4
	.4byte 0x4B657950
	.4byte 0x726F7000
.global __RTTI__7KeyProp
__RTTI__7KeyProp:
	.4byte 0x803E1E00
	.4byte 0x802BECEC
.global __RTTI__8SeedProp
__RTTI__8SeedProp:
	.4byte 0x802BED04
	.4byte 0x802BED10
.global __RTTI__8RopeProp
__RTTI__8RopeProp:
	.4byte 0x802BED28
	.4byte 0x802BED34
.global __RTTI__12MizuItemProp
__RTTI__12MizuItemProp:
	.4byte 0x802BED4C
	.4byte 0x802BED5C
.global __RTTI__12BombItemProp
__RTTI__12BombItemProp:
	.4byte 0x802BED74
	.4byte 0x802BED84
.global __RTTI__Q27ItemMgr7UseNode
__RTTI__Q27ItemMgr7UseNode:
	.4byte 0x802BED9C
	.4byte 0x802BEDB0
.global __RTTI__12KusaItemProp
__RTTI__12KusaItemProp:
	.4byte 0x802BEDD4
	.4byte 0x802BEDE4
.global __RTTI__16BuildingItemProp
__RTTI__16BuildingItemProp:
	.4byte 0x802BEDFC
	.4byte 0x802BEE10
	.4byte 0x802BEE34
	.4byte 0
.global __RTTI__11UfoItemProp
__RTTI__11UfoItemProp:
	.4byte 0x802BEE60
	.4byte 0x802BEE6C
.global __RTTI__12GoalItemProp
__RTTI__12GoalItemProp:
	.4byte 0x802BEE84
	.4byte 0x802BEE94
.global __RTTI__15CreatureNodeMgr_1
__RTTI__15CreatureNodeMgr_1:
	.4byte 0x802BEEC8
	.4byte 0x802BEED8
.global __RTTI__13MeltingPotMgr
__RTTI__13MeltingPotMgr:
	.4byte 0x802BEEB8
	.4byte 0x802BEF04
.global __RTTI__12CreatureNode
__RTTI__12CreatureNode:
	.4byte 0x802BEFB0
	.4byte 0x802BEFC0
.global __RTTI__12BuildingItem
__RTTI__12BuildingItem:
	.4byte 0x802BF018
	.4byte 0x802BF028
	.4byte 0x802BF1F0
	.4byte 0
	.4byte 0x802BF204
	.4byte 0
	.4byte 0x802BF210
	.4byte 0
	.4byte 0x802BF220
	.4byte 0x802BF22C
	.4byte 0x802BF240
	.4byte 0x802BF24C
	.4byte 0x802BF270
	.4byte 0x802BF280
.global __RTTI__10ItemObject
__RTTI__10ItemObject:
	.4byte 0x802BF2AC
	.4byte 0x802BF2B8
.global __RTTI__18NaviDemoSunsetGoal
__RTTI__18NaviDemoSunsetGoal:
	.4byte 0x802BF1DC
	.4byte 0x802BF2EC
.global __RTTI__19NaviDemoSunsetStart
__RTTI__19NaviDemoSunsetStart:
	.4byte 0x802BF484
	.4byte 0x802BF498
	.4byte 0x46756C63
	.4byte 0x72756D00
.global __RTTI__7Fulcrum
__RTTI__7Fulcrum:
	.4byte 0x803E1EC8
	.4byte 0x802BF630
.global __RTTI__11BombGenItem
__RTTI__11BombGenItem:
	.4byte 0x802BF7C8
	.4byte 0x802BF7D4
.global __RTTI__8ItemBall
__RTTI__8ItemBall:
	.4byte 0x802BFAC8
	.4byte 0x802BFAD4
	.4byte 0x802BFC90
	.4byte 0
	.4byte 0x802BFCA4
	.4byte 0
	.4byte 0x802BFCB0
	.4byte 0
	.4byte 0x802BFCC0
	.4byte 0x802BFCCC
	.4byte 0x802BFCE0
	.4byte 0x802BFCEC
	.4byte 0x802BFD10
	.4byte 0x802BFD20
.global __RTTI__8MizuItem
__RTTI__8MizuItem:
	.4byte 0x802BFC84
	.4byte 0x802BFD4C
	.4byte 0x31000000
	.4byte 0x32000000
	.4byte 0x33000000
	.4byte 0x34000000
	.4byte 0x35000000
	.4byte 0x36000000
	.4byte 0x37000000
	.4byte 0x38000000
	.4byte 0x39000000
	.4byte 0x31300000
	.4byte 0x31310000
	.4byte 0x31320000
	.4byte 0x31330000
	.4byte 0x31340000
	.4byte 0x31350000
	.4byte 0x802BFF5C
	.4byte 0
	.4byte 0x802BFF68
	.4byte 0x802BFF78
.global __RTTI__16PaniItemAnimator
__RTTI__16PaniItemAnimator:
	.4byte 0x802BFF48
	.4byte 0x802BFF84
	.4byte 0
	.4byte 0x802C000C
	.4byte 0
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803E1F80
	.4byte 0x802C0018
	.4byte 0x802C0024
	.4byte 0x802C0030
.global __RTTI__13GenObjectNavi
__RTTI__13GenObjectNavi:
	.4byte 0x802BFFFC
	.4byte 0x802C0044
.global DelayPikiBirth
DelayPikiBirth:
	.4byte 0x01000000
.global lbl_803E1FA4
lbl_803E1FA4:
	.4byte 0x73303000
.global lbl_803E1FA8
lbl_803E1FA8:
	.4byte 0x73303100
.global lbl_803E1FAC
lbl_803E1FAC:
	.4byte 0x73303200
.global lbl_803E1FB0
lbl_803E1FB0:
	.4byte 0x73303300
.global lbl_803E1FB4
lbl_803E1FB4:
	.4byte 0x73303400
.global lbl_803E1FB8
lbl_803E1FB8:
	.4byte 0x70303000
.global lbl_803E1FBC
lbl_803E1FBC:
	.4byte 0x70363000
.global lbl_803E1FC0
lbl_803E1FC0:
	.4byte 0x70363200
.global lbl_803E1FC4
lbl_803E1FC4:
	.4byte 0x70303100
.global lbl_803E1FC8
lbl_803E1FC8:
	.4byte 0x70353300
.global lbl_803E1FCC
lbl_803E1FCC:
	.4byte 0x70303200
.global lbl_803E1FD0
lbl_803E1FD0:
	.4byte 0x70303300
.global lbl_803E1FD4
lbl_803E1FD4:
	.4byte 0x70303400
.global lbl_803E1FD8
lbl_803E1FD8:
	.4byte 0x70353600
.global lbl_803E1FDC
lbl_803E1FDC:
	.4byte 0x70333800
.global lbl_803E1FE0
lbl_803E1FE0:
	.4byte 0x70303500
.global lbl_803E1FE4
lbl_803E1FE4:
	.4byte 0x70323000
.global lbl_803E1FE8
lbl_803E1FE8:
	.4byte 0x70303600
.global lbl_803E1FEC
lbl_803E1FEC:
	.4byte 0x70303700
.global lbl_803E1FF0
lbl_803E1FF0:
	.4byte 0x70303800
.global lbl_803E1FF4
lbl_803E1FF4:
	.4byte 0x70303900
.global lbl_803E1FF8
lbl_803E1FF8:
	.4byte 0x70313000
.global lbl_803E1FFC
lbl_803E1FFC:
	.4byte 0x70313100
.global lbl_803E2000
lbl_803E2000:
	.4byte 0x70323400
.global lbl_803E2004
lbl_803E2004:
	.4byte 0x70323500
.global lbl_803E2008
lbl_803E2008:
	.4byte 0x70353400
.global lbl_803E200C
lbl_803E200C:
	.4byte 0x70323600
.global lbl_803E2010
lbl_803E2010:
	.4byte 0x70333700
.global lbl_803E2014
lbl_803E2014:
	.4byte 0x70343200
.global lbl_803E2018
lbl_803E2018:
	.4byte 0x70333900
.global lbl_803E201C
lbl_803E201C:
	.4byte 0x70343000
.global lbl_803E2020
lbl_803E2020:
	.4byte 0x70323100
.global lbl_803E2024
lbl_803E2024:
	.4byte 0x70343100
.global lbl_803E2028
lbl_803E2028:
	.4byte 0x70323200
.global lbl_803E202C
lbl_803E202C:
	.4byte 0x70323300
.global lbl_803E2030
lbl_803E2030:
	.4byte 0x70313400
.global lbl_803E2034
lbl_803E2034:
	.4byte 0x70313500
.global lbl_803E2038
lbl_803E2038:
	.4byte 0x70313600
.global lbl_803E203C
lbl_803E203C:
	.4byte 0x70313700
.global lbl_803E2040
lbl_803E2040:
	.4byte 0x70313800
.global lbl_803E2044
lbl_803E2044:
	.4byte 0x70313900
.global lbl_803E2048
lbl_803E2048:
	.4byte 0x70323700
.global lbl_803E204C
lbl_803E204C:
	.4byte 0x70323800
.global lbl_803E2050
lbl_803E2050:
	.4byte 0x70323900
.global lbl_803E2054
lbl_803E2054:
	.4byte 0x70333000
.global lbl_803E2058
lbl_803E2058:
	.4byte 0x70333100
.global lbl_803E205C
lbl_803E205C:
	.4byte 0x70333200
.global lbl_803E2060
lbl_803E2060:
	.4byte 0x70333300
.global lbl_803E2064
lbl_803E2064:
	.4byte 0x70333400
.global lbl_803E2068
lbl_803E2068:
	.4byte 0x70333500
.global lbl_803E206C
lbl_803E206C:
	.4byte 0x70333600
.global lbl_803E2070
lbl_803E2070:
	.4byte 0x70343800
.global lbl_803E2074
lbl_803E2074:
	.4byte 0x70343900
.global lbl_803E2078
lbl_803E2078:
	.4byte 0x70343300
.global lbl_803E207C
lbl_803E207C:
	.4byte 0x70343400
.global lbl_803E2080
lbl_803E2080:
	.4byte 0x70343500
.global lbl_803E2084
lbl_803E2084:
	.4byte 0x70343600
.global lbl_803E2088
lbl_803E2088:
	.4byte 0x70343700
.global lbl_803E208C
lbl_803E208C:
	.4byte 0x70353000
.global lbl_803E2090
lbl_803E2090:
	.4byte 0x70353100
.global lbl_803E2094
lbl_803E2094:
	.4byte 0x70353200
.global lbl_803E2098
lbl_803E2098:
	.4byte 0x70353500
.global lbl_803E209C
lbl_803E209C:
	.4byte 0x70353700
.global lbl_803E20A0
lbl_803E20A0:
	.4byte 0x70353800
.global lbl_803E20A4
lbl_803E20A4:
	.4byte 0x70353900
.global lbl_803E20A8
lbl_803E20A8:
	.4byte 0x70363100
.global lbl_803E20AC
lbl_803E20AC:
	.4byte 0x00000000
.global lbl_803E20B0
lbl_803E20B0:
	.float 1.0
.global lbl_803E20B4
lbl_803E20B4:
	.4byte 0x00000000
.global lbl_803E20B8
lbl_803E20B8:
	.4byte 0x00000000
.global lbl_803E20BC
lbl_803E20BC:
	.4byte 0x00000000
.global lbl_803E20C0
lbl_803E20C0:
	.4byte 0x00000000
.global lbl_803E20C4
lbl_803E20C4:
	.4byte 0x00000000
.global lbl_803E20C8
lbl_803E20C8:
	.4byte 0x00000000
.global lbl_803E20CC
lbl_803E20CC:
	.4byte 0x00000000
.global lbl_803E20D0
lbl_803E20D0:
	.4byte 0x00000000
.global lbl_803E20D4
lbl_803E20D4:
	.4byte 0x00000000
.global lbl_803E20D8
lbl_803E20D8:
	.4byte 0x00000000
.global lbl_803E20DC
lbl_803E20DC:
	.4byte 0x00000000
.global lbl_803E20E0
lbl_803E20E0:
	.4byte 0x00000000
.global lbl_803E20E4
lbl_803E20E4:
	.4byte 0x00000000
.global lbl_803E20E8
lbl_803E20E8:
	.4byte 0x00000000
.global lbl_803E20EC
lbl_803E20EC:
	.4byte 0x00000000
.global lbl_803E20F0
lbl_803E20F0:
	.4byte 0x00000000
.global lbl_803E20F4
lbl_803E20F4:
	.4byte 0x00000000
.global lbl_803E20F8
lbl_803E20F8:
	.4byte 0x6E617669
	.4byte 0x45666600
.global lbl_803E2100
lbl_803E2100:
	.4byte 0x00000000
.global lbl_803E2104
lbl_803E2104:
	.4byte 0x00000000
.global lbl_803E2108
lbl_803E2108:
	.4byte 0x00000000
.global lbl_803E210C
lbl_803E210C:
	.4byte 0x00000000
.global lbl_803E2110
lbl_803E2110:
	.4byte 0x00000000
.global lbl_803E2114
lbl_803E2114:
	.4byte 0x00000000
.global lbl_803E2118
lbl_803E2118:
	.4byte 0x00000000
.global lbl_803E211C
lbl_803E211C:
	.4byte 0x00000000
.global lbl_803E2120
lbl_803E2120:
	.4byte 0x00000000
.global lbl_803E2124
lbl_803E2124:
	.4byte 0x00000000
.global lbl_803E2128
lbl_803E2128:
	.4byte 0x00000000
.global lbl_803E212C
lbl_803E212C:
	.4byte 0x00000000
.global lbl_803E2130
lbl_803E2130:
	.4byte 0x00000000
.global lbl_803E2134
lbl_803E2134:
	.4byte 0x00000000
.global lbl_803E2138
lbl_803E2138:
	.4byte 0x00000000
.global lbl_803E213C
lbl_803E213C:
	.4byte 0x00000000
.global lbl_803E2140
lbl_803E2140:
	.4byte 0x40000000
.global lbl_803E2144
lbl_803E2144:
	.4byte 0x00000000
.global lbl_803E2148
lbl_803E2148:
	.4byte 0x00000000
.global lbl_803E214C
lbl_803E214C:
	.4byte 0x00000000
.global lbl_803E2150
lbl_803E2150:
	.4byte 0x00000000
.global lbl_803E2154
lbl_803E2154:
	.float 1.0
.global lbl_803E2158
lbl_803E2158:
	.4byte 0x00000000
.global lbl_803E215C
lbl_803E215C:
	.4byte 0x00000000
.global lbl_803E2160
lbl_803E2160:
	.4byte 0x25730000
.global lbl_803E2164
lbl_803E2164:
	.4byte 0x00000000
.global lbl_803E2168
lbl_803E2168:
	.4byte 0x00000000
.global lbl_803E216C
lbl_803E216C:
	.4byte 0x00000000
.global lbl_803E2170
lbl_803E2170:
	.4byte 0x00000000
.global lbl_803E2174
lbl_803E2174:
	.4byte 0x00000000
.global lbl_803E2178
lbl_803E2178:
	.4byte 0x00000000
.global lbl_803E217C
lbl_803E217C:
	.4byte 0x00000000
.global lbl_803E2180
lbl_803E2180:
	.4byte 0x00000000
.global lbl_803E2184
lbl_803E2184:
	.4byte 0x00000000
.global lbl_803E2188
lbl_803E2188:
	.4byte 0x00000000
.global lbl_803E218C
lbl_803E218C:
	.4byte 0x00000000
.global lbl_803E2190
lbl_803E2190:
	.4byte 0x00000000
.global lbl_803E2194
lbl_803E2194:
	.4byte 0x00000000
.global lbl_803E2198
lbl_803E2198:
	.4byte 0x00000000
.global lbl_803E219C
lbl_803E219C:
	.4byte 0x00000000
.global lbl_803E21A0
lbl_803E21A0:
	.4byte 0x00000000
.global lbl_803E21A4
lbl_803E21A4:
	.4byte 0x00000000
.global lbl_803E21A8
lbl_803E21A8:
	.4byte 0x00000000
.global lbl_803E21AC
lbl_803E21AC:
	.4byte 0x00000000
.global lbl_803E21B0
lbl_803E21B0:
	.4byte 0x00000000
.global lbl_803E21B4
lbl_803E21B4:
	.4byte 0x00000000
.global lbl_803E21B8
lbl_803E21B8:
	.float 1.0
.global lbl_803E21BC
lbl_803E21BC:
	.4byte 0x00000000
.global lbl_803E21C0
lbl_803E21C0:
	.4byte 0x00000000
.global lbl_803E21C4
lbl_803E21C4:
	.4byte 0x00000000
.global lbl_803E21C8
lbl_803E21C8:
	.4byte 0x00000000
.global lbl_803E21CC
lbl_803E21CC:
	.4byte 0x00000000
.global lbl_803E21D0
lbl_803E21D0:
	.4byte 0x00000000
.global lbl_803E21D4
lbl_803E21D4:
	.4byte 0x41200000
.global lbl_803E21D8
lbl_803E21D8:
	.4byte 0x00000000
.global lbl_803E21DC
lbl_803E21DC:
	.4byte 0x00000000
.global lbl_803E21E0
lbl_803E21E0:
	.4byte 0x00000000
.global lbl_803E21E4
lbl_803E21E4:
	.4byte 0x00000000
	.4byte 0x802C0114
	.4byte 0x00000000
.global __RTTI__12InteractSuck
__RTTI__12InteractSuck:
	.4byte 0x802C0104
	.4byte 0x802C0120
.global __RTTI__14InteractGeyzer
__RTTI__14InteractGeyzer:
	.4byte 0x802C0158
	.4byte 0x802C0168
.global "__RTTI__19StateMachine<4Navi>"
"__RTTI__19StateMachine<4Navi>":
	.4byte 0x802C01CC
	.4byte 0
	.4byte 0x802C01F8
	.4byte 0
	.4byte 0x802C021C
	.4byte 0
	.4byte 0x802C025C
	.4byte 0
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E2220
	.4byte 0
	.4byte 0x802C0310
	.4byte 0x802C031C
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803E2238
	.4byte 0x802C0328
.global __RTTI__10NaviDrawer
__RTTI__10NaviDrawer:
	.4byte 0x802C0304
	.4byte 0x802C033C
.global __RTTI__10PelletView
__RTTI__10PelletView:
	.4byte 0x802C03A4
	.4byte 0
	.4byte 0x802C03E4
	.4byte 0
	.4byte 0x802C0410
	.4byte 0
	.4byte 0x802C0448
	.4byte 0
.global __RTTI__8NaviProp
__RTTI__8NaviProp:
	.4byte 0x802C043C
	.4byte 0x802C0458
	.4byte 0x4E617669
	.4byte 0
	.4byte 0x802C04A8
	.4byte 0
	.4byte 0x802C04B4
	.4byte 0
	.4byte 0x802C04C4
	.4byte 0x802C04D0
.global __RTTI__4Navi
__RTTI__4Navi:
	.4byte 0x803E2278
	.4byte 0x802C04E4
.global lbl_803E22A0
lbl_803E22A0:
	.4byte 0x00000000
.global lbl_803E22A4
lbl_803E22A4:
	.4byte 0x00000000
.global lbl_803E22A8
lbl_803E22A8:
	.4byte 0x00000000
.global lbl_803E22AC
lbl_803E22AC:
	.4byte 0x00000000
.global lbl_803E22B0
lbl_803E22B0:
	.4byte 0x00000000
.global lbl_803E22B4
lbl_803E22B4:
	.4byte 0x00000000
.global lbl_803E22B8
lbl_803E22B8:
	.4byte 0x00000000
.global lbl_803E22BC
lbl_803E22BC:
	.4byte 0x00000000
.global lbl_803E22C0
lbl_803E22C0:
	.4byte 0x00000000
.global lbl_803E22C4
lbl_803E22C4:
	.4byte 0x00000000
.global lbl_803E22C8
lbl_803E22C8:
	.4byte 0x00000000
.global lbl_803E22CC
lbl_803E22CC:
	.4byte 0x00000000
.global lbl_803E22D0
lbl_803E22D0:
	.4byte 0x00000000
.global lbl_803E22D4
lbl_803E22D4:
	.4byte 0x00000000
.global lbl_803E22D8
lbl_803E22D8:
	.4byte 0x00000000
.global lbl_803E22DC
lbl_803E22DC:
	.4byte 0x00000000
.global lbl_803E22E0
lbl_803E22E0:
	.4byte 0x00000000
.global lbl_803E22E4
lbl_803E22E4:
	.4byte 0x00000000
.global lbl_803E22E8
lbl_803E22E8:
	.4byte 0x00000000
.global lbl_803E22EC
lbl_803E22EC:
	.4byte 0x00000000
.global lbl_803E22F0
lbl_803E22F0:
	.4byte 0x00000000
.global lbl_803E22F4
lbl_803E22F4:
	.4byte 0x00000000
.global lbl_803E22F8
lbl_803E22F8:
	.4byte 0x00000000
.global lbl_803E22FC
lbl_803E22FC:
	.4byte 0x00000000
.global lbl_803E2300
lbl_803E2300:
	.4byte 0x00000000
.global lbl_803E2304
lbl_803E2304:
	.4byte 0x00000000
.global lbl_803E2308
lbl_803E2308:
	.4byte 0x00000000
.global lbl_803E230C
lbl_803E230C:
	.4byte 0x00000000
.global lbl_803E2310
lbl_803E2310:
	.4byte 0x00000000
.global lbl_803E2314
lbl_803E2314:
	.4byte 0x00000000
.global lbl_803E2318
lbl_803E2318:
	.4byte 0x00000000
.global lbl_803E231C
lbl_803E231C:
	.4byte 0x00000000
.global lbl_803E2320
lbl_803E2320:
	.4byte 0x00000000
.global lbl_803E2324
lbl_803E2324:
	.4byte 0x42C80000
.global lbl_803E2328
lbl_803E2328:
	.4byte 0x00000000
.global lbl_803E232C
lbl_803E232C:
	.4byte 0x00000000
.global lbl_803E2330
lbl_803E2330:
	.4byte 0x00000000
.global lbl_803E2334
lbl_803E2334:
	.4byte 0x00000000
.global lbl_803E2338
lbl_803E2338:
	.4byte 0x00000000
.global lbl_803E233C
lbl_803E233C:
	.4byte 0x00000000
.global lbl_803E2340
lbl_803E2340:
	.4byte 0x00000000
.global lbl_803E2344
lbl_803E2344:
	.4byte 0x00000000
.global lbl_803E2348
lbl_803E2348:
	.4byte 0x00000000
.global lbl_803E234C
lbl_803E234C:
	.4byte 0x00000000
.global lbl_803E2350
lbl_803E2350:
	.4byte 0x00000000
.global lbl_803E2354
lbl_803E2354:
	.4byte 0x00000000
.global lbl_803E2358
lbl_803E2358:
	.4byte 0x00000000
.global lbl_803E235C
lbl_803E235C:
	.4byte 0x42700000
.global lbl_803E2360
lbl_803E2360:
	.4byte 0x42700000
.global lbl_803E2364
lbl_803E2364:
	.4byte 0x00000000
.global lbl_803E2368
lbl_803E2368:
	.4byte 0x00000000
.global lbl_803E236C
lbl_803E236C:
	.4byte 0x00000000
.global lbl_803E2370
lbl_803E2370:
	.4byte 0x00000000
.global lbl_803E2374
lbl_803E2374:
	.4byte 0x00000000
.global lbl_803E2378
lbl_803E2378:
	.4byte 0x00000000
.global lbl_803E237C
lbl_803E237C:
	.4byte 0x00000000
.global lbl_803E2380
lbl_803E2380:
	.4byte 0x00000000
.global lbl_803E2384
lbl_803E2384:
	.4byte 0x00000000
.global lbl_803E2388
lbl_803E2388:
	.4byte 0x00000000
.global lbl_803E238C
lbl_803E238C:
	.4byte 0x00000000
.global lbl_803E2390
lbl_803E2390:
	.4byte 0x00000000
.global lbl_803E2394
lbl_803E2394:
	.4byte 0x00000000
.global lbl_803E2398
lbl_803E2398:
	.4byte 0x00000000
.global lbl_803E239C
lbl_803E239C:
	.4byte 0x00000000
.global lbl_803E23A0
lbl_803E23A0:
	.4byte 0x00000000
.global lbl_803E23A4
lbl_803E23A4:
	.4byte 0x43480000
.global lbl_803E23A8
lbl_803E23A8:
	.4byte 0x00000000
.global lbl_803E23AC
lbl_803E23AC:
	.4byte 0x00000000
.global lbl_803E23B0
lbl_803E23B0:
	.4byte 0x00000000
.global lbl_803E23B4
lbl_803E23B4:
	.4byte 0x00000000
.global lbl_803E23B8
lbl_803E23B8:
	.4byte 0x00000000
.global lbl_803E23BC
lbl_803E23BC:
	.4byte 0x00000000
.global lbl_803E23C0
lbl_803E23C0:
	.4byte 0x00000000
.global lbl_803E23C4
lbl_803E23C4:
	.4byte 0x00000000
.global lbl_803E23C8
lbl_803E23C8:
	.4byte 0x00000000
.global lbl_803E23CC
lbl_803E23CC:
	.4byte 0x00000000
.global lbl_803E23D0
lbl_803E23D0:
	.4byte 0x43480000
.global lbl_803E23D4
lbl_803E23D4:
	.4byte 0x00000000
.global lbl_803E23D8
lbl_803E23D8:
	.4byte 0x00000000
.global lbl_803E23DC
lbl_803E23DC:
	.4byte 0x00000000
.global lbl_803E23E0
lbl_803E23E0:
	.4byte 0x00000000
.global lbl_803E23E4
lbl_803E23E4:
	.4byte 0x00000000
.global lbl_803E23E8
lbl_803E23E8:
	.4byte 0x00000000
.global lbl_803E23EC
lbl_803E23EC:
	.4byte 0x00000000
.global lbl_803E23F0
lbl_803E23F0:
	.4byte 0x00000000
.global lbl_803E23F4
lbl_803E23F4:
	.4byte 0x00000000
.global lbl_803E23F8
lbl_803E23F8:
	.4byte 0xC1200000
.global lbl_803E23FC
lbl_803E23FC:
	.4byte 0x00000000
.global lbl_803E2400
lbl_803E2400:
	.4byte 0x00000000
.global lbl_803E2404
lbl_803E2404:
	.4byte 0xBF800000
.global lbl_803E2408
lbl_803E2408:
	.4byte 0x00000000
.global lbl_803E240C
lbl_803E240C:
	.4byte 0x00000000
.global lbl_803E2410
lbl_803E2410:
	.4byte 0x00000000
.global lbl_803E2414
lbl_803E2414:
	.4byte 0x40800000
.global lbl_803E2418
lbl_803E2418:
	.4byte 0x00000000
.global lbl_803E241C
lbl_803E241C:
	.4byte 0x00000000
.global lbl_803E2420
lbl_803E2420:
	.4byte 0x40800000
.global lbl_803E2424
lbl_803E2424:
	.4byte 0x00000000
.global lbl_803E2428
lbl_803E2428:
	.4byte 0x00000000
.global lbl_803E242C
lbl_803E242C:
	.4byte 0x00000000
.global lbl_803E2430
lbl_803E2430:
	.4byte 0x00000000
.global lbl_803E2434
lbl_803E2434:
	.4byte 0x00000000
.global lbl_803E2438
lbl_803E2438:
	.4byte 0x00000000
.global lbl_803E243C
lbl_803E243C:
	.4byte 0x00000000
.global lbl_803E2440
lbl_803E2440:
	.4byte 0x00000000
.global lbl_803E2444
lbl_803E2444:
	.4byte 0x00000000
.global lbl_803E2448
lbl_803E2448:
	.4byte 0x40C00000
.global lbl_803E244C
lbl_803E244C:
	.4byte 0x40C00000
.global lbl_803E2450
lbl_803E2450:
	.4byte 0x00000000
.global lbl_803E2454
lbl_803E2454:
	.4byte 0x00000000
.global lbl_803E2458
lbl_803E2458:
	.4byte 0x00000000
.global lbl_803E245C
lbl_803E245C:
	.4byte 0x00000000
.global lbl_803E2460
lbl_803E2460:
	.4byte 0x00000000
.global lbl_803E2464
lbl_803E2464:
	.4byte 0x00000000
.global lbl_803E2468
lbl_803E2468:
	.4byte 0x00000000
.global lbl_803E246C
lbl_803E246C:
	.4byte 0x00000000
.global lbl_803E2470
lbl_803E2470:
	.4byte 0x00000000
.global lbl_803E2474
lbl_803E2474:
	.4byte 0x41300000
.global lbl_803E2478
lbl_803E2478:
	.4byte 0x00000000
.global lbl_803E247C
lbl_803E247C:
	.4byte 0x00000000
.global lbl_803E2480
lbl_803E2480:
	.4byte 0x00000000
.global lbl_803E2484
lbl_803E2484:
	.4byte 0x00000000
.global lbl_803E2488
lbl_803E2488:
	.4byte 0x00000000
.global lbl_803E248C
lbl_803E248C:
	.4byte 0x00000000
.global lbl_803E2490
lbl_803E2490:
	.4byte 0x00000000
.global lbl_803E2494
lbl_803E2494:
	.4byte 0x00000000
.global lbl_803E2498
lbl_803E2498:
	.4byte 0x00000000
.global lbl_803E249C
lbl_803E249C:
	.4byte 0x00000000
.global lbl_803E24A0
lbl_803E24A0:
	.4byte 0x00000000
.global lbl_803E24A4
lbl_803E24A4:
	.4byte 0x00000000
.global lbl_803E24A8
lbl_803E24A8:
	.4byte 0x00000000
.global lbl_803E24AC
lbl_803E24AC:
	.4byte 0x00000000
.global lbl_803E24B0
lbl_803E24B0:
	.4byte 0x00000000
.global lbl_803E24B4
lbl_803E24B4:
	.4byte 0x00000000
.global lbl_803E24B8
lbl_803E24B8:
	.4byte 0x00000000
.global lbl_803E24BC
lbl_803E24BC:
	.4byte 0x00000000
.global lbl_803E24C0
lbl_803E24C0:
	.4byte 0x00000000
.global lbl_803E24C4
lbl_803E24C4:
	.4byte 0x42480000
.global lbl_803E24C8
lbl_803E24C8:
	.4byte 0x00000000
.global lbl_803E24CC
lbl_803E24CC:
	.4byte 0x00000000
.global lbl_803E24D0
lbl_803E24D0:
	.4byte 0x00000000
.global lbl_803E24D4
lbl_803E24D4:
	.4byte 0x00000000
.global lbl_803E24D8
lbl_803E24D8:
	.4byte 0x00000000
.global lbl_803E24DC
lbl_803E24DC:
	.4byte 0x00000000
.global lbl_803E24E0
lbl_803E24E0:
	.4byte 0x41C80000
.global lbl_803E24E4
lbl_803E24E4:
	.4byte 0x00000000
.global lbl_803E24E8
lbl_803E24E8:
	.4byte 0x00000000
.global lbl_803E24EC
lbl_803E24EC:
	.4byte 0x00000000
.global lbl_803E24F0
lbl_803E24F0:
	.4byte 0x00000000
.global lbl_803E24F4
lbl_803E24F4:
	.4byte 0x00000000
.global lbl_803E24F8
lbl_803E24F8:
	.4byte 0x00000000
.global lbl_803E24FC
lbl_803E24FC:
	.4byte 0x00000000
.global lbl_803E2500
lbl_803E2500:
	.4byte 0x00000000
.global lbl_803E2504
lbl_803E2504:
	.4byte 0x00000000
.global lbl_803E2508
lbl_803E2508:
	.4byte 0x00000000
.global lbl_803E250C
lbl_803E250C:
	.4byte 0x00000000
.global lbl_803E2510
lbl_803E2510:
	.4byte 0x00000000
.global lbl_803E2514
lbl_803E2514:
	.4byte 0x00000000
.global lbl_803E2518
lbl_803E2518:
	.4byte 0x00000000
.global lbl_803E251C
lbl_803E251C:
	.4byte 0x00000000
.global lbl_803E2520
lbl_803E2520:
	.4byte 0x00000000
.global lbl_803E2524
lbl_803E2524:
	.4byte 0x00000000
.global lbl_803E2528
lbl_803E2528:
	.4byte 0x00000000
.global lbl_803E252C
lbl_803E252C:
	.4byte 0x00000000
.global lbl_803E2530
lbl_803E2530:
	.4byte 0x00000000
.global lbl_803E2534
lbl_803E2534:
	.4byte 0x00000000
.global lbl_803E2538
lbl_803E2538:
	.4byte 0x00000000
.global lbl_803E253C
lbl_803E253C:
	.4byte 0x00000000
.global lbl_803E2540
lbl_803E2540:
	.4byte 0x00000000
	.4byte 0x802C06B0
	.4byte 0x00000000
.global "__RTTI__13AState<4Navi>"
"__RTTI__13AState<4Navi>":
	.4byte 0x802C06C0
	.4byte 0x802C06D0
	.4byte 0x802C06DC
	.4byte 0x802C06E8
.global __RTTI__18NaviUfoAccessState
__RTTI__18NaviUfoAccessState:
	.4byte 0x802C069C
	.4byte 0x802C06FC
.global __RTTI__20NaviPartsAccessState
__RTTI__20NaviPartsAccessState:
	.4byte 0x802C076C
	.4byte 0x802C0784
.global __RTTI__17NaviStartingState
__RTTI__17NaviStartingState:
	.4byte 0x802C07F4
	.4byte 0x802C0808
.global __RTTI__17NaviPikiZeroState
__RTTI__17NaviPikiZeroState:
	.4byte 0x802C0878
	.4byte 0x802C088C
.global __RTTI__13NaviDeadState
__RTTI__13NaviDeadState:
	.4byte 0x802C08FC
	.4byte 0x802C090C
.global __RTTI__15NaviIroIroState
__RTTI__15NaviIroIroState:
	.4byte 0x802C097C
	.4byte 0x802C098C
.global __RTTI__14NaviClearState
__RTTI__14NaviClearState:
	.4byte 0x802C09FC
	.4byte 0x802C0A0C
.global __RTTI__13NaviLockState
__RTTI__13NaviLockState:
	.4byte 0x802C0A7C
	.4byte 0x802C0A8C
.global __RTTI__15NaviAttackState
__RTTI__15NaviAttackState:
	.4byte 0x802C0AFC
	.4byte 0x802C0B0C
.global __RTTI__14NaviWaterState
__RTTI__14NaviWaterState:
	.4byte 0x802C0B7C
	.4byte 0x802C0B8C
.global __RTTI__12NaviSowState
__RTTI__12NaviSowState:
	.4byte 0x802C0BFC
	.4byte 0x802C0C0C
.global __RTTI__16NaviPressedState
__RTTI__16NaviPressedState:
	.4byte 0x802C0C7C
	.4byte 0x802C0C90
.global __RTTI__19NaviNukuAdjustState
__RTTI__19NaviNukuAdjustState:
	.4byte 0x802C0D00
	.4byte 0x802C0D14
.global __RTTI__13NaviNukuState
__RTTI__13NaviNukuState:
	.4byte 0x802C0D84
	.4byte 0x802C0D94
.global __RTTI__17NaviPushPikiState
__RTTI__17NaviPushPikiState:
	.4byte 0x802C0E04
	.4byte 0x802C0E18
.global __RTTI__13NaviPushState
__RTTI__13NaviPushState:
	.4byte 0x802C0E88
	.4byte 0x802C0E98
.global __RTTI__14NaviThrowState
__RTTI__14NaviThrowState:
	.4byte 0x802C0F08
	.4byte 0x802C0F18
.global __RTTI__18NaviThrowWaitState
__RTTI__18NaviThrowWaitState:
	.4byte 0x802C0F88
	.4byte 0x802C0F9C
.global __RTTI__16NaviReleaseState
__RTTI__16NaviReleaseState:
	.4byte 0x802C100C
	.4byte 0x802C1020
.global __RTTI__15NaviGatherState
__RTTI__15NaviGatherState:
	.4byte 0x802C1090
	.4byte 0x802C10A0
.global __RTTI__15NaviGeyzerState
__RTTI__15NaviGeyzerState:
	.4byte 0x802C1110
	.4byte 0x802C1120
.global __RTTI__14NaviFlickState
__RTTI__14NaviFlickState:
	.4byte 0x802C1190
	.4byte 0x802C11A0
.global __RTTI__13NaviIdleState
__RTTI__13NaviIdleState:
	.4byte 0x802C1210
	.4byte 0x802C1220
.global __RTTI__16NaviFunbariState
__RTTI__16NaviFunbariState:
	.4byte 0x802C1290
	.4byte 0x802C12A4
.global __RTTI__17NaviRopeExitState
__RTTI__17NaviRopeExitState:
	.4byte 0x802C1314
	.4byte 0x802C1328
.global __RTTI__13NaviRopeState
__RTTI__13NaviRopeState:
	.4byte 0x802C1398
	.4byte 0x802C13A8
.global __RTTI__13NaviPickState
__RTTI__13NaviPickState:
	.4byte 0x802C1418
	.4byte 0x802C1428
.global __RTTI__Q25GmWin13CloseListener
__RTTI__Q25GmWin13CloseListener:
	.4byte 0x802C14AC
	.4byte 0
.global __RTTI__Q212ContainerWin8Listener
__RTTI__Q212ContainerWin8Listener:
	.4byte 0x802C14C4
	.4byte 0
.global __RTTI__18NaviContainerState
__RTTI__18NaviContainerState:
	.4byte 0x802C1498
	.4byte 0x802C14DC
.global __RTTI__12NaviUfoState
__RTTI__12NaviUfoState:
	.4byte 0x802C1594
	.4byte 0x802C15A4
.global __RTTI__13NaviWalkState
__RTTI__13NaviWalkState:
	.4byte 0x802C1614
	.4byte 0x802C1624
.global __RTTI__13NaviBuryState
__RTTI__13NaviBuryState:
	.4byte 0x802C1694
	.4byte 0x802C16A4
.global __RTTI__14NaviStuckState
__RTTI__14NaviStuckState:
	.4byte 0x802C174C
	.4byte 0x802C175C
.global __RTTI__16NaviDemoInfState
__RTTI__16NaviDemoInfState:
	.4byte 0x802C17CC
	.4byte 0x802C17E0
.global __RTTI__17NaviDemoWaitState
__RTTI__17NaviDemoWaitState:
	.4byte 0x802C1850
	.4byte 0x802C1864
.global __RTTI__15NaviPelletState
__RTTI__15NaviPelletState:
	.4byte 0x802C18D4
	.4byte 0x802C18E4
.global "__RTTI__19StateMachine<4Navi>_1"
"__RTTI__19StateMachine<4Navi>_1":
	.4byte 0x802C1A44
	.4byte 0
.global __RTTI__16NaviStateMachine
__RTTI__16NaviStateMachine:
	.4byte 0x802C1A30
	.4byte 0x802C1A58
	.4byte 0
.global lbl_803E2698
lbl_803E2698:
	.4byte 0x00000000
.global lbl_803E269C
lbl_803E269C:
	.4byte 0x00000000
.global lbl_803E26A0
lbl_803E26A0:
	.4byte 0x00000000
.global lbl_803E26A4
lbl_803E26A4:
	.4byte 0x00000000
.global lbl_803E26A8
lbl_803E26A8:
	.4byte 0x00000000
.global lbl_803E26AC
lbl_803E26AC:
	.4byte 0x00000000
.global lbl_803E26B0
lbl_803E26B0:
	.4byte 0x00000000
.global lbl_803E26B4
lbl_803E26B4:
	.4byte 0x00000000
.global lbl_803E26B8
lbl_803E26B8:
	.4byte 0x00000000
.global lbl_803E26BC
lbl_803E26BC:
	.4byte 0x00000000
.global lbl_803E26C0
lbl_803E26C0:
	.4byte 0x00000000
.global lbl_803E26C4
lbl_803E26C4:
	.4byte 0x00000000
.global lbl_803E26C8
lbl_803E26C8:
	.4byte 0x00000000
.global lbl_803E26CC
lbl_803E26CC:
	.4byte 0x00000000
.global lbl_803E26D0
lbl_803E26D0:
	.4byte 0x43C80000
	.4byte 0x802C1B24
	.4byte 0x00000000
.global "__RTTI__13AState<4Navi>_1"
"__RTTI__13AState<4Navi>_1":
	.4byte 0x802C1B34
	.4byte 0x802C1B44
	.4byte 0x802C1B50
	.4byte 0x802C1B5C
.global __RTTI__19NaviDemoSunsetState
__RTTI__19NaviDemoSunsetState:
	.4byte 0x802C1B10
	.4byte 0x802C1B70
.global "__RTTI__35StateMachine<19NaviDemoSunsetState>"
"__RTTI__35StateMachine<19NaviDemoSunsetState>":
	.4byte 0x802C1BE0
	.4byte 0
.global "__RTTI__31Receiver<19NaviDemoSunsetState>"
"__RTTI__31Receiver<19NaviDemoSunsetState>":
	.4byte 0x802C1D18
	.4byte 0
.global "__RTTI__29AState<19NaviDemoSunsetState>"
"__RTTI__29AState<19NaviDemoSunsetState>":
	.4byte 0x802C1D38
	.4byte 0x802C1D54
.global __RTTI__Q219NaviDemoSunsetState9DemoState
__RTTI__Q219NaviDemoSunsetState9DemoState:
	.4byte 0x802C1D60
	.4byte 0x802C1D80
.global __RTTI__Q219NaviDemoSunsetState8SitState
__RTTI__Q219NaviDemoSunsetState8SitState:
	.4byte 0x802C1CF8
	.4byte 0x802C1D94
.global __RTTI__Q219NaviDemoSunsetState9WaitState
__RTTI__Q219NaviDemoSunsetState9WaitState:
	.4byte 0x802C1E00
	.4byte 0x802C1E20
.global __RTTI__Q219NaviDemoSunsetState12WhistleState
__RTTI__Q219NaviDemoSunsetState12WhistleState:
	.4byte 0x802C1E8C
	.4byte 0x802C1EB0
.global __RTTI__Q219NaviDemoSunsetState9LookState
__RTTI__Q219NaviDemoSunsetState9LookState:
	.4byte 0x802C1F1C
	.4byte 0x802C1F3C
.global __RTTI__Q219NaviDemoSunsetState7GoState
__RTTI__Q219NaviDemoSunsetState7GoState:
	.4byte 0x802C1FA8
	.4byte 0x802C1FC8
.global __RTTI__Q219NaviDemoSunsetState16DemoStateMachine
__RTTI__Q219NaviDemoSunsetState16DemoStateMachine:
	.4byte 0x802C210C
	.4byte 0x802C2134
	.4byte 0
.global lbl_803E2748
lbl_803E2748:
	.float 1.0
.global lbl_803E274C
lbl_803E274C:
	.float 1.0
.global lbl_803E2750
lbl_803E2750:
	.float 1.0
.global lbl_803E2754
lbl_803E2754:
	.4byte 0x00000000
.global lbl_803E2758
lbl_803E2758:
	.4byte 0x00000000
.global lbl_803E275C
lbl_803E275C:
	.4byte 0x00000000
.global lbl_803E2760
lbl_803E2760:
	.4byte 0x00000000
.global lbl_803E2764
lbl_803E2764:
	.4byte 0x00000000
.global lbl_803E2768
lbl_803E2768:
	.4byte 0x00000000
.global lbl_803E276C
lbl_803E276C:
	.4byte 0x00000000
.global lbl_803E2770
lbl_803E2770:
	.4byte 0x00000000
.global lbl_803E2774
lbl_803E2774:
	.4byte 0x00000000
.global lbl_803E2778
lbl_803E2778:
	.4byte 0x00000000
.global lbl_803E277C
lbl_803E277C:
	.4byte 0x70696B69
	.4byte 0x00000000
.global lbl_803E2784
lbl_803E2784:
	.4byte 0x70696B69
	.4byte 0x4D677200
.global lbl_803E278C
lbl_803E278C:
	.4byte 0x25732573
	.4byte 0x00000000
.global lbl_803E2794
lbl_803E2794:
	.4byte 0x6974656D
	.4byte 0x00000000
.global lbl_803E279C
lbl_803E279C:
	.4byte 0x6D61704D
	.4byte 0x67720000
.global lbl_803E27A4
lbl_803E27A4:
	.4byte 0x706C616E
	.4byte 0x74000000
.global lbl_803E27AC
lbl_803E27AC:
	.4byte 0x74656B69
	.4byte 0x00000000
.global lbl_803E27B4
lbl_803E27B4:
	.4byte 0x626F7373
	.4byte 0x00000000
.global lbl_803E27BC
lbl_803E27BC:
	.4byte 0x70656C6C
	.4byte 0x65740000
.global lbl_803E27C4
lbl_803E27C4:
	.4byte 0x776F726B
	.4byte 0x6F626A00
.global lbl_803E27CC
lbl_803E27CC:
	.4byte 0x626F6262
	.4byte 0x79000000
.global lbl_803E27D4
lbl_803E27D4:
	.4byte 0x67756900
.global lbl_803E27D8
lbl_803E27D8:
	.4byte 0x414992E8
	.4byte 0x90940000
.global lbl_803E27E0
lbl_803E27E0:
	.4byte 0x6E617669
	.4byte 0x00000000
.global lbl_803E27E8
lbl_803E27E8:
	.4byte 0x6E617669
	.4byte 0x4D677200
.global lbl_803E27F0
lbl_803E27F0:
	.4byte 0x64656661
	.4byte 0x756C7400
.global lbl_803E27F8
lbl_803E27F8:
	.4byte 0x696E6974
	.4byte 0x00000000
.global lbl_803E2800
lbl_803E2800:
	.4byte 0x6461696C
	.4byte 0x79000000
.global lbl_803E2808
lbl_803E2808:
	.4byte 0x6C696D69
	.4byte 0x74000000
.global lbl_803E2810
lbl_803E2810:
	.4byte 0x626F7373
	.4byte 0x4D677200
.global lbl_803E2818
lbl_803E2818:
	.4byte 0x74656B69
	.4byte 0x4D677200
	.4byte 0x48494445
	.4byte 0x20324400
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E2828
	.4byte 0x00000000
	.4byte 0x802C242C
	.4byte 0x802C2438
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803E2840
	.4byte 0x802C2444
.global __RTTI__15GameCoreSection
__RTTI__15GameCoreSection:
	.4byte 0x802C241C
	.4byte 0x802C2458
.global lbl_803E2858
lbl_803E2858:
	.4byte 0x00000000
	.4byte 0x00000000
.global lbl_803E2860
lbl_803E2860:
	.4byte 0x3F666666
.global lbl_803E2864
lbl_803E2864:
	.4byte 0x00000000
.global lbl_803E2868
lbl_803E2868:
	.4byte 0x00000000
.global lbl_803E286C
lbl_803E286C:
	.4byte 0x00000000
.global lbl_803E2870
lbl_803E2870:
	.4byte 0x00000000
.global lbl_803E2874
lbl_803E2874:
	.float 1.0
.global lbl_803E2878
lbl_803E2878:
	.4byte 0x00000000
.global lbl_803E287C
lbl_803E287C:
	.4byte 0x00000000
.global lbl_803E2880
lbl_803E2880:
	.float 1.0
.global lbl_803E2884
lbl_803E2884:
	.4byte 0x00000000
.global lbl_803E2888
lbl_803E2888:
	.4byte 0xBF800000
.global lbl_803E288C
lbl_803E288C:
	.4byte 0xBF800000
.global lbl_803E2890
lbl_803E2890:
	.4byte 0x00000000
.global lbl_803E2894
lbl_803E2894:
	.4byte 0x00000000
.global lbl_803E2898
lbl_803E2898:
	.4byte 0x00000000
.global lbl_803E289C
lbl_803E289C:
	.4byte 0x00000000
.global lbl_803E28A0
lbl_803E28A0:
	.float 1.0
.global lbl_803E28A4
lbl_803E28A4:
	.4byte 0x00000000
.global lbl_803E28A8
lbl_803E28A8:
	.4byte 0x00000000
.global lbl_803E28AC
lbl_803E28AC:
	.float 1.0
.global lbl_803E28B0
lbl_803E28B0:
	.4byte 0x00000000
.global lbl_803E28B4
lbl_803E28B4:
	.float 1.0
.global lbl_803E28B8
lbl_803E28B8:
	.4byte 0x00000000
.global lbl_803E28BC
lbl_803E28BC:
	.4byte 0x00000000
	.4byte 0x802C2520
	.4byte 0x00000000
	.4byte 0x802C2544
	.4byte 0x00000000
	.4byte 0x802C2584
	.4byte 0x00000000
	.4byte 0x4B456666
	.4byte 0x65637400
.global __RTTI__7KEffect_1
__RTTI__7KEffect_1:
	.4byte 0x803E28D8
	.4byte 0x802C25B0
.global __RTTI__10BurnEffect
__RTTI__10BurnEffect:
	.4byte 0x802C2514
	.4byte 0x802C25CC
.global __RTTI__12RippleEffect
__RTTI__12RippleEffect:
	.4byte 0x802C262C
	.4byte 0x802C263C
.global __RTTI__15FreeLightEffect
__RTTI__15FreeLightEffect:
	.4byte 0x802C269C
	.4byte 0x802C26AC
.global __RTTI__16UfoSuikomiEffect
__RTTI__16UfoSuikomiEffect:
	.4byte 0x802C270C
	.4byte 0x802C2720
.global __RTTI__15WhistleTemplate
__RTTI__15WhistleTemplate:
	.4byte 0x802C2790
	.4byte 0x802C27A0
.global __RTTI__13UfoSuckEffect
__RTTI__13UfoSuckEffect:
	.4byte 0x802C2780
	.4byte 0x802C27C4
.global __RTTI__15BombEffectLight
__RTTI__15BombEffectLight:
	.4byte 0x802C2868
	.4byte 0x802C2878
.global __RTTI__10BombEffect
__RTTI__10BombEffect:
	.4byte 0x802C28D8
	.4byte 0x802C28E4
.global __RTTI__12SimpleEffect
__RTTI__12SimpleEffect:
	.4byte 0x802C2944
	.4byte 0x802C2954
	.4byte 0x4E617669
	.4byte 0x46756500
.global __RTTI__7NaviFue
__RTTI__7NaviFue:
	.4byte 0x803E2930
	.4byte 0x802C29B4
.global __RTTI__15SmokeTreeEffect
__RTTI__15SmokeTreeEffect:
	.4byte 0x802C2A14
	.4byte 0x802C2A24
.global __RTTI__15SmokeRockEffect
__RTTI__15SmokeRockEffect:
	.4byte 0x802C2A84
	.4byte 0x802C2A94
.global __RTTI__16SmokeGrassEffect
__RTTI__16SmokeGrassEffect:
	.4byte 0x802C2AF4
	.4byte 0x802C2B08
.global __RTTI__15SmokeSoilEffect
__RTTI__15SmokeSoilEffect:
	.4byte 0x802C2B68
	.4byte 0x802C2B78
.global __RTTI__11NaviWhistle
__RTTI__11NaviWhistle:
	.4byte 0x802C2BD8
	.4byte 0x802C2BE4
.global __RTTI__10GoalEffect
__RTTI__10GoalEffect:
	.4byte 0x802C2C44
	.4byte 0x802C2C50
.global __RTTI__11SlimeEffect
__RTTI__11SlimeEffect:
	.4byte 0x802C2CB0
	.4byte 0x802C2CBC
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E2978
	.4byte 0
	.4byte 0x802C2DAC
	.4byte 0x802C2DB8
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803E2990
	.4byte 0x802C2DC4
.global __RTTI__10Controller_1
__RTTI__10Controller_1:
	.4byte 0x802C2DD8
	.4byte 0x802C2DE4
.global __RTTI__10Kontroller
__RTTI__10Kontroller:
	.4byte 0x802C2D90
	.4byte 0x802C2E00
.global lbl_803E29B0
lbl_803E29B0:
	.4byte 0x00000000
.global lbl_803E29B4
lbl_803E29B4:
	.4byte 0x00000000
.global lbl_803E29B8
lbl_803E29B8:
	.4byte 0x00000000
.global lbl_803E29BC
lbl_803E29BC:
	.4byte 0x00000000
.global lbl_803E29C0
lbl_803E29C0:
	.4byte 0x00000000
.global lbl_803E29C4
lbl_803E29C4:
	.4byte 0x40800000
.global lbl_803E29C8
lbl_803E29C8:
	.4byte 0x00000000
.global lbl_803E29CC
lbl_803E29CC:
	.4byte 0x40800000
.global lbl_803E29D0
lbl_803E29D0:
	.4byte 0x7061726D
	.4byte 0x732F0000
	.4byte 0x4E617669
	.4byte 0x4D677200
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E29E0
	.4byte 0x00000000
	.4byte 0x802C2F00
	.4byte 0x802C2F0C
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803E29F8
	.4byte 0x802C2F18
	.4byte 0x802C2F2C
	.4byte 0x00000000
	.4byte 0x802C2F38
	.4byte 0x802C2F44
	.4byte 0x802C2F68
	.4byte 0x802C2F78
.global __RTTI__7NaviMgr
__RTTI__7NaviMgr:
	.4byte 0x803E29D8
	.4byte 0x802C2FA4
.global lbl_803E2A28
lbl_803E2A28:
	.4byte 0x00000000
.global lbl_803E2A2C
lbl_803E2A2C:
	.4byte 0x00000000
.global lbl_803E2A30
lbl_803E2A30:
	.4byte 0x00000000
.global lbl_803E2A34
lbl_803E2A34:
	.4byte 0x00000000
.global lbl_803E2A38
lbl_803E2A38:
	.4byte 0x00000000
.global lbl_803E2A3C
lbl_803E2A3C:
	.4byte 0x00000000
.global numShapes
numShapes:
	.4byte 0x00000005
	.4byte 0x626F7800
	.4byte 0x31000000
	.4byte 0x32000000
	.4byte 0x33000000
	.4byte 0x6C6F6700
	.4byte 0x736C6964
	.4byte 0x65720000
	.4byte 0x656E7469
	.4byte 0x74790000
	.4byte 0x64796E61
	.4byte 0x6D696300
.global lbl_803E2A70
lbl_803E2A70:
	.4byte 0x70303000
.global lbl_803E2A74
lbl_803E2A74:
	.4byte 0x70303100
.global lbl_803E2A78
lbl_803E2A78:
	.4byte 0x70303200
.global lbl_803E2A7C
lbl_803E2A7C:
	.4byte 0x70303400
.global lbl_803E2A80
lbl_803E2A80:
	.4byte 0x70303300
.global lbl_803E2A84
lbl_803E2A84:
	.float 1.0
.global lbl_803E2A88
lbl_803E2A88:
	.float 1.0
.global lbl_803E2A8C
lbl_803E2A8C:
	.float 1.0
.global lbl_803E2A90
lbl_803E2A90:
	.4byte 0x00000000
.global lbl_803E2A94
lbl_803E2A94:
	.4byte 0x00000000
.global lbl_803E2A98
lbl_803E2A98:
	.4byte 0x00000000
.global lbl_803E2A9C
lbl_803E2A9C:
	.float 1.0
.global lbl_803E2AA0
lbl_803E2AA0:
	.float 1.0
.global lbl_803E2AA4
lbl_803E2AA4:
	.float 1.0
.global lbl_803E2AA8
lbl_803E2AA8:
	.4byte 0x00000000
.global lbl_803E2AAC
lbl_803E2AAC:
	.4byte 0x00000000
.global lbl_803E2AB0
lbl_803E2AB0:
	.4byte 0x00000000
.global lbl_803E2AB4
lbl_803E2AB4:
	.4byte 0x00000000
.global lbl_803E2AB8
lbl_803E2AB8:
	.4byte 0x00000000
.global lbl_803E2ABC
lbl_803E2ABC:
	.4byte 0x00000000
.global lbl_803E2AC0
lbl_803E2AC0:
	.4byte 0x00000000
.global lbl_803E2AC4
lbl_803E2AC4:
	.4byte 0x00000000
.global lbl_803E2AC8
lbl_803E2AC8:
	.4byte 0x00000000
	.4byte 0x802C30E4
	.4byte 0x00000000
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803E2AD4
	.4byte 0x802C30F0
	.4byte 0x802C30FC
	.4byte 0x802C3108
.global __RTTI__17GenObjectMapParts
__RTTI__17GenObjectMapParts:
	.4byte 0x802C30D0
	.4byte 0x802C311C
	.4byte 0x802C317C
	.4byte 0
	.4byte 0
.global lbl_803E2B00
lbl_803E2B00:
	.4byte 0x00000000
.global lbl_803E2B04
lbl_803E2B04:
	.4byte 0x00000000
.global lbl_803E2B08
lbl_803E2B08:
	.4byte 0x00000000
.global lbl_803E2B0C
lbl_803E2B0C:
	.4byte 0x3DCCCCCD
.global lbl_803E2B10
lbl_803E2B10:
	.4byte 0x00000000
.global lbl_803E2B14
lbl_803E2B14:
	.4byte 0x00000000
.global lbl_803E2B18
lbl_803E2B18:
	.4byte 0x00000000
.global lbl_803E2B1C
lbl_803E2B1C:
	.4byte 0x00000000
.global lbl_803E2B20
lbl_803E2B20:
	.4byte 0x00000000
.global lbl_803E2B24
lbl_803E2B24:
	.4byte 0x00000000
.global lbl_803E2B28
lbl_803E2B28:
	.4byte 0x00000000
.global lbl_803E2B2C
lbl_803E2B2C:
	.4byte 0x41A00000
.global lbl_803E2B30
lbl_803E2B30:
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E2B34
	.4byte 0x00000000
	.4byte 0x802C3270
	.4byte 0x802C327C
	.4byte 0x4E6F6465
	.4byte 0x00000000
	.4byte 0x803E2B4C
	.4byte 0x802C3288
	.4byte 0x802C329C
	.4byte 0x802C32AC
.global __RTTI__12DynCollShape_3
__RTTI__12DynCollShape_3:
	.4byte 0x802C32C8
	.4byte 0x802C32D8
.global __RTTI__8MapParts
__RTTI__8MapParts:
	.4byte 0x802C32FC
	.4byte 0x802C3308
.global __RTTI__9MapSlider
__RTTI__9MapSlider:
	.4byte 0x802C3264
	.4byte 0x802C3334
.global __RTTI__9MapEntity
__RTTI__9MapEntity:
	.4byte 0x802C33B4
	.4byte 0x802C33C0
	.4byte 0
	.4byte 0x52554E00
	.4byte 0x4E494745
	.4byte 0x52550000
	.4byte 0x57414C4B
	.4byte 0
	.4byte 0x57414954
	.4byte 0
	.4byte 0x5049434B
	.4byte 0
	.4byte 0x4E554B55
	.4byte 0
	.4byte 0x44454144
	.4byte 0
	.4byte 0x44454144
	.4byte 0x32000000
	.4byte 0x44454144
	.4byte 0x33000000
	.4byte 0x44414D41
	.4byte 0x47450000
	.4byte 0x41534942
	.4byte 0x554D4900
	.4byte 0x4F434152
	.4byte 0x52590000
	.4byte 0x4C535542
	.4byte 0x45525500
	.4byte 0x52535542
	.4byte 0x45525500
	.4byte 0x4A4F4231
	.4byte 0
	.4byte 0x47524F57
	.4byte 0x55503100
	.4byte 0x47524F57
	.4byte 0x55503200
	.4byte 0x4A4F4232
	.4byte 0
	.4byte 0x4B4F524F
	.4byte 0x42550000
	.4byte 0x4A554D50
	.4byte 0
	.4byte 0x41545441
	.4byte 0x434B0000
	.4byte 0x50554E43
	.4byte 0x48000000
	.4byte 0x4B454E4B
	.4byte 0x41000000
	.4byte 0x5448524F
	.4byte 0x57000000
	.4byte 0x48414E47
	.4byte 0
	.4byte 0x46414C4C
	.4byte 0
	.4byte 0x4A4B4F4B
	.4byte 0x45000000
	.4byte 0x4A484954
	.4byte 0
	.4byte 0x47455455
	.4byte 0x50000000
	.4byte 0x4E45574A
	.4byte 0x4D500000
	.4byte 0x524F4C4C
	.4byte 0x4A4D5000
	.4byte 0x57415645
	.4byte 0x4A4D5000
	.4byte 0x50555348
	.4byte 0
	.4byte 0x554D4152
	.4byte 0x55000000
	.4byte 0x414B5542
	.4byte 0x49000000
	.4byte 0x52494E42
	.4byte 0x4F570000
	.4byte 0x49524149
	.4byte 0x52410000
	.4byte 0x4B414946
	.4byte 0x554B5500
	.4byte 0x4B495A55
	.4byte 0x4B550000
	.4byte 0x4B555454
	.4byte 0x554B5500
	.4byte 0x46554500
	.4byte 0x53555741
	.4byte 0x52550000
	.4byte 0x414F4755
	.4byte 0
	.4byte 0x4E455255
	.4byte 0
	.4byte 0x50524553
	.4byte 0x53310000
	.4byte 0x50524553
	.4byte 0x53320000
	.4byte 0x53505245
	.4byte 0x53530000
	.4byte 0x4F424F52
	.4byte 0x45525500
	.4byte 0x53495A55
	.4byte 0x4D550000
	.4byte 0x4F54494B
	.4byte 0x414B4500
	.4byte 0x4F544952
	.4byte 0x55000000
	.4byte 0x484E4F42
	.4byte 0x4F525500
	.4byte 0x4E4F424F
	.4byte 0x52550000
	.4byte 0x53414741
	.4byte 0x53553200
	.4byte 0x50756E63
	.4byte 0x68210000
	.4byte 0x4D4F4552
	.4byte 0x55000000
	.4byte 0x45534100
	.4byte 0x47415454
	.4byte 0x55000000
	.4byte 0x47414B4B
	.4byte 0x41524900
	.4byte 0x4F4B4F52
	.4byte 0x55000000
	.4byte 0x524F544A
	.4byte 0x554D5000
	.4byte 0x67776169
	.4byte 0x74310000
	.4byte 0x67776169
	.4byte 0x74320000
	.4byte 0x67667572
	.4byte 0x69310000
	.4byte 0x67667572
	.4byte 0x69320000
	.4byte 0x676E756B
	.4byte 0x65000000
	.4byte 0x6A756D70
	.4byte 0x20623100
	.4byte 0x6D697A75
	.4byte 0x61676500
	.4byte 0x73616761
	.4byte 0x73750000
	.4byte 0x6F737500
	.4byte 0x6E6F7275
	.4byte 0
	.4byte 0x6F646561
	.4byte 0x64000000
	.4byte 0x802C3768
	.4byte 0
	.4byte 0x802C3774
	.4byte 0x802C3784
.global __RTTI__16PaniPikiAnimator
__RTTI__16PaniPikiAnimator:
	.4byte 0x802C3754
	.4byte 0x802C3790
	.4byte 0x802C3818
	.4byte 0
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803E2DD8
	.4byte 0x802C3824
	.4byte 0x802C3830
	.4byte 0x802C383C
.global __RTTI__14GenObjectActor
__RTTI__14GenObjectActor:
	.4byte 0x802C3808
	.4byte 0x802C3850
.global lbl_803E2DF8
lbl_803E2DF8:
	.4byte 0x3C4E6F64
	.4byte 0x653E0000
.global lbl_803E2E00
lbl_803E2E00:
	.4byte 0x636E6F64
	.4byte 0x65000000
.global lbl_803E2E08
lbl_803E2E08:
	.4byte 0x73303000
.global lbl_803E2E0C
lbl_803E2E0C:
	.4byte 0x73303100
.global lbl_803E2E10
lbl_803E2E10:
	.4byte 0x73303200
.global lbl_803E2E14
lbl_803E2E14:
	.4byte 0x73303300
.global lbl_803E2E18
lbl_803E2E18:
	.4byte 0x73303400
	.4byte 0x636C6F76
	.4byte 0x65720000
	.4byte 0x63686964
	.4byte 0x6F6D6500
	.4byte 0x68757461
	.4byte 0x62610000
	.4byte 0x696E6500
	.4byte 0x74616E70
	.4byte 0x6F706F00
	.4byte 0x6F6F696E
	.4byte 0x755F6C00
	.4byte 0x6F6F696E
	.4byte 0x755F7300
	.4byte 0x68616500
.global lbl_803E2E54
lbl_803E2E54:
	.4byte 0x25730000
.global lbl_803E2E58
lbl_803E2E58:
	.4byte 0x25732E62
	.4byte 0x696E0000
	.4byte 0x802C39A4
	.4byte 0x00000000
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803E2E68
	.4byte 0x802C39B0
	.4byte 0x802C39BC
	.4byte 0x802C39C8
.global __RTTI__14GenObjectPlant
__RTTI__14GenObjectPlant:
	.4byte 0x802C3994
	.4byte 0x802C39DC
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803E2E88
	.4byte 0
	.4byte lbl_802C38C4
	.4byte 0x802C3A3C
	.4byte 0x4E6F6465
	.4byte 0
	.4byte 0x803E2EA0
	.4byte 0x802C3A48
	.4byte 0x802C3A5C
	.4byte 0
	.4byte 0x802C3A68
	.4byte 0x802C3A74
.global __RTTI__15CreatureNodeMgr_2
__RTTI__15CreatureNodeMgr_2:
	.4byte 0x802C3A98
	.4byte 0x802C3AA8
.global __RTTI__8PlantMgr
__RTTI__8PlantMgr:
	.4byte 0x802C3A30
	.4byte 0x802C3AD4
	.4byte 0x802C3B90
	.4byte 0
.global __RTTI__Q28PlantMgr7UseNode
__RTTI__Q28PlantMgr7UseNode:
	.4byte 0x802C3BD8
	.4byte 0x802C3BEC
.global __RTTI__9SAIAction_1
__RTTI__9SAIAction_1:
	.4byte 0x802C3C70
	.4byte 0
.global __RTTI__Q27PlantAI9TouchInit
__RTTI__Q27PlantAI9TouchInit:
	.4byte 0x802C3C5C
	.4byte 0x802C3C7C
.global __RTTI__Q27PlantAI8WaitInit
__RTTI__Q27PlantAI8WaitInit:
	.4byte 0x802C3C94
	.4byte 0x802C3CA8
.global __RTTI__12SAICondition_2
__RTTI__12SAICondition_2:
	.4byte 0x802C3CD8
	.4byte 0x802C3CE8
.global __RTTI__Q27PlantAI12OpponentMove
__RTTI__Q27PlantAI12OpponentMove:
	.4byte 0x802C3CC0
	.4byte 0x802C3CFC
	.4byte 0x506C616E
	.4byte 0x74414900
.global "__RTTI__26StateMachine<10AICreature>_2"
"__RTTI__26StateMachine<10AICreature>_2":
	.4byte 0x802C3D68
	.4byte 0
.global __RTTI__8SimpleAI_2
__RTTI__8SimpleAI_2:
	.4byte 0x802C3D84
	.4byte 0x802C3D90
.global __RTTI__7PlantAI
__RTTI__7PlantAI:
	.4byte 0x803E2F08
	.4byte 0x802C3D9C
	.4byte 0x506C616E
	.4byte 0x74000000
	.4byte 0x802C3DC8
	.4byte 0
	.4byte 0x802C3DDC
	.4byte 0
	.4byte 0x802C3DE8
	.4byte 0
	.4byte 0x802C3DF8
	.4byte 0x802C3E04
	.4byte 0x802C3E18
	.4byte 0x802C3E24
.global __RTTI__5Plant
__RTTI__5Plant:
	.4byte 0x803E2F28
	.4byte 0x802C3E48
	.4byte 0x31000000
	.4byte 0x32000000
	.4byte 0x33000000
	.4byte 0x34000000
	.4byte 0x35000000
	.4byte 0x36000000
	.4byte 0x37000000
	.4byte 0x802C402C
	.4byte 0
	.4byte 0x802C4038
	.4byte 0x802C4048
.global __RTTI__17PaniPlantAnimator
__RTTI__17PaniPlantAnimator:
	.4byte 0x802C4018
	.4byte 0x802C4054
	.4byte 0
	.4byte 0x802C40C8
	.4byte 0
	.4byte 0x47656E42
	.4byte 0x61736500
	.4byte 0x803E2FA0
	.4byte 0x802C40D4
	.4byte 0x802C40E0
	.4byte 0x802C40EC
.global __RTTI__13GenObjectTeki
__RTTI__13GenObjectTeki:
	.4byte 0x802C40B8
	.4byte 0x802C4100
.global __RTTI__9NFunction
__RTTI__9NFunction:
	.4byte 0x802C4190
	.4byte 0
.global __RTTI__18NVibrationFunction
__RTTI__18NVibrationFunction:
	.4byte 0x802C417C
	.4byte 0x802C419C
.global __RTTI__19NPolynomialFunction
__RTTI__19NPolynomialFunction:
	.4byte 0x802C41CC
	.4byte 0x802C41E0
.global __RTTI__15NLinearFunction
__RTTI__15NLinearFunction:
	.4byte 0x802C41EC
	.4byte 0x802C41FC
.global __RTTI__20NClampLinearFunction
__RTTI__20NClampLinearFunction:
	.4byte 0x802C41B4
	.4byte 0x802C4210
.global lbl_803E2FE8
lbl_803E2FE8:
	.4byte 0x00000000
.global lbl_803E2FEC
lbl_803E2FEC:
	.4byte 0x00000000
.global lbl_803E2FF0
lbl_803E2FF0:
	.4byte 0x00000000
	.4byte 0x4E416C70
	.4byte 0x68610000
.global __RTTI__6NAlpha
__RTTI__6NAlpha:
	.4byte 0x803E2FF4
	.4byte 0
.global __RTTI__14NSpecialMatrix
__RTTI__14NSpecialMatrix:
	.4byte 0x802C42A4
	.4byte 0
.global __RTTI__8LUMatrix
__RTTI__8LUMatrix:
	.4byte 0x802C4298
	.4byte 0x802C42B4
.global __RTTI__12NUpperMatrix
__RTTI__12NUpperMatrix:
	.4byte 0x802C42CC
	.4byte 0x802C42DC
.global __RTTI__12NLowerMatrix
__RTTI__12NLowerMatrix:
	.4byte 0x802C42F4
	.4byte 0x802C4304
.global __RTTI__10NPosture3D
__RTTI__10NPosture3D:
	.4byte 0x802C4328
	.4byte 0
.global __RTTI__10NPosture2D
__RTTI__10NPosture2D:
	.4byte 0x802C4340
	.4byte 0
