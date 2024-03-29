.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.fn Add_PortcmdOnce, global
/* 8000E300 0000B260  7C 08 02 A6 */	mflr r0
/* 8000E304 0000B264  38 83 00 00 */	addi r4, r3, 0
/* 8000E308 0000B268  90 01 00 04 */	stw r0, 4(r1)
/* 8000E30C 0000B26C  38 6D 2C 00 */	addi r3, r13, cmd_once@sda21
/* 8000E310 0000B270  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000E314 0000B274  48 00 00 4D */	bl Add_Portcmd
/* 8000E318 0000B278  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000E31C 0000B27C  38 21 00 08 */	addi r1, r1, 8
/* 8000E320 0000B280  7C 08 03 A6 */	mtlr r0
/* 8000E324 0000B284  4E 80 00 20 */	blr 
.endfn Add_PortcmdOnce

.balign 32, 0
.fn Set_Portcmd, global
/* 8000E340 0000B2A0  90 83 00 14 */	stw r4, 0x14(r3)
/* 8000E344 0000B2A4  38 00 00 00 */	li r0, 0
/* 8000E348 0000B2A8  90 A3 00 18 */	stw r5, 0x18(r3)
/* 8000E34C 0000B2AC  90 03 00 0C */	stw r0, 0xc(r3)
/* 8000E350 0000B2B0  38 60 00 01 */	li r3, 1
/* 8000E354 0000B2B4  4E 80 00 20 */	blr 
.endfn Set_Portcmd

.balign 32, 0
.fn Add_Portcmd, global
/* 8000E360 0000B2C0  7C 08 02 A6 */	mflr r0
/* 8000E364 0000B2C4  90 01 00 04 */	stw r0, 4(r1)
/* 8000E368 0000B2C8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000E36C 0000B2CC  BF C1 00 10 */	stmw r30, 0x10(r1)
/* 8000E370 0000B2D0  3B C3 00 00 */	addi r30, r3, 0
/* 8000E374 0000B2D4  3B E4 00 00 */	addi r31, r4, 0
/* 8000E378 0000B2D8  48 1E AC 05 */	bl OSDisableInterrupts
/* 8000E37C 0000B2DC  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8000E380 0000B2E0  28 00 00 00 */	cmplwi r0, 0
/* 8000E384 0000B2E4  41 82 00 10 */	beq .L_8000E394
/* 8000E388 0000B2E8  48 1E AC 1D */	bl OSRestoreInterrupts
/* 8000E38C 0000B2EC  38 60 00 00 */	li r3, 0
/* 8000E390 0000B2F0  48 00 00 34 */	b .L_8000E3C4
.L_8000E394:
/* 8000E394 0000B2F4  80 9E 00 04 */	lwz r4, 4(r30)
/* 8000E398 0000B2F8  28 04 00 00 */	cmplwi r4, 0
/* 8000E39C 0000B2FC  41 82 00 0C */	beq .L_8000E3A8
/* 8000E3A0 0000B300  93 E4 00 10 */	stw r31, 0x10(r4)
/* 8000E3A4 0000B304  48 00 00 08 */	b .L_8000E3AC
.L_8000E3A8:
/* 8000E3A8 0000B308  93 FE 00 00 */	stw r31, 0(r30)
.L_8000E3AC:
/* 8000E3AC 0000B30C  93 FE 00 04 */	stw r31, 4(r30)
/* 8000E3B0 0000B310  38 00 00 00 */	li r0, 0
/* 8000E3B4 0000B314  90 1F 00 10 */	stw r0, 0x10(r31)
/* 8000E3B8 0000B318  93 DF 00 0C */	stw r30, 0xc(r31)
/* 8000E3BC 0000B31C  48 1E AB E9 */	bl OSRestoreInterrupts
/* 8000E3C0 0000B320  38 60 00 01 */	li r3, 1
.L_8000E3C4:
/* 8000E3C4 0000B324  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8000E3C8 0000B328  BB C1 00 10 */	lmw r30, 0x10(r1)
/* 8000E3CC 0000B32C  38 21 00 18 */	addi r1, r1, 0x18
/* 8000E3D0 0000B330  7C 08 03 A6 */	mtlr r0
/* 8000E3D4 0000B334  4E 80 00 20 */	blr 
.endfn Add_Portcmd

