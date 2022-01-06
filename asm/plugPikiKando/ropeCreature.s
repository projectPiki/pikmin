.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__12RopeCreatureFP12CreatureProp
__ct__12RopeCreatureFP12CreatureProp:
/* 800946A4 00091604  7C 08 02 A6 */	mflr r0
/* 800946A8 00091608  90 01 00 04 */	stw r0, 4(r1)
/* 800946AC 0009160C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800946B0 00091610  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800946B4 00091614  7C 7F 1B 78 */	mr r31, r3
/* 800946B8 00091618  4B FF 68 21 */	bl __ct__8CreatureFP12CreatureProp
/* 800946BC 0009161C  3C 60 80 2B */	lis r3, __vt__12RopeCreature@ha
/* 800946C0 00091620  38 03 FA DC */	addi r0, r3, __vt__12RopeCreature@l
/* 800946C4 00091624  90 1F 00 00 */	stw r0, 0(r31)
/* 800946C8 00091628  38 00 00 00 */	li r0, 0
/* 800946CC 0009162C  38 7F 00 00 */	addi r3, r31, 0
/* 800946D0 00091630  C0 02 8B E8 */	lfs f0, lbl_803E8DE8@sda21(r2)
/* 800946D4 00091634  D0 1F 02 CC */	stfs f0, 0x2cc(r31)
/* 800946D8 00091638  D0 1F 02 C8 */	stfs f0, 0x2c8(r31)
/* 800946DC 0009163C  D0 1F 02 C4 */	stfs f0, 0x2c4(r31)
/* 800946E0 00091640  90 1F 02 B8 */	stw r0, 0x2b8(r31)
/* 800946E4 00091644  90 1F 02 BC */	stw r0, 0x2bc(r31)
/* 800946E8 00091648  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800946EC 0009164C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800946F0 00091650  38 21 00 18 */	addi r1, r1, 0x18
/* 800946F4 00091654  7C 08 03 A6 */	mtlr r0
/* 800946F8 00091658  4E 80 00 20 */	blr 

