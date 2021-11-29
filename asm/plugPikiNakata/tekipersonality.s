.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__15TekiPersonalityFv
__ct__15TekiPersonalityFv:
/* 8014CA60 001499C0  7C 08 02 A6 */	mflr r0
/* 8014CA64 001499C4  3C 80 80 2D */	lis r4, __vt__15TekiPersonality@ha
/* 8014CA68 001499C8  90 01 00 04 */	stw r0, 4(r1)
/* 8014CA6C 001499CC  38 04 E6 9C */	addi r0, r4, __vt__15TekiPersonality@l
/* 8014CA70 001499D0  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 8014CA74 001499D4  BE E1 00 24 */	stmw r23, 0x24(r1)
/* 8014CA78 001499D8  3B E3 00 00 */	addi r31, r3, 0
/* 8014CA7C 001499DC  90 03 00 00 */	stw r0, 0(r3)
/* 8014CA80 001499E0  3C 60 80 2D */	lis r3, lbl_802CE5B8@ha
/* 8014CA84 001499E4  3B 03 E5 B8 */	addi r24, r3, lbl_802CE5B8@l
/* 8014CA88 001499E8  C0 02 A7 E8 */	lfs f0, lbl_803EA9E8@sda21(r2)
/* 8014CA8C 001499EC  38 7F 00 28 */	addi r3, r31, 0x28
/* 8014CA90 001499F0  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8014CA94 001499F4  D0 1F 00 08 */	stfs f0, 8(r31)
/* 8014CA98 001499F8  D0 1F 00 04 */	stfs f0, 4(r31)
/* 8014CA9C 001499FC  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 8014CAA0 00149A00  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 8014CAA4 00149A04  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8014CAA8 00149A08  4B EF 73 B5 */	bl __ct__4ID32Fv
/* 8014CAAC 00149A0C  38 00 00 05 */	li r0, 5
/* 8014CAB0 00149A10  1F 20 00 0C */	mulli r25, r0, 0xc
/* 8014CAB4 00149A14  38 79 00 08 */	addi r3, r25, 8
/* 8014CAB8 00149A18  4B EF A5 4D */	bl alloc__6SystemFUl
/* 8014CABC 00149A1C  3C 80 80 12 */	lis r4, __ct__18ParaParameterInfoIFv@ha
/* 8014CAC0 00149A20  38 84 54 54 */	addi r4, r4, __ct__18ParaParameterInfoIFv@l
/* 8014CAC4 00149A24  38 A0 00 00 */	li r5, 0
/* 8014CAC8 00149A28  38 C0 00 0C */	li r6, 0xc
/* 8014CACC 00149A2C  38 E0 00 05 */	li r7, 5
/* 8014CAD0 00149A30  48 0C 81 59 */	bl __construct_new_array
/* 8014CAD4 00149A34  38 00 00 00 */	li r0, 0
/* 8014CAD8 00149A38  1F 40 00 0C */	mulli r26, r0, 0xc
/* 8014CADC 00149A3C  7C E3 D2 14 */	add r7, r3, r26
/* 8014CAE0 00149A40  38 98 00 24 */	addi r4, r24, 0x24
/* 8014CAE4 00149A44  38 00 00 01 */	li r0, 1
/* 8014CAE8 00149A48  90 87 00 00 */	stw r4, 0(r7)
/* 8014CAEC 00149A4C  1F 60 00 0C */	mulli r27, r0, 0xc
/* 8014CAF0 00149A50  38 C0 FF 80 */	li r6, -128
/* 8014CAF4 00149A54  38 00 00 02 */	li r0, 2
/* 8014CAF8 00149A58  90 C7 00 04 */	stw r6, 4(r7)
/* 8014CAFC 00149A5C  38 A0 00 7F */	li r5, 0x7f
/* 8014CB00 00149A60  1F 80 00 0C */	mulli r28, r0, 0xc
/* 8014CB04 00149A64  90 A7 00 08 */	stw r5, 8(r7)
/* 8014CB08 00149A68  38 00 00 03 */	li r0, 3
/* 8014CB0C 00149A6C  1F A0 00 0C */	mulli r29, r0, 0xc
/* 8014CB10 00149A70  7C 83 DA 14 */	add r4, r3, r27
/* 8014CB14 00149A74  38 18 00 38 */	addi r0, r24, 0x38
/* 8014CB18 00149A78  90 04 00 00 */	stw r0, 0(r4)
/* 8014CB1C 00149A7C  38 00 00 04 */	li r0, 4
/* 8014CB20 00149A80  1F C0 00 0C */	mulli r30, r0, 0xc
/* 8014CB24 00149A84  90 C4 00 04 */	stw r6, 4(r4)
/* 8014CB28 00149A88  90 A4 00 08 */	stw r5, 8(r4)
/* 8014CB2C 00149A8C  7C E3 E2 14 */	add r7, r3, r28
/* 8014CB30 00149A90  38 18 00 4C */	addi r0, r24, 0x4c
/* 8014CB34 00149A94  90 07 00 00 */	stw r0, 0(r7)
/* 8014CB38 00149A98  7D 03 EA 14 */	add r8, r3, r29
/* 8014CB3C 00149A9C  38 98 00 5C */	addi r4, r24, 0x5c
/* 8014CB40 00149AA0  90 C7 00 04 */	stw r6, 4(r7)
/* 8014CB44 00149AA4  7D 23 F2 14 */	add r9, r3, r30
/* 8014CB48 00149AA8  38 18 00 6C */	addi r0, r24, 0x6c
/* 8014CB4C 00149AAC  90 A7 00 08 */	stw r5, 8(r7)
/* 8014CB50 00149AB0  3A E3 00 00 */	addi r23, r3, 0
/* 8014CB54 00149AB4  38 79 00 08 */	addi r3, r25, 8
/* 8014CB58 00149AB8  90 88 00 00 */	stw r4, 0(r8)
/* 8014CB5C 00149ABC  90 C8 00 04 */	stw r6, 4(r8)
/* 8014CB60 00149AC0  90 A8 00 08 */	stw r5, 8(r8)
/* 8014CB64 00149AC4  90 09 00 00 */	stw r0, 0(r9)
/* 8014CB68 00149AC8  90 C9 00 04 */	stw r6, 4(r9)
/* 8014CB6C 00149ACC  90 A9 00 08 */	stw r5, 8(r9)
/* 8014CB70 00149AD0  4B EF A4 95 */	bl alloc__6SystemFUl
/* 8014CB74 00149AD4  3C 80 80 12 */	lis r4, __ct__18ParaParameterInfoFFv@ha
/* 8014CB78 00149AD8  38 84 54 3C */	addi r4, r4, __ct__18ParaParameterInfoFFv@l
/* 8014CB7C 00149ADC  38 A0 00 00 */	li r5, 0
/* 8014CB80 00149AE0  38 C0 00 0C */	li r6, 0xc
/* 8014CB84 00149AE4  38 E0 00 05 */	li r7, 5
/* 8014CB88 00149AE8  48 0C 80 A1 */	bl __construct_new_array
/* 8014CB8C 00149AEC  7C E3 D2 14 */	add r7, r3, r26
/* 8014CB90 00149AF0  38 0D FA 28 */	addi r0, r13, lbl_803E4748@sda21
/* 8014CB94 00149AF4  90 07 00 00 */	stw r0, 0(r7)
/* 8014CB98 00149AF8  7D 03 DA 14 */	add r8, r3, r27
/* 8014CB9C 00149AFC  38 D8 00 78 */	addi r6, r24, 0x78
/* 8014CBA0 00149B00  C0 02 A7 EC */	lfs f0, lbl_803EA9EC@sda21(r2)
/* 8014CBA4 00149B04  7D 23 E2 14 */	add r9, r3, r28
/* 8014CBA8 00149B08  38 B8 00 84 */	addi r5, r24, 0x84
/* 8014CBAC 00149B0C  D0 07 00 04 */	stfs f0, 4(r7)
/* 8014CBB0 00149B10  7D 43 EA 14 */	add r10, r3, r29
/* 8014CBB4 00149B14  38 98 00 94 */	addi r4, r24, 0x94
/* 8014CBB8 00149B18  C0 02 A7 F0 */	lfs f0, lbl_803EA9F0@sda21(r2)
/* 8014CBBC 00149B1C  7D 63 F2 14 */	add r11, r3, r30
/* 8014CBC0 00149B20  3B 23 00 00 */	addi r25, r3, 0
/* 8014CBC4 00149B24  D0 07 00 08 */	stfs f0, 8(r7)
/* 8014CBC8 00149B28  38 18 00 B4 */	addi r0, r24, 0xb4
/* 8014CBCC 00149B2C  38 60 00 0C */	li r3, 0xc
/* 8014CBD0 00149B30  90 C8 00 00 */	stw r6, 0(r8)
/* 8014CBD4 00149B34  C0 22 A7 E8 */	lfs f1, lbl_803EA9E8@sda21(r2)
/* 8014CBD8 00149B38  D0 28 00 04 */	stfs f1, 4(r8)
/* 8014CBDC 00149B3C  C0 02 A7 F4 */	lfs f0, lbl_803EA9F4@sda21(r2)
/* 8014CBE0 00149B40  D0 08 00 08 */	stfs f0, 8(r8)
/* 8014CBE4 00149B44  90 A9 00 00 */	stw r5, 0(r9)
/* 8014CBE8 00149B48  D0 29 00 04 */	stfs f1, 4(r9)
/* 8014CBEC 00149B4C  C0 02 A7 F8 */	lfs f0, lbl_803EA9F8@sda21(r2)
/* 8014CBF0 00149B50  D0 09 00 08 */	stfs f0, 8(r9)
/* 8014CBF4 00149B54  90 8A 00 00 */	stw r4, 0(r10)
/* 8014CBF8 00149B58  D0 2A 00 04 */	stfs f1, 4(r10)
/* 8014CBFC 00149B5C  C0 02 A7 FC */	lfs f0, lbl_803EA9FC@sda21(r2)
/* 8014CC00 00149B60  D0 0A 00 08 */	stfs f0, 8(r10)
/* 8014CC04 00149B64  90 0B 00 00 */	stw r0, 0(r11)
/* 8014CC08 00149B68  D0 2B 00 04 */	stfs f1, 4(r11)
/* 8014CC0C 00149B6C  D0 0B 00 08 */	stfs f0, 8(r11)
/* 8014CC10 00149B70  4B EF A3 F5 */	bl alloc__6SystemFUl
/* 8014CC14 00149B74  3B 03 00 00 */	addi r24, r3, 0
/* 8014CC18 00149B78  7F 03 C3 79 */	or. r3, r24, r24
/* 8014CC1C 00149B7C  41 82 00 18 */	beq lbl_8014CC34
/* 8014CC20 00149B80  38 B7 00 00 */	addi r5, r23, 0
/* 8014CC24 00149B84  38 F9 00 00 */	addi r7, r25, 0
/* 8014CC28 00149B88  38 80 00 05 */	li r4, 5
/* 8014CC2C 00149B8C  38 C0 00 05 */	li r6, 5
/* 8014CC30 00149B90  4B FD 4C 25 */	bl __ct__19ParaMultiParametersFiP18ParaParameterInfoIiP18ParaParameterInfoF
lbl_8014CC34:
/* 8014CC34 00149B94  93 1F 00 34 */	stw r24, 0x34(r31)
/* 8014CC38 00149B98  7F E3 FB 78 */	mr r3, r31
/* 8014CC3C 00149B9C  48 00 00 1D */	bl reset__15TekiPersonalityFv
/* 8014CC40 00149BA0  7F E3 FB 78 */	mr r3, r31
/* 8014CC44 00149BA4  BA E1 00 24 */	lmw r23, 0x24(r1)
/* 8014CC48 00149BA8  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 8014CC4C 00149BAC  38 21 00 48 */	addi r1, r1, 0x48
/* 8014CC50 00149BB0  7C 08 03 A6 */	mtlr r0
/* 8014CC54 00149BB4  4E 80 00 20 */	blr 

