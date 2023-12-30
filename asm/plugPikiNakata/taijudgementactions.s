.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn act__22TaiVisibleTargetActionFR4Teki, global
/* 8012F4CC 0012C42C  7C 08 02 A6 */	mflr r0
/* 8012F4D0 0012C430  90 01 00 04 */	stw r0, 4(r1)
/* 8012F4D4 0012C434  94 21 FF F8 */	stwu r1, -8(r1)
/* 8012F4D8 0012C438  80 04 04 18 */	lwz r0, 0x418(r4)
/* 8012F4DC 0012C43C  28 00 00 00 */	cmplwi r0, 0
/* 8012F4E0 0012C440  40 82 00 0C */	bne .L_8012F4EC
/* 8012F4E4 0012C444  38 60 00 00 */	li r3, 0
/* 8012F4E8 0012C448  48 00 00 24 */	b .L_8012F50C
.L_8012F4EC:
/* 8012F4EC 0012C44C  38 64 00 00 */	addi r3, r4, 0
/* 8012F4F0 0012C450  7C 04 03 78 */	mr r4, r0
/* 8012F4F4 0012C454  48 01 78 21 */	bl visibleCreature__5BTekiFR8Creature
/* 8012F4F8 0012C458  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8012F4FC 0012C45C  40 82 00 0C */	bne .L_8012F508
/* 8012F500 0012C460  38 60 00 00 */	li r3, 0
/* 8012F504 0012C464  48 00 00 08 */	b .L_8012F50C
.L_8012F508:
/* 8012F508 0012C468  38 60 00 01 */	li r3, 1
.L_8012F50C:
/* 8012F50C 0012C46C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8012F510 0012C470  38 21 00 08 */	addi r1, r1, 8
/* 8012F514 0012C474  7C 08 03 A6 */	mtlr r0
/* 8012F518 0012C478  4E 80 00 20 */	blr 
.endfn act__22TaiVisibleTargetActionFR4Teki

.fn act__22TaiContactTargetActionFR4Teki, global
/* 8012F51C 0012C47C  7C 08 02 A6 */	mflr r0
/* 8012F520 0012C480  90 01 00 04 */	stw r0, 4(r1)
/* 8012F524 0012C484  94 21 FF F8 */	stwu r1, -8(r1)
/* 8012F528 0012C488  80 04 04 18 */	lwz r0, 0x418(r4)
/* 8012F52C 0012C48C  28 00 00 00 */	cmplwi r0, 0
/* 8012F530 0012C490  40 82 00 0C */	bne .L_8012F53C
/* 8012F534 0012C494  38 60 00 00 */	li r3, 0
/* 8012F538 0012C498  48 00 00 24 */	b .L_8012F55C
.L_8012F53C:
/* 8012F53C 0012C49C  38 64 00 00 */	addi r3, r4, 0
/* 8012F540 0012C4A0  7C 04 03 78 */	mr r4, r0
/* 8012F544 0012C4A4  48 01 7A B5 */	bl contactCreature__5BTekiFR8Creature
/* 8012F548 0012C4A8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8012F54C 0012C4AC  40 82 00 0C */	bne .L_8012F558
/* 8012F550 0012C4B0  38 60 00 00 */	li r3, 0
/* 8012F554 0012C4B4  48 00 00 08 */	b .L_8012F55C
.L_8012F558:
/* 8012F558 0012C4B8  38 60 00 01 */	li r3, 1
.L_8012F55C:
/* 8012F55C 0012C4BC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8012F560 0012C4C0  38 21 00 08 */	addi r1, r1, 8
/* 8012F564 0012C4C4  7C 08 03 A6 */	mtlr r0
/* 8012F568 0012C4C8  4E 80 00 20 */	blr 
.endfn act__22TaiContactTargetActionFR4Teki

.fn act__23TaiSeparateTargetActionFR4Teki, global
/* 8012F56C 0012C4CC  7C 08 02 A6 */	mflr r0
/* 8012F570 0012C4D0  90 01 00 04 */	stw r0, 4(r1)
/* 8012F574 0012C4D4  94 21 FF F8 */	stwu r1, -8(r1)
/* 8012F578 0012C4D8  80 04 04 18 */	lwz r0, 0x418(r4)
/* 8012F57C 0012C4DC  28 00 00 00 */	cmplwi r0, 0
/* 8012F580 0012C4E0  40 82 00 0C */	bne .L_8012F58C
/* 8012F584 0012C4E4  38 60 00 01 */	li r3, 1
/* 8012F588 0012C4E8  48 00 00 24 */	b .L_8012F5AC
.L_8012F58C:
/* 8012F58C 0012C4EC  38 64 00 00 */	addi r3, r4, 0
/* 8012F590 0012C4F0  7C 04 03 78 */	mr r4, r0
/* 8012F594 0012C4F4  48 01 79 11 */	bl separateCreature__5BTekiFR8Creature
/* 8012F598 0012C4F8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8012F59C 0012C4FC  40 82 00 0C */	bne .L_8012F5A8
/* 8012F5A0 0012C500  38 60 00 00 */	li r3, 0
/* 8012F5A4 0012C504  48 00 00 08 */	b .L_8012F5AC
.L_8012F5A8:
/* 8012F5A8 0012C508  38 60 00 01 */	li r3, 1
.L_8012F5AC:
/* 8012F5AC 0012C50C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8012F5B0 0012C510  38 21 00 08 */	addi r1, r1, 8
/* 8012F5B4 0012C514  7C 08 03 A6 */	mtlr r0
/* 8012F5B8 0012C518  4E 80 00 20 */	blr 
.endfn act__23TaiSeparateTargetActionFR4Teki

