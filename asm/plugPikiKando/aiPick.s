.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__11ActPickItemFP4Piki, global
/* 800BCAFC 000B9A5C  7C 08 02 A6 */	mflr r0
/* 800BCB00 000B9A60  38 A0 00 01 */	li r5, 1
/* 800BCB04 000B9A64  90 01 00 04 */	stw r0, 4(r1)
/* 800BCB08 000B9A68  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BCB0C 000B9A6C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BCB10 000B9A70  7C 9F 23 78 */	mr r31, r4
/* 800BCB14 000B9A74  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800BCB18 000B9A78  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800BCB1C 000B9A7C  90 61 00 08 */	stw r3, 8(r1)
/* 800BCB20 000B9A80  83 C1 00 08 */	lwz r30, 8(r1)
/* 800BCB24 000B9A84  38 7E 00 00 */	addi r3, r30, 0
/* 800BCB28 000B9A88  48 00 72 A9 */	bl __ct__6ActionFP4Pikib
/* 800BCB2C 000B9A8C  3C 60 80 2C */	lis r3, __vt__9AndAction@ha
/* 800BCB30 000B9A90  38 03 81 30 */	addi r0, r3, __vt__9AndAction@l
/* 800BCB34 000B9A94  90 1E 00 00 */	stw r0, 0(r30)
/* 800BCB38 000B9A98  38 80 00 00 */	li r4, 0
/* 800BCB3C 000B9A9C  3C 60 80 2B */	lis r3, __vt__11ActPickItem@ha
/* 800BCB40 000B9AA0  90 9E 00 14 */	stw r4, 0x14(r30)
/* 800BCB44 000B9AA4  38 03 6E DC */	addi r0, r3, __vt__11ActPickItem@l
/* 800BCB48 000B9AA8  3C 60 80 2B */	lis r3, lbl_802B6D78@ha
/* 800BCB4C 000B9AAC  90 1E 00 00 */	stw r0, 0(r30)
/* 800BCB50 000B9AB0  38 03 6D 78 */	addi r0, r3, lbl_802B6D78@l
/* 800BCB54 000B9AB4  38 60 00 24 */	li r3, 0x24
/* 800BCB58 000B9AB8  90 9E 00 18 */	stw r4, 0x18(r30)
/* 800BCB5C 000B9ABC  90 1E 00 10 */	stw r0, 0x10(r30)
/* 800BCB60 000B9AC0  4B F8 A4 A5 */	bl alloc__6SystemFUl
/* 800BCB64 000B9AC4  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BCB68 000B9AC8  41 82 00 10 */	beq .L_800BCB78
/* 800BCB6C 000B9ACC  38 7E 00 00 */	addi r3, r30, 0
/* 800BCB70 000B9AD0  38 9F 00 00 */	addi r4, r31, 0
/* 800BCB74 000B9AD4  4B FF E3 F5 */	bl __ct__7ActGotoFP4Piki
.L_800BCB78:
/* 800BCB78 000B9AD8  38 60 00 20 */	li r3, 0x20
/* 800BCB7C 000B9ADC  4B F8 A4 89 */	bl alloc__6SystemFUl
/* 800BCB80 000B9AE0  7C 7D 1B 79 */	or. r29, r3, r3
/* 800BCB84 000B9AE4  41 82 00 10 */	beq .L_800BCB94
/* 800BCB88 000B9AE8  38 7D 00 00 */	addi r3, r29, 0
/* 800BCB8C 000B9AEC  38 9F 00 00 */	addi r4, r31, 0
/* 800BCB90 000B9AF0  4B FE AE 69 */	bl __ct__7ActPickFP4Piki
.L_800BCB94:
/* 800BCB94 000B9AF4  80 61 00 08 */	lwz r3, 8(r1)
/* 800BCB98 000B9AF8  38 BE 00 00 */	addi r5, r30, 0
/* 800BCB9C 000B9AFC  38 FD 00 00 */	addi r7, r29, 0
/* 800BCBA0 000B9B00  4C C6 31 82 */	crclr 6
/* 800BCBA4 000B9B04  38 80 00 02 */	li r4, 2
/* 800BCBA8 000B9B08  38 C0 00 00 */	li r6, 0
/* 800BCBAC 000B9B0C  39 00 00 00 */	li r8, 0
/* 800BCBB0 000B9B10  48 00 77 C1 */	bl setChildren__6ActionFie
/* 800BCBB4 000B9B14  80 61 00 08 */	lwz r3, 8(r1)
/* 800BCBB8 000B9B18  38 00 00 00 */	li r0, 0
/* 800BCBBC 000B9B1C  90 03 00 18 */	stw r0, 0x18(r3)
/* 800BCBC0 000B9B20  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BCBC4 000B9B24  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BCBC8 000B9B28  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800BCBCC 000B9B2C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800BCBD0 000B9B30  38 21 00 20 */	addi r1, r1, 0x20
/* 800BCBD4 000B9B34  7C 08 03 A6 */	mtlr r0
/* 800BCBD8 000B9B38  4E 80 00 20 */	blr 
.endfn __ct__11ActPickItemFP4Piki

