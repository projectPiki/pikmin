.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global makeObjectNavi__Fv
makeObjectNavi__Fv:
/* 800F8130 000F5090  7C 08 02 A6 */	mflr r0
/* 800F8134 000F5094  38 60 00 18 */	li r3, 0x18
/* 800F8138 000F5098  90 01 00 04 */	stw r0, 4(r1)
/* 800F813C 000F509C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F8140 000F50A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F8144 000F50A4  4B F4 EE C1 */	bl alloc__6SystemFUl
/* 800F8148 000F50A8  3B E3 00 00 */	addi r31, r3, 0
/* 800F814C 000F50AC  7F E3 FB 79 */	or. r3, r31, r31
/* 800F8150 000F50B0  41 82 00 38 */	beq lbl_800F8188
/* 800F8154 000F50B4  3C 80 80 2C */	lis r4, lbl_802BFFD0@ha
/* 800F8158 000F50B8  3C A0 80 2C */	lis r5, lbl_802BFFC4@ha
/* 800F815C 000F50BC  38 C4 FF D0 */	addi r6, r4, lbl_802BFFD0@l
/* 800F8160 000F50C0  3C 80 6E 61 */	lis r4, 0x6E617669@ha
/* 800F8164 000F50C4  38 A5 FF C4 */	addi r5, r5, lbl_802BFFC4@l
/* 800F8168 000F50C8  38 84 76 69 */	addi r4, r4, 0x6E617669@l
/* 800F816C 000F50CC  4B FE 2B 49 */	bl __ct__7GenBaseFUlPcPc
/* 800F8170 000F50D0  3C 60 80 2C */	lis r3, __vt__9GenObject@ha
/* 800F8174 000F50D4  38 03 AB 70 */	addi r0, r3, __vt__9GenObject@l
/* 800F8178 000F50D8  3C 60 80 2C */	lis r3, __vt__13GenObjectNavi@ha
/* 800F817C 000F50DC  90 1F 00 04 */	stw r0, 4(r31)
/* 800F8180 000F50E0  38 03 00 60 */	addi r0, r3, __vt__13GenObjectNavi@l
/* 800F8184 000F50E4  90 1F 00 04 */	stw r0, 4(r31)
lbl_800F8188:
/* 800F8188 000F50E8  7F E3 FB 78 */	mr r3, r31
/* 800F818C 000F50EC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F8190 000F50F0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F8194 000F50F4  38 21 00 10 */	addi r1, r1, 0x10
/* 800F8198 000F50F8  7C 08 03 A6 */	mtlr r0
/* 800F819C 000F50FC  4E 80 00 20 */	blr 

