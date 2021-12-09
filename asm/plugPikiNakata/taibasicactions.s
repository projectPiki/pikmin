.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global start__20TaiActionStateActionFR4Teki
start__20TaiActionStateActionFR4Teki:
/* 801283A8 00125308  38 00 00 00 */	li r0, 0
/* 801283AC 0012530C  90 04 03 38 */	stw r0, 0x338(r4)
/* 801283B0 00125310  4E 80 00 20 */	blr 

.global act__20TaiActionStateActionFR4Teki
act__20TaiActionStateActionFR4Teki:
/* 801283B4 00125314  80 84 03 38 */	lwz r4, 0x338(r4)
/* 801283B8 00125318  80 03 00 08 */	lwz r0, 8(r3)
/* 801283BC 0012531C  7C 04 00 00 */	cmpw r4, r0
/* 801283C0 00125320  40 82 00 0C */	bne lbl_801283CC
/* 801283C4 00125324  38 60 00 01 */	li r3, 1
/* 801283C8 00125328  4E 80 00 20 */	blr 
lbl_801283CC:
/* 801283CC 0012532C  38 60 00 00 */	li r3, 0
/* 801283D0 00125330  4E 80 00 20 */	blr 

.global start__18TaiSetOptionActionFR4Teki
start__18TaiSetOptionActionFR4Teki:
/* 801283D4 00125334  7C 08 02 A6 */	mflr r0
/* 801283D8 00125338  7C 65 1B 78 */	mr r5, r3
/* 801283DC 0012533C  90 01 00 04 */	stw r0, 4(r1)
/* 801283E0 00125340  94 21 FF F8 */	stwu r1, -8(r1)
/* 801283E4 00125344  88 03 00 0C */	lbz r0, 0xc(r3)
/* 801283E8 00125348  28 00 00 00 */	cmplwi r0, 0
/* 801283EC 0012534C  41 82 00 20 */	beq lbl_8012840C
/* 801283F0 00125350  7C 83 23 78 */	mr r3, r4
/* 801283F4 00125354  80 85 00 08 */	lwz r4, 8(r5)
/* 801283F8 00125358  81 83 00 00 */	lwz r12, 0(r3)
/* 801283FC 0012535C  81 8C 01 CC */	lwz r12, 0x1cc(r12)
/* 80128400 00125360  7D 88 03 A6 */	mtlr r12
/* 80128404 00125364  4E 80 00 21 */	blrl 
/* 80128408 00125368  48 00 00 1C */	b lbl_80128424
lbl_8012840C:
/* 8012840C 0012536C  7C 83 23 78 */	mr r3, r4
/* 80128410 00125370  80 85 00 08 */	lwz r4, 8(r5)
/* 80128414 00125374  81 83 00 00 */	lwz r12, 0(r3)
/* 80128418 00125378  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 8012841C 0012537C  7D 88 03 A6 */	mtlr r12
/* 80128420 00125380  4E 80 00 21 */	blrl 
lbl_80128424:
/* 80128424 00125384  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80128428 00125388  38 21 00 08 */	addi r1, r1, 8
/* 8012842C 0012538C  7C 08 03 A6 */	mtlr r0
/* 80128430 00125390  4E 80 00 20 */	blr 

.global start__18TaiPlaySoundActionFR4Teki
start__18TaiPlaySoundActionFR4Teki:
/* 80128434 00125394  7C 08 02 A6 */	mflr r0
/* 80128438 00125398  38 A3 00 00 */	addi r5, r3, 0
/* 8012843C 0012539C  90 01 00 04 */	stw r0, 4(r1)
/* 80128440 001253A0  38 64 00 00 */	addi r3, r4, 0
/* 80128444 001253A4  94 21 FF F8 */	stwu r1, -8(r1)
/* 80128448 001253A8  81 83 00 00 */	lwz r12, 0(r3)
/* 8012844C 001253AC  80 85 00 08 */	lwz r4, 8(r5)
/* 80128450 001253B0  81 8C 01 C0 */	lwz r12, 0x1c0(r12)
/* 80128454 001253B4  7D 88 03 A6 */	mtlr r12
/* 80128458 001253B8  4E 80 00 21 */	blrl 
/* 8012845C 001253BC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80128460 001253C0  38 21 00 08 */	addi r1, r1, 8
/* 80128464 001253C4  7C 08 03 A6 */	mtlr r0
/* 80128468 001253C8  4E 80 00 20 */	blr 

