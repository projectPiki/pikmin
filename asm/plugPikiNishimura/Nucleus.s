.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__11NucleusPropFv
__ct__11NucleusPropFv:
/* 8017A1AC 0017710C  7C 08 02 A6 */	mflr r0
/* 8017A1B0 00177110  90 01 00 04 */	stw r0, 4(r1)
/* 8017A1B4 00177114  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017A1B8 00177118  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017A1BC 0017711C  7C 7F 1B 78 */	mr r31, r3
/* 8017A1C0 00177120  4B FD 37 0D */	bl __ct__8BossPropFv
/* 8017A1C4 00177124  3C 60 80 22 */	lis r3, __vt__5ANode@ha
/* 8017A1C8 00177128  38 03 73 8C */	addi r0, r3, __vt__5ANode@l
/* 8017A1CC 0017712C  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 8017A1D0 00177130  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 8017A1D4 00177134  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 8017A1D8 00177138  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 8017A1DC 0017713C  38 C0 00 00 */	li r6, 0
/* 8017A1E0 00177140  3C A0 80 2D */	lis r5, lbl_802D108C@ha
/* 8017A1E4 00177144  90 DF 01 FC */	stw r6, 0x1fc(r31)
/* 8017A1E8 00177148  3C 60 80 2D */	lis r3, __vt__11NucleusProp@ha
/* 8017A1EC 0017714C  38 83 12 9C */	addi r4, r3, __vt__11NucleusProp@l
/* 8017A1F0 00177150  90 DF 01 F8 */	stw r6, 0x1f8(r31)
/* 8017A1F4 00177154  38 A5 10 8C */	addi r5, r5, lbl_802D108C@l
/* 8017A1F8 00177158  38 04 00 0C */	addi r0, r4, 0xc
/* 8017A1FC 0017715C  90 DF 01 F4 */	stw r6, 0x1f4(r31)
/* 8017A200 00177160  7F E3 FB 78 */	mr r3, r31
/* 8017A204 00177164  90 BF 01 F0 */	stw r5, 0x1f0(r31)
/* 8017A208 00177168  90 9F 00 54 */	stw r4, 0x54(r31)
/* 8017A20C 0017716C  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 8017A210 00177170  90 DF 02 00 */	stw r6, 0x200(r31)
/* 8017A214 00177174  C0 22 AE 48 */	lfs f1, lbl_803EB048@sda21(r2)
/* 8017A218 00177178  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 8017A21C 0017717C  C0 02 AE 4C */	lfs f0, lbl_803EB04C@sda21(r2)
/* 8017A220 00177180  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 8017A224 00177184  D0 3F 00 40 */	stfs f1, 0x40(r31)
/* 8017A228 00177188  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017A22C 0017718C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017A230 00177190  38 21 00 18 */	addi r1, r1, 0x18
/* 8017A234 00177194  7C 08 03 A6 */	mtlr r0
/* 8017A238 00177198  4E 80 00 20 */	blr 

.global __ct__7NucleusFP12CreatureProp
__ct__7NucleusFP12CreatureProp:
/* 8017A23C 0017719C  7C 08 02 A6 */	mflr r0
/* 8017A240 001771A0  90 01 00 04 */	stw r0, 4(r1)
/* 8017A244 001771A4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017A248 001771A8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017A24C 001771AC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017A250 001771B0  7C 7E 1B 78 */	mr r30, r3
/* 8017A254 001771B4  4B FD 3C 25 */	bl __ct__4BossFP12CreatureProp
/* 8017A258 001771B8  3C 60 80 2D */	lis r3, __vt__7Nucleus@ha
/* 8017A25C 001771BC  38 03 11 14 */	addi r0, r3, __vt__7Nucleus@l
/* 8017A260 001771C0  90 1E 00 00 */	stw r0, 0(r30)
/* 8017A264 001771C4  38 60 00 14 */	li r3, 0x14
/* 8017A268 001771C8  4B EC CD 9D */	bl alloc__6SystemFUl
/* 8017A26C 001771CC  3B E3 00 00 */	addi r31, r3, 0
/* 8017A270 001771D0  7F E3 FB 79 */	or. r3, r31, r31
/* 8017A274 001771D4  41 82 00 0C */	beq .L_8017A280
/* 8017A278 001771D8  38 80 00 03 */	li r4, 3
/* 8017A27C 001771DC  4B F0 E9 B5 */	bl __ct__8CollInfoFi
.L_8017A280:
/* 8017A280 001771E0  93 FE 02 20 */	stw r31, 0x220(r30)
/* 8017A284 001771E4  38 60 00 0C */	li r3, 0xc
/* 8017A288 001771E8  4B EC CD 7D */	bl alloc__6SystemFUl
/* 8017A28C 001771EC  3B E3 00 00 */	addi r31, r3, 0
/* 8017A290 001771F0  7F E3 FB 79 */	or. r3, r31, r31
/* 8017A294 001771F4  41 82 00 0C */	beq .L_8017A2A0
/* 8017A298 001771F8  7F C4 F3 78 */	mr r4, r30
/* 8017A29C 001771FC  48 00 02 A9 */	bl __ct__9NucleusAiFP7Nucleus
.L_8017A2A0:
/* 8017A2A0 00177200  93 FE 03 BC */	stw r31, 0x3bc(r30)
/* 8017A2A4 00177204  7F C3 F3 78 */	mr r3, r30
/* 8017A2A8 00177208  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017A2AC 0017720C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017A2B0 00177210  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017A2B4 00177214  38 21 00 18 */	addi r1, r1, 0x18
/* 8017A2B8 00177218  7C 08 03 A6 */	mtlr r0
/* 8017A2BC 0017721C  4E 80 00 20 */	blr 

