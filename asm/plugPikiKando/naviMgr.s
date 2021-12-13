.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__7NaviMgrFv
__ct__7NaviMgrFv:
/* 801171C4 00114124  7C 08 02 A6 */	mflr r0
/* 801171C8 00114128  90 01 00 04 */	stw r0, 4(r1)
/* 801171CC 0011412C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801171D0 00114130  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801171D4 00114134  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801171D8 00114138  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801171DC 0011413C  90 61 00 08 */	stw r3, 8(r1)
/* 801171E0 00114140  3C 60 80 2C */	lis r3, lbl_802C2E70@ha
/* 801171E4 00114144  3B C3 2E 70 */	addi r30, r3, lbl_802C2E70@l
/* 801171E8 00114148  80 61 00 08 */	lwz r3, 8(r1)
/* 801171EC 0011414C  4B FC 9E 61 */	bl __ct__13MonoObjectMgrFv
/* 801171F0 00114150  3C 80 80 2C */	lis r4, __vt__7NaviMgr@ha
/* 801171F4 00114154  80 61 00 08 */	lwz r3, 8(r1)
/* 801171F8 00114158  38 84 2F D8 */	addi r4, r4, __vt__7NaviMgr@l
/* 801171FC 0011415C  90 83 00 00 */	stw r4, 0(r3)
/* 80117200 00114160  38 04 00 18 */	addi r0, r4, 0x18
/* 80117204 00114164  38 9E 00 18 */	addi r4, r30, 0x18
/* 80117208 00114168  90 03 00 08 */	stw r0, 8(r3)
/* 8011720C 0011416C  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80117210 00114170  4B F6 F5 29 */	bl start__7MemStatFPc
/* 80117214 00114174  38 60 04 3C */	li r3, 0x43c
/* 80117218 00114178  4B F2 FD ED */	bl alloc__6SystemFUl
/* 8011721C 0011417C  3B A3 00 00 */	addi r29, r3, 0
/* 80117220 00114180  7F A3 EB 79 */	or. r3, r29, r29
/* 80117224 00114184  41 82 00 08 */	beq lbl_8011722C
/* 80117228 00114188  4B FE 19 81 */	bl __ct__8NaviPropFv
lbl_8011722C:
/* 8011722C 0011418C  83 E1 00 08 */	lwz r31, 8(r1)
/* 80117230 00114190  38 BE 00 24 */	addi r5, r30, 0x24
/* 80117234 00114194  38 8D DC B0 */	addi r4, r13, lbl_803E29D0@sda21
/* 80117238 00114198  93 BF 00 58 */	stw r29, 0x58(r31)
/* 8011723C 0011419C  38 7F 00 08 */	addi r3, r31, 8
/* 80117240 001141A0  38 C0 00 01 */	li r6, 1
/* 80117244 001141A4  4B F2 94 5D */	bl load__8CoreNodeFPcPcUl
/* 80117248 001141A8  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 8011724C 001141AC  38 9E 00 18 */	addi r4, r30, 0x18
/* 80117250 001141B0  4B F6 F5 F9 */	bl end__7MemStatFPc
/* 80117254 001141B4  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80117258 001141B8  38 9E 00 30 */	addi r4, r30, 0x30
/* 8011725C 001141BC  4B F6 F4 DD */	bl start__7MemStatFPc
/* 80117260 001141C0  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80117264 001141C4  38 9E 00 40 */	addi r4, r30, 0x40
/* 80117268 001141C8  4B F6 F4 D1 */	bl start__7MemStatFPc
/* 8011726C 001141CC  48 00 1A 99 */	bl createMotionTable__16PaniPikiAnimatorFv
/* 80117270 001141D0  90 7F 00 50 */	stw r3, 0x50(r31)
/* 80117274 001141D4  38 9E 00 40 */	addi r4, r30, 0x40
/* 80117278 001141D8  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 8011727C 001141DC  4B F6 F5 CD */	bl end__7MemStatFPc
/* 80117280 001141E0  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80117284 001141E4  38 9E 00 4C */	addi r4, r30, 0x4c
/* 80117288 001141E8  4B F6 F4 B1 */	bl start__7MemStatFPc
/* 8011728C 001141EC  3C 60 80 3A */	lis r3, gameflow@ha
/* 80117290 001141F0  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 80117294 001141F4  38 9E 00 58 */	addi r4, r30, 0x58
/* 80117298 001141F8  38 A0 00 01 */	li r5, 1
/* 8011729C 001141FC  4B F3 BA 75 */	bl loadShape__8GameFlowFPcb
/* 801172A0 00114200  90 7F 00 40 */	stw r3, 0x40(r31)
/* 801172A4 00114204  38 9E 00 4C */	addi r4, r30, 0x4c
/* 801172A8 00114208  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 801172AC 0011420C  4B F6 F5 9D */	bl end__7MemStatFPc
/* 801172B0 00114210  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 801172B4 00114214  38 9E 00 6C */	addi r4, r30, 0x6c
/* 801172B8 00114218  4B F6 F4 81 */	bl start__7MemStatFPc
/* 801172BC 0011421C  38 60 00 28 */	li r3, 0x28
/* 801172C0 00114220  4B F2 FD 45 */	bl alloc__6SystemFUl
/* 801172C4 00114224  3B A3 00 00 */	addi r29, r3, 0
/* 801172C8 00114228  7F A3 EB 79 */	or. r3, r29, r29
/* 801172CC 0011422C  41 82 00 0C */	beq lbl_801172D8
/* 801172D0 00114230  80 9F 00 40 */	lwz r4, 0x40(r31)
/* 801172D4 00114234  4B FC 18 01 */	bl __ct__15PikiShapeObjectFP5Shape
lbl_801172D8:
/* 801172D8 00114238  83 E1 00 08 */	lwz r31, 8(r1)
/* 801172DC 0011423C  38 9E 00 6C */	addi r4, r30, 0x6c
/* 801172E0 00114240  93 BF 00 48 */	stw r29, 0x48(r31)
/* 801172E4 00114244  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 801172E8 00114248  4B F6 F5 61 */	bl end__7MemStatFPc
/* 801172EC 0011424C  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 801172F0 00114250  38 9E 00 80 */	addi r4, r30, 0x80
/* 801172F4 00114254  4B F6 F4 45 */	bl start__7MemStatFPc
/* 801172F8 00114258  4B FC 15 ED */	bl getAnimMgr__15PikiShapeObjectFv
/* 801172FC 0011425C  80 BF 00 48 */	lwz r5, 0x48(r31)
/* 80117300 00114260  38 9E 00 80 */	addi r4, r30, 0x80
/* 80117304 00114264  90 65 00 24 */	stw r3, 0x24(r5)
/* 80117308 00114268  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 8011730C 0011426C  4B F6 F5 3D */	bl end__7MemStatFPc
/* 80117310 00114270  38 00 00 00 */	li r0, 0
/* 80117314 00114274  90 1F 00 54 */	stw r0, 0x54(r31)
/* 80117318 00114278  38 9E 00 30 */	addi r4, r30, 0x30
/* 8011731C 0011427C  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80117320 00114280  4B F6 F5 29 */	bl end__7MemStatFPc
/* 80117324 00114284  7F E3 FB 78 */	mr r3, r31
/* 80117328 00114288  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011732C 0011428C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80117330 00114290  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80117334 00114294  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80117338 00114298  38 21 00 20 */	addi r1, r1, 0x20
/* 8011733C 0011429C  7C 08 03 A6 */	mtlr r0
/* 80117340 001142A0  4E 80 00 20 */	blr 

