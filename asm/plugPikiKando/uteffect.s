.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__11SlimeEffectFv, global
/* 80113164 001100C4  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113168 001100C8  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 8011316C 001100CC  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113170 001100D0  90 03 00 00 */	stw r0, 0(r3)
/* 80113174 001100D4  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113178 001100D8  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 8011317C 001100DC  90 03 00 04 */	stw r0, 4(r3)
/* 80113180 001100E0  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113184 001100E4  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113188 001100E8  90 03 00 08 */	stw r0, 8(r3)
/* 8011318C 001100EC  38 A4 05 AC */	addi r5, r4, __vt__7KEffect@l
/* 80113190 001100F0  90 A3 00 00 */	stw r5, 0(r3)
/* 80113194 001100F4  38 05 00 0C */	addi r0, r5, 0xc
/* 80113198 001100F8  3C 80 80 2C */	lis r4, __vt__11SlimeEffect@ha
/* 8011319C 001100FC  90 03 00 04 */	stw r0, 4(r3)
/* 801131A0 00110100  38 05 00 18 */	addi r0, r5, 0x18
/* 801131A4 00110104  38 C4 2C E0 */	addi r6, r4, __vt__11SlimeEffect@l
/* 801131A8 00110108  90 03 00 08 */	stw r0, 8(r3)
/* 801131AC 0011010C  38 A6 00 0C */	addi r5, r6, 0xc
/* 801131B0 00110110  38 86 00 18 */	addi r4, r6, 0x18
/* 801131B4 00110114  90 C3 00 00 */	stw r6, 0(r3)
/* 801131B8 00110118  38 00 00 00 */	li r0, 0
/* 801131BC 0011011C  90 A3 00 04 */	stw r5, 4(r3)
/* 801131C0 00110120  90 83 00 08 */	stw r4, 8(r3)
/* 801131C4 00110124  90 03 00 0C */	stw r0, 0xc(r3)
/* 801131C8 00110128  4E 80 00 20 */	blr 
.endfn __ct__11SlimeEffectFv

.fn stop__11SlimeEffectFv, global
/* 801131CC 0011012C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 801131D0 00110130  28 03 00 00 */	cmplwi r3, 0
/* 801131D4 00110134  4D 82 00 20 */	beqlr 
/* 801131D8 00110138  80 03 00 80 */	lwz r0, 0x80(r3)
/* 801131DC 0011013C  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 801131E0 00110140  90 03 00 80 */	stw r0, 0x80(r3)
/* 801131E4 00110144  4E 80 00 20 */	blr 
.endfn stop__11SlimeEffectFv

.fn restart__11SlimeEffectFv, global
/* 801131E8 00110148  80 63 00 0C */	lwz r3, 0xc(r3)
/* 801131EC 0011014C  28 03 00 00 */	cmplwi r3, 0
/* 801131F0 00110150  4D 82 00 20 */	beqlr 
/* 801131F4 00110154  80 03 00 80 */	lwz r0, 0x80(r3)
/* 801131F8 00110158  60 00 00 10 */	ori r0, r0, 0x10
/* 801131FC 0011015C  90 03 00 80 */	stw r0, 0x80(r3)
/* 80113200 00110160  4E 80 00 20 */	blr 
.endfn restart__11SlimeEffectFv

.fn emit__11SlimeEffectFR10EffectParm, global
/* 80113204 00110164  7C 08 02 A6 */	mflr r0
/* 80113208 00110168  90 01 00 04 */	stw r0, 4(r1)
/* 8011320C 0011016C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80113210 00110170  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80113214 00110174  7C 7F 1B 78 */	mr r31, r3
/* 80113218 00110178  80 04 00 28 */	lwz r0, 0x28(r4)
/* 8011321C 0011017C  90 03 00 10 */	stw r0, 0x10(r3)
/* 80113220 00110180  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80113224 00110184  C4 03 00 94 */	lfsu f0, 0x94(r3)
/* 80113228 00110188  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 8011322C 0011018C  C0 03 00 04 */	lfs f0, 4(r3)
/* 80113230 00110190  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 80113234 00110194  C0 03 00 08 */	lfs f0, 8(r3)
/* 80113238 00110198  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 8011323C 0011019C  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 80113240 001101A0  28 00 00 00 */	cmplwi r0, 0
/* 80113244 001101A4  40 82 00 3C */	bne .L_80113280
/* 80113248 001101A8  28 1F 00 00 */	cmplwi r31, 0
/* 8011324C 001101AC  38 FF 00 00 */	addi r7, r31, 0
/* 80113250 001101B0  41 82 00 08 */	beq .L_80113258
/* 80113254 001101B4  38 E7 00 04 */	addi r7, r7, 4
.L_80113258:
/* 80113258 001101B8  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8011325C 001101BC  38 DF 00 00 */	addi r6, r31, 0
/* 80113260 001101C0  38 A1 00 18 */	addi r5, r1, 0x18
/* 80113264 001101C4  38 80 00 24 */	li r4, 0x24
/* 80113268 001101C8  48 08 98 D1 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8011326C 001101CC  90 7F 00 0C */	stw r3, 0xc(r31)
/* 80113270 001101D0  80 9F 00 10 */	lwz r4, 0x10(r31)
/* 80113274 001101D4  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 80113278 001101D8  38 04 00 94 */	addi r0, r4, 0x94
/* 8011327C 001101DC  90 03 00 18 */	stw r0, 0x18(r3)
.L_80113280:
/* 80113280 001101E0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80113284 001101E4  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80113288 001101E8  38 21 00 30 */	addi r1, r1, 0x30
/* 8011328C 001101EC  7C 08 03 A6 */	mtlr r0
/* 80113290 001101F0  4E 80 00 20 */	blr 
.endfn emit__11SlimeEffectFR10EffectParm

.fn invoke__11SlimeEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl, global
/* 80113294 001101F4  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 80113298 001101F8  80 03 00 0C */	lwz r0, 0xc(r3)
/* 8011329C 001101FC  28 00 00 00 */	cmplwi r0, 0
/* 801132A0 00110200  41 82 00 84 */	beq .L_80113324
/* 801132A4 00110204  28 05 00 00 */	cmplwi r5, 0
/* 801132A8 00110208  41 82 00 7C */	beq .L_80113324
/* 801132AC 0011020C  80 63 00 10 */	lwz r3, 0x10(r3)
/* 801132B0 00110210  C4 03 00 70 */	lfsu f0, 0x70(r3)
/* 801132B4 00110214  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 801132B8 00110218  C0 03 00 04 */	lfs f0, 4(r3)
/* 801132BC 0011021C  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 801132C0 00110220  C0 03 00 08 */	lfs f0, 8(r3)
/* 801132C4 00110224  D0 01 00 50 */	stfs f0, 0x50(r1)
/* 801132C8 00110228  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 801132CC 0011022C  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 801132D0 00110230  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801132D4 00110234  C0 01 00 48 */	lfs f0, 0x48(r1)
/* 801132D8 00110238  C0 43 02 8C */	lfs f2, 0x28c(r3)
/* 801132DC 0011023C  C0 21 00 4C */	lfs f1, 0x4c(r1)
/* 801132E0 00110240  EC 00 00 B2 */	fmuls f0, f0, f2
/* 801132E4 00110244  C0 8D DB 40 */	lfs f4, lbl_803E2860@sda21(r13)
/* 801132E8 00110248  EC 61 00 B2 */	fmuls f3, f1, f2
/* 801132EC 0011024C  C0 21 00 50 */	lfs f1, 0x50(r1)
/* 801132F0 00110250  EC 00 01 32 */	fmuls f0, f0, f4
/* 801132F4 00110254  EC 41 00 B2 */	fmuls f2, f1, f2
/* 801132F8 00110258  EC 23 01 32 */	fmuls f1, f3, f4
/* 801132FC 0011025C  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 80113300 00110260  EC 02 01 32 */	fmuls f0, f2, f4
/* 80113304 00110264  D0 21 00 4C */	stfs f1, 0x4c(r1)
/* 80113308 00110268  D0 01 00 50 */	stfs f0, 0x50(r1)
/* 8011330C 0011026C  80 61 00 48 */	lwz r3, 0x48(r1)
/* 80113310 00110270  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80113314 00110274  90 65 00 34 */	stw r3, 0x34(r5)
/* 80113318 00110278  90 05 00 38 */	stw r0, 0x38(r5)
/* 8011331C 0011027C  80 01 00 50 */	lwz r0, 0x50(r1)
/* 80113320 00110280  90 05 00 3C */	stw r0, 0x3c(r5)
.L_80113324:
/* 80113324 00110284  38 60 00 01 */	li r3, 1
/* 80113328 00110288  38 21 00 58 */	addi r1, r1, 0x58
/* 8011332C 0011028C  4E 80 00 20 */	blr 
.endfn invoke__11SlimeEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl

.fn kill__11SlimeEffectFv, global
/* 80113330 00110290  7C 08 02 A6 */	mflr r0
/* 80113334 00110294  90 01 00 04 */	stw r0, 4(r1)
/* 80113338 00110298  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011333C 0011029C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80113340 001102A0  7C 7F 1B 78 */	mr r31, r3
/* 80113344 001102A4  80 83 00 0C */	lwz r4, 0xc(r3)
/* 80113348 001102A8  28 04 00 00 */	cmplwi r4, 0
/* 8011334C 001102AC  41 82 00 1C */	beq .L_80113368
/* 80113350 001102B0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80113354 001102B4  38 A0 00 00 */	li r5, 0
/* 80113358 001102B8  38 63 00 14 */	addi r3, r3, 0x14
/* 8011335C 001102BC  48 08 E2 69 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80113360 001102C0  38 00 00 00 */	li r0, 0
/* 80113364 001102C4  90 1F 00 0C */	stw r0, 0xc(r31)
.L_80113368:
/* 80113368 001102C8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011336C 001102CC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80113370 001102D0  38 21 00 18 */	addi r1, r1, 0x18
/* 80113374 001102D4  7C 08 03 A6 */	mtlr r0
/* 80113378 001102D8  4E 80 00 20 */	blr 
.endfn kill__11SlimeEffectFv

