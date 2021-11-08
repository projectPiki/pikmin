.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80017500 00014460  2C 00 00 00 */	cmpwi r0, 0
/* 80017504 00014464  41 82 00 18 */	beq lbl_8001751C
/* 80017508 00014468  38 60 00 00 */	li r3, 0
/* 8001750C 0001446C  38 80 00 64 */	li r4, 0x64
/* 80017510 00014470  48 00 1F F1 */	bl Jac_EasyCrossFade
/* 80017514 00014474  38 00 00 00 */	li r0, 0
/* 80017518 00014478  90 0D 2C 78 */	stw r0, demo_fade_flag@sda21(r13)
lbl_8001751C:
/* 8001751C 0001447C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80017520 00014480  38 21 00 08 */	addi r1, r1, 8
/* 80017524 00014484  7C 08 03 A6 */	mtlr r0
/* 80017528 00014488  4E 80 00 20 */	blr 
/* 8001752C 0001448C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017530 00014490  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017534 00014494  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017538 00014498  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001753C 0001449C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_StreamMovieUpdate
Jac_StreamMovieUpdate:
/* 80017540 000144A0  7C 08 02 A6 */	mflr r0
/* 80017544 000144A4  90 01 00 04 */	stw r0, 4(r1)
/* 80017548 000144A8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8001754C 000144AC  48 00 6E F5 */	bl Jac_HVQM_Update
/* 80017550 000144B0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80017554 000144B4  38 21 00 08 */	addi r1, r1, 8
/* 80017558 000144B8  7C 08 03 A6 */	mtlr r0
/* 8001755C 000144BC  4E 80 00 20 */	blr 

