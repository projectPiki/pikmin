.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global CARDProbe
CARDProbe:
/* 8020AAA4 00207A04  7C 08 02 A6 */	mflr r0
/* 8020AAA8 00207A08  90 01 00 04 */	stw r0, 4(r1)
/* 8020AAAC 00207A0C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8020AAB0 00207A10  4B FE D8 C5 */	bl EXIProbe
/* 8020AAB4 00207A14  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8020AAB8 00207A18  38 21 00 08 */	addi r1, r1, 8
/* 8020AABC 00207A1C  7C 08 03 A6 */	mtlr r0
/* 8020AAC0 00207A20  4E 80 00 20 */	blr 

.global DoMount
DoMount:
/* 8020AAC4 00207A24  7C 08 02 A6 */	mflr r0
/* 8020AAC8 00207A28  90 01 00 04 */	stw r0, 4(r1)
/* 8020AACC 00207A2C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8020AAD0 00207A30  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8020AAD4 00207A34  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8020AAD8 00207A38  93 A1 00 24 */	stw r29, 0x24(r1)
/* 8020AADC 00207A3C  3B A3 00 00 */	addi r29, r3, 0
/* 8020AAE0 00207A40  1C 9D 01 08 */	mulli r4, r29, 0x108
/* 8020AAE4 00207A44  93 81 00 20 */	stw r28, 0x20(r1)
/* 8020AAE8 00207A48  3C 60 80 3D */	lis r3, __CARDBlock@ha
/* 8020AAEC 00207A4C  38 03 34 20 */	addi r0, r3, __CARDBlock@l
/* 8020AAF0 00207A50  7C 60 22 14 */	add r3, r0, r4
/* 8020AAF4 00207A54  80 03 00 24 */	lwz r0, 0x24(r3)
/* 8020AAF8 00207A58  3B E3 00 00 */	addi r31, r3, 0
/* 8020AAFC 00207A5C  2C 00 00 00 */	cmpwi r0, 0
/* 8020AB00 00207A60  40 82 02 94 */	bne lbl_8020AD94
/* 8020AB04 00207A64  38 7D 00 00 */	addi r3, r29, 0
/* 8020AB08 00207A68  38 81 00 18 */	addi r4, r1, 0x18
/* 8020AB0C 00207A6C  4B FF D6 9D */	bl __CARDReadNintendoID
/* 8020AB10 00207A70  7C 7E 1B 79 */	or. r30, r3, r3
/* 8020AB14 00207A74  41 80 03 1C */	blt lbl_8020AE30
/* 8020AB18 00207A78  80 01 00 18 */	lwz r0, 0x18(r1)
/* 8020AB1C 00207A7C  3C 80 80 2F */	lis r4, SectorSizeTable@ha
/* 8020AB20 00207A80  3C 60 80 2F */	lis r3, LatencyTable@ha
/* 8020AB24 00207A84  54 00 06 3A */	rlwinm r0, r0, 0, 0x18, 0x1d
/* 8020AB28 00207A88  B0 1F 00 08 */	sth r0, 8(r31)
/* 8020AB2C 00207A8C  38 03 8B E0 */	addi r0, r3, LatencyTable@l
/* 8020AB30 00207A90  38 84 8B C0 */	addi r4, r4, SectorSizeTable@l
/* 8020AB34 00207A94  80 61 00 18 */	lwz r3, 0x18(r1)
/* 8020AB38 00207A98  54 63 BE FA */	rlwinm r3, r3, 0x17, 0x1b, 0x1d
/* 8020AB3C 00207A9C  7C 64 1A 14 */	add r3, r4, r3
/* 8020AB40 00207AA0  80 63 00 00 */	lwz r3, 0(r3)
/* 8020AB44 00207AA4  90 7F 00 0C */	stw r3, 0xc(r31)
/* 8020AB48 00207AA8  A0 9F 00 08 */	lhz r4, 8(r31)
/* 8020AB4C 00207AAC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8020AB50 00207AB0  54 84 A0 16 */	slwi r4, r4, 0x14
/* 8020AB54 00207AB4  7C 84 1E 70 */	srawi r4, r4, 3
/* 8020AB58 00207AB8  7C 84 01 94 */	addze r4, r4
/* 8020AB5C 00207ABC  7C 64 1B D6 */	divw r3, r4, r3
/* 8020AB60 00207AC0  B0 7F 00 10 */	sth r3, 0x10(r31)
/* 8020AB64 00207AC4  80 61 00 18 */	lwz r3, 0x18(r1)
/* 8020AB68 00207AC8  54 63 D6 FA */	rlwinm r3, r3, 0x1a, 0x1b, 0x1d
/* 8020AB6C 00207ACC  7C 60 1A 14 */	add r3, r0, r3
/* 8020AB70 00207AD0  80 03 00 00 */	lwz r0, 0(r3)
/* 8020AB74 00207AD4  90 1F 00 14 */	stw r0, 0x14(r31)
/* 8020AB78 00207AD8  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8020AB7C 00207ADC  2C 00 00 00 */	cmpwi r0, 0
/* 8020AB80 00207AE0  41 82 00 10 */	beq lbl_8020AB90
/* 8020AB84 00207AE4  A0 1F 00 10 */	lhz r0, 0x10(r31)
/* 8020AB88 00207AE8  28 00 00 08 */	cmplwi r0, 8
/* 8020AB8C 00207AEC  40 80 00 0C */	bge lbl_8020AB98
lbl_8020AB90:
/* 8020AB90 00207AF0  3B C0 FF FE */	li r30, -2
/* 8020AB94 00207AF4  48 00 02 9C */	b lbl_8020AE30
lbl_8020AB98:
/* 8020AB98 00207AF8  7F A3 EB 78 */	mr r3, r29
/* 8020AB9C 00207AFC  4B FF D8 C9 */	bl __CARDClearStatus
/* 8020ABA0 00207B00  7C 7E 1B 79 */	or. r30, r3, r3
/* 8020ABA4 00207B04  41 80 02 8C */	blt lbl_8020AE30
/* 8020ABA8 00207B08  38 7D 00 00 */	addi r3, r29, 0
/* 8020ABAC 00207B0C  38 81 00 14 */	addi r4, r1, 0x14
/* 8020ABB0 00207B10  4B FF D7 C5 */	bl __CARDReadStatus
/* 8020ABB4 00207B14  7C 7E 1B 79 */	or. r30, r3, r3
/* 8020ABB8 00207B18  41 80 02 78 */	blt lbl_8020AE30
/* 8020ABBC 00207B1C  7F A3 EB 78 */	mr r3, r29
/* 8020ABC0 00207B20  4B FE D7 B5 */	bl EXIProbe
/* 8020ABC4 00207B24  2C 03 00 00 */	cmpwi r3, 0
/* 8020ABC8 00207B28  40 82 00 0C */	bne lbl_8020ABD4
/* 8020ABCC 00207B2C  3B C0 FF FD */	li r30, -3
/* 8020ABD0 00207B30  48 00 02 60 */	b lbl_8020AE30
lbl_8020ABD4:
/* 8020ABD4 00207B34  88 01 00 14 */	lbz r0, 0x14(r1)
/* 8020ABD8 00207B38  54 00 06 73 */	rlwinm. r0, r0, 0, 0x19, 0x19
/* 8020ABDC 00207B3C  40 82 01 14 */	bne lbl_8020ACF0
/* 8020ABE0 00207B40  38 7D 00 00 */	addi r3, r29, 0
/* 8020ABE4 00207B44  38 9F 00 18 */	addi r4, r31, 0x18
/* 8020ABE8 00207B48  4B DF E3 79 */	bl __CARDUnlock
/* 8020ABEC 00207B4C  7C 7E 1B 79 */	or. r30, r3, r3
/* 8020ABF0 00207B50  41 80 02 40 */	blt lbl_8020AE30
/* 8020ABF4 00207B54  4B FE FD B1 */	bl __OSLockSramEx
/* 8020ABF8 00207B58  1C 1D 00 0C */	mulli r0, r29, 0xc
/* 8020ABFC 00207B5C  7C 83 02 14 */	add r4, r3, r0
/* 8020AC00 00207B60  88 1F 00 18 */	lbz r0, 0x18(r31)
/* 8020AC04 00207B64  38 BF 00 18 */	addi r5, r31, 0x18
/* 8020AC08 00207B68  98 04 00 00 */	stb r0, 0(r4)
/* 8020AC0C 00207B6C  39 05 00 02 */	addi r8, r5, 2
/* 8020AC10 00207B70  39 25 00 03 */	addi r9, r5, 3
/* 8020AC14 00207B74  88 FF 00 18 */	lbz r7, 0x18(r31)
/* 8020AC18 00207B78  39 45 00 04 */	addi r10, r5, 4
/* 8020AC1C 00207B7C  88 1F 00 19 */	lbz r0, 0x19(r31)
/* 8020AC20 00207B80  39 65 00 05 */	addi r11, r5, 5
/* 8020AC24 00207B84  39 85 00 06 */	addi r12, r5, 6
/* 8020AC28 00207B88  98 04 00 01 */	stb r0, 1(r4)
/* 8020AC2C 00207B8C  3B 85 00 07 */	addi r28, r5, 7
/* 8020AC30 00207B90  38 A0 00 08 */	li r5, 8
/* 8020AC34 00207B94  88 1F 00 19 */	lbz r0, 0x19(r31)
/* 8020AC38 00207B98  88 C8 00 00 */	lbz r6, 0(r8)
/* 8020AC3C 00207B9C  7C 07 02 14 */	add r0, r7, r0
/* 8020AC40 00207BA0  98 C4 00 02 */	stb r6, 2(r4)
/* 8020AC44 00207BA4  88 E8 00 00 */	lbz r7, 0(r8)
/* 8020AC48 00207BA8  88 C9 00 00 */	lbz r6, 0(r9)
/* 8020AC4C 00207BAC  7C 00 3A 14 */	add r0, r0, r7
/* 8020AC50 00207BB0  98 C4 00 03 */	stb r6, 3(r4)
/* 8020AC54 00207BB4  88 E9 00 00 */	lbz r7, 0(r9)
/* 8020AC58 00207BB8  88 CA 00 00 */	lbz r6, 0(r10)
/* 8020AC5C 00207BBC  7C 00 3A 14 */	add r0, r0, r7
/* 8020AC60 00207BC0  98 C4 00 04 */	stb r6, 4(r4)
/* 8020AC64 00207BC4  88 EA 00 00 */	lbz r7, 0(r10)
/* 8020AC68 00207BC8  88 CB 00 00 */	lbz r6, 0(r11)
/* 8020AC6C 00207BCC  7C 00 3A 14 */	add r0, r0, r7
/* 8020AC70 00207BD0  98 C4 00 05 */	stb r6, 5(r4)
/* 8020AC74 00207BD4  88 EB 00 00 */	lbz r7, 0(r11)
/* 8020AC78 00207BD8  88 CC 00 00 */	lbz r6, 0(r12)
/* 8020AC7C 00207BDC  7C 00 3A 14 */	add r0, r0, r7
/* 8020AC80 00207BE0  98 C4 00 06 */	stb r6, 6(r4)
/* 8020AC84 00207BE4  88 EC 00 00 */	lbz r7, 0(r12)
/* 8020AC88 00207BE8  88 DC 00 00 */	lbz r6, 0(r28)
/* 8020AC8C 00207BEC  7C 00 3A 14 */	add r0, r0, r7
/* 8020AC90 00207BF0  98 C4 00 07 */	stb r6, 7(r4)
/* 8020AC94 00207BF4  88 DC 00 00 */	lbz r6, 0(r28)
/* 8020AC98 00207BF8  7C 00 32 14 */	add r0, r0, r6
/* 8020AC9C 00207BFC  48 00 01 B0 */	b lbl_8020AE4C
lbl_8020ACA0:
/* 8020ACA0 00207C00  20 85 00 0C */	subfic r4, r5, 0xc
/* 8020ACA4 00207C04  2C 05 00 0C */	cmpwi r5, 0xc
/* 8020ACA8 00207C08  7C 89 03 A6 */	mtctr r4
/* 8020ACAC 00207C0C  40 80 00 28 */	bge lbl_8020ACD4
lbl_8020ACB0:
/* 8020ACB0 00207C10  38 E5 00 18 */	addi r7, r5, 0x18
/* 8020ACB4 00207C14  7C FF 3A 14 */	add r7, r31, r7
/* 8020ACB8 00207C18  88 87 00 00 */	lbz r4, 0(r7)
/* 8020ACBC 00207C1C  38 A5 00 01 */	addi r5, r5, 1
/* 8020ACC0 00207C20  98 86 00 00 */	stb r4, 0(r6)
/* 8020ACC4 00207C24  38 C6 00 01 */	addi r6, r6, 1
/* 8020ACC8 00207C28  88 87 00 00 */	lbz r4, 0(r7)
/* 8020ACCC 00207C2C  7C 00 22 14 */	add r0, r0, r4
/* 8020ACD0 00207C30  42 00 FF E0 */	bdnz lbl_8020ACB0
lbl_8020ACD4:
/* 8020ACD4 00207C34  7C 63 EA 14 */	add r3, r3, r29
/* 8020ACD8 00207C38  7C 00 00 F8 */	nor r0, r0, r0
/* 8020ACDC 00207C3C  98 03 00 26 */	stb r0, 0x26(r3)
/* 8020ACE0 00207C40  38 60 00 01 */	li r3, 1
/* 8020ACE4 00207C44  4B FF 00 49 */	bl __OSUnlockSramEx
/* 8020ACE8 00207C48  7F C3 F3 78 */	mr r3, r30
/* 8020ACEC 00207C4C  48 00 01 70 */	b lbl_8020AE5C
lbl_8020ACF0:
/* 8020ACF0 00207C50  38 00 00 01 */	li r0, 1
/* 8020ACF4 00207C54  90 1F 00 24 */	stw r0, 0x24(r31)
/* 8020ACF8 00207C58  4B FE FC AD */	bl __OSLockSramEx
/* 8020ACFC 00207C5C  1C 1D 00 0C */	mulli r0, r29, 0xc
/* 8020AD00 00207C60  3B C3 00 00 */	addi r30, r3, 0
/* 8020AD04 00207C64  7C BE 02 14 */	add r5, r30, r0
/* 8020AD08 00207C68  88 85 00 00 */	lbz r4, 0(r5)
/* 8020AD0C 00207C6C  38 C0 00 08 */	li r6, 8
/* 8020AD10 00207C70  88 05 00 01 */	lbz r0, 1(r5)
/* 8020AD14 00207C74  88 65 00 02 */	lbz r3, 2(r5)
/* 8020AD18 00207C78  7F 84 02 14 */	add r28, r4, r0
/* 8020AD1C 00207C7C  88 05 00 03 */	lbz r0, 3(r5)
/* 8020AD20 00207C80  7F 9C 1A 14 */	add r28, r28, r3
/* 8020AD24 00207C84  88 65 00 04 */	lbz r3, 4(r5)
/* 8020AD28 00207C88  7F 9C 02 14 */	add r28, r28, r0
/* 8020AD2C 00207C8C  88 05 00 05 */	lbz r0, 5(r5)
/* 8020AD30 00207C90  7F 9C 1A 14 */	add r28, r28, r3
/* 8020AD34 00207C94  88 65 00 06 */	lbz r3, 6(r5)
/* 8020AD38 00207C98  7F 9C 02 14 */	add r28, r28, r0
/* 8020AD3C 00207C9C  88 05 00 07 */	lbz r0, 7(r5)
/* 8020AD40 00207CA0  7F 9C 1A 14 */	add r28, r28, r3
/* 8020AD44 00207CA4  7F 9C 02 14 */	add r28, r28, r0
/* 8020AD48 00207CA8  48 00 01 0C */	b lbl_8020AE54
lbl_8020AD4C:
/* 8020AD4C 00207CAC  20 06 00 0C */	subfic r0, r6, 0xc
/* 8020AD50 00207CB0  2C 06 00 0C */	cmpwi r6, 0xc
/* 8020AD54 00207CB4  7C 09 03 A6 */	mtctr r0
/* 8020AD58 00207CB8  40 80 00 14 */	bge lbl_8020AD6C
lbl_8020AD5C:
/* 8020AD5C 00207CBC  88 03 00 00 */	lbz r0, 0(r3)
/* 8020AD60 00207CC0  38 63 00 01 */	addi r3, r3, 1
/* 8020AD64 00207CC4  7F 9C 02 14 */	add r28, r28, r0
/* 8020AD68 00207CC8  42 00 FF F4 */	bdnz lbl_8020AD5C
lbl_8020AD6C:
/* 8020AD6C 00207CCC  38 60 00 00 */	li r3, 0
/* 8020AD70 00207CD0  4B FE FF BD */	bl __OSUnlockSramEx
/* 8020AD74 00207CD4  7C 7E EA 14 */	add r3, r30, r29
/* 8020AD78 00207CD8  7F 80 E0 F8 */	nor r0, r28, r28
/* 8020AD7C 00207CDC  88 63 00 26 */	lbz r3, 0x26(r3)
/* 8020AD80 00207CE0  54 00 06 3E */	clrlwi r0, r0, 0x18
/* 8020AD84 00207CE4  7C 03 00 40 */	cmplw r3, r0
/* 8020AD88 00207CE8  41 82 00 0C */	beq lbl_8020AD94
/* 8020AD8C 00207CEC  3B C0 FF FB */	li r30, -5
/* 8020AD90 00207CF0  48 00 00 A0 */	b lbl_8020AE30
lbl_8020AD94:
/* 8020AD94 00207CF4  80 1F 00 24 */	lwz r0, 0x24(r31)
/* 8020AD98 00207CF8  2C 00 00 01 */	cmpwi r0, 1
/* 8020AD9C 00207CFC  40 82 00 48 */	bne lbl_8020ADE4
/* 8020ADA0 00207D00  38 00 00 02 */	li r0, 2
/* 8020ADA4 00207D04  90 1F 00 24 */	stw r0, 0x24(r31)
/* 8020ADA8 00207D08  38 7D 00 00 */	addi r3, r29, 0
/* 8020ADAC 00207D0C  38 80 00 01 */	li r4, 1
/* 8020ADB0 00207D10  4B FF D5 05 */	bl __CARDEnableInterrupt
/* 8020ADB4 00207D14  7C 7E 1B 79 */	or. r30, r3, r3
/* 8020ADB8 00207D18  41 80 00 78 */	blt lbl_8020AE30
/* 8020ADBC 00207D1C  3C 60 80 20 */	lis r3, __CARDExiHandler@ha
/* 8020ADC0 00207D20  38 83 7F 64 */	addi r4, r3, __CARDExiHandler@l
/* 8020ADC4 00207D24  38 7D 00 00 */	addi r3, r29, 0
/* 8020ADC8 00207D28  4B FE D5 31 */	bl EXISetExiCallback
/* 8020ADCC 00207D2C  7F A3 EB 78 */	mr r3, r29
/* 8020ADD0 00207D30  4B FE E0 61 */	bl EXIUnlock
/* 8020ADD4 00207D34  3C 80 00 01 */	lis r4, 0x0000A000@ha
/* 8020ADD8 00207D38  80 7F 00 80 */	lwz r3, 0x80(r31)
/* 8020ADDC 00207D3C  38 84 A0 00 */	addi r4, r4, 0x0000A000@l
/* 8020ADE0 00207D40  4B FE BD D9 */	bl DCInvalidateRange
lbl_8020ADE4:
/* 8020ADE4 00207D44  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 8020ADE8 00207D48  3C 60 80 21 */	lis r3, __CARDMountCallback@ha
/* 8020ADEC 00207D4C  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 8020ADF0 00207D50  38 E3 AE 7C */	addi r7, r3, __CARDMountCallback@l
/* 8020ADF4 00207D54  38 64 FF FE */	addi r3, r4, -2
/* 8020ADF8 00207D58  7C 80 19 D6 */	mullw r4, r0, r3
/* 8020ADFC 00207D5C  80 BF 00 80 */	lwz r5, 0x80(r31)
/* 8020AE00 00207D60  54 60 68 24 */	slwi r0, r3, 0xd
/* 8020AE04 00207D64  7C C5 02 14 */	add r6, r5, r0
/* 8020AE08 00207D68  38 7D 00 00 */	addi r3, r29, 0
/* 8020AE0C 00207D6C  38 A0 20 00 */	li r5, 0x2000
/* 8020AE10 00207D70  4B FF E4 E1 */	bl __CARDRead
/* 8020AE14 00207D74  7C 7C 1B 79 */	or. r28, r3, r3
/* 8020AE18 00207D78  40 80 00 10 */	bge lbl_8020AE28
/* 8020AE1C 00207D7C  38 7F 00 00 */	addi r3, r31, 0
/* 8020AE20 00207D80  38 9C 00 00 */	addi r4, r28, 0
/* 8020AE24 00207D84  4B FF E0 FD */	bl __CARDPutControlBlock
lbl_8020AE28:
/* 8020AE28 00207D88  7F 83 E3 78 */	mr r3, r28
/* 8020AE2C 00207D8C  48 00 00 30 */	b lbl_8020AE5C
lbl_8020AE30:
/* 8020AE30 00207D90  7F A3 EB 78 */	mr r3, r29
/* 8020AE34 00207D94  4B FE DF FD */	bl EXIUnlock
/* 8020AE38 00207D98  38 7D 00 00 */	addi r3, r29, 0
/* 8020AE3C 00207D9C  38 9E 00 00 */	addi r4, r30, 0
/* 8020AE40 00207DA0  48 00 03 15 */	bl DoUnmount
/* 8020AE44 00207DA4  7F C3 F3 78 */	mr r3, r30
/* 8020AE48 00207DA8  48 00 00 14 */	b lbl_8020AE5C
lbl_8020AE4C:
/* 8020AE4C 00207DAC  38 C4 00 08 */	addi r6, r4, 8
/* 8020AE50 00207DB0  4B FF FE 50 */	b lbl_8020ACA0
lbl_8020AE54:
/* 8020AE54 00207DB4  38 65 00 08 */	addi r3, r5, 8
/* 8020AE58 00207DB8  4B FF FE F4 */	b lbl_8020AD4C
lbl_8020AE5C:
/* 8020AE5C 00207DBC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8020AE60 00207DC0  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8020AE64 00207DC4  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8020AE68 00207DC8  7C 08 03 A6 */	mtlr r0
/* 8020AE6C 00207DCC  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 8020AE70 00207DD0  83 81 00 20 */	lwz r28, 0x20(r1)
/* 8020AE74 00207DD4  38 21 00 30 */	addi r1, r1, 0x30
/* 8020AE78 00207DD8  4E 80 00 20 */	blr 