.global initialise__13GenObjectNaviFv
initialise__13GenObjectNaviFv:
/* 800F81A0 000F5100  80 ED 30 74 */	lwz r7, factory__16GenObjectFactory@sda21(r13)
/* 800F81A4 000F5104  80 A7 00 00 */	lwz r5, 0(r7)
/* 800F81A8 000F5108  80 07 00 04 */	lwz r0, 4(r7)
/* 800F81AC 000F510C  7C 05 00 00 */	cmpw r5, r0
/* 800F81B0 000F5110  4C 80 00 20 */	bgelr 
/* 800F81B4 000F5114  3C 80 6E 61 */	lis r4, 0x6E617669@ha
/* 800F81B8 000F5118  80 67 00 08 */	lwz r3, 8(r7)
/* 800F81BC 000F511C  38 84 76 69 */	addi r4, r4, 0x6E617669@l
/* 800F81C0 000F5120  54 A0 20 36 */	slwi r0, r5, 4
/* 800F81C4 000F5124  7C 83 01 2E */	stwx r4, r3, r0
/* 800F81C8 000F5128  3C C0 80 10 */	lis r6, makeObjectNavi__Fv@ha
/* 800F81CC 000F512C  3C 80 80 2C */	lis r4, lbl_802BFFE4@ha
/* 800F81D0 000F5130  80 07 00 00 */	lwz r0, 0(r7)
/* 800F81D4 000F5134  3C 60 76 30 */	lis r3, 0x76302E30@ha
/* 800F81D8 000F5138  80 A7 00 08 */	lwz r5, 8(r7)
/* 800F81DC 000F513C  38 C6 81 30 */	addi r6, r6, makeObjectNavi__Fv@l
/* 800F81E0 000F5140  54 00 20 36 */	slwi r0, r0, 4
/* 800F81E4 000F5144  7C A5 02 14 */	add r5, r5, r0
/* 800F81E8 000F5148  90 C5 00 04 */	stw r6, 4(r5)
/* 800F81EC 000F514C  38 A4 FF E4 */	addi r5, r4, lbl_802BFFE4@l
/* 800F81F0 000F5150  38 83 2E 30 */	addi r4, r3, 0x76302E30@l
/* 800F81F4 000F5154  80 07 00 00 */	lwz r0, 0(r7)
/* 800F81F8 000F5158  80 67 00 08 */	lwz r3, 8(r7)
/* 800F81FC 000F515C  54 00 20 36 */	slwi r0, r0, 4
/* 800F8200 000F5160  7C 63 02 14 */	add r3, r3, r0
/* 800F8204 000F5164  90 A3 00 08 */	stw r5, 8(r3)
/* 800F8208 000F5168  80 07 00 00 */	lwz r0, 0(r7)
/* 800F820C 000F516C  80 67 00 08 */	lwz r3, 8(r7)
/* 800F8210 000F5170  54 00 20 36 */	slwi r0, r0, 4
/* 800F8214 000F5174  7C 63 02 14 */	add r3, r3, r0
/* 800F8218 000F5178  90 83 00 0C */	stw r4, 0xc(r3)
/* 800F821C 000F517C  80 67 00 00 */	lwz r3, 0(r7)
/* 800F8220 000F5180  38 03 00 01 */	addi r0, r3, 1
/* 800F8224 000F5184  90 07 00 00 */	stw r0, 0(r7)
/* 800F8228 000F5188  4E 80 00 20 */	blr 

.global doRead__13GenObjectNaviFR18RandomAccessStream
doRead__13GenObjectNaviFR18RandomAccessStream:
/* 800F822C 000F518C  4E 80 00 20 */	blr 