.fn act__19TaiTargetLostActionFR4Teki, global
/* 8012F5BC 0012C51C  7C 08 02 A6 */	mflr r0
/* 8012F5C0 0012C520  90 01 00 04 */	stw r0, 4(r1)
/* 8012F5C4 0012C524  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8012F5C8 0012C528  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8012F5CC 0012C52C  7C 9F 23 78 */	mr r31, r4
/* 8012F5D0 0012C530  80 04 04 18 */	lwz r0, 0x418(r4)
/* 8012F5D4 0012C534  28 00 00 00 */	cmplwi r0, 0
/* 8012F5D8 0012C538  7C 04 03 78 */	mr r4, r0
/* 8012F5DC 0012C53C  40 82 00 0C */	bne .L_8012F5E8
/* 8012F5E0 0012C540  38 60 00 01 */	li r3, 1
/* 8012F5E4 0012C544  48 00 00 38 */	b .L_8012F61C
.L_8012F5E8:
/* 8012F5E8 0012C548  7F E3 FB 78 */	mr r3, r31
/* 8012F5EC 0012C54C  48 01 77 29 */	bl visibleCreature__5BTekiFR8Creature
/* 8012F5F0 0012C550  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8012F5F4 0012C554  40 82 00 24 */	bne .L_8012F618
/* 8012F5F8 0012C558  80 7F 04 18 */	lwz r3, 0x418(r31)
/* 8012F5FC 0012C55C  28 03 00 00 */	cmplwi r3, 0
/* 8012F600 0012C560  41 82 00 10 */	beq .L_8012F610
/* 8012F604 0012C564  4B FB 4D 69 */	bl subCnt__12RefCountableFv
/* 8012F608 0012C568  38 00 00 00 */	li r0, 0
/* 8012F60C 0012C56C  90 1F 04 18 */	stw r0, 0x418(r31)
.L_8012F610:
/* 8012F610 0012C570  38 60 00 01 */	li r3, 1
/* 8012F614 0012C574  48 00 00 08 */	b .L_8012F61C
.L_8012F618:
/* 8012F618 0012C578  38 60 00 00 */	li r3, 0
.L_8012F61C:
/* 8012F61C 0012C57C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8012F620 0012C580  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8012F624 0012C584  38 21 00 20 */	addi r1, r1, 0x20
/* 8012F628 0012C588  7C 08 03 A6 */	mtlr r0
/* 8012F62C 0012C58C  4E 80 00 20 */	blr 
.endfn act__19TaiTargetLostActionFR4Teki

.fn act__25TaiOutsideTerritoryActionFR4Teki, global
/* 8012F630 0012C590  7C 08 02 A6 */	mflr r0
/* 8012F634 0012C594  39 04 00 94 */	addi r8, r4, 0x94
/* 8012F638 0012C598  90 01 00 04 */	stw r0, 4(r1)
/* 8012F63C 0012C59C  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 8012F640 0012C5A0  93 E1 00 44 */	stw r31, 0x44(r1)
/* 8012F644 0012C5A4  3B E3 00 00 */	addi r31, r3, 0
/* 8012F648 0012C5A8  38 C1 00 28 */	addi r6, r1, 0x28
/* 8012F64C 0012C5AC  80 E4 02 C8 */	lwz r7, 0x2c8(r4)
/* 8012F650 0012C5B0  38 A1 00 24 */	addi r5, r1, 0x24
/* 8012F654 0012C5B4  C0 02 A3 48 */	lfs f0, lbl_803EA548@sda21(r2)
/* 8012F658 0012C5B8  38 81 00 20 */	addi r4, r1, 0x20
/* 8012F65C 0012C5BC  38 E7 00 10 */	addi r7, r7, 0x10
/* 8012F660 0012C5C0  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 8012F664 0012C5C4  38 61 00 34 */	addi r3, r1, 0x34
/* 8012F668 0012C5C8  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 8012F66C 0012C5CC  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 8012F670 0012C5D0  C0 28 00 08 */	lfs f1, 8(r8)
/* 8012F674 0012C5D4  C0 07 00 08 */	lfs f0, 8(r7)
/* 8012F678 0012C5D8  EC 01 00 28 */	fsubs f0, f1, f0
/* 8012F67C 0012C5DC  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 8012F680 0012C5E0  C0 28 00 04 */	lfs f1, 4(r8)
/* 8012F684 0012C5E4  C0 07 00 04 */	lfs f0, 4(r7)
/* 8012F688 0012C5E8  EC 01 00 28 */	fsubs f0, f1, f0
/* 8012F68C 0012C5EC  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 8012F690 0012C5F0  C0 28 00 00 */	lfs f1, 0(r8)
/* 8012F694 0012C5F4  C0 07 00 00 */	lfs f0, 0(r7)
/* 8012F698 0012C5F8  EC 01 00 28 */	fsubs f0, f1, f0
/* 8012F69C 0012C5FC  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 8012F6A0 0012C600  4B F2 DF ED */	bl set__8Vector3fFRCfRCfRCf
/* 8012F6A4 0012C604  C0 21 00 34 */	lfs f1, 0x34(r1)
/* 8012F6A8 0012C608  C0 01 00 38 */	lfs f0, 0x38(r1)
/* 8012F6AC 0012C60C  EC 21 00 72 */	fmuls f1, f1, f1
/* 8012F6B0 0012C610  C0 41 00 3C */	lfs f2, 0x3c(r1)
/* 8012F6B4 0012C614  EC 00 00 32 */	fmuls f0, f0, f0
/* 8012F6B8 0012C618  EC 42 00 B2 */	fmuls f2, f2, f2
/* 8012F6BC 0012C61C  EC 01 00 2A */	fadds f0, f1, f0
/* 8012F6C0 0012C620  EC 22 00 2A */	fadds f1, f2, f0
/* 8012F6C4 0012C624  4B ED E5 7D */	bl sqrtf__3stdFf
/* 8012F6C8 0012C628  C0 1F 00 08 */	lfs f0, 8(r31)
/* 8012F6CC 0012C62C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8012F6D0 0012C630  7C 00 00 26 */	mfcr r0
/* 8012F6D4 0012C634  54 03 17 FE */	rlwinm r3, r0, 2, 0x1f, 0x1f
/* 8012F6D8 0012C638  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 8012F6DC 0012C63C  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 8012F6E0 0012C640  38 21 00 48 */	addi r1, r1, 0x48
/* 8012F6E4 0012C644  7C 08 03 A6 */	mtlr r0
/* 8012F6E8 0012C648  4E 80 00 20 */	blr 
.endfn act__25TaiOutsideTerritoryActionFR4Teki