.fn __ct__11UtEffectMgrFv, global
/* 8011337C 001102DC  7C 08 02 A6 */	mflr r0
/* 80113380 001102E0  90 01 00 04 */	stw r0, 4(r1)
/* 80113384 001102E4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80113388 001102E8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011338C 001102EC  3B E3 00 00 */	addi r31, r3, 0
/* 80113390 001102F0  38 60 00 70 */	li r3, 0x70
/* 80113394 001102F4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80113398 001102F8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8011339C 001102FC  4B F3 3C 69 */	bl alloc__6SystemFUl
/* 801133A0 00110300  90 6D 31 14 */	stw r3, effects__11UtEffectMgr@sda21(r13)
/* 801133A4 00110304  38 60 00 0C */	li r3, 0xc
/* 801133A8 00110308  4B F3 3C 5D */	bl alloc__6SystemFUl
/* 801133AC 0011030C  7C 65 1B 79 */	or. r5, r3, r3
/* 801133B0 00110310  41 82 00 60 */	beq .L_80113410
/* 801133B4 00110314  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 801133B8 00110318  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 801133BC 0011031C  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 801133C0 00110320  90 03 00 00 */	stw r0, 0(r3)
/* 801133C4 00110324  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 801133C8 00110328  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 801133CC 0011032C  90 03 00 04 */	stw r0, 4(r3)
/* 801133D0 00110330  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 801133D4 00110334  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 801133D8 00110338  90 03 00 08 */	stw r0, 8(r3)
/* 801133DC 0011033C  38 E4 05 AC */	addi r7, r4, __vt__7KEffect@l
/* 801133E0 00110340  90 E3 00 00 */	stw r7, 0(r3)
/* 801133E4 00110344  38 07 00 0C */	addi r0, r7, 0xc
/* 801133E8 00110348  3C 80 80 2C */	lis r4, __vt__10GoalEffect@ha
/* 801133EC 0011034C  90 03 00 04 */	stw r0, 4(r3)
/* 801133F0 00110350  38 C4 2C 74 */	addi r6, r4, __vt__10GoalEffect@l
/* 801133F4 00110354  38 07 00 18 */	addi r0, r7, 0x18
/* 801133F8 00110358  90 03 00 08 */	stw r0, 8(r3)
/* 801133FC 0011035C  38 86 00 0C */	addi r4, r6, 0xc
/* 80113400 00110360  38 06 00 18 */	addi r0, r6, 0x18
/* 80113404 00110364  90 C3 00 00 */	stw r6, 0(r3)
/* 80113408 00110368  90 83 00 04 */	stw r4, 4(r3)
/* 8011340C 0011036C  90 03 00 08 */	stw r0, 8(r3)
.L_80113410:
/* 80113410 00110370  38 7F 00 00 */	addi r3, r31, 0
/* 80113414 00110374  38 80 00 00 */	li r4, 0
/* 80113418 00110378  48 00 0E B9 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 8011341C 0011037C  38 60 00 1C */	li r3, 0x1c
/* 80113420 00110380  4B F3 3B E5 */	bl alloc__6SystemFUl
/* 80113424 00110384  7C 7D 1B 79 */	or. r29, r3, r3
/* 80113428 00110388  41 82 00 80 */	beq .L_801134A8
/* 8011342C 0011038C  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 80113430 00110390  38 80 00 00 */	li r4, 0
/* 80113434 00110394  48 00 40 05 */	bl getNavi__7NaviMgrFi
/* 80113438 00110398  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 8011343C 0011039C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113440 001103A0  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113444 001103A4  90 1D 00 00 */	stw r0, 0(r29)
/* 80113448 001103A8  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 8011344C 001103AC  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113450 001103B0  90 1D 00 04 */	stw r0, 4(r29)
/* 80113454 001103B4  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113458 001103B8  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 8011345C 001103BC  90 1D 00 08 */	stw r0, 8(r29)
/* 80113460 001103C0  38 A4 05 AC */	addi r5, r4, __vt__7KEffect@l
/* 80113464 001103C4  90 BD 00 00 */	stw r5, 0(r29)
/* 80113468 001103C8  38 05 00 0C */	addi r0, r5, 0xc
/* 8011346C 001103CC  3C 80 80 2C */	lis r4, __vt__11NaviWhistle@ha
/* 80113470 001103D0  90 1D 00 04 */	stw r0, 4(r29)
/* 80113474 001103D4  38 C4 2C 08 */	addi r6, r4, __vt__11NaviWhistle@l
/* 80113478 001103D8  38 05 00 18 */	addi r0, r5, 0x18
/* 8011347C 001103DC  90 1D 00 08 */	stw r0, 8(r29)
/* 80113480 001103E0  38 A6 00 0C */	addi r5, r6, 0xc
/* 80113484 001103E4  38 86 00 18 */	addi r4, r6, 0x18
/* 80113488 001103E8  90 DD 00 00 */	stw r6, 0(r29)
/* 8011348C 001103EC  38 00 00 00 */	li r0, 0
/* 80113490 001103F0  90 BD 00 04 */	stw r5, 4(r29)
/* 80113494 001103F4  90 9D 00 08 */	stw r4, 8(r29)
/* 80113498 001103F8  90 7D 00 0C */	stw r3, 0xc(r29)
/* 8011349C 001103FC  90 1D 00 18 */	stw r0, 0x18(r29)
/* 801134A0 00110400  90 1D 00 14 */	stw r0, 0x14(r29)
/* 801134A4 00110404  90 1D 00 10 */	stw r0, 0x10(r29)
.L_801134A8:
/* 801134A8 00110408  38 7F 00 00 */	addi r3, r31, 0
/* 801134AC 0011040C  38 BD 00 00 */	addi r5, r29, 0
/* 801134B0 00110410  38 80 00 01 */	li r4, 1
/* 801134B4 00110414  48 00 0E 1D */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 801134B8 00110418  38 60 00 1C */	li r3, 0x1c
/* 801134BC 0011041C  4B F3 3B 49 */	bl alloc__6SystemFUl
/* 801134C0 00110420  7C 7D 1B 79 */	or. r29, r3, r3
/* 801134C4 00110424  41 82 00 80 */	beq .L_80113544
/* 801134C8 00110428  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 801134CC 0011042C  38 80 00 01 */	li r4, 1
/* 801134D0 00110430  48 00 3F 69 */	bl getNavi__7NaviMgrFi
/* 801134D4 00110434  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 801134D8 00110438  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 801134DC 0011043C  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 801134E0 00110440  90 1D 00 00 */	stw r0, 0(r29)
/* 801134E4 00110444  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 801134E8 00110448  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 801134EC 0011044C  90 1D 00 04 */	stw r0, 4(r29)
/* 801134F0 00110450  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 801134F4 00110454  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 801134F8 00110458  90 1D 00 08 */	stw r0, 8(r29)
/* 801134FC 0011045C  38 A4 05 AC */	addi r5, r4, __vt__7KEffect@l
/* 80113500 00110460  90 BD 00 00 */	stw r5, 0(r29)
/* 80113504 00110464  38 05 00 0C */	addi r0, r5, 0xc
/* 80113508 00110468  3C 80 80 2C */	lis r4, __vt__11NaviWhistle@ha
/* 8011350C 0011046C  90 1D 00 04 */	stw r0, 4(r29)
/* 80113510 00110470  38 C4 2C 08 */	addi r6, r4, __vt__11NaviWhistle@l
/* 80113514 00110474  38 05 00 18 */	addi r0, r5, 0x18
/* 80113518 00110478  90 1D 00 08 */	stw r0, 8(r29)
/* 8011351C 0011047C  38 A6 00 0C */	addi r5, r6, 0xc
/* 80113520 00110480  38 86 00 18 */	addi r4, r6, 0x18
/* 80113524 00110484  90 DD 00 00 */	stw r6, 0(r29)
/* 80113528 00110488  38 00 00 00 */	li r0, 0
/* 8011352C 0011048C  90 BD 00 04 */	stw r5, 4(r29)
/* 80113530 00110490  90 9D 00 08 */	stw r4, 8(r29)
/* 80113534 00110494  90 7D 00 0C */	stw r3, 0xc(r29)
/* 80113538 00110498  90 1D 00 18 */	stw r0, 0x18(r29)
/* 8011353C 0011049C  90 1D 00 14 */	stw r0, 0x14(r29)
/* 80113540 001104A0  90 1D 00 10 */	stw r0, 0x10(r29)
.L_80113544:
/* 80113544 001104A4  38 7F 00 00 */	addi r3, r31, 0
/* 80113548 001104A8  38 BD 00 00 */	addi r5, r29, 0
/* 8011354C 001104AC  38 80 00 02 */	li r4, 2
/* 80113550 001104B0  48 00 0D 81 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113554 001104B4  38 60 00 0C */	li r3, 0xc
/* 80113558 001104B8  4B F3 3A AD */	bl alloc__6SystemFUl
/* 8011355C 001104BC  7C 65 1B 79 */	or. r5, r3, r3
/* 80113560 001104C0  41 82 00 60 */	beq .L_801135C0
/* 80113564 001104C4  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113568 001104C8  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 8011356C 001104CC  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113570 001104D0  90 03 00 00 */	stw r0, 0(r3)
/* 80113574 001104D4  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113578 001104D8  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 8011357C 001104DC  90 03 00 04 */	stw r0, 4(r3)
/* 80113580 001104E0  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113584 001104E4  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113588 001104E8  90 03 00 08 */	stw r0, 8(r3)
/* 8011358C 001104EC  38 E4 05 AC */	addi r7, r4, __vt__7KEffect@l
/* 80113590 001104F0  90 E3 00 00 */	stw r7, 0(r3)
/* 80113594 001104F4  38 07 00 0C */	addi r0, r7, 0xc
/* 80113598 001104F8  3C 80 80 2C */	lis r4, __vt__15SmokeSoilEffect@ha
/* 8011359C 001104FC  90 03 00 04 */	stw r0, 4(r3)
/* 801135A0 00110500  38 C4 2B 9C */	addi r6, r4, __vt__15SmokeSoilEffect@l
/* 801135A4 00110504  38 07 00 18 */	addi r0, r7, 0x18
/* 801135A8 00110508  90 03 00 08 */	stw r0, 8(r3)
/* 801135AC 0011050C  38 86 00 0C */	addi r4, r6, 0xc
/* 801135B0 00110510  38 06 00 18 */	addi r0, r6, 0x18
/* 801135B4 00110514  90 C3 00 00 */	stw r6, 0(r3)
/* 801135B8 00110518  90 83 00 04 */	stw r4, 4(r3)
/* 801135BC 0011051C  90 03 00 08 */	stw r0, 8(r3)
.L_801135C0:
/* 801135C0 00110520  38 7F 00 00 */	addi r3, r31, 0
/* 801135C4 00110524  38 80 00 03 */	li r4, 3
/* 801135C8 00110528  48 00 0D 09 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 801135CC 0011052C  38 60 00 0C */	li r3, 0xc
/* 801135D0 00110530  4B F3 3A 35 */	bl alloc__6SystemFUl
/* 801135D4 00110534  7C 65 1B 79 */	or. r5, r3, r3
/* 801135D8 00110538  41 82 00 60 */	beq .L_80113638
/* 801135DC 0011053C  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 801135E0 00110540  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 801135E4 00110544  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 801135E8 00110548  90 03 00 00 */	stw r0, 0(r3)
/* 801135EC 0011054C  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 801135F0 00110550  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 801135F4 00110554  90 03 00 04 */	stw r0, 4(r3)
/* 801135F8 00110558  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 801135FC 0011055C  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113600 00110560  90 03 00 08 */	stw r0, 8(r3)
/* 80113604 00110564  38 E4 05 AC */	addi r7, r4, __vt__7KEffect@l
/* 80113608 00110568  90 E3 00 00 */	stw r7, 0(r3)
/* 8011360C 0011056C  38 07 00 0C */	addi r0, r7, 0xc
/* 80113610 00110570  3C 80 80 2C */	lis r4, __vt__16SmokeGrassEffect@ha
/* 80113614 00110574  90 03 00 04 */	stw r0, 4(r3)
/* 80113618 00110578  38 C4 2B 2C */	addi r6, r4, __vt__16SmokeGrassEffect@l
/* 8011361C 0011057C  38 07 00 18 */	addi r0, r7, 0x18
/* 80113620 00110580  90 03 00 08 */	stw r0, 8(r3)
/* 80113624 00110584  38 86 00 0C */	addi r4, r6, 0xc
/* 80113628 00110588  38 06 00 18 */	addi r0, r6, 0x18
/* 8011362C 0011058C  90 C3 00 00 */	stw r6, 0(r3)
/* 80113630 00110590  90 83 00 04 */	stw r4, 4(r3)
/* 80113634 00110594  90 03 00 08 */	stw r0, 8(r3)
.L_80113638:
/* 80113638 00110598  38 7F 00 00 */	addi r3, r31, 0
/* 8011363C 0011059C  38 80 00 05 */	li r4, 5
/* 80113640 001105A0  48 00 0C 91 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113644 001105A4  38 60 00 0C */	li r3, 0xc
/* 80113648 001105A8  4B F3 39 BD */	bl alloc__6SystemFUl
/* 8011364C 001105AC  7C 65 1B 79 */	or. r5, r3, r3
/* 80113650 001105B0  41 82 00 60 */	beq .L_801136B0
/* 80113654 001105B4  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113658 001105B8  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 8011365C 001105BC  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113660 001105C0  90 03 00 00 */	stw r0, 0(r3)
/* 80113664 001105C4  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113668 001105C8  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 8011366C 001105CC  90 03 00 04 */	stw r0, 4(r3)
/* 80113670 001105D0  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113674 001105D4  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113678 001105D8  90 03 00 08 */	stw r0, 8(r3)
/* 8011367C 001105DC  38 E4 05 AC */	addi r7, r4, __vt__7KEffect@l
/* 80113680 001105E0  90 E3 00 00 */	stw r7, 0(r3)
/* 80113684 001105E4  38 07 00 0C */	addi r0, r7, 0xc
/* 80113688 001105E8  3C 80 80 2C */	lis r4, __vt__15SmokeRockEffect@ha
/* 8011368C 001105EC  90 03 00 04 */	stw r0, 4(r3)
/* 80113690 001105F0  38 C4 2A B8 */	addi r6, r4, __vt__15SmokeRockEffect@l
/* 80113694 001105F4  38 07 00 18 */	addi r0, r7, 0x18
/* 80113698 001105F8  90 03 00 08 */	stw r0, 8(r3)
/* 8011369C 001105FC  38 86 00 0C */	addi r4, r6, 0xc
/* 801136A0 00110600  38 06 00 18 */	addi r0, r6, 0x18
/* 801136A4 00110604  90 C3 00 00 */	stw r6, 0(r3)
/* 801136A8 00110608  90 83 00 04 */	stw r4, 4(r3)
/* 801136AC 0011060C  90 03 00 08 */	stw r0, 8(r3)
.L_801136B0:
/* 801136B0 00110610  38 7F 00 00 */	addi r3, r31, 0
/* 801136B4 00110614  38 80 00 04 */	li r4, 4
/* 801136B8 00110618  48 00 0C 19 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 801136BC 0011061C  38 60 00 0C */	li r3, 0xc
/* 801136C0 00110620  4B F3 39 45 */	bl alloc__6SystemFUl
/* 801136C4 00110624  7C 65 1B 79 */	or. r5, r3, r3
/* 801136C8 00110628  41 82 00 60 */	beq .L_80113728
/* 801136CC 0011062C  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 801136D0 00110630  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 801136D4 00110634  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 801136D8 00110638  90 03 00 00 */	stw r0, 0(r3)
/* 801136DC 0011063C  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 801136E0 00110640  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 801136E4 00110644  90 03 00 04 */	stw r0, 4(r3)
/* 801136E8 00110648  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 801136EC 0011064C  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 801136F0 00110650  90 03 00 08 */	stw r0, 8(r3)
/* 801136F4 00110654  38 E4 05 AC */	addi r7, r4, __vt__7KEffect@l
/* 801136F8 00110658  90 E3 00 00 */	stw r7, 0(r3)
/* 801136FC 0011065C  38 07 00 0C */	addi r0, r7, 0xc
/* 80113700 00110660  3C 80 80 2C */	lis r4, __vt__15SmokeTreeEffect@ha
/* 80113704 00110664  90 03 00 04 */	stw r0, 4(r3)
/* 80113708 00110668  38 C4 2A 48 */	addi r6, r4, __vt__15SmokeTreeEffect@l
/* 8011370C 0011066C  38 07 00 18 */	addi r0, r7, 0x18
/* 80113710 00110670  90 03 00 08 */	stw r0, 8(r3)
/* 80113714 00110674  38 86 00 0C */	addi r4, r6, 0xc
/* 80113718 00110678  38 06 00 18 */	addi r0, r6, 0x18
/* 8011371C 0011067C  90 C3 00 00 */	stw r6, 0(r3)
/* 80113720 00110680  90 83 00 04 */	stw r4, 4(r3)
/* 80113724 00110684  90 03 00 08 */	stw r0, 8(r3)
.L_80113728:
/* 80113728 00110688  38 7F 00 00 */	addi r3, r31, 0
/* 8011372C 0011068C  38 80 00 06 */	li r4, 6
/* 80113730 00110690  48 00 0B A1 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113734 00110694  38 60 00 18 */	li r3, 0x18
/* 80113738 00110698  4B F3 38 CD */	bl alloc__6SystemFUl
/* 8011373C 0011069C  7C 7E 1B 79 */	or. r30, r3, r3
/* 80113740 001106A0  41 82 00 C0 */	beq .L_80113800
/* 80113744 001106A4  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 80113748 001106A8  38 80 00 00 */	li r4, 0
/* 8011374C 001106AC  48 00 3C ED */	bl getNavi__7NaviMgrFi
/* 80113750 001106B0  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113754 001106B4  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113758 001106B8  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 8011375C 001106BC  90 1E 00 00 */	stw r0, 0(r30)
/* 80113760 001106C0  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113764 001106C4  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113768 001106C8  90 1E 00 04 */	stw r0, 4(r30)
/* 8011376C 001106CC  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113770 001106D0  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113774 001106D4  90 1E 00 08 */	stw r0, 8(r30)
/* 80113778 001106D8  38 A4 05 AC */	addi r5, r4, __vt__7KEffect@l
/* 8011377C 001106DC  90 BE 00 00 */	stw r5, 0(r30)
/* 80113780 001106E0  38 05 00 0C */	addi r0, r5, 0xc
/* 80113784 001106E4  3C 80 80 2C */	lis r4, __vt__7NaviFue@ha
/* 80113788 001106E8  90 1E 00 04 */	stw r0, 4(r30)
/* 8011378C 001106EC  38 05 00 18 */	addi r0, r5, 0x18
/* 80113790 001106F0  38 C4 29 D8 */	addi r6, r4, __vt__7NaviFue@l
/* 80113794 001106F4  90 1E 00 08 */	stw r0, 8(r30)
/* 80113798 001106F8  38 A6 00 0C */	addi r5, r6, 0xc
/* 8011379C 001106FC  38 86 00 18 */	addi r4, r6, 0x18
/* 801137A0 00110700  90 DE 00 00 */	stw r6, 0(r30)
/* 801137A4 00110704  3B A3 00 00 */	addi r29, r3, 0
/* 801137A8 00110708  38 00 00 18 */	li r0, 0x18
/* 801137AC 0011070C  90 BE 00 04 */	stw r5, 4(r30)
/* 801137B0 00110710  90 9E 00 08 */	stw r4, 8(r30)
/* 801137B4 00110714  93 BE 00 0C */	stw r29, 0xc(r30)
/* 801137B8 00110718  90 1E 00 10 */	stw r0, 0x10(r30)
/* 801137BC 0011071C  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 801137C0 00110720  54 03 10 3A */	slwi r3, r0, 2
/* 801137C4 00110724  4B F3 38 41 */	bl alloc__6SystemFUl
/* 801137C8 00110728  28 1D 00 00 */	cmplwi r29, 0
/* 801137CC 0011072C  90 7E 00 14 */	stw r3, 0x14(r30)
/* 801137D0 00110730  41 82 00 30 */	beq .L_80113800
/* 801137D4 00110734  38 A0 00 00 */	li r5, 0
/* 801137D8 00110738  38 C5 00 00 */	addi r6, r5, 0
/* 801137DC 0011073C  38 85 00 00 */	addi r4, r5, 0
/* 801137E0 00110740  48 00 00 14 */	b .L_801137F4
.L_801137E4:
/* 801137E4 00110744  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 801137E8 00110748  38 A5 00 01 */	addi r5, r5, 1
/* 801137EC 0011074C  7C 83 31 2E */	stwx r4, r3, r6
/* 801137F0 00110750  38 C6 00 04 */	addi r6, r6, 4
.L_801137F4:
/* 801137F4 00110754  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 801137F8 00110758  7C 05 00 00 */	cmpw r5, r0
/* 801137FC 0011075C  41 80 FF E8 */	blt .L_801137E4
.L_80113800:
/* 80113800 00110760  38 7F 00 00 */	addi r3, r31, 0
/* 80113804 00110764  38 BE 00 00 */	addi r5, r30, 0
/* 80113808 00110768  38 80 00 07 */	li r4, 7
/* 8011380C 0011076C  48 00 0A C5 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113810 00110770  38 60 00 14 */	li r3, 0x14
/* 80113814 00110774  4B F3 37 F1 */	bl alloc__6SystemFUl
/* 80113818 00110778  7C 65 1B 79 */	or. r5, r3, r3
/* 8011381C 0011077C  41 82 00 70 */	beq .L_8011388C
/* 80113820 00110780  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113824 00110784  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113828 00110788  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 8011382C 0011078C  90 03 00 00 */	stw r0, 0(r3)
/* 80113830 00110790  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113834 00110794  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113838 00110798  90 03 00 04 */	stw r0, 4(r3)
/* 8011383C 0011079C  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113840 001107A0  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113844 001107A4  90 03 00 08 */	stw r0, 8(r3)
/* 80113848 001107A8  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 8011384C 001107AC  90 C3 00 00 */	stw r6, 0(r3)
/* 80113850 001107B0  38 06 00 0C */	addi r0, r6, 0xc
/* 80113854 001107B4  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80113858 001107B8  90 03 00 04 */	stw r0, 4(r3)
/* 8011385C 001107BC  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80113860 001107C0  38 06 00 18 */	addi r0, r6, 0x18
/* 80113864 001107C4  90 03 00 08 */	stw r0, 8(r3)
/* 80113868 001107C8  38 E4 00 0C */	addi r7, r4, 0xc
/* 8011386C 001107CC  38 C4 00 18 */	addi r6, r4, 0x18
/* 80113870 001107D0  90 83 00 00 */	stw r4, 0(r3)
/* 80113874 001107D4  38 80 00 2D */	li r4, 0x2d
/* 80113878 001107D8  38 00 00 00 */	li r0, 0
/* 8011387C 001107DC  90 E3 00 04 */	stw r7, 4(r3)
/* 80113880 001107E0  90 C3 00 08 */	stw r6, 8(r3)
/* 80113884 001107E4  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113888 001107E8  90 03 00 10 */	stw r0, 0x10(r3)
.L_8011388C:
/* 8011388C 001107EC  38 7F 00 00 */	addi r3, r31, 0
/* 80113890 001107F0  38 80 00 09 */	li r4, 9
/* 80113894 001107F4  48 00 0A 3D */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113898 001107F8  38 60 00 14 */	li r3, 0x14
/* 8011389C 001107FC  4B F3 37 69 */	bl alloc__6SystemFUl
/* 801138A0 00110800  7C 65 1B 79 */	or. r5, r3, r3
/* 801138A4 00110804  41 82 00 70 */	beq .L_80113914
/* 801138A8 00110808  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 801138AC 0011080C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 801138B0 00110810  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 801138B4 00110814  90 03 00 00 */	stw r0, 0(r3)
/* 801138B8 00110818  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 801138BC 0011081C  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 801138C0 00110820  90 03 00 04 */	stw r0, 4(r3)
/* 801138C4 00110824  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 801138C8 00110828  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 801138CC 0011082C  90 03 00 08 */	stw r0, 8(r3)
/* 801138D0 00110830  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 801138D4 00110834  90 C3 00 00 */	stw r6, 0(r3)
/* 801138D8 00110838  38 06 00 0C */	addi r0, r6, 0xc
/* 801138DC 0011083C  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 801138E0 00110840  90 03 00 04 */	stw r0, 4(r3)
/* 801138E4 00110844  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 801138E8 00110848  38 06 00 18 */	addi r0, r6, 0x18
/* 801138EC 0011084C  90 03 00 08 */	stw r0, 8(r3)
/* 801138F0 00110850  38 E4 00 0C */	addi r7, r4, 0xc
/* 801138F4 00110854  38 C4 00 18 */	addi r6, r4, 0x18
/* 801138F8 00110858  90 83 00 00 */	stw r4, 0(r3)
/* 801138FC 0011085C  38 80 00 2E */	li r4, 0x2e
/* 80113900 00110860  38 00 00 00 */	li r0, 0
/* 80113904 00110864  90 E3 00 04 */	stw r7, 4(r3)
/* 80113908 00110868  90 C3 00 08 */	stw r6, 8(r3)
/* 8011390C 0011086C  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113910 00110870  90 03 00 10 */	stw r0, 0x10(r3)
.L_80113914:
/* 80113914 00110874  38 7F 00 00 */	addi r3, r31, 0
/* 80113918 00110878  38 80 00 0A */	li r4, 0xa
/* 8011391C 0011087C  48 00 09 B5 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113920 00110880  38 60 00 14 */	li r3, 0x14
/* 80113924 00110884  4B F3 36 E1 */	bl alloc__6SystemFUl
/* 80113928 00110888  7C 65 1B 79 */	or. r5, r3, r3
/* 8011392C 0011088C  41 82 00 70 */	beq .L_8011399C
/* 80113930 00110890  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113934 00110894  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113938 00110898  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 8011393C 0011089C  90 03 00 00 */	stw r0, 0(r3)
/* 80113940 001108A0  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113944 001108A4  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113948 001108A8  90 03 00 04 */	stw r0, 4(r3)
/* 8011394C 001108AC  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113950 001108B0  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113954 001108B4  90 03 00 08 */	stw r0, 8(r3)
/* 80113958 001108B8  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 8011395C 001108BC  90 C3 00 00 */	stw r6, 0(r3)
/* 80113960 001108C0  38 06 00 0C */	addi r0, r6, 0xc
/* 80113964 001108C4  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80113968 001108C8  90 03 00 04 */	stw r0, 4(r3)
/* 8011396C 001108CC  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80113970 001108D0  38 06 00 18 */	addi r0, r6, 0x18
/* 80113974 001108D4  90 03 00 08 */	stw r0, 8(r3)
/* 80113978 001108D8  38 E4 00 0C */	addi r7, r4, 0xc
/* 8011397C 001108DC  38 C4 00 18 */	addi r6, r4, 0x18
/* 80113980 001108E0  90 83 00 00 */	stw r4, 0(r3)
/* 80113984 001108E4  38 80 00 DE */	li r4, 0xde
/* 80113988 001108E8  38 00 00 00 */	li r0, 0
/* 8011398C 001108EC  90 E3 00 04 */	stw r7, 4(r3)
/* 80113990 001108F0  90 C3 00 08 */	stw r6, 8(r3)
/* 80113994 001108F4  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113998 001108F8  90 03 00 10 */	stw r0, 0x10(r3)
.L_8011399C:
/* 8011399C 001108FC  38 7F 00 00 */	addi r3, r31, 0
/* 801139A0 00110900  38 80 00 0B */	li r4, 0xb
/* 801139A4 00110904  48 00 09 2D */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 801139A8 00110908  38 60 00 14 */	li r3, 0x14
/* 801139AC 0011090C  4B F3 36 59 */	bl alloc__6SystemFUl
/* 801139B0 00110910  7C 65 1B 79 */	or. r5, r3, r3
/* 801139B4 00110914  41 82 00 70 */	beq .L_80113A24
/* 801139B8 00110918  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 801139BC 0011091C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 801139C0 00110920  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 801139C4 00110924  90 03 00 00 */	stw r0, 0(r3)
/* 801139C8 00110928  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 801139CC 0011092C  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 801139D0 00110930  90 03 00 04 */	stw r0, 4(r3)
/* 801139D4 00110934  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 801139D8 00110938  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 801139DC 0011093C  90 03 00 08 */	stw r0, 8(r3)
/* 801139E0 00110940  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 801139E4 00110944  90 C3 00 00 */	stw r6, 0(r3)
/* 801139E8 00110948  38 06 00 0C */	addi r0, r6, 0xc
/* 801139EC 0011094C  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 801139F0 00110950  90 03 00 04 */	stw r0, 4(r3)
/* 801139F4 00110954  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 801139F8 00110958  38 06 00 18 */	addi r0, r6, 0x18
/* 801139FC 0011095C  90 03 00 08 */	stw r0, 8(r3)
/* 80113A00 00110960  38 E4 00 0C */	addi r7, r4, 0xc
/* 80113A04 00110964  38 C4 00 18 */	addi r6, r4, 0x18
/* 80113A08 00110968  90 83 00 00 */	stw r4, 0(r3)
/* 80113A0C 0011096C  38 80 00 DF */	li r4, 0xdf
/* 80113A10 00110970  38 00 00 00 */	li r0, 0
/* 80113A14 00110974  90 E3 00 04 */	stw r7, 4(r3)
/* 80113A18 00110978  90 C3 00 08 */	stw r6, 8(r3)
/* 80113A1C 0011097C  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113A20 00110980  90 03 00 10 */	stw r0, 0x10(r3)
.L_80113A24:
/* 80113A24 00110984  38 7F 00 00 */	addi r3, r31, 0
/* 80113A28 00110988  38 80 00 0C */	li r4, 0xc
/* 80113A2C 0011098C  48 00 08 A5 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113A30 00110990  38 60 00 14 */	li r3, 0x14
/* 80113A34 00110994  4B F3 35 D1 */	bl alloc__6SystemFUl
/* 80113A38 00110998  7C 65 1B 79 */	or. r5, r3, r3
/* 80113A3C 0011099C  41 82 00 70 */	beq .L_80113AAC
/* 80113A40 001109A0  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113A44 001109A4  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113A48 001109A8  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113A4C 001109AC  90 03 00 00 */	stw r0, 0(r3)
/* 80113A50 001109B0  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113A54 001109B4  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113A58 001109B8  90 03 00 04 */	stw r0, 4(r3)
/* 80113A5C 001109BC  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113A60 001109C0  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113A64 001109C4  90 03 00 08 */	stw r0, 8(r3)
/* 80113A68 001109C8  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80113A6C 001109CC  90 C3 00 00 */	stw r6, 0(r3)
/* 80113A70 001109D0  38 06 00 0C */	addi r0, r6, 0xc
/* 80113A74 001109D4  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80113A78 001109D8  90 03 00 04 */	stw r0, 4(r3)
/* 80113A7C 001109DC  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80113A80 001109E0  38 06 00 18 */	addi r0, r6, 0x18
/* 80113A84 001109E4  90 03 00 08 */	stw r0, 8(r3)
/* 80113A88 001109E8  38 E4 00 0C */	addi r7, r4, 0xc
/* 80113A8C 001109EC  38 C4 00 18 */	addi r6, r4, 0x18
/* 80113A90 001109F0  90 83 00 00 */	stw r4, 0(r3)
/* 80113A94 001109F4  38 80 00 D2 */	li r4, 0xd2
/* 80113A98 001109F8  38 00 00 00 */	li r0, 0
/* 80113A9C 001109FC  90 E3 00 04 */	stw r7, 4(r3)
/* 80113AA0 00110A00  90 C3 00 08 */	stw r6, 8(r3)
/* 80113AA4 00110A04  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113AA8 00110A08  90 03 00 10 */	stw r0, 0x10(r3)
.L_80113AAC:
/* 80113AAC 00110A0C  38 7F 00 00 */	addi r3, r31, 0
/* 80113AB0 00110A10  38 80 00 0D */	li r4, 0xd
/* 80113AB4 00110A14  48 00 08 1D */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113AB8 00110A18  38 60 00 14 */	li r3, 0x14
/* 80113ABC 00110A1C  4B F3 35 49 */	bl alloc__6SystemFUl
/* 80113AC0 00110A20  7C 65 1B 79 */	or. r5, r3, r3
/* 80113AC4 00110A24  41 82 00 70 */	beq .L_80113B34
/* 80113AC8 00110A28  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113ACC 00110A2C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113AD0 00110A30  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113AD4 00110A34  90 03 00 00 */	stw r0, 0(r3)
/* 80113AD8 00110A38  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113ADC 00110A3C  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113AE0 00110A40  90 03 00 04 */	stw r0, 4(r3)
/* 80113AE4 00110A44  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113AE8 00110A48  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113AEC 00110A4C  90 03 00 08 */	stw r0, 8(r3)
/* 80113AF0 00110A50  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80113AF4 00110A54  90 C3 00 00 */	stw r6, 0(r3)
/* 80113AF8 00110A58  38 06 00 0C */	addi r0, r6, 0xc
/* 80113AFC 00110A5C  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80113B00 00110A60  90 03 00 04 */	stw r0, 4(r3)
/* 80113B04 00110A64  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80113B08 00110A68  38 06 00 18 */	addi r0, r6, 0x18
/* 80113B0C 00110A6C  90 03 00 08 */	stw r0, 8(r3)
/* 80113B10 00110A70  38 E4 00 0C */	addi r7, r4, 0xc
/* 80113B14 00110A74  38 C4 00 18 */	addi r6, r4, 0x18
/* 80113B18 00110A78  90 83 00 00 */	stw r4, 0(r3)
/* 80113B1C 00110A7C  38 80 00 D1 */	li r4, 0xd1
/* 80113B20 00110A80  38 00 00 00 */	li r0, 0
/* 80113B24 00110A84  90 E3 00 04 */	stw r7, 4(r3)
/* 80113B28 00110A88  90 C3 00 08 */	stw r6, 8(r3)
/* 80113B2C 00110A8C  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113B30 00110A90  90 03 00 10 */	stw r0, 0x10(r3)
.L_80113B34:
/* 80113B34 00110A94  38 7F 00 00 */	addi r3, r31, 0
/* 80113B38 00110A98  38 80 00 0E */	li r4, 0xe
/* 80113B3C 00110A9C  48 00 07 95 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113B40 00110AA0  38 60 00 14 */	li r3, 0x14
/* 80113B44 00110AA4  4B F3 34 C1 */	bl alloc__6SystemFUl
/* 80113B48 00110AA8  7C 65 1B 79 */	or. r5, r3, r3
/* 80113B4C 00110AAC  41 82 00 70 */	beq .L_80113BBC
/* 80113B50 00110AB0  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113B54 00110AB4  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113B58 00110AB8  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113B5C 00110ABC  90 03 00 00 */	stw r0, 0(r3)
/* 80113B60 00110AC0  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113B64 00110AC4  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113B68 00110AC8  90 03 00 04 */	stw r0, 4(r3)
/* 80113B6C 00110ACC  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113B70 00110AD0  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113B74 00110AD4  90 03 00 08 */	stw r0, 8(r3)
/* 80113B78 00110AD8  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80113B7C 00110ADC  90 C3 00 00 */	stw r6, 0(r3)
/* 80113B80 00110AE0  38 06 00 0C */	addi r0, r6, 0xc
/* 80113B84 00110AE4  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80113B88 00110AE8  90 03 00 04 */	stw r0, 4(r3)
/* 80113B8C 00110AEC  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80113B90 00110AF0  38 06 00 18 */	addi r0, r6, 0x18
/* 80113B94 00110AF4  90 03 00 08 */	stw r0, 8(r3)
/* 80113B98 00110AF8  38 E4 00 0C */	addi r7, r4, 0xc
/* 80113B9C 00110AFC  38 C4 00 18 */	addi r6, r4, 0x18
/* 80113BA0 00110B00  90 83 00 00 */	stw r4, 0(r3)
/* 80113BA4 00110B04  38 80 00 DD */	li r4, 0xdd
/* 80113BA8 00110B08  38 00 00 00 */	li r0, 0
/* 80113BAC 00110B0C  90 E3 00 04 */	stw r7, 4(r3)
/* 80113BB0 00110B10  90 C3 00 08 */	stw r6, 8(r3)
/* 80113BB4 00110B14  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113BB8 00110B18  90 03 00 10 */	stw r0, 0x10(r3)
.L_80113BBC:
/* 80113BBC 00110B1C  38 7F 00 00 */	addi r3, r31, 0
/* 80113BC0 00110B20  38 80 00 0F */	li r4, 0xf
/* 80113BC4 00110B24  48 00 07 0D */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113BC8 00110B28  38 60 00 14 */	li r3, 0x14
/* 80113BCC 00110B2C  4B F3 34 39 */	bl alloc__6SystemFUl
/* 80113BD0 00110B30  7C 65 1B 79 */	or. r5, r3, r3
/* 80113BD4 00110B34  41 82 00 70 */	beq .L_80113C44
/* 80113BD8 00110B38  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113BDC 00110B3C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113BE0 00110B40  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113BE4 00110B44  90 03 00 00 */	stw r0, 0(r3)
/* 80113BE8 00110B48  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113BEC 00110B4C  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113BF0 00110B50  90 03 00 04 */	stw r0, 4(r3)
/* 80113BF4 00110B54  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113BF8 00110B58  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113BFC 00110B5C  90 03 00 08 */	stw r0, 8(r3)
/* 80113C00 00110B60  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80113C04 00110B64  90 C3 00 00 */	stw r6, 0(r3)
/* 80113C08 00110B68  38 06 00 0C */	addi r0, r6, 0xc
/* 80113C0C 00110B6C  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80113C10 00110B70  90 03 00 04 */	stw r0, 4(r3)
/* 80113C14 00110B74  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80113C18 00110B78  38 06 00 18 */	addi r0, r6, 0x18
/* 80113C1C 00110B7C  90 03 00 08 */	stw r0, 8(r3)
/* 80113C20 00110B80  38 E4 00 0C */	addi r7, r4, 0xc
/* 80113C24 00110B84  38 C4 00 18 */	addi r6, r4, 0x18
/* 80113C28 00110B88  90 83 00 00 */	stw r4, 0(r3)
/* 80113C2C 00110B8C  38 80 00 DC */	li r4, 0xdc
/* 80113C30 00110B90  38 00 00 00 */	li r0, 0
/* 80113C34 00110B94  90 E3 00 04 */	stw r7, 4(r3)
/* 80113C38 00110B98  90 C3 00 08 */	stw r6, 8(r3)
/* 80113C3C 00110B9C  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113C40 00110BA0  90 03 00 10 */	stw r0, 0x10(r3)
.L_80113C44:
/* 80113C44 00110BA4  38 7F 00 00 */	addi r3, r31, 0
/* 80113C48 00110BA8  38 80 00 10 */	li r4, 0x10
/* 80113C4C 00110BAC  48 00 06 85 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113C50 00110BB0  38 60 00 14 */	li r3, 0x14
/* 80113C54 00110BB4  4B F3 33 B1 */	bl alloc__6SystemFUl
/* 80113C58 00110BB8  7C 65 1B 79 */	or. r5, r3, r3
/* 80113C5C 00110BBC  41 82 00 70 */	beq .L_80113CCC
/* 80113C60 00110BC0  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113C64 00110BC4  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113C68 00110BC8  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113C6C 00110BCC  90 03 00 00 */	stw r0, 0(r3)
/* 80113C70 00110BD0  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113C74 00110BD4  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113C78 00110BD8  90 03 00 04 */	stw r0, 4(r3)
/* 80113C7C 00110BDC  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113C80 00110BE0  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113C84 00110BE4  90 03 00 08 */	stw r0, 8(r3)
/* 80113C88 00110BE8  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80113C8C 00110BEC  90 C3 00 00 */	stw r6, 0(r3)
/* 80113C90 00110BF0  38 06 00 0C */	addi r0, r6, 0xc
/* 80113C94 00110BF4  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80113C98 00110BF8  90 03 00 04 */	stw r0, 4(r3)
/* 80113C9C 00110BFC  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80113CA0 00110C00  38 06 00 18 */	addi r0, r6, 0x18
/* 80113CA4 00110C04  90 03 00 08 */	stw r0, 8(r3)
/* 80113CA8 00110C08  38 E4 00 0C */	addi r7, r4, 0xc
/* 80113CAC 00110C0C  38 C4 00 18 */	addi r6, r4, 0x18
/* 80113CB0 00110C10  90 83 00 00 */	stw r4, 0(r3)
/* 80113CB4 00110C14  38 80 00 0F */	li r4, 0xf
/* 80113CB8 00110C18  38 00 00 00 */	li r0, 0
/* 80113CBC 00110C1C  90 E3 00 04 */	stw r7, 4(r3)
/* 80113CC0 00110C20  90 C3 00 08 */	stw r6, 8(r3)
/* 80113CC4 00110C24  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113CC8 00110C28  90 03 00 10 */	stw r0, 0x10(r3)
.L_80113CCC:
/* 80113CCC 00110C2C  38 7F 00 00 */	addi r3, r31, 0
/* 80113CD0 00110C30  38 80 00 11 */	li r4, 0x11
/* 80113CD4 00110C34  48 00 05 FD */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113CD8 00110C38  38 60 00 14 */	li r3, 0x14
/* 80113CDC 00110C3C  4B F3 33 29 */	bl alloc__6SystemFUl
/* 80113CE0 00110C40  7C 65 1B 79 */	or. r5, r3, r3
/* 80113CE4 00110C44  41 82 00 70 */	beq .L_80113D54
/* 80113CE8 00110C48  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113CEC 00110C4C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113CF0 00110C50  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113CF4 00110C54  90 03 00 00 */	stw r0, 0(r3)
/* 80113CF8 00110C58  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113CFC 00110C5C  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113D00 00110C60  90 03 00 04 */	stw r0, 4(r3)
/* 80113D04 00110C64  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113D08 00110C68  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113D0C 00110C6C  90 03 00 08 */	stw r0, 8(r3)
/* 80113D10 00110C70  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80113D14 00110C74  90 C3 00 00 */	stw r6, 0(r3)
/* 80113D18 00110C78  38 06 00 0C */	addi r0, r6, 0xc
/* 80113D1C 00110C7C  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80113D20 00110C80  90 03 00 04 */	stw r0, 4(r3)
/* 80113D24 00110C84  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80113D28 00110C88  38 06 00 18 */	addi r0, r6, 0x18
/* 80113D2C 00110C8C  90 03 00 08 */	stw r0, 8(r3)
/* 80113D30 00110C90  38 E4 00 0C */	addi r7, r4, 0xc
/* 80113D34 00110C94  38 C4 00 18 */	addi r6, r4, 0x18
/* 80113D38 00110C98  90 83 00 00 */	stw r4, 0(r3)
/* 80113D3C 00110C9C  38 80 00 0E */	li r4, 0xe
/* 80113D40 00110CA0  38 00 00 00 */	li r0, 0
/* 80113D44 00110CA4  90 E3 00 04 */	stw r7, 4(r3)
/* 80113D48 00110CA8  90 C3 00 08 */	stw r6, 8(r3)
/* 80113D4C 00110CAC  90 83 00 0C */	stw r4, 0xc(r3)
/* 80113D50 00110CB0  90 03 00 10 */	stw r0, 0x10(r3)
.L_80113D54:
/* 80113D54 00110CB4  38 7F 00 00 */	addi r3, r31, 0
/* 80113D58 00110CB8  38 80 00 12 */	li r4, 0x12
/* 80113D5C 00110CBC  48 00 05 75 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113D60 00110CC0  38 60 00 0C */	li r3, 0xc
/* 80113D64 00110CC4  4B F3 32 A1 */	bl alloc__6SystemFUl
/* 80113D68 00110CC8  7C 65 1B 79 */	or. r5, r3, r3
/* 80113D6C 00110CCC  41 82 00 60 */	beq .L_80113DCC
/* 80113D70 00110CD0  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113D74 00110CD4  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113D78 00110CD8  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113D7C 00110CDC  90 03 00 00 */	stw r0, 0(r3)
/* 80113D80 00110CE0  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113D84 00110CE4  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113D88 00110CE8  90 03 00 04 */	stw r0, 4(r3)
/* 80113D8C 00110CEC  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113D90 00110CF0  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113D94 00110CF4  90 03 00 08 */	stw r0, 8(r3)
/* 80113D98 00110CF8  38 E4 05 AC */	addi r7, r4, __vt__7KEffect@l
/* 80113D9C 00110CFC  90 E3 00 00 */	stw r7, 0(r3)
/* 80113DA0 00110D00  38 07 00 0C */	addi r0, r7, 0xc
/* 80113DA4 00110D04  3C 80 80 2C */	lis r4, __vt__10BombEffect@ha
/* 80113DA8 00110D08  90 03 00 04 */	stw r0, 4(r3)
/* 80113DAC 00110D0C  38 C4 29 08 */	addi r6, r4, __vt__10BombEffect@l
/* 80113DB0 00110D10  38 07 00 18 */	addi r0, r7, 0x18
/* 80113DB4 00110D14  90 03 00 08 */	stw r0, 8(r3)
/* 80113DB8 00110D18  38 86 00 0C */	addi r4, r6, 0xc
/* 80113DBC 00110D1C  38 06 00 18 */	addi r0, r6, 0x18
/* 80113DC0 00110D20  90 C3 00 00 */	stw r6, 0(r3)
/* 80113DC4 00110D24  90 83 00 04 */	stw r4, 4(r3)
/* 80113DC8 00110D28  90 03 00 08 */	stw r0, 8(r3)
.L_80113DCC:
/* 80113DCC 00110D2C  38 7F 00 00 */	addi r3, r31, 0
/* 80113DD0 00110D30  38 80 00 13 */	li r4, 0x13
/* 80113DD4 00110D34  48 00 04 FD */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113DD8 00110D38  38 60 00 0C */	li r3, 0xc
/* 80113DDC 00110D3C  4B F3 32 29 */	bl alloc__6SystemFUl
/* 80113DE0 00110D40  7C 65 1B 79 */	or. r5, r3, r3
/* 80113DE4 00110D44  41 82 00 60 */	beq .L_80113E44
/* 80113DE8 00110D48  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113DEC 00110D4C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113DF0 00110D50  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113DF4 00110D54  90 03 00 00 */	stw r0, 0(r3)
/* 80113DF8 00110D58  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113DFC 00110D5C  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113E00 00110D60  90 03 00 04 */	stw r0, 4(r3)
/* 80113E04 00110D64  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113E08 00110D68  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113E0C 00110D6C  90 03 00 08 */	stw r0, 8(r3)
/* 80113E10 00110D70  38 E4 05 AC */	addi r7, r4, __vt__7KEffect@l
/* 80113E14 00110D74  90 E3 00 00 */	stw r7, 0(r3)
/* 80113E18 00110D78  38 07 00 0C */	addi r0, r7, 0xc
/* 80113E1C 00110D7C  3C 80 80 2C */	lis r4, __vt__15BombEffectLight@ha
/* 80113E20 00110D80  90 03 00 04 */	stw r0, 4(r3)
/* 80113E24 00110D84  38 C4 28 9C */	addi r6, r4, __vt__15BombEffectLight@l
/* 80113E28 00110D88  38 07 00 18 */	addi r0, r7, 0x18
/* 80113E2C 00110D8C  90 03 00 08 */	stw r0, 8(r3)
/* 80113E30 00110D90  38 86 00 0C */	addi r4, r6, 0xc
/* 80113E34 00110D94  38 06 00 18 */	addi r0, r6, 0x18
/* 80113E38 00110D98  90 C3 00 00 */	stw r6, 0(r3)
/* 80113E3C 00110D9C  90 83 00 04 */	stw r4, 4(r3)
/* 80113E40 00110DA0  90 03 00 08 */	stw r0, 8(r3)
.L_80113E44:
/* 80113E44 00110DA4  38 7F 00 00 */	addi r3, r31, 0
/* 80113E48 00110DA8  38 80 00 14 */	li r4, 0x14
/* 80113E4C 00110DAC  48 00 04 85 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113E50 00110DB0  38 60 00 34 */	li r3, 0x34
/* 80113E54 00110DB4  4B F3 31 B1 */	bl alloc__6SystemFUl
/* 80113E58 00110DB8  7C 65 1B 79 */	or. r5, r3, r3
/* 80113E5C 00110DBC  41 82 00 B4 */	beq .L_80113F10
/* 80113E60 00110DC0  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113E64 00110DC4  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113E68 00110DC8  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113E6C 00110DCC  90 03 00 00 */	stw r0, 0(r3)
/* 80113E70 00110DD0  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113E74 00110DD4  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113E78 00110DD8  90 03 00 04 */	stw r0, 4(r3)
/* 80113E7C 00110DDC  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113E80 00110DE0  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113E84 00110DE4  90 03 00 08 */	stw r0, 8(r3)
/* 80113E88 00110DE8  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80113E8C 00110DEC  90 C3 00 00 */	stw r6, 0(r3)
/* 80113E90 00110DF0  38 06 00 0C */	addi r0, r6, 0xc
/* 80113E94 00110DF4  3C 80 80 2C */	lis r4, __vt__15WhistleTemplate@ha
/* 80113E98 00110DF8  90 03 00 04 */	stw r0, 4(r3)
/* 80113E9C 00110DFC  38 06 00 18 */	addi r0, r6, 0x18
/* 80113EA0 00110E00  38 E4 28 2C */	addi r7, r4, __vt__15WhistleTemplate@l
/* 80113EA4 00110E04  90 03 00 08 */	stw r0, 8(r3)
/* 80113EA8 00110E08  3C 80 80 2C */	lis r4, __vt__13UfoSuckEffect@ha
/* 80113EAC 00110E0C  38 C4 27 F0 */	addi r6, r4, __vt__13UfoSuckEffect@l
/* 80113EB0 00110E10  90 E3 00 00 */	stw r7, 0(r3)
/* 80113EB4 00110E14  38 87 00 0C */	addi r4, r7, 0xc
/* 80113EB8 00110E18  38 07 00 18 */	addi r0, r7, 0x18
/* 80113EBC 00110E1C  90 83 00 04 */	stw r4, 4(r3)
/* 80113EC0 00110E20  39 20 00 00 */	li r9, 0
/* 80113EC4 00110E24  39 00 01 46 */	li r8, 0x146
/* 80113EC8 00110E28  90 03 00 08 */	stw r0, 8(r3)
/* 80113ECC 00110E2C  38 E0 01 47 */	li r7, 0x147
/* 80113ED0 00110E30  38 86 00 0C */	addi r4, r6, 0xc
/* 80113ED4 00110E34  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80113ED8 00110E38  38 06 00 18 */	addi r0, r6, 0x18
/* 80113EDC 00110E3C  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 80113EE0 00110E40  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 80113EE4 00110E44  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 80113EE8 00110E48  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 80113EEC 00110E4C  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 80113EF0 00110E50  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 80113EF4 00110E54  91 23 00 28 */	stw r9, 0x28(r3)
/* 80113EF8 00110E58  91 23 00 24 */	stw r9, 0x24(r3)
/* 80113EFC 00110E5C  91 03 00 2C */	stw r8, 0x2c(r3)
/* 80113F00 00110E60  90 E3 00 30 */	stw r7, 0x30(r3)
/* 80113F04 00110E64  90 C3 00 00 */	stw r6, 0(r3)
/* 80113F08 00110E68  90 83 00 04 */	stw r4, 4(r3)
/* 80113F0C 00110E6C  90 03 00 08 */	stw r0, 8(r3)
.L_80113F10:
/* 80113F10 00110E70  38 7F 00 00 */	addi r3, r31, 0
/* 80113F14 00110E74  38 80 00 15 */	li r4, 0x15
/* 80113F18 00110E78  48 00 03 B9 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113F1C 00110E7C  38 60 00 28 */	li r3, 0x28
/* 80113F20 00110E80  4B F3 30 E5 */	bl alloc__6SystemFUl
/* 80113F24 00110E84  7C 65 1B 79 */	or. r5, r3, r3
/* 80113F28 00110E88  41 82 00 84 */	beq .L_80113FAC
/* 80113F2C 00110E8C  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113F30 00110E90  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113F34 00110E94  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113F38 00110E98  90 03 00 00 */	stw r0, 0(r3)
/* 80113F3C 00110E9C  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113F40 00110EA0  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113F44 00110EA4  90 03 00 04 */	stw r0, 4(r3)
/* 80113F48 00110EA8  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113F4C 00110EAC  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113F50 00110EB0  90 03 00 08 */	stw r0, 8(r3)
/* 80113F54 00110EB4  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80113F58 00110EB8  90 C3 00 00 */	stw r6, 0(r3)
/* 80113F5C 00110EBC  38 06 00 0C */	addi r0, r6, 0xc
/* 80113F60 00110EC0  3C 80 80 2C */	lis r4, __vt__16UfoSuikomiEffect@ha
/* 80113F64 00110EC4  90 03 00 04 */	stw r0, 4(r3)
/* 80113F68 00110EC8  38 06 00 18 */	addi r0, r6, 0x18
/* 80113F6C 00110ECC  38 E4 27 44 */	addi r7, r4, __vt__16UfoSuikomiEffect@l
/* 80113F70 00110ED0  90 03 00 08 */	stw r0, 8(r3)
/* 80113F74 00110ED4  38 C7 00 0C */	addi r6, r7, 0xc
/* 80113F78 00110ED8  38 87 00 18 */	addi r4, r7, 0x18
/* 80113F7C 00110EDC  90 E3 00 00 */	stw r7, 0(r3)
/* 80113F80 00110EE0  38 00 00 00 */	li r0, 0
/* 80113F84 00110EE4  90 C3 00 04 */	stw r6, 4(r3)
/* 80113F88 00110EE8  90 83 00 08 */	stw r4, 8(r3)
/* 80113F8C 00110EEC  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80113F90 00110EF0  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 80113F94 00110EF4  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 80113F98 00110EF8  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 80113F9C 00110EFC  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 80113FA0 00110F00  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 80113FA4 00110F04  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 80113FA8 00110F08  90 03 00 24 */	stw r0, 0x24(r3)
.L_80113FAC:
/* 80113FAC 00110F0C  38 7F 00 00 */	addi r3, r31, 0
/* 80113FB0 00110F10  38 80 00 16 */	li r4, 0x16
/* 80113FB4 00110F14  48 00 03 1D */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80113FB8 00110F18  38 60 00 34 */	li r3, 0x34
/* 80113FBC 00110F1C  4B F3 30 49 */	bl alloc__6SystemFUl
/* 80113FC0 00110F20  7C 65 1B 79 */	or. r5, r3, r3
/* 80113FC4 00110F24  41 82 00 98 */	beq .L_8011405C
/* 80113FC8 00110F28  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 80113FCC 00110F2C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80113FD0 00110F30  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80113FD4 00110F34  90 03 00 00 */	stw r0, 0(r3)
/* 80113FD8 00110F38  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 80113FDC 00110F3C  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80113FE0 00110F40  90 03 00 04 */	stw r0, 4(r3)
/* 80113FE4 00110F44  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80113FE8 00110F48  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 80113FEC 00110F4C  90 03 00 08 */	stw r0, 8(r3)
/* 80113FF0 00110F50  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80113FF4 00110F54  90 C3 00 00 */	stw r6, 0(r3)
/* 80113FF8 00110F58  38 06 00 0C */	addi r0, r6, 0xc
/* 80113FFC 00110F5C  3C 80 80 2C */	lis r4, __vt__15WhistleTemplate@ha
/* 80114000 00110F60  90 03 00 04 */	stw r0, 4(r3)
/* 80114004 00110F64  38 06 00 18 */	addi r0, r6, 0x18
/* 80114008 00110F68  38 84 28 2C */	addi r4, r4, __vt__15WhistleTemplate@l
/* 8011400C 00110F6C  90 03 00 08 */	stw r0, 8(r3)
/* 80114010 00110F70  38 04 00 0C */	addi r0, r4, 0xc
/* 80114014 00110F74  38 E4 00 18 */	addi r7, r4, 0x18
/* 80114018 00110F78  90 83 00 00 */	stw r4, 0(r3)
/* 8011401C 00110F7C  38 C0 00 00 */	li r6, 0
/* 80114020 00110F80  38 80 01 22 */	li r4, 0x122
/* 80114024 00110F84  90 03 00 04 */	stw r0, 4(r3)
/* 80114028 00110F88  38 00 01 23 */	li r0, 0x123
/* 8011402C 00110F8C  90 E3 00 08 */	stw r7, 8(r3)
/* 80114030 00110F90  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80114034 00110F94  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 80114038 00110F98  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 8011403C 00110F9C  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 80114040 00110FA0  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 80114044 00110FA4  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 80114048 00110FA8  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 8011404C 00110FAC  90 C3 00 28 */	stw r6, 0x28(r3)
/* 80114050 00110FB0  90 C3 00 24 */	stw r6, 0x24(r3)
/* 80114054 00110FB4  90 83 00 2C */	stw r4, 0x2c(r3)
/* 80114058 00110FB8  90 03 00 30 */	stw r0, 0x30(r3)
.L_8011405C:
/* 8011405C 00110FBC  38 7F 00 00 */	addi r3, r31, 0
/* 80114060 00110FC0  38 80 00 17 */	li r4, 0x17
/* 80114064 00110FC4  48 00 02 6D */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80114068 00110FC8  38 60 00 34 */	li r3, 0x34
/* 8011406C 00110FCC  4B F3 2F 99 */	bl alloc__6SystemFUl
/* 80114070 00110FD0  7C 65 1B 79 */	or. r5, r3, r3
/* 80114074 00110FD4  41 82 00 98 */	beq .L_8011410C
/* 80114078 00110FD8  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 8011407C 00110FDC  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80114080 00110FE0  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80114084 00110FE4  90 03 00 00 */	stw r0, 0(r3)
/* 80114088 00110FE8  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 8011408C 00110FEC  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80114090 00110FF0  90 03 00 04 */	stw r0, 4(r3)
/* 80114094 00110FF4  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80114098 00110FF8  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 8011409C 00110FFC  90 03 00 08 */	stw r0, 8(r3)
/* 801140A0 00111000  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 801140A4 00111004  90 C3 00 00 */	stw r6, 0(r3)
/* 801140A8 00111008  38 06 00 0C */	addi r0, r6, 0xc
/* 801140AC 0011100C  3C 80 80 2C */	lis r4, __vt__15WhistleTemplate@ha
/* 801140B0 00111010  90 03 00 04 */	stw r0, 4(r3)
/* 801140B4 00111014  38 06 00 18 */	addi r0, r6, 0x18
/* 801140B8 00111018  38 84 28 2C */	addi r4, r4, __vt__15WhistleTemplate@l
/* 801140BC 0011101C  90 03 00 08 */	stw r0, 8(r3)
/* 801140C0 00111020  38 04 00 0C */	addi r0, r4, 0xc
/* 801140C4 00111024  38 E4 00 18 */	addi r7, r4, 0x18
/* 801140C8 00111028  90 83 00 00 */	stw r4, 0(r3)
/* 801140CC 0011102C  38 C0 00 00 */	li r6, 0
/* 801140D0 00111030  38 80 01 22 */	li r4, 0x122
/* 801140D4 00111034  90 03 00 04 */	stw r0, 4(r3)
/* 801140D8 00111038  38 00 01 23 */	li r0, 0x123
/* 801140DC 0011103C  90 E3 00 08 */	stw r7, 8(r3)
/* 801140E0 00111040  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 801140E4 00111044  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 801140E8 00111048  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 801140EC 0011104C  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 801140F0 00111050  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 801140F4 00111054  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 801140F8 00111058  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 801140FC 0011105C  90 C3 00 28 */	stw r6, 0x28(r3)
/* 80114100 00111060  90 C3 00 24 */	stw r6, 0x24(r3)
/* 80114104 00111064  90 83 00 2C */	stw r4, 0x2c(r3)
/* 80114108 00111068  90 03 00 30 */	stw r0, 0x30(r3)
.L_8011410C:
/* 8011410C 0011106C  38 7F 00 00 */	addi r3, r31, 0
/* 80114110 00111070  38 80 00 18 */	li r4, 0x18
/* 80114114 00111074  48 00 01 BD */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80114118 00111078  38 60 00 14 */	li r3, 0x14
/* 8011411C 0011107C  4B F3 2E E9 */	bl alloc__6SystemFUl
/* 80114120 00111080  7C 65 1B 79 */	or. r5, r3, r3
/* 80114124 00111084  41 82 00 70 */	beq .L_80114194
/* 80114128 00111088  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 8011412C 0011108C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80114130 00111090  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80114134 00111094  90 03 00 00 */	stw r0, 0(r3)
/* 80114138 00111098  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 8011413C 0011109C  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80114140 001110A0  90 03 00 04 */	stw r0, 4(r3)
/* 80114144 001110A4  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80114148 001110A8  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 8011414C 001110AC  90 03 00 08 */	stw r0, 8(r3)
/* 80114150 001110B0  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80114154 001110B4  90 C3 00 00 */	stw r6, 0(r3)
/* 80114158 001110B8  38 06 00 0C */	addi r0, r6, 0xc
/* 8011415C 001110BC  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80114160 001110C0  90 03 00 04 */	stw r0, 4(r3)
/* 80114164 001110C4  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80114168 001110C8  38 06 00 18 */	addi r0, r6, 0x18
/* 8011416C 001110CC  90 03 00 08 */	stw r0, 8(r3)
/* 80114170 001110D0  38 E4 00 0C */	addi r7, r4, 0xc
/* 80114174 001110D4  38 C4 00 18 */	addi r6, r4, 0x18
/* 80114178 001110D8  90 83 00 00 */	stw r4, 0(r3)
/* 8011417C 001110DC  38 80 00 2A */	li r4, 0x2a
/* 80114180 001110E0  38 00 00 00 */	li r0, 0
/* 80114184 001110E4  90 E3 00 04 */	stw r7, 4(r3)
/* 80114188 001110E8  90 C3 00 08 */	stw r6, 8(r3)
/* 8011418C 001110EC  90 83 00 0C */	stw r4, 0xc(r3)
/* 80114190 001110F0  90 03 00 10 */	stw r0, 0x10(r3)
.L_80114194:
/* 80114194 001110F4  38 7F 00 00 */	addi r3, r31, 0
/* 80114198 001110F8  38 80 00 19 */	li r4, 0x19
/* 8011419C 001110FC  48 00 01 35 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 801141A0 00111100  38 60 00 14 */	li r3, 0x14
/* 801141A4 00111104  4B F3 2E 61 */	bl alloc__6SystemFUl
/* 801141A8 00111108  7C 65 1B 79 */	or. r5, r3, r3
/* 801141AC 0011110C  41 82 00 70 */	beq .L_8011421C
/* 801141B0 00111110  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 801141B4 00111114  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 801141B8 00111118  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 801141BC 0011111C  90 03 00 00 */	stw r0, 0(r3)
/* 801141C0 00111120  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 801141C4 00111124  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 801141C8 00111128  90 03 00 04 */	stw r0, 4(r3)
/* 801141CC 0011112C  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 801141D0 00111130  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 801141D4 00111134  90 03 00 08 */	stw r0, 8(r3)
/* 801141D8 00111138  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 801141DC 0011113C  90 C3 00 00 */	stw r6, 0(r3)
/* 801141E0 00111140  38 06 00 0C */	addi r0, r6, 0xc
/* 801141E4 00111144  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 801141E8 00111148  90 03 00 04 */	stw r0, 4(r3)
/* 801141EC 0011114C  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 801141F0 00111150  38 06 00 18 */	addi r0, r6, 0x18
/* 801141F4 00111154  90 03 00 08 */	stw r0, 8(r3)
/* 801141F8 00111158  38 E4 00 0C */	addi r7, r4, 0xc
/* 801141FC 0011115C  38 C4 00 18 */	addi r6, r4, 0x18
/* 80114200 00111160  90 83 00 00 */	stw r4, 0(r3)
/* 80114204 00111164  38 80 00 29 */	li r4, 0x29
/* 80114208 00111168  38 00 00 00 */	li r0, 0
/* 8011420C 0011116C  90 E3 00 04 */	stw r7, 4(r3)
/* 80114210 00111170  90 C3 00 08 */	stw r6, 8(r3)
/* 80114214 00111174  90 83 00 0C */	stw r4, 0xc(r3)
/* 80114218 00111178  90 03 00 10 */	stw r0, 0x10(r3)
.L_8011421C:
/* 8011421C 0011117C  38 7F 00 00 */	addi r3, r31, 0
/* 80114220 00111180  38 80 00 1A */	li r4, 0x1a
/* 80114224 00111184  48 00 00 AD */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 80114228 00111188  38 60 00 14 */	li r3, 0x14
/* 8011422C 0011118C  4B F3 2D D9 */	bl alloc__6SystemFUl
/* 80114230 00111190  7C 65 1B 79 */	or. r5, r3, r3
/* 80114234 00111194  41 82 00 70 */	beq .L_801142A4
/* 80114238 00111198  3C 80 80 2B */	lis r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@ha
/* 8011423C 0011119C  38 04 06 00 */	addi r0, r4, "__vt__Q23zen37CallBack1<PQ23zen17particleGenerator>"@l
/* 80114240 001111A0  3C 80 80 2B */	lis r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@ha
/* 80114244 001111A4  90 03 00 00 */	stw r0, 0(r3)
/* 80114248 001111A8  38 04 05 F4 */	addi r0, r4, "__vt__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"@l
/* 8011424C 001111AC  3C 80 80 2B */	lis r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@ha
/* 80114250 001111B0  90 03 00 04 */	stw r0, 4(r3)
/* 80114254 001111B4  38 04 05 E8 */	addi r0, r4, "__vt__Q23zen31CallBack1<PQ23zen11particleMdl>"@l
/* 80114258 001111B8  3C 80 80 2B */	lis r4, __vt__7KEffect@ha
/* 8011425C 001111BC  90 03 00 08 */	stw r0, 8(r3)
/* 80114260 001111C0  38 C4 05 AC */	addi r6, r4, __vt__7KEffect@l
/* 80114264 001111C4  90 C3 00 00 */	stw r6, 0(r3)
/* 80114268 001111C8  38 06 00 0C */	addi r0, r6, 0xc
/* 8011426C 001111CC  3C 80 80 2C */	lis r4, __vt__12SimpleEffect@ha
/* 80114270 001111D0  90 03 00 04 */	stw r0, 4(r3)
/* 80114274 001111D4  38 84 29 78 */	addi r4, r4, __vt__12SimpleEffect@l
/* 80114278 001111D8  38 06 00 18 */	addi r0, r6, 0x18
/* 8011427C 001111DC  90 03 00 08 */	stw r0, 8(r3)
/* 80114280 001111E0  38 E4 00 0C */	addi r7, r4, 0xc
/* 80114284 001111E4  38 C4 00 18 */	addi r6, r4, 0x18
/* 80114288 001111E8  90 83 00 00 */	stw r4, 0(r3)
/* 8011428C 001111EC  38 80 00 28 */	li r4, 0x28
/* 80114290 001111F0  38 00 00 00 */	li r0, 0
/* 80114294 001111F4  90 E3 00 04 */	stw r7, 4(r3)
/* 80114298 001111F8  90 C3 00 08 */	stw r6, 8(r3)
/* 8011429C 001111FC  90 83 00 0C */	stw r4, 0xc(r3)
/* 801142A0 00111200  90 03 00 10 */	stw r0, 0x10(r3)
.L_801142A4:
/* 801142A4 00111204  38 7F 00 00 */	addi r3, r31, 0
/* 801142A8 00111208  38 80 00 1B */	li r4, 0x1b
/* 801142AC 0011120C  48 00 00 25 */	bl registerEffect__11UtEffectMgrFiP7KEffect
/* 801142B0 00111210  7F E3 FB 78 */	mr r3, r31
/* 801142B4 00111214  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801142B8 00111218  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801142BC 0011121C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801142C0 00111220  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 801142C4 00111224  38 21 00 20 */	addi r1, r1, 0x20
/* 801142C8 00111228  7C 08 03 A6 */	mtlr r0
/* 801142CC 0011122C  4E 80 00 20 */	blr 
.endfn __ct__11UtEffectMgrFv

