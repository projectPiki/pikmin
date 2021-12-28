.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__7ActGotoFP4Piki
__ct__7ActGotoFP4Piki:
/* 800BAF68 000B7EC8  7C 08 02 A6 */	mflr r0
/* 800BAF6C 000B7ECC  38 A0 00 01 */	li r5, 1
/* 800BAF70 000B7ED0  90 01 00 04 */	stw r0, 4(r1)
/* 800BAF74 000B7ED4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BAF78 000B7ED8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BAF7C 000B7EDC  3B E3 00 00 */	addi r31, r3, 0
/* 800BAF80 000B7EE0  48 00 8E 51 */	bl __ct__6ActionFP4Pikib
/* 800BAF84 000B7EE4  3C 60 80 2B */	lis r3, __vt__7ActGoto@ha
/* 800BAF88 000B7EE8  38 03 6B B4 */	addi r0, r3, __vt__7ActGoto@l
/* 800BAF8C 000B7EEC  90 1F 00 00 */	stw r0, 0(r31)
/* 800BAF90 000B7EF0  38 00 00 00 */	li r0, 0
/* 800BAF94 000B7EF4  38 7F 00 00 */	addi r3, r31, 0
/* 800BAF98 000B7EF8  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 800BAF9C 000B7EFC  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 800BAFA0 000B7F00  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BAFA4 000B7F04  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BAFA8 000B7F08  38 21 00 18 */	addi r1, r1, 0x18
/* 800BAFAC 000B7F0C  7C 08 03 A6 */	mtlr r0
/* 800BAFB0 000B7F10  4E 80 00 20 */	blr 

.global initialise__Q27ActGoto11InitialiserFP6Action
initialise__Q27ActGoto11InitialiserFP6Action:
/* 800BAFB4 000B7F14  7C 08 02 A6 */	mflr r0
/* 800BAFB8 000B7F18  90 01 00 04 */	stw r0, 4(r1)
/* 800BAFBC 000B7F1C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BAFC0 000B7F20  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BAFC4 000B7F24  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800BAFC8 000B7F28  7C 9E 23 78 */	mr r30, r4
/* 800BAFCC 000B7F2C  C0 03 00 08 */	lfs f0, 8(r3)
/* 800BAFD0 000B7F30  D0 04 00 14 */	stfs f0, 0x14(r4)
/* 800BAFD4 000B7F34  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 800BAFD8 000B7F38  D0 04 00 18 */	stfs f0, 0x18(r4)
/* 800BAFDC 000B7F3C  83 E3 00 04 */	lwz r31, 4(r3)
/* 800BAFE0 000B7F40  28 1F 00 00 */	cmplwi r31, 0
/* 800BAFE4 000B7F44  41 82 00 34 */	beq lbl_800BB018
/* 800BAFE8 000B7F48  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 800BAFEC 000B7F4C  28 03 00 00 */	cmplwi r3, 0
/* 800BAFF0 000B7F50  41 82 00 14 */	beq lbl_800BB004
/* 800BAFF4 000B7F54  41 82 00 10 */	beq lbl_800BB004
/* 800BAFF8 000B7F58  48 02 93 75 */	bl subCnt__12RefCountableFv
/* 800BAFFC 000B7F5C  38 00 00 00 */	li r0, 0
/* 800BB000 000B7F60  90 1E 00 1C */	stw r0, 0x1c(r30)
lbl_800BB004:
/* 800BB004 000B7F64  93 FE 00 1C */	stw r31, 0x1c(r30)
/* 800BB008 000B7F68  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 800BB00C 000B7F6C  28 03 00 00 */	cmplwi r3, 0
/* 800BB010 000B7F70  41 82 00 08 */	beq lbl_800BB018
/* 800BB014 000B7F74  48 02 93 49 */	bl addCnt__12RefCountableFv
lbl_800BB018:
/* 800BB018 000B7F78  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BB01C 000B7F7C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BB020 000B7F80  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800BB024 000B7F84  38 21 00 20 */	addi r1, r1, 0x20
/* 800BB028 000B7F88  7C 08 03 A6 */	mtlr r0
/* 800BB02C 000B7F8C  4E 80 00 20 */	blr 

