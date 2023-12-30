.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn atan__Fff, global
/* 8011DB48 0011AAA8  94 21 FF D8 */	stwu r1, -0x28(r1)
/* 8011DB4C 0011AAAC  3C 60 80 2C */	lis r3, lbl_802C4378@ha
/* 8011DB50 0011AAB0  38 63 43 78 */	addi r3, r3, lbl_802C4378@l
/* 8011DB54 0011AAB4  C0 02 A0 40 */	lfs f0, lbl_803EA240@sda21(r2)
/* 8011DB58 0011AAB8  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8011DB5C 0011AABC  4C 41 13 82 */	cror 2, 1, 2
/* 8011DB60 0011AAC0  40 82 01 4C */	bne .L_8011DCAC
/* 8011DB64 0011AAC4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8011DB68 0011AAC8  4C 41 13 82 */	cror 2, 1, 2
/* 8011DB6C 0011AACC  40 82 00 9C */	bne .L_8011DC08
/* 8011DB70 0011AAD0  FC 01 10 40 */	fcmpo cr0, f1, f2
/* 8011DB74 0011AAD4  4C 41 13 82 */	cror 2, 1, 2
/* 8011DB78 0011AAD8  40 82 00 48 */	bne .L_8011DBC0
/* 8011DB7C 0011AADC  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 8011DB80 0011AAE0  40 82 00 0C */	bne .L_8011DB8C
/* 8011DB84 0011AAE4  A0 03 00 1C */	lhz r0, 0x1c(r3)
/* 8011DB88 0011AAE8  48 00 00 30 */	b .L_8011DBB8
.L_8011DB8C:
/* 8011DB8C 0011AAEC  EC 02 08 24 */	fdivs f0, f2, f1
/* 8011DB90 0011AAF0  C0 22 A0 48 */	lfs f1, lbl_803EA248@sda21(r2)
/* 8011DB94 0011AAF4  C0 42 A0 44 */	lfs f2, lbl_803EA244@sda21(r2)
/* 8011DB98 0011AAF8  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011DB9C 0011AAFC  EC 02 00 2A */	fadds f0, f2, f0
/* 8011DBA0 0011AB00  FC 00 00 1E */	fctiwz f0, f0
/* 8011DBA4 0011AB04  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 8011DBA8 0011AB08  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011DBAC 0011AB0C  54 00 08 3C */	slwi r0, r0, 1
/* 8011DBB0 0011AB10  7C 63 02 14 */	add r3, r3, r0
/* 8011DBB4 0011AB14  A0 03 00 1C */	lhz r0, 0x1c(r3)
.L_8011DBB8:
/* 8011DBB8 0011AB18  54 03 04 3E */	clrlwi r3, r0, 0x10
/* 8011DBBC 0011AB1C  48 00 02 40 */	b .L_8011DDFC
.L_8011DBC0:
/* 8011DBC0 0011AB20  FC 00 10 00 */	fcmpu cr0, f0, f2
/* 8011DBC4 0011AB24  40 82 00 0C */	bne .L_8011DBD0
/* 8011DBC8 0011AB28  A0 03 00 1C */	lhz r0, 0x1c(r3)
/* 8011DBCC 0011AB2C  48 00 00 30 */	b .L_8011DBFC
.L_8011DBD0:
/* 8011DBD0 0011AB30  EC 01 10 24 */	fdivs f0, f1, f2
/* 8011DBD4 0011AB34  C0 22 A0 48 */	lfs f1, lbl_803EA248@sda21(r2)
/* 8011DBD8 0011AB38  C0 42 A0 44 */	lfs f2, lbl_803EA244@sda21(r2)
/* 8011DBDC 0011AB3C  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011DBE0 0011AB40  EC 02 00 2A */	fadds f0, f2, f0
/* 8011DBE4 0011AB44  FC 00 00 1E */	fctiwz f0, f0
/* 8011DBE8 0011AB48  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 8011DBEC 0011AB4C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011DBF0 0011AB50  54 00 08 3C */	slwi r0, r0, 1
/* 8011DBF4 0011AB54  7C 63 02 14 */	add r3, r3, r0
/* 8011DBF8 0011AB58  A0 03 00 1C */	lhz r0, 0x1c(r3)
.L_8011DBFC:
/* 8011DBFC 0011AB5C  54 00 04 3E */	clrlwi r0, r0, 0x10
/* 8011DC00 0011AB60  20 60 40 00 */	subfic r3, r0, 0x4000
/* 8011DC04 0011AB64  48 00 01 F8 */	b .L_8011DDFC
.L_8011DC08:
/* 8011DC08 0011AB68  FC 20 08 50 */	fneg f1, f1
/* 8011DC0C 0011AB6C  FC 01 10 40 */	fcmpo cr0, f1, f2
/* 8011DC10 0011AB70  40 80 00 4C */	bge .L_8011DC5C
/* 8011DC14 0011AB74  FC 00 10 00 */	fcmpu cr0, f0, f2
/* 8011DC18 0011AB78  40 82 00 0C */	bne .L_8011DC24
/* 8011DC1C 0011AB7C  A0 03 00 1C */	lhz r0, 0x1c(r3)
/* 8011DC20 0011AB80  48 00 00 30 */	b .L_8011DC50
.L_8011DC24:
/* 8011DC24 0011AB84  EC 01 10 24 */	fdivs f0, f1, f2
/* 8011DC28 0011AB88  C0 22 A0 48 */	lfs f1, lbl_803EA248@sda21(r2)
/* 8011DC2C 0011AB8C  C0 42 A0 44 */	lfs f2, lbl_803EA244@sda21(r2)
/* 8011DC30 0011AB90  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011DC34 0011AB94  EC 02 00 2A */	fadds f0, f2, f0
/* 8011DC38 0011AB98  FC 00 00 1E */	fctiwz f0, f0
/* 8011DC3C 0011AB9C  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 8011DC40 0011ABA0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011DC44 0011ABA4  54 00 08 3C */	slwi r0, r0, 1
/* 8011DC48 0011ABA8  7C 63 02 14 */	add r3, r3, r0
/* 8011DC4C 0011ABAC  A0 03 00 1C */	lhz r0, 0x1c(r3)
.L_8011DC50:
/* 8011DC50 0011ABB0  54 03 04 3E */	clrlwi r3, r0, 0x10
/* 8011DC54 0011ABB4  38 63 40 00 */	addi r3, r3, 0x4000
/* 8011DC58 0011ABB8  48 00 01 A4 */	b .L_8011DDFC
.L_8011DC5C:
/* 8011DC5C 0011ABBC  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 8011DC60 0011ABC0  40 82 00 0C */	bne .L_8011DC6C
/* 8011DC64 0011ABC4  A0 03 00 1C */	lhz r0, 0x1c(r3)
/* 8011DC68 0011ABC8  48 00 00 30 */	b .L_8011DC98
.L_8011DC6C:
/* 8011DC6C 0011ABCC  EC 02 08 24 */	fdivs f0, f2, f1
/* 8011DC70 0011ABD0  C0 22 A0 48 */	lfs f1, lbl_803EA248@sda21(r2)
/* 8011DC74 0011ABD4  C0 42 A0 44 */	lfs f2, lbl_803EA244@sda21(r2)
/* 8011DC78 0011ABD8  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011DC7C 0011ABDC  EC 02 00 2A */	fadds f0, f2, f0
/* 8011DC80 0011ABE0  FC 00 00 1E */	fctiwz f0, f0
/* 8011DC84 0011ABE4  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 8011DC88 0011ABE8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011DC8C 0011ABEC  54 00 08 3C */	slwi r0, r0, 1
/* 8011DC90 0011ABF0  7C 63 02 14 */	add r3, r3, r0
/* 8011DC94 0011ABF4  A0 03 00 1C */	lhz r0, 0x1c(r3)
.L_8011DC98:
/* 8011DC98 0011ABF8  3C 60 00 01 */	lis r3, 0x00008000@ha
/* 8011DC9C 0011ABFC  54 04 04 3E */	clrlwi r4, r0, 0x10
/* 8011DCA0 0011AC00  38 03 80 00 */	addi r0, r3, 0x00008000@l
/* 8011DCA4 0011AC04  7C 64 00 50 */	subf r3, r4, r0
/* 8011DCA8 0011AC08  48 00 01 54 */	b .L_8011DDFC
.L_8011DCAC:
/* 8011DCAC 0011AC0C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8011DCB0 0011AC10  FC 40 10 50 */	fneg f2, f2
/* 8011DCB4 0011AC14  40 80 00 B0 */	bge .L_8011DD64
/* 8011DCB8 0011AC18  FC 20 08 50 */	fneg f1, f1
/* 8011DCBC 0011AC1C  FC 01 10 40 */	fcmpo cr0, f1, f2
/* 8011DCC0 0011AC20  4C 41 13 82 */	cror 2, 1, 2
/* 8011DCC4 0011AC24  40 82 00 50 */	bne .L_8011DD14
/* 8011DCC8 0011AC28  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 8011DCCC 0011AC2C  40 82 00 0C */	bne .L_8011DCD8
/* 8011DCD0 0011AC30  A0 03 00 1C */	lhz r0, 0x1c(r3)
/* 8011DCD4 0011AC34  48 00 00 30 */	b .L_8011DD04
.L_8011DCD8:
/* 8011DCD8 0011AC38  EC 02 08 24 */	fdivs f0, f2, f1
/* 8011DCDC 0011AC3C  C0 22 A0 48 */	lfs f1, lbl_803EA248@sda21(r2)
/* 8011DCE0 0011AC40  C0 42 A0 44 */	lfs f2, lbl_803EA244@sda21(r2)
/* 8011DCE4 0011AC44  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011DCE8 0011AC48  EC 02 00 2A */	fadds f0, f2, f0
/* 8011DCEC 0011AC4C  FC 00 00 1E */	fctiwz f0, f0
/* 8011DCF0 0011AC50  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 8011DCF4 0011AC54  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011DCF8 0011AC58  54 00 08 3C */	slwi r0, r0, 1
/* 8011DCFC 0011AC5C  7C 63 02 14 */	add r3, r3, r0
/* 8011DD00 0011AC60  A0 03 00 1C */	lhz r0, 0x1c(r3)
.L_8011DD04:
/* 8011DD04 0011AC64  54 03 04 3E */	clrlwi r3, r0, 0x10
/* 8011DD08 0011AC68  3C 63 00 01 */	addis r3, r3, 1
/* 8011DD0C 0011AC6C  38 63 80 00 */	addi r3, r3, -32768
/* 8011DD10 0011AC70  48 00 00 EC */	b .L_8011DDFC
.L_8011DD14:
/* 8011DD14 0011AC74  FC 00 10 00 */	fcmpu cr0, f0, f2
/* 8011DD18 0011AC78  40 82 00 0C */	bne .L_8011DD24
/* 8011DD1C 0011AC7C  A0 03 00 1C */	lhz r0, 0x1c(r3)
/* 8011DD20 0011AC80  48 00 00 30 */	b .L_8011DD50
.L_8011DD24:
/* 8011DD24 0011AC84  EC 01 10 24 */	fdivs f0, f1, f2
/* 8011DD28 0011AC88  C0 22 A0 48 */	lfs f1, lbl_803EA248@sda21(r2)
/* 8011DD2C 0011AC8C  C0 42 A0 44 */	lfs f2, lbl_803EA244@sda21(r2)
/* 8011DD30 0011AC90  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011DD34 0011AC94  EC 02 00 2A */	fadds f0, f2, f0
/* 8011DD38 0011AC98  FC 00 00 1E */	fctiwz f0, f0
/* 8011DD3C 0011AC9C  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 8011DD40 0011ACA0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011DD44 0011ACA4  54 00 08 3C */	slwi r0, r0, 1
/* 8011DD48 0011ACA8  7C 63 02 14 */	add r3, r3, r0
/* 8011DD4C 0011ACAC  A0 03 00 1C */	lhz r0, 0x1c(r3)
.L_8011DD50:
/* 8011DD50 0011ACB0  3C 60 00 01 */	lis r3, 0x0000C000@ha
/* 8011DD54 0011ACB4  54 04 04 3E */	clrlwi r4, r0, 0x10
/* 8011DD58 0011ACB8  38 03 C0 00 */	addi r0, r3, 0x0000C000@l
/* 8011DD5C 0011ACBC  7C 64 00 50 */	subf r3, r4, r0
/* 8011DD60 0011ACC0  48 00 00 9C */	b .L_8011DDFC
.L_8011DD64:
/* 8011DD64 0011ACC4  FC 01 10 40 */	fcmpo cr0, f1, f2
/* 8011DD68 0011ACC8  40 80 00 50 */	bge .L_8011DDB8
/* 8011DD6C 0011ACCC  FC 00 10 00 */	fcmpu cr0, f0, f2
/* 8011DD70 0011ACD0  40 82 00 0C */	bne .L_8011DD7C
/* 8011DD74 0011ACD4  A0 03 00 1C */	lhz r0, 0x1c(r3)
/* 8011DD78 0011ACD8  48 00 00 30 */	b .L_8011DDA8
.L_8011DD7C:
/* 8011DD7C 0011ACDC  EC 01 10 24 */	fdivs f0, f1, f2
/* 8011DD80 0011ACE0  C0 22 A0 48 */	lfs f1, lbl_803EA248@sda21(r2)
/* 8011DD84 0011ACE4  C0 42 A0 44 */	lfs f2, lbl_803EA244@sda21(r2)
/* 8011DD88 0011ACE8  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011DD8C 0011ACEC  EC 02 00 2A */	fadds f0, f2, f0
/* 8011DD90 0011ACF0  FC 00 00 1E */	fctiwz f0, f0
/* 8011DD94 0011ACF4  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 8011DD98 0011ACF8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011DD9C 0011ACFC  54 00 08 3C */	slwi r0, r0, 1
/* 8011DDA0 0011AD00  7C 63 02 14 */	add r3, r3, r0
/* 8011DDA4 0011AD04  A0 03 00 1C */	lhz r0, 0x1c(r3)
.L_8011DDA8:
/* 8011DDA8 0011AD08  54 03 04 3E */	clrlwi r3, r0, 0x10
/* 8011DDAC 0011AD0C  3C 63 00 01 */	addis r3, r3, 1
/* 8011DDB0 0011AD10  38 63 C0 00 */	addi r3, r3, -16384
/* 8011DDB4 0011AD14  48 00 00 48 */	b .L_8011DDFC
.L_8011DDB8:
/* 8011DDB8 0011AD18  FC 00 08 00 */	fcmpu cr0, f0, f1
/* 8011DDBC 0011AD1C  40 82 00 0C */	bne .L_8011DDC8
/* 8011DDC0 0011AD20  A0 03 00 1C */	lhz r0, 0x1c(r3)
/* 8011DDC4 0011AD24  48 00 00 30 */	b .L_8011DDF4
.L_8011DDC8:
/* 8011DDC8 0011AD28  EC 02 08 24 */	fdivs f0, f2, f1
/* 8011DDCC 0011AD2C  C0 22 A0 48 */	lfs f1, lbl_803EA248@sda21(r2)
/* 8011DDD0 0011AD30  C0 42 A0 44 */	lfs f2, lbl_803EA244@sda21(r2)
/* 8011DDD4 0011AD34  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011DDD8 0011AD38  EC 02 00 2A */	fadds f0, f2, f0
/* 8011DDDC 0011AD3C  FC 00 00 1E */	fctiwz f0, f0
/* 8011DDE0 0011AD40  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 8011DDE4 0011AD44  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8011DDE8 0011AD48  54 00 08 3C */	slwi r0, r0, 1
/* 8011DDEC 0011AD4C  7C 63 02 14 */	add r3, r3, r0
/* 8011DDF0 0011AD50  A0 03 00 1C */	lhz r0, 0x1c(r3)
.L_8011DDF4:
/* 8011DDF4 0011AD54  54 00 04 3E */	clrlwi r0, r0, 0x10
/* 8011DDF8 0011AD58  7C 60 00 D0 */	neg r3, r0
.L_8011DDFC:
/* 8011DDFC 0011AD5C  54 63 04 3E */	clrlwi r3, r3, 0x10
/* 8011DE00 0011AD60  38 21 00 28 */	addi r1, r1, 0x28
/* 8011DE04 0011AD64  4E 80 00 20 */	blr 
.endfn atan__Fff

