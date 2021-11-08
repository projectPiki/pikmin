.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80124A0C 0012196C  93 7C 00 08 */	stw r27, 8(r28)
/* 80124A10 00121970  4B F0 04 C5 */	bl setName__8CoreNodeFPc
/* 80124A14 00121974  3C 60 80 23 */	lis r3, __vt__4Node@ha
/* 80124A18 00121978  38 03 8E 20 */	addi r0, r3, __vt__4Node@l
/* 80124A1C 0012197C  90 1C 00 00 */	stw r0, 0(r28)
/* 80124A20 00121980  38 7C 00 00 */	addi r3, r28, 0
/* 80124A24 00121984  38 8D E5 B8 */	addi r4, r13, lbl_803E32D8@sda21
/* 80124A28 00121988  4B F1 BD 15 */	bl init__4NodeFPc
/* 80124A2C 0012198C  3C 60 80 2C */	lis r3, __vt__20PcamCameraParameters@ha
/* 80124A30 00121990  38 03 5B 30 */	addi r0, r3, __vt__20PcamCameraParameters@l
/* 80124A34 00121994  90 1C 00 00 */	stw r0, 0(r28)
/* 80124A38 00121998  38 60 00 14 */	li r3, 0x14
/* 80124A3C 0012199C  4B F2 25 C9 */	bl alloc__6SystemFUl
/* 80124A40 001219A0  3C 80 80 12 */	lis r4, __ct__18ParaParameterInfoIFv@ha
/* 80124A44 001219A4  38 84 54 54 */	addi r4, r4, __ct__18ParaParameterInfoIFv@l
/* 80124A48 001219A8  38 A0 00 00 */	li r5, 0
/* 80124A4C 001219AC  38 C0 00 0C */	li r6, 0xc
/* 80124A50 001219B0  38 E0 00 01 */	li r7, 1
/* 80124A54 001219B4  48 0F 01 D5 */	bl __construct_new_array
/* 80124A58 001219B8  38 00 00 00 */	li r0, 0
/* 80124A5C 001219BC  1F A0 00 0C */	mulli r29, r0, 0xc
/* 80124A60 001219C0  7C 83 EA 14 */	add r4, r3, r29
/* 80124A64 001219C4  38 1F 00 34 */	addi r0, r31, 0x34
/* 80124A68 001219C8  90 04 00 00 */	stw r0, 0(r4)
/* 80124A6C 001219CC  3B C3 00 00 */	addi r30, r3, 0
/* 80124A70 001219D0  38 00 00 01 */	li r0, 1
/* 80124A74 001219D4  93 64 00 04 */	stw r27, 4(r4)
/* 80124A78 001219D8  38 60 02 9C */	li r3, 0x29c
/* 80124A7C 001219DC  90 04 00 08 */	stw r0, 8(r4)
/* 80124A80 001219E0  4B F2 25 85 */	bl alloc__6SystemFUl
/* 80124A84 001219E4  3C 80 80 12 */	lis r4, __ct__18ParaParameterInfoFFv@ha
/* 80124A88 001219E8  38 84 54 3C */	addi r4, r4, __ct__18ParaParameterInfoFFv@l
/* 80124A8C 001219EC  38 A0 00 00 */	li r5, 0
/* 80124A90 001219F0  38 C0 00 0C */	li r6, 0xc
/* 80124A94 001219F4  38 E0 00 37 */	li r7, 0x37
/* 80124A98 001219F8  48 0F 01 91 */	bl __construct_new_array
/* 80124A9C 001219FC  7C C3 EA 14 */	add r6, r3, r29
/* 80124AA0 00121A00  38 1F 00 44 */	addi r0, r31, 0x44
/* 80124AA4 00121A04  90 06 00 00 */	stw r0, 0(r6)
/* 80124AA8 00121A08  38 00 00 01 */	li r0, 1
/* 80124AAC 00121A0C  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124AB0 00121A10  C1 02 A1 50 */	lfs f8, lbl_803EA350@sda21(r2)
/* 80124AB4 00121A14  D1 06 00 04 */	stfs f8, 4(r6)
/* 80124AB8 00121A18  38 00 00 02 */	li r0, 2
/* 80124ABC 00121A1C  1C A0 00 0C */	mulli r5, r0, 0xc
/* 80124AC0 00121A20  C0 E2 A1 54 */	lfs f7, lbl_803EA354@sda21(r2)
/* 80124AC4 00121A24  D0 E6 00 08 */	stfs f7, 8(r6)
/* 80124AC8 00121A28  7C C3 22 14 */	add r6, r3, r4
/* 80124ACC 00121A2C  38 1F 00 58 */	addi r0, r31, 0x58
/* 80124AD0 00121A30  90 06 00 00 */	stw r0, 0(r6)
/* 80124AD4 00121A34  38 00 00 03 */	li r0, 3
/* 80124AD8 00121A38  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124ADC 00121A3C  C0 C2 A1 58 */	lfs f6, lbl_803EA358@sda21(r2)
/* 80124AE0 00121A40  D0 C6 00 04 */	stfs f6, 4(r6)
/* 80124AE4 00121A44  38 00 00 04 */	li r0, 4
/* 80124AE8 00121A48  1D 00 00 0C */	mulli r8, r0, 0xc
/* 80124AEC 00121A4C  C0 A2 A1 5C */	lfs f5, lbl_803EA35C@sda21(r2)
/* 80124AF0 00121A50  D0 A6 00 08 */	stfs f5, 8(r6)
/* 80124AF4 00121A54  7C A3 2A 14 */	add r5, r3, r5
/* 80124AF8 00121A58  38 1F 00 68 */	addi r0, r31, 0x68
/* 80124AFC 00121A5C  90 05 00 00 */	stw r0, 0(r5)
/* 80124B00 00121A60  38 00 00 05 */	li r0, 5
/* 80124B04 00121A64  1C E0 00 0C */	mulli r7, r0, 0xc
/* 80124B08 00121A68  D1 05 00 04 */	stfs f8, 4(r5)
/* 80124B0C 00121A6C  C0 82 A1 60 */	lfs f4, lbl_803EA360@sda21(r2)
/* 80124B10 00121A70  38 00 00 06 */	li r0, 6
/* 80124B14 00121A74  1C C0 00 0C */	mulli r6, r0, 0xc
/* 80124B18 00121A78  D0 85 00 08 */	stfs f4, 8(r5)
/* 80124B1C 00121A7C  7D 23 22 14 */	add r9, r3, r4
/* 80124B20 00121A80  38 1F 00 78 */	addi r0, r31, 0x78
/* 80124B24 00121A84  90 09 00 00 */	stw r0, 0(r9)
/* 80124B28 00121A88  38 00 00 07 */	li r0, 7
/* 80124B2C 00121A8C  1C A0 00 0C */	mulli r5, r0, 0xc
/* 80124B30 00121A90  C0 62 A1 64 */	lfs f3, lbl_803EA364@sda21(r2)
/* 80124B34 00121A94  D0 69 00 04 */	stfs f3, 4(r9)
/* 80124B38 00121A98  38 00 00 08 */	li r0, 8
/* 80124B3C 00121A9C  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124B40 00121AA0  C0 42 A1 68 */	lfs f2, lbl_803EA368@sda21(r2)
/* 80124B44 00121AA4  D0 49 00 08 */	stfs f2, 8(r9)
/* 80124B48 00121AA8  7D 03 42 14 */	add r8, r3, r8
/* 80124B4C 00121AAC  38 1F 00 94 */	addi r0, r31, 0x94
/* 80124B50 00121AB0  90 08 00 00 */	stw r0, 0(r8)
/* 80124B54 00121AB4  7D 23 3A 14 */	add r9, r3, r7
/* 80124B58 00121AB8  7D 43 22 14 */	add r10, r3, r4
/* 80124B5C 00121ABC  D0 C8 00 04 */	stfs f6, 4(r8)
/* 80124B60 00121AC0  38 00 00 09 */	li r0, 9
/* 80124B64 00121AC4  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124B68 00121AC8  C0 22 A1 6C */	lfs f1, lbl_803EA36C@sda21(r2)
/* 80124B6C 00121ACC  D0 28 00 08 */	stfs f1, 8(r8)
/* 80124B70 00121AD0  38 FF 00 B0 */	addi r7, r31, 0xb0
/* 80124B74 00121AD4  7D 03 32 14 */	add r8, r3, r6
/* 80124B78 00121AD8  90 E9 00 00 */	stw r7, 0(r9)
/* 80124B7C 00121ADC  7C E3 2A 14 */	add r7, r3, r5
/* 80124B80 00121AE0  7D 63 02 14 */	add r11, r3, r0
/* 80124B84 00121AE4  D0 C9 00 04 */	stfs f6, 4(r9)
/* 80124B88 00121AE8  38 DF 00 C0 */	addi r6, r31, 0xc0
/* 80124B8C 00121AEC  38 BF 00 D4 */	addi r5, r31, 0xd4
/* 80124B90 00121AF0  C0 02 A1 70 */	lfs f0, lbl_803EA370@sda21(r2)
/* 80124B94 00121AF4  38 9F 00 E8 */	addi r4, r31, 0xe8
/* 80124B98 00121AF8  38 1F 00 F8 */	addi r0, r31, 0xf8
/* 80124B9C 00121AFC  D0 09 00 08 */	stfs f0, 8(r9)
/* 80124BA0 00121B00  7C 7D 1B 78 */	mr r29, r3
/* 80124BA4 00121B04  90 C8 00 00 */	stw r6, 0(r8)
/* 80124BA8 00121B08  D1 08 00 04 */	stfs f8, 4(r8)
/* 80124BAC 00121B0C  D0 E8 00 08 */	stfs f7, 8(r8)
/* 80124BB0 00121B10  90 A7 00 00 */	stw r5, 0(r7)
/* 80124BB4 00121B14  D0 C7 00 04 */	stfs f6, 4(r7)
/* 80124BB8 00121B18  D0 A7 00 08 */	stfs f5, 8(r7)
/* 80124BBC 00121B1C  90 8A 00 00 */	stw r4, 0(r10)
/* 80124BC0 00121B20  D1 0A 00 04 */	stfs f8, 4(r10)
/* 80124BC4 00121B24  D0 8A 00 08 */	stfs f4, 8(r10)
/* 80124BC8 00121B28  90 0B 00 00 */	stw r0, 0(r11)
/* 80124BCC 00121B2C  D0 6B 00 04 */	stfs f3, 4(r11)
/* 80124BD0 00121B30  38 00 00 0A */	li r0, 0xa
/* 80124BD4 00121B34  D0 4B 00 08 */	stfs f2, 8(r11)
/* 80124BD8 00121B38  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124BDC 00121B3C  7C 83 02 14 */	add r4, r3, r0
/* 80124BE0 00121B40  38 1F 01 14 */	addi r0, r31, 0x114
/* 80124BE4 00121B44  90 04 00 00 */	stw r0, 0(r4)
/* 80124BE8 00121B48  38 00 00 0B */	li r0, 0xb
/* 80124BEC 00121B4C  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124BF0 00121B50  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124BF4 00121B54  D0 24 00 08 */	stfs f1, 8(r4)
/* 80124BF8 00121B58  7C 83 02 14 */	add r4, r3, r0
/* 80124BFC 00121B5C  38 1F 01 34 */	addi r0, r31, 0x134
/* 80124C00 00121B60  90 04 00 00 */	stw r0, 0(r4)
/* 80124C04 00121B64  38 00 00 0C */	li r0, 0xc
/* 80124C08 00121B68  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124C0C 00121B6C  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124C10 00121B70  D0 04 00 08 */	stfs f0, 8(r4)
/* 80124C14 00121B74  7C 83 02 14 */	add r4, r3, r0
/* 80124C18 00121B78  38 1F 01 44 */	addi r0, r31, 0x144
/* 80124C1C 00121B7C  90 04 00 00 */	stw r0, 0(r4)
/* 80124C20 00121B80  38 00 00 0D */	li r0, 0xd
/* 80124C24 00121B84  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124C28 00121B88  D1 04 00 04 */	stfs f8, 4(r4)
/* 80124C2C 00121B8C  D0 E4 00 08 */	stfs f7, 8(r4)
/* 80124C30 00121B90  7C 83 02 14 */	add r4, r3, r0
/* 80124C34 00121B94  38 1F 01 58 */	addi r0, r31, 0x158
/* 80124C38 00121B98  90 04 00 00 */	stw r0, 0(r4)
/* 80124C3C 00121B9C  38 00 00 0E */	li r0, 0xe
/* 80124C40 00121BA0  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124C44 00121BA4  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124C48 00121BA8  D0 A4 00 08 */	stfs f5, 8(r4)
/* 80124C4C 00121BAC  7C 83 02 14 */	add r4, r3, r0
/* 80124C50 00121BB0  38 1F 01 68 */	addi r0, r31, 0x168
/* 80124C54 00121BB4  90 04 00 00 */	stw r0, 0(r4)
/* 80124C58 00121BB8  38 00 00 0F */	li r0, 0xf
/* 80124C5C 00121BBC  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124C60 00121BC0  D1 04 00 04 */	stfs f8, 4(r4)
/* 80124C64 00121BC4  D0 84 00 08 */	stfs f4, 8(r4)
/* 80124C68 00121BC8  7C 83 02 14 */	add r4, r3, r0
/* 80124C6C 00121BCC  38 1F 01 74 */	addi r0, r31, 0x174
/* 80124C70 00121BD0  90 04 00 00 */	stw r0, 0(r4)
/* 80124C74 00121BD4  38 00 00 10 */	li r0, 0x10
/* 80124C78 00121BD8  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124C7C 00121BDC  D0 64 00 04 */	stfs f3, 4(r4)
/* 80124C80 00121BE0  D0 44 00 08 */	stfs f2, 8(r4)
/* 80124C84 00121BE4  7C 83 02 14 */	add r4, r3, r0
/* 80124C88 00121BE8  38 1F 01 90 */	addi r0, r31, 0x190
/* 80124C8C 00121BEC  90 04 00 00 */	stw r0, 0(r4)
/* 80124C90 00121BF0  38 00 00 11 */	li r0, 0x11
/* 80124C94 00121BF4  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124C98 00121BF8  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124C9C 00121BFC  D0 24 00 08 */	stfs f1, 8(r4)
/* 80124CA0 00121C00  7C 83 02 14 */	add r4, r3, r0
/* 80124CA4 00121C04  38 1F 01 AC */	addi r0, r31, 0x1ac
/* 80124CA8 00121C08  90 04 00 00 */	stw r0, 0(r4)
/* 80124CAC 00121C0C  38 00 00 12 */	li r0, 0x12
/* 80124CB0 00121C10  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124CB4 00121C14  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124CB8 00121C18  D0 04 00 08 */	stfs f0, 8(r4)
/* 80124CBC 00121C1C  7C 83 02 14 */	add r4, r3, r0
/* 80124CC0 00121C20  38 1F 01 BC */	addi r0, r31, 0x1bc
/* 80124CC4 00121C24  90 04 00 00 */	stw r0, 0(r4)
/* 80124CC8 00121C28  38 00 00 13 */	li r0, 0x13
/* 80124CCC 00121C2C  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124CD0 00121C30  D1 04 00 04 */	stfs f8, 4(r4)
/* 80124CD4 00121C34  D0 E4 00 08 */	stfs f7, 8(r4)
/* 80124CD8 00121C38  7C 83 02 14 */	add r4, r3, r0
/* 80124CDC 00121C3C  38 1F 01 D0 */	addi r0, r31, 0x1d0
/* 80124CE0 00121C40  90 04 00 00 */	stw r0, 0(r4)
/* 80124CE4 00121C44  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124CE8 00121C48  D0 A4 00 08 */	stfs f5, 8(r4)
/* 80124CEC 00121C4C  38 00 00 14 */	li r0, 0x14
/* 80124CF0 00121C50  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124CF4 00121C54  7C 83 02 14 */	add r4, r3, r0
/* 80124CF8 00121C58  38 1F 01 E0 */	addi r0, r31, 0x1e0
/* 80124CFC 00121C5C  90 04 00 00 */	stw r0, 0(r4)
/* 80124D00 00121C60  38 00 00 15 */	li r0, 0x15
/* 80124D04 00121C64  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124D08 00121C68  D1 04 00 04 */	stfs f8, 4(r4)
/* 80124D0C 00121C6C  D0 84 00 08 */	stfs f4, 8(r4)
/* 80124D10 00121C70  7C 83 02 14 */	add r4, r3, r0
/* 80124D14 00121C74  38 1F 01 F0 */	addi r0, r31, 0x1f0
/* 80124D18 00121C78  90 04 00 00 */	stw r0, 0(r4)
/* 80124D1C 00121C7C  38 00 00 16 */	li r0, 0x16
/* 80124D20 00121C80  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124D24 00121C84  D0 64 00 04 */	stfs f3, 4(r4)
/* 80124D28 00121C88  D0 44 00 08 */	stfs f2, 8(r4)
/* 80124D2C 00121C8C  7C 83 02 14 */	add r4, r3, r0
/* 80124D30 00121C90  38 1F 02 0C */	addi r0, r31, 0x20c
/* 80124D34 00121C94  90 04 00 00 */	stw r0, 0(r4)
/* 80124D38 00121C98  38 00 00 17 */	li r0, 0x17
/* 80124D3C 00121C9C  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124D40 00121CA0  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124D44 00121CA4  D0 24 00 08 */	stfs f1, 8(r4)
/* 80124D48 00121CA8  7C 83 02 14 */	add r4, r3, r0
/* 80124D4C 00121CAC  38 1F 02 28 */	addi r0, r31, 0x228
/* 80124D50 00121CB0  90 04 00 00 */	stw r0, 0(r4)
/* 80124D54 00121CB4  38 00 00 18 */	li r0, 0x18
/* 80124D58 00121CB8  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124D5C 00121CBC  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124D60 00121CC0  D0 04 00 08 */	stfs f0, 8(r4)
/* 80124D64 00121CC4  7C 83 02 14 */	add r4, r3, r0
/* 80124D68 00121CC8  38 1F 02 38 */	addi r0, r31, 0x238
/* 80124D6C 00121CCC  90 04 00 00 */	stw r0, 0(r4)
/* 80124D70 00121CD0  38 00 00 19 */	li r0, 0x19
/* 80124D74 00121CD4  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124D78 00121CD8  D1 04 00 04 */	stfs f8, 4(r4)
/* 80124D7C 00121CDC  D0 E4 00 08 */	stfs f7, 8(r4)
/* 80124D80 00121CE0  7C 83 02 14 */	add r4, r3, r0
/* 80124D84 00121CE4  38 1F 02 50 */	addi r0, r31, 0x250
/* 80124D88 00121CE8  90 04 00 00 */	stw r0, 0(r4)
/* 80124D8C 00121CEC  38 00 00 1A */	li r0, 0x1a
/* 80124D90 00121CF0  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124D94 00121CF4  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124D98 00121CF8  D0 A4 00 08 */	stfs f5, 8(r4)
/* 80124D9C 00121CFC  7C 83 02 14 */	add r4, r3, r0
/* 80124DA0 00121D00  38 1F 02 64 */	addi r0, r31, 0x264
/* 80124DA4 00121D04  90 04 00 00 */	stw r0, 0(r4)
/* 80124DA8 00121D08  38 00 00 1B */	li r0, 0x1b
/* 80124DAC 00121D0C  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124DB0 00121D10  D1 04 00 04 */	stfs f8, 4(r4)
/* 80124DB4 00121D14  D0 84 00 08 */	stfs f4, 8(r4)
/* 80124DB8 00121D18  7C 83 02 14 */	add r4, r3, r0
/* 80124DBC 00121D1C  38 1F 02 74 */	addi r0, r31, 0x274
/* 80124DC0 00121D20  90 04 00 00 */	stw r0, 0(r4)
/* 80124DC4 00121D24  38 00 00 1C */	li r0, 0x1c
/* 80124DC8 00121D28  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124DCC 00121D2C  D0 64 00 04 */	stfs f3, 4(r4)
/* 80124DD0 00121D30  D0 44 00 08 */	stfs f2, 8(r4)
/* 80124DD4 00121D34  7C 83 02 14 */	add r4, r3, r0
/* 80124DD8 00121D38  38 1F 02 94 */	addi r0, r31, 0x294
/* 80124DDC 00121D3C  90 04 00 00 */	stw r0, 0(r4)
/* 80124DE0 00121D40  38 00 00 1D */	li r0, 0x1d
/* 80124DE4 00121D44  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124DE8 00121D48  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124DEC 00121D4C  D0 24 00 08 */	stfs f1, 8(r4)
/* 80124DF0 00121D50  7C 83 02 14 */	add r4, r3, r0
/* 80124DF4 00121D54  38 1F 02 B4 */	addi r0, r31, 0x2b4
/* 80124DF8 00121D58  90 04 00 00 */	stw r0, 0(r4)
/* 80124DFC 00121D5C  38 00 00 1E */	li r0, 0x1e
/* 80124E00 00121D60  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124E04 00121D64  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124E08 00121D68  D0 04 00 08 */	stfs f0, 8(r4)
/* 80124E0C 00121D6C  7C A3 02 14 */	add r5, r3, r0
/* 80124E10 00121D70  38 1F 02 C8 */	addi r0, r31, 0x2c8
/* 80124E14 00121D74  90 05 00 00 */	stw r0, 0(r5)
/* 80124E18 00121D78  38 00 00 1F */	li r0, 0x1f
/* 80124E1C 00121D7C  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124E20 00121D80  D1 05 00 04 */	stfs f8, 4(r5)
/* 80124E24 00121D84  D0 E5 00 08 */	stfs f7, 8(r5)
/* 80124E28 00121D88  38 00 00 20 */	li r0, 0x20
/* 80124E2C 00121D8C  7C A3 22 14 */	add r5, r3, r4
/* 80124E30 00121D90  38 9F 02 DC */	addi r4, r31, 0x2dc
/* 80124E34 00121D94  90 85 00 00 */	stw r4, 0(r5)
/* 80124E38 00121D98  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124E3C 00121D9C  D0 C5 00 04 */	stfs f6, 4(r5)
/* 80124E40 00121DA0  38 00 00 21 */	li r0, 0x21
/* 80124E44 00121DA4  D0 A5 00 08 */	stfs f5, 8(r5)
/* 80124E48 00121DA8  7C A3 22 14 */	add r5, r3, r4
/* 80124E4C 00121DAC  38 9F 02 EC */	addi r4, r31, 0x2ec
/* 80124E50 00121DB0  90 85 00 00 */	stw r4, 0(r5)
/* 80124E54 00121DB4  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124E58 00121DB8  D1 05 00 04 */	stfs f8, 4(r5)
/* 80124E5C 00121DBC  38 00 00 22 */	li r0, 0x22
/* 80124E60 00121DC0  D0 85 00 08 */	stfs f4, 8(r5)
/* 80124E64 00121DC4  7C A3 22 14 */	add r5, r3, r4
/* 80124E68 00121DC8  38 9F 02 FC */	addi r4, r31, 0x2fc
/* 80124E6C 00121DCC  90 85 00 00 */	stw r4, 0(r5)
/* 80124E70 00121DD0  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124E74 00121DD4  D0 65 00 04 */	stfs f3, 4(r5)
/* 80124E78 00121DD8  38 00 00 23 */	li r0, 0x23
/* 80124E7C 00121DDC  D0 45 00 08 */	stfs f2, 8(r5)
/* 80124E80 00121DE0  7C A3 22 14 */	add r5, r3, r4
/* 80124E84 00121DE4  38 9F 03 18 */	addi r4, r31, 0x318
/* 80124E88 00121DE8  90 85 00 00 */	stw r4, 0(r5)
/* 80124E8C 00121DEC  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124E90 00121DF0  D0 C5 00 04 */	stfs f6, 4(r5)
/* 80124E94 00121DF4  38 00 00 24 */	li r0, 0x24
/* 80124E98 00121DF8  D0 25 00 08 */	stfs f1, 8(r5)
/* 80124E9C 00121DFC  7C A3 22 14 */	add r5, r3, r4
/* 80124EA0 00121E00  38 9F 03 34 */	addi r4, r31, 0x334
/* 80124EA4 00121E04  90 85 00 00 */	stw r4, 0(r5)
/* 80124EA8 00121E08  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124EAC 00121E0C  D0 C5 00 04 */	stfs f6, 4(r5)
/* 80124EB0 00121E10  38 00 00 25 */	li r0, 0x25
/* 80124EB4 00121E14  D0 05 00 08 */	stfs f0, 8(r5)
/* 80124EB8 00121E18  7C A3 22 14 */	add r5, r3, r4
/* 80124EBC 00121E1C  38 9F 03 44 */	addi r4, r31, 0x344
/* 80124EC0 00121E20  90 85 00 00 */	stw r4, 0(r5)
/* 80124EC4 00121E24  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124EC8 00121E28  D1 05 00 04 */	stfs f8, 4(r5)
/* 80124ECC 00121E2C  38 00 00 26 */	li r0, 0x26
/* 80124ED0 00121E30  D0 E5 00 08 */	stfs f7, 8(r5)
/* 80124ED4 00121E34  7C A3 22 14 */	add r5, r3, r4
/* 80124ED8 00121E38  38 9F 03 5C */	addi r4, r31, 0x35c
/* 80124EDC 00121E3C  90 85 00 00 */	stw r4, 0(r5)
/* 80124EE0 00121E40  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124EE4 00121E44  D0 C5 00 04 */	stfs f6, 4(r5)
/* 80124EE8 00121E48  38 00 00 27 */	li r0, 0x27
/* 80124EEC 00121E4C  D0 A5 00 08 */	stfs f5, 8(r5)
/* 80124EF0 00121E50  7C A3 22 14 */	add r5, r3, r4
/* 80124EF4 00121E54  38 9F 03 74 */	addi r4, r31, 0x374
/* 80124EF8 00121E58  90 85 00 00 */	stw r4, 0(r5)
/* 80124EFC 00121E5C  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124F00 00121E60  D1 05 00 04 */	stfs f8, 4(r5)
/* 80124F04 00121E64  38 00 00 28 */	li r0, 0x28
/* 80124F08 00121E68  D0 85 00 08 */	stfs f4, 8(r5)
/* 80124F0C 00121E6C  7C A3 22 14 */	add r5, r3, r4
/* 80124F10 00121E70  38 9F 03 88 */	addi r4, r31, 0x388
/* 80124F14 00121E74  90 85 00 00 */	stw r4, 0(r5)
/* 80124F18 00121E78  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124F1C 00121E7C  D0 65 00 04 */	stfs f3, 4(r5)
/* 80124F20 00121E80  7C 83 02 14 */	add r4, r3, r0
/* 80124F24 00121E84  D0 45 00 08 */	stfs f2, 8(r5)
/* 80124F28 00121E88  38 1F 03 A8 */	addi r0, r31, 0x3a8
/* 80124F2C 00121E8C  90 04 00 00 */	stw r0, 0(r4)
/* 80124F30 00121E90  38 00 00 29 */	li r0, 0x29
/* 80124F34 00121E94  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124F38 00121E98  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124F3C 00121E9C  D0 24 00 08 */	stfs f1, 8(r4)
/* 80124F40 00121EA0  7C 83 02 14 */	add r4, r3, r0
/* 80124F44 00121EA4  38 1F 03 CC */	addi r0, r31, 0x3cc
/* 80124F48 00121EA8  90 04 00 00 */	stw r0, 0(r4)
/* 80124F4C 00121EAC  38 00 00 2A */	li r0, 0x2a
/* 80124F50 00121EB0  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80124F54 00121EB4  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80124F58 00121EB8  D0 04 00 08 */	stfs f0, 8(r4)
/* 80124F5C 00121EBC  7C C3 02 14 */	add r6, r3, r0
/* 80124F60 00121EC0  38 1F 03 E0 */	addi r0, r31, 0x3e0
/* 80124F64 00121EC4  90 06 00 00 */	stw r0, 0(r6)
/* 80124F68 00121EC8  38 00 00 2B */	li r0, 0x2b
/* 80124F6C 00121ECC  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124F70 00121ED0  C0 02 A1 74 */	lfs f0, lbl_803EA374@sda21(r2)
/* 80124F74 00121ED4  D0 06 00 04 */	stfs f0, 4(r6)
/* 80124F78 00121ED8  38 00 00 2C */	li r0, 0x2c
/* 80124F7C 00121EDC  1C A0 00 0C */	mulli r5, r0, 0xc
/* 80124F80 00121EE0  C0 42 A1 78 */	lfs f2, lbl_803EA378@sda21(r2)
/* 80124F84 00121EE4  D0 46 00 08 */	stfs f2, 8(r6)
/* 80124F88 00121EE8  7C C3 22 14 */	add r6, r3, r4
/* 80124F8C 00121EEC  38 1F 03 F0 */	addi r0, r31, 0x3f0
/* 80124F90 00121EF0  90 06 00 00 */	stw r0, 0(r6)
/* 80124F94 00121EF4  38 00 00 2D */	li r0, 0x2d
/* 80124F98 00121EF8  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124F9C 00121EFC  D0 06 00 04 */	stfs f0, 4(r6)
/* 80124FA0 00121F00  D0 46 00 08 */	stfs f2, 8(r6)
/* 80124FA4 00121F04  7C C3 2A 14 */	add r6, r3, r5
/* 80124FA8 00121F08  38 1F 04 04 */	addi r0, r31, 0x404
/* 80124FAC 00121F0C  90 06 00 00 */	stw r0, 0(r6)
/* 80124FB0 00121F10  38 00 00 2E */	li r0, 0x2e
/* 80124FB4 00121F14  1C A0 00 0C */	mulli r5, r0, 0xc
/* 80124FB8 00121F18  D0 C6 00 04 */	stfs f6, 4(r6)
/* 80124FBC 00121F1C  D1 06 00 08 */	stfs f8, 8(r6)
/* 80124FC0 00121F20  7C C3 22 14 */	add r6, r3, r4
/* 80124FC4 00121F24  38 1F 04 14 */	addi r0, r31, 0x414
/* 80124FC8 00121F28  90 06 00 00 */	stw r0, 0(r6)
/* 80124FCC 00121F2C  38 00 00 2F */	li r0, 0x2f
/* 80124FD0 00121F30  1C 80 00 0C */	mulli r4, r0, 0xc
/* 80124FD4 00121F34  D0 C6 00 04 */	stfs f6, 4(r6)
/* 80124FD8 00121F38  D1 06 00 08 */	stfs f8, 8(r6)
/* 80124FDC 00121F3C  7C C3 2A 14 */	add r6, r3, r5
/* 80124FE0 00121F40  38 1F 04 28 */	addi r0, r31, 0x428
/* 80124FE4 00121F44  90 06 00 00 */	stw r0, 0(r6)
/* 80124FE8 00121F48  38 00 00 30 */	li r0, 0x30
/* 80124FEC 00121F4C  1C A0 00 0C */	mulli r5, r0, 0xc
/* 80124FF0 00121F50  D0 06 00 04 */	stfs f0, 4(r6)
/* 80124FF4 00121F54  D0 46 00 08 */	stfs f2, 8(r6)
/* 80124FF8 00121F58  7C C3 22 14 */	add r6, r3, r4
/* 80124FFC 00121F5C  38 1F 04 40 */	addi r0, r31, 0x440
/* 80125000 00121F60  90 06 00 00 */	stw r0, 0(r6)
/* 80125004 00121F64  38 00 00 31 */	li r0, 0x31
/* 80125008 00121F68  1C 80 00 0C */	mulli r4, r0, 0xc
/* 8012500C 00121F6C  C0 02 A1 7C */	lfs f0, lbl_803EA37C@sda21(r2)
/* 80125010 00121F70  D0 06 00 04 */	stfs f0, 4(r6)
/* 80125014 00121F74  38 00 00 32 */	li r0, 0x32
/* 80125018 00121F78  1C 00 00 0C */	mulli r0, r0, 0xc
/* 8012501C 00121F7C  C0 22 A1 80 */	lfs f1, lbl_803EA380@sda21(r2)
/* 80125020 00121F80  D0 26 00 08 */	stfs f1, 8(r6)
/* 80125024 00121F84  7C C3 2A 14 */	add r6, r3, r5
/* 80125028 00121F88  38 BF 04 54 */	addi r5, r31, 0x454
/* 8012502C 00121F8C  90 A6 00 00 */	stw r5, 0(r6)
/* 80125030 00121F90  7C A3 22 14 */	add r5, r3, r4
/* 80125034 00121F94  38 9F 04 6C */	addi r4, r31, 0x46c
/* 80125038 00121F98  D0 C6 00 04 */	stfs f6, 4(r6)
/* 8012503C 00121F9C  7C E3 02 14 */	add r7, r3, r0
/* 80125040 00121FA0  38 1F 04 88 */	addi r0, r31, 0x488
/* 80125044 00121FA4  C0 02 A1 84 */	lfs f0, lbl_803EA384@sda21(r2)
/* 80125048 00121FA8  D0 06 00 08 */	stfs f0, 8(r6)
/* 8012504C 00121FAC  90 85 00 00 */	stw r4, 0(r5)
/* 80125050 00121FB0  D0 C5 00 04 */	stfs f6, 4(r5)
/* 80125054 00121FB4  D0 25 00 08 */	stfs f1, 8(r5)
/* 80125058 00121FB8  90 07 00 00 */	stw r0, 0(r7)
/* 8012505C 00121FBC  D0 C7 00 04 */	stfs f6, 4(r7)
/* 80125060 00121FC0  38 00 00 33 */	li r0, 0x33
/* 80125064 00121FC4  D0 47 00 08 */	stfs f2, 8(r7)
/* 80125068 00121FC8  1C 00 00 0C */	mulli r0, r0, 0xc
/* 8012506C 00121FCC  7C 83 02 14 */	add r4, r3, r0
/* 80125070 00121FD0  38 1F 04 9C */	addi r0, r31, 0x49c
/* 80125074 00121FD4  90 04 00 00 */	stw r0, 0(r4)
/* 80125078 00121FD8  38 00 00 34 */	li r0, 0x34
/* 8012507C 00121FDC  1C 00 00 0C */	mulli r0, r0, 0xc
/* 80125080 00121FE0  D0 C4 00 04 */	stfs f6, 4(r4)
/* 80125084 00121FE4  D0 44 00 08 */	stfs f2, 8(r4)
/* 80125088 00121FE8  7C A3 02 14 */	add r5, r3, r0
/* 8012508C 00121FEC  38 1F 04 B0 */	addi r0, r31, 0x4b0
/* 80125090 00121FF0  90 05 00 00 */	stw r0, 0(r5)
/* 80125094 00121FF4  38 00 00 35 */	li r0, 0x35
/* 80125098 00121FF8  1C 80 00 0C */	mulli r4, r0, 0xc
/* 8012509C 00121FFC  D0 C5 00 04 */	stfs f6, 4(r5)
/* 801250A0 00122000  C0 02 A1 88 */	lfs f0, lbl_803EA388@sda21(r2)
/* 801250A4 00122004  38 00 00 36 */	li r0, 0x36
/* 801250A8 00122008  1C 00 00 0C */	mulli r0, r0, 0xc
/* 801250AC 0012200C  D0 05 00 08 */	stfs f0, 8(r5)
/* 801250B0 00122010  7C A3 22 14 */	add r5, r3, r4
/* 801250B4 00122014  38 9F 04 C8 */	addi r4, r31, 0x4c8
/* 801250B8 00122018  90 85 00 00 */	stw r4, 0(r5)
/* 801250BC 0012201C  7C 83 02 14 */	add r4, r3, r0
/* 801250C0 00122020  38 1F 04 DC */	addi r0, r31, 0x4dc
/* 801250C4 00122024  D0 C5 00 04 */	stfs f6, 4(r5)
/* 801250C8 00122028  38 60 00 0C */	li r3, 0xc
/* 801250CC 0012202C  D0 05 00 08 */	stfs f0, 8(r5)
/* 801250D0 00122030  90 04 00 00 */	stw r0, 0(r4)
/* 801250D4 00122034  D0 C4 00 04 */	stfs f6, 4(r4)
/* 801250D8 00122038  C0 2D E3 5C */	lfs f1, pi__6NMathF@sda21(r13)
/* 801250DC 0012203C  C0 02 A1 8C */	lfs f0, lbl_803EA38C@sda21(r2)
/* 801250E0 00122040  EC 01 00 32 */	fmuls f0, f1, f0
/* 801250E4 00122044  D0 04 00 08 */	stfs f0, 8(r4)
/* 801250E8 00122048  4B F2 1F 1D */	bl alloc__6SystemFUl
/* 801250EC 0012204C  3B 63 00 00 */	addi r27, r3, 0
/* 801250F0 00122050  7F 63 DB 79 */	or. r3, r27, r27
/* 801250F4 00122054  41 82 00 18 */	beq lbl_8012510C
/* 801250F8 00122058  38 BE 00 00 */	addi r5, r30, 0
/* 801250FC 0012205C  38 FD 00 00 */	addi r7, r29, 0
/* 80125100 00122060  38 80 00 01 */	li r4, 1
/* 80125104 00122064  38 C0 00 37 */	li r6, 0x37
/* 80125108 00122068  4B FF C7 4D */	bl __ct__19ParaMultiParametersFiP18ParaParameterInfoIiP18ParaParameterInfoF
lbl_8012510C:
/* 8012510C 0012206C  93 7C 00 24 */	stw r27, 0x24(r28)
/* 80125110 00122070  38 00 00 00 */	li r0, 0
/* 80125114 00122074  80 9C 00 24 */	lwz r4, 0x24(r28)
/* 80125118 00122078  80 64 00 00 */	lwz r3, 0(r4)
/* 8012511C 0012207C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125120 00122080  90 03 00 00 */	stw r0, 0(r3)
/* 80125124 00122084  80 64 00 04 */	lwz r3, 4(r4)
/* 80125128 00122088  C1 A2 A1 90 */	lfs f13, lbl_803EA390@sda21(r2)
/* 8012512C 0012208C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125130 00122090  D1 A3 00 00 */	stfs f13, 0(r3)
/* 80125134 00122094  80 64 00 04 */	lwz r3, 4(r4)
/* 80125138 00122098  C1 82 A1 94 */	lfs f12, lbl_803EA394@sda21(r2)
/* 8012513C 0012209C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125140 001220A0  D1 83 00 04 */	stfs f12, 4(r3)
/* 80125144 001220A4  80 64 00 04 */	lwz r3, 4(r4)
/* 80125148 001220A8  C1 62 A1 50 */	lfs f11, lbl_803EA350@sda21(r2)
/* 8012514C 001220AC  80 63 00 00 */	lwz r3, 0(r3)
/* 80125150 001220B0  D1 63 00 08 */	stfs f11, 8(r3)
/* 80125154 001220B4  80 64 00 04 */	lwz r3, 4(r4)
/* 80125158 001220B8  C1 42 A1 98 */	lfs f10, lbl_803EA398@sda21(r2)
/* 8012515C 001220BC  80 63 00 00 */	lwz r3, 0(r3)
/* 80125160 001220C0  D1 43 00 0C */	stfs f10, 0xc(r3)
/* 80125164 001220C4  80 64 00 04 */	lwz r3, 4(r4)
/* 80125168 001220C8  C1 22 A1 6C */	lfs f9, lbl_803EA36C@sda21(r2)
/* 8012516C 001220CC  80 63 00 00 */	lwz r3, 0(r3)
/* 80125170 001220D0  D1 23 00 10 */	stfs f9, 0x10(r3)
/* 80125174 001220D4  80 64 00 04 */	lwz r3, 4(r4)
/* 80125178 001220D8  C1 02 A1 9C */	lfs f8, lbl_803EA39C@sda21(r2)
/* 8012517C 001220DC  80 63 00 00 */	lwz r3, 0(r3)
/* 80125180 001220E0  D1 03 00 14 */	stfs f8, 0x14(r3)
/* 80125184 001220E4  80 64 00 04 */	lwz r3, 4(r4)
/* 80125188 001220E8  80 63 00 00 */	lwz r3, 0(r3)
/* 8012518C 001220EC  D1 A3 00 18 */	stfs f13, 0x18(r3)
/* 80125190 001220F0  80 64 00 04 */	lwz r3, 4(r4)
/* 80125194 001220F4  80 63 00 00 */	lwz r3, 0(r3)
/* 80125198 001220F8  D1 83 00 1C */	stfs f12, 0x1c(r3)
/* 8012519C 001220FC  80 64 00 04 */	lwz r3, 4(r4)
/* 801251A0 00122100  C0 02 A1 A0 */	lfs f0, lbl_803EA3A0@sda21(r2)
/* 801251A4 00122104  80 63 00 00 */	lwz r3, 0(r3)
/* 801251A8 00122108  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 801251AC 0012210C  80 64 00 04 */	lwz r3, 4(r4)
/* 801251B0 00122110  C0 E2 A1 A4 */	lfs f7, lbl_803EA3A4@sda21(r2)
/* 801251B4 00122114  80 63 00 00 */	lwz r3, 0(r3)
/* 801251B8 00122118  D0 E3 00 24 */	stfs f7, 0x24(r3)
/* 801251BC 0012211C  80 64 00 04 */	lwz r3, 4(r4)
/* 801251C0 00122120  C0 C2 A1 68 */	lfs f6, lbl_803EA368@sda21(r2)
/* 801251C4 00122124  80 63 00 00 */	lwz r3, 0(r3)
/* 801251C8 00122128  D0 C3 00 28 */	stfs f6, 0x28(r3)
/* 801251CC 0012212C  80 64 00 04 */	lwz r3, 4(r4)
/* 801251D0 00122130  C0 A2 A1 A8 */	lfs f5, lbl_803EA3A8@sda21(r2)
/* 801251D4 00122134  80 63 00 00 */	lwz r3, 0(r3)
/* 801251D8 00122138  D0 A3 00 2C */	stfs f5, 0x2c(r3)
/* 801251DC 0012213C  80 64 00 04 */	lwz r3, 4(r4)
/* 801251E0 00122140  C0 82 A1 AC */	lfs f4, lbl_803EA3AC@sda21(r2)
/* 801251E4 00122144  80 63 00 00 */	lwz r3, 0(r3)
/* 801251E8 00122148  D0 83 00 30 */	stfs f4, 0x30(r3)
/* 801251EC 0012214C  80 64 00 04 */	lwz r3, 4(r4)
/* 801251F0 00122150  80 63 00 00 */	lwz r3, 0(r3)
/* 801251F4 00122154  D1 83 00 34 */	stfs f12, 0x34(r3)
/* 801251F8 00122158  80 64 00 04 */	lwz r3, 4(r4)
/* 801251FC 0012215C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125200 00122160  D0 03 00 38 */	stfs f0, 0x38(r3)
/* 80125204 00122164  80 64 00 04 */	lwz r3, 4(r4)
/* 80125208 00122168  C0 62 A1 B0 */	lfs f3, lbl_803EA3B0@sda21(r2)
/* 8012520C 0012216C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125210 00122170  D0 63 00 3C */	stfs f3, 0x3c(r3)
/* 80125214 00122174  80 64 00 04 */	lwz r3, 4(r4)
/* 80125218 00122178  C0 42 A1 B4 */	lfs f2, lbl_803EA3B4@sda21(r2)
/* 8012521C 0012217C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125220 00122180  D0 43 00 40 */	stfs f2, 0x40(r3)
/* 80125224 00122184  80 64 00 04 */	lwz r3, 4(r4)
/* 80125228 00122188  C0 22 A1 B8 */	lfs f1, lbl_803EA3B8@sda21(r2)
/* 8012522C 0012218C  80 63 00 00 */	lwz r3, 0(r3)
/* 80125230 00122190  D0 23 00 44 */	stfs f1, 0x44(r3)
/* 80125234 00122194  80 64 00 04 */	lwz r3, 4(r4)
/* 80125238 00122198  80 63 00 00 */	lwz r3, 0(r3)
/* 8012523C 0012219C  D1 A3 00 48 */	stfs f13, 0x48(r3)
/* 80125240 001221A0  80 64 00 04 */	lwz r3, 4(r4)
/* 80125244 001221A4  80 63 00 00 */	lwz r3, 0(r3)
/* 80125248 001221A8  D1 03 00 4C */	stfs f8, 0x4c(r3)
/* 8012524C 001221AC  80 64 00 04 */	lwz r3, 4(r4)
/* 80125250 001221B0  80 63 00 00 */	lwz r3, 0(r3)
/* 80125254 001221B4  D1 63 00 50 */	stfs f11, 0x50(r3)
/* 80125258 001221B8  80 64 00 04 */	lwz r3, 4(r4)
/* 8012525C 001221BC  80 63 00 00 */	lwz r3, 0(r3)
/* 80125260 001221C0  D1 43 00 54 */	stfs f10, 0x54(r3)
/* 80125264 001221C4  80 64 00 04 */	lwz r3, 4(r4)
/* 80125268 001221C8  80 63 00 00 */	lwz r3, 0(r3)
/* 8012526C 001221CC  D1 23 00 58 */	stfs f9, 0x58(r3)
/* 80125270 001221D0  80 64 00 04 */	lwz r3, 4(r4)
/* 80125274 001221D4  80 63 00 00 */	lwz r3, 0(r3)
/* 80125278 001221D8  D1 03 00 5C */	stfs f8, 0x5c(r3)
/* 8012527C 001221DC  80 64 00 04 */	lwz r3, 4(r4)
/* 80125280 001221E0  80 63 00 00 */	lwz r3, 0(r3)
/* 80125284 001221E4  D1 A3 00 60 */	stfs f13, 0x60(r3)
/* 80125288 001221E8  80 64 00 04 */	lwz r3, 4(r4)
/* 8012528C 001221EC  80 63 00 00 */	lwz r3, 0(r3)
/* 80125290 001221F0  D1 03 00 64 */	stfs f8, 0x64(r3)
/* 80125294 001221F4  80 64 00 04 */	lwz r3, 4(r4)
/* 80125298 001221F8  C0 02 A1 BC */	lfs f0, lbl_803EA3BC@sda21(r2)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
	.4byte 0x6b757361
	.4byte 0x4974656d
	.4byte 0x2e637070
	.4byte 0
	.4byte 0x426f4261
	.4byte 0x73654974
	.4byte 0x656d0000
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
	.4byte 0x803e15a8
	.4byte 0x8
	.4byte 0x803e15b0
	.4byte 0
	.4byte 0
	.4byte 0x41494372
	.4byte 0x65617475
	.4byte 0x72650000
	.4byte 0x803e15a0
	.4byte 0x2b8
	.4byte 0x803e15a8
	.4byte 0x8
	.4byte 0x803e15b0
	.4byte 0
	.4byte 0x803e15b8
	.4byte 0
	.4byte 0
	.4byte 0x4974656d
	.4byte 0x43726561
	.4byte 0x74757265
	.4byte 0
	.4byte 0x803e15a0
	.4byte 0x2b8
	.4byte 0x803e15a8
	.4byte 0x8
	.4byte 0x803e15b0
	.4byte 0
	.4byte 0x803e15b8
	.4byte 0
	.4byte 0x803e15c0
	.4byte 0
	.4byte 0
	.4byte 0x803e15a0
	.4byte 0x2b8
	.4byte 0x803e15a8
	.4byte 0x8
	.4byte 0x803e15b0
	.4byte 0
	.4byte 0x803e15b8
	.4byte 0
	.4byte 0x803e15c0
	.4byte 0
	.4byte 0x803e15c8
	.4byte 0
	.4byte 0