.global createObject__7NaviMgrFv
createObject__7NaviMgrFv:
/* 80117344 001142A4  7C 08 02 A6 */	mflr r0
/* 80117348 001142A8  90 01 00 04 */	stw r0, 4(r1)
/* 8011734C 001142AC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80117350 001142B0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80117354 001142B4  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80117358 001142B8  3B C3 00 00 */	addi r30, r3, 0
/* 8011735C 001142BC  38 60 0A E0 */	li r3, 0xae0
/* 80117360 001142C0  4B F2 FC A5 */	bl alloc__6SystemFUl
/* 80117364 001142C4  3B E3 00 00 */	addi r31, r3, 0
/* 80117368 001142C8  7F E3 FB 79 */	or. r3, r31, r31
/* 8011736C 001142CC  41 82 00 10 */	beq lbl_8011737C
/* 80117370 001142D0  80 9E 00 58 */	lwz r4, 0x58(r30)
/* 80117374 001142D4  80 BE 00 54 */	lwz r5, 0x54(r30)
/* 80117378 001142D8  4B FE 28 15 */	bl __ct__4NaviFP12CreaturePropi
lbl_8011737C:
/* 8011737C 001142DC  80 9E 00 54 */	lwz r4, 0x54(r30)
/* 80117380 001142E0  38 7F 00 00 */	addi r3, r31, 0
/* 80117384 001142E4  38 04 00 01 */	addi r0, r4, 1
/* 80117388 001142E8  90 1E 00 54 */	stw r0, 0x54(r30)
/* 8011738C 001142EC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80117390 001142F0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80117394 001142F4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80117398 001142F8  38 21 00 18 */	addi r1, r1, 0x18
/* 8011739C 001142FC  7C 08 03 A6 */	mtlr r0
/* 801173A0 00114300  4E 80 00 20 */	blr 

