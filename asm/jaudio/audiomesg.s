.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.fn Jac_InitMessageQueue__FP16Jac_MessageQueuePPvl, global
/* 80008160 000050C0  90 83 00 10 */	stw r4, 0x10(r3)
/* 80008164 000050C4  38 00 00 00 */	li r0, 0
/* 80008168 000050C8  90 A3 00 14 */	stw r5, 0x14(r3)
/* 8000816C 000050CC  90 03 00 18 */	stw r0, 0x18(r3)
/* 80008170 000050D0  90 03 00 1C */	stw r0, 0x1c(r3)
/* 80008174 000050D4  4E 80 00 20 */	blr 
.endfn Jac_InitMessageQueue__FP16Jac_MessageQueuePPvl

.balign 32, 0
.fn Jac_SendMessage__FP16Jac_MessageQueuePv, global
/* 80008180 000050E0  7C 08 02 A6 */	mflr r0
/* 80008184 000050E4  90 01 00 04 */	stw r0, 4(r1)
/* 80008188 000050E8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8000818C 000050EC  BF C1 00 18 */	stmw r30, 0x18(r1)
/* 80008190 000050F0  3B C3 00 00 */	addi r30, r3, 0
/* 80008194 000050F4  3B E4 00 00 */	addi r31, r4, 0
/* 80008198 000050F8  48 1F 0D E5 */	bl OSDisableInterrupts
/* 8000819C 000050FC  48 00 00 10 */	b .L_800081AC
.L_800081A0:
/* 800081A0 00005100  48 1F 0E 05 */	bl OSRestoreInterrupts
/* 800081A4 00005104  38 60 00 00 */	li r3, 0
/* 800081A8 00005108  48 00 00 44 */	b .L_800081EC
.L_800081AC:
/* 800081AC 0000510C  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 800081B0 00005110  80 DE 00 1C */	lwz r6, 0x1c(r30)
/* 800081B4 00005114  7C 04 30 00 */	cmpw r4, r6
/* 800081B8 00005118  40 81 FF E8 */	ble .L_800081A0
/* 800081BC 0000511C  80 1E 00 18 */	lwz r0, 0x18(r30)
/* 800081C0 00005120  38 84 FF FF */	addi r4, r4, -1
/* 800081C4 00005124  80 BE 00 10 */	lwz r5, 0x10(r30)
/* 800081C8 00005128  7C 00 32 14 */	add r0, r0, r6
/* 800081CC 0000512C  7C 80 00 38 */	and r0, r4, r0
/* 800081D0 00005130  54 00 10 3A */	slwi r0, r0, 2
/* 800081D4 00005134  7F E5 01 2E */	stwx r31, r5, r0
/* 800081D8 00005138  80 9E 00 1C */	lwz r4, 0x1c(r30)
/* 800081DC 0000513C  38 04 00 01 */	addi r0, r4, 1
/* 800081E0 00005140  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 800081E4 00005144  48 1F 0D C1 */	bl OSRestoreInterrupts
/* 800081E8 00005148  38 60 00 01 */	li r3, 1
.L_800081EC:
/* 800081EC 0000514C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800081F0 00005150  BB C1 00 18 */	lmw r30, 0x18(r1)
/* 800081F4 00005154  38 21 00 20 */	addi r1, r1, 0x20
/* 800081F8 00005158  7C 08 03 A6 */	mtlr r0
/* 800081FC 0000515C  4E 80 00 20 */	blr 
.endfn Jac_SendMessage__FP16Jac_MessageQueuePv

