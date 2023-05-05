.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn makeObjectPellet__Fv, local
/* 80099D1C 00096C7C  7C 08 02 A6 */	mflr r0
/* 80099D20 00096C80  38 60 00 28 */	li r3, 0x28
/* 80099D24 00096C84  90 01 00 04 */	stw r0, 4(r1)
/* 80099D28 00096C88  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80099D2C 00096C8C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80099D30 00096C90  4B FA D2 D5 */	bl alloc__6SystemFUl
/* 80099D34 00096C94  7C 7F 1B 79 */	or. r31, r3, r3
/* 80099D38 00096C98  41 82 00 4C */	beq .L_80099D84
/* 80099D3C 00096C9C  3C 80 80 2B */	lis r4, lbl_802B0904@ha
/* 80099D40 00096CA0  3C 60 80 2B */	lis r3, lbl_802B0910@ha
/* 80099D44 00096CA4  38 A4 09 04 */	addi r5, r4, lbl_802B0904@l
/* 80099D48 00096CA8  3C 80 70 65 */	lis r4, 0x70656C74@ha
/* 80099D4C 00096CAC  38 C3 09 10 */	addi r6, r3, lbl_802B0910@l
/* 80099D50 00096CB0  38 7F 00 00 */	addi r3, r31, 0
/* 80099D54 00096CB4  38 84 6C 74 */	addi r4, r4, 0x70656C74@l
/* 80099D58 00096CB8  48 04 0F 5D */	bl __ct__7GenBaseFUlPcPc
/* 80099D5C 00096CBC  3C 60 80 2C */	lis r3, __vt__9GenObject@ha
/* 80099D60 00096CC0  38 03 AB 70 */	addi r0, r3, __vt__9GenObject@l
/* 80099D64 00096CC4  3C 60 80 2B */	lis r3, __vt__15GenObjectPellet@ha
/* 80099D68 00096CC8  90 1F 00 04 */	stw r0, 4(r31)
/* 80099D6C 00096CCC  38 03 09 84 */	addi r0, r3, __vt__15GenObjectPellet@l
/* 80099D70 00096CD0  90 1F 00 04 */	stw r0, 4(r31)
/* 80099D74 00096CD4  38 7F 00 1C */	addi r3, r31, 0x1c
/* 80099D78 00096CD8  4B FA A0 E5 */	bl __ct__4ID32Fv
/* 80099D7C 00096CDC  38 00 00 00 */	li r0, 0
/* 80099D80 00096CE0  90 1F 00 18 */	stw r0, 0x18(r31)
.L_80099D84:
/* 80099D84 00096CE4  7F E3 FB 78 */	mr r3, r31
/* 80099D88 00096CE8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80099D8C 00096CEC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80099D90 00096CF0  38 21 00 10 */	addi r1, r1, 0x10
/* 80099D94 00096CF4  7C 08 03 A6 */	mtlr r0
/* 80099D98 00096CF8  4E 80 00 20 */	blr 
.endfn makeObjectPellet__Fv

