.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn init__14NinLogoSectionFv, global
/* 80061250 0005E1B0  7C 08 02 A6 */	mflr r0
/* 80061254 0005E1B4  3C 80 80 2B */	lis r4, lbl_802A8BF8@ha
/* 80061258 0005E1B8  90 01 00 04 */	stw r0, 4(r1)
/* 8006125C 0005E1BC  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80061260 0005E1C0  BF 61 00 14 */	stmw r27, 0x14(r1)
/* 80061264 0005E1C4  3B 84 8B F8 */	addi r28, r4, lbl_802A8BF8@l
/* 80061268 0005E1C8  3B C3 00 00 */	addi r30, r3, 0
/* 8006126C 0005E1CC  38 9C 00 0C */	addi r4, r28, 0xc
/* 80061270 0005E1D0  4B FD F4 CD */	bl init__4NodeFPc
/* 80061274 0005E1D4  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80061278 0005E1D8  38 00 00 00 */	li r0, 0
/* 8006127C 0005E1DC  38 60 00 50 */	li r3, 0x50
/* 80061280 0005E1E0  90 04 00 18 */	stw r0, 0x18(r4)
/* 80061284 0005E1E4  4B FE 5D 81 */	bl alloc__6SystemFUl
/* 80061288 0005E1E8  7C 7F 1B 79 */	or. r31, r3, r3
/* 8006128C 0005E1EC  41 82 01 24 */	beq .L_800613B0
/* 80061290 0005E1F0  38 7F 00 00 */	addi r3, r31, 0
/* 80061294 0005E1F4  38 8D 92 98 */	addi r4, r13, lbl_803DDFB8@sda21
/* 80061298 0005E1F8  4B FD 3D 21 */	bl __ct__8CoreNodeFPc
/* 8006129C 0005E1FC  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 800612A0 0005E200  3B A3 8E 20 */	addi r29, r3, __vt__4Node@l
/* 800612A4 0005E204  93 BF 00 00 */	stw r29, 0(r31)
/* 800612A8 0005E208  38 7F 00 00 */	addi r3, r31, 0
/* 800612AC 0005E20C  38 8D 92 98 */	addi r4, r13, lbl_803DDFB8@sda21
/* 800612B0 0005E210  4B FD F4 8D */	bl init__4NodeFPc
/* 800612B4 0005E214  3C 60 80 2B */	lis r3, __vt__19NinLogoSetupSection@ha
/* 800612B8 0005E218  38 03 8C B0 */	addi r0, r3, __vt__19NinLogoSetupSection@l
/* 800612BC 0005E21C  90 1F 00 00 */	stw r0, 0(r31)
/* 800612C0 0005E220  38 1C 00 20 */	addi r0, r28, 0x20
/* 800612C4 0005E224  38 60 00 50 */	li r3, 0x50
/* 800612C8 0005E228  90 1F 00 04 */	stw r0, 4(r31)
/* 800612CC 0005E22C  4B FE 5D 39 */	bl alloc__6SystemFUl
/* 800612D0 0005E230  3B 63 00 00 */	addi r27, r3, 0
/* 800612D4 0005E234  7F 60 DB 79 */	or. r0, r27, r27
/* 800612D8 0005E238  41 82 00 38 */	beq .L_80061310
/* 800612DC 0005E23C  38 7B 00 00 */	addi r3, r27, 0
/* 800612E0 0005E240  38 9C 00 30 */	addi r4, r28, 0x30
/* 800612E4 0005E244  4B FD 3C D5 */	bl __ct__8CoreNodeFPc
/* 800612E8 0005E248  93 BB 00 00 */	stw r29, 0(r27)
/* 800612EC 0005E24C  38 7B 00 00 */	addi r3, r27, 0
/* 800612F0 0005E250  38 9C 00 30 */	addi r4, r28, 0x30
/* 800612F4 0005E254  4B FD F4 49 */	bl init__4NodeFPc
/* 800612F8 0005E258  3C 60 80 23 */	lis r3, __vt__10Controller@ha
/* 800612FC 0005E25C  38 03 8E B4 */	addi r0, r3, __vt__10Controller@l
/* 80061300 0005E260  90 1B 00 00 */	stw r0, 0(r27)
/* 80061304 0005E264  38 7B 00 00 */	addi r3, r27, 0
/* 80061308 0005E268  38 80 00 01 */	li r4, 1
/* 8006130C 0005E26C  4B FD F6 A5 */	bl reset__10ControllerFUl
.L_80061310:
/* 80061310 0005E270  93 7F 00 28 */	stw r27, 0x28(r31)
/* 80061314 0005E274  38 00 00 00 */	li r0, 0
/* 80061318 0005E278  90 0D 2E F8 */	stw r0, progresWindow@sda21(r13)
/* 8006131C 0005E27C  48 1A 28 75 */	bl VIGetDTVStatus
/* 80061320 0005E280  28 03 00 00 */	cmplwi r3, 0
/* 80061324 0005E284  41 82 00 10 */	beq .L_80061334
/* 80061328 0005E288  48 19 9B 5D */	bl OSGetProgressiveMode
/* 8006132C 0005E28C  28 03 00 00 */	cmplwi r3, 0
/* 80061330 0005E290  40 82 00 30 */	bne .L_80061360
.L_80061334:
/* 80061334 0005E294  48 1A 28 5D */	bl VIGetDTVStatus
/* 80061338 0005E298  28 03 00 00 */	cmplwi r3, 0
/* 8006133C 0005E29C  41 82 00 48 */	beq .L_80061384
/* 80061340 0005E2A0  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80061344 0005E2A4  38 80 02 00 */	li r4, 0x200
/* 80061348 0005E2A8  85 83 02 7C */	lwzu r12, 0x27c(r3)
/* 8006134C 0005E2AC  81 8C 00 08 */	lwz r12, 8(r12)
/* 80061350 0005E2B0  7D 88 03 A6 */	mtlr r12
/* 80061354 0005E2B4  4E 80 00 21 */	blrl 
/* 80061358 0005E2B8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8006135C 0005E2BC  41 82 00 28 */	beq .L_80061384
.L_80061360:
/* 80061360 0005E2C0  38 60 00 10 */	li r3, 0x10
/* 80061364 0005E2C4  4B FE 5C A1 */	bl alloc__6SystemFUl
/* 80061368 0005E2C8  3B 63 00 00 */	addi r27, r3, 0
/* 8006136C 0005E2CC  7F 63 DB 79 */	or. r3, r27, r27
/* 80061370 0005E2D0  41 82 00 08 */	beq .L_80061378
/* 80061374 0005E2D4  48 17 8E DD */	bl __ct__Q23zen10DrawProgreFv
.L_80061378:
/* 80061378 0005E2D8  93 6D 2E F8 */	stw r27, progresWindow@sda21(r13)
/* 8006137C 0005E2DC  80 6D 2E F8 */	lwz r3, progresWindow@sda21(r13)
/* 80061380 0005E2E0  48 17 91 5D */	bl start__Q23zen10DrawProgreFv
.L_80061384:
/* 80061384 0005E2E4  38 00 00 00 */	li r0, 0
/* 80061388 0005E2E8  3C 60 80 3A */	lis r3, gameflow@ha
/* 8006138C 0005E2EC  90 1F 00 2C */	stw r0, 0x2c(r31)
/* 80061390 0005E2F0  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 80061394 0005E2F4  38 00 00 01 */	li r0, 1
/* 80061398 0005E2F8  98 03 00 B2 */	stb r0, 0xb2(r3)
/* 8006139C 0005E2FC  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800613A0 0005E300  C0 02 87 38 */	lfs f0, lbl_803E8938@sda21(r2)
/* 800613A4 0005E304  D0 03 00 08 */	stfs f0, 8(r3)
/* 800613A8 0005E308  C0 02 87 3C */	lfs f0, lbl_803E893C@sda21(r2)
/* 800613AC 0005E30C  D0 03 00 0C */	stfs f0, 0xc(r3)
.L_800613B0:
/* 800613B0 0005E310  38 7E 00 00 */	addi r3, r30, 0
/* 800613B4 0005E314  38 9F 00 00 */	addi r4, r31, 0
/* 800613B8 0005E318  4B FD F2 21 */	bl add__8CoreNodeFP8CoreNode
/* 800613BC 0005E31C  BB 61 00 14 */	lmw r27, 0x14(r1)
/* 800613C0 0005E320  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800613C4 0005E324  38 21 00 28 */	addi r1, r1, 0x28
/* 800613C8 0005E328  7C 08 03 A6 */	mtlr r0
/* 800613CC 0005E32C  4E 80 00 20 */	blr 
.endfn init__14NinLogoSectionFv