.global __CARDMountCallback
__CARDMountCallback:
/* 8020AE7C 00207DDC  7C 08 02 A6 */	mflr r0
/* 8020AE80 00207DE0  90 01 00 04 */	stw r0, 4(r1)
/* 8020AE84 00207DE4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8020AE88 00207DE8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8020AE8C 00207DEC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8020AE90 00207DF0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8020AE94 00207DF4  3B A4 00 00 */	addi r29, r4, 0
/* 8020AE98 00207DF8  2C 1D FF FD */	cmpwi r29, -3
/* 8020AE9C 00207DFC  93 81 00 10 */	stw r28, 0x10(r1)
/* 8020AEA0 00207E00  3B 83 00 00 */	addi r28, r3, 0
/* 8020AEA4 00207E04  1C BC 01 08 */	mulli r5, r28, 0x108
/* 8020AEA8 00207E08  3C 60 80 3D */	lis r3, __CARDBlock@ha
/* 8020AEAC 00207E0C  38 03 34 20 */	addi r0, r3, __CARDBlock@l
/* 8020AEB0 00207E10  7F E0 2A 14 */	add r31, r0, r5
/* 8020AEB4 00207E14  41 82 00 78 */	beq lbl_8020AF2C
/* 8020AEB8 00207E18  40 80 00 10 */	bge lbl_8020AEC8
/* 8020AEBC 00207E1C  2C 1D FF FB */	cmpwi r29, -5
/* 8020AEC0 00207E20  41 82 00 6C */	beq lbl_8020AF2C
/* 8020AEC4 00207E24  48 00 00 74 */	b lbl_8020AF38
lbl_8020AEC8:
/* 8020AEC8 00207E28  2C 1D 00 01 */	cmpwi r29, 1
/* 8020AECC 00207E2C  41 82 00 4C */	beq lbl_8020AF18
/* 8020AED0 00207E30  40 80 00 68 */	bge lbl_8020AF38
/* 8020AED4 00207E34  2C 1D 00 00 */	cmpwi r29, 0
/* 8020AED8 00207E38  40 80 00 08 */	bge lbl_8020AEE0
/* 8020AEDC 00207E3C  48 00 00 5C */	b lbl_8020AF38
lbl_8020AEE0:
/* 8020AEE0 00207E40  80 7F 00 24 */	lwz r3, 0x24(r31)
/* 8020AEE4 00207E44  38 03 00 01 */	addi r0, r3, 1
/* 8020AEE8 00207E48  2C 00 00 07 */	cmpwi r0, 7
/* 8020AEEC 00207E4C  90 1F 00 24 */	stw r0, 0x24(r31)
/* 8020AEF0 00207E50  40 80 00 18 */	bge lbl_8020AF08
/* 8020AEF4 00207E54  7F 83 E3 78 */	mr r3, r28
/* 8020AEF8 00207E58  4B FF FB CD */	bl DoMount
/* 8020AEFC 00207E5C  7C 7D 1B 79 */	or. r29, r3, r3
/* 8020AF00 00207E60  41 80 00 38 */	blt lbl_8020AF38
/* 8020AF04 00207E64  48 00 00 60 */	b lbl_8020AF64
lbl_8020AF08:
/* 8020AF08 00207E68  7F E3 FB 78 */	mr r3, r31
/* 8020AF0C 00207E6C  4B FF F5 01 */	bl __CARDVerify
/* 8020AF10 00207E70  7C 7D 1B 78 */	mr r29, r3
/* 8020AF14 00207E74  48 00 00 24 */	b lbl_8020AF38
lbl_8020AF18:
/* 8020AF18 00207E78  7F 83 E3 78 */	mr r3, r28
/* 8020AF1C 00207E7C  4B FF FB A9 */	bl DoMount
/* 8020AF20 00207E80  7C 7D 1B 79 */	or. r29, r3, r3
/* 8020AF24 00207E84  41 80 00 14 */	blt lbl_8020AF38
/* 8020AF28 00207E88  48 00 00 3C */	b lbl_8020AF64
lbl_8020AF2C:
/* 8020AF2C 00207E8C  38 7C 00 00 */	addi r3, r28, 0
/* 8020AF30 00207E90  38 9D 00 00 */	addi r4, r29, 0
/* 8020AF34 00207E94  48 00 02 21 */	bl DoUnmount
lbl_8020AF38:
/* 8020AF38 00207E98  83 DF 00 D0 */	lwz r30, 0xd0(r31)
/* 8020AF3C 00207E9C  38 00 00 00 */	li r0, 0
/* 8020AF40 00207EA0  38 7F 00 00 */	addi r3, r31, 0
/* 8020AF44 00207EA4  90 1F 00 D0 */	stw r0, 0xd0(r31)
/* 8020AF48 00207EA8  7F A4 EB 78 */	mr r4, r29
/* 8020AF4C 00207EAC  4B FF DF D5 */	bl __CARDPutControlBlock
/* 8020AF50 00207EB0  39 9E 00 00 */	addi r12, r30, 0
/* 8020AF54 00207EB4  7D 88 03 A6 */	mtlr r12
/* 8020AF58 00207EB8  38 7C 00 00 */	addi r3, r28, 0
/* 8020AF5C 00207EBC  38 9D 00 00 */	addi r4, r29, 0
/* 8020AF60 00207EC0  4E 80 00 21 */	blrl 
lbl_8020AF64:
/* 8020AF64 00207EC4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8020AF68 00207EC8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8020AF6C 00207ECC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8020AF70 00207ED0  7C 08 03 A6 */	mtlr r0
/* 8020AF74 00207ED4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8020AF78 00207ED8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8020AF7C 00207EDC  38 21 00 20 */	addi r1, r1, 0x20
/* 8020AF80 00207EE0  4E 80 00 20 */	blr 

