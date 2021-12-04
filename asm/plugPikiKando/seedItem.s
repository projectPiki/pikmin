.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8012CA04 00129964  41 82 00 0C */	beq lbl_8012CA10
/* 8012CA08 00129968  38 60 00 00 */	li r3, 0
/* 8012CA0C 0012996C  48 00 01 A0 */	b lbl_8012CBAC
lbl_8012CA10:
/* 8012CA10 00129970  80 64 05 5C */	lwz r3, 0x55c(r4)
/* 8012CA14 00129974  3B E4 00 00 */	addi r31, r4, 0
/* 8012CA18 00129978  28 03 00 00 */	cmplwi r3, 0
/* 8012CA1C 0012997C  41 82 00 18 */	beq lbl_8012CA34
/* 8012CA20 00129980  80 03 00 5C */	lwz r0, 0x5c(r3)
/* 8012CA24 00129984  20 00 00 03 */	subfic r0, r0, 3
/* 8012CA28 00129988  7C 00 00 34 */	cntlzw r0, r0
/* 8012CA2C 0012998C  54 00 DE 3E */	rlwinm r0, r0, 0x1b, 0x18, 0x1f
/* 8012CA30 00129990  48 00 00 08 */	b lbl_8012CA38
lbl_8012CA34:
/* 8012CA34 00129994  38 00 00 00 */	li r0, 0
lbl_8012CA38:
/* 8012CA38 00129998  2C 00 00 00 */	cmpwi r0, 0
/* 8012CA3C 0012999C  41 82 00 0C */	beq lbl_8012CA48
/* 8012CA40 001299A0  38 60 00 00 */	li r3, 0
/* 8012CA44 001299A4  48 00 01 68 */	b lbl_8012CBAC
lbl_8012CA48:
/* 8012CA48 001299A8  7F E3 FB 78 */	mr r3, r31
/* 8012CA4C 001299AC  80 9E 00 08 */	lwz r4, 8(r30)
/* 8012CA50 001299B0  4B F6 96 D9 */	bl winnable__6PelletFi
/* 8012CA54 001299B4  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8012CA58 001299B8  40 82 00 0C */	bne lbl_8012CA64
/* 8012CA5C 001299BC  38 60 00 00 */	li r3, 0
/* 8012CA60 001299C0  48 00 01 4C */	b lbl_8012CBAC
lbl_8012CA64:
/* 8012CA64 001299C4  80 7F 05 5C */	lwz r3, 0x55c(r31)
/* 8012CA68 001299C8  80 1E 00 08 */	lwz r0, 8(r30)
/* 8012CA6C 001299CC  80 63 00 7C */	lwz r3, 0x7c(r3)
/* 8012CA70 001299D0  7C 03 00 00 */	cmpw r3, r0
/* 8012CA74 001299D4  40 81 00 0C */	ble lbl_8012CA80
/* 8012CA78 001299D8  38 60 00 00 */	li r3, 0
/* 8012CA7C 001299DC  48 00 01 30 */	b lbl_8012CBAC
lbl_8012CA80:
/* 8012CA80 001299E0  38 61 00 48 */	addi r3, r1, 0x48
/* 8012CA84 001299E4  38 9F 00 00 */	addi r4, r31, 0
/* 8012CA88 001299E8  4B F6 41 FD */	bl __ct__8StickersFP8Creature
/* 8012CA8C 001299EC  3B A1 00 48 */	addi r29, r1, 0x48
/* 8012CA90 001299F0  38 7D 00 00 */	addi r3, r29, 0
/* 8012CA94 001299F4  81 9D 00 00 */	lwz r12, 0(r29)
/* 8012CA98 001299F8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8012CA9C 001299FC  7D 88 03 A6 */	mtlr r12
/* 8012CAA0 00129A00  4E 80 00 21 */	blrl 
/* 8012CAA4 00129A04  7C 7C 1B 78 */	mr r28, r3
/* 8012CAA8 00129A08  48 00 00 90 */	b lbl_8012CB38
lbl_8012CAAC:
/* 8012CAAC 00129A0C  2C 1C FF FF */	cmpwi r28, -1
/* 8012CAB0 00129A10  40 82 00 20 */	bne lbl_8012CAD0
/* 8012CAB4 00129A14  7F A3 EB 78 */	mr r3, r29
/* 8012CAB8 00129A18  81 9D 00 00 */	lwz r12, 0(r29)
/* 8012CABC 00129A1C  38 80 00 00 */	li r4, 0
/* 8012CAC0 00129A20  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012CAC4 00129A24  7D 88 03 A6 */	mtlr r12
/* 8012CAC8 00129A28  4E 80 00 21 */	blrl 
/* 8012CACC 00129A2C  48 00 00 1C */	b lbl_8012CAE8
lbl_8012CAD0:
/* 8012CAD0 00129A30  7F A3 EB 78 */	mr r3, r29
/* 8012CAD4 00129A34  81 9D 00 00 */	lwz r12, 0(r29)
/* 8012CAD8 00129A38  7F 84 E3 78 */	mr r4, r28
/* 8012CADC 00129A3C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012CAE0 00129A40  7D 88 03 A6 */	mtlr r12
/* 8012CAE4 00129A44  4E 80 00 21 */	blrl 
lbl_8012CAE8:
/* 8012CAE8 00129A48  28 03 00 00 */	cmplwi r3, 0
/* 8012CAEC 00129A4C  41 82 00 A8 */	beq lbl_8012CB94
/* 8012CAF0 00129A50  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 8012CAF4 00129A54  2C 00 00 37 */	cmpwi r0, 0x37
/* 8012CAF8 00129A58  40 82 00 24 */	bne lbl_8012CB1C
/* 8012CAFC 00129A5C  80 1E 00 04 */	lwz r0, 4(r30)
/* 8012CB00 00129A60  7C 03 00 40 */	cmplw r3, r0
/* 8012CB04 00129A64  41 82 00 18 */	beq lbl_8012CB1C
/* 8012CB08 00129A68  80 03 03 20 */	lwz r0, 0x320(r3)
/* 8012CB0C 00129A6C  2C 00 00 08 */	cmpwi r0, 8
/* 8012CB10 00129A70  40 82 00 0C */	bne lbl_8012CB1C
/* 8012CB14 00129A74  38 60 00 00 */	li r3, 0
/* 8012CB18 00129A78  48 00 00 94 */	b lbl_8012CBAC
lbl_8012CB1C:
/* 8012CB1C 00129A7C  7F A3 EB 78 */	mr r3, r29
/* 8012CB20 00129A80  81 9D 00 00 */	lwz r12, 0(r29)
/* 8012CB24 00129A84  7F 84 E3 78 */	mr r4, r28
/* 8012CB28 00129A88  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8012CB2C 00129A8C  7D 88 03 A6 */	mtlr r12
/* 8012CB30 00129A90  4E 80 00 21 */	blrl 
/* 8012CB34 00129A94  7C 7C 1B 78 */	mr r28, r3
lbl_8012CB38:
/* 8012CB38 00129A98  7F A3 EB 78 */	mr r3, r29
/* 8012CB3C 00129A9C  81 9D 00 00 */	lwz r12, 0(r29)
/* 8012CB40 00129AA0  7F 84 E3 78 */	mr r4, r28
/* 8012CB44 00129AA4  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8012CB48 00129AA8  7D 88 03 A6 */	mtlr r12
/* 8012CB4C 00129AAC  4E 80 00 21 */	blrl 
/* 8012CB50 00129AB0  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8012CB54 00129AB4  41 82 00 0C */	beq lbl_8012CB60
/* 8012CB58 00129AB8  38 00 00 01 */	li r0, 1
/* 8012CB5C 00129ABC  48 00 00 30 */	b lbl_8012CB8C
lbl_8012CB60:
/* 8012CB60 00129AC0  7F A3 EB 78 */	mr r3, r29
/* 8012CB64 00129AC4  81 9D 00 00 */	lwz r12, 0(r29)
/* 8012CB68 00129AC8  7F 84 E3 78 */	mr r4, r28
/* 8012CB6C 00129ACC  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012CB70 00129AD0  7D 88 03 A6 */	mtlr r12
/* 8012CB74 00129AD4  4E 80 00 21 */	blrl 
/* 8012CB78 00129AD8  28 03 00 00 */	cmplwi r3, 0
/* 8012CB7C 00129ADC  40 82 00 0C */	bne lbl_8012CB88
/* 8012CB80 00129AE0  38 00 00 01 */	li r0, 1
/* 8012CB84 00129AE4  48 00 00 08 */	b lbl_8012CB8C
lbl_8012CB88:
/* 8012CB88 00129AE8  38 00 00 00 */	li r0, 0
lbl_8012CB8C:
/* 8012CB8C 00129AEC  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8012CB90 00129AF0  41 82 FF 1C */	beq lbl_8012CAAC
lbl_8012CB94:
/* 8012CB94 00129AF4  80 1F 01 84 */	lwz r0, 0x184(r31)
/* 8012CB98 00129AF8  28 00 00 00 */	cmplwi r0, 0
/* 8012CB9C 00129AFC  41 82 00 0C */	beq lbl_8012CBA8
/* 8012CBA0 00129B00  38 60 00 00 */	li r3, 0
/* 8012CBA4 00129B04  48 00 00 08 */	b lbl_8012CBAC
lbl_8012CBA8:
/* 8012CBA8 00129B08  38 60 00 01 */	li r3, 1
lbl_8012CBAC:
/* 8012CBAC 00129B0C  80 01 00 74 */	lwz r0, 0x74(r1)
/* 8012CBB0 00129B10  83 E1 00 6C */	lwz r31, 0x6c(r1)
/* 8012CBB4 00129B14  83 C1 00 68 */	lwz r30, 0x68(r1)
/* 8012CBB8 00129B18  83 A1 00 64 */	lwz r29, 0x64(r1)
/* 8012CBBC 00129B1C  83 81 00 60 */	lwz r28, 0x60(r1)
/* 8012CBC0 00129B20  38 21 00 70 */	addi r1, r1, 0x70
/* 8012CBC4 00129B24  7C 08 03 A6 */	mtlr r0
/* 8012CBC8 00129B28  4E 80 00 20 */	blr 

