.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__8ActEnterFP4Piki, global
/* 800B7F64 000B4EC4  7C 08 02 A6 */	mflr r0
/* 800B7F68 000B4EC8  38 A0 00 01 */	li r5, 1
/* 800B7F6C 000B4ECC  90 01 00 04 */	stw r0, 4(r1)
/* 800B7F70 000B4ED0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B7F74 000B4ED4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B7F78 000B4ED8  3B E3 00 00 */	addi r31, r3, 0
/* 800B7F7C 000B4EDC  48 00 BE 55 */	bl __ct__6ActionFP4Pikib
/* 800B7F80 000B4EE0  3C 60 80 2B */	lis r3, __vt__8ActEnter@ha
/* 800B7F84 000B4EE4  38 03 65 58 */	addi r0, r3, __vt__8ActEnter@l
/* 800B7F88 000B4EE8  90 1F 00 00 */	stw r0, 0(r31)
/* 800B7F8C 000B4EEC  38 8D B5 88 */	addi r4, r13, lbl_803E02A8@sda21
/* 800B7F90 000B4EF0  38 00 FF FF */	li r0, -1
/* 800B7F94 000B4EF4  C0 02 91 B8 */	lfs f0, lbl_803E93B8@sda21(r2)
/* 800B7F98 000B4EF8  7F E3 FB 78 */	mr r3, r31
/* 800B7F9C 000B4EFC  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 800B7FA0 000B4F00  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 800B7FA4 000B4F04  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 800B7FA8 000B4F08  90 9F 00 10 */	stw r4, 0x10(r31)
/* 800B7FAC 000B4F0C  B0 1F 00 08 */	sth r0, 8(r31)
/* 800B7FB0 000B4F10  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B7FB4 000B4F14  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B7FB8 000B4F18  38 21 00 18 */	addi r1, r1, 0x18
/* 800B7FBC 000B4F1C  7C 08 03 A6 */	mtlr r0
/* 800B7FC0 000B4F20  4E 80 00 20 */	blr 
.endfn __ct__8ActEnterFP4Piki

