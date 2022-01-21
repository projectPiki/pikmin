.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global reset__10ControllerFUl
reset__10ControllerFUl:
/* 800409B0 0003D910  38 00 FF FF */	li r0, -1
/* 800409B4 0003D914  90 03 00 3C */	stw r0, 0x3c(r3)
/* 800409B8 0003D918  38 00 00 00 */	li r0, 0
/* 800409BC 0003D91C  98 03 00 44 */	stb r0, 0x44(r3)
/* 800409C0 0003D920  90 83 00 38 */	stw r4, 0x38(r3)
/* 800409C4 0003D924  90 03 00 40 */	stw r0, 0x40(r3)
/* 800409C8 0003D928  90 03 00 20 */	stw r0, 0x20(r3)
/* 800409CC 0003D92C  90 03 00 24 */	stw r0, 0x24(r3)
/* 800409D0 0003D930  4E 80 00 20 */	blr 

.global updateCont__10ControllerFUl
updateCont__10ControllerFUl:
/* 800409D4 0003D934  80 A3 00 20 */	lwz r5, 0x20(r3)
/* 800409D8 0003D938  38 00 00 00 */	li r0, 0
/* 800409DC 0003D93C  90 A3 00 24 */	stw r5, 0x24(r3)
/* 800409E0 0003D940  90 03 00 20 */	stw r0, 0x20(r3)
/* 800409E4 0003D944  88 03 00 44 */	lbz r0, 0x44(r3)
/* 800409E8 0003D948  28 00 00 00 */	cmplwi r0, 0
/* 800409EC 0003D94C  40 82 00 08 */	bne lbl_800409F4
/* 800409F0 0003D950  90 83 00 20 */	stw r4, 0x20(r3)
lbl_800409F4:
/* 800409F4 0003D954  80 83 00 20 */	lwz r4, 0x20(r3)
/* 800409F8 0003D958  80 03 00 24 */	lwz r0, 0x24(r3)
/* 800409FC 0003D95C  7C 80 00 78 */	andc r0, r4, r0
/* 80040A00 0003D960  90 03 00 28 */	stw r0, 0x28(r3)
/* 80040A04 0003D964  80 83 00 24 */	lwz r4, 0x24(r3)
/* 80040A08 0003D968  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80040A0C 0003D96C  7C 80 00 78 */	andc r0, r4, r0
/* 80040A10 0003D970  90 03 00 2C */	stw r0, 0x2c(r3)
/* 80040A14 0003D974  80 83 00 40 */	lwz r4, 0x40(r3)
/* 80040A18 0003D978  28 04 00 00 */	cmplwi r4, 0
/* 80040A1C 0003D97C  41 82 00 30 */	beq lbl_80040A4C
/* 80040A20 0003D980  34 04 FF FF */	addic. r0, r4, -1
/* 80040A24 0003D984  90 03 00 40 */	stw r0, 0x40(r3)
/* 80040A28 0003D988  4D 82 00 20 */	beqlr 
/* 80040A2C 0003D98C  80 83 00 34 */	lwz r4, 0x34(r3)
/* 80040A30 0003D990  80 03 00 28 */	lwz r0, 0x28(r3)
/* 80040A34 0003D994  7C 80 00 39 */	and. r0, r4, r0
/* 80040A38 0003D998  90 03 00 30 */	stw r0, 0x30(r3)
/* 80040A3C 0003D99C  4D 82 00 20 */	beqlr 
/* 80040A40 0003D9A0  38 00 00 00 */	li r0, 0
/* 80040A44 0003D9A4  90 03 00 40 */	stw r0, 0x40(r3)
/* 80040A48 0003D9A8  4E 80 00 20 */	blr 
lbl_80040A4C:
/* 80040A4C 0003D9AC  38 00 00 00 */	li r0, 0
/* 80040A50 0003D9B0  90 03 00 30 */	stw r0, 0x30(r3)
/* 80040A54 0003D9B4  80 03 00 28 */	lwz r0, 0x28(r3)
/* 80040A58 0003D9B8  28 00 00 00 */	cmplwi r0, 0
/* 80040A5C 0003D9BC  90 03 00 34 */	stw r0, 0x34(r3)
/* 80040A60 0003D9C0  4D 82 00 20 */	beqlr 
/* 80040A64 0003D9C4  38 00 00 0A */	li r0, 0xa
/* 80040A68 0003D9C8  90 03 00 40 */	stw r0, 0x40(r3)
/* 80040A6C 0003D9CC  4E 80 00 20 */	blr 

