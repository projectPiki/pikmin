.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__9ActBoMakeFP4Piki, global
/* 800AC30C 000A926C  7C 08 02 A6 */	mflr r0
/* 800AC310 000A9270  38 A0 00 01 */	li r5, 1
/* 800AC314 000A9274  90 01 00 04 */	stw r0, 4(r1)
/* 800AC318 000A9278  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800AC31C 000A927C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800AC320 000A9280  3B E3 00 00 */	addi r31, r3, 0
/* 800AC324 000A9284  48 01 7A AD */	bl __ct__6ActionFP4Pikib
/* 800AC328 000A9288  3C 60 80 2B */	lis r3, __vt__19PaniAnimKeyListener@ha
/* 800AC32C 000A928C  38 03 DB 94 */	addi r0, r3, __vt__19PaniAnimKeyListener@l
/* 800AC330 000A9290  3C 60 80 2B */	lis r3, __vt__9ActBoMake@ha
/* 800AC334 000A9294  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800AC338 000A9298  38 63 5A 50 */	addi r3, r3, __vt__9ActBoMake@l
/* 800AC33C 000A929C  90 7F 00 00 */	stw r3, 0(r31)
/* 800AC340 000A92A0  38 03 00 64 */	addi r0, r3, 0x64
/* 800AC344 000A92A4  38 7F 00 00 */	addi r3, r31, 0
/* 800AC348 000A92A8  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800AC34C 000A92AC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800AC350 000A92B0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800AC354 000A92B4  38 21 00 18 */	addi r1, r1, 0x18
/* 800AC358 000A92B8  7C 08 03 A6 */	mtlr r0
/* 800AC35C 000A92BC  4E 80 00 20 */	blr 
.endfn __ct__9ActBoMakeFP4Piki

.fn init__9ActBoMakeFP8Creature, global
/* 800AC360 000A92C0  7C 08 02 A6 */	mflr r0
/* 800AC364 000A92C4  28 04 00 00 */	cmplwi r4, 0
/* 800AC368 000A92C8  90 01 00 04 */	stw r0, 4(r1)
/* 800AC36C 000A92CC  38 00 00 00 */	li r0, 0
/* 800AC370 000A92D0  94 21 FF F8 */	stwu r1, -8(r1)
/* 800AC374 000A92D4  90 03 00 1C */	stw r0, 0x1c(r3)
/* 800AC378 000A92D8  41 82 00 14 */	beq .L_800AC38C
/* 800AC37C 000A92DC  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 800AC380 000A92E0  2C 00 00 23 */	cmpwi r0, 0x23
/* 800AC384 000A92E4  40 82 00 08 */	bne .L_800AC38C
/* 800AC388 000A92E8  90 83 00 1C */	stw r4, 0x1c(r3)
.L_800AC38C:
/* 800AC38C 000A92EC  48 00 00 B5 */	bl initApproach__9ActBoMakeFv
/* 800AC390 000A92F0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800AC394 000A92F4  38 21 00 08 */	addi r1, r1, 8
/* 800AC398 000A92F8  7C 08 03 A6 */	mtlr r0
/* 800AC39C 000A92FC  4E 80 00 20 */	blr 
.endfn init__9ActBoMakeFP8Creature

