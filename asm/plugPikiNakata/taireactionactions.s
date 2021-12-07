.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global act__13TaiDeadActionFR4Teki
act__13TaiDeadActionFR4Teki:
/* 8013EBD8 0013BB38  C0 24 00 58 */	lfs f1, 0x58(r4)
/* 8013EBDC 0013BB3C  C0 02 A6 20 */	lfs f0, lbl_803EA820@sda21(r2)
/* 8013EBE0 0013BB40  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8013EBE4 0013BB44  4C 40 13 82 */	cror 2, 0, 2
/* 8013EBE8 0013BB48  7C 00 00 26 */	mfcr r0
/* 8013EBEC 0013BB4C  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 8013EBF0 0013BB50  4E 80 00 20 */	blr 

.global start__17TaiLifeZeroActionFR4Teki
start__17TaiLifeZeroActionFR4Teki:
/* 8013EBF4 0013BB54  C0 02 A6 20 */	lfs f0, lbl_803EA820@sda21(r2)
/* 8013EBF8 0013BB58  D0 04 00 58 */	stfs f0, 0x58(r4)
/* 8013EBFC 0013BB5C  4E 80 00 20 */	blr 

.global start__19TaiLifeDamageActionFR4Teki
start__19TaiLifeDamageActionFR4Teki:
/* 8013EC00 0013BB60  C0 24 00 58 */	lfs f1, 0x58(r4)
/* 8013EC04 0013BB64  C0 03 00 08 */	lfs f0, 8(r3)
/* 8013EC08 0013BB68  EC 01 00 28 */	fsubs f0, f1, f0
/* 8013EC0C 0013BB6C  D0 04 00 58 */	stfs f0, 0x58(r4)
/* 8013EC10 0013BB70  4E 80 00 20 */	blr 

.global start__12TaiDyeActionFR4Teki
start__12TaiDyeActionFR4Teki:
/* 8013EC14 0013BB74  7C 08 02 A6 */	mflr r0
/* 8013EC18 0013BB78  7C 83 23 78 */	mr r3, r4
/* 8013EC1C 0013BB7C  90 01 00 04 */	stw r0, 4(r1)
/* 8013EC20 0013BB80  94 21 FF F8 */	stwu r1, -8(r1)
/* 8013EC24 0013BB84  81 84 00 00 */	lwz r12, 0(r4)
/* 8013EC28 0013BB88  81 8C 01 78 */	lwz r12, 0x178(r12)
/* 8013EC2C 0013BB8C  7D 88 03 A6 */	mtlr r12
/* 8013EC30 0013BB90  4E 80 00 21 */	blrl 
/* 8013EC34 0013BB94  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013EC38 0013BB98  38 21 00 08 */	addi r1, r1, 8
/* 8013EC3C 0013BB9C  7C 08 03 A6 */	mtlr r0
/* 8013EC40 0013BBA0  4E 80 00 20 */	blr 

.global start__19TaiStartDyingActionFR4Teki
start__19TaiStartDyingActionFR4Teki:
/* 8013EC44 0013BBA4  7C 08 02 A6 */	mflr r0
/* 8013EC48 0013BBA8  90 01 00 04 */	stw r0, 4(r1)
/* 8013EC4C 0013BBAC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8013EC50 0013BBB0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8013EC54 0013BBB4  3B E4 00 00 */	addi r31, r4, 0
/* 8013EC58 0013BBB8  38 7F 00 00 */	addi r3, r31, 0
/* 8013EC5C 0013BBBC  48 00 72 0D */	bl spawnItems__5BTekiFv
/* 8013EC60 0013BBC0  7F E3 FB 78 */	mr r3, r31
/* 8013EC64 0013BBC4  48 00 70 01 */	bl createDeadEffect__5BTekiFv
/* 8013EC68 0013BBC8  7F E3 FB 78 */	mr r3, r31
/* 8013EC6C 0013BBCC  48 00 6F D5 */	bl releasePlatCollisions__5BTekiFv
/* 8013EC70 0013BBD0  7F E3 FB 78 */	mr r3, r31
/* 8013EC74 0013BBD4  80 8D F6 30 */	lwz r4, TEKI_OPTION_SHADOW_VISIBLE__5BTeki@sda21(r13)
/* 8013EC78 0013BBD8  81 9F 00 00 */	lwz r12, 0(r31)
/* 8013EC7C 0013BBDC  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 8013EC80 0013BBE0  7D 88 03 A6 */	mtlr r12
/* 8013EC84 0013BBE4  4E 80 00 21 */	blrl 
/* 8013EC88 0013BBE8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8013EC8C 0013BBEC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8013EC90 0013BBF0  38 21 00 18 */	addi r1, r1, 0x18
/* 8013EC94 0013BBF4  7C 08 03 A6 */	mtlr r0
/* 8013EC98 0013BBF8  4E 80 00 20 */	blr 

.global start__19TaiSpawnItemsActionFR4Teki
start__19TaiSpawnItemsActionFR4Teki:
/* 8013EC9C 0013BBFC  7C 08 02 A6 */	mflr r0
/* 8013ECA0 0013BC00  7C 83 23 78 */	mr r3, r4
/* 8013ECA4 0013BC04  90 01 00 04 */	stw r0, 4(r1)
/* 8013ECA8 0013BC08  94 21 FF F8 */	stwu r1, -8(r1)
/* 8013ECAC 0013BC0C  48 00 71 BD */	bl spawnItems__5BTekiFv
/* 8013ECB0 0013BC10  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013ECB4 0013BC14  38 21 00 08 */	addi r1, r1, 8
/* 8013ECB8 0013BC18  7C 08 03 A6 */	mtlr r0
/* 8013ECBC 0013BC1C  4E 80 00 20 */	blr 

.global start__25TaiCreateDeadEffectActionFR4Teki
start__25TaiCreateDeadEffectActionFR4Teki:
/* 8013ECC0 0013BC20  7C 08 02 A6 */	mflr r0
/* 8013ECC4 0013BC24  7C 83 23 78 */	mr r3, r4
/* 8013ECC8 0013BC28  90 01 00 04 */	stw r0, 4(r1)
/* 8013ECCC 0013BC2C  94 21 FF F8 */	stwu r1, -8(r1)
/* 8013ECD0 0013BC30  48 00 6F 95 */	bl createDeadEffect__5BTekiFv
/* 8013ECD4 0013BC34  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013ECD8 0013BC38  38 21 00 08 */	addi r1, r1, 8
/* 8013ECDC 0013BC3C  7C 08 03 A6 */	mtlr r0
/* 8013ECE0 0013BC40  4E 80 00 20 */	blr 

