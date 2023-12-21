.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.fn DspSyncCountClear, global
/* 800062C0 00003220  90 6D 2B 44 */	stw r3, intcount@sda21(r13)
/* 800062C4 00003224  4E 80 00 20 */	blr 
.endfn DspSyncCountClear

.balign 32, 0
.fn DspSyncCountCheck, global
/* 800062E0 00003240  80 6D 2B 44 */	lwz r3, intcount@sda21(r13)
/* 800062E4 00003244  4E 80 00 20 */	blr 
.endfn DspSyncCountCheck

.balign 32, 0
.fn DspSync__Fv, local
/* 80006300 00003260  7C 08 02 A6 */	mflr r0
/* 80006304 00003264  90 01 00 04 */	stw r0, 4(r1)
/* 80006308 00003268  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000630C 0000326C  80 0D 2B 40 */	lwz r0, audioproc_mq_init@sda21(r13)
/* 80006310 00003270  28 00 00 00 */	cmplwi r0, 0
/* 80006314 00003274  41 82 00 1C */	beq .L_80006330
/* 80006318 00003278  3C 60 80 2F */	lis r3, audioproc_mq@ha
/* 8000631C 0000327C  38 80 00 01 */	li r4, 1
/* 80006320 00003280  38 63 96 60 */	addi r3, r3, audioproc_mq@l
/* 80006324 00003284  38 A0 00 00 */	li r5, 0
/* 80006328 00003288  48 1F 34 ED */	bl OSSendMessage
/* 8000632C 0000328C  48 00 00 08 */	b .L_80006334
.L_80006330:
/* 80006330 00003290  48 00 24 51 */	bl DSPReleaseHalt__Fv
.L_80006334:
/* 80006334 00003294  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80006338 00003298  38 21 00 08 */	addi r1, r1, 8
/* 8000633C 0000329C  7C 08 03 A6 */	mtlr r0
/* 80006340 000032A0  4E 80 00 20 */	blr 
.endfn DspSync__Fv

.balign 32, 0
.fn StopAudioThread, global
/* 80006360 000032C0  7C 08 02 A6 */	mflr r0
/* 80006364 000032C4  90 01 00 04 */	stw r0, 4(r1)
/* 80006368 000032C8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000636C 000032CC  80 0D 2B 40 */	lwz r0, audioproc_mq_init@sda21(r13)
/* 80006370 000032D0  28 00 00 00 */	cmplwi r0, 0
/* 80006374 000032D4  41 82 00 2C */	beq .L_800063A0
/* 80006378 000032D8  3C 60 80 2F */	lis r3, audioproc_mq@ha
/* 8000637C 000032DC  38 80 00 03 */	li r4, 3
/* 80006380 000032E0  38 63 96 60 */	addi r3, r3, audioproc_mq@l
/* 80006384 000032E4  38 A0 00 00 */	li r5, 0
/* 80006388 000032E8  48 1F 34 8D */	bl OSSendMessage
/* 8000638C 000032EC  2C 03 00 00 */	cmpwi r3, 0
/* 80006390 000032F0  40 82 00 10 */	bne .L_800063A0
/* 80006394 000032F4  3C 60 80 3D */	lis r3, jac_audioThread@ha
/* 80006398 000032F8  38 63 62 C0 */	addi r3, r3, jac_audioThread@l
/* 8000639C 000032FC  48 1F 5F 2D */	bl OSCancelThread
.L_800063A0:
/* 800063A0 00003300  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800063A4 00003304  38 21 00 08 */	addi r1, r1, 8
/* 800063A8 00003308  7C 08 03 A6 */	mtlr r0
/* 800063AC 0000330C  4E 80 00 20 */	blr 
.endfn StopAudioThread

