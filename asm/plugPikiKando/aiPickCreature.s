.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__15ActPickCreatureFP4Piki
__ct__15ActPickCreatureFP4Piki:
/* 800BD364 000BA2C4  7C 08 02 A6 */	mflr r0
/* 800BD368 000BA2C8  38 A0 00 01 */	li r5, 1
/* 800BD36C 000BA2CC  90 01 00 04 */	stw r0, 4(r1)
/* 800BD370 000BA2D0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BD374 000BA2D4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BD378 000BA2D8  7C 9F 23 78 */	mr r31, r4
/* 800BD37C 000BA2DC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800BD380 000BA2E0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800BD384 000BA2E4  90 61 00 08 */	stw r3, 8(r1)
/* 800BD388 000BA2E8  83 C1 00 08 */	lwz r30, 8(r1)
/* 800BD38C 000BA2EC  38 7E 00 00 */	addi r3, r30, 0
/* 800BD390 000BA2F0  48 00 6A 41 */	bl __ct__6ActionFP4Pikib
/* 800BD394 000BA2F4  3C 60 80 2C */	lis r3, __vt__9AndAction@ha
/* 800BD398 000BA2F8  38 03 81 30 */	addi r0, r3, __vt__9AndAction@l
/* 800BD39C 000BA2FC  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD3A0 000BA300  38 80 00 00 */	li r4, 0
/* 800BD3A4 000BA304  3C 60 80 2B */	lis r3, __vt__15ActPickCreature@ha
/* 800BD3A8 000BA308  90 9E 00 14 */	stw r4, 0x14(r30)
/* 800BD3AC 000BA30C  38 03 70 D8 */	addi r0, r3, __vt__15ActPickCreature@l
/* 800BD3B0 000BA310  38 60 00 24 */	li r3, 0x24
/* 800BD3B4 000BA314  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD3B8 000BA318  90 9E 00 18 */	stw r4, 0x18(r30)
/* 800BD3BC 000BA31C  4B F8 9C 49 */	bl alloc__6SystemFUl
/* 800BD3C0 000BA320  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BD3C4 000BA324  41 82 00 10 */	beq lbl_800BD3D4
/* 800BD3C8 000BA328  38 7E 00 00 */	addi r3, r30, 0
/* 800BD3CC 000BA32C  38 9F 00 00 */	addi r4, r31, 0
/* 800BD3D0 000BA330  4B FF DB 99 */	bl __ct__7ActGotoFP4Piki
lbl_800BD3D4:
/* 800BD3D4 000BA334  38 60 00 20 */	li r3, 0x20
/* 800BD3D8 000BA338  4B F8 9C 2D */	bl alloc__6SystemFUl
/* 800BD3DC 000BA33C  7C 7D 1B 79 */	or. r29, r3, r3
/* 800BD3E0 000BA340  41 82 00 10 */	beq lbl_800BD3F0
/* 800BD3E4 000BA344  38 7D 00 00 */	addi r3, r29, 0
/* 800BD3E8 000BA348  38 9F 00 00 */	addi r4, r31, 0
/* 800BD3EC 000BA34C  4B FE A6 0D */	bl __ct__7ActPickFP4Piki
lbl_800BD3F0:
/* 800BD3F0 000BA350  80 61 00 08 */	lwz r3, 8(r1)
/* 800BD3F4 000BA354  38 BE 00 00 */	addi r5, r30, 0
/* 800BD3F8 000BA358  38 FD 00 00 */	addi r7, r29, 0
/* 800BD3FC 000BA35C  4C C6 31 82 */	crclr 6
/* 800BD400 000BA360  38 80 00 02 */	li r4, 2
/* 800BD404 000BA364  38 C0 00 00 */	li r6, 0
/* 800BD408 000BA368  39 00 00 00 */	li r8, 0
/* 800BD40C 000BA36C  48 00 6F 65 */	bl setChildren__6ActionFie
/* 800BD410 000BA370  80 61 00 08 */	lwz r3, 8(r1)
/* 800BD414 000BA374  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BD418 000BA378  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BD41C 000BA37C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800BD420 000BA380  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800BD424 000BA384  38 21 00 20 */	addi r1, r1, 0x20
/* 800BD428 000BA388  7C 08 03 A6 */	mtlr r0
/* 800BD42C 000BA38C  4E 80 00 20 */	blr 