.fn findItem__11ActPickItemFv, global
/* 800BCBDC 000B9B3C  7C 08 02 A6 */	mflr r0
/* 800BCBE0 000B9B40  90 01 00 04 */	stw r0, 4(r1)
/* 800BCBE4 000B9B44  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 800BCBE8 000B9B48  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 800BCBEC 000B9B4C  BF 61 00 2C */	stmw r27, 0x2c(r1)
/* 800BCBF0 000B9B50  7C 7B 1B 78 */	mr r27, r3
/* 800BCBF4 000B9B54  3B 80 00 00 */	li r28, 0
/* 800BCBF8 000B9B58  83 CD 30 AC */	lwz r30, itemMgr@sda21(r13)
/* 800BCBFC 000B9B5C  C3 E2 93 A8 */	lfs f31, lbl_803E95A8@sda21(r2)
/* 800BCC00 000B9B60  81 9E 00 00 */	lwz r12, 0(r30)
/* 800BCC04 000B9B64  38 7E 00 00 */	addi r3, r30, 0
/* 800BCC08 000B9B68  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800BCC0C 000B9B6C  7D 88 03 A6 */	mtlr r12
/* 800BCC10 000B9B70  4E 80 00 21 */	blrl 
/* 800BCC14 000B9B74  7C 7D 1B 78 */	mr r29, r3
/* 800BCC18 000B9B78  48 00 00 CC */	b .L_800BCCE4
.L_800BCC1C:
/* 800BCC1C 000B9B7C  2C 1D FF FF */	cmpwi r29, -1
/* 800BCC20 000B9B80  40 82 00 24 */	bne .L_800BCC44
/* 800BCC24 000B9B84  7F C3 F3 78 */	mr r3, r30
/* 800BCC28 000B9B88  81 9E 00 00 */	lwz r12, 0(r30)
/* 800BCC2C 000B9B8C  38 80 00 00 */	li r4, 0
/* 800BCC30 000B9B90  81 8C 00 08 */	lwz r12, 8(r12)
/* 800BCC34 000B9B94  7D 88 03 A6 */	mtlr r12
/* 800BCC38 000B9B98  4E 80 00 21 */	blrl 
/* 800BCC3C 000B9B9C  7C 7F 1B 78 */	mr r31, r3
/* 800BCC40 000B9BA0  48 00 00 20 */	b .L_800BCC60
.L_800BCC44:
/* 800BCC44 000B9BA4  7F C3 F3 78 */	mr r3, r30
/* 800BCC48 000B9BA8  81 9E 00 00 */	lwz r12, 0(r30)
/* 800BCC4C 000B9BAC  7F A4 EB 78 */	mr r4, r29
/* 800BCC50 000B9BB0  81 8C 00 08 */	lwz r12, 8(r12)
/* 800BCC54 000B9BB4  7D 88 03 A6 */	mtlr r12
/* 800BCC58 000B9BB8  4E 80 00 21 */	blrl 
/* 800BCC5C 000B9BBC  7C 7F 1B 78 */	mr r31, r3
.L_800BCC60:
/* 800BCC60 000B9BC0  FC 20 F8 90 */	fmr f1, f31
/* 800BCC64 000B9BC4  80 9B 00 0C */	lwz r4, 0xc(r27)
/* 800BCC68 000B9BC8  7F E3 FB 78 */	mr r3, r31
/* 800BCC6C 000B9BCC  4B FD 0C 25 */	bl roughCull__FP8CreatureP8Creaturef
/* 800BCC70 000B9BD0  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BCC74 000B9BD4  40 82 00 54 */	bne .L_800BCCC8
/* 800BCC78 000B9BD8  80 1F 00 6C */	lwz r0, 0x6c(r31)
/* 800BCC7C 000B9BDC  2C 00 00 0E */	cmpwi r0, 0xe
/* 800BCC80 000B9BE0  40 82 00 48 */	bne .L_800BCCC8
/* 800BCC84 000B9BE4  7F E3 FB 78 */	mr r3, r31
/* 800BCC88 000B9BE8  81 9F 00 00 */	lwz r12, 0(r31)
/* 800BCC8C 000B9BEC  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800BCC90 000B9BF0  7D 88 03 A6 */	mtlr r12
/* 800BCC94 000B9BF4  4E 80 00 21 */	blrl 
/* 800BCC98 000B9BF8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BCC9C 000B9BFC  41 82 00 2C */	beq .L_800BCCC8
/* 800BCCA0 000B9C00  80 1F 02 A8 */	lwz r0, 0x2a8(r31)
/* 800BCCA4 000B9C04  28 00 00 00 */	cmplwi r0, 0
/* 800BCCA8 000B9C08  40 82 00 20 */	bne .L_800BCCC8
/* 800BCCAC 000B9C0C  7F E3 FB 78 */	mr r3, r31
/* 800BCCB0 000B9C10  80 9B 00 0C */	lwz r4, 0xc(r27)
/* 800BCCB4 000B9C14  4B FD 01 C9 */	bl qdist2__FP8CreatureP8Creature
/* 800BCCB8 000B9C18  FC 01 F8 40 */	fcmpo cr0, f1, f31
/* 800BCCBC 000B9C1C  40 80 00 0C */	bge .L_800BCCC8
/* 800BCCC0 000B9C20  FF E0 08 90 */	fmr f31, f1
/* 800BCCC4 000B9C24  7F FC FB 78 */	mr r28, r31
.L_800BCCC8:
/* 800BCCC8 000B9C28  7F C3 F3 78 */	mr r3, r30
/* 800BCCCC 000B9C2C  81 9E 00 00 */	lwz r12, 0(r30)
/* 800BCCD0 000B9C30  7F A4 EB 78 */	mr r4, r29
/* 800BCCD4 000B9C34  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800BCCD8 000B9C38  7D 88 03 A6 */	mtlr r12
/* 800BCCDC 000B9C3C  4E 80 00 21 */	blrl 
/* 800BCCE0 000B9C40  7C 7D 1B 78 */	mr r29, r3
.L_800BCCE4:
/* 800BCCE4 000B9C44  7F C3 F3 78 */	mr r3, r30
/* 800BCCE8 000B9C48  81 9E 00 00 */	lwz r12, 0(r30)
/* 800BCCEC 000B9C4C  7F A4 EB 78 */	mr r4, r29
/* 800BCCF0 000B9C50  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800BCCF4 000B9C54  7D 88 03 A6 */	mtlr r12
/* 800BCCF8 000B9C58  4E 80 00 21 */	blrl 
/* 800BCCFC 000B9C5C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BCD00 000B9C60  41 82 00 0C */	beq .L_800BCD0C
/* 800BCD04 000B9C64  38 00 00 01 */	li r0, 1
/* 800BCD08 000B9C68  48 00 00 30 */	b .L_800BCD38
.L_800BCD0C:
/* 800BCD0C 000B9C6C  7F C3 F3 78 */	mr r3, r30
/* 800BCD10 000B9C70  81 9E 00 00 */	lwz r12, 0(r30)
/* 800BCD14 000B9C74  7F A4 EB 78 */	mr r4, r29
/* 800BCD18 000B9C78  81 8C 00 08 */	lwz r12, 8(r12)
/* 800BCD1C 000B9C7C  7D 88 03 A6 */	mtlr r12
/* 800BCD20 000B9C80  4E 80 00 21 */	blrl 
/* 800BCD24 000B9C84  28 03 00 00 */	cmplwi r3, 0
/* 800BCD28 000B9C88  40 82 00 0C */	bne .L_800BCD34
/* 800BCD2C 000B9C8C  38 00 00 01 */	li r0, 1
/* 800BCD30 000B9C90  48 00 00 08 */	b .L_800BCD38
.L_800BCD34:
/* 800BCD34 000B9C94  38 00 00 00 */	li r0, 0
.L_800BCD38:
/* 800BCD38 000B9C98  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 800BCD3C 000B9C9C  41 82 FE E0 */	beq .L_800BCC1C
/* 800BCD40 000B9CA0  7F 83 E3 78 */	mr r3, r28
/* 800BCD44 000B9CA4  BB 61 00 2C */	lmw r27, 0x2c(r1)
/* 800BCD48 000B9CA8  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 800BCD4C 000B9CAC  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 800BCD50 000B9CB0  38 21 00 48 */	addi r1, r1, 0x48
/* 800BCD54 000B9CB4  7C 08 03 A6 */	mtlr r0
/* 800BCD58 000B9CB8  4E 80 00 20 */	blr 
.endfn findItem__11ActPickItemFv

