.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global preCacheShapes__16GameSetupSectionFv
preCacheShapes__16GameSetupSectionFv:
/* 80054B34 00051A94  7C 08 02 A6 */	mflr r0
/* 80054B38 00051A98  3C 60 80 2A */	lis r3, lbl_802A69A8@ha
/* 80054B3C 00051A9C  90 01 00 04 */	stw r0, 4(r1)
/* 80054B40 00051AA0  38 0D 8C 38 */	addi r0, r13, lbl_803DD958@sda21
/* 80054B44 00051AA4  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80054B48 00051AA8  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80054B4C 00051AAC  3B E3 69 A8 */	addi r31, r3, lbl_802A69A8@l
/* 80054B50 00051AB0  38 60 00 00 */	li r3, 0
/* 80054B54 00051AB4  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80054B58 00051AB8  93 A1 00 24 */	stw r29, 0x24(r1)
/* 80054B5C 00051ABC  3B BF 09 D4 */	addi r29, r31, 0x9d4
/* 80054B60 00051AC0  80 CD 2D EC */	lwz r6, gsys@sda21(r13)
/* 80054B64 00051AC4  38 A6 03 1C */	addi r5, r6, 0x31c
/* 80054B68 00051AC8  80 86 03 20 */	lwz r4, 0x320(r6)
/* 80054B6C 00051ACC  80 E6 03 20 */	lwz r7, 0x320(r6)
/* 80054B70 00051AD0  39 06 03 10 */	addi r8, r6, 0x310
/* 80054B74 00051AD4  80 C6 03 1C */	lwz r6, 0x31c(r6)
/* 80054B78 00051AD8  80 A5 00 08 */	lwz r5, 8(r5)
/* 80054B7C 00051ADC  7C A6 2A 14 */	add r5, r6, r5
/* 80054B80 00051AE0  90 88 00 00 */	stw r4, 0(r8)
/* 80054B84 00051AE4  7C 87 28 50 */	subf r4, r7, r5
/* 80054B88 00051AE8  90 88 00 08 */	stw r4, 8(r8)
/* 80054B8C 00051AEC  80 88 00 00 */	lwz r4, 0(r8)
/* 80054B90 00051AF0  90 88 00 04 */	stw r4, 4(r8)
/* 80054B94 00051AF4  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 80054B98 00051AF8  38 85 03 10 */	addi r4, r5, 0x310
/* 80054B9C 00051AFC  90 85 03 28 */	stw r4, 0x328(r5)
/* 80054BA0 00051B00  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80054BA4 00051B04  38 84 02 14 */	addi r4, r4, 0x214
/* 80054BA8 00051B08  90 64 00 10 */	stw r3, 0x10(r4)
/* 80054BAC 00051B0C  90 64 00 0C */	stw r3, 0xc(r4)
/* 80054BB0 00051B10  90 64 00 08 */	stw r3, 8(r4)
/* 80054BB4 00051B14  90 04 00 04 */	stw r0, 4(r4)
/* 80054BB8 00051B18  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80054BBC 00051B1C  38 03 02 14 */	addi r0, r3, 0x214
/* 80054BC0 00051B20  90 03 02 28 */	stw r0, 0x228(r3)
/* 80054BC4 00051B24  48 00 00 20 */	b .L_80054BE4
.L_80054BC8:
/* 80054BC8 00051B28  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80054BCC 00051B2C  80 BD 00 04 */	lwz r5, 4(r29)
/* 80054BD0 00051B30  81 83 01 A0 */	lwz r12, 0x1a0(r3)
/* 80054BD4 00051B34  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80054BD8 00051B38  7D 88 03 A6 */	mtlr r12
/* 80054BDC 00051B3C  4E 80 00 21 */	blrl 
/* 80054BE0 00051B40  3B BD 00 08 */	addi r29, r29, 8
.L_80054BE4:
/* 80054BE4 00051B44  80 9D 00 00 */	lwz r4, 0(r29)
/* 80054BE8 00051B48  28 04 00 00 */	cmplwi r4, 0
/* 80054BEC 00051B4C  40 82 FF DC */	bne .L_80054BC8
/* 80054BF0 00051B50  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80054BF4 00051B54  3C 60 80 3A */	lis r3, gameflow@ha
/* 80054BF8 00051B58  84 A4 00 1C */	lwzu r5, 0x1c(r4)
/* 80054BFC 00051B5C  38 00 00 01 */	li r0, 1
/* 80054C00 00051B60  3B C3 D7 B8 */	addi r30, r3, gameflow@l
/* 80054C04 00051B64  90 04 00 00 */	stw r0, 0(r4)
/* 80054C08 00051B68  3B BF 01 74 */	addi r29, r31, 0x174
/* 80054C0C 00051B6C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80054C10 00051B70  90 A3 00 1C */	stw r5, 0x1c(r3)
/* 80054C14 00051B74  48 00 00 38 */	b .L_80054C4C
.L_80054C18:
/* 80054C18 00051B78  38 7E 00 00 */	addi r3, r30, 0
/* 80054C1C 00051B7C  38 A0 00 01 */	li r5, 1
/* 80054C20 00051B80  4B FF E0 F1 */	bl loadShape__8GameFlowFPcb
/* 80054C24 00051B84  80 1D 00 04 */	lwz r0, 4(r29)
/* 80054C28 00051B88  28 00 00 00 */	cmplwi r0, 0
/* 80054C2C 00051B8C  41 82 00 1C */	beq .L_80054C48
/* 80054C30 00051B90  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80054C34 00051B94  38 A0 00 00 */	li r5, 0
/* 80054C38 00051B98  90 64 01 FC */	stw r3, 0x1fc(r4)
/* 80054C3C 00051B9C  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80054C40 00051BA0  80 9D 00 04 */	lwz r4, 4(r29)
/* 80054C44 00051BA4  4B FE B1 91 */	bl loadBundle__9StdSystemFPcb
.L_80054C48:
/* 80054C48 00051BA8  3B BD 00 08 */	addi r29, r29, 8
.L_80054C4C:
/* 80054C4C 00051BAC  80 9D 00 00 */	lwz r4, 0(r29)
/* 80054C50 00051BB0  28 04 00 00 */	cmplwi r4, 0
/* 80054C54 00051BB4  40 82 FF C4 */	bne .L_80054C18
/* 80054C58 00051BB8  3C 60 80 3A */	lis r3, gameflow@ha
/* 80054C5C 00051BBC  3B DF 05 CC */	addi r30, r31, 0x5cc
/* 80054C60 00051BC0  3B E3 D7 B8 */	addi r31, r3, gameflow@l
/* 80054C64 00051BC4  48 00 00 38 */	b .L_80054C9C
.L_80054C68:
/* 80054C68 00051BC8  38 7F 00 00 */	addi r3, r31, 0
/* 80054C6C 00051BCC  38 A0 00 01 */	li r5, 1
/* 80054C70 00051BD0  4B FF E0 A1 */	bl loadShape__8GameFlowFPcb
/* 80054C74 00051BD4  80 1E 00 04 */	lwz r0, 4(r30)
/* 80054C78 00051BD8  28 00 00 00 */	cmplwi r0, 0
/* 80054C7C 00051BDC  41 82 00 1C */	beq .L_80054C98
/* 80054C80 00051BE0  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80054C84 00051BE4  38 A0 00 00 */	li r5, 0
/* 80054C88 00051BE8  90 64 01 FC */	stw r3, 0x1fc(r4)
/* 80054C8C 00051BEC  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80054C90 00051BF0  80 9E 00 04 */	lwz r4, 4(r30)
/* 80054C94 00051BF4  4B FE B1 41 */	bl loadBundle__9StdSystemFPcb
.L_80054C98:
/* 80054C98 00051BF8  3B DE 00 08 */	addi r30, r30, 8
.L_80054C9C:
/* 80054C9C 00051BFC  80 9E 00 00 */	lwz r4, 0(r30)
/* 80054CA0 00051C00  28 04 00 00 */	cmplwi r4, 0
/* 80054CA4 00051C04  40 82 FF C4 */	bne .L_80054C68
/* 80054CA8 00051C08  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80054CAC 00051C0C  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80054CB0 00051C10  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80054CB4 00051C14  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 80054CB8 00051C18  38 21 00 30 */	addi r1, r1, 0x30
/* 80054CBC 00051C1C  7C 08 03 A6 */	mtlr r0
/* 80054CC0 00051C20  4E 80 00 20 */	blr 