.global Jac_StreamMovieGetPicture
Jac_StreamMovieGetPicture:
/* 80017560 000144C0  7C 08 02 A6 */	mflr r0
/* 80017564 000144C4  90 01 00 04 */	stw r0, 4(r1)
/* 80017568 000144C8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8001756C 000144CC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80017570 000144D0  48 00 72 F1 */	bl Jac_GetPicture
/* 80017574 000144D4  3B E3 00 00 */	addi r31, r3, 0
/* 80017578 000144D8  2C 1F FF FF */	cmpwi r31, -1
/* 8001757C 000144DC  40 82 00 30 */	bne lbl_800175AC
/* 80017580 000144E0  48 00 22 C1 */	bl Jac_GetCurrentScene
/* 80017584 000144E4  28 03 00 01 */	cmplwi r3, 1
/* 80017588 000144E8  40 82 00 24 */	bne lbl_800175AC
/* 8001758C 000144EC  80 0D 2C 78 */	lwz r0, demo_fade_flag@sda21(r13)
/* 80017590 000144F0  2C 00 00 00 */	cmpwi r0, 0
/* 80017594 000144F4  41 82 00 18 */	beq lbl_800175AC
/* 80017598 000144F8  38 60 00 00 */	li r3, 0
/* 8001759C 000144FC  38 80 00 64 */	li r4, 0x64
/* 800175A0 00014500  48 00 1F 61 */	bl Jac_EasyCrossFade
/* 800175A4 00014504  38 00 00 00 */	li r0, 0
/* 800175A8 00014508  90 0D 2C 78 */	stw r0, demo_fade_flag@sda21(r13)
lbl_800175AC:
/* 800175AC 0001450C  7F E3 FB 78 */	mr r3, r31
/* 800175B0 00014510  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800175B4 00014514  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800175B8 00014518  38 21 00 20 */	addi r1, r1, 0x20
/* 800175BC 0001451C  7C 08 03 A6 */	mtlr r0
/* 800175C0 00014520  4E 80 00 20 */	blr 
/* 800175C4 00014524  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800175C8 00014528  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800175CC 0001452C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800175D0 00014530  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800175D4 00014534  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800175D8 00014538  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800175DC 0001453C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global __SetVolandPan__FP9Portargs_
__SetVolandPan__FP9Portargs_:
/* 800175E0 00014540  7C 08 02 A6 */	mflr r0
/* 800175E4 00014544  38 80 00 01 */	li r4, 1
/* 800175E8 00014548  90 01 00 04 */	stw r0, 4(r1)
/* 800175EC 0001454C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800175F0 00014550  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800175F4 00014554  83 E3 00 00 */	lwz r31, 0(r3)
/* 800175F8 00014558  80 7F 00 D0 */	lwz r3, 0xd0(r31)
/* 800175FC 0001455C  C0 3F 01 60 */	lfs f1, 0x160(r31)
/* 80017600 00014560  4B FF 93 21 */	bl Jam_SetExtParam
/* 80017604 00014564  80 7F 00 D0 */	lwz r3, 0xd0(r31)
/* 80017608 00014568  38 80 00 08 */	li r4, 8
/* 8001760C 0001456C  C0 3F 01 64 */	lfs f1, 0x164(r31)
/* 80017610 00014570  4B FF 93 11 */	bl Jam_SetExtParam
/* 80017614 00014574  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80017618 00014578  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8001761C 0001457C  38 21 00 18 */	addi r1, r1, 0x18
/* 80017620 00014580  7C 08 03 A6 */	mtlr r0
/* 80017624 00014584  4E 80 00 20 */	blr 
/* 80017628 00014588  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001762C 0001458C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017630 00014590  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017634 00014594  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80017638 00014598  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8001763C 0001459C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global SendToStack__FP7SEvent_
SendToStack__FP7SEvent_:
/* 80017640 000145A0  7C 08 02 A6 */	mflr r0
/* 80017644 000145A4  90 01 00 04 */	stw r0, 4(r1)
/* 80017648 000145A8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8001764C 000145AC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80017650 000145B0  3B E3 00 00 */	addi r31, r3, 0
/* 80017654 000145B4  3C 60 80 01 */	lis r3, __SetVolandPan__FP9Portargs_@ha
/* 80017658 000145B8  38 BF 01 40 */	addi r5, r31, 0x140
/* 8001765C 000145BC  93 FF 01 40 */	stw r31, 0x140(r31)
/* 80017660 000145C0  38 83 75 E0 */	addi r4, r3, __SetVolandPan__FP9Portargs_@l
/* 80017664 000145C4  38 7F 01 44 */	addi r3, r31, 0x144
/* 80017668 000145C8  4B FF 6C D9 */	bl Set_Portcmd
/* 8001766C 000145CC  38 7F 01 44 */	addi r3, r31, 0x144
/* 80017670 000145D0  4B FF 6C 91 */	bl Add_PortcmdOnce
/* 80017674 000145D4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80017678 000145D8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8001767C 000145DC  38 21 00 18 */	addi r1, r1, 0x18

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80056094 00052FF4  90 03 00 00 */	stw r0, 0(r3)
/* 80056098 00052FF8  93 C3 00 04 */	stw r30, 4(r3)
/* 8005609C 00052FFC  80 81 00 4C */	lwz r4, 0x4c(r1)
/* 800560A0 00053000  80 01 00 50 */	lwz r0, 0x50(r1)
/* 800560A4 00053004  90 83 00 08 */	stw r4, 8(r3)
/* 800560A8 00053008  90 03 00 0C */	stw r0, 0xc(r3)
/* 800560AC 0005300C  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800560B0 00053010  90 03 00 10 */	stw r0, 0x10(r3)
lbl_800560B4:
/* 800560B4 00053014  7C 66 1B 78 */	mr r6, r3
/* 800560B8 00053018  48 00 00 64 */	b lbl_8005611C
lbl_800560BC:
/* 800560BC 0005301C  38 60 00 14 */	li r3, 0x14
/* 800560C0 00053020  4B FF 0F 45 */	bl alloc__6SystemFUl
/* 800560C4 00053024  28 03 00 00 */	cmplwi r3, 0
/* 800560C8 00053028  41 82 00 50 */	beq lbl_80056118
/* 800560CC 0005302C  80 1F 00 28 */	lwz r0, 0x28(r31)
/* 800560D0 00053030  3C A0 80 2A */	lis r5, "__vt__18IDelegate1<R4Menu>"@ha
/* 800560D4 00053034  80 DF 00 2C */	lwz r6, 0x2c(r31)
/* 800560D8 00053038  3C 80 80 2A */	lis r4, "__vt__41Delegate1<21MapSelectSetupSection,R4Menu>"@ha
/* 800560DC 0005303C  38 A5 65 F0 */	addi r5, r5, "__vt__18IDelegate1<R4Menu>"@l
/* 800560E0 00053040  90 01 00 58 */	stw r0, 0x58(r1)
/* 800560E4 00053044  38 04 7A C4 */	addi r0, r4, "__vt__41Delegate1<21MapSelectSetupSection,R4Menu>"@l
/* 800560E8 00053048  90 C1 00 5C */	stw r6, 0x5c(r1)
/* 800560EC 0005304C  80 9F 00 30 */	lwz r4, 0x30(r31)
/* 800560F0 00053050  90 81 00 60 */	stw r4, 0x60(r1)
/* 800560F4 00053054  90 A3 00 00 */	stw r5, 0(r3)
/* 800560F8 00053058  90 03 00 00 */	stw r0, 0(r3)
/* 800560FC 0005305C  93 C3 00 04 */	stw r30, 4(r3)
/* 80056100 00053060  80 81 00 58 */	lwz r4, 0x58(r1)
/* 80056104 00053064  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 80056108 00053068  90 83 00 08 */	stw r4, 8(r3)
/* 8005610C 0005306C  90 03 00 0C */	stw r0, 0xc(r3)
/* 80056110 00053070  80 01 00 60 */	lwz r0, 0x60(r1)
/* 80056114 00053074  90 03 00 10 */	stw r0, 0x10(r3)
lbl_80056118:
/* 80056118 00053078  7C 66 1B 78 */	mr r6, r3
lbl_8005611C:
/* 8005611C 0005307C  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 80056120 00053080  38 BF 00 A0 */	addi r5, r31, 0xa0
/* 80056124 00053084  38 80 00 00 */	li r4, 0
/* 80056128 00053088  38 E0 00 01 */	li r7, 1
/* 8005612C 0005308C  48 00 79 F1 */	bl "addOption__4MenuFiPcP18IDelegate1<R4Menu>b"
/* 80056130 00053090  38 00 00 00 */	li r0, 0
/* 80056134 00053094  90 1E 00 2C */	stw r0, 0x2c(r30)
/* 80056138 00053098  90 0D 2E 54 */	stw r0, mapWindow@sda21(r13)
/* 8005613C 0005309C  90 0D 2E 50 */	stw r0, selectWindow@sda21(r13)
/* 80056140 000530A0  80 1C 00 00 */	lwz r0, 0(r28)
/* 80056144 000530A4  2C 00 00 00 */	cmpwi r0, 0
/* 80056148 000530A8  40 82 00 8C */	bne lbl_800561D4
/* 8005614C 000530AC  38 60 03 68 */	li r3, 0x368
/* 80056150 000530B0  4B FF 0E B5 */	bl alloc__6SystemFUl
/* 80056154 000530B4  3B 63 00 00 */	addi r27, r3, 0
/* 80056158 000530B8  7F 63 DB 79 */	or. r3, r27, r27
/* 8005615C 000530BC  41 82 00 08 */	beq lbl_80056164
/* 80056160 000530C0  48 18 4F ED */	bl __ct__Q23zen12DrawWorldMapFv
lbl_80056164:
/* 80056164 000530C4  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80056168 000530C8  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005616C 000530CC  93 6D 2E 54 */	stw r27, mapWindow@sda21(r13)
/* 80056170 000530D0  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 80056174 000530D4  38 A4 00 1C */	addi r5, r4, 0x1c
/* 80056178 000530D8  80 84 00 1C */	lwz r4, 0x1c(r4)
/* 8005617C 000530DC  38 00 00 01 */	li r0, 1
/* 80056180 000530E0  38 C3 01 CC */	addi r6, r3, 0x1cc
/* 80056184 000530E4  90 05 00 00 */	stw r0, 0(r5)
/* 80056188 000530E8  7C 64 00 D0 */	neg r3, r4
/* 8005618C 000530EC  30 03 FF FF */	addic r0, r3, -1
/* 80056190 000530F0  7C 00 19 10 */	subfe r0, r0, r3
/* 80056194 000530F4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80056198 000530F8  54 00 06 3E */	clrlwi r0, r0, 0x18
/* 8005619C 000530FC  90 03 00 1C */	stw r0, 0x1c(r3)
/* 800561A0 00053100  80 A6 00 00 */	lwz r5, 0(r6)
/* 800561A4 00053104  2C 05 FF FF */	cmpwi r5, -1
/* 800561A8 00053108  40 82 00 08 */	bne lbl_800561B0
/* 800561AC 0005310C  38 A0 00 00 */	li r5, 0
lbl_800561B0:
/* 800561B0 00053110  3C 60 80 3A */	lis r3, gameflow@ha
/* 800561B4 00053114  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800561B8 00053118  80 83 01 D0 */	lwz r4, 0x1d0(r3)
/* 800561BC 0005311C  2C 04 FF FF */	cmpwi r4, -1
/* 800561C0 00053120  40 82 00 08 */	bne lbl_800561C8
/* 800561C4 00053124  38 80 00 00 */	li r4, 0
lbl_800561C8:
/* 800561C8 00053128  80 6D 2E 54 */	lwz r3, mapWindow@sda21(r13)
/* 800561CC 0005312C  48 18 AC A1 */	bl start__Q23zen12DrawWorldMapFQ33zen12DrawWorldMap13startModeFlagQ33zen12DrawWorldMap14startPlaceFlag
/* 800561D0 00053130  48 00 00 38 */	b lbl_80056208
lbl_800561D4:
/* 800561D4 00053134  3C 60 80 3A */	lis r3, gameflow@ha
/* 800561D8 00053138  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800561DC 0005313C  38 00 00 01 */	li r0, 1
/* 800561E0 00053140  90 03 02 FC */	stw r0, 0x2fc(r3)
/* 800561E4 00053144  38 60 00 94 */	li r3, 0x94
/* 800561E8 00053148  4B FF 0E 1D */	bl alloc__6SystemFUl
/* 800561EC 0005314C  3B 63 00 00 */	addi r27, r3, 0
/* 800561F0 00053150  7F 63 DB 79 */	or. r3, r27, r27
/* 800561F4 00053154  41 82 00 08 */	beq lbl_800561FC
/* 800561F8 00053158  48 19 66 E1 */	bl __ct__Q23zen18DrawCMcourseSelectFv
lbl_800561FC:
/* 800561FC 0005315C  93 6D 2E 50 */	stw r27, selectWindow@sda21(r13)
/* 80056200 00053160  80 6D 2E 50 */	lwz r3, selectWindow@sda21(r13)
/* 80056204 00053164  48 19 6B 01 */	bl start__Q23zen18DrawCMcourseSelectFv
lbl_80056208:
/* 80056208 00053168  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005620C 0005316C  3C 00 00 0B */	lis r0, 0xb
/* 80056210 00053170  C0 02 85 70 */	lfs f0, lbl_803E8770@sda21(r2)

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8016C1C4 00169124  80 1F 03 90 */	lwz r0, 0x390(r31)
/* 8016C1C8 00169128  28 00 00 00 */	cmplwi r0, 0
/* 8016C1CC 0016912C  41 82 00 1C */	beq lbl_8016C1E8
/* 8016C1D0 00169130  81 9F 03 6C */	lwz r12, 0x36c(r31)
/* 8016C1D4 00169134  38 7F 03 3C */	addi r3, r31, 0x33c
/* 8016C1D8 00169138  C0 3F 02 D8 */	lfs f1, 0x2d8(r31)
/* 8016C1DC 0016913C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8016C1E0 00169140  7D 88 03 A6 */	mtlr r12
/* 8016C1E4 00169144  4E 80 00 21 */	blrl 
lbl_8016C1E8:
/* 8016C1E8 00169148  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8016C1EC 0016914C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8016C1F0 00169150  38 21 00 18 */	addi r1, r1, 0x18
/* 8016C1F4 00169154  7C 08 03 A6 */	mtlr r0
/* 8016C1F8 00169158  4E 80 00 20 */	blr 