.global reset__15TekiPersonalityFv
reset__15TekiPersonalityFv:
/* 8014CC58 00149BB8  7C 08 02 A6 */	mflr r0
/* 8014CC5C 00149BBC  3C 80 6E 6F */	lis r4, 0x6E6F6E65@ha
/* 8014CC60 00149BC0  90 01 00 04 */	stw r0, 4(r1)
/* 8014CC64 00149BC4  38 84 6E 65 */	addi r4, r4, 0x6E6F6E65@l
/* 8014CC68 00149BC8  94 21 FF 98 */	stwu r1, -0x68(r1)
/* 8014CC6C 00149BCC  93 E1 00 64 */	stw r31, 0x64(r1)
/* 8014CC70 00149BD0  3B E3 00 00 */	addi r31, r3, 0
/* 8014CC74 00149BD4  93 C1 00 60 */	stw r30, 0x60(r1)
/* 8014CC78 00149BD8  3B C0 00 00 */	li r30, 0
/* 8014CC7C 00149BDC  C0 0D FA 30 */	lfs f0, lbl_803E4750@sda21(r13)
/* 8014CC80 00149BE0  D0 03 00 04 */	stfs f0, 4(r3)
/* 8014CC84 00149BE4  38 7F 00 28 */	addi r3, r31, 0x28
/* 8014CC88 00149BE8  C0 0D FA 34 */	lfs f0, lbl_803E4754@sda21(r13)
/* 8014CC8C 00149BEC  D0 1F 00 08 */	stfs f0, 8(r31)
/* 8014CC90 00149BF0  C0 0D FA 38 */	lfs f0, lbl_803E4758@sda21(r13)
/* 8014CC94 00149BF4  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8014CC98 00149BF8  C0 02 A7 E8 */	lfs f0, lbl_803EA9E8@sda21(r2)
/* 8014CC9C 00149BFC  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8014CCA0 00149C00  C0 0D FA 3C */	lfs f0, lbl_803E475C@sda21(r13)
/* 8014CCA4 00149C04  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8014CCA8 00149C08  C0 0D FA 40 */	lfs f0, lbl_803E4760@sda21(r13)
/* 8014CCAC 00149C0C  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 8014CCB0 00149C10  C0 0D FA 44 */	lfs f0, lbl_803E4764@sda21(r13)
/* 8014CCB4 00149C14  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 8014CCB8 00149C18  93 DF 00 20 */	stw r30, 0x20(r31)
/* 8014CCBC 00149C1C  93 DF 00 24 */	stw r30, 0x24(r31)
/* 8014CCC0 00149C20  4B EF 72 05 */	bl setID__4ID32FUl
/* 8014CCC4 00149C24  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CCC8 00149C28  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CCCC 00149C2C  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CCD0 00149C30  93 C3 00 00 */	stw r30, 0(r3)
/* 8014CCD4 00149C34  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CCD8 00149C38  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CCDC 00149C3C  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CCE0 00149C40  93 C3 00 04 */	stw r30, 4(r3)
/* 8014CCE4 00149C44  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CCE8 00149C48  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CCEC 00149C4C  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CCF0 00149C50  93 C3 00 08 */	stw r30, 8(r3)
/* 8014CCF4 00149C54  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CCF8 00149C58  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CCFC 00149C5C  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CD00 00149C60  93 C3 00 0C */	stw r30, 0xc(r3)
/* 8014CD04 00149C64  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CD08 00149C68  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CD0C 00149C6C  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CD10 00149C70  93 C3 00 10 */	stw r30, 0x10(r3)
/* 8014CD14 00149C74  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CD18 00149C78  C0 02 A7 FC */	lfs f0, lbl_803EA9FC@sda21(r2)
/* 8014CD1C 00149C7C  80 63 00 04 */	lwz r3, 4(r3)
/* 8014CD20 00149C80  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CD24 00149C84  D0 03 00 00 */	stfs f0, 0(r3)
/* 8014CD28 00149C88  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CD2C 00149C8C  80 63 00 04 */	lwz r3, 4(r3)
/* 8014CD30 00149C90  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CD34 00149C94  D0 03 00 04 */	stfs f0, 4(r3)
/* 8014CD38 00149C98  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CD3C 00149C9C  C0 02 A7 E8 */	lfs f0, lbl_803EA9E8@sda21(r2)
/* 8014CD40 00149CA0  80 63 00 04 */	lwz r3, 4(r3)
/* 8014CD44 00149CA4  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CD48 00149CA8  D0 03 00 08 */	stfs f0, 8(r3)
/* 8014CD4C 00149CAC  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CD50 00149CB0  80 63 00 04 */	lwz r3, 4(r3)
/* 8014CD54 00149CB4  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CD58 00149CB8  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 8014CD5C 00149CBC  80 7F 00 34 */	lwz r3, 0x34(r31)
/* 8014CD60 00149CC0  80 63 00 04 */	lwz r3, 4(r3)
/* 8014CD64 00149CC4  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CD68 00149CC8  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 8014CD6C 00149CCC  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 8014CD70 00149CD0  83 E1 00 64 */	lwz r31, 0x64(r1)
/* 8014CD74 00149CD4  83 C1 00 60 */	lwz r30, 0x60(r1)
/* 8014CD78 00149CD8  38 21 00 68 */	addi r1, r1, 0x68
/* 8014CD7C 00149CDC  7C 08 03 A6 */	mtlr r0
/* 8014CD80 00149CE0  4E 80 00 20 */	blr 

