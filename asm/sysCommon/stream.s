.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn readInt__6StreamFv, global
/* 800250B0 00022010  7C 08 02 A6 */	mflr r0
/* 800250B4 00022014  38 A0 00 04 */	li r5, 4
/* 800250B8 00022018  90 01 00 04 */	stw r0, 4(r1)
/* 800250BC 0002201C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800250C0 00022020  81 83 00 04 */	lwz r12, 4(r3)
/* 800250C4 00022024  38 81 00 0C */	addi r4, r1, 0xc
/* 800250C8 00022028  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 800250CC 0002202C  7D 88 03 A6 */	mtlr r12
/* 800250D0 00022030  4E 80 00 21 */	blrl 
/* 800250D4 00022034  80 61 00 0C */	lwz r3, 0xc(r1)
/* 800250D8 00022038  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800250DC 0002203C  38 21 00 10 */	addi r1, r1, 0x10
/* 800250E0 00022040  7C 08 03 A6 */	mtlr r0
/* 800250E4 00022044  4E 80 00 20 */	blr 
.endfn readInt__6StreamFv

.fn readByte__6StreamFv, global
/* 800250E8 00022048  7C 08 02 A6 */	mflr r0
/* 800250EC 0002204C  38 A0 00 01 */	li r5, 1
/* 800250F0 00022050  90 01 00 04 */	stw r0, 4(r1)
/* 800250F4 00022054  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800250F8 00022058  81 83 00 04 */	lwz r12, 4(r3)
/* 800250FC 0002205C  38 81 00 0C */	addi r4, r1, 0xc
/* 80025100 00022060  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 80025104 00022064  7D 88 03 A6 */	mtlr r12
/* 80025108 00022068  4E 80 00 21 */	blrl 
/* 8002510C 0002206C  88 61 00 0C */	lbz r3, 0xc(r1)
/* 80025110 00022070  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80025114 00022074  38 21 00 10 */	addi r1, r1, 0x10
/* 80025118 00022078  7C 08 03 A6 */	mtlr r0
/* 8002511C 0002207C  4E 80 00 20 */	blr 
.endfn readByte__6StreamFv

.fn readShort__6StreamFv, global
/* 80025120 00022080  7C 08 02 A6 */	mflr r0
/* 80025124 00022084  38 A0 00 02 */	li r5, 2
/* 80025128 00022088  90 01 00 04 */	stw r0, 4(r1)
/* 8002512C 0002208C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80025130 00022090  81 83 00 04 */	lwz r12, 4(r3)
/* 80025134 00022094  38 81 00 0C */	addi r4, r1, 0xc
/* 80025138 00022098  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 8002513C 0002209C  7D 88 03 A6 */	mtlr r12
/* 80025140 000220A0  4E 80 00 21 */	blrl 
/* 80025144 000220A4  A8 61 00 0C */	lha r3, 0xc(r1)
/* 80025148 000220A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8002514C 000220AC  38 21 00 10 */	addi r1, r1, 0x10
/* 80025150 000220B0  7C 08 03 A6 */	mtlr r0
/* 80025154 000220B4  4E 80 00 20 */	blr 
.endfn readShort__6StreamFv

.fn readFloat__6StreamFv, global
/* 80025158 000220B8  7C 08 02 A6 */	mflr r0
/* 8002515C 000220BC  38 A0 00 04 */	li r5, 4
/* 80025160 000220C0  90 01 00 04 */	stw r0, 4(r1)
/* 80025164 000220C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80025168 000220C8  81 83 00 04 */	lwz r12, 4(r3)
/* 8002516C 000220CC  38 81 00 0C */	addi r4, r1, 0xc
/* 80025170 000220D0  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 80025174 000220D4  7D 88 03 A6 */	mtlr r12
/* 80025178 000220D8  4E 80 00 21 */	blrl 
/* 8002517C 000220DC  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 80025180 000220E0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80025184 000220E4  38 21 00 10 */	addi r1, r1, 0x10
/* 80025188 000220E8  7C 08 03 A6 */	mtlr r0
/* 8002518C 000220EC  4E 80 00 20 */	blr 
.endfn readFloat__6StreamFv

