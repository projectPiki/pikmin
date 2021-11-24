.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__8MizuPropFv
__ct__8MizuPropFv:
/* 8017B3D4 00178334  7C 08 02 A6 */	mflr r0
/* 8017B3D8 00178338  90 01 00 04 */	stw r0, 4(r1)
/* 8017B3DC 0017833C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017B3E0 00178340  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017B3E4 00178344  7C 7F 1B 78 */	mr r31, r3
/* 8017B3E8 00178348  4B FD 24 E5 */	bl __ct__8BossPropFv
/* 8017B3EC 0017834C  3C 60 80 22 */	lis r3, __vt__5ANode@ha
/* 8017B3F0 00178350  38 03 73 8C */	addi r0, r3, __vt__5ANode@l
/* 8017B3F4 00178354  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 8017B3F8 00178358  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 8017B3FC 0017835C  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 8017B400 00178360  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 8017B404 00178364  38 C0 00 00 */	li r6, 0
/* 8017B408 00178368  3C A0 80 2D */	lis r5, lbl_802D1604@ha
/* 8017B40C 0017836C  90 DF 01 FC */	stw r6, 0x1fc(r31)
/* 8017B410 00178370  3C 60 80 2D */	lis r3, __vt__8MizuProp@ha
/* 8017B414 00178374  38 83 18 14 */	addi r4, r3, __vt__8MizuProp@l
/* 8017B418 00178378  90 DF 01 F8 */	stw r6, 0x1f8(r31)
/* 8017B41C 0017837C  38 A5 16 04 */	addi r5, r5, lbl_802D1604@l
/* 8017B420 00178380  38 04 00 0C */	addi r0, r4, 0xc
/* 8017B424 00178384  90 DF 01 F4 */	stw r6, 0x1f4(r31)
/* 8017B428 00178388  7F E3 FB 78 */	mr r3, r31
/* 8017B42C 0017838C  90 BF 01 F0 */	stw r5, 0x1f0(r31)
/* 8017B430 00178390  90 9F 00 54 */	stw r4, 0x54(r31)
/* 8017B434 00178394  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 8017B438 00178398  90 DF 02 00 */	stw r6, 0x200(r31)
/* 8017B43C 0017839C  C0 22 AE 88 */	lfs f1, lbl_803EB088@sda21(r2)
/* 8017B440 001783A0  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 8017B444 001783A4  C0 02 AE 8C */	lfs f0, lbl_803EB08C@sda21(r2)
/* 8017B448 001783A8  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 8017B44C 001783AC  D0 3F 00 40 */	stfs f1, 0x40(r31)
/* 8017B450 001783B0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017B454 001783B4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017B458 001783B8  38 21 00 18 */	addi r1, r1, 0x18
/* 8017B45C 001783BC  7C 08 03 A6 */	mtlr r0
/* 8017B460 001783C0  4E 80 00 20 */	blr 