.fn act__24TaiInsideTerritoryActionFR4Teki, global
/* 8012F6EC 0012C64C  7C 08 02 A6 */	mflr r0
/* 8012F6F0 0012C650  39 04 00 94 */	addi r8, r4, 0x94
/* 8012F6F4 0012C654  90 01 00 04 */	stw r0, 4(r1)
/* 8012F6F8 0012C658  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 8012F6FC 0012C65C  93 E1 00 44 */	stw r31, 0x44(r1)
/* 8012F700 0012C660  3B E3 00 00 */	addi r31, r3, 0
/* 8012F704 0012C664  38 C1 00 28 */	addi r6, r1, 0x28
/* 8012F708 0012C668  80 E4 02 C8 */	lwz r7, 0x2c8(r4)
/* 8012F70C 0012C66C  38 A1 00 24 */	addi r5, r1, 0x24
/* 8012F710 0012C670  C0 02 A3 48 */	lfs f0, lbl_803EA548@sda21(r2)
/* 8012F714 0012C674  38 81 00 20 */	addi r4, r1, 0x20
/* 8012F718 0012C678  38 E7 00 10 */	addi r7, r7, 0x10
/* 8012F71C 0012C67C  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 8012F720 0012C680  38 61 00 34 */	addi r3, r1, 0x34
/* 8012F724 0012C684  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 8012F728 0012C688  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 8012F72C 0012C68C  C0 28 00 08 */	lfs f1, 8(r8)
/* 8012F730 0012C690  C0 07 00 08 */	lfs f0, 8(r7)
/* 8012F734 0012C694  EC 01 00 28 */	fsubs f0, f1, f0
/* 8012F738 0012C698  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 8012F73C 0012C69C  C0 28 00 04 */	lfs f1, 4(r8)
/* 8012F740 0012C6A0  C0 07 00 04 */	lfs f0, 4(r7)
/* 8012F744 0012C6A4  EC 01 00 28 */	fsubs f0, f1, f0
/* 8012F748 0012C6A8  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 8012F74C 0012C6AC  C0 28 00 00 */	lfs f1, 0(r8)
/* 8012F750 0012C6B0  C0 07 00 00 */	lfs f0, 0(r7)
/* 8012F754 0012C6B4  EC 01 00 28 */	fsubs f0, f1, f0
/* 8012F758 0012C6B8  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 8012F75C 0012C6BC  4B F2 DF 31 */	bl set__8Vector3fFRCfRCfRCf
/* 8012F760 0012C6C0  C0 21 00 34 */	lfs f1, 0x34(r1)
/* 8012F764 0012C6C4  C0 01 00 38 */	lfs f0, 0x38(r1)
/* 8012F768 0012C6C8  EC 21 00 72 */	fmuls f1, f1, f1
/* 8012F76C 0012C6CC  C0 41 00 3C */	lfs f2, 0x3c(r1)
/* 8012F770 0012C6D0  EC 00 00 32 */	fmuls f0, f0, f0
/* 8012F774 0012C6D4  EC 42 00 B2 */	fmuls f2, f2, f2
/* 8012F778 0012C6D8  EC 01 00 2A */	fadds f0, f1, f0
/* 8012F77C 0012C6DC  EC 22 00 2A */	fadds f1, f2, f0
/* 8012F780 0012C6E0  4B ED E4 C1 */	bl sqrtf__3stdFf
/* 8012F784 0012C6E4  C0 1F 00 08 */	lfs f0, 8(r31)
/* 8012F788 0012C6E8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8012F78C 0012C6EC  4C 40 13 82 */	cror 2, 0, 2
/* 8012F790 0012C6F0  7C 00 00 26 */	mfcr r0
/* 8012F794 0012C6F4  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 8012F798 0012C6F8  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 8012F79C 0012C6FC  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 8012F7A0 0012C700  38 21 00 48 */	addi r1, r1, 0x48
/* 8012F7A4 0012C704  7C 08 03 A6 */	mtlr r0
/* 8012F7A8 0012C708  4E 80 00 20 */	blr 
.endfn act__24TaiInsideTerritoryActionFR4Teki

