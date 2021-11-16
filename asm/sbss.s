.include "macros.inc"
.section .sbss, "wa"
.global UNIVERSAL_DACCOUNTER
UNIVERSAL_DACCOUNTER:
	.skip 0x4
.global audio_hp_exist
audio_hp_exist:
	.skip 0x4
.global last_rsp_madep
last_rsp_madep:
	.skip 0x4
.global use_rsp_madep
use_rsp_madep:
	.skip 0x4
.global vframe_work_running
vframe_work_running:
	.skip 0x4
.global DAC_CALLBACK_FUNC
DAC_CALLBACK_FUNC:
	.skip 0x4
.global JAC_VFRAME_COUNTER
JAC_VFRAME_COUNTER:
	.skip 0x4
.global ext_mixcallback
ext_mixcallback:
	.skip 0x4
.global ext_mixmode
ext_mixmode:
	.skip 0x4
.global dacp$240
dacp$240:
	.skip 0x4
.global init$241
init$241:
	.skip 0x8
.global JAC_ARAM_DMA_BUFFER_TOP
JAC_ARAM_DMA_BUFFER_TOP:
	.skip 0x4
.global AUDIO_ARAM_TOP
AUDIO_ARAM_TOP:
	.skip 0x4
.global CARD_SECURITY_BUFFER
CARD_SECURITY_BUFFER:
	.skip 0x4
.global SELECTED_ARAM_SIZE
SELECTED_ARAM_SIZE:
	.skip 0x4
.global audioproc_mq_init
audioproc_mq_init:
	.skip 0x4
.global intcount
intcount:
	.skip 0x4
.global first$70
first$70:
	.skip 0x4
.global init$71
init$71:
	.skip 0x4
.global priority_set
priority_set:
	.skip 0x4
.global pri
pri:
	.skip 0x4
.global pri2
pri2:
	.skip 0x4
.global pri3
pri3:
	.skip 0x4
.global write_buffer
write_buffer:
	.skip 0x1
.global read_buffer
read_buffer:
	.skip 0x1
.global dspstatus
dspstatus:
	.skip 0x2
.global dac_sync_counter
dac_sync_counter:
	.skip 0x4
.global cur$194
cur$194:
	.skip 0x4
.global init$195
init$195:
	.skip 0x4
.global write_buffer_1
write_buffer_1:
	.skip 0x1
.global read_buffer_1
read_buffer_1:
	.skip 0x1
.global dspstatus_1
dspstatus_1:
	.skip 0x6
.global mq_init
mq_init:
	.skip 0x4
.global buffersize
buffersize:
	.skip 0x4
.global buffers
buffers:
	.skip 0x4
.global next_buffersize
next_buffersize:
	.skip 0x4
.global next_buffertop
next_buffertop:
	.skip 0x4
.global next_buffers
next_buffers:
	.skip 0x4
.global cur_q
cur_q:
	.skip 0x4
.global dvdt_sleep
dvdt_sleep:
	.skip 0x8
.global DVDT_PAUSE_FLAG
DVDT_PAUSE_FLAG:
	.skip 0x4
.global error_callback
error_callback:
	.skip 0x4
.global ADVD_BUFFER
ADVD_BUFFER:
	.skip 0x8
.global buffer_load
buffer_load:
	.skip 0x4
.global buffer_full
buffer_full:
	.skip 0x4
.global arq_index$223
arq_index$223:
	.skip 0x4
.global init$224
init$224:
	.skip 0x4
.global dvdfile_dics
dvdfile_dics:
	.skip 0x4
.global JAC_AI_SETTING
JAC_AI_SETTING:
	.skip 0x8
.global TASK_READPTR
TASK_READPTR:
	.skip 0x1
.global TASK_WRITEPTR
TASK_WRITEPTR:
	.skip 0x1
.global TASK_REMAIN
TASK_REMAIN:
	.skip 0x6
.global cur_waits
cur_waits:
	.skip 0x4
.global cur_top
cur_top:
	.skip 0x4
.global cur_tail
cur_tail:
	.skip 0x8
.global old_time
old_time:
	.skip 0x8