.global setRope__12RopeCreatureFP8Creature
setRope__12RopeCreatureFP8Creature:
/* 800946FC 0009165C  7C 08 02 A6 */	mflr r0
/* 80094700 00091660  90 01 00 04 */	stw r0, 4(r1)
/* 80094704 00091664  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 80094708 00091668  93 E1 00 6C */	stw r31, 0x6c(r1)
/* 8009470C 0009166C  3B E4 00 00 */	addi r31, r4, 0
/* 80094710 00091670  93 C1 00 68 */	stw r30, 0x68(r1)
/* 80094714 00091674  3B C3 00 00 */	addi r30, r3, 0
/* 80094718 00091678  38 9E 00 00 */	addi r4, r30, 0
/* 8009471C 0009167C  81 9E 00 00 */	lwz r12, 0(r30)
/* 80094720 00091680  38 61 00 34 */	addi r3, r1, 0x34
/* 80094724 00091684  81 8C 00 58 */	lwz r12, 0x58(r12)
/* 80094728 00091688  7D 88 03 A6 */	mtlr r12
/* 8009472C 0009168C  4E 80 00 21 */	blrl 
/* 80094730 00091690  7F E4 FB 78 */	mr r4, r31
/* 80094734 00091694  81 9F 00 00 */	lwz r12, 0(r31)
/* 80094738 00091698  38 61 00 40 */	addi r3, r1, 0x40
/* 8009473C 0009169C  81 8C 00 58 */	lwz r12, 0x58(r12)
/* 80094740 000916A0  7D 88 03 A6 */	mtlr r12
/* 80094744 000916A4  4E 80 00 21 */	blrl 
/* 80094748 000916A8  C0 41 00 40 */	lfs f2, 0x40(r1)
/* 8009474C 000916AC  C0 01 00 34 */	lfs f0, 0x34(r1)
/* 80094750 000916B0  C0 21 00 44 */	lfs f1, 0x44(r1)
/* 80094754 000916B4  EC 42 00 28 */	fsubs f2, f2, f0
/* 80094758 000916B8  C0 01 00 38 */	lfs f0, 0x38(r1)
/* 8009475C 000916BC  C0 81 00 48 */	lfs f4, 0x48(r1)
/* 80094760 000916C0  C0 61 00 3C */	lfs f3, 0x3c(r1)
/* 80094764 000916C4  EC 01 00 28 */	fsubs f0, f1, f0
/* 80094768 000916C8  D0 41 00 58 */	stfs f2, 0x58(r1)
/* 8009476C 000916CC  EC 24 18 28 */	fsubs f1, f4, f3
/* 80094770 000916D0  D0 01 00 5C */	stfs f0, 0x5c(r1)
/* 80094774 000916D4  D0 21 00 60 */	stfs f1, 0x60(r1)
/* 80094778 000916D8  80 61 00 58 */	lwz r3, 0x58(r1)
/* 8009477C 000916DC  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 80094780 000916E0  90 7E 02 C4 */	stw r3, 0x2c4(r30)
/* 80094784 000916E4  90 1E 02 C8 */	stw r0, 0x2c8(r30)
/* 80094788 000916E8  80 01 00 60 */	lwz r0, 0x60(r1)
/* 8009478C 000916EC  90 1E 02 CC */	stw r0, 0x2cc(r30)
/* 80094790 000916F0  C0 3E 02 C4 */	lfs f1, 0x2c4(r30)
/* 80094794 000916F4  C0 1E 02 C8 */	lfs f0, 0x2c8(r30)
/* 80094798 000916F8  C0 5E 02 CC */	lfs f2, 0x2cc(r30)
/* 8009479C 000916FC  EC 21 00 72 */	fmuls f1, f1, f1
/* 800947A0 00091700  EC 00 00 32 */	fmuls f0, f0, f0
/* 800947A4 00091704  EC 42 00 B2 */	fmuls f2, f2, f2
/* 800947A8 00091708  EC 01 00 2A */	fadds f0, f1, f0
/* 800947AC 0009170C  EC 22 00 2A */	fadds f1, f2, f0
/* 800947B0 00091710  4B F7 94 91 */	bl sqrtf__3stdFf
/* 800947B4 00091714  C0 02 8B E8 */	lfs f0, lbl_803E8DE8@sda21(r2)
/* 800947B8 00091718  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 800947BC 0009171C  41 82 00 28 */	beq lbl_800947E4
/* 800947C0 00091720  C0 1E 02 C4 */	lfs f0, 0x2c4(r30)
/* 800947C4 00091724  EC 00 08 24 */	fdivs f0, f0, f1
/* 800947C8 00091728  D0 1E 02 C4 */	stfs f0, 0x2c4(r30)
/* 800947CC 0009172C  C0 1E 02 C8 */	lfs f0, 0x2c8(r30)
/* 800947D0 00091730  EC 00 08 24 */	fdivs f0, f0, f1
/* 800947D4 00091734  D0 1E 02 C8 */	stfs f0, 0x2c8(r30)
/* 800947D8 00091738  C0 1E 02 CC */	lfs f0, 0x2cc(r30)
/* 800947DC 0009173C  EC 00 08 24 */	fdivs f0, f0, f1
/* 800947E0 00091740  D0 1E 02 CC */	stfs f0, 0x2cc(r30)
lbl_800947E4:
/* 800947E4 00091744  C0 21 00 58 */	lfs f1, 0x58(r1)
/* 800947E8 00091748  C0 01 00 5C */	lfs f0, 0x5c(r1)
/* 800947EC 0009174C  EC 41 00 72 */	fmuls f2, f1, f1
/* 800947F0 00091750  C0 61 00 60 */	lfs f3, 0x60(r1)
/* 800947F4 00091754  EC 20 00 32 */	fmuls f1, f0, f0
/* 800947F8 00091758  C0 02 8B E8 */	lfs f0, lbl_803E8DE8@sda21(r2)
/* 800947FC 0009175C  EC 63 00 F2 */	fmuls f3, f3, f3
/* 80094800 00091760  EC 22 08 2A */	fadds f1, f2, f1
/* 80094804 00091764  EC 83 08 2A */	fadds f4, f3, f1
/* 80094808 00091768  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 8009480C 0009176C  40 81 00 5C */	ble lbl_80094868
/* 80094810 00091770  FC 20 20 34 */	frsqrte f1, f4
/* 80094814 00091774  C8 62 8B F0 */	lfd f3, lbl_803E8DF0@sda21(r2)
/* 80094818 00091778  C8 42 8B F8 */	lfd f2, lbl_803E8DF8@sda21(r2)
/* 8009481C 0009177C  FC 01 00 72 */	fmul f0, f1, f1
/* 80094820 00091780  FC 23 00 72 */	fmul f1, f3, f1
/* 80094824 00091784  FC 04 00 32 */	fmul f0, f4, f0
/* 80094828 00091788  FC 02 00 28 */	fsub f0, f2, f0
/* 8009482C 0009178C  FC 21 00 32 */	fmul f1, f1, f0
/* 80094830 00091790  FC 01 00 72 */	fmul f0, f1, f1
/* 80094834 00091794  FC 23 00 72 */	fmul f1, f3, f1
/* 80094838 00091798  FC 04 00 32 */	fmul f0, f4, f0
/* 8009483C 0009179C  FC 02 00 28 */	fsub f0, f2, f0
/* 80094840 000917A0  FC 21 00 32 */	fmul f1, f1, f0
/* 80094844 000917A4  FC 01 00 72 */	fmul f0, f1, f1
/* 80094848 000917A8  FC 23 00 72 */	fmul f1, f3, f1
/* 8009484C 000917AC  FC 04 00 32 */	fmul f0, f4, f0
/* 80094850 000917B0  FC 02 00 28 */	fsub f0, f2, f0
/* 80094854 000917B4  FC 01 00 32 */	fmul f0, f1, f0
/* 80094858 000917B8  FC 04 00 32 */	fmul f0, f4, f0
/* 8009485C 000917BC  FC 00 00 18 */	frsp f0, f0
/* 80094860 000917C0  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 80094864 000917C4  C0 81 00 20 */	lfs f4, 0x20(r1)
lbl_80094868:
/* 80094868 000917C8  D0 9E 02 C0 */	stfs f4, 0x2c0(r30)
/* 8009486C 000917CC  93 FE 02 B8 */	stw r31, 0x2b8(r30)
/* 80094870 000917D0  80 7E 02 B8 */	lwz r3, 0x2b8(r30)
/* 80094874 000917D4  80 03 00 6C */	lwz r0, 0x6c(r3)
/* 80094878 000917D8  2C 00 00 12 */	cmpwi r0, 0x12
/* 8009487C 000917DC  40 82 00 08 */	bne lbl_80094884
/* 80094880 000917E0  93 C3 02 BC */	stw r30, 0x2bc(r3)
lbl_80094884:
/* 80094884 000917E4  C0 02 8C 00 */	lfs f0, lbl_803E8E00@sda21(r2)
/* 80094888 000917E8  D0 1E 02 C0 */	stfs f0, 0x2c0(r30)
/* 8009488C 000917EC  80 01 00 74 */	lwz r0, 0x74(r1)
/* 80094890 000917F0  83 E1 00 6C */	lwz r31, 0x6c(r1)
/* 80094894 000917F4  83 C1 00 68 */	lwz r30, 0x68(r1)
/* 80094898 000917F8  38 21 00 70 */	addi r1, r1, 0x70
/* 8009489C 000917FC  7C 08 03 A6 */	mtlr r0
/* 800948A0 00091800  4E 80 00 20 */	blr 

