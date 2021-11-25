.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__12KingBackPropFv
__ct__12KingBackPropFv:
/* 80179E08 00176D68  7C 08 02 A6 */	mflr r0
/* 80179E0C 00176D6C  90 01 00 04 */	stw r0, 4(r1)
/* 80179E10 00176D70  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80179E14 00176D74  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80179E18 00176D78  7C 7F 1B 78 */	mr r31, r3
/* 80179E1C 00176D7C  4B FD 3A B1 */	bl __ct__8BossPropFv
/* 80179E20 00176D80  3C 60 80 22 */	lis r3, __vt__5ANode@ha
/* 80179E24 00176D84  38 03 73 8C */	addi r0, r3, __vt__5ANode@l
/* 80179E28 00176D88  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 80179E2C 00176D8C  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 80179E30 00176D90  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 80179E34 00176D94  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 80179E38 00176D98  38 C0 00 00 */	li r6, 0
/* 80179E3C 00176D9C  3C A0 80 2D */	lis r5, lbl_802D0E34@ha
/* 80179E40 00176DA0  90 DF 01 FC */	stw r6, 0x1fc(r31)
/* 80179E44 00176DA4  3C 60 80 2D */	lis r3, __vt__12KingBackProp@ha
/* 80179E48 00176DA8  38 83 10 48 */	addi r4, r3, __vt__12KingBackProp@l
/* 80179E4C 00176DAC  90 DF 01 F8 */	stw r6, 0x1f8(r31)
/* 80179E50 00176DB0  38 A5 0E 34 */	addi r5, r5, lbl_802D0E34@l
/* 80179E54 00176DB4  38 04 00 0C */	addi r0, r4, 0xc
/* 80179E58 00176DB8  90 DF 01 F4 */	stw r6, 0x1f4(r31)
/* 80179E5C 00176DBC  7F E3 FB 78 */	mr r3, r31
/* 80179E60 00176DC0  90 BF 01 F0 */	stw r5, 0x1f0(r31)
/* 80179E64 00176DC4  90 9F 00 54 */	stw r4, 0x54(r31)
/* 80179E68 00176DC8  90 1F 01 EC */	stw r0, 0x1ec(r31)
/* 80179E6C 00176DCC  90 DF 02 00 */	stw r6, 0x200(r31)
/* 80179E70 00176DD0  C0 22 AE 38 */	lfs f1, lbl_803EB038@sda21(r2)
/* 80179E74 00176DD4  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 80179E78 00176DD8  C0 02 AE 3C */	lfs f0, lbl_803EB03C@sda21(r2)
/* 80179E7C 00176DDC  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 80179E80 00176DE0  D0 3F 00 40 */	stfs f1, 0x40(r31)
/* 80179E84 00176DE4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80179E88 00176DE8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80179E8C 00176DEC  38 21 00 18 */	addi r1, r1, 0x18
/* 80179E90 00176DF0  7C 08 03 A6 */	mtlr r0
/* 80179E94 00176DF4  4E 80 00 20 */	blr 