.fn init__8ActEnterFP8Creature, global
/* 800B7FC4 000B4F24  7C 08 02 A6 */	mflr r0
/* 800B7FC8 000B4F28  28 04 00 00 */	cmplwi r4, 0
/* 800B7FCC 000B4F2C  90 01 00 04 */	stw r0, 4(r1)
/* 800B7FD0 000B4F30  38 00 00 00 */	li r0, 0
/* 800B7FD4 000B4F34  94 21 FF 98 */	stwu r1, -0x68(r1)
/* 800B7FD8 000B4F38  93 E1 00 64 */	stw r31, 0x64(r1)
/* 800B7FDC 000B4F3C  3B E3 00 00 */	addi r31, r3, 0
/* 800B7FE0 000B4F40  93 C1 00 60 */	stw r30, 0x60(r1)
/* 800B7FE4 000B4F44  98 03 00 2C */	stb r0, 0x2c(r3)
/* 800B7FE8 000B4F48  41 82 00 14 */	beq .L_800B7FFC
/* 800B7FEC 000B4F4C  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 800B7FF0 000B4F50  2C 00 00 10 */	cmpwi r0, 0x10
/* 800B7FF4 000B4F54  40 82 00 08 */	bne .L_800B7FFC
/* 800B7FF8 000B4F58  90 9F 00 18 */	stw r4, 0x18(r31)
.L_800B7FFC:
/* 800B7FFC 000B4F5C  7F E3 FB 78 */	mr r3, r31
/* 800B8000 000B4F60  48 00 01 B5 */	bl findLeg__8ActEnterFv
/* 800B8004 000B4F64  80 9F 00 18 */	lwz r4, 0x18(r31)
/* 800B8008 000B4F68  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B800C 000B4F6C  38 84 00 94 */	addi r4, r4, 0x94
/* 800B8010 000B4F70  C0 02 91 B8 */	lfs f0, lbl_803E93B8@sda21(r2)
/* 800B8014 000B4F74  38 63 00 94 */	addi r3, r3, 0x94
/* 800B8018 000B4F78  C0 84 00 04 */	lfs f4, 4(r4)
/* 800B801C 000B4F7C  C0 63 00 04 */	lfs f3, 4(r3)
/* 800B8020 000B4F80  C0 44 00 00 */	lfs f2, 0(r4)
/* 800B8024 000B4F84  C0 23 00 00 */	lfs f1, 0(r3)
/* 800B8028 000B4F88  EC 84 18 28 */	fsubs f4, f4, f3
/* 800B802C 000B4F8C  C0 64 00 08 */	lfs f3, 8(r4)
/* 800B8030 000B4F90  EC A2 08 28 */	fsubs f5, f2, f1
/* 800B8034 000B4F94  C0 43 00 08 */	lfs f2, 8(r3)
/* 800B8038 000B4F98  EC 24 01 32 */	fmuls f1, f4, f4
/* 800B803C 000B4F9C  EC 63 10 28 */	fsubs f3, f3, f2
/* 800B8040 000B4FA0  EC 45 01 72 */	fmuls f2, f5, f5
/* 800B8044 000B4FA4  EC 63 00 F2 */	fmuls f3, f3, f3
/* 800B8048 000B4FA8  EC 22 08 2A */	fadds f1, f2, f1
/* 800B804C 000B4FAC  EC 83 08 2A */	fadds f4, f3, f1
/* 800B8050 000B4FB0  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 800B8054 000B4FB4  40 81 00 5C */	ble .L_800B80B0
/* 800B8058 000B4FB8  FC 20 20 34 */	frsqrte f1, f4
/* 800B805C 000B4FBC  C8 62 91 C0 */	lfd f3, lbl_803E93C0@sda21(r2)
/* 800B8060 000B4FC0  C8 42 91 C8 */	lfd f2, lbl_803E93C8@sda21(r2)
/* 800B8064 000B4FC4  FC 01 00 72 */	fmul f0, f1, f1
/* 800B8068 000B4FC8  FC 23 00 72 */	fmul f1, f3, f1
/* 800B806C 000B4FCC  FC 04 00 32 */	fmul f0, f4, f0
/* 800B8070 000B4FD0  FC 02 00 28 */	fsub f0, f2, f0
/* 800B8074 000B4FD4  FC 21 00 32 */	fmul f1, f1, f0
/* 800B8078 000B4FD8  FC 01 00 72 */	fmul f0, f1, f1
/* 800B807C 000B4FDC  FC 23 00 72 */	fmul f1, f3, f1
/* 800B8080 000B4FE0  FC 04 00 32 */	fmul f0, f4, f0
/* 800B8084 000B4FE4  FC 02 00 28 */	fsub f0, f2, f0
/* 800B8088 000B4FE8  FC 21 00 32 */	fmul f1, f1, f0
/* 800B808C 000B4FEC  FC 01 00 72 */	fmul f0, f1, f1
/* 800B8090 000B4FF0  FC 23 00 72 */	fmul f1, f3, f1
/* 800B8094 000B4FF4  FC 04 00 32 */	fmul f0, f4, f0
/* 800B8098 000B4FF8  FC 02 00 28 */	fsub f0, f2, f0
/* 800B809C 000B4FFC  FC 01 00 32 */	fmul f0, f1, f0
/* 800B80A0 000B5000  FC 04 00 32 */	fmul f0, f4, f0
/* 800B80A4 000B5004  FC 00 00 18 */	frsp f0, f0
/* 800B80A8 000B5008  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 800B80AC 000B500C  C0 81 00 2C */	lfs f4, 0x2c(r1)
.L_800B80B0:
/* 800B80B0 000B5010  C0 02 91 D0 */	lfs f0, lbl_803E93D0@sda21(r2)
/* 800B80B4 000B5014  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 800B80B8 000B5018  40 81 00 48 */	ble .L_800B8100
/* 800B80BC 000B501C  38 00 00 00 */	li r0, 0
/* 800B80C0 000B5020  B0 1F 00 14 */	sth r0, 0x14(r31)
/* 800B80C4 000B5024  38 A0 00 00 */	li r5, 0
/* 800B80C8 000B5028  80 9F 00 18 */	lwz r4, 0x18(r31)
/* 800B80CC 000B502C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B80D0 000B5030  38 84 00 94 */	addi r4, r4, 0x94
/* 800B80D4 000B5034  48 00 EF 55 */	bl initRouteTrace__4PikiFR8Vector3fb
/* 800B80D8 000B5038  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B80DC 000B503C  40 82 00 40 */	bne .L_800B811C
/* 800B80E0 000B5040  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B80E4 000B5044  C0 22 91 D4 */	lfs f1, lbl_803E93D4@sda21(r2)
/* 800B80E8 000B5048  C0 42 91 D8 */	lfs f2, lbl_803E93D8@sda21(r2)
/* 800B80EC 000B504C  38 63 02 BC */	addi r3, r3, 0x2bc
/* 800B80F0 000B5050  48 01 57 25 */	bl start__8OdoMeterFff
/* 800B80F4 000B5054  38 00 00 01 */	li r0, 1
/* 800B80F8 000B5058  B0 1F 00 14 */	sth r0, 0x14(r31)
/* 800B80FC 000B505C  48 00 00 20 */	b .L_800B811C
.L_800B8100:
/* 800B8100 000B5060  38 00 00 01 */	li r0, 1
/* 800B8104 000B5064  B0 1F 00 14 */	sth r0, 0x14(r31)
/* 800B8108 000B5068  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B810C 000B506C  C0 22 91 D4 */	lfs f1, lbl_803E93D4@sda21(r2)
/* 800B8110 000B5070  C0 42 91 D8 */	lfs f2, lbl_803E93D8@sda21(r2)
/* 800B8114 000B5074  38 63 02 BC */	addi r3, r3, 0x2bc
/* 800B8118 000B5078  48 01 56 FD */	bl start__8OdoMeterFff
.L_800B811C:
/* 800B811C 000B507C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B8120 000B5080  48 00 FD 51 */	bl hasBomb__4PikiFv
/* 800B8124 000B5084  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B8128 000B5088  41 82 00 48 */	beq .L_800B8170
/* 800B812C 000B508C  3C 60 80 2B */	lis r3, __vt__11Interaction@ha
/* 800B8130 000B5090  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B8134 000B5094  38 03 CF 9C */	addi r0, r3, __vt__11Interaction@l
/* 800B8138 000B5098  C0 02 91 D4 */	lfs f0, lbl_803E93D4@sda21(r2)
/* 800B813C 000B509C  90 01 00 44 */	stw r0, 0x44(r1)
/* 800B8140 000B50A0  3C 60 80 2B */	lis r3, __vt__15InteractRelease@ha
/* 800B8144 000B50A4  38 03 D1 8C */	addi r0, r3, __vt__15InteractRelease@l
/* 800B8148 000B50A8  90 81 00 48 */	stw r4, 0x48(r1)
/* 800B814C 000B50AC  38 81 00 44 */	addi r4, r1, 0x44
/* 800B8150 000B50B0  90 01 00 44 */	stw r0, 0x44(r1)
/* 800B8154 000B50B4  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 800B8158 000B50B8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B815C 000B50BC  80 63 02 AC */	lwz r3, 0x2ac(r3)
/* 800B8160 000B50C0  81 83 00 00 */	lwz r12, 0(r3)
/* 800B8164 000B50C4  81 8C 00 A0 */	lwz r12, 0xa0(r12)
/* 800B8168 000B50C8  7D 88 03 A6 */	mtlr r12
/* 800B816C 000B50CC  4E 80 00 21 */	blrl 
.L_800B8170:
/* 800B8170 000B50D0  38 61 00 34 */	addi r3, r1, 0x34
/* 800B8174 000B50D4  38 80 00 02 */	li r4, 2
/* 800B8178 000B50D8  48 06 6D E1 */	bl __ct__14PaniMotionInfoFi
/* 800B817C 000B50DC  3B C3 00 00 */	addi r30, r3, 0
/* 800B8180 000B50E0  38 61 00 3C */	addi r3, r1, 0x3c
/* 800B8184 000B50E4  38 80 00 02 */	li r4, 2
/* 800B8188 000B50E8  48 06 6D D1 */	bl __ct__14PaniMotionInfoFi
/* 800B818C 000B50EC  7C 64 1B 78 */	mr r4, r3
/* 800B8190 000B50F0  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B8194 000B50F4  7F C5 F3 78 */	mr r5, r30
/* 800B8198 000B50F8  48 01 28 41 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800B819C 000B50FC  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 800B81A0 000B5100  83 E1 00 64 */	lwz r31, 0x64(r1)
/* 800B81A4 000B5104  83 C1 00 60 */	lwz r30, 0x60(r1)
/* 800B81A8 000B5108  38 21 00 68 */	addi r1, r1, 0x68
/* 800B81AC 000B510C  7C 08 03 A6 */	mtlr r0
/* 800B81B0 000B5110  4E 80 00 20 */	blr 
.endfn init__8ActEnterFP8Creature

