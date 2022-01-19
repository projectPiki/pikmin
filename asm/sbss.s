.include "macros.inc"
.section .sbss, "wa"
.global UNIVERSAL_DACCOUNTER
UNIVERSAL_DACCOUNTER:
	.skip 4
.global audio_hp_exist
audio_hp_exist:
	.skip 4
.global last_rsp_madep
last_rsp_madep:
	.skip 4
.global use_rsp_madep
use_rsp_madep:
	.skip 4
.global vframe_work_running
vframe_work_running:
	.skip 4
.global DAC_CALLBACK_FUNC
DAC_CALLBACK_FUNC:
	.skip 4
.global JAC_VFRAME_COUNTER
JAC_VFRAME_COUNTER:
	.skip 4
.global ext_mixcallback
ext_mixcallback:
	.skip 4
.global ext_mixmode
ext_mixmode:
	.skip 4
.global dacp$240
dacp$240:
	.skip 4
.global init$241
init$241:
	.skip 8
.global JAC_ARAM_DMA_BUFFER_TOP
JAC_ARAM_DMA_BUFFER_TOP:
	.skip 4
.global AUDIO_ARAM_TOP
AUDIO_ARAM_TOP:
	.skip 4
.global CARD_SECURITY_BUFFER
CARD_SECURITY_BUFFER:
	.skip 4
.global SELECTED_ARAM_SIZE
SELECTED_ARAM_SIZE:
	.skip 4
.global audioproc_mq_init
audioproc_mq_init:
	.skip 4
.global intcount
intcount:
	.skip 4
.global first$70
first$70:
	.skip 4
.global init$71
init$71:
	.skip 4
.global priority_set
priority_set:
	.skip 4
.global pri
pri:
	.skip 4
.global pri2
pri2:
	.skip 4
.global pri3
pri3:
	.skip 4
.global write_buffer
write_buffer:
	.skip 1
.global read_buffer
read_buffer:
	.skip 1
.global dspstatus
dspstatus:
	.skip 2
.global dac_sync_counter
dac_sync_counter:
	.skip 4
.global cur$194
cur$194:
	.skip 4
.global init$195
init$195:
	.skip 4
.global write_buffer_1
write_buffer_1:
	.skip 1
.global read_buffer_1
read_buffer_1:
	.skip 1
.global dspstatus_1
dspstatus_1:
	.skip 6
.global mq_init
mq_init:
	.skip 4
.global buffersize
buffersize:
	.skip 4
.global buffers
buffers:
	.skip 4
.global next_buffersize
next_buffersize:
	.skip 4
.global next_buffertop
next_buffertop:
	.skip 4
.global next_buffers
next_buffers:
	.skip 4
.global cur_q
cur_q:
	.skip 4
.global dvdt_sleep
dvdt_sleep:
	.skip 8
.global DVDT_PAUSE_FLAG
DVDT_PAUSE_FLAG:
	.skip 4
.global error_callback
error_callback:
	.skip 4
.global ADVD_BUFFER
ADVD_BUFFER:
	.skip 8
.global buffer_load
buffer_load:
	.skip 4
.global buffer_full
buffer_full:
	.skip 4
.global arq_index$223
arq_index$223:
	.skip 4
.global init$224
init$224:
	.skip 4
.global dvdfile_dics
dvdfile_dics:
	.skip 4
.global JAC_AI_SETTING
JAC_AI_SETTING:
	.skip 8
.global TASK_READPTR
TASK_READPTR:
	.skip 1
.global TASK_WRITEPTR
TASK_WRITEPTR:
	.skip 1
.global TASK_REMAIN
TASK_REMAIN:
	.skip 6
.global cur_waits
cur_waits:
	.skip 4
.global cur_top
cur_top:
	.skip 4
.global cur_tail
cur_tail:
	.skip 8
.global old_time
old_time:
	.skip 8
.global inited$64
inited$64:
	.skip 4
.global init$65
init$65:
	.skip 4
.global ACTIVE_FATS
ACTIVE_FATS:
	.skip 4
.global USEFAT_TAIL
USEFAT_TAIL:
	.skip 4
.global fatheapptr
fatheapptr:
	.skip 8
.global cmd_once
cmd_once:
	.skip 8
.global cmd_stay
cmd_stay:
	.skip 8
.global JV_CURRENT_ARCS
JV_CURRENT_ARCS:
	.skip 4
.global first$164
first$164:
	.skip 4
.global init$165
init$165:
	.skip 8
.global global_id
global_id:
	.skip 8
