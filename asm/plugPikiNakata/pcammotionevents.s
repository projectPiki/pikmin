.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global __ct__22PcamLongVibrationEventFP10PcamCamera
__ct__22PcamLongVibrationEventFP10PcamCamera:
/* 801241A8 00121108  7C 08 02 A6 */	mflr r0
/* 801241AC 0012110C  90 01 00 04 */	stw r0, 4(r1)
/* 801241B0 00121110  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801241B4 00121114  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801241B8 00121118  3B E4 00 00 */	addi r31, r4, 0
/* 801241BC 0012111C  38 80 00 02 */	li r4, 2
/* 801241C0 00121120  93 C1 00 10 */	stw r30, 0x10(r1)
/* 801241C4 00121124  3B C3 00 00 */	addi r30, r3, 0
/* 801241C8 00121128  48 00 15 55 */	bl __ct__15PeveSerialEventFi
/* 801241CC 0012112C  3C 60 80 2C */	lis r3, __vt__22PcamLongVibrationEvent@ha
/* 801241D0 00121130  38 03 55 9C */	addi r0, r3, __vt__22PcamLongVibrationEvent@l
/* 801241D4 00121134  90 1E 00 00 */	stw r0, 0(r30)
/* 801241D8 00121138  38 7E 00 20 */	addi r3, r30, 0x20
/* 801241DC 0012113C  48 00 17 3D */	bl __ct__19PeveCameraPostureIOFv
/* 801241E0 00121140  93 FE 00 1C */	stw r31, 0x1c(r30)
/* 801241E4 00121144  38 60 00 48 */	li r3, 0x48
/* 801241E8 00121148  4B F2 2E 1D */	bl alloc__6SystemFUl
/* 801241EC 0012114C  3B E3 00 00 */	addi r31, r3, 0
/* 801241F0 00121150  7F E3 FB 79 */	or. r3, r31, r31
/* 801241F4 00121154  41 82 00 08 */	beq lbl_801241FC
/* 801241F8 00121158  48 00 29 85 */	bl __ct__18PeveVibrationEventFv
lbl_801241FC:
/* 801241FC 0012115C  93 FE 00 14 */	stw r31, 0x14(r30)
/* 80124200 00121160  38 60 00 48 */	li r3, 0x48
/* 80124204 00121164  4B F2 2E 01 */	bl alloc__6SystemFUl
/* 80124208 00121168  3B E3 00 00 */	addi r31, r3, 0
/* 8012420C 0012116C  7F E3 FB 79 */	or. r3, r31, r31
/* 80124210 00121170  41 82 00 08 */	beq lbl_80124218
/* 80124214 00121174  48 00 29 69 */	bl __ct__18PeveVibrationEventFv
lbl_80124218:
/* 80124218 00121178  93 FE 00 18 */	stw r31, 0x18(r30)
/* 8012421C 0012117C  7F C3 F3 78 */	mr r3, r30
/* 80124220 00121180  81 9E 00 00 */	lwz r12, 0(r30)
/* 80124224 00121184  80 9E 00 14 */	lwz r4, 0x14(r30)
/* 80124228 00121188  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8012422C 0012118C  7D 88 03 A6 */	mtlr r12
/* 80124230 00121190  4E 80 00 21 */	blrl 
/* 80124234 00121194  7F C3 F3 78 */	mr r3, r30
/* 80124238 00121198  80 9E 00 18 */	lwz r4, 0x18(r30)
/* 8012423C 0012119C  81 9E 00 00 */	lwz r12, 0(r30)
/* 80124240 001211A0  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80124244 001211A4  7D 88 03 A6 */	mtlr r12
/* 80124248 001211A8  4E 80 00 21 */	blrl 
/* 8012424C 001211AC  38 7E 00 20 */	addi r3, r30, 0x20
/* 80124250 001211B0  80 9E 00 1C */	lwz r4, 0x1c(r30)
/* 80124254 001211B4  48 00 17 15 */	bl construct__19PeveCameraPostureIOFP10PcamCamera
/* 80124258 001211B8  7F C3 F3 78 */	mr r3, r30
/* 8012425C 001211BC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80124260 001211C0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80124264 001211C4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80124268 001211C8  38 21 00 18 */	addi r1, r1, 0x18
/* 8012426C 001211CC  7C 08 03 A6 */	mtlr r0
/* 80124270 001211D0  4E 80 00 20 */	blr 

.global makePcamLongVibrationEvent__22PcamLongVibrationEventFffff
makePcamLongVibrationEvent__22PcamLongVibrationEventFffff:
/* 80124274 001211D4  7C 08 02 A6 */	mflr r0
/* 80124278 001211D8  90 01 00 04 */	stw r0, 4(r1)
/* 8012427C 001211DC  94 21 FF 88 */	stwu r1, -0x78(r1)
/* 80124280 001211E0  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 80124284 001211E4  FF E0 20 90 */	fmr f31, f4
/* 80124288 001211E8  DB C1 00 68 */	stfd f30, 0x68(r1)
/* 8012428C 001211EC  FF C0 18 90 */	fmr f30, f3
/* 80124290 001211F0  DB A1 00 60 */	stfd f29, 0x60(r1)
/* 80124294 001211F4  FF A0 10 90 */	fmr f29, f2
/* 80124298 001211F8  DB 81 00 58 */	stfd f28, 0x58(r1)
/* 8012429C 001211FC  FF 80 08 90 */	fmr f28, f1
/* 801242A0 00121200  93 E1 00 54 */	stw r31, 0x54(r1)
/* 801242A4 00121204  93 C1 00 50 */	stw r30, 0x50(r1)
/* 801242A8 00121208  7C 7E 1B 78 */	mr r30, r3
/* 801242AC 0012120C  80 83 00 1C */	lwz r4, 0x1c(r3)
/* 801242B0 00121210  38 61 00 44 */	addi r3, r1, 0x44
/* 801242B4 00121214  38 A4 00 14 */	addi r5, r4, 0x14
/* 801242B8 00121218  38 84 00 08 */	addi r4, r4, 8
/* 801242BC 0012121C  4B FF 8C 71 */	bl __ct__9NVector3fFR8Vector3fR8Vector3f
/* 801242C0 00121220  7C 7F 1B 78 */	mr r31, r3
/* 801242C4 00121224  4B FF 8E 3D */	bl normalize__9NVector3fFv
/* 801242C8 00121228  38 61 00 2C */	addi r3, r1, 0x2c
/* 801242CC 0012122C  38 9F 00 00 */	addi r4, r31, 0
/* 801242D0 00121230  4B FF 7C 7D */	bl __ct__12NOrientationFR8Vector3f
/* 801242D4 00121234  7C 7F 1B 78 */	mr r31, r3
/* 801242D8 00121238  4B FF 7D 3D */	bl normalize__12NOrientationFv
/* 801242DC 0012123C  FC 20 E0 90 */	fmr f1, f28
/* 801242E0 00121240  3B FF 00 0C */	addi r31, r31, 0xc
/* 801242E4 00121244  FC 40 F0 90 */	fmr f2, f30
/* 801242E8 00121248  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 801242EC 0012124C  FC 60 F8 90 */	fmr f3, f31
/* 801242F0 00121250  C0 82 A1 20 */	lfs f4, lbl_803EA320@sda21(r2)
/* 801242F4 00121254  38 BF 00 00 */	addi r5, r31, 0
/* 801242F8 00121258  38 9E 00 20 */	addi r4, r30, 0x20
/* 801242FC 0012125C  48 00 29 1D */	bl makeVibrationEvent__18PeveVibrationEventFfP12NPosture3DIOR9NVector3ffff
/* 80124300 00121260  FC 00 F8 50 */	fneg f0, f31
/* 80124304 00121264  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 80124308 00121268  FC 20 E8 90 */	fmr f1, f29
/* 8012430C 0012126C  38 BF 00 00 */	addi r5, r31, 0
/* 80124310 00121270  FC 40 F0 90 */	fmr f2, f30
/* 80124314 00121274  EC 80 E8 24 */	fdivs f4, f0, f29
/* 80124318 00121278  38 9E 00 20 */	addi r4, r30, 0x20
/* 8012431C 0012127C  FC 60 F8 90 */	fmr f3, f31
/* 80124320 00121280  48 00 28 F9 */	bl makeVibrationEvent__18PeveVibrationEventFfP12NPosture3DIOR9NVector3ffff
/* 80124324 00121284  80 01 00 7C */	lwz r0, 0x7c(r1)
/* 80124328 00121288  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 8012432C 0012128C  CB C1 00 68 */	lfd f30, 0x68(r1)
/* 80124330 00121290  CB A1 00 60 */	lfd f29, 0x60(r1)
/* 80124334 00121294  CB 81 00 58 */	lfd f28, 0x58(r1)
/* 80124338 00121298  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 8012433C 0012129C  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 80124340 001212A0  38 21 00 78 */	addi r1, r1, 0x78
/* 80124344 001212A4  7C 08 03 A6 */	mtlr r0
/* 80124348 001212A8  4E 80 00 20 */	blr 