.fn initialise__15GenObjectPelletFv, global
/* 80099D9C 00096CFC  80 ED 30 74 */	lwz r7, factory__16GenObjectFactory@sda21(r13)
/* 80099DA0 00096D00  80 A7 00 00 */	lwz r5, 0(r7)
/* 80099DA4 00096D04  80 07 00 04 */	lwz r0, 4(r7)
/* 80099DA8 00096D08  7C 05 00 00 */	cmpw r5, r0
/* 80099DAC 00096D0C  4C 80 00 20 */	bgelr 
/* 80099DB0 00096D10  3C 80 70 65 */	lis r4, 0x70656C74@ha
/* 80099DB4 00096D14  80 67 00 08 */	lwz r3, 8(r7)
/* 80099DB8 00096D18  38 84 6C 74 */	addi r4, r4, 0x70656C74@l
/* 80099DBC 00096D1C  54 A0 20 36 */	slwi r0, r5, 4
/* 80099DC0 00096D20  7C 83 01 2E */	stwx r4, r3, r0
/* 80099DC4 00096D24  3C C0 80 0A */	lis r6, makeObjectPellet__Fv@ha
/* 80099DC8 00096D28  3C 80 80 2B */	lis r4, lbl_802B0910@ha
/* 80099DCC 00096D2C  80 07 00 00 */	lwz r0, 0(r7)
/* 80099DD0 00096D30  3C 60 76 30 */	lis r3, 0x76302E30@ha
/* 80099DD4 00096D34  80 A7 00 08 */	lwz r5, 8(r7)
/* 80099DD8 00096D38  38 C6 9D 1C */	addi r6, r6, makeObjectPellet__Fv@l
/* 80099DDC 00096D3C  54 00 20 36 */	slwi r0, r0, 4
/* 80099DE0 00096D40  7C A5 02 14 */	add r5, r5, r0
/* 80099DE4 00096D44  90 C5 00 04 */	stw r6, 4(r5)
/* 80099DE8 00096D48  38 A4 09 10 */	addi r5, r4, lbl_802B0910@l
/* 80099DEC 00096D4C  38 83 2E 30 */	addi r4, r3, 0x76302E30@l
/* 80099DF0 00096D50  80 07 00 00 */	lwz r0, 0(r7)
/* 80099DF4 00096D54  80 67 00 08 */	lwz r3, 8(r7)
/* 80099DF8 00096D58  54 00 20 36 */	slwi r0, r0, 4
/* 80099DFC 00096D5C  7C 63 02 14 */	add r3, r3, r0
/* 80099E00 00096D60  90 A3 00 08 */	stw r5, 8(r3)
/* 80099E04 00096D64  80 07 00 00 */	lwz r0, 0(r7)
/* 80099E08 00096D68  80 67 00 08 */	lwz r3, 8(r7)
/* 80099E0C 00096D6C  54 00 20 36 */	slwi r0, r0, 4
/* 80099E10 00096D70  7C 63 02 14 */	add r3, r3, r0
/* 80099E14 00096D74  90 83 00 0C */	stw r4, 0xc(r3)
/* 80099E18 00096D78  80 67 00 00 */	lwz r3, 0(r7)
/* 80099E1C 00096D7C  38 03 00 01 */	addi r0, r3, 1
/* 80099E20 00096D80  90 07 00 00 */	stw r0, 0(r7)
/* 80099E24 00096D84  4E 80 00 20 */	blr 
.endfn initialise__15GenObjectPelletFv

.fn doRead__15GenObjectPelletFR18RandomAccessStream, global
/* 80099E28 00096D88  7C 08 02 A6 */	mflr r0
/* 80099E2C 00096D8C  90 01 00 04 */	stw r0, 4(r1)
/* 80099E30 00096D90  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80099E34 00096D94  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80099E38 00096D98  3B E3 00 00 */	addi r31, r3, 0
/* 80099E3C 00096D9C  38 7F 00 1C */	addi r3, r31, 0x1c
/* 80099E40 00096DA0  4B FA A2 5D */	bl read__4ID32FR18RandomAccessStream
/* 80099E44 00096DA4  80 6D 30 1C */	lwz r3, pelletMgr@sda21(r13)
/* 80099E48 00096DA8  80 9F 00 1C */	lwz r4, 0x1c(r31)
/* 80099E4C 00096DAC  4B FF ED FD */	bl getConfigIndex__9PelletMgrFUl
/* 80099E50 00096DB0  90 7F 00 18 */	stw r3, 0x18(r31)
/* 80099E54 00096DB4  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 80099E58 00096DB8  2C 00 FF FF */	cmpwi r0, -1
/* 80099E5C 00096DBC  40 82 00 0C */	bne .L_80099E68
/* 80099E60 00096DC0  38 00 00 00 */	li r0, 0
/* 80099E64 00096DC4  90 1F 00 18 */	stw r0, 0x18(r31)
.L_80099E68:
/* 80099E68 00096DC8  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80099E6C 00096DCC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80099E70 00096DD0  38 21 00 18 */	addi r1, r1, 0x18
/* 80099E74 00096DD4  7C 08 03 A6 */	mtlr r0
/* 80099E78 00096DD8  4E 80 00 20 */	blr 
.endfn doRead__15GenObjectPelletFR18RandomAccessStream

