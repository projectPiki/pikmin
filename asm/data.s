.include "macros.inc"
.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.global lbl_80222DC0
lbl_80222DC0:
	.incbin "baserom.dol", 0x21FDC0, 0x10
.global lbl_80222DD0
lbl_80222DD0:
	.incbin "baserom.dol", 0x21FDD0, 0x10
.global J_STREAMNAME
J_STREAMNAME:
	.incbin "baserom.dol", 0x21FDE0, 0x80
.global J_STREAM
J_STREAM:
	.incbin "baserom.dol", 0x21FE60, 0x2C
.global lbl_80222E8C
lbl_80222E8C:
	.incbin "baserom.dol", 0x21FE8C, 0x24
.global audio_root_path
audio_root_path:
	.incbin "baserom.dol", 0x21FEB0, 0x30
.global jdsp
jdsp:
	.incbin "baserom.dol", 0x21FEE0, 0x1A00
.global calc_sw_table
calc_sw_table:
	.incbin "baserom.dol", 0x2218E0, 0x54
.global lbl_80224934
lbl_80224934:
	.incbin "baserom.dol", 0x221934, 0x20
.global lbl_80224954
lbl_80224954:
	.incbin "baserom.dol", 0x221954, 0x24
.global history
history:
	.incbin "baserom.dol", 0x221978, 0x28
.global connect_table$94
connect_table$94:
	.incbin "baserom.dol", 0x2219A0, 0x20
.global DSPADPCM_FILTER
DSPADPCM_FILTER:
	.incbin "baserom.dol", 0x2219C0, 0x40
.global DSPRES_FILTER
DSPRES_FILTER:
	.incbin "baserom.dol", 0x221A00, 0x400
.global SEND_TABLE
SEND_TABLE:
	.incbin "baserom.dol", 0x221E00, 0x18
.global C5BASE_PITCHTABLE
C5BASE_PITCHTABLE:
	.incbin "baserom.dol", 0x221E18, 0x200
.global FORCE_RELEASE_TABLE
FORCE_RELEASE_TABLE:
	.incbin "baserom.dol", 0x222018, 0x10
.global extdir
extdir:
	.incbin "baserom.dol", 0x222028, 0x40
.global lbl_80225068
lbl_80225068:
	.incbin "baserom.dol", 0x222068, 0x34
.global lbl_8022509C
lbl_8022509C:
	.incbin "baserom.dol", 0x22209C, 0x44
.global lbl_802250E0
lbl_802250E0:
	.incbin "baserom.dol", 0x2220E0, 0x44
.global Arglist
Arglist:
	.incbin "baserom.dol", 0x222124, 0x100
.global CMDP_LIST
CMDP_LIST:
	.incbin "baserom.dol", 0x222224, 0x104
.global CUTOFF_TO_IIR_TABLE
CUTOFF_TO_IIR_TABLE:
	.incbin "baserom.dol", 0x222328, 0x400
.global KEY_TABLE
KEY_TABLE:
	.incbin "baserom.dol", 0x222728, 0x100
.global VIB_TABLE
VIB_TABLE:
	.incbin "baserom.dol", 0x222828, 0x24
.global TRE_TABLE
TRE_TABLE:
	.incbin "baserom.dol", 0x22284C, 0x24
.global REL_TABLE
REL_TABLE:
	.incbin "baserom.dol", 0x222870, 0xC
.global VIBRATO_DEF
VIBRATO_DEF:
	.incbin "baserom.dol", 0x22287C, 0x18
.global TREMOLO_DEF
TREMOLO_DEF:
	.incbin "baserom.dol", 0x222894, 0x18
.global ENVELOPE_DEF
ENVELOPE_DEF:
	.incbin "baserom.dol", 0x2228AC, 0x18
.global ADS_TABLE
ADS_TABLE:
	.incbin "baserom.dol", 0x2228C4, 0x18
.global ADSR_DEF
ADSR_DEF:
	.incbin "baserom.dol", 0x2228DC, 0x18
.global OSC_DEF
OSC_DEF:
	.incbin "baserom.dol", 0x2228F4, 0x1C
.global PERC_ENV
PERC_ENV:
	.incbin "baserom.dol", 0x222910, 0x18
.global OSC_ENV
OSC_ENV:
	.incbin "baserom.dol", 0x222928, 0x18
.global polys_table
polys_table:
	.incbin "baserom.dol", 0x222940, 0x10
.global lbl_80225950
lbl_80225950:
	.incbin "baserom.dol", 0x222950, 0x98
.global fx_config$180
fx_config$180:
	.incbin "baserom.dol", 0x2229E8, 0x80
.global EVENT_OFFSET
EVENT_OFFSET:
	.incbin "baserom.dol", 0x222A68, 0x20
.global ACTION_STATUS
ACTION_STATUS:
	.incbin "baserom.dol", 0x222A88, 0x684
.global EVENT_DIST_SCALE
EVENT_DIST_SCALE:
	.incbin "baserom.dol", 0x22310C, 0x24
.global bgm_mute_set
bgm_mute_set:
	.incbin "baserom.dol", 0x223130, 0x50
.global bgm_volume_set
bgm_volume_set:
	.incbin "baserom.dol", 0x223180, 0x50
.global GAMEBGM_VOL_TABLE
GAMEBGM_VOL_TABLE:
	.incbin "baserom.dol", 0x2231D0, 0x2C
.global GAMEDEMO_VOL_TABLE
GAMEDEMO_VOL_TABLE:
	.incbin "baserom.dol", 0x2231FC, 0x18
.global GAMESE_VOL_TABLE
GAMESE_VOL_TABLE:
	.incbin "baserom.dol", 0x223214, 0x18
.global GAMESTREAM_VOL_TABLE
GAMESTREAM_VOL_TABLE:
	.incbin "baserom.dol", 0x22322C, 0x1C
.global tbl_scene_to_bgm
tbl_scene_to_bgm:
	.incbin "baserom.dol", 0x223248, 0x38
.global tbl_scene_to_fadetime
tbl_scene_to_fadetime:
	.incbin "baserom.dol", 0x223280, 0x38
.global tbl_stage_to_bgm
tbl_stage_to_bgm:
	.incbin "baserom.dol", 0x2232B8, 0x14
.global filelist
filelist:
	.incbin "baserom.dol", 0x2232CC, 0x1C0
.global header
header:
	.incbin "baserom.dol", 0x22348C, 0x24
.global parts_bright_table
parts_bright_table:
	.incbin "baserom.dol", 0x2234B0, 0x20
.global demo4
demo4:
	.incbin "baserom.dol", 0x2234D0, 0x2C
.global demo5
demo5:
	.incbin "baserom.dol", 0x2234FC, 0x28
.global demo9
demo9:
	.incbin "baserom.dol", 0x223524, 0xC
.global demo16
demo16:
	.incbin "baserom.dol", 0x223530, 0x24
.global demo17
demo17:
	.incbin "baserom.dol", 0x223554, 0x54
.global demo18
demo18:
	.incbin "baserom.dol", 0x2235A8, 0x10
.global demo19
demo19:
	.incbin "baserom.dol", 0x2235B8, 0x2C
.global demo20
demo20:
	.incbin "baserom.dol", 0x2235E4, 0x28
.global demo21
demo21:
	.incbin "baserom.dol", 0x22360C, 0x28
.global demo24
demo24:
	.incbin "baserom.dol", 0x223634, 0x28
.global demo25
demo25:
	.incbin "baserom.dol", 0x22365C, 0x20
.global demo26
demo26:
	.incbin "baserom.dol", 0x22367C, 0x34
.global demo28
demo28:
	.incbin "baserom.dol", 0x2236B0, 0x7C
.global demo29
demo29:
	.incbin "baserom.dol", 0x22372C, 0x7C
.global demo32
demo32:
	.incbin "baserom.dol", 0x2237A8, 0xC
.global demo40
demo40:
	.incbin "baserom.dol", 0x2237B4, 0x14
.global demo47
demo47:
	.incbin "baserom.dol", 0x2237C8, 0x2C
.global demo52
demo52:
	.incbin "baserom.dol", 0x2237F4, 0x34
.global demo56
demo56:
	.incbin "baserom.dol", 0x223828, 0x40
.global demo69
demo69:
	.incbin "baserom.dol", 0x223868, 0x14
.global demo73
demo73:
	.incbin "baserom.dol", 0x22387C, 0x34
.global demo74
demo74:
	.incbin "baserom.dol", 0x2238B0, 0x38
.global demo75
demo75:
	.incbin "baserom.dol", 0x2238E8, 0x28
.global demo76
demo76:
	.incbin "baserom.dol", 0x223910, 0x14
.global demo100
demo100:
	.incbin "baserom.dol", 0x223924, 0x18
.global demo101
demo101:
	.incbin "baserom.dol", 0x22393C, 0x20
.global demo113
demo113:
	.incbin "baserom.dol", 0x22395C, 0x48
.global demo114
demo114:
	.incbin "baserom.dol", 0x2239A4, 0xC
.global DEMO_STATUS
DEMO_STATUS:
	.incbin "baserom.dol", 0x2239B0, 0x564
.global lbl_80226F14
lbl_80226F14:
	.incbin "baserom.dol", 0x223F14, 0x2C
.global lbl_80226F40
lbl_80226F40:
	.incbin "baserom.dol", 0x223F40, 0x30
.global filter_table
filter_table:
	.incbin "baserom.dol", 0x223F70, 0x40
.global table4
table4:
	.incbin "baserom.dol", 0x223FB0, 0x30
.global HEAD_pikiseq
HEAD_pikiseq:
	.incbin "baserom.dol", 0x223FE0, 0x2E0
.global func$793
func$793:
	.incbin "baserom.dol", 0x2242C0, 0x1C
.global lbl_802272DC
lbl_802272DC:
	.incbin "baserom.dol", 0x2242DC, 0x54
.global __vt__7BaseApp
__vt__7BaseApp:
	.incbin "baserom.dol", 0x224330, 0x4C
.global __vt__8CoreNode
__vt__8CoreNode:
	.incbin "baserom.dol", 0x22437C, 0x10
.global __vt__5ANode
__vt__5ANode:
	.incbin "baserom.dol", 0x22438C, 0xC
.global __vt__6Stream
__vt__6Stream:
	.incbin "baserom.dol", 0x224398, 0xCC
.global __vt__19BufferedInputStream
__vt__19BufferedInputStream:
	.incbin "baserom.dol", 0x224464, 0x64
.global __vt__18RandomAccessStream
__vt__18RandomAccessStream:
	.incbin "baserom.dol", 0x2244C8, 0x78
.global lbl_80227540
lbl_80227540:
	.incbin "baserom.dol", 0x224540, 0x28
.global mappingTypes$1231
mappingTypes$1231:
	.incbin "baserom.dol", 0x224568, 0xC
.global sjis_convert_table
sjis_convert_table:
	.incbin "baserom.dol", 0x224574, 0x4CC
.global kanji_convert_table
kanji_convert_table:
	.incbin "baserom.dol", 0x224A40, 0x49C
.global convFmts
convFmts:
	.incbin "baserom.dol", 0x224EDC, 0xAC
.global fmtNames
fmtNames:
	.incbin "baserom.dol", 0x224F88, 0x20
.global lbl_80227FA8
lbl_80227FA8:
	.incbin "baserom.dol", 0x224FA8, 0x90
.global btitexFmts
btitexFmts:
	.incbin "baserom.dol", 0x225038, 0x60
.global btipalFmts
btipalFmts:
	.incbin "baserom.dol", 0x225098, 0x48
.global __vt__12CacheTexture
__vt__12CacheTexture:
	.incbin "baserom.dol", 0x2250E0, 0x40
.global __vt__7TexAttr
__vt__7TexAttr:
	.incbin "baserom.dol", 0x225120, 0x24
.global __vt__6TexImg
__vt__6TexImg:
	.incbin "baserom.dol", 0x225144, 0x10
.global __vt__8Graphics
__vt__8Graphics:
	.incbin "baserom.dol", 0x225154, 0x104
.global __vt__15MaterialHandler
__vt__15MaterialHandler:
	.incbin "baserom.dol", 0x225258, 0x30
.global __vt__8Material
__vt__8Material:
	.incbin "baserom.dol", 0x225288, 0x24
.global lbl_802282AC
lbl_802282AC:
	.incbin "baserom.dol", 0x2252AC, 0x48
.global __vt__5Light
__vt__5Light:
	.incbin "baserom.dol", 0x2252F4, 0x2C
.global lbl_80228320
lbl_80228320:
	.incbin "baserom.dol", 0x225320, 0x1C
.global modes
modes:
	.incbin "baserom.dol", 0x22533C, 0x14
.global lbl_80228350
lbl_80228350:
	.incbin "baserom.dol", 0x225350, 0x16C
.global lbl_802284BC
lbl_802284BC:
	.incbin "baserom.dol", 0x2254BC, 0xCC
.global lbl_80228588
lbl_80228588:
	.incbin "baserom.dol", 0x225588, 0xC4
.global lbl_8022864C
lbl_8022864C:
	.incbin "baserom.dol", 0x22564C, 0xC
.global lbl_80228658
lbl_80228658:
	.incbin "baserom.dol", 0x225658, 0xC
.global lbl_80228664
lbl_80228664:
	.incbin "baserom.dol", 0x225664, 0x30
.global __vt__10MatobjInfo
__vt__10MatobjInfo:
	.incbin "baserom.dol", 0x225694, 0x10
.global __vt__10GfxobjInfo
__vt__10GfxobjInfo:
	.incbin "baserom.dol", 0x2256A4, 0x3C
.global __vt__9BaseShape
__vt__9BaseShape:
	.incbin "baserom.dol", 0x2256E0, 0x84
.global __vt__32Delegate2$$09BaseShape$$4P5Joint$$4Ul$$1
__vt__32Delegate2$$09BaseShape$$4P5Joint$$4Ul$$1:
	.incbin "baserom.dol", 0x225764, 0xC
.global __vt__22IDelegate2$$0P5Joint$$4Ul$$1
__vt__22IDelegate2$$0P5Joint$$4Ul$$1:
	.incbin "baserom.dol", 0x225770, 0x2C
.global __vt__10LightFlare
__vt__10LightFlare:
	.incbin "baserom.dol", 0x22579C, 0x30
.global __vt__10LightGroup
__vt__10LightGroup:
	.incbin "baserom.dol", 0x2257CC, 0x30
.global __vt__11ObjCollInfo
__vt__11ObjCollInfo:
	.incbin "baserom.dol", 0x2257FC, 0x4C
.global __vt__7AnimDck
__vt__7AnimDck:
	.incbin "baserom.dol", 0x225848, 0x3C
.global __vt__7AnimDca
__vt__7AnimDca:
	.incbin "baserom.dol", 0x225884, 0x20
.global __vt__8AnimData
__vt__8AnimData:
	.incbin "baserom.dol", 0x2258A4, 0x2C
.global __vt__11AnimContext
__vt__11AnimContext:
	.incbin "baserom.dol", 0x2258D0, 0x30
.global __vt__Q25Joint7MatPoly
__vt__Q25Joint7MatPoly:
	.incbin "baserom.dol", 0x225900, 0x24
.global __vt__5Joint
__vt__5Joint:
	.incbin "baserom.dol", 0x225924, 0x24
.global __vt__4Mesh
__vt__4Mesh:
	.incbin "baserom.dol", 0x225948, 0x30
.global __vt__8FaceNode
__vt__8FaceNode:
	.incbin "baserom.dol", 0x225978, 0x4C
.global __vt__8DispList
__vt__8DispList:
	.incbin "baserom.dol", 0x2259C4, 0x14
.global lbl_802289D8
lbl_802289D8:
	.incbin "baserom.dol", 0x2259D8, 0xC
.global lbl_802289E4
lbl_802289E4:
	.incbin "baserom.dol", 0x2259E4, 0xC
.global lbl_802289F0
lbl_802289F0:
	.incbin "baserom.dol", 0x2259F0, 0x2C
.global lbl_80228A1C
lbl_80228A1C:
	.incbin "baserom.dol", 0x225A1C, 0x10
.global lbl_80228A2C
lbl_80228A2C:
	.incbin "baserom.dol", 0x225A2C, 0x118
.global __vt__10RouteGroup
__vt__10RouteGroup:
	.incbin "baserom.dol", 0x225B44, 0x18
.global __vt__8EditNode
__vt__8EditNode:
	.incbin "baserom.dol", 0x225B5C, 0x38
.global __vt__9RouteLink
__vt__9RouteLink:
	.incbin "baserom.dol", 0x225B94, 0x30
.global __vt__10RoutePoint
__vt__10RoutePoint:
	.incbin "baserom.dol", 0x225BC4, 0x2C
.global lbl_80228BF0
lbl_80228BF0:
	.incbin "baserom.dol", 0x225BF0, 0x68
.global __vt__10BinobjInfo
__vt__10BinobjInfo:
	.incbin "baserom.dol", 0x225C58, 0x3C
.global __vt__11LFlareGroup
__vt__11LFlareGroup:
	.incbin "baserom.dol", 0x225C94, 0x10
.global __vt__9StdSystem
__vt__9StdSystem:
	.incbin "baserom.dol", 0x225CA4, 0x4C
.global __vt__10TexobjInfo
__vt__10TexobjInfo:
	.incbin "baserom.dol", 0x225CF0, 0x28
.global __vt__10ShpobjInfo
__vt__10ShpobjInfo:
	.incbin "baserom.dol", 0x225D18, 0x54
.global __vt__10AnmobjInfo
__vt__10AnmobjInfo:
	.incbin "baserom.dol", 0x225D6C, 0x20
.global lbl_80228D8C
lbl_80228D8C:
	.incbin "baserom.dol", 0x225D8C, 0x48
.global __vt__7SRTNode
__vt__7SRTNode:
	.incbin "baserom.dol", 0x225DD4, 0x4C
.global __vt__4Node
__vt__4Node:
	.incbin "baserom.dol", 0x225E20, 0x94
.global __vt__10Controller
__vt__10Controller:
	.incbin "baserom.dol", 0x225EB4, 0x34
.global lbl_80228EE8
lbl_80228EE8:
	.incbin "baserom.dol", 0x225EE8, 0x5C
.global __vt__13AtxFileStream
__vt__13AtxFileStream:
	.incbin "baserom.dol", 0x225F44, 0x80
.global __vt__9AtxStream
__vt__9AtxStream:
	.incbin "baserom.dol", 0x225FC4, 0x68
.global gxTexFmts
gxTexFmts:
	.incbin "baserom.dol", 0x22602C, 0x3C
.global __vt__7Texture
__vt__7Texture:
	.incbin "baserom.dol", 0x226068, 0x48
.global __vt__9GfxObject
__vt__9GfxObject:
	.incbin "baserom.dol", 0x2260B0, 0x10
.global bigFont_data
bigFont_data:
	.incbin "baserom.dol", 0x2260C0, 0x7C08C
.global lbl_802A514C
lbl_802A514C:
	.incbin "baserom.dol", 0x2A214C, 0xC
.global lbl_802A5158
lbl_802A5158:
	.incbin "baserom.dol", 0x2A2158, 0xC
.global lbl_802A5164
lbl_802A5164:
	.incbin "baserom.dol", 0x2A2164, 0x160
.global errorMessages
errorMessages:
	.incbin "baserom.dol", 0x2A22C4, 0x64
.global errorList
errorList:
	.incbin "baserom.dol", 0x2A2328, 0x8C
.global __vt__29Delegate1$$06System$$4R8Graphics$$1
__vt__29Delegate1$$06System$$4R8Graphics$$1:
	.incbin "baserom.dol", 0x2A23B4, 0xC
.global __vt__22IDelegate1$$0R8Graphics$$1
__vt__22IDelegate1$$0R8Graphics$$1:
	.incbin "baserom.dol", 0x2A23C0, 0x24
.global __vt__9LogStream
__vt__9LogStream:
	.incbin "baserom.dol", 0x2A23E4, 0x90
.global __vt__11AddressNode
__vt__11AddressNode:
	.incbin "baserom.dol", 0x2A2474, 0x30
.global __vt__8DirEntry
__vt__8DirEntry:
	.incbin "baserom.dol", 0x2A24A4, 0x6C
.global __vt__9DVDStream
__vt__9DVDStream:
	.incbin "baserom.dol", 0x2A2510, 0xE0
.global __vt__6System
__vt__6System:
	.incbin "baserom.dol", 0x2A25F0, 0x54
.global __vt__10AramStream
__vt__10AramStream:
	.incbin "baserom.dol", 0x2A2644, 0x88
.global padChannels
padChannels:
	.incbin "baserom.dol", 0x2A26CC, 0x10
.global __vt__13ControllerMgr
__vt__13ControllerMgr:
	.incbin "baserom.dol", 0x2A26DC, 0xC
.global lbl_802A56E8
lbl_802A56E8:
	.incbin "baserom.dol", 0x2A26E8, 0x1C
.global progressiveRenderMode
progressiveRenderMode:
	.incbin "baserom.dol", 0x2A2704, 0x3C
.global localNtsc480IntDf
localNtsc480IntDf:
	.incbin "baserom.dol", 0x2A2740, 0x3C
.global oldTexs
oldTexs:
	.incbin "baserom.dol", 0x2A277C, 0xA4
.global mtxTypes
mtxTypes:
	.incbin "baserom.dol", 0x2A2820, 0x150
.global genSrcs
genSrcs:
	.incbin "baserom.dol", 0x2A2970, 0x54
.global meshVCD
meshVCD:
	.incbin "baserom.dol", 0x2A29C4, 0xB8
.global meshVAT
meshVAT:
	.incbin "baserom.dol", 0x2A2A7C, 0xB0
.global lbl_802A5B2C
lbl_802A5B2C:
	.incbin "baserom.dol", 0x2A2B2C, 0x28
.global lbl_802A5B54
lbl_802A5B54:
	.incbin "baserom.dol", 0x2A2B54, 0x50
.global sAsciiTable
sAsciiTable:
	.incbin "baserom.dol", 0x2A2BA4, 0x80
.global sFontData
sFontData:
	.incbin "baserom.dol", 0x2A2C24, 0x154
.global __vt__5Shape
__vt__5Shape:
	.incbin "baserom.dol", 0x2A2D78, 0x3C
.global __vt__11DGXGraphics
__vt__11DGXGraphics:
	.incbin "baserom.dol", 0x2A2DB4, 0xFC
.global lbl_802A5EB0
lbl_802A5EB0:
	.incbin "baserom.dol", 0x2A2EB0, 0xA0
.global __vt__9RigidBody
__vt__9RigidBody:
	.incbin "baserom.dol", 0x2A2F50, 0x7C
.global lbl_802A5FCC
lbl_802A5FCC:
	.incbin "baserom.dol", 0x2A2FCC, 0xC
.global lbl_802A5FD8
lbl_802A5FD8:
	.incbin "baserom.dol", 0x2A2FD8, 0xC
.global lbl_802A5FE4
lbl_802A5FE4:
	.incbin "baserom.dol", 0x2A2FE4, 0x18
.global __vt__8Animator
__vt__8Animator:
	.incbin "baserom.dol", 0x2A2FFC, 0x38
.global __vt__7AnimMgr
__vt__7AnimMgr:
	.incbin "baserom.dol", 0x2A3034, 0x38
.global __vt__13Parm$$06String$$1
__vt__13Parm$$06String$$1:
	.incbin "baserom.dol", 0x2A306C, 0x2C
.global __vt__7Parm$$0f$$1
__vt__7Parm$$0f$$1:
	.incbin "baserom.dol", 0x2A3098, 0x2C
.global __vt__7Parm$$0i$$1
__vt__7Parm$$0i$$1:
	.incbin "baserom.dol", 0x2A30C4, 0x34
.global __vt__8AnimInfo
__vt__8AnimInfo:
	.incbin "baserom.dol", 0x2A30F8, 0x30
.global lbl_802A6128
lbl_802A6128:
	.incbin "baserom.dol", 0x2A3128, 0x10
.global lbl_802A6138
lbl_802A6138:
	.incbin "baserom.dol", 0x2A3138, 0xC
.global timopts
timopts:
	.incbin "baserom.dol", 0x2A3144, 0xC
.global lbl_802A6150
lbl_802A6150:
	.incbin "baserom.dol", 0x2A3150, 0x14
.global lbl_802A6164
lbl_802A6164:
	.incbin "baserom.dol", 0x2A3164, 0x10
.global lbl_802A6174
lbl_802A6174:
	.incbin "baserom.dol", 0x2A3174, 0x10
.global lbl_802A6184
lbl_802A6184:
	.incbin "baserom.dol", 0x2A3184, 0x14
.global lbl_802A6198
lbl_802A6198:
	.incbin "baserom.dol", 0x2A3198, 0x10
.global lbl_802A61A8
lbl_802A61A8:
	.incbin "baserom.dol", 0x2A31A8, 0x14
.global lbl_802A61BC
lbl_802A61BC:
	.incbin "baserom.dol", 0x2A31BC, 0x64
.global lbl_802A6220
lbl_802A6220:
	.incbin "baserom.dol", 0x2A3220, 0xC
.global lbl_802A622C
lbl_802A622C:
	.incbin "baserom.dol", 0x2A322C, 0x184
.global __vt__11GameGenNode
__vt__11GameGenNode:
	.incbin "baserom.dol", 0x2A33B0, 0x7C
.global __vt__7Section
__vt__7Section:
	.incbin "baserom.dol", 0x2A342C, 0x50
.global __vt__11GameGenFlow
__vt__11GameGenFlow:
	.incbin "baserom.dol", 0x2A347C, 0xFC
.global __vt__8GameFlow
__vt__8GameFlow:
	.incbin "baserom.dol", 0x2A3578, 0x6C
.global __vt__27Delegate1$$08GameFlow$$4R4Menu$$1
__vt__27Delegate1$$08GameFlow$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2A35E4, 0xC
.global __vt__18IDelegate1$$0R4Menu$$1
__vt__18IDelegate1$$0R4Menu$$1:
	.incbin "baserom.dol", 0x2A35F0, 0x58
.global __vt__13GameLoadIdler
__vt__13GameLoadIdler:
	.incbin "baserom.dol", 0x2A3648, 0x3C
.global __vt__9LoadIdler
__vt__9LoadIdler:
	.incbin "baserom.dol", 0x2A3684, 0x38
.global __vt__10MemoryCard
__vt__10MemoryCard:
	.incbin "baserom.dol", 0x2A36BC, 0x14
.global lbl_802A66D0
lbl_802A66D0:
	.incbin "baserom.dol", 0x2A36D0, 0x1C
.global lbl_802A66EC
lbl_802A66EC:
	.incbin "baserom.dol", 0x2A36EC, 0x68
.global levNames
levNames:
	.incbin "baserom.dol", 0x2A3754, 0x64
.global lbl_802A67B8
lbl_802A67B8:
	.incbin "baserom.dol", 0x2A37B8, 0xB0
.global __vt__16OnePlayerSection
__vt__16OnePlayerSection:
	.incbin "baserom.dol", 0x2A3868, 0x54
.global __vt__11GenFileInfo
__vt__11GenFileInfo:
	.incbin "baserom.dol", 0x2A38BC, 0x4C
.global __vt__9StageInfo
__vt__9StageInfo:
	.incbin "baserom.dol", 0x2A3908, 0x64
.global __vt__9PlayState
__vt__9PlayState:
	.incbin "baserom.dol", 0x2A396C, 0x28
.global __vt__9GamePrefs
__vt__9GamePrefs:
	.incbin "baserom.dol", 0x2A3994, 0x14
.global lbl_802A69A8
lbl_802A69A8:
	.incbin "baserom.dol", 0x2A39A8, 0x174
.global shapeList
shapeList:
	.incbin "baserom.dol", 0x2A3B1C, 0x458
.global shapeList2
shapeList2:
	.incbin "baserom.dol", 0x2A3F74, 0x408
.global arambundleList
arambundleList:
	.incbin "baserom.dol", 0x2A437C, 0x150
.global __vt__16GameSetupSection
__vt__16GameSetupSection:
	.incbin "baserom.dol", 0x2A44CC, 0x90
.global __vt__9RamStream
__vt__9RamStream:
	.incbin "baserom.dol", 0x2A455C, 0x104
.global lbl_802A7660
lbl_802A7660:
	.incbin "baserom.dol", 0x2A4660, 0xD0
.global __vt__22CardSelectSetupSection
__vt__22CardSelectSetupSection:
	.incbin "baserom.dol", 0x2A4730, 0x84
.global __vt__17CardSelectSection
__vt__17CardSelectSection:
	.incbin "baserom.dol", 0x2A47B4, 0x6C
.global lbl_802A7820
lbl_802A7820:
	.incbin "baserom.dol", 0x2A4820, 0x34
.global lbl_802A7854
lbl_802A7854:
	.incbin "baserom.dol", 0x2A4854, 0xC
.global lbl_802A7860
lbl_802A7860:
	.incbin "baserom.dol", 0x2A4860, 0xFC
.global __vt__21MapSelectSetupSection
__vt__21MapSelectSetupSection:
	.incbin "baserom.dol", 0x2A495C, 0x84
.global __vt__16MapSelectSection
__vt__16MapSelectSection:
	.incbin "baserom.dol", 0x2A49E0, 0xA0
.global __vt__23Delegate1$$04Menu$$4R4Menu$$1
__vt__23Delegate1$$04Menu$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2A4A80, 0x44
.global __vt__41Delegate1$$021MapSelectSetupSection$$4R4Menu$$1
__vt__41Delegate1$$021MapSelectSetupSection$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2A4AC4, 0x1C
.global lbl_802A7AE0
lbl_802A7AE0:
	.incbin "baserom.dol", 0x2A4AE0, 0x1C
.global lbl_802A7AFC
lbl_802A7AFC:
	.incbin "baserom.dol", 0x2A4AFC, 0x10
.global lbl_802A7B0C
lbl_802A7B0C:
	.incbin "baserom.dol", 0x2A4B0C, 0x9C
.global lbl_802A7BA8
lbl_802A7BA8:
	.incbin "baserom.dol", 0x2A4BA8, 0xC
.global lbl_802A7BB4
lbl_802A7BB4:
	.incbin "baserom.dol", 0x2A4BB4, 0x2C
.global __vt__13GameInterface
__vt__13GameInterface:
	.incbin "baserom.dol", 0x2A4BE0, 0x50
.global __vt__9GaugeInfo
__vt__9GaugeInfo:
	.incbin "baserom.dol", 0x2A4C30, 0x8C
.global __vt__23NewPikiGameSetupSection
__vt__23NewPikiGameSetupSection:
	.incbin "baserom.dol", 0x2A4CBC, 0x88
.global __vt__18NewPikiGameSection
__vt__18NewPikiGameSection:
	.incbin "baserom.dol", 0x2A4D44, 0x88
.global __vt__18GameMovieInterface
__vt__18GameMovieInterface:
	.incbin "baserom.dol", 0x2A4DCC, 0x4C
.global __vt__16DayOverModeState
__vt__16DayOverModeState:
	.incbin "baserom.dol", 0x2A4E18, 0x34
.global __vt__16MessageModeState
__vt__16MessageModeState:
	.incbin "baserom.dol", 0x2A4E4C, 0x34
.global __vt__16RunningModeState
__vt__16RunningModeState:
	.incbin "baserom.dol", 0x2A4E80, 0x38
.global __vt__21QuittingGameModeState
__vt__21QuittingGameModeState:
	.incbin "baserom.dol", 0x2A4EB8, 0x14
.global __vt__9ModeState
__vt__9ModeState:
	.incbin "baserom.dol", 0x2A4ECC, 0x34
.global __vt__18IntroGameModeState
__vt__18IntroGameModeState:
	.incbin "baserom.dol", 0x2A4F00, 0x14
.global __vt__15BaseGameSection
__vt__15BaseGameSection:
	.incbin "baserom.dol", 0x2A4F14, 0x70
.global lbl_802A7F84
lbl_802A7F84:
	.incbin "baserom.dol", 0x2A4F84, 0x70
.global __vt__14IntroModeState
__vt__14IntroModeState:
	.incbin "baserom.dol", 0x2A4FF4, 0x34
.global __vt__17QuittingModeState
__vt__17QuittingModeState:
	.incbin "baserom.dol", 0x2A5028, 0xA4
.global __vt__21IntroGameSetupSection
__vt__21IntroGameSetupSection:
	.incbin "baserom.dol", 0x2A50CC, 0x88
.global __vt__16IntroGameSection
__vt__16IntroGameSection:
	.incbin "baserom.dol", 0x2A5154, 0x104
.global __vt__15GameExitSection
__vt__15GameExitSection:
	.incbin "baserom.dol", 0x2A5258, 0x88
.global lbl_802A82E0
lbl_802A82E0:
	.incbin "baserom.dol", 0x2A52E0, 0x3C
.global lbl_802A831C
lbl_802A831C:
	.incbin "baserom.dol", 0x2A531C, 0xC
.global lbl_802A8328
lbl_802A8328:
	.incbin "baserom.dol", 0x2A5328, 0x14
.global lbl_802A833C
lbl_802A833C:
	.incbin "baserom.dol", 0x2A533C, 0xE8
.global __vt__12DynObjBridge
__vt__12DynObjBridge:
	.incbin "baserom.dol", 0x2A5424, 0xE0
.global __vt__18GenObjectMapObject
__vt__18GenObjectMapObject:
	.incbin "baserom.dol", 0x2A5504, 0x3C
.global lbl_802A8540
lbl_802A8540:
	.incbin "baserom.dol", 0x2A5540, 0xCC
.global __vt__4Menu
__vt__4Menu:
	.incbin "baserom.dol", 0x2A560C, 0x90
.global __vt__8BaseParm
__vt__8BaseParm:
	.incbin "baserom.dol", 0x2A569C, 0x14
.global lbl_802A86B0
lbl_802A86B0:
	.incbin "baserom.dol", 0x2A56B0, 0x8C
.global lbl_802A873C
lbl_802A873C:
	.incbin "baserom.dol", 0x2A573C, 0x50
.global __vt__16AtxCommandStream
__vt__16AtxCommandStream:
	.incbin "baserom.dol", 0x2A578C, 0xC4
.global __vt__7GameApp
__vt__7GameApp:
	.incbin "baserom.dol", 0x2A5850, 0x84
.global __vt__11PlugPikiApp
__vt__11PlugPikiApp:
	.incbin "baserom.dol", 0x2A58D4, 0x4C
.global lbl_802A8920
lbl_802A8920:
	.incbin "baserom.dol", 0x2A5920, 0x164
.global __vt__37Delegate1$$017TitleSetupSection$$4R4Menu$$1
__vt__37Delegate1$$017TitleSetupSection$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2A5A84, 0x84
.global __vt__17TitleSetupSection
__vt__17TitleSetupSection:
	.incbin "baserom.dol", 0x2A5B08, 0x80
.global __vt__13TitlesSection
__vt__13TitlesSection:
	.incbin "baserom.dol", 0x2A5B88, 0x58
.global __vt__20TitlesMovieInterface
__vt__20TitlesMovieInterface:
	.incbin "baserom.dol", 0x2A5BE0, 0x18
.global lbl_802A8BF8
lbl_802A8BF8:
	.incbin "baserom.dol", 0x2A5BF8, 0xB8
.global __vt__19NinLogoSetupSection
__vt__19NinLogoSetupSection:
	.incbin "baserom.dol", 0x2A5CB0, 0x80
.global __vt__14NinLogoSection
__vt__14NinLogoSection:
	.incbin "baserom.dol", 0x2A5D30, 0x38
.global lbl_802A8D68
lbl_802A8D68:
	.incbin "baserom.dol", 0x2A5D68, 0x11C
.global __vt__12ShadowCaster
__vt__12ShadowCaster:
	.incbin "baserom.dol", 0x2A5E84, 0x50
.global __vt__12DynSimulator
__vt__12DynSimulator:
	.incbin "baserom.dol", 0x2A5ED4, 0x60
.global __vt__17MapProjMatHandler
__vt__17MapProjMatHandler:
	.incbin "baserom.dol", 0x2A5F34, 0x30
.global __vt__17MapShadMatHandler
__vt__17MapShadMatHandler:
	.incbin "baserom.dol", 0x2A5F64, 0xA4
.global __vt__14DynObjPushable
__vt__14DynObjPushable:
	.incbin "baserom.dol", 0x2A6008, 0x78
.global __vt__10DynObjBody
__vt__10DynObjBody:
	.incbin "baserom.dol", 0x2A6080, 0xB4
.global __vt__12DynObjSeeSaw
__vt__12DynObjSeeSaw:
	.incbin "baserom.dol", 0x2A6134, 0x114
