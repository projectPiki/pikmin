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
	.4byte 0
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
	.4byte 0
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
	.4byte 0
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
	.4byte 0
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
	.4byte 0
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
	.4byte 0
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
	.4byte 0
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
	.4byte 0
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
	.4byte 0
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
	.4byte 0
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
	.4byte 0
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
.balign 8
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
