.include "macros.inc"

.section .text, "ax"  # 0x80005560 - 0x80221F60
/* 80100A58 000FD9B8  C8 42 9C 70 */	lfd f2, "@2212"@sda21(r2)
/* 80100A5C 000FD9BC  FC 01 00 72 */	fmul f0, f1, f1
/* 80100A60 000FD9C0  FC 23 00 72 */	fmul f1, f3, f1
/* 80100A64 000FD9C4  FC 04 00 32 */	fmul f0, f4, f0
/* 80100A68 000FD9C8  FC 02 00 28 */	fsub f0, f2, f0
/* 80100A6C 000FD9CC  FC 21 00 32 */	fmul f1, f1, f0
/* 80100A70 000FD9D0  FC 01 00 72 */	fmul f0, f1, f1
/* 80100A74 000FD9D4  FC 23 00 72 */	fmul f1, f3, f1
/* 80100A78 000FD9D8  FC 04 00 32 */	fmul f0, f4, f0
/* 80100A7C 000FD9DC  FC 02 00 28 */	fsub f0, f2, f0
/* 80100A80 000FD9E0  FC 21 00 32 */	fmul f1, f1, f0
/* 80100A84 000FD9E4  FC 01 00 72 */	fmul f0, f1, f1
/* 80100A88 000FD9E8  FC 23 00 72 */	fmul f1, f3, f1
/* 80100A8C 000FD9EC  FC 04 00 32 */	fmul f0, f4, f0
/* 80100A90 000FD9F0  FC 02 00 28 */	fsub f0, f2, f0
/* 80100A94 000FD9F4  FC 01 00 32 */	fmul f0, f1, f0
/* 80100A98 000FD9F8  FC 04 00 32 */	fmul f0, f4, f0
/* 80100A9C 000FD9FC  FC 00 00 18 */	frsp f0, f0
/* 80100AA0 000FDA00  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 80100AA4 000FDA04  C0 81 00 28 */	lfs f4, 0x28(r1)
lbl_80100AA8:
/* 80100AA8 000FDA08  FC 40 20 90 */	fmr f2, f4
/* 80100AAC 000FDA0C  FC 20 F8 90 */	fmr f1, f31
/* 80100AB0 000FDA10  48 11 AF 49 */	bl atan2f
/* 80100AB4 000FDA14  FF E0 08 90 */	fmr f31, f1
/* 80100AB8 000FDA18  48 00 00 88 */	b lbl_80100B40
lbl_80100ABC:
/* 80100ABC 000FDA1C  C3 82 9C A0 */	lfs f28, lbl_803E9EA0@sda21(r2)
/* 80100AC0 000FDA20  C0 22 9C 60 */	lfs f1, lbl_803E9E60@sda21(r2)
/* 80100AC4 000FDA24  C0 5F 02 F4 */	lfs f2, 0x2f4(r31)
/* 80100AC8 000FDA28  4B F3 7A ED */	bl angDist__Fff
/* 80100ACC 000FDA2C  EC 01 07 32 */	fmuls f0, f1, f28
/* 80100AD0 000FDA30  C0 3F 02 F4 */	lfs f1, 0x2f4(r31)
/* 80100AD4 000FDA34  EC 21 00 2A */	fadds f1, f1, f0
/* 80100AD8 000FDA38  4B F3 7A B1 */	bl roundAng__Ff
/* 80100ADC 000FDA3C  D0 3F 02 F4 */	stfs f1, 0x2f4(r31)
/* 80100AE0 000FDA40  C0 22 9C 60 */	lfs f1, lbl_803E9E60@sda21(r2)
/* 80100AE4 000FDA44  C0 5F 02 F8 */	lfs f2, 0x2f8(r31)
/* 80100AE8 000FDA48  4B F3 7A CD */	bl angDist__Fff
/* 80100AEC 000FDA4C  EC 01 07 32 */	fmuls f0, f1, f28
/* 80100AF0 000FDA50  C0 3F 02 F8 */	lfs f1, 0x2f8(r31)
/* 80100AF4 000FDA54  EC 21 00 2A */	fadds f1, f1, f0
/* 80100AF8 000FDA58  4B F3 7A 91 */	bl roundAng__Ff
/* 80100AFC 000FDA5C  D0 3F 02 F8 */	stfs f1, 0x2f8(r31)
/* 80100B00 000FDA60  C0 3F 02 F4 */	lfs f1, 0x2f4(r31)
/* 80100B04 000FDA64  C0 02 9C 84 */	lfs f0, lbl_803E9E84@sda21(r2)
/* 80100B08 000FDA68  FC 20 0A 10 */	fabs f1, f1
/* 80100B0C 000FDA6C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80100B10 000FDA70  40 80 01 DC */	bge lbl_80100CEC
/* 80100B14 000FDA74  C0 3F 02 F8 */	lfs f1, 0x2f8(r31)
/* 80100B18 000FDA78  FC 20 0A 10 */	fabs f1, f1
/* 80100B1C 000FDA7C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80100B20 000FDA80  40 80 01 CC */	bge lbl_80100CEC
/* 80100B24 000FDA84  38 00 00 00 */	li r0, 0
/* 80100B28 000FDA88  90 1F 02 EC */	stw r0, 0x2ec(r31)
/* 80100B2C 000FDA8C  C0 02 9C 60 */	lfs f0, lbl_803E9E60@sda21(r2)
/* 80100B30 000FDA90  D0 1F 02 F8 */	stfs f0, 0x2f8(r31)
/* 80100B34 000FDA94  D0 1F 02 F4 */	stfs f0, 0x2f4(r31)
/* 80100B38 000FDA98  98 1F 02 F0 */	stb r0, 0x2f0(r31)
/* 80100B3C 000FDA9C  48 00 01 B0 */	b lbl_80100CEC
lbl_80100B40:
/* 80100B40 000FDAA0  C0 3F 02 F4 */	lfs f1, 0x2f4(r31)
/* 80100B44 000FDAA4  C0 1F 00 A0 */	lfs f0, 0xa0(r31)
/* 80100B48 000FDAA8  EC 21 00 2A */	fadds f1, f1, f0
/* 80100B4C 000FDAAC  4B F3 7A 3D */	bl roundAng__Ff
/* 80100B50 000FDAB0  FC 40 08 90 */	fmr f2, f1
/* 80100B54 000FDAB4  C0 1F 00 A0 */	lfs f0, 0xa0(r31)
/* 80100B58 000FDAB8  EC 3E 00 28 */	fsubs f1, f30, f0
/* 80100B5C 000FDABC  FF 80 10 90 */	fmr f28, f2
/* 80100B60 000FDAC0  4B F3 7A 29 */	bl roundAng__Ff
/* 80100B64 000FDAC4  C0 02 9D 70 */	lfs f0, lbl_803E9F70@sda21(r2)
/* 80100B68 000FDAC8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80100B6C 000FDACC  40 80 00 30 */	bge lbl_80100B9C
/* 80100B70 000FDAD0  C0 5F 02 F4 */	lfs f2, 0x2f4(r31)
/* 80100B74 000FDAD4  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80100B78 000FDAD8  40 81 00 14 */	ble lbl_80100B8C
/* 80100B7C 000FDADC  EC 02 08 28 */	fsubs f0, f2, f1
/* 80100B80 000FDAE0  C0 22 9D 80 */	lfs f1, lbl_803E9F80@sda21(r2)
/* 80100B84 000FDAE4  EC 21 00 28 */	fsubs f1, f1, f0
/* 80100B88 000FDAE8  48 00 00 48 */	b lbl_80100BD0
lbl_80100B8C:
/* 80100B8C 000FDAEC  FC 20 F0 90 */	fmr f1, f30
/* 80100B90 000FDAF0  FC 40 E0 90 */	fmr f2, f28
/* 80100B94 000FDAF4  4B F3 7A 21 */	bl angDist__Fff
/* 80100B98 000FDAF8  48 00 00 38 */	b lbl_80100BD0
lbl_80100B9C:
/* 80100B9C 000FDAFC  C0 5F 02 F4 */	lfs f2, 0x2f4(r31)
/* 80100BA0 000FDB00  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80100BA4 000FDB04  4C 40 13 82 */	cror 2, 0, 2
/* 80100BA8 000FDB08  40 82 00 1C */	bne lbl_80100BC4
/* 80100BAC 000FDB0C  EC 22 08 28 */	fsubs f1, f2, f1
/* 80100BB0 000FDB10  C0 42 9D 80 */	lfs f2, lbl_803E9F80@sda21(r2)
/* 80100BB4 000FDB14  C0 02 9D 3C */	lfs f0, lbl_803E9F3C@sda21(r2)
/* 80100BB8 000FDB18  EC 22 08 28 */	fsubs f1, f2, f1
/* 80100BBC 000FDB1C  EC 21 00 32 */	fmuls f1, f1, f0
/* 80100BC0 000FDB20  48 00 00 10 */	b lbl_80100BD0
lbl_80100BC4:
/* 80100BC4 000FDB24  FC 20 F0 90 */	fmr f1, f30
/* 80100BC8 000FDB28  FC 40 E0 90 */	fmr f2, f28
/* 80100BCC 000FDB2C  4B F3 79 E9 */	bl angDist__Fff
lbl_80100BD0:
/* 80100BD0 000FDB30  FC 40 0A 10 */	fabs f2, f1
/* 80100BD4 000FDB34  C0 02 9D 88 */	lfs f0, lbl_803E9F88@sda21(r2)
/* 80100BD8 000FDB38  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80100BDC 000FDB3C  40 80 00 08 */	bge lbl_80100BE4
/* 80100BE0 000FDB40  C0 22 9C 60 */	lfs f1, lbl_803E9E60@sda21(r2)
lbl_80100BE4:
/* 80100BE4 000FDB44  EC 01 07 72 */	fmuls f0, f1, f29
/* 80100BE8 000FDB48  C0 3F 02 F4 */	lfs f1, 0x2f4(r31)
/* 80100BEC 000FDB4C  EC 21 00 2A */	fadds f1, f1, f0
/* 80100BF0 000FDB50  4B F3 79 99 */	bl roundAng__Ff
/* 80100BF4 000FDB54  D0 3F 02 F4 */	stfs f1, 0x2f4(r31)
/* 80100BF8 000FDB58  C0 5F 02 F4 */	lfs f2, 0x2f4(r31)
/* 80100BFC 000FDB5C  C0 22 9D 5C */	lfs f1, lbl_803E9F5C@sda21(r2)
/* 80100C00 000FDB60  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 80100C04 000FDB64  40 81 00 18 */	ble lbl_80100C1C
/* 80100C08 000FDB68  C0 02 9D 70 */	lfs f0, lbl_803E9F70@sda21(r2)
/* 80100C0C 000FDB6C  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80100C10 000FDB70  40 80 00 0C */	bge lbl_80100C1C
/* 80100C14 000FDB74  D0 3F 02 F4 */	stfs f1, 0x2f4(r31)
/* 80100C18 000FDB78  48 00 00 24 */	b lbl_80100C3C
lbl_80100C1C:
/* 80100C1C 000FDB7C  C0 22 9D 8C */	lfs f1, lbl_803E9F8C@sda21(r2)
/* 80100C20 000FDB80  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 80100C24 000FDB84  40 80 00 18 */	bge lbl_80100C3C
/* 80100C28 000FDB88  C0 02 9D 70 */	lfs f0, lbl_803E9F70@sda21(r2)
/* 80100C2C 000FDB8C  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80100C30 000FDB90  4C 41 13 82 */	cror 2, 1, 2
/* 80100C34 000FDB94  40 82 00 08 */	bne lbl_80100C3C
/* 80100C38 000FDB98  D0 3F 02 F4 */	stfs f1, 0x2f4(r31)
lbl_80100C3C:
/* 80100C3C 000FDB9C  FC 20 F8 90 */	fmr f1, f31
/* 80100C40 000FDBA0  C0 5F 02 F8 */	lfs f2, 0x2f8(r31)
/* 80100C44 000FDBA4  4B F3 79 71 */	bl angDist__Fff
/* 80100C48 000FDBA8  FC 40 0A 10 */	fabs f2, f1
/* 80100C4C 000FDBAC  C0 02 9D 88 */	lfs f0, lbl_803E9F88@sda21(r2)
/* 80100C50 000FDBB0  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80100C54 000FDBB4  40 80 00 08 */	bge lbl_80100C5C
/* 80100C58 000FDBB8  C0 22 9C 60 */	lfs f1, lbl_803E9E60@sda21(r2)
lbl_80100C5C:
/* 80100C5C 000FDBBC  EC 01 07 72 */	fmuls f0, f1, f29
/* 80100C60 000FDBC0  C0 3F 02 F8 */	lfs f1, 0x2f8(r31)
/* 80100C64 000FDBC4  EC 21 00 2A */	fadds f1, f1, f0
/* 80100C68 000FDBC8  4B F3 79 21 */	bl roundAng__Ff
/* 80100C6C 000FDBCC  D0 3F 02 F8 */	stfs f1, 0x2f8(r31)
/* 80100C70 000FDBD0  C0 5F 02 F8 */	lfs f2, 0x2f8(r31)
/* 80100C74 000FDBD4  C0 22 9D 90 */	lfs f1, lbl_803E9F90@sda21(r2)
/* 80100C78 000FDBD8  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 80100C7C 000FDBDC  40 81 00 18 */	ble lbl_80100C94
/* 80100C80 000FDBE0  C0 02 9D 70 */	lfs f0, lbl_803E9F70@sda21(r2)
/* 80100C84 000FDBE4  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80100C88 000FDBE8  40 80 00 0C */	bge lbl_80100C94
/* 80100C8C 000FDBEC  D0 3F 02 F8 */	stfs f1, 0x2f8(r31)
/* 80100C90 000FDBF0  48 00 00 24 */	b lbl_80100CB4
lbl_80100C94:
/* 80100C94 000FDBF4  C0 22 9D 94 */	lfs f1, lbl_803E9F94@sda21(r2)
/* 80100C98 000FDBF8  FC 02 08 40 */	fcmpo cr0, f2, f1
/* 80100C9C 000FDBFC  40 80 00 18 */	bge lbl_80100CB4
/* 80100CA0 000FDC00  C0 02 9D 70 */	lfs f0, lbl_803E9F70@sda21(r2)
/* 80100CA4 000FDC04  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80100CA8 000FDC08  4C 41 13 82 */	cror 2, 1, 2
/* 80100CAC 000FDC0C  40 82 00 08 */	bne lbl_80100CB4
/* 80100CB0 000FDC10  D0 3F 02 F8 */	stfs f1, 0x2f8(r31)
lbl_80100CB4:
/* 80100CB4 000FDC14  88 7F 02 F0 */	lbz r3, 0x2f0(r31)
/* 80100CB8 000FDC18  28 03 00 00 */	cmplwi r3, 0
/* 80100CBC 000FDC1C  41 82 00 30 */	beq lbl_80100CEC
/* 80100CC0 000FDC20  38 03 FF FF */	addi r0, r3, -1
/* 80100CC4 000FDC24  98 1F 02 F0 */	stb r0, 0x2f0(r31)
/* 80100CC8 000FDC28  88 1F 02 F0 */	lbz r0, 0x2f0(r31)
/* 80100CCC 000FDC2C  28 00 00 00 */	cmplwi r0, 0
/* 80100CD0 000FDC30  40 82 00 1C */	bne lbl_80100CEC
/* 80100CD4 000FDC34  38 00 00 00 */	li r0, 0
/* 80100CD8 000FDC38  90 1F 02 EC */	stw r0, 0x2ec(r31)
/* 80100CDC 000FDC3C  C0 02 9C 60 */	lfs f0, lbl_803E9E60@sda21(r2)
/* 80100CE0 000FDC40  D0 1F 02 F8 */	stfs f0, 0x2f8(r31)
/* 80100CE4 000FDC44  D0 1F 02 F4 */	stfs f0, 0x2f4(r31)
/* 80100CE8 000FDC48  98 1F 02 F0 */	stb r0, 0x2f0(r31)
lbl_80100CEC:
/* 80100CEC 000FDC4C  80 01 00 74 */	lwz r0, 0x74(r1)
/* 80100CF0 000FDC50  CB E1 00 68 */	lfd f31, 0x68(r1)
/* 80100CF4 000FDC54  CB C1 00 60 */	lfd f30, 0x60(r1)
/* 80100CF8 000FDC58  CB A1 00 58 */	lfd f29, 0x58(r1)
/* 80100CFC 000FDC5C  CB 81 00 50 */	lfd f28, 0x50(r1)
/* 80100D00 000FDC60  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 80100D04 000FDC64  38 21 00 70 */	addi r1, r1, 0x70
/* 80100D08 000FDC68  7C 08 03 A6 */	mtlr r0
/* 80100D0C 000FDC6C  4E 80 00 20 */	blr 

