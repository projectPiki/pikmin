.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8012529C 001221FC  80 63 00 00 */	lwz r3, 0(r3)
/* 801252A0 00122200  D0 03 00 68 */	stfs f0, 0x68(r3)
/* 801252A4 00122204  80 64 00 04 */	lwz r3, 4(r4)
/* 801252A8 00122208  80 63 00 00 */	lwz r3, 0(r3)
/* 801252AC 0012220C  D0 E3 00 6C */	stfs f7, 0x6c(r3)
/* 801252B0 00122210  80 64 00 04 */	lwz r3, 4(r4)
/* 801252B4 00122214  80 63 00 00 */	lwz r3, 0(r3)
/* 801252B8 00122218  D0 C3 00 70 */	stfs f6, 0x70(r3)
/* 801252BC 0012221C  80 64 00 04 */	lwz r3, 4(r4)
/* 801252C0 00122220  80 63 00 00 */	lwz r3, 0(r3)
/* 801252C4 00122224  D0 A3 00 74 */	stfs f5, 0x74(r3)
/* 801252C8 00122228  80 64 00 04 */	lwz r3, 4(r4)
/* 801252CC 0012222C  80 63 00 00 */	lwz r3, 0(r3)
/* 801252D0 00122230  D0 83 00 78 */	stfs f4, 0x78(r3)
/* 801252D4 00122234  80 64 00 04 */	lwz r3, 4(r4)
/* 801252D8 00122238  80 63 00 00 */	lwz r3, 0(r3)
/* 801252DC 0012223C  D1 03 00 7C */	stfs f8, 0x7c(r3)
/* 801252E0 00122240  80 64 00 04 */	lwz r3, 4(r4)
/* 801252E4 00122244  80 63 00 00 */	lwz r3, 0(r3)
/* 801252E8 00122248  D0 03 00 80 */	stfs f0, 0x80(r3)
/* 801252EC 0012224C  80 64 00 04 */	lwz r3, 4(r4)
/* 801252F0 00122250  80 63 00 00 */	lwz r3, 0(r3)
/* 801252F4 00122254  D0 63 00 84 */	stfs f3, 0x84(r3)
/* 801252F8 00122258  80 64 00 04 */	lwz r3, 4(r4)
/* 801252FC 0012225C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125300 00122260  D0 43 00 88 */	stfs f2, 0x88(r3)
/* 80125304 00122264  80 64 00 04 */	lwz r3, 4(r4)
/* 80125308 00122268  80 63 00 00 */	lwz r3, 0(r3)
/* 8012530C 0012226C  D0 23 00 8C */	stfs f1, 0x8c(r3)
/* 80125310 00122270  80 64 00 04 */	lwz r3, 4(r4)
/* 80125314 00122274  80 63 00 00 */	lwz r3, 0(r3)
/* 80125318 00122278  D1 A3 00 90 */	stfs f13, 0x90(r3)
/* 8012531C 0012227C  80 64 00 04 */	lwz r3, 4(r4)
/* 80125320 00122280  80 63 00 00 */	lwz r3, 0(r3)
/* 80125324 00122284  D1 83 00 94 */	stfs f12, 0x94(r3)
/* 80125328 00122288  80 64 00 04 */	lwz r3, 4(r4)
/* 8012532C 0012228C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125330 00122290  D1 63 00 98 */	stfs f11, 0x98(r3)
/* 80125334 00122294  80 64 00 04 */	lwz r3, 4(r4)
/* 80125338 00122298  C0 02 A1 C0 */	lfs f0, lbl_803EA3C0@sda21(r2)
/* 8012533C 0012229C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125340 001222A0  D0 03 00 9C */	stfs f0, 0x9c(r3)
/* 80125344 001222A4  80 64 00 04 */	lwz r3, 4(r4)
/* 80125348 001222A8  80 63 00 00 */	lwz r3, 0(r3)
/* 8012534C 001222AC  D1 83 00 A0 */	stfs f12, 0xa0(r3)
/* 80125350 001222B0  80 64 00 04 */	lwz r3, 4(r4)
/* 80125354 001222B4  80 63 00 00 */	lwz r3, 0(r3)
/* 80125358 001222B8  D0 23 00 A4 */	stfs f1, 0xa4(r3)
/* 8012535C 001222BC  80 64 00 04 */	lwz r3, 4(r4)
/* 80125360 001222C0  C0 02 A1 C4 */	lfs f0, lbl_803EA3C4@sda21(r2)
/* 80125364 001222C4  80 63 00 00 */	lwz r3, 0(r3)
/* 80125368 001222C8  D0 03 00 A8 */	stfs f0, 0xa8(r3)
/* 8012536C 001222CC  80 64 00 04 */	lwz r3, 4(r4)
/* 80125370 001222D0  80 63 00 00 */	lwz r3, 0(r3)
/* 80125374 001222D4  D0 03 00 AC */	stfs f0, 0xac(r3)
/* 80125378 001222D8  80 64 00 04 */	lwz r3, 4(r4)
/* 8012537C 001222DC  C0 02 A1 C8 */	lfs f0, lbl_803EA3C8@sda21(r2)
/* 80125380 001222E0  80 63 00 00 */	lwz r3, 0(r3)
/* 80125384 001222E4  D0 03 00 B0 */	stfs f0, 0xb0(r3)
/* 80125388 001222E8  80 64 00 04 */	lwz r3, 4(r4)
/* 8012538C 001222EC  C0 02 A1 80 */	lfs f0, lbl_803EA380@sda21(r2)
/* 80125390 001222F0  80 63 00 00 */	lwz r3, 0(r3)
/* 80125394 001222F4  D0 03 00 B4 */	stfs f0, 0xb4(r3)
/* 80125398 001222F8  80 64 00 04 */	lwz r3, 4(r4)
/* 8012539C 001222FC  C0 02 A1 CC */	lfs f0, lbl_803EA3CC@sda21(r2)
/* 801253A0 00122300  80 63 00 00 */	lwz r3, 0(r3)
/* 801253A4 00122304  D0 03 00 B8 */	stfs f0, 0xb8(r3)
/* 801253A8 00122308  80 64 00 04 */	lwz r3, 4(r4)
/* 801253AC 0012230C  C0 02 A1 D0 */	lfs f0, lbl_803EA3D0@sda21(r2)
/* 801253B0 00122310  80 63 00 00 */	lwz r3, 0(r3)
/* 801253B4 00122314  D0 03 00 BC */	stfs f0, 0xbc(r3)
/* 801253B8 00122318  80 64 00 04 */	lwz r3, 4(r4)
/* 801253BC 0012231C  C0 02 A1 D4 */	lfs f0, lbl_803EA3D4@sda21(r2)
/* 801253C0 00122320  80 63 00 00 */	lwz r3, 0(r3)
/* 801253C4 00122324  D0 03 00 C0 */	stfs f0, 0xc0(r3)
/* 801253C8 00122328  80 64 00 04 */	lwz r3, 4(r4)
/* 801253CC 0012232C  C0 02 A1 D8 */	lfs f0, lbl_803EA3D8@sda21(r2)
/* 801253D0 00122330  80 63 00 00 */	lwz r3, 0(r3)
/* 801253D4 00122334  D0 03 00 C4 */	stfs f0, 0xc4(r3)
/* 801253D8 00122338  80 A4 00 04 */	lwz r5, 4(r4)
/* 801253DC 0012233C  7F 83 E3 78 */	mr r3, r28
/* 801253E0 00122340  80 A5 00 00 */	lwz r5, 0(r5)
/* 801253E4 00122344  D0 05 00 C8 */	stfs f0, 0xc8(r5)
/* 801253E8 00122348  80 A4 00 04 */	lwz r5, 4(r4)
/* 801253EC 0012234C  C0 02 A1 DC */	lfs f0, lbl_803EA3DC@sda21(r2)
/* 801253F0 00122350  80 A5 00 00 */	lwz r5, 0(r5)
/* 801253F4 00122354  D0 05 00 CC */	stfs f0, 0xcc(r5)
/* 801253F8 00122358  80 A4 00 04 */	lwz r5, 4(r4)
/* 801253FC 0012235C  80 A5 00 00 */	lwz r5, 0(r5)
/* 80125400 00122360  D0 C5 00 D0 */	stfs f6, 0xd0(r5)
/* 80125404 00122364  80 A4 00 04 */	lwz r5, 4(r4)
/* 80125408 00122368  80 A5 00 00 */	lwz r5, 0(r5)
/* 8012540C 0012236C  D0 C5 00 D4 */	stfs f6, 0xd4(r5)
/* 80125410 00122370  C0 2D E3 5C */	lfs f1, pi__6NMathF@sda21(r13)
/* 80125414 00122374  C0 02 A1 E0 */	lfs f0, lbl_803EA3E0@sda21(r2)
/* 80125418 00122378  80 84 00 04 */	lwz r4, 4(r4)
/* 8012541C 0012237C  EC 01 00 32 */	fmuls f0, f1, f0
/* 80125420 00122380  80 84 00 00 */	lwz r4, 0(r4)
/* 80125424 00122384  D0 04 00 D8 */	stfs f0, 0xd8(r4)
/* 80125428 00122388  80 01 01 0C */	lwz r0, 0x10c(r1)
/* 8012542C 0012238C  BB 61 00 F4 */	lmw r27, 0xf4(r1)
/* 80125430 00122390  38 21 01 08 */	addi r1, r1, 0x108
/* 80125434 00122394  7C 08 03 A6 */	mtlr r0
/* 80125438 00122398  4E 80 00 20 */	blr 