.global __vt__14DynCollObjBody
__vt__14DynCollObjBody:
	.incbin "baserom.dol", 0x2A6248, 0x84
.global __vt__12DynMapObject
__vt__12DynMapObject:
	.incbin "baserom.dol", 0x2A62CC, 0xA0
.global __vt__13MapObjectPart
__vt__13MapObjectPart:
	.incbin "baserom.dol", 0x2A636C, 0x48
.global __vt__13DynCollObject
__vt__13DynCollObject:
	.incbin "baserom.dol", 0x2A63B4, 0x68
.global __vt__14MapObjAnimator
__vt__14MapObjAnimator:
	.incbin "baserom.dol", 0x2A641C, 0x18
.global __vt__12DynCollShape
__vt__12DynCollShape:
	.incbin "baserom.dol", 0x2A6434, 0x4C
.global lbl_802A9480
lbl_802A9480:
	.incbin "baserom.dol", 0x2A6480, 0x84
.global lbl_802A9504
lbl_802A9504:
	.incbin "baserom.dol", 0x2A6504, 0x108
.global lightTypeNames
lightTypeNames:
	.incbin "baserom.dol", 0x2A660C, 0x10
.global lightConv
lightConv:
	.incbin "baserom.dol", 0x2A661C, 0x11C
.global lbl_802A9738
lbl_802A9738:
	.incbin "baserom.dol", 0x2A6738, 0x10
.global lbl_802A9748
lbl_802A9748:
	.incbin "baserom.dol", 0x2A6748, 0x130
.global settingnames$2810
settingnames$2810:
	.incbin "baserom.dol", 0x2A6878, 0x14
.global lightnames$2816
lightnames$2816:
	.incbin "baserom.dol", 0x2A688C, 0x7C
.global __vt__26Delegate1$$07FogMenu$$4R4Menu$$1
__vt__26Delegate1$$07FogMenu$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2A6908, 0x78
.global __vt__7FogMenu
__vt__7FogMenu:
	.incbin "baserom.dol", 0x2A6980, 0x84
.global __vt__9LightMenu
__vt__9LightMenu:
	.incbin "baserom.dol", 0x2A6A04, 0x84
.global __vt__10DaySetMenu
__vt__10DaySetMenu:
	.incbin "baserom.dol", 0x2A6A88, 0x7C
.global __vt__25Delegate1$$06DayMgr$$4R4Menu$$1
__vt__25Delegate1$$06DayMgr$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2A6B04, 0x38
.global __vt__32Delegate1$$012PositionMenu$$4R4Menu$$1
__vt__32Delegate1$$012PositionMenu$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2A6B3C, 0x40
.global __vt__12PositionMenu
__vt__12PositionMenu:
	.incbin "baserom.dol", 0x2A6B7C, 0x80
.global __vt__30Delegate1$$010ColourMenu$$4R4Menu$$1
__vt__30Delegate1$$010ColourMenu$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2A6BFC, 0x6C
.global __vt__10ColourMenu
__vt__10ColourMenu:
	.incbin "baserom.dol", 0x2A6C68, 0x80
.global __vt__28Delegate1$$09LightMenu$$4R4Menu$$1
__vt__28Delegate1$$09LightMenu$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2A6CE8, 0x18
.global lbl_802A9D00
lbl_802A9D00:
	.incbin "baserom.dol", 0x2A6D00, 0x1C
.global lbl_802A9D1C
lbl_802A9D1C:
	.incbin "baserom.dol", 0x2A6D1C, 0xC
.global lbl_802A9D28
lbl_802A9D28:
	.incbin "baserom.dol", 0x2A6D28, 0xC
.global lbl_802A9D34
lbl_802A9D34:
	.incbin "baserom.dol", 0x2A6D34, 0x18
.global onionColours$1858
onionColours$1858:
	.incbin "baserom.dol", 0x2A6D4C, 0x38
.global lbl_802A9D84
lbl_802A9D84:
	.incbin "baserom.dol", 0x2A6D84, 0x118
.global __vt__13ActorInstance
__vt__13ActorInstance:
	.incbin "baserom.dol", 0x2A6E9C, 0x30
.global __vt__8SceneCut
__vt__8SceneCut:
	.incbin "baserom.dol", 0x2A6ECC, 0x34
.global __vt__15CineShapeObject
__vt__15CineShapeObject:
	.incbin "baserom.dol", 0x2A6F00, 0x30
.global __vt__9SceneData
__vt__9SceneData:
	.incbin "baserom.dol", 0x2A6F30, 0x94
.global __vt__9LightPool
__vt__9LightPool:
	.incbin "baserom.dol", 0x2A6FC4, 0x5C
.global lbl_802AA020
lbl_802AA020:
	.incbin "baserom.dol", 0x2A7020, 0x1C
.global basecardname
basecardname:
	.incbin "baserom.dol", 0x2A703C, 0x24
.global p_icon_palette
p_icon_palette:
	.incbin "baserom.dol", 0x2A7060, 0x200
.global p_icon_data
p_icon_data:
	.incbin "baserom.dol", 0x2A7260, 0x400
.global o_icon_palette
o_icon_palette:
	.incbin "baserom.dol", 0x2A7660, 0x200
.global o_icon_data
o_icon_data:
	.incbin "baserom.dol", 0x2A7860, 0x400
.global p_card_v_palette
p_card_v_palette:
	.incbin "baserom.dol", 0x2A7C60, 0x200
.global p_card_v_data
p_card_v_data:
	.incbin "baserom.dol", 0x2A7E60, 0xC00
.global icon_datas
icon_datas:
	.incbin "baserom.dol", 0x2A8A60, 0xC0
.global errCodes
errCodes:
	.incbin "baserom.dol", 0x2A8B20, 0x24
.global lbl_802ABB44
lbl_802ABB44:
	.incbin "baserom.dol", 0x2A8B44, 0x68
.global sectionNames$2018
sectionNames$2018:
	.incbin "baserom.dol", 0x2A8BAC, 0x15C
.global lbl_802ABD08
lbl_802ABD08:
	.incbin "baserom.dol", 0x2A8D08, 0x6D4
.global movieTitles
movieTitles:
	.incbin "baserom.dol", 0x2A93DC, 0x2DC
.global movie04table
movie04table:
	.incbin "baserom.dol", 0x2A96B8, 0x14
.global movie09table
movie09table:
	.incbin "baserom.dol", 0x2A96CC, 0x14
.global movie17table
movie17table:
	.incbin "baserom.dol", 0x2A96E0, 0x14
.global movie20table
movie20table:
	.incbin "baserom.dol", 0x2A96F4, 0x14
.global movie18table
movie18table:
	.incbin "baserom.dol", 0x2A9708, 0x14
.global movie28table
movie28table:
	.incbin "baserom.dol", 0x2A971C, 0x14
.global movie32table
movie32table:
	.incbin "baserom.dol", 0x2A9730, 0x14
.global movie40table
movie40table:
	.incbin "baserom.dol", 0x2A9744, 0x14
.global movie44table
movie44table:
	.incbin "baserom.dol", 0x2A9758, 0x14
.global movie47table
movie47table:
	.incbin "baserom.dol", 0x2A976C, 0x14
.global movie52table
movie52table:
	.incbin "baserom.dol", 0x2A9780, 0x14
.global movie56table
movie56table:
	.incbin "baserom.dol", 0x2A9794, 0x14
.global movie60table
movie60table:
	.incbin "baserom.dol", 0x2A97A8, 0x14
.global movie64table
movie64table:
	.incbin "baserom.dol", 0x2A97BC, 0x14
.global movie69table
movie69table:
	.incbin "baserom.dol", 0x2A97D0, 0x14
.global transTable
transTable:
	.incbin "baserom.dol", 0x2A97E4, 0xC8
.global __vt__9MovieInfo
__vt__9MovieInfo:
	.incbin "baserom.dol", 0x2A98AC, 0x2C
.global lbl_802AC8D8
lbl_802AC8D8:
	.incbin "baserom.dol", 0x2A98D8, 0xAC
.global movieNames$localstatic0$__ct__21MovSampleSetupSectionFv
movieNames$localstatic0$__ct__21MovSampleSetupSectionFv:
	.incbin "baserom.dol", 0x2A9984, 0xCC
.global __vt__21MovSampleSetupSection
__vt__21MovSampleSetupSection:
	.incbin "baserom.dol", 0x2A9A50, 0x84
.global __vt__16MovSampleSection
__vt__16MovSampleSection:
	.incbin "baserom.dol", 0x2A9AD4, 0x80
.global __vt__10ClothFader
__vt__10ClothFader:
	.incbin "baserom.dol", 0x2A9B54, 0x38
.global __vt__11SimpleFader
__vt__11SimpleFader:
	.incbin "baserom.dol", 0x2A9B8C, 0x3C
.global __vt__12DefaultFader
__vt__12DefaultFader:
	.incbin "baserom.dol", 0x2A9BC8, 0x20
.global __vt__Q215AttentionCamera5Fader
__vt__Q215AttentionCamera5Fader:
	.incbin "baserom.dol", 0x2A9BE8, 0x3C
.global lbl_802ACC24
lbl_802ACC24:
	.incbin "baserom.dol", 0x2A9C24, 0x44
.global __vt__Q29RadarInfo9PartsInfo
__vt__Q29RadarInfo9PartsInfo:
	.incbin "baserom.dol", 0x2A9C68, 0x7C
.global __vt__13InteractFlute
__vt__13InteractFlute:
	.incbin "baserom.dol", 0x2A9CE4, 0x48
.global __vt__13InteractPress
__vt__13InteractPress:
	.incbin "baserom.dol", 0x2A9D2C, 0x48
.global __vt__12InteractKill
__vt__12InteractKill:
	.incbin "baserom.dol", 0x2A9D74, 0x48
.global __vt__15InteractSwallow
__vt__15InteractSwallow:
	.incbin "baserom.dol", 0x2A9DBC, 0x48
.global __vt__14InteractAttack
__vt__14InteractAttack:
	.incbin "baserom.dol", 0x2A9E04, 0x4C
.global __vt__19InteractSlimeAttack
__vt__19InteractSlimeAttack:
	.incbin "baserom.dol", 0x2A9E50, 0x48
.global __vt__13InteractFlick
__vt__13InteractFlick:
	.incbin "baserom.dol", 0x2A9E98, 0x48
.global __vt__12InteractWind
__vt__12InteractWind:
	.incbin "baserom.dol", 0x2A9EE0, 0x48
.global __vt__12InteractFire
__vt__12InteractFire:
	.incbin "baserom.dol", 0x2A9F28, 0x48
.global __vt__14InteractBubble
__vt__14InteractBubble:
	.incbin "baserom.dol", 0x2A9F70, 0x2C
.global __vt__11Interaction
__vt__11Interaction:
	.incbin "baserom.dol", 0x2A9F9C, 0x48
.global __vt__13InteractSpore
__vt__13InteractSpore:
	.incbin "baserom.dol", 0x2A9FE4, 0x4C
.global __vt__19InteractChangeHappa
__vt__19InteractChangeHappa:
	.incbin "baserom.dol", 0x2AA030, 0x4C
.global __vt__19InteractChangeColor
__vt__19InteractChangeColor:
	.incbin "baserom.dol", 0x2AA07C, 0x4C
.global __vt__17InteractThrowAway
__vt__17InteractThrowAway:
	.incbin "baserom.dol", 0x2AA0C8, 0x48
.global __vt__12InteractBury
__vt__12InteractBury:
	.incbin "baserom.dol", 0x2AA110, 0x7C
.global __vt__15InteractRelease
__vt__15InteractRelease:
	.incbin "baserom.dol", 0x2AA18C, 0x48
.global __vt__12InteractGrab
__vt__12InteractGrab:
	.incbin "baserom.dol", 0x2AA1D4, 0x70
.global __vt__12InteractWarn
__vt__12InteractWarn:
	.incbin "baserom.dol", 0x2AA244, 0x48
.global __vt__12InteractTalk
__vt__12InteractTalk:
	.incbin "baserom.dol", 0x2AA28C, 0x78
.global __vt__15InteractPullout
__vt__15InteractPullout:
	.incbin "baserom.dol", 0x2AA304, 0x9C
.global __vt__12SAIUserEvent
__vt__12SAIUserEvent:
	.incbin "baserom.dol", 0x2AA3A0, 0x5C
.global __vt__14SAIGroundEvent
__vt__14SAIGroundEvent:
	.incbin "baserom.dol", 0x2AA3FC, 0x5C
.global __vt__15SAICollideEvent
__vt__15SAICollideEvent:
	.incbin "baserom.dol", 0x2AA458, 0x5C
.global __vt__14SAIBounceEvent
__vt__14SAIBounceEvent:
	.incbin "baserom.dol", 0x2AA4B4, 0x64
.global __vt__21SAIMotionLoopEndEvent
__vt__21SAIMotionLoopEndEvent:
	.incbin "baserom.dol", 0x2AA518, 0x64
.global __vt__23SAIMotionLoopStartEvent
__vt__23SAIMotionLoopStartEvent:
	.incbin "baserom.dol", 0x2AA57C, 0x64
.global __vt__21SAIMotionAction0Event
__vt__21SAIMotionAction0Event:
	.incbin "baserom.dol", 0x2AA5E0, 0x60
.global __vt__18SAIMotionDoneEvent
__vt__18SAIMotionDoneEvent:
	.incbin "baserom.dol", 0x2AA640, 0x38
.global __vt__8SAIEvent
__vt__8SAIEvent:
	.incbin "baserom.dol", 0x2AA678, 0x38
.global __vt__22Receiver$$010AICreature$$1
__vt__22Receiver$$010AICreature$$1:
	.incbin "baserom.dol", 0x2AA6B0, 0x38
.global lbl_802AD6E8
lbl_802AD6E8:
	.incbin "baserom.dol", 0x2AA6E8, 0x30
.global lbl_802AD718
lbl_802AD718:
	.incbin "baserom.dol", 0x2AA718, 0x1C
.global lbl_802AD734
lbl_802AD734:
	.incbin "baserom.dol", 0x2AA734, 0xC
.global lbl_802AD740
lbl_802AD740:
	.incbin "baserom.dol", 0x2AA740, 0xBC
.global __vt__8SAIState
__vt__8SAIState:
	.incbin "baserom.dol", 0x2AA7FC, 0x50
.global __vt__20AState$$010AICreature$$1
__vt__20AState$$010AICreature$$1:
	.incbin "baserom.dol", 0x2AA84C, 0xB8
.global __vt__12SAICondition
__vt__12SAICondition:
	.incbin "baserom.dol", 0x2AA904, 0x28
.global __vt__8SAIArrow
__vt__8SAIArrow:
	.incbin "baserom.dol", 0x2AA92C, 0x60
.global __vt__8SimpleAI
__vt__8SimpleAI:
	.incbin "baserom.dol", 0x2AA98C, 0x18
.global __vt__26StateMachine$$010AICreature$$1
__vt__26StateMachine$$010AICreature$$1:
	.incbin "baserom.dol", 0x2AA9A4, 0x98
.global __vt__10AICreature
__vt__10AICreature:
	.incbin "baserom.dol", 0x2AAA3C, 0x158
.global __vt__19PaniAnimKeyListener
__vt__19PaniAnimKeyListener:
	.incbin "baserom.dol", 0x2AAB94, 0x58
.global __vt__12WingArranger
__vt__12WingArranger:
	.incbin "baserom.dol", 0x2AABEC, 0x2C
.global __vt__12LineArranger
__vt__12LineArranger:
	.incbin "baserom.dol", 0x2AAC18, 0x2C
.global __vt__15PyramidArranger
__vt__15PyramidArranger:
	.incbin "baserom.dol", 0x2AAC44, 0x2C
.global __vt__14CircleArranger
__vt__14CircleArranger:
	.incbin "baserom.dol", 0x2AAC70, 0x1C
.global __vt__11Traversable
__vt__11Traversable:
	.incbin "baserom.dol", 0x2AAC8C, 0x34
.global __vt__12FormationMgr
__vt__12FormationMgr:
	.incbin "baserom.dol", 0x2AACC0, 0x18
.global lbl_802ADCD8
lbl_802ADCD8:
	.incbin "baserom.dol", 0x2AACD8, 0xBC
.global partsInfo
partsInfo:
	.incbin "baserom.dol", 0x2AAD94, 0x74
.global __vt__Q211PlayerState8UfoParts
__vt__Q211PlayerState8UfoParts:
	.incbin "baserom.dol", 0x2AAE08, 0x18
.global lbl_802ADE20
lbl_802ADE20:
	.incbin "baserom.dol", 0x2AAE20, 0x330
.global __vt__9DemoParms
__vt__9DemoParms:
	.incbin "baserom.dol", 0x2AB150, 0x50
.global lbl_802AE1A0
lbl_802AE1A0:
	.incbin "baserom.dol", 0x2AB1A0, 0x1C
.global lbl_802AE1BC
lbl_802AE1BC:
	.incbin "baserom.dol", 0x2AB1BC, 0x24
.global lbl_802AE1E0
lbl_802AE1E0:
	.incbin "baserom.dol", 0x2AB1E0, 0x1C
.global flagTable__11ResultFlags
flagTable__11ResultFlags:
	.incbin "baserom.dol", 0x2AB1FC, 0x4D4
.global lbl_802AE6D0
lbl_802AE6D0:
	.incbin "baserom.dol", 0x2AB6D0, 0xC4
.global __vt__10AIConstant
__vt__10AIConstant:
	.incbin "baserom.dol", 0x2AB794, 0x4C
.global lbl_802AE7E0
lbl_802AE7E0:
	.incbin "baserom.dol", 0x2AB7E0, 0x9C
.global __vt__Q29KeyConfig3Key
__vt__Q29KeyConfig3Key:
	.incbin "baserom.dol", 0x2AB87C, 0x58
.global __vt__9KeyConfig
__vt__9KeyConfig:
	.incbin "baserom.dol", 0x2AB8D4, 0x4C
.global lbl_802AE920
lbl_802AE920:
	.incbin "baserom.dol", 0x2AB920, 0x30
.global gridStrings
gridStrings:
	.incbin "baserom.dol", 0x2AB950, 0xFC
.global lbl_802AEA4C
lbl_802AEA4C:
	.incbin "baserom.dol", 0x2ABA4C, 0x24
.global lbl_802AEA70
lbl_802AEA70:
	.incbin "baserom.dol", 0x2ABA70, 0x14
.global lbl_802AEA84
lbl_802AEA84:
	.incbin "baserom.dol", 0x2ABA84, 0x14
.global lbl_802AEA98
lbl_802AEA98:
	.incbin "baserom.dol", 0x2ABA98, 0x10
.global lbl_802AEAA8
lbl_802AEAA8:
	.incbin "baserom.dol", 0x2ABAA8, 0x10
.global lbl_802AEAB8
lbl_802AEAB8:
	.incbin "baserom.dol", 0x2ABAB8, 0x14
.global lbl_802AEACC
lbl_802AEACC:
	.incbin "baserom.dol", 0x2ABACC, 0x28
.global lbl_802AEAF4
lbl_802AEAF4:
	.incbin "baserom.dol", 0x2ABAF4, 0x14
.global lbl_802AEB08
lbl_802AEB08:
	.incbin "baserom.dol", 0x2ABB08, 0x14
.global lbl_802AEB1C
lbl_802AEB1C:
	.incbin "baserom.dol", 0x2ABB1C, 0x10
.global lbl_802AEB2C
lbl_802AEB2C:
	.incbin "baserom.dol", 0x2ABB2C, 0xC
.global lbl_802AEB38
lbl_802AEB38:
	.incbin "baserom.dol", 0x2ABB38, 0xC
.global lbl_802AEB44
lbl_802AEB44:
	.incbin "baserom.dol", 0x2ABB44, 0xC
.global lbl_802AEB50
lbl_802AEB50:
	.incbin "baserom.dol", 0x2ABB50, 0xC
.global lbl_802AEB5C
lbl_802AEB5C:
	.incbin "baserom.dol", 0x2ABB5C, 0xC
.global lbl_802AEB68
lbl_802AEB68:
	.incbin "baserom.dol", 0x2ABB68, 0xC
.global lbl_802AEB74
lbl_802AEB74:
	.incbin "baserom.dol", 0x2ABB74, 0xC
.global lbl_802AEB80
lbl_802AEB80:
	.incbin "baserom.dol", 0x2ABB80, 0xC
.global lbl_802AEB8C
lbl_802AEB8C:
	.incbin "baserom.dol", 0x2ABB8C, 0x5C
.global lbl_802AEBE8
lbl_802AEBE8:
	.incbin "baserom.dol", 0x2ABBE8, 0x34
.global lbl_802AEC1C
lbl_802AEC1C:
	.incbin "baserom.dol", 0x2ABC1C, 0xAC
.global ufoParts
ufoParts:
	.incbin "baserom.dol", 0x2ABCC8, 0x78
.global lbl_802AED40
lbl_802AED40:
	.incbin "baserom.dol", 0x2ABD40, 0xAC
.global __vt__25Delegate1$$06AIPerf$$4R4Menu$$1
__vt__25Delegate1$$06AIPerf$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2ABDEC, 0x68
.global lbl_802AEE54
lbl_802AEE54:
	.incbin "baserom.dol", 0x2ABE54, 0xC
.global lbl_802AEE60
lbl_802AEE60:
	.incbin "baserom.dol", 0x2ABE60, 0x74
.global __vt__14GenObjectDebug
__vt__14GenObjectDebug:
	.incbin "baserom.dol", 0x2ABED4, 0x80
.global lbl_802AEF54
lbl_802AEF54:
	.incbin "baserom.dol", 0x2ABF54, 0x60
.global __vt__7MemInfo
__vt__7MemInfo:
	.incbin "baserom.dol", 0x2ABFB4, 0x10
.global __vt__11MemInfoNode
__vt__11MemInfoNode:
	.incbin "baserom.dol", 0x2ABFC4, 0x90
.global _typeStr
_typeStr:
	.incbin "baserom.dol", 0x2AC054, 0x44
.global __vt__9Condition
__vt__9Condition:
	.incbin "baserom.dol", 0x2AC098, 0x3C
.global __vt__8Creature
__vt__8Creature:
	.incbin "baserom.dol", 0x2AC0D4, 0x20C
.global __vt__16CreatureCollPart
__vt__16CreatureCollPart:
	.incbin "baserom.dol", 0x2AC2E0, 0x78
.global _standType
_standType:
	.incbin "baserom.dol", 0x2AC358, 0x10
.global lbl_802AF368
lbl_802AF368:
	.incbin "baserom.dol", 0x2AC368, 0x34
.global __vt__8Stickers
__vt__8Stickers:
	.incbin "baserom.dol", 0x2AC39C, 0x150
.global __vt__11PelCreature
__vt__11PelCreature:
	.incbin "baserom.dol", 0x2AC4EC, 0x120
.global __vt__12DualCreature
__vt__12DualCreature:
	.incbin "baserom.dol", 0x2AC60C, 0x134
.global lbl_802AF740
lbl_802AF740:
	.incbin "baserom.dol", 0x2AC740, 0xC
.global lbl_802AF74C
lbl_802AF74C:
	.incbin "baserom.dol", 0x2AC74C, 0xC
.global lbl_802AF758
lbl_802AF758:
	.incbin "baserom.dol", 0x2AC758, 0x10
.global lbl_802AF768
lbl_802AF768:
	.incbin "baserom.dol", 0x2AC768, 0x74
.global __vt__11DynCreature
__vt__11DynCreature:
	.incbin "baserom.dol", 0x2AC7DC, 0x15C
.global __vt__12CreatureProp
__vt__12CreatureProp:
	.incbin "baserom.dol", 0x2AC938, 0x38
.global __vt__11DynParticle
__vt__11DynParticle:
	.incbin "baserom.dol", 0x2AC970, 0x64
.global lbl_802AF9D4
lbl_802AF9D4:
	.incbin "baserom.dol", 0x2AC9D4, 0xC
.global lbl_802AF9E0
lbl_802AF9E0:
	.incbin "baserom.dol", 0x2AC9E0, 0x40
.global __vt__13EventListener
__vt__13EventListener:
	.incbin "baserom.dol", 0x2ACA20, 0xBC
.global __vt__12RopeCreature
__vt__12RopeCreature:
	.incbin "baserom.dol", 0x2ACADC, 0x114
.global lbl_802AFBF0
lbl_802AFBF0:
	.incbin "baserom.dol", 0x2ACBF0, 0x15C
.global _info
_info:
	.incbin "baserom.dol", 0x2ACD4C, 0x1CC
.global lbl_802AFF18
lbl_802AFF18:
	.incbin "baserom.dol", 0x2ACF18, 0x10
.global _ufoIDTable
_ufoIDTable:
	.incbin "baserom.dol", 0x2ACF28, 0x7C
.global lbl_802AFFA4
lbl_802AFFA4:
	.incbin "baserom.dol", 0x2ACFA4, 0xC
.global lbl_802AFFB0
lbl_802AFFB0:
	.incbin "baserom.dol", 0x2ACFB0, 0x10
.global bounceSounds
bounceSounds:
	.incbin "baserom.dol", 0x2ACFC0, 0x30
.global numberPellets
numberPellets:
	.incbin "baserom.dol", 0x2ACFF0, 0x9C
.global lbl_802B008C
lbl_802B008C:
	.incbin "baserom.dol", 0x2AD08C, 0xC
.global lbl_802B0098
lbl_802B0098:
	.incbin "baserom.dol", 0x2AD098, 0xC
.global lbl_802B00A4
lbl_802B00A4:
	.incbin "baserom.dol", 0x2AD0A4, 0xE4
.global __vt__9PelletMgr
__vt__9PelletMgr:
	.incbin "baserom.dol", 0x2AD188, 0xB0
.global __vt__10PelletProp
__vt__10PelletProp:
	.incbin "baserom.dol", 0x2AD238, 0x40
.global __vt__Q29PelletMgr7UseNode
__vt__Q29PelletMgr7UseNode:
	.incbin "baserom.dol", 0x2AD278, 0x128
.global __vt__6Pellet
__vt__6Pellet:
	.incbin "baserom.dol", 0x2AD3A0, 0x148
.global __vt__21StateMachine$$06Pellet$$1
__vt__21StateMachine$$06Pellet$$1:
	.incbin "baserom.dol", 0x2AD4E8, 0xC4
.global __vt__7KEffect
__vt__7KEffect:
	.incbin "baserom.dol", 0x2AD5AC, 0x3C
.global __vt__Q23zen31CallBack1$$0PQ23zen11particleMdl$$1
__vt__Q23zen31CallBack1$$0PQ23zen11particleMdl$$1:
	.incbin "baserom.dol", 0x2AD5E8, 0xC
.global __vt__Q23zen58CallBack2$$0PQ23zen17particleGenerator$$4PQ23zen11particleMdl$$1
__vt__Q23zen58CallBack2$$0PQ23zen17particleGenerator$$4PQ23zen11particleMdl$$1:
	.incbin "baserom.dol", 0x2AD5F4, 0xC
.global __vt__Q23zen37CallBack1$$0PQ23zen17particleGenerator$$1
__vt__Q23zen37CallBack1$$0PQ23zen17particleGenerator$$1:
	.incbin "baserom.dol", 0x2AD600, 0x50
.global __vt__12PelletConfig
__vt__12PelletConfig:
	.incbin "baserom.dol", 0x2AD650, 0xCC
.global lbl_802B071C
lbl_802B071C:
	.incbin "baserom.dol", 0x2AD71C, 0x48
.global lbl_802B0764
lbl_802B0764:
	.incbin "baserom.dol", 0x2AD764, 0xC
.global lbl_802B0770
lbl_802B0770:
	.incbin "baserom.dol", 0x2AD770, 0x10
.global lbl_802B0780
lbl_802B0780:
	.incbin "baserom.dol", 0x2AD780, 0x14
.global lbl_802B0794
lbl_802B0794:
	.incbin "baserom.dol", 0x2AD794, 0x10
.global motionLabels__18PaniPelletAnimator
motionLabels__18PaniPelletAnimator:
	.incbin "baserom.dol", 0x2AD7A4, 0x6C
.global __vt__18PaniPelletAnimator
__vt__18PaniPelletAnimator:
	.incbin "baserom.dol", 0x2AD810, 0x60
.global __vt__14PelletAnimInfo
__vt__14PelletAnimInfo:
	.incbin "baserom.dol", 0x2AD870, 0x94
.global lbl_802B0904
lbl_802B0904:
	.incbin "baserom.dol", 0x2AD904, 0xC
.global lbl_802B0910
lbl_802B0910:
	.incbin "baserom.dol", 0x2AD910, 0x74
.global __vt__15GenObjectPellet
__vt__15GenObjectPellet:
	.incbin "baserom.dol", 0x2AD984, 0x58
.global lbl_802B09DC
lbl_802B09DC:
	.incbin "baserom.dol", 0x2AD9DC, 0x88
.global __vt__15PelletGoalState
__vt__15PelletGoalState:
	.incbin "baserom.dol", 0x2ADA64, 0x80
.global __vt__17PelletAppearState
__vt__17PelletAppearState:
	.incbin "baserom.dol", 0x2ADAE4, 0x84
.global __vt__20PelletSwallowedState
__vt__20PelletSwallowedState:
	.incbin "baserom.dol", 0x2ADB68, 0x80
.global __vt__17PelletNormalState
__vt__17PelletNormalState:
	.incbin "baserom.dol", 0x2ADBE8, 0x7C
.global __vt__15PelletDeadState
__vt__15PelletDeadState:
	.incbin "baserom.dol", 0x2ADC64, 0x80
.global __vt__18PelletUfoLoadState
__vt__18PelletUfoLoadState:
	.incbin "baserom.dol", 0x2ADCE4, 0x50
.global __vt__11PelletState
__vt__11PelletState:
	.incbin "baserom.dol", 0x2ADD34, 0x50
.global __vt__15AState$$06Pellet$$1
__vt__15AState$$06Pellet$$1:
	.incbin "baserom.dol", 0x2ADD84, 0x50
.global __vt__17Receiver$$06Pellet$$1
__vt__17Receiver$$06Pellet$$1:
	.incbin "baserom.dol", 0x2ADDD4, 0x70
.global __vt__18PelletStateMachine
__vt__18PelletStateMachine:
	.incbin "baserom.dol", 0x2ADE44, 0x44
.global lbl_802B0E88
lbl_802B0E88:
	.incbin "baserom.dol", 0x2ADE88, 0x1C
.global bridgeFirstPos
bridgeFirstPos:
	.incbin "baserom.dol", 0x2ADEA4, 0x14
.global bridgeFirstY
bridgeFirstY:
	.incbin "baserom.dol", 0x2ADEB8, 0x14
.global bridgeGrad
bridgeGrad:
	.incbin "baserom.dol", 0x2ADECC, 0x2C
.global info
info:
	.incbin "baserom.dol", 0x2ADEF8, 0x58
.global shpInfo
shpInfo:
	.incbin "baserom.dol", 0x2ADF50, 0xC0
.global files
files:
	.incbin "baserom.dol", 0x2AE010, 0x14
.global lbl_802B1024
lbl_802B1024:
	.incbin "baserom.dol", 0x2AE024, 0xC
.global lbl_802B1030
lbl_802B1030:
	.incbin "baserom.dol", 0x2AE030, 0xC
.global lbl_802B103C
lbl_802B103C:
	.incbin "baserom.dol", 0x2AE03C, 0x14
.global lbl_802B1050
lbl_802B1050:
	.incbin "baserom.dol", 0x2AE050, 0x40
.global __vt__13InteractBreak
__vt__13InteractBreak:
	.incbin "baserom.dol", 0x2AE090, 0x48
.global __vt__13InteractBuild
__vt__13InteractBuild:
	.incbin "baserom.dol", 0x2AE0D8, 0x164
.global __vt__6Bridge
__vt__6Bridge:
	.incbin "baserom.dol", 0x2AE23C, 0x188
.global __vt__12InteractPush
__vt__12InteractPush:
	.incbin "baserom.dol", 0x2AE3C4, 0x74
.global __vt__10HinderRock
__vt__10HinderRock:
	.incbin "baserom.dol", 0x2AE438, 0x268
.global __vt__13DynBuildShape
__vt__13DynBuildShape:
	.incbin "baserom.dol", 0x2AE6A0, 0xB0
.global __vt__19GenObjectWorkObject
__vt__19GenObjectWorkObject:
	.incbin "baserom.dol", 0x2AE750, 0x114
.global __vt__13WorkObjectMgr
__vt__13WorkObjectMgr:
	.incbin "baserom.dol", 0x2AE864, 0x9C
.global __vt__14WorkObjectNode
__vt__14WorkObjectNode:
	.incbin "baserom.dol", 0x2AE900, 0x44
.global __vt__10WorkObject
__vt__10WorkObject:
	.incbin "baserom.dol", 0x2AE944, 0x1F8
.global __vt__8RouteMgr
__vt__8RouteMgr:
	.incbin "baserom.dol", 0x2AEB3C, 0x34
.global lbl_802B1B70
lbl_802B1B70:
	.incbin "baserom.dol", 0x2AEB70, 0x88
.global lbl_802B1BF8
lbl_802B1BF8:
	.incbin "baserom.dol", 0x2AEBF8, 0x54
.global __vt__5SeWin
__vt__5SeWin:
	.incbin "baserom.dol", 0x2AEC4C, 0x78
.global __vt__5SeMgr
__vt__5SeMgr:
	.incbin "baserom.dol", 0x2AECC4, 0x68
.global lbl_802B1D2C
lbl_802B1D2C:
	.incbin "baserom.dol", 0x2AED2C, 0x98
.global __vt__10SeConstant
__vt__10SeConstant:
	.incbin "baserom.dol", 0x2AEDC4, 0x4C
.global lbl_802B1E10
lbl_802B1E10:
	.incbin "baserom.dol", 0x2AEE10, 0x15C4
.global soundTable
soundTable:
	.incbin "baserom.dol", 0x2B03D4, 0x19DC
.global lbl_802B4DB0
lbl_802B4DB0:
	.incbin "baserom.dol", 0x2B1DB0, 0x8C
.global lbl_802B4E3C
lbl_802B4E3C:
	.incbin "baserom.dol", 0x2B1E3C, 0x68
.global __vt__6CPlate
__vt__6CPlate:
	.incbin "baserom.dol", 0x2B1EA4, 0x10C
.global __vt__8ActStone
__vt__8ActStone:
	.incbin "baserom.dol", 0x2B1FB0, 0x94
.global lbl_802B5044
lbl_802B5044:
	.incbin "baserom.dol", 0x2B2044, 0x84
.global __vt__9ActAdjust
__vt__9ActAdjust:
	.incbin "baserom.dol", 0x2B20C8, 0x9C
.global __vt__Q29ActAdjust11Initialiser
__vt__Q29ActAdjust11Initialiser:
	.incbin "baserom.dol", 0x2B2164, 0x20
.global __vt__6ActPut
__vt__6ActPut:
	.incbin "baserom.dol", 0x2B2184, 0x84
.global __vt__Q26ActPut11Initialiser
__vt__Q26ActPut11Initialiser:
	.incbin "baserom.dol", 0x2B2208, 0x74
.global __vt__7ActPick
__vt__7ActPick:
	.incbin "baserom.dol", 0x2B227C, 0x98
.global __vt__Q27ActPick11Initialiser
__vt__Q27ActPick11Initialiser:
	.incbin "baserom.dol", 0x2B2314, 0x60
.global lbl_802B5374
lbl_802B5374:
	.incbin "baserom.dol", 0x2B2374, 0xB0
.global __vt__13ActJumpAttack
__vt__13ActJumpAttack:
	.incbin "baserom.dol", 0x2B2424, 0xC4
.global __vt__9ActAttack
__vt__9ActAttack:
	.incbin "baserom.dol", 0x2B24E8, 0xBC
.global lbl_802B55A4
lbl_802B55A4:
	.incbin "baserom.dol", 0x2B25A4, 0x64
.global __vt__11ActBoreRest
__vt__11ActBoreRest:
	.incbin "baserom.dol", 0x2B2608, 0xA0
.global __vt__14ActBoreOneshot
__vt__14ActBoreOneshot:
	.incbin "baserom.dol", 0x2B26A8, 0x98
.global __vt__13ActBoreListen
__vt__13ActBoreListen:
	.incbin "baserom.dol", 0x2B2740, 0xC4
.global __vt__11ActBoreTalk
__vt__11ActBoreTalk:
	.incbin "baserom.dol", 0x2B2804, 0xA4
.global __vt__13ActBoreSelect
__vt__13ActBoreSelect:
	.incbin "baserom.dol", 0x2B28A8, 0x88
.global __vt__13ActFreeSelect
__vt__13ActFreeSelect:
	.incbin "baserom.dol", 0x2B2930, 0x120