.global init__15ActPickCreatureFP8Creature
init__15ActPickCreatureFP8Creature:
/* 800BD430 000BA390  7C 08 02 A6 */	mflr r0
/* 800BD434 000BA394  90 01 00 04 */	stw r0, 4(r1)
/* 800BD438 000BA398  94 21 FF F8 */	stwu r1, -8(r1)
/* 800BD43C 000BA39C  48 00 6A D9 */	bl init__9AndActionFP8Creature
/* 800BD440 000BA3A0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800BD444 000BA3A4  38 21 00 08 */	addi r1, r1, 8
/* 800BD448 000BA3A8  7C 08 03 A6 */	mtlr r0
/* 800BD44C 000BA3AC  4E 80 00 20 */	blr 

.global initialise__Q210ActDeliver11InitialiserFP6Action
initialise__Q210ActDeliver11InitialiserFP6Action:
/* 800BD450 000BA3B0  7C 08 02 A6 */	mflr r0
/* 800BD454 000BA3B4  90 01 00 04 */	stw r0, 4(r1)
/* 800BD458 000BA3B8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BD45C 000BA3BC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BD460 000BA3C0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BD464 000BA3C4  7C 9E 23 78 */	mr r30, r4
/* 800BD468 000BA3C8  83 E3 00 04 */	lwz r31, 4(r3)
/* 800BD46C 000BA3CC  80 64 00 18 */	lwz r3, 0x18(r4)
/* 800BD470 000BA3D0  28 03 00 00 */	cmplwi r3, 0
/* 800BD474 000BA3D4  41 82 00 14 */	beq lbl_800BD488
/* 800BD478 000BA3D8  41 82 00 10 */	beq lbl_800BD488
/* 800BD47C 000BA3DC  48 02 6E F1 */	bl subCnt__12RefCountableFv
/* 800BD480 000BA3E0  38 00 00 00 */	li r0, 0
/* 800BD484 000BA3E4  90 1E 00 18 */	stw r0, 0x18(r30)
lbl_800BD488:
/* 800BD488 000BA3E8  93 FE 00 18 */	stw r31, 0x18(r30)
/* 800BD48C 000BA3EC  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800BD490 000BA3F0  28 03 00 00 */	cmplwi r3, 0
/* 800BD494 000BA3F4  41 82 00 08 */	beq lbl_800BD49C
/* 800BD498 000BA3F8  48 02 6E C5 */	bl addCnt__12RefCountableFv
lbl_800BD49C:
/* 800BD49C 000BA3FC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BD4A0 000BA400  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BD4A4 000BA404  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BD4A8 000BA408  38 21 00 18 */	addi r1, r1, 0x18
/* 800BD4AC 000BA40C  7C 08 03 A6 */	mtlr r0
/* 800BD4B0 000BA410  4E 80 00 20 */	blr 

