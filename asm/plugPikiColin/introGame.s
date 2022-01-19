.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__16IntroGameSectionFv
__ct__16IntroGameSectionFv:
/* 8005AE1C 00057D7C  7C 08 02 A6 */	mflr r0
/* 8005AE20 00057D80  38 8D 8F 24 */	addi r4, r13, lbl_803DDC44@sda21
/* 8005AE24 00057D84  90 01 00 04 */	stw r0, 4(r1)
/* 8005AE28 00057D88  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8005AE2C 00057D8C  BF 61 00 3C */	stmw r27, 0x3c(r1)
/* 8005AE30 00057D90  3B A3 00 00 */	addi r29, r3, 0
/* 8005AE34 00057D94  4B FD A1 85 */	bl __ct__8CoreNodeFPc
/* 8005AE38 00057D98  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 8005AE3C 00057D9C  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 8005AE40 00057DA0  90 1D 00 00 */	stw r0, 0(r29)
/* 8005AE44 00057DA4  38 7D 00 00 */	addi r3, r29, 0
/* 8005AE48 00057DA8  38 8D 8F 24 */	addi r4, r13, lbl_803DDC44@sda21
/* 8005AE4C 00057DAC  4B FE 58 F1 */	bl init__4NodeFPc
/* 8005AE50 00057DB0  3C 60 80 2A */	lis r3, __vt__7Section@ha
/* 8005AE54 00057DB4  38 03 64 2C */	addi r0, r3, __vt__7Section@l
/* 8005AE58 00057DB8  3C 60 80 2B */	lis r3, __vt__16IntroGameSection@ha
/* 8005AE5C 00057DBC  90 1D 00 00 */	stw r0, 0(r29)
/* 8005AE60 00057DC0  38 03 81 54 */	addi r0, r3, __vt__16IntroGameSection@l
/* 8005AE64 00057DC4  3C 60 80 2A */	lis r3, lbl_802A7F84@ha
/* 8005AE68 00057DC8  90 1D 00 00 */	stw r0, 0(r29)
/* 8005AE6C 00057DCC  38 83 7F 84 */	addi r4, r3, lbl_802A7F84@l
/* 8005AE70 00057DD0  38 7D 00 00 */	addi r3, r29, 0
/* 8005AE74 00057DD4  4B FE 58 C9 */	bl init__4NodeFPc
/* 8005AE78 00057DD8  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005AE7C 00057DDC  38 80 00 02 */	li r4, 2
/* 8005AE80 00057DE0  38 00 00 00 */	li r0, 0
/* 8005AE84 00057DE4  90 83 00 14 */	stw r4, 0x14(r3)
/* 8005AE88 00057DE8  38 80 00 00 */	li r4, 0
/* 8005AE8C 00057DEC  38 A0 00 01 */	li r5, 1
/* 8005AE90 00057DF0  90 0D 2F 00 */	stw r0, mapMgr@sda21(r13)
/* 8005AE94 00057DF4  38 C0 00 3C */	li r6, 0x3c
/* 8005AE98 00057DF8  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005AE9C 00057DFC  90 0D 2E 90 */	stw r0, igss@sda21(r13)
/* 8005AEA0 00057E00  81 83 01 A0 */	lwz r12, 0x1a0(r3)
/* 8005AEA4 00057E04  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 8005AEA8 00057E08  7D 88 03 A6 */	mtlr r12
/* 8005AEAC 00057E0C  4E 80 00 21 */	blrl 
/* 8005AEB0 00057E10  38 60 03 A8 */	li r3, 0x3a8
/* 8005AEB4 00057E14  4B FE C1 51 */	bl alloc__6SystemFUl
/* 8005AEB8 00057E18  7C 7F 1B 79 */	or. r31, r3, r3
/* 8005AEBC 00057E1C  41 82 01 C0 */	beq lbl_8005B07C
/* 8005AEC0 00057E20  7F E3 FB 78 */	mr r3, r31
/* 8005AEC4 00057E24  4B FF BF C1 */	bl __ct__15BaseGameSectionFv
/* 8005AEC8 00057E28  3C 60 80 2B */	lis r3, __vt__21IntroGameSetupSection@ha
/* 8005AECC 00057E2C  38 03 80 CC */	addi r0, r3, __vt__21IntroGameSetupSection@l
/* 8005AED0 00057E30  90 1F 00 00 */	stw r0, 0(r31)
/* 8005AED4 00057E34  38 7F 00 50 */	addi r3, r31, 0x50
/* 8005AED8 00057E38  4B FE 82 ED */	bl __ct__6CameraFv
/* 8005AEDC 00057E3C  38 60 00 0C */	li r3, 0xc
/* 8005AEE0 00057E40  4B FE C1 25 */	bl alloc__6SystemFUl
/* 8005AEE4 00057E44  28 03 00 00 */	cmplwi r3, 0
/* 8005AEE8 00057E48  41 82 00 28 */	beq lbl_8005AF10
/* 8005AEEC 00057E4C  3C 80 80 2A */	lis r4, __vt__9ModeState@ha
/* 8005AEF0 00057E50  38 04 7E CC */	addi r0, r4, __vt__9ModeState@l
/* 8005AEF4 00057E54  90 03 00 04 */	stw r0, 4(r3)
/* 8005AEF8 00057E58  3C 80 80 2A */	lis r4, __vt__14IntroModeState@ha
/* 8005AEFC 00057E5C  38 04 7F F4 */	addi r0, r4, __vt__14IntroModeState@l
/* 8005AF00 00057E60  93 E3 00 00 */	stw r31, 0(r3)
/* 8005AF04 00057E64  90 03 00 04 */	stw r0, 4(r3)
/* 8005AF08 00057E68  80 1F 00 24 */	lwz r0, 0x24(r31)
/* 8005AF0C 00057E6C  90 03 00 08 */	stw r0, 8(r3)
lbl_8005AF10:
/* 8005AF10 00057E70  90 7F 00 34 */	stw r3, 0x34(r31)
/* 8005AF14 00057E74  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005AF18 00057E78  39 03 D7 B8 */	addi r8, r3, gameflow@l
/* 8005AF1C 00057E7C  C0 2D 8F 18 */	lfs f1, lbl_803DDC38@sda21(r13)
/* 8005AF20 00057E80  3B C8 01 DC */	addi r30, r8, 0x1dc
/* 8005AF24 00057E84  C0 0D 8F 0C */	lfs f0, lbl_803DDC2C@sda21(r13)
/* 8005AF28 00057E88  38 E0 00 00 */	li r7, 0
/* 8005AF2C 00057E8C  D0 21 00 28 */	stfs f1, 0x28(r1)
/* 8005AF30 00057E90  C0 2D 8F 1C */	lfs f1, lbl_803DDC3C@sda21(r13)
/* 8005AF34 00057E94  38 00 00 01 */	li r0, 1
/* 8005AF38 00057E98  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 8005AF3C 00057E9C  38 60 00 0B */	li r3, 0xb
/* 8005AF40 00057EA0  C0 0D 8F 10 */	lfs f0, lbl_803DDC30@sda21(r13)
/* 8005AF44 00057EA4  D0 21 00 2C */	stfs f1, 0x2c(r1)
/* 8005AF48 00057EA8  38 80 00 00 */	li r4, 0
/* 8005AF4C 00057EAC  C0 2D 8F 20 */	lfs f1, lbl_803DDC40@sda21(r13)
/* 8005AF50 00057EB0  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 8005AF54 00057EB4  C0 0D 8F 14 */	lfs f0, lbl_803DDC34@sda21(r13)
/* 8005AF58 00057EB8  D0 21 00 30 */	stfs f1, 0x30(r1)
/* 8005AF5C 00057EBC  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 8005AF60 00057EC0  81 28 01 DC */	lwz r9, 0x1dc(r8)
/* 8005AF64 00057EC4  98 E9 01 6C */	stb r7, 0x16c(r9)
/* 8005AF68 00057EC8  C0 02 85 E0 */	lfs f0, lbl_803E87E0@sda21(r2)
/* 8005AF6C 00057ECC  D0 09 01 60 */	stfs f0, 0x160(r9)
/* 8005AF70 00057ED0  80 C1 00 1C */	lwz r6, 0x1c(r1)
/* 8005AF74 00057ED4  80 A1 00 20 */	lwz r5, 0x20(r1)
/* 8005AF78 00057ED8  90 C9 01 48 */	stw r6, 0x148(r9)
/* 8005AF7C 00057EDC  90 A9 01 4C */	stw r5, 0x14c(r9)
/* 8005AF80 00057EE0  80 A1 00 24 */	lwz r5, 0x24(r1)
/* 8005AF84 00057EE4  90 A9 01 50 */	stw r5, 0x150(r9)
/* 8005AF88 00057EE8  80 C1 00 28 */	lwz r6, 0x28(r1)
/* 8005AF8C 00057EEC  80 A1 00 2C */	lwz r5, 0x2c(r1)
/* 8005AF90 00057EF0  90 C9 01 54 */	stw r6, 0x154(r9)
/* 8005AF94 00057EF4  90 A9 01 58 */	stw r5, 0x158(r9)
/* 8005AF98 00057EF8  80 A1 00 30 */	lwz r5, 0x30(r1)
/* 8005AF9C 00057EFC  90 A9 01 5C */	stw r5, 0x15c(r9)
/* 8005AFA0 00057F00  98 1F 03 A4 */	stb r0, 0x3a4(r31)
/* 8005AFA4 00057F04  B0 E8 01 E4 */	sth r7, 0x1e4(r8)
/* 8005AFA8 00057F08  90 FF 00 44 */	stw r7, 0x44(r31)
/* 8005AFAC 00057F0C  90 FF 00 38 */	stw r7, 0x38(r31)
/* 8005AFB0 00057F10  4B FB E8 D1 */	bl Jac_SceneSetup
/* 8005AFB4 00057F14  38 60 06 B4 */	li r3, 0x6b4
/* 8005AFB8 00057F18  4B FE C0 4D */	bl alloc__6SystemFUl
/* 8005AFBC 00057F1C  3B 83 00 00 */	addi r28, r3, 0
/* 8005AFC0 00057F20  7F 83 E3 79 */	or. r3, r28, r28
/* 8005AFC4 00057F24  41 82 00 08 */	beq lbl_8005AFCC
/* 8005AFC8 00057F28  48 14 11 E5 */	bl __ct__9EffectMgrFv
lbl_8005AFCC:
/* 8005AFCC 00057F2C  38 00 00 00 */	li r0, 0
/* 8005AFD0 00057F30  98 1C 06 B0 */	stb r0, 0x6b0(r28)
/* 8005AFD4 00057F34  38 60 14 18 */	li r3, 0x1418
/* 8005AFD8 00057F38  4B FE C0 2D */	bl alloc__6SystemFUl
/* 8005AFDC 00057F3C  3B 63 00 00 */	addi r27, r3, 0
/* 8005AFE0 00057F40  7F 63 DB 79 */	or. r3, r27, r27
/* 8005AFE4 00057F44  41 82 00 10 */	beq lbl_8005AFF4
/* 8005AFE8 00057F48  80 BF 00 24 */	lwz r5, 0x24(r31)
/* 8005AFEC 00057F4C  38 80 00 00 */	li r4, 0
/* 8005AFF0 00057F50  48 01 04 C5 */	bl __ct__6DayMgrFP6MapMgrP10Controller
lbl_8005AFF4:
/* 8005AFF4 00057F54  3F 80 00 50 */	lis r28, 0x50
/* 8005AFF8 00057F58  93 7F 03 9C */	stw r27, 0x39c(r31)
/* 8005AFFC 00057F5C  7F 83 E3 78 */	mr r3, r28
/* 8005B000 00057F60  4B FE C0 05 */	bl alloc__6SystemFUl
/* 8005B004 00057F64  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8005B008 00057F68  38 C3 00 00 */	addi r6, r3, 0
/* 8005B00C 00057F6C  38 FC 00 00 */	addi r7, r28, 0
/* 8005B010 00057F70  38 64 01 1C */	addi r3, r4, 0x11c
/* 8005B014 00057F74  38 8D 8F 2C */	addi r4, r13, lbl_803DDC4C@sda21
/* 8005B018 00057F78  38 A0 00 02 */	li r5, 2
/* 8005B01C 00057F7C  4B FC 98 ED */	bl init__7AyuHeapFPciPvi
/* 8005B020 00057F80  80 7E 00 00 */	lwz r3, 0(r30)
/* 8005B024 00057F84  38 80 00 01 */	li r4, 1
/* 8005B028 00057F88  38 A0 00 00 */	li r5, 0
/* 8005B02C 00057F8C  38 C0 00 00 */	li r6, 0
/* 8005B030 00057F90  38 E0 00 00 */	li r7, 0
/* 8005B034 00057F94  39 00 00 00 */	li r8, 0
/* 8005B038 00057F98  39 20 FF FF */	li r9, -1
/* 8005B03C 00057F9C  39 40 00 01 */	li r10, 1
/* 8005B040 00057FA0  48 01 C1 21 */	bl startMovie__11MoviePlayerFiiP8CreatureP8Vector3fP8Vector3fUlb
/* 8005B044 00057FA4  80 7E 00 00 */	lwz r3, 0(r30)
/* 8005B048 00057FA8  38 80 00 02 */	li r4, 2
/* 8005B04C 00057FAC  38 A0 00 00 */	li r5, 0
/* 8005B050 00057FB0  38 C0 00 00 */	li r6, 0
/* 8005B054 00057FB4  38 E0 00 00 */	li r7, 0
/* 8005B058 00057FB8  39 00 00 00 */	li r8, 0
/* 8005B05C 00057FBC  39 20 FF FF */	li r9, -1
/* 8005B060 00057FC0  39 40 00 01 */	li r10, 1
/* 8005B064 00057FC4  48 01 C0 FD */	bl startMovie__11MoviePlayerFiiP8CreatureP8Vector3fP8Vector3fUlb
/* 8005B068 00057FC8  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005B06C 00057FCC  C0 02 85 E4 */	lfs f0, lbl_803E87E4@sda21(r2)
/* 8005B070 00057FD0  D0 03 00 08 */	stfs f0, 8(r3)
/* 8005B074 00057FD4  C0 02 85 E8 */	lfs f0, lbl_803E87E8@sda21(r2)
/* 8005B078 00057FD8  D0 03 00 0C */	stfs f0, 0xc(r3)
lbl_8005B07C:
/* 8005B07C 00057FDC  38 9F 00 00 */	addi r4, r31, 0
/* 8005B080 00057FE0  38 7D 00 00 */	addi r3, r29, 0
/* 8005B084 00057FE4  4B FE 55 55 */	bl add__8CoreNodeFP8CoreNode
/* 8005B088 00057FE8  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005B08C 00057FEC  81 83 01 A0 */	lwz r12, 0x1a0(r3)
/* 8005B090 00057FF0  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 8005B094 00057FF4  7D 88 03 A6 */	mtlr r12
/* 8005B098 00057FF8  4E 80 00 21 */	blrl 
/* 8005B09C 00057FFC  7F A3 EB 78 */	mr r3, r29
/* 8005B0A0 00058000  BB 61 00 3C */	lmw r27, 0x3c(r1)
/* 8005B0A4 00058004  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8005B0A8 00058008  38 21 00 50 */	addi r1, r1, 0x50
/* 8005B0AC 0005800C  7C 08 03 A6 */	mtlr r0
/* 8005B0B0 00058010  4E 80 00 20 */	blr 

