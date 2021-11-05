.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800F7EF4 000F4E54  38 80 00 01 */	li r4, 1
/* 800F7EF8 000F4E58  48 02 70 D1 */	bl __ct__10PaniMotionFi
lbl_800F7EFC:
/* 800F7EFC 000F4E5C  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F00 000F4E60  38 60 00 08 */	li r3, 8
/* 800F7F04 000F4E64  93 C4 00 04 */	stw r30, 4(r4)
/* 800F7F08 000F4E68  4B F4 F0 FD */	bl alloc__6SystemFUl
/* 800F7F0C 000F4E6C  3B C3 00 00 */	addi r30, r3, 0
/* 800F7F10 000F4E70  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7F14 000F4E74  41 82 00 0C */	beq lbl_800F7F20
/* 800F7F18 000F4E78  38 80 00 02 */	li r4, 2
/* 800F7F1C 000F4E7C  48 02 70 AD */	bl __ct__10PaniMotionFi
lbl_800F7F20:
/* 800F7F20 000F4E80  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F24 000F4E84  38 60 00 08 */	li r3, 8
/* 800F7F28 000F4E88  93 C4 00 08 */	stw r30, 8(r4)
/* 800F7F2C 000F4E8C  4B F4 F0 D9 */	bl alloc__6SystemFUl
/* 800F7F30 000F4E90  3B C3 00 00 */	addi r30, r3, 0
/* 800F7F34 000F4E94  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7F38 000F4E98  41 82 00 0C */	beq lbl_800F7F44
/* 800F7F3C 000F4E9C  38 80 00 03 */	li r4, 3
/* 800F7F40 000F4EA0  48 02 70 89 */	bl __ct__10PaniMotionFi
lbl_800F7F44:
/* 800F7F44 000F4EA4  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F48 000F4EA8  38 60 00 08 */	li r3, 8
/* 800F7F4C 000F4EAC  93 C4 00 0C */	stw r30, 0xc(r4)
/* 800F7F50 000F4EB0  4B F4 F0 B5 */	bl alloc__6SystemFUl
/* 800F7F54 000F4EB4  3B C3 00 00 */	addi r30, r3, 0
/* 800F7F58 000F4EB8  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7F5C 000F4EBC  41 82 00 0C */	beq lbl_800F7F68
/* 800F7F60 000F4EC0  38 80 00 04 */	li r4, 4
/* 800F7F64 000F4EC4  48 02 70 65 */	bl __ct__10PaniMotionFi
lbl_800F7F68:
/* 800F7F68 000F4EC8  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F6C 000F4ECC  38 60 00 08 */	li r3, 8
/* 800F7F70 000F4ED0  93 C4 00 10 */	stw r30, 0x10(r4)
/* 800F7F74 000F4ED4  4B F4 F0 91 */	bl alloc__6SystemFUl
/* 800F7F78 000F4ED8  3B C3 00 00 */	addi r30, r3, 0
/* 800F7F7C 000F4EDC  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7F80 000F4EE0  41 82 00 0C */	beq lbl_800F7F8C
/* 800F7F84 000F4EE4  38 80 00 05 */	li r4, 5
/* 800F7F88 000F4EE8  48 02 70 41 */	bl __ct__10PaniMotionFi
lbl_800F7F8C:
/* 800F7F8C 000F4EEC  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7F90 000F4EF0  38 60 00 08 */	li r3, 8
/* 800F7F94 000F4EF4  93 C4 00 14 */	stw r30, 0x14(r4)
/* 800F7F98 000F4EF8  4B F4 F0 6D */	bl alloc__6SystemFUl
/* 800F7F9C 000F4EFC  3B C3 00 00 */	addi r30, r3, 0
/* 800F7FA0 000F4F00  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7FA4 000F4F04  41 82 00 0C */	beq lbl_800F7FB0
/* 800F7FA8 000F4F08  38 80 00 06 */	li r4, 6
/* 800F7FAC 000F4F0C  48 02 70 1D */	bl __ct__10PaniMotionFi
lbl_800F7FB0:
/* 800F7FB0 000F4F10  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7FB4 000F4F14  38 60 00 08 */	li r3, 8
/* 800F7FB8 000F4F18  93 C4 00 18 */	stw r30, 0x18(r4)
/* 800F7FBC 000F4F1C  4B F4 F0 49 */	bl alloc__6SystemFUl
/* 800F7FC0 000F4F20  3B C3 00 00 */	addi r30, r3, 0
/* 800F7FC4 000F4F24  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7FC8 000F4F28  41 82 00 0C */	beq lbl_800F7FD4
/* 800F7FCC 000F4F2C  38 80 00 07 */	li r4, 7
/* 800F7FD0 000F4F30  48 02 6F F9 */	bl __ct__10PaniMotionFi
lbl_800F7FD4:
/* 800F7FD4 000F4F34  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7FD8 000F4F38  38 60 00 08 */	li r3, 8
/* 800F7FDC 000F4F3C  93 C4 00 1C */	stw r30, 0x1c(r4)
/* 800F7FE0 000F4F40  4B F4 F0 25 */	bl alloc__6SystemFUl
/* 800F7FE4 000F4F44  3B C3 00 00 */	addi r30, r3, 0
/* 800F7FE8 000F4F48  7F C3 F3 79 */	or. r3, r30, r30
/* 800F7FEC 000F4F4C  41 82 00 0C */	beq lbl_800F7FF8
/* 800F7FF0 000F4F50  38 80 00 08 */	li r4, 8
/* 800F7FF4 000F4F54  48 02 6F D5 */	bl __ct__10PaniMotionFi
lbl_800F7FF8:
/* 800F7FF8 000F4F58  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F7FFC 000F4F5C  38 60 00 08 */	li r3, 8
/* 800F8000 000F4F60  93 C4 00 20 */	stw r30, 0x20(r4)
/* 800F8004 000F4F64  4B F4 F0 01 */	bl alloc__6SystemFUl
/* 800F8008 000F4F68  3B C3 00 00 */	addi r30, r3, 0
/* 800F800C 000F4F6C  7F C3 F3 79 */	or. r3, r30, r30
/* 800F8010 000F4F70  41 82 00 0C */	beq lbl_800F801C
/* 800F8014 000F4F74  38 80 00 09 */	li r4, 9
/* 800F8018 000F4F78  48 02 6F B1 */	bl __ct__10PaniMotionFi
lbl_800F801C:
/* 800F801C 000F4F7C  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F8020 000F4F80  38 60 00 08 */	li r3, 8
/* 800F8024 000F4F84  93 C4 00 24 */	stw r30, 0x24(r4)
/* 800F8028 000F4F88  4B F4 EF DD */	bl alloc__6SystemFUl
/* 800F802C 000F4F8C  3B C3 00 00 */	addi r30, r3, 0
/* 800F8030 000F4F90  7F C3 F3 79 */	or. r3, r30, r30
/* 800F8034 000F4F94  41 82 00 0C */	beq lbl_800F8040
/* 800F8038 000F4F98  38 80 00 0A */	li r4, 0xa
/* 800F803C 000F4F9C  48 02 6F 8D */	bl __ct__10PaniMotionFi
lbl_800F8040:
/* 800F8040 000F4FA0  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F8044 000F4FA4  38 60 00 08 */	li r3, 8
/* 800F8048 000F4FA8  93 C4 00 28 */	stw r30, 0x28(r4)
/* 800F804C 000F4FAC  4B F4 EF B9 */	bl alloc__6SystemFUl
/* 800F8050 000F4FB0  3B C3 00 00 */	addi r30, r3, 0
/* 800F8054 000F4FB4  7F C3 F3 79 */	or. r3, r30, r30
/* 800F8058 000F4FB8  41 82 00 0C */	beq lbl_800F8064
/* 800F805C 000F4FBC  38 80 00 0B */	li r4, 0xb
/* 800F8060 000F4FC0  48 02 6F 69 */	bl __ct__10PaniMotionFi
lbl_800F8064:
/* 800F8064 000F4FC4  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F8068 000F4FC8  38 60 00 08 */	li r3, 8
/* 800F806C 000F4FCC  93 C4 00 2C */	stw r30, 0x2c(r4)
/* 800F8070 000F4FD0  4B F4 EF 95 */	bl alloc__6SystemFUl
/* 800F8074 000F4FD4  3B C3 00 00 */	addi r30, r3, 0
/* 800F8078 000F4FD8  7F C3 F3 79 */	or. r3, r30, r30
/* 800F807C 000F4FDC  41 82 00 0C */	beq lbl_800F8088
/* 800F8080 000F4FE0  38 80 00 0C */	li r4, 0xc
/* 800F8084 000F4FE4  48 02 6F 45 */	bl __ct__10PaniMotionFi
lbl_800F8088:
/* 800F8088 000F4FE8  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F808C 000F4FEC  38 60 00 08 */	li r3, 8
/* 800F8090 000F4FF0  93 C4 00 30 */	stw r30, 0x30(r4)
/* 800F8094 000F4FF4  4B F4 EF 71 */	bl alloc__6SystemFUl
/* 800F8098 000F4FF8  3B C3 00 00 */	addi r30, r3, 0
/* 800F809C 000F4FFC  7F C3 F3 79 */	or. r3, r30, r30
/* 800F80A0 000F5000  41 82 00 0C */	beq lbl_800F80AC
/* 800F80A4 000F5004  38 80 00 0D */	li r4, 0xd
/* 800F80A8 000F5008  48 02 6F 21 */	bl __ct__10PaniMotionFi
lbl_800F80AC:
/* 800F80AC 000F500C  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F80B0 000F5010  38 60 00 08 */	li r3, 8
/* 800F80B4 000F5014  93 C4 00 34 */	stw r30, 0x34(r4)
/* 800F80B8 000F5018  4B F4 EF 4D */	bl alloc__6SystemFUl
/* 800F80BC 000F501C  3B C3 00 00 */	addi r30, r3, 0
/* 800F80C0 000F5020  7F C3 F3 79 */	or. r3, r30, r30
/* 800F80C4 000F5024  41 82 00 0C */	beq lbl_800F80D0
/* 800F80C8 000F5028  38 80 00 0E */	li r4, 0xe
/* 800F80CC 000F502C  48 02 6E FD */	bl __ct__10PaniMotionFi
lbl_800F80D0:
/* 800F80D0 000F5030  80 9F 00 04 */	lwz r4, 4(r31)
/* 800F80D4 000F5034  7F E3 FB 78 */	mr r3, r31
/* 800F80D8 000F5038  93 C4 00 38 */	stw r30, 0x38(r4)
/* 800F80DC 000F503C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F80E0 000F5040  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F80E4 000F5044  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800F80E8 000F5048  38 21 00 18 */	addi r1, r1, 0x18
/* 800F80EC 000F504C  7C 08 03 A6 */	mtlr r0
/* 800F80F0 000F5050  4E 80 00 20 */	blr 

