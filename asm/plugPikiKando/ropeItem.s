.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__8RopeItemFP12CreaturePropP5Shape, global
/* 800ED9DC 000EA93C  7C 08 02 A6 */	mflr r0
/* 800ED9E0 000EA940  90 01 00 04 */	stw r0, 4(r1)
/* 800ED9E4 000EA944  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800ED9E8 000EA948  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800ED9EC 000EA94C  3B E5 00 00 */	addi r31, r5, 0
/* 800ED9F0 000EA950  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800ED9F4 000EA954  3B C3 00 00 */	addi r30, r3, 0
/* 800ED9F8 000EA958  4B FA 6C AD */	bl __ct__12RopeCreatureFP12CreatureProp
/* 800ED9FC 000EA95C  3C 60 80 2C */	lis r3, __vt__8RopeItem@ha
/* 800EDA00 000EA960  38 03 D4 EC */	addi r0, r3, __vt__8RopeItem@l
/* 800EDA04 000EA964  3C 60 80 09 */	lis r3, __ct__10SearchDataFv@ha
/* 800EDA08 000EA968  90 1E 00 00 */	stw r0, 0(r30)
/* 800EDA0C 000EA96C  38 83 A7 F8 */	addi r4, r3, __ct__10SearchDataFv@l
/* 800EDA10 000EA970  38 7E 02 D4 */	addi r3, r30, 0x2d4
/* 800EDA14 000EA974  38 A0 00 00 */	li r5, 0
/* 800EDA18 000EA978  38 C0 00 0C */	li r6, 0xc
/* 800EDA1C 000EA97C  38 E0 00 03 */	li r7, 3
/* 800EDA20 000EA980  48 12 70 51 */	bl __construct_array
/* 800EDA24 000EA984  93 FE 02 F8 */	stw r31, 0x2f8(r30)
/* 800EDA28 000EA988  38 00 00 04 */	li r0, 4
/* 800EDA2C 000EA98C  38 7E 01 B8 */	addi r3, r30, 0x1b8
/* 800EDA30 000EA990  90 1E 00 68 */	stw r0, 0x68(r30)
/* 800EDA34 000EA994  38 9E 02 D4 */	addi r4, r30, 0x2d4
/* 800EDA38 000EA998  38 A0 00 03 */	li r5, 3
/* 800EDA3C 000EA99C  80 1E 00 C8 */	lwz r0, 0xc8(r30)
/* 800EDA40 000EA9A0  54 00 05 EA */	rlwinm r0, r0, 0, 0x17, 0x15
/* 800EDA44 000EA9A4  90 1E 00 C8 */	stw r0, 0xc8(r30)
/* 800EDA48 000EA9A8  80 1E 00 C8 */	lwz r0, 0xc8(r30)
/* 800EDA4C 000EA9AC  60 00 00 01 */	ori r0, r0, 1
/* 800EDA50 000EA9B0  90 1E 00 C8 */	stw r0, 0xc8(r30)
/* 800EDA54 000EA9B4  4B FF 62 2D */	bl init__12SearchBufferFP10SearchDatai
/* 800EDA58 000EA9B8  38 00 00 12 */	li r0, 0x12
/* 800EDA5C 000EA9BC  90 1E 00 6C */	stw r0, 0x6c(r30)
/* 800EDA60 000EA9C0  38 00 00 00 */	li r0, 0
/* 800EDA64 000EA9C4  38 7E 00 00 */	addi r3, r30, 0
/* 800EDA68 000EA9C8  C0 02 9B 28 */	lfs f0, lbl_803E9D28@sda21(r2)
/* 800EDA6C 000EA9CC  D0 1E 02 70 */	stfs f0, 0x270(r30)
/* 800EDA70 000EA9D0  90 1E 02 FC */	stw r0, 0x2fc(r30)
/* 800EDA74 000EA9D4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800EDA78 000EA9D8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800EDA7C 000EA9DC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800EDA80 000EA9E0  38 21 00 20 */	addi r1, r1, 0x20
/* 800EDA84 000EA9E4  7C 08 03 A6 */	mtlr r0
/* 800EDA88 000EA9E8  4E 80 00 20 */	blr 
.endfn __ct__8RopeItemFP12CreaturePropP5Shape

.fn isAtari__8RopeItemFv, global
/* 800EDA8C 000EA9EC  38 60 00 00 */	li r3, 0
/* 800EDA90 000EA9F0  4E 80 00 20 */	blr 
.endfn isAtari__8RopeItemFv