.fn readString__6StreamFv, global
/* 80025190 000220F0  7C 08 02 A6 */	mflr r0
/* 80025194 000220F4  90 01 00 04 */	stw r0, 4(r1)
/* 80025198 000220F8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8002519C 000220FC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800251A0 00022100  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800251A4 00022104  7C 7E 1B 78 */	mr r30, r3
/* 800251A8 00022108  81 9E 00 04 */	lwz r12, 4(r30)
/* 800251AC 0002210C  81 8C 00 08 */	lwz r12, 8(r12)
/* 800251B0 00022110  7D 88 03 A6 */	mtlr r12
/* 800251B4 00022114  4E 80 00 21 */	blrl 
/* 800251B8 00022118  3B E3 00 00 */	addi r31, r3, 0
/* 800251BC 0002211C  38 7F 00 01 */	addi r3, r31, 1
/* 800251C0 00022120  48 02 B9 25 */	bl __nwa__FUl
/* 800251C4 00022124  38 03 00 00 */	addi r0, r3, 0
/* 800251C8 00022128  38 7E 00 00 */	addi r3, r30, 0
/* 800251CC 0002212C  81 9E 00 04 */	lwz r12, 4(r30)
/* 800251D0 00022130  7C 1E 03 78 */	mr r30, r0
/* 800251D4 00022134  38 9E 00 00 */	addi r4, r30, 0
/* 800251D8 00022138  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 800251DC 0002213C  38 BF 00 00 */	addi r5, r31, 0
/* 800251E0 00022140  7D 88 03 A6 */	mtlr r12
/* 800251E4 00022144  4E 80 00 21 */	blrl 
/* 800251E8 00022148  38 00 00 00 */	li r0, 0
/* 800251EC 0002214C  7C 1E F9 AE */	stbx r0, r30, r31
/* 800251F0 00022150  7F C3 F3 78 */	mr r3, r30
/* 800251F4 00022154  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800251F8 00022158  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800251FC 0002215C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80025200 00022160  38 21 00 18 */	addi r1, r1, 0x18
/* 80025204 00022164  7C 08 03 A6 */	mtlr r0
/* 80025208 00022168  4E 80 00 20 */	blr 
.endfn readString__6StreamFv

.fn readString__6StreamFPci, global
/* 8002520C 0002216C  7C 08 02 A6 */	mflr r0
/* 80025210 00022170  90 01 00 04 */	stw r0, 4(r1)
/* 80025214 00022174  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80025218 00022178  90 81 00 18 */	stw r4, 0x18(r1)
/* 8002521C 0002217C  38 81 00 14 */	addi r4, r1, 0x14
/* 80025220 00022180  90 A1 00 14 */	stw r5, 0x14(r1)
/* 80025224 00022184  81 83 00 04 */	lwz r12, 4(r3)
/* 80025228 00022188  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8002522C 0002218C  7D 88 03 A6 */	mtlr r12
/* 80025230 00022190  4E 80 00 21 */	blrl 
/* 80025234 00022194  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80025238 00022198  38 21 00 20 */	addi r1, r1, 0x20
/* 8002523C 0002219C  7C 08 03 A6 */	mtlr r0
/* 80025240 000221A0  4E 80 00 20 */	blr 
.endfn readString__6StreamFPci