.global start__18TaiStopSoundActionFR4Teki
start__18TaiStopSoundActionFR4Teki:
/* 8012846C 001253CC  7C 08 02 A6 */	mflr r0
/* 80128470 001253D0  38 A3 00 00 */	addi r5, r3, 0
/* 80128474 001253D4  90 01 00 04 */	stw r0, 4(r1)
/* 80128478 001253D8  38 64 00 00 */	addi r3, r4, 0
/* 8012847C 001253DC  94 21 FF F8 */	stwu r1, -8(r1)
/* 80128480 001253E0  81 83 00 00 */	lwz r12, 0(r3)
/* 80128484 001253E4  80 85 00 08 */	lwz r4, 8(r5)
/* 80128488 001253E8  81 8C 01 C4 */	lwz r12, 0x1c4(r12)
/* 8012848C 001253EC  7D 88 03 A6 */	mtlr r12
/* 80128490 001253F0  4E 80 00 21 */	blrl 
/* 80128494 001253F4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80128498 001253F8  38 21 00 08 */	addi r1, r1, 8
/* 8012849C 001253FC  7C 08 03 A6 */	mtlr r0
/* 801284A0 00125400  4E 80 00 20 */	blr 

.global start__30TaiTypeNaviWatchResultOnActionFR4Teki
start__30TaiTypeNaviWatchResultOnActionFR4Teki:
/* 801284A4 00125404  7C 08 02 A6 */	mflr r0
/* 801284A8 00125408  90 01 00 04 */	stw r0, 4(r1)
/* 801284AC 0012540C  94 21 FF F8 */	stwu r1, -8(r1)
/* 801284B0 00125410  80 04 00 C8 */	lwz r0, 0xc8(r4)
/* 801284B4 00125414  54 00 03 19 */	rlwinm. r0, r0, 0, 0xc, 0xc
/* 801284B8 00125418  40 82 00 20 */	bne lbl_801284D8
/* 801284BC 0012541C  80 6D 31 60 */	lwz r3, tekiMgr@sda21(r13)
/* 801284C0 00125420  80 84 03 20 */	lwz r4, 0x320(r4)
/* 801284C4 00125424  48 02 2B 81 */	bl getResultFlag__7TekiMgrFi
/* 801284C8 00125428  80 AD 2F 6C */	lwz r5, playerState@sda21(r13)
/* 801284CC 0012542C  38 83 00 00 */	addi r4, r3, 0
/* 801284D0 00125430  38 65 00 70 */	addi r3, r5, 0x70
/* 801284D4 00125434  4B F5 B5 2D */	bl setOn__11ResultFlagsFi
lbl_801284D8:
/* 801284D8 00125438  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801284DC 0012543C  38 21 00 08 */	addi r1, r1, 8
/* 801284E0 00125440  7C 08 03 A6 */	mtlr r0
/* 801284E4 00125444  4E 80 00 20 */	blr 