.global update__7NaviMgrFv
update__7NaviMgrFv:
/* 801173A4 00114304  7C 08 02 A6 */	mflr r0
/* 801173A8 00114308  90 01 00 04 */	stw r0, 4(r1)
/* 801173AC 0011430C  94 21 FF F8 */	stwu r1, -8(r1)
/* 801173B0 00114310  4B FC 9F D9 */	bl update__13MonoObjectMgrFv
/* 801173B4 00114314  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801173B8 00114318  38 21 00 08 */	addi r1, r1, 8
/* 801173BC 0011431C  7C 08 03 A6 */	mtlr r0
/* 801173C0 00114320  4E 80 00 20 */	blr 

.global getNavi__7NaviMgrFv
getNavi__7NaviMgrFv:
/* 801173C4 00114324  7C 08 02 A6 */	mflr r0
/* 801173C8 00114328  90 01 00 04 */	stw r0, 4(r1)
/* 801173CC 0011432C  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 801173D0 00114330  93 E1 00 24 */	stw r31, 0x24(r1)
/* 801173D4 00114334  7C 7F 1B 78 */	mr r31, r3
/* 801173D8 00114338  81 9F 00 00 */	lwz r12, 0(r31)
/* 801173DC 0011433C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801173E0 00114340  7D 88 03 A6 */	mtlr r12
/* 801173E4 00114344  4E 80 00 21 */	blrl 
/* 801173E8 00114348  38 83 00 00 */	addi r4, r3, 0
/* 801173EC 0011434C  2C 04 FF FF */	cmpwi r4, -1
/* 801173F0 00114350  40 82 00 20 */	bne lbl_80117410
/* 801173F4 00114354  7F E3 FB 78 */	mr r3, r31
/* 801173F8 00114358  81 9F 00 00 */	lwz r12, 0(r31)
/* 801173FC 0011435C  38 80 00 00 */	li r4, 0
/* 80117400 00114360  81 8C 00 08 */	lwz r12, 8(r12)
/* 80117404 00114364  7D 88 03 A6 */	mtlr r12
/* 80117408 00114368  4E 80 00 21 */	blrl 
/* 8011740C 0011436C  48 00 00 18 */	b lbl_80117424
lbl_80117410:
/* 80117410 00114370  81 9F 00 00 */	lwz r12, 0(r31)
/* 80117414 00114374  7F E3 FB 78 */	mr r3, r31
/* 80117418 00114378  81 8C 00 08 */	lwz r12, 8(r12)
/* 8011741C 0011437C  7D 88 03 A6 */	mtlr r12
/* 80117420 00114380  4E 80 00 21 */	blrl 
lbl_80117424:
/* 80117424 00114384  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80117428 00114388  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8011742C 0011438C  38 21 00 28 */	addi r1, r1, 0x28
/* 80117430 00114390  7C 08 03 A6 */	mtlr r0
/* 80117434 00114394  4E 80 00 20 */	blr 

.global getNavi__7NaviMgrFi
getNavi__7NaviMgrFi:
/* 80117438 00114398  80 03 00 30 */	lwz r0, 0x30(r3)
/* 8011743C 0011439C  7C 04 00 00 */	cmpw r4, r0
/* 80117440 001143A0  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80117444 001143A4  54 80 10 3A */	slwi r0, r4, 2
/* 80117448 001143A8  7C 63 00 2E */	lwzx r3, r3, r0
/* 8011744C 001143AC  4E 80 00 20 */	blr 

