.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global touchCallback__16CreatureCollPartFR5PlaneR8Vector3fR8Vector3f
touchCallback__16CreatureCollPartFR5PlaneR8Vector3fR8Vector3f:
/* 8008E0BC 0008B01C  4E 80 00 20 */	blr 

.global init__15CreaturePlatMgrFP8CreatureP6MapMgrP5Shape
init__15CreaturePlatMgrFP8CreatureP6MapMgrP5Shape:
/* 8008E0C0 0008B020  7C 08 02 A6 */	mflr r0
/* 8008E0C4 0008B024  90 01 00 04 */	stw r0, 4(r1)
/* 8008E0C8 0008B028  38 00 00 00 */	li r0, 0
/* 8008E0CC 0008B02C  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8008E0D0 0008B030  93 E1 00 34 */	stw r31, 0x34(r1)
/* 8008E0D4 0008B034  93 C1 00 30 */	stw r30, 0x30(r1)
/* 8008E0D8 0008B038  3B C5 00 00 */	addi r30, r5, 0
/* 8008E0DC 0008B03C  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 8008E0E0 0008B040  3B A4 00 00 */	addi r29, r4, 0
/* 8008E0E4 0008B044  93 81 00 28 */	stw r28, 0x28(r1)
/* 8008E0E8 0008B048  3B 83 00 00 */	addi r28, r3, 0
/* 8008E0EC 0008B04C  90 03 00 44 */	stw r0, 0x44(r3)
/* 8008E0F0 0008B050  90 C3 00 00 */	stw r6, 0(r3)
/* 8008E0F4 0008B054  80 63 00 00 */	lwz r3, 0(r3)
/* 8008E0F8 0008B058  83 E3 00 F8 */	lwz r31, 0xf8(r3)
/* 8008E0FC 0008B05C  48 00 00 3C */	b lbl_8008E138
lbl_8008E100:
/* 8008E100 0008B060  80 1F 00 48 */	lwz r0, 0x48(r31)
/* 8008E104 0008B064  28 00 00 00 */	cmplwi r0, 0
/* 8008E108 0008B068  41 82 00 2C */	beq lbl_8008E134
/* 8008E10C 0008B06C  38 7E 00 00 */	addi r3, r30, 0
/* 8008E110 0008B070  38 9F 00 00 */	addi r4, r31, 0
/* 8008E114 0008B074  38 BD 00 00 */	addi r5, r29, 0
/* 8008E118 0008B078  4B FD B3 7D */	bl requestCollPart__6MapMgrFP11ObjCollInfoP8Creature
/* 8008E11C 0008B07C  80 9C 00 44 */	lwz r4, 0x44(r28)
/* 8008E120 0008B080  38 04 00 01 */	addi r0, r4, 1
/* 8008E124 0008B084  54 84 10 3A */	slwi r4, r4, 2
/* 8008E128 0008B088  90 1C 00 44 */	stw r0, 0x44(r28)
/* 8008E12C 0008B08C  38 04 00 04 */	addi r0, r4, 4
/* 8008E130 0008B090  7C 7C 01 2E */	stwx r3, r28, r0
lbl_8008E134:
/* 8008E134 0008B094  83 FF 00 0C */	lwz r31, 0xc(r31)
lbl_8008E138:
/* 8008E138 0008B098  28 1F 00 00 */	cmplwi r31, 0
/* 8008E13C 0008B09C  40 82 FF C4 */	bne lbl_8008E100
/* 8008E140 0008B0A0  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8008E144 0008B0A4  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 8008E148 0008B0A8  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 8008E14C 0008B0AC  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 8008E150 0008B0B0  83 81 00 28 */	lwz r28, 0x28(r1)
/* 8008E154 0008B0B4  38 21 00 38 */	addi r1, r1, 0x38
/* 8008E158 0008B0B8  7C 08 03 A6 */	mtlr r0
/* 8008E15C 0008B0BC  4E 80 00 20 */	blr 

