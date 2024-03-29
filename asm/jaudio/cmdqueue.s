.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.fn Add_Queue__FP9cmdqueue_, local
/* 8001B960 000188C0  80 8D 2C 50 */	lwz r4, queue_list@sda21(r13)
/* 8001B964 000188C4  38 00 00 00 */	li r0, 0
/* 8001B968 000188C8  90 03 00 68 */	stw r0, 0x68(r3)
/* 8001B96C 000188CC  80 0D 2C 50 */	lwz r0, queue_list@sda21(r13)
/* 8001B970 000188D0  28 00 00 00 */	cmplwi r0, 0
/* 8001B974 000188D4  40 82 00 14 */	bne .L_8001B988
/* 8001B978 000188D8  90 6D 2C 50 */	stw r3, queue_list@sda21(r13)
/* 8001B97C 000188DC  4E 80 00 20 */	blr 
/* 8001B980 000188E0  48 00 00 08 */	b .L_8001B988
.L_8001B984:
/* 8001B984 000188E4  7C 04 03 78 */	mr r4, r0
.L_8001B988:
/* 8001B988 000188E8  80 04 00 68 */	lwz r0, 0x68(r4)
/* 8001B98C 000188EC  28 00 00 00 */	cmplwi r0, 0
/* 8001B990 000188F0  40 82 FF F4 */	bne .L_8001B984
/* 8001B994 000188F4  90 64 00 68 */	stw r3, 0x68(r4)
/* 8001B998 000188F8  4E 80 00 20 */	blr 
.endfn Add_Queue__FP9cmdqueue_

.balign 32, 0
.fn Jal_AddCmdQueue, global
/* 8001B9A0 00018900  7C 08 02 A6 */	mflr r0
/* 8001B9A4 00018904  90 01 00 04 */	stw r0, 4(r1)
/* 8001B9A8 00018908  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8001B9AC 0001890C  BF A1 00 1C */	stmw r29, 0x1c(r1)
/* 8001B9B0 00018910  3B A3 00 00 */	addi r29, r3, 0
/* 8001B9B4 00018914  3B E4 00 00 */	addi r31, r4, 0
/* 8001B9B8 00018918  3B C5 00 00 */	addi r30, r5, 0
/* 8001B9BC 0001891C  48 1D D5 C1 */	bl OSDisableInterrupts
/* 8001B9C0 00018920  93 FD 00 60 */	stw r31, 0x60(r29)
/* 8001B9C4 00018924  3B E3 00 00 */	addi r31, r3, 0
/* 8001B9C8 00018928  38 7D 00 00 */	addi r3, r29, 0
/* 8001B9CC 0001892C  38 9D 00 20 */	addi r4, r29, 0x20
/* 8001B9D0 00018930  9B DD 00 64 */	stb r30, 0x64(r29)
/* 8001B9D4 00018934  38 A0 00 10 */	li r5, 0x10
/* 8001B9D8 00018938  4B FE C7 89 */	bl Jac_InitMessageQueue__FP16Jac_MessageQueuePPvl
/* 8001B9DC 0001893C  7F A3 EB 78 */	mr r3, r29
/* 8001B9E0 00018940  4B FF FF 81 */	bl Add_Queue__FP9cmdqueue_
/* 8001B9E4 00018944  7F E3 FB 78 */	mr r3, r31
/* 8001B9E8 00018948  48 1D D5 BD */	bl OSRestoreInterrupts
/* 8001B9EC 0001894C  BB A1 00 1C */	lmw r29, 0x1c(r1)
/* 8001B9F0 00018950  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8001B9F4 00018954  38 21 00 28 */	addi r1, r1, 0x28
/* 8001B9F8 00018958  7C 08 03 A6 */	mtlr r0
/* 8001B9FC 0001895C  4E 80 00 20 */	blr 
.endfn Jal_AddCmdQueue

.balign 32, 0
.fn Jal_SendCmdQueue_Noblock, global
/* 8001BA00 00018960  7C 08 02 A6 */	mflr r0
/* 8001BA04 00018964  90 01 00 04 */	stw r0, 4(r1)
/* 8001BA08 00018968  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8001BA0C 0001896C  90 61 00 08 */	stw r3, 8(r1)
/* 8001BA10 00018970  B0 81 00 0C */	sth r4, 0xc(r1)
/* 8001BA14 00018974  80 61 00 08 */	lwz r3, 8(r1)
/* 8001BA18 00018978  A0 81 00 0C */	lhz r4, 0xc(r1)
/* 8001BA1C 0001897C  4B FE C7 65 */	bl Jac_SendMessage__FP16Jac_MessageQueuePv
/* 8001BA20 00018980  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8001BA24 00018984  38 21 00 18 */	addi r1, r1, 0x18
/* 8001BA28 00018988  7C 08 03 A6 */	mtlr r0
/* 8001BA2C 0001898C  4E 80 00 20 */	blr 
.endfn Jal_SendCmdQueue_Noblock

