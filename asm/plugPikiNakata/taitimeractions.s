.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn start__14TaiTimerActionFR4Teki, global
/* 801436D0 00140630  7C 08 02 A6 */	mflr r0
/* 801436D4 00140634  90 01 00 04 */	stw r0, 4(r1)
/* 801436D8 00140638  94 21 FF F8 */	stwu r1, -8(r1)
/* 801436DC 0014063C  48 00 00 3D */	bl resetTimer__14TaiTimerActionFR4Teki
/* 801436E0 00140640  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801436E4 00140644  38 21 00 08 */	addi r1, r1, 8
/* 801436E8 00140648  7C 08 03 A6 */	mtlr r0
/* 801436EC 0014064C  4E 80 00 20 */	blr 
.endfn start__14TaiTimerActionFR4Teki

.fn act__14TaiTimerActionFR4Teki, global
/* 801436F0 00140650  80 03 00 08 */	lwz r0, 8(r3)
/* 801436F4 00140654  C0 02 A7 08 */	lfs f0, lbl_803EA908@sda21(r2)
/* 801436F8 00140658  54 00 10 3A */	slwi r0, r0, 2
/* 801436FC 0014065C  7C 64 02 14 */	add r3, r4, r0
/* 80143700 00140660  C0 23 03 C4 */	lfs f1, 0x3c4(r3)
/* 80143704 00140664  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80143708 00140668  4C 40 13 82 */	cror 2, 0, 2
/* 8014370C 0014066C  7C 00 00 26 */	mfcr r0
/* 80143710 00140670  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 80143714 00140674  4E 80 00 20 */	blr 
.endfn act__14TaiTimerActionFR4Teki

.fn resetTimer__14TaiTimerActionFR4Teki, global
/* 80143718 00140678  7C 08 02 A6 */	mflr r0
/* 8014371C 0014067C  90 01 00 04 */	stw r0, 4(r1)
/* 80143720 00140680  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80143724 00140684  DB E1 00 38 */	stfd f31, 0x38(r1)
/* 80143728 00140688  DB C1 00 30 */	stfd f30, 0x30(r1)
/* 8014372C 0014068C  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80143730 00140690  7C 9F 23 78 */	mr r31, r4
/* 80143734 00140694  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80143738 00140698  7C 7E 1B 78 */	mr r30, r3
/* 8014373C 0014069C  C3 C3 00 10 */	lfs f30, 0x10(r3)
/* 80143740 001406A0  C3 E3 00 0C */	lfs f31, 0xc(r3)
/* 80143744 001406A4  48 0D 49 2D */	bl rand
/* 80143748 001406A8  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8014374C 001406AC  80 1E 00 08 */	lwz r0, 8(r30)
/* 80143750 001406B0  90 61 00 24 */	stw r3, 0x24(r1)
/* 80143754 001406B4  3C 60 43 30 */	lis r3, 0x4330
/* 80143758 001406B8  54 00 10 3A */	slwi r0, r0, 2
/* 8014375C 001406BC  C8 22 A7 20 */	lfd f1, lbl_803EA920@sda21(r2)
/* 80143760 001406C0  90 61 00 20 */	stw r3, 0x20(r1)
/* 80143764 001406C4  C0 62 A7 10 */	lfs f3, lbl_803EA910@sda21(r2)
/* 80143768 001406C8  7C 7F 02 14 */	add r3, r31, r0
/* 8014376C 001406CC  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 80143770 001406D0  C0 42 A7 0C */	lfs f2, lbl_803EA90C@sda21(r2)
/* 80143774 001406D4  EC 80 08 28 */	fsubs f4, f0, f1
/* 80143778 001406D8  C0 02 A7 18 */	lfs f0, lbl_803EA918@sda21(r2)
/* 8014377C 001406DC  C0 22 A7 14 */	lfs f1, lbl_803EA914@sda21(r2)
/* 80143780 001406E0  EC 64 18 24 */	fdivs f3, f4, f3
/* 80143784 001406E4  EC 42 00 F2 */	fmuls f2, f2, f3
/* 80143788 001406E8  EC 02 00 28 */	fsubs f0, f2, f0
/* 8014378C 001406EC  EC 01 00 32 */	fmuls f0, f1, f0
/* 80143790 001406F0  EC 1F 00 32 */	fmuls f0, f31, f0
/* 80143794 001406F4  EC 1E 00 32 */	fmuls f0, f30, f0
/* 80143798 001406F8  EC 1F 00 2A */	fadds f0, f31, f0
/* 8014379C 001406FC  D0 03 03 C4 */	stfs f0, 0x3c4(r3)
/* 801437A0 00140700  80 01 00 44 */	lwz r0, 0x44(r1)
/* 801437A4 00140704  CB E1 00 38 */	lfd f31, 0x38(r1)
/* 801437A8 00140708  CB C1 00 30 */	lfd f30, 0x30(r1)
/* 801437AC 0014070C  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 801437B0 00140710  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 801437B4 00140714  38 21 00 40 */	addi r1, r1, 0x40
/* 801437B8 00140718  7C 08 03 A6 */	mtlr r0
/* 801437BC 0014071C  4E 80 00 20 */	blr 
.endfn resetTimer__14TaiTimerActionFR4Teki