.global __ct__18PcamVibrationEventFP10PcamCamera
__ct__18PcamVibrationEventFP10PcamCamera:
/* 8012434C 001212AC  7C 08 02 A6 */	mflr r0
/* 80124350 001212B0  90 01 00 04 */	stw r0, 4(r1)
/* 80124354 001212B4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80124358 001212B8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8012435C 001212BC  3B E4 00 00 */	addi r31, r4, 0
/* 80124360 001212C0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80124364 001212C4  3B C3 00 00 */	addi r30, r3, 0
/* 80124368 001212C8  48 00 28 15 */	bl __ct__18PeveVibrationEventFv
/* 8012436C 001212CC  3C 60 80 2C */	lis r3, __vt__18PcamVibrationEvent@ha
/* 80124370 001212D0  38 03 55 08 */	addi r0, r3, __vt__18PcamVibrationEvent@l
/* 80124374 001212D4  90 1E 00 00 */	stw r0, 0(r30)
/* 80124378 001212D8  38 7E 00 58 */	addi r3, r30, 0x58
/* 8012437C 001212DC  48 00 15 9D */	bl __ct__19PeveCameraPostureIOFv
/* 80124380 001212E0  93 FE 00 54 */	stw r31, 0x54(r30)
/* 80124384 001212E4  38 7E 00 58 */	addi r3, r30, 0x58
/* 80124388 001212E8  80 9E 00 54 */	lwz r4, 0x54(r30)
/* 8012438C 001212EC  48 00 15 DD */	bl construct__19PeveCameraPostureIOFP10PcamCamera
/* 80124390 001212F0  C0 02 A1 24 */	lfs f0, lbl_803EA324@sda21(r2)
/* 80124394 001212F4  7F C3 F3 78 */	mr r3, r30
/* 80124398 001212F8  D0 1E 00 48 */	stfs f0, 0x48(r30)
/* 8012439C 001212FC  C0 02 A1 28 */	lfs f0, lbl_803EA328@sda21(r2)
/* 801243A0 00121300  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 801243A4 00121304  C0 02 A1 2C */	lfs f0, lbl_803EA32C@sda21(r2)
/* 801243A8 00121308  D0 1E 00 50 */	stfs f0, 0x50(r30)
/* 801243AC 0012130C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801243B0 00121310  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801243B4 00121314  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 801243B8 00121318  38 21 00 18 */	addi r1, r1, 0x18
/* 801243BC 0012131C  7C 08 03 A6 */	mtlr r0
/* 801243C0 00121320  4E 80 00 20 */	blr 

.global makePcamVibrationEvent__18PcamVibrationEventFv
makePcamVibrationEvent__18PcamVibrationEventFv:
/* 801243C4 00121324  7C 08 02 A6 */	mflr r0
/* 801243C8 00121328  90 01 00 04 */	stw r0, 4(r1)
/* 801243CC 0012132C  94 21 FF B8 */	stwu r1, -0x48(r1)
/* 801243D0 00121330  93 E1 00 44 */	stw r31, 0x44(r1)
/* 801243D4 00121334  93 C1 00 40 */	stw r30, 0x40(r1)
/* 801243D8 00121338  7C 7E 1B 78 */	mr r30, r3
/* 801243DC 0012133C  80 83 00 54 */	lwz r4, 0x54(r3)
/* 801243E0 00121340  38 61 00 34 */	addi r3, r1, 0x34
/* 801243E4 00121344  38 A4 00 14 */	addi r5, r4, 0x14
/* 801243E8 00121348  38 84 00 08 */	addi r4, r4, 8
/* 801243EC 0012134C  4B FF 8B 41 */	bl __ct__9NVector3fFR8Vector3fR8Vector3f
/* 801243F0 00121350  7C 7F 1B 78 */	mr r31, r3
/* 801243F4 00121354  4B FF 8D 0D */	bl normalize__9NVector3fFv
/* 801243F8 00121358  38 61 00 1C */	addi r3, r1, 0x1c
/* 801243FC 0012135C  38 9F 00 00 */	addi r4, r31, 0
/* 80124400 00121360  4B FF 7B 4D */	bl __ct__12NOrientationFR8Vector3f
/* 80124404 00121364  7C 7F 1B 78 */	mr r31, r3
/* 80124408 00121368  4B FF 7C 0D */	bl normalize__12NOrientationFv
/* 8012440C 0012136C  C0 7E 00 50 */	lfs f3, 0x50(r30)
/* 80124410 00121370  38 BF 00 0C */	addi r5, r31, 0xc
/* 80124414 00121374  C0 3E 00 48 */	lfs f1, 0x48(r30)
/* 80124418 00121378  7F C3 F3 78 */	mr r3, r30
/* 8012441C 0012137C  FC 00 18 50 */	fneg f0, f3
/* 80124420 00121380  C0 5E 00 4C */	lfs f2, 0x4c(r30)
/* 80124424 00121384  38 9E 00 58 */	addi r4, r30, 0x58
/* 80124428 00121388  EC 80 08 24 */	fdivs f4, f0, f1
/* 8012442C 0012138C  48 00 27 ED */	bl makeVibrationEvent__18PeveVibrationEventFfP12NPosture3DIOR9NVector3ffff
/* 80124430 00121390  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80124434 00121394  83 E1 00 44 */	lwz r31, 0x44(r1)
/* 80124438 00121398  83 C1 00 40 */	lwz r30, 0x40(r1)
/* 8012443C 0012139C  38 21 00 48 */	addi r1, r1, 0x48
/* 80124440 001213A0  7C 08 03 A6 */	mtlr r0
/* 80124444 001213A4  4E 80 00 20 */	blr 

