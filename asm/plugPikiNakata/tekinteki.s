.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__5NTekiFv, global
/* 8014B9F8 00148958  7C 08 02 A6 */	mflr r0
/* 8014B9FC 0014895C  90 01 00 04 */	stw r0, 4(r1)
/* 8014BA00 00148960  7C 80 07 35 */	extsh. r0, r4
/* 8014BA04 00148964  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8014BA08 00148968  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8014BA0C 0014896C  3B E3 00 00 */	addi r31, r3, 0
/* 8014BA10 00148970  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8014BA14 00148974  41 82 00 18 */	beq .L_8014BA2C
/* 8014BA18 00148978  38 1F 04 6C */	addi r0, r31, 0x46c
/* 8014BA1C 0014897C  3C 60 80 2B */	lis r3, __vt__19PaniAnimKeyListener@ha
/* 8014BA20 00148980  90 1F 02 C0 */	stw r0, 0x2c0(r31)
/* 8014BA24 00148984  38 03 DB 94 */	addi r0, r3, __vt__19PaniAnimKeyListener@l
/* 8014BA28 00148988  90 1F 04 6C */	stw r0, 0x46c(r31)
.L_8014BA2C:
/* 8014BA2C 0014898C  38 7F 00 00 */	addi r3, r31, 0
/* 8014BA30 00148990  38 80 00 00 */	li r4, 0
/* 8014BA34 00148994  4B FF 8B 65 */	bl __ct__5BTekiFv
/* 8014BA38 00148998  3C 60 80 2D */	lis r3, __vt__5NTeki@ha
/* 8014BA3C 0014899C  38 63 DD F8 */	addi r3, r3, __vt__5NTeki@l
/* 8014BA40 001489A0  90 7F 00 00 */	stw r3, 0(r31)
/* 8014BA44 001489A4  38 C3 01 F4 */	addi r6, r3, 0x1f4
/* 8014BA48 001489A8  38 83 01 14 */	addi r4, r3, 0x114
/* 8014BA4C 001489AC  80 BF 02 C0 */	lwz r5, 0x2c0(r31)
/* 8014BA50 001489B0  38 1F 04 6C */	addi r0, r31, 0x46c
/* 8014BA54 001489B4  38 60 00 40 */	li r3, 0x40
/* 8014BA58 001489B8  90 C5 00 00 */	stw r6, 0(r5)
/* 8014BA5C 001489BC  90 9F 02 B8 */	stw r4, 0x2b8(r31)
/* 8014BA60 001489C0  80 9F 02 C0 */	lwz r4, 0x2c0(r31)
/* 8014BA64 001489C4  7C 04 00 50 */	subf r0, r4, r0
/* 8014BA68 001489C8  90 04 00 04 */	stw r0, 4(r4)
/* 8014BA6C 001489CC  4B EF B5 99 */	bl alloc__6SystemFUl
/* 8014BA70 001489D0  3B C3 00 00 */	addi r30, r3, 0
/* 8014BA74 001489D4  7F C3 F3 79 */	or. r3, r30, r30
/* 8014BA78 001489D8  41 82 00 08 */	beq .L_8014BA80
/* 8014BA7C 001489DC  4B FD A6 59 */	bl __ct__17PeveParabolaEventFv
.L_8014BA80:
/* 8014BA80 001489E0  93 DF 04 5C */	stw r30, 0x45c(r31)
/* 8014BA84 001489E4  38 60 00 1C */	li r3, 0x1c
/* 8014BA88 001489E8  4B EF B5 7D */	bl alloc__6SystemFUl
/* 8014BA8C 001489EC  3B C3 00 00 */	addi r30, r3, 0
/* 8014BA90 001489F0  7F C3 F3 79 */	or. r3, r30, r30
/* 8014BA94 001489F4  41 82 00 08 */	beq .L_8014BA9C
/* 8014BA98 001489F8  4B FD A4 6D */	bl __ct__21PeveAccelerationEventFv
.L_8014BA9C:
/* 8014BA9C 001489FC  93 DF 04 60 */	stw r30, 0x460(r31)
/* 8014BAA0 00148A00  38 60 00 38 */	li r3, 0x38
/* 8014BAA4 00148A04  4B EF B5 61 */	bl alloc__6SystemFUl
/* 8014BAA8 00148A08  3B C3 00 00 */	addi r30, r3, 0
/* 8014BAAC 00148A0C  7F C3 F3 79 */	or. r3, r30, r30
/* 8014BAB0 00148A10  41 82 00 08 */	beq .L_8014BAB8
/* 8014BAB4 00148A14  4B FD A8 DD */	bl __ct__19PeveCircleMoveEventFv
.L_8014BAB8:
/* 8014BAB8 00148A18  93 DF 04 64 */	stw r30, 0x464(r31)
/* 8014BABC 00148A1C  38 60 00 34 */	li r3, 0x34
/* 8014BAC0 00148A20  4B EF B5 45 */	bl alloc__6SystemFUl
/* 8014BAC4 00148A24  7C 7E 1B 79 */	or. r30, r3, r3
/* 8014BAC8 00148A28  41 82 00 24 */	beq .L_8014BAEC
/* 8014BACC 00148A2C  38 7E 00 00 */	addi r3, r30, 0
/* 8014BAD0 00148A30  38 80 00 00 */	li r4, 0
/* 8014BAD4 00148A34  4B FD 9A 7D */	bl __ct__9PeveEventFi
/* 8014BAD8 00148A38  3C 60 80 2C */	lis r3, __vt__26PeveHorizontalSinWaveEvent@ha
/* 8014BADC 00148A3C  38 03 63 AC */	addi r0, r3, __vt__26PeveHorizontalSinWaveEvent@l
/* 8014BAE0 00148A40  90 1E 00 00 */	stw r0, 0(r30)
/* 8014BAE4 00148A44  38 7E 00 14 */	addi r3, r30, 0x14
/* 8014BAE8 00148A48  4B FD 13 6D */	bl __ct__9NVector3fFv
.L_8014BAEC:
/* 8014BAEC 00148A4C  93 DF 04 68 */	stw r30, 0x468(r31)
/* 8014BAF0 00148A50  7F E3 FB 78 */	mr r3, r31
/* 8014BAF4 00148A54  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8014BAF8 00148A58  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8014BAFC 00148A5C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8014BB00 00148A60  38 21 00 18 */	addi r1, r1, 0x18
/* 8014BB04 00148A64  7C 08 03 A6 */	mtlr r0
/* 8014BB08 00148A68  4E 80 00 20 */	blr 
.endfn __ct__5NTekiFv