.global refresh2d__7NaviMgrFR8Graphics
refresh2d__7NaviMgrFR8Graphics:
/* 80117450 001143B0  7C 08 02 A6 */	mflr r0
/* 80117454 001143B4  90 01 00 04 */	stw r0, 4(r1)
/* 80117458 001143B8  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8011745C 001143BC  93 E1 00 34 */	stw r31, 0x34(r1)
/* 80117460 001143C0  7C 7F 1B 78 */	mr r31, r3
/* 80117464 001143C4  93 C1 00 30 */	stw r30, 0x30(r1)
/* 80117468 001143C8  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 8011746C 001143CC  7C 9D 23 78 */	mr r29, r4
/* 80117470 001143D0  81 9F 00 00 */	lwz r12, 0(r31)
/* 80117474 001143D4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80117478 001143D8  7D 88 03 A6 */	mtlr r12
/* 8011747C 001143DC  4E 80 00 21 */	blrl 
/* 80117480 001143E0  7C 7E 1B 78 */	mr r30, r3
/* 80117484 001143E4  48 00 00 70 */	b lbl_801174F4
lbl_80117488:
/* 80117488 001143E8  2C 1E FF FF */	cmpwi r30, -1
/* 8011748C 001143EC  40 82 00 20 */	bne lbl_801174AC
/* 80117490 001143F0  7F E3 FB 78 */	mr r3, r31
/* 80117494 001143F4  81 9F 00 00 */	lwz r12, 0(r31)
/* 80117498 001143F8  38 80 00 00 */	li r4, 0
/* 8011749C 001143FC  81 8C 00 08 */	lwz r12, 8(r12)
/* 801174A0 00114400  7D 88 03 A6 */	mtlr r12
/* 801174A4 00114404  4E 80 00 21 */	blrl 
/* 801174A8 00114408  48 00 00 1C */	b lbl_801174C4
lbl_801174AC:
/* 801174AC 0011440C  7F E3 FB 78 */	mr r3, r31
/* 801174B0 00114410  81 9F 00 00 */	lwz r12, 0(r31)
/* 801174B4 00114414  7F C4 F3 78 */	mr r4, r30
/* 801174B8 00114418  81 8C 00 08 */	lwz r12, 8(r12)
/* 801174BC 0011441C  7D 88 03 A6 */	mtlr r12
/* 801174C0 00114420  4E 80 00 21 */	blrl 
lbl_801174C4:
/* 801174C4 00114424  81 83 00 00 */	lwz r12, 0(r3)
/* 801174C8 00114428  7F A4 EB 78 */	mr r4, r29
/* 801174CC 0011442C  81 8C 00 F0 */	lwz r12, 0xf0(r12)
/* 801174D0 00114430  7D 88 03 A6 */	mtlr r12
/* 801174D4 00114434  4E 80 00 21 */	blrl 
/* 801174D8 00114438  7F E3 FB 78 */	mr r3, r31
/* 801174DC 0011443C  81 9F 00 00 */	lwz r12, 0(r31)
/* 801174E0 00114440  7F C4 F3 78 */	mr r4, r30
/* 801174E4 00114444  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801174E8 00114448  7D 88 03 A6 */	mtlr r12
/* 801174EC 0011444C  4E 80 00 21 */	blrl 
/* 801174F0 00114450  7C 7E 1B 78 */	mr r30, r3
lbl_801174F4:
/* 801174F4 00114454  7F E3 FB 78 */	mr r3, r31
/* 801174F8 00114458  81 9F 00 00 */	lwz r12, 0(r31)
/* 801174FC 0011445C  7F C4 F3 78 */	mr r4, r30
/* 80117500 00114460  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80117504 00114464  7D 88 03 A6 */	mtlr r12
/* 80117508 00114468  4E 80 00 21 */	blrl 
/* 8011750C 0011446C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80117510 00114470  41 82 00 0C */	beq lbl_8011751C
/* 80117514 00114474  38 00 00 01 */	li r0, 1
/* 80117518 00114478  48 00 00 30 */	b lbl_80117548
lbl_8011751C:
/* 8011751C 0011447C  7F E3 FB 78 */	mr r3, r31
/* 80117520 00114480  81 9F 00 00 */	lwz r12, 0(r31)
/* 80117524 00114484  7F C4 F3 78 */	mr r4, r30
/* 80117528 00114488  81 8C 00 08 */	lwz r12, 8(r12)
/* 8011752C 0011448C  7D 88 03 A6 */	mtlr r12
/* 80117530 00114490  4E 80 00 21 */	blrl 
/* 80117534 00114494  28 03 00 00 */	cmplwi r3, 0
/* 80117538 00114498  40 82 00 0C */	bne lbl_80117544
/* 8011753C 0011449C  38 00 00 01 */	li r0, 1
/* 80117540 001144A0  48 00 00 08 */	b lbl_80117548
lbl_80117544:
/* 80117544 001144A4  38 00 00 00 */	li r0, 0
lbl_80117548:
/* 80117548 001144A8  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8011754C 001144AC  41 82 FF 3C */	beq lbl_80117488
/* 80117550 001144B0  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 80117554 001144B4  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 80117558 001144B8  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 8011755C 001144BC  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 80117560 001144C0  38 21 00 38 */	addi r1, r1, 0x38
/* 80117564 001144C4  7C 08 03 A6 */	mtlr r0
/* 80117568 001144C8  4E 80 00 20 */	blr 