.global __ct__18ParaParameterInfoFFv
__ct__18ParaParameterInfoFFv:
/* 8012543C 0012239C  38 00 00 00 */	li r0, 0
/* 80125440 001223A0  90 03 00 00 */	stw r0, 0(r3)
/* 80125444 001223A4  C0 02 A1 58 */	lfs f0, lbl_803EA358@sda21(r2)
/* 80125448 001223A8  D0 03 00 04 */	stfs f0, 4(r3)
/* 8012544C 001223AC  D0 03 00 08 */	stfs f0, 8(r3)
/* 80125450 001223B0  4E 80 00 20 */	blr 

.global __ct__18ParaParameterInfoIFv
__ct__18ParaParameterInfoIFv:
/* 80125454 001223B4  38 00 00 00 */	li r0, 0
/* 80125458 001223B8  90 03 00 00 */	stw r0, 0(r3)
/* 8012545C 001223BC  90 03 00 04 */	stw r0, 4(r3)
/* 80125460 001223C0  90 03 00 08 */	stw r0, 8(r3)
/* 80125464 001223C4  4E 80 00 20 */	blr 

.global read__20PcamCameraParametersFR18RandomAccessStream
read__20PcamCameraParametersFR18RandomAccessStream:
/* 80125468 001223C8  7C 08 02 A6 */	mflr r0
/* 8012546C 001223CC  90 01 00 04 */	stw r0, 4(r1)
/* 80125470 001223D0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80125474 001223D4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80125478 001223D8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8012547C 001223DC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80125480 001223E0  3B A3 00 00 */	addi r29, r3, 0
/* 80125484 001223E4  93 81 00 10 */	stw r28, 0x10(r1)
/* 80125488 001223E8  3B 84 00 00 */	addi r28, r4, 0
/* 8012548C 001223EC  38 7C 00 00 */	addi r3, r28, 0
/* 80125490 001223F0  81 9C 00 04 */	lwz r12, 4(r28)
/* 80125494 001223F4  81 8C 00 08 */	lwz r12, 8(r12)
/* 80125498 001223F8  7D 88 03 A6 */	mtlr r12
/* 8012549C 001223FC  4E 80 00 21 */	blrl 
/* 801254A0 00122400  90 7D 00 20 */	stw r3, 0x20(r29)
/* 801254A4 00122404  80 1D 00 20 */	lwz r0, 0x20(r29)
/* 801254A8 00122408  83 DD 00 24 */	lwz r30, 0x24(r29)
/* 801254AC 0012240C  2C 00 00 06 */	cmpwi r0, 6
/* 801254B0 00122410  41 81 00 58 */	bgt lbl_80125508
/* 801254B4 00122414  80 7E 00 00 */	lwz r3, 0(r30)
/* 801254B8 00122418  7F 84 E3 78 */	mr r4, r28
/* 801254BC 0012241C  81 83 00 0C */	lwz r12, 0xc(r3)
/* 801254C0 00122420  81 8C 00 08 */	lwz r12, 8(r12)
/* 801254C4 00122424  7D 88 03 A6 */	mtlr r12
/* 801254C8 00122428  4E 80 00 21 */	blrl 
/* 801254CC 0012242C  3B A0 00 00 */	li r29, 0
/* 801254D0 00122430  3B E0 00 00 */	li r31, 0
lbl_801254D4:
/* 801254D4 00122434  7F 83 E3 78 */	mr r3, r28
/* 801254D8 00122438  81 9C 00 04 */	lwz r12, 4(r28)
/* 801254DC 0012243C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 801254E0 00122440  7D 88 03 A6 */	mtlr r12
/* 801254E4 00122444  4E 80 00 21 */	blrl 
/* 801254E8 00122448  80 7E 00 04 */	lwz r3, 4(r30)
/* 801254EC 0012244C  3B BD 00 01 */	addi r29, r29, 1
/* 801254F0 00122450  2C 1D 00 36 */	cmpwi r29, 0x36
/* 801254F4 00122454  80 63 00 00 */	lwz r3, 0(r3)
/* 801254F8 00122458  7C 23 FD 2E */	stfsx f1, r3, r31
/* 801254FC 0012245C  3B FF 00 04 */	addi r31, r31, 4
/* 80125500 00122460  41 80 FF D4 */	blt lbl_801254D4
/* 80125504 00122464  48 00 00 1C */	b lbl_80125520
lbl_80125508:
/* 80125508 00122468  7F C3 F3 78 */	mr r3, r30
/* 8012550C 0012246C  81 9E 00 08 */	lwz r12, 8(r30)
/* 80125510 00122470  7F 84 E3 78 */	mr r4, r28
/* 80125514 00122474  81 8C 00 08 */	lwz r12, 8(r12)
/* 80125518 00122478  7D 88 03 A6 */	mtlr r12
/* 8012551C 0012247C  4E 80 00 21 */	blrl 
lbl_80125520:
/* 80125520 00122480  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80125524 00122484  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80125528 00122488  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8012552C 0012248C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80125530 00122490  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80125534 00122494  38 21 00 20 */	addi r1, r1, 0x20
/* 80125538 00122498  7C 08 03 A6 */	mtlr r0
/* 8012553C 0012249C  4E 80 00 20 */	blr 

