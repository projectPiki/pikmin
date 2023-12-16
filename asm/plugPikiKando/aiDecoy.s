.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__8ActDecoyFP4Piki, global
/* 800B77AC 000B470C  7C 08 02 A6 */	mflr r0
/* 800B77B0 000B4710  38 A0 00 01 */	li r5, 1
/* 800B77B4 000B4714  90 01 00 04 */	stw r0, 4(r1)
/* 800B77B8 000B4718  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B77BC 000B471C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B77C0 000B4720  3B E3 00 00 */	addi r31, r3, 0
/* 800B77C4 000B4724  48 00 C6 0D */	bl __ct__6ActionFP4Pikib
/* 800B77C8 000B4728  3C 60 80 2B */	lis r3, __vt__19PaniAnimKeyListener@ha
/* 800B77CC 000B472C  38 03 DB 94 */	addi r0, r3, __vt__19PaniAnimKeyListener@l
/* 800B77D0 000B4730  3C 60 80 2B */	lis r3, __vt__8ActDecoy@ha
/* 800B77D4 000B4734  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800B77D8 000B4738  38 63 64 2C */	addi r3, r3, __vt__8ActDecoy@l
/* 800B77DC 000B473C  90 7F 00 00 */	stw r3, 0(r31)
/* 800B77E0 000B4740  38 03 00 64 */	addi r0, r3, 0x64
/* 800B77E4 000B4744  38 7F 00 00 */	addi r3, r31, 0
/* 800B77E8 000B4748  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800B77EC 000B474C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B77F0 000B4750  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B77F4 000B4754  38 21 00 18 */	addi r1, r1, 0x18
/* 800B77F8 000B4758  7C 08 03 A6 */	mtlr r0
/* 800B77FC 000B475C  4E 80 00 20 */	blr 
.endfn __ct__8ActDecoyFP4Piki

.fn findTeki__8ActDecoyFv, global
/* 800B7800 000B4760  7C 08 02 A6 */	mflr r0
/* 800B7804 000B4764  90 01 00 04 */	stw r0, 4(r1)
/* 800B7808 000B4768  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800B780C 000B476C  DB E1 00 48 */	stfd f31, 0x48(r1)
/* 800B7810 000B4770  DB C1 00 40 */	stfd f30, 0x40(r1)
/* 800B7814 000B4774  BF 61 00 2C */	stmw r27, 0x2c(r1)
/* 800B7818 000B4778  7C 7B 1B 78 */	mr r27, r3
/* 800B781C 000B477C  3B 80 00 00 */	li r28, 0
/* 800B7820 000B4780  83 CD 31 60 */	lwz r30, tekiMgr@sda21(r13)
/* 800B7824 000B4784  C3 E2 91 80 */	lfs f31, lbl_803E9380@sda21(r2)
/* 800B7828 000B4788  81 9E 00 00 */	lwz r12, 0(r30)
/* 800B782C 000B478C  38 7E 00 00 */	addi r3, r30, 0
/* 800B7830 000B4790  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800B7834 000B4794  7D 88 03 A6 */	mtlr r12
/* 800B7838 000B4798  4E 80 00 21 */	blrl 
/* 800B783C 000B479C  7C 7D 1B 78 */	mr r29, r3
/* 800B7840 000B47A0  48 00 00 BC */	b .L_800B78FC
.L_800B7844:
/* 800B7844 000B47A4  2C 1D FF FF */	cmpwi r29, -1
/* 800B7848 000B47A8  40 82 00 24 */	bne .L_800B786C
/* 800B784C 000B47AC  7F C3 F3 78 */	mr r3, r30
/* 800B7850 000B47B0  81 9E 00 00 */	lwz r12, 0(r30)
/* 800B7854 000B47B4  38 80 00 00 */	li r4, 0
/* 800B7858 000B47B8  81 8C 00 08 */	lwz r12, 8(r12)
/* 800B785C 000B47BC  7D 88 03 A6 */	mtlr r12
/* 800B7860 000B47C0  4E 80 00 21 */	blrl 
/* 800B7864 000B47C4  7C 7F 1B 78 */	mr r31, r3
/* 800B7868 000B47C8  48 00 00 20 */	b .L_800B7888
.L_800B786C:
/* 800B786C 000B47CC  7F C3 F3 78 */	mr r3, r30
/* 800B7870 000B47D0  81 9E 00 00 */	lwz r12, 0(r30)
/* 800B7874 000B47D4  7F A4 EB 78 */	mr r4, r29
/* 800B7878 000B47D8  81 8C 00 08 */	lwz r12, 8(r12)
/* 800B787C 000B47DC  7D 88 03 A6 */	mtlr r12
/* 800B7880 000B47E0  4E 80 00 21 */	blrl 
/* 800B7884 000B47E4  7C 7F 1B 78 */	mr r31, r3
.L_800B7888:
/* 800B7888 000B47E8  80 9B 00 0C */	lwz r4, 0xc(r27)
/* 800B788C 000B47EC  7F E3 FB 78 */	mr r3, r31
/* 800B7890 000B47F0  4B FD 55 ED */	bl qdist2__FP8CreatureP8Creature
/* 800B7894 000B47F4  81 9F 00 00 */	lwz r12, 0(r31)
/* 800B7898 000B47F8  FF C0 08 90 */	fmr f30, f1
/* 800B789C 000B47FC  7F E3 FB 78 */	mr r3, r31
/* 800B78A0 000B4800  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800B78A4 000B4804  7D 88 03 A6 */	mtlr r12
/* 800B78A8 000B4808  4E 80 00 21 */	blrl 
/* 800B78AC 000B480C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B78B0 000B4810  41 82 00 30 */	beq .L_800B78E0
/* 800B78B4 000B4814  7F E3 FB 78 */	mr r3, r31
/* 800B78B8 000B4818  81 9F 00 00 */	lwz r12, 0(r31)
/* 800B78BC 000B481C  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 800B78C0 000B4820  7D 88 03 A6 */	mtlr r12
/* 800B78C4 000B4824  4E 80 00 21 */	blrl 
/* 800B78C8 000B4828  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B78CC 000B482C  41 82 00 14 */	beq .L_800B78E0
/* 800B78D0 000B4830  FC 1E F8 40 */	fcmpo cr0, f30, f31
/* 800B78D4 000B4834  40 80 00 0C */	bge .L_800B78E0
/* 800B78D8 000B4838  FF E0 F0 90 */	fmr f31, f30
/* 800B78DC 000B483C  7F FC FB 78 */	mr r28, r31
.L_800B78E0:
/* 800B78E0 000B4840  7F C3 F3 78 */	mr r3, r30
/* 800B78E4 000B4844  81 9E 00 00 */	lwz r12, 0(r30)
/* 800B78E8 000B4848  7F A4 EB 78 */	mr r4, r29
/* 800B78EC 000B484C  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800B78F0 000B4850  7D 88 03 A6 */	mtlr r12
/* 800B78F4 000B4854  4E 80 00 21 */	blrl 
/* 800B78F8 000B4858  7C 7D 1B 78 */	mr r29, r3
.L_800B78FC:
/* 800B78FC 000B485C  7F C3 F3 78 */	mr r3, r30
/* 800B7900 000B4860  81 9E 00 00 */	lwz r12, 0(r30)
/* 800B7904 000B4864  7F A4 EB 78 */	mr r4, r29
/* 800B7908 000B4868  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800B790C 000B486C  7D 88 03 A6 */	mtlr r12
/* 800B7910 000B4870  4E 80 00 21 */	blrl 
/* 800B7914 000B4874  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B7918 000B4878  41 82 00 0C */	beq .L_800B7924
/* 800B791C 000B487C  38 00 00 01 */	li r0, 1
/* 800B7920 000B4880  48 00 00 30 */	b .L_800B7950
.L_800B7924:
/* 800B7924 000B4884  7F C3 F3 78 */	mr r3, r30
/* 800B7928 000B4888  81 9E 00 00 */	lwz r12, 0(r30)
/* 800B792C 000B488C  7F A4 EB 78 */	mr r4, r29
/* 800B7930 000B4890  81 8C 00 08 */	lwz r12, 8(r12)
/* 800B7934 000B4894  7D 88 03 A6 */	mtlr r12
/* 800B7938 000B4898  4E 80 00 21 */	blrl 
/* 800B793C 000B489C  28 03 00 00 */	cmplwi r3, 0
/* 800B7940 000B48A0  40 82 00 0C */	bne .L_800B794C
/* 800B7944 000B48A4  38 00 00 01 */	li r0, 1
/* 800B7948 000B48A8  48 00 00 08 */	b .L_800B7950
.L_800B794C:
/* 800B794C 000B48AC  38 00 00 00 */	li r0, 0
.L_800B7950:
/* 800B7950 000B48B0  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 800B7954 000B48B4  41 82 FE F0 */	beq .L_800B7844
/* 800B7958 000B48B8  7F 83 E3 78 */	mr r3, r28
/* 800B795C 000B48BC  BB 61 00 2C */	lmw r27, 0x2c(r1)
/* 800B7960 000B48C0  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800B7964 000B48C4  CB E1 00 48 */	lfd f31, 0x48(r1)
/* 800B7968 000B48C8  CB C1 00 40 */	lfd f30, 0x40(r1)
/* 800B796C 000B48CC  38 21 00 50 */	addi r1, r1, 0x50
/* 800B7970 000B48D0  7C 08 03 A6 */	mtlr r0
/* 800B7974 000B48D4  4E 80 00 20 */	blr 
.endfn findTeki__8ActDecoyFv