.global update__14IntroModeStateFRUl
update__14IntroModeStateFRUl:
/* 8005B0B4 00058014  7C 08 02 A6 */	mflr r0
/* 8005B0B8 00058018  3C A0 80 3A */	lis r5, gameflow@ha
/* 8005B0BC 0005801C  90 01 00 04 */	stw r0, 4(r1)
/* 8005B0C0 00058020  38 00 00 01 */	li r0, 1
/* 8005B0C4 00058024  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8005B0C8 00058028  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8005B0CC 0005802C  7C 7F 1B 78 */	mr r31, r3
/* 8005B0D0 00058030  90 04 00 00 */	stw r0, 0(r4)
/* 8005B0D4 00058034  38 85 D7 B8 */	addi r4, r5, gameflow@l
/* 8005B0D8 00058038  80 84 01 DC */	lwz r4, 0x1dc(r4)
/* 8005B0DC 0005803C  88 04 01 24 */	lbz r0, 0x124(r4)
/* 8005B0E0 00058040  28 00 00 00 */	cmplwi r0, 0
/* 8005B0E4 00058044  40 82 00 38 */	bne lbl_8005B11C
/* 8005B0E8 00058048  38 60 00 08 */	li r3, 8
/* 8005B0EC 0005804C  4B FE BF 19 */	bl alloc__6SystemFUl
/* 8005B0F0 00058050  28 03 00 00 */	cmplwi r3, 0
/* 8005B0F4 00058054  41 82 00 2C */	beq lbl_8005B120
/* 8005B0F8 00058058  3C 80 80 2A */	lis r4, __vt__9ModeState@ha
/* 8005B0FC 0005805C  80 BF 00 00 */	lwz r5, 0(r31)
/* 8005B100 00058060  38 04 7E CC */	addi r0, r4, __vt__9ModeState@l
/* 8005B104 00058064  90 03 00 04 */	stw r0, 4(r3)
/* 8005B108 00058068  3C 80 80 2B */	lis r4, __vt__17QuittingModeState@ha
/* 8005B10C 0005806C  38 04 80 28 */	addi r0, r4, __vt__17QuittingModeState@l
/* 8005B110 00058070  90 A3 00 00 */	stw r5, 0(r3)
/* 8005B114 00058074  90 03 00 04 */	stw r0, 4(r3)
/* 8005B118 00058078  48 00 00 08 */	b lbl_8005B120
lbl_8005B11C:
/* 8005B11C 0005807C  7F E3 FB 78 */	mr r3, r31
lbl_8005B120:
/* 8005B120 00058080  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8005B124 00058084  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8005B128 00058088  38 21 00 18 */	addi r1, r1, 0x18
/* 8005B12C 0005808C  7C 08 03 A6 */	mtlr r0
/* 8005B130 00058090  4E 80 00 20 */	blr 