.global CARDMountAsync
CARDMountAsync:
/* 8020AF84 00207EE4  7C 08 02 A6 */	mflr r0
/* 8020AF88 00207EE8  90 01 00 04 */	stw r0, 4(r1)
/* 8020AF8C 00207EEC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8020AF90 00207EF0  BF 41 00 18 */	stmw r26, 0x18(r1)
/* 8020AF94 00207EF4  7C 7E 1B 79 */	or. r30, r3, r3
/* 8020AF98 00207EF8  3B 44 00 00 */	addi r26, r4, 0
/* 8020AF9C 00207EFC  3B 65 00 00 */	addi r27, r5, 0
/* 8020AFA0 00207F00  3B A6 00 00 */	addi r29, r6, 0
/* 8020AFA4 00207F04  41 80 00 0C */	blt lbl_8020AFB0
/* 8020AFA8 00207F08  2C 1E 00 02 */	cmpwi r30, 2
/* 8020AFAC 00207F0C  41 80 00 0C */	blt lbl_8020AFB8
lbl_8020AFB0:
/* 8020AFB0 00207F10  38 60 FF 80 */	li r3, -128
/* 8020AFB4 00207F14  48 00 01 44 */	b lbl_8020B0F8
lbl_8020AFB8:
/* 8020AFB8 00207F18  1C 9E 01 08 */	mulli r4, r30, 0x108
/* 8020AFBC 00207F1C  3C 60 80 3D */	lis r3, __CARDBlock@ha
/* 8020AFC0 00207F20  38 03 34 20 */	addi r0, r3, __CARDBlock@l
/* 8020AFC4 00207F24  7F E0 22 14 */	add r31, r0, r4
/* 8020AFC8 00207F28  4B FE DF B5 */	bl OSDisableInterrupts
/* 8020AFCC 00207F2C  80 1F 00 04 */	lwz r0, 4(r31)
/* 8020AFD0 00207F30  3B 83 00 00 */	addi r28, r3, 0
/* 8020AFD4 00207F34  2C 00 FF FF */	cmpwi r0, -1
/* 8020AFD8 00207F38  40 82 00 14 */	bne lbl_8020AFEC
/* 8020AFDC 00207F3C  7F 83 E3 78 */	mr r3, r28
/* 8020AFE0 00207F40  4B FE DF C5 */	bl OSRestoreInterrupts
/* 8020AFE4 00207F44  38 60 FF FF */	li r3, -1
/* 8020AFE8 00207F48  48 00 01 10 */	b lbl_8020B0F8
lbl_8020AFEC:
/* 8020AFEC 00207F4C  80 1F 00 00 */	lwz r0, 0(r31)
/* 8020AFF0 00207F50  2C 00 00 00 */	cmpwi r0, 0
/* 8020AFF4 00207F54  40 82 00 24 */	bne lbl_8020B018
/* 8020AFF8 00207F58  7F C3 F3 78 */	mr r3, r30
/* 8020AFFC 00207F5C  4B FE DF 11 */	bl EXIGetState
/* 8020B000 00207F60  54 60 07 39 */	rlwinm. r0, r3, 0, 0x1c, 0x1c
/* 8020B004 00207F64  41 82 00 14 */	beq lbl_8020B018
/* 8020B008 00207F68  7F 83 E3 78 */	mr r3, r28
/* 8020B00C 00207F6C  4B FE DF 99 */	bl OSRestoreInterrupts
/* 8020B010 00207F70  38 60 FF FE */	li r3, -2
/* 8020B014 00207F74  48 00 00 E4 */	b lbl_8020B0F8
lbl_8020B018:
/* 8020B018 00207F78  38 00 FF FF */	li r0, -1
/* 8020B01C 00207F7C  90 1F 00 04 */	stw r0, 4(r31)
/* 8020B020 00207F80  28 1D 00 00 */	cmplwi r29, 0
/* 8020B024 00207F84  93 5F 00 80 */	stw r26, 0x80(r31)
/* 8020B028 00207F88  93 7F 00 C4 */	stw r27, 0xc4(r31)
/* 8020B02C 00207F8C  41 82 00 0C */	beq lbl_8020B038
/* 8020B030 00207F90  7F A0 EB 78 */	mr r0, r29
/* 8020B034 00207F94  48 00 00 0C */	b lbl_8020B040
lbl_8020B038:
/* 8020B038 00207F98  3C 60 80 20 */	lis r3, __CARDDefaultApiCallback@ha
/* 8020B03C 00207F9C  38 03 7E 60 */	addi r0, r3, __CARDDefaultApiCallback@l
lbl_8020B040:
/* 8020B040 00207FA0  90 1F 00 D0 */	stw r0, 0xd0(r31)
/* 8020B044 00207FA4  38 00 00 00 */	li r0, 0
/* 8020B048 00207FA8  90 1F 00 CC */	stw r0, 0xcc(r31)
/* 8020B04C 00207FAC  80 1F 00 00 */	lwz r0, 0(r31)
/* 8020B050 00207FB0  2C 00 00 00 */	cmpwi r0, 0
/* 8020B054 00207FB4  40 82 00 34 */	bne lbl_8020B088
/* 8020B058 00207FB8  3C 60 80 20 */	lis r3, __CARDExtHandler@ha
/* 8020B05C 00207FBC  38 83 7E 98 */	addi r4, r3, __CARDExtHandler@l
/* 8020B060 00207FC0  38 7E 00 00 */	addi r3, r30, 0
/* 8020B064 00207FC4  4B FE D4 D9 */	bl EXIAttach
/* 8020B068 00207FC8  2C 03 00 00 */	cmpwi r3, 0
/* 8020B06C 00207FCC  40 82 00 1C */	bne lbl_8020B088
/* 8020B070 00207FD0  38 00 FF FD */	li r0, -3
/* 8020B074 00207FD4  90 1F 00 04 */	stw r0, 4(r31)
/* 8020B078 00207FD8  7F 83 E3 78 */	mr r3, r28
/* 8020B07C 00207FDC  4B FE DF 29 */	bl OSRestoreInterrupts
/* 8020B080 00207FE0  38 60 FF FD */	li r3, -3
/* 8020B084 00207FE4  48 00 00 74 */	b lbl_8020B0F8
lbl_8020B088:
/* 8020B088 00207FE8  3B A0 00 00 */	li r29, 0
/* 8020B08C 00207FEC  93 BF 00 24 */	stw r29, 0x24(r31)
/* 8020B090 00207FF0  38 00 00 01 */	li r0, 1
/* 8020B094 00207FF4  38 7E 00 00 */	addi r3, r30, 0
/* 8020B098 00207FF8  90 1F 00 00 */	stw r0, 0(r31)
/* 8020B09C 00207FFC  38 80 00 00 */	li r4, 0
/* 8020B0A0 00208000  4B FE D2 59 */	bl EXISetExiCallback
/* 8020B0A4 00208004  38 7F 00 E0 */	addi r3, r31, 0xe0
/* 8020B0A8 00208008  4B FE B3 8D */	bl OSCancelAlarm
/* 8020B0AC 0020800C  93 BF 00 84 */	stw r29, 0x84(r31)
/* 8020B0B0 00208010  7F 83 E3 78 */	mr r3, r28
/* 8020B0B4 00208014  93 BF 00 88 */	stw r29, 0x88(r31)
/* 8020B0B8 00208018  4B FE DE ED */	bl OSRestoreInterrupts
/* 8020B0BC 0020801C  3C 60 80 21 */	lis r3, __CARDMountCallback@ha
/* 8020B0C0 00208020  38 03 AE 7C */	addi r0, r3, __CARDMountCallback@l
/* 8020B0C4 00208024  3C 60 80 21 */	lis r3, __CARDUnlockedHandler@ha
/* 8020B0C8 00208028  90 1F 00 DC */	stw r0, 0xdc(r31)
/* 8020B0CC 0020802C  38 A3 81 24 */	addi r5, r3, __CARDUnlockedHandler@l
/* 8020B0D0 00208030  38 7E 00 00 */	addi r3, r30, 0
/* 8020B0D4 00208034  38 80 00 00 */	li r4, 0
/* 8020B0D8 00208038  4B FE DC 65 */	bl EXILock
/* 8020B0DC 0020803C  2C 03 00 00 */	cmpwi r3, 0
/* 8020B0E0 00208040  40 82 00 0C */	bne lbl_8020B0EC
/* 8020B0E4 00208044  38 60 00 00 */	li r3, 0
/* 8020B0E8 00208048  48 00 00 10 */	b lbl_8020B0F8
lbl_8020B0EC:
/* 8020B0EC 0020804C  93 BF 00 DC */	stw r29, 0xdc(r31)
/* 8020B0F0 00208050  7F C3 F3 78 */	mr r3, r30
/* 8020B0F4 00208054  4B FF F9 D1 */	bl DoMount
lbl_8020B0F8:
/* 8020B0F8 00208058  BB 41 00 18 */	lmw r26, 0x18(r1)
/* 8020B0FC 0020805C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8020B100 00208060  38 21 00 30 */	addi r1, r1, 0x30
/* 8020B104 00208064  7C 08 03 A6 */	mtlr r0
/* 8020B108 00208068  4E 80 00 20 */	blr 