.fn atan2__6NMathFFff, global
/* 8011DE08 0011AD68  FC 00 10 90 */	fmr f0, f2
/* 8011DE0C 0011AD6C  7C 08 02 A6 */	mflr r0
/* 8011DE10 0011AD70  90 01 00 04 */	stw r0, 4(r1)
/* 8011DE14 0011AD74  FC 40 08 90 */	fmr f2, f1
/* 8011DE18 0011AD78  FC 20 00 90 */	fmr f1, f0
/* 8011DE1C 0011AD7C  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011DE20 0011AD80  4B FF FD 29 */	bl atan__Fff
/* 8011DE24 0011AD84  54 60 04 3E */	clrlwi r0, r3, 0x10
/* 8011DE28 0011AD88  C8 62 A0 58 */	lfd f3, lbl_803EA258@sda21(r2)
/* 8011DE2C 0011AD8C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8011DE30 0011AD90  3C 00 43 30 */	lis r0, 0x4330
/* 8011DE34 0011AD94  C0 22 A0 50 */	lfs f1, lbl_803EA250@sda21(r2)
/* 8011DE38 0011AD98  90 01 00 10 */	stw r0, 0x10(r1)
/* 8011DE3C 0011AD9C  C0 02 A0 4C */	lfs f0, lbl_803EA24C@sda21(r2)
/* 8011DE40 0011ADA0  C8 41 00 10 */	lfd f2, 0x10(r1)
/* 8011DE44 0011ADA4  EC 42 18 28 */	fsubs f2, f2, f3
/* 8011DE48 0011ADA8  EC 22 08 24 */	fdivs f1, f2, f1
/* 8011DE4C 0011ADAC  EC 20 00 72 */	fmuls f1, f0, f1
/* 8011DE50 0011ADB0  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011DE54 0011ADB4  38 21 00 18 */	addi r1, r1, 0x18
/* 8011DE58 0011ADB8  7C 08 03 A6 */	mtlr r0
/* 8011DE5C 0011ADBC  4E 80 00 20 */	blr 
.endfn atan2__6NMathFFff

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
.balign 8
.obj lbl_802C4378, local
	.asciz "nlibmath.cpp"