.global draw__10KingDrawerFR8Graphics
draw__10KingDrawerFR8Graphics:
/* 8016C1FC 0016915C  7C 08 02 A6 */	mflr r0
/* 8016C200 00169160  90 01 00 04 */	stw r0, 4(r1)
/* 8016C204 00169164  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8016C208 00169168  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8016C20C 0016916C  3B E4 00 00 */	addi r31, r4, 0
/* 8016C210 00169170  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8016C214 00169174  3B C3 00 00 */	addi r30, r3, 0
/* 8016C218 00169178  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8016C21C 0016917C  4B FF FD 25 */	bl draw__4KingFR8Graphics
/* 8016C220 00169180  80 7E 00 20 */	lwz r3, 0x20(r30)
/* 8016C224 00169184  7F E4 FB 78 */	mr r4, r31
/* 8016C228 00169188  81 83 00 00 */	lwz r12, 0(r3)
/* 8016C22C 0016918C  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 8016C230 00169190  7D 88 03 A6 */	mtlr r12
/* 8016C234 00169194  4E 80 00 21 */	blrl 
/* 8016C238 00169198  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8016C23C 0016919C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8016C240 001691A0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8016C244 001691A4  38 21 00 18 */	addi r1, r1, 0x18
/* 8016C248 001691A8  7C 08 03 A6 */	mtlr r0
/* 8016C24C 001691AC  4E 80 00 20 */	blr 

