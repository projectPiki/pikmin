.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80128DC4 00125D24  38 1F 00 1C */	addi r0, r31, 0x1c
/* 80128DC8 00125D28  7D 07 32 14 */	add r8, r7, r6
/* 80128DCC 00125D2C  90 08 00 00 */	stw r0, 0(r8)
/* 80128DD0 00125D30  38 C0 00 00 */	li r6, 0
/* 80128DD4 00125D34  38 00 00 01 */	li r0, 1
/* 80128DD8 00125D38  90 C8 00 04 */	stw r6, 4(r8)
/* 80128DDC 00125D3C  1C E5 00 0C */	mulli r7, r5, 0xc
/* 80128DE0 00125D40  90 08 00 08 */	stw r0, 8(r8)
/* 80128DE4 00125D44  38 DF 00 28 */	addi r6, r31, 0x28
/* 80128DE8 00125D48  81 1E 00 84 */	lwz r8, 0x84(r30)
/* 80128DEC 00125D4C  1C A4 00 0C */	mulli r5, r4, 0xc
/* 80128DF0 00125D50  81 08 00 04 */	lwz r8, 4(r8)
/* 80128DF4 00125D54  38 9F 00 38 */	addi r4, r31, 0x38
/* 80128DF8 00125D58  81 48 00 08 */	lwz r10, 8(r8)
/* 80128DFC 00125D5C  1C 63 00 0C */	mulli r3, r3, 0xc
/* 80128E00 00125D60  7D 0A 3A 14 */	add r8, r10, r7
/* 80128E04 00125D64  90 C8 00 00 */	stw r6, 0(r8)
/* 80128E08 00125D68  7D 2A 2A 14 */	add r9, r10, r5
/* 80128E0C 00125D6C  7D 4A 1A 14 */	add r10, r10, r3
/* 80128E10 00125D70  C1 02 A2 20 */	lfs f8, lbl_803EA420@sda21(r2)
/* 80128E14 00125D74  38 7F 00 48 */	addi r3, r31, 0x48
/* 80128E18 00125D78  38 E0 FF FF */	li r7, -1
/* 80128E1C 00125D7C  D1 08 00 04 */	stfs f8, 4(r8)
/* 80128E20 00125D80  38 C0 00 03 */	li r6, 3
/* 80128E24 00125D84  38 A0 00 02 */	li r5, 2
/* 80128E28 00125D88  C0 E2 A2 24 */	lfs f7, lbl_803EA424@sda21(r2)
/* 80128E2C 00125D8C  D0 E8 00 08 */	stfs f7, 8(r8)
/* 80128E30 00125D90  90 89 00 00 */	stw r4, 0(r9)
/* 80128E34 00125D94  D1 09 00 04 */	stfs f8, 4(r9)
/* 80128E38 00125D98  C0 C2 A2 28 */	lfs f6, lbl_803EA428@sda21(r2)
/* 80128E3C 00125D9C  D0 C9 00 08 */	stfs f6, 8(r9)
/* 80128E40 00125DA0  90 6A 00 00 */	stw r3, 0(r10)
/* 80128E44 00125DA4  D1 0A 00 04 */	stfs f8, 4(r10)
/* 80128E48 00125DA8  C0 02 A2 2C */	lfs f0, lbl_803EA42C@sda21(r2)
/* 80128E4C 00125DAC  D0 0A 00 08 */	stfs f0, 8(r10)
/* 80128E50 00125DB0  80 9E 00 84 */	lwz r4, 0x84(r30)
/* 80128E54 00125DB4  80 64 00 00 */	lwz r3, 0(r4)
/* 80128E58 00125DB8  80 63 00 00 */	lwz r3, 0(r3)
/* 80128E5C 00125DBC  90 03 00 00 */	stw r0, 0(r3)
/* 80128E60 00125DC0  80 64 00 00 */	lwz r3, 0(r4)
/* 80128E64 00125DC4  80 63 00 00 */	lwz r3, 0(r3)
/* 80128E68 00125DC8  90 03 00 18 */	stw r0, 0x18(r3)
/* 80128E6C 00125DCC  80 64 00 00 */	lwz r3, 0(r4)
/* 80128E70 00125DD0  80 63 00 00 */	lwz r3, 0(r3)
/* 80128E74 00125DD4  90 E3 00 0C */	stw r7, 0xc(r3)
/* 80128E78 00125DD8  80 64 00 00 */	lwz r3, 0(r4)
/* 80128E7C 00125DDC  80 63 00 00 */	lwz r3, 0(r3)
/* 80128E80 00125DE0  90 C3 00 24 */	stw r6, 0x24(r3)
/* 80128E84 00125DE4  80 64 00 00 */	lwz r3, 0(r4)
/* 80128E88 00125DE8  80 63 00 00 */	lwz r3, 0(r3)
/* 80128E8C 00125DEC  90 03 00 28 */	stw r0, 0x28(r3)
/* 80128E90 00125DF0  80 64 00 00 */	lwz r3, 0(r4)
/* 80128E94 00125DF4  80 63 00 00 */	lwz r3, 0(r3)
/* 80128E98 00125DF8  90 A3 00 2C */	stw r5, 0x2c(r3)
/* 80128E9C 00125DFC  80 64 00 00 */	lwz r3, 0(r4)
/* 80128EA0 00125E00  80 63 00 00 */	lwz r3, 0(r3)
/* 80128EA4 00125E04  90 C3 00 30 */	stw r6, 0x30(r3)
/* 80128EA8 00125E08  80 64 00 00 */	lwz r3, 0(r4)
/* 80128EAC 00125E0C  80 63 00 00 */	lwz r3, 0(r3)
/* 80128EB0 00125E10  90 03 00 34 */	stw r0, 0x34(r3)
/* 80128EB4 00125E14  80 64 00 00 */	lwz r3, 0(r4)
/* 80128EB8 00125E18  80 63 00 00 */	lwz r3, 0(r3)
/* 80128EBC 00125E1C  90 03 00 38 */	stw r0, 0x38(r3)
/* 80128EC0 00125E20  80 64 00 00 */	lwz r3, 0(r4)
/* 80128EC4 00125E24  80 63 00 00 */	lwz r3, 0(r3)
/* 80128EC8 00125E28  90 A3 00 3C */	stw r5, 0x3c(r3)
/* 80128ECC 00125E2C  80 64 00 00 */	lwz r3, 0(r4)
/* 80128ED0 00125E30  80 63 00 00 */	lwz r3, 0(r3)
/* 80128ED4 00125E34  90 A3 00 40 */	stw r5, 0x40(r3)
/* 80128ED8 00125E38  80 64 00 04 */	lwz r3, 4(r4)
/* 80128EDC 00125E3C  C0 22 A2 88 */	lfs f1, lbl_803EA488@sda21(r2)
/* 80128EE0 00125E40  80 63 00 00 */	lwz r3, 0(r3)
/* 80128EE4 00125E44  D0 23 00 00 */	stfs f1, 0(r3)
/* 80128EE8 00125E48  80 64 00 04 */	lwz r3, 4(r4)
/* 80128EEC 00125E4C  C0 02 A2 8C */	lfs f0, lbl_803EA48C@sda21(r2)
/* 80128EF0 00125E50  80 63 00 00 */	lwz r3, 0(r3)
/* 80128EF4 00125E54  D0 03 00 04 */	stfs f0, 4(r3)
/* 80128EF8 00125E58  80 64 00 04 */	lwz r3, 4(r4)
/* 80128EFC 00125E5C  C0 A2 A2 34 */	lfs f5, lbl_803EA434@sda21(r2)
/* 80128F00 00125E60  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F04 00125E64  D0 A3 00 08 */	stfs f5, 8(r3)
/* 80128F08 00125E68  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F0C 00125E6C  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F10 00125E70  D0 C3 00 0C */	stfs f6, 0xc(r3)
/* 80128F14 00125E74  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F18 00125E78  C0 82 A2 74 */	lfs f4, lbl_803EA474@sda21(r2)
/* 80128F1C 00125E7C  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F20 00125E80  D0 83 00 10 */	stfs f4, 0x10(r3)
/* 80128F24 00125E84  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F28 00125E88  C0 02 A2 3C */	lfs f0, lbl_803EA43C@sda21(r2)
/* 80128F2C 00125E8C  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F30 00125E90  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 80128F34 00125E94  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F38 00125E98  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F3C 00125E9C  D0 23 00 18 */	stfs f1, 0x18(r3)
/* 80128F40 00125EA0  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F44 00125EA4  C0 02 A2 44 */	lfs f0, lbl_803EA444@sda21(r2)
/* 80128F48 00125EA8  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F4C 00125EAC  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 80128F50 00125EB0  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F54 00125EB4  C0 62 A2 30 */	lfs f3, lbl_803EA430@sda21(r2)
/* 80128F58 00125EB8  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F5C 00125EBC  D0 63 00 70 */	stfs f3, 0x70(r3)
/* 80128F60 00125EC0  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F64 00125EC4  C0 42 A2 4C */	lfs f2, lbl_803EA44C@sda21(r2)
/* 80128F68 00125EC8  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F6C 00125ECC  D0 43 00 20 */	stfs f2, 0x20(r3)
/* 80128F70 00125ED0  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F74 00125ED4  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F78 00125ED8  D0 43 00 24 */	stfs f2, 0x24(r3)
/* 80128F7C 00125EDC  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F80 00125EE0  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F84 00125EE4  D0 C3 00 28 */	stfs f6, 0x28(r3)
/* 80128F88 00125EE8  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F8C 00125EEC  C0 02 A2 90 */	lfs f0, lbl_803EA490@sda21(r2)
/* 80128F90 00125EF0  80 63 00 00 */	lwz r3, 0(r3)
/* 80128F94 00125EF4  D0 03 00 B4 */	stfs f0, 0xb4(r3)
/* 80128F98 00125EF8  80 64 00 04 */	lwz r3, 4(r4)
/* 80128F9C 00125EFC  C0 02 A2 54 */	lfs f0, lbl_803EA454@sda21(r2)
/* 80128FA0 00125F00  80 63 00 00 */	lwz r3, 0(r3)
/* 80128FA4 00125F04  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 80128FA8 00125F08  80 64 00 04 */	lwz r3, 4(r4)
/* 80128FAC 00125F0C  80 63 00 00 */	lwz r3, 0(r3)
/* 80128FB0 00125F10  D0 E3 00 30 */	stfs f7, 0x30(r3)
/* 80128FB4 00125F14  80 64 00 04 */	lwz r3, 4(r4)
/* 80128FB8 00125F18  C0 22 A2 68 */	lfs f1, lbl_803EA468@sda21(r2)
/* 80128FBC 00125F1C  80 63 00 00 */	lwz r3, 0(r3)
/* 80128FC0 00125F20  D0 23 00 3C */	stfs f1, 0x3c(r3)
/* 80128FC4 00125F24  80 64 00 04 */	lwz r3, 4(r4)
/* 80128FC8 00125F28  C0 02 A2 5C */	lfs f0, lbl_803EA45C@sda21(r2)
/* 80128FCC 00125F2C  80 63 00 00 */	lwz r3, 0(r3)
/* 80128FD0 00125F30  D0 03 00 40 */	stfs f0, 0x40(r3)
/* 80128FD4 00125F34  80 64 00 04 */	lwz r3, 4(r4)
/* 80128FD8 00125F38  80 63 00 00 */	lwz r3, 0(r3)
/* 80128FDC 00125F3C  D0 43 00 44 */	stfs f2, 0x44(r3)
/* 80128FE0 00125F40  80 64 00 04 */	lwz r3, 4(r4)
/* 80128FE4 00125F44  C0 02 A2 60 */	lfs f0, lbl_803EA460@sda21(r2)
/* 80128FE8 00125F48  80 63 00 00 */	lwz r3, 0(r3)
/* 80128FEC 00125F4C  D0 03 00 48 */	stfs f0, 0x48(r3)
/* 80128FF0 00125F50  80 64 00 04 */	lwz r3, 4(r4)
/* 80128FF4 00125F54  C0 02 A2 94 */	lfs f0, lbl_803EA494@sda21(r2)
/* 80128FF8 00125F58  80 63 00 00 */	lwz r3, 0(r3)
/* 80128FFC 00125F5C  D0 03 00 4C */	stfs f0, 0x4c(r3)
/* 80129000 00125F60  80 64 00 04 */	lwz r3, 4(r4)
/* 80129004 00125F64  80 63 00 00 */	lwz r3, 0(r3)
/* 80129008 00125F68  D0 E3 00 50 */	stfs f7, 0x50(r3)
/* 8012900C 00125F6C  80 64 00 04 */	lwz r3, 4(r4)
/* 80129010 00125F70  80 63 00 00 */	lwz r3, 0(r3)
/* 80129014 00125F74  D0 E3 00 54 */	stfs f7, 0x54(r3)
/* 80129018 00125F78  80 64 00 04 */	lwz r3, 4(r4)
/* 8012901C 00125F7C  80 63 00 00 */	lwz r3, 0(r3)
/* 80129020 00125F80  D0 23 00 68 */	stfs f1, 0x68(r3)
/* 80129024 00125F84  80 64 00 04 */	lwz r3, 4(r4)
/* 80129028 00125F88  C0 02 A2 6C */	lfs f0, lbl_803EA46C@sda21(r2)
/* 8012902C 00125F8C  80 63 00 00 */	lwz r3, 0(r3)
/* 80129030 00125F90  D0 03 00 78 */	stfs f0, 0x78(r3)
/* 80129034 00125F94  80 64 00 04 */	lwz r3, 4(r4)
/* 80129038 00125F98  C0 02 A2 70 */	lfs f0, lbl_803EA470@sda21(r2)
/* 8012903C 00125F9C  80 63 00 00 */	lwz r3, 0(r3)
/* 80129040 00125FA0  D0 03 00 7C */	stfs f0, 0x7c(r3)
/* 80129044 00125FA4  80 64 00 04 */	lwz r3, 4(r4)
/* 80129048 00125FA8  80 63 00 00 */	lwz r3, 0(r3)
/* 8012904C 00125FAC  D0 A3 00 80 */	stfs f5, 0x80(r3)
/* 80129050 00125FB0  80 64 00 04 */	lwz r3, 4(r4)
/* 80129054 00125FB4  80 63 00 00 */	lwz r3, 0(r3)
/* 80129058 00125FB8  D0 83 00 84 */	stfs f4, 0x84(r3)
/* 8012905C 00125FBC  80 A4 00 04 */	lwz r5, 4(r4)
/* 80129060 00125FC0  7F C3 F3 78 */	mr r3, r30
/* 80129064 00125FC4  C0 02 A2 38 */	lfs f0, lbl_803EA438@sda21(r2)
/* 80129068 00125FC8  80 A5 00 00 */	lwz r5, 0(r5)
/* 8012906C 00125FCC  D0 05 00 88 */	stfs f0, 0x88(r5)
/* 80129070 00125FD0  80 A4 00 04 */	lwz r5, 4(r4)
/* 80129074 00125FD4  80 A5 00 00 */	lwz r5, 0(r5)
/* 80129078 00125FD8  D1 05 00 8C */	stfs f8, 0x8c(r5)
/* 8012907C 00125FDC  80 A4 00 04 */	lwz r5, 4(r4)
/* 80129080 00125FE0  80 A5 00 00 */	lwz r5, 0(r5)
/* 80129084 00125FE4  D1 05 00 90 */	stfs f8, 0x90(r5)
/* 80129088 00125FE8  80 A4 00 04 */	lwz r5, 4(r4)
/* 8012908C 00125FEC  80 A5 00 00 */	lwz r5, 0(r5)
/* 80129090 00125FF0  D0 05 00 9C */	stfs f0, 0x9c(r5)
/* 80129094 00125FF4  80 A4 00 04 */	lwz r5, 4(r4)
/* 80129098 00125FF8  C0 02 A2 78 */	lfs f0, lbl_803EA478@sda21(r2)
/* 8012909C 00125FFC  80 A5 00 00 */	lwz r5, 0(r5)
/* 801290A0 00126000  D0 05 00 A0 */	stfs f0, 0xa0(r5)
/* 801290A4 00126004  80 A4 00 04 */	lwz r5, 4(r4)
/* 801290A8 00126008  80 A5 00 00 */	lwz r5, 0(r5)
/* 801290AC 0012600C  D0 A5 00 AC */	stfs f5, 0xac(r5)
/* 801290B0 00126010  80 A4 00 04 */	lwz r5, 4(r4)
/* 801290B4 00126014  C0 02 A2 7C */	lfs f0, lbl_803EA47C@sda21(r2)
/* 801290B8 00126018  80 A5 00 00 */	lwz r5, 0(r5)
/* 801290BC 0012601C  D0 05 00 B0 */	stfs f0, 0xb0(r5)
/* 801290C0 00126020  80 A4 00 00 */	lwz r5, 0(r4)
/* 801290C4 00126024  80 A5 00 00 */	lwz r5, 0(r5)
/* 801290C8 00126028  90 05 00 50 */	stw r0, 0x50(r5)
/* 801290CC 0012602C  80 A4 00 04 */	lwz r5, 4(r4)
/* 801290D0 00126030  80 A5 00 00 */	lwz r5, 0(r5)
/* 801290D4 00126034  D0 E5 00 CC */	stfs f7, 0xcc(r5)
/* 801290D8 00126038  80 A4 00 04 */	lwz r5, 4(r4)
/* 801290DC 0012603C  80 A5 00 00 */	lwz r5, 0(r5)
/* 801290E0 00126040  D0 A5 00 C8 */	stfs f5, 0xc8(r5)
/* 801290E4 00126044  80 84 00 04 */	lwz r4, 4(r4)
/* 801290E8 00126048  80 84 00 00 */	lwz r4, 0(r4)
/* 801290EC 0012604C  D0 64 00 D0 */	stfs f3, 0xd0(r4)
/* 801290F0 00126050  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 801290F4 00126054  83 E1 00 DC */	lwz r31, 0xdc(r1)
/* 801290F8 00126058  83 C1 00 D8 */	lwz r30, 0xd8(r1)
/* 801290FC 0012605C  38 21 00 E0 */	addi r1, r1, 0xe0
/* 80129100 00126060  7C 08 03 A6 */	mtlr r0
/* 80129104 00126064  4E 80 00 20 */	blr 

