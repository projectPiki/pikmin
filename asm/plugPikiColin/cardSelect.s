.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__17CardSelectSectionFv, global
/* 8005503C 00051F9C  7C 08 02 A6 */	mflr r0
/* 80055040 00051FA0  3C 80 80 2A */	lis r4, lbl_802A7660@ha
/* 80055044 00051FA4  90 01 00 04 */	stw r0, 4(r1)
/* 80055048 00051FA8  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8005504C 00051FAC  BF 41 00 10 */	stmw r26, 0x10(r1)
/* 80055050 00051FB0  3B E4 76 60 */	addi r31, r4, lbl_802A7660@l
/* 80055054 00051FB4  3B 83 00 00 */	addi r28, r3, 0
/* 80055058 00051FB8  38 8D 8C B0 */	addi r4, r13, lbl_803DD9D0@sda21
/* 8005505C 00051FBC  4B FD FF 5D */	bl __ct__8CoreNodeFPc
/* 80055060 00051FC0  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 80055064 00051FC4  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 80055068 00051FC8  90 1C 00 00 */	stw r0, 0(r28)
/* 8005506C 00051FCC  38 7C 00 00 */	addi r3, r28, 0
/* 80055070 00051FD0  38 8D 8C B0 */	addi r4, r13, lbl_803DD9D0@sda21
/* 80055074 00051FD4  4B FE B6 C9 */	bl init__4NodeFPc
/* 80055078 00051FD8  3C 60 80 2A */	lis r3, __vt__7Section@ha
/* 8005507C 00051FDC  38 03 64 2C */	addi r0, r3, __vt__7Section@l
/* 80055080 00051FE0  3C 60 80 2A */	lis r3, __vt__17CardSelectSection@ha
/* 80055084 00051FE4  90 1C 00 00 */	stw r0, 0(r28)
/* 80055088 00051FE8  38 03 77 B4 */	addi r0, r3, __vt__17CardSelectSection@l
/* 8005508C 00051FEC  90 1C 00 00 */	stw r0, 0(r28)
/* 80055090 00051FF0  38 7C 00 00 */	addi r3, r28, 0
/* 80055094 00051FF4  38 9F 00 1C */	addi r4, r31, 0x1c
/* 80055098 00051FF8  4B FE B6 A5 */	bl init__4NodeFPc
/* 8005509C 00051FFC  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 800550A0 00052000  38 00 00 01 */	li r0, 1
/* 800550A4 00052004  3C 60 80 3A */	lis r3, flowCont@ha
/* 800550A8 00052008  90 04 00 14 */	stw r0, 0x14(r4)
/* 800550AC 0005200C  3B 63 DB 20 */	addi r27, r3, flowCont@l
/* 800550B0 00052010  3B A0 00 00 */	li r29, 0
/* 800550B4 00052014  93 BB 00 A8 */	stw r29, 0xa8(r27)
/* 800550B8 00052018  80 6D 2F 6C */	lwz r3, playerState@sda21(r13)
/* 800550BC 0005201C  48 02 A4 F1 */	bl initGame__11PlayerStateFv
/* 800550C0 00052020  80 6D 30 98 */	lwz r3, generatorCache@sda21(r13)
/* 800550C4 00052024  48 08 9D ED */	bl initGame__14GeneratorCacheFv
/* 800550C8 00052028  3C 60 80 3D */	lis r3, pikiInfMgr@ha
/* 800550CC 0005202C  38 63 1D F0 */	addi r3, r3, pikiInfMgr@l
/* 800550D0 00052030  48 07 06 05 */	bl initGame__10PikiInfMgrFv
/* 800550D4 00052034  83 5B 00 10 */	lwz r26, 0x10(r27)
/* 800550D8 00052038  48 00 00 14 */	b .L_800550EC
.L_800550DC:
/* 800550DC 0005203C  93 BA 00 20 */	stw r29, 0x20(r26)
/* 800550E0 00052040  38 7A 00 2C */	addi r3, r26, 0x2c
/* 800550E4 00052044  48 07 13 31 */	bl initGame__8StageInfFv
/* 800550E8 00052048  83 5A 00 0C */	lwz r26, 0xc(r26)
.L_800550EC:
/* 800550EC 0005204C  28 1A 00 00 */	cmplwi r26, 0
/* 800550F0 00052050  40 82 FF EC */	bne .L_800550DC
/* 800550F4 00052054  3C 60 80 3A */	lis r3, gameflow@ha
/* 800550F8 00052058  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800550FC 0005205C  38 00 00 00 */	li r0, 0
/* 80055100 00052060  98 03 00 B4 */	stb r0, 0xb4(r3)
/* 80055104 00052064  3B A3 02 B4 */	addi r29, r3, 0x2b4
/* 80055108 00052068  98 03 00 B2 */	stb r0, 0xb2(r3)
/* 8005510C 0005206C  80 03 02 B4 */	lwz r0, 0x2b4(r3)
/* 80055110 00052070  2C 00 00 00 */	cmpwi r0, 0
/* 80055114 00052074  40 82 00 10 */	bne .L_80055124
/* 80055118 00052078  38 60 00 02 */	li r3, 2
/* 8005511C 0005207C  38 80 00 00 */	li r4, 0
/* 80055120 00052080  4B FC 47 61 */	bl Jac_SceneSetup
.L_80055124:
/* 80055124 00052084  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80055128 00052088  38 80 00 00 */	li r4, 0
/* 8005512C 0005208C  38 A0 00 01 */	li r5, 1
/* 80055130 00052090  81 83 01 A0 */	lwz r12, 0x1a0(r3)
/* 80055134 00052094  38 C0 00 3C */	li r6, 0x3c
/* 80055138 00052098  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 8005513C 0005209C  7D 88 03 A6 */	mtlr r12
/* 80055140 000520A0  4E 80 00 21 */	blrl 
/* 80055144 000520A4  38 60 00 38 */	li r3, 0x38
/* 80055148 000520A8  4B FF 1E BD */	bl alloc__6SystemFUl
/* 8005514C 000520AC  7C 7E 1B 79 */	or. r30, r3, r3
/* 80055150 000520B0  41 82 00 F0 */	beq .L_80055240
/* 80055154 000520B4  38 7E 00 00 */	addi r3, r30, 0
/* 80055158 000520B8  38 8D 8C B0 */	addi r4, r13, lbl_803DD9D0@sda21
/* 8005515C 000520BC  4B FD FE 5D */	bl __ct__8CoreNodeFPc
/* 80055160 000520C0  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 80055164 000520C4  3B 63 8E 20 */	addi r27, r3, __vt__4Node@l
/* 80055168 000520C8  93 7E 00 00 */	stw r27, 0(r30)
/* 8005516C 000520CC  38 7E 00 00 */	addi r3, r30, 0
/* 80055170 000520D0  38 8D 8C B0 */	addi r4, r13, lbl_803DD9D0@sda21
/* 80055174 000520D4  4B FE B5 C9 */	bl init__4NodeFPc
/* 80055178 000520D8  3C 60 80 2A */	lis r3, __vt__22CardSelectSetupSection@ha
/* 8005517C 000520DC  38 03 77 30 */	addi r0, r3, __vt__22CardSelectSetupSection@l
/* 80055180 000520E0  90 1E 00 00 */	stw r0, 0(r30)
/* 80055184 000520E4  38 7F 00 30 */	addi r3, r31, 0x30
/* 80055188 000520E8  38 00 00 05 */	li r0, 5
/* 8005518C 000520EC  90 7E 00 04 */	stw r3, 4(r30)
/* 80055190 000520F0  38 60 00 50 */	li r3, 0x50
/* 80055194 000520F4  90 1E 00 34 */	stw r0, 0x34(r30)
/* 80055198 000520F8  4B FF 1E 6D */	bl alloc__6SystemFUl
/* 8005519C 000520FC  3B 43 00 00 */	addi r26, r3, 0
/* 800551A0 00052100  7F 40 D3 79 */	or. r0, r26, r26
/* 800551A4 00052104  41 82 00 38 */	beq .L_800551DC
/* 800551A8 00052108  38 7A 00 00 */	addi r3, r26, 0
/* 800551AC 0005210C  38 9F 00 44 */	addi r4, r31, 0x44
/* 800551B0 00052110  4B FD FE 09 */	bl __ct__8CoreNodeFPc
/* 800551B4 00052114  93 7A 00 00 */	stw r27, 0(r26)
/* 800551B8 00052118  38 7A 00 00 */	addi r3, r26, 0
/* 800551BC 0005211C  38 9F 00 44 */	addi r4, r31, 0x44
/* 800551C0 00052120  4B FE B5 7D */	bl init__4NodeFPc
/* 800551C4 00052124  3C 60 80 23 */	lis r3, __vt__10Controller@ha
/* 800551C8 00052128  38 03 8E B4 */	addi r0, r3, __vt__10Controller@l
/* 800551CC 0005212C  90 1A 00 00 */	stw r0, 0(r26)
/* 800551D0 00052130  38 7A 00 00 */	addi r3, r26, 0
/* 800551D4 00052134  38 80 00 01 */	li r4, 1
/* 800551D8 00052138  4B FE B7 D9 */	bl reset__10ControllerFUl
.L_800551DC:
/* 800551DC 0005213C  93 5E 00 30 */	stw r26, 0x30(r30)
/* 800551E0 00052140  38 00 00 00 */	li r0, 0
/* 800551E4 00052144  38 60 00 18 */	li r3, 0x18
/* 800551E8 00052148  90 1E 00 20 */	stw r0, 0x20(r30)
/* 800551EC 0005214C  90 0D 2E 48 */	stw r0, memcardWindow@sda21(r13)
/* 800551F0 00052150  4B FF 1E 15 */	bl alloc__6SystemFUl
/* 800551F4 00052154  3B 43 00 00 */	addi r26, r3, 0
/* 800551F8 00052158  7F 43 D3 79 */	or. r3, r26, r26
/* 800551FC 0005215C  41 82 00 08 */	beq .L_80055204
/* 80055200 00052160  48 13 E3 95 */	bl __ct__Q23zen18ogScrFileChkSelMgrFv
.L_80055204:
/* 80055204 00052164  93 4D 2E 48 */	stw r26, memcardWindow@sda21(r13)
/* 80055208 00052168  80 1D 00 00 */	lwz r0, 0(r29)
/* 8005520C 0005216C  80 6D 2E 48 */	lwz r3, memcardWindow@sda21(r13)
/* 80055210 00052170  7C 80 00 D0 */	neg r4, r0
/* 80055214 00052174  30 04 FF FF */	addic r0, r4, -1
/* 80055218 00052178  7C 00 21 10 */	subfe r0, r0, r4
/* 8005521C 0005217C  54 04 06 3E */	clrlwi r4, r0, 0x18
/* 80055220 00052180  48 13 E4 85 */	bl start__Q23zen18ogScrFileChkSelMgrFb
/* 80055224 00052184  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80055228 00052188  38 00 00 00 */	li r0, 0
/* 8005522C 0005218C  C0 02 85 58 */	lfs f0, lbl_803E8758@sda21(r2)
/* 80055230 00052190  D0 03 00 08 */	stfs f0, 8(r3)
/* 80055234 00052194  C0 02 85 5C */	lfs f0, lbl_803E875C@sda21(r2)
/* 80055238 00052198  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 8005523C 0005219C  90 1E 00 24 */	stw r0, 0x24(r30)
.L_80055240:
/* 80055240 000521A0  38 7C 00 00 */	addi r3, r28, 0
/* 80055244 000521A4  38 9E 00 00 */	addi r4, r30, 0
/* 80055248 000521A8  4B FE B3 91 */	bl add__8CoreNodeFP8CoreNode
/* 8005524C 000521AC  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80055250 000521B0  81 83 01 A0 */	lwz r12, 0x1a0(r3)
/* 80055254 000521B4  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80055258 000521B8  7D 88 03 A6 */	mtlr r12
/* 8005525C 000521BC  4E 80 00 21 */	blrl 
/* 80055260 000521C0  7F 83 E3 78 */	mr r3, r28
/* 80055264 000521C4  BB 41 00 10 */	lmw r26, 0x10(r1)
/* 80055268 000521C8  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8005526C 000521CC  38 21 00 28 */	addi r1, r1, 0x28
/* 80055270 000521D0  7C 08 03 A6 */	mtlr r0
/* 80055274 000521D4  4E 80 00 20 */	blr 
.endfn __ct__17CardSelectSectionFv