.fn start__19TaiResetTimerActionFR4Teki, global
/* 801437C0 00140720  7C 08 02 A6 */	mflr r0
/* 801437C4 00140724  90 01 00 04 */	stw r0, 4(r1)
/* 801437C8 00140728  94 21 FF F8 */	stwu r1, -8(r1)
/* 801437CC 0014072C  48 00 00 15 */	bl resetTimer__19TaiResetTimerActionFR4Teki
/* 801437D0 00140730  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801437D4 00140734  38 21 00 08 */	addi r1, r1, 8
/* 801437D8 00140738  7C 08 03 A6 */	mtlr r0
/* 801437DC 0014073C  4E 80 00 20 */	blr 
.endfn start__19TaiResetTimerActionFR4Teki

.fn resetTimer__19TaiResetTimerActionFR4Teki, global
/* 801437E0 00140740  7C 08 02 A6 */	mflr r0
/* 801437E4 00140744  90 01 00 04 */	stw r0, 4(r1)
/* 801437E8 00140748  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 801437EC 0014074C  DB E1 00 38 */	stfd f31, 0x38(r1)
/* 801437F0 00140750  DB C1 00 30 */	stfd f30, 0x30(r1)
/* 801437F4 00140754  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 801437F8 00140758  7C 9F 23 78 */	mr r31, r4
/* 801437FC 0014075C  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80143800 00140760  7C 7E 1B 78 */	mr r30, r3
/* 80143804 00140764  C3 C3 00 10 */	lfs f30, 0x10(r3)
/* 80143808 00140768  C3 E3 00 0C */	lfs f31, 0xc(r3)
/* 8014380C 0014076C  48 0D 48 65 */	bl rand
/* 80143810 00140770  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80143814 00140774  80 1E 00 08 */	lwz r0, 8(r30)
/* 80143818 00140778  90 61 00 24 */	stw r3, 0x24(r1)
/* 8014381C 0014077C  3C 60 43 30 */	lis r3, 0x4330
/* 80143820 00140780  54 00 10 3A */	slwi r0, r0, 2
/* 80143824 00140784  C8 22 A7 20 */	lfd f1, lbl_803EA920@sda21(r2)
/* 80143828 00140788  90 61 00 20 */	stw r3, 0x20(r1)
/* 8014382C 0014078C  C0 62 A7 10 */	lfs f3, lbl_803EA910@sda21(r2)
/* 80143830 00140790  7C 7F 02 14 */	add r3, r31, r0
/* 80143834 00140794  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 80143838 00140798  C0 42 A7 0C */	lfs f2, lbl_803EA90C@sda21(r2)
/* 8014383C 0014079C  EC 80 08 28 */	fsubs f4, f0, f1
/* 80143840 001407A0  C0 02 A7 18 */	lfs f0, lbl_803EA918@sda21(r2)
/* 80143844 001407A4  C0 22 A7 14 */	lfs f1, lbl_803EA914@sda21(r2)
/* 80143848 001407A8  EC 64 18 24 */	fdivs f3, f4, f3
/* 8014384C 001407AC  EC 42 00 F2 */	fmuls f2, f2, f3
/* 80143850 001407B0  EC 02 00 28 */	fsubs f0, f2, f0
/* 80143854 001407B4  EC 01 00 32 */	fmuls f0, f1, f0
/* 80143858 001407B8  EC 1F 00 32 */	fmuls f0, f31, f0
/* 8014385C 001407BC  EC 1E 00 32 */	fmuls f0, f30, f0
/* 80143860 001407C0  EC 1F 00 2A */	fadds f0, f31, f0
/* 80143864 001407C4  D0 03 03 C4 */	stfs f0, 0x3c4(r3)
/* 80143868 001407C8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8014386C 001407CC  CB E1 00 38 */	lfd f31, 0x38(r1)
/* 80143870 001407D0  CB C1 00 30 */	lfd f30, 0x30(r1)
/* 80143874 001407D4  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80143878 001407D8  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8014387C 001407DC  38 21 00 40 */	addi r1, r1, 0x40
/* 80143880 001407E0  7C 08 03 A6 */	mtlr r0
/* 80143884 001407E4  4E 80 00 20 */	blr 
.endfn resetTimer__19TaiResetTimerActionFR4Teki

