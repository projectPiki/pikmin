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
	.float 0.1
.global lbl_803DDAC0
lbl_803DDAC0:
	.float 0.1
.global lbl_803DDAC4
lbl_803DDAC4:
	.float 0.1
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
	.float 0.1
.global lbl_803DDAE4
lbl_803DDAE4:
	.float 0.1
.global lbl_803DDAE8
lbl_803DDAE8:
	.float 0.1
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
	.float 0.1
.global lbl_803DDC0C
lbl_803DDC0C:
	.float 0.1
.global lbl_803DDC10
lbl_803DDC10:
	.float 0.1
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
	.float 0.1
.global lbl_803DE150
lbl_803DE150:
	.float 0.1
.global lbl_803DE154
lbl_803DE154:
	.float 0.1
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
.balign 4
.global lbl_803DE2F0
lbl_803DE2F0:
	.asciz "Z"
.balign 4
.global lbl_803DE2F4
lbl_803DE2F4:
	.asciz "Y"
.balign 4
.global lbl_803DE2F8
lbl_803DE2F8:
	.asciz "X"
.balign 4
.global lbl_803DE2FC
lbl_803DE2FC:
	.asciz "A"
.balign 4
.global lbl_803DE300
lbl_803DE300:
	.asciz "%s = %d"
.balign 4
.global lbl_803DE308
lbl_803DE308:
	.asciz "B"
.balign 4
.global lbl_803DE30C
lbl_803DE30C:
	.asciz "G"
.balign 4
.global lbl_803DE310
lbl_803DE310:
	.asciz "R"
.balign 4
.global lbl_803DE314
lbl_803DE314:
	.asciz "Far"
.balign 4
.global lbl_803DE318
lbl_803DE318:
	.asciz "Near"
.balign 4
.global lbl_803DE320
lbl_803DE320:
	.asciz "OFF"
.balign 4
.global lbl_803DE324
lbl_803DE324:
	.asciz "POINT"
.balign 4
.global lbl_803DE32C
lbl_803DE32C:
	.asciz "SPOT"
.balign 4
.global lightTypes
lightTypes:
	.4byte 0x00000001
	.4byte 0x00000003
.balign 4
lbl_803DE33C:
	.asciz "global"
.balign 4
.global lightMoveNames
lightMoveNames:
	.4byte lbl_803DE33C
	.4byte lbl_802A962C
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
.balign 4
.global lbl_803DE3D4
lbl_803DE3D4:
	.asciz "night"
.balign 4
.global lbl_803DE3DC
lbl_803DE3DC:
	.asciz "morning"
.balign 4
.global lbl_803DE3E4
lbl_803DE3E4:
	.asciz "day"
.balign 4
.global lbl_803DE3E8
lbl_803DE3E8:
	.asciz "evening"
.balign 4
.global lbl_803DE3F0
lbl_803DE3F0:
	.asciz "movie"
.balign 4
.global lbl_803DE3F8
lbl_803DE3F8:
	.asciz "+1"
.balign 4
.global lbl_803DE3FC
lbl_803DE3FC:
	.asciz "+2"
.balign 4
.global lbl_803DE400
lbl_803DE400:
	.asciz "+3"
.balign 4
.global lbl_803DE404
lbl_803DE404:
	.asciz "+4"
.balign 4
.global lbl_803DE408
lbl_803DE408:
	.asciz "+5"
.balign 4
.global lbl_803DE40C
lbl_803DE40C:
	.asciz "%d"
.balign 4
.global lbl_803DE410
lbl_803DE410:
	.asciz "light"
.balign 4
.global lbl_803DE418
lbl_803DE418:
	.asciz "type"
.balign 4
.global lbl_803DE420
lbl_803DE420:
	.asciz "attach"
.balign 4
.global lbl_803DE428
lbl_803DE428:
	.asciz "fov"
.balign 4
.global lbl_803DE42C
lbl_803DE42C:
	.asciz "%f"
.balign 4
.global lbl_803DE430
lbl_803DE430:
	.asciz "ambient"
.balign 4
.global lbl_803DE438
lbl_803DE438:
	.asciz "dist"
.balign 4
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
	.4byte p_icon_palette
.balign 4
.global lbl_803DE7D4
lbl_803DE7D4:
	.asciz "Pikmin"
.balign 4
.global lbl_803DE7DC
lbl_803DE7DC:
	.asciz "~Pikmin"
