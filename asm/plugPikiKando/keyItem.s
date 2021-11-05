.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 8012BE38 00128D98  4B F1 B1 CD */	bl alloc__6SystemFUl
/* 8012BE3C 00128D9C  3B 83 00 00 */	addi r28, r3, 0
/* 8012BE40 00128DA0  7F 80 E3 79 */	or. r0, r28, r28
/* 8012BE44 00128DA4  41 82 00 2C */	beq lbl_8012BE70
/* 8012BE48 00128DA8  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012BE4C 00128DAC  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012BE50 00128DB0  90 1C 00 04 */	stw r0, 4(r28)
/* 8012BE54 00128DB4  38 00 FF FF */	li r0, -1
/* 8012BE58 00128DB8  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 8012BE5C 00128DBC  90 1C 00 00 */	stw r0, 0(r28)
/* 8012BE60 00128DC0  38 63 95 94 */	addi r3, r3, __vt__15TaiMotionAction@l
/* 8012BE64 00128DC4  38 00 00 0A */	li r0, 0xa
/* 8012BE68 00128DC8  90 7C 00 04 */	stw r3, 4(r28)
/* 8012BE6C 00128DCC  90 1C 00 08 */	stw r0, 8(r28)
lbl_8012BE70:
/* 8012BE70 00128DD0  38 60 00 08 */	li r3, 8
/* 8012BE74 00128DD4  4B F1 B1 91 */	bl alloc__6SystemFUl
/* 8012BE78 00128DD8  3B 63 00 00 */	addi r27, r3, 0
/* 8012BE7C 00128DDC  7F 60 DB 79 */	or. r0, r27, r27
/* 8012BE80 00128DE0  41 82 00 24 */	beq lbl_8012BEA4
/* 8012BE84 00128DE4  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012BE88 00128DE8  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012BE8C 00128DEC  90 1B 00 04 */	stw r0, 4(r27)
/* 8012BE90 00128DF0  38 00 FF FF */	li r0, -1
/* 8012BE94 00128DF4  3C 60 80 2C */	lis r3, __vt__27TaiCollecBeingDraggedAction@ha
/* 8012BE98 00128DF8  90 1B 00 00 */	stw r0, 0(r27)
/* 8012BE9C 00128DFC  38 03 77 50 */	addi r0, r3, __vt__27TaiCollecBeingDraggedAction@l
/* 8012BEA0 00128E00  90 1B 00 04 */	stw r0, 4(r27)
lbl_8012BEA4:
/* 8012BEA4 00128E04  38 60 00 0C */	li r3, 0xc
/* 8012BEA8 00128E08  4B F1 B1 5D */	bl alloc__6SystemFUl
/* 8012BEAC 00128E0C  3B E3 00 00 */	addi r31, r3, 0
/* 8012BEB0 00128E10  7F E3 FB 79 */	or. r3, r31, r31
/* 8012BEB4 00128E14  41 82 00 0C */	beq lbl_8012BEC0
/* 8012BEB8 00128E18  38 80 00 09 */	li r4, 9
/* 8012BEBC 00128E1C  4B FF B1 DD */	bl __ct__8TaiStateFi
lbl_8012BEC0:
/* 8012BEC0 00128E20  38 00 00 00 */	li r0, 0
/* 8012BEC4 00128E24  80 7F 00 08 */	lwz r3, 8(r31)
/* 8012BEC8 00128E28  54 04 10 3A */	slwi r4, r0, 2
/* 8012BECC 00128E2C  80 01 02 24 */	lwz r0, 0x224(r1)
/* 8012BED0 00128E30  38 E0 00 03 */	li r7, 3
/* 8012BED4 00128E34  7C 03 21 2E */	stwx r0, r3, r4
/* 8012BED8 00128E38  38 80 00 01 */	li r4, 1
/* 8012BEDC 00128E3C  38 00 00 02 */	li r0, 2
/* 8012BEE0 00128E40  80 7F 00 08 */	lwz r3, 8(r31)
/* 8012BEE4 00128E44  54 84 10 3A */	slwi r4, r4, 2
/* 8012BEE8 00128E48  38 C0 00 06 */	li r6, 6
/* 8012BEEC 00128E4C  7E 23 21 2E */	stwx r17, r3, r4
/* 8012BEF0 00128E50  38 80 00 04 */	li r4, 4
/* 8012BEF4 00128E54  54 00 10 3A */	slwi r0, r0, 2
/* 8012BEF8 00128E58  80 7F 00 08 */	lwz r3, 8(r31)
/* 8012BEFC 00128E5C  54 E7 10 3A */	slwi r7, r7, 2
/* 8012BF00 00128E60  54 84 10 3A */	slwi r4, r4, 2
/* 8012BF04 00128E64  7D C3 01 2E */	stwx r14, r3, r0
/* 8012BF08 00128E68  38 A0 00 05 */	li r5, 5
/* 8012BF0C 00128E6C  54 C6 10 3A */	slwi r6, r6, 2
/* 8012BF10 00128E70  80 7F 00 08 */	lwz r3, 8(r31)
/* 8012BF14 00128E74  38 00 00 07 */	li r0, 7
/* 8012BF18 00128E78  39 00 00 08 */	li r8, 8
/* 8012BF1C 00128E7C  7D E3 39 2E */	stwx r15, r3, r7
/* 8012BF20 00128E80  54 A7 10 3A */	slwi r7, r5, 2
/* 8012BF24 00128E84  54 05 10 3A */	slwi r5, r0, 2
/* 8012BF28 00128E88  80 7F 00 08 */	lwz r3, 8(r31)
/* 8012BF2C 00128E8C  55 00 10 3A */	slwi r0, r8, 2
/* 8012BF30 00128E90  7E 03 21 2E */	stwx r16, r3, r4
/* 8012BF34 00128E94  38 60 00 0C */	li r3, 0xc
/* 8012BF38 00128E98  80 9F 00 08 */	lwz r4, 8(r31)
/* 8012BF3C 00128E9C  7E 84 39 2E */	stwx r20, r4, r7
/* 8012BF40 00128EA0  80 9F 00 08 */	lwz r4, 8(r31)
/* 8012BF44 00128EA4  7F A4 31 2E */	stwx r29, r4, r6
/* 8012BF48 00128EA8  80 9F 00 08 */	lwz r4, 8(r31)
/* 8012BF4C 00128EAC  7F 64 29 2E */	stwx r27, r4, r5
/* 8012BF50 00128EB0  80 9F 00 08 */	lwz r4, 8(r31)
/* 8012BF54 00128EB4  7F 84 01 2E */	stwx r28, r4, r0
/* 8012BF58 00128EB8  80 97 00 08 */	lwz r4, 8(r23)
/* 8012BF5C 00128EBC  93 E4 00 1C */	stw r31, 0x1c(r4)
/* 8012BF60 00128EC0  4B F1 B0 A5 */	bl alloc__6SystemFUl
/* 8012BF64 00128EC4  3B 83 00 00 */	addi r28, r3, 0
/* 8012BF68 00128EC8  7F 80 E3 79 */	or. r0, r28, r28
/* 8012BF6C 00128ECC  41 82 00 2C */	beq lbl_8012BF98
/* 8012BF70 00128ED0  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012BF74 00128ED4  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012BF78 00128ED8  90 1C 00 04 */	stw r0, 4(r28)
/* 8012BF7C 00128EDC  38 00 00 09 */	li r0, 9
/* 8012BF80 00128EE0  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 8012BF84 00128EE4  90 1C 00 00 */	stw r0, 0(r28)
/* 8012BF88 00128EE8  38 63 95 94 */	addi r3, r3, __vt__15TaiMotionAction@l
/* 8012BF8C 00128EEC  38 00 00 0C */	li r0, 0xc
/* 8012BF90 00128EF0  90 7C 00 04 */	stw r3, 4(r28)
/* 8012BF94 00128EF4  90 1C 00 08 */	stw r0, 8(r28)
lbl_8012BF98:
/* 8012BF98 00128EF8  38 60 00 08 */	li r3, 8
/* 8012BF9C 00128EFC  4B F1 B0 69 */	bl alloc__6SystemFUl
/* 8012BFA0 00128F00  3B 63 00 00 */	addi r27, r3, 0
/* 8012BFA4 00128F04  7F 60 DB 79 */	or. r0, r27, r27
/* 8012BFA8 00128F08  41 82 00 24 */	beq lbl_8012BFCC
/* 8012BFAC 00128F0C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012BFB0 00128F10  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012BFB4 00128F14  90 1B 00 04 */	stw r0, 4(r27)
/* 8012BFB8 00128F18  38 00 FF FF */	li r0, -1
/* 8012BFBC 00128F1C  3C 60 80 2C */	lis r3, __vt__28TaiCollecPuttingPelletAction@ha
/* 8012BFC0 00128F20  90 1B 00 00 */	stw r0, 0(r27)
/* 8012BFC4 00128F24  38 03 76 44 */	addi r0, r3, __vt__28TaiCollecPuttingPelletAction@l
/* 8012BFC8 00128F28  90 1B 00 04 */	stw r0, 4(r27)
lbl_8012BFCC:
/* 8012BFCC 00128F2C  38 60 00 0C */	li r3, 0xc
/* 8012BFD0 00128F30  4B F1 B0 35 */	bl alloc__6SystemFUl
/* 8012BFD4 00128F34  3B A3 00 00 */	addi r29, r3, 0
/* 8012BFD8 00128F38  7F A3 EB 79 */	or. r3, r29, r29
/* 8012BFDC 00128F3C  41 82 00 0C */	beq lbl_8012BFE8
/* 8012BFE0 00128F40  38 80 00 04 */	li r4, 4
/* 8012BFE4 00128F44  4B FF B0 B5 */	bl __ct__8TaiStateFi
lbl_8012BFE8:
/* 8012BFE8 00128F48  38 00 00 00 */	li r0, 0
/* 8012BFEC 00128F4C  80 7D 00 08 */	lwz r3, 8(r29)
/* 8012BFF0 00128F50  54 00 10 3A */	slwi r0, r0, 2
/* 8012BFF4 00128F54  7E A3 01 2E */	stwx r21, r3, r0
/* 8012BFF8 00128F58  38 00 00 01 */	li r0, 1
/* 8012BFFC 00128F5C  38 A0 00 03 */	li r5, 3
/* 8012C000 00128F60  80 7D 00 08 */	lwz r3, 8(r29)
/* 8012C004 00128F64  54 00 10 3A */	slwi r0, r0, 2
/* 8012C008 00128F68  38 80 00 02 */	li r4, 2
/* 8012C00C 00128F6C  7F 63 01 2E */	stwx r27, r3, r0
/* 8012C010 00128F70  54 80 10 3A */	slwi r0, r4, 2
/* 8012C014 00128F74  54 A5 10 3A */	slwi r5, r5, 2
/* 8012C018 00128F78  80 9D 00 08 */	lwz r4, 8(r29)
/* 8012C01C 00128F7C  38 60 00 14 */	li r3, 0x14
/* 8012C020 00128F80  7F 84 01 2E */	stwx r28, r4, r0
/* 8012C024 00128F84  80 01 02 28 */	lwz r0, 0x228(r1)
/* 8012C028 00128F88  80 9D 00 08 */	lwz r4, 8(r29)
/* 8012C02C 00128F8C  7C 04 29 2E */	stwx r0, r4, r5
/* 8012C030 00128F90  80 97 00 08 */	lwz r4, 8(r23)
/* 8012C034 00128F94  93 A4 00 20 */	stw r29, 0x20(r4)
/* 8012C038 00128F98  4B F1 AF CD */	bl alloc__6SystemFUl
/* 8012C03C 00128F9C  3B C3 00 00 */	addi r30, r3, 0
/* 8012C040 00128FA0  7F C0 F3 79 */	or. r0, r30, r30
/* 8012C044 00128FA4  41 82 00 4C */	beq lbl_8012C090
/* 8012C048 00128FA8  80 61 02 20 */	lwz r3, 0x220(r1)
/* 8012C04C 00128FAC  3C A0 80 2D */	lis r5, __vt__14TaiTimerAction@ha
/* 8012C050 00128FB0  38 C5 CA 28 */	addi r6, r5, __vt__14TaiTimerAction@l
/* 8012C054 00128FB4  80 83 00 84 */	lwz r4, 0x84(r3)
/* 8012C058 00128FB8  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C05C 00128FBC  38 63 66 20 */	addi r3, r3, __vt__9TaiAction@l
/* 8012C060 00128FC0  80 84 00 04 */	lwz r4, 4(r4)
/* 8012C064 00128FC4  38 00 00 0A */	li r0, 0xa
/* 8012C068 00128FC8  38 A0 00 01 */	li r5, 1
/* 8012C06C 00128FCC  80 84 00 00 */	lwz r4, 0(r4)
/* 8012C070 00128FD0  C0 04 00 D8 */	lfs f0, 0xd8(r4)
/* 8012C074 00128FD4  C0 24 00 D4 */	lfs f1, 0xd4(r4)
/* 8012C078 00128FD8  90 7E 00 04 */	stw r3, 4(r30)
/* 8012C07C 00128FDC  90 1E 00 00 */	stw r0, 0(r30)
/* 8012C080 00128FE0  90 DE 00 04 */	stw r6, 4(r30)
/* 8012C084 00128FE4  90 BE 00 08 */	stw r5, 8(r30)
/* 8012C088 00128FE8  D0 3E 00 0C */	stfs f1, 0xc(r30)
/* 8012C08C 00128FEC  D0 1E 00 10 */	stfs f0, 0x10(r30)
lbl_8012C090:
/* 8012C090 00128FF0  38 60 00 10 */	li r3, 0x10
/* 8012C094 00128FF4  4B F1 AF 71 */	bl alloc__6SystemFUl
/* 8012C098 00128FF8  3B A3 00 00 */	addi r29, r3, 0
/* 8012C09C 00128FFC  7F A0 EB 79 */	or. r0, r29, r29
/* 8012C0A0 00129000  41 82 00 44 */	beq lbl_8012C0E4
/* 8012C0A4 00129004  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C0A8 00129008  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C0AC 0012900C  90 1D 00 04 */	stw r0, 4(r29)
/* 8012C0B0 00129010  38 00 FF FF */	li r0, -1
/* 8012C0B4 00129014  3C 60 80 2C */	lis r3, __vt__18TaiSetOptionAction@ha
/* 8012C0B8 00129018  90 1D 00 00 */	stw r0, 0(r29)
/* 8012C0BC 0012901C  38 63 6B 14 */	addi r3, r3, __vt__18TaiSetOptionAction@l
/* 8012C0C0 00129020  38 00 00 00 */	li r0, 0
/* 8012C0C4 00129024  90 7D 00 04 */	stw r3, 4(r29)
/* 8012C0C8 00129028  80 8D F6 2C */	lwz r4, TEKI_OPTION_VISIBLE__5BTeki@sda21(r13)
/* 8012C0CC 0012902C  80 6D F6 38 */	lwz r3, TEKI_OPTION_ATARI__5BTeki@sda21(r13)
/* 8012C0D0 00129030  80 AD F6 30 */	lwz r5, TEKI_OPTION_SHADOW_VISIBLE__5BTeki@sda21(r13)
/* 8012C0D4 00129034  7C 83 1B 78 */	or r3, r4, r3
/* 8012C0D8 00129038  7C A3 1B 78 */	or r3, r5, r3
/* 8012C0DC 0012903C  90 7D 00 08 */	stw r3, 8(r29)
/* 8012C0E0 00129040  98 1D 00 0C */	stb r0, 0xc(r29)
lbl_8012C0E4:
/* 8012C0E4 00129044  38 60 00 08 */	li r3, 8
/* 8012C0E8 00129048  4B F1 AF 1D */	bl alloc__6SystemFUl
/* 8012C0EC 0012904C  3B 63 00 00 */	addi r27, r3, 0
/* 8012C0F0 00129050  7F 60 DB 79 */	or. r0, r27, r27
/* 8012C0F4 00129054  41 82 00 24 */	beq lbl_8012C118
/* 8012C0F8 00129058  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C0FC 0012905C  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C100 00129060  90 1B 00 04 */	stw r0, 4(r27)
/* 8012C104 00129064  38 00 FF FF */	li r0, -1
/* 8012C108 00129068  3C 60 80 2D */	lis r3, __vt__25TaiMoveNestPositionAction@ha
/* 8012C10C 0012906C  90 1B 00 00 */	stw r0, 0(r27)
/* 8012C110 00129070  38 03 9F 04 */	addi r0, r3, __vt__25TaiMoveNestPositionAction@l
/* 8012C114 00129074  90 1B 00 04 */	stw r0, 4(r27)
lbl_8012C118:
/* 8012C118 00129078  38 60 00 0C */	li r3, 0xc
/* 8012C11C 0012907C  4B F1 AE E9 */	bl alloc__6SystemFUl
/* 8012C120 00129080  3B 83 00 00 */	addi r28, r3, 0
/* 8012C124 00129084  7F 83 E3 79 */	or. r3, r28, r28
/* 8012C128 00129088  41 82 00 0C */	beq lbl_8012C134
/* 8012C12C 0012908C  38 80 00 04 */	li r4, 4
/* 8012C130 00129090  4B FF AF 69 */	bl __ct__8TaiStateFi
lbl_8012C134:
/* 8012C134 00129094  38 00 00 00 */	li r0, 0
/* 8012C138 00129098  80 7C 00 08 */	lwz r3, 8(r28)
/* 8012C13C 0012909C  54 00 10 3A */	slwi r0, r0, 2
/* 8012C140 001290A0  7F 63 01 2E */	stwx r27, r3, r0
/* 8012C144 001290A4  38 00 00 01 */	li r0, 1
/* 8012C148 001290A8  38 A0 00 02 */	li r5, 2
/* 8012C14C 001290AC  80 9C 00 08 */	lwz r4, 8(r28)
/* 8012C150 001290B0  54 00 10 3A */	slwi r0, r0, 2
/* 8012C154 001290B4  38 60 00 03 */	li r3, 3
/* 8012C158 001290B8  7E A4 01 2E */	stwx r21, r4, r0
/* 8012C15C 001290BC  54 A0 10 3A */	slwi r0, r5, 2
/* 8012C160 001290C0  54 65 10 3A */	slwi r5, r3, 2
/* 8012C164 001290C4  80 9C 00 08 */	lwz r4, 8(r28)
/* 8012C168 001290C8  38 60 00 0C */	li r3, 0xc
/* 8012C16C 001290CC  7F A4 01 2E */	stwx r29, r4, r0
/* 8012C170 001290D0  80 9C 00 08 */	lwz r4, 8(r28)
/* 8012C174 001290D4  7F C4 29 2E */	stwx r30, r4, r5
/* 8012C178 001290D8  80 97 00 08 */	lwz r4, 8(r23)
/* 8012C17C 001290DC  93 84 00 24 */	stw r28, 0x24(r4)
/* 8012C180 001290E0  4B F1 AE 85 */	bl alloc__6SystemFUl
/* 8012C184 001290E4  3B 83 00 00 */	addi r28, r3, 0
/* 8012C188 001290E8  7F 80 E3 79 */	or. r0, r28, r28
/* 8012C18C 001290EC  41 82 00 2C */	beq lbl_8012C1B8
/* 8012C190 001290F0  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C194 001290F4  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C198 001290F8  90 1C 00 04 */	stw r0, 4(r28)
/* 8012C19C 001290FC  38 00 00 03 */	li r0, 3
/* 8012C1A0 00129100  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 8012C1A4 00129104  90 1C 00 00 */	stw r0, 0(r28)
/* 8012C1A8 00129108  38 63 95 94 */	addi r3, r3, __vt__15TaiMotionAction@l
/* 8012C1AC 0012910C  38 00 00 0B */	li r0, 0xb
/* 8012C1B0 00129110  90 7C 00 04 */	stw r3, 4(r28)
/* 8012C1B4 00129114  90 1C 00 08 */	stw r0, 8(r28)
lbl_8012C1B8:
/* 8012C1B8 00129118  38 60 00 10 */	li r3, 0x10
/* 8012C1BC 0012911C  4B F1 AE 49 */	bl alloc__6SystemFUl
/* 8012C1C0 00129120  3B C3 00 00 */	addi r30, r3, 0
/* 8012C1C4 00129124  7F C0 F3 79 */	or. r0, r30, r30
/* 8012C1C8 00129128  41 82 00 44 */	beq lbl_8012C20C
/* 8012C1CC 0012912C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C1D0 00129130  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C1D4 00129134  90 1E 00 04 */	stw r0, 4(r30)
/* 8012C1D8 00129138  38 00 FF FF */	li r0, -1
/* 8012C1DC 0012913C  3C 60 80 2C */	lis r3, __vt__18TaiSetOptionAction@ha
/* 8012C1E0 00129140  90 1E 00 00 */	stw r0, 0(r30)
/* 8012C1E4 00129144  38 63 6B 14 */	addi r3, r3, __vt__18TaiSetOptionAction@l
/* 8012C1E8 00129148  38 00 00 01 */	li r0, 1
/* 8012C1EC 0012914C  90 7E 00 04 */	stw r3, 4(r30)
/* 8012C1F0 00129150  80 8D F6 2C */	lwz r4, TEKI_OPTION_VISIBLE__5BTeki@sda21(r13)
/* 8012C1F4 00129154  80 6D F6 38 */	lwz r3, TEKI_OPTION_ATARI__5BTeki@sda21(r13)
/* 8012C1F8 00129158  80 AD F6 30 */	lwz r5, TEKI_OPTION_SHADOW_VISIBLE__5BTeki@sda21(r13)
/* 8012C1FC 0012915C  7C 83 1B 78 */	or r3, r4, r3
/* 8012C200 00129160  7C A3 1B 78 */	or r3, r5, r3
/* 8012C204 00129164  90 7E 00 08 */	stw r3, 8(r30)
/* 8012C208 00129168  98 1E 00 0C */	stb r0, 0xc(r30)
lbl_8012C20C:
/* 8012C20C 0012916C  38 60 00 08 */	li r3, 8
/* 8012C210 00129170  4B F1 AD F5 */	bl alloc__6SystemFUl
/* 8012C214 00129174  3B 63 00 00 */	addi r27, r3, 0
/* 8012C218 00129178  7F 60 DB 79 */	or. r0, r27, r27
/* 8012C21C 0012917C  41 82 00 24 */	beq lbl_8012C240
/* 8012C220 00129180  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C224 00129184  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C228 00129188  90 1B 00 04 */	stw r0, 4(r27)
/* 8012C22C 0012918C  38 00 FF FF */	li r0, -1
/* 8012C230 00129190  3C 60 80 2C */	lis r3, __vt__21TaiCollecGetOutAction@ha
/* 8012C234 00129194  90 1B 00 00 */	stw r0, 0(r27)
/* 8012C238 00129198  38 03 73 68 */	addi r0, r3, __vt__21TaiCollecGetOutAction@l
/* 8012C23C 0012919C  90 1B 00 04 */	stw r0, 4(r27)
lbl_8012C240:
/* 8012C240 001291A0  38 60 00 0C */	li r3, 0xc
/* 8012C244 001291A4  4B F1 AD C1 */	bl alloc__6SystemFUl
/* 8012C248 001291A8  3B A3 00 00 */	addi r29, r3, 0
/* 8012C24C 001291AC  7F A3 EB 79 */	or. r3, r29, r29
/* 8012C250 001291B0  41 82 00 0C */	beq lbl_8012C25C
/* 8012C254 001291B4  38 80 00 05 */	li r4, 5
/* 8012C258 001291B8  4B FF AE 41 */	bl __ct__8TaiStateFi
lbl_8012C25C:
/* 8012C25C 001291BC  38 00 00 00 */	li r0, 0
/* 8012C260 001291C0  80 7D 00 08 */	lwz r3, 8(r29)
/* 8012C264 001291C4  54 00 10 3A */	slwi r0, r0, 2
/* 8012C268 001291C8  80 81 02 30 */	lwz r4, 0x230(r1)
/* 8012C26C 001291CC  7E A3 01 2E */	stwx r21, r3, r0
/* 8012C270 001291D0  38 00 00 01 */	li r0, 1
/* 8012C274 001291D4  54 06 10 3A */	slwi r6, r0, 2
/* 8012C278 001291D8  80 7D 00 08 */	lwz r3, 8(r29)
/* 8012C27C 001291DC  38 A0 00 02 */	li r5, 2
/* 8012C280 001291E0  38 00 00 03 */	li r0, 3
/* 8012C284 001291E4  7C 83 31 2E */	stwx r4, r3, r6
/* 8012C288 001291E8  38 80 00 04 */	li r4, 4
/* 8012C28C 001291EC  54 A5 10 3A */	slwi r5, r5, 2
/* 8012C290 001291F0  80 7D 00 08 */	lwz r3, 8(r29)
/* 8012C294 001291F4  54 00 10 3A */	slwi r0, r0, 2
/* 8012C298 001291F8  54 84 10 3A */	slwi r4, r4, 2
/* 8012C29C 001291FC  7F 83 29 2E */	stwx r28, r3, r5
/* 8012C2A0 00129200  38 60 00 08 */	li r3, 8
/* 8012C2A4 00129204  80 BD 00 08 */	lwz r5, 8(r29)
/* 8012C2A8 00129208  7F 65 01 2E */	stwx r27, r5, r0
/* 8012C2AC 0012920C  80 BD 00 08 */	lwz r5, 8(r29)
/* 8012C2B0 00129210  7F C5 21 2E */	stwx r30, r5, r4
/* 8012C2B4 00129214  80 97 00 08 */	lwz r4, 8(r23)
/* 8012C2B8 00129218  93 A4 00 28 */	stw r29, 0x28(r4)
/* 8012C2BC 0012921C  4B F1 AD 49 */	bl alloc__6SystemFUl
/* 8012C2C0 00129220  3B 83 00 00 */	addi r28, r3, 0
/* 8012C2C4 00129224  7F 80 E3 79 */	or. r0, r28, r28
/* 8012C2C8 00129228  41 82 00 24 */	beq lbl_8012C2EC
/* 8012C2CC 0012922C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C2D0 00129230  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C2D4 00129234  90 1C 00 04 */	stw r0, 4(r28)
/* 8012C2D8 00129238  38 00 00 0C */	li r0, 0xc
/* 8012C2DC 0012923C  3C 60 80 2C */	lis r3, __vt__40TaiCollecPelletFinishContainerizedAction@ha
/* 8012C2E0 00129240  90 1C 00 00 */	stw r0, 0(r28)
/* 8012C2E4 00129244  38 03 74 40 */	addi r0, r3, __vt__40TaiCollecPelletFinishContainerizedAction@l
/* 8012C2E8 00129248  90 1C 00 04 */	stw r0, 4(r28)
lbl_8012C2EC:
/* 8012C2EC 0012924C  38 60 00 0C */	li r3, 0xc
/* 8012C2F0 00129250  4B F1 AD 15 */	bl alloc__6SystemFUl
/* 8012C2F4 00129254  3B 23 00 00 */	addi r25, r3, 0
/* 8012C2F8 00129258  7F 23 CB 79 */	or. r3, r25, r25
/* 8012C2FC 0012925C  41 82 00 0C */	beq lbl_8012C308
/* 8012C300 00129260  38 80 00 01 */	li r4, 1
/* 8012C304 00129264  4B FF AD 95 */	bl __ct__8TaiStateFi
lbl_8012C308:
/* 8012C308 00129268  38 00 00 00 */	li r0, 0
/* 8012C30C 0012926C  80 79 00 08 */	lwz r3, 8(r25)
/* 8012C310 00129270  54 00 10 3A */	slwi r0, r0, 2
/* 8012C314 00129274  7F 83 01 2E */	stwx r28, r3, r0
/* 8012C318 00129278  38 60 00 0C */	li r3, 0xc
/* 8012C31C 0012927C  80 97 00 08 */	lwz r4, 8(r23)
/* 8012C320 00129280  93 24 00 2C */	stw r25, 0x2c(r4)
/* 8012C324 00129284  4B F1 AC E1 */	bl alloc__6SystemFUl
/* 8012C328 00129288  3B A3 00 00 */	addi r29, r3, 0
/* 8012C32C 0012928C  7F A0 EB 79 */	or. r0, r29, r29
/* 8012C330 00129290  41 82 00 38 */	beq lbl_8012C368
/* 8012C334 00129294  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C338 00129298  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C33C 0012929C  90 1D 00 04 */	stw r0, 4(r29)
/* 8012C340 001292A0  38 00 FF FF */	li r0, -1
/* 8012C344 001292A4  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 8012C348 001292A8  90 1D 00 00 */	stw r0, 0(r29)
/* 8012C34C 001292AC  38 03 95 94 */	addi r0, r3, __vt__15TaiMotionAction@l
/* 8012C350 001292B0  3C 60 80 2D */	lis r3, __vt__21TaiFinishMotionAction@ha
/* 8012C354 001292B4  90 1D 00 04 */	stw r0, 4(r29)
/* 8012C358 001292B8  38 00 00 00 */	li r0, 0
/* 8012C35C 001292BC  38 63 95 28 */	addi r3, r3, __vt__21TaiFinishMotionAction@l
/* 8012C360 001292C0  90 1D 00 08 */	stw r0, 8(r29)
/* 8012C364 001292C4  90 7D 00 04 */	stw r3, 4(r29)
lbl_8012C368:
/* 8012C368 001292C8  38 60 00 0C */	li r3, 0xc
/* 8012C36C 001292CC  4B F1 AC 99 */	bl alloc__6SystemFUl
/* 8012C370 001292D0  3B E3 00 00 */	addi r31, r3, 0
/* 8012C374 001292D4  7F E0 FB 79 */	or. r0, r31, r31
/* 8012C378 001292D8  41 82 00 3C */	beq lbl_8012C3B4
/* 8012C37C 001292DC  80 61 02 20 */	lwz r3, 0x220(r1)
/* 8012C380 001292E0  3C 80 80 2C */	lis r4, __vt__9TaiAction@ha
/* 8012C384 001292E4  38 84 66 20 */	addi r4, r4, __vt__9TaiAction@l
/* 8012C388 001292E8  80 A3 00 84 */	lwz r5, 0x84(r3)
/* 8012C38C 001292EC  3C 60 80 2D */	lis r3, __vt__17TaiRotatingAction@ha
/* 8012C390 001292F0  38 00 FF FF */	li r0, -1
/* 8012C394 001292F4  80 A5 00 04 */	lwz r5, 4(r5)
/* 8012C398 001292F8  38 63 97 D8 */	addi r3, r3, __vt__17TaiRotatingAction@l
/* 8012C39C 001292FC  80 A5 00 00 */	lwz r5, 0(r5)
/* 8012C3A0 00129300  C0 05 00 DC */	lfs f0, 0xdc(r5)
/* 8012C3A4 00129304  90 9F 00 04 */	stw r4, 4(r31)
/* 8012C3A8 00129308  90 1F 00 00 */	stw r0, 0(r31)
/* 8012C3AC 0012930C  90 7F 00 04 */	stw r3, 4(r31)
/* 8012C3B0 00129310  D0 1F 00 08 */	stfs f0, 8(r31)
lbl_8012C3B4:
/* 8012C3B4 00129314  38 60 00 08 */	li r3, 8
/* 8012C3B8 00129318  4B F1 AC 4D */	bl alloc__6SystemFUl
/* 8012C3BC 0012931C  3B 43 00 00 */	addi r26, r3, 0
/* 8012C3C0 00129320  7F 40 D3 79 */	or. r0, r26, r26
/* 8012C3C4 00129324  41 82 00 24 */	beq lbl_8012C3E8
/* 8012C3C8 00129328  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C3CC 0012932C  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C3D0 00129330  90 1A 00 04 */	stw r0, 4(r26)
/* 8012C3D4 00129334  38 00 00 00 */	li r0, 0
/* 8012C3D8 00129338  3C 60 80 2C */	lis r3, __vt__26TaiCollecDeadFallingAction@ha
/* 8012C3DC 0012933C  90 1A 00 00 */	stw r0, 0(r26)
/* 8012C3E0 00129340  38 03 73 EC */	addi r0, r3, __vt__26TaiCollecDeadFallingAction@l
/* 8012C3E4 00129344  90 1A 00 04 */	stw r0, 4(r26)
lbl_8012C3E8:
/* 8012C3E8 00129348  38 60 00 08 */	li r3, 8
/* 8012C3EC 0012934C  4B F1 AC 19 */	bl alloc__6SystemFUl
/* 8012C3F0 00129350  3B 63 00 00 */	addi r27, r3, 0
/* 8012C3F4 00129354  7F 60 DB 79 */	or. r0, r27, r27
/* 8012C3F8 00129358  41 82 00 24 */	beq lbl_8012C41C
/* 8012C3FC 0012935C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C400 00129360  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C404 00129364  90 1B 00 04 */	stw r0, 4(r27)
/* 8012C408 00129368  38 00 00 0D */	li r0, 0xd
/* 8012C40C 0012936C  3C 60 80 2C */	lis r3, __vt__22TaiCollecFallingAction@ha
/* 8012C410 00129370  90 1B 00 00 */	stw r0, 0(r27)
/* 8012C414 00129374  38 03 73 A8 */	addi r0, r3, __vt__22TaiCollecFallingAction@l
/* 8012C418 00129378  90 1B 00 04 */	stw r0, 4(r27)
lbl_8012C41C:
/* 8012C41C 0012937C  38 60 00 0C */	li r3, 0xc
/* 8012C420 00129380  4B F1 AB E5 */	bl alloc__6SystemFUl
/* 8012C424 00129384  3B 83 00 00 */	addi r28, r3, 0
/* 8012C428 00129388  7F 80 E3 79 */	or. r0, r28, r28
/* 8012C42C 0012938C  41 82 00 2C */	beq lbl_8012C458
/* 8012C430 00129390  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C434 00129394  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C438 00129398  90 1C 00 04 */	stw r0, 4(r28)
/* 8012C43C 0012939C  38 00 FF FF */	li r0, -1
/* 8012C440 001293A0  3C 60 80 2C */	lis r3, __vt__18TaiPlaySoundAction@ha
/* 8012C444 001293A4  90 1C 00 00 */	stw r0, 0(r28)
/* 8012C448 001293A8  38 63 6A D8 */	addi r3, r3, __vt__18TaiPlaySoundAction@l
/* 8012C44C 001293AC  38 00 00 74 */	li r0, 0x74
/* 8012C450 001293B0  90 7C 00 04 */	stw r3, 4(r28)
/* 8012C454 001293B4  90 1C 00 08 */	stw r0, 8(r28)
lbl_8012C458:
/* 8012C458 001293B8  38 60 00 0C */	li r3, 0xc
/* 8012C45C 001293BC  4B F1 AB A9 */	bl alloc__6SystemFUl
/* 8012C460 001293C0  3B C3 00 00 */	addi r30, r3, 0
/* 8012C464 001293C4  7F C3 F3 79 */	or. r3, r30, r30
/* 8012C468 001293C8  41 82 00 0C */	beq lbl_8012C474
/* 8012C46C 001293CC  38 80 00 06 */	li r4, 6
/* 8012C470 001293D0  4B FF AC 29 */	bl __ct__8TaiStateFi
lbl_8012C474:
/* 8012C474 001293D4  38 00 00 00 */	li r0, 0
/* 8012C478 001293D8  80 7E 00 08 */	lwz r3, 8(r30)
/* 8012C47C 001293DC  54 00 10 3A */	slwi r0, r0, 2
/* 8012C480 001293E0  7E 83 01 2E */	stwx r20, r3, r0
/* 8012C484 001293E4  38 00 00 01 */	li r0, 1
/* 8012C488 001293E8  38 A0 00 02 */	li r5, 2
/* 8012C48C 001293EC  80 7E 00 08 */	lwz r3, 8(r30)
/* 8012C490 001293F0  54 04 10 3A */	slwi r4, r0, 2
/* 8012C494 001293F4  38 00 00 03 */	li r0, 3
/* 8012C498 001293F8  7F A3 21 2E */	stwx r29, r3, r4
/* 8012C49C 001293FC  38 60 00 04 */	li r3, 4
/* 8012C4A0 00129400  38 80 00 05 */	li r4, 5
/* 8012C4A4 00129404  80 DE 00 08 */	lwz r6, 8(r30)
/* 8012C4A8 00129408  54 A5 10 3A */	slwi r5, r5, 2
/* 8012C4AC 0012940C  54 00 10 3A */	slwi r0, r0, 2
/* 8012C4B0 00129410  7F E6 29 2E */	stwx r31, r6, r5
/* 8012C4B4 00129414  54 65 10 3A */	slwi r5, r3, 2
/* 8012C4B8 00129418  54 86 10 3A */	slwi r6, r4, 2
/* 8012C4BC 0012941C  80 9E 00 08 */	lwz r4, 8(r30)
/* 8012C4C0 00129420  38 60 00 0C */	li r3, 0xc
/* 8012C4C4 00129424  7F 44 01 2E */	stwx r26, r4, r0
/* 8012C4C8 00129428  80 9E 00 08 */	lwz r4, 8(r30)
/* 8012C4CC 0012942C  7F 64 29 2E */	stwx r27, r4, r5
/* 8012C4D0 00129430  80 9E 00 08 */	lwz r4, 8(r30)
/* 8012C4D4 00129434  7F 84 31 2E */	stwx r28, r4, r6
/* 8012C4D8 00129438  80 97 00 08 */	lwz r4, 8(r23)
/* 8012C4DC 0012943C  93 C4 00 30 */	stw r30, 0x30(r4)
/* 8012C4E0 00129440  4B F1 AB 25 */	bl alloc__6SystemFUl
/* 8012C4E4 00129444  3B 83 00 00 */	addi r28, r3, 0
/* 8012C4E8 00129448  7F 80 E3 79 */	or. r0, r28, r28
/* 8012C4EC 0012944C  41 82 00 2C */	beq lbl_8012C518
/* 8012C4F0 00129450  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C4F4 00129454  38 03 66 20 */	addi r0, r3, __vt__9TaiAction@l
/* 8012C4F8 00129458  90 1C 00 04 */	stw r0, 4(r28)
/* 8012C4FC 0012945C  38 00 00 03 */	li r0, 3
/* 8012C500 00129460  3C 60 80 2D */	lis r3, __vt__15TaiMotionAction@ha
/* 8012C504 00129464  90 1C 00 00 */	stw r0, 0(r28)
/* 8012C508 00129468  38 63 95 94 */	addi r3, r3, __vt__15TaiMotionAction@l
/* 8012C50C 0012946C  38 00 00 0D */	li r0, 0xd
/* 8012C510 00129470  90 7C 00 04 */	stw r3, 4(r28)
/* 8012C514 00129474  90 1C 00 08 */	stw r0, 8(r28)
lbl_8012C518:
/* 8012C518 00129478  38 60 00 0C */	li r3, 0xc
/* 8012C51C 0012947C  4B F1 AA E9 */	bl alloc__6SystemFUl
/* 8012C520 00129480  3B A3 00 00 */	addi r29, r3, 0
/* 8012C524 00129484  7F A0 EB 79 */	or. r0, r29, r29
/* 8012C528 00129488  41 82 00 3C */	beq lbl_8012C564
/* 8012C52C 0012948C  80 61 02 20 */	lwz r3, 0x220(r1)
/* 8012C530 00129490  3C 80 80 2C */	lis r4, __vt__9TaiAction@ha
/* 8012C534 00129494  38 84 66 20 */	addi r4, r4, __vt__9TaiAction@l
/* 8012C538 00129498  80 A3 00 84 */	lwz r5, 0x84(r3)
/* 8012C53C 0012949C  3C 60 80 2D */	lis r3, __vt__19TaiLifeDamageAction@ha
/* 8012C540 001294A0  38 00 FF FF */	li r0, -1
/* 8012C544 001294A4  80 A5 00 04 */	lwz r5, 4(r5)
/* 8012C548 001294A8  38 63 BC B4 */	addi r3, r3, __vt__19TaiLifeDamageAction@l
/* 8012C54C 001294AC  80 A5 00 00 */	lwz r5, 0(r5)
/* 8012C550 001294B0  C0 05 00 C8 */	lfs f0, 0xc8(r5)
/* 8012C554 001294B4  90 9D 00 04 */	stw r4, 4(r29)
/* 8012C558 001294B8  90 1D 00 00 */	stw r0, 0(r29)
/* 8012C55C 001294BC  90 7D 00 04 */	stw r3, 4(r29)
/* 8012C560 001294C0  D0 1D 00 08 */	stfs f0, 8(r29)
lbl_8012C564:
/* 8012C564 001294C4  38 60 00 0C */	li r3, 0xc
/* 8012C568 001294C8  4B F1 AA 9D */	bl alloc__6SystemFUl
/* 8012C56C 001294CC  3B 63 00 00 */	addi r27, r3, 0
/* 8012C570 001294D0  7F 63 DB 79 */	or. r3, r27, r27
/* 8012C574 001294D4  41 82 00 0C */	beq lbl_8012C580
/* 8012C578 001294D8  38 80 00 03 */	li r4, 3
/* 8012C57C 001294DC  4B FF AB 1D */	bl __ct__8TaiStateFi
lbl_8012C580:
/* 8012C580 001294E0  38 00 00 00 */	li r0, 0
/* 8012C584 001294E4  80 7B 00 08 */	lwz r3, 8(r27)
/* 8012C588 001294E8  54 00 10 3A */	slwi r0, r0, 2
/* 8012C58C 001294EC  7E A3 01 2E */	stwx r21, r3, r0
/* 8012C590 001294F0  38 80 00 01 */	li r4, 1
/* 8012C594 001294F4  38 00 00 02 */	li r0, 2
/* 8012C598 001294F8  80 7B 00 08 */	lwz r3, 8(r27)
/* 8012C59C 001294FC  54 84 10 3A */	slwi r4, r4, 2
/* 8012C5A0 00129500  54 00 10 3A */	slwi r0, r0, 2
/* 8012C5A4 00129504  7F A3 21 2E */	stwx r29, r3, r4
/* 8012C5A8 00129508  38 60 00 14 */	li r3, 0x14
/* 8012C5AC 0012950C  80 9B 00 08 */	lwz r4, 8(r27)
/* 8012C5B0 00129510  7F 84 01 2E */	stwx r28, r4, r0
/* 8012C5B4 00129514  80 97 00 08 */	lwz r4, 8(r23)
/* 8012C5B8 00129518  93 64 00 34 */	stw r27, 0x34(r4)
/* 8012C5BC 0012951C  4B F1 AA 49 */	bl alloc__6SystemFUl
/* 8012C5C0 00129520  3B C3 00 00 */	addi r30, r3, 0
/* 8012C5C4 00129524  7F C0 F3 79 */	or. r0, r30, r30
/* 8012C5C8 00129528  41 82 00 4C */	beq lbl_8012C614
/* 8012C5CC 0012952C  80 61 02 20 */	lwz r3, 0x220(r1)
/* 8012C5D0 00129530  3C A0 80 2D */	lis r5, __vt__14TaiTimerAction@ha
/* 8012C5D4 00129534  38 C5 CA 28 */	addi r6, r5, __vt__14TaiTimerAction@l
/* 8012C5D8 00129538  80 83 00 84 */	lwz r4, 0x84(r3)
/* 8012C5DC 0012953C  3C 60 80 2C */	lis r3, __vt__9TaiAction@ha
/* 8012C5E0 00129540  38 63 66 20 */	addi r3, r3, __vt__9TaiAction@l
/* 8012C5E4 00129544  80 84 00 04 */	lwz r4, 4(r4)
/* 8012C5E8 00129548  38 00 00 0A */	li r0, 0xa
/* 8012C5EC 0012954C  38 A0 00 01 */	li r5, 1
/* 8012C5F0 00129550  80 84 00 00 */	lwz r4, 0(r4)
/* 8012C5F4 00129554  C0 04 00 E8 */	lfs f0, 0xe8(r4)
/* 8012C5F8 00129558  90 7E 00 04 */	stw r3, 4(r30)
/* 8012C5FC 0012955C  90 1E 00 00 */	stw r0, 0(r30)
/* 8012C600 00129560  90 DE 00 04 */	stw r6, 4(r30)
/* 8012C604 00129564  90 BE 00 08 */	stw r5, 8(r30)
/* 8012C608 00129568  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8012C60C 0012956C  C0 02 A2 A0 */	lfs f0, lbl_803EA4A0@sda21(r2)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x6b657949
  .4byte 0x74656d2e
  .4byte 0x63707000
  .4byte 0x446f6f72
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
  .4byte 0x803e19c8
  .4byte 0x8
  .4byte 0x803e19d0
  .4byte 0
  .4byte 0
  .4byte 0x41494372
  .4byte 0x65617475
  .4byte 0x72650000
  .4byte 0x803e19c0
  .4byte 0x2b8
  .4byte 0x803e19c8
  .4byte 0x8
  .4byte 0x803e19d0
  .4byte 0
  .4byte 0x803e19d8
  .4byte 0
  .4byte 0
  .4byte 0x4974656d
  .4byte 0x43726561
  .4byte 0x74757265
  .4byte 0
  .4byte 0x803e19c0
  .4byte 0x2b8
  .4byte 0x803e19c8
  .4byte 0x8
  .4byte 0x803e19d0
  .4byte 0
  .4byte 0x803e19d8
  .4byte 0
  .4byte 0x803e19e0
  .4byte 0
  .4byte 0
  .4byte 0x803e19c0
  .4byte 0x2b8
  .4byte 0x803e19c8
  .4byte 0x8
  .4byte 0x803e19d0
  .4byte 0
  .4byte 0x803e19d8
  .4byte 0
  .4byte 0x803e19e0
  .4byte 0
  .4byte 0x803e19e8
  .4byte 0
  .4byte 0