.global __ct__16PaniItemAnimatorFv
__ct__16PaniItemAnimatorFv:
/* 800F80F4 000F5054  7C 08 02 A6 */	mflr r0
/* 800F80F8 000F5058  90 01 00 04 */	stw r0, 4(r1)
/* 800F80FC 000F505C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F8100 000F5060  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F8104 000F5064  7C 7F 1B 78 */	mr r31, r3
/* 800F8108 000F5068  48 02 6F D9 */	bl __ct__12PaniAnimatorFv
/* 800F810C 000F506C  3C 60 80 2C */	lis r3, __vt__16PaniItemAnimator@ha
/* 800F8110 000F5070  38 03 FF 98 */	addi r0, r3, __vt__16PaniItemAnimator@l
/* 800F8114 000F5074  90 1F 00 30 */	stw r0, 0x30(r31)
/* 800F8118 000F5078  7F E3 FB 78 */	mr r3, r31
/* 800F811C 000F507C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F8120 000F5080  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F8124 000F5084  38 21 00 18 */	addi r1, r1, 0x18
/* 800F8128 000F5088  7C 08 03 A6 */	mtlr r0
/* 800F812C 000F508C  4E 80 00 20 */	blr 

.global makeObjectNavi__Fv
makeObjectNavi__Fv:
/* 800F8130 000F5090  7C 08 02 A6 */	mflr r0
/* 800F8134 000F5094  38 60 00 18 */	li r3, 0x18
/* 800F8138 000F5098  90 01 00 04 */	stw r0, 4(r1)
/* 800F813C 000F509C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F8140 000F50A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F8144 000F50A4  4B F4 EE C1 */	bl alloc__6SystemFUl
/* 800F8148 000F50A8  3B E3 00 00 */	addi r31, r3, 0
/* 800F814C 000F50AC  7F E3 FB 79 */	or. r3, r31, r31
/* 800F8150 000F50B0  41 82 00 38 */	beq lbl_800F8188
/* 800F8154 000F50B4  3C 80 80 2C */	lis r4, lbl_802BFFD0@ha
/* 800F8158 000F50B8  3C A0 80 2C */	lis r5, lbl_802BFFC4@ha
/* 800F815C 000F50BC  38 C4 FF D0 */	addi r6, r4, lbl_802BFFD0@l
/* 800F8160 000F50C0  3C 80 6E 61 */	lis r4, 0x6E617669@ha
/* 800F8164 000F50C4  38 A5 FF C4 */	addi r5, r5, lbl_802BFFC4@l
/* 800F8168 000F50C8  38 84 76 69 */	addi r4, r4, 0x6E617669@l
/* 800F816C 000F50CC  4B FE 2B 49 */	bl __ct__7GenBaseFUlPcPc
/* 800F8170 000F50D0  3C 60 80 2C */	lis r3, __vt__9GenObject@ha
/* 800F8174 000F50D4  38 03 AB 70 */	addi r0, r3, __vt__9GenObject@l
/* 800F8178 000F50D8  3C 60 80 2C */	lis r3, __vt__13GenObjectNavi@ha
/* 800F817C 000F50DC  90 1F 00 04 */	stw r0, 4(r31)
/* 800F8180 000F50E0  38 03 00 60 */	addi r0, r3, __vt__13GenObjectNavi@l
/* 800F8184 000F50E4  90 1F 00 04 */	stw r0, 4(r31)
lbl_800F8188:
/* 800F8188 000F50E8  7F E3 FB 78 */	mr r3, r31
/* 800F818C 000F50EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F8190 000F50F0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F8194 000F50F4  38 21 00 10 */	addi r1, r1, 0x10
/* 800F8198 000F50F8  7C 08 03 A6 */	mtlr r0
/* 800F819C 000F50FC  4E 80 00 20 */	blr 