.global init__7ActGotoFP8Creature
init__7ActGotoFP8Creature:
/* 800BB030 000B7F90  7C 08 02 A6 */	mflr r0
/* 800BB034 000B7F94  90 01 00 04 */	stw r0, 4(r1)
/* 800BB038 000B7F98  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 800BB03C 000B7F9C  93 E1 00 34 */	stw r31, 0x34(r1)
/* 800BB040 000B7FA0  3B E4 00 00 */	addi r31, r4, 0
/* 800BB044 000B7FA4  93 C1 00 30 */	stw r30, 0x30(r1)
/* 800BB048 000B7FA8  3B C3 00 00 */	addi r30, r3, 0
/* 800BB04C 000B7FAC  48 15 D0 25 */	bl rand
/* 800BB050 000B7FB0  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800BB054 000B7FB4  C8 82 93 38 */	lfd f4, lbl_803E9538@sda21(r2)
/* 800BB058 000B7FB8  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800BB05C 000B7FBC  3C 00 43 30 */	lis r0, 0x4330
/* 800BB060 000B7FC0  C0 62 93 2C */	lfs f3, lbl_803E952C@sda21(r2)
/* 800BB064 000B7FC4  90 01 00 28 */	stw r0, 0x28(r1)
/* 800BB068 000B7FC8  C0 42 93 28 */	lfs f2, lbl_803E9528@sda21(r2)
/* 800BB06C 000B7FCC  C8 21 00 28 */	lfd f1, 0x28(r1)
/* 800BB070 000B7FD0  C0 02 93 34 */	lfs f0, lbl_803E9534@sda21(r2)
/* 800BB074 000B7FD4  EC 81 20 28 */	fsubs f4, f1, f4
/* 800BB078 000B7FD8  C0 22 93 30 */	lfs f1, lbl_803E9530@sda21(r2)
/* 800BB07C 000B7FDC  EC 64 18 24 */	fdivs f3, f4, f3
/* 800BB080 000B7FE0  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800BB084 000B7FE4  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800BB088 000B7FE8  EC 01 00 2A */	fadds f0, f1, f0
/* 800BB08C 000B7FEC  D0 1E 00 20 */	stfs f0, 0x20(r30)
/* 800BB090 000B7FF0  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 800BB094 000B7FF4  28 03 00 00 */	cmplwi r3, 0
/* 800BB098 000B7FF8  41 82 00 14 */	beq lbl_800BB0AC
/* 800BB09C 000B7FFC  41 82 00 10 */	beq lbl_800BB0AC
/* 800BB0A0 000B8000  48 02 92 CD */	bl subCnt__12RefCountableFv
/* 800BB0A4 000B8004  38 00 00 00 */	li r0, 0
/* 800BB0A8 000B8008  90 1E 00 1C */	stw r0, 0x1c(r30)
lbl_800BB0AC:
/* 800BB0AC 000B800C  93 FE 00 1C */	stw r31, 0x1c(r30)
/* 800BB0B0 000B8010  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 800BB0B4 000B8014  28 03 00 00 */	cmplwi r3, 0
/* 800BB0B8 000B8018  41 82 00 08 */	beq lbl_800BB0C0
/* 800BB0BC 000B801C  48 02 92 A1 */	bl addCnt__12RefCountableFv
lbl_800BB0C0:
/* 800BB0C0 000B8020  38 61 00 14 */	addi r3, r1, 0x14
/* 800BB0C4 000B8024  38 80 00 00 */	li r4, 0
/* 800BB0C8 000B8028  48 06 3E 91 */	bl __ct__14PaniMotionInfoFi
/* 800BB0CC 000B802C  3B E3 00 00 */	addi r31, r3, 0
/* 800BB0D0 000B8030  38 61 00 1C */	addi r3, r1, 0x1c
/* 800BB0D4 000B8034  38 80 00 00 */	li r4, 0
/* 800BB0D8 000B8038  48 06 3E 81 */	bl __ct__14PaniMotionInfoFi
/* 800BB0DC 000B803C  7C 64 1B 78 */	mr r4, r3
/* 800BB0E0 000B8040  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BB0E4 000B8044  7F E5 FB 78 */	mr r5, r31
/* 800BB0E8 000B8048  48 00 F8 F1 */	bl startMotion__4PikiFR14PaniMotionInfoR14PaniMotionInfo
/* 800BB0EC 000B804C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800BB0F0 000B8050  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 800BB0F4 000B8054  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 800BB0F8 000B8058  38 21 00 38 */	addi r1, r1, 0x38
/* 800BB0FC 000B805C  7C 08 03 A6 */	mtlr r0
/* 800BB100 000B8060  4E 80 00 20 */	blr 