.fn getSize__8RopeItemFv, global
/* 800EDA94 000EA9F4  C0 22 9B 28 */	lfs f1, lbl_803E9D28@sda21(r2)
/* 800EDA98 000EA9F8  4E 80 00 20 */	blr 
.endfn getSize__8RopeItemFv

.fn init__8RopeItemFR8Vector3f, global
/* 800EDA9C 000EA9FC  7C 08 02 A6 */	mflr r0
/* 800EDAA0 000EAA00  90 01 00 04 */	stw r0, 4(r1)
/* 800EDAA4 000EAA04  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800EDAA8 000EAA08  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800EDAAC 000EAA0C  7C 7F 1B 78 */	mr r31, r3
/* 800EDAB0 000EAA10  C0 02 9B 2C */	lfs f0, lbl_803E9D2C@sda21(r2)
/* 800EDAB4 000EAA14  D0 03 00 7C */	stfs f0, 0x7c(r3)
/* 800EDAB8 000EAA18  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 800EDABC 000EAA1C  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 800EDAC0 000EAA20  4B F9 D1 45 */	bl init__8CreatureFR8Vector3f
/* 800EDAC4 000EAA24  38 7F 01 B8 */	addi r3, r31, 0x1b8
/* 800EDAC8 000EAA28  38 9F 02 D4 */	addi r4, r31, 0x2d4
/* 800EDACC 000EAA2C  38 A0 00 03 */	li r5, 3
/* 800EDAD0 000EAA30  4B FF 61 B1 */	bl init__12SearchBufferFP10SearchDatai
/* 800EDAD4 000EAA34  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800EDAD8 000EAA38  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800EDADC 000EAA3C  38 21 00 20 */	addi r1, r1, 0x20
/* 800EDAE0 000EAA40  7C 08 03 A6 */	mtlr r0
/* 800EDAE4 000EAA44  4E 80 00 20 */	blr 
.endfn init__8RopeItemFR8Vector3f