.balign 32, 0
.fn AudioSync__Fv, local
/* 800063C0 00003320  7C 08 02 A6 */	mflr r0
/* 800063C4 00003324  90 01 00 04 */	stw r0, 4(r1)
/* 800063C8 00003328  94 21 FF F8 */	stwu r1, -8(r1)
/* 800063CC 0000332C  88 0D 2B 4C */	lbz r0, init$71@sda21(r13)
/* 800063D0 00003330  7C 00 07 75 */	extsb. r0, r0
/* 800063D4 00003334  40 82 00 10 */	bne .L_800063E4
/* 800063D8 00003338  38 00 00 01 */	li r0, 1
/* 800063DC 0000333C  90 0D 2B 48 */	stw r0, first$70@sda21(r13)
/* 800063E0 00003340  98 0D 2B 4C */	stb r0, init$71@sda21(r13)
.L_800063E4:
/* 800063E4 00003344  80 0D 2B 48 */	lwz r0, first$70@sda21(r13)
/* 800063E8 00003348  2C 00 00 00 */	cmpwi r0, 0
/* 800063EC 0000334C  40 82 00 0C */	bne .L_800063F8
/* 800063F0 00003350  38 60 00 04 */	li r3, 4
/* 800063F4 00003354  4B FF F2 2D */	bl Probe_Finish
.L_800063F8:
/* 800063F8 00003358  38 00 00 00 */	li r0, 0
/* 800063FC 0000335C  3C 60 80 22 */	lis r3, lbl_80221FF8@ha
/* 80006400 00003360  90 0D 2B 48 */	stw r0, first$70@sda21(r13)
/* 80006404 00003364  38 83 1F F8 */	addi r4, r3, lbl_80221FF8@l
/* 80006408 00003368  38 60 00 04 */	li r3, 4
/* 8000640C 0000336C  4B FF F1 F5 */	bl Probe_Start
/* 80006410 00003370  80 0D 2B 40 */	lwz r0, audioproc_mq_init@sda21(r13)
/* 80006414 00003374  28 00 00 00 */	cmplwi r0, 0
/* 80006418 00003378  41 82 00 18 */	beq .L_80006430
/* 8000641C 0000337C  3C 60 80 2F */	lis r3, audioproc_mq@ha
/* 80006420 00003380  38 80 00 00 */	li r4, 0
/* 80006424 00003384  38 63 96 60 */	addi r3, r3, audioproc_mq@l
/* 80006428 00003388  38 A0 00 00 */	li r5, 0
/* 8000642C 0000338C  48 1F 33 E9 */	bl OSSendMessage
.L_80006430:
/* 80006430 00003390  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80006434 00003394  38 21 00 08 */	addi r1, r1, 8
/* 80006438 00003398  7C 08 03 A6 */	mtlr r0
/* 8000643C 0000339C  4E 80 00 20 */	blr 
.endfn AudioSync__Fv

.balign 32, 0
.fn __DspSync__FsP9OSContext, local
/* 80006440 000033A0  7C 08 02 A6 */	mflr r0
/* 80006444 000033A4  3C 60 CC 00 */	lis r3, 0xCC005000@ha
/* 80006448 000033A8  90 01 00 04 */	stw r0, 4(r1)
/* 8000644C 000033AC  38 A3 50 00 */	addi r5, r3, 0xCC005000@l
/* 80006450 000033B0  38 00 FF D7 */	li r0, -41
/* 80006454 000033B4  94 21 FD 20 */	stwu r1, -0x2e0(r1)
/* 80006458 000033B8  93 E1 02 DC */	stw r31, 0x2dc(r1)
/* 8000645C 000033BC  3B E4 00 00 */	addi r31, r4, 0
/* 80006460 000033C0  38 61 00 10 */	addi r3, r1, 0x10
/* 80006464 000033C4  A0 85 00 0A */	lhz r4, 0xa(r5)
/* 80006468 000033C8  7C 80 00 38 */	and r0, r4, r0
/* 8000646C 000033CC  60 00 00 80 */	ori r0, r0, 0x80
/* 80006470 000033D0  B0 05 00 0A */	sth r0, 0xa(r5)
/* 80006474 000033D4  48 1F 0F C9 */	bl OSClearContext
/* 80006478 000033D8  38 61 00 10 */	addi r3, r1, 0x10
/* 8000647C 000033DC  48 1F 0D F9 */	bl OSSetCurrentContext
/* 80006480 000033E0  4B FF FE 81 */	bl DspSync__Fv
/* 80006484 000033E4  38 61 00 10 */	addi r3, r1, 0x10
/* 80006488 000033E8  48 1F 0F B5 */	bl OSClearContext
/* 8000648C 000033EC  7F E3 FB 78 */	mr r3, r31
/* 80006490 000033F0  48 1F 0D E5 */	bl OSSetCurrentContext
/* 80006494 000033F4  80 01 02 E4 */	lwz r0, 0x2e4(r1)
/* 80006498 000033F8  83 E1 02 DC */	lwz r31, 0x2dc(r1)
/* 8000649C 000033FC  38 21 02 E0 */	addi r1, r1, 0x2e0
/* 800064A0 00003400  7C 08 03 A6 */	mtlr r0
/* 800064A4 00003404  4E 80 00 20 */	blr 
.endfn __DspSync__FsP9OSContext