.global getiMass__7NucleusFv
getiMass__7NucleusFv:
/* 8017A2C0 00177220  C0 22 AE 50 */	lfs f1, lbl_803EB050@sda21(r2)
/* 8017A2C4 00177224  4E 80 00 20 */	blr 

.global init__7NucleusFR8Vector3f
init__7NucleusFR8Vector3f:
/* 8017A2C8 00177228  7C 08 02 A6 */	mflr r0
/* 8017A2CC 0017722C  38 A0 00 00 */	li r5, 0
/* 8017A2D0 00177230  90 01 00 04 */	stw r0, 4(r1)
/* 8017A2D4 00177234  38 00 00 01 */	li r0, 1
/* 8017A2D8 00177238  38 83 00 00 */	addi r4, r3, 0
/* 8017A2DC 0017723C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017A2E0 00177240  C0 02 AE 54 */	lfs f0, lbl_803EB054@sda21(r2)
/* 8017A2E4 00177244  D0 03 02 70 */	stfs f0, 0x270(r3)
/* 8017A2E8 00177248  C0 0D 06 E8 */	lfs f0, lbl_803E5408@sda21(r13)
/* 8017A2EC 0017724C  D0 03 00 7C */	stfs f0, 0x7c(r3)
/* 8017A2F0 00177250  C0 0D 06 EC */	lfs f0, lbl_803E540C@sda21(r13)
/* 8017A2F4 00177254  D0 03 00 80 */	stfs f0, 0x80(r3)
/* 8017A2F8 00177258  C0 0D 06 F0 */	lfs f0, lbl_803E5410@sda21(r13)
/* 8017A2FC 0017725C  D0 03 00 84 */	stfs f0, 0x84(r3)
/* 8017A300 00177260  98 A3 02 B8 */	stb r5, 0x2b8(r3)
/* 8017A304 00177264  98 03 02 BE */	stb r0, 0x2be(r3)
/* 8017A308 00177268  C0 02 AE 58 */	lfs f0, lbl_803EB058@sda21(r2)
/* 8017A30C 0017726C  D0 03 02 E0 */	stfs f0, 0x2e0(r3)
/* 8017A310 00177270  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 8017A314 00177274  48 00 02 51 */	bl initAI__9NucleusAiFP7Nucleus
/* 8017A318 00177278  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017A31C 0017727C  38 21 00 08 */	addi r1, r1, 8
/* 8017A320 00177280  7C 08 03 A6 */	mtlr r0
/* 8017A324 00177284  4E 80 00 20 */	blr 

.global doKill__7NucleusFv
doKill__7NucleusFv:
/* 8017A328 00177288  7C 08 02 A6 */	mflr r0
/* 8017A32C 0017728C  7C 64 1B 78 */	mr r4, r3
/* 8017A330 00177290  90 01 00 04 */	stw r0, 4(r1)
/* 8017A334 00177294  38 00 00 00 */	li r0, 0
/* 8017A338 00177298  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017A33C 0017729C  98 03 02 B8 */	stb r0, 0x2b8(r3)
/* 8017A340 001772A0  98 03 02 B9 */	stb r0, 0x2b9(r3)
/* 8017A344 001772A4  80 6D 31 68 */	lwz r3, bossMgr@sda21(r13)
/* 8017A348 001772A8  4B FD 7E 51 */	bl kill__7BossMgrFP8Creature
/* 8017A34C 001772AC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017A350 001772B0  38 21 00 08 */	addi r1, r1, 8
/* 8017A354 001772B4  7C 08 03 A6 */	mtlr r0
/* 8017A358 001772B8  4E 80 00 20 */	blr 