.global initialise__13GenObjectNaviFv
initialise__13GenObjectNaviFv:
/* 800F81A0 000F5100  80 ED 30 74 */	lwz r7, factory__16GenObjectFactory@sda21(r13)
/* 800F81A4 000F5104  80 A7 00 00 */	lwz r5, 0(r7)
/* 800F81A8 000F5108  80 07 00 04 */	lwz r0, 4(r7)
/* 800F81AC 000F510C  7C 05 00 00 */	cmpw r5, r0
/* 800F81B0 000F5110  4C 80 00 20 */	bgelr 
/* 800F81B4 000F5114  3C 80 6E 61 */	lis r4, 0x6E617669@ha
/* 800F81B8 000F5118  80 67 00 08 */	lwz r3, 8(r7)
/* 800F81BC 000F511C  38 84 76 69 */	addi r4, r4, 0x6E617669@l
/* 800F81C0 000F5120  54 A0 20 36 */	slwi r0, r5, 4
/* 800F81C4 000F5124  7C 83 01 2E */	stwx r4, r3, r0
/* 800F81C8 000F5128  3C C0 80 10 */	lis r6, makeObjectNavi__Fv@ha
/* 800F81CC 000F512C  3C 80 80 2C */	lis r4, lbl_802BFFE4@ha
/* 800F81D0 000F5130  80 07 00 00 */	lwz r0, 0(r7)
/* 800F81D4 000F5134  3C 60 76 30 */	lis r3, 0x76302E30@ha
/* 800F81D8 000F5138  80 A7 00 08 */	lwz r5, 8(r7)
/* 800F81DC 000F513C  38 C6 81 30 */	addi r6, r6, makeObjectNavi__Fv@l
/* 800F81E0 000F5140  54 00 20 36 */	slwi r0, r0, 4
/* 800F81E4 000F5144  7C A5 02 14 */	add r5, r5, r0
/* 800F81E8 000F5148  90 C5 00 04 */	stw r6, 4(r5)
/* 800F81EC 000F514C  38 A4 FF E4 */	addi r5, r4, lbl_802BFFE4@l
/* 800F81F0 000F5150  38 83 2E 30 */	addi r4, r3, 0x76302E30@l
/* 800F81F4 000F5154  80 07 00 00 */	lwz r0, 0(r7)
/* 800F81F8 000F5158  80 67 00 08 */	lwz r3, 8(r7)
/* 800F81FC 000F515C  54 00 20 36 */	slwi r0, r0, 4
/* 800F8200 000F5160  7C 63 02 14 */	add r3, r3, r0
/* 800F8204 000F5164  90 A3 00 08 */	stw r5, 8(r3)
/* 800F8208 000F5168  80 07 00 00 */	lwz r0, 0(r7)
/* 800F820C 000F516C  80 67 00 08 */	lwz r3, 8(r7)
/* 800F8210 000F5170  54 00 20 36 */	slwi r0, r0, 4
/* 800F8214 000F5174  7C 63 02 14 */	add r3, r3, r0
/* 800F8218 000F5178  90 83 00 0C */	stw r4, 0xc(r3)
/* 800F821C 000F517C  80 67 00 00 */	lwz r3, 0(r7)
/* 800F8220 000F5180  38 03 00 01 */	addi r0, r3, 1
/* 800F8224 000F5184  90 07 00 00 */	stw r0, 0(r7)
/* 800F8228 000F5188  4E 80 00 20 */	blr 

