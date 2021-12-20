.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global satisfy__12CndIsVisibleFP8Creature
satisfy__12CndIsVisibleFP8Creature:
/* 800DAC28 000D7B88  7C 08 02 A6 */	mflr r0
/* 800DAC2C 000D7B8C  7C 83 23 78 */	mr r3, r4
/* 800DAC30 000D7B90  90 01 00 04 */	stw r0, 4(r1)
/* 800DAC34 000D7B94  94 21 FF F8 */	stwu r1, -8(r1)
/* 800DAC38 000D7B98  81 84 00 00 */	lwz r12, 0(r4)
/* 800DAC3C 000D7B9C  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800DAC40 000D7BA0  7D 88 03 A6 */	mtlr r12
/* 800DAC44 000D7BA4  4E 80 00 21 */	blrl 
/* 800DAC48 000D7BA8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800DAC4C 000D7BAC  38 21 00 08 */	addi r1, r1, 8
/* 800DAC50 000D7BB0  7C 08 03 A6 */	mtlr r0
/* 800DAC54 000D7BB4  4E 80 00 20 */	blr 

.global satisfy__10CndIsAtariFP8Creature
satisfy__10CndIsAtariFP8Creature:
/* 800DAC58 000D7BB8  7C 08 02 A6 */	mflr r0
/* 800DAC5C 000D7BBC  7C 83 23 78 */	mr r3, r4
/* 800DAC60 000D7BC0  90 01 00 04 */	stw r0, 4(r1)
/* 800DAC64 000D7BC4  94 21 FF F8 */	stwu r1, -8(r1)
/* 800DAC68 000D7BC8  81 84 00 00 */	lwz r12, 0(r4)
/* 800DAC6C 000D7BCC  81 8C 00 84 */	lwz r12, 0x84(r12)
/* 800DAC70 000D7BD0  7D 88 03 A6 */	mtlr r12
/* 800DAC74 000D7BD4  4E 80 00 21 */	blrl 
/* 800DAC78 000D7BD8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 800DAC7C 000D7BDC  38 21 00 08 */	addi r1, r1, 8
/* 800DAC80 000D7BE0  7C 08 03 A6 */	mtlr r0
/* 800DAC84 000D7BE4  4E 80 00 20 */	blr 

.global satisfy__13CndStickMouthFP8Creature
satisfy__13CndStickMouthFP8Creature:
/* 800DAC88 000D7BE8  80 04 00 C8 */	lwz r0, 0xc8(r4)
/* 800DAC8C 000D7BEC  54 00 04 21 */	rlwinm. r0, r0, 0, 0x10, 0x10
/* 800DAC90 000D7BF0  41 82 00 1C */	beq lbl_800DACAC
/* 800DAC94 000D7BF4  80 84 01 84 */	lwz r4, 0x184(r4)
/* 800DAC98 000D7BF8  80 03 00 04 */	lwz r0, 4(r3)
/* 800DAC9C 000D7BFC  7C 04 00 40 */	cmplw r4, r0
/* 800DACA0 000D7C00  40 82 00 0C */	bne lbl_800DACAC
/* 800DACA4 000D7C04  38 60 00 01 */	li r3, 1
/* 800DACA8 000D7C08  4E 80 00 20 */	blr 
lbl_800DACAC:
/* 800DACAC 000D7C0C  38 60 00 00 */	li r3, 0
/* 800DACB0 000D7C10  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BA5A0:
	.asciz "CndStickMouth"
.balign 4
lbl_802BA5B0:
	.asciz "Condition"
.balign 4
lbl_802BA5BC:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.global __vt__13CndStickMouth
__vt__13CndStickMouth:
	.4byte __RTTI__13CndStickMouth
	.4byte 0
	.4byte satisfy__13CndStickMouthFP8Creature
.balign 4
lbl_802BA5D4:
	.asciz "CndIsAtari"
.balign 4
lbl_802BA5E0:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.global __vt__10CndIsAtari
__vt__10CndIsAtari:
	.4byte __RTTI__10CndIsAtari
	.4byte 0
	.4byte satisfy__10CndIsAtariFP8Creature
.balign 4
lbl_802BA5F8:
	.asciz "CndIsVisible"
.balign 4
lbl_802BA608:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.global __vt__12CndIsVisible
__vt__12CndIsVisible:
	.4byte __RTTI__12CndIsVisible
	.4byte 0
	.4byte satisfy__12CndIsVisibleFP8Creature

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__9Condition:
	.4byte lbl_802BA5B0
	.4byte 0
__RTTI__13CndStickMouth:
	.4byte lbl_802BA5A0
	.4byte lbl_802BA5BC
__RTTI__10CndIsAtari:
	.4byte lbl_802BA5D4
	.4byte lbl_802BA5E0
__RTTI__12CndIsVisible:
	.4byte lbl_802BA5F8
	.4byte lbl_802BA608