.fn registerEffect__11UtEffectMgrFiP7KEffect, global
/* 801142D0 00111230  80 6D 31 14 */	lwz r3, effects__11UtEffectMgr@sda21(r13)
/* 801142D4 00111234  54 80 10 3A */	slwi r0, r4, 2
/* 801142D8 00111238  7C A3 01 2E */	stwx r5, r3, r0
/* 801142DC 0011123C  4E 80 00 20 */	blr 
.endfn registerEffect__11UtEffectMgrFiP7KEffect

.fn cast__11UtEffectMgrFiR10EffectParm, global
/* 801142E0 00111240  7C 08 02 A6 */	mflr r0
/* 801142E4 00111244  90 01 00 04 */	stw r0, 4(r1)
/* 801142E8 00111248  54 60 10 3A */	slwi r0, r3, 2
/* 801142EC 0011124C  94 21 FF F8 */	stwu r1, -8(r1)
/* 801142F0 00111250  80 AD 31 14 */	lwz r5, effects__11UtEffectMgr@sda21(r13)
/* 801142F4 00111254  7C 05 00 2E */	lwzx r0, r5, r0
/* 801142F8 00111258  28 00 00 00 */	cmplwi r0, 0
/* 801142FC 0011125C  7C 03 03 78 */	mr r3, r0
/* 80114300 00111260  41 82 00 14 */	beq .L_80114314
/* 80114304 00111264  81 83 00 00 */	lwz r12, 0(r3)
/* 80114308 00111268  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 8011430C 0011126C  7D 88 03 A6 */	mtlr r12
/* 80114310 00111270  4E 80 00 21 */	blrl 
.L_80114314:
/* 80114314 00111274  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80114318 00111278  38 21 00 08 */	addi r1, r1, 8
/* 8011431C 0011127C  7C 08 03 A6 */	mtlr r0
/* 80114320 00111280  4E 80 00 20 */	blr 
.endfn cast__11UtEffectMgrFiR10EffectParm

.fn kill__11UtEffectMgrFi, global
/* 80114324 00111284  7C 08 02 A6 */	mflr r0
/* 80114328 00111288  90 01 00 04 */	stw r0, 4(r1)
/* 8011432C 0011128C  54 60 10 3A */	slwi r0, r3, 2
/* 80114330 00111290  94 21 FF F8 */	stwu r1, -8(r1)
/* 80114334 00111294  80 8D 31 14 */	lwz r4, effects__11UtEffectMgr@sda21(r13)
/* 80114338 00111298  7C 04 00 2E */	lwzx r0, r4, r0
/* 8011433C 0011129C  28 00 00 00 */	cmplwi r0, 0
/* 80114340 001112A0  7C 03 03 78 */	mr r3, r0
/* 80114344 001112A4  41 82 00 14 */	beq .L_80114358
/* 80114348 001112A8  81 83 00 00 */	lwz r12, 0(r3)
/* 8011434C 001112AC  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80114350 001112B0  7D 88 03 A6 */	mtlr r12
/* 80114354 001112B4  4E 80 00 21 */	blrl 
.L_80114358:
/* 80114358 001112B8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8011435C 001112BC  38 21 00 08 */	addi r1, r1, 8
/* 80114360 001112C0  7C 08 03 A6 */	mtlr r0
/* 80114364 001112C4  4E 80 00 20 */	blr 
.endfn kill__11UtEffectMgrFi

.fn __ct__15PermanentEffectFv, global
/* 80114368 001112C8  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 8011436C 001112CC  38 00 00 00 */	li r0, 0
/* 80114370 001112D0  D0 03 00 08 */	stfs f0, 8(r3)
/* 80114374 001112D4  D0 03 00 04 */	stfs f0, 4(r3)
/* 80114378 001112D8  D0 03 00 00 */	stfs f0, 0(r3)
/* 8011437C 001112DC  90 03 00 0C */	stw r0, 0xc(r3)
/* 80114380 001112E0  C0 0D DB 70 */	lfs f0, lbl_803E2890@sda21(r13)
/* 80114384 001112E4  D0 03 00 00 */	stfs f0, 0(r3)
/* 80114388 001112E8  C0 0D DB 74 */	lfs f0, lbl_803E2894@sda21(r13)
/* 8011438C 001112EC  D0 03 00 04 */	stfs f0, 4(r3)
/* 80114390 001112F0  C0 0D DB 78 */	lfs f0, lbl_803E2898@sda21(r13)
/* 80114394 001112F4  D0 03 00 08 */	stfs f0, 8(r3)
/* 80114398 001112F8  4E 80 00 20 */	blr 
.endfn __ct__15PermanentEffectFv

.fn init__15PermanentEffectFR8Vector3fi, global
/* 8011439C 001112FC  7C 08 02 A6 */	mflr r0
/* 801143A0 00111300  39 05 00 00 */	addi r8, r5, 0
/* 801143A4 00111304  90 01 00 04 */	stw r0, 4(r1)
/* 801143A8 00111308  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 801143AC 0011130C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 801143B0 00111310  7C 7F 1B 78 */	mr r31, r3
/* 801143B4 00111314  80 03 00 0C */	lwz r0, 0xc(r3)
/* 801143B8 00111318  28 00 00 00 */	cmplwi r0, 0
/* 801143BC 0011131C  40 82 00 58 */	bne .L_80114414
/* 801143C0 00111320  80 64 00 00 */	lwz r3, 0(r4)
/* 801143C4 00111324  7F E5 FB 78 */	mr r5, r31
/* 801143C8 00111328  80 04 00 04 */	lwz r0, 4(r4)
/* 801143CC 0011132C  38 C0 00 00 */	li r6, 0
/* 801143D0 00111330  38 E0 00 00 */	li r7, 0
/* 801143D4 00111334  90 7F 00 00 */	stw r3, 0(r31)
/* 801143D8 00111338  90 1F 00 04 */	stw r0, 4(r31)
/* 801143DC 0011133C  80 04 00 08 */	lwz r0, 8(r4)
/* 801143E0 00111340  7D 04 43 78 */	mr r4, r8
/* 801143E4 00111344  90 1F 00 08 */	stw r0, 8(r31)
/* 801143E8 00111348  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801143EC 0011134C  48 08 87 4D */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801143F0 00111350  90 7F 00 0C */	stw r3, 0xc(r31)
/* 801143F4 00111354  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 801143F8 00111358  28 03 00 00 */	cmplwi r3, 0
/* 801143FC 0011135C  41 82 00 18 */	beq .L_80114414
/* 80114400 00111360  93 E3 00 18 */	stw r31, 0x18(r3)
/* 80114404 00111364  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 80114408 00111368  80 03 00 80 */	lwz r0, 0x80(r3)
/* 8011440C 0011136C  60 00 00 01 */	ori r0, r0, 1
/* 80114410 00111370  90 03 00 80 */	stw r0, 0x80(r3)
.L_80114414:
/* 80114414 00111374  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80114418 00111378  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8011441C 0011137C  38 21 00 28 */	addi r1, r1, 0x28
/* 80114420 00111380  7C 08 03 A6 */	mtlr r0
/* 80114424 00111384  4E 80 00 20 */	blr 
.endfn init__15PermanentEffectFR8Vector3fi