.fn init__8ActDecoyFP8Creature, global
/* 800B7978 000B48D8  7C 08 02 A6 */	mflr r0
/* 800B797C 000B48DC  38 80 00 00 */	li r4, 0
/* 800B7980 000B48E0  90 01 00 04 */	stw r0, 4(r1)
/* 800B7984 000B48E4  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800B7988 000B48E8  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800B798C 000B48EC  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800B7990 000B48F0  3B C3 00 00 */	addi r30, r3, 0
/* 800B7994 000B48F4  38 61 00 10 */	addi r3, r1, 0x10
/* 800B7998 000B48F8  48 06 75 C1 */	bl __ct__14PaniMotionInfoFi
/* 800B799C 000B48FC  3B E3 00 00 */	addi r31, r3, 0
/* 800B79A0 000B4900  38 61 00 18 */	addi r3, r1, 0x18
/* 800B79A4 000B4904  38 80 00 00 */	li r4, 0
/* 800B79A8 000B4908  48 06 75 B1 */	bl __ct__14PaniMotionInfoFi
/* 800B79AC 000B490C  7C 64 1B 78 */	mr r4, r3
/* 800B79B0 000B4910  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800B79B4 000B4914  7F E5 FB 78 */	mr r5, r31
/* 800B79B8 000B4918  48 01 30 21 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800B79BC 000B491C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800B79C0 000B4920  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800B79C4 000B4924  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800B79C8 000B4928  38 21 00 28 */	addi r1, r1, 0x28
/* 800B79CC 000B492C  7C 08 03 A6 */	mtlr r0
/* 800B79D0 000B4930  4E 80 00 20 */	blr 
.endfn init__8ActDecoyFP8Creature

.fn cleanup__8ActDecoyFv, global
/* 800B79D4 000B4934  4E 80 00 20 */	blr 
.endfn cleanup__8ActDecoyFv

.fn animationKeyUpdated__8ActDecoyFR16PaniAnimKeyEvent, global
/* 800B79D8 000B4938  4E 80 00 20 */	blr 
.endfn animationKeyUpdated__8ActDecoyFR16PaniAnimKeyEvent