.global inited$64
inited$64:
	.skip 0x4
.global init$65
init$65:
	.skip 0x4
.global ACTIVE_FATS
ACTIVE_FATS:
	.skip 0x4
.global USEFAT_TAIL
USEFAT_TAIL:
	.skip 0x4
.global fatheapptr
fatheapptr:
	.skip 0x8
.global cmd_once
cmd_once:
	.skip 0x8
.global cmd_stay
cmd_stay:
	.skip 0x8
.global JV_CURRENT_ARCS
JV_CURRENT_ARCS:
	.skip 0x4
.global first$164
first$164:
	.skip 0x4
.global init$165
init$165:
	.skip 0x8
.global global_id
global_id:
	.skip 0x8
.global JAM_CALLBACK_FUNC
JAM_CALLBACK_FUNC:
	.skip 0x4
.global T_LISTS
T_LISTS:
	.skip 0x4
.global SEQ_P
SEQ_P:
	.skip 0x4
.global SEQ_CMD
SEQ_CMD:
	.skip 0x4
.global BACK_P
BACK_P:
	.skip 0x4
.global GET_P
GET_P:
	.skip 0x4
.global SEQ_REMAIN
SEQ_REMAIN:
	.skip 0x8
.global vol_chg
vol_chg:
	.skip 0x4
.global stacklevel
stacklevel:
	.skip 0x4
.global queue_list
queue_list:
	.skip 0x4
.global cmdqueue_reset
cmdqueue_reset:
	.skip 0x4
.global countdown_count
countdown_count:
	.skip 0x4
.global pausemode
pausemode:
	.skip 0x4
.global container
container:
	.skip 0x4
.global sys_voldown_flag
sys_voldown_flag:
	.skip 0x4
.global boot_ok
boot_ok:
	.skip 0x4
.global count
count:
	.skip 0x4
.global lend_buffer
lend_buffer:
	.skip 0x8
.global demo_fade_flag
demo_fade_flag:
	.skip 0x8
.global CURRENT_TIME
CURRENT_TIME:
	.skip 0x4
.global jac_debug_multi_entry
jac_debug_multi_entry:
	.skip 0x4
.global jac_debug_multi_cancel
jac_debug_multi_cancel:
	.skip 0x8
.global gaya_timer
gaya_timer:
	.skip 0x4
.global seqp$71
seqp$71:
	.skip 0x4
.global init$72
init$72:
	.skip 0x1
.global status$74
status$74:
	.skip 0x1
.global init$75
init$75:
	.skip 0x2
.global stick_seqp
stick_seqp:
	.skip 0x4
.global flag$87
flag$87:
	.skip 0x4
.global init$88
init$88:
	.skip 0x4
.global orima_seqp
orima_seqp:
	.skip 0x4
.global status$120
status$120:
	.skip 0x1
.global init$121
init$121:
	.skip 0x3
.global cmdqueue_reset$124
cmdqueue_reset$124:
	.skip 0x4
.global init$125
init$125:
	.skip 0x4
.global flyready$135
flyready$135:
	.skip 0x4
.global init$136
init$136:
	.skip 0x2
.global old1$151
old1$151:
	.skip 0x2
.global init$152
init$152:
	.skip 0x2
.global old2$154
old2$154:
	.skip 0x2
.global init$155
init$155:
	.skip 0x2
.global old3$157
old3$157:
	.skip 0x2
.global init$158
init$158:
	.skip 0x4
.global seqp$186
seqp$186:
	.skip 0x4
.global init$187
init$187:
	.skip 0x4
.global cmdqueue_reset$190
cmdqueue_reset$190:
	.skip 0x4
.global init$191
init$191:
	.skip 0x4
.global pikis
pikis:
	.skip 0x4
.global seqp$215
seqp$215:
	.skip 0x4
.global init$216
init$216:
	.skip 0x4
.global init$217
init$217:
	.skip 0x4
.global volume$220
volume$220:
	.skip 0x4
.global init$221
init$221:
	.skip 0x8
.global lastside
lastside:
	.skip 0x4
.global last_crossmode
last_crossmode:
	.skip 0x4
