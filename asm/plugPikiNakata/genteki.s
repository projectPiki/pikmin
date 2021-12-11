.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global makeObjectTeki__Fv
makeObjectTeki__Fv:
/* 8011B2CC 0011822C  7C 08 02 A6 */	mflr r0
/* 8011B2D0 00118230  38 60 00 20 */	li r3, 0x20
/* 8011B2D4 00118234  90 01 00 04 */	stw r0, 4(r1)
/* 8011B2D8 00118238  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8011B2DC 0011823C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8011B2E0 00118240  4B F2 BD 25 */	bl alloc__6SystemFUl
/* 8011B2E4 00118244  3B E3 00 00 */	addi r31, r3, 0
/* 8011B2E8 00118248  7F E3 FB 79 */	or. r3, r31, r31
/* 8011B2EC 0011824C  41 82 00 08 */	beq lbl_8011B2F4
/* 8011B2F0 00118250  48 00 00 A5 */	bl __ct__13GenObjectTekiFv
lbl_8011B2F4:
/* 8011B2F4 00118254  7F E3 FB 78 */	mr r3, r31
/* 8011B2F8 00118258  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8011B2FC 0011825C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8011B300 00118260  38 21 00 10 */	addi r1, r1, 0x10
/* 8011B304 00118264  7C 08 03 A6 */	mtlr r0
/* 8011B308 00118268  4E 80 00 20 */	blr 

.global initialise__13GenObjectTekiFv
initialise__13GenObjectTekiFv:
/* 8011B30C 0011826C  80 ED 30 74 */	lwz r7, factory__16GenObjectFactory@sda21(r13)
/* 8011B310 00118270  80 A7 00 00 */	lwz r5, 0(r7)
/* 8011B314 00118274  80 07 00 04 */	lwz r0, 4(r7)
/* 8011B318 00118278  7C 05 00 00 */	cmpw r5, r0
/* 8011B31C 0011827C  4C 80 00 20 */	bgelr 
/* 8011B320 00118280  3C 80 74 65 */	lis r4, 0x74656B69@ha
/* 8011B324 00118284  80 67 00 08 */	lwz r3, 8(r7)
/* 8011B328 00118288  38 84 6B 69 */	addi r4, r4, 0x74656B69@l
/* 8011B32C 0011828C  54 A0 20 36 */	slwi r0, r5, 4
/* 8011B330 00118290  7C 83 01 2E */	stwx r4, r3, r0
/* 8011B334 00118294  3C 80 80 12 */	lis r4, makeObjectTeki__Fv@ha
/* 8011B338 00118298  3C 60 80 2C */	lis r3, lbl_802C4094@ha
/* 8011B33C 0011829C  80 07 00 00 */	lwz r0, 0(r7)
/* 8011B340 001182A0  38 C4 B2 CC */	addi r6, r4, makeObjectTeki__Fv@l
/* 8011B344 001182A4  80 87 00 08 */	lwz r4, 8(r7)
/* 8011B348 001182A8  38 A3 40 94 */	addi r5, r3, lbl_802C4094@l
/* 8011B34C 001182AC  54 00 20 36 */	slwi r0, r0, 4
/* 8011B350 001182B0  7C 64 02 14 */	add r3, r4, r0
/* 8011B354 001182B4  90 C3 00 04 */	stw r6, 4(r3)
/* 8011B358 001182B8  38 80 00 0A */	li r4, 0xa
/* 8011B35C 001182BC  80 07 00 00 */	lwz r0, 0(r7)
/* 8011B360 001182C0  80 67 00 08 */	lwz r3, 8(r7)
/* 8011B364 001182C4  54 00 20 36 */	slwi r0, r0, 4
/* 8011B368 001182C8  7C 63 02 14 */	add r3, r3, r0
/* 8011B36C 001182CC  90 A3 00 08 */	stw r5, 8(r3)
/* 8011B370 001182D0  80 07 00 00 */	lwz r0, 0(r7)
/* 8011B374 001182D4  80 67 00 08 */	lwz r3, 8(r7)
/* 8011B378 001182D8  54 00 20 36 */	slwi r0, r0, 4
/* 8011B37C 001182DC  7C 63 02 14 */	add r3, r3, r0
/* 8011B380 001182E0  90 83 00 0C */	stw r4, 0xc(r3)
/* 8011B384 001182E4  80 67 00 00 */	lwz r3, 0(r7)
/* 8011B388 001182E8  38 03 00 01 */	addi r0, r3, 1
/* 8011B38C 001182EC  90 07 00 00 */	stw r0, 0(r7)
/* 8011B390 001182F0  4E 80 00 20 */	blr 