.global updateHeadMatrix__4NaviFv
updateHeadMatrix__4NaviFv:
/* 80100D10 000FDC70  7C 08 02 A6 */	mflr r0
/* 80100D14 000FDC74  90 01 00 04 */	stw r0, 4(r1)
/* 80100D18 000FDC78  94 21 FE 10 */	stwu r1, -0x1f0(r1)
/* 80100D1C 000FDC7C  DB E1 01 E8 */	stfd f31, 0x1e8(r1)
/* 80100D20 000FDC80  DB C1 01 E0 */	stfd f30, 0x1e0(r1)
/* 80100D24 000FDC84  DB A1 01 D8 */	stfd f29, 0x1d8(r1)
/* 80100D28 000FDC88  93 E1 01 D4 */	stw r31, 0x1d4(r1)
/* 80100D2C 000FDC8C  93 C1 01 D0 */	stw r30, 0x1d0(r1)
/* 80100D30 000FDC90  7C 7E 1B 78 */	mr r30, r3
/* 80100D34 000FDC94  80 03 02 EC */	lwz r0, 0x2ec(r3)
/* 80100D38 000FDC98  28 00 00 00 */	cmplwi r0, 0
/* 80100D3C 000FDC9C  40 82 00 10 */	bne lbl_80100D4C
/* 80100D40 000FDCA0  88 1E 02 F0 */	lbz r0, 0x2f0(r30)
/* 80100D44 000FDCA4  28 00 00 00 */	cmplwi r0, 0
/* 80100D48 000FDCA8  41 82 03 20 */	beq lbl_80101068
lbl_80100D4C:
/* 80100D4C 000FDCAC  7F C3 F3 78 */	mr r3, r30
/* 80100D50 000FDCB0  4B FF FC 81 */	bl updateLook__4NaviFv
/* 80100D54 000FDCB4  80 7E 08 2C */	lwz r3, 0x82c(r30)
/* 80100D58 000FDCB8  38 80 00 02 */	li r4, 2
/* 80100D5C 000FDCBC  80 63 00 00 */	lwz r3, 0(r3)
/* 80100D60 000FDCC0  4B F3 42 89 */	bl getAnimMatrix__9BaseShapeFi
/* 80100D64 000FDCC4  80 A3 00 00 */	lwz r5, 0(r3)
/* 80100D68 000FDCC8  38 81 01 4C */	addi r4, r1, 0x14c
/* 80100D6C 000FDCCC  80 03 00 04 */	lwz r0, 4(r3)
/* 80100D70 000FDCD0  90 A1 01 8C */	stw r5, 0x18c(r1)
/* 80100D74 000FDCD4  90 01 01 90 */	stw r0, 0x190(r1)
/* 80100D78 000FDCD8  80 A3 00 08 */	lwz r5, 8(r3)
/* 80100D7C 000FDCDC  80 03 00 0C */	lwz r0, 0xc(r3)
/* 80100D80 000FDCE0  90 A1 01 94 */	stw r5, 0x194(r1)
/* 80100D84 000FDCE4  90 01 01 98 */	stw r0, 0x198(r1)
/* 80100D88 000FDCE8  80 A3 00 10 */	lwz r5, 0x10(r3)
/* 80100D8C 000FDCEC  80 03 00 14 */	lwz r0, 0x14(r3)
/* 80100D90 000FDCF0  90 A1 01 9C */	stw r5, 0x19c(r1)
/* 80100D94 000FDCF4  90 01 01 A0 */	stw r0, 0x1a0(r1)
/* 80100D98 000FDCF8  80 A3 00 18 */	lwz r5, 0x18(r3)
/* 80100D9C 000FDCFC  80 03 00 1C */	lwz r0, 0x1c(r3)

