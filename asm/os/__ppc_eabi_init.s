.include "macros.inc"
.section .init, "ax"  # 0x80003100 - 0x800054C0
.fn __init_hardware, global
/* 800032CC 000002CC  7C 00 00 A6 */	mfmsr r0
/* 800032D0 000002D0  60 00 20 00 */	ori r0, r0, 0x2000
/* 800032D4 000002D4  7C 00 01 24 */	mtmsr r0
/* 800032D8 000002D8  7F E8 02 A6 */	mflr r31
/* 800032DC 000002DC  48 1F 2D 99 */	bl __OSPSInit
/* 800032E0 000002E0  48 1F 3C 55 */	bl __OSCacheInit
/* 800032E4 000002E4  7F E8 03 A6 */	mtlr r31
/* 800032E8 000002E8  4E 80 00 20 */	blr 
.endfn __init_hardware

.fn __flush_cache, global
/* 800032EC 000002EC  3C A0 FF FF */	lis r5, 0xFFFFFFF1@h
/* 800032F0 000002F0  60 A5 FF F1 */	ori r5, r5, 0xFFFFFFF1@l
/* 800032F4 000002F4  7C A5 18 38 */	and r5, r5, r3
/* 800032F8 000002F8  7C 65 18 50 */	subf r3, r5, r3
/* 800032FC 000002FC  7C 84 1A 14 */	add r4, r4, r3
.L_80003300:
/* 80003300 00000300  7C 00 28 6C */	dcbst 0, r5
/* 80003304 00000304  7C 00 04 AC */	sync 0
/* 80003308 00000308  7C 00 2F AC */	icbi 0, r5
/* 8000330C 0000030C  30 A5 00 08 */	addic r5, r5, 8
/* 80003310 00000310  34 84 FF F8 */	addic. r4, r4, -8
/* 80003314 00000314  40 80 FF EC */	bge .L_80003300
/* 80003318 00000318  4C 00 01 2C */	isync 
/* 8000331C 0000031C  4E 80 00 20 */	blr 
.endfn __flush_cache

.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __init_user, global
/* 801FDA14 001FA974  7C 08 02 A6 */	mflr r0
/* 801FDA18 001FA978  90 01 00 04 */	stw r0, 4(r1)
/* 801FDA1C 001FA97C  94 21 FF F8 */	stwu r1, -8(r1)
/* 801FDA20 001FA980  48 00 00 15 */	bl __init_cpp
/* 801FDA24 001FA984  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801FDA28 001FA988  38 21 00 08 */	addi r1, r1, 8
/* 801FDA2C 001FA98C  7C 08 03 A6 */	mtlr r0
/* 801FDA30 001FA990  4E 80 00 20 */	blr 
.endfn __init_user

.fn __init_cpp, global
/* 801FDA34 001FA994  7C 08 02 A6 */	mflr r0
/* 801FDA38 001FA998  90 01 00 04 */	stw r0, 4(r1)
/* 801FDA3C 001FA99C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 801FDA40 001FA9A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 801FDA44 001FA9A4  3C 60 80 22 */	lis r3, __init_cpp_exceptions_reference@ha
/* 801FDA48 001FA9A8  38 03 1F 60 */	addi r0, r3, __init_cpp_exceptions_reference@l
/* 801FDA4C 001FA9AC  7C 1F 03 78 */	mr r31, r0
/* 801FDA50 001FA9B0  48 00 00 04 */	b .L_801FDA54
.L_801FDA54:
/* 801FDA54 001FA9B4  48 00 00 04 */	b .L_801FDA58
.L_801FDA58:
/* 801FDA58 001FA9B8  48 00 00 10 */	b .L_801FDA68
.L_801FDA5C:
/* 801FDA5C 001FA9BC  7D 88 03 A6 */	mtlr r12
/* 801FDA60 001FA9C0  4E 80 00 21 */	blrl 
/* 801FDA64 001FA9C4  3B FF 00 04 */	addi r31, r31, 4
.L_801FDA68:
/* 801FDA68 001FA9C8  81 9F 00 00 */	lwz r12, 0(r31)
/* 801FDA6C 001FA9CC  28 0C 00 00 */	cmplwi r12, 0
/* 801FDA70 001FA9D0  40 82 FF EC */	bne .L_801FDA5C
/* 801FDA74 001FA9D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801FDA78 001FA9D8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 801FDA7C 001FA9DC  38 21 00 10 */	addi r1, r1, 0x10
/* 801FDA80 001FA9E0  7C 08 03 A6 */	mtlr r0
/* 801FDA84 001FA9E4  4E 80 00 20 */	blr 
.endfn __init_cpp

.fn _ExitProcess, global
/* 801FDA88 001FA9E8  7C 08 02 A6 */	mflr r0
/* 801FDA8C 001FA9EC  90 01 00 04 */	stw r0, 4(r1)
/* 801FDA90 001FA9F0  94 21 FF F8 */	stwu r1, -8(r1)
/* 801FDA94 001FA9F4  4B FF 7E E9 */	bl PPCHalt
/* 801FDA98 001FA9F8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801FDA9C 001FA9FC  38 21 00 08 */	addi r1, r1, 8
/* 801FDAA0 001FAA00  7C 08 03 A6 */	mtlr r0
/* 801FDAA4 001FAA04  4E 80 00 20 */	blr 
.endfn _ExitProcess