.global __ct__15PcamDamageEventFP10PcamCamera
__ct__15PcamDamageEventFP10PcamCamera:
/* 80124448 001213A8  7C 08 02 A6 */	mflr r0
/* 8012444C 001213AC  90 01 00 04 */	stw r0, 4(r1)
/* 80124450 001213B0  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80124454 001213B4  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80124458 001213B8  3B E4 00 00 */	addi r31, r4, 0
/* 8012445C 001213BC  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80124460 001213C0  3B C3 00 00 */	addi r30, r3, 0
/* 80124464 001213C4  48 00 27 19 */	bl __ct__18PeveVibrationEventFv
/* 80124468 001213C8  3C 60 80 2C */	lis r3, __vt__15PcamDamageEvent@ha
/* 8012446C 001213CC  38 03 54 9C */	addi r0, r3, __vt__15PcamDamageEvent@l
/* 80124470 001213D0  90 1E 00 00 */	stw r0, 0(r30)
/* 80124474 001213D4  38 7E 00 58 */	addi r3, r30, 0x58
/* 80124478 001213D8  48 00 14 A1 */	bl __ct__19PeveCameraPostureIOFv
/* 8012447C 001213DC  93 FE 00 54 */	stw r31, 0x54(r30)
/* 80124480 001213E0  38 7E 00 58 */	addi r3, r30, 0x58
/* 80124484 001213E4  80 9E 00 54 */	lwz r4, 0x54(r30)
/* 80124488 001213E8  48 00 14 E1 */	bl construct__19PeveCameraPostureIOFP10PcamCamera
/* 8012448C 001213EC  C0 02 A1 24 */	lfs f0, lbl_803EA324@sda21(r2)
/* 80124490 001213F0  7F C3 F3 78 */	mr r3, r30
/* 80124494 001213F4  D0 1E 00 48 */	stfs f0, 0x48(r30)
/* 80124498 001213F8  C0 02 A1 28 */	lfs f0, lbl_803EA328@sda21(r2)
/* 8012449C 001213FC  D0 1E 00 4C */	stfs f0, 0x4c(r30)
/* 801244A0 00121400  C0 02 A1 2C */	lfs f0, lbl_803EA32C@sda21(r2)
/* 801244A4 00121404  D0 1E 00 50 */	stfs f0, 0x50(r30)
/* 801244A8 00121408  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801244AC 0012140C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801244B0 00121410  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 801244B4 00121414  38 21 00 18 */	addi r1, r1, 0x18
/* 801244B8 00121418  7C 08 03 A6 */	mtlr r0
/* 801244BC 0012141C  4E 80 00 20 */	blr 

.global makePcamDamageEvent__15PcamDamageEventFv
makePcamDamageEvent__15PcamDamageEventFv:
/* 801244C0 00121420  7C 08 02 A6 */	mflr r0
/* 801244C4 00121424  90 01 00 04 */	stw r0, 4(r1)
/* 801244C8 00121428  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 801244CC 0012142C  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 801244D0 00121430  93 C1 00 28 */	stw r30, 0x28(r1)
/* 801244D4 00121434  7C 7E 1B 78 */	mr r30, r3
/* 801244D8 00121438  80 83 00 54 */	lwz r4, 0x54(r3)
/* 801244DC 0012143C  38 61 00 1C */	addi r3, r1, 0x1c
/* 801244E0 00121440  38 A4 00 14 */	addi r5, r4, 0x14
/* 801244E4 00121444  38 84 00 08 */	addi r4, r4, 8
/* 801244E8 00121448  4B FF 8A 45 */	bl __ct__9NVector3fFR8Vector3fR8Vector3f
/* 801244EC 0012144C  7C 7F 1B 78 */	mr r31, r3
/* 801244F0 00121450  4B FF 8C 11 */	bl normalize__9NVector3fFv
/* 801244F4 00121454  C0 7E 00 50 */	lfs f3, 0x50(r30)
/* 801244F8 00121458  7F C3 F3 78 */	mr r3, r30
/* 801244FC 0012145C  C0 3E 00 48 */	lfs f1, 0x48(r30)
/* 80124500 00121460  7F E5 FB 78 */	mr r5, r31
/* 80124504 00121464  FC 00 18 50 */	fneg f0, f3
/* 80124508 00121468  C0 5E 00 4C */	lfs f2, 0x4c(r30)
/* 8012450C 0012146C  38 9E 00 58 */	addi r4, r30, 0x58
/* 80124510 00121470  EC 80 08 24 */	fdivs f4, f0, f1
/* 80124514 00121474  48 00 27 05 */	bl makeVibrationEvent__18PeveVibrationEventFfP12NPosture3DIOR9NVector3ffff
/* 80124518 00121478  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8012451C 0012147C  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80124520 00121480  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80124524 00121484  38 21 00 30 */	addi r1, r1, 0x30
/* 80124528 00121488  7C 08 03 A6 */	mtlr r0
/* 8012452C 0012148C  4E 80 00 20 */	blr 

