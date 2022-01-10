.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global actPiki__12InteractTalkFP4Piki
actPiki__12InteractTalkFP4Piki:
/* 8007C9F8 00079958  7C 08 02 A6 */	mflr r0
/* 8007C9FC 0007995C  90 01 00 04 */	stw r0, 4(r1)
/* 8007CA00 00079960  38 00 00 02 */	li r0, 2
/* 8007CA04 00079964  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8007CA08 00079968  80 63 00 04 */	lwz r3, 4(r3)
/* 8007CA0C 0007996C  90 01 00 10 */	stw r0, 0x10(r1)
/* 8007CA10 00079970  90 61 00 14 */	stw r3, 0x14(r1)
/* 8007CA14 00079974  80 64 04 F8 */	lwz r3, 0x4f8(r4)
/* 8007CA18 00079978  38 81 00 10 */	addi r4, r1, 0x10
/* 8007CA1C 0007997C  48 04 70 C9 */	bl procMsg__6ActionFP3Msg
/* 8007CA20 00079980  38 60 00 01 */	li r3, 1
/* 8007CA24 00079984  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8007CA28 00079988  38 21 00 18 */	addi r1, r1, 0x18
/* 8007CA2C 0007998C  7C 08 03 A6 */	mtlr r0
/* 8007CA30 00079990  4E 80 00 20 */	blr 

