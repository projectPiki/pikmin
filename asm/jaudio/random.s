.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8000D7E0 0000A740  4E 80 00 20 */	blr 
/* 8000D7E4 0000A744  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D7E8 0000A748  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D7EC 0000A74C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D7F0 0000A750  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D7F4 0000A754  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D7F8 0000A758  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D7FC 0000A75C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global GetRandom_ulimit
GetRandom_ulimit:
/* 8000D800 0000A760  7C 08 02 A6 */	mflr r0
/* 8000D804 0000A764  90 01 00 04 */	stw r0, 4(r1)
/* 8000D808 0000A768  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000D80C 0000A76C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8000D810 0000A770  7C 7F 1B 78 */	mr r31, r3
/* 8000D814 0000A774  4B FF FF AD */	bl GetRandom_u32
/* 8000D818 0000A778  7C 03 FB 96 */	divwu r0, r3, r31
/* 8000D81C 0000A77C  7C 00 F9 D6 */	mullw r0, r0, r31
/* 8000D820 0000A780  7C 60 18 50 */	subf r3, r0, r3
/* 8000D824 0000A784  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8000D828 0000A788  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8000D82C 0000A78C  38 21 00 18 */	addi r1, r1, 0x18
/* 8000D830 0000A790  7C 08 03 A6 */	mtlr r0
/* 8000D834 0000A794  4E 80 00 20 */	blr 
/* 8000D838 0000A798  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D83C 0000A79C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global GetRandom_sf32
GetRandom_sf32:
/* 8000D840 0000A7A0  7C 08 02 A6 */	mflr r0
/* 8000D844 0000A7A4  90 01 00 04 */	stw r0, 4(r1)
/* 8000D848 0000A7A8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000D84C 0000A7AC  4B FF FE F5 */	bl GetRandom_s32
/* 8000D850 0000A7B0  54 64 02 3E */	clrlwi r4, r3, 8
/* 8000D854 0000A7B4  3C 00 43 30 */	lis r0, 0x4330
/* 8000D858 0000A7B8  6C 84 80 00 */	xoris r4, r4, 0x8000
/* 8000D85C 0000A7BC  C8 42 80 98 */	lfd f2, "@58"@sda21(r2)
/* 8000D860 0000A7C0  90 81 00 14 */	stw r4, 0x14(r1)
/* 8000D864 0000A7C4  2C 03 00 00 */	cmpwi r3, 0
/* 8000D868 0000A7C8  C0 02 80 90 */	lfs f0, lbl_803E8290@sda21(r2)
/* 8000D86C 0000A7CC  90 01 00 10 */	stw r0, 0x10(r1)
/* 8000D870 0000A7D0  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 8000D874 0000A7D4  EC 21 10 28 */	fsubs f1, f1, f2
/* 8000D878 0000A7D8  EC 21 00 24 */	fdivs f1, f1, f0
/* 8000D87C 0000A7DC  40 80 00 08 */	bge lbl_8000D884
/* 8000D880 0000A7E0  FC 20 08 50 */	fneg f1, f1
lbl_8000D884:
/* 8000D884 0000A7E4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8000D888 0000A7E8  38 21 00 18 */	addi r1, r1, 0x18
/* 8000D88C 0000A7EC  7C 08 03 A6 */	mtlr r0
/* 8000D890 0000A7F0  4E 80 00 20 */	blr 
/* 8000D894 0000A7F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D898 0000A7F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D89C 0000A7FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global LoadAram__FPcPUlUl
LoadAram__FPcPUlUl:
/* 8000D8A0 0000A800  7C 08 02 A6 */	mflr r0
/* 8000D8A4 0000A804  39 04 00 00 */	addi r8, r4, 0
/* 8000D8A8 0000A808  90 01 00 04 */	stw r0, 4(r1)
/* 8000D8AC 0000A80C  38 C0 00 00 */	li r6, 0
/* 8000D8B0 0000A810  38 E0 00 00 */	li r7, 0
/* 8000D8B4 0000A814  39 20 00 00 */	li r9, 0
/* 8000D8B8 0000A818  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8000D8BC 0000A81C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8000D8C0 0000A820  90 A1 00 10 */	stw r5, 0x10(r1)
/* 8000D8C4 0000A824  90 61 00 08 */	stw r3, 8(r1)
/* 8000D8C8 0000A828  38 60 00 00 */	li r3, 0
/* 8000D8CC 0000A82C  83 E1 00 10 */	lwz r31, 0x10(r1)
/* 8000D8D0 0000A830  80 81 00 08 */	lwz r4, 8(r1)
/* 8000D8D4 0000A834  38 BF 00 00 */	addi r5, r31, 0
/* 8000D8D8 0000A838  4B FF A5 09 */	bl DVDT_LoadtoARAM__FUlPcUlUlUlPUlPFUl_v
/* 8000D8DC 0000A83C  2C 03 FF FF */	cmpwi r3, -1
/* 8000D8E0 0000A840  40 82 00 0C */	bne lbl_8000D8EC
/* 8000D8E4 0000A844  38 60 00 00 */	li r3, 0
/* 8000D8E8 0000A848  48 00 00 08 */	b lbl_8000D8F0
lbl_8000D8EC:
/* 8000D8EC 0000A84C  7F E3 FB 78 */	mr r3, r31
lbl_8000D8F0:
/* 8000D8F0 0000A850  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8000D8F4 0000A854  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8000D8F8 0000A858  38 21 00 28 */	addi r1, r1, 0x28
/* 8000D8FC 0000A85C  7C 08 03 A6 */	mtlr r0
/* 8000D900 0000A860  4E 80 00 20 */	blr 
/* 8000D904 0000A864  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D908 0000A868  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D90C 0000A86C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D910 0000A870  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D914 0000A874  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D918 0000A878  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000D91C 0000A87C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global LoadAramSingle__FPcUlUlPUlUl
LoadAramSingle__FPcUlUlPUlUl:
/* 8000D920 0000A880  7C 08 02 A6 */	mflr r0
/* 8000D924 0000A884  39 06 00 00 */	addi r8, r6, 0
/* 8000D928 0000A888  90 01 00 04 */	stw r0, 4(r1)
/* 8000D92C 0000A88C  39 20 00 00 */	li r9, 0
/* 8000D930 0000A890  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8000D934 0000A894  93 E1 00 34 */	stw r31, 0x34(r1)
/* 8000D938 0000A898  3B E7 00 00 */	addi r31, r7, 0
/* 8000D93C 0000A89C  90 A1 00 10 */	stw r5, 0x10(r1)

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8021C2C8 00219228  80 01 00 04 */	lwz r0, 4(r1)
/* 8021C2CC 0021922C  7C 08 03 A6 */	mtlr r0
/* 8021C2D0 00219230  4E 80 00 20 */	blr 

