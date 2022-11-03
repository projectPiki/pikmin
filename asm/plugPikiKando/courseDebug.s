.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.global makeObjectDebug__Fv
makeObjectDebug__Fv:
/* 800864A8 00083408  7C 08 02 A6 */	mflr r0
/* 800864AC 0008340C  38 60 00 58 */	li r3, 0x58
/* 800864B0 00083410  90 01 00 04 */	stw r0, 4(r1)
/* 800864B4 00083414  94 21 FF A8 */	stwu r1, -0x58(r1)
/* 800864B8 00083418  93 E1 00 54 */	stw r31, 0x54(r1)
/* 800864BC 0008341C  93 C1 00 50 */	stw r30, 0x50(r1)
/* 800864C0 00083420  93 A1 00 4C */	stw r29, 0x4c(r1)
/* 800864C4 00083424  4B FC 0B 41 */	bl alloc__6SystemFUl
/* 800864C8 00083428  7C 7F 1B 79 */	or. r31, r3, r3
/* 800864CC 0008342C  41 82 00 E8 */	beq .L_800865B4
/* 800864D0 00083430  3C 80 80 2B */	lis r4, lbl_802AEE54@ha
/* 800864D4 00083434  3C 60 80 2B */	lis r3, lbl_802AEE60@ha
/* 800864D8 00083438  38 A4 EE 54 */	addi r5, r4, lbl_802AEE54@l
/* 800864DC 0008343C  3C 80 64 65 */	lis r4, 0x64656267@ha
/* 800864E0 00083440  38 C3 EE 60 */	addi r6, r3, lbl_802AEE60@l
/* 800864E4 00083444  38 7F 00 00 */	addi r3, r31, 0
/* 800864E8 00083448  38 84 62 67 */	addi r4, r4, 0x64656267@l
/* 800864EC 0008344C  48 05 47 C9 */	bl __ct__7GenBaseFUlPcPc
/* 800864F0 00083450  3C 60 80 2C */	lis r3, __vt__9GenObject@ha
/* 800864F4 00083454  38 03 AB 70 */	addi r0, r3, __vt__9GenObject@l
/* 800864F8 00083458  3C 60 80 2B */	lis r3, __vt__14GenObjectDebug@ha
/* 800864FC 0008345C  90 1F 00 04 */	stw r0, 4(r31)
/* 80086500 00083460  38 03 EE D4 */	addi r0, r3, __vt__14GenObjectDebug@l
/* 80086504 00083464  90 1F 00 04 */	stw r0, 4(r31)
/* 80086508 00083468  38 A1 00 24 */	addi r5, r1, 0x24
/* 8008650C 0008346C  38 9F 00 00 */	addi r4, r31, 0
/* 80086510 00083470  80 0D A1 30 */	lwz r0, lbl_803DEE50@sda21(r13)
/* 80086514 00083474  38 7F 00 18 */	addi r3, r31, 0x18
/* 80086518 00083478  90 01 00 2C */	stw r0, 0x2c(r1)
/* 8008651C 0008347C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80086520 00083480  90 01 00 24 */	stw r0, 0x24(r1)
/* 80086524 00083484  4B FD 85 5D */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80086528 00083488  3C 60 80 2A */	lis r3, "__vt__7Parm<i>"@ha
/* 8008652C 0008348C  3B A3 60 C4 */	addi r29, r3, "__vt__7Parm<i>"@l
/* 80086530 00083490  93 BF 00 20 */	stw r29, 0x20(r31)
/* 80086534 00083494  3B C0 00 00 */	li r30, 0
/* 80086538 00083498  38 A1 00 20 */	addi r5, r1, 0x20
/* 8008653C 0008349C  93 DF 00 24 */	stw r30, 0x24(r31)
/* 80086540 000834A0  7F E4 FB 78 */	mr r4, r31
/* 80086544 000834A4  38 7F 00 28 */	addi r3, r31, 0x28
/* 80086548 000834A8  80 0D A1 34 */	lwz r0, lbl_803DEE54@sda21(r13)
/* 8008654C 000834AC  90 01 00 34 */	stw r0, 0x34(r1)
/* 80086550 000834B0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80086554 000834B4  90 01 00 20 */	stw r0, 0x20(r1)
/* 80086558 000834B8  4B FD 85 29 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 8008655C 000834BC  93 BF 00 30 */	stw r29, 0x30(r31)
/* 80086560 000834C0  38 A1 00 1C */	addi r5, r1, 0x1c
/* 80086564 000834C4  38 9F 00 00 */	addi r4, r31, 0
/* 80086568 000834C8  93 DF 00 34 */	stw r30, 0x34(r31)
/* 8008656C 000834CC  38 7F 00 38 */	addi r3, r31, 0x38
/* 80086570 000834D0  80 0D A1 38 */	lwz r0, lbl_803DEE58@sda21(r13)
/* 80086574 000834D4  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80086578 000834D8  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 8008657C 000834DC  90 01 00 1C */	stw r0, 0x1c(r1)
/* 80086580 000834E0  4B FD 85 01 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 80086584 000834E4  93 BF 00 40 */	stw r29, 0x40(r31)
/* 80086588 000834E8  38 A1 00 18 */	addi r5, r1, 0x18
/* 8008658C 000834EC  38 9F 00 00 */	addi r4, r31, 0
/* 80086590 000834F0  93 DF 00 44 */	stw r30, 0x44(r31)
/* 80086594 000834F4  38 7F 00 48 */	addi r3, r31, 0x48
/* 80086598 000834F8  80 0D A1 3C */	lwz r0, lbl_803DEE5C@sda21(r13)
/* 8008659C 000834FC  90 01 00 44 */	stw r0, 0x44(r1)
/* 800865A0 00083500  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800865A4 00083504  90 01 00 18 */	stw r0, 0x18(r1)
/* 800865A8 00083508  4B FD 84 D9 */	bl __ct__8BaseParmFP10Parameters5ayuID
/* 800865AC 0008350C  93 BF 00 50 */	stw r29, 0x50(r31)
/* 800865B0 00083510  93 DF 00 54 */	stw r30, 0x54(r31)
.L_800865B4:
/* 800865B4 00083514  7F E3 FB 78 */	mr r3, r31
/* 800865B8 00083518  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 800865BC 0008351C  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 800865C0 00083520  83 C1 00 50 */	lwz r30, 0x50(r1)
/* 800865C4 00083524  83 A1 00 4C */	lwz r29, 0x4c(r1)
/* 800865C8 00083528  38 21 00 58 */	addi r1, r1, 0x58
/* 800865CC 0008352C  7C 08 03 A6 */	mtlr r0
/* 800865D0 00083530  4E 80 00 20 */	blr 