.global actPiki__12InteractWarnFP4Piki
actPiki__12InteractWarnFP4Piki:
/* 8007CA34 00079994  7C 08 02 A6 */	mflr r0
/* 8007CA38 00079998  90 01 00 04 */	stw r0, 4(r1)
/* 8007CA3C 0007999C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8007CA40 000799A0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8007CA44 000799A4  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8007CA48 000799A8  3B C4 00 00 */	addi r30, r4, 0
/* 8007CA4C 000799AC  38 7E 00 00 */	addi r3, r30, 0
/* 8007CA50 000799B0  48 04 BB 05 */	bl getState__4PikiFv
/* 8007CA54 000799B4  3B E3 00 00 */	addi r31, r3, 0
/* 8007CA58 000799B8  38 7E 00 00 */	addi r3, r30, 0
/* 8007CA5C 000799BC  81 9E 00 00 */	lwz r12, 0(r30)
/* 8007CA60 000799C0  81 8C 00 88 */	lwz r12, 0x88(r12)
/* 8007CA64 000799C4  7D 88 03 A6 */	mtlr r12
/* 8007CA68 000799C8  4E 80 00 21 */	blrl 
/* 8007CA6C 000799CC  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8007CA70 000799D0  40 82 00 0C */	bne lbl_8007CA7C
/* 8007CA74 000799D4  38 60 00 00 */	li r3, 0
/* 8007CA78 000799D8  48 00 00 A8 */	b lbl_8007CB20
lbl_8007CA7C:
/* 8007CA7C 000799DC  7F C3 F3 78 */	mr r3, r30
/* 8007CA80 000799E0  81 9E 00 00 */	lwz r12, 0(r30)
/* 8007CA84 000799E4  81 8C 01 20 */	lwz r12, 0x120(r12)
/* 8007CA88 000799E8  7D 88 03 A6 */	mtlr r12
/* 8007CA8C 000799EC  4E 80 00 21 */	blrl 
/* 8007CA90 000799F0  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8007CA94 000799F4  40 82 00 1C */	bne lbl_8007CAB0
/* 8007CA98 000799F8  88 1E 04 09 */	lbz r0, 0x409(r30)
/* 8007CA9C 000799FC  28 00 00 00 */	cmplwi r0, 0
/* 8007CAA0 00079A00  41 82 00 10 */	beq lbl_8007CAB0
/* 8007CAA4 00079A04  A0 1E 04 FC */	lhz r0, 0x4fc(r30)
/* 8007CAA8 00079A08  28 00 00 01 */	cmplwi r0, 1
/* 8007CAAC 00079A0C  40 82 00 0C */	bne lbl_8007CAB8
lbl_8007CAB0:
/* 8007CAB0 00079A10  38 60 00 00 */	li r3, 0
/* 8007CAB4 00079A14  48 00 00 6C */	b lbl_8007CB20
lbl_8007CAB8:
/* 8007CAB8 00079A18  2C 1F 00 08 */	cmpwi r31, 8
/* 8007CABC 00079A1C  41 82 00 1C */	beq lbl_8007CAD8
/* 8007CAC0 00079A20  2C 1F 00 18 */	cmpwi r31, 0x18
/* 8007CAC4 00079A24  41 82 00 14 */	beq lbl_8007CAD8
/* 8007CAC8 00079A28  2C 1F 00 1A */	cmpwi r31, 0x1a
/* 8007CACC 00079A2C  41 82 00 0C */	beq lbl_8007CAD8
/* 8007CAD0 00079A30  2C 1F 00 21 */	cmpwi r31, 0x21
/* 8007CAD4 00079A34  40 82 00 0C */	bne lbl_8007CAE0
lbl_8007CAD8:
/* 8007CAD8 00079A38  38 60 00 00 */	li r3, 0
/* 8007CADC 00079A3C  48 00 00 44 */	b lbl_8007CB20
lbl_8007CAE0:
/* 8007CAE0 00079A40  88 1E 02 B4 */	lbz r0, 0x2b4(r30)
/* 8007CAE4 00079A44  28 00 00 00 */	cmplwi r0, 0
/* 8007CAE8 00079A48  40 82 00 2C */	bne lbl_8007CB14
/* 8007CAEC 00079A4C  2C 1F 00 16 */	cmpwi r31, 0x16
/* 8007CAF0 00079A50  41 82 00 24 */	beq lbl_8007CB14
/* 8007CAF4 00079A54  80 7E 04 90 */	lwz r3, 0x490(r30)
/* 8007CAF8 00079A58  38 9E 00 00 */	addi r4, r30, 0
/* 8007CAFC 00079A5C  38 A0 00 1A */	li r5, 0x1a
/* 8007CB00 00079A60  81 83 00 00 */	lwz r12, 0(r3)
/* 8007CB04 00079A64  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8007CB08 00079A68  7D 88 03 A6 */	mtlr r12
/* 8007CB0C 00079A6C  4E 80 00 21 */	blrl 
/* 8007CB10 00079A70  48 00 00 0C */	b lbl_8007CB1C
lbl_8007CB14:
/* 8007CB14 00079A74  38 00 00 01 */	li r0, 1
/* 8007CB18 00079A78  98 1E 04 A0 */	stb r0, 0x4a0(r30)
lbl_8007CB1C:
/* 8007CB1C 00079A7C  38 60 00 01 */	li r3, 1
lbl_8007CB20:
/* 8007CB20 00079A80  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8007CB24 00079A84  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8007CB28 00079A88  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8007CB2C 00079A8C  38 21 00 18 */	addi r1, r1, 0x18
/* 8007CB30 00079A90  7C 08 03 A6 */	mtlr r0
/* 8007CB34 00079A94  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802AD200:
	.asciz "interactEtc.cpp"
.balign 4
lbl_802AD210:
	.asciz "interactEtc"
.balign 4
lbl_802AD21C:
	.asciz "InteractWarn"
.balign 4
lbl_802AD22C:
	.asciz "Interaction"
.balign 4
lbl_802AD238:
	.4byte __RTTI__11Interaction
	.4byte 0
	.4byte 0
.global __vt__12InteractWarn
__vt__12InteractWarn:
	.4byte __RTTI__12InteractWarn
	.4byte 0
	.4byte actCommon__11InteractionFP8Creature
	.4byte actPiki__12InteractWarnFP4Piki
	.4byte actTeki__11InteractionFP4Teki
	.4byte actNavi__11InteractionFP4Navi
	.4byte actBoss__11InteractionFP4Boss
	.4byte actPellet__11InteractionFP6Pellet
	.4byte actHinderRock__11InteractionFP10HinderRock
	.4byte actBridge__11InteractionFP6Bridge
	.4byte actItem__11InteractionFP12ItemCreature
.balign 4
lbl_802AD270:
	.asciz "InteractTalk"
.balign 4
lbl_802AD280:
	.4byte __RTTI__11Interaction
	.4byte 0
	.4byte 0
.global __vt__12InteractTalk
__vt__12InteractTalk:
	.4byte __RTTI__12InteractTalk
	.4byte 0
	.4byte actCommon__11InteractionFP8Creature
	.4byte actPiki__12InteractTalkFP4Piki
	.4byte actTeki__11InteractionFP4Teki
	.4byte actNavi__11InteractionFP4Navi
	.4byte actBoss__11InteractionFP4Boss
	.4byte actPellet__11InteractionFP6Pellet
	.4byte actHinderRock__11InteractionFP10HinderRock
	.4byte actBridge__11InteractionFP6Bridge
	.4byte actItem__11InteractionFP12ItemCreature

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__11Interaction:
	.4byte lbl_802AD22C
	.4byte 0
__RTTI__12InteractWarn:
	.4byte lbl_802AD21C
	.4byte lbl_802AD238
__RTTI__12InteractTalk:
	.4byte lbl_802AD270
	.4byte lbl_802AD280
