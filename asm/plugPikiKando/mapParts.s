.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global getShapeFile__8MapPartsFi
getShapeFile__8MapPartsFi:
/* 801184A8 00115408  3C 80 80 2C */	lis r4, shapeFiles__8MapParts@ha
/* 801184AC 0011540C  54 63 10 3A */	slwi r3, r3, 2
/* 801184B0 00115410  38 04 32 48 */	addi r0, r4, shapeFiles__8MapParts@l
/* 801184B4 00115414  7C 60 1A 14 */	add r3, r0, r3
/* 801184B8 00115418  80 63 00 00 */	lwz r3, 0(r3)
/* 801184BC 0011541C  4E 80 00 20 */	blr 

.global applyVelocity__8MapPartsFR5PlaneR8Vector3fR8Vector3f
applyVelocity__8MapPartsFR5PlaneR8Vector3fR8Vector3f:
/* 801184C0 00115420  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 801184C4 00115424  C0 23 01 44 */	lfs f1, 0x144(r3)
/* 801184C8 00115428  C0 06 00 00 */	lfs f0, 0(r6)
/* 801184CC 0011542C  EC 01 00 2A */	fadds f0, f1, f0
/* 801184D0 00115430  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 801184D4 00115434  C0 01 00 24 */	lfs f0, 0x24(r1)
/* 801184D8 00115438  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 801184DC 0011543C  C0 23 01 48 */	lfs f1, 0x148(r3)
/* 801184E0 00115440  C0 06 00 04 */	lfs f0, 4(r6)
/* 801184E4 00115444  EC 01 00 2A */	fadds f0, f1, f0
/* 801184E8 00115448  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 801184EC 0011544C  C0 23 01 4C */	lfs f1, 0x14c(r3)
/* 801184F0 00115450  C0 06 00 08 */	lfs f0, 8(r6)
/* 801184F4 00115454  EC 01 00 2A */	fadds f0, f1, f0
/* 801184F8 00115458  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 801184FC 0011545C  80 81 00 30 */	lwz r4, 0x30(r1)
/* 80118500 00115460  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80118504 00115464  90 83 01 44 */	stw r4, 0x144(r3)
/* 80118508 00115468  90 03 01 48 */	stw r0, 0x148(r3)
/* 8011850C 0011546C  80 01 00 38 */	lwz r0, 0x38(r1)
/* 80118510 00115470  90 03 01 4C */	stw r0, 0x14c(r3)
/* 80118514 00115474  38 21 00 40 */	addi r1, r1, 0x40
/* 80118518 00115478  4E 80 00 20 */	blr 

.global __ct__9MapEntityFP5Shape
__ct__9MapEntityFP5Shape:
/* 8011851C 0011547C  7C 08 02 A6 */	mflr r0
/* 80118520 00115480  90 01 00 04 */	stw r0, 4(r1)
/* 80118524 00115484  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80118528 00115488  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011852C 0011548C  7C 7F 1B 78 */	mr r31, r3
/* 80118530 00115490  4B F4 9A B9 */	bl __ct__12DynCollShapeFP5Shape
/* 80118534 00115494  3C 60 80 2C */	lis r3, __vt__8MapParts@ha
/* 80118538 00115498  38 03 34 9C */	addi r0, r3, __vt__8MapParts@l
/* 8011853C 0011549C  90 1F 00 00 */	stw r0, 0(r31)
/* 80118540 001154A0  3C 60 80 2C */	lis r3, __vt__9MapEntity@ha
/* 80118544 001154A4  38 80 00 00 */	li r4, 0
/* 80118548 001154A8  C0 02 9F B8 */	lfs f0, lbl_803EA1B8@sda21(r2)
/* 8011854C 001154AC  38 03 33 F4 */	addi r0, r3, __vt__9MapEntity@l
/* 80118550 001154B0  38 7F 00 00 */	addi r3, r31, 0
/* 80118554 001154B4  D0 1F 01 4C */	stfs f0, 0x14c(r31)
/* 80118558 001154B8  D0 1F 01 48 */	stfs f0, 0x148(r31)
/* 8011855C 001154BC  D0 1F 01 44 */	stfs f0, 0x144(r31)
/* 80118560 001154C0  90 9F 01 40 */	stw r4, 0x140(r31)
/* 80118564 001154C4  90 1F 00 00 */	stw r0, 0(r31)
/* 80118568 001154C8  C0 0D DD E0 */	lfs f0, lbl_803E2B00@sda21(r13)
/* 8011856C 001154CC  D0 1F 01 44 */	stfs f0, 0x144(r31)
/* 80118570 001154D0  C0 0D DD E4 */	lfs f0, lbl_803E2B04@sda21(r13)
/* 80118574 001154D4  D0 1F 01 48 */	stfs f0, 0x148(r31)
/* 80118578 001154D8  C0 0D DD E8 */	lfs f0, lbl_803E2B08@sda21(r13)
/* 8011857C 001154DC  D0 1F 01 4C */	stfs f0, 0x14c(r31)
/* 80118580 001154E0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80118584 001154E4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80118588 001154E8  38 21 00 18 */	addi r1, r1, 0x18
/* 8011858C 001154EC  7C 08 03 A6 */	mtlr r0
/* 80118590 001154F0  4E 80 00 20 */	blr 