.fn findLeg__8ActEnterFv, global
/* 800B81B4 000B5114  7C 08 02 A6 */	mflr r0
/* 800B81B8 000B5118  90 01 00 04 */	stw r0, 4(r1)
/* 800B81BC 000B511C  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800B81C0 000B5120  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800B81C4 000B5124  3F E0 62 61 */	lis r31, 0x62617331@ha
/* 800B81C8 000B5128  38 9F 73 31 */	addi r4, r31, 0x62617331@l
/* 800B81CC 000B512C  93 C1 00 30 */	stw r30, 0x30(r1)
/* 800B81D0 000B5130  7C 7E 1B 78 */	mr r30, r3
/* 800B81D4 000B5134  80 63 00 18 */	lwz r3, 0x18(r3)
/* 800B81D8 000B5138  80 63 02 20 */	lwz r3, 0x220(r3)
/* 800B81DC 000B513C  4B FD 15 35 */	bl getSphere__8CollInfoFUl
/* 800B81E0 000B5140  90 61 00 14 */	stw r3, 0x14(r1)
/* 800B81E4 000B5144  38 9F 73 32 */	addi r4, r31, 0x7332
/* 800B81E8 000B5148  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800B81EC 000B514C  80 63 02 20 */	lwz r3, 0x220(r3)
/* 800B81F0 000B5150  4B FD 15 21 */	bl getSphere__8CollInfoFUl
/* 800B81F4 000B5154  90 61 00 18 */	stw r3, 0x18(r1)
/* 800B81F8 000B5158  38 9F 73 33 */	addi r4, r31, 0x7333
/* 800B81FC 000B515C  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 800B8200 000B5160  80 63 02 20 */	lwz r3, 0x220(r3)
/* 800B8204 000B5164  4B FD 15 0D */	bl getSphere__8CollInfoFUl
/* 800B8208 000B5168  90 61 00 1C */	stw r3, 0x1c(r1)
/* 800B820C 000B516C  48 15 FE 65 */	bl rand
/* 800B8210 000B5170  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800B8214 000B5174  C8 82 91 E8 */	lfd f4, lbl_803E93E8@sda21(r2)
/* 800B8218 000B5178  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800B821C 000B517C  3C 00 43 30 */	lis r0, 0x4330
/* 800B8220 000B5180  C0 62 91 DC */	lfs f3, lbl_803E93DC@sda21(r2)
/* 800B8224 000B5184  38 61 00 14 */	addi r3, r1, 0x14
/* 800B8228 000B5188  90 01 00 28 */	stw r0, 0x28(r1)
/* 800B822C 000B518C  C0 42 91 D4 */	lfs f2, lbl_803E93D4@sda21(r2)
/* 800B8230 000B5190  C8 21 00 28 */	lfd f1, 0x28(r1)
/* 800B8234 000B5194  C0 02 91 E4 */	lfs f0, lbl_803E93E4@sda21(r2)
/* 800B8238 000B5198  EC 81 20 28 */	fsubs f4, f1, f4
/* 800B823C 000B519C  C0 22 91 E0 */	lfs f1, lbl_803E93E0@sda21(r2)
/* 800B8240 000B51A0  EC 64 18 24 */	fdivs f3, f4, f3
/* 800B8244 000B51A4  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800B8248 000B51A8  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800B824C 000B51AC  EC 01 00 32 */	fmuls f0, f1, f0
/* 800B8250 000B51B0  FC 00 00 1E */	fctiwz f0, f0
/* 800B8254 000B51B4  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 800B8258 000B51B8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800B825C 000B51BC  54 00 10 3A */	slwi r0, r0, 2
/* 800B8260 000B51C0  7C 03 00 2E */	lwzx r0, r3, r0
/* 800B8264 000B51C4  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 800B8268 000B51C8  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800B826C 000B51CC  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800B8270 000B51D0  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 800B8274 000B51D4  38 21 00 38 */	addi r1, r1, 0x38
/* 800B8278 000B51D8  7C 08 03 A6 */	mtlr r0
/* 800B827C 000B51DC  4E 80 00 20 */	blr 
.endfn findLeg__8ActEnterFv

.fn exec__8ActEnterFv, global
/* 800B8280 000B51E0  7C 08 02 A6 */	mflr r0
/* 800B8284 000B51E4  90 01 00 04 */	stw r0, 4(r1)
/* 800B8288 000B51E8  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800B828C 000B51EC  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800B8290 000B51F0  7C 7F 1B 78 */	mr r31, r3
/* 800B8294 000B51F4  A0 03 00 14 */	lhz r0, 0x14(r3)
/* 800B8298 000B51F8  28 00 00 02 */	cmplwi r0, 2
/* 800B829C 000B51FC  40 82 00 34 */	bne .L_800B82D0
/* 800B82A0 000B5200  88 0D 30 6C */	lbz r0, containerDebug__7PikiMgr@sda21(r13)
/* 800B82A4 000B5204  28 00 00 00 */	cmplwi r0, 0
/* 800B82A8 000B5208  41 82 00 28 */	beq .L_800B82D0
/* 800B82AC 000B520C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B82B0 000B5210  C0 02 91 F0 */	lfs f0, lbl_803E93F0@sda21(r2)
/* 800B82B4 000B5214  C0 23 00 94 */	lfs f1, 0x94(r3)
/* 800B82B8 000B5218  FC 20 0A 10 */	fabs f1, f1
/* 800B82BC 000B521C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B82C0 000B5220  41 81 00 10 */	bgt .L_800B82D0
/* 800B82C4 000B5224  C0 23 00 98 */	lfs f1, 0x98(r3)
/* 800B82C8 000B5228  FC 20 0A 10 */	fabs f1, f1
/* 800B82CC 000B522C  FC 01 00 40 */	fcmpo cr0, f1, f0
.L_800B82D0:
/* 800B82D0 000B5230  A0 1F 00 14 */	lhz r0, 0x14(r31)
/* 800B82D4 000B5234  2C 00 00 01 */	cmpwi r0, 1
/* 800B82D8 000B5238  41 82 00 60 */	beq .L_800B8338
/* 800B82DC 000B523C  40 80 00 10 */	bge .L_800B82EC
/* 800B82E0 000B5240  2C 00 00 00 */	cmpwi r0, 0
/* 800B82E4 000B5244  40 80 00 14 */	bge .L_800B82F8
/* 800B82E8 000B5248  48 00 00 68 */	b .L_800B8350
.L_800B82EC:
/* 800B82EC 000B524C  2C 00 00 03 */	cmpwi r0, 3
/* 800B82F0 000B5250  40 80 00 60 */	bge .L_800B8350
/* 800B82F4 000B5254  48 00 00 50 */	b .L_800B8344
.L_800B82F8:
/* 800B82F8 000B5258  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B82FC 000B525C  C0 22 91 D4 */	lfs f1, lbl_803E93D4@sda21(r2)
/* 800B8300 000B5260  48 00 F1 E9 */	bl moveRouteTrace__4PikiFf
/* 800B8304 000B5264  2C 03 00 00 */	cmpwi r3, 0
/* 800B8308 000B5268  40 82 00 28 */	bne .L_800B8330
/* 800B830C 000B526C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B8310 000B5270  C0 22 91 D4 */	lfs f1, lbl_803E93D4@sda21(r2)
/* 800B8314 000B5274  C0 42 91 D8 */	lfs f2, lbl_803E93D8@sda21(r2)
/* 800B8318 000B5278  38 63 02 BC */	addi r3, r3, 0x2bc
/* 800B831C 000B527C  48 01 54 F9 */	bl start__8OdoMeterFff
/* 800B8320 000B5280  38 00 00 01 */	li r0, 1
/* 800B8324 000B5284  B0 1F 00 14 */	sth r0, 0x14(r31)
/* 800B8328 000B5288  38 60 00 00 */	li r3, 0
/* 800B832C 000B528C  48 00 00 28 */	b .L_800B8354
.L_800B8330:
/* 800B8330 000B5290  38 60 00 00 */	li r3, 0
/* 800B8334 000B5294  48 00 00 20 */	b .L_800B8354
.L_800B8338:
/* 800B8338 000B5298  7F E3 FB 78 */	mr r3, r31
/* 800B833C 000B529C  48 00 00 85 */	bl gotoLeg__8ActEnterFv
/* 800B8340 000B52A0  48 00 00 14 */	b .L_800B8354
.L_800B8344:
/* 800B8344 000B52A4  7F E3 FB 78 */	mr r3, r31
/* 800B8348 000B52A8  48 00 02 25 */	bl climb__8ActEnterFv
/* 800B834C 000B52AC  48 00 00 08 */	b .L_800B8354
.L_800B8350:
/* 800B8350 000B52B0  38 60 00 00 */	li r3, 0
.L_800B8354:
/* 800B8354 000B52B4  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800B8358 000B52B8  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800B835C 000B52BC  38 21 00 28 */	addi r1, r1, 0x28
/* 800B8360 000B52C0  7C 08 03 A6 */	mtlr r0
/* 800B8364 000B52C4  4E 80 00 20 */	blr 
.endfn exec__8ActEnterFv