.fn act__21TaiTimerElapsedActionFR4Teki, global
/* 80143888 001407E8  80 03 00 08 */	lwz r0, 8(r3)
/* 8014388C 001407EC  C0 02 A7 08 */	lfs f0, lbl_803EA908@sda21(r2)
/* 80143890 001407F0  54 00 10 3A */	slwi r0, r0, 2
/* 80143894 001407F4  7C 64 02 14 */	add r3, r4, r0
/* 80143898 001407F8  C0 23 03 C4 */	lfs f1, 0x3c4(r3)
/* 8014389C 001407FC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801438A0 00140800  4C 40 13 82 */	cror 2, 0, 2
/* 801438A4 00140804  7C 00 00 26 */	mfcr r0
/* 801438A8 00140808  54 03 1F FE */	rlwinm r3, r0, 3, 0x1f, 0x1f
/* 801438AC 0014080C  4E 80 00 20 */	blr 
.endfn act__21TaiTimerElapsedActionFR4Teki

.fn start__22TaiStartingTimerActionFR4Teki, global
/* 801438B0 00140810  7C 08 02 A6 */	mflr r0
/* 801438B4 00140814  90 01 00 04 */	stw r0, 4(r1)
/* 801438B8 00140818  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 801438BC 0014081C  DB E1 00 28 */	stfd f31, 0x28(r1)
/* 801438C0 00140820  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 801438C4 00140824  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801438C8 00140828  7C 9F 23 78 */	mr r31, r4
/* 801438CC 0014082C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 801438D0 00140830  7C 7E 1B 78 */	mr r30, r3
/* 801438D4 00140834  80 6D 31 50 */	lwz r3, system__7NSystem@sda21(r13)
/* 801438D8 00140838  C3 DE 00 10 */	lfs f30, 0x10(r30)
/* 801438DC 0014083C  C3 FE 00 0C */	lfs f31, 0xc(r30)
/* 801438E0 00140840  C0 22 A7 0C */	lfs f1, lbl_803EA90C@sda21(r2)
/* 801438E4 00140844  48 00 00 51 */	bl getRand__9StdSystemFf
/* 801438E8 00140848  C0 02 A7 18 */	lfs f0, lbl_803EA918@sda21(r2)
/* 801438EC 0014084C  80 1E 00 08 */	lwz r0, 8(r30)
/* 801438F0 00140850  EC 01 00 28 */	fsubs f0, f1, f0
/* 801438F4 00140854  C0 22 A7 14 */	lfs f1, lbl_803EA914@sda21(r2)
/* 801438F8 00140858  54 00 10 3A */	slwi r0, r0, 2
/* 801438FC 0014085C  7C 7F 02 14 */	add r3, r31, r0
/* 80143900 00140860  EC 01 00 32 */	fmuls f0, f1, f0
/* 80143904 00140864  EC 1F 00 32 */	fmuls f0, f31, f0
/* 80143908 00140868  EC 1E 00 32 */	fmuls f0, f30, f0
/* 8014390C 0014086C  EC 1F 00 2A */	fadds f0, f31, f0
/* 80143910 00140870  D0 03 03 C4 */	stfs f0, 0x3c4(r3)
/* 80143914 00140874  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80143918 00140878  CB E1 00 28 */	lfd f31, 0x28(r1)
/* 8014391C 0014087C  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 80143920 00140880  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80143924 00140884  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80143928 00140888  38 21 00 30 */	addi r1, r1, 0x30
/* 8014392C 0014088C  7C 08 03 A6 */	mtlr r0
/* 80143930 00140890  4E 80 00 20 */	blr 
.endfn start__22TaiStartingTimerActionFR4Teki