.global __vt__8DoorItem
__vt__8DoorItem:
  .4byte __RTTI__8DoorItem
  .4byte 0
  .4byte addCntCallback__12RefCountableFv
  .4byte subCntCallback__12RefCountableFv
  .4byte insideSafeArea__8CreatureFR8Vector3f
  .4byte platAttachable__8CreatureFv
  .4byte alwaysUpdatePlatform__8CreatureFv
  .4byte doDoAI__8CreatureFv
  .4byte setRouteTracer__8CreatureFP11RouteTracer
  .4byte init__8CreatureFv
  .4byte init__8DoorItemFR8Vector3f
  .4byte resetPosition__8CreatureFR8Vector3f
  .4byte initParam__8CreatureFi
  .4byte startAI__8DoorItemFi
  .4byte getiMass__8DoorItemFv
  .4byte getSize__8DoorItemFv
  .4byte getHeight__8DoorItemFv
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
  .4byte isVisible__8DoorItemFv
  .4byte isOrganic__8CreatureFv
  .4byte isTerrible__8CreatureFv
  .4byte isBuried__8CreatureFv
  .4byte isAtari__8DoorItemFv
  .4byte isAlive__8DoorItemFv
  .4byte isFixed__8CreatureFv
  .4byte needShadow__8CreatureFv
  .4byte needFlick__8CreatureFP8Creature
  .4byte ignoreAtari__8CreatureFP8Creature
  .4byte isFree__8CreatureFv
  .4byte stimulate__12ItemCreatureFR11Interaction
  .4byte sendMsg__8CreatureFP3Msg
  .4byte collisionCallback__10AICreatureFR9CollEvent
  .4byte bounceCallback__10AICreatureFv
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
  .4byte update__8DoorItemFv
  .4byte postUpdate__8CreatureFif
  .4byte stickUpdate__8CreatureFv
  .4byte refresh__8DoorItemFR8Graphics
  .4byte refresh2d__8CreatureFR8Graphics
  .4byte renderAtari__8CreatureFR8Graphics
  .4byte drawShadow__8CreatureFR8Graphics
  .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
  .4byte getCatchPos__8CreatureFP8Creature
  .4byte doAI__12ItemCreatureFv
  .4byte doAnimation__12ItemCreatureFv
  .4byte doKill__12ItemCreatureFv
  .4byte exitCourse__8CreatureFv
  .4byte __RTTI__8DoorItem
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
  .4byte 0x803e19c8
  .4byte 0x8
  .4byte 0x803e19d0
  .4byte 0
  .4byte 0x803e19d8
  .4byte 0
  .4byte 0
