.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn makeObjectMapObject__Fv, local
/* 8005D0E8 0005A048  7C 08 02 A6 */	mflr r0
/* 8005D0EC 0005A04C  38 60 00 1C */	li r3, 0x1c
/* 8005D0F0 0005A050  90 01 00 04 */	stw r0, 4(r1)
/* 8005D0F4 0005A054  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8005D0F8 0005A058  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8005D0FC 0005A05C  4B FE 9F 09 */	bl alloc__6SystemFUl
/* 8005D100 0005A060  3B E3 00 00 */	addi r31, r3, 0
/* 8005D104 0005A064  7F E3 FB 79 */	or. r3, r31, r31
/* 8005D108 0005A068  41 82 00 08 */	beq .L_8005D110
/* 8005D10C 0005A06C  48 00 00 1D */	bl __ct__18GenObjectMapObjectFv
.L_8005D110:
/* 8005D110 0005A070  7F E3 FB 78 */	mr r3, r31
/* 8005D114 0005A074  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8005D118 0005A078  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8005D11C 0005A07C  38 21 00 10 */	addi r1, r1, 0x10
/* 8005D120 0005A080  7C 08 03 A6 */	mtlr r0
/* 8005D124 0005A084  4E 80 00 20 */	blr 
.endfn makeObjectMapObject__Fv

.fn __ct__18GenObjectMapObjectFv, global
/* 8005D128 0005A088  7C 08 02 A6 */	mflr r0
/* 8005D12C 0005A08C  3C 80 80 2B */	lis r4, lbl_802A8328@ha
/* 8005D130 0005A090  90 01 00 04 */	stw r0, 4(r1)
/* 8005D134 0005A094  3C A0 80 2B */	lis r5, lbl_802A831C@ha
/* 8005D138 0005A098  38 C4 83 28 */	addi r6, r4, lbl_802A8328@l
/* 8005D13C 0005A09C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8005D140 0005A0A0  3C 80 6D 6F */	lis r4, 0x6D6F626A@ha
/* 8005D144 0005A0A4  38 A5 83 1C */	addi r5, r5, lbl_802A831C@l
/* 8005D148 0005A0A8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8005D14C 0005A0AC  3B E3 00 00 */	addi r31, r3, 0
/* 8005D150 0005A0B0  38 84 62 6A */	addi r4, r4, 0x6D6F626A@l
/* 8005D154 0005A0B4  48 07 DB 61 */	bl __ct__7GenBaseFUlPcPc
/* 8005D158 0005A0B8  3C 60 80 2C */	lis r3, __vt__9GenObject@ha
/* 8005D15C 0005A0BC  38 03 AB 70 */	addi r0, r3, __vt__9GenObject@l
/* 8005D160 0005A0C0  3C 60 80 2B */	lis r3, __vt__18GenObjectMapObject@ha
/* 8005D164 0005A0C4  90 1F 00 04 */	stw r0, 4(r31)
/* 8005D168 0005A0C8  38 03 85 04 */	addi r0, r3, __vt__18GenObjectMapObject@l
/* 8005D16C 0005A0CC  90 1F 00 04 */	stw r0, 4(r31)
/* 8005D170 0005A0D0  38 00 00 00 */	li r0, 0
/* 8005D174 0005A0D4  38 7F 00 00 */	addi r3, r31, 0
/* 8005D178 0005A0D8  90 1F 00 18 */	stw r0, 0x18(r31)
/* 8005D17C 0005A0DC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8005D180 0005A0E0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8005D184 0005A0E4  38 21 00 18 */	addi r1, r1, 0x18
/* 8005D188 0005A0E8  7C 08 03 A6 */	mtlr r0
/* 8005D18C 0005A0EC  4E 80 00 20 */	blr 
.endfn __ct__18GenObjectMapObjectFv

.fn initialise__18GenObjectMapObjectFP6MapMgr, global
/* 8005D190 0005A0F0  90 6D 2E B0 */	stw r3, mapMgr__18GenObjectMapObject@sda21(r13)
/* 8005D194 0005A0F4  80 ED 30 74 */	lwz r7, factory__16GenObjectFactory@sda21(r13)
/* 8005D198 0005A0F8  80 A7 00 00 */	lwz r5, 0(r7)
/* 8005D19C 0005A0FC  80 07 00 04 */	lwz r0, 4(r7)
/* 8005D1A0 0005A100  7C 05 00 00 */	cmpw r5, r0
/* 8005D1A4 0005A104  4C 80 00 20 */	bgelr 
/* 8005D1A8 0005A108  3C 80 6D 6F */	lis r4, 0x6D6F626A@ha
/* 8005D1AC 0005A10C  80 67 00 08 */	lwz r3, 8(r7)
/* 8005D1B0 0005A110  38 84 62 6A */	addi r4, r4, 0x6D6F626A@l
/* 8005D1B4 0005A114  54 A0 20 36 */	slwi r0, r5, 4
/* 8005D1B8 0005A118  7C 83 01 2E */	stwx r4, r3, r0
/* 8005D1BC 0005A11C  3C C0 80 06 */	lis r6, makeObjectMapObject__Fv@ha
/* 8005D1C0 0005A120  3C 80 80 2B */	lis r4, lbl_802A8328@ha
/* 8005D1C4 0005A124  80 07 00 00 */	lwz r0, 0(r7)
/* 8005D1C8 0005A128  3C 60 76 30 */	lis r3, 0x76302E30@ha
/* 8005D1CC 0005A12C  80 A7 00 08 */	lwz r5, 8(r7)
/* 8005D1D0 0005A130  38 C6 D0 E8 */	addi r6, r6, makeObjectMapObject__Fv@l
/* 8005D1D4 0005A134  54 00 20 36 */	slwi r0, r0, 4
/* 8005D1D8 0005A138  7C A5 02 14 */	add r5, r5, r0
/* 8005D1DC 0005A13C  90 C5 00 04 */	stw r6, 4(r5)
/* 8005D1E0 0005A140  38 A4 83 28 */	addi r5, r4, lbl_802A8328@l
/* 8005D1E4 0005A144  38 83 2E 30 */	addi r4, r3, 0x76302E30@l
/* 8005D1E8 0005A148  80 07 00 00 */	lwz r0, 0(r7)
/* 8005D1EC 0005A14C  80 67 00 08 */	lwz r3, 8(r7)
/* 8005D1F0 0005A150  54 00 20 36 */	slwi r0, r0, 4
/* 8005D1F4 0005A154  7C 63 02 14 */	add r3, r3, r0
/* 8005D1F8 0005A158  90 A3 00 08 */	stw r5, 8(r3)
/* 8005D1FC 0005A15C  80 07 00 00 */	lwz r0, 0(r7)
/* 8005D200 0005A160  80 67 00 08 */	lwz r3, 8(r7)
/* 8005D204 0005A164  54 00 20 36 */	slwi r0, r0, 4
/* 8005D208 0005A168  7C 63 02 14 */	add r3, r3, r0
/* 8005D20C 0005A16C  90 83 00 0C */	stw r4, 0xc(r3)
/* 8005D210 0005A170  80 67 00 00 */	lwz r3, 0(r7)
/* 8005D214 0005A174  38 03 00 01 */	addi r0, r3, 1
/* 8005D218 0005A178  90 07 00 00 */	stw r0, 0(r7)
/* 8005D21C 0005A17C  4E 80 00 20 */	blr 
.endfn initialise__18GenObjectMapObjectFP6MapMgr