.fn readString__6StreamFR6String, global
/* 80025244 000221A4  7C 08 02 A6 */	mflr r0
/* 80025248 000221A8  90 01 00 04 */	stw r0, 4(r1)
/* 8002524C 000221AC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80025250 000221B0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80025254 000221B4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80025258 000221B8  7C 9E 23 78 */	mr r30, r4
/* 8002525C 000221BC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80025260 000221C0  7C 7D 1B 78 */	mr r29, r3
/* 80025264 000221C4  81 9D 00 04 */	lwz r12, 4(r29)
/* 80025268 000221C8  81 8C 00 08 */	lwz r12, 8(r12)
/* 8002526C 000221CC  7D 88 03 A6 */	mtlr r12
/* 80025270 000221D0  4E 80 00 21 */	blrl 
/* 80025274 000221D4  80 1E 00 00 */	lwz r0, 0(r30)
/* 80025278 000221D8  3B E3 00 00 */	addi r31, r3, 0
/* 8002527C 000221DC  7C 00 F8 00 */	cmpw r0, r31
/* 80025280 000221E0  40 80 00 24 */	bge .L_800252A4
/* 80025284 000221E4  2C 1F 00 00 */	cmpwi r31, 0
/* 80025288 000221E8  41 82 00 10 */	beq .L_80025298
/* 8002528C 000221EC  38 7F 00 01 */	addi r3, r31, 1
/* 80025290 000221F0  48 02 B8 55 */	bl __nwa__FUl
/* 80025294 000221F4  48 00 00 08 */	b .L_8002529C
.L_80025298:
/* 80025298 000221F8  38 60 00 00 */	li r3, 0
.L_8002529C:
/* 8002529C 000221FC  90 7E 00 04 */	stw r3, 4(r30)
/* 800252A0 00022200  93 FE 00 00 */	stw r31, 0(r30)
.L_800252A4:
/* 800252A4 00022204  7F A3 EB 78 */	mr r3, r29
/* 800252A8 00022208  80 9E 00 04 */	lwz r4, 4(r30)
/* 800252AC 0002220C  81 9D 00 04 */	lwz r12, 4(r29)
/* 800252B0 00022210  7F E5 FB 78 */	mr r5, r31
/* 800252B4 00022214  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 800252B8 00022218  7D 88 03 A6 */	mtlr r12
/* 800252BC 0002221C  4E 80 00 21 */	blrl 
/* 800252C0 00022220  80 7E 00 04 */	lwz r3, 4(r30)
/* 800252C4 00022224  38 00 00 00 */	li r0, 0
/* 800252C8 00022228  7C 03 F9 AE */	stbx r0, r3, r31
/* 800252CC 0002222C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800252D0 00022230  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800252D4 00022234  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800252D8 00022238  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800252DC 0002223C  38 21 00 20 */	addi r1, r1, 0x20
/* 800252E0 00022240  7C 08 03 A6 */	mtlr r0
/* 800252E4 00022244  4E 80 00 20 */	blr 
.endfn readString__6StreamFR6String

.fn writeInt__6StreamFi, global
/* 800252E8 00022248  7C 08 02 A6 */	mflr r0
/* 800252EC 0002224C  38 A0 00 04 */	li r5, 4
/* 800252F0 00022250  90 01 00 04 */	stw r0, 4(r1)
/* 800252F4 00022254  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800252F8 00022258  90 81 00 10 */	stw r4, 0x10(r1)
/* 800252FC 0002225C  38 81 00 10 */	addi r4, r1, 0x10
/* 80025300 00022260  81 83 00 04 */	lwz r12, 4(r3)
/* 80025304 00022264  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80025308 00022268  7D 88 03 A6 */	mtlr r12
/* 8002530C 0002226C  4E 80 00 21 */	blrl 
/* 80025310 00022270  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80025314 00022274  38 21 00 18 */	addi r1, r1, 0x18
/* 80025318 00022278  7C 08 03 A6 */	mtlr r0
/* 8002531C 0002227C  4E 80 00 20 */	blr 
.endfn writeInt__6StreamFi

.fn writeByte__6StreamFUc, global
/* 80025320 00022280  7C 08 02 A6 */	mflr r0
/* 80025324 00022284  38 A0 00 01 */	li r5, 1
/* 80025328 00022288  90 01 00 04 */	stw r0, 4(r1)
/* 8002532C 0002228C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80025330 00022290  98 81 00 0C */	stb r4, 0xc(r1)
/* 80025334 00022294  38 81 00 0C */	addi r4, r1, 0xc
/* 80025338 00022298  81 83 00 04 */	lwz r12, 4(r3)
/* 8002533C 0002229C  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80025340 000222A0  7D 88 03 A6 */	mtlr r12
/* 80025344 000222A4  4E 80 00 21 */	blrl 
/* 80025348 000222A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8002534C 000222AC  38 21 00 10 */	addi r1, r1, 0x10
/* 80025350 000222B0  7C 08 03 A6 */	mtlr r0
/* 80025354 000222B4  4E 80 00 20 */	blr 
.endfn writeByte__6StreamFUc

