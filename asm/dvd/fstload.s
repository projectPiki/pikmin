.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn cb, local
/* 80202254 001FF1B4  7C 08 02 A6 */	mflr r0
/* 80202258 001FF1B8  2C 03 00 00 */	cmpwi r3, 0
/* 8020225C 001FF1BC  90 01 00 04 */	stw r0, 4(r1)
/* 80202260 001FF1C0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80202264 001FF1C4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80202268 001FF1C8  3B E4 00 00 */	addi r31, r4, 0
/* 8020226C 001FF1CC  40 81 00 7C */	ble .L_802022E8
/* 80202270 001FF1D0  80 0D 33 00 */	lwz r0, status@sda21(r13)
/* 80202274 001FF1D4  2C 00 00 01 */	cmpwi r0, 1
/* 80202278 001FF1D8  41 82 00 3C */	beq .L_802022B4
/* 8020227C 001FF1DC  40 80 00 9C */	bge .L_80202318
/* 80202280 001FF1E0  2C 00 00 00 */	cmpwi r0, 0
/* 80202284 001FF1E4  40 80 00 08 */	bge .L_8020228C
/* 80202288 001FF1E8  48 00 00 90 */	b .L_80202318
.L_8020228C:
/* 8020228C 001FF1EC  38 00 00 01 */	li r0, 1
/* 80202290 001FF1F0  80 8D 33 04 */	lwz r4, bb2@sda21(r13)
/* 80202294 001FF1F4  3C 60 80 20 */	lis r3, cb@ha
/* 80202298 001FF1F8  90 0D 33 00 */	stw r0, status@sda21(r13)
/* 8020229C 001FF1FC  38 E3 22 54 */	addi r7, r3, cb@l
/* 802022A0 001FF200  38 7F 00 00 */	addi r3, r31, 0
/* 802022A4 001FF204  38 A0 00 20 */	li r5, 0x20
/* 802022A8 001FF208  38 C0 04 20 */	li r6, 0x420
/* 802022AC 001FF20C  4B FF F2 F1 */	bl DVDReadAbsAsyncForBS
/* 802022B0 001FF210  48 00 00 68 */	b .L_80202318
.L_802022B4:
/* 802022B4 001FF214  38 00 00 02 */	li r0, 2
/* 802022B8 001FF218  80 CD 33 04 */	lwz r6, bb2@sda21(r13)
/* 802022BC 001FF21C  90 0D 33 00 */	stw r0, status@sda21(r13)
/* 802022C0 001FF220  3C 60 80 20 */	lis r3, cb@ha
/* 802022C4 001FF224  38 E3 22 54 */	addi r7, r3, cb@l
/* 802022C8 001FF228  80 A6 00 08 */	lwz r5, 8(r6)
/* 802022CC 001FF22C  7F E3 FB 78 */	mr r3, r31
/* 802022D0 001FF230  80 86 00 10 */	lwz r4, 0x10(r6)
/* 802022D4 001FF234  38 05 00 1F */	addi r0, r5, 0x1f
/* 802022D8 001FF238  80 C6 00 04 */	lwz r6, 4(r6)
/* 802022DC 001FF23C  54 05 00 34 */	rlwinm r5, r0, 0, 0, 0x1a
/* 802022E0 001FF240  4B FF F2 BD */	bl DVDReadAbsAsyncForBS
/* 802022E4 001FF244  48 00 00 34 */	b .L_80202318
.L_802022E8:
/* 802022E8 001FF248  2C 03 FF FF */	cmpwi r3, -1
/* 802022EC 001FF24C  41 82 00 2C */	beq .L_80202318
/* 802022F0 001FF250  2C 03 FF FC */	cmpwi r3, -4
/* 802022F4 001FF254  40 82 00 24 */	bne .L_80202318
/* 802022F8 001FF258  38 00 00 00 */	li r0, 0
/* 802022FC 001FF25C  90 0D 33 00 */	stw r0, status@sda21(r13)
/* 80202300 001FF260  4B FF F5 CD */	bl DVDReset
/* 80202304 001FF264  3C 60 80 20 */	lis r3, cb@ha
/* 80202308 001FF268  80 8D 33 08 */	lwz r4, idTmp@sda21(r13)
/* 8020230C 001FF26C  38 A3 22 54 */	addi r5, r3, cb@l
/* 80202310 001FF270  38 7F 00 00 */	addi r3, r31, 0
/* 80202314 001FF274  4B FF F3 59 */	bl DVDReadDiskID
.L_80202318:
/* 80202318 001FF278  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8020231C 001FF27C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80202320 001FF280  38 21 00 18 */	addi r1, r1, 0x18
/* 80202324 001FF284  7C 08 03 A6 */	mtlr r0
/* 80202328 001FF288  4E 80 00 20 */	blr 
.endfn cb