.global doRead__13GenObjectNaviFR18RandomAccessStream
doRead__13GenObjectNaviFR18RandomAccessStream:
/* 800F822C 000F518C  4E 80 00 20 */	blr 

.global birth__13GenObjectNaviFR9BirthInfo
birth__13GenObjectNaviFR9BirthInfo:
/* 800F8230 000F5190  7C 08 02 A6 */	mflr r0
/* 800F8234 000F5194  90 01 00 04 */	stw r0, 4(r1)
/* 800F8238 000F5198  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F823C 000F519C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F8240 000F51A0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800F8244 000F51A4  7C 9E 23 78 */	mr r30, r4
/* 800F8248 000F51A8  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 800F824C 000F51AC  81 83 00 00 */	lwz r12, 0(r3)
/* 800F8250 000F51B0  81 8C 00 78 */	lwz r12, 0x78(r12)
/* 800F8254 000F51B4  7D 88 03 A6 */	mtlr r12
/* 800F8258 000F51B8  4E 80 00 21 */	blrl 
/* 800F825C 000F51BC  7C 7F 1B 79 */	or. r31, r3, r3
/* 800F8260 000F51C0  41 82 00 6C */	beq lbl_800F82CC
/* 800F8264 000F51C4  81 9F 00 00 */	lwz r12, 0(r31)
/* 800F8268 000F51C8  38 7F 00 00 */	addi r3, r31, 0
/* 800F826C 000F51CC  38 9E 00 00 */	addi r4, r30, 0
/* 800F8270 000F51D0  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 800F8274 000F51D4  7D 88 03 A6 */	mtlr r12
/* 800F8278 000F51D8  4E 80 00 21 */	blrl 
/* 800F827C 000F51DC  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800F8280 000F51E0  7F E3 FB 78 */	mr r3, r31
/* 800F8284 000F51E4  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 800F8288 000F51E8  90 9F 00 88 */	stw r4, 0x88(r31)
/* 800F828C 000F51EC  90 1F 00 8C */	stw r0, 0x8c(r31)
/* 800F8290 000F51F0  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800F8294 000F51F4  90 1F 00 90 */	stw r0, 0x90(r31)
/* 800F8298 000F51F8  C0 1F 00 8C */	lfs f0, 0x8c(r31)
/* 800F829C 000F51FC  D0 1F 00 A0 */	stfs f0, 0xa0(r31)
/* 800F82A0 000F5200  48 00 1F E9 */	bl reset__4NaviFv
/* 800F82A4 000F5204  80 1E 00 24 */	lwz r0, 0x24(r30)
/* 800F82A8 000F5208  90 1F 00 64 */	stw r0, 0x64(r31)
/* 800F82AC 000F520C  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 800F82B0 000F5210  48 01 F1 15 */	bl getNavi__7NaviMgrFv
/* 800F82B4 000F5214  80 03 02 E8 */	lwz r0, 0x2e8(r3)
/* 800F82B8 000F5218  3C 60 80 3A */	lis r3, flowCont@ha
/* 800F82BC 000F521C  38 63 DB 20 */	addi r3, r3, flowCont@l
/* 800F82C0 000F5220  90 1F 02 E8 */	stw r0, 0x2e8(r31)
/* 800F82C4 000F5224  38 00 00 01 */	li r0, 1
/* 800F82C8 000F5228  90 03 02 30 */	stw r0, 0x230(r3)
lbl_800F82CC:
/* 800F82CC 000F522C  7F E3 FB 78 */	mr r3, r31
/* 800F82D0 000F5230  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F82D4 000F5234  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F82D8 000F5238  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800F82DC 000F523C  38 21 00 18 */	addi r1, r1, 0x18
/* 800F82E0 000F5240  7C 08 03 A6 */	mtlr r0
/* 800F82E4 000F5244  4E 80 00 20 */	blr 

