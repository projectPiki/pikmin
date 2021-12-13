.include "macros.inc"
.section .bss, "wa"  # 0x802E9640 - 0x803E81E5
.global dac
dac:
	.skip 0xC
.global audio_hp
audio_hp:
	.skip 0x14
.global audioproc_mq
audioproc_mq:
	.skip 0x20
.global msgbuf
msgbuf:
	.skip 0x40
.global finfo$42
finfo$42:
	.skip 0x3C
.global cmd$43
cmd$43:
	.skip 0x34
.global dsp_buf
dsp_buf:
	.skip 0x10
.global dsp_buf_1
dsp_buf_1:
	.skip 0x10
.global PLAYER_CALLLIST
PLAYER_CALLLIST:
	.skip 0xC0
.global mq
mq:
	.skip 0x20
.global msgbuf_1
msgbuf_1:
	.skip 0x200
.global CALLSTACK
CALLSTACK:
	.skip 0x8000
.global finfo$221
finfo$221:
	.skip 0x3C
.global req$222
req$222:
	.skip 0x80
.global finfo$264
finfo$264:
	.skip 0x3C
.global req$265
req$265:
	.skip 0x20
.global finfo$272
finfo$272:
	.skip 0x3C
.global req$273
req$273:
	.skip 0x20
.global finfo$290
finfo$290:
	.skip 0x3C
.global finfo$307
finfo$307:
	.skip 0x3C
.global finfo$312
finfo$312:
	.skip 0x3C
.global dvd_file
dvd_file:
	.skip 0x800
.global dvd_entrynum
dvd_entrynum:
	.skip 0x88
.global GLOBAL_CHANNEL
GLOBAL_CHANNEL:
	.skip 0x80
.global CHANNEL
CHANNEL:
	.skip 0x14000
.global waitp
waitp:
	.skip 0x80
.global waittime
waittime:
	.skip 0x80
.global DSPCH
DSPCH:
	.skip 0x400
.global CH_BUF
CH_BUF:
	.skip 0x6000
.global FX_BUF
FX_BUF:
	.skip 0x80
.global bankp
bankp:
	.skip 0x400
.global wavearc
wavearc:
	.skip 0x400
.global wavegroup
wavegroup:
	.skip 0x400
.global WS_V2P_TABLE
WS_V2P_TABLE:
	.skip 0x200
.global BNK_V2P_TABLE
BNK_V2P_TABLE:
	.skip 0x200
.global SINTABLE
SINTABLE:
	.skip 0x408
.global FH_TO_FAT
FH_TO_FAT:
	.skip 0x400
.global FAT
FAT:
	.skip 0x800
.global fattmp
fattmp:
	.skip 0x800
.global JV_DIR_NAME
JV_DIR_NAME:
	.skip 0x400
.global JV_ARC_NAME
JV_ARC_NAME:
	.skip 0x200
.global JV_ARC
JV_ARC:
	.skip 0x40
.global finfo$150
finfo$150:
	.skip 0x58
.global dmabuffer
dmabuffer:
	.skip 0x10000
.global TRACK_LIST
TRACK_LIST:
	.skip 0x100
.global SEQ_ARG
SEQ_ARG:
	.skip 0x20
.global seq
seq:
	.skip 0x43400
.global ROOT_OUTER
ROOT_OUTER:
	.skip 0x400
.global rootseq
rootseq:
	.skip 0x40
.global FREE_SEQP_QUEUE
FREE_SEQP_QUEUE:
	.skip 0x400
.global process_stack
process_stack:
	.skip 0x10
.global system_se
system_se:
	.skip 0x6C
.global system_se_stop
system_se_stop:
	.skip 0x6C
.global player_se$123
player_se$123:
	.skip 0x6C
.global player_se_stop$189
player_se_stop$189:
	.skip 0x6C
.global outerparam$219
outerparam$219:
	.skip 0x40
.global bgm
bgm:
	.skip 0xD38
.global demo_q
demo_q:
	.skip 0x70
.global seq_loadbuffer
seq_loadbuffer:
	.skip 0x400
.global rootseq_1
rootseq_1:
	.skip 0x4340
.global rootseqhandle
rootseqhandle:
	.skip 0x40
.global as
as:
	.skip 0x98
.global SC
SC:
	.skip 0x21A50
.global copyinfo
copyinfo:
	.skip 0x18
.global interleavebuf
interleavebuf:
	.skip 0x38
.global filename
filename:
	.skip 0x40
.global dvd_buf
dvd_buf:
	.skip 0xC
.global file_header
file_header:
	.skip 0x44