.global __ct__8KingBackFP12CreatureProp
__ct__8KingBackFP12CreatureProp:
/* 80179E98 00176DF8  7C 08 02 A6 */	mflr r0
/* 80179E9C 00176DFC  90 01 00 04 */	stw r0, 4(r1)
/* 80179EA0 00176E00  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80179EA4 00176E04  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80179EA8 00176E08  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80179EAC 00176E0C  7C 7E 1B 78 */	mr r30, r3
/* 80179EB0 00176E10  4B FD 3F C9 */	bl __ct__4BossFP12CreatureProp
/* 80179EB4 00176E14  3C 60 80 2D */	lis r3, __vt__8KingBack@ha
/* 80179EB8 00176E18  38 03 0E BC */	addi r0, r3, __vt__8KingBack@l
/* 80179EBC 00176E1C  90 1E 00 00 */	stw r0, 0(r30)
/* 80179EC0 00176E20  38 00 00 00 */	li r0, 0
/* 80179EC4 00176E24  38 60 00 14 */	li r3, 0x14
/* 80179EC8 00176E28  90 1E 03 FC */	stw r0, 0x3fc(r30)
/* 80179ECC 00176E2C  4B EC D1 39 */	bl alloc__6SystemFUl
/* 80179ED0 00176E30  3B E3 00 00 */	addi r31, r3, 0
/* 80179ED4 00176E34  7F E3 FB 79 */	or. r3, r31, r31
/* 80179ED8 00176E38  41 82 00 0C */	beq lbl_80179EE4
/* 80179EDC 00176E3C  38 80 00 04 */	li r4, 4
/* 80179EE0 00176E40  4B F0 ED 51 */	bl __ct__8CollInfoFi
lbl_80179EE4:
/* 80179EE4 00176E44  93 FE 02 20 */	stw r31, 0x220(r30)
/* 80179EE8 00176E48  7F C3 F3 78 */	mr r3, r30
/* 80179EEC 00176E4C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80179EF0 00176E50  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80179EF4 00176E54  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80179EF8 00176E58  38 21 00 18 */	addi r1, r1, 0x18
/* 80179EFC 00176E5C  7C 08 03 A6 */	mtlr r0
/* 80179F00 00176E60  4E 80 00 20 */	blr 

.global getiMass__8KingBackFv
getiMass__8KingBackFv:
/* 80179F04 00176E64  C0 22 AE 40 */	lfs f1, lbl_803EB040@sda21(r2)
/* 80179F08 00176E68  4E 80 00 20 */	blr 

.global init__8KingBackFR8Vector3f
init__8KingBackFR8Vector3f:
/* 80179F0C 00176E6C  7C 08 02 A6 */	mflr r0
/* 80179F10 00176E70  38 83 00 00 */	addi r4, r3, 0
/* 80179F14 00176E74  90 01 00 04 */	stw r0, 4(r1)
/* 80179F18 00176E78  38 60 00 00 */	li r3, 0
/* 80179F1C 00176E7C  38 00 00 01 */	li r0, 1
/* 80179F20 00176E80  94 21 FF F8 */	stwu r1, -8(r1)
/* 80179F24 00176E84  C0 02 AE 44 */	lfs f0, lbl_803EB044@sda21(r2)
/* 80179F28 00176E88  D0 04 02 70 */	stfs f0, 0x270(r4)
/* 80179F2C 00176E8C  98 64 02 BB */	stb r3, 0x2bb(r4)
/* 80179F30 00176E90  38 64 03 B8 */	addi r3, r4, 0x3b8
/* 80179F34 00176E94  98 04 02 BC */	stb r0, 0x2bc(r4)
/* 80179F38 00176E98  80 C4 03 90 */	lwz r6, 0x390(r4)
/* 80179F3C 00176E9C  80 AD 2F 00 */	lwz r5, mapMgr@sda21(r13)
/* 80179F40 00176EA0  80 C6 00 00 */	lwz r6, 0(r6)
/* 80179F44 00176EA4  4B F1 41 7D */	bl init__15CreaturePlatMgrFP8CreatureP6MapMgrP5Shape
/* 80179F48 00176EA8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80179F4C 00176EAC  38 21 00 08 */	addi r1, r1, 8
/* 80179F50 00176EB0  7C 08 03 A6 */	mtlr r0
/* 80179F54 00176EB4  4E 80 00 20 */	blr 