.fn writeShort__6StreamFs, global
/* 80025358 000222B8  7C 08 02 A6 */	mflr r0
/* 8002535C 000222BC  38 A0 00 02 */	li r5, 2
/* 80025360 000222C0  90 01 00 04 */	stw r0, 4(r1)
/* 80025364 000222C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80025368 000222C8  B0 81 00 0E */	sth r4, 0xe(r1)
/* 8002536C 000222CC  38 81 00 0E */	addi r4, r1, 0xe
/* 80025370 000222D0  81 83 00 04 */	lwz r12, 4(r3)
/* 80025374 000222D4  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80025378 000222D8  7D 88 03 A6 */	mtlr r12
/* 8002537C 000222DC  4E 80 00 21 */	blrl 
/* 80025380 000222E0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80025384 000222E4  38 21 00 10 */	addi r1, r1, 0x10
/* 80025388 000222E8  7C 08 03 A6 */	mtlr r0
/* 8002538C 000222EC  4E 80 00 20 */	blr 
.endfn writeShort__6StreamFs

.fn writeFloat__6StreamFf, global
/* 80025390 000222F0  7C 08 02 A6 */	mflr r0
/* 80025394 000222F4  38 A0 00 04 */	li r5, 4
/* 80025398 000222F8  90 01 00 04 */	stw r0, 4(r1)
/* 8002539C 000222FC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800253A0 00022300  D0 21 00 10 */	stfs f1, 0x10(r1)
/* 800253A4 00022304  38 81 00 10 */	addi r4, r1, 0x10
/* 800253A8 00022308  81 83 00 04 */	lwz r12, 4(r3)
/* 800253AC 0002230C  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 800253B0 00022310  7D 88 03 A6 */	mtlr r12
/* 800253B4 00022314  4E 80 00 21 */	blrl 
/* 800253B8 00022318  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800253BC 0002231C  38 21 00 18 */	addi r1, r1, 0x18
/* 800253C0 00022320  7C 08 03 A6 */	mtlr r0
/* 800253C4 00022324  4E 80 00 20 */	blr 
.endfn writeFloat__6StreamFf

.fn writeString__6StreamFPc, global
/* 800253C8 00022328  7C 08 02 A6 */	mflr r0
/* 800253CC 0002232C  90 01 00 04 */	stw r0, 4(r1)
/* 800253D0 00022330  38 00 00 00 */	li r0, 0
/* 800253D4 00022334  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800253D8 00022338  90 81 00 14 */	stw r4, 0x14(r1)
/* 800253DC 0002233C  38 81 00 10 */	addi r4, r1, 0x10
/* 800253E0 00022340  90 01 00 10 */	stw r0, 0x10(r1)
/* 800253E4 00022344  81 83 00 04 */	lwz r12, 4(r3)
/* 800253E8 00022348  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 800253EC 0002234C  7D 88 03 A6 */	mtlr r12
/* 800253F0 00022350  4E 80 00 21 */	blrl 
/* 800253F4 00022354  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800253F8 00022358  38 21 00 18 */	addi r1, r1, 0x18
/* 800253FC 0002235C  7C 08 03 A6 */	mtlr r0
/* 80025400 00022360  4E 80 00 20 */	blr 
.endfn writeString__6StreamFPc