.global exitCourse__7NucleusFv
exitCourse__7NucleusFv:
/* 8017A35C 001772BC  4E 80 00 20 */	blr 

.global update__7NucleusFv
update__7NucleusFv:
/* 8017A360 001772C0  7C 08 02 A6 */	mflr r0
/* 8017A364 001772C4  90 01 00 04 */	stw r0, 4(r1)
/* 8017A368 001772C8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017A36C 001772CC  4B F1 0E 9D */	bl update__8CreatureFv
/* 8017A370 001772D0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017A374 001772D4  38 21 00 08 */	addi r1, r1, 8
/* 8017A378 001772D8  7C 08 03 A6 */	mtlr r0
/* 8017A37C 001772DC  4E 80 00 20 */	blr 

.global refresh__7NucleusFR8Graphics
refresh__7NucleusFR8Graphics:
/* 8017A380 001772E0  7C 08 02 A6 */	mflr r0
/* 8017A384 001772E4  90 01 00 04 */	stw r0, 4(r1)
/* 8017A388 001772E8  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 8017A38C 001772EC  93 E1 00 54 */	stw r31, 0x54(r1)
/* 8017A390 001772F0  3B E4 00 00 */	addi r31, r4, 0
/* 8017A394 001772F4  93 C1 00 50 */	stw r30, 0x50(r1)
/* 8017A398 001772F8  3B C3 00 00 */	addi r30, r3, 0
/* 8017A39C 001772FC  38 7E 02 28 */	addi r3, r30, 0x228
/* 8017A3A0 00177300  38 9E 00 7C */	addi r4, r30, 0x7c
/* 8017A3A4 00177304  38 BE 00 88 */	addi r5, r30, 0x88
/* 8017A3A8 00177308  38 DE 00 94 */	addi r6, r30, 0x94
/* 8017A3AC 0017730C  4B EC 3D 49 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 8017A3B0 00177310  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 8017A3B4 00177314  38 9E 02 28 */	addi r4, r30, 0x228
/* 8017A3B8 00177318  38 A1 00 10 */	addi r5, r1, 0x10
/* 8017A3BC 0017731C  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 8017A3C0 00177320  4B EC 3D 15 */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 8017A3C4 00177324  38 7E 03 3C */	addi r3, r30, 0x33c
/* 8017A3C8 00177328  81 9E 03 6C */	lwz r12, 0x36c(r30)
/* 8017A3CC 0017732C  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8017A3D0 00177330  7D 88 03 A6 */	mtlr r12
/* 8017A3D4 00177334  4E 80 00 21 */	blrl 
/* 8017A3D8 00177338  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8017A3DC 0017733C  38 9F 00 00 */	addi r4, r31, 0
/* 8017A3E0 00177340  38 A1 00 10 */	addi r5, r1, 0x10
/* 8017A3E4 00177344  80 63 00 00 */	lwz r3, 0(r3)
/* 8017A3E8 00177348  38 C0 00 00 */	li r6, 0
/* 8017A3EC 0017734C  4B EB AF 29 */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 8017A3F0 00177350  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 8017A3F4 00177354  38 9F 00 00 */	addi r4, r31, 0
/* 8017A3F8 00177358  38 A0 00 00 */	li r5, 0
/* 8017A3FC 0017735C  4B F0 F6 F1 */	bl updateInfo__8CollInfoFR8Graphicsb
/* 8017A400 00177360  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 8017A404 00177364  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 8017A408 00177368  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 8017A40C 0017736C  38 21 00 58 */	addi r1, r1, 0x58
/* 8017A410 00177370  7C 08 03 A6 */	mtlr r0
/* 8017A414 00177374  4E 80 00 20 */	blr 

