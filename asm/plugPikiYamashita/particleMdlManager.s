.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn init__Q23zen18particleMdlManagerFUlUl, global
/* 801A17D4 0019E734  7C 08 02 A6 */	mflr r0
/* 801A17D8 0019E738  90 01 00 04 */	stw r0, 4(r1)
/* 801A17DC 0019E73C  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 801A17E0 0019E740  BF 41 00 28 */	stmw r26, 0x28(r1)
/* 801A17E4 0019E744  3B 44 00 00 */	addi r26, r4, 0
/* 801A17E8 0019E748  54 84 38 30 */	slwi r4, r4, 7
/* 801A17EC 0019E74C  3B C3 00 00 */	addi r30, r3, 0
/* 801A17F0 0019E750  3B BA 00 00 */	addi r29, r26, 0
/* 801A17F4 0019E754  3B E5 00 00 */	addi r31, r5, 0
/* 801A17F8 0019E758  38 64 00 08 */	addi r3, r4, 8
/* 801A17FC 0019E75C  4B EA 58 09 */	bl alloc__6SystemFUl
/* 801A1800 0019E760  3C 80 80 1A */	lis r4, __ct__Q23zen11particleMdlFv@ha
/* 801A1804 0019E764  3C A0 80 1A */	lis r5, __dt__Q23zen11particleMdlFv@ha
/* 801A1808 0019E768  38 84 1A 64 */	addi r4, r4, __ct__Q23zen11particleMdlFv@l
/* 801A180C 0019E76C  38 A5 1A 08 */	addi r5, r5, __dt__Q23zen11particleMdlFv@l
/* 801A1810 0019E770  38 FD 00 00 */	addi r7, r29, 0
/* 801A1814 0019E774  38 C0 00 80 */	li r6, 0x80
/* 801A1818 0019E778  48 07 34 11 */	bl __construct_new_array
/* 801A181C 0019E77C  90 7E 00 20 */	stw r3, 0x20(r30)
/* 801A1820 0019E780  3B 60 00 00 */	li r27, 0
/* 801A1824 0019E784  3B 80 00 00 */	li r28, 0
/* 801A1828 0019E788  48 00 00 40 */	b .L_801A1868
.L_801A182C:
/* 801A182C 0019E78C  80 1E 00 20 */	lwz r0, 0x20(r30)
/* 801A1830 0019E790  7F A0 E2 14 */	add r29, r0, r28
/* 801A1834 0019E794  38 7D 00 00 */	addi r3, r29, 0
/* 801A1838 0019E798  81 9D 00 00 */	lwz r12, 0(r29)
/* 801A183C 0019E79C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801A1840 0019E7A0  7D 88 03 A6 */	mtlr r12
/* 801A1844 0019E7A4  4E 80 00 21 */	blrl 
/* 801A1848 0019E7A8  80 7E 00 00 */	lwz r3, 0(r30)
/* 801A184C 0019E7AC  7F A4 EB 78 */	mr r4, r29
/* 801A1850 0019E7B0  81 83 00 00 */	lwz r12, 0(r3)
/* 801A1854 0019E7B4  81 8C 00 08 */	lwz r12, 8(r12)
/* 801A1858 0019E7B8  7D 88 03 A6 */	mtlr r12
/* 801A185C 0019E7BC  4E 80 00 21 */	blrl 
/* 801A1860 0019E7C0  3B 9C 00 80 */	addi r28, r28, 0x80
/* 801A1864 0019E7C4  3B 7B 00 01 */	addi r27, r27, 1
.L_801A1868:
/* 801A1868 0019E7C8  7C 1B D0 40 */	cmplw r27, r26
/* 801A186C 0019E7CC  41 80 FF C0 */	blt .L_801A182C
/* 801A1870 0019E7D0  3B BF 00 00 */	addi r29, r31, 0
/* 801A1874 0019E7D4  1C 7D 00 34 */	mulli r3, r29, 0x34
/* 801A1878 0019E7D8  38 63 00 08 */	addi r3, r3, 8
/* 801A187C 0019E7DC  4B EA 57 89 */	bl alloc__6SystemFUl
/* 801A1880 0019E7E0  3C 80 80 1A */	lis r4, __ct__Q23zen16particleChildMdlFv@ha
/* 801A1884 0019E7E4  3C A0 80 1A */	lis r5, __dt__Q23zen16particleChildMdlFv@ha
/* 801A1888 0019E7E8  38 84 19 60 */	addi r4, r4, __ct__Q23zen16particleChildMdlFv@l
/* 801A188C 0019E7EC  38 A5 19 04 */	addi r5, r5, __dt__Q23zen16particleChildMdlFv@l
/* 801A1890 0019E7F0  38 FD 00 00 */	addi r7, r29, 0
/* 801A1894 0019E7F4  38 C0 00 34 */	li r6, 0x34
/* 801A1898 0019E7F8  48 07 33 91 */	bl __construct_new_array
/* 801A189C 0019E7FC  3B 60 00 00 */	li r27, 0
/* 801A18A0 0019E800  90 7E 00 24 */	stw r3, 0x24(r30)
/* 801A18A4 0019E804  7F 7C DB 78 */	mr r28, r27
/* 801A18A8 0019E808  48 00 00 40 */	b .L_801A18E8
.L_801A18AC:
/* 801A18AC 0019E80C  80 1E 00 24 */	lwz r0, 0x24(r30)
/* 801A18B0 0019E810  7F A0 E2 14 */	add r29, r0, r28
/* 801A18B4 0019E814  38 7D 00 00 */	addi r3, r29, 0
/* 801A18B8 0019E818  81 9D 00 00 */	lwz r12, 0(r29)
/* 801A18BC 0019E81C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 801A18C0 0019E820  7D 88 03 A6 */	mtlr r12
/* 801A18C4 0019E824  4E 80 00 21 */	blrl 
/* 801A18C8 0019E828  80 7E 00 10 */	lwz r3, 0x10(r30)
/* 801A18CC 0019E82C  7F A4 EB 78 */	mr r4, r29
/* 801A18D0 0019E830  81 83 00 00 */	lwz r12, 0(r3)
/* 801A18D4 0019E834  81 8C 00 08 */	lwz r12, 8(r12)
/* 801A18D8 0019E838  7D 88 03 A6 */	mtlr r12
/* 801A18DC 0019E83C  4E 80 00 21 */	blrl 
/* 801A18E0 0019E840  3B 9C 00 34 */	addi r28, r28, 0x34
/* 801A18E4 0019E844  3B 7B 00 01 */	addi r27, r27, 1
.L_801A18E8:
/* 801A18E8 0019E848  7C 1B F8 40 */	cmplw r27, r31
/* 801A18EC 0019E84C  41 80 FF C0 */	blt .L_801A18AC
/* 801A18F0 0019E850  BB 41 00 28 */	lmw r26, 0x28(r1)
/* 801A18F4 0019E854  80 01 00 44 */	lwz r0, 0x44(r1)
/* 801A18F8 0019E858  38 21 00 40 */	addi r1, r1, 0x40
/* 801A18FC 0019E85C  7C 08 03 A6 */	mtlr r0
/* 801A1900 0019E860  4E 80 00 20 */	blr 
.endfn init__Q23zen18particleMdlManagerFUlUl