.fn act__30TaiTargetVisibleNaviPikiActionFR4Teki, global
/* 8012F7AC 0012C70C  7C 08 02 A6 */	mflr r0
/* 8012F7B0 0012C710  3C 60 80 2B */	lis r3, __vt__9Condition@ha
/* 8012F7B4 0012C714  90 01 00 04 */	stw r0, 4(r1)
/* 8012F7B8 0012C718  38 03 F0 98 */	addi r0, r3, __vt__9Condition@l
/* 8012F7BC 0012C71C  3C 60 80 2C */	lis r3, __vt__13TekiCondition@ha
/* 8012F7C0 0012C720  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8012F7C4 0012C724  38 A0 00 00 */	li r5, 0
/* 8012F7C8 0012C728  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8012F7CC 0012C72C  93 C1 00 20 */	stw r30, 0x20(r1)
/* 8012F7D0 0012C730  3B C4 00 00 */	addi r30, r4, 0
/* 8012F7D4 0012C734  38 81 00 18 */	addi r4, r1, 0x18
/* 8012F7D8 0012C738  90 01 00 18 */	stw r0, 0x18(r1)
/* 8012F7DC 0012C73C  38 03 69 64 */	addi r0, r3, __vt__13TekiCondition@l
/* 8012F7E0 0012C740  3C 60 80 2D */	lis r3, __vt__20TekiVisibleCondition@ha
/* 8012F7E4 0012C744  90 01 00 18 */	stw r0, 0x18(r1)
/* 8012F7E8 0012C748  38 03 D5 0C */	addi r0, r3, __vt__20TekiVisibleCondition@l
/* 8012F7EC 0012C74C  38 7E 00 00 */	addi r3, r30, 0
/* 8012F7F0 0012C750  90 01 00 18 */	stw r0, 0x18(r1)
/* 8012F7F4 0012C754  93 C1 00 1C */	stw r30, 0x1c(r1)
/* 8012F7F8 0012C758  48 01 7E E9 */	bl getClosestNaviPiki__5BTekiFR9ConditionPf
/* 8012F7FC 0012C75C  7C 7F 1B 79 */	or. r31, r3, r3
/* 8012F800 0012C760  40 82 00 0C */	bne .L_8012F80C
/* 8012F804 0012C764  38 60 00 00 */	li r3, 0
/* 8012F808 0012C768  48 00 00 38 */	b .L_8012F840
.L_8012F80C:
/* 8012F80C 0012C76C  80 7E 04 18 */	lwz r3, 0x418(r30)
/* 8012F810 0012C770  28 03 00 00 */	cmplwi r3, 0
/* 8012F814 0012C774  41 82 00 14 */	beq .L_8012F828
/* 8012F818 0012C778  41 82 00 10 */	beq .L_8012F828
/* 8012F81C 0012C77C  4B FB 4B 51 */	bl subCnt__12RefCountableFv
/* 8012F820 0012C780  38 00 00 00 */	li r0, 0
/* 8012F824 0012C784  90 1E 04 18 */	stw r0, 0x418(r30)
.L_8012F828:
/* 8012F828 0012C788  93 FE 04 18 */	stw r31, 0x418(r30)
/* 8012F82C 0012C78C  80 7E 04 18 */	lwz r3, 0x418(r30)
/* 8012F830 0012C790  28 03 00 00 */	cmplwi r3, 0
/* 8012F834 0012C794  41 82 00 08 */	beq .L_8012F83C
/* 8012F838 0012C798  4B FB 4B 25 */	bl addCnt__12RefCountableFv
.L_8012F83C:
/* 8012F83C 0012C79C  38 60 00 01 */	li r3, 1
.L_8012F840:
/* 8012F840 0012C7A0  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8012F844 0012C7A4  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8012F848 0012C7A8  83 C1 00 20 */	lwz r30, 0x20(r1)
/* 8012F84C 0012C7AC  38 21 00 28 */	addi r1, r1, 0x28
/* 8012F850 0012C7B0  7C 08 03 A6 */	mtlr r0
/* 8012F854 0012C7B4  4E 80 00 20 */	blr 
.endfn act__30TaiTargetVisibleNaviPikiActionFR4Teki

