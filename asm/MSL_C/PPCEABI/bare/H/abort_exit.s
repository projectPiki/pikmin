.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn exit, global
/* 8021553C 0021249C  7C 08 02 A6 */	mflr r0
/* 80215540 002124A0  90 01 00 04 */	stw r0, 4(r1)
/* 80215544 002124A4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80215548 002124A8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8021554C 002124AC  80 0D 34 78 */	lwz r0, __aborting@sda21(r13)
/* 80215550 002124B0  2C 00 00 00 */	cmpwi r0, 0
/* 80215554 002124B4  40 82 00 84 */	bne .L_802155D8
/* 80215558 002124B8  3C 60 80 3D */	lis r3, atexit_funcs@ha
/* 8021555C 002124BC  3B E3 40 F0 */	addi r31, r3, atexit_funcs@l
/* 80215560 002124C0  48 00 00 24 */	b .L_80215584
.L_80215564:
/* 80215564 002124C4  80 6D 34 7C */	lwz r3, atexit_curr_func@sda21(r13)
/* 80215568 002124C8  38 63 FF FF */	addi r3, r3, -1
/* 8021556C 002124CC  54 60 10 3A */	slwi r0, r3, 2
/* 80215570 002124D0  90 6D 34 7C */	stw r3, atexit_curr_func@sda21(r13)
/* 80215574 002124D4  7C 7F 02 14 */	add r3, r31, r0
/* 80215578 002124D8  81 83 00 00 */	lwz r12, 0(r3)
/* 8021557C 002124DC  7D 88 03 A6 */	mtlr r12
/* 80215580 002124E0  4E 80 00 21 */	blrl 
.L_80215584:
/* 80215584 002124E4  80 0D 34 7C */	lwz r0, atexit_curr_func@sda21(r13)
/* 80215588 002124E8  2C 00 00 00 */	cmpwi r0, 0
/* 8021558C 002124EC  41 81 FF D8 */	bgt .L_80215564
/* 80215590 002124F0  4B FF F3 D5 */	bl __destroy_global_chain
/* 80215594 002124F4  3C 60 80 22 */	lis r3, _dtors@ha
/* 80215598 002124F8  38 03 1F C0 */	addi r0, r3, _dtors@l
/* 8021559C 002124FC  7C 1F 03 78 */	mr r31, r0
/* 802155A0 00212500  48 00 00 10 */	b .L_802155B0
.L_802155A4:
/* 802155A4 00212504  7D 88 03 A6 */	mtlr r12
/* 802155A8 00212508  4E 80 00 21 */	blrl 
/* 802155AC 0021250C  3B FF 00 04 */	addi r31, r31, 4
.L_802155B0:
/* 802155B0 00212510  81 9F 00 00 */	lwz r12, 0(r31)
/* 802155B4 00212514  28 0C 00 00 */	cmplwi r12, 0
/* 802155B8 00212518  40 82 FF EC */	bne .L_802155A4
/* 802155BC 0021251C  81 8D 34 84 */	lwz r12, __stdio_exit@sda21(r13)
/* 802155C0 00212520  28 0C 00 00 */	cmplwi r12, 0
/* 802155C4 00212524  41 82 00 14 */	beq .L_802155D8
/* 802155C8 00212528  7D 88 03 A6 */	mtlr r12
/* 802155CC 0021252C  4E 80 00 21 */	blrl 
/* 802155D0 00212530  38 00 00 00 */	li r0, 0
/* 802155D4 00212534  90 0D 34 84 */	stw r0, __stdio_exit@sda21(r13)
.L_802155D8:
/* 802155D8 00212538  3C 60 80 3D */	lis r3, __atexit_funcs@ha
/* 802155DC 0021253C  3B E3 41 F0 */	addi r31, r3, __atexit_funcs@l
/* 802155E0 00212540  48 00 00 24 */	b .L_80215604
.L_802155E4:
/* 802155E4 00212544  80 6D 34 80 */	lwz r3, __atexit_curr_func@sda21(r13)
/* 802155E8 00212548  38 63 FF FF */	addi r3, r3, -1
/* 802155EC 0021254C  54 60 10 3A */	slwi r0, r3, 2
/* 802155F0 00212550  90 6D 34 80 */	stw r3, __atexit_curr_func@sda21(r13)
/* 802155F4 00212554  7C 7F 02 14 */	add r3, r31, r0
/* 802155F8 00212558  81 83 00 00 */	lwz r12, 0(r3)
/* 802155FC 0021255C  7D 88 03 A6 */	mtlr r12
/* 80215600 00212560  4E 80 00 21 */	blrl 
.L_80215604:
/* 80215604 00212564  80 0D 34 80 */	lwz r0, __atexit_curr_func@sda21(r13)
/* 80215608 00212568  2C 00 00 00 */	cmpwi r0, 0
/* 8021560C 0021256C  41 81 FF D8 */	bgt .L_802155E4
/* 80215610 00212570  48 00 07 A1 */	bl __kill_critical_regions
/* 80215614 00212574  81 8D 34 88 */	lwz r12, __console_exit@sda21(r13)
/* 80215618 00212578  28 0C 00 00 */	cmplwi r12, 0
/* 8021561C 0021257C  41 82 00 14 */	beq .L_80215630
/* 80215620 00212580  7D 88 03 A6 */	mtlr r12
/* 80215624 00212584  4E 80 00 21 */	blrl 
/* 80215628 00212588  38 00 00 00 */	li r0, 0
/* 8021562C 0021258C  90 0D 34 88 */	stw r0, __console_exit@sda21(r13)
.L_80215630:
/* 80215630 00212590  4B FE 84 59 */	bl _ExitProcess
/* 80215634 00212594  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80215638 00212598  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8021563C 0021259C  38 21 00 18 */	addi r1, r1, 0x18
/* 80215640 002125A0  7C 08 03 A6 */	mtlr r0
/* 80215644 002125A4  4E 80 00 20 */	blr 
.endfn exit

.section .sbss, "wa"
.balign 8
.obj __aborting, global
	.skip 0x4
.endobj __aborting
.obj atexit_curr_func, local
	.skip 0x4
.endobj atexit_curr_func
.obj __atexit_curr_func, local
	.skip 0x4
.endobj __atexit_curr_func
.obj __stdio_exit, global
	.skip 0x4
.endobj __stdio_exit
.obj __console_exit, global
	.skip 0x4
.endobj __console_exit

.section .bss, "wa"  # 0x802E9640 - 0x803E81E5
.balign 8
.obj atexit_funcs, local
	.skip 0x100
.endobj atexit_funcs
.balign 4
.obj __atexit_funcs, local
	.skip 0x100
.endobj __atexit_funcs
