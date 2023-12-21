.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
.balign 32, 0
.fn LoadAram__FPcPUlUl, local
/* 8000D8A0 0000A800  7C 08 02 A6 */	mflr r0
/* 8000D8A4 0000A804  39 04 00 00 */	addi r8, r4, 0
/* 8000D8A8 0000A808  90 01 00 04 */	stw r0, 4(r1)
/* 8000D8AC 0000A80C  38 C0 00 00 */	li r6, 0
/* 8000D8B0 0000A810  38 E0 00 00 */	li r7, 0
/* 8000D8B4 0000A814  39 20 00 00 */	li r9, 0
/* 8000D8B8 0000A818  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8000D8BC 0000A81C  93 E1 00 24 */	stw r31, 0x24(r1)
/* 8000D8C0 0000A820  90 A1 00 10 */	stw r5, 0x10(r1)
/* 8000D8C4 0000A824  90 61 00 08 */	stw r3, 8(r1)
/* 8000D8C8 0000A828  38 60 00 00 */	li r3, 0
/* 8000D8CC 0000A82C  83 E1 00 10 */	lwz r31, 0x10(r1)
/* 8000D8D0 0000A830  80 81 00 08 */	lwz r4, 8(r1)
/* 8000D8D4 0000A834  38 BF 00 00 */	addi r5, r31, 0
/* 8000D8D8 0000A838  4B FF A5 09 */	bl DVDT_LoadtoARAM__FUlPcUlUlUlPUlPFUl_v
/* 8000D8DC 0000A83C  2C 03 FF FF */	cmpwi r3, -1
/* 8000D8E0 0000A840  40 82 00 0C */	bne .L_8000D8EC
/* 8000D8E4 0000A844  38 60 00 00 */	li r3, 0
/* 8000D8E8 0000A848  48 00 00 08 */	b .L_8000D8F0
.L_8000D8EC:
/* 8000D8EC 0000A84C  7F E3 FB 78 */	mr r3, r31
.L_8000D8F0:
/* 8000D8F0 0000A850  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 8000D8F4 0000A854  83 E1 00 24 */	lwz r31, 0x24(r1)
/* 8000D8F8 0000A858  38 21 00 28 */	addi r1, r1, 0x28
/* 8000D8FC 0000A85C  7C 08 03 A6 */	mtlr r0
/* 8000D900 0000A860  4E 80 00 20 */	blr 
.endfn LoadAram__FPcPUlUl

.balign 32, 0
.fn LoadAramSingle__FPcUlUlPUlUl, local
/* 8000D920 0000A880  7C 08 02 A6 */	mflr r0
/* 8000D924 0000A884  39 06 00 00 */	addi r8, r6, 0
/* 8000D928 0000A888  90 01 00 04 */	stw r0, 4(r1)
/* 8000D92C 0000A88C  39 20 00 00 */	li r9, 0
/* 8000D930 0000A890  94 21 FF C8 */	stwu r1, -0x38(r1)
/* 8000D934 0000A894  93 E1 00 34 */	stw r31, 0x34(r1)
/* 8000D938 0000A898  3B E7 00 00 */	addi r31, r7, 0
/* 8000D93C 0000A89C  90 A1 00 10 */	stw r5, 0x10(r1)
/* 8000D940 0000A8A0  7F E5 FB 78 */	mr r5, r31
/* 8000D944 0000A8A4  90 61 00 08 */	stw r3, 8(r1)
/* 8000D948 0000A8A8  38 60 00 00 */	li r3, 0
/* 8000D94C 0000A8AC  80 E1 00 10 */	lwz r7, 0x10(r1)
/* 8000D950 0000A8B0  90 81 00 0C */	stw r4, 0xc(r1)
/* 8000D954 0000A8B4  80 81 00 08 */	lwz r4, 8(r1)
/* 8000D958 0000A8B8  80 C1 00 0C */	lwz r6, 0xc(r1)
/* 8000D95C 0000A8BC  4B FF A4 85 */	bl DVDT_LoadtoARAM__FUlPcUlUlUlPUlPFUl_v
/* 8000D960 0000A8C0  2C 03 FF FF */	cmpwi r3, -1
/* 8000D964 0000A8C4  40 82 00 0C */	bne .L_8000D970
/* 8000D968 0000A8C8  38 60 00 00 */	li r3, 0
/* 8000D96C 0000A8CC  48 00 00 08 */	b .L_8000D974
.L_8000D970:
/* 8000D970 0000A8D0  7F E3 FB 78 */	mr r3, r31
.L_8000D974:
/* 8000D974 0000A8D4  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8000D978 0000A8D8  83 E1 00 34 */	lwz r31, 0x34(r1)
/* 8000D97C 0000A8DC  38 21 00 38 */	addi r1, r1, 0x38
/* 8000D980 0000A8E0  7C 08 03 A6 */	mtlr r0
/* 8000D984 0000A8E4  4E 80 00 20 */	blr 
.endfn LoadAramSingle__FPcUlUlPUlUl

