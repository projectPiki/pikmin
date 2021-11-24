.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__15CoreNucleusPropFv
__ct__15CoreNucleusPropFv:
/* 8017A954 001778B4  7C 08 02 A6 */	mflr r0
/* 8017A958 001778B8  90 01 00 04 */	stw r0, 4(r1)
/* 8017A95C 001778BC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017A960 001778C0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017A964 001778C4  7C 7F 1B 78 */	mr r31, r3
/* 8017A968 001778C8  4B FD 2F 65 */	bl __ct__8BossPropFv
/* 8017A96C 001778CC  3C 60 80 22 */	lis r3, __vt__5ANode@ha
/* 8017A970 001778D0  38 03 73 8C */	addi r0, r3, __vt__5ANode@l
/* 8017A974 001778D4  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 8017A978 001778D8  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 8017A97C 001778DC  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 8017A980 001778E0  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 8017A984 001778E4  38 C0 00 00 */	li r6, 0
/* 8017A988 001778E8  3C A0 80 2D */	lis r5, lbl_802D134C@ha
/* 8017A98C 001778EC  90 DF 01 FC */	stw r6, 0x1fc(r31)
/* 8017A990 001778F0  3C 60 80 2D */	lis r3, __vt__15CoreNucleusProp@ha
/* 8017A994 001778F4  38 83 15 60 */	addi r4, r3, __vt__15CoreNucleusProp@l
/* 8017A998 001778F8  90 DF 01 F8 */	stw r6, 0x1f8(r31)
/* 8017A99C 001778FC  38 A5 13 4C */	addi r5, r5, lbl_802D134C@l
/* 8017A9A0 00177900  38 04 00 0C */	addi r0, r4, 0xc
/* 8017A9A4 00177904  90 DF 01 F4 */	stw r6, 0x1f4(r31)
/* 8017A9A8 00177908  7F E3 FB 78 */	mr r3, r31
/* 8017A9AC 0017790C  90 BF 01 F0 */	stw r5, 0x1f0(r31)
/* 8017A9B0 00177910  90 9F 00 54 */	stw r4, 0x54(r31)
/* 8017A9B4 00177914  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 8017A9B8 00177918  90 DF 02 00 */	stw r6, 0x200(r31)
/* 8017A9BC 0017791C  C0 22 AE 68 */	lfs f1, lbl_803EB068@sda21(r2)
/* 8017A9C0 00177920  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 8017A9C4 00177924  C0 02 AE 6C */	lfs f0, lbl_803EB06C@sda21(r2)
/* 8017A9C8 00177928  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 8017A9CC 0017792C  D0 3F 00 40 */	stfs f1, 0x40(r31)
/* 8017A9D0 00177930  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017A9D4 00177934  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017A9D8 00177938  38 21 00 18 */	addi r1, r1, 0x18
/* 8017A9DC 0017793C  7C 08 03 A6 */	mtlr r0
/* 8017A9E0 00177940  4E 80 00 20 */	blr 