.global renderCircle__7NaviMgrFR8Graphics
renderCircle__7NaviMgrFR8Graphics:
/* 8011756C 001144CC  7C 08 02 A6 */	mflr r0
/* 80117570 001144D0  90 01 00 04 */	stw r0, 4(r1)
/* 80117574 001144D4  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 80117578 001144D8  93 E1 00 34 */	stw r31, 0x34(r1)
/* 8011757C 001144DC  7C 7F 1B 78 */	mr r31, r3
/* 80117580 001144E0  93 C1 00 30 */	stw r30, 0x30(r1)
/* 80117584 001144E4  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 80117588 001144E8  7C 9D 23 78 */	mr r29, r4
/* 8011758C 001144EC  81 9F 00 00 */	lwz r12, 0(r31)
/* 80117590 001144F0  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80117594 001144F4  7D 88 03 A6 */	mtlr r12
/* 80117598 001144F8  4E 80 00 21 */	blrl 
/* 8011759C 001144FC  7C 7E 1B 78 */	mr r30, r3
/* 801175A0 00114500  48 00 00 64 */	b lbl_80117604
lbl_801175A4:
/* 801175A4 00114504  2C 1E FF FF */	cmpwi r30, -1
/* 801175A8 00114508  40 82 00 20 */	bne lbl_801175C8
/* 801175AC 0011450C  7F E3 FB 78 */	mr r3, r31
/* 801175B0 00114510  81 9F 00 00 */	lwz r12, 0(r31)
/* 801175B4 00114514  38 80 00 00 */	li r4, 0
/* 801175B8 00114518  81 8C 00 08 */	lwz r12, 8(r12)
/* 801175BC 0011451C  7D 88 03 A6 */	mtlr r12
/* 801175C0 00114520  4E 80 00 21 */	blrl 
/* 801175C4 00114524  48 00 00 1C */	b lbl_801175E0
lbl_801175C8:
/* 801175C8 00114528  7F E3 FB 78 */	mr r3, r31
/* 801175CC 0011452C  81 9F 00 00 */	lwz r12, 0(r31)
/* 801175D0 00114530  7F C4 F3 78 */	mr r4, r30
/* 801175D4 00114534  81 8C 00 08 */	lwz r12, 8(r12)
/* 801175D8 00114538  7D 88 03 A6 */	mtlr r12
/* 801175DC 0011453C  4E 80 00 21 */	blrl 
lbl_801175E0:
/* 801175E0 00114540  7F A4 EB 78 */	mr r4, r29
/* 801175E4 00114544  4B FE 7F C9 */	bl renderCircle__4NaviFR8Graphics
/* 801175E8 00114548  7F E3 FB 78 */	mr r3, r31
/* 801175EC 0011454C  81 9F 00 00 */	lwz r12, 0(r31)
/* 801175F0 00114550  7F C4 F3 78 */	mr r4, r30
/* 801175F4 00114554  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801175F8 00114558  7D 88 03 A6 */	mtlr r12
/* 801175FC 0011455C  4E 80 00 21 */	blrl 
/* 80117600 00114560  7C 7E 1B 78 */	mr r30, r3
lbl_80117604:
/* 80117604 00114564  7F E3 FB 78 */	mr r3, r31
/* 80117608 00114568  81 9F 00 00 */	lwz r12, 0(r31)
/* 8011760C 0011456C  7F C4 F3 78 */	mr r4, r30
/* 80117610 00114570  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80117614 00114574  7D 88 03 A6 */	mtlr r12
/* 80117618 00114578  4E 80 00 21 */	blrl 
/* 8011761C 0011457C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80117620 00114580  41 82 00 0C */	beq lbl_8011762C
/* 80117624 00114584  38 00 00 01 */	li r0, 1
/* 80117628 00114588  48 00 00 30 */	b lbl_80117658
lbl_8011762C:
/* 8011762C 0011458C  7F E3 FB 78 */	mr r3, r31
/* 80117630 00114590  81 9F 00 00 */	lwz r12, 0(r31)
/* 80117634 00114594  7F C4 F3 78 */	mr r4, r30
/* 80117638 00114598  81 8C 00 08 */	lwz r12, 8(r12)
/* 8011763C 0011459C  7D 88 03 A6 */	mtlr r12
/* 80117640 001145A0  4E 80 00 21 */	blrl 
/* 80117644 001145A4  28 03 00 00 */	cmplwi r3, 0
/* 80117648 001145A8  40 82 00 0C */	bne lbl_80117654
/* 8011764C 001145AC  38 00 00 01 */	li r0, 1
/* 80117650 001145B0  48 00 00 08 */	b lbl_80117658
lbl_80117654:
/* 80117654 001145B4  38 00 00 00 */	li r0, 0
lbl_80117658:
/* 80117658 001145B8  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8011765C 001145BC  41 82 FF 48 */	beq lbl_801175A4
/* 80117660 001145C0  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 80117664 001145C4  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 80117668 001145C8  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 8011766C 001145CC  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 80117670 001145D0  38 21 00 38 */	addi r1, r1, 0x38
/* 80117674 001145D4  7C 08 03 A6 */	mtlr r0
/* 80117678 001145D8  4E 80 00 20 */	blr 