.fn sendMessage__5NTekiFi, global
/* 8014BB0C 00148A6C  7C 08 02 A6 */	mflr r0
/* 8014BB10 00148A70  90 01 00 04 */	stw r0, 4(r1)
/* 8014BB14 00148A74  94 21 FF 38 */	stwu r1, -0xc8(r1)
/* 8014BB18 00148A78  DB E1 00 C0 */	stfd f31, 0xc0(r1)
/* 8014BB1C 00148A7C  BE C1 00 98 */	stmw r22, 0x98(r1)
/* 8014BB20 00148A80  3A E3 00 00 */	addi r23, r3, 0
/* 8014BB24 00148A84  3B 04 00 00 */	addi r24, r4, 0
/* 8014BB28 00148A88  83 4D 31 60 */	lwz r26, tekiMgr@sda21(r13)
/* 8014BB2C 00148A8C  81 9A 00 00 */	lwz r12, 0(r26)
/* 8014BB30 00148A90  38 7A 00 00 */	addi r3, r26, 0
/* 8014BB34 00148A94  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8014BB38 00148A98  7D 88 03 A6 */	mtlr r12
/* 8014BB3C 00148A9C  4E 80 00 21 */	blrl 
/* 8014BB40 00148AA0  C3 E2 A7 A0 */	lfs f31, lbl_803EA9A0@sda21(r2)
/* 8014BB44 00148AA4  3B 23 00 00 */	addi r25, r3, 0
/* 8014BB48 00148AA8  3B 61 00 7C */	addi r27, r1, 0x7c
/* 8014BB4C 00148AAC  3B F7 00 94 */	addi r31, r23, 0x94
/* 8014BB50 00148AB0  3B C1 00 50 */	addi r30, r1, 0x50
/* 8014BB54 00148AB4  3B A1 00 4C */	addi r29, r1, 0x4c
/* 8014BB58 00148AB8  3B 81 00 48 */	addi r28, r1, 0x48
/* 8014BB5C 00148ABC  48 00 01 10 */	b .L_8014BC6C
.L_8014BB60:
/* 8014BB60 00148AC0  2C 19 FF FF */	cmpwi r25, -1
/* 8014BB64 00148AC4  40 82 00 20 */	bne .L_8014BB84
/* 8014BB68 00148AC8  7F 43 D3 78 */	mr r3, r26
/* 8014BB6C 00148ACC  81 9A 00 00 */	lwz r12, 0(r26)
/* 8014BB70 00148AD0  38 80 00 00 */	li r4, 0
/* 8014BB74 00148AD4  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014BB78 00148AD8  7D 88 03 A6 */	mtlr r12
/* 8014BB7C 00148ADC  4E 80 00 21 */	blrl 
/* 8014BB80 00148AE0  48 00 00 1C */	b .L_8014BB9C
.L_8014BB84:
/* 8014BB84 00148AE4  7F 43 D3 78 */	mr r3, r26
/* 8014BB88 00148AE8  81 9A 00 00 */	lwz r12, 0(r26)
/* 8014BB8C 00148AEC  7F 24 CB 78 */	mr r4, r25
/* 8014BB90 00148AF0  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014BB94 00148AF4  7D 88 03 A6 */	mtlr r12
/* 8014BB98 00148AF8  4E 80 00 21 */	blrl 
.L_8014BB9C:
/* 8014BB9C 00148AFC  7C 03 B8 40 */	cmplw r3, r23
/* 8014BBA0 00148B00  3A C3 00 00 */	addi r22, r3, 0
/* 8014BBA4 00148B04  41 82 00 AC */	beq .L_8014BC50
/* 8014BBA8 00148B08  D3 E1 00 6C */	stfs f31, 0x6c(r1)
/* 8014BBAC 00148B0C  7F 84 E3 78 */	mr r4, r28
/* 8014BBB0 00148B10  38 BD 00 00 */	addi r5, r29, 0
/* 8014BBB4 00148B14  D3 E1 00 68 */	stfs f31, 0x68(r1)
/* 8014BBB8 00148B18  38 DE 00 00 */	addi r6, r30, 0
/* 8014BBBC 00148B1C  38 61 00 64 */	addi r3, r1, 0x64
/* 8014BBC0 00148B20  D3 E1 00 64 */	stfs f31, 0x64(r1)
/* 8014BBC4 00148B24  C0 36 00 9C */	lfs f1, 0x9c(r22)
/* 8014BBC8 00148B28  C0 1F 00 08 */	lfs f0, 8(r31)
/* 8014BBCC 00148B2C  EC 01 00 28 */	fsubs f0, f1, f0
/* 8014BBD0 00148B30  D0 01 00 50 */	stfs f0, 0x50(r1)
/* 8014BBD4 00148B34  C0 36 00 98 */	lfs f1, 0x98(r22)
/* 8014BBD8 00148B38  C0 1F 00 04 */	lfs f0, 4(r31)
/* 8014BBDC 00148B3C  EC 01 00 28 */	fsubs f0, f1, f0
/* 8014BBE0 00148B40  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 8014BBE4 00148B44  C0 36 00 94 */	lfs f1, 0x94(r22)
/* 8014BBE8 00148B48  C0 1F 00 00 */	lfs f0, 0(r31)
/* 8014BBEC 00148B4C  EC 01 00 28 */	fsubs f0, f1, f0
/* 8014BBF0 00148B50  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 8014BBF4 00148B54  4B F1 1A 99 */	bl set__8Vector3fFRCfRCfRCf
/* 8014BBF8 00148B58  C0 21 00 64 */	lfs f1, 0x64(r1)
/* 8014BBFC 00148B5C  C0 01 00 68 */	lfs f0, 0x68(r1)
/* 8014BC00 00148B60  EC 21 00 72 */	fmuls f1, f1, f1
/* 8014BC04 00148B64  C0 41 00 6C */	lfs f2, 0x6c(r1)
/* 8014BC08 00148B68  EC 00 00 32 */	fmuls f0, f0, f0
/* 8014BC0C 00148B6C  EC 42 00 B2 */	fmuls f2, f2, f2
/* 8014BC10 00148B70  EC 01 00 2A */	fadds f0, f1, f0
/* 8014BC14 00148B74  EC 22 00 2A */	fadds f1, f2, f0
/* 8014BC18 00148B78  4B EC 20 29 */	bl sqrtf__3stdFf
/* 8014BC1C 00148B7C  80 77 02 C4 */	lwz r3, 0x2c4(r23)
/* 8014BC20 00148B80  80 63 00 84 */	lwz r3, 0x84(r3)
/* 8014BC24 00148B84  80 63 00 04 */	lwz r3, 4(r3)
/* 8014BC28 00148B88  80 63 00 00 */	lwz r3, 0(r3)
/* 8014BC2C 00148B8C  C0 03 00 68 */	lfs f0, 0x68(r3)
/* 8014BC30 00148B90  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8014BC34 00148B94  4C 40 13 82 */	cror 2, 0, 2
/* 8014BC38 00148B98  40 82 00 18 */	bne .L_8014BC50
/* 8014BC3C 00148B9C  93 01 00 7C */	stw r24, 0x7c(r1)
/* 8014BC40 00148BA0  38 76 00 00 */	addi r3, r22, 0
/* 8014BC44 00148BA4  38 9B 00 00 */	addi r4, r27, 0
/* 8014BC48 00148BA8  92 E1 00 80 */	stw r23, 0x80(r1)
/* 8014BC4C 00148BAC  48 00 00 95 */	bl receiveMessage__5NTekiFR11TekiMessage
.L_8014BC50:
/* 8014BC50 00148BB0  7F 43 D3 78 */	mr r3, r26
/* 8014BC54 00148BB4  81 9A 00 00 */	lwz r12, 0(r26)
/* 8014BC58 00148BB8  7F 24 CB 78 */	mr r4, r25
/* 8014BC5C 00148BBC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8014BC60 00148BC0  7D 88 03 A6 */	mtlr r12
/* 8014BC64 00148BC4  4E 80 00 21 */	blrl 
/* 8014BC68 00148BC8  7C 79 1B 78 */	mr r25, r3
.L_8014BC6C:
/* 8014BC6C 00148BCC  7F 43 D3 78 */	mr r3, r26
/* 8014BC70 00148BD0  81 9A 00 00 */	lwz r12, 0(r26)
/* 8014BC74 00148BD4  7F 24 CB 78 */	mr r4, r25
/* 8014BC78 00148BD8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8014BC7C 00148BDC  7D 88 03 A6 */	mtlr r12
/* 8014BC80 00148BE0  4E 80 00 21 */	blrl 
/* 8014BC84 00148BE4  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8014BC88 00148BE8  41 82 00 0C */	beq .L_8014BC94
/* 8014BC8C 00148BEC  38 00 00 01 */	li r0, 1
/* 8014BC90 00148BF0  48 00 00 30 */	b .L_8014BCC0
.L_8014BC94:
/* 8014BC94 00148BF4  7F 43 D3 78 */	mr r3, r26
/* 8014BC98 00148BF8  81 9A 00 00 */	lwz r12, 0(r26)
/* 8014BC9C 00148BFC  7F 24 CB 78 */	mr r4, r25
/* 8014BCA0 00148C00  81 8C 00 08 */	lwz r12, 8(r12)
/* 8014BCA4 00148C04  7D 88 03 A6 */	mtlr r12
/* 8014BCA8 00148C08  4E 80 00 21 */	blrl 
/* 8014BCAC 00148C0C  28 03 00 00 */	cmplwi r3, 0
/* 8014BCB0 00148C10  40 82 00 0C */	bne .L_8014BCBC
/* 8014BCB4 00148C14  38 00 00 01 */	li r0, 1
/* 8014BCB8 00148C18  48 00 00 08 */	b .L_8014BCC0
.L_8014BCBC:
/* 8014BCBC 00148C1C  38 00 00 00 */	li r0, 0
.L_8014BCC0:
/* 8014BCC0 00148C20  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8014BCC4 00148C24  41 82 FE 9C */	beq .L_8014BB60
/* 8014BCC8 00148C28  BA C1 00 98 */	lmw r22, 0x98(r1)
/* 8014BCCC 00148C2C  80 01 00 CC */	lwz r0, 0xcc(r1)
/* 8014BCD0 00148C30  CB E1 00 C0 */	lfd f31, 0xc0(r1)
/* 8014BCD4 00148C34  38 21 00 C8 */	addi r1, r1, 0xc8
/* 8014BCD8 00148C38  7C 08 03 A6 */	mtlr r0
/* 8014BCDC 00148C3C  4E 80 00 20 */	blr 
.endfn sendMessage__5NTekiFi