.global init__10ActDeliverFP8Creature
init__10ActDeliverFP8Creature:
/* 800BD4B4 000BA414  7C 08 02 A6 */	mflr r0
/* 800BD4B8 000BA418  90 01 00 04 */	stw r0, 4(r1)
/* 800BD4BC 000BA41C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BD4C0 000BA420  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BD4C4 000BA424  3B E4 00 00 */	addi r31, r4, 0
/* 800BD4C8 000BA428  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800BD4CC 000BA42C  3B C3 00 00 */	addi r30, r3, 0
/* 800BD4D0 000BA430  48 00 6A 45 */	bl init__9AndActionFP8Creature
/* 800BD4D4 000BA434  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800BD4D8 000BA438  28 03 00 00 */	cmplwi r3, 0
/* 800BD4DC 000BA43C  40 82 00 30 */	bne lbl_800BD50C
/* 800BD4E0 000BA440  41 82 00 14 */	beq lbl_800BD4F4
/* 800BD4E4 000BA444  41 82 00 10 */	beq lbl_800BD4F4
/* 800BD4E8 000BA448  48 02 6E 85 */	bl subCnt__12RefCountableFv
/* 800BD4EC 000BA44C  38 00 00 00 */	li r0, 0
/* 800BD4F0 000BA450  90 1E 00 18 */	stw r0, 0x18(r30)
lbl_800BD4F4:
/* 800BD4F4 000BA454  93 FE 00 18 */	stw r31, 0x18(r30)
/* 800BD4F8 000BA458  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800BD4FC 000BA45C  28 03 00 00 */	cmplwi r3, 0
/* 800BD500 000BA460  41 82 00 20 */	beq lbl_800BD520
/* 800BD504 000BA464  48 02 6E 59 */	bl addCnt__12RefCountableFv
/* 800BD508 000BA468  48 00 00 18 */	b lbl_800BD520
lbl_800BD50C:
/* 800BD50C 000BA46C  80 9E 00 04 */	lwz r4, 4(r30)
/* 800BD510 000BA470  80 84 00 0C */	lwz r4, 0xc(r4)
/* 800BD514 000BA474  28 04 00 00 */	cmplwi r4, 0
/* 800BD518 000BA478  41 82 00 08 */	beq lbl_800BD520
/* 800BD51C 000BA47C  90 64 00 04 */	stw r3, 4(r4)
lbl_800BD520:
/* 800BD520 000BA480  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BD524 000BA484  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BD528 000BA488  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800BD52C 000BA48C  38 21 00 20 */	addi r1, r1, 0x20
/* 800BD530 000BA490  7C 08 03 A6 */	mtlr r0
/* 800BD534 000BA494  4E 80 00 20 */	blr 

.global __dt__10ActDeliverFv
__dt__10ActDeliverFv:
/* 800BD538 000BA498  7C 08 02 A6 */	mflr r0
/* 800BD53C 000BA49C  90 01 00 04 */	stw r0, 4(r1)
/* 800BD540 000BA4A0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BD544 000BA4A4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BD548 000BA4A8  3B E4 00 00 */	addi r31, r4, 0
/* 800BD54C 000BA4AC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BD550 000BA4B0  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BD554 000BA4B4  41 82 00 3C */	beq lbl_800BD590
/* 800BD558 000BA4B8  3C 60 80 2B */	lis r3, __vt__10ActDeliver@ha
/* 800BD55C 000BA4BC  38 03 6F F8 */	addi r0, r3, __vt__10ActDeliver@l
/* 800BD560 000BA4C0  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD564 000BA4C4  41 82 00 1C */	beq lbl_800BD580
/* 800BD568 000BA4C8  3C 60 80 2C */	lis r3, __vt__9AndAction@ha
/* 800BD56C 000BA4CC  38 03 81 30 */	addi r0, r3, __vt__9AndAction@l
/* 800BD570 000BA4D0  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD574 000BA4D4  38 7E 00 00 */	addi r3, r30, 0
/* 800BD578 000BA4D8  38 80 00 00 */	li r4, 0
/* 800BD57C 000BA4DC  48 00 68 8D */	bl __dt__6ActionFv
lbl_800BD580:
/* 800BD580 000BA4E0  7F E0 07 35 */	extsh. r0, r31
/* 800BD584 000BA4E4  40 81 00 0C */	ble lbl_800BD590
/* 800BD588 000BA4E8  7F C3 F3 78 */	mr r3, r30
/* 800BD58C 000BA4EC  4B F8 9C 21 */	bl __dl__FPv
lbl_800BD590:
/* 800BD590 000BA4F0  7F C3 F3 78 */	mr r3, r30
/* 800BD594 000BA4F4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BD598 000BA4F8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BD59C 000BA4FC  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BD5A0 000BA500  38 21 00 18 */	addi r1, r1, 0x18
/* 800BD5A4 000BA504  7C 08 03 A6 */	mtlr r0
/* 800BD5A8 000BA508  4E 80 00 20 */	blr 