.global doKill__8KingBackFv
doKill__8KingBackFv:
/* 80179F58 00176EB8  7C 08 02 A6 */	mflr r0
/* 80179F5C 00176EBC  90 01 00 04 */	stw r0, 4(r1)
/* 80179F60 00176EC0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80179F64 00176EC4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80179F68 00176EC8  3B E3 00 00 */	addi r31, r3, 0
/* 80179F6C 00176ECC  38 7F 03 B8 */	addi r3, r31, 0x3b8
/* 80179F70 00176ED0  4B F1 41 F1 */	bl release__15CreaturePlatMgrFv
/* 80179F74 00176ED4  80 6D 31 68 */	lwz r3, bossMgr@sda21(r13)
/* 80179F78 00176ED8  7F E4 FB 78 */	mr r4, r31
/* 80179F7C 00176EDC  4B FD 82 1D */	bl kill__7BossMgrFP8Creature
/* 80179F80 00176EE0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80179F84 00176EE4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80179F88 00176EE8  38 21 00 18 */	addi r1, r1, 0x18
/* 80179F8C 00176EEC  7C 08 03 A6 */	mtlr r0
/* 80179F90 00176EF0  4E 80 00 20 */	blr 

.global exitCourse__8KingBackFv
exitCourse__8KingBackFv:
/* 80179F94 00176EF4  4E 80 00 20 */	blr 

.global update__8KingBackFv
update__8KingBackFv:
/* 80179F98 00176EF8  7C 08 02 A6 */	mflr r0
/* 80179F9C 00176EFC  90 01 00 04 */	stw r0, 4(r1)
/* 80179FA0 00176F00  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80179FA4 00176F04  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80179FA8 00176F08  7C 7F 1B 78 */	mr r31, r3
/* 80179FAC 00176F0C  81 9F 00 00 */	lwz r12, 0(r31)
/* 80179FB0 00176F10  81 8C 01 04 */	lwz r12, 0x104(r12)
/* 80179FB4 00176F14  7D 88 03 A6 */	mtlr r12
/* 80179FB8 00176F18  4E 80 00 21 */	blrl 
/* 80179FBC 00176F1C  7F E3 FB 78 */	mr r3, r31
/* 80179FC0 00176F20  81 9F 00 00 */	lwz r12, 0(r31)
/* 80179FC4 00176F24  81 8C 01 08 */	lwz r12, 0x108(r12)
/* 80179FC8 00176F28  7D 88 03 A6 */	mtlr r12
/* 80179FCC 00176F2C  4E 80 00 21 */	blrl 
/* 80179FD0 00176F30  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80179FD4 00176F34  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80179FD8 00176F38  38 21 00 18 */	addi r1, r1, 0x18
/* 80179FDC 00176F3C  7C 08 03 A6 */	mtlr r0
/* 80179FE0 00176F40  4E 80 00 20 */	blr 