.global __ct__16GameSetupSectionFv
__ct__16GameSetupSectionFv:
/* 80054CC4 00051C24  7C 08 02 A6 */	mflr r0
/* 80054CC8 00051C28  3C 80 80 2A */	lis r4, lbl_802A69A8@ha
/* 80054CCC 00051C2C  90 01 00 04 */	stw r0, 4(r1)
/* 80054CD0 00051C30  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 80054CD4 00051C34  BE 61 00 24 */	stmw r19, 0x24(r1)
/* 80054CD8 00051C38  3A A4 69 A8 */	addi r21, r4, lbl_802A69A8@l
/* 80054CDC 00051C3C  3B E3 00 00 */	addi r31, r3, 0
/* 80054CE0 00051C40  38 8D 8C 3C */	addi r4, r13, lbl_803DD95C@sda21
/* 80054CE4 00051C44  4B FE 02 D5 */	bl __ct__8CoreNodeFPc
/* 80054CE8 00051C48  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 80054CEC 00051C4C  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 80054CF0 00051C50  90 1F 00 00 */	stw r0, 0(r31)
/* 80054CF4 00051C54  38 7F 00 00 */	addi r3, r31, 0
/* 80054CF8 00051C58  38 8D 8C 3C */	addi r4, r13, lbl_803DD95C@sda21
/* 80054CFC 00051C5C  4B FE BA 41 */	bl init__4NodeFPc
/* 80054D00 00051C60  3C 60 80 2A */	lis r3, __vt__7Section@ha
/* 80054D04 00051C64  38 03 64 2C */	addi r0, r3, __vt__7Section@l
/* 80054D08 00051C68  3C 60 80 2A */	lis r3, __vt__16GameSetupSection@ha
/* 80054D0C 00051C6C  90 1F 00 00 */	stw r0, 0(r31)
/* 80054D10 00051C70  38 03 74 CC */	addi r0, r3, __vt__16GameSetupSection@l
/* 80054D14 00051C74  90 1F 00 00 */	stw r0, 0(r31)
/* 80054D18 00051C78  38 7F 00 00 */	addi r3, r31, 0
/* 80054D1C 00051C7C  38 95 0A 64 */	addi r4, r21, 0xa64
/* 80054D20 00051C80  4B FE BA 1D */	bl init__4NodeFPc
/* 80054D24 00051C84  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80054D28 00051C88  38 80 00 02 */	li r4, 2
/* 80054D2C 00051C8C  4B FE A2 F5 */	bl getHeap__9StdSystemFi
/* 80054D30 00051C90  7C 7E 1B 78 */	mr r30, r3
/* 80054D34 00051C94  82 C3 00 00 */	lwz r22, 0(r3)
/* 80054D38 00051C98  38 00 00 01 */	li r0, 1
/* 80054D3C 00051C9C  38 60 00 A0 */	li r3, 0xa0
/* 80054D40 00051CA0  90 1E 00 00 */	stw r0, 0(r30)
/* 80054D44 00051CA4  4B FF 22 C1 */	bl alloc__6SystemFUl
/* 80054D48 00051CA8  3A 63 00 00 */	addi r19, r3, 0
/* 80054D4C 00051CAC  7E 63 9B 79 */	or. r3, r19, r19
/* 80054D50 00051CB0  41 82 00 08 */	beq .L_80054D58
/* 80054D54 00051CB4  48 03 19 3D */	bl __ct__7MemStatFv
.L_80054D58:
/* 80054D58 00051CB8  92 6D 2F E8 */	stw r19, memStat@sda21(r13)
/* 80054D5C 00051CBC  38 8D 8C 44 */	addi r4, r13, lbl_803DD964@sda21
/* 80054D60 00051CC0  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80054D64 00051CC4  48 03 19 D5 */	bl start__7MemStatFPc
/* 80054D68 00051CC8  3C 60 80 3A */	lis r3, gameflow@ha
/* 80054D6C 00051CCC  38 A3 D7 B8 */	addi r5, r3, gameflow@l
/* 80054D70 00051CD0  38 C0 00 01 */	li r6, 1
/* 80054D74 00051CD4  98 C5 01 C4 */	stb r6, 0x1c4(r5)
/* 80054D78 00051CD8  38 00 FF FF */	li r0, -1
/* 80054D7C 00051CDC  3C 60 80 3A */	lis r3, flowCont@ha
/* 80054D80 00051CE0  90 05 01 C0 */	stw r0, 0x1c0(r5)
/* 80054D84 00051CE4  3A 83 DB 20 */	addi r20, r3, flowCont@l
/* 80054D88 00051CE8  3A 60 00 00 */	li r19, 0
/* 80054D8C 00051CEC  90 05 01 BC */	stw r0, 0x1bc(r5)
/* 80054D90 00051CF0  3A E5 01 C4 */	addi r23, r5, 0x1c4
/* 80054D94 00051CF4  3B 05 01 C0 */	addi r24, r5, 0x1c0
/* 80054D98 00051CF8  90 05 01 B8 */	stw r0, 0x1b8(r5)
/* 80054D9C 00051CFC  3B 25 01 BC */	addi r25, r5, 0x1bc
/* 80054DA0 00051D00  3B A5 01 B8 */	addi r29, r5, 0x1b8
/* 80054DA4 00051D04  98 C5 01 C5 */	stb r6, 0x1c5(r5)
/* 80054DA8 00051D08  3B 85 01 C5 */	addi r28, r5, 0x1c5
/* 80054DAC 00051D0C  3B 65 01 C6 */	addi r27, r5, 0x1c6
/* 80054DB0 00051D10  9A 65 01 C6 */	stb r19, 0x1c6(r5)
/* 80054DB4 00051D14  3B 45 01 C8 */	addi r26, r5, 0x1c8
/* 80054DB8 00051D18  38 74 00 00 */	addi r3, r20, 0
/* 80054DBC 00051D1C  90 C5 01 C8 */	stw r6, 0x1c8(r5)
/* 80054DC0 00051D20  38 95 0A 78 */	addi r4, r21, 0xa78
/* 80054DC4 00051D24  90 C5 02 FC */	stw r6, 0x2fc(r5)
/* 80054DC8 00051D28  92 74 02 48 */	stw r19, 0x248(r20)
/* 80054DCC 00051D2C  92 74 02 54 */	stw r19, 0x254(r20)
/* 80054DD0 00051D30  92 74 02 58 */	stw r19, 0x258(r20)
/* 80054DD4 00051D34  92 74 02 4C */	stw r19, 0x24c(r20)
/* 80054DD8 00051D38  92 74 02 50 */	stw r19, 0x250(r20)
/* 80054DDC 00051D3C  4B FF E4 ED */	bl readMapList__14FlowControllerFPc
/* 80054DE0 00051D40  92 74 02 44 */	stw r19, 0x244(r20)
/* 80054DE4 00051D44  7F E3 FB 78 */	mr r3, r31
/* 80054DE8 00051D48  4B FF FD 4D */	bl preCacheShapes__16GameSetupSectionFv
/* 80054DEC 00051D4C  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80054DF0 00051D50  38 95 0A 8C */	addi r4, r21, 0xa8c
/* 80054DF4 00051D54  48 03 19 45 */	bl start__7MemStatFPc
/* 80054DF8 00051D58  38 60 00 84 */	li r3, 0x84
/* 80054DFC 00051D5C  4B FF 22 09 */	bl alloc__6SystemFUl
/* 80054E00 00051D60  3A 63 00 00 */	addi r19, r3, 0
/* 80054E04 00051D64  7E 63 9B 79 */	or. r3, r19, r19
/* 80054E08 00051D68  41 82 00 08 */	beq .L_80054E10
/* 80054E0C 00051D6C  48 08 9F 5D */	bl __ct__14GeneratorCacheFv
.L_80054E10:
/* 80054E10 00051D70  92 6D 30 98 */	stw r19, generatorCache@sda21(r13)
/* 80054E14 00051D74  80 6D 30 98 */	lwz r3, generatorCache@sda21(r13)
/* 80054E18 00051D78  48 08 A0 99 */	bl initGame__14GeneratorCacheFv
/* 80054E1C 00051D7C  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80054E20 00051D80  38 95 0A 8C */	addi r4, r21, 0xa8c
/* 80054E24 00051D84  48 03 1A 25 */	bl end__7MemStatFPc
/* 80054E28 00051D88  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80054E2C 00051D8C  38 95 0A 98 */	addi r4, r21, 0xa98
/* 80054E30 00051D90  48 03 19 09 */	bl start__7MemStatFPc
/* 80054E34 00051D94  38 60 01 CC */	li r3, 0x1cc
/* 80054E38 00051D98  4B FF 21 CD */	bl alloc__6SystemFUl
/* 80054E3C 00051D9C  3A 63 00 00 */	addi r19, r3, 0
/* 80054E40 00051DA0  7E 63 9B 79 */	or. r3, r19, r19
/* 80054E44 00051DA4  41 82 00 08 */	beq .L_80054E4C
/* 80054E48 00051DA8  48 02 A9 31 */	bl __ct__11PlayerStateFv
.L_80054E4C:
/* 80054E4C 00051DAC  92 6D 2F 6C */	stw r19, playerState@sda21(r13)
/* 80054E50 00051DB0  80 6D 2F 6C */	lwz r3, playerState@sda21(r13)
/* 80054E54 00051DB4  48 02 A7 59 */	bl initGame__11PlayerStateFv
/* 80054E58 00051DB8  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80054E5C 00051DBC  38 95 0A 98 */	addi r4, r21, 0xa98
/* 80054E60 00051DC0  48 03 19 E9 */	bl end__7MemStatFPc
/* 80054E64 00051DC4  38 60 00 14 */	li r3, 0x14
/* 80054E68 00051DC8  4B FF 21 9D */	bl alloc__6SystemFUl
/* 80054E6C 00051DCC  3A 63 00 00 */	addi r19, r3, 0
/* 80054E70 00051DD0  7E 63 9B 79 */	or. r3, r19, r19
/* 80054E74 00051DD4  41 82 00 08 */	beq .L_80054E7C
/* 80054E78 00051DD8  48 02 F4 FD */	bl __ct__3KIOFv
.L_80054E7C:
/* 80054E7C 00051DDC  92 6D 2F 88 */	stw r19, kio@sda21(r13)
/* 80054E80 00051DE0  80 6D 2F 88 */	lwz r3, kio@sda21(r13)
/* 80054E84 00051DE4  48 02 F5 4D */	bl initialise__3KIOFv
/* 80054E88 00051DE8  38 60 0B B8 */	li r3, 0xbb8
/* 80054E8C 00051DEC  48 0C 0F D5 */	bl getSaveSize__10KontrollerFi
/* 80054E90 00051DF0  3A 83 00 00 */	addi r20, r3, 0
/* 80054E94 00051DF4  38 80 00 20 */	li r4, 0x20
/* 80054E98 00051DF8  4B FF 22 D1 */	bl __nwa__FUli
/* 80054E9C 00051DFC  3A A3 00 00 */	addi r21, r3, 0
/* 80054EA0 00051E00  38 60 00 14 */	li r3, 0x14
/* 80054EA4 00051E04  4B FF 21 61 */	bl alloc__6SystemFUl
/* 80054EA8 00051E08  28 03 00 00 */	cmplwi r3, 0
/* 80054EAC 00051E0C  41 82 00 38 */	beq .L_80054EE4
/* 80054EB0 00051E10  3C 80 80 22 */	lis r4, __vt__6Stream@ha
/* 80054EB4 00051E14  38 04 73 98 */	addi r0, r4, __vt__6Stream@l
/* 80054EB8 00051E18  3C 80 80 22 */	lis r4, __vt__18RandomAccessStream@ha
/* 80054EBC 00051E1C  90 03 00 04 */	stw r0, 4(r3)
/* 80054EC0 00051E20  38 04 74 C8 */	addi r0, r4, __vt__18RandomAccessStream@l
/* 80054EC4 00051E24  3C 80 80 2A */	lis r4, __vt__9RamStream@ha
/* 80054EC8 00051E28  90 03 00 04 */	stw r0, 4(r3)
/* 80054ECC 00051E2C  38 04 75 5C */	addi r0, r4, __vt__9RamStream@l
/* 80054ED0 00051E30  90 03 00 04 */	stw r0, 4(r3)
/* 80054ED4 00051E34  38 00 00 00 */	li r0, 0
/* 80054ED8 00051E38  92 A3 00 08 */	stw r21, 8(r3)
/* 80054EDC 00051E3C  90 03 00 0C */	stw r0, 0xc(r3)
/* 80054EE0 00051E40  92 83 00 10 */	stw r20, 0x10(r3)
.L_80054EE4:
/* 80054EE4 00051E44  90 6D 31 18 */	stw r3, controllerBuffer@sda21(r13)
/* 80054EE8 00051E48  48 02 A3 ED */	bl init__11GlobalShapeFv
/* 80054EEC 00051E4C  80 6D 2F E8 */	lwz r3, memStat@sda21(r13)
/* 80054EF0 00051E50  38 8D 8C 44 */	addi r4, r13, lbl_803DD964@sda21
/* 80054EF4 00051E54  48 03 19 55 */	bl end__7MemStatFPc
/* 80054EF8 00051E58  3C 60 80 3D */	lis r3, pikiInfMgr@ha
/* 80054EFC 00051E5C  92 DE 00 00 */	stw r22, 0(r30)
/* 80054F00 00051E60  38 63 1D F0 */	addi r3, r3, pikiInfMgr@l
/* 80054F04 00051E64  48 07 09 65 */	bl clear__10PikiInfMgrFv
/* 80054F08 00051E68  38 A0 00 01 */	li r5, 1
/* 80054F0C 00051E6C  98 B7 00 00 */	stb r5, 0(r23)
/* 80054F10 00051E70  38 80 FF FF */	li r4, -1
/* 80054F14 00051E74  38 00 00 00 */	li r0, 0
/* 80054F18 00051E78  90 98 00 00 */	stw r4, 0(r24)
/* 80054F1C 00051E7C  7F E3 FB 78 */	mr r3, r31
/* 80054F20 00051E80  90 99 00 00 */	stw r4, 0(r25)
/* 80054F24 00051E84  90 9D 00 00 */	stw r4, 0(r29)
/* 80054F28 00051E88  98 BC 00 00 */	stb r5, 0(r28)
/* 80054F2C 00051E8C  98 1B 00 00 */	stb r0, 0(r27)
/* 80054F30 00051E90  90 BA 00 00 */	stw r5, 0(r26)
/* 80054F34 00051E94  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 80054F38 00051E98  BA 61 00 24 */	lmw r19, 0x24(r1)
/* 80054F3C 00051E9C  38 21 00 58 */	addi r1, r1, 0x58
/* 80054F40 00051EA0  7C 08 03 A6 */	mtlr r0
/* 80054F44 00051EA4  4E 80 00 20 */	blr 