.balign 32, 0
.fn __DspReg__Fv, local
/* 800064C0 00003420  7C 08 02 A6 */	mflr r0
/* 800064C4 00003424  90 01 00 04 */	stw r0, 4(r1)
/* 800064C8 00003428  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800064CC 0000342C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800064D0 00003430  48 1F 2A AD */	bl OSDisableInterrupts
/* 800064D4 00003434  3C 80 80 00 */	lis r4, __DspSync__FsP9OSContext@ha
/* 800064D8 00003438  3B E3 00 00 */	addi r31, r3, 0
/* 800064DC 0000343C  38 84 64 40 */	addi r4, r4, __DspSync__FsP9OSContext@l
/* 800064E0 00003440  38 60 00 07 */	li r3, 7
/* 800064E4 00003444  48 1F 2A E5 */	bl __OSSetInterruptHandler
/* 800064E8 00003448  7F E3 FB 78 */	mr r3, r31
/* 800064EC 0000344C  48 1F 2A B9 */	bl OSRestoreInterrupts
/* 800064F0 00003450  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800064F4 00003454  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800064F8 00003458  38 21 00 10 */	addi r1, r1, 0x10
/* 800064FC 0000345C  7C 08 03 A6 */	mtlr r0
/* 80006500 00003460  4E 80 00 20 */	blr 
.endfn __DspReg__Fv