.global TRKConstructEvent
TRKConstructEvent:
/* 8021C2D4 00219234  98 83 00 00 */	stb r4, 0(r3)
/* 8021C2D8 00219238  38 80 00 00 */	li r4, 0
/* 8021C2DC 0021923C  38 00 FF FF */	li r0, -1
/* 8021C2E0 00219240  90 83 00 04 */	stw r4, 4(r3)
/* 8021C2E4 00219244  90 03 00 08 */	stw r0, 8(r3)
/* 8021C2E8 00219248  4E 80 00 20 */	blr 

.global TRKDestructEvent
TRKDestructEvent:
/* 8021C2EC 0021924C  7C 08 02 A6 */	mflr r0
/* 8021C2F0 00219250  90 01 00 04 */	stw r0, 4(r1)
/* 8021C2F4 00219254  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021C2F8 00219258  80 63 00 08 */	lwz r3, 8(r3)
/* 8021C2FC 0021925C  48 00 03 19 */	bl TRKReleaseBuffer
/* 8021C300 00219260  38 21 00 08 */	addi r1, r1, 8
/* 8021C304 00219264  80 01 00 04 */	lwz r0, 4(r1)
/* 8021C308 00219268  7C 08 03 A6 */	mtlr r0
/* 8021C30C 0021926C  4E 80 00 20 */	blr 

.global TRKInitializeNub
TRKInitializeNub:
/* 8021C310 00219270  7C 08 02 A6 */	mflr r0
/* 8021C314 00219274  90 01 00 04 */	stw r0, 4(r1)
/* 8021C318 00219278  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8021C31C 0021927C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8021C320 00219280  93 C1 00 08 */	stw r30, 8(r1)
/* 8021C324 00219284  48 00 01 0D */	bl TRKInitializeEndian
/* 8021C328 00219288  7C 7E 1B 79 */	or. r30, r3, r3
/* 8021C32C 0021928C  40 82 00 08 */	bne lbl_8021C334
/* 8021C330 00219290  48 00 0B AD */	bl usr_put_initialize
lbl_8021C334:
/* 8021C334 00219294  2C 1E 00 00 */	cmpwi r30, 0
/* 8021C338 00219298  40 82 00 0C */	bne lbl_8021C344
/* 8021C33C 0021929C  4B FF FD 79 */	bl TRKInitializeEventQueue
/* 8021C340 002192A0  7C 7E 1B 78 */	mr r30, r3
lbl_8021C344:
/* 8021C344 002192A4  2C 1E 00 00 */	cmpwi r30, 0
/* 8021C348 002192A8  40 82 00 0C */	bne lbl_8021C354
/* 8021C34C 002192AC  48 00 01 89 */	bl TRKInitializeMessageBuffers
/* 8021C350 002192B0  7C 7E 1B 78 */	mr r30, r3
lbl_8021C354:
/* 8021C354 002192B4  2C 1E 00 00 */	cmpwi r30, 0
/* 8021C358 002192B8  40 82 00 0C */	bne lbl_8021C364
/* 8021C35C 002192BC  48 00 0B 85 */	bl TRKInitializeDispatcher
/* 8021C360 002192C0  7C 7E 1B 78 */	mr r30, r3
lbl_8021C364:
/* 8021C364 002192C4  2C 1E 00 00 */	cmpwi r30, 0
/* 8021C368 002192C8  40 82 00 40 */	bne lbl_8021C3A8
/* 8021C36C 002192CC  3C 60 80 3D */	lis r3, gTRKInputPendingPtr@ha
/* 8021C370 002192D0  3B E3 5C E4 */	addi r31, r3, gTRKInputPendingPtr@l
/* 8021C374 002192D4  3C 60 00 01 */	lis r3, 0x0000E100@ha
/* 8021C378 002192D8  38 DF 00 00 */	addi r6, r31, 0
/* 8021C37C 002192DC  38 63 E1 00 */	addi r3, r3, 0x0000E100@l
/* 8021C380 002192E0  38 80 00 01 */	li r4, 1
/* 8021C384 002192E4  38 A0 00 00 */	li r5, 0
/* 8021C388 002192E8  48 00 42 85 */	bl TRKInitializeIntDrivenUART
/* 8021C38C 002192EC  7C 60 1B 78 */	mr r0, r3
/* 8021C390 002192F0  80 7F 00 00 */	lwz r3, 0(r31)
/* 8021C394 002192F4  7C 1F 03 78 */	mr r31, r0
/* 8021C398 002192F8  48 00 3A B9 */	bl TRKTargetSetInputPendingPtr
/* 8021C39C 002192FC  2C 1F 00 00 */	cmpwi r31, 0
/* 8021C3A0 00219300  41 82 00 08 */	beq lbl_8021C3A8
/* 8021C3A4 00219304  7F FE FB 78 */	mr r30, r31
lbl_8021C3A8:
/* 8021C3A8 00219308  2C 1E 00 00 */	cmpwi r30, 0
/* 8021C3AC 0021930C  40 82 00 0C */	bne lbl_8021C3B8
/* 8021C3B0 00219310  48 00 0B 01 */	bl TRKInitializeSerialHandler
/* 8021C3B4 00219314  7C 7E 1B 78 */	mr r30, r3
lbl_8021C3B8:
/* 8021C3B8 00219318  2C 1E 00 00 */	cmpwi r30, 0
/* 8021C3BC 0021931C  40 82 00 0C */	bne lbl_8021C3C8
/* 8021C3C0 00219320  48 00 3C 91 */	bl TRKInitializeTarget
/* 8021C3C4 00219324  7C 7E 1B 78 */	mr r30, r3
lbl_8021C3C8:
/* 8021C3C8 00219328  7F C3 F3 78 */	mr r3, r30
/* 8021C3CC 0021932C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8021C3D0 00219330  83 C1 00 08 */	lwz r30, 8(r1)
/* 8021C3D4 00219334  38 21 00 10 */	addi r1, r1, 0x10
/* 8021C3D8 00219338  80 01 00 04 */	lwz r0, 4(r1)
/* 8021C3DC 0021933C  7C 08 03 A6 */	mtlr r0
/* 8021C3E0 00219340  4E 80 00 20 */	blr 