.global defaultInitialiser__10ActDeliverFv
defaultInitialiser__10ActDeliverFv:
/* 800BD5AC 000BA50C  38 00 00 00 */	li r0, 0
/* 800BD5B0 000BA510  90 03 00 18 */	stw r0, 0x18(r3)
/* 800BD5B4 000BA514  4E 80 00 20 */	blr 

.global cleanup__10ActDeliverFv
cleanup__10ActDeliverFv:
/* 800BD5B8 000BA518  7C 08 02 A6 */	mflr r0
/* 800BD5BC 000BA51C  90 01 00 04 */	stw r0, 4(r1)
/* 800BD5C0 000BA520  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BD5C4 000BA524  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BD5C8 000BA528  7C 7F 1B 78 */	mr r31, r3
/* 800BD5CC 000BA52C  80 63 00 18 */	lwz r3, 0x18(r3)
/* 800BD5D0 000BA530  28 03 00 00 */	cmplwi r3, 0
/* 800BD5D4 000BA534  41 82 00 10 */	beq lbl_800BD5E4
/* 800BD5D8 000BA538  48 02 6D 95 */	bl subCnt__12RefCountableFv
/* 800BD5DC 000BA53C  38 00 00 00 */	li r0, 0
/* 800BD5E0 000BA540  90 1F 00 18 */	stw r0, 0x18(r31)
lbl_800BD5E4:
/* 800BD5E4 000BA544  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BD5E8 000BA548  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BD5EC 000BA54C  38 21 00 18 */	addi r1, r1, 0x18
/* 800BD5F0 000BA550  7C 08 03 A6 */	mtlr r0
/* 800BD5F4 000BA554  4E 80 00 20 */	blr 

.global initialise__Q26Action11InitialiserFP6Action
initialise__Q26Action11InitialiserFP6Action:
/* 800BD5F8 000BA558  4E 80 00 20 */	blr 

