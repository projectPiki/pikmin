.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global makeObjectActor__Fv
makeObjectActor__Fv:
/* 80119B30 00116A90  7C 08 02 A6 */	mflr r0
/* 80119B34 00116A94  38 60 00 1C */	li r3, 0x1c
/* 80119B38 00116A98  90 01 00 04 */	stw r0, 4(r1)
/* 80119B3C 00116A9C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80119B40 00116AA0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80119B44 00116AA4  4B F2 D4 C1 */	bl alloc__6SystemFUl
/* 80119B48 00116AA8  3B E3 00 00 */	addi r31, r3, 0
/* 80119B4C 00116AAC  7F E3 FB 79 */	or. r3, r31, r31
/* 80119B50 00116AB0  41 82 00 40 */	beq .L_80119B90
/* 80119B54 00116AB4  3C 80 80 2C */	lis r4, lbl_802C37E8@ha
/* 80119B58 00116AB8  3C A0 80 2C */	lis r5, lbl_802C37DC@ha
/* 80119B5C 00116ABC  38 C4 37 E8 */	addi r6, r4, lbl_802C37E8@l
/* 80119B60 00116AC0  3C 80 61 63 */	lis r4, 0x61637472@ha
/* 80119B64 00116AC4  38 A5 37 DC */	addi r5, r5, lbl_802C37DC@l
/* 80119B68 00116AC8  38 84 74 72 */	addi r4, r4, 0x61637472@l
/* 80119B6C 00116ACC  4B FC 11 49 */	bl __ct__7GenBaseFUlPcPc
/* 80119B70 00116AD0  3C 60 80 2C */	lis r3, __vt__9GenObject@ha
/* 80119B74 00116AD4  38 03 AB 70 */	addi r0, r3, __vt__9GenObject@l
/* 80119B78 00116AD8  3C 60 80 2C */	lis r3, __vt__14GenObjectActor@ha
/* 80119B7C 00116ADC  90 1F 00 04 */	stw r0, 4(r31)
/* 80119B80 00116AE0  38 03 38 6C */	addi r0, r3, __vt__14GenObjectActor@l
/* 80119B84 00116AE4  90 1F 00 04 */	stw r0, 4(r31)
/* 80119B88 00116AE8  38 00 00 00 */	li r0, 0
/* 80119B8C 00116AEC  90 1F 00 18 */	stw r0, 0x18(r31)
.L_80119B90:
/* 80119B90 00116AF0  7F E3 FB 78 */	mr r3, r31
/* 80119B94 00116AF4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80119B98 00116AF8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80119B9C 00116AFC  38 21 00 10 */	addi r1, r1, 0x10
/* 80119BA0 00116B00  7C 08 03 A6 */	mtlr r0
/* 80119BA4 00116B04  4E 80 00 20 */	blr 