.global start__14TaiDyingActionFR4Teki
start__14TaiDyingActionFR4Teki:
/* 8013ECE4 0013BC44  7C 08 02 A6 */	mflr r0
/* 8013ECE8 0013BC48  90 01 00 04 */	stw r0, 4(r1)
/* 8013ECEC 0013BC4C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8013ECF0 0013BC50  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8013ECF4 0013BC54  7C 9F 23 78 */	mr r31, r4
/* 8013ECF8 0013BC58  4B FF 53 21 */	bl start__15TaiMotionActionFR4Teki
/* 8013ECFC 0013BC5C  7F E3 FB 78 */	mr r3, r31
/* 8013ED00 0013BC60  80 8D F6 3C */	lwz r4, TEKI_OPTION_ALIVE__5BTeki@sda21(r13)
/* 8013ED04 0013BC64  81 9F 00 00 */	lwz r12, 0(r31)
/* 8013ED08 0013BC68  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 8013ED0C 0013BC6C  7D 88 03 A6 */	mtlr r12
/* 8013ED10 0013BC70  4E 80 00 21 */	blrl 
/* 8013ED14 0013BC74  C0 02 A6 20 */	lfs f0, lbl_803EA820@sda21(r2)
/* 8013ED18 0013BC78  D0 1F 00 58 */	stfs f0, 0x58(r31)
/* 8013ED1C 0013BC7C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8013ED20 0013BC80  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8013ED24 0013BC84  38 21 00 18 */	addi r1, r1, 0x18
/* 8013ED28 0013BC88  7C 08 03 A6 */	mtlr r0
/* 8013ED2C 0013BC8C  4E 80 00 20 */	blr 

.global act__14TaiDyingActionFR4Teki
act__14TaiDyingActionFR4Teki:
/* 8013ED30 0013BC90  7C 08 02 A6 */	mflr r0
/* 8013ED34 0013BC94  90 01 00 04 */	stw r0, 4(r1)
/* 8013ED38 0013BC98  94 21 FF F8 */	stwu r1, -8(r1)
/* 8013ED3C 0013BC9C  80 64 02 CC */	lwz r3, 0x2cc(r4)
/* 8013ED40 0013BCA0  80 03 00 38 */	lwz r0, 0x38(r3)
/* 8013ED44 0013BCA4  2C 00 00 00 */	cmpwi r0, 0
/* 8013ED48 0013BCA8  40 80 00 20 */	bge lbl_8013ED68
/* 8013ED4C 0013BCAC  7C 83 23 78 */	mr r3, r4
/* 8013ED50 0013BCB0  81 84 00 00 */	lwz r12, 0(r4)
/* 8013ED54 0013BCB4  81 8C 01 78 */	lwz r12, 0x178(r12)
/* 8013ED58 0013BCB8  7D 88 03 A6 */	mtlr r12
/* 8013ED5C 0013BCBC  4E 80 00 21 */	blrl 
/* 8013ED60 0013BCC0  38 60 00 01 */	li r3, 1
/* 8013ED64 0013BCC4  48 00 00 08 */	b lbl_8013ED6C
lbl_8013ED68:
/* 8013ED68 0013BCC8  38 60 00 00 */	li r3, 0
lbl_8013ED6C:
/* 8013ED6C 0013BCCC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013ED70 0013BCD0  38 21 00 08 */	addi r1, r1, 8
/* 8013ED74 0013BCD4  7C 08 03 A6 */	mtlr r0
/* 8013ED78 0013BCD8  4E 80 00 20 */	blr 

.global start__25TaiDamageCountResetActionFR4Teki
start__25TaiDamageCountResetActionFR4Teki:
/* 8013ED7C 0013BCDC  C0 02 A6 20 */	lfs f0, lbl_803EA820@sda21(r2)
/* 8013ED80 0013BCE0  D0 04 03 40 */	stfs f0, 0x340(r4)
/* 8013ED84 0013BCE4  4E 80 00 20 */	blr 

.global act__20TaiDamageCountActionFR4Teki
act__20TaiDamageCountActionFR4Teki:
/* 8013ED88 0013BCE8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8013ED8C 0013BCEC  3C 00 43 30 */	lis r0, 0x4330
/* 8013ED90 0013BCF0  80 63 00 08 */	lwz r3, 8(r3)
/* 8013ED94 0013BCF4  C8 22 A6 28 */	lfd f1, lbl_803EA828@sda21(r2)
/* 8013ED98 0013BCF8  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8013ED9C 0013BCFC  C0 44 03 40 */	lfs f2, 0x340(r4)
/* 8013EDA0 0013BD00  90 61 00 14 */	stw r3, 0x14(r1)
/* 8013EDA4 0013BD04  90 01 00 10 */	stw r0, 0x10(r1)
/* 8013EDA8 0013BD08  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8013EDAC 0013BD0C  EC 00 08 28 */	fsubs f0, f0, f1
/* 8013EDB0 0013BD10  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8013EDB4 0013BD14  4C 41 13 82 */	cror 2, 1, 2
/* 8013EDB8 0013BD18  7C 00 00 26 */	mfcr r0
/* 8013EDBC 0013BD1C  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 8013EDC0 0013BD20  38 21 00 18 */	addi r1, r1, 0x18
/* 8013EDC4 0013BD24  4E 80 00 20 */	blr 

.global act__20TaiDamageScaleActionFR4Teki
act__20TaiDamageScaleActionFR4Teki:
/* 8013EDC8 0013BD28  C0 03 00 08 */	lfs f0, 8(r3)
/* 8013EDCC 0013BD2C  38 60 00 00 */	li r3, 0
/* 8013EDD0 0013BD30  C0 24 03 3C */	lfs f1, 0x33c(r4)
/* 8013EDD4 0013BD34  EC 01 00 32 */	fmuls f0, f1, f0
/* 8013EDD8 0013BD38  D0 04 03 3C */	stfs f0, 0x33c(r4)
/* 8013EDDC 0013BD3C  4E 80 00 20 */	blr 

.global act__15TaiDamageActionFR4Teki
act__15TaiDamageActionFR4Teki:
/* 8013EDE0 0013BD40  C0 24 03 3C */	lfs f1, 0x33c(r4)
/* 8013EDE4 0013BD44  C0 02 A6 20 */	lfs f0, lbl_803EA820@sda21(r2)
/* 8013EDE8 0013BD48  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8013EDEC 0013BD4C  4C 40 13 82 */	cror 2, 0, 2
/* 8013EDF0 0013BD50  40 82 00 0C */	bne lbl_8013EDFC
/* 8013EDF4 0013BD54  38 60 00 00 */	li r3, 0
/* 8013EDF8 0013BD58  4E 80 00 20 */	blr 
lbl_8013EDFC:
/* 8013EDFC 0013BD5C  38 60 00 01 */	li r3, 1
/* 8013EE00 0013BD60  4E 80 00 20 */	blr 