.global drawShape__7NucleusFR8Graphics
drawShape__7NucleusFR8Graphics:
/* 8017A418 00177378  7C 08 02 A6 */	mflr r0
/* 8017A41C 0017737C  38 A0 00 00 */	li r5, 0
/* 8017A420 00177380  90 01 00 04 */	stw r0, 4(r1)
/* 8017A424 00177384  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017A428 00177388  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017A42C 0017738C  3B E4 00 00 */	addi r31, r4, 0
/* 8017A430 00177390  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 8017A434 00177394  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017A438 00177398  3B C3 00 00 */	addi r30, r3, 0
/* 8017A43C 0017739C  38 7F 00 00 */	addi r3, r31, 0
/* 8017A440 001773A0  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 8017A444 001773A4  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 8017A448 001773A8  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8017A44C 001773AC  7D 88 03 A6 */	mtlr r12
/* 8017A450 001773B0  4E 80 00 21 */	blrl 
/* 8017A454 001773B4  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8017A458 001773B8  7F E4 FB 78 */	mr r4, r31
/* 8017A45C 001773BC  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 8017A460 001773C0  38 C0 00 00 */	li r6, 0
/* 8017A464 001773C4  80 63 00 00 */	lwz r3, 0(r3)
/* 8017A468 001773C8  4B EB 60 05 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 8017A46C 001773CC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017A470 001773D0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017A474 001773D4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017A478 001773D8  38 21 00 18 */	addi r1, r1, 0x18
/* 8017A47C 001773DC  7C 08 03 A6 */	mtlr r0
/* 8017A480 001773E0  4E 80 00 20 */	blr 

.global doAI__7NucleusFv
doAI__7NucleusFv:
/* 8017A484 001773E4  7C 08 02 A6 */	mflr r0
/* 8017A488 001773E8  90 01 00 04 */	stw r0, 4(r1)
/* 8017A48C 001773EC  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017A490 001773F0  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 8017A494 001773F4  48 00 01 F1 */	bl update__9NucleusAiFv
/* 8017A498 001773F8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017A49C 001773FC  38 21 00 08 */	addi r1, r1, 8
/* 8017A4A0 00177400  7C 08 03 A6 */	mtlr r0
/* 8017A4A4 00177404  4E 80 00 20 */	blr 

.global doAnimation__7NucleusFv
doAnimation__7NucleusFv:
/* 8017A4A8 00177408  7C 08 02 A6 */	mflr r0
/* 8017A4AC 0017740C  7C 64 1B 78 */	mr r4, r3
/* 8017A4B0 00177410  90 01 00 04 */	stw r0, 4(r1)
/* 8017A4B4 00177414  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017A4B8 00177418  80 03 03 90 */	lwz r0, 0x390(r3)
/* 8017A4BC 0017741C  28 00 00 00 */	cmplwi r0, 0
/* 8017A4C0 00177420  41 82 00 1C */	beq .L_8017A4DC
/* 8017A4C4 00177424  81 84 03 6C */	lwz r12, 0x36c(r4)
/* 8017A4C8 00177428  38 64 03 3C */	addi r3, r4, 0x33c
/* 8017A4CC 0017742C  C0 24 02 D8 */	lfs f1, 0x2d8(r4)
/* 8017A4D0 00177430  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8017A4D4 00177434  7D 88 03 A6 */	mtlr r12
/* 8017A4D8 00177438  4E 80 00 21 */	blrl 
.L_8017A4DC:
/* 8017A4DC 0017743C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017A4E0 00177440  38 21 00 08 */	addi r1, r1, 8
/* 8017A4E4 00177444  7C 08 03 A6 */	mtlr r0
/* 8017A4E8 00177448  4E 80 00 20 */	blr 

.global read__11NucleusPropFR18RandomAccessStream
read__11NucleusPropFR18RandomAccessStream:
/* 8017A4EC 0017744C  7C 08 02 A6 */	mflr r0
/* 8017A4F0 00177450  90 01 00 04 */	stw r0, 4(r1)
/* 8017A4F4 00177454  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017A4F8 00177458  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017A4FC 0017745C  3B E4 00 00 */	addi r31, r4, 0
/* 8017A500 00177460  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017A504 00177464  3B C3 00 00 */	addi r30, r3, 0
/* 8017A508 00177468  4B EE 46 91 */	bl read__10ParametersFR18RandomAccessStream
/* 8017A50C 0017746C  38 7E 00 58 */	addi r3, r30, 0x58
/* 8017A510 00177470  38 9F 00 00 */	addi r4, r31, 0
/* 8017A514 00177474  4B EE 46 85 */	bl read__10ParametersFR18RandomAccessStream
/* 8017A518 00177478  38 7E 02 00 */	addi r3, r30, 0x200
/* 8017A51C 0017747C  38 9F 00 00 */	addi r4, r31, 0
/* 8017A520 00177480  4B EE 46 79 */	bl read__10ParametersFR18RandomAccessStream
/* 8017A524 00177484  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017A528 00177488  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017A52C 0017748C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017A530 00177490  38 21 00 18 */	addi r1, r1, 0x18
/* 8017A534 00177494  7C 08 03 A6 */	mtlr r0
/* 8017A538 00177498  4E 80 00 20 */	blr 

