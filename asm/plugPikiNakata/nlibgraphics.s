.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__7NCameraFP6Camera, global
/* 8011D95C 0011A8BC  7C 08 02 A6 */	mflr r0
/* 8011D960 0011A8C0  90 01 00 04 */	stw r0, 4(r1)
/* 8011D964 0011A8C4  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 8011D968 0011A8C8  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8011D96C 0011A8CC  3B E4 00 00 */	addi r31, r4, 0
/* 8011D970 0011A8D0  93 C1 00 10 */	stw r30, 0x10(r1)
/* 8011D974 0011A8D4  3B C3 00 00 */	addi r30, r3, 0
/* 8011D978 0011A8D8  38 7E 00 08 */	addi r3, r30, 8
/* 8011D97C 0011A8DC  4B FF F4 D9 */	bl __ct__9NVector3fFv
/* 8011D980 0011A8E0  38 7E 00 14 */	addi r3, r30, 0x14
/* 8011D984 0011A8E4  4B FF F4 D1 */	bl __ct__9NVector3fFv
/* 8011D988 0011A8E8  93 FE 00 04 */	stw r31, 4(r30)
/* 8011D98C 0011A8EC  7F C3 F3 78 */	mr r3, r30
/* 8011D990 0011A8F0  C0 0D E3 38 */	lfs f0, lbl_803E3058@sda21(r13)
/* 8011D994 0011A8F4  D0 1E 00 08 */	stfs f0, 8(r30)
/* 8011D998 0011A8F8  C0 0D E3 3C */	lfs f0, lbl_803E305C@sda21(r13)
/* 8011D99C 0011A8FC  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8011D9A0 0011A900  C0 0D E3 40 */	lfs f0, lbl_803E3060@sda21(r13)
/* 8011D9A4 0011A904  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 8011D9A8 0011A908  C0 0D E3 44 */	lfs f0, lbl_803E3064@sda21(r13)
/* 8011D9AC 0011A90C  D0 1E 00 14 */	stfs f0, 0x14(r30)
/* 8011D9B0 0011A910  C0 0D E3 48 */	lfs f0, lbl_803E3068@sda21(r13)
/* 8011D9B4 0011A914  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 8011D9B8 0011A918  C0 0D E3 4C */	lfs f0, lbl_803E306C@sda21(r13)
/* 8011D9BC 0011A91C  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8011D9C0 0011A920  C0 02 A0 38 */	lfs f0, lbl_803EA238@sda21(r2)
/* 8011D9C4 0011A924  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8011D9C8 0011A928  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8011D9CC 0011A92C  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8011D9D0 0011A930  83 C1 00 10 */	lwz r30, 0x10(r1)
/* 8011D9D4 0011A934  38 21 00 18 */	addi r1, r1, 0x18
/* 8011D9D8 0011A938  7C 08 03 A6 */	mtlr r0
/* 8011D9DC 0011A93C  4E 80 00 20 */	blr 
.endfn __ct__7NCameraFP6Camera