.balign 32, 0
.fn audioproc__FPv, local
/* 80006520 00003480  7C 08 02 A6 */	mflr r0
/* 80006524 00003484  3C 60 80 2F */	lis r3, audioproc_mq@ha
/* 80006528 00003488  90 01 00 04 */	stw r0, 4(r1)
/* 8000652C 0000348C  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80006530 00003490  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80006534 00003494  3B E3 96 60 */	addi r31, r3, audioproc_mq@l
/* 80006538 00003498  48 00 01 29 */	bl OSInitFastCast
/* 8000653C 0000349C  38 7F 00 00 */	addi r3, r31, 0
/* 80006540 000034A0  38 9F 00 20 */	addi r4, r31, 0x20
/* 80006544 000034A4  38 A0 00 10 */	li r5, 0x10
/* 80006548 000034A8  48 1F 32 6D */	bl OSInitMessageQueue
/* 8000654C 000034AC  38 00 00 01 */	li r0, 1
/* 80006550 000034B0  90 0D 2B 40 */	stw r0, audioproc_mq_init@sda21(r13)
/* 80006554 000034B4  4B FF F2 AD */	bl Jac_Init
/* 80006558 000034B8  48 00 77 A9 */	bl Jac_InitSinTable__Fv
/* 8000655C 000034BC  48 00 0B C5 */	bl ResetPlayerCallback
/* 80006560 000034C0  38 60 00 00 */	li r3, 0
/* 80006564 000034C4  48 00 06 3D */	bl DspbufProcess__F13DSPBUF_EVENTS
/* 80006568 000034C8  38 60 00 00 */	li r3, 0
/* 8000656C 000034CC  48 00 09 75 */	bl CpubufProcess__F13DSPBUF_EVENTS
/* 80006570 000034D0  48 00 20 D1 */	bl DspBoot__Fv
/* 80006574 000034D4  48 00 56 ED */	bl DSP_InitBuffer__Fv
/* 80006578 000034D8  4B FF FF 49 */	bl __DspReg__Fv
/* 8000657C 000034DC  80 6D 2B C0 */	lwz r3, JAC_AI_SETTING@sda21(r13)
/* 80006580 000034E0  48 1F FC 89 */	bl AISetDSPSampleRate
/* 80006584 000034E4  3C 60 80 00 */	lis r3, AudioSync__Fv@ha
/* 80006588 000034E8  38 63 63 C0 */	addi r3, r3, AudioSync__Fv@l
/* 8000658C 000034EC  48 1F FA 79 */	bl AIRegisterDMACallback
/* 80006590 000034F0  48 1F FB 41 */	bl AIStartDMA
.L_80006594:
/* 80006594 000034F4  38 7F 00 00 */	addi r3, r31, 0
/* 80006598 000034F8  38 81 00 18 */	addi r4, r1, 0x18
/* 8000659C 000034FC  38 A0 00 01 */	li r5, 1
/* 800065A0 00003500  48 1F 33 3D */	bl OSReceiveMessage
/* 800065A4 00003504  80 01 00 18 */	lwz r0, 0x18(r1)
/* 800065A8 00003508  2C 00 00 02 */	cmpwi r0, 2
/* 800065AC 0000350C  41 82 00 7C */	beq .L_80006628
/* 800065B0 00003510  40 80 00 14 */	bge .L_800065C4
/* 800065B4 00003514  2C 00 00 00 */	cmpwi r0, 0
/* 800065B8 00003518  41 82 00 18 */	beq .L_800065D0
/* 800065BC 0000351C  40 80 00 1C */	bge .L_800065D8
/* 800065C0 00003520  4B FF FF D4 */	b .L_80006594
.L_800065C4:
/* 800065C4 00003524  2C 00 00 04 */	cmpwi r0, 4
/* 800065C8 00003528  40 80 FF CC */	bge .L_80006594
/* 800065CC 0000352C  48 00 00 64 */	b .L_80006630
.L_800065D0:
/* 800065D0 00003530  4B FF F7 F1 */	bl Jac_UpdateDAC
/* 800065D4 00003534  4B FF FF C0 */	b .L_80006594
.L_800065D8:
/* 800065D8 00003538  80 0D 2B 44 */	lwz r0, intcount@sda21(r13)
/* 800065DC 0000353C  2C 00 00 00 */	cmpwi r0, 0
/* 800065E0 00003540  41 82 00 5C */	beq .L_8000663C
/* 800065E4 00003544  80 6D 2B 44 */	lwz r3, intcount@sda21(r13)
/* 800065E8 00003548  38 03 FF FF */	addi r0, r3, -1
/* 800065EC 0000354C  90 0D 2B 44 */	stw r0, intcount@sda21(r13)
/* 800065F0 00003550  80 0D 2B 44 */	lwz r0, intcount@sda21(r13)
/* 800065F4 00003554  2C 00 00 00 */	cmpwi r0, 0
/* 800065F8 00003558  40 82 00 14 */	bne .L_8000660C
/* 800065FC 0000355C  38 60 00 07 */	li r3, 7
/* 80006600 00003560  4B FF F0 21 */	bl Probe_Finish
/* 80006604 00003564  48 00 08 9D */	bl DspFrameEnd__Fv
/* 80006608 00003568  4B FF FF 8C */	b .L_80006594
.L_8000660C:
/* 8000660C 0000356C  38 60 00 02 */	li r3, 2
/* 80006610 00003570  38 82 80 10 */	addi r4, r2, lbl_803E8210@sda21
/* 80006614 00003574  4B FF EF ED */	bl Probe_Start
/* 80006618 00003578  48 00 07 E9 */	bl UpdateDSP__Fv
/* 8000661C 0000357C  38 60 00 02 */	li r3, 2
/* 80006620 00003580  4B FF F0 01 */	bl Probe_Finish
/* 80006624 00003584  4B FF FF 70 */	b .L_80006594
.L_80006628:
/* 80006628 00003588  48 00 0A B9 */	bl CpuFrameEnd__Fv
/* 8000662C 0000358C  4B FF FF 68 */	b .L_80006594
.L_80006630:
/* 80006630 00003590  38 60 00 00 */	li r3, 0
/* 80006634 00003594  48 1F 5B B1 */	bl OSExitThread
/* 80006638 00003598  4B FF FF 5C */	b .L_80006594
.L_8000663C:
/* 8000663C 0000359C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80006640 000035A0  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80006644 000035A4  38 21 00 28 */	addi r1, r1, 0x28
/* 80006648 000035A8  7C 08 03 A6 */	mtlr r0
/* 8000664C 000035AC  4E 80 00 20 */	blr 
.endfn audioproc__FPv