.fn init__11ActPickItemFP8Creature, global
/* 800BCD5C 000B9CBC  7C 08 02 A6 */	mflr r0
/* 800BCD60 000B9CC0  90 01 00 04 */	stw r0, 4(r1)
/* 800BCD64 000B9CC4  38 00 00 00 */	li r0, 0
/* 800BCD68 000B9CC8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BCD6C 000B9CCC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BCD70 000B9CD0  7C 9F 23 79 */	or. r31, r4, r4
/* 800BCD74 000B9CD4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800BCD78 000B9CD8  3B C3 00 00 */	addi r30, r3, 0
/* 800BCD7C 000B9CDC  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800BCD80 000B9CE0  98 03 04 08 */	stb r0, 0x408(r3)
/* 800BCD84 000B9CE4  40 82 00 10 */	bne .L_800BCD94
/* 800BCD88 000B9CE8  7F C3 F3 78 */	mr r3, r30
/* 800BCD8C 000B9CEC  4B FF FE 51 */	bl findItem__11ActPickItemFv
/* 800BCD90 000B9CF0  7C 7F 1B 78 */	mr r31, r3
.L_800BCD94:
/* 800BCD94 000B9CF4  28 1F 00 00 */	cmplwi r31, 0
/* 800BCD98 000B9CF8  41 82 00 44 */	beq .L_800BCDDC
/* 800BCD9C 000B9CFC  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800BCDA0 000B9D00  28 03 00 00 */	cmplwi r3, 0
/* 800BCDA4 000B9D04  41 82 00 14 */	beq .L_800BCDB8
/* 800BCDA8 000B9D08  41 82 00 10 */	beq .L_800BCDB8
/* 800BCDAC 000B9D0C  48 02 75 C1 */	bl subCnt__12RefCountableFv
/* 800BCDB0 000B9D10  38 00 00 00 */	li r0, 0
/* 800BCDB4 000B9D14  90 1E 00 18 */	stw r0, 0x18(r30)
.L_800BCDB8:
/* 800BCDB8 000B9D18  93 FE 00 18 */	stw r31, 0x18(r30)
/* 800BCDBC 000B9D1C  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800BCDC0 000B9D20  28 03 00 00 */	cmplwi r3, 0
/* 800BCDC4 000B9D24  41 82 00 08 */	beq .L_800BCDCC
/* 800BCDC8 000B9D28  48 02 75 95 */	bl addCnt__12RefCountableFv
.L_800BCDCC:
/* 800BCDCC 000B9D2C  38 7E 00 00 */	addi r3, r30, 0
/* 800BCDD0 000B9D30  38 9F 00 00 */	addi r4, r31, 0
/* 800BCDD4 000B9D34  48 00 71 41 */	bl init__9AndActionFP8Creature
/* 800BCDD8 000B9D38  48 00 00 1C */	b .L_800BCDF4
.L_800BCDDC:
/* 800BCDDC 000B9D3C  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800BCDE0 000B9D40  28 03 00 00 */	cmplwi r3, 0
/* 800BCDE4 000B9D44  41 82 00 10 */	beq .L_800BCDF4
/* 800BCDE8 000B9D48  48 02 75 85 */	bl subCnt__12RefCountableFv
/* 800BCDEC 000B9D4C  38 00 00 00 */	li r0, 0
/* 800BCDF0 000B9D50  90 1E 00 18 */	stw r0, 0x18(r30)
.L_800BCDF4:
/* 800BCDF4 000B9D54  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BCDF8 000B9D58  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BCDFC 000B9D5C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800BCE00 000B9D60  38 21 00 20 */	addi r1, r1, 0x20
/* 800BCE04 000B9D64  7C 08 03 A6 */	mtlr r0
/* 800BCE08 000B9D68  4E 80 00 20 */	blr 
.endfn init__11ActPickItemFP8Creature