.global __vt__10BoBaseItem
__vt__10BoBaseItem:
	.4byte __RTTI__10BoBaseItem
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
	.4byte startAI__10BoBaseItemFi
	.4byte getiMass__10BoBaseItemFv
	.4byte getSize__10BoBaseItemFv
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
	.4byte isVisible__10BoBaseItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__10BoBaseItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__10BoBaseItemFP8Creature
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
	.4byte update__10BoBaseItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__10BoBaseItemFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__10BoBaseItem
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
	.4byte 0x4b757361
	.4byte 0x4974656d
	.4byte 0
	.4byte 0x803e15a0
	.4byte 0x2b8
	.4byte 0x803e15a8
	.4byte 0x8
	.4byte 0x803e15b0
	.4byte 0
	.4byte 0x803e15b8
	.4byte 0
	.4byte 0x803e15c0
	.4byte 0
	.4byte 0x803e15c8
	.4byte 0
	.4byte 0
.global __vt__8KusaItem
__vt__8KusaItem:
	.4byte __RTTI__8KusaItem
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
	.4byte startAI__8KusaItemFi
	.4byte getiMass__8KusaItemFv
	.4byte getSize__8KusaItemFv
	.4byte getHeight__12ItemCreatureFv
	.4byte getCylinderHeight__8CreatureFv
	.4byte doStore__8CreatureFP11CreatureInf
	.4byte doRestore__8CreatureFP11CreatureInf
	.4byte doSave__8KusaItemFR18RandomAccessStream
	.4byte doLoad__8KusaItemFR18RandomAccessStream
	.4byte getCentre__8CreatureFv
	.4byte getCentreSize__8CreatureFv
	.4byte getBoundingSphereCentre__8CreatureFv
	.4byte getBoundingSphereRadius__8CreatureFv
	.4byte getShadowPos__8CreatureFv
	.4byte setCentre__8CreatureFR8Vector3f
	.4byte getShadowSize__8CreatureFv
	.4byte isVisible__8KusaItemFv
	.4byte isOrganic__8CreatureFv
	.4byte isTerrible__8CreatureFv
	.4byte isBuried__8CreatureFv
	.4byte isAtari__8CreatureFv
	.4byte isAlive__8KusaItemFv
	.4byte isFixed__8CreatureFv
	.4byte needShadow__8CreatureFv
	.4byte needFlick__8CreatureFP8Creature
	.4byte ignoreAtari__8KusaItemFP8Creature
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
	.4byte update__8KusaItemFv
	.4byte postUpdate__8CreatureFif
	.4byte stickUpdate__8CreatureFv
	.4byte refresh__8KusaItemFR8Graphics
	.4byte refresh2d__8CreatureFR8Graphics
	.4byte renderAtari__8CreatureFR8Graphics
	.4byte drawShadow__8CreatureFR8Graphics
	.4byte demoDraw__8CreatureFR8GraphicsP8Matrix4f
	.4byte getCatchPos__8CreatureFP8Creature
	.4byte doAI__12ItemCreatureFv
	.4byte doAnimation__12ItemCreatureFv
	.4byte doKill__12ItemCreatureFv
	.4byte exitCourse__8CreatureFv
	.4byte __RTTI__8KusaItem
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
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x802BB2E0
.global __RTTI__4Weed
__RTTI__4Weed:
	.4byte 0x803e1504
	.4byte 0x802bb30c