.fn procCollideMsg__8ActEnterFP4PikiP10MsgCollide, global
/* 800B8368 000B52C8  7C 08 02 A6 */	mflr r0
/* 800B836C 000B52CC  90 01 00 04 */	stw r0, 4(r1)
/* 800B8370 000B52D0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800B8374 000B52D4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800B8378 000B52D8  7C 7F 1B 78 */	mr r31, r3
/* 800B837C 000B52DC  80 85 00 04 */	lwz r4, 4(r5)
/* 800B8380 000B52E0  80 64 00 6C */	lwz r3, 0x6c(r4)
/* 800B8384 000B52E4  2C 03 00 34 */	cmpwi r3, 0x34
/* 800B8388 000B52E8  40 82 00 24 */	bne .L_800B83AC
/* 800B838C 000B52EC  A0 1F 00 14 */	lhz r0, 0x14(r31)
/* 800B8390 000B52F0  28 00 00 01 */	cmplwi r0, 1
/* 800B8394 000B52F4  41 82 00 0C */	beq .L_800B83A0
/* 800B8398 000B52F8  28 00 00 02 */	cmplwi r0, 2
/* 800B839C 000B52FC  40 82 00 10 */	bne .L_800B83AC
.L_800B83A0:
/* 800B83A0 000B5300  4B FD C6 99 */	bl getName__7ObjTypeFi
/* 800B83A4 000B5304  38 00 00 01 */	li r0, 1
/* 800B83A8 000B5308  98 1F 00 2C */	stb r0, 0x2c(r31)
.L_800B83AC:
/* 800B83AC 000B530C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800B83B0 000B5310  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800B83B4 000B5314  38 21 00 20 */	addi r1, r1, 0x20
/* 800B83B8 000B5318  7C 08 03 A6 */	mtlr r0
/* 800B83BC 000B531C  4E 80 00 20 */	blr 
.endfn procCollideMsg__8ActEnterFP4PikiP10MsgCollide