.fn exec__11ActPickItemFv, global
/* 800BCE0C 000B9D6C  7C 08 02 A6 */	mflr r0
/* 800BCE10 000B9D70  90 01 00 04 */	stw r0, 4(r1)
/* 800BCE14 000B9D74  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BCE18 000B9D78  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BCE1C 000B9D7C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800BCE20 000B9D80  7C 7E 1B 78 */	mr r30, r3
/* 800BCE24 000B9D84  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800BCE28 000B9D88  80 03 02 AC */	lwz r0, 0x2ac(r3)
/* 800BCE2C 000B9D8C  28 00 00 00 */	cmplwi r0, 0
/* 800BCE30 000B9D90  41 82 00 20 */	beq .L_800BCE50
/* 800BCE34 000B9D94  38 00 00 00 */	li r0, 0
/* 800BCE38 000B9D98  98 03 04 08 */	stb r0, 0x408(r3)
/* 800BCE3C 000B9D9C  38 00 00 06 */	li r0, 6
/* 800BCE40 000B9DA0  38 60 00 02 */	li r3, 2
/* 800BCE44 000B9DA4  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800BCE48 000B9DA8  98 04 04 00 */	stb r0, 0x400(r4)
/* 800BCE4C 000B9DAC  48 00 00 90 */	b .L_800BCEDC
.L_800BCE50:
/* 800BCE50 000B9DB0  83 FE 00 18 */	lwz r31, 0x18(r30)
/* 800BCE54 000B9DB4  28 1F 00 00 */	cmplwi r31, 0
/* 800BCE58 000B9DB8  38 7F 00 00 */	addi r3, r31, 0
/* 800BCE5C 000B9DBC  40 82 00 0C */	bne .L_800BCE68
/* 800BCE60 000B9DC0  38 60 00 01 */	li r3, 1
/* 800BCE64 000B9DC4  48 00 00 78 */	b .L_800BCEDC
.L_800BCE68:
/* 800BCE68 000B9DC8  81 83 00 00 */	lwz r12, 0(r3)
/* 800BCE6C 000B9DCC  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800BCE70 000B9DD0  7D 88 03 A6 */	mtlr r12
/* 800BCE74 000B9DD4  4E 80 00 21 */	blrl 
/* 800BCE78 000B9DD8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BCE7C 000B9DDC  40 82 00 0C */	bne .L_800BCE88
/* 800BCE80 000B9DE0  38 60 00 01 */	li r3, 1
/* 800BCE84 000B9DE4  48 00 00 58 */	b .L_800BCEDC
.L_800BCE88:
/* 800BCE88 000B9DE8  80 1F 02 A8 */	lwz r0, 0x2a8(r31)
/* 800BCE8C 000B9DEC  28 00 00 00 */	cmplwi r0, 0
/* 800BCE90 000B9DF0  41 82 00 20 */	beq .L_800BCEB0
/* 800BCE94 000B9DF4  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BCE98 000B9DF8  7C 00 18 40 */	cmplw r0, r3
/* 800BCE9C 000B9DFC  41 82 00 14 */	beq .L_800BCEB0
/* 800BCEA0 000B9E00  38 00 00 07 */	li r0, 7
/* 800BCEA4 000B9E04  98 03 04 00 */	stb r0, 0x400(r3)
/* 800BCEA8 000B9E08  38 60 00 01 */	li r3, 1
/* 800BCEAC 000B9E0C  48 00 00 30 */	b .L_800BCEDC
.L_800BCEB0:
/* 800BCEB0 000B9E10  7F C3 F3 78 */	mr r3, r30
/* 800BCEB4 000B9E14  48 00 71 41 */	bl exec__9AndActionFv
/* 800BCEB8 000B9E18  2C 03 00 01 */	cmpwi r3, 1
/* 800BCEBC 000B9E1C  40 82 00 20 */	bne .L_800BCEDC
/* 800BCEC0 000B9E20  7F C3 F3 78 */	mr r3, r30
/* 800BCEC4 000B9E24  81 9E 00 00 */	lwz r12, 0(r30)
/* 800BCEC8 000B9E28  38 80 00 00 */	li r4, 0
/* 800BCECC 000B9E2C  81 8C 00 48 */	lwz r12, 0x48(r12)
/* 800BCED0 000B9E30  7D 88 03 A6 */	mtlr r12
/* 800BCED4 000B9E34  4E 80 00 21 */	blrl 
/* 800BCED8 000B9E38  38 60 00 00 */	li r3, 0
.L_800BCEDC:
/* 800BCEDC 000B9E3C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BCEE0 000B9E40  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BCEE4 000B9E44  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800BCEE8 000B9E48  38 21 00 20 */	addi r1, r1, 0x20
/* 800BCEEC 000B9E4C  7C 08 03 A6 */	mtlr r0
/* 800BCEF0 000B9E50  4E 80 00 20 */	blr 
.endfn exec__11ActPickItemFv

.fn cleanup__11ActPickItemFv, global
/* 800BCEF4 000B9E54  7C 08 02 A6 */	mflr r0
/* 800BCEF8 000B9E58  90 01 00 04 */	stw r0, 4(r1)
/* 800BCEFC 000B9E5C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BCF00 000B9E60  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BCF04 000B9E64  7C 7F 1B 78 */	mr r31, r3
/* 800BCF08 000B9E68  80 63 00 18 */	lwz r3, 0x18(r3)
/* 800BCF0C 000B9E6C  28 03 00 00 */	cmplwi r3, 0
/* 800BCF10 000B9E70  41 82 00 10 */	beq .L_800BCF20
/* 800BCF14 000B9E74  48 02 74 59 */	bl subCnt__12RefCountableFv
/* 800BCF18 000B9E78  38 00 00 00 */	li r0, 0
/* 800BCF1C 000B9E7C  90 1F 00 18 */	stw r0, 0x18(r31)
.L_800BCF20:
/* 800BCF20 000B9E80  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BCF24 000B9E84  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BCF28 000B9E88  38 21 00 20 */	addi r1, r1, 0x20
/* 800BCF2C 000B9E8C  7C 08 03 A6 */	mtlr r0
/* 800BCF30 000B9E90  4E 80 00 20 */	blr 
.endfn cleanup__11ActPickItemFv