.fn exec__9ActBoMakeFv, global
/* 800AC3A0 000A9300  7C 08 02 A6 */	mflr r0
/* 800AC3A4 000A9304  90 01 00 04 */	stw r0, 4(r1)
/* 800AC3A8 000A9308  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800AC3AC 000A930C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800AC3B0 000A9310  7C 7F 1B 78 */	mr r31, r3
/* 800AC3B4 000A9314  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 800AC3B8 000A9318  28 03 00 00 */	cmplwi r3, 0
/* 800AC3BC 000A931C  40 82 00 0C */	bne .L_800AC3C8
/* 800AC3C0 000A9320  38 60 00 01 */	li r3, 1
/* 800AC3C4 000A9324  48 00 00 68 */	b .L_800AC42C
.L_800AC3C8:
/* 800AC3C8 000A9328  81 83 00 00 */	lwz r12, 0(r3)
/* 800AC3CC 000A932C  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 800AC3D0 000A9330  7D 88 03 A6 */	mtlr r12
/* 800AC3D4 000A9334  4E 80 00 21 */	blrl 
/* 800AC3D8 000A9338  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800AC3DC 000A933C  40 82 00 18 */	bne .L_800AC3F4
/* 800AC3E0 000A9340  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800AC3E4 000A9344  38 00 00 00 */	li r0, 0
/* 800AC3E8 000A9348  38 60 00 02 */	li r3, 2
/* 800AC3EC 000A934C  98 04 04 00 */	stb r0, 0x400(r4)
/* 800AC3F0 000A9350  48 00 00 3C */	b .L_800AC42C
.L_800AC3F4:
/* 800AC3F4 000A9354  A0 1F 00 18 */	lhz r0, 0x18(r31)
/* 800AC3F8 000A9358  2C 00 00 01 */	cmpwi r0, 1
/* 800AC3FC 000A935C  41 82 00 20 */	beq .L_800AC41C
/* 800AC400 000A9360  40 80 00 28 */	bge .L_800AC428
/* 800AC404 000A9364  2C 00 00 00 */	cmpwi r0, 0
/* 800AC408 000A9368  40 80 00 08 */	bge .L_800AC410
/* 800AC40C 000A936C  48 00 00 1C */	b .L_800AC428
.L_800AC410:
/* 800AC410 000A9370  7F E3 FB 78 */	mr r3, r31
/* 800AC414 000A9374  48 00 00 91 */	bl exeApproach__9ActBoMakeFv
/* 800AC418 000A9378  48 00 00 14 */	b .L_800AC42C
.L_800AC41C:
/* 800AC41C 000A937C  7F E3 FB 78 */	mr r3, r31
/* 800AC420 000A9380  48 00 02 65 */	bl exeWork__9ActBoMakeFv
/* 800AC424 000A9384  48 00 00 08 */	b .L_800AC42C
.L_800AC428:
/* 800AC428 000A9388  38 60 00 00 */	li r3, 0
.L_800AC42C:
/* 800AC42C 000A938C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800AC430 000A9390  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800AC434 000A9394  38 21 00 18 */	addi r1, r1, 0x18
/* 800AC438 000A9398  7C 08 03 A6 */	mtlr r0
/* 800AC43C 000A939C  4E 80 00 20 */	blr 
.endfn exec__9ActBoMakeFv

.fn initApproach__9ActBoMakeFv, global
/* 800AC440 000A93A0  7C 08 02 A6 */	mflr r0
/* 800AC444 000A93A4  38 80 00 02 */	li r4, 2
/* 800AC448 000A93A8  90 01 00 04 */	stw r0, 4(r1)
/* 800AC44C 000A93AC  38 00 00 00 */	li r0, 0
/* 800AC450 000A93B0  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800AC454 000A93B4  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800AC458 000A93B8  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800AC45C 000A93BC  3B C3 00 00 */	addi r30, r3, 0
/* 800AC460 000A93C0  B0 03 00 18 */	sth r0, 0x18(r3)
/* 800AC464 000A93C4  38 61 00 0C */	addi r3, r1, 0xc
/* 800AC468 000A93C8  48 07 2A F1 */	bl __ct__14PaniMotionInfoFi
/* 800AC46C 000A93CC  3B E3 00 00 */	addi r31, r3, 0
/* 800AC470 000A93D0  38 61 00 14 */	addi r3, r1, 0x14
/* 800AC474 000A93D4  38 80 00 02 */	li r4, 2
/* 800AC478 000A93D8  48 07 2A E1 */	bl __ct__14PaniMotionInfoFi
/* 800AC47C 000A93DC  7C 64 1B 78 */	mr r4, r3
/* 800AC480 000A93E0  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800AC484 000A93E4  7F E5 FB 78 */	mr r5, r31
/* 800AC488 000A93E8  48 01 E5 51 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800AC48C 000A93EC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800AC490 000A93F0  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800AC494 000A93F4  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800AC498 000A93F8  38 21 00 28 */	addi r1, r1, 0x28
/* 800AC49C 000A93FC  7C 08 03 A6 */	mtlr r0
/* 800AC4A0 000A9400  4E 80 00 20 */	blr 
.endfn initApproach__9ActBoMakeFv

