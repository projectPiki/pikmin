.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800EAF40 000E7EA0  38 63 00 14 */	addi r3, r3, 0x14
/* 800EAF44 000E7EA4  48 0B 66 81 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 800EAF48 000E7EA8  38 00 00 00 */	li r0, 0
/* 800EAF4C 000E7EAC  90 1E 03 E8 */	stw r0, 0x3e8(r30)
lbl_800EAF50:
/* 800EAF50 000E7EB0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800EAF54 000E7EB4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800EAF58 000E7EB8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800EAF5C 000E7EBC  38 21 00 20 */	addi r1, r1, 0x20
/* 800EAF60 000E7EC0  7C 08 03 A6 */	mtlr r0
/* 800EAF64 000E7EC4  4E 80 00 20 */	blr 

.global setSpotActive__8GoalItemFb
setSpotActive__8GoalItemFb:
/* 800EAF68 000E7EC8  7C 08 02 A6 */	mflr r0
/* 800EAF6C 000E7ECC  90 01 00 04 */	stw r0, 4(r1)
/* 800EAF70 000E7ED0  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800EAF74 000E7ED4  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800EAF78 000E7ED8  7C 7F 1B 78 */	mr r31, r3
/* 800EAF7C 000E7EDC  98 83 03 D9 */	stb r4, 0x3d9(r3)
/* 800EAF80 000E7EE0  88 03 03 D9 */	lbz r0, 0x3d9(r3)
/* 800EAF84 000E7EE4  28 00 00 00 */	cmplwi r0, 0
/* 800EAF88 000E7EE8  41 82 00 78 */	beq lbl_800EB000
/* 800EAF8C 000E7EEC  3C 60 80 22 */	lis r3, lbl_8022264C@ha
/* 800EAF90 000E7EF0  38 83 26 4C */	addi r4, r3, lbl_8022264C@l
/* 800EAF94 000E7EF4  80 64 00 00 */	lwz r3, 0(r4)
/* 800EAF98 000E7EF8  80 04 00 04 */	lwz r0, 4(r4)
/* 800EAF9C 000E7EFC  90 61 00 24 */	stw r3, 0x24(r1)
/* 800EAFA0 000E7F00  90 01 00 28 */	stw r0, 0x28(r1)
/* 800EAFA4 000E7F04  80 04 00 08 */	lwz r0, 8(r4)
/* 800EAFA8 000E7F08  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800EAFAC 000E7F0C  80 1F 03 DC */	lwz r0, 0x3dc(r31)
/* 800EAFB0 000E7F10  28 00 00 00 */	cmplwi r0, 0
/* 800EAFB4 000E7F14  40 82 00 7C */	bne lbl_800EB030
/* 800EAFB8 000E7F18  A0 1F 04 28 */	lhz r0, 0x428(r31)
/* 800EAFBC 000E7F1C  38 81 00 24 */	addi r4, r1, 0x24
/* 800EAFC0 000E7F20  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800EAFC4 000E7F24  38 BF 00 94 */	addi r5, r31, 0x94
/* 800EAFC8 000E7F28  54 00 10 3A */	slwi r0, r0, 2
/* 800EAFCC 000E7F2C  7C 84 00 2E */	lwzx r4, r4, r0
/* 800EAFD0 000E7F30  38 C0 00 00 */	li r6, 0
/* 800EAFD4 000E7F34  38 E0 00 00 */	li r7, 0
/* 800EAFD8 000E7F38  48 0B 1B 61 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 800EAFDC 000E7F3C  90 7F 03 DC */	stw r3, 0x3dc(r31)
/* 800EAFE0 000E7F40  80 7F 03 DC */	lwz r3, 0x3dc(r31)
/* 800EAFE4 000E7F44  28 03 00 00 */	cmplwi r3, 0
/* 800EAFE8 000E7F48  41 82 00 0C */	beq lbl_800EAFF4
/* 800EAFEC 000E7F4C  38 1F 00 94 */	addi r0, r31, 0x94
/* 800EAFF0 000E7F50  90 03 00 18 */	stw r0, 0x18(r3)
lbl_800EAFF4:
/* 800EAFF4 000E7F54  38 60 01 20 */	li r3, 0x120
/* 800EAFF8 000E7F58  4B FB A3 7D */	bl playSysSe__8SeSystemFi
/* 800EAFFC 000E7F5C  48 00 00 34 */	b lbl_800EB030
lbl_800EB000:
/* 800EB000 000E7F60  80 1F 03 DC */	lwz r0, 0x3dc(r31)
/* 800EB004 000E7F64  28 00 00 00 */	cmplwi r0, 0
/* 800EB008 000E7F68  41 82 00 28 */	beq lbl_800EB030
/* 800EB00C 000E7F6C  38 60 01 20 */	li r3, 0x120
/* 800EB010 000E7F70  4B FB A3 99 */	bl stopSysSe__8SeSystemFi
/* 800EB014 000E7F74  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800EB018 000E7F78  38 A0 00 00 */	li r5, 0
/* 800EB01C 000E7F7C  80 9F 03 DC */	lwz r4, 0x3dc(r31)
/* 800EB020 000E7F80  38 63 00 14 */	addi r3, r3, 0x14
/* 800EB024 000E7F84  48 0B 65 A1 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 800EB028 000E7F88  38 00 00 00 */	li r0, 0
/* 800EB02C 000E7F8C  90 1F 03 DC */	stw r0, 0x3dc(r31)
lbl_800EB030:
/* 800EB030 000E7F90  88 1F 03 D9 */	lbz r0, 0x3d9(r31)
/* 800EB034 000E7F94  28 00 00 00 */	cmplwi r0, 0
/* 800EB038 000E7F98  41 82 00 70 */	beq lbl_800EB0A8
/* 800EB03C 000E7F9C  3C 60 80 22 */	lis r3, lbl_80222658@ha
/* 800EB040 000E7FA0  38 83 26 58 */	addi r4, r3, lbl_80222658@l
/* 800EB044 000E7FA4  80 64 00 00 */	lwz r3, 0(r4)
/* 800EB048 000E7FA8  80 04 00 04 */	lwz r0, 4(r4)
/* 800EB04C 000E7FAC  90 61 00 18 */	stw r3, 0x18(r1)
/* 800EB050 000E7FB0  90 01 00 1C */	stw r0, 0x1c(r1)
/* 800EB054 000E7FB4  80 04 00 08 */	lwz r0, 8(r4)
/* 800EB058 000E7FB8  90 01 00 20 */	stw r0, 0x20(r1)
/* 800EB05C 000E7FBC  80 1F 03 E0 */	lwz r0, 0x3e0(r31)
/* 800EB060 000E7FC0  28 00 00 00 */	cmplwi r0, 0
/* 800EB064 000E7FC4  40 82 00 68 */	bne lbl_800EB0CC
/* 800EB068 000E7FC8  A0 1F 04 28 */	lhz r0, 0x428(r31)
/* 800EB06C 000E7FCC  38 81 00 18 */	addi r4, r1, 0x18
/* 800EB070 000E7FD0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800EB074 000E7FD4  38 BF 00 94 */	addi r5, r31, 0x94
/* 800EB078 000E7FD8  54 00 10 3A */	slwi r0, r0, 2
/* 800EB07C 000E7FDC  7C 84 00 2E */	lwzx r4, r4, r0
/* 800EB080 000E7FE0  38 C0 00 00 */	li r6, 0
/* 800EB084 000E7FE4  38 E0 00 00 */	li r7, 0
/* 800EB088 000E7FE8  48 0B 1A B1 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 800EB08C 000E7FEC  90 7F 03 E0 */	stw r3, 0x3e0(r31)
/* 800EB090 000E7FF0  80 7F 03 E0 */	lwz r3, 0x3e0(r31)
/* 800EB094 000E7FF4  28 03 00 00 */	cmplwi r3, 0
/* 800EB098 000E7FF8  41 82 00 34 */	beq lbl_800EB0CC
/* 800EB09C 000E7FFC  38 1F 00 94 */	addi r0, r31, 0x94
/* 800EB0A0 000E8000  90 03 00 18 */	stw r0, 0x18(r3)
/* 800EB0A4 000E8004  48 00 00 28 */	b lbl_800EB0CC
lbl_800EB0A8:
/* 800EB0A8 000E8008  80 9F 03 E0 */	lwz r4, 0x3e0(r31)
/* 800EB0AC 000E800C  28 04 00 00 */	cmplwi r4, 0
/* 800EB0B0 000E8010  41 82 00 1C */	beq lbl_800EB0CC
/* 800EB0B4 000E8014  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 800EB0B8 000E8018  38 A0 00 00 */	li r5, 0
/* 800EB0BC 000E801C  38 63 00 14 */	addi r3, r3, 0x14
/* 800EB0C0 000E8020  48 0B 65 05 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 800EB0C4 000E8024  38 00 00 00 */	li r0, 0
/* 800EB0C8 000E8028  90 1F 03 E0 */	stw r0, 0x3e0(r31)
lbl_800EB0CC:
/* 800EB0CC 000E802C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800EB0D0 000E8030  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800EB0D4 000E8034  38 21 00 38 */	addi r1, r1, 0x38
/* 800EB0D8 000E8038  7C 08 03 A6 */	mtlr r0
/* 800EB0DC 000E803C  4E 80 00 20 */	blr 