.global call_counter
call_counter:
	.skip 0x4
.global bgm_semaphore
bgm_semaphore:
	.skip 0x4
.global current_bgm
current_bgm:
	.skip 0x4
.global current_ready
current_ready:
	.skip 0x4
.global now_loading
now_loading:
	.skip 0x4
.global first_load
first_load:
	.skip 0x4
.global chgmode
chgmode:
	.skip 0x4
.global first$89
first$89:
	.skip 0x4
.global init$90
init$90:
	.skip 0x4
.global stop_flag
stop_flag:
	.skip 0x4
.global stop_ready
stop_ready:
	.skip 0x8
.global demo_seqp
demo_seqp:
	.skip 0x4
.global demo_bgm_seqp
demo_bgm_seqp:
	.skip 0x4
.global current_seq_bgm
current_seq_bgm:
	.skip 0x4
.global demo_inited
demo_inited:
	.skip 0x4
.global now_loading_1
now_loading_1:
	.skip 0x4
.global parts_find_demo_state
parts_find_demo_state:
	.skip 0x4
.global text_demo_state
text_demo_state:
	.skip 0x4
.global demo_parts_id
demo_parts_id:
	.skip 0x1
.global demo_onyon_num
demo_onyon_num:
	.skip 0x1
.global demo_parts_num
demo_parts_num:
	.skip 0x1
.global event_pause_counter
event_pause_counter:
	.skip 0x1
.global demo_end_delay
demo_end_delay:
	.skip 0x8
.global seq_archandle
seq_archandle:
	.skip 0x8
.global default_streamsync_call
default_streamsync_call:
	.skip 0x8
.global dvd_loadfinish
dvd_loadfinish:
	.skip 0x4
.global dvdcount
dvdcount:
	.skip 0x4
.global arcoffset
arcoffset:
	.skip 0x4
.global AUDIO_FRAME
AUDIO_FRAME:
	.skip 0x4
.global PIC_FRAME
PIC_FRAME:
	.skip 0x4
.global drop_picture_flag
drop_picture_flag:
	.skip 0x4
.global PIC_BUFFERS
PIC_BUFFERS:
	.skip 0x4
.global dvdload_size
dvdload_size:
	.skip 0x4
.global dvdfile_size
dvdfile_size:
	.skip 0x4
.global rec_header
rec_header:
	.skip 0x8
.global v_header
v_header:
	.skip 0x4
.global gop_baseframe
gop_baseframe:
	.skip 0x4
.global gop_frame
gop_frame:
	.skip 0x4
.global vh_state
vh_state:
	.skip 0x4
.global hvqm_obj
hvqm_obj:
	.skip 0x4
.global dvd_active
dvd_active:
	.skip 0x4
.global virtualfile_buf
virtualfile_buf:
	.skip 0x4
.global record_ok
record_ok:
	.skip 0x4
.global ref1
ref1:
	.skip 0x4
.global ref2
ref2:
	.skip 0x8
.global readTree_signed
readTree_signed:
	.skip 0x4
.global readTree_scale
readTree_scale:
	.skip 0x4
.global matIndex
matIndex:
	.skip 0x4
.global usedIndex
usedIndex:
	.skip 0x4
.global _dlindx
_dlindx:
	.skip 0x8
.global nodeMgr
nodeMgr:
	.skip 0x8
.global statbuff__9CmdStream
statbuff__9CmdStream:
	.skip 0x8
.global useSymbols
useSymbols:
	.skip 0x4
.global gsys
gsys:
	.skip 0x4
.global sysCon
sysCon:
	.skip 0x4
.global errCon
errCon:
	.skip 0x4
.global dvdMesgBuffer
dvdMesgBuffer:
	.skip 0x4
.global loadMesgBuffer
loadMesgBuffer:
	.skip 0x4
.global sysMesgBuffer
sysMesgBuffer:
	.skip 0x4
.global readBuffer__9DVDStream
readBuffer__9DVDStream:
	.skip 0x4
.global numOpen__9DVDStream
numOpen__9DVDStream:
	.skip 0x4
