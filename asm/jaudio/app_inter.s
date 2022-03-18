.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.global Jac_StreamMovieInit
Jac_StreamMovieInit:
/* 80017460 000143C0  7C 08 02 A6 */	mflr r0
/* 80017464 000143C4  90 01 00 04 */	stw r0, 4(r1)
/* 80017468 000143C8  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8001746C 000143CC  BF A1 00 1C */	stmw r29, 0x1c(r1)
/* 80017470 000143D0  3B A3 00 00 */	addi r29, r3, 0
/* 80017474 000143D4  3B C4 00 00 */	addi r30, r4, 0
/* 80017478 000143D8  3B E5 00 00 */	addi r31, r5, 0
/* 8001747C 000143DC  48 00 23 C5 */	bl Jac_GetCurrentScene
/* 80017480 000143E0  28 03 00 01 */	cmplwi r3, 1
/* 80017484 000143E4  40 82 00 24 */	bne lbl_800174A8
/* 80017488 000143E8  80 0D 2C 78 */	lwz r0, demo_fade_flag@sda21(r13)
/* 8001748C 000143EC  2C 00 00 00 */	cmpwi r0, 0
/* 80017490 000143F0  40 82 00 18 */	bne lbl_800174A8
/* 80017494 000143F4  38 60 00 01 */	li r3, 1
/* 80017498 000143F8  38 80 00 32 */	li r4, 0x32
/* 8001749C 000143FC  48 00 20 65 */	bl Jac_EasyCrossFade
/* 800174A0 00014400  38 00 00 01 */	li r0, 1
/* 800174A4 00014404  90 0D 2C 78 */	stw r0, demo_fade_flag@sda21(r13)
lbl_800174A8:
/* 800174A8 00014408  38 7D 00 00 */	addi r3, r29, 0
/* 800174AC 0001440C  38 9E 00 00 */	addi r4, r30, 0
/* 800174B0 00014410  38 BF 00 00 */	addi r5, r31, 0
/* 800174B4 00014414  48 00 6B 6D */	bl Jac_HVQM_Init
/* 800174B8 00014418  48 00 29 49 */	bl Jac_UpdateStreamLevel
/* 800174BC 0001441C  BB A1 00 1C */	lmw r29, 0x1c(r1)
/* 800174C0 00014420  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800174C4 00014424  38 21 00 28 */	addi r1, r1, 0x28
/* 800174C8 00014428  7C 08 03 A6 */	mtlr r0
/* 800174CC 0001442C  4E 80 00 20 */	blr 

.balign 32, 0
.global Jac_StreamMovieStop
Jac_StreamMovieStop:
/* 800174E0 00014440  7C 08 02 A6 */	mflr r0
/* 800174E4 00014444  90 01 00 04 */	stw r0, 4(r1)
/* 800174E8 00014448  94 21 FF F8 */	stwu r1, -8(r1)
/* 800174EC 0001444C  48 00 72 F5 */	bl Jac_HVQM_ForceStop
/* 800174F0 00014450  48 00 23 51 */	bl Jac_GetCurrentScene
/* 800174F4 00014454  28 03 00 01 */	cmplwi r3, 1
/* 800174F8 00014458  40 82 00 24 */	bne lbl_8001751C
/* 800174FC 0001445C  80 0D 2C 78 */	lwz r0, demo_fade_flag@sda21(r13)
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

.balign 32, 0
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

.balign 32, 0
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

.section .sbss, "wa"
.balign 8
demo_fade_flag:
	.skip 4