.global birth__13GenObjectNaviFR9BirthInfo
birth__13GenObjectNaviFR9BirthInfo:
/* 800F8230 000F5190  7C 08 02 A6 */	mflr r0
/* 800F8234 000F5194  90 01 00 04 */	stw r0, 4(r1)
/* 800F8238 000F5198  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 800F823C 000F519C  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800F8240 000F51A0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 800F8244 000F51A4  7C 9E 23 78 */	mr r30, r4
/* 800F8248 000F51A8  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 800F824C 000F51AC  81 83 00 00 */	lwz r12, 0(r3)
/* 800F8250 000F51B0  81 8C 00 78 */	lwz r12, 0x78(r12)
/* 800F8254 000F51B4  7D 88 03 A6 */	mtlr r12
/* 800F8258 000F51B8  4E 80 00 21 */	blrl 
/* 800F825C 000F51BC  7C 7F 1B 79 */	or. r31, r3, r3
/* 800F8260 000F51C0  41 82 00 6C */	beq lbl_800F82CC
/* 800F8264 000F51C4  81 9F 00 00 */	lwz r12, 0(r31)
/* 800F8268 000F51C8  38 7F 00 00 */	addi r3, r31, 0
/* 800F826C 000F51CC  38 9E 00 00 */	addi r4, r30, 0
/* 800F8270 000F51D0  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 800F8274 000F51D4  7D 88 03 A6 */	mtlr r12
/* 800F8278 000F51D8  4E 80 00 21 */	blrl 
/* 800F827C 000F51DC  80 9E 00 0C */	lwz r4, 0xc(r30)
/* 800F8280 000F51E0  7F E3 FB 78 */	mr r3, r31
/* 800F8284 000F51E4  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 800F8288 000F51E8  90 9F 00 88 */	stw r4, 0x88(r31)
/* 800F828C 000F51EC  90 1F 00 8C */	stw r0, 0x8c(r31)
/* 800F8290 000F51F0  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 800F8294 000F51F4  90 1F 00 90 */	stw r0, 0x90(r31)
/* 800F8298 000F51F8  C0 1F 00 8C */	lfs f0, 0x8c(r31)
/* 800F829C 000F51FC  D0 1F 00 A0 */	stfs f0, 0xa0(r31)
/* 800F82A0 000F5200  48 00 1F E9 */	bl reset__4NaviFv
/* 800F82A4 000F5204  80 1E 00 24 */	lwz r0, 0x24(r30)
/* 800F82A8 000F5208  90 1F 00 64 */	stw r0, 0x64(r31)
/* 800F82AC 000F520C  80 6D 31 20 */	lwz r3, naviMgr@sda21(r13)
/* 800F82B0 000F5210  48 01 F1 15 */	bl getNavi__7NaviMgrFv
/* 800F82B4 000F5214  80 03 02 E8 */	lwz r0, 0x2e8(r3)
/* 800F82B8 000F5218  3C 60 80 3A */	lis r3, flowCont@ha
/* 800F82BC 000F521C  38 63 DB 20 */	addi r3, r3, flowCont@l
/* 800F82C0 000F5220  90 1F 02 E8 */	stw r0, 0x2e8(r31)
/* 800F82C4 000F5224  38 00 00 01 */	li r0, 1
/* 800F82C8 000F5228  90 03 02 30 */	stw r0, 0x230(r3)
lbl_800F82CC:
/* 800F82CC 000F522C  7F E3 FB 78 */	mr r3, r31
/* 800F82D0 000F5230  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 800F82D4 000F5234  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800F82D8 000F5238  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 800F82DC 000F523C  38 21 00 18 */	addi r1, r1, 0x18
/* 800F82E0 000F5240  7C 08 03 A6 */	mtlr r0
/* 800F82E4 000F5244  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802BFFB8:
	.asciz "genNavi.cpp"
.balign 4
lbl_802BFFC4:
	.asciz "object type"
.balign 4
lbl_802BFFD0:
	.4byte 0x8376838C
	.4byte 0x83438384
	.4byte 0x815B8251
	.4byte 0x82F090B6
	.4byte 0x82DE0000
.balign 4
lbl_802BFFE4:
	.asciz "generate NAVI (player2)"
.balign 4
lbl_802BFFFC:
	.asciz "GenObjectNavi"
.balign 4
lbl_802C000C:
	.asciz "Parameters"
.balign 4
lbl_802C0018:
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
lbl_802C0024:
	.asciz "GenObject"
.balign 4
lbl_802C0030:
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte __RTTI__7GenBase
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802C0044:
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte __RTTI__7GenBase
	.4byte 0x00000000
	.4byte __RTTI__9GenObject
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__13GenObjectNavi
__vt__13GenObjectNavi:
	.4byte __RTTI__13GenObjectNavi
	.4byte 0
	.4byte doWrite__7GenBaseFR18RandomAccessStream
	.4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
	.4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
	.4byte doRead__13GenObjectNaviFR18RandomAccessStream
	.4byte update__7GenBaseFv
	.4byte render__7GenBaseFR8Graphics
	.4byte getLatestVersion__9GenObjectFv
	.4byte updateUseList__9GenObjectFP9Generatori
	.4byte init__9GenObjectFP9Generator
	.4byte update__9GenObjectFP9Generator
	.4byte render__9GenObjectFR8GraphicsP9Generator
	.4byte birth__13GenObjectNaviFR9BirthInfo

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
__RTTI__10Parameters:
	.4byte lbl_802C000C
	.4byte 0
.balign 4
lbl_803E1F80:
	.asciz "GenBase"
.balign 4
__RTTI__7GenBase:
	.4byte lbl_803E1F80
	.4byte lbl_802C0018
__RTTI__9GenObject:
	.4byte lbl_802C0024
	.4byte lbl_802C0030
__RTTI__13GenObjectNavi:
	.4byte lbl_802BFFFC
	.4byte lbl_802C0044
