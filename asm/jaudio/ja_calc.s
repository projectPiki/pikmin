.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
.global atanf2__Fff
atanf2__Fff:
/* 8000DCC0 0000AC20  7C 08 02 A6 */	mflr r0
/* 8000DCC4 0000AC24  90 01 00 04 */	stw r0, 4(r1)
/* 8000DCC8 0000AC28  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000DCCC 0000AC2C  48 20 DA 1D */	bl atan2
/* 8000DCD0 0000AC30  FC 20 08 18 */	frsp f1, f1
/* 8000DCD4 0000AC34  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000DCD8 0000AC38  38 21 00 08 */	addi r1, r1, 8
/* 8000DCDC 0000AC3C  7C 08 03 A6 */	mtlr r0
/* 8000DCE0 0000AC40  4E 80 00 20 */	blr 
/* 8000DCE4 0000AC44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DCE8 0000AC48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DCEC 0000AC4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DCF0 0000AC50  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DCF4 0000AC54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DCF8 0000AC58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DCFC 0000AC5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_InitSinTable__Fv
Jac_InitSinTable__Fv:
/* 8000DD00 0000AC60  7C 08 02 A6 */	mflr r0
/* 8000DD04 0000AC64  90 01 00 04 */	stw r0, 4(r1)
/* 8000DD08 0000AC68  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8000DD0C 0000AC6C  39 61 00 38 */	addi r11, r1, 0x38
/* 8000DD10 0000AC70  48 20 71 51 */	bl func_80214E60
/* 8000DD14 0000AC74  BF 81 00 10 */	stmw r28, 0x10(r1)
/* 8000DD18 0000AC78  3C 60 80 31 */	lis r3, SINTABLE@ha
/* 8000DD1C 0000AC7C  C3 A2 80 B8 */	lfs f29, lbl_803E82B8@sda21(r2)
/* 8000DD20 0000AC80  CB C2 80 C0 */	lfd f30, "@124"@sda21(r2)
/* 8000DD24 0000AC84  3B C3 DA E0 */	addi r30, r3, SINTABLE@l
/* 8000DD28 0000AC88  C3 E2 80 BC */	lfs f31, lbl_803E82BC@sda21(r2)
/* 8000DD2C 0000AC8C  3B 80 00 00 */	li r28, 0
/* 8000DD30 0000AC90  3B E0 00 00 */	li r31, 0
/* 8000DD34 0000AC94  3F A0 43 30 */	lis r29, 0x4330
lbl_8000DD38:
/* 8000DD38 0000AC98  93 81 00 0C */	stw r28, 0xc(r1)
/* 8000DD3C 0000AC9C  93 A1 00 08 */	stw r29, 8(r1)
/* 8000DD40 0000ACA0  C8 01 00 08 */	lfd f0, 8(r1)
/* 8000DD44 0000ACA4  EC 00 F0 28 */	fsubs f0, f0, f30
/* 8000DD48 0000ACA8  EC 1D 00 32 */	fmuls f0, f29, f0
/* 8000DD4C 0000ACAC  EC 20 07 F2 */	fmuls f1, f0, f31
/* 8000DD50 0000ACB0  48 20 DF 99 */	bl sinf
/* 8000DD54 0000ACB4  3B 9C 00 01 */	addi r28, r28, 1
/* 8000DD58 0000ACB8  7C 7E FA 14 */	add r3, r30, r31
/* 8000DD5C 0000ACBC  28 1C 01 01 */	cmplwi r28, 0x101
/* 8000DD60 0000ACC0  D0 23 00 00 */	stfs f1, 0(r3)
/* 8000DD64 0000ACC4  3B FF 00 04 */	addi r31, r31, 4
/* 8000DD68 0000ACC8  41 80 FF D0 */	blt lbl_8000DD38
/* 8000DD6C 0000ACCC  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8000DD70 0000ACD0  39 61 00 38 */	addi r11, r1, 0x38
/* 8000DD74 0000ACD4  48 20 71 39 */	bl func_80214EAC
/* 8000DD78 0000ACD8  BB 81 00 10 */	lmw r28, 0x10(r1)
/* 8000DD7C 0000ACDC  38 21 00 38 */	addi r1, r1, 0x38
/* 8000DD80 0000ACE0  7C 08 03 A6 */	mtlr r0
/* 8000DD84 0000ACE4  4E 80 00 20 */	blr 
/* 8000DD88 0000ACE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DD8C 0000ACEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DD90 0000ACF0  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DD94 0000ACF4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DD98 0000ACF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DD9C 0000ACFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global sinf3__Ff
sinf3__Ff:
/* 8000DDA0 0000AD00  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000DDA4 0000AD04  3C 60 80 31 */	lis r3, SINTABLE@ha
/* 8000DDA8 0000AD08  38 03 DA E0 */	addi r0, r3, SINTABLE@l
/* 8000DDAC 0000AD0C  C0 02 80 C8 */	lfs f0, lbl_803E82C8@sda21(r2)
/* 8000DDB0 0000AD10  EC 00 00 72 */	fmuls f0, f0, f1
/* 8000DDB4 0000AD14  FC 00 00 1E */	fctiwz f0, f0
/* 8000DDB8 0000AD18  D8 01 00 10 */	stfd f0, 0x10(r1)
/* 8000DDBC 0000AD1C  80 61 00 14 */	lwz r3, 0x14(r1)
/* 8000DDC0 0000AD20  54 63 10 3A */	slwi r3, r3, 2
/* 8000DDC4 0000AD24  7C 60 1A 14 */	add r3, r0, r3
/* 8000DDC8 0000AD28  C0 23 00 00 */	lfs f1, 0(r3)
/* 8000DDCC 0000AD2C  38 21 00 18 */	addi r1, r1, 0x18
/* 8000DDD0 0000AD30  4E 80 00 20 */	blr 
/* 8000DDD4 0000AD34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DDD8 0000AD38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DDDC 0000AD3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global Jac_FatMemory_Init__FUl
Jac_FatMemory_Init__FUl:
/* 8000DDE0 0000AD40  7C 08 02 A6 */	mflr r0
/* 8000DDE4 0000AD44  90 01 00 04 */	stw r0, 4(r1)
/* 8000DDE8 0000AD48  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8000DDEC 0000AD4C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8000DDF0 0000AD50  7C 7F 1B 78 */	mr r31, r3
/* 8000DDF4 0000AD54  4B FF 79 8D */	bl OSAlloc2
/* 8000DDF8 0000AD58  90 6D 2B F8 */	stw r3, fatheapptr@sda21(r13)
/* 8000DDFC 0000AD5C  80 6D 2B F8 */	lwz r3, fatheapptr@sda21(r13)
/* 8000DE00 0000AD60  28 03 00 00 */	cmplwi r3, 0
/* 8000DE04 0000AD64  41 82 00 0C */	beq lbl_8000DE10
/* 8000DE08 0000AD68  7F E4 FB 78 */	mr r4, r31
/* 8000DE0C 0000AD6C  48 00 00 35 */	bl FAT_InitSystem__FPUcUl
lbl_8000DE10:
/* 8000DE10 0000AD70  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8000DE14 0000AD74  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8000DE18 0000AD78  38 21 00 18 */	addi r1, r1, 0x18
/* 8000DE1C 0000AD7C  7C 08 03 A6 */	mtlr r0
/* 8000DE20 0000AD80  4E 80 00 20 */	blr 
/* 8000DE24 0000AD84  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DE28 0000AD88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DE2C 0000AD8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DE30 0000AD90  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DE34 0000AD94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DE38 0000AD98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8000DE3C 0000AD9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */

.global FAT_InitSystem__FPUcUl
FAT_InitSystem__FPUcUl:
/* 8000DE40 0000ADA0  3C C0 80 31 */	lis r6, FH_TO_FAT@ha
/* 8000DE44 0000ADA4  3C A0 00 01 */	lis r5, 0x0000FFFF@ha
/* 8000DE48 0000ADA8  39 06 DE E8 */	addi r8, r6, FH_TO_FAT@l
/* 8000DE4C 0000ADAC  38 C5 FF FF */	addi r6, r5, 0x0000FFFF@l
/* 8000DE50 0000ADB0  38 00 01 00 */	li r0, 0x100
/* 8000DE54 0000ADB4  39 40 00 00 */	li r10, 0
/* 8000DE58 0000ADB8  38 A0 00 00 */	li r5, 0
/* 8000DE5C 0000ADBC  38 E0 10 00 */	li r7, 0x1000
/* 8000DE60 0000ADC0  7C 09 03 A6 */	mtctr r0
lbl_8000DE64:
/* 8000DE64 0000ADC4  28 04 10 00 */	cmplwi r4, 0x1000
/* 8000DE68 0000ADC8  41 80 00 28 */	blt lbl_8000DE90
/* 8000DE6C 0000ADCC  7D 28 2A 14 */	add r9, r8, r5
/* 8000DE70 0000ADD0  38 84 F0 00 */	addi r4, r4, -4096
/* 8000DE74 0000ADD4  90 69 04 04 */	stw r3, 0x404(r9)
/* 8000DE78 0000ADD8  39 4A 00 01 */	addi r10, r10, 1
/* 8000DE7C 0000ADDC  38 63 10 00 */	addi r3, r3, 0x1000

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8002DFD4 0002AF34  38 8D 83 8C */	addi r4, r13, lbl_803DD0AC@sda21
/* 8002DFD8 0002AF38  48 01 33 FD */	bl isToken__9CmdStreamFPc
/* 8002DFDC 0002AF3C  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002DFE0 0002AF40  41 82 06 60 */	beq lbl_8002E640
/* 8002DFE4 0002AF44  38 7F 00 00 */	addi r3, r31, 0
/* 8002DFE8 0002AF48  38 80 00 01 */	li r4, 1
/* 8002DFEC 0002AF4C  48 01 30 C5 */	bl getToken__9CmdStreamFb
/* 8002DFF0 0002AF50  38 00 FF FF */	li r0, -1
/* 8002DFF4 0002AF54  90 01 00 40 */	stw r0, 0x40(r1)
/* 8002DFF8 0002AF58  48 00 06 08 */	b lbl_8002E600
lbl_8002DFFC:
/* 8002DFFC 0002AF5C  38 7F 00 00 */	addi r3, r31, 0
/* 8002E000 0002AF60  38 80 00 01 */	li r4, 1
/* 8002E004 0002AF64  48 01 30 AD */	bl getToken__9CmdStreamFb
/* 8002E008 0002AF68  38 7F 00 00 */	addi r3, r31, 0
/* 8002E00C 0002AF6C  38 8D 83 74 */	addi r4, r13, lbl_803DD094@sda21
/* 8002E010 0002AF70  48 01 33 C5 */	bl isToken__9CmdStreamFPc
/* 8002E014 0002AF74  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002E018 0002AF78  41 82 00 24 */	beq lbl_8002E03C
/* 8002E01C 0002AF7C  38 7F 00 00 */	addi r3, r31, 0
/* 8002E020 0002AF80  38 80 00 01 */	li r4, 1
/* 8002E024 0002AF84  48 01 30 8D */	bl getToken__9CmdStreamFb
/* 8002E028 0002AF88  4C C6 31 82 */	crclr 6
/* 8002E02C 0002AF8C  38 A1 00 40 */	addi r5, r1, 0x40
/* 8002E030 0002AF90  38 8D 83 6C */	addi r4, r13, lbl_803DD08C@sda21
/* 8002E034 0002AF94  48 1E A0 61 */	bl sscanf
/* 8002E038 0002AF98  48 00 05 C8 */	b lbl_8002E600
lbl_8002E03C:
/* 8002E03C 0002AF9C  38 7F 00 00 */	addi r3, r31, 0
/* 8002E040 0002AFA0  38 8D 83 7C */	addi r4, r13, lbl_803DD09C@sda21
/* 8002E044 0002AFA4  48 01 33 91 */	bl isToken__9CmdStreamFPc
/* 8002E048 0002AFA8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002E04C 0002AFAC  41 82 00 14 */	beq lbl_8002E060
/* 8002E050 0002AFB0  38 7F 00 00 */	addi r3, r31, 0
/* 8002E054 0002AFB4  38 80 00 01 */	li r4, 1
/* 8002E058 0002AFB8  48 01 30 59 */	bl getToken__9CmdStreamFb
/* 8002E05C 0002AFBC  48 00 05 A4 */	b lbl_8002E600
lbl_8002E060:
/* 8002E060 0002AFC0  38 7F 00 00 */	addi r3, r31, 0
/* 8002E064 0002AFC4  38 8D 83 94 */	addi r4, r13, lbl_803DD0B4@sda21
/* 8002E068 0002AFC8  48 01 33 6D */	bl isToken__9CmdStreamFPc
/* 8002E06C 0002AFCC  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002E070 0002AFD0  41 82 00 14 */	beq lbl_8002E084
/* 8002E074 0002AFD4  38 7F 00 00 */	addi r3, r31, 0
/* 8002E078 0002AFD8  38 80 00 01 */	li r4, 1
/* 8002E07C 0002AFDC  48 01 30 35 */	bl getToken__9CmdStreamFb
/* 8002E080 0002AFE0  48 00 05 80 */	b lbl_8002E600
lbl_8002E084:
/* 8002E084 0002AFE4  38 7F 00 00 */	addi r3, r31, 0
/* 8002E088 0002AFE8  38 8D 83 9C */	addi r4, r13, lbl_803DD0BC@sda21
/* 8002E08C 0002AFEC  48 01 33 49 */	bl isToken__9CmdStreamFPc
/* 8002E090 0002AFF0  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002E094 0002AFF4  41 82 00 64 */	beq lbl_8002E0F8
/* 8002E098 0002AFF8  38 7F 00 00 */	addi r3, r31, 0
/* 8002E09C 0002AFFC  38 80 00 01 */	li r4, 1
/* 8002E0A0 0002B000  48 01 30 11 */	bl getToken__9CmdStreamFb
/* 8002E0A4 0002B004  4C C6 31 82 */	crclr 6
/* 8002E0A8 0002B008  38 A1 00 3C */	addi r5, r1, 0x3c
/* 8002E0AC 0002B00C  38 8D 83 6C */	addi r4, r13, lbl_803DD08C@sda21
/* 8002E0B0 0002B010  48 1E 9F E5 */	bl sscanf
/* 8002E0B4 0002B014  38 7F 00 00 */	addi r3, r31, 0
/* 8002E0B8 0002B018  38 80 00 01 */	li r4, 1
/* 8002E0BC 0002B01C  48 01 2F F5 */	bl getToken__9CmdStreamFb
/* 8002E0C0 0002B020  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8002E0C4 0002B024  2C 00 FF FF */	cmpwi r0, -1
/* 8002E0C8 0002B028  40 82 00 0C */	bne lbl_8002E0D4
/* 8002E0CC 0002B02C  38 A0 00 00 */	li r5, 0
/* 8002E0D0 0002B030  48 00 00 10 */	b lbl_8002E0E0
lbl_8002E0D4:
/* 8002E0D4 0002B034  1C 00 00 DC */	mulli r0, r0, 0xdc
/* 8002E0D8 0002B038  80 7E 00 3C */	lwz r3, 0x3c(r30)
/* 8002E0DC 0002B03C  7C A3 02 14 */	add r5, r3, r0
lbl_8002E0E0:
/* 8002E0E0 0002B040  80 01 00 40 */	lwz r0, 0x40(r1)
/* 8002E0E4 0002B044  80 9E 00 3C */	lwz r4, 0x3c(r30)
/* 8002E0E8 0002B048  1C 60 00 DC */	mulli r3, r0, 0xdc
/* 8002E0EC 0002B04C  38 03 00 70 */	addi r0, r3, 0x70
/* 8002E0F0 0002B050  7C A4 01 2E */	stwx r5, r4, r0
/* 8002E0F4 0002B054  48 00 05 0C */	b lbl_8002E600
lbl_8002E0F8:
/* 8002E0F8 0002B058  38 7F 00 00 */	addi r3, r31, 0
/* 8002E0FC 0002B05C  38 8D 83 A4 */	addi r4, r13, lbl_803DD0C4@sda21
/* 8002E100 0002B060  48 01 32 D5 */	bl isToken__9CmdStreamFPc
/* 8002E104 0002B064  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002E108 0002B068  41 82 00 20 */	beq lbl_8002E128
/* 8002E10C 0002B06C  38 7F 00 00 */	addi r3, r31, 0
/* 8002E110 0002B070  38 80 00 01 */	li r4, 1
/* 8002E114 0002B074  48 01 2F 9D */	bl getToken__9CmdStreamFb
/* 8002E118 0002B078  38 7F 00 00 */	addi r3, r31, 0
/* 8002E11C 0002B07C  38 80 00 01 */	li r4, 1
/* 8002E120 0002B080  48 01 2F 91 */	bl getToken__9CmdStreamFb
/* 8002E124 0002B084  48 00 04 DC */	b lbl_8002E600
lbl_8002E128:
/* 8002E128 0002B088  38 7F 00 00 */	addi r3, r31, 0
/* 8002E12C 0002B08C  38 9D 01 DC */	addi r4, r29, 0x1dc
/* 8002E130 0002B090  48 01 32 A5 */	bl isToken__9CmdStreamFPc
/* 8002E134 0002B094  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002E138 0002B098  41 82 00 20 */	beq lbl_8002E158
/* 8002E13C 0002B09C  38 7F 00 00 */	addi r3, r31, 0
/* 8002E140 0002B0A0  38 80 00 01 */	li r4, 1
/* 8002E144 0002B0A4  48 01 2F 6D */	bl getToken__9CmdStreamFb
/* 8002E148 0002B0A8  38 7F 00 00 */	addi r3, r31, 0
/* 8002E14C 0002B0AC  38 80 00 01 */	li r4, 1
/* 8002E150 0002B0B0  48 01 2F 61 */	bl getToken__9CmdStreamFb
/* 8002E154 0002B0B4  48 00 04 AC */	b lbl_8002E600
lbl_8002E158:
/* 8002E158 0002B0B8  38 7F 00 00 */	addi r3, r31, 0
/* 8002E15C 0002B0BC  38 9D 01 EC */	addi r4, r29, 0x1ec
/* 8002E160 0002B0C0  48 01 32 75 */	bl isToken__9CmdStreamFPc
/* 8002E164 0002B0C4  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8002E168 0002B0C8  41 82 00 20 */	beq lbl_8002E188
/* 8002E16C 0002B0CC  38 7F 00 00 */	addi r3, r31, 0
/* 8002E170 0002B0D0  38 80 00 01 */	li r4, 1
/* 8002E174 0002B0D4  48 01 2F 3D */	bl getToken__9CmdStreamFb
/* 8002E178 0002B0D8  38 7F 00 00 */	addi r3, r31, 0
/* 8002E17C 0002B0DC  38 80 00 01 */	li r4, 1
/* 8002E180 0002B0E0  48 01 2F 31 */	bl getToken__9CmdStreamFb
/* 8002E184 0002B0E4  48 00 04 7C */	b lbl_8002E600
lbl_8002E188:
/* 8002E188 0002B0E8  38 7F 00 00 */	addi r3, r31, 0
/* 8002E18C 0002B0EC  38 9D 01 FC */	addi r4, r29, 0x1fc
/* 8002E190 0002B0F0  48 01 32 45 */	bl isToken__9CmdStreamFPc

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8004C854 000497B4  48 00 00 18 */	b lbl_8004C86C
lbl_8004C858:
/* 8004C858 000497B8  80 7A 00 1C */	lwz r3, 0x1c(r26)
/* 8004C85C 000497BC  80 9A 00 18 */	lwz r4, 0x18(r26)
/* 8004C860 000497C0  48 1A A3 BD */	bl DCStoreRange
/* 8004C864 000497C4  3B 5A 00 74 */	addi r26, r26, 0x74
/* 8004C868 000497C8  3B 39 00 01 */	addi r25, r25, 1
lbl_8004C86C:
/* 8004C86C 000497CC  80 7F 00 54 */	lwz r3, 0x54(r31)
/* 8004C870 000497D0  38 03 00 24 */	addi r0, r3, 0x24
/* 8004C874 000497D4  7C 7D 00 2E */	lwzx r3, r29, r0
/* 8004C878 000497D8  38 03 00 08 */	addi r0, r3, 8
/* 8004C87C 000497DC  7C 1E 00 2E */	lwzx r0, r30, r0
/* 8004C880 000497E0  7C 19 00 00 */	cmpw r25, r0
/* 8004C884 000497E4  41 80 FF D4 */	blt lbl_8004C858
/* 8004C888 000497E8  3B DE 00 10 */	addi r30, r30, 0x10
/* 8004C88C 000497EC  3B 7B 00 01 */	addi r27, r27, 1
lbl_8004C890:
/* 8004C890 000497F0  80 1F 00 54 */	lwz r0, 0x54(r31)
/* 8004C894 000497F4  7C 7D 02 14 */	add r3, r29, r0
/* 8004C898 000497F8  80 03 00 20 */	lwz r0, 0x20(r3)
/* 8004C89C 000497FC  7C 1B 00 00 */	cmpw r27, r0
/* 8004C8A0 00049800  41 80 FF A4 */	blt lbl_8004C844
/* 8004C8A4 00049804  3B BD 00 30 */	addi r29, r29, 0x30
/* 8004C8A8 00049808  3B 9C 00 01 */	addi r28, r28, 1
lbl_8004C8AC:
/* 8004C8AC 0004980C  80 1F 00 50 */	lwz r0, 0x50(r31)
/* 8004C8B0 00049810  7C 1C 00 00 */	cmpw r28, r0
/* 8004C8B4 00049814  41 80 FF 84 */	blt lbl_8004C838
lbl_8004C8B8:
/* 8004C8B8 00049818  BB 21 00 14 */	lmw r25, 0x14(r1)
/* 8004C8BC 0004981C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8004C8C0 00049820  38 21 00 30 */	addi r1, r1, 0x30
/* 8004C8C4 00049824  7C 08 03 A6 */	mtlr r0
/* 8004C8C8 00049828  4E 80 00 20 */	blr 