.global bigFont
bigFont:
	.skip 0x4
.global sFrameSize
sFrameSize:
	.skip 0x4
.global oldVerts
oldVerts:
	.skip 0x4
.global oldNorms
oldNorms:
	.skip 0x4
.global oldCols
oldCols:
	.skip 0x4
.global oldCull
oldCull:
	.skip 0x4
.global oldTevGroup
oldTevGroup:
	.skip 0x4
.global frameNum
frameNum:
	.skip 0x4
.global videoModeAsIs$643
videoModeAsIs$643:
	.skip 0x4
.global init$644
init$644:
	.skip 0x4
.global gfx__11DGXGraphics
gfx__11DGXGraphics:
	.skip 0x4
.global sendTxIndx
sendTxIndx:
	.skip 0x1
.global sendColIndx
sendColIndx:
	.skip 0x1
.global sendNbtIndx
sendNbtIndx:
	.skip 0x6
.global app
app:
	.skip 0x4
.global llspin
llspin:
	.skip 0x4
.global memcardWindow
memcardWindow:
	.skip 0x8
.global selectWindow
selectWindow:
	.skip 0x4
.global mapWindow
mapWindow:
	.skip 0x4
.global npgss
npgss:
	.skip 0x4
.global gamecore
gamecore:
	.skip 0x4
.global movieIndex
movieIndex:
	.skip 0x4
.global challengeWindow
challengeWindow:
	.skip 0x4
.global gameoverWindow
gameoverWindow:
	.skip 0x4
.global countWindow
countWindow:
	.skip 0x4
.global pauseWindow
pauseWindow:
	.skip 0x4
.global resultWindow
resultWindow:
	.skip 0x4
.global totalWindow
totalWindow:
	.skip 0x4
.global memcardWindow_1
memcardWindow_1:
	.skip 0x4
.global menuOn
menuOn:
	.skip 0x1
.global gameInfoOn
gameInfoOn:
	.skip 0x1
.global gameInfoIn
gameInfoIn:
	.skip 0x2
.global menuWindow
menuWindow:
	.skip 0x4
.global tutorialWindow
tutorialWindow:
	.skip 0x4
.global hasDemoSound
hasDemoSound:
	.skip 0x1
.global dontShowFrame
dontShowFrame:
	.skip 0x3
.global igss
igss:
	.skip 0x8
.global lgborder
lgborder:
	.skip 0x4
.global lglev0
lglev0:
	.skip 0x4
.global lglev1
lglev1:
	.skip 0x4
.global lglev2
lglev2:
	.skip 0x4
.global lglev3
lglev3:
	.skip 0x4
.global lgMgr
lgMgr:
	.skip 0x4
.global mapMgr__18GenObjectMapObject
mapMgr__18GenObjectMapObject:
	.skip 0x8
.global titleWindow
titleWindow:
	.skip 0x4
.global titleWindowOn
titleWindowOn:
	.skip 0x4
.global totalWindow_1
totalWindow_1:
	.skip 0x4
.global totalWindowOn
totalWindowOn:
	.skip 0x4
.global startWindow
startWindow:
	.skip 0x4
.global startWindowOn
startWindowOn:
	.skip 0x4
.global spin$localstatic0$draw__17TitleSetupSectionFR8Graphics
spin$localstatic0$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global init$localstatic1$draw__17TitleSetupSectionFR8Graphics
init$localstatic1$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global chas$localstatic2$draw__17TitleSetupSectionFR8Graphics
chas$localstatic2$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global init$localstatic3$draw__17TitleSetupSectionFR8Graphics
init$localstatic3$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global cmax$localstatic4$draw__17TitleSetupSectionFR8Graphics
cmax$localstatic4$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global init$localstatic5$draw__17TitleSetupSectionFR8Graphics
init$localstatic5$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global rspin$localstatic6$draw__17TitleSetupSectionFR8Graphics
rspin$localstatic6$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global init$localstatic7$draw__17TitleSetupSectionFR8Graphics
init$localstatic7$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global mfade$localstatic8$draw__17TitleSetupSectionFR8Graphics
mfade$localstatic8$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global init$localstatic9$draw__17TitleSetupSectionFR8Graphics
init$localstatic9$draw__17TitleSetupSectionFR8Graphics:
	.skip 0x4