.global update__19PcamRandomMoveEventFv
update__19PcamRandomMoveEventFv:
/* 80124530 00121490  7C 08 02 A6 */	mflr r0
/* 80124534 00121494  90 01 00 04 */	stw r0, 4(r1)
/* 80124538 00121498  94 21 FF 50 */	stwu r1, -0xb0(r1)
/* 8012453C 0012149C  93 E1 00 AC */	stw r31, 0xac(r1)
/* 80124540 001214A0  93 C1 00 A8 */	stw r30, 0xa8(r1)
/* 80124544 001214A4  7C 7E 1B 78 */	mr r30, r3
/* 80124548 001214A8  80 63 00 08 */	lwz r3, 8(r3)
/* 8012454C 001214AC  28 03 00 00 */	cmplwi r3, 0
/* 80124550 001214B0  41 82 00 14 */	beq lbl_80124564
/* 80124554 001214B4  81 83 00 00 */	lwz r12, 0(r3)
/* 80124558 001214B8  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8012455C 001214BC  7D 88 03 A6 */	mtlr r12
/* 80124560 001214C0  4E 80 00 21 */	blrl 
lbl_80124564:
/* 80124564 001214C4  38 61 00 6C */	addi r3, r1, 0x6c
/* 80124568 001214C8  4B FF 88 ED */	bl __ct__9NVector3fFv
/* 8012456C 001214CC  48 0F 3B 05 */	bl rand
/* 80124570 001214D0  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 80124574 001214D4  C8 82 A1 40 */	lfd f4, lbl_803EA340@sda21(r2)
/* 80124578 001214D8  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 8012457C 001214DC  3F E0 43 30 */	lis r31, 0x4330
/* 80124580 001214E0  C0 62 A1 34 */	lfs f3, lbl_803EA334@sda21(r2)
/* 80124584 001214E4  93 E1 00 A0 */	stw r31, 0xa0(r1)
/* 80124588 001214E8  C0 42 A1 30 */	lfs f2, lbl_803EA330@sda21(r2)
/* 8012458C 001214EC  C8 21 00 A0 */	lfd f1, 0xa0(r1)
/* 80124590 001214F0  C0 02 A1 3C */	lfs f0, lbl_803EA33C@sda21(r2)
/* 80124594 001214F4  EC 81 20 28 */	fsubs f4, f1, f4
/* 80124598 001214F8  C0 22 A1 38 */	lfs f1, lbl_803EA338@sda21(r2)
/* 8012459C 001214FC  EC 64 18 24 */	fdivs f3, f4, f3
/* 801245A0 00121500  EC 42 00 F2 */	fmuls f2, f2, f3
/* 801245A4 00121504  EC 00 00 B2 */	fmuls f0, f0, f2
/* 801245A8 00121508  EC 01 00 2A */	fadds f0, f1, f0
/* 801245AC 0012150C  D0 01 00 6C */	stfs f0, 0x6c(r1)
/* 801245B0 00121510  48 0F 3A C1 */	bl rand
/* 801245B4 00121514  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 801245B8 00121518  C8 82 A1 40 */	lfd f4, lbl_803EA340@sda21(r2)
/* 801245BC 0012151C  90 01 00 9C */	stw r0, 0x9c(r1)
/* 801245C0 00121520  C0 62 A1 34 */	lfs f3, lbl_803EA334@sda21(r2)
/* 801245C4 00121524  93 E1 00 98 */	stw r31, 0x98(r1)
/* 801245C8 00121528  C0 42 A1 30 */	lfs f2, lbl_803EA330@sda21(r2)
/* 801245CC 0012152C  C8 21 00 98 */	lfd f1, 0x98(r1)
/* 801245D0 00121530  C0 02 A1 3C */	lfs f0, lbl_803EA33C@sda21(r2)
/* 801245D4 00121534  EC 81 20 28 */	fsubs f4, f1, f4
/* 801245D8 00121538  C0 22 A1 38 */	lfs f1, lbl_803EA338@sda21(r2)
/* 801245DC 0012153C  EC 64 18 24 */	fdivs f3, f4, f3
/* 801245E0 00121540  EC 42 00 F2 */	fmuls f2, f2, f3
/* 801245E4 00121544  EC 00 00 B2 */	fmuls f0, f0, f2
/* 801245E8 00121548  EC 01 00 2A */	fadds f0, f1, f0
/* 801245EC 0012154C  D0 01 00 70 */	stfs f0, 0x70(r1)
/* 801245F0 00121550  48 0F 3A 81 */	bl rand
/* 801245F4 00121554  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 801245F8 00121558  C8 82 A1 40 */	lfd f4, lbl_803EA340@sda21(r2)
/* 801245FC 0012155C  90 01 00 94 */	stw r0, 0x94(r1)
/* 80124600 00121560  C0 62 A1 34 */	lfs f3, lbl_803EA334@sda21(r2)
/* 80124604 00121564  93 E1 00 90 */	stw r31, 0x90(r1)
/* 80124608 00121568  C0 42 A1 30 */	lfs f2, lbl_803EA330@sda21(r2)
/* 8012460C 0012156C  C8 21 00 90 */	lfd f1, 0x90(r1)
/* 80124610 00121570  C0 02 A1 3C */	lfs f0, lbl_803EA33C@sda21(r2)
/* 80124614 00121574  EC 81 20 28 */	fsubs f4, f1, f4
/* 80124618 00121578  C0 22 A1 38 */	lfs f1, lbl_803EA338@sda21(r2)
/* 8012461C 0012157C  EC 64 18 24 */	fdivs f3, f4, f3
/* 80124620 00121580  EC 42 00 F2 */	fmuls f2, f2, f3
/* 80124624 00121584  EC 00 00 B2 */	fmuls f0, f0, f2
/* 80124628 00121588  EC 01 00 2A */	fadds f0, f1, f0
/* 8012462C 0012158C  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 80124630 00121590  C0 3E 00 14 */	lfs f1, 0x14(r30)
/* 80124634 00121594  C0 01 00 6C */	lfs f0, 0x6c(r1)
/* 80124638 00121598  EC 00 00 72 */	fmuls f0, f0, f1
/* 8012463C 0012159C  D0 01 00 6C */	stfs f0, 0x6c(r1)
/* 80124640 001215A0  C0 01 00 70 */	lfs f0, 0x70(r1)
/* 80124644 001215A4  EC 00 00 72 */	fmuls f0, f0, f1
/* 80124648 001215A8  D0 01 00 70 */	stfs f0, 0x70(r1)
/* 8012464C 001215AC  C0 01 00 74 */	lfs f0, 0x74(r1)
/* 80124650 001215B0  EC 00 00 72 */	fmuls f0, f0, f1
/* 80124654 001215B4  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 80124658 001215B8  80 7E 00 24 */	lwz r3, 0x24(r30)
/* 8012465C 001215BC  C0 01 00 6C */	lfs f0, 0x6c(r1)
/* 80124660 001215C0  C4 23 00 08 */	lfsu f1, 8(r3)
/* 80124664 001215C4  EC 01 00 2A */	fadds f0, f1, f0
/* 80124668 001215C8  D0 03 00 00 */	stfs f0, 0(r3)
/* 8012466C 001215CC  C0 23 00 04 */	lfs f1, 4(r3)
/* 80124670 001215D0  C0 01 00 70 */	lfs f0, 0x70(r1)
/* 80124674 001215D4  EC 01 00 2A */	fadds f0, f1, f0
/* 80124678 001215D8  D0 03 00 04 */	stfs f0, 4(r3)
/* 8012467C 001215DC  C0 23 00 08 */	lfs f1, 8(r3)
/* 80124680 001215E0  C0 01 00 74 */	lfs f0, 0x74(r1)
/* 80124684 001215E4  EC 01 00 2A */	fadds f0, f1, f0
/* 80124688 001215E8  D0 03 00 08 */	stfs f0, 8(r3)
/* 8012468C 001215EC  48 0F 39 E5 */	bl rand
/* 80124690 001215F0  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 80124694 001215F4  C8 82 A1 40 */	lfd f4, lbl_803EA340@sda21(r2)
/* 80124698 001215F8  90 01 00 8C */	stw r0, 0x8c(r1)
/* 8012469C 001215FC  C0 62 A1 34 */	lfs f3, lbl_803EA334@sda21(r2)
/* 801246A0 00121600  93 E1 00 88 */	stw r31, 0x88(r1)
/* 801246A4 00121604  C0 42 A1 30 */	lfs f2, lbl_803EA330@sda21(r2)
/* 801246A8 00121608  C8 21 00 88 */	lfd f1, 0x88(r1)
/* 801246AC 0012160C  C0 02 A1 3C */	lfs f0, lbl_803EA33C@sda21(r2)
/* 801246B0 00121610  EC 81 20 28 */	fsubs f4, f1, f4
/* 801246B4 00121614  C0 22 A1 38 */	lfs f1, lbl_803EA338@sda21(r2)
/* 801246B8 00121618  EC 64 18 24 */	fdivs f3, f4, f3
/* 801246BC 0012161C  EC 42 00 F2 */	fmuls f2, f2, f3
/* 801246C0 00121620  EC 00 00 B2 */	fmuls f0, f0, f2
/* 801246C4 00121624  EC 01 00 2A */	fadds f0, f1, f0
/* 801246C8 00121628  D0 01 00 6C */	stfs f0, 0x6c(r1)
/* 801246CC 0012162C  48 0F 39 A5 */	bl rand
/* 801246D0 00121630  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 801246D4 00121634  C8 82 A1 40 */	lfd f4, lbl_803EA340@sda21(r2)
/* 801246D8 00121638  90 01 00 84 */	stw r0, 0x84(r1)
/* 801246DC 0012163C  C0 62 A1 34 */	lfs f3, lbl_803EA334@sda21(r2)
/* 801246E0 00121640  93 E1 00 80 */	stw r31, 0x80(r1)
/* 801246E4 00121644  C0 42 A1 30 */	lfs f2, lbl_803EA330@sda21(r2)
/* 801246E8 00121648  C8 21 00 80 */	lfd f1, 0x80(r1)
/* 801246EC 0012164C  C0 02 A1 3C */	lfs f0, lbl_803EA33C@sda21(r2)
/* 801246F0 00121650  EC 81 20 28 */	fsubs f4, f1, f4
/* 801246F4 00121654  C0 22 A1 38 */	lfs f1, lbl_803EA338@sda21(r2)
/* 801246F8 00121658  EC 64 18 24 */	fdivs f3, f4, f3
/* 801246FC 0012165C  EC 42 00 F2 */	fmuls f2, f2, f3
/* 80124700 00121660  EC 00 00 B2 */	fmuls f0, f0, f2
/* 80124704 00121664  EC 01 00 2A */	fadds f0, f1, f0
/* 80124708 00121668  D0 01 00 70 */	stfs f0, 0x70(r1)
/* 8012470C 0012166C  48 0F 39 65 */	bl rand
/* 80124710 00121670  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 80124714 00121674  C8 82 A1 40 */	lfd f4, lbl_803EA340@sda21(r2)
/* 80124718 00121678  90 01 00 7C */	stw r0, 0x7c(r1)
/* 8012471C 0012167C  C0 62 A1 34 */	lfs f3, lbl_803EA334@sda21(r2)
/* 80124720 00121680  93 E1 00 78 */	stw r31, 0x78(r1)
/* 80124724 00121684  C0 42 A1 30 */	lfs f2, lbl_803EA330@sda21(r2)
/* 80124728 00121688  C8 21 00 78 */	lfd f1, 0x78(r1)
/* 8012472C 0012168C  C0 02 A1 3C */	lfs f0, lbl_803EA33C@sda21(r2)
/* 80124730 00121690  EC 81 20 28 */	fsubs f4, f1, f4
/* 80124734 00121694  C0 22 A1 38 */	lfs f1, lbl_803EA338@sda21(r2)
/* 80124738 00121698  EC 64 18 24 */	fdivs f3, f4, f3
/* 8012473C 0012169C  EC 42 00 F2 */	fmuls f2, f2, f3
/* 80124740 001216A0  EC 00 00 B2 */	fmuls f0, f0, f2
/* 80124744 001216A4  EC 01 00 2A */	fadds f0, f1, f0
/* 80124748 001216A8  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 8012474C 001216AC  C0 3E 00 14 */	lfs f1, 0x14(r30)
/* 80124750 001216B0  C0 01 00 6C */	lfs f0, 0x6c(r1)
/* 80124754 001216B4  EC 00 00 72 */	fmuls f0, f0, f1
/* 80124758 001216B8  D0 01 00 6C */	stfs f0, 0x6c(r1)
/* 8012475C 001216BC  C0 01 00 70 */	lfs f0, 0x70(r1)
/* 80124760 001216C0  EC 00 00 72 */	fmuls f0, f0, f1
/* 80124764 001216C4  D0 01 00 70 */	stfs f0, 0x70(r1)
/* 80124768 001216C8  C0 01 00 74 */	lfs f0, 0x74(r1)
/* 8012476C 001216CC  EC 00 00 72 */	fmuls f0, f0, f1
/* 80124770 001216D0  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 80124774 001216D4  80 7E 00 24 */	lwz r3, 0x24(r30)
/* 80124778 001216D8  C0 01 00 6C */	lfs f0, 0x6c(r1)
/* 8012477C 001216DC  C4 23 00 14 */	lfsu f1, 0x14(r3)
/* 80124780 001216E0  EC 01 00 2A */	fadds f0, f1, f0
/* 80124784 001216E4  D0 03 00 00 */	stfs f0, 0(r3)
/* 80124788 001216E8  C0 23 00 04 */	lfs f1, 4(r3)
/* 8012478C 001216EC  C0 01 00 70 */	lfs f0, 0x70(r1)
/* 80124790 001216F0  EC 01 00 2A */	fadds f0, f1, f0
/* 80124794 001216F4  D0 03 00 04 */	stfs f0, 4(r3)
/* 80124798 001216F8  C0 23 00 08 */	lfs f1, 8(r3)
/* 8012479C 001216FC  C0 01 00 74 */	lfs f0, 0x74(r1)
/* 801247A0 00121700  EC 01 00 2A */	fadds f0, f1, f0
/* 801247A4 00121704  D0 03 00 08 */	stfs f0, 8(r3)
/* 801247A8 00121708  80 01 00 B4 */	lwz r0, 0xb4(r1)
/* 801247AC 0012170C  83 E1 00 AC */	lwz r31, 0xac(r1)
/* 801247B0 00121710  83 C1 00 A8 */	lwz r30, 0xa8(r1)
/* 801247B4 00121714  38 21 00 B0 */	addi r1, r1, 0xb0
/* 801247B8 00121718  7C 08 03 A6 */	mtlr r0
/* 801247BC 0012171C  4E 80 00 20 */	blr 