.fn updatePos__15PermanentEffectFR8Vector3f, global
/* 80114428 00111388  80 A4 00 00 */	lwz r5, 0(r4)
/* 8011442C 0011138C  80 04 00 04 */	lwz r0, 4(r4)
/* 80114430 00111390  90 A3 00 00 */	stw r5, 0(r3)
/* 80114434 00111394  90 03 00 04 */	stw r0, 4(r3)
/* 80114438 00111398  80 04 00 08 */	lwz r0, 8(r4)
/* 8011443C 0011139C  90 03 00 08 */	stw r0, 8(r3)
/* 80114440 001113A0  80 63 00 0C */	lwz r3, 0xc(r3)
/* 80114444 001113A4  28 03 00 00 */	cmplwi r3, 0
/* 80114448 001113A8  4D 82 00 20 */	beqlr 
/* 8011444C 001113AC  80 03 00 80 */	lwz r0, 0x80(r3)
/* 80114450 001113B0  54 00 00 3C */	rlwinm r0, r0, 0, 0, 0x1e
/* 80114454 001113B4  90 03 00 80 */	stw r0, 0x80(r3)
/* 80114458 001113B8  4E 80 00 20 */	blr 
.endfn updatePos__15PermanentEffectFR8Vector3f

.fn changeEffect__15PermanentEffectFi, global
/* 8011445C 001113BC  7C 08 02 A6 */	mflr r0
/* 80114460 001113C0  90 01 00 04 */	stw r0, 4(r1)
/* 80114464 001113C4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80114468 001113C8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011446C 001113CC  3B E4 00 00 */	addi r31, r4, 0
/* 80114470 001113D0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80114474 001113D4  7C 7E 1B 78 */	mr r30, r3
/* 80114478 001113D8  80 03 00 0C */	lwz r0, 0xc(r3)
/* 8011447C 001113DC  28 00 00 00 */	cmplwi r0, 0
/* 80114480 001113E0  41 82 00 18 */	beq .L_80114498
/* 80114484 001113E4  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114488 001113E8  7C 04 03 78 */	mr r4, r0
/* 8011448C 001113EC  38 A0 00 00 */	li r5, 0
/* 80114490 001113F0  38 63 00 14 */	addi r3, r3, 0x14
/* 80114494 001113F4  48 08 D1 31 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
.L_80114498:
/* 80114498 001113F8  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8011449C 001113FC  38 9F 00 00 */	addi r4, r31, 0
/* 801144A0 00111400  38 BE 00 00 */	addi r5, r30, 0
/* 801144A4 00111404  38 C0 00 00 */	li r6, 0
/* 801144A8 00111408  38 E0 00 00 */	li r7, 0
/* 801144AC 0011140C  48 08 86 8D */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801144B0 00111410  90 7E 00 0C */	stw r3, 0xc(r30)
/* 801144B4 00111414  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 801144B8 00111418  28 03 00 00 */	cmplwi r3, 0
/* 801144BC 0011141C  41 82 00 08 */	beq .L_801144C4
/* 801144C0 00111420  93 C3 00 18 */	stw r30, 0x18(r3)
.L_801144C4:
/* 801144C4 00111424  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801144C8 00111428  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 801144CC 0011142C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 801144D0 00111430  38 21 00 20 */	addi r1, r1, 0x20
/* 801144D4 00111434  7C 08 03 A6 */	mtlr r0
/* 801144D8 00111438  4E 80 00 20 */	blr 
.endfn changeEffect__15PermanentEffectFi

.fn stop__15PermanentEffectFv, global
/* 801144DC 0011143C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 801144E0 00111440  28 03 00 00 */	cmplwi r3, 0
/* 801144E4 00111444  4D 82 00 20 */	beqlr 
/* 801144E8 00111448  80 03 00 80 */	lwz r0, 0x80(r3)
/* 801144EC 0011144C  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 801144F0 00111450  90 03 00 80 */	stw r0, 0x80(r3)
/* 801144F4 00111454  4E 80 00 20 */	blr 
.endfn stop__15PermanentEffectFv

.fn restart__15PermanentEffectFv, global
/* 801144F8 00111458  80 63 00 0C */	lwz r3, 0xc(r3)
/* 801144FC 0011145C  28 03 00 00 */	cmplwi r3, 0
/* 80114500 00111460  4D 82 00 20 */	beqlr 
/* 80114504 00111464  80 03 00 80 */	lwz r0, 0x80(r3)
/* 80114508 00111468  60 00 00 10 */	ori r0, r0, 0x10
/* 8011450C 0011146C  90 03 00 80 */	stw r0, 0x80(r3)
/* 80114510 00111470  4E 80 00 20 */	blr 
.endfn restart__15PermanentEffectFv

.fn kill__15PermanentEffectFv, global
/* 80114514 00111474  7C 08 02 A6 */	mflr r0
/* 80114518 00111478  90 01 00 04 */	stw r0, 4(r1)
/* 8011451C 0011147C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80114520 00111480  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80114524 00111484  7C 7F 1B 78 */	mr r31, r3
/* 80114528 00111488  80 83 00 0C */	lwz r4, 0xc(r3)
/* 8011452C 0011148C  28 04 00 00 */	cmplwi r4, 0
/* 80114530 00111490  41 82 00 1C */	beq .L_8011454C
/* 80114534 00111494  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114538 00111498  38 A0 00 00 */	li r5, 0
/* 8011453C 0011149C  38 63 00 14 */	addi r3, r3, 0x14
/* 80114540 001114A0  48 08 D0 85 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80114544 001114A4  38 00 00 00 */	li r0, 0
/* 80114548 001114A8  90 1F 00 0C */	stw r0, 0xc(r31)
.L_8011454C:
/* 8011454C 001114AC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80114550 001114B0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80114554 001114B4  38 21 00 18 */	addi r1, r1, 0x18
/* 80114558 001114B8  7C 08 03 A6 */	mtlr r0
/* 8011455C 001114BC  4E 80 00 20 */	blr 
.endfn kill__15PermanentEffectFv

.fn emit__15FreeLightEffectFR10EffectParm, global
/* 80114560 001114C0  7C 08 02 A6 */	mflr r0
/* 80114564 001114C4  90 01 00 04 */	stw r0, 4(r1)
/* 80114568 001114C8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8011456C 001114CC  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80114570 001114D0  3B E4 00 00 */	addi r31, r4, 0
/* 80114574 001114D4  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80114578 001114D8  7C 7E 1B 78 */	mr r30, r3
/* 8011457C 001114DC  80 03 00 10 */	lwz r0, 0x10(r3)
/* 80114580 001114E0  28 00 00 00 */	cmplwi r0, 0
/* 80114584 001114E4  40 82 00 44 */	bne .L_801145C8
/* 80114588 001114E8  A0 1E 00 0C */	lhz r0, 0xc(r30)
/* 8011458C 001114EC  38 C0 00 00 */	li r6, 0
/* 80114590 001114F0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114594 001114F4  38 E0 00 00 */	li r7, 0
/* 80114598 001114F8  80 BF 00 20 */	lwz r5, 0x20(r31)
/* 8011459C 001114FC  20 80 00 2A */	subfic r4, r0, 0x2a
/* 801145A0 00111500  48 08 85 99 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801145A4 00111504  90 7E 00 10 */	stw r3, 0x10(r30)
/* 801145A8 00111508  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 801145AC 0011150C  28 03 00 00 */	cmplwi r3, 0
/* 801145B0 00111510  41 82 00 18 */	beq .L_801145C8
/* 801145B4 00111514  C0 03 00 F0 */	lfs f0, 0xf0(r3)
/* 801145B8 00111518  D0 1E 00 14 */	stfs f0, 0x14(r30)
/* 801145BC 0011151C  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 801145C0 00111520  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 801145C4 00111524  90 03 00 18 */	stw r0, 0x18(r3)
.L_801145C8:
/* 801145C8 00111528  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801145CC 0011152C  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 801145D0 00111530  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 801145D4 00111534  38 21 00 30 */	addi r1, r1, 0x30
/* 801145D8 00111538  7C 08 03 A6 */	mtlr r0
/* 801145DC 0011153C  4E 80 00 20 */	blr 
.endfn emit__15FreeLightEffectFR10EffectParm

.fn stop__15FreeLightEffectFv, global
/* 801145E0 00111540  80 63 00 10 */	lwz r3, 0x10(r3)
/* 801145E4 00111544  28 03 00 00 */	cmplwi r3, 0
/* 801145E8 00111548  4D 82 00 20 */	beqlr 
/* 801145EC 0011154C  80 03 00 80 */	lwz r0, 0x80(r3)
/* 801145F0 00111550  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 801145F4 00111554  90 03 00 80 */	stw r0, 0x80(r3)
/* 801145F8 00111558  4E 80 00 20 */	blr 
.endfn stop__15FreeLightEffectFv

.fn restart__15FreeLightEffectFv, global
/* 801145FC 0011155C  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80114600 00111560  28 03 00 00 */	cmplwi r3, 0
/* 80114604 00111564  4D 82 00 20 */	beqlr 
/* 80114608 00111568  80 03 00 80 */	lwz r0, 0x80(r3)
/* 8011460C 0011156C  60 00 00 10 */	ori r0, r0, 0x10
/* 80114610 00111570  90 03 00 80 */	stw r0, 0x80(r3)
/* 80114614 00111574  4E 80 00 20 */	blr 
.endfn restart__15FreeLightEffectFv

.fn setScale__15FreeLightEffectFf, global
/* 80114618 00111578  80 83 00 10 */	lwz r4, 0x10(r3)
/* 8011461C 0011157C  28 04 00 00 */	cmplwi r4, 0
/* 80114620 00111580  4D 82 00 20 */	beqlr 
/* 80114624 00111584  C0 03 00 14 */	lfs f0, 0x14(r3)
/* 80114628 00111588  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011462C 0011158C  D0 04 00 F0 */	stfs f0, 0xf0(r4)
/* 80114630 00111590  4E 80 00 20 */	blr 
.endfn setScale__15FreeLightEffectFf

.fn kill__15FreeLightEffectFv, global
/* 80114634 00111594  7C 08 02 A6 */	mflr r0
/* 80114638 00111598  90 01 00 04 */	stw r0, 4(r1)
/* 8011463C 0011159C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80114640 001115A0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80114644 001115A4  7C 7F 1B 78 */	mr r31, r3
/* 80114648 001115A8  80 83 00 10 */	lwz r4, 0x10(r3)
/* 8011464C 001115AC  28 04 00 00 */	cmplwi r4, 0
/* 80114650 001115B0  41 82 00 1C */	beq .L_8011466C
/* 80114654 001115B4  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114658 001115B8  38 A0 00 00 */	li r5, 0
/* 8011465C 001115BC  38 63 00 14 */	addi r3, r3, 0x14
/* 80114660 001115C0  48 08 CF 65 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80114664 001115C4  38 00 00 00 */	li r0, 0
/* 80114668 001115C8  90 1F 00 10 */	stw r0, 0x10(r31)
.L_8011466C:
/* 8011466C 001115CC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80114670 001115D0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80114674 001115D4  38 21 00 18 */	addi r1, r1, 0x18
/* 80114678 001115D8  7C 08 03 A6 */	mtlr r0
/* 8011467C 001115DC  4E 80 00 20 */	blr 
.endfn kill__15FreeLightEffectFv

.fn emit__12RippleEffectFR10EffectParm, global
/* 80114680 001115E0  7C 08 02 A6 */	mflr r0
/* 80114684 001115E4  90 01 00 04 */	stw r0, 4(r1)
/* 80114688 001115E8  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 8011468C 001115EC  DB E1 00 68 */	stfd f31, 0x68(r1)
/* 80114690 001115F0  93 E1 00 64 */	stw r31, 0x64(r1)
/* 80114694 001115F4  3B E4 00 00 */	addi r31, r4, 0
/* 80114698 001115F8  93 C1 00 60 */	stw r30, 0x60(r1)
/* 8011469C 001115FC  7C 7E 1B 78 */	mr r30, r3
/* 801146A0 00111600  80 03 00 0C */	lwz r0, 0xc(r3)
/* 801146A4 00111604  28 00 00 00 */	cmplwi r0, 0
/* 801146A8 00111608  40 82 00 F0 */	bne .L_80114798
/* 801146AC 0011160C  C3 FF 00 24 */	lfs f31, 0x24(r31)
/* 801146B0 00111610  38 80 00 0D */	li r4, 0xd
/* 801146B4 00111614  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801146B8 00111618  38 C0 00 00 */	li r6, 0
/* 801146BC 0011161C  80 BF 00 20 */	lwz r5, 0x20(r31)
/* 801146C0 00111620  38 E0 00 00 */	li r7, 0
/* 801146C4 00111624  48 08 84 75 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801146C8 00111628  90 7E 00 10 */	stw r3, 0x10(r30)
/* 801146CC 0011162C  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 801146D0 00111630  28 03 00 00 */	cmplwi r3, 0
/* 801146D4 00111634  41 82 00 50 */	beq .L_80114724
/* 801146D8 00111638  C0 03 00 F0 */	lfs f0, 0xf0(r3)
/* 801146DC 0011163C  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 801146E0 00111640  EC 1F 00 32 */	fmuls f0, f31, f0
/* 801146E4 00111644  90 03 00 18 */	stw r0, 0x18(r3)
/* 801146E8 00111648  C0 2D DB 7C */	lfs f1, lbl_803E289C@sda21(r13)
/* 801146EC 0011164C  C0 4D DB 80 */	lfs f2, lbl_803E28A0@sda21(r13)
/* 801146F0 00111650  D0 21 00 4C */	stfs f1, 0x4c(r1)
/* 801146F4 00111654  C0 2D DB 84 */	lfs f1, lbl_803E28A4@sda21(r13)
/* 801146F8 00111658  D0 41 00 50 */	stfs f2, 0x50(r1)
/* 801146FC 0011165C  D0 21 00 54 */	stfs f1, 0x54(r1)
/* 80114700 00111660  80 9E 00 10 */	lwz r4, 0x10(r30)
/* 80114704 00111664  80 61 00 4C */	lwz r3, 0x4c(r1)
/* 80114708 00111668  80 01 00 50 */	lwz r0, 0x50(r1)
/* 8011470C 0011166C  90 64 01 DC */	stw r3, 0x1dc(r4)
/* 80114710 00111670  90 04 01 E0 */	stw r0, 0x1e0(r4)
/* 80114714 00111674  80 01 00 54 */	lwz r0, 0x54(r1)
/* 80114718 00111678  90 04 01 E4 */	stw r0, 0x1e4(r4)
/* 8011471C 0011167C  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 80114720 00111680  D0 03 00 F0 */	stfs f0, 0xf0(r3)
.L_80114724:
/* 80114724 00111684  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114728 00111688  38 80 00 0E */	li r4, 0xe
/* 8011472C 0011168C  80 BF 00 20 */	lwz r5, 0x20(r31)
/* 80114730 00111690  38 C0 00 00 */	li r6, 0
/* 80114734 00111694  38 E0 00 00 */	li r7, 0
/* 80114738 00111698  48 08 84 01 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8011473C 0011169C  90 7E 00 0C */	stw r3, 0xc(r30)
/* 80114740 001116A0  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 80114744 001116A4  28 03 00 00 */	cmplwi r3, 0
/* 80114748 001116A8  41 82 00 50 */	beq .L_80114798
/* 8011474C 001116AC  C0 03 00 F0 */	lfs f0, 0xf0(r3)
/* 80114750 001116B0  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 80114754 001116B4  EC 1F 00 32 */	fmuls f0, f31, f0
/* 80114758 001116B8  90 03 00 18 */	stw r0, 0x18(r3)
/* 8011475C 001116BC  C0 2D DB 88 */	lfs f1, lbl_803E28A8@sda21(r13)
/* 80114760 001116C0  C0 4D DB 8C */	lfs f2, lbl_803E28AC@sda21(r13)
/* 80114764 001116C4  D0 21 00 40 */	stfs f1, 0x40(r1)
/* 80114768 001116C8  C0 2D DB 90 */	lfs f1, lbl_803E28B0@sda21(r13)
/* 8011476C 001116CC  D0 41 00 44 */	stfs f2, 0x44(r1)
/* 80114770 001116D0  D0 21 00 48 */	stfs f1, 0x48(r1)
/* 80114774 001116D4  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 80114778 001116D8  80 61 00 40 */	lwz r3, 0x40(r1)
/* 8011477C 001116DC  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80114780 001116E0  90 64 01 DC */	stw r3, 0x1dc(r4)
/* 80114784 001116E4  90 04 01 E0 */	stw r0, 0x1e0(r4)
/* 80114788 001116E8  80 01 00 48 */	lwz r0, 0x48(r1)
/* 8011478C 001116EC  90 04 01 E4 */	stw r0, 0x1e4(r4)
/* 80114790 001116F0  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 80114794 001116F4  D0 03 00 F0 */	stfs f0, 0xf0(r3)
.L_80114798:
/* 80114798 001116F8  80 01 00 74 */	lwz r0, 0x74(r1)
/* 8011479C 001116FC  CB E1 00 68 */	lfd f31, 0x68(r1)
/* 801147A0 00111700  83 E1 00 64 */	lwz r31, 0x64(r1)
/* 801147A4 00111704  83 C1 00 60 */	lwz r30, 0x60(r1)
/* 801147A8 00111708  38 21 00 70 */	addi r1, r1, 0x70
/* 801147AC 0011170C  7C 08 03 A6 */	mtlr r0
/* 801147B0 00111710  4E 80 00 20 */	blr 
.endfn emit__12RippleEffectFR10EffectParm

.fn kill__12RippleEffectFv, global
/* 801147B4 00111714  7C 08 02 A6 */	mflr r0
/* 801147B8 00111718  90 01 00 04 */	stw r0, 4(r1)
/* 801147BC 0011171C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801147C0 00111720  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801147C4 00111724  7C 7F 1B 78 */	mr r31, r3
/* 801147C8 00111728  80 83 00 10 */	lwz r4, 0x10(r3)
/* 801147CC 0011172C  28 04 00 00 */	cmplwi r4, 0
/* 801147D0 00111730  41 82 00 1C */	beq .L_801147EC
/* 801147D4 00111734  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801147D8 00111738  38 A0 00 00 */	li r5, 0
/* 801147DC 0011173C  38 63 00 14 */	addi r3, r3, 0x14
/* 801147E0 00111740  48 08 CD E5 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 801147E4 00111744  38 00 00 00 */	li r0, 0
/* 801147E8 00111748  90 1F 00 10 */	stw r0, 0x10(r31)
.L_801147EC:
/* 801147EC 0011174C  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 801147F0 00111750  28 04 00 00 */	cmplwi r4, 0
/* 801147F4 00111754  41 82 00 1C */	beq .L_80114810
/* 801147F8 00111758  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801147FC 0011175C  38 A0 00 00 */	li r5, 0
/* 80114800 00111760  38 63 00 14 */	addi r3, r3, 0x14
/* 80114804 00111764  48 08 CD C1 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80114808 00111768  38 00 00 00 */	li r0, 0
/* 8011480C 0011176C  90 1F 00 14 */	stw r0, 0x14(r31)
.L_80114810:
/* 80114810 00111770  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 80114814 00111774  28 04 00 00 */	cmplwi r4, 0
/* 80114818 00111778  41 82 00 1C */	beq .L_80114834
/* 8011481C 0011177C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114820 00111780  38 A0 00 00 */	li r5, 0
/* 80114824 00111784  38 63 00 14 */	addi r3, r3, 0x14
/* 80114828 00111788  48 08 CD 9D */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 8011482C 0011178C  38 00 00 00 */	li r0, 0
/* 80114830 00111790  90 1F 00 0C */	stw r0, 0xc(r31)
.L_80114834:
/* 80114834 00111794  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80114838 00111798  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011483C 0011179C  38 21 00 18 */	addi r1, r1, 0x18
/* 80114840 001117A0  7C 08 03 A6 */	mtlr r0
/* 80114844 001117A4  4E 80 00 20 */	blr 
.endfn kill__12RippleEffectFv

.fn stop__12RippleEffectFv, global
/* 80114848 001117A8  80 83 00 10 */	lwz r4, 0x10(r3)
/* 8011484C 001117AC  28 04 00 00 */	cmplwi r4, 0
/* 80114850 001117B0  41 82 00 10 */	beq .L_80114860
/* 80114854 001117B4  80 04 00 80 */	lwz r0, 0x80(r4)
/* 80114858 001117B8  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 8011485C 001117BC  90 04 00 80 */	stw r0, 0x80(r4)
.L_80114860:
/* 80114860 001117C0  80 63 00 0C */	lwz r3, 0xc(r3)
/* 80114864 001117C4  28 03 00 00 */	cmplwi r3, 0
/* 80114868 001117C8  4D 82 00 20 */	beqlr 
/* 8011486C 001117CC  80 03 00 80 */	lwz r0, 0x80(r3)
/* 80114870 001117D0  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 80114874 001117D4  90 03 00 80 */	stw r0, 0x80(r3)
/* 80114878 001117D8  4E 80 00 20 */	blr 
.endfn stop__12RippleEffectFv

.fn restart__12RippleEffectFv, global
/* 8011487C 001117DC  80 83 00 10 */	lwz r4, 0x10(r3)
/* 80114880 001117E0  28 04 00 00 */	cmplwi r4, 0
/* 80114884 001117E4  41 82 00 10 */	beq .L_80114894
/* 80114888 001117E8  80 04 00 80 */	lwz r0, 0x80(r4)
/* 8011488C 001117EC  60 00 00 10 */	ori r0, r0, 0x10
/* 80114890 001117F0  90 04 00 80 */	stw r0, 0x80(r4)
.L_80114894:
/* 80114894 001117F4  80 63 00 0C */	lwz r3, 0xc(r3)
/* 80114898 001117F8  28 03 00 00 */	cmplwi r3, 0
/* 8011489C 001117FC  4D 82 00 20 */	beqlr 
/* 801148A0 00111800  80 03 00 80 */	lwz r0, 0x80(r3)
/* 801148A4 00111804  60 00 00 10 */	ori r0, r0, 0x10
/* 801148A8 00111808  90 03 00 80 */	stw r0, 0x80(r3)
/* 801148AC 0011180C  4E 80 00 20 */	blr 
.endfn restart__12RippleEffectFv

.fn stop__10BurnEffectFv, global
/* 801148B0 00111810  80 63 00 10 */	lwz r3, 0x10(r3)
/* 801148B4 00111814  28 03 00 00 */	cmplwi r3, 0
/* 801148B8 00111818  4D 82 00 20 */	beqlr 
/* 801148BC 0011181C  80 03 00 80 */	lwz r0, 0x80(r3)
/* 801148C0 00111820  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 801148C4 00111824  90 03 00 80 */	stw r0, 0x80(r3)
/* 801148C8 00111828  4E 80 00 20 */	blr 
.endfn stop__10BurnEffectFv

.fn restart__10BurnEffectFv, global
/* 801148CC 0011182C  80 63 00 10 */	lwz r3, 0x10(r3)
/* 801148D0 00111830  28 03 00 00 */	cmplwi r3, 0
/* 801148D4 00111834  4D 82 00 20 */	beqlr 
/* 801148D8 00111838  80 03 00 80 */	lwz r0, 0x80(r3)
/* 801148DC 0011183C  60 00 00 10 */	ori r0, r0, 0x10
/* 801148E0 00111840  90 03 00 80 */	stw r0, 0x80(r3)
/* 801148E4 00111844  4E 80 00 20 */	blr 
.endfn restart__10BurnEffectFv

.fn emit__10BurnEffectFR10EffectParm, global
/* 801148E8 00111848  7C 08 02 A6 */	mflr r0
/* 801148EC 0011184C  90 01 00 04 */	stw r0, 4(r1)
/* 801148F0 00111850  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 801148F4 00111854  93 E1 00 7C */	stw r31, 0x7c(r1)
/* 801148F8 00111858  3B E4 00 00 */	addi r31, r4, 0
/* 801148FC 0011185C  93 C1 00 78 */	stw r30, 0x78(r1)
/* 80114900 00111860  7C 7E 1B 78 */	mr r30, r3
/* 80114904 00111864  80 03 00 10 */	lwz r0, 0x10(r3)
/* 80114908 00111868  28 00 00 00 */	cmplwi r0, 0
/* 8011490C 0011186C  40 82 01 10 */	bne .L_80114A1C
/* 80114910 00111870  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114914 00111874  7F C6 F3 78 */	mr r6, r30
/* 80114918 00111878  80 BF 00 20 */	lwz r5, 0x20(r31)
/* 8011491C 0011187C  38 80 00 2B */	li r4, 0x2b
/* 80114920 00111880  38 E0 00 00 */	li r7, 0
/* 80114924 00111884  48 08 82 15 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80114928 00111888  90 7E 00 10 */	stw r3, 0x10(r30)
/* 8011492C 0011188C  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 80114930 00111890  28 03 00 00 */	cmplwi r3, 0
/* 80114934 00111894  41 82 00 7C */	beq .L_801149B0
/* 80114938 00111898  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 8011493C 0011189C  90 03 00 18 */	stw r0, 0x18(r3)
/* 80114940 001118A0  C0 0D DB 94 */	lfs f0, lbl_803E28B4@sda21(r13)
/* 80114944 001118A4  C0 2D DB 98 */	lfs f1, lbl_803E28B8@sda21(r13)
/* 80114948 001118A8  D0 01 00 54 */	stfs f0, 0x54(r1)
/* 8011494C 001118AC  C0 0D DB 9C */	lfs f0, lbl_803E28BC@sda21(r13)
/* 80114950 001118B0  D0 21 00 58 */	stfs f1, 0x58(r1)
/* 80114954 001118B4  D0 01 00 5C */	stfs f0, 0x5c(r1)
/* 80114958 001118B8  80 9E 00 10 */	lwz r4, 0x10(r30)
/* 8011495C 001118BC  80 61 00 54 */	lwz r3, 0x54(r1)
/* 80114960 001118C0  80 01 00 58 */	lwz r0, 0x58(r1)
/* 80114964 001118C4  90 64 01 DC */	stw r3, 0x1dc(r4)
/* 80114968 001118C8  90 04 01 E0 */	stw r0, 0x1e0(r4)
/* 8011496C 001118CC  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 80114970 001118D0  90 04 01 E4 */	stw r0, 0x1e4(r4)
/* 80114974 001118D4  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 80114978 001118D8  C0 02 9F 54 */	lfs f0, lbl_803EA154@sda21(r2)
/* 8011497C 001118DC  C0 23 00 00 */	lfs f1, 0(r3)
/* 80114980 001118E0  C0 42 9F 50 */	lfs f2, lbl_803EA150@sda21(r2)
/* 80114984 001118E4  C0 63 00 08 */	lfs f3, 8(r3)
/* 80114988 001118E8  EC 21 00 32 */	fmuls f1, f1, f0
/* 8011498C 001118EC  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 80114990 001118F0  EC 42 00 32 */	fmuls f2, f2, f0
/* 80114994 001118F4  EC 63 00 32 */	fmuls f3, f3, f0
/* 80114998 001118F8  D0 23 01 38 */	stfs f1, 0x138(r3)
/* 8011499C 001118FC  D0 43 01 3C */	stfs f2, 0x13c(r3)
/* 801149A0 00111900  D0 63 01 40 */	stfs f3, 0x140(r3)
/* 801149A4 00111904  80 03 00 84 */	lwz r0, 0x84(r3)
/* 801149A8 00111908  64 00 00 02 */	oris r0, r0, 2
/* 801149AC 0011190C  90 03 00 84 */	stw r0, 0x84(r3)
.L_801149B0:
/* 801149B0 00111910  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801149B4 00111914  7F C6 F3 78 */	mr r6, r30
/* 801149B8 00111918  80 BF 00 20 */	lwz r5, 0x20(r31)
/* 801149BC 0011191C  38 80 00 2C */	li r4, 0x2c
/* 801149C0 00111920  38 E0 00 00 */	li r7, 0
/* 801149C4 00111924  48 08 81 75 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801149C8 00111928  90 7E 00 14 */	stw r3, 0x14(r30)
/* 801149CC 0011192C  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 801149D0 00111930  28 03 00 00 */	cmplwi r3, 0
/* 801149D4 00111934  41 82 00 48 */	beq .L_80114A1C
/* 801149D8 00111938  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 801149DC 0011193C  90 03 00 18 */	stw r0, 0x18(r3)
/* 801149E0 00111940  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 801149E4 00111944  C0 02 9F 54 */	lfs f0, lbl_803EA154@sda21(r2)
/* 801149E8 00111948  C0 23 00 00 */	lfs f1, 0(r3)
/* 801149EC 0011194C  C0 42 9F 50 */	lfs f2, lbl_803EA150@sda21(r2)
/* 801149F0 00111950  EC 21 00 32 */	fmuls f1, f1, f0
/* 801149F4 00111954  C0 63 00 08 */	lfs f3, 8(r3)
/* 801149F8 00111958  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 801149FC 0011195C  EC 42 00 32 */	fmuls f2, f2, f0
/* 80114A00 00111960  EC 63 00 32 */	fmuls f3, f3, f0
/* 80114A04 00111964  D0 23 01 38 */	stfs f1, 0x138(r3)
/* 80114A08 00111968  D0 43 01 3C */	stfs f2, 0x13c(r3)
/* 80114A0C 0011196C  D0 63 01 40 */	stfs f3, 0x140(r3)
/* 80114A10 00111970  80 03 00 84 */	lwz r0, 0x84(r3)
/* 80114A14 00111974  64 00 00 02 */	oris r0, r0, 2
/* 80114A18 00111978  90 03 00 84 */	stw r0, 0x84(r3)
.L_80114A1C:
/* 80114A1C 0011197C  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80114A20 00111980  83 E1 00 7C */	lwz r31, 0x7c(r1)
/* 80114A24 00111984  83 C1 00 78 */	lwz r30, 0x78(r1)
/* 80114A28 00111988  38 21 00 80 */	addi r1, r1, 0x80
/* 80114A2C 0011198C  7C 08 03 A6 */	mtlr r0
/* 80114A30 00111990  4E 80 00 20 */	blr 
.endfn emit__10BurnEffectFR10EffectParm