.fn getRand__9StdSystemFf, weak
/* 80143934 00140894  7C 08 02 A6 */	mflr r0
/* 80143938 00140898  90 01 00 04 */	stw r0, 4(r1)
/* 8014393C 0014089C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80143940 001408A0  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 80143944 001408A4  FF E0 08 90 */	fmr f31, f1
/* 80143948 001408A8  48 0D 47 29 */	bl rand
/* 8014394C 001408AC  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 80143950 001408B0  C8 42 A7 20 */	lfd f2, lbl_803EA920@sda21(r2)
/* 80143954 001408B4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80143958 001408B8  3C 00 43 30 */	lis r0, 0x4330
/* 8014395C 001408BC  C0 02 A7 10 */	lfs f0, lbl_803EA910@sda21(r2)
/* 80143960 001408C0  90 01 00 10 */	stw r0, 0x10(r1)
/* 80143964 001408C4  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 80143968 001408C8  EC 21 10 28 */	fsubs f1, f1, f2
/* 8014396C 001408CC  EC 01 00 24 */	fdivs f0, f1, f0
/* 80143970 001408D0  EC 3F 00 32 */	fmuls f1, f31, f0
/* 80143974 001408D4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80143978 001408D8  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 8014397C 001408DC  38 21 00 20 */	addi r1, r1, 0x20
/* 80143980 001408E0  7C 08 03 A6 */	mtlr r0
/* 80143984 001408E4  4E 80 00 20 */	blr 
.endfn getRand__9StdSystemFf