.balign 32, 0
.fn Show_AramMotherHeap__Fv, global
/* 8000D9A0 0000A900  7C 08 02 A6 */	mflr r0
/* 8000D9A4 0000A904  3C 60 80 3E */	lis r3, aram_mother@ha
/* 8000D9A8 0000A908  90 01 00 04 */	stw r0, 4(r1)
/* 8000D9AC 0000A90C  38 80 00 00 */	li r4, 0
/* 8000D9B0 0000A910  38 63 AF A0 */	addi r3, r3, aram_mother@l
/* 8000D9B4 0000A914  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000D9B8 0000A918  48 00 19 69 */	bl Jac_ShowHeap__FP7jaheap_Ul
/* 8000D9BC 0000A91C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000D9C0 0000A920  38 21 00 08 */	addi r1, r1, 8
/* 8000D9C4 0000A924  7C 08 03 A6 */	mtlr r0
/* 8000D9C8 0000A928  4E 80 00 20 */	blr 
.endfn Show_AramMotherHeap__Fv

.balign 32, 0
.fn Collect_AramMotherHeap__Fv, global
/* 8000D9E0 0000A940  7C 08 02 A6 */	mflr r0
/* 8000D9E4 0000A944  3C 60 80 3E */	lis r3, aram_mother@ha
/* 8000D9E8 0000A948  90 01 00 04 */	stw r0, 4(r1)
/* 8000D9EC 0000A94C  38 63 AF A0 */	addi r3, r3, aram_mother@l
/* 8000D9F0 0000A950  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000D9F4 0000A954  48 00 18 4D */	bl Jac_GarbageCollection_St__FP7jaheap_
/* 8000D9F8 0000A958  4B FF FF A9 */	bl Show_AramMotherHeap__Fv
/* 8000D9FC 0000A95C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000DA00 0000A960  38 21 00 08 */	addi r1, r1, 8
/* 8000DA04 0000A964  7C 08 03 A6 */	mtlr r0
/* 8000DA08 0000A968  4E 80 00 20 */	blr 
.endfn Collect_AramMotherHeap__Fv

.balign 32, 0
.fn Init_AramMotherHeap__Fv, global
/* 8000DA20 0000A980  7C 08 02 A6 */	mflr r0
/* 8000DA24 0000A984  90 01 00 04 */	stw r0, 4(r1)
/* 8000DA28 0000A988  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8000DA2C 0000A98C  88 0D 2B EC */	lbz r0, init$65@sda21(r13)
/* 8000DA30 0000A990  7C 00 07 75 */	extsb. r0, r0
/* 8000DA34 0000A994  40 82 00 14 */	bne .L_8000DA48
/* 8000DA38 0000A998  38 60 00 00 */	li r3, 0
/* 8000DA3C 0000A99C  38 00 00 01 */	li r0, 1
/* 8000DA40 0000A9A0  90 6D 2B E8 */	stw r3, inited$64@sda21(r13)
/* 8000DA44 0000A9A4  98 0D 2B EC */	stb r0, init$65@sda21(r13)
.L_8000DA48:
/* 8000DA48 0000A9A8  80 0D 2B E8 */	lwz r0, inited$64@sda21(r13)
/* 8000DA4C 0000A9AC  2C 00 00 00 */	cmpwi r0, 0
/* 8000DA50 0000A9B0  40 82 00 2C */	bne .L_8000DA7C
/* 8000DA54 0000A9B4  38 00 00 01 */	li r0, 1
/* 8000DA58 0000A9B8  38 61 00 08 */	addi r3, r1, 8
/* 8000DA5C 0000A9BC  90 0D 2B E8 */	stw r0, inited$64@sda21(r13)
/* 8000DA60 0000A9C0  4B FF 87 61 */	bl ARAllocFull__FPUl
/* 8000DA64 0000A9C4  3C A0 80 3E */	lis r5, aram_mother@ha
/* 8000DA68 0000A9C8  38 83 00 00 */	addi r4, r3, 0
/* 8000DA6C 0000A9CC  38 65 AF A0 */	addi r3, r5, aram_mother@l
/* 8000DA70 0000A9D0  80 A1 00 08 */	lwz r5, 8(r1)
/* 8000DA74 0000A9D4  38 C0 00 00 */	li r6, 0
/* 8000DA78 0000A9D8  48 00 13 69 */	bl Jac_InitMotherHeap__FP7jaheap_UlUlUc
.L_8000DA7C:
/* 8000DA7C 0000A9DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8000DA80 0000A9E0  38 21 00 10 */	addi r1, r1, 0x10
/* 8000DA84 0000A9E4  7C 08 03 A6 */	mtlr r0
/* 8000DA88 0000A9E8  4E 80 00 20 */	blr 
.endfn Init_AramMotherHeap__Fv