.fn exeApproach__9ActBoMakeFv, global
/* 800AC4A4 000A9404  7C 08 02 A6 */	mflr r0
/* 800AC4A8 000A9408  90 01 00 04 */	stw r0, 4(r1)
/* 800AC4AC 000A940C  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 800AC4B0 000A9410  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 800AC4B4 000A9414  DB C1 00 48 */	stfd f30, 0x48(r1)
/* 800AC4B8 000A9418  93 E1 00 44 */	stw r31, 0x44(r1)
/* 800AC4BC 000A941C  7C 7F 1B 78 */	mr r31, r3
/* 800AC4C0 000A9420  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800AC4C4 000A9424  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 800AC4C8 000A9428  C4 23 00 94 */	lfsu f1, 0x94(r3)
/* 800AC4CC 000A942C  C4 04 00 94 */	lfsu f0, 0x94(r4)
/* 800AC4D0 000A9430  C0 63 00 04 */	lfs f3, 4(r3)
/* 800AC4D4 000A9434  C0 44 00 04 */	lfs f2, 4(r4)
/* 800AC4D8 000A9438  EC 01 00 28 */	fsubs f0, f1, f0
/* 800AC4DC 000A943C  C0 83 00 08 */	lfs f4, 8(r3)
/* 800AC4E0 000A9440  C0 24 00 08 */	lfs f1, 8(r4)
/* 800AC4E4 000A9444  EC 43 10 28 */	fsubs f2, f3, f2
/* 800AC4E8 000A9448  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 800AC4EC 000A944C  EC 04 08 28 */	fsubs f0, f4, f1
/* 800AC4F0 000A9450  D0 41 00 38 */	stfs f2, 0x38(r1)
/* 800AC4F4 000A9454  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 800AC4F8 000A9458  C0 21 00 34 */	lfs f1, 0x34(r1)
/* 800AC4FC 000A945C  C0 01 00 38 */	lfs f0, 0x38(r1)
/* 800AC500 000A9460  C0 41 00 3C */	lfs f2, 0x3c(r1)
/* 800AC504 000A9464  EC 21 00 72 */	fmuls f1, f1, f1
/* 800AC508 000A9468  EC 00 00 32 */	fmuls f0, f0, f0
/* 800AC50C 000A946C  EC 42 00 B2 */	fmuls f2, f2, f2
/* 800AC510 000A9470  EC 01 00 2A */	fadds f0, f1, f0
/* 800AC514 000A9474  EC 22 00 2A */	fadds f1, f2, f0
/* 800AC518 000A9478  4B F6 17 29 */	bl sqrtf__3stdFf
/* 800AC51C 000A947C  FF C0 08 90 */	fmr f30, f1
/* 800AC520 000A9480  C0 02 8F 30 */	lfs f0, lbl_803E9130@sda21(r2)
/* 800AC524 000A9484  FC 00 F0 00 */	fcmpu cr0, f0, f30
/* 800AC528 000A9488  41 82 00 28 */	beq .L_800AC550
/* 800AC52C 000A948C  C0 01 00 34 */	lfs f0, 0x34(r1)
/* 800AC530 000A9490  EC 00 F0 24 */	fdivs f0, f0, f30
/* 800AC534 000A9494  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 800AC538 000A9498  C0 01 00 38 */	lfs f0, 0x38(r1)
/* 800AC53C 000A949C  EC 00 F0 24 */	fdivs f0, f0, f30
/* 800AC540 000A94A0  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 800AC544 000A94A4  C0 01 00 3C */	lfs f0, 0x3c(r1)
/* 800AC548 000A94A8  EC 00 F0 24 */	fdivs f0, f0, f30
/* 800AC54C 000A94AC  D0 01 00 3C */	stfs f0, 0x3c(r1)
.L_800AC550:
/* 800AC550 000A94B0  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800AC554 000A94B4  81 83 00 00 */	lwz r12, 0(r3)
/* 800AC558 000A94B8  81 8C 00 5C */	lwz r12, 0x5c(r12)
/* 800AC55C 000A94BC  7D 88 03 A6 */	mtlr r12
/* 800AC560 000A94C0  4E 80 00 21 */	blrl 
/* 800AC564 000A94C4  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 800AC568 000A94C8  FF E0 08 90 */	fmr f31, f1
/* 800AC56C 000A94CC  81 83 00 00 */	lwz r12, 0(r3)
/* 800AC570 000A94D0  81 8C 00 5C */	lwz r12, 0x5c(r12)
/* 800AC574 000A94D4  7D 88 03 A6 */	mtlr r12
/* 800AC578 000A94D8  4E 80 00 21 */	blrl 
/* 800AC57C 000A94DC  EC 3E 08 28 */	fsubs f1, f30, f1
/* 800AC580 000A94E0  C0 02 8F 34 */	lfs f0, lbl_803E9134@sda21(r2)
/* 800AC584 000A94E4  EC 21 F8 28 */	fsubs f1, f1, f31
/* 800AC588 000A94E8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800AC58C 000A94EC  40 80 00 14 */	bge .L_800AC5A0
/* 800AC590 000A94F0  7F E3 FB 78 */	mr r3, r31
/* 800AC594 000A94F4  48 00 00 3D */	bl initWork__9ActBoMakeFv
/* 800AC598 000A94F8  38 60 00 00 */	li r3, 0
/* 800AC59C 000A94FC  48 00 00 18 */	b .L_800AC5B4
.L_800AC5A0:
/* 800AC5A0 000A9500  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800AC5A4 000A9504  38 81 00 34 */	addi r4, r1, 0x34
/* 800AC5A8 000A9508  C0 22 8F 38 */	lfs f1, lbl_803E9138@sda21(r2)
/* 800AC5AC 000A950C  48 01 F8 2D */	bl setSpeed__4PikiFfR8Vector3f
/* 800AC5B0 000A9510  38 60 00 00 */	li r3, 0
.L_800AC5B4:
/* 800AC5B4 000A9514  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 800AC5B8 000A9518  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 800AC5BC 000A951C  CB C1 00 48 */	lfd f30, 0x48(r1)
/* 800AC5C0 000A9520  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 800AC5C4 000A9524  38 21 00 58 */	addi r1, r1, 0x58
/* 800AC5C8 000A9528  7C 08 03 A6 */	mtlr r0
/* 800AC5CC 000A952C  4E 80 00 20 */	blr 
.endfn exeApproach__9ActBoMakeFv