.global isBossBgm__4KingFv
isBossBgm__4KingFv:
/* 8016C250 001691B0  88 63 03 B8 */	lbz r3, 0x3b8(r3)
/* 8016C254 001691B4  4E 80 00 20 */	blr 

.global read__8KingPropFR18RandomAccessStream
read__8KingPropFR18RandomAccessStream:
/* 8016C258 001691B8  7C 08 02 A6 */	mflr r0
/* 8016C25C 001691BC  90 01 00 04 */	stw r0, 4(r1)
/* 8016C260 001691C0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8016C264 001691C4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8016C268 001691C8  3B E4 00 00 */	addi r31, r4, 0
/* 8016C26C 001691CC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8016C270 001691D0  3B C3 00 00 */	addi r30, r3, 0
/* 8016C274 001691D4  4B EF 29 25 */	bl read__10ParametersFR18RandomAccessStream
/* 8016C278 001691D8  38 7E 00 58 */	addi r3, r30, 0x58
/* 8016C27C 001691DC  38 9F 00 00 */	addi r4, r31, 0
/* 8016C280 001691E0  4B EF 29 19 */	bl read__10ParametersFR18RandomAccessStream
/* 8016C284 001691E4  38 7E 02 00 */	addi r3, r30, 0x200
/* 8016C288 001691E8  38 9F 00 00 */	addi r4, r31, 0
/* 8016C28C 001691EC  4B EF 29 0D */	bl read__10ParametersFR18RandomAccessStream
/* 8016C290 001691F0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8016C294 001691F4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8016C298 001691F8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8016C29C 001691FC  38 21 00 18 */	addi r1, r1, 0x18
/* 8016C2A0 00169200  7C 08 03 A6 */	mtlr r0
/* 8016C2A4 00169204  4E 80 00 20 */	blr 
.global lbl_8016C2A8
lbl_8016C2A8:
/* 8016C2A8 00169208  38 63 FE 14 */	addi r3, r3, -492
/* 8016C2AC 0016920C  4B FF FF AC */	b read__8KingPropFR18RandomAccessStream

