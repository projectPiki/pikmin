.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800D32D8 000D0238  93 C1 00 60 */	stw r30, 0x60(r1)
/* 800D32DC 000D023C  3B C3 00 00 */	addi r30, r3, 0
/* 800D32E0 000D0240  93 A1 00 5C */	stw r29, 0x5c(r1)
/* 800D32E4 000D0244  93 81 00 58 */	stw r28, 0x58(r1)
/* 800D32E8 000D0248  80 A5 00 04 */	lwz r5, 4(r5)
/* 800D32EC 000D024C  80 05 00 00 */	lwz r0, 0(r5)
/* 800D32F0 000D0250  2C 00 00 00 */	cmpwi r0, 0
/* 800D32F4 000D0254  41 82 00 08 */	beq lbl_800D32FC
/* 800D32F8 000D0258  48 00 02 30 */	b lbl_800D3528
lbl_800D32FC:
/* 800D32FC 000D025C  A0 1E 00 10 */	lhz r0, 0x10(r30)
/* 800D3300 000D0260  28 00 00 00 */	cmplwi r0, 0
/* 800D3304 000D0264  40 82 00 50 */	bne lbl_800D3354
/* 800D3308 000D0268  28 1F 00 00 */	cmplwi r31, 0
/* 800D330C 000D026C  3B 9F 00 00 */	addi r28, r31, 0
/* 800D3310 000D0270  41 82 00 08 */	beq lbl_800D3318
/* 800D3314 000D0274  3B 9C 02 B8 */	addi r28, r28, 0x2b8
lbl_800D3318:
/* 800D3318 000D0278  38 61 00 3C */	addi r3, r1, 0x3c
/* 800D331C 000D027C  38 80 00 1E */	li r4, 0x1e
/* 800D3320 000D0280  48 04 BC 39 */	bl __ct__14PaniMotionInfoFi
/* 800D3324 000D0284  3B A3 00 00 */	addi r29, r3, 0
/* 800D3328 000D0288  38 BC 00 00 */	addi r5, r28, 0
/* 800D332C 000D028C  38 61 00 44 */	addi r3, r1, 0x44
/* 800D3330 000D0290  38 80 00 1E */	li r4, 0x1e
/* 800D3334 000D0294  48 04 BC 59 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800D3338 000D0298  38 83 00 00 */	addi r4, r3, 0
/* 800D333C 000D029C  38 7F 00 00 */	addi r3, r31, 0
/* 800D3340 000D02A0  38 BD 00 00 */	addi r5, r29, 0
/* 800D3344 000D02A4  4B FF 76 95 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800D3348 000D02A8  38 00 00 01 */	li r0, 1
/* 800D334C 000D02AC  B0 1E 00 10 */	sth r0, 0x10(r30)
/* 800D3350 000D02B0  48 00 01 D8 */	b lbl_800D3528
lbl_800D3354:
/* 800D3354 000D02B4  28 00 00 01 */	cmplwi r0, 1
/* 800D3358 000D02B8  40 82 00 8C */	bne lbl_800D33E4
/* 800D335C 000D02BC  38 00 00 02 */	li r0, 2
/* 800D3360 000D02C0  B0 1E 00 10 */	sth r0, 0x10(r30)
/* 800D3364 000D02C4  80 9F 02 24 */	lwz r4, 0x224(r31)
/* 800D3368 000D02C8  C3 C4 03 28 */	lfs f30, 0x328(r4)
/* 800D336C 000D02CC  C3 E4 03 38 */	lfs f31, 0x338(r4)
/* 800D3370 000D02D0  48 14 4D 01 */	bl rand
/* 800D3374 000D02D4  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800D3378 000D02D8  C8 82 97 28 */	lfd f4, "@2634"@sda21(r2)
/* 800D337C 000D02DC  90 01 00 54 */	stw r0, 0x54(r1)
/* 800D3380 000D02E0  3C 00 43 30 */	lis r0, 0x4330
/* 800D3384 000D02E4  C0 42 97 1C */	lfs f2, lbl_803E991C@sda21(r2)
/* 800D3388 000D02E8  EC 1E F8 28 */	fsubs f0, f30, f31
/* 800D338C 000D02EC  90 01 00 50 */	stw r0, 0x50(r1)
/* 800D3390 000D02F0  C0 22 97 18 */	lfs f1, lbl_803E9918@sda21(r2)
/* 800D3394 000D02F4  C8 61 00 50 */	lfd f3, 0x50(r1)
/* 800D3398 000D02F8  EC 63 20 28 */	fsubs f3, f3, f4
/* 800D339C 000D02FC  EC 43 10 24 */	fdivs f2, f3, f2
/* 800D33A0 000D0300  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800D33A4 000D0304  EC 00 00 72 */	fmuls f0, f0, f1
/* 800D33A8 000D0308  EC 1F 00 2A */	fadds f0, f31, f0
/* 800D33AC 000D030C  D0 1E 00 14 */	stfs f0, 0x14(r30)
/* 800D33B0 000D0310  C0 3F 00 58 */	lfs f1, 0x58(r31)
/* 800D33B4 000D0314  C0 02 97 30 */	lfs f0, lbl_803E9930@sda21(r2)
/* 800D33B8 000D0318  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800D33BC 000D031C  4C 40 13 82 */	cror 2, 0, 2
/* 800D33C0 000D0320  40 82 01 68 */	bne lbl_800D3528
/* 800D33C4 000D0324  7F C3 F3 78 */	mr r3, r30
/* 800D33C8 000D0328  81 9E 00 00 */	lwz r12, 0(r30)
/* 800D33CC 000D032C  38 9F 00 00 */	addi r4, r31, 0
/* 800D33D0 000D0330  38 A0 00 07 */	li r5, 7
/* 800D33D4 000D0334  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 800D33D8 000D0338  7D 88 03 A6 */	mtlr r12
/* 800D33DC 000D033C  4E 80 00 21 */	blrl 
/* 800D33E0 000D0340  48 00 01 48 */	b lbl_800D3528
lbl_800D33E4:
/* 800D33E4 000D0344  48 14 4C 8D */	bl rand
/* 800D33E8 000D0348  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800D33EC 000D034C  C8 82 97 28 */	lfd f4, "@2634"@sda21(r2)
/* 800D33F0 000D0350  90 01 00 54 */	stw r0, 0x54(r1)
/* 800D33F4 000D0354  3C 00 43 30 */	lis r0, 0x4330
/* 800D33F8 000D0358  C0 42 97 1C */	lfs f2, lbl_803E991C@sda21(r2)
/* 800D33FC 000D035C  90 01 00 50 */	stw r0, 0x50(r1)
/* 800D3400 000D0360  C0 22 97 18 */	lfs f1, lbl_803E9918@sda21(r2)
/* 800D3404 000D0364  C8 61 00 50 */	lfd f3, 0x50(r1)
/* 800D3408 000D0368  C0 02 97 90 */	lfs f0, lbl_803E9990@sda21(r2)
/* 800D340C 000D036C  EC 63 20 28 */	fsubs f3, f3, f4
/* 800D3410 000D0370  EC 43 10 24 */	fdivs f2, f3, f2
/* 800D3414 000D0374  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800D3418 000D0378  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800D341C 000D037C  40 80 00 98 */	bge lbl_800D34B4
/* 800D3420 000D0380  80 7F 05 20 */	lwz r3, 0x520(r31)
/* 800D3424 000D0384  2C 03 00 01 */	cmpwi r3, 1
/* 800D3428 000D0388  41 80 00 8C */	blt lbl_800D34B4
/* 800D342C 000D038C  38 03 FF FF */	addi r0, r3, -1
/* 800D3430 000D0390  90 1F 05 20 */	stw r0, 0x520(r31)
/* 800D3434 000D0394  7F E3 FB 78 */	mr r3, r31
/* 800D3438 000D0398  81 9F 00 00 */	lwz r12, 0(r31)
/* 800D343C 000D039C  80 9F 05 20 */	lwz r4, 0x520(r31)
/* 800D3440 000D03A0  81 8C 01 30 */	lwz r12, 0x130(r12)
/* 800D3444 000D03A4  7D 88 03 A6 */	mtlr r12
/* 800D3448 000D03A8  4E 80 00 21 */	blrl 
/* 800D344C 000D03AC  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800D3450 000D03B0  38 BF 04 64 */	addi r5, r31, 0x464
/* 800D3454 000D03B4  38 80 00 1B */	li r4, 0x1b
/* 800D3458 000D03B8  38 C0 00 00 */	li r6, 0
/* 800D345C 000D03BC  38 E0 00 00 */	li r7, 0
/* 800D3460 000D03C0  48 0C 96 D9 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 800D3464 000D03C4  28 03 00 00 */	cmplwi r3, 0
/* 800D3468 000D03C8  41 82 00 34 */	beq lbl_800D349C
/* 800D346C 000D03CC  C0 0D C1 14 */	lfs f0, lbl_803E0E34@sda21(r13)
/* 800D3470 000D03D0  C0 2D C1 18 */	lfs f1, lbl_803E0E38@sda21(r13)
/* 800D3474 000D03D4  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 800D3478 000D03D8  C0 0D C1 1C */	lfs f0, lbl_803E0E3C@sda21(r13)
/* 800D347C 000D03DC  D0 21 00 34 */	stfs f1, 0x34(r1)
/* 800D3480 000D03E0  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 800D3484 000D03E4  80 81 00 30 */	lwz r4, 0x30(r1)
/* 800D3488 000D03E8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800D348C 000D03EC  90 83 01 DC */	stw r4, 0x1dc(r3)
/* 800D3490 000D03F0  90 03 01 E0 */	stw r0, 0x1e0(r3)
/* 800D3494 000D03F4  80 01 00 38 */	lwz r0, 0x38(r1)
/* 800D3498 000D03F8  90 03 01 E4 */	stw r0, 0x1e4(r3)
lbl_800D349C:
/* 800D349C 000D03FC  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800D34A0 000D0400  38 BF 04 64 */	addi r5, r31, 0x464
/* 800D34A4 000D0404  38 80 00 1C */	li r4, 0x1c
/* 800D34A8 000D0408  38 C0 00 00 */	li r6, 0
/* 800D34AC 000D040C  38 E0 00 00 */	li r7, 0
/* 800D34B0 000D0410  48 0C 96 89 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
lbl_800D34B4:
/* 800D34B4 000D0414  7F E3 FB 78 */	mr r3, r31
/* 800D34B8 000D0418  81 9F 00 00 */	lwz r12, 0(r31)
/* 800D34BC 000D041C  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800D34C0 000D0420  7D 88 03 A6 */	mtlr r12
/* 800D34C4 000D0424  4E 80 00 21 */	blrl 
/* 800D34C8 000D0428  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800D34CC 000D042C  41 82 00 40 */	beq lbl_800D350C
/* 800D34D0 000D0430  80 7F 04 F8 */	lwz r3, 0x4f8(r31)
/* 800D34D4 000D0434  38 80 00 00 */	li r4, 0
/* 800D34D8 000D0438  4B FF 1E 6D */	bl abandon__9TopActionFPQ23zen17particleGenerator
/* 800D34DC 000D043C  80 BF 05 04 */	lwz r5, 0x504(r31)
/* 800D34E0 000D0440  38 7F 00 00 */	addi r3, r31, 0
/* 800D34E4 000D0444  38 80 00 01 */	li r4, 1
/* 800D34E8 000D0448  4B FF 9C E5 */	bl changeMode__4PikiFiP4Navi
/* 800D34EC 000D044C  7F C3 F3 78 */	mr r3, r30
/* 800D34F0 000D0450  81 9E 00 00 */	lwz r12, 0(r30)
/* 800D34F4 000D0454  38 9F 00 00 */	addi r4, r31, 0
/* 800D34F8 000D0458  38 A0 00 1D */	li r5, 0x1d
/* 800D34FC 000D045C  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 800D3500 000D0460  7D 88 03 A6 */	mtlr r12
/* 800D3504 000D0464  4E 80 00 21 */	blrl 
/* 800D3508 000D0468  48 00 00 20 */	b lbl_800D3528
lbl_800D350C:
/* 800D350C 000D046C  7F C3 F3 78 */	mr r3, r30
/* 800D3510 000D0470  81 9E 00 00 */	lwz r12, 0(r30)
/* 800D3514 000D0474  38 9F 00 00 */	addi r4, r31, 0
/* 800D3518 000D0478  38 A0 00 00 */	li r5, 0
/* 800D351C 000D047C  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 800D3520 000D0480  7D 88 03 A6 */	mtlr r12
/* 800D3524 000D0484  4E 80 00 21 */	blrl 
lbl_800D3528:
/* 800D3528 000D0488  80 01 00 7C */	lwz r0, 0x7c(r1)
/* 800D352C 000D048C  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 800D3530 000D0490  CB C1 00 68 */	lfd f30, 0x68(r1)
/* 800D3534 000D0494  83 E1 00 64 */	lwz r31, 0x64(r1)
/* 800D3538 000D0498  83 C1 00 60 */	lwz r30, 0x60(r1)
/* 800D353C 000D049C  83 A1 00 5C */	lwz r29, 0x5c(r1)
/* 800D3540 000D04A0  83 81 00 58 */	lwz r28, 0x58(r1)
/* 800D3544 000D04A4  38 21 00 78 */	addi r1, r1, 0x78
/* 800D3548 000D04A8  7C 08 03 A6 */	mtlr r0
/* 800D354C 000D04AC  4E 80 00 20 */	blr 

