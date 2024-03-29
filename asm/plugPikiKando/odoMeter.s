.include "macros.inc"
.section .text, "ax"  # 0x80005560 - 0x80221F60
.fn __ct__8OdoMeterFv, global
/* 800CD804 000CA764  C0 02 96 48 */	lfs f0, lbl_803E9848@sda21(r2)
/* 800CD808 000CA768  D0 03 00 00 */	stfs f0, 0(r3)
/* 800CD80C 000CA76C  D0 03 00 04 */	stfs f0, 4(r3)
/* 800CD810 000CA770  4E 80 00 20 */	blr 
.endfn __ct__8OdoMeterFv

.fn start__8OdoMeterFff, global
/* 800CD814 000CA774  D0 23 00 0C */	stfs f1, 0xc(r3)
/* 800CD818 000CA778  D0 23 00 04 */	stfs f1, 4(r3)
/* 800CD81C 000CA77C  D0 43 00 08 */	stfs f2, 8(r3)
/* 800CD820 000CA780  C0 02 96 48 */	lfs f0, lbl_803E9848@sda21(r2)
/* 800CD824 000CA784  D0 03 00 00 */	stfs f0, 0(r3)
/* 800CD828 000CA788  4E 80 00 20 */	blr 
.endfn start__8OdoMeterFff