.global __ct__11CoreNucleusFP12CreatureProp
__ct__11CoreNucleusFP12CreatureProp:
/* 8017A9E4 00177944  7C 08 02 A6 */	mflr r0
/* 8017A9E8 00177948  90 01 00 04 */	stw r0, 4(r1)
/* 8017A9EC 0017794C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017A9F0 00177950  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017A9F4 00177954  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017A9F8 00177958  7C 7E 1B 78 */	mr r30, r3
/* 8017A9FC 0017795C  4B FD 34 7D */	bl __ct__4BossFP12CreatureProp
/* 8017AA00 00177960  3C 60 80 2D */	lis r3, __vt__11CoreNucleus@ha
/* 8017AA04 00177964  38 03 13 D4 */	addi r0, r3, __vt__11CoreNucleus@l
/* 8017AA08 00177968  90 1E 00 00 */	stw r0, 0(r30)
/* 8017AA0C 0017796C  38 60 00 14 */	li r3, 0x14
/* 8017AA10 00177970  4B EC C5 F5 */	bl alloc__6SystemFUl
/* 8017AA14 00177974  3B E3 00 00 */	addi r31, r3, 0
/* 8017AA18 00177978  7F E3 FB 79 */	or. r3, r31, r31
/* 8017AA1C 0017797C  41 82 00 0C */	beq lbl_8017AA28
/* 8017AA20 00177980  38 80 00 03 */	li r4, 3
/* 8017AA24 00177984  4B F0 E2 0D */	bl __ct__8CollInfoFi
lbl_8017AA28:
/* 8017AA28 00177988  93 FE 02 20 */	stw r31, 0x220(r30)
/* 8017AA2C 0017798C  38 60 00 0C */	li r3, 0xc
/* 8017AA30 00177990  4B EC C5 D5 */	bl alloc__6SystemFUl
/* 8017AA34 00177994  3B E3 00 00 */	addi r31, r3, 0
/* 8017AA38 00177998  7F E3 FB 79 */	or. r3, r31, r31
/* 8017AA3C 0017799C  41 82 00 0C */	beq lbl_8017AA48
/* 8017AA40 001779A0  7F C4 F3 78 */	mr r4, r30
/* 8017AA44 001779A4  48 00 03 01 */	bl __ct__13CoreNucleusAiFP11CoreNucleus
lbl_8017AA48:
/* 8017AA48 001779A8  93 FE 03 C0 */	stw r31, 0x3c0(r30)
/* 8017AA4C 001779AC  7F C3 F3 78 */	mr r3, r30
/* 8017AA50 001779B0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017AA54 001779B4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017AA58 001779B8  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017AA5C 001779BC  38 21 00 18 */	addi r1, r1, 0x18
/* 8017AA60 001779C0  7C 08 03 A6 */	mtlr r0
/* 8017AA64 001779C4  4E 80 00 20 */	blr 

.global getiMass__11CoreNucleusFv
getiMass__11CoreNucleusFv:
/* 8017AA68 001779C8  C0 22 AE 70 */	lfs f1, lbl_803EB070@sda21(r2)
/* 8017AA6C 001779CC  4E 80 00 20 */	blr 

.global init__11CoreNucleusFR8Vector3f
init__11CoreNucleusFR8Vector3f:
/* 8017AA70 001779D0  7C 08 02 A6 */	mflr r0
/* 8017AA74 001779D4  38 A0 00 00 */	li r5, 0
/* 8017AA78 001779D8  90 01 00 04 */	stw r0, 4(r1)
/* 8017AA7C 001779DC  38 00 00 01 */	li r0, 1
/* 8017AA80 001779E0  38 83 00 00 */	addi r4, r3, 0
/* 8017AA84 001779E4  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017AA88 001779E8  C0 02 AE 74 */	lfs f0, lbl_803EB074@sda21(r2)
/* 8017AA8C 001779EC  D0 03 02 70 */	stfs f0, 0x270(r3)
/* 8017AA90 001779F0  C0 0D 07 68 */	lfs f0, lbl_803E5488@sda21(r13)
/* 8017AA94 001779F4  D0 03 00 7C */	stfs f0, 0x7c(r3)
/* 8017AA98 001779F8  C0 0D 07 6C */	lfs f0, lbl_803E548C@sda21(r13)
/* 8017AA9C 001779FC  D0 03 00 80 */	stfs f0, 0x80(r3)
/* 8017AAA0 00177A00  C0 0D 07 70 */	lfs f0, lbl_803E5490@sda21(r13)
/* 8017AAA4 00177A04  D0 03 00 84 */	stfs f0, 0x84(r3)
/* 8017AAA8 00177A08  98 A3 02 B8 */	stb r5, 0x2b8(r3)
/* 8017AAAC 00177A0C  98 A3 02 BB */	stb r5, 0x2bb(r3)
/* 8017AAB0 00177A10  98 03 02 BE */	stb r0, 0x2be(r3)
/* 8017AAB4 00177A14  C0 02 AE 78 */	lfs f0, lbl_803EB078@sda21(r2)
/* 8017AAB8 00177A18  D0 03 02 E0 */	stfs f0, 0x2e0(r3)
/* 8017AABC 00177A1C  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 8017AAC0 00177A20  48 00 02 A5 */	bl initAI__13CoreNucleusAiFP11CoreNucleus
/* 8017AAC4 00177A24  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017AAC8 00177A28  38 21 00 08 */	addi r1, r1, 8
/* 8017AACC 00177A2C  7C 08 03 A6 */	mtlr r0
/* 8017AAD0 00177A30  4E 80 00 20 */	blr 