.global start__25TaiCollecImpassableActionFR4Teki
start__25TaiCollecImpassableActionFR4Teki:
/* 8012CBCC 00129B2C  7C 08 02 A6 */	mflr r0
/* 8012CBD0 00129B30  90 01 00 04 */	stw r0, 4(r1)
/* 8012CBD4 00129B34  94 21 FF F8 */	stwu r1, -8(r1)
/* 8012CBD8 00129B38  80 04 03 30 */	lwz r0, 0x330(r4)
/* 8012CBDC 00129B3C  2C 00 00 03 */	cmpwi r0, 3
/* 8012CBE0 00129B40  41 82 00 1C */	beq lbl_8012CBFC
/* 8012CBE4 00129B44  2C 00 00 04 */	cmpwi r0, 4
/* 8012CBE8 00129B48  41 82 00 14 */	beq lbl_8012CBFC
/* 8012CBEC 00129B4C  2C 00 00 06 */	cmpwi r0, 6
/* 8012CBF0 00129B50  40 82 00 08 */	bne lbl_8012CBF8
/* 8012CBF4 00129B54  48 00 00 08 */	b lbl_8012CBFC
lbl_8012CBF8:
/* 8012CBF8 00129B58  48 00 00 C1 */	bl resetPosition__25TaiCollecImpassableActionFR4Teki
lbl_8012CBFC:
/* 8012CBFC 00129B5C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8012CC00 00129B60  38 21 00 08 */	addi r1, r1, 8
/* 8012CC04 00129B64  7C 08 03 A6 */	mtlr r0
/* 8012CC08 00129B68  4E 80 00 20 */	blr 