.global update__12RopeCreatureFv
update__12RopeCreatureFv:
/* 800948A4 00091804  7C 08 02 A6 */	mflr r0
/* 800948A8 00091808  90 01 00 04 */	stw r0, 4(r1)
/* 800948AC 0009180C  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 800948B0 00091810  93 E1 00 44 */	stw r31, 0x44(r1)
/* 800948B4 00091814  7C 7F 1B 78 */	mr r31, r3
/* 800948B8 00091818  4B FF 69 51 */	bl update__8CreatureFv
/* 800948BC 0009181C  80 7F 02 B8 */	lwz r3, 0x2b8(r31)
/* 800948C0 00091820  C0 1F 00 94 */	lfs f0, 0x94(r31)
/* 800948C4 00091824  C4 23 00 94 */	lfsu f1, 0x94(r3)
/* 800948C8 00091828  EC 01 00 28 */	fsubs f0, f1, f0
/* 800948CC 0009182C  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 800948D0 00091830  C0 01 00 24 */	lfs f0, 0x24(r1)
/* 800948D4 00091834  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 800948D8 00091838  C0 23 00 04 */	lfs f1, 4(r3)
/* 800948DC 0009183C  C0 1F 00 98 */	lfs f0, 0x98(r31)
/* 800948E0 00091840  EC 01 00 28 */	fsubs f0, f1, f0
/* 800948E4 00091844  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 800948E8 00091848  C0 23 00 08 */	lfs f1, 8(r3)
/* 800948EC 0009184C  C0 1F 00 9C */	lfs f0, 0x9c(r31)
/* 800948F0 00091850  EC 01 00 28 */	fsubs f0, f1, f0
/* 800948F4 00091854  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 800948F8 00091858  80 61 00 30 */	lwz r3, 0x30(r1)
/* 800948FC 0009185C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80094900 00091860  90 7F 02 C4 */	stw r3, 0x2c4(r31)
/* 80094904 00091864  90 1F 02 C8 */	stw r0, 0x2c8(r31)
/* 80094908 00091868  80 01 00 38 */	lwz r0, 0x38(r1)
/* 8009490C 0009186C  90 1F 02 CC */	stw r0, 0x2cc(r31)
/* 80094910 00091870  C0 3F 02 C4 */	lfs f1, 0x2c4(r31)
/* 80094914 00091874  C0 1F 02 C8 */	lfs f0, 0x2c8(r31)
/* 80094918 00091878  C0 5F 02 CC */	lfs f2, 0x2cc(r31)
/* 8009491C 0009187C  EC 21 00 72 */	fmuls f1, f1, f1
/* 80094920 00091880  EC 00 00 32 */	fmuls f0, f0, f0
/* 80094924 00091884  EC 42 00 B2 */	fmuls f2, f2, f2
/* 80094928 00091888  EC 01 00 2A */	fadds f0, f1, f0
/* 8009492C 0009188C  EC 22 00 2A */	fadds f1, f2, f0
/* 80094930 00091890  4B F7 93 11 */	bl sqrtf__3stdFf
/* 80094934 00091894  C0 02 8B E8 */	lfs f0, lbl_803E8DE8@sda21(r2)
/* 80094938 00091898  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 8009493C 0009189C  41 82 00 28 */	beq lbl_80094964
/* 80094940 000918A0  C0 1F 02 C4 */	lfs f0, 0x2c4(r31)
/* 80094944 000918A4  EC 00 08 24 */	fdivs f0, f0, f1
/* 80094948 000918A8  D0 1F 02 C4 */	stfs f0, 0x2c4(r31)
/* 8009494C 000918AC  C0 1F 02 C8 */	lfs f0, 0x2c8(r31)
/* 80094950 000918B0  EC 00 08 24 */	fdivs f0, f0, f1
/* 80094954 000918B4  D0 1F 02 C8 */	stfs f0, 0x2c8(r31)
/* 80094958 000918B8  C0 1F 02 CC */	lfs f0, 0x2cc(r31)
/* 8009495C 000918BC  EC 00 08 24 */	fdivs f0, f0, f1
/* 80094960 000918C0  D0 1F 02 CC */	stfs f0, 0x2cc(r31)
lbl_80094964:
/* 80094964 000918C4  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80094968 000918C8  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 8009496C 000918CC  38 21 00 48 */	addi r1, r1, 0x48
/* 80094970 000918D0  7C 08 03 A6 */	mtlr r0
/* 80094974 000918D4  4E 80 00 20 */	blr 