.fn receiveMessage__5NTekiFR11TekiMessage, global
/* 8014BCE0 00148C40  7C 08 02 A6 */	mflr r0
/* 8014BCE4 00148C44  90 01 00 04 */	stw r0, 4(r1)
/* 8014BCE8 00148C48  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8014BCEC 00148C4C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8014BCF0 00148C50  7C 7F 1B 78 */	mr r31, r3
/* 8014BCF4 00148C54  38 BF 00 00 */	addi r5, r31, 0
/* 8014BCF8 00148C58  80 C4 00 04 */	lwz r6, 4(r4)
/* 8014BCFC 00148C5C  38 61 00 10 */	addi r3, r1, 0x10
/* 8014BD00 00148C60  38 80 00 04 */	li r4, 4
/* 8014BD04 00148C64  4B FF E6 C9 */	bl __ct__9TekiEventFiP4TekiP8Creature
/* 8014BD08 00148C68  81 9F 00 00 */	lwz r12, 0(r31)
/* 8014BD0C 00148C6C  38 83 00 00 */	addi r4, r3, 0
/* 8014BD10 00148C70  38 7F 00 00 */	addi r3, r31, 0
/* 8014BD14 00148C74  81 8C 01 A0 */	lwz r12, 0x1a0(r12)
/* 8014BD18 00148C78  7D 88 03 A6 */	mtlr r12
/* 8014BD1C 00148C7C  4E 80 00 21 */	blrl 
/* 8014BD20 00148C80  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8014BD24 00148C84  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8014BD28 00148C88  38 21 00 28 */	addi r1, r1, 0x28
/* 8014BD2C 00148C8C  7C 08 03 A6 */	mtlr r0
/* 8014BD30 00148C90  4E 80 00 20 */	blr 
.endfn receiveMessage__5NTekiFR11TekiMessage