.fn kill__10BurnEffectFv, global
/* 80114A34 00111994  7C 08 02 A6 */	mflr r0
/* 80114A38 00111998  90 01 00 04 */	stw r0, 4(r1)
/* 80114A3C 0011199C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80114A40 001119A0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80114A44 001119A4  7C 7F 1B 78 */	mr r31, r3
/* 80114A48 001119A8  80 83 00 10 */	lwz r4, 0x10(r3)
/* 80114A4C 001119AC  28 04 00 00 */	cmplwi r4, 0
/* 80114A50 001119B0  41 82 00 1C */	beq .L_80114A6C
/* 80114A54 001119B4  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114A58 001119B8  38 A0 00 00 */	li r5, 0
/* 80114A5C 001119BC  38 63 00 14 */	addi r3, r3, 0x14
/* 80114A60 001119C0  48 08 CB 65 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80114A64 001119C4  38 00 00 00 */	li r0, 0
/* 80114A68 001119C8  90 1F 00 10 */	stw r0, 0x10(r31)
.L_80114A6C:
/* 80114A6C 001119CC  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 80114A70 001119D0  28 04 00 00 */	cmplwi r4, 0
/* 80114A74 001119D4  41 82 00 1C */	beq .L_80114A90
/* 80114A78 001119D8  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114A7C 001119DC  38 A0 00 00 */	li r5, 0
/* 80114A80 001119E0  38 63 00 14 */	addi r3, r3, 0x14
/* 80114A84 001119E4  48 08 CB 41 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80114A88 001119E8  38 00 00 00 */	li r0, 0
/* 80114A8C 001119EC  90 1F 00 14 */	stw r0, 0x14(r31)
.L_80114A90:
/* 80114A90 001119F0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80114A94 001119F4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80114A98 001119F8  38 21 00 18 */	addi r1, r1, 0x18
/* 80114A9C 001119FC  7C 08 03 A6 */	mtlr r0
/* 80114AA0 00111A00  4E 80 00 20 */	blr 
.endfn kill__10BurnEffectFv

.fn invoke__10BurnEffectFPQ23zen17particleGenerator, global
/* 80114AA4 00111A04  38 60 00 01 */	li r3, 1
/* 80114AA8 00111A08  4E 80 00 20 */	blr 
.endfn invoke__10BurnEffectFPQ23zen17particleGenerator

.fn emit__16UfoSuikomiEffectFR10EffectParm, weak
/* 80114AAC 00111A0C  7C 08 02 A6 */	mflr r0
/* 80114AB0 00111A10  90 01 00 04 */	stw r0, 4(r1)
/* 80114AB4 00111A14  94 21 FF 40 */	stwu r1, -0xc0(r1)
/* 80114AB8 00111A18  DB E1 00 B8 */	stfd f31, 0xb8(r1)
/* 80114ABC 00111A1C  DB C1 00 B0 */	stfd f30, 0xb0(r1)
/* 80114AC0 00111A20  DB A1 00 A8 */	stfd f29, 0xa8(r1)
/* 80114AC4 00111A24  DB 81 00 A0 */	stfd f28, 0xa0(r1)
/* 80114AC8 00111A28  DB 61 00 98 */	stfd f27, 0x98(r1)
/* 80114ACC 00111A2C  DB 41 00 90 */	stfd f26, 0x90(r1)
/* 80114AD0 00111A30  93 E1 00 8C */	stw r31, 0x8c(r1)
/* 80114AD4 00111A34  93 C1 00 88 */	stw r30, 0x88(r1)
/* 80114AD8 00111A38  7C 7E 1B 78 */	mr r30, r3
/* 80114ADC 00111A3C  80 A4 00 00 */	lwz r5, 0(r4)
/* 80114AE0 00111A40  80 04 00 04 */	lwz r0, 4(r4)
/* 80114AE4 00111A44  90 A3 00 0C */	stw r5, 0xc(r3)
/* 80114AE8 00111A48  90 03 00 10 */	stw r0, 0x10(r3)
/* 80114AEC 00111A4C  80 04 00 08 */	lwz r0, 8(r4)
/* 80114AF0 00111A50  90 03 00 14 */	stw r0, 0x14(r3)
/* 80114AF4 00111A54  80 64 00 0C */	lwz r3, 0xc(r4)
/* 80114AF8 00111A58  80 04 00 10 */	lwz r0, 0x10(r4)
/* 80114AFC 00111A5C  90 7E 00 18 */	stw r3, 0x18(r30)
/* 80114B00 00111A60  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 80114B04 00111A64  80 04 00 14 */	lwz r0, 0x14(r4)
/* 80114B08 00111A68  90 1E 00 20 */	stw r0, 0x20(r30)
/* 80114B0C 00111A6C  80 1E 00 24 */	lwz r0, 0x24(r30)
/* 80114B10 00111A70  28 00 00 00 */	cmplwi r0, 0
/* 80114B14 00111A74  40 82 01 2C */	bne .L_80114C40
/* 80114B18 00111A78  28 1E 00 00 */	cmplwi r30, 0
/* 80114B1C 00111A7C  38 FE 00 00 */	addi r7, r30, 0
/* 80114B20 00111A80  41 82 00 08 */	beq .L_80114B28
/* 80114B24 00111A84  38 E7 00 04 */	addi r7, r7, 4
.L_80114B28:
/* 80114B28 00111A88  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114B2C 00111A8C  38 DE 00 00 */	addi r6, r30, 0
/* 80114B30 00111A90  38 BE 00 0C */	addi r5, r30, 0xc
/* 80114B34 00111A94  38 80 01 48 */	li r4, 0x148
/* 80114B38 00111A98  48 08 80 01 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80114B3C 00111A9C  90 7E 00 24 */	stw r3, 0x24(r30)
/* 80114B40 00111AA0  C3 5E 00 20 */	lfs f26, 0x20(r30)
/* 80114B44 00111AA4  C0 1E 00 14 */	lfs f0, 0x14(r30)
/* 80114B48 00111AA8  C3 7E 00 1C */	lfs f27, 0x1c(r30)
/* 80114B4C 00111AAC  C0 3E 00 10 */	lfs f1, 0x10(r30)
/* 80114B50 00111AB0  EF BA 00 28 */	fsubs f29, f26, f0
/* 80114B54 00111AB4  83 FE 00 24 */	lwz r31, 0x24(r30)
/* 80114B58 00111AB8  C3 9E 00 18 */	lfs f28, 0x18(r30)
/* 80114B5C 00111ABC  EF DB 08 28 */	fsubs f30, f27, f1
/* 80114B60 00111AC0  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 80114B64 00111AC4  7F E3 FB 78 */	mr r3, r31
/* 80114B68 00111AC8  EF FC 00 28 */	fsubs f31, f28, f0
/* 80114B6C 00111ACC  48 00 01 05 */	bl getGPos__Q23zen17particleGeneratorFv
/* 80114B70 00111AD0  C0 03 00 08 */	lfs f0, 8(r3)
/* 80114B74 00111AD4  38 C1 00 3C */	addi r6, r1, 0x3c
/* 80114B78 00111AD8  38 A1 00 38 */	addi r5, r1, 0x38
/* 80114B7C 00111ADC  EC 1A 00 28 */	fsubs f0, f26, f0
/* 80114B80 00111AE0  38 81 00 34 */	addi r4, r1, 0x34
/* 80114B84 00111AE4  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 80114B88 00111AE8  C0 03 00 04 */	lfs f0, 4(r3)
/* 80114B8C 00111AEC  EC 1B 00 28 */	fsubs f0, f27, f0
/* 80114B90 00111AF0  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 80114B94 00111AF4  C0 03 00 00 */	lfs f0, 0(r3)
/* 80114B98 00111AF8  38 61 00 48 */	addi r3, r1, 0x48
/* 80114B9C 00111AFC  EC 1C 00 28 */	fsubs f0, f28, f0
/* 80114BA0 00111B00  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 80114BA4 00111B04  4B F2 25 79 */	bl __ct__8Vector3fFRCfRCfRCf
/* 80114BA8 00111B08  C0 41 00 48 */	lfs f2, 0x48(r1)
/* 80114BAC 00111B0C  EC 3F 07 F2 */	fmuls f1, f31, f31
/* 80114BB0 00111B10  EC 1E 07 B2 */	fmuls f0, f30, f30
/* 80114BB4 00111B14  D0 5F 01 70 */	stfs f2, 0x170(r31)
/* 80114BB8 00111B18  EC 5D 07 72 */	fmuls f2, f29, f29
/* 80114BBC 00111B1C  C0 61 00 4C */	lfs f3, 0x4c(r1)
/* 80114BC0 00111B20  EC 01 00 2A */	fadds f0, f1, f0
/* 80114BC4 00111B24  D0 7F 01 74 */	stfs f3, 0x174(r31)
/* 80114BC8 00111B28  EC 22 00 2A */	fadds f1, f2, f0
/* 80114BCC 00111B2C  C0 01 00 50 */	lfs f0, 0x50(r1)
/* 80114BD0 00111B30  D0 1F 01 78 */	stfs f0, 0x178(r31)
/* 80114BD4 00111B34  C0 02 9F 58 */	lfs f0, lbl_803EA158@sda21(r2)
/* 80114BD8 00111B38  D0 1F 01 7C */	stfs f0, 0x17c(r31)
/* 80114BDC 00111B3C  80 1F 00 84 */	lwz r0, 0x84(r31)
/* 80114BE0 00111B40  64 00 00 10 */	oris r0, r0, 0x10
/* 80114BE4 00111B44  90 1F 00 84 */	stw r0, 0x84(r31)
/* 80114BE8 00111B48  4B EF 90 59 */	bl sqrtf__3stdFf
/* 80114BEC 00111B4C  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80114BF0 00111B50  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 80114BF4 00111B54  41 82 00 10 */	beq .L_80114C04
/* 80114BF8 00111B58  EF FF 08 24 */	fdivs f31, f31, f1
/* 80114BFC 00111B5C  EF DE 08 24 */	fdivs f30, f30, f1
/* 80114C00 00111B60  EF BD 08 24 */	fdivs f29, f29, f1
.L_80114C04:
/* 80114C04 00111B64  80 7E 00 24 */	lwz r3, 0x24(r30)
/* 80114C08 00111B68  D3 E3 01 44 */	stfs f31, 0x144(r3)
/* 80114C0C 00111B6C  D3 C3 01 48 */	stfs f30, 0x148(r3)
/* 80114C10 00111B70  D3 A3 01 4C */	stfs f29, 0x14c(r3)
/* 80114C14 00111B74  C0 02 9F 5C */	lfs f0, lbl_803EA15C@sda21(r2)
/* 80114C18 00111B78  D0 03 01 50 */	stfs f0, 0x150(r3)
/* 80114C1C 00111B7C  C0 02 9F 60 */	lfs f0, lbl_803EA160@sda21(r2)
/* 80114C20 00111B80  D0 03 01 54 */	stfs f0, 0x154(r3)
/* 80114C24 00111B84  C0 02 9F 64 */	lfs f0, lbl_803EA164@sda21(r2)
/* 80114C28 00111B88  D0 03 01 58 */	stfs f0, 0x158(r3)
/* 80114C2C 00111B8C  C0 02 9F 68 */	lfs f0, lbl_803EA168@sda21(r2)
/* 80114C30 00111B90  D0 03 01 5C */	stfs f0, 0x15c(r3)
/* 80114C34 00111B94  80 03 00 84 */	lwz r0, 0x84(r3)
/* 80114C38 00111B98  64 00 00 04 */	oris r0, r0, 4
/* 80114C3C 00111B9C  90 03 00 84 */	stw r0, 0x84(r3)
.L_80114C40:
/* 80114C40 00111BA0  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 80114C44 00111BA4  CB E1 00 B8 */	lfd f31, 0xb8(r1)
/* 80114C48 00111BA8  CB C1 00 B0 */	lfd f30, 0xb0(r1)
/* 80114C4C 00111BAC  CB A1 00 A8 */	lfd f29, 0xa8(r1)
/* 80114C50 00111BB0  CB 81 00 A0 */	lfd f28, 0xa0(r1)
/* 80114C54 00111BB4  CB 61 00 98 */	lfd f27, 0x98(r1)
/* 80114C58 00111BB8  CB 41 00 90 */	lfd f26, 0x90(r1)
/* 80114C5C 00111BBC  83 E1 00 8C */	lwz r31, 0x8c(r1)
/* 80114C60 00111BC0  83 C1 00 88 */	lwz r30, 0x88(r1)
/* 80114C64 00111BC4  38 21 00 C0 */	addi r1, r1, 0xc0
/* 80114C68 00111BC8  7C 08 03 A6 */	mtlr r0
/* 80114C6C 00111BCC  4E 80 00 20 */	blr 
.endfn emit__16UfoSuikomiEffectFR10EffectParm

.fn getGPos__Q23zen17particleGeneratorFv, weak
/* 80114C70 00111BD0  80 03 00 18 */	lwz r0, 0x18(r3)
/* 80114C74 00111BD4  28 00 00 00 */	cmplwi r0, 0
/* 80114C78 00111BD8  41 82 00 0C */	beq .L_80114C84
/* 80114C7C 00111BDC  7C 03 03 78 */	mr r3, r0
/* 80114C80 00111BE0  4E 80 00 20 */	blr 
.L_80114C84:
/* 80114C84 00111BE4  38 63 00 0C */	addi r3, r3, 0xc
/* 80114C88 00111BE8  4E 80 00 20 */	blr 
.endfn getGPos__Q23zen17particleGeneratorFv

.fn kill__16UfoSuikomiEffectFv, weak
/* 80114C8C 00111BEC  7C 08 02 A6 */	mflr r0
/* 80114C90 00111BF0  90 01 00 04 */	stw r0, 4(r1)
/* 80114C94 00111BF4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80114C98 00111BF8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80114C9C 00111BFC  7C 7F 1B 78 */	mr r31, r3
/* 80114CA0 00111C00  80 83 00 24 */	lwz r4, 0x24(r3)
/* 80114CA4 00111C04  28 04 00 00 */	cmplwi r4, 0
/* 80114CA8 00111C08  41 82 00 1C */	beq .L_80114CC4
/* 80114CAC 00111C0C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114CB0 00111C10  38 A0 00 00 */	li r5, 0
/* 80114CB4 00111C14  38 63 00 14 */	addi r3, r3, 0x14
/* 80114CB8 00111C18  48 08 C9 0D */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80114CBC 00111C1C  38 00 00 00 */	li r0, 0
/* 80114CC0 00111C20  90 1F 00 24 */	stw r0, 0x24(r31)
.L_80114CC4:
/* 80114CC4 00111C24  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80114CC8 00111C28  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80114CCC 00111C2C  38 21 00 18 */	addi r1, r1, 0x18
/* 80114CD0 00111C30  7C 08 03 A6 */	mtlr r0
/* 80114CD4 00111C34  4E 80 00 20 */	blr 
.endfn kill__16UfoSuikomiEffectFv

.fn emit__15WhistleTemplateFR10EffectParm, weak
/* 80114CD8 00111C38  7C 08 02 A6 */	mflr r0
/* 80114CDC 00111C3C  90 01 00 04 */	stw r0, 4(r1)
/* 80114CE0 00111C40  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80114CE4 00111C44  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80114CE8 00111C48  7C 7F 1B 78 */	mr r31, r3
/* 80114CEC 00111C4C  80 A4 00 00 */	lwz r5, 0(r4)
/* 80114CF0 00111C50  80 04 00 04 */	lwz r0, 4(r4)
/* 80114CF4 00111C54  90 A3 00 0C */	stw r5, 0xc(r3)
/* 80114CF8 00111C58  90 03 00 10 */	stw r0, 0x10(r3)
/* 80114CFC 00111C5C  80 04 00 08 */	lwz r0, 8(r4)
/* 80114D00 00111C60  90 03 00 14 */	stw r0, 0x14(r3)
/* 80114D04 00111C64  80 64 00 0C */	lwz r3, 0xc(r4)
/* 80114D08 00111C68  80 04 00 10 */	lwz r0, 0x10(r4)
/* 80114D0C 00111C6C  90 7F 00 18 */	stw r3, 0x18(r31)
/* 80114D10 00111C70  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 80114D14 00111C74  80 04 00 14 */	lwz r0, 0x14(r4)
/* 80114D18 00111C78  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80114D1C 00111C7C  80 1F 00 24 */	lwz r0, 0x24(r31)
/* 80114D20 00111C80  28 00 00 00 */	cmplwi r0, 0
/* 80114D24 00111C84  40 82 00 80 */	bne .L_80114DA4
/* 80114D28 00111C88  80 1F 00 28 */	lwz r0, 0x28(r31)
/* 80114D2C 00111C8C  28 00 00 00 */	cmplwi r0, 0
/* 80114D30 00111C90  41 82 00 08 */	beq .L_80114D38
/* 80114D34 00111C94  48 00 00 70 */	b .L_80114DA4
.L_80114D38:
/* 80114D38 00111C98  28 1F 00 00 */	cmplwi r31, 0
/* 80114D3C 00111C9C  38 FF 00 00 */	addi r7, r31, 0
/* 80114D40 00111CA0  41 82 00 08 */	beq .L_80114D48
/* 80114D44 00111CA4  38 E7 00 04 */	addi r7, r7, 4
.L_80114D48:
/* 80114D48 00111CA8  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114D4C 00111CAC  7F E6 FB 78 */	mr r6, r31
/* 80114D50 00111CB0  80 9F 00 2C */	lwz r4, 0x2c(r31)
/* 80114D54 00111CB4  38 BF 00 18 */	addi r5, r31, 0x18
/* 80114D58 00111CB8  48 08 7D E1 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80114D5C 00111CBC  28 1F 00 00 */	cmplwi r31, 0
/* 80114D60 00111CC0  90 7F 00 24 */	stw r3, 0x24(r31)
/* 80114D64 00111CC4  7F E7 FB 78 */	mr r7, r31
/* 80114D68 00111CC8  41 82 00 08 */	beq .L_80114D70
/* 80114D6C 00111CCC  38 E7 00 04 */	addi r7, r7, 4
.L_80114D70:
/* 80114D70 00111CD0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114D74 00111CD4  7F E6 FB 78 */	mr r6, r31
/* 80114D78 00111CD8  80 9F 00 30 */	lwz r4, 0x30(r31)
/* 80114D7C 00111CDC  38 BF 00 18 */	addi r5, r31, 0x18
/* 80114D80 00111CE0  48 08 7D B9 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80114D84 00111CE4  90 7F 00 28 */	stw r3, 0x28(r31)
/* 80114D88 00111CE8  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 80114D8C 00111CEC  28 04 00 00 */	cmplwi r4, 0
/* 80114D90 00111CF0  41 82 00 14 */	beq .L_80114DA4
/* 80114D94 00111CF4  88 04 00 68 */	lbz r0, 0x68(r4)
/* 80114D98 00111CF8  38 60 00 01 */	li r3, 1
/* 80114D9C 00111CFC  50 60 2E B4 */	rlwimi r0, r3, 5, 0x1a, 0x1a
/* 80114DA0 00111D00  98 04 00 68 */	stb r0, 0x68(r4)
.L_80114DA4:
/* 80114DA4 00111D04  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80114DA8 00111D08  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80114DAC 00111D0C  38 21 00 20 */	addi r1, r1, 0x20
/* 80114DB0 00111D10  7C 08 03 A6 */	mtlr r0
/* 80114DB4 00111D14  4E 80 00 20 */	blr 
.endfn emit__15WhistleTemplateFR10EffectParm

.fn kill__15WhistleTemplateFv, weak
/* 80114DB8 00111D18  7C 08 02 A6 */	mflr r0
/* 80114DBC 00111D1C  90 01 00 04 */	stw r0, 4(r1)
/* 80114DC0 00111D20  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80114DC4 00111D24  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80114DC8 00111D28  7C 7F 1B 78 */	mr r31, r3
/* 80114DCC 00111D2C  80 83 00 24 */	lwz r4, 0x24(r3)
/* 80114DD0 00111D30  28 04 00 00 */	cmplwi r4, 0
/* 80114DD4 00111D34  41 82 00 1C */	beq .L_80114DF0
/* 80114DD8 00111D38  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114DDC 00111D3C  38 A0 00 00 */	li r5, 0
/* 80114DE0 00111D40  38 63 00 14 */	addi r3, r3, 0x14
/* 80114DE4 00111D44  48 08 C7 E1 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80114DE8 00111D48  38 00 00 00 */	li r0, 0
/* 80114DEC 00111D4C  90 1F 00 24 */	stw r0, 0x24(r31)
.L_80114DF0:
/* 80114DF0 00111D50  80 9F 00 28 */	lwz r4, 0x28(r31)
/* 80114DF4 00111D54  28 04 00 00 */	cmplwi r4, 0
/* 80114DF8 00111D58  41 82 00 1C */	beq .L_80114E14
/* 80114DFC 00111D5C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80114E00 00111D60  38 A0 00 00 */	li r5, 0
/* 80114E04 00111D64  38 63 00 14 */	addi r3, r3, 0x14
/* 80114E08 00111D68  48 08 C7 BD */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80114E0C 00111D6C  38 00 00 00 */	li r0, 0
/* 80114E10 00111D70  90 1F 00 28 */	stw r0, 0x28(r31)
.L_80114E14:
/* 80114E14 00111D74  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80114E18 00111D78  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80114E1C 00111D7C  38 21 00 18 */	addi r1, r1, 0x18
/* 80114E20 00111D80  7C 08 03 A6 */	mtlr r0
/* 80114E24 00111D84  4E 80 00 20 */	blr 
.endfn kill__15WhistleTemplateFv

