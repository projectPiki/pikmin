.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global createInstance__10AIConstantFv
createInstance__10AIConstantFv:
/* 80083E60 00080DC0  7C 08 02 A6 */	mflr r0
/* 80083E64 00080DC4  90 01 00 04 */	stw r0, 4(r1)
/* 80083E68 00080DC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80083E6C 00080DCC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80083E70 00080DD0  80 0D 2F 80 */	lwz r0, _instance__10AIConstant@sda21(r13)
/* 80083E74 00080DD4  28 00 00 00 */	cmplwi r0, 0
/* 80083E78 00080DD8  40 82 00 20 */	bne lbl_80083E98
/* 80083E7C 00080DDC  38 60 01 94 */	li r3, 0x194
/* 80083E80 00080DE0  4B FC 31 85 */	bl alloc__6SystemFUl
/* 80083E84 00080DE4  3B E3 00 00 */	addi r31, r3, 0
/* 80083E88 00080DE8  7F E3 FB 79 */	or. r3, r31, r31
/* 80083E8C 00080DEC  41 82 00 08 */	beq lbl_80083E94
/* 80083E90 00080DF0  48 00 00 1D */	bl __ct__10AIConstantFv
lbl_80083E94:
/* 80083E94 00080DF4  93 ED 2F 80 */	stw r31, _instance__10AIConstant@sda21(r13)
lbl_80083E98:
/* 80083E98 00080DF8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80083E9C 00080DFC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80083EA0 00080E00  38 21 00 10 */	addi r1, r1, 0x10
/* 80083EA4 00080E04  7C 08 03 A6 */	mtlr r0
/* 80083EA8 00080E08  4E 80 00 20 */	blr 