.global __ct__13PeveConditionFv
__ct__13PeveConditionFv:
/* 80125540 001224A0  3C 80 80 2C */	lis r4, __vt__13PeveCondition@ha
/* 80125544 001224A4  38 04 5E 24 */	addi r0, r4, __vt__13PeveCondition@l
/* 80125548 001224A8  90 03 00 00 */	stw r0, 0(r3)
/* 8012554C 001224AC  4E 80 00 20 */	blr 

.global __ct__9PeveEventFi
__ct__9PeveEventFi:
/* 80125550 001224B0  7C 08 02 A6 */	mflr r0
/* 80125554 001224B4  90 01 00 04 */	stw r0, 4(r1)
/* 80125558 001224B8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8012555C 001224BC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80125560 001224C0  7C 7F 1B 78 */	mr r31, r3
/* 80125564 001224C4  4B FF 8B 95 */	bl __ct__5NNodeFi
/* 80125568 001224C8  3C 60 80 2C */	lis r3, __vt__9PeveEvent@ha
/* 8012556C 001224CC  38 03 5D D8 */	addi r0, r3, __vt__9PeveEvent@l
/* 80125570 001224D0  90 1F 00 00 */	stw r0, 0(r31)
/* 80125574 001224D4  38 00 00 00 */	li r0, 0
/* 80125578 001224D8  38 7F 00 00 */	addi r3, r31, 0
/* 8012557C 001224DC  90 1F 00 08 */	stw r0, 8(r31)
/* 80125580 001224E0  90 1F 00 0C */	stw r0, 0xc(r31)
/* 80125584 001224E4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80125588 001224E8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8012558C 001224EC  38 21 00 18 */	addi r1, r1, 0x18
/* 80125590 001224F0  7C 08 03 A6 */	mtlr r0
/* 80125594 001224F4  4E 80 00 20 */	blr 

.global reset__17PeveParallelEventFv
reset__17PeveParallelEventFv:
/* 80125598 001224F8  7C 08 02 A6 */	mflr r0
/* 8012559C 001224FC  90 01 00 04 */	stw r0, 4(r1)
/* 801255A0 00122500  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801255A4 00122504  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801255A8 00122508  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801255AC 0012250C  7C 7E 1B 78 */	mr r30, r3
/* 801255B0 00122510  80 63 00 08 */	lwz r3, 8(r3)
/* 801255B4 00122514  28 03 00 00 */	cmplwi r3, 0
/* 801255B8 00122518  41 82 00 14 */	beq lbl_801255CC
/* 801255BC 0012251C  81 83 00 00 */	lwz r12, 0(r3)
/* 801255C0 00122520  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801255C4 00122524  7D 88 03 A6 */	mtlr r12
/* 801255C8 00122528  4E 80 00 21 */	blrl 
lbl_801255CC:
/* 801255CC 0012252C  3B E0 00 00 */	li r31, 0
/* 801255D0 00122530  48 00 00 24 */	b lbl_801255F4
lbl_801255D4:
/* 801255D4 00122534  38 7E 00 00 */	addi r3, r30, 0
/* 801255D8 00122538  38 9F 00 00 */	addi r4, r31, 0
/* 801255DC 0012253C  4B FF 8E 69 */	bl getChild__5NNodeFi
/* 801255E0 00122540  81 83 00 00 */	lwz r12, 0(r3)
/* 801255E4 00122544  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 801255E8 00122548  7D 88 03 A6 */	mtlr r12
/* 801255EC 0012254C  4E 80 00 21 */	blrl 
/* 801255F0 00122550  3B FF 00 01 */	addi r31, r31, 1
lbl_801255F4:
/* 801255F4 00122554  80 7E 00 04 */	lwz r3, 4(r30)
/* 801255F8 00122558  80 03 00 08 */	lwz r0, 8(r3)
/* 801255FC 0012255C  7C 1F 00 00 */	cmpw r31, r0
/* 80125600 00122560  41 80 FF D4 */	blt lbl_801255D4
/* 80125604 00122564  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80125608 00122568  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8012560C 0012256C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80125610 00122570  38 21 00 20 */	addi r1, r1, 0x20
/* 80125614 00122574  7C 08 03 A6 */	mtlr r0
/* 80125618 00122578  4E 80 00 20 */	blr 

.global update__17PeveParallelEventFv
update__17PeveParallelEventFv:
/* 8012561C 0012257C  7C 08 02 A6 */	mflr r0
/* 80125620 00122580  90 01 00 04 */	stw r0, 4(r1)
/* 80125624 00122584  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80125628 00122588  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8012562C 0012258C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80125630 00122590  7C 7E 1B 78 */	mr r30, r3
/* 80125634 00122594  80 63 00 08 */	lwz r3, 8(r3)
/* 80125638 00122598  28 03 00 00 */	cmplwi r3, 0
/* 8012563C 0012259C  41 82 00 14 */	beq lbl_80125650
/* 80125640 001225A0  81 83 00 00 */	lwz r12, 0(r3)
/* 80125644 001225A4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80125648 001225A8  7D 88 03 A6 */	mtlr r12
/* 8012564C 001225AC  4E 80 00 21 */	blrl 
lbl_80125650:
/* 80125650 001225B0  3B E0 00 00 */	li r31, 0
/* 80125654 001225B4  48 00 00 24 */	b lbl_80125678
lbl_80125658:
/* 80125658 001225B8  38 7E 00 00 */	addi r3, r30, 0
/* 8012565C 001225BC  38 9F 00 00 */	addi r4, r31, 0
/* 80125660 001225C0  4B FF 8D E5 */	bl getChild__5NNodeFi
/* 80125664 001225C4  81 83 00 00 */	lwz r12, 0(r3)
/* 80125668 001225C8  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8012566C 001225CC  7D 88 03 A6 */	mtlr r12
/* 80125670 001225D0  4E 80 00 21 */	blrl 
/* 80125674 001225D4  3B FF 00 01 */	addi r31, r31, 1
lbl_80125678:
/* 80125678 001225D8  80 7E 00 04 */	lwz r3, 4(r30)
/* 8012567C 001225DC  80 03 00 08 */	lwz r0, 8(r3)
/* 80125680 001225E0  7C 1F 00 00 */	cmpw r31, r0
/* 80125684 001225E4  41 80 FF D4 */	blt lbl_80125658
/* 80125688 001225E8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8012568C 001225EC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80125690 001225F0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80125694 001225F4  38 21 00 20 */	addi r1, r1, 0x20
/* 80125698 001225F8  7C 08 03 A6 */	mtlr r0
/* 8012569C 001225FC  4E 80 00 20 */	blr 