.global doKill__11CoreNucleusFv
doKill__11CoreNucleusFv:
/* 8017AAD4 00177A34  7C 08 02 A6 */	mflr r0
/* 8017AAD8 00177A38  7C 64 1B 78 */	mr r4, r3
/* 8017AADC 00177A3C  90 01 00 04 */	stw r0, 4(r1)
/* 8017AAE0 00177A40  38 00 00 00 */	li r0, 0
/* 8017AAE4 00177A44  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017AAE8 00177A48  98 03 02 B8 */	stb r0, 0x2b8(r3)
/* 8017AAEC 00177A4C  98 03 02 B9 */	stb r0, 0x2b9(r3)
/* 8017AAF0 00177A50  80 6D 31 68 */	lwz r3, bossMgr@sda21(r13)
/* 8017AAF4 00177A54  4B FD 76 A5 */	bl kill__7BossMgrFP8Creature
/* 8017AAF8 00177A58  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017AAFC 00177A5C  38 21 00 08 */	addi r1, r1, 8
/* 8017AB00 00177A60  7C 08 03 A6 */	mtlr r0
/* 8017AB04 00177A64  4E 80 00 20 */	blr 

.global exitCourse__11CoreNucleusFv
exitCourse__11CoreNucleusFv:
/* 8017AB08 00177A68  4E 80 00 20 */	blr 

.global update__11CoreNucleusFv
update__11CoreNucleusFv:
/* 8017AB0C 00177A6C  7C 08 02 A6 */	mflr r0
/* 8017AB10 00177A70  90 01 00 04 */	stw r0, 4(r1)
/* 8017AB14 00177A74  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017AB18 00177A78  4B F1 06 F1 */	bl update__8CreatureFv
/* 8017AB1C 00177A7C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017AB20 00177A80  38 21 00 08 */	addi r1, r1, 8
/* 8017AB24 00177A84  7C 08 03 A6 */	mtlr r0
/* 8017AB28 00177A88  4E 80 00 20 */	blr 

.global refresh__11CoreNucleusFR8Graphics
refresh__11CoreNucleusFR8Graphics:
/* 8017AB2C 00177A8C  7C 08 02 A6 */	mflr r0
/* 8017AB30 00177A90  90 01 00 04 */	stw r0, 4(r1)
/* 8017AB34 00177A94  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 8017AB38 00177A98  93 E1 00 54 */	stw r31, 0x54(r1)
/* 8017AB3C 00177A9C  3B E4 00 00 */	addi r31, r4, 0
/* 8017AB40 00177AA0  93 C1 00 50 */	stw r30, 0x50(r1)
/* 8017AB44 00177AA4  3B C3 00 00 */	addi r30, r3, 0
/* 8017AB48 00177AA8  38 7E 02 28 */	addi r3, r30, 0x228
/* 8017AB4C 00177AAC  38 9E 00 7C */	addi r4, r30, 0x7c
/* 8017AB50 00177AB0  38 BE 00 88 */	addi r5, r30, 0x88
/* 8017AB54 00177AB4  38 DE 00 94 */	addi r6, r30, 0x94
/* 8017AB58 00177AB8  4B EC 35 9D */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 8017AB5C 00177ABC  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 8017AB60 00177AC0  38 9E 02 28 */	addi r4, r30, 0x228
/* 8017AB64 00177AC4  38 A1 00 10 */	addi r5, r1, 0x10
/* 8017AB68 00177AC8  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 8017AB6C 00177ACC  4B EC 35 69 */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 8017AB70 00177AD0  38 7E 03 3C */	addi r3, r30, 0x33c
/* 8017AB74 00177AD4  81 9E 03 6C */	lwz r12, 0x36c(r30)
/* 8017AB78 00177AD8  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8017AB7C 00177ADC  7D 88 03 A6 */	mtlr r12
/* 8017AB80 00177AE0  4E 80 00 21 */	blrl 
/* 8017AB84 00177AE4  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8017AB88 00177AE8  38 9F 00 00 */	addi r4, r31, 0
/* 8017AB8C 00177AEC  38 A1 00 10 */	addi r5, r1, 0x10
/* 8017AB90 00177AF0  80 63 00 00 */	lwz r3, 0(r3)
/* 8017AB94 00177AF4  38 C0 00 00 */	li r6, 0
/* 8017AB98 00177AF8  4B EB A7 7D */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 8017AB9C 00177AFC  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 8017ABA0 00177B00  38 9F 00 00 */	addi r4, r31, 0
/* 8017ABA4 00177B04  38 A0 00 00 */	li r5, 0
/* 8017ABA8 00177B08  4B F0 EF 45 */	bl updateInfo__8CollInfoFR8Graphicsb
/* 8017ABAC 00177B0C  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 8017ABB0 00177B10  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 8017ABB4 00177B14  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 8017ABB8 00177B18  38 21 00 58 */	addi r1, r1, 0x58
/* 8017ABBC 00177B1C  7C 08 03 A6 */	mtlr r0
/* 8017ABC0 00177B20  4E 80 00 20 */	blr 