.global postRender__14IntroModeStateFR8Graphics
postRender__14IntroModeStateFR8Graphics:
/* 8005B134 00058094  4E 80 00 20 */	blr 

.global update__17QuittingModeStateFRUl
update__17QuittingModeStateFRUl:
/* 8005B138 00058098  38 00 00 00 */	li r0, 0
/* 8005B13C 0005809C  90 04 00 00 */	stw r0, 0(r4)
/* 8005B140 000580A0  4E 80 00 20 */	blr 

.global postUpdate__17QuittingModeStateFv
postUpdate__17QuittingModeStateFv:
/* 8005B144 000580A4  7C 08 02 A6 */	mflr r0
/* 8005B148 000580A8  90 01 00 04 */	stw r0, 4(r1)
/* 8005B14C 000580AC  94 21 FF F8 */	stwu r1, -8(r1)
/* 8005B150 000580B0  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005B154 000580B4  88 03 00 00 */	lbz r0, 0(r3)
/* 8005B158 000580B8  28 00 00 00 */	cmplwi r0, 0
/* 8005B15C 000580BC  40 82 00 34 */	bne lbl_8005B190
/* 8005B160 000580C0  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 8005B164 000580C4  48 02 B5 AD */	bl reset__7MemStatFv
/* 8005B168 000580C8  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005B16C 000580CC  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 8005B170 000580D0  38 00 00 07 */	li r0, 7
/* 8005B174 000580D4  90 03 01 F4 */	stw r0, 0x1f4(r3)
/* 8005B178 000580D8  38 60 00 0D */	li r3, 0xd
/* 8005B17C 000580DC  38 80 00 00 */	li r4, 0
/* 8005B180 000580E0  4B FB EB 61 */	bl Jac_SceneExit
/* 8005B184 000580E4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005B188 000580E8  38 00 00 01 */	li r0, 1
/* 8005B18C 000580EC  98 03 00 00 */	stb r0, 0(r3)
lbl_8005B190:
/* 8005B190 000580F0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8005B194 000580F4  38 21 00 08 */	addi r1, r1, 8
/* 8005B198 000580F8  7C 08 03 A6 */	mtlr r0
/* 8005B19C 000580FC  4E 80 00 20 */	blr 

