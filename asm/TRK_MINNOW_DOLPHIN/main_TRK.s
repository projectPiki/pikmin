.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn TRK_main, global
/* 80220418 0021D378  7C 08 02 A6 */	mflr r0
/* 8022041C 0021D37C  90 01 00 04 */	stw r0, 4(r1)
/* 80220420 0021D380  94 21 FF F8 */	stwu r1, -8(r1)
/* 80220424 0021D384  4B FF BE ED */	bl TRKInitializeNub
/* 80220428 0021D388  3C 80 80 3D */	lis r4, TRK_mainError@ha
/* 8022042C 0021D38C  94 64 62 78 */	stwu r3, TRK_mainError@l(r4)
/* 80220430 0021D390  80 04 00 00 */	lwz r0, 0(r4)
/* 80220434 0021D394  2C 00 00 00 */	cmpwi r0, 0
/* 80220438 0021D398  40 82 00 0C */	bne .L_80220444
/* 8022043C 0021D39C  4B FF BF CD */	bl TRKNubWelcome
/* 80220440 0021D3A0  4B FF BB 81 */	bl TRKNubMainLoop
.L_80220444:
/* 80220444 0021D3A4  4B FF BF A1 */	bl TRKTerminateNub
/* 80220448 0021D3A8  3C 80 80 3D */	lis r4, TRK_mainError@ha
/* 8022044C 0021D3AC  90 64 62 78 */	stw r3, TRK_mainError@l(r4)
/* 80220450 0021D3B0  38 21 00 08 */	addi r1, r1, 8
/* 80220454 0021D3B4  80 01 00 04 */	lwz r0, 4(r1)
/* 80220458 0021D3B8  7C 08 03 A6 */	mtlr r0
/* 8022045C 0021D3BC  4E 80 00 20 */	blr 
.endfn TRK_main

.section .bss, "wa"  # 0x802E9640 - 0x803E81E5
.balign 8
.obj TRK_mainError, local
	.skip 0x4
.endobj TRK_mainError