.global setPointSize__11DGXGraphicsFf
setPointSize__11DGXGraphicsFf:
/* 8004C8CC 0004982C  4E 80 00 20 */	blr 

.global setClippingPlane__11DGXGraphicsFbP5Plane
setClippingPlane__11DGXGraphicsFbP5Plane:
/* 8004C8D0 00049830  4E 80 00 20 */	blr 

.global drawOutline__11DGXGraphicsFR6CameraP5Shape
drawOutline__11DGXGraphicsFR6CameraP5Shape:
/* 8004C8D4 00049834  4E 80 00 20 */	blr 

.global drawOneStrip__11DGXGraphicsFP8Vector3fP8Vector3fP8Vector2fi
drawOneStrip__11DGXGraphicsFP8Vector3fP8Vector3fP8Vector2fi:
/* 8004C8D8 00049838  4E 80 00 20 */	blr 

.global __sinit_dgxGraphics_cpp
__sinit_dgxGraphics_cpp:
/* 8004C8DC 0004983C  38 00 00 FF */	li r0, 0xff
/* 8004C8E0 00049840  3C 60 80 3A */	lis r3, GColors@ha
/* 8004C8E4 00049844  9C 03 D4 30 */	stbu r0, GColors@l(r3)
/* 8004C8E8 00049848  98 03 00 01 */	stb r0, 1(r3)
/* 8004C8EC 0004984C  98 03 00 02 */	stb r0, 2(r3)
/* 8004C8F0 00049850  98 03 00 03 */	stb r0, 3(r3)
/* 8004C8F4 00049854  98 03 00 04 */	stb r0, 4(r3)
/* 8004C8F8 00049858  98 03 00 05 */	stb r0, 5(r3)
/* 8004C8FC 0004985C  98 03 00 06 */	stb r0, 6(r3)
/* 8004C900 00049860  98 03 00 07 */	stb r0, 7(r3)
/* 8004C904 00049864  4E 80 00 20 */	blr 