.fn autoInit__8RopeItemFv, global
/* 800EDAE8 000EAA48  7C 08 02 A6 */	mflr r0
/* 800EDAEC 000EAA4C  90 01 00 04 */	stw r0, 4(r1)
/* 800EDAF0 000EAA50  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 800EDAF4 000EAA54  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 800EDAF8 000EAA58  BF 61 00 2C */	stmw r27, 0x2c(r1)
/* 800EDAFC 000EAA5C  7C 7E 1B 78 */	mr r30, r3
/* 800EDB00 000EAA60  80 03 02 D0 */	lwz r0, 0x2d0(r3)
/* 800EDB04 000EAA64  83 ED 30 AC */	lwz r31, itemMgr@sda21(r13)
/* 800EDB08 000EAA68  2C 00 00 00 */	cmpwi r0, 0
/* 800EDB0C 000EAA6C  40 82 01 24 */	bne .L_800EDC30
/* 800EDB10 000EAA70  7F E3 FB 78 */	mr r3, r31
/* 800EDB14 000EAA74  C3 E2 9B 30 */	lfs f31, lbl_803E9D30@sda21(r2)
/* 800EDB18 000EAA78  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDB1C 000EAA7C  3B 60 00 00 */	li r27, 0
/* 800EDB20 000EAA80  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800EDB24 000EAA84  7D 88 03 A6 */	mtlr r12
/* 800EDB28 000EAA88  4E 80 00 21 */	blrl 
/* 800EDB2C 000EAA8C  7C 7C 1B 78 */	mr r28, r3
/* 800EDB30 000EAA90  48 00 00 8C */	b .L_800EDBBC
.L_800EDB34:
/* 800EDB34 000EAA94  2C 1C FF FF */	cmpwi r28, -1
/* 800EDB38 000EAA98  40 82 00 24 */	bne .L_800EDB5C
/* 800EDB3C 000EAA9C  7F E3 FB 78 */	mr r3, r31
/* 800EDB40 000EAAA0  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDB44 000EAAA4  38 80 00 00 */	li r4, 0
/* 800EDB48 000EAAA8  81 8C 00 08 */	lwz r12, 8(r12)
/* 800EDB4C 000EAAAC  7D 88 03 A6 */	mtlr r12
/* 800EDB50 000EAAB0  4E 80 00 21 */	blrl 
/* 800EDB54 000EAAB4  7C 7D 1B 78 */	mr r29, r3
/* 800EDB58 000EAAB8  48 00 00 20 */	b .L_800EDB78
.L_800EDB5C:
/* 800EDB5C 000EAABC  7F E3 FB 78 */	mr r3, r31
/* 800EDB60 000EAAC0  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDB64 000EAAC4  7F 84 E3 78 */	mr r4, r28
/* 800EDB68 000EAAC8  81 8C 00 08 */	lwz r12, 8(r12)
/* 800EDB6C 000EAACC  7D 88 03 A6 */	mtlr r12
/* 800EDB70 000EAAD0  4E 80 00 21 */	blrl 
/* 800EDB74 000EAAD4  7C 7D 1B 78 */	mr r29, r3
.L_800EDB78:
/* 800EDB78 000EAAD8  38 7D 00 00 */	addi r3, r29, 0
/* 800EDB7C 000EAADC  38 9E 00 00 */	addi r4, r30, 0
/* 800EDB80 000EAAE0  4B F9 F2 FD */	bl qdist2__FP8CreatureP8Creature
/* 800EDB84 000EAAE4  80 1D 00 6C */	lwz r0, 0x6c(r29)
/* 800EDB88 000EAAE8  2C 00 00 11 */	cmpwi r0, 0x11
/* 800EDB8C 000EAAEC  40 82 00 14 */	bne .L_800EDBA0
/* 800EDB90 000EAAF0  FC 01 F8 40 */	fcmpo cr0, f1, f31
/* 800EDB94 000EAAF4  40 80 00 0C */	bge .L_800EDBA0
/* 800EDB98 000EAAF8  7F BB EB 78 */	mr r27, r29
/* 800EDB9C 000EAAFC  FF E0 08 90 */	fmr f31, f1
.L_800EDBA0:
/* 800EDBA0 000EAB00  7F E3 FB 78 */	mr r3, r31
/* 800EDBA4 000EAB04  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDBA8 000EAB08  7F 84 E3 78 */	mr r4, r28
/* 800EDBAC 000EAB0C  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800EDBB0 000EAB10  7D 88 03 A6 */	mtlr r12
/* 800EDBB4 000EAB14  4E 80 00 21 */	blrl 
/* 800EDBB8 000EAB18  7C 7C 1B 78 */	mr r28, r3
.L_800EDBBC:
/* 800EDBBC 000EAB1C  7F E3 FB 78 */	mr r3, r31
/* 800EDBC0 000EAB20  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDBC4 000EAB24  7F 84 E3 78 */	mr r4, r28
/* 800EDBC8 000EAB28  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800EDBCC 000EAB2C  7D 88 03 A6 */	mtlr r12
/* 800EDBD0 000EAB30  4E 80 00 21 */	blrl 
/* 800EDBD4 000EAB34  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800EDBD8 000EAB38  41 82 00 0C */	beq .L_800EDBE4
/* 800EDBDC 000EAB3C  38 00 00 01 */	li r0, 1
/* 800EDBE0 000EAB40  48 00 00 30 */	b .L_800EDC10
.L_800EDBE4:
/* 800EDBE4 000EAB44  7F E3 FB 78 */	mr r3, r31
/* 800EDBE8 000EAB48  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDBEC 000EAB4C  7F 84 E3 78 */	mr r4, r28
/* 800EDBF0 000EAB50  81 8C 00 08 */	lwz r12, 8(r12)
/* 800EDBF4 000EAB54  7D 88 03 A6 */	mtlr r12
/* 800EDBF8 000EAB58  4E 80 00 21 */	blrl 
/* 800EDBFC 000EAB5C  28 03 00 00 */	cmplwi r3, 0
/* 800EDC00 000EAB60  40 82 00 0C */	bne .L_800EDC0C
/* 800EDC04 000EAB64  38 00 00 01 */	li r0, 1
/* 800EDC08 000EAB68  48 00 00 08 */	b .L_800EDC10
.L_800EDC0C:
/* 800EDC0C 000EAB6C  38 00 00 00 */	li r0, 0
.L_800EDC10:
/* 800EDC10 000EAB70  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 800EDC14 000EAB74  41 82 FF 20 */	beq .L_800EDB34
/* 800EDC18 000EAB78  28 1B 00 00 */	cmplwi r27, 0
/* 800EDC1C 000EAB7C  41 82 01 44 */	beq .L_800EDD60
/* 800EDC20 000EAB80  38 7E 00 00 */	addi r3, r30, 0
/* 800EDC24 000EAB84  38 9B 00 00 */	addi r4, r27, 0
/* 800EDC28 000EAB88  4B FA 6A D5 */	bl setRope__12RopeCreatureFP8Creature
/* 800EDC2C 000EAB8C  48 00 01 34 */	b .L_800EDD60
.L_800EDC30:
/* 800EDC30 000EAB90  7F E3 FB 78 */	mr r3, r31
/* 800EDC34 000EAB94  C3 E2 9B 30 */	lfs f31, lbl_803E9D30@sda21(r2)
/* 800EDC38 000EAB98  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDC3C 000EAB9C  3B 60 00 00 */	li r27, 0
/* 800EDC40 000EABA0  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800EDC44 000EABA4  7D 88 03 A6 */	mtlr r12
/* 800EDC48 000EABA8  4E 80 00 21 */	blrl 
/* 800EDC4C 000EABAC  7C 7C 1B 78 */	mr r28, r3
/* 800EDC50 000EABB0  48 00 00 A0 */	b .L_800EDCF0
.L_800EDC54:
/* 800EDC54 000EABB4  2C 1C FF FF */	cmpwi r28, -1
/* 800EDC58 000EABB8  40 82 00 24 */	bne .L_800EDC7C
/* 800EDC5C 000EABBC  7F E3 FB 78 */	mr r3, r31
/* 800EDC60 000EABC0  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDC64 000EABC4  38 80 00 00 */	li r4, 0
/* 800EDC68 000EABC8  81 8C 00 08 */	lwz r12, 8(r12)
/* 800EDC6C 000EABCC  7D 88 03 A6 */	mtlr r12
/* 800EDC70 000EABD0  4E 80 00 21 */	blrl 
/* 800EDC74 000EABD4  7C 7D 1B 78 */	mr r29, r3
/* 800EDC78 000EABD8  48 00 00 20 */	b .L_800EDC98
.L_800EDC7C:
/* 800EDC7C 000EABDC  7F E3 FB 78 */	mr r3, r31
/* 800EDC80 000EABE0  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDC84 000EABE4  7F 84 E3 78 */	mr r4, r28
/* 800EDC88 000EABE8  81 8C 00 08 */	lwz r12, 8(r12)
/* 800EDC8C 000EABEC  7D 88 03 A6 */	mtlr r12
/* 800EDC90 000EABF0  4E 80 00 21 */	blrl 
/* 800EDC94 000EABF4  7C 7D 1B 78 */	mr r29, r3
.L_800EDC98:
/* 800EDC98 000EABF8  38 7D 00 00 */	addi r3, r29, 0
/* 800EDC9C 000EABFC  38 9E 00 00 */	addi r4, r30, 0
/* 800EDCA0 000EAC00  4B F9 F1 DD */	bl qdist2__FP8CreatureP8Creature
/* 800EDCA4 000EAC04  80 1D 00 6C */	lwz r0, 0x6c(r29)
/* 800EDCA8 000EAC08  2C 00 00 12 */	cmpwi r0, 0x12
/* 800EDCAC 000EAC0C  40 82 00 28 */	bne .L_800EDCD4
/* 800EDCB0 000EAC10  80 7E 02 D0 */	lwz r3, 0x2d0(r30)
/* 800EDCB4 000EAC14  80 1D 02 D0 */	lwz r0, 0x2d0(r29)
/* 800EDCB8 000EAC18  38 63 FF FF */	addi r3, r3, -1
/* 800EDCBC 000EAC1C  7C 03 00 00 */	cmpw r3, r0
/* 800EDCC0 000EAC20  40 82 00 14 */	bne .L_800EDCD4
/* 800EDCC4 000EAC24  FC 01 F8 40 */	fcmpo cr0, f1, f31
/* 800EDCC8 000EAC28  40 80 00 0C */	bge .L_800EDCD4
/* 800EDCCC 000EAC2C  7F BB EB 78 */	mr r27, r29
/* 800EDCD0 000EAC30  FF E0 08 90 */	fmr f31, f1
.L_800EDCD4:
/* 800EDCD4 000EAC34  7F E3 FB 78 */	mr r3, r31
/* 800EDCD8 000EAC38  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDCDC 000EAC3C  7F 84 E3 78 */	mr r4, r28
/* 800EDCE0 000EAC40  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800EDCE4 000EAC44  7D 88 03 A6 */	mtlr r12
/* 800EDCE8 000EAC48  4E 80 00 21 */	blrl 
/* 800EDCEC 000EAC4C  7C 7C 1B 78 */	mr r28, r3
.L_800EDCF0:
/* 800EDCF0 000EAC50  7F E3 FB 78 */	mr r3, r31
/* 800EDCF4 000EAC54  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDCF8 000EAC58  7F 84 E3 78 */	mr r4, r28
/* 800EDCFC 000EAC5C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800EDD00 000EAC60  7D 88 03 A6 */	mtlr r12
/* 800EDD04 000EAC64  4E 80 00 21 */	blrl 
/* 800EDD08 000EAC68  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800EDD0C 000EAC6C  41 82 00 0C */	beq .L_800EDD18
/* 800EDD10 000EAC70  38 00 00 01 */	li r0, 1
/* 800EDD14 000EAC74  48 00 00 30 */	b .L_800EDD44
.L_800EDD18:
/* 800EDD18 000EAC78  7F E3 FB 78 */	mr r3, r31
/* 800EDD1C 000EAC7C  81 9F 00 00 */	lwz r12, 0(r31)
/* 800EDD20 000EAC80  7F 84 E3 78 */	mr r4, r28
/* 800EDD24 000EAC84  81 8C 00 08 */	lwz r12, 8(r12)
/* 800EDD28 000EAC88  7D 88 03 A6 */	mtlr r12
/* 800EDD2C 000EAC8C  4E 80 00 21 */	blrl 
/* 800EDD30 000EAC90  28 03 00 00 */	cmplwi r3, 0
/* 800EDD34 000EAC94  40 82 00 0C */	bne .L_800EDD40
/* 800EDD38 000EAC98  38 00 00 01 */	li r0, 1
/* 800EDD3C 000EAC9C  48 00 00 08 */	b .L_800EDD44
.L_800EDD40:
/* 800EDD40 000EACA0  38 00 00 00 */	li r0, 0
.L_800EDD44:
/* 800EDD44 000EACA4  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 800EDD48 000EACA8  41 82 FF 0C */	beq .L_800EDC54
/* 800EDD4C 000EACAC  28 1B 00 00 */	cmplwi r27, 0
/* 800EDD50 000EACB0  41 82 00 10 */	beq .L_800EDD60
/* 800EDD54 000EACB4  38 7E 00 00 */	addi r3, r30, 0
/* 800EDD58 000EACB8  38 9B 00 00 */	addi r4, r27, 0
/* 800EDD5C 000EACBC  4B FA 69 A1 */	bl setRope__12RopeCreatureFP8Creature
.L_800EDD60:
/* 800EDD60 000EACC0  BB 61 00 2C */	lmw r27, 0x2c(r1)
/* 800EDD64 000EACC4  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 800EDD68 000EACC8  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 800EDD6C 000EACCC  38 21 00 48 */	addi r1, r1, 0x48
/* 800EDD70 000EACD0  7C 08 03 A6 */	mtlr r0
/* 800EDD74 000EACD4  4E 80 00 20 */	blr 
.endfn autoInit__8RopeItemFv