.global __ct__22PcamSideVibrationEventFP10PcamCamera
__ct__22PcamSideVibrationEventFP10PcamCamera:
/* 801247C0 00121720  7C 08 02 A6 */	mflr r0
/* 801247C4 00121724  90 01 00 04 */	stw r0, 4(r1)
/* 801247C8 00121728  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801247CC 0012172C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801247D0 00121730  3B E4 00 00 */	addi r31, r4, 0
/* 801247D4 00121734  38 80 00 00 */	li r4, 0
/* 801247D8 00121738  93 C1 00 10 */	stw r30, 0x10(r1)
/* 801247DC 0012173C  3B C3 00 00 */	addi r30, r3, 0
/* 801247E0 00121740  48 00 0D 71 */	bl __ct__9PeveEventFi
/* 801247E4 00121744  3C 60 80 2C */	lis r3, __vt__22PcamSideVibrationEvent@ha
/* 801247E8 00121748  38 03 53 90 */	addi r0, r3, __vt__22PcamSideVibrationEvent@l
/* 801247EC 0012174C  90 1E 00 00 */	stw r0, 0(r30)
/* 801247F0 00121750  38 7E 00 1C */	addi r3, r30, 0x1c
/* 801247F4 00121754  48 00 14 75 */	bl __ct__17PeveTimeConditionFv
/* 801247F8 00121758  38 7E 00 2C */	addi r3, r30, 0x2c
/* 801247FC 0012175C  4B FF 73 3D */	bl __ct__18NVibrationFunctionFv
/* 80124800 00121760  3C 60 80 2C */	lis r3, __vt__9NFunction@ha
/* 80124804 00121764  38 03 42 5C */	addi r0, r3, __vt__9NFunction@l
/* 80124808 00121768  3C 60 80 2C */	lis r3, __vt__19NPolynomialFunction@ha
/* 8012480C 0012176C  90 1E 00 3C */	stw r0, 0x3c(r30)
/* 80124810 00121770  38 03 42 4C */	addi r0, r3, __vt__19NPolynomialFunction@l
/* 80124814 00121774  90 1E 00 3C */	stw r0, 0x3c(r30)
/* 80124818 00121778  38 7E 00 40 */	addi r3, r30, 0x40
/* 8012481C 0012177C  4B FF 85 A5 */	bl __ct__7NVectorFv
/* 80124820 00121780  93 FE 00 28 */	stw r31, 0x28(r30)
/* 80124824 00121784  38 60 00 08 */	li r3, 8
/* 80124828 00121788  4B F2 27 DD */	bl alloc__6SystemFUl
/* 8012482C 0012178C  38 83 00 00 */	addi r4, r3, 0
/* 80124830 00121790  38 7E 00 3C */	addi r3, r30, 0x3c
/* 80124834 00121794  38 A0 00 02 */	li r5, 2
/* 80124838 00121798  4B FF 6E AD */	bl construct__19NPolynomialFunctionFPfi
/* 8012483C 0012179C  38 7E 00 1C */	addi r3, r30, 0x1c
/* 80124840 001217A0  C0 22 A1 20 */	lfs f1, lbl_803EA320@sda21(r2)
/* 80124844 001217A4  48 00 14 6D */	bl construct__17PeveTimeConditionFf
/* 80124848 001217A8  C0 02 A1 48 */	lfs f0, lbl_803EA348@sda21(r2)
/* 8012484C 001217AC  7F C3 F3 78 */	mr r3, r30
/* 80124850 001217B0  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 80124854 001217B4  C0 02 A1 28 */	lfs f0, lbl_803EA328@sda21(r2)
/* 80124858 001217B8  D0 1E 00 14 */	stfs f0, 0x14(r30)
/* 8012485C 001217BC  C0 2D E3 5C */	lfs f1, pi__6NMathF@sda21(r13)
/* 80124860 001217C0  C0 02 A1 4C */	lfs f0, lbl_803EA34C@sda21(r2)
/* 80124864 001217C4  EC 01 00 32 */	fmuls f0, f1, f0
/* 80124868 001217C8  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 8012486C 001217CC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80124870 001217D0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80124874 001217D4  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80124878 001217D8  38 21 00 18 */	addi r1, r1, 0x18
/* 8012487C 001217DC  7C 08 03 A6 */	mtlr r0
/* 80124880 001217E0  4E 80 00 20 */	blr 