.fn gotoLeg__8ActEnterFv, global
/* 800B83C0 000B5320  7C 08 02 A6 */	mflr r0
/* 800B83C4 000B5324  90 01 00 04 */	stw r0, 4(r1)
/* 800B83C8 000B5328  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 800B83CC 000B532C  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 800B83D0 000B5330  7C 7F 1B 78 */	mr r31, r3
/* 800B83D4 000B5334  93 C1 00 58 */	stw r30, 0x58(r1)
/* 800B83D8 000B5338  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800B83DC 000B533C  80 04 01 58 */	lwz r0, 0x158(r4)
/* 800B83E0 000B5340  28 00 00 00 */	cmplwi r0, 0
/* 800B83E4 000B5344  41 82 00 88 */	beq .L_800B846C
/* 800B83E8 000B5348  38 00 00 02 */	li r0, 2
/* 800B83EC 000B534C  B0 1F 00 14 */	sth r0, 0x14(r31)
/* 800B83F0 000B5350  38 A0 00 D9 */	li r5, 0xd9
/* 800B83F4 000B5354  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B83F8 000B5358  80 9F 00 18 */	lwz r4, 0x18(r31)
/* 800B83FC 000B535C  4B FD 21 B9 */	bl playEventSound__8CreatureFP8Creaturei
/* 800B8400 000B5360  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800B8404 000B5364  38 61 00 34 */	addi r3, r1, 0x34
/* 800B8408 000B5368  C0 0D B5 90 */	lfs f0, lbl_803E02B0@sda21(r13)
/* 800B840C 000B536C  38 80 00 3E */	li r4, 0x3e
/* 800B8410 000B5370  D4 05 00 70 */	stfsu f0, 0x70(r5)
/* 800B8414 000B5374  C0 0D B5 94 */	lfs f0, lbl_803E02B4@sda21(r13)
/* 800B8418 000B5378  D0 05 00 04 */	stfs f0, 4(r5)
/* 800B841C 000B537C  C0 0D B5 98 */	lfs f0, lbl_803E02B8@sda21(r13)
/* 800B8420 000B5380  D0 05 00 08 */	stfs f0, 8(r5)
/* 800B8424 000B5384  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800B8428 000B5388  C0 0D B5 9C */	lfs f0, lbl_803E02BC@sda21(r13)
/* 800B842C 000B538C  D4 05 00 A4 */	stfsu f0, 0xa4(r5)
/* 800B8430 000B5390  C0 0D B5 A0 */	lfs f0, lbl_803E02C0@sda21(r13)
/* 800B8434 000B5394  D0 05 00 04 */	stfs f0, 4(r5)
/* 800B8438 000B5398  C0 0D B5 A4 */	lfs f0, lbl_803E02C4@sda21(r13)
/* 800B843C 000B539C  D0 05 00 08 */	stfs f0, 8(r5)
/* 800B8440 000B53A0  48 06 6B 19 */	bl __ct__14PaniMotionInfoFi
/* 800B8444 000B53A4  3B C3 00 00 */	addi r30, r3, 0
/* 800B8448 000B53A8  38 61 00 3C */	addi r3, r1, 0x3c
/* 800B844C 000B53AC  38 80 00 3E */	li r4, 0x3e
/* 800B8450 000B53B0  48 06 6B 09 */	bl __ct__14PaniMotionInfoFi
/* 800B8454 000B53B4  7C 64 1B 78 */	mr r4, r3
/* 800B8458 000B53B8  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B845C 000B53BC  7F C5 F3 78 */	mr r5, r30
/* 800B8460 000B53C0  48 01 25 79 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800B8464 000B53C4  38 60 00 00 */	li r3, 0
/* 800B8468 000B53C8  48 00 00 EC */	b .L_800B8554
.L_800B846C:
/* 800B846C 000B53CC  88 1F 00 2C */	lbz r0, 0x2c(r31)
/* 800B8470 000B53D0  28 00 00 00 */	cmplwi r0, 0
/* 800B8474 000B53D4  41 82 00 24 */	beq .L_800B8498
/* 800B8478 000B53D8  38 64 02 BC */	addi r3, r4, 0x2bc
/* 800B847C 000B53DC  38 84 00 94 */	addi r4, r4, 0x94
/* 800B8480 000B53E0  38 BF 00 20 */	addi r5, r31, 0x20
/* 800B8484 000B53E4  48 01 53 A9 */	bl moving__8OdoMeterFR8Vector3fR8Vector3f
/* 800B8488 000B53E8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800B848C 000B53EC  40 82 00 0C */	bne .L_800B8498
/* 800B8490 000B53F0  38 60 00 01 */	li r3, 1
/* 800B8494 000B53F4  48 00 00 C0 */	b .L_800B8554
.L_800B8498:
/* 800B8498 000B53F8  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B849C 000B53FC  80 64 00 94 */	lwz r3, 0x94(r4)
/* 800B84A0 000B5400  80 04 00 98 */	lwz r0, 0x98(r4)
/* 800B84A4 000B5404  90 7F 00 20 */	stw r3, 0x20(r31)
/* 800B84A8 000B5408  90 1F 00 24 */	stw r0, 0x24(r31)
/* 800B84AC 000B540C  80 04 00 9C */	lwz r0, 0x9c(r4)
/* 800B84B0 000B5410  90 1F 00 28 */	stw r0, 0x28(r31)
/* 800B84B4 000B5414  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B84B8 000B5418  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 800B84BC 000B541C  C4 23 00 04 */	lfsu f1, 4(r3)
/* 800B84C0 000B5420  C4 04 00 94 */	lfsu f0, 0x94(r4)
/* 800B84C4 000B5424  C0 63 00 04 */	lfs f3, 4(r3)
/* 800B84C8 000B5428  C0 44 00 04 */	lfs f2, 4(r4)
/* 800B84CC 000B542C  EC 01 00 28 */	fsubs f0, f1, f0
/* 800B84D0 000B5430  C0 83 00 08 */	lfs f4, 8(r3)
/* 800B84D4 000B5434  C0 24 00 08 */	lfs f1, 8(r4)
/* 800B84D8 000B5438  EC 43 10 28 */	fsubs f2, f3, f2
/* 800B84DC 000B543C  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 800B84E0 000B5440  EC 04 08 28 */	fsubs f0, f4, f1
/* 800B84E4 000B5444  D0 41 00 4C */	stfs f2, 0x4c(r1)
/* 800B84E8 000B5448  D0 01 00 50 */	stfs f0, 0x50(r1)
/* 800B84EC 000B544C  C0 21 00 48 */	lfs f1, 0x48(r1)
/* 800B84F0 000B5450  C0 01 00 4C */	lfs f0, 0x4c(r1)
/* 800B84F4 000B5454  C0 41 00 50 */	lfs f2, 0x50(r1)
/* 800B84F8 000B5458  EC 21 00 72 */	fmuls f1, f1, f1
/* 800B84FC 000B545C  EC 00 00 32 */	fmuls f0, f0, f0
/* 800B8500 000B5460  EC 42 00 B2 */	fmuls f2, f2, f2
/* 800B8504 000B5464  EC 01 00 2A */	fadds f0, f1, f0
/* 800B8508 000B5468  EC 22 00 2A */	fadds f1, f2, f0
/* 800B850C 000B546C  4B F5 57 35 */	bl sqrtf__3stdFf
/* 800B8510 000B5470  C0 02 91 B8 */	lfs f0, lbl_803E93B8@sda21(r2)
/* 800B8514 000B5474  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800B8518 000B5478  41 82 00 28 */	beq .L_800B8540
/* 800B851C 000B547C  C0 01 00 48 */	lfs f0, 0x48(r1)
/* 800B8520 000B5480  EC 00 08 24 */	fdivs f0, f0, f1
/* 800B8524 000B5484  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 800B8528 000B5488  C0 01 00 4C */	lfs f0, 0x4c(r1)
/* 800B852C 000B548C  EC 00 08 24 */	fdivs f0, f0, f1
/* 800B8530 000B5490  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 800B8534 000B5494  C0 01 00 50 */	lfs f0, 0x50(r1)
/* 800B8538 000B5498  EC 00 08 24 */	fdivs f0, f0, f1
/* 800B853C 000B549C  D0 01 00 50 */	stfs f0, 0x50(r1)
.L_800B8540:
/* 800B8540 000B54A0  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B8544 000B54A4  38 81 00 48 */	addi r4, r1, 0x48
/* 800B8548 000B54A8  C0 22 91 F4 */	lfs f1, lbl_803E93F4@sda21(r2)
/* 800B854C 000B54AC  48 01 38 8D */	bl setSpeed__4PikiFfR8Vector3f
/* 800B8550 000B54B0  38 60 00 00 */	li r3, 0
.L_800B8554:
/* 800B8554 000B54B4  80 01 00 64 */	lwz r0, 0x64(r1)
/* 800B8558 000B54B8  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 800B855C 000B54BC  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 800B8560 000B54C0  38 21 00 60 */	addi r1, r1, 0x60
/* 800B8564 000B54C4  7C 08 03 A6 */	mtlr r0
/* 800B8568 000B54C8  4E 80 00 20 */	blr 
.endfn gotoLeg__8ActEnterFv