.fn __dt__Q23zen16particleChildMdlFv, weak
/* 801A1904 0019E864  7C 08 02 A6 */	mflr r0
/* 801A1908 0019E868  90 01 00 04 */	stw r0, 4(r1)
/* 801A190C 0019E86C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A1910 0019E870  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A1914 0019E874  7C 7F 1B 79 */	or. r31, r3, r3
/* 801A1918 0019E878  41 82 00 30 */	beq .L_801A1948
/* 801A191C 0019E87C  3C 60 80 2E */	lis r3, __vt__Q23zen16particleChildMdl@ha
/* 801A1920 0019E880  38 03 D8 84 */	addi r0, r3, __vt__Q23zen16particleChildMdl@l
/* 801A1924 0019E884  90 1F 00 00 */	stw r0, 0(r31)
/* 801A1928 0019E888  41 82 00 10 */	beq .L_801A1938
/* 801A192C 0019E88C  3C 60 80 2E */	lis r3, __vt__Q23zen15particleMdlBase@ha
/* 801A1930 0019E890  38 03 D8 48 */	addi r0, r3, __vt__Q23zen15particleMdlBase@l
/* 801A1934 0019E894  90 1F 00 00 */	stw r0, 0(r31)
.L_801A1938:
/* 801A1938 0019E898  7C 80 07 35 */	extsh. r0, r4
/* 801A193C 0019E89C  40 81 00 0C */	ble .L_801A1948
/* 801A1940 0019E8A0  7F E3 FB 78 */	mr r3, r31
/* 801A1944 0019E8A4  4B EA 58 69 */	bl __dl__FPv
.L_801A1948:
/* 801A1948 0019E8A8  7F E3 FB 78 */	mr r3, r31
/* 801A194C 0019E8AC  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A1950 0019E8B0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A1954 0019E8B4  38 21 00 18 */	addi r1, r1, 0x18
/* 801A1958 0019E8B8  7C 08 03 A6 */	mtlr r0
/* 801A195C 0019E8BC  4E 80 00 20 */	blr 
.endfn __dt__Q23zen16particleChildMdlFv