.fn init__9ActFlowerFP8Creature, global
/* 800BCF34 000B9E94  7C 08 02 A6 */	mflr r0
/* 800BCF38 000B9E98  38 A0 00 20 */	li r5, 0x20
/* 800BCF3C 000B9E9C  90 01 00 04 */	stw r0, 4(r1)
/* 800BCF40 000B9EA0  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800BCF44 000B9EA4  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 800BCF48 000B9EA8  7C 7F 1B 78 */	mr r31, r3
/* 800BCF4C 000B9EAC  93 C1 00 48 */	stw r30, 0x48(r1)
/* 800BCF50 000B9EB0  93 A1 00 44 */	stw r29, 0x44(r1)
/* 800BCF54 000B9EB4  C0 0D B8 30 */	lfs f0, lbl_803E0550@sda21(r13)
/* 800BCF58 000B9EB8  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800BCF5C 000B9EBC  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800BCF60 000B9EC0  C0 0D B8 34 */	lfs f0, lbl_803E0554@sda21(r13)
/* 800BCF64 000B9EC4  D0 03 00 04 */	stfs f0, 4(r3)
/* 800BCF68 000B9EC8  C0 0D B8 38 */	lfs f0, lbl_803E0558@sda21(r13)
/* 800BCF6C 000B9ECC  D0 03 00 08 */	stfs f0, 8(r3)
/* 800BCF70 000B9ED0  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BCF74 000B9ED4  C0 0D B8 3C */	lfs f0, lbl_803E055C@sda21(r13)
/* 800BCF78 000B9ED8  D4 03 00 70 */	stfsu f0, 0x70(r3)
/* 800BCF7C 000B9EDC  C0 0D B8 40 */	lfs f0, lbl_803E0560@sda21(r13)
/* 800BCF80 000B9EE0  D0 03 00 04 */	stfs f0, 4(r3)
/* 800BCF84 000B9EE4  C0 0D B8 44 */	lfs f0, lbl_803E0564@sda21(r13)
/* 800BCF88 000B9EE8  D0 03 00 08 */	stfs f0, 8(r3)
/* 800BCF8C 000B9EEC  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800BCF90 000B9EF0  80 64 04 90 */	lwz r3, 0x490(r4)
/* 800BCF94 000B9EF4  81 83 00 00 */	lwz r12, 0(r3)
/* 800BCF98 000B9EF8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800BCF9C 000B9EFC  7D 88 03 A6 */	mtlr r12
/* 800BCFA0 000B9F00  4E 80 00 21 */	blrl 
/* 800BCFA4 000B9F04  38 80 00 00 */	li r4, 0
/* 800BCFA8 000B9F08  98 9F 00 1C */	stb r4, 0x1c(r31)
/* 800BCFAC 000B9F0C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BCFB0 000B9F10  80 03 02 AC */	lwz r0, 0x2ac(r3)
/* 800BCFB4 000B9F14  28 00 00 00 */	cmplwi r0, 0
/* 800BCFB8 000B9F18  40 82 00 10 */	bne .L_800BCFC8
/* 800BCFBC 000B9F1C  38 00 00 01 */	li r0, 1
/* 800BCFC0 000B9F20  98 1F 00 1D */	stb r0, 0x1d(r31)
/* 800BCFC4 000B9F24  48 00 00 B0 */	b .L_800BD074
.L_800BCFC8:
/* 800BCFC8 000B9F28  98 9F 00 1D */	stb r4, 0x1d(r31)
/* 800BCFCC 000B9F2C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BCFD0 000B9F30  80 83 02 24 */	lwz r4, 0x224(r3)
/* 800BCFD4 000B9F34  80 63 05 14 */	lwz r3, 0x514(r3)
/* 800BCFD8 000B9F38  80 04 01 28 */	lwz r0, 0x128(r4)
/* 800BCFDC 000B9F3C  38 63 00 01 */	addi r3, r3, 1
/* 800BCFE0 000B9F40  7C 03 00 00 */	cmpw r3, r0
/* 800BCFE4 000B9F44  41 80 00 48 */	blt .L_800BD02C
/* 800BCFE8 000B9F48  28 1F 00 00 */	cmplwi r31, 0
/* 800BCFEC 000B9F4C  3B BF 00 00 */	addi r29, r31, 0
/* 800BCFF0 000B9F50  41 82 00 08 */	beq .L_800BCFF8
/* 800BCFF4 000B9F54  83 BF 00 14 */	lwz r29, 0x14(r31)
.L_800BCFF8:
/* 800BCFF8 000B9F58  38 61 00 30 */	addi r3, r1, 0x30
/* 800BCFFC 000B9F5C  38 80 00 12 */	li r4, 0x12
/* 800BD000 000B9F60  48 06 1F 59 */	bl __ct__14PaniMotionInfoFi
/* 800BD004 000B9F64  3B C3 00 00 */	addi r30, r3, 0
/* 800BD008 000B9F68  38 BD 00 00 */	addi r5, r29, 0
/* 800BD00C 000B9F6C  38 61 00 38 */	addi r3, r1, 0x38
/* 800BD010 000B9F70  38 80 00 12 */	li r4, 0x12
/* 800BD014 000B9F74  48 06 1F 79 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800BD018 000B9F78  7C 64 1B 78 */	mr r4, r3
/* 800BD01C 000B9F7C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BD020 000B9F80  7F C5 F3 78 */	mr r5, r30
/* 800BD024 000B9F84  48 00 D9 B5 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800BD028 000B9F88  48 00 00 44 */	b .L_800BD06C
.L_800BD02C:
/* 800BD02C 000B9F8C  28 1F 00 00 */	cmplwi r31, 0
/* 800BD030 000B9F90  3B BF 00 00 */	addi r29, r31, 0
/* 800BD034 000B9F94  41 82 00 08 */	beq .L_800BD03C
/* 800BD038 000B9F98  83 BF 00 14 */	lwz r29, 0x14(r31)
.L_800BD03C:
/* 800BD03C 000B9F9C  38 61 00 20 */	addi r3, r1, 0x20
/* 800BD040 000B9FA0  38 80 00 11 */	li r4, 0x11
/* 800BD044 000B9FA4  48 06 1F 15 */	bl __ct__14PaniMotionInfoFi
/* 800BD048 000B9FA8  3B C3 00 00 */	addi r30, r3, 0
/* 800BD04C 000B9FAC  38 BD 00 00 */	addi r5, r29, 0
/* 800BD050 000B9FB0  38 61 00 28 */	addi r3, r1, 0x28
/* 800BD054 000B9FB4  38 80 00 11 */	li r4, 0x11
/* 800BD058 000B9FB8  48 06 1F 35 */	bl __ct__14PaniMotionInfoFiP19PaniAnimKeyListener
/* 800BD05C 000B9FBC  7C 64 1B 78 */	mr r4, r3
/* 800BD060 000B9FC0  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BD064 000B9FC4  7F C5 F3 78 */	mr r5, r30
/* 800BD068 000B9FC8  48 00 D9 71 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
.L_800BD06C:
/* 800BD06C 000B9FCC  C0 02 93 AC */	lfs f0, lbl_803E95AC@sda21(r2)
/* 800BD070 000B9FD0  D0 1F 00 18 */	stfs f0, 0x18(r31)
.L_800BD074:
/* 800BD074 000B9FD4  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800BD078 000B9FD8  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 800BD07C 000B9FDC  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 800BD080 000B9FE0  83 A1 00 44 */	lwz r29, 0x44(r1)
/* 800BD084 000B9FE4  38 21 00 50 */	addi r1, r1, 0x50
/* 800BD088 000B9FE8  7C 08 03 A6 */	mtlr r0
/* 800BD08C 000B9FEC  4E 80 00 20 */	blr 
.endfn init__9ActFlowerFP8Creature