.global refresh__8KingBackFR8Graphics
refresh__8KingBackFR8Graphics:
/* 80179FE4 00176F44  7C 08 02 A6 */	mflr r0
/* 80179FE8 00176F48  90 01 00 04 */	stw r0, 4(r1)
/* 80179FEC 00176F4C  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 80179FF0 00176F50  93 E1 00 54 */	stw r31, 0x54(r1)
/* 80179FF4 00176F54  3B E4 00 00 */	addi r31, r4, 0
/* 80179FF8 00176F58  93 C1 00 50 */	stw r30, 0x50(r1)
/* 80179FFC 00176F5C  3B C3 00 00 */	addi r30, r3, 0
/* 8017A000 00176F60  38 7E 02 28 */	addi r3, r30, 0x228
/* 8017A004 00176F64  38 9E 00 7C */	addi r4, r30, 0x7c
/* 8017A008 00176F68  38 BE 00 88 */	addi r5, r30, 0x88
/* 8017A00C 00176F6C  38 DE 00 94 */	addi r6, r30, 0x94
/* 8017A010 00176F70  4B EC 40 E5 */	bl makeSRT__8Matrix4fFR8Vector3fR8Vector3fR8Vector3f
/* 8017A014 00176F74  80 7F 02 E4 */	lwz r3, 0x2e4(r31)
/* 8017A018 00176F78  38 9E 02 28 */	addi r4, r30, 0x228
/* 8017A01C 00176F7C  38 A1 00 10 */	addi r5, r1, 0x10
/* 8017A020 00176F80  38 63 01 E0 */	addi r3, r3, 0x1e0
/* 8017A024 00176F84  4B EC 40 B1 */	bl multiplyTo__8Matrix4fFR8Matrix4fR8Matrix4f
/* 8017A028 00176F88  38 7E 03 3C */	addi r3, r30, 0x33c
/* 8017A02C 00176F8C  81 9E 03 6C */	lwz r12, 0x36c(r30)
/* 8017A030 00176F90  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8017A034 00176F94  7D 88 03 A6 */	mtlr r12
/* 8017A038 00176F98  4E 80 00 21 */	blrl 
/* 8017A03C 00176F9C  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8017A040 00176FA0  38 9F 00 00 */	addi r4, r31, 0
/* 8017A044 00176FA4  38 A1 00 10 */	addi r5, r1, 0x10
/* 8017A048 00176FA8  80 63 00 00 */	lwz r3, 0(r3)
/* 8017A04C 00176FAC  38 C0 00 00 */	li r6, 0
/* 8017A050 00176FB0  4B EB B2 C5 */	bl updateAnim__9BaseShapeFR8GraphicsR8Matrix4fPf
/* 8017A054 00176FB4  80 7E 02 20 */	lwz r3, 0x220(r30)
/* 8017A058 00176FB8  38 9F 00 00 */	addi r4, r31, 0
/* 8017A05C 00176FBC  38 A0 00 00 */	li r5, 0
/* 8017A060 00176FC0  4B F0 FA 8D */	bl updateInfo__8CollInfoFR8Graphicsb
/* 8017A064 00176FC4  38 7E 03 B8 */	addi r3, r30, 0x3b8
/* 8017A068 00176FC8  38 9F 00 00 */	addi r4, r31, 0
/* 8017A06C 00176FCC  4B F1 41 5D */	bl update__15CreaturePlatMgrFR8Graphics
/* 8017A070 00176FD0  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 8017A074 00176FD4  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 8017A078 00176FD8  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 8017A07C 00176FDC  38 21 00 58 */	addi r1, r1, 0x58
/* 8017A080 00176FE0  7C 08 03 A6 */	mtlr r0
/* 8017A084 00176FE4  4E 80 00 20 */	blr 

.global drawShape__8KingBackFR8Graphics
drawShape__8KingBackFR8Graphics:
/* 8017A088 00176FE8  7C 08 02 A6 */	mflr r0
/* 8017A08C 00176FEC  38 A0 00 00 */	li r5, 0
/* 8017A090 00176FF0  90 01 00 04 */	stw r0, 4(r1)
/* 8017A094 00176FF4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017A098 00176FF8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017A09C 00176FFC  3B E4 00 00 */	addi r31, r4, 0
/* 8017A0A0 00177000  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 8017A0A4 00177004  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017A0A8 00177008  3B C3 00 00 */	addi r30, r3, 0
/* 8017A0AC 0017700C  38 7F 00 00 */	addi r3, r31, 0
/* 8017A0B0 00177010  81 9F 03 B4 */	lwz r12, 0x3b4(r31)
/* 8017A0B4 00177014  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 8017A0B8 00177018  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8017A0BC 0017701C  7D 88 03 A6 */	mtlr r12
/* 8017A0C0 00177020  4E 80 00 21 */	blrl 
/* 8017A0C4 00177024  80 7E 03 90 */	lwz r3, 0x390(r30)
/* 8017A0C8 00177028  7F E4 FB 78 */	mr r4, r31
/* 8017A0CC 0017702C  80 BF 02 E4 */	lwz r5, 0x2e4(r31)
/* 8017A0D0 00177030  38 C0 00 00 */	li r6, 0
/* 8017A0D4 00177034  80 63 00 00 */	lwz r3, 0(r3)
/* 8017A0D8 00177038  4B EB 63 95 */	bl drawshape__9BaseShapeFR8GraphicsR6CameraP17ShapeDynMaterials
/* 8017A0DC 0017703C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017A0E0 00177040  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017A0E4 00177044  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017A0E8 00177048  38 21 00 18 */	addi r1, r1, 0x18
/* 8017A0EC 0017704C  7C 08 03 A6 */	mtlr r0
/* 8017A0F0 00177050  4E 80 00 20 */	blr 