.global progresWindow
progresWindow:
	.skip 0x8
.global mapMgr
mapMgr:
	.skip 0x4
.global Kda
Kda:
	.skip 0x4
.global numRepeats
numRepeats:
	.skip 0x4
.global numUpdated
numUpdated:
	.skip 0x4
.global vlink
vlink:
	.skip 0x8
.global ImgH
ImgH:
	.skip 0x2
.global ImgW
ImgW:
	.skip 0x2
.global finishPlayback
finishPlayback:
	.skip 0x4
.global attentionCamera
attentionCamera:
	.skip 0x8
.global radarInfo
radarInfo:
	.skip 0x8
.global saiMotionDoneEvent
saiMotionDoneEvent:
	.skip 0x4
.global saiBounceEvent
saiBounceEvent:
	.skip 0x4
.global saiMotionLoopStartEvent
saiMotionLoopStartEvent:
	.skip 0x4
.global saiMotionLoopEndEvent
saiMotionLoopEndEvent:
	.skip 0x4
.global saiCollideEvent
saiCollideEvent:
	.skip 0x4
.global saiGroundEvent
saiGroundEvent:
	.skip 0x4
.global saiMotionAction0Event
saiMotionAction0Event:
	.skip 0x8
.global arrowShape__11GlobalShape
arrowShape__11GlobalShape:
	.skip 0x4
.global markerShape__11GlobalShape
markerShape__11GlobalShape:
	.skip 0x4
.global axisShape__11GlobalShape
axisShape__11GlobalShape:
	.skip 0x4
.global enShape__11GlobalShape
enShape__11GlobalShape:
	.skip 0x4
.global markerShape2__11GlobalShape
markerShape2__11GlobalShape:
	.skip 0x4
.global cursorShape__11GlobalShape
cursorShape__11GlobalShape:
	.skip 0x4
.global preloadUFO
preloadUFO:
	.skip 0x4
.global playerState
playerState:
	.skip 0x4
.global demoParms
demoParms:
	.skip 0x8
.global demoEventMgr
demoEventMgr:
	.skip 0x8
.global _instance__10AIConstant
_instance__10AIConstant:
	.skip 0x8
.global kio
kio:
	.skip 0x4
.global fbCopy__3KIO
fbCopy__3KIO:
	.skip 0x4
.global haltMessage__3KIO
haltMessage__3KIO:
	.skip 0x8
.global _instance__9KeyConfig
_instance__9KeyConfig:
	.skip 0x8
.global showRoute__6AIPerf
showRoute__6AIPerf:
	.skip 0x1
.global generatorMode__6AIPerf
generatorMode__6AIPerf:
	.skip 0x3
.global moveType__6AIPerf
moveType__6AIPerf:
	.skip 0x4
.global kandoOnly__6AIPerf
kandoOnly__6AIPerf:
	.skip 0x1
.global soundDebug__6AIPerf
soundDebug__6AIPerf:
	.skip 0x1
.global updateSearchBuffer__6AIPerf
updateSearchBuffer__6AIPerf:
	.skip 0x1
.global loopOptimise__6AIPerf
loopOptimise__6AIPerf:
	.skip 0x1
.global useUpdateMgr__6AIPerf
useUpdateMgr__6AIPerf:
	.skip 0x4
.global ufoLevel__6AIPerf
ufoLevel__6AIPerf:
	.skip 0x4
.global searchCnt__6AIPerf
searchCnt__6AIPerf:
	.skip 0x4
.global searchCullCnt__6AIPerf
searchCullCnt__6AIPerf:
	.skip 0x4
.global searchInsertCnt__6AIPerf
searchInsertCnt__6AIPerf:
	.skip 0x4
.global collisionCnt__6AIPerf
collisionCnt__6AIPerf:
	.skip 0x4
.global iteratorCullCnt__6AIPerf
iteratorCullCnt__6AIPerf:
	.skip 0x4