.fn makeMatrix__7NCameraFv, global
/* 8011D9E0 0011A940  7C 08 02 A6 */	mflr r0
/* 8011D9E4 0011A944  90 01 00 04 */	stw r0, 4(r1)
/* 8011D9E8 0011A948  94 21 FF 60 */	stwu r1, -0xa0(r1)
/* 8011D9EC 0011A94C  93 E1 00 9C */	stw r31, 0x9c(r1)
/* 8011D9F0 0011A950  93 C1 00 98 */	stw r30, 0x98(r1)
/* 8011D9F4 0011A954  93 A1 00 94 */	stw r29, 0x94(r1)
/* 8011D9F8 0011A958  3B A3 00 00 */	addi r29, r3, 0
/* 8011D9FC 0011A95C  3B FD 00 14 */	addi r31, r29, 0x14
/* 8011DA00 0011A960  3B DD 00 08 */	addi r30, r29, 8
/* 8011DA04 0011A964  38 9E 00 00 */	addi r4, r30, 0
/* 8011DA08 0011A968  38 BF 00 00 */	addi r5, r31, 0
/* 8011DA0C 0011A96C  38 61 00 80 */	addi r3, r1, 0x80
/* 8011DA10 0011A970  4B FF F5 1D */	bl __ct__9NVector3fFR8Vector3fR8Vector3f
/* 8011DA14 0011A974  38 61 00 80 */	addi r3, r1, 0x80
/* 8011DA18 0011A978  4B FF F6 E9 */	bl normalize__9NVector3fFv
/* 8011DA1C 0011A97C  38 61 00 68 */	addi r3, r1, 0x68
/* 8011DA20 0011A980  38 81 00 80 */	addi r4, r1, 0x80
/* 8011DA24 0011A984  4B FF E5 29 */	bl __ct__12NOrientationFR8Vector3f
/* 8011DA28 0011A988  38 61 00 68 */	addi r3, r1, 0x68
/* 8011DA2C 0011A98C  4B FF E5 E9 */	bl normalize__12NOrientationFv
/* 8011DA30 0011A990  C0 01 00 74 */	lfs f0, 0x74(r1)
/* 8011DA34 0011A994  38 61 00 4C */	addi r3, r1, 0x4c
/* 8011DA38 0011A998  38 81 00 80 */	addi r4, r1, 0x80
/* 8011DA3C 0011A99C  D0 01 00 5C */	stfs f0, 0x5c(r1)
/* 8011DA40 0011A9A0  C0 01 00 78 */	lfs f0, 0x78(r1)
/* 8011DA44 0011A9A4  D0 01 00 60 */	stfs f0, 0x60(r1)
/* 8011DA48 0011A9A8  C0 01 00 7C */	lfs f0, 0x7c(r1)
/* 8011DA4C 0011A9AC  D0 01 00 64 */	stfs f0, 0x64(r1)
/* 8011DA50 0011A9B0  C0 3D 00 00 */	lfs f1, 0(r29)
/* 8011DA54 0011A9B4  4B FF E2 2D */	bl __ct__12NAxisAngle4fFR9NVector3ff
/* 8011DA58 0011A9B8  38 61 00 0C */	addi r3, r1, 0xc
/* 8011DA5C 0011A9BC  4B FF EF A5 */	bl __ct__12NTransform3DFv
/* 8011DA60 0011A9C0  38 61 00 0C */	addi r3, r1, 0xc
/* 8011DA64 0011A9C4  38 81 00 4C */	addi r4, r1, 0x4c
/* 8011DA68 0011A9C8  4B FF F2 69 */	bl inputAxisAngle__12NTransform3DFR12NAxisAngle4f
/* 8011DA6C 0011A9CC  38 61 00 0C */	addi r3, r1, 0xc
/* 8011DA70 0011A9D0  38 81 00 5C */	addi r4, r1, 0x5c
/* 8011DA74 0011A9D4  4B FF F2 31 */	bl transform__12NTransform3DFR8Vector3f
/* 8011DA78 0011A9D8  38 61 00 5C */	addi r3, r1, 0x5c
/* 8011DA7C 0011A9DC  4B FF F6 85 */	bl normalize__9NVector3fFv
/* 8011DA80 0011A9E0  80 7D 00 04 */	lwz r3, 4(r29)
/* 8011DA84 0011A9E4  38 9E 00 00 */	addi r4, r30, 0
/* 8011DA88 0011A9E8  38 BF 00 00 */	addi r5, r31, 0
/* 8011DA8C 0011A9EC  38 C1 00 5C */	addi r6, r1, 0x5c
/* 8011DA90 0011A9F0  4B F2 55 7D */	bl calcLookAt__11CullFrustumFR8Vector3fR8Vector3fP8Vector3f
/* 8011DA94 0011A9F4  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 8011DA98 0011A9F8  83 E1 00 9C */	lwz r31, 0x9c(r1)
/* 8011DA9C 0011A9FC  83 C1 00 98 */	lwz r30, 0x98(r1)
/* 8011DAA0 0011AA00  83 A1 00 94 */	lwz r29, 0x94(r1)
/* 8011DAA4 0011AA04  38 21 00 A0 */	addi r1, r1, 0xa0
/* 8011DAA8 0011AA08  7C 08 03 A6 */	mtlr r0
/* 8011DAAC 0011AA0C  4E 80 00 20 */	blr 
.endfn makeMatrix__7NCameraFv