.global invoke__8GoalItemFPQ23zen17particleGeneratorPQ23zen11particleMdl
invoke__8GoalItemFPQ23zen17particleGeneratorPQ23zen11particleMdl:
/* 800EB0E0 000E8040  7C 08 02 A6 */	mflr r0
/* 800EB0E4 000E8044  90 01 00 04 */	stw r0, 4(r1)
/* 800EB0E8 000E8048  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800EB0EC 000E804C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800EB0F0 000E8050  7C BF 2B 79 */	or. r31, r5, r5
/* 800EB0F4 000E8054  41 82 00 2C */	beq lbl_800EB120
/* 800EB0F8 000E8058  3C 80 6C 6C */	lis r4, 0x6C6C6974@ha
/* 800EB0FC 000E805C  80 63 02 20 */	lwz r3, 0x220(r3)
/* 800EB100 000E8060  38 84 69 74 */	addi r4, r4, 0x6C6C6974@l
/* 800EB104 000E8064  4B F9 E6 0D */	bl getSphere__8CollInfoFUl
/* 800EB108 000E8068  80 83 00 04 */	lwz r4, 4(r3)
/* 800EB10C 000E806C  80 03 00 08 */	lwz r0, 8(r3)
/* 800EB110 000E8070  90 9F 00 18 */	stw r4, 0x18(r31)
/* 800EB114 000E8074  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 800EB118 000E8078  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800EB11C 000E807C  90 1F 00 20 */	stw r0, 0x20(r31)
lbl_800EB120:
/* 800EB120 000E8080  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800EB124 000E8084  38 60 00 01 */	li r3, 1
/* 800EB128 000E8088  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800EB12C 000E808C  38 21 00 20 */	addi r1, r1, 0x20
/* 800EB130 000E8090  7C 08 03 A6 */	mtlr r0
/* 800EB134 000E8094  4E 80 00 20 */	blr 