.global __ct__10AIConstantFv
__ct__10AIConstantFv:
/* 80083EAC 00080E0C  7C 08 02 A6 */	mflr r0
/* 80083EB0 00080E10  3C 80 80 22 */	lis r4, __vt__5ANode@ha
/* 80083EB4 00080E14  90 01 00 04 */	stw r0, 4(r1)
/* 80083EB8 00080E18  38 04 73 8C */	addi r0, r4, __vt__5ANode@l
/* 80083EBC 00080E1C  38 8D 9F C8 */	addi r4, r13, lbl_803DECE8@sda21
/* 80083EC0 00080E20  94 21 FE 68 */	stwu r1, -0x198(r1)
/* 80083EC4 00080E24  BF 61 01 84 */	stmw r27, 0x184(r1)
/* 80083EC8 00080E28  3B E3 00 00 */	addi r31, r3, 0
/* 80083ECC 00080E2C  3C 60 80 22 */	lis r3, __vt__8CoreNode@ha
/* 80083ED0 00080E30  3B 60 00 00 */	li r27, 0
/* 80083ED4 00080E34  90 1F 00 00 */	stw r0, 0(r31)
/* 80083ED8 00080E38  38 03 73 7C */	addi r0, r3, __vt__8CoreNode@l
/* 80083EDC 00080E3C  38 7F 00 00 */	addi r3, r31, 0
/* 80083EE0 00080E40  90 1F 00 00 */	stw r0, 0(r31)
/* 80083EE4 00080E44  93 7F 00 10 */	stw r27, 0x10(r31)
/* 80083EE8 00080E48  93 7F 00 0C */	stw r27, 0xc(r31)
/* 80083EEC 00080E4C  93 7F 00 08 */	stw r27, 8(r31)
/* 80083EF0 00080E50  4B FA 0F E5 */	bl setName__8CoreNodeFPc
/* 80083EF4 00080E54  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 80083EF8 00080E58  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 80083EFC 00080E5C  90 1F 00 00 */	stw r0, 0(r31)
/* 80083F00 00080E60  38 7F 00 00 */	addi r3, r31, 0
/* 80083F04 00080E64  38 8D 9F C8 */	addi r4, r13, lbl_803DECE8@sda21
/* 80083F08 00080E68  4B FB C8 35 */	bl init__4NodeFPc
/* 80083F0C 00080E6C  3C 60 80 2B */	lis r3, __vt__10AIConstant@ha
/* 80083F10 00080E70  38 03 E7 94 */	addi r0, r3, __vt__10AIConstant@l
/* 80083F14 00080E74  90 1F 00 00 */	stw r0, 0(r31)
/* 80083F18 00080E78  38 A1 00 C0 */	addi r5, r1, 0xc0
/* 80083F1C 00080E7C  38 7F 00 24 */	addi r3, r31, 0x24
/* 80083F20 00080E80  93 7F 00 20 */	stw r27, 0x20(r31)
/* 80083F24 00080E84  38 9F 00 20 */	addi r4, r31, 0x20
/* 80083F28 00080E88  80 0D 9F D0 */	lwz r0, lbl_803DECF0@sda21(r13)
/* 80083F2C 00080E8C  90 01 00 C8 */	stw r0, 0xc8(r1)
/* 80083F30 00080E90  80 01 00 C8 */	lwz r0, 0xc8(r1)
/* 80083F34 00080E94  90 01 00 C0 */	stw r0, 0xc0(r1)
/* 80083F38 00080E98  4B FD AB 49 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80083F3C 00080E9C  3C 60 80 2A */	lis r3, "__vt__7Parm<f>"@ha
/* 80083F40 00080EA0  3B 83 60 98 */	addi r28, r3, "__vt__7Parm<f>"@l
/* 80083F44 00080EA4  93 9F 00 2C */	stw r28, 0x2c(r31)
/* 80083F48 00080EA8  38 A1 00 BC */	addi r5, r1, 0xbc
/* 80083F4C 00080EAC  38 7F 00 34 */	addi r3, r31, 0x34
/* 80083F50 00080EB0  C0 02 8A 20 */	lfs f0, lbl_803E8C20@sda21(r2)
/* 80083F54 00080EB4  38 9F 00 20 */	addi r4, r31, 0x20
/* 80083F58 00080EB8  D0 1F 00 30 */	stfs f0, 0x30(r31)
/* 80083F5C 00080EBC  80 0D 9F D4 */	lwz r0, lbl_803DECF4@sda21(r13)
/* 80083F60 00080EC0  90 01 00 D0 */	stw r0, 0xd0(r1)
/* 80083F64 00080EC4  80 01 00 D0 */	lwz r0, 0xd0(r1)
/* 80083F68 00080EC8  90 01 00 BC */	stw r0, 0xbc(r1)
/* 80083F6C 00080ECC  4B FD AB 15 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80083F70 00080ED0  3C 60 80 2A */	lis r3, "__vt__7Parm<i>"@ha
/* 80083F74 00080ED4  3B C3 60 C4 */	addi r30, r3, "__vt__7Parm<i>"@l
/* 80083F78 00080ED8  93 DF 00 3C */	stw r30, 0x3c(r31)
/* 80083F7C 00080EDC  3B A0 00 01 */	li r29, 1
/* 80083F80 00080EE0  38 A1 00 B8 */	addi r5, r1, 0xb8
/* 80083F84 00080EE4  93 BF 00 40 */	stw r29, 0x40(r31)
/* 80083F88 00080EE8  38 7F 00 44 */	addi r3, r31, 0x44
/* 80083F8C 00080EEC  38 9F 00 20 */	addi r4, r31, 0x20
/* 80083F90 00080EF0  80 0D 9F D8 */	lwz r0, lbl_803DECF8@sda21(r13)
/* 80083F94 00080EF4  90 01 00 D8 */	stw r0, 0xd8(r1)
/* 80083F98 00080EF8  80 01 00 D8 */	lwz r0, 0xd8(r1)
/* 80083F9C 00080EFC  90 01 00 B8 */	stw r0, 0xb8(r1)
/* 80083FA0 00080F00  4B FD AA E1 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80083FA4 00080F04  93 DF 00 4C */	stw r30, 0x4c(r31)
/* 80083FA8 00080F08  38 A1 00 B4 */	addi r5, r1, 0xb4
/* 80083FAC 00080F0C  38 7F 00 54 */	addi r3, r31, 0x54
/* 80083FB0 00080F10  93 BF 00 50 */	stw r29, 0x50(r31)
/* 80083FB4 00080F14  38 9F 00 20 */	addi r4, r31, 0x20
/* 80083FB8 00080F18  80 0D 9F DC */	lwz r0, lbl_803DECFC@sda21(r13)
/* 80083FBC 00080F1C  90 01 00 E0 */	stw r0, 0xe0(r1)
/* 80083FC0 00080F20  80 01 00 E0 */	lwz r0, 0xe0(r1)
/* 80083FC4 00080F24  90 01 00 B4 */	stw r0, 0xb4(r1)
/* 80083FC8 00080F28  4B FD AA B9 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80083FCC 00080F2C  93 DF 00 5C */	stw r30, 0x5c(r31)
/* 80083FD0 00080F30  38 A1 00 B0 */	addi r5, r1, 0xb0
/* 80083FD4 00080F34  38 7F 00 64 */	addi r3, r31, 0x64
/* 80083FD8 00080F38  93 7F 00 60 */	stw r27, 0x60(r31)
/* 80083FDC 00080F3C  38 9F 00 20 */	addi r4, r31, 0x20
/* 80083FE0 00080F40  80 0D 9F E0 */	lwz r0, lbl_803DED00@sda21(r13)
/* 80083FE4 00080F44  90 01 00 E8 */	stw r0, 0xe8(r1)
/* 80083FE8 00080F48  80 01 00 E8 */	lwz r0, 0xe8(r1)
/* 80083FEC 00080F4C  90 01 00 B0 */	stw r0, 0xb0(r1)
/* 80083FF0 00080F50  4B FD AA 91 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80083FF4 00080F54  93 DF 00 6C */	stw r30, 0x6c(r31)
/* 80083FF8 00080F58  38 A1 00 AC */	addi r5, r1, 0xac
/* 80083FFC 00080F5C  38 7F 00 74 */	addi r3, r31, 0x74
/* 80084000 00080F60  93 BF 00 70 */	stw r29, 0x70(r31)
/* 80084004 00080F64  38 9F 00 20 */	addi r4, r31, 0x20
/* 80084008 00080F68  80 0D 9F E4 */	lwz r0, lbl_803DED04@sda21(r13)
/* 8008400C 00080F6C  90 01 00 F0 */	stw r0, 0xf0(r1)
/* 80084010 00080F70  80 01 00 F0 */	lwz r0, 0xf0(r1)
/* 80084014 00080F74  90 01 00 AC */	stw r0, 0xac(r1)
/* 80084018 00080F78  4B FD AA 69 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8008401C 00080F7C  93 DF 00 7C */	stw r30, 0x7c(r31)
/* 80084020 00080F80  38 A1 00 A8 */	addi r5, r1, 0xa8
/* 80084024 00080F84  38 7F 00 84 */	addi r3, r31, 0x84
/* 80084028 00080F88  93 BF 00 80 */	stw r29, 0x80(r31)
/* 8008402C 00080F8C  38 9F 00 20 */	addi r4, r31, 0x20
/* 80084030 00080F90  80 0D 9F E8 */	lwz r0, lbl_803DED08@sda21(r13)
/* 80084034 00080F94  90 01 00 F8 */	stw r0, 0xf8(r1)
/* 80084038 00080F98  80 01 00 F8 */	lwz r0, 0xf8(r1)
/* 8008403C 00080F9C  90 01 00 A8 */	stw r0, 0xa8(r1)
/* 80084040 00080FA0  4B FD AA 41 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80084044 00080FA4  93 DF 00 8C */	stw r30, 0x8c(r31)
/* 80084048 00080FA8  38 A1 00 A4 */	addi r5, r1, 0xa4
/* 8008404C 00080FAC  38 7F 00 94 */	addi r3, r31, 0x94
/* 80084050 00080FB0  93 BF 00 90 */	stw r29, 0x90(r31)
/* 80084054 00080FB4  38 9F 00 20 */	addi r4, r31, 0x20
/* 80084058 00080FB8  80 0D 9F EC */	lwz r0, lbl_803DED0C@sda21(r13)
/* 8008405C 00080FBC  90 01 01 00 */	stw r0, 0x100(r1)
/* 80084060 00080FC0  80 01 01 00 */	lwz r0, 0x100(r1)
/* 80084064 00080FC4  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 80084068 00080FC8  4B FD AA 19 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8008406C 00080FCC  93 DF 00 9C */	stw r30, 0x9c(r31)
/* 80084070 00080FD0  38 A1 00 A0 */	addi r5, r1, 0xa0
/* 80084074 00080FD4  38 7F 00 A4 */	addi r3, r31, 0xa4
/* 80084078 00080FD8  93 BF 00 A0 */	stw r29, 0xa0(r31)
/* 8008407C 00080FDC  38 9F 00 20 */	addi r4, r31, 0x20
/* 80084080 00080FE0  80 0D 9F F0 */	lwz r0, lbl_803DED10@sda21(r13)
/* 80084084 00080FE4  90 01 01 08 */	stw r0, 0x108(r1)
/* 80084088 00080FE8  80 01 01 08 */	lwz r0, 0x108(r1)
/* 8008408C 00080FEC  90 01 00 A0 */	stw r0, 0xa0(r1)
/* 80084090 00080FF0  4B FD A9 F1 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80084094 00080FF4  93 DF 00 AC */	stw r30, 0xac(r31)
/* 80084098 00080FF8  38 A1 00 9C */	addi r5, r1, 0x9c
/* 8008409C 00080FFC  38 7F 00 B4 */	addi r3, r31, 0xb4
/* 800840A0 00081000  93 BF 00 B0 */	stw r29, 0xb0(r31)
/* 800840A4 00081004  38 9F 00 20 */	addi r4, r31, 0x20
/* 800840A8 00081008  80 0D 9F F4 */	lwz r0, lbl_803DED14@sda21(r13)
/* 800840AC 0008100C  90 01 01 10 */	stw r0, 0x110(r1)
/* 800840B0 00081010  80 01 01 10 */	lwz r0, 0x110(r1)
/* 800840B4 00081014  90 01 00 9C */	stw r0, 0x9c(r1)
/* 800840B8 00081018  4B FD A9 C9 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800840BC 0008101C  93 DF 00 BC */	stw r30, 0xbc(r31)
/* 800840C0 00081020  38 A1 00 98 */	addi r5, r1, 0x98
/* 800840C4 00081024  38 7F 00 C4 */	addi r3, r31, 0xc4
/* 800840C8 00081028  93 BF 00 C0 */	stw r29, 0xc0(r31)
/* 800840CC 0008102C  38 9F 00 20 */	addi r4, r31, 0x20
/* 800840D0 00081030  80 0D 9F F8 */	lwz r0, lbl_803DED18@sda21(r13)
/* 800840D4 00081034  90 01 01 18 */	stw r0, 0x118(r1)
/* 800840D8 00081038  80 01 01 18 */	lwz r0, 0x118(r1)
/* 800840DC 0008103C  90 01 00 98 */	stw r0, 0x98(r1)
/* 800840E0 00081040  4B FD A9 A1 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800840E4 00081044  93 DF 00 CC */	stw r30, 0xcc(r31)
/* 800840E8 00081048  38 A1 00 94 */	addi r5, r1, 0x94
/* 800840EC 0008104C  38 7F 00 D4 */	addi r3, r31, 0xd4
/* 800840F0 00081050  93 BF 00 D0 */	stw r29, 0xd0(r31)
/* 800840F4 00081054  38 9F 00 20 */	addi r4, r31, 0x20
/* 800840F8 00081058  80 0D 9F FC */	lwz r0, lbl_803DED1C@sda21(r13)
/* 800840FC 0008105C  90 01 01 20 */	stw r0, 0x120(r1)
/* 80084100 00081060  80 01 01 20 */	lwz r0, 0x120(r1)
/* 80084104 00081064  90 01 00 94 */	stw r0, 0x94(r1)
/* 80084108 00081068  4B FD A9 79 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8008410C 0008106C  93 9F 00 DC */	stw r28, 0xdc(r31)
/* 80084110 00081070  38 A1 00 90 */	addi r5, r1, 0x90
/* 80084114 00081074  38 7F 00 E4 */	addi r3, r31, 0xe4
/* 80084118 00081078  C0 02 8A 24 */	lfs f0, lbl_803E8C24@sda21(r2)
/* 8008411C 0008107C  38 9F 00 20 */	addi r4, r31, 0x20
/* 80084120 00081080  D0 1F 00 E0 */	stfs f0, 0xe0(r31)
/* 80084124 00081084  80 0D A0 00 */	lwz r0, lbl_803DED20@sda21(r13)
/* 80084128 00081088  90 01 01 28 */	stw r0, 0x128(r1)
/* 8008412C 0008108C  80 01 01 28 */	lwz r0, 0x128(r1)
/* 80084130 00081090  90 01 00 90 */	stw r0, 0x90(r1)
/* 80084134 00081094  4B FD A9 4D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80084138 00081098  93 DF 00 EC */	stw r30, 0xec(r31)
/* 8008413C 0008109C  38 A1 00 8C */	addi r5, r1, 0x8c
/* 80084140 000810A0  38 7F 00 F4 */	addi r3, r31, 0xf4
/* 80084144 000810A4  93 BF 00 F0 */	stw r29, 0xf0(r31)
/* 80084148 000810A8  38 9F 00 20 */	addi r4, r31, 0x20
/* 8008414C 000810AC  80 0D A0 04 */	lwz r0, lbl_803DED24@sda21(r13)
/* 80084150 000810B0  90 01 01 30 */	stw r0, 0x130(r1)
/* 80084154 000810B4  80 01 01 30 */	lwz r0, 0x130(r1)
/* 80084158 000810B8  90 01 00 8C */	stw r0, 0x8c(r1)
/* 8008415C 000810BC  4B FD A9 25 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80084160 000810C0  93 DF 00 FC */	stw r30, 0xfc(r31)
/* 80084164 000810C4  38 A1 00 88 */	addi r5, r1, 0x88
/* 80084168 000810C8  38 7F 01 04 */	addi r3, r31, 0x104
/* 8008416C 000810CC  93 BF 01 00 */	stw r29, 0x100(r31)
/* 80084170 000810D0  38 9F 00 20 */	addi r4, r31, 0x20
/* 80084174 000810D4  80 0D A0 08 */	lwz r0, lbl_803DED28@sda21(r13)
/* 80084178 000810D8  90 01 01 38 */	stw r0, 0x138(r1)
/* 8008417C 000810DC  80 01 01 38 */	lwz r0, 0x138(r1)
/* 80084180 000810E0  90 01 00 88 */	stw r0, 0x88(r1)
/* 80084184 000810E4  4B FD A8 FD */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80084188 000810E8  93 DF 01 0C */	stw r30, 0x10c(r31)
/* 8008418C 000810EC  38 A1 00 84 */	addi r5, r1, 0x84
/* 80084190 000810F0  38 7F 01 14 */	addi r3, r31, 0x114
/* 80084194 000810F4  93 BF 01 10 */	stw r29, 0x110(r31)
/* 80084198 000810F8  38 9F 00 20 */	addi r4, r31, 0x20
/* 8008419C 000810FC  80 0D A0 0C */	lwz r0, lbl_803DED2C@sda21(r13)
/* 800841A0 00081100  90 01 01 40 */	stw r0, 0x140(r1)
/* 800841A4 00081104  80 01 01 40 */	lwz r0, 0x140(r1)
/* 800841A8 00081108  90 01 00 84 */	stw r0, 0x84(r1)
/* 800841AC 0008110C  4B FD A8 D5 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800841B0 00081110  93 DF 01 1C */	stw r30, 0x11c(r31)
/* 800841B4 00081114  38 00 00 64 */	li r0, 0x64
/* 800841B8 00081118  38 A1 00 80 */	addi r5, r1, 0x80
/* 800841BC 0008111C  90 1F 01 20 */	stw r0, 0x120(r31)
/* 800841C0 00081120  38 7F 01 24 */	addi r3, r31, 0x124
/* 800841C4 00081124  38 9F 00 20 */	addi r4, r31, 0x20
/* 800841C8 00081128  80 0D A0 10 */	lwz r0, lbl_803DED30@sda21(r13)
/* 800841CC 0008112C  90 01 01 48 */	stw r0, 0x148(r1)
/* 800841D0 00081130  80 01 01 48 */	lwz r0, 0x148(r1)
/* 800841D4 00081134  90 01 00 80 */	stw r0, 0x80(r1)
/* 800841D8 00081138  4B FD A8 A9 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800841DC 0008113C  93 DF 01 2C */	stw r30, 0x12c(r31)
/* 800841E0 00081140  38 A1 00 7C */	addi r5, r1, 0x7c
/* 800841E4 00081144  38 7F 01 34 */	addi r3, r31, 0x134
/* 800841E8 00081148  93 BF 01 30 */	stw r29, 0x130(r31)
/* 800841EC 0008114C  38 9F 00 20 */	addi r4, r31, 0x20
/* 800841F0 00081150  80 0D A0 14 */	lwz r0, lbl_803DED34@sda21(r13)
/* 800841F4 00081154  90 01 01 50 */	stw r0, 0x150(r1)
/* 800841F8 00081158  80 01 01 50 */	lwz r0, 0x150(r1)
/* 800841FC 0008115C  90 01 00 7C */	stw r0, 0x7c(r1)
/* 80084200 00081160  4B FD A8 81 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80084204 00081164  93 9F 01 3C */	stw r28, 0x13c(r31)
/* 80084208 00081168  38 A1 00 78 */	addi r5, r1, 0x78
/* 8008420C 0008116C  38 7F 01 44 */	addi r3, r31, 0x144
/* 80084210 00081170  C0 02 8A 28 */	lfs f0, lbl_803E8C28@sda21(r2)
/* 80084214 00081174  38 9F 00 20 */	addi r4, r31, 0x20
/* 80084218 00081178  D0 1F 01 40 */	stfs f0, 0x140(r31)
/* 8008421C 0008117C  80 0D A0 18 */	lwz r0, lbl_803DED38@sda21(r13)
/* 80084220 00081180  90 01 01 58 */	stw r0, 0x158(r1)
/* 80084224 00081184  80 01 01 58 */	lwz r0, 0x158(r1)
/* 80084228 00081188  90 01 00 78 */	stw r0, 0x78(r1)
/* 8008422C 0008118C  4B FD A8 55 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80084230 00081190  93 9F 01 4C */	stw r28, 0x14c(r31)
/* 80084234 00081194  38 A1 00 74 */	addi r5, r1, 0x74
/* 80084238 00081198  38 7F 01 54 */	addi r3, r31, 0x154
/* 8008423C 0008119C  C0 02 8A 2C */	lfs f0, lbl_803E8C2C@sda21(r2)
/* 80084240 000811A0  38 9F 00 20 */	addi r4, r31, 0x20
/* 80084244 000811A4  D0 1F 01 50 */	stfs f0, 0x150(r31)
/* 80084248 000811A8  80 0D A0 1C */	lwz r0, lbl_803DED3C@sda21(r13)
/* 8008424C 000811AC  90 01 01 60 */	stw r0, 0x160(r1)
/* 80084250 000811B0  80 01 01 60 */	lwz r0, 0x160(r1)
/* 80084254 000811B4  90 01 00 74 */	stw r0, 0x74(r1)
/* 80084258 000811B8  4B FD A8 29 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8008425C 000811BC  93 DF 01 5C */	stw r30, 0x15c(r31)
/* 80084260 000811C0  38 00 00 06 */	li r0, 6
/* 80084264 000811C4  38 A1 00 70 */	addi r5, r1, 0x70
/* 80084268 000811C8  90 1F 01 60 */	stw r0, 0x160(r31)
/* 8008426C 000811CC  38 7F 01 64 */	addi r3, r31, 0x164
/* 80084270 000811D0  38 9F 00 20 */	addi r4, r31, 0x20
/* 80084274 000811D4  80 0D A0 20 */	lwz r0, lbl_803DED40@sda21(r13)
/* 80084278 000811D8  90 01 01 68 */	stw r0, 0x168(r1)
/* 8008427C 000811DC  80 01 01 68 */	lwz r0, 0x168(r1)
/* 80084280 000811E0  90 01 00 70 */	stw r0, 0x70(r1)
/* 80084284 000811E4  4B FD A7 FD */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80084288 000811E8  93 DF 01 6C */	stw r30, 0x16c(r31)
/* 8008428C 000811EC  38 00 00 0C */	li r0, 0xc
/* 80084290 000811F0  38 A1 00 6C */	addi r5, r1, 0x6c
/* 80084294 000811F4  90 1F 01 70 */	stw r0, 0x170(r31)
/* 80084298 000811F8  38 7F 01 74 */	addi r3, r31, 0x174
/* 8008429C 000811FC  38 9F 00 20 */	addi r4, r31, 0x20
/* 800842A0 00081200  80 0D A0 24 */	lwz r0, lbl_803DED44@sda21(r13)
/* 800842A4 00081204  90 01 01 70 */	stw r0, 0x170(r1)
/* 800842A8 00081208  80 01 01 70 */	lwz r0, 0x170(r1)
/* 800842AC 0008120C  90 01 00 6C */	stw r0, 0x6c(r1)
/* 800842B0 00081210  4B FD A7 D1 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800842B4 00081214  93 DF 01 7C */	stw r30, 0x17c(r31)
/* 800842B8 00081218  38 00 00 1D */	li r0, 0x1d
/* 800842BC 0008121C  38 A1 00 68 */	addi r5, r1, 0x68
/* 800842C0 00081220  90 1F 01 80 */	stw r0, 0x180(r31)
/* 800842C4 00081224  38 7F 01 84 */	addi r3, r31, 0x184
/* 800842C8 00081228  38 9F 00 20 */	addi r4, r31, 0x20
/* 800842CC 0008122C  80 0D A0 28 */	lwz r0, lbl_803DED48@sda21(r13)
/* 800842D0 00081230  90 01 01 78 */	stw r0, 0x178(r1)
/* 800842D4 00081234  80 01 01 78 */	lwz r0, 0x178(r1)
/* 800842D8 00081238  90 01 00 68 */	stw r0, 0x68(r1)
/* 800842DC 0008123C  4B FD A7 A5 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800842E0 00081240  93 DF 01 8C */	stw r30, 0x18c(r31)
/* 800842E4 00081244  38 00 00 1E */	li r0, 0x1e
/* 800842E8 00081248  3C 60 80 2B */	lis r3, lbl_802AE6D0@ha
/* 800842EC 0008124C  90 1F 01 90 */	stw r0, 0x190(r31)
/* 800842F0 00081250  38 A3 E6 D0 */	addi r5, r3, lbl_802AE6D0@l
/* 800842F4 00081254  38 7F 00 00 */	addi r3, r31, 0
/* 800842F8 00081258  38 8D A0 2C */	addi r4, r13, lbl_803DED4C@sda21
/* 800842FC 0008125C  38 C0 00 01 */	li r6, 1
/* 80084300 00081260  4B FB C3 A1 */	bl load__8CoreNodeFPcPcUl
/* 80084304 00081264  7F E3 FB 78 */	mr r3, r31
/* 80084308 00081268  BB 61 01 84 */	lmw r27, 0x184(r1)
/* 8008430C 0008126C  80 01 01 9C */	lwz r0, 0x19c(r1)
/* 80084310 00081270  38 21 01 98 */	addi r1, r1, 0x198
/* 80084314 00081274  7C 08 03 A6 */	mtlr r0
/* 80084318 00081278  4E 80 00 20 */	blr 