.global isFinished__17PeveParallelEventFv
isFinished__17PeveParallelEventFv:
/* 801256A0 00122600  7C 08 02 A6 */	mflr r0
/* 801256A4 00122604  90 01 00 04 */	stw r0, 4(r1)
/* 801256A8 00122608  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801256AC 0012260C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801256B0 00122610  3B E0 00 00 */	li r31, 0
/* 801256B4 00122614  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801256B8 00122618  3B C3 00 00 */	addi r30, r3, 0
/* 801256BC 0012261C  48 00 00 34 */	b lbl_801256F0
lbl_801256C0:
/* 801256C0 00122620  38 7E 00 00 */	addi r3, r30, 0
/* 801256C4 00122624  38 9F 00 00 */	addi r4, r31, 0
/* 801256C8 00122628  4B FF 8D 7D */	bl getChild__5NNodeFi
/* 801256CC 0012262C  81 83 00 00 */	lwz r12, 0(r3)
/* 801256D0 00122630  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 801256D4 00122634  7D 88 03 A6 */	mtlr r12
/* 801256D8 00122638  4E 80 00 21 */	blrl 
/* 801256DC 0012263C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801256E0 00122640  40 82 00 0C */	bne lbl_801256EC
/* 801256E4 00122644  38 60 00 00 */	li r3, 0
/* 801256E8 00122648  48 00 00 1C */	b lbl_80125704
lbl_801256EC:
/* 801256EC 0012264C  3B FF 00 01 */	addi r31, r31, 1
lbl_801256F0:
/* 801256F0 00122650  80 7E 00 04 */	lwz r3, 4(r30)
/* 801256F4 00122654  80 03 00 08 */	lwz r0, 8(r3)
/* 801256F8 00122658  7C 1F 00 00 */	cmpw r31, r0
/* 801256FC 0012265C  41 80 FF C4 */	blt lbl_801256C0
/* 80125700 00122660  38 60 00 01 */	li r3, 1
lbl_80125704:
/* 80125704 00122664  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80125708 00122668  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8012570C 0012266C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80125710 00122670  38 21 00 20 */	addi r1, r1, 0x20
/* 80125714 00122674  7C 08 03 A6 */	mtlr r0
/* 80125718 00122678  4E 80 00 20 */	blr 

.global __ct__15PeveSerialEventFi
__ct__15PeveSerialEventFi:
/* 8012571C 0012267C  7C 08 02 A6 */	mflr r0
/* 80125720 00122680  90 01 00 04 */	stw r0, 4(r1)
/* 80125724 00122684  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80125728 00122688  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8012572C 0012268C  7C 7F 1B 78 */	mr r31, r3
/* 80125730 00122690  4B FF 89 C9 */	bl __ct__5NNodeFi
/* 80125734 00122694  3C 60 80 2C */	lis r3, __vt__9PeveEvent@ha
/* 80125738 00122698  38 03 5D D8 */	addi r0, r3, __vt__9PeveEvent@l
/* 8012573C 0012269C  90 1F 00 00 */	stw r0, 0(r31)
/* 80125740 001226A0  38 80 00 00 */	li r4, 0
/* 80125744 001226A4  3C 60 80 2C */	lis r3, __vt__15PeveSerialEvent@ha
/* 80125748 001226A8  90 9F 00 08 */	stw r4, 8(r31)
/* 8012574C 001226AC  38 03 5D 38 */	addi r0, r3, __vt__15PeveSerialEvent@l
/* 80125750 001226B0  38 7F 00 00 */	addi r3, r31, 0
/* 80125754 001226B4  90 9F 00 0C */	stw r4, 0xc(r31)
/* 80125758 001226B8  90 1F 00 00 */	stw r0, 0(r31)
/* 8012575C 001226BC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80125760 001226C0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80125764 001226C4  38 21 00 18 */	addi r1, r1, 0x18
/* 80125768 001226C8  7C 08 03 A6 */	mtlr r0
/* 8012576C 001226CC  4E 80 00 20 */	blr 

.global reset__15PeveSerialEventFv
reset__15PeveSerialEventFv:
/* 80125770 001226D0  7C 08 02 A6 */	mflr r0
/* 80125774 001226D4  90 01 00 04 */	stw r0, 4(r1)
/* 80125778 001226D8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8012577C 001226DC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80125780 001226E0  7C 7F 1B 78 */	mr r31, r3
/* 80125784 001226E4  80 63 00 08 */	lwz r3, 8(r3)
/* 80125788 001226E8  28 03 00 00 */	cmplwi r3, 0
/* 8012578C 001226EC  41 82 00 14 */	beq lbl_801257A0
/* 80125790 001226F0  81 83 00 00 */	lwz r12, 0(r3)
/* 80125794 001226F4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80125798 001226F8  7D 88 03 A6 */	mtlr r12
/* 8012579C 001226FC  4E 80 00 21 */	blrl 
lbl_801257A0:
/* 801257A0 00122700  38 00 00 00 */	li r0, 0
/* 801257A4 00122704  90 1F 00 10 */	stw r0, 0x10(r31)
/* 801257A8 00122708  7F E3 FB 78 */	mr r3, r31
/* 801257AC 0012270C  80 9F 00 10 */	lwz r4, 0x10(r31)
/* 801257B0 00122710  4B FF 8C 95 */	bl getChild__5NNodeFi
/* 801257B4 00122714  81 83 00 00 */	lwz r12, 0(r3)
/* 801257B8 00122718  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 801257BC 0012271C  7D 88 03 A6 */	mtlr r12
/* 801257C0 00122720  4E 80 00 21 */	blrl 
/* 801257C4 00122724  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801257C8 00122728  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801257CC 0012272C  38 21 00 20 */	addi r1, r1, 0x20
/* 801257D0 00122730  7C 08 03 A6 */	mtlr r0
/* 801257D4 00122734  4E 80 00 20 */	blr 