.global __vt__9ActBoMake
__vt__9ActBoMake:
	.incbin "baserom.dol", 0x2B2A50, 0xFC
.global __vt__6ActBou
__vt__6ActBou:
	.incbin "baserom.dol", 0x2B2B4C, 0x14C
.global __vt__9ActBridge
__vt__9ActBridge:
	.incbin "baserom.dol", 0x2B2C98, 0xCC
.global lbl_802B5D64
lbl_802B5D64:
	.incbin "baserom.dol", 0x2B2D64, 0xA0
.global __vt__12ActBreakWall
__vt__12ActBreakWall:
	.incbin "baserom.dol", 0x2B2E04, 0xAC
.global lbl_802B5EB0
lbl_802B5EB0:
	.incbin "baserom.dol", 0x2B2EB0, 0x10
.global lbl_802B5EC0
lbl_802B5EC0:
	.incbin "baserom.dol", 0x2B2EC0, 0xC
.global lbl_802B5ECC
lbl_802B5ECC:
	.incbin "baserom.dol", 0x2B2ECC, 0x10
.global lbl_802B5EDC
lbl_802B5EDC:
	.incbin "baserom.dol", 0x2B2EDC, 0xA8
.global __vt__12ActTransport
__vt__12ActTransport:
	.incbin "baserom.dol", 0x2B2F84, 0x158
.global __vt__9ActKinoko
__vt__9ActKinoko:
	.incbin "baserom.dol", 0x2B30DC, 0x104
.global __vt__8ActChase
__vt__8ActChase:
	.incbin "baserom.dol", 0x2B31E0, 0x9C
.global __vt__Q28ActChase11Initialiser
__vt__Q28ActChase11Initialiser:
	.incbin "baserom.dol", 0x2B327C, 0xA0
.global __vt__8ActCrowd
__vt__8ActCrowd:
	.incbin "baserom.dol", 0x2B331C, 0x74
.global __vt__17SlotChangeListner
__vt__17SlotChangeListner:
	.incbin "baserom.dol", 0x2B3390, 0x9C
.global __vt__8ActDecoy
__vt__8ActDecoy:
	.incbin "baserom.dol", 0x2B342C, 0x12C
.global __vt__8ActEnter
__vt__8ActEnter:
	.incbin "baserom.dol", 0x2B3558, 0xAC
.global lbl_802B6604
lbl_802B6604:
	.incbin "baserom.dol", 0x2B3604, 0x50
.global __vt__9ActEscape
__vt__9ActEscape:
	.incbin "baserom.dol", 0x2B3654, 0x9C
.global __vt__Q29ActEscape11Initialiser
__vt__Q29ActEscape11Initialiser:
	.incbin "baserom.dol", 0x2B36F0, 0x74
.global __vt__7ActExit
__vt__7ActExit:
	.incbin "baserom.dol", 0x2B3764, 0xEC
.global __vt__7ActMine
__vt__7ActMine:
	.incbin "baserom.dol", 0x2B3850, 0x160
.global __vt__12ActFormation
__vt__12ActFormation:
	.incbin "baserom.dol", 0x2B39B0, 0xBC
.global motions
motions:
	.incbin "baserom.dol", 0x2B3A6C, 0x5C
.global __vt__7ActFree
__vt__7ActFree:
	.incbin "baserom.dol", 0x2B3AC8, 0xEC
.global __vt__7ActGoto
__vt__7ActGoto:
	.incbin "baserom.dol", 0x2B3BB4, 0x9C
.global __vt__Q27ActGoto11Initialiser
__vt__Q27ActGoto11Initialiser:
	.incbin "baserom.dol", 0x2B3C50, 0x80
.global __vt__8ActGuard
__vt__8ActGuard:
	.incbin "baserom.dol", 0x2B3CD0, 0xA8
.global lbl_802B6D78
lbl_802B6D78:
	.incbin "baserom.dol", 0x2B3D78, 0x9C
.global __vt__9ActFlower
__vt__9ActFlower:
	.incbin "baserom.dol", 0x2B3E14, 0xC8
.global __vt__11ActPickItem
__vt__11ActPickItem:
	.incbin "baserom.dol", 0x2B3EDC, 0x11C
.global __vt__10ActDeliver
__vt__10ActDeliver:
	.incbin "baserom.dol", 0x2B3FF8, 0x9C
.global __vt__Q210ActDeliver11Initialiser
__vt__Q210ActDeliver11Initialiser:
	.incbin "baserom.dol", 0x2B4094, 0xC
.global __vt__Q26Action11Initialiser
__vt__Q26Action11Initialiser:
	.incbin "baserom.dol", 0x2B40A0, 0x38
.global __vt__15ActPickCreature
__vt__15ActPickCreature:
	.incbin "baserom.dol", 0x2B40D8, 0x128
.global __vt__18ActPulloutCreature
__vt__18ActPulloutCreature:
	.incbin "baserom.dol", 0x2B4200, 0xDC
.global __vt__10ActPullout
__vt__10ActPullout:
	.incbin "baserom.dol", 0x2B42DC, 0xA0
.global lbl_802B737C
lbl_802B737C:
	.incbin "baserom.dol", 0x2B437C, 0xB8
.global __vt__7ActPush
__vt__7ActPush:
	.incbin "baserom.dol", 0x2B4434, 0x100
.global __vt__10ActPutItem
__vt__10ActPutItem:
	.incbin "baserom.dol", 0x2B4534, 0xA0
.global __vt__10ActPutBomb
__vt__10ActPutBomb:
	.incbin "baserom.dol", 0x2B45D4, 0x114
.global stateName
stateName:
	.incbin "baserom.dol", 0x2B46E8, 0x4C
.global __vt__13ActRandomBoid
__vt__13ActRandomBoid:
	.incbin "baserom.dol", 0x2B4734, 0xA0
.global __vt__Q213ActRandomBoid11Initialiser
__vt__Q213ActRandomBoid11Initialiser:
	.incbin "baserom.dol", 0x2B47D4, 0x54
.global __vt__Q213ActRandomBoid12AnimListener
__vt__Q213ActRandomBoid12AnimListener:
	.incbin "baserom.dol", 0x2B4828, 0xAC
.global __vt__9ActRescue
__vt__9ActRescue:
	.incbin "baserom.dol", 0x2B48D4, 0xE8
.global __vt__7ActRope
__vt__7ActRope:
	.incbin "baserom.dol", 0x2B49BC, 0x100
.global __vt__16ActShootCreature
__vt__16ActShootCreature:
	.incbin "baserom.dol", 0x2B4ABC, 0xC8
.global __vt__8ActShoot
__vt__8ActShoot:
	.incbin "baserom.dol", 0x2B4B84, 0xC0
.global lbl_802B7C44
lbl_802B7C44:
	.incbin "baserom.dol", 0x2B4C44, 0x48
.global __vt__8ActWatch
__vt__8ActWatch:
	.incbin "baserom.dol", 0x2B4C8C, 0x9C
.global __vt__Q28ActWatch11Initialiser
__vt__Q28ActWatch11Initialiser:
	.incbin "baserom.dol", 0x2B4D28, 0x50
.global __vt__Q28ActWatch12AnimListener
__vt__Q28ActWatch12AnimListener:
	.incbin "baserom.dol", 0x2B4D78, 0x74
.global __vt__7ActWeed
__vt__7ActWeed:
	.incbin "baserom.dol", 0x2B4DEC, 0xC4
.global lbl_802B7EB0
lbl_802B7EB0:
	.incbin "baserom.dol", 0x2B4EB0, 0x28
.global info__8Reaction
info__8Reaction:
	.incbin "baserom.dol", 0x2B4ED8, 0x24
.global lbl_802B7EFC
lbl_802B7EFC:
	.incbin "baserom.dol", 0x2B4EFC, 0xD8
.global __vt__9TopAction
__vt__9TopAction:
	.incbin "baserom.dol", 0x2B4FD4, 0xAC
.global __vt__Q29TopAction14MotionListener
__vt__Q29TopAction14MotionListener:
	.incbin "baserom.dol", 0x2B5080, 0x2C
.global __vt__8OrAction
__vt__8OrAction:
	.incbin "baserom.dol", 0x2B50AC, 0x84
.global __vt__9AndAction
__vt__9AndAction:
	.incbin "baserom.dol", 0x2B5130, 0x64
.global __vt__6Action
__vt__6Action:
	.incbin "baserom.dol", 0x2B5194, 0x64
.global __vt__15Receiver$$04Piki$$1
__vt__15Receiver$$04Piki$$1:
	.incbin "baserom.dol", 0x2B51F8, 0x44
.global lbl_802B823C
lbl_802B823C:
	.incbin "baserom.dol", 0x2B523C, 0xC
.global lbl_802B8248
lbl_802B8248:
	.incbin "baserom.dol", 0x2B5248, 0xC
.global lbl_802B8254
lbl_802B8254:
	.incbin "baserom.dol", 0x2B5254, 0x54
.global __vt__11CreatureInf
__vt__11CreatureInf:
	.incbin "baserom.dol", 0x2B52A8, 0x5C
.global __vt__14CreatureInfMgr
__vt__14CreatureInfMgr:
	.incbin "baserom.dol", 0x2B5304, 0x40
.global __vt__11BPikiInfMgr
__vt__11BPikiInfMgr:
	.incbin "baserom.dol", 0x2B5344, 0x20
.global __vt__10MonoInfMgr
__vt__10MonoInfMgr:
	.incbin "baserom.dol", 0x2B5364, 0x20
.global __vt__6InfMgr
__vt__6InfMgr:
	.incbin "baserom.dol", 0x2B5384, 0x44
.global __vt__8BPikiInf
__vt__8BPikiInf:
	.incbin "baserom.dol", 0x2B53C8, 0x20
.global __vt__7BaseInf
__vt__7BaseInf:
	.incbin "baserom.dol", 0x2B53E8, 0x40
.global lbl_802B8428
lbl_802B8428:
	.incbin "baserom.dol", 0x2B5428, 0xC
.global lbl_802B8434
lbl_802B8434:
	.incbin "baserom.dol", 0x2B5434, 0x3C
.global lbl_802B8470
lbl_802B8470:
	.incbin "baserom.dol", 0x2B5470, 0x58
.global lbl_802B84C8
lbl_802B84C8:
	.incbin "baserom.dol", 0x2B54C8, 0x38
.global lbl_802B8500
lbl_802B8500:
	.incbin "baserom.dol", 0x2B5500, 0x64
.global states_str
states_str:
	.incbin "baserom.dol", 0x2B5564, 0x44
.global _standStr
_standStr:
	.incbin "baserom.dol", 0x2B55A8, 0x148
.global _modeStr
_modeStr:
	.incbin "baserom.dol", 0x2B56F0, 0x64
.global _colorNames
_colorNames:
	.incbin "baserom.dol", 0x2B5754, 0x20
.global __vt__19StateMachine$$04Piki$$1
__vt__19StateMachine$$04Piki$$1:
	.incbin "baserom.dol", 0x2B5774, 0x1A4
.global __vt__4Piki
__vt__4Piki:
	.incbin "baserom.dol", 0x2B5918, 0x138
.global lbl_802B8A50
lbl_802B8A50:
	.incbin "baserom.dol", 0x2B5A50, 0x144
.global __vt__7PikiMgr
__vt__7PikiMgr:
	.incbin "baserom.dol", 0x2B5B94, 0x114
.global __vt__8PikiProp
__vt__8PikiProp:
	.incbin "baserom.dol", 0x2B5CA8, 0x34
.global lbl_802B8CDC
lbl_802B8CDC:
	.incbin "baserom.dol", 0x2B5CDC, 0xC
.global lbl_802B8CE8
lbl_802B8CE8:
	.incbin "baserom.dol", 0x2B5CE8, 0xC
.global lbl_802B8CF4
lbl_802B8CF4:
	.incbin "baserom.dol", 0x2B5CF4, 0xC
.global lbl_802B8D00
lbl_802B8D00:
	.incbin "baserom.dol", 0x2B5D00, 0x10
.global lbl_802B8D10
lbl_802B8D10:
	.incbin "baserom.dol", 0x2B5D10, 0x10
.global lbl_802B8D20
lbl_802B8D20:
	.incbin "baserom.dol", 0x2B5D20, 0xC
.global lbl_802B8D2C
lbl_802B8D2C:
	.incbin "baserom.dol", 0x2B5D2C, 0xC
.global lbl_802B8D38
lbl_802B8D38:
	.incbin "baserom.dol", 0x2B5D38, 0xC
.global lbl_802B8D44
lbl_802B8D44:
	.incbin "baserom.dol", 0x2B5D44, 0xA4
.global __vt__16PikiEmotionState
__vt__16PikiEmotionState:
	.incbin "baserom.dol", 0x2B5DE8, 0x98
.global __vt__13PikiDeadState
__vt__13PikiDeadState:
	.incbin "baserom.dol", 0x2B5E80, 0x98
.global __vt__14PikiDyingState
__vt__14PikiDyingState:
	.incbin "baserom.dol", 0x2B5F18, 0x9C
.global __vt__16PikiPressedState
__vt__16PikiPressedState:
	.incbin "baserom.dol", 0x2B5FB4, 0x9C
.global __vt__17PikiAutoNukiState
__vt__17PikiAutoNukiState:
	.incbin "baserom.dol", 0x2B6050, 0x98
.global __vt__15PikiNukareState
__vt__15PikiNukareState:
	.incbin "baserom.dol", 0x2B60E8, 0x9C
.global __vt__19PikiNukareWaitState
__vt__19PikiNukareWaitState:
	.incbin "baserom.dol", 0x2B6184, 0x98
.global __vt__13PikiBuryState
__vt__13PikiBuryState:
	.incbin "baserom.dol", 0x2B621C, 0x9C
.global __vt__17PikiPushPikiState
__vt__17PikiPushPikiState:
	.incbin "baserom.dol", 0x2B62B8, 0x98
.global __vt__13PikiPushState
__vt__13PikiPushState:
	.incbin "baserom.dol", 0x2B6350, 0x98
.global __vt__13PikiWaveState
__vt__13PikiWaveState:
	.incbin "baserom.dol", 0x2B63E8, 0x98
.global __vt__15PikiGrowupState
__vt__15PikiGrowupState:
	.incbin "baserom.dol", 0x2B6480, 0xA0
.global __vt__21PikiKinokoChangeState
__vt__21PikiKinokoChangeState:
	.incbin "baserom.dol", 0x2B6520, 0x98
.global __vt__13PikiGrowState
__vt__13PikiGrowState:
	.incbin "baserom.dol", 0x2B65B8, 0x98
.global __vt__15PikiFlyingState
__vt__15PikiFlyingState:
	.incbin "baserom.dol", 0x2B6650, 0x98
.global __vt__13PikiEmitState
__vt__13PikiEmitState:
	.incbin "baserom.dol", 0x2B66E8, 0xA0
.global __vt__20PikiWaterHangedState
__vt__20PikiWaterHangedState:
	.incbin "baserom.dol", 0x2B6788, 0x98
.global __vt__15PikiHangedState
__vt__15PikiHangedState:
	.incbin "baserom.dol", 0x2B6820, 0x98
.global __vt__15PikiGoHangState
__vt__15PikiGoHangState:
	.incbin "baserom.dol", 0x2B68B8, 0x98
.global __vt__14PikiCliffState
__vt__14PikiCliffState:
	.incbin "baserom.dol", 0x2B6950, 0x98
.global __vt__13PikiFallState
__vt__13PikiFallState:
	.incbin "baserom.dol", 0x2B69E8, 0x9C
.global __vt__17PikiFallMeckState
__vt__17PikiFallMeckState:
	.incbin "baserom.dol", 0x2B6A84, 0x98
.global __vt__14PikiFlownState
__vt__14PikiFlownState:
	.incbin "baserom.dol", 0x2B6B1C, 0x98
.global __vt__14PikiFlickState
__vt__14PikiFlickState:
	.incbin "baserom.dol", 0x2B6BB4, 0x98
.global __vt__15PikiBulletState
__vt__15PikiBulletState:
	.incbin "baserom.dol", 0x2B6C4C, 0x9C
.global __vt__18PikiSwallowedState
__vt__18PikiSwallowedState:
	.incbin "baserom.dol", 0x2B6CE8, 0x98
.global __vt__14PikiFiredState
__vt__14PikiFiredState:
	.incbin "baserom.dol", 0x2B6D80, 0x98
.global __vt__15PikiBubbleState
__vt__15PikiBubbleState:
	.incbin "baserom.dol", 0x2B6E18, 0x98
.global __vt__15PikiKinokoState
__vt__15PikiKinokoState:
	.incbin "baserom.dol", 0x2B6EB0, 0xD0
.global __vt__14PikiDrownState
__vt__14PikiDrownState:
	.incbin "baserom.dol", 0x2B6F80, 0x98
.global __vt__15PikiAbsorbState
__vt__15PikiAbsorbState:
	.incbin "baserom.dol", 0x2B7018, 0x98
.global __vt__15PikiNormalState
__vt__15PikiNormalState:
	.incbin "baserom.dol", 0x2B70B0, 0x98
.global __vt__15PikiLookAtState
__vt__15PikiLookAtState:
	.incbin "baserom.dol", 0x2B7148, 0x6C
.global __vt__13AState$$04Piki$$1
__vt__13AState$$04Piki$$1:
	.incbin "baserom.dol", 0x2B71B4, 0x88
.global __vt__9PikiState
__vt__9PikiState:
	.incbin "baserom.dol", 0x2B723C, 0xA0
.global __vt__16PikiStateMachine
__vt__16PikiStateMachine:
	.incbin "baserom.dol", 0x2B72DC, 0x44
.global lbl_802BA320
lbl_802BA320:
	.incbin "baserom.dol", 0x2B7320, 0x1C
.global lbl_802BA33C
lbl_802BA33C:
	.incbin "baserom.dol", 0x2B733C, 0x12C
.global __vt__8ViewPiki
__vt__8ViewPiki:
	.incbin "baserom.dol", 0x2B7468, 0x160
.global __vt__13CndStickMouth
__vt__13CndStickMouth:
	.incbin "baserom.dol", 0x2B75C8, 0x24
.global __vt__10CndIsAtari
__vt__10CndIsAtari:
	.incbin "baserom.dol", 0x2B75EC, 0x28
.global __vt__12CndIsVisible
__vt__12CndIsVisible:
	.incbin "baserom.dol", 0x2B7614, 0xC
.global lbl_802BA620
lbl_802BA620:
	.incbin "baserom.dol", 0x2B7620, 0x1C
.global lbl_802BA63C
lbl_802BA63C:
	.incbin "baserom.dol", 0x2B763C, 0xC
.global lbl_802BA648
lbl_802BA648:
	.incbin "baserom.dol", 0x2B7648, 0xC
.global lbl_802BA654
lbl_802BA654:
	.incbin "baserom.dol", 0x2B7654, 0xC
.global lbl_802BA660
lbl_802BA660:
	.incbin "baserom.dol", 0x2B7660, 0x10
.global lbl_802BA670
lbl_802BA670:
	.incbin "baserom.dol", 0x2B7670, 0x14
.global lbl_802BA684
lbl_802BA684:
	.incbin "baserom.dol", 0x2B7684, 0x4C
.global lbl_802BA6D0
lbl_802BA6D0:
	.incbin "baserom.dol", 0x2B76D0, 0xC
.global lbl_802BA6DC
lbl_802BA6DC:
	.incbin "baserom.dol", 0x2B76DC, 0x10
.global lbl_802BA6EC
lbl_802BA6EC:
	.incbin "baserom.dol", 0x2B76EC, 0x24
.global coStrings
coStrings:
	.incbin "baserom.dol", 0x2B7710, 0x70
.global __vt__13GenAreaCircle
__vt__13GenAreaCircle:
	.incbin "baserom.dol", 0x2B7780, 0x64
.global __vt__12GenAreaPoint
__vt__12GenAreaPoint:
	.incbin "baserom.dol", 0x2B77E4, 0x78
.global __vt__15GenTypeInitRand
__vt__15GenTypeInitRand:
	.incbin "baserom.dol", 0x2B785C, 0x64
.global __vt__13GenTypeAtOnce
__vt__13GenTypeAtOnce:
	.incbin "baserom.dol", 0x2B78C0, 0x60
.global __vt__10GenTypeOne
__vt__10GenTypeOne:
	.incbin "baserom.dol", 0x2B7920, 0x84
.global __vt__13GenObjectPiki
__vt__13GenObjectPiki:
	.incbin "baserom.dol", 0x2B79A4, 0x80
.global __vt__12GeneratorMgr
__vt__12GeneratorMgr:
	.incbin "baserom.dol", 0x2B7A24, 0x58
.global __vt__9Generator
__vt__9Generator:
	.incbin "baserom.dol", 0x2B7A7C, 0x4C
.global __vt__7GenArea
__vt__7GenArea:
	.incbin "baserom.dol", 0x2B7AC8, 0x70
.global __vt__7GenType
__vt__7GenType:
	.incbin "baserom.dol", 0x2B7B38, 0x38
.global __vt__9GenObject
__vt__9GenObject:
	.incbin "baserom.dol", 0x2B7B70, 0x64
.global __vt__7GenBase
__vt__7GenBase:
	.incbin "baserom.dol", 0x2B7BD4, 0x48
.global lbl_802BAC1C
lbl_802BAC1C:
	.incbin "baserom.dol", 0x2B7C1C, 0x150
.global __vt__Q214GeneratorCache5Cache
__vt__Q214GeneratorCache5Cache:
	.incbin "baserom.dol", 0x2B7D6C, 0xEC
.global __vt__15CreatureNodeMgr
__vt__15CreatureNodeMgr:
	.incbin "baserom.dol", 0x2B7E58, 0xB4
.global __vt__13PolyObjectMgr
__vt__13PolyObjectMgr:
	.incbin "baserom.dol", 0x2B7F0C, 0xBC
.global __vt__13MonoObjectMgr
__vt__13MonoObjectMgr:
	.incbin "baserom.dol", 0x2B7FC8, 0xB8
.global __vt__9ObjectMgr
__vt__9ObjectMgr:
	.incbin "baserom.dol", 0x2B8080, 0xC0
.global __vt__12SearchBuffer
__vt__12SearchBuffer:
	.incbin "baserom.dol", 0x2B8140, 0x5C
.global __vt__12RefCountable
__vt__12RefCountable:
	.incbin "baserom.dol", 0x2B819C, 0x14
.global table
table:
	.incbin "baserom.dol", 0x2B81B0, 0x190
.global __vt__4Weed
__vt__4Weed:
	.incbin "baserom.dol", 0x2B8340, 0x19C
.global __vt__8WeedsGen
__vt__8WeedsGen:
	.incbin "baserom.dol", 0x2B84DC, 0x19C
.global __vt__8GrassGen
__vt__8GrassGen:
	.incbin "baserom.dol", 0x2B8678, 0x190
.global __vt__7RockGen
__vt__7RockGen:
	.incbin "baserom.dol", 0x2B8808, 0x26C
.global __vt__10BoBaseItem
__vt__10BoBaseItem:
	.incbin "baserom.dol", 0x2B8A74, 0x19C
.global __vt__8KusaItem
__vt__8KusaItem:
	.incbin "baserom.dol", 0x2B8C10, 0x270
.global __vt__13FishGenerator
__vt__13FishGenerator:
	.incbin "baserom.dol", 0x2B8E80, 0x160
.global lbl_802BBFE0
lbl_802BBFE0:
	.incbin "baserom.dol", 0x2B8FE0, 0xC
.global trKeys
trKeys:
	.incbin "baserom.dol", 0x2B8FEC, 0xC
.global leg_ids
leg_ids:
	.incbin "baserom.dol", 0x2B8FF8, 0xC
.global effects
effects:
	.incbin "baserom.dol", 0x2B9004, 0x17C
.global __vt__8Suckable
__vt__8Suckable:
	.incbin "baserom.dol", 0x2B9180, 0x1B0
.global __vt__7UfoItem
__vt__7UfoItem:
	.incbin "baserom.dol", 0x2B9330, 0x184
.global lbl_802BC4B4
lbl_802BC4B4:
	.incbin "baserom.dol", 0x2B94B4, 0x18
.global lbl_802BC4CC
lbl_802BC4CC:
	.incbin "baserom.dol", 0x2B94CC, 0x60
.global motionLabels__15PaniUfoAnimator
motionLabels__15PaniUfoAnimator:
	.incbin "baserom.dol", 0x2B952C, 0x90
.global __vt__15PaniUfoAnimator
__vt__15PaniUfoAnimator:
	.incbin "baserom.dol", 0x2B95BC, 0x134
.global __vt__8BombItem
__vt__8BombItem:
	.incbin "baserom.dol", 0x2B96F0, 0x184
.global leg_ids_1
leg_ids_1:
	.incbin "baserom.dol", 0x2B9874, 0x318
.global __vt__8GoalItem
__vt__8GoalItem:
	.incbin "baserom.dol", 0x2B9B8C, 0x2A8
.global __vt__12PikiHeadItem
__vt__12PikiHeadItem:
	.incbin "baserom.dol", 0x2B9E34, 0x374
.global __vt__8DoorItem
__vt__8DoorItem:
	.incbin "baserom.dol", 0x2BA1A8, 0x178
.global __vt__7KeyItem
__vt__7KeyItem:
	.incbin "baserom.dol", 0x2BA320, 0x1CC
.global __vt__8RopeItem
__vt__8RopeItem:
	.incbin "baserom.dol", 0x2BA4EC, 0x194
.global __vt__8SeedItem
__vt__8SeedItem:
	.incbin "baserom.dol", 0x2BA680, 0x124
.global lbl_802BD7A4
lbl_802BD7A4:
	.incbin "baserom.dol", 0x2BA7A4, 0xC
.global lbl_802BD7B0
lbl_802BD7B0:
	.incbin "baserom.dol", 0x2BA7B0, 0x10
.global lbl_802BD7C0
lbl_802BD7C0:
	.incbin "baserom.dol", 0x2BA7C0, 0x10
.global lbl_802BD7D0
lbl_802BD7D0:
	.incbin "baserom.dol", 0x2BA7D0, 0xC0
.global __vt__13GenObjectItem
__vt__13GenObjectItem:
	.incbin "baserom.dol", 0x2BA890, 0x7C
.global lbl_802BD90C
lbl_802BD90C:
	.incbin "baserom.dol", 0x2BA90C, 0xC
.global lbl_802BD918
lbl_802BD918:
	.incbin "baserom.dol", 0x2BA918, 0x44
.global __vt__Q211FallWaterAI13DisappearInit
__vt__Q211FallWaterAI13DisappearInit:
	.incbin "baserom.dol", 0x2BA95C, 0x30
.global __vt__Q211FallWaterAI8EmitInit
__vt__Q211FallWaterAI8EmitInit:
	.incbin "baserom.dol", 0x2BA98C, 0x34
.global __vt__Q211FallWaterAI11CollideInit
__vt__Q211FallWaterAI11CollideInit:
	.incbin "baserom.dol", 0x2BA9C0, 0x60
.global __vt__11FallWaterAI
__vt__11FallWaterAI:
	.incbin "baserom.dol", 0x2BAA20, 0x34
.global __vt__Q27WaterAI3Die
__vt__Q27WaterAI3Die:
	.incbin "baserom.dol", 0x2BAA54, 0x70
.global __vt__Q27WaterAI11CollideChar
__vt__Q27WaterAI11CollideChar:
	.incbin "baserom.dol", 0x2BAAC4, 0x28
.global __vt__7WaterAI
__vt__7WaterAI:
	.incbin "baserom.dol", 0x2BAAEC, 0x30
.global __vt__Q25GemAI3Die
__vt__Q25GemAI3Die:
	.incbin "baserom.dol", 0x2BAB1C, 0x28
.global __vt__Q25GemAI8RiseExec
__vt__Q25GemAI8RiseExec:
	.incbin "baserom.dol", 0x2BAB44, 0x28
.global __vt__Q25GemAI8RiseInit
__vt__Q25GemAI8RiseInit:
	.incbin "baserom.dol", 0x2BAB6C, 0x20
.global __vt__5GemAI
__vt__5GemAI:
	.incbin "baserom.dol", 0x2BAB8C, 0x34
.global __vt__Q26GoalAI6Effect
__vt__Q26GoalAI6Effect:
	.incbin "baserom.dol", 0x2BABC0, 0x2C
.global __vt__Q26GoalAI8EmitWait
__vt__Q26GoalAI8EmitWait:
	.incbin "baserom.dol", 0x2BABEC, 0x2C
.global __vt__Q26GoalAI8EmitPiki
__vt__Q26GoalAI8EmitPiki:
	.incbin "baserom.dol", 0x2BAC18, 0x2C
.global __vt__Q26GoalAI8BootDone
__vt__Q26GoalAI8BootDone:
	.incbin "baserom.dol", 0x2BAC44, 0x2C
.global __vt__Q26GoalAI8BootEmit
__vt__Q26GoalAI8BootEmit:
	.incbin "baserom.dol", 0x2BAC70, 0x2C
.global __vt__Q26GoalAI8BootInit
__vt__Q26GoalAI8BootInit:
	.incbin "baserom.dol", 0x2BAC9C, 0x2C
.global __vt__Q26GoalAI8WaitInit
__vt__Q26GoalAI8WaitInit:
	.incbin "baserom.dol", 0x2BACC8, 0x3C
.global __vt__Q26GoalAI11NotFinished
__vt__Q26GoalAI11NotFinished:
	.incbin "baserom.dol", 0x2BAD04, 0x58
.global __vt__6GoalAI
__vt__6GoalAI:
	.incbin "baserom.dol", 0x2BAD5C, 0x34
.global __vt__Q26BombAI7DieExec
__vt__Q26BombAI7DieExec:
	.incbin "baserom.dol", 0x2BAD90, 0x28
.global __vt__Q26BombAI7DieInit
__vt__Q26BombAI7DieInit:
	.incbin "baserom.dol", 0x2BADB8, 0x2C
.global __vt__Q26BombAI8MizuExec
__vt__Q26BombAI8MizuExec:
	.incbin "baserom.dol", 0x2BADE4, 0x2C
.global __vt__Q26BombAI8MizuInit
__vt__Q26BombAI8MizuInit:
	.incbin "baserom.dol", 0x2BAE10, 0x2C
.global __vt__Q26BombAI8BombExec
__vt__Q26BombAI8BombExec:
	.incbin "baserom.dol", 0x2BAE3C, 0x68
.global __vt__11CndBombable
__vt__11CndBombable:
	.incbin "baserom.dol", 0x2BAEA4, 0xC
.global __vt__11CndCollPart
__vt__11CndCollPart:
	.incbin "baserom.dol", 0x2BAEB0, 0x2C
.global __vt__Q26BombAI8BombInit
__vt__Q26BombAI8BombInit:
	.incbin "baserom.dol", 0x2BAEDC, 0x28
.global __vt__Q26BombAI7SetExec
__vt__Q26BombAI7SetExec:
	.incbin "baserom.dol", 0x2BAF04, 0x28
.global __vt__Q26BombAI7SetInit
__vt__Q26BombAI7SetInit:
	.incbin "baserom.dol", 0x2BAF2C, 0x20
.global __vt__6BombAI
__vt__6BombAI:
	.incbin "baserom.dol", 0x2BAF4C, 0x38
.global __vt__Q210PikiHeadAI4Dead
__vt__Q210PikiHeadAI4Dead:
	.incbin "baserom.dol", 0x2BAF84, 0x30
.global __vt__Q210PikiHeadAI10KaretaExec
__vt__Q210PikiHeadAI10KaretaExec:
	.incbin "baserom.dol", 0x2BAFB4, 0x30
.global __vt__Q210PikiHeadAI10KaretaInit
__vt__Q210PikiHeadAI10KaretaInit:
	.incbin "baserom.dol", 0x2BAFE4, 0x30
.global __vt__Q210PikiHeadAI10GrowEffect
__vt__Q210PikiHeadAI10GrowEffect:
	.incbin "baserom.dol", 0x2BB014, 0x34
.global __vt__Q210PikiHeadAI12GrowupedExec
__vt__Q210PikiHeadAI12GrowupedExec:
	.incbin "baserom.dol", 0x2BB048, 0x30
.global __vt__Q210PikiHeadAI8WaitExec
__vt__Q210PikiHeadAI8WaitExec:
	.incbin "baserom.dol", 0x2BB078, 0x30
.global __vt__Q210PikiHeadAI8WaitInit
__vt__Q210PikiHeadAI8WaitInit:
	.incbin "baserom.dol", 0x2BB0A8, 0x30
.global __vt__Q210PikiHeadAI8TaneExec
__vt__Q210PikiHeadAI8TaneExec:
	.incbin "baserom.dol", 0x2BB0D8, 0x30
.global __vt__Q210PikiHeadAI8TaneInit
__vt__Q210PikiHeadAI8TaneInit:
	.incbin "baserom.dol", 0x2BB108, 0x30
.global __vt__Q210PikiHeadAI8BuryExec
__vt__Q210PikiHeadAI8BuryExec:
	.incbin "baserom.dol", 0x2BB138, 0x30
.global __vt__Q210PikiHeadAI8BuryInit
__vt__Q210PikiHeadAI8BuryInit:
	.incbin "baserom.dol", 0x2BB168, 0x30
.global __vt__Q210PikiHeadAI9BuryExec2
__vt__Q210PikiHeadAI9BuryExec2:
	.incbin "baserom.dol", 0x2BB198, 0x30
.global __vt__Q210PikiHeadAI9BuryInit2
__vt__Q210PikiHeadAI9BuryInit2:
	.incbin "baserom.dol", 0x2BB1C8, 0x34
.global __vt__Q210PikiHeadAI13FlyingCleanup
__vt__Q210PikiHeadAI13FlyingCleanup:
	.incbin "baserom.dol", 0x2BB1FC, 0x30
.global __vt__Q210PikiHeadAI10FlyingExec
__vt__Q210PikiHeadAI10FlyingExec:
	.incbin "baserom.dol", 0x2BB22C, 0x34
.global __vt__Q210PikiHeadAI12FlyingEffect
__vt__Q210PikiHeadAI12FlyingEffect:
	.incbin "baserom.dol", 0x2BB260, 0x30
.global __vt__Q210PikiHeadAI11BounceSound
__vt__Q210PikiHeadAI11BounceSound:
	.incbin "baserom.dol", 0x2BB290, 0x2C
.global __vt__10PikiHeadAI
__vt__10PikiHeadAI:
	.incbin "baserom.dol", 0x2BB2BC, 0x3C
.global __vt__Q28SluiceAI10DamageInit
__vt__Q28SluiceAI10DamageInit:
	.incbin "baserom.dol", 0x2BB2F8, 0x30
.global __vt__Q28SluiceAI10ChangeInit
__vt__Q28SluiceAI10ChangeInit:
	.incbin "baserom.dol", 0x2BB328, 0x2C
.global __vt__Q28SluiceAI8WaitInit
__vt__Q28SluiceAI8WaitInit:
	.incbin "baserom.dol", 0x2BB354, 0x2C
.global __vt__Q28SluiceAI8AddCount
__vt__Q28SluiceAI8AddCount:
	.incbin "baserom.dol", 0x2BB380, 0x30
.global __vt__Q28SluiceAI10MotionDone
__vt__Q28SluiceAI10MotionDone:
	.incbin "baserom.dol", 0x2BB3B0, 0x28
.global __vt__Q28SluiceAI4Init
__vt__Q28SluiceAI4Init:
	.incbin "baserom.dol", 0x2BB3D8, 0xC
.global __vt__9SAIAction
__vt__9SAIAction:
	.incbin "baserom.dol", 0x2BB3E4, 0xCC
.global __vt__8SluiceAI
__vt__8SluiceAI:
	.incbin "baserom.dol", 0x2BB4B0, 0x48
.global lbl_802BE4F8
lbl_802BE4F8:
	.incbin "baserom.dol", 0x2BB4F8, 0x1C
.global lbl_802BE514
lbl_802BE514:
	.incbin "baserom.dol", 0x2BB514, 0x18
.global lbl_802BE52C
lbl_802BE52C:
	.incbin "baserom.dol", 0x2BB52C, 0x18
.global lbl_802BE544
lbl_802BE544:
	.incbin "baserom.dol", 0x2BB544, 0x58
.global lbl_802BE59C
lbl_802BE59C:
	.incbin "baserom.dol", 0x2BB59C, 0xC
.global lbl_802BE5A8
lbl_802BE5A8:
	.incbin "baserom.dol", 0x2BB5A8, 0x1CC
.global lbl_802BE774
lbl_802BE774:
	.incbin "baserom.dol", 0x2BB774, 0x134