.global aiCullCnt__6AIPerf
aiCullCnt__6AIPerf:
	.skip 0x4
.global viewCullCnt__6AIPerf
viewCullCnt__6AIPerf:
	.skip 0x4
.global outsideViewCnt__6AIPerf
outsideViewCnt__6AIPerf:
	.skip 0x4
.global drawshapeCullCnt__6AIPerf
drawshapeCullCnt__6AIPerf:
	.skip 0x4
.global collision__11CourseDebug
collision__11CourseDebug:
	.skip 0x4
.global pikiNoAttack__11CourseDebug
pikiNoAttack__11CourseDebug:
	.skip 0x4
.global noCarryover__11CourseDebug
noCarryover__11CourseDebug:
	.skip 0x4
.global pelletDebug__11CourseDebug
pelletDebug__11CourseDebug:
	.skip 0x4
.global memStat
memStat:
	.skip 0x8
.global numTris
numTris:
	.skip 0x4
.global baseTri
baseTri:
	.skip 0x4
.global checkRadius
checkRadius:
	.skip 0x8
.global particleHeap
particleHeap:
	.skip 0x8
.global aiGridMap__8FastGrid
aiGridMap__8FastGrid:
	.skip 0x4
.global aiGridSize__8FastGrid
aiGridSize__8FastGrid:
	.skip 0x4
.global SmartTurnOver
SmartTurnOver:
	.skip 0x4
.global count$1859
count$1859:
	.skip 0x4
.global init$1860
init$1860:
	.skip 0x4
.global pelletMgr
pelletMgr:
	.skip 0x4
.global workObjectMgr
workObjectMgr:
	.skip 0x8
.global mode__10PathFinder
mode__10PathFinder:
	.skip 0x4
.global routeMgr
routeMgr:
	.skip 0x4
.global seMgr
seMgr:
	.skip 0x8
.global seSystem
seSystem:
	.skip 0x8
.global pikiUpdateMgr
pikiUpdateMgr:
	.skip 0x4
.global searchUpdateMgr
searchUpdateMgr:
	.skip 0x4
.global pikiLookUpdateMgr
pikiLookUpdateMgr:
	.skip 0x4
.global pikiOptUpdateMgr
pikiOptUpdateMgr:
	.skip 0x4
.global tekiOptUpdateMgr
tekiOptUpdateMgr:
	.skip 0x8
.global uniqueInstance__7AiTable
uniqueInstance__7AiTable:
	.skip 0x8
.global directDumpMode__4Piki
directDumpMode__4Piki:
	.skip 0x8
.global pikiMgr
pikiMgr:
	.skip 0x4
.global containerDebug__7PikiMgr
containerDebug__7PikiMgr:
	.skip 0x1
.global meBirthMode__7PikiMgr
meBirthMode__7PikiMgr:
	.skip 0x1
.global meNukiMode__7PikiMgr
meNukiMode__7PikiMgr:
	.skip 0x1
.global containerExitMode__7PikiMgr
containerExitMode__7PikiMgr:
	.skip 0x1
.global ramMode__9Generator
ramMode__9Generator:
	.skip 0x4
.global factory__16GenObjectFactory
factory__16GenObjectFactory:
	.skip 0x4
.global factory__14GenTypeFactory
factory__14GenTypeFactory:
	.skip 0x4
.global factory__14GenAreaFactory
factory__14GenAreaFactory:
	.skip 0x4
.global generatorMgr
generatorMgr:
	.skip 0x4
.global plantGeneratorMgr
plantGeneratorMgr:
	.skip 0x4
.global dailyGeneratorMgr
dailyGeneratorMgr:
	.skip 0x4
.global onceGeneratorMgr
onceGeneratorMgr:
	.skip 0x4
.global limitGeneratorMgr
limitGeneratorMgr:
	.skip 0x4
.global generatorList
generatorList:
	.skip 0x4
.global generatorCache
generatorCache:
	.skip 0x8
.global demoHideFlag__8GoalItem
demoHideFlag__8GoalItem:
	.skip 0x8
.global buryMode__11PikiHeadMgr
buryMode__11PikiHeadMgr:
	.skip 0x4