.fn act__22TaiStartingTimerActionFR4Teki, global
/* 80143988 001408E8  7C 08 02 A6 */	mflr r0
/* 8014398C 001408EC  90 01 00 04 */	stw r0, 4(r1)
/* 80143990 001408F0  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 80143994 001408F4  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 80143998 001408F8  DB C1 00 48 */	stfd f30, 0x48(r1)
/* 8014399C 001408FC  93 E1 00 44 */	stw r31, 0x44(r1)
/* 801439A0 00140900  93 C1 00 40 */	stw r30, 0x40(r1)
/* 801439A4 00140904  3B C4 00 00 */	addi r30, r4, 0
/* 801439A8 00140908  93 A1 00 3C */	stw r29, 0x3c(r1)
/* 801439AC 0014090C  7C 7D 1B 78 */	mr r29, r3
/* 801439B0 00140910  80 03 00 08 */	lwz r0, 8(r3)
/* 801439B4 00140914  C0 02 A7 08 */	lfs f0, lbl_803EA908@sda21(r2)
/* 801439B8 00140918  54 00 10 3A */	slwi r0, r0, 2
/* 801439BC 0014091C  7C 7E 02 14 */	add r3, r30, r0
/* 801439C0 00140920  C0 23 03 C4 */	lfs f1, 0x3c4(r3)
/* 801439C4 00140924  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 801439C8 00140928  4C 40 13 82 */	cror 2, 0, 2
/* 801439CC 0014092C  40 82 00 A8 */	bne .L_80143A74
/* 801439D0 00140930  C3 FD 00 14 */	lfs f31, 0x14(r29)
/* 801439D4 00140934  48 0D 46 9D */	bl rand
/* 801439D8 00140938  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 801439DC 0014093C  C8 62 A7 20 */	lfd f3, lbl_803EA920@sda21(r2)
/* 801439E0 00140940  90 01 00 34 */	stw r0, 0x34(r1)
/* 801439E4 00140944  3F E0 43 30 */	lis r31, 0x4330
/* 801439E8 00140948  C0 22 A7 10 */	lfs f1, lbl_803EA910@sda21(r2)
/* 801439EC 0014094C  93 E1 00 30 */	stw r31, 0x30(r1)
/* 801439F0 00140950  C0 02 A7 0C */	lfs f0, lbl_803EA90C@sda21(r2)
/* 801439F4 00140954  C8 41 00 30 */	lfd f2, 0x30(r1)
/* 801439F8 00140958  EC 42 18 28 */	fsubs f2, f2, f3
/* 801439FC 0014095C  EC 22 08 24 */	fdivs f1, f2, f1
/* 80143A00 00140960  EC 00 00 72 */	fmuls f0, f0, f1
/* 80143A04 00140964  FC 00 F8 40 */	fcmpo cr0, f0, f31
/* 80143A08 00140968  40 80 00 0C */	bge .L_80143A14
/* 80143A0C 0014096C  38 60 00 01 */	li r3, 1
/* 80143A10 00140970  48 00 00 68 */	b .L_80143A78
.L_80143A14:
/* 80143A14 00140974  C3 DD 00 10 */	lfs f30, 0x10(r29)
/* 80143A18 00140978  C3 FD 00 0C */	lfs f31, 0xc(r29)
/* 80143A1C 0014097C  48 0D 46 55 */	bl rand
/* 80143A20 00140980  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80143A24 00140984  80 1D 00 08 */	lwz r0, 8(r29)
/* 80143A28 00140988  90 61 00 34 */	stw r3, 0x34(r1)
/* 80143A2C 0014098C  54 00 10 3A */	slwi r0, r0, 2
/* 80143A30 00140990  C8 22 A7 20 */	lfd f1, lbl_803EA920@sda21(r2)
/* 80143A34 00140994  93 E1 00 30 */	stw r31, 0x30(r1)
/* 80143A38 00140998  7C 7E 02 14 */	add r3, r30, r0
/* 80143A3C 0014099C  C0 62 A7 10 */	lfs f3, lbl_803EA910@sda21(r2)
/* 80143A40 001409A0  C8 01 00 30 */	lfd f0, 0x30(r1)
/* 80143A44 001409A4  C0 42 A7 0C */	lfs f2, lbl_803EA90C@sda21(r2)
/* 80143A48 001409A8  EC 80 08 28 */	fsubs f4, f0, f1
/* 80143A4C 001409AC  C0 02 A7 18 */	lfs f0, lbl_803EA918@sda21(r2)
/* 80143A50 001409B0  C0 22 A7 14 */	lfs f1, lbl_803EA914@sda21(r2)
/* 80143A54 001409B4  EC 64 18 24 */	fdivs f3, f4, f3
/* 80143A58 001409B8  EC 42 00 F2 */	fmuls f2, f2, f3
/* 80143A5C 001409BC  EC 02 00 28 */	fsubs f0, f2, f0
/* 80143A60 001409C0  EC 01 00 32 */	fmuls f0, f1, f0
/* 80143A64 001409C4  EC 1F 00 32 */	fmuls f0, f31, f0
/* 80143A68 001409C8  EC 1E 00 32 */	fmuls f0, f30, f0
/* 80143A6C 001409CC  EC 1F 00 2A */	fadds f0, f31, f0
/* 80143A70 001409D0  D0 03 03 C4 */	stfs f0, 0x3c4(r3)
.L_80143A74:
/* 80143A74 001409D4  38 60 00 00 */	li r3, 0
.L_80143A78:
/* 80143A78 001409D8  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 80143A7C 001409DC  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 80143A80 001409E0  CB C1 00 48 */	lfd f30, 0x48(r1)
/* 80143A84 001409E4  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 80143A88 001409E8  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 80143A8C 001409EC  83 A1 00 3C */	lwz r29, 0x3c(r1)
/* 80143A90 001409F0  38 21 00 58 */	addi r1, r1, 0x58
/* 80143A94 001409F4  7C 08 03 A6 */	mtlr r0
/* 80143A98 001409F8  4E 80 00 20 */	blr 
.endfn act__22TaiStartingTimerActionFR4Teki

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802CC918, local
	.asciz "taitimeractions.cpp"