.global __ct__6KingAiFP4King
__ct__6KingAiFP4King:
/* 8016C2B0 00169210  3C A0 80 2B */	lis r5, __vt__19PaniAnimKeyListener@ha
/* 8016C2B4 00169214  38 05 DB 94 */	addi r0, r5, __vt__19PaniAnimKeyListener@l
/* 8016C2B8 00169218  3C A0 80 2D */	lis r5, __vt__6KingAi@ha
/* 8016C2BC 0016921C  90 03 00 00 */	stw r0, 0(r3)
/* 8016C2C0 00169220  38 05 05 14 */	addi r0, r5, __vt__6KingAi@l
/* 8016C2C4 00169224  90 03 00 00 */	stw r0, 0(r3)
/* 8016C2C8 00169228  C0 02 AC 70 */	lfs f0, lbl_803EAE70@sda21(r2)
/* 8016C2CC 0016922C  D0 03 00 34 */	stfs f0, 0x34(r3)
/* 8016C2D0 00169230  D0 03 00 30 */	stfs f0, 0x30(r3)
/* 8016C2D4 00169234  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 8016C2D8 00169238  D0 03 00 40 */	stfs f0, 0x40(r3)
/* 8016C2DC 0016923C  D0 03 00 3C */	stfs f0, 0x3c(r3)
/* 8016C2E0 00169240  D0 03 00 38 */	stfs f0, 0x38(r3)
/* 8016C2E4 00169244  D0 03 00 4C */	stfs f0, 0x4c(r3)
/* 8016C2E8 00169248  D0 03 00 48 */	stfs f0, 0x48(r3)
/* 8016C2EC 0016924C  D0 03 00 44 */	stfs f0, 0x44(r3)
/* 8016C2F0 00169250  90 83 00 04 */	stw r4, 4(r3)
/* 8016C2F4 00169254  4E 80 00 20 */	blr 