.global viewDraw__4NaviFR8GraphicsR8Matrix4f
viewDraw__4NaviFR8GraphicsR8Matrix4f:
/* 800F82E8 000F5248  7C 08 02 A6 */	mflr r0
/* 800F82EC 000F524C  90 01 00 04 */	stw r0, 4(r1)
/* 800F82F0 000F5250  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800F82F4 000F5254  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800F82F8 000F5258  3B E5 00 00 */	addi r31, r5, 0
/* 800F82FC 000F525C  38 A0 00 00 */	li r5, 0
/* 800F8300 000F5260  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800F8304 000F5264  3B C4 00 00 */	addi r30, r4, 0
/* 800F8308 000F5268  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 800F830C 000F526C  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 800F8310 000F5270  3B A3 00 00 */	addi r29, r3, 0
/* 800F8314 000F5274  38 7E 00 00 */	addi r3, r30, 0
/* 800F8318 000F5278  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 800F831C 000F527C  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 800F8320 000F5280  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800F8324 000F5284  7D 88 03 A6 */	mtlr r12
/* 800F8328 000F5288  4E 80 00 21 */	blrl 
/* 800F832C 000F528C  38 7D 08 34 */	addi r3, r29, 0x834
/* 800F8330 000F5290  48 02 78 D5 */	bl updateContext__15PaniPikiAnimMgrFv
/* 800F8334 000F5294  80 7D 08 2C */	lwz r3, 0x82c(r29)
/* 800F8338 000F5298  38 9E 00 00 */	addi r4, r30, 0
/* 800F833C 000F529C  38 BF 00 00 */	addi r5, r31, 0
/* 800F8340 000F52A0  80 63 00 00 */	lwz r3, 0(r3)
/* 800F8344 000F52A4  38 C0 00 00 */	li r6, 0
/* 800F8348 000F52A8  4B F3 CF CD */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 800F834C 000F52AC  7F A3 EB 78 */	mr r3, r29
/* 800F8350 000F52B0  81 9D 00 00 */	lwz r12, 0(r29)
/* 800F8354 000F52B4  38 9E 00 00 */	addi r4, r30, 0
/* 800F8358 000F52B8  38 BF 00 00 */	addi r5, r31, 0
/* 800F835C 000F52BC  81 8C 00 FC */	lwz r12, 0xfc(r12)
/* 800F8360 000F52C0  7D 88 03 A6 */	mtlr r12
/* 800F8364 000F52C4  4E 80 00 21 */	blrl 
/* 800F8368 000F52C8  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800F836C 000F52CC  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800F8370 000F52D0  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800F8374 000F52D4  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 800F8378 000F52D8  38 21 00 28 */	addi r1, r1, 0x28
/* 800F837C 000F52DC  7C 08 03 A6 */	mtlr r0
/* 800F8380 000F52E0  4E 80 00 20 */	blr 