.global release__15CreaturePlatMgrFv
release__15CreaturePlatMgrFv:
/* 8008E160 0008B0C0  7C 08 02 A6 */	mflr r0
/* 8008E164 0008B0C4  90 01 00 04 */	stw r0, 4(r1)
/* 8008E168 0008B0C8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8008E16C 0008B0CC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8008E170 0008B0D0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8008E174 0008B0D4  3B C0 00 00 */	li r30, 0
/* 8008E178 0008B0D8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8008E17C 0008B0DC  3B A3 00 00 */	addi r29, r3, 0
/* 8008E180 0008B0E0  3B FD 00 00 */	addi r31, r29, 0
/* 8008E184 0008B0E4  48 00 00 14 */	b lbl_8008E198
lbl_8008E188:
/* 8008E188 0008B0E8  80 7F 00 04 */	lwz r3, 4(r31)
/* 8008E18C 0008B0EC  4B FB 24 85 */	bl del__8CoreNodeFv
/* 8008E190 0008B0F0  3B FF 00 04 */	addi r31, r31, 4
/* 8008E194 0008B0F4  3B DE 00 01 */	addi r30, r30, 1
lbl_8008E198:
/* 8008E198 0008B0F8  80 1D 00 44 */	lwz r0, 0x44(r29)
/* 8008E19C 0008B0FC  7C 1E 00 00 */	cmpw r30, r0
/* 8008E1A0 0008B100  41 80 FF E8 */	blt lbl_8008E188
/* 8008E1A4 0008B104  38 00 00 00 */	li r0, 0
/* 8008E1A8 0008B108  90 1D 00 44 */	stw r0, 0x44(r29)
/* 8008E1AC 0008B10C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8008E1B0 0008B110  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8008E1B4 0008B114  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8008E1B8 0008B118  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8008E1BC 0008B11C  38 21 00 20 */	addi r1, r1, 0x20
/* 8008E1C0 0008B120  7C 08 03 A6 */	mtlr r0
/* 8008E1C4 0008B124  4E 80 00 20 */	blr 

.global update__15CreaturePlatMgrFR8Graphics
update__15CreaturePlatMgrFR8Graphics:
/* 8008E1C8 0008B128  7C 08 02 A6 */	mflr r0
/* 8008E1CC 0008B12C  90 01 00 04 */	stw r0, 4(r1)
/* 8008E1D0 0008B130  94 21 FF 98 */	stwu r1, -0x68(r1)
/* 8008E1D4 0008B134  BF 61 00 54 */	stmw r27, 0x54(r1)
/* 8008E1D8 0008B138  3B 83 00 00 */	addi r28, r3, 0
/* 8008E1DC 0008B13C  3B A4 00 00 */	addi r29, r4, 0
/* 8008E1E0 0008B140  3B FC 00 00 */	addi r31, r28, 0
/* 8008E1E4 0008B144  3B C0 00 00 */	li r30, 0
/* 8008E1E8 0008B148  48 00 00 BC */	b lbl_8008E2A4
lbl_8008E1EC:
/* 8008E1EC 0008B14C  83 7F 00 04 */	lwz r27, 4(r31)
/* 8008E1F0 0008B150  38 7B 00 5C */	addi r3, r27, 0x5c
/* 8008E1F4 0008B154  38 9B 00 9C */	addi r4, r27, 0x9c
/* 8008E1F8 0008B158  4B FB 02 45 */	bl inverse__8Matrix4fFP8Matrix4f
/* 8008E1FC 0008B15C  80 7C 00 00 */	lwz r3, 0(r28)
/* 8008E200 0008B160  80 9B 01 44 */	lwz r4, 0x144(r27)
/* 8008E204 0008B164  4B FA 6D E5 */	bl getAnimMatrix__9BaseShapeFi
/* 8008E208 0008B168  80 C3 00 00 */	lwz r6, 0(r3)
/* 8008E20C 0008B16C  38 81 00 10 */	addi r4, r1, 0x10
/* 8008E210 0008B170  80 03 00 04 */	lwz r0, 4(r3)
/* 8008E214 0008B174  38 BB 00 5C */	addi r5, r27, 0x5c
/* 8008E218 0008B178  90 C1 00 10 */	stw r6, 0x10(r1)
/* 8008E21C 0008B17C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8008E220 0008B180  80 C3 00 08 */	lwz r6, 8(r3)
/* 8008E224 0008B184  80 03 00 0C */	lwz r0, 0xc(r3)
/* 8008E228 0008B188  90 C1 00 18 */	stw r6, 0x18(r1)
/* 8008E22C 0008B18C  90 01 00 1C */	stw r0, 0x1c(r1)
/* 8008E230 0008B190  80 C3 00 10 */	lwz r6, 0x10(r3)
/* 8008E234 0008B194  80 03 00 14 */	lwz r0, 0x14(r3)
/* 8008E238 0008B198  90 C1 00 20 */	stw r6, 0x20(r1)
/* 8008E23C 0008B19C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8008E240 0008B1A0  80 C3 00 18 */	lwz r6, 0x18(r3)
/* 8008E244 0008B1A4  80 03 00 1C */	lwz r0, 0x1c(r3)
/* 8008E248 0008B1A8  90 C1 00 28 */	stw r6, 0x28(r1)
/* 8008E24C 0008B1AC  90 01 00 2C */	stw r0, 0x2c(r1)
/* 8008E250 0008B1B0  80 C3 00 20 */	lwz r6, 0x20(r3)
/* 8008E254 0008B1B4  80 03 00 24 */	lwz r0, 0x24(r3)
/* 8008E258 0008B1B8  90 C1 00 30 */	stw r6, 0x30(r1)
/* 8008E25C 0008B1BC  90 01 00 34 */	stw r0, 0x34(r1)
/* 8008E260 0008B1C0  80 C3 00 28 */	lwz r6, 0x28(r3)
/* 8008E264 0008B1C4  80 03 00 2C */	lwz r0, 0x2c(r3)
/* 8008E268 0008B1C8  90 C1 00 38 */	stw r6, 0x38(r1)
/* 8008E26C 0008B1CC  90 01 00 3C */	stw r0, 0x3c(r1)
/* 8008E270 0008B1D0  80 C3 00 30 */	lwz r6, 0x30(r3)
/* 8008E274 0008B1D4  80 03 00 34 */	lwz r0, 0x34(r3)
/* 8008E278 0008B1D8  90 C1 00 40 */	stw r6, 0x40(r1)
/* 8008E27C 0008B1DC  90 01 00 44 */	stw r0, 0x44(r1)
/* 8008E280 0008B1E0  80 C3 00 38 */	lwz r6, 0x38(r3)
/* 8008E284 0008B1E4  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 8008E288 0008B1E8  90 C1 00 48 */	stw r6, 0x48(r1)
/* 8008E28C 0008B1EC  90 01 00 4C */	stw r0, 0x4c(r1)
/* 8008E290 0008B1F0  80 7D 02 E4 */	lwz r3, 0x2e4(r29)
/* 8008E294 0008B1F4  38 63 02 20 */	addi r3, r3, 0x220
/* 8008E298 0008B1F8  4B FA FE 3D */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 8008E29C 0008B1FC  3B FF 00 04 */	addi r31, r31, 4
/* 8008E2A0 0008B200  3B DE 00 01 */	addi r30, r30, 1
lbl_8008E2A4:
/* 8008E2A4 0008B204  80 1C 00 44 */	lwz r0, 0x44(r28)
/* 8008E2A8 0008B208  7C 1E 00 00 */	cmpw r30, r0
/* 8008E2AC 0008B20C  41 80 FF 40 */	blt lbl_8008E1EC
/* 8008E2B0 0008B210  BB 61 00 54 */	lmw r27, 0x54(r1)
/* 8008E2B4 0008B214  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 8008E2B8 0008B218  38 21 00 68 */	addi r1, r1, 0x68
/* 8008E2BC 0008B21C  7C 08 03 A6 */	mtlr r0
/* 8008E2C0 0008B220  4E 80 00 20 */	blr 