.global update__16GameSetupSectionFv
update__16GameSetupSectionFv:
/* 80054F48 00051EA8  3C 60 80 3A */	lis r3, gameflow@ha
/* 80054F4C 00051EAC  38 63 D7 B8 */	addi r3, r3, gameflow@l
/* 80054F50 00051EB0  38 00 00 01 */	li r0, 1
/* 80054F54 00051EB4  90 03 01 F4 */	stw r0, 0x1f4(r3)
/* 80054F58 00051EB8  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80054F5C 00051EBC  98 03 00 00 */	stb r0, 0(r3)
/* 80054F60 00051EC0  4E 80 00 20 */	blr 

.global init__16GameSetupSectionFv
init__16GameSetupSectionFv:
/* 80054F64 00051EC4  4E 80 00 20 */	blr 

.global getPending__9RamStreamFv
getPending__9RamStreamFv:
/* 80054F68 00051EC8  80 83 00 0C */	lwz r4, 0xc(r3)
/* 80054F6C 00051ECC  80 03 00 10 */	lwz r0, 0x10(r3)
/* 80054F70 00051ED0  7C 64 00 50 */	subf r3, r4, r0
/* 80054F74 00051ED4  4E 80 00 20 */	blr 

.global setPosition__9RamStreamFi
setPosition__9RamStreamFi: # weak funcs
/* 80054F78 00051ED8  90 83 00 0C */	stw r4, 0xc(r3)
/* 80054F7C 00051EDC  4E 80 00 20 */	blr 