.global __ct__4MizuFP12CreatureProp
__ct__4MizuFP12CreatureProp:
/* 8017B464 001783C4  7C 08 02 A6 */	mflr r0
/* 8017B468 001783C8  90 01 00 04 */	stw r0, 4(r1)
/* 8017B46C 001783CC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017B470 001783D0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017B474 001783D4  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017B478 001783D8  7C 7E 1B 78 */	mr r30, r3
/* 8017B47C 001783DC  4B FD 29 FD */	bl __ct__4BossFP12CreatureProp
/* 8017B480 001783E0  3C 60 80 2D */	lis r3, __vt__4Mizu@ha
/* 8017B484 001783E4  38 03 16 8C */	addi r0, r3, __vt__4Mizu@l
/* 8017B488 001783E8  90 1E 00 00 */	stw r0, 0(r30)
/* 8017B48C 001783EC  38 60 00 14 */	li r3, 0x14
/* 8017B490 001783F0  4B EC BB 75 */	bl alloc__6SystemFUl
/* 8017B494 001783F4  3B E3 00 00 */	addi r31, r3, 0
/* 8017B498 001783F8  7F E3 FB 79 */	or. r3, r31, r31
/* 8017B49C 001783FC  41 82 00 0C */	beq lbl_8017B4A8
/* 8017B4A0 00178400  38 80 00 03 */	li r4, 3
/* 8017B4A4 00178404  4B F0 D7 8D */	bl __ct__8CollInfoFi
lbl_8017B4A8:
/* 8017B4A8 00178408  93 FE 02 20 */	stw r31, 0x220(r30)
/* 8017B4AC 0017840C  38 60 00 14 */	li r3, 0x14
/* 8017B4B0 00178410  4B EC BB 55 */	bl alloc__6SystemFUl
/* 8017B4B4 00178414  3B E3 00 00 */	addi r31, r3, 0
/* 8017B4B8 00178418  7F E3 FB 79 */	or. r3, r31, r31
/* 8017B4BC 0017841C  41 82 00 0C */	beq lbl_8017B4C8
/* 8017B4C0 00178420  7F C4 F3 78 */	mr r4, r30
/* 8017B4C4 00178424  48 00 03 95 */	bl __ct__6MizuAiFP4Mizu
lbl_8017B4C8:
/* 8017B4C8 00178428  93 FE 03 BC */	stw r31, 0x3bc(r30)
/* 8017B4CC 0017842C  7F C3 F3 78 */	mr r3, r30
/* 8017B4D0 00178430  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017B4D4 00178434  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017B4D8 00178438  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017B4DC 0017843C  38 21 00 18 */	addi r1, r1, 0x18
/* 8017B4E0 00178440  7C 08 03 A6 */	mtlr r0
/* 8017B4E4 00178444  4E 80 00 20 */	blr 

.global attackDefaultPortion__4MizuFv
attackDefaultPortion__4MizuFv:
/* 8017B4E8 00178448  7C 08 02 A6 */	mflr r0
/* 8017B4EC 0017844C  38 80 00 33 */	li r4, 0x33
/* 8017B4F0 00178450  90 01 00 04 */	stw r0, 4(r1)
/* 8017B4F4 00178454  38 C0 00 00 */	li r6, 0
/* 8017B4F8 00178458  38 E0 00 00 */	li r7, 0
/* 8017B4FC 0017845C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017B500 00178460  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017B504 00178464  7C 7F 1B 78 */	mr r31, r3
/* 8017B508 00178468  38 BF 00 94 */	addi r5, r31, 0x94
/* 8017B50C 0017846C  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8017B510 00178470  48 02 16 29 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8017B514 00178474  80 6D 31 80 */	lwz r3, effectMgr@sda21(r13)
/* 8017B518 00178478  38 BF 00 94 */	addi r5, r31, 0x94
/* 8017B51C 0017847C  38 80 00 32 */	li r4, 0x32
/* 8017B520 00178480  38 C0 00 00 */	li r6, 0
/* 8017B524 00178484  38 E0 00 00 */	li r7, 0
/* 8017B528 00178488  48 02 16 11 */	bl "create__9EffectMgrFQ29EffectMgr12effTypeTableR8Vector3fPQ23zen37CallBack1<PQ23zen17particleGenerator>PQ23zen58CallBack2<PQ23zen17particleGenerator,PQ23zen11particleMdl>"
/* 8017B52C 0017848C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017B530 00178490  38 60 00 01 */	li r3, 1
/* 8017B534 00178494  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017B538 00178498  38 21 00 18 */	addi r1, r1, 0x18
/* 8017B53C 0017849C  7C 08 03 A6 */	mtlr r0
/* 8017B540 001784A0  4E 80 00 20 */	blr 

.global getiMass__4MizuFv
getiMass__4MizuFv:
/* 8017B544 001784A4  C0 22 AE 90 */	lfs f1, lbl_803EB090@sda21(r2)
/* 8017B548 001784A8  4E 80 00 20 */	blr 