.balign 32, 0
.fn OSInitFastCast, local
/* 80006660 000035C0  38 60 00 04 */	li r3, 4
/* 80006664 000035C4  64 63 00 04 */	oris r3, r3, 4
/* 80006668 000035C8  7C 72 E3 A6 */	mtspr GQR2, r3
/* 8000666C 000035CC  38 60 00 05 */	li r3, 5
/* 80006670 000035D0  64 63 00 05 */	oris r3, r3, 5
/* 80006674 000035D4  7C 73 E3 A6 */	mtspr GQR3, r3
/* 80006678 000035D8  38 60 00 06 */	li r3, 6
/* 8000667C 000035DC  64 63 00 06 */	oris r3, r3, 6
/* 80006680 000035E0  7C 74 E3 A6 */	mtspr GQR4, r3
/* 80006684 000035E4  38 60 00 07 */	li r3, 7
/* 80006688 000035E8  64 63 00 07 */	oris r3, r3, 7
/* 8000668C 000035EC  7C 75 E3 A6 */	mtspr GQR5, r3
/* 80006690 000035F0  4E 80 00 20 */	blr 
.endfn OSInitFastCast

.balign 32, 0
.fn StartAudioThread, global
/* 800066A0 00003600  7C 08 02 A6 */	mflr r0
/* 800066A4 00003604  90 01 00 04 */	stw r0, 4(r1)
/* 800066A8 00003608  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800066AC 0000360C  BF 81 00 20 */	stmw r28, 0x20(r1)
/* 800066B0 00003610  3B 83 00 00 */	addi r28, r3, 0
/* 800066B4 00003614  3B E4 00 00 */	addi r31, r4, 0
/* 800066B8 00003618  3B C5 00 00 */	addi r30, r5, 0
/* 800066BC 0000361C  3B A6 00 00 */	addi r29, r6, 0
/* 800066C0 00003620  80 0D 2B 50 */	lwz r0, priority_set@sda21(r13)
/* 800066C4 00003624  2C 00 00 00 */	cmpwi r0, 0
/* 800066C8 00003628  40 82 00 28 */	bne .L_800066F0
/* 800066CC 0000362C  48 1F 54 19 */	bl OSGetCurrentThread
/* 800066D0 00003630  48 1F 64 DD */	bl OSGetThreadPriority
/* 800066D4 00003634  38 03 FF FD */	addi r0, r3, -3
/* 800066D8 00003638  90 0D 2B 54 */	stw r0, pri@sda21(r13)
/* 800066DC 0000363C  80 8D 2B 54 */	lwz r4, pri@sda21(r13)
/* 800066E0 00003640  38 64 00 01 */	addi r3, r4, 1
/* 800066E4 00003644  38 04 00 02 */	addi r0, r4, 2
/* 800066E8 00003648  90 6D 2B 5C */	stw r3, pri3@sda21(r13)
/* 800066EC 0000364C  90 0D 2B 58 */	stw r0, pri2@sda21(r13)
.L_800066F0:
/* 800066F0 00003650  38 7C 00 00 */	addi r3, r28, 0
/* 800066F4 00003654  38 9F 00 00 */	addi r4, r31, 0
/* 800066F8 00003658  4B FF F0 29 */	bl Jac_HeapSetup
/* 800066FC 0000365C  7F C3 F3 78 */	mr r3, r30
/* 80006700 00003660  4B FF FA A1 */	bl Jac_SetAudioARAMSize__FUl
/* 80006704 00003664  57 A3 07 7A */	rlwinm r3, r29, 0, 0x1d, 0x1d
/* 80006708 00003668  4B FF FB 19 */	bl Jac_InitARAM__FUl
/* 8000670C 0000366C  3C 60 80 3E */	lis r3, jac_audioStack@ha
/* 80006710 00003670  38 80 02 00 */	li r4, 0x200
/* 80006714 00003674  3B E3 8C 00 */	addi r31, r3, jac_audioStack@l
/* 80006718 00003678  38 7F 00 00 */	addi r3, r31, 0
/* 8000671C 0000367C  48 00 1B A5 */	bl Jac_StackInit
/* 80006720 00003680  57 A0 07 BD */	rlwinm. r0, r29, 0, 0x1e, 0x1e
/* 80006724 00003684  41 82 00 38 */	beq .L_8000675C
/* 80006728 00003688  3C 80 80 3D */	lis r4, jac_audioThread@ha
/* 8000672C 0000368C  3C 60 80 00 */	lis r3, audioproc__FPv@ha
/* 80006730 00003690  3B C4 62 C0 */	addi r30, r4, jac_audioThread@l
/* 80006734 00003694  81 0D 2B 54 */	lwz r8, pri@sda21(r13)
/* 80006738 00003698  38 83 65 20 */	addi r4, r3, audioproc__FPv@l
/* 8000673C 0000369C  38 7E 00 00 */	addi r3, r30, 0
/* 80006740 000036A0  38 DF 10 00 */	addi r6, r31, 0x1000
/* 80006744 000036A4  38 A0 00 00 */	li r5, 0
/* 80006748 000036A8  38 E0 10 00 */	li r7, 0x1000
/* 8000674C 000036AC  39 20 00 01 */	li r9, 1
/* 80006750 000036B0  48 1F 59 75 */	bl OSCreateThread
/* 80006754 000036B4  7F C3 F3 78 */	mr r3, r30
/* 80006758 000036B8  48 1F 5E 6D */	bl OSResumeThread
.L_8000675C:
/* 8000675C 000036BC  3C 60 80 3E */	lis r3, jac_dvdStack@ha
/* 80006760 000036C0  38 80 02 00 */	li r4, 0x200
/* 80006764 000036C4  3B C3 9F 20 */	addi r30, r3, jac_dvdStack@l
/* 80006768 000036C8  38 7E 00 00 */	addi r3, r30, 0
/* 8000676C 000036CC  48 00 1B 55 */	bl Jac_StackInit
/* 80006770 000036D0  57 A0 07 FF */	clrlwi. r0, r29, 0x1f
/* 80006774 000036D4  41 82 00 3C */	beq .L_800067B0
/* 80006778 000036D8  48 00 0E C9 */	bl jac_dvdproc_init__Fv
/* 8000677C 000036DC  3C 80 80 3E */	lis r4, jac_dvdThread@ha
/* 80006780 000036E0  3C 60 80 00 */	lis r3, jac_dvdproc__FPv@ha
/* 80006784 000036E4  3B E4 9C 00 */	addi r31, r4, jac_dvdThread@l
/* 80006788 000036E8  81 0D 2B 5C */	lwz r8, pri3@sda21(r13)
/* 8000678C 000036EC  38 83 76 80 */	addi r4, r3, jac_dvdproc__FPv@l
/* 80006790 000036F0  38 7F 00 00 */	addi r3, r31, 0
/* 80006794 000036F4  38 DE 10 00 */	addi r6, r30, 0x1000
/* 80006798 000036F8  38 A0 00 00 */	li r5, 0
/* 8000679C 000036FC  38 E0 10 00 */	li r7, 0x1000
/* 800067A0 00003700  39 20 00 01 */	li r9, 1
/* 800067A4 00003704  48 1F 59 21 */	bl OSCreateThread
/* 800067A8 00003708  7F E3 FB 78 */	mr r3, r31
/* 800067AC 0000370C  48 1F 5E 19 */	bl OSResumeThread
.L_800067B0:
/* 800067B0 00003710  BB 81 00 20 */	lmw r28, 0x20(r1)
/* 800067B4 00003714  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800067B8 00003718  38 21 00 30 */	addi r1, r1, 0x30
/* 800067BC 0000371C  7C 08 03 A6 */	mtlr r0
/* 800067C0 00003720  4E 80 00 20 */	blr 
.endfn StartAudioThread