.fn "@1132@4@animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent", weak
/* 8014BD34 00148C94  39 60 00 04 */	li r11, 4
/* 8014BD38 00148C98  7D 63 58 2E */	lwzx r11, r3, r11
/* 8014BD3C 00148C9C  7C 63 5A 14 */	add r3, r3, r11
/* 8014BD40 00148CA0  38 63 FB 94 */	addi r3, r3, -1132
/* 8014BD44 00148CA4  4B FF 94 9C */	b animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent
.endfn "@1132@4@animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802CDD20, local
	.asciz "tekinteki.cpp"
.endobj lbl_802CDD20
.balign 4
.obj lbl_802CDD30, local
	.asciz "tekinakata"
.endobj lbl_802CDD30
.balign 4
.obj lbl_802CDD3C, local
	.asciz "PelletView"
.endobj lbl_802CDD3C
.balign 4
.obj lbl_802CDD48, local
	.asciz "PaniAnimKeyListener"
.endobj lbl_802CDD48
.balign 4
.obj lbl_802CDD5C, local
	.asciz "EventTalker"
.endobj lbl_802CDD5C
.balign 4
.obj lbl_802CDD68, local
	.asciz "RefCountable"
.endobj lbl_802CDD68
.balign 4
.obj lbl_802CDD78, local
	.asciz "Creature"