.global CARDMount
CARDMount:
/* 8020B10C 0020806C  7C 08 02 A6 */	mflr r0
/* 8020B110 00208070  3C C0 80 20 */	lis r6, __CARDSyncCallback@ha
/* 8020B114 00208074  90 01 00 04 */	stw r0, 4(r1)
/* 8020B118 00208078  38 C6 7E 64 */	addi r6, r6, __CARDSyncCallback@l
/* 8020B11C 0020807C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8020B120 00208080  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8020B124 00208084  3B E3 00 00 */	addi r31, r3, 0
/* 8020B128 00208088  4B FF FE 5D */	bl CARDMountAsync
/* 8020B12C 0020808C  2C 03 00 00 */	cmpwi r3, 0
/* 8020B130 00208090  40 80 00 08 */	bge lbl_8020B138
/* 8020B134 00208094  48 00 00 0C */	b lbl_8020B140
lbl_8020B138:
/* 8020B138 00208098  7F E3 FB 78 */	mr r3, r31
/* 8020B13C 0020809C  4B FF DF F1 */	bl __CARDSync
lbl_8020B140:
/* 8020B140 002080A0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8020B144 002080A4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8020B148 002080A8  38 21 00 20 */	addi r1, r1, 0x20
/* 8020B14C 002080AC  7C 08 03 A6 */	mtlr r0
/* 8020B150 002080B0  4E 80 00 20 */	blr 