.fn doRead__18GenObjectMapObjectFR18RandomAccessStream, global
/* 8005D220 0005A180  7C 08 02 A6 */	mflr r0
/* 8005D224 0005A184  90 01 00 04 */	stw r0, 4(r1)
/* 8005D228 0005A188  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8005D22C 0005A18C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8005D230 0005A190  3B E3 00 00 */	addi r31, r3, 0
/* 8005D234 0005A194  38 64 00 00 */	addi r3, r4, 0
/* 8005D238 0005A198  81 84 00 04 */	lwz r12, 4(r4)
/* 8005D23C 0005A19C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8005D240 0005A1A0  7D 88 03 A6 */	mtlr r12
/* 8005D244 0005A1A4  4E 80 00 21 */	blrl 
/* 8005D248 0005A1A8  90 7F 00 18 */	stw r3, 0x18(r31)
/* 8005D24C 0005A1AC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8005D250 0005A1B0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8005D254 0005A1B4  38 21 00 18 */	addi r1, r1, 0x18
/* 8005D258 0005A1B8  7C 08 03 A6 */	mtlr r0
/* 8005D25C 0005A1BC  4E 80 00 20 */	blr 
.endfn doRead__18GenObjectMapObjectFR18RandomAccessStream

.fn render__18GenObjectMapObjectFR8GraphicsP9Generator, global
/* 8005D260 0005A1C0  4E 80 00 20 */	blr 
.endfn render__18GenObjectMapObjectFR8GraphicsP9Generator

.fn birth__18GenObjectMapObjectFR9BirthInfo, global
/* 8005D264 0005A1C4  38 60 00 00 */	li r3, 0
/* 8005D268 0005A1C8  4E 80 00 20 */	blr 
.endfn birth__18GenObjectMapObjectFR9BirthInfo