.fn __ct__Q23zen16particleChildMdlFv, weak
/* 801A1960 0019E8C0  3C 80 80 2D */	lis r4, __vt__Q23zen7zenList@ha
/* 801A1964 0019E8C4  38 04 68 DC */	addi r0, r4, __vt__Q23zen7zenList@l
/* 801A1968 0019E8C8  90 03 00 00 */	stw r0, 0(r3)
/* 801A196C 0019E8CC  3C A0 80 2E */	lis r5, __vt__Q23zen15particleMdlBase@ha
/* 801A1970 0019E8D0  38 C5 D8 48 */	addi r6, r5, __vt__Q23zen15particleMdlBase@l
/* 801A1974 0019E8D4  90 63 00 08 */	stw r3, 8(r3)
/* 801A1978 0019E8D8  3C 80 80 2E */	lis r4, __vt__Q23zen16particleChildMdl@ha
/* 801A197C 0019E8DC  38 A0 00 00 */	li r5, 0
/* 801A1980 0019E8E0  90 63 00 04 */	stw r3, 4(r3)
/* 801A1984 0019E8E4  38 04 D8 84 */	addi r0, r4, __vt__Q23zen16particleChildMdl@l
/* 801A1988 0019E8E8  90 C3 00 00 */	stw r6, 0(r3)
/* 801A198C 0019E8EC  C0 22 B3 E8 */	lfs f1, lbl_803EB5E8@sda21(r2)
/* 801A1990 0019E8F0  D0 23 00 14 */	stfs f1, 0x14(r3)
/* 801A1994 0019E8F4  D0 23 00 10 */	stfs f1, 0x10(r3)
/* 801A1998 0019E8F8  D0 23 00 0C */	stfs f1, 0xc(r3)
/* 801A199C 0019E8FC  D0 23 00 20 */	stfs f1, 0x20(r3)
/* 801A19A0 0019E900  D0 23 00 1C */	stfs f1, 0x1c(r3)
/* 801A19A4 0019E904  D0 23 00 18 */	stfs f1, 0x18(r3)
/* 801A19A8 0019E908  C0 0D 11 18 */	lfs f0, lbl_803E5E38@sda21(r13)
/* 801A19AC 0019E90C  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 801A19B0 0019E910  C0 0D 11 1C */	lfs f0, lbl_803E5E3C@sda21(r13)
/* 801A19B4 0019E914  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 801A19B8 0019E918  C0 0D 11 20 */	lfs f0, lbl_803E5E40@sda21(r13)
/* 801A19BC 0019E91C  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 801A19C0 0019E920  C0 0D 11 24 */	lfs f0, lbl_803E5E44@sda21(r13)
/* 801A19C4 0019E924  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 801A19C8 0019E928  C0 0D 11 28 */	lfs f0, lbl_803E5E48@sda21(r13)
/* 801A19CC 0019E92C  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 801A19D0 0019E930  C0 0D 11 2C */	lfs f0, lbl_803E5E4C@sda21(r13)
/* 801A19D4 0019E934  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 801A19D8 0019E938  C0 02 B3 EC */	lfs f0, lbl_803EB5EC@sda21(r2)
/* 801A19DC 0019E93C  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 801A19E0 0019E940  98 A3 00 28 */	stb r5, 0x28(r3)
/* 801A19E4 0019E944  98 A3 00 29 */	stb r5, 0x29(r3)
/* 801A19E8 0019E948  98 A3 00 2A */	stb r5, 0x2a(r3)
/* 801A19EC 0019E94C  98 A3 00 2B */	stb r5, 0x2b(r3)
/* 801A19F0 0019E950  90 03 00 00 */	stw r0, 0(r3)
/* 801A19F4 0019E954  D0 23 00 2C */	stfs f1, 0x2c(r3)
/* 801A19F8 0019E958  98 A3 00 31 */	stb r5, 0x31(r3)
/* 801A19FC 0019E95C  98 A3 00 30 */	stb r5, 0x30(r3)
/* 801A1A00 0019E960  98 A3 00 32 */	stb r5, 0x32(r3)
/* 801A1A04 0019E964  4E 80 00 20 */	blr 
.endfn __ct__Q23zen16particleChildMdlFv

.fn __dt__Q23zen11particleMdlFv, weak
/* 801A1A08 0019E968  7C 08 02 A6 */	mflr r0
/* 801A1A0C 0019E96C  90 01 00 04 */	stw r0, 4(r1)
/* 801A1A10 0019E970  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A1A14 0019E974  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A1A18 0019E978  7C 7F 1B 79 */	or. r31, r3, r3
/* 801A1A1C 0019E97C  41 82 00 30 */	beq .L_801A1A4C
/* 801A1A20 0019E980  3C 60 80 2E */	lis r3, __vt__Q23zen11particleMdl@ha
/* 801A1A24 0019E984  38 03 D8 28 */	addi r0, r3, __vt__Q23zen11particleMdl@l
/* 801A1A28 0019E988  90 1F 00 00 */	stw r0, 0(r31)
/* 801A1A2C 0019E98C  41 82 00 10 */	beq .L_801A1A3C
/* 801A1A30 0019E990  3C 60 80 2E */	lis r3, __vt__Q23zen15particleMdlBase@ha
/* 801A1A34 0019E994  38 03 D8 48 */	addi r0, r3, __vt__Q23zen15particleMdlBase@l
/* 801A1A38 0019E998  90 1F 00 00 */	stw r0, 0(r31)
.L_801A1A3C:
/* 801A1A3C 0019E99C  7C 80 07 35 */	extsh. r0, r4
/* 801A1A40 0019E9A0  40 81 00 0C */	ble .L_801A1A4C
/* 801A1A44 0019E9A4  7F E3 FB 78 */	mr r3, r31
/* 801A1A48 0019E9A8  4B EA 57 65 */	bl __dl__FPv
.L_801A1A4C:
/* 801A1A4C 0019E9AC  7F E3 FB 78 */	mr r3, r31
/* 801A1A50 0019E9B0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A1A54 0019E9B4  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A1A58 0019E9B8  38 21 00 18 */	addi r1, r1, 0x18
/* 801A1A5C 0019E9BC  7C 08 03 A6 */	mtlr r0
/* 801A1A60 0019E9C0  4E 80 00 20 */	blr 
.endfn __dt__Q23zen11particleMdlFv