.global makePcamSideVibrationEvent__22PcamSideVibrationEventFv
makePcamSideVibrationEvent__22PcamSideVibrationEventFv:
/* 80124884 001217E4  7C 08 02 A6 */	mflr r0
/* 80124888 001217E8  90 01 00 04 */	stw r0, 4(r1)
/* 8012488C 001217EC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80124890 001217F0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80124894 001217F4  7C 7F 1B 78 */	mr r31, r3
/* 80124898 001217F8  38 1F 00 1C */	addi r0, r31, 0x1c
/* 8012489C 001217FC  C0 03 00 10 */	lfs f0, 0x10(r3)
/* 801248A0 00121800  38 7F 00 2C */	addi r3, r31, 0x2c
/* 801248A4 00121804  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 801248A8 00121808  90 1F 00 08 */	stw r0, 8(r31)
/* 801248AC 0012180C  C0 22 A1 20 */	lfs f1, lbl_803EA320@sda21(r2)
/* 801248B0 00121810  C0 5F 00 14 */	lfs f2, 0x14(r31)
/* 801248B4 00121814  C0 62 A1 30 */	lfs f3, lbl_803EA330@sda21(r2)
/* 801248B8 00121818  4B FF 72 BD */	bl makeVibrationFunction__18NVibrationFunctionFfff
/* 801248BC 0012181C  C0 1F 00 18 */	lfs f0, 0x18(r31)
/* 801248C0 00121820  80 7F 00 40 */	lwz r3, 0x40(r31)
/* 801248C4 00121824  D0 03 00 00 */	stfs f0, 0(r3)
/* 801248C8 00121828  C0 3F 00 18 */	lfs f1, 0x18(r31)
/* 801248CC 0012182C  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 801248D0 00121830  FC 20 08 50 */	fneg f1, f1
/* 801248D4 00121834  80 7F 00 40 */	lwz r3, 0x40(r31)
/* 801248D8 00121838  EC 01 00 24 */	fdivs f0, f1, f0
/* 801248DC 0012183C  D0 03 00 04 */	stfs f0, 4(r3)
/* 801248E0 00121840  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801248E4 00121844  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801248E8 00121848  38 21 00 18 */	addi r1, r1, 0x18
/* 801248EC 0012184C  7C 08 03 A6 */	mtlr r0
/* 801248F0 00121850  4E 80 00 20 */	blr 