.global __vt__11PikiHeadMgr
__vt__11PikiHeadMgr:
	.incbin "baserom.dol", 0x2BB8A8, 0xB4
.global __vt__16PikiHeadItemProp
__vt__16PikiHeadItemProp:
	.incbin "baserom.dol", 0x2BB95C, 0x7C
.global __vt__7ItemMgr
__vt__7ItemMgr:
	.incbin "baserom.dol", 0x2BB9D8, 0xAC
.global __vt__15InteractBikkuri
__vt__15InteractBikkuri:
	.incbin "baserom.dol", 0x2BBA84, 0xE8
.global __vt__12ItemCreature
__vt__12ItemCreature:
	.incbin "baserom.dol", 0x2BBB6C, 0x174
.global __vt__8DoorProp
__vt__8DoorProp:
	.incbin "baserom.dol", 0x2BBCE0, 0x18
.global __vt__7KeyProp
__vt__7KeyProp:
	.incbin "baserom.dol", 0x2BBCF8, 0x24
.global __vt__8SeedProp
__vt__8SeedProp:
	.incbin "baserom.dol", 0x2BBD1C, 0x24
.global __vt__8RopeProp
__vt__8RopeProp:
	.incbin "baserom.dol", 0x2BBD40, 0x28
.global __vt__12MizuItemProp
__vt__12MizuItemProp:
	.incbin "baserom.dol", 0x2BBD68, 0x28
.global __vt__12BombItemProp
__vt__12BombItemProp:
	.incbin "baserom.dol", 0x2BBD90, 0x34
.global __vt__Q27ItemMgr7UseNode
__vt__Q27ItemMgr7UseNode:
	.incbin "baserom.dol", 0x2BBDC4, 0x2C
.global __vt__12KusaItemProp
__vt__12KusaItemProp:
	.incbin "baserom.dol", 0x2BBDF0, 0x2C
.global __vt__16BuildingItemProp
__vt__16BuildingItemProp:
	.incbin "baserom.dol", 0x2BBE1C, 0x5C
.global __vt__11UfoItemProp
__vt__11UfoItemProp:
	.incbin "baserom.dol", 0x2BBE78, 0x28
.global __vt__12GoalItemProp
__vt__12GoalItemProp:
	.incbin "baserom.dol", 0x2BBEA0, 0x98
.global __vt__13MeltingPotMgr
__vt__13MeltingPotMgr:
	.incbin "baserom.dol", 0x2BBF38, 0x9C
.global __vt__12CreatureNode
__vt__12CreatureNode:
	.incbin "baserom.dol", 0x2BBFD4, 0x88
.global __vt__12BuildingItem
__vt__12BuildingItem:
	.incbin "baserom.dol", 0x2BC05C, 0x2CC
.global __vt__18NaviDemoSunsetGoal
__vt__18NaviDemoSunsetGoal:
	.incbin "baserom.dol", 0x2BC328, 0x1AC
.global __vt__19NaviDemoSunsetStart
__vt__19NaviDemoSunsetStart:
	.incbin "baserom.dol", 0x2BC4D4, 0x198
.global __vt__7Fulcrum
__vt__7Fulcrum:
	.incbin "baserom.dol", 0x2BC66C, 0x1A4
.global __vt__11BombGenItem
__vt__11BombGenItem:
	.incbin "baserom.dol", 0x2BC810, 0x15C
.global __vt__10ItemObject
__vt__10ItemObject:
	.incbin "baserom.dol", 0x2BC96C, 0x19C
.global __vt__8ItemBall
__vt__8ItemBall:
	.incbin "baserom.dol", 0x2BCB08, 0x278
.global __vt__8MizuItem
__vt__8MizuItem:
	.incbin "baserom.dol", 0x2BCD80, 0x18C
.global motionLabels__16PaniItemAnimator
motionLabels__16PaniItemAnimator:
	.incbin "baserom.dol", 0x2BCF0C, 0x8C
.global __vt__16PaniItemAnimator
__vt__16PaniItemAnimator:
	.incbin "baserom.dol", 0x2BCF98, 0x2C
.global lbl_802BFFC4
lbl_802BFFC4:
	.incbin "baserom.dol", 0x2BCFC4, 0xC
.global lbl_802BFFD0
lbl_802BFFD0:
	.incbin "baserom.dol", 0x2BCFD0, 0x14
.global lbl_802BFFE4
lbl_802BFFE4:
	.incbin "baserom.dol", 0x2BCFE4, 0x7C
.global __vt__13GenObjectNavi
__vt__13GenObjectNavi:
	.incbin "baserom.dol", 0x2BD060, 0x38
.global lbl_802C0098
lbl_802C0098:
	.incbin "baserom.dol", 0x2BD098, 0xC
.global lbl_802C00A4
lbl_802C00A4:
	.incbin "baserom.dol", 0x2BD0A4, 0x10
.global lbl_802C00B4
lbl_802C00B4:
	.incbin "baserom.dol", 0x2BD0B4, 0x24
.global lbl_802C00D8
lbl_802C00D8:
	.incbin "baserom.dol", 0x2BD0D8, 0x54
.global __vt__12InteractSuck
__vt__12InteractSuck:
	.incbin "baserom.dol", 0x2BD12C, 0x48
.global __vt__14InteractGeyzer
__vt__14InteractGeyzer:
	.incbin "baserom.dol", 0x2BD174, 0x6C
.global __vt__19StateMachine$$04Navi$$1
__vt__19StateMachine$$04Navi$$1:
	.incbin "baserom.dol", 0x2BD1E0, 0x178
.global __vt__10NaviDrawer
__vt__10NaviDrawer:
	.incbin "baserom.dol", 0x2BD358, 0x58
.global __vt__10PelletView
__vt__10PelletView:
	.incbin "baserom.dol", 0x2BD3B0, 0xB4
.global __vt__8NaviProp
__vt__8NaviProp:
	.incbin "baserom.dol", 0x2BD464, 0xAC
.global __vt__4Navi
__vt__4Navi:
	.incbin "baserom.dol", 0x2BD510, 0x208
.global __vt__18NaviUfoAccessState
__vt__18NaviUfoAccessState:
	.incbin "baserom.dol", 0x2BD718, 0x88
.global __vt__20NaviPartsAccessState
__vt__20NaviPartsAccessState:
	.incbin "baserom.dol", 0x2BD7A0, 0x84
.global __vt__17NaviStartingState
__vt__17NaviStartingState:
	.incbin "baserom.dol", 0x2BD824, 0x84
.global __vt__17NaviPikiZeroState
__vt__17NaviPikiZeroState:
	.incbin "baserom.dol", 0x2BD8A8, 0x80
.global __vt__13NaviDeadState
__vt__13NaviDeadState:
	.incbin "baserom.dol", 0x2BD928, 0x80
.global __vt__15NaviIroIroState
__vt__15NaviIroIroState:
	.incbin "baserom.dol", 0x2BD9A8, 0x80
.global __vt__14NaviClearState
__vt__14NaviClearState:
	.incbin "baserom.dol", 0x2BDA28, 0x80
.global __vt__13NaviLockState
__vt__13NaviLockState:
	.incbin "baserom.dol", 0x2BDAA8, 0x80
.global __vt__15NaviAttackState
__vt__15NaviAttackState:
	.incbin "baserom.dol", 0x2BDB28, 0x80
.global __vt__14NaviWaterState
__vt__14NaviWaterState:
	.incbin "baserom.dol", 0x2BDBA8, 0x80
.global __vt__12NaviSowState
__vt__12NaviSowState:
	.incbin "baserom.dol", 0x2BDC28, 0x84
.global __vt__16NaviPressedState
__vt__16NaviPressedState:
	.incbin "baserom.dol", 0x2BDCAC, 0x84
.global __vt__19NaviNukuAdjustState
__vt__19NaviNukuAdjustState:
	.incbin "baserom.dol", 0x2BDD30, 0x80
.global __vt__13NaviNukuState
__vt__13NaviNukuState:
	.incbin "baserom.dol", 0x2BDDB0, 0x84
.global __vt__17NaviPushPikiState
__vt__17NaviPushPikiState:
	.incbin "baserom.dol", 0x2BDE34, 0x80
.global __vt__13NaviPushState
__vt__13NaviPushState:
	.incbin "baserom.dol", 0x2BDEB4, 0x80
.global __vt__14NaviThrowState
__vt__14NaviThrowState:
	.incbin "baserom.dol", 0x2BDF34, 0x84
.global __vt__18NaviThrowWaitState
__vt__18NaviThrowWaitState:
	.incbin "baserom.dol", 0x2BDFB8, 0x84
.global __vt__16NaviReleaseState
__vt__16NaviReleaseState:
	.incbin "baserom.dol", 0x2BE03C, 0x80
.global __vt__15NaviGatherState
__vt__15NaviGatherState:
	.incbin "baserom.dol", 0x2BE0BC, 0x80
.global __vt__15NaviGeyzerState
__vt__15NaviGeyzerState:
	.incbin "baserom.dol", 0x2BE13C, 0x80
.global __vt__14NaviFlickState
__vt__14NaviFlickState:
	.incbin "baserom.dol", 0x2BE1BC, 0x80
.global __vt__13NaviIdleState
__vt__13NaviIdleState:
	.incbin "baserom.dol", 0x2BE23C, 0x84
.global __vt__16NaviFunbariState
__vt__16NaviFunbariState:
	.incbin "baserom.dol", 0x2BE2C0, 0x84
.global __vt__17NaviRopeExitState
__vt__17NaviRopeExitState:
	.incbin "baserom.dol", 0x2BE344, 0x80
.global __vt__13NaviRopeState
__vt__13NaviRopeState:
	.incbin "baserom.dol", 0x2BE3C4, 0x80
.global __vt__13NaviPickState
__vt__13NaviPickState:
	.incbin "baserom.dol", 0x2BE444, 0xC4
.global __vt__18NaviContainerState
__vt__18NaviContainerState:
	.incbin "baserom.dol", 0x2BE508, 0x74
.global __vt__Q25GmWin13CloseListener
__vt__Q25GmWin13CloseListener:
	.incbin "baserom.dol", 0x2BE57C, 0xC
.global __vt__Q212ContainerWin8Listener
__vt__Q212ContainerWin8Listener:
	.incbin "baserom.dol", 0x2BE588, 0x38
.global __vt__12NaviUfoState
__vt__12NaviUfoState:
	.incbin "baserom.dol", 0x2BE5C0, 0x80
.global __vt__13NaviWalkState
__vt__13NaviWalkState:
	.incbin "baserom.dol", 0x2BE640, 0x80
.global __vt__13NaviBuryState
__vt__13NaviBuryState:
	.incbin "baserom.dol", 0x2BE6C0, 0xB8
.global __vt__14NaviStuckState
__vt__14NaviStuckState:
	.incbin "baserom.dol", 0x2BE778, 0x84
.global __vt__16NaviDemoInfState
__vt__16NaviDemoInfState:
	.incbin "baserom.dol", 0x2BE7FC, 0x84
.global __vt__17NaviDemoWaitState
__vt__17NaviDemoWaitState:
	.incbin "baserom.dol", 0x2BE880, 0x80
.global __vt__15NaviPelletState
__vt__15NaviPelletState:
	.incbin "baserom.dol", 0x2BE900, 0x54
.global __vt__9NaviState
__vt__9NaviState:
	.incbin "baserom.dol", 0x2BE954, 0x54
.global __vt__13AState$$04Navi$$1
__vt__13AState$$04Navi$$1:
	.incbin "baserom.dol", 0x2BE9A8, 0x50
.global __vt__15Receiver$$04Navi$$1
__vt__15Receiver$$04Navi$$1:
	.incbin "baserom.dol", 0x2BE9F8, 0x6C
.global __vt__16NaviStateMachine
__vt__16NaviStateMachine:
	.incbin "baserom.dol", 0x2BEA64, 0x64
.global lbl_802C1AC8
lbl_802C1AC8:
	.incbin "baserom.dol", 0x2BEAC8, 0x10
.global lbl_802C1AD8
lbl_802C1AD8:
	.incbin "baserom.dol", 0x2BEAD8, 0xC
.global lbl_802C1AE4
lbl_802C1AE4:
	.incbin "baserom.dol", 0x2BEAE4, 0xA8
.global __vt__19NaviDemoSunsetState
__vt__19NaviDemoSunsetState:
	.incbin "baserom.dol", 0x2BEB8C, 0x78
.global __vt__35StateMachine$$019NaviDemoSunsetState$$1
__vt__35StateMachine$$019NaviDemoSunsetState$$1:
	.incbin "baserom.dol", 0x2BEC04, 0x1AC
.global __vt__Q219NaviDemoSunsetState8SitState
__vt__Q219NaviDemoSunsetState8SitState:
	.incbin "baserom.dol", 0x2BEDB0, 0x8C
.global __vt__Q219NaviDemoSunsetState9WaitState
__vt__Q219NaviDemoSunsetState9WaitState:
	.incbin "baserom.dol", 0x2BEE3C, 0x90
.global __vt__Q219NaviDemoSunsetState12WhistleState
__vt__Q219NaviDemoSunsetState12WhistleState:
	.incbin "baserom.dol", 0x2BEECC, 0x8C
.global __vt__Q219NaviDemoSunsetState9LookState
__vt__Q219NaviDemoSunsetState9LookState:
	.incbin "baserom.dol", 0x2BEF58, 0x8C
.global __vt__Q219NaviDemoSunsetState7GoState
__vt__Q219NaviDemoSunsetState7GoState:
	.incbin "baserom.dol", 0x2BEFE4, 0x50
.global __vt__Q219NaviDemoSunsetState9DemoState
__vt__Q219NaviDemoSunsetState9DemoState:
	.incbin "baserom.dol", 0x2BF034, 0x50
.global __vt__29AState$$019NaviDemoSunsetState$$1
__vt__29AState$$019NaviDemoSunsetState$$1:
	.incbin "baserom.dol", 0x2BF084, 0x50
.global __vt__31Receiver$$019NaviDemoSunsetState$$1
__vt__31Receiver$$019NaviDemoSunsetState$$1:
	.incbin "baserom.dol", 0x2BF0D4, 0x6C
.global __vt__Q219NaviDemoSunsetState16DemoStateMachine
__vt__Q219NaviDemoSunsetState16DemoStateMachine:
	.incbin "baserom.dol", 0x2BF140, 0x48
.global lbl_802C2188
lbl_802C2188:
	.incbin "baserom.dol", 0x2BF188, 0x24
.global lbl_802C21AC
lbl_802C21AC:
	.incbin "baserom.dol", 0x2BF1AC, 0x1BC
.global lbl_802C2368
lbl_802C2368:
	.incbin "baserom.dol", 0x2BF368, 0x8C
.global triNames$4141
triNames$4141:
	.incbin "baserom.dol", 0x2BF3F4, 0x80
.global __vt__15GameCoreSection
__vt__15GameCoreSection:
	.incbin "baserom.dol", 0x2BF474, 0x17C
.global __vt__10BurnEffect
__vt__10BurnEffect:
	.incbin "baserom.dol", 0x2BF5F0, 0x70
.global __vt__12RippleEffect
__vt__12RippleEffect:
	.incbin "baserom.dol", 0x2BF660, 0x70
.global __vt__15FreeLightEffect
__vt__15FreeLightEffect:
	.incbin "baserom.dol", 0x2BF6D0, 0x74
.global __vt__16UfoSuikomiEffect
__vt__16UfoSuikomiEffect:
	.incbin "baserom.dol", 0x2BF744, 0xAC
.global __vt__13UfoSuckEffect
__vt__13UfoSuckEffect:
	.incbin "baserom.dol", 0x2BF7F0, 0x3C
.global __vt__15WhistleTemplate
__vt__15WhistleTemplate:
	.incbin "baserom.dol", 0x2BF82C, 0x70
.global __vt__15BombEffectLight
__vt__15BombEffectLight:
	.incbin "baserom.dol", 0x2BF89C, 0x6C
.global __vt__10BombEffect
__vt__10BombEffect:
	.incbin "baserom.dol", 0x2BF908, 0x70
.global __vt__12SimpleEffect
__vt__12SimpleEffect:
	.incbin "baserom.dol", 0x2BF978, 0x60
.global __vt__7NaviFue
__vt__7NaviFue:
	.incbin "baserom.dol", 0x2BF9D8, 0x70
.global __vt__15SmokeTreeEffect
__vt__15SmokeTreeEffect:
	.incbin "baserom.dol", 0x2BFA48, 0x70
.global __vt__15SmokeRockEffect
__vt__15SmokeRockEffect:
	.incbin "baserom.dol", 0x2BFAB8, 0x74
.global __vt__16SmokeGrassEffect
__vt__16SmokeGrassEffect:
	.incbin "baserom.dol", 0x2BFB2C, 0x70
.global __vt__15SmokeSoilEffect
__vt__15SmokeSoilEffect:
	.incbin "baserom.dol", 0x2BFB9C, 0x6C
.global __vt__11NaviWhistle
__vt__11NaviWhistle:
	.incbin "baserom.dol", 0x2BFC08, 0x6C
.global __vt__10GoalEffect
__vt__10GoalEffect:
	.incbin "baserom.dol", 0x2BFC74, 0x6C
.global __vt__11SlimeEffect
__vt__11SlimeEffect:
	.incbin "baserom.dol", 0x2BFCE0, 0xBC
.global lbl_802C2D9C
lbl_802C2D9C:
	.incbin "baserom.dol", 0x2BFD9C, 0x88
.global __vt__10Kontroller
__vt__10Kontroller:
	.incbin "baserom.dol", 0x2BFE24, 0x4C
.global lbl_802C2E70
lbl_802C2E70:
	.incbin "baserom.dol", 0x2BFE70, 0x168
.global __vt__7NaviMgr
__vt__7NaviMgr:
	.incbin "baserom.dol", 0x2BFFD8, 0xA4
.global shapeNames
shapeNames:
	.incbin "baserom.dol", 0x2C007C, 0x14
.global kindNames
kindNames:
	.incbin "baserom.dol", 0x2C0090, 0xC
.global lbl_802C309C
lbl_802C309C:
	.incbin "baserom.dol", 0x2C009C, 0xC
.global lbl_802C30A8
lbl_802C30A8:
	.incbin "baserom.dol", 0x2C00A8, 0x14
.global lbl_802C30BC
lbl_802C30BC:
	.incbin "baserom.dol", 0x2C00BC, 0x7C
.global __vt__17GenObjectMapParts
__vt__17GenObjectMapParts:
	.incbin "baserom.dol", 0x2C0138, 0x110
.global shapeFiles__8MapParts
shapeFiles__8MapParts:
	.incbin "baserom.dol", 0x2C0248, 0x10
.global lbl_802C3258
lbl_802C3258:
	.incbin "baserom.dol", 0x2C0258, 0x110
.global __vt__9MapSlider
__vt__9MapSlider:
	.incbin "baserom.dol", 0x2C0368, 0x8C
.global __vt__9MapEntity
__vt__9MapEntity:
	.incbin "baserom.dol", 0x2C03F4, 0xA8
.global __vt__8MapParts
__vt__8MapParts:
	.incbin "baserom.dol", 0x2C049C, 0x150
.global motionLabels__16PaniPikiAnimator
motionLabels__16PaniPikiAnimator:
	.incbin "baserom.dol", 0x2C05EC, 0x1B8
.global __vt__16PaniPikiAnimator
__vt__16PaniPikiAnimator:
	.incbin "baserom.dol", 0x2C07A4, 0x38
.global lbl_802C37DC
lbl_802C37DC:
	.incbin "baserom.dol", 0x2C07DC, 0xC
.global lbl_802C37E8
lbl_802C37E8:
	.incbin "baserom.dol", 0x2C07E8, 0x10
.global lbl_802C37F8
lbl_802C37F8:
	.incbin "baserom.dol", 0x2C07F8, 0x74
.global __vt__14GenObjectActor
__vt__14GenObjectActor:
	.incbin "baserom.dol", 0x2C086C, 0x3C
.global lbl_802C38A8
lbl_802C38A8:
	.incbin "baserom.dol", 0x2C08A8, 0x1C
.global lbl_802C38C4
lbl_802C38C4:
	.incbin "baserom.dol", 0x2C08C4, 0xC
.global lbl_802C38D0
lbl_802C38D0:
	.incbin "baserom.dol", 0x2C08D0, 0x3C
.global plantNames
plantNames:
	.incbin "baserom.dol", 0x2C090C, 0x30
.global lbl_802C393C
lbl_802C393C:
	.incbin "baserom.dol", 0x2C093C, 0x18
.global lbl_802C3954
lbl_802C3954:
	.incbin "baserom.dol", 0x2C0954, 0x14
.global lbl_802C3968
lbl_802C3968:
	.incbin "baserom.dol", 0x2C0968, 0xC
.global lbl_802C3974
lbl_802C3974:
	.incbin "baserom.dol", 0x2C0974, 0x10
.global lbl_802C3984
lbl_802C3984:
	.incbin "baserom.dol", 0x2C0984, 0x74
.global __vt__14GenObjectPlant
__vt__14GenObjectPlant:
	.incbin "baserom.dol", 0x2C09F8, 0x110
.global __vt__8PlantMgr
__vt__8PlantMgr:
	.incbin "baserom.dol", 0x2C0B08, 0xF8
.global __vt__Q28PlantMgr7UseNode
__vt__Q28PlantMgr7UseNode:
	.incbin "baserom.dol", 0x2C0C00, 0x88
.global __vt__Q27PlantAI9TouchInit
__vt__Q27PlantAI9TouchInit:
	.incbin "baserom.dol", 0x2C0C88, 0x2C
.global __vt__Q27PlantAI8WaitInit
__vt__Q27PlantAI8WaitInit:
	.incbin "baserom.dol", 0x2C0CB4, 0x64
.global __vt__Q27PlantAI12OpponentMove
__vt__Q27PlantAI12OpponentMove:
	.incbin "baserom.dol", 0x2C0D18, 0x98
.global __vt__7PlantAI
__vt__7PlantAI:
	.incbin "baserom.dol", 0x2C0DB0, 0xC4
.global __vt__5Plant
__vt__5Plant:
	.incbin "baserom.dol", 0x2C0E74, 0x188
.global motionLabels__17PaniPlantAnimator
motionLabels__17PaniPlantAnimator:
	.incbin "baserom.dol", 0x2C0FFC, 0x6C
.global __vt__17PaniPlantAnimator
__vt__17PaniPlantAnimator:
	.incbin "baserom.dol", 0x2C1068, 0x2C
.global lbl_802C4094
lbl_802C4094:
	.incbin "baserom.dol", 0x2C1094, 0xC
.global lbl_802C40A0
lbl_802C40A0:
	.incbin "baserom.dol", 0x2C10A0, 0xC
.global lbl_802C40AC
lbl_802C40AC:
	.incbin "baserom.dol", 0x2C10AC, 0x70
.global __vt__13GenObjectTeki
__vt__13GenObjectTeki:
	.incbin "baserom.dol", 0x2C111C, 0x8C
.global __vt__18NVibrationFunction
__vt__18NVibrationFunction:
	.incbin "baserom.dol", 0x2C11A8, 0x84
.global __vt__20NClampLinearFunction
__vt__20NClampLinearFunction:
	.incbin "baserom.dol", 0x2C122C, 0x10
.global __vt__15NLinearFunction
__vt__15NLinearFunction:
	.incbin "baserom.dol", 0x2C123C, 0x10
.global __vt__19NPolynomialFunction
__vt__19NPolynomialFunction:
	.incbin "baserom.dol", 0x2C124C, 0x10
.global __vt__9NFunction
__vt__9NFunction:
	.incbin "baserom.dol", 0x2C125C, 0x30
.global __vt__6NAlpha
__vt__6NAlpha:
	.incbin "baserom.dol", 0x2C128C, 0x34
.global __vt__8LUMatrix
__vt__8LUMatrix:
	.incbin "baserom.dol", 0x2C12C0, 0x28
.global __vt__12NUpperMatrix
__vt__12NUpperMatrix:
	.incbin "baserom.dol", 0x2C12E8, 0x28
.global __vt__12NLowerMatrix
__vt__12NLowerMatrix:
	.incbin "baserom.dol", 0x2C1310, 0xC
.global __vt__14NSpecialMatrix
__vt__14NSpecialMatrix:
	.incbin "baserom.dol", 0x2C131C, 0x18
.global __vt__10NPosture3D
__vt__10NPosture3D:
	.incbin "baserom.dol", 0x2C1334, 0x18
.global __vt__10NPosture2D
__vt__10NPosture2D:
	.incbin "baserom.dol", 0x2C134C, 0xC
.global __vt__6NPlane
__vt__6NPlane:
	.incbin "baserom.dol", 0x2C1358, 0x10
.global __vt__5NLine
__vt__5NLine:
	.incbin "baserom.dol", 0x2C1368, 0x10
.global lbl_802C4378
lbl_802C4378:
	.incbin "baserom.dol", 0x2C1378, 0x1C
.global AtanTable
AtanTable:
	.incbin "baserom.dol", 0x2C1394, 0x820
.global __vt__5NHeap
__vt__5NHeap:
	.incbin "baserom.dol", 0x2C1BB4, 0x20
.global __vt__14NArray$$05NHeap$$1
__vt__14NArray$$05NHeap$$1:
	.incbin "baserom.dol", 0x2C1BD4, 0x40
.global __vt__5NNode
__vt__5NNode:
	.incbin "baserom.dol", 0x2C1C14, 0x30
.global __vt__14NArray$$05NNode$$1
__vt__14NArray$$05NNode$$1:
	.incbin "baserom.dol", 0x2C1C44, 0xB0
.global keyNames__12PaniAnimator
keyNames__12PaniAnimator:
	.incbin "baserom.dol", 0x2C1CF4, 0x40
.global __vt__12PaniAnimator
__vt__12PaniAnimator:
	.incbin "baserom.dol", 0x2C1D34, 0x68
.global motionLabels__16PaniTekiAnimator
motionLabels__16PaniTekiAnimator:
	.incbin "baserom.dol", 0x2C1D9C, 0x8C
.global __vt__16PaniTekiAnimator
__vt__16PaniTekiAnimator:
	.incbin "baserom.dol", 0x2C1E28, 0x20
.global lbl_802C4E48
lbl_802C4E48:
	.incbin "baserom.dol", 0x2C1E48, 0xC8
.global lbl_802C4F10
lbl_802C4F10:
	.incbin "baserom.dol", 0x2C1F10, 0x90
.global __vt__15PaniTestSection
__vt__15PaniTestSection:
	.incbin "baserom.dol", 0x2C1FA0, 0x6C
.global __vt__12PaniTestNode
__vt__12PaniTestNode:
	.incbin "baserom.dol", 0x2C200C, 0xA4
.global __vt__19ParaMultiParameters
__vt__19ParaMultiParameters:
	.incbin "baserom.dol", 0x2C20B0, 0x48
.global __vt__15ParaParametersF
__vt__15ParaParametersF:
	.incbin "baserom.dol", 0x2C20F8, 0x14
.global __vt__17ParaParameters$$0f$$1
__vt__17ParaParameters$$0f$$1:
	.incbin "baserom.dol", 0x2C210C, 0x44
.global __vt__15ParaParametersI
__vt__15ParaParametersI:
	.incbin "baserom.dol", 0x2C2150, 0x14
.global __vt__17ParaParameters$$0i$$1
__vt__17ParaParameters$$0i$$1:
	.incbin "baserom.dol", 0x2C2164, 0x30
.global lbl_802C5194
lbl_802C5194:
	.incbin "baserom.dol", 0x2C2194, 0x54
.global __vt__10PcamCamera
__vt__10PcamCamera:
	.incbin "baserom.dol", 0x2C21E8, 0x20
.global __vt__17NArray$$08Creature$$1
__vt__17NArray$$08Creature$$1:
	.incbin "baserom.dol", 0x2C2208, 0x6C
.global lbl_802C5274
lbl_802C5274:
	.incbin "baserom.dol", 0x2C2274, 0x5C
.global __vt__17PcamCameraManager
__vt__17PcamCameraManager:
	.incbin "baserom.dol", 0x2C22D0, 0xC0
.global __vt__22PcamSideVibrationEvent
__vt__22PcamSideVibrationEvent:
	.incbin "baserom.dol", 0x2C2390, 0x7C
.global __vt__19PcamRandomMoveEvent
__vt__19PcamRandomMoveEvent:
	.incbin "baserom.dol", 0x2C240C, 0x90
.global __vt__15PcamDamageEvent
__vt__15PcamDamageEvent:
	.incbin "baserom.dol", 0x2C249C, 0x6C
.global __vt__18PcamVibrationEvent
__vt__18PcamVibrationEvent:
	.incbin "baserom.dol", 0x2C2508, 0x94
.global __vt__22PcamLongVibrationEvent
__vt__22PcamLongVibrationEvent:
	.incbin "baserom.dol", 0x2C259C, 0x3C
.global lbl_802C55D8
lbl_802C55D8:
	.incbin "baserom.dol", 0x2C25D8, 0x558
.global __vt__20PcamCameraParameters
__vt__20PcamCameraParameters:
	.incbin "baserom.dol", 0x2C2B30, 0xB0
.global __vt__19PeveClampVector3fIO
__vt__19PeveClampVector3fIO:
	.incbin "baserom.dol", 0x2C2BE0, 0x10
.global __vt__16NVector3fIOClass
__vt__16NVector3fIOClass:
	.incbin "baserom.dol", 0x2C2BF0, 0x34
.global __vt__22PeveCreaturePositionIO
__vt__22PeveCreaturePositionIO:
	.incbin "baserom.dol", 0x2C2C24, 0x40
.global __vt__19PeveCameraPostureIO
__vt__19PeveCameraPostureIO:
	.incbin "baserom.dol", 0x2C2C64, 0x10
.global __vt__12NPosture3DIO
__vt__12NPosture3DIO:
	.incbin "baserom.dol", 0x2C2C74, 0x34
.global __vt__22PeveCameraWatchpointIO
__vt__22PeveCameraWatchpointIO:
	.incbin "baserom.dol", 0x2C2CA8, 0x34
.global __vt__21PeveCameraViewpointIO
__vt__21PeveCameraViewpointIO:
	.incbin "baserom.dol", 0x2C2CDC, 0x10
.global __vt__11NVector3fIO
__vt__11NVector3fIO:
	.incbin "baserom.dol", 0x2C2CEC, 0x4C
.global __vt__15PeveSerialEvent
__vt__15PeveSerialEvent:
	.incbin "baserom.dol", 0x2C2D38, 0x64
.global __vt__17PeveParallelEvent
__vt__17PeveParallelEvent:
	.incbin "baserom.dol", 0x2C2D9C, 0x3C
.global __vt__9PeveEvent
__vt__9PeveEvent:
	.incbin "baserom.dol", 0x2C2DD8, 0x4C
.global __vt__13PeveCondition
__vt__13PeveCondition:
	.incbin "baserom.dol", 0x2C2E24, 0x9C
.global __vt__24PeveComparisonYCondition
__vt__24PeveComparisonYCondition:
	.incbin "baserom.dol", 0x2C2EC0, 0x40
.global __vt__21PeveDistanceCondition
__vt__21PeveDistanceCondition:
	.incbin "baserom.dol", 0x2C2F00, 0x34
.global __vt__17PeveTimeCondition
__vt__17PeveTimeCondition:
	.incbin "baserom.dol", 0x2C2F34, 0x38
.global __vt__23PeveDependenceCondition
__vt__23PeveDependenceCondition:
	.incbin "baserom.dol", 0x2C2F6C, 0x14
.global __vt__20PeveBooleanCondition
__vt__20PeveBooleanCondition:
	.incbin "baserom.dol", 0x2C2F80, 0x84
.global __vt__18PeveVibrationEvent
__vt__18PeveVibrationEvent:
	.incbin "baserom.dol", 0x2C3004, 0x78
.global __vt__13PeveMoveEvent
__vt__13PeveMoveEvent:
	.incbin "baserom.dol", 0x2C307C, 0x68
.global __vt__22PeveInterpolationEvent
__vt__22PeveInterpolationEvent:
	.incbin "baserom.dol", 0x2C30E4, 0xB4
.global __vt__22PeveHomingPostureEvent
__vt__22PeveHomingPostureEvent:
	.incbin "baserom.dol", 0x2C3198, 0x68
.global __vt__23PeveHomingPositionEvent
__vt__23PeveHomingPositionEvent:
	.incbin "baserom.dol", 0x2C3200, 0x68
.global __vt__22PeveFunctionCurveEvent
__vt__22PeveFunctionCurveEvent:
	.incbin "baserom.dol", 0x2C3268, 0x74
.global __vt__24PeveCircleMoveWatchEvent
__vt__24PeveCircleMoveWatchEvent:
	.incbin "baserom.dol", 0x2C32DC, 0x64
.global __vt__19PeveCircleMoveEvent
__vt__19PeveCircleMoveEvent:
	.incbin "baserom.dol", 0x2C3340, 0x6C
.global __vt__26PeveHorizontalSinWaveEvent
__vt__26PeveHorizontalSinWaveEvent:
	.incbin "baserom.dol", 0x2C33AC, 0xE4
.global __vt__17PeveParabolaEvent
__vt__17PeveParabolaEvent:
	.incbin "baserom.dol", 0x2C3490, 0x3C
.global __vt__21PeveAccelerationEvent
__vt__21PeveAccelerationEvent:
	.incbin "baserom.dol", 0x2C34CC, 0x60
.global __vt__13PeveWaitEvent
__vt__13PeveWaitEvent:
	.incbin "baserom.dol", 0x2C352C, 0x64
.global __vt__11TaiStrategy
__vt__11TaiStrategy:
	.incbin "baserom.dol", 0x2C3590, 0x34
.global __vt__8TaiState
__vt__8TaiState:
	.incbin "baserom.dol", 0x2C35C4, 0x40
.global __vt__15TaiSerialAction
__vt__15TaiSerialAction:
	.incbin "baserom.dol", 0x2C3604, 0x1C
.global __vt__9TaiAction
__vt__9TaiAction:
	.incbin "baserom.dol", 0x2C3620, 0xA0
.global __vt__22TaiFlickingUpperAction
__vt__22TaiFlickingUpperAction:
	.incbin "baserom.dol", 0x2C36C0, 0x44
.global __vt__17TaiFlickingAction
__vt__17TaiFlickingAction:
	.incbin "baserom.dol", 0x2C3704, 0x40
.global __vt__20TaiTargetStickAction
__vt__20TaiTargetStickAction:
	.incbin "baserom.dol", 0x2C3744, 0x38
.global __vt__14TaiFlickAction
__vt__14TaiFlickAction:
	.incbin "baserom.dol", 0x2C377C, 0x3C
.global __vt__16TaiBangingAction
__vt__16TaiBangingAction:
	.incbin "baserom.dol", 0x2C37B8, 0xA4
.global __vt__16TekiAndCondition
__vt__16TekiAndCondition:
	.incbin "baserom.dol", 0x2C385C, 0x34
.global __vt__16TekiNotCondition
__vt__16TekiNotCondition:
	.incbin "baserom.dol", 0x2C3890, 0x38
.global __vt__28TaiAnimationSwallowingAction
__vt__28TaiAnimationSwallowingAction:
	.incbin "baserom.dol", 0x2C38C8, 0x40
.global __vt__23TaiAttackablePikiAction
__vt__23TaiAttackablePikiAction:
	.incbin "baserom.dol", 0x2C3908, 0x40
.global __vt__23TaiAttackableNaviAction
__vt__23TaiAttackableNaviAction:
	.incbin "baserom.dol", 0x2C3948, 0x1C
.global __vt__13TekiCondition
__vt__13TekiCondition:
	.incbin "baserom.dol", 0x2C3964, 0x40
.global __vt__27TaiAttackableNaviPikiAction
__vt__27TaiAttackableNaviPikiAction:
	.incbin "baserom.dol", 0x2C39A4, 0x74
.global __vt__26TaiNaviWatchResultOnAction
__vt__26TaiNaviWatchResultOnAction:
	.incbin "baserom.dol", 0x2C3A18, 0x48
.global __vt__30TaiTypeNaviWatchResultOnAction
__vt__30TaiTypeNaviWatchResultOnAction:
	.incbin "baserom.dol", 0x2C3A60, 0x3C
.global __vt__18TaiStopSoundAction
__vt__18TaiStopSoundAction:
	.incbin "baserom.dol", 0x2C3A9C, 0x3C
.global __vt__18TaiPlaySoundAction
__vt__18TaiPlaySoundAction:
	.incbin "baserom.dol", 0x2C3AD8, 0x3C