.fn __ct__9RigidBodyFv, weak
/* 8005D26C 0005A1CC  7C 08 02 A6 */	mflr r0
/* 8005D270 0005A1D0  3C 80 80 22 */	lis r4, __vt__5ANode@ha
/* 8005D274 0005A1D4  90 01 00 04 */	stw r0, 4(r1)
/* 8005D278 0005A1D8  38 04 73 8C */	addi r0, r4, __vt__5ANode@l
/* 8005D27C 0005A1DC  38 80 00 00 */	li r4, 0
/* 8005D280 0005A1E0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8005D284 0005A1E4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8005D288 0005A1E8  3B E3 00 00 */	addi r31, r3, 0
/* 8005D28C 0005A1EC  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 8005D290 0005A1F0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8005D294 0005A1F4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8005D298 0005A1F8  90 1F 00 00 */	stw r0, 0(r31)
/* 8005D29C 0005A1FC  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 8005D2A0 0005A200  3C 60 80 2B */	lis r3, lbl_802A833C@ha
/* 8005D2A4 0005A204  90 1F 00 00 */	stw r0, 0(r31)
/* 8005D2A8 0005A208  38 A3 83 3C */	addi r5, r3, lbl_802A833C@l
/* 8005D2AC 0005A20C  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 8005D2B0 0005A210  90 9F 00 10 */	stw r4, 0x10(r31)
/* 8005D2B4 0005A214  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 8005D2B8 0005A218  38 7F 00 00 */	addi r3, r31, 0
/* 8005D2BC 0005A21C  90 9F 00 0C */	stw r4, 0xc(r31)
/* 8005D2C0 0005A220  90 9F 00 08 */	stw r4, 8(r31)
/* 8005D2C4 0005A224  38 85 00 00 */	addi r4, r5, 0
/* 8005D2C8 0005A228  90 BF 00 04 */	stw r5, 4(r31)
/* 8005D2CC 0005A22C  90 1F 00 00 */	stw r0, 0(r31)
/* 8005D2D0 0005A230  4B FE 34 6D */	bl init__4NodeFPc
/* 8005D2D4 0005A234  3C 60 80 2A */	lis r3, __vt__9RigidBody@ha
/* 8005D2D8 0005A238  38 03 5F 50 */	addi r0, r3, __vt__9RigidBody@l
/* 8005D2DC 0005A23C  90 1F 00 00 */	stw r0, 0(r31)
/* 8005D2E0 0005A240  38 60 00 08 */	li r3, 8
/* 8005D2E4 0005A244  C0 02 86 80 */	lfs f0, lbl_803E8880@sda21(r2)
/* 8005D2E8 0005A248  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 8005D2EC 0005A24C  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 8005D2F0 0005A250  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 8005D2F4 0005A254  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 8005D2F8 0005A258  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 8005D2FC 0005A25C  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 8005D300 0005A260  D0 1F 00 40 */	stfs f0, 0x40(r31)
/* 8005D304 0005A264  D0 1F 00 3C */	stfs f0, 0x3c(r31)
/* 8005D308 0005A268  D0 1F 00 38 */	stfs f0, 0x38(r31)
/* 8005D30C 0005A26C  D0 1F 00 4C */	stfs f0, 0x4c(r31)
/* 8005D310 0005A270  D0 1F 00 48 */	stfs f0, 0x48(r31)
/* 8005D314 0005A274  D0 1F 00 44 */	stfs f0, 0x44(r31)
/* 8005D318 0005A278  D0 1F 00 58 */	stfs f0, 0x58(r31)
/* 8005D31C 0005A27C  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 8005D320 0005A280  D0 1F 00 50 */	stfs f0, 0x50(r31)
/* 8005D324 0005A284  D0 1F 00 64 */	stfs f0, 0x64(r31)
/* 8005D328 0005A288  D0 1F 00 68 */	stfs f0, 0x68(r31)
/* 8005D32C 0005A28C  D0 1F 00 6C */	stfs f0, 0x6c(r31)
/* 8005D330 0005A290  D0 1F 00 70 */	stfs f0, 0x70(r31)
/* 8005D334 0005A294  D0 1F 00 74 */	stfs f0, 0x74(r31)
/* 8005D338 0005A298  D0 1F 00 78 */	stfs f0, 0x78(r31)
/* 8005D33C 0005A29C  D0 1F 00 7C */	stfs f0, 0x7c(r31)
/* 8005D340 0005A2A0  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 8005D344 0005A2A4  48 00 01 A8 */	b .L_8005D4EC
.L_8005D348:
/* 8005D348 0005A2A8  20 03 00 09 */	subfic r0, r3, 9
/* 8005D34C 0005A2AC  2C 03 00 09 */	cmpwi r3, 9
/* 8005D350 0005A2B0  7C 09 03 A6 */	mtctr r0
/* 8005D354 0005A2B4  40 80 00 10 */	bge .L_8005D364
.L_8005D358:
/* 8005D358 0005A2B8  D0 04 00 64 */	stfs f0, 0x64(r4)
/* 8005D35C 0005A2BC  38 84 00 04 */	addi r4, r4, 4
/* 8005D360 0005A2C0  42 00 FF F8 */	bdnz .L_8005D358
.L_8005D364:
/* 8005D364 0005A2C4  C0 02 86 84 */	lfs f0, lbl_803E8884@sda21(r2)
/* 8005D368 0005A2C8  3C 60 80 03 */	lis r3, __ct__8Vector3fFv@ha
/* 8005D36C 0005A2CC  3B A3 5B 24 */	addi r29, r3, __ct__8Vector3fFv@l
/* 8005D370 0005A2D0  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 8005D374 0005A2D4  38 9D 00 00 */	addi r4, r29, 0
/* 8005D378 0005A2D8  38 7F 00 94 */	addi r3, r31, 0x94
/* 8005D37C 0005A2DC  D0 1F 00 74 */	stfs f0, 0x74(r31)
/* 8005D380 0005A2E0  38 A0 00 00 */	li r5, 0
/* 8005D384 0005A2E4  38 C0 00 0C */	li r6, 0xc
/* 8005D388 0005A2E8  D0 1F 00 64 */	stfs f0, 0x64(r31)
/* 8005D38C 0005A2EC  38 E0 04 00 */	li r7, 0x400
/* 8005D390 0005A2F0  48 1B 76 E1 */	bl __construct_array
/* 8005D394 0005A2F4  3C 60 80 06 */	lis r3, __ct__11WorldSpringFv@ha
/* 8005D398 0005A2F8  38 83 D6 78 */	addi r4, r3, __ct__11WorldSpringFv@l
/* 8005D39C 0005A2FC  38 7F 40 98 */	addi r3, r31, 0x4098
/* 8005D3A0 0005A300  38 A0 00 00 */	li r5, 0
/* 8005D3A4 0005A304  38 C0 00 10 */	li r6, 0x10
/* 8005D3A8 0005A308  38 E0 00 08 */	li r7, 8
/* 8005D3AC 0005A30C  48 1B 76 C5 */	bl __construct_array
/* 8005D3B0 0005A310  3C 60 80 06 */	lis r3, __ct__Q29RigidBody13configurationFv@ha
/* 8005D3B4 0005A314  38 83 D5 28 */	addi r4, r3, __ct__Q29RigidBody13configurationFv@l
/* 8005D3B8 0005A318  38 7F 41 18 */	addi r3, r31, 0x4118
/* 8005D3BC 0005A31C  38 A0 00 00 */	li r5, 0
/* 8005D3C0 0005A320  38 C0 30 8C */	li r6, 0x308c
/* 8005D3C4 0005A324  38 E0 00 02 */	li r7, 2
/* 8005D3C8 0005A328  48 1B 76 A9 */	bl __construct_array
/* 8005D3CC 0005A32C  C0 02 86 80 */	lfs f0, lbl_803E8880@sda21(r2)
/* 8005D3D0 0005A330  3F DF 00 01 */	addis r30, r31, 1
/* 8005D3D4 0005A334  38 7E 00 00 */	addi r3, r30, 0
/* 8005D3D8 0005A338  D0 1E A2 38 */	stfs f0, -0x5dc8(r30)
/* 8005D3DC 0005A33C  7F A4 EB 78 */	mr r4, r29
/* 8005D3E0 0005A340  38 A0 00 00 */	li r5, 0
/* 8005D3E4 0005A344  D0 1E A2 34 */	stfs f0, -0x5dcc(r30)
/* 8005D3E8 0005A348  38 C0 00 0C */	li r6, 0xc
/* 8005D3EC 0005A34C  38 E0 08 00 */	li r7, 0x800
/* 8005D3F0 0005A350  D0 1E A2 30 */	stfs f0, -0x5dd0(r30)
/* 8005D3F4 0005A354  38 63 A2 48 */	addi r3, r3, -23992
/* 8005D3F8 0005A358  D0 1E A2 44 */	stfs f0, -0x5dbc(r30)
/* 8005D3FC 0005A35C  D0 1E A2 40 */	stfs f0, -0x5dc0(r30)
/* 8005D400 0005A360  D0 1E A2 3C */	stfs f0, -0x5dc4(r30)
/* 8005D404 0005A364  48 1B 76 6D */	bl __construct_array
/* 8005D408 0005A368  38 7E 00 00 */	addi r3, r30, 0
/* 8005D40C 0005A36C  38 9D 00 00 */	addi r4, r29, 0
/* 8005D410 0005A370  38 A0 00 00 */	li r5, 0
/* 8005D414 0005A374  38 C0 00 0C */	li r6, 0xc
/* 8005D418 0005A378  38 E0 04 00 */	li r7, 0x400
/* 8005D41C 0005A37C  38 63 02 48 */	addi r3, r3, 0x248
/* 8005D420 0005A380  48 1B 76 51 */	bl __construct_array
/* 8005D424 0005A384  38 7E 00 00 */	addi r3, r30, 0
/* 8005D428 0005A388  38 9D 00 00 */	addi r4, r29, 0
/* 8005D42C 0005A38C  38 A0 00 00 */	li r5, 0
/* 8005D430 0005A390  38 C0 00 0C */	li r6, 0xc
/* 8005D434 0005A394  38 E0 00 02 */	li r7, 2
/* 8005D438 0005A398  38 63 32 48 */	addi r3, r3, 0x3248
/* 8005D43C 0005A39C  48 1B 76 35 */	bl __construct_array
/* 8005D440 0005A3A0  C0 02 86 80 */	lfs f0, lbl_803E8880@sda21(r2)
/* 8005D444 0005A3A4  3C 80 80 06 */	lis r4, __ct__4QuatFv@ha
/* 8005D448 0005A3A8  38 7E 00 00 */	addi r3, r30, 0
/* 8005D44C 0005A3AC  D0 1E 32 68 */	stfs f0, 0x3268(r30)
/* 8005D450 0005A3B0  38 84 D5 14 */	addi r4, r4, __ct__4QuatFv@l
/* 8005D454 0005A3B4  38 A0 00 00 */	li r5, 0
/* 8005D458 0005A3B8  D0 1E 32 64 */	stfs f0, 0x3264(r30)
/* 8005D45C 0005A3BC  38 C0 00 10 */	li r6, 0x10
/* 8005D460 0005A3C0  38 E0 00 02 */	li r7, 2
/* 8005D464 0005A3C4  D0 1E 32 60 */	stfs f0, 0x3260(r30)
/* 8005D468 0005A3C8  38 63 32 6C */	addi r3, r3, 0x326c
/* 8005D46C 0005A3CC  48 1B 76 05 */	bl __construct_array
/* 8005D470 0005A3D0  C0 22 86 80 */	lfs f1, lbl_803E8880@sda21(r2)
/* 8005D474 0005A3D4  38 00 00 00 */	li r0, 0
/* 8005D478 0005A3D8  38 7F 00 00 */	addi r3, r31, 0
/* 8005D47C 0005A3DC  D0 3E 32 94 */	stfs f1, 0x3294(r30)
/* 8005D480 0005A3E0  D0 3E 32 90 */	stfs f1, 0x3290(r30)
/* 8005D484 0005A3E4  D0 3E 32 8C */	stfs f1, 0x328c(r30)
/* 8005D488 0005A3E8  D0 3E 32 A4 */	stfs f1, 0x32a4(r30)
/* 8005D48C 0005A3EC  D0 3E 32 A0 */	stfs f1, 0x32a0(r30)
/* 8005D490 0005A3F0  D0 3E 32 9C */	stfs f1, 0x329c(r30)
/* 8005D494 0005A3F4  D0 3E 32 B0 */	stfs f1, 0x32b0(r30)
/* 8005D498 0005A3F8  D0 3E 32 AC */	stfs f1, 0x32ac(r30)
/* 8005D49C 0005A3FC  D0 3E 32 A8 */	stfs f1, 0x32a8(r30)
/* 8005D4A0 0005A400  C0 0D 90 40 */	lfs f0, lbl_803DDD60@sda21(r13)
/* 8005D4A4 0005A404  D0 1E 32 9C */	stfs f0, 0x329c(r30)
/* 8005D4A8 0005A408  C0 0D 90 44 */	lfs f0, lbl_803DDD64@sda21(r13)
/* 8005D4AC 0005A40C  D0 1E 32 A0 */	stfs f0, 0x32a0(r30)
/* 8005D4B0 0005A410  C0 0D 90 48 */	lfs f0, lbl_803DDD68@sda21(r13)
/* 8005D4B4 0005A414  D0 1E 32 A4 */	stfs f0, 0x32a4(r30)
/* 8005D4B8 0005A418  C0 0D 90 4C */	lfs f0, lbl_803DDD6C@sda21(r13)
/* 8005D4BC 0005A41C  D0 1E 32 A8 */	stfs f0, 0x32a8(r30)
/* 8005D4C0 0005A420  C0 0D 90 50 */	lfs f0, lbl_803DDD70@sda21(r13)
/* 8005D4C4 0005A424  D0 1E 32 AC */	stfs f0, 0x32ac(r30)
/* 8005D4C8 0005A428  C0 0D 90 54 */	lfs f0, lbl_803DDD74@sda21(r13)
/* 8005D4CC 0005A42C  D0 1E 32 B0 */	stfs f0, 0x32b0(r30)
/* 8005D4D0 0005A430  90 1F 72 2C */	stw r0, 0x722c(r31)
/* 8005D4D4 0005A434  90 1F 41 A0 */	stw r0, 0x41a0(r31)
/* 8005D4D8 0005A438  D0 3F 00 5C */	stfs f1, 0x5c(r31)
/* 8005D4DC 0005A43C  90 1F 00 90 */	stw r0, 0x90(r31)
/* 8005D4E0 0005A440  90 1F 00 8C */	stw r0, 0x8c(r31)
/* 8005D4E4 0005A444  90 1F 40 94 */	stw r0, 0x4094(r31)
/* 8005D4E8 0005A448  48 00 00 10 */	b .L_8005D4F8
.L_8005D4EC:
/* 8005D4EC 0005A44C  54 60 10 3A */	slwi r0, r3, 2
/* 8005D4F0 0005A450  7C 9F 02 14 */	add r4, r31, r0
/* 8005D4F4 0005A454  4B FF FE 54 */	b .L_8005D348
.L_8005D4F8:
/* 8005D4F8 0005A458  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8005D4FC 0005A45C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8005D500 0005A460  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8005D504 0005A464  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8005D508 0005A468  38 21 00 20 */	addi r1, r1, 0x20
/* 8005D50C 0005A46C  7C 08 03 A6 */	mtlr r0
/* 8005D510 0005A470  4E 80 00 20 */	blr 
.endfn __ct__9RigidBodyFv