.global input__15TekiPersonalityFR15TekiPersonality
input__15TekiPersonalityFR15TekiPersonality:
/* 8014CD84 00149CE4  7C 08 02 A6 */	mflr r0
/* 8014CD88 00149CE8  38 A0 00 05 */	li r5, 5
/* 8014CD8C 00149CEC  90 01 00 04 */	stw r0, 4(r1)
/* 8014CD90 00149CF0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8014CD94 00149CF4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8014CD98 00149CF8  7C 9F 23 78 */	mr r31, r4
/* 8014CD9C 00149CFC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8014CDA0 00149D00  3B C3 00 00 */	addi r30, r3, 0
/* 8014CDA4 00149D04  38 7E 00 2C */	addi r3, r30, 0x2c
/* 8014CDA8 00149D08  C0 04 00 04 */	lfs f0, 4(r4)
/* 8014CDAC 00149D0C  38 9F 00 2C */	addi r4, r31, 0x2c
/* 8014CDB0 00149D10  D0 1E 00 04 */	stfs f0, 4(r30)
/* 8014CDB4 00149D14  C0 1F 00 08 */	lfs f0, 8(r31)
/* 8014CDB8 00149D18  D0 1E 00 08 */	stfs f0, 8(r30)
/* 8014CDBC 00149D1C  C0 1F 00 0C */	lfs f0, 0xc(r31)
/* 8014CDC0 00149D20  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8014CDC4 00149D24  C0 1F 00 1C */	lfs f0, 0x1c(r31)
/* 8014CDC8 00149D28  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8014CDCC 00149D2C  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 8014CDD0 00149D30  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 8014CDD4 00149D34  C0 1F 00 14 */	lfs f0, 0x14(r31)
/* 8014CDD8 00149D38  D0 1E 00 14 */	stfs f0, 0x14(r30)
/* 8014CDDC 00149D3C  C0 1F 00 18 */	lfs f0, 0x18(r31)
/* 8014CDE0 00149D40  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 8014CDE4 00149D44  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 8014CDE8 00149D48  90 1E 00 20 */	stw r0, 0x20(r30)
/* 8014CDEC 00149D4C  80 1F 00 24 */	lwz r0, 0x24(r31)
/* 8014CDF0 00149D50  90 1E 00 24 */	stw r0, 0x24(r30)
/* 8014CDF4 00149D54  80 1F 00 28 */	lwz r0, 0x28(r31)
/* 8014CDF8 00149D58  90 1E 00 28 */	stw r0, 0x28(r30)
/* 8014CDFC 00149D5C  48 0C 7B C9 */	bl __copy
/* 8014CE00 00149D60  80 7E 00 34 */	lwz r3, 0x34(r30)
/* 8014CE04 00149D64  80 9F 00 34 */	lwz r4, 0x34(r31)
/* 8014CE08 00149D68  4B FD 4C 15 */	bl input__19ParaMultiParametersFR19ParaMultiParameters
/* 8014CE0C 00149D6C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8014CE10 00149D70  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8014CE14 00149D74  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8014CE18 00149D78  38 21 00 18 */	addi r1, r1, 0x18
/* 8014CE1C 00149D7C  7C 08 03 A6 */	mtlr r0
/* 8014CE20 00149D80  4E 80 00 20 */	blr 