.global update__15PeveSerialEventFv
update__15PeveSerialEventFv:
/* 801257D8 00122738  7C 08 02 A6 */	mflr r0
/* 801257DC 0012273C  90 01 00 04 */	stw r0, 4(r1)
/* 801257E0 00122740  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 801257E4 00122744  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 801257E8 00122748  93 C1 00 28 */	stw r30, 0x28(r1)
/* 801257EC 0012274C  7C 7E 1B 78 */	mr r30, r3
/* 801257F0 00122750  80 83 00 10 */	lwz r4, 0x10(r3)
/* 801257F4 00122754  4B FF 8C 51 */	bl getChild__5NNodeFi
/* 801257F8 00122758  7C 7F 1B 78 */	mr r31, r3
/* 801257FC 0012275C  81 9F 00 00 */	lwz r12, 0(r31)
/* 80125800 00122760  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 80125804 00122764  7D 88 03 A6 */	mtlr r12
/* 80125808 00122768  4E 80 00 21 */	blrl 
/* 8012580C 0012276C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80125810 00122770  41 82 00 68 */	beq lbl_80125878
/* 80125814 00122774  80 7E 00 04 */	lwz r3, 4(r30)
/* 80125818 00122778  28 03 00 00 */	cmplwi r3, 0
/* 8012581C 0012277C  40 82 00 0C */	bne lbl_80125828
/* 80125820 00122780  38 80 00 00 */	li r4, 0
/* 80125824 00122784  48 00 00 08 */	b lbl_8012582C
lbl_80125828:
/* 80125828 00122788  80 83 00 08 */	lwz r4, 8(r3)
lbl_8012582C:
/* 8012582C 0012278C  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 80125830 00122790  38 03 00 01 */	addi r0, r3, 1
/* 80125834 00122794  7C 00 20 00 */	cmpw r0, r4
/* 80125838 00122798  40 80 00 54 */	bge lbl_8012588C
/* 8012583C 0012279C  90 1E 00 10 */	stw r0, 0x10(r30)
/* 80125840 001227A0  7F C3 F3 78 */	mr r3, r30
/* 80125844 001227A4  80 9E 00 10 */	lwz r4, 0x10(r30)
/* 80125848 001227A8  4B FF 8B FD */	bl getChild__5NNodeFi
/* 8012584C 001227AC  7C 7F 1B 78 */	mr r31, r3
/* 80125850 001227B0  81 9F 00 00 */	lwz r12, 0(r31)
/* 80125854 001227B4  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 80125858 001227B8  7D 88 03 A6 */	mtlr r12
/* 8012585C 001227BC  4E 80 00 21 */	blrl 
/* 80125860 001227C0  7F E3 FB 78 */	mr r3, r31
/* 80125864 001227C4  81 9F 00 00 */	lwz r12, 0(r31)
/* 80125868 001227C8  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8012586C 001227CC  7D 88 03 A6 */	mtlr r12
/* 80125870 001227D0  4E 80 00 21 */	blrl 
/* 80125874 001227D4  48 00 00 18 */	b lbl_8012588C
lbl_80125878:
/* 80125878 001227D8  7F E3 FB 78 */	mr r3, r31
/* 8012587C 001227DC  81 9F 00 00 */	lwz r12, 0(r31)
/* 80125880 001227E0  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80125884 001227E4  7D 88 03 A6 */	mtlr r12
/* 80125888 001227E8  4E 80 00 21 */	blrl 
lbl_8012588C:
/* 8012588C 001227EC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80125890 001227F0  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80125894 001227F4  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80125898 001227F8  38 21 00 30 */	addi r1, r1, 0x30
/* 8012589C 001227FC  7C 08 03 A6 */	mtlr r0
/* 801258A0 00122800  4E 80 00 20 */	blr 

.global isFinished__15PeveSerialEventFv
isFinished__15PeveSerialEventFv:
/* 801258A4 00122804  7C 08 02 A6 */	mflr r0
/* 801258A8 00122808  90 01 00 04 */	stw r0, 4(r1)
/* 801258AC 0012280C  94 21 FF F8 */	stwu r1, -8(r1)
/* 801258B0 00122810  80 83 00 04 */	lwz r4, 4(r3)
/* 801258B4 00122814  28 04 00 00 */	cmplwi r4, 0
/* 801258B8 00122818  40 82 00 0C */	bne lbl_801258C4
/* 801258BC 0012281C  38 A0 00 00 */	li r5, 0
/* 801258C0 00122820  48 00 00 08 */	b lbl_801258C8
lbl_801258C4:
/* 801258C4 00122824  80 A4 00 08 */	lwz r5, 8(r4)
lbl_801258C8:
/* 801258C8 00122828  80 83 00 10 */	lwz r4, 0x10(r3)
/* 801258CC 0012282C  38 05 FF FF */	addi r0, r5, -1
/* 801258D0 00122830  7C 04 00 00 */	cmpw r4, r0
/* 801258D4 00122834  40 80 00 0C */	bge lbl_801258E0
/* 801258D8 00122838  38 60 00 00 */	li r3, 0
/* 801258DC 0012283C  48 00 00 2C */	b lbl_80125908
lbl_801258E0:
/* 801258E0 00122840  4B FF 8B 65 */	bl getChild__5NNodeFi
/* 801258E4 00122844  81 83 00 00 */	lwz r12, 0(r3)
/* 801258E8 00122848  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 801258EC 0012284C  7D 88 03 A6 */	mtlr r12
/* 801258F0 00122850  4E 80 00 21 */	blrl 
/* 801258F4 00122854  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801258F8 00122858  40 82 00 0C */	bne lbl_80125904
/* 801258FC 0012285C  38 60 00 00 */	li r3, 0
/* 80125900 00122860  48 00 00 08 */	b lbl_80125908
lbl_80125904:
/* 80125904 00122864  38 60 00 01 */	li r3, 1
lbl_80125908:
/* 80125908 00122868  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8012590C 0012286C  38 21 00 08 */	addi r1, r1, 8
/* 80125910 00122870  7C 08 03 A6 */	mtlr r0
/* 80125914 00122874  4E 80 00 20 */	blr 

.global __ct__19PeveCameraPostureIOFv
__ct__19PeveCameraPostureIOFv:
/* 80125918 00122878  7C 08 02 A6 */	mflr r0
/* 8012591C 0012287C  3C 80 80 2C */	lis r4, __vt__12NPosture3DIO@ha
/* 80125920 00122880  90 01 00 04 */	stw r0, 4(r1)
/* 80125924 00122884  38 04 5C 74 */	addi r0, r4, __vt__12NPosture3DIO@l
/* 80125928 00122888  38 80 00 00 */	li r4, 0
/* 8012592C 0012288C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80125930 00122890  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80125934 00122894  3B E3 00 00 */	addi r31, r3, 0
/* 80125938 00122898  3C 60 80 2C */	lis r3, __vt__19PeveCameraPostureIO@ha
/* 8012593C 0012289C  90 1F 00 00 */	stw r0, 0(r31)
/* 80125940 001228A0  38 03 5C 64 */	addi r0, r3, __vt__19PeveCameraPostureIO@l
/* 80125944 001228A4  38 7F 00 00 */	addi r3, r31, 0
/* 80125948 001228A8  90 1F 00 00 */	stw r0, 0(r31)
/* 8012594C 001228AC  48 00 00 1D */	bl construct__19PeveCameraPostureIOFP10PcamCamera
/* 80125950 001228B0  7F E3 FB 78 */	mr r3, r31
/* 80125954 001228B4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80125958 001228B8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8012595C 001228BC  38 21 00 18 */	addi r1, r1, 0x18
/* 80125960 001228C0  7C 08 03 A6 */	mtlr r0
/* 80125964 001228C4  4E 80 00 20 */	blr 

.global construct__19PeveCameraPostureIOFP10PcamCamera
construct__19PeveCameraPostureIOFP10PcamCamera:
/* 80125968 001228C8  90 83 00 04 */	stw r4, 4(r3)
/* 8012596C 001228CC  4E 80 00 20 */	blr 