.global setFlightLight__8GoalItemFb
setFlightLight__8GoalItemFb:
/* 800EB138 000E8098  98 83 03 EC */	stb r4, 0x3ec(r3)
/* 800EB13C 000E809C  4E 80 00 20 */	blr 

.global getSuckPos__8GoalItemFv
getSuckPos__8GoalItemFv:
/* 800EB140 000E80A0  C0 44 00 98 */	lfs f2, 0x98(r4)
/* 800EB144 000E80A4  C0 22 9A 60 */	lfs f1, lbl_803E9C60@sda21(r2)
/* 800EB148 000E80A8  C0 64 00 9C */	lfs f3, 0x9c(r4)
/* 800EB14C 000E80AC  C0 04 00 94 */	lfs f0, 0x94(r4)
/* 800EB150 000E80B0  EC 42 08 2A */	fadds f2, f2, f1
/* 800EB154 000E80B4  D0 03 00 00 */	stfs f0, 0(r3)
/* 800EB158 000E80B8  D0 43 00 04 */	stfs f2, 4(r3)
/* 800EB15C 000E80BC  D0 63 00 08 */	stfs f3, 8(r3)
/* 800EB160 000E80C0  4E 80 00 20 */	blr 

.global suckMe__8GoalItemFP6Pellet
suckMe__8GoalItemFP6Pellet:
/* 800EB164 000E80C4  7C 08 02 A6 */	mflr r0
/* 800EB168 000E80C8  90 01 00 04 */	stw r0, 4(r1)
/* 800EB16C 000E80CC  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800EB170 000E80D0  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800EB174 000E80D4  7C 7F 1B 78 */	mr r31, r3
/* 800EB178 000E80D8  80 84 05 5C */	lwz r4, 0x55c(r4)
/* 800EB17C 000E80DC  A0 63 04 28 */	lhz r3, 0x428(r3)
/* 800EB180 000E80E0  80 04 00 5C */	lwz r0, 0x5c(r4)
/* 800EB184 000E80E4  7C 03 00 00 */	cmpw r3, r0
/* 800EB188 000E80E8  40 82 00 0C */	bne lbl_800EB194
/* 800EB18C 000E80EC  80 A4 00 DC */	lwz r5, 0xdc(r4)
/* 800EB190 000E80F0  48 00 00 08 */	b lbl_800EB198
lbl_800EB194:
/* 800EB194 000E80F4  80 A4 00 EC */	lwz r5, 0xec(r4)
lbl_800EB198:
/* 800EB198 000E80F8  2C 05 00 00 */	cmpwi r5, 0
/* 800EB19C 000E80FC  40 80 00 60 */	bge lbl_800EB1FC
/* 800EB1A0 000E8100  80 9F 02 D4 */	lwz r4, 0x2d4(r31)
/* 800EB1A4 000E8104  38 60 00 0A */	li r3, 0xa
/* 800EB1A8 000E8108  38 00 00 00 */	li r0, 0
/* 800EB1AC 000E810C  38 84 00 02 */	addi r4, r4, 2
/* 800EB1B0 000E8110  90 9F 02 D4 */	stw r4, 0x2d4(r31)
/* 800EB1B4 000E8114  38 9F 00 00 */	addi r4, r31, 0
/* 800EB1B8 000E8118  38 A1 00 24 */	addi r5, r1, 0x24
/* 800EB1BC 000E811C  90 61 00 24 */	stw r3, 0x24(r1)
/* 800EB1C0 000E8120  90 01 00 28 */	stw r0, 0x28(r1)
/* 800EB1C4 000E8124  80 7F 02 E8 */	lwz r3, 0x2e8(r31)
/* 800EB1C8 000E8128  81 83 00 00 */	lwz r12, 0(r3)
/* 800EB1CC 000E812C  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800EB1D0 000E8130  7D 88 03 A6 */	mtlr r12
/* 800EB1D4 000E8134  4E 80 00 21 */	blrl 
/* 800EB1D8 000E8138  38 7F 00 00 */	addi r3, r31, 0
/* 800EB1DC 000E813C  38 9F 00 00 */	addi r4, r31, 0
/* 800EB1E0 000E8140  38 A0 00 D8 */	li r5, 0xd8
/* 800EB1E4 000E8144  4B F9 F3 D1 */	bl playEventSound__8CreatureFP8Creaturei
/* 800EB1E8 000E8148  38 7F 00 00 */	addi r3, r31, 0
/* 800EB1EC 000E814C  38 9F 00 00 */	addi r4, r31, 0
/* 800EB1F0 000E8150  38 A0 00 D6 */	li r5, 0xd6
/* 800EB1F4 000E8154  4B F9 F3 C1 */	bl playEventSound__8CreatureFP8Creaturei
/* 800EB1F8 000E8158  48 00 00 4C */	b lbl_800EB244
lbl_800EB1FC:
/* 800EB1FC 000E815C  80 9F 02 D0 */	lwz r4, 0x2d0(r31)
/* 800EB200 000E8160  38 60 00 0A */	li r3, 0xa
/* 800EB204 000E8164  38 00 00 00 */	li r0, 0
/* 800EB208 000E8168  7C 84 2A 14 */	add r4, r4, r5
/* 800EB20C 000E816C  90 9F 02 D0 */	stw r4, 0x2d0(r31)
/* 800EB210 000E8170  38 9F 00 00 */	addi r4, r31, 0
/* 800EB214 000E8174  38 A1 00 1C */	addi r5, r1, 0x1c
/* 800EB218 000E8178  90 61 00 1C */	stw r3, 0x1c(r1)
/* 800EB21C 000E817C  90 01 00 20 */	stw r0, 0x20(r1)
/* 800EB220 000E8180  80 7F 02 E8 */	lwz r3, 0x2e8(r31)
/* 800EB224 000E8184  81 83 00 00 */	lwz r12, 0(r3)
/* 800EB228 000E8188  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800EB22C 000E818C  7D 88 03 A6 */	mtlr r12
/* 800EB230 000E8190  4E 80 00 21 */	blrl 
/* 800EB234 000E8194  38 7F 00 00 */	addi r3, r31, 0
/* 800EB238 000E8198  38 9F 00 00 */	addi r4, r31, 0
/* 800EB23C 000E819C  38 A0 00 D6 */	li r5, 0xd6
/* 800EB240 000E81A0  4B F9 F3 75 */	bl playEventSound__8CreatureFP8Creaturei
lbl_800EB244:
/* 800EB244 000E81A4  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800EB248 000E81A8  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800EB24C 000E81AC  38 21 00 38 */	addi r1, r1, 0x38
/* 800EB250 000E81B0  7C 08 03 A6 */	mtlr r0
/* 800EB254 000E81B4  4E 80 00 20 */	blr 