.fn update__22CardSelectSetupSectionFv, weak
/* 80055278 000521D8  7C 08 02 A6 */	mflr r0
/* 8005527C 000521DC  90 01 00 04 */	stw r0, 4(r1)
/* 80055280 000521E0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80055284 000521E4  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80055288 000521E8  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8005528C 000521EC  7C 7E 1B 78 */	mr r30, r3
/* 80055290 000521F0  93 A1 00 24 */	stw r29, 0x24(r1)
/* 80055294 000521F4  80 63 00 30 */	lwz r3, 0x30(r3)
/* 80055298 000521F8  81 83 00 00 */	lwz r12, 0(r3)
/* 8005529C 000521FC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800552A0 00052200  7D 88 03 A6 */	mtlr r12
/* 800552A4 00052204  4E 80 00 21 */	blrl 
/* 800552A8 00052208  80 0D 2E 48 */	lwz r0, memcardWindow@sda21(r13)
/* 800552AC 0005220C  28 00 00 00 */	cmplwi r0, 0
/* 800552B0 00052210  40 82 00 2C */	bne .L_800552DC
/* 800552B4 00052214  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 800552B8 00052218  28 00 00 00 */	cmplwi r0, 0
/* 800552BC 0005221C  40 82 00 20 */	bne .L_800552DC
/* 800552C0 00052220  38 00 00 01 */	li r0, 1
/* 800552C4 00052224  90 1E 00 20 */	stw r0, 0x20(r30)
/* 800552C8 00052228  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800552CC 0005222C  C0 02 85 60 */	lfs f0, lbl_803E8760@sda21(r2)
/* 800552D0 00052230  D0 03 00 08 */	stfs f0, 8(r3)
/* 800552D4 00052234  C0 02 85 5C */	lfs f0, lbl_803E875C@sda21(r2)
/* 800552D8 00052238  D0 03 00 0C */	stfs f0, 0xc(r3)
.L_800552DC:
/* 800552DC 0005223C  80 0D 2E 48 */	lwz r0, memcardWindow@sda21(r13)
/* 800552E0 00052240  28 00 00 00 */	cmplwi r0, 0
/* 800552E4 00052244  41 82 00 44 */	beq .L_80055328
/* 800552E8 00052248  3C 60 80 3A */	lis r3, gameflow@ha
/* 800552EC 0005224C  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800552F0 00052250  80 03 02 B4 */	lwz r0, 0x2b4(r3)
/* 800552F4 00052254  2C 00 00 00 */	cmpwi r0, 0
/* 800552F8 00052258  41 82 00 30 */	beq .L_80055328
/* 800552FC 0005225C  80 7E 00 34 */	lwz r3, 0x34(r30)
/* 80055300 00052260  2C 03 00 00 */	cmpwi r3, 0
/* 80055304 00052264  41 82 00 24 */	beq .L_80055328
/* 80055308 00052268  38 03 FF FF */	addi r0, r3, -1
/* 8005530C 0005226C  90 1E 00 34 */	stw r0, 0x34(r30)
/* 80055310 00052270  80 1E 00 34 */	lwz r0, 0x34(r30)
/* 80055314 00052274  2C 00 00 00 */	cmpwi r0, 0
/* 80055318 00052278  40 82 00 10 */	bne .L_80055328
/* 8005531C 0005227C  38 60 00 02 */	li r3, 2
/* 80055320 00052280  38 80 00 00 */	li r4, 0
/* 80055324 00052284  4B FC 45 5D */	bl Jac_SceneSetup
.L_80055328:
/* 80055328 00052288  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 8005532C 0005228C  28 00 00 01 */	cmplwi r0, 1
/* 80055330 00052290  40 82 01 C4 */	bne .L_800554F4
/* 80055334 00052294  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80055338 00052298  C0 22 85 60 */	lfs f1, lbl_803E8760@sda21(r2)
/* 8005533C 0005229C  C0 03 00 04 */	lfs f0, 4(r3)
/* 80055340 000522A0  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80055344 000522A4  40 82 01 B0 */	bne .L_800554F4
/* 80055348 000522A8  3B A0 FF FF */	li r29, -1
/* 8005534C 000522AC  93 BE 00 20 */	stw r29, 0x20(r30)
/* 80055350 000522B0  80 1E 00 24 */	lwz r0, 0x24(r30)
/* 80055354 000522B4  28 00 00 00 */	cmplwi r0, 0
/* 80055358 000522B8  41 82 00 18 */	beq .L_80055370
/* 8005535C 000522BC  3C 60 80 3A */	lis r3, gameflow@ha
/* 80055360 000522C0  54 00 84 3E */	srwi r0, r0, 0x10
/* 80055364 000522C4  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 80055368 000522C8  90 03 01 F4 */	stw r0, 0x1f4(r3)
/* 8005536C 000522CC  48 00 01 70 */	b .L_800554DC
.L_80055370:
/* 80055370 000522D0  3C 60 80 3A */	lis r3, gameflow@ha
/* 80055374 000522D4  3B C3 D7 B8 */	addi r30, r3, gameflow@l
/* 80055378 000522D8  38 9E 02 B4 */	addi r4, r30, 0x2b4
/* 8005537C 000522DC  80 1E 02 B4 */	lwz r0, 0x2b4(r30)
/* 80055380 000522E0  2C 00 00 00 */	cmpwi r0, 0
/* 80055384 000522E4  40 82 00 FC */	bne .L_80055480
/* 80055388 000522E8  3B E0 00 01 */	li r31, 1
/* 8005538C 000522EC  93 FE 02 FC */	stw r31, 0x2fc(r30)
/* 80055390 000522F0  88 1E 00 B2 */	lbz r0, 0xb2(r30)
/* 80055394 000522F4  28 00 00 00 */	cmplwi r0, 0
/* 80055398 000522F8  41 82 00 58 */	beq .L_800553F0
/* 8005539C 000522FC  38 7E 00 24 */	addi r3, r30, 0x24
/* 800553A0 00052300  48 01 F0 C9 */	bl loadCurrentGame__10MemoryCardFv
/* 800553A4 00052304  38 9E 01 C4 */	addi r4, r30, 0x1c4
/* 800553A8 00052308  88 1E 01 C4 */	lbz r0, 0x1c4(r30)
/* 800553AC 0005230C  28 00 00 01 */	cmplwi r0, 1
/* 800553B0 00052310  40 82 00 2C */	bne .L_800553DC
/* 800553B4 00052314  9B E4 00 00 */	stb r31, 0(r4)
/* 800553B8 00052318  38 60 00 00 */	li r3, 0
/* 800553BC 0005231C  38 00 00 02 */	li r0, 2
/* 800553C0 00052320  93 BE 01 C0 */	stw r29, 0x1c0(r30)
/* 800553C4 00052324  93 BE 01 BC */	stw r29, 0x1bc(r30)
/* 800553C8 00052328  93 BE 01 B8 */	stw r29, 0x1b8(r30)
/* 800553CC 0005232C  9B FE 01 C5 */	stb r31, 0x1c5(r30)
/* 800553D0 00052330  98 7E 01 C6 */	stb r3, 0x1c6(r30)
/* 800553D4 00052334  93 FE 01 C8 */	stw r31, 0x1c8(r30)
/* 800553D8 00052338  98 04 00 00 */	stb r0, 0(r4)
.L_800553DC:
/* 800553DC 0005233C  3C 60 80 3A */	lis r3, gameflow@ha
/* 800553E0 00052340  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800553E4 00052344  38 00 00 06 */	li r0, 6
/* 800553E8 00052348  90 03 01 F4 */	stw r0, 0x1f4(r3)
/* 800553EC 0005234C  48 00 00 2C */	b .L_80055418
.L_800553F0:
/* 800553F0 00052350  9B FE 01 C4 */	stb r31, 0x1c4(r30)
/* 800553F4 00052354  38 60 00 00 */	li r3, 0
/* 800553F8 00052358  38 00 00 05 */	li r0, 5
/* 800553FC 0005235C  93 BE 01 C0 */	stw r29, 0x1c0(r30)
/* 80055400 00052360  93 BE 01 BC */	stw r29, 0x1bc(r30)
/* 80055404 00052364  93 BE 01 B8 */	stw r29, 0x1b8(r30)
/* 80055408 00052368  9B FE 01 C5 */	stb r31, 0x1c5(r30)
/* 8005540C 0005236C  98 7E 01 C6 */	stb r3, 0x1c6(r30)
/* 80055410 00052370  93 FE 01 C8 */	stw r31, 0x1c8(r30)
/* 80055414 00052374  90 1E 01 F4 */	stw r0, 0x1f4(r30)
.L_80055418:
/* 80055418 00052378  80 6D 2F 6C */	lwz r3, playerState@sda21(r13)
/* 8005541C 0005237C  48 02 B0 59 */	bl isTutorial__11PlayerStateFv
/* 80055420 00052380  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 80055424 00052384  41 82 00 A4 */	beq .L_800554C8
/* 80055428 00052388  3C 60 80 3A */	lis r3, flowCont@ha
/* 8005542C 0005238C  4C C6 31 82 */	crclr 6
/* 80055430 00052390  3B E3 DB 20 */	addi r31, r3, flowCont@l
/* 80055434 00052394  83 BF 00 10 */	lwz r29, 0x10(r31)
/* 80055438 00052398  38 7F 01 30 */	addi r3, r31, 0x130
/* 8005543C 0005239C  38 8D 8C E8 */	addi r4, r13, lbl_803DDA08@sda21
/* 80055440 000523A0  93 BF 00 A8 */	stw r29, 0xa8(r31)
/* 80055444 000523A4  80 BD 00 18 */	lwz r5, 0x18(r29)
/* 80055448 000523A8  48 1C 11 51 */	bl sprintf
/* 8005544C 000523AC  80 BD 00 18 */	lwz r5, 0x18(r29)
/* 80055450 000523B0  38 7F 01 B0 */	addi r3, r31, 0x1b0
/* 80055454 000523B4  4C C6 31 82 */	crclr 6
/* 80055458 000523B8  38 8D 8C E8 */	addi r4, r13, lbl_803DDA08@sda21
/* 8005545C 000523BC  48 1C 11 3D */	bl sprintf
/* 80055460 000523C0  3C 60 80 3A */	lis r3, gameflow@ha
/* 80055464 000523C4  C0 22 85 64 */	lfs f1, lbl_803E8764@sda21(r2)
/* 80055468 000523C8  3B E3 D7 B8 */	addi r31, r3, gameflow@l
/* 8005546C 000523CC  38 7F 02 D8 */	addi r3, r31, 0x2d8
/* 80055470 000523D0  4B FF C3 AD */	bl setTime__10WorldClockFf
/* 80055474 000523D4  38 00 00 05 */	li r0, 5
/* 80055478 000523D8  90 1F 01 F4 */	stw r0, 0x1f4(r31)
/* 8005547C 000523DC  48 00 00 4C */	b .L_800554C8
.L_80055480:
/* 80055480 000523E0  38 60 00 01 */	li r3, 1
/* 80055484 000523E4  98 7E 01 C4 */	stb r3, 0x1c4(r30)
/* 80055488 000523E8  38 00 00 00 */	li r0, 0
/* 8005548C 000523EC  93 BE 01 C0 */	stw r29, 0x1c0(r30)
/* 80055490 000523F0  93 BE 01 BC */	stw r29, 0x1bc(r30)
/* 80055494 000523F4  93 BE 01 B8 */	stw r29, 0x1b8(r30)
/* 80055498 000523F8  98 7E 01 C5 */	stb r3, 0x1c5(r30)
/* 8005549C 000523FC  98 1E 01 C6 */	stb r0, 0x1c6(r30)
/* 800554A0 00052400  90 7E 01 C8 */	stw r3, 0x1c8(r30)
/* 800554A4 00052404  80 04 00 00 */	lwz r0, 0(r4)
/* 800554A8 00052408  2C 00 00 00 */	cmpwi r0, 0
/* 800554AC 0005240C  41 82 00 0C */	beq .L_800554B8
/* 800554B0 00052410  80 6D 2F 6C */	lwz r3, playerState@sda21(r13)
/* 800554B4 00052414  48 02 A6 ED */	bl setChallengeMode__11PlayerStateFv
.L_800554B8:
/* 800554B8 00052418  3C 60 80 3A */	lis r3, gameflow@ha
/* 800554BC 0005241C  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800554C0 00052420  38 00 00 06 */	li r0, 6
/* 800554C4 00052424  90 03 01 F4 */	stw r0, 0x1f4(r3)
.L_800554C8:
/* 800554C8 00052428  3C 60 80 3A */	lis r3, gameflow@ha
/* 800554CC 0005242C  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800554D0 00052430  38 00 FF FF */	li r0, -1
/* 800554D4 00052434  90 03 01 CC */	stw r0, 0x1cc(r3)
/* 800554D8 00052438  90 03 01 D0 */	stw r0, 0x1d0(r3)
.L_800554DC:
/* 800554DC 0005243C  38 60 00 0D */	li r3, 0xd
/* 800554E0 00052440  38 80 00 00 */	li r4, 0
/* 800554E4 00052444  4B FC 47 FD */	bl Jac_SceneExit
/* 800554E8 00052448  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800554EC 0005244C  38 00 00 01 */	li r0, 1
/* 800554F0 00052450  98 03 00 00 */	stb r0, 0(r3)
.L_800554F4:
/* 800554F4 00052454  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800554F8 00052458  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800554FC 0005245C  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80055500 00052460  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 80055504 00052464  38 21 00 30 */	addi r1, r1, 0x30
/* 80055508 00052468  7C 08 03 A6 */	mtlr r0
/* 8005550C 0005246C  4E 80 00 20 */	blr 
.endfn update__22CardSelectSetupSectionFv