.global drawShadow__7NaviMgrFR8Graphics
drawShadow__7NaviMgrFR8Graphics:
/* 8011767C 001145DC  7C 08 02 A6 */	mflr r0
/* 80117680 001145E0  90 01 00 04 */	stw r0, 4(r1)
/* 80117684 001145E4  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 80117688 001145E8  93 E1 00 34 */	stw r31, 0x34(r1)
/* 8011768C 001145EC  7C 7F 1B 78 */	mr r31, r3
/* 80117690 001145F0  93 C1 00 30 */	stw r30, 0x30(r1)
/* 80117694 001145F4  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 80117698 001145F8  7C 9D 23 78 */	mr r29, r4
/* 8011769C 001145FC  81 9F 00 00 */	lwz r12, 0(r31)
/* 801176A0 00114600  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801176A4 00114604  7D 88 03 A6 */	mtlr r12
/* 801176A8 00114608  4E 80 00 21 */	blrl 
/* 801176AC 0011460C  7C 7E 1B 78 */	mr r30, r3
/* 801176B0 00114610  48 00 00 70 */	b lbl_80117720
lbl_801176B4:
/* 801176B4 00114614  2C 1E FF FF */	cmpwi r30, -1
/* 801176B8 00114618  40 82 00 20 */	bne lbl_801176D8
/* 801176BC 0011461C  7F E3 FB 78 */	mr r3, r31
/* 801176C0 00114620  81 9F 00 00 */	lwz r12, 0(r31)
/* 801176C4 00114624  38 80 00 00 */	li r4, 0
/* 801176C8 00114628  81 8C 00 08 */	lwz r12, 8(r12)
/* 801176CC 0011462C  7D 88 03 A6 */	mtlr r12
/* 801176D0 00114630  4E 80 00 21 */	blrl 
/* 801176D4 00114634  48 00 00 1C */	b lbl_801176F0
lbl_801176D8:
/* 801176D8 00114638  7F E3 FB 78 */	mr r3, r31
/* 801176DC 0011463C  81 9F 00 00 */	lwz r12, 0(r31)
/* 801176E0 00114640  7F C4 F3 78 */	mr r4, r30
/* 801176E4 00114644  81 8C 00 08 */	lwz r12, 8(r12)
/* 801176E8 00114648  7D 88 03 A6 */	mtlr r12
/* 801176EC 0011464C  4E 80 00 21 */	blrl 
lbl_801176F0:
/* 801176F0 00114650  81 83 00 00 */	lwz r12, 0(r3)
/* 801176F4 00114654  7F A4 EB 78 */	mr r4, r29
/* 801176F8 00114658  81 8C 00 F8 */	lwz r12, 0xf8(r12)
/* 801176FC 0011465C  7D 88 03 A6 */	mtlr r12
/* 80117700 00114660  4E 80 00 21 */	blrl 
/* 80117704 00114664  7F E3 FB 78 */	mr r3, r31
/* 80117708 00114668  81 9F 00 00 */	lwz r12, 0(r31)
/* 8011770C 0011466C  7F C4 F3 78 */	mr r4, r30
/* 80117710 00114670  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80117714 00114674  7D 88 03 A6 */	mtlr r12
/* 80117718 00114678  4E 80 00 21 */	blrl 
/* 8011771C 0011467C  7C 7E 1B 78 */	mr r30, r3
lbl_80117720:
/* 80117720 00114680  7F E3 FB 78 */	mr r3, r31
/* 80117724 00114684  81 9F 00 00 */	lwz r12, 0(r31)
/* 80117728 00114688  7F C4 F3 78 */	mr r4, r30
/* 8011772C 0011468C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80117730 00114690  7D 88 03 A6 */	mtlr r12
/* 80117734 00114694  4E 80 00 21 */	blrl 
/* 80117738 00114698  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8011773C 0011469C  41 82 00 0C */	beq lbl_80117748
/* 80117740 001146A0  38 00 00 01 */	li r0, 1
/* 80117744 001146A4  48 00 00 30 */	b lbl_80117774
lbl_80117748:
/* 80117748 001146A8  7F E3 FB 78 */	mr r3, r31
/* 8011774C 001146AC  81 9F 00 00 */	lwz r12, 0(r31)
/* 80117750 001146B0  7F C4 F3 78 */	mr r4, r30
/* 80117754 001146B4  81 8C 00 08 */	lwz r12, 8(r12)
/* 80117758 001146B8  7D 88 03 A6 */	mtlr r12
/* 8011775C 001146BC  4E 80 00 21 */	blrl 
/* 80117760 001146C0  28 03 00 00 */	cmplwi r3, 0
/* 80117764 001146C4  40 82 00 0C */	bne lbl_80117770
/* 80117768 001146C8  38 00 00 01 */	li r0, 1
/* 8011776C 001146CC  48 00 00 08 */	b lbl_80117774
lbl_80117770:
/* 80117770 001146D0  38 00 00 00 */	li r0, 0
lbl_80117774:
/* 80117774 001146D4  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 80117778 001146D8  41 82 FF 3C */	beq lbl_801176B4
/* 8011777C 001146DC  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 80117780 001146E0  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 80117784 001146E4  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 80117788 001146E8  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 8011778C 001146EC  38 21 00 38 */	addi r1, r1, 0x38
/* 80117790 001146F0  7C 08 03 A6 */	mtlr r0
/* 80117794 001146F4  4E 80 00 20 */	blr 