.global __RTTI__8WeedsGen
__RTTI__8WeedsGen:
	.4byte 0x802bb49c
	.4byte 0x802bb4a8
.global __RTTI__8GrassGen
__RTTI__8GrassGen:
	.4byte 0x802bb638
	.4byte 0x802bb644
	.4byte 0x526f636b
	.4byte 0x47656e00
.global __RTTI__7RockGen
__RTTI__7RockGen:
	.4byte 0x803e1554
	.4byte 0x802bb7d4
	.4byte 0
.global lbl_803E1568
lbl_803E1568:
	.4byte 0x3F800000
.global lbl_803E156C
lbl_803E156C:
	.4byte 0x3F800000
.global lbl_803E1570
lbl_803E1570:
	.4byte 0x3F800000
.global lbl_803E1574
lbl_803E1574:
	.4byte 0x3F800000
.global lbl_803E1578
lbl_803E1578:
	.4byte 0x3F800000
.global lbl_803E157C
lbl_803E157C:
	.4byte 0x3F800000
.global lbl_803E1580
lbl_803E1580:
	.4byte 0x00000000
.global lbl_803E1584
lbl_803E1584:
	.4byte 0x00000000
.global lbl_803E1588
lbl_803E1588:
	.4byte 0x00000000
.global lbl_803E158C
lbl_803E158C:
	.4byte 0x00000000
.global lbl_803E1590
lbl_803E1590:
	.4byte 0x00000000
.global lbl_803E1594
lbl_803E1594:
	.4byte 0x3F800000
.global lbl_803E1598
lbl_803E1598:
	.4byte 0x3F800000
.global lbl_803E159C
lbl_803E159C:
	.4byte 0x3F800000
	.4byte 0x802BB984
	.4byte 0x00000000
	.4byte 0x802BB998
	.4byte 0x00000000