.global renderall__7GameAppFv
renderall__7GameAppFv:
/* 8004C908 00049868  7C 08 02 A6 */	mflr r0
/* 8004C90C 0004986C  90 01 00 04 */	stw r0, 4(r1)
/* 8004C910 00049870  94 21 FF F8 */	stwu r1, -8(r1)
/* 8004C914 00049874  81 83 00 00 */	lwz r12, 0(r3)
/* 8004C918 00049878  80 8D 2D EC */	lwz r4, gsys@sda21(r13)
/* 8004C91C 0004987C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8004C920 00049880  80 84 02 4C */	lwz r4, 0x24c(r4)
/* 8004C924 00049884  7D 88 03 A6 */	mtlr r12
/* 8004C928 00049888  4E 80 00 21 */	blrl 
/* 8004C92C 0004988C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8004C930 00049890  38 21 00 08 */	addi r1, r1, 8
/* 8004C934 00049894  7C 08 03 A6 */	mtlr r0
/* 8004C938 00049898  4E 80 00 20 */	blr 

.global DoMount__FlPv
DoMount__FlPv:
/* 8004C93C 0004989C  7C 08 02 A6 */	mflr r0
/* 8004C940 000498A0  3C A0 80 3A */	lis r5, CardThread@ha
/* 8004C944 000498A4  90 01 00 04 */	stw r0, 4(r1)
/* 8004C948 000498A8  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8004C94C 000498AC  BF 41 00 10 */	stmw r26, 0x10(r1)
/* 8004C950 000498B0  3B C5 D4 38 */	addi r30, r5, CardThread@l
/* 8004C954 000498B4  3B BE 03 60 */	addi r29, r30, 0x360
/* 8004C958 000498B8  3B 43 00 00 */	addi r26, r3, 0
/* 8004C95C 000498BC  3B 64 00 00 */	addi r27, r4, 0
/* 8004C960 000498C0  38 7D 00 00 */	addi r3, r29, 0
/* 8004C964 000498C4  48 1A D0 8D */	bl OSLockMutex
/* 8004C968 000498C8  3B E0 00 00 */	li r31, 0
/* 8004C96C 000498CC  93 FE 03 7C */	stw r31, 0x37c(r30)
/* 8004C970 000498D0  7F A3 EB 78 */	mr r3, r29
/* 8004C974 000498D4  48 1A D1 59 */	bl OSUnlockMutex
/* 8004C978 000498D8  3B BE 03 50 */	addi r29, r30, 0x350
/* 8004C97C 000498DC  93 FE 03 50 */	stw r31, 0x350(r30)
/* 8004C980 000498E0  3B 9E 03 4C */	addi r28, r30, 0x34c
/* 8004C984 000498E4  3C 60 00 01 */	lis r3, 0x0000A000@ha
/* 8004C988 000498E8  93 FE 03 4C */	stw r31, 0x34c(r30)
/* 8004C98C 000498EC  38 03 A0 00 */	addi r0, r3, 0x0000A000@l
/* 8004C990 000498F0  38 7A 00 00 */	addi r3, r26, 0
/* 8004C994 000498F4  90 1E 03 5C */	stw r0, 0x35c(r30)
/* 8004C998 000498F8  38 9B 00 00 */	addi r4, r27, 0
/* 8004C99C 000498FC  38 A0 00 00 */	li r5, 0
/* 8004C9A0 00049900  48 1B E7 6D */	bl CARDMount
/* 8004C9A4 00049904  3B E3 00 00 */	addi r31, r3, 0
/* 8004C9A8 00049908  2C 1F FF FA */	cmpwi r31, -6
/* 8004C9AC 0004990C  41 82 00 20 */	beq lbl_8004C9CC
/* 8004C9B0 00049910  40 80 00 10 */	bge lbl_8004C9C0
/* 8004C9B4 00049914  2C 1F FF F3 */	cmpwi r31, -13
/* 8004C9B8 00049918  41 82 00 3C */	beq lbl_8004C9F4
/* 8004C9BC 0004991C  48 00 00 50 */	b lbl_8004CA0C
lbl_8004C9C0:
/* 8004C9C0 00049920  2C 1F 00 00 */	cmpwi r31, 0
/* 8004C9C4 00049924  41 82 00 08 */	beq lbl_8004C9CC
/* 8004C9C8 00049928  48 00 00 44 */	b lbl_8004CA0C
lbl_8004C9CC:
/* 8004C9CC 0004992C  38 7A 00 00 */	addi r3, r26, 0
/* 8004C9D0 00049930  38 9E 03 54 */	addi r4, r30, 0x354
/* 8004C9D4 00049934  48 1B C6 ED */	bl CARDGetSectorSize
/* 8004C9D8 00049938  2C 03 00 00 */	cmpwi r3, 0
/* 8004C9DC 0004993C  40 80 00 08 */	bge lbl_8004C9E4
/* 8004C9E0 00049940  48 00 00 4C */	b lbl_8004CA2C
lbl_8004C9E4:
/* 8004C9E4 00049944  7F 43 D3 78 */	mr r3, r26
/* 8004C9E8 00049948  48 1B E0 69 */	bl CARDCheck
/* 8004C9EC 0004994C  7C 7F 1B 78 */	mr r31, r3
/* 8004C9F0 00049950  48 00 00 1C */	b lbl_8004CA0C
lbl_8004C9F4:
/* 8004C9F4 00049954  38 7A 00 00 */	addi r3, r26, 0
/* 8004C9F8 00049958  38 9E 03 54 */	addi r4, r30, 0x354
/* 8004C9FC 0004995C  48 1B C6 C5 */	bl CARDGetSectorSize
/* 8004CA00 00049960  2C 03 00 00 */	cmpwi r3, 0
/* 8004CA04 00049964  40 80 00 08 */	bge lbl_8004CA0C
/* 8004CA08 00049968  48 00 00 24 */	b lbl_8004CA2C
lbl_8004CA0C:
/* 8004CA0C 0004996C  2C 1F 00 00 */	cmpwi r31, 0
/* 8004CA10 00049970  40 82 00 18 */	bne lbl_8004CA28

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80210520 0020D480  48 00 00 A4 */	b lbl_802105C4
lbl_80210524:
/* 80210524 0020D484  2C 04 00 0A */	cmpwi r4, 0xa
/* 80210528 0020D488  41 82 00 74 */	beq lbl_8021059C
/* 8021052C 0020D48C  40 80 00 98 */	bge lbl_802105C4
/* 80210530 0020D490  48 00 00 30 */	b lbl_80210560
lbl_80210534:
/* 80210534 0020D494  55 80 10 3A */	slwi r0, r12, 2
/* 80210538 0020D498  54 04 07 26 */	rlwinm r4, r0, 0, 0x1c, 0x13
/* 8021053C 0020D49C  55 40 38 30 */	slwi r0, r10, 7
/* 80210540 0020D4A0  7C 8B 03 78 */	or r11, r4, r0
/* 80210544 0020D4A4  48 00 00 80 */	b lbl_802105C4
lbl_80210548:
/* 80210548 0020D4A8  55 80 10 3A */	slwi r0, r12, 2
/* 8021054C 0020D4AC  60 00 00 02 */	ori r0, r0, 2
/* 80210550 0020D4B0  54 04 07 26 */	rlwinm r4, r0, 0, 0x1c, 0x13
/* 80210554 0020D4B4  55 40 38 30 */	slwi r0, r10, 7
/* 80210558 0020D4B8  7C 8B 03 78 */	or r11, r4, r0
/* 8021055C 0020D4BC  48 00 00 68 */	b lbl_802105C4
lbl_80210560:
/* 80210560 0020D4C0  55 80 10 3A */	slwi r0, r12, 2
/* 80210564 0020D4C4  54 00 07 30 */	rlwinm r0, r0, 0, 0x1c, 0x18
/* 80210568 0020D4C8  60 00 00 10 */	ori r0, r0, 0x10
/* 8021056C 0020D4CC  54 09 06 66 */	rlwinm r9, r0, 0, 0x19, 0x13
/* 80210570 0020D4D0  55 40 38 30 */	slwi r0, r10, 7
/* 80210574 0020D4D4  7D 29 03 78 */	or r9, r9, r0
/* 80210578 0020D4D8  38 A5 FF F4 */	addi r5, r5, -12
/* 8021057C 0020D4DC  38 04 FF FE */	addi r0, r4, -2
/* 80210580 0020D4E0  55 29 05 20 */	rlwinm r9, r9, 0, 0x14, 0x10
/* 80210584 0020D4E4  54 A4 60 26 */	slwi r4, r5, 0xc
/* 80210588 0020D4E8  7D 24 23 78 */	or r4, r9, r4
/* 8021058C 0020D4EC  54 84 04 5A */	rlwinm r4, r4, 0, 0x11, 0xd
/* 80210590 0020D4F0  54 00 78 20 */	slwi r0, r0, 0xf
/* 80210594 0020D4F4  7C 8B 03 78 */	or r11, r4, r0
/* 80210598 0020D4F8  48 00 00 2C */	b lbl_802105C4
lbl_8021059C:
/* 8021059C 0020D4FC  2C 05 00 13 */	cmpwi r5, 0x13
/* 802105A0 0020D500  55 80 10 3A */	slwi r0, r12, 2
/* 802105A4 0020D504  40 82 00 10 */	bne lbl_802105B4
/* 802105A8 0020D508  54 00 07 30 */	rlwinm r0, r0, 0, 0x1c, 0x18
/* 802105AC 0020D50C  60 00 00 20 */	ori r0, r0, 0x20
/* 802105B0 0020D510  48 00 00 0C */	b lbl_802105BC
lbl_802105B4:
/* 802105B4 0020D514  54 00 07 30 */	rlwinm r0, r0, 0, 0x1c, 0x18
/* 802105B8 0020D518  60 00 00 30 */	ori r0, r0, 0x30
lbl_802105BC:
/* 802105BC 0020D51C  54 00 06 66 */	rlwinm r0, r0, 0, 0x19, 0x13
/* 802105C0 0020D520  60 0B 01 00 */	ori r11, r0, 0x100
lbl_802105C4:
/* 802105C4 0020D524  39 40 00 10 */	li r10, 0x10
/* 802105C8 0020D528  3D 20 CC 01 */	lis r9, 0xCC008000@ha
/* 802105CC 0020D52C  99 49 80 00 */	stb r10, 0xCC008000@l(r9)
/* 802105D0 0020D530  38 03 10 40 */	addi r0, r3, 0x1040
/* 802105D4 0020D534  38 88 FF C0 */	addi r4, r8, -64
/* 802105D8 0020D538  90 09 80 00 */	stw r0, -0x8000(r9)
/* 802105DC 0020D53C  54 85 06 2C */	rlwinm r5, r4, 0, 0x18, 0x16
/* 802105E0 0020D540  54 E4 44 2E */	rlwinm r4, r7, 8, 0x10, 0x17
/* 802105E4 0020D544  91 69 80 00 */	stw r11, -0x8000(r9)
/* 802105E8 0020D548  38 03 10 50 */	addi r0, r3, 0x1050
/* 802105EC 0020D54C  28 03 00 06 */	cmplwi r3, 6
/* 802105F0 0020D550  99 49 80 00 */	stb r10, -0x8000(r9)
/* 802105F4 0020D554  7C A4 23 78 */	or r4, r5, r4
/* 802105F8 0020D558  90 09 80 00 */	stw r0, -0x8000(r9)
/* 802105FC 0020D55C  90 89 80 00 */	stw r4, -0x8000(r9)
/* 80210600 0020D560  41 81 00 F4 */	bgt lbl_802106F4
/* 80210604 0020D564  3C 80 80 2F */	lis r4, lbl_802E8D58@ha
/* 80210608 0020D568  38 84 8D 58 */	addi r4, r4, lbl_802E8D58@l
/* 8021060C 0020D56C  54 60 10 3A */	slwi r0, r3, 2
/* 80210610 0020D570  7C 04 00 2E */	lwzx r0, r4, r0
/* 80210614 0020D574  7C 09 03 A6 */	mtctr r0
/* 80210618 0020D578  4E 80 04 20 */	bctr 
/* 8021061C 0020D57C  80 8D 2A 68 */	lwz r4, gx@sda21(r13)
/* 80210620 0020D580  54 C0 30 32 */	slwi r0, r6, 6
/* 80210624 0020D584  38 A4 00 80 */	addi r5, r4, 0x80
/* 80210628 0020D588  80 84 00 80 */	lwz r4, 0x80(r4)
/* 8021062C 0020D58C  54 84 06 A6 */	rlwinm r4, r4, 0, 0x1a, 0x13
/* 80210630 0020D590  7C 80 03 78 */	or r0, r4, r0
/* 80210634 0020D594  90 05 00 00 */	stw r0, 0(r5)
/* 80210638 0020D598  48 00 00 D8 */	b lbl_80210710
/* 8021063C 0020D59C  80 8D 2A 68 */	lwz r4, gx@sda21(r13)
/* 80210640 0020D5A0  54 C0 60 26 */	slwi r0, r6, 0xc
/* 80210644 0020D5A4  38 A4 00 80 */	addi r5, r4, 0x80
/* 80210648 0020D5A8  80 84 00 80 */	lwz r4, 0x80(r4)
/* 8021064C 0020D5AC  54 84 05 1A */	rlwinm r4, r4, 0, 0x14, 0xd
/* 80210650 0020D5B0  7C 80 03 78 */	or r0, r4, r0
/* 80210654 0020D5B4  90 05 00 00 */	stw r0, 0(r5)
/* 80210658 0020D5B8  48 00 00 B8 */	b lbl_80210710
/* 8021065C 0020D5BC  80 8D 2A 68 */	lwz r4, gx@sda21(r13)
/* 80210660 0020D5C0  54 C0 90 1A */	slwi r0, r6, 0x12
/* 80210664 0020D5C4  38 A4 00 80 */	addi r5, r4, 0x80
/* 80210668 0020D5C8  80 84 00 80 */	lwz r4, 0x80(r4)
/* 8021066C 0020D5CC  54 84 03 8E */	rlwinm r4, r4, 0, 0xe, 7
/* 80210670 0020D5D0  7C 80 03 78 */	or r0, r4, r0
/* 80210674 0020D5D4  90 05 00 00 */	stw r0, 0(r5)
/* 80210678 0020D5D8  48 00 00 98 */	b lbl_80210710
/* 8021067C 0020D5DC  80 8D 2A 68 */	lwz r4, gx@sda21(r13)
/* 80210680 0020D5E0  54 C0 C0 0E */	slwi r0, r6, 0x18
/* 80210684 0020D5E4  38 A4 00 80 */	addi r5, r4, 0x80
/* 80210688 0020D5E8  80 84 00 80 */	lwz r4, 0x80(r4)
/* 8021068C 0020D5EC  54 84 02 02 */	rlwinm r4, r4, 0, 8, 1
/* 80210690 0020D5F0  7C 80 03 78 */	or r0, r4, r0
/* 80210694 0020D5F4  90 05 00 00 */	stw r0, 0(r5)
/* 80210698 0020D5F8  48 00 00 78 */	b lbl_80210710
/* 8021069C 0020D5FC  80 8D 2A 68 */	lwz r4, gx@sda21(r13)
/* 802106A0 0020D600  84 04 00 84 */	lwzu r0, 0x84(r4)
/* 802106A4 0020D604  54 00 00 32 */	rlwinm r0, r0, 0, 0, 0x19
/* 802106A8 0020D608  7C 00 33 78 */	or r0, r0, r6
/* 802106AC 0020D60C  90 04 00 00 */	stw r0, 0(r4)
/* 802106B0 0020D610  48 00 00 60 */	b lbl_80210710
/* 802106B4 0020D614  80 8D 2A 68 */	lwz r4, gx@sda21(r13)
/* 802106B8 0020D618  54 C0 30 32 */	slwi r0, r6, 6
/* 802106BC 0020D61C  38 A4 00 84 */	addi r5, r4, 0x84
/* 802106C0 0020D620  80 84 00 84 */	lwz r4, 0x84(r4)
/* 802106C4 0020D624  54 84 06 A6 */	rlwinm r4, r4, 0, 0x1a, 0x13
/* 802106C8 0020D628  7C 80 03 78 */	or r0, r4, r0
/* 802106CC 0020D62C  90 05 00 00 */	stw r0, 0(r5)
/* 802106D0 0020D630  48 00 00 40 */	b lbl_80210710
/* 802106D4 0020D634  80 8D 2A 68 */	lwz r4, gx@sda21(r13)
/* 802106D8 0020D638  54 C0 60 26 */	slwi r0, r6, 0xc
/* 802106DC 0020D63C  38 A4 00 84 */	addi r5, r4, 0x84

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80162984 0015F8E4  80 19 00 B4 */	lwz r0, 0xb4(r25)
/* 80162988 0015F8E8  90 79 00 50 */	stw r3, 0x50(r25)
/* 8016298C 0015F8EC  90 19 00 54 */	stw r0, 0x54(r25)
/* 80162990 0015F8F0  80 19 00 B8 */	lwz r0, 0xb8(r25)
/* 80162994 0015F8F4  90 19 00 58 */	stw r0, 0x58(r25)
/* 80162998 0015F8F8  48 00 00 24 */	b lbl_801629BC
lbl_8016299C:
/* 8016299C 0015F8FC  54 60 10 3A */	slwi r0, r3, 2
/* 801629A0 0015F900  38 81 00 94 */	addi r4, r1, 0x94
/* 801629A4 0015F904  7C 84 02 14 */	add r4, r4, r0
/* 801629A8 0015F908  4B FF FC F0 */	b lbl_80162698
lbl_801629AC:
/* 801629AC 0015F90C  54 60 10 3A */	slwi r0, r3, 2
/* 801629B0 0015F910  38 81 00 70 */	addi r4, r1, 0x70
/* 801629B4 0015F914  7C 84 02 14 */	add r4, r4, r0
/* 801629B8 0015F918  4B FF FD 3C */	b lbl_801626F4
lbl_801629BC:
/* 801629BC 0015F91C  BB 21 00 BC */	lmw r25, 0xbc(r1)
/* 801629C0 0015F920  80 01 00 EC */	lwz r0, 0xec(r1)
/* 801629C4 0015F924  CB E1 00 E0 */	lfd f31, 0xe0(r1)
/* 801629C8 0015F928  CB C1 00 D8 */	lfd f30, 0xd8(r1)
/* 801629CC 0015F92C  38 21 00 E8 */	addi r1, r1, 0xe8
/* 801629D0 0015F930  7C 08 03 A6 */	mtlr r0
/* 801629D4 0015F934  4E 80 00 20 */	blr 