.global cleanup__14PikiFlickStateFP4Piki
cleanup__14PikiFlickStateFP4Piki:
/* 800D3550 000D04B0  7C 08 02 A6 */	mflr r0
/* 800D3554 000D04B4  90 01 00 04 */	stw r0, 4(r1)
/* 800D3558 000D04B8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800D355C 000D04BC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800D3560 000D04C0  3B E4 00 00 */	addi r31, r4, 0
/* 800D3564 000D04C4  38 7F 00 00 */	addi r3, r31, 0
/* 800D3568 000D04C8  81 9F 00 00 */	lwz r12, 0(r31)
/* 800D356C 000D04CC  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 800D3570 000D04D0  7D 88 03 A6 */	mtlr r12
/* 800D3574 000D04D4  4E 80 00 21 */	blrl 
/* 800D3578 000D04D8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800D357C 000D04DC  40 82 00 B8 */	bne lbl_800D3634
/* 800D3580 000D04E0  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 800D3584 000D04E4  54 00 04 21 */	rlwinm. r0, r0, 0, 0x10, 0x10
/* 800D3588 000D04E8  40 82 00 AC */	bne lbl_800D3634
/* 800D358C 000D04EC  7F E3 FB 78 */	mr r3, r31
/* 800D3590 000D04F0  81 9F 00 00 */	lwz r12, 0(r31)
/* 800D3594 000D04F4  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 800D3598 000D04F8  7D 88 03 A6 */	mtlr r12
/* 800D359C 000D04FC  4E 80 00 21 */	blrl 
/* 800D35A0 000D0500  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800D35A4 000D0504  41 82 00 34 */	beq lbl_800D35D8
/* 800D35A8 000D0508  88 1F 04 A0 */	lbz r0, 0x4a0(r31)
/* 800D35AC 000D050C  28 00 00 00 */	cmplwi r0, 0
/* 800D35B0 000D0510  41 82 00 28 */	beq lbl_800D35D8
/* 800D35B4 000D0514  80 BF 05 04 */	lwz r5, 0x504(r31)
/* 800D35B8 000D0518  38 7F 00 00 */	addi r3, r31, 0
/* 800D35BC 000D051C  38 80 00 01 */	li r4, 1
/* 800D35C0 000D0520  4B FF 9C 0D */	bl changeMode__4PikiFiP4Navi
/* 800D35C4 000D0524  7F E3 FB 78 */	mr r3, r31
/* 800D35C8 000D0528  4B FB D2 B1 */	bl endStickObject__8CreatureFv
/* 800D35CC 000D052C  38 00 00 00 */	li r0, 0
/* 800D35D0 000D0530  98 1F 04 A0 */	stb r0, 0x4a0(r31)
/* 800D35D4 000D0534  48 00 00 60 */	b lbl_800D3634
lbl_800D35D8:
/* 800D35D8 000D0538  7F E3 FB 78 */	mr r3, r31
/* 800D35DC 000D053C  81 9F 00 00 */	lwz r12, 0(r31)
/* 800D35E0 000D0540  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 800D35E4 000D0544  7D 88 03 A6 */	mtlr r12
/* 800D35E8 000D0548  4E 80 00 21 */	blrl 
/* 800D35EC 000D054C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800D35F0 000D0550  41 82 00 38 */	beq lbl_800D3628
/* 800D35F4 000D0554  80 7F 04 F8 */	lwz r3, 0x4f8(r31)
/* 800D35F8 000D0558  81 83 00 00 */	lwz r12, 0(r3)
/* 800D35FC 000D055C  81 8C 00 5C */	lwz r12, 0x5c(r12)
/* 800D3600 000D0560  7D 88 03 A6 */	mtlr r12
/* 800D3604 000D0564  4E 80 00 21 */	blrl 
/* 800D3608 000D0568  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800D360C 000D056C  41 82 00 1C */	beq lbl_800D3628
/* 800D3610 000D0570  80 7F 04 F8 */	lwz r3, 0x4f8(r31)
/* 800D3614 000D0574  81 83 00 00 */	lwz r12, 0(r3)
/* 800D3618 000D0578  81 8C 00 58 */	lwz r12, 0x58(r12)
/* 800D361C 000D057C  7D 88 03 A6 */	mtlr r12
/* 800D3620 000D0580  4E 80 00 21 */	blrl 
/* 800D3624 000D0584  48 00 00 10 */	b lbl_800D3634
lbl_800D3628:
/* 800D3628 000D0588  80 7F 04 F8 */	lwz r3, 0x4f8(r31)
/* 800D362C 000D058C  38 80 00 00 */	li r4, 0
/* 800D3630 000D0590  4B FF 1D 15 */	bl abandon__9TopActionFPQ23zen17particleGenerator
lbl_800D3634:
/* 800D3634 000D0594  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800D3638 000D0598  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800D363C 000D059C  38 21 00 20 */	addi r1, r1, 0x20
/* 800D3640 000D05A0  7C 08 03 A6 */	mtlr r0
/* 800D3644 000D05A4  4E 80 00 20 */	blr 