.fn makeCamera__7NCameraFv, global
/* 8011DAB0 0011AA10  7C 08 02 A6 */	mflr r0
/* 8011DAB4 0011AA14  90 01 00 04 */	stw r0, 4(r1)
/* 8011DAB8 0011AA18  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8011DABC 0011AA1C  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8011DAC0 0011AA20  7C 7F 1B 78 */	mr r31, r3
/* 8011DAC4 0011AA24  38 9F 00 14 */	addi r4, r31, 0x14
/* 8011DAC8 0011AA28  80 A3 00 04 */	lwz r5, 4(r3)
/* 8011DACC 0011AA2C  38 61 00 18 */	addi r3, r1, 0x18
/* 8011DAD0 0011AA30  C0 1F 00 08 */	lfs f0, 8(r31)
/* 8011DAD4 0011AA34  38 C5 01 64 */	addi r6, r5, 0x164
/* 8011DAD8 0011AA38  D0 05 01 64 */	stfs f0, 0x164(r5)
/* 8011DADC 0011AA3C  38 BF 00 08 */	addi r5, r31, 8
/* 8011DAE0 0011AA40  C0 1F 00 0C */	lfs f0, 0xc(r31)
/* 8011DAE4 0011AA44  D0 06 00 04 */	stfs f0, 4(r6)
/* 8011DAE8 0011AA48  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 8011DAEC 0011AA4C  D0 06 00 08 */	stfs f0, 8(r6)
/* 8011DAF0 0011AA50  4B FF F4 3D */	bl __ct__9NVector3fFR8Vector3fR8Vector3f
/* 8011DAF4 0011AA54  38 61 00 0C */	addi r3, r1, 0xc
/* 8011DAF8 0011AA58  38 81 00 18 */	addi r4, r1, 0x18
/* 8011DAFC 0011AA5C  4B FF E8 E5 */	bl __ct__8NPolar3fFR8Vector3f
/* 8011DB00 0011AA60  C0 2D E3 5C */	lfs f1, pi__6NMathF@sda21(r13)
/* 8011DB04 0011AA64  C0 02 A0 3C */	lfs f0, lbl_803EA23C@sda21(r2)
/* 8011DB08 0011AA68  C0 41 00 10 */	lfs f2, 0x10(r1)
/* 8011DB0C 0011AA6C  EC 01 00 32 */	fmuls f0, f1, f0
/* 8011DB10 0011AA70  80 7F 00 04 */	lwz r3, 4(r31)
/* 8011DB14 0011AA74  EC 02 00 28 */	fsubs f0, f2, f0
/* 8011DB18 0011AA78  D0 03 03 20 */	stfs f0, 0x320(r3)
/* 8011DB1C 0011AA7C  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 8011DB20 0011AA80  80 7F 00 04 */	lwz r3, 4(r31)
/* 8011DB24 0011AA84  D0 03 03 24 */	stfs f0, 0x324(r3)
/* 8011DB28 0011AA88  C0 02 A0 38 */	lfs f0, lbl_803EA238@sda21(r2)
/* 8011DB2C 0011AA8C  80 7F 00 04 */	lwz r3, 4(r31)
/* 8011DB30 0011AA90  D0 03 03 28 */	stfs f0, 0x328(r3)
/* 8011DB34 0011AA94  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8011DB38 0011AA98  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8011DB3C 0011AA9C  38 21 00 30 */	addi r1, r1, 0x30
/* 8011DB40 0011AAA0  7C 08 03 A6 */	mtlr r0
/* 8011DB44 0011AAA4  4E 80 00 20 */	blr 
.endfn makeCamera__7NCameraFv

.section .sdata, "wa"  # 0x803DCD20 - 0x803E7820
.balign 8
.obj lbl_803E3058, local
	.float 0.0
.endobj lbl_803E3058
.obj lbl_803E305C, local
	.float 0.0
.endobj lbl_803E305C
.obj lbl_803E3060, local
	.float 0.0
.endobj lbl_803E3060
.obj lbl_803E3064, local
	.float 0.0
.endobj lbl_803E3064
.obj lbl_803E3068, local
	.float 0.0
.endobj lbl_803E3068
.obj lbl_803E306C, local
	.float 1.0
.endobj lbl_803E306C

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803EA238, local
	.float 0.0
.endobj lbl_803EA238
.obj lbl_803EA23C, local
	.float 0.5
.endobj lbl_803EA23C