.fn initWork__9ActBoMakeFv, global
/* 800AC5D0 000A9530  7C 08 02 A6 */	mflr r0
/* 800AC5D4 000A9534  90 01 00 04 */	stw r0, 4(r1)
/* 800AC5D8 000A9538  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800AC5DC 000A953C  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800AC5E0 000A9540  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800AC5E4 000A9544  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800AC5E8 000A9548  7C 7D 1B 78 */	mr r29, r3
/* 800AC5EC 000A954C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800AC5F0 000A9550  80 03 01 84 */	lwz r0, 0x184(r3)
/* 800AC5F4 000A9554  28 00 00 00 */	cmplwi r0, 0
/* 800AC5F8 000A9558  40 82 00 70 */	bne .L_800AC668
/* 800AC5FC 000A955C  80 BD 00 1C */	lwz r5, 0x1c(r29)
/* 800AC600 000A9560  3C 60 63 65 */	lis r3, 0x63656E74@ha
/* 800AC604 000A9564  38 83 6E 74 */	addi r4, r3, 0x63656E74@l
/* 800AC608 000A9568  80 65 02 20 */	lwz r3, 0x220(r5)
/* 800AC60C 000A956C  4B FD D1 05 */	bl getSphere__8CollInfoFUl
/* 800AC610 000A9570  7C 65 1B 78 */	mr r5, r3
/* 800AC614 000A9574  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800AC618 000A9578  80 9D 00 1C */	lwz r4, 0x1c(r29)
/* 800AC61C 000A957C  38 C0 FF FF */	li r6, -1
/* 800AC620 000A9580  C0 22 8F 30 */	lfs f1, lbl_803E9130@sda21(r2)
/* 800AC624 000A9584  4B FE 40 95 */	bl startStickObject__8CreatureFP8CreatureP8CollPartif
/* 800AC628 000A9588  28 1D 00 00 */	cmplwi r29, 0
/* 800AC62C 000A958C  3B DD 00 00 */	addi r30, r29, 0
/* 800AC630 000A9590  41 82 00 08 */	beq .L_800AC638
/* 800AC634 000A9594  3B DE 00 14 */	addi r30, r30, 0x14
.L_800AC638:
/* 800AC638 000A9598  38 61 00 10 */	addi r3, r1, 0x10
/* 800AC63C 000A959C  38 80 00 30 */	li r4, 0x30
/* 800AC640 000A95A0  48 07 29 19 */	bl __ct__14PaniMotionInfoFi
/* 800AC644 000A95A4  3B E3 00 00 */	addi r31, r3, 0
/* 800AC648 000A95A8  38 BE 00 00 */	addi r5, r30, 0
/* 800AC64C 000A95AC  38 61 00 18 */	addi r3, r1, 0x18
/* 800AC650 000A95B0  38 80 00 30 */	li r4, 0x30
/* 800AC654 000A95B4  48 07 29 39 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800AC658 000A95B8  7C 64 1B 78 */	mr r4, r3
/* 800AC65C 000A95BC  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800AC660 000A95C0  7F E5 FB 78 */	mr r5, r31
/* 800AC664 000A95C4  48 01 E3 75 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
.L_800AC668:
/* 800AC668 000A95C8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800AC66C 000A95CC  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800AC670 000A95D0  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800AC674 000A95D4  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800AC678 000A95D8  38 21 00 30 */	addi r1, r1, 0x30
/* 800AC67C 000A95DC  7C 08 03 A6 */	mtlr r0
/* 800AC680 000A95E0  4E 80 00 20 */	blr 
.endfn initWork__9ActBoMakeFv