.global getPosition__9RamStreamFv
getPosition__9RamStreamFv:
/* 80054F80 00051EE0  80 63 00 0C */	lwz r3, 0xc(r3)
/* 80054F84 00051EE4  4E 80 00 20 */	blr 

.global getLength__9RamStreamFv
getLength__9RamStreamFv:
/* 80054F88 00051EE8  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80054F8C 00051EEC  4E 80 00 20 */	blr 

.global setLength__9RamStreamFi
setLength__9RamStreamFi:
/* 80054F90 00051EF0  90 83 00 10 */	stw r4, 0x10(r3)
/* 80054F94 00051EF4  4E 80 00 20 */	blr 

.global read__9RamStreamFPvi
read__9RamStreamFPvi:
/* 80054F98 00051EF8  7C 08 02 A6 */	mflr r0
/* 80054F9C 00051EFC  90 01 00 04 */	stw r0, 4(r1)
/* 80054FA0 00051F00  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80054FA4 00051F04  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80054FA8 00051F08  3B E5 00 00 */	addi r31, r5, 0
/* 80054FAC 00051F0C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80054FB0 00051F10  7C 7E 1B 78 */	mr r30, r3
/* 80054FB4 00051F14  80 C3 00 08 */	lwz r6, 8(r3)
/* 80054FB8 00051F18  80 03 00 0C */	lwz r0, 0xc(r3)
/* 80054FBC 00051F1C  38 64 00 00 */	addi r3, r4, 0
/* 80054FC0 00051F20  7C 86 02 14 */	add r4, r6, r0
/* 80054FC4 00051F24  4B FA E4 51 */	bl memcpy
/* 80054FC8 00051F28  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 80054FCC 00051F2C  7C 00 FA 14 */	add r0, r0, r31
/* 80054FD0 00051F30  90 1E 00 0C */	stw r0, 0xc(r30)
/* 80054FD4 00051F34  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80054FD8 00051F38  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80054FDC 00051F3C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80054FE0 00051F40  38 21 00 20 */	addi r1, r1, 0x20
/* 80054FE4 00051F44  7C 08 03 A6 */	mtlr r0
/* 80054FE8 00051F48  4E 80 00 20 */	blr 