.fn __ct__4QuatFv, weak
/* 8005D514 0005A474  C0 02 86 80 */	lfs f0, lbl_803E8880@sda21(r2)
/* 8005D518 0005A478  D0 03 00 08 */	stfs f0, 8(r3)
/* 8005D51C 0005A47C  D0 03 00 04 */	stfs f0, 4(r3)
/* 8005D520 0005A480  D0 03 00 00 */	stfs f0, 0(r3)
/* 8005D524 0005A484  4E 80 00 20 */	blr 
.endfn __ct__4QuatFv

.fn __ct__Q29RigidBody13configurationFv, weak
/* 8005D528 0005A488  7C 08 02 A6 */	mflr r0
/* 8005D52C 0005A48C  90 01 00 04 */	stw r0, 4(r1)
/* 8005D530 0005A490  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8005D534 0005A494  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8005D538 0005A498  7C 7F 1B 78 */	mr r31, r3
/* 8005D53C 0005A49C  C0 02 86 80 */	lfs f0, lbl_803E8880@sda21(r2)
/* 8005D540 0005A4A0  D0 03 00 00 */	stfs f0, 0(r3)
/* 8005D544 0005A4A4  38 60 00 08 */	li r3, 8
/* 8005D548 0005A4A8  D0 1F 00 04 */	stfs f0, 4(r31)
/* 8005D54C 0005A4AC  D0 1F 00 08 */	stfs f0, 8(r31)
/* 8005D550 0005A4B0  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8005D554 0005A4B4  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8005D558 0005A4B8  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 8005D55C 0005A4BC  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 8005D560 0005A4C0  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8005D564 0005A4C4  48 00 00 E8 */	b .L_8005D64C
.L_8005D568:
/* 8005D568 0005A4C8  20 03 00 09 */	subfic r0, r3, 9
/* 8005D56C 0005A4CC  2C 03 00 09 */	cmpwi r3, 9
/* 8005D570 0005A4D0  7C 09 03 A6 */	mtctr r0
/* 8005D574 0005A4D4  40 80 00 10 */	bge .L_8005D584
.L_8005D578:
/* 8005D578 0005A4D8  D0 04 00 00 */	stfs f0, 0(r4)
/* 8005D57C 0005A4DC  38 84 00 04 */	addi r4, r4, 4
/* 8005D580 0005A4E0  42 00 FF F8 */	bdnz .L_8005D578
.L_8005D584:
/* 8005D584 0005A4E4  C0 02 86 84 */	lfs f0, lbl_803E8884@sda21(r2)
/* 8005D588 0005A4E8  38 60 00 08 */	li r3, 8
/* 8005D58C 0005A4EC  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 8005D590 0005A4F0  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8005D594 0005A4F4  D0 1F 00 00 */	stfs f0, 0(r31)
/* 8005D598 0005A4F8  C0 02 86 80 */	lfs f0, lbl_803E8880@sda21(r2)
/* 8005D59C 0005A4FC  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 8005D5A0 0005A500  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 8005D5A4 0005A504  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 8005D5A8 0005A508  D0 1F 00 3C */	stfs f0, 0x3c(r31)
/* 8005D5AC 0005A50C  D0 1F 00 38 */	stfs f0, 0x38(r31)
/* 8005D5B0 0005A510  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 8005D5B4 0005A514  D0 1F 00 48 */	stfs f0, 0x48(r31)
/* 8005D5B8 0005A518  D0 1F 00 44 */	stfs f0, 0x44(r31)
/* 8005D5BC 0005A51C  D0 1F 00 40 */	stfs f0, 0x40(r31)
/* 8005D5C0 0005A520  D0 1F 00 54 */	stfs f0, 0x54(r31)
/* 8005D5C4 0005A524  D0 1F 00 50 */	stfs f0, 0x50(r31)
/* 8005D5C8 0005A528  D0 1F 00 4C */	stfs f0, 0x4c(r31)
/* 8005D5CC 0005A52C  D0 1F 00 60 */	stfs f0, 0x60(r31)
/* 8005D5D0 0005A530  D0 1F 00 5C */	stfs f0, 0x5c(r31)
/* 8005D5D4 0005A534  D0 1F 00 58 */	stfs f0, 0x58(r31)
/* 8005D5D8 0005A538  D0 1F 00 64 */	stfs f0, 0x64(r31)
/* 8005D5DC 0005A53C  D0 1F 00 68 */	stfs f0, 0x68(r31)
/* 8005D5E0 0005A540  D0 1F 00 6C */	stfs f0, 0x6c(r31)
/* 8005D5E4 0005A544  D0 1F 00 70 */	stfs f0, 0x70(r31)
/* 8005D5E8 0005A548  D0 1F 00 74 */	stfs f0, 0x74(r31)
/* 8005D5EC 0005A54C  D0 1F 00 78 */	stfs f0, 0x78(r31)
/* 8005D5F0 0005A550  D0 1F 00 7C */	stfs f0, 0x7c(r31)
/* 8005D5F4 0005A554  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 8005D5F8 0005A558  48 00 00 60 */	b .L_8005D658
.L_8005D5FC:
/* 8005D5FC 0005A55C  20 03 00 09 */	subfic r0, r3, 9
/* 8005D600 0005A560  2C 03 00 09 */	cmpwi r3, 9
/* 8005D604 0005A564  7C 09 03 A6 */	mtctr r0
/* 8005D608 0005A568  40 80 00 10 */	bge .L_8005D618
.L_8005D60C:
/* 8005D60C 0005A56C  D0 04 00 64 */	stfs f0, 0x64(r4)
/* 8005D610 0005A570  38 84 00 04 */	addi r4, r4, 4
/* 8005D614 0005A574  42 00 FF F8 */	bdnz .L_8005D60C
.L_8005D618:
/* 8005D618 0005A578  C0 02 86 84 */	lfs f0, lbl_803E8884@sda21(r2)
/* 8005D61C 0005A57C  3C 60 80 03 */	lis r3, __ct__8Vector3fFv@ha
/* 8005D620 0005A580  38 83 5B 24 */	addi r4, r3, __ct__8Vector3fFv@l
/* 8005D624 0005A584  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 8005D628 0005A588  38 7F 00 8C */	addi r3, r31, 0x8c
/* 8005D62C 0005A58C  38 A0 00 00 */	li r5, 0
/* 8005D630 0005A590  D0 1F 00 74 */	stfs f0, 0x74(r31)
/* 8005D634 0005A594  38 C0 00 0C */	li r6, 0xc
/* 8005D638 0005A598  38 E0 04 00 */	li r7, 0x400
/* 8005D63C 0005A59C  D0 1F 00 64 */	stfs f0, 0x64(r31)
/* 8005D640 0005A5A0  48 1B 74 31 */	bl __construct_array
/* 8005D644 0005A5A4  7F E3 FB 78 */	mr r3, r31
/* 8005D648 0005A5A8  48 00 00 1C */	b .L_8005D664
.L_8005D64C:
/* 8005D64C 0005A5AC  54 60 10 3A */	slwi r0, r3, 2
/* 8005D650 0005A5B0  7C 9F 02 14 */	add r4, r31, r0
/* 8005D654 0005A5B4  4B FF FF 14 */	b .L_8005D568
.L_8005D658:
/* 8005D658 0005A5B8  54 60 10 3A */	slwi r0, r3, 2
/* 8005D65C 0005A5BC  7C 9F 02 14 */	add r4, r31, r0
/* 8005D660 0005A5C0  4B FF FF 9C */	b .L_8005D5FC
.L_8005D664:
/* 8005D664 0005A5C4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8005D668 0005A5C8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8005D66C 0005A5CC  38 21 00 20 */	addi r1, r1, 0x20
/* 8005D670 0005A5D0  7C 08 03 A6 */	mtlr r0
/* 8005D674 0005A5D4  4E 80 00 20 */	blr 
.endfn __ct__Q29RigidBody13configurationFv