.global cleanup__7ActGotoFv
cleanup__7ActGotoFv:
/* 800BB104 000B8064  7C 08 02 A6 */	mflr r0
/* 800BB108 000B8068  90 01 00 04 */	stw r0, 4(r1)
/* 800BB10C 000B806C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800BB110 000B8070  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800BB114 000B8074  7C 7F 1B 78 */	mr r31, r3
/* 800BB118 000B8078  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 800BB11C 000B807C  28 03 00 00 */	cmplwi r3, 0
/* 800BB120 000B8080  41 82 00 10 */	beq lbl_800BB130
/* 800BB124 000B8084  48 02 92 49 */	bl subCnt__12RefCountableFv
/* 800BB128 000B8088  38 00 00 00 */	li r0, 0
/* 800BB12C 000B808C  90 1F 00 1C */	stw r0, 0x1c(r31)
lbl_800BB130:
/* 800BB130 000B8090  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800BB134 000B8094  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800BB138 000B8098  38 21 00 20 */	addi r1, r1, 0x20
/* 800BB13C 000B809C  7C 08 03 A6 */	mtlr r0
/* 800BB140 000B80A0  4E 80 00 20 */	blr 

.global exec__7ActGotoFv
exec__7ActGotoFv:
/* 800BB144 000B80A4  7C 08 02 A6 */	mflr r0
/* 800BB148 000B80A8  90 01 00 04 */	stw r0, 4(r1)
/* 800BB14C 000B80AC  94 21 FE 18 */	stwu r1, -0x1e8(r1)
/* 800BB150 000B80B0  DB E1 01 E0 */	stfd f31, 0x1e0(r1)
/* 800BB154 000B80B4  DB C1 01 D8 */	stfd f30, 0x1d8(r1)
/* 800BB158 000B80B8  DB A1 01 D0 */	stfd f29, 0x1d0(r1)
/* 800BB15C 000B80BC  DB 81 01 C8 */	stfd f28, 0x1c8(r1)
/* 800BB160 000B80C0  DB 61 01 C0 */	stfd f27, 0x1c0(r1)
/* 800BB164 000B80C4  DB 41 01 B8 */	stfd f26, 0x1b8(r1)
/* 800BB168 000B80C8  93 E1 01 B4 */	stw r31, 0x1b4(r1)
/* 800BB16C 000B80CC  93 C1 01 B0 */	stw r30, 0x1b0(r1)
/* 800BB170 000B80D0  7C 7E 1B 78 */	mr r30, r3
/* 800BB174 000B80D4  83 E3 00 1C */	lwz r31, 0x1c(r3)
/* 800BB178 000B80D8  28 1F 00 00 */	cmplwi r31, 0
/* 800BB17C 000B80DC  41 82 00 20 */	beq lbl_800BB19C
/* 800BB180 000B80E0  7F E3 FB 78 */	mr r3, r31
/* 800BB184 000B80E4  81 9F 00 00 */	lwz r12, 0(r31)
/* 800BB188 000B80E8  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 800BB18C 000B80EC  7D 88 03 A6 */	mtlr r12
/* 800BB190 000B80F0  4E 80 00 21 */	blrl 
/* 800BB194 000B80F4  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800BB198 000B80F8  40 82 00 0C */	bne lbl_800BB1A4
lbl_800BB19C:
/* 800BB19C 000B80FC  38 60 00 01 */	li r3, 1
/* 800BB1A0 000B8100  48 00 02 EC */	b lbl_800BB48C
lbl_800BB1A4:
/* 800BB1A4 000B8104  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 800BB1A8 000B8108  7F E3 FB 78 */	mr r3, r31
/* 800BB1AC 000B810C  C0 3E 00 20 */	lfs f1, 0x20(r30)
/* 800BB1B0 000B8110  C0 04 02 8C */	lfs f0, 0x28c(r4)
/* 800BB1B4 000B8114  EC 01 00 28 */	fsubs f0, f1, f0
/* 800BB1B8 000B8118  D0 1E 00 20 */	stfs f0, 0x20(r30)
/* 800BB1BC 000B811C  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800BB1C0 000B8120  4B FD 1C BD */	bl qdist2__FP8CreatureP8Creature
/* 800BB1C4 000B8124  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BB1C8 000B8128  FF A0 08 90 */	fmr f29, f1
/* 800BB1CC 000B812C  C0 1E 00 18 */	lfs f0, 0x18(r30)
/* 800BB1D0 000B8130  C0 5F 00 98 */	lfs f2, 0x98(r31)
/* 800BB1D4 000B8134  C0 23 00 98 */	lfs f1, 0x98(r3)
/* 800BB1D8 000B8138  FC 1D 00 40 */	fcmpo cr0, f29, f0
/* 800BB1DC 000B813C  EC 02 08 28 */	fsubs f0, f2, f1
/* 800BB1E0 000B8140  FF C0 02 10 */	fabs f30, f0
/* 800BB1E4 000B8144  4C 41 13 82 */	cror 2, 1, 2
/* 800BB1E8 000B8148  40 82 00 64 */	bne lbl_800BB24C
/* 800BB1EC 000B814C  7F E3 FB 78 */	mr r3, r31
/* 800BB1F0 000B8150  81 9F 00 00 */	lwz r12, 0(r31)
/* 800BB1F4 000B8154  81 8C 00 5C */	lwz r12, 0x5c(r12)
/* 800BB1F8 000B8158  7D 88 03 A6 */	mtlr r12
/* 800BB1FC 000B815C  4E 80 00 21 */	blrl 
/* 800BB200 000B8160  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BB204 000B8164  FF 80 08 90 */	fmr f28, f1
/* 800BB208 000B8168  81 83 00 00 */	lwz r12, 0(r3)
/* 800BB20C 000B816C  81 8C 00 5C */	lwz r12, 0x5c(r12)
/* 800BB210 000B8170  7D 88 03 A6 */	mtlr r12
/* 800BB214 000B8174  4E 80 00 21 */	blrl 
/* 800BB218 000B8178  C0 1E 00 14 */	lfs f0, 0x14(r30)
/* 800BB21C 000B817C  EC 00 08 2A */	fadds f0, f0, f1
/* 800BB220 000B8180  EC 00 E0 2A */	fadds f0, f0, f28
/* 800BB224 000B8184  FC 1D 00 40 */	fcmpo cr0, f29, f0
/* 800BB228 000B8188  4C 40 13 82 */	cror 2, 0, 2
/* 800BB22C 000B818C  40 82 00 20 */	bne lbl_800BB24C
/* 800BB230 000B8190  C0 02 93 40 */	lfs f0, lbl_803E9540@sda21(r2)
/* 800BB234 000B8194  FC 1E 00 40 */	fcmpo cr0, f30, f0
/* 800BB238 000B8198  40 81 00 0C */	ble lbl_800BB244
/* 800BB23C 000B819C  38 60 00 01 */	li r3, 1
/* 800BB240 000B81A0  48 00 02 4C */	b lbl_800BB48C
lbl_800BB244:
/* 800BB244 000B81A4  38 60 00 02 */	li r3, 2
/* 800BB248 000B81A8  48 00 02 44 */	b lbl_800BB48C
lbl_800BB24C:
/* 800BB24C 000B81AC  C0 3E 00 20 */	lfs f1, 0x20(r30)
/* 800BB250 000B81B0  C0 02 93 44 */	lfs f0, lbl_803E9544@sda21(r2)
/* 800BB254 000B81B4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800BB258 000B81B8  40 80 00 0C */	bge lbl_800BB264
/* 800BB25C 000B81BC  38 60 00 01 */	li r3, 1
/* 800BB260 000B81C0  48 00 02 2C */	b lbl_800BB48C
lbl_800BB264:
/* 800BB264 000B81C4  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BB268 000B81C8  C4 23 00 94 */	lfsu f1, 0x94(r3)
/* 800BB26C 000B81CC  C3 BF 00 94 */	lfs f29, 0x94(r31)
/* 800BB270 000B81D0  C3 DF 00 98 */	lfs f30, 0x98(r31)
/* 800BB274 000B81D4  C0 03 00 04 */	lfs f0, 4(r3)
/* 800BB278 000B81D8  EF 81 E8 28 */	fsubs f28, f1, f29
/* 800BB27C 000B81DC  C3 FF 00 9C */	lfs f31, 0x9c(r31)
/* 800BB280 000B81E0  EF 60 F0 28 */	fsubs f27, f0, f30
/* 800BB284 000B81E4  C0 03 00 08 */	lfs f0, 8(r3)
/* 800BB288 000B81E8  EC 3C 07 32 */	fmuls f1, f28, f28
/* 800BB28C 000B81EC  EF 40 F8 28 */	fsubs f26, f0, f31
/* 800BB290 000B81F0  EC 1B 06 F2 */	fmuls f0, f27, f27
/* 800BB294 000B81F4  EC 5A 06 B2 */	fmuls f2, f26, f26
/* 800BB298 000B81F8  EC 01 00 2A */	fadds f0, f1, f0
/* 800BB29C 000B81FC  EC 22 00 2A */	fadds f1, f2, f0
/* 800BB2A0 000B8200  4B F5 29 A1 */	bl sqrtf__3stdFf
/* 800BB2A4 000B8204  C0 02 93 44 */	lfs f0, lbl_803E9544@sda21(r2)
/* 800BB2A8 000B8208  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800BB2AC 000B820C  41 82 00 10 */	beq lbl_800BB2BC
/* 800BB2B0 000B8210  EF 9C 08 24 */	fdivs f28, f28, f1
/* 800BB2B4 000B8214  EF 7B 08 24 */	fdivs f27, f27, f1
/* 800BB2B8 000B8218  EF 5A 08 24 */	fdivs f26, f26, f1
lbl_800BB2BC:
/* 800BB2BC 000B821C  C0 7E 00 18 */	lfs f3, 0x18(r30)
/* 800BB2C0 000B8220  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BB2C4 000B8224  C0 0D B7 98 */	lfs f0, lbl_803E04B8@sda21(r13)
/* 800BB2C8 000B8228  EC 3C 00 F2 */	fmuls f1, f28, f3
/* 800BB2CC 000B822C  EC 5B 00 F2 */	fmuls f2, f27, f3
/* 800BB2D0 000B8230  D4 03 00 A4 */	stfsu f0, 0xa4(r3)
/* 800BB2D4 000B8234  EC 7A 00 F2 */	fmuls f3, f26, f3
/* 800BB2D8 000B8238  EF 9D 08 2A */	fadds f28, f29, f1
/* 800BB2DC 000B823C  C0 0D B7 9C */	lfs f0, lbl_803E04BC@sda21(r13)
/* 800BB2E0 000B8240  EF DE 10 2A */	fadds f30, f30, f2
/* 800BB2E4 000B8244  D0 03 00 04 */	stfs f0, 4(r3)
/* 800BB2E8 000B8248  EF BF 18 2A */	fadds f29, f31, f3
/* 800BB2EC 000B824C  C0 0D B7 A0 */	lfs f0, lbl_803E04C0@sda21(r13)
/* 800BB2F0 000B8250  D0 03 00 08 */	stfs f0, 8(r3)
/* 800BB2F4 000B8254  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BB2F8 000B8258  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 800BB2FC 000B825C  C0 23 00 04 */	lfs f1, 4(r3)
/* 800BB300 000B8260  EC 1C 00 28 */	fsubs f0, f28, f0
/* 800BB304 000B8264  C0 43 00 08 */	lfs f2, 8(r3)
/* 800BB308 000B8268  EC 7E 08 28 */	fsubs f3, f30, f1
/* 800BB30C 000B826C  D0 01 01 80 */	stfs f0, 0x180(r1)
/* 800BB310 000B8270  EC 3D 10 28 */	fsubs f1, f29, f2
/* 800BB314 000B8274  D0 61 01 84 */	stfs f3, 0x184(r1)
/* 800BB318 000B8278  D0 21 01 88 */	stfs f1, 0x188(r1)
/* 800BB31C 000B827C  C0 62 93 44 */	lfs f3, lbl_803E9544@sda21(r2)
/* 800BB320 000B8280  D0 61 01 84 */	stfs f3, 0x184(r1)
/* 800BB324 000B8284  C0 21 01 80 */	lfs f1, 0x180(r1)
/* 800BB328 000B8288  C0 01 01 84 */	lfs f0, 0x184(r1)
/* 800BB32C 000B828C  C0 41 01 88 */	lfs f2, 0x188(r1)
/* 800BB330 000B8290  EC 21 00 72 */	fmuls f1, f1, f1
/* 800BB334 000B8294  EC 00 00 32 */	fmuls f0, f0, f0
/* 800BB338 000B8298  EC 42 00 B2 */	fmuls f2, f2, f2
/* 800BB33C 000B829C  EC 01 00 2A */	fadds f0, f1, f0
/* 800BB340 000B82A0  EC 82 00 2A */	fadds f4, f2, f0
/* 800BB344 000B82A4  FC 04 18 40 */	fcmpo cr0, f4, f3
/* 800BB348 000B82A8  40 81 00 5C */	ble lbl_800BB3A4
/* 800BB34C 000B82AC  FC 20 20 34 */	frsqrte f1, f4
/* 800BB350 000B82B0  C8 62 93 48 */	lfd f3, lbl_803E9548@sda21(r2)
/* 800BB354 000B82B4  C8 42 93 50 */	lfd f2, lbl_803E9550@sda21(r2)
/* 800BB358 000B82B8  FC 01 00 72 */	fmul f0, f1, f1
/* 800BB35C 000B82BC  FC 23 00 72 */	fmul f1, f3, f1
/* 800BB360 000B82C0  FC 04 00 32 */	fmul f0, f4, f0
/* 800BB364 000B82C4  FC 02 00 28 */	fsub f0, f2, f0
/* 800BB368 000B82C8  FC 21 00 32 */	fmul f1, f1, f0
/* 800BB36C 000B82CC  FC 01 00 72 */	fmul f0, f1, f1
/* 800BB370 000B82D0  FC 23 00 72 */	fmul f1, f3, f1
/* 800BB374 000B82D4  FC 04 00 32 */	fmul f0, f4, f0
/* 800BB378 000B82D8  FC 02 00 28 */	fsub f0, f2, f0
/* 800BB37C 000B82DC  FC 21 00 32 */	fmul f1, f1, f0
/* 800BB380 000B82E0  FC 01 00 72 */	fmul f0, f1, f1
/* 800BB384 000B82E4  FC 23 00 72 */	fmul f1, f3, f1
/* 800BB388 000B82E8  FC 04 00 32 */	fmul f0, f4, f0
/* 800BB38C 000B82EC  FC 02 00 28 */	fsub f0, f2, f0
/* 800BB390 000B82F0  FC 01 00 32 */	fmul f0, f1, f0
/* 800BB394 000B82F4  FC 04 00 32 */	fmul f0, f4, f0
/* 800BB398 000B82F8  FC 00 00 18 */	frsp f0, f0
/* 800BB39C 000B82FC  D0 01 00 C4 */	stfs f0, 0xc4(r1)
/* 800BB3A0 000B8300  C0 81 00 C4 */	lfs f4, 0xc4(r1)
lbl_800BB3A4:
/* 800BB3A4 000B8304  C0 02 93 44 */	lfs f0, lbl_803E9544@sda21(r2)
/* 800BB3A8 000B8308  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 800BB3AC 000B830C  40 81 00 34 */	ble lbl_800BB3E0
/* 800BB3B0 000B8310  C0 22 93 28 */	lfs f1, lbl_803E9528@sda21(r2)
/* 800BB3B4 000B8314  C0 01 01 80 */	lfs f0, 0x180(r1)
/* 800BB3B8 000B8318  EC 61 20 24 */	fdivs f3, f1, f4
/* 800BB3BC 000B831C  C0 21 01 84 */	lfs f1, 0x184(r1)
/* 800BB3C0 000B8320  C0 41 01 88 */	lfs f2, 0x188(r1)
/* 800BB3C4 000B8324  EC 00 00 F2 */	fmuls f0, f0, f3
/* 800BB3C8 000B8328  EC 81 00 F2 */	fmuls f4, f1, f3
/* 800BB3CC 000B832C  EC 22 00 F2 */	fmuls f1, f2, f3
/* 800BB3D0 000B8330  D0 01 01 80 */	stfs f0, 0x180(r1)
/* 800BB3D4 000B8334  D0 81 01 84 */	stfs f4, 0x184(r1)
/* 800BB3D8 000B8338  D0 21 01 88 */	stfs f1, 0x188(r1)
/* 800BB3DC 000B833C  48 00 00 68 */	b lbl_800BB444
lbl_800BB3E0:
/* 800BB3E0 000B8340  48 15 CC 91 */	bl rand
/* 800BB3E4 000B8344  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 800BB3E8 000B8348  C8 82 93 38 */	lfd f4, lbl_803E9538@sda21(r2)
/* 800BB3EC 000B834C  90 01 01 AC */	stw r0, 0x1ac(r1)
/* 800BB3F0 000B8350  3C 00 43 30 */	lis r0, 0x4330
/* 800BB3F4 000B8354  C0 62 93 2C */	lfs f3, lbl_803E952C@sda21(r2)
/* 800BB3F8 000B8358  90 01 01 A8 */	stw r0, 0x1a8(r1)
/* 800BB3FC 000B835C  C0 42 93 28 */	lfs f2, lbl_803E9528@sda21(r2)
/* 800BB400 000B8360  C8 21 01 A8 */	lfd f1, 0x1a8(r1)
/* 800BB404 000B8364  C0 02 93 58 */	lfs f0, lbl_803E9558@sda21(r2)
/* 800BB408 000B8368  EC 81 20 28 */	fsubs f4, f1, f4
/* 800BB40C 000B836C  C0 22 93 34 */	lfs f1, lbl_803E9534@sda21(r2)
/* 800BB410 000B8370  EC 64 18 24 */	fdivs f3, f4, f3
/* 800BB414 000B8374  EC 42 00 F2 */	fmuls f2, f2, f3
/* 800BB418 000B8378  EC 00 00 B2 */	fmuls f0, f0, f2
/* 800BB41C 000B837C  EF 41 00 32 */	fmuls f26, f1, f0
/* 800BB420 000B8380  FC 20 D0 90 */	fmr f1, f26
/* 800BB424 000B8384  48 16 08 C5 */	bl sinf
/* 800BB428 000B8388  FF E0 08 90 */	fmr f31, f1
/* 800BB42C 000B838C  FC 20 D0 90 */	fmr f1, f26
/* 800BB430 000B8390  48 16 07 25 */	bl cosf
/* 800BB434 000B8394  D0 21 01 80 */	stfs f1, 0x180(r1)
/* 800BB438 000B8398  C0 0D B7 A4 */	lfs f0, lbl_803E04C4@sda21(r13)
/* 800BB43C 000B839C  D0 01 01 84 */	stfs f0, 0x184(r1)
/* 800BB440 000B83A0  D3 E1 01 88 */	stfs f31, 0x188(r1)
lbl_800BB444:
/* 800BB444 000B83A4  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BB448 000B83A8  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 800BB44C 000B83AC  C0 23 00 04 */	lfs f1, 4(r3)
/* 800BB450 000B83B0  EC 5C 00 28 */	fsubs f2, f28, f0
/* 800BB454 000B83B4  C0 03 00 08 */	lfs f0, 8(r3)
/* 800BB458 000B83B8  EC 7E 08 28 */	fsubs f3, f30, f1
/* 800BB45C 000B83BC  EC 9D 00 28 */	fsubs f4, f29, f0
/* 800BB460 000B83C0  EC 22 00 B2 */	fmuls f1, f2, f2
/* 800BB464 000B83C4  EC 03 00 F2 */	fmuls f0, f3, f3
/* 800BB468 000B83C8  EC 44 01 32 */	fmuls f2, f4, f4
/* 800BB46C 000B83CC  EC 01 00 2A */	fadds f0, f1, f0
/* 800BB470 000B83D0  EC 22 00 2A */	fadds f1, f2, f0
/* 800BB474 000B83D4  4B F5 27 CD */	bl sqrtf__3stdFf
/* 800BB478 000B83D8  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 800BB47C 000B83DC  38 81 01 80 */	addi r4, r1, 0x180
/* 800BB480 000B83E0  C0 22 93 28 */	lfs f1, lbl_803E9528@sda21(r2)
/* 800BB484 000B83E4  48 01 09 55 */	bl setSpeed__4PikiFfR8Vector3f
/* 800BB488 000B83E8  38 60 00 00 */	li r3, 0
lbl_800BB48C:
/* 800BB48C 000B83EC  80 01 01 EC */	lwz r0, 0x1ec(r1)
/* 800BB490 000B83F0  CB E1 01 E0 */	lfd f31, 0x1e0(r1)
/* 800BB494 000B83F4  CB C1 01 D8 */	lfd f30, 0x1d8(r1)
/* 800BB498 000B83F8  CB A1 01 D0 */	lfd f29, 0x1d0(r1)
/* 800BB49C 000B83FC  CB 81 01 C8 */	lfd f28, 0x1c8(r1)
/* 800BB4A0 000B8400  CB 61 01 C0 */	lfd f27, 0x1c0(r1)
/* 800BB4A4 000B8404  CB 41 01 B8 */	lfd f26, 0x1b8(r1)
/* 800BB4A8 000B8408  83 E1 01 B4 */	lwz r31, 0x1b4(r1)
/* 800BB4AC 000B840C  83 C1 01 B0 */	lwz r30, 0x1b0(r1)
/* 800BB4B0 000B8410  38 21 01 E8 */	addi r1, r1, 0x1e8
/* 800BB4B4 000B8414  7C 08 03 A6 */	mtlr r0
/* 800BB4B8 000B8418  4E 80 00 20 */	blr 