.fn exec__8ActDecoyFv, global
/* 800B79DC 000B493C  7C 08 02 A6 */	mflr r0
/* 800B79E0 000B4940  90 01 00 04 */	stw r0, 4(r1)
/* 800B79E4 000B4944  94 21 FE 98 */	stwu r1, -0x168(r1)
/* 800B79E8 000B4948  DB E1 01 60 */	stfd f31, 0x160(r1)
/* 800B79EC 000B494C  DB C1 01 58 */	stfd f30, 0x158(r1)
/* 800B79F0 000B4950  DB A1 01 50 */	stfd f29, 0x150(r1)
/* 800B79F4 000B4954  DB 81 01 48 */	stfd f28, 0x148(r1)
/* 800B79F8 000B4958  93 E1 01 44 */	stw r31, 0x144(r1)
/* 800B79FC 000B495C  7C 7F 1B 78 */	mr r31, r3
/* 800B7A00 000B4960  93 C1 01 40 */	stw r30, 0x140(r1)
/* 800B7A04 000B4964  93 A1 01 3C */	stw r29, 0x13c(r1)
/* 800B7A08 000B4968  4B FF FD F9 */	bl findTeki__8ActDecoyFv
/* 800B7A0C 000B496C  7C 7D 1B 79 */	or. r29, r3, r3
/* 800B7A10 000B4970  41 82 00 34 */	beq .L_800B7A44
/* 800B7A14 000B4974  7F A3 EB 78 */	mr r3, r29
/* 800B7A18 000B4978  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B7A1C 000B497C  4B FD 54 61 */	bl qdist2__FP8CreatureP8Creature
/* 800B7A20 000B4980  C0 02 91 88 */	lfs f0, lbl_803E9388@sda21(r2)
/* 800B7A24 000B4984  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B7A28 000B4988  40 80 00 10 */	bge .L_800B7A38
/* 800B7A2C 000B498C  38 00 00 00 */	li r0, 0
/* 800B7A30 000B4990  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800B7A34 000B4994  48 00 00 58 */	b .L_800B7A8C
.L_800B7A38:
/* 800B7A38 000B4998  38 00 00 02 */	li r0, 2
/* 800B7A3C 000B499C  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800B7A40 000B49A0  48 00 00 4C */	b .L_800B7A8C
.L_800B7A44:
/* 800B7A44 000B49A4  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 800B7A48 000B49A8  2C 00 00 03 */	cmpwi r0, 3
/* 800B7A4C 000B49AC  41 82 00 38 */	beq .L_800B7A84
/* 800B7A50 000B49B0  C0 02 91 8C */	lfs f0, lbl_803E938C@sda21(r2)
/* 800B7A54 000B49B4  38 61 00 C0 */	addi r3, r1, 0xc0
/* 800B7A58 000B49B8  38 80 00 03 */	li r4, 3
/* 800B7A5C 000B49BC  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 800B7A60 000B49C0  48 06 74 F9 */	bl __ct__14PaniMotionInfoFi
/* 800B7A64 000B49C4  3B C3 00 00 */	addi r30, r3, 0
/* 800B7A68 000B49C8  38 61 00 B8 */	addi r3, r1, 0xb8
/* 800B7A6C 000B49CC  38 80 00 03 */	li r4, 3
/* 800B7A70 000B49D0  48 06 74 E9 */	bl __ct__14PaniMotionInfoFi
/* 800B7A74 000B49D4  7C 64 1B 78 */	mr r4, r3
/* 800B7A78 000B49D8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B7A7C 000B49DC  7F C5 F3 78 */	mr r5, r30
/* 800B7A80 000B49E0  48 01 2F 59 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
.L_800B7A84:
/* 800B7A84 000B49E4  38 00 00 03 */	li r0, 3
/* 800B7A88 000B49E8  90 1F 00 18 */	stw r0, 0x18(r31)
.L_800B7A8C:
/* 800B7A8C 000B49EC  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 800B7A90 000B49F0  2C 00 00 02 */	cmpwi r0, 2
/* 800B7A94 000B49F4  41 82 00 64 */	beq .L_800B7AF8
/* 800B7A98 000B49F8  40 80 00 10 */	bge .L_800B7AA8
/* 800B7A9C 000B49FC  2C 00 00 00 */	cmpwi r0, 0
/* 800B7AA0 000B4A00  41 82 01 C4 */	beq .L_800B7C64
/* 800B7AA4 000B4A04  48 00 04 1C */	b .L_800B7EC0
.L_800B7AA8:
/* 800B7AA8 000B4A08  2C 00 00 04 */	cmpwi r0, 4
/* 800B7AAC 000B4A0C  40 80 04 14 */	bge .L_800B7EC0
/* 800B7AB0 000B4A10  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B7AB4 000B4A14  C0 0D B5 40 */	lfs f0, lbl_803E0260@sda21(r13)
/* 800B7AB8 000B4A18  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800B7ABC 000B4A1C  C0 0D B5 44 */	lfs f0, lbl_803E0264@sda21(r13)
/* 800B7AC0 000B4A20  D0 03 00 04 */	stfs f0, 4(r3)
/* 800B7AC4 000B4A24  C0 0D B5 48 */	lfs f0, lbl_803E0268@sda21(r13)
/* 800B7AC8 000B4A28  D0 03 00 08 */	stfs f0, 8(r3)
/* 800B7ACC 000B4A2C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800B7AD0 000B4A30  C0 3F 00 1C */	lfs f1, 0x1c(r31)
/* 800B7AD4 000B4A34  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 800B7AD8 000B4A38  EC 01 00 28 */	fsubs f0, f1, f0
/* 800B7ADC 000B4A3C  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 800B7AE0 000B4A40  C0 3F 00 1C */	lfs f1, 0x1c(r31)
/* 800B7AE4 000B4A44  C0 02 91 84 */	lfs f0, lbl_803E9384@sda21(r2)
/* 800B7AE8 000B4A48  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B7AEC 000B4A4C  40 80 03 D4 */	bge .L_800B7EC0
/* 800B7AF0 000B4A50  38 60 00 02 */	li r3, 2
/* 800B7AF4 000B4A54  48 00 03 D0 */	b .L_800B7EC4
.L_800B7AF8:
/* 800B7AF8 000B4A58  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B7AFC 000B4A5C  C4 23 00 94 */	lfsu f1, 0x94(r3)
/* 800B7B00 000B4A60  C0 1D 00 94 */	lfs f0, 0x94(r29)
/* 800B7B04 000B4A64  C0 63 00 04 */	lfs f3, 4(r3)
/* 800B7B08 000B4A68  C0 5D 00 98 */	lfs f2, 0x98(r29)
/* 800B7B0C 000B4A6C  EC 01 00 28 */	fsubs f0, f1, f0
/* 800B7B10 000B4A70  C0 83 00 08 */	lfs f4, 8(r3)
/* 800B7B14 000B4A74  C0 3D 00 9C */	lfs f1, 0x9c(r29)
/* 800B7B18 000B4A78  EC 43 10 28 */	fsubs f2, f3, f2
/* 800B7B1C 000B4A7C  D0 01 01 28 */	stfs f0, 0x128(r1)
/* 800B7B20 000B4A80  EC 04 08 28 */	fsubs f0, f4, f1
/* 800B7B24 000B4A84  D0 41 01 2C */	stfs f2, 0x12c(r1)
/* 800B7B28 000B4A88  D0 01 01 30 */	stfs f0, 0x130(r1)
/* 800B7B2C 000B4A8C  C0 21 01 28 */	lfs f1, 0x128(r1)
/* 800B7B30 000B4A90  C0 61 01 30 */	lfs f3, 0x130(r1)
/* 800B7B34 000B4A94  C0 01 01 2C */	lfs f0, 0x12c(r1)
/* 800B7B38 000B4A98  EC 41 00 72 */	fmuls f2, f1, f1
/* 800B7B3C 000B4A9C  EC 63 00 F2 */	fmuls f3, f3, f3
/* 800B7B40 000B4AA0  EC 20 00 32 */	fmuls f1, f0, f0
/* 800B7B44 000B4AA4  C0 02 91 84 */	lfs f0, lbl_803E9384@sda21(r2)
/* 800B7B48 000B4AA8  EC 22 08 2A */	fadds f1, f2, f1
/* 800B7B4C 000B4AAC  EC A3 08 2A */	fadds f5, f3, f1
/* 800B7B50 000B4AB0  FC 05 00 40 */	fcmpo cr0, f5, f0
/* 800B7B54 000B4AB4  40 81 00 5C */	ble .L_800B7BB0
/* 800B7B58 000B4AB8  FC 20 28 34 */	frsqrte f1, f5
/* 800B7B5C 000B4ABC  C8 62 91 90 */	lfd f3, lbl_803E9390@sda21(r2)
/* 800B7B60 000B4AC0  C8 42 91 98 */	lfd f2, lbl_803E9398@sda21(r2)
/* 800B7B64 000B4AC4  FC 01 00 72 */	fmul f0, f1, f1
/* 800B7B68 000B4AC8  FC 23 00 72 */	fmul f1, f3, f1
/* 800B7B6C 000B4ACC  FC 05 00 32 */	fmul f0, f5, f0
/* 800B7B70 000B4AD0  FC 02 00 28 */	fsub f0, f2, f0
/* 800B7B74 000B4AD4  FC 21 00 32 */	fmul f1, f1, f0
/* 800B7B78 000B4AD8  FC 01 00 72 */	fmul f0, f1, f1
/* 800B7B7C 000B4ADC  FC 23 00 72 */	fmul f1, f3, f1
/* 800B7B80 000B4AE0  FC 05 00 32 */	fmul f0, f5, f0
/* 800B7B84 000B4AE4  FC 02 00 28 */	fsub f0, f2, f0
/* 800B7B88 000B4AE8  FC 21 00 32 */	fmul f1, f1, f0
/* 800B7B8C 000B4AEC  FC 01 00 72 */	fmul f0, f1, f1
/* 800B7B90 000B4AF0  FC 23 00 72 */	fmul f1, f3, f1
/* 800B7B94 000B4AF4  FC 05 00 32 */	fmul f0, f5, f0
/* 800B7B98 000B4AF8  FC 02 00 28 */	fsub f0, f2, f0
/* 800B7B9C 000B4AFC  FC 01 00 32 */	fmul f0, f1, f0
/* 800B7BA0 000B4B00  FC 05 00 32 */	fmul f0, f5, f0
/* 800B7BA4 000B4B04  FC 00 00 18 */	frsp f0, f0
/* 800B7BA8 000B4B08  D0 01 00 94 */	stfs f0, 0x94(r1)
/* 800B7BAC 000B4B0C  C0 A1 00 94 */	lfs f5, 0x94(r1)
.L_800B7BB0:
/* 800B7BB0 000B4B10  C0 22 91 A0 */	lfs f1, lbl_803E93A0@sda21(r2)
/* 800B7BB4 000B4B14  C0 01 01 28 */	lfs f0, 0x128(r1)
/* 800B7BB8 000B4B18  EC 61 28 24 */	fdivs f3, f1, f5
/* 800B7BBC 000B4B1C  C0 21 01 2C */	lfs f1, 0x12c(r1)
/* 800B7BC0 000B4B20  C0 41 01 30 */	lfs f2, 0x130(r1)
/* 800B7BC4 000B4B24  EC 00 00 F2 */	fmuls f0, f0, f3
/* 800B7BC8 000B4B28  EC 81 00 F2 */	fmuls f4, f1, f3
/* 800B7BCC 000B4B2C  EC 22 00 F2 */	fmuls f1, f2, f3
/* 800B7BD0 000B4B30  D0 01 01 28 */	stfs f0, 0x128(r1)
/* 800B7BD4 000B4B34  D0 81 01 2C */	stfs f4, 0x12c(r1)
/* 800B7BD8 000B4B38  D0 21 01 30 */	stfs f1, 0x130(r1)
/* 800B7BDC 000B4B3C  C0 02 91 A4 */	lfs f0, lbl_803E93A4@sda21(r2)
/* 800B7BE0 000B4B40  FC 05 00 40 */	fcmpo cr0, f5, f0
/* 800B7BE4 000B4B44  40 80 00 6C */	bge .L_800B7C50
/* 800B7BE8 000B4B48  C0 02 91 88 */	lfs f0, lbl_803E9388@sda21(r2)
/* 800B7BEC 000B4B4C  FC 05 00 40 */	fcmpo cr0, f5, f0
/* 800B7BF0 000B4B50  40 81 00 60 */	ble .L_800B7C50
/* 800B7BF4 000B4B54  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800B7BF8 000B4B58  C0 21 01 28 */	lfs f1, 0x128(r1)
/* 800B7BFC 000B4B5C  C3 83 02 8C */	lfs f28, 0x28c(r3)
/* 800B7C00 000B4B60  C0 41 01 30 */	lfs f2, 0x130(r1)
/* 800B7C04 000B4B64  48 16 3D F5 */	bl atan2f
/* 800B7C08 000B4B68  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B7C0C 000B4B6C  C0 43 00 A0 */	lfs f2, 0xa0(r3)
/* 800B7C10 000B4B70  4B F8 09 A5 */	bl angDist__Fff
/* 800B7C14 000B4B74  EC 21 07 32 */	fmuls f1, f1, f28
/* 800B7C18 000B4B78  C0 02 91 A8 */	lfs f0, lbl_803E93A8@sda21(r2)
/* 800B7C1C 000B4B7C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B7C20 000B4B80  EC 20 00 72 */	fmuls f1, f0, f1
/* 800B7C24 000B4B84  C0 03 00 A0 */	lfs f0, 0xa0(r3)
/* 800B7C28 000B4B88  EC 00 08 2A */	fadds f0, f0, f1
/* 800B7C2C 000B4B8C  D0 03 00 A0 */	stfs f0, 0xa0(r3)
/* 800B7C30 000B4B90  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B7C34 000B4B94  C0 0D B5 4C */	lfs f0, lbl_803E026C@sda21(r13)
/* 800B7C38 000B4B98  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800B7C3C 000B4B9C  C0 0D B5 50 */	lfs f0, lbl_803E0270@sda21(r13)
/* 800B7C40 000B4BA0  D0 03 00 04 */	stfs f0, 4(r3)
/* 800B7C44 000B4BA4  C0 0D B5 54 */	lfs f0, lbl_803E0274@sda21(r13)
/* 800B7C48 000B4BA8  D0 03 00 08 */	stfs f0, 8(r3)
/* 800B7C4C 000B4BAC  48 00 02 74 */	b .L_800B7EC0
.L_800B7C50:
/* 800B7C50 000B4BB0  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B7C54 000B4BB4  38 81 01 28 */	addi r4, r1, 0x128
/* 800B7C58 000B4BB8  C0 22 91 AC */	lfs f1, lbl_803E93AC@sda21(r2)
/* 800B7C5C 000B4BBC  48 01 41 7D */	bl setSpeed__4PikiFfR8Vector3f
/* 800B7C60 000B4BC0  48 00 02 60 */	b .L_800B7EC0
.L_800B7C64:
/* 800B7C64 000B4BC4  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 800B7C68 000B4BC8  48 05 F7 5D */	bl getNavi__7NaviMgrFv
/* 800B7C6C 000B4BCC  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B7C70 000B4BD0  C4 64 00 94 */	lfsu f3, 0x94(r4)
/* 800B7C74 000B4BD4  C0 23 00 94 */	lfs f1, 0x94(r3)
/* 800B7C78 000B4BD8  C0 03 00 98 */	lfs f0, 0x98(r3)
/* 800B7C7C 000B4BDC  C0 44 00 04 */	lfs f2, 4(r4)
/* 800B7C80 000B4BE0  EF E3 08 28 */	fsubs f31, f3, f1
/* 800B7C84 000B4BE4  C0 24 00 08 */	lfs f1, 8(r4)
/* 800B7C88 000B4BE8  EF C2 00 28 */	fsubs f30, f2, f0
/* 800B7C8C 000B4BEC  C0 03 00 9C */	lfs f0, 0x9c(r3)
/* 800B7C90 000B4BF0  EF A1 00 28 */	fsubs f29, f1, f0
/* 800B7C94 000B4BF4  EC 3F 07 F2 */	fmuls f1, f31, f31
/* 800B7C98 000B4BF8  EC 1E 07 B2 */	fmuls f0, f30, f30
/* 800B7C9C 000B4BFC  EC 5D 07 72 */	fmuls f2, f29, f29
/* 800B7CA0 000B4C00  EC 01 00 2A */	fadds f0, f1, f0
/* 800B7CA4 000B4C04  EC 22 00 2A */	fadds f1, f2, f0
/* 800B7CA8 000B4C08  4B F5 5F 99 */	bl sqrtf__3stdFf
/* 800B7CAC 000B4C0C  C0 02 91 84 */	lfs f0, lbl_803E9384@sda21(r2)
/* 800B7CB0 000B4C10  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800B7CB4 000B4C14  41 82 00 10 */	beq .L_800B7CC4
/* 800B7CB8 000B4C18  EF FF 08 24 */	fdivs f31, f31, f1
/* 800B7CBC 000B4C1C  EF DE 08 24 */	fdivs f30, f30, f1
/* 800B7CC0 000B4C20  EF BD 08 24 */	fdivs f29, f29, f1
.L_800B7CC4:
/* 800B7CC4 000B4C24  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B7CC8 000B4C28  C4 23 00 94 */	lfsu f1, 0x94(r3)
/* 800B7CCC 000B4C2C  C0 1D 00 94 */	lfs f0, 0x94(r29)
/* 800B7CD0 000B4C30  C0 63 00 04 */	lfs f3, 4(r3)
/* 800B7CD4 000B4C34  C0 5D 00 98 */	lfs f2, 0x98(r29)
/* 800B7CD8 000B4C38  EC 01 00 28 */	fsubs f0, f1, f0
/* 800B7CDC 000B4C3C  C0 83 00 08 */	lfs f4, 8(r3)
/* 800B7CE0 000B4C40  C0 3D 00 9C */	lfs f1, 0x9c(r29)
/* 800B7CE4 000B4C44  EC 43 10 28 */	fsubs f2, f3, f2
/* 800B7CE8 000B4C48  D0 01 01 0C */	stfs f0, 0x10c(r1)
/* 800B7CEC 000B4C4C  EC 04 08 28 */	fsubs f0, f4, f1
/* 800B7CF0 000B4C50  D0 41 01 10 */	stfs f2, 0x110(r1)
/* 800B7CF4 000B4C54  D0 01 01 14 */	stfs f0, 0x114(r1)
/* 800B7CF8 000B4C58  C0 21 01 0C */	lfs f1, 0x10c(r1)
/* 800B7CFC 000B4C5C  C0 61 01 14 */	lfs f3, 0x114(r1)
/* 800B7D00 000B4C60  C0 01 01 10 */	lfs f0, 0x110(r1)
/* 800B7D04 000B4C64  EC 41 00 72 */	fmuls f2, f1, f1
/* 800B7D08 000B4C68  EC 63 00 F2 */	fmuls f3, f3, f3
/* 800B7D0C 000B4C6C  EC 20 00 32 */	fmuls f1, f0, f0
/* 800B7D10 000B4C70  C0 02 91 84 */	lfs f0, lbl_803E9384@sda21(r2)
/* 800B7D14 000B4C74  EC 22 08 2A */	fadds f1, f2, f1
/* 800B7D18 000B4C78  EF 83 08 2A */	fadds f28, f3, f1
/* 800B7D1C 000B4C7C  FC 1C 00 40 */	fcmpo cr0, f28, f0
/* 800B7D20 000B4C80  40 81 00 5C */	ble .L_800B7D7C
/* 800B7D24 000B4C84  FC 20 E0 34 */	frsqrte f1, f28
/* 800B7D28 000B4C88  C8 62 91 90 */	lfd f3, lbl_803E9390@sda21(r2)
/* 800B7D2C 000B4C8C  C8 42 91 98 */	lfd f2, lbl_803E9398@sda21(r2)
/* 800B7D30 000B4C90  FC 01 00 72 */	fmul f0, f1, f1
/* 800B7D34 000B4C94  FC 23 00 72 */	fmul f1, f3, f1
/* 800B7D38 000B4C98  FC 1C 00 32 */	fmul f0, f28, f0
/* 800B7D3C 000B4C9C  FC 02 00 28 */	fsub f0, f2, f0
/* 800B7D40 000B4CA0  FC 21 00 32 */	fmul f1, f1, f0
/* 800B7D44 000B4CA4  FC 01 00 72 */	fmul f0, f1, f1
/* 800B7D48 000B4CA8  FC 23 00 72 */	fmul f1, f3, f1
/* 800B7D4C 000B4CAC  FC 1C 00 32 */	fmul f0, f28, f0
/* 800B7D50 000B4CB0  FC 02 00 28 */	fsub f0, f2, f0
/* 800B7D54 000B4CB4  FC 21 00 32 */	fmul f1, f1, f0
/* 800B7D58 000B4CB8  FC 01 00 72 */	fmul f0, f1, f1
/* 800B7D5C 000B4CBC  FC 23 00 72 */	fmul f1, f3, f1
/* 800B7D60 000B4CC0  FC 1C 00 32 */	fmul f0, f28, f0
/* 800B7D64 000B4CC4  FC 02 00 28 */	fsub f0, f2, f0
/* 800B7D68 000B4CC8  FC 01 00 32 */	fmul f0, f1, f0
/* 800B7D6C 000B4CCC  FC 1C 00 32 */	fmul f0, f28, f0
/* 800B7D70 000B4CD0  FC 00 00 18 */	frsp f0, f0
/* 800B7D74 000B4CD4  D0 01 00 7C */	stfs f0, 0x7c(r1)
/* 800B7D78 000B4CD8  C3 81 00 7C */	lfs f28, 0x7c(r1)
.L_800B7D7C:
/* 800B7D7C 000B4CDC  C0 22 91 B0 */	lfs f1, lbl_803E93B0@sda21(r2)
/* 800B7D80 000B4CE0  38 C1 00 68 */	addi r6, r1, 0x68
/* 800B7D84 000B4CE4  C0 01 01 0C */	lfs f0, 0x10c(r1)
/* 800B7D88 000B4CE8  38 A1 00 64 */	addi r5, r1, 0x64
/* 800B7D8C 000B4CEC  EC 61 E0 24 */	fdivs f3, f1, f28
/* 800B7D90 000B4CF0  C0 21 01 10 */	lfs f1, 0x110(r1)
/* 800B7D94 000B4CF4  38 81 00 60 */	addi r4, r1, 0x60
/* 800B7D98 000B4CF8  C0 41 01 14 */	lfs f2, 0x114(r1)
/* 800B7D9C 000B4CFC  38 61 00 CC */	addi r3, r1, 0xcc
/* 800B7DA0 000B4D00  EC 00 00 F2 */	fmuls f0, f0, f3
/* 800B7DA4 000B4D04  EC 81 00 F2 */	fmuls f4, f1, f3
/* 800B7DA8 000B4D08  EC 22 00 F2 */	fmuls f1, f2, f3
/* 800B7DAC 000B4D0C  D0 01 01 0C */	stfs f0, 0x10c(r1)
/* 800B7DB0 000B4D10  D0 81 01 10 */	stfs f4, 0x110(r1)
/* 800B7DB4 000B4D14  D0 21 01 14 */	stfs f1, 0x114(r1)
/* 800B7DB8 000B4D18  C0 21 01 0C */	lfs f1, 0x10c(r1)
/* 800B7DBC 000B4D1C  C0 01 01 10 */	lfs f0, 0x110(r1)
/* 800B7DC0 000B4D20  C0 41 01 14 */	lfs f2, 0x114(r1)
/* 800B7DC4 000B4D24  EC 21 07 F2 */	fmuls f1, f1, f31
/* 800B7DC8 000B4D28  EC 00 07 B2 */	fmuls f0, f0, f30
/* 800B7DCC 000B4D2C  EC 42 07 72 */	fmuls f2, f2, f29
/* 800B7DD0 000B4D30  EC 01 00 2A */	fadds f0, f1, f0
/* 800B7DD4 000B4D34  EC 02 00 2A */	fadds f0, f2, f0
/* 800B7DD8 000B4D38  D0 01 00 6C */	stfs f0, 0x6c(r1)
/* 800B7DDC 000B4D3C  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 800B7DE0 000B4D40  54 00 00 7E */	clrlwi r0, r0, 1
/* 800B7DE4 000B4D44  90 01 00 6C */	stw r0, 0x6c(r1)
/* 800B7DE8 000B4D48  C0 01 00 6C */	lfs f0, 0x6c(r1)
/* 800B7DEC 000B4D4C  EC 5D 00 32 */	fmuls f2, f29, f0
/* 800B7DF0 000B4D50  EC 3E 00 32 */	fmuls f1, f30, f0
/* 800B7DF4 000B4D54  EC 1F 00 32 */	fmuls f0, f31, f0
/* 800B7DF8 000B4D58  D0 41 00 68 */	stfs f2, 0x68(r1)
/* 800B7DFC 000B4D5C  D0 21 00 64 */	stfs f1, 0x64(r1)
/* 800B7E00 000B4D60  D0 01 00 60 */	stfs f0, 0x60(r1)
/* 800B7E04 000B4D64  4B F7 F3 19 */	bl __ct__8Vector3fFRCfRCfRCf
/* 800B7E08 000B4D68  C0 AD B5 58 */	lfs f5, lbl_803E0278@sda21(r13)
/* 800B7E0C 000B4D6C  C0 01 00 CC */	lfs f0, 0xcc(r1)
/* 800B7E10 000B4D70  C0 41 00 D0 */	lfs f2, 0xd0(r1)
/* 800B7E14 000B4D74  EC 00 01 72 */	fmuls f0, f0, f5
/* 800B7E18 000B4D78  C0 21 01 0C */	lfs f1, 0x10c(r1)
/* 800B7E1C 000B4D7C  C0 81 00 D4 */	lfs f4, 0xd4(r1)
/* 800B7E20 000B4D80  EC 42 01 72 */	fmuls f2, f2, f5
/* 800B7E24 000B4D84  C0 61 01 10 */	lfs f3, 0x110(r1)
/* 800B7E28 000B4D88  EC 01 00 2A */	fadds f0, f1, f0
/* 800B7E2C 000B4D8C  C0 21 01 14 */	lfs f1, 0x114(r1)
/* 800B7E30 000B4D90  EC 84 01 72 */	fmuls f4, f4, f5
/* 800B7E34 000B4D94  EC 43 10 2A */	fadds f2, f3, f2
/* 800B7E38 000B4D98  D0 01 01 0C */	stfs f0, 0x10c(r1)
/* 800B7E3C 000B4D9C  EC 01 20 2A */	fadds f0, f1, f4
/* 800B7E40 000B4DA0  D0 41 01 10 */	stfs f2, 0x110(r1)
/* 800B7E44 000B4DA4  D0 01 01 14 */	stfs f0, 0x114(r1)
/* 800B7E48 000B4DA8  C0 21 01 0C */	lfs f1, 0x10c(r1)
/* 800B7E4C 000B4DAC  C0 01 01 10 */	lfs f0, 0x110(r1)
/* 800B7E50 000B4DB0  C0 41 01 14 */	lfs f2, 0x114(r1)
/* 800B7E54 000B4DB4  EC 21 00 72 */	fmuls f1, f1, f1
/* 800B7E58 000B4DB8  EC 00 00 32 */	fmuls f0, f0, f0
/* 800B7E5C 000B4DBC  EC 42 00 B2 */	fmuls f2, f2, f2
/* 800B7E60 000B4DC0  EC 01 00 2A */	fadds f0, f1, f0
/* 800B7E64 000B4DC4  EC 22 00 2A */	fadds f1, f2, f0
/* 800B7E68 000B4DC8  4B F5 5D D9 */	bl sqrtf__3stdFf
/* 800B7E6C 000B4DCC  C0 02 91 84 */	lfs f0, lbl_803E9384@sda21(r2)
/* 800B7E70 000B4DD0  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800B7E74 000B4DD4  41 82 00 28 */	beq .L_800B7E9C
/* 800B7E78 000B4DD8  C0 01 01 0C */	lfs f0, 0x10c(r1)
/* 800B7E7C 000B4DDC  EC 00 08 24 */	fdivs f0, f0, f1
/* 800B7E80 000B4DE0  D0 01 01 0C */	stfs f0, 0x10c(r1)
/* 800B7E84 000B4DE4  C0 01 01 10 */	lfs f0, 0x110(r1)
/* 800B7E88 000B4DE8  EC 00 08 24 */	fdivs f0, f0, f1
/* 800B7E8C 000B4DEC  D0 01 01 10 */	stfs f0, 0x110(r1)
/* 800B7E90 000B4DF0  C0 01 01 14 */	lfs f0, 0x114(r1)
/* 800B7E94 000B4DF4  EC 00 08 24 */	fdivs f0, f0, f1
/* 800B7E98 000B4DF8  D0 01 01 14 */	stfs f0, 0x114(r1)
.L_800B7E9C:
/* 800B7E9C 000B4DFC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B7EA0 000B4E00  38 81 01 0C */	addi r4, r1, 0x10c
/* 800B7EA4 000B4E04  C0 22 91 B0 */	lfs f1, lbl_803E93B0@sda21(r2)
/* 800B7EA8 000B4E08  48 01 3F 31 */	bl setSpeed__4PikiFfR8Vector3f
/* 800B7EAC 000B4E0C  C0 02 91 88 */	lfs f0, lbl_803E9388@sda21(r2)
/* 800B7EB0 000B4E10  FC 1C 00 40 */	fcmpo cr0, f28, f0
/* 800B7EB4 000B4E14  40 81 00 0C */	ble .L_800B7EC0
/* 800B7EB8 000B4E18  38 00 00 02 */	li r0, 2
/* 800B7EBC 000B4E1C  90 1F 00 18 */	stw r0, 0x18(r31)
.L_800B7EC0:
/* 800B7EC0 000B4E20  38 60 00 00 */	li r3, 0
.L_800B7EC4:
/* 800B7EC4 000B4E24  80 01 01 6C */	lwz r0, 0x16c(r1)
/* 800B7EC8 000B4E28  CB E1 01 60 */	lfd f31, 0x160(r1)
/* 800B7ECC 000B4E2C  CB C1 01 58 */	lfd f30, 0x158(r1)
/* 800B7ED0 000B4E30  CB A1 01 50 */	lfd f29, 0x150(r1)
/* 800B7ED4 000B4E34  CB 81 01 48 */	lfd f28, 0x148(r1)
/* 800B7ED8 000B4E38  83 E1 01 44 */	lwz r31, 0x144(r1)
/* 800B7EDC 000B4E3C  83 C1 01 40 */	lwz r30, 0x140(r1)
/* 800B7EE0 000B4E40  83 A1 01 3C */	lwz r29, 0x13c(r1)
/* 800B7EE4 000B4E44  38 21 01 68 */	addi r1, r1, 0x168
/* 800B7EE8 000B4E48  7C 08 03 A6 */	mtlr r0
/* 800B7EEC 000B4E4C  4E 80 00 20 */	blr 
.endfn exec__8ActDecoyFv

