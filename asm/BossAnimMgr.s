.include "macros.inc"

.global __ct__20BossAnimationManagerFP7BossMgr
__ct__20BossAnimationManagerFP7BossMgr:
/* 8014FA68 0014C9C8  7C 08 02 A6 */	mflr r0
/* 8014FA6C 0014C9CC  3C A0 80 22 */	lis r5, __vt__5ANode@ha
/* 8014FA70 0014C9D0  90 01 00 04 */	stw r0, 4(r1)
/* 8014FA74 0014C9D4  38 05 73 8C */	addi r0, r5, __vt__5ANode@l
/* 8014FA78 0014C9D8  38 C0 00 00 */	li r6, 0
/* 8014FA7C 0014C9DC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8014FA80 0014C9E0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8014FA84 0014C9E4  3B E4 00 00 */	addi r31, r4, 0
/* 8014FA88 0014C9E8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8014FA8C 0014C9EC  3B C3 00 00 */	addi r30, r3, 0
/* 8014FA90 0014C9F0  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 8014FA94 0014C9F4  90 1E 00 00 */	stw r0, 0(r30)
/* 8014FA98 0014C9F8  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 8014FA9C 0014C9FC  3C 60 80 2D */	lis r3, lbl_802CEA9C@ha
/* 8014FAA0 0014CA00  90 1E 00 00 */	stw r0, 0(r30)
/* 8014FAA4 0014CA04  38 A3 EA 9C */	addi r5, r3, lbl_802CEA9C@l
/* 8014FAA8 0014CA08  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 8014FAAC 0014CA0C  90 DE 00 10 */	stw r6, 0x10(r30)
/* 8014FAB0 0014CA10  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 8014FAB4 0014CA14  38 7E 00 00 */	addi r3, r30, 0
/* 8014FAB8 0014CA18  90 DE 00 0C */	stw r6, 0xc(r30)
/* 8014FABC 0014CA1C  7C A4 2B 78 */	mr r4, r5
/* 8014FAC0 0014CA20  90 DE 00 08 */	stw r6, 8(r30)
/* 8014FAC4 0014CA24  90 BE 00 04 */	stw r5, 4(r30)
/* 8014FAC8 0014CA28  90 1E 00 00 */	stw r0, 0(r30)
/* 8014FACC 0014CA2C  4B EF 0C 71 */	bl init__4NodeFPc
/* 8014FAD0 0014CA30  3C 60 80 2D */	lis r3, __vt__20BossAnimationManager@ha
/* 8014FAD4 0014CA34  38 03 EA FC */	addi r0, r3, __vt__20BossAnimationManager@l
/* 8014FAD8 0014CA38  90 1E 00 00 */	stw r0, 0(r30)
/* 8014FADC 0014CA3C  7F C3 F3 78 */	mr r3, r30
/* 8014FAE0 0014CA40  93 FE 00 20 */	stw r31, 0x20(r30)
/* 8014FAE4 0014CA44  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8014FAE8 0014CA48  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8014FAEC 0014CA4C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8014FAF0 0014CA50  38 21 00 18 */	addi r1, r1, 0x18
/* 8014FAF4 0014CA54  7C 08 03 A6 */	mtlr r0
/* 8014FAF8 0014CA58  4E 80 00 20 */	blr 