.fn draw__22CardSelectSetupSectionFR8Graphics, weak
/* 80055510 00052470  7C 08 02 A6 */	mflr r0
/* 80055514 00052474  90 01 00 04 */	stw r0, 4(r1)
/* 80055518 00052478  94 21 FF 40 */	stwu r1, -0xc0(r1)
/* 8005551C 0005247C  93 E1 00 BC */	stw r31, 0xbc(r1)
/* 80055520 00052480  7C 9F 23 78 */	mr r31, r4
/* 80055524 00052484  93 C1 00 B8 */	stw r30, 0xb8(r1)
/* 80055528 00052488  7C 7E 1B 78 */	mr r30, r3
/* 8005552C 0005248C  7F E3 FB 78 */	mr r3, r31
/* 80055530 00052490  93 A1 00 B4 */	stw r29, 0xb4(r1)
/* 80055534 00052494  3B A0 00 00 */	li r29, 0
/* 80055538 00052498  80 A4 03 10 */	lwz r5, 0x310(r4)
/* 8005553C 0005249C  80 04 03 0C */	lwz r0, 0x30c(r4)
/* 80055540 000524A0  38 81 00 34 */	addi r4, r1, 0x34
/* 80055544 000524A4  93 A1 00 34 */	stw r29, 0x34(r1)
/* 80055548 000524A8  93 A1 00 38 */	stw r29, 0x38(r1)
/* 8005554C 000524AC  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80055550 000524B0  90 A1 00 40 */	stw r5, 0x40(r1)
/* 80055554 000524B4  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80055558 000524B8  81 8C 00 48 */	lwz r12, 0x48(r12)
/* 8005555C 000524BC  7D 88 03 A6 */	mtlr r12
/* 80055560 000524C0  4E 80 00 21 */	blrl 
/* 80055564 000524C4  80 BF 03 10 */	lwz r5, 0x310(r31)
/* 80055568 000524C8  38 81 00 24 */	addi r4, r1, 0x24
/* 8005556C 000524CC  80 1F 03 0C */	lwz r0, 0x30c(r31)
/* 80055570 000524D0  7F E3 FB 78 */	mr r3, r31
/* 80055574 000524D4  93 A1 00 24 */	stw r29, 0x24(r1)
/* 80055578 000524D8  93 A1 00 28 */	stw r29, 0x28(r1)
/* 8005557C 000524DC  90 01 00 2C */	stw r0, 0x2c(r1)
/* 80055580 000524E0  90 A1 00 30 */	stw r5, 0x30(r1)
/* 80055584 000524E4  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80055588 000524E8  81 8C 00 50 */	lwz r12, 0x50(r12)
/* 8005558C 000524EC  7D 88 03 A6 */	mtlr r12
/* 80055590 000524F0  4E 80 00 21 */	blrl 
/* 80055594 000524F4  9B A1 00 20 */	stb r29, 0x20(r1)
/* 80055598 000524F8  38 81 00 20 */	addi r4, r1, 0x20
/* 8005559C 000524FC  38 7F 00 00 */	addi r3, r31, 0
/* 800555A0 00052500  9B A1 00 21 */	stb r29, 0x21(r1)
/* 800555A4 00052504  9B A1 00 22 */	stb r29, 0x22(r1)
/* 800555A8 00052508  9B A1 00 23 */	stb r29, 0x23(r1)
/* 800555AC 0005250C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800555B0 00052510  81 8C 00 B4 */	lwz r12, 0xb4(r12)
/* 800555B4 00052514  7D 88 03 A6 */	mtlr r12
/* 800555B8 00052518  4E 80 00 21 */	blrl 
/* 800555BC 0005251C  7F E3 FB 78 */	mr r3, r31
/* 800555C0 00052520  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800555C4 00052524  38 80 00 03 */	li r4, 3
/* 800555C8 00052528  38 A0 00 00 */	li r5, 0
/* 800555CC 0005252C  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 800555D0 00052530  7D 88 03 A6 */	mtlr r12
/* 800555D4 00052534  4E 80 00 21 */	blrl 
/* 800555D8 00052538  80 DF 03 10 */	lwz r6, 0x310(r31)
/* 800555DC 0005253C  38 A1 00 10 */	addi r5, r1, 0x10
/* 800555E0 00052540  80 1F 03 0C */	lwz r0, 0x30c(r31)
/* 800555E4 00052544  7F E3 FB 78 */	mr r3, r31
/* 800555E8 00052548  38 81 00 6C */	addi r4, r1, 0x6c
/* 800555EC 0005254C  93 A1 00 10 */	stw r29, 0x10(r1)
/* 800555F0 00052550  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800555F4 00052554  90 01 00 18 */	stw r0, 0x18(r1)
/* 800555F8 00052558  90 C1 00 1C */	stw r6, 0x1c(r1)
/* 800555FC 0005255C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80055600 00052560  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80055604 00052564  7D 88 03 A6 */	mtlr r12
/* 80055608 00052568  4E 80 00 21 */	blrl 
/* 8005560C 0005256C  80 6D 2E 48 */	lwz r3, memcardWindow@sda21(r13)
/* 80055610 00052570  28 03 00 00 */	cmplwi r3, 0
/* 80055614 00052574  41 82 00 D8 */	beq .L_800556EC
/* 80055618 00052578  93 A1 00 4C */	stw r29, 0x4c(r1)
/* 8005561C 0005257C  38 A1 00 44 */	addi r5, r1, 0x44
/* 80055620 00052580  80 9E 00 30 */	lwz r4, 0x30(r30)
/* 80055624 00052584  48 13 E1 25 */	bl update__Q23zen18ogScrFileChkSelMgrFP10ControllerR13CardQuickInfo
/* 80055628 00052588  2C 03 00 01 */	cmpwi r3, 1
/* 8005562C 0005258C  41 80 00 AC */	blt .L_800556D8
/* 80055630 00052590  93 AD 2E 48 */	stw r29, memcardWindow@sda21(r13)
/* 80055634 00052594  40 82 00 2C */	bne .L_80055660
/* 80055638 00052598  3C 00 00 0B */	lis r0, 0xb
/* 8005563C 0005259C  90 1E 00 24 */	stw r0, 0x24(r30)
/* 80055640 000525A0  38 00 00 01 */	li r0, 1
/* 80055644 000525A4  90 1E 00 20 */	stw r0, 0x20(r30)
/* 80055648 000525A8  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 8005564C 000525AC  C0 02 85 60 */	lfs f0, lbl_803E8760@sda21(r2)
/* 80055650 000525B0  D0 03 00 08 */	stfs f0, 8(r3)
/* 80055654 000525B4  C0 02 85 5C */	lfs f0, lbl_803E875C@sda21(r2)
/* 80055658 000525B8  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 8005565C 000525BC  48 00 00 7C */	b .L_800556D8
.L_80055660:
/* 80055660 000525C0  2C 03 00 05 */	cmpwi r3, 5
/* 80055664 000525C4  40 82 00 28 */	bne .L_8005568C
/* 80055668 000525C8  93 BE 00 24 */	stw r29, 0x24(r30)
/* 8005566C 000525CC  38 00 00 01 */	li r0, 1
/* 80055670 000525D0  90 1E 00 20 */	stw r0, 0x20(r30)
/* 80055674 000525D4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80055678 000525D8  C0 02 85 60 */	lfs f0, lbl_803E8760@sda21(r2)
/* 8005567C 000525DC  D0 03 00 08 */	stfs f0, 8(r3)
/* 80055680 000525E0  C0 02 85 5C */	lfs f0, lbl_803E875C@sda21(r2)
/* 80055684 000525E4  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 80055688 000525E8  48 00 00 50 */	b .L_800556D8
.L_8005568C:
/* 8005568C 000525EC  3C 80 80 3A */	lis r4, gameflow@ha
/* 80055690 000525F0  38 84 D7 B8 */	addi r4, r4, gameflow@l
/* 80055694 000525F4  38 A0 00 01 */	li r5, 1
/* 80055698 000525F8  98 A4 00 B2 */	stb r5, 0xb2(r4)
/* 8005569C 000525FC  38 03 FF FE */	addi r0, r3, -2
/* 800556A0 00052600  80 61 00 68 */	lwz r3, 0x68(r1)
/* 800556A4 00052604  90 64 01 A0 */	stw r3, 0x1a0(r4)
/* 800556A8 00052608  90 04 01 9C */	stw r0, 0x19c(r4)
/* 800556AC 0005260C  80 61 00 44 */	lwz r3, 0x44(r1)
/* 800556B0 00052610  38 03 00 01 */	addi r0, r3, 1
/* 800556B4 00052614  98 04 00 B4 */	stb r0, 0xb4(r4)
/* 800556B8 00052618  80 01 00 50 */	lwz r0, 0x50(r1)
/* 800556BC 0005261C  90 04 02 FC */	stw r0, 0x2fc(r4)
/* 800556C0 00052620  90 BE 00 20 */	stw r5, 0x20(r30)
/* 800556C4 00052624  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800556C8 00052628  C0 02 85 60 */	lfs f0, lbl_803E8760@sda21(r2)
/* 800556CC 0005262C  D0 03 00 08 */	stfs f0, 8(r3)
/* 800556D0 00052630  C0 02 85 5C */	lfs f0, lbl_803E875C@sda21(r2)
/* 800556D4 00052634  D0 03 00 0C */	stfs f0, 0xc(r3)
.L_800556D8:
/* 800556D8 00052638  80 6D 2E 48 */	lwz r3, memcardWindow@sda21(r13)
/* 800556DC 0005263C  28 03 00 00 */	cmplwi r3, 0
/* 800556E0 00052640  41 82 00 0C */	beq .L_800556EC
/* 800556E4 00052644  7F E4 FB 78 */	mr r4, r31
/* 800556E8 00052648  48 13 E1 F9 */	bl draw__Q23zen18ogScrFileChkSelMgrFR8Graphics
.L_800556EC:
/* 800556EC 0005264C  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 800556F0 00052650  83 E1 00 BC */	lwz r31, 0xbc(r1)
/* 800556F4 00052654  83 C1 00 B8 */	lwz r30, 0xb8(r1)
/* 800556F8 00052658  83 A1 00 B4 */	lwz r29, 0xb4(r1)
/* 800556FC 0005265C  38 21 00 C0 */	addi r1, r1, 0xc0
/* 80055700 00052660  7C 08 03 A6 */	mtlr r0
/* 80055704 00052664  4E 80 00 20 */	blr 
.endfn draw__22CardSelectSetupSectionFR8Graphics