.global initMizu__4MizuFR8Vector3f
initMizu__4MizuFR8Vector3f:
/* 8017B54C 001784AC  7C 08 02 A6 */	mflr r0
/* 8017B550 001784B0  7C 64 1B 78 */	mr r4, r3
/* 8017B554 001784B4  90 01 00 04 */	stw r0, 4(r1)
/* 8017B558 001784B8  38 00 00 01 */	li r0, 1
/* 8017B55C 001784BC  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017B560 001784C0  C0 02 AE 94 */	lfs f0, lbl_803EB094@sda21(r2)
/* 8017B564 001784C4  D0 03 02 70 */	stfs f0, 0x270(r3)
/* 8017B568 001784C8  98 03 02 BE */	stb r0, 0x2be(r3)
/* 8017B56C 001784CC  C0 02 AE 98 */	lfs f0, lbl_803EB098@sda21(r2)
/* 8017B570 001784D0  D0 03 02 E0 */	stfs f0, 0x2e0(r3)
/* 8017B574 001784D4  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 8017B578 001784D8  48 00 03 61 */	bl initMizu__6MizuAiFP4Mizu
/* 8017B57C 001784DC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017B580 001784E0  38 21 00 08 */	addi r1, r1, 8
/* 8017B584 001784E4  7C 08 03 A6 */	mtlr r0
/* 8017B588 001784E8  4E 80 00 20 */	blr 

.global initGeyzer__4MizuFR8Vector3f
initGeyzer__4MizuFR8Vector3f:
/* 8017B58C 001784EC  7C 08 02 A6 */	mflr r0
/* 8017B590 001784F0  7C 64 1B 78 */	mr r4, r3
/* 8017B594 001784F4  90 01 00 04 */	stw r0, 4(r1)
/* 8017B598 001784F8  38 00 00 01 */	li r0, 1
/* 8017B59C 001784FC  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017B5A0 00178500  C0 02 AE 94 */	lfs f0, lbl_803EB094@sda21(r2)
/* 8017B5A4 00178504  D0 03 02 70 */	stfs f0, 0x270(r3)
/* 8017B5A8 00178508  98 03 02 BE */	stb r0, 0x2be(r3)
/* 8017B5AC 0017850C  C0 02 AE 98 */	lfs f0, lbl_803EB098@sda21(r2)
/* 8017B5B0 00178510  D0 03 02 E0 */	stfs f0, 0x2e0(r3)
/* 8017B5B4 00178514  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 8017B5B8 00178518  48 00 03 D9 */	bl initGeyzer__6MizuAiFP4Mizu
/* 8017B5BC 0017851C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017B5C0 00178520  38 21 00 08 */	addi r1, r1, 8
/* 8017B5C4 00178524  7C 08 03 A6 */	mtlr r0
/* 8017B5C8 00178528  4E 80 00 20 */	blr 

.global doKill__4MizuFv
doKill__4MizuFv:
/* 8017B5CC 0017852C  7C 08 02 A6 */	mflr r0
/* 8017B5D0 00178530  38 80 00 00 */	li r4, 0
/* 8017B5D4 00178534  90 01 00 04 */	stw r0, 4(r1)
/* 8017B5D8 00178538  38 00 00 00 */	li r0, 0
/* 8017B5DC 0017853C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017B5E0 00178540  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017B5E4 00178544  3B E3 00 00 */	addi r31, r3, 0
/* 8017B5E8 00178548  98 03 02 B8 */	stb r0, 0x2b8(r3)
/* 8017B5EC 0017854C  98 03 02 B9 */	stb r0, 0x2b9(r3)
/* 8017B5F0 00178550  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 8017B5F4 00178554  48 00 04 59 */	bl killCallBackEffect__6MizuAiFb
/* 8017B5F8 00178558  80 6D 31 68 */	lwz r3, bossMgr@sda21(r13)
/* 8017B5FC 0017855C  7F E4 FB 78 */	mr r4, r31
/* 8017B600 00178560  4B FD 6B 99 */	bl kill__7BossMgrFP8Creature
/* 8017B604 00178564  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017B608 00178568  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017B60C 0017856C  38 21 00 18 */	addi r1, r1, 0x18
/* 8017B610 00178570  7C 08 03 A6 */	mtlr r0
/* 8017B614 00178574  4E 80 00 20 */	blr 