.global setDeadPattern01__9SnakeBodyFP8Matrix4f
setDeadPattern01__9SnakeBodyFP8Matrix4f:
/* 801629D8 0015F938  38 00 00 08 */	li r0, 8
/* 801629DC 0015F93C  7C 09 03 A6 */	mtctr r0
/* 801629E0 0015F940  38 A0 00 00 */	li r5, 0
lbl_801629E4:
/* 801629E4 0015F944  C0 24 00 00 */	lfs f1, 0(r4)
/* 801629E8 0015F948  2C 05 00 07 */	cmpwi r5, 7
/* 801629EC 0015F94C  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 801629F0 0015F950  EC 01 00 32 */	fmuls f0, f1, f0
/* 801629F4 0015F954  D0 04 00 00 */	stfs f0, 0(r4)
/* 801629F8 0015F958  C0 24 00 10 */	lfs f1, 0x10(r4)
/* 801629FC 0015F95C  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80162A00 0015F960  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162A04 0015F964  D0 04 00 10 */	stfs f0, 0x10(r4)
/* 80162A08 0015F968  C0 24 00 20 */	lfs f1, 0x20(r4)
/* 80162A0C 0015F96C  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80162A10 0015F970  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162A14 0015F974  D0 04 00 20 */	stfs f0, 0x20(r4)
/* 80162A18 0015F978  C0 24 00 04 */	lfs f1, 4(r4)
/* 80162A1C 0015F97C  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80162A20 0015F980  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162A24 0015F984  D0 04 00 04 */	stfs f0, 4(r4)
/* 80162A28 0015F988  C0 24 00 14 */	lfs f1, 0x14(r4)
/* 80162A2C 0015F98C  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80162A30 0015F990  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162A34 0015F994  D0 04 00 14 */	stfs f0, 0x14(r4)
/* 80162A38 0015F998  C0 24 00 24 */	lfs f1, 0x24(r4)
/* 80162A3C 0015F99C  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80162A40 0015F9A0  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162A44 0015F9A4  D0 04 00 24 */	stfs f0, 0x24(r4)
/* 80162A48 0015F9A8  C0 24 00 08 */	lfs f1, 8(r4)
/* 80162A4C 0015F9AC  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80162A50 0015F9B0  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162A54 0015F9B4  D0 04 00 08 */	stfs f0, 8(r4)
/* 80162A58 0015F9B8  C0 24 00 18 */	lfs f1, 0x18(r4)
/* 80162A5C 0015F9BC  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80162A60 0015F9C0  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162A64 0015F9C4  D0 04 00 18 */	stfs f0, 0x18(r4)
/* 80162A68 0015F9C8  C0 24 00 28 */	lfs f1, 0x28(r4)
/* 80162A6C 0015F9CC  C0 03 00 30 */	lfs f0, 0x30(r3)
/* 80162A70 0015F9D0  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162A74 0015F9D4  D0 04 00 28 */	stfs f0, 0x28(r4)
/* 80162A78 0015F9D8  40 80 00 58 */	bge lbl_80162AD0
/* 80162A7C 0015F9DC  C0 44 00 0C */	lfs f2, 0xc(r4)
/* 80162A80 0015F9E0  C0 04 00 4C */	lfs f0, 0x4c(r4)
/* 80162A84 0015F9E4  C0 23 00 30 */	lfs f1, 0x30(r3)
/* 80162A88 0015F9E8  EC 00 10 28 */	fsubs f0, f0, f2
/* 80162A8C 0015F9EC  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162A90 0015F9F0  EC 02 00 2A */	fadds f0, f2, f0
/* 80162A94 0015F9F4  D0 04 00 4C */	stfs f0, 0x4c(r4)
/* 80162A98 0015F9F8  C0 44 00 1C */	lfs f2, 0x1c(r4)
/* 80162A9C 0015F9FC  C0 04 00 5C */	lfs f0, 0x5c(r4)
/* 80162AA0 0015FA00  C0 23 00 30 */	lfs f1, 0x30(r3)
/* 80162AA4 0015FA04  EC 00 10 28 */	fsubs f0, f0, f2
/* 80162AA8 0015FA08  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162AAC 0015FA0C  EC 02 00 2A */	fadds f0, f2, f0
/* 80162AB0 0015FA10  D0 04 00 5C */	stfs f0, 0x5c(r4)
/* 80162AB4 0015FA14  C0 44 00 2C */	lfs f2, 0x2c(r4)
/* 80162AB8 0015FA18  C0 04 00 6C */	lfs f0, 0x6c(r4)
/* 80162ABC 0015FA1C  C0 23 00 30 */	lfs f1, 0x30(r3)
/* 80162AC0 0015FA20  EC 00 10 28 */	fsubs f0, f0, f2
/* 80162AC4 0015FA24  EC 01 00 32 */	fmuls f0, f1, f0
/* 80162AC8 0015FA28  EC 02 00 2A */	fadds f0, f2, f0
/* 80162ACC 0015FA2C  D0 04 00 6C */	stfs f0, 0x6c(r4)
lbl_80162AD0:
/* 80162AD0 0015FA30  38 63 00 04 */	addi r3, r3, 4
/* 80162AD4 0015FA34  38 84 00 40 */	addi r4, r4, 0x40
/* 80162AD8 0015FA38  38 A5 00 01 */	addi r5, r5, 1
/* 80162ADC 0015FA3C  42 00 FF 08 */	bdnz lbl_801629E4
/* 80162AE0 0015FA40  4E 80 00 20 */	blr 