.fn animationKeyUpdated__9ActFlowerFR16PaniAnimKeyEvent, global
/* 800BD090 000B9FF0  7C 08 02 A6 */	mflr r0
/* 800BD094 000B9FF4  90 01 00 04 */	stw r0, 4(r1)
/* 800BD098 000B9FF8  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800BD09C 000B9FFC  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 800BD0A0 000BA000  3B E3 00 00 */	addi r31, r3, 0
/* 800BD0A4 000BA004  93 C1 00 48 */	stw r30, 0x48(r1)
/* 800BD0A8 000BA008  80 04 00 00 */	lwz r0, 0(r4)
/* 800BD0AC 000BA00C  2C 00 00 01 */	cmpwi r0, 1
/* 800BD0B0 000BA010  41 82 00 14 */	beq .L_800BD0C4
/* 800BD0B4 000BA014  40 80 00 E4 */	bge .L_800BD198
/* 800BD0B8 000BA018  2C 00 00 00 */	cmpwi r0, 0
/* 800BD0BC 000BA01C  40 80 00 D4 */	bge .L_800BD190
/* 800BD0C0 000BA020  48 00 00 D8 */	b .L_800BD198
.L_800BD0C4:
/* 800BD0C4 000BA024  80 DF 00 0C */	lwz r6, 0xc(r31)
/* 800BD0C8 000BA028  3C 80 80 2B */	lis r4, __vt__11Interaction@ha
/* 800BD0CC 000BA02C  38 04 CF 9C */	addi r0, r4, __vt__11Interaction@l
/* 800BD0D0 000BA030  C0 02 93 B0 */	lfs f0, lbl_803E95B0@sda21(r2)
/* 800BD0D4 000BA034  83 C6 02 AC */	lwz r30, 0x2ac(r6)
/* 800BD0D8 000BA038  3C 60 80 2B */	lis r3, __vt__15InteractRelease@ha
/* 800BD0DC 000BA03C  90 01 00 38 */	stw r0, 0x38(r1)
/* 800BD0E0 000BA040  38 03 D1 8C */	addi r0, r3, __vt__15InteractRelease@l
/* 800BD0E4 000BA044  38 81 00 38 */	addi r4, r1, 0x38
/* 800BD0E8 000BA048  90 C1 00 3C */	stw r6, 0x3c(r1)
/* 800BD0EC 000BA04C  38 7E 00 00 */	addi r3, r30, 0
/* 800BD0F0 000BA050  90 01 00 38 */	stw r0, 0x38(r1)
/* 800BD0F4 000BA054  D0 01 00 40 */	stfs f0, 0x40(r1)
/* 800BD0F8 000BA058  81 9E 00 00 */	lwz r12, 0(r30)
/* 800BD0FC 000BA05C  81 8C 00 A0 */	lwz r12, 0xa0(r12)
/* 800BD100 000BA060  7D 88 03 A6 */	mtlr r12
/* 800BD104 000BA064  4E 80 00 21 */	blrl 
/* 800BD108 000BA068  38 7E 00 00 */	addi r3, r30, 0
/* 800BD10C 000BA06C  38 80 00 00 */	li r4, 0
/* 800BD110 000BA070  4B FC DB D1 */	bl kill__8CreatureFb
/* 800BD114 000BA074  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800BD118 000BA078  80 64 05 14 */	lwz r3, 0x514(r4)
/* 800BD11C 000BA07C  38 03 00 01 */	addi r0, r3, 1
/* 800BD120 000BA080  90 04 05 14 */	stw r0, 0x514(r4)
/* 800BD124 000BA084  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BD128 000BA088  80 A3 02 24 */	lwz r5, 0x224(r3)
/* 800BD12C 000BA08C  80 C3 05 14 */	lwz r6, 0x514(r3)
/* 800BD130 000BA090  80 05 01 28 */	lwz r0, 0x128(r5)
/* 800BD134 000BA094  7C 06 00 00 */	cmpw r6, r0
/* 800BD138 000BA098  41 80 00 34 */	blt .L_800BD16C
/* 800BD13C 000BA09C  81 83 00 00 */	lwz r12, 0(r3)
/* 800BD140 000BA0A0  38 80 00 02 */	li r4, 2
/* 800BD144 000BA0A4  81 8C 01 30 */	lwz r12, 0x130(r12)
/* 800BD148 000BA0A8  7D 88 03 A6 */	mtlr r12
/* 800BD14C 000BA0AC  4E 80 00 21 */	blrl 
/* 800BD150 000BA0B0  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800BD154 000BA0B4  84 03 05 14 */	lwzu r0, 0x514(r3)
/* 800BD158 000BA0B8  2C 00 00 64 */	cmpwi r0, 0x64
/* 800BD15C 000BA0BC  40 81 00 3C */	ble .L_800BD198
/* 800BD160 000BA0C0  38 00 00 64 */	li r0, 0x64
/* 800BD164 000BA0C4  90 03 00 00 */	stw r0, 0(r3)
/* 800BD168 000BA0C8  48 00 00 30 */	b .L_800BD198
.L_800BD16C:
/* 800BD16C 000BA0CC  80 05 01 18 */	lwz r0, 0x118(r5)
/* 800BD170 000BA0D0  7C 06 00 00 */	cmpw r6, r0
/* 800BD174 000BA0D4  41 80 00 24 */	blt .L_800BD198
/* 800BD178 000BA0D8  81 83 00 00 */	lwz r12, 0(r3)
/* 800BD17C 000BA0DC  38 80 00 01 */	li r4, 1
/* 800BD180 000BA0E0  81 8C 01 30 */	lwz r12, 0x130(r12)
/* 800BD184 000BA0E4  7D 88 03 A6 */	mtlr r12
/* 800BD188 000BA0E8  4E 80 00 21 */	blrl 
/* 800BD18C 000BA0EC  48 00 00 0C */	b .L_800BD198
.L_800BD190:
/* 800BD190 000BA0F0  38 00 00 01 */	li r0, 1
/* 800BD194 000BA0F4  98 1F 00 1C */	stb r0, 0x1c(r31)
.L_800BD198:
/* 800BD198 000BA0F8  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800BD19C 000BA0FC  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 800BD1A0 000BA100  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 800BD1A4 000BA104  38 21 00 50 */	addi r1, r1, 0x50
/* 800BD1A8 000BA108  7C 08 03 A6 */	mtlr r0
/* 800BD1AC 000BA10C  4E 80 00 20 */	blr 
.endfn animationKeyUpdated__9ActFlowerFR16PaniAnimKeyEvent

.fn cleanup__9ActFlowerFv, global
/* 800BD1B0 000BA110  7C 08 02 A6 */	mflr r0
/* 800BD1B4 000BA114  38 A0 00 00 */	li r5, 0
/* 800BD1B8 000BA118  90 01 00 04 */	stw r0, 4(r1)
/* 800BD1BC 000BA11C  94 21 FF F8 */	stwu r1, -8(r1)
/* 800BD1C0 000BA120  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800BD1C4 000BA124  80 64 04 90 */	lwz r3, 0x490(r4)
/* 800BD1C8 000BA128  81 83 00 00 */	lwz r12, 0(r3)
/* 800BD1CC 000BA12C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800BD1D0 000BA130  7D 88 03 A6 */	mtlr r12
/* 800BD1D4 000BA134  4E 80 00 21 */	blrl 
/* 800BD1D8 000BA138  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800BD1DC 000BA13C  38 21 00 08 */	addi r1, r1, 8
/* 800BD1E0 000BA140  7C 08 03 A6 */	mtlr r0
/* 800BD1E4 000BA144  4E 80 00 20 */	blr 
.endfn cleanup__9ActFlowerFv