.global exitCourse__4MizuFv
exitCourse__4MizuFv:
/* 8017B618 00178578  7C 08 02 A6 */	mflr r0
/* 8017B61C 0017857C  38 80 00 01 */	li r4, 1
/* 8017B620 00178580  90 01 00 04 */	stw r0, 4(r1)
/* 8017B624 00178584  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017B628 00178588  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 8017B62C 0017858C  48 00 04 21 */	bl killCallBackEffect__6MizuAiFb
/* 8017B630 00178590  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017B634 00178594  38 21 00 08 */	addi r1, r1, 8
/* 8017B638 00178598  7C 08 03 A6 */	mtlr r0
/* 8017B63C 0017859C  4E 80 00 20 */	blr 

.global update__4MizuFv
update__4MizuFv:
/* 8017B640 001785A0  7C 08 02 A6 */	mflr r0
/* 8017B644 001785A4  90 01 00 04 */	stw r0, 4(r1)
/* 8017B648 001785A8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017B64C 001785AC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017B650 001785B0  7C 7F 1B 78 */	mr r31, r3
/* 8017B654 001785B4  81 9F 00 00 */	lwz r12, 0(r31)
/* 8017B658 001785B8  81 8C 01 04 */	lwz r12, 0x104(r12)
/* 8017B65C 001785BC  7D 88 03 A6 */	mtlr r12
/* 8017B660 001785C0  4E 80 00 21 */	blrl 
/* 8017B664 001785C4  7F E3 FB 78 */	mr r3, r31
/* 8017B668 001785C8  81 9F 00 00 */	lwz r12, 0(r31)
/* 8017B66C 001785CC  81 8C 01 08 */	lwz r12, 0x108(r12)
/* 8017B670 001785D0  7D 88 03 A6 */	mtlr r12
/* 8017B674 001785D4  4E 80 00 21 */	blrl 
/* 8017B678 001785D8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017B67C 001785DC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017B680 001785E0  38 21 00 18 */	addi r1, r1, 0x18
/* 8017B684 001785E4  7C 08 03 A6 */	mtlr r0
/* 8017B688 001785E8  4E 80 00 20 */	blr 