.fn __ct__Q23zen11particleMdlFv, weak
/* 801A1A64 0019E9C4  7C 08 02 A6 */	mflr r0
/* 801A1A68 0019E9C8  3C 80 80 2E */	lis r4, __vt__Q23zen15particleMdlBase@ha
/* 801A1A6C 0019E9CC  90 01 00 04 */	stw r0, 4(r1)
/* 801A1A70 0019E9D0  38 A4 D8 48 */	addi r5, r4, __vt__Q23zen15particleMdlBase@l
/* 801A1A74 0019E9D4  38 80 00 00 */	li r4, 0
/* 801A1A78 0019E9D8  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A1A7C 0019E9DC  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A1A80 0019E9E0  3B E0 00 00 */	li r31, 0
/* 801A1A84 0019E9E4  93 C1 00 10 */	stw r30, 0x10(r1)
/* 801A1A88 0019E9E8  90 61 00 08 */	stw r3, 8(r1)
/* 801A1A8C 0019E9EC  3C 60 80 2D */	lis r3, __vt__Q23zen7zenList@ha
/* 801A1A90 0019E9F0  38 03 68 DC */	addi r0, r3, __vt__Q23zen7zenList@l
/* 801A1A94 0019E9F4  83 C1 00 08 */	lwz r30, 8(r1)
/* 801A1A98 0019E9F8  3C 60 80 2E */	lis r3, __vt__Q23zen11particleMdl@ha
/* 801A1A9C 0019E9FC  38 C3 D8 28 */	addi r6, r3, __vt__Q23zen11particleMdl@l
/* 801A1AA0 0019EA00  90 1E 00 00 */	stw r0, 0(r30)
/* 801A1AA4 0019EA04  38 00 00 01 */	li r0, 1
/* 801A1AA8 0019EA08  38 7E 00 6C */	addi r3, r30, 0x6c
/* 801A1AAC 0019EA0C  93 DE 00 08 */	stw r30, 8(r30)
/* 801A1AB0 0019EA10  93 DE 00 04 */	stw r30, 4(r30)
/* 801A1AB4 0019EA14  90 BE 00 00 */	stw r5, 0(r30)
/* 801A1AB8 0019EA18  38 A0 00 01 */	li r5, 1
/* 801A1ABC 0019EA1C  C0 42 B3 E8 */	lfs f2, lbl_803EB5E8@sda21(r2)
/* 801A1AC0 0019EA20  D0 5E 00 14 */	stfs f2, 0x14(r30)
/* 801A1AC4 0019EA24  D0 5E 00 10 */	stfs f2, 0x10(r30)
/* 801A1AC8 0019EA28  D0 5E 00 0C */	stfs f2, 0xc(r30)
/* 801A1ACC 0019EA2C  D0 5E 00 20 */	stfs f2, 0x20(r30)
/* 801A1AD0 0019EA30  D0 5E 00 1C */	stfs f2, 0x1c(r30)
/* 801A1AD4 0019EA34  D0 5E 00 18 */	stfs f2, 0x18(r30)
/* 801A1AD8 0019EA38  C0 0D 11 18 */	lfs f0, lbl_803E5E38@sda21(r13)
/* 801A1ADC 0019EA3C  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 801A1AE0 0019EA40  C0 0D 11 1C */	lfs f0, lbl_803E5E3C@sda21(r13)
/* 801A1AE4 0019EA44  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 801A1AE8 0019EA48  C0 0D 11 20 */	lfs f0, lbl_803E5E40@sda21(r13)
/* 801A1AEC 0019EA4C  D0 1E 00 14 */	stfs f0, 0x14(r30)
/* 801A1AF0 0019EA50  C0 0D 11 24 */	lfs f0, lbl_803E5E44@sda21(r13)
/* 801A1AF4 0019EA54  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 801A1AF8 0019EA58  C0 0D 11 28 */	lfs f0, lbl_803E5E48@sda21(r13)
/* 801A1AFC 0019EA5C  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 801A1B00 0019EA60  C0 0D 11 2C */	lfs f0, lbl_803E5E4C@sda21(r13)
/* 801A1B04 0019EA64  D0 1E 00 20 */	stfs f0, 0x20(r30)
/* 801A1B08 0019EA68  C0 22 B3 EC */	lfs f1, lbl_803EB5EC@sda21(r2)
/* 801A1B0C 0019EA6C  D0 3E 00 24 */	stfs f1, 0x24(r30)
/* 801A1B10 0019EA70  9B FE 00 28 */	stb r31, 0x28(r30)
/* 801A1B14 0019EA74  9B FE 00 29 */	stb r31, 0x29(r30)
/* 801A1B18 0019EA78  9B FE 00 2A */	stb r31, 0x2a(r30)
/* 801A1B1C 0019EA7C  9B FE 00 2B */	stb r31, 0x2b(r30)
/* 801A1B20 0019EA80  90 DE 00 00 */	stw r6, 0(r30)
/* 801A1B24 0019EA84  D0 5E 00 3C */	stfs f2, 0x3c(r30)
/* 801A1B28 0019EA88  D0 5E 00 38 */	stfs f2, 0x38(r30)
/* 801A1B2C 0019EA8C  D0 5E 00 34 */	stfs f2, 0x34(r30)
/* 801A1B30 0019EA90  D0 5E 00 48 */	stfs f2, 0x48(r30)
/* 801A1B34 0019EA94  D0 5E 00 44 */	stfs f2, 0x44(r30)
/* 801A1B38 0019EA98  D0 5E 00 40 */	stfs f2, 0x40(r30)
/* 801A1B3C 0019EA9C  D0 5E 00 64 */	stfs f2, 0x64(r30)
/* 801A1B40 0019EAA0  D0 5E 00 60 */	stfs f2, 0x60(r30)
/* 801A1B44 0019EAA4  D0 5E 00 5C */	stfs f2, 0x5c(r30)
/* 801A1B48 0019EAA8  D0 5E 00 6C */	stfs f2, 0x6c(r30)
/* 801A1B4C 0019EAAC  9B FE 00 70 */	stb r31, 0x70(r30)
/* 801A1B50 0019EAB0  B0 1E 00 72 */	sth r0, 0x72(r30)
/* 801A1B54 0019EAB4  93 FE 00 74 */	stw r31, 0x74(r30)
/* 801A1B58 0019EAB8  B3 FE 00 2E */	sth r31, 0x2e(r30)
/* 801A1B5C 0019EABC  B3 FE 00 2C */	sth r31, 0x2c(r30)
/* 801A1B60 0019EAC0  D0 5E 00 30 */	stfs f2, 0x30(r30)
/* 801A1B64 0019EAC4  C0 0D 11 30 */	lfs f0, lbl_803E5E50@sda21(r13)
/* 801A1B68 0019EAC8  D0 1E 00 34 */	stfs f0, 0x34(r30)
/* 801A1B6C 0019EACC  C0 0D 11 34 */	lfs f0, lbl_803E5E54@sda21(r13)
/* 801A1B70 0019EAD0  D0 1E 00 38 */	stfs f0, 0x38(r30)
/* 801A1B74 0019EAD4  C0 0D 11 38 */	lfs f0, lbl_803E5E58@sda21(r13)
/* 801A1B78 0019EAD8  D0 1E 00 3C */	stfs f0, 0x3c(r30)
/* 801A1B7C 0019EADC  D0 5E 00 54 */	stfs f2, 0x54(r30)
/* 801A1B80 0019EAE0  D0 5E 00 50 */	stfs f2, 0x50(r30)
/* 801A1B84 0019EAE4  D0 5E 00 50 */	stfs f2, 0x50(r30)
/* 801A1B88 0019EAE8  C0 0D 11 3C */	lfs f0, lbl_803E5E5C@sda21(r13)
/* 801A1B8C 0019EAEC  D0 1E 00 5C */	stfs f0, 0x5c(r30)
/* 801A1B90 0019EAF0  C0 0D 11 40 */	lfs f0, lbl_803E5E60@sda21(r13)
/* 801A1B94 0019EAF4  D0 1E 00 60 */	stfs f0, 0x60(r30)
/* 801A1B98 0019EAF8  C0 0D 11 44 */	lfs f0, lbl_803E5E64@sda21(r13)
/* 801A1B9C 0019EAFC  D0 1E 00 64 */	stfs f0, 0x64(r30)
/* 801A1BA0 0019EB00  B3 FE 00 58 */	sth r31, 0x58(r30)
/* 801A1BA4 0019EB04  B3 FE 00 5A */	sth r31, 0x5a(r30)
/* 801A1BA8 0019EB08  D0 3E 00 64 */	stfs f1, 0x64(r30)
/* 801A1BAC 0019EB0C  9B FE 00 4C */	stb r31, 0x4c(r30)
/* 801A1BB0 0019EB10  9B FE 00 68 */	stb r31, 0x68(r30)
/* 801A1BB4 0019EB14  9B FE 00 69 */	stb r31, 0x69(r30)
/* 801A1BB8 0019EB18  9B FE 00 6A */	stb r31, 0x6a(r30)
/* 801A1BBC 0019EB1C  9B FE 00 6B */	stb r31, 0x6b(r30)
/* 801A1BC0 0019EB20  48 00 00 25 */	bl init__Q23zen16bBoardColourAnimFPQ23zen20bBoardColourAnimDatas
/* 801A1BC4 0019EB24  93 FE 00 78 */	stw r31, 0x78(r30)
/* 801A1BC8 0019EB28  7F C3 F3 78 */	mr r3, r30
/* 801A1BCC 0019EB2C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A1BD0 0019EB30  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A1BD4 0019EB34  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 801A1BD8 0019EB38  38 21 00 18 */	addi r1, r1, 0x18
/* 801A1BDC 0019EB3C  7C 08 03 A6 */	mtlr r0
/* 801A1BE0 0019EB40  4E 80 00 20 */	blr 
.endfn __ct__Q23zen11particleMdlFv