.global initialise__14GenObjectActorFv
initialise__14GenObjectActorFv:
/* 80119BA8 00116B08  80 ED 30 74 */	lwz r7, factory__16GenObjectFactory@sda21(r13)
/* 80119BAC 00116B0C  80 A7 00 00 */	lwz r5, 0(r7)
/* 80119BB0 00116B10  80 07 00 04 */	lwz r0, 4(r7)
/* 80119BB4 00116B14  7C 05 00 00 */	cmpw r5, r0
/* 80119BB8 00116B18  4C 80 00 20 */	bgelr 
/* 80119BBC 00116B1C  3C 80 61 63 */	lis r4, 0x61637472@ha
/* 80119BC0 00116B20  80 67 00 08 */	lwz r3, 8(r7)
/* 80119BC4 00116B24  38 84 74 72 */	addi r4, r4, 0x61637472@l
/* 80119BC8 00116B28  54 A0 20 36 */	slwi r0, r5, 4
/* 80119BCC 00116B2C  7C 83 01 2E */	stwx r4, r3, r0
/* 80119BD0 00116B30  3C C0 80 12 */	lis r6, makeObjectActor__Fv@ha
/* 80119BD4 00116B34  3C 80 80 2C */	lis r4, lbl_802C37F8@ha
/* 80119BD8 00116B38  80 07 00 00 */	lwz r0, 0(r7)
/* 80119BDC 00116B3C  3C 60 76 30 */	lis r3, 0x76302E30@ha
/* 80119BE0 00116B40  80 A7 00 08 */	lwz r5, 8(r7)
/* 80119BE4 00116B44  38 C6 9B 30 */	addi r6, r6, makeObjectActor__Fv@l
/* 80119BE8 00116B48  54 00 20 36 */	slwi r0, r0, 4
/* 80119BEC 00116B4C  7C A5 02 14 */	add r5, r5, r0
/* 80119BF0 00116B50  90 C5 00 04 */	stw r6, 4(r5)
/* 80119BF4 00116B54  38 A4 37 F8 */	addi r5, r4, lbl_802C37F8@l
/* 80119BF8 00116B58  38 83 2E 30 */	addi r4, r3, 0x76302E30@l
/* 80119BFC 00116B5C  80 07 00 00 */	lwz r0, 0(r7)
/* 80119C00 00116B60  80 67 00 08 */	lwz r3, 8(r7)
/* 80119C04 00116B64  54 00 20 36 */	slwi r0, r0, 4
/* 80119C08 00116B68  7C 63 02 14 */	add r3, r3, r0
/* 80119C0C 00116B6C  90 A3 00 08 */	stw r5, 8(r3)
/* 80119C10 00116B70  80 07 00 00 */	lwz r0, 0(r7)
/* 80119C14 00116B74  80 67 00 08 */	lwz r3, 8(r7)
/* 80119C18 00116B78  54 00 20 36 */	slwi r0, r0, 4
/* 80119C1C 00116B7C  7C 63 02 14 */	add r3, r3, r0
/* 80119C20 00116B80  90 83 00 0C */	stw r4, 0xc(r3)
/* 80119C24 00116B84  80 67 00 00 */	lwz r3, 0(r7)
/* 80119C28 00116B88  38 03 00 01 */	addi r0, r3, 1
/* 80119C2C 00116B8C  90 07 00 00 */	stw r0, 0(r7)
/* 80119C30 00116B90  4E 80 00 20 */	blr 

.global doRead__14GenObjectActorFR18RandomAccessStream
doRead__14GenObjectActorFR18RandomAccessStream:
/* 80119C34 00116B94  7C 08 02 A6 */	mflr r0
/* 80119C38 00116B98  90 01 00 04 */	stw r0, 4(r1)
/* 80119C3C 00116B9C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80119C40 00116BA0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80119C44 00116BA4  3B E3 00 00 */	addi r31, r3, 0
/* 80119C48 00116BA8  38 64 00 00 */	addi r3, r4, 0
/* 80119C4C 00116BAC  81 84 00 04 */	lwz r12, 4(r4)
/* 80119C50 00116BB0  81 8C 00 08 */	lwz r12, 8(r12)
/* 80119C54 00116BB4  7D 88 03 A6 */	mtlr r12
/* 80119C58 00116BB8  4E 80 00 21 */	blrl 
/* 80119C5C 00116BBC  90 7F 00 18 */	stw r3, 0x18(r31)
/* 80119C60 00116BC0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80119C64 00116BC4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80119C68 00116BC8  38 21 00 18 */	addi r1, r1, 0x18
/* 80119C6C 00116BCC  7C 08 03 A6 */	mtlr r0
/* 80119C70 00116BD0  4E 80 00 20 */	blr 