.fn init__17CardSelectSectionFv, weak
/* 80055708 00052668  4E 80 00 20 */	blr 
.endfn init__17CardSelectSectionFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802A7660, local
	.asciz "cardSelect.cpp"
.endobj lbl_802A7660
.balign 4
.obj lbl_802A7670, local
	.asciz "CardSelect"
.endobj lbl_802A7670
.balign 4
.obj lbl_802A767C, local
	.asciz "<CardSelectSection>"
.endobj lbl_802A767C
.balign 4
.obj lbl_802A7690, local
	.asciz "CardSelect section"
.endobj lbl_802A7690
.balign 4
.obj lbl_802A76A4, local
	.asciz "<Controller>"
.endobj lbl_802A76A4
.balign 4
.obj lbl_802A76B4, local
	.asciz "CoreNode"
.endobj lbl_802A76B4
.balign 4
.obj lbl_802A76C0, local
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802A76C0
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
.obj lbl_802A76E8, local
	.asciz "CardSelectSetupSection"
.endobj lbl_802A76E8
.balign 4
.obj lbl_802A7700, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.endobj lbl_802A7700
.obj lbl_802A7714, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.endobj lbl_802A7714
.obj __vt__22CardSelectSetupSection, weak
	.4byte __RTTI__22CardSelectSetupSection
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__22CardSelectSetupSectionFv
	.4byte draw__22CardSelectSetupSectionFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