.global update__10ControllerFv
update__10ControllerFv:
/* 80040A70 0003D9D0  7C 08 02 A6 */	mflr r0
/* 80040A74 0003D9D4  38 83 00 00 */	addi r4, r3, 0
/* 80040A78 0003D9D8  90 01 00 04 */	stw r0, 4(r1)
/* 80040A7C 0003D9DC  94 21 FF F8 */	stwu r1, -8(r1)
/* 80040A80 0003D9E0  80 AD 2D EC */	lwz r5, gsys@sda21(r13)
/* 80040A84 0003D9E4  38 65 02 7C */	addi r3, r5, 0x27c
/* 80040A88 0003D9E8  48 00 68 39 */	bl updateController__13ControllerMgrFP10Controller
/* 80040A8C 0003D9EC  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80040A90 0003D9F0  38 21 00 08 */	addi r1, r1, 8
/* 80040A94 0003D9F4  7C 08 03 A6 */	mtlr r0
/* 80040A98 0003D9F8  4E 80 00 20 */	blr 

.global getMainStickX__10ControllerFv
getMainStickX__10ControllerFv:
/* 80040A9C 0003D9FC  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80040AA0 0003DA00  3C 00 43 30 */	lis r0, 0x4330
/* 80040AA4 0003DA04  88 63 00 45 */	lbz r3, 0x45(r3)
/* 80040AA8 0003DA08  C8 42 84 00 */	lfd f2, lbl_803E8600@sda21(r2)
/* 80040AAC 0003DA0C  7C 63 07 74 */	extsb r3, r3
/* 80040AB0 0003DA10  C0 02 83 F8 */	lfs f0, lbl_803E85F8@sda21(r2)
/* 80040AB4 0003DA14  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80040AB8 0003DA18  90 61 00 14 */	stw r3, 0x14(r1)
/* 80040ABC 0003DA1C  90 01 00 10 */	stw r0, 0x10(r1)
/* 80040AC0 0003DA20  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 80040AC4 0003DA24  EC 21 10 28 */	fsubs f1, f1, f2
/* 80040AC8 0003DA28  EC 21 00 24 */	fdivs f1, f1, f0
/* 80040ACC 0003DA2C  38 21 00 18 */	addi r1, r1, 0x18
/* 80040AD0 0003DA30  4E 80 00 20 */	blr 

.global getMainStickY__10ControllerFv
getMainStickY__10ControllerFv:
/* 80040AD4 0003DA34  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80040AD8 0003DA38  3C 00 43 30 */	lis r0, 0x4330
/* 80040ADC 0003DA3C  88 63 00 46 */	lbz r3, 0x46(r3)
/* 80040AE0 0003DA40  C8 42 84 00 */	lfd f2, lbl_803E8600@sda21(r2)
/* 80040AE4 0003DA44  7C 63 07 74 */	extsb r3, r3
/* 80040AE8 0003DA48  C0 02 83 F8 */	lfs f0, lbl_803E85F8@sda21(r2)
/* 80040AEC 0003DA4C  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80040AF0 0003DA50  90 61 00 14 */	stw r3, 0x14(r1)
/* 80040AF4 0003DA54  90 01 00 10 */	stw r0, 0x10(r1)
/* 80040AF8 0003DA58  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 80040AFC 0003DA5C  EC 21 10 28 */	fsubs f1, f1, f2
/* 80040B00 0003DA60  EC 21 00 24 */	fdivs f1, f1, f0
/* 80040B04 0003DA64  38 21 00 18 */	addi r1, r1, 0x18
/* 80040B08 0003DA68  4E 80 00 20 */	blr 

