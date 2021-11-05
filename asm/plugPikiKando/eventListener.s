.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 800D2BDC 000CFB3C  4E 80 00 21 */	blrl 
/* 800D2BE0 000CFB40  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800D2BE4 000CFB44  41 82 01 04 */	beq lbl_800D2CE8
/* 800D2BE8 000CFB48  80 1D 00 C8 */	lwz r0, 0xc8(r29)
/* 800D2BEC 000CFB4C  54 00 06 73 */	rlwinm. r0, r0, 0, 0x19, 0x19
/* 800D2BF0 000CFB50  40 82 00 F8 */	bne lbl_800D2CE8
/* 800D2BF4 000CFB54  C0 7D 00 98 */	lfs f3, 0x98(r29)
/* 800D2BF8 000CFB58  C0 5F 00 98 */	lfs f2, 0x98(r31)
/* 800D2BFC 000CFB5C  C0 3D 00 94 */	lfs f1, 0x94(r29)
/* 800D2C00 000CFB60  C0 1F 00 94 */	lfs f0, 0x94(r31)
/* 800D2C04 000CFB64  EC 63 10 28 */	fsubs f3, f3, f2
/* 800D2C08 000CFB68  C0 5D 00 9C */	lfs f2, 0x9c(r29)
/* 800D2C0C 000CFB6C  EC 81 00 28 */	fsubs f4, f1, f0
/* 800D2C10 000CFB70  C0 3F 00 9C */	lfs f1, 0x9c(r31)
/* 800D2C14 000CFB74  EC 03 00 F2 */	fmuls f0, f3, f3
/* 800D2C18 000CFB78  EC 42 08 28 */	fsubs f2, f2, f1
/* 800D2C1C 000CFB7C  EC 24 01 32 */	fmuls f1, f4, f4
/* 800D2C20 000CFB80  EC 42 00 B2 */	fmuls f2, f2, f2
/* 800D2C24 000CFB84  EC 01 00 2A */	fadds f0, f1, f0
/* 800D2C28 000CFB88  EC 42 00 2A */	fadds f2, f2, f0
/* 800D2C2C 000CFB8C  FC 02 E8 40 */	fcmpo cr0, f2, f29
/* 800D2C30 000CFB90  40 81 00 54 */	ble lbl_800D2C84
/* 800D2C34 000CFB94  FC 20 10 34 */	frsqrte f1, f2
/* 800D2C38 000CFB98  FC 01 00 72 */	fmul f0, f1, f1
/* 800D2C3C 000CFB9C  FC 3E 00 72 */	fmul f1, f30, f1
/* 800D2C40 000CFBA0  FC 02 00 32 */	fmul f0, f2, f0
/* 800D2C44 000CFBA4  FC 1F 00 28 */	fsub f0, f31, f0
/* 800D2C48 000CFBA8  FC 21 00 32 */	fmul f1, f1, f0
/* 800D2C4C 000CFBAC  FC 01 00 72 */	fmul f0, f1, f1
/* 800D2C50 000CFBB0  FC 3E 00 72 */	fmul f1, f30, f1
/* 800D2C54 000CFBB4  FC 02 00 32 */	fmul f0, f2, f0
/* 800D2C58 000CFBB8  FC 1F 00 28 */	fsub f0, f31, f0
/* 800D2C5C 000CFBBC  FC 21 00 32 */	fmul f1, f1, f0
/* 800D2C60 000CFBC0  FC 01 00 72 */	fmul f0, f1, f1
/* 800D2C64 000CFBC4  FC 3E 00 72 */	fmul f1, f30, f1
/* 800D2C68 000CFBC8  FC 02 00 32 */	fmul f0, f2, f0
/* 800D2C6C 000CFBCC  FC 1F 00 28 */	fsub f0, f31, f0
/* 800D2C70 000CFBD0  FC 01 00 32 */	fmul f0, f1, f0
/* 800D2C74 000CFBD4  FC 02 00 32 */	fmul f0, f2, f0
/* 800D2C78 000CFBD8  FC 00 00 18 */	frsp f0, f0
/* 800D2C7C 000CFBDC  D0 01 00 68 */	stfs f0, 0x68(r1)
/* 800D2C80 000CFBE0  C0 41 00 68 */	lfs f2, 0x68(r1)
lbl_800D2C84:
/* 800D2C84 000CFBE4  FC 02 E0 40 */	fcmpo cr0, f2, f28
/* 800D2C88 000CFBE8  40 80 00 60 */	bge lbl_800D2CE8
/* 800D2C8C 000CFBEC  80 7F 04 F8 */	lwz r3, 0x4f8(r31)
/* 800D2C90 000CFBF0  38 80 00 00 */	li r4, 0
/* 800D2C94 000CFBF4  4B FF 26 B1 */	bl abandon__9TopActionFPQ23zen17particleGenerator
/* 800D2C98 000CFBF8  80 7F 04 F8 */	lwz r3, 0x4f8(r31)
/* 800D2C9C 000CFBFC  38 00 00 08 */	li r0, 8
/* 800D2CA0 000CFC00  38 9D 00 00 */	addi r4, r29, 0
/* 800D2CA4 000CFC04  B0 03 00 08 */	sth r0, 8(r3)
/* 800D2CA8 000CFC08  80 7F 04 F8 */	lwz r3, 0x4f8(r31)
/* 800D2CAC 000CFC0C  A8 03 00 08 */	lha r0, 8(r3)
/* 800D2CB0 000CFC10  80 63 00 04 */	lwz r3, 4(r3)
/* 800D2CB4 000CFC14  54 00 18 38 */	slwi r0, r0, 3
/* 800D2CB8 000CFC18  7C 63 02 14 */	add r3, r3, r0
/* 800D2CBC 000CFC1C  4B FF 10 69 */	bl initialise__Q26Action5ChildFP8Creature
/* 800D2CC0 000CFC20  38 00 00 02 */	li r0, 2
/* 800D2CC4 000CFC24  B0 1F 04 FC */	sth r0, 0x4fc(r31)
/* 800D2CC8 000CFC28  38 7E 00 00 */	addi r3, r30, 0

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 801E8D0C 001E5C6C  EC 02 00 28 */	fsubs f0, f2, f0
lbl_801E8D10:
/* 801E8D10 001E5C70  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 801E8D14 001E5C74  FC 00 00 1E */	fctiwz f0, f0
/* 801E8D18 001E5C78  81 83 00 00 */	lwz r12, 0(r3)
/* 801E8D1C 001E5C7C  D8 01 00 48 */	stfd f0, 0x48(r1)
/* 801E8D20 001E5C80  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 801E8D24 001E5C84  80 81 00 4C */	lwz r4, 0x4c(r1)
/* 801E8D28 001E5C88  7D 88 03 A6 */	mtlr r12
/* 801E8D2C 001E5C8C  4E 80 00 21 */	blrl 
/* 801E8D30 001E5C90  48 02 F3 41 */	bl rand
/* 801E8D34 001E5C94  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 801E8D38 001E5C98  C8 82 BF C8 */	lfd f4, "@807"@sda21(r2)
/* 801E8D3C 001E5C9C  90 01 00 44 */	stw r0, 0x44(r1)
/* 801E8D40 001E5CA0  3C 00 43 30 */	lis r0, 0x4330
/* 801E8D44 001E5CA4  C0 42 BF BC */	lfs f2, lbl_803EC1BC@sda21(r2)
/* 801E8D48 001E5CA8  90 01 00 40 */	stw r0, 0x40(r1)
/* 801E8D4C 001E5CAC  C0 22 BF B8 */	lfs f1, lbl_803EC1B8@sda21(r2)
/* 801E8D50 001E5CB0  C8 61 00 40 */	lfd f3, 0x40(r1)
/* 801E8D54 001E5CB4  C0 02 BF C0 */	lfs f0, lbl_803EC1C0@sda21(r2)
/* 801E8D58 001E5CB8  EC 63 20 28 */	fsubs f3, f3, f4
/* 801E8D5C 001E5CBC  EC 43 10 24 */	fdivs f2, f3, f2
/* 801E8D60 001E5CC0  EC 21 00 B2 */	fmuls f1, f1, f2
/* 801E8D64 001E5CC4  EC 01 00 28 */	fsubs f0, f1, f0
/* 801E8D68 001E5CC8  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 801E8D6C 001E5CCC  C0 02 BF A8 */	lfs f0, lbl_803EC1A8@sda21(r2)
/* 801E8D70 001E5CD0  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 801E8D74 001E5CD4  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 801E8D78 001E5CD8  D0 1F 00 2C */	stfs f0, 0x2c(r31)
lbl_801E8D7C:
/* 801E8D7C 001E5CDC  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 801E8D80 001E5CE0  83 E1 00 54 */	lwz r31, 0x54(r1)
/* 801E8D84 001E5CE4  38 21 00 58 */	addi r1, r1, 0x58
/* 801E8D88 001E5CE8  7C 08 03 A6 */	mtlr r0
/* 801E8D8C 001E5CEC  4E 80 00 20 */	blr 