.global drawShape__11CoreNucleusFR8Graphics
drawShape__11CoreNucleusFR8Graphics:
/* 8017ABC4 00177B24  7C 08 02 A6 */	mflr r0
/* 8017ABC8 00177B28  38 A0 00 00 */	li r5, 0
/* 8017ABCC 00177B2C  90 01 00 04 */	stw r0, 4(r1)
/* 8017ABD0 00177B30  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017ABD4 00177B34  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017ABD8 00177B38  3B E4 00 00 */	addi r31, r4, 0
/* 8017ABDC 00177B3C  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 8017ABE0 00177B40  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017ABE4 00177B44  3B C3 00 00 */	addi r30, r3, 0
/* 8017ABE8 00177B48  38 7F 00 00 */	addi r3, r31, 0
/* 8017ABEC 00177B4C  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 8017ABF0 00177B50  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 8017ABF4 00177B54  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8017ABF8 00177B58  7D 88 03 A6 */	mtlr r12
/* 8017ABFC 00177B5C  4E 80 00 21 */	blrl 
/* 8017AC00 00177B60  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8017AC04 00177B64  7F E4 FB 78 */	mr r4, r31
/* 8017AC08 00177B68  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 8017AC0C 00177B6C  38 C0 00 00 */	li r6, 0
/* 8017AC10 00177B70  80 63 00 00 */	lwz r3, 0(r3)
/* 8017AC14 00177B74  4B EB 58 59 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 8017AC18 00177B78  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017AC1C 00177B7C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017AC20 00177B80  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017AC24 00177B84  38 21 00 18 */	addi r1, r1, 0x18
/* 8017AC28 00177B88  7C 08 03 A6 */	mtlr r0
/* 8017AC2C 00177B8C  4E 80 00 20 */	blr 

.global doAI__11CoreNucleusFv
doAI__11CoreNucleusFv:
/* 8017AC30 00177B90  7C 08 02 A6 */	mflr r0
/* 8017AC34 00177B94  90 01 00 04 */	stw r0, 4(r1)
/* 8017AC38 00177B98  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017AC3C 00177B9C  80 63 03 C0 */	lwz r3, 0x3c0(r3)
/* 8017AC40 00177BA0  48 00 02 51 */	bl update__13CoreNucleusAiFv
/* 8017AC44 00177BA4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017AC48 00177BA8  38 21 00 08 */	addi r1, r1, 8
/* 8017AC4C 00177BAC  7C 08 03 A6 */	mtlr r0
/* 8017AC50 00177BB0  4E 80 00 20 */	blr 