.global DoUnmount
DoUnmount:
/* 8020B154 002080B4  7C 08 02 A6 */	mflr r0
/* 8020B158 002080B8  90 01 00 04 */	stw r0, 4(r1)
/* 8020B15C 002080BC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8020B160 002080C0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8020B164 002080C4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8020B168 002080C8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8020B16C 002080CC  3B A4 00 00 */	addi r29, r4, 0
/* 8020B170 002080D0  93 81 00 10 */	stw r28, 0x10(r1)
/* 8020B174 002080D4  3B 83 00 00 */	addi r28, r3, 0
/* 8020B178 002080D8  1C BC 01 08 */	mulli r5, r28, 0x108
/* 8020B17C 002080DC  3C 60 80 3D */	lis r3, __CARDBlock@ha
/* 8020B180 002080E0  38 03 34 20 */	addi r0, r3, __CARDBlock@l
/* 8020B184 002080E4  7F E0 2A 14 */	add r31, r0, r5
/* 8020B188 002080E8  4B FE DD F5 */	bl OSDisableInterrupts
/* 8020B18C 002080EC  80 1F 00 00 */	lwz r0, 0(r31)
/* 8020B190 002080F0  3B C3 00 00 */	addi r30, r3, 0
/* 8020B194 002080F4  2C 00 00 00 */	cmpwi r0, 0
/* 8020B198 002080F8  41 82 00 30 */	beq lbl_8020B1C8
/* 8020B19C 002080FC  38 7C 00 00 */	addi r3, r28, 0
/* 8020B1A0 00208100  38 80 00 00 */	li r4, 0
/* 8020B1A4 00208104  4B FE D1 55 */	bl EXISetExiCallback
/* 8020B1A8 00208108  7F 83 E3 78 */	mr r3, r28
/* 8020B1AC 0020810C  4B FE D4 75 */	bl EXIDetach
/* 8020B1B0 00208110  38 7F 00 E0 */	addi r3, r31, 0xe0
/* 8020B1B4 00208114  4B FE B2 81 */	bl OSCancelAlarm
/* 8020B1B8 00208118  38 00 00 00 */	li r0, 0
/* 8020B1BC 0020811C  90 1F 00 00 */	stw r0, 0(r31)
/* 8020B1C0 00208120  93 BF 00 04 */	stw r29, 4(r31)
/* 8020B1C4 00208124  90 1F 00 24 */	stw r0, 0x24(r31)
lbl_8020B1C8:
/* 8020B1C8 00208128  7F C3 F3 78 */	mr r3, r30
/* 8020B1CC 0020812C  4B FE DD D9 */	bl OSRestoreInterrupts
/* 8020B1D0 00208130  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8020B1D4 00208134  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8020B1D8 00208138  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8020B1DC 0020813C  7C 08 03 A6 */	mtlr r0
/* 8020B1E0 00208140  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8020B1E4 00208144  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8020B1E8 00208148  38 21 00 20 */	addi r1, r1, 0x20
/* 8020B1EC 0020814C  4E 80 00 20 */	blr 