.global initialise__14GenObjectDebugFv
initialise__14GenObjectDebugFv:
/* 800865D4 00083534  80 ED 30 74 */	lwz r7, factory__16GenObjectFactory@sda21(r13)
/* 800865D8 00083538  80 A7 00 00 */	lwz r5, 0(r7)
/* 800865DC 0008353C  80 07 00 04 */	lwz r0, 4(r7)
/* 800865E0 00083540  7C 05 00 00 */	cmpw r5, r0
/* 800865E4 00083544  4C 80 00 20 */	bgelr 
/* 800865E8 00083548  3C 80 64 65 */	lis r4, 0x64656267@ha
/* 800865EC 0008354C  80 67 00 08 */	lwz r3, 8(r7)
/* 800865F0 00083550  38 84 62 67 */	addi r4, r4, 0x64656267@l
/* 800865F4 00083554  54 A0 20 36 */	slwi r0, r5, 4
/* 800865F8 00083558  7C 83 01 2E */	stwx r4, r3, r0
/* 800865FC 0008355C  3C C0 80 08 */	lis r6, makeObjectDebug__Fv@ha
/* 80086600 00083560  3C 80 80 2B */	lis r4, lbl_802AEE60@ha
/* 80086604 00083564  80 07 00 00 */	lwz r0, 0(r7)
/* 80086608 00083568  3C 60 76 30 */	lis r3, 0x76302E30@ha
/* 8008660C 0008356C  80 A7 00 08 */	lwz r5, 8(r7)
/* 80086610 00083570  38 C6 64 A8 */	addi r6, r6, makeObjectDebug__Fv@l
/* 80086614 00083574  54 00 20 36 */	slwi r0, r0, 4
/* 80086618 00083578  7C A5 02 14 */	add r5, r5, r0
/* 8008661C 0008357C  90 C5 00 04 */	stw r6, 4(r5)
/* 80086620 00083580  38 A4 EE 60 */	addi r5, r4, lbl_802AEE60@l
/* 80086624 00083584  38 83 2E 30 */	addi r4, r3, 0x76302E30@l
/* 80086628 00083588  80 07 00 00 */	lwz r0, 0(r7)
/* 8008662C 0008358C  80 67 00 08 */	lwz r3, 8(r7)
/* 80086630 00083590  54 00 20 36 */	slwi r0, r0, 4
/* 80086634 00083594  7C 63 02 14 */	add r3, r3, r0
/* 80086638 00083598  90 A3 00 08 */	stw r5, 8(r3)
/* 8008663C 0008359C  80 07 00 00 */	lwz r0, 0(r7)
/* 80086640 000835A0  80 67 00 08 */	lwz r3, 8(r7)
/* 80086644 000835A4  54 00 20 36 */	slwi r0, r0, 4
/* 80086648 000835A8  7C 63 02 14 */	add r3, r3, r0
/* 8008664C 000835AC  90 83 00 0C */	stw r4, 0xc(r3)
/* 80086650 000835B0  80 67 00 00 */	lwz r3, 0(r7)
/* 80086654 000835B4  38 03 00 01 */	addi r0, r3, 1
/* 80086658 000835B8  90 07 00 00 */	stw r0, 0(r7)
/* 8008665C 000835BC  4E 80 00 20 */	blr 