.global act__25TaiCollecImpassableActionFR4Teki
act__25TaiCollecImpassableActionFR4Teki:
/* 8012CC0C 00129B6C  7C 08 02 A6 */	mflr r0
/* 8012CC10 00129B70  90 01 00 04 */	stw r0, 4(r1)
/* 8012CC14 00129B74  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 8012CC18 00129B78  93 E1 00 44 */	stw r31, 0x44(r1)
/* 8012CC1C 00129B7C  7C 9F 23 78 */	mr r31, r4
/* 8012CC20 00129B80  93 C1 00 40 */	stw r30, 0x40(r1)
/* 8012CC24 00129B84  7C 7E 1B 78 */	mr r30, r3
/* 8012CC28 00129B88  C0 44 00 9C */	lfs f2, 0x9c(r4)
/* 8012CC2C 00129B8C  C0 64 03 90 */	lfs f3, 0x390(r4)
/* 8012CC30 00129B90  C0 3F 03 88 */	lfs f1, 0x388(r31)
/* 8012CC34 00129B94  C0 1F 00 94 */	lfs f0, 0x94(r31)
/* 8012CC38 00129B98  EC 43 10 28 */	fsubs f2, f3, f2
/* 8012CC3C 00129B9C  EC 21 00 28 */	fsubs f1, f1, f0
/* 8012CC40 00129BA0  EC 02 00 B2 */	fmuls f0, f2, f2
/* 8012CC44 00129BA4  EC 21 00 72 */	fmuls f1, f1, f1
/* 8012CC48 00129BA8  EC 21 00 2A */	fadds f1, f1, f0
/* 8012CC4C 00129BAC  4B EE 0F F5 */	bl sqrtf__3stdFf
/* 8012CC50 00129BB0  C0 1E 00 10 */	lfs f0, 0x10(r30)
/* 8012CC54 00129BB4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8012CC58 00129BB8  4C 41 13 82 */	cror 2, 1, 2
/* 8012CC5C 00129BBC  40 82 00 18 */	bne lbl_8012CC74
/* 8012CC60 00129BC0  38 7E 00 00 */	addi r3, r30, 0
/* 8012CC64 00129BC4  38 9F 00 00 */	addi r4, r31, 0
/* 8012CC68 00129BC8  48 00 00 51 */	bl resetPosition__25TaiCollecImpassableActionFR4Teki
/* 8012CC6C 00129BCC  38 60 00 00 */	li r3, 0
/* 8012CC70 00129BD0  48 00 00 30 */	b lbl_8012CCA0
lbl_8012CC74:
/* 8012CC74 00129BD4  80 1E 00 08 */	lwz r0, 8(r30)
/* 8012CC78 00129BD8  C0 02 A2 A0 */	lfs f0, lbl_803EA4A0@sda21(r2)
/* 8012CC7C 00129BDC  54 00 10 3A */	slwi r0, r0, 2
/* 8012CC80 00129BE0  7C 7F 02 14 */	add r3, r31, r0
/* 8012CC84 00129BE4  C0 23 03 C4 */	lfs f1, 0x3c4(r3)
/* 8012CC88 00129BE8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8012CC8C 00129BEC  4C 40 13 82 */	cror 2, 0, 2
/* 8012CC90 00129BF0  41 82 00 0C */	beq lbl_8012CC9C
/* 8012CC94 00129BF4  38 60 00 00 */	li r3, 0
/* 8012CC98 00129BF8  48 00 00 08 */	b lbl_8012CCA0
lbl_8012CC9C:
/* 8012CC9C 00129BFC  38 60 00 01 */	li r3, 1
lbl_8012CCA0:
/* 8012CCA0 00129C00  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 8012CCA4 00129C04  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 8012CCA8 00129C08  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 8012CCAC 00129C0C  38 21 00 48 */	addi r1, r1, 0x48
/* 8012CCB0 00129C10  7C 08 03 A6 */	mtlr r0
/* 8012CCB4 00129C14  4E 80 00 20 */	blr 