.global returnJoint__9SnakeBodyFP15BossShapeObjectR8GraphicsP8Matrix4f
returnJoint__9SnakeBodyFP15BossShapeObjectR8GraphicsP8Matrix4f:
/* 80162AE4 0015FA44  7C 08 02 A6 */	mflr r0
/* 80162AE8 0015FA48  90 01 00 04 */	stw r0, 4(r1)
/* 80162AEC 0015FA4C  94 21 FE 90 */	stwu r1, -0x170(r1)
/* 80162AF0 0015FA50  BF 61 01 5C */	stmw r27, 0x15c(r1)
/* 80162AF4 0015FA54  7C 9F 23 78 */	mr r31, r4
/* 80162AF8 0015FA58  3B 65 00 00 */	addi r27, r5, 0
/* 80162AFC 0015FA5C  3B 86 00 00 */	addi r28, r6, 0
/* 80162B00 0015FA60  80 64 00 00 */	lwz r3, 0(r4)
/* 80162B04 0015FA64  38 80 00 07 */	li r4, 7
/* 80162B08 0015FA68  4B ED 24 E1 */	bl getAnimMatrix__9BaseShapeFi
/* 80162B0C 0015FA6C  38 81 00 98 */	addi r4, r1, 0x98
/* 80162B10 0015FA70  4B ED B9 2D */	bl inverse__8Matrix4fFP8Matrix4f
/* 80162B14 0015FA74  80 7F 00 00 */	lwz r3, 0(r31)
/* 80162B18 0015FA78  38 80 00 08 */	li r4, 8
/* 80162B1C 0015FA7C  4B ED 24 CD */	bl getAnimMatrix__9BaseShapeFi
/* 80162B20 0015FA80  38 81 00 D8 */	addi r4, r1, 0xd8
/* 80162B24 0015FA84  4B ED B9 19 */	bl inverse__8Matrix4fFP8Matrix4f
/* 80162B28 0015FA88  80 7F 00 00 */	lwz r3, 0(r31)
/* 80162B2C 0015FA8C  38 80 00 0B */	li r4, 0xb
/* 80162B30 0015FA90  4B ED 24 B9 */	bl getAnimMatrix__9BaseShapeFi
/* 80162B34 0015FA94  38 81 00 58 */	addi r4, r1, 0x58
/* 80162B38 0015FA98  4B ED B9 05 */	bl inverse__8Matrix4fFP8Matrix4f
/* 80162B3C 0015FA9C  3B A0 00 00 */	li r29, 0
/* 80162B40 0015FAA0  57 A0 30 32 */	slwi r0, r29, 6

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E82A0
lbl_803E82A0:
	.4byte 0x00000000
	.4byte 0x00000000