.global birth__14GenObjectActorFR9BirthInfo
birth__14GenObjectActorFR9BirthInfo:
/* 80119C74 00116BD4  7C 08 02 A6 */	mflr r0
/* 80119C78 00116BD8  90 01 00 04 */	stw r0, 4(r1)
/* 80119C7C 00116BDC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80119C80 00116BE0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80119C84 00116BE4  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80119C88 00116BE8  3B C4 00 00 */	addi r30, r4, 0
/* 80119C8C 00116BEC  38 80 00 00 */	li r4, 0
/* 80119C90 00116BF0  80 6D 31 30 */	lwz r3, actorMgr@sda21(r13)
/* 80119C94 00116BF4  4B FF FE 21 */	bl newActor__8ActorMgrFi
/* 80119C98 00116BF8  7C 7F 1B 78 */	mr r31, r3
/* 80119C9C 00116BFC  81 9F 00 00 */	lwz r12, 0(r31)
/* 80119CA0 00116C00  7F C4 F3 78 */	mr r4, r30
/* 80119CA4 00116C04  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 80119CA8 00116C08  7D 88 03 A6 */	mtlr r12
/* 80119CAC 00116C0C  4E 80 00 21 */	blrl 
/* 80119CB0 00116C10  7F E3 FB 78 */	mr r3, r31
/* 80119CB4 00116C14  81 9F 00 00 */	lwz r12, 0(r31)
/* 80119CB8 00116C18  38 80 00 00 */	li r4, 0
/* 80119CBC 00116C1C  81 8C 00 34 */	lwz r12, 0x34(r12)
/* 80119CC0 00116C20  7D 88 03 A6 */	mtlr r12
/* 80119CC4 00116C24  4E 80 00 21 */	blrl 
/* 80119CC8 00116C28  7F E3 FB 78 */	mr r3, r31
/* 80119CCC 00116C2C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80119CD0 00116C30  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80119CD4 00116C34  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80119CD8 00116C38  38 21 00 18 */	addi r1, r1, 0x18
/* 80119CDC 00116C3C  7C 08 03 A6 */	mtlr r0
/* 80119CE0 00116C40  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C37C0:
	.asciz "genActor.cpp"
.balign 4
lbl_802C37D0:
	.asciz "genActor"
.balign 4
lbl_802C37DC:
	.asciz "object type"
.balign 4
lbl_802C37E8:
	.asciz "create actor"
.balign 4
lbl_802C37F8:
	.asciz "create Actor"
.balign 4
lbl_802C3808:
	.asciz "GenObjectActor"
.balign 4
lbl_802C3818:
	.asciz "Parameters"
.balign 4
lbl_802C3824:
	.4byte __RTTI__10Parameters
	.4byte 0
	.4byte 0
.balign 4
lbl_802C3830:
	.asciz "GenObject"
.balign 4
lbl_802C383C:
	.4byte __RTTI__10Parameters
	.4byte 0
	.4byte __RTTI__7GenBase
	.4byte 0
	.4byte 0
lbl_802C3850:
	.4byte __RTTI__10Parameters
	.4byte 0
	.4byte __RTTI__7GenBase
	.4byte 0
	.4byte __RTTI__9GenObject
	.4byte 0
	.4byte 0
.global __vt__14GenObjectActor
__vt__14GenObjectActor:
	.4byte __RTTI__14GenObjectActor
	.4byte 0
	.4byte doWrite__7GenBaseFR18RandomAccessStream
	.4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
	.4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
	.4byte doRead__14GenObjectActorFR18RandomAccessStream
	.4byte update__7GenBaseFv
	.4byte render__7GenBaseFR8Graphics
	.4byte getLatestVersion__9GenObjectFv
	.4byte updateUseList__9GenObjectFP9Generatori
	.4byte init__9GenObjectFP9Generator
	.4byte update__9GenObjectFP9Generator
	.4byte render__9GenObjectFR8GraphicsP9Generator
	.4byte birth__14GenObjectActorFR9BirthInfo

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__10Parameters:
	.4byte lbl_802C3818
	.4byte 0
.balign 4
lbl_803E2DD8:
	.asciz "GenBase"
.balign 4
__RTTI__7GenBase:
	.4byte lbl_803E2DD8
	.4byte lbl_802C3824
__RTTI__9GenObject:
	.4byte lbl_802C3830
	.4byte lbl_802C383C
__RTTI__14GenObjectActor:
	.4byte lbl_802C3808
	.4byte lbl_802C3850