.global getRopePos__12RopeCreatureFf
getRopePos__12RopeCreatureFf:
/* 80094978 000918D8  7C 08 02 A6 */	mflr r0
/* 8009497C 000918DC  90 01 00 04 */	stw r0, 4(r1)
/* 80094980 000918E0  94 21 FF 98 */	stwu r1, -0x68(r1)
/* 80094984 000918E4  DB E1 00 60 */	stfd f31, 0x60(r1)
/* 80094988 000918E8  38 01 00 1C */	addi r0, r1, 0x1c
/* 8009498C 000918EC  38 C1 00 24 */	addi r6, r1, 0x24
/* 80094990 000918F0  DB C1 00 58 */	stfd f30, 0x58(r1)
/* 80094994 000918F4  38 A1 00 20 */	addi r5, r1, 0x20
/* 80094998 000918F8  DB A1 00 50 */	stfd f29, 0x50(r1)
/* 8009499C 000918FC  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 800949A0 00091900  7C 7F 1B 78 */	mr r31, r3
/* 800949A4 00091904  38 61 00 2C */	addi r3, r1, 0x2c
/* 800949A8 00091908  C0 44 02 C0 */	lfs f2, 0x2c0(r4)
/* 800949AC 0009190C  C0 04 02 CC */	lfs f0, 0x2cc(r4)
/* 800949B0 00091910  EC 22 00 72 */	fmuls f1, f2, f1
/* 800949B4 00091914  C3 E4 00 94 */	lfs f31, 0x94(r4)
/* 800949B8 00091918  C3 C4 00 98 */	lfs f30, 0x98(r4)
/* 800949BC 0009191C  C3 A4 00 9C */	lfs f29, 0x9c(r4)
/* 800949C0 00091920  EC 00 00 72 */	fmuls f0, f0, f1
/* 800949C4 00091924  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 800949C8 00091928  C0 04 02 C8 */	lfs f0, 0x2c8(r4)
/* 800949CC 0009192C  EC 00 00 72 */	fmuls f0, f0, f1
/* 800949D0 00091930  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 800949D4 00091934  C0 04 02 C4 */	lfs f0, 0x2c4(r4)
/* 800949D8 00091938  7C 04 03 78 */	mr r4, r0
/* 800949DC 0009193C  EC 00 00 72 */	fmuls f0, f0, f1
/* 800949E0 00091940  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 800949E4 00091944  4B FA 27 39 */	bl __ct__8Vector3fFRCfRCfRCf
/* 800949E8 00091948  C0 01 00 2C */	lfs f0, 0x2c(r1)
/* 800949EC 0009194C  C0 21 00 30 */	lfs f1, 0x30(r1)
/* 800949F0 00091950  EC 1F 00 2A */	fadds f0, f31, f0
/* 800949F4 00091954  C0 41 00 34 */	lfs f2, 0x34(r1)
/* 800949F8 00091958  EC 7E 08 2A */	fadds f3, f30, f1
/* 800949FC 0009195C  EC 3D 10 2A */	fadds f1, f29, f2
/* 80094A00 00091960  D0 1F 00 00 */	stfs f0, 0(r31)
/* 80094A04 00091964  D0 7F 00 04 */	stfs f3, 4(r31)
/* 80094A08 00091968  D0 3F 00 08 */	stfs f1, 8(r31)
/* 80094A0C 0009196C  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 80094A10 00091970  CB E1 00 60 */	lfd f31, 0x60(r1)
/* 80094A14 00091974  CB C1 00 58 */	lfd f30, 0x58(r1)
/* 80094A18 00091978  CB A1 00 50 */	lfd f29, 0x50(r1)
/* 80094A1C 0009197C  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 80094A20 00091980  38 21 00 68 */	addi r1, r1, 0x68
/* 80094A24 00091984  7C 08 03 A6 */	mtlr r0
/* 80094A28 00091988  4E 80 00 20 */	blr 