.global TRKTerminateNub
TRKTerminateNub:
/* 8021C3E4 00219344  7C 08 02 A6 */	mflr r0
/* 8021C3E8 00219348  90 01 00 04 */	stw r0, 4(r1)
/* 8021C3EC 0021934C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021C3F0 00219350  48 00 0A E5 */	bl TRKTerminateSerialHandler
/* 8021C3F4 00219354  38 60 00 00 */	li r3, 0
/* 8021C3F8 00219358  38 21 00 08 */	addi r1, r1, 8
/* 8021C3FC 0021935C  80 01 00 04 */	lwz r0, 4(r1)
/* 8021C400 00219360  7C 08 03 A6 */	mtlr r0
/* 8021C404 00219364  4E 80 00 20 */	blr 

.global TRKNubWelcome
TRKNubWelcome:
/* 8021C408 00219368  7C 08 02 A6 */	mflr r0
/* 8021C40C 0021936C  3C 60 80 22 */	lis r3, lbl_80222D50@ha
/* 8021C410 00219370  90 01 00 04 */	stw r0, 4(r1)
/* 8021C414 00219374  38 63 2D 50 */	addi r3, r3, lbl_80222D50@l
/* 8021C418 00219378  94 21 FF F8 */	stwu r1, -8(r1)
/* 8021C41C 0021937C  48 00 43 79 */	bl TRK_board_display
/* 8021C420 00219380  38 21 00 08 */	addi r1, r1, 8
/* 8021C424 00219384  80 01 00 04 */	lwz r0, 4(r1)

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8002DAF4 0002AA54  41 80 FF 9C */	blt lbl_8002DA90
/* 8002DAF8 0002AA58  3B 60 00 00 */	li r27, 0
/* 8002DAFC 0002AA5C  3B 5B 00 00 */	addi r26, r27, 0
lbl_8002DB00:
/* 8002DB00 0002AA60  7F 83 E3 78 */	mr r3, r28
/* 8002DB04 0002AA64  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8002DB08 0002AA68  81 9C 00 04 */	lwz r12, 4(r28)
/* 8002DB0C 0002AA6C  7C 9E D2 14 */	add r4, r30, r26
/* 8002DB10 0002AA70  3B 24 00 48 */	addi r25, r4, 0x48
/* 8002DB14 0002AA74  81 8C 00 08 */	lwz r12, 8(r12)
/* 8002DB18 0002AA78  7F 20 CA 14 */	add r25, r0, r25
/* 8002DB1C 0002AA7C  7D 88 03 A6 */	mtlr r12
/* 8002DB20 0002AA80  4E 80 00 21 */	blrl 
/* 8002DB24 0002AA84  90 79 00 00 */	stw r3, 0(r25)
/* 8002DB28 0002AA88  7F 83 E3 78 */	mr r3, r28
/* 8002DB2C 0002AA8C  81 9C 00 04 */	lwz r12, 4(r28)
/* 8002DB30 0002AA90  81 8C 00 08 */	lwz r12, 8(r12)
/* 8002DB34 0002AA94  7D 88 03 A6 */	mtlr r12
/* 8002DB38 0002AA98  4E 80 00 21 */	blrl 
/* 8002DB3C 0002AA9C  90 79 00 04 */	stw r3, 4(r25)
/* 8002DB40 0002AAA0  7F 83 E3 78 */	mr r3, r28
/* 8002DB44 0002AAA4  81 9C 00 04 */	lwz r12, 4(r28)
/* 8002DB48 0002AAA8  81 8C 00 08 */	lwz r12, 8(r12)
/* 8002DB4C 0002AAAC  7D 88 03 A6 */	mtlr r12
/* 8002DB50 0002AAB0  4E 80 00 21 */	blrl 
/* 8002DB54 0002AAB4  3B 7B 00 01 */	addi r27, r27, 1
/* 8002DB58 0002AAB8  90 79 00 08 */	stw r3, 8(r25)
/* 8002DB5C 0002AABC  2C 1B 00 03 */	cmpwi r27, 3
/* 8002DB60 0002AAC0  3B 5A 00 0C */	addi r26, r26, 0xc
/* 8002DB64 0002AAC4  41 80 FF 9C */	blt lbl_8002DB00
/* 8002DB68 0002AAC8  3B DE 00 DC */	addi r30, r30, 0xdc
/* 8002DB6C 0002AACC  3B BD 00 01 */	addi r29, r29, 1
lbl_8002DB70:
/* 8002DB70 0002AAD0  80 1F 00 28 */	lwz r0, 0x28(r31)
/* 8002DB74 0002AAD4  7C 1D 00 00 */	cmpw r29, r0
/* 8002DB78 0002AAD8  41 80 FE 48 */	blt lbl_8002D9C0
/* 8002DB7C 0002AADC  7F E3 FB 78 */	mr r3, r31
/* 8002DB80 0002AAE0  4B FF E8 D9 */	bl checkMask__8AnimDataFv
/* 8002DB84 0002AAE4  83 7F 00 30 */	lwz r27, 0x30(r31)
/* 8002DB88 0002AAE8  1C 7B 00 1C */	mulli r3, r27, 0x1c
/* 8002DB8C 0002AAEC  38 63 00 08 */	addi r3, r3, 8
/* 8002DB90 0002AAF0  48 01 94 75 */	bl alloc__6SystemFUl
/* 8002DB94 0002AAF4  3C 80 80 03 */	lis r4, __ct__13AnimCacheInfoFv@ha
/* 8002DB98 0002AAF8  38 84 C4 48 */	addi r4, r4, __ct__13AnimCacheInfoFv@l
/* 8002DB9C 0002AAFC  38 FB 00 00 */	addi r7, r27, 0
/* 8002DBA0 0002AB00  38 A0 00 00 */	li r5, 0
/* 8002DBA4 0002AB04  38 C0 00 1C */	li r6, 0x1c
/* 8002DBA8 0002AB08  48 1E 70 81 */	bl __construct_new_array
/* 8002DBAC 0002AB0C  90 7F 00 40 */	stw r3, 0x40(r31)
/* 8002DBB0 0002AB10  BB 21 00 2C */	lmw r25, 0x2c(r1)
/* 8002DBB4 0002AB14  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 8002DBB8 0002AB18  38 21 00 48 */	addi r1, r1, 0x48
/* 8002DBBC 0002AB1C  7C 08 03 A6 */	mtlr r0
/* 8002DBC0 0002AB20  4E 80 00 20 */	blr 