.endobj lbl_802CC918
.balign 4
.obj lbl_802CC92C, local
	.asciz "taitimeractions"
.endobj lbl_802CC92C
.balign 4
.obj lbl_802CC93C, local
	.asciz "TaiStartingTimerAction"
.endobj lbl_802CC93C
.balign 4
.obj lbl_802CC954, local
	.asciz "TaiAction"
.endobj lbl_802CC954
.balign 4
.obj lbl_802CC960, local
	.asciz "TaiTimerAction"
.endobj lbl_802CC960
.balign 4
.obj lbl_802CC970, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802CC970
.balign 4
.obj lbl_802CC97C, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte __RTTI__14TaiTimerAction
	.4byte 0
	.4byte 0
.endobj lbl_802CC97C
.balign 4
.obj __vt__22TaiStartingTimerAction, global
	.4byte __RTTI__22TaiStartingTimerAction
	.4byte 0
	.4byte start__22TaiStartingTimerActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__22TaiStartingTimerActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__22TaiStartingTimerAction
.balign 4
.obj lbl_802CC9AC, local
	.asciz "TaiTimerElapsedAction"
.endobj lbl_802CC9AC
.balign 4
.obj lbl_802CC9C4, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802CC9C4
.balign 4
.obj __vt__21TaiTimerElapsedAction, global
	.4byte __RTTI__21TaiTimerElapsedAction
	.4byte 0
	.4byte start__9TaiActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__21TaiTimerElapsedActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__21TaiTimerElapsedAction
.balign 4
.obj lbl_802CC9EC, local
	.asciz "TaiResetTimerAction"
.endobj lbl_802CC9EC
.balign 4
.obj lbl_802CCA00, local
	.4byte __RTTI__9TaiAction
	.4byte 0
	.4byte 0
.endobj lbl_802CCA00
.balign 4
.obj __vt__19TaiResetTimerAction, global
	.4byte __RTTI__19TaiResetTimerAction
	.4byte 0
	.4byte start__19TaiResetTimerActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__9TaiActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__19TaiResetTimerAction
.balign 4
.obj __vt__14TaiTimerAction, global
	.4byte __RTTI__14TaiTimerAction
	.4byte 0
	.4byte start__14TaiTimerActionFR4Teki
	.4byte finish__9TaiActionFR4Teki
	.4byte act__14TaiTimerActionFR4Teki
	.4byte actByEvent__9TaiActionFR9TekiEvent
	.4byte hasNextState__9TaiActionFv
.endobj __vt__14TaiTimerAction

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__9TaiAction, local
	.4byte lbl_802CC954
	.4byte 0
.endobj __RTTI__9TaiAction
.balign 4
.obj __RTTI__14TaiTimerAction, local
	.4byte lbl_802CC960
	.4byte lbl_802CC970
.endobj __RTTI__14TaiTimerAction
.balign 4
.obj __RTTI__22TaiStartingTimerAction, local
	.4byte lbl_802CC93C
	.4byte lbl_802CC97C
.endobj __RTTI__22TaiStartingTimerAction
.balign 4
.obj __RTTI__21TaiTimerElapsedAction, local
	.4byte lbl_802CC9AC
	.4byte lbl_802CC9C4
.endobj __RTTI__21TaiTimerElapsedAction
.balign 4
.obj __RTTI__19TaiResetTimerAction, local
	.4byte lbl_802CC9EC
	.4byte lbl_802CCA00
.endobj __RTTI__19TaiResetTimerAction

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA908, local
	.float 0.0
.endobj lbl_803EA908
.obj lbl_803EA90C, local
	.float 1.0
.endobj lbl_803EA90C
.obj lbl_803EA910, local
	.float 32767.0
.endobj lbl_803EA910
.obj lbl_803EA914, local
	.float 2.0
.endobj lbl_803EA914
.obj lbl_803EA918, local
	.float 0.5
.endobj lbl_803EA918
.balign 8
.obj lbl_803EA920, local
	.8byte 0x4330000080000000
.endobj lbl_803EA920