.global act__27TaiSimultaneousDamageActionFR4Teki
act__27TaiSimultaneousDamageActionFR4Teki:
/* 8013EE04 0013BD64  7C 08 02 A6 */	mflr r0
/* 8013EE08 0013BD68  90 01 00 04 */	stw r0, 4(r1)
/* 8013EE0C 0013BD6C  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8013EE10 0013BD70  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 8013EE14 0013BD74  7C 9F 23 78 */	mr r31, r4
/* 8013EE18 0013BD78  C0 02 A6 20 */	lfs f0, lbl_803EA820@sda21(r2)
/* 8013EE1C 0013BD7C  C0 24 03 3C */	lfs f1, 0x33c(r4)
/* 8013EE20 0013BD80  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8013EE24 0013BD84  4C 40 13 82 */	cror 2, 0, 2
/* 8013EE28 0013BD88  40 82 00 0C */	bne lbl_8013EE34
/* 8013EE2C 0013BD8C  38 60 00 00 */	li r3, 0
/* 8013EE30 0013BD90  48 00 00 48 */	b lbl_8013EE78
lbl_8013EE34:
/* 8013EE34 0013BD94  7F E3 FB 78 */	mr r3, r31
/* 8013EE38 0013BD98  81 9F 00 00 */	lwz r12, 0(r31)
/* 8013EE3C 0013BD9C  81 8C 01 8C */	lwz r12, 0x18c(r12)
/* 8013EE40 0013BDA0  7D 88 03 A6 */	mtlr r12
/* 8013EE44 0013BDA4  4E 80 00 21 */	blrl 
/* 8013EE48 0013BDA8  80 9F 02 C4 */	lwz r4, 0x2c4(r31)
/* 8013EE4C 0013BDAC  7F E3 FB 78 */	mr r3, r31
/* 8013EE50 0013BDB0  81 9F 00 00 */	lwz r12, 0(r31)
/* 8013EE54 0013BDB4  80 84 00 84 */	lwz r4, 0x84(r4)
/* 8013EE58 0013BDB8  81 8C 01 90 */	lwz r12, 0x190(r12)
/* 8013EE5C 0013BDBC  80 84 00 04 */	lwz r4, 4(r4)
/* 8013EE60 0013BDC0  7D 88 03 A6 */	mtlr r12
/* 8013EE64 0013BDC4  80 84 00 00 */	lwz r4, 0(r4)
/* 8013EE68 0013BDC8  C0 44 00 7C */	lfs f2, 0x7c(r4)
/* 8013EE6C 0013BDCC  C0 24 00 78 */	lfs f1, 0x78(r4)
/* 8013EE70 0013BDD0  4E 80 00 21 */	blrl 
/* 8013EE74 0013BDD4  38 60 00 01 */	li r3, 1
lbl_8013EE78:
/* 8013EE78 0013BDD8  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8013EE7C 0013BDDC  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 8013EE80 0013BDE0  38 21 00 60 */	addi r1, r1, 0x60
/* 8013EE84 0013BDE4  7C 08 03 A6 */	mtlr r0
/* 8013EE88 0013BDE8  4E 80 00 20 */	blr 

.global act__40TaiCounterattackSimultaneousDamageActionFR4Teki
act__40TaiCounterattackSimultaneousDamageActionFR4Teki:
/* 8013EE8C 0013BDEC  7C 08 02 A6 */	mflr r0
/* 8013EE90 0013BDF0  90 01 00 04 */	stw r0, 4(r1)
/* 8013EE94 0013BDF4  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8013EE98 0013BDF8  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 8013EE9C 0013BDFC  93 C1 00 58 */	stw r30, 0x58(r1)
/* 8013EEA0 0013BE00  7C 9E 23 78 */	mr r30, r4
/* 8013EEA4 0013BE04  C0 02 A6 20 */	lfs f0, lbl_803EA820@sda21(r2)
/* 8013EEA8 0013BE08  C0 24 03 3C */	lfs f1, 0x33c(r4)
/* 8013EEAC 0013BE0C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8013EEB0 0013BE10  4C 40 13 82 */	cror 2, 0, 2
/* 8013EEB4 0013BE14  40 82 00 0C */	bne lbl_8013EEC0
/* 8013EEB8 0013BE18  38 60 00 00 */	li r3, 0
/* 8013EEBC 0013BE1C  48 00 00 90 */	b lbl_8013EF4C
lbl_8013EEC0:
/* 8013EEC0 0013BE20  83 FE 04 1C */	lwz r31, 0x41c(r30)
/* 8013EEC4 0013BE24  38 7E 00 00 */	addi r3, r30, 0
/* 8013EEC8 0013BE28  38 9F 00 00 */	addi r4, r31, 0
/* 8013EECC 0013BE2C  48 00 7B FD */	bl nearestAngleTarget__5BTekiFP8Creature
/* 8013EED0 0013BE30  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8013EED4 0013BE34  41 82 00 34 */	beq lbl_8013EF08
/* 8013EED8 0013BE38  80 7E 04 18 */	lwz r3, 0x418(r30)
/* 8013EEDC 0013BE3C  28 03 00 00 */	cmplwi r3, 0
/* 8013EEE0 0013BE40  41 82 00 14 */	beq lbl_8013EEF4
/* 8013EEE4 0013BE44  41 82 00 10 */	beq lbl_8013EEF4
/* 8013EEE8 0013BE48  4B FA 54 85 */	bl subCnt__12RefCountableFv
/* 8013EEEC 0013BE4C  38 00 00 00 */	li r0, 0
/* 8013EEF0 0013BE50  90 1E 04 18 */	stw r0, 0x418(r30)
lbl_8013EEF4:
/* 8013EEF4 0013BE54  93 FE 04 18 */	stw r31, 0x418(r30)
/* 8013EEF8 0013BE58  80 7E 04 18 */	lwz r3, 0x418(r30)
/* 8013EEFC 0013BE5C  28 03 00 00 */	cmplwi r3, 0
/* 8013EF00 0013BE60  41 82 00 08 */	beq lbl_8013EF08
/* 8013EF04 0013BE64  4B FA 54 59 */	bl addCnt__12RefCountableFv
lbl_8013EF08:
/* 8013EF08 0013BE68  7F C3 F3 78 */	mr r3, r30
/* 8013EF0C 0013BE6C  81 9E 00 00 */	lwz r12, 0(r30)
/* 8013EF10 0013BE70  81 8C 01 8C */	lwz r12, 0x18c(r12)
/* 8013EF14 0013BE74  7D 88 03 A6 */	mtlr r12
/* 8013EF18 0013BE78  4E 80 00 21 */	blrl 
/* 8013EF1C 0013BE7C  80 9E 02 C4 */	lwz r4, 0x2c4(r30)
/* 8013EF20 0013BE80  7F C3 F3 78 */	mr r3, r30
/* 8013EF24 0013BE84  81 9E 00 00 */	lwz r12, 0(r30)
/* 8013EF28 0013BE88  80 84 00 84 */	lwz r4, 0x84(r4)
/* 8013EF2C 0013BE8C  81 8C 01 90 */	lwz r12, 0x190(r12)
/* 8013EF30 0013BE90  80 84 00 04 */	lwz r4, 4(r4)
/* 8013EF34 0013BE94  7D 88 03 A6 */	mtlr r12
/* 8013EF38 0013BE98  80 84 00 00 */	lwz r4, 0(r4)
/* 8013EF3C 0013BE9C  C0 44 00 7C */	lfs f2, 0x7c(r4)
/* 8013EF40 0013BEA0  C0 24 00 78 */	lfs f1, 0x78(r4)
/* 8013EF44 0013BEA4  4E 80 00 21 */	blrl 
/* 8013EF48 0013BEA8  38 60 00 01 */	li r3, 1
lbl_8013EF4C:
/* 8013EF4C 0013BEAC  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8013EF50 0013BEB0  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 8013EF54 0013BEB4  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 8013EF58 0013BEB8  38 21 00 60 */	addi r1, r1, 0x60
/* 8013EF5C 0013BEBC  7C 08 03 A6 */	mtlr r0
/* 8013EF60 0013BEC0  4E 80 00 20 */	blr 