.global parse__7AnimDckFP9CmdStream
parse__7AnimDckFP9CmdStream:
/* 8002DBC4 0002AB24  7C 08 02 A6 */	mflr r0
/* 8002DBC8 0002AB28  90 01 00 04 */	stw r0, 4(r1)
/* 8002DBCC 0002AB2C  38 00 00 00 */	li r0, 0
/* 8002DBD0 0002AB30  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8002DBD4 0002AB34  BF 41 00 48 */	stmw r26, 0x48(r1)
/* 8002DBD8 0002AB38  3B C3 00 00 */	addi r30, r3, 0
/* 8002DBDC 0002AB3C  3B E4 00 00 */	addi r31, r4, 0
/* 8002DBE0 0002AB40  90 03 00 1C */	stw r0, 0x1c(r3)
/* 8002DBE4 0002AB44  3C 60 80 23 */	lis r3, lbl_80228320@ha
/* 8002DBE8 0002AB48  3B A3 83 20 */	addi r29, r3, lbl_80228320@l
/* 8002DBEC 0002AB4C  90 1E 00 18 */	stw r0, 0x18(r30)
/* 8002DBF0 0002AB50  90 1E 00 14 */	stw r0, 0x14(r30)
/* 8002DBF4 0002AB54  48 00 0A A4 */	b lbl_8002E698
lbl_8002DBF8:
/* 8002DBF8 0002AB58  38 7F 00 00 */	addi r3, r31, 0
/* 8002DBFC 0002AB5C  38 80 00 01 */	li r4, 1
/* 8002DC00 0002AB60  48 01 34 B1 */	bl getToken__9CmdStreamFb
/* 8002DC04 0002AB64  38 7F 00 00 */	addi r3, r31, 0
/* 8002DC08 0002AB68  38 9D 02 74 */	addi r4, r29, 0x274
/* 8002DC0C 0002AB6C  48 01 37 C9 */	bl isToken__9CmdStreamFPc
/* 8002DC10 0002AB70  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002DC14 0002AB74  41 82 00 20 */	beq lbl_8002DC34
/* 8002DC18 0002AB78  38 7F 00 00 */	addi r3, r31, 0
/* 8002DC1C 0002AB7C  38 80 00 01 */	li r4, 1
/* 8002DC20 0002AB80  48 01 34 91 */	bl getToken__9CmdStreamFb
/* 8002DC24 0002AB84  38 7E 00 00 */	addi r3, r30, 0
/* 8002DC28 0002AB88  38 9F 00 00 */	addi r4, r31, 0
/* 8002DC2C 0002AB8C  48 00 0C 7D */	bl getAnimInfo__7AnimDckFP9CmdStream
/* 8002DC30 0002AB90  48 00 0A 68 */	b lbl_8002E698
lbl_8002DC34:
/* 8002DC34 0002AB94  38 7F 00 00 */	addi r3, r31, 0
/* 8002DC38 0002AB98  38 9D 02 84 */	addi r4, r29, 0x284
/* 8002DC3C 0002AB9C  48 01 37 99 */	bl isToken__9CmdStreamFPc
/* 8002DC40 0002ABA0  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002DC44 0002ABA4  41 82 01 24 */	beq lbl_8002DD68
/* 8002DC48 0002ABA8  38 60 00 0C */	li r3, 0xc
/* 8002DC4C 0002ABAC  48 01 93 B9 */	bl alloc__6SystemFUl
/* 8002DC50 0002ABB0  28 03 00 00 */	cmplwi r3, 0

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8004C374 000492D4  D8 41 00 30 */	stfd f2, 0x30(r1)
/* 8004C378 000492D8  D8 61 00 38 */	stfd f3, 0x38(r1)
/* 8004C37C 000492DC  D8 81 00 40 */	stfd f4, 0x40(r1)
/* 8004C380 000492E0  D8 A1 00 48 */	stfd f5, 0x48(r1)
/* 8004C384 000492E4  D8 C1 00 50 */	stfd f6, 0x50(r1)
/* 8004C388 000492E8  D8 E1 00 58 */	stfd f7, 0x58(r1)
/* 8004C38C 000492EC  D9 01 00 60 */	stfd f8, 0x60(r1)
lbl_8004C390:
/* 8004C390 000492F0  90 61 00 08 */	stw r3, 8(r1)
/* 8004C394 000492F4  3B A3 00 00 */	addi r29, r3, 0
/* 8004C398 000492F8  3C 00 05 00 */	lis r0, 0x500
/* 8004C39C 000492FC  90 81 00 0C */	stw r4, 0xc(r1)
/* 8004C3A0 00049300  3B C4 00 00 */	addi r30, r4, 0
/* 8004C3A4 00049304  3A 25 00 00 */	addi r17, r5, 0
/* 8004C3A8 00049308  90 A1 00 10 */	stw r5, 0x10(r1)
/* 8004C3AC 0004930C  3B E6 00 00 */	addi r31, r6, 0
/* 8004C3B0 00049310  38 87 00 00 */	addi r4, r7, 0
/* 8004C3B4 00049314  90 C1 00 14 */	stw r6, 0x14(r1)
/* 8004C3B8 00049318  38 61 00 E0 */	addi r3, r1, 0xe0
/* 8004C3BC 0004931C  90 E1 00 18 */	stw r7, 0x18(r1)
/* 8004C3C0 00049320  91 01 00 1C */	stw r8, 0x1c(r1)
/* 8004C3C4 00049324  91 21 00 20 */	stw r9, 0x20(r1)
/* 8004C3C8 00049328  91 41 00 24 */	stw r10, 0x24(r1)
/* 8004C3CC 0004932C  90 01 00 D4 */	stw r0, 0xd4(r1)
/* 8004C3D0 00049330  38 01 02 C0 */	addi r0, r1, 0x2c0
/* 8004C3D4 00049334  90 01 00 D8 */	stw r0, 0xd8(r1)
/* 8004C3D8 00049338  38 01 00 08 */	addi r0, r1, 8
/* 8004C3DC 0004933C  90 01 00 DC */	stw r0, 0xdc(r1)
/* 8004C3E0 00049340  38 01 00 D4 */	addi r0, r1, 0xd4
/* 8004C3E4 00049344  7C 05 03 78 */	mr r5, r0
/* 8004C3E8 00049348  48 1C A2 85 */	bl vsprintf
/* 8004C3EC 0004934C  38 60 00 00 */	li r3, 0
/* 8004C3F0 00049350  38 80 00 00 */	li r4, 0
/* 8004C3F4 00049354  48 1C 6B A9 */	bl GXSetTevOp
/* 8004C3F8 00049358  38 60 00 01 */	li r3, 1
/* 8004C3FC 0004935C  38 80 00 04 */	li r4, 4
/* 8004C400 00049360  38 A0 00 05 */	li r5, 5
/* 8004C404 00049364  38 C0 00 00 */	li r6, 0
/* 8004C408 00049368  48 1C 78 45 */	bl GXSetBlendMode
/* 8004C40C 0004936C  7F A3 EB 78 */	mr r3, r29
/* 8004C410 00049370  80 9E 00 00 */	lwz r4, 0(r30)
/* 8004C414 00049374  81 9D 03 B4 */	lwz r12, 0x3b4(r29)
/* 8004C418 00049378  38 A0 00 00 */	li r5, 0
/* 8004C41C 0004937C  81 8C 00 CC */	lwz r12, 0xcc(r12)
/* 8004C420 00049380  7D 88 03 A6 */	mtlr r12
/* 8004C424 00049384  4E 80 00 21 */	blrl 
/* 8004C428 00049388  80 1D 03 18 */	lwz r0, 0x318(r29)
/* 8004C42C 0004938C  38 81 00 C0 */	addi r4, r1, 0xc0
/* 8004C430 00049390  38 60 00 00 */	li r3, 0
/* 8004C434 00049394  90 01 00 C0 */	stw r0, 0xc0(r1)
/* 8004C438 00049398  48 1C 59 35 */	bl GXSetChanMatColor
/* 8004C43C 0004939C  48 1C 37 C1 */	bl GXClearVtxDesc
/* 8004C440 000493A0  38 60 00 09 */	li r3, 9
/* 8004C444 000493A4  38 80 00 01 */	li r4, 1
/* 8004C448 000493A8  48 1C 2F B9 */	bl GXSetVtxDesc
/* 8004C44C 000493AC  38 60 00 0B */	li r3, 0xb
/* 8004C450 000493B0  38 80 00 01 */	li r4, 1
/* 8004C454 000493B4  48 1C 2F AD */	bl GXSetVtxDesc
/* 8004C458 000493B8  38 60 00 0D */	li r3, 0xd
/* 8004C45C 000493BC  38 80 00 01 */	li r4, 1
/* 8004C460 000493C0  48 1C 2F A1 */	bl GXSetVtxDesc
/* 8004C464 000493C4  38 60 00 00 */	li r3, 0
/* 8004C468 000493C8  38 80 00 09 */	li r4, 9
/* 8004C46C 000493CC  38 A0 00 01 */	li r5, 1
/* 8004C470 000493D0  38 C0 00 04 */	li r6, 4
/* 8004C474 000493D4  38 E0 00 00 */	li r7, 0
/* 8004C478 000493D8  48 1C 37 D1 */	bl GXSetVtxAttrFmt
/* 8004C47C 000493DC  38 60 00 00 */	li r3, 0
/* 8004C480 000493E0  38 80 00 0B */	li r4, 0xb
/* 8004C484 000493E4  38 A0 00 01 */	li r5, 1
/* 8004C488 000493E8  38 C0 00 05 */	li r6, 5
/* 8004C48C 000493EC  38 E0 00 00 */	li r7, 0
/* 8004C490 000493F0  48 1C 37 B9 */	bl GXSetVtxAttrFmt
/* 8004C494 000493F4  38 60 00 00 */	li r3, 0
/* 8004C498 000493F8  38 80 00 0D */	li r4, 0xd
/* 8004C49C 000493FC  38 A0 00 01 */	li r5, 1
/* 8004C4A0 00049400  38 C0 00 04 */	li r6, 4
/* 8004C4A4 00049404  38 E0 00 00 */	li r7, 0
/* 8004C4A8 00049408  48 1C 37 A1 */	bl GXSetVtxAttrFmt
/* 8004C4AC 0004940C  CB A2 84 B8 */	lfd f29, "@896_1"@sda21(r2)
/* 8004C4B0 00049410  7E 37 8B 78 */	mr r23, r17
/* 8004C4B4 00049414  C3 C2 84 A8 */	lfs f30, lbl_803E86A8@sda21(r2)
/* 8004C4B8 00049418  3A C1 00 E0 */	addi r22, r1, 0xe0
/* 8004C4BC 0004941C  C3 E2 84 AC */	lfs f31, lbl_803E86AC@sda21(r2)
/* 8004C4C0 00049420  6F FC 80 00 */	xoris r28, r31, 0x8000
/* 8004C4C4 00049424  3F 40 43 30 */	lis r26, 0x4330
/* 8004C4C8 00049428  3F 60 CC 01 */	lis r27, 0xcc01
/* 8004C4CC 0004942C  48 00 02 5C */	b lbl_8004C728
lbl_8004C4D0:
/* 8004C4D0 00049430  54 A0 06 31 */	rlwinm. r0, r5, 0, 0x18, 0x18

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80210040 0020CFA0  7C E6 33 78 */	or r6, r7, r6
/* 80210044 0020CFA4  90 C8 00 00 */	stw r6, 0(r8)
/* 80210048 0020CFA8  40 82 00 28 */	bne lbl_80210070
/* 8021004C 0020CFAC  80 08 00 00 */	lwz r0, 0(r8)
/* 80210050 0020CFB0  54 00 05 EA */	rlwinm r0, r0, 0, 0x17, 0x15
/* 80210054 0020CFB4  60 00 02 00 */	ori r0, r0, 0x200
/* 80210058 0020CFB8  90 08 00 00 */	stw r0, 0(r8)
/* 8021005C 0020CFBC  80 08 00 00 */	lwz r0, 0(r8)
/* 80210060 0020CFC0  54 00 00 7E */	clrlwi r0, r0, 1
/* 80210064 0020CFC4  64 00 80 00 */	oris r0, r0, 0x8000
/* 80210068 0020CFC8  90 08 00 00 */	stw r0, 0(r8)
/* 8021006C 0020CFCC  48 00 02 70 */	b lbl_802102DC
lbl_80210070:
/* 80210070 0020CFD0  80 C8 00 00 */	lwz r6, 0(r8)
/* 80210074 0020CFD4  54 00 48 2C */	slwi r0, r0, 9
/* 80210078 0020CFD8  54 C6 05 EA */	rlwinm r6, r6, 0, 0x17, 0x15
/* 8021007C 0020CFDC  7C C0 03 78 */	or r0, r6, r0
/* 80210080 0020CFE0  90 08 00 00 */	stw r0, 0(r8)
/* 80210084 0020CFE4  80 08 00 00 */	lwz r0, 0(r8)
/* 80210088 0020CFE8  54 00 00 7E */	clrlwi r0, r0, 1
/* 8021008C 0020CFEC  90 08 00 00 */	stw r0, 0(r8)
/* 80210090 0020CFF0  48 00 02 4C */	b lbl_802102DC
.global lbl_80210094
lbl_80210094:
/* 80210094 0020CFF4  81 68 00 00 */	lwz r11, 0(r8)
/* 80210098 0020CFF8  54 07 68 24 */	slwi r7, r0, 0xd
/* 8021009C 0020CFFC  54 C0 70 22 */	slwi r0, r6, 0xe
/* 802100A0 0020D000  55 66 04 E2 */	rlwinm r6, r11, 0, 0x13, 0x11
/* 802100A4 0020D004  7C C6 3B 78 */	or r6, r6, r7
/* 802100A8 0020D008  90 C8 00 00 */	stw r6, 0(r8)
/* 802100AC 0020D00C  80 C8 00 00 */	lwz r6, 0(r8)
/* 802100B0 0020D010  54 C6 04 9C */	rlwinm r6, r6, 0, 0x12, 0xe
/* 802100B4 0020D014  7C C0 03 78 */	or r0, r6, r0
/* 802100B8 0020D018  90 08 00 00 */	stw r0, 0(r8)
/* 802100BC 0020D01C  48 00 02 20 */	b lbl_802102DC
.global lbl_802100C0
lbl_802100C0:
/* 802100C0 0020D020  81 68 00 00 */	lwz r11, 0(r8)
/* 802100C4 0020D024  54 07 88 1C */	slwi r7, r0, 0x11
/* 802100C8 0020D028  54 C0 90 1A */	slwi r0, r6, 0x12
/* 802100CC 0020D02C  55 66 03 DA */	rlwinm r6, r11, 0, 0xf, 0xd
/* 802100D0 0020D030  7C C6 3B 78 */	or r6, r6, r7
/* 802100D4 0020D034  90 C8 00 00 */	stw r6, 0(r8)
/* 802100D8 0020D038  80 C8 00 00 */	lwz r6, 0(r8)
/* 802100DC 0020D03C  54 C6 03 94 */	rlwinm r6, r6, 0, 0xe, 0xa
/* 802100E0 0020D040  7C C0 03 78 */	or r0, r6, r0
/* 802100E4 0020D044  90 08 00 00 */	stw r0, 0(r8)
/* 802100E8 0020D048  48 00 01 F4 */	b lbl_802102DC
.global lbl_802100EC
lbl_802100EC:
/* 802100EC 0020D04C  81 68 00 00 */	lwz r11, 0(r8)
/* 802100F0 0020D050  54 00 A8 14 */	slwi r0, r0, 0x15
/* 802100F4 0020D054  54 C6 B0 12 */	slwi r6, r6, 0x16
/* 802100F8 0020D058  55 6B 02 D2 */	rlwinm r11, r11, 0, 0xb, 9
/* 802100FC 0020D05C  7D 60 03 78 */	or r0, r11, r0
/* 80210100 0020D060  90 08 00 00 */	stw r0, 0(r8)
/* 80210104 0020D064  54 E0 C8 0C */	slwi r0, r7, 0x19
/* 80210108 0020D068  80 E8 00 00 */	lwz r7, 0(r8)
/* 8021010C 0020D06C  54 E7 02 8C */	rlwinm r7, r7, 0, 0xa, 6
/* 80210110 0020D070  7C E6 33 78 */	or r6, r7, r6
/* 80210114 0020D074  90 C8 00 00 */	stw r6, 0(r8)
/* 80210118 0020D078  80 C8 00 00 */	lwz r6, 0(r8)
/* 8021011C 0020D07C  54 C6 01 C2 */	rlwinm r6, r6, 0, 7, 1
/* 80210120 0020D080  7C C0 03 78 */	or r0, r6, r0
/* 80210124 0020D084  90 08 00 00 */	stw r0, 0(r8)
/* 80210128 0020D088  48 00 01 B4 */	b lbl_802102DC
.global lbl_8021012C
lbl_8021012C:
/* 8021012C 0020D08C  81 89 00 00 */	lwz r12, 0(r9)
/* 80210130 0020D090  54 CB 08 3C */	slwi r11, r6, 1
/* 80210134 0020D094  54 E6 20 36 */	slwi r6, r7, 4
/* 80210138 0020D098  55 87 00 3C */	rlwinm r7, r12, 0, 0, 0x1e
/* 8021013C 0020D09C  7C E0 03 78 */	or r0, r7, r0
/* 80210140 0020D0A0  90 09 00 00 */	stw r0, 0(r9)
/* 80210144 0020D0A4  80 09 00 00 */	lwz r0, 0(r9)
/* 80210148 0020D0A8  54 00 07 F6 */	rlwinm r0, r0, 0, 0x1f, 0x1b
/* 8021014C 0020D0AC  7C 00 5B 78 */	or r0, r0, r11
/* 80210150 0020D0B0  90 09 00 00 */	stw r0, 0(r9)
/* 80210154 0020D0B4  80 09 00 00 */	lwz r0, 0(r9)
/* 80210158 0020D0B8  54 00 07 2C */	rlwinm r0, r0, 0, 0x1c, 0x16
/* 8021015C 0020D0BC  7C 00 33 78 */	or r0, r0, r6
/* 80210160 0020D0C0  90 09 00 00 */	stw r0, 0(r9)
/* 80210164 0020D0C4  48 00 01 78 */	b lbl_802102DC
.global lbl_80210168
lbl_80210168:
/* 80210168 0020D0C8  81 69 00 00 */	lwz r11, 0(r9)
/* 8021016C 0020D0CC  54 00 48 2C */	slwi r0, r0, 9
/* 80210170 0020D0D0  54 C6 50 2A */	slwi r6, r6, 0xa
/* 80210174 0020D0D4  55 6B 05 EA */	rlwinm r11, r11, 0, 0x17, 0x15
/* 80210178 0020D0D8  7D 60 03 78 */	or r0, r11, r0
/* 8021017C 0020D0DC  90 09 00 00 */	stw r0, 0(r9)
/* 80210180 0020D0E0  54 E0 68 24 */	slwi r0, r7, 0xd
/* 80210184 0020D0E4  80 E9 00 00 */	lwz r7, 0(r9)
/* 80210188 0020D0E8  54 E7 05 A4 */	rlwinm r7, r7, 0, 0x16, 0x12
/* 8021018C 0020D0EC  7C E6 33 78 */	or r6, r7, r6
/* 80210190 0020D0F0  90 C9 00 00 */	stw r6, 0(r9)
/* 80210194 0020D0F4  80 C9 00 00 */	lwz r6, 0(r9)
/* 80210198 0020D0F8  54 C6 04 DA */	rlwinm r6, r6, 0, 0x13, 0xd
/* 8021019C 0020D0FC  7C C0 03 78 */	or r0, r6, r0

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 801624A4 0015F404  DB E1 00 E0 */	stfd f31, 0xe0(r1)
/* 801624A8 0015F408  DB C1 00 D8 */	stfd f30, 0xd8(r1)
/* 801624AC 0015F40C  BF 21 00 BC */	stmw r25, 0xbc(r1)
/* 801624B0 0015F410  7C 79 1B 78 */	mr r25, r3
/* 801624B4 0015F414  C0 02 AA B4 */	lfs f0, lbl_803EACB4@sda21(r2)
/* 801624B8 0015F418  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 801624BC 0015F41C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801624C0 0015F420  40 81 04 00 */	ble lbl_801628C0
/* 801624C4 0015F424  C0 02 AA B8 */	lfs f0, lbl_803EACB8@sda21(r2)
/* 801624C8 0015F428  38 00 00 02 */	li r0, 2
/* 801624CC 0015F42C  7C 09 03 A6 */	mtctr r0
/* 801624D0 0015F430  38 79 00 00 */	addi r3, r25, 0
/* 801624D4 0015F434  EC 60 08 28 */	fsubs f3, f0, f1
/* 801624D8 0015F438  38 A4 00 00 */	addi r5, r4, 0
/* 801624DC 0015F43C  38 D9 00 00 */	addi r6, r25, 0
lbl_801624E0:
/* 801624E0 0015F440  C0 03 04 90 */	lfs f0, 0x490(r3)
/* 801624E4 0015F444  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 801624E8 0015F448  C0 25 00 0C */	lfs f1, 0xc(r5)
/* 801624EC 0015F44C  EC 03 00 32 */	fmuls f0, f3, f0
/* 801624F0 0015F450  EC 22 00 72 */	fmuls f1, f2, f1
/* 801624F4 0015F454  EC 01 00 2A */	fadds f0, f1, f0
/* 801624F8 0015F458  D0 06 00 5C */	stfs f0, 0x5c(r6)
/* 801624FC 0015F45C  C0 03 04 A0 */	lfs f0, 0x4a0(r3)
/* 80162500 0015F460  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 80162504 0015F464  C0 25 00 1C */	lfs f1, 0x1c(r5)
/* 80162508 0015F468  EC 03 00 32 */	fmuls f0, f3, f0
/* 8016250C 0015F46C  EC 22 00 72 */	fmuls f1, f2, f1
/* 80162510 0015F470  EC 01 00 2A */	fadds f0, f1, f0
/* 80162514 0015F474  D0 06 00 60 */	stfs f0, 0x60(r6)
/* 80162518 0015F478  C0 03 04 B0 */	lfs f0, 0x4b0(r3)
/* 8016251C 0015F47C  C0 25 00 2C */	lfs f1, 0x2c(r5)
/* 80162520 0015F480  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 80162524 0015F484  EC 03 00 32 */	fmuls f0, f3, f0
/* 80162528 0015F488  EC 22 00 72 */	fmuls f1, f2, f1
/* 8016252C 0015F48C  EC 01 00 2A */	fadds f0, f1, f0
/* 80162530 0015F490  D0 06 00 64 */	stfs f0, 0x64(r6)
/* 80162534 0015F494  C0 03 04 D0 */	lfs f0, 0x4d0(r3)
/* 80162538 0015F498  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 8016253C 0015F49C  C0 25 00 4C */	lfs f1, 0x4c(r5)
/* 80162540 0015F4A0  EC 03 00 32 */	fmuls f0, f3, f0
/* 80162544 0015F4A4  EC 22 00 72 */	fmuls f1, f2, f1
/* 80162548 0015F4A8  EC 01 00 2A */	fadds f0, f1, f0
/* 8016254C 0015F4AC  D0 06 00 68 */	stfs f0, 0x68(r6)
/* 80162550 0015F4B0  C0 03 04 E0 */	lfs f0, 0x4e0(r3)
/* 80162554 0015F4B4  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 80162558 0015F4B8  C0 25 00 5C */	lfs f1, 0x5c(r5)
/* 8016255C 0015F4BC  EC 03 00 32 */	fmuls f0, f3, f0
/* 80162560 0015F4C0  EC 22 00 72 */	fmuls f1, f2, f1
/* 80162564 0015F4C4  EC 01 00 2A */	fadds f0, f1, f0
/* 80162568 0015F4C8  D0 06 00 6C */	stfs f0, 0x6c(r6)
/* 8016256C 0015F4CC  C0 03 04 F0 */	lfs f0, 0x4f0(r3)
/* 80162570 0015F4D0  C0 25 00 6C */	lfs f1, 0x6c(r5)
/* 80162574 0015F4D4  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 80162578 0015F4D8  EC 03 00 32 */	fmuls f0, f3, f0
/* 8016257C 0015F4DC  EC 22 00 72 */	fmuls f1, f2, f1
/* 80162580 0015F4E0  EC 01 00 2A */	fadds f0, f1, f0
/* 80162584 0015F4E4  D0 06 00 70 */	stfs f0, 0x70(r6)
/* 80162588 0015F4E8  C0 03 05 10 */	lfs f0, 0x510(r3)
/* 8016258C 0015F4EC  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 80162590 0015F4F0  C0 25 00 8C */	lfs f1, 0x8c(r5)
/* 80162594 0015F4F4  EC 03 00 32 */	fmuls f0, f3, f0
/* 80162598 0015F4F8  EC 22 00 72 */	fmuls f1, f2, f1
/* 8016259C 0015F4FC  EC 01 00 2A */	fadds f0, f1, f0
/* 801625A0 0015F500  D0 06 00 74 */	stfs f0, 0x74(r6)
/* 801625A4 0015F504  C0 03 05 20 */	lfs f0, 0x520(r3)
/* 801625A8 0015F508  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 801625AC 0015F50C  C0 25 00 9C */	lfs f1, 0x9c(r5)
/* 801625B0 0015F510  EC 03 00 32 */	fmuls f0, f3, f0
/* 801625B4 0015F514  EC 22 00 72 */	fmuls f1, f2, f1
/* 801625B8 0015F518  EC 01 00 2A */	fadds f0, f1, f0
/* 801625BC 0015F51C  D0 06 00 78 */	stfs f0, 0x78(r6)
/* 801625C0 0015F520  C0 03 05 30 */	lfs f0, 0x530(r3)
/* 801625C4 0015F524  C0 25 00 AC */	lfs f1, 0xac(r5)
/* 801625C8 0015F528  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 801625CC 0015F52C  EC 03 00 32 */	fmuls f0, f3, f0
/* 801625D0 0015F530  EC 22 00 72 */	fmuls f1, f2, f1
/* 801625D4 0015F534  EC 01 00 2A */	fadds f0, f1, f0
/* 801625D8 0015F538  D0 06 00 7C */	stfs f0, 0x7c(r6)
/* 801625DC 0015F53C  C0 03 05 50 */	lfs f0, 0x550(r3)
/* 801625E0 0015F540  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 801625E4 0015F544  C0 25 00 CC */	lfs f1, 0xcc(r5)
/* 801625E8 0015F548  EC 03 00 32 */	fmuls f0, f3, f0
/* 801625EC 0015F54C  EC 22 00 72 */	fmuls f1, f2, f1
/* 801625F0 0015F550  EC 01 00 2A */	fadds f0, f1, f0
/* 801625F4 0015F554  D0 06 00 80 */	stfs f0, 0x80(r6)
/* 801625F8 0015F558  C0 03 05 60 */	lfs f0, 0x560(r3)
/* 801625FC 0015F55C  C0 59 00 0C */	lfs f2, 0xc(r25)
/* 80162600 0015F560  C0 25 00 DC */	lfs f1, 0xdc(r5)

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global v0
v0:
	.4byte 0x00001000