.global __ct__19PeveClampVector3fIOFv
__ct__19PeveClampVector3fIOFv:
/* 80125970 001228D0  7C 08 02 A6 */	mflr r0
/* 80125974 001228D4  3C 80 80 2C */	lis r4, __vt__11NVector3fIO@ha
/* 80125978 001228D8  90 01 00 04 */	stw r0, 4(r1)
/* 8012597C 001228DC  38 04 5C EC */	addi r0, r4, __vt__11NVector3fIO@l
/* 80125980 001228E0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80125984 001228E4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80125988 001228E8  3B E3 00 00 */	addi r31, r3, 0
/* 8012598C 001228EC  3C 60 80 2C */	lis r3, __vt__16NVector3fIOClass@ha
/* 80125990 001228F0  90 1F 00 00 */	stw r0, 0(r31)
/* 80125994 001228F4  38 03 5B F0 */	addi r0, r3, __vt__16NVector3fIOClass@l
/* 80125998 001228F8  38 7F 00 04 */	addi r3, r31, 4
/* 8012599C 001228FC  90 1F 00 00 */	stw r0, 0(r31)
/* 801259A0 00122900  4B FF 74 B5 */	bl __ct__9NVector3fFv
/* 801259A4 00122904  3C 60 80 2C */	lis r3, __vt__19PeveClampVector3fIO@ha
/* 801259A8 00122908  38 03 5B E0 */	addi r0, r3, __vt__19PeveClampVector3fIO@l
/* 801259AC 0012290C  90 1F 00 00 */	stw r0, 0(r31)
/* 801259B0 00122910  7F E3 FB 78 */	mr r3, r31
/* 801259B4 00122914  48 00 00 1D */	bl construct__19PeveClampVector3fIOFv
/* 801259B8 00122918  7F E3 FB 78 */	mr r3, r31
/* 801259BC 0012291C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801259C0 00122920  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801259C4 00122924  38 21 00 18 */	addi r1, r1, 0x18
/* 801259C8 00122928  7C 08 03 A6 */	mtlr r0
/* 801259CC 0012292C  4E 80 00 20 */	blr 

.global construct__19PeveClampVector3fIOFv
construct__19PeveClampVector3fIOFv:
/* 801259D0 00122930  C0 02 A1 E8 */	lfs f0, lbl_803EA3E8@sda21(r2)
/* 801259D4 00122934  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 801259D8 00122938  4E 80 00 20 */	blr 

.global input__19PeveClampVector3fIOFR9NVector3f
input__19PeveClampVector3fIOFR9NVector3f:
/* 801259DC 0012293C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801259E0 00122940  C0 04 00 00 */	lfs f0, 0(r4)
/* 801259E4 00122944  D0 03 00 04 */	stfs f0, 4(r3)
/* 801259E8 00122948  C0 04 00 04 */	lfs f0, 4(r4)
/* 801259EC 0012294C  D0 03 00 08 */	stfs f0, 8(r3)
/* 801259F0 00122950  C0 04 00 08 */	lfs f0, 8(r4)
/* 801259F4 00122954  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 801259F8 00122958  C0 23 00 04 */	lfs f1, 4(r3)
/* 801259FC 0012295C  C0 03 00 08 */	lfs f0, 8(r3)
/* 80125A00 00122960  EC 41 00 72 */	fmuls f2, f1, f1
/* 80125A04 00122964  C0 63 00 0C */	lfs f3, 0xc(r3)
/* 80125A08 00122968  EC 20 00 32 */	fmuls f1, f0, f0
/* 80125A0C 0012296C  C0 02 A1 EC */	lfs f0, lbl_803EA3EC@sda21(r2)
/* 80125A10 00122970  EC 63 00 F2 */	fmuls f3, f3, f3
/* 80125A14 00122974  EC 22 08 2A */	fadds f1, f2, f1
/* 80125A18 00122978  EC 83 08 2A */	fadds f4, f3, f1
/* 80125A1C 0012297C  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 80125A20 00122980  40 81 00 5C */	ble lbl_80125A7C
/* 80125A24 00122984  FC 20 20 34 */	frsqrte f1, f4
/* 80125A28 00122988  C8 62 A1 F0 */	lfd f3, "@850"@sda21(r2)
/* 80125A2C 0012298C  C8 42 A1 F8 */	lfd f2, "@851"@sda21(r2)
/* 80125A30 00122990  FC 01 00 72 */	fmul f0, f1, f1
/* 80125A34 00122994  FC 23 00 72 */	fmul f1, f3, f1
/* 80125A38 00122998  FC 04 00 32 */	fmul f0, f4, f0
/* 80125A3C 0012299C  FC 02 00 28 */	fsub f0, f2, f0
/* 80125A40 001229A0  FC 21 00 32 */	fmul f1, f1, f0
/* 80125A44 001229A4  FC 01 00 72 */	fmul f0, f1, f1
/* 80125A48 001229A8  FC 23 00 72 */	fmul f1, f3, f1
/* 80125A4C 001229AC  FC 04 00 32 */	fmul f0, f4, f0
/* 80125A50 001229B0  FC 02 00 28 */	fsub f0, f2, f0
/* 80125A54 001229B4  FC 21 00 32 */	fmul f1, f1, f0
/* 80125A58 001229B8  FC 01 00 72 */	fmul f0, f1, f1
/* 80125A5C 001229BC  FC 23 00 72 */	fmul f1, f3, f1
/* 80125A60 001229C0  FC 04 00 32 */	fmul f0, f4, f0
/* 80125A64 001229C4  FC 02 00 28 */	fsub f0, f2, f0
/* 80125A68 001229C8  FC 01 00 32 */	fmul f0, f1, f0
/* 80125A6C 001229CC  FC 04 00 32 */	fmul f0, f4, f0
/* 80125A70 001229D0  FC 00 00 18 */	frsp f0, f0
/* 80125A74 001229D4  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 80125A78 001229D8  C0 81 00 14 */	lfs f4, 0x14(r1)
lbl_80125A7C:
/* 80125A7C 001229DC  C0 03 00 10 */	lfs f0, 0x10(r3)
/* 80125A80 001229E0  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 80125A84 001229E4  40 81 00 2C */	ble lbl_80125AB0
/* 80125A88 001229E8  EC 20 20 24 */	fdivs f1, f0, f4
/* 80125A8C 001229EC  C0 03 00 04 */	lfs f0, 4(r3)
/* 80125A90 001229F0  EC 00 00 72 */	fmuls f0, f0, f1
/* 80125A94 001229F4  D0 03 00 04 */	stfs f0, 4(r3)
/* 80125A98 001229F8  C0 03 00 08 */	lfs f0, 8(r3)
/* 80125A9C 001229FC  EC 00 00 72 */	fmuls f0, f0, f1
/* 80125AA0 00122A00  D0 03 00 08 */	stfs f0, 8(r3)
/* 80125AA4 00122A04  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 80125AA8 00122A08  EC 00 00 72 */	fmuls f0, f0, f1
/* 80125AAC 00122A0C  D0 03 00 0C */	stfs f0, 0xc(r3)
lbl_80125AB0:
/* 80125AB0 00122A10  38 21 00 20 */	addi r1, r1, 0x20
/* 80125AB4 00122A14  4E 80 00 20 */	blr 

.global output__16NVector3fIOClassFR9NVector3f
output__16NVector3fIOClassFR9NVector3f:
/* 80125AB8 00122A18  C0 03 00 04 */	lfs f0, 4(r3)
/* 80125ABC 00122A1C  D0 04 00 00 */	stfs f0, 0(r4)
/* 80125AC0 00122A20  C0 03 00 08 */	lfs f0, 8(r3)
/* 80125AC4 00122A24  D0 04 00 04 */	stfs f0, 4(r4)
/* 80125AC8 00122A28  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 80125ACC 00122A2C  D0 04 00 08 */	stfs f0, 8(r4)
/* 80125AD0 00122A30  4E 80 00 20 */	blr 