.global doAnimation__11CoreNucleusFv
doAnimation__11CoreNucleusFv:
/* 8017AC54 00177BB4  7C 08 02 A6 */	mflr r0
/* 8017AC58 00177BB8  7C 64 1B 78 */	mr r4, r3
/* 8017AC5C 00177BBC  90 01 00 04 */	stw r0, 4(r1)
/* 8017AC60 00177BC0  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017AC64 00177BC4  80 03 03 90 */	lwz r0, 0x390(r3)
/* 8017AC68 00177BC8  28 00 00 00 */	cmplwi r0, 0
/* 8017AC6C 00177BCC  41 82 00 1C */	beq lbl_8017AC88
/* 8017AC70 00177BD0  81 84 03 6C */	lwz r12, 0x36c(r4)
/* 8017AC74 00177BD4  38 64 03 3C */	addi r3, r4, 0x33c
/* 8017AC78 00177BD8  C0 24 02 D8 */	lfs f1, 0x2d8(r4)
/* 8017AC7C 00177BDC  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8017AC80 00177BE0  7D 88 03 A6 */	mtlr r12
/* 8017AC84 00177BE4  4E 80 00 21 */	blrl 
lbl_8017AC88:
/* 8017AC88 00177BE8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017AC8C 00177BEC  38 21 00 08 */	addi r1, r1, 8
/* 8017AC90 00177BF0  7C 08 03 A6 */	mtlr r0
/* 8017AC94 00177BF4  4E 80 00 20 */	blr 

.global collisionCallback__11CoreNucleusFR9CollEvent
collisionCallback__11CoreNucleusFR9CollEvent:
/* 8017AC98 00177BF8  7C 08 02 A6 */	mflr r0
/* 8017AC9C 00177BFC  90 01 00 04 */	stw r0, 4(r1)
/* 8017ACA0 00177C00  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017ACA4 00177C04  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017ACA8 00177C08  7C 7F 1B 78 */	mr r31, r3
/* 8017ACAC 00177C0C  80 84 00 00 */	lwz r4, 0(r4)
/* 8017ACB0 00177C10  80 04 00 6C */	lwz r0, 0x6c(r4)
/* 8017ACB4 00177C14  2C 00 00 00 */	cmpwi r0, 0
/* 8017ACB8 00177C18  40 82 00 20 */	bne lbl_8017ACD8
/* 8017ACBC 00177C1C  7C 83 23 78 */	mr r3, r4
/* 8017ACC0 00177C20  4B F4 D8 95 */	bl getState__4PikiFv
/* 8017ACC4 00177C24  2C 03 00 0E */	cmpwi r3, 0xe
/* 8017ACC8 00177C28  40 82 00 10 */	bne lbl_8017ACD8
/* 8017ACCC 00177C2C  80 7F 03 BC */	lwz r3, 0x3bc(r31)
/* 8017ACD0 00177C30  38 00 00 01 */	li r0, 1
/* 8017ACD4 00177C34  98 03 03 C5 */	stb r0, 0x3c5(r3)
lbl_8017ACD8:
/* 8017ACD8 00177C38  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017ACDC 00177C3C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017ACE0 00177C40  38 21 00 18 */	addi r1, r1, 0x18
/* 8017ACE4 00177C44  7C 08 03 A6 */	mtlr r0
/* 8017ACE8 00177C48  4E 80 00 20 */	blr 

.global read__15CoreNucleusPropFR18RandomAccessStream
read__15CoreNucleusPropFR18RandomAccessStream:
/* 8017ACEC 00177C4C  7C 08 02 A6 */	mflr r0
/* 8017ACF0 00177C50  90 01 00 04 */	stw r0, 4(r1)
/* 8017ACF4 00177C54  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017ACF8 00177C58  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017ACFC 00177C5C  3B E4 00 00 */	addi r31, r4, 0
/* 8017AD00 00177C60  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017AD04 00177C64  3B C3 00 00 */	addi r30, r3, 0
/* 8017AD08 00177C68  4B EE 3E 91 */	bl read__10ParametersFR18RandomAccessStream
/* 8017AD0C 00177C6C  38 7E 00 58 */	addi r3, r30, 0x58
/* 8017AD10 00177C70  38 9F 00 00 */	addi r4, r31, 0
/* 8017AD14 00177C74  4B EE 3E 85 */	bl read__10ParametersFR18RandomAccessStream
/* 8017AD18 00177C78  38 7E 02 00 */	addi r3, r30, 0x200
/* 8017AD1C 00177C7C  38 9F 00 00 */	addi r4, r31, 0
/* 8017AD20 00177C80  4B EE 3E 79 */	bl read__10ParametersFR18RandomAccessStream
/* 8017AD24 00177C84  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017AD28 00177C88  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017AD2C 00177C8C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017AD30 00177C90  38 21 00 18 */	addi r1, r1, 0x18
/* 8017AD34 00177C94  7C 08 03 A6 */	mtlr r0
/* 8017AD38 00177C98  4E 80 00 20 */	blr 