.fn __ct__11WorldSpringFv, weak
/* 8005D678 0005A5D8  C0 02 86 80 */	lfs f0, lbl_803E8880@sda21(r2)
/* 8005D67C 0005A5DC  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 8005D680 0005A5E0  D0 03 00 08 */	stfs f0, 8(r3)
/* 8005D684 0005A5E4  D0 03 00 04 */	stfs f0, 4(r3)
/* 8005D688 0005A5E8  4E 80 00 20 */	blr 
.endfn __ct__11WorldSpringFv

.fn set__8Vector3fFRCfRCfRCf, weak
/* 8005D68C 0005A5EC  C0 04 00 00 */	lfs f0, 0(r4)
/* 8005D690 0005A5F0  D0 03 00 00 */	stfs f0, 0(r3)
/* 8005D694 0005A5F4  C0 05 00 00 */	lfs f0, 0(r5)
/* 8005D698 0005A5F8  D0 03 00 04 */	stfs f0, 4(r3)
/* 8005D69C 0005A5FC  C0 06 00 00 */	lfs f0, 0(r6)
/* 8005D6A0 0005A600  D0 03 00 08 */	stfs f0, 8(r3)
/* 8005D6A4 0005A604  4E 80 00 20 */	blr 
.endfn set__8Vector3fFRCfRCfRCf