.endobj lbl_802CDD78
.balign 4
.obj lbl_802CDD84, local
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
.endobj lbl_802CDD84
.obj lbl_802CDD98, local
	.4byte __RTTI__10PelletView
	.4byte 0x2b8
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x454
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
.endobj lbl_802CDD98
.obj lbl_802CDDC4, local
	.4byte __RTTI__10PelletView
	.4byte 0x2b8
	.4byte __RTTI__19PaniAnimKeyListener
	.4byte 0x46c
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte __RTTI__5BTeki
	.4byte 0
	.4byte 0
.endobj lbl_802CDDC4
.obj __vt__5NTeki, weak
	.4byte __RTTI__5NTeki
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__5BTekiFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8CreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__5BTekiFi
	.4byte getiMass__5BTekiFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__5BTekiFP11CreatureInf
	.4byte doRestore__5BTekiFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__5BTekiFv
	.4byte isVisible__5BTekiFv
	.4byte isOrganic__5BTekiFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__5BTekiFv
	.4byte isAlive__5BTekiFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__5BTekiFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__5BTekiFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__5BTekiFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__5BTekiFR9CollEvent
	.4byte bounceCallback__5BTekiFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__5BTekiFR5PlaneP13DynCollObject
	.4byte offwallCallback__8CreatureFP13DynCollObject
	.4byte stickCallback__8CreatureFP8Creature
	.4byte offstickCallback__8CreatureFP8Creature
	.4byte stickToCallback__8CreatureFP8Creature
	.4byte dump__5BTekiFv
	.4byte startWaterEffect__8CreatureFv
	.4byte finishWaterEffect__8CreatureFv
	.4byte isRopable__8CreatureFv
	.4byte mayIstick__8CreatureFv
	.4byte getFormationPri__8CreatureFv
	.4byte update__5BTekiFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__5BTekiFR8Graphics
	.4byte refresh2d__5BTekiFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__5BTekiFv
	.4byte doAnimation__5BTekiFv
	.4byte doKill__5BTekiFv
	.4byte exitCourse__5BTekiFv
	.4byte __RTTI__5NTeki
	.4byte 0xfffffd48
	.4byte viewInit__10PelletViewFv
	.4byte "@696@viewKill__5BTekiFv"
	.4byte "@696@viewDraw__5BTekiFR8GraphicsR8Matrix4f"
	.4byte "@696@viewStartTrembleMotion__5BTekiFf"
	.4byte viewStartExplodeMotion__10PelletViewFf
	.4byte "@696@viewSetMotionSpeed__5BTekiFf"
	.4byte "@696@viewFinishMotion__5BTekiFv"
	.4byte "@696@viewDoAnimation__5BTekiFv"
	.4byte "@696@viewGetBottomRadius__5BTekiFv"
	.4byte "@696@viewGetHeight__5BTekiFv"
	.4byte "@696@viewGetScale__5BTekiFv"
	.4byte viewStartTrembleMotion__5BTekiFf
	.4byte viewSetMotionSpeed__5BTekiFf
	.4byte viewDoAnimation__5BTekiFv
	.4byte viewFinishMotion__5BTekiFv
	.4byte viewDraw__5BTekiFR8GraphicsR8Matrix4f
	.4byte viewKill__5BTekiFv
	.4byte viewGetScale__5BTekiFv
	.4byte viewGetBottomRadius__5BTekiFv
	.4byte viewGetHeight__5BTekiFv
	.4byte init__5BTekiFi
	.4byte reset__5BTekiFv
	.4byte startMotion__5BTekiFi
	.4byte die__5BTekiFv
	.4byte updateTimers__5BTekiFv
	.4byte gravitate__5BTekiFf
	.4byte animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent
	.4byte getTekiCollisionSize__5BTekiFv
	.4byte makeDamaged__5BTekiFv
	.4byte startDamageMotion__5BTekiFff
	.4byte generateTeki__5BTekiFi
	.4byte spawnTeki__5BTekiFi
	.4byte shootBall__5BTekiFR8Creature
	.4byte eventPerformed__5BTekiFR9TekiEvent
	.4byte interact__5BTekiFR18TekiInteractionKey
	.4byte interactDefault__5BTekiFR18TekiInteractionKey
	.4byte drawDefault__5BTekiFR8Graphics
	.4byte drawTekiShape__5BTekiFR8Graphics
	.4byte drawTekiDebugInfo__5BTekiFR8Graphics
	.4byte drawTekiDebugInfoDefault__5BTekiFR8Graphics
	.4byte playTableSound__5BTekiFi
	.4byte playSound__5BTekiFi
	.4byte stopSound__5BTekiFi
	.4byte createTekiEffect__5BTekiFi
	.4byte setTekiOption__5BTekiFi
	.4byte clearTekiOption__5BTekiFi
	.4byte setTekiOptions__5BTekiFi
	.4byte clearTekiOptions__5BTekiFv
	.4byte setAnimationKeyOption__5BTekiFi
	.4byte clearAnimationKeyOption__5BTekiFi
	.4byte setAnimationKeyOptions__5BTekiFi
	.4byte clearAnimationKeyOptions__5BTekiFv
	.4byte dieSoon__5BTekiFv
	.4byte becomeCorpse__5BTekiFv
	.4byte __RTTI__5NTeki
	.4byte 0xfffffb94
	.4byte "@1132@4@animationKeyUpdated__5BTekiFR16PaniAnimKeyEvent"