.fn __dt__8ActDecoyFv, weak
/* 800B7EF0 000B4E50  7C 08 02 A6 */	mflr r0
/* 800B7EF4 000B4E54  90 01 00 04 */	stw r0, 4(r1)
/* 800B7EF8 000B4E58  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B7EFC 000B4E5C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B7F00 000B4E60  3B E4 00 00 */	addi r31, r4, 0
/* 800B7F04 000B4E64  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800B7F08 000B4E68  7C 7E 1B 79 */	or. r30, r3, r3
/* 800B7F0C 000B4E6C  41 82 00 34 */	beq .L_800B7F40
/* 800B7F10 000B4E70  3C 60 80 2B */	lis r3, __vt__8ActDecoy@ha
/* 800B7F14 000B4E74  38 63 64 2C */	addi r3, r3, __vt__8ActDecoy@l
/* 800B7F18 000B4E78  90 7E 00 00 */	stw r3, 0(r30)
/* 800B7F1C 000B4E7C  38 03 00 64 */	addi r0, r3, 0x64
/* 800B7F20 000B4E80  38 7E 00 00 */	addi r3, r30, 0
/* 800B7F24 000B4E84  90 1E 00 14 */	stw r0, 0x14(r30)
/* 800B7F28 000B4E88  38 80 00 00 */	li r4, 0
/* 800B7F2C 000B4E8C  48 00 BE DD */	bl __dt__6ActionFv
/* 800B7F30 000B4E90  7F E0 07 35 */	extsh. r0, r31
/* 800B7F34 000B4E94  40 81 00 0C */	ble .L_800B7F40
/* 800B7F38 000B4E98  7F C3 F3 78 */	mr r3, r30
/* 800B7F3C 000B4E9C  4B F8 F2 71 */	bl __dl__FPv
.L_800B7F40:
/* 800B7F40 000B4EA0  7F C3 F3 78 */	mr r3, r30
/* 800B7F44 000B4EA4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B7F48 000B4EA8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B7F4C 000B4EAC  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800B7F50 000B4EB0  38 21 00 18 */	addi r1, r1, 0x18
/* 800B7F54 000B4EB4  7C 08 03 A6 */	mtlr r0
/* 800B7F58 000B4EB8  4E 80 00 20 */	blr 
.endfn __dt__8ActDecoyFv