.global start__17TaiDamagingActionFR4Teki
start__17TaiDamagingActionFR4Teki:
/* 8013EF64 0013BEC4  7C 08 02 A6 */	mflr r0
/* 8013EF68 0013BEC8  90 01 00 04 */	stw r0, 4(r1)
/* 8013EF6C 0013BECC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8013EF70 0013BED0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8013EF74 0013BED4  7C 9F 23 78 */	mr r31, r4
/* 8013EF78 0013BED8  4B FF 50 A1 */	bl start__15TaiMotionActionFR4Teki
/* 8013EF7C 0013BEDC  7F E3 FB 78 */	mr r3, r31
/* 8013EF80 0013BEE0  81 9F 00 00 */	lwz r12, 0(r31)
/* 8013EF84 0013BEE4  81 8C 01 8C */	lwz r12, 0x18c(r12)
/* 8013EF88 0013BEE8  7D 88 03 A6 */	mtlr r12
/* 8013EF8C 0013BEEC  4E 80 00 21 */	blrl 
/* 8013EF90 0013BEF0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8013EF94 0013BEF4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8013EF98 0013BEF8  38 21 00 18 */	addi r1, r1, 0x18
/* 8013EF9C 0013BEFC  7C 08 03 A6 */	mtlr r0
/* 8013EFA0 0013BF00  4E 80 00 20 */	blr 

.global act__17TaiDamagingActionFR4Teki
act__17TaiDamagingActionFR4Teki:
/* 8013EFA4 0013BF04  80 64 02 CC */	lwz r3, 0x2cc(r4)
/* 8013EFA8 0013BF08  80 03 00 38 */	lwz r0, 0x38(r3)
/* 8013EFAC 0013BF0C  2C 00 00 00 */	cmpwi r0, 0
/* 8013EFB0 0013BF10  40 80 00 0C */	bge lbl_8013EFBC
/* 8013EFB4 0013BF14  38 60 00 01 */	li r3, 1
/* 8013EFB8 0013BF18  4E 80 00 20 */	blr 
lbl_8013EFBC:
/* 8013EFBC 0013BF1C  38 60 00 00 */	li r3, 0
/* 8013EFC0 0013BF20  4E 80 00 20 */	blr 

.global act__31TaiTargetNearestAssailantActionFR4Teki
act__31TaiTargetNearestAssailantActionFR4Teki:
/* 8013EFC4 0013BF24  7C 08 02 A6 */	mflr r0
/* 8013EFC8 0013BF28  90 01 00 04 */	stw r0, 4(r1)
/* 8013EFCC 0013BF2C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8013EFD0 0013BF30  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8013EFD4 0013BF34  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8013EFD8 0013BF38  7C 9E 23 78 */	mr r30, r4
/* 8013EFDC 0013BF3C  C0 02 A6 20 */	lfs f0, lbl_803EA820@sda21(r2)
/* 8013EFE0 0013BF40  C0 24 03 3C */	lfs f1, 0x33c(r4)
/* 8013EFE4 0013BF44  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8013EFE8 0013BF48  4C 40 13 82 */	cror 2, 0, 2
/* 8013EFEC 0013BF4C  40 82 00 0C */	bne lbl_8013EFF8
/* 8013EFF0 0013BF50  38 60 00 00 */	li r3, 0
/* 8013EFF4 0013BF54  48 00 00 50 */	b lbl_8013F044
lbl_8013EFF8:
/* 8013EFF8 0013BF58  83 FE 04 1C */	lwz r31, 0x41c(r30)
/* 8013EFFC 0013BF5C  38 7E 00 00 */	addi r3, r30, 0
/* 8013F000 0013BF60  38 9F 00 00 */	addi r4, r31, 0
/* 8013F004 0013BF64  48 00 7A C5 */	bl nearestAngleTarget__5BTekiFP8Creature
/* 8013F008 0013BF68  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8013F00C 0013BF6C  41 82 00 34 */	beq lbl_8013F040
/* 8013F010 0013BF70  80 7E 04 18 */	lwz r3, 0x418(r30)
/* 8013F014 0013BF74  28 03 00 00 */	cmplwi r3, 0
/* 8013F018 0013BF78  41 82 00 14 */	beq lbl_8013F02C
/* 8013F01C 0013BF7C  41 82 00 10 */	beq lbl_8013F02C
/* 8013F020 0013BF80  4B FA 53 4D */	bl subCnt__12RefCountableFv
/* 8013F024 0013BF84  38 00 00 00 */	li r0, 0
/* 8013F028 0013BF88  90 1E 04 18 */	stw r0, 0x418(r30)
lbl_8013F02C:
/* 8013F02C 0013BF8C  93 FE 04 18 */	stw r31, 0x418(r30)
/* 8013F030 0013BF90  80 7E 04 18 */	lwz r3, 0x418(r30)
/* 8013F034 0013BF94  28 03 00 00 */	cmplwi r3, 0
/* 8013F038 0013BF98  41 82 00 08 */	beq lbl_8013F040
/* 8013F03C 0013BF9C  4B FA 53 21 */	bl addCnt__12RefCountableFv
lbl_8013F040:
/* 8013F040 0013BFA0  38 60 00 01 */	li r3, 1
lbl_8013F044:
/* 8013F044 0013BFA4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8013F048 0013BFA8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8013F04C 0013BFAC  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8013F050 0013BFB0  38 21 00 18 */	addi r1, r1, 0x18
/* 8013F054 0013BFB4  7C 08 03 A6 */	mtlr r0
/* 8013F058 0013BFB8  4E 80 00 20 */	blr 