.fn applyGroundForces__12DynObjBridgeFiP9CollGroup, weak
/* 8005D6A8 0005A608  4E 80 00 20 */	blr 
.endfn applyGroundForces__12DynObjBridgeFiP9CollGroup

.fn initDimensions__10DynObjBodyFfff, weak
/* 8005D6AC 0005A60C  D0 23 00 50 */	stfs f1, 0x50(r3)
/* 8005D6B0 0005A610  D0 43 00 54 */	stfs f2, 0x54(r3)
/* 8005D6B4 0005A614  D0 63 00 58 */	stfs f3, 0x58(r3)
/* 8005D6B8 0005A618  C0 82 86 8C */	lfs f4, lbl_803E888C@sda21(r2)
/* 8005D6BC 0005A61C  C0 A2 86 88 */	lfs f5, lbl_803E8888@sda21(r2)
/* 8005D6C0 0005A620  EC 21 01 32 */	fmuls f1, f1, f4
/* 8005D6C4 0005A624  EC 02 01 32 */	fmuls f0, f2, f4
/* 8005D6C8 0005A628  EC 43 01 32 */	fmuls f2, f3, f4
/* 8005D6CC 0005A62C  EC 01 00 32 */	fmuls f0, f1, f0
/* 8005D6D0 0005A630  EC 02 00 32 */	fmuls f0, f2, f0
/* 8005D6D4 0005A634  EC 05 00 32 */	fmuls f0, f5, f0
/* 8005D6D8 0005A638  D0 03 00 5C */	stfs f0, 0x5c(r3)
/* 8005D6DC 0005A63C  4E 80 00 20 */	blr 
.endfn initDimensions__10DynObjBodyFfff