.global update__9MapEntityFv
update__9MapEntityFv:
/* 80118594 001154F4  7C 08 02 A6 */	mflr r0
/* 80118598 001154F8  90 01 00 04 */	stw r0, 4(r1)
/* 8011859C 001154FC  94 21 FF 58 */	stwu r1, -0xa8(r1)
/* 801185A0 00115500  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 801185A4 00115504  C0 03 01 44 */	lfs f0, 0x144(r3)
/* 801185A8 00115508  C0 64 02 8C */	lfs f3, 0x28c(r4)
/* 801185AC 0011550C  C0 43 01 4C */	lfs f2, 0x14c(r3)
/* 801185B0 00115510  EC 00 00 F2 */	fmuls f0, f0, f3
/* 801185B4 00115514  C0 23 01 48 */	lfs f1, 0x148(r3)
/* 801185B8 00115518  EC 42 00 F2 */	fmuls f2, f2, f3
/* 801185BC 0011551C  EC 21 00 F2 */	fmuls f1, f1, f3
/* 801185C0 00115520  D0 01 00 50 */	stfs f0, 0x50(r1)
/* 801185C4 00115524  C0 01 00 50 */	lfs f0, 0x50(r1)
/* 801185C8 00115528  D0 01 00 90 */	stfs f0, 0x90(r1)
/* 801185CC 0011552C  D0 21 00 94 */	stfs f1, 0x94(r1)
/* 801185D0 00115530  D0 41 00 98 */	stfs f2, 0x98(r1)
/* 801185D4 00115534  C0 23 01 34 */	lfs f1, 0x134(r3)
/* 801185D8 00115538  C0 01 00 90 */	lfs f0, 0x90(r1)
/* 801185DC 0011553C  EC 01 00 2A */	fadds f0, f1, f0
/* 801185E0 00115540  D0 01 00 64 */	stfs f0, 0x64(r1)
/* 801185E4 00115544  C0 01 00 64 */	lfs f0, 0x64(r1)
/* 801185E8 00115548  D0 01 00 9C */	stfs f0, 0x9c(r1)
/* 801185EC 0011554C  C0 23 01 38 */	lfs f1, 0x138(r3)
/* 801185F0 00115550  C0 01 00 94 */	lfs f0, 0x94(r1)
/* 801185F4 00115554  EC 01 00 2A */	fadds f0, f1, f0
/* 801185F8 00115558  D0 01 00 A0 */	stfs f0, 0xa0(r1)
/* 801185FC 0011555C  C0 23 01 3C */	lfs f1, 0x13c(r3)
/* 80118600 00115560  C0 01 00 98 */	lfs f0, 0x98(r1)
/* 80118604 00115564  EC 01 00 2A */	fadds f0, f1, f0
/* 80118608 00115568  D0 01 00 A4 */	stfs f0, 0xa4(r1)
/* 8011860C 0011556C  80 81 00 9C */	lwz r4, 0x9c(r1)
/* 80118610 00115570  80 01 00 A0 */	lwz r0, 0xa0(r1)
/* 80118614 00115574  90 83 01 34 */	stw r4, 0x134(r3)
/* 80118618 00115578  90 03 01 38 */	stw r0, 0x138(r3)
/* 8011861C 0011557C  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 80118620 00115580  90 03 01 3C */	stw r0, 0x13c(r3)
/* 80118624 00115584  C0 4D DD EC */	lfs f2, lbl_803E2B0C@sda21(r13)
/* 80118628 00115588  C0 C3 01 44 */	lfs f6, 0x144(r3)
/* 8011862C 0011558C  C0 83 01 4C */	lfs f4, 0x14c(r3)
/* 80118630 00115590  C0 A3 01 48 */	lfs f5, 0x148(r3)
/* 80118634 00115594  EC 06 00 B2 */	fmuls f0, f6, f2
/* 80118638 00115598  EC 24 00 B2 */	fmuls f1, f4, f2
/* 8011863C 0011559C  EC 65 00 B2 */	fmuls f3, f5, f2
/* 80118640 001155A0  D0 01 00 60 */	stfs f0, 0x60(r1)
/* 80118644 001155A4  EC 04 08 28 */	fsubs f0, f4, f1
/* 80118648 001155A8  C0 41 00 60 */	lfs f2, 0x60(r1)
/* 8011864C 001155AC  EC 25 18 28 */	fsubs f1, f5, f3
/* 80118650 001155B0  EC 46 10 28 */	fsubs f2, f6, f2
/* 80118654 001155B4  D0 41 00 54 */	stfs f2, 0x54(r1)
/* 80118658 001155B8  C0 41 00 54 */	lfs f2, 0x54(r1)
/* 8011865C 001155BC  D0 41 00 80 */	stfs f2, 0x80(r1)
/* 80118660 001155C0  D0 21 00 84 */	stfs f1, 0x84(r1)
/* 80118664 001155C4  D0 01 00 88 */	stfs f0, 0x88(r1)
/* 80118668 001155C8  80 81 00 80 */	lwz r4, 0x80(r1)
/* 8011866C 001155CC  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80118670 001155D0  90 83 01 44 */	stw r4, 0x144(r3)
/* 80118674 001155D4  90 03 01 48 */	stw r0, 0x148(r3)
/* 80118678 001155D8  80 01 00 88 */	lwz r0, 0x88(r1)
/* 8011867C 001155DC  90 03 01 4C */	stw r0, 0x14c(r3)
/* 80118680 001155E0  4B F4 98 4D */	bl update__12DynCollShapeFv
/* 80118684 001155E4  80 01 00 AC */	lwz r0, 0xac(r1)
/* 80118688 001155E8  38 21 00 A8 */	addi r1, r1, 0xa8
/* 8011868C 001155EC  7C 08 03 A6 */	mtlr r0
/* 80118690 001155F0  4E 80 00 20 */	blr 

.global __ct__9MapSliderFP5Shapeiifffi
__ct__9MapSliderFP5Shapeiifffi:
/* 80118694 001155F4  7C 08 02 A6 */	mflr r0
/* 80118698 001155F8  90 01 00 04 */	stw r0, 4(r1)
/* 8011869C 001155FC  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 801186A0 00115600  DB E1 00 48 */	stfd f31, 0x48(r1)
/* 801186A4 00115604  FF E0 18 90 */	fmr f31, f3
/* 801186A8 00115608  DB C1 00 40 */	stfd f30, 0x40(r1)
/* 801186AC 0011560C  FF C0 10 90 */	fmr f30, f2
/* 801186B0 00115610  DB A1 00 38 */	stfd f29, 0x38(r1)
/* 801186B4 00115614  FF A0 08 90 */	fmr f29, f1
/* 801186B8 00115618  93 E1 00 34 */	stw r31, 0x34(r1)
/* 801186BC 0011561C  3B E7 00 00 */	addi r31, r7, 0
/* 801186C0 00115620  93 C1 00 30 */	stw r30, 0x30(r1)
/* 801186C4 00115624  3B C6 00 00 */	addi r30, r6, 0
/* 801186C8 00115628  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 801186CC 0011562C  3B A5 00 00 */	addi r29, r5, 0
/* 801186D0 00115630  93 81 00 28 */	stw r28, 0x28(r1)
/* 801186D4 00115634  7C 7C 1B 78 */	mr r28, r3
/* 801186D8 00115638  4B F4 99 11 */	bl __ct__12DynCollShapeFP5Shape
/* 801186DC 0011563C  3C 60 80 2C */	lis r3, __vt__8MapParts@ha
/* 801186E0 00115640  38 03 34 9C */	addi r0, r3, __vt__8MapParts@l
/* 801186E4 00115644  90 1C 00 00 */	stw r0, 0(r28)
/* 801186E8 00115648  3C 60 80 2C */	lis r3, __vt__9MapSlider@ha
/* 801186EC 0011564C  38 80 00 00 */	li r4, 0
/* 801186F0 00115650  C0 02 9F B8 */	lfs f0, lbl_803EA1B8@sda21(r2)
/* 801186F4 00115654  38 03 33 68 */	addi r0, r3, __vt__9MapSlider@l
/* 801186F8 00115658  38 7C 00 00 */	addi r3, r28, 0
/* 801186FC 0011565C  D0 1C 01 4C */	stfs f0, 0x14c(r28)
/* 80118700 00115660  D0 1C 01 48 */	stfs f0, 0x148(r28)
/* 80118704 00115664  D0 1C 01 44 */	stfs f0, 0x144(r28)
/* 80118708 00115668  90 9C 01 40 */	stw r4, 0x140(r28)
/* 8011870C 0011566C  90 1C 00 00 */	stw r0, 0(r28)
/* 80118710 00115670  D0 1C 01 58 */	stfs f0, 0x158(r28)
/* 80118714 00115674  D0 1C 01 54 */	stfs f0, 0x154(r28)
/* 80118718 00115678  D0 1C 01 50 */	stfs f0, 0x150(r28)
/* 8011871C 0011567C  93 BC 01 60 */	stw r29, 0x160(r28)
/* 80118720 00115680  93 DC 01 64 */	stw r30, 0x164(r28)
/* 80118724 00115684  D3 BC 01 68 */	stfs f29, 0x168(r28)
/* 80118728 00115688  D3 DC 01 6C */	stfs f30, 0x16c(r28)
/* 8011872C 0011568C  D3 FC 01 70 */	stfs f31, 0x170(r28)
/* 80118730 00115690  93 FC 01 74 */	stw r31, 0x174(r28)
/* 80118734 00115694  D0 1C 01 5C */	stfs f0, 0x15c(r28)
/* 80118738 00115698  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8011873C 0011569C  CB E1 00 48 */	lfd f31, 0x48(r1)
/* 80118740 001156A0  CB C1 00 40 */	lfd f30, 0x40(r1)
/* 80118744 001156A4  CB A1 00 38 */	lfd f29, 0x38(r1)
/* 80118748 001156A8  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 8011874C 001156AC  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 80118750 001156B0  83 A1 00 2C */	lwz r29, 0x2c(r1)
/* 80118754 001156B4  83 81 00 28 */	lwz r28, 0x28(r1)
/* 80118758 001156B8  38 21 00 50 */	addi r1, r1, 0x50
/* 8011875C 001156BC  7C 08 03 A6 */	mtlr r0
/* 80118760 001156C0  4E 80 00 20 */	blr 