.global v1
v1:
	.4byte 0x00005555

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E8290
lbl_803E8290:
	.4byte 0x4B7FFFFF
	.4byte 0x00000000
.global "@58"
"@58":
	.4byte 0x43300000
	.4byte 0x80000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E83B0
lbl_803E83B0:
	.4byte 0x3F4CCCCD
	.4byte 0x00000000
.global "@118"
"@118":
	.4byte 0x43300000
	.4byte 0x80000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E989C
lbl_803E989C:
	.4byte 0x43200000
.global lbl_803E98A0
lbl_803E98A0:
	.4byte 0x42C80000
.global lbl_803E98A4
lbl_803E98A4:
	.4byte 0x43160000
.global lbl_803E98A8
lbl_803E98A8:
	.4byte 0x43480000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E8F68
lbl_803E8F68:
	.4byte 0x40E00000
	.4byte 0x00000000
.global lbl_803E8F70
lbl_803E8F70:
	.4byte 0x3F000000
.global lbl_803E8F74
lbl_803E8F74:
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E8B50
lbl_803E8B50:
	.4byte 0x3F800000
.global lbl_803E8B54
lbl_803E8B54:
	.4byte 0xC1200000
.global lbl_803E8B58
lbl_803E8B58:
	.4byte 0x42C80000
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EAF78
lbl_803EAF78:
	.4byte 0x3C0EFA35
.global lbl_803EAF7C
lbl_803EAF7C:
	.4byte 0x3F000000
.global lbl_803EAF80
lbl_803EAF80:
	.4byte 0x41A00000
.global lbl_803EAF84
lbl_803EAF84:
	.4byte 0x403FFFF3