.fn startAI__8RopeItemFi, global
/* 800EDD78 000EACD8  4E 80 00 20 */	blr 
.endfn startAI__8RopeItemFi

.fn doKill__8RopeItemFv, global
/* 800EDD7C 000EACDC  7C 08 02 A6 */	mflr r0
/* 800EDD80 000EACE0  7C 64 1B 78 */	mr r4, r3
/* 800EDD84 000EACE4  90 01 00 04 */	stw r0, 4(r1)
/* 800EDD88 000EACE8  94 21 FF F8 */	stwu r1, -8(r1)
/* 800EDD8C 000EACEC  80 6D 30 AC */	lwz r3, itemMgr@sda21(r13)
/* 800EDD90 000EACF0  81 83 00 00 */	lwz r12, 0(r3)
/* 800EDD94 000EACF4  81 8C 00 7C */	lwz r12, 0x7c(r12)
/* 800EDD98 000EACF8  7D 88 03 A6 */	mtlr r12
/* 800EDD9C 000EACFC  4E 80 00 21 */	blrl 
/* 800EDDA0 000EAD00  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800EDDA4 000EAD04  38 21 00 08 */	addi r1, r1, 8
/* 800EDDA8 000EAD08  7C 08 03 A6 */	mtlr r0
/* 800EDDAC 000EAD0C  4E 80 00 20 */	blr 
.endfn doKill__8RopeItemFv