.fn init__Q23zen16bBoardColourAnimFPQ23zen20bBoardColourAnimDatas, weak
/* 801A1BE4 0019EB44  C0 02 B3 E8 */	lfs f0, lbl_803EB5E8@sda21(r2)
/* 801A1BE8 0019EB48  38 00 00 00 */	li r0, 0
/* 801A1BEC 0019EB4C  D0 03 00 00 */	stfs f0, 0(r3)
/* 801A1BF0 0019EB50  98 03 00 04 */	stb r0, 4(r3)
/* 801A1BF4 0019EB54  90 83 00 08 */	stw r4, 8(r3)
/* 801A1BF8 0019EB58  80 83 00 08 */	lwz r4, 8(r3)
/* 801A1BFC 0019EB5C  28 04 00 00 */	cmplwi r4, 0
/* 801A1C00 0019EB60  41 82 00 24 */	beq .L_801A1C24
/* 801A1C04 0019EB64  88 04 00 02 */	lbz r0, 2(r4)
/* 801A1C08 0019EB68  28 00 00 00 */	cmplwi r0, 0
/* 801A1C0C 0019EB6C  41 82 00 0C */	beq .L_801A1C18
/* 801A1C10 0019EB70  B0 A3 00 06 */	sth r5, 6(r3)
/* 801A1C14 0019EB74  4E 80 00 20 */	blr 
.L_801A1C18:
/* 801A1C18 0019EB78  88 04 00 01 */	lbz r0, 1(r4)
/* 801A1C1C 0019EB7C  B0 03 00 06 */	sth r0, 6(r3)
/* 801A1C20 0019EB80  4E 80 00 20 */	blr 
.L_801A1C24:
/* 801A1C24 0019EB84  B0 A3 00 06 */	sth r5, 6(r3)
/* 801A1C28 0019EB88  4E 80 00 20 */	blr 
.endfn init__Q23zen16bBoardColourAnimFPQ23zen20bBoardColourAnimDatas