.global resetPosition__25TaiCollecImpassableActionFR4Teki
resetPosition__25TaiCollecImpassableActionFR4Teki:
/* 8012CCB8 00129C18  C0 04 00 94 */	lfs f0, 0x94(r4)
/* 8012CCBC 00129C1C  D0 04 03 88 */	stfs f0, 0x388(r4)
/* 8012CCC0 00129C20  C0 04 00 98 */	lfs f0, 0x98(r4)
/* 8012CCC4 00129C24  D0 04 03 8C */	stfs f0, 0x38c(r4)
/* 8012CCC8 00129C28  C0 04 00 9C */	lfs f0, 0x9c(r4)
/* 8012CCCC 00129C2C  D0 04 03 90 */	stfs f0, 0x390(r4)
/* 8012CCD0 00129C30  80 03 00 08 */	lwz r0, 8(r3)
/* 8012CCD4 00129C34  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 8012CCD8 00129C38  54 00 10 3A */	slwi r0, r0, 2
/* 8012CCDC 00129C3C  7C 64 02 14 */	add r3, r4, r0
/* 8012CCE0 00129C40  D0 03 03 C4 */	stfs f0, 0x3c4(r3)
/* 8012CCE4 00129C44  4E 80 00 20 */	blr 

.global act__28TaiCollecLetGoOfPelletActionFR4Teki
act__28TaiCollecLetGoOfPelletActionFR4Teki:
/* 8012CCE8 00129C48  7C 08 02 A6 */	mflr r0
/* 8012CCEC 00129C4C  90 01 00 04 */	stw r0, 4(r1)
/* 8012CCF0 00129C50  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8012CCF4 00129C54  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8012CCF8 00129C58  7C 9F 23 78 */	mr r31, r4
/* 8012CCFC 00129C5C  80 04 04 20 */	lwz r0, 0x420(r4)
/* 8012CD00 00129C60  28 00 00 00 */	cmplwi r0, 0
/* 8012CD04 00129C64  40 82 00 0C */	bne lbl_8012CD10
/* 8012CD08 00129C68  38 60 00 01 */	li r3, 1
/* 8012CD0C 00129C6C  48 00 00 38 */	b lbl_8012CD44
lbl_8012CD10:
/* 8012CD10 00129C70  7C 03 03 78 */	mr r3, r0
/* 8012CD14 00129C74  38 9F 00 00 */	addi r4, r31, 0
/* 8012CD18 00129C78  4B F6 93 7D */	bl endStickTeki__6PelletFP8Creature
/* 8012CD1C 00129C7C  80 7F 04 20 */	lwz r3, 0x420(r31)
/* 8012CD20 00129C80  28 03 00 00 */	cmplwi r3, 0
/* 8012CD24 00129C84  41 82 00 10 */	beq lbl_8012CD34
/* 8012CD28 00129C88  4B FB 76 45 */	bl subCnt__12RefCountableFv
/* 8012CD2C 00129C8C  38 00 00 00 */	li r0, 0
/* 8012CD30 00129C90  90 1F 04 20 */	stw r0, 0x420(r31)
lbl_8012CD34:
/* 8012CD34 00129C94  38 7F 00 00 */	addi r3, r31, 0
/* 8012CD38 00129C98  38 80 00 02 */	li r4, 2
/* 8012CD3C 00129C9C  48 01 CC E1 */	bl stopParticleGenerator__5BTekiFi
/* 8012CD40 00129CA0  38 60 00 01 */	li r3, 1
lbl_8012CD44:
/* 8012CD44 00129CA4  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8012CD48 00129CA8  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8012CD4C 00129CAC  38 21 00 28 */	addi r1, r1, 0x28
/* 8012CD50 00129CB0  7C 08 03 A6 */	mtlr r0
/* 8012CD54 00129CB4  4E 80 00 20 */	blr 