.fn updateUseList__9GenObjectFP9Generatori, weak
/* 8005D6E0 0005A640  4E 80 00 20 */	blr 
.endfn updateUseList__9GenObjectFP9Generatori

.fn init__9GenObjectFP9Generator, weak
/* 8005D6E4 0005A644  4E 80 00 20 */	blr 
.endfn init__9GenObjectFP9Generator

.fn update__9GenObjectFP9Generator, weak
/* 8005D6E8 0005A648  4E 80 00 20 */	blr 
.endfn update__9GenObjectFP9Generator

.fn doWrite__7GenBaseFR18RandomAccessStream, weak
/* 8005D6EC 0005A64C  4E 80 00 20 */	blr 
.endfn doWrite__7GenBaseFR18RandomAccessStream

.fn update__7GenBaseFv, weak
/* 8005D6F0 0005A650  4E 80 00 20 */	blr 
.endfn update__7GenBaseFv

.fn render__7GenBaseFR8Graphics, weak
/* 8005D6F4 0005A654  4E 80 00 20 */	blr 
.endfn render__7GenBaseFR8Graphics

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802A82F8, local
	.asciz "genMapObject.cpp"
.endobj lbl_802A82F8
.balign 4
.obj lbl_802A830C, local
	.asciz "genMapObject"
.endobj lbl_802A830C
.balign 4
.obj lbl_802A831C, local
	.asciz "object type"
.endobj lbl_802A831C
.balign 4
.obj lbl_802A8328, local
	.asciz "create MAP OBJECT"
.endobj lbl_802A8328
.balign 4
.obj lbl_802A833C, local
	.asciz "rigidBody"
.endobj lbl_802A833C
.balign 4
.obj lbl_802A8348, local
	.asciz "CoreNode"
.endobj lbl_802A8348
.balign 4
.obj lbl_802A8354, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.endobj lbl_802A8354
.skip 0x1C # compiler padding
.balign 4
.obj lbl_802A837C, local
	.asciz "DynObjBridge"
.endobj lbl_802A837C
.balign 4
.obj lbl_802A838C, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.endobj lbl_802A838C
.balign 4
.obj lbl_802A83A0, local
	.asciz "RigidBody"
.endobj lbl_802A83A0
.balign 4
.obj lbl_802A83AC, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.endobj lbl_802A83AC
.balign 4
.obj lbl_802A83C8, local
	.asciz "DynObjBody"
.endobj lbl_802A83C8
.balign 4
.obj lbl_802A83D4, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__9RigidBody
	.4byte 0
	.4byte 0
.endobj lbl_802A83D4
.balign 4
.obj lbl_802A83F8, local
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__9RigidBody
	.4byte 0
	.4byte __RTTI__10DynObjBody
	.4byte 0
	.4byte 0
.endobj lbl_802A83F8
.balign 4
.obj __vt__12DynObjBridge, weak
	.4byte __RTTI__12DynObjBridge
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__4NodeFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__10DynObjBodyFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte initDimensions__10DynObjBodyFfff
	.4byte computeForces__10DynObjBodyFif
	.4byte integrate__10DynObjBodyFiif
	.4byte resolveCollisions__9RigidBodyFiR9Collision
	.4byte calculateVertices__9RigidBodyFi
	.4byte initCollisions__9RigidBodyFi
	.4byte checkForCollisions__9RigidBodyFiR9CollState
	.4byte updateVecQuats__9RigidBodyFif
	.4byte updateViewInfo__9RigidBodyFii
	.4byte applyBodyFriction__9RigidBodyFiR8Vector3fR8Vector3fR8Vector3f
	.4byte makeBodyQuat__9RigidBodyFR4Quat
	.4byte initRender__10DynObjBodyFi
	.4byte shadrender__9RigidBodyFR8GraphicsP11LightCamera
	.4byte getViewScale__9RigidBodyFv
	.4byte updateCont__9RigidBodyFv
	.4byte applyGroundForces__12DynObjBridgeFiP9CollGroup
	.4byte touchCallback__10DynObjBodyFR5PlaneR8Vector3fR8Vector3f
	.4byte applyVelocity__10DynObjBodyFR5PlaneR8Vector3fR8Vector3f