.global enterGoal__8GoalItemFP4Piki
enterGoal__8GoalItemFP4Piki:
/* 800EB258 000E81B8  7C 08 02 A6 */	mflr r0
/* 800EB25C 000E81BC  38 A0 00 D2 */	li r5, 0xd2
/* 800EB260 000E81C0  90 01 00 04 */	stw r0, 4(r1)
/* 800EB264 000E81C4  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800EB268 000E81C8  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800EB26C 000E81CC  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800EB270 000E81D0  3B C4 00 00 */	addi r30, r4, 0
/* 800EB274 000E81D4  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 800EB278 000E81D8  7C 7D 1B 78 */	mr r29, r3
/* 800EB27C 000E81DC  38 9D 00 00 */	addi r4, r29, 0
/* 800EB280 000E81E0  83 E3 03 B0 */	lwz r31, 0x3b0(r3)
/* 800EB284 000E81E4  4B F9 F3 31 */	bl playEventSound__8CreatureFP8Creaturei
/* 800EB288 000E81E8  3C 60 80 3D */	lis r3, pikiInfMgr@ha
/* 800EB28C 000E81EC  38 63 1D F0 */	addi r3, r3, pikiInfMgr@l
/* 800EB290 000E81F0  38 9E 00 00 */	addi r4, r30, 0
/* 800EB294 000E81F4  4B FD A5 51 */	bl incPiki__10PikiInfMgrFP4Piki
/* 800EB298 000E81F8  80 9E 05 20 */	lwz r4, 0x520(r30)
/* 800EB29C 000E81FC  38 00 00 01 */	li r0, 1
/* 800EB2A0 000E8200  38 7E 00 00 */	addi r3, r30, 0
/* 800EB2A4 000E8204  54 84 10 3A */	slwi r4, r4, 2
/* 800EB2A8 000E8208  7C DD 22 14 */	add r6, r29, r4
/* 800EB2AC 000E820C  80 A6 04 2C */	lwz r5, 0x42c(r6)
/* 800EB2B0 000E8210  38 80 00 00 */	li r4, 0
/* 800EB2B4 000E8214  38 A5 00 01 */	addi r5, r5, 1
/* 800EB2B8 000E8218  90 A6 04 2C */	stw r5, 0x42c(r6)
/* 800EB2BC 000E821C  98 1E 05 84 */	stb r0, 0x584(r30)
/* 800EB2C0 000E8220  4B F9 FA 21 */	bl kill__8CreatureFb
/* 800EB2C4 000E8224  A0 9E 05 10 */	lhz r4, 0x510(r30)
/* 800EB2C8 000E8228  3C 60 80 3D */	lis r3, containerPikis__8GameStat@ha
/* 800EB2CC 000E822C  38 03 1E A0 */	addi r0, r3, containerPikis__8GameStat@l
/* 800EB2D0 000E8230  54 83 10 3A */	slwi r3, r4, 2
/* 800EB2D4 000E8234  7C 80 1A 14 */	add r4, r0, r3
/* 800EB2D8 000E8238  80 64 00 00 */	lwz r3, 0(r4)
/* 800EB2DC 000E823C  38 03 00 01 */	addi r0, r3, 1
/* 800EB2E0 000E8240  90 04 00 00 */	stw r0, 0(r4)
/* 800EB2E4 000E8244  48 02 72 7D */	bl update__8GameStatFv
/* 800EB2E8 000E8248  2C 1F 00 01 */	cmpwi r31, 1
/* 800EB2EC 000E824C  40 82 00 14 */	bne lbl_800EB300
/* 800EB2F0 000E8250  80 7D 02 E8 */	lwz r3, 0x2e8(r29)
/* 800EB2F4 000E8254  38 9D 00 00 */	addi r4, r29, 0
/* 800EB2F8 000E8258  38 A0 00 00 */	li r5, 0
/* 800EB2FC 000E825C  4B F9 24 5D */	bl start__8SimpleAIFP10AICreaturei
lbl_800EB300:
/* 800EB300 000E8260  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800EB304 000E8264  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800EB308 000E8268  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800EB30C 000E826C  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 800EB310 000E8270  38 21 00 28 */	addi r1, r1, 0x28
/* 800EB314 000E8274  7C 08 03 A6 */	mtlr r0
/* 800EB318 000E8278  4E 80 00 20 */	blr 