.global viewStartTrembleMotion__4NaviFf
viewStartTrembleMotion__4NaviFf:
/* 800F8384 000F52E4  7C 08 02 A6 */	mflr r0
/* 800F8388 000F52E8  38 80 00 0C */	li r4, 0xc
/* 800F838C 000F52EC  90 01 00 04 */	stw r0, 4(r1)
/* 800F8390 000F52F0  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800F8394 000F52F4  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800F8398 000F52F8  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800F839C 000F52FC  3B C3 00 00 */	addi r30, r3, 0
/* 800F83A0 000F5300  38 61 00 10 */	addi r3, r1, 0x10
/* 800F83A4 000F5304  48 02 6B B5 */	bl __ct__14PaniMotionInfoFi
/* 800F83A8 000F5308  3B E3 00 00 */	addi r31, r3, 0
/* 800F83AC 000F530C  38 61 00 18 */	addi r3, r1, 0x18
/* 800F83B0 000F5310  38 80 00 0C */	li r4, 0xc
/* 800F83B4 000F5314  48 02 6B A5 */	bl __ct__14PaniMotionInfoFi
/* 800F83B8 000F5318  38 83 00 00 */	addi r4, r3, 0
/* 800F83BC 000F531C  38 BF 00 00 */	addi r5, r31, 0
/* 800F83C0 000F5320  38 7E 08 34 */	addi r3, r30, 0x834
/* 800F83C4 000F5324  48 02 76 A5 */	bl startMotion__15PaniPikiAnimMgrFR14PaniMotionInfoR14PaniMotionInfo
/* 800F83C8 000F5328  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800F83CC 000F532C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800F83D0 000F5330  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800F83D4 000F5334  38 21 00 28 */	addi r1, r1, 0x28
/* 800F83D8 000F5338  7C 08 03 A6 */	mtlr r0
/* 800F83DC 000F533C  4E 80 00 20 */	blr 

.global viewKill__4NaviFv
viewKill__4NaviFv:
/* 800F83E0 000F5340  80 C3 02 C0 */	lwz r6, 0x2c0(r3)
/* 800F83E4 000F5344  38 00 00 00 */	li r0, 0
/* 800F83E8 000F5348  80 A6 00 94 */	lwz r5, 0x94(r6)
/* 800F83EC 000F534C  80 86 00 98 */	lwz r4, 0x98(r6)
/* 800F83F0 000F5350  90 A3 00 94 */	stw r5, 0x94(r3)
/* 800F83F4 000F5354  90 83 00 98 */	stw r4, 0x98(r3)
/* 800F83F8 000F5358  80 86 00 9C */	lwz r4, 0x9c(r6)
/* 800F83FC 000F535C  90 83 00 9C */	stw r4, 0x9c(r3)
/* 800F8400 000F5360  90 03 02 C0 */	stw r0, 0x2c0(r3)
/* 800F8404 000F5364  4E 80 00 20 */	blr 

