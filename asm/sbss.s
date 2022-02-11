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
	.skip 4