.global read__15TekiPersonalityFR18RandomAccessStreami
read__15TekiPersonalityFR18RandomAccessStreami:
/* 8014CE24 00149D84  7C 08 02 A6 */	mflr r0
/* 8014CE28 00149D88  2C 05 00 07 */	cmpwi r5, 7
/* 8014CE2C 00149D8C  90 01 00 04 */	stw r0, 4(r1)
/* 8014CE30 00149D90  94 21 FF 98 */	stwu r1, -0x68(r1)
/* 8014CE34 00149D94  93 E1 00 64 */	stw r31, 0x64(r1)
/* 8014CE38 00149D98  93 C1 00 60 */	stw r30, 0x60(r1)
/* 8014CE3C 00149D9C  7C 9E 23 78 */	mr r30, r4
/* 8014CE40 00149DA0  93 A1 00 5C */	stw r29, 0x5c(r1)
/* 8014CE44 00149DA4  93 81 00 58 */	stw r28, 0x58(r1)
/* 8014CE48 00149DA8  3B 83 00 00 */	addi r28, r3, 0
/* 8014CE4C 00149DAC  83 E3 00 34 */	lwz r31, 0x34(r3)
/* 8014CE50 00149DB0  41 81 00 60 */	bgt lbl_8014CEB0
/* 8014CE54 00149DB4  7F C3 F3 78 */	mr r3, r30
/* 8014CE58 00149DB8  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014CE5C 00149DBC  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014CE60 00149DC0  7D 88 03 A6 */	mtlr r12
/* 8014CE64 00149DC4  4E 80 00 21 */	blrl 
/* 8014CE68 00149DC8  90 7C 00 20 */	stw r3, 0x20(r28)
/* 8014CE6C 00149DCC  7F C3 F3 78 */	mr r3, r30
/* 8014CE70 00149DD0  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014CE74 00149DD4  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014CE78 00149DD8  7D 88 03 A6 */	mtlr r12
/* 8014CE7C 00149DDC  4E 80 00 21 */	blrl 
/* 8014CE80 00149DE0  90 7C 00 24 */	stw r3, 0x24(r28)
/* 8014CE84 00149DE4  3C 80 6E 6F */	lis r4, 0x6E6F6E65@ha
/* 8014CE88 00149DE8  38 7C 00 28 */	addi r3, r28, 0x28
/* 8014CE8C 00149DEC  38 84 6E 65 */	addi r4, r4, 0x6E6F6E65@l
/* 8014CE90 00149DF0  4B EF 70 35 */	bl setID__4ID32FUl
/* 8014CE94 00149DF4  7F E3 FB 78 */	mr r3, r31
/* 8014CE98 00149DF8  81 9F 00 08 */	lwz r12, 8(r31)
/* 8014CE9C 00149DFC  7F C4 F3 78 */	mr r4, r30
/* 8014CEA0 00149E00  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014CEA4 00149E04  7D 88 03 A6 */	mtlr r12
/* 8014CEA8 00149E08  4E 80 00 21 */	blrl 
/* 8014CEAC 00149E0C  48 00 02 48 */	b lbl_8014D0F4
lbl_8014CEB0:
/* 8014CEB0 00149E10  2C 05 00 08 */	cmpwi r5, 8
/* 8014CEB4 00149E14  41 81 00 EC */	bgt lbl_8014CFA0
/* 8014CEB8 00149E18  7F C3 F3 78 */	mr r3, r30
/* 8014CEBC 00149E1C  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014CEC0 00149E20  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014CEC4 00149E24  7D 88 03 A6 */	mtlr r12
/* 8014CEC8 00149E28  4E 80 00 21 */	blrl 
/* 8014CECC 00149E2C  90 7C 00 20 */	stw r3, 0x20(r28)
/* 8014CED0 00149E30  7F C3 F3 78 */	mr r3, r30
/* 8014CED4 00149E34  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014CED8 00149E38  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014CEDC 00149E3C  7D 88 03 A6 */	mtlr r12
/* 8014CEE0 00149E40  4E 80 00 21 */	blrl 
/* 8014CEE4 00149E44  90 7C 00 24 */	stw r3, 0x24(r28)
/* 8014CEE8 00149E48  38 9E 00 00 */	addi r4, r30, 0
/* 8014CEEC 00149E4C  38 7C 00 28 */	addi r3, r28, 0x28
/* 8014CEF0 00149E50  4B EF 71 AD */	bl read__4ID32FR18RandomAccessStream
/* 8014CEF4 00149E54  3B 80 00 00 */	li r28, 0
/* 8014CEF8 00149E58  3B A0 00 00 */	li r29, 0
lbl_8014CEFC:
/* 8014CEFC 00149E5C  7F C3 F3 78 */	mr r3, r30
/* 8014CF00 00149E60  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014CF04 00149E64  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014CF08 00149E68  7D 88 03 A6 */	mtlr r12
/* 8014CF0C 00149E6C  4E 80 00 21 */	blrl 
/* 8014CF10 00149E70  80 9F 00 00 */	lwz r4, 0(r31)
/* 8014CF14 00149E74  3B 9C 00 01 */	addi r28, r28, 1
/* 8014CF18 00149E78  2C 1C 00 02 */	cmpwi r28, 2
/* 8014CF1C 00149E7C  80 84 00 00 */	lwz r4, 0(r4)
/* 8014CF20 00149E80  7C 64 E9 2E */	stwx r3, r4, r29
/* 8014CF24 00149E84  3B BD 00 04 */	addi r29, r29, 4
/* 8014CF28 00149E88  40 81 FF D4 */	ble lbl_8014CEFC
/* 8014CF2C 00149E8C  80 7F 00 00 */	lwz r3, 0(r31)
/* 8014CF30 00149E90  3B 80 00 00 */	li r28, 0
/* 8014CF34 00149E94  7F 9D E3 78 */	mr r29, r28
/* 8014CF38 00149E98  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CF3C 00149E9C  80 03 00 08 */	lwz r0, 8(r3)
/* 8014CF40 00149EA0  90 03 00 10 */	stw r0, 0x10(r3)
/* 8014CF44 00149EA4  80 7F 00 00 */	lwz r3, 0(r31)
/* 8014CF48 00149EA8  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CF4C 00149EAC  93 83 00 08 */	stw r28, 8(r3)
/* 8014CF50 00149EB0  80 7F 00 00 */	lwz r3, 0(r31)
/* 8014CF54 00149EB4  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CF58 00149EB8  93 83 00 0C */	stw r28, 0xc(r3)
lbl_8014CF5C:
/* 8014CF5C 00149EBC  7F C3 F3 78 */	mr r3, r30
/* 8014CF60 00149EC0  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014CF64 00149EC4  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8014CF68 00149EC8  7D 88 03 A6 */	mtlr r12
/* 8014CF6C 00149ECC  4E 80 00 21 */	blrl 
/* 8014CF70 00149ED0  80 7F 00 04 */	lwz r3, 4(r31)
/* 8014CF74 00149ED4  3B 9C 00 01 */	addi r28, r28, 1
/* 8014CF78 00149ED8  2C 1C 00 03 */	cmpwi r28, 3
/* 8014CF7C 00149EDC  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CF80 00149EE0  7C 23 ED 2E */	stfsx f1, r3, r29
/* 8014CF84 00149EE4  3B BD 00 04 */	addi r29, r29, 4
/* 8014CF88 00149EE8  40 81 FF D4 */	ble lbl_8014CF5C
/* 8014CF8C 00149EEC  80 7F 00 04 */	lwz r3, 4(r31)
/* 8014CF90 00149EF0  C0 02 A7 E8 */	lfs f0, lbl_803EA9E8@sda21(r2)
/* 8014CF94 00149EF4  80 63 00 00 */	lwz r3, 0(r3)
/* 8014CF98 00149EF8  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 8014CF9C 00149EFC  48 00 01 58 */	b lbl_8014D0F4
lbl_8014CFA0:
/* 8014CFA0 00149F00  2C 05 00 09 */	cmpwi r5, 9
/* 8014CFA4 00149F04  41 81 00 F4 */	bgt lbl_8014D098
/* 8014CFA8 00149F08  7F C3 F3 78 */	mr r3, r30
/* 8014CFAC 00149F0C  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014CFB0 00149F10  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8014CFB4 00149F14  7D 88 03 A6 */	mtlr r12
/* 8014CFB8 00149F18  4E 80 00 21 */	blrl 
/* 8014CFBC 00149F1C  7C 60 07 74 */	extsb r0, r3
/* 8014CFC0 00149F20  90 1C 00 20 */	stw r0, 0x20(r28)
/* 8014CFC4 00149F24  7F C3 F3 78 */	mr r3, r30
/* 8014CFC8 00149F28  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014CFCC 00149F2C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8014CFD0 00149F30  7D 88 03 A6 */	mtlr r12
/* 8014CFD4 00149F34  4E 80 00 21 */	blrl 
/* 8014CFD8 00149F38  7C 60 07 74 */	extsb r0, r3
/* 8014CFDC 00149F3C  90 1C 00 24 */	stw r0, 0x24(r28)
/* 8014CFE0 00149F40  38 9E 00 00 */	addi r4, r30, 0
/* 8014CFE4 00149F44  38 7C 00 28 */	addi r3, r28, 0x28
/* 8014CFE8 00149F48  4B EF 70 B5 */	bl read__4ID32FR18RandomAccessStream
/* 8014CFEC 00149F4C  3B 80 00 00 */	li r28, 0
/* 8014CFF0 00149F50  3B A0 00 00 */	li r29, 0
lbl_8014CFF4:
/* 8014CFF4 00149F54  7F C3 F3 78 */	mr r3, r30
/* 8014CFF8 00149F58  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014CFFC 00149F5C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014D000 00149F60  7D 88 03 A6 */	mtlr r12
/* 8014D004 00149F64  4E 80 00 21 */	blrl 
/* 8014D008 00149F68  80 9F 00 00 */	lwz r4, 0(r31)
/* 8014D00C 00149F6C  3B 9C 00 01 */	addi r28, r28, 1
/* 8014D010 00149F70  2C 1C 00 02 */	cmpwi r28, 2
/* 8014D014 00149F74  80 84 00 00 */	lwz r4, 0(r4)
/* 8014D018 00149F78  7C 64 E9 2E */	stwx r3, r4, r29
/* 8014D01C 00149F7C  3B BD 00 04 */	addi r29, r29, 4
/* 8014D020 00149F80  40 81 FF D4 */	ble lbl_8014CFF4
/* 8014D024 00149F84  80 7F 00 00 */	lwz r3, 0(r31)
/* 8014D028 00149F88  3B 80 00 00 */	li r28, 0
/* 8014D02C 00149F8C  7F 9D E3 78 */	mr r29, r28
/* 8014D030 00149F90  80 63 00 00 */	lwz r3, 0(r3)
/* 8014D034 00149F94  80 03 00 08 */	lwz r0, 8(r3)
/* 8014D038 00149F98  90 03 00 10 */	stw r0, 0x10(r3)
/* 8014D03C 00149F9C  80 7F 00 00 */	lwz r3, 0(r31)
/* 8014D040 00149FA0  80 63 00 00 */	lwz r3, 0(r3)
/* 8014D044 00149FA4  93 83 00 08 */	stw r28, 8(r3)
/* 8014D048 00149FA8  80 7F 00 00 */	lwz r3, 0(r31)
/* 8014D04C 00149FAC  80 63 00 00 */	lwz r3, 0(r3)
/* 8014D050 00149FB0  93 83 00 0C */	stw r28, 0xc(r3)
lbl_8014D054:
/* 8014D054 00149FB4  7F C3 F3 78 */	mr r3, r30
/* 8014D058 00149FB8  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014D05C 00149FBC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8014D060 00149FC0  7D 88 03 A6 */	mtlr r12
/* 8014D064 00149FC4  4E 80 00 21 */	blrl 
/* 8014D068 00149FC8  80 7F 00 04 */	lwz r3, 4(r31)
/* 8014D06C 00149FCC  3B 9C 00 01 */	addi r28, r28, 1
/* 8014D070 00149FD0  2C 1C 00 03 */	cmpwi r28, 3
/* 8014D074 00149FD4  80 63 00 00 */	lwz r3, 0(r3)
/* 8014D078 00149FD8  7C 23 ED 2E */	stfsx f1, r3, r29
/* 8014D07C 00149FDC  3B BD 00 04 */	addi r29, r29, 4
/* 8014D080 00149FE0  40 81 FF D4 */	ble lbl_8014D054
/* 8014D084 00149FE4  80 7F 00 04 */	lwz r3, 4(r31)
/* 8014D088 00149FE8  C0 02 A7 E8 */	lfs f0, lbl_803EA9E8@sda21(r2)
/* 8014D08C 00149FEC  80 63 00 00 */	lwz r3, 0(r3)
/* 8014D090 00149FF0  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 8014D094 00149FF4  48 00 00 60 */	b lbl_8014D0F4
lbl_8014D098:
/* 8014D098 00149FF8  7F C3 F3 78 */	mr r3, r30
/* 8014D09C 00149FFC  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014D0A0 0014A000  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8014D0A4 0014A004  7D 88 03 A6 */	mtlr r12
/* 8014D0A8 0014A008  4E 80 00 21 */	blrl 
/* 8014D0AC 0014A00C  7C 60 07 74 */	extsb r0, r3
/* 8014D0B0 0014A010  90 1C 00 20 */	stw r0, 0x20(r28)
/* 8014D0B4 0014A014  7F C3 F3 78 */	mr r3, r30
/* 8014D0B8 0014A018  81 9E 00 04 */	lwz r12, 4(r30)
/* 8014D0BC 0014A01C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8014D0C0 0014A020  7D 88 03 A6 */	mtlr r12
/* 8014D0C4 0014A024  4E 80 00 21 */	blrl 
/* 8014D0C8 0014A028  7C 60 07 74 */	extsb r0, r3
/* 8014D0CC 0014A02C  90 1C 00 24 */	stw r0, 0x24(r28)
/* 8014D0D0 0014A030  38 9E 00 00 */	addi r4, r30, 0
/* 8014D0D4 0014A034  38 7C 00 28 */	addi r3, r28, 0x28
/* 8014D0D8 0014A038  4B EF 6F C5 */	bl read__4ID32FR18RandomAccessStream
/* 8014D0DC 0014A03C  7F E3 FB 78 */	mr r3, r31
/* 8014D0E0 0014A040  81 9F 00 08 */	lwz r12, 8(r31)
/* 8014D0E4 0014A044  7F C4 F3 78 */	mr r4, r30
/* 8014D0E8 0014A048  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014D0EC 0014A04C  7D 88 03 A6 */	mtlr r12
/* 8014D0F0 0014A050  4E 80 00 21 */	blrl 
lbl_8014D0F4:
/* 8014D0F4 0014A054  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 8014D0F8 0014A058  83 E1 00 64 */	lwz r31, 0x64(r1)
/* 8014D0FC 0014A05C  83 C1 00 60 */	lwz r30, 0x60(r1)
/* 8014D100 0014A060  83 A1 00 5C */	lwz r29, 0x5c(r1)
/* 8014D104 0014A064  83 81 00 58 */	lwz r28, 0x58(r1)
/* 8014D108 0014A068  38 21 00 68 */	addi r1, r1, 0x68
/* 8014D10C 0014A06C  7C 08 03 A6 */	mtlr r0
/* 8014D110 0014A070  4E 80 00 20 */	blr 