.fn exeWork__9ActBoMakeFv, global
/* 800AC684 000A95E4  38 60 00 00 */	li r3, 0
/* 800AC688 000A95E8  4E 80 00 20 */	blr 
.endfn exeWork__9ActBoMakeFv

.fn cleanup__9ActBoMakeFv, global
/* 800AC68C 000A95EC  7C 08 02 A6 */	mflr r0
/* 800AC690 000A95F0  90 01 00 04 */	stw r0, 4(r1)
/* 800AC694 000A95F4  94 21 FF F8 */	stwu r1, -8(r1)
/* 800AC698 000A95F8  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800AC69C 000A95FC  4B FE 41 DD */	bl endStickObject__8CreatureFv
/* 800AC6A0 000A9600  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800AC6A4 000A9604  38 21 00 08 */	addi r1, r1, 8
/* 800AC6A8 000A9608  7C 08 03 A6 */	mtlr r0
/* 800AC6AC 000A960C  4E 80 00 20 */	blr 
.endfn cleanup__9ActBoMakeFv

.fn animationKeyUpdated__9ActBoMakeFR16PaniAnimKeyEvent, global
/* 800AC6B0 000A9610  7C 08 02 A6 */	mflr r0
/* 800AC6B4 000A9614  90 01 00 04 */	stw r0, 4(r1)
/* 800AC6B8 000A9618  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800AC6BC 000A961C  80 04 00 00 */	lwz r0, 0(r4)
/* 800AC6C0 000A9620  2C 00 00 01 */	cmpwi r0, 1
/* 800AC6C4 000A9624  41 82 00 0C */	beq .L_800AC6D0
/* 800AC6C8 000A9628  40 80 00 50 */	bge .L_800AC718
/* 800AC6CC 000A962C  48 00 00 4C */	b .L_800AC718
.L_800AC6D0:
/* 800AC6D0 000A9630  3C 80 80 2B */	lis r4, __vt__11Interaction@ha
/* 800AC6D4 000A9634  80 C3 00 0C */	lwz r6, 0xc(r3)
/* 800AC6D8 000A9638  38 04 CF 9C */	addi r0, r4, __vt__11Interaction@l
/* 800AC6DC 000A963C  C0 02 8F 38 */	lfs f0, lbl_803E9138@sda21(r2)
/* 800AC6E0 000A9640  90 01 00 10 */	stw r0, 0x10(r1)
/* 800AC6E4 000A9644  3C 80 80 2B */	lis r4, __vt__13InteractBuild@ha
/* 800AC6E8 000A9648  38 A4 10 D8 */	addi r5, r4, __vt__13InteractBuild@l
/* 800AC6EC 000A964C  90 C1 00 14 */	stw r6, 0x14(r1)
/* 800AC6F0 000A9650  38 00 00 00 */	li r0, 0
/* 800AC6F4 000A9654  38 81 00 10 */	addi r4, r1, 0x10
/* 800AC6F8 000A9658  90 A1 00 10 */	stw r5, 0x10(r1)
/* 800AC6FC 000A965C  90 01 00 18 */	stw r0, 0x18(r1)
/* 800AC700 000A9660  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 800AC704 000A9664  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 800AC708 000A9668  81 83 00 00 */	lwz r12, 0(r3)
/* 800AC70C 000A966C  81 8C 00 A0 */	lwz r12, 0xa0(r12)
/* 800AC710 000A9670  7D 88 03 A6 */	mtlr r12
/* 800AC714 000A9674  4E 80 00 21 */	blrl 
.L_800AC718:
/* 800AC718 000A9678  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800AC71C 000A967C  38 21 00 20 */	addi r1, r1, 0x20
/* 800AC720 000A9680  7C 08 03 A6 */	mtlr r0
/* 800AC724 000A9684  4E 80 00 20 */	blr 
.endfn animationKeyUpdated__9ActBoMakeFR16PaniAnimKeyEvent