.global gop_header
gop_header:
	.skip 0x18
.global jac_hvqmThread
jac_hvqmThread:
	.skip 0x318
.global hvqmStack
hvqmStack:
	.skip 0x1000
.global clipTable
clipTable:
	.skip 0x200
.global divTable
divTable:
	.skip 0x40
.global mcdivTable
mcdivTable:
	.skip 0x800
.global fnVerts
fnVerts:
	.skip 0x1800
.global fnNorms
fnNorms:
	.skip 0x1800
.global fnTexs
fnTexs:
	.skip 0x1000
.global matUsed
matUsed:
	.skip 0x100
.global sintable
sintable:
	.skip 0x4000
.global costable
costable:
	.skip 0x4000
.global ident__8Matrix4f
ident__8Matrix4f:
	.skip 0x40
.global lbl_80398880
lbl_80398880:
	.skip 0xC
.global sys
sys:
	.skip 0x334
.global dvdMesgQueue
dvdMesgQueue:
	.skip 0x20
.global loadMesgQueue
loadMesgQueue:
	.skip 0x20
.global sysMesgQueue
sysMesgQueue:
	.skip 0x20
.global aramStream
aramStream:
	.skip 0x14
.global lastName
lastName:
	.skip 0x100
.global dvdStream
dvdStream:
	.skip 0x54
.global dvdBufferedStream
dvdBufferedStream:
	.skip 0x20
.global mMemoryTable$1026
mMemoryTable$1026:
	.skip 0x10
.global Thread
Thread:
	.skip 0x328
.global ThreadStack
ThreadStack:
	.skip 0x2000
.global dvdThread
dvdThread:
	.skip 0x320
.global dvdThreadStack
dvdThreadStack:
	.skip 0x2000
.global sControllerPad
sControllerPad:
	.skip 0x30
.global GColors
GColors:
	.skip 0x8
.global CardThread
CardThread:
	.skip 0x310
.global CardControl
CardControl:
	.skip 0x70
.global gameflow
gameflow:
	.skip 0x368
.global flowCont
flowCont:
	.skip 0x260
.global resultTable
resultTable:
	.skip 0x40
.global collExtents
collExtents:
	.skip 0x18
.global bcs
bcs:
	.skip 0x408
.global cst
cst:
	.skip 0x80
.global CardWorkArea
CardWorkArea:
	.skip 0xA000
.global cardData
cardData:
	.skip 0x26000
.global CardStack
CardStack:
	.skip 0x2000
.global YtexObj
YtexObj:
	.skip 0x20
.global UVtexObj
UVtexObj:
	.skip 0x20
.global playbackThread
playbackThread:
	.skip 0x310
.global playbackThreadStack
playbackThreadStack:
	.skip 0x1000
.global invCamMat
invCamMat:
	.skip 0x40
.global triList
triList:
	.skip 0x800
.global pikiInfMgr
pikiInfMgr:
	.skip 0x28
.global pikiColors__4Piki
pikiColors__4Piki:
	.skip 0x18
.global kinokoColors__4Piki
kinokoColors__4Piki:
	.skip 0x18
.global _instances__15PikiShapeObject
_instances__15PikiShapeObject:
	.skip 0x10
.global deadPikis__8GameStat
deadPikis__8GameStat:
	.skip 0xC
.global fallPikis__8GameStat
fallPikis__8GameStat:
	.skip 0xC
.global formationPikis__8GameStat
formationPikis__8GameStat:
	.skip 0xC
.global freePikis__8GameStat
freePikis__8GameStat:
	.skip 0xC
.global workPikis__8GameStat
workPikis__8GameStat:
	.skip 0xC
.global mePikis__8GameStat
mePikis__8GameStat:
	.skip 0xC
.global containerPikis__8GameStat
containerPikis__8GameStat:
	.skip 0xC
.global bornPikis__8GameStat
bornPikis__8GameStat:
	.skip 0xC
.global victimPikis__8GameStat
victimPikis__8GameStat:
	.skip 0xC
.global mapPikis__8GameStat
mapPikis__8GameStat:
	.skip 0xC
.global allPikis__8GameStat
allPikis__8GameStat:
	.skip 0x10
.global workString__3zen
workString__3zen:
	.skip 0x400
.global bloFile_Diary_Table__3zen
bloFile_Diary_Table__3zen:
	.skip 0x28
.global pTexTable__Q23zen13StickCallBack
pTexTable__Q23zen13StickCallBack:
	.skip 0x58
.global texTable__Q23zen9NumberTex
texTable__Q23zen9NumberTex:
	.skip 0x28