.global update__21IntroGameSetupSectionFv
update__21IntroGameSetupSectionFv:
/* 8005B1A0 00058100  7C 08 02 A6 */	mflr r0
/* 8005B1A4 00058104  90 01 00 04 */	stw r0, 4(r1)
/* 8005B1A8 00058108  94 21 FF F8 */	stwu r1, -8(r1)
/* 8005B1AC 0005810C  80 63 00 24 */	lwz r3, 0x24(r3)
/* 8005B1B0 00058110  81 83 00 00 */	lwz r12, 0(r3)
/* 8005B1B4 00058114  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8005B1B8 00058118  7D 88 03 A6 */	mtlr r12
/* 8005B1BC 0005811C  4E 80 00 21 */	blrl 
/* 8005B1C0 00058120  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8005B1C4 00058124  38 21 00 08 */	addi r1, r1, 8
/* 8005B1C8 00058128  7C 08 03 A6 */	mtlr r0
/* 8005B1CC 0005812C  4E 80 00 20 */	blr 

.global draw__21IntroGameSetupSectionFR8Graphics
draw__21IntroGameSetupSectionFR8Graphics:
/* 8005B1D0 00058130  7C 08 02 A6 */	mflr r0
/* 8005B1D4 00058134  3C A0 80 3A */	lis r5, gameflow@ha
/* 8005B1D8 00058138  90 01 00 04 */	stw r0, 4(r1)
/* 8005B1DC 0005813C  38 A5 D7 B8 */	addi r5, r5, gameflow@l
/* 8005B1E0 00058140  94 21 FE 80 */	stwu r1, -0x180(r1)
/* 8005B1E4 00058144  93 E1 01 7C */	stw r31, 0x17c(r1)
/* 8005B1E8 00058148  3B E5 01 DC */	addi r31, r5, 0x1dc
/* 8005B1EC 0005814C  93 C1 01 78 */	stw r30, 0x178(r1)
/* 8005B1F0 00058150  7C 9E 23 78 */	mr r30, r4
/* 8005B1F4 00058154  93 A1 01 74 */	stw r29, 0x174(r1)
/* 8005B1F8 00058158  3B A3 00 00 */	addi r29, r3, 0
/* 8005B1FC 0005815C  93 81 01 70 */	stw r28, 0x170(r1)
/* 8005B200 00058160  80 65 01 DC */	lwz r3, 0x1dc(r5)
/* 8005B204 00058164  48 01 C6 85 */	bl update__11MoviePlayerFv
/* 8005B208 00058168  80 7F 00 00 */	lwz r3, 0(r31)
/* 8005B20C 0005816C  7F C4 F3 78 */	mr r4, r30
/* 8005B210 00058170  48 01 CB 0D */	bl setCamera__11MoviePlayerFR8Graphics
/* 8005B214 00058174  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8005B218 00058178  40 82 00 6C */	bne lbl_8005B284
/* 8005B21C 0005817C  7F C3 F3 78 */	mr r3, r30
/* 8005B220 00058180  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B224 00058184  38 9D 00 50 */	addi r4, r29, 0x50
/* 8005B228 00058188  81 8C 00 6C */	lwz r12, 0x6c(r12)
/* 8005B22C 0005818C  7D 88 03 A6 */	mtlr r12
/* 8005B230 00058190  4E 80 00 21 */	blrl 
/* 8005B234 00058194  80 BE 03 0C */	lwz r5, 0x30c(r30)
/* 8005B238 00058198  3C 80 43 30 */	lis r4, 0x4330
/* 8005B23C 0005819C  80 1E 03 10 */	lwz r0, 0x310(r30)
/* 8005B240 000581A0  38 7D 00 50 */	addi r3, r29, 0x50
/* 8005B244 000581A4  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 8005B248 000581A8  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8005B24C 000581AC  90 A1 01 6C */	stw r5, 0x16c(r1)
/* 8005B250 000581B0  C8 A2 85 F8 */	lfd f5, lbl_803E87F8@sda21(r2)
/* 8005B254 000581B4  90 01 01 64 */	stw r0, 0x164(r1)
/* 8005B258 000581B8  C0 5D 02 1C */	lfs f2, 0x21c(r29)
/* 8005B25C 000581BC  90 81 01 68 */	stw r4, 0x168(r1)
/* 8005B260 000581C0  C0 62 85 EC */	lfs f3, lbl_803E87EC@sda21(r2)
/* 8005B264 000581C4  90 81 01 60 */	stw r4, 0x160(r1)
/* 8005B268 000581C8  C8 21 01 68 */	lfd f1, 0x168(r1)
/* 8005B26C 000581CC  C8 01 01 60 */	lfd f0, 0x160(r1)
/* 8005B270 000581D0  EC 21 28 28 */	fsubs f1, f1, f5
/* 8005B274 000581D4  C0 9D 03 98 */	lfs f4, 0x398(r29)
/* 8005B278 000581D8  EC 00 28 28 */	fsubs f0, f0, f5
/* 8005B27C 000581DC  EC 21 00 24 */	fdivs f1, f1, f0
/* 8005B280 000581E0  4B FE 79 D5 */	bl update__11CullFrustumFffff
lbl_8005B284:
/* 8005B284 000581E4  80 BE 03 10 */	lwz r5, 0x310(r30)
/* 8005B288 000581E8  3B 80 00 00 */	li r28, 0
/* 8005B28C 000581EC  80 1E 03 0C */	lwz r0, 0x30c(r30)
/* 8005B290 000581F0  38 81 00 C8 */	addi r4, r1, 0xc8
/* 8005B294 000581F4  38 7E 00 00 */	addi r3, r30, 0
/* 8005B298 000581F8  93 81 00 C8 */	stw r28, 0xc8(r1)
/* 8005B29C 000581FC  93 81 00 CC */	stw r28, 0xcc(r1)
/* 8005B2A0 00058200  90 01 00 D0 */	stw r0, 0xd0(r1)
/* 8005B2A4 00058204  90 A1 00 D4 */	stw r5, 0xd4(r1)
/* 8005B2A8 00058208  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B2AC 0005820C  81 8C 00 48 */	lwz r12, 0x48(r12)
/* 8005B2B0 00058210  7D 88 03 A6 */	mtlr r12
/* 8005B2B4 00058214  4E 80 00 21 */	blrl 
/* 8005B2B8 00058218  80 BE 03 10 */	lwz r5, 0x310(r30)
/* 8005B2BC 0005821C  38 81 00 D8 */	addi r4, r1, 0xd8
/* 8005B2C0 00058220  80 1E 03 0C */	lwz r0, 0x30c(r30)
/* 8005B2C4 00058224  7F C3 F3 78 */	mr r3, r30
/* 8005B2C8 00058228  93 81 00 D8 */	stw r28, 0xd8(r1)
/* 8005B2CC 0005822C  93 81 00 DC */	stw r28, 0xdc(r1)
/* 8005B2D0 00058230  90 01 00 E0 */	stw r0, 0xe0(r1)
/* 8005B2D4 00058234  90 A1 00 E4 */	stw r5, 0xe4(r1)
/* 8005B2D8 00058238  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B2DC 0005823C  81 8C 00 50 */	lwz r12, 0x50(r12)
/* 8005B2E0 00058240  7D 88 03 A6 */	mtlr r12
/* 8005B2E4 00058244  4E 80 00 21 */	blrl 
/* 8005B2E8 00058248  9B 81 00 E8 */	stb r28, 0xe8(r1)
/* 8005B2EC 0005824C  38 81 00 E8 */	addi r4, r1, 0xe8
/* 8005B2F0 00058250  38 7E 00 00 */	addi r3, r30, 0
/* 8005B2F4 00058254  9B 81 00 E9 */	stb r28, 0xe9(r1)
/* 8005B2F8 00058258  9B 81 00 EA */	stb r28, 0xea(r1)
/* 8005B2FC 0005825C  9B 81 00 EB */	stb r28, 0xeb(r1)
/* 8005B300 00058260  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B304 00058264  81 8C 00 B4 */	lwz r12, 0xb4(r12)
/* 8005B308 00058268  7D 88 03 A6 */	mtlr r12
/* 8005B30C 0005826C  4E 80 00 21 */	blrl 
/* 8005B310 00058270  7F C3 F3 78 */	mr r3, r30
/* 8005B314 00058274  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B318 00058278  38 80 00 03 */	li r4, 3
/* 8005B31C 0005827C  38 A0 00 00 */	li r5, 0
/* 8005B320 00058280  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 8005B324 00058284  7D 88 03 A6 */	mtlr r12
/* 8005B328 00058288  4E 80 00 21 */	blrl 
/* 8005B32C 0005828C  7F C3 F3 78 */	mr r3, r30
/* 8005B330 00058290  80 BE 02 E4 */	lwz r5, 0x2e4(r30)
/* 8005B334 00058294  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B338 00058298  C0 25 01 CC */	lfs f1, 0x1cc(r5)
/* 8005B33C 0005829C  38 85 02 60 */	addi r4, r5, 0x260
/* 8005B340 000582A0  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 8005B344 000582A4  C0 45 01 C4 */	lfs f2, 0x1c4(r5)
/* 8005B348 000582A8  7D 88 03 A6 */	mtlr r12
/* 8005B34C 000582AC  C0 65 01 D0 */	lfs f3, 0x1d0(r5)
/* 8005B350 000582B0  C0 85 01 D4 */	lfs f4, 0x1d4(r5)
/* 8005B354 000582B4  C0 A2 85 E4 */	lfs f5, lbl_803E87E4@sda21(r2)
/* 8005B358 000582B8  4E 80 00 21 */	blrl 
/* 8005B35C 000582BC  7F C3 F3 78 */	mr r3, r30
/* 8005B360 000582C0  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B364 000582C4  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 8005B368 000582C8  3B 84 88 40 */	addi r28, r4, ident__8Matrix4f@l
/* 8005B36C 000582CC  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8005B370 000582D0  38 9C 00 00 */	addi r4, r28, 0
/* 8005B374 000582D4  38 A0 00 00 */	li r5, 0
/* 8005B378 000582D8  7D 88 03 A6 */	mtlr r12
/* 8005B37C 000582DC  4E 80 00 21 */	blrl 
/* 8005B380 000582E0  80 7D 03 9C */	lwz r3, 0x39c(r29)
/* 8005B384 000582E4  7F C4 F3 78 */	mr r4, r30
/* 8005B388 000582E8  C0 22 85 F0 */	lfs f1, lbl_803E87F0@sda21(r2)
/* 8005B38C 000582EC  38 A0 00 08 */	li r5, 8
/* 8005B390 000582F0  48 01 31 CD */	bl refresh__6DayMgrFR8Graphicsfi
/* 8005B394 000582F4  80 7D 03 9C */	lwz r3, 0x39c(r29)
/* 8005B398 000582F8  38 9E 00 00 */	addi r4, r30, 0
/* 8005B39C 000582FC  38 A0 00 00 */	li r5, 0
/* 8005B3A0 00058300  48 01 3B F5 */	bl setFog__6DayMgrFR8GraphicsP6Colour
/* 8005B3A4 00058304  7F C3 F3 78 */	mr r3, r30
/* 8005B3A8 00058308  C0 22 85 E4 */	lfs f1, lbl_803E87E4@sda21(r2)
/* 8005B3AC 0005830C  4B FC E4 31 */	bl calcLighting__8GraphicsFf
/* 8005B3B0 00058310  80 7F 00 00 */	lwz r3, 0(r31)
/* 8005B3B4 00058314  7F C4 F3 78 */	mr r4, r30
/* 8005B3B8 00058318  48 01 CA C5 */	bl refresh__11MoviePlayerFR8Graphics
/* 8005B3BC 0005831C  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B3C0 00058320  7F C3 F3 78 */	mr r3, r30
/* 8005B3C4 00058324  7F 84 E3 78 */	mr r4, r28
/* 8005B3C8 00058328  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8005B3CC 0005832C  38 A0 00 00 */	li r5, 0
/* 8005B3D0 00058330  7D 88 03 A6 */	mtlr r12
/* 8005B3D4 00058334  4E 80 00 21 */	blrl 
/* 8005B3D8 00058338  7F C3 F3 78 */	mr r3, r30
/* 8005B3DC 0005833C  4B FC D2 F1 */	bl flushCachedShapes__8GraphicsFv
/* 8005B3E0 00058340  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8005B3E4 00058344  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 8005B3E8 00058348  28 03 00 00 */	cmplwi r3, 0
/* 8005B3EC 0005834C  41 82 00 50 */	beq lbl_8005B43C
/* 8005B3F0 00058350  3C 80 80 3A */	lis r4, gameflow@ha
/* 8005B3F4 00058354  38 84 D7 B8 */	addi r4, r4, gameflow@l
/* 8005B3F8 00058358  80 04 03 3C */	lwz r0, 0x33c(r4)
/* 8005B3FC 0005835C  2C 00 00 00 */	cmpwi r0, 0
/* 8005B400 00058360  40 82 00 30 */	bne lbl_8005B430
/* 8005B404 00058364  80 04 03 38 */	lwz r0, 0x338(r4)
/* 8005B408 00058368  2C 00 00 00 */	cmpwi r0, 0
/* 8005B40C 0005836C  40 82 00 24 */	bne lbl_8005B430
/* 8005B410 00058370  80 05 02 58 */	lwz r0, 0x258(r5)
/* 8005B414 00058374  38 80 00 01 */	li r4, 1
/* 8005B418 00058378  2C 00 00 00 */	cmpwi r0, 0
/* 8005B41C 0005837C  41 80 00 08 */	blt lbl_8005B424
/* 8005B420 00058380  38 80 00 00 */	li r4, 0
lbl_8005B424:
/* 8005B424 00058384  54 80 06 3F */	clrlwi. r0, r4, 0x18
/* 8005B428 00058388  41 82 00 08 */	beq lbl_8005B430
/* 8005B42C 0005838C  48 14 15 0D */	bl update__9EffectMgrFv
lbl_8005B430:
/* 8005B430 00058390  7F C4 F3 78 */	mr r4, r30
/* 8005B434 00058394  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8005B438 00058398  48 14 15 7D */	bl draw__9EffectMgrFR8Graphics
lbl_8005B43C:
/* 8005B43C 0005839C  3C 60 80 3A */	lis r3, gameflow@ha
/* 8005B440 000583A0  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 8005B444 000583A4  80 03 01 D8 */	lwz r0, 0x1d8(r3)
/* 8005B448 000583A8  54 00 06 31 */	rlwinm. r0, r0, 0, 0x18, 0x18
/* 8005B44C 000583AC  40 82 01 1C */	bne lbl_8005B568
/* 8005B450 000583B0  80 DE 03 10 */	lwz r6, 0x310(r30)
/* 8005B454 000583B4  3B 80 00 00 */	li r28, 0
/* 8005B458 000583B8  80 1E 03 0C */	lwz r0, 0x30c(r30)
/* 8005B45C 000583BC  38 A1 01 0C */	addi r5, r1, 0x10c
/* 8005B460 000583C0  38 7E 00 00 */	addi r3, r30, 0
/* 8005B464 000583C4  93 81 01 0C */	stw r28, 0x10c(r1)
/* 8005B468 000583C8  38 81 01 1C */	addi r4, r1, 0x11c
/* 8005B46C 000583CC  93 81 01 10 */	stw r28, 0x110(r1)
/* 8005B470 000583D0  90 01 01 14 */	stw r0, 0x114(r1)
/* 8005B474 000583D4  90 C1 01 18 */	stw r6, 0x118(r1)
/* 8005B478 000583D8  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B47C 000583DC  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 8005B480 000583E0  7D 88 03 A6 */	mtlr r12
/* 8005B484 000583E4  4E 80 00 21 */	blrl 
/* 8005B488 000583E8  7F C3 F3 78 */	mr r3, r30
/* 8005B48C 000583EC  80 BE 02 E4 */	lwz r5, 0x2e4(r30)
/* 8005B490 000583F0  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B494 000583F4  C0 62 85 E4 */	lfs f3, lbl_803E87E4@sda21(r2)
/* 8005B498 000583F8  38 85 02 60 */	addi r4, r5, 0x260
/* 8005B49C 000583FC  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 8005B4A0 00058400  FC A0 18 90 */	fmr f5, f3
/* 8005B4A4 00058404  C0 22 85 E0 */	lfs f1, lbl_803E87E0@sda21(r2)
/* 8005B4A8 00058408  7D 88 03 A6 */	mtlr r12
/* 8005B4AC 0005840C  C0 45 01 C4 */	lfs f2, 0x1c4(r5)
/* 8005B4B0 00058410  C0 85 01 D4 */	lfs f4, 0x1d4(r5)
/* 8005B4B4 00058414  4E 80 00 21 */	blrl 
/* 8005B4B8 00058418  C0 4D 8F 00 */	lfs f2, lbl_803DDC20@sda21(r13)
/* 8005B4BC 0005841C  38 C1 00 AC */	addi r6, r1, 0xac
/* 8005B4C0 00058420  C0 2D 8E F4 */	lfs f1, lbl_803DDC14@sda21(r13)
/* 8005B4C4 00058424  38 A1 00 A0 */	addi r5, r1, 0xa0
/* 8005B4C8 00058428  C0 0D 8E E8 */	lfs f0, lbl_803DDC08@sda21(r13)
/* 8005B4CC 0005842C  D0 41 00 AC */	stfs f2, 0xac(r1)
/* 8005B4D0 00058430  38 81 00 94 */	addi r4, r1, 0x94
/* 8005B4D4 00058434  C0 4D 8F 04 */	lfs f2, lbl_803DDC24@sda21(r13)
/* 8005B4D8 00058438  38 61 00 14 */	addi r3, r1, 0x14
/* 8005B4DC 0005843C  D0 21 00 A0 */	stfs f1, 0xa0(r1)
/* 8005B4E0 00058440  C0 2D 8E F8 */	lfs f1, lbl_803DDC18@sda21(r13)
/* 8005B4E4 00058444  D0 01 00 94 */	stfs f0, 0x94(r1)
/* 8005B4E8 00058448  C0 0D 8E EC */	lfs f0, lbl_803DDC0C@sda21(r13)
/* 8005B4EC 0005844C  D0 41 00 B0 */	stfs f2, 0xb0(r1)
/* 8005B4F0 00058450  C0 4D 8F 08 */	lfs f2, lbl_803DDC28@sda21(r13)
/* 8005B4F4 00058454  D0 21 00 A4 */	stfs f1, 0xa4(r1)
/* 8005B4F8 00058458  C0 2D 8E FC */	lfs f1, lbl_803DDC1C@sda21(r13)
/* 8005B4FC 0005845C  D0 01 00 98 */	stfs f0, 0x98(r1)
/* 8005B500 00058460  C0 0D 8E F0 */	lfs f0, lbl_803DDC10@sda21(r13)
/* 8005B504 00058464  D0 41 00 B4 */	stfs f2, 0xb4(r1)
/* 8005B508 00058468  D0 21 00 A8 */	stfs f1, 0xa8(r1)
/* 8005B50C 0005846C  D0 01 00 9C */	stfs f0, 0x9c(r1)
/* 8005B510 00058470  4B FE 2B E5 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 8005B514 00058474  38 00 07 00 */	li r0, 0x700
/* 8005B518 00058478  90 1E 00 04 */	stw r0, 4(r30)
/* 8005B51C 0005847C  7F C4 F3 78 */	mr r4, r30
/* 8005B520 00058480  80 7D 00 34 */	lwz r3, 0x34(r29)
/* 8005B524 00058484  81 83 00 04 */	lwz r12, 4(r3)
/* 8005B528 00058488  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8005B52C 0005848C  7D 88 03 A6 */	mtlr r12
/* 8005B530 00058490  4E 80 00 21 */	blrl 
/* 8005B534 00058494  80 DE 03 10 */	lwz r6, 0x310(r30)
/* 8005B538 00058498  38 A1 00 B8 */	addi r5, r1, 0xb8
/* 8005B53C 0005849C  80 1E 03 0C */	lwz r0, 0x30c(r30)
/* 8005B540 000584A0  7F C3 F3 78 */	mr r3, r30
/* 8005B544 000584A4  38 81 00 54 */	addi r4, r1, 0x54
/* 8005B548 000584A8  93 81 00 B8 */	stw r28, 0xb8(r1)
/* 8005B54C 000584AC  93 81 00 BC */	stw r28, 0xbc(r1)
/* 8005B550 000584B0  90 01 00 C0 */	stw r0, 0xc0(r1)
/* 8005B554 000584B4  90 C1 00 C4 */	stw r6, 0xc4(r1)
/* 8005B558 000584B8  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B55C 000584BC  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 8005B560 000584C0  7D 88 03 A6 */	mtlr r12
/* 8005B564 000584C4  4E 80 00 21 */	blrl 
lbl_8005B568:
/* 8005B568 000584C8  80 DE 03 10 */	lwz r6, 0x310(r30)
/* 8005B56C 000584CC  3B 80 00 00 */	li r28, 0
/* 8005B570 000584D0  80 1E 03 0C */	lwz r0, 0x30c(r30)
/* 8005B574 000584D4  38 A1 00 FC */	addi r5, r1, 0xfc
/* 8005B578 000584D8  38 7E 00 00 */	addi r3, r30, 0
/* 8005B57C 000584DC  93 81 00 FC */	stw r28, 0xfc(r1)
/* 8005B580 000584E0  38 81 01 1C */	addi r4, r1, 0x11c
/* 8005B584 000584E4  93 81 01 00 */	stw r28, 0x100(r1)
/* 8005B588 000584E8  90 01 01 04 */	stw r0, 0x104(r1)
/* 8005B58C 000584EC  90 C1 01 08 */	stw r6, 0x108(r1)
/* 8005B590 000584F0  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B594 000584F4  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 8005B598 000584F8  7D 88 03 A6 */	mtlr r12
/* 8005B59C 000584FC  4E 80 00 21 */	blrl 
/* 8005B5A0 00058500  80 DE 03 10 */	lwz r6, 0x310(r30)
/* 8005B5A4 00058504  38 A1 00 EC */	addi r5, r1, 0xec
/* 8005B5A8 00058508  80 1E 03 0C */	lwz r0, 0x30c(r30)
/* 8005B5AC 0005850C  7F C3 F3 78 */	mr r3, r30
/* 8005B5B0 00058510  38 81 01 1C */	addi r4, r1, 0x11c
/* 8005B5B4 00058514  93 81 00 EC */	stw r28, 0xec(r1)
/* 8005B5B8 00058518  93 81 00 F0 */	stw r28, 0xf0(r1)
/* 8005B5BC 0005851C  90 01 00 F4 */	stw r0, 0xf4(r1)
/* 8005B5C0 00058520  90 C1 00 F8 */	stw r6, 0xf8(r1)
/* 8005B5C4 00058524  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 8005B5C8 00058528  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 8005B5CC 0005852C  7D 88 03 A6 */	mtlr r12
/* 8005B5D0 00058530  4E 80 00 21 */	blrl 
/* 8005B5D4 00058534  38 7D 00 00 */	addi r3, r29, 0
/* 8005B5D8 00058538  38 9E 00 00 */	addi r4, r30, 0
/* 8005B5DC 0005853C  4B FF B9 C1 */	bl draw__15BaseGameSectionFR8Graphics
/* 8005B5E0 00058540  88 1D 03 A4 */	lbz r0, 0x3a4(r29)
/* 8005B5E4 00058544  28 00 00 00 */	cmplwi r0, 0
/* 8005B5E8 00058548  40 82 00 68 */	bne lbl_8005B650
/* 8005B5EC 0005854C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005B5F0 00058550  88 03 00 00 */	lbz r0, 0(r3)
/* 8005B5F4 00058554  28 00 00 00 */	cmplwi r0, 0
/* 8005B5F8 00058558  40 82 00 5C */	bne lbl_8005B654
/* 8005B5FC 0005855C  80 1D 00 20 */	lwz r0, 0x20(r29)
/* 8005B600 00058560  28 00 00 00 */	cmplwi r0, 0
/* 8005B604 00058564  41 82 00 14 */	beq lbl_8005B618
/* 8005B608 00058568  80 7F 00 00 */	lwz r3, 0(r31)
/* 8005B60C 0005856C  88 03 01 24 */	lbz r0, 0x124(r3)
/* 8005B610 00058570  28 00 00 00 */	cmplwi r0, 0
/* 8005B614 00058574  41 82 00 40 */	beq lbl_8005B654
lbl_8005B618:
/* 8005B618 00058578  80 1D 00 38 */	lwz r0, 0x38(r29)
/* 8005B61C 0005857C  28 00 00 00 */	cmplwi r0, 0
/* 8005B620 00058580  41 82 00 10 */	beq lbl_8005B630
/* 8005B624 00058584  90 1D 00 34 */	stw r0, 0x34(r29)
/* 8005B628 00058588  38 00 00 00 */	li r0, 0
/* 8005B62C 0005858C  90 1D 00 38 */	stw r0, 0x38(r29)
lbl_8005B630:
/* 8005B630 00058590  80 7D 00 34 */	lwz r3, 0x34(r29)
/* 8005B634 00058594  38 9D 00 3C */	addi r4, r29, 0x3c
/* 8005B638 00058598  81 83 00 04 */	lwz r12, 4(r3)
/* 8005B63C 0005859C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8005B640 000585A0  7D 88 03 A6 */	mtlr r12
/* 8005B644 000585A4  4E 80 00 21 */	blrl 
/* 8005B648 000585A8  90 7D 00 34 */	stw r3, 0x34(r29)
/* 8005B64C 000585AC  48 00 00 08 */	b lbl_8005B654
lbl_8005B650:
/* 8005B650 000585B0  9B 9D 03 A4 */	stb r28, 0x3a4(r29)
lbl_8005B654:
/* 8005B654 000585B4  80 1D 00 38 */	lwz r0, 0x38(r29)
/* 8005B658 000585B8  28 00 00 00 */	cmplwi r0, 0
/* 8005B65C 000585BC  41 82 00 10 */	beq lbl_8005B66C
/* 8005B660 000585C0  90 1D 00 34 */	stw r0, 0x34(r29)
/* 8005B664 000585C4  38 00 00 00 */	li r0, 0
/* 8005B668 000585C8  90 1D 00 38 */	stw r0, 0x38(r29)
lbl_8005B66C:
/* 8005B66C 000585CC  80 01 01 84 */	lwz r0, 0x184(r1)
/* 8005B670 000585D0  83 E1 01 7C */	lwz r31, 0x17c(r1)
/* 8005B674 000585D4  83 C1 01 78 */	lwz r30, 0x178(r1)
/* 8005B678 000585D8  83 A1 01 74 */	lwz r29, 0x174(r1)
/* 8005B67C 000585DC  83 81 01 70 */	lwz r28, 0x170(r1)
/* 8005B680 000585E0  38 21 01 80 */	addi r1, r1, 0x180
/* 8005B684 000585E4  7C 08 03 A6 */	mtlr r0
/* 8005B688 000585E8  4E 80 00 20 */	blr 