.global __ct__17TaiChappyStrategyFP14TekiParameters
__ct__17TaiChappyStrategyFP14TekiParameters:
/* 80129108 00126068  7C 08 02 A6 */	mflr r0
/* 8012910C 0012606C  38 A0 00 0F */	li r5, 0xf
/* 80129110 00126070  90 01 00 04 */	stw r0, 4(r1)
/* 80129114 00126074  94 21 FD E0 */	stwu r1, -0x220(r1)
/* 80129118 00126078  BD C1 01 D8 */	stmw r14, 0x1d8(r1)
/* 8012911C 0012607C  3A 04 00 00 */	addi r16, r4, 0
/* 80129120 00126080  3B 43 00 00 */	addi r26, r3, 0
/* 80129124 00126084  38 80 00 10 */	li r4, 0x10
/* 80129128 00126088  4B FF E2 BD */	bl __ct__11TaiStrategyFii
/* 8012912C 0012608C  3C 60 80 2C */	lis r3, __vt__17TaiChappyStrategy@ha
/* 80129130 00126090  38 03 6E 9C */	addi r0, r3, __vt__17TaiChappyStrategy@l
/* 80129134 00126094  90 1A 00 00 */	stw r0, 0(r26)
/* 80129138 00126098  38 60 00 08 */	li r3, 8
/* 8012913C 0012609C  4B F1 DE C9 */	bl alloc__6SystemFUl
/* 80129140 001260A0  3A 63 00 00 */	addi r19, r3, 0
/* 80129144 001260A4  7E 60 9B 79 */	or. r0, r19, r19
/* 80129148 001260A8  41 82 00 24 */	beq lbl_8012916C
/* 8012914C 001260AC  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80129150 001260B0  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80129154 001260B4  90 13 00 04 */	stw r0, 4(r19)
/* 80129158 001260B8  38 00 FF FF */	li r0, -1
/* 8012915C 001260BC  3C 60 80 2D */	lis r3, __vt__17TaiStopMoveAction@ha
/* 80129160 001260C0  90 13 00 00 */	stw r0, 0(r19)
/* 80129164 001260C4  38 03 9E C0 */	addi r0, r3, __vt__17TaiStopMoveAction@l
/* 80129168 001260C8  90 13 00 04 */	stw r0, 4(r19)
lbl_8012916C:
/* 8012916C 001260CC  38 60 00 0C */	li r3, 0xc
/* 80129170 001260D0  4B F1 DE 95 */	bl alloc__6SystemFUl
/* 80129174 001260D4  3A 83 00 00 */	addi r20, r3, 0
/* 80129178 001260D8  7E 80 A3 79 */	or. r0, r20, r20
/* 8012917C 001260DC  41 82 00 2C */	beq lbl_801291A8
/* 80129180 001260E0  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80129184 001260E4  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80129188 001260E8  90 14 00 04 */	stw r0, 4(r20)
/* 8012918C 001260EC  38 00 FF FF */	li r0, -1
/* 80129190 001260F0  3C 60 80 2D */	lis r3, __vt__21TaiStoppingMoveAction@ha
/* 80129194 001260F4  90 14 00 00 */	stw r0, 0(r20)
/* 80129198 001260F8  38 63 93 BC */	addi r3, r3, __vt__21TaiStoppingMoveAction@l
/* 8012919C 001260FC  38 00 00 06 */	li r0, 6
/* 801291A0 00126100  90 74 00 04 */	stw r3, 4(r20)
/* 801291A4 00126104  90 14 00 08 */	stw r0, 8(r20)
lbl_801291A8:
/* 801291A8 00126108  38 60 00 08 */	li r3, 8
/* 801291AC 0012610C  4B F1 DE 59 */	bl alloc__6SystemFUl
/* 801291B0 00126110  90 61 01 D4 */	stw r3, 0x1d4(r1)
/* 801291B4 00126114  80 01 01 D4 */	lwz r0, 0x1d4(r1)
/* 801291B8 00126118  28 00 00 00 */	cmplwi r0, 0
/* 801291BC 0012611C  41 82 00 30 */	beq lbl_801291EC
/* 801291C0 00126120  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801291C4 00126124  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 801291C8 00126128  80 61 01 D4 */	lwz r3, 0x1d4(r1)
/* 801291CC 0012612C  3C 80 80 2D */	lis r4, __vt__27TaiFinishStoppingMoveAction@ha
/* 801291D0 00126130  90 03 00 04 */	stw r0, 4(r3)
/* 801291D4 00126134  38 00 FF FF */	li r0, -1
/* 801291D8 00126138  80 61 01 D4 */	lwz r3, 0x1d4(r1)
/* 801291DC 0012613C  90 03 00 00 */	stw r0, 0(r3)
/* 801291E0 00126140  38 04 93 7C */	addi r0, r4, __vt__27TaiFinishStoppingMoveAction@l
/* 801291E4 00126144  80 61 01 D4 */	lwz r3, 0x1d4(r1)
/* 801291E8 00126148  90 03 00 04 */	stw r0, 4(r3)
lbl_801291EC:
/* 801291EC 0012614C  38 60 00 08 */	li r3, 8
/* 801291F0 00126150  4B F1 DE 15 */	bl alloc__6SystemFUl
/* 801291F4 00126154  3A A3 00 00 */	addi r21, r3, 0
/* 801291F8 00126158  7E A0 AB 79 */	or. r0, r21, r21
/* 801291FC 0012615C  41 82 00 24 */	beq lbl_80129220
/* 80129200 00126160  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80129204 00126164  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80129208 00126168  90 15 00 04 */	stw r0, 4(r21)
/* 8012920C 0012616C  38 00 00 00 */	li r0, 0
/* 80129210 00126170  3C 60 80 2D */	lis r3, __vt__13TaiDeadAction@ha
/* 80129214 00126174  90 15 00 00 */	stw r0, 0(r21)
/* 80129218 00126178  38 03 BD 28 */	addi r0, r3, __vt__13TaiDeadAction@l
/* 8012921C 0012617C  90 15 00 04 */	stw r0, 4(r21)
lbl_80129220:
/* 80129220 00126180  38 60 00 08 */	li r3, 8
/* 80129224 00126184  4B F1 DD E1 */	bl alloc__6SystemFUl
/* 80129228 00126188  3B 03 00 00 */	addi r24, r3, 0
/* 8012922C 0012618C  7F 00 C3 79 */	or. r0, r24, r24
/* 80129230 00126190  41 82 00 24 */	beq lbl_80129254
/* 80129234 00126194  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80129238 00126198  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012923C 0012619C  90 18 00 04 */	stw r0, 4(r24)
/* 80129240 001261A0  38 00 00 02 */	li r0, 2
/* 80129244 001261A4  3C 60 80 2D */	lis r3, __vt__16TaiPressedAction@ha
/* 80129248 001261A8  90 18 00 00 */	stw r0, 0(r24)
/* 8012924C 001261AC  38 03 B7 94 */	addi r0, r3, __vt__16TaiPressedAction@l
/* 80129250 001261B0  90 18 00 04 */	stw r0, 4(r24)
lbl_80129254:
/* 80129254 001261B4  38 60 00 08 */	li r3, 8
/* 80129258 001261B8  4B F1 DD AD */	bl alloc__6SystemFUl
/* 8012925C 001261BC  3A E3 00 00 */	addi r23, r3, 0
/* 80129260 001261C0  7E E0 BB 79 */	or. r0, r23, r23
/* 80129264 001261C4  41 82 00 30 */	beq lbl_80129294
/* 80129268 001261C8  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012926C 001261CC  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80129270 001261D0  90 17 00 04 */	stw r0, 4(r23)
/* 80129274 001261D4  38 00 00 0D */	li r0, 0xd
/* 80129278 001261D8  3C 60 80 2D */	lis r3, __vt__16TaiSmashedAction@ha
/* 8012927C 001261DC  90 17 00 00 */	stw r0, 0(r23)
/* 80129280 001261E0  38 03 B8 10 */	addi r0, r3, __vt__16TaiSmashedAction@l
/* 80129284 001261E4  3C 60 80 2C */	lis r3, __vt__22TaiChappySmashedAction@ha
/* 80129288 001261E8  90 17 00 04 */	stw r0, 4(r23)
/* 8012928C 001261EC  38 03 6C C4 */	addi r0, r3, __vt__22TaiChappySmashedAction@l
/* 80129290 001261F0  90 17 00 04 */	stw r0, 4(r23)
lbl_80129294:
/* 80129294 001261F4  38 60 00 14 */	li r3, 0x14
/* 80129298 001261F8  4B F1 DD 6D */	bl alloc__6SystemFUl
/* 8012929C 001261FC  3A C3 00 00 */	addi r22, r3, 0
/* 801292A0 00126200  7E C0 B3 79 */	or. r0, r22, r22
/* 801292A4 00126204  41 82 00 48 */	beq lbl_801292EC
/* 801292A8 00126208  80 90 00 84 */	lwz r4, 0x84(r16)
/* 801292AC 0012620C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 801292B0 00126210  3C A0 80 2D */	lis r5, __vt__19TaiResetTimerAction@ha
/* 801292B4 00126214  80 84 00 04 */	lwz r4, 4(r4)
/* 801292B8 00126218  38 63 66 20 */	addi r3, r3, __vt__9TaiAction@l
/* 801292BC 0012621C  38 00 FF FF */	li r0, -1
/* 801292C0 00126220  80 84 00 00 */	lwz r4, 0(r4)
/* 801292C4 00126224  38 C5 CA 0C */	addi r6, r5, __vt__19TaiResetTimerAction@l
/* 801292C8 00126228  38 A0 00 00 */	li r5, 0
/* 801292CC 0012622C  C0 04 00 CC */	lfs f0, 0xcc(r4)
/* 801292D0 00126230  90 76 00 04 */	stw r3, 4(r22)
/* 801292D4 00126234  90 16 00 00 */	stw r0, 0(r22)
/* 801292D8 00126238  90 D6 00 04 */	stw r6, 4(r22)
/* 801292DC 0012623C  90 B6 00 08 */	stw r5, 8(r22)
/* 801292E0 00126240  D0 16 00 0C */	stfs f0, 0xc(r22)
/* 801292E4 00126244  C0 02 A2 20 */	lfs f0, lbl_803EA420@sda21(r2)
/* 801292E8 00126248  D0 16 00 10 */	stfs f0, 0x10(r22)
lbl_801292EC:
/* 801292EC 0012624C  38 60 00 0C */	li r3, 0xc
/* 801292F0 00126250  4B F1 DD 15 */	bl alloc__6SystemFUl
/* 801292F4 00126254  3B C3 00 00 */	addi r30, r3, 0
/* 801292F8 00126258  7F C0 F3 79 */	or. r0, r30, r30
/* 801292FC 0012625C  41 82 00 2C */	beq lbl_80129328
/* 80129300 00126260  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80129304 00126264  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80129308 00126268  90 1E 00 04 */	stw r0, 4(r30)
/* 8012930C 0012626C  38 00 FF FF */	li r0, -1
/* 80129310 00126270  3C 60 80 2D */	lis r3, __vt__21TaiTimerElapsedAction@ha
/* 80129314 00126274  90 1E 00 00 */	stw r0, 0(r30)
/* 80129318 00126278  38 63 C9 D0 */	addi r3, r3, __vt__21TaiTimerElapsedAction@l
/* 8012931C 0012627C  38 00 00 00 */	li r0, 0
/* 80129320 00126280  90 7E 00 04 */	stw r3, 4(r30)
/* 80129324 00126284  90 1E 00 08 */	stw r0, 8(r30)
lbl_80129328:
/* 80129328 00126288  38 60 00 08 */	li r3, 8
/* 8012932C 0012628C  4B F1 DC D9 */	bl alloc__6SystemFUl
/* 80129330 00126290  3B 83 00 00 */	addi r28, r3, 0
/* 80129334 00126294  7F 80 E3 79 */	or. r0, r28, r28
/* 80129338 00126298  41 82 00 24 */	beq lbl_8012935C
/* 8012933C 0012629C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 80129340 001262A0  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 80129344 001262A4  90 1C 00 04 */	stw r0, 4(r28)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x626f6d62
	.4byte 0x4974656d
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x626f6d62
	.4byte 0x4974656d
	.4byte 0
	.4byte 0x426f6d62
	.4byte 0x4974656d
	.4byte 0
	.4byte 0x50616e69
	.4byte 0x416e696d
	.4byte 0x4b65794c
	.4byte 0x69737465
	.4byte 0x6e657200
	.4byte 0x4576656e
	.4byte 0x7454616c
	.4byte 0x6b657200
	.4byte 0x52656643
	.4byte 0x6f756e74
	.4byte 0x61626c65
	.4byte 0
	.4byte 0x43726561
	.4byte 0x74757265
	.4byte 0
	.4byte 0x803e183c
	.4byte 0x8
	.4byte 0x803e1844
	.4byte 0
	.4byte 0
	.4byte 0x41494372
	.4byte 0x65617475
	.4byte 0x72650000
	.4byte 0x803e1834
	.4byte 0x2b8
	.4byte 0x803e183c
	.4byte 0x8
	.4byte 0x803e1844
	.4byte 0
	.4byte 0x803e184c
	.4byte 0
	.4byte 0
	.4byte 0x4974656d
	.4byte 0x43726561
	.4byte 0x74757265
	.4byte 0
	.4byte 0x803e1834
	.4byte 0x2b8
	.4byte 0x803e183c
	.4byte 0x8
	.4byte 0x803e1844
	.4byte 0
	.4byte 0x803e184c
	.4byte 0
	.4byte 0x803e1854
	.4byte 0
	.4byte 0
	.4byte 0x803e1834
	.4byte 0x2b8
	.4byte 0x803e183c
	.4byte 0x8
	.4byte 0x803e1844
	.4byte 0
	.4byte 0x803e184c
	.4byte 0
	.4byte 0x803e1854
	.4byte 0
	.4byte 0x803e185c
	.4byte 0
	.4byte 0