.global __ct__14PikiFlownStateFv
__ct__14PikiFlownStateFv:
/* 800D3648 000D05A8  3C 80 80 2C */	lis r4, "__vt__15Receiver<4Piki>"@ha
/* 800D364C 000D05AC  38 04 81 F8 */	addi r0, r4, "__vt__15Receiver<4Piki>"@l
/* 800D3650 000D05B0  3C 80 80 2C */	lis r4, "__vt__13AState<4Piki>"@ha
/* 800D3654 000D05B4  90 03 00 00 */	stw r0, 0(r3)
/* 800D3658 000D05B8  38 04 A1 B4 */	addi r0, r4, "__vt__13AState<4Piki>"@l
/* 800D365C 000D05BC  90 03 00 00 */	stw r0, 0(r3)
/* 800D3660 000D05C0  38 00 00 19 */	li r0, 0x19
/* 800D3664 000D05C4  3C A0 80 2C */	lis r5, __vt__9PikiState@ha
/* 800D3668 000D05C8  90 03 00 04 */	stw r0, 4(r3)

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 801E9408 001E6368  7C 03 07 34 */	extsh r3, r0
/* 801E940C 001E636C  80 01 01 6C */	lwz r0, 0x16c(r1)
/* 801E9410 001E6370  B0 65 00 B8 */	sth r3, 0xb8(r5)
/* 801E9414 001E6374  38 65 00 00 */	addi r3, r5, 0
/* 801E9418 001E6378  7C 00 07 34 */	extsh r0, r0
/* 801E941C 001E637C  B0 05 00 BA */	sth r0, 0xba(r5)
/* 801E9420 001E6380  4B F9 D3 ED */	bl rotate__7P2DPaneF13P2DRotateAxisf
/* 801E9424 001E6384  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801E9428 001E6388  C0 3F 00 04 */	lfs f1, 4(r31)
/* 801E942C 001E638C  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801E9430 001E6390  EC 01 00 2A */	fadds f0, f1, f0
/* 801E9434 001E6394  D0 1F 00 04 */	stfs f0, 4(r31)
/* 801E9438 001E6398  C0 3F 00 04 */	lfs f1, 4(r31)
/* 801E943C 001E639C  C0 02 BF F4 */	lfs f0, lbl_803EC1F4@sda21(r2)
/* 801E9440 001E63A0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801E9444 001E63A4  40 81 01 B4 */	ble lbl_801E95F8
/* 801E9448 001E63A8  C0 02 BF A8 */	lfs f0, lbl_803EC1A8@sda21(r2)
/* 801E944C 001E63AC  38 00 00 03 */	li r0, 3
/* 801E9450 001E63B0  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 801E9454 001E63B4  D0 1F 00 04 */	stfs f0, 4(r31)
/* 801E9458 001E63B8  90 1F 00 00 */	stw r0, 0(r31)
/* 801E945C 001E63BC  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 801E9460 001E63C0  48 00 01 98 */	b lbl_801E95F8
lbl_801E9464:
/* 801E9464 001E63C4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801E9468 001E63C8  C0 3F 00 04 */	lfs f1, 4(r31)
/* 801E946C 001E63CC  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801E9470 001E63D0  EC 01 00 2A */	fadds f0, f1, f0
/* 801E9474 001E63D4  D0 1F 00 04 */	stfs f0, 4(r31)
/* 801E9478 001E63D8  C0 3F 00 04 */	lfs f1, 4(r31)
/* 801E947C 001E63DC  C0 02 BF C0 */	lfs f0, lbl_803EC1C0@sda21(r2)
/* 801E9480 001E63E0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801E9484 001E63E4  40 81 00 1C */	ble lbl_801E94A0
/* 801E9488 001E63E8  C0 02 BF A8 */	lfs f0, lbl_803EC1A8@sda21(r2)
/* 801E948C 001E63EC  D0 1F 00 04 */	stfs f0, 4(r31)
/* 801E9490 001E63F0  C0 02 BF F8 */	lfs f0, lbl_803EC1F8@sda21(r2)
/* 801E9494 001E63F4  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 801E9498 001E63F8  C0 02 BF FC */	lfs f0, lbl_803EC1FC@sda21(r2)
/* 801E949C 001E63FC  D0 1F 00 2C */	stfs f0, 0x2c(r31)
lbl_801E94A0:
/* 801E94A0 001E6400  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 801E94A4 001E6404  C0 02 C0 00 */	lfs f0, lbl_803EC200@sda21(r2)
/* 801E94A8 001E6408  C0 23 00 BC */	lfs f1, 0xbc(r3)
/* 801E94AC 001E640C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801E94B0 001E6410  40 80 00 24 */	bge lbl_801E94D4
/* 801E94B4 001E6414  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801E94B8 001E6418  FC 20 08 50 */	fneg f1, f1
/* 801E94BC 001E641C  C0 5F 00 28 */	lfs f2, 0x28(r31)
/* 801E94C0 001E6420  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801E94C4 001E6424  EC 01 00 32 */	fmuls f0, f1, f0
/* 801E94C8 001E6428  EC 02 00 2A */	fadds f0, f2, f0
/* 801E94CC 001E642C  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 801E94D0 001E6430  48 00 00 24 */	b lbl_801E94F4
lbl_801E94D4:
/* 801E94D4 001E6434  C0 02 C0 04 */	lfs f0, lbl_803EC204@sda21(r2)
/* 801E94D8 001E6438  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801E94DC 001E643C  EC 20 08 28 */	fsubs f1, f0, f1
/* 801E94E0 001E6440  C0 5F 00 28 */	lfs f2, 0x28(r31)
/* 801E94E4 001E6444  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801E94E8 001E6448  EC 01 00 32 */	fmuls f0, f1, f0
/* 801E94EC 001E644C  EC 02 00 2A */	fadds f0, f2, f0
/* 801E94F0 001E6450  D0 1F 00 28 */	stfs f0, 0x28(r31)
lbl_801E94F4:
/* 801E94F4 001E6454  C0 3F 00 28 */	lfs f1, 0x28(r31)
/* 801E94F8 001E6458  3C 00 43 30 */	lis r0, 0x4330
/* 801E94FC 001E645C  C0 02 C0 08 */	lfs f0, lbl_803EC208@sda21(r2)
/* 801E9500 001E6460  EC 01 00 32 */	fmuls f0, f1, f0
/* 801E9504 001E6464  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 801E9508 001E6468  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 801E950C 001E646C  C8 62 BF C8 */	lfd f3, "@807"@sda21(r2)
/* 801E9510 001E6470  A8 85 00 1A */	lha r4, 0x1a(r5)
/* 801E9514 001E6474  A8 65 00 1E */	lha r3, 0x1e(r5)
/* 801E9518 001E6478  C0 82 BF F0 */	lfs f4, lbl_803EC1F0@sda21(r2)
/* 801E951C 001E647C  7C 64 18 50 */	subf r3, r4, r3
/* 801E9520 001E6480  C0 02 BF A8 */	lfs f0, lbl_803EC1A8@sda21(r2)
/* 801E9524 001E6484  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 801E9528 001E6488  C0 45 00 BC */	lfs f2, 0xbc(r5)
/* 801E952C 001E648C  90 61 01 6C */	stw r3, 0x16c(r1)
/* 801E9530 001E6490  C0 3F 00 28 */	lfs f1, 0x28(r31)
/* 801E9534 001E6494  90 01 01 68 */	stw r0, 0x168(r1)
/* 801E9538 001E6498  EC 21 10 2A */	fadds f1, f1, f2
/* 801E953C 001E649C  C8 41 01 68 */	lfd f2, 0x168(r1)
/* 801E9540 001E64A0  EC 42 18 28 */	fsubs f2, f2, f3
/* 801E9544 001E64A4  EC 44 00 B2 */	fmuls f2, f4, f2
/* 801E9548 001E64A8  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 801E954C 001E64AC  4C 41 13 82 */	cror 2, 1, 2
/* 801E9550 001E64B0  40 82 00 10 */	bne lbl_801E9560
/* 801E9554 001E64B4  C0 02 BF B4 */	lfs f0, lbl_803EC1B4@sda21(r2)
/* 801E9558 001E64B8  EC 00 10 2A */	fadds f0, f0, f2
/* 801E955C 001E64BC  48 00 00 0C */	b lbl_801E9568
lbl_801E9560:
/* 801E9560 001E64C0  C0 02 BF B4 */	lfs f0, lbl_803EC1B4@sda21(r2)
/* 801E9564 001E64C4  EC 02 00 28 */	fsubs f0, f2, f0
lbl_801E9568:
/* 801E9568 001E64C8  FC 00 00 1E */	fctiwz f0, f0
/* 801E956C 001E64CC  A8 65 00 18 */	lha r3, 0x18(r5)
/* 801E9570 001E64D0  A8 05 00 1C */	lha r0, 0x1c(r5)
/* 801E9574 001E64D4  38 80 00 7A */	li r4, 0x7a
/* 801E9578 001E64D8  7C 03 00 50 */	subf r0, r3, r0
/* 801E957C 001E64DC  7C 00 0E 70 */	srawi r0, r0, 1
/* 801E9580 001E64E0  D8 01 01 68 */	stfd f0, 0x168(r1)
/* 801E9584 001E64E4  7C 03 07 34 */	extsh r3, r0
/* 801E9588 001E64E8  80 01 01 6C */	lwz r0, 0x16c(r1)
/* 801E958C 001E64EC  B0 65 00 B8 */	sth r3, 0xb8(r5)
/* 801E9590 001E64F0  38 65 00 00 */	addi r3, r5, 0
/* 801E9594 001E64F4  7C 00 07 34 */	extsh r0, r0
/* 801E9598 001E64F8  B0 05 00 BA */	sth r0, 0xba(r5)
/* 801E959C 001E64FC  4B F9 D2 71 */	bl rotate__7P2DPaneF13P2DRotateAxisf
/* 801E95A0 001E6500  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 801E95A4 001E6504  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801E95A8 001E6508  C0 84 00 C0 */	lfs f4, 0xc0(r4)
/* 801E95AC 001E650C  C0 22 C0 10 */	lfs f1, lbl_803EC210@sda21(r2)
/* 801E95B0 001E6510  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801E95B4 001E6514  EC 21 20 28 */	fsubs f1, f1, f4
/* 801E95B8 001E6518  C0 42 C0 0C */	lfs f2, lbl_803EC20C@sda21(r2)
/* 801E95BC 001E651C  C0 7F 00 2C */	lfs f3, 0x2c(r31)
/* 801E95C0 001E6520  EC 01 00 32 */	fmuls f0, f1, f0
/* 801E95C4 001E6524  EC 02 00 32 */	fmuls f0, f2, f0
/* 801E95C8 001E6528  EC 03 00 2A */	fadds f0, f3, f0
/* 801E95CC 001E652C  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 801E95D0 001E6530  C0 3F 00 2C */	lfs f1, 0x2c(r31)
/* 801E95D4 001E6534  C0 02 C0 14 */	lfs f0, lbl_803EC214@sda21(r2)
/* 801E95D8 001E6538  EC 01 00 32 */	fmuls f0, f1, f0
/* 801E95DC 001E653C  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 801E95E0 001E6540  C0 1F 00 2C */	lfs f0, 0x2c(r31)
/* 801E95E4 001E6544  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 801E95E8 001E6548  EC 04 00 2A */	fadds f0, f4, f0
/* 801E95EC 001E654C  D0 03 00 C0 */	stfs f0, 0xc0(r3)
/* 801E95F0 001E6550  D0 03 00 C4 */	stfs f0, 0xc4(r3)
/* 801E95F4 001E6554  D0 03 00 C8 */	stfs f0, 0xc8(r3)
lbl_801E95F8:
/* 801E95F8 001E6558  80 01 01 84 */	lwz r0, 0x184(r1)
/* 801E95FC 001E655C  38 60 00 00 */	li r3, 0
/* 801E9600 001E6560  83 E1 01 7C */	lwz r31, 0x17c(r1)
/* 801E9604 001E6564  83 C1 01 78 */	lwz r30, 0x178(r1)
/* 801E9608 001E6568  38 21 01 80 */	addi r1, r1, 0x180
/* 801E960C 001E656C  7C 08 03 A6 */	mtlr r0
/* 801E9610 001E6570  4E 80 00 20 */	blr 