.fn act__26TaiTargetVisibleNaviActionFR4Teki, global
/* 8012F858 0012C7B8  7C 08 02 A6 */	mflr r0
/* 8012F85C 0012C7BC  3C A0 80 2B */	lis r5, __vt__9Condition@ha
/* 8012F860 0012C7C0  90 01 00 04 */	stw r0, 4(r1)
/* 8012F864 0012C7C4  38 C5 F0 98 */	addi r6, r5, __vt__9Condition@l
/* 8012F868 0012C7C8  3C A0 80 2C */	lis r5, __vt__13TekiCondition@ha
/* 8012F86C 0012C7CC  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8012F870 0012C7D0  39 25 69 64 */	addi r9, r5, __vt__13TekiCondition@l
/* 8012F874 0012C7D4  3C A0 80 2C */	lis r5, __vt__16TekiAndCondition@ha
/* 8012F878 0012C7D8  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 8012F87C 0012C7DC  38 05 68 5C */	addi r0, r5, __vt__16TekiAndCondition@l
/* 8012F880 0012C7E0  3C A0 80 2D */	lis r5, __vt__20TekiVisibleCondition@ha
/* 8012F884 0012C7E4  93 C1 00 58 */	stw r30, 0x58(r1)
/* 8012F888 0012C7E8  38 E5 D5 0C */	addi r7, r5, __vt__20TekiVisibleCondition@l
/* 8012F88C 0012C7EC  3C A0 80 2D */	lis r5, __vt__17TekiNaviCondition@ha
/* 8012F890 0012C7F0  90 C1 00 48 */	stw r6, 0x48(r1)
/* 8012F894 0012C7F4  3B C4 00 00 */	addi r30, r4, 0
/* 8012F898 0012C7F8  39 05 D8 44 */	addi r8, r5, __vt__17TekiNaviCondition@l
/* 8012F89C 0012C7FC  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 8012F8A0 0012C800  90 C1 00 40 */	stw r6, 0x40(r1)
/* 8012F8A4 0012C804  38 A1 00 48 */	addi r5, r1, 0x48
/* 8012F8A8 0012C808  90 C1 00 3C */	stw r6, 0x3c(r1)
/* 8012F8AC 0012C80C  38 C1 00 40 */	addi r6, r1, 0x40
/* 8012F8B0 0012C810  38 9E 00 94 */	addi r4, r30, 0x94
/* 8012F8B4 0012C814  91 21 00 48 */	stw r9, 0x48(r1)
/* 8012F8B8 0012C818  90 01 00 48 */	stw r0, 0x48(r1)
/* 8012F8BC 0012C81C  38 01 00 3C */	addi r0, r1, 0x3c
/* 8012F8C0 0012C820  91 21 00 40 */	stw r9, 0x40(r1)
/* 8012F8C4 0012C824  91 21 00 3C */	stw r9, 0x3c(r1)
/* 8012F8C8 0012C828  90 E1 00 40 */	stw r7, 0x40(r1)
/* 8012F8CC 0012C82C  90 C1 00 4C */	stw r6, 0x4c(r1)
/* 8012F8D0 0012C830  91 01 00 3C */	stw r8, 0x3c(r1)
/* 8012F8D4 0012C834  93 C1 00 44 */	stw r30, 0x44(r1)
/* 8012F8D8 0012C838  90 01 00 50 */	stw r0, 0x50(r1)
/* 8012F8DC 0012C83C  81 83 00 00 */	lwz r12, 0(r3)
/* 8012F8E0 0012C840  81 8C 00 6C */	lwz r12, 0x6c(r12)
/* 8012F8E4 0012C844  7D 88 03 A6 */	mtlr r12
/* 8012F8E8 0012C848  4E 80 00 21 */	blrl 
/* 8012F8EC 0012C84C  7C 7F 1B 79 */	or. r31, r3, r3
/* 8012F8F0 0012C850  40 82 00 0C */	bne .L_8012F8FC
/* 8012F8F4 0012C854  38 60 00 00 */	li r3, 0
/* 8012F8F8 0012C858  48 00 00 38 */	b .L_8012F930
.L_8012F8FC:
/* 8012F8FC 0012C85C  80 7E 04 18 */	lwz r3, 0x418(r30)
/* 8012F900 0012C860  28 03 00 00 */	cmplwi r3, 0
/* 8012F904 0012C864  41 82 00 14 */	beq .L_8012F918
/* 8012F908 0012C868  41 82 00 10 */	beq .L_8012F918
/* 8012F90C 0012C86C  4B FB 4A 61 */	bl subCnt__12RefCountableFv
/* 8012F910 0012C870  38 00 00 00 */	li r0, 0
/* 8012F914 0012C874  90 1E 04 18 */	stw r0, 0x418(r30)
.L_8012F918:
/* 8012F918 0012C878  93 FE 04 18 */	stw r31, 0x418(r30)
/* 8012F91C 0012C87C  80 7E 04 18 */	lwz r3, 0x418(r30)
/* 8012F920 0012C880  28 03 00 00 */	cmplwi r3, 0
/* 8012F924 0012C884  41 82 00 08 */	beq .L_8012F92C
/* 8012F928 0012C888  4B FB 4A 35 */	bl addCnt__12RefCountableFv
.L_8012F92C:
/* 8012F92C 0012C88C  38 60 00 01 */	li r3, 1
.L_8012F930:
/* 8012F930 0012C890  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8012F934 0012C894  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 8012F938 0012C898  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 8012F93C 0012C89C  38 21 00 60 */	addi r1, r1, 0x60
/* 8012F940 0012C8A0  7C 08 03 A6 */	mtlr r0
/* 8012F944 0012C8A4  4E 80 00 20 */	blr 
.endfn act__26TaiTargetVisibleNaviActionFR4Teki