.global init__9MapSliderFv
init__9MapSliderFv:
/* 80118764 001156C4  80 E3 01 40 */	lwz r7, 0x140(r3)
/* 80118768 001156C8  28 07 00 00 */	cmplwi r7, 0
/* 8011876C 001156CC  4D 82 00 20 */	beqlr 
/* 80118770 001156D0  80 C7 00 00 */	lwz r6, 0(r7)
/* 80118774 001156D4  38 80 00 02 */	li r4, 2
/* 80118778 001156D8  80 A7 00 04 */	lwz r5, 4(r7)
/* 8011877C 001156DC  38 00 00 01 */	li r0, 1
/* 80118780 001156E0  90 C3 01 34 */	stw r6, 0x134(r3)
/* 80118784 001156E4  90 A3 01 38 */	stw r5, 0x138(r3)
/* 80118788 001156E8  80 A7 00 08 */	lwz r5, 8(r7)
/* 8011878C 001156EC  90 A3 01 3C */	stw r5, 0x13c(r3)
/* 80118790 001156F0  C0 03 01 68 */	lfs f0, 0x168(r3)
/* 80118794 001156F4  D0 03 01 80 */	stfs f0, 0x180(r3)
/* 80118798 001156F8  90 83 01 78 */	stw r4, 0x178(r3)
/* 8011879C 001156FC  90 03 01 7C */	stw r0, 0x17c(r3)
/* 801187A0 00115700  4E 80 00 20 */	blr 