.global refresh__12RopeCreatureFR8Graphics
refresh__12RopeCreatureFR8Graphics:
/* 80094A2C 0009198C  4E 80 00 20 */	blr 

.global needShadow__12RopeCreatureFv
needShadow__12RopeCreatureFv:
/* 80094A30 00091990  38 60 00 00 */	li r3, 0
/* 80094A34 00091994  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802AFA50:
	.asciz "ropeCreature.cpp"
.balign 4
lbl_802AFA64:
	.asciz "ropeCreature"
.balign 4
lbl_802AFA74:
	.asciz "RopeCreature"
.balign 4
lbl_802AFA84:
	.asciz "EventTalker"
.balign 4
lbl_802AFA90:
	.asciz "RefCountable"
.balign 4
lbl_802AFAA0:
	.asciz "Creature"
.balign 4
lbl_802AFAAC:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte 0
lbl_802AFAC0:
	.4byte __RTTI__11EventTalker
	.4byte 0x8
	.4byte __RTTI__12RefCountable
	.4byte 0
	.4byte __RTTI__8Creature
	.4byte 0
	.4byte 0
.global __vt__12RopeCreature
__vt__12RopeCreature:
	.4byte __RTTI__12RopeCreature
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
	.4byte getiMass__8CreatureFv
	.4byte getSize__8CreatureFv
	.4byte getHeight__8CreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8CreatureFR18RandomAccessStream
	.4byte doLoad__8CreatureFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__8CreatureFv
	.4byte isVisible__8CreatureFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8CreatureFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__12RopeCreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__8CreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__8CreatureFR9CollEvent
	.4byte bounceCallback__8CreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
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
	.4byte update__12RopeCreatureFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__12RopeCreatureFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__8CreatureFv
	.4byte doAnimation__8CreatureFv
	.4byte 0
	.4byte exitCourse__8CreatureFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__11EventTalker:
	.4byte lbl_802AFA84
	.4byte 0
__RTTI__12RefCountable:
	.4byte lbl_802AFA90
	.4byte 0
__RTTI__8Creature:
	.4byte lbl_802AFAA0
	.4byte lbl_802AFAAC
__RTTI__12RopeCreature:
	.4byte lbl_802AFA74
	.4byte lbl_802AFAC0

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E8DE8:
	.float 0.0
.balign 8
lbl_803E8DF0:
	.double 0.5
lbl_803E8DF8:
	.double 3.0
lbl_803E8E00:
	.float 50.0