.balign 32, 0
.fn Get_Portcmd__FP10JPorthead_, local
/* 8000E3E0 0000B340  80 83 00 00 */	lwz r4, 0(r3)
/* 8000E3E4 0000B344  28 04 00 00 */	cmplwi r4, 0
/* 8000E3E8 0000B348  41 82 00 2C */	beq .L_8000E414
/* 8000E3EC 0000B34C  80 04 00 10 */	lwz r0, 0x10(r4)
/* 8000E3F0 0000B350  90 03 00 00 */	stw r0, 0(r3)
/* 8000E3F4 0000B354  80 03 00 00 */	lwz r0, 0(r3)
/* 8000E3F8 0000B358  28 00 00 00 */	cmplwi r0, 0
/* 8000E3FC 0000B35C  40 82 00 0C */	bne .L_8000E408
/* 8000E400 0000B360  38 00 00 00 */	li r0, 0
/* 8000E404 0000B364  90 03 00 04 */	stw r0, 4(r3)
.L_8000E408:
/* 8000E408 0000B368  38 00 00 00 */	li r0, 0
/* 8000E40C 0000B36C  90 04 00 0C */	stw r0, 0xc(r4)
/* 8000E410 0000B370  48 00 00 08 */	b .L_8000E418
.L_8000E414:
/* 8000E414 0000B374  38 80 00 00 */	li r4, 0
.L_8000E418:
/* 8000E418 0000B378  7C 83 23 78 */	mr r3, r4
/* 8000E41C 0000B37C  4E 80 00 20 */	blr 
.endfn Get_Portcmd__FP10JPorthead_

.balign 32, 0
.fn Jac_Portcmd_Proc_Once, global
/* 8000E420 0000B380  7C 08 02 A6 */	mflr r0
/* 8000E424 0000B384  90 01 00 04 */	stw r0, 4(r1)
/* 8000E428 0000B388  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000E42C 0000B38C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8000E430 0000B390  7C 7F 1B 78 */	mr r31, r3
.L_8000E434:
/* 8000E434 0000B394  7F E3 FB 78 */	mr r3, r31
/* 8000E438 0000B398  4B FF FF A9 */	bl Get_Portcmd__FP10JPorthead_
/* 8000E43C 0000B39C  28 03 00 00 */	cmplwi r3, 0
/* 8000E440 0000B3A0  41 82 00 18 */	beq .L_8000E458
/* 8000E444 0000B3A4  81 83 00 14 */	lwz r12, 0x14(r3)
/* 8000E448 0000B3A8  80 63 00 18 */	lwz r3, 0x18(r3)
/* 8000E44C 0000B3AC  7D 88 03 A6 */	mtlr r12
/* 8000E450 0000B3B0  4E 80 00 21 */	blrl 
/* 8000E454 0000B3B4  4B FF FF E0 */	b .L_8000E434
.L_8000E458:
/* 8000E458 0000B3B8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8000E45C 0000B3BC  38 60 00 00 */	li r3, 0
/* 8000E460 0000B3C0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8000E464 0000B3C4  38 21 00 18 */	addi r1, r1, 0x18
/* 8000E468 0000B3C8  7C 08 03 A6 */	mtlr r0
/* 8000E46C 0000B3CC  4E 80 00 20 */	blr 
.endfn Jac_Portcmd_Proc_Once