.fn invoke__15WhistleTemplateFPQ23zen17particleGeneratorPQ23zen11particleMdl, weak
/* 80114E28 00111D88  7C 08 02 A6 */	mflr r0
/* 80114E2C 00111D8C  7C 66 1B 78 */	mr r6, r3
/* 80114E30 00111D90  90 01 00 04 */	stw r0, 4(r1)
/* 80114E34 00111D94  3C 80 43 30 */	lis r4, 0x4330
/* 80114E38 00111D98  94 21 FE D0 */	stwu r1, -0x130(r1)
/* 80114E3C 00111D9C  DB E1 01 28 */	stfd f31, 0x128(r1)
/* 80114E40 00111DA0  93 E1 01 24 */	stw r31, 0x124(r1)
/* 80114E44 00111DA4  7C BF 2B 78 */	mr r31, r5
/* 80114E48 00111DA8  93 C1 01 20 */	stw r30, 0x120(r1)
/* 80114E4C 00111DAC  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 80114E50 00111DB0  C0 03 00 18 */	lfs f0, 0x18(r3)
/* 80114E54 00111DB4  C0 63 00 10 */	lfs f3, 0x10(r3)
/* 80114E58 00111DB8  C0 43 00 1C */	lfs f2, 0x1c(r3)
/* 80114E5C 00111DBC  EC 01 00 28 */	fsubs f0, f1, f0
/* 80114E60 00111DC0  C0 83 00 14 */	lfs f4, 0x14(r3)
/* 80114E64 00111DC4  C0 23 00 20 */	lfs f1, 0x20(r3)
/* 80114E68 00111DC8  EC 43 10 28 */	fsubs f2, f3, f2
/* 80114E6C 00111DCC  D0 01 01 00 */	stfs f0, 0x100(r1)
/* 80114E70 00111DD0  EC 04 08 28 */	fsubs f0, f4, f1
/* 80114E74 00111DD4  D0 41 01 04 */	stfs f2, 0x104(r1)
/* 80114E78 00111DD8  D0 01 01 08 */	stfs f0, 0x108(r1)
/* 80114E7C 00111DDC  A8 65 00 2E */	lha r3, 0x2e(r5)
/* 80114E80 00111DE0  A8 05 00 2C */	lha r0, 0x2c(r5)
/* 80114E84 00111DE4  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80114E88 00111DE8  C8 42 9F 78 */	lfd f2, lbl_803EA178@sda21(r2)
/* 80114E8C 00111DEC  90 61 01 1C */	stw r3, 0x11c(r1)
/* 80114E90 00111DF0  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80114E94 00111DF4  80 66 00 18 */	lwz r3, 0x18(r6)
/* 80114E98 00111DF8  90 01 01 14 */	stw r0, 0x114(r1)
/* 80114E9C 00111DFC  80 06 00 1C */	lwz r0, 0x1c(r6)
/* 80114EA0 00111E00  90 81 01 18 */	stw r4, 0x118(r1)
/* 80114EA4 00111E04  90 81 01 10 */	stw r4, 0x110(r1)
/* 80114EA8 00111E08  C8 21 01 18 */	lfd f1, 0x118(r1)
/* 80114EAC 00111E0C  C8 01 01 10 */	lfd f0, 0x110(r1)
/* 80114EB0 00111E10  EC 21 10 28 */	fsubs f1, f1, f2
/* 80114EB4 00111E14  90 65 00 18 */	stw r3, 0x18(r5)
/* 80114EB8 00111E18  EC 00 10 28 */	fsubs f0, f0, f2
/* 80114EBC 00111E1C  90 05 00 1C */	stw r0, 0x1c(r5)
/* 80114EC0 00111E20  EF E1 00 24 */	fdivs f31, f1, f0
/* 80114EC4 00111E24  80 06 00 20 */	lwz r0, 0x20(r6)
/* 80114EC8 00111E28  90 05 00 20 */	stw r0, 0x20(r5)
/* 80114ECC 00111E2C  C0 01 01 00 */	lfs f0, 0x100(r1)
/* 80114ED0 00111E30  EC 00 07 F2 */	fmuls f0, f0, f31
/* 80114ED4 00111E34  D0 01 00 58 */	stfs f0, 0x58(r1)
/* 80114ED8 00111E38  C0 01 00 58 */	lfs f0, 0x58(r1)
/* 80114EDC 00111E3C  D0 01 00 7C */	stfs f0, 0x7c(r1)
/* 80114EE0 00111E40  C0 01 01 04 */	lfs f0, 0x104(r1)
/* 80114EE4 00111E44  EC 00 07 F2 */	fmuls f0, f0, f31
/* 80114EE8 00111E48  D0 01 00 80 */	stfs f0, 0x80(r1)
/* 80114EEC 00111E4C  C0 01 01 08 */	lfs f0, 0x108(r1)
/* 80114EF0 00111E50  EC 00 07 F2 */	fmuls f0, f0, f31
/* 80114EF4 00111E54  D0 01 00 84 */	stfs f0, 0x84(r1)
/* 80114EF8 00111E58  80 61 00 7C */	lwz r3, 0x7c(r1)
/* 80114EFC 00111E5C  80 01 00 80 */	lwz r0, 0x80(r1)
/* 80114F00 00111E60  90 65 00 0C */	stw r3, 0xc(r5)
/* 80114F04 00111E64  90 05 00 10 */	stw r0, 0x10(r5)
/* 80114F08 00111E68  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80114F0C 00111E6C  90 05 00 14 */	stw r0, 0x14(r5)
/* 80114F10 00111E70  C0 22 9F 6C */	lfs f1, lbl_803EA16C@sda21(r2)
/* 80114F14 00111E74  C0 06 00 1C */	lfs f0, 0x1c(r6)
/* 80114F18 00111E78  C0 46 00 10 */	lfs f2, 0x10(r6)
/* 80114F1C 00111E7C  EC 01 00 2A */	fadds f0, f1, f0
/* 80114F20 00111E80  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80114F24 00111E84  40 80 01 F4 */	bge .L_80115118
/* 80114F28 00111E88  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 80114F2C 00111E8C  38 80 00 01 */	li r4, 1
/* 80114F30 00111E90  C0 26 00 0C */	lfs f1, 0xc(r6)
/* 80114F34 00111E94  C0 46 00 14 */	lfs f2, 0x14(r6)
/* 80114F38 00111E98  4B F5 32 A1 */	bl getCurrTri__6MapMgrFffb
/* 80114F3C 00111E9C  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80114F40 00111EA0  7C 7E 1B 78 */	mr r30, r3
/* 80114F44 00111EA4  38 60 00 08 */	li r3, 8
/* 80114F48 00111EA8  D0 01 00 D8 */	stfs f0, 0xd8(r1)
/* 80114F4C 00111EAC  D0 01 00 DC */	stfs f0, 0xdc(r1)
/* 80114F50 00111EB0  D0 01 00 E0 */	stfs f0, 0xe0(r1)
/* 80114F54 00111EB4  D0 01 00 E4 */	stfs f0, 0xe4(r1)
/* 80114F58 00111EB8  D0 01 00 E8 */	stfs f0, 0xe8(r1)
/* 80114F5C 00111EBC  D0 01 00 EC */	stfs f0, 0xec(r1)
/* 80114F60 00111EC0  D0 01 00 F0 */	stfs f0, 0xf0(r1)
/* 80114F64 00111EC4  D0 01 00 F4 */	stfs f0, 0xf4(r1)
/* 80114F68 00111EC8  48 00 01 D0 */	b .L_80115138
.L_80114F6C:
/* 80114F6C 00111ECC  20 03 00 09 */	subfic r0, r3, 9
/* 80114F70 00111ED0  2C 03 00 09 */	cmpwi r3, 9
/* 80114F74 00111ED4  7C 09 03 A6 */	mtctr r0
/* 80114F78 00111ED8  40 80 00 10 */	bge .L_80114F88
.L_80114F7C:
/* 80114F7C 00111EDC  D0 04 00 00 */	stfs f0, 0(r4)
/* 80114F80 00111EE0  38 84 00 04 */	addi r4, r4, 4
/* 80114F84 00111EE4  42 00 FF F8 */	bdnz .L_80114F7C
.L_80114F88:
/* 80114F88 00111EE8  C0 22 9F 70 */	lfs f1, lbl_803EA170@sda21(r2)
/* 80114F8C 00111EEC  38 60 00 08 */	li r3, 8
/* 80114F90 00111EF0  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80114F94 00111EF4  D0 21 00 F8 */	stfs f1, 0xf8(r1)
/* 80114F98 00111EF8  D0 21 00 E8 */	stfs f1, 0xe8(r1)
/* 80114F9C 00111EFC  D0 21 00 D8 */	stfs f1, 0xd8(r1)
/* 80114FA0 00111F00  D0 01 00 B4 */	stfs f0, 0xb4(r1)
/* 80114FA4 00111F04  D0 01 00 B8 */	stfs f0, 0xb8(r1)
/* 80114FA8 00111F08  D0 01 00 BC */	stfs f0, 0xbc(r1)
/* 80114FAC 00111F0C  D0 01 00 C0 */	stfs f0, 0xc0(r1)
/* 80114FB0 00111F10  D0 01 00 C4 */	stfs f0, 0xc4(r1)
/* 80114FB4 00111F14  D0 01 00 C8 */	stfs f0, 0xc8(r1)
/* 80114FB8 00111F18  D0 01 00 CC */	stfs f0, 0xcc(r1)
/* 80114FBC 00111F1C  D0 01 00 D0 */	stfs f0, 0xd0(r1)
/* 80114FC0 00111F20  48 00 01 88 */	b .L_80115148
.L_80114FC4:
/* 80114FC4 00111F24  20 03 00 09 */	subfic r0, r3, 9
/* 80114FC8 00111F28  2C 03 00 09 */	cmpwi r3, 9
/* 80114FCC 00111F2C  7C 09 03 A6 */	mtctr r0
/* 80114FD0 00111F30  40 80 00 10 */	bge .L_80114FE0
.L_80114FD4:
/* 80114FD4 00111F34  D0 04 00 00 */	stfs f0, 0(r4)
/* 80114FD8 00111F38  38 84 00 04 */	addi r4, r4, 4
/* 80114FDC 00111F3C  42 00 FF F8 */	bdnz .L_80114FD4
.L_80114FE0:
/* 80114FE0 00111F40  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80114FE4 00111F44  C0 42 9F 70 */	lfs f2, lbl_803EA170@sda21(r2)
/* 80114FE8 00111F48  D0 01 00 AC */	stfs f0, 0xac(r1)
/* 80114FEC 00111F4C  C0 21 01 00 */	lfs f1, 0x100(r1)
/* 80114FF0 00111F50  D0 41 00 D4 */	stfs f2, 0xd4(r1)
/* 80114FF4 00111F54  EC 21 00 72 */	fmuls f1, f1, f1
/* 80114FF8 00111F58  D0 01 00 9C */	stfs f0, 0x9c(r1)
/* 80114FFC 00111F5C  D0 41 00 C4 */	stfs f2, 0xc4(r1)
/* 80115000 00111F60  D0 01 00 A8 */	stfs f0, 0xa8(r1)
/* 80115004 00111F64  D0 01 00 98 */	stfs f0, 0x98(r1)
/* 80115008 00111F68  D0 41 00 B4 */	stfs f2, 0xb4(r1)
/* 8011500C 00111F6C  D0 01 00 A4 */	stfs f0, 0xa4(r1)
/* 80115010 00111F70  D0 01 00 94 */	stfs f0, 0x94(r1)
/* 80115014 00111F74  C0 01 01 04 */	lfs f0, 0x104(r1)
/* 80115018 00111F78  C0 41 01 08 */	lfs f2, 0x108(r1)
/* 8011501C 00111F7C  EC 00 00 32 */	fmuls f0, f0, f0
/* 80115020 00111F80  EC 42 00 B2 */	fmuls f2, f2, f2
/* 80115024 00111F84  EC 01 00 2A */	fadds f0, f1, f0
/* 80115028 00111F88  EC 22 00 2A */	fadds f1, f2, f0
/* 8011502C 00111F8C  4B EF 8C 15 */	bl sqrtf__3stdFf
/* 80115030 00111F90  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80115034 00111F94  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 80115038 00111F98  41 82 00 28 */	beq .L_80115060
/* 8011503C 00111F9C  C0 01 01 00 */	lfs f0, 0x100(r1)
/* 80115040 00111FA0  EC 00 08 24 */	fdivs f0, f0, f1
/* 80115044 00111FA4  D0 01 01 00 */	stfs f0, 0x100(r1)
/* 80115048 00111FA8  C0 01 01 04 */	lfs f0, 0x104(r1)
/* 8011504C 00111FAC  EC 00 08 24 */	fdivs f0, f0, f1
/* 80115050 00111FB0  D0 01 01 04 */	stfs f0, 0x104(r1)
/* 80115054 00111FB4  C0 01 01 08 */	lfs f0, 0x108(r1)
/* 80115058 00111FB8  EC 00 08 24 */	fdivs f0, f0, f1
/* 8011505C 00111FBC  D0 01 01 08 */	stfs f0, 0x108(r1)
.L_80115060:
/* 80115060 00111FC0  38 61 01 00 */	addi r3, r1, 0x100
/* 80115064 00111FC4  38 81 00 D8 */	addi r4, r1, 0xd8
/* 80115068 00111FC8  48 08 6A 79 */	bl makeRotMatrix__3zenFR8Vector3fR8Matrix3f
/* 8011506C 00111FCC  C0 6D DB 68 */	lfs f3, lbl_803E2888@sda21(r13)
/* 80115070 00111FD0  38 61 00 70 */	addi r3, r1, 0x70
/* 80115074 00111FD4  C0 1E 00 18 */	lfs f0, 0x18(r30)
/* 80115078 00111FD8  38 81 00 B4 */	addi r4, r1, 0xb4
/* 8011507C 00111FDC  C0 5E 00 20 */	lfs f2, 0x20(r30)
/* 80115080 00111FE0  C0 3E 00 1C */	lfs f1, 0x1c(r30)
/* 80115084 00111FE4  EC 00 00 F2 */	fmuls f0, f0, f3
/* 80115088 00111FE8  EC 42 00 F2 */	fmuls f2, f2, f3
/* 8011508C 00111FEC  EC 21 00 F2 */	fmuls f1, f1, f3
/* 80115090 00111FF0  D0 01 00 54 */	stfs f0, 0x54(r1)
/* 80115094 00111FF4  C0 01 00 54 */	lfs f0, 0x54(r1)
/* 80115098 00111FF8  D0 01 00 70 */	stfs f0, 0x70(r1)
/* 8011509C 00111FFC  D0 21 00 74 */	stfs f1, 0x74(r1)
/* 801150A0 00112000  D0 41 00 78 */	stfs f2, 0x78(r1)
/* 801150A4 00112004  48 08 6A 3D */	bl makeRotMatrix__3zenFR8Vector3fR8Matrix3f
/* 801150A8 00112008  38 61 00 A4 */	addi r3, r1, 0xa4
/* 801150AC 0011200C  38 81 00 D8 */	addi r4, r1, 0xd8
/* 801150B0 00112010  4B F2 28 0D */	bl fromMat3f__4QuatFR8Matrix3f
/* 801150B4 00112014  38 61 00 94 */	addi r3, r1, 0x94
/* 801150B8 00112018  38 81 00 B4 */	addi r4, r1, 0xb4
/* 801150BC 0011201C  4B F2 28 01 */	bl fromMat3f__4QuatFR8Matrix3f
/* 801150C0 00112020  FC 20 F8 90 */	fmr f1, f31
/* 801150C4 00112024  38 61 00 A4 */	addi r3, r1, 0xa4
/* 801150C8 00112028  38 81 00 94 */	addi r4, r1, 0x94
/* 801150CC 0011202C  38 A0 00 00 */	li r5, 0
/* 801150D0 00112030  4B F2 30 B5 */	bl slerp__4QuatFR4Quatfi
/* 801150D4 00112034  38 61 00 A4 */	addi r3, r1, 0xa4
/* 801150D8 00112038  38 9F 00 5C */	addi r4, r31, 0x5c
/* 801150DC 0011203C  4B F2 2F A9 */	bl genVectorY__4QuatFR8Vector3f
/* 801150E0 00112040  38 61 00 A4 */	addi r3, r1, 0xa4
/* 801150E4 00112044  38 9F 00 34 */	addi r4, r31, 0x34
/* 801150E8 00112048  4B F2 2F 1D */	bl genVectorX__4QuatFR8Vector3f
/* 801150EC 0011204C  C0 1F 00 34 */	lfs f0, 0x34(r31)
/* 801150F0 00112050  C0 22 9F 54 */	lfs f1, lbl_803EA154@sda21(r2)
/* 801150F4 00112054  EC 00 00 72 */	fmuls f0, f0, f1
/* 801150F8 00112058  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 801150FC 0011205C  C0 1F 00 38 */	lfs f0, 0x38(r31)
/* 80115100 00112060  EC 00 00 72 */	fmuls f0, f0, f1
/* 80115104 00112064  D0 1F 00 38 */	stfs f0, 0x38(r31)
/* 80115108 00112068  C0 1F 00 3C */	lfs f0, 0x3c(r31)
/* 8011510C 0011206C  EC 00 00 72 */	fmuls f0, f0, f1
/* 80115110 00112070  D0 1F 00 3C */	stfs f0, 0x3c(r31)
/* 80115114 00112074  48 00 00 1C */	b .L_80115130
.L_80115118:
/* 80115118 00112078  C0 01 01 00 */	lfs f0, 0x100(r1)
/* 8011511C 0011207C  D0 1F 00 5C */	stfs f0, 0x5c(r31)
/* 80115120 00112080  C0 01 01 04 */	lfs f0, 0x104(r1)
/* 80115124 00112084  D0 1F 00 60 */	stfs f0, 0x60(r31)
/* 80115128 00112088  C0 01 01 08 */	lfs f0, 0x108(r1)
/* 8011512C 0011208C  D0 1F 00 64 */	stfs f0, 0x64(r31)
.L_80115130:
/* 80115130 00112090  38 60 00 00 */	li r3, 0
/* 80115134 00112094  48 00 00 24 */	b .L_80115158
.L_80115138:
/* 80115138 00112098  54 60 10 3A */	slwi r0, r3, 2
/* 8011513C 0011209C  38 81 00 D8 */	addi r4, r1, 0xd8
/* 80115140 001120A0  7C 84 02 14 */	add r4, r4, r0
/* 80115144 001120A4  4B FF FE 28 */	b .L_80114F6C
.L_80115148:
/* 80115148 001120A8  54 60 10 3A */	slwi r0, r3, 2
/* 8011514C 001120AC  38 81 00 B4 */	addi r4, r1, 0xb4
/* 80115150 001120B0  7C 84 02 14 */	add r4, r4, r0
/* 80115154 001120B4  4B FF FE 70 */	b .L_80114FC4
.L_80115158:
/* 80115158 001120B8  80 01 01 34 */	lwz r0, 0x134(r1)
/* 8011515C 001120BC  CB E1 01 28 */	lfd f31, 0x128(r1)
/* 80115160 001120C0  83 E1 01 24 */	lwz r31, 0x124(r1)
/* 80115164 001120C4  83 C1 01 20 */	lwz r30, 0x120(r1)
/* 80115168 001120C8  38 21 01 30 */	addi r1, r1, 0x130
/* 8011516C 001120CC  7C 08 03 A6 */	mtlr r0
/* 80115170 001120D0  4E 80 00 20 */	blr 
.endfn invoke__15WhistleTemplateFPQ23zen17particleGeneratorPQ23zen11particleMdl

.fn emit__15BombEffectLightFR10EffectParm, weak
/* 80115174 001120D4  7C 08 02 A6 */	mflr r0
/* 80115178 001120D8  38 C0 00 00 */	li r6, 0
/* 8011517C 001120DC  90 01 00 04 */	stw r0, 4(r1)
/* 80115180 001120E0  38 E0 00 00 */	li r7, 0
/* 80115184 001120E4  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80115188 001120E8  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8011518C 001120EC  7C 9F 23 78 */	mr r31, r4
/* 80115190 001120F0  38 BF 00 00 */	addi r5, r31, 0
/* 80115194 001120F4  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115198 001120F8  38 80 00 20 */	li r4, 0x20
/* 8011519C 001120FC  48 08 79 9D */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801151A0 00112100  28 03 00 00 */	cmplwi r3, 0
/* 801151A4 00112104  41 82 00 34 */	beq .L_801151D8
/* 801151A8 00112108  C0 0D DB 5C */	lfs f0, lbl_803E287C@sda21(r13)
/* 801151AC 0011210C  C0 2D DB 60 */	lfs f1, lbl_803E2880@sda21(r13)
/* 801151B0 00112110  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 801151B4 00112114  C0 0D DB 64 */	lfs f0, lbl_803E2884@sda21(r13)
/* 801151B8 00112118  D0 21 00 14 */	stfs f1, 0x14(r1)
/* 801151BC 0011211C  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 801151C0 00112120  80 81 00 10 */	lwz r4, 0x10(r1)
/* 801151C4 00112124  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801151C8 00112128  90 83 01 DC */	stw r4, 0x1dc(r3)
/* 801151CC 0011212C  90 03 01 E0 */	stw r0, 0x1e0(r3)
/* 801151D0 00112130  80 01 00 18 */	lwz r0, 0x18(r1)
/* 801151D4 00112134  90 03 01 E4 */	stw r0, 0x1e4(r3)
.L_801151D8:
/* 801151D8 00112138  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801151DC 0011213C  38 BF 00 00 */	addi r5, r31, 0
/* 801151E0 00112140  38 80 00 17 */	li r4, 0x17
/* 801151E4 00112144  38 C0 00 00 */	li r6, 0
/* 801151E8 00112148  38 E0 00 00 */	li r7, 0
/* 801151EC 0011214C  48 08 79 4D */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801151F0 00112150  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801151F4 00112154  38 BF 00 00 */	addi r5, r31, 0
/* 801151F8 00112158  38 80 00 18 */	li r4, 0x18
/* 801151FC 0011215C  38 C0 00 00 */	li r6, 0
/* 80115200 00112160  38 E0 00 00 */	li r7, 0
/* 80115204 00112164  48 08 79 35 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115208 00112168  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8011520C 0011216C  38 BF 00 00 */	addi r5, r31, 0
/* 80115210 00112170  38 80 00 19 */	li r4, 0x19
/* 80115214 00112174  38 C0 00 00 */	li r6, 0
/* 80115218 00112178  38 E0 00 00 */	li r7, 0
/* 8011521C 0011217C  48 08 79 1D */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115220 00112180  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115224 00112184  38 BF 00 00 */	addi r5, r31, 0
/* 80115228 00112188  38 80 00 1A */	li r4, 0x1a
/* 8011522C 0011218C  38 C0 00 00 */	li r6, 0
/* 80115230 00112190  38 E0 00 00 */	li r7, 0
/* 80115234 00112194  48 08 79 05 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115238 00112198  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8011523C 0011219C  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80115240 001121A0  38 21 00 28 */	addi r1, r1, 0x28
/* 80115244 001121A4  7C 08 03 A6 */	mtlr r0
/* 80115248 001121A8  4E 80 00 20 */	blr 
.endfn emit__15BombEffectLightFR10EffectParm

.fn kill__15BombEffectLightFv, weak
/* 8011524C 001121AC  4E 80 00 20 */	blr 
.endfn kill__15BombEffectLightFv

.fn emit__10BombEffectFR10EffectParm, weak
/* 80115250 001121B0  7C 08 02 A6 */	mflr r0
/* 80115254 001121B4  38 C0 00 00 */	li r6, 0
/* 80115258 001121B8  90 01 00 04 */	stw r0, 4(r1)
/* 8011525C 001121BC  38 E0 00 00 */	li r7, 0
/* 80115260 001121C0  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80115264 001121C4  93 E1 00 24 */	stw r31, 0x24(r1)
/* 80115268 001121C8  7C 9F 23 78 */	mr r31, r4
/* 8011526C 001121CC  38 BF 00 00 */	addi r5, r31, 0
/* 80115270 001121D0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115274 001121D4  38 80 00 20 */	li r4, 0x20
/* 80115278 001121D8  48 08 78 C1 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8011527C 001121DC  28 03 00 00 */	cmplwi r3, 0
/* 80115280 001121E0  41 82 00 34 */	beq .L_801152B4
/* 80115284 001121E4  C0 0D DB 50 */	lfs f0, lbl_803E2870@sda21(r13)
/* 80115288 001121E8  C0 2D DB 54 */	lfs f1, lbl_803E2874@sda21(r13)
/* 8011528C 001121EC  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 80115290 001121F0  C0 0D DB 58 */	lfs f0, lbl_803E2878@sda21(r13)
/* 80115294 001121F4  D0 21 00 14 */	stfs f1, 0x14(r1)
/* 80115298 001121F8  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 8011529C 001121FC  80 81 00 10 */	lwz r4, 0x10(r1)
/* 801152A0 00112200  80 01 00 14 */	lwz r0, 0x14(r1)
/* 801152A4 00112204  90 83 01 DC */	stw r4, 0x1dc(r3)
/* 801152A8 00112208  90 03 01 E0 */	stw r0, 0x1e0(r3)
/* 801152AC 0011220C  80 01 00 18 */	lwz r0, 0x18(r1)
/* 801152B0 00112210  90 03 01 E4 */	stw r0, 0x1e4(r3)
.L_801152B4:
/* 801152B4 00112214  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801152B8 00112218  38 BF 00 00 */	addi r5, r31, 0
/* 801152BC 0011221C  38 80 00 1F */	li r4, 0x1f
/* 801152C0 00112220  38 C0 00 00 */	li r6, 0
/* 801152C4 00112224  38 E0 00 00 */	li r7, 0
/* 801152C8 00112228  48 08 78 71 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801152CC 0011222C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801152D0 00112230  38 BF 00 00 */	addi r5, r31, 0
/* 801152D4 00112234  38 80 00 21 */	li r4, 0x21
/* 801152D8 00112238  38 C0 00 00 */	li r6, 0
/* 801152DC 0011223C  38 E0 00 00 */	li r7, 0
/* 801152E0 00112240  48 08 78 59 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801152E4 00112244  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801152E8 00112248  38 BF 00 00 */	addi r5, r31, 0
/* 801152EC 0011224C  38 80 00 1E */	li r4, 0x1e
/* 801152F0 00112250  38 C0 00 00 */	li r6, 0
/* 801152F4 00112254  38 E0 00 00 */	li r7, 0
/* 801152F8 00112258  48 08 78 41 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801152FC 0011225C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115300 00112260  38 BF 00 00 */	addi r5, r31, 0
/* 80115304 00112264  38 80 00 22 */	li r4, 0x22
/* 80115308 00112268  38 C0 00 00 */	li r6, 0
/* 8011530C 0011226C  38 E0 00 00 */	li r7, 0
/* 80115310 00112270  48 08 78 29 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115314 00112274  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115318 00112278  38 BF 00 00 */	addi r5, r31, 0
/* 8011531C 0011227C  38 80 00 23 */	li r4, 0x23
/* 80115320 00112280  38 C0 00 00 */	li r6, 0
/* 80115324 00112284  38 E0 00 00 */	li r7, 0
/* 80115328 00112288  48 08 78 11 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8011532C 0011228C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80115330 00112290  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80115334 00112294  38 21 00 28 */	addi r1, r1, 0x28
/* 80115338 00112298  7C 08 03 A6 */	mtlr r0
/* 8011533C 0011229C  4E 80 00 20 */	blr 
.endfn emit__10BombEffectFR10EffectParm

.fn kill__10BombEffectFv, weak
/* 80115340 001122A0  4E 80 00 20 */	blr 
.endfn kill__10BombEffectFv

.fn emit__12SimpleEffectFR10EffectParm, weak
/* 80115344 001122A4  7C 08 02 A6 */	mflr r0
/* 80115348 001122A8  7C 85 23 78 */	mr r5, r4
/* 8011534C 001122AC  90 01 00 04 */	stw r0, 4(r1)
/* 80115350 001122B0  38 C0 00 00 */	li r6, 0
/* 80115354 001122B4  38 E0 00 00 */	li r7, 0
/* 80115358 001122B8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011535C 001122BC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80115360 001122C0  7C 7F 1B 78 */	mr r31, r3
/* 80115364 001122C4  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115368 001122C8  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 8011536C 001122CC  48 08 77 CD */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115370 001122D0  90 7F 00 10 */	stw r3, 0x10(r31)
/* 80115374 001122D4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80115378 001122D8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011537C 001122DC  38 21 00 18 */	addi r1, r1, 0x18
/* 80115380 001122E0  7C 08 03 A6 */	mtlr r0
/* 80115384 001122E4  4E 80 00 20 */	blr 
.endfn emit__12SimpleEffectFR10EffectParm

.fn kill__12SimpleEffectFv, weak
/* 80115388 001122E8  7C 08 02 A6 */	mflr r0
/* 8011538C 001122EC  90 01 00 04 */	stw r0, 4(r1)
/* 80115390 001122F0  94 21 FF F8 */	stwu r1, -8(r1)
/* 80115394 001122F4  80 83 00 10 */	lwz r4, 0x10(r3)
/* 80115398 001122F8  28 04 00 00 */	cmplwi r4, 0
/* 8011539C 001122FC  41 82 00 14 */	beq .L_801153B0
/* 801153A0 00112300  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801153A4 00112304  38 A0 00 00 */	li r5, 0
/* 801153A8 00112308  38 63 00 14 */	addi r3, r3, 0x14
/* 801153AC 0011230C  48 08 C2 19 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
.L_801153B0:
/* 801153B0 00112310  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801153B4 00112314  38 21 00 08 */	addi r1, r1, 8
/* 801153B8 00112318  7C 08 03 A6 */	mtlr r0
/* 801153BC 0011231C  4E 80 00 20 */	blr 
.endfn kill__12SimpleEffectFv

.fn invoke__7NaviFueFPQ23zen17particleGenerator, weak
/* 801153C0 00112320  38 60 00 01 */	li r3, 1
/* 801153C4 00112324  4E 80 00 20 */	blr 
.endfn invoke__7NaviFueFPQ23zen17particleGenerator

.fn emit__7NaviFueFR10EffectParm, weak
/* 801153C8 00112328  7C 08 02 A6 */	mflr r0
/* 801153CC 0011232C  90 01 00 04 */	stw r0, 4(r1)
/* 801153D0 00112330  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 801153D4 00112334  93 E1 00 24 */	stw r31, 0x24(r1)
/* 801153D8 00112338  93 C1 00 20 */	stw r30, 0x20(r1)
/* 801153DC 0011233C  93 A1 00 1C */	stw r29, 0x1c(r1)
/* 801153E0 00112340  93 81 00 18 */	stw r28, 0x18(r1)
/* 801153E4 00112344  7C 7C 1B 78 */	mr r28, r3
/* 801153E8 00112348  80 63 00 14 */	lwz r3, 0x14(r3)
/* 801153EC 0011234C  80 03 00 00 */	lwz r0, 0(r3)
/* 801153F0 00112350  28 00 00 00 */	cmplwi r0, 0
/* 801153F4 00112354  40 82 00 74 */	bne .L_80115468
/* 801153F8 00112358  3B A0 00 00 */	li r29, 0
/* 801153FC 0011235C  1F FD 00 0C */	mulli r31, r29, 0xc
/* 80115400 00112360  3B C0 00 00 */	li r30, 0
/* 80115404 00112364  48 00 00 58 */	b .L_8011545C
.L_80115408:
/* 80115408 00112368  80 1C 00 0C */	lwz r0, 0xc(r28)
/* 8011540C 0011236C  38 BF 09 38 */	addi r5, r31, 0x938
/* 80115410 00112370  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115414 00112374  38 DC 00 00 */	addi r6, r28, 0
/* 80115418 00112378  7C A0 2A 14 */	add r5, r0, r5
/* 8011541C 0011237C  38 80 00 14 */	li r4, 0x14
/* 80115420 00112380  38 E0 00 00 */	li r7, 0
/* 80115424 00112384  48 08 77 15 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115428 00112388  80 9C 00 14 */	lwz r4, 0x14(r28)
/* 8011542C 0011238C  7C 64 F1 2E */	stwx r3, r4, r30
/* 80115430 00112390  80 7C 00 14 */	lwz r3, 0x14(r28)
/* 80115434 00112394  7C 83 F0 2E */	lwzx r4, r3, r30
/* 80115438 00112398  28 04 00 00 */	cmplwi r4, 0
/* 8011543C 0011239C  41 82 00 14 */	beq .L_80115450
/* 80115440 001123A0  80 7C 00 0C */	lwz r3, 0xc(r28)
/* 80115444 001123A4  38 1F 09 38 */	addi r0, r31, 0x938
/* 80115448 001123A8  7C 03 02 14 */	add r0, r3, r0
/* 8011544C 001123AC  90 04 00 18 */	stw r0, 0x18(r4)
.L_80115450:
/* 80115450 001123B0  3B FF 00 0C */	addi r31, r31, 0xc
/* 80115454 001123B4  3B DE 00 04 */	addi r30, r30, 4
/* 80115458 001123B8  3B BD 00 01 */	addi r29, r29, 1
.L_8011545C:
/* 8011545C 001123BC  80 1C 00 10 */	lwz r0, 0x10(r28)
/* 80115460 001123C0  7C 1D 00 00 */	cmpw r29, r0
/* 80115464 001123C4  41 80 FF A4 */	blt .L_80115408
.L_80115468:
/* 80115468 001123C8  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8011546C 001123CC  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 80115470 001123D0  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 80115474 001123D4  83 A1 00 1C */	lwz r29, 0x1c(r1)
/* 80115478 001123D8  83 81 00 18 */	lwz r28, 0x18(r1)
/* 8011547C 001123DC  38 21 00 28 */	addi r1, r1, 0x28
/* 80115480 001123E0  7C 08 03 A6 */	mtlr r0
/* 80115484 001123E4  4E 80 00 20 */	blr 
.endfn emit__7NaviFueFR10EffectParm