.global refresh__4MizuFR8Graphics
refresh__4MizuFR8Graphics:
/* 8017B68C 001785EC  7C 08 02 A6 */	mflr r0
/* 8017B690 001785F0  90 01 00 04 */	stw r0, 4(r1)
/* 8017B694 001785F4  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 8017B698 001785F8  93 E1 00 54 */	stw r31, 0x54(r1)
/* 8017B69C 001785FC  3B E4 00 00 */	addi r31, r4, 0
/* 8017B6A0 00178600  93 C1 00 50 */	stw r30, 0x50(r1)
/* 8017B6A4 00178604  3B C3 00 00 */	addi r30, r3, 0
/* 8017B6A8 00178608  38 7E 02 28 */	addi r3, r30, 0x228
/* 8017B6AC 0017860C  38 9E 00 7C */	addi r4, r30, 0x7c
/* 8017B6B0 00178610  38 BE 00 88 */	addi r5, r30, 0x88
/* 8017B6B4 00178614  38 DE 00 94 */	addi r6, r30, 0x94
/* 8017B6B8 00178618  4B EC 2A 3D */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 8017B6BC 0017861C  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 8017B6C0 00178620  38 9E 02 28 */	addi r4, r30, 0x228
/* 8017B6C4 00178624  38 A1 00 10 */	addi r5, r1, 0x10
/* 8017B6C8 00178628  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 8017B6CC 0017862C  4B EC 2A 09 */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 8017B6D0 00178630  38 7E 03 3C */	addi r3, r30, 0x33c
/* 8017B6D4 00178634  81 9E 03 6C */	lwz r12, 0x36c(r30)
/* 8017B6D8 00178638  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8017B6DC 0017863C  7D 88 03 A6 */	mtlr r12
/* 8017B6E0 00178640  4E 80 00 21 */	blrl 
/* 8017B6E4 00178644  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8017B6E8 00178648  38 9F 00 00 */	addi r4, r31, 0
/* 8017B6EC 0017864C  38 A1 00 10 */	addi r5, r1, 0x10
/* 8017B6F0 00178650  80 63 00 00 */	lwz r3, 0(r3)
/* 8017B6F4 00178654  38 C0 00 00 */	li r6, 0
/* 8017B6F8 00178658  4B EB 9C 1D */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 8017B6FC 0017865C  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 8017B700 00178660  38 9F 00 00 */	addi r4, r31, 0
/* 8017B704 00178664  38 A0 00 00 */	li r5, 0
/* 8017B708 00178668  4B F0 E3 E5 */	bl updateInfo__8CollInfoFR8Graphicsb
/* 8017B70C 0017866C  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 8017B710 00178670  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 8017B714 00178674  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 8017B718 00178678  38 21 00 58 */	addi r1, r1, 0x58
/* 8017B71C 0017867C  7C 08 03 A6 */	mtlr r0
/* 8017B720 00178680  4E 80 00 20 */	blr 

.global drawShape__4MizuFR8Graphics
drawShape__4MizuFR8Graphics:
/* 8017B724 00178684  7C 08 02 A6 */	mflr r0
/* 8017B728 00178688  38 A0 00 00 */	li r5, 0
/* 8017B72C 0017868C  90 01 00 04 */	stw r0, 4(r1)
/* 8017B730 00178690  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017B734 00178694  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017B738 00178698  3B E4 00 00 */	addi r31, r4, 0
/* 8017B73C 0017869C  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 8017B740 001786A0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017B744 001786A4  3B C3 00 00 */	addi r30, r3, 0
/* 8017B748 001786A8  38 7F 00 00 */	addi r3, r31, 0
/* 8017B74C 001786AC  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 8017B750 001786B0  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 8017B754 001786B4  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8017B758 001786B8  7D 88 03 A6 */	mtlr r12
/* 8017B75C 001786BC  4E 80 00 21 */	blrl 
/* 8017B760 001786C0  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8017B764 001786C4  7F E4 FB 78 */	mr r4, r31
/* 8017B768 001786C8  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 8017B76C 001786CC  38 C0 00 00 */	li r6, 0
/* 8017B770 001786D0  80 63 00 00 */	lwz r3, 0(r3)
/* 8017B774 001786D4  4B EB 4C F9 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 8017B778 001786D8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017B77C 001786DC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017B780 001786E0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017B784 001786E4  38 21 00 18 */	addi r1, r1, 0x18
/* 8017B788 001786E8  7C 08 03 A6 */	mtlr r0
/* 8017B78C 001786EC  4E 80 00 20 */	blr 

.global doAI__4MizuFv
doAI__4MizuFv:
/* 8017B790 001786F0  7C 08 02 A6 */	mflr r0
/* 8017B794 001786F4  90 01 00 04 */	stw r0, 4(r1)
/* 8017B798 001786F8  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017B79C 001786FC  80 63 03 BC */	lwz r3, 0x3bc(r3)
/* 8017B7A0 00178700  48 00 07 21 */	bl update__6MizuAiFv
/* 8017B7A4 00178704  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017B7A8 00178708  38 21 00 08 */	addi r1, r1, 8
/* 8017B7AC 0017870C  7C 08 03 A6 */	mtlr r0
/* 8017B7B0 00178710  4E 80 00 20 */	blr 