.global "@110"
"@110":
	.4byte 0x3FE00000
	.4byte 0x00000000
.global "@111"
"@111":
	.4byte 0x40080000
	.4byte 0x00000000
.global lbl_803E82B8
lbl_803E82B8:
	.4byte 0x3FC90FDB
.global lbl_803E82BC
lbl_803E82BC:
	.4byte 0x3B800000
.global "@124"
"@124":
	.4byte 0x43300000
	.4byte 0x00000000
.global lbl_803E82C8
lbl_803E82C8:
	.4byte 0x43800000
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E83C0
lbl_803E83C0:
	.4byte 0x00000000
.global lbl_803E83C4
lbl_803E83C4:
	.4byte 0x3D4CCCCD
.global lbl_803E83C8
lbl_803E83C8:
	.4byte 0x3F800000
	.4byte 0x00000000
.global lbl_803E83D0
lbl_803E83D0:
	.4byte 0x00000000
.global lbl_803E83D4
lbl_803E83D4:
	.4byte 0x3F99999A
.global "@213"
"@213":
	.4byte 0x43300000
	.4byte 0x00000000
.global lbl_803E83E0
lbl_803E83E0:
	.4byte 0x3F800000
	.4byte 0x00000000
.global lbl_803E83E8
lbl_803E83E8:
	.4byte 0x3C23D70A