.fn remove__Q23zen11particleMdlFv, weak
/* 801A1C2C 0019EB8C  7C 08 02 A6 */	mflr r0
/* 801A1C30 0019EB90  38 80 00 00 */	li r4, 0
/* 801A1C34 0019EB94  90 01 00 04 */	stw r0, 4(r1)
/* 801A1C38 0019EB98  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 801A1C3C 0019EB9C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 801A1C40 0019EBA0  3B E0 00 00 */	li r31, 0
/* 801A1C44 0019EBA4  93 C1 00 10 */	stw r30, 0x10(r1)
/* 801A1C48 0019EBA8  7C 7E 1B 78 */	mr r30, r3
/* 801A1C4C 0019EBAC  80 03 00 04 */	lwz r0, 4(r3)
/* 801A1C50 0019EBB0  80 A3 00 08 */	lwz r5, 8(r3)
/* 801A1C54 0019EBB4  38 7E 00 6C */	addi r3, r30, 0x6c
/* 801A1C58 0019EBB8  90 05 00 04 */	stw r0, 4(r5)
/* 801A1C5C 0019EBBC  38 A0 00 01 */	li r5, 1
/* 801A1C60 0019EBC0  80 1E 00 08 */	lwz r0, 8(r30)
/* 801A1C64 0019EBC4  80 DE 00 04 */	lwz r6, 4(r30)
/* 801A1C68 0019EBC8  90 06 00 08 */	stw r0, 8(r6)
/* 801A1C6C 0019EBCC  C0 0D 11 18 */	lfs f0, lbl_803E5E38@sda21(r13)
/* 801A1C70 0019EBD0  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 801A1C74 0019EBD4  C0 0D 11 1C */	lfs f0, lbl_803E5E3C@sda21(r13)
/* 801A1C78 0019EBD8  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 801A1C7C 0019EBDC  C0 0D 11 20 */	lfs f0, lbl_803E5E40@sda21(r13)
/* 801A1C80 0019EBE0  D0 1E 00 14 */	stfs f0, 0x14(r30)
/* 801A1C84 0019EBE4  C0 0D 11 24 */	lfs f0, lbl_803E5E44@sda21(r13)
/* 801A1C88 0019EBE8  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 801A1C8C 0019EBEC  C0 0D 11 28 */	lfs f0, lbl_803E5E48@sda21(r13)
/* 801A1C90 0019EBF0  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 801A1C94 0019EBF4  C0 0D 11 2C */	lfs f0, lbl_803E5E4C@sda21(r13)
/* 801A1C98 0019EBF8  D0 1E 00 20 */	stfs f0, 0x20(r30)
/* 801A1C9C 0019EBFC  C0 42 B3 EC */	lfs f2, lbl_803EB5EC@sda21(r2)
/* 801A1CA0 0019EC00  D0 5E 00 24 */	stfs f2, 0x24(r30)
/* 801A1CA4 0019EC04  9B FE 00 28 */	stb r31, 0x28(r30)
/* 801A1CA8 0019EC08  9B FE 00 29 */	stb r31, 0x29(r30)
/* 801A1CAC 0019EC0C  9B FE 00 2A */	stb r31, 0x2a(r30)
/* 801A1CB0 0019EC10  9B FE 00 2B */	stb r31, 0x2b(r30)
/* 801A1CB4 0019EC14  B3 FE 00 2E */	sth r31, 0x2e(r30)
/* 801A1CB8 0019EC18  B3 FE 00 2C */	sth r31, 0x2c(r30)
/* 801A1CBC 0019EC1C  C0 22 B3 E8 */	lfs f1, lbl_803EB5E8@sda21(r2)
/* 801A1CC0 0019EC20  D0 3E 00 30 */	stfs f1, 0x30(r30)
/* 801A1CC4 0019EC24  C0 0D 11 30 */	lfs f0, lbl_803E5E50@sda21(r13)
/* 801A1CC8 0019EC28  D0 1E 00 34 */	stfs f0, 0x34(r30)
/* 801A1CCC 0019EC2C  C0 0D 11 34 */	lfs f0, lbl_803E5E54@sda21(r13)
/* 801A1CD0 0019EC30  D0 1E 00 38 */	stfs f0, 0x38(r30)
/* 801A1CD4 0019EC34  C0 0D 11 38 */	lfs f0, lbl_803E5E58@sda21(r13)
/* 801A1CD8 0019EC38  D0 1E 00 3C */	stfs f0, 0x3c(r30)
/* 801A1CDC 0019EC3C  D0 3E 00 54 */	stfs f1, 0x54(r30)
/* 801A1CE0 0019EC40  D0 3E 00 50 */	stfs f1, 0x50(r30)
/* 801A1CE4 0019EC44  D0 3E 00 50 */	stfs f1, 0x50(r30)
/* 801A1CE8 0019EC48  C0 0D 11 3C */	lfs f0, lbl_803E5E5C@sda21(r13)
/* 801A1CEC 0019EC4C  D0 1E 00 5C */	stfs f0, 0x5c(r30)
/* 801A1CF0 0019EC50  C0 0D 11 40 */	lfs f0, lbl_803E5E60@sda21(r13)
/* 801A1CF4 0019EC54  D0 1E 00 60 */	stfs f0, 0x60(r30)
/* 801A1CF8 0019EC58  C0 0D 11 44 */	lfs f0, lbl_803E5E64@sda21(r13)
/* 801A1CFC 0019EC5C  D0 1E 00 64 */	stfs f0, 0x64(r30)
/* 801A1D00 0019EC60  B3 FE 00 58 */	sth r31, 0x58(r30)
/* 801A1D04 0019EC64  B3 FE 00 5A */	sth r31, 0x5a(r30)
/* 801A1D08 0019EC68  D0 5E 00 64 */	stfs f2, 0x64(r30)
/* 801A1D0C 0019EC6C  9B FE 00 4C */	stb r31, 0x4c(r30)
/* 801A1D10 0019EC70  9B FE 00 68 */	stb r31, 0x68(r30)
/* 801A1D14 0019EC74  9B FE 00 69 */	stb r31, 0x69(r30)
/* 801A1D18 0019EC78  9B FE 00 6A */	stb r31, 0x6a(r30)
/* 801A1D1C 0019EC7C  9B FE 00 6B */	stb r31, 0x6b(r30)
/* 801A1D20 0019EC80  4B FF FE C5 */	bl init__Q23zen16bBoardColourAnimFPQ23zen20bBoardColourAnimDatas
/* 801A1D24 0019EC84  93 FE 00 78 */	stw r31, 0x78(r30)
/* 801A1D28 0019EC88  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 801A1D2C 0019EC8C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 801A1D30 0019EC90  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 801A1D34 0019EC94  38 21 00 18 */	addi r1, r1, 0x18
/* 801A1D38 0019EC98  7C 08 03 A6 */	mtlr r0
/* 801A1D3C 0019EC9C  4E 80 00 20 */	blr 
.endfn remove__Q23zen11particleMdlFv