.fn update__19NinLogoSetupSectionFv, weak
/* 800613D0 0005E330  7C 08 02 A6 */	mflr r0
/* 800613D4 0005E334  90 01 00 04 */	stw r0, 4(r1)
/* 800613D8 0005E338  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800613DC 0005E33C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800613E0 0005E340  7C 7F 1B 78 */	mr r31, r3
/* 800613E4 0005E344  80 63 00 28 */	lwz r3, 0x28(r3)
/* 800613E8 0005E348  81 83 00 00 */	lwz r12, 0(r3)
/* 800613EC 0005E34C  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800613F0 0005E350  7D 88 03 A6 */	mtlr r12
/* 800613F4 0005E354  4E 80 00 21 */	blrl 
/* 800613F8 0005E358  80 7F 00 2C */	lwz r3, 0x2c(r31)
/* 800613FC 0005E35C  28 03 00 00 */	cmplwi r3, 0
/* 80061400 0005E360  41 82 00 20 */	beq .L_80061420
/* 80061404 0005E364  81 83 00 00 */	lwz r12, 0(r3)
/* 80061408 0005E368  38 80 00 00 */	li r4, 0
/* 8006140C 0005E36C  81 8C 00 50 */	lwz r12, 0x50(r12)
/* 80061410 0005E370  7D 88 03 A6 */	mtlr r12
/* 80061414 0005E374  4E 80 00 21 */	blrl 
/* 80061418 0005E378  90 7F 00 2C */	stw r3, 0x2c(r31)
/* 8006141C 0005E37C  48 00 00 90 */	b .L_800614AC
.L_80061420:
/* 80061420 0005E380  80 6D 2E F8 */	lwz r3, progresWindow@sda21(r13)
/* 80061424 0005E384  28 03 00 00 */	cmplwi r3, 0
/* 80061428 0005E388  41 82 00 6C */	beq .L_80061494
/* 8006142C 0005E38C  80 9F 00 28 */	lwz r4, 0x28(r31)
/* 80061430 0005E390  48 17 90 FD */	bl update__Q23zen10DrawProgreFP10Controller
/* 80061434 0005E394  2C 03 00 01 */	cmpwi r3, 1
/* 80061438 0005E398  40 82 00 40 */	bne .L_80061478
/* 8006143C 0005E39C  38 60 00 01 */	li r3, 1
/* 80061440 0005E3A0  48 19 9A C5 */	bl OSSetProgressiveMode
/* 80061444 0005E3A4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80061448 0005E3A8  38 00 00 01 */	li r0, 1
/* 8006144C 0005E3AC  80 63 02 4C */	lwz r3, 0x24c(r3)
/* 80061450 0005E3B0  90 03 00 00 */	stw r0, 0(r3)
/* 80061454 0005E3B4  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80061458 0005E3B8  80 63 02 4C */	lwz r3, 0x24c(r3)
/* 8006145C 0005E3BC  81 83 03 B4 */	lwz r12, 0x3b4(r3)
/* 80061460 0005E3C0  81 8C 00 08 */	lwz r12, 8(r12)
/* 80061464 0005E3C4  7D 88 03 A6 */	mtlr r12
/* 80061468 0005E3C8  4E 80 00 21 */	blrl 
/* 8006146C 0005E3CC  38 00 00 00 */	li r0, 0
/* 80061470 0005E3D0  90 0D 2E F8 */	stw r0, progresWindow@sda21(r13)
/* 80061474 0005E3D4  48 00 00 38 */	b .L_800614AC
.L_80061478:
/* 80061478 0005E3D8  2C 03 00 02 */	cmpwi r3, 2
/* 8006147C 0005E3DC  40 82 00 30 */	bne .L_800614AC
/* 80061480 0005E3E0  38 60 00 00 */	li r3, 0
/* 80061484 0005E3E4  48 19 9A 81 */	bl OSSetProgressiveMode
/* 80061488 0005E3E8  38 00 00 00 */	li r0, 0
/* 8006148C 0005E3EC  90 0D 2E F8 */	stw r0, progresWindow@sda21(r13)
/* 80061490 0005E3F0  48 00 00 1C */	b .L_800614AC
.L_80061494:
/* 80061494 0005E3F4  3C 60 80 3A */	lis r3, gameflow@ha
/* 80061498 0005E3F8  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 8006149C 0005E3FC  38 00 00 01 */	li r0, 1
/* 800614A0 0005E400  90 03 01 F0 */	stw r0, 0x1f0(r3)
/* 800614A4 0005E404  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 800614A8 0005E408  98 03 00 00 */	stb r0, 0(r3)
.L_800614AC:
/* 800614AC 0005E40C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800614B0 0005E410  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800614B4 0005E414  38 21 00 18 */	addi r1, r1, 0x18
/* 800614B8 0005E418  7C 08 03 A6 */	mtlr r0
/* 800614BC 0005E41C  4E 80 00 20 */	blr 
.endfn update__19NinLogoSetupSectionFv

