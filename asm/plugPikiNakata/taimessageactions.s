.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global start__20TaiSendMessageActionFR4Teki
start__20TaiSendMessageActionFR4Teki:
/* 80131EF8 0012EE58  7C 08 02 A6 */	mflr r0
/* 80131EFC 0012EE5C  90 01 00 04 */	stw r0, 4(r1)
/* 80131F00 0012EE60  7C 80 23 78 */	mr r0, r4
/* 80131F04 0012EE64  94 21 FF F8 */	stwu r1, -8(r1)
/* 80131F08 0012EE68  80 83 00 08 */	lwz r4, 8(r3)
/* 80131F0C 0012EE6C  7C 03 03 78 */	mr r3, r0
/* 80131F10 0012EE70  48 01 9B FD */	bl sendMessage__5NTekiFi
/* 80131F14 0012EE74  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80131F18 0012EE78  38 21 00 08 */	addi r1, r1, 8
/* 80131F1C 0012EE7C  7C 08 03 A6 */	mtlr r0
/* 80131F20 0012EE80  4E 80 00 20 */	blr 

.global act__23TaiKeySendMessageActionFR4Teki
act__23TaiKeySendMessageActionFR4Teki:
/* 80131F24 0012EE84  7C 08 02 A6 */	mflr r0
/* 80131F28 0012EE88  7C 65 1B 78 */	mr r5, r3
/* 80131F2C 0012EE8C  90 01 00 04 */	stw r0, 4(r1)
/* 80131F30 0012EE90  94 21 FF F8 */	stwu r1, -8(r1)
/* 80131F34 0012EE94  80 03 00 0C */	lwz r0, 0xc(r3)
/* 80131F38 0012EE98  80 64 04 14 */	lwz r3, 0x414(r4)
/* 80131F3C 0012EE9C  7C 60 00 39 */	and. r0, r3, r0
/* 80131F40 0012EEA0  41 82 00 10 */	beq lbl_80131F50
/* 80131F44 0012EEA4  7C 83 23 78 */	mr r3, r4
/* 80131F48 0012EEA8  80 85 00 08 */	lwz r4, 8(r5)
/* 80131F4C 0012EEAC  48 01 9B C1 */	bl sendMessage__5NTekiFi
lbl_80131F50:
/* 80131F50 0012EEB0  38 60 00 00 */	li r3, 0
/* 80131F54 0012EEB4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80131F58 0012EEB8  38 21 00 08 */	addi r1, r1, 8
/* 80131F5C 0012EEBC  7C 08 03 A6 */	mtlr r0
/* 80131F60 0012EEC0  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C8BA0:
	.asciz "taimessageactions.cpp"
.balign 4
lbl_802C8BB8:
	.asciz "taimessageactions"
.balign 4
lbl_802C8BCC:
	.asciz "TaiKeySendMessageAction"
.balign 4
lbl_802C8BE4:
	.asciz "TaiAction"
.balign 4
lbl_802C8BF0:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__23TaiKeySendMessageAction
__vt__23TaiKeySendMessageAction:
	.4byte __RTTI__23TaiKeySendMessageAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__23TaiKeySendMessageActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802C8C18:
	.asciz "TaiSendMessageAction"
.balign 4
lbl_802C8C30:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__20TaiSendMessageAction
__vt__20TaiSendMessageAction:
	.4byte __RTTI__20TaiSendMessageAction
	.4byte 0
	.4byte start__20TaiSendMessageActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__9TaiAction:
	.4byte lbl_802C8BE4
	.4byte 0
__RTTI__23TaiKeySendMessageAction:
	.4byte lbl_802C8BCC
	.4byte lbl_802C8BF0
__RTTI__20TaiSendMessageAction:
	.4byte lbl_802C8C18
	.4byte lbl_802C8C30