.global viewGetBottomRadius__4NaviFv
viewGetBottomRadius__4NaviFv:
/* 800F8408 000F5368  C0 22 9C 58 */	lfs f1, lbl_803E9E58@sda21(r2)
/* 800F840C 000F536C  4E 80 00 20 */	blr 

.global viewGetHeight__4NaviFv
viewGetHeight__4NaviFv:
/* 800F8410 000F5370  C0 22 9C 5C */	lfs f1, lbl_803E9E5C@sda21(r2)
/* 800F8414 000F5374  4E 80 00 20 */	blr 

.global isNuking__4NaviFv
isNuking__4NaviFv:
/* 800F8418 000F5378  80 63 0A DC */	lwz r3, 0xadc(r3)
/* 800F841C 000F537C  28 03 00 00 */	cmplwi r3, 0
/* 800F8420 000F5380  41 82 00 0C */	beq lbl_800F842C
/* 800F8424 000F5384  80 03 00 04 */	lwz r0, 4(r3)
/* 800F8428 000F5388  48 00 00 08 */	b lbl_800F8430
lbl_800F842C:
/* 800F842C 000F538C  38 00 FF FF */	li r0, -1
lbl_800F8430:
/* 800F8430 000F5390  20 00 00 05 */	subfic r0, r0, 5
/* 800F8434 000F5394  7C 00 00 34 */	cntlzw r0, r0
/* 800F8438 000F5398  54 03 D9 7E */	srwi r3, r0, 5
/* 800F843C 000F539C  4E 80 00 20 */	blr 

.global "transit__19StateMachine<4Navi>FP4Navii"
"transit__19StateMachine<4Navi>FP4Navii":
/* 800F8440 000F53A0  7C 08 02 A6 */	mflr r0
/* 800F8444 000F53A4  90 01 00 04 */	stw r0, 4(r1)
/* 800F8448 000F53A8  54 A0 10 3A */	slwi r0, r5, 2
/* 800F844C 000F53AC  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 800F8450 000F53B0  93 E1 00 24 */	stw r31, 0x24(r1)
/* 800F8454 000F53B4  93 C1 00 20 */	stw r30, 0x20(r1)
/* 800F8458 000F53B8  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 800F845C 000F53BC  7C 9D 23 78 */	mr r29, r4
/* 800F8460 000F53C0  93 81 00 18 */	stw r28, 0x18(r1)
/* 800F8464 000F53C4  7C 7C 1B 78 */	mr r28, r3
/* 800F8468 000F53C8  83 E4 0A DC */	lwz r31, 0xadc(r4)
/* 800F846C 000F53CC  80 63 00 14 */	lwz r3, 0x14(r3)
/* 800F8470 000F53D0  28 1F 00 00 */	cmplwi r31, 0
/* 800F8474 000F53D4  7F C3 00 2E */	lwzx r30, r3, r0
/* 800F8478 000F53D8  7F E3 FB 78 */	mr r3, r31
/* 800F847C 000F53DC  41 82 00 20 */	beq lbl_800F849C
/* 800F8480 000F53E0  81 83 00 00 */	lwz r12, 0(r3)
/* 800F8484 000F53E4  7F A4 EB 78 */	mr r4, r29
/* 800F8488 000F53E8  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 800F848C 000F53EC  7D 88 03 A6 */	mtlr r12
/* 800F8490 000F53F0  4E 80 00 21 */	blrl 
/* 800F8494 000F53F4  80 1F 00 04 */	lwz r0, 4(r31)
/* 800F8498 000F53F8  90 1C 00 18 */	stw r0, 0x18(r28)
lbl_800F849C:
/* 800F849C 000F53FC  80 1C 00 0C */	lwz r0, 0xc(r28)
/* 800F84A0 000F5400  7C 1E 00 00 */	cmpw r30, r0
/* 800F84A4 000F5404  41 80 00 08 */	blt lbl_800F84AC
lbl_800F84A8:
/* 800F84A8 000F5408  48 00 00 00 */	b lbl_800F84A8
lbl_800F84AC:
/* 800F84AC 000F540C  80 7C 00 04 */	lwz r3, 4(r28)
/* 800F84B0 000F5410  57 C0 10 3A */	slwi r0, r30, 2
/* 800F84B4 000F5414  38 9D 00 00 */	addi r4, r29, 0
/* 800F84B8 000F5418  7C 63 00 2E */	lwzx r3, r3, r0
/* 800F84BC 000F541C  90 7D 0A DC */	stw r3, 0xadc(r29)
/* 800F84C0 000F5420  81 83 00 00 */	lwz r12, 0(r3)
/* 800F84C4 000F5424  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 800F84C8 000F5428  7D 88 03 A6 */	mtlr r12
/* 800F84CC 000F542C  4E 80 00 21 */	blrl 
/* 800F84D0 000F5430  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800F84D4 000F5434  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800F84D8 000F5438  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800F84DC 000F543C  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 800F84E0 000F5440  83 81 00 18 */	lwz r28, 0x18(r1)
/* 800F84E4 000F5444  38 21 00 28 */	addi r1, r1, 0x28
/* 800F84E8 000F5448  7C 08 03 A6 */	mtlr r0
/* 800F84EC 000F544C  4E 80 00 20 */	blr 