.fn draw__19NinLogoSetupSectionFR8Graphics, weak
/* 800614C0 0005E420  7C 08 02 A6 */	mflr r0
/* 800614C4 0005E424  90 01 00 04 */	stw r0, 4(r1)
/* 800614C8 0005E428  94 21 FE 58 */	stwu r1, -0x1a8(r1)
/* 800614CC 0005E42C  BF 61 01 94 */	stmw r27, 0x194(r1)
/* 800614D0 0005E430  3B 60 00 00 */	li r27, 0
/* 800614D4 0005E434  7C 9F 23 78 */	mr r31, r4
/* 800614D8 0005E438  7C 7E 1B 78 */	mr r30, r3
/* 800614DC 0005E43C  7F E3 FB 78 */	mr r3, r31
/* 800614E0 0005E440  80 A4 03 10 */	lwz r5, 0x310(r4)
/* 800614E4 0005E444  80 04 03 0C */	lwz r0, 0x30c(r4)
/* 800614E8 0005E448  38 81 00 3C */	addi r4, r1, 0x3c
/* 800614EC 0005E44C  93 61 00 3C */	stw r27, 0x3c(r1)
/* 800614F0 0005E450  93 61 00 40 */	stw r27, 0x40(r1)
/* 800614F4 0005E454  90 01 00 44 */	stw r0, 0x44(r1)
/* 800614F8 0005E458  90 A1 00 48 */	stw r5, 0x48(r1)
/* 800614FC 0005E45C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80061500 0005E460  81 8C 00 48 */	lwz r12, 0x48(r12)
/* 80061504 0005E464  7D 88 03 A6 */	mtlr r12
/* 80061508 0005E468  4E 80 00 21 */	blrl 
/* 8006150C 0005E46C  80 BF 03 10 */	lwz r5, 0x310(r31)
/* 80061510 0005E470  38 81 00 2C */	addi r4, r1, 0x2c
/* 80061514 0005E474  80 1F 03 0C */	lwz r0, 0x30c(r31)
/* 80061518 0005E478  7F E3 FB 78 */	mr r3, r31
/* 8006151C 0005E47C  93 61 00 2C */	stw r27, 0x2c(r1)
/* 80061520 0005E480  93 61 00 30 */	stw r27, 0x30(r1)
/* 80061524 0005E484  90 01 00 34 */	stw r0, 0x34(r1)
/* 80061528 0005E488  90 A1 00 38 */	stw r5, 0x38(r1)
/* 8006152C 0005E48C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80061530 0005E490  81 8C 00 50 */	lwz r12, 0x50(r12)
/* 80061534 0005E494  7D 88 03 A6 */	mtlr r12
/* 80061538 0005E498  4E 80 00 21 */	blrl 
/* 8006153C 0005E49C  9B 61 00 28 */	stb r27, 0x28(r1)
/* 80061540 0005E4A0  38 81 00 28 */	addi r4, r1, 0x28
/* 80061544 0005E4A4  38 7F 00 00 */	addi r3, r31, 0
/* 80061548 0005E4A8  9B 61 00 29 */	stb r27, 0x29(r1)
/* 8006154C 0005E4AC  9B 61 00 2A */	stb r27, 0x2a(r1)
/* 80061550 0005E4B0  9B 61 00 2B */	stb r27, 0x2b(r1)
/* 80061554 0005E4B4  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80061558 0005E4B8  81 8C 00 B4 */	lwz r12, 0xb4(r12)
/* 8006155C 0005E4BC  7D 88 03 A6 */	mtlr r12
/* 80061560 0005E4C0  4E 80 00 21 */	blrl 
/* 80061564 0005E4C4  7F E3 FB 78 */	mr r3, r31
/* 80061568 0005E4C8  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 8006156C 0005E4CC  38 80 00 03 */	li r4, 3
/* 80061570 0005E4D0  38 A0 00 00 */	li r5, 0
/* 80061574 0005E4D4  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80061578 0005E4D8  7D 88 03 A6 */	mtlr r12
/* 8006157C 0005E4DC  4E 80 00 21 */	blrl 
/* 80061580 0005E4E0  80 DF 03 10 */	lwz r6, 0x310(r31)
/* 80061584 0005E4E4  38 A1 00 18 */	addi r5, r1, 0x18
/* 80061588 0005E4E8  80 1F 03 0C */	lwz r0, 0x30c(r31)
/* 8006158C 0005E4EC  7F E3 FB 78 */	mr r3, r31
/* 80061590 0005E4F0  38 81 01 4C */	addi r4, r1, 0x14c
/* 80061594 0005E4F4  93 61 00 18 */	stw r27, 0x18(r1)
/* 80061598 0005E4F8  93 61 00 1C */	stw r27, 0x1c(r1)
/* 8006159C 0005E4FC  90 01 00 20 */	stw r0, 0x20(r1)
/* 800615A0 0005E500  90 C1 00 24 */	stw r6, 0x24(r1)
/* 800615A4 0005E504  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800615A8 0005E508  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 800615AC 0005E50C  7D 88 03 A6 */	mtlr r12
/* 800615B0 0005E510  4E 80 00 21 */	blrl 
/* 800615B4 0005E514  3B 80 00 FF */	li r28, 0xff
/* 800615B8 0005E518  9B 81 00 14 */	stb r28, 0x14(r1)
/* 800615BC 0005E51C  3B A0 00 40 */	li r29, 0x40
/* 800615C0 0005E520  38 81 00 14 */	addi r4, r1, 0x14
/* 800615C4 0005E524  9B 81 00 15 */	stb r28, 0x15(r1)
/* 800615C8 0005E528  7F E3 FB 78 */	mr r3, r31
/* 800615CC 0005E52C  38 A0 00 01 */	li r5, 1
/* 800615D0 0005E530  9B A1 00 16 */	stb r29, 0x16(r1)
/* 800615D4 0005E534  9B 81 00 17 */	stb r28, 0x17(r1)
/* 800615D8 0005E538  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 800615DC 0005E53C  81 8C 00 A8 */	lwz r12, 0xa8(r12)
/* 800615E0 0005E540  7D 88 03 A6 */	mtlr r12
/* 800615E4 0005E544  4E 80 00 21 */	blrl 
/* 800615E8 0005E548  9B 81 00 10 */	stb r28, 0x10(r1)
/* 800615EC 0005E54C  38 81 00 10 */	addi r4, r1, 0x10
/* 800615F0 0005E550  38 7F 00 00 */	addi r3, r31, 0
/* 800615F4 0005E554  9B 61 00 11 */	stb r27, 0x11(r1)
/* 800615F8 0005E558  9B A1 00 12 */	stb r29, 0x12(r1)
/* 800615FC 0005E55C  9B 81 00 13 */	stb r28, 0x13(r1)
/* 80061600 0005E560  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 80061604 0005E564  81 8C 00 AC */	lwz r12, 0xac(r12)
/* 80061608 0005E568  7D 88 03 A6 */	mtlr r12
/* 8006160C 0005E56C  4E 80 00 21 */	blrl 
/* 80061610 0005E570  83 7E 00 2C */	lwz r27, 0x2c(r30)
/* 80061614 0005E574  28 1B 00 00 */	cmplwi r27, 0
/* 80061618 0005E578  41 82 00 78 */	beq .L_80061690
/* 8006161C 0005E57C  80 1B 00 3C */	lwz r0, 0x3c(r27)
/* 80061620 0005E580  2C 00 00 00 */	cmpwi r0, 0
/* 80061624 0005E584  41 82 00 58 */	beq .L_8006167C
/* 80061628 0005E588  83 9B 00 20 */	lwz r28, 0x20(r27)
/* 8006162C 0005E58C  80 1C 00 3C */	lwz r0, 0x3c(r28)
/* 80061630 0005E590  2C 00 00 00 */	cmpwi r0, 0
/* 80061634 0005E594  41 82 00 38 */	beq .L_8006166C
/* 80061638 0005E598  83 BC 00 20 */	lwz r29, 0x20(r28)
/* 8006163C 0005E59C  80 1D 00 3C */	lwz r0, 0x3c(r29)
/* 80061640 0005E5A0  2C 00 00 00 */	cmpwi r0, 0
/* 80061644 0005E5A4  41 82 00 18 */	beq .L_8006165C
/* 80061648 0005E5A8  80 BD 00 20 */	lwz r5, 0x20(r29)
/* 8006164C 0005E5AC  7F C3 F3 78 */	mr r3, r30
/* 80061650 0005E5B0  C0 22 87 40 */	lfs f1, lbl_803E8940@sda21(r2)
/* 80061654 0005E5B4  7F E4 FB 78 */	mr r4, r31
/* 80061658 0005E5B8  48 00 00 7D */	bl drawMenu__19NinLogoSetupSectionFR8GraphicsP4Menuf
.L_8006165C:
/* 8006165C 0005E5BC  C0 22 87 44 */	lfs f1, lbl_803E8944@sda21(r2)
/* 80061660 0005E5C0  38 7D 00 00 */	addi r3, r29, 0
/* 80061664 0005E5C4  38 9F 00 00 */	addi r4, r31, 0
/* 80061668 0005E5C8  4B FF CD A9 */	bl draw__4MenuFR8Graphicsf
.L_8006166C:
/* 8006166C 0005E5CC  C0 22 87 48 */	lfs f1, lbl_803E8948@sda21(r2)
/* 80061670 0005E5D0  38 7C 00 00 */	addi r3, r28, 0
/* 80061674 0005E5D4  38 9F 00 00 */	addi r4, r31, 0
/* 80061678 0005E5D8  4B FF CD 99 */	bl draw__4MenuFR8Graphicsf
.L_8006167C:
/* 8006167C 0005E5DC  C0 22 87 38 */	lfs f1, lbl_803E8938@sda21(r2)
/* 80061680 0005E5E0  38 7B 00 00 */	addi r3, r27, 0
/* 80061684 0005E5E4  38 9F 00 00 */	addi r4, r31, 0
/* 80061688 0005E5E8  4B FF CD 89 */	bl draw__4MenuFR8Graphicsf
/* 8006168C 0005E5EC  48 00 00 18 */	b .L_800616A4
.L_80061690:
/* 80061690 0005E5F0  80 6D 2E F8 */	lwz r3, progresWindow@sda21(r13)
/* 80061694 0005E5F4  28 03 00 00 */	cmplwi r3, 0
/* 80061698 0005E5F8  41 82 00 0C */	beq .L_800616A4
/* 8006169C 0005E5FC  7F E4 FB 78 */	mr r4, r31
/* 800616A0 0005E600  48 17 91 2D */	bl draw__Q23zen10DrawProgreFR8Graphics
.L_800616A4:
/* 800616A4 0005E604  3C 60 80 3A */	lis r3, gameflow@ha
/* 800616A8 0005E608  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 800616AC 0005E60C  80 C3 03 10 */	lwz r6, 0x310(r3)
/* 800616B0 0005E610  38 9F 00 00 */	addi r4, r31, 0
/* 800616B4 0005E614  C0 23 03 14 */	lfs f1, 0x314(r3)
/* 800616B8 0005E618  38 A0 00 00 */	li r5, 0
/* 800616BC 0005E61C  4B FE FF 0D */	bl drawLoadLogo__8GameFlowFR8GraphicsbP7Texturef
/* 800616C0 0005E620  BB 61 01 94 */	lmw r27, 0x194(r1)
/* 800616C4 0005E624  80 01 01 AC */	lwz r0, 0x1ac(r1)
/* 800616C8 0005E628  38 21 01 A8 */	addi r1, r1, 0x1a8
/* 800616CC 0005E62C  7C 08 03 A6 */	mtlr r0
/* 800616D0 0005E630  4E 80 00 20 */	blr 
.endfn draw__19NinLogoSetupSectionFR8Graphics