.global __ct__13GenObjectTekiFv
__ct__13GenObjectTekiFv:
/* 8011B394 001182F4  7C 08 02 A6 */	mflr r0
/* 8011B398 001182F8  3C 80 80 2C */	lis r4, lbl_802C40AC@ha
/* 8011B39C 001182FC  90 01 00 04 */	stw r0, 4(r1)
/* 8011B3A0 00118300  3C A0 80 2C */	lis r5, lbl_802C40A0@ha
/* 8011B3A4 00118304  38 C4 40 AC */	addi r6, r4, lbl_802C40AC@l
/* 8011B3A8 00118308  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011B3AC 0011830C  3C 80 74 65 */	lis r4, 0x74656B69@ha
/* 8011B3B0 00118310  38 A5 40 A0 */	addi r5, r5, lbl_802C40A0@l
/* 8011B3B4 00118314  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011B3B8 00118318  38 84 6B 69 */	addi r4, r4, 0x74656B69@l
/* 8011B3BC 0011831C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8011B3C0 00118320  3B C3 00 00 */	addi r30, r3, 0
/* 8011B3C4 00118324  4B FB F8 F1 */	bl __ct__7GenBaseFUlPcPc
/* 8011B3C8 00118328  3C 60 80 2C */	lis r3, __vt__9GenObject@ha
/* 8011B3CC 0011832C  38 03 AB 70 */	addi r0, r3, __vt__9GenObject@l
/* 8011B3D0 00118330  3C 60 80 2C */	lis r3, __vt__13GenObjectTeki@ha
/* 8011B3D4 00118334  90 1E 00 04 */	stw r0, 4(r30)
/* 8011B3D8 00118338  38 03 41 1C */	addi r0, r3, __vt__13GenObjectTeki@l
/* 8011B3DC 0011833C  90 1E 00 04 */	stw r0, 4(r30)
/* 8011B3E0 00118340  38 00 00 00 */	li r0, 0
/* 8011B3E4 00118344  38 60 00 38 */	li r3, 0x38
/* 8011B3E8 00118348  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 8011B3EC 0011834C  4B F2 BC 19 */	bl alloc__6SystemFUl
/* 8011B3F0 00118350  3B E3 00 00 */	addi r31, r3, 0
/* 8011B3F4 00118354  7F E3 FB 79 */	or. r3, r31, r31
/* 8011B3F8 00118358  41 82 00 08 */	beq lbl_8011B400
/* 8011B3FC 0011835C  48 03 16 65 */	bl __ct__15TekiPersonalityFv
lbl_8011B400:
/* 8011B400 00118360  93 FE 00 18 */	stw r31, 0x18(r30)
/* 8011B404 00118364  7F C3 F3 78 */	mr r3, r30
/* 8011B408 00118368  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011B40C 0011836C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011B410 00118370  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8011B414 00118374  38 21 00 18 */	addi r1, r1, 0x18
/* 8011B418 00118378  7C 08 03 A6 */	mtlr r0
/* 8011B41C 0011837C  4E 80 00 20 */	blr 