.endobj __vt__22CardSelectSetupSection
.balign 4
.obj lbl_802A7760, local
	.asciz "CardSelectSection"
.endobj lbl_802A7760
.balign 4
.obj lbl_802A7774, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.endobj lbl_802A7774
.obj lbl_802A7790, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__7Section
	.4byte 0
	.4byte 0
.endobj lbl_802A7790
.obj __vt__17CardSelectSection, weak
	.4byte __RTTI__17CardSelectSection
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
	.4byte init__17CardSelectSectionFv
.endobj __vt__17CardSelectSection
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
.obj lbl_803DD9D0, local
	.asciz "<Node>"
.endobj lbl_803DD9D0
.balign 4
.obj lbl_803DD9D8, local
	.asciz "ANode"
.endobj lbl_803DD9D8
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803DD9D8
	.4byte 0
.endobj __RTTI__5ANode
.obj __RTTI__8CoreNode, local
	.4byte lbl_802A76B4
	.4byte lbl_802A76C0
.endobj __RTTI__8CoreNode
.balign 4
.obj lbl_803DD9F0, local
	.asciz "Node"
.endobj lbl_803DD9F0
.balign 4
.obj __RTTI__4Node, local
	.4byte lbl_803DD9F0
	.4byte lbl_802A7700
.endobj __RTTI__4Node
.obj __RTTI__22CardSelectSetupSection, local
	.4byte lbl_802A76E8
	.4byte lbl_802A7714
.endobj __RTTI__22CardSelectSetupSection
.balign 4
.obj lbl_803DDA08, local
	.asciz "%s"
.endobj lbl_803DDA08
.balign 4
.obj lbl_803DDA0C, local
	.asciz "Section"
.endobj lbl_803DDA0C
.balign 4
.obj __RTTI__7Section, local
	.4byte lbl_803DDA0C
	.4byte lbl_802A7774
.endobj __RTTI__7Section
.obj __RTTI__17CardSelectSection, local
	.4byte lbl_802A7760
	.4byte lbl_802A7790
.endobj __RTTI__17CardSelectSection

.section .sbss, "wa"
.balign 8
.obj memcardWindow, local
	.skip 4
.endobj memcardWindow

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E8758, local
	.float 1.0
.endobj lbl_803E8758
.obj lbl_803E875C, local
	.float 3.0
.endobj lbl_803E875C
.obj lbl_803E8760, local
	.float 0.0
.endobj lbl_803E8760
.obj lbl_803E8764, local
	.float 14.8
.endobj lbl_803E8764