.global read__10AIConstantFR18RandomAccessStream
read__10AIConstantFR18RandomAccessStream:
/* 8008431C 0008127C  7C 08 02 A6 */	mflr r0
/* 80084320 00081280  38 63 00 20 */	addi r3, r3, 0x20
/* 80084324 00081284  90 01 00 04 */	stw r0, 4(r1)
/* 80084328 00081288  94 21 FF F8 */	stwu r1, -8(r1)
/* 8008432C 0008128C  4B FD A8 6D */	bl read__10ParametersFR18RandomAccessStream
/* 80084330 00081290  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80084334 00081294  38 21 00 08 */	addi r1, r1, 8
/* 80084338 00081298  7C 08 03 A6 */	mtlr r0
/* 8008433C 0008129C  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802AE6C0:
	.asciz "aiConstants.cpp"
.balign 4
lbl_802AE6D0:
	.asciz "aiconst.bin"
.balign 4
lbl_802AE6DC:
	.asciz "Parm<int>"
.balign 4
lbl_802AE6E8:
	.asciz "BaseParm"
.balign 4
lbl_802AE6F4:
	.4byte __RTTI__8BaseParm
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
lbl_802AE714:
	.asciz "Parm<float>"
.balign 4
lbl_802AE720:
	.4byte __RTTI__8BaseParm
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
lbl_802AE740:
	.asciz "AIConstant"
.balign 4
lbl_802AE74C:
	.asciz "CoreNode"
.balign 4
lbl_802AE758:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802AE764:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802AE778:
	.4byte __RTTI__5ANode
	.4byte 0x00000000
	.4byte __RTTI__8CoreNode
	.4byte 0x00000000
	.4byte __RTTI__4Node
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__10AIConstant
__vt__10AIConstant:
	.4byte __RTTI__10AIConstant
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__10AIConstantFR18RandomAccessStream
	.4byte update__4NodeFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DECE8:
	.asciz "<Node>"
.balign 4
lbl_803DECF0:
	.asciz "p00"
.balign 4
lbl_803DECF4:
	.asciz "p01"
.balign 4
lbl_803DECF8:
	.asciz "p02"
.balign 4
lbl_803DECFC:
	.asciz "p03"
.balign 4
lbl_803DED00:
	.asciz "p04"
.balign 4
lbl_803DED04:
	.asciz "p05"
.balign 4
lbl_803DED08:
	.asciz "p07"
.balign 4
lbl_803DED0C:
	.asciz "p06"
.balign 4
lbl_803DED10:
	.asciz "p08"
.balign 4
lbl_803DED14:
	.asciz "p09"
.balign 4
lbl_803DED18:
	.asciz "p10"
.balign 4
lbl_803DED1C:
	.asciz "p11"
.balign 4
lbl_803DED20:
	.asciz "p12"
.balign 4
lbl_803DED24:
	.asciz "p13"
.balign 4
lbl_803DED28:
	.asciz "p14"
.balign 4
lbl_803DED2C:
	.asciz "p15"
.balign 4
lbl_803DED30:
	.asciz "p16"
.balign 4
lbl_803DED34:
	.asciz "p17"
.balign 4
lbl_803DED38:
	.asciz "p18"
.balign 4
lbl_803DED3C:
	.asciz "p19"
.balign 4
lbl_803DED40:
	.asciz "p20"
.balign 4
lbl_803DED44:
	.asciz "p21"
.balign 4
lbl_803DED48:
	.asciz "p22"
.balign 4
lbl_803DED4C:
	.asciz "parms/"
.balign 4
__RTTI__8BaseParm:
	.4byte lbl_802AE6E8
	.4byte 0
.balign 4
lbl_803DED5C:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803DED5C
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_802AE74C
	.4byte lbl_802AE758
.balign 4
lbl_803DED74:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803DED74
	.4byte lbl_802AE764
__RTTI__10AIConstant:
	.4byte lbl_802AE740
	.4byte lbl_802AE778

.section .sbss, "wa"
.balign 8
.global _instance__10AIConstant
_instance__10AIConstant:
	.skip 4

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E8C20:
	.float 550.0
lbl_803E8C24:
	.float 90.0
lbl_803E8C28:
	.float 1.0
lbl_803E8C2C:
	.float 2.5