.global JAM_CALLBACK_FUNC
JAM_CALLBACK_FUNC:
	.skip 4
.global T_LISTS
T_LISTS:
	.skip 4
.global SEQ_P
SEQ_P:
	.skip 4
.global SEQ_CMD
SEQ_CMD:
	.skip 4
.global BACK_P
BACK_P:
	.skip 4
.global GET_P
GET_P:
	.skip 4
.global SEQ_REMAIN
SEQ_REMAIN:
	.skip 8
.global vol_chg
vol_chg:
	.skip 4
.global stacklevel
stacklevel:
	.skip 4
.global queue_list
queue_list:
	.skip 4
.global cmdqueue_reset
cmdqueue_reset:
	.skip 4
.global countdown_count
countdown_count:
	.skip 4
.global pausemode
pausemode:
	.skip 4
.global container
container:
	.skip 4
.global sys_voldown_flag
sys_voldown_flag:
	.skip 4
.global boot_ok
boot_ok:
	.skip 4
.global count
count:
	.skip 4
.global lend_buffer
lend_buffer:
	.skip 8
.global demo_fade_flag
demo_fade_flag:
	.skip 8
.global CURRENT_TIME
CURRENT_TIME:
	.skip 4
.global jac_debug_multi_entry
jac_debug_multi_entry:
	.skip 4
.global jac_debug_multi_cancel
jac_debug_multi_cancel:
	.skip 8
.global gaya_timer
gaya_timer:
	.skip 4
.global seqp$71
seqp$71:
	.skip 4
.global init$72
init$72:
	.skip 1
.global status$74
status$74:
	.skip 1
.global init$75
init$75:
	.skip 2
.global stick_seqp
stick_seqp:
	.skip 4
.global flag$87
flag$87:
	.skip 4
.global init$88
init$88:
	.skip 4
.global orima_seqp
orima_seqp:
	.skip 4
.global status$120
status$120:
	.skip 1
.global init$121
init$121:
	.skip 3
.global cmdqueue_reset$124
cmdqueue_reset$124:
	.skip 4
.global init$125
init$125:
	.skip 4
.global flyready$135
flyready$135:
	.skip 4
.global init$136
init$136:
	.skip 2
.global old1$151
old1$151:
	.skip 2
.global init$152
init$152:
	.skip 2
.global old2$154
old2$154:
	.skip 2
.global init$155
init$155:
	.skip 2
.global old3$157
old3$157:
	.skip 2
.global init$158
init$158:
	.skip 4
.global seqp$186
seqp$186:
	.skip 4
.global init$187
init$187:
	.skip 4
.global cmdqueue_reset$190
cmdqueue_reset$190:
	.skip 4
.global init$191
init$191:
	.skip 4
.global pikis
pikis:
	.skip 4
.global seqp$215
seqp$215:
	.skip 4
.global init$216
init$216:
	.skip 4
.global init$217
init$217:
	.skip 4
.global volume$220
volume$220:
	.skip 4
.global init$221
init$221:
	.skip 8
.global lastside
lastside:
	.skip 4
.global last_crossmode
last_crossmode:
	.skip 4
.global call_counter
call_counter:
	.skip 4
.global bgm_semaphore
bgm_semaphore:
	.skip 4
.global current_bgm
current_bgm:
	.skip 4
.global current_ready
current_ready:
	.skip 4
.global now_loading
now_loading:
	.skip 4
.global first_load
first_load:
	.skip 4
.global chgmode
chgmode:
	.skip 4
.global first$89
first$89:
	.skip 4
.global init$90
init$90:
	.skip 4
.global stop_flag
stop_flag:
	.skip 4
.global stop_ready
stop_ready:
	.skip 8
.global demo_seqp
demo_seqp:
	.skip 4
.global demo_bgm_seqp
demo_bgm_seqp:
	.skip 4
.global current_seq_bgm
current_seq_bgm:
	.skip 4
.global demo_inited
demo_inited:
	.skip 4
.global now_loading_1
now_loading_1:
	.skip 4
.global parts_find_demo_state
parts_find_demo_state:
	.skip 4
.global text_demo_state
text_demo_state:
	.skip 4
.global demo_parts_id
demo_parts_id:
	.skip 1
.global demo_onyon_num
demo_onyon_num:
	.skip 1
.global demo_parts_num
demo_parts_num:
	.skip 1
.global event_pause_counter
event_pause_counter:
	.skip 1
.global demo_end_delay
demo_end_delay:
	.skip 8