.fn moving__8OdoMeterFR8Vector3fR8Vector3f, global
/* 800CD82C 000CA78C  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 800CD830 000CA790  C0 23 00 04 */	lfs f1, 4(r3)
/* 800CD834 000CA794  C0 02 96 48 */	lfs f0, lbl_803E9848@sda21(r2)
/* 800CD838 000CA798  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800CD83C 000CA79C  40 81 00 14 */	ble .L_800CD850
/* 800CD840 000CA7A0  80 CD 2D EC */	lwz r6, gsys@sda21(r13)
/* 800CD844 000CA7A4  C0 06 02 8C */	lfs f0, 0x28c(r6)
/* 800CD848 000CA7A8  EC 01 00 28 */	fsubs f0, f1, f0
/* 800CD84C 000CA7AC  D0 03 00 04 */	stfs f0, 4(r3)
.L_800CD850:
/* 800CD850 000CA7B0  C0 23 00 00 */	lfs f1, 0(r3)
/* 800CD854 000CA7B4  C0 02 96 4C */	lfs f0, lbl_803E984C@sda21(r2)
/* 800CD858 000CA7B8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800CD85C 000CA7BC  40 80 00 AC */	bge .L_800CD908
/* 800CD860 000CA7C0  C0 64 00 04 */	lfs f3, 4(r4)
/* 800CD864 000CA7C4  C0 45 00 04 */	lfs f2, 4(r5)
/* 800CD868 000CA7C8  C0 24 00 00 */	lfs f1, 0(r4)
/* 800CD86C 000CA7CC  C0 05 00 00 */	lfs f0, 0(r5)
/* 800CD870 000CA7D0  EC 63 10 28 */	fsubs f3, f3, f2
/* 800CD874 000CA7D4  C0 44 00 08 */	lfs f2, 8(r4)
/* 800CD878 000CA7D8  EC 81 00 28 */	fsubs f4, f1, f0
/* 800CD87C 000CA7DC  C0 05 00 08 */	lfs f0, 8(r5)
/* 800CD880 000CA7E0  EC 23 00 F2 */	fmuls f1, f3, f3
/* 800CD884 000CA7E4  EC 62 00 28 */	fsubs f3, f2, f0
/* 800CD888 000CA7E8  C0 02 96 48 */	lfs f0, lbl_803E9848@sda21(r2)
/* 800CD88C 000CA7EC  EC 44 01 32 */	fmuls f2, f4, f4
/* 800CD890 000CA7F0  EC 63 00 F2 */	fmuls f3, f3, f3
/* 800CD894 000CA7F4  EC 22 08 2A */	fadds f1, f2, f1
/* 800CD898 000CA7F8  EC 83 08 2A */	fadds f4, f3, f1
/* 800CD89C 000CA7FC  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 800CD8A0 000CA800  40 81 00 5C */	ble .L_800CD8FC
/* 800CD8A4 000CA804  FC 20 20 34 */	frsqrte f1, f4
/* 800CD8A8 000CA808  C8 62 96 50 */	lfd f3, lbl_803E9850@sda21(r2)
/* 800CD8AC 000CA80C  C8 42 96 58 */	lfd f2, lbl_803E9858@sda21(r2)
/* 800CD8B0 000CA810  FC 01 00 72 */	fmul f0, f1, f1
/* 800CD8B4 000CA814  FC 23 00 72 */	fmul f1, f3, f1
/* 800CD8B8 000CA818  FC 04 00 32 */	fmul f0, f4, f0
/* 800CD8BC 000CA81C  FC 02 00 28 */	fsub f0, f2, f0
/* 800CD8C0 000CA820  FC 21 00 32 */	fmul f1, f1, f0
/* 800CD8C4 000CA824  FC 01 00 72 */	fmul f0, f1, f1
/* 800CD8C8 000CA828  FC 23 00 72 */	fmul f1, f3, f1
/* 800CD8CC 000CA82C  FC 04 00 32 */	fmul f0, f4, f0
/* 800CD8D0 000CA830  FC 02 00 28 */	fsub f0, f2, f0
/* 800CD8D4 000CA834  FC 21 00 32 */	fmul f1, f1, f0
/* 800CD8D8 000CA838  FC 01 00 72 */	fmul f0, f1, f1
/* 800CD8DC 000CA83C  FC 23 00 72 */	fmul f1, f3, f1
/* 800CD8E0 000CA840  FC 04 00 32 */	fmul f0, f4, f0
/* 800CD8E4 000CA844  FC 02 00 28 */	fsub f0, f2, f0
/* 800CD8E8 000CA848  FC 01 00 32 */	fmul f0, f1, f0
/* 800CD8EC 000CA84C  FC 04 00 32 */	fmul f0, f4, f0
/* 800CD8F0 000CA850  FC 00 00 18 */	frsp f0, f0
/* 800CD8F4 000CA854  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 800CD8F8 000CA858  C0 81 00 38 */	lfs f4, 0x38(r1)
.L_800CD8FC:
/* 800CD8FC 000CA85C  C0 03 00 00 */	lfs f0, 0(r3)
/* 800CD900 000CA860  EC 00 20 2A */	fadds f0, f0, f4
/* 800CD904 000CA864  D0 03 00 00 */	stfs f0, 0(r3)
.L_800CD908:
/* 800CD908 000CA868  C0 03 00 04 */	lfs f0, 4(r3)
/* 800CD90C 000CA86C  C0 42 96 48 */	lfs f2, lbl_803E9848@sda21(r2)
/* 800CD910 000CA870  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 800CD914 000CA874  4C 40 13 82 */	cror 2, 0, 2
/* 800CD918 000CA878  40 82 00 2C */	bne .L_800CD944
/* 800CD91C 000CA87C  C0 23 00 00 */	lfs f1, 0(r3)
/* 800CD920 000CA880  C0 03 00 08 */	lfs f0, 8(r3)
/* 800CD924 000CA884  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800CD928 000CA888  40 80 00 10 */	bge .L_800CD938
/* 800CD92C 000CA88C  D0 43 00 00 */	stfs f2, 0(r3)
/* 800CD930 000CA890  38 60 00 00 */	li r3, 0
/* 800CD934 000CA894  48 00 00 14 */	b .L_800CD948
.L_800CD938:
/* 800CD938 000CA898  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 800CD93C 000CA89C  D0 03 00 04 */	stfs f0, 4(r3)
/* 800CD940 000CA8A0  D0 43 00 00 */	stfs f2, 0(r3)
.L_800CD944:
/* 800CD944 000CA8A4  38 60 00 01 */	li r3, 1
.L_800CD948:
/* 800CD948 000CA8A8  38 21 00 60 */	addi r1, r1, 0x60
/* 800CD94C 000CA8AC  4E 80 00 20 */	blr 
.endfn moving__8OdoMeterFR8Vector3fR8Vector3f

.section .sdata2, "a"  # 0x803E8200 - 0x803EC840
.balign 8
.obj lbl_803E9848, local
	.float 0.0
.endobj lbl_803E9848
.balign 4
.obj lbl_803E984C, local
	.float 100.0
.endobj lbl_803E984C
.balign 8
.obj lbl_803E9850, local
	.double 0.5
.endobj lbl_803E9850
.balign 8
.obj lbl_803E9858, local
	.double 3.0
.endobj lbl_803E9858