.global update__16CreatureCollPartFv
update__16CreatureCollPartFv:
/* 8008E2C4 0008B224  4E 80 00 20 */	blr 

.global refresh__16CreatureCollPartFR8Graphics
refresh__16CreatureCollPartFR8Graphics:
/* 8008E2C8 0008B228  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802AF1E8:
	.asciz "creatureCollPart.cpp"
.balign 4
lbl_802AF200:
	.asciz "creatureCollPart"
.balign 4
lbl_802AF214:
	.asciz "CreatureCollPart"
.balign 4
lbl_802AF228:
	.asciz "CoreNode"
.balign 4
lbl_802AF234:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
lbl_802AF240:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.balign 4
lbl_802AF254:
	.asciz "DynCollObject"
.balign 4
lbl_802AF264:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.balign 4
lbl_802AF280:
	.asciz "DynCollShape"
.balign 4
lbl_802AF290:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__13DynCollObject
	.4byte 0
	.4byte 0
lbl_802AF2B4:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__13DynCollObject
	.4byte 0
	.4byte __RTTI__12DynCollShape
	.4byte 0
	.4byte 0
.global __vt__16CreatureCollPart
__vt__16CreatureCollPart:
	.4byte __RTTI__16CreatureCollPart
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__16CreatureCollPartFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte adjust__12DynCollShapeFP8Creature
	.4byte applyVelocity__13DynCollObjectFR5PlaneR8Vector3fR8Vector3f
	.4byte touchCallback__16CreatureCollPartFR5PlaneR8Vector3fR8Vector3f
	.4byte getShape__12DynCollShapeFv
	.4byte jointVisible__12DynCollShapeFii
	.4byte refresh__16CreatureCollPartFR8Graphics

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DF058:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803DF058
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802AF228
	.4byte lbl_802AF234
.balign 4
lbl_803DF070:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803DF070
	.4byte lbl_802AF240
__RTTI__13DynCollObject:
	.4byte lbl_802AF254
	.4byte lbl_802AF264
__RTTI__12DynCollShape:
	.4byte lbl_802AF280
	.4byte lbl_802AF290
__RTTI__16CreatureCollPart:
	.4byte lbl_802AF214
	.4byte lbl_802AF2B4