.balign 32, 0
.fn LoadAram_Default__FPcUlUlPUlP7jaheap_, global
/* 8000DAA0 0000AA00  7C 08 02 A6 */	mflr r0
/* 8000DAA4 0000AA04  90 01 00 04 */	stw r0, 4(r1)
/* 8000DAA8 0000AA08  94 21 FF 40 */	stwu r1, -0xc0(r1)
/* 8000DAAC 0000AA0C  BF 61 00 AC */	stmw r27, 0xac(r1)
/* 8000DAB0 0000AA10  3B 63 00 00 */	addi r27, r3, 0
/* 8000DAB4 0000AA14  3B 84 00 00 */	addi r28, r4, 0
/* 8000DAB8 0000AA18  3B A5 00 00 */	addi r29, r5, 0
/* 8000DABC 0000AA1C  3B C6 00 00 */	addi r30, r6, 0
/* 8000DAC0 0000AA20  3B E7 00 00 */	addi r31, r7, 0
/* 8000DAC4 0000AA24  80 0D 80 3C */	lwz r0, first@sda21(r13)
/* 8000DAC8 0000AA28  2C 00 00 00 */	cmpwi r0, 0
/* 8000DACC 0000AA2C  41 82 00 10 */	beq .L_8000DADC
/* 8000DAD0 0000AA30  4B FF FF 51 */	bl Init_AramMotherHeap__Fv
/* 8000DAD4 0000AA34  38 00 00 00 */	li r0, 0
/* 8000DAD8 0000AA38  90 0D 80 3C */	stw r0, first@sda21(r13)
.L_8000DADC:
/* 8000DADC 0000AA3C  3C 80 80 22 */	lis r4, extdir@ha
/* 8000DAE0 0000AA40  38 61 00 1C */	addi r3, r1, 0x1c
/* 8000DAE4 0000AA44  38 84 50 28 */	addi r4, r4, extdir@l
/* 8000DAE8 0000AA48  48 20 B8 71 */	bl strcpy
/* 8000DAEC 0000AA4C  38 61 00 1C */	addi r3, r1, 0x1c
/* 8000DAF0 0000AA50  38 9B 00 00 */	addi r4, r27, 0
/* 8000DAF4 0000AA54  48 20 B7 F5 */	bl strcat
/* 8000DAF8 0000AA58  28 1C 00 00 */	cmplwi r28, 0
/* 8000DAFC 0000AA5C  40 82 00 4C */	bne .L_8000DB48
/* 8000DB00 0000AA60  28 1D 00 00 */	cmplwi r29, 0
/* 8000DB04 0000AA64  40 82 00 44 */	bne .L_8000DB48
/* 8000DB08 0000AA68  38 61 00 1C */	addi r3, r1, 0x1c
/* 8000DB0C 0000AA6C  4B FF A3 75 */	bl DVDT_CheckFile__FPc
/* 8000DB10 0000AA70  3C 80 80 3E */	lis r4, aram_mother@ha
/* 8000DB14 0000AA74  38 A3 00 00 */	addi r5, r3, 0
/* 8000DB18 0000AA78  38 84 AF A0 */	addi r4, r4, aram_mother@l
/* 8000DB1C 0000AA7C  38 7F 00 00 */	addi r3, r31, 0
/* 8000DB20 0000AA80  48 00 13 21 */	bl Jac_AllocHeap__FP7jaheap_P7jaheap_Ul
/* 8000DB24 0000AA84  2C 03 00 00 */	cmpwi r3, 0
/* 8000DB28 0000AA88  40 82 00 0C */	bne .L_8000DB34
/* 8000DB2C 0000AA8C  38 60 00 00 */	li r3, 0
/* 8000DB30 0000AA90  48 00 00 54 */	b .L_8000DB84
.L_8000DB34:
/* 8000DB34 0000AA94  80 BF 00 08 */	lwz r5, 8(r31)
/* 8000DB38 0000AA98  38 9E 00 00 */	addi r4, r30, 0
/* 8000DB3C 0000AA9C  38 61 00 1C */	addi r3, r1, 0x1c
/* 8000DB40 0000AAA0  4B FF FD 61 */	bl LoadAram__FPcPUlUl
/* 8000DB44 0000AAA4  48 00 00 40 */	b .L_8000DB84
.L_8000DB48:
/* 8000DB48 0000AAA8  3C 80 80 3E */	lis r4, aram_mother@ha
/* 8000DB4C 0000AAAC  38 7F 00 00 */	addi r3, r31, 0
/* 8000DB50 0000AAB0  38 84 AF A0 */	addi r4, r4, aram_mother@l
/* 8000DB54 0000AAB4  38 BD 00 00 */	addi r5, r29, 0
/* 8000DB58 0000AAB8  48 00 12 E9 */	bl Jac_AllocHeap__FP7jaheap_P7jaheap_Ul
/* 8000DB5C 0000AABC  2C 03 00 00 */	cmpwi r3, 0
/* 8000DB60 0000AAC0  40 82 00 0C */	bne .L_8000DB6C
/* 8000DB64 0000AAC4  38 60 00 00 */	li r3, 0
/* 8000DB68 0000AAC8  48 00 00 1C */	b .L_8000DB84
.L_8000DB6C:
/* 8000DB6C 0000AACC  80 FF 00 08 */	lwz r7, 8(r31)
/* 8000DB70 0000AAD0  38 9C 00 00 */	addi r4, r28, 0
/* 8000DB74 0000AAD4  38 BD 00 00 */	addi r5, r29, 0
/* 8000DB78 0000AAD8  38 DE 00 00 */	addi r6, r30, 0
/* 8000DB7C 0000AADC  38 61 00 1C */	addi r3, r1, 0x1c
/* 8000DB80 0000AAE0  4B FF FD A1 */	bl LoadAramSingle__FPcUlUlPUlUl
.L_8000DB84:
/* 8000DB84 0000AAE4  BB 61 00 AC */	lmw r27, 0xac(r1)
/* 8000DB88 0000AAE8  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 8000DB8C 0000AAEC  38 21 00 C0 */	addi r1, r1, 0xc0
/* 8000DB90 0000AAF0  7C 08 03 A6 */	mtlr r0
/* 8000DB94 0000AAF4  4E 80 00 20 */	blr 
.endfn LoadAram_Default__FPcUlUlPUlP7jaheap_