.global actByEvent__28TaiCollecLetGoOfPelletActionFR9TekiEvent
actByEvent__28TaiCollecLetGoOfPelletActionFR9TekiEvent:
/* 8012CD58 00129CB8  7C 08 02 A6 */	mflr r0
/* 8012CD5C 00129CBC  90 01 00 04 */	stw r0, 4(r1)
/* 8012CD60 00129CC0  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8012CD64 00129CC4  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8012CD68 00129CC8  80 64 00 04 */	lwz r3, 4(r4)
/* 8012CD6C 00129CCC  80 03 04 20 */	lwz r0, 0x420(r3)
/* 8012CD70 00129CD0  3B E3 00 00 */	addi r31, r3, 0
/* 8012CD74 00129CD4  28 00 00 00 */	cmplwi r0, 0
/* 8012CD78 00129CD8  40 82 00 0C */	bne lbl_8012CD84
/* 8012CD7C 00129CDC  38 60 00 01 */	li r3, 1
/* 8012CD80 00129CE0  48 00 00 38 */	b lbl_8012CDB8
lbl_8012CD84:
/* 8012CD84 00129CE4  7C 03 03 78 */	mr r3, r0
/* 8012CD88 00129CE8  38 9F 00 00 */	addi r4, r31, 0
/* 8012CD8C 00129CEC  4B F6 93 09 */	bl endStickTeki__6PelletFP8Creature
/* 8012CD90 00129CF0  80 7F 04 20 */	lwz r3, 0x420(r31)
/* 8012CD94 00129CF4  28 03 00 00 */	cmplwi r3, 0
/* 8012CD98 00129CF8  41 82 00 10 */	beq lbl_8012CDA8
/* 8012CD9C 00129CFC  4B FB 75 D1 */	bl subCnt__12RefCountableFv
/* 8012CDA0 00129D00  38 00 00 00 */	li r0, 0
/* 8012CDA4 00129D04  90 1F 04 20 */	stw r0, 0x420(r31)
lbl_8012CDA8:
/* 8012CDA8 00129D08  38 7F 00 00 */	addi r3, r31, 0
/* 8012CDAC 00129D0C  38 80 00 02 */	li r4, 2
/* 8012CDB0 00129D10  48 01 CC 6D */	bl stopParticleGenerator__5BTekiFi
/* 8012CDB4 00129D14  38 60 00 01 */	li r3, 1
lbl_8012CDB8:
/* 8012CDB8 00129D18  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8012CDBC 00129D1C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8012CDC0 00129D20  38 21 00 28 */	addi r1, r1, 0x28
/* 8012CDC4 00129D24  7C 08 03 A6 */	mtlr r0
/* 8012CDC8 00129D28  4E 80 00 20 */	blr 