.global lbl_803E83EC
lbl_803E83EC:
	.4byte 0x3F000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E98AC
lbl_803E98AC:
	.4byte 0x41200000
.global lbl_803E98B0
lbl_803E98B0:
	.4byte 0x41700000
.global lbl_803E98B4
lbl_803E98B4:
	.4byte 0x3F4CCCCD
.global lbl_803E98B8
lbl_803E98B8:
	.4byte 0x3FC00000
.global lbl_803E98BC
lbl_803E98BC:
	.4byte 0x3F99999A
.global lbl_803E98C0
lbl_803E98C0:
	.4byte 0x40A00000
.global lbl_803E98C4
lbl_803E98C4:
	.4byte 0x40400000
.global lbl_803E98C8
lbl_803E98C8:
	.4byte 0x42200000
.global lbl_803E98CC
lbl_803E98CC:
	.4byte 0x420C0000
.global lbl_803E98D0
lbl_803E98D0:
	.4byte 0x428C0000
.global lbl_803E98D4
lbl_803E98D4:
	.4byte 0x41F00000
.global lbl_803E98D8
lbl_803E98D8:
	.4byte 0x42700000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E8F78
lbl_803E8F78:
	.4byte 0x3F4CCCCD
.global lbl_803E8F7C
lbl_803E8F7C:
	.4byte 0x3FB33333
.global lbl_803E8F80
lbl_803E8F80:
	.4byte 0xBF000000
	.4byte 0x00000000
.global lbl_803E8F88
lbl_803E8F88:
	.4byte 0x442F0000
.global lbl_803E8F8C
lbl_803E8F8C:
	.4byte 0x43C80000
.global lbl_803E8F90
lbl_803E8F90:
	.4byte 0x44480000
	.4byte 0x00000000
.global lbl_803E8F98
lbl_803E8F98:
	.4byte 0x00000000
.global lbl_803E8F9C
lbl_803E8F9C:
	.4byte 0x442F0000
.global lbl_803E8FA0
lbl_803E8FA0:
	.4byte 0x43480000
	.4byte 0x00000000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803E8B60
lbl_803E8B60:
	.4byte 0x422F5A86
.global lbl_803E8B64
lbl_803E8B64:
	.4byte 0x41700000
.global lbl_803E8B68
lbl_803E8B68:
	.4byte 0x3F800000
	.4byte 0x00000000
.global lbl_803E8B70
lbl_803E8B70:
	.4byte 0x00000000
.global lbl_803E8B74
lbl_803E8B74:
	.4byte 0xC2F6CCCD
.global lbl_803E8B78
lbl_803E8B78:
	.4byte 0x42C80000
.global lbl_803E8B7C
lbl_803E8B7C:
	.4byte 0x41700000
.global lbl_803E8B80
lbl_803E8B80:
	.4byte 0x41200000
	.4byte 0x00000000
.global lbl_803E8B88
lbl_803E8B88:
	.4byte 0x00000000
.global lbl_803E8B8C
lbl_803E8B8C:
	.4byte 0x437F0000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.global lbl_803EAF88
lbl_803EAF88:
	.4byte 0x42C80000
.global lbl_803EAF8C
lbl_803EAF8C:
	.4byte 0x40490FDB
.global lbl_803EAF90
lbl_803EAF90:
	.4byte 0x42480000
.global lbl_803EAF94
lbl_803EAF94:
	.4byte 0x3ECCCCCD
.global lbl_803EAF98
lbl_803EAF98:
	.4byte 0x41200000
.global lbl_803EAF9C
lbl_803EAF9C:
	.4byte 0x41F00000
.global lbl_803EAFA0
lbl_803EAFA0:
	.4byte 0x40A00000
.global lbl_803EAFA4
lbl_803EAFA4:
	.4byte 0x3FC90FDB
.global lbl_803EAFA8
lbl_803EAFA8:
	.4byte 0x3F733333
	.4byte 0x00000000
.global lbl_803EAFB0
lbl_803EAFB0:
	.4byte 0x3E4CCCCD
.global lbl_803EAFB4
lbl_803EAFB4:
	.4byte 0x3F000000