.endobj __vt__12DynObjBridge
.balign 4
.obj lbl_802A849C, local
	.asciz "GenObjectMapObject"
.endobj lbl_802A849C
.balign 4
.obj lbl_802A84B0, local
	.asciz "Parameters"
.endobj lbl_802A84B0
.balign 4
.obj lbl_802A84BC, local
	.4byte __RTTI__10Parameters
	.4byte 0
	.4byte 0
.endobj lbl_802A84BC
.balign 4
.obj lbl_802A84C8, local
	.asciz "GenObject"
.endobj lbl_802A84C8
.balign 4
.obj lbl_802A84D4, local
	.4byte __RTTI__10Parameters
	.4byte 0
	.4byte __RTTI__7GenBase
	.4byte 0
	.4byte 0
.endobj lbl_802A84D4
.balign 4
.obj lbl_802A84E8, local
	.4byte __RTTI__10Parameters
	.4byte 0
	.4byte __RTTI__7GenBase
	.4byte 0
	.4byte __RTTI__9GenObject
	.4byte 0
	.4byte 0
.endobj lbl_802A84E8
.balign 4
.obj __vt__18GenObjectMapObject, global
	.4byte __RTTI__18GenObjectMapObject
	.4byte 0
	.4byte doWrite__7GenBaseFR18RandomAccessStream
	.4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
	.4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
	.4byte doRead__18GenObjectMapObjectFR18RandomAccessStream
	.4byte update__7GenBaseFv
	.4byte render__7GenBaseFR8Graphics
	.4byte getLatestVersion__9GenObjectFv
	.4byte updateUseList__9GenObjectFP9Generatori
	.4byte init__9GenObjectFP9Generator
	.4byte update__9GenObjectFP9Generator
	.4byte render__18GenObjectMapObjectFR8GraphicsP9Generator
	.4byte birth__18GenObjectMapObjectFR9BirthInfo
.endobj __vt__18GenObjectMapObject

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803DDD60, local
	.float 32768.0
.endobj lbl_803DDD60
.obj lbl_803DDD64, local
	.float 32768.0
.endobj lbl_803DDD64
.obj lbl_803DDD68, local
	.float 32768.0
.endobj lbl_803DDD68
.obj lbl_803DDD6C, local
	.float -32768.0
.endobj lbl_803DDD6C
.obj lbl_803DDD70, local
	.float -32768.0
.endobj lbl_803DDD70
.obj lbl_803DDD74, local
	.float -32768.0
.endobj lbl_803DDD74
.balign 4
.obj lbl_803DDD78, local
	.asciz "ANode"
.endobj lbl_803DDD78
.balign 4
.obj __RTTI__5ANode, local
	.4byte lbl_803DDD78
	.4byte 0
.endobj __RTTI__5ANode
.balign 4
.obj __RTTI__8CoreNode, local
	.4byte lbl_802A8348
	.4byte lbl_802A8354
.endobj __RTTI__8CoreNode
.balign 4
.obj lbl_803DDD90, local
	.asciz "Node"
.endobj lbl_803DDD90
.balign 4
.obj __RTTI__4Node, local
	.4byte lbl_803DDD90
	.4byte lbl_802A838C
.endobj __RTTI__4Node
.balign 4
.obj __RTTI__9RigidBody, local
	.4byte lbl_802A83A0
	.4byte lbl_802A83AC
.endobj __RTTI__9RigidBody
.balign 4
.obj __RTTI__10DynObjBody, local
	.4byte lbl_802A83C8
	.4byte lbl_802A83D4
.endobj __RTTI__10DynObjBody
.balign 4
.obj __RTTI__12DynObjBridge, local
	.4byte lbl_802A837C
	.4byte lbl_802A83F8
.endobj __RTTI__12DynObjBridge
.balign 4
.obj __RTTI__10Parameters, local
	.4byte lbl_802A84B0
	.4byte 0
.endobj __RTTI__10Parameters
.balign 4
.obj lbl_803DDDC0, local
	.asciz "GenBase"
.endobj lbl_803DDDC0
.balign 4
.obj __RTTI__7GenBase, local
	.4byte lbl_803DDDC0
	.4byte lbl_802A84BC
.endobj __RTTI__7GenBase
.balign 4
.obj __RTTI__9GenObject, local
	.4byte lbl_802A84C8
	.4byte lbl_802A84D4
.endobj __RTTI__9GenObject
.balign 4
.obj __RTTI__18GenObjectMapObject, local
	.4byte lbl_802A849C
	.4byte lbl_802A84E8
.endobj __RTTI__18GenObjectMapObject

.section .sbss, "wa"
.balign 8
.obj mapMgr__18GenObjectMapObject, global
	.skip 4
.endobj mapMgr__18GenObjectMapObject

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E8880, local
	.float 0.0
.endobj lbl_803E8880
.balign 4
.obj lbl_803E8884, local
	.float 1.0
.endobj lbl_803E8884
.balign 4
.obj lbl_803E8888, local
	.float 7.5E-5
.endobj lbl_803E8888
.balign 4
.obj lbl_803E888C, local
	.float 0.5
.endobj lbl_803E888C