.global CARDUnmount
CARDUnmount:
/* 8020B1F0 00208150  7C 08 02 A6 */	mflr r0
/* 8020B1F4 00208154  90 01 00 04 */	stw r0, 4(r1)
/* 8020B1F8 00208158  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8020B1FC 0020815C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8020B200 00208160  38 81 00 0C */	addi r4, r1, 0xc
/* 8020B204 00208164  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8020B208 00208168  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8020B20C 0020816C  3B A3 00 00 */	addi r29, r3, 0
/* 8020B210 00208170  4B FF DC 61 */	bl __CARDGetControlBlock
/* 8020B214 00208174  2C 03 00 00 */	cmpwi r3, 0
/* 8020B218 00208178  40 80 00 08 */	bge lbl_8020B220
/* 8020B21C 0020817C  48 00 00 64 */	b lbl_8020B280
lbl_8020B220:
/* 8020B220 00208180  1C 9D 01 08 */	mulli r4, r29, 0x108
/* 8020B224 00208184  3C 60 80 3D */	lis r3, __CARDBlock@ha
/* 8020B228 00208188  38 03 34 20 */	addi r0, r3, __CARDBlock@l
/* 8020B22C 0020818C  7F C0 22 14 */	add r30, r0, r4
/* 8020B230 00208190  4B FE DD 4D */	bl OSDisableInterrupts
/* 8020B234 00208194  80 1E 00 00 */	lwz r0, 0(r30)
/* 8020B238 00208198  3B E3 00 00 */	addi r31, r3, 0
/* 8020B23C 0020819C  2C 00 00 00 */	cmpwi r0, 0
/* 8020B240 002081A0  41 82 00 34 */	beq lbl_8020B274
/* 8020B244 002081A4  38 7D 00 00 */	addi r3, r29, 0
/* 8020B248 002081A8  38 80 00 00 */	li r4, 0
/* 8020B24C 002081AC  4B FE D0 AD */	bl EXISetExiCallback
/* 8020B250 002081B0  7F A3 EB 78 */	mr r3, r29
/* 8020B254 002081B4  4B FE D3 CD */	bl EXIDetach
/* 8020B258 002081B8  38 7E 00 E0 */	addi r3, r30, 0xe0
/* 8020B25C 002081BC  4B FE B1 D9 */	bl OSCancelAlarm
/* 8020B260 002081C0  38 60 00 00 */	li r3, 0
/* 8020B264 002081C4  90 7E 00 00 */	stw r3, 0(r30)
/* 8020B268 002081C8  38 00 FF FD */	li r0, -3
/* 8020B26C 002081CC  90 1E 00 04 */	stw r0, 4(r30)
/* 8020B270 002081D0  90 7E 00 24 */	stw r3, 0x24(r30)
lbl_8020B274:
/* 8020B274 002081D4  7F E3 FB 78 */	mr r3, r31
/* 8020B278 002081D8  4B FE DD 2D */	bl OSRestoreInterrupts
/* 8020B27C 002081DC  38 60 00 00 */	li r3, 0
lbl_8020B280:
/* 8020B280 002081E0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8020B284 002081E4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8020B288 002081E8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8020B28C 002081EC  7C 08 03 A6 */	mtlr r0
/* 8020B290 002081F0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8020B294 002081F4  38 21 00 20 */	addi r1, r1, 0x20
/* 8020B298 002081F8  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 0x8
.global SectorSizeTable
SectorSizeTable:
	.4byte 0x00002000
	.4byte 0x00004000
	.4byte 0x00008000
	.4byte 0x00010000
	.4byte 0x00020000
	.4byte 0x00040000
	.4byte 0x00000000
	.4byte 0x00000000
.global LatencyTable
LatencyTable:
	.4byte 0x00000004
	.4byte 0x00000008
	.4byte 0x00000010
	.4byte 0x00000020
	.4byte 0x00000040
	.4byte 0x00000080
	.4byte 0x00000100
	.4byte 0x00000200