.fn climb__8ActEnterFv, global
/* 800B856C 000B54CC  7C 08 02 A6 */	mflr r0
/* 800B8570 000B54D0  90 01 00 04 */	stw r0, 4(r1)
/* 800B8574 000B54D4  94 21 FE D8 */	stwu r1, -0x128(r1)
/* 800B8578 000B54D8  DB E1 01 20 */	stfd f31, 0x120(r1)
/* 800B857C 000B54DC  DB C1 01 18 */	stfd f30, 0x118(r1)
/* 800B8580 000B54E0  DB A1 01 10 */	stfd f29, 0x110(r1)
/* 800B8584 000B54E4  DB 81 01 08 */	stfd f28, 0x108(r1)
/* 800B8588 000B54E8  DB 61 01 00 */	stfd f27, 0x100(r1)
/* 800B858C 000B54EC  DB 41 00 F8 */	stfd f26, 0xf8(r1)
/* 800B8590 000B54F0  DB 21 00 F0 */	stfd f25, 0xf0(r1)
/* 800B8594 000B54F4  93 E1 00 EC */	stw r31, 0xec(r1)
/* 800B8598 000B54F8  7C 7F 1B 78 */	mr r31, r3
/* 800B859C 000B54FC  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800B85A0 000B5500  80 04 01 58 */	lwz r0, 0x158(r4)
/* 800B85A4 000B5504  28 00 00 00 */	cmplwi r0, 0
/* 800B85A8 000B5508  41 82 00 14 */	beq .L_800B85BC
/* 800B85AC 000B550C  C0 24 01 5C */	lfs f1, 0x15c(r4)
/* 800B85B0 000B5510  C0 02 91 F8 */	lfs f0, lbl_803E93F8@sda21(r2)
/* 800B85B4 000B5514  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B85B8 000B5518  40 81 00 14 */	ble .L_800B85CC
.L_800B85BC:
/* 800B85BC 000B551C  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800B85C0 000B5520  48 03 2C 99 */	bl enterGoal__8GoalItemFP4Piki
/* 800B85C4 000B5524  38 60 00 01 */	li r3, 1
/* 800B85C8 000B5528  48 00 01 A8 */	b .L_800B8770
.L_800B85CC:
/* 800B85CC 000B552C  88 1F 00 2C */	lbz r0, 0x2c(r31)
/* 800B85D0 000B5530  28 00 00 00 */	cmplwi r0, 0
/* 800B85D4 000B5534  41 82 00 0C */	beq .L_800B85E0
/* 800B85D8 000B5538  38 60 00 01 */	li r3, 1
/* 800B85DC 000B553C  48 00 01 94 */	b .L_800B8770
.L_800B85E0:
/* 800B85E0 000B5540  C0 02 91 FC */	lfs f0, lbl_803E93FC@sda21(r2)
/* 800B85E4 000B5544  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B85E8 000B5548  40 81 00 40 */	ble .L_800B8628
/* 800B85EC 000B554C  38 00 00 00 */	li r0, 0
/* 800B85F0 000B5550  98 04 04 09 */	stb r0, 0x409(r4)
/* 800B85F4 000B5554  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B85F8 000B5558  C0 42 91 D4 */	lfs f2, lbl_803E93D4@sda21(r2)
/* 800B85FC 000B555C  C0 03 01 5C */	lfs f0, 0x15c(r3)
/* 800B8600 000B5560  C0 22 92 00 */	lfs f1, lbl_803E9400@sda21(r2)
/* 800B8604 000B5564  EC 42 00 28 */	fsubs f2, f2, f0
/* 800B8608 000B5568  C0 02 91 B8 */	lfs f0, lbl_803E93B8@sda21(r2)
/* 800B860C 000B556C  EC 22 08 24 */	fdivs f1, f2, f1
/* 800B8610 000B5570  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800B8614 000B5574  40 80 00 08 */	bge .L_800B861C
/* 800B8618 000B5578  FC 20 00 90 */	fmr f1, f0
.L_800B861C:
/* 800B861C 000B557C  D4 23 00 7C */	stfsu f1, 0x7c(r3)
/* 800B8620 000B5580  D0 23 00 04 */	stfs f1, 4(r3)
/* 800B8624 000B5584  D0 23 00 08 */	stfs f1, 8(r3)
.L_800B8628:
/* 800B8628 000B5588  48 15 FA 49 */	bl rand
/* 800B862C 000B558C  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800B8630 000B5590  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800B8634 000B5594  90 01 00 E4 */	stw r0, 0xe4(r1)
/* 800B8638 000B5598  3C 00 43 30 */	lis r0, 0x4330
/* 800B863C 000B559C  80 64 01 58 */	lwz r3, 0x158(r4)
/* 800B8640 000B55A0  90 01 00 E0 */	stw r0, 0xe0(r1)
/* 800B8644 000B55A4  C7 E3 02 C4 */	lfsu f31, 0x2c4(r3)
/* 800B8648 000B55A8  C8 42 91 E8 */	lfd f2, lbl_803E93E8@sda21(r2)
/* 800B864C 000B55AC  C8 01 00 E0 */	lfd f0, 0xe0(r1)
/* 800B8650 000B55B0  C0 22 91 DC */	lfs f1, lbl_803E93DC@sda21(r2)
/* 800B8654 000B55B4  EC 80 10 28 */	fsubs f4, f0, f2
/* 800B8658 000B55B8  C0 62 91 D4 */	lfs f3, lbl_803E93D4@sda21(r2)
/* 800B865C 000B55BC  C0 02 91 F4 */	lfs f0, lbl_803E93F4@sda21(r2)
/* 800B8660 000B55C0  C0 42 92 04 */	lfs f2, lbl_803E9404@sda21(r2)
/* 800B8664 000B55C4  EC 84 08 24 */	fdivs f4, f4, f1
/* 800B8668 000B55C8  C3 C3 00 04 */	lfs f30, 4(r3)
/* 800B866C 000B55CC  C3 A3 00 08 */	lfs f29, 8(r3)
/* 800B8670 000B55D0  C0 24 00 A0 */	lfs f1, 0xa0(r4)
/* 800B8674 000B55D4  EC 63 01 32 */	fmuls f3, f3, f4
/* 800B8678 000B55D8  EC 03 00 28 */	fsubs f0, f3, f0
/* 800B867C 000B55DC  EF 82 00 32 */	fmuls f28, f2, f0
/* 800B8680 000B55E0  48 16 34 D5 */	bl cosf
/* 800B8684 000B55E4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 800B8688 000B55E8  FF 60 08 90 */	fmr f27, f1
/* 800B868C 000B55EC  C0 23 00 A0 */	lfs f1, 0xa0(r3)
/* 800B8690 000B55F0  48 16 36 59 */	bl sinf
/* 800B8694 000B55F4  C0 CD B5 A8 */	lfs f6, lbl_803E02C8@sda21(r13)
/* 800B8698 000B55F8  EC 9B 07 B2 */	fmuls f4, f27, f30
/* 800B869C 000B55FC  EC 5B 07 F2 */	fmuls f2, f27, f31
/* 800B86A0 000B5600  EC A6 07 72 */	fmuls f5, f6, f29
/* 800B86A4 000B5604  EC 01 07 72 */	fmuls f0, f1, f29
/* 800B86A8 000B5608  EC 61 07 B2 */	fmuls f3, f1, f30
/* 800B86AC 000B560C  EF 65 20 28 */	fsubs f27, f5, f4
/* 800B86B0 000B5610  EF 42 00 28 */	fsubs f26, f2, f0
/* 800B86B4 000B5614  EC 46 07 F2 */	fmuls f2, f6, f31
/* 800B86B8 000B5618  EC 3B 06 F2 */	fmuls f1, f27, f27
/* 800B86BC 000B561C  EC 1A 06 B2 */	fmuls f0, f26, f26
/* 800B86C0 000B5620  EF 23 10 28 */	fsubs f25, f3, f2
/* 800B86C4 000B5624  EC 01 00 2A */	fadds f0, f1, f0
/* 800B86C8 000B5628  EC 39 06 72 */	fmuls f1, f25, f25
/* 800B86CC 000B562C  EC 21 00 2A */	fadds f1, f1, f0
/* 800B86D0 000B5630  4B F5 55 71 */	bl sqrtf__3stdFf
/* 800B86D4 000B5634  C0 02 91 B8 */	lfs f0, lbl_803E93B8@sda21(r2)
/* 800B86D8 000B5638  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800B86DC 000B563C  41 82 00 10 */	beq .L_800B86EC
/* 800B86E0 000B5640  EF 7B 08 24 */	fdivs f27, f27, f1
/* 800B86E4 000B5644  EF 5A 08 24 */	fdivs f26, f26, f1
/* 800B86E8 000B5648  EF 39 08 24 */	fdivs f25, f25, f1
.L_800B86EC:
/* 800B86EC 000B564C  C0 42 92 08 */	lfs f2, lbl_803E9408@sda21(r2)
/* 800B86F0 000B5650  EC 9B 07 32 */	fmuls f4, f27, f28
/* 800B86F4 000B5654  EC 3A 07 32 */	fmuls f1, f26, f28
/* 800B86F8 000B5658  38 60 00 00 */	li r3, 0
/* 800B86FC 000B565C  EC 1F 00 B2 */	fmuls f0, f31, f2
/* 800B8700 000B5660  EC 7E 00 B2 */	fmuls f3, f30, f2
/* 800B8704 000B5664  D0 81 00 68 */	stfs f4, 0x68(r1)
/* 800B8708 000B5668  EC 5D 00 B2 */	fmuls f2, f29, f2
/* 800B870C 000B566C  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 800B8710 000B5670  EC 19 07 32 */	fmuls f0, f25, f28
/* 800B8714 000B5674  C0 81 00 74 */	lfs f4, 0x74(r1)
/* 800B8718 000B5678  D0 81 00 9C */	stfs f4, 0x9c(r1)
/* 800B871C 000B567C  D0 61 00 A0 */	stfs f3, 0xa0(r1)
/* 800B8720 000B5680  D0 41 00 A4 */	stfs f2, 0xa4(r1)
/* 800B8724 000B5684  C0 61 00 9C */	lfs f3, 0x9c(r1)
/* 800B8728 000B5688  C0 41 00 68 */	lfs f2, 0x68(r1)
/* 800B872C 000B568C  EC 43 10 2A */	fadds f2, f3, f2
/* 800B8730 000B5690  D0 41 00 5C */	stfs f2, 0x5c(r1)
/* 800B8734 000B5694  C0 41 00 5C */	lfs f2, 0x5c(r1)
/* 800B8738 000B5698  D0 41 00 A8 */	stfs f2, 0xa8(r1)
/* 800B873C 000B569C  C0 41 00 A0 */	lfs f2, 0xa0(r1)
/* 800B8740 000B56A0  EC 22 08 2A */	fadds f1, f2, f1
/* 800B8744 000B56A4  D0 21 00 AC */	stfs f1, 0xac(r1)
/* 800B8748 000B56A8  C0 21 00 A4 */	lfs f1, 0xa4(r1)
/* 800B874C 000B56AC  EC 01 00 2A */	fadds f0, f1, f0
/* 800B8750 000B56B0  D0 01 00 B0 */	stfs f0, 0xb0(r1)
/* 800B8754 000B56B4  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 800B8758 000B56B8  80 81 00 A8 */	lwz r4, 0xa8(r1)
/* 800B875C 000B56BC  80 01 00 AC */	lwz r0, 0xac(r1)
/* 800B8760 000B56C0  90 85 00 70 */	stw r4, 0x70(r5)
/* 800B8764 000B56C4  90 05 00 74 */	stw r0, 0x74(r5)
/* 800B8768 000B56C8  80 01 00 B0 */	lwz r0, 0xb0(r1)
/* 800B876C 000B56CC  90 05 00 78 */	stw r0, 0x78(r5)
.L_800B8770:
/* 800B8770 000B56D0  80 01 01 2C */	lwz r0, 0x12c(r1)
/* 800B8774 000B56D4  CB E1 01 20 */	lfd f31, 0x120(r1)
/* 800B8778 000B56D8  CB C1 01 18 */	lfd f30, 0x118(r1)
/* 800B877C 000B56DC  CB A1 01 10 */	lfd f29, 0x110(r1)
/* 800B8780 000B56E0  CB 81 01 08 */	lfd f28, 0x108(r1)
/* 800B8784 000B56E4  CB 61 01 00 */	lfd f27, 0x100(r1)
/* 800B8788 000B56E8  CB 41 00 F8 */	lfd f26, 0xf8(r1)
/* 800B878C 000B56EC  CB 21 00 F0 */	lfd f25, 0xf0(r1)
/* 800B8790 000B56F0  83 E1 00 EC */	lwz r31, 0xec(r1)
/* 800B8794 000B56F4  38 21 01 28 */	addi r1, r1, 0x128
/* 800B8798 000B56F8  7C 08 03 A6 */	mtlr r0
/* 800B879C 000B56FC  4E 80 00 20 */	blr 
.endfn climb__8ActEnterFv