.global actByEvent__31TaiTargetNearestCollisionActionFR9TekiEvent
actByEvent__31TaiTargetNearestCollisionActionFR9TekiEvent:
/* 8013F05C 0013BFBC  7C 08 02 A6 */	mflr r0
/* 8013F060 0013BFC0  90 01 00 04 */	stw r0, 4(r1)
/* 8013F064 0013BFC4  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8013F068 0013BFC8  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 8013F06C 0013BFCC  93 C1 00 58 */	stw r30, 0x58(r1)
/* 8013F070 0013BFD0  93 A1 00 54 */	stw r29, 0x54(r1)
/* 8013F074 0013BFD4  93 81 00 50 */	stw r28, 0x50(r1)
/* 8013F078 0013BFD8  80 04 00 00 */	lwz r0, 0(r4)
/* 8013F07C 0013BFDC  83 E4 00 04 */	lwz r31, 4(r4)
/* 8013F080 0013BFE0  2C 00 00 01 */	cmpwi r0, 1
/* 8013F084 0013BFE4  41 82 00 0C */	beq lbl_8013F090
/* 8013F088 0013BFE8  38 60 00 00 */	li r3, 0
/* 8013F08C 0013BFEC  48 00 00 EC */	b lbl_8013F178
lbl_8013F090:
/* 8013F090 0013BFF0  3C 60 80 2B */	lis r3, __vt__9Condition@ha
/* 8013F094 0013BFF4  83 C4 00 08 */	lwz r30, 8(r4)
/* 8013F098 0013BFF8  38 E3 F0 98 */	addi r7, r3, __vt__9Condition@l
/* 8013F09C 0013BFFC  3C 60 80 2C */	lis r3, __vt__13TekiCondition@ha
/* 8013F0A0 0013C000  90 E1 00 38 */	stw r7, 0x38(r1)
/* 8013F0A4 0013C004  38 C3 69 64 */	addi r6, r3, __vt__13TekiCondition@l
/* 8013F0A8 0013C008  3C 60 80 2D */	lis r3, __vt__21TekiNaviPikiCondition@ha
/* 8013F0AC 0013C00C  90 C1 00 38 */	stw r6, 0x38(r1)
/* 8013F0B0 0013C010  38 03 D8 10 */	addi r0, r3, __vt__21TekiNaviPikiCondition@l
/* 8013F0B4 0013C014  90 01 00 38 */	stw r0, 0x38(r1)
/* 8013F0B8 0013C018  3C A0 80 2D */	lis r5, __vt__24TekiRecognitionCondition@ha
/* 8013F0BC 0013C01C  38 05 D6 A4 */	addi r0, r5, __vt__24TekiRecognitionCondition@l
/* 8013F0C0 0013C020  81 04 00 04 */	lwz r8, 4(r4)
/* 8013F0C4 0013C024  38 61 00 3C */	addi r3, r1, 0x3c
/* 8013F0C8 0013C028  38 9E 00 00 */	addi r4, r30, 0
/* 8013F0CC 0013C02C  90 E1 00 3C */	stw r7, 0x3c(r1)
/* 8013F0D0 0013C030  3B 81 00 38 */	addi r28, r1, 0x38
/* 8013F0D4 0013C034  3B A0 00 00 */	li r29, 0
/* 8013F0D8 0013C038  90 C1 00 3C */	stw r6, 0x3c(r1)
/* 8013F0DC 0013C03C  90 01 00 3C */	stw r0, 0x3c(r1)
/* 8013F0E0 0013C040  91 01 00 40 */	stw r8, 0x40(r1)
/* 8013F0E4 0013C044  81 81 00 3C */	lwz r12, 0x3c(r1)
/* 8013F0E8 0013C048  81 8C 00 08 */	lwz r12, 8(r12)
/* 8013F0EC 0013C04C  7D 88 03 A6 */	mtlr r12
/* 8013F0F0 0013C050  4E 80 00 21 */	blrl 
/* 8013F0F4 0013C054  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8013F0F8 0013C058  41 82 00 28 */	beq lbl_8013F120
/* 8013F0FC 0013C05C  7F 83 E3 78 */	mr r3, r28
/* 8013F100 0013C060  81 9C 00 00 */	lwz r12, 0(r28)
/* 8013F104 0013C064  7F C4 F3 78 */	mr r4, r30
/* 8013F108 0013C068  81 8C 00 08 */	lwz r12, 8(r12)
/* 8013F10C 0013C06C  7D 88 03 A6 */	mtlr r12
/* 8013F110 0013C070  4E 80 00 21 */	blrl 
/* 8013F114 0013C074  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8013F118 0013C078  41 82 00 08 */	beq lbl_8013F120
/* 8013F11C 0013C07C  3B A0 00 01 */	li r29, 1
lbl_8013F120:
/* 8013F120 0013C080  57 A0 06 3F */	clrlwi. r0, r29, 0x18
/* 8013F124 0013C084  40 82 00 0C */	bne lbl_8013F130
/* 8013F128 0013C088  38 60 00 00 */	li r3, 0
/* 8013F12C 0013C08C  48 00 00 4C */	b lbl_8013F178
lbl_8013F130:
/* 8013F130 0013C090  38 7F 00 00 */	addi r3, r31, 0
/* 8013F134 0013C094  38 9E 00 00 */	addi r4, r30, 0
/* 8013F138 0013C098  48 00 79 91 */	bl nearestAngleTarget__5BTekiFP8Creature
/* 8013F13C 0013C09C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8013F140 0013C0A0  41 82 00 34 */	beq lbl_8013F174
/* 8013F144 0013C0A4  80 7F 04 18 */	lwz r3, 0x418(r31)
/* 8013F148 0013C0A8  28 03 00 00 */	cmplwi r3, 0
/* 8013F14C 0013C0AC  41 82 00 14 */	beq lbl_8013F160
/* 8013F150 0013C0B0  41 82 00 10 */	beq lbl_8013F160
/* 8013F154 0013C0B4  4B FA 52 19 */	bl subCnt__12RefCountableFv
/* 8013F158 0013C0B8  38 00 00 00 */	li r0, 0
/* 8013F15C 0013C0BC  90 1F 04 18 */	stw r0, 0x418(r31)
lbl_8013F160:
/* 8013F160 0013C0C0  93 DF 04 18 */	stw r30, 0x418(r31)
/* 8013F164 0013C0C4  80 7F 04 18 */	lwz r3, 0x418(r31)
/* 8013F168 0013C0C8  28 03 00 00 */	cmplwi r3, 0
/* 8013F16C 0013C0CC  41 82 00 08 */	beq lbl_8013F174
/* 8013F170 0013C0D0  4B FA 51 ED */	bl addCnt__12RefCountableFv
lbl_8013F174:
/* 8013F174 0013C0D4  38 60 00 01 */	li r3, 1
lbl_8013F178:
/* 8013F178 0013C0D8  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8013F17C 0013C0DC  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 8013F180 0013C0E0  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 8013F184 0013C0E4  83 A1 00 54 */	lwz r29, 0x54(r1)
/* 8013F188 0013C0E8  83 81 00 50 */	lwz r28, 0x50(r1)
/* 8013F18C 0013C0EC  38 21 00 60 */	addi r1, r1, 0x60
/* 8013F190 0013C0F0  7C 08 03 A6 */	mtlr r0
/* 8013F194 0013C0F4  4E 80 00 20 */	blr 