.global __dt__15ActPickCreatureFv
__dt__15ActPickCreatureFv:
/* 800BD5FC 000BA55C  7C 08 02 A6 */	mflr r0
/* 800BD600 000BA560  90 01 00 04 */	stw r0, 4(r1)
/* 800BD604 000BA564  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BD608 000BA568  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BD60C 000BA56C  3B E4 00 00 */	addi r31, r4, 0
/* 800BD610 000BA570  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BD614 000BA574  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BD618 000BA578  41 82 00 3C */	beq lbl_800BD654
/* 800BD61C 000BA57C  3C 60 80 2B */	lis r3, __vt__15ActPickCreature@ha
/* 800BD620 000BA580  38 03 70 D8 */	addi r0, r3, __vt__15ActPickCreature@l
/* 800BD624 000BA584  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD628 000BA588  41 82 00 1C */	beq lbl_800BD644
/* 800BD62C 000BA58C  3C 60 80 2C */	lis r3, __vt__9AndAction@ha
/* 800BD630 000BA590  38 03 81 30 */	addi r0, r3, __vt__9AndAction@l
/* 800BD634 000BA594  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD638 000BA598  38 7E 00 00 */	addi r3, r30, 0
/* 800BD63C 000BA59C  38 80 00 00 */	li r4, 0
/* 800BD640 000BA5A0  48 00 67 C9 */	bl __dt__6ActionFv
lbl_800BD644:
/* 800BD644 000BA5A4  7F E0 07 35 */	extsh. r0, r31
/* 800BD648 000BA5A8  40 81 00 0C */	ble lbl_800BD654
/* 800BD64C 000BA5AC  7F C3 F3 78 */	mr r3, r30
/* 800BD650 000BA5B0  4B F8 9B 5D */	bl __dl__FPv
lbl_800BD654:
/* 800BD654 000BA5B4  7F C3 F3 78 */	mr r3, r30
/* 800BD658 000BA5B8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BD65C 000BA5BC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BD660 000BA5C0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BD664 000BA5C4  38 21 00 18 */	addi r1, r1, 0x18
/* 800BD668 000BA5C8  7C 08 03 A6 */	mtlr r0
/* 800BD66C 000BA5CC  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802B6F70:
	.asciz "aiPickCreature.cpp"
.balign 4
lbl_802B6F84:
	.asciz "pickCreature\n"
.balign 4
lbl_802B6F94:
	.asciz "ActDeliver"
.balign 4
lbl_802B6FA0:
	.asciz "Receiver<Piki>"
.balign 4
lbl_802B6FB0:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.balign 4
lbl_802B6FBC:
	.asciz "AndAction"
.balign 4
lbl_802B6FC8:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
lbl_802B6FDC:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte __RTTI__9AndAction
	.4byte 0
	.4byte 0
.global __vt__10ActDeliver
__vt__10ActDeliver:
	.4byte __RTTI__10ActDeliver
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__10ActDeliverFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__10ActDeliverFv
	.4byte init__10ActDeliverFP8Creature
	.4byte exec__9AndActionFv
	.4byte cleanup__10ActDeliverFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
.balign 4
lbl_802B705C:
	.asciz "ActDeliver::Initialiser"
.balign 4
lbl_802B7074:
	.asciz "Action::Initialiser"
.balign 4
lbl_802B7088:
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte 0
.global __vt__Q210ActDeliver11Initialiser
__vt__Q210ActDeliver11Initialiser:
	.4byte __RTTI__Q210ActDeliver11Initialiser
	.4byte 0
	.4byte initialise__Q210ActDeliver11InitialiserFP6Action
.global __vt__Q26Action11Initialiser
__vt__Q26Action11Initialiser:
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte initialise__Q26Action11InitialiserFP6Action
.balign 4
lbl_802B70AC:
	.asciz "ActPickCreature"
.balign 4
lbl_802B70BC:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte __RTTI__9AndAction
	.4byte 0
	.4byte 0
.global __vt__15ActPickCreature
__vt__15ActPickCreature:
	.4byte __RTTI__15ActPickCreature
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__6ActionFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__15ActPickCreatureFv
	.4byte init__15ActPickCreatureFP8Creature
	.4byte exec__9AndActionFv
	.4byte cleanup__6ActionFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
lbl_802B713C:
	.4byte lbl_800A7908
	.4byte lbl_800A7930
	.4byte lbl_800A7944
	.4byte lbl_800A7958
	.4byte lbl_800A796C
	.4byte lbl_800A7980
	.4byte lbl_800A7994
	.4byte lbl_800A79A8
	.4byte lbl_800A791C
	.4byte lbl_800A79D0
	.4byte lbl_800A79BC

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
"__RTTI__15Receiver<4Piki>":
	.4byte lbl_802B6FA0
	.4byte 0
.balign 4
lbl_803E05A8:
	.asciz "Action"
.balign 4
__RTTI__6Action:
	.4byte lbl_803E05A8
	.4byte lbl_802B6FB0
__RTTI__9AndAction:
	.4byte lbl_802B6FBC
	.4byte lbl_802B6FC8
__RTTI__10ActDeliver:
	.4byte lbl_802B6F94
	.4byte lbl_802B6FDC
__RTTI__Q26Action11Initialiser:
	.4byte lbl_802B7074
	.4byte 0
__RTTI__Q210ActDeliver11Initialiser:
	.4byte lbl_802B705C
	.4byte lbl_802B7088
__RTTI__15ActPickCreature:
	.4byte lbl_802B70AC
	.4byte lbl_802B70BC