.global draw__Q23zen12DrawGameOverFR8Graphics
draw__Q23zen12DrawGameOverFR8Graphics:
/* 801E9614 001E6574  7C 08 02 A6 */	mflr r0
/* 801E9618 001E6578  90 01 00 04 */	stw r0, 4(r1)
/* 801E961C 001E657C  94 21 FF F8 */	stwu r1, -8(r1)
/* 801E9620 001E6580  80 03 00 00 */	lwz r0, 0(r3)
/* 801E9624 001E6584  2C 00 00 00 */	cmpwi r0, 0
/* 801E9628 001E6588  41 82 00 1C */	beq lbl_801E9644
/* 801E962C 001E658C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 801E9630 001E6590  80 63 00 00 */	lwz r3, 0(r3)
/* 801E9634 001E6594  81 83 00 00 */	lwz r12, 0(r3)
/* 801E9638 001E6598  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801E963C 001E659C  7D 88 03 A6 */	mtlr r12
/* 801E9640 001E65A0  4E 80 00 21 */	blrl 
lbl_801E9644:
/* 801E9644 001E65A4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801E9648 001E65A8  38 21 00 08 */	addi r1, r1, 8
/* 801E964C 001E65AC  7C 08 03 A6 */	mtlr r0
/* 801E9650 001E65B0  4E 80 00 20 */	blr 