.global doAI__8KingBackFv
doAI__8KingBackFv:
/* 8017A0F4 00177054  C0 03 03 00 */	lfs f0, 0x300(r3)
/* 8017A0F8 00177058  D0 03 00 94 */	stfs f0, 0x94(r3)
/* 8017A0FC 0017705C  C0 03 03 04 */	lfs f0, 0x304(r3)
/* 8017A100 00177060  D0 03 00 98 */	stfs f0, 0x98(r3)
/* 8017A104 00177064  C0 03 03 08 */	lfs f0, 0x308(r3)
/* 8017A108 00177068  D0 03 00 9C */	stfs f0, 0x9c(r3)
/* 8017A10C 0017706C  4E 80 00 20 */	blr 

.global doAnimation__8KingBackFv
doAnimation__8KingBackFv:
/* 8017A110 00177070  7C 08 02 A6 */	mflr r0
/* 8017A114 00177074  7C 64 1B 78 */	mr r4, r3
/* 8017A118 00177078  90 01 00 04 */	stw r0, 4(r1)
/* 8017A11C 0017707C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8017A120 00177080  80 03 03 90 */	lwz r0, 0x390(r3)
/* 8017A124 00177084  28 00 00 00 */	cmplwi r0, 0
/* 8017A128 00177088  41 82 00 1C */	beq lbl_8017A144
/* 8017A12C 0017708C  81 84 03 6C */	lwz r12, 0x36c(r4)
/* 8017A130 00177090  38 64 03 3C */	addi r3, r4, 0x33c
/* 8017A134 00177094  C0 24 02 D8 */	lfs f1, 0x2d8(r4)
/* 8017A138 00177098  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8017A13C 0017709C  7D 88 03 A6 */	mtlr r12
/* 8017A140 001770A0  4E 80 00 21 */	blrl 
lbl_8017A144:
/* 8017A144 001770A4  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8017A148 001770A8  38 21 00 08 */	addi r1, r1, 8
/* 8017A14C 001770AC  7C 08 03 A6 */	mtlr r0
/* 8017A150 001770B0  4E 80 00 20 */	blr 

.global read__12KingBackPropFR18RandomAccessStream
read__12KingBackPropFR18RandomAccessStream:
/* 8017A154 001770B4  7C 08 02 A6 */	mflr r0
/* 8017A158 001770B8  90 01 00 04 */	stw r0, 4(r1)
/* 8017A15C 001770BC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8017A160 001770C0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8017A164 001770C4  3B E4 00 00 */	addi r31, r4, 0
/* 8017A168 001770C8  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8017A16C 001770CC  3B C3 00 00 */	addi r30, r3, 0
/* 8017A170 001770D0  4B EE 4A 29 */	bl read__10ParametersFR18RandomAccessStream
/* 8017A174 001770D4  38 7E 00 58 */	addi r3, r30, 0x58
/* 8017A178 001770D8  38 9F 00 00 */	addi r4, r31, 0
/* 8017A17C 001770DC  4B EE 4A 1D */	bl read__10ParametersFR18RandomAccessStream
/* 8017A180 001770E0  38 7E 02 00 */	addi r3, r30, 0x200
/* 8017A184 001770E4  38 9F 00 00 */	addi r4, r31, 0
/* 8017A188 001770E8  4B EE 4A 11 */	bl read__10ParametersFR18RandomAccessStream
/* 8017A18C 001770EC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8017A190 001770F0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8017A194 001770F4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8017A198 001770F8  38 21 00 18 */	addi r1, r1, 0x18
/* 8017A19C 001770FC  7C 08 03 A6 */	mtlr r0
/* 8017A1A0 00177100  4E 80 00 20 */	blr 