.global doRead__14GenObjectDebugFR18RandomAccessStream
doRead__14GenObjectDebugFR18RandomAccessStream:
/* 80086660 000835C0  4E 80 00 20 */	blr 

.global birth__14GenObjectDebugFR9BirthInfo
birth__14GenObjectDebugFR9BirthInfo:
/* 80086664 000835C4  80 03 00 24 */	lwz r0, 0x24(r3)
/* 80086668 000835C8  90 0D 2F D8 */	stw r0, collision__11CourseDebug@sda21(r13)
/* 8008666C 000835CC  80 03 00 34 */	lwz r0, 0x34(r3)
/* 80086670 000835D0  90 0D 2F DC */	stw r0, pikiNoAttack__11CourseDebug@sda21(r13)
/* 80086674 000835D4  80 03 00 44 */	lwz r0, 0x44(r3)
/* 80086678 000835D8  90 0D 2F E0 */	stw r0, noCarryover__11CourseDebug@sda21(r13)
/* 8008667C 000835DC  80 03 00 54 */	lwz r0, 0x54(r3)
/* 80086680 000835E0  38 60 00 00 */	li r3, 0
/* 80086684 000835E4  90 0D 2F E4 */	stw r0, pelletDebug__11CourseDebug@sda21(r13)
/* 80086688 000835E8  4E 80 00 20 */	blr 

.global render__9GenObjectFR8GraphicsP9Generator
render__9GenObjectFR8GraphicsP9Generator:
/* 8008668C 000835EC  4E 80 00 20 */	blr 

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
lbl_802AEE38:
	.asciz "courseDebug.cpp"
.balign 4
lbl_802AEE48:
	.asciz "courseDebug"
.balign 4
lbl_802AEE54:
	.asciz "object type"
.balign 4
lbl_802AEE60:
	.asciz "Debug Switches"
.balign 4
lbl_802AEE70:
	.asciz "GenObjectDebug"
.balign 4
lbl_802AEE80:
	.asciz "Parameters"
.balign 4
lbl_802AEE8C:
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte 0x00000000
.balign 4
lbl_802AEE98:
	.asciz "GenObject"
.balign 4
lbl_802AEEA4:
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte __RTTI__7GenBase
	.4byte 0x00000000
	.4byte 0x00000000
lbl_802AEEB8:
	.4byte __RTTI__10Parameters
	.4byte 0x00000000
	.4byte __RTTI__7GenBase
	.4byte 0x00000000
	.4byte __RTTI__9GenObject
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__14GenObjectDebug
__vt__14GenObjectDebug:
	.4byte __RTTI__14GenObjectDebug
	.4byte 0
	.4byte doWrite__7GenBaseFR18RandomAccessStream
	.4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
	.4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
	.4byte doRead__14GenObjectDebugFR18RandomAccessStream
	.4byte update__7GenBaseFv
	.4byte render__7GenBaseFR8Graphics
	.4byte getLatestVersion__9GenObjectFv
	.4byte updateUseList__9GenObjectFP9Generatori
	.4byte init__9GenObjectFP9Generator
	.4byte update__9GenObjectFP9Generator
	.4byte render__9GenObjectFR8GraphicsP9Generator
	.4byte birth__14GenObjectDebugFR9BirthInfo
.balign 4
lbl_802AEF0C:
	.asciz "Parm<int>"
.balign 4
lbl_802AEF18:
	.asciz "BaseParm"
.balign 4
lbl_802AEF24:
	.4byte __RTTI__8BaseParm
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
lbl_803DEE50:
	.asciz "p00"
.balign 4
lbl_803DEE54:
	.asciz "p01"
.balign 4
lbl_803DEE58:
	.asciz "p02"
.balign 4
lbl_803DEE5C:
	.asciz "p03"
.balign 4
__RTTI__10Parameters:
	.4byte lbl_802AEE80
	.4byte 0
.balign 4
lbl_803DEE68:
	.asciz "GenBase"
.balign 4
__RTTI__7GenBase:
	.4byte lbl_803DEE68
	.4byte lbl_802AEE8C
__RTTI__9GenObject:
	.4byte lbl_802AEE98
	.4byte lbl_802AEEA4
__RTTI__14GenObjectDebug:
	.4byte lbl_802AEE70
	.4byte lbl_802AEEB8
__RTTI__8BaseParm:
	.4byte lbl_802AEF18
	.4byte 0

.section .sbss, "wa"
.balign 8
.global collision__11CourseDebug
collision__11CourseDebug:
	.skip 4
.global pikiNoAttack__11CourseDebug
pikiNoAttack__11CourseDebug:
	.skip 4
.global noCarryover__11CourseDebug
noCarryover__11CourseDebug:
	.skip 4
.global pelletDebug__11CourseDebug
pelletDebug__11CourseDebug:
	.skip 4