.global __ct__11YaiStrategyFii
__ct__11YaiStrategyFii:
/* 801E9654 001E65B4  7C 08 02 A6 */	mflr r0
/* 801E9658 001E65B8  90 01 00 04 */	stw r0, 4(r1)
/* 801E965C 001E65BC  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 801E9660 001E65C0  93 E1 00 24 */	stw r31, 0x24(r1)
/* 801E9664 001E65C4  3B E5 00 00 */	addi r31, r5, 0
/* 801E9668 001E65C8  93 C1 00 20 */	stw r30, 0x20(r1)
/* 801E966C 001E65CC  3B C4 00 00 */	addi r30, r4, 0
/* 801E9670 001E65D0  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 801E9674 001E65D4  3B A3 00 00 */	addi r29, r3, 0
/* 801E9678 001E65D8  4B F6 3B 2D */	bl __ct__12TekiStrategyFv
/* 801E967C 001E65DC  3C 60 80 2E */	lis r3, __vt__11YaiStrategy@ha
/* 801E9680 001E65E0  38 03 5A A8 */	addi r0, r3, __vt__11YaiStrategy@l
/* 801E9684 001E65E4  90 1D 00 00 */	stw r0, 0(r29)
/* 801E9688 001E65E8  38 7D 00 00 */	addi r3, r29, 0
/* 801E968C 001E65EC  38 9E 00 00 */	addi r4, r30, 0
/* 801E9690 001E65F0  38 BF 00 00 */	addi r5, r31, 0
/* 801E9694 001E65F4  48 00 00 25 */	bl init__11YaiStrategyFii
/* 801E9698 001E65F8  7F A3 EB 78 */	mr r3, r29
/* 801E969C 001E65FC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 801E96A0 001E6600  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 801E96A4 001E6604  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 801E96A8 001E6608  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 801E96AC 001E660C  38 21 00 28 */	addi r1, r1, 0x28
/* 801E96B0 001E6610  7C 08 03 A6 */	mtlr r0
/* 801E96B4 001E6614  4E 80 00 20 */	blr 