.fn doWrite__15GenObjectPelletFR18RandomAccessStream, global
/* 80099E7C 00096DDC  7C 08 02 A6 */	mflr r0
/* 80099E80 00096DE0  90 01 00 04 */	stw r0, 4(r1)
/* 80099E84 00096DE4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80099E88 00096DE8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80099E8C 00096DEC  7C 9F 23 78 */	mr r31, r4
/* 80099E90 00096DF0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 80099E94 00096DF4  7C 7E 1B 78 */	mr r30, r3
/* 80099E98 00096DF8  80 6D 30 1C */	lwz r3, pelletMgr@sda21(r13)
/* 80099E9C 00096DFC  80 9E 00 18 */	lwz r4, 0x18(r30)
/* 80099EA0 00096E00  4B FF ED E9 */	bl getConfigFromIdx__9PelletMgrFi
/* 80099EA4 00096E04  38 83 00 2C */	addi r4, r3, 0x2c
/* 80099EA8 00096E08  80 03 00 2C */	lwz r0, 0x2c(r3)
/* 80099EAC 00096E0C  38 7E 00 20 */	addi r3, r30, 0x20
/* 80099EB0 00096E10  38 84 00 04 */	addi r4, r4, 4
/* 80099EB4 00096E14  90 1E 00 1C */	stw r0, 0x1c(r30)
/* 80099EB8 00096E18  38 A0 00 05 */	li r5, 5
/* 80099EBC 00096E1C  48 17 AB 09 */	bl __copy
/* 80099EC0 00096E20  38 7E 00 1C */	addi r3, r30, 0x1c
/* 80099EC4 00096E24  38 9F 00 00 */	addi r4, r31, 0
/* 80099EC8 00096E28  4B FA A1 41 */	bl write__4ID32FR18RandomAccessStream
/* 80099ECC 00096E2C  38 7E 00 1C */	addi r3, r30, 0x1c
/* 80099ED0 00096E30  4B FA A2 89 */	bl print__4ID32Fv
/* 80099ED4 00096E34  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80099ED8 00096E38  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80099EDC 00096E3C  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 80099EE0 00096E40  38 21 00 18 */	addi r1, r1, 0x18
/* 80099EE4 00096E44  7C 08 03 A6 */	mtlr r0
/* 80099EE8 00096E48  4E 80 00 20 */	blr 
.endfn doWrite__15GenObjectPelletFR18RandomAccessStream

.fn updateUseList__15GenObjectPelletFP9Generatori, global
/* 80099EEC 00096E4C  7C 08 02 A6 */	mflr r0
/* 80099EF0 00096E50  7C 64 1B 78 */	mr r4, r3
/* 80099EF4 00096E54  90 01 00 04 */	stw r0, 4(r1)
/* 80099EF8 00096E58  94 21 FF F8 */	stwu r1, -8(r1)
/* 80099EFC 00096E5C  80 6D 30 1C */	lwz r3, pelletMgr@sda21(r13)
/* 80099F00 00096E60  80 84 00 1C */	lwz r4, 0x1c(r4)
/* 80099F04 00096E64  4B FF EE 21 */	bl getConfig__9PelletMgrFUl
/* 80099F08 00096E68  7C 64 1B 79 */	or. r4, r3, r3
/* 80099F0C 00096E6C  41 82 00 10 */	beq .L_80099F1C
/* 80099F10 00096E70  80 6D 30 1C */	lwz r3, pelletMgr@sda21(r13)
/* 80099F14 00096E74  80 84 00 44 */	lwz r4, 0x44(r4)
/* 80099F18 00096E78  4B FF EB ED */	bl addUseList__9PelletMgrFUl
.L_80099F1C:
/* 80099F1C 00096E7C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80099F20 00096E80  38 21 00 08 */	addi r1, r1, 8
/* 80099F24 00096E84  7C 08 03 A6 */	mtlr r0
/* 80099F28 00096E88  4E 80 00 20 */	blr 
.endfn updateUseList__15GenObjectPelletFP9Generatori