.section .rodata, "a"  # 0x80221FE0 - 0x80222DC0
.balign 8
.obj lbl_80221FF8, local
	.asciz "UPDATE-DAC"
.endobj lbl_80221FF8

.section .sbss, "wa"
.balign 8
.obj audioproc_mq_init, local
	.skip 4
.endobj audioproc_mq_init
.obj intcount, local
	.skip 4
.endobj intcount
.obj first$70, local
	.skip 4
.endobj first$70
.obj init$71, local
	.skip 1
.endobj init$71
.balign 4
.obj priority_set, local
	.skip 4
.endobj priority_set
.obj pri, local
	.skip 4
.endobj pri
.obj pri2, local
	.skip 4
.endobj pri2
.obj pri3, local
	.skip 4
.endobj pri3

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E8210, local
	.asciz "SFR_DSP"
.endobj lbl_803E8210

.section .bss, "wa"  # 0x802E9640 - 0x803E81E5
.balign 8
.obj audioproc_mq, local
	.skip 0x20
.endobj audioproc_mq
.balign 4
.obj msgbuf, local
	.skip 0x40
.endobj msgbuf

.comm jac_audioThread, 0x2940, 32
.comm jac_audioStack, 0x1000, 32
.comm jac_dvdThread, 0x310, 8
# .comm jac_dvdStack, 0x1000, 32 # keeps wanting to be placed before jac_dvdThread