.global input__16NVector3fIOClassFR9NVector3f
input__16NVector3fIOClassFR9NVector3f:
/* 80125AD4 00122A34  C0 04 00 00 */	lfs f0, 0(r4)
/* 80125AD8 00122A38  D0 03 00 04 */	stfs f0, 4(r3)
/* 80125ADC 00122A3C  C0 04 00 04 */	lfs f0, 4(r4)
/* 80125AE0 00122A40  D0 03 00 08 */	stfs f0, 8(r3)
/* 80125AE4 00122A44  C0 04 00 08 */	lfs f0, 8(r4)
/* 80125AE8 00122A48  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 80125AEC 00122A4C  4E 80 00 20 */	blr 

.global input__22PeveCreaturePositionIOFR9NVector3f
input__22PeveCreaturePositionIOFR9NVector3f:
/* 80125AF0 00122A50  80 A3 00 04 */	lwz r5, 4(r3)
/* 80125AF4 00122A54  80 64 00 00 */	lwz r3, 0(r4)
/* 80125AF8 00122A58  80 04 00 04 */	lwz r0, 4(r4)
/* 80125AFC 00122A5C  90 65 00 94 */	stw r3, 0x94(r5)
/* 80125B00 00122A60  90 05 00 98 */	stw r0, 0x98(r5)
/* 80125B04 00122A64  80 04 00 08 */	lwz r0, 8(r4)
/* 80125B08 00122A68  90 05 00 9C */	stw r0, 0x9c(r5)
/* 80125B0C 00122A6C  4E 80 00 20 */	blr 

.global output__22PeveCreaturePositionIOFR9NVector3f
output__22PeveCreaturePositionIOFR9NVector3f:
/* 80125B10 00122A70  80 A3 00 04 */	lwz r5, 4(r3)
/* 80125B14 00122A74  80 65 00 94 */	lwz r3, 0x94(r5)
/* 80125B18 00122A78  80 05 00 98 */	lwz r0, 0x98(r5)
/* 80125B1C 00122A7C  90 64 00 00 */	stw r3, 0(r4)
/* 80125B20 00122A80  90 04 00 04 */	stw r0, 4(r4)
/* 80125B24 00122A84  80 05 00 9C */	lwz r0, 0x9c(r5)
/* 80125B28 00122A88  90 04 00 08 */	stw r0, 8(r4)
/* 80125B2C 00122A8C  4E 80 00 20 */	blr 

.global input__19PeveCameraPostureIOFR10NPosture3D
input__19PeveCameraPostureIOFR10NPosture3D:
/* 80125B30 00122A90  7C 08 02 A6 */	mflr r0
/* 80125B34 00122A94  90 01 00 04 */	stw r0, 4(r1)
/* 80125B38 00122A98  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80125B3C 00122A9C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80125B40 00122AA0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80125B44 00122AA4  7C 9E 23 78 */	mr r30, r4
/* 80125B48 00122AA8  38 9E 00 04 */	addi r4, r30, 4
/* 80125B4C 00122AAC  83 E3 00 04 */	lwz r31, 4(r3)
/* 80125B50 00122AB0  38 A4 00 04 */	addi r5, r4, 4
/* 80125B54 00122AB4  38 C4 00 08 */	addi r6, r4, 8
/* 80125B58 00122AB8  38 7F 00 08 */	addi r3, r31, 8
/* 80125B5C 00122ABC  4B F3 7B 31 */	bl set__8Vector3fFRCfRCfRCf
/* 80125B60 00122AC0  38 9E 00 10 */	addi r4, r30, 0x10
/* 80125B64 00122AC4  38 7F 00 14 */	addi r3, r31, 0x14
/* 80125B68 00122AC8  38 A4 00 04 */	addi r5, r4, 4
/* 80125B6C 00122ACC  38 C4 00 08 */	addi r6, r4, 8
/* 80125B70 00122AD0  4B F3 7B 1D */	bl set__8Vector3fFRCfRCfRCf
/* 80125B74 00122AD4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80125B78 00122AD8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80125B7C 00122ADC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80125B80 00122AE0  38 21 00 20 */	addi r1, r1, 0x20
/* 80125B84 00122AE4  7C 08 03 A6 */	mtlr r0
/* 80125B88 00122AE8  4E 80 00 20 */	blr 

.global output__19PeveCameraPostureIOFR10NPosture3D
output__19PeveCameraPostureIOFR10NPosture3D:
/* 80125B8C 00122AEC  7C 08 02 A6 */	mflr r0
/* 80125B90 00122AF0  90 01 00 04 */	stw r0, 4(r1)
/* 80125B94 00122AF4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80125B98 00122AF8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80125B9C 00122AFC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80125BA0 00122B00  3B C4 00 00 */	addi r30, r4, 0
/* 80125BA4 00122B04  83 E3 00 04 */	lwz r31, 4(r3)
/* 80125BA8 00122B08  38 7E 00 04 */	addi r3, r30, 4
/* 80125BAC 00122B0C  38 9F 00 08 */	addi r4, r31, 8
/* 80125BB0 00122B10  38 BF 00 0C */	addi r5, r31, 0xc
/* 80125BB4 00122B14  38 DF 00 10 */	addi r6, r31, 0x10
/* 80125BB8 00122B18  4B F3 7A D5 */	bl set__8Vector3fFRCfRCfRCf
/* 80125BBC 00122B1C  38 7E 00 10 */	addi r3, r30, 0x10
/* 80125BC0 00122B20  38 9F 00 14 */	addi r4, r31, 0x14
/* 80125BC4 00122B24  38 BF 00 18 */	addi r5, r31, 0x18
/* 80125BC8 00122B28  38 DF 00 1C */	addi r6, r31, 0x1c
/* 80125BCC 00122B2C  4B F3 7A C1 */	bl set__8Vector3fFRCfRCfRCf
/* 80125BD0 00122B30  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80125BD4 00122B34  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80125BD8 00122B38  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80125BDC 00122B3C  38 21 00 18 */	addi r1, r1, 0x18
/* 80125BE0 00122B40  7C 08 03 A6 */	mtlr r0
/* 80125BE4 00122B44  4E 80 00 20 */	blr 

.global input__22PeveCameraWatchpointIOFR9NVector3f
input__22PeveCameraWatchpointIOFR9NVector3f:
/* 80125BE8 00122B48  80 63 00 04 */	lwz r3, 4(r3)
/* 80125BEC 00122B4C  C0 04 00 00 */	lfs f0, 0(r4)
/* 80125BF0 00122B50  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 80125BF4 00122B54  C0 04 00 04 */	lfs f0, 4(r4)
/* 80125BF8 00122B58  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 80125BFC 00122B5C  C0 04 00 08 */	lfs f0, 8(r4)
/* 80125C00 00122B60  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 80125C04 00122B64  4E 80 00 20 */	blr 

.global output__22PeveCameraWatchpointIOFR9NVector3f
output__22PeveCameraWatchpointIOFR9NVector3f:
/* 80125C08 00122B68  80 63 00 04 */	lwz r3, 4(r3)
/* 80125C0C 00122B6C  C4 03 00 14 */	lfsu f0, 0x14(r3)
/* 80125C10 00122B70  D0 04 00 00 */	stfs f0, 0(r4)
/* 80125C14 00122B74  C0 03 00 04 */	lfs f0, 4(r3)
/* 80125C18 00122B78  D0 04 00 04 */	stfs f0, 4(r4)
/* 80125C1C 00122B7C  C0 03 00 08 */	lfs f0, 8(r3)
/* 80125C20 00122B80  D0 04 00 08 */	stfs f0, 8(r4)
/* 80125C24 00122B84  4E 80 00 20 */	blr 