.global update__9MapSliderFv
update__9MapSliderFv:
/* 801187A4 00115704  7C 08 02 A6 */	mflr r0
/* 801187A8 00115708  90 01 00 04 */	stw r0, 4(r1)
/* 801187AC 0011570C  94 21 FE F0 */	stwu r1, -0x110(r1)
/* 801187B0 00115710  DB E1 01 08 */	stfd f31, 0x108(r1)
/* 801187B4 00115714  DB C1 01 00 */	stfd f30, 0x100(r1)
/* 801187B8 00115718  DB A1 00 F8 */	stfd f29, 0xf8(r1)
/* 801187BC 0011571C  DB 81 00 F0 */	stfd f28, 0xf0(r1)
/* 801187C0 00115720  93 E1 00 EC */	stw r31, 0xec(r1)
/* 801187C4 00115724  93 C1 00 E8 */	stw r30, 0xe8(r1)
/* 801187C8 00115728  7C 7E 1B 78 */	mr r30, r3
/* 801187CC 0011572C  80 03 01 7C */	lwz r0, 0x17c(r3)
/* 801187D0 00115730  38 60 FF FF */	li r3, -1
/* 801187D4 00115734  80 BE 00 20 */	lwz r5, 0x20(r30)
/* 801187D8 00115738  80 9E 01 60 */	lwz r4, 0x160(r30)
/* 801187DC 0011573C  2C 00 00 01 */	cmpwi r0, 1
/* 801187E0 00115740  7C 04 28 10 */	subfc r0, r4, r5
/* 801187E4 00115744  7F E3 01 90 */	subfze r31, r3
/* 801187E8 00115748  40 82 00 0C */	bne lbl_801187F4
/* 801187EC 0011574C  C3 FE 01 68 */	lfs f31, 0x168(r30)
/* 801187F0 00115750  48 00 00 08 */	b lbl_801187F8
lbl_801187F4:
/* 801187F4 00115754  C3 FE 01 6C */	lfs f31, 0x16c(r30)
lbl_801187F8:
/* 801187F8 00115758  80 1E 01 40 */	lwz r0, 0x140(r30)
/* 801187FC 0011575C  28 00 00 00 */	cmplwi r0, 0
/* 80118800 00115760  41 82 02 A4 */	beq lbl_80118AA4
/* 80118804 00115764  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80118808 00115768  C0 1E 01 44 */	lfs f0, 0x144(r30)
/* 8011880C 0011576C  C0 63 02 8C */	lfs f3, 0x28c(r3)
/* 80118810 00115770  C0 5E 01 4C */	lfs f2, 0x14c(r30)
/* 80118814 00115774  EC 00 00 F2 */	fmuls f0, f0, f3
/* 80118818 00115778  C0 3E 01 48 */	lfs f1, 0x148(r30)
/* 8011881C 0011577C  EC 42 00 F2 */	fmuls f2, f2, f3
/* 80118820 00115780  EC 21 00 F2 */	fmuls f1, f1, f3
/* 80118824 00115784  D0 01 00 88 */	stfs f0, 0x88(r1)
/* 80118828 00115788  C0 01 00 88 */	lfs f0, 0x88(r1)
/* 8011882C 0011578C  D0 01 00 AC */	stfs f0, 0xac(r1)
/* 80118830 00115790  D0 21 00 B0 */	stfs f1, 0xb0(r1)
/* 80118834 00115794  D0 41 00 B4 */	stfs f2, 0xb4(r1)
/* 80118838 00115798  C0 3E 01 34 */	lfs f1, 0x134(r30)
/* 8011883C 0011579C  C0 01 00 AC */	lfs f0, 0xac(r1)
/* 80118840 001157A0  EC 01 00 2A */	fadds f0, f1, f0
/* 80118844 001157A4  D0 01 00 7C */	stfs f0, 0x7c(r1)
/* 80118848 001157A8  C0 01 00 7C */	lfs f0, 0x7c(r1)
/* 8011884C 001157AC  D0 01 00 B8 */	stfs f0, 0xb8(r1)
/* 80118850 001157B0  C0 3E 01 38 */	lfs f1, 0x138(r30)
/* 80118854 001157B4  C0 01 00 B0 */	lfs f0, 0xb0(r1)
/* 80118858 001157B8  EC 01 00 2A */	fadds f0, f1, f0
/* 8011885C 001157BC  D0 01 00 BC */	stfs f0, 0xbc(r1)
/* 80118860 001157C0  C0 3E 01 3C */	lfs f1, 0x13c(r30)
/* 80118864 001157C4  C0 01 00 B4 */	lfs f0, 0xb4(r1)
/* 80118868 001157C8  EC 01 00 2A */	fadds f0, f1, f0
/* 8011886C 001157CC  D0 01 00 C0 */	stfs f0, 0xc0(r1)
/* 80118870 001157D0  80 61 00 B8 */	lwz r3, 0xb8(r1)
/* 80118874 001157D4  80 01 00 BC */	lwz r0, 0xbc(r1)
/* 80118878 001157D8  90 7E 01 34 */	stw r3, 0x134(r30)
/* 8011887C 001157DC  90 1E 01 38 */	stw r0, 0x138(r30)
/* 80118880 001157E0  80 01 00 C0 */	lwz r0, 0xc0(r1)
/* 80118884 001157E4  90 1E 01 3C */	stw r0, 0x13c(r30)
/* 80118888 001157E8  C0 02 9F B8 */	lfs f0, lbl_803EA1B8@sda21(r2)
/* 8011888C 001157EC  D0 01 00 DC */	stfs f0, 0xdc(r1)
/* 80118890 001157F0  D0 01 00 D8 */	stfs f0, 0xd8(r1)
/* 80118894 001157F4  80 1E 01 7C */	lwz r0, 0x17c(r30)
/* 80118898 001157F8  2C 00 00 01 */	cmpwi r0, 1
/* 8011889C 001157FC  40 82 00 0C */	bne lbl_801188A8
/* 801188A0 00115800  80 9E 01 40 */	lwz r4, 0x140(r30)
/* 801188A4 00115804  48 00 00 0C */	b lbl_801188B0
lbl_801188A8:
/* 801188A8 00115808  80 7E 01 40 */	lwz r3, 0x140(r30)
/* 801188AC 0011580C  38 83 00 0C */	addi r4, r3, 0xc
lbl_801188B0:
/* 801188B0 00115810  80 64 00 00 */	lwz r3, 0(r4)
/* 801188B4 00115814  80 04 00 04 */	lwz r0, 4(r4)
/* 801188B8 00115818  90 61 00 D4 */	stw r3, 0xd4(r1)
/* 801188BC 0011581C  90 01 00 D8 */	stw r0, 0xd8(r1)
/* 801188C0 00115820  80 04 00 08 */	lwz r0, 8(r4)
/* 801188C4 00115824  90 01 00 DC */	stw r0, 0xdc(r1)
/* 801188C8 00115828  C0 61 00 D4 */	lfs f3, 0xd4(r1)
/* 801188CC 0011582C  C0 5E 01 34 */	lfs f2, 0x134(r30)
/* 801188D0 00115830  C0 21 00 D8 */	lfs f1, 0xd8(r1)
/* 801188D4 00115834  C0 1E 01 38 */	lfs f0, 0x138(r30)
/* 801188D8 00115838  EF C3 10 28 */	fsubs f30, f3, f2
/* 801188DC 0011583C  C0 41 00 DC */	lfs f2, 0xdc(r1)
/* 801188E0 00115840  EF A1 00 28 */	fsubs f29, f1, f0
/* 801188E4 00115844  C0 1E 01 3C */	lfs f0, 0x13c(r30)
/* 801188E8 00115848  EC 3E 07 B2 */	fmuls f1, f30, f30
/* 801188EC 0011584C  EF 82 00 28 */	fsubs f28, f2, f0
/* 801188F0 00115850  EC 1D 07 72 */	fmuls f0, f29, f29
/* 801188F4 00115854  EC 5C 07 32 */	fmuls f2, f28, f28
/* 801188F8 00115858  EC 01 00 2A */	fadds f0, f1, f0
/* 801188FC 0011585C  EC 22 00 2A */	fadds f1, f2, f0
/* 80118900 00115860  4B EF 53 41 */	bl sqrtf__3stdFf
/* 80118904 00115864  C0 02 9F B8 */	lfs f0, lbl_803EA1B8@sda21(r2)
/* 80118908 00115868  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 8011890C 0011586C  41 82 00 10 */	beq lbl_8011891C
/* 80118910 00115870  EF DE 08 24 */	fdivs f30, f30, f1
/* 80118914 00115874  EF BD 08 24 */	fdivs f29, f29, f1
/* 80118918 00115878  EF 9C 08 24 */	fdivs f28, f28, f1
lbl_8011891C:
/* 8011891C 0011587C  C0 7E 01 70 */	lfs f3, 0x170(r30)
/* 80118920 00115880  EC 5E 00 F2 */	fmuls f2, f30, f3
/* 80118924 00115884  EC 1D 00 F2 */	fmuls f0, f29, f3
/* 80118928 00115888  EC 7C 00 F2 */	fmuls f3, f28, f3
/* 8011892C 0011588C  D0 41 00 6C */	stfs f2, 0x6c(r1)
/* 80118930 00115890  C0 41 00 6C */	lfs f2, 0x6c(r1)
/* 80118934 00115894  D0 41 00 90 */	stfs f2, 0x90(r1)
/* 80118938 00115898  D0 01 00 94 */	stfs f0, 0x94(r1)
/* 8011893C 0011589C  D0 61 00 98 */	stfs f3, 0x98(r1)
/* 80118940 001158A0  80 61 00 90 */	lwz r3, 0x90(r1)
/* 80118944 001158A4  80 01 00 94 */	lwz r0, 0x94(r1)
/* 80118948 001158A8  90 7E 01 44 */	stw r3, 0x144(r30)
/* 8011894C 001158AC  90 1E 01 48 */	stw r0, 0x148(r30)
/* 80118950 001158B0  80 01 00 98 */	lwz r0, 0x98(r1)
/* 80118954 001158B4  90 1E 01 4C */	stw r0, 0x14c(r30)
/* 80118958 001158B8  80 1E 01 78 */	lwz r0, 0x178(r30)
/* 8011895C 001158BC  2C 00 00 02 */	cmpwi r0, 2
/* 80118960 001158C0  41 82 00 3C */	beq lbl_8011899C
/* 80118964 001158C4  40 80 00 10 */	bge lbl_80118974
/* 80118968 001158C8  2C 00 00 00 */	cmpwi r0, 0
/* 8011896C 001158CC  40 80 00 14 */	bge lbl_80118980
/* 80118970 001158D0  48 00 01 70 */	b lbl_80118AE0
lbl_80118974:
/* 80118974 001158D4  2C 00 00 04 */	cmpwi r0, 4
/* 80118978 001158D8  40 80 01 68 */	bge lbl_80118AE0
/* 8011897C 001158DC  48 00 00 F4 */	b lbl_80118A70
lbl_80118980:
/* 80118980 001158E0  C0 02 9F BC */	lfs f0, lbl_803EA1BC@sda21(r2)
/* 80118984 001158E4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80118988 001158E8  40 80 01 58 */	bge lbl_80118AE0
/* 8011898C 001158EC  38 00 00 03 */	li r0, 3
/* 80118990 001158F0  90 1E 01 78 */	stw r0, 0x178(r30)
/* 80118994 001158F4  D3 FE 01 80 */	stfs f31, 0x180(r30)
/* 80118998 001158F8  48 00 01 48 */	b lbl_80118AE0
lbl_8011899C:
/* 8011899C 001158FC  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 801189A0 00115900  C0 3E 01 80 */	lfs f1, 0x180(r30)
/* 801189A4 00115904  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 801189A8 00115908  EC 01 00 28 */	fsubs f0, f1, f0
/* 801189AC 0011590C  D0 1E 01 80 */	stfs f0, 0x180(r30)
/* 801189B0 00115910  C0 0D DD F0 */	lfs f0, lbl_803E2B10@sda21(r13)
/* 801189B4 00115914  D0 1E 01 44 */	stfs f0, 0x144(r30)
/* 801189B8 00115918  C0 0D DD F4 */	lfs f0, lbl_803E2B14@sda21(r13)
/* 801189BC 0011591C  D0 1E 01 48 */	stfs f0, 0x148(r30)
/* 801189C0 00115920  C0 0D DD F8 */	lfs f0, lbl_803E2B18@sda21(r13)
/* 801189C4 00115924  D0 1E 01 4C */	stfs f0, 0x14c(r30)
/* 801189C8 00115928  80 1E 01 74 */	lwz r0, 0x174(r30)
/* 801189CC 0011592C  2C 00 00 01 */	cmpwi r0, 1
/* 801189D0 00115930  41 82 00 10 */	beq lbl_801189E0
/* 801189D4 00115934  80 1E 01 7C */	lwz r0, 0x17c(r30)
/* 801189D8 00115938  2C 00 00 01 */	cmpwi r0, 1
/* 801189DC 0011593C  40 82 00 60 */	bne lbl_80118A3C
lbl_801189E0:
/* 801189E0 00115940  C0 3E 01 80 */	lfs f1, 0x180(r30)
/* 801189E4 00115944  C0 02 9F B8 */	lfs f0, lbl_803EA1B8@sda21(r2)
/* 801189E8 00115948  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801189EC 0011594C  40 80 00 34 */	bge lbl_80118A20
/* 801189F0 00115950  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 801189F4 00115954  41 82 00 2C */	beq lbl_80118A20
/* 801189F8 00115958  80 1E 01 7C */	lwz r0, 0x17c(r30)
/* 801189FC 0011595C  2C 00 00 01 */	cmpwi r0, 1
/* 80118A00 00115960  40 82 00 0C */	bne lbl_80118A0C
/* 80118A04 00115964  38 00 00 00 */	li r0, 0
/* 80118A08 00115968  48 00 00 08 */	b lbl_80118A10
lbl_80118A0C:
/* 80118A0C 0011596C  38 00 00 01 */	li r0, 1
lbl_80118A10:
/* 80118A10 00115970  90 1E 01 7C */	stw r0, 0x17c(r30)
/* 80118A14 00115974  80 1E 01 7C */	lwz r0, 0x17c(r30)
/* 80118A18 00115978  90 1E 01 78 */	stw r0, 0x178(r30)
/* 80118A1C 0011597C  48 00 00 C4 */	b lbl_80118AE0
lbl_80118A20:
/* 80118A20 00115980  80 1E 01 60 */	lwz r0, 0x160(r30)
/* 80118A24 00115984  2C 00 00 01 */	cmpwi r0, 1
/* 80118A28 00115988  41 80 00 B8 */	blt lbl_80118AE0
/* 80118A2C 0011598C  57 E0 06 3F */	clrlwi. r0, r31, 0x18
/* 80118A30 00115990  40 82 00 B0 */	bne lbl_80118AE0
/* 80118A34 00115994  D3 FE 01 80 */	stfs f31, 0x180(r30)
/* 80118A38 00115998  48 00 00 A8 */	b lbl_80118AE0
lbl_80118A3C:
/* 80118A3C 0011599C  C0 3E 01 80 */	lfs f1, 0x180(r30)
/* 80118A40 001159A0  C0 02 9F B8 */	lfs f0, lbl_803EA1B8@sda21(r2)
/* 80118A44 001159A4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80118A48 001159A8  40 80 00 98 */	bge lbl_80118AE0
/* 80118A4C 001159AC  2C 00 00 01 */	cmpwi r0, 1
/* 80118A50 001159B0  40 82 00 0C */	bne lbl_80118A5C
/* 80118A54 001159B4  38 00 00 00 */	li r0, 0
/* 80118A58 001159B8  48 00 00 08 */	b lbl_80118A60
lbl_80118A5C:
/* 80118A5C 001159BC  38 00 00 01 */	li r0, 1
lbl_80118A60:
/* 80118A60 001159C0  90 1E 01 7C */	stw r0, 0x17c(r30)
/* 80118A64 001159C4  80 1E 01 7C */	lwz r0, 0x17c(r30)
/* 80118A68 001159C8  90 1E 01 78 */	stw r0, 0x178(r30)
/* 80118A6C 001159CC  48 00 00 74 */	b lbl_80118AE0
lbl_80118A70:
/* 80118A70 001159D0  C0 0D DD FC */	lfs f0, lbl_803E2B1C@sda21(r13)
/* 80118A74 001159D4  D0 1E 01 44 */	stfs f0, 0x144(r30)
/* 80118A78 001159D8  C0 0D DE 00 */	lfs f0, lbl_803E2B20@sda21(r13)
/* 80118A7C 001159DC  D0 1E 01 48 */	stfs f0, 0x148(r30)
/* 80118A80 001159E0  C0 0D DE 04 */	lfs f0, lbl_803E2B24@sda21(r13)
/* 80118A84 001159E4  D0 1E 01 4C */	stfs f0, 0x14c(r30)
/* 80118A88 001159E8  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 80118A8C 001159EC  28 00 00 00 */	cmplwi r0, 0
/* 80118A90 001159F0  40 82 00 50 */	bne lbl_80118AE0
/* 80118A94 001159F4  38 00 00 02 */	li r0, 2
/* 80118A98 001159F8  90 1E 01 78 */	stw r0, 0x178(r30)
/* 80118A9C 001159FC  D3 FE 01 80 */	stfs f31, 0x180(r30)
/* 80118AA0 00115A00  48 00 00 40 */	b lbl_80118AE0
lbl_80118AA4:
/* 80118AA4 00115A04  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80118AA8 00115A08  C0 3E 01 5C */	lfs f1, 0x15c(r30)
/* 80118AAC 00115A0C  C0 03 02 8C */	lfs f0, 0x28c(r3)
/* 80118AB0 00115A10  EC 01 00 2A */	fadds f0, f1, f0
/* 80118AB4 00115A14  D0 1E 01 5C */	stfs f0, 0x15c(r30)
/* 80118AB8 00115A18  C0 22 9F C0 */	lfs f1, lbl_803EA1C0@sda21(r2)
/* 80118ABC 00115A1C  C0 1E 01 5C */	lfs f0, 0x15c(r30)
/* 80118AC0 00115A20  EC 01 00 32 */	fmuls f0, f1, f0
/* 80118AC4 00115A24  D0 1E 01 30 */	stfs f0, 0x130(r30)
/* 80118AC8 00115A28  C0 1E 01 50 */	lfs f0, 0x150(r30)
/* 80118ACC 00115A2C  D0 1E 01 34 */	stfs f0, 0x134(r30)
/* 80118AD0 00115A30  C0 1E 01 54 */	lfs f0, 0x154(r30)
/* 80118AD4 00115A34  D0 1E 01 38 */	stfs f0, 0x138(r30)
/* 80118AD8 00115A38  C0 1E 01 58 */	lfs f0, 0x158(r30)
/* 80118ADC 00115A3C  D0 1E 01 3C */	stfs f0, 0x13c(r30)
lbl_80118AE0:
/* 80118AE0 00115A40  7F C3 F3 78 */	mr r3, r30
/* 80118AE4 00115A44  4B F4 93 E9 */	bl update__12DynCollShapeFv
/* 80118AE8 00115A48  80 01 01 14 */	lwz r0, 0x114(r1)
/* 80118AEC 00115A4C  CB E1 01 08 */	lfd f31, 0x108(r1)
/* 80118AF0 00115A50  CB C1 01 00 */	lfd f30, 0x100(r1)
/* 80118AF4 00115A54  CB A1 00 F8 */	lfd f29, 0xf8(r1)
/* 80118AF8 00115A58  CB 81 00 F0 */	lfd f28, 0xf0(r1)
/* 80118AFC 00115A5C  83 E1 00 EC */	lwz r31, 0xec(r1)
/* 80118B00 00115A60  83 C1 00 E8 */	lwz r30, 0xe8(r1)
/* 80118B04 00115A64  38 21 01 10 */	addi r1, r1, 0x110
/* 80118B08 00115A68  7C 08 03 A6 */	mtlr r0
/* 80118B0C 00115A6C  4E 80 00 20 */	blr 