.global init__11YaiStrategyFii
init__11YaiStrategyFii:
/* 801E96B8 001E6618  7C 08 02 A6 */	mflr r0
/* 801E96BC 001E661C  90 01 00 04 */	stw r0, 4(r1)
/* 801E96C0 001E6620  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801E96C4 001E6624  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801E96C8 001E6628  7C BF 2B 78 */	mr r31, r5
/* 801E96CC 001E662C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801E96D0 001E6630  7C 7E 1B 78 */	mr r30, r3
/* 801E96D4 001E6634  90 83 00 04 */	stw r4, 4(r3)
/* 801E96D8 001E6638  80 03 00 04 */	lwz r0, 4(r3)
/* 801E96DC 001E663C  54 03 10 3A */	slwi r3, r0, 2
/* 801E96E0 001E6640  4B E5 D9 25 */	bl alloc__6SystemFUl
/* 801E96E4 001E6644  90 7E 00 08 */	stw r3, 8(r30)
/* 801E96E8 001E6648  93 FE 00 0C */	stw r31, 0xc(r30)
/* 801E96EC 001E664C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801E96F0 001E6650  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801E96F4 001E6654  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801E96F8 001E6658  38 21 00 20 */	addi r1, r1, 0x20
/* 801E96FC 001E665C  7C 08 03 A6 */	mtlr r0
/* 801E9700 001E6660  4E 80 00 20 */	blr 