.global __vt__18TaiSetOptionAction
__vt__18TaiSetOptionAction:
	.incbin "baserom.dol", 0x2C3B14, 0x40
.global __vt__20TaiActionStateAction
__vt__20TaiActionStateAction:
	.incbin "baserom.dol", 0x2C3B54, 0x1C
.global lbl_802C6B70
lbl_802C6B70:
	.incbin "baserom.dol", 0x2C3B70, 0xE8
.global __vt__24TaiChappyLegEffectAction
__vt__24TaiChappyLegEffectAction:
	.incbin "baserom.dol", 0x2C3C58, 0x6C
.global __vt__22TaiChappySmashedAction
__vt__22TaiChappySmashedAction:
	.incbin "baserom.dol", 0x2C3CC4, 0x9C
.global __vt__15TekiOrCondition
__vt__15TekiOrCondition:
	.incbin "baserom.dol", 0x2C3D60, 0x44
.global __vt__18TaiChappyCryAction
__vt__18TaiChappyCryAction:
	.incbin "baserom.dol", 0x2C3DA4, 0x38
.global __vt__13TaiOnceAction
__vt__13TaiOnceAction:
	.incbin "baserom.dol", 0x2C3DDC, 0x38
.global __vt__12TaiAndAction
__vt__12TaiAndAction:
	.incbin "baserom.dol", 0x2C3E14, 0x88
.global __vt__17TaiChappyStrategy
__vt__17TaiChappyStrategy:
	.incbin "baserom.dol", 0x2C3E9C, 0xBC
.global __vt__20TaiCatfishParameters
__vt__20TaiCatfishParameters:
	.incbin "baserom.dol", 0x2C3F58, 0x70
.global __vt__24TaiBlackChappyParameters
__vt__24TaiBlackChappyParameters:
	.incbin "baserom.dol", 0x2C3FC8, 0x68
.global __vt__19TaiChappyParameters
__vt__19TaiChappyParameters:
	.incbin "baserom.dol", 0x2C4030, 0x30
.global lbl_802C7060
lbl_802C7060:
	.incbin "baserom.dol", 0x2C4060, 0x14C
.global __vt__17TaiHollecStrategy
__vt__17TaiHollecStrategy:
	.incbin "baserom.dol", 0x2C41AC, 0xB8
.global __vt__19TaiHollecParameters
__vt__19TaiHollecParameters:
	.incbin "baserom.dol", 0x2C4264, 0xC0
.global __vt__24TaiCollecLegEffectAction
__vt__24TaiCollecLegEffectAction:
	.incbin "baserom.dol", 0x2C4324, 0x44
.global __vt__21TaiCollecGetOutAction
__vt__21TaiCollecGetOutAction:
	.incbin "baserom.dol", 0x2C4368, 0x40
.global __vt__22TaiCollecFallingAction
__vt__22TaiCollecFallingAction:
	.incbin "baserom.dol", 0x2C43A8, 0x44
.global __vt__26TaiCollecDeadFallingAction
__vt__26TaiCollecDeadFallingAction:
	.incbin "baserom.dol", 0x2C43EC, 0x54
.global __vt__40TaiCollecPelletFinishContainerizedAction
__vt__40TaiCollecPelletFinishContainerizedAction:
	.incbin "baserom.dol", 0x2C4440, 0x50
.global __vt__39TaiCollecPelletStartContainerizedAction
__vt__39TaiCollecPelletStartContainerizedAction:
	.incbin "baserom.dol", 0x2C4490, 0x44
.global __vt__25TaiCollecRoundCarryAction
__vt__25TaiCollecRoundCarryAction:
	.incbin "baserom.dol", 0x2C44D4, 0x48
.global __vt__30TaiCollecRouteImpassableAction
__vt__30TaiCollecRouteImpassableAction:
	.incbin "baserom.dol", 0x2C451C, 0xA4
.global __vt__29TaiCollecCarryingToNestAction
__vt__29TaiCollecCarryingToNestAction:
	.incbin "baserom.dol", 0x2C45C0, 0x84
.global __vt__28TaiCollecPuttingPelletAction
__vt__28TaiCollecPuttingPelletAction:
	.incbin "baserom.dol", 0x2C4644, 0x3C
.global __vt__18TaiCollecPutAction
__vt__18TaiCollecPutAction:
	.incbin "baserom.dol", 0x2C4680, 0x48
.global __vt__29TaiCollecDefeatCarryingAction
__vt__29TaiCollecDefeatCarryingAction:
	.incbin "baserom.dol", 0x2C46C8, 0x44
.global __vt__26TaiCollecWinCarryingAction
__vt__26TaiCollecWinCarryingAction:
	.incbin "baserom.dol", 0x2C470C, 0x44
.global __vt__27TaiCollecBeingDraggedAction
__vt__27TaiCollecBeingDraggedAction:
	.incbin "baserom.dol", 0x2C4750, 0x40
.global __vt__23TaiCollecCarryingAction
__vt__23TaiCollecCarryingAction:
	.incbin "baserom.dol", 0x2C4790, 0x40
.global __vt__23TaiCollecCatchingAction
__vt__23TaiCollecCatchingAction:
	.incbin "baserom.dol", 0x2C47D0, 0x44
.global __vt__25TaiCollecHoldPelletAction
__vt__25TaiCollecHoldPelletAction:
	.incbin "baserom.dol", 0x2C4814, 0x4C
.global __vt__32TaiCollecPelletDisappearedAction
__vt__32TaiCollecPelletDisappearedAction:
	.incbin "baserom.dol", 0x2C4860, 0x44
.global __vt__25TaiCollecPelletLostAction
__vt__25TaiCollecPelletLostAction:
	.incbin "baserom.dol", 0x2C48A4, 0x78
.global __vt__43TaiCollecVisibleHeightPelletLostTimerAction
__vt__43TaiCollecVisibleHeightPelletLostTimerAction:
	.incbin "baserom.dol", 0x2C491C, 0x50
.global __vt__38TaiCollecVisibleHeightPelletLostAction
__vt__38TaiCollecVisibleHeightPelletLostAction:
	.incbin "baserom.dol", 0x2C496C, 0xEC
.global __vt__27TaiCollecTargetPelletAction
__vt__27TaiCollecTargetPelletAction:
	.incbin "baserom.dol", 0x2C4A58, 0x48
.global __vt__28TaiCollecLetGoOfPelletAction
__vt__28TaiCollecLetGoOfPelletAction:
	.incbin "baserom.dol", 0x2C4AA0, 0x44
.global __vt__25TaiCollecImpassableAction
__vt__25TaiCollecImpassableAction:
	.incbin "baserom.dol", 0x2C4AE4, 0x50
.global __vt__31TekiCollecTargetPelletCondition
__vt__31TekiCollecTargetPelletCondition:
	.incbin "baserom.dol", 0x2C4B34, 0x34
.global __vt__17TaiCollecStrategy
__vt__17TaiCollecStrategy:
	.incbin "baserom.dol", 0x2C4B68, 0x48
.global __vt__19TaiDependenceAction
__vt__19TaiDependenceAction:
	.incbin "baserom.dol", 0x2C4BB0, 0x70
.global __vt__19TaiCollecParameters
__vt__19TaiCollecParameters:
	.incbin "baserom.dol", 0x2C4C20, 0xC0
.global __vt__26TaiTekiTypeCollisionAction
__vt__26TaiTekiTypeCollisionAction:
	.incbin "baserom.dol", 0x2C4CE0, 0x48
.global __vt__22TaiNaviCollisionAction
__vt__22TaiNaviCollisionAction:
	.incbin "baserom.dol", 0x2C4D28, 0x48
.global __vt__22TaiPikiCollisionAction
__vt__22TaiPikiCollisionAction:
	.incbin "baserom.dol", 0x2C4D70, 0x1C
.global __vt__26TaiCreatureCollisionAction
__vt__26TaiCreatureCollisionAction:
	.incbin "baserom.dol", 0x2C4D8C, 0x40
.global __vt__22TaiWallCollisionAction
__vt__22TaiWallCollisionAction:
	.incbin "baserom.dol", 0x2C4DCC, 0x44
.global __vt__24TaiGroundCollisionAction
__vt__24TaiGroundCollisionAction:
	.incbin "baserom.dol", 0x2C4E10, 0x38
.global __vt__15TaiBounceAction
__vt__15TaiBounceAction:
	.incbin "baserom.dol", 0x2C4E48, 0xA4
.global __vt__20TaiJointEffectAction
__vt__20TaiJointEffectAction:
	.incbin "baserom.dol", 0x2C4EEC, 0x6C
.global __vt__33TaiStopGenParticleGeneratorAction
__vt__33TaiStopGenParticleGeneratorAction:
	.incbin "baserom.dol", 0x2C4F58, 0x4C
.global __vt__34TaiStartGenParticleGeneratorAction
__vt__34TaiStartGenParticleGeneratorAction:
	.incbin "baserom.dol", 0x2C4FA4, 0x38
.global __vt__15TaiEffectAction
__vt__15TaiEffectAction:
	.incbin "baserom.dol", 0x2C4FDC, 0x38
.global lbl_802C8014
lbl_802C8014:
	.incbin "baserom.dol", 0x2C5014, 0x40
.global __vt__23TaiIwagenShootingAction
__vt__23TaiIwagenShootingAction:
	.incbin "baserom.dol", 0x2C5054, 0x6C
.global __vt__17TaiIwagenStrategy
__vt__17TaiIwagenStrategy:
	.incbin "baserom.dol", 0x2C50C0, 0xB8
.global __vt__19TaiIwagenParameters
__vt__19TaiIwagenParameters:
	.incbin "baserom.dol", 0x2C5178, 0x54
.global __vt__22TaiIwagonRollingAction
__vt__22TaiIwagonRollingAction:
	.incbin "baserom.dol", 0x2C51CC, 0x44
.global __vt__25TaiIwagonDustEffectAction
__vt__25TaiIwagonDustEffectAction:
	.incbin "baserom.dol", 0x2C5210, 0x44
.global __vt__17TaiIwagonStrategy
__vt__17TaiIwagonStrategy:
	.incbin "baserom.dol", 0x2C5254, 0x7C
.global __vt__19TaiIwagonParameters
__vt__19TaiIwagonParameters:
	.incbin "baserom.dol", 0x2C52D0, 0x90
.global __vt__26TaiHasStickersOnBodyAction
__vt__26TaiHasStickersOnBodyAction:
	.incbin "baserom.dol", 0x2C5360, 0x44
.global __vt__27TaiHasStickersInMouthAction
__vt__27TaiHasStickersInMouthAction:
	.incbin "baserom.dol", 0x2C53A4, 0xA0
.global __vt__26TaiTargetVisibleNaviAction
__vt__26TaiTargetVisibleNaviAction:
	.incbin "baserom.dol", 0x2C5444, 0x60
.global __vt__30TaiTargetVisibleNaviPikiAction
__vt__30TaiTargetVisibleNaviPikiAction:
	.incbin "baserom.dol", 0x2C54A4, 0x44
.global __vt__24TaiInsideTerritoryAction
__vt__24TaiInsideTerritoryAction:
	.incbin "baserom.dol", 0x2C54E8, 0x44
.global __vt__25TaiOutsideTerritoryAction
__vt__25TaiOutsideTerritoryAction:
	.incbin "baserom.dol", 0x2C552C, 0x3C
.global __vt__19TaiTargetLostAction
__vt__19TaiTargetLostAction:
	.incbin "baserom.dol", 0x2C5568, 0x40
.global __vt__23TaiSeparateTargetAction
__vt__23TaiSeparateTargetAction:
	.incbin "baserom.dol", 0x2C55A8, 0x40
.global __vt__22TaiContactTargetAction
__vt__22TaiContactTargetAction:
	.incbin "baserom.dol", 0x2C55E8, 0x40
.global __vt__22TaiVisibleTargetAction
__vt__22TaiVisibleTargetAction:
	.incbin "baserom.dol", 0x2C5628, 0x20
.global lbl_802C8648
lbl_802C8648:
	.incbin "baserom.dol", 0x2C5648, 0x1A4
.global __vt__24TaiKinokoLegEffectAction
__vt__24TaiKinokoLegEffectAction:
	.incbin "baserom.dol", 0x2C57EC, 0x50
.global __vt__35TaiKinokoTerritoryRunningAwayAction
__vt__35TaiKinokoTerritoryRunningAwayAction:
	.incbin "baserom.dol", 0x2C583C, 0xF8
.global __vt__32TaiKinokoDischargingSporesAction
__vt__32TaiKinokoDischargingSporesAction:
	.incbin "baserom.dol", 0x2C5934, 0x48
.global __vt__29TaiKinokoChargingSporesAction
__vt__29TaiKinokoChargingSporesAction:
	.incbin "baserom.dol", 0x2C597C, 0x44
.global __vt__26TaiKinokoTurningOverAction
__vt__26TaiKinokoTurningOverAction:
	.incbin "baserom.dol", 0x2C59C0, 0x6C
.global __vt__17TaiKinokoStrategy
__vt__17TaiKinokoStrategy:
	.incbin "baserom.dol", 0x2C5A2C, 0x44
.global __vt__12TaiNotAction
__vt__12TaiNotAction:
	.incbin "baserom.dol", 0x2C5A70, 0x100
.global __vt__19TaiKinokoParameters
__vt__19TaiKinokoParameters:
	.incbin "baserom.dol", 0x2C5B70, 0x8C
.global __vt__23TaiKeySendMessageAction
__vt__23TaiKeySendMessageAction:
	.incbin "baserom.dol", 0x2C5BFC, 0x40
.global __vt__20TaiSendMessageAction
__vt__20TaiSendMessageAction:
	.incbin "baserom.dol", 0x2C5C3C, 0x1C
.global lbl_802C8C58
lbl_802C8C58:
	.incbin "baserom.dol", 0x2C5C58, 0x184
.global __vt__26TaiMizinkoFlyingAwayAction
__vt__26TaiMizinkoFlyingAwayAction:
	.incbin "baserom.dol", 0x2C5DDC, 0x40
.global __vt__23TaiMizinkoWaitingAction
__vt__23TaiMizinkoWaitingAction:
	.incbin "baserom.dol", 0x2C5E1C, 0x44
.global __vt__25TaiMizinkoDropWaterAction
__vt__25TaiMizinkoDropWaterAction:
	.incbin "baserom.dol", 0x2C5E60, 0x40
.global __vt__22TaiMizinkoComingAction
__vt__22TaiMizinkoComingAction:
	.incbin "baserom.dol", 0x2C5EA0, 0x40
.global __vt__21TaiMizinkoGoingAction
__vt__21TaiMizinkoGoingAction:
	.incbin "baserom.dol", 0x2C5EE0, 0x40
.global __vt__22TaiMizinkoFadingAction
__vt__22TaiMizinkoFadingAction:
	.incbin "baserom.dol", 0x2C5F20, 0x68
.global __vt__27TaiMizinkoMovingTimerAction
__vt__27TaiMizinkoMovingTimerAction:
	.incbin "baserom.dol", 0x2C5F88, 0x4C
.global __vt__24TaiMizinkoCryTimerAction
__vt__24TaiMizinkoCryTimerAction:
	.incbin "baserom.dol", 0x2C5FD4, 0x6C
.global __vt__18TaiMizinkoStrategy
__vt__18TaiMizinkoStrategy:
	.incbin "baserom.dol", 0x2C6040, 0xBC
.global __vt__20TaiMizinkoParameters
__vt__20TaiMizinkoParameters:
	.incbin "baserom.dol", 0x2C60FC, 0x5C
.global __vt__28TaiMizigenNaviApprouchAction
__vt__28TaiMizigenNaviApprouchAction:
	.incbin "baserom.dol", 0x2C6158, 0x44
.global __vt__26TaiMizigenGeneratingAction
__vt__26TaiMizigenGeneratingAction:
	.incbin "baserom.dol", 0x2C619C, 0x44
.global __vt__18TaiMizigenStrategy
__vt__18TaiMizigenStrategy:
	.incbin "baserom.dol", 0x2C61E0, 0x80
.global __vt__20TaiMizigenParameters
__vt__20TaiMizigenParameters:
	.incbin "baserom.dol", 0x2C6260, 0x98
.global __vt__34TaiRandomSetAnimationCounterAction
__vt__34TaiRandomSetAnimationCounterAction:
	.incbin "baserom.dol", 0x2C62F8, 0x40
.global __vt__23TaiSetFrameMotionAction
__vt__23TaiSetFrameMotionAction:
	.incbin "baserom.dol", 0x2C6338, 0x44
.global __vt__27TaiFinishStoppingMoveAction
__vt__27TaiFinishStoppingMoveAction:
	.incbin "baserom.dol", 0x2C637C, 0x40
.global __vt__21TaiStoppingMoveAction
__vt__21TaiStoppingMoveAction:
	.incbin "baserom.dol", 0x2C63BC, 0x44
.global __vt__27TaiOutsideKeyStopMoveAction
__vt__27TaiOutsideKeyStopMoveAction:
	.incbin "baserom.dol", 0x2C6400, 0x64
.global __vt__21TaiSwitchMotionAction
__vt__21TaiSwitchMotionAction:
	.incbin "baserom.dol", 0x2C6464, 0x3C
.global __vt__18TaiCountLoopAction
__vt__18TaiCountLoopAction:
	.incbin "baserom.dol", 0x2C64A0, 0x40
.global __vt__21TaiAnimationKeyAction
__vt__21TaiAnimationKeyAction:
	.incbin "baserom.dol", 0x2C64E0, 0x48
.global __vt__21TaiFinishMotionAction
__vt__21TaiFinishMotionAction:
	.incbin "baserom.dol", 0x2C6528, 0x4C
.global __vt__25TaiContinuousMotionAction
__vt__25TaiContinuousMotionAction:
	.incbin "baserom.dol", 0x2C6574, 0x20
.global __vt__15TaiMotionAction
__vt__15TaiMotionAction:
	.incbin "baserom.dol", 0x2C6594, 0x7C
.global __vt__33TaiHeadOnCollisionAvoidanceAction
__vt__33TaiHeadOnCollisionAvoidanceAction:
	.incbin "baserom.dol", 0x2C6610, 0x3C
.global __vt__19TaiTargetNestAction
__vt__19TaiTargetNestAction:
	.incbin "baserom.dol", 0x2C664C, 0x4C
.global __vt__32TaiWatchOffTerritoryCenterAction
__vt__32TaiWatchOffTerritoryCenterAction:
	.incbin "baserom.dol", 0x2C6698, 0x9C
.global __vt__20TaiRunningAwayAction
__vt__20TaiRunningAwayAction:
	.incbin "baserom.dol", 0x2C6734, 0x64
.global __vt__37TaiRunningAwayToTargetDirectionAction
__vt__37TaiRunningAwayToTargetDirectionAction:
	.incbin "baserom.dol", 0x2C6798, 0x40
.global __vt__17TaiRotatingAction
__vt__17TaiRotatingAction:
	.incbin "baserom.dol", 0x2C67D8, 0x5C
.global __vt__32TaiTurningToTargetPositionAction
__vt__32TaiTurningToTargetPositionAction:
	.incbin "baserom.dol", 0x2C6834, 0x48
.global __vt__24TaiOutOfTraceAngleAction
__vt__24TaiOutOfTraceAngleAction:
	.incbin "baserom.dol", 0x2C687C, 0x50
.global __vt__21TaiTraceTurningAction
__vt__21TaiTraceTurningAction:
	.incbin "baserom.dol", 0x2C68CC, 0x54
.global __vt__20TaiTurningAwayAction
__vt__20TaiTurningAwayAction:
	.incbin "baserom.dol", 0x2C6920, 0x90
.global __vt__16TaiTurningAction
__vt__16TaiTurningAction:
	.incbin "baserom.dol", 0x2C69B0, 0x40
.global __vt__19TaiDirectTurnAction
__vt__19TaiDirectTurnAction:
	.incbin "baserom.dol", 0x2C69F0, 0x4C
.global __vt__18TaiGoingHomeAction
__vt__18TaiGoingHomeAction:
	.incbin "baserom.dol", 0x2C6A3C, 0x50
.global __vt__16TaiTracingAction
__vt__16TaiTracingAction:
	.incbin "baserom.dol", 0x2C6A8C, 0x5C
.global __vt__29TaiRandomWanderingRouteAction
__vt__29TaiRandomWanderingRouteAction:
	.incbin "baserom.dol", 0x2C6AE8, 0x40
.global __vt__19TaiImpassableAction
__vt__19TaiImpassableAction:
	.incbin "baserom.dol", 0x2C6B28, 0x44
.global __vt__26TaiClampMinVelocityYAction
__vt__26TaiClampMinVelocityYAction:
	.incbin "baserom.dol", 0x2C6B6C, 0x40
.global __vt__23TaiClampMinHeightAction
__vt__23TaiClampMinHeightAction:
	.incbin "baserom.dol", 0x2C6BAC, 0x40
.global __vt__23TaiClampMaxHeightAction
__vt__23TaiClampMaxHeightAction:
	.incbin "baserom.dol", 0x2C6BEC, 0x44
.global __vt__26TaiHorizontalSinWaveAction
__vt__26TaiHorizontalSinWaveAction:
	.incbin "baserom.dol", 0x2C6C30, 0x3C
.global __vt__19TaiCircleMoveAction
__vt__19TaiCircleMoveAction:
	.incbin "baserom.dol", 0x2C6C6C, 0x3C
.global __vt__17TaiParabolaAction
__vt__17TaiParabolaAction:
	.incbin "baserom.dol", 0x2C6CA8, 0x40
.global __vt__21TaiAccelerationAction
__vt__21TaiAccelerationAction:
	.incbin "baserom.dol", 0x2C6CE8, 0x44
.global __vt__24TaiMakingNextDriveAction
__vt__24TaiMakingNextDriveAction:
	.incbin "baserom.dol", 0x2C6D2C, 0x44
.global __vt__27TaiMakingNextVelocityAction
__vt__27TaiMakingNextVelocityAction:
	.incbin "baserom.dol", 0x2C6D70, 0x4C
.global __vt__34TaiMakeAccelerationDirectionAction
__vt__34TaiMakeAccelerationDirectionAction:
	.incbin "baserom.dol", 0x2C6DBC, 0x48
.global __vt__30TaiMakeVelocityDirectionAction
__vt__30TaiMakeVelocityDirectionAction:
	.incbin "baserom.dol", 0x2C6E04, 0x40
.global __vt__21TaiFinishFlyingAction
__vt__21TaiFinishFlyingAction:
	.incbin "baserom.dol", 0x2C6E44, 0x40
.global __vt__20TaiStartFlyingAction
__vt__20TaiStartFlyingAction:
	.incbin "baserom.dol", 0x2C6E84, 0x3C
.global __vt__17TaiStopMoveAction
__vt__17TaiStopMoveAction:
	.incbin "baserom.dol", 0x2C6EC0, 0x44
.global __vt__25TaiMoveNestPositionAction
__vt__25TaiMoveNestPositionAction:
	.incbin "baserom.dol", 0x2C6F04, 0x1C
.global lbl_802C9F20
lbl_802C9F20:
	.incbin "baserom.dol", 0x2C6F20, 0x1A4
.global __vt__33TaiNapkidStartDroppingWaterAction
__vt__33TaiNapkidStartDroppingWaterAction:
	.incbin "baserom.dol", 0x2C70C4, 0x4C
.global __vt__33TaiNapkidFallingWaterEffectAction
__vt__33TaiNapkidFallingWaterEffectAction:
	.incbin "baserom.dol", 0x2C7110, 0x44
.global __vt__27TaiNapkidShockFallingAction
__vt__27TaiNapkidShockFallingAction:
	.incbin "baserom.dol", 0x2C7154, 0x40
.global __vt__22TaiNapkidFallingAction
__vt__22TaiNapkidFallingAction:
	.incbin "baserom.dol", 0x2C7194, 0x40
.global __vt__20TaiNapkidFlickAction
__vt__20TaiNapkidFlickAction:
	.incbin "baserom.dol", 0x2C71D4, 0x44
.global __vt__27TaiNapkidThrowingPikiAction
__vt__27TaiNapkidThrowingPikiAction:
	.incbin "baserom.dol", 0x2C7218, 0x48
.global __vt__30TaiNapkidRisingAscendingAction
__vt__30TaiNapkidRisingAscendingAction:
	.incbin "baserom.dol", 0x2C7260, 0x4C
.global __vt__33TaiNapkidTakingOffAscendingAction
__vt__33TaiNapkidTakingOffAscendingAction:
	.incbin "baserom.dol", 0x2C72AC, 0x48
.global __vt__29TaiNapkidCatchAscendingAction
__vt__29TaiNapkidCatchAscendingAction:
	.incbin "baserom.dol", 0x2C72F4, 0x44
.global __vt__26TaiNapkidCatchFlyingAction
__vt__26TaiNapkidCatchFlyingAction:
	.incbin "baserom.dol", 0x2C7338, 0x44
.global __vt__27TaiNapkidCatchTracingAction
__vt__27TaiNapkidCatchTracingAction:
	.incbin "baserom.dol", 0x2C737C, 0x48
.global __vt__30TaiNapkidCatchDescendingAction
__vt__30TaiNapkidCatchDescendingAction:
	.incbin "baserom.dol", 0x2C73C4, 0x108
.global __vt__23TaiNapkidCatchingAction
__vt__23TaiNapkidCatchingAction:
	.incbin "baserom.dol", 0x2C74CC, 0x44
.global __vt__27TaiNapkidApproachPikiAction
__vt__27TaiNapkidApproachPikiAction:
	.incbin "baserom.dol", 0x2C7510, 0x44
.global __vt__24TaiNapkidAscendingAction
__vt__24TaiNapkidAscendingAction:
	.incbin "baserom.dol", 0x2C7554, 0x40
.global __vt__21TaiNapkidFlyingAction
__vt__21TaiNapkidFlyingAction:
	.incbin "baserom.dol", 0x2C7594, 0x40
.global __vt__23TaiNapkidCirclingAction
__vt__23TaiNapkidCirclingAction:
	.incbin "baserom.dol", 0x2C75D4, 0x48
.global __vt__29TaiNapkidStraightFlyingAction
__vt__29TaiNapkidStraightFlyingAction:
	.incbin "baserom.dol", 0x2C761C, 0x44
.global __vt__25TaiNapkidShortRangeAction
__vt__25TaiNapkidShortRangeAction:
	.incbin "baserom.dol", 0x2C7660, 0x40
.global __vt__23TaiNapkidPikiLostAction
__vt__23TaiNapkidPikiLostAction:
	.incbin "baserom.dol", 0x2C76A0, 0x44
.global __vt__25TaiNapkidTargetPikiAction
__vt__25TaiNapkidTargetPikiAction:
	.incbin "baserom.dol", 0x2C76E4, 0xA4
.global __vt__29TaiNapkidWanderingRouteAction
__vt__29TaiNapkidWanderingRouteAction:
	.incbin "baserom.dol", 0x2C7788, 0x54
.global __vt__29TekiNapkidShortRangeCondition
__vt__29TekiNapkidShortRangeCondition:
	.incbin "baserom.dol", 0x2C77DC, 0x58
.global __vt__29TekiNapkidTargetPikiCondition
__vt__29TekiNapkidTargetPikiCondition:
	.incbin "baserom.dol", 0x2C7834, 0x5C
.global __vt__17TaiNapkidStrategy
__vt__17TaiNapkidStrategy:
	.incbin "baserom.dol", 0x2C7890, 0x144
.global __vt__19TaiNapkidParameters
__vt__19TaiNapkidParameters:
	.incbin "baserom.dol", 0x2C79D4, 0x34
.global lbl_802CAA08
lbl_802CAA08:
	.incbin "baserom.dol", 0x2C7A08, 0x1E4
.global __vt__25TaiOtimotiLegEffectAction
__vt__25TaiOtimotiLegEffectAction:
	.incbin "baserom.dol", 0x2C7BEC, 0x4C
.global __vt__31TaiOtimotiAttackingEffectAction
__vt__31TaiOtimotiAttackingEffectAction:
	.incbin "baserom.dol", 0x2C7C38, 0x44
.global __vt__25TaiOtimotiAttackingAction
__vt__25TaiOtimotiAttackingAction:
	.incbin "baserom.dol", 0x2C7C7C, 0x44
.global __vt__24TaiOtimotiBouncingAction
__vt__24TaiOtimotiBouncingAction:
	.incbin "baserom.dol", 0x2C7CC0, 0xD8
.global __vt__24TaiOtimotiPressingAction
__vt__24TaiOtimotiPressingAction:
	.incbin "baserom.dol", 0x2C7D98, 0x44
.global __vt__24TaiOtimotiDroppingAction
__vt__24TaiOtimotiDroppingAction:
	.incbin "baserom.dol", 0x2C7DDC, 0x44
.global __vt__26TaiOtimotiAirWaitingAction
__vt__26TaiOtimotiAirWaitingAction:
	.incbin "baserom.dol", 0x2C7E20, 0x40
.global __vt__23TaiOtimotiJumpingAction
__vt__23TaiOtimotiJumpingAction:
	.incbin "baserom.dol", 0x2C7E60, 0x44
.global __vt__26TaiOtimotiFailToJumpAction
__vt__26TaiOtimotiFailToJumpAction:
	.incbin "baserom.dol", 0x2C7EA4, 0x8C
.global __vt__21TaiOtimotiFlickAction
__vt__21TaiOtimotiFlickAction:
	.incbin "baserom.dol", 0x2C7F30, 0x4C
.global __vt__34TaiOtimotiStartDroppingWaterAction
__vt__34TaiOtimotiStartDroppingWaterAction:
	.incbin "baserom.dol", 0x2C7F7C, 0x6C
.global __vt__18TaiOtimotiStrategy
__vt__18TaiOtimotiStrategy:
	.incbin "baserom.dol", 0x2C7FE8, 0x110
.global __vt__22TaiBlackFrogParameters
__vt__22TaiBlackFrogParameters:
	.incbin "baserom.dol", 0x2C80F8, 0x6C
.global __vt__20TaiOtimotiParameters
__vt__20TaiOtimotiParameters:
	.incbin "baserom.dol", 0x2C8164, 0x34
.global lbl_802CB198
lbl_802CB198:
	.incbin "baserom.dol", 0x2C8198, 0x8C
.global __vt__26TaiPalmChangingColorAction
__vt__26TaiPalmChangingColorAction:
	.incbin "baserom.dol", 0x2C8224, 0x44
.global __vt__26TaiPalmSettingPelletAction
__vt__26TaiPalmSettingPelletAction:
	.incbin "baserom.dol", 0x2C8268, 0x40
.global __vt__22TaiPalmSunflowerAction
__vt__22TaiPalmSunflowerAction:
	.incbin "baserom.dol", 0x2C82A8, 0x44
.global __vt__25TaiPalmFlowerDamageAction
__vt__25TaiPalmFlowerDamageAction:
	.incbin "baserom.dol", 0x2C82EC, 0x3C
.global __vt__17TaiPalmGrowAction
__vt__17TaiPalmGrowAction:
	.incbin "baserom.dol", 0x2C8328, 0x40
.global __vt__20TaiPalmGrowingAction
__vt__20TaiPalmGrowingAction:
	.incbin "baserom.dol", 0x2C8368, 0x94
.global __vt__21TaiPalmDamagingAction
__vt__21TaiPalmDamagingAction:
	.incbin "baserom.dol", 0x2C83FC, 0x70
.global __vt__18TaiPalmDyingAction
__vt__18TaiPalmDyingAction:
	.incbin "baserom.dol", 0x2C846C, 0x44
.global __vt__19TaiPalmMotionAction
__vt__19TaiPalmMotionAction:
	.incbin "baserom.dol", 0x2C84B0, 0x110
.global __vt__15TaiPalmStrategy
__vt__15TaiPalmStrategy:
	.incbin "baserom.dol", 0x2C85C0, 0xD4
.global __vt__17TaiPalmParameters
__vt__17TaiPalmParameters:
	.incbin "baserom.dol", 0x2C8694, 0x8C
.global __vt__19TaiDangerLifeAction
__vt__19TaiDangerLifeAction:
	.incbin "baserom.dol", 0x2C8720, 0x38
.global __vt__13TaiWarnAction
__vt__13TaiWarnAction:
	.incbin "baserom.dol", 0x2C8758, 0x3C
.global __vt__16TaiPressedAction
__vt__16TaiPressedAction:
	.incbin "baserom.dol", 0x2C8794, 0x40
.global __vt__21TaiBeingPressedAction
__vt__21TaiBeingPressedAction:
	.incbin "baserom.dol", 0x2C87D4, 0x3C
.global __vt__16TaiSmashedAction
__vt__16TaiSmashedAction:
	.incbin "baserom.dol", 0x2C8810, 0x3C
.global __vt__16TaiStickedAction
__vt__16TaiStickedAction:
	.incbin "baserom.dol", 0x2C884C, 0xBC
.global __vt__31TaiTargetNearestCollisionAction
__vt__31TaiTargetNearestCollisionAction:
	.incbin "baserom.dol", 0x2C8908, 0x48
.global __vt__31TaiTargetNearestAssailantAction
__vt__31TaiTargetNearestAssailantAction:
	.incbin "baserom.dol", 0x2C8950, 0x60
.global __vt__17TaiDamagingAction
__vt__17TaiDamagingAction:
	.incbin "baserom.dol", 0x2C89B0, 0x54
.global __vt__40TaiCounterattackSimultaneousDamageAction
__vt__40TaiCounterattackSimultaneousDamageAction:
	.incbin "baserom.dol", 0x2C8A04, 0x44
.global __vt__27TaiSimultaneousDamageAction
__vt__27TaiSimultaneousDamageAction:
	.incbin "baserom.dol", 0x2C8A48, 0x38
.global __vt__15TaiDamageAction
__vt__15TaiDamageAction:
	.incbin "baserom.dol", 0x2C8A80, 0x40
.global __vt__20TaiDamageScaleAction
__vt__20TaiDamageScaleAction:
	.incbin "baserom.dol", 0x2C8AC0, 0x40
.global __vt__20TaiDamageCountAction
__vt__20TaiDamageCountAction:
	.incbin "baserom.dol", 0x2C8B00, 0x44
.global __vt__25TaiDamageCountResetAction
__vt__25TaiDamageCountResetAction:
	.incbin "baserom.dol", 0x2C8B44, 0x40
.global __vt__14TaiDyingAction
__vt__14TaiDyingAction:
	.incbin "baserom.dol", 0x2C8B84, 0x44
.global __vt__25TaiCreateDeadEffectAction
__vt__25TaiCreateDeadEffectAction:
	.incbin "baserom.dol", 0x2C8BC8, 0x3C
.global __vt__19TaiSpawnItemsAction
__vt__19TaiSpawnItemsAction:
	.incbin "baserom.dol", 0x2C8C04, 0x3C
.global __vt__19TaiStartDyingAction
__vt__19TaiStartDyingAction:
	.incbin "baserom.dol", 0x2C8C40, 0x38
.global __vt__12TaiDyeAction
__vt__12TaiDyeAction:
	.incbin "baserom.dol", 0x2C8C78, 0x3C
.global __vt__19TaiLifeDamageAction
__vt__19TaiLifeDamageAction:
	.incbin "baserom.dol", 0x2C8CB4, 0x3C
.global __vt__17TaiLifeZeroAction
__vt__17TaiLifeZeroAction:
	.incbin "baserom.dol", 0x2C8CF0, 0x38
.global __vt__13TaiDeadAction
__vt__13TaiDeadAction:
	.incbin "baserom.dol", 0x2C8D28, 0x20
.global lbl_802CBD48
lbl_802CBD48:
	.incbin "baserom.dol", 0x2C8D48, 0x148
.global __vt__35TaiSwallowMissAttackingEffectAction
__vt__35TaiSwallowMissAttackingEffectAction:
	.incbin "baserom.dol", 0x2C8E90, 0x58
.global __vt__25TaiSwallowLegEffectAction
__vt__25TaiSwallowLegEffectAction:
	.incbin "baserom.dol", 0x2C8EE8, 0x44
.global __vt__22TaiSwallowNoticeAction
__vt__22TaiSwallowNoticeAction:
	.incbin "baserom.dol", 0x2C8F2C, 0x40
.global __vt__21TaiSwallowSnoreAction
__vt__21TaiSwallowSnoreAction:
	.incbin "baserom.dol", 0x2C8F6C, 0x48
.global __vt__31TaiSwallowSwallowingFlickAction
__vt__31TaiSwallowSwallowingFlickAction:
	.incbin "baserom.dol", 0x2C8FB4, 0xFC
.global __vt__24TaiSwallowFlickingAction
__vt__24TaiSwallowFlickingAction:
	.incbin "baserom.dol", 0x2C90B0, 0xCC