.fn birth__15GenObjectPelletFR9BirthInfo, global
/* 80099F2C 00096E8C  7C 08 02 A6 */	mflr r0
/* 80099F30 00096E90  90 01 00 04 */	stw r0, 4(r1)
/* 80099F34 00096E94  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 80099F38 00096E98  93 E1 00 34 */	stw r31, 0x34(r1)
/* 80099F3C 00096E9C  3B E3 00 00 */	addi r31, r3, 0
/* 80099F40 00096EA0  38 7F 00 1C */	addi r3, r31, 0x1c
/* 80099F44 00096EA4  93 C1 00 30 */	stw r30, 0x30(r1)
/* 80099F48 00096EA8  3B C4 00 00 */	addi r30, r4, 0
/* 80099F4C 00096EAC  4B FA A2 0D */	bl print__4ID32Fv
/* 80099F50 00096EB0  80 6D 30 1C */	lwz r3, pelletMgr@sda21(r13)
/* 80099F54 00096EB4  38 A0 00 00 */	li r5, 0
/* 80099F58 00096EB8  80 9F 00 1C */	lwz r4, 0x1c(r31)
/* 80099F5C 00096EBC  4B FF E6 55 */	bl newPellet__9PelletMgrFUlP10PelletView
/* 80099F60 00096EC0  7C 7F 1B 79 */	or. r31, r3, r3
/* 80099F64 00096EC4  41 82 00 AC */	beq .L_8009A010
/* 80099F68 00096EC8  7F E3 FB 78 */	mr r3, r31
/* 80099F6C 00096ECC  81 9F 00 00 */	lwz r12, 0(r31)
/* 80099F70 00096ED0  7F C4 F3 78 */	mr r4, r30
/* 80099F74 00096ED4  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 80099F78 00096ED8  7D 88 03 A6 */	mtlr r12
/* 80099F7C 00096EDC  4E 80 00 21 */	blrl 
/* 80099F80 00096EE0  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 80099F84 00096EE4  7F E3 FB 78 */	mr r3, r31
/* 80099F88 00096EE8  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 80099F8C 00096EEC  38 80 00 00 */	li r4, 0
/* 80099F90 00096EF0  90 BF 00 88 */	stw r5, 0x88(r31)
/* 80099F94 00096EF4  90 1F 00 8C */	stw r0, 0x8c(r31)
/* 80099F98 00096EF8  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 80099F9C 00096EFC  90 1F 00 90 */	stw r0, 0x90(r31)
/* 80099FA0 00096F00  C0 1F 00 8C */	lfs f0, 0x8c(r31)
/* 80099FA4 00096F04  D0 1F 00 A0 */	stfs f0, 0xa0(r31)
/* 80099FA8 00096F08  80 1E 00 24 */	lwz r0, 0x24(r30)
/* 80099FAC 00096F0C  90 1F 00 64 */	stw r0, 0x64(r31)
/* 80099FB0 00096F10  81 9F 00 00 */	lwz r12, 0(r31)
/* 80099FB4 00096F14  81 8C 00 34 */	lwz r12, 0x34(r12)
/* 80099FB8 00096F18  7D 88 03 A6 */	mtlr r12
/* 80099FBC 00096F1C  4E 80 00 21 */	blrl 
/* 80099FC0 00096F20  80 7E 00 24 */	lwz r3, 0x24(r30)
/* 80099FC4 00096F24  80 63 00 28 */	lwz r3, 0x28(r3)
/* 80099FC8 00096F28  80 03 00 34 */	lwz r0, 0x34(r3)
/* 80099FCC 00096F2C  2C 00 00 00 */	cmpwi r0, 0
/* 80099FD0 00096F30  41 82 00 10 */	beq .L_80099FE0
/* 80099FD4 00096F34  80 1F 00 C8 */	lwz r0, 0xc8(r31)
/* 80099FD8 00096F38  64 00 00 01 */	oris r0, r0, 1
/* 80099FDC 00096F3C  90 1F 00 C8 */	stw r0, 0xc8(r31)
.L_80099FE0:
/* 80099FE0 00096F40  80 7F 05 5C */	lwz r3, 0x55c(r31)
/* 80099FE4 00096F44  38 9F 00 00 */	addi r4, r31, 0
/* 80099FE8 00096F48  38 A0 00 00 */	li r5, 0
/* 80099FEC 00096F4C  C0 03 00 FC */	lfs f0, 0xfc(r3)
/* 80099FF0 00096F50  D0 1F 00 7C */	stfs f0, 0x7c(r31)
/* 80099FF4 00096F54  D0 1F 00 80 */	stfs f0, 0x80(r31)
/* 80099FF8 00096F58  D0 1F 00 84 */	stfs f0, 0x84(r31)
/* 80099FFC 00096F5C  80 7F 04 70 */	lwz r3, 0x470(r31)
/* 8009A000 00096F60  81 83 00 00 */	lwz r12, 0(r3)
/* 8009A004 00096F64  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8009A008 00096F68  7D 88 03 A6 */	mtlr r12
/* 8009A00C 00096F6C  4E 80 00 21 */	blrl 
.L_8009A010:
/* 8009A010 00096F70  7F E3 FB 78 */	mr r3, r31
/* 8009A014 00096F74  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8009A018 00096F78  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 8009A01C 00096F7C  83 C1 00 30 */	lwz r30, 0x30(r1)
/* 8009A020 00096F80  38 21 00 38 */	addi r1, r1, 0x38
/* 8009A024 00096F84  7C 08 03 A6 */	mtlr r0
/* 8009A028 00096F88  4E 80 00 20 */	blr 
.endfn birth__15GenObjectPelletFR9BirthInfo

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802B08E8, local
	.asciz "genPellet.cpp"