.global "init__13AState<4Navi>FP4Navi"
"init__13AState<4Navi>FP4Navi":
/* 800F84F0 000F5450  4E 80 00 20 */	blr 

.global "cleanup__13AState<4Navi>FP4Navi"
"cleanup__13AState<4Navi>FP4Navi":
/* 800F84F4 000F5454  4E 80 00 20 */	blr 

.global startMovieInf__4NaviFv
startMovieInf__4NaviFv:
/* 800F84F8 000F5458  7C 08 02 A6 */	mflr r0
/* 800F84FC 000F545C  7C 64 1B 78 */	mr r4, r3
/* 800F8500 000F5460  90 01 00 04 */	stw r0, 4(r1)
/* 800F8504 000F5464  38 A0 00 16 */	li r5, 0x16
/* 800F8508 000F5468  94 21 FF F8 */	stwu r1, -8(r1)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x61694d69
  .4byte 0x6e652e63
  .4byte 0x70700000
  .4byte 0x50616e69
  .4byte 0x416e696d
  .4byte 0x4b65794c
  .4byte 0x69737465
  .4byte 0x6e657200
  .4byte 0x52656365
  .4byte 0x69766572
  .4byte 0x3c50696b
  .4byte 0x693e0000
  .4byte 0x803e03e8
  .4byte 0
  .4byte 0
  .4byte 0x803e03e0
  .4byte 0x28
  .4byte 0x803e03e8
  .4byte 0
  .4byte 0x803e03f8
  .4byte 0
  .4byte 0
.global __vt__7ActMine
__vt__7ActMine:
  .4byte __RTTI__7ActMine
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
  .4byte __dt__7ActMineFv
  .4byte init__7ActMineFP8Creature
  .4byte exec__7ActMineFv
  .4byte cleanup__7ActMineFv
  .4byte resume__6ActionFv
  .4byte restart__6ActionFv
  .4byte resumable__6ActionFv
  .4byte getInfo__6ActionFPc
  .4byte animationKeyUpdated__7ActMineFR16PaniAnimKeyEvent
  .4byte __RTTI__7ActMine
  .4byte 0xffffffd8
  .4byte 0x800b98c4
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
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0x800a7908
  .4byte 0x800a7930
  .4byte 0x800a7944
  .4byte 0x800a7958
  .4byte 0x800a796c
  .4byte 0x800a7980
  .4byte 0x800a7994
  .4byte 0x800a79a8
  .4byte 0x800a791c
  .4byte 0x800a79d0
  .4byte 0x800a79bc
  .4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global lbl_803E0390
lbl_803E0390:
	.4byte 0x43480000
	.4byte 0x41637445
	.4byte 0x78697400
	.4byte 0x802B6734
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E03A4
	.4byte 0x802B6744
.global __RTTI__7ActExit
__RTTI__7ActExit:
  .4byte 0x803e0394
  .4byte 0x802b6750
  .4byte 0
.global lbl_803E03C0
lbl_803E03C0:
	.4byte 0x00000000
.global lbl_803E03C4
lbl_803E03C4:
	.4byte 0x00000000
.global lbl_803E03C8
lbl_803E03C8:
	.4byte 0x00000000
.global lbl_803E03CC
lbl_803E03CC:
	.4byte 0x00000000
.global lbl_803E03D0
lbl_803E03D0:
	.4byte 0x00000000
.global lbl_803E03D4
lbl_803E03D4:
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EAA94
lbl_803EAA94:
	.4byte 0x41200000
.global lbl_803EAA98
lbl_803EAA98:
	.4byte 0x42F00000
.global lbl_803EAA9C
lbl_803EAA9C:
	.4byte 0x41700000
.global lbl_803EAAA0
lbl_803EAAA0:
	.4byte 0x42340000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EC16C
lbl_803EC16C:
	.4byte 0x3D75C28F
.global lbl_803EC170
lbl_803EC170:
	.4byte 0x3D23D70A
.global lbl_803EC174
lbl_803EC174:
	.4byte 0x3DBA2E8C
.global lbl_803EC178
lbl_803EC178:
	.4byte 0x3F333333