.global act__27TaiCollecTargetPelletActionFR4Teki
act__27TaiCollecTargetPelletActionFR4Teki:
/* 8012CDCC 00129D2C  7C 08 02 A6 */	mflr r0
/* 8012CDD0 00129D30  3D 00 80 2C */	lis r8, __vt__31TekiCollecTargetPelletCondition@ha
/* 8012CDD4 00129D34  90 01 00 04 */	stw r0, 4(r1)
/* 8012CDD8 00129D38  3C A0 80 2B */	lis r5, __vt__9Condition@ha
/* 8012CDDC 00129D3C  39 88 7B 34 */	addi r12, r8, __vt__31TekiCollecTargetPelletCondition@l
/* 8012CDE0 00129D40  94 21 FE D0 */	stwu r1, -0x130(r1)
/* 8012CDE4 00129D44  3D 60 80 2D */	lis r11, __vt__28TekiCreaturePointerCondition@ha
/* 8012CDE8 00129D48  3D 20 80 2C */	lis r9, __vt__16TekiNotCondition@ha
/* 8012CDEC 00129D4C  BF 21 01 14 */	stmw r25, 0x114(r1)
/* 8012CDF0 00129D50  7C 9F 23 78 */	mr r31, r4
/* 8012CDF4 00129D54  3B 45 F0 98 */	addi r26, r5, __vt__9Condition@l
/* 8012CDF8 00129D58  3B A9 68 90 */	addi r29, r9, __vt__16TekiNotCondition@l
/* 8012CDFC 00129D5C  3B 8B D6 68 */	addi r28, r11, __vt__28TekiCreaturePointerCondition@l
/* 8012CE00 00129D60  39 21 00 E8 */	addi r9, r1, 0xe8
/* 8012CE04 00129D64  3B C1 00 CC */	addi r30, r1, 0xcc
/* 8012CE08 00129D68  39 01 00 DC */	addi r8, r1, 0xdc
/* 8012CE0C 00129D6C  38 A1 00 FC */	addi r5, r1, 0xfc
/* 8012CE10 00129D70  80 C4 02 C4 */	lwz r6, 0x2c4(r4)
/* 8012CE14 00129D74  3C 80 80 2C */	lis r4, __vt__13TekiCondition@ha
/* 8012CE18 00129D78  3B 64 69 64 */	addi r27, r4, __vt__13TekiCondition@l
/* 8012CE1C 00129D7C  80 1F 04 24 */	lwz r0, 0x424(r31)
/* 8012CE20 00129D80  80 C6 00 84 */	lwz r6, 0x84(r6)
/* 8012CE24 00129D84  80 6D 30 1C */	lwz r3, pelletMgr@sda21(r13)
/* 8012CE28 00129D88  38 9F 00 94 */	addi r4, r31, 0x94
/* 8012CE2C 00129D8C  80 E6 00 00 */	lwz r7, 0(r6)
/* 8012CE30 00129D90  3C C0 80 2C */	lis r6, __vt__16TekiAndCondition@ha
/* 8012CE34 00129D94  81 47 00 00 */	lwz r10, 0(r7)
/* 8012CE38 00129D98  3C E0 80 2D */	lis r7, __vt__20TekiVisibleCondition@ha
/* 8012CE3C 00129D9C  39 67 D5 0C */	addi r11, r7, __vt__20TekiVisibleCondition@l
/* 8012CE40 00129DA0  83 2A 00 50 */	lwz r25, 0x50(r10)
/* 8012CE44 00129DA4  39 46 68 5C */	addi r10, r6, __vt__16TekiAndCondition@l
/* 8012CE48 00129DA8  38 E1 00 F0 */	addi r7, r1, 0xf0
/* 8012CE4C 00129DAC  93 41 00 DC */	stw r26, 0xdc(r1)
/* 8012CE50 00129DB0  38 C1 00 D4 */	addi r6, r1, 0xd4
/* 8012CE54 00129DB4  93 41 00 F0 */	stw r26, 0xf0(r1)
/* 8012CE58 00129DB8  93 41 00 FC */	stw r26, 0xfc(r1)
/* 8012CE5C 00129DBC  93 41 00 CC */	stw r26, 0xcc(r1)
/* 8012CE60 00129DC0  93 41 00 D4 */	stw r26, 0xd4(r1)
/* 8012CE64 00129DC4  93 61 00 DC */	stw r27, 0xdc(r1)
/* 8012CE68 00129DC8  93 41 00 E8 */	stw r26, 0xe8(r1)
/* 8012CE6C 00129DCC  93 61 00 F0 */	stw r27, 0xf0(r1)
/* 8012CE70 00129DD0  93 61 00 FC */	stw r27, 0xfc(r1)
/* 8012CE74 00129DD4  93 61 00 CC */	stw r27, 0xcc(r1)
/* 8012CE78 00129DD8  93 61 00 D4 */	stw r27, 0xd4(r1)
/* 8012CE7C 00129DDC  91 81 00 DC */	stw r12, 0xdc(r1)
/* 8012CE80 00129DE0  93 61 00 E8 */	stw r27, 0xe8(r1)
/* 8012CE84 00129DE4  91 41 00 F0 */	stw r10, 0xf0(r1)
/* 8012CE88 00129DE8  91 41 00 FC */	stw r10, 0xfc(r1)
/* 8012CE8C 00129DEC  93 81 00 CC */	stw r28, 0xcc(r1)
/* 8012CE90 00129DF0  93 A1 00 D4 */	stw r29, 0xd4(r1)
/* 8012CE94 00129DF4  93 E1 00 E0 */	stw r31, 0xe0(r1)
/* 8012CE98 00129DF8  91 61 00 E8 */	stw r11, 0xe8(r1)
/* 8012CE9C 00129DFC  91 21 00 F4 */	stw r9, 0xf4(r1)
/* 8012CEA0 00129E00  90 E1 01 00 */	stw r7, 0x100(r1)
/* 8012CEA4 00129E04  90 01 00 D0 */	stw r0, 0xd0(r1)
/* 8012CEA8 00129E08  93 C1 00 D8 */	stw r30, 0xd8(r1)
/* 8012CEAC 00129E0C  93 21 00 E4 */	stw r25, 0xe4(r1)
/* 8012CEB0 00129E10  93 E1 00 EC */	stw r31, 0xec(r1)
/* 8012CEB4 00129E14  91 01 00 F8 */	stw r8, 0xf8(r1)
/* 8012CEB8 00129E18  90 C1 01 04 */	stw r6, 0x104(r1)
/* 8012CEBC 00129E1C  81 83 00 00 */	lwz r12, 0(r3)
/* 8012CEC0 00129E20  81 8C 00 6C */	lwz r12, 0x6c(r12)
/* 8012CEC4 00129E24  7D 88 03 A6 */	mtlr r12
/* 8012CEC8 00129E28  4E 80 00 21 */	blrl 
/* 8012CECC 00129E2C  7C 7E 1B 79 */	or. r30, r3, r3
/* 8012CED0 00129E30  40 82 00 0C */	bne lbl_8012CEDC
/* 8012CED4 00129E34  38 60 00 00 */	li r3, 0
/* 8012CED8 00129E38  48 00 00 38 */	b lbl_8012CF10
lbl_8012CEDC:
/* 8012CEDC 00129E3C  80 7F 04 18 */	lwz r3, 0x418(r31)
/* 8012CEE0 00129E40  28 03 00 00 */	cmplwi r3, 0
/* 8012CEE4 00129E44  41 82 00 14 */	beq lbl_8012CEF8
/* 8012CEE8 00129E48  41 82 00 10 */	beq lbl_8012CEF8
/* 8012CEEC 00129E4C  4B FB 74 81 */	bl subCnt__12RefCountableFv
/* 8012CEF0 00129E50  38 00 00 00 */	li r0, 0
/* 8012CEF4 00129E54  90 1F 04 18 */	stw r0, 0x418(r31)
lbl_8012CEF8:
/* 8012CEF8 00129E58  93 DF 04 18 */	stw r30, 0x418(r31)
/* 8012CEFC 00129E5C  80 7F 04 18 */	lwz r3, 0x418(r31)
/* 8012CF00 00129E60  28 03 00 00 */	cmplwi r3, 0
/* 8012CF04 00129E64  41 82 00 08 */	beq lbl_8012CF0C
/* 8012CF08 00129E68  4B FB 74 55 */	bl addCnt__12RefCountableFv
lbl_8012CF0C:
/* 8012CF0C 00129E6C  38 60 00 01 */	li r3, 1
lbl_8012CF10:
/* 8012CF10 00129E70  BB 21 01 14 */	lmw r25, 0x114(r1)
/* 8012CF14 00129E74  80 01 01 34 */	lwz r0, 0x134(r1)
/* 8012CF18 00129E78  38 21 01 30 */	addi r1, r1, 0x130
/* 8012CF1C 00129E7C  7C 08 03 A6 */	mtlr r0
/* 8012CF20 00129E80  4E 80 00 20 */	blr 