.fn act__27TaiHasStickersInMouthActionFR4Teki, global
/* 8012F948 0012C8A8  7C 08 02 A6 */	mflr r0
/* 8012F94C 0012C8AC  90 01 00 04 */	stw r0, 4(r1)
/* 8012F950 0012C8B0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8012F954 0012C8B4  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8012F958 0012C8B8  38 61 00 28 */	addi r3, r1, 0x28
/* 8012F95C 0012C8BC  93 C1 00 38 */	stw r30, 0x38(r1)
/* 8012F960 0012C8C0  4B F6 13 25 */	bl __ct__8StickersFP8Creature
/* 8012F964 0012C8C4  3B E1 00 28 */	addi r31, r1, 0x28
/* 8012F968 0012C8C8  38 7F 00 00 */	addi r3, r31, 0
/* 8012F96C 0012C8CC  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012F970 0012C8D0  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8012F974 0012C8D4  7D 88 03 A6 */	mtlr r12
/* 8012F978 0012C8D8  4E 80 00 21 */	blrl 
/* 8012F97C 0012C8DC  7C 7E 1B 78 */	mr r30, r3
/* 8012F980 0012C8E0  48 00 00 78 */	b .L_8012F9F8
.L_8012F984:
/* 8012F984 0012C8E4  2C 1E FF FF */	cmpwi r30, -1
/* 8012F988 0012C8E8  40 82 00 20 */	bne .L_8012F9A8
/* 8012F98C 0012C8EC  7F E3 FB 78 */	mr r3, r31
/* 8012F990 0012C8F0  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012F994 0012C8F4  38 80 00 00 */	li r4, 0
/* 8012F998 0012C8F8  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012F99C 0012C8FC  7D 88 03 A6 */	mtlr r12
/* 8012F9A0 0012C900  4E 80 00 21 */	blrl 
/* 8012F9A4 0012C904  48 00 00 1C */	b .L_8012F9C0
.L_8012F9A8:
/* 8012F9A8 0012C908  7F E3 FB 78 */	mr r3, r31
/* 8012F9AC 0012C90C  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012F9B0 0012C910  7F C4 F3 78 */	mr r4, r30
/* 8012F9B4 0012C914  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012F9B8 0012C918  7D 88 03 A6 */	mtlr r12
/* 8012F9BC 0012C91C  4E 80 00 21 */	blrl 
.L_8012F9C0:
/* 8012F9C0 0012C920  28 03 00 00 */	cmplwi r3, 0
/* 8012F9C4 0012C924  41 82 00 90 */	beq .L_8012FA54
/* 8012F9C8 0012C928  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 8012F9CC 0012C92C  54 00 04 21 */	rlwinm. r0, r0, 0, 0x10, 0x10
/* 8012F9D0 0012C930  41 82 00 0C */	beq .L_8012F9DC
/* 8012F9D4 0012C934  38 60 00 01 */	li r3, 1
/* 8012F9D8 0012C938  48 00 00 80 */	b .L_8012FA58
.L_8012F9DC:
/* 8012F9DC 0012C93C  7F E3 FB 78 */	mr r3, r31
/* 8012F9E0 0012C940  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012F9E4 0012C944  7F C4 F3 78 */	mr r4, r30
/* 8012F9E8 0012C948  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8012F9EC 0012C94C  7D 88 03 A6 */	mtlr r12
/* 8012F9F0 0012C950  4E 80 00 21 */	blrl 
/* 8012F9F4 0012C954  7C 7E 1B 78 */	mr r30, r3
.L_8012F9F8:
/* 8012F9F8 0012C958  7F E3 FB 78 */	mr r3, r31
/* 8012F9FC 0012C95C  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012FA00 0012C960  7F C4 F3 78 */	mr r4, r30
/* 8012FA04 0012C964  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8012FA08 0012C968  7D 88 03 A6 */	mtlr r12
/* 8012FA0C 0012C96C  4E 80 00 21 */	blrl 
/* 8012FA10 0012C970  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8012FA14 0012C974  41 82 00 0C */	beq .L_8012FA20
/* 8012FA18 0012C978  38 00 00 01 */	li r0, 1
/* 8012FA1C 0012C97C  48 00 00 30 */	b .L_8012FA4C
.L_8012FA20:
/* 8012FA20 0012C980  7F E3 FB 78 */	mr r3, r31
/* 8012FA24 0012C984  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012FA28 0012C988  7F C4 F3 78 */	mr r4, r30
/* 8012FA2C 0012C98C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012FA30 0012C990  7D 88 03 A6 */	mtlr r12
/* 8012FA34 0012C994  4E 80 00 21 */	blrl 
/* 8012FA38 0012C998  28 03 00 00 */	cmplwi r3, 0
/* 8012FA3C 0012C99C  40 82 00 0C */	bne .L_8012FA48
/* 8012FA40 0012C9A0  38 00 00 01 */	li r0, 1
/* 8012FA44 0012C9A4  48 00 00 08 */	b .L_8012FA4C
.L_8012FA48:
/* 8012FA48 0012C9A8  38 00 00 00 */	li r0, 0
.L_8012FA4C:
/* 8012FA4C 0012C9AC  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8012FA50 0012C9B0  41 82 FF 34 */	beq .L_8012F984
.L_8012FA54:
/* 8012FA54 0012C9B4  38 60 00 00 */	li r3, 0
.L_8012FA58:
/* 8012FA58 0012C9B8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8012FA5C 0012C9BC  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8012FA60 0012C9C0  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 8012FA64 0012C9C4  38 21 00 40 */	addi r1, r1, 0x40
/* 8012FA68 0012C9C8  7C 08 03 A6 */	mtlr r0
/* 8012FA6C 0012C9CC  4E 80 00 20 */	blr 
.endfn act__27TaiHasStickersInMouthActionFR4Teki