.fn exec__9ActFlowerFv, global
/* 800BD1E8 000BA148  88 03 00 1D */	lbz r0, 0x1d(r3)
/* 800BD1EC 000BA14C  28 00 00 00 */	cmplwi r0, 0
/* 800BD1F0 000BA150  41 82 00 0C */	beq .L_800BD1FC
/* 800BD1F4 000BA154  38 60 00 01 */	li r3, 1
/* 800BD1F8 000BA158  4E 80 00 20 */	blr 
.L_800BD1FC:
/* 800BD1FC 000BA15C  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 800BD200 000BA160  C0 23 00 18 */	lfs f1, 0x18(r3)
/* 800BD204 000BA164  C0 04 02 8C */	lfs f0, 0x28c(r4)
/* 800BD208 000BA168  EC 01 00 2A */	fadds f0, f1, f0
/* 800BD20C 000BA16C  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 800BD210 000BA170  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800BD214 000BA174  80 84 02 AC */	lwz r4, 0x2ac(r4)
/* 800BD218 000BA178  28 04 00 00 */	cmplwi r4, 0
/* 800BD21C 000BA17C  41 82 00 24 */	beq .L_800BD240
/* 800BD220 000BA180  C0 22 93 B0 */	lfs f1, lbl_803E95B0@sda21(r2)
/* 800BD224 000BA184  C0 03 00 18 */	lfs f0, 0x18(r3)
/* 800BD228 000BA188  C0 42 93 B4 */	lfs f2, lbl_803E95B4@sda21(r2)
/* 800BD22C 000BA18C  EC 01 00 28 */	fsubs f0, f1, f0
/* 800BD230 000BA190  EC 02 00 32 */	fmuls f0, f2, f0
/* 800BD234 000BA194  D0 04 00 7C */	stfs f0, 0x7c(r4)
/* 800BD238 000BA198  D0 04 00 80 */	stfs f0, 0x80(r4)
/* 800BD23C 000BA19C  D0 04 00 84 */	stfs f0, 0x84(r4)
.L_800BD240:
/* 800BD240 000BA1A0  88 03 00 1C */	lbz r0, 0x1c(r3)
/* 800BD244 000BA1A4  28 00 00 00 */	cmplwi r0, 0
/* 800BD248 000BA1A8  41 82 00 0C */	beq .L_800BD254
/* 800BD24C 000BA1AC  38 60 00 02 */	li r3, 2
/* 800BD250 000BA1B0  4E 80 00 20 */	blr 
.L_800BD254:
/* 800BD254 000BA1B4  38 60 00 00 */	li r3, 0
/* 800BD258 000BA1B8  4E 80 00 20 */	blr 
.endfn exec__9ActFlowerFv

.fn __dt__9ActFlowerFv, weak
/* 800BD25C 000BA1BC  7C 08 02 A6 */	mflr r0
/* 800BD260 000BA1C0  90 01 00 04 */	stw r0, 4(r1)
/* 800BD264 000BA1C4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BD268 000BA1C8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BD26C 000BA1CC  3B E4 00 00 */	addi r31, r4, 0
/* 800BD270 000BA1D0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BD274 000BA1D4  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BD278 000BA1D8  41 82 00 48 */	beq .L_800BD2C0
/* 800BD27C 000BA1DC  3C 60 80 2B */	lis r3, __vt__9ActFlower@ha
/* 800BD280 000BA1E0  38 63 6E 14 */	addi r3, r3, __vt__9ActFlower@l
/* 800BD284 000BA1E4  90 7E 00 00 */	stw r3, 0(r30)
/* 800BD288 000BA1E8  38 C3 00 68 */	addi r6, r3, 0x68
/* 800BD28C 000BA1EC  38 1E 00 20 */	addi r0, r30, 0x20
/* 800BD290 000BA1F0  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 800BD294 000BA1F4  38 7E 00 00 */	addi r3, r30, 0
/* 800BD298 000BA1F8  38 80 00 00 */	li r4, 0
/* 800BD29C 000BA1FC  90 C5 00 00 */	stw r6, 0(r5)
/* 800BD2A0 000BA200  80 BE 00 14 */	lwz r5, 0x14(r30)
/* 800BD2A4 000BA204  7C 05 00 50 */	subf r0, r5, r0
/* 800BD2A8 000BA208  90 05 00 04 */	stw r0, 4(r5)
/* 800BD2AC 000BA20C  48 00 6B 5D */	bl __dt__6ActionFv
/* 800BD2B0 000BA210  7F E0 07 35 */	extsh. r0, r31
/* 800BD2B4 000BA214  40 81 00 0C */	ble .L_800BD2C0
/* 800BD2B8 000BA218  7F C3 F3 78 */	mr r3, r30
/* 800BD2BC 000BA21C  4B F8 9E F1 */	bl __dl__FPv
.L_800BD2C0:
/* 800BD2C0 000BA220  7F C3 F3 78 */	mr r3, r30
/* 800BD2C4 000BA224  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BD2C8 000BA228  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BD2CC 000BA22C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BD2D0 000BA230  38 21 00 18 */	addi r1, r1, 0x18
/* 800BD2D4 000BA234  7C 08 03 A6 */	mtlr r0
/* 800BD2D8 000BA238  4E 80 00 20 */	blr 
.endfn __dt__9ActFlowerFv