.global refresh__9MapSliderFR8Graphics
refresh__9MapSliderFR8Graphics:
/* 80118B10 00115A70  7C 08 02 A6 */	mflr r0
/* 80118B14 00115A74  90 01 00 04 */	stw r0, 4(r1)
/* 80118B18 00115A78  94 21 FE D0 */	stwu r1, -0x130(r1)
/* 80118B1C 00115A7C  93 E1 01 2C */	stw r31, 0x12c(r1)
/* 80118B20 00115A80  93 C1 01 28 */	stw r30, 0x128(r1)
/* 80118B24 00115A84  3B C4 00 00 */	addi r30, r4, 0
/* 80118B28 00115A88  93 A1 01 24 */	stw r29, 0x124(r1)
/* 80118B2C 00115A8C  3B A3 00 00 */	addi r29, r3, 0
/* 80118B30 00115A90  38 61 01 14 */	addi r3, r1, 0x114
/* 80118B34 00115A94  93 81 01 20 */	stw r28, 0x120(r1)
/* 80118B38 00115A98  38 9D 00 DC */	addi r4, r29, 0xdc
/* 80118B3C 00115A9C  C0 0D DE 08 */	lfs f0, lbl_803E2B28@sda21(r13)
/* 80118B40 00115AA0  C0 2D DE 0C */	lfs f1, lbl_803E2B2C@sda21(r13)
/* 80118B44 00115AA4  D0 01 01 14 */	stfs f0, 0x114(r1)
/* 80118B48 00115AA8  C0 0D DE 10 */	lfs f0, lbl_803E2B30@sda21(r13)
/* 80118B4C 00115AAC  D0 21 01 18 */	stfs f1, 0x118(r1)
/* 80118B50 00115AB0  D0 01 01 1C */	stfs f0, 0x11c(r1)
/* 80118B54 00115AB4  4B F1 EB F9 */	bl multMatrix__8Vector3fFR8Matrix4f
/* 80118B58 00115AB8  7F C3 F3 78 */	mr r3, r30
/* 80118B5C 00115ABC  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80118B60 00115AC0  38 80 00 00 */	li r4, 0
/* 80118B64 00115AC4  38 A0 00 00 */	li r5, 0
/* 80118B68 00115AC8  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80118B6C 00115ACC  7D 88 03 A6 */	mtlr r12
/* 80118B70 00115AD0  4E 80 00 21 */	blrl 
/* 80118B74 00115AD4  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80118B78 00115AD8  38 03 00 00 */	addi r0, r3, 0
/* 80118B7C 00115ADC  3C 80 80 3A */	lis r4, ident__8Matrix4f@ha
/* 80118B80 00115AE0  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 80118B84 00115AE4  38 7E 00 00 */	addi r3, r30, 0
/* 80118B88 00115AE8  38 84 88 40 */	addi r4, r4, ident__8Matrix4f@l
/* 80118B8C 00115AEC  7D 88 03 A6 */	mtlr r12
/* 80118B90 00115AF0  7C 1F 03 78 */	mr r31, r0
/* 80118B94 00115AF4  38 A0 00 00 */	li r5, 0
/* 80118B98 00115AF8  4E 80 00 21 */	blrl 
/* 80118B9C 00115AFC  38 00 00 FF */	li r0, 0xff
/* 80118BA0 00115B00  98 01 00 10 */	stb r0, 0x10(r1)
/* 80118BA4 00115B04  38 81 00 10 */	addi r4, r1, 0x10
/* 80118BA8 00115B08  38 7E 00 00 */	addi r3, r30, 0
/* 80118BAC 00115B0C  98 01 00 11 */	stb r0, 0x11(r1)
/* 80118BB0 00115B10  38 A0 00 01 */	li r5, 1
/* 80118BB4 00115B14  98 01 00 12 */	stb r0, 0x12(r1)
/* 80118BB8 00115B18  98 01 00 13 */	stb r0, 0x13(r1)
/* 80118BBC 00115B1C  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80118BC0 00115B20  81 8C 00 A8 */	lwz r12, 0xa8(r12)
/* 80118BC4 00115B24  7D 88 03 A6 */	mtlr r12
/* 80118BC8 00115B28  4E 80 00 21 */	blrl 
/* 80118BCC 00115B2C  7F C3 F3 78 */	mr r3, r30
/* 80118BD0 00115B30  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80118BD4 00115B34  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80118BD8 00115B38  38 A0 00 00 */	li r5, 0
/* 80118BDC 00115B3C  80 84 00 10 */	lwz r4, 0x10(r4)
/* 80118BE0 00115B40  81 8C 00 CC */	lwz r12, 0xcc(r12)
/* 80118BE4 00115B44  80 84 00 00 */	lwz r4, 0(r4)
/* 80118BE8 00115B48  7D 88 03 A6 */	mtlr r12
/* 80118BEC 00115B4C  4E 80 00 21 */	blrl 
/* 80118BF0 00115B50  7F C3 F3 78 */	mr r3, r30
/* 80118BF4 00115B54  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80118BF8 00115B58  38 80 00 00 */	li r4, 0
/* 80118BFC 00115B5C  81 8C 00 60 */	lwz r12, 0x60(r12)
/* 80118C00 00115B60  7D 88 03 A6 */	mtlr r12
/* 80118C04 00115B64  4E 80 00 21 */	blrl 
/* 80118C08 00115B68  80 9D 00 20 */	lwz r4, 0x20(r29)
/* 80118C0C 00115B6C  3B 83 00 00 */	addi r28, r3, 0
/* 80118C10 00115B70  80 1D 01 60 */	lwz r0, 0x160(r29)
/* 80118C14 00115B74  7C 04 00 51 */	subf. r0, r4, r0
/* 80118C18 00115B78  7C 05 03 78 */	mr r5, r0
/* 80118C1C 00115B7C  40 80 00 08 */	bge lbl_80118C24
/* 80118C20 00115B80  38 A0 00 00 */	li r5, 0
lbl_80118C24:
/* 80118C24 00115B84  3C 60 80 2C */	lis r3, lbl_802C3258@ha
/* 80118C28 00115B88  4C C6 31 82 */	crclr 6
/* 80118C2C 00115B8C  38 83 32 58 */	addi r4, r3, lbl_802C3258@l
/* 80118C30 00115B90  38 61 00 14 */	addi r3, r1, 0x14
/* 80118C34 00115B94  48 0F D9 65 */	bl sprintf
/* 80118C38 00115B98  80 6D 2D EC */	lwz r3, gsys@sda21(r13)
/* 80118C3C 00115B9C  38 81 00 14 */	addi r4, r1, 0x14
/* 80118C40 00115BA0  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80118C44 00115BA4  4B F0 F4 F1 */	bl stringWidth__4FontFPc
/* 80118C48 00115BA8  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80118C4C 00115BAC  7C 60 0E 70 */	srawi r0, r3, 1
/* 80118C50 00115BB0  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 80118C54 00115BB4  7C 00 01 94 */	addze r0, r0
/* 80118C58 00115BB8  81 8C 00 F0 */	lwz r12, 0xf0(r12)
/* 80118C5C 00115BBC  80 84 00 10 */	lwz r4, 0x10(r4)
/* 80118C60 00115BC0  38 7E 00 00 */	addi r3, r30, 0
/* 80118C64 00115BC4  7D 88 03 A6 */	mtlr r12
/* 80118C68 00115BC8  7C C0 00 D0 */	neg r6, r0
/* 80118C6C 00115BCC  38 A1 01 14 */	addi r5, r1, 0x114
/* 80118C70 00115BD0  4C C6 31 82 */	crclr 6
/* 80118C74 00115BD4  39 01 00 14 */	addi r8, r1, 0x14
/* 80118C78 00115BD8  38 E0 00 00 */	li r7, 0
/* 80118C7C 00115BDC  4E 80 00 21 */	blrl 
/* 80118C80 00115BE0  7F C3 F3 78 */	mr r3, r30
/* 80118C84 00115BE4  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80118C88 00115BE8  7F 84 E3 78 */	mr r4, r28
/* 80118C8C 00115BEC  81 8C 00 60 */	lwz r12, 0x60(r12)
/* 80118C90 00115BF0  7D 88 03 A6 */	mtlr r12
/* 80118C94 00115BF4  4E 80 00 21 */	blrl 
/* 80118C98 00115BF8  7F C3 F3 78 */	mr r3, r30
/* 80118C9C 00115BFC  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80118CA0 00115C00  38 9F 00 00 */	addi r4, r31, 0
/* 80118CA4 00115C04  38 A0 00 00 */	li r5, 0
/* 80118CA8 00115C08  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80118CAC 00115C0C  7D 88 03 A6 */	mtlr r12
/* 80118CB0 00115C10  4E 80 00 21 */	blrl 
/* 80118CB4 00115C14  7F C3 F3 78 */	mr r3, r30
/* 80118CB8 00115C18  81 9E 03 B4 */	lwz r12, 0x3b4(r30)
/* 80118CBC 00115C1C  38 9D 00 DC */	addi r4, r29, 0xdc
/* 80118CC0 00115C20  38 A0 00 00 */	li r5, 0
/* 80118CC4 00115C24  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 80118CC8 00115C28  7D 88 03 A6 */	mtlr r12
/* 80118CCC 00115C2C  4E 80 00 21 */	blrl 
/* 80118CD0 00115C30  38 7D 00 00 */	addi r3, r29, 0
/* 80118CD4 00115C34  38 9E 00 00 */	addi r4, r30, 0
/* 80118CD8 00115C38  4B F4 92 79 */	bl refresh__12DynCollShapeFR8Graphics
/* 80118CDC 00115C3C  80 01 01 34 */	lwz r0, 0x134(r1)
/* 80118CE0 00115C40  83 E1 01 2C */	lwz r31, 0x12c(r1)
/* 80118CE4 00115C44  83 C1 01 28 */	lwz r30, 0x128(r1)
/* 80118CE8 00115C48  83 A1 01 24 */	lwz r29, 0x124(r1)
/* 80118CEC 00115C4C  83 81 01 20 */	lwz r28, 0x120(r1)
/* 80118CF0 00115C50  38 21 01 30 */	addi r1, r1, 0x130
/* 80118CF4 00115C54  7C 08 03 A6 */	mtlr r0
/* 80118CF8 00115C58  4E 80 00 20 */	blr 