.fn remove__Q23zen15particleMdlBaseFv, weak
/* 801A1D40 0019ECA0  80 A3 00 04 */	lwz r5, 4(r3)
/* 801A1D44 0019ECA4  38 00 00 00 */	li r0, 0
/* 801A1D48 0019ECA8  80 83 00 08 */	lwz r4, 8(r3)
/* 801A1D4C 0019ECAC  90 A4 00 04 */	stw r5, 4(r4)
/* 801A1D50 0019ECB0  80 A3 00 08 */	lwz r5, 8(r3)
/* 801A1D54 0019ECB4  80 83 00 04 */	lwz r4, 4(r3)
/* 801A1D58 0019ECB8  90 A4 00 08 */	stw r5, 8(r4)
/* 801A1D5C 0019ECBC  C0 0D 11 18 */	lfs f0, lbl_803E5E38@sda21(r13)
/* 801A1D60 0019ECC0  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 801A1D64 0019ECC4  C0 0D 11 1C */	lfs f0, lbl_803E5E3C@sda21(r13)
/* 801A1D68 0019ECC8  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 801A1D6C 0019ECCC  C0 0D 11 20 */	lfs f0, lbl_803E5E40@sda21(r13)
/* 801A1D70 0019ECD0  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 801A1D74 0019ECD4  C0 0D 11 24 */	lfs f0, lbl_803E5E44@sda21(r13)
/* 801A1D78 0019ECD8  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 801A1D7C 0019ECDC  C0 0D 11 28 */	lfs f0, lbl_803E5E48@sda21(r13)
/* 801A1D80 0019ECE0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 801A1D84 0019ECE4  C0 0D 11 2C */	lfs f0, lbl_803E5E4C@sda21(r13)
/* 801A1D88 0019ECE8  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 801A1D8C 0019ECEC  C0 02 B3 EC */	lfs f0, lbl_803EB5EC@sda21(r2)
/* 801A1D90 0019ECF0  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 801A1D94 0019ECF4  98 03 00 28 */	stb r0, 0x28(r3)
/* 801A1D98 0019ECF8  98 03 00 29 */	stb r0, 0x29(r3)
/* 801A1D9C 0019ECFC  98 03 00 2A */	stb r0, 0x2a(r3)
/* 801A1DA0 0019ED00  98 03 00 2B */	stb r0, 0x2b(r3)
/* 801A1DA4 0019ED04  4E 80 00 20 */	blr 
.endfn remove__Q23zen15particleMdlBaseFv

.fn remove__Q23zen16particleChildMdlFv, weak
/* 801A1DA8 0019ED08  80 A3 00 04 */	lwz r5, 4(r3)
/* 801A1DAC 0019ED0C  38 00 00 00 */	li r0, 0
/* 801A1DB0 0019ED10  80 83 00 08 */	lwz r4, 8(r3)
/* 801A1DB4 0019ED14  90 A4 00 04 */	stw r5, 4(r4)
/* 801A1DB8 0019ED18  80 A3 00 08 */	lwz r5, 8(r3)
/* 801A1DBC 0019ED1C  80 83 00 04 */	lwz r4, 4(r3)
/* 801A1DC0 0019ED20  90 A4 00 08 */	stw r5, 8(r4)
/* 801A1DC4 0019ED24  C0 0D 11 18 */	lfs f0, lbl_803E5E38@sda21(r13)
/* 801A1DC8 0019ED28  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 801A1DCC 0019ED2C  C0 0D 11 1C */	lfs f0, lbl_803E5E3C@sda21(r13)
/* 801A1DD0 0019ED30  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 801A1DD4 0019ED34  C0 0D 11 20 */	lfs f0, lbl_803E5E40@sda21(r13)
/* 801A1DD8 0019ED38  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 801A1DDC 0019ED3C  C0 0D 11 24 */	lfs f0, lbl_803E5E44@sda21(r13)
/* 801A1DE0 0019ED40  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 801A1DE4 0019ED44  C0 0D 11 28 */	lfs f0, lbl_803E5E48@sda21(r13)
/* 801A1DE8 0019ED48  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 801A1DEC 0019ED4C  C0 0D 11 2C */	lfs f0, lbl_803E5E4C@sda21(r13)
/* 801A1DF0 0019ED50  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 801A1DF4 0019ED54  C0 02 B3 EC */	lfs f0, lbl_803EB5EC@sda21(r2)
/* 801A1DF8 0019ED58  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 801A1DFC 0019ED5C  98 03 00 28 */	stb r0, 0x28(r3)
/* 801A1E00 0019ED60  98 03 00 29 */	stb r0, 0x29(r3)
/* 801A1E04 0019ED64  98 03 00 2A */	stb r0, 0x2a(r3)
/* 801A1E08 0019ED68  98 03 00 2B */	stb r0, 0x2b(r3)
/* 801A1E0C 0019ED6C  4E 80 00 20 */	blr 
.endfn remove__Q23zen16particleChildMdlFv

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802DD7A0, local
	.asciz "particleMdlManager.cpp"