.fn __dt__11ActPickItemFv, weak
/* 800BD2DC 000BA23C  7C 08 02 A6 */	mflr r0
/* 800BD2E0 000BA240  90 01 00 04 */	stw r0, 4(r1)
/* 800BD2E4 000BA244  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BD2E8 000BA248  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BD2EC 000BA24C  3B E4 00 00 */	addi r31, r4, 0
/* 800BD2F0 000BA250  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BD2F4 000BA254  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BD2F8 000BA258  41 82 00 3C */	beq .L_800BD334
/* 800BD2FC 000BA25C  3C 60 80 2B */	lis r3, __vt__11ActPickItem@ha
/* 800BD300 000BA260  38 03 6E DC */	addi r0, r3, __vt__11ActPickItem@l
/* 800BD304 000BA264  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD308 000BA268  41 82 00 1C */	beq .L_800BD324
/* 800BD30C 000BA26C  3C 60 80 2C */	lis r3, __vt__9AndAction@ha
/* 800BD310 000BA270  38 03 81 30 */	addi r0, r3, __vt__9AndAction@l
/* 800BD314 000BA274  90 1E 00 00 */	stw r0, 0(r30)
/* 800BD318 000BA278  38 7E 00 00 */	addi r3, r30, 0
/* 800BD31C 000BA27C  38 80 00 00 */	li r4, 0
/* 800BD320 000BA280  48 00 6A E9 */	bl __dt__6ActionFv
.L_800BD324:
/* 800BD324 000BA284  7F E0 07 35 */	extsh. r0, r31
/* 800BD328 000BA288  40 81 00 0C */	ble .L_800BD334
/* 800BD32C 000BA28C  7F C3 F3 78 */	mr r3, r30
/* 800BD330 000BA290  4B F8 9E 7D */	bl __dl__FPv
.L_800BD334:
/* 800BD334 000BA294  7F C3 F3 78 */	mr r3, r30
/* 800BD338 000BA298  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BD33C 000BA29C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BD340 000BA2A0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BD344 000BA2A4  38 21 00 18 */	addi r1, r1, 0x18
/* 800BD348 000BA2A8  7C 08 03 A6 */	mtlr r0
/* 800BD34C 000BA2AC  4E 80 00 20 */	blr 
.endfn __dt__11ActPickItemFv

.fn "@32@4@animationKeyUpdated__9ActFlowerFR16PaniAnimKeyEvent", weak
/* 800BD350 000BA2B0  39 60 00 04 */	li r11, 4
/* 800BD354 000BA2B4  7D 63 58 2E */	lwzx r11, r3, r11
/* 800BD358 000BA2B8  7C 63 5A 14 */	add r3, r3, r11
/* 800BD35C 000BA2BC  38 63 FF E0 */	addi r3, r3, -32
/* 800BD360 000BA2C0  4B FF FD 30 */	b animationKeyUpdated__9ActFlowerFR16PaniAnimKeyEvent
.endfn "@32@4@animationKeyUpdated__9ActFlowerFR16PaniAnimKeyEvent"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B6D60, local
	.asciz "aiPick.cpp"
.endobj lbl_802B6D60
.balign 4
.obj lbl_802B6D6C, local
	.asciz "PickItem"
.endobj lbl_802B6D6C
.balign 4
.obj lbl_802B6D78, local
	.asciz "pick item"
.endobj lbl_802B6D78
.balign 4
.obj lbl_802B6D84, local
	.asciz "Interaction"
.endobj lbl_802B6D84
.balign 4
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
.obj lbl_802B6DBC, local
	.asciz "ActFlower"
.endobj lbl_802B6DBC
.balign 4
.obj lbl_802B6DC8, local
	.asciz "PaniAnimKeyListener"
.endobj lbl_802B6DC8
.balign 4
.obj lbl_802B6DDC, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B6DDC
.balign 4
.obj lbl_802B6DEC, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B6DEC
.obj lbl_802B6DF8, local
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x00000020
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0x00000000
	.4byte __RTTI__6Action
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B6DF8
.obj __vt__9ActFlower, global
	.4byte __RTTI__9ActFlower
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__6ActionFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__9ActFlowerFv
	.4byte init__9ActFlowerFP8Creature
	.4byte exec__9ActFlowerFv
	.4byte cleanup__9ActFlowerFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
	.4byte animationKeyUpdated__9ActFlowerFR16PaniAnimKeyEvent
	.4byte __RTTI__9ActFlower
	.4byte 0xFFFFFFE0
	.4byte "@32@4@animationKeyUpdated__9ActFlowerFR16PaniAnimKeyEvent"
.endobj __vt__9ActFlower
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
.obj lbl_802B6E94, local
	.asciz "ActPickItem"
.endobj lbl_802B6E94
.balign 4
.obj lbl_802B6EA0, local
	.asciz "AndAction"
.endobj lbl_802B6EA0
.balign 4
.obj lbl_802B6EAC, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B6EAC
.obj lbl_802B6EC0, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte __RTTI__9AndAction
	.4byte 0
	.4byte 0
.endobj lbl_802B6EC0
.obj __vt__11ActPickItem, global
	.4byte __RTTI__11ActPickItem
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__6ActionFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__11ActPickItemFv
	.4byte init__11ActPickItemFP8Creature
	.4byte exec__11ActPickItemFv
	.4byte cleanup__11ActPickItemFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
.endobj __vt__11ActPickItem
.obj lbl_802B6F40, local
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x30)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x58)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x6C)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x80)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x94)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xA8)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xBC)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xD0)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0x44)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xF8)
	.4byte ("procMsg__15Receiver<4Piki>FP4PikiP3Msg"+0xE4)
.endobj lbl_802B6F40

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E0550, local
	.float 0.0
.endobj lbl_803E0550
.obj lbl_803E0554, local
	.float 0.0
.endobj lbl_803E0554
.obj lbl_803E0558, local
	.float 0.0
.endobj lbl_803E0558
.obj lbl_803E055C, local
	.float 0.0
.endobj lbl_803E055C
.obj lbl_803E0560, local
	.float 0.0
.endobj lbl_803E0560
.obj lbl_803E0564, local
	.float 0.0
.endobj lbl_803E0564
.obj __RTTI__19PaniAnimKeyListener, local
	.4byte lbl_802B6DC8
	.4byte 0
.endobj __RTTI__19PaniAnimKeyListener
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B6DDC
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E0578, local
	.asciz "Action"
.endobj lbl_803E0578
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E0578
	.4byte lbl_802B6DEC
.endobj __RTTI__6Action
.obj __RTTI__9ActFlower, local
	.4byte lbl_802B6DBC
	.4byte lbl_802B6DF8
.endobj __RTTI__9ActFlower
.obj __RTTI__9AndAction, local
	.4byte lbl_802B6EA0
	.4byte lbl_802B6EAC
.endobj __RTTI__9AndAction
.obj __RTTI__11ActPickItem, local
	.4byte lbl_802B6E94
	.4byte lbl_802B6EC0
.endobj __RTTI__11ActPickItem

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E95A8, local
	.float 200.0
.endobj lbl_803E95A8
.obj lbl_803E95AC, local
	.float 0.0
.endobj lbl_803E95AC
.obj lbl_803E95B0, local
	.float 1.0
.endobj lbl_803E95B0
.obj lbl_803E95B4, local
	.float 0.3
.endobj lbl_803E95B4