.fn __dt__9ActBoMakeFv, weak
/* 800AC728 000A9688  7C 08 02 A6 */	mflr r0
/* 800AC72C 000A968C  90 01 00 04 */	stw r0, 4(r1)
/* 800AC730 000A9690  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800AC734 000A9694  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800AC738 000A9698  3B E4 00 00 */	addi r31, r4, 0
/* 800AC73C 000A969C  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800AC740 000A96A0  7C 7E 1B 79 */	or. r30, r3, r3
/* 800AC744 000A96A4  41 82 00 34 */	beq .L_800AC778
/* 800AC748 000A96A8  3C 60 80 2B */	lis r3, __vt__9ActBoMake@ha
/* 800AC74C 000A96AC  38 63 5A 50 */	addi r3, r3, __vt__9ActBoMake@l
/* 800AC750 000A96B0  90 7E 00 00 */	stw r3, 0(r30)
/* 800AC754 000A96B4  38 03 00 64 */	addi r0, r3, 0x64
/* 800AC758 000A96B8  38 7E 00 00 */	addi r3, r30, 0
/* 800AC75C 000A96BC  90 1E 00 14 */	stw r0, 0x14(r30)
/* 800AC760 000A96C0  38 80 00 00 */	li r4, 0
/* 800AC764 000A96C4  48 01 76 A5 */	bl __dt__6ActionFv
/* 800AC768 000A96C8  7F E0 07 35 */	extsh. r0, r31
/* 800AC76C 000A96CC  40 81 00 0C */	ble .L_800AC778
/* 800AC770 000A96D0  7F C3 F3 78 */	mr r3, r30
/* 800AC774 000A96D4  4B F9 AA 39 */	bl __dl__FPv
.L_800AC778:
/* 800AC778 000A96D8  7F C3 F3 78 */	mr r3, r30
/* 800AC77C 000A96DC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800AC780 000A96E0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800AC784 000A96E4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800AC788 000A96E8  38 21 00 18 */	addi r1, r1, 0x18
/* 800AC78C 000A96EC  7C 08 03 A6 */	mtlr r0
/* 800AC790 000A96F0  4E 80 00 20 */	blr 
.endfn __dt__9ActBoMakeFv