.fn act__26TaiHasStickersOnBodyActionFR4Teki, global
/* 8012FA70 0012C9D0  7C 08 02 A6 */	mflr r0
/* 8012FA74 0012C9D4  90 01 00 04 */	stw r0, 4(r1)
/* 8012FA78 0012C9D8  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8012FA7C 0012C9DC  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8012FA80 0012C9E0  38 61 00 28 */	addi r3, r1, 0x28
/* 8012FA84 0012C9E4  93 C1 00 38 */	stw r30, 0x38(r1)
/* 8012FA88 0012C9E8  4B F6 11 FD */	bl __ct__8StickersFP8Creature
/* 8012FA8C 0012C9EC  3B E1 00 28 */	addi r31, r1, 0x28
/* 8012FA90 0012C9F0  38 7F 00 00 */	addi r3, r31, 0
/* 8012FA94 0012C9F4  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012FA98 0012C9F8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8012FA9C 0012C9FC  7D 88 03 A6 */	mtlr r12
/* 8012FAA0 0012CA00  4E 80 00 21 */	blrl 
/* 8012FAA4 0012CA04  7C 7E 1B 78 */	mr r30, r3
/* 8012FAA8 0012CA08  48 00 00 78 */	b .L_8012FB20
.L_8012FAAC:
/* 8012FAAC 0012CA0C  2C 1E FF FF */	cmpwi r30, -1
/* 8012FAB0 0012CA10  40 82 00 20 */	bne .L_8012FAD0
/* 8012FAB4 0012CA14  7F E3 FB 78 */	mr r3, r31
/* 8012FAB8 0012CA18  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012FABC 0012CA1C  38 80 00 00 */	li r4, 0
/* 8012FAC0 0012CA20  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012FAC4 0012CA24  7D 88 03 A6 */	mtlr r12
/* 8012FAC8 0012CA28  4E 80 00 21 */	blrl 
/* 8012FACC 0012CA2C  48 00 00 1C */	b .L_8012FAE8
.L_8012FAD0:
/* 8012FAD0 0012CA30  7F E3 FB 78 */	mr r3, r31
/* 8012FAD4 0012CA34  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012FAD8 0012CA38  7F C4 F3 78 */	mr r4, r30
/* 8012FADC 0012CA3C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012FAE0 0012CA40  7D 88 03 A6 */	mtlr r12
/* 8012FAE4 0012CA44  4E 80 00 21 */	blrl 
.L_8012FAE8:
/* 8012FAE8 0012CA48  28 03 00 00 */	cmplwi r3, 0
/* 8012FAEC 0012CA4C  41 82 00 90 */	beq .L_8012FB7C
/* 8012FAF0 0012CA50  80 03 00 C8 */	lwz r0, 0xc8(r3)
/* 8012FAF4 0012CA54  54 00 04 21 */	rlwinm. r0, r0, 0, 0x10, 0x10
/* 8012FAF8 0012CA58  40 82 00 0C */	bne .L_8012FB04
/* 8012FAFC 0012CA5C  38 60 00 01 */	li r3, 1
/* 8012FB00 0012CA60  48 00 00 80 */	b .L_8012FB80
.L_8012FB04:
/* 8012FB04 0012CA64  7F E3 FB 78 */	mr r3, r31
/* 8012FB08 0012CA68  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012FB0C 0012CA6C  7F C4 F3 78 */	mr r4, r30
/* 8012FB10 0012CA70  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8012FB14 0012CA74  7D 88 03 A6 */	mtlr r12
/* 8012FB18 0012CA78  4E 80 00 21 */	blrl 
/* 8012FB1C 0012CA7C  7C 7E 1B 78 */	mr r30, r3
.L_8012FB20:
/* 8012FB20 0012CA80  7F E3 FB 78 */	mr r3, r31
/* 8012FB24 0012CA84  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012FB28 0012CA88  7F C4 F3 78 */	mr r4, r30
/* 8012FB2C 0012CA8C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8012FB30 0012CA90  7D 88 03 A6 */	mtlr r12
/* 8012FB34 0012CA94  4E 80 00 21 */	blrl 
/* 8012FB38 0012CA98  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8012FB3C 0012CA9C  41 82 00 0C */	beq .L_8012FB48
/* 8012FB40 0012CAA0  38 00 00 01 */	li r0, 1
/* 8012FB44 0012CAA4  48 00 00 30 */	b .L_8012FB74
.L_8012FB48:
/* 8012FB48 0012CAA8  7F E3 FB 78 */	mr r3, r31
/* 8012FB4C 0012CAAC  81 9F 00 00 */	lwz r12, 0(r31)
/* 8012FB50 0012CAB0  7F C4 F3 78 */	mr r4, r30
/* 8012FB54 0012CAB4  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012FB58 0012CAB8  7D 88 03 A6 */	mtlr r12
/* 8012FB5C 0012CABC  4E 80 00 21 */	blrl 
/* 8012FB60 0012CAC0  28 03 00 00 */	cmplwi r3, 0
/* 8012FB64 0012CAC4  40 82 00 0C */	bne .L_8012FB70
/* 8012FB68 0012CAC8  38 00 00 01 */	li r0, 1
/* 8012FB6C 0012CACC  48 00 00 08 */	b .L_8012FB74
.L_8012FB70:
/* 8012FB70 0012CAD0  38 00 00 00 */	li r0, 0
.L_8012FB74:
/* 8012FB74 0012CAD4  54 00 06 3F */	clrlwi. r0, r0, 0x18
/* 8012FB78 0012CAD8  41 82 FF 34 */	beq .L_8012FAAC
.L_8012FB7C:
/* 8012FB7C 0012CADC  38 60 00 00 */	li r3, 0
.L_8012FB80:
/* 8012FB80 0012CAE0  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8012FB84 0012CAE4  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8012FB88 0012CAE8  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 8012FB8C 0012CAEC  38 21 00 40 */	addi r1, r1, 0x40
/* 8012FB90 0012CAF0  7C 08 03 A6 */	mtlr r0
/* 8012FB94 0012CAF4  4E 80 00 20 */	blr 
.endfn act__26TaiHasStickersOnBodyActionFR4Teki

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802C8300, local
	.asciz "taijudgementactions.cpp"
.endobj lbl_802C8300
.balign 4
.obj lbl_802C8318, local
	.asciz "taijudgementactions"
.endobj lbl_802C8318
.balign 4
.obj lbl_802C832C, local
	.asciz "TaiHasStickersOnBodyAction"
.endobj lbl_802C832C
.balign 4
.obj lbl_802C8348, local
	.asciz "TaiAction"
.endobj lbl_802C8348
.balign 4
.obj lbl_802C8354, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C8354
.balign 4
.obj __vt__26TaiHasStickersOnBodyAction, global
	.4byte __RTTI__26TaiHasStickersOnBodyAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__26TaiHasStickersOnBodyActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__26TaiHasStickersOnBodyAction
.balign 4
.obj lbl_802C837C, local
	.asciz "TaiHasStickersInMouthAction"
.endobj lbl_802C837C
.balign 4
.obj lbl_802C8398, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C8398
.balign 4
.obj __vt__27TaiHasStickersInMouthAction, global
	.4byte __RTTI__27TaiHasStickersInMouthAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__27TaiHasStickersInMouthActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__27TaiHasStickersInMouthAction
.balign 4
.obj lbl_802C83C0, local
	.asciz "TekiAndCondition"
.endobj lbl_802C83C0
.balign 4
.obj lbl_802C83D4, local
	.asciz "Condition"
.endobj lbl_802C83D4
.balign 4
.obj lbl_802C83E0, local
	.asciz "TekiCondition"
.endobj lbl_802C83E0
.balign 4
.obj lbl_802C83F0, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte 0
.endobj lbl_802C83F0
.balign 4
.obj lbl_802C83FC, local
	.4byte __RTTI__9Condition
	.4byte 0
	.4byte __RTTI__13TekiCondition
	.4byte 0
	.4byte 0
.endobj lbl_802C83FC
.balign 4
.skip 0xC # compiler padding
.balign 4
.obj lbl_802C841C, local
	.asciz "TaiTargetVisibleNaviAction"