.section .data, "wa"  # 0x80222DC0 - 0x802E9640
  .4byte 0x6169526f
  .4byte 0x70652e63
  .4byte 0x70700000
  .4byte 0x52656365
  .4byte 0x69766572
  .4byte 0x3c50696b
  .4byte 0x693e0000
  .4byte 0x803e0830
  .4byte 0
  .4byte 0
  .4byte 0x803e0830
  .4byte 0
  .4byte 0x803e0840
  .4byte 0
  .4byte 0
.global __vt__7ActRope
__vt__7ActRope:
  .4byte __RTTI__7ActRope
  .4byte 0
  .4byte "procMsg__15Receiver<4Piki>FP4PikiP3Msg"
  .4byte "procBounceMsg__15Receiver<4Piki>FP4PikiP9MsgBounce"
  .4byte "procStickMsg__15Receiver<4Piki>FP4PikiP8MsgStick"
  .4byte "procHangMsg__15Receiver<4Piki>FP4PikiP7MsgHang"
  .4byte "procTargetMsg__15Receiver<4Piki>FP4PikiP9MsgTarget"
  .4byte "procCollideMsg__15Receiver<4Piki>FP4PikiP10MsgCollide"
  .4byte "procAnimMsg__15Receiver<4Piki>FP4PikiP7MsgAnim"
  .4byte "procDamageMsg__15Receiver<4Piki>FP4PikiP9MsgDamage"
  .4byte "procWallMsg__15Receiver<4Piki>FP4PikiP7MsgWall"
  .4byte "procOffWallMsg__15Receiver<4Piki>FP4PikiP10MsgOffWall"
  .4byte "procUserMsg__15Receiver<4Piki>FP4PikiP7MsgUser"
  .4byte "procGroundMsg__15Receiver<4Piki>FP4PikiP9MsgGround"
  .4byte defaultInitialiser__6ActionFv
  .4byte dump__6ActionFv
  .4byte draw__6ActionFR8Graphics
  .4byte __dt__7ActRopeFv
  .4byte init__7ActRopeFP8Creature
  .4byte exec__7ActRopeFv
  .4byte cleanup__7ActRopeFv
  .4byte resume__6ActionFv
  .4byte restart__6ActionFv
  .4byte resumable__6ActionFv
  .4byte getInfo__6ActionFPc
  .4byte 0x800a7908
  .4byte 0x800a7930
  .4byte 0x800a7944
  .4byte 0x800a7958
  .4byte 0x800a796c
  .4byte 0x800a7980
  .4byte 0x800a7994
  .4byte 0x800a79a8
  .4byte 0x800a791c
  .4byte 0x800a79d0
  .4byte 0x800a79bc
  .4byte 0

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.global lbl_803E07E0
lbl_803E07E0:
	.4byte 0x00000000
	.4byte 0x802B7888
	.4byte 0x00000000
	.4byte 0x802B789C
	.4byte 0x00000000
	.4byte 0x41637469
	.4byte 0x6F6E0000
	.4byte 0x803E07F4
	.4byte 0x802B78AC