.fn "@20@animationKeyUpdated__9ActBoMakeFR16PaniAnimKeyEvent", weak
/* 800AC794 000A96F4  38 63 FF EC */	addi r3, r3, -20
/* 800AC798 000A96F8  4B FF FF 18 */	b animationKeyUpdated__9ActBoMakeFR16PaniAnimKeyEvent
.endfn "@20@animationKeyUpdated__9ActBoMakeFR16PaniAnimKeyEvent"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B59C0, local
	.asciz "aiBoMake.cpp"
.endobj lbl_802B59C0
.balign 4
.obj lbl_802B59D0, local
	.asciz "aiBoMake"
.endobj lbl_802B59D0
.balign 4
.obj lbl_802B59DC, local
	.asciz "Interaction"
.endobj lbl_802B59DC
.balign 4
.skip 0x2C # compiler padding
.balign 4
.obj lbl_802B5A14, local
	.asciz "ActBoMake"
.endobj lbl_802B5A14
.balign 4
.obj lbl_802B5A20, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B5A20
.balign 4
.obj lbl_802B5A30, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.endobj lbl_802B5A30
.balign 4
.obj lbl_802B5A3C, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B5A3C
.balign 4
.obj __vt__9ActBoMake, global
	.4byte __RTTI__9ActBoMake
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
	.4byte __dt__9ActBoMakeFv
	.4byte init__9ActBoMakeFP8Creature
	.4byte exec__9ActBoMakeFv
	.4byte cleanup__9ActBoMakeFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
	.4byte __RTTI__9ActBoMake
	.4byte 0xFFFFFFEC
	.4byte "@20@animationKeyUpdated__9ActBoMakeFR16PaniAnimKeyEvent"
	.4byte animationKeyUpdated__9ActBoMakeFR16PaniAnimKeyEvent
.endobj __vt__9ActBoMake
.balign 4
.obj lbl_802B5AC4, local
	.asciz "PaniAnimKeyListener"
.endobj lbl_802B5AC4
.balign 4
.skip 0xC # compiler padding
.obj lbl_802B5AE4, local
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x30)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x58)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x6C)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x80)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x94)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xA8)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xBC)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xD0)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x44)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xF8)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xE4)
.endobj lbl_802B5AE4

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B5A20
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803DFE48, local
	.asciz "Action"
.endobj lbl_803DFE48
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803DFE48
	.4byte lbl_802B5A30
.endobj __RTTI__6Action
.balign 4
.obj __RTTI__9ActBoMake, local
	.4byte lbl_802B5A14
	.4byte lbl_802B5A3C
.endobj __RTTI__9ActBoMake

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9130, local
	.float 0.0
.endobj lbl_803E9130
.obj lbl_803E9134, local
	.float 3.0
.endobj lbl_803E9134
.obj lbl_803E9138, local
	.float 1.0
.endobj lbl_803E9138