.endobj lbl_802C841C
.balign 4
.obj lbl_802C8438, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C8438
.balign 4
.obj __vt__26TaiTargetVisibleNaviAction, global
	.4byte __RTTI__26TaiTargetVisibleNaviAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__26TaiTargetVisibleNaviActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__26TaiTargetVisibleNaviAction
.balign 4
.skip 0x18 # compiler padding
.balign 4
.obj lbl_802C8478, local
	.asciz "TaiTargetVisibleNaviPikiAction"
.endobj lbl_802C8478
.balign 4
.obj lbl_802C8498, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C8498
.balign 4
.obj __vt__30TaiTargetVisibleNaviPikiAction, global
	.4byte __RTTI__30TaiTargetVisibleNaviPikiAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__30TaiTargetVisibleNaviPikiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__30TaiTargetVisibleNaviPikiAction
.balign 4
.obj lbl_802C84C0, local
	.asciz "TaiInsideTerritoryAction"
.endobj lbl_802C84C0
.balign 4
.obj lbl_802C84DC, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C84DC
.balign 4
.obj __vt__24TaiInsideTerritoryAction, global
	.4byte __RTTI__24TaiInsideTerritoryAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__24TaiInsideTerritoryActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__24TaiInsideTerritoryAction
.balign 4
.obj lbl_802C8504, local
	.asciz "TaiOutsideTerritoryAction"
.endobj lbl_802C8504
.balign 4
.obj lbl_802C8520, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C8520
.balign 4
.obj __vt__25TaiOutsideTerritoryAction, global
	.4byte __RTTI__25TaiOutsideTerritoryAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__25TaiOutsideTerritoryActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__25TaiOutsideTerritoryAction
.balign 4
.obj lbl_802C8548, local
	.asciz "TaiTargetLostAction"
.endobj lbl_802C8548
.balign 4
.obj lbl_802C855C, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C855C
.balign 4
.obj __vt__19TaiTargetLostAction, global
	.4byte __RTTI__19TaiTargetLostAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__19TaiTargetLostActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__19TaiTargetLostAction
.balign 4
.obj lbl_802C8584, local
	.asciz "TaiSeparateTargetAction"
.endobj lbl_802C8584
.balign 4
.obj lbl_802C859C, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C859C
.balign 4
.obj __vt__23TaiSeparateTargetAction, global
	.4byte __RTTI__23TaiSeparateTargetAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__23TaiSeparateTargetActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__23TaiSeparateTargetAction
.balign 4
.obj lbl_802C85C4, local
	.asciz "TaiContactTargetAction"
.endobj lbl_802C85C4
.balign 4
.obj lbl_802C85DC, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C85DC
.balign 4
.obj __vt__22TaiContactTargetAction, global
	.4byte __RTTI__22TaiContactTargetAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__22TaiContactTargetActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__22TaiContactTargetAction
.balign 4
.obj lbl_802C8604, local
	.asciz "TaiVisibleTargetAction"
.endobj lbl_802C8604
.balign 4
.obj lbl_802C861C, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802C861C
.balign 4
.obj __vt__22TaiVisibleTargetAction, global
	.4byte __RTTI__22TaiVisibleTargetAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__22TaiVisibleTargetActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__22TaiVisibleTargetAction

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__9TaiAction, local
	.4byte lbl_802C8348
	.4byte 0
.endobj __RTTI__9TaiAction
.balign 4
.obj __RTTI__26TaiHasStickersOnBodyAction, local
	.4byte lbl_802C832C
	.4byte lbl_802C8354
.endobj __RTTI__26TaiHasStickersOnBodyAction
.balign 4
.obj __RTTI__27TaiHasStickersInMouthAction, local
	.4byte lbl_802C837C
	.4byte lbl_802C8398
.endobj __RTTI__27TaiHasStickersInMouthAction
.balign 4
.obj __RTTI__9Condition, local
	.4byte lbl_802C83D4
	.4byte 0
.endobj __RTTI__9Condition
.balign 4
.obj __RTTI__13TekiCondition, local
	.4byte lbl_802C83E0
	.4byte lbl_802C83F0
.endobj __RTTI__13TekiCondition
.balign 4
.obj __RTTI__26TaiTargetVisibleNaviAction, local
	.4byte lbl_802C841C
	.4byte lbl_802C8438
.endobj __RTTI__26TaiTargetVisibleNaviAction
.balign 4
.obj __RTTI__30TaiTargetVisibleNaviPikiAction, local
	.4byte lbl_802C8478
	.4byte lbl_802C8498
.endobj __RTTI__30TaiTargetVisibleNaviPikiAction
.balign 4
.obj __RTTI__24TaiInsideTerritoryAction, local
	.4byte lbl_802C84C0
	.4byte lbl_802C84DC
.endobj __RTTI__24TaiInsideTerritoryAction
.balign 4
.obj __RTTI__25TaiOutsideTerritoryAction, local
	.4byte lbl_802C8504
	.4byte lbl_802C8520
.endobj __RTTI__25TaiOutsideTerritoryAction
.balign 4
.obj __RTTI__19TaiTargetLostAction, local
	.4byte lbl_802C8548
	.4byte lbl_802C855C
.endobj __RTTI__19TaiTargetLostAction
.balign 4
.obj __RTTI__23TaiSeparateTargetAction, local
	.4byte lbl_802C8584
	.4byte lbl_802C859C
.endobj __RTTI__23TaiSeparateTargetAction
.balign 4
.obj __RTTI__22TaiContactTargetAction, local
	.4byte lbl_802C85C4
	.4byte lbl_802C85DC
.endobj __RTTI__22TaiContactTargetAction
.balign 4
.obj __RTTI__22TaiVisibleTargetAction, local
	.4byte lbl_802C8604
	.4byte lbl_802C861C
.endobj __RTTI__22TaiVisibleTargetAction

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA548, local
	.float 0.0
.endobj lbl_803EA548