.global initAI__6KingAiFP4King
initAI__6KingAiFP4King:
/* 8016C2F8 00169258  7C 08 02 A6 */	mflr r0
/* 8016C2FC 0016925C  90 01 00 04 */	stw r0, 4(r1)
/* 8016C300 00169260  38 00 00 10 */	li r0, 0x10
/* 8016C304 00169264  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8016C308 00169268  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8016C30C 0016926C  7C 7F 1B 78 */	mr r31, r3
/* 8016C310 00169270  38 BF 00 00 */	addi r5, r31, 0
/* 8016C314 00169274  93 C1 00 38 */	stw r30, 0x38(r1)
/* 8016C318 00169278  93 A1 00 34 */	stw r29, 0x34(r1)
/* 8016C31C 0016927C  93 81 00 30 */	stw r28, 0x30(r1)
/* 8016C320 00169280  90 83 00 04 */	stw r4, 4(r3)
/* 8016C324 00169284  38 80 00 03 */	li r4, 3
/* 8016C328 00169288  80 C3 00 04 */	lwz r6, 4(r3)
/* 8016C32C 0016928C  38 61 00 28 */	addi r3, r1, 0x28
/* 8016C330 00169290  90 06 02 E4 */	stw r0, 0x2e4(r6)
/* 8016C334 00169294  80 DF 00 04 */	lwz r6, 4(r31)
/* 8016C338 00169298  90 06 02 E8 */	stw r0, 0x2e8(r6)
/* 8016C33C 0016929C  4B FB 2C 51 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 8016C340 001692A0  80 BF 00 04 */	lwz r5, 4(r31)