.balign 32, 0
.fn LoadAram_All__FPcPUlP7jaheap_, global
/* 8000DBA0 0000AB00  7C 08 02 A6 */	mflr r0
/* 8000DBA4 0000AB04  38 C4 00 00 */	addi r6, r4, 0
/* 8000DBA8 0000AB08  90 01 00 04 */	stw r0, 4(r1)
/* 8000DBAC 0000AB0C  38 E5 00 00 */	addi r7, r5, 0
/* 8000DBB0 0000AB10  38 80 00 00 */	li r4, 0
/* 8000DBB4 0000AB14  38 A0 00 00 */	li r5, 0
/* 8000DBB8 0000AB18  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000DBBC 0000AB1C  81 8D 80 38 */	lwz r12, ARCALL@sda21(r13)
/* 8000DBC0 0000AB20  7D 88 03 A6 */	mtlr r12
/* 8000DBC4 0000AB24  4E 80 00 21 */	blrl 
/* 8000DBC8 0000AB28  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000DBCC 0000AB2C  38 21 00 08 */	addi r1, r1, 8
/* 8000DBD0 0000AB30  7C 08 03 A6 */	mtlr r0
/* 8000DBD4 0000AB34  4E 80 00 20 */	blr 
.endfn LoadAram_All__FPcPUlP7jaheap_

.balign 32, 0
.fn LoadAram_One__FPcUlUlPUlP7jaheap_, global
/* 8000DBE0 0000AB40  7C 08 02 A6 */	mflr r0
/* 8000DBE4 0000AB44  90 01 00 04 */	stw r0, 4(r1)
/* 8000DBE8 0000AB48  94 21 FF F8 */	stwu r1, -8(r1)
/* 8000DBEC 0000AB4C  81 8D 80 38 */	lwz r12, ARCALL@sda21(r13)
/* 8000DBF0 0000AB50  7D 88 03 A6 */	mtlr r12
/* 8000DBF4 0000AB54  4E 80 00 21 */	blrl 
/* 8000DBF8 0000AB58  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8000DBFC 0000AB5C  38 21 00 08 */	addi r1, r1, 8
/* 8000DC00 0000AB60  7C 08 03 A6 */	mtlr r0
/* 8000DC04 0000AB64  4E 80 00 20 */	blr 
.endfn LoadAram_One__FPcUlUlPUlP7jaheap_

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj extdir, local
	.asciz "/Banks/"
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
.endobj extdir

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj ARCALL, local
	.4byte LoadAram_Default__FPcUlUlPUlP7jaheap_
.endobj ARCALL
.obj first, local
	.4byte 1
.endobj first

.section .sbss, "wa"
.balign 8
.obj inited$64, local
	.skip 4
.endobj inited$64
.obj init$65, local
	.skip 1
.endobj init$65

.section .bss, "wa"  # 0x802E9640 - 0x803E81E5
.comm aram_mother, 0x2C, 4