.endobj lbl_802B08E8
.balign 4
.obj lbl_802B08F8, local
	.asciz "genPellet"
.endobj lbl_802B08F8
.balign 4
.obj lbl_802B0904, local
	.asciz "object type"
.endobj lbl_802B0904
.balign 4
.obj lbl_802B0910, local # Shift-JIS
	.4byte 0x8379838C
	.4byte 0x83628367
	.4byte 0x82F082A4
	.4byte 0x82DE0000
.endobj lbl_802B0910
.balign 4
.obj lbl_802B0920, local
	.asciz "GenObjectPellet"
.endobj lbl_802B0920
.balign 4
.obj lbl_802B0930, local
	.asciz "Parameters"
.endobj lbl_802B0930
.balign 4
.obj lbl_802B093C, local
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B093C
.balign 4
.obj lbl_802B0948, local
	.asciz "GenObject"
.endobj lbl_802B0948
.balign 4
.obj lbl_802B0954, local
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte __RTTI__7GenBase
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B0954
.obj lbl_802B0968, local
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte __RTTI__7GenBase
	.4byte 0x00000000
	.4byte __RTTI__9GenObject
	.4byte 0x00000000
	.4byte 0x00000000
.endobj lbl_802B0968
.obj __vt__15GenObjectPellet, global
	.4byte __RTTI__15GenObjectPellet
	.4byte 0
	.4byte doWrite__15GenObjectPelletFR18RandomAccessStream
	.4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
	.4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
	.4byte doRead__15GenObjectPelletFR18RandomAccessStream
	.4byte update__7GenBaseFv
	.4byte render__7GenBaseFR8Graphics
	.4byte getLatestVersion__9GenObjectFv
	.4byte updateUseList__15GenObjectPelletFP9Generatori
	.4byte init__9GenObjectFP9Generator
	.4byte update__9GenObjectFP9Generator
	.4byte render__9GenObjectFR8GraphicsP9Generator
	.4byte birth__15GenObjectPelletFR9BirthInfo
.endobj __vt__15GenObjectPellet

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj __RTTI__10Parameters, local
	.4byte lbl_802B0930
	.4byte 0
.endobj __RTTI__10Parameters
.balign 4
.obj lbl_803DF708, local
	.asciz "GenBase"
.endobj lbl_803DF708
.balign 4
.obj __RTTI__7GenBase, local
	.4byte lbl_803DF708
	.4byte lbl_802B093C
.endobj __RTTI__7GenBase
.obj __RTTI__9GenObject, local
	.4byte lbl_802B0948
	.4byte lbl_802B0954
.endobj __RTTI__9GenObject
.obj __RTTI__15GenObjectPellet, local
	.4byte lbl_802B0920
	.4byte lbl_802B0968
.endobj __RTTI__15GenObjectPellet