.global start__11YaiStrategyFR4Teki
start__11YaiStrategyFR4Teki:
/* 801E9704 001E6664  7C 08 02 A6 */	mflr r0
/* 801E9708 001E6668  90 01 00 04 */	stw r0, 4(r1)
/* 801E970C 001E666C  94 21 FF F8 */	stwu r1, -8(r1)
/* 801E9710 001E6670  80 03 00 0C */	lwz r0, 0xc(r3)
/* 801E9714 001E6674  90 04 03 24 */	stw r0, 0x324(r4)
/* 801E9718 001E6678  80 04 03 24 */	lwz r0, 0x324(r4)
/* 801E971C 001E667C  80 63 00 08 */	lwz r3, 8(r3)
/* 801E9720 001E6680  54 00 10 3A */	slwi r0, r0, 2
/* 801E9724 001E6684  7C 63 00 2E */	lwzx r3, r3, r0
/* 801E9728 001E6688  81 83 00 00 */	lwz r12, 0(r3)
/* 801E972C 001E668C  81 8C 00 08 */	lwz r12, 8(r12)
/* 801E9730 001E6690  7D 88 03 A6 */	mtlr r12
/* 801E9734 001E6694  4E 80 00 21 */	blrl 
/* 801E9738 001E6698  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801E973C 001E669C  38 21 00 08 */	addi r1, r1, 8
/* 801E9740 001E66A0  7C 08 03 A6 */	mtlr r0
/* 801E9744 001E66A4  4E 80 00 20 */	blr 