.global read__8MapPartsFR18RandomAccessStream
read__8MapPartsFR18RandomAccessStream:
/* 80118CFC 00115C5C  4E 80 00 20 */	blr 

.global update__8MapPartsFv
update__8MapPartsFv:
/* 80118D00 00115C60  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C31D8:
	.asciz "mapParts.cpp"
.balign 4
lbl_802C31E8:
	.asciz "mapParts"
.balign 4
lbl_802C31F4:
	.asciz "mapparts/cone.mod"
.balign 4
lbl_802C3208:
	.asciz "mapparts/cylinder.mod"
.balign 4
lbl_802C3220:
	.asciz "mapparts/cube.mod"
.balign 4
lbl_802C3234:
	.asciz "mapparts/board.mod"
.balign 4
.global shapeFiles__8MapParts
shapeFiles__8MapParts:
	.4byte lbl_802C31F4
	.4byte lbl_802C3208
	.4byte lbl_802C3220
	.4byte lbl_802C3234
lbl_802C3258:
	.asciz "%d to go!\n"
.balign 4
lbl_802C3264:
	.asciz "MapSlider"
.balign 4
lbl_802C3270:
	.asciz "CoreNode"
.balign 4
lbl_802C327C:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
lbl_802C3288:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
.balign 4
lbl_802C329C:
	.asciz "DynCollObject"
.balign 4
lbl_802C32AC:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.balign 4
lbl_802C32C8:
	.asciz "DynCollShape"
.balign 4
lbl_802C32D8:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__13DynCollObject
	.4byte 0
	.4byte 0
.balign 4
lbl_802C32FC:
	.asciz "MapParts"
.balign 4
lbl_802C3308:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__13DynCollObject
	.4byte 0
	.4byte __RTTI__12DynCollShape
	.4byte 0
	.4byte 0
lbl_802C3334:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__13DynCollObject
	.4byte 0
	.4byte __RTTI__12DynCollShape
	.4byte 0
	.4byte __RTTI__8MapParts
	.4byte 0
	.4byte 0
.global __vt__9MapSlider
__vt__9MapSlider:
	.4byte __RTTI__9MapSlider
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8MapPartsFR18RandomAccessStream
	.4byte update__9MapSliderFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte adjust__12DynCollShapeFP8Creature
	.4byte applyVelocity__8MapPartsFR5PlaneR8Vector3fR8Vector3f
	.4byte touchCallback__13DynCollObjectFR5PlaneR8Vector3fR8Vector3f
	.4byte getShape__12DynCollShapeFv
	.4byte jointVisible__12DynCollShapeFii
	.4byte refresh__9MapSliderFR8Graphics
	.4byte init__9MapSliderFv
.balign 4
lbl_802C33B4:
	.asciz "MapEntity"
.balign 4
lbl_802C33C0:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte __RTTI__13DynCollObject
	.4byte 0
	.4byte __RTTI__12DynCollShape
	.4byte 0
	.4byte __RTTI__8MapParts
	.4byte 0
	.4byte 0
.global __vt__9MapEntity
__vt__9MapEntity:
	.4byte __RTTI__9MapEntity
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8MapPartsFR18RandomAccessStream
	.4byte update__9MapEntityFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte adjust__12DynCollShapeFP8Creature
	.4byte applyVelocity__8MapPartsFR5PlaneR8Vector3fR8Vector3f
	.4byte touchCallback__13DynCollObjectFR5PlaneR8Vector3fR8Vector3f
	.4byte getShape__12DynCollShapeFv
	.4byte jointVisible__12DynCollShapeFii
	.4byte refresh__12DynCollShapeFR8Graphics
	.4byte init__8MapPartsFv
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
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
.global __vt__8MapParts
__vt__8MapParts:
	.4byte __RTTI__8MapParts
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8MapPartsFR18RandomAccessStream
	.4byte update__8MapPartsFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte adjust__12DynCollShapeFP8Creature
	.4byte applyVelocity__8MapPartsFR5PlaneR8Vector3fR8Vector3f
	.4byte touchCallback__13DynCollObjectFR5PlaneR8Vector3fR8Vector3f
	.4byte getShape__12DynCollShapeFv
	.4byte jointVisible__12DynCollShapeFii
	.4byte refresh__12DynCollShapeFR8Graphics
	.4byte init__8MapPartsFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E2B00:
	.float 0.0
lbl_803E2B04:
	.float 0.0
lbl_803E2B08:
	.float 0.0
lbl_803E2B0C:
	.float 0.1
lbl_803E2B10:
	.float 0.0
lbl_803E2B14:
	.float 0.0
lbl_803E2B18:
	.float 0.0
lbl_803E2B1C:
	.float 0.0
lbl_803E2B20:
	.float 0.0
lbl_803E2B24:
	.float 0.0
lbl_803E2B28:
	.float 0.0
lbl_803E2B2C:
	.float 20.0
lbl_803E2B30:
	.float 0.0
.balign 4
lbl_803E2B34:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803E2B34
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802C3270
	.4byte lbl_802C327C
.balign 4
lbl_803E2B4C:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803E2B4C
	.4byte lbl_802C3288
__RTTI__13DynCollObject:
	.4byte lbl_802C329C
	.4byte lbl_802C32AC
__RTTI__12DynCollShape:
	.4byte lbl_802C32C8
	.4byte lbl_802C32D8
__RTTI__8MapParts:
	.4byte lbl_802C32FC
	.4byte lbl_802C3308
__RTTI__9MapSlider:
	.4byte lbl_802C3264
	.4byte lbl_802C3334
__RTTI__9MapEntity:
	.4byte lbl_802C33B4
	.4byte lbl_802C33C0

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EA1B8:
	.float 0.0
lbl_803EA1BC:
	.float 1.0
lbl_803EA1C0:
	.float 0.5