.balign 32, 0
.fn Jac_ReceiveMessage__FP16Jac_MessageQueuePPv, global
/* 80008200 00005160  7C 08 02 A6 */	mflr r0
/* 80008204 00005164  90 01 00 04 */	stw r0, 4(r1)
/* 80008208 00005168  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000820C 0000516C  BF C1 00 10 */	stmw r30, 0x10(r1)
/* 80008210 00005170  3B E3 00 00 */	addi r31, r3, 0
/* 80008214 00005174  3B C4 00 00 */	addi r30, r4, 0
/* 80008218 00005178  48 1F 0D 65 */	bl OSDisableInterrupts
/* 8000821C 0000517C  38 03 00 00 */	addi r0, r3, 0
/* 80008220 00005180  38 7F 00 00 */	addi r3, r31, 0
/* 80008224 00005184  7C 1F 03 78 */	mr r31, r0
/* 80008228 00005188  38 9E 00 00 */	addi r4, r30, 0
/* 8000822C 0000518C  48 00 00 35 */	bl Jac_ReceiveMessage_Fast__FP16Jac_MessageQueuePPv
/* 80008230 00005190  38 03 00 00 */	addi r0, r3, 0
/* 80008234 00005194  38 7F 00 00 */	addi r3, r31, 0
/* 80008238 00005198  7C 1F 03 78 */	mr r31, r0
/* 8000823C 0000519C  48 1F 0D 69 */	bl OSRestoreInterrupts
/* 80008240 000051A0  7F E3 FB 78 */	mr r3, r31
/* 80008244 000051A4  BB C1 00 10 */	lmw r30, 0x10(r1)
/* 80008248 000051A8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8000824C 000051AC  38 21 00 18 */	addi r1, r1, 0x18
/* 80008250 000051B0  7C 08 03 A6 */	mtlr r0
/* 80008254 000051B4  4E 80 00 20 */	blr 
.endfn Jac_ReceiveMessage__FP16Jac_MessageQueuePPv

.balign 32, 0
.fn Jac_ReceiveMessage_Fast__FP16Jac_MessageQueuePPv, global
/* 80008260 000051C0  48 00 00 0C */	b .L_8000826C
.L_80008264:
/* 80008264 000051C4  38 60 00 00 */	li r3, 0
/* 80008268 000051C8  4E 80 00 20 */	blr 
.L_8000826C:
/* 8000826C 000051CC  80 03 00 1C */	lwz r0, 0x1c(r3)
/* 80008270 000051D0  2C 00 00 00 */	cmpwi r0, 0
/* 80008274 000051D4  41 82 FF F0 */	beq .L_80008264
/* 80008278 000051D8  28 04 00 00 */	cmplwi r4, 0
/* 8000827C 000051DC  41 82 00 18 */	beq .L_80008294
/* 80008280 000051E0  80 03 00 18 */	lwz r0, 0x18(r3)
/* 80008284 000051E4  80 A3 00 10 */	lwz r5, 0x10(r3)
/* 80008288 000051E8  54 00 10 3A */	slwi r0, r0, 2
/* 8000828C 000051EC  7C 05 00 2E */	lwzx r0, r5, r0
/* 80008290 000051F0  90 04 00 00 */	stw r0, 0(r4)
.L_80008294:
/* 80008294 000051F4  80 A3 00 18 */	lwz r5, 0x18(r3)
/* 80008298 000051F8  80 83 00 14 */	lwz r4, 0x14(r3)
/* 8000829C 000051FC  38 A5 00 01 */	addi r5, r5, 1
/* 800082A0 00005200  38 04 FF FF */	addi r0, r4, -1
/* 800082A4 00005204  7C A0 00 38 */	and r0, r5, r0
/* 800082A8 00005208  90 03 00 18 */	stw r0, 0x18(r3)
/* 800082AC 0000520C  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 800082B0 00005210  38 04 FF FF */	addi r0, r4, -1
/* 800082B4 00005214  90 03 00 1C */	stw r0, 0x1c(r3)
/* 800082B8 00005218  38 60 00 01 */	li r3, 1
/* 800082BC 0000521C  4E 80 00 20 */	blr 
.endfn Jac_ReceiveMessage_Fast__FP16Jac_MessageQueuePPv