.global "@492@read__12KingBackPropFR18RandomAccessStream"
"@492@read__12KingBackPropFR18RandomAccessStream":
/* 8017A1A4 00177104  38 63 FE 14 */	addi r3, r3, -492
/* 8017A1A8 00177108  4B FF FF AC */	b read__12KingBackPropFR18RandomAccessStream

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802D0E18:
	.asciz "KingBack.cpp"
.balign 4
lbl_802D0E28:
	.asciz "KingBack"
.balign 4
lbl_802D0E34:
	.asciz "CoreNode"
.balign 4
lbl_802D0E40:
	.asciz "EventTalker"
.balign 4
lbl_802D0E4C:
	.asciz "RefCountable"
.balign 4
lbl_802D0E5C:
	.asciz "Creature"
.balign 4
lbl_802D0E68:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D0E7C:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802D0E98:
	.4byte __RTTI__11EventTalker
	.4byte 0x00000008
	.4byte __RTTI__12RefCountable
	.4byte 0x00000000
	.4byte __RTTI__8Creature
	.4byte 0x00000000
	.4byte __RTTI__4Boss
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__8KingBack
__vt__8KingBack:
	.4byte __RTTI__8KingBack
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__8KingBackFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8CreatureFi
	.4byte getiMass__8KingBackFv
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
	.4byte update__8KingBackFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__8KingBackFR8Graphics
	.4byte refresh2d__4BossFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__8KingBackFv
	.4byte doAnimation__8KingBackFv
	.4byte doKill__8KingBackFv
	.4byte exitCourse__8KingBackFv
	.4byte isBossBgm__4BossFv
	.4byte attackDefaultPortion__4BossFv
	.4byte bombDamageCounter__4BossFP8CollPart
	.4byte drawShape__8KingBackFR8Graphics
.balign 4
lbl_802D0FE0:
	.asciz "KingBackProp"
.balign 4
lbl_802D0FF0:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
.balign 4
lbl_802D0FFC:
	.asciz "CreatureProp"
.balign 4
lbl_802D100C:
	.asciz "BossProp"
.balign 4
lbl_802D1018:
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte 0
lbl_802D1024:
	.4byte __RTTI__5ANode
	.4byte 0x1ec
	.4byte __RTTI__8CoreNode
	.4byte 0x1ec
	.4byte __RTTI__12CreatureProp
	.4byte 0
	.4byte __RTTI__8BossProp
	.4byte 0
	.4byte 0
.global __vt__12KingBackProp
__vt__12KingBackProp:
	.4byte __RTTI__12KingBackProp
	.4byte 0
	.4byte read__12KingBackPropFR18RandomAccessStream
	.4byte __RTTI__12KingBackProp
	.4byte 0xfffffe14
	.4byte getAgeNodeType__5ANodeFv
	.4byte "@492@read__12KingBackPropFR18RandomAccessStream"
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__11EventTalker:
	.4byte lbl_802D0E40
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802D0E4C
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802D0E5C
	.4byte lbl_802D0E68
.balign 4
lbl_803E53B8:
	.asciz "Boss"
.balign 4
__RTTI__4Boss:
	.4byte lbl_803E53B8
	.4byte lbl_802D0E7C
__RTTI__8KingBack:
	.4byte lbl_802D0E28
	.4byte lbl_802D0E98
.balign 4
lbl_803E53D0:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E53D0
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802D0E34
	.4byte lbl_802D0FF0
__RTTI__12CreatureProp:
	.4byte lbl_802D0FFC
	.4byte 0
__RTTI__8BossProp:
	.4byte lbl_802D100C
	.4byte lbl_802D1018
__RTTI__12KingBackProp:
	.4byte lbl_802D0FE0
	.4byte lbl_802D1024

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EB038:
	.float 1.0
lbl_803EB03C:
	.float 0.0
lbl_803EB040:
	.4byte 0x38D1B717
lbl_803EB044:
	.float 20.0