.fn kill__7NaviFueFv, weak
/* 80115488 001123E8  7C 08 02 A6 */	mflr r0
/* 8011548C 001123EC  90 01 00 04 */	stw r0, 4(r1)
/* 80115490 001123F0  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80115494 001123F4  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80115498 001123F8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8011549C 001123FC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801154A0 00112400  93 A1 00 14 */	stw r29, 0x14(r1)
/* 801154A4 00112404  93 81 00 10 */	stw r28, 0x10(r1)
/* 801154A8 00112408  7C 7C 1B 78 */	mr r28, r3
/* 801154AC 0011240C  80 63 00 14 */	lwz r3, 0x14(r3)
/* 801154B0 00112410  80 03 00 00 */	lwz r0, 0(r3)
/* 801154B4 00112414  28 00 00 00 */	cmplwi r0, 0
/* 801154B8 00112418  41 82 00 60 */	beq .L_80115518
/* 801154BC 0011241C  3B C0 00 00 */	li r30, 0
/* 801154C0 00112420  C3 E2 9F 50 */	lfs f31, lbl_803EA150@sda21(r2)
/* 801154C4 00112424  3B FE 00 00 */	addi r31, r30, 0
/* 801154C8 00112428  3B A0 00 00 */	li r29, 0
/* 801154CC 0011242C  48 00 00 40 */	b .L_8011550C
.L_801154D0:
/* 801154D0 00112430  80 7C 00 14 */	lwz r3, 0x14(r28)
/* 801154D4 00112434  7C 63 F0 2E */	lwzx r3, r3, r30
/* 801154D8 00112438  28 03 00 00 */	cmplwi r3, 0
/* 801154DC 0011243C  41 82 00 20 */	beq .L_801154FC
/* 801154E0 00112440  D3 E3 00 B8 */	stfs f31, 0xb8(r3)
/* 801154E4 00112444  38 A0 00 00 */	li r5, 0
/* 801154E8 00112448  80 7C 00 14 */	lwz r3, 0x14(r28)
/* 801154EC 0011244C  80 CD 31 80 */	lwz r6, effectMgr@sda21(r13)
/* 801154F0 00112450  7C 83 F0 2E */	lwzx r4, r3, r30
/* 801154F4 00112454  38 66 00 14 */	addi r3, r6, 0x14
/* 801154F8 00112458  48 08 C0 CD */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
.L_801154FC:
/* 801154FC 0011245C  80 7C 00 14 */	lwz r3, 0x14(r28)
/* 80115500 00112460  3B BD 00 01 */	addi r29, r29, 1
/* 80115504 00112464  7F E3 F1 2E */	stwx r31, r3, r30
/* 80115508 00112468  3B DE 00 04 */	addi r30, r30, 4
.L_8011550C:
/* 8011550C 0011246C  80 1C 00 10 */	lwz r0, 0x10(r28)
/* 80115510 00112470  7C 1D 00 00 */	cmpw r29, r0
/* 80115514 00112474  41 80 FF BC */	blt .L_801154D0
.L_80115518:
/* 80115518 00112478  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8011551C 0011247C  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80115520 00112480  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80115524 00112484  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80115528 00112488  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8011552C 0011248C  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80115530 00112490  38 21 00 28 */	addi r1, r1, 0x28
/* 80115534 00112494  7C 08 03 A6 */	mtlr r0
/* 80115538 00112498  4E 80 00 20 */	blr 
.endfn kill__7NaviFueFv

.fn emit__15SmokeTreeEffectFR10EffectParm, weak
/* 8011553C 0011249C  7C 08 02 A6 */	mflr r0
/* 80115540 001124A0  38 A4 00 00 */	addi r5, r4, 0
/* 80115544 001124A4  90 01 00 04 */	stw r0, 4(r1)
/* 80115548 001124A8  38 80 00 13 */	li r4, 0x13
/* 8011554C 001124AC  38 C0 00 00 */	li r6, 0
/* 80115550 001124B0  94 21 FF F8 */	stwu r1, -8(r1)
/* 80115554 001124B4  38 E0 00 00 */	li r7, 0
/* 80115558 001124B8  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8011555C 001124BC  48 08 75 DD */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115560 001124C0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80115564 001124C4  38 21 00 08 */	addi r1, r1, 8
/* 80115568 001124C8  7C 08 03 A6 */	mtlr r0
/* 8011556C 001124CC  4E 80 00 20 */	blr 
.endfn emit__15SmokeTreeEffectFR10EffectParm

.fn emit__15SmokeRockEffectFR10EffectParm, weak
/* 80115570 001124D0  7C 08 02 A6 */	mflr r0
/* 80115574 001124D4  38 A4 00 00 */	addi r5, r4, 0
/* 80115578 001124D8  90 01 00 04 */	stw r0, 4(r1)
/* 8011557C 001124DC  38 80 00 11 */	li r4, 0x11
/* 80115580 001124E0  38 C0 00 00 */	li r6, 0
/* 80115584 001124E4  94 21 FF F8 */	stwu r1, -8(r1)
/* 80115588 001124E8  38 E0 00 00 */	li r7, 0
/* 8011558C 001124EC  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115590 001124F0  48 08 75 A9 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115594 001124F4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80115598 001124F8  38 21 00 08 */	addi r1, r1, 8
/* 8011559C 001124FC  7C 08 03 A6 */	mtlr r0
/* 801155A0 00112500  4E 80 00 20 */	blr 
.endfn emit__15SmokeRockEffectFR10EffectParm

.fn emit__16SmokeGrassEffectFR10EffectParm, weak
/* 801155A4 00112504  7C 08 02 A6 */	mflr r0
/* 801155A8 00112508  38 A4 00 00 */	addi r5, r4, 0
/* 801155AC 0011250C  90 01 00 04 */	stw r0, 4(r1)
/* 801155B0 00112510  38 80 00 12 */	li r4, 0x12
/* 801155B4 00112514  38 C0 00 00 */	li r6, 0
/* 801155B8 00112518  94 21 FF F8 */	stwu r1, -8(r1)
/* 801155BC 0011251C  38 E0 00 00 */	li r7, 0
/* 801155C0 00112520  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801155C4 00112524  48 08 75 75 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801155C8 00112528  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801155CC 0011252C  38 21 00 08 */	addi r1, r1, 8
/* 801155D0 00112530  7C 08 03 A6 */	mtlr r0
/* 801155D4 00112534  4E 80 00 20 */	blr 
.endfn emit__16SmokeGrassEffectFR10EffectParm

.fn emit__15SmokeSoilEffectFR10EffectParm, weak
/* 801155D8 00112538  7C 08 02 A6 */	mflr r0
/* 801155DC 0011253C  38 A4 00 00 */	addi r5, r4, 0
/* 801155E0 00112540  90 01 00 04 */	stw r0, 4(r1)
/* 801155E4 00112544  38 80 00 13 */	li r4, 0x13
/* 801155E8 00112548  38 C0 00 00 */	li r6, 0
/* 801155EC 0011254C  94 21 FF F8 */	stwu r1, -8(r1)
/* 801155F0 00112550  38 E0 00 00 */	li r7, 0
/* 801155F4 00112554  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801155F8 00112558  48 08 75 41 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801155FC 0011255C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80115600 00112560  38 21 00 08 */	addi r1, r1, 8
/* 80115604 00112564  7C 08 03 A6 */	mtlr r0
/* 80115608 00112568  4E 80 00 20 */	blr 
.endfn emit__15SmokeSoilEffectFR10EffectParm

.fn emit__11NaviWhistleFR10EffectParm, weak
/* 8011560C 0011256C  7C 08 02 A6 */	mflr r0
/* 80115610 00112570  90 01 00 04 */	stw r0, 4(r1)
/* 80115614 00112574  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80115618 00112578  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8011561C 0011257C  7C 7F 1B 78 */	mr r31, r3
/* 80115620 00112580  80 03 00 10 */	lwz r0, 0x10(r3)
/* 80115624 00112584  28 00 00 00 */	cmplwi r0, 0
/* 80115628 00112588  40 82 00 CC */	bne .L_801156F4
/* 8011562C 0011258C  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 80115630 00112590  28 00 00 00 */	cmplwi r0, 0
/* 80115634 00112594  40 82 00 C0 */	bne .L_801156F4
/* 80115638 00112598  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 8011563C 0011259C  28 00 00 00 */	cmplwi r0, 0
/* 80115640 001125A0  41 82 00 08 */	beq .L_80115648
/* 80115644 001125A4  48 00 00 B0 */	b .L_801156F4
.L_80115648:
/* 80115648 001125A8  80 BF 00 0C */	lwz r5, 0xc(r31)
/* 8011564C 001125AC  7F E6 FB 78 */	mr r6, r31
/* 80115650 001125B0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115654 001125B4  38 80 00 0B */	li r4, 0xb
/* 80115658 001125B8  38 A5 07 84 */	addi r5, r5, 0x784
/* 8011565C 001125BC  38 E0 00 00 */	li r7, 0
/* 80115660 001125C0  48 08 74 D9 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115664 001125C4  28 1F 00 00 */	cmplwi r31, 0
/* 80115668 001125C8  90 7F 00 10 */	stw r3, 0x10(r31)
/* 8011566C 001125CC  7F E7 FB 78 */	mr r7, r31
/* 80115670 001125D0  41 82 00 08 */	beq .L_80115678
/* 80115674 001125D4  38 E7 00 04 */	addi r7, r7, 4
.L_80115678:
/* 80115678 001125D8  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 8011567C 001125DC  7F E6 FB 78 */	mr r6, r31
/* 80115680 001125E0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115684 001125E4  38 A4 07 84 */	addi r5, r4, 0x784
/* 80115688 001125E8  38 80 00 0A */	li r4, 0xa
/* 8011568C 001125EC  48 08 74 AD */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115690 001125F0  28 1F 00 00 */	cmplwi r31, 0
/* 80115694 001125F4  90 7F 00 14 */	stw r3, 0x14(r31)
/* 80115698 001125F8  7F E7 FB 78 */	mr r7, r31
/* 8011569C 001125FC  41 82 00 08 */	beq .L_801156A4
/* 801156A0 00112600  38 E7 00 04 */	addi r7, r7, 4
.L_801156A4:
/* 801156A4 00112604  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 801156A8 00112608  7F E6 FB 78 */	mr r6, r31
/* 801156AC 0011260C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 801156B0 00112610  38 A4 07 84 */	addi r5, r4, 0x784
/* 801156B4 00112614  38 80 00 09 */	li r4, 9
/* 801156B8 00112618  48 08 74 81 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 801156BC 0011261C  90 7F 00 18 */	stw r3, 0x18(r31)
/* 801156C0 00112620  80 9F 00 10 */	lwz r4, 0x10(r31)
/* 801156C4 00112624  28 04 00 00 */	cmplwi r4, 0
/* 801156C8 00112628  41 82 00 10 */	beq .L_801156D8
/* 801156CC 0011262C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 801156D0 00112630  38 03 07 84 */	addi r0, r3, 0x784
/* 801156D4 00112634  90 04 00 18 */	stw r0, 0x18(r4)
.L_801156D8:
/* 801156D8 00112638  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 801156DC 0011263C  28 04 00 00 */	cmplwi r4, 0
/* 801156E0 00112640  41 82 00 14 */	beq .L_801156F4
/* 801156E4 00112644  88 04 00 68 */	lbz r0, 0x68(r4)
/* 801156E8 00112648  38 60 00 01 */	li r3, 1
/* 801156EC 0011264C  50 60 2E B4 */	rlwimi r0, r3, 5, 0x1a, 0x1a
/* 801156F0 00112650  98 04 00 68 */	stb r0, 0x68(r4)
.L_801156F4:
/* 801156F4 00112654  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 801156F8 00112658  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 801156FC 0011265C  38 21 00 28 */	addi r1, r1, 0x28
/* 80115700 00112660  7C 08 03 A6 */	mtlr r0
/* 80115704 00112664  4E 80 00 20 */	blr 
.endfn emit__11NaviWhistleFR10EffectParm

.fn kill__11NaviWhistleFv, weak
/* 80115708 00112668  7C 08 02 A6 */	mflr r0
/* 8011570C 0011266C  90 01 00 04 */	stw r0, 4(r1)
/* 80115710 00112670  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80115714 00112674  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80115718 00112678  7C 7F 1B 78 */	mr r31, r3
/* 8011571C 0011267C  80 83 00 10 */	lwz r4, 0x10(r3)
/* 80115720 00112680  28 04 00 00 */	cmplwi r4, 0
/* 80115724 00112684  41 82 00 1C */	beq .L_80115740
/* 80115728 00112688  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8011572C 0011268C  38 A0 00 00 */	li r5, 0
/* 80115730 00112690  38 63 00 14 */	addi r3, r3, 0x14
/* 80115734 00112694  48 08 BE 91 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80115738 00112698  38 00 00 00 */	li r0, 0
/* 8011573C 0011269C  90 1F 00 10 */	stw r0, 0x10(r31)
.L_80115740:
/* 80115740 001126A0  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 80115744 001126A4  28 04 00 00 */	cmplwi r4, 0
/* 80115748 001126A8  41 82 00 1C */	beq .L_80115764
/* 8011574C 001126AC  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115750 001126B0  38 A0 00 00 */	li r5, 0
/* 80115754 001126B4  38 63 00 14 */	addi r3, r3, 0x14
/* 80115758 001126B8  48 08 BE 6D */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 8011575C 001126BC  38 00 00 00 */	li r0, 0
/* 80115760 001126C0  90 1F 00 14 */	stw r0, 0x14(r31)
.L_80115764:
/* 80115764 001126C4  80 9F 00 18 */	lwz r4, 0x18(r31)
/* 80115768 001126C8  28 04 00 00 */	cmplwi r4, 0
/* 8011576C 001126CC  41 82 00 1C */	beq .L_80115788
/* 80115770 001126D0  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115774 001126D4  38 A0 00 00 */	li r5, 0
/* 80115778 001126D8  38 63 00 14 */	addi r3, r3, 0x14
/* 8011577C 001126DC  48 08 BE 49 */	bl killGenerator__Q23zen15particleManagerFPQ23zen17particleGeneratorb
/* 80115780 001126E0  38 00 00 00 */	li r0, 0
/* 80115784 001126E4  90 1F 00 18 */	stw r0, 0x18(r31)
.L_80115788:
/* 80115788 001126E8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011578C 001126EC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80115790 001126F0  38 21 00 18 */	addi r1, r1, 0x18
/* 80115794 001126F4  7C 08 03 A6 */	mtlr r0
/* 80115798 001126F8  4E 80 00 20 */	blr 
.endfn kill__11NaviWhistleFv

.fn invoke__11NaviWhistleFPQ23zen17particleGeneratorPQ23zen11particleMdl, weak
/* 8011579C 001126FC  7C 08 02 A6 */	mflr r0
/* 801157A0 00112700  3C C0 43 30 */	lis r6, 0x4330
/* 801157A4 00112704  90 01 00 04 */	stw r0, 4(r1)
/* 801157A8 00112708  94 21 FE C8 */	stwu r1, -0x138(r1)
/* 801157AC 0011270C  DB E1 01 30 */	stfd f31, 0x130(r1)
/* 801157B0 00112710  93 E1 01 2C */	stw r31, 0x12c(r1)
/* 801157B4 00112714  3B E5 00 00 */	addi r31, r5, 0
/* 801157B8 00112718  93 C1 01 28 */	stw r30, 0x128(r1)
/* 801157BC 0011271C  80 83 00 0C */	lwz r4, 0xc(r3)
/* 801157C0 00112720  38 A4 07 84 */	addi r5, r4, 0x784
/* 801157C4 00112724  C0 04 07 84 */	lfs f0, 0x784(r4)
/* 801157C8 00112728  C4 24 06 F0 */	lfsu f1, 0x6f0(r4)
/* 801157CC 0011272C  C0 45 00 04 */	lfs f2, 4(r5)
/* 801157D0 00112730  C0 64 00 04 */	lfs f3, 4(r4)
/* 801157D4 00112734  EC 01 00 28 */	fsubs f0, f1, f0
/* 801157D8 00112738  C0 84 00 08 */	lfs f4, 8(r4)
/* 801157DC 0011273C  C0 25 00 08 */	lfs f1, 8(r5)
/* 801157E0 00112740  EC 43 10 28 */	fsubs f2, f3, f2
/* 801157E4 00112744  D0 01 01 08 */	stfs f0, 0x108(r1)
/* 801157E8 00112748  EC 04 08 28 */	fsubs f0, f4, f1
/* 801157EC 0011274C  D0 41 01 0C */	stfs f2, 0x10c(r1)
/* 801157F0 00112750  D0 01 01 10 */	stfs f0, 0x110(r1)
/* 801157F4 00112754  A8 9F 00 2E */	lha r4, 0x2e(r31)
/* 801157F8 00112758  A8 1F 00 2C */	lha r0, 0x2c(r31)
/* 801157FC 0011275C  6C 84 80 00 */	xoris r4, r4, 0x8000
/* 80115800 00112760  C8 42 9F 78 */	lfd f2, lbl_803EA178@sda21(r2)
/* 80115804 00112764  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80115808 00112768  90 81 01 24 */	stw r4, 0x124(r1)
/* 8011580C 0011276C  80 A3 00 0C */	lwz r5, 0xc(r3)
/* 80115810 00112770  90 01 01 1C */	stw r0, 0x11c(r1)
/* 80115814 00112774  80 85 07 84 */	lwz r4, 0x784(r5)
/* 80115818 00112778  90 C1 01 20 */	stw r6, 0x120(r1)
/* 8011581C 0011277C  80 05 07 88 */	lwz r0, 0x788(r5)
/* 80115820 00112780  90 C1 01 18 */	stw r6, 0x118(r1)
/* 80115824 00112784  C8 21 01 20 */	lfd f1, 0x120(r1)
/* 80115828 00112788  C8 01 01 18 */	lfd f0, 0x118(r1)
/* 8011582C 0011278C  EC 21 10 28 */	fsubs f1, f1, f2
/* 80115830 00112790  90 9F 00 18 */	stw r4, 0x18(r31)
/* 80115834 00112794  EC 00 10 28 */	fsubs f0, f0, f2
/* 80115838 00112798  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 8011583C 0011279C  EF E1 00 24 */	fdivs f31, f1, f0
/* 80115840 001127A0  80 05 07 8C */	lwz r0, 0x78c(r5)
/* 80115844 001127A4  90 1F 00 20 */	stw r0, 0x20(r31)
/* 80115848 001127A8  C0 01 01 08 */	lfs f0, 0x108(r1)
/* 8011584C 001127AC  EC 00 07 F2 */	fmuls f0, f0, f31
/* 80115850 001127B0  D0 01 00 60 */	stfs f0, 0x60(r1)
/* 80115854 001127B4  C0 01 00 60 */	lfs f0, 0x60(r1)
/* 80115858 001127B8  D0 01 00 84 */	stfs f0, 0x84(r1)
/* 8011585C 001127BC  C0 01 01 0C */	lfs f0, 0x10c(r1)
/* 80115860 001127C0  EC 00 07 F2 */	fmuls f0, f0, f31
/* 80115864 001127C4  D0 01 00 88 */	stfs f0, 0x88(r1)
/* 80115868 001127C8  C0 01 01 10 */	lfs f0, 0x110(r1)
/* 8011586C 001127CC  EC 00 07 F2 */	fmuls f0, f0, f31
/* 80115870 001127D0  D0 01 00 8C */	stfs f0, 0x8c(r1)
/* 80115874 001127D4  80 81 00 84 */	lwz r4, 0x84(r1)
/* 80115878 001127D8  80 01 00 88 */	lwz r0, 0x88(r1)
/* 8011587C 001127DC  90 9F 00 0C */	stw r4, 0xc(r31)
/* 80115880 001127E0  90 1F 00 10 */	stw r0, 0x10(r31)
/* 80115884 001127E4  80 01 00 8C */	lwz r0, 0x8c(r1)
/* 80115888 001127E8  90 1F 00 14 */	stw r0, 0x14(r31)
/* 8011588C 001127EC  80 A3 00 0C */	lwz r5, 0xc(r3)
/* 80115890 001127F0  C0 22 9F 6C */	lfs f1, lbl_803EA16C@sda21(r2)
/* 80115894 001127F4  C0 05 00 98 */	lfs f0, 0x98(r5)
/* 80115898 001127F8  C0 45 06 F4 */	lfs f2, 0x6f4(r5)
/* 8011589C 001127FC  EC 01 00 2A */	fadds f0, f1, f0
/* 801158A0 00112800  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 801158A4 00112804  40 80 02 00 */	bge .L_80115AA4
/* 801158A8 00112808  80 6D 2F 00 */	lwz r3, mapMgr@sda21(r13)
/* 801158AC 0011280C  38 80 00 01 */	li r4, 1
/* 801158B0 00112810  C0 25 06 F0 */	lfs f1, 0x6f0(r5)
/* 801158B4 00112814  C0 45 06 F8 */	lfs f2, 0x6f8(r5)
/* 801158B8 00112818  4B F5 29 21 */	bl getCurrTri__6MapMgrFffb
/* 801158BC 0011281C  7C 7E 1B 79 */	or. r30, r3, r3
/* 801158C0 00112820  40 82 00 0C */	bne .L_801158CC
/* 801158C4 00112824  38 60 00 00 */	li r3, 0
/* 801158C8 00112828  48 00 02 1C */	b .L_80115AE4
.L_801158CC:
/* 801158CC 0011282C  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 801158D0 00112830  38 60 00 08 */	li r3, 8
/* 801158D4 00112834  D0 01 00 E0 */	stfs f0, 0xe0(r1)
/* 801158D8 00112838  D0 01 00 E4 */	stfs f0, 0xe4(r1)
/* 801158DC 0011283C  D0 01 00 E8 */	stfs f0, 0xe8(r1)
/* 801158E0 00112840  D0 01 00 EC */	stfs f0, 0xec(r1)
/* 801158E4 00112844  D0 01 00 F0 */	stfs f0, 0xf0(r1)
/* 801158E8 00112848  D0 01 00 F4 */	stfs f0, 0xf4(r1)
/* 801158EC 0011284C  D0 01 00 F8 */	stfs f0, 0xf8(r1)
/* 801158F0 00112850  D0 01 00 FC */	stfs f0, 0xfc(r1)
/* 801158F4 00112854  48 00 01 D0 */	b .L_80115AC4
.L_801158F8:
/* 801158F8 00112858  20 03 00 09 */	subfic r0, r3, 9
/* 801158FC 0011285C  2C 03 00 09 */	cmpwi r3, 9
/* 80115900 00112860  7C 09 03 A6 */	mtctr r0
/* 80115904 00112864  40 80 00 10 */	bge .L_80115914
.L_80115908:
/* 80115908 00112868  D0 04 00 00 */	stfs f0, 0(r4)
/* 8011590C 0011286C  38 84 00 04 */	addi r4, r4, 4
/* 80115910 00112870  42 00 FF F8 */	bdnz .L_80115908
.L_80115914:
/* 80115914 00112874  C0 22 9F 70 */	lfs f1, lbl_803EA170@sda21(r2)
/* 80115918 00112878  38 60 00 08 */	li r3, 8
/* 8011591C 0011287C  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80115920 00112880  D0 21 01 00 */	stfs f1, 0x100(r1)
/* 80115924 00112884  D0 21 00 F0 */	stfs f1, 0xf0(r1)
/* 80115928 00112888  D0 21 00 E0 */	stfs f1, 0xe0(r1)
/* 8011592C 0011288C  D0 01 00 BC */	stfs f0, 0xbc(r1)
/* 80115930 00112890  D0 01 00 C0 */	stfs f0, 0xc0(r1)
/* 80115934 00112894  D0 01 00 C4 */	stfs f0, 0xc4(r1)
/* 80115938 00112898  D0 01 00 C8 */	stfs f0, 0xc8(r1)
/* 8011593C 0011289C  D0 01 00 CC */	stfs f0, 0xcc(r1)
/* 80115940 001128A0  D0 01 00 D0 */	stfs f0, 0xd0(r1)
/* 80115944 001128A4  D0 01 00 D4 */	stfs f0, 0xd4(r1)
/* 80115948 001128A8  D0 01 00 D8 */	stfs f0, 0xd8(r1)
/* 8011594C 001128AC  48 00 01 88 */	b .L_80115AD4
.L_80115950:
/* 80115950 001128B0  20 03 00 09 */	subfic r0, r3, 9
/* 80115954 001128B4  2C 03 00 09 */	cmpwi r3, 9
/* 80115958 001128B8  7C 09 03 A6 */	mtctr r0
/* 8011595C 001128BC  40 80 00 10 */	bge .L_8011596C
.L_80115960:
/* 80115960 001128C0  D0 04 00 00 */	stfs f0, 0(r4)
/* 80115964 001128C4  38 84 00 04 */	addi r4, r4, 4
/* 80115968 001128C8  42 00 FF F8 */	bdnz .L_80115960
.L_8011596C:
/* 8011596C 001128CC  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 80115970 001128D0  C0 42 9F 70 */	lfs f2, lbl_803EA170@sda21(r2)
/* 80115974 001128D4  D0 01 00 B4 */	stfs f0, 0xb4(r1)
/* 80115978 001128D8  C0 21 01 08 */	lfs f1, 0x108(r1)
/* 8011597C 001128DC  D0 41 00 DC */	stfs f2, 0xdc(r1)
/* 80115980 001128E0  EC 21 00 72 */	fmuls f1, f1, f1
/* 80115984 001128E4  D0 01 00 A4 */	stfs f0, 0xa4(r1)
/* 80115988 001128E8  D0 41 00 CC */	stfs f2, 0xcc(r1)
/* 8011598C 001128EC  D0 01 00 B0 */	stfs f0, 0xb0(r1)
/* 80115990 001128F0  D0 01 00 A0 */	stfs f0, 0xa0(r1)
/* 80115994 001128F4  D0 41 00 BC */	stfs f2, 0xbc(r1)
/* 80115998 001128F8  D0 01 00 AC */	stfs f0, 0xac(r1)
/* 8011599C 001128FC  D0 01 00 9C */	stfs f0, 0x9c(r1)
/* 801159A0 00112900  C0 01 01 0C */	lfs f0, 0x10c(r1)
/* 801159A4 00112904  C0 41 01 10 */	lfs f2, 0x110(r1)
/* 801159A8 00112908  EC 00 00 32 */	fmuls f0, f0, f0
/* 801159AC 0011290C  EC 42 00 B2 */	fmuls f2, f2, f2
/* 801159B0 00112910  EC 01 00 2A */	fadds f0, f1, f0
/* 801159B4 00112914  EC 22 00 2A */	fadds f1, f2, f0
/* 801159B8 00112918  4B EF 82 89 */	bl sqrtf__3stdFf
/* 801159BC 0011291C  C0 02 9F 50 */	lfs f0, lbl_803EA150@sda21(r2)
/* 801159C0 00112920  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 801159C4 00112924  41 82 00 28 */	beq .L_801159EC
/* 801159C8 00112928  C0 01 01 08 */	lfs f0, 0x108(r1)
/* 801159CC 0011292C  EC 00 08 24 */	fdivs f0, f0, f1
/* 801159D0 00112930  D0 01 01 08 */	stfs f0, 0x108(r1)
/* 801159D4 00112934  C0 01 01 0C */	lfs f0, 0x10c(r1)
/* 801159D8 00112938  EC 00 08 24 */	fdivs f0, f0, f1
/* 801159DC 0011293C  D0 01 01 0C */	stfs f0, 0x10c(r1)
/* 801159E0 00112940  C0 01 01 10 */	lfs f0, 0x110(r1)
/* 801159E4 00112944  EC 00 08 24 */	fdivs f0, f0, f1
/* 801159E8 00112948  D0 01 01 10 */	stfs f0, 0x110(r1)
.L_801159EC:
/* 801159EC 0011294C  38 61 01 08 */	addi r3, r1, 0x108
/* 801159F0 00112950  38 81 00 E0 */	addi r4, r1, 0xe0
/* 801159F4 00112954  48 08 60 ED */	bl makeRotMatrix__3zenFR8Vector3fR8Matrix3f
/* 801159F8 00112958  C0 6D DB 6C */	lfs f3, lbl_803E288C@sda21(r13)
/* 801159FC 0011295C  38 61 00 78 */	addi r3, r1, 0x78
/* 80115A00 00112960  C0 1E 00 18 */	lfs f0, 0x18(r30)
/* 80115A04 00112964  38 81 00 BC */	addi r4, r1, 0xbc
/* 80115A08 00112968  C0 5E 00 20 */	lfs f2, 0x20(r30)
/* 80115A0C 0011296C  C0 3E 00 1C */	lfs f1, 0x1c(r30)
/* 80115A10 00112970  EC 00 00 F2 */	fmuls f0, f0, f3
/* 80115A14 00112974  EC 42 00 F2 */	fmuls f2, f2, f3
/* 80115A18 00112978  EC 21 00 F2 */	fmuls f1, f1, f3
/* 80115A1C 0011297C  D0 01 00 58 */	stfs f0, 0x58(r1)
/* 80115A20 00112980  C0 01 00 58 */	lfs f0, 0x58(r1)
/* 80115A24 00112984  D0 01 00 78 */	stfs f0, 0x78(r1)
/* 80115A28 00112988  D0 21 00 7C */	stfs f1, 0x7c(r1)
/* 80115A2C 0011298C  D0 41 00 80 */	stfs f2, 0x80(r1)
/* 80115A30 00112990  48 08 60 B1 */	bl makeRotMatrix__3zenFR8Vector3fR8Matrix3f
/* 80115A34 00112994  38 61 00 AC */	addi r3, r1, 0xac
/* 80115A38 00112998  38 81 00 E0 */	addi r4, r1, 0xe0
/* 80115A3C 0011299C  4B F2 1E 81 */	bl fromMat3f__4QuatFR8Matrix3f
/* 80115A40 001129A0  38 61 00 9C */	addi r3, r1, 0x9c
/* 80115A44 001129A4  38 81 00 BC */	addi r4, r1, 0xbc
/* 80115A48 001129A8  4B F2 1E 75 */	bl fromMat3f__4QuatFR8Matrix3f
/* 80115A4C 001129AC  FC 20 F8 90 */	fmr f1, f31
/* 80115A50 001129B0  38 61 00 AC */	addi r3, r1, 0xac
/* 80115A54 001129B4  38 81 00 9C */	addi r4, r1, 0x9c
/* 80115A58 001129B8  38 A0 00 00 */	li r5, 0
/* 80115A5C 001129BC  4B F2 27 29 */	bl slerp__4QuatFR4Quatfi
/* 80115A60 001129C0  38 61 00 AC */	addi r3, r1, 0xac
/* 80115A64 001129C4  38 9F 00 5C */	addi r4, r31, 0x5c
/* 80115A68 001129C8  4B F2 26 1D */	bl genVectorY__4QuatFR8Vector3f
/* 80115A6C 001129CC  38 61 00 AC */	addi r3, r1, 0xac
/* 80115A70 001129D0  38 9F 00 34 */	addi r4, r31, 0x34
/* 80115A74 001129D4  4B F2 25 91 */	bl genVectorX__4QuatFR8Vector3f
/* 80115A78 001129D8  C0 1F 00 34 */	lfs f0, 0x34(r31)
/* 80115A7C 001129DC  C0 22 9F 54 */	lfs f1, lbl_803EA154@sda21(r2)
/* 80115A80 001129E0  EC 00 00 72 */	fmuls f0, f0, f1
/* 80115A84 001129E4  D0 1F 00 34 */	stfs f0, 0x34(r31)
/* 80115A88 001129E8  C0 1F 00 38 */	lfs f0, 0x38(r31)
/* 80115A8C 001129EC  EC 00 00 72 */	fmuls f0, f0, f1
/* 80115A90 001129F0  D0 1F 00 38 */	stfs f0, 0x38(r31)
/* 80115A94 001129F4  C0 1F 00 3C */	lfs f0, 0x3c(r31)
/* 80115A98 001129F8  EC 00 00 72 */	fmuls f0, f0, f1
/* 80115A9C 001129FC  D0 1F 00 3C */	stfs f0, 0x3c(r31)
/* 80115AA0 00112A00  48 00 00 1C */	b .L_80115ABC
.L_80115AA4:
/* 80115AA4 00112A04  C0 01 01 08 */	lfs f0, 0x108(r1)
/* 80115AA8 00112A08  D0 1F 00 5C */	stfs f0, 0x5c(r31)
/* 80115AAC 00112A0C  C0 01 01 0C */	lfs f0, 0x10c(r1)
/* 80115AB0 00112A10  D0 1F 00 60 */	stfs f0, 0x60(r31)
/* 80115AB4 00112A14  C0 01 01 10 */	lfs f0, 0x110(r1)
/* 80115AB8 00112A18  D0 1F 00 64 */	stfs f0, 0x64(r31)
.L_80115ABC:
/* 80115ABC 00112A1C  38 60 00 00 */	li r3, 0
/* 80115AC0 00112A20  48 00 00 24 */	b .L_80115AE4
.L_80115AC4:
/* 80115AC4 00112A24  54 60 10 3A */	slwi r0, r3, 2
/* 80115AC8 00112A28  38 81 00 E0 */	addi r4, r1, 0xe0
/* 80115ACC 00112A2C  7C 84 02 14 */	add r4, r4, r0
/* 80115AD0 00112A30  4B FF FE 28 */	b .L_801158F8
.L_80115AD4:
/* 80115AD4 00112A34  54 60 10 3A */	slwi r0, r3, 2
/* 80115AD8 00112A38  38 81 00 BC */	addi r4, r1, 0xbc
/* 80115ADC 00112A3C  7C 84 02 14 */	add r4, r4, r0
/* 80115AE0 00112A40  4B FF FE 70 */	b .L_80115950
.L_80115AE4:
/* 80115AE4 00112A44  80 01 01 3C */	lwz r0, 0x13c(r1)
/* 80115AE8 00112A48  CB E1 01 30 */	lfd f31, 0x130(r1)
/* 80115AEC 00112A4C  83 E1 01 2C */	lwz r31, 0x12c(r1)
/* 80115AF0 00112A50  83 C1 01 28 */	lwz r30, 0x128(r1)
/* 80115AF4 00112A54  38 21 01 38 */	addi r1, r1, 0x138
/* 80115AF8 00112A58  7C 08 03 A6 */	mtlr r0
/* 80115AFC 00112A5C  4E 80 00 20 */	blr 
.endfn invoke__11NaviWhistleFPQ23zen17particleGeneratorPQ23zen11particleMdl