.fn getiMass__8RopeItemFv, global
/* 800EDDB0 000EAD10  C0 22 9B 34 */	lfs f1, lbl_803E9D34@sda21(r2)
/* 800EDDB4 000EAD14  4E 80 00 20 */	blr 
.endfn getiMass__8RopeItemFv

.fn needShadow__8RopeItemFv, weak
/* 800EDDB8 000EAD18  38 60 00 00 */	li r3, 0
/* 800EDDBC 000EAD1C  4E 80 00 20 */	blr 
.endfn needShadow__8RopeItemFv

.fn isAlive__8RopeItemFv, weak
/* 800EDDC0 000EAD20  38 60 00 01 */	li r3, 1
/* 800EDDC4 000EAD24  4E 80 00 20 */	blr 
.endfn isAlive__8RopeItemFv

.fn isVisible__8RopeItemFv, weak
/* 800EDDC8 000EAD28  38 60 00 01 */	li r3, 1
/* 800EDDCC 000EAD2C  4E 80 00 20 */	blr 
.endfn isVisible__8RopeItemFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802BD438, local
	.asciz "ropeItem.cpp"
.endobj lbl_802BD438
.balign 4
.obj lbl_802BD448, local
	.asciz "ropeItem"
.endobj lbl_802BD448
.balign 4
.obj lbl_802BD454, local
	.asciz "RopeItem"