.global update__22PcamSideVibrationEventFv
update__22PcamSideVibrationEventFv:
/* 801248F4 00121854  7C 08 02 A6 */	mflr r0
/* 801248F8 00121858  90 01 00 04 */	stw r0, 4(r1)
/* 801248FC 0012185C  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 80124900 00121860  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 80124904 00121864  DB C1 00 18 */	stfd f30, 0x18(r1)
/* 80124908 00121868  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8012490C 0012186C  7C 7F 1B 78 */	mr r31, r3
/* 80124910 00121870  80 63 00 08 */	lwz r3, 8(r3)
/* 80124914 00121874  28 03 00 00 */	cmplwi r3, 0
/* 80124918 00121878  41 82 00 14 */	beq lbl_8012492C
/* 8012491C 0012187C  81 83 00 00 */	lwz r12, 0(r3)
/* 80124920 00121880  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80124924 00121884  7D 88 03 A6 */	mtlr r12
/* 80124928 00121888  4E 80 00 21 */	blrl 
lbl_8012492C:
/* 8012492C 0012188C  38 7F 00 2C */	addi r3, r31, 0x2c
/* 80124930 00121890  C3 DF 00 20 */	lfs f30, 0x20(r31)
/* 80124934 00121894  81 9F 00 2C */	lwz r12, 0x2c(r31)
/* 80124938 00121898  FC 20 F0 90 */	fmr f1, f30
/* 8012493C 0012189C  81 8C 00 08 */	lwz r12, 8(r12)
/* 80124940 001218A0  7D 88 03 A6 */	mtlr r12
/* 80124944 001218A4  4E 80 00 21 */	blrl 
/* 80124948 001218A8  38 7F 00 3C */	addi r3, r31, 0x3c
/* 8012494C 001218AC  FF E0 08 90 */	fmr f31, f1
/* 80124950 001218B0  81 9F 00 3C */	lwz r12, 0x3c(r31)
/* 80124954 001218B4  FC 20 F0 90 */	fmr f1, f30
/* 80124958 001218B8  81 8C 00 08 */	lwz r12, 8(r12)
/* 8012495C 001218BC  7D 88 03 A6 */	mtlr r12
/* 80124960 001218C0  4E 80 00 21 */	blrl 
/* 80124964 001218C4  EC 01 07 F2 */	fmuls f0, f1, f31
/* 80124968 001218C8  80 7F 00 28 */	lwz r3, 0x28(r31)
/* 8012496C 001218CC  D0 03 00 00 */	stfs f0, 0(r3)
/* 80124970 001218D0  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80124974 001218D4  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 80124978 001218D8  CB C1 00 18 */	lfd f30, 0x18(r1)
/* 8012497C 001218DC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80124980 001218E0  38 21 00 28 */	addi r1, r1, 0x28
/* 80124984 001218E4  7C 08 03 A6 */	mtlr r0
/* 80124988 001218E8  4E 80 00 20 */	blr 

.global finish__22PcamSideVibrationEventFv
finish__22PcamSideVibrationEventFv:
/* 8012498C 001218EC  C0 02 A1 20 */	lfs f0, lbl_803EA320@sda21(r2)
/* 80124990 001218F0  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80124994 001218F4  D0 03 00 00 */	stfs f0, 0(r3)
/* 80124998 001218F8  4E 80 00 20 */	blr 

.global setEventOption__9PeveEventFi
setEventOption__9PeveEventFi:
/* 8012499C 001218FC  80 03 00 0C */	lwz r0, 0xc(r3)
/* 801249A0 00121900  7C 00 23 78 */	or r0, r0, r4
/* 801249A4 00121904  90 03 00 0C */	stw r0, 0xc(r3)
/* 801249A8 00121908  4E 80 00 20 */	blr 

.global clearEventOption__9PeveEventFi
clearEventOption__9PeveEventFi:
/* 801249AC 0012190C  80 03 00 0C */	lwz r0, 0xc(r3)
/* 801249B0 00121910  7C 00 20 78 */	andc r0, r0, r4
/* 801249B4 00121914  90 03 00 0C */	stw r0, 0xc(r3)
/* 801249B8 00121918  4E 80 00 20 */	blr 

