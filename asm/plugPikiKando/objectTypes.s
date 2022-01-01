.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global getName__7ObjTypeFi
getName__7ObjTypeFi:
/* 80094A38 00091998  3C 80 80 2B */	lis r4, lbl_802AFBF0@ha
/* 80094A3C 0009199C  38 84 FB F0 */	addi r4, r4, lbl_802AFBF0@l
/* 80094A40 000919A0  38 A4 01 5C */	addi r5, r4, 0x15c
/* 80094A44 000919A4  38 C0 00 00 */	li r6, 0
/* 80094A48 000919A8  48 00 00 24 */	b lbl_80094A6C
lbl_80094A4C:
/* 80094A4C 000919AC  7C 03 00 00 */	cmpw r3, r0
/* 80094A50 000919B0  40 82 00 14 */	bne lbl_80094A64
/* 80094A54 000919B4  54 C0 18 38 */	slwi r0, r6, 3
/* 80094A58 000919B8  7C 64 02 14 */	add r3, r4, r0
/* 80094A5C 000919BC  80 63 01 60 */	lwz r3, 0x160(r3)
/* 80094A60 000919C0  4E 80 00 20 */	blr 
lbl_80094A64:
/* 80094A64 000919C4  38 A5 00 08 */	addi r5, r5, 8
/* 80094A68 000919C8  38 C6 00 01 */	addi r6, r6, 1
lbl_80094A6C:
/* 80094A6C 000919CC  80 05 00 00 */	lwz r0, 0(r5)
/* 80094A70 000919D0  2C 00 00 39 */	cmpwi r0, 0x39
/* 80094A74 000919D4  40 82 FF D8 */	bne lbl_80094A4C
/* 80094A78 000919D8  38 64 03 14 */	addi r3, r4, 0x314
/* 80094A7C 000919DC  4E 80 00 20 */	blr 