.balign 4
.global lbl_803DE7E4
lbl_803DE7E4:
	.asciz "Blocks"
.balign 4
.global lbl_803DE7EC
lbl_803DE7EC:
	.asciz "%s"
.balign 4
.global lbl_803DE7F0
lbl_803DE7F0:
	.asciz "banner"
.balign 4
lbl_803DE7F8:
	.asciz "ANode"
.balign 4
	.4byte lbl_803DE7F8
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
	.float 0.1
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
.balign 4
.global lbl_803DF31C
lbl_803DF31C:
	.asciz "aiGrid"
.balign 4
	.4byte 0x00000000
	.4byte 0x802AFA84
	.4byte 0x00000000
	.4byte 0x802AFA90
	.4byte 0x00000000
	.4byte 0x802AFAA0
	.4byte 0x802AFAAC
	.4byte 0x802AFA74
	.4byte 0x802AFAC0
.balign 4
.global lbl_803DF348
lbl_803DF348:
	.asciz "piki"
.balign 4
.global lbl_803DF350
lbl_803DF350:
	.asciz "teki"
.balign 4
.global lbl_803DF358
lbl_803DF358:
	.asciz "navi"
.balign 4
.global lbl_803DF360
lbl_803DF360:
	.asciz "water"
.balign 4
.global lbl_803DF368
lbl_803DF368:
	.asciz "seed"
.balign 4
.global lbl_803DF370
lbl_803DF370:
	.asciz "key"
.balign 4
.global lbl_803DF374
lbl_803DF374:
	.asciz "door"
.balign 4
.global lbl_803DF37C
lbl_803DF37C:
	.asciz "gate"
.balign 4
.global lbl_803DF384
lbl_803DF384:
	.asciz "gem5"
.balign 4
.global lbl_803DF38C
lbl_803DF38C:
	.asciz "gem10"
.balign 4
.global lbl_803DF394
lbl_803DF394:
	.asciz "gem20"
.balign 4
.global lbl_803DF39C
lbl_803DF39C:
	.asciz "gem50"
.balign 4
.global lbl_803DF3A4
lbl_803DF3A4:
	.asciz "gem1"
.balign 4
.global lbl_803DF3AC
lbl_803DF3AC:
	.asciz "bomb"
.balign 4
.global lbl_803DF3B4
lbl_803DF3B4:
	.asciz "goal"
.balign 4
.global lbl_803DF3BC
lbl_803DF3BC:
	.asciz "fulcrum"
.balign 4
.global lbl_803DF3C4
lbl_803DF3C4:
	.asciz "rope"
.balign 4
.global lbl_803DF3CC
lbl_803DF3CC:
	.asciz "ivy"
.balign 4
.global lbl_803DF3D0
lbl_803DF3D0:
	.asciz "rocket"
.balign 4
.global lbl_803DF3D8
lbl_803DF3D8:
	.asciz "kusa"
.balign 4
.global lbl_803DF3E0
lbl_803DF3E0:
	.asciz "ufo"
.balign 4
.global lbl_803DF3E4
lbl_803DF3E4:
	.asciz "weeds"
.balign 4
.global lbl_803DF3EC
lbl_803DF3EC:
	.asciz "<weed>"
.balign 4
.global lbl_803DF3F4
lbl_803DF3F4:
	.asciz "rockgen"
.balign 4
.global lbl_803DF3FC
lbl_803DF3FC:
	.asciz "fish"
.balign 4
.global lbl_803DF404
lbl_803DF404:
	.asciz "secret1"
.balign 4
.global lbl_803DF40C
lbl_803DF40C:
	.asciz "PLANT"
.balign 4
.global lbl_803DF414
lbl_803DF414:
	.asciz "PELLET"
.balign 4
.global lbl_803DF41C
lbl_803DF41C:
	.asciz ""
.balign 4
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
.global lbl_803DFA88
lbl_803DFA88:
	.asciz "dummy 1"
.balign 4
.global lbl_803DFA90
lbl_803DFA90:
	.asciz "dummy 2"
.balign 4
.global lbl_803DFA98
lbl_803DFA98:
	.asciz "dummy 3"
.balign 4
.global lbl_803DFAA0
lbl_803DFAA0:
	.asciz "dummy 4"
.balign 4
.global lbl_803DFAA8
lbl_803DFAA8:
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
	.float 0.1
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
	.byte 1
.balign 4
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