.global itemMgr
itemMgr:
	.skip 0x4
.global controllerLen
controllerLen:
	.skip 0x4
.global ang$5655
ang$5655:
	.skip 0x4
.global init$5656
init$5656:
	.skip 0x8
.global lastDamage
lastDamage:
	.skip 0x1
.global currDamage
currDamage:
	.skip 0x3
.global damageParm
damageParm:
	.skip 0x4
.global pauseFlag__15GameCoreSection
pauseFlag__15GameCoreSection:
	.skip 0x4
.global textDemoState__15GameCoreSection
textDemoState__15GameCoreSection:
	.skip 0x4
.global textDemoTimer__15GameCoreSection
textDemoTimer__15GameCoreSection:
	.skip 0x4
.global textDemoIndex__15GameCoreSection
textDemoIndex__15GameCoreSection:
	.skip 0x4
.global cameraMgr
cameraMgr:
	.skip 0x4
.global containerWindow
containerWindow:
	.skip 0x4
.global hurryupWindow
hurryupWindow:
	.skip 0x4
.global accountWindow
accountWindow:
	.skip 0x4
.global timer$4155
timer$4155:
	.skip 0x4
.global init$4156
init$4156:
	.skip 0x4
.global wintex
wintex:
	.skip 0x4
.global font
font:
	.skip 0x4
.global killTekis__8GameStat
killTekis__8GameStat:
	.skip 0x4
.global getPellets__8GameStat
getPellets__8GameStat:
	.skip 0x4
.global minPikis__8GameStat
minPikis__8GameStat:
	.skip 0x4
.global maxPikis__8GameStat
maxPikis__8GameStat:
	.skip 0x4
.global orimaDead__8GameStat
orimaDead__8GameStat:
	.skip 0x8
.global utEffectMgr
utEffectMgr:
	.skip 0x4
.global effects__11UtEffectMgr
effects__11UtEffectMgr:
	.skip 0x4
.global controllerBuffer
controllerBuffer:
	.skip 0x8
.global naviMgr
naviMgr:
	.skip 0x8
.global mapMgr__17GenObjectMapParts
mapMgr__17GenObjectMapParts:
	.skip 0x4
.global first$817
first$817:
	.skip 0x1
.global init$818
init$818:
	.skip 0x3
.global actorMgr
actorMgr:
	.skip 0x8
.global pikiInfo
pikiInfo:
	.skip 0x8
.global plantMgr
plantMgr:
	.skip 0x8
.global nakataDebugMode
nakataDebugMode:
	.skip 0x8
.global system__7NSystem
system__7NSystem:
	.skip 0x8
.global motionTable__15PaniPikiAnimMgr
motionTable__15PaniPikiAnimMgr:
	.skip 0x8
.global tekiMgr
tekiMgr:
	.skip 0x8
.global bossMgr
bossMgr:
	.skip 0x8
.global vibSpin$2820
vibSpin$2820:
	.skip 0x4
.global init$2821
init$2821:
	.skip 0x4
.global rumbleMgr
rumbleMgr:
	.skip 0x8
.global effectMgr
effectMgr:
	.skip 0x8
.global eventCallBackFire__10FireEffect
eventCallBackFire__10FireEffect:
	.skip 0x8
.global effectScale0__12TAIAdyingMar
effectScale0__12TAIAdyingMar:
	.skip 0x4
.global effectScale1__12TAIAdyingMar
effectScale1__12TAIAdyingMar:
	.skip 0x4
.global effectStartCounter__12TAIAdyingMar
effectStartCounter__12TAIAdyingMar:
	.skip 0x4
.global eventCallBack__12BreathEffect
eventCallBack__12BreathEffect:
	.skip 0x4
.global pGameInfo__3zen
pGameInfo__3zen:
	.skip 0x8
.global pUpTex__Q23zen19ArrowCenterCallBack
pUpTex__Q23zen19ArrowCenterCallBack:
	.skip 0x4
.global pDownTex__Q23zen19ArrowCenterCallBack
pDownTex__Q23zen19ArrowCenterCallBack:
	.skip 0x4