.global read__7NaviMgrFR18RandomAccessStream
read__7NaviMgrFR18RandomAccessStream:
/* 80117798 001146F8  7C 08 02 A6 */	mflr r0
/* 8011779C 001146FC  90 01 00 04 */	stw r0, 4(r1)
/* 801177A0 00114700  94 21 FF F8 */	stwu r1, -8(r1)
/* 801177A4 00114704  80 63 00 58 */	lwz r3, 0x58(r3)
/* 801177A8 00114708  81 83 00 54 */	lwz r12, 0x54(r3)
/* 801177AC 0011470C  81 8C 00 08 */	lwz r12, 8(r12)
/* 801177B0 00114710  7D 88 03 A6 */	mtlr r12
/* 801177B4 00114714  4E 80 00 21 */	blrl 
/* 801177B8 00114718  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801177BC 0011471C  38 21 00 08 */	addi r1, r1, 8
/* 801177C0 00114720  7C 08 03 A6 */	mtlr r0
/* 801177C4 00114724  4E 80 00 20 */	blr 

.global __dt__7NaviMgrFv
__dt__7NaviMgrFv:
/* 801177C8 00114728  7C 08 02 A6 */	mflr r0
/* 801177CC 0011472C  90 01 00 04 */	stw r0, 4(r1)
/* 801177D0 00114730  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801177D4 00114734  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801177D8 00114738  7C 7F 1B 79 */	or. r31, r3, r3
/* 801177DC 0011473C  41 82 00 58 */	beq lbl_80117834
/* 801177E0 00114740  3C 60 80 2C */	lis r3, __vt__7NaviMgr@ha
/* 801177E4 00114744  38 63 2F D8 */	addi r3, r3, __vt__7NaviMgr@l
/* 801177E8 00114748  90 7F 00 00 */	stw r3, 0(r31)
/* 801177EC 0011474C  38 03 00 18 */	addi r0, r3, 0x18
/* 801177F0 00114750  90 1F 00 08 */	stw r0, 8(r31)
/* 801177F4 00114754  41 82 00 30 */	beq lbl_80117824
/* 801177F8 00114758  3C 60 80 2C */	lis r3, __vt__13MonoObjectMgr@ha
/* 801177FC 0011475C  38 63 AF C8 */	addi r3, r3, __vt__13MonoObjectMgr@l
/* 80117800 00114760  90 7F 00 00 */	stw r3, 0(r31)
/* 80117804 00114764  38 03 00 18 */	addi r0, r3, 0x18
/* 80117808 00114768  90 1F 00 08 */	stw r0, 8(r31)
/* 8011780C 0011476C  41 82 00 18 */	beq lbl_80117824
/* 80117810 00114770  3C 60 80 2C */	lis r3, __vt__9ObjectMgr@ha
/* 80117814 00114774  38 63 B0 80 */	addi r3, r3, __vt__9ObjectMgr@l
/* 80117818 00114778  90 7F 00 00 */	stw r3, 0(r31)
/* 8011781C 0011477C  38 03 00 18 */	addi r0, r3, 0x18
/* 80117820 00114780  90 1F 00 08 */	stw r0, 8(r31)
lbl_80117824:
/* 80117824 00114784  7C 80 07 35 */	extsh. r0, r4
/* 80117828 00114788  40 81 00 0C */	ble lbl_80117834
/* 8011782C 0011478C  7F E3 FB 78 */	mr r3, r31
/* 80117830 00114790  4B F2 F9 7D */	bl __dl__FPv
lbl_80117834:
/* 80117834 00114794  7F E3 FB 78 */	mr r3, r31
/* 80117838 00114798  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011783C 0011479C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80117840 001147A0  38 21 00 18 */	addi r1, r1, 0x18
/* 80117844 001147A4  7C 08 03 A6 */	mtlr r0
/* 80117848 001147A8  4E 80 00 20 */	blr 

"@8@read__7NaviMgrFR18RandomAccessStream":
/* 8011784C 001147AC  38 63 FF F8 */	addi r3, r3, -8
/* 80117850 001147B0  4B FF FF 48 */	b read__7NaviMgrFR18RandomAccessStream

"@8@update__7NaviMgrFv":
/* 80117854 001147B4  38 63 FF F8 */	addi r3, r3, -8
/* 80117858 001147B8  4B FF FB 4C */	b update__7NaviMgrFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C2E70:
	.asciz "naviMgr.cpp"