.fn drawMenu__19NinLogoSetupSectionFR8GraphicsP4Menuf, weak
/* 800616D4 0005E634  7C 08 02 A6 */	mflr r0
/* 800616D8 0005E638  90 01 00 04 */	stw r0, 4(r1)
/* 800616DC 0005E63C  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800616E0 0005E640  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 800616E4 0005E644  FF E0 08 90 */	fmr f31, f1
/* 800616E8 0005E648  BF 61 00 1C */	stmw r27, 0x1c(r1)
/* 800616EC 0005E64C  7C BC 2B 78 */	mr r28, r5
/* 800616F0 0005E650  3B 64 00 00 */	addi r27, r4, 0
/* 800616F4 0005E654  80 05 00 3C */	lwz r0, 0x3c(r5)
/* 800616F8 0005E658  2C 00 00 00 */	cmpwi r0, 0
/* 800616FC 0005E65C  41 82 00 9C */	beq .L_80061798
/* 80061700 0005E660  83 FC 00 20 */	lwz r31, 0x20(r28)
/* 80061704 0005E664  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80061708 0005E668  2C 00 00 00 */	cmpwi r0, 0
/* 8006170C 0005E66C  41 82 00 78 */	beq .L_80061784
/* 80061710 0005E670  83 DF 00 20 */	lwz r30, 0x20(r31)
/* 80061714 0005E674  80 1E 00 3C */	lwz r0, 0x3c(r30)
/* 80061718 0005E678  2C 00 00 00 */	cmpwi r0, 0
/* 8006171C 0005E67C  41 82 00 50 */	beq .L_8006176C
/* 80061720 0005E680  83 BE 00 20 */	lwz r29, 0x20(r30)
/* 80061724 0005E684  80 1D 00 3C */	lwz r0, 0x3c(r29)
/* 80061728 0005E688  2C 00 00 00 */	cmpwi r0, 0
/* 8006172C 0005E68C  41 82 00 24 */	beq .L_80061750
/* 80061730 0005E690  C0 22 87 48 */	lfs f1, lbl_803E8948@sda21(r2)
/* 80061734 0005E694  7F 64 DB 78 */	mr r4, r27
/* 80061738 0005E698  80 BD 00 20 */	lwz r5, 0x20(r29)
/* 8006173C 0005E69C  EC 01 07 F2 */	fmuls f0, f1, f31
/* 80061740 0005E6A0  EC 01 00 32 */	fmuls f0, f1, f0
/* 80061744 0005E6A4  EC 01 00 32 */	fmuls f0, f1, f0
/* 80061748 0005E6A8  EC 21 00 32 */	fmuls f1, f1, f0
/* 8006174C 0005E6AC  4B FF FF 89 */	bl drawMenu__19NinLogoSetupSectionFR8GraphicsP4Menuf
.L_80061750:
/* 80061750 0005E6B0  C0 22 87 48 */	lfs f1, lbl_803E8948@sda21(r2)
/* 80061754 0005E6B4  38 7D 00 00 */	addi r3, r29, 0
/* 80061758 0005E6B8  38 9B 00 00 */	addi r4, r27, 0
/* 8006175C 0005E6BC  EC 01 07 F2 */	fmuls f0, f1, f31
/* 80061760 0005E6C0  EC 01 00 32 */	fmuls f0, f1, f0
/* 80061764 0005E6C4  EC 21 00 32 */	fmuls f1, f1, f0
/* 80061768 0005E6C8  4B FF CC A9 */	bl draw__4MenuFR8Graphicsf
.L_8006176C:
/* 8006176C 0005E6CC  C0 22 87 48 */	lfs f1, lbl_803E8948@sda21(r2)
/* 80061770 0005E6D0  38 7E 00 00 */	addi r3, r30, 0
/* 80061774 0005E6D4  38 9B 00 00 */	addi r4, r27, 0
/* 80061778 0005E6D8  EC 01 07 F2 */	fmuls f0, f1, f31
/* 8006177C 0005E6DC  EC 21 00 32 */	fmuls f1, f1, f0
/* 80061780 0005E6E0  4B FF CC 91 */	bl draw__4MenuFR8Graphicsf
.L_80061784:
/* 80061784 0005E6E4  C0 02 87 48 */	lfs f0, lbl_803E8948@sda21(r2)
/* 80061788 0005E6E8  38 7F 00 00 */	addi r3, r31, 0
/* 8006178C 0005E6EC  38 9B 00 00 */	addi r4, r27, 0
/* 80061790 0005E6F0  EC 20 07 F2 */	fmuls f1, f0, f31
/* 80061794 0005E6F4  4B FF CC 7D */	bl draw__4MenuFR8Graphicsf
.L_80061798:
/* 80061798 0005E6F8  FC 20 F8 90 */	fmr f1, f31
/* 8006179C 0005E6FC  38 7C 00 00 */	addi r3, r28, 0
/* 800617A0 0005E700  38 9B 00 00 */	addi r4, r27, 0
/* 800617A4 0005E704  4B FF CC 6D */	bl draw__4MenuFR8Graphicsf
/* 800617A8 0005E708  BB 61 00 1C */	lmw r27, 0x1c(r1)
/* 800617AC 0005E70C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800617B0 0005E710  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 800617B4 0005E714  38 21 00 38 */	addi r1, r1, 0x38
/* 800617B8 0005E718  7C 08 03 A6 */	mtlr r0
/* 800617BC 0005E71C  4E 80 00 20 */	blr 
.endfn drawMenu__19NinLogoSetupSectionFR8GraphicsP4Menuf

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802A8BF8, local
	.asciz "ninLogo.cpp"