.global getSubStickX__10ControllerFv
getSubStickX__10ControllerFv:
/* 80040B0C 0003DA6C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80040B10 0003DA70  3C 00 43 30 */	lis r0, 0x4330
/* 80040B14 0003DA74  88 63 00 47 */	lbz r3, 0x47(r3)
/* 80040B18 0003DA78  C8 42 84 00 */	lfd f2, lbl_803E8600@sda21(r2)
/* 80040B1C 0003DA7C  7C 63 07 74 */	extsb r3, r3
/* 80040B20 0003DA80  C0 02 83 F8 */	lfs f0, lbl_803E85F8@sda21(r2)
/* 80040B24 0003DA84  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80040B28 0003DA88  90 61 00 14 */	stw r3, 0x14(r1)
/* 80040B2C 0003DA8C  90 01 00 10 */	stw r0, 0x10(r1)
/* 80040B30 0003DA90  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 80040B34 0003DA94  EC 21 10 28 */	fsubs f1, f1, f2
/* 80040B38 0003DA98  EC 21 00 24 */	fdivs f1, f1, f0
/* 80040B3C 0003DA9C  38 21 00 18 */	addi r1, r1, 0x18
/* 80040B40 0003DAA0  4E 80 00 20 */	blr 

.global getSubStickY__10ControllerFv
getSubStickY__10ControllerFv:
/* 80040B44 0003DAA4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80040B48 0003DAA8  3C 00 43 30 */	lis r0, 0x4330
/* 80040B4C 0003DAAC  88 63 00 48 */	lbz r3, 0x48(r3)
/* 80040B50 0003DAB0  C8 42 84 00 */	lfd f2, lbl_803E8600@sda21(r2)
/* 80040B54 0003DAB4  7C 63 07 74 */	extsb r3, r3
/* 80040B58 0003DAB8  C0 02 83 F8 */	lfs f0, lbl_803E85F8@sda21(r2)
/* 80040B5C 0003DABC  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 80040B60 0003DAC0  90 61 00 14 */	stw r3, 0x14(r1)
/* 80040B64 0003DAC4  90 01 00 10 */	stw r0, 0x10(r1)
/* 80040B68 0003DAC8  C8 21 00 10 */	lfd f1, 0x10(r1)
/* 80040B6C 0003DACC  EC 21 10 28 */	fsubs f1, f1, f2
/* 80040B70 0003DAD0  EC 21 00 24 */	fdivs f1, f1, f0
/* 80040B74 0003DAD4  38 21 00 18 */	addi r1, r1, 0x18
/* 80040B78 0003DAD8  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_80228E50:
	.asciz "controller.cpp"
.balign 4
lbl_80228E60:
	.asciz "Controller"
.balign 4
lbl_80228E6C:
	.asciz "CoreNode"
.balign 4
lbl_80228E78:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte 0
lbl_80228E84:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte 0
lbl_80228E98:
	.4byte __RTTI__5ANode
	.4byte 0
	.4byte __RTTI__8CoreNode
	.4byte 0
	.4byte __RTTI__4Node
	.4byte 0
	.4byte 0
.global __vt__10Controller
__vt__10Controller:
	.4byte __RTTI__10Controller
	.4byte 0
	.4byte getAgeNodeType__5ANodeFv
	.4byte read__8CoreNodeFR18RandomAccessStream
	.4byte update__10ControllerFv
	.4byte draw__4NodeFR8Graphics
	.4byte render__4NodeFR8Graphics
	.4byte concat__4NodeFv
	.4byte concat__4NodeFR3VQS
	.4byte concat__4NodeFR3SRT
	.4byte concat__4NodeFR8Matrix4f
	.4byte getModelMatrix__4NodeFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DD3C0:
	.asciz "ANode"
.balign 4
__RTTI__5ANode:
	.4byte lbl_803DD3C0
	.4byte 0
__RTTI__8CoreNode:
	.4byte lbl_80228E6C
	.4byte lbl_80228E78
.balign 4
lbl_803DD3D8:
	.asciz "Node"
.balign 4
__RTTI__4Node:
	.4byte lbl_803DD3D8
	.4byte lbl_80228E84
__RTTI__10Controller:
	.4byte lbl_80228E60
	.4byte lbl_80228E98

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
lbl_803E85F8:
	.float 74.0
.balign 8
lbl_803E8600:
	.4byte 0x43300000
	.4byte 0x80000000