.global __vt__23TaiSwallowTurningAction
__vt__23TaiSwallowTurningAction:
	.incbin "baserom.dol", 0x2C917C, 0x4C
.global __vt__30TaiSwallowReceiveMessageAction
__vt__30TaiSwallowReceiveMessageAction:
	.incbin "baserom.dol", 0x2C91C8, 0x6C
.global __vt__18TaiSwallowStrategy
__vt__18TaiSwallowStrategy:
	.incbin "baserom.dol", 0x2C9234, 0x114
.global __vt__25TaiBlackSwallowParameters
__vt__25TaiBlackSwallowParameters:
	.incbin "baserom.dol", 0x2C9348, 0x6C
.global __vt__20TaiSwallowParameters
__vt__20TaiSwallowParameters:
	.incbin "baserom.dol", 0x2C93B4, 0x50
.global lbl_802CC404
lbl_802CC404:
	.incbin "baserom.dol", 0x2C9404, 0x14
.global lbl_802CC418
lbl_802CC418:
	.incbin "baserom.dol", 0x2C9418, 0x44
.global __vt__26TaiPearlTresureSoundAction
__vt__26TaiPearlTresureSoundAction:
	.incbin "baserom.dol", 0x2C945C, 0x6C
.global __vt__16TaiPearlStrategy
__vt__16TaiPearlStrategy:
	.incbin "baserom.dol", 0x2C94C8, 0xBC
.global __vt__21TaiRocpearlParameters
__vt__21TaiRocpearlParameters:
	.incbin "baserom.dol", 0x2C9584, 0x68
.global __vt__18TaiPearlParameters
__vt__18TaiPearlParameters:
	.incbin "baserom.dol", 0x2C95EC, 0x118
.global __vt__17TaiShellEatAction
__vt__17TaiShellEatAction:
	.incbin "baserom.dol", 0x2C9704, 0x60
.global __vt__28TaiShellNaviPikiInsideAction
__vt__28TaiShellNaviPikiInsideAction:
	.incbin "baserom.dol", 0x2C9764, 0x48
.global __vt__30TaiShellSaveItemPositionAction
__vt__30TaiShellSaveItemPositionAction:
	.incbin "baserom.dol", 0x2C97AC, 0x44
.global __vt__25TaiShellSetPositionAction
__vt__25TaiShellSetPositionAction:
	.incbin "baserom.dol", 0x2C97F0, 0x44
.global __vt__16TaiShellStrategy
__vt__16TaiShellStrategy:
	.incbin "baserom.dol", 0x2C9834, 0xB4
.global __vt__18TaiShellParameters
__vt__18TaiShellParameters:
	.incbin "baserom.dol", 0x2C98E8, 0xA8
.global __vt__22TaiStartingTimerAction
__vt__22TaiStartingTimerAction:
	.incbin "baserom.dol", 0x2C9990, 0x40
.global __vt__21TaiTimerElapsedAction
__vt__21TaiTimerElapsedAction:
	.incbin "baserom.dol", 0x2C99D0, 0x3C
.global __vt__19TaiResetTimerAction
__vt__19TaiResetTimerAction:
	.incbin "baserom.dol", 0x2C9A0C, 0x1C
.global __vt__14TaiTimerAction
__vt__14TaiTimerAction:
	.incbin "baserom.dol", 0x2C9A28, 0x98
.global __vt__20TaiWaitTurningAction
__vt__20TaiWaitTurningAction:
	.incbin "baserom.dol", 0x2C9AC0, 0x168
.global __vt__4Teki
__vt__4Teki:
	.incbin "baserom.dol", 0x2C9C28, 0x244
.global lbl_802CCE6C
lbl_802CCE6C:
	.incbin "baserom.dol", 0x2C9E6C, 0x60
.global __vt__20TekiAnimationManager
__vt__20TekiAnimationManager:
	.incbin "baserom.dol", 0x2C9ECC, 0x2A4
.global __vt__5BTeki
__vt__5BTeki:
	.incbin "baserom.dol", 0x2CA170, 0x274
.global __vt__18TekiAngleCondition
__vt__18TekiAngleCondition:
	.incbin "baserom.dol", 0x2CA3E4, 0xB4
.global __vt__18TekiLowerCondition
__vt__18TekiLowerCondition:
	.incbin "baserom.dol", 0x2CA498, 0x3C
.global __vt__26TekiVisibleHeightCondition
__vt__26TekiVisibleHeightCondition:
	.incbin "baserom.dol", 0x2CA4D4, 0x38
.global __vt__20TekiVisibleCondition
__vt__20TekiVisibleCondition:
	.incbin "baserom.dol", 0x2CA50C, 0x38
.global __vt__23TekiAttackableCondition
__vt__23TekiAttackableCondition:
	.incbin "baserom.dol", 0x2CA544, 0x38
.global __vt__23TekiLowerRangeCondition
__vt__23TekiLowerRangeCondition:
	.incbin "baserom.dol", 0x2CA57C, 0x38
.global __vt__20TekiStickerCondition
__vt__20TekiStickerCondition:
	.incbin "baserom.dol", 0x2CA5B4, 0x3C
.global __vt__27TekiSphereDistanceCondition
__vt__27TekiSphereDistanceCondition:
	.incbin "baserom.dol", 0x2CA5F0, 0x38
.global __vt__21TekiDistanceCondition
__vt__21TekiDistanceCondition:
	.incbin "baserom.dol", 0x2CA628, 0x40
.global __vt__28TekiCreaturePointerCondition
__vt__28TekiCreaturePointerCondition:
	.incbin "baserom.dol", 0x2CA668, 0x3C
.global __vt__24TekiRecognitionCondition
__vt__24TekiRecognitionCondition:
	.incbin "baserom.dol", 0x2CA6A4, 0x38
.global __vt__21TekiStickingCondition
__vt__21TekiStickingCondition:
	.incbin "baserom.dol", 0x2CA6DC, 0x44
.global __vt__35TekiPositionSphereDistanceCondition
__vt__35TekiPositionSphereDistanceCondition:
	.incbin "baserom.dol", 0x2CA720, 0x44
.global __vt__35TekiPositionCircleDistanceCondition
__vt__35TekiPositionCircleDistanceCondition:
	.incbin "baserom.dol", 0x2CA764, 0x40
.global __vt__29TekiPositionDistanceCondition
__vt__29TekiPositionDistanceCondition:
	.incbin "baserom.dol", 0x2CA7A4, 0x34
.global __vt__19TekiPelletCondition
__vt__19TekiPelletCondition:
	.incbin "baserom.dol", 0x2CA7D8, 0x38
.global __vt__21TekiNaviPikiCondition
__vt__21TekiNaviPikiCondition:
	.incbin "baserom.dol", 0x2CA810, 0x34
.global __vt__17TekiNaviCondition
__vt__17TekiNaviCondition:
	.incbin "baserom.dol", 0x2CA844, 0x34
.global __vt__17TekiFreeCondition
__vt__17TekiFreeCondition:
	.incbin "baserom.dol", 0x2CA878, 0x34
.global __vt__17TekiTypeCondition
__vt__17TekiTypeCondition:
	.incbin "baserom.dol", 0x2CA8AC, 0x34
.global __vt__18TekiStateCondition
__vt__18TekiStateCondition:
	.incbin "baserom.dol", 0x2CA8E0, 0x38
.global __vt__22TekiPikiStateCondition
__vt__22TekiPikiStateCondition:
	.incbin "baserom.dol", 0x2CA918, 0x60
.global __vt__17InteractHitEffect
__vt__17InteractHitEffect:
	.incbin "baserom.dol", 0x2CA978, 0x74
.global __vt__12InteractBomb
__vt__12InteractBomb:
	.incbin "baserom.dol", 0x2CA9EC, 0x2C
.global lbl_802CDA18
lbl_802CDA18:
	.incbin "baserom.dol", 0x2CAA18, 0x30
.global typeNames__7TekiMgr
typeNames__7TekiMgr:
	.incbin "baserom.dol", 0x2CAA48, 0x8C
.global typeIds__7TekiMgr
typeIds__7TekiMgr:
	.incbin "baserom.dol", 0x2CAAD4, 0x8C
.global lbl_802CDB60
lbl_802CDB60:
	.incbin "baserom.dol", 0x2CAB60, 0x138
.global __vt__7TekiMgr
__vt__7TekiMgr:
	.incbin "baserom.dol", 0x2CAC98, 0x160
.global __vt__5NTeki
__vt__5NTeki:
	.incbin "baserom.dol", 0x2CADF8, 0x210
.global lbl_802CE008
lbl_802CE008:
	.incbin "baserom.dol", 0x2CB008, 0x564
.global __vt__14TekiParameters
__vt__14TekiParameters:
	.incbin "baserom.dol", 0x2CB56C, 0x4C
.global lbl_802CE5B8
lbl_802CE5B8:
	.incbin "baserom.dol", 0x2CB5B8, 0xE4
.global __vt__15TekiPersonality
__vt__15TekiPersonality:
	.incbin "baserom.dol", 0x2CB69C, 0x48
.global __vt__12TekiStrategy
__vt__12TekiStrategy:
	.incbin "baserom.dol", 0x2CB6E4, 0x38
.global lbl_802CE71C
lbl_802CE71C:
	.incbin "baserom.dol", 0x2CB71C, 0xC
.global lbl_802CE728
lbl_802CE728:
	.incbin "baserom.dol", 0x2CB728, 0xC
.global lbl_802CE734
lbl_802CE734:
	.incbin "baserom.dol", 0x2CB734, 0x70
.global __vt__13GenObjectBoss
__vt__13GenObjectBoss:
	.incbin "baserom.dol", 0x2CB7A4, 0x48
.global lbl_802CE7EC
lbl_802CE7EC:
	.incbin "baserom.dol", 0x2CB7EC, 0x78
.global __vt__4Boss
__vt__4Boss:
	.incbin "baserom.dol", 0x2CB864, 0x1D4
.global __vt__8BossProp
__vt__8BossProp:
	.incbin "baserom.dol", 0x2CBA38, 0x64
.global lbl_802CEA9C
lbl_802CEA9C:
	.incbin "baserom.dol", 0x2CBA9C, 0x60
.global __vt__20BossAnimationManager
__vt__20BossAnimationManager:
	.incbin "baserom.dol", 0x2CBAFC, 0x80
.global __vt__15CndBossCollKill
__vt__15CndBossCollKill:
	.incbin "baserom.dol", 0x2CBB7C, 0x2C
.global __vt__17CndStickMouthKill
__vt__17CndStickMouthKill:
	.incbin "baserom.dol", 0x2CBBA8, 0x2C
.global __vt__16CndStickBossKill
__vt__16CndStickBossKill:
	.incbin "baserom.dol", 0x2CBBD4, 0x28
.global __vt__12CndBossFlick
__vt__12CndBossFlick:
	.incbin "baserom.dol", 0x2CBBFC, 0x24
.global __vt__10CndIsAlive
__vt__10CndIsAlive:
	.incbin "baserom.dol", 0x2CBC20, 0x10
.global lbl_802CEC30
lbl_802CEC30:
	.incbin "baserom.dol", 0x2CBC30, 0xC
.global lbl_802CEC3C
lbl_802CEC3C:
	.incbin "baserom.dol", 0x2CBC3C, 0x360
.global lbl_802CEF9C
lbl_802CEF9C:
	.incbin "baserom.dol", 0x2CBF9C, 0x30
.global lbl_802CEFCC
lbl_802CEFCC:
	.incbin "baserom.dol", 0x2CBFCC, 0x54
.global __vt__8BossNode
__vt__8BossNode:
	.incbin "baserom.dol", 0x2CC020, 0xC0
.global __vt__7BossMgr
__vt__7BossMgr:
	.incbin "baserom.dol", 0x2CC0E0, 0x78
.global lbl_802CF158
lbl_802CF158:
	.incbin "baserom.dol", 0x2CC158, 0x24
.global lbl_802CF17C
lbl_802CF17C:
	.incbin "baserom.dol", 0x2CC17C, 0x58
.global __vt__12SpiderDrawer
__vt__12SpiderDrawer:
	.incbin "baserom.dol", 0x2CC1D4, 0xAC
.global __vt__6Spider
__vt__6Spider:
	.incbin "baserom.dol", 0x2CC280, 0x1E0
.global __vt__10SpiderProp
__vt__10SpiderProp:
	.incbin "baserom.dol", 0x2CC460, 0x38
.global spiderSE
spiderSE:
	.incbin "baserom.dol", 0x2CC498, 0x30
.global lbl_802CF4C8
lbl_802CF4C8:
	.incbin "baserom.dol", 0x2CC4C8, 0x44
.global __vt__8SpiderAi
__vt__8SpiderAi:
	.incbin "baserom.dol", 0x2CC50C, 0x1C
.global leg_index__4Kumo
leg_index__4Kumo:
	.incbin "baserom.dol", 0x2CC528, 0x30
.global legId__4Kumo
legId__4Kumo:
	.incbin "baserom.dol", 0x2CC558, 0xD0
.global __vt__30SpiderGenHalfDeadCallBackJoint
__vt__30SpiderGenHalfDeadCallBackJoint:
	.incbin "baserom.dol", 0x2CC628, 0x30
.global __vt__23SpiderGenPerishCallBack
__vt__23SpiderGenPerishCallBack:
	.incbin "baserom.dol", 0x2CC658, 0x30
.global __vt__23SpiderGenRippleCallBack
__vt__23SpiderGenRippleCallBack:
	.incbin "baserom.dol", 0x2CC688, 0x24
.global lbl_802CF6AC
lbl_802CF6AC:
	.incbin "baserom.dol", 0x2CC6AC, 0x88
.global __vt__5Snake
__vt__5Snake:
	.incbin "baserom.dol", 0x2CC734, 0x15C
.global __vt__Q25Snake18BoundSphereUpdater
__vt__Q25Snake18BoundSphereUpdater:
	.incbin "baserom.dol", 0x2CC890, 0x10
.global __vt__15CollPartUpdater
__vt__15CollPartUpdater:
	.incbin "baserom.dol", 0x2CC8A0, 0xD8
.global __vt__9SnakeProp
__vt__9SnakeProp:
	.incbin "baserom.dol", 0x2CC978, 0x38
.global snakeSE
snakeSE:
	.incbin "baserom.dol", 0x2CC9B0, 0x30
.global lbl_802CF9E0
lbl_802CF9E0:
	.incbin "baserom.dol", 0x2CC9E0, 0x80
.global __vt__7SnakeAi
__vt__7SnakeAi:
	.incbin "baserom.dol", 0x2CCA60, 0x88
.global __vt__26SnakeGenBodyRotateCallBack
__vt__26SnakeGenBodyRotateCallBack:
	.incbin "baserom.dol", 0x2CCAE8, 0x38
.global __vt__28SnakeGenBodyOnGroundCallBack
__vt__28SnakeGenBodyOnGroundCallBack:
	.incbin "baserom.dol", 0x2CCB20, 0x24
.global lbl_802CFB44
lbl_802CFB44:
	.incbin "baserom.dol", 0x2CCB44, 0xC0
.global __vt__5Slime
__vt__5Slime:
	.incbin "baserom.dol", 0x2CCC04, 0x15C
.global __vt__Q25Slime20CollideSphereUpdater
__vt__Q25Slime20CollideSphereUpdater:
	.incbin "baserom.dol", 0x2CCD60, 0x38
.global __vt__Q25Slime17TubeSphereUpdater
__vt__Q25Slime17TubeSphereUpdater:
	.incbin "baserom.dol", 0x2CCD98, 0x38
.global __vt__Q25Slime18BoundSphereUpdater
__vt__Q25Slime18BoundSphereUpdater:
	.incbin "baserom.dol", 0x2CCDD0, 0xE8
.global __vt__9SlimeProp
__vt__9SlimeProp:
	.incbin "baserom.dol", 0x2CCEB8, 0x38
.global lbl_802CFEF0
lbl_802CFEF0:
	.incbin "baserom.dol", 0x2CCEF0, 0xA4
.global __vt__13SlimeCreature
__vt__13SlimeCreature:
	.incbin "baserom.dol", 0x2CCF94, 0x120
.global lbl_802D00B4
lbl_802D00B4:
	.incbin "baserom.dol", 0x2CD0B4, 0x54
.global __vt__10KingDrawer
__vt__10KingDrawer:
	.incbin "baserom.dol", 0x2CD108, 0xAC
.global __vt__4King
__vt__4King:
	.incbin "baserom.dol", 0x2CD1B4, 0x1E0
.global __vt__8KingProp
__vt__8KingProp:
	.incbin "baserom.dol", 0x2CD394, 0x3C
.global kingSE
kingSE:
	.incbin "baserom.dol", 0x2CD3D0, 0x44
.global lbl_802D0414
lbl_802D0414:
	.incbin "baserom.dol", 0x2CD414, 0x24
.global lbl_802D0438
lbl_802D0438:
	.incbin "baserom.dol", 0x2CD438, 0x40
.global lbl_802D0478
lbl_802D0478:
	.incbin "baserom.dol", 0x2CD478, 0x9C
.global __vt__6KingAi
__vt__6KingAi:
	.incbin "baserom.dol", 0x2CD514, 0x88
.global __vt__21KingGenSalivaCallBack
__vt__21KingGenSalivaCallBack:
	.incbin "baserom.dol", 0x2CD59C, 0x30
.global __vt__21KingGenRippleCallBack
__vt__21KingGenRippleCallBack:
	.incbin "baserom.dol", 0x2CD5CC, 0x7C
.global __vt__32KingGenSpitPartsParticleCallBack
__vt__32KingGenSpitPartsParticleCallBack:
	.incbin "baserom.dol", 0x2CD648, 0x34
.global __vt__25KingGenDamageStarCallBack
__vt__25KingGenDamageStarCallBack:
	.incbin "baserom.dol", 0x2CD67C, 0x38
.global __vt__29KingGenSalivaParticleCallBack
__vt__29KingGenSalivaParticleCallBack:
	.incbin "baserom.dol", 0x2CD6B4, 0x40
.global __vt__27KingGenSpreadSalivaCallBack
__vt__27KingGenSpreadSalivaCallBack:
	.incbin "baserom.dol", 0x2CD6F4, 0x28
.global lbl_802D071C
lbl_802D071C:
	.incbin "baserom.dol", 0x2CD71C, 0x88
.global __vt__6Kogane
__vt__6Kogane:
	.incbin "baserom.dol", 0x2CD7A4, 0x1C0
.global __vt__10KoganeProp
__vt__10KoganeProp:
	.incbin "baserom.dol", 0x2CD964, 0x58
.global lbl_802D09BC
lbl_802D09BC:
	.incbin "baserom.dol", 0x2CD9BC, 0x3C
.global __vt__8KoganeAi
__vt__8KoganeAi:
	.incbin "baserom.dol", 0x2CD9F8, 0x5C
.global __vt__23KoganeGenRippleCallBack
__vt__23KoganeGenRippleCallBack:
	.incbin "baserom.dol", 0x2CDA54, 0x24
.global lbl_802D0A78
lbl_802D0A78:
	.incbin "baserom.dol", 0x2CDA78, 0x88
.global __vt__3Pom
__vt__3Pom:
	.incbin "baserom.dol", 0x2CDB00, 0x1E0
.global __vt__7PomProp
__vt__7PomProp:
	.incbin "baserom.dol", 0x2CDCE0, 0x38
.global pomSE
pomSE:
	.incbin "baserom.dol", 0x2CDD18, 0x7C
.global __vt__5PomAi
__vt__5PomAi:
	.incbin "baserom.dol", 0x2CDD94, 0x5C
.global __vt__22PomGenOpenStarCallBack
__vt__22PomGenOpenStarCallBack:
	.incbin "baserom.dol", 0x2CDDF0, 0x44
.global lbl_802D0E34
lbl_802D0E34:
	.incbin "baserom.dol", 0x2CDE34, 0x88
.global __vt__8KingBack
__vt__8KingBack:
	.incbin "baserom.dol", 0x2CDEBC, 0x18C
.global __vt__12KingBackProp
__vt__12KingBackProp:
	.incbin "baserom.dol", 0x2CE048, 0x44
.global lbl_802D108C
lbl_802D108C:
	.incbin "baserom.dol", 0x2CE08C, 0x88
.global __vt__7Nucleus
__vt__7Nucleus:
	.incbin "baserom.dol", 0x2CE114, 0x188
.global __vt__11NucleusProp
__vt__11NucleusProp:
	.incbin "baserom.dol", 0x2CE29C, 0x78
.global __vt__9NucleusAi
__vt__9NucleusAi:
	.incbin "baserom.dol", 0x2CE314, 0x38
.global lbl_802D134C
lbl_802D134C:
	.incbin "baserom.dol", 0x2CE34C, 0x88
.global __vt__11CoreNucleus
__vt__11CoreNucleus:
	.incbin "baserom.dol", 0x2CE3D4, 0x18C
.global __vt__15CoreNucleusProp
__vt__15CoreNucleusProp:
	.incbin "baserom.dol", 0x2CE560, 0x7C
.global __vt__13CoreNucleusAi
__vt__13CoreNucleusAi:
	.incbin "baserom.dol", 0x2CE5DC, 0x28
.global lbl_802D1604
lbl_802D1604:
	.incbin "baserom.dol", 0x2CE604, 0x88
.global __vt__4Mizu
__vt__4Mizu:
	.incbin "baserom.dol", 0x2CE68C, 0x188
.global __vt__8MizuProp
__vt__8MizuProp:
	.incbin "baserom.dol", 0x2CE814, 0xA0
.global __vt__6MizuAi
__vt__6MizuAi:
	.incbin "baserom.dol", 0x2CE8B4, 0x60
.global __vt__25MizuGenSpringPuffCallBack
__vt__25MizuGenSpringPuffCallBack:
	.incbin "baserom.dol", 0x2CE914, 0x24
.global patternTable
patternTable:
	.incbin "baserom.dol", 0x2CE938, 0x80
.global rumbleFrame_00
rumbleFrame_00:
	.incbin "baserom.dol", 0x2CE9B8, 0x2C
.global rumblePower_00
rumblePower_00:
	.incbin "baserom.dol", 0x2CE9E4, 0x2C
.global rumbleFrame_01
rumbleFrame_01:
	.incbin "baserom.dol", 0x2CEA10, 0x60
.global rumblePower_01
rumblePower_01:
	.incbin "baserom.dol", 0x2CEA70, 0x60
.global rumbleFrame_02
rumbleFrame_02:
	.incbin "baserom.dol", 0x2CEAD0, 0x14
.global rumblePower_02
rumblePower_02:
	.incbin "baserom.dol", 0x2CEAE4, 0x14
.global rumbleFrame_03
rumbleFrame_03:
	.incbin "baserom.dol", 0x2CEAF8, 0x70
.global rumblePower_03
rumblePower_03:
	.incbin "baserom.dol", 0x2CEB68, 0x70
.global rumbleFrame_04
rumbleFrame_04:
	.incbin "baserom.dol", 0x2CEBD8, 0x18
.global rumblePower_04
rumblePower_04:
	.incbin "baserom.dol", 0x2CEBF0, 0x18
.global rumbleFrame_05
rumbleFrame_05:
	.incbin "baserom.dol", 0x2CEC08, 0x54
.global rumblePower_05
rumblePower_05:
	.incbin "baserom.dol", 0x2CEC5C, 0x54
.global rumbleFrame_06
rumbleFrame_06:
	.incbin "baserom.dol", 0x2CECB0, 0x50
.global rumblePower_06
rumblePower_06:
	.incbin "baserom.dol", 0x2CED00, 0x50
.global rumbleFrame_07
rumbleFrame_07:
	.incbin "baserom.dol", 0x2CED50, 0x50
.global rumblePower_07
rumblePower_07:
	.incbin "baserom.dol", 0x2CEDA0, 0x50
.global rumbleFrame_08
rumbleFrame_08:
	.incbin "baserom.dol", 0x2CEDF0, 0x28
.global rumblePower_08
rumblePower_08:
	.incbin "baserom.dol", 0x2CEE18, 0x28
.global rumbleFrame_09
rumbleFrame_09:
	.incbin "baserom.dol", 0x2CEE40, 0x2C
.global rumblePower_09
rumblePower_09:
	.incbin "baserom.dol", 0x2CEE6C, 0x2C
.global rumbleFrame_10
rumbleFrame_10:
	.incbin "baserom.dol", 0x2CEE98, 0x18
.global rumblePower_10
rumblePower_10:
	.incbin "baserom.dol", 0x2CEEB0, 0x18
.global rumbleFrame_11
rumbleFrame_11:
	.incbin "baserom.dol", 0x2CEEC8, 0x38
.global rumblePower_11
rumblePower_11:
	.incbin "baserom.dol", 0x2CEF00, 0x38
.global rumbleFrame_12
rumbleFrame_12:
	.incbin "baserom.dol", 0x2CEF38, 0x64
.global rumblePower_12
rumblePower_12:
	.incbin "baserom.dol", 0x2CEF9C, 0x64
.global rumbleFrame_13
rumbleFrame_13:
	.incbin "baserom.dol", 0x2CF000, 0x38
.global rumblePower_13
rumblePower_13:
	.incbin "baserom.dol", 0x2CF038, 0x38
.global rumbleFrame_14
rumbleFrame_14:
	.incbin "baserom.dol", 0x2CF070, 0x20
.global rumblePower_14
rumblePower_14:
	.incbin "baserom.dol", 0x2CF090, 0x20
.global rumbleFrame_15
rumbleFrame_15:
	.incbin "baserom.dol", 0x2CF0B0, 0x18
.global rumblePower_15
rumblePower_15:
	.incbin "baserom.dol", 0x2CF0C8, 0x18
.global rumbleFrame_16
rumbleFrame_16:
	.incbin "baserom.dol", 0x2CF0E0, 0x6C
.global rumblePower_16
rumblePower_16:
	.incbin "baserom.dol", 0x2CF14C, 0x6C
.global rumbleFrame_17
rumbleFrame_17:
	.incbin "baserom.dol", 0x2CF1B8, 0x98
.global rumblePower_17
rumblePower_17:
	.incbin "baserom.dol", 0x2CF250, 0x98
.global rumbleFrame_18
rumbleFrame_18:
	.incbin "baserom.dol", 0x2CF2E8, 0x3C
.global rumblePower_18
rumblePower_18:
	.incbin "baserom.dol", 0x2CF324, 0x3C
.global rumbleFrame_19
rumbleFrame_19:
	.incbin "baserom.dol", 0x2CF360, 0xC
.global rumblePower_19
rumblePower_19:
	.incbin "baserom.dol", 0x2CF36C, 0xC
.global channelDataTbl
channelDataTbl:
	.incbin "baserom.dol", 0x2CF378, 0xF0
.global lbl_802D2468
lbl_802D2468:
	.incbin "baserom.dol", 0x2CF468, 0x48
.global lbl_802D24B0
lbl_802D24B0:
	.incbin "baserom.dol", 0x2CF4B0, 0x128
.global lbl_802D25D8
lbl_802D25D8:
	.incbin "baserom.dol", 0x2CF5D8, 0x90
.global __vt__Q23zen13OgTestSection
__vt__Q23zen13OgTestSection:
	.incbin "baserom.dol", 0x2CF668, 0x98
.global __vt__Q23zen12OgTestScreen
__vt__Q23zen12OgTestScreen:
	.incbin "baserom.dol", 0x2CF700, 0x50
.global lbl_802D2750
lbl_802D2750:
	.incbin "baserom.dol", 0x2CF750, 0x1C
.global wkstr__3zen
wkstr__3zen:
	.incbin "baserom.dol", 0x2CF76C, 0x400
.global numStrBuf__3zen
numStrBuf__3zen:
	.incbin "baserom.dol", 0x2CFB6C, 0x100
.global formatStr__3zen
formatStr__3zen:
	.incbin "baserom.dol", 0x2CFC6C, 0x100
.global SpecialNumber__3zen
SpecialNumber__3zen:
	.incbin "baserom.dol", 0x2CFD6C, 0x190
.global lbl_802D2EFC
lbl_802D2EFC:
	.incbin "baserom.dol", 0x2CFEFC, 0xE8
.global __vt__Q23zen20NumberPicCallBack$$0i$$1
__vt__Q23zen20NumberPicCallBack$$0i$$1:
	.incbin "baserom.dol", 0x2CFFE4, 0x10
.global __vt__15P2DPaneCallBack
__vt__15P2DPaneCallBack:
	.incbin "baserom.dol", 0x2CFFF4, 0x10
.global __vt__Q23zen20CallBack1$$0P7P2DPane$$1
__vt__Q23zen20CallBack1$$0P7P2DPane$$1:
	.incbin "baserom.dol", 0x2D0004, 0xC
.global lbl_802D3010
lbl_802D3010:
	.incbin "baserom.dol", 0x2D0010, 0xB0
.global lbl_802D30C0
lbl_802D30C0:
	.incbin "baserom.dol", 0x2D00C0, 0x68
.global lbl_802D3128
lbl_802D3128:
	.incbin "baserom.dol", 0x2D0128, 0x70
.global bloFile_Mezame__3zen
bloFile_Mezame__3zen:
	.incbin "baserom.dol", 0x2D0198, 0x9C
.global bloFile_GetPikmin__3zen
bloFile_GetPikmin__3zen:
	.incbin "baserom.dol", 0x2D0234, 0x70
.global bloFile_StoneHint2__3zen
bloFile_StoneHint2__3zen:
	.incbin "baserom.dol", 0x2D02A4, 0x14C
.global bloFile_BombInfo__3zen
bloFile_BombInfo__3zen:
	.incbin "baserom.dol", 0x2D03F0, 0x11C
.global bloFile_NukiAndFree__3zen
bloFile_NukiAndFree__3zen:
	.incbin "baserom.dol", 0x2D050C, 0x60
.global bloFile_InfoDisplay__3zen
bloFile_InfoDisplay__3zen:
	.incbin "baserom.dol", 0x2D056C, 0x598
.global bloFile_PartsGet_ust1__3zen
bloFile_PartsGet_ust1__3zen:
	.incbin "baserom.dol", 0x2D0B04, 0xC
.global bloFile_PartsGet_ust2__3zen
bloFile_PartsGet_ust2__3zen:
	.incbin "baserom.dol", 0x2D0B10, 0xC
.global bloFile_PartsGet_ust3__3zen
bloFile_PartsGet_ust3__3zen:
	.incbin "baserom.dol", 0x2D0B1C, 0xC
.global bloFile_PartsGet_ust4__3zen
bloFile_PartsGet_ust4__3zen:
	.incbin "baserom.dol", 0x2D0B28, 0xC
.global bloFile_PartsGet_ust5__3zen
bloFile_PartsGet_ust5__3zen:
	.incbin "baserom.dol", 0x2D0B34, 0xC
.global bloFile_PartsGet_uf01__3zen
bloFile_PartsGet_uf01__3zen:
	.incbin "baserom.dol", 0x2D0B40, 0xC
.global bloFile_PartsGet_uf02__3zen
bloFile_PartsGet_uf02__3zen:
	.incbin "baserom.dol", 0x2D0B4C, 0xC
.global bloFile_PartsGet_uf03__3zen
bloFile_PartsGet_uf03__3zen:
	.incbin "baserom.dol", 0x2D0B58, 0xC
.global bloFile_PartsGet_uf04__3zen
bloFile_PartsGet_uf04__3zen:
	.incbin "baserom.dol", 0x2D0B64, 0xC
.global bloFile_PartsGet_uf05__3zen
bloFile_PartsGet_uf05__3zen:
	.incbin "baserom.dol", 0x2D0B70, 0xC
.global bloFile_PartsGet_uf06__3zen
bloFile_PartsGet_uf06__3zen:
	.incbin "baserom.dol", 0x2D0B7C, 0xC
.global bloFile_PartsGet_uf07__3zen
bloFile_PartsGet_uf07__3zen:
	.incbin "baserom.dol", 0x2D0B88, 0xC
.global bloFile_PartsGet_uf08__3zen
bloFile_PartsGet_uf08__3zen:
	.incbin "baserom.dol", 0x2D0B94, 0xC
.global bloFile_PartsGet_uf09__3zen
bloFile_PartsGet_uf09__3zen:
	.incbin "baserom.dol", 0x2D0BA0, 0xC
.global bloFile_PartsGet_uf10__3zen
bloFile_PartsGet_uf10__3zen:
	.incbin "baserom.dol", 0x2D0BAC, 0xC
.global bloFile_PartsGet_uf11__3zen
bloFile_PartsGet_uf11__3zen:
	.incbin "baserom.dol", 0x2D0BB8, 0xC
.global bloFile_PartsGet_un01__3zen
bloFile_PartsGet_un01__3zen:
	.incbin "baserom.dol", 0x2D0BC4, 0xC
.global bloFile_PartsGet_un02__3zen
bloFile_PartsGet_un02__3zen:
	.incbin "baserom.dol", 0x2D0BD0, 0xC
.global bloFile_PartsGet_un03__3zen
bloFile_PartsGet_un03__3zen:
	.incbin "baserom.dol", 0x2D0BDC, 0xC
.global bloFile_PartsGet_un04__3zen
bloFile_PartsGet_un04__3zen:
	.incbin "baserom.dol", 0x2D0BE8, 0xC
.global bloFile_PartsGet_un05__3zen
bloFile_PartsGet_un05__3zen:
	.incbin "baserom.dol", 0x2D0BF4, 0xC
.global bloFile_PartsGet_un06__3zen
bloFile_PartsGet_un06__3zen:
	.incbin "baserom.dol", 0x2D0C00, 0xC
.global bloFile_PartsGet_un07__3zen
bloFile_PartsGet_un07__3zen:
	.incbin "baserom.dol", 0x2D0C0C, 0xC
.global bloFile_PartsGet_un08__3zen
bloFile_PartsGet_un08__3zen:
	.incbin "baserom.dol", 0x2D0C18, 0xC
.global bloFile_PartsGet_un09__3zen
bloFile_PartsGet_un09__3zen:
	.incbin "baserom.dol", 0x2D0C24, 0xC
.global bloFile_PartsGet_un10__3zen
bloFile_PartsGet_un10__3zen:
	.incbin "baserom.dol", 0x2D0C30, 0xC
.global bloFile_PartsGet_un11__3zen
bloFile_PartsGet_un11__3zen:
	.incbin "baserom.dol", 0x2D0C3C, 0xC
.global bloFile_PartsGet_un12__3zen
bloFile_PartsGet_un12__3zen:
	.incbin "baserom.dol", 0x2D0C48, 0xC
.global bloFile_PartsGet_un13__3zen
bloFile_PartsGet_un13__3zen:
	.incbin "baserom.dol", 0x2D0C54, 0xC
.global bloFile_PartsGet_un14__3zen
bloFile_PartsGet_un14__3zen:
	.incbin "baserom.dol", 0x2D0C60, 0xC
.global bloFile_PartsPower_ust1__3zen
bloFile_PartsPower_ust1__3zen:
	.incbin "baserom.dol", 0x2D0C6C, 0xC
.global bloFile_PartsPower_ust2__3zen
bloFile_PartsPower_ust2__3zen:
	.incbin "baserom.dol", 0x2D0C78, 0xC
.global bloFile_PartsPower_ust3__3zen
bloFile_PartsPower_ust3__3zen:
	.incbin "baserom.dol", 0x2D0C84, 0xC
.global bloFile_PartsPower_ust4__3zen
bloFile_PartsPower_ust4__3zen:
	.incbin "baserom.dol", 0x2D0C90, 0xC
.global bloFile_PartsPower_ust5__3zen
bloFile_PartsPower_ust5__3zen:
	.incbin "baserom.dol", 0x2D0C9C, 0xC
.global bloFile_PartsPower_uf01__3zen
bloFile_PartsPower_uf01__3zen:
	.incbin "baserom.dol", 0x2D0CA8, 0xC
.global bloFile_PartsPower_uf02__3zen
bloFile_PartsPower_uf02__3zen:
	.incbin "baserom.dol", 0x2D0CB4, 0xC
.global bloFile_PartsPower_uf03__3zen
bloFile_PartsPower_uf03__3zen:
	.incbin "baserom.dol", 0x2D0CC0, 0xC
.global bloFile_PartsPower_uf04__3zen
bloFile_PartsPower_uf04__3zen:
	.incbin "baserom.dol", 0x2D0CCC, 0xC
.global bloFile_PartsPower_uf05__3zen
bloFile_PartsPower_uf05__3zen:
	.incbin "baserom.dol", 0x2D0CD8, 0xC
.global bloFile_PartsPower_uf06__3zen
bloFile_PartsPower_uf06__3zen:
	.incbin "baserom.dol", 0x2D0CE4, 0xC