.global act__38TaiCollecVisibleHeightPelletLostActionFR4Teki
act__38TaiCollecVisibleHeightPelletLostActionFR4Teki:
/* 8012CF24 00129E84  7C 08 02 A6 */	mflr r0
/* 8012CF28 00129E88  90 01 00 04 */	stw r0, 4(r1)
/* 8012CF2C 00129E8C  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8012CF30 00129E90  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8012CF34 00129E94  93 C1 00 38 */	stw r30, 0x38(r1)
/* 8012CF38 00129E98  7C 9E 23 78 */	mr r30, r4
/* 8012CF3C 00129E9C  83 E4 04 18 */	lwz r31, 0x418(r4)
/* 8012CF40 00129EA0  28 1F 00 00 */	cmplwi r31, 0
/* 8012CF44 00129EA4  38 9F 00 00 */	addi r4, r31, 0
/* 8012CF48 00129EA8  40 82 00 0C */	bne lbl_8012CF54
/* 8012CF4C 00129EAC  38 60 00 01 */	li r3, 1
/* 8012CF50 00129EB0  48 00 00 9C */	b lbl_8012CFEC

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x73656564
	.4byte 0x4974656d
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x73656564
	.4byte 0x4974656d
	.4byte 0
	.4byte 0x53656564
	.4byte 0x4974656d
	.4byte 0
	.4byte 0x4576656e
	.4byte 0x7454616c
	.4byte 0x6b657200
	.4byte 0x52656643
	.4byte 0x6f756e74
	.4byte 0x61626c65
	.4byte 0
	.4byte 0x43726561
	.4byte 0x74757265
	.4byte 0
	.4byte 0x803E1a38
	.4byte 0x8
	.4byte 0x803E1a40
	.4byte 0
	.4byte 0
	.4byte 0x803E1a38
	.4byte 0x8
	.4byte 0x803E1a40
	.4byte 0
	.4byte 0x803E1a48
	.4byte 0
	.4byte 0
.global __vt__8SeedItem
__vt__8SeedItem:
	.4byte __RTTI__8SeedItem
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8SeedItemFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__8SeedItemFv
	.4byte getSize__8SeedItemFv
	.4byte getHeight__8SeedItemFv
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
	.4byte isVisible__8SeedItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8SeedItemFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__8SeedItemFR11Interaction
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
	.4byte update__8SeedItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__8SeedItemFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__8SeedItemFv
	.4byte doAnimation__8CreatureFv
	.4byte doKill__8SeedItemFv
	.4byte exitCourse__8CreatureFv
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global __RTTI__7KeyItem
__RTTI__7KeyItem:
	.4byte 0x803E19f8
	.4byte 0x802bd304
	.4byte 0x802bd460
	.4byte 0
	.4byte 0x802bd46c
	.4byte 0
	.4byte 0x802bd47c
	.4byte 0x802bd488
	.4byte 0x802bd49c
	.4byte 0x802bd4ac