.global exitPikis__8GoalItemFi
exitPikis__8GoalItemFi:
/* 800EB31C 000E827C  38 00 00 01 */	li r0, 1
/* 800EB320 000E8280  98 03 04 10 */	stb r0, 0x410(r3)
/* 800EB324 000E8284  80 03 04 14 */	lwz r0, 0x414(r3)
/* 800EB328 000E8288  7C 00 22 14 */	add r0, r0, r4
/* 800EB32C 000E828C  90 03 04 14 */	stw r0, 0x414(r3)
/* 800EB330 000E8290  C0 02 9A 3C */	lfs f0, lbl_803E9C3C@sda21(r2)
/* 800EB334 000E8294  D0 03 04 18 */	stfs f0, 0x418(r3)
/* 800EB338 000E8298  4E 80 00 20 */	blr 

.global exitPiki__8GoalItemFv
exitPiki__8GoalItemFv:
/* 800EB33C 000E829C  7C 08 02 A6 */	mflr r0
/* 800EB340 000E82A0  90 01 00 04 */	stw r0, 4(r1)
/* 800EB344 000E82A4  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800EB348 000E82A8  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 800EB34C 000E82AC  93 C1 00 38 */	stw r30, 0x38(r1)
/* 800EB350 000E82B0  93 A1 00 34 */	stw r29, 0x34(r1)
/* 800EB354 000E82B4  7C 7D 1B 78 */	mr r29, r3
/* 800EB358 000E82B8  93 81 00 30 */	stw r28, 0x30(r1)
/* 800EB35C 000E82BC  48 12 CD 15 */	bl rand
/* 800EB360 000E82C0  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800EB364 000E82C4  C8 82 9A 58 */	lfd f4, "@1668"@sda21(r2)
/* 800EB368 000E82C8  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800EB36C 000E82CC  3C 00 43 30 */	lis r0, 0x4330
/* 800EB370 000E82D0  C0 42 9A 44 */	lfs f2, lbl_803E9C44@sda21(r2)
/* 800EB374 000E82D4  90 01 00 28 */	stw r0, 0x28(r1)
/* 800EB378 000E82D8  C0 22 9A 40 */	lfs f1, lbl_803E9C40@sda21(r2)
/* 800EB37C 000E82DC  C8 61 00 28 */	lfd f3, 0x28(r1)
/* 800EB380 000E82E0  C0 02 9A 4C */	lfs f0, lbl_803E9C4C@sda21(r2)
/* 800EB384 000E82E4  EC 63 20 28 */	fsubs f3, f3, f4
/* 800EB388 000E82E8  EC 43 10 24 */	fdivs f2, f3, f2
/* 800EB38C 000E82EC  EC 21 00 B2 */	fmuls f1, f1, f2
/* 800EB390 000E82F0  EC 00 00 72 */	fmuls f0, f0, f1
/* 800EB394 000E82F4  FC 00 00 1E */	fctiwz f0, f0
/* 800EB398 000E82F8  D8 01 00 18 */	stfd f0, 0x18(r1)
/* 800EB39C 000E82FC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800EB3A0 000E8300  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 800EB3A4 000E8304  2C 00 00 03 */	cmpwi r0, 3
/* 800EB3A8 000E8308  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800EB3AC 000E830C  41 80 00 08 */	blt lbl_800EB3B4
/* 800EB3B0 000E8310  3B E0 00 02 */	li r31, 2
lbl_800EB3B4:
/* 800EB3B4 000E8314  3C 80 80 2C */	lis r4, leg_ids_1@ha
/* 800EB3B8 000E8318  80 7D 02 20 */	lwz r3, 0x220(r29)
/* 800EB3BC 000E831C  57 E5 10 3A */	slwi r5, r31, 2
/* 800EB3C0 000E8320  38 04 C8 74 */	addi r0, r4, leg_ids_1@l
/* 800EB3C4 000E8324  7C 80 2A 14 */	add r4, r0, r5
/* 800EB3C8 000E8328  80 84 00 00 */	lwz r4, 0(r4)
/* 800EB3CC 000E832C  4B F9 E3 45 */	bl getSphere__8CollInfoFUl

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x6169426f
	.4byte 0x4d616b65
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x6169426f
	.4byte 0x4d616b65
	.4byte 0
	.4byte 0x496e7465
	.4byte 0x72616374
	.4byte 0x696f6e00
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0x41637442
	.4byte 0x6f4d616b
	.4byte 0x65000000
	.4byte 0x52656365
	.4byte 0x69766572
	.4byte 0x3c50696b
	.4byte 0x693e0000
	.4byte 0x803dfe40
	.4byte 0
	.4byte 0
	.4byte 0x803dfe40
	.4byte 0
	.4byte 0x803dfe50
	.4byte 0
	.4byte 0