.endobj __vt__5NTeki
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E46B0, local
	.asciz "NTeki"
.endobj lbl_803E46B0
.balign 4
.obj __RTTI__10PelletView, local
	.4byte lbl_802CDD3C
	.4byte 0
.endobj __RTTI__10PelletView
.obj __RTTI__19PaniAnimKeyListener, local
	.4byte lbl_802CDD48
	.4byte 0
.endobj __RTTI__19PaniAnimKeyListener
.obj __RTTI__11EventTalker, local
	.4byte lbl_802CDD5C
	.4byte 0
.endobj __RTTI__11EventTalker
.obj __RTTI__12RefCountable, local
	.4byte lbl_802CDD68
	.4byte 0
.endobj __RTTI__12RefCountable
.obj __RTTI__8Creature, local
	.4byte lbl_802CDD78
	.4byte lbl_802CDD84
.endobj __RTTI__8Creature
.balign 4
.obj lbl_803E46E0, local
	.asciz "BTeki"
.endobj lbl_803E46E0
.balign 4
.obj __RTTI__5BTeki, local
	.4byte lbl_803E46E0
	.4byte lbl_802CDD98
.endobj __RTTI__5BTeki
.obj __RTTI__5NTeki, local
	.4byte lbl_803E46B0
	.4byte lbl_802CDDC4
.endobj __RTTI__5NTeki

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA9A0, local
	.float 0.0
.endobj lbl_803EA9A0