.global __vt__7KeyItem
__vt__7KeyItem:
  .4byte __RTTI__7KeyItem
  .4byte 0
  .4byte addCntCallback__12RefCountableFv
  .4byte subCntCallback__12RefCountableFv
  .4byte insideSafeArea__8CreatureFR8Vector3f
  .4byte platAttachable__8CreatureFv
  .4byte alwaysUpdatePlatform__8CreatureFv
  .4byte doDoAI__8CreatureFv
  .4byte setRouteTracer__8CreatureFP11RouteTracer
  .4byte init__8CreatureFv
  .4byte init__7KeyItemFR8Vector3f
  .4byte resetPosition__8CreatureFR8Vector3f
  .4byte initParam__8CreatureFi
  .4byte startAI__7KeyItemFi
  .4byte getiMass__7KeyItemFv
  .4byte getSize__7KeyItemFv
  .4byte getHeight__7KeyItemFv
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
  .4byte isVisible__7KeyItemFv
  .4byte isOrganic__8CreatureFv
  .4byte isTerrible__8CreatureFv
  .4byte isBuried__8CreatureFv
  .4byte isAtari__8CreatureFv
  .4byte isAlive__8CreatureFv
  .4byte isFixed__8CreatureFv
  .4byte needShadow__8CreatureFv
  .4byte needFlick__8CreatureFP8Creature
  .4byte ignoreAtari__8CreatureFP8Creature
  .4byte isFree__8CreatureFv
  .4byte stimulate__8CreatureFR11Interaction
  .4byte sendMsg__8CreatureFP3Msg
  .4byte collisionCallback__7KeyItemFR9CollEvent
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
  .4byte update__7KeyItemFv
  .4byte postUpdate__8CreatureFif
  .4byte stickUpdate__8CreatureFv
  .4byte refresh__7KeyItemFR8Graphics
  .4byte refresh2d__8CreatureFR8Graphics
  .4byte renderAtari__8CreatureFR8Graphics
  .4byte drawShadow__8CreatureFR8Graphics
  .4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
  .4byte getCatchPos__8CreatureFP8Creature
  .4byte doAI__8CreatureFv
  .4byte doAnimation__8CreatureFv
  .4byte doKill__7KeyItemFv
  .4byte exitCourse__8CreatureFv
  .4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x802BCDA0
	.4byte 0x802BCDC4
	.4byte 0x802BCDD4
.global __RTTI__12PikiHeadItem
__RTTI__12PikiHeadItem:
  .4byte 0x802bcd34
  .4byte 0x802bce00
  .4byte 0x802bcf90
  .4byte 0
  .4byte 0x802bcfb4
  .4byte 0
  .4byte 0x802bcff4
  .4byte 0
  .4byte 0
.global lbl_803E19A8
lbl_803E19A8:
	.4byte 0x40000000
.global lbl_803E19AC
lbl_803E19AC:
	.4byte 0x40000000
.global lbl_803E19B0
lbl_803E19B0:
	.4byte 0x00000000
.global lbl_803E19B4
lbl_803E19B4:
	.4byte 0x42200000
.global lbl_803E19B8
lbl_803E19B8:
	.4byte 0x00000000
.global lbl_803E19BC
lbl_803E19BC:
	.4byte 0x25730000
	.4byte 0x802BD0B8
	.4byte 0x00000000
	.4byte 0x802BD0CC
	.4byte 0x00000000
	.4byte 0x802BD0D8
	.4byte 0x00000000