.global __ct__Q23zen18DrawGameOverLetterFv
__ct__Q23zen18DrawGameOverLetterFv:
/* 801E8D90 001E5CF0  38 00 00 00 */	li r0, 0
/* 801E8D94 001E5CF4  90 03 00 00 */	stw r0, 0(r3)
/* 801E8D98 001E5CF8  90 03 00 0C */	stw r0, 0xc(r3)
/* 801E8D9C 001E5CFC  90 03 00 10 */	stw r0, 0x10(r3)
/* 801E8DA0 001E5D00  90 03 00 14 */	stw r0, 0x14(r3)
/* 801E8DA4 001E5D04  C0 02 BF A8 */	lfs f0, lbl_803EC1A8@sda21(r2)
/* 801E8DA8 001E5D08  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 801E8DAC 001E5D0C  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 801E8DB0 001E5D10  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 801E8DB4 001E5D14  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 801E8DB8 001E5D18  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 801E8DBC 001E5D1C  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 801E8DC0 001E5D20  D0 03 00 04 */	stfs f0, 4(r3)
/* 801E8DC4 001E5D24  D0 03 00 08 */	stfs f0, 8(r3)
/* 801E8DC8 001E5D28  4E 80 00 20 */	blr 

.global start__Q23zen12DrawGameOverFQ33zen12DrawGameOver8modeFlagf
start__Q23zen12DrawGameOverFQ33zen12DrawGameOver8modeFlagf:
/* 801E8DCC 001E5D2C  7C 08 02 A6 */	mflr r0
/* 801E8DD0 001E5D30  90 01 00 04 */	stw r0, 4(r1)
/* 801E8DD4 001E5D34  38 00 00 01 */	li r0, 1
/* 801E8DD8 001E5D38  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 801E8DDC 001E5D3C  DB E1 00 48 */	stfd f31, 0x48(r1)
/* 801E8DE0 001E5D40  DB C1 00 40 */	stfd f30, 0x40(r1)
/* 801E8DE4 001E5D44  DB A1 00 38 */	stfd f29, 0x38(r1)
/* 801E8DE8 001E5D48  BF 41 00 20 */	stmw r26, 0x20(r1)
/* 801E8DEC 001E5D4C  90 03 00 00 */	stw r0, 0(r3)
/* 801E8DF0 001E5D50  90 83 00 10 */	stw r4, 0x10(r3)
/* 801E8DF4 001E5D54  D0 23 00 18 */	stfs f1, 0x18(r3)
/* 801E8DF8 001E5D58  80 03 00 10 */	lwz r0, 0x10(r3)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x6576656e
  .4byte 0x744c6973
  .4byte 0x74656e65
  .4byte 0x722e6370
  .4byte 0x70000000
  .4byte 0x6576656e
  .4byte 0x744c6973
  .4byte 0x74656e65
  .4byte 0x72000000
.global lbl_802AF9D4
lbl_802AF9D4:
	.4byte 0x436F7265
	.4byte 0x4E6F6465
	.4byte 0x00000000
.global lbl_802AF9E0
lbl_802AF9E0:
	.4byte 0x6576656E
	.4byte 0x744C6973
	.4byte 0x74656E65
	.4byte 0x72730000
	.4byte 0x4576656E
	.4byte 0x744C6973
	.4byte 0x74656E65
	.4byte 0x72000000
	.4byte 0x803DF300
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x803DF300
	.4byte 0x00000000
	.4byte 0x803DF308
	.4byte 0x00000000
	.4byte 0x00000000
.global __vt__13EventListener
__vt__13EventListener:
  .4byte __RTTI__13EventListener
  .4byte 0
  .4byte getAgeNodeType__5ANodeFv
  .4byte read__8CoreNodeFR18RandomAccessStream
  .4byte gotEvent__13EventListenerFR5Event
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0
  .4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
	.4byte 0x00000000
	.4byte 0x802AF928
	.4byte 0x00000000
	.4byte 0x414E6F64
	.4byte 0x65000000
	.4byte 0x803DF2D4
	.4byte 0x00000000
	.4byte 0x802AF740