.global bloFile_PartsPower_uf07__3zen
bloFile_PartsPower_uf07__3zen:
	.incbin "baserom.dol", 0x2D0CF0, 0xC
.global bloFile_PartsPower_uf08__3zen
bloFile_PartsPower_uf08__3zen:
	.incbin "baserom.dol", 0x2D0CFC, 0xC
.global bloFile_PartsPower_uf09__3zen
bloFile_PartsPower_uf09__3zen:
	.incbin "baserom.dol", 0x2D0D08, 0xC
.global bloFile_PartsPower_uf10__3zen
bloFile_PartsPower_uf10__3zen:
	.incbin "baserom.dol", 0x2D0D14, 0xC
.global bloFile_PartsPower_uf11__3zen
bloFile_PartsPower_uf11__3zen:
	.incbin "baserom.dol", 0x2D0D20, 0xC
.global bloFile_PartsPower_un01__3zen
bloFile_PartsPower_un01__3zen:
	.incbin "baserom.dol", 0x2D0D2C, 0xC
.global bloFile_PartsPower_un02__3zen
bloFile_PartsPower_un02__3zen:
	.incbin "baserom.dol", 0x2D0D38, 0xC
.global bloFile_PartsPower_un03__3zen
bloFile_PartsPower_un03__3zen:
	.incbin "baserom.dol", 0x2D0D44, 0xC
.global bloFile_PartsPower_un04__3zen
bloFile_PartsPower_un04__3zen:
	.incbin "baserom.dol", 0x2D0D50, 0xC
.global bloFile_PartsPower_un05__3zen
bloFile_PartsPower_un05__3zen:
	.incbin "baserom.dol", 0x2D0D5C, 0xC
.global bloFile_PartsPower_un06__3zen
bloFile_PartsPower_un06__3zen:
	.incbin "baserom.dol", 0x2D0D68, 0xC
.global bloFile_PartsPower_un07__3zen
bloFile_PartsPower_un07__3zen:
	.incbin "baserom.dol", 0x2D0D74, 0xC
.global bloFile_PartsPower_un08__3zen
bloFile_PartsPower_un08__3zen:
	.incbin "baserom.dol", 0x2D0D80, 0xC
.global bloFile_PartsPower_un09__3zen
bloFile_PartsPower_un09__3zen:
	.incbin "baserom.dol", 0x2D0D8C, 0xC
.global bloFile_PartsPower_un10__3zen
bloFile_PartsPower_un10__3zen:
	.incbin "baserom.dol", 0x2D0D98, 0xC
.global bloFile_PartsPower_un11__3zen
bloFile_PartsPower_un11__3zen:
	.incbin "baserom.dol", 0x2D0DA4, 0xC
.global bloFile_PartsPower_un12__3zen
bloFile_PartsPower_un12__3zen:
	.incbin "baserom.dol", 0x2D0DB0, 0xC
.global bloFile_PartsPower_un13__3zen
bloFile_PartsPower_un13__3zen:
	.incbin "baserom.dol", 0x2D0DBC, 0xC
.global bloFile_PartsPower_un14__3zen
bloFile_PartsPower_un14__3zen:
	.incbin "baserom.dol", 0x2D0DC8, 0x24
.global bloFiles_Tutorial__3zen
bloFiles_Tutorial__3zen:
	.incbin "baserom.dol", 0x2D0DEC, 0x26C
.global lbl_802D4058
lbl_802D4058:
	.incbin "baserom.dol", 0x2D1058, 0x14
.global lbl_802D406C
lbl_802D406C:
	.incbin "baserom.dol", 0x2D106C, 0x1C
.global lbl_802D4088
lbl_802D4088:
	.incbin "baserom.dol", 0x2D1088, 0xD88
.global bloFile_Res_Table__3zen
bloFile_Res_Table__3zen:
	.incbin "baserom.dol", 0x2D1E10, 0x254
.global dummy_blo_num_table__3zen
dummy_blo_num_table__3zen:
	.incbin "baserom.dol", 0x2D2064, 0x54
.global lbl_802D50B8
lbl_802D50B8:
	.incbin "baserom.dol", 0x2D20B8, 0x1C
.global map_area_data__3zen
map_area_data__3zen:
	.incbin "baserom.dol", 0x2D20D4, 0xB4
.global lbl_802D5188
lbl_802D5188:
	.incbin "baserom.dol", 0x2D2188, 0x28
.global lbl_802D51B0
lbl_802D51B0:
	.incbin "baserom.dol", 0x2D21B0, 0x130
.global sjis_convert_table_1
sjis_convert_table_1:
	.incbin "baserom.dol", 0x2D22E0, 0x4C0
.global kanji_convert_table_1
kanji_convert_table_1:
	.incbin "baserom.dol", 0x2D27A0, 0x4C0
.global lbl_802D5C60
lbl_802D5C60:
	.incbin "baserom.dol", 0x2D2C60, 0x68
.global lbl_802D5CC8
lbl_802D5CC8:
	.incbin "baserom.dol", 0x2D2CC8, 0x18
.global lbl_802D5CE0
lbl_802D5CE0:
	.incbin "baserom.dol", 0x2D2CE0, 0x18
.global lbl_802D5CF8
lbl_802D5CF8:
	.incbin "baserom.dol", 0x2D2CF8, 0x4C
.global lbl_802D5D44
lbl_802D5D44:
	.incbin "baserom.dol", 0x2D2D44, 0x4C
.global lbl_802D5D90
lbl_802D5D90:
	.incbin "baserom.dol", 0x2D2D90, 0x38
.global lbl_802D5DC8
lbl_802D5DC8:
	.incbin "baserom.dol", 0x2D2DC8, 0x20
.global lbl_802D5DE8
lbl_802D5DE8:
	.incbin "baserom.dol", 0x2D2DE8, 0xC
.global lbl_802D5DF4
lbl_802D5DF4:
	.incbin "baserom.dol", 0x2D2DF4, 0x18
.global lbl_802D5E0C
lbl_802D5E0C:
	.incbin "baserom.dol", 0x2D2E0C, 0x10
.global lbl_802D5E1C
lbl_802D5E1C:
	.incbin "baserom.dol", 0x2D2E1C, 0x18
.global lbl_802D5E34
lbl_802D5E34:
	.incbin "baserom.dol", 0x2D2E34, 0x18
.global lbl_802D5E4C
lbl_802D5E4C:
	.incbin "baserom.dol", 0x2D2E4C, 0x1C
.global lbl_802D5E68
lbl_802D5E68:
	.incbin "baserom.dol", 0x2D2E68, 0x1C
.global RotateAngleData__3zen
RotateAngleData__3zen:
	.incbin "baserom.dol", 0x2D2E84, 0x80
.global pane_name$1940
pane_name$1940:
	.incbin "baserom.dol", 0x2D2F04, 0x24
.global pane_name2$1941
pane_name2$1941:
	.incbin "baserom.dol", 0x2D2F28, 0x24
.global pane_name3$1942
pane_name3$1942:
	.incbin "baserom.dol", 0x2D2F4C, 0x24
.global pane_name4$1943
pane_name4$1943:
	.incbin "baserom.dol", 0x2D2F70, 0x3C
.global lbl_802D5FAC
lbl_802D5FAC:
	.incbin "baserom.dol", 0x2D2FAC, 0x64
.global lbl_802D6010
lbl_802D6010:
	.incbin "baserom.dol", 0x2D3010, 0x18
.global lbl_802D6028
lbl_802D6028:
	.incbin "baserom.dol", 0x2D3028, 0x18
.global lbl_802D6040
lbl_802D6040:
	.incbin "baserom.dol", 0x2D3040, 0x18
.global lbl_802D6058
lbl_802D6058:
	.incbin "baserom.dol", 0x2D3058, 0x18
.global lbl_802D6070
lbl_802D6070:
	.incbin "baserom.dol", 0x2D3070, 0x64
.global lbl_802D60D4
lbl_802D60D4:
	.incbin "baserom.dol", 0x2D30D4, 0x4C
.global lbl_802D6120
lbl_802D6120:
	.incbin "baserom.dol", 0x2D3120, 0x20
.global LinePointB__3zen
LinePointB__3zen:
	.incbin "baserom.dol", 0x2D3140, 0x40
.global LinePointR__3zen
LinePointR__3zen:
	.incbin "baserom.dol", 0x2D3180, 0x40
.global LinePointY__3zen
LinePointY__3zen:
	.incbin "baserom.dol", 0x2D31C0, 0x40
.global ogawa_per_line__3zen
ogawa_per_line__3zen:
	.incbin "baserom.dol", 0x2D3200, 0x20
.global og_piki_lines_color__3zen
og_piki_lines_color__3zen:
	.incbin "baserom.dol", 0x2D3220, 0x10
.global lbl_802D6230
lbl_802D6230:
	.incbin "baserom.dol", 0x2D3230, 0xC4
.global __vt__Q23zen17TextColorCallBack
__vt__Q23zen17TextColorCallBack:
	.incbin "baserom.dol", 0x2D32F4, 0x2C
.global lbl_802D6320
lbl_802D6320:
	.incbin "baserom.dol", 0x2D3320, 0x1EC
.global lbl_802D650C
lbl_802D650C:
	.incbin "baserom.dol", 0x2D350C, 0x84
.global __vt__Q23zen17particleGenerator
__vt__Q23zen17particleGenerator:
	.incbin "baserom.dol", 0x2D3590, 0x3C
.global __vt__12CMresultMode
__vt__12CMresultMode:
	.incbin "baserom.dol", 0x2D35CC, 0x28
.global __vt__11HurryUpMode
__vt__11HurryUpMode:
	.incbin "baserom.dol", 0x2D35F4, 0x2C
.global __vt__12GameInfoMode
__vt__12GameInfoMode:
	.incbin "baserom.dol", 0x2D3620, 0x2C
.global __vt__15ProgressiveMode
__vt__15ProgressiveMode:
	.incbin "baserom.dol", 0x2D364C, 0x2C
.global __vt__13CountDownMode
__vt__13CountDownMode:
	.incbin "baserom.dol", 0x2D3678, 0x2C
.global __vt__12GameOverMode
__vt__12GameOverMode:
	.incbin "baserom.dol", 0x2D36A4, 0x2C
.global __vt__13ContainerMode
__vt__13ContainerMode:
	.incbin "baserom.dol", 0x2D36D0, 0x28
.global __vt__11WMPauseMode
__vt__11WMPauseMode:
	.incbin "baserom.dol", 0x2D36F8, 0x2C
.global __vt__12WorldMapMode
__vt__12WorldMapMode:
	.incbin "baserom.dol", 0x2D3724, 0x30
.global __vt__18CMcourseSelectMode
__vt__18CMcourseSelectMode:
	.incbin "baserom.dol", 0x2D3754, 0x28
.global __vt__11HiScoreMode
__vt__11HiScoreMode:
	.incbin "baserom.dol", 0x2D377C, 0x2C
.global __vt__12UfoPartsMode
__vt__12UfoPartsMode:
	.incbin "baserom.dol", 0x2D37A8, 0x28
.global __vt__11SaveMesMode
__vt__11SaveMesMode:
	.incbin "baserom.dol", 0x2D37D0, 0x2C
.global __vt__15SaveFailureMode
__vt__15SaveFailureMode:
	.incbin "baserom.dol", 0x2D37FC, 0x2C
.global __vt__15FinalResultMode
__vt__15FinalResultMode:
	.incbin "baserom.dol", 0x2D3828, 0x10
.global __vt__12GameModeBase
__vt__12GameModeBase:
	.incbin "baserom.dol", 0x2D3838, 0x5C
.global __vt__41Delegate1$$021GameCourseClearScreen$$4R4Menu$$1
__vt__41Delegate1$$021GameCourseClearScreen$$4R4Menu$$1:
	.incbin "baserom.dol", 0x2D3894, 0x48
.global __vt__Q23zen7zenList
__vt__Q23zen7zenList:
	.incbin "baserom.dol", 0x2D38DC, 0xA4
.global __vt__21GameCourseClearScreen
__vt__21GameCourseClearScreen:
	.incbin "baserom.dol", 0x2D3980, 0x70
.global __vt__22GameCourseClearSection
__vt__22GameCourseClearSection:
	.incbin "baserom.dol", 0x2D39F0, 0x94
.global lbl_802D6A84
lbl_802D6A84:
	.incbin "baserom.dol", 0x2D3A84, 0xA0
.global __vt__21GameStageClearSection
__vt__21GameStageClearSection:
	.incbin "baserom.dol", 0x2D3B24, 0x90
.global lbl_802D6BB4
lbl_802D6BB4:
	.incbin "baserom.dol", 0x2D3BB4, 0xA0
.global __vt__18GameCreditsSection
__vt__18GameCreditsSection:
	.incbin "baserom.dol", 0x2D3C54, 0x6C
.global lbl_802D6CC0
lbl_802D6CC0:
	.incbin "baserom.dol", 0x2D3CC0, 0x2770
.global ptclLoadInfo
ptclLoadInfo:
	.incbin "baserom.dol", 0x2D6430, 0xFE4
.global geometryLoadInfo
geometryLoadInfo:
	.incbin "baserom.dol", 0x2D7414, 0x30
.global simplePtclLoadInfo
simplePtclLoadInfo:
	.incbin "baserom.dol", 0x2D7444, 0x6C
.global __vt__10EffShpInst
__vt__10EffShpInst:
	.incbin "baserom.dol", 0x2D74B0, 0x50
.global __vt__9EffectMgr
__vt__9EffectMgr:
	.incbin "baserom.dol", 0x2D7500, 0x2C
.global __vt__26EffectGeometryRegistration
__vt__26EffectGeometryRegistration:
	.incbin "baserom.dol", 0x2D752C, 0x2C
.global __vt__11EffectShape
__vt__11EffectShape:
	.incbin "baserom.dol", 0x2D7558, 0x2C
.global __vt__26EffectParticleRegistration
__vt__26EffectParticleRegistration:
	.incbin "baserom.dol", 0x2D7584, 0x4C
.global __vt__12SmokeEmitter
__vt__12SmokeEmitter:
	.incbin "baserom.dol", 0x2D75D0, 0x50
.global lbl_802DA620
lbl_802DA620:
	.incbin "baserom.dol", 0x2D7620, 0x40
.global lpsPos
lpsPos:
	.incbin "baserom.dol", 0x2D7660, 0x9C
.global lbl_802DA6FC
lbl_802DA6FC:
	.incbin "baserom.dol", 0x2D76FC, 0x6C
.global __vt__Q23zen7PCRData
__vt__Q23zen7PCRData:
	.incbin "baserom.dol", 0x2D7768, 0x20
.global ami
ami:
	.incbin "baserom.dol", 0x2D7788, 0x800
.global check
check:
	.incbin "baserom.dol", 0x2D7F88, 0x800
.global cloud
cloud:
	.incbin "baserom.dol", 0x2D8788, 0x800
.global marble
marble:
	.incbin "baserom.dol", 0x2D8F88, 0x800
.global noise
noise:
	.incbin "baserom.dol", 0x2D9788, 0x800
.global yura
yura:
	.incbin "baserom.dol", 0x2D9F88, 0x800
.global UseSolidTex__3zen
UseSolidTex__3zen:
	.incbin "baserom.dol", 0x2DA788, 0xA0
.global __vt__Q23zen11particleMdl
__vt__Q23zen11particleMdl:
	.incbin "baserom.dol", 0x2DA828, 0x20
.global __vt__Q23zen15particleMdlBase
__vt__Q23zen15particleMdlBase:
	.incbin "baserom.dol", 0x2DA848, 0x3C
.global __vt__Q23zen16particleChildMdl
__vt__Q23zen16particleChildMdl:
	.incbin "baserom.dol", 0x2DA884, 0x160
.global __vt__5YTeki
__vt__5YTeki:
	.incbin "baserom.dol", 0x2DA9E4, 0x258
.global __vt__28TAIeffectAttackEventCallBack
__vt__28TAIeffectAttackEventCallBack:
	.incbin "baserom.dol", 0x2DAC3C, 0x34
.global lbl_802DDC70
lbl_802DDC70:
	.incbin "baserom.dol", 0x2DAC70, 0x1CC
.global __vt__16TAItankAnimation
__vt__16TAItankAnimation:
	.incbin "baserom.dol", 0x2DAE3C, 0x58
.global __vt__15TAItankStrategy
__vt__15TAItankStrategy:
	.incbin "baserom.dol", 0x2DAE94, 0x50
.global __vt__14TAIAnoReaction
__vt__14TAIAnoReaction:
	.incbin "baserom.dol", 0x2DAEE4, 0x38
.global __vt__12TAIAinitTank
__vt__12TAIAinitTank:
	.incbin "baserom.dol", 0x2DAF1C, 0x40
.global __vt__20TAIAoutsideTerritory
__vt__20TAIAoutsideTerritory:
	.incbin "baserom.dol", 0x2DAF5C, 0x88
.global __vt__16TAIAflickingTank
__vt__16TAIAflickingTank:
	.incbin "baserom.dol", 0x2DAFE4, 0x98
.global __vt__18TAIAfireBreathTank
__vt__18TAIAfireBreathTank:
	.incbin "baserom.dol", 0x2DB07C, 0x54
.global __vt__10FireEffect
__vt__10FireEffect:
	.incbin "baserom.dol", 0x2DB0D0, 0xC
.global __vt__Q23zen17CallBack1$$0R4Teki$$1
__vt__Q23zen17CallBack1$$0R4Teki$$1:
	.incbin "baserom.dol", 0x2DB0DC, 0x60
.global __vt__16TAIAstepBackTank
__vt__16TAIAstepBackTank:
	.incbin "baserom.dol", 0x2DB13C, 0xB0
.global __vt__28TAIAoutsideOptionalRangeTank
__vt__28TAIAoutsideOptionalRangeTank:
	.incbin "baserom.dol", 0x2DB1EC, 0x7C
.global __vt__25TAIAattackableAngleTarget
__vt__25TAIAattackableAngleTarget:
	.incbin "baserom.dol", 0x2DB268, 0xA4
.global __vt__14TAIApatrolTank
__vt__14TAIApatrolTank:
	.incbin "baserom.dol", 0x2DB30C, 0xD0
.global __vt__17TAItankParameters
__vt__17TAItankParameters:
	.incbin "baserom.dol", 0x2DB3DC, 0x80
.global __vt__32TAIeffectAttackEventCallBackTank
__vt__32TAIeffectAttackEventCallBackTank:
	.incbin "baserom.dol", 0x2DB45C, 0x84
.global lbl_802DE4E0
lbl_802DE4E0:
	.incbin "baserom.dol", 0x2DB4E0, 0x268
.global __vt__15TAImarAnimation
__vt__15TAImarAnimation:
	.incbin "baserom.dol", 0x2DB748, 0x58
.global __vt__14TAImarStrategy
__vt__14TAImarStrategy:
	.incbin "baserom.dol", 0x2DB7A0, 0x4C
.global __vt__11TAIAinitMar
__vt__11TAIAinitMar:
	.incbin "baserom.dol", 0x2DB7EC, 0x38
.global __vt__13TAIAwatchNavi
__vt__13TAIAwatchNavi:
	.incbin "baserom.dol", 0x2DB824, 0x108
.global __vt__32TAIAflyingDistanceInTerritoryMar
__vt__32TAIAflyingDistanceInTerritoryMar:
	.incbin "baserom.dol", 0x2DB92C, 0xC8
.global __vt__17TAIAfireBreathMar
__vt__17TAIAfireBreathMar:
	.incbin "baserom.dol", 0x2DB9F4, 0x58
.global __vt__12BreathEffect
__vt__12BreathEffect:
	.incbin "baserom.dol", 0x2DBA4C, 0x74
.global __vt__21TAIAflyingDistanceMar
__vt__21TAIAflyingDistanceMar:
	.incbin "baserom.dol", 0x2DBAC0, 0x30
.global __vt__14FlyingDistance
__vt__14FlyingDistance:
	.incbin "baserom.dol", 0x2DBAF0, 0x54
.global __vt__19TAIAtimerTakeOffMar
__vt__19TAIAtimerTakeOffMar:
	.incbin "baserom.dol", 0x2DBB44, 0x20
.global __vt__17TAIAtimerReaction
__vt__17TAIAtimerReaction:
	.incbin "baserom.dol", 0x2DBB64, 0x6C
.global __vt__14TAIAtakeOffMar
__vt__14TAIAtakeOffMar:
	.incbin "baserom.dol", 0x2DBBD0, 0xA0
.global __vt__19TAIAstickingPikiMar
__vt__19TAIAstickingPikiMar:
	.incbin "baserom.dol", 0x2DBC70, 0x64
.global __vt__17TAIAflickCheckMar
__vt__17TAIAflickCheckMar:
	.incbin "baserom.dol", 0x2DBCD4, 0x6C
.global __vt__14TAIAlandingMar
__vt__14TAIAlandingMar:
	.incbin "baserom.dol", 0x2DBD40, 0x4C
.global __vt__22TAIAstickingPikiMarFly
__vt__22TAIAstickingPikiMarFly:
	.incbin "baserom.dol", 0x2DBD8C, 0x88
.global __vt__15TAIAflickingMar
__vt__15TAIAflickingMar:
	.incbin "baserom.dol", 0x2DBE14, 0x80
.global __vt__22TAIAflickCheckTimerMar
__vt__22TAIAflickCheckTimerMar:
	.incbin "baserom.dol", 0x2DBE94, 0xA0
.global __vt__17TAIAflyingBaseMar
__vt__17TAIAflyingBaseMar:
	.incbin "baserom.dol", 0x2DBF34, 0x6C
.global __vt__12TAIAdyingMar
__vt__12TAIAdyingMar:
	.incbin "baserom.dol", 0x2DBFA0, 0xC8
.global __vt__16TAImarParameters
__vt__16TAImarParameters:
	.incbin "baserom.dol", 0x2DC068, 0x7C
.global __vt__31TAIeffectAttackEventCallBackMar
__vt__31TAIeffectAttackEventCallBackMar:
	.incbin "baserom.dol", 0x2DC0E4, 0xBC
.global __vt__17TAIAinWaterDamage
__vt__17TAIAinWaterDamage:
	.incbin "baserom.dol", 0x2DC1A0, 0x1C
.global __vt__11TAIAinWater
__vt__11TAIAinWater:
	.incbin "baserom.dol", 0x2DC1BC, 0x34
.global __vt__10TAIAdamage
__vt__10TAIAdamage:
	.incbin "baserom.dol", 0x2DC1F0, 0xC4
.global __vt__21TAIAdyingCrushKabekui
__vt__21TAIAdyingCrushKabekui:
	.incbin "baserom.dol", 0x2DC2B4, 0x1C
.global __vt__16TAIAdyingKabekui
__vt__16TAIAdyingKabekui:
	.incbin "baserom.dol", 0x2DC2D0, 0x1C
.global __vt__9TAIAdying
__vt__9TAIAdying:
	.incbin "baserom.dol", 0x2DC2EC, 0x28
.global __vt__7TAIAdie
__vt__7TAIAdie:
	.incbin "baserom.dol", 0x2DC314, 0x38
.global __vt__13TAIAdeadCheck
__vt__13TAIAdeadCheck:
	.incbin "baserom.dol", 0x2DC34C, 0x40
.global __vt__22TAIAhitCheckFlyingPiki
__vt__22TAIAhitCheckFlyingPiki:
	.incbin "baserom.dol", 0x2DC38C, 0x84
.global __vt__11TAIAtakeOff
__vt__11TAIAtakeOff:
	.incbin "baserom.dol", 0x2DC410, 0x40
.global __vt__11TAIAlanding
__vt__11TAIAlanding:
	.incbin "baserom.dol", 0x2DC450, 0x40
.global __vt__11TAIAdescent
__vt__11TAIAdescent:
	.incbin "baserom.dol", 0x2DC490, 0x5C
.global __vt__18TAIAflyingDistance
__vt__18TAIAflyingDistance:
	.incbin "baserom.dol", 0x2DC4EC, 0x98
.global __vt__29TAIAflyingDistanceInTerritory
__vt__29TAIAflyingDistanceInTerritory:
	.incbin "baserom.dol", 0x2DC584, 0x30
.global __vt__16TAIAflyingToGoal
__vt__16TAIAflyingToGoal:
	.incbin "baserom.dol", 0x2DC5B4, 0x48
.global __vt__21TAIAflyingInTerritory
__vt__21TAIAflyingInTerritory:
	.incbin "baserom.dol", 0x2DC5FC, 0x38
.global __vt__14TAIAflyingBase
__vt__14TAIAflyingBase:
	.incbin "baserom.dol", 0x2DC634, 0x54
.global __vt__28TAIAgoingHomePriorityFaceDir
__vt__28TAIAgoingHomePriorityFaceDir:
	.incbin "baserom.dol", 0x2DC688, 0x40
.global __vt__13TAIAgoingHome
__vt__13TAIAgoingHome:
	.incbin "baserom.dol", 0x2DC6C8, 0x70
.global __vt__12TAIAturnHome
__vt__12TAIAturnHome:
	.incbin "baserom.dol", 0x2DC738, 0x40
.global __vt__12TAIAstepBack
__vt__12TAIAstepBack:
	.incbin "baserom.dol", 0x2DC778, 0x70
.global __vt__10TAIApatrol
__vt__10TAIApatrol:
	.incbin "baserom.dol", 0x2DC7E8, 0x44
.global __vt__8TAIAwait
__vt__8TAIAwait:
	.incbin "baserom.dol", 0x2DC82C, 0x54
.global __vt__21TAIAturnFocusCreature
__vt__21TAIAturnFocusCreature:
	.incbin "baserom.dol", 0x2DC880, 0x20
.global __vt__16TAIAturnOccasion
__vt__16TAIAturnOccasion:
	.incbin "baserom.dol", 0x2DC8A0, 0x40
.global __vt__14TAIArandomWalk
__vt__14TAIArandomWalk:
	.incbin "baserom.dol", 0x2DC8E0, 0x34
.global __vt__8TAIAstop
__vt__8TAIAstop:
	.incbin "baserom.dol", 0x2DC914, 0x1C
.global __vt__16TAIAturnToTarget
__vt__16TAIAturnToTarget:
	.incbin "baserom.dol", 0x2DC930, 0x44
.global __vt__14TAIAlookAround
__vt__14TAIAlookAround:
	.incbin "baserom.dol", 0x2DC974, 0x54
.global __vt__33TAIAapproachTargetPriorityFaceDir
__vt__33TAIAapproachTargetPriorityFaceDir:
	.incbin "baserom.dol", 0x2DC9C8, 0x50
.global __vt__27TAIAgoTargetPriorityFaceDir
__vt__27TAIAgoTargetPriorityFaceDir:
	.incbin "baserom.dol", 0x2DCA18, 0x48
.global __vt__12TAIAgoTarget
__vt__12TAIAgoTarget:
	.incbin "baserom.dol", 0x2DCA60, 0x48
.global __vt__24TAIAsetTargetPointCircle
__vt__24TAIAsetTargetPointCircle:
	.incbin "baserom.dol", 0x2DCAA8, 0x48
.global __vt__30TAIAsetTargetPointCircleRandom
__vt__30TAIAsetTargetPointCircleRandom:
	.incbin "baserom.dol", 0x2DCAF0, 0x48
.global __vt__14TAIAgoGoalPath
__vt__14TAIAgoGoalPath:
	.incbin "baserom.dol", 0x2DCB38, 0x50
.global __vt__28TAIAsetTargetPointWorkObject
__vt__28TAIAsetTargetPointWorkObject:
	.incbin "baserom.dol", 0x2DCB88, 0x8C
.global __vt__17TAIAappearKabekui
__vt__17TAIAappearKabekui:
	.incbin "baserom.dol", 0x2DCC14, 0x88
.global __vt__14TAIAmotionLoop
__vt__14TAIAmotionLoop:
	.incbin "baserom.dol", 0x2DCC9C, 0x20
.global __vt__17TAIAreserveMotion
__vt__17TAIAreserveMotion:
	.incbin "baserom.dol", 0x2DCCBC, 0x28
.global __vt__10TAIAmotion
__vt__10TAIAmotion:
	.incbin "baserom.dol", 0x2DCCE4, 0x84
.global __vt__18TAIAcheckTurnAngle
__vt__18TAIAcheckTurnAngle:
	.incbin "baserom.dol", 0x2DCD68, 0x3C
.global __vt__18TAIAdistanceTarget
__vt__18TAIAdistanceTarget:
	.incbin "baserom.dol", 0x2DCDA4, 0x7C
.global __vt__16TAIAstickingPiki
__vt__16TAIAstickingPiki:
	.incbin "baserom.dol", 0x2DCE20, 0x40
.global __vt__19TAIAunvisibleTarget
__vt__19TAIAunvisibleTarget:
	.incbin "baserom.dol", 0x2DCE60, 0x40
.global __vt__20TAIAattackableTarget
__vt__20TAIAattackableTarget:
	.incbin "baserom.dol", 0x2DCEA0, 0x3C
.global __vt__15TAIAvisiblePiki
__vt__15TAIAvisiblePiki:
	.incbin "baserom.dol", 0x2DCEDC, 0x38
.global __vt__15TAIAvisibleNavi
__vt__15TAIAvisibleNavi:
	.incbin "baserom.dol", 0x2DCF14, 0x48
.global __vt__29TAIAoutsideTerritoryRangeNavi
__vt__29TAIAoutsideTerritoryRangeNavi:
	.incbin "baserom.dol", 0x2DCF5C, 0x48
.global __vt__28TAIAinsideTerritoryRangeNavi
__vt__28TAIAinsideTerritoryRangeNavi:
	.incbin "baserom.dol", 0x2DCFA4, 0x44
.global __vt__24TAIAcheckInsideRangePiki
__vt__24TAIAcheckInsideRangePiki:
	.incbin "baserom.dol", 0x2DCFE8, 0x78
.global __vt__24TAIAoutsideOptionalRange
__vt__24TAIAoutsideOptionalRange:
	.incbin "baserom.dol", 0x2DD060, 0x54
.global __vt__23TAIAinsideOptionalRange
__vt__23TAIAinsideOptionalRange:
	.incbin "baserom.dol", 0x2DD0B4, 0x28
.global __vt__22TAIAjudgeOptionalRange
__vt__22TAIAjudgeOptionalRange:
	.incbin "baserom.dol", 0x2DD0DC, 0x68
.global __vt__12TAIAmoreLife
__vt__12TAIAmoreLife:
	.incbin "baserom.dol", 0x2DD144, 0x44
.global __vt__12TAIAlessLife
__vt__12TAIAlessLife:
	.incbin "baserom.dol", 0x2DD188, 0x44
.global __vt__20TAIAsearchWorkObject
__vt__20TAIAsearchWorkObject:
	.incbin "baserom.dol", 0x2DD1CC, 0x84
.global __vt__11TAIAeatPiki
__vt__11TAIAeatPiki:
	.incbin "baserom.dol", 0x2DD250, 0x48
.global __vt__18TAIAbiteForKabekui
__vt__18TAIAbiteForKabekui:
	.incbin "baserom.dol", 0x2DD298, 0x54
.global __vt__25TAIAflickingReserveMotion
__vt__25TAIAflickingReserveMotion:
	.incbin "baserom.dol", 0x2DD2EC, 0x60
.global __vt__12TAIAflicking
__vt__12TAIAflicking:
	.incbin "baserom.dol", 0x2DD34C, 0x80
.global __vt__14TAIAflickCheck
__vt__14TAIAflickCheck:
	.incbin "baserom.dol", 0x2DD3CC, 0x44
.global __vt__14TAIAfireBreath
__vt__14TAIAfireBreath:
	.incbin "baserom.dol", 0x2DD410, 0x40
.global __vt__14TAIAtargetPiki
__vt__14TAIAtargetPiki:
	.incbin "baserom.dol", 0x2DD450, 0x38
.global __vt__14TAIAtargetNavi
__vt__14TAIAtargetNavi:
	.incbin "baserom.dol", 0x2DD488, 0x78
.global __vt__27TAIAflickingAfterMotionLoop
__vt__27TAIAflickingAfterMotionLoop:
	.incbin "baserom.dol", 0x2DD500, 0x88
.global __vt__20TAIAattackWorkObject
__vt__20TAIAattackWorkObject:
	.incbin "baserom.dol", 0x2DD588, 0x4C
.global __vt__14P2DGrafContext
__vt__14P2DGrafContext:
	.incbin "baserom.dol", 0x2DD5D4, 0x50
.global __vt__13P2DOrthoGraph
__vt__13P2DOrthoGraph:
	.incbin "baserom.dol", 0x2DD624, 0x74
.global __vt__13P2DPerspGraph
__vt__13P2DPerspGraph:
	.incbin "baserom.dol", 0x2DD698, 0x28
.global __vt__7P2DPane
__vt__7P2DPane:
	.incbin "baserom.dol", 0x2DD6C0, 0x68
.global __vt__10P2DPicture
__vt__10P2DPicture:
	.incbin "baserom.dol", 0x2DD728, 0x5C
.global lbl_802E0784
lbl_802E0784:
	.incbin "baserom.dol", 0x2DD784, 0x5C
.global __vt__9P2DScreen
__vt__9P2DScreen:
	.incbin "baserom.dol", 0x2DD7E0, 0x68
.global __vt__9P2DWindow
__vt__9P2DWindow:
	.incbin "baserom.dol", 0x2DD848, 0x68
.global __vt__10P2DTextBox
__vt__10P2DTextBox:
	.incbin "baserom.dol", 0x2DD8B0, 0x40
.global lbl_802E08F0
lbl_802E08F0:
	.incbin "baserom.dol", 0x2DD8F0, 0x6C
.global lbl_802E095C
lbl_802E095C:
	.incbin "baserom.dol", 0x2DD95C, 0x30
.global __vt__10FntobjInfo
__vt__10FntobjInfo:
	.incbin "baserom.dol", 0x2DD98C, 0x24
.global lbl_802E09B0
lbl_802E09B0:
	.incbin "baserom.dol", 0x2DD9B0, 0x1EC
.global pikiTexNametable__9$$2unnamed$$2
pikiTexNametable__9$$2unnamed$$2:
	.incbin "baserom.dol", 0x2DDB9C, 0x14C
.global __vt__Q29$$2unnamed$$212DateCallBack
__vt__Q29$$2unnamed$$212DateCallBack:
	.incbin "baserom.dol", 0x2DDCE8, 0x4C
.global __vt__Q29$$2unnamed$$217LifePinchCallBack
__vt__Q29$$2unnamed$$217LifePinchCallBack:
	.incbin "baserom.dol", 0x2DDD34, 0x48
.global __vt__Q29$$2unnamed$$216LifeIconCallBack
__vt__Q29$$2unnamed$$216LifeIconCallBack:
	.incbin "baserom.dol", 0x2DDD7C, 0x48
.global __vt__Q29$$2unnamed$$215NaviTexCallBack
__vt__Q29$$2unnamed$$215NaviTexCallBack:
	.incbin "baserom.dol", 0x2DDDC4, 0x48
.global __vt__Q29$$2unnamed$$216NaviIconCallBack
__vt__Q29$$2unnamed$$216NaviIconCallBack:
	.incbin "baserom.dol", 0x2DDE0C, 0x64
.global __vt__Q29$$2unnamed$$216MoonIconCallBack
__vt__Q29$$2unnamed$$216MoonIconCallBack:
	.incbin "baserom.dol", 0x2DDE70, 0x6C
.global __vt__Q29$$2unnamed$$216SunIcon2CallBack
__vt__Q29$$2unnamed$$216SunIcon2CallBack:
	.incbin "baserom.dol", 0x2DDEDC, 0x50
.global __vt__Q29$$2unnamed$$216SunIcon1CallBack
__vt__Q29$$2unnamed$$216SunIcon1CallBack:
	.incbin "baserom.dol", 0x2DDF2C, 0x4C
.global __vt__Q29$$2unnamed$$218SunCapsuleCallBack
__vt__Q29$$2unnamed$$218SunCapsuleCallBack:
	.incbin "baserom.dol", 0x2DDF78, 0x50
.global __vt__Q29$$2unnamed$$215SunBaseCallBack
__vt__Q29$$2unnamed$$215SunBaseCallBack:
	.incbin "baserom.dol", 0x2DDFC8, 0x8C
.global __vt__Q23zen20NumberPicCallBack$$0s$$1
__vt__Q23zen20NumberPicCallBack$$0s$$1:
	.incbin "baserom.dol", 0x2DE054, 0x50
.global __vt__Q29$$2unnamed$$223MapPikminWindowCallBack
__vt__Q29$$2unnamed$$223MapPikminWindowCallBack:
	.incbin "baserom.dol", 0x2DE0A4, 0x48