.global shadowTexTable__Q23zen9NumberTex
shadowTexTable__Q23zen9NumberTex:
	.skip 0x28
.global OSErrorTable
OSErrorTable:
	.skip 0x40
.global Ecb
Ecb:
	.skip 0xB0
.global Header
Header:
	.skip 0x20
.global Scb
Scb:
	.skip 0x58
.global Packet
Packet:
	.skip 0x80
.global Alarm
Alarm:
	.skip 0xA0
.global RunQueue
RunQueue:
	.skip 0x100
.global IdleThread
IdleThread:
	.skip 0x310
.global DefaultThread
DefaultThread:
	.skip 0x310
.global IdleContext
IdleContext:
	.skip 0x2C8
.global CommandList
CommandList:
	.skip 0x40
.global AlarmForWA
AlarmForWA:
	.skip 0x28
.global AlarmForTimeout
AlarmForTimeout:
	.skip 0x28
.global AlarmForBreak
AlarmForBreak:
	.skip 0x28
.global Prev
Prev:
	.skip 0xC
.global Curr
Curr:
	.skip 0x1C
.global tmpBuffer
tmpBuffer:
	.skip 0x80
.global DummyCommandBlock
DummyCommandBlock:
	.skip 0x30
.global ResetAlarm
ResetAlarm:
	.skip 0x28
.global WaitingQueue
WaitingQueue:
	.skip 0x20
.global bb2Buf
bb2Buf:
	.skip 0x40
.global block$16
block$16:
	.skip 0x30
.global regs
regs:
	.skip 0x78
.global shdwRegs
shdwRegs:
	.skip 0x78
.global HorVer
HorVer:
	.skip 0x58
.global PADType
PADType:
	.skip 0x10
.global Type
Type:
	.skip 0x10
.global Origin
Origin:
	.skip 0x30
.global cmdProbeDevice
cmdProbeDevice:
	.skip 0x10
.global cmdFixDevice
cmdFixDevice:
	.skip 0x10
.global __CARDBlock
__CARDBlock:
	.skip 0x210
.global __CARDDiskNone
__CARDDiskNone:
	.skip 0x20
.global gxData
gxData:
	.skip 0x4F4
.global FifoObj
FifoObj:
	.skip 0x84
.global DisplayListFifo
DisplayListFifo:
	.skip 0x24
.global __savedGXdata
__savedGXdata:
	.skip 0x4F4
.global fragmentinfo
fragmentinfo:
	.skip 0x10
.global atexit_funcs
atexit_funcs:
	.skip 0x100
.global __atexit_funcs
__atexit_funcs:
	.skip 0x100
.global gTRKEventQueue
gTRKEventQueue:
	.skip 0x28
.global gTRKBigEndian
gTRKBigEndian:
	.skip 0x8
.global gTRKMsgBufs
gTRKMsgBufs:
	.skip 0x19B0
.global gTRKFramingState
gTRKFramingState:
	.skip 0x14
.global gTRKInputPendingPtr
gTRKInputPendingPtr:
	.skip 0x4
.global gTRKDispatchTableSize
gTRKDispatchTableSize:
	.skip 0x8
.global TRK_saved_exceptionID
TRK_saved_exceptionID:
	.skip 0x4
.global gTRKSaveState
gTRKSaveState:
	.skip 0x94
.global TRKvalue128_temp
TRKvalue128_temp:
	.skip 0x10
.global gTRKState
gTRKState:
	.skip 0xA8
.global gTRKCPUState
gTRKCPUState:
	.skip 0x430
.global lc_base
lc_base:
	.skip 0x8
.global TRK_mainError
TRK_mainError:
	.skip 0x8
.global Ecb_1
Ecb_1:
	.skip 0x18
.global aram_hp
aram_hp:
	.skip 0x28
.global jac_audioThread
jac_audioThread:
	.skip 0x2940
.global jac_audioStack
jac_audioStack:
	.skip 0x1000
.global jac_dvdThread
jac_dvdThread:
	.skip 0x320
.global jac_dvdStack
jac_dvdStack:
	.skip 0x1000
.global EX_DSPTASK
EX_DSPTASK:
	.skip 0x40
.global CGRP_ARRAY
CGRP_ARRAY:
	.skip 0x40
.global aram_mother
aram_mother:
	.skip 0x2C
.global EVENT
EVENT:
	.skip 0x1B64
.global pic_ctrl
pic_ctrl:
	.skip 0x1B0
.global dvd_ctrl
dvd_ctrl:
	.skip 0x30