.global doRead__13GenObjectTekiFR18RandomAccessStream
doRead__13GenObjectTekiFR18RandomAccessStream:
/* 8011B420 00118380  7C 08 02 A6 */	mflr r0
/* 8011B424 00118384  90 01 00 04 */	stw r0, 4(r1)
/* 8011B428 00118388  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011B42C 0011838C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011B430 00118390  3B E4 00 00 */	addi r31, r4, 0
/* 8011B434 00118394  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8011B438 00118398  7C 7E 1B 78 */	mr r30, r3
/* 8011B43C 0011839C  80 03 00 0C */	lwz r0, 0xc(r3)
/* 8011B440 001183A0  28 00 00 08 */	cmplwi r0, 8
/* 8011B444 001183A4  41 81 00 20 */	bgt lbl_8011B464
/* 8011B448 001183A8  7F E3 FB 78 */	mr r3, r31
/* 8011B44C 001183AC  81 9F 00 04 */	lwz r12, 4(r31)
/* 8011B450 001183B0  81 8C 00 08 */	lwz r12, 8(r12)
/* 8011B454 001183B4  7D 88 03 A6 */	mtlr r12
/* 8011B458 001183B8  4E 80 00 21 */	blrl 
/* 8011B45C 001183BC  90 7E 00 1C */	stw r3, 0x1c(r30)
/* 8011B460 001183C0  48 00 00 20 */	b lbl_8011B480
lbl_8011B464:
/* 8011B464 001183C4  7F E3 FB 78 */	mr r3, r31
/* 8011B468 001183C8  81 9F 00 04 */	lwz r12, 4(r31)
/* 8011B46C 001183CC  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8011B470 001183D0  7D 88 03 A6 */	mtlr r12
/* 8011B474 001183D4  4E 80 00 21 */	blrl 
/* 8011B478 001183D8  54 60 06 3E */	clrlwi r0, r3, 0x18
/* 8011B47C 001183DC  90 1E 00 1C */	stw r0, 0x1c(r30)
lbl_8011B480:
/* 8011B480 001183E0  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 8011B484 001183E4  7F E4 FB 78 */	mr r4, r31
/* 8011B488 001183E8  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 8011B48C 001183EC  81 83 00 00 */	lwz r12, 0(r3)
/* 8011B490 001183F0  81 8C 00 08 */	lwz r12, 8(r12)
/* 8011B494 001183F4  7D 88 03 A6 */	mtlr r12
/* 8011B498 001183F8  4E 80 00 21 */	blrl 
/* 8011B49C 001183FC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011B4A0 00118400  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011B4A4 00118404  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8011B4A8 00118408  38 21 00 18 */	addi r1, r1, 0x18
/* 8011B4AC 0011840C  7C 08 03 A6 */	mtlr r0
/* 8011B4B0 00118410  4E 80 00 20 */	blr 

.global doWrite__13GenObjectTekiFR18RandomAccessStream
doWrite__13GenObjectTekiFR18RandomAccessStream:
/* 8011B4B4 00118414  7C 08 02 A6 */	mflr r0
/* 8011B4B8 00118418  90 01 00 04 */	stw r0, 4(r1)
/* 8011B4BC 0011841C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011B4C0 00118420  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011B4C4 00118424  3B E4 00 00 */	addi r31, r4, 0
/* 8011B4C8 00118428  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8011B4CC 0011842C  3B C3 00 00 */	addi r30, r3, 0
/* 8011B4D0 00118430  38 7F 00 00 */	addi r3, r31, 0
/* 8011B4D4 00118434  81 9F 00 04 */	lwz r12, 4(r31)
/* 8011B4D8 00118438  80 1E 00 1C */	lwz r0, 0x1c(r30)
/* 8011B4DC 0011843C  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 8011B4E0 00118440  7C 04 07 74 */	extsb r4, r0
/* 8011B4E4 00118444  7D 88 03 A6 */	mtlr r12
/* 8011B4E8 00118448  4E 80 00 21 */	blrl 
/* 8011B4EC 0011844C  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 8011B4F0 00118450  7F E4 FB 78 */	mr r4, r31
/* 8011B4F4 00118454  81 83 00 00 */	lwz r12, 0(r3)
/* 8011B4F8 00118458  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8011B4FC 0011845C  7D 88 03 A6 */	mtlr r12
/* 8011B500 00118460  4E 80 00 21 */	blrl 
/* 8011B504 00118464  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011B508 00118468  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011B50C 0011846C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8011B510 00118470  38 21 00 18 */	addi r1, r1, 0x18
/* 8011B514 00118474  7C 08 03 A6 */	mtlr r0
/* 8011B518 00118478  4E 80 00 20 */	blr 