.global act__16TaiStickedActionFR4Teki
act__16TaiStickedActionFR4Teki:
/* 8013F198 0013C0F8  7C 08 02 A6 */	mflr r0
/* 8013F19C 0013C0FC  90 01 00 04 */	stw r0, 4(r1)
/* 8013F1A0 0013C100  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8013F1A4 0013C104  38 61 00 18 */	addi r3, r1, 0x18
/* 8013F1A8 0013C108  4B F5 1A DD */	bl __ct__8StickersFP8Creature
/* 8013F1AC 0013C10C  80 81 00 20 */	lwz r4, 0x20(r1)
/* 8013F1B0 0013C110  38 60 00 00 */	li r3, 0
/* 8013F1B4 0013C114  7C 80 1A 38 */	eqv r0, r4, r3
/* 8013F1B8 0013C118  7C 64 18 10 */	subfc r3, r4, r3
/* 8013F1BC 0013C11C  54 00 0F FE */	srwi r0, r0, 0x1f
/* 8013F1C0 0013C120  7C 60 01 94 */	addze r3, r0
/* 8013F1C4 0013C124  54 63 07 FE */	clrlwi r3, r3, 0x1f
/* 8013F1C8 0013C128  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8013F1CC 0013C12C  38 21 00 28 */	addi r1, r1, 0x28
/* 8013F1D0 0013C130  7C 08 03 A6 */	mtlr r0
/* 8013F1D4 0013C134  4E 80 00 20 */	blr 

.global actByEvent__16TaiSmashedActionFR9TekiEvent
actByEvent__16TaiSmashedActionFR9TekiEvent:
/* 8013F1D8 0013C138  7C 08 02 A6 */	mflr r0
/* 8013F1DC 0013C13C  90 01 00 04 */	stw r0, 4(r1)
/* 8013F1E0 0013C140  94 21 FF F8 */	stwu r1, -8(r1)
/* 8013F1E4 0013C144  80 04 00 00 */	lwz r0, 0(r4)
/* 8013F1E8 0013C148  2C 00 00 01 */	cmpwi r0, 1
/* 8013F1EC 0013C14C  40 82 00 28 */	bne lbl_8013F214
/* 8013F1F0 0013C150  80 64 00 08 */	lwz r3, 8(r4)
/* 8013F1F4 0013C154  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 8013F1F8 0013C158  2C 00 00 00 */	cmpwi r0, 0
/* 8013F1FC 0013C15C  40 82 00 18 */	bne lbl_8013F214
/* 8013F200 0013C160  4B F8 93 55 */	bl getState__4PikiFv
/* 8013F204 0013C164  2C 03 00 0E */	cmpwi r3, 0xe
/* 8013F208 0013C168  40 82 00 0C */	bne lbl_8013F214
/* 8013F20C 0013C16C  38 60 00 01 */	li r3, 1
/* 8013F210 0013C170  48 00 00 08 */	b lbl_8013F218
lbl_8013F214:
/* 8013F214 0013C174  38 60 00 00 */	li r3, 0
lbl_8013F218:
/* 8013F218 0013C178  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013F21C 0013C17C  38 21 00 08 */	addi r1, r1, 8
/* 8013F220 0013C180  7C 08 03 A6 */	mtlr r0
/* 8013F224 0013C184  4E 80 00 20 */	blr 

.global start__21TaiBeingPressedActionFR4Teki
start__21TaiBeingPressedActionFR4Teki:
/* 8013F228 0013C188  7C 08 02 A6 */	mflr r0
/* 8013F22C 0013C18C  90 01 00 04 */	stw r0, 4(r1)
/* 8013F230 0013C190  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8013F234 0013C194  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8013F238 0013C198  7C 9F 23 78 */	mr r31, r4
/* 8013F23C 0013C19C  7F E3 FB 78 */	mr r3, r31
/* 8013F240 0013C1A0  81 9F 00 00 */	lwz r12, 0(r31)
/* 8013F244 0013C1A4  80 8D F6 50 */	lwz r4, TEKI_OPTION_PRESSED__5BTeki@sda21(r13)
/* 8013F248 0013C1A8  81 8C 01 CC */	lwz r12, 0x1cc(r12)
/* 8013F24C 0013C1AC  7D 88 03 A6 */	mtlr r12
/* 8013F250 0013C1B0  4E 80 00 21 */	blrl 
/* 8013F254 0013C1B4  7F E3 FB 78 */	mr r3, r31
/* 8013F258 0013C1B8  80 8D F6 3C */	lwz r4, TEKI_OPTION_ALIVE__5BTeki@sda21(r13)
/* 8013F25C 0013C1BC  81 9F 00 00 */	lwz r12, 0(r31)
/* 8013F260 0013C1C0  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 8013F264 0013C1C4  7D 88 03 A6 */	mtlr r12
/* 8013F268 0013C1C8  4E 80 00 21 */	blrl 
/* 8013F26C 0013C1CC  7F E3 FB 78 */	mr r3, r31
/* 8013F270 0013C1D0  80 8D F6 38 */	lwz r4, TEKI_OPTION_ATARI__5BTeki@sda21(r13)
/* 8013F274 0013C1D4  81 9F 00 00 */	lwz r12, 0(r31)
/* 8013F278 0013C1D8  81 8C 01 D0 */	lwz r12, 0x1d0(r12)
/* 8013F27C 0013C1DC  7D 88 03 A6 */	mtlr r12
/* 8013F280 0013C1E0  4E 80 00 21 */	blrl 
/* 8013F284 0013C1E4  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8013F288 0013C1E8  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8013F28C 0013C1EC  38 21 00 18 */	addi r1, r1, 0x18
/* 8013F290 0013C1F0  7C 08 03 A6 */	mtlr r0
/* 8013F294 0013C1F4  4E 80 00 20 */	blr 