.global setEventOptions__9PeveEventFi
setEventOptions__9PeveEventFi:
/* 801249BC 0012191C  90 83 00 0C */	stw r4, 0xc(r3)
/* 801249C0 00121920  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802C5320:
	.asciz "pcammotionevents.cpp"
.balign 4
lbl_802C5338:
	.asciz "pcammotionevents"
.balign 4
lbl_802C534C:
	.asciz "PcamSideVibrationEvent"
.balign 4
lbl_802C5364:
	.asciz "PeveEvent"
.balign 4
lbl_802C5370:
	.4byte __RTTI__5NNode
	.4byte 0
	.4byte 0
lbl_802C537C:
	.4byte __RTTI__5NNode
	.4byte 0
	.4byte __RTTI__9PeveEvent
	.4byte 0
	.4byte 0
.global __vt__22PcamSideVibrationEvent
__vt__22PcamSideVibrationEvent:
	.4byte __RTTI__22PcamSideVibrationEvent
	.4byte 0
	.4byte setChild__5NNodeFiP5NNode
	.4byte addChild__5NNodeFP5NNode
	.4byte addChild__5NNodeFiP5NNode
	.4byte removeChild__5NNodeFP5NNode
	.4byte removeChild__5NNodeFi
	.4byte removeAllChildren__5NNodeFv
	.4byte reset__9PeveEventFv
	.4byte update__22PcamSideVibrationEventFv
	.4byte isFinished__9PeveEventFv
	.4byte finish__22PcamSideVibrationEventFv
	.4byte setEventOption__9PeveEventFi
	.4byte clearEventOption__9PeveEventFi
	.4byte setEventOptions__9PeveEventFi
.balign 4
lbl_802C53CC:
	.asciz "NFunction"
.balign 4
	.4byte 0
	.4byte 0
	.4byte 0
.balign 4
lbl_802C53E4:
	.asciz "PcamRandomMoveEvent"
.balign 4
lbl_802C53F8:
	.4byte __RTTI__5NNode
	.4byte 0
	.4byte __RTTI__9PeveEvent
	.4byte 0
	.4byte 0
.global __vt__19PcamRandomMoveEvent
__vt__19PcamRandomMoveEvent:
	.4byte __RTTI__19PcamRandomMoveEvent
	.4byte 0
	.4byte setChild__5NNodeFiP5NNode
	.4byte addChild__5NNodeFP5NNode
	.4byte addChild__5NNodeFiP5NNode
	.4byte removeChild__5NNodeFP5NNode
	.4byte removeChild__5NNodeFi
	.4byte removeAllChildren__5NNodeFv
	.4byte reset__9PeveEventFv
	.4byte update__19PcamRandomMoveEventFv
	.4byte isFinished__9PeveEventFv
	.4byte finish__9PeveEventFv
	.4byte setEventOption__9PeveEventFi
	.4byte clearEventOption__9PeveEventFi
	.4byte setEventOptions__9PeveEventFi
.balign 4
lbl_802C5448:
	.asciz "PcamDamageEvent"
.balign 4
lbl_802C5458:
	.asciz "PeveVibrationEvent"
.balign 4
lbl_802C546C:
	.4byte __RTTI__5NNode
	.4byte 0
	.4byte __RTTI__9PeveEvent
	.4byte 0
	.4byte 0
lbl_802C5480:
	.4byte __RTTI__5NNode
	.4byte 0
	.4byte __RTTI__9PeveEvent
	.4byte 0
	.4byte __RTTI__18PeveVibrationEvent
	.4byte 0
	.4byte 0
.global __vt__15PcamDamageEvent
__vt__15PcamDamageEvent:
	.4byte __RTTI__15PcamDamageEvent
	.4byte 0
	.4byte setChild__5NNodeFiP5NNode
	.4byte addChild__5NNodeFP5NNode
	.4byte addChild__5NNodeFiP5NNode
	.4byte removeChild__5NNodeFP5NNode
	.4byte removeChild__5NNodeFi
	.4byte removeAllChildren__5NNodeFv
	.4byte reset__9PeveEventFv
	.4byte update__18PeveVibrationEventFv
	.4byte isFinished__9PeveEventFv
	.4byte finish__9PeveEventFv
	.4byte setEventOption__9PeveEventFi
	.4byte clearEventOption__9PeveEventFi
	.4byte setEventOptions__9PeveEventFi
.balign 4
lbl_802C54D8:
	.asciz "PcamVibrationEvent"
.balign 4
lbl_802C54EC:
	.4byte __RTTI__5NNode
	.4byte 0
	.4byte __RTTI__9PeveEvent
	.4byte 0
	.4byte __RTTI__18PeveVibrationEvent
	.4byte 0
	.4byte 0
.global __vt__18PcamVibrationEvent
__vt__18PcamVibrationEvent:
	.4byte __RTTI__18PcamVibrationEvent
	.4byte 0
	.4byte setChild__5NNodeFiP5NNode
	.4byte addChild__5NNodeFP5NNode
	.4byte addChild__5NNodeFiP5NNode
	.4byte removeChild__5NNodeFP5NNode
	.4byte removeChild__5NNodeFi
	.4byte removeAllChildren__5NNodeFv
	.4byte reset__9PeveEventFv
	.4byte update__18PeveVibrationEventFv
	.4byte isFinished__9PeveEventFv
	.4byte finish__9PeveEventFv
	.4byte setEventOption__9PeveEventFi
	.4byte clearEventOption__9PeveEventFi
	.4byte setEventOptions__9PeveEventFi
.balign 4
lbl_802C5544:
	.asciz "PcamLongVibrationEvent"
.balign 4
lbl_802C555C:
	.asciz "PeveSerialEvent"
.balign 4
lbl_802C556C:
	.4byte __RTTI__5NNode
	.4byte 0
	.4byte __RTTI__9PeveEvent
	.4byte 0
	.4byte 0
lbl_802C5580:
	.4byte __RTTI__5NNode
	.4byte 0
	.4byte __RTTI__9PeveEvent
	.4byte 0
	.4byte __RTTI__15PeveSerialEvent
	.4byte 0
	.4byte 0
.global __vt__22PcamLongVibrationEvent
__vt__22PcamLongVibrationEvent:
	.4byte __RTTI__22PcamLongVibrationEvent
	.4byte 0
	.4byte setChild__5NNodeFiP5NNode
	.4byte addChild__5NNodeFP5NNode
	.4byte addChild__5NNodeFiP5NNode
	.4byte removeChild__5NNodeFP5NNode
	.4byte removeChild__5NNodeFi
	.4byte removeAllChildren__5NNodeFv
	.4byte reset__15PeveSerialEventFv
	.4byte update__15PeveSerialEventFv
	.4byte isFinished__15PeveSerialEventFv
	.4byte finish__9PeveEventFv
	.4byte setEventOption__9PeveEventFi
	.4byte clearEventOption__9PeveEventFi
	.4byte setEventOptions__9PeveEventFi

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803E3288:
	.asciz "NNode"
.balign 4
__RTTI__5NNode:
	.4byte lbl_803E3288
	.4byte 0
__RTTI__9PeveEvent:
	.4byte lbl_802C5364
	.4byte lbl_802C5370
__RTTI__22PcamSideVibrationEvent:
	.4byte lbl_802C534C
	.4byte lbl_802C537C
__RTTI__19PcamRandomMoveEvent:
	.4byte lbl_802C53E4
	.4byte lbl_802C53F8
__RTTI__18PeveVibrationEvent:
	.4byte lbl_802C5458
	.4byte lbl_802C546C
__RTTI__15PcamDamageEvent:
	.4byte lbl_802C5448
	.4byte lbl_802C5480
__RTTI__18PcamVibrationEvent:
	.4byte lbl_802C54D8
	.4byte lbl_802C54EC
__RTTI__15PeveSerialEvent:
	.4byte lbl_802C555C
	.4byte lbl_802C556C
__RTTI__22PcamLongVibrationEvent:
	.4byte lbl_802C5544
	.4byte lbl_802C5580

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803EA320:
	.float 0.0
lbl_803EA324:
	.float 0.8
lbl_803EA328:
	.float 0.2
lbl_803EA32C:
	.float 16.0
lbl_803EA330:
	.float 1.0
lbl_803EA334:
	.float 32767.0
lbl_803EA338:
	.float -1.0
lbl_803EA33C:
	.float 2.0
lbl_803EA340:
	.4byte 0x43300000
	.4byte 0x80000000
lbl_803EA348:
	.float 0.6
lbl_803EA34C:
	.float 0.125