.global getIndex__7ObjTypeFPc
getIndex__7ObjTypeFPc:
/* 80094A80 000919E0  7C 08 02 A6 */	mflr r0
/* 80094A84 000919E4  3C 80 80 2B */	lis r4, _info@ha
/* 80094A88 000919E8  90 01 00 04 */	stw r0, 4(r1)
/* 80094A8C 000919EC  38 04 FD 4C */	addi r0, r4, _info@l
/* 80094A90 000919F0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80094A94 000919F4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80094A98 000919F8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80094A9C 000919FC  3B C0 00 00 */	li r30, 0
/* 80094AA0 00091A00  57 C5 18 38 */	slwi r5, r30, 3
/* 80094AA4 00091A04  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80094AA8 00091A08  7F E0 2A 14 */	add r31, r0, r5
/* 80094AAC 00091A0C  3B A3 00 00 */	addi r29, r3, 0
/* 80094AB0 00091A10  48 00 00 38 */	b lbl_80094AE8
lbl_80094AB4:
/* 80094AB4 00091A14  7F A3 EB 78 */	mr r3, r29
/* 80094AB8 00091A18  80 9F 00 04 */	lwz r4, 4(r31)
/* 80094ABC 00091A1C  48 18 47 09 */	bl strcmp
/* 80094AC0 00091A20  2C 03 00 00 */	cmpwi r3, 0
/* 80094AC4 00091A24  40 82 00 1C */	bne lbl_80094AE0
/* 80094AC8 00091A28  3C 60 80 2B */	lis r3, _info@ha
/* 80094ACC 00091A2C  57 C4 18 38 */	slwi r4, r30, 3
/* 80094AD0 00091A30  38 03 FD 4C */	addi r0, r3, _info@l
/* 80094AD4 00091A34  7C 60 22 14 */	add r3, r0, r4
/* 80094AD8 00091A38  80 63 00 00 */	lwz r3, 0(r3)
/* 80094ADC 00091A3C  48 00 00 1C */	b lbl_80094AF8
lbl_80094AE0:
/* 80094AE0 00091A40  3B FF 00 08 */	addi r31, r31, 8
/* 80094AE4 00091A44  3B DE 00 01 */	addi r30, r30, 1
lbl_80094AE8:
/* 80094AE8 00091A48  80 1F 00 00 */	lwz r0, 0(r31)
/* 80094AEC 00091A4C  2C 00 00 39 */	cmpwi r0, 0x39
/* 80094AF0 00091A50  40 82 FF C4 */	bne lbl_80094AB4
/* 80094AF4 00091A54  38 60 FF FF */	li r3, -1
lbl_80094AF8:
/* 80094AF8 00091A58  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80094AFC 00091A5C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80094B00 00091A60  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80094B04 00091A64  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80094B08 00091A68  38 21 00 20 */	addi r1, r1, 0x20
/* 80094B0C 00091A6C  7C 08 03 A6 */	mtlr r0
/* 80094B10 00091A70  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802AFBF0:
	.asciz "fall water"
.balign 4
lbl_802AFBFC:
	.asciz "never use this"
.balign 4
lbl_802AFC0C:
	.asciz "bomb gen"
.balign 4
lbl_802AFC18:
	.asciz "pikihead"
.balign 4
lbl_802AFC24:
	.asciz "cylinder test"
.balign 4
lbl_802AFC34:
	.asciz "sluice soft"
.balign 4
lbl_802AFC40:
	.asciz "sluice hard"
.balign 4
lbl_802AFC4C:
	.asciz "sluice bomb"
.balign 4
lbl_802AFC58:
	.asciz "sluice bombhard"
.balign 4
lbl_802AFC68:
	.asciz "dual test"
.balign 4
lbl_802AFC74:
	.asciz "<demo:sunset> start"
.balign 4
lbl_802AFC88:
	.asciz "<demo:sunset> goal"
.balign 4
lbl_802AFC9C:
	.asciz "grassgen"
.balign 4
lbl_802AFCA8:
	.asciz "<bo base>"
.balign 4
lbl_802AFCB4:
	.asciz "workobject"
.balign 4
lbl_802AFCC0:
	.asciz "boss:Spider"
.balign 4
lbl_802AFCCC:
	.asciz "boss:Giant"
.balign 4
lbl_802AFCD8:
	.asciz "boss:Snake"
.balign 4
lbl_802AFCE4:
	.asciz "boss:TwSnake"
.balign 4
lbl_802AFCF4:
	.asciz "boss:King"
.balign 4
lbl_802AFD00:
	.asciz "boss:Slime"
.balign 4
lbl_802AFD0C:
	.asciz "boss:Kogane"
.balign 4
lbl_802AFD18:
	.asciz "boss:Pom"
.balign 4
lbl_802AFD24:
	.asciz "boss:KingBack"
.balign 4
lbl_802AFD34:
	.asciz "boss:Mizu"
.balign 4
lbl_802AFD40:
	.asciz "boss:XXX3"
.balign 4
_info:
	.4byte 0x00000000
	.4byte lbl_803DF348
	.4byte 0x00000037
	.4byte lbl_803DF350
	.4byte 0x00000036
	.4byte lbl_803DF358
	.4byte 0x00000001
	.4byte lbl_803DF360
	.4byte 0x00000002
	.4byte lbl_803DF368
	.4byte 0x00000003
	.4byte lbl_803DF370
	.4byte 0x00000004
	.4byte lbl_803DF374
	.4byte 0x00000005
	.4byte lbl_803DF37C
	.4byte 0x00000006
	.4byte lbl_802AFBF0
	.4byte 0x00000007
	.4byte lbl_803DF384
	.4byte 0x00000008
	.4byte lbl_803DF38C
	.4byte 0x00000009
	.4byte lbl_803DF394
	.4byte 0x0000000A
	.4byte lbl_803DF39C
	.4byte 0x0000000B
	.4byte lbl_803DF3A4
	.4byte 0x0000000C
	.4byte lbl_802AFBFC
	.4byte 0x0000000D
	.4byte lbl_802AFC0C
	.4byte 0x0000000E
	.4byte lbl_803DF3AC
	.4byte 0x0000000F
	.4byte lbl_802AFC18
	.4byte 0x00000010
	.4byte lbl_803DF3B4
	.4byte 0x00000011
	.4byte lbl_803DF3BC
	.4byte 0x00000012
	.4byte lbl_803DF3C4
	.4byte 0x00000013
	.4byte lbl_803DF3CC
	.4byte 0x00000014
	.4byte lbl_802AFC24
	.4byte 0x00000016
	.4byte lbl_802AFC34
	.4byte 0x00000017
	.4byte lbl_802AFC40
	.4byte 0x00000018
	.4byte lbl_802AFC4C
	.4byte 0x00000019
	.4byte lbl_802AFC58
	.4byte 0x0000001A
	.4byte lbl_803DF3D0
	.4byte 0x00000015
	.4byte lbl_802AFC68
	.4byte 0x0000001B
	.4byte lbl_802AFC74
	.4byte 0x0000001C
	.4byte lbl_802AFC88
	.4byte 0x0000001D
	.4byte lbl_803DF3D8
	.4byte 0x0000001E
	.4byte lbl_803DF3E0
	.4byte 0x0000001F
	.4byte lbl_803DF3E4
	.4byte 0x00000020
	.4byte lbl_803DF3EC
	.4byte 0x00000021
	.4byte lbl_803DF3F4
	.4byte 0x00000022
	.4byte lbl_802AFC9C
	.4byte 0x00000025
	.4byte lbl_803DF3FC
	.4byte 0x00000023
	.4byte lbl_802AFCA8
	.4byte 0x00000024
	.4byte lbl_803DF404
	.4byte 0x00000026
	.4byte lbl_802AFCB4
	.4byte 0x00000027
	.4byte lbl_802AFCC0
	.4byte 0x00000028
	.4byte lbl_802AFCCC
	.4byte 0x00000029
	.4byte lbl_802AFCD8
	.4byte 0x0000002A
	.4byte lbl_802AFCE4
	.4byte 0x0000002B
	.4byte lbl_802AFCF4
	.4byte 0x0000002C
	.4byte lbl_802AFD00
	.4byte 0x0000002D
	.4byte lbl_802AFD0C
	.4byte 0x0000002E
	.4byte lbl_802AFD18
	.4byte 0x0000002F
	.4byte lbl_802AFD24
	.4byte 0x00000031
	.4byte lbl_802AFD34
	.4byte 0x00000032
	.4byte lbl_802AFD40
	.4byte 0x00000033
	.4byte lbl_803DF40C
	.4byte 0x00000034
	.4byte lbl_803DF414
	.4byte 0x00000039
	.4byte lbl_803DF41C
.balign 4
lbl_802AFF04:
	.asciz "invalid objname"

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DF348:
	.asciz "piki"
.balign 4
lbl_803DF350:
	.asciz "teki"
.balign 4
lbl_803DF358:
	.asciz "navi"
.balign 4
lbl_803DF360:
	.asciz "water"
.balign 4
lbl_803DF368:
	.asciz "seed"
.balign 4
lbl_803DF370:
	.asciz "key"
.balign 4
lbl_803DF374:
	.asciz "door"
.balign 4
lbl_803DF37C:
	.asciz "gate"
.balign 4
lbl_803DF384:
	.asciz "gem5"
.balign 4
lbl_803DF38C:
	.asciz "gem10"
.balign 4
lbl_803DF394:
	.asciz "gem20"
.balign 4
lbl_803DF39C:
	.asciz "gem50"
.balign 4
lbl_803DF3A4:
	.asciz "gem1"
.balign 4
lbl_803DF3AC:
	.asciz "bomb"
.balign 4
lbl_803DF3B4:
	.asciz "goal"
.balign 4
lbl_803DF3BC:
	.asciz "fulcrum"
.balign 4
lbl_803DF3C4:
	.asciz "rope"
.balign 4
lbl_803DF3CC:
	.asciz "ivy"
.balign 4
lbl_803DF3D0:
	.asciz "rocket"
.balign 4
lbl_803DF3D8:
	.asciz "kusa"
.balign 4
lbl_803DF3E0:
	.asciz "ufo"
.balign 4
lbl_803DF3E4:
	.asciz "weeds"
.balign 4
lbl_803DF3EC:
	.asciz "<weed>"
.balign 4
lbl_803DF3F4:
	.asciz "rockgen"
.balign 4
lbl_803DF3FC:
	.asciz "fish"
.balign 4
lbl_803DF404:
	.asciz "secret1"
.balign 4
lbl_803DF40C:
	.asciz "PLANT"
.balign 4
lbl_803DF414:
	.asciz "PELLET"
.balign 4
lbl_803DF41C:
	.asciz ""