.global input__21PeveCameraViewpointIOFR9NVector3f
input__21PeveCameraViewpointIOFR9NVector3f:
/* 80125C28 00122B88  80 63 00 04 */	lwz r3, 4(r3)
/* 80125C2C 00122B8C  C0 04 00 00 */	lfs f0, 0(r4)
/* 80125C30 00122B90  D0 03 00 08 */	stfs f0, 8(r3)
/* 80125C34 00122B94  C0 04 00 04 */	lfs f0, 4(r4)
/* 80125C38 00122B98  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 80125C3C 00122B9C  C0 04 00 08 */	lfs f0, 8(r4)
/* 80125C40 00122BA0  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 80125C44 00122BA4  4E 80 00 20 */	blr 

.global output__21PeveCameraViewpointIOFR9NVector3f
output__21PeveCameraViewpointIOFR9NVector3f:
/* 80125C48 00122BA8  80 63 00 04 */	lwz r3, 4(r3)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x66697368
	.4byte 0x4974656d
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x46697368
	.4byte 0x47656e65
	.4byte 0x7261746f
	.4byte 0x72000000
	.4byte 0x50616e69
	.4byte 0x416e696d
	.4byte 0x4b65794c
	.4byte 0x69737465
	.4byte 0x6e657200
	.4byte 0x4576656e
	.4byte 0x7454616c
	.4byte 0x6b657200
	.4byte 0x52656643
	.4byte 0x6f756e74
	.4byte 0x61626c65
	.4byte 0
	.4byte 0x43726561
	.4byte 0x74757265
	.4byte 0
	.4byte 0x803e1644
	.4byte 0x8
	.4byte 0x803e164c
	.4byte 0
	.4byte 0
	.4byte 0x41494372
	.4byte 0x65617475
	.4byte 0x72650000
	.4byte 0x803e163c
	.4byte 0x2b8
	.4byte 0x803e1644
	.4byte 0x8
	.4byte 0x803e164c
	.4byte 0
	.4byte 0x803e1654
	.4byte 0
	.4byte 0
	.4byte 0x4974656d
	.4byte 0x43726561
	.4byte 0x74757265
	.4byte 0
	.4byte 0x803e163c
	.4byte 0x2b8
	.4byte 0x803e1644
	.4byte 0x8
	.4byte 0x803e164c
	.4byte 0
	.4byte 0x803e1654
	.4byte 0
	.4byte 0x803e165c
	.4byte 0
	.4byte 0
	.4byte 0x803e163c
	.4byte 0x2b8
	.4byte 0x803e1644
	.4byte 0x8
	.4byte 0x803e164c
	.4byte 0
	.4byte 0x803e1654
	.4byte 0
	.4byte 0x803e165c
	.4byte 0
	.4byte 0x803e1664
	.4byte 0
	.4byte 0
.global __vt__13FishGenerator
__vt__13FishGenerator:
	.4byte __RTTI__13FishGenerator
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__12ItemCreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__13FishGeneratorFi
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__12ItemCreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__8CreatureFv
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__12ItemCreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__10AICreatureFR9CollEvent
	.4byte bounceCallback__10AICreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
	.4byte offwallCallback__8CreatureFP13DynCollObject
	.4byte stickCallback__8CreatureFP8Creature
	.4byte offstickCallback__8CreatureFP8Creature
	.4byte stickToCallback__8CreatureFP8Creature
	.4byte dump__8CreatureFv
	.4byte startWaterEffect__8CreatureFv
	.4byte finishWaterEffect__8CreatureFv
	.4byte isRopable__8CreatureFv
	.4byte mayIstick__8CreatureFv
	.4byte getFormationPri__8CreatureFv
	.4byte update__13FishGeneratorFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__13FishGeneratorFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__13FishGenerator
	.4byte 0xfffffd48
	.4byte lbl_8007DF54
	.4byte getCurrState__10AICreatureFv
	.4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
	.4byte playSound__10AICreatureFi
	.4byte playEffect__10AICreatureFi
	.4byte startMotion__12ItemCreatureFi
	.4byte finishMotion__12ItemCreatureFv
	.4byte finishMotion__12ItemCreatureFf
	.4byte startMotion__12ItemCreatureFif
	.4byte getCurrentMotionName__12ItemCreatureFv
	.4byte getCurrentMotionCounter__12ItemCreatureFv
	.4byte getMotionSpeed__12ItemCreatureFv
	.4byte setMotionSpeed__12ItemCreatureFf
	.4byte stopMotion__12ItemCreatureFv
	.4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
	.4byte finalSetup__12ItemCreatureFv
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x802BB9A4
	.4byte 0x00000000
	.4byte 0x802BB9B4
	.4byte 0x802BB9C0
	.4byte 0x802BB9D4
	.4byte 0x802BB9E0
	.4byte 0x802BBA04
	.4byte 0x802BBA14
.global __RTTI__10BoBaseItem
__RTTI__10BoBaseItem:
	.4byte 0x802bb978
	.4byte 0x802bba40
.global __RTTI__8KusaItem
__RTTI__8KusaItem:
	.4byte 0x802bbbd0
	.4byte 0x802bbbdc
.global lbl_803E15E0
lbl_803E15E0:
	.4byte 0x40800000
.global lbl_803E15E4
lbl_803E15E4:
	.4byte 0x00000000
.global lbl_803E15E8
lbl_803E15E8:
	.4byte 0x00000000
.global lbl_803E15EC
lbl_803E15EC:
	.4byte 0x00000000
.global lbl_803E15F0
lbl_803E15F0:
	.4byte 0x00000000
.global lbl_803E15F4
lbl_803E15F4:
	.4byte 0x00000000
.global lbl_803E15F8
lbl_803E15F8:
	.4byte 0x00000000
.global lbl_803E15FC
lbl_803E15FC:
	.4byte 0x00000000
.global lbl_803E1600
lbl_803E1600:
	.4byte 0x00000000
.global lbl_803E1604
lbl_803E1604:
	.4byte 0x00000000
.global lbl_803E1608
lbl_803E1608:
	.4byte 0x00000000
.global lbl_803E160C
lbl_803E160C:
	.4byte 0x00000000
.global lbl_803E1610
lbl_803E1610:
	.4byte 0x00000000
.global lbl_803E1614
lbl_803E1614:
	.4byte 0x42C80000
.global lbl_803E1618
lbl_803E1618:
	.4byte 0x42C80000
.global lbl_803E161C
lbl_803E161C:
	.4byte 0x3ECCCCCD
.global lbl_803E1620
lbl_803E1620:
	.4byte 0x3E4CCCCD
.global lbl_803E1624
lbl_803E1624:
	.4byte 0x3ECCCCCD
.global lbl_803E1628
lbl_803E1628:
	.4byte 0x42C80000
.global lbl_803E162C
lbl_803E162C:
	.4byte 0x00000000
.global lbl_803E1630
lbl_803E1630:
	.4byte 0x42C80000
.global lbl_803E1634
lbl_803E1634:
	.4byte 0x3F666666
.global lbl_803E1638
lbl_803E1638:
	.4byte 0x3DCCCCCD
	.4byte 0x802BBD90
	.4byte 0x00000000
	.4byte 0x802BBDA4