.global __dt__7ActGotoFv
__dt__7ActGotoFv:
/* 800BB4BC 000B841C  7C 08 02 A6 */	mflr r0
/* 800BB4C0 000B8420  90 01 00 04 */	stw r0, 4(r1)
/* 800BB4C4 000B8424  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800BB4C8 000B8428  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800BB4CC 000B842C  3B E4 00 00 */	addi r31, r4, 0
/* 800BB4D0 000B8430  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800BB4D4 000B8434  7C 7E 1B 79 */	or. r30, r3, r3
/* 800BB4D8 000B8438  41 82 00 2C */	beq lbl_800BB504
/* 800BB4DC 000B843C  3C 60 80 2B */	lis r3, __vt__7ActGoto@ha
/* 800BB4E0 000B8440  38 03 6B B4 */	addi r0, r3, __vt__7ActGoto@l
/* 800BB4E4 000B8444  90 1E 00 00 */	stw r0, 0(r30)
/* 800BB4E8 000B8448  38 7E 00 00 */	addi r3, r30, 0
/* 800BB4EC 000B844C  38 80 00 00 */	li r4, 0
/* 800BB4F0 000B8450  48 00 89 19 */	bl __dt__6ActionFv
/* 800BB4F4 000B8454  7F E0 07 35 */	extsh. r0, r31
/* 800BB4F8 000B8458  40 81 00 0C */	ble lbl_800BB504
/* 800BB4FC 000B845C  7F C3 F3 78 */	mr r3, r30
/* 800BB500 000B8460  4B F8 BC AD */	bl __dl__FPv
lbl_800BB504:
/* 800BB504 000B8464  7F C3 F3 78 */	mr r3, r30
/* 800BB508 000B8468  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800BB50C 000B846C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800BB510 000B8470  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800BB514 000B8474  38 21 00 18 */	addi r1, r1, 0x18
/* 800BB518 000B8478  7C 08 03 A6 */	mtlr r0
/* 800BB51C 000B847C  4E 80 00 20 */	blr 