.global start__26TaiNaviWatchResultOnActionFR4Teki
start__26TaiNaviWatchResultOnActionFR4Teki:
/* 801284E8 00125448  7C 08 02 A6 */	mflr r0
/* 801284EC 0012544C  90 01 00 04 */	stw r0, 4(r1)
/* 801284F0 00125450  94 21 FF F8 */	stwu r1, -8(r1)
/* 801284F4 00125454  80 04 00 C8 */	lwz r0, 0xc8(r4)
/* 801284F8 00125458  54 00 03 19 */	rlwinm. r0, r0, 0, 0xc, 0xc
/* 801284FC 0012545C  40 82 00 14 */	bne lbl_80128510
/* 80128500 00125460  80 AD 2F 6C */	lwz r5, playerState@sda21(r13)
/* 80128504 00125464  80 83 00 08 */	lwz r4, 8(r3)
/* 80128508 00125468  38 65 00 70 */	addi r3, r5, 0x70
/* 8012850C 0012546C  4B F5 B4 F5 */	bl setOn__11ResultFlagsFi
lbl_80128510:
/* 80128510 00125470  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80128514 00125474  38 21 00 08 */	addi r1, r1, 8
/* 80128518 00125478  7C 08 03 A6 */	mtlr r0
/* 8012851C 0012547C  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C69C0:
	.asciz "taibasicactions.cpp"
.balign 4
lbl_802C69D4:
	.asciz "taibasicactions"
.balign 4
lbl_802C69E4:
	.asciz "TaiNaviWatchResultOnAction"
.balign 4
lbl_802C6A00:
	.asciz "TaiAction"
.balign 4
lbl_802C6A0C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__26TaiNaviWatchResultOnAction
__vt__26TaiNaviWatchResultOnAction:
	.4byte __RTTI__26TaiNaviWatchResultOnAction
	.4byte 0
	.4byte start__26TaiNaviWatchResultOnActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C6A34:
	.asciz "TaiTypeNaviWatchResultOnAction"
.balign 4
lbl_802C6A54:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__30TaiTypeNaviWatchResultOnAction
__vt__30TaiTypeNaviWatchResultOnAction:
	.4byte __RTTI__30TaiTypeNaviWatchResultOnAction
	.4byte 0
	.4byte start__30TaiTypeNaviWatchResultOnActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C6A7C:
	.asciz "TaiStopSoundAction"
.balign 4
lbl_802C6A90:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__18TaiStopSoundAction
__vt__18TaiStopSoundAction:
	.4byte __RTTI__18TaiStopSoundAction
	.4byte 0
	.4byte start__18TaiStopSoundActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C6AB8:
	.asciz "TaiPlaySoundAction"
.balign 4
lbl_802C6ACC:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__18TaiPlaySoundAction
__vt__18TaiPlaySoundAction:
	.4byte __RTTI__18TaiPlaySoundAction
	.4byte 0
	.4byte start__18TaiPlaySoundActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C6AF4:
	.asciz "TaiSetOptionAction"
.balign 4
lbl_802C6B08:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__18TaiSetOptionAction
__vt__18TaiSetOptionAction:
	.4byte __RTTI__18TaiSetOptionAction
	.4byte 0
	.4byte start__18TaiSetOptionActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C6B30:
	.asciz "TaiActionStateAction"
.balign 4
lbl_802C6B48:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__20TaiActionStateAction
__vt__20TaiActionStateAction:
	.4byte __RTTI__20TaiActionStateAction
	.4byte 0
	.4byte start__20TaiActionStateActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__20TaiActionStateActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__9TaiAction:
	.4byte lbl_802C6A00
	.4byte 0
__RTTI__26TaiNaviWatchResultOnAction:
	.4byte lbl_802C69E4
	.4byte lbl_802C6A0C
__RTTI__30TaiTypeNaviWatchResultOnAction:
	.4byte lbl_802C6A34
	.4byte lbl_802C6A54
__RTTI__18TaiStopSoundAction:
	.4byte lbl_802C6A7C
	.4byte lbl_802C6A90
__RTTI__18TaiPlaySoundAction:
	.4byte lbl_802C6AB8
	.4byte lbl_802C6ACC
__RTTI__18TaiSetOptionAction:
	.4byte lbl_802C6AF4
	.4byte lbl_802C6B08
__RTTI__20TaiActionStateAction:
	.4byte lbl_802C6B30
	.4byte lbl_802C6B48