.global act__11YaiStrategyFR4Teki
act__11YaiStrategyFR4Teki:
/* 801E9748 001E66A8  7C 08 02 A6 */	mflr r0
/* 801E974C 001E66AC  90 01 00 04 */	stw r0, 4(r1)
/* 801E9750 001E66B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 801E9754 001E66B4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801E9758 001E66B8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801E975C 001E66BC  3B C4 00 00 */	addi r30, r4, 0
/* 801E9760 001E66C0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801E9764 001E66C4  3B A3 00 00 */	addi r29, r3, 0
/* 801E9768 001E66C8  80 04 03 24 */	lwz r0, 0x324(r4)
/* 801E976C 001E66CC  80 63 00 08 */	lwz r3, 8(r3)
/* 801E9770 001E66D0  54 00 10 3A */	slwi r0, r0, 2
/* 801E9774 001E66D4  83 FE 03 24 */	lwz r31, 0x324(r30)
/* 801E9778 001E66D8  7C 63 00 2E */	lwzx r3, r3, r0
/* 801E977C 001E66DC  81 83 00 00 */	lwz r12, 0(r3)
/* 801E9780 001E66E0  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 801E9784 001E66E4  7D 88 03 A6 */	mtlr r12
/* 801E9788 001E66E8  4E 80 00 21 */	blrl 
/* 801E978C 001E66EC  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 801E9790 001E66F0  41 82 00 48 */	beq lbl_801E97D8
/* 801E9794 001E66F4  80 7D 00 08 */	lwz r3, 8(r29)
/* 801E9798 001E66F8  57 E0 10 3A */	slwi r0, r31, 2

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x726f7065
  .4byte 0x43726561
  .4byte 0x74757265
  .4byte 0x2e637070
  .4byte 0
  .4byte 0x726f7065
  .4byte 0x43726561
  .4byte 0x74757265
  .4byte 0
  .4byte 0x526f7065
  .4byte 0x43726561
  .4byte 0x74757265
  .4byte 0
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
  .4byte 0x803df328
  .4byte 0x8
  .4byte 0x803df330
  .4byte 0
  .4byte 0
  .4byte 0x803df328
  .4byte 0x8
  .4byte 0x803df330
  .4byte 0
  .4byte 0x803df338
  .4byte 0
  .4byte 0
.global __vt__12RopeCreature
__vt__12RopeCreature:
  .4byte 0x803df340
  .4byte 0
  .4byte addCntCallback__12RefCountableFv
  .4byte subCntCallback__12RefCountableFv
  .4byte insideSafeArea__8CreatureFR8Vector3f
  .4byte platAttachable__8CreatureFv
  .4byte alwaysUpdatePlatform__8CreatureFv
  .4byte doDoAI__8CreatureFv
  .4byte setRouteTracer__8CreatureFP11RouteTracer
  .4byte init__8CreatureFv
  .4byte init__8CreatureFR8Vector3f
  .4byte resetPosition__8CreatureFR8Vector3f
  .4byte initParam__8CreatureFi
  .4byte startAI__8CreatureFi
  .4byte getiMass__8CreatureFv
  .4byte getSize__8CreatureFv
  .4byte getHeight__8CreatureFv
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
  .4byte needShadow__12RopeCreatureFv
  .4byte needFlick__8CreatureFP8Creature
  .4byte ignoreAtari__8CreatureFP8Creature
  .4byte isFree__8CreatureFv
  .4byte stimulate__8CreatureFR11Interaction
  .4byte sendMsg__8CreatureFP3Msg
  .4byte collisionCallback__8CreatureFR9CollEvent
  .4byte bounceCallback__8CreatureFv
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
  .4byte update__12RopeCreatureFv
  .4byte postUpdate__8CreatureFif
  .4byte stickUpdate__8CreatureFv
  .4byte refresh__12RopeCreatureFR8Graphics
  .4byte refresh2d__8CreatureFR8Graphics
  .4byte renderAtari__8CreatureFR8Graphics
  .4byte drawShadow__8CreatureFR8Graphics
  .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
  .4byte getCatchPos__8CreatureFP8Creature
  .4byte doAI__8CreatureFv
  .4byte doAnimation__8CreatureFv
  .4byte 0
  .4byte exitCourse__8CreatureFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
  .4byte 0x414e6f64
  .4byte 0x65000000
  .4byte 0x803df2f8
  .4byte 0
  .4byte lbl_802AF9D4
  .4byte 0x802afa00
.global __RTTI__13EventListener
__RTTI__13EventListener:
  .4byte 0x802af9f0
  .4byte 0x802afa0c

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
	.4byte 0x00000000
.global "@851"
"@851":
	.4byte 0x40080000
	.4byte 0x00000000
.global lbl_803EA400
lbl_803EA400:
	.4byte 0x00000000
	.4byte 0x00000000
.global lbl_803EA408
lbl_803EA408:
	.4byte 0x3F800000
.global lbl_803EA40C
lbl_803EA40C:
	.4byte 0x00000000
.global lbl_803EA410
lbl_803EA410:
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EBACC
lbl_803EBACC:
	.4byte 0x46FFFE00
.global lbl_803EBAD0
lbl_803EBAD0:
	.4byte 0x3F7D70A4
.global lbl_803EBAD4
lbl_803EBAD4:
	.4byte 0x40A00000
.global lbl_803EBAD8
lbl_803EBAD8:
	.4byte 0x3F000000
.global lbl_803EBADC
lbl_803EBADC:
	.4byte 0x40490FDB
.global lbl_803EBAE0
lbl_803EBAE0:
	.4byte 0x40C90FDB
.global lbl_803EBAE4
lbl_803EBAE4:
	.4byte 0xC0490FDB
.global lbl_803EBAE8
lbl_803EBAE8:
	.4byte 0x40000000