.endobj lbl_802BD454
.balign 4
.obj lbl_802BD460, local
	.asciz "EventTalker"
.endobj lbl_802BD460
.balign 4
.obj lbl_802BD46C, local
	.asciz "RefCountable"
.endobj lbl_802BD46C
.balign 4
.obj lbl_802BD47C, local
	.asciz "Creature"
.endobj lbl_802BD47C
.balign 4
.obj lbl_802BD488, local
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
.endobj lbl_802BD488
.balign 4
.obj lbl_802BD49C, local
	.asciz "RopeCreature"
.endobj lbl_802BD49C
.balign 4
.obj lbl_802BD4AC, local
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
.endobj lbl_802BD4AC
.balign 4
.obj lbl_802BD4C8, local
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__12RopeCreature
	.4byte 0
	.4byte 0
.endobj lbl_802BD4C8
.balign 4
.obj __vt__8RopeItem, global
	.4byte __RTTI__8RopeItem
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8RopeItemFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8RopeItemFi
	.4byte getiMass__8RopeItemFv
	.4byte getSize__8RopeItemFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__8CreatureFv
	.4byte isVisible__8RopeItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8RopeItemFv
	.4byte isAlive__8RopeItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8RopeItemFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__8CreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__8CreatureFR9CollEvent
	.4byte bounceCallback__8CreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
	.4byte offwallCallback__8CreatureFP13DynCollObject
	.4byte stickCallback__8CreatureFP8Creature
	.4byte offstickCallback__8CreatureFP8Creature
	.4byte stickToCallback__8CreatureFP8Creature
	.4byte dump__8CreatureFv
	.4byte startWaterEffect__8CreatureFv
	.4byte finishWaterEffect__8CreatureFv
	.4byte isRopable__8CreatureFv
	.4byte mayIstick__8CreatureFv
	.4byte getFormationPri__8CreatureFv
	.4byte update__12RopeCreatureFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12RopeCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__8CreatureFv
	.4byte doAnimation__8CreatureFv
	.4byte doKill__8RopeItemFv
	.4byte exitCourse__8CreatureFv
.endobj __vt__8RopeItem

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__11EventTalker, local
	.4byte lbl_802BD460
	.4byte 0
.endobj __RTTI__11EventTalker
.balign 4
.obj __RTTI__12RefCountable, local
	.4byte lbl_802BD46C
	.4byte 0
.endobj __RTTI__12RefCountable
.balign 4
.obj __RTTI__8Creature, local
	.4byte lbl_802BD47C
	.4byte lbl_802BD488
.endobj __RTTI__8Creature
.balign 4
.obj __RTTI__12RopeCreature, local
	.4byte lbl_802BD49C
	.4byte lbl_802BD4AC
.endobj __RTTI__12RopeCreature
.balign 4
.obj __RTTI__8RopeItem, local
	.4byte lbl_802BD454
	.4byte lbl_802BD4C8
.endobj __RTTI__8RopeItem

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9D28, local
	.float 5.0
.endobj lbl_803E9D28
.obj lbl_803E9D2C, local
	.float 1.0
.endobj lbl_803E9D2C
.obj lbl_803E9D30, local
	.float 12800.0
.endobj lbl_803E9D30
.obj lbl_803E9D34, local
	.float 10.0
.endobj lbl_803E9D34