.global updateUseList__13GenObjectTekiFP9Generatori
updateUseList__13GenObjectTekiFP9Generatori:
/* 8011B51C 0011847C  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 8011B520 00118480  2C 04 00 00 */	cmpwi r4, 0
/* 8011B524 00118484  4D 80 00 20 */	bltlr 
/* 8011B528 00118488  2C 04 00 23 */	cmpwi r4, 0x23
/* 8011B52C 0011848C  41 80 00 08 */	blt lbl_8011B534
/* 8011B530 00118490  4E 80 00 20 */	blr 
lbl_8011B534:
/* 8011B534 00118494  80 0D 31 60 */	lwz r0, tekiMgr@sda21(r13)
/* 8011B538 00118498  38 A0 00 01 */	li r5, 1
/* 8011B53C 0011849C  7C 80 22 14 */	add r4, r0, r4
/* 8011B540 001184A0  98 A4 01 64 */	stb r5, 0x164(r4)
/* 8011B544 001184A4  80 03 00 1C */	lwz r0, 0x1c(r3)
/* 8011B548 001184A8  80 8D 31 60 */	lwz r4, tekiMgr@sda21(r13)
/* 8011B54C 001184AC  54 00 10 3A */	slwi r0, r0, 2
/* 8011B550 001184B0  7C 64 02 14 */	add r3, r4, r0
/* 8011B554 001184B4  80 63 00 4C */	lwz r3, 0x4c(r3)
/* 8011B558 001184B8  28 03 00 00 */	cmplwi r3, 0
/* 8011B55C 001184BC  4D 82 00 20 */	beqlr 
/* 8011B560 001184C0  80 63 00 84 */	lwz r3, 0x84(r3)
/* 8011B564 001184C4  80 63 00 00 */	lwz r3, 0(r3)
/* 8011B568 001184C8  80 63 00 00 */	lwz r3, 0(r3)
/* 8011B56C 001184CC  80 03 00 0C */	lwz r0, 0xc(r3)
/* 8011B570 001184D0  2C 00 00 00 */	cmpwi r0, 0
/* 8011B574 001184D4  4D 80 00 20 */	bltlr 
/* 8011B578 001184D8  2C 00 00 23 */	cmpwi r0, 0x23
/* 8011B57C 001184DC  4C 80 00 20 */	bgelr 
/* 8011B580 001184E0  7C 64 02 14 */	add r3, r4, r0
/* 8011B584 001184E4  98 A3 01 64 */	stb r5, 0x164(r3)
/* 8011B588 001184E8  4E 80 00 20 */	blr 