.global write__9RamStreamFPvi
write__9RamStreamFPvi:
/* 80054FEC 00051F4C  7C 08 02 A6 */	mflr r0
/* 80054FF0 00051F50  90 01 00 04 */	stw r0, 4(r1)
/* 80054FF4 00051F54  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80054FF8 00051F58  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80054FFC 00051F5C  3B E5 00 00 */	addi r31, r5, 0
/* 80055000 00051F60  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80055004 00051F64  7C 7E 1B 78 */	mr r30, r3
/* 80055008 00051F68  80 63 00 08 */	lwz r3, 8(r3)
/* 8005500C 00051F6C  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 80055010 00051F70  7C 63 02 14 */	add r3, r3, r0
/* 80055014 00051F74  4B FA E4 01 */	bl memcpy
/* 80055018 00051F78  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 8005501C 00051F7C  7C 00 FA 14 */	add r0, r0, r31
/* 80055020 00051F80  90 1E 00 0C */	stw r0, 0xc(r30)
/* 80055024 00051F84  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80055028 00051F88  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8005502C 00051F8C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80055030 00051F90  38 21 00 20 */	addi r1, r1, 0x20
/* 80055034 00051F94  7C 08 03 A6 */	mtlr r0
/* 80055038 00051F98  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802A69A8:
	.asciz "gameSetup.cpp"
.balign 4
lbl_802A69B8:
	.asciz "GameSetup"
.balign 4
lbl_802A69C4:
	.asciz "objects/pellets/white1.mod"
.balign 4
lbl_802A69E0:
	.asciz "objects/pellets/white1.anm"
.balign 4
lbl_802A69FC:
	.asciz "objects/pellets/white2.mod"
.balign 4
lbl_802A6A18:
	.asciz "objects/pellets/white2.anm"
.balign 4
lbl_802A6A34:
	.asciz "objects/pellets/white3.mod"
.balign 4
lbl_802A6A50:
	.asciz "objects/pellets/white3.anm"
.balign 4
lbl_802A6A6C:
	.asciz "objects/pellets/white4.mod"
.balign 4
lbl_802A6A88:
	.asciz "objects/pellets/white4.anm"
.balign 4
lbl_802A6AA4:
	.asciz "pikis/bluModel.mod"
.balign 4
lbl_802A6AB8:
	.asciz "pikis/bluModel.anm"
.balign 4
lbl_802A6ACC:
	.asciz "pikis/redModel.mod"
.balign 4
lbl_802A6AE0:
	.asciz "pikis/yelModel.mod"
.balign 4
lbl_802A6AF4:
	.asciz "pikis/kinModel.mod"
.balign 4
lbl_802A6B08:
	.asciz "pikis/nv3Model.mod"
.balign 4
shapeList:
	.4byte lbl_802A69C4
	.4byte lbl_802A69E0
	.4byte lbl_802A69FC
	.4byte lbl_802A6A18
	.4byte lbl_802A6A34
	.4byte lbl_802A6A50
	.4byte lbl_802A6A6C
	.4byte lbl_802A6A88
	.4byte lbl_802A6AA4
	.4byte lbl_802A6AB8
	.4byte lbl_802A6ACC
	.4byte 0
	.4byte lbl_802A6AE0
	.4byte 0
	.4byte lbl_802A6AF4
	.4byte 0
	.4byte lbl_802A6B08
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
lbl_802A6B6C:
	.asciz "objects/ufo/ufo0705.mod"
.balign 4
lbl_802A6B84:
	.asciz "objects/ufo/ufo0705.anm"
.balign 4
lbl_802A6B9C:
	.asciz "objects/ufoparts/soto1.mod"
.balign 4
lbl_802A6BB8:
	.asciz "objects/ufoparts/soto1.anm"
.balign 4
lbl_802A6BD4:
	.asciz "objects/ufoparts/soto2.mod"
.balign 4
lbl_802A6BF0:
	.asciz "objects/ufoparts/soto2.anm"
.balign 4
lbl_802A6C0C:
	.asciz "objects/ufoparts/soto3.mod"
.balign 4
lbl_802A6C28:
	.asciz "objects/ufoparts/soto3.anm"
.balign 4
lbl_802A6C44:
	.asciz "objects/ufoparts/soto4.mod"
.balign 4
lbl_802A6C60:
	.asciz "objects/ufoparts/soto4.anm"
.balign 4
lbl_802A6C7C:
	.asciz "objects/ufoparts/soto5.mod"
.balign 4
lbl_802A6C98:
	.asciz "objects/ufoparts/soto5.anm"
.balign 4
lbl_802A6CB4:
	.asciz "objects/ufoparts/fuzoku1.mod"
.balign 4
lbl_802A6CD4:
	.asciz "objects/ufoparts/fuzoku1.anm"
.balign 4
lbl_802A6CF4:
	.asciz "objects/ufoparts/fuzoku2.mod"
.balign 4
lbl_802A6D14:
	.asciz "objects/ufoparts/fuzoku2.anm"
.balign 4
lbl_802A6D34:
	.asciz "objects/ufoparts/fuzoku3.mod"
.balign 4
lbl_802A6D54:
	.asciz "objects/ufoparts/fuzoku3.anm"
.balign 4
lbl_802A6D74:
	.asciz "objects/ufoparts/fuzoku4.mod"
.balign 4
lbl_802A6D94:
	.asciz "objects/ufoparts/fuzoku4.anm"
.balign 4
lbl_802A6DB4:
	.asciz "objects/ufoparts/fuzoku5.mod"
.balign 4
lbl_802A6DD4:
	.asciz "objects/ufoparts/fuzoku5.anm"
.balign 4
lbl_802A6DF4:
	.asciz "objects/ufoparts/fuzoku6.mod"
.balign 4
lbl_802A6E14:
	.asciz "objects/ufoparts/fuzoku6.anm"
.balign 4
lbl_802A6E34:
	.asciz "objects/ufoparts/fuzoku7.mod"
.balign 4
lbl_802A6E54:
	.asciz "objects/ufoparts/fuzoku7.anm"
.balign 4
lbl_802A6E74:
	.asciz "objects/ufoparts/fuzoku8.mod"
.balign 4
lbl_802A6E94:
	.asciz "objects/ufoparts/fuzoku8.anm"
.balign 4
lbl_802A6EB4:
	.asciz "objects/ufoparts/fuzoku9.mod"
.balign 4
lbl_802A6ED4:
	.asciz "objects/ufoparts/fuzoku9.anm"
.balign 4
lbl_802A6EF4:
	.asciz "objects/ufoparts/fuzoku10.mod"
.balign 4
lbl_802A6F14:
	.asciz "objects/ufoparts/fuzoku10.anm"
.balign 4
lbl_802A6F34:
	.asciz "objects/ufoparts/fuzoku11.mod"
.balign 4
lbl_802A6F54:
	.asciz "objects/ufoparts/fuzoku11.anm"
.balign 4
shapeList2:
	.4byte lbl_802A6B6C
	.4byte lbl_802A6B84
	.4byte lbl_802A6B9C
	.4byte lbl_802A6BB8
	.4byte lbl_802A6BD4
	.4byte lbl_802A6BF0
	.4byte lbl_802A6C0C
	.4byte lbl_802A6C28
	.4byte lbl_802A6C44
	.4byte lbl_802A6C60
	.4byte lbl_802A6C7C
	.4byte lbl_802A6C98
	.4byte lbl_802A6CB4
	.4byte lbl_802A6CD4
	.4byte lbl_802A6CF4
	.4byte lbl_802A6D14
	.4byte lbl_802A6D34
	.4byte lbl_802A6D54
	.4byte lbl_802A6D74
	.4byte lbl_802A6D94
	.4byte lbl_802A6DB4
	.4byte lbl_802A6DD4
	.4byte lbl_802A6DF4
	.4byte lbl_802A6E14
	.4byte lbl_802A6E34
	.4byte lbl_802A6E54
	.4byte lbl_802A6E74
	.4byte lbl_802A6E94
	.4byte lbl_802A6EB4
	.4byte lbl_802A6ED4
	.4byte lbl_802A6EF4
	.4byte lbl_802A6F14
	.4byte lbl_802A6F34
	.4byte lbl_802A6F54
	.4byte 0
	.4byte 0
.balign 4
lbl_802A7004:
	.asciz "archives/tekis.dir"
.balign 4
lbl_802A7018:
	.asciz "dataDir/archives/tekis.arc"
.balign 4
lbl_802A7034:
	.asciz "archives/bosses.dir"
.balign 4
lbl_802A7048:
	.asciz "dataDir/archives/bosses.arc"
.balign 4
lbl_802A7064:
	.asciz "archives/tekipara.dir"
.balign 4
lbl_802A707C:
	.asciz "dataDir/archives/tekipara.arc"
.balign 4
lbl_802A709C:
	.asciz "archives/tekikey.dir"
.balign 4
lbl_802A70B4:
	.asciz "dataDir/archives/tekikey.arc"
.balign 4
lbl_802A70D4:
	.asciz "archives/plants.dir"
.balign 4
lbl_802A70E8:
	.asciz "dataDir/archives/plants.arc"
.balign 4
lbl_802A7104:
	.asciz "archives/ufopartsbin.dir"
.balign 4
lbl_802A7120:
	.asciz "dataDir/archives/ufopartsbin.arc"
.balign 4
lbl_802A7144:
	.asciz "archives/bridges.dir"
.balign 4
lbl_802A715C:
	.asciz "dataDir/archives/bridges.arc"
.balign 4
lbl_802A717C:
	.asciz "archives/gates.dir"
.balign 4
lbl_802A7190:
	.asciz "dataDir/archives/gates.arc"
.balign 4
lbl_802A71AC:
	.asciz "archives/bomb.dir"
.balign 4
lbl_802A71C0:
	.asciz "dataDir/archives/bomb.arc"
.balign 4
lbl_802A71DC:
	.asciz "archives/rope.dir"
.balign 4
lbl_802A71F0:
	.asciz "dataDir/archives/rope.arc"
.balign 4
lbl_802A720C:
	.asciz "archives/water.dir"
.balign 4
lbl_802A7220:
	.asciz "dataDir/archives/water.arc"
.balign 4
lbl_802A723C:
	.asciz "archives/fl_water.dir"
.balign 4
lbl_802A7254:
	.asciz "dataDir/archives/fl_water.arc"
.balign 4
lbl_802A7274:
	.asciz "archives/pelletsbin.dir"
.balign 4
lbl_802A728C:
	.asciz "dataDir/archives/pelletsbin.arc"
.balign 4
lbl_802A72AC:
	.asciz "archives/pikihead.dir"
.balign 4
lbl_802A72C4:
	.asciz "dataDir/archives/pikihead.arc"
.balign 4
lbl_802A72E4:
	.asciz "archives/effshapes.dir"
.balign 4
lbl_802A72FC:
	.asciz "dataDir/archives/effshapes.arc"
.balign 4
lbl_802A731C:
	.asciz "archives/weeds.dir"
.balign 4
lbl_802A7330:
	.asciz "dataDir/archives/weeds.arc"
.balign 4
lbl_802A734C:
	.asciz "archives/goal.dir"
.balign 4
lbl_802A7360:
	.asciz "dataDir/archives/goal.arc"
.balign 4
arambundleList:
	.4byte lbl_802A7004
	.4byte lbl_802A7018
	.4byte lbl_802A7034
	.4byte lbl_802A7048
	.4byte lbl_802A7064
	.4byte lbl_802A707C
	.4byte lbl_802A709C
	.4byte lbl_802A70B4
	.4byte lbl_802A70D4
	.4byte lbl_802A70E8
	.4byte lbl_802A7104
	.4byte lbl_802A7120
	.4byte lbl_802A7144
	.4byte lbl_802A715C
	.4byte lbl_802A717C
	.4byte lbl_802A7190
	.4byte lbl_802A71AC
	.4byte lbl_802A71C0
	.4byte lbl_802A71DC
	.4byte lbl_802A71F0
	.4byte lbl_802A720C
	.4byte lbl_802A7220
	.4byte lbl_802A723C
	.4byte lbl_802A7254
	.4byte lbl_802A7274
	.4byte lbl_802A728C
	.4byte lbl_802A72AC
	.4byte lbl_802A72C4
	.4byte lbl_802A72E4
	.4byte lbl_802A72FC
	.4byte lbl_802A731C
	.4byte lbl_802A7330
	.4byte lbl_802A734C
	.4byte lbl_802A7360
	.4byte 0
	.4byte 0
.balign 4
lbl_802A740C:
	.asciz "<GameSetupSection>"
.balign 4
lbl_802A7420:
	.asciz "stages/stages.ini"
.balign 4
lbl_802A7434:
	.asciz "genCache"
.balign 4
lbl_802A7440:
	.asciz "playerInfo"
.balign 4
lbl_802A744C:
	.asciz "GameSetupSection"
.balign 4
lbl_802A7460:
	.asciz "CoreNode"
.balign 4
lbl_802A746C:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
lbl_802A7478:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
lbl_802A748C:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
lbl_802A74A8:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__7Section
	.4byte 0
	.4byte 0
.global __vt__16GameSetupSection
__vt__16GameSetupSection:
	.4byte __RTTI__16GameSetupSection
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__16GameSetupSectionFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte init__16GameSetupSectionFv
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
lbl_802A751C:
	.asciz "RamStream"
.balign 4
lbl_802A7528:
	.asciz "RandomAccessStream"
.balign 4
lbl_802A753C:
	.4byte __RTTI__6Stream
	.4byte 0
	.4byte 0
lbl_802A7548:
	.4byte __RTTI__6Stream
	.4byte 0
	.4byte __RTTI__18RandomAccessStream
	.4byte 0
	.4byte 0
.global __vt__9RamStream
__vt__9RamStream:
	.4byte __RTTI__9RamStream
	.4byte 0
	.4byte readInt__6StreamFv
	.4byte readByte__6StreamFv
	.4byte readShort__6StreamFv
	.4byte readFloat__6StreamFv
	.4byte readString__6StreamFPci
	.4byte readString__6StreamFR6String
	.4byte readString__6StreamFv
	.4byte writeInt__6StreamFi
	.4byte writeByte__6StreamFUc
	.4byte writeShort__6StreamFs
	.4byte writeFloat__6StreamFf
	.4byte writeString__6StreamFPc
	.4byte writeString__6StreamFR6String
	.4byte read__9RamStreamFPvi
	.4byte write__9RamStreamFPvi
	.4byte getPending__9RamStreamFv
	.4byte getAvailable__6StreamFv
	.4byte close__6StreamFv
	.4byte getClosing__6StreamFv
	.4byte flush__6StreamFv
	.4byte getPosition__9RamStreamFv
	.4byte setPosition__9RamStreamFi
	.4byte getLength__9RamStreamFv
	.4byte setLength__9RamStreamFi
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
lbl_803DD958:
	.asciz ""
.balign 4
lbl_803DD95C:
	.asciz "<Node>"
.balign 4
lbl_803DD964:
	.asciz "setup"
.balign 4
lbl_803DD96C:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803DD96C
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802A7460
	.4byte lbl_802A746C
.balign 4
lbl_803DD984:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803DD984
	.4byte lbl_802A7478
.balign 4
lbl_803DD994:
	.asciz "Section"
.balign 4
__RTTI__7Section:
	.4byte lbl_803DD994
	.4byte lbl_802A748C
__RTTI__16GameSetupSection:
	.4byte lbl_802A744C
	.4byte lbl_802A74A8
.balign 4
lbl_803DD9AC:
	.asciz "Stream"
.balign 4
__RTTI__6Stream:
	.4byte lbl_803DD9AC
	.4byte 0
__RTTI__18RandomAccessStream:
	.4byte lbl_802A7528
	.4byte lbl_802A753C
__RTTI__9RamStream:
	.4byte lbl_802A751C
	.4byte lbl_802A7548