.global __RTTI__9ActRescue
__RTTI__9ActRescue:
  .4byte 0x802b787c
  .4byte 0x802b78b8
  .4byte 0
.global lbl_803E0810
lbl_803E0810:
	.4byte 0x726F7065
	.4byte 0x00000000
.global lbl_803E0818
lbl_803E0818:
	.4byte 0x00000000
.global lbl_803E081C
lbl_803E081C:
	.4byte 0x3F800000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
	.4byte 0x00000000
.global lbl_803EACE8
lbl_803EACE8:
	.4byte 0x42C80000
.global lbl_803EACEC
lbl_803EACEC:
	.4byte 0x42480000
.global lbl_803EACF0
lbl_803EACF0:
	.4byte 0x41A00000
.global lbl_803EACF4
lbl_803EACF4:
	.4byte 0x43480000
.global lbl_803EACF8
lbl_803EACF8:
	.4byte 0x43610000
.global lbl_803EACFC
lbl_803EACFC:
	.4byte 0x42200000
.global lbl_803EAD00
lbl_803EAD00:
	.4byte 0x41200000

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
	.4byte 0x80000000
.global lbl_803EC3C0
lbl_803EC3C0:
	.4byte 0x40800000
.global lbl_803EC3C4
lbl_803EC3C4:
	.4byte 0x3E800000
.global lbl_803EC3C8
lbl_803EC3C8:
	.4byte 0x00000000
.global lbl_803EC3CC
lbl_803EC3CC:
	.4byte 0x3F800000
.global lbl_803EC3D0
lbl_803EC3D0:
	.4byte 0x3DCCCCCD
.global lbl_803EC3D4
lbl_803EC3D4:
	.4byte 0x3FC90FDB
.global lbl_803EC3D8
lbl_803EC3D8:
	.4byte 0xC3F00000