.fn "@20@animationKeyUpdated__8ActDecoyFR16PaniAnimKeyEvent", weak
/* 800B7F5C 000B4EBC  38 63 FF EC */	addi r3, r3, -20
/* 800B7F60 000B4EC0  4B FF FA 78 */	b animationKeyUpdated__8ActDecoyFR16PaniAnimKeyEvent
.endfn "@20@animationKeyUpdated__8ActDecoyFR16PaniAnimKeyEvent"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B63C8, local
	.asciz "aiDecoy.cpp"
.endobj lbl_802B63C8
.balign 4
.obj lbl_802B63D4, local
	.asciz "ActDecoy"
.endobj lbl_802B63D4
.balign 4
.obj lbl_802B63E0, local
	.asciz "PaniAnimKeyListener"
.endobj lbl_802B63E0
.balign 4
.obj lbl_802B63F4, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B63F4
.balign 4
.obj lbl_802B6404, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.endobj lbl_802B6404
.obj lbl_802B6410, local
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x14
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B6410
.obj __vt__8ActDecoy, global
	.4byte __RTTI__8ActDecoy
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
	.4byte __dt__8ActDecoyFv
	.4byte init__8ActDecoyFP8Creature
	.4byte exec__8ActDecoyFv
	.4byte cleanup__8ActDecoyFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
	.4byte __RTTI__8ActDecoy
	.4byte 0xFFFFFFEC
	.4byte "@20@animationKeyUpdated__8ActDecoyFR16PaniAnimKeyEvent"
	.4byte animationKeyUpdated__8ActDecoyFR16PaniAnimKeyEvent