.global doAnimation__4MizuFv
doAnimation__4MizuFv:
/* 8017B7B4 00178714  7C 08 02 A6 */	mflr r0
/* 8017B7B8 00178718  7C 64 1B 78 */	mr r4, r3
/* 8017B7BC 0017871C  90 01 00 04 */	stw r0, 4(r1)
/* 8017B7C0 00178720  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017B7C4 00178724  80 03 03 90 */	lwz r0, 0x390(r3)
/* 8017B7C8 00178728  28 00 00 00 */	cmplwi r0, 0
/* 8017B7CC 0017872C  41 82 00 1C */	beq lbl_8017B7E8
/* 8017B7D0 00178730  81 84 03 6C */	lwz r12, 0x36c(r4)
/* 8017B7D4 00178734  38 64 03 3C */	addi r3, r4, 0x33c
/* 8017B7D8 00178738  C0 24 02 D8 */	lfs f1, 0x2d8(r4)
/* 8017B7DC 0017873C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8017B7E0 00178740  7D 88 03 A6 */	mtlr r12
/* 8017B7E4 00178744  4E 80 00 21 */	blrl 
lbl_8017B7E8:
/* 8017B7E8 00178748  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017B7EC 0017874C  38 21 00 08 */	addi r1, r1, 8
/* 8017B7F0 00178750  7C 08 03 A6 */	mtlr r0
/* 8017B7F4 00178754  4E 80 00 20 */	blr 

.global isVisible__4MizuFv
isVisible__4MizuFv:
/* 8017B7F8 00178758  88 63 03 B9 */	lbz r3, 0x3b9(r3)
/* 8017B7FC 0017875C  4E 80 00 20 */	blr 

.global read__8MizuPropFR18RandomAccessStream
read__8MizuPropFR18RandomAccessStream:
/* 8017B800 00178760  7C 08 02 A6 */	mflr r0
/* 8017B804 00178764  90 01 00 04 */	stw r0, 4(r1)
/* 8017B808 00178768  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017B80C 0017876C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017B810 00178770  3B E4 00 00 */	addi r31, r4, 0
/* 8017B814 00178774  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017B818 00178778  3B C3 00 00 */	addi r30, r3, 0
/* 8017B81C 0017877C  4B EE 33 7D */	bl read__10ParametersFR18RandomAccessStream
/* 8017B820 00178780  38 7E 00 58 */	addi r3, r30, 0x58
/* 8017B824 00178784  38 9F 00 00 */	addi r4, r31, 0
/* 8017B828 00178788  4B EE 33 71 */	bl read__10ParametersFR18RandomAccessStream
/* 8017B82C 0017878C  38 7E 02 00 */	addi r3, r30, 0x200
/* 8017B830 00178790  38 9F 00 00 */	addi r4, r31, 0
/* 8017B834 00178794  4B EE 33 65 */	bl read__10ParametersFR18RandomAccessStream
/* 8017B838 00178798  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017B83C 0017879C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017B840 001787A0  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017B844 001787A4  38 21 00 18 */	addi r1, r1, 0x18
/* 8017B848 001787A8  7C 08 03 A6 */	mtlr r0
/* 8017B84C 001787AC  4E 80 00 20 */	blr 

.global "@492@read__8MizuPropFR18RandomAccessStream"
"@492@read__8MizuPropFR18RandomAccessStream":
/* 8017B850 001787B0  38 63 FE 14 */	addi r3, r3, -492
/* 8017B854 001787B4  4B FF FF AC */	b read__8MizuPropFR18RandomAccessStream

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802D15F8:
	.asciz "Mizu.cpp"
.balign 4
lbl_802D1604:
	.asciz "CoreNode"
.balign 4
lbl_802D1610:
	.asciz "EventTalker"