.global defaultInitialiser__7ActGotoFv
defaultInitialiser__7ActGotoFv:
/* 800BB520 000B8480  C0 02 93 44 */	lfs f0, lbl_803E9544@sda21(r2)
/* 800BB524 000B8484  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 800BB528 000B8488  C0 02 93 5C */	lfs f0, lbl_803E955C@sda21(r2)
/* 800BB52C 000B848C  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 800BB530 000B8490  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802B6B78:
	.asciz "aiGoto.cpp"
.balign 4
lbl_802B6B84:
	.asciz "Receiver<Piki>"
.balign 4
lbl_802B6B94:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte 0
lbl_802B6BA0:
	.4byte "__RTTI__15Receiver<4Piki>"
	.4byte 0
	.4byte __RTTI__6Action
	.4byte 0
	.4byte 0
.global __vt__7ActGoto
__vt__7ActGoto:
	.4byte __RTTI__7ActGoto
	.4byte 0
	.4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
	.4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
	.4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
	.4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
	.4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
	.4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
	.4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
	.4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
	.4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
	.4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
	.4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
	.4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
	.4byte defaultInitialiser__7ActGotoFv
	.4byte dump__6ActionFv
	.4byte draw__6ActionFR8Graphics
	.4byte __dt__7ActGotoFv
	.4byte init__7ActGotoFP8Creature
	.4byte exec__7ActGotoFv
	.4byte cleanup__7ActGotoFv
	.4byte resume__6ActionFv
	.4byte restart__6ActionFv
	.4byte resumable__6ActionFv
	.4byte getInfo__6ActionFPc
.balign 4
lbl_802B6C18:
	.asciz "ActGoto::Initialiser"
.balign 4
lbl_802B6C30:
	.asciz "Action::Initialiser"
.balign 4
lbl_802B6C44:
	.4byte __RTTI__Q26Action11Initialiser
	.4byte 0
	.4byte 0
.global __vt__Q27ActGoto11Initialiser
__vt__Q27ActGoto11Initialiser:
	.4byte __RTTI__Q27ActGoto11Initialiser
	.4byte 0
	.4byte initialise__Q27ActGoto11InitialiserFP6Action
lbl_802B6C5C:
	.4byte lbl_800A7908
	.4byte lbl_800A7930
	.4byte lbl_800A7944
	.4byte lbl_800A7958
	.4byte lbl_800A796C
	.4byte lbl_800A7980
	.4byte lbl_800A7994
	.4byte lbl_800A79A8
	.4byte lbl_800A791C
	.4byte lbl_800A79D0
	.4byte lbl_800A79BC

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E04B8:
	.float 0.0
lbl_803E04BC:
	.float 0.0
lbl_803E04C0:
	.float 0.0
lbl_803E04C4:
	.float 0.0
.balign 4
lbl_803E04C8:
	.asciz "ActGoto"
.balign 4
"__RTTI__15Receiver<4Piki>":
	.4byte lbl_802B6B84
	.4byte 0
.balign 4
lbl_803E04D8:
	.asciz "Action"
.balign 4
__RTTI__6Action:
	.4byte lbl_803E04D8
	.4byte lbl_802B6B94
__RTTI__7ActGoto:
	.4byte lbl_803E04C8
	.4byte lbl_802B6BA0
__RTTI__Q26Action11Initialiser:
	.4byte lbl_802B6C30
	.4byte 0
__RTTI__Q27ActGoto11Initialiser:
	.4byte lbl_802B6C18
	.4byte lbl_802B6C44

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E9528:
	.float 1.0
lbl_803E952C:
	.float 32767.0
lbl_803E9530:
	.float 4.0
lbl_803E9534:
	.float 2.0
lbl_803E9538:
	.4byte 0x43300000
	.4byte 0x80000000
lbl_803E9540:
	.float 20.0
lbl_803E9544:
	.float 0.0
lbl_803E9548:
	.double 0.5
lbl_803E9550:
	.double 3.0
lbl_803E9558:
	.float 3.1415927
lbl_803E955C:
	.float 9.0