"@492@read__15CoreNucleusPropFR18RandomAccessStream":
/* 8017AD3C 00177C9C  38 63 FE 14 */	addi r3, r3, -492
/* 8017AD40 00177CA0  4B FF FF AC */	b read__15CoreNucleusPropFR18RandomAccessStream

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802D1330:
	.asciz "CoreNucleus.cpp"
.balign 4
lbl_802D1340:
	.asciz "CoreNucleus"
.balign 4
lbl_802D134C:
	.asciz "CoreNode"
.balign 4
lbl_802D1358:
	.asciz "EventTalker"
.balign 4
lbl_802D1364:
	.asciz "RefCountable"
.balign 4
lbl_802D1374:
	.asciz "Creature"
.balign 4
lbl_802D1380:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D1394:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D13B0:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte __RTTI__4Boss
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__11CoreNucleus
__vt__11CoreNucleus:
	.4byte __RTTI__11CoreNucleus
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__11CoreNucleusFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__11CoreNucleusFv
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
	.4byte isVisible__4BossFv
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
	.4byte collisionCallback__11CoreNucleusFR9CollEvent
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
	.4byte update__11CoreNucleusFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__11CoreNucleusFR8Graphics
	.4byte refresh2d__4BossFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__11CoreNucleusFv
	.4byte doAnimation__11CoreNucleusFv
	.4byte doKill__11CoreNucleusFv
	.4byte exitCourse__11CoreNucleusFv
	.4byte isBossBgm__4BossFv
	.4byte attackDefaultPortion__4BossFv
	.4byte bombDamageCounter__4BossFP8CollPart
	.4byte drawShape__11CoreNucleusFR8Graphics
.balign 4
lbl_802D14F8:
	.asciz "CoreNucleusProp"
.balign 4
lbl_802D1508:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.balign 4
lbl_802D1514:
	.asciz "CreatureProp"
.balign 4
lbl_802D1524:
	.asciz "BossProp"
.balign 4
lbl_802D1530:
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte 0
lbl_802D153C:
	.4byte __RTTI__5ANode
	.4byte 0x1ec
	.4byte __RTTI__8CoreNode
	.4byte 0x1ec
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte __RTTI__8BossProp
	.4byte 0
	.4byte 0
.global __vt__15CoreNucleusProp
__vt__15CoreNucleusProp:
	.4byte __RTTI__15CoreNucleusProp
	.4byte 0
	.4byte read__15CoreNucleusPropFR18RandomAccessStream
	.4byte __RTTI__15CoreNucleusProp
	.4byte 0xfffffe14
	.4byte getAgeNodeType__5ANodeFv
	.4byte "@492@read__15CoreNucleusPropFR18RandomAccessStream"
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E5488:
	.float 0.0
lbl_803E548C:
	.float 0.0
lbl_803E5490:
	.float 0.0
__RTTI__11EventTalker:
	.4byte lbl_802D1358
	.4byte 0x00000000
__RTTI__12RefCountable:
	.4byte lbl_802D1364
	.4byte 0x00000000
__RTTI__8Creature:
	.4byte lbl_802D1374
	.4byte lbl_802D1380
.balign 4
lbl_803E54AC:
	.asciz "Boss"
.balign 4
__RTTI__4Boss:
	.4byte lbl_803E54AC
	.4byte lbl_802D1394
__RTTI__11CoreNucleus:
	.4byte lbl_802D1340
	.4byte lbl_802D13B0
.balign 4
lbl_803E54C4:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E54C4
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802D134C
	.4byte lbl_802D1508
__RTTI__12CreatureProp:
	.4byte lbl_802D1514
	.4byte 0
__RTTI__8BossProp:
	.4byte lbl_802D1524
	.4byte lbl_802D1530
__RTTI__15CoreNucleusProp:
	.4byte lbl_802D14F8
	.4byte lbl_802D153C

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EB068:
	.float 1.0
lbl_803EB06C:
	.float 0.0
lbl_803EB070:
	.float 0.01
lbl_803EB074:
	.float 20.0
lbl_803EB078:
	.float 40.0