.balign 4
lbl_802D161C:
	.asciz "RefCountable"
.balign 4
lbl_802D162C:
	.asciz "Creature"
.balign 4
lbl_802D1638:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D164C:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D1668:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte __RTTI__4Boss
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__4Mizu
__vt__4Mizu:
	.4byte __RTTI__4Mizu
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8CreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__4MizuFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__4BossFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__4BossFv
	.4byte isVisible__4MizuFv
	.4byte isOrganic__4BossFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__4BossFv
	.4byte isAlive__4BossFv
	.4byte isFixed__4BossFv
	.4byte needShadow__4BossFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__4BossFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__4BossFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__4BossFR9CollEvent
	.4byte bounceCallback__8CreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__4BossFR5PlaneP13DynCollObject
	.4byte offwallCallback__8CreatureFP13DynCollObject
	.4byte stickCallback__8CreatureFP8Creature
	.4byte offstickCallback__8CreatureFP8Creature
	.4byte stickToCallback__8CreatureFP8Creature
	.4byte dump__8CreatureFv
	.4byte startWaterEffect__8CreatureFv
	.4byte finishWaterEffect__8CreatureFv
	.4byte isRopable__8CreatureFv
	.4byte mayIstick__8CreatureFv
	.4byte getFormationPri__8CreatureFv
	.4byte update__4MizuFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__4MizuFR8Graphics
	.4byte refresh2d__4BossFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__4MizuFv
	.4byte doAnimation__4MizuFv
	.4byte doKill__4MizuFv
	.4byte exitCourse__4MizuFv
	.4byte isBossBgm__4BossFv
	.4byte attackDefaultPortion__4MizuFv
	.4byte bombDamageCounter__4BossFP8CollPart
	.4byte drawShape__4MizuFR8Graphics
.balign 4
lbl_802D17B0:
	.asciz "MizuProp"
.balign 4
lbl_802D17BC:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.balign 4
lbl_802D17C8:
	.asciz "CreatureProp"
.balign 4
lbl_802D17D8:
	.asciz "BossProp"
.balign 4
lbl_802D17E4:
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte 0
lbl_802D17F0:
	.4byte __RTTI__5ANode
	.4byte 0x1ec
	.4byte __RTTI__8CoreNode
	.4byte 0x1ec
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte __RTTI__8BossProp
	.4byte 0
	.4byte 0
.global __vt__8MizuProp
__vt__8MizuProp:
	.4byte __RTTI__8MizuProp
	.4byte 0
	.4byte read__8MizuPropFR18RandomAccessStream
	.4byte __RTTI__8MizuProp
	.4byte 0xfffffe14
	.4byte getAgeNodeType__5ANodeFv
	.4byte "@492@read__8MizuPropFR18RandomAccessStream"
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E5510:
	.asciz "Mizu"
.balign 4
__RTTI__11EventTalker:
	.4byte lbl_802D1610
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802D161C
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802D162C
	.4byte lbl_802D1638
.balign 4
lbl_803E5530:
	.asciz "Boss"
.balign 4
__RTTI__4Boss:
	.4byte lbl_803E5530
	.4byte lbl_802D164C
__RTTI__4Mizu:
	.4byte lbl_803E5510
	.4byte lbl_802D1668
.balign 4
lbl_803E5548:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E5548
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802D1604
	.4byte lbl_802D17BC
__RTTI__12CreatureProp:
	.4byte lbl_802D17C8
	.4byte 0
__RTTI__8BossProp:
	.4byte lbl_802D17D8
	.4byte lbl_802D17E4
__RTTI__8MizuProp:
	.4byte lbl_802D17B0
	.4byte lbl_802D17F0

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EB088:
	.float 1.0
lbl_803EB08C:
	.float 0.0
lbl_803EB090:
	.4byte 0x38D1B717
lbl_803EB094:
	.float 10.0
lbl_803EB098:
	.float 20.0