.endobj lbl_802A8BF8
.balign 4
.obj lbl_802A8C04, local
	.asciz "<NinLogoSection>"
.endobj lbl_802A8C04
.balign 4
.obj lbl_802A8C18, local
	.asciz "NinLogo section"
.endobj lbl_802A8C18
.balign 4
.obj lbl_802A8C28, local
	.asciz "<Controller>"
.endobj lbl_802A8C28
.balign 4
.obj lbl_802A8C38, local
	.asciz "CoreNode"
.endobj lbl_802A8C38
.balign 4
.obj lbl_802A8C44, local
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802A8C44
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
.obj lbl_802A8C6C, local
	.asciz "NinLogoSetupSection"
.endobj lbl_802A8C6C
.balign 4
.obj lbl_802A8C80, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.endobj lbl_802A8C80
.obj lbl_802A8C94, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.endobj lbl_802A8C94
.obj __vt__19NinLogoSetupSection, weak
	.4byte __RTTI__19NinLogoSetupSection
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__19NinLogoSetupSectionFv
	.4byte draw__19NinLogoSetupSectionFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
.endobj __vt__19NinLogoSetupSection
.balign 4
.obj lbl_802A8CE0, local
	.asciz "NinLogoSection"
.endobj lbl_802A8CE0
.balign 4
.obj lbl_802A8CF0, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.endobj lbl_802A8CF0
.obj lbl_802A8D0C, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__7Section
	.4byte 0
	.4byte 0