.global seq_archandle
seq_archandle:
	.skip 8
.global default_streamsync_call
default_streamsync_call:
	.skip 8
.global dvd_loadfinish
dvd_loadfinish:
	.skip 4
.global dvdcount
dvdcount:
	.skip 4
.global arcoffset
arcoffset:
	.skip 4
.global AUDIO_FRAME
AUDIO_FRAME:
	.skip 4
.global PIC_FRAME
PIC_FRAME:
	.skip 4
.global drop_picture_flag
drop_picture_flag:
	.skip 4
.global PIC_BUFFERS
PIC_BUFFERS:
	.skip 4
.global dvdload_size
dvdload_size:
	.skip 4
.global dvdfile_size
dvdfile_size:
	.skip 4
.global rec_header
rec_header:
	.skip 8
.global v_header
v_header:
	.skip 4
.global gop_baseframe
gop_baseframe:
	.skip 4
.global gop_frame
gop_frame:
	.skip 4
.global vh_state
vh_state:
	.skip 4
.global hvqm_obj
hvqm_obj:
	.skip 4
.global dvd_active
dvd_active:
	.skip 4
.global virtualfile_buf
virtualfile_buf:
	.skip 4
.global record_ok
record_ok:
	.skip 4
.global ref1
ref1:
	.skip 4
.global ref2
ref2:
	.skip 8
.global readTree_signed
readTree_signed:
	.skip 4
.global readTree_scale
readTree_scale:
	.skip 4
.global matIndex
matIndex:
	.skip 4
.global usedIndex
usedIndex:
	.skip 4
.global _dlindx
_dlindx:
	.skip 8
.global nodeMgr
nodeMgr:
	.skip 8
.global statbuff__9CmdStream
statbuff__9CmdStream:
	.skip 8
.global useSymbols
useSymbols:
	.skip 4
.global gsys
gsys:
	.skip 4
.global sysCon
sysCon:
	.skip 4
.global errCon
errCon:
	.skip 4
.global dvdMesgBuffer
dvdMesgBuffer:
	.skip 4
.global loadMesgBuffer
loadMesgBuffer:
	.skip 4
.global sysMesgBuffer
sysMesgBuffer:
	.skip 4
.global readBuffer__9DVDStream
readBuffer__9DVDStream:
	.skip 4
.global numOpen__9DVDStream
numOpen__9DVDStream:
	.skip 4
.global bigFont
bigFont:
	.skip 4
.global sFrameSize
sFrameSize:
	.skip 4
.global oldVerts
oldVerts:
	.skip 4
.global oldNorms
oldNorms:
	.skip 4
.global oldCols
oldCols:
	.skip 4
.global oldCull
oldCull:
	.skip 4
.global oldTevGroup
oldTevGroup:
	.skip 4
.global frameNum
frameNum:
	.skip 4
.global videoModeAsIs$643
videoModeAsIs$643:
	.skip 4
.global init$644
init$644:
	.skip 4
.global gfx__11DGXGraphics
gfx__11DGXGraphics:
	.skip 4
.global sendTxIndx
sendTxIndx:
	.skip 1
.global sendColIndx
sendColIndx:
	.skip 1
.global sendNbtIndx
sendNbtIndx:
	.skip 6
.global app
app:
	.skip 4
.global llspin
llspin:
	.skip 4
.global memcardWindow
memcardWindow:
	.skip 8
.global selectWindow
selectWindow:
	.skip 4
.global mapWindow
mapWindow:
	.skip 4
.global npgss
npgss:
	.skip 4
.global gamecore
gamecore:
	.skip 4
.global movieIndex
movieIndex:
	.skip 4
.global challengeWindow
challengeWindow:
	.skip 4
.global gameoverWindow
gameoverWindow:
	.skip 4
.global countWindow
countWindow:
	.skip 4
.global pauseWindow
pauseWindow:
	.skip 4
.global resultWindow
resultWindow:
	.skip 4
.global totalWindow
totalWindow:
	.skip 4
.global memcardWindow_1
memcardWindow_1:
	.skip 4
.global menuOn
menuOn:
	.skip 1
.global gameInfoOn
gameInfoOn:
	.skip 1
.global gameInfoIn
gameInfoIn:
	.skip 2
.global menuWindow
menuWindow:
	.skip 4
.global tutorialWindow
tutorialWindow:
	.skip 4
.global hasDemoSound
hasDemoSound:
	.skip 1
.global dontShowFrame
dontShowFrame:
	.skip 1