.global actByEvent__16TaiPressedActionFR9TekiEvent
actByEvent__16TaiPressedActionFR9TekiEvent:
/* 8013F298 0013C1F8  80 04 00 00 */	lwz r0, 0(r4)
/* 8013F29C 0013C1FC  2C 00 00 03 */	cmpwi r0, 3
/* 8013F2A0 0013C200  40 82 00 0C */	bne lbl_8013F2AC
/* 8013F2A4 0013C204  38 60 00 01 */	li r3, 1
/* 8013F2A8 0013C208  4E 80 00 20 */	blr 
lbl_8013F2AC:
/* 8013F2AC 0013C20C  38 60 00 00 */	li r3, 0
/* 8013F2B0 0013C210  4E 80 00 20 */	blr 

.global start__13TaiWarnActionFR4Teki
start__13TaiWarnActionFR4Teki:
/* 8013F2B4 0013C214  80 64 02 C4 */	lwz r3, 0x2c4(r4)
/* 8013F2B8 0013C218  80 63 00 84 */	lwz r3, 0x84(r3)
/* 8013F2BC 0013C21C  80 63 00 04 */	lwz r3, 4(r3)
/* 8013F2C0 0013C220  80 63 00 00 */	lwz r3, 0(r3)
/* 8013F2C4 0013C224  C0 03 00 6C */	lfs f0, 0x6c(r3)
/* 8013F2C8 0013C228  D0 04 03 D4 */	stfs f0, 0x3d4(r4)
/* 8013F2CC 0013C22C  4E 80 00 20 */	blr 