.endobj lbl_802DD7A0
.balign 4
.obj lbl_802DD7B8, local
	.asciz "particleMdlManager"
.endobj lbl_802DD7B8
.balign 4
.obj lbl_802DD7CC, local
	.asciz "zen::particleMdl"
.endobj lbl_802DD7CC
.balign 4
.obj lbl_802DD7E0, local
	.asciz "zen::zenList"
.endobj lbl_802DD7E0
.balign 4
.obj lbl_802DD7F0, local
	.asciz "zen::particleMdlBase"
.endobj lbl_802DD7F0
.balign 4
.obj lbl_802DD808, local
	.4byte __RTTI__Q23zen7zenList
	.4byte 0
	.4byte 0
.endobj lbl_802DD808
.balign 4
.obj lbl_802DD814, local
	.4byte __RTTI__Q23zen7zenList
	.4byte 0
	.4byte __RTTI__Q23zen15particleMdlBase
	.4byte 0
	.4byte 0
.endobj lbl_802DD814
.balign 4
.obj __vt__Q23zen11particleMdl, weak
	.4byte __RTTI__Q23zen11particleMdl
	.4byte 0
	.4byte insertAfter__Q23zen7zenListFPQ23zen7zenList
	.4byte remove__Q23zen11particleMdlFv
.endobj __vt__Q23zen11particleMdl
.balign 4
.skip 0x10 # compiler padding
.obj __vt__Q23zen15particleMdlBase, weak
	.4byte __RTTI__Q23zen15particleMdlBase
	.4byte 0
	.4byte insertAfter__Q23zen7zenListFPQ23zen7zenList
	.4byte remove__Q23zen15particleMdlBaseFv
.endobj __vt__Q23zen15particleMdlBase
.balign 4
.obj lbl_802DD858, local
	.asciz "zen::particleChildMdl"
.endobj lbl_802DD858
.balign 4
.obj lbl_802DD870, local
	.4byte __RTTI__Q23zen7zenList
	.4byte 0
	.4byte __RTTI__Q23zen15particleMdlBase
	.4byte 0
	.4byte 0
.endobj lbl_802DD870
.balign 4
.obj __vt__Q23zen16particleChildMdl, weak
	.4byte __RTTI__Q23zen16particleChildMdl
	.4byte 0
	.4byte insertAfter__Q23zen7zenListFPQ23zen7zenList
	.4byte remove__Q23zen16particleChildMdlFv
.endobj __vt__Q23zen16particleChildMdl

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E5E38, local
	.float 0.0
.endobj lbl_803E5E38
.obj lbl_803E5E3C, local
	.float 0.0
.endobj lbl_803E5E3C
.obj lbl_803E5E40, local
	.float 0.0
.endobj lbl_803E5E40
.obj lbl_803E5E44, local
	.float 0.0
.endobj lbl_803E5E44
.obj lbl_803E5E48, local
	.float 0.0
.endobj lbl_803E5E48
.obj lbl_803E5E4C, local
	.float 0.0
.endobj lbl_803E5E4C
.obj lbl_803E5E50, local
	.float 0.0
.endobj lbl_803E5E50
.obj lbl_803E5E54, local
	.float 0.0
.endobj lbl_803E5E54
.obj lbl_803E5E58, local
	.float 0.0
.endobj lbl_803E5E58
.obj lbl_803E5E5C, local
	.float 0.0
.endobj lbl_803E5E5C
.obj lbl_803E5E60, local
	.float 0.0
.endobj lbl_803E5E60
.obj lbl_803E5E64, local
	.float 0.0
.endobj lbl_803E5E64
.obj __RTTI__Q23zen7zenList, local
	.4byte lbl_802DD7E0
	.4byte 0
.endobj __RTTI__Q23zen7zenList
.balign 4
.obj __RTTI__Q23zen15particleMdlBase, local
	.4byte lbl_802DD7F0
	.4byte lbl_802DD808
.endobj __RTTI__Q23zen15particleMdlBase
.balign 4
.obj __RTTI__Q23zen11particleMdl, local
	.4byte lbl_802DD7CC
	.4byte lbl_802DD814
.endobj __RTTI__Q23zen11particleMdl
.balign 4
.obj __RTTI__Q23zen16particleChildMdl, local
	.4byte lbl_802DD858
	.4byte lbl_802DD870
.endobj __RTTI__Q23zen16particleChildMdl

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EB5E8, local
	.float 0.0
.endobj lbl_803EB5E8
.balign 4
.obj lbl_803EB5EC, local
	.float 1.0
.endobj lbl_803EB5EC