.global init__16IntroGameSectionFv
init__16IntroGameSectionFv:
/* 8005B68C 000585EC  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802A7F68:
	.asciz "introGame.cpp"
.balign 4
lbl_802A7F78:
	.asciz "introGame"
.balign 4
lbl_802A7F84:
	.asciz "<IntroGameSection>"
.balign 4
lbl_802A7F98:
	.asciz "CoreNode"
.balign 4
lbl_802A7FA4:
	.4byte __RTTI__5ANode
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
lbl_802A7FCC:
	.asciz "IntroModeState"
.balign 4
lbl_802A7FDC:
	.asciz "ModeState"
.balign 4
lbl_802A7FE8:
	.4byte __RTTI__9ModeState
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__14IntroModeState
__vt__14IntroModeState:
	.4byte __RTTI__14IntroModeState
	.4byte 0
	.4byte update__14IntroModeStateFRUl
	.4byte postRender__14IntroModeStateFR8Graphics
	.4byte postUpdate__9ModeStateFv
.balign 4
lbl_802A8008:
	.asciz "QuittingModeState"
.balign 4
lbl_802A801C:
	.4byte __RTTI__9ModeState
	.4byte 0
	.4byte 0
.global __vt__17QuittingModeState
__vt__17QuittingModeState:
	.4byte __RTTI__17QuittingModeState
	.4byte 0
	.4byte update__17QuittingModeStateFRUl
	.4byte postRender__9ModeStateFR8Graphics
	.4byte postUpdate__17QuittingModeStateFv
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
lbl_802A8050:
	.asciz "IntroGameSetupSection"
.balign 4
lbl_802A8068:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.balign 4
lbl_802A807C:
	.asciz "BaseGameSection"
.balign 4
lbl_802A808C:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
lbl_802A80A8:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__15BaseGameSection
	.4byte 0
	.4byte 0
.global __vt__21IntroGameSetupSection
__vt__21IntroGameSetupSection:
	.4byte __RTTI__21IntroGameSetupSection
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__21IntroGameSetupSectionFv
	.4byte draw__21IntroGameSetupSectionFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte openMenu__15BaseGameSectionFv
.balign 4
lbl_802A8100:
	.asciz "IntroGameSection"
.balign 4
lbl_802A8114:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
lbl_802A8130:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__7Section
	.4byte 0
	.4byte 0
.global __vt__16IntroGameSection
__vt__16IntroGameSection:
	.4byte __RTTI__16IntroGameSection
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__4NodeFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte init__16IntroGameSectionFv
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

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DDC08:
	.float 0.1
lbl_803DDC0C:
	.float 0.1
lbl_803DDC10:
	.float 0.1
lbl_803DDC14:
	.float 0.0
lbl_803DDC18:
	.float 0.0
lbl_803DDC1C:
	.float 0.0
lbl_803DDC20:
	.float 0.0
lbl_803DDC24:
	.float 0.0
lbl_803DDC28:
	.float -5.0
lbl_803DDC2C:
	.float 0.0
lbl_803DDC30:
	.float 0.0
lbl_803DDC34:
	.float 0.0
lbl_803DDC38:
	.float 0.0
lbl_803DDC3C:
	.float 0.0
lbl_803DDC40:
	.float 0.0
.balign 4
lbl_803DDC44:
	.asciz "<Node>"
.balign 4
lbl_803DDC4C:
	.asciz "movie"
.balign 4
lbl_803DDC54:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803DDC54
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802A7F98
	.4byte lbl_802A7FA4
__RTTI__9ModeState:
	.4byte lbl_802A7FDC
	.4byte 0
__RTTI__14IntroModeState:
	.4byte lbl_802A7FCC
	.4byte lbl_802A7FE8
__RTTI__17QuittingModeState:
	.4byte lbl_802A8008
	.4byte lbl_802A801C
.balign 4
lbl_803DDC84:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803DDC84
	.4byte lbl_802A8068
__RTTI__15BaseGameSection:
	.4byte lbl_802A807C
	.4byte lbl_802A808C
__RTTI__21IntroGameSetupSection:
	.4byte lbl_802A8050
	.4byte lbl_802A80A8
.balign 4
lbl_803DDCA4:
	.asciz "Section"
.balign 4
__RTTI__7Section:
	.4byte lbl_803DDCA4
	.4byte lbl_802A8114
__RTTI__16IntroGameSection:
	.4byte lbl_802A8100
	.4byte lbl_802A8130

.section .sbss, "wa"
.balign 8
igss:
	.skip 4

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E87E0:
	.float 60.0
lbl_803E87E4:
	.float 1.0
lbl_803E87E8:
	.float 3.0
lbl_803E87EC:
	.float 100.0
lbl_803E87F0:
	.float 25.0
.balign 8
lbl_803E87F8:
	.4byte 0x43300000
	.4byte 0x80000000