.global __vt__8BombItem
__vt__8BombItem:
	.4byte __RTTI__8BombItem
	.4byte 0
	.4byte addCntCallback__12RefCountableFv
	.4byte subCntCallback__12RefCountableFv
	.4byte insideSafeArea__8CreatureFR8Vector3f
	.4byte platAttachable__8CreatureFv
	.4byte alwaysUpdatePlatform__8CreatureFv
	.4byte doDoAI__8CreatureFv
	.4byte setRouteTracer__8CreatureFP11RouteTracer
	.4byte init__8CreatureFv
	.4byte init__12ItemCreatureFR8Vector3f
	.4byte resetPosition__8CreatureFR8Vector3f
	.4byte initParam__8CreatureFi
	.4byte startAI__8BombItemFi
	.4byte getiMass__8BombItemFv
	.4byte getSize__8BombItemFv
	.4byte getHeight__12ItemCreatureFv
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
	.4byte isVisible__8BombItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8BombItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8BombItemFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8CreatureFP8Creature
	.4byte isFree__8CreatureFv
	.4byte stimulate__12ItemCreatureFR11Interaction
	.4byte sendMsg__8CreatureFP3Msg
	.4byte collisionCallback__8BombItemFR9CollEvent
	.4byte bounceCallback__10AICreatureFv
	.4byte jumpCallback__8CreatureFv
	.4byte wallCallback__8CreatureFR5PlaneP13DynCollObject
	.4byte offwallCallback__8CreatureFP13DynCollObject
	.4byte stickCallback__8CreatureFP8Creature
	.4byte offstickCallback__8CreatureFP8Creature
	.4byte stickToCallback__8CreatureFP8Creature
	.4byte dump__8BombItemFv
	.4byte startWaterEffect__8CreatureFv
	.4byte finishWaterEffect__8CreatureFv
	.4byte isRopable__8CreatureFv
	.4byte mayIstick__8CreatureFv
	.4byte getFormationPri__8CreatureFv
	.4byte update__8BombItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__8BombItemFR8Graphics
	.4byte refresh2d__8BombItemFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__8BombItem
	.4byte 0xfffffd48
	.4byte 0x8007df54
	.4byte getCurrState__10AICreatureFv
	.4byte "setCurrState__10AICreatureFP20AState<10AICreature>"
	.4byte playSound__10AICreatureFi
	.4byte playEffect__10AICreatureFi
	.4byte startMotion__12ItemCreatureFi
	.4byte finishMotion__12ItemCreatureFv
	.4byte finishMotion__12ItemCreatureFf
	.4byte startMotion__12ItemCreatureFif
	.4byte getCurrentMotionName__12ItemCreatureFv
	.4byte getCurrentMotionCounter__12ItemCreatureFv
	.4byte getMotionSpeed__12ItemCreatureFv
	.4byte setMotionSpeed__12ItemCreatureFf
	.4byte stopMotion__12ItemCreatureFv
	.4byte animationKeyUpdated__10AICreatureFR16PaniAnimKeyEvent
	.4byte finalSetup__12ItemCreatureFv
	.4byte renderTimer__8BombItemFR8Graphics
	.4byte renderBlast__8BombItemFR8Graphics
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x68656e6b
	.4byte 0x61330000
	.4byte 0x68656e6b
	.4byte 0x61346100
	.4byte 0x68656e6b
	.4byte 0x61346200
	.4byte 0x802bc580
	.4byte 0
	.4byte 0x802bc58c
	.4byte 0x802bc59c
.global __RTTI__15PaniUfoAnimator
__RTTI__15PaniUfoAnimator:
	.4byte 0x802bc570
	.4byte 0x802bc5a8
.global lbl_803E1828
lbl_803E1828:
	.4byte 0x00000000
.global lbl_803E182C
lbl_803E182C:
	.4byte 0x41A00000
.global lbl_803E1830
lbl_803E1830:
	.4byte 0x00000000
	.4byte 0x802BC600
	.4byte 0x00000000
	.4byte 0x802BC614