.fn cleanup__8ActEnterFv, global
/* 800B87A0 000B5700  7C 08 02 A6 */	mflr r0
/* 800B87A4 000B5704  90 01 00 04 */	stw r0, 4(r1)
/* 800B87A8 000B5708  94 21 FF F8 */	stwu r1, -8(r1)
/* 800B87AC 000B570C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800B87B0 000B5710  4B FD 84 3D */	bl endRope__8CreatureFv
/* 800B87B4 000B5714  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800B87B8 000B5718  38 21 00 08 */	addi r1, r1, 8
/* 800B87BC 000B571C  7C 08 03 A6 */	mtlr r0
/* 800B87C0 000B5720  4E 80 00 20 */	blr 
.endfn cleanup__8ActEnterFv

.fn __dt__8ActEnterFv, weak
/* 800B87C4 000B5724  7C 08 02 A6 */	mflr r0
/* 800B87C8 000B5728  90 01 00 04 */	stw r0, 4(r1)
/* 800B87CC 000B572C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800B87D0 000B5730  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800B87D4 000B5734  3B E4 00 00 */	addi r31, r4, 0
/* 800B87D8 000B5738  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800B87DC 000B573C  7C 7E 1B 79 */	or. r30, r3, r3
/* 800B87E0 000B5740  41 82 00 2C */	beq .L_800B880C
/* 800B87E4 000B5744  3C 60 80 2B */	lis r3, __vt__8ActEnter@ha
/* 800B87E8 000B5748  38 03 65 58 */	addi r0, r3, __vt__8ActEnter@l
/* 800B87EC 000B574C  90 1E 00 00 */	stw r0, 0(r30)
/* 800B87F0 000B5750  38 7E 00 00 */	addi r3, r30, 0
/* 800B87F4 000B5754  38 80 00 00 */	li r4, 0
/* 800B87F8 000B5758  48 00 B6 11 */	bl __dt__6ActionFv
/* 800B87FC 000B575C  7F E0 07 35 */	extsh. r0, r31
/* 800B8800 000B5760  40 81 00 0C */	ble .L_800B880C
/* 800B8804 000B5764  7F C3 F3 78 */	mr r3, r30
/* 800B8808 000B5768  4B F8 E9 A5 */	bl __dl__FPv
.L_800B880C:
/* 800B880C 000B576C  7F C3 F3 78 */	mr r3, r30
/* 800B8810 000B5770  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800B8814 000B5774  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800B8818 000B5778  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800B881C 000B577C  38 21 00 18 */	addi r1, r1, 0x18
/* 800B8820 000B5780  7C 08 03 A6 */	mtlr r0
/* 800B8824 000B5784  4E 80 00 20 */	blr 
.endfn __dt__8ActEnterFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B64D8, local
	.asciz "aiEnter.cpp"