.endobj lbl_802C4378
.balign 4
.obj lbl_802C4388, local
	.asciz "nlibmath"
.endobj lbl_802C4388
.balign 4
.obj AtanTable, global # many short entries
	.2byte 0x0000
	.2byte 0x000A
	.2byte 0x0014
	.2byte 0x001F
	.2byte 0x0029
	.2byte 0x0033
	.2byte 0x003D
	.2byte 0x0047
	.2byte 0x0051
	.2byte 0x005C
	.2byte 0x0066
	.2byte 0x0070
	.2byte 0x007A
	.2byte 0x0084
	.2byte 0x008F
	.2byte 0x0099
	.2byte 0x00A3
	.2byte 0x00AD
	.2byte 0x00B7
	.2byte 0x00C2
	.2byte 0x00CC
	.2byte 0x00D6
	.2byte 0x00E0
	.2byte 0x00EA
	.2byte 0x00F4
	.2byte 0x00FF
	.2byte 0x0109
	.2byte 0x0113
	.2byte 0x011D
	.2byte 0x0127
	.2byte 0x0131
	.2byte 0x013C
	.2byte 0x0146
	.2byte 0x0150
	.2byte 0x015A
	.2byte 0x0164
	.2byte 0x016F
	.2byte 0x0179
	.2byte 0x0183
	.2byte 0x018D
	.2byte 0x0197
	.2byte 0x01A1
	.2byte 0x01AC
	.2byte 0x01B6
	.2byte 0x01C0
	.2byte 0x01CA
	.2byte 0x01D4
	.2byte 0x01DE
	.2byte 0x01E9
	.2byte 0x01F3
	.2byte 0x01FD
	.2byte 0x0207
	.2byte 0x0211
	.2byte 0x021B
	.2byte 0x0226
	.2byte 0x0230
	.2byte 0x023A
	.2byte 0x0244
	.2byte 0x024E
	.2byte 0x0258
	.2byte 0x0262
	.2byte 0x026D
	.2byte 0x0277
	.2byte 0x0281
	.2byte 0x028B
	.2byte 0x0295
	.2byte 0x029F
	.2byte 0x02A9
	.2byte 0x02B4
	.2byte 0x02BE
	.2byte 0x02C8
	.2byte 0x02D2
	.2byte 0x02DC
	.2byte 0x02E6
	.2byte 0x02F0
	.2byte 0x02FB
	.2byte 0x0305
	.2byte 0x030F
	.2byte 0x0319
	.2byte 0x0323
	.2byte 0x032D
	.2byte 0x0337
	.2byte 0x0341
	.2byte 0x034C
	.2byte 0x0356
	.2byte 0x0360
	.2byte 0x036A
	.2byte 0x0374
	.2byte 0x037E
	.2byte 0x0388
	.2byte 0x0392
	.2byte 0x039C
	.2byte 0x03A7
	.2byte 0x03B1
	.2byte 0x03BB
	.2byte 0x03C5
	.2byte 0x03CF
	.2byte 0x03D9
	.2byte 0x03E3
	.2byte 0x03ED
	.2byte 0x03F7
	.2byte 0x0401
	.2byte 0x040C
	.2byte 0x0416
	.2byte 0x0420
	.2byte 0x042A
	.2byte 0x0434
	.2byte 0x043E
	.2byte 0x0448
	.2byte 0x0452
	.2byte 0x045C
	.2byte 0x0466
	.2byte 0x0470
	.2byte 0x047A
	.2byte 0x0484
	.2byte 0x048E
	.2byte 0x0499
	.2byte 0x04A3
	.2byte 0x04AD
	.2byte 0x04B7
	.2byte 0x04C1
	.2byte 0x04CB
	.2byte 0x04D5
	.2byte 0x04DF
	.2byte 0x04E9
	.2byte 0x04F3
	.2byte 0x04FD
	.2byte 0x0507
	.2byte 0x0511
	.2byte 0x051B
	.2byte 0x0525
	.2byte 0x052F
	.2byte 0x0539
	.2byte 0x0543
	.2byte 0x054D
	.2byte 0x0557
	.2byte 0x0561
	.2byte 0x056B
	.2byte 0x0575
	.2byte 0x057F
	.2byte 0x0589
	.2byte 0x0593
	.2byte 0x059D
	.2byte 0x05A7
	.2byte 0x05B1
	.2byte 0x05BB
	.2byte 0x05C5
	.2byte 0x05CF
	.2byte 0x05D9
	.2byte 0x05E3
	.2byte 0x05ED
	.2byte 0x05F7
	.2byte 0x0601
	.2byte 0x060B
	.2byte 0x0615
	.2byte 0x061F
	.2byte 0x0629
	.2byte 0x0633
	.2byte 0x063D
	.2byte 0x0647
	.2byte 0x0651
	.2byte 0x065B
	.2byte 0x0665
	.2byte 0x066E
	.2byte 0x0678
	.2byte 0x0682
	.2byte 0x068C
	.2byte 0x0696
	.2byte 0x06A0
	.2byte 0x06AA
	.2byte 0x06B4
	.2byte 0x06BE
	.2byte 0x06C8
	.2byte 0x06D2
	.2byte 0x06DC
	.2byte 0x06E5
	.2byte 0x06EF
	.2byte 0x06F9
	.2byte 0x0703
	.2byte 0x070D
	.2byte 0x0717
	.2byte 0x0721
	.2byte 0x072B
	.2byte 0x0735
	.2byte 0x073E
	.2byte 0x0748
	.2byte 0x0752
	.2byte 0x075C
	.2byte 0x0766
	.2byte 0x0770
	.2byte 0x077A
	.2byte 0x0783
	.2byte 0x078D
	.2byte 0x0797
	.2byte 0x07A1
	.2byte 0x07AB
	.2byte 0x07B5
	.2byte 0x07BE
	.2byte 0x07C8
	.2byte 0x07D2
	.2byte 0x07DC
	.2byte 0x07E6
	.2byte 0x07EF
	.2byte 0x07F9
	.2byte 0x0803
	.2byte 0x080D
	.2byte 0x0817
	.2byte 0x0820
	.2byte 0x082A
	.2byte 0x0834
	.2byte 0x083E
	.2byte 0x0848
	.2byte 0x0851
	.2byte 0x085B
	.2byte 0x0865
	.2byte 0x086F
	.2byte 0x0878
	.2byte 0x0882
	.2byte 0x088C
	.2byte 0x0896
	.2byte 0x089F
	.2byte 0x08A9
	.2byte 0x08B3
	.2byte 0x08BD
	.2byte 0x08C6
	.2byte 0x08D0
	.2byte 0x08DA
	.2byte 0x08E3
	.2byte 0x08ED
	.2byte 0x08F7
	.2byte 0x0901
	.2byte 0x090A
	.2byte 0x0914
	.2byte 0x091E
	.2byte 0x0927
	.2byte 0x0931
	.2byte 0x093B
	.2byte 0x0944
	.2byte 0x094E
	.2byte 0x0958
	.2byte 0x0961
	.2byte 0x096B
	.2byte 0x0975
	.2byte 0x097E
	.2byte 0x0988
	.2byte 0x0992
	.2byte 0x099B
	.2byte 0x09A5
	.2byte 0x09AE
	.2byte 0x09B8
	.2byte 0x09C2
	.2byte 0x09CB
	.2byte 0x09D5
	.2byte 0x09DE
	.2byte 0x09E8
	.2byte 0x09F2
	.2byte 0x09FB
	.2byte 0x0A05
	.2byte 0x0A0E
	.2byte 0x0A18
	.2byte 0x0A22
	.2byte 0x0A2B
	.2byte 0x0A35
	.2byte 0x0A3E
	.2byte 0x0A48
	.2byte 0x0A51
	.2byte 0x0A5B
	.2byte 0x0A64
	.2byte 0x0A6E
	.2byte 0x0A77
	.2byte 0x0A81
	.2byte 0x0A8B
	.2byte 0x0A94
	.2byte 0x0A9E
	.2byte 0x0AA7
	.2byte 0x0AB1
	.2byte 0x0ABA
	.2byte 0x0AC4
	.2byte 0x0ACD
	.2byte 0x0AD7
	.2byte 0x0AE0
	.2byte 0x0AE9
	.2byte 0x0AF3
	.2byte 0x0AFC
	.2byte 0x0B06
	.2byte 0x0B0F
	.2byte 0x0B19
	.2byte 0x0B22
	.2byte 0x0B2C
	.2byte 0x0B35
	.2byte 0x0B3F
	.2byte 0x0B48
	.2byte 0x0B51
	.2byte 0x0B5B
	.2byte 0x0B64
	.2byte 0x0B6E
	.2byte 0x0B77
	.2byte 0x0B80
	.2byte 0x0B8A
	.2byte 0x0B93
	.2byte 0x0B9D
	.2byte 0x0BA6
	.2byte 0x0BAF
	.2byte 0x0BB9
	.2byte 0x0BC2
	.2byte 0x0BCB
	.2byte 0x0BD5
	.2byte 0x0BDE
	.2byte 0x0BE7
	.2byte 0x0BF1
	.2byte 0x0BFA
	.2byte 0x0C03
	.2byte 0x0C0D
	.2byte 0x0C16
	.2byte 0x0C1F
	.2byte 0x0C29
	.2byte 0x0C32
	.2byte 0x0C3B
	.2byte 0x0C45
	.2byte 0x0C4E
	.2byte 0x0C57
	.2byte 0x0C60
	.2byte 0x0C6A
	.2byte 0x0C73
	.2byte 0x0C7C
	.2byte 0x0C86
	.2byte 0x0C8F
	.2byte 0x0C98
	.2byte 0x0CA1
	.2byte 0x0CAB
	.2byte 0x0CB4
	.2byte 0x0CBD
	.2byte 0x0CC6
	.2byte 0x0CCF
	.2byte 0x0CD9
	.2byte 0x0CE2
	.2byte 0x0CEB
	.2byte 0x0CF4
	.2byte 0x0CFD
	.2byte 0x0D07
	.2byte 0x0D10
	.2byte 0x0D19
	.2byte 0x0D22
	.2byte 0x0D2B
	.2byte 0x0D34
	.2byte 0x0D3E
	.2byte 0x0D47
	.2byte 0x0D50
	.2byte 0x0D59
	.2byte 0x0D62
	.2byte 0x0D6B
	.2byte 0x0D74
	.2byte 0x0D7D
	.2byte 0x0D87
	.2byte 0x0D90
	.2byte 0x0D99
	.2byte 0x0DA2
	.2byte 0x0DAB
	.2byte 0x0DB4
	.2byte 0x0DBD
	.2byte 0x0DC6
	.2byte 0x0DCF
	.2byte 0x0DD8
	.2byte 0x0DE1
	.2byte 0x0DEA
	.2byte 0x0DF3
	.2byte 0x0DFC
	.2byte 0x0E05
	.2byte 0x0E0F
	.2byte 0x0E18
	.2byte 0x0E21
	.2byte 0x0E2A
	.2byte 0x0E33
	.2byte 0x0E3C
	.2byte 0x0E45
	.2byte 0x0E4E
	.2byte 0x0E56
	.2byte 0x0E5F
	.2byte 0x0E68
	.2byte 0x0E71
	.2byte 0x0E7A
	.2byte 0x0E83
	.2byte 0x0E8C
	.2byte 0x0E95
	.2byte 0x0E9E
	.2byte 0x0EA7
	.2byte 0x0EB0
	.2byte 0x0EB9
	.2byte 0x0EC2
	.2byte 0x0ECB
	.2byte 0x0ED4
	.2byte 0x0EDC
	.2byte 0x0EE5
	.2byte 0x0EEE
	.2byte 0x0EF7
	.2byte 0x0F00
	.2byte 0x0F09
	.2byte 0x0F12
	.2byte 0x0F1B
	.2byte 0x0F23
	.2byte 0x0F2C
	.2byte 0x0F35
	.2byte 0x0F3E
	.2byte 0x0F47
	.2byte 0x0F50
	.2byte 0x0F58
	.2byte 0x0F61
	.2byte 0x0F6A
	.2byte 0x0F73
	.2byte 0x0F7C
	.2byte 0x0F84
	.2byte 0x0F8D
	.2byte 0x0F96
	.2byte 0x0F9F
	.2byte 0x0FA7
	.2byte 0x0FB0
	.2byte 0x0FB9
	.2byte 0x0FC2
	.2byte 0x0FCA
	.2byte 0x0FD3
	.2byte 0x0FDC
	.2byte 0x0FE5
	.2byte 0x0FED
	.2byte 0x0FF6
	.2byte 0x0FFF
	.2byte 0x1007
	.2byte 0x1010
	.2byte 0x1019
	.2byte 0x1021
	.2byte 0x102A
	.2byte 0x1033
	.2byte 0x103B
	.2byte 0x1044
	.2byte 0x104D
	.2byte 0x1055
	.2byte 0x105E
	.2byte 0x1067
	.2byte 0x106F
	.2byte 0x1078
	.2byte 0x1080
	.2byte 0x1089
	.2byte 0x1092
	.2byte 0x109A
	.2byte 0x10A3
	.2byte 0x10AB
	.2byte 0x10B4
	.2byte 0x10BC
	.2byte 0x10C5
	.2byte 0x10CE
	.2byte 0x10D6
	.2byte 0x10DF
	.2byte 0x10E7
	.2byte 0x10F0
	.2byte 0x10F8
	.2byte 0x1101
	.2byte 0x1109
	.2byte 0x1112
	.2byte 0x111A
	.2byte 0x1123
	.2byte 0x112B
	.2byte 0x1134
	.2byte 0x113C
	.2byte 0x1145
	.2byte 0x114D
	.2byte 0x1156
	.2byte 0x115E
	.2byte 0x1166
	.2byte 0x116F
	.2byte 0x1177
	.2byte 0x1180
	.2byte 0x1188
	.2byte 0x1191
	.2byte 0x1199
	.2byte 0x11A1
	.2byte 0x11AA
	.2byte 0x11B2
	.2byte 0x11BB
	.2byte 0x11C3
	.2byte 0x11CB
	.2byte 0x11D4
	.2byte 0x11DC
	.2byte 0x11E4
	.2byte 0x11ED
	.2byte 0x11F5
	.2byte 0x11FD
	.2byte 0x1206
	.2byte 0x120E
	.2byte 0x1216
	.2byte 0x121F
	.2byte 0x1227
	.2byte 0x122F
	.2byte 0x1237
	.2byte 0x1240
	.2byte 0x1248
	.2byte 0x1250
	.2byte 0x1259
	.2byte 0x1261
	.2byte 0x1269
	.2byte 0x1271
	.2byte 0x127A
	.2byte 0x1282
	.2byte 0x128A
	.2byte 0x1292
	.2byte 0x129A
	.2byte 0x12A3
	.2byte 0x12AB
	.2byte 0x12B3
	.2byte 0x12BB
	.2byte 0x12C3
	.2byte 0x12CC
	.2byte 0x12D4
	.2byte 0x12DC
	.2byte 0x12E4
	.2byte 0x12EC
	.2byte 0x12F4
	.2byte 0x12FC
	.2byte 0x1305
	.2byte 0x130D
	.2byte 0x1315
	.2byte 0x131D
	.2byte 0x1325
	.2byte 0x132D
	.2byte 0x1335
	.2byte 0x133D
	.2byte 0x1345
	.2byte 0x134D
	.2byte 0x1355
	.2byte 0x135E
	.2byte 0x1366
	.2byte 0x136E
	.2byte 0x1376
	.2byte 0x137E
	.2byte 0x1386
	.2byte 0x138E
	.2byte 0x1396
	.2byte 0x139E
	.2byte 0x13A6
	.2byte 0x13AE
	.2byte 0x13B6
	.2byte 0x13BE
	.2byte 0x13C6
	.2byte 0x13CE
	.2byte 0x13D6
	.2byte 0x13DE
	.2byte 0x13E6
	.2byte 0x13ED
	.2byte 0x13F5
	.2byte 0x13FD
	.2byte 0x1405
	.2byte 0x140D
	.2byte 0x1415
	.2byte 0x141D
	.2byte 0x1425
	.2byte 0x142D
	.2byte 0x1435
	.2byte 0x143D
	.2byte 0x1444
	.2byte 0x144C
	.2byte 0x1454
	.2byte 0x145C
	.2byte 0x1464
	.2byte 0x146C
	.2byte 0x1473
	.2byte 0x147B
	.2byte 0x1483
	.2byte 0x148B
	.2byte 0x1493
	.2byte 0x149B
	.2byte 0x14A2
	.2byte 0x14AA
	.2byte 0x14B2
	.2byte 0x14BA
	.2byte 0x14C1
	.2byte 0x14C9
	.2byte 0x14D1
	.2byte 0x14D9
	.2byte 0x14E0
	.2byte 0x14E8
	.2byte 0x14F0
	.2byte 0x14F8
	.2byte 0x14FF
	.2byte 0x1507
	.2byte 0x150F
	.2byte 0x1516
	.2byte 0x151E
	.2byte 0x1526
	.2byte 0x152D
	.2byte 0x1535
	.2byte 0x153D
	.2byte 0x1544
	.2byte 0x154C
	.2byte 0x1554
	.2byte 0x155B
	.2byte 0x1563
	.2byte 0x156B
	.2byte 0x1572
	.2byte 0x157A
	.2byte 0x1581
	.2byte 0x1589
	.2byte 0x1591
	.2byte 0x1598
	.2byte 0x15A0
	.2byte 0x15A7
	.2byte 0x15AF
	.2byte 0x15B7
	.2byte 0x15BE
	.2byte 0x15C6
	.2byte 0x15CD
	.2byte 0x15D5
	.2byte 0x15DC
	.2byte 0x15E4
	.2byte 0x15EB
	.2byte 0x15F3
	.2byte 0x15FA
	.2byte 0x1602
	.2byte 0x1609
	.2byte 0x1611
	.2byte 0x1618
	.2byte 0x1620
	.2byte 0x1627
	.2byte 0x162F
	.2byte 0x1636
	.2byte 0x163E
	.2byte 0x1645
	.2byte 0x164C
	.2byte 0x1654
	.2byte 0x165B
	.2byte 0x1663
	.2byte 0x166A
	.2byte 0x1671
	.2byte 0x1679
	.2byte 0x1680
	.2byte 0x1688
	.2byte 0x168F
	.2byte 0x1696
	.2byte 0x169E
	.2byte 0x16A5
	.2byte 0x16AC
	.2byte 0x16B4
	.2byte 0x16BB
	.2byte 0x16C2
	.2byte 0x16CA
	.2byte 0x16D1
	.2byte 0x16D8
	.2byte 0x16E0
	.2byte 0x16E7
	.2byte 0x16EE
	.2byte 0x16F6
	.2byte 0x16FD
	.2byte 0x1704
	.2byte 0x170B
	.2byte 0x1713
	.2byte 0x171A
	.2byte 0x1721
	.2byte 0x1728
	.2byte 0x1730
	.2byte 0x1737
	.2byte 0x173E
	.2byte 0x1745
	.2byte 0x174C
	.2byte 0x1754
	.2byte 0x175B
	.2byte 0x1762
	.2byte 0x1769
	.2byte 0x1770
	.2byte 0x1778
	.2byte 0x177F
	.2byte 0x1786
	.2byte 0x178D
	.2byte 0x1794
	.2byte 0x179B
	.2byte 0x17A2
	.2byte 0x17AA
	.2byte 0x17B1
	.2byte 0x17B8
	.2byte 0x17BF
	.2byte 0x17C6
	.2byte 0x17CD
	.2byte 0x17D4
	.2byte 0x17DB
	.2byte 0x17E2
	.2byte 0x17E9
	.2byte 0x17F0
	.2byte 0x17F7
	.2byte 0x17FE
	.2byte 0x1806
	.2byte 0x180D
	.2byte 0x1814
	.2byte 0x181B
	.2byte 0x1822
	.2byte 0x1829
	.2byte 0x1830
	.2byte 0x1837
	.2byte 0x183E
	.2byte 0x1845
	.2byte 0x184C
	.2byte 0x1853
	.2byte 0x185A
	.2byte 0x1860
	.2byte 0x1867
	.2byte 0x186E
	.2byte 0x1875
	.2byte 0x187C
	.2byte 0x1883
	.2byte 0x188A
	.2byte 0x1891
	.2byte 0x1898
	.2byte 0x189F
	.2byte 0x18A6
	.2byte 0x18AD
	.2byte 0x18B3
	.2byte 0x18BA
	.2byte 0x18C1
	.2byte 0x18C8
	.2byte 0x18CF
	.2byte 0x18D6
	.2byte 0x18DD
	.2byte 0x18E3
	.2byte 0x18EA
	.2byte 0x18F1
	.2byte 0x18F8
	.2byte 0x18FF
	.2byte 0x1906
	.2byte 0x190C
	.2byte 0x1913
	.2byte 0x191A
	.2byte 0x1921
	.2byte 0x1928
	.2byte 0x192E
	.2byte 0x1935
	.2byte 0x193C
	.2byte 0x1943
	.2byte 0x1949
	.2byte 0x1950
	.2byte 0x1957
	.2byte 0x195D
	.2byte 0x1964
	.2byte 0x196B
	.2byte 0x1972
	.2byte 0x1978
	.2byte 0x197F
	.2byte 0x1986
	.2byte 0x198C
	.2byte 0x1993
	.2byte 0x199A
	.2byte 0x19A0
	.2byte 0x19A7
	.2byte 0x19AE
	.2byte 0x19B4
	.2byte 0x19BB
	.2byte 0x19C2
	.2byte 0x19C8
	.2byte 0x19CF
	.2byte 0x19D5
	.2byte 0x19DC
	.2byte 0x19E3
	.2byte 0x19E9
	.2byte 0x19F0
	.2byte 0x19F6
	.2byte 0x19FD
	.2byte 0x1A04
	.2byte 0x1A0A
	.2byte 0x1A11
	.2byte 0x1A17
	.2byte 0x1A1E
	.2byte 0x1A24
	.2byte 0x1A2B
	.2byte 0x1A31
	.2byte 0x1A38
	.2byte 0x1A3E
	.2byte 0x1A45
	.2byte 0x1A4B
	.2byte 0x1A52
	.2byte 0x1A58
	.2byte 0x1A5F
	.2byte 0x1A65
	.2byte 0x1A6C
	.2byte 0x1A72
	.2byte 0x1A79
	.2byte 0x1A7F
	.2byte 0x1A86
	.2byte 0x1A8C
	.2byte 0x1A93
	.2byte 0x1A99
	.2byte 0x1A9F
	.2byte 0x1AA6
	.2byte 0x1AAC
	.2byte 0x1AB3
	.2byte 0x1AB9
	.2byte 0x1AC0
	.2byte 0x1AC6
	.2byte 0x1ACC
	.2byte 0x1AD3
	.2byte 0x1AD9
	.2byte 0x1ADF
	.2byte 0x1AE6
	.2byte 0x1AEC
	.2byte 0x1AF2
	.2byte 0x1AF9
	.2byte 0x1AFF
	.2byte 0x1B05
	.2byte 0x1B0C
	.2byte 0x1B12
	.2byte 0x1B18
	.2byte 0x1B1F
	.2byte 0x1B25
	.2byte 0x1B2B
	.2byte 0x1B32
	.2byte 0x1B38
	.2byte 0x1B3E
	.2byte 0x1B44
	.2byte 0x1B4B
	.2byte 0x1B51
	.2byte 0x1B57
	.2byte 0x1B5D
	.2byte 0x1B64
	.2byte 0x1B6A
	.2byte 0x1B70
	.2byte 0x1B76
	.2byte 0x1B7D
	.2byte 0x1B83
	.2byte 0x1B89
	.2byte 0x1B8F
	.2byte 0x1B95
	.2byte 0x1B9C
	.2byte 0x1BA2
	.2byte 0x1BA8
	.2byte 0x1BAE
	.2byte 0x1BB4
	.2byte 0x1BBA
	.2byte 0x1BC1
	.2byte 0x1BC7
	.2byte 0x1BCD
	.2byte 0x1BD3
	.2byte 0x1BD9
	.2byte 0x1BDF
	.2byte 0x1BE5
	.2byte 0x1BEB
	.2byte 0x1BF2
	.2byte 0x1BF8
	.2byte 0x1BFE
	.2byte 0x1C04
	.2byte 0x1C0A
	.2byte 0x1C10
	.2byte 0x1C16
	.2byte 0x1C1C
	.2byte 0x1C22
	.2byte 0x1C28
	.2byte 0x1C2E
	.2byte 0x1C34
	.2byte 0x1C3A
	.2byte 0x1C40
	.2byte 0x1C46
	.2byte 0x1C4C
	.2byte 0x1C52
	.2byte 0x1C58
	.2byte 0x1C5E
	.2byte 0x1C64
	.2byte 0x1C6A
	.2byte 0x1C70
	.2byte 0x1C76
	.2byte 0x1C7C
	.2byte 0x1C82
	.2byte 0x1C88
	.2byte 0x1C8E
	.2byte 0x1C94
	.2byte 0x1C9A
	.2byte 0x1CA0
	.2byte 0x1CA6
	.2byte 0x1CAC
	.2byte 0x1CB2
	.2byte 0x1CB8
	.2byte 0x1CBE
	.2byte 0x1CC3
	.2byte 0x1CC9
	.2byte 0x1CCF
	.2byte 0x1CD5
	.2byte 0x1CDB
	.2byte 0x1CE1
	.2byte 0x1CE7
	.2byte 0x1CED
	.2byte 0x1CF3
	.2byte 0x1CF8
	.2byte 0x1CFE
	.2byte 0x1D04
	.2byte 0x1D0A
	.2byte 0x1D10
	.2byte 0x1D16
	.2byte 0x1D1B
	.2byte 0x1D21
	.2byte 0x1D27
	.2byte 0x1D2D
	.2byte 0x1D33
	.2byte 0x1D38
	.2byte 0x1D3E
	.2byte 0x1D44
	.2byte 0x1D4A
	.2byte 0x1D4F
	.2byte 0x1D55
	.2byte 0x1D5B
	.2byte 0x1D61
	.2byte 0x1D66
	.2byte 0x1D6C
	.2byte 0x1D72
	.2byte 0x1D78
	.2byte 0x1D7D
	.2byte 0x1D83
	.2byte 0x1D89
	.2byte 0x1D8E
	.2byte 0x1D94
	.2byte 0x1D9A
	.2byte 0x1DA0
	.2byte 0x1DA5
	.2byte 0x1DAB
	.2byte 0x1DB1
	.2byte 0x1DB6
	.2byte 0x1DBC
	.2byte 0x1DC2
	.2byte 0x1DC7
	.2byte 0x1DCD
	.2byte 0x1DD3
	.2byte 0x1DD8
	.2byte 0x1DDE
	.2byte 0x1DE3
	.2byte 0x1DE9
	.2byte 0x1DEF
	.2byte 0x1DF4
	.2byte 0x1DFA
	.2byte 0x1DFF
	.2byte 0x1E05
	.2byte 0x1E0B
	.2byte 0x1E10
	.2byte 0x1E16
	.2byte 0x1E1B
	.2byte 0x1E21
	.2byte 0x1E26
	.2byte 0x1E2C
	.2byte 0x1E32
	.2byte 0x1E37
	.2byte 0x1E3D
	.2byte 0x1E42
	.2byte 0x1E48
	.2byte 0x1E4D
	.2byte 0x1E53
	.2byte 0x1E58
	.2byte 0x1E5E
	.2byte 0x1E63
	.2byte 0x1E69
	.2byte 0x1E6E
	.2byte 0x1E74
	.2byte 0x1E79
	.2byte 0x1E7F
	.2byte 0x1E84
	.2byte 0x1E8A
	.2byte 0x1E8F
	.2byte 0x1E94
	.2byte 0x1E9A
	.2byte 0x1E9F
	.2byte 0x1EA5
	.2byte 0x1EAA
	.2byte 0x1EB0
	.2byte 0x1EB5
	.2byte 0x1EBA
	.2byte 0x1EC0
	.2byte 0x1EC5
	.2byte 0x1ECB
	.2byte 0x1ED0
	.2byte 0x1ED5
	.2byte 0x1EDB
	.2byte 0x1EE0
	.2byte 0x1EE6
	.2byte 0x1EEB
	.2byte 0x1EF0
	.2byte 0x1EF6
	.2byte 0x1EFB
	.2byte 0x1F00
	.2byte 0x1F06
	.2byte 0x1F0B
	.2byte 0x1F10
	.2byte 0x1F16
	.2byte 0x1F1B
	.2byte 0x1F20
	.2byte 0x1F26
	.2byte 0x1F2B
	.2byte 0x1F30
	.2byte 0x1F36
	.2byte 0x1F3B
	.2byte 0x1F40
	.2byte 0x1F45
	.2byte 0x1F4B
	.2byte 0x1F50
	.2byte 0x1F55
	.2byte 0x1F5A
	.2byte 0x1F60
	.2byte 0x1F65
	.2byte 0x1F6A
	.2byte 0x1F6F
	.2byte 0x1F75
	.2byte 0x1F7A
	.2byte 0x1F7F
	.2byte 0x1F84
	.2byte 0x1F8A
	.2byte 0x1F8F
	.2byte 0x1F94
	.2byte 0x1F99
	.2byte 0x1F9E
	.2byte 0x1FA4
	.2byte 0x1FA9
	.2byte 0x1FAE
	.2byte 0x1FB3
	.2byte 0x1FB8
	.2byte 0x1FBD
	.2byte 0x1FC3
	.2byte 0x1FC8
	.2byte 0x1FCD
	.2byte 0x1FD2
	.2byte 0x1FD7
	.2byte 0x1FDC
	.2byte 0x1FE1
	.2byte 0x1FE6
	.2byte 0x1FEC
	.2byte 0x1FF1
	.2byte 0x1FF6
	.2byte 0x1FFB
	.2byte 0x2000
.endobj AtanTable

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj error__6NMathF, global
	.float 0.0001
.endobj error__6NMathF
.obj degreePerRadian__6NMathF, global
	.float 57.295776
.endobj degreePerRadian__6NMathF
.obj radianPerDegree__6NMathF, global
	.float 0.017453292
.endobj radianPerDegree__6NMathF
.obj pi__6NMathF, global
	.float 3.1415927
.endobj pi__6NMathF

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA240, local
	.float 0.0
.endobj lbl_803EA240
.obj lbl_803EA244, local
	.float 0.5
.endobj lbl_803EA244
.obj lbl_803EA248, local
	.float 1024.0
.endobj lbl_803EA248
.obj lbl_803EA24C, local
	.float 3.1415927
.endobj lbl_803EA24C
.obj lbl_803EA250, local
	.float 32768.0
.endobj lbl_803EA250
.balign 8
.obj lbl_803EA258, local
	.8byte 0x4330000000000000
.endobj lbl_803EA258