.balign 32, 0
.fn Jac_Portcmd_Proc_Stay, global
/* 8000E480 0000B3E0  7C 08 02 A6 */	mflr r0
/* 8000E484 0000B3E4  90 01 00 04 */	stw r0, 4(r1)
/* 8000E488 0000B3E8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000E48C 0000B3EC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8000E490 0000B3F0  83 E3 00 00 */	lwz r31, 0(r3)
.L_8000E494:
/* 8000E494 0000B3F4  28 1F 00 00 */	cmplwi r31, 0
/* 8000E498 0000B3F8  41 82 00 1C */	beq .L_8000E4B4
/* 8000E49C 0000B3FC  81 9F 00 14 */	lwz r12, 0x14(r31)
/* 8000E4A0 0000B400  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 8000E4A4 0000B404  7D 88 03 A6 */	mtlr r12
/* 8000E4A8 0000B408  4E 80 00 21 */	blrl 
/* 8000E4AC 0000B40C  83 FF 00 10 */	lwz r31, 0x10(r31)
/* 8000E4B0 0000B410  4B FF FF E4 */	b .L_8000E494
.L_8000E4B4:
/* 8000E4B4 0000B414  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8000E4B8 0000B418  38 60 00 00 */	li r3, 0
/* 8000E4BC 0000B41C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8000E4C0 0000B420  38 21 00 18 */	addi r1, r1, 0x18
/* 8000E4C4 0000B424  7C 08 03 A6 */	mtlr r0
/* 8000E4C8 0000B428  4E 80 00 20 */	blr 
.endfn Jac_Portcmd_Proc_Stay

.balign 32, 0
.fn Portcmd_Main__FPv, local
/* 8000E4E0 0000B440  7C 08 02 A6 */	mflr r0
/* 8000E4E4 0000B444  38 6D 2C 00 */	addi r3, r13, cmd_once@sda21
/* 8000E4E8 0000B448  90 01 00 04 */	stw r0, 4(r1)
/* 8000E4EC 0000B44C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000E4F0 0000B450  4B FF FF 31 */	bl Jac_Portcmd_Proc_Once
/* 8000E4F4 0000B454  38 6D 2C 08 */	addi r3, r13, cmd_stay@sda21
/* 8000E4F8 0000B458  4B FF FF 89 */	bl Jac_Portcmd_Proc_Stay
/* 8000E4FC 0000B45C  38 60 00 00 */	li r3, 0
/* 8000E500 0000B460  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000E504 0000B464  38 21 00 08 */	addi r1, r1, 8
/* 8000E508 0000B468  7C 08 03 A6 */	mtlr r0
/* 8000E50C 0000B46C  4E 80 00 20 */	blr 
.endfn Portcmd_Main__FPv

.balign 32, 0
.fn Jac_Porthead_Init, global
/* 8000E520 0000B480  38 00 00 00 */	li r0, 0
/* 8000E524 0000B484  90 03 00 00 */	stw r0, 0(r3)
/* 8000E528 0000B488  90 03 00 04 */	stw r0, 4(r3)
/* 8000E52C 0000B48C  4E 80 00 20 */	blr 
.endfn Jac_Porthead_Init

.balign 32, 0
.fn Jac_Portcmd_Init, global
/* 8000E540 0000B4A0  7C 08 02 A6 */	mflr r0
/* 8000E544 0000B4A4  38 6D 2C 00 */	addi r3, r13, cmd_once@sda21
/* 8000E548 0000B4A8  90 01 00 04 */	stw r0, 4(r1)
/* 8000E54C 0000B4AC  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000E550 0000B4B0  4B FF FF D1 */	bl Jac_Porthead_Init
/* 8000E554 0000B4B4  38 6D 2C 08 */	addi r3, r13, cmd_stay@sda21
/* 8000E558 0000B4B8  4B FF FF C9 */	bl Jac_Porthead_Init
/* 8000E55C 0000B4BC  3C 60 80 01 */	lis r3, Portcmd_Main__FPv@ha
/* 8000E560 0000B4C0  38 80 00 00 */	li r4, 0
/* 8000E564 0000B4C4  38 63 E4 E0 */	addi r3, r3, Portcmd_Main__FPv@l
/* 8000E568 0000B4C8  4B FF 8C B9 */	bl Jac_RegisterPlayerCallback
/* 8000E56C 0000B4CC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000E570 0000B4D0  38 21 00 08 */	addi r1, r1, 8
/* 8000E574 0000B4D4  7C 08 03 A6 */	mtlr r0
/* 8000E578 0000B4D8  4E 80 00 20 */	blr 
.endfn Jac_Portcmd_Init

.section .sbss, "wa"
.balign 8
.obj cmd_once, local
	.skip 8
.endobj cmd_once
.obj cmd_stay, local
	.skip 8
.endobj cmd_stay