.balign 32, 0
.fn Jal_SendCmdQueue_Force, global
/* 8001BA40 000189A0  7C 08 02 A6 */	mflr r0
/* 8001BA44 000189A4  90 01 00 04 */	stw r0, 4(r1)
/* 8001BA48 000189A8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8001BA4C 000189AC  BF C1 00 18 */	stmw r30, 0x18(r1)
/* 8001BA50 000189B0  54 9F 04 3E */	clrlwi r31, r4, 0x10
/* 8001BA54 000189B4  3B C3 00 00 */	addi r30, r3, 0
/* 8001BA58 000189B8  38 9F 00 00 */	addi r4, r31, 0
/* 8001BA5C 000189BC  4B FE C7 25 */	bl Jac_SendMessage__FP16Jac_MessageQueuePv
/* 8001BA60 000189C0  2C 03 00 00 */	cmpwi r3, 0
/* 8001BA64 000189C4  40 82 00 1C */	bne .L_8001BA80
/* 8001BA68 000189C8  38 7E 00 00 */	addi r3, r30, 0
/* 8001BA6C 000189CC  38 81 00 10 */	addi r4, r1, 0x10
/* 8001BA70 000189D0  4B FE C7 91 */	bl Jac_ReceiveMessage__FP16Jac_MessageQueuePPv
/* 8001BA74 000189D4  38 7E 00 00 */	addi r3, r30, 0
/* 8001BA78 000189D8  38 9F 00 00 */	addi r4, r31, 0
/* 8001BA7C 000189DC  4B FE C7 05 */	bl Jac_SendMessage__FP16Jac_MessageQueuePv
.L_8001BA80:
/* 8001BA80 000189E0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8001BA84 000189E4  BB C1 00 18 */	lmw r30, 0x18(r1)
/* 8001BA88 000189E8  38 21 00 20 */	addi r1, r1, 0x20
/* 8001BA8C 000189EC  7C 08 03 A6 */	mtlr r0
/* 8001BA90 000189F0  4E 80 00 20 */	blr 
.endfn Jal_SendCmdQueue_Force

.balign 32, 0
.fn Jal_FrameWork__FPv, local
/* 8001BAA0 00018A00  7C 08 02 A6 */	mflr r0
/* 8001BAA4 00018A04  90 01 00 04 */	stw r0, 4(r1)
/* 8001BAA8 00018A08  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8001BAAC 00018A0C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8001BAB0 00018A10  83 ED 2C 50 */	lwz r31, queue_list@sda21(r13)
/* 8001BAB4 00018A14  48 00 00 48 */	b .L_8001BAFC
.L_8001BAB8:
/* 8001BAB8 00018A18  80 7F 00 60 */	lwz r3, 0x60(r31)
/* 8001BABC 00018A1C  38 A0 00 01 */	li r5, 1
/* 8001BAC0 00018A20  88 9F 00 64 */	lbz r4, 0x64(r31)
/* 8001BAC4 00018A24  4B FF 49 7D */	bl Jam_CheckPortAppDirect
/* 8001BAC8 00018A28  2C 03 00 01 */	cmpwi r3, 1
/* 8001BACC 00018A2C  40 82 00 2C */	bne .L_8001BAF8
/* 8001BAD0 00018A30  38 7F 00 00 */	addi r3, r31, 0
/* 8001BAD4 00018A34  38 81 00 10 */	addi r4, r1, 0x10
/* 8001BAD8 00018A38  4B FE C7 89 */	bl Jac_ReceiveMessage_Fast__FP16Jac_MessageQueuePPv
/* 8001BADC 00018A3C  2C 03 00 01 */	cmpwi r3, 1
/* 8001BAE0 00018A40  40 82 00 18 */	bne .L_8001BAF8
/* 8001BAE4 00018A44  80 01 00 10 */	lwz r0, 0x10(r1)
/* 8001BAE8 00018A48  80 7F 00 60 */	lwz r3, 0x60(r31)
/* 8001BAEC 00018A4C  88 9F 00 64 */	lbz r4, 0x64(r31)
/* 8001BAF0 00018A50  54 05 04 3E */	clrlwi r5, r0, 0x10
/* 8001BAF4 00018A54  4B FF 48 8D */	bl Jam_WritePortAppDirect
.L_8001BAF8:
/* 8001BAF8 00018A58  83 FF 00 68 */	lwz r31, 0x68(r31)
.L_8001BAFC:
/* 8001BAFC 00018A5C  28 1F 00 00 */	cmplwi r31, 0
/* 8001BB00 00018A60  40 82 FF B8 */	bne .L_8001BAB8
/* 8001BB04 00018A64  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8001BB08 00018A68  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8001BB0C 00018A6C  38 21 00 20 */	addi r1, r1, 0x20
/* 8001BB10 00018A70  7C 08 03 A6 */	mtlr r0
/* 8001BB14 00018A74  4E 80 00 20 */	blr 
.endfn Jal_FrameWork__FPv

.balign 32, 0
.fn Jal_CmdQueue_Init, global
/* 8001BB20 00018A80  7C 08 02 A6 */	mflr r0
/* 8001BB24 00018A84  3C 60 80 02 */	lis r3, Jal_FrameWork__FPv@ha
/* 8001BB28 00018A88  90 01 00 04 */	stw r0, 4(r1)
/* 8001BB2C 00018A8C  38 80 00 00 */	li r4, 0
/* 8001BB30 00018A90  38 63 BA A0 */	addi r3, r3, Jal_FrameWork__FPv@l
/* 8001BB34 00018A94  94 21 FF F8 */	stwu r1, -8(r1)
/* 8001BB38 00018A98  4B FE B6 E9 */	bl Jac_RegisterPlayerCallback
/* 8001BB3C 00018A9C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8001BB40 00018AA0  38 21 00 08 */	addi r1, r1, 8
/* 8001BB44 00018AA4  7C 08 03 A6 */	mtlr r0
/* 8001BB48 00018AA8  4E 80 00 20 */	blr 
.endfn Jal_CmdQueue_Init