.endobj lbl_802B64D8
.balign 4
.obj lbl_802B64E4, local
	.asciz "Interaction"
.endobj lbl_802B64E4
.balign 4
.skip 0x2C # compiler padding
.balign 4
.obj lbl_802B651C, local
	.asciz "ActEnter"
.endobj lbl_802B651C
.balign 4
.obj lbl_802B6528, local
	.asciz "Receiver<Piki>"
.endobj lbl_802B6528
.balign 4
.obj lbl_802B6538, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
.endobj lbl_802B6538
.balign 4
.obj lbl_802B6544, local
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.endobj lbl_802B6544
.balign 4
.obj __vt__8ActEnter, global
	.4byte __RTTI__8ActEnter
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte procCollideMsg__8ActEnterFP4PikiP10MsgCollide
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__6ActionFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__8ActEnterFv
	.4byte init__8ActEnterFP8Creature
	.4byte exec__8ActEnterFv
	.4byte cleanup__8ActEnterFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
.endobj __vt__8ActEnter
.balign 4
.obj lbl_802B65BC, local
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
.endobj lbl_802B65BC

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E02A8, local
	.asciz "Enter"
.endobj lbl_803E02A8
.balign 4
.obj lbl_803E02B0, local
	.float 0.0
.endobj lbl_803E02B0
.obj lbl_803E02B4, local
	.float 0.0
.endobj lbl_803E02B4
.obj lbl_803E02B8, local
	.float 0.0
.endobj lbl_803E02B8
.obj lbl_803E02BC, local
	.float 0.0
.endobj lbl_803E02BC
.obj lbl_803E02C0, local
	.float 0.0
.endobj lbl_803E02C0
.obj lbl_803E02C4, local
	.float 0.0
.endobj lbl_803E02C4
.obj lbl_803E02C8, local
	.float 0.0
.endobj lbl_803E02C8
.balign 4
.obj "__RTTI__15Receiver<4Piki>", local
	.4byte lbl_802B6528
	.4byte 0
.endobj "__RTTI__15Receiver<4Piki>"
.balign 4
.obj lbl_803E02D4, local
	.asciz "Action"
.endobj lbl_803E02D4
.balign 4
.obj __RTTI__6Action, local
	.4byte lbl_803E02D4
	.4byte lbl_802B6538
.endobj __RTTI__6Action
.balign 4
.obj __RTTI__8ActEnter, local
	.4byte lbl_802B651C
	.4byte lbl_802B6544
.endobj __RTTI__8ActEnter

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E93B8, local
	.float 0.0
.endobj lbl_803E93B8
.balign 8
.obj lbl_803E93C0, local
	.double 0.5
.endobj lbl_803E93C0
.balign 8
.obj lbl_803E93C8, local
	.double 3.0
.endobj lbl_803E93C8
.obj lbl_803E93D0, local
	.float 400.0
.endobj lbl_803E93D0
.obj lbl_803E93D4, local
	.float 1.0
.endobj lbl_803E93D4
.obj lbl_803E93D8, local
	.float 5.0
.endobj lbl_803E93D8
.obj lbl_803E93DC, local
	.float 32767.0
.endobj lbl_803E93DC
.obj lbl_803E93E0, local
	.float 3.0
.endobj lbl_803E93E0
.obj lbl_803E93E4, local
	.float 0.9999999
.endobj lbl_803E93E4
.balign 8
.obj lbl_803E93E8, local
	.8byte 0x4330000080000000
.endobj lbl_803E93E8
.obj lbl_803E93F0, local
	.float 10000.0
.endobj lbl_803E93F0
.obj lbl_803E93F4, local
	.float 0.5
.endobj lbl_803E93F4
.obj lbl_803E93F8, local
	.float 0.9
.endobj lbl_803E93F8
.obj lbl_803E93FC, local
	.float 0.72
.endobj lbl_803E93FC
.obj lbl_803E9400, local
	.float 0.27999997
.endobj lbl_803E9400
.obj lbl_803E9404, local
	.float 8.0
.endobj lbl_803E9404
.obj lbl_803E9408, local
	.float 15.0
.endobj lbl_803E9408