.fn __fstLoad, global
/* 8020232C 001FF28C  7C 08 02 A6 */	mflr r0
/* 80202330 001FF290  3C 60 80 2F */	lis r3, lbl_802E8970@ha
/* 80202334 001FF294  90 01 00 04 */	stw r0, 4(r1)
/* 80202338 001FF298  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8020233C 001FF29C  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 80202340 001FF2A0  3B E3 89 70 */	addi r31, r3, lbl_802E8970@l
/* 80202344 001FF2A4  93 C1 00 58 */	stw r30, 0x58(r1)
/* 80202348 001FF2A8  93 A1 00 54 */	stw r29, 0x54(r1)
/* 8020234C 001FF2AC  4B FF 45 CD */	bl OSGetArenaHi
/* 80202350 001FF2B0  3C 60 80 3D */	lis r3, bb2Buf@ha
/* 80202354 001FF2B4  38 63 31 F8 */	addi r3, r3, bb2Buf@l
/* 80202358 001FF2B8  38 81 00 2B */	addi r4, r1, 0x2b
/* 8020235C 001FF2BC  38 03 00 1F */	addi r0, r3, 0x1f
/* 80202360 001FF2C0  54 83 00 34 */	rlwinm r3, r4, 0, 0, 0x1a
/* 80202364 001FF2C4  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80202368 001FF2C8  90 6D 33 08 */	stw r3, idTmp@sda21(r13)
/* 8020236C 001FF2CC  90 0D 33 04 */	stw r0, bb2@sda21(r13)
/* 80202370 001FF2D0  4B FF F5 5D */	bl DVDReset
/* 80202374 001FF2D4  3C 60 80 3D */	lis r3, block$16@ha
/* 80202378 001FF2D8  80 8D 33 08 */	lwz r4, idTmp@sda21(r13)
/* 8020237C 001FF2DC  3C A0 80 20 */	lis r5, cb@ha
/* 80202380 001FF2E0  38 63 32 38 */	addi r3, r3, block$16@l
/* 80202384 001FF2E4  38 A5 22 54 */	addi r5, r5, cb@l
/* 80202388 001FF2E8  4B FF F2 E5 */	bl DVDReadDiskID
.L_8020238C:
/* 8020238C 001FF2EC  4B FF F5 85 */	bl DVDGetDriveStatus
/* 80202390 001FF2F0  2C 03 00 00 */	cmpwi r3, 0
/* 80202394 001FF2F4  40 82 FF F8 */	bne .L_8020238C
/* 80202398 001FF2F8  80 6D 33 04 */	lwz r3, bb2@sda21(r13)
/* 8020239C 001FF2FC  3F A0 80 00 */	lis r29, 0x80000000@ha
/* 802023A0 001FF300  3F C0 80 00 */	lis r30, 0x80000038@ha
/* 802023A4 001FF304  80 03 00 10 */	lwz r0, 0x10(r3)
/* 802023A8 001FF308  38 7D 00 00 */	addi r3, r29, 0x80000000@l
/* 802023AC 001FF30C  38 A0 00 20 */	li r5, 0x20
/* 802023B0 001FF310  90 1E 00 38 */	stw r0, 0x80000038@l(r30)
/* 802023B4 001FF314  80 8D 33 04 */	lwz r4, bb2@sda21(r13)
/* 802023B8 001FF318  80 04 00 0C */	lwz r0, 0xc(r4)
/* 802023BC 001FF31C  90 1E 00 3C */	stw r0, 0x3c(r30)
/* 802023C0 001FF320  80 8D 33 08 */	lwz r4, idTmp@sda21(r13)
/* 802023C4 001FF324  4B E0 10 51 */	bl memcpy
/* 802023C8 001FF328  38 6D 2A 20 */	addi r3, r13, lbl_803E7740@sda21
/* 802023CC 001FF32C  4C C6 31 82 */	crclr 6
/* 802023D0 001FF330  4B FF 54 C1 */	bl OSReport
/* 802023D4 001FF334  88 9D 00 00 */	lbz r4, 0(r29)
/* 802023D8 001FF338  7F E3 FB 78 */	mr r3, r31
/* 802023DC 001FF33C  88 BD 00 01 */	lbz r5, 1(r29)
/* 802023E0 001FF340  4C C6 31 82 */	crclr 6
/* 802023E4 001FF344  88 DD 00 02 */	lbz r6, 2(r29)
/* 802023E8 001FF348  88 FD 00 03 */	lbz r7, 3(r29)
/* 802023EC 001FF34C  4B FF 54 A5 */	bl OSReport
/* 802023F0 001FF350  88 9D 00 04 */	lbz r4, 4(r29)
/* 802023F4 001FF354  38 7F 00 1C */	addi r3, r31, 0x1c
/* 802023F8 001FF358  88 BD 00 05 */	lbz r5, 5(r29)
/* 802023FC 001FF35C  4C C6 31 82 */	crclr 6
/* 80202400 001FF360  4B FF 54 91 */	bl OSReport
/* 80202404 001FF364  88 9D 00 06 */	lbz r4, 6(r29)
/* 80202408 001FF368  38 7F 00 34 */	addi r3, r31, 0x34
/* 8020240C 001FF36C  4C C6 31 82 */	crclr 6
/* 80202410 001FF370  4B FF 54 81 */	bl OSReport
/* 80202414 001FF374  88 9D 00 07 */	lbz r4, 7(r29)
/* 80202418 001FF378  38 7F 00 48 */	addi r3, r31, 0x48
/* 8020241C 001FF37C  4C C6 31 82 */	crclr 6
/* 80202420 001FF380  4B FF 54 71 */	bl OSReport
/* 80202424 001FF384  88 1E 00 08 */	lbz r0, 8(r30)
/* 80202428 001FF388  28 00 00 00 */	cmplwi r0, 0
/* 8020242C 001FF38C  40 82 00 0C */	bne .L_80202438
/* 80202430 001FF390  38 8D 2A 24 */	addi r4, r13, lbl_803E7744@sda21
/* 80202434 001FF394  48 00 00 08 */	b .L_8020243C
.L_80202438:
/* 80202438 001FF398  38 8D 2A 28 */	addi r4, r13, lbl_803E7748@sda21
.L_8020243C:
/* 8020243C 001FF39C  4C C6 31 82 */	crclr 6
/* 80202440 001FF3A0  38 7F 00 5C */	addi r3, r31, 0x5c
/* 80202444 001FF3A4  4B FF 54 4D */	bl OSReport
/* 80202448 001FF3A8  38 6D 2A 20 */	addi r3, r13, lbl_803E7740@sda21
/* 8020244C 001FF3AC  4C C6 31 82 */	crclr 6
/* 80202450 001FF3B0  4B FF 54 41 */	bl OSReport
/* 80202454 001FF3B4  80 6D 33 04 */	lwz r3, bb2@sda21(r13)
/* 80202458 001FF3B8  80 63 00 10 */	lwz r3, 0x10(r3)
/* 8020245C 001FF3BC  4B FF 44 CD */	bl OSSetArenaHi
/* 80202460 001FF3C0  80 01 00 64 */	lwz r0, 0x64(r1)
/* 80202464 001FF3C4  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 80202468 001FF3C8  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 8020246C 001FF3CC  7C 08 03 A6 */	mtlr r0
/* 80202470 001FF3D0  83 A1 00 54 */	lwz r29, 0x54(r1)
/* 80202474 001FF3D4  38 21 00 60 */	addi r1, r1, 0x60
/* 80202478 001FF3D8  4E 80 00 20 */	blr 
.endfn __fstLoad

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802E8970, local
	.asciz "  Game Name ... %c%c%c%c\n"
.endobj lbl_802E8970
.balign 4
.obj lbl_802E898C, local
	.asciz "  Company ..... %c%c\n"
.endobj lbl_802E898C
.balign 4
.obj lbl_802E89A4, local
	.asciz "  Disk # ...... %d\n"
.endobj lbl_802E89A4
.balign 4
.obj lbl_802E89B8, local
	.asciz "  Game ver .... %d\n"
.endobj lbl_802E89B8
.balign 4
.obj lbl_802E89CC, local
	.asciz "  Streaming ... %s\n"
.endobj lbl_802E89CC

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E7740, local
	.asciz "\n"
.endobj lbl_803E7740
.balign 4
.obj lbl_803E7744, local
	.asciz "OFF"
.endobj lbl_803E7744
.balign 4
.obj lbl_803E7748, local
	.asciz "ON"
.endobj lbl_803E7748

.section .sbss, "wa"
.balign 8
.obj status, local
	.skip 0x4
.endobj status
.obj bb2, local
	.skip 0x4
.endobj bb2
.obj idTmp, local
	.skip 0x4
.endobj idTmp