.balign 4
lbl_802C2E7C:
	.asciz "naviiMgr"
.balign 4
lbl_802C2E88:
	.asciz "naviparms"
.balign 4
lbl_802C2E94:
	.asciz "naviMgr.bin"
.balign 4
lbl_802C2EA0:
	.asciz "navi shape anim"
.balign 4
lbl_802C2EB0:
	.asciz "navi mtable"
.balign 4
lbl_802C2EBC:
	.asciz "navi shape"
.balign 4
lbl_802C2EC8:
	.asciz "pikis/nv3Model.mod"
.balign 4
lbl_802C2EDC:
	.asciz "navi shapeobject"
.balign 4
lbl_802C2EF0:
	.asciz "navi animmgr"
.balign 4
lbl_802C2F00:
	.asciz "CoreNode"
.balign 4
lbl_802C2F0C:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802C2F18:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
lbl_802C2F2C:
	.asciz "Traversable"
.balign 4
lbl_802C2F38:
	.asciz "ObjectMgr"
.balign 4
lbl_802C2F44:
	.4byte __RTTI__5ANode
	.4byte 0x00000008
	.4byte __RTTI__8CoreNode
	.4byte 0x00000008
	.4byte __RTTI__4Node
	.4byte 0x00000008
	.4byte __RTTI__11Traversable
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
lbl_802C2F68:
	.asciz "MonoObjectMgr"
.balign 4
lbl_802C2F78:
	.4byte __RTTI__5ANode
	.4byte 0x00000008
	.4byte __RTTI__8CoreNode
	.4byte 0x00000008
	.4byte __RTTI__4Node
	.4byte 0x00000008
	.4byte __RTTI__11Traversable
	.4byte 0x00000000
	.4byte __RTTI__9ObjectMgr
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802C2FA4:
	.4byte __RTTI__5ANode
	.4byte 0x00000008
	.4byte __RTTI__8CoreNode
	.4byte 0x00000008
	.4byte __RTTI__4Node
	.4byte 0x00000008
	.4byte __RTTI__11Traversable
	.4byte 0x00000000
	.4byte __RTTI__9ObjectMgr
	.4byte 0x00000000
	.4byte __RTTI__13MonoObjectMgr
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__7NaviMgr
__vt__7NaviMgr:
	.4byte __RTTI__7NaviMgr
	.4byte 0
	.4byte getCreature__13MonoObjectMgrFi
	.4byte getFirst__13MonoObjectMgrFv
	.4byte getNext__13MonoObjectMgrFi
	.4byte isDone__13MonoObjectMgrFi
	.4byte __RTTI__7NaviMgr
	.4byte 0xFFFFFFF8
	.4byte getAgeNodeType__5ANodeFv
	.4byte "@8@read__7NaviMgrFR18RandomAccessStream"
	.4byte "@8@update__7NaviMgrFv"
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte __dt__7NaviMgrFv
	.4byte update__7NaviMgrFv
	.4byte postUpdate__13MonoObjectMgrFif
	.4byte stickUpdate__9ObjectMgrFv
	.4byte refresh__13MonoObjectMgrFR8Graphics
	.4byte drawShadow__13MonoObjectMgrFR8GraphicsP7Texture
	.4byte getSize__13MonoObjectMgrFv
	.4byte getMax__13MonoObjectMgrFv
	.4byte findClosest__9ObjectMgrFR8Vector3ffP9Condition
	.4byte findClosest__9ObjectMgrFR8Vector3fP9Condition
	.4byte search__13MonoObjectMgrFP9ObjectMgr
	.4byte killAll__9ObjectMgrFv
	.4byte birth__13MonoObjectMgrFv
	.4byte kill__13MonoObjectMgrFP8Creature
	.4byte createObject__7NaviMgrFv
	.4byte read__7NaviMgrFR18RandomAccessStream

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E29D0:
	.asciz "parms/"
.balign 4
lbl_803E29D8:
	.asciz "NaviMgr"
.balign 4
lbl_803E29E0:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E29E0
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802C2F00
	.4byte lbl_802C2F0C
lbl_803E29F8:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803E29F8
	.4byte lbl_802C2F18
__RTTI__11Traversable:
	.4byte lbl_802C2F2C
	.4byte 0
__RTTI__9ObjectMgr:
	.4byte lbl_802C2F38
	.4byte lbl_802C2F44
__RTTI__13MonoObjectMgr:
	.4byte lbl_802C2F68
	.4byte lbl_802C2F78
__RTTI__7NaviMgr:
	.4byte lbl_803E29D8
	.4byte lbl_802C2FA4

.section .sbss, "wa"
.balign 8
.global naviMgr
naviMgr:
	.skip 0x4