.endobj lbl_802A8D0C
.obj __vt__14NinLogoSection, global
	.4byte __RTTI__14NinLogoSection
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
	.4byte init__14NinLogoSectionFv
.endobj __vt__14NinLogoSection

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DDFB8, local
	.asciz "<Node>"
.endobj lbl_803DDFB8
.balign 4
.obj lbl_803DDFC0, local
	.asciz "ANode"
.endobj lbl_803DDFC0
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803DDFC0
	.4byte 0
.endobj __RTTI__5ANode
.obj __RTTI__8CoreNode, local
	.4byte lbl_802A8C38
	.4byte lbl_802A8C44
.endobj __RTTI__8CoreNode
.balign 4
.obj lbl_803DDFD8, local
	.asciz "Node"
.endobj lbl_803DDFD8
.balign 4
.obj __RTTI__4Node, local
	.4byte lbl_803DDFD8
	.4byte lbl_802A8C80
.endobj __RTTI__4Node
.obj __RTTI__19NinLogoSetupSection, local
	.4byte lbl_802A8C6C
	.4byte lbl_802A8C94
.endobj __RTTI__19NinLogoSetupSection
.balign 4
.obj lbl_803DDFF0, local
	.asciz "Section"
.endobj lbl_803DDFF0
.balign 4
.obj __RTTI__7Section, local
	.4byte lbl_803DDFF0
	.4byte lbl_802A8CF0
.endobj __RTTI__7Section
.obj __RTTI__14NinLogoSection, local
	.4byte lbl_802A8CE0
	.4byte lbl_802A8D0C
.endobj __RTTI__14NinLogoSection

.section .sbss, "wa"
.balign 8
.obj progresWindow, local
	.skip 4
.endobj progresWindow

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E8938, local
	.float 1.0
.endobj lbl_803E8938
.obj lbl_803E893C, local
	.float 3.0
.endobj lbl_803E893C
.obj lbl_803E8940, local
	.float 0.125
.endobj lbl_803E8940
.obj lbl_803E8944, local
	.float 0.25
.endobj lbl_803E8944
.obj lbl_803E8948, local
	.float 0.5
.endobj lbl_803E8948