.fn invoke__10GoalEffectFPQ23zen17particleGenerator, weak
/* 80115B00 00112A60  A8 04 00 90 */	lha r0, 0x90(r4)
/* 80115B04 00112A64  2C 00 00 32 */	cmpwi r0, 0x32
/* 80115B08 00112A68  41 80 00 28 */	blt .L_80115B30
/* 80115B0C 00112A6C  C0 2D DB 48 */	lfs f1, lbl_803E2868@sda21(r13)
/* 80115B10 00112A70  C0 4D DB 4C */	lfs f2, lbl_803E286C@sda21(r13)
/* 80115B14 00112A74  C0 0D DB 44 */	lfs f0, lbl_803E2864@sda21(r13)
/* 80115B18 00112A78  D0 04 01 2C */	stfs f0, 0x12c(r4)
/* 80115B1C 00112A7C  D0 24 01 30 */	stfs f1, 0x130(r4)
/* 80115B20 00112A80  D0 44 01 34 */	stfs f2, 0x134(r4)
/* 80115B24 00112A84  80 04 00 84 */	lwz r0, 0x84(r4)
/* 80115B28 00112A88  54 00 04 1C */	rlwinm r0, r0, 0, 0x10, 0xe
/* 80115B2C 00112A8C  90 04 00 84 */	stw r0, 0x84(r4)
.L_80115B30:
/* 80115B30 00112A90  38 60 00 01 */	li r3, 1
/* 80115B34 00112A94  4E 80 00 20 */	blr 
.endfn invoke__10GoalEffectFPQ23zen17particleGenerator

.fn emit__10GoalEffectFR10EffectParm, weak
/* 80115B38 00112A98  7C 08 02 A6 */	mflr r0
/* 80115B3C 00112A9C  7C 66 1B 79 */	or. r6, r3, r3
/* 80115B40 00112AA0  90 01 00 04 */	stw r0, 4(r1)
/* 80115B44 00112AA4  94 21 FF F8 */	stwu r1, -8(r1)
/* 80115B48 00112AA8  38 E6 00 00 */	addi r7, r6, 0
/* 80115B4C 00112AAC  41 82 00 08 */	beq .L_80115B54
/* 80115B50 00112AB0  38 E7 00 04 */	addi r7, r7, 4
.L_80115B54:
/* 80115B54 00112AB4  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 80115B58 00112AB8  38 A4 00 00 */	addi r5, r4, 0
/* 80115B5C 00112ABC  38 80 00 E1 */	li r4, 0xe1
/* 80115B60 00112AC0  48 08 6F D9 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 80115B64 00112AC4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80115B68 00112AC8  38 21 00 08 */	addi r1, r1, 8
/* 80115B6C 00112ACC  7C 08 03 A6 */	mtlr r0
/* 80115B70 00112AD0  4E 80 00 20 */	blr 
.endfn emit__10GoalEffectFR10EffectParm

.fn "@4@invoke__11SlimeEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl", weak
/* 80115B74 00112AD4  38 63 FF FC */	addi r3, r3, -4
/* 80115B78 00112AD8  4B FF D7 1C */	b invoke__11SlimeEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
.endfn "@4@invoke__11SlimeEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"

.fn "@4@invoke__11NaviWhistleFPQ23zen17particleGeneratorPQ23zen11particleMdl", weak
/* 80115B7C 00112ADC  38 63 FF FC */	addi r3, r3, -4
/* 80115B80 00112AE0  4B FF FC 1C */	b invoke__11NaviWhistleFPQ23zen17particleGeneratorPQ23zen11particleMdl
.endfn "@4@invoke__11NaviWhistleFPQ23zen17particleGeneratorPQ23zen11particleMdl"

.fn "@4@invoke__15WhistleTemplateFPQ23zen17particleGeneratorPQ23zen11particleMdl", weak
/* 80115B84 00112AE4  38 63 FF FC */	addi r3, r3, -4
/* 80115B88 00112AE8  4B FF F2 A0 */	b invoke__15WhistleTemplateFPQ23zen17particleGeneratorPQ23zen11particleMdl
.endfn "@4@invoke__15WhistleTemplateFPQ23zen17particleGeneratorPQ23zen11particleMdl"

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802C24F8, local
	.asciz "uteffect.cpp"
.endobj lbl_802C24F8
.balign 4
.obj lbl_802C2508, local
	.asciz "utEffect"
.endobj lbl_802C2508
.balign 4
.obj lbl_802C2514, local
	.asciz "BurnEffect"
.endobj lbl_802C2514
.balign 4
.obj lbl_802C2520, local
	.asciz "zen::CallBack1<zen::particleMdl *>"
.endobj lbl_802C2520
.balign 4
.obj lbl_802C2544, local
	.asciz "zen::CallBack2<zen::particleGenerator *, zen::particleMdl *>"
.endobj lbl_802C2544
.balign 4
.obj lbl_802C2584, local
	.asciz "zen::CallBack1<zen::particleGenerator *>"
.endobj lbl_802C2584
.balign 4
.obj lbl_802C25B0, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte 0
.endobj lbl_802C25B0
.balign 4
.obj lbl_802C25CC, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C25CC
.balign 4
.obj __vt__10BurnEffect, global
	.4byte __RTTI__10BurnEffect
	.4byte 0
	.4byte invoke__10BurnEffectFPQ23zen17particleGenerator
	.4byte __RTTI__10BurnEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__10BurnEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__10BurnEffectFR10EffectParm
	.4byte kill__10BurnEffectFv
	.4byte stop__10BurnEffectFv
	.4byte restart__10BurnEffectFv
.endobj __vt__10BurnEffect
.balign 4
.obj lbl_802C262C, local
	.asciz "RippleEffect"
.endobj lbl_802C262C
.balign 4
.obj lbl_802C263C, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C263C
.balign 4
.obj __vt__12RippleEffect, global
	.4byte __RTTI__12RippleEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__12RippleEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__12RippleEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__12RippleEffectFR10EffectParm
	.4byte kill__12RippleEffectFv
	.4byte stop__12RippleEffectFv
	.4byte restart__12RippleEffectFv
.endobj __vt__12RippleEffect
.balign 4
.obj lbl_802C269C, local
	.asciz "FreeLightEffect"
.endobj lbl_802C269C
.balign 4
.obj lbl_802C26AC, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C26AC
.balign 4
.obj __vt__15FreeLightEffect, global
	.4byte __RTTI__15FreeLightEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__15FreeLightEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__15FreeLightEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__15FreeLightEffectFR10EffectParm
	.4byte kill__15FreeLightEffectFv
	.4byte stop__15FreeLightEffectFv
	.4byte restart__15FreeLightEffectFv
.endobj __vt__15FreeLightEffect
.balign 4
.obj lbl_802C270C, local
	.asciz "UfoSuikomiEffect"
.endobj lbl_802C270C
.balign 4
.obj lbl_802C2720, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2720
.balign 4
.obj __vt__16UfoSuikomiEffect, weak
	.4byte __RTTI__16UfoSuikomiEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__16UfoSuikomiEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__16UfoSuikomiEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__16UfoSuikomiEffectFR10EffectParm
	.4byte kill__16UfoSuikomiEffectFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__16UfoSuikomiEffect
.balign 4
.obj lbl_802C2780, local
	.asciz "UfoSuckEffect"
.endobj lbl_802C2780
.balign 4
.obj lbl_802C2790, local
	.asciz "WhistleTemplate"
.endobj lbl_802C2790
.balign 4
.obj lbl_802C27A0, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C27A0
.balign 4
.obj lbl_802C27C4, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte __RTTI__15WhistleTemplate
	.4byte 0
	.4byte 0
.endobj lbl_802C27C4
.balign 4
.obj __vt__13UfoSuckEffect, weak
	.4byte __RTTI__13UfoSuckEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__13UfoSuckEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__15WhistleTemplateFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__13UfoSuckEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__15WhistleTemplateFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__15WhistleTemplateFR10EffectParm
	.4byte kill__15WhistleTemplateFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__13UfoSuckEffect
.balign 4
.obj __vt__15WhistleTemplate, weak
	.4byte __RTTI__15WhistleTemplate
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__15WhistleTemplate
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__15WhistleTemplateFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__15WhistleTemplate
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__15WhistleTemplateFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__15WhistleTemplateFR10EffectParm
	.4byte kill__15WhistleTemplateFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__15WhistleTemplate
.balign 4
.obj lbl_802C2868, local
	.asciz "BombEffectLight"
.endobj lbl_802C2868
.balign 4
.obj lbl_802C2878, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2878
.balign 4
.obj __vt__15BombEffectLight, weak
	.4byte __RTTI__15BombEffectLight
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__15BombEffectLight
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__15BombEffectLight
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__15BombEffectLightFR10EffectParm
	.4byte kill__15BombEffectLightFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__15BombEffectLight
.balign 4
.obj lbl_802C28D8, local
	.asciz "BombEffect"
.endobj lbl_802C28D8
.balign 4
.obj lbl_802C28E4, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C28E4
.balign 4
.obj __vt__10BombEffect, weak
	.4byte __RTTI__10BombEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__10BombEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__10BombEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__10BombEffectFR10EffectParm
	.4byte kill__10BombEffectFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__10BombEffect
.balign 4
.obj lbl_802C2944, local
	.asciz "SimpleEffect"
.endobj lbl_802C2944
.balign 4
.obj lbl_802C2954, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2954
.balign 4
.obj __vt__12SimpleEffect, weak
	.4byte __RTTI__12SimpleEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__12SimpleEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__12SimpleEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__12SimpleEffectFR10EffectParm
	.4byte kill__12SimpleEffectFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__12SimpleEffect
.balign 4
.obj lbl_802C29B4, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C29B4
.balign 4
.obj __vt__7NaviFue, weak
	.4byte __RTTI__7NaviFue
	.4byte 0
	.4byte invoke__7NaviFueFPQ23zen17particleGenerator
	.4byte __RTTI__7NaviFue
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__7NaviFue
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__7NaviFueFR10EffectParm
	.4byte kill__7NaviFueFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__7NaviFue
.balign 4
.obj lbl_802C2A14, local
	.asciz "SmokeTreeEffect"
.endobj lbl_802C2A14
.balign 4
.obj lbl_802C2A24, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2A24
.balign 4
.obj __vt__15SmokeTreeEffect, weak
	.4byte __RTTI__15SmokeTreeEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__15SmokeTreeEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__15SmokeTreeEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__15SmokeTreeEffectFR10EffectParm
	.4byte kill__7KEffectFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__15SmokeTreeEffect
.balign 4
.obj lbl_802C2A84, local
	.asciz "SmokeRockEffect"
.endobj lbl_802C2A84
.balign 4
.obj lbl_802C2A94, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2A94
.balign 4
.obj __vt__15SmokeRockEffect, weak
	.4byte __RTTI__15SmokeRockEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__15SmokeRockEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__15SmokeRockEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__15SmokeRockEffectFR10EffectParm
	.4byte kill__7KEffectFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__15SmokeRockEffect
.balign 4
.obj lbl_802C2AF4, local
	.asciz "SmokeGrassEffect"
.endobj lbl_802C2AF4
.balign 4
.obj lbl_802C2B08, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2B08
.balign 4
.obj __vt__16SmokeGrassEffect, weak
	.4byte __RTTI__16SmokeGrassEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__16SmokeGrassEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__16SmokeGrassEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__16SmokeGrassEffectFR10EffectParm
	.4byte kill__7KEffectFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__16SmokeGrassEffect
.balign 4
.obj lbl_802C2B68, local
	.asciz "SmokeSoilEffect"
.endobj lbl_802C2B68
.balign 4
.obj lbl_802C2B78, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2B78
.balign 4
.obj __vt__15SmokeSoilEffect, weak
	.4byte __RTTI__15SmokeSoilEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__15SmokeSoilEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__15SmokeSoilEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__15SmokeSoilEffectFR10EffectParm
	.4byte kill__7KEffectFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__15SmokeSoilEffect
.balign 4
.obj lbl_802C2BD8, local
	.asciz "NaviWhistle"
.endobj lbl_802C2BD8
.balign 4
.obj lbl_802C2BE4, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2BE4
.balign 4
.obj __vt__11NaviWhistle, weak
	.4byte __RTTI__11NaviWhistle
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__11NaviWhistle
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__11NaviWhistleFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__11NaviWhistle
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__11NaviWhistleFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__11NaviWhistleFR10EffectParm
	.4byte kill__11NaviWhistleFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__11NaviWhistle
.balign 4
.obj lbl_802C2C44, local
	.asciz "GoalEffect"
.endobj lbl_802C2C44
.balign 4
.obj lbl_802C2C50, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2C50
.balign 4
.obj __vt__10GoalEffect, weak
	.4byte __RTTI__10GoalEffect
	.4byte 0
	.4byte invoke__10GoalEffectFPQ23zen17particleGenerator
	.4byte __RTTI__10GoalEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__10GoalEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__7KEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__10GoalEffectFR10EffectParm
	.4byte kill__7KEffectFv
	.4byte stop__7KEffectFv
	.4byte restart__7KEffectFv
.endobj __vt__10GoalEffect
.balign 4
.obj lbl_802C2CB0, local
	.asciz "SlimeEffect"
.endobj lbl_802C2CB0
.balign 4
.obj lbl_802C2CBC, local
	.4byte "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
	.4byte 0x8
	.4byte "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
	.4byte 0x4
	.4byte "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
	.4byte 0
	.4byte __RTTI__7KEffect
	.4byte 0
	.4byte 0
.endobj lbl_802C2CBC
.balign 4
.obj __vt__11SlimeEffect, global
	.4byte __RTTI__11SlimeEffect
	.4byte 0
	.4byte invoke__7KEffectFPQ23zen17particleGenerator
	.4byte __RTTI__11SlimeEffect
	.4byte 0xFFFFFFFC
	.4byte "@4@invoke__11SlimeEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl"
	.4byte __RTTI__11SlimeEffect
	.4byte 0xFFFFFFF8
	.4byte "@8@invoke__7KEffectFPQ23zen11particleMdl"
	.4byte invoke__11SlimeEffectFPQ23zen17particleGeneratorPQ23zen11particleMdl
	.4byte invoke__7KEffectFPQ23zen11particleMdl
	.4byte emit__11SlimeEffectFR10EffectParm
	.4byte kill__11SlimeEffectFv
	.4byte stop__11SlimeEffectFv
	.4byte restart__11SlimeEffectFv
.endobj __vt__11SlimeEffect
.balign 4
# This doesn't show in the map. What the hell is this?!
# Looks like remnants of a virtual table containing thunks.
# Appears in pikiheadItem.cpp, navi.cpp, piki.cpp, and uteffect.cpp.
#.obj UNKNOWN_WEIRD_SHIT, local
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0xFFFFFFFC
	.4byte 0
	.4byte 0
	.4byte 0xFFFFFFF8
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
#.endobj UNKNOWN_WEIRD_SHIT

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E2860, local
	.float 0.9
.endobj lbl_803E2860
.obj lbl_803E2864, local
	.float 0.0
.endobj lbl_803E2864
.obj lbl_803E2868, local
	.float 0.0
.endobj lbl_803E2868
.obj lbl_803E286C, local
	.float 0.0
.endobj lbl_803E286C
.obj lbl_803E2870, local
	.float 0.0
.endobj lbl_803E2870
.obj lbl_803E2874, local
	.float 1.0
.endobj lbl_803E2874
.obj lbl_803E2878, local
	.float 0.0
.endobj lbl_803E2878
.obj lbl_803E287C, local
	.float 0.0
.endobj lbl_803E287C
.obj lbl_803E2880, local
	.float 1.0
.endobj lbl_803E2880
.obj lbl_803E2884, local
	.float 0.0
.endobj lbl_803E2884
.obj lbl_803E2888, local
	.float -1.0
.endobj lbl_803E2888
.obj lbl_803E288C, local
	.float -1.0
.endobj lbl_803E288C
.obj lbl_803E2890, local
	.float 0.0
.endobj lbl_803E2890
.obj lbl_803E2894, local
	.float 0.0
.endobj lbl_803E2894
.obj lbl_803E2898, local
	.float 0.0
.endobj lbl_803E2898
.obj lbl_803E289C, local
	.float 0.0
.endobj lbl_803E289C
.obj lbl_803E28A0, local
	.float 1.0
.endobj lbl_803E28A0
.obj lbl_803E28A4, local
	.float 0.0
.endobj lbl_803E28A4
.obj lbl_803E28A8, local
	.float 0.0
.endobj lbl_803E28A8
.obj lbl_803E28AC, local
	.float 1.0
.endobj lbl_803E28AC
.obj lbl_803E28B0, local
	.float 0.0
.endobj lbl_803E28B0
.obj lbl_803E28B4, local
	.float 1.0
.endobj lbl_803E28B4
.obj lbl_803E28B8, local
	.float 0.0
.endobj lbl_803E28B8
.obj lbl_803E28BC, local
	.float 0.0
.endobj lbl_803E28BC
.balign 4
.obj "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>", local
	.4byte lbl_802C2520
	.4byte 0
.endobj "__RTTI__Q23zen31CallBack1<PQ23zen11particleMdl>"
.balign 4
.obj "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>", local
	.4byte lbl_802C2544
	.4byte 0
.endobj "__RTTI__Q23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
.balign 4
.obj "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>", local
	.4byte lbl_802C2584
	.4byte 0
.endobj "__RTTI__Q23zen37CallBack1<PQ23zen17particleGenerator>"
.balign 4
.obj lbl_803E28D8, local
	.asciz "KEffect"
.endobj lbl_803E28D8
.balign 4
.obj __RTTI__7KEffect, local
	.4byte lbl_803E28D8
	.4byte lbl_802C25B0
.endobj __RTTI__7KEffect
.balign 4
.obj __RTTI__10BurnEffect, local
	.4byte lbl_802C2514
	.4byte lbl_802C25CC
.endobj __RTTI__10BurnEffect
.balign 4
.obj __RTTI__12RippleEffect, local
	.4byte lbl_802C262C
	.4byte lbl_802C263C
.endobj __RTTI__12RippleEffect
.balign 4
.obj __RTTI__15FreeLightEffect, local
	.4byte lbl_802C269C
	.4byte lbl_802C26AC
.endobj __RTTI__15FreeLightEffect
.balign 4
.obj __RTTI__16UfoSuikomiEffect, local
	.4byte lbl_802C270C
	.4byte lbl_802C2720
.endobj __RTTI__16UfoSuikomiEffect
.balign 4
.obj __RTTI__15WhistleTemplate, local
	.4byte lbl_802C2790
	.4byte lbl_802C27A0
.endobj __RTTI__15WhistleTemplate
.balign 4
.obj __RTTI__13UfoSuckEffect, local
	.4byte lbl_802C2780
	.4byte lbl_802C27C4
.endobj __RTTI__13UfoSuckEffect
.balign 4
.obj __RTTI__15BombEffectLight, local
	.4byte lbl_802C2868
	.4byte lbl_802C2878
.endobj __RTTI__15BombEffectLight
.balign 4
.obj __RTTI__10BombEffect, local
	.4byte lbl_802C28D8
	.4byte lbl_802C28E4
.endobj __RTTI__10BombEffect
.balign 4
.obj __RTTI__12SimpleEffect, local
	.4byte lbl_802C2944
	.4byte lbl_802C2954
.endobj __RTTI__12SimpleEffect
.balign 4
.obj lbl_803E2930, local
	.asciz "NaviFue"
.endobj lbl_803E2930
.balign 4
.obj __RTTI__7NaviFue, local
	.4byte lbl_803E2930
	.4byte lbl_802C29B4
.endobj __RTTI__7NaviFue
.balign 4
.obj __RTTI__15SmokeTreeEffect, local
	.4byte lbl_802C2A14
	.4byte lbl_802C2A24
.endobj __RTTI__15SmokeTreeEffect
.balign 4
.obj __RTTI__15SmokeRockEffect, local
	.4byte lbl_802C2A84
	.4byte lbl_802C2A94
.endobj __RTTI__15SmokeRockEffect
.balign 4
.obj __RTTI__16SmokeGrassEffect, local
	.4byte lbl_802C2AF4
	.4byte lbl_802C2B08
.endobj __RTTI__16SmokeGrassEffect
.balign 4
.obj __RTTI__15SmokeSoilEffect, local
	.4byte lbl_802C2B68
	.4byte lbl_802C2B78
.endobj __RTTI__15SmokeSoilEffect
.balign 4
.obj __RTTI__11NaviWhistle, local
	.4byte lbl_802C2BD8
	.4byte lbl_802C2BE4
.endobj __RTTI__11NaviWhistle
.balign 4
.obj __RTTI__10GoalEffect, local
	.4byte lbl_802C2C44
	.4byte lbl_802C2C50
.endobj __RTTI__10GoalEffect
.balign 4
.obj __RTTI__11SlimeEffect, local
	.4byte lbl_802C2CB0
	.4byte lbl_802C2CBC
.endobj __RTTI__11SlimeEffect

.section .sbss, "wa"
.balign 8
.obj utEffectMgr, global
	.skip 0x4
.endobj utEffectMgr
.balign 4
.obj effects__11UtEffectMgr, global
	.skip 0x4
.endobj effects__11UtEffectMgr

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA150, local
	.float 0.0
.endobj lbl_803EA150
.obj lbl_803EA154, local
	.float 0.01
.endobj lbl_803EA154
.obj lbl_803EA158, local
	.float 0.0016
.endobj lbl_803EA158
.obj lbl_803EA15C, local
	.float -0.12
.endobj lbl_803EA15C
.obj lbl_803EA160, local
	.float -0.09
.endobj lbl_803EA160
.obj lbl_803EA164, local
	.float 0.3
.endobj lbl_803EA164
.obj lbl_803EA168, local
	.float 400.0
.endobj lbl_803EA168
.obj lbl_803EA16C, local
	.float 15.0
.endobj lbl_803EA16C
.obj lbl_803EA170, local
	.float 1.0
.endobj lbl_803EA170
.balign 8
.obj lbl_803EA178, local
	.8byte 0x4330000080000000
.endobj lbl_803EA178