.fn writeString__6StreamFR6String, global
/* 80025404 00022364  7C 08 02 A6 */	mflr r0
/* 80025408 00022368  90 01 00 04 */	stw r0, 4(r1)
/* 8002540C 0002236C  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80025410 00022370  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80025414 00022374  93 C1 00 20 */	stw r30, 0x20(r1)
/* 80025418 00022378  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 8002541C 0002237C  3B A4 00 00 */	addi r29, r4, 0
/* 80025420 00022380  93 81 00 18 */	stw r28, 0x18(r1)
/* 80025424 00022384  3B 83 00 00 */	addi r28, r3, 0
/* 80025428 00022388  38 7D 00 00 */	addi r3, r29, 0
/* 8002542C 0002238C  48 00 04 C5 */	bl getLength__6StringFv
/* 80025430 00022390  38 03 00 03 */	addi r0, r3, 3
/* 80025434 00022394  38 7C 00 00 */	addi r3, r28, 0
/* 80025438 00022398  81 9C 00 04 */	lwz r12, 4(r28)
/* 8002543C 0002239C  54 1F 00 3A */	rlwinm r31, r0, 0, 0, 0x1d
/* 80025440 000223A0  38 9F 00 00 */	addi r4, r31, 0
/* 80025444 000223A4  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80025448 000223A8  7D 88 03 A6 */	mtlr r12
/* 8002544C 000223AC  4E 80 00 21 */	blrl 
/* 80025450 000223B0  7F A3 EB 78 */	mr r3, r29
/* 80025454 000223B4  48 00 04 9D */	bl getLength__6StringFv
/* 80025458 000223B8  81 9C 00 04 */	lwz r12, 4(r28)
/* 8002545C 000223BC  7C 65 1B 78 */	mr r5, r3
/* 80025460 000223C0  80 9D 00 04 */	lwz r4, 4(r29)
/* 80025464 000223C4  7F 83 E3 78 */	mr r3, r28
/* 80025468 000223C8  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 8002546C 000223CC  7D 88 03 A6 */	mtlr r12
/* 80025470 000223D0  4E 80 00 21 */	blrl 
/* 80025474 000223D4  38 00 00 00 */	li r0, 0
/* 80025478 000223D8  98 01 00 10 */	stb r0, 0x10(r1)
/* 8002547C 000223DC  3B C0 00 00 */	li r30, 0
/* 80025480 000223E0  48 00 00 24 */	b .L_800254A4
.L_80025484:
/* 80025484 000223E4  7F 83 E3 78 */	mr r3, r28
/* 80025488 000223E8  81 9C 00 04 */	lwz r12, 4(r28)
/* 8002548C 000223EC  38 81 00 10 */	addi r4, r1, 0x10
/* 80025490 000223F0  38 A0 00 01 */	li r5, 1
/* 80025494 000223F4  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80025498 000223F8  7D 88 03 A6 */	mtlr r12
/* 8002549C 000223FC  4E 80 00 21 */	blrl 
/* 800254A0 00022400  3B DE 00 01 */	addi r30, r30, 1
.L_800254A4:
/* 800254A4 00022404  7F A3 EB 78 */	mr r3, r29
/* 800254A8 00022408  48 00 04 49 */	bl getLength__6StringFv
/* 800254AC 0002240C  7C 03 F8 50 */	subf r0, r3, r31
/* 800254B0 00022410  7C 1E 00 00 */	cmpw r30, r0
/* 800254B4 00022414  41 80 FF D0 */	blt .L_80025484
/* 800254B8 00022418  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 800254BC 0002241C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 800254C0 00022420  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 800254C4 00022424  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 800254C8 00022428  83 81 00 18 */	lwz r28, 0x18(r1)
/* 800254CC 0002242C  38 21 00 28 */	addi r1, r1, 0x28
/* 800254D0 00022430  7C 08 03 A6 */	mtlr r0
/* 800254D4 00022434  4E 80 00 20 */	blr 
.endfn writeString__6StreamFR6String

.fn read__6StreamFPvi, global
/* 800254D8 00022438  4E 80 00 20 */	blr 
.endfn read__6StreamFPvi

.fn write__6StreamFPvi, global
/* 800254DC 0002243C  4E 80 00 20 */	blr 
.endfn write__6StreamFPvi

.fn getPending__6StreamFv, global
/* 800254E0 00022440  38 60 00 00 */	li r3, 0
/* 800254E4 00022444  4E 80 00 20 */	blr 
.endfn getPending__6StreamFv

.fn getAvailable__6StreamFv, global
/* 800254E8 00022448  38 60 00 00 */	li r3, 0
/* 800254EC 0002244C  4E 80 00 20 */	blr 
.endfn getAvailable__6StreamFv

.fn close__6StreamFv, global
/* 800254F0 00022450  4E 80 00 20 */	blr 
.endfn close__6StreamFv

.fn setPosition__18RandomAccessStreamFi, weak
/* 800254F4 00022454  4E 80 00 20 */	blr 
.endfn setPosition__18RandomAccessStreamFi

.fn getClosing__6StreamFv, weak
/* 800254F8 00022458  38 60 00 00 */	li r3, 0
/* 800254FC 0002245C  4E 80 00 20 */	blr 
.endfn getClosing__6StreamFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj __vt__6Stream, global
	.4byte __RTTI__6Stream
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
	.4byte read__6StreamFPvi
	.4byte write__6StreamFPvi
	.4byte getPending__6StreamFv
	.4byte getAvailable__6StreamFv
	.4byte close__6StreamFv
	.4byte getClosing__6StreamFv
	.4byte flush__6StreamFv
.endobj __vt__6Stream

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DCEB0, local
	.asciz "Stream"
.endobj lbl_803DCEB0
.balign 4
.obj __RTTI__6Stream, local
	.4byte lbl_803DCEB0
	.4byte 0
.endobj __RTTI__6Stream