.global act__19TaiDangerLifeActionFR4Teki
act__19TaiDangerLifeActionFR4Teki:
/* 8013F2D0 0013C230  C0 24 03 3C */	lfs f1, 0x33c(r4)
/* 8013F2D4 0013C234  38 00 00 00 */	li r0, 0
/* 8013F2D8 0013C238  C0 02 A6 20 */	lfs f0, lbl_803EA820@sda21(r2)
/* 8013F2DC 0013C23C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8013F2E0 0013C240  40 81 00 1C */	ble lbl_8013F2FC
/* 8013F2E4 0013C244  C0 24 00 58 */	lfs f1, 0x58(r4)
/* 8013F2E8 0013C248  C0 03 00 08 */	lfs f0, 8(r3)
/* 8013F2EC 0013C24C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8013F2F0 0013C250  4C 40 13 82 */	cror 2, 0, 2
/* 8013F2F4 0013C254  40 82 00 08 */	bne lbl_8013F2FC
/* 8013F2F8 0013C258  38 00 00 01 */	li r0, 1
lbl_8013F2FC:
/* 8013F2FC 0013C25C  7C 03 03 78 */	mr r3, r0
/* 8013F300 0013C260  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802CB6C8:
	.asciz "taireactionactions.cpp"
.balign 4
lbl_802CB6E0:
	.asciz "taireactionactions"
.balign 4
lbl_802CB6F4:
	.asciz "TaiDangerLifeAction"
.balign 4
lbl_802CB708:
	.asciz "TaiAction"
.balign 4
lbl_802CB714:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__19TaiDangerLifeAction
__vt__19TaiDangerLifeAction:
	.4byte __RTTI__19TaiDangerLifeAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__19TaiDangerLifeActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CB73C:
	.asciz "TaiWarnAction"
.balign 4
lbl_802CB74C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__13TaiWarnAction
__vt__13TaiWarnAction:
	.4byte __RTTI__13TaiWarnAction
	.4byte 0
	.4byte start__13TaiWarnActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CB774:
	.asciz "TaiPressedAction"
.balign 4
lbl_802CB788:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__16TaiPressedAction
__vt__16TaiPressedAction:
	.4byte __RTTI__16TaiPressedAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__16TaiPressedActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CB7B0:
	.asciz "TaiBeingPressedAction"
.balign 4
lbl_802CB7C8:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__21TaiBeingPressedAction
__vt__21TaiBeingPressedAction:
	.4byte __RTTI__21TaiBeingPressedAction
	.4byte 0
	.4byte start__21TaiBeingPressedActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CB7F0:
	.asciz "TaiSmashedAction"
.balign 4
lbl_802CB804:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__16TaiSmashedAction
__vt__16TaiSmashedAction:
	.4byte __RTTI__16TaiSmashedAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__16TaiSmashedActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CB82C:
	.asciz "TaiStickedAction"
.balign 4
lbl_802CB840:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__16TaiStickedAction
__vt__16TaiStickedAction:
	.4byte __RTTI__16TaiStickedAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__16TaiStickedActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CB868:
	.asciz "TekiAndCondition"
.balign 4
lbl_802CB87C:
	.asciz "Condition"
.balign 4
lbl_802CB888:
	.asciz "TekiCondition"
.balign 4
lbl_802CB898:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
lbl_802CB8A4:
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
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
.balign 4
lbl_802CB8DC:
	.asciz "TaiTargetNearestCollisionAction"
.balign 4
lbl_802CB8FC:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__31TaiTargetNearestCollisionAction
__vt__31TaiTargetNearestCollisionAction:
	.4byte __RTTI__31TaiTargetNearestCollisionAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__31TaiTargetNearestCollisionActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CB924:
	.asciz "TaiTargetNearestAssailantAction"
.balign 4
lbl_802CB944:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__31TaiTargetNearestAssailantAction
__vt__31TaiTargetNearestAssailantAction:
	.4byte __RTTI__31TaiTargetNearestAssailantAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__31TaiTargetNearestAssailantActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CB96C:
	.asciz "TaiDamagingAction"
.balign 4
lbl_802CB980:
	.asciz "TaiMotionAction"
.balign 4
lbl_802CB990:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
lbl_802CB99C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__15TaiMotionAction
	.4byte 0
	.4byte 0
.global __vt__17TaiDamagingAction
__vt__17TaiDamagingAction:
	.4byte __RTTI__17TaiDamagingAction
	.4byte 0
	.4byte start__17TaiDamagingActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__17TaiDamagingActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CB9CC:
	.asciz "TaiCounterattackSimultaneousDamageAction"
.balign 4
lbl_802CB9F8:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__40TaiCounterattackSimultaneousDamageAction
__vt__40TaiCounterattackSimultaneousDamageAction:
	.4byte __RTTI__40TaiCounterattackSimultaneousDamageAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__40TaiCounterattackSimultaneousDamageActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBA20:
	.asciz "TaiSimultaneousDamageAction"
.balign 4
lbl_802CBA3C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__27TaiSimultaneousDamageAction
__vt__27TaiSimultaneousDamageAction:
	.4byte __RTTI__27TaiSimultaneousDamageAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__27TaiSimultaneousDamageActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBA64:
	.asciz "TaiDamageAction"
.balign 4
lbl_802CBA74:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__15TaiDamageAction
__vt__15TaiDamageAction:
	.4byte __RTTI__15TaiDamageAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__15TaiDamageActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBA9C:
	.asciz "TaiDamageScaleAction"
.balign 4
lbl_802CBAB4:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__20TaiDamageScaleAction
__vt__20TaiDamageScaleAction:
	.4byte __RTTI__20TaiDamageScaleAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__20TaiDamageScaleActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBADC:
	.asciz "TaiDamageCountAction"
.balign 4
lbl_802CBAF4:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__20TaiDamageCountAction
__vt__20TaiDamageCountAction:
	.4byte __RTTI__20TaiDamageCountAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__20TaiDamageCountActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBB1C:
	.asciz "TaiDamageCountResetAction"
.balign 4
lbl_802CBB38:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__25TaiDamageCountResetAction
__vt__25TaiDamageCountResetAction:
	.4byte __RTTI__25TaiDamageCountResetAction
	.4byte 0
	.4byte start__25TaiDamageCountResetActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBB60:
	.asciz "TaiDyingAction"
.balign 4
lbl_802CBB70:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__15TaiMotionAction
	.4byte 0
	.4byte 0
.global __vt__14TaiDyingAction
__vt__14TaiDyingAction:
	.4byte __RTTI__14TaiDyingAction
	.4byte 0
	.4byte start__14TaiDyingActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__14TaiDyingActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBBA0:
	.asciz "TaiCreateDeadEffectAction"
.balign 4
lbl_802CBBBC:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__25TaiCreateDeadEffectAction
__vt__25TaiCreateDeadEffectAction:
	.4byte __RTTI__25TaiCreateDeadEffectAction
	.4byte 0
	.4byte start__25TaiCreateDeadEffectActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBBE4:
	.asciz "TaiSpawnItemsAction"
.balign 4
lbl_802CBBF8:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__19TaiSpawnItemsAction
__vt__19TaiSpawnItemsAction:
	.4byte __RTTI__19TaiSpawnItemsAction
	.4byte 0
	.4byte start__19TaiSpawnItemsActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBC20:
	.asciz "TaiStartDyingAction"
.balign 4
lbl_802CBC34:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__19TaiStartDyingAction
__vt__19TaiStartDyingAction:
	.4byte __RTTI__19TaiStartDyingAction
	.4byte 0
	.4byte start__19TaiStartDyingActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBC5C:
	.asciz "TaiDyeAction"
.balign 4
lbl_802CBC6C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__12TaiDyeAction
__vt__12TaiDyeAction:
	.4byte __RTTI__12TaiDyeAction
	.4byte 0
	.4byte start__12TaiDyeActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBC94:
	.asciz "TaiLifeDamageAction"
.balign 4
lbl_802CBCA8:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__19TaiLifeDamageAction
__vt__19TaiLifeDamageAction:
	.4byte __RTTI__19TaiLifeDamageAction
	.4byte 0
	.4byte start__19TaiLifeDamageActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBCD0:
	.asciz "TaiLifeZeroAction"
.balign 4
lbl_802CBCE4:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__17TaiLifeZeroAction
__vt__17TaiLifeZeroAction:
	.4byte __RTTI__17TaiLifeZeroAction
	.4byte 0
	.4byte start__17TaiLifeZeroActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.balign 4
lbl_802CBD0C:
	.asciz "TaiDeadAction"
.balign 4
lbl_802CBD1C:
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.global __vt__13TaiDeadAction
__vt__13TaiDeadAction:
	.4byte __RTTI__13TaiDeadAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__13TaiDeadActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__9TaiAction:
	.4byte lbl_802CB708
	.4byte 0
__RTTI__19TaiDangerLifeAction:
	.4byte lbl_802CB6F4
	.4byte lbl_802CB714
__RTTI__13TaiWarnAction:
	.4byte lbl_802CB73C
	.4byte lbl_802CB74C
__RTTI__16TaiPressedAction:
	.4byte lbl_802CB774
	.4byte lbl_802CB788
__RTTI__21TaiBeingPressedAction:
	.4byte lbl_802CB7B0
	.4byte lbl_802CB7C8
__RTTI__16TaiSmashedAction:
	.4byte lbl_802CB7F0
	.4byte lbl_802CB804
__RTTI__16TaiStickedAction:
	.4byte lbl_802CB82C
	.4byte lbl_802CB840
__RTTI__9Condition:
	.4byte lbl_802CB87C
	.4byte 0
__RTTI__13TekiCondition:
	.4byte lbl_802CB888
	.4byte lbl_802CB898
__RTTI__31TaiTargetNearestCollisionAction:
	.4byte lbl_802CB8DC
	.4byte lbl_802CB8FC
__RTTI__31TaiTargetNearestAssailantAction:
	.4byte lbl_802CB924
	.4byte lbl_802CB944
__RTTI__15TaiMotionAction:
	.4byte lbl_802CB980
	.4byte lbl_802CB990
__RTTI__17TaiDamagingAction:
	.4byte lbl_802CB96C
	.4byte lbl_802CB99C
__RTTI__40TaiCounterattackSimultaneousDamageAction:
	.4byte lbl_802CB9CC
	.4byte lbl_802CB9F8
__RTTI__27TaiSimultaneousDamageAction:
	.4byte lbl_802CBA20
	.4byte lbl_802CBA3C
__RTTI__15TaiDamageAction:
	.4byte lbl_802CBA64
	.4byte lbl_802CBA74
__RTTI__20TaiDamageScaleAction:
	.4byte lbl_802CBA9C
	.4byte lbl_802CBAB4
__RTTI__20TaiDamageCountAction:
	.4byte lbl_802CBADC
	.4byte lbl_802CBAF4
__RTTI__25TaiDamageCountResetAction:
	.4byte lbl_802CBB1C
	.4byte lbl_802CBB38
__RTTI__14TaiDyingAction:
	.4byte lbl_802CBB60
	.4byte lbl_802CBB70
__RTTI__25TaiCreateDeadEffectAction:
	.4byte lbl_802CBBA0
	.4byte lbl_802CBBBC
__RTTI__19TaiSpawnItemsAction:
	.4byte lbl_802CBBE4
	.4byte lbl_802CBBF8
__RTTI__19TaiStartDyingAction:
	.4byte lbl_802CBC20
	.4byte lbl_802CBC34
__RTTI__12TaiDyeAction:
	.4byte lbl_802CBC5C
	.4byte lbl_802CBC6C
__RTTI__19TaiLifeDamageAction:
	.4byte lbl_802CBC94
	.4byte lbl_802CBCA8
__RTTI__17TaiLifeZeroAction:
	.4byte lbl_802CBCD0
	.4byte lbl_802CBCE4
__RTTI__13TaiDeadAction:
	.4byte lbl_802CBD0C
	.4byte lbl_802CBD1C

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EA820:
	.float 0.0
.balign 8
lbl_803EA828:
	.4byte 0x43300000
	.4byte 0x80000000