.global __vt__Q29$$2unnamed$$216PikiIconCallBack
__vt__Q29$$2unnamed$$216PikiIconCallBack:
	.incbin "baserom.dol", 0x2DE0EC, 0x2C
.global lbl_802E1118
lbl_802E1118:
	.incbin "baserom.dol", 0x2DE118, 0x1D0
.global __vt__Q23zen13StickCallBack
__vt__Q23zen13StickCallBack:
	.incbin "baserom.dol", 0x2DE2E8, 0x64
.global __vt__Q23zen15ArrowLRCallBack
__vt__Q23zen15ArrowLRCallBack:
	.incbin "baserom.dol", 0x2DE34C, 0x50
.global __vt__Q23zen19ArrowCenterCallBack
__vt__Q23zen19ArrowCenterCallBack:
	.incbin "baserom.dol", 0x2DE39C, 0x108
.global lbl_802E14A4
lbl_802E14A4:
	.incbin "baserom.dol", 0x2DE4A4, 0xC
.global lbl_802E14B0
lbl_802E14B0:
	.incbin "baserom.dol", 0x2DE4B0, 0x94
.global __vt__Q23zen11BalloonPane
__vt__Q23zen11BalloonPane:
	.incbin "baserom.dol", 0x2DE544, 0x3C
.global __vt__Q23zen10DrawScreen
__vt__Q23zen10DrawScreen:
	.incbin "baserom.dol", 0x2DE580, 0x10
.global lbl_802E1590
lbl_802E1590:
	.incbin "baserom.dol", 0x2DE590, 0x34
.global lbl_802E15C4
lbl_802E15C4:
	.incbin "baserom.dol", 0x2DE5C4, 0x48
.global __vt__Q23zen11DrawAccount
__vt__Q23zen11DrawAccount:
	.incbin "baserom.dol", 0x2DE60C, 0x15C
.global __vt__Q23zen8DrawMenu
__vt__Q23zen8DrawMenu:
	.incbin "baserom.dol", 0x2DE768, 0x80
.global __vt__16ConeTypeCallBack
__vt__16ConeTypeCallBack:
	.incbin "baserom.dol", 0x2DE7E8, 0x30
.global __vt__20CylinderTypeCallBack
__vt__20CylinderTypeCallBack:
	.incbin "baserom.dol", 0x2DE818, 0x2C
.global __vt__17EventTypeCallBack
__vt__17EventTypeCallBack:
	.incbin "baserom.dol", 0x2DE844, 0xC
.global lbl_802E1850
lbl_802E1850:
	.incbin "baserom.dol", 0x2DE850, 0xA4
.global __vt__18TAIbeatleAnimation
__vt__18TAIbeatleAnimation:
	.incbin "baserom.dol", 0x2DE8F4, 0x5C
.global __vt__17TAIbeatleStrategy
__vt__17TAIbeatleStrategy:
	.incbin "baserom.dol", 0x2DE950, 0x90
.global __vt__30TAIAcheckInsideRangePikiBeatle
__vt__30TAIAcheckInsideRangePikiBeatle:
	.incbin "baserom.dol", 0x2DE9E0, 0x44
.global __vt__16TAIAdisableStick
__vt__16TAIAdisableStick:
	.incbin "baserom.dol", 0x2DEA24, 0xC0
.global __vt__18TAIAflickingBeatle
__vt__18TAIAflickingBeatle:
	.incbin "baserom.dol", 0x2DEAE4, 0x7C
.global __vt__17TAIAinvincibleOff
__vt__17TAIAinvincibleOff:
	.incbin "baserom.dol", 0x2DEB60, 0xE0
.global __vt__33TAIAflickingAfterMotionLoopBeatle
__vt__33TAIAflickingAfterMotionLoopBeatle:
	.incbin "baserom.dol", 0x2DEC40, 0x88
.global __vt__14TAIArockAttack
__vt__14TAIArockAttack:
	.incbin "baserom.dol", 0x2DECC8, 0xA8
.global __vt__29TAIAinsideOptionalRangeBeatle
__vt__29TAIAinsideOptionalRangeBeatle:
	.incbin "baserom.dol", 0x2DED70, 0x4C
.global __vt__21TAIAvisiblePikiBeatle
__vt__21TAIAvisiblePikiBeatle:
	.incbin "baserom.dol", 0x2DEDBC, 0x9C
.global __vt__16TAIAdamageBeatle
__vt__16TAIAdamageBeatle:
	.incbin "baserom.dol", 0x2DEE58, 0x6C
.global __vt__15TAIAdyingBeatle
__vt__15TAIAdyingBeatle:
	.incbin "baserom.dol", 0x2DEEC4, 0x38
.global __vt__14TAIAinitBeatle
__vt__14TAIAinitBeatle:
	.incbin "baserom.dol", 0x2DEEFC, 0xC8
.global __vt__19TAIbeatleParameters
__vt__19TAIbeatleParameters:
	.incbin "baserom.dol", 0x2DEFC4, 0xD8
.global __vt__Q23zen9MenuPanel
__vt__Q23zen9MenuPanel:
	.incbin "baserom.dol", 0x2DF09C, 0x2C
.global lbl_802E20C8
lbl_802E20C8:
	.incbin "baserom.dol", 0x2DF0C8, 0x214
.global __vt__20TAIkabekuiAAnimation
__vt__20TAIkabekuiAAnimation:
	.incbin "baserom.dol", 0x2DF2DC, 0x34
.global __vt__13TAIAshadowOff
__vt__13TAIAshadowOff:
	.incbin "baserom.dol", 0x2DF310, 0x38
.global __vt__12TAIAshadowOn
__vt__12TAIAshadowOn:
	.incbin "baserom.dol", 0x2DF348, 0x64
.global __vt__17TAIAsleepKabekuiA
__vt__17TAIAsleepKabekuiA:
	.incbin "baserom.dol", 0x2DF3AC, 0x48
.global __vt__16TAIAdiveKabekuiA
__vt__16TAIAdiveKabekuiA:
	.incbin "baserom.dol", 0x2DF3F4, 0xC8
.global __vt__28TAIAattackWorkObjectKabekuiA
__vt__28TAIAattackWorkObjectKabekuiA:
	.incbin "baserom.dol", 0x2DF4BC, 0x84
.global __vt__16TAIAinvincibleOn
__vt__16TAIAinvincibleOn:
	.incbin "baserom.dol", 0x2DF540, 0x5C
.global __vt__18TAIAsetMotionSpeed
__vt__18TAIAsetMotionSpeed:
	.incbin "baserom.dol", 0x2DF59C, 0x88
.global __vt__19TAIkabekuiAStrategy
__vt__19TAIkabekuiAStrategy:
	.incbin "baserom.dol", 0x2DF624, 0xBC
.global __vt__21TAIkabekuiAParameters
__vt__21TAIkabekuiAParameters:
	.incbin "baserom.dol", 0x2DF6E0, 0x30
.global lbl_802E2710
lbl_802E2710:
	.incbin "baserom.dol", 0x2DF710, 0x23C
.global __vt__20TAIkabekuiBAnimation
__vt__20TAIkabekuiBAnimation:
	.incbin "baserom.dol", 0x2DF94C, 0xD0
.global __vt__17TAIAsleepKabekuiB
__vt__17TAIAsleepKabekuiB:
	.incbin "baserom.dol", 0x2DFA1C, 0x48
.global __vt__16TAIAdiveKabekuiB
__vt__16TAIAdiveKabekuiB:
	.incbin "baserom.dol", 0x2DFA64, 0xC8
.global __vt__28TAIAattackWorkObjectKabekuiB
__vt__28TAIAattackWorkObjectKabekuiB:
	.incbin "baserom.dol", 0x2DFB2C, 0xF8
.global __vt__19TAIAbiteForKabekuiB
__vt__19TAIAbiteForKabekuiB:
	.incbin "baserom.dol", 0x2DFC24, 0xEC
.global __vt__19TAIkabekuiBStrategy
__vt__19TAIkabekuiBStrategy:
	.incbin "baserom.dol", 0x2DFD10, 0xBC
.global __vt__21TAIkabekuiBParameters
__vt__21TAIkabekuiBParameters:
	.incbin "baserom.dol", 0x2DFDCC, 0x34
.global lbl_802E2E00
lbl_802E2E00:
	.incbin "baserom.dol", 0x2DFE00, 0x2C0
.global __vt__20TAIkabekuiCAnimation
__vt__20TAIkabekuiCAnimation:
	.incbin "baserom.dol", 0x2E00C0, 0xD0
.global __vt__17TAIAsleepKabekuiC
__vt__17TAIAsleepKabekuiC:
	.incbin "baserom.dol", 0x2E0190, 0x48
.global __vt__16TAIAdiveKabekuiC
__vt__16TAIAdiveKabekuiC:
	.incbin "baserom.dol", 0x2E01D8, 0xC8
.global __vt__28TAIAattackWorkObjectKabekuiC
__vt__28TAIAattackWorkObjectKabekuiC:
	.incbin "baserom.dol", 0x2E02A0, 0xC8
.global __vt__19TAIAlandingKabekuiC
__vt__19TAIAlandingKabekuiC:
	.incbin "baserom.dol", 0x2E0368, 0x90
.global __vt__20TAIAmoreLifeKabekuiC
__vt__20TAIAmoreLifeKabekuiC:
	.incbin "baserom.dol", 0x2E03F8, 0x74
.global __vt__24TAIAcheckPikiFlyKabekuiC
__vt__24TAIAcheckPikiFlyKabekuiC:
	.incbin "baserom.dol", 0x2E046C, 0x4C
.global __vt__24TAIAflyingMotionKabekuiC
__vt__24TAIAflyingMotionKabekuiC:
	.incbin "baserom.dol", 0x2E04B8, 0x64
.global __vt__22TAIAflyingBaseKabekuiC
__vt__22TAIAflyingBaseKabekuiC:
	.incbin "baserom.dol", 0x2E051C, 0x70
.global __vt__Q29$$2unnamed$$212rippleEffect
__vt__Q29$$2unnamed$$212rippleEffect:
	.incbin "baserom.dol", 0x2E058C, 0x40
.global __vt__19TAIAtakeOffKabekuiC
__vt__19TAIAtakeOffKabekuiC:
	.incbin "baserom.dol", 0x2E05CC, 0x74
.global __vt__20TAIAlessLifeKabekuiC
__vt__20TAIAlessLifeKabekuiC:
	.incbin "baserom.dol", 0x2E0640, 0x20
.global __vt__13TAIAjudgeLife
__vt__13TAIAjudgeLife:
	.incbin "baserom.dol", 0x2E0660, 0x78
.global __vt__19TAIAbiteForKabekuiC
__vt__19TAIAbiteForKabekuiC:
	.incbin "baserom.dol", 0x2E06D8, 0xEC
.global __vt__19TAIkabekuiCStrategy
__vt__19TAIkabekuiCStrategy:
	.incbin "baserom.dol", 0x2E07C4, 0xBC
.global __vt__21TAIkabekuiCParameters
__vt__21TAIkabekuiCParameters:
	.incbin "baserom.dol", 0x2E0880, 0x30
.global lbl_802E38B0
lbl_802E38B0:
	.incbin "baserom.dol", 0x2E08B0, 0x1C
.global lbl_802E38CC
lbl_802E38CC:
	.incbin "baserom.dol", 0x2E08CC, 0x18
.global lbl_802E38E4
lbl_802E38E4:
	.incbin "baserom.dol", 0x2E08E4, 0x1B0
.global __vt__18TAItamagoAnimation
__vt__18TAItamagoAnimation:
	.incbin "baserom.dol", 0x2E0A94, 0x3C
.global __vt__20TAIAcountStartTamago
__vt__20TAIAcountStartTamago:
	.incbin "baserom.dol", 0x2E0AD0, 0x54
.global __vt__9TAIAhatch
__vt__9TAIAhatch:
	.incbin "baserom.dol", 0x2E0B24, 0x68
.global __vt__23TAIAtimerReactionTamago
__vt__23TAIAtimerReactionTamago:
	.incbin "baserom.dol", 0x2E0B8C, 0x64
.global __vt__15TAIAdyingTamago
__vt__15TAIAdyingTamago:
	.incbin "baserom.dol", 0x2E0BF0, 0x88
.global __vt__17TAItamagoStrategy
__vt__17TAItamagoStrategy:
	.incbin "baserom.dol", 0x2E0C78, 0xB8
.global __vt__19TAItamagoParameters
__vt__19TAItamagoParameters:
	.incbin "baserom.dol", 0x2E0D30, 0x30
.global lbl_802E3D60
lbl_802E3D60:
	.incbin "baserom.dol", 0x2E0D60, 0x238
.global __vt__18TAIdororoAnimation
__vt__18TAIdororoAnimation:
	.incbin "baserom.dol", 0x2E0F98, 0x5C
.global __vt__17TAIdororoStrategy
__vt__17TAIdororoStrategy:
	.incbin "baserom.dol", 0x2E0FF4, 0x54
.global __vt__17TAIAgravityDororo
__vt__17TAIAgravityDororo:
	.incbin "baserom.dol", 0x2E1048, 0x3C
.global __vt__19TAIAcheckBarkDororo
__vt__19TAIAcheckBarkDororo:
	.incbin "baserom.dol", 0x2E1084, 0x8C
.global __vt__14TAIAbarkDororo
__vt__14TAIAbarkDororo:
	.incbin "baserom.dol", 0x2E1110, 0x88
.global __vt__24TAIAtransformationDororo
__vt__24TAIAtransformationDororo:
	.incbin "baserom.dol", 0x2E1198, 0x40
.global __vt__15TAIAbirthDororo
__vt__15TAIAbirthDororo:
	.incbin "baserom.dol", 0x2E11D8, 0x7C
.global __vt__16TAIAgoTargetPiki
__vt__16TAIAgoTargetPiki:
	.incbin "baserom.dol", 0x2E1254, 0xA8
.global __vt__14TAIAwaitDororo
__vt__14TAIAwaitDororo:
	.incbin "baserom.dol", 0x2E12FC, 0x8C
.global __vt__18TAIAflickingDororo
__vt__18TAIAflickingDororo:
	.incbin "baserom.dol", 0x2E1388, 0x8C
.global __vt__20TAIAgoGoalPathDororo
__vt__20TAIAgoGoalPathDororo:
	.incbin "baserom.dol", 0x2E1414, 0x84
.global __vt__17TAIAkillTouchPiki
__vt__17TAIAkillTouchPiki:
	.incbin "baserom.dol", 0x2E1498, 0x68
.global __vt__15TAIAdyingDororo
__vt__15TAIAdyingDororo:
	.incbin "baserom.dol", 0x2E1500, 0x38
.global __vt__14TAIAinitDororo
__vt__14TAIAinitDororo:
	.incbin "baserom.dol", 0x2E1538, 0xC8
.global __vt__19TAIdororoParameters
__vt__19TAIdororoParameters:
	.incbin "baserom.dol", 0x2E1600, 0x30
.global lbl_802E4630
lbl_802E4630:
	.incbin "baserom.dol", 0x2E1630, 0x1C
.global lbl_802E464C
lbl_802E464C:
	.incbin "baserom.dol", 0x2E164C, 0x10
.global lbl_802E465C
lbl_802E465C:
	.incbin "baserom.dol", 0x2E165C, 0x19C
.global __vt__17TAIhibaAAnimation
__vt__17TAIhibaAAnimation:
	.incbin "baserom.dol", 0x2E17F8, 0x5C
.global __vt__16TAIhibaAStrategy
__vt__16TAIhibaAStrategy:
	.incbin "baserom.dol", 0x2E1854, 0x7C
.global __vt__19TAIAfireAttackHibaA
__vt__19TAIAfireAttackHibaA:
	.incbin "baserom.dol", 0x2E18D0, 0x68
.global __vt__22TAIAtimerReactionHibaA
__vt__22TAIAtimerReactionHibaA:
	.incbin "baserom.dol", 0x2E1938, 0x5C
.global __vt__13TAIAinitHibaA
__vt__13TAIAinitHibaA:
	.incbin "baserom.dol", 0x2E1994, 0xC8
.global __vt__18TAIhibaAParameters
__vt__18TAIhibaAParameters:
	.incbin "baserom.dol", 0x2E1A5C, 0x80
.global __vt__33TAIeffectAttackEventCallBackHibaA
__vt__33TAIeffectAttackEventCallBackHibaA:
	.incbin "baserom.dol", 0x2E1ADC, 0xCC
.global __vt__18TAIAeffCloudOfDust
__vt__18TAIAeffCloudOfDust:
	.incbin "baserom.dol", 0x2E1BA8, 0x20
.global lbl_802E4BC8
lbl_802E4BC8:
	.incbin "baserom.dol", 0x2E1BC8, 0x254
.global __vt__18TAImiurinAnimation
__vt__18TAImiurinAnimation:
	.incbin "baserom.dol", 0x2E1E1C, 0x5C
.global __vt__17TAImiurinStrategy
__vt__17TAImiurinStrategy:
	.incbin "baserom.dol", 0x2E1E78, 0x7C
.global __vt__16TAIAgroggyMiurin
__vt__16TAIAgroggyMiurin:
	.incbin "baserom.dol", 0x2E1EF4, 0x44
.global __vt__24TAIAresetAnimSpeedMiurin
__vt__24TAIAresetAnimSpeedMiurin:
	.incbin "baserom.dol", 0x2E1F38, 0x58
.global __vt__15TAIAangryMiurin
__vt__15TAIAangryMiurin:
	.incbin "baserom.dol", 0x2E1F90, 0xAC
.global __vt__19TAIAcheckNaviMiurin
__vt__19TAIAcheckNaviMiurin:
	.incbin "baserom.dol", 0x2E203C, 0x40
.global __vt__21TAIAcheckFlowerPikmin
__vt__21TAIAcheckFlowerPikmin:
	.incbin "baserom.dol", 0x2E207C, 0x44
.global __vt__17TAIAsatisfyMiurin
__vt__17TAIAsatisfyMiurin:
	.incbin "baserom.dol", 0x2E20C0, 0x3C
.global __vt__19TAIAwatchNaviMiurin
__vt__19TAIAwatchNaviMiurin:
	.incbin "baserom.dol", 0x2E20FC, 0xB0
.global __vt__26TAIAoutsideTerritoryMiurin
__vt__26TAIAoutsideTerritoryMiurin:
	.incbin "baserom.dol", 0x2E21AC, 0x98
.global __vt__18TAIAflickingMiurin
__vt__18TAIAflickingMiurin:
	.incbin "baserom.dol", 0x2E2244, 0x6C
.global __vt__20TAIAflickCheckMiurin
__vt__20TAIAflickCheckMiurin:
	.incbin "baserom.dol", 0x2E22B0, 0x6C
.global __vt__22TAIAstickingPikiMiurin
__vt__22TAIAstickingPikiMiurin:
	.incbin "baserom.dol", 0x2E231C, 0x7C
.global __vt__22TAIAcheckSatisfyMiurin
__vt__22TAIAcheckSatisfyMiurin:
	.incbin "baserom.dol", 0x2E2398, 0x44
.global __vt__16TAIAattackMiurin
__vt__16TAIAattackMiurin:
	.incbin "baserom.dol", 0x2E23DC, 0x44
.global __vt__17TAIAattackPosture
__vt__17TAIAattackPosture:
	.incbin "baserom.dol", 0x2E2420, 0x70
.global __vt__26TAIAattackableTargetMiurin
__vt__26TAIAattackableTargetMiurin:
	.incbin "baserom.dol", 0x2E2490, 0x9C
.global __vt__39TAIAapproachTargetPriorityFaceDirMiurin
__vt__39TAIAapproachTargetPriorityFaceDirMiurin:
	.incbin "baserom.dol", 0x2E252C, 0xBC
.global __vt__27TAIAturnFocusCreatureMiurin
__vt__27TAIAturnFocusCreatureMiurin:
	.incbin "baserom.dol", 0x2E25E8, 0x6C
.global __vt__15TAIAdyingMiurin
__vt__15TAIAdyingMiurin:
	.incbin "baserom.dol", 0x2E2654, 0x38
.global __vt__14TAIAinitMiurin
__vt__14TAIAinitMiurin:
	.incbin "baserom.dol", 0x2E268C, 0xC8
.global __vt__19TAImiurinParameters
__vt__19TAImiurinParameters:
	.incbin "baserom.dol", 0x2E2754, 0x34
.global lbl_802E5788
lbl_802E5788:
	.incbin "baserom.dol", 0x2E2788, 0x18
.global lbl_802E57A0
lbl_802E57A0:
	.incbin "baserom.dol", 0x2E27A0, 0x10
.global lbl_802E57B0
lbl_802E57B0:
	.incbin "baserom.dol", 0x2E27B0, 0x110
.global lbl_802E58C0
lbl_802E58C0:
	.incbin "baserom.dol", 0x2E28C0, 0x148
.global __vt__Q29$$2unnamed$$224DrawWorldMapDateCallBack
__vt__Q29$$2unnamed$$224DrawWorldMapDateCallBack:
	.incbin "baserom.dol", 0x2E2A08, 0x30
.global lbl_802E5A38
lbl_802E5A38:
	.incbin "baserom.dol", 0x2E2A38, 0x18
.global lbl_802E5A50
lbl_802E5A50:
	.incbin "baserom.dol", 0x2E2A50, 0x18
.global lbl_802E5A68
lbl_802E5A68:
	.incbin "baserom.dol", 0x2E2A68, 0x40
.global __vt__11YaiStrategy
__vt__11YaiStrategy:
	.incbin "baserom.dol", 0x2E2AA8, 0x69C
.global ptclInfo__9$$2unnamed$$2
ptclInfo__9$$2unnamed$$2:
	.incbin "baserom.dol", 0x2E3144, 0x294
.global lbl_802E63D8
lbl_802E63D8:
	.incbin "baserom.dol", 0x2E33D8, 0x18
.global lbl_802E63F0
lbl_802E63F0:
	.incbin "baserom.dol", 0x2E33F0, 0x1A8
.global __vt__17TAIusubaAnimation
__vt__17TAIusubaAnimation:
	.incbin "baserom.dol", 0x2E3598, 0x54
.global __vt__12TAIAflyUsuba
__vt__12TAIAflyUsuba:
	.incbin "baserom.dol", 0x2E35EC, 0x88
.global __vt__16TAIusubaStrategy
__vt__16TAIusubaStrategy:
	.incbin "baserom.dol", 0x2E3674, 0xB8
.global __vt__18TAIusubaParameters
__vt__18TAIusubaParameters:
	.incbin "baserom.dol", 0x2E372C, 0x34
.global lbl_802E6760
lbl_802E6760:
	.incbin "baserom.dol", 0x2E3760, 0x1C
.global lbl_802E677C
lbl_802E677C:
	.incbin "baserom.dol", 0x2E377C, 0x18
.global lbl_802E6794
lbl_802E6794:
	.incbin "baserom.dol", 0x2E3794, 0x1A4
.global __vt__17TAIotamaAnimation
__vt__17TAIotamaAnimation:
	.incbin "baserom.dol", 0x2E3938, 0x60
.global __vt__16TAIArunAwayOtama
__vt__16TAIArunAwayOtama:
	.incbin "baserom.dol", 0x2E3998, 0xB8
.global __vt__15TAIAappealOtama
__vt__15TAIAappealOtama:
	.incbin "baserom.dol", 0x2E3A50, 0x78
.global __vt__18TAIAsetTargetOtama
__vt__18TAIAsetTargetOtama:
	.incbin "baserom.dol", 0x2E3AC8, 0x40
.global __vt__13TAIAwaitOtama
__vt__13TAIAwaitOtama:
	.incbin "baserom.dol", 0x2E3B08, 0x88
.global __vt__16TAIotamaStrategy
__vt__16TAIotamaStrategy:
	.incbin "baserom.dol", 0x2E3B90, 0xB8
.global __vt__18TAIotamaParameters
__vt__18TAIotamaParameters:
	.incbin "baserom.dol", 0x2E3C48, 0x30
.global lbl_802E6C78
lbl_802E6C78:
	.incbin "baserom.dol", 0x2E3C78, 0x2C
.global lbl_802E6CA4
lbl_802E6CA4:
	.incbin "baserom.dol", 0x2E3CA4, 0xC4
.global __vt__Q23zen12DrawCMCSmenu
__vt__Q23zen12DrawCMCSmenu:
	.incbin "baserom.dol", 0x2E3D68, 0x30
.global lbl_802E6D98
lbl_802E6D98:
	.incbin "baserom.dol", 0x2E3D98, 0xC
.global lbl_802E6DA4
lbl_802E6DA4:
	.incbin "baserom.dol", 0x2E3DA4, 0xC
.global lbl_802E6DB0
lbl_802E6DB0:
	.incbin "baserom.dol", 0x2E3DB0, 0x10
.global lbl_802E6DC0
lbl_802E6DC0:
	.incbin "baserom.dol", 0x2E3DC0, 0xC
.global lbl_802E6DCC
lbl_802E6DCC:
	.incbin "baserom.dol", 0x2E3DCC, 0xC
.global lbl_802E6DD8
lbl_802E6DD8:
	.incbin "baserom.dol", 0x2E3DD8, 0xC
.global lbl_802E6DE4
lbl_802E6DE4:
	.incbin "baserom.dol", 0x2E3DE4, 0xC
.global lbl_802E6DF0
lbl_802E6DF0:
	.incbin "baserom.dol", 0x2E3DF0, 0xC
.global lbl_802E6DFC
lbl_802E6DFC:
	.incbin "baserom.dol", 0x2E3DFC, 0xC
.global lbl_802E6E08
lbl_802E6E08:
	.incbin "baserom.dol", 0x2E3E08, 0x10
.global lbl_802E6E18
lbl_802E6E18:
	.incbin "baserom.dol", 0x2E3E18, 0x40
.global lbl_802E6E58
lbl_802E6E58:
	.incbin "baserom.dol", 0x2E3E58, 0x30
.global lbl_802E6E88
lbl_802E6E88:
	.incbin "baserom.dol", 0x2E3E88, 0xF0
.global __vt__Q23zen17DrawCMresultGraph
__vt__Q23zen17DrawCMresultGraph:
	.incbin "baserom.dol", 0x2E3F78, 0xC
.global __vt__Q23zen17DrawCMresultAlpha
__vt__Q23zen17DrawCMresultAlpha:
	.incbin "baserom.dol", 0x2E3F84, 0x104
.global lbl_802E7088
lbl_802E7088:
	.incbin "baserom.dol", 0x2E4088, 0x78
.global __vt__Q23zen12DrawMenuBase
__vt__Q23zen12DrawMenuBase:
	.incbin "baserom.dol", 0x2E4100, 0x30
.global lbl_802E7130
lbl_802E7130:
	.incbin "baserom.dol", 0x2E4130, 0x18
.global lbl_802E7148
lbl_802E7148:
	.incbin "baserom.dol", 0x2E4148, 0x18
.global lbl_802E7160
lbl_802E7160:
	.incbin "baserom.dol", 0x2E4160, 0x18
.global lbl_802E7178
lbl_802E7178:
	.incbin "baserom.dol", 0x2E4178, 0x18
.global lbl_802E7190
lbl_802E7190:
	.incbin "baserom.dol", 0x2E4190, 0x28
.global lbl_802E71B8
lbl_802E71B8:
	.incbin "baserom.dol", 0x2E41B8, 0x28
.global lbl_802E71E0
lbl_802E71E0:
	.incbin "baserom.dol", 0x2E41E0, 0x10
.global lbl_802E71F0
lbl_802E71F0:
	.incbin "baserom.dol", 0x2E41F0, 0x10
.global lbl_802E7200
lbl_802E7200:
	.incbin "baserom.dol", 0x2E4200, 0x1C
.global lbl_802E721C
lbl_802E721C:
	.incbin "baserom.dol", 0x2E421C, 0x1C
.global lbl_802E7238
lbl_802E7238:
	.incbin "baserom.dol", 0x2E4238, 0x20
.global lbl_802E7258
lbl_802E7258:
	.incbin "baserom.dol", 0x2E4258, 0x28
.global lbl_802E7280
lbl_802E7280:
	.incbin "baserom.dol", 0x2E4280, 0x28
.global lbl_802E72A8
lbl_802E72A8:
	.incbin "baserom.dol", 0x2E42A8, 0xE8
.global __OSExceptionLocations
__OSExceptionLocations:
	.incbin "baserom.dol", 0x2E4390, 0xD8
.global DSPInitCode
DSPInitCode:
	.incbin "baserom.dol", 0x2E4468, 0x80
.global lbl_802E74E8
lbl_802E74E8:
	.incbin "baserom.dol", 0x2E44E8, 0x230
.global lbl_802E7718
lbl_802E7718:
	.incbin "baserom.dol", 0x2E4718, 0x1B4
.global lbl_802E78CC
lbl_802E78CC:
	.incbin "baserom.dol", 0x2E48CC, 0x24
.global lbl_802E78F0
lbl_802E78F0:
	.incbin "baserom.dol", 0x2E48F0, 0x238
.global InterruptPrioTable
InterruptPrioTable:
	.incbin "baserom.dol", 0x2E4B28, 0x2C
.global lbl_802E7B54
lbl_802E7B54:
	.incbin "baserom.dol", 0x2E4B54, 0x6C
.global Si
Si:
	.incbin "baserom.dol", 0x2E4BC0, 0x18
.global lbl_802E7BD8
lbl_802E7BD8:
	.incbin "baserom.dol", 0x2E4BD8, 0x810
.global YearDays
YearDays:
	.incbin "baserom.dol", 0x2E53E8, 0x30
.global LeapYearDays
LeapYearDays:
	.incbin "baserom.dol", 0x2E5418, 0x30
.global lbl_802E8448
lbl_802E8448:
	.incbin "baserom.dol", 0x2E5448, 0x18
.global lbl_802E8460
lbl_802E8460:
	.incbin "baserom.dol", 0x2E5460, 0xC8
.global lbl_802E8528
lbl_802E8528:
	.incbin "baserom.dol", 0x2E5528, 0x38
.global lbl_802E8560
lbl_802E8560:
	.incbin "baserom.dol", 0x2E5560, 0x34
.global lbl_802E8594
lbl_802E8594:
	.incbin "baserom.dol", 0x2E5594, 0x284
.global lbl_802E8818
lbl_802E8818:
	.incbin "baserom.dol", 0x2E5818, 0x4C
.global lbl_802E8864
lbl_802E8864:
	.incbin "baserom.dol", 0x2E5864, 0x20
.global lbl_802E8884
lbl_802E8884:
	.incbin "baserom.dol", 0x2E5884, 0x40
.global lbl_802E88C4
lbl_802E88C4:
	.incbin "baserom.dol", 0x2E58C4, 0x34
.global lbl_802E88F8
lbl_802E88F8:
	.incbin "baserom.dol", 0x2E58F8, 0x38
.global ErrorTable
ErrorTable:
	.incbin "baserom.dol", 0x2E5930, 0x40
.global lbl_802E8970
lbl_802E8970:
	.incbin "baserom.dol", 0x2E5970, 0x70
.global timing
timing:
	.incbin "baserom.dol", 0x2E59E0, 0x10C
.global taps
taps:
	.incbin "baserom.dol", 0x2E5AEC, 0x34
.global lbl_802E8B20
lbl_802E8B20:
	.incbin "baserom.dol", 0x2E5B20, 0x28
.global ResetFunctionInfo
ResetFunctionInfo:
	.incbin "baserom.dol", 0x2E5B48, 0x10
.global XYNTSC
XYNTSC:
	.incbin "baserom.dol", 0x2E5B58, 0x18
.global XYPAL
XYPAL:
	.incbin "baserom.dol", 0x2E5B70, 0x40
.global ResetFunctionInfo_1
ResetFunctionInfo_1:
	.incbin "baserom.dol", 0x2E5BB0, 0x10
.global SectorSizeTable
SectorSizeTable:
	.incbin "baserom.dol", 0x2E5BC0, 0x20
.global LatencyTable
LatencyTable:
	.incbin "baserom.dol", 0x2E5BE0, 0x20
.global lbl_802E8C00
lbl_802E8C00:
	.incbin "baserom.dol", 0x2E5C00, 0x68
.global lbl_802E8C68
lbl_802E8C68:
	.incbin "baserom.dol", 0x2E5C68, 0x68
.global lbl_802E8CD0
lbl_802E8CD0:
	.incbin "baserom.dol", 0x2E5CD0, 0x44
.global lbl_802E8D14
lbl_802E8D14:
	.incbin "baserom.dol", 0x2E5D14, 0x44
.global lbl_802E8D58
lbl_802E8D58:
	.incbin "baserom.dol", 0x2E5D58, 0x1C
.global lbl_802E8D74
lbl_802E8D74:
	.incbin "baserom.dol", 0x2E5D74, 0x54
.global GXNtsc480IntDf
GXNtsc480IntDf:
	.incbin "baserom.dol", 0x2E5DC8, 0x3C
.global GXMpal480IntDf
GXMpal480IntDf:
	.incbin "baserom.dol", 0x2E5E04, 0x3C
.global GXPal528IntDf
GXPal528IntDf:
	.incbin "baserom.dol", 0x2E5E40, 0x40
.global lbl_802E8E80
lbl_802E8E80:
	.incbin "baserom.dol", 0x2E5E80, 0xF4
.global lbl_802E8F74
lbl_802E8F74:
	.incbin "baserom.dol", 0x2E5F74, 0x3C
.global c2r$71
c2r$71:
	.incbin "baserom.dol", 0x2E5FB0, 0x28
.global p2f$194
p2f$194:
	.incbin "baserom.dol", 0x2E5FD8, 0x20
.global __files
__files:
	.incbin "baserom.dol", 0x2E5FF8, 0xD8
.global __lconv
__lconv:
	.incbin "baserom.dol", 0x2E60D0, 0x30
.global lbl_802E9100
lbl_802E9100:
	.incbin "baserom.dol", 0x2E6100, 0x84
.global lbl_802E9184
lbl_802E9184:
	.incbin "baserom.dol", 0x2E6184, 0x84
.global lbl_802E9208
lbl_802E9208:
	.incbin "baserom.dol", 0x2E6208, 0xD0
.global lbl_802E92D8
lbl_802E92D8:
	.incbin "baserom.dol", 0x2E62D8, 0x48
.global lbl_802E9320
lbl_802E9320:
	.incbin "baserom.dol", 0x2E6320, 0xD0
.global lbl_802E93F0
lbl_802E93F0:
	.incbin "baserom.dol", 0x2E63F0, 0x44
.global lbl_802E9434
lbl_802E9434:
	.incbin "baserom.dol", 0x2E6434, 0x44
.global __float_nan
__float_nan:
	.incbin "baserom.dol", 0x2E6478, 0x4
.global __float_huge
__float_huge:
	.incbin "baserom.dol", 0x2E647C, 0x4
.global __double_min
__double_min:
	.incbin "baserom.dol", 0x2E6480, 0x8
.global __double_max
__double_max:
	.incbin "baserom.dol", 0x2E6488, 0x8
.global __double_huge
__double_huge:
	.incbin "baserom.dol", 0x2E6490, 0x8
.global __double_nan
__double_nan:
	.incbin "baserom.dol", 0x2E6498, 0x8
.global __extended_min
__extended_min:
	.incbin "baserom.dol", 0x2E64A0, 0x8
.global __extended_max
__extended_max:
	.incbin "baserom.dol", 0x2E64A8, 0x8
.global __four_over_pi_m1
__four_over_pi_m1:
	.incbin "baserom.dol", 0x2E64B0, 0x10
.global gTRKDispatchTable
gTRKDispatchTable:
	.incbin "baserom.dol", 0x2E64C0, 0x88
.global lbl_802E9548
lbl_802E9548:
	.incbin "baserom.dol", 0x2E6548, 0x1C
.global lbl_802E9564
lbl_802E9564:
	.incbin "baserom.dol", 0x2E6564, 0x1C
.global gTRKRestoreFlags
gTRKRestoreFlags:
	.incbin "baserom.dol", 0x2E6580, 0xC
.global gTRKExceptionStatus
gTRKExceptionStatus:
	.incbin "baserom.dol", 0x2E658C, 0x10
.global gTRKStepStatus
gTRKStepStatus:
	.incbin "baserom.dol", 0x2E659C, 0x14
.global TRK_ISR_OFFSETS
TRK_ISR_OFFSETS:
	.incbin "baserom.dol", 0x2E65B0, 0x40
.global gDBCommTable
gDBCommTable:
	.incbin "baserom.dol", 0x2E65F0, 0x20
.global lbl_802E9610
lbl_802E9610:
	.incbin "baserom.dol", 0x2E6610, 0x30