.endobj __vt__8ActDecoy
	.4byte 0
	.4byte 0
	.4byte 0
.obj lbl_802B64AC, local
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
.endobj lbl_802B64AC

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E0260, local
	.float 0.0
.endobj lbl_803E0260
.obj lbl_803E0264, local
	.float 0.0
.endobj lbl_803E0264
.obj lbl_803E0268, local
	.float 0.0
.endobj lbl_803E0268
.obj lbl_803E026C, local
	.float 0.0
.endobj lbl_803E026C
.obj lbl_803E0270, local
	.float 0.0
.endobj lbl_803E0270
.obj lbl_803E0274, local
	.float 0.0
.endobj lbl_803E0274
.obj lbl_803E0278, local
	.float 1.3
.endobj lbl_803E0278
.obj __RTTI__19PaniAnimKeyListener, local
	.4byte lbl_802B63E0
	.4byte 0
.endobj __RTTI__19PaniAnimKeyListener
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B63F4
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E028C, local
	.asciz "Action"
.endobj lbl_803E028C
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E028C
	.4byte lbl_802B6404
.endobj __RTTI__6Action
.obj __RTTI__8ActDecoy, local
	.4byte lbl_802B63D4
	.4byte lbl_802B6410
.endobj __RTTI__8ActDecoy

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9380, local
	.float 300.0
.endobj lbl_803E9380
.obj lbl_803E9384, local
	.float 0.0
.endobj lbl_803E9384
.obj lbl_803E9388, local
	.float 60.0
.endobj lbl_803E9388
.obj lbl_803E938C, local
	.float 5.0
.endobj lbl_803E938C
.balign 8
.obj lbl_803E9390, local
	.double 0.5
.endobj lbl_803E9390
.balign 8
.obj lbl_803E9398, local
	.double 3.0
.endobj lbl_803E9398
.obj lbl_803E93A0, local
	.float -1.0
.endobj lbl_803E93A0
.obj lbl_803E93A4, local
	.float 80.0
.endobj lbl_803E93A4
.obj lbl_803E93A8, local
	.float 3.0
.endobj lbl_803E93A8
.obj lbl_803E93AC, local
	.float 0.5
.endobj lbl_803E93AC
.obj lbl_803E93B0, local
	.float 1.0
.endobj lbl_803E93B0