.global "@492@read__11NucleusPropFR18RandomAccessStream"
"@492@read__11NucleusPropFR18RandomAccessStream":
/* 8017A53C 0017749C  38 63 FE 14 */	addi r3, r3, -492
/* 8017A540 001774A0  4B FF FF AC */	b read__11NucleusPropFR18RandomAccessStream

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802D1080:
	.asciz "Nucleus.cpp"
.balign 4
lbl_802D108C:
	.asciz "CoreNode"
.balign 4
lbl_802D1098:
	.asciz "EventTalker"
.balign 4
lbl_802D10A4:
	.asciz "RefCountable"
.balign 4
lbl_802D10B4:
	.asciz "Creature"
.balign 4
lbl_802D10C0:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D10D4:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D10F0:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte __RTTI__4Boss
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__7Nucleus
__vt__7Nucleus:
	.4byte __RTTI__7Nucleus
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__7NucleusFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__7NucleusFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__4BossFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__4BossFv
	.4byte isVisible__4BossFv
	.4byte isOrganic__4BossFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__4BossFv
	.4byte isAlive__4BossFv
	.4byte isFixed__4BossFv
	.4byte needShadow__4BossFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__4BossFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__4BossFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__4BossFR9CollEvent
	.4byte bounceCallback__8CreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__4BossFR5PlaneP13DynCollObject
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
	.4byte update__7NucleusFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__7NucleusFR8Graphics
	.4byte refresh2d__4BossFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__7NucleusFv
	.4byte doAnimation__7NucleusFv
	.4byte doKill__7NucleusFv
	.4byte exitCourse__7NucleusFv
	.4byte isBossBgm__4BossFv
	.4byte attackDefaultPortion__4BossFv
	.4byte bombDamageCounter__4BossFP8CollPart
	.4byte drawShape__7NucleusFR8Graphics
.balign 4
lbl_802D1238:
	.asciz "NucleusProp"
.balign 4
lbl_802D1244:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.balign 4
lbl_802D1250:
	.asciz "CreatureProp"
.balign 4
lbl_802D1260:
	.asciz "BossProp"
.balign 4
lbl_802D126C:
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte 0
lbl_802D1278:
	.4byte __RTTI__5ANode
	.4byte 0x1ec
	.4byte __RTTI__8CoreNode
	.4byte 0x1ec
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte __RTTI__8BossProp
	.4byte 0
	.4byte 0
.global __vt__11NucleusProp
__vt__11NucleusProp:
	.4byte __RTTI__11NucleusProp
	.4byte 0
	.4byte read__11NucleusPropFR18RandomAccessStream
	.4byte __RTTI__11NucleusProp
	.4byte 0xfffffe14
	.4byte getAgeNodeType__5ANodeFv
	.4byte "@492@read__11NucleusPropFR18RandomAccessStream"
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
lbl_803E5400:
	.asciz "Nucleus"
.balign 4
lbl_803E5408:
	.float 0.0
lbl_803E540C:
	.float 0.0
lbl_803E5410:
	.float 0.0
__RTTI__11EventTalker:
	.4byte lbl_802D1098
	.4byte 0x00000000
__RTTI__12RefCountable:
	.4byte lbl_802D10A4
	.4byte 0x00000000
__RTTI__8Creature:
	.4byte lbl_802D10B4
	.4byte lbl_802D10C0
.balign 4
lbl_803E542C:
	.asciz "Boss"
.balign 4
__RTTI__4Boss:
	.4byte lbl_803E542C
	.4byte lbl_802D10D4
__RTTI__7Nucleus:
	.4byte lbl_803E5400
	.4byte lbl_802D10F0
.balign 4
lbl_803E5444:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E5444
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802D108C
	.4byte lbl_802D1244
__RTTI__12CreatureProp:
	.4byte lbl_802D1250
	.4byte 0
__RTTI__8BossProp:
	.4byte lbl_802D1260
	.4byte lbl_802D126C
__RTTI__11NucleusProp:
	.4byte lbl_802D1238
	.4byte lbl_802D1278

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EB048:
	.float 1.0
lbl_803EB04C:
	.float 0.0
lbl_803EB050:
	.float 0.01
lbl_803EB054:
	.float 20.0
lbl_803EB058:
	.float 30.0