.global write__15TekiPersonalityFR18RandomAccessStream
write__15TekiPersonalityFR18RandomAccessStream:
/* 8014D114 0014A074  7C 08 02 A6 */	mflr r0
/* 8014D118 0014A078  90 01 00 04 */	stw r0, 4(r1)
/* 8014D11C 0014A07C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8014D120 0014A080  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8014D124 0014A084  3B E4 00 00 */	addi r31, r4, 0
/* 8014D128 0014A088  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8014D12C 0014A08C  3B C3 00 00 */	addi r30, r3, 0
/* 8014D130 0014A090  38 7F 00 00 */	addi r3, r31, 0
/* 8014D134 0014A094  81 9F 00 04 */	lwz r12, 4(r31)
/* 8014D138 0014A098  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 8014D13C 0014A09C  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 8014D140 0014A0A0  7C 04 07 74 */	extsb r4, r0
/* 8014D144 0014A0A4  7D 88 03 A6 */	mtlr r12
/* 8014D148 0014A0A8  4E 80 00 21 */	blrl 
/* 8014D14C 0014A0AC  7F E3 FB 78 */	mr r3, r31
/* 8014D150 0014A0B0  80 1E 00 24 */	lwz r0, 0x24(r30)
/* 8014D154 0014A0B4  81 9F 00 04 */	lwz r12, 4(r31)
/* 8014D158 0014A0B8  7C 04 07 74 */	extsb r4, r0
/* 8014D15C 0014A0BC  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 8014D160 0014A0C0  7D 88 03 A6 */	mtlr r12
/* 8014D164 0014A0C4  4E 80 00 21 */	blrl 
/* 8014D168 0014A0C8  38 7E 00 28 */	addi r3, r30, 0x28
/* 8014D16C 0014A0CC  38 9F 00 00 */	addi r4, r31, 0
/* 8014D170 0014A0D0  4B EF 6E 99 */	bl write__4ID32FR18RandomAccessStream
/* 8014D174 0014A0D4  80 7E 00 34 */	lwz r3, 0x34(r30)
/* 8014D178 0014A0D8  7F E4 FB 78 */	mr r4, r31
/* 8014D17C 0014A0DC  81 83 00 08 */	lwz r12, 8(r3)
/* 8014D180 0014A0E0  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8014D184 0014A0E4  7D 88 03 A6 */	mtlr r12
/* 8014D188 0014A0E8  4E 80 00 21 */	blrl 
/* 8014D18C 0014A0EC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8014D190 0014A0F0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8014D194 0014A0F4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8014D198 0014A0F8  38 21 00 18 */	addi r1, r1, 0x18
/* 8014D19C 0014A0FC  7C 08 03 A6 */	mtlr r0
/* 8014D1A0 0014A100  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802CE5B8:
	.asciz "tekipersonality.cpp"
.balign 4
lbl_802CE5CC:
	.asciz "tekipersonality"
.balign 4
lbl_802CE5DC:
	.asciz "PELLET_MIN_COUNT"
.balign 4
lbl_802CE5F0:
	.asciz "PELLET_MAX_COUNT"
.balign 4
lbl_802CE604:
	.asciz "WATER_MIN_COUNT"
.balign 4
lbl_802CE614:
	.asciz "WATER_MAX_COUNT"
.balign 4
lbl_802CE624:
	.asciz "PARAMETER_0"
.balign 4
lbl_802CE630:
	.asciz "STRENGTH"
.balign 4
lbl_802CE63C:
	.asciz "TERRITORY_RANGE"
.balign 4
lbl_802CE64C:
	.asciz "PELLET_APPEARANCE_PROBABILITY"
.balign 4
lbl_802CE66C:
	.asciz "WATER_APPEARANCE_PROBABILITY"
.balign 4
lbl_802CE68C:
	.asciz "TekiPersonality"
.balign 4
.global __vt__15TekiPersonality
__vt__15TekiPersonality:
	.4byte __RTTI__15TekiPersonality
	.4byte 0
	.4byte read__15TekiPersonalityFR18RandomAccessStreami
	.4byte write__15TekiPersonalityFR18RandomAccessStream

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E4748:
	.asciz "SIZE"
.balign 4
lbl_803E4750:
	.float 0.0
lbl_803E4754:
	.float 0.0
lbl_803E4758:
	.float 0.0
lbl_803E475C:
	.float 0.0
lbl_803E4760:
	.float 0.0
lbl_803E4764:
	.float 0.0
__RTTI__15TekiPersonality:
	.4byte lbl_802CE68C
	.4byte 0

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EA9E8:
	.float 0.0
lbl_803EA9EC:
	.float 0.1
lbl_803EA9F0:
	.float 10.0
lbl_803EA9F4:
	.float 100.0
lbl_803EA9F8:
	.float 10000.0
lbl_803EA9FC:
	.float 1.0