.global birth__13GenObjectTekiFR9BirthInfo
birth__13GenObjectTekiFR9BirthInfo:
/* 8011B58C 001184EC  7C 08 02 A6 */	mflr r0
/* 8011B590 001184F0  90 01 00 04 */	stw r0, 4(r1)
/* 8011B594 001184F4  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 8011B598 001184F8  93 E1 00 44 */	stw r31, 0x44(r1)
/* 8011B59C 001184FC  93 C1 00 40 */	stw r30, 0x40(r1)
/* 8011B5A0 00118500  7C 9E 23 78 */	mr r30, r4
/* 8011B5A4 00118504  93 A1 00 3C */	stw r29, 0x3c(r1)
/* 8011B5A8 00118508  7C 7D 1B 78 */	mr r29, r3
/* 8011B5AC 0011850C  80 6D 31 60 */	lwz r3, tekiMgr@sda21(r13)
/* 8011B5B0 00118510  80 9D 00 1C */	lwz r4, 0x1c(r29)
/* 8011B5B4 00118514  48 02 F5 99 */	bl newTeki__7TekiMgrFi
/* 8011B5B8 00118518  7C 7F 1B 79 */	or. r31, r3, r3
/* 8011B5BC 0011851C  40 82 00 0C */	bne lbl_8011B5C8
/* 8011B5C0 00118520  38 60 00 00 */	li r3, 0
/* 8011B5C4 00118524  48 00 00 CC */	b lbl_8011B690
lbl_8011B5C8:
/* 8011B5C8 00118528  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 8011B5CC 0011852C  C0 1E 00 00 */	lfs f0, 0(r30)
/* 8011B5D0 00118530  D4 03 00 04 */	stfsu f0, 4(r3)
/* 8011B5D4 00118534  C0 1E 00 04 */	lfs f0, 4(r30)
/* 8011B5D8 00118538  D0 03 00 04 */	stfs f0, 4(r3)
/* 8011B5DC 0011853C  C0 1E 00 08 */	lfs f0, 8(r30)
/* 8011B5E0 00118540  D0 03 00 08 */	stfs f0, 8(r3)
/* 8011B5E4 00118544  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 8011B5E8 00118548  C0 1E 00 18 */	lfs f0, 0x18(r30)
/* 8011B5EC 0011854C  D4 03 00 10 */	stfsu f0, 0x10(r3)
/* 8011B5F0 00118550  C0 1E 00 1C */	lfs f0, 0x1c(r30)
/* 8011B5F4 00118554  D0 03 00 04 */	stfs f0, 4(r3)
/* 8011B5F8 00118558  C0 1E 00 20 */	lfs f0, 0x20(r30)
/* 8011B5FC 0011855C  D0 03 00 08 */	stfs f0, 8(r3)
/* 8011B600 00118560  C0 1E 00 10 */	lfs f0, 0x10(r30)
/* 8011B604 00118564  80 7D 00 18 */	lwz r3, 0x18(r29)
/* 8011B608 00118568  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8011B60C 0011856C  80 7F 02 C8 */	lwz r3, 0x2c8(r31)
/* 8011B610 00118570  80 9D 00 18 */	lwz r4, 0x18(r29)
/* 8011B614 00118574  48 03 17 71 */	bl input__15TekiPersonalityFR15TekiPersonality
/* 8011B618 00118578  7F E3 FB 78 */	mr r3, r31
/* 8011B61C 0011857C  81 9F 00 00 */	lwz r12, 0(r31)
/* 8011B620 00118580  81 8C 01 70 */	lwz r12, 0x170(r12)
/* 8011B624 00118584  7D 88 03 A6 */	mtlr r12
/* 8011B628 00118588  4E 80 00 21 */	blrl 
/* 8011B62C 0011858C  7F E3 FB 78 */	mr r3, r31
/* 8011B630 00118590  81 9F 00 00 */	lwz r12, 0(r31)
/* 8011B634 00118594  38 80 00 00 */	li r4, 0
/* 8011B638 00118598  81 8C 00 34 */	lwz r12, 0x34(r12)
/* 8011B63C 0011859C  7D 88 03 A6 */	mtlr r12
/* 8011B640 001185A0  4E 80 00 21 */	blrl 
/* 8011B644 001185A4  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 8011B648 001185A8  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 8011B64C 001185AC  90 7F 00 88 */	stw r3, 0x88(r31)
/* 8011B650 001185B0  90 1F 00 8C */	stw r0, 0x8c(r31)
/* 8011B654 001185B4  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 8011B658 001185B8  90 1F 00 90 */	stw r0, 0x90(r31)
/* 8011B65C 001185BC  80 7E 00 24 */	lwz r3, 0x24(r30)
/* 8011B660 001185C0  80 63 00 28 */	lwz r3, 0x28(r3)
/* 8011B664 001185C4  80 03 00 34 */	lwz r0, 0x34(r3)
/* 8011B668 001185C8  2C 00 00 00 */	cmpwi r0, 0
/* 8011B66C 001185CC  41 82 00 10 */	beq lbl_8011B67C
/* 8011B670 001185D0  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 8011B674 001185D4  64 00 00 01 */	oris r0, r0, 1
/* 8011B678 001185D8  90 1F 00 C8 */	stw r0, 0xc8(r31)
lbl_8011B67C:
/* 8011B67C 001185DC  80 9E 00 24 */	lwz r4, 0x24(r30)
/* 8011B680 001185E0  7F E3 FB 78 */	mr r3, r31
/* 8011B684 001185E4  80 84 00 28 */	lwz r4, 0x28(r4)
/* 8011B688 001185E8  80 04 00 24 */	lwz r0, 0x24(r4)
/* 8011B68C 001185EC  90 1F 00 34 */	stw r0, 0x34(r31)
lbl_8011B690:
/* 8011B690 001185F0  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 8011B694 001185F4  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 8011B698 001185F8  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 8011B69C 001185FC  83 A1 00 3C */	lwz r29, 0x3c(r1)
/* 8011B6A0 00118600  38 21 00 48 */	addi r1, r1, 0x48
/* 8011B6A4 00118604  7C 08 03 A6 */	mtlr r0
/* 8011B6A8 00118608  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C4088:
	.asciz "genteki.cpp"
.balign 4
lbl_802C4094:
	.4byte 0x934782F0
	.4byte 0x94AD90B6
	.4byte 0x00000000
.balign 4
lbl_802C40A0:
	.asciz "object type"
.balign 4
lbl_802C40AC:
	.4byte 0x934782F0
	.4byte 0x90B682DE
	.4byte 0x00000000
.balign 4
lbl_802C40B8:
	.asciz "GenObjectTeki"
.balign 4
lbl_802C40C8:
	.asciz "Parameters"
.balign 4
lbl_802C40D4:
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
lbl_802C40E0:
	.asciz "GenObject"
.balign 4
lbl_802C40EC:
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte __RTTI__7GenBase
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802C4100:
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte __RTTI__7GenBase
	.4byte 0x00000000
	.4byte __RTTI__9GenObject
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__13GenObjectTeki
__vt__13GenObjectTeki:
	.4byte __RTTI__13GenObjectTeki
	.4byte 0
	.4byte doWrite__13GenObjectTekiFR18RandomAccessStream
	.4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
	.4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
	.4byte doRead__13GenObjectTekiFR18RandomAccessStream
	.4byte update__7GenBaseFv
	.4byte render__7GenBaseFR8Graphics
	.4byte getLatestVersion__9GenObjectFv
	.4byte updateUseList__13GenObjectTekiFP9Generatori
	.4byte init__9GenObjectFP9Generator
	.4byte update__9GenObjectFP9Generator
	.4byte render__9GenObjectFR8GraphicsP9Generator
	.4byte birth__13GenObjectTekiFR9BirthInfo

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__10Parameters:
	.4byte lbl_802C40C8
	.4byte 0
.balign 4
lbl_803E2FA0:
	.asciz "GenBase"
.balign 4
__RTTI__7GenBase:
	.4byte lbl_803E2FA0
	.4byte lbl_802C40D4
__RTTI__9GenObject:
	.4byte lbl_802C40E0
	.4byte lbl_802C40EC
__RTTI__13GenObjectTeki:
	.4byte lbl_802C40B8
	.4byte lbl_802C4100