.global __vt__9ActBoMake
__vt__9ActBoMake:
	.4byte __RTTI__9ActBoMake
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
	.4byte __dt__9ActBoMakeFv
	.4byte init__9ActBoMakeFP8Creature
	.4byte exec__9ActBoMakeFv
	.4byte cleanup__9ActBoMakeFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
	.4byte __RTTI__9ActBoMake
	.4byte 0xffffffec
	.4byte lbl_800AC794
	.4byte animationKeyUpdated__9ActBoMakeFR16PaniAnimKeyEvent
	.4byte 0x50616e69
	.4byte 0x416e696d
	.4byte 0x4b65794c
	.4byte 0x69737465
	.4byte 0x6e657200
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte lbl_800A7908
	.4byte lbl_800A7930
	.4byte lbl_800A7944
	.4byte lbl_800A7958
	.4byte lbl_800A796C
	.4byte lbl_800A7980
	.4byte lbl_800A7994
	.4byte lbl_800A79A8
	.4byte lbl_800A791C
	.4byte lbl_800A79D0
	.4byte lbl_800A79BC

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global __RTTI__11ActBoreRest
__RTTI__11ActBoreRest:
	.4byte 0x802b55b0
	.4byte 0x802b55ec
.global __RTTI__14ActBoreOneshot
__RTTI__14ActBoreOneshot:
	.4byte 0x802b567c
	.4byte 0x802b568c
.global __RTTI__13ActBoreListen
__RTTI__13ActBoreListen:
	.4byte 0x802b571c
	.4byte 0x802b572c
.global __RTTI__11ActBoreTalk
__RTTI__11ActBoreTalk:
	.4byte 0x802b57dc
	.4byte 0x802b57e8

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EA73C
lbl_803EA73C:
	.4byte 0x3F000000
.global lbl_803EA740
lbl_803EA740:
	.4byte 0x43960000
.global lbl_803EA744
lbl_803EA744:
	.4byte 0x43870000
.global lbl_803EA748
lbl_803EA748:
	.4byte 0x43700000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EBE14
lbl_803EBE14:
	.4byte 0x3E4CCCCD
.global lbl_803EBE18
lbl_803EBE18:
	.4byte 0x43960000
.global lbl_803EBE1C
lbl_803EBE1C:
	.4byte 0x41200000
.global lbl_803EBE20
lbl_803EBE20:
	.4byte 0x3D4CCCCD
