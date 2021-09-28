

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014B124
 * Size:	000244
 */
void TekiNakata::makeTekiParameters(TekiMgr *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  li        r3, 0x88
  stw       r30, 0x10(r1)
  bl        -0x10413C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x30
  bl        -0x10BCC

.loc_0x30:
  stw       r30, 0x4C(r31)
  li        r3, 0x88
  bl        -0x104158
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x4C
  bl        -0x1C298

.loc_0x4C:
  stw       r30, 0x50(r31)
  li        r3, 0x88
  bl        -0x104174
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x68
  bl        -0x1CAC0

.loc_0x68:
  stw       r30, 0x54(r31)
  li        r3, 0x88
  bl        -0x104190
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x84
  bl        -0x22C00

.loc_0x84:
  stw       r30, 0x58(r31)
  li        r3, 0x88
  bl        -0x1041AC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xA0
  bl        -0xBE38

.loc_0xA0:
  stw       r30, 0x5C(r31)
  li        r3, 0x88
  bl        -0x1041C8
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xBC
  bl        -0x19278

.loc_0xBC:
  stw       r30, 0x60(r31)
  li        r3, 0x88
  bl        -0x1041E4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xD8
  bl        -0x18DB8

.loc_0xD8:
  stw       r30, 0x64(r31)
  li        r3, 0x88
  bl        -0x104200
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xF4
  bl        -0xD6DC

.loc_0xF4:
  stw       r30, 0x68(r31)
  li        r3, 0x88
  bl        -0x10421C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x110
  bl        -0x206EC

.loc_0x110:
  stw       r30, 0x6C(r31)
  li        r3, 0x88
  bl        -0x104238
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x12C
  bl        -0x1B630

.loc_0x12C:
  stw       r30, 0x70(r31)
  li        r3, 0x88
  bl        -0x104254
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x148
  bl        -0x9214

.loc_0x148:
  stw       r30, 0x74(r31)
  li        r3, 0x88
  bl        -0x104270
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x164
  bl        -0x155E0

.loc_0x164:
  stw       r30, 0x78(r31)
  li        r3, 0x88
  bl        -0x10428C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x180
  bl        -0x1D1E4

.loc_0x180:
  stw       r30, 0x7C(r31)
  li        r3, 0x88
  bl        -0x1042A8
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x19C
  bl        -0x8270

.loc_0x19C:
  stw       r30, 0x80(r31)
  li        r3, 0x88
  bl        -0x1042C4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1B8
  bl        -0x8144

.loc_0x1B8:
  stw       r30, 0x84(r31)
  li        r3, 0x88
  bl        -0x1042E0
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1D4
  bl        -0x229AC

.loc_0x1D4:
  stw       r30, 0xC8(r31)
  li        r3, 0x88
  bl        -0x1042FC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1F0
  bl        -0xBB40

.loc_0x1F0:
  stw       r30, 0xCC(r31)
  li        r3, 0x88
  bl        -0x104318
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x20C
  bl        -0x107E4

.loc_0x20C:
  stw       r30, 0xD0(r31)
  li        r3, 0x88
  bl        -0x104334
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x228
  bl        -0x225DC

.loc_0x228:
  stw       r30, 0xC4(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014B368
 * Size:	000690
 */
void TekiNakata::makeTekis(TekiMgr *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x70(r1)
  stw       r31, 0x6C(r1)
  mr        r31, r3
  stw       r30, 0x68(r1)
  stw       r29, 0x64(r1)
  lbz       r0, 0x164(r3)
  cmplwi    r0, 0
  beq-      .loc_0x74
  lwz       r29, 0x4C(r31)
  li        r3, 0x14
  bl        -0x104394
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x48
  mr        r4, r29
  bl        -0x10328

.loc_0x48:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x0(r4)
  bl        -0x1043BC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x6C
  bl        -0x10ED0

.loc_0x6C:
  lwz       r3, 0x44(r31)
  stw       r30, 0x0(r3)

.loc_0x74:
  lbz       r0, 0x165(r31)
  cmplwi    r0, 0
  beq-      .loc_0xAC
  lwz       r29, 0x50(r31)
  li        r3, 0x14
  bl        -0x1043EC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xA0
  mr        r4, r29
  bl        -0x1C418

.loc_0xA0:
  lwz       r3, 0x3C(r31)
  lwz       r3, 0x4(r3)
  stw       r30, 0x4(r3)

.loc_0xAC:
  lbz       r0, 0x166(r31)
  cmplwi    r0, 0
  beq-      .loc_0x104
  lwz       r29, 0x54(r31)
  li        r3, 0x14
  bl        -0x104424
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xD8
  mr        r4, r29
  bl        -0x1CBE8

.loc_0xD8:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x8(r4)
  bl        -0x10444C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xFC
  bl        -0x1CC90

.loc_0xFC:
  lwz       r3, 0x44(r31)
  stw       r30, 0x8(r3)

.loc_0x104:
  lbz       r0, 0x167(r31)
  cmplwi    r0, 0
  beq-      .loc_0x15C
  lwz       r29, 0x58(r31)
  li        r3, 0x14
  bl        -0x10447C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x130
  mr        r4, r29
  bl        -0x2238C

.loc_0x130:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0xC(r4)
  bl        -0x1044A4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x154
  bl        -0x22F98

.loc_0x154:
  lwz       r3, 0x44(r31)
  stw       r30, 0xC(r3)

.loc_0x15C:
  lbz       r0, 0x168(r31)
  cmplwi    r0, 0
  beq-      .loc_0x1B4
  lwz       r29, 0x5C(r31)
  li        r3, 0x14
  bl        -0x1044D4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x188
  mr        r4, r29
  bl        -0xB8E0

.loc_0x188:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x10(r4)
  bl        -0x1044FC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1AC
  bl        -0xC20C

.loc_0x1AC:
  lwz       r3, 0x44(r31)
  stw       r30, 0x10(r3)

.loc_0x1B4:
  lbz       r0, 0x169(r31)
  cmplwi    r0, 0
  beq-      .loc_0x1EC
  lwz       r29, 0x60(r31)
  li        r3, 0x14
  bl        -0x10452C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1E0
  mr        r4, r29
  bl        -0x19530

.loc_0x1E0:
  lwz       r3, 0x3C(r31)
  lwz       r3, 0x4(r3)
  stw       r30, 0x14(r3)

.loc_0x1EC:
  lbz       r0, 0x16A(r31)
  cmplwi    r0, 0
  beq-      .loc_0x244
  lwz       r29, 0x64(r31)
  li        r3, 0x14
  bl        -0x104564
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x218
  mr        r4, r29
  bl        -0x18D38

.loc_0x218:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x18(r4)
  bl        -0x10458C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x23C
  bl        -0x18DE0

.loc_0x23C:
  lwz       r3, 0x44(r31)
  stw       r30, 0x18(r3)

.loc_0x244:
  lbz       r0, 0x16B(r31)
  cmplwi    r0, 0
  beq-      .loc_0x29C
  lwz       r29, 0x68(r31)
  li        r3, 0x14
  bl        -0x1045BC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x270
  mr        r4, r29
  bl        -0xD8A8

.loc_0x270:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x1C(r4)
  bl        -0x1045E4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x294
  bl        -0xDB44

.loc_0x294:
  lwz       r3, 0x44(r31)
  stw       r30, 0x1C(r3)

.loc_0x29C:
  lbz       r0, 0x16C(r31)
  cmplwi    r0, 0
  beq-      .loc_0x2F4
  lwz       r29, 0x6C(r31)
  li        r3, 0x14
  bl        -0x104614
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x2C8
  mr        r4, r29
  bl        -0x20664

.loc_0x2C8:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x20(r4)
  bl        -0x10463C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x2EC
  bl        -0x20B90

.loc_0x2EC:
  lwz       r3, 0x44(r31)
  stw       r30, 0x20(r3)

.loc_0x2F4:
  lbz       r0, 0x16D(r31)
  cmplwi    r0, 0
  beq-      .loc_0x34C
  lwz       r29, 0x70(r31)
  li        r3, 0x14
  bl        -0x10466C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x320
  mr        r4, r29
  bl        -0x1B550

.loc_0x320:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x24(r4)
  bl        -0x104694
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x344
  bl        -0x1BB10

.loc_0x344:
  lwz       r3, 0x44(r31)
  stw       r30, 0x24(r3)

.loc_0x34C:
  lbz       r0, 0x16E(r31)
  cmplwi    r0, 0
  beq-      .loc_0x3A4
  lwz       r29, 0x74(r31)
  li        r3, 0x14
  bl        -0x1046C4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x378
  mr        r4, r29
  bl        -0x94FC

.loc_0x378:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x28(r4)
  bl        -0x1046EC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x39C
  bl        -0x9730

.loc_0x39C:
  lwz       r3, 0x44(r31)
  stw       r30, 0x28(r3)

.loc_0x3A4:
  lbz       r0, 0x16F(r31)
  cmplwi    r0, 0
  beq-      .loc_0x3FC
  lwz       r29, 0x78(r31)
  li        r3, 0x14
  bl        -0x10471C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x3D0
  mr        r4, r29
  bl        -0x1552C

.loc_0x3D0:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x2C(r4)
  bl        -0x104744
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x3F4
  bl        -0x15B38

.loc_0x3F4:
  lwz       r3, 0x44(r31)
  stw       r30, 0x2C(r3)

.loc_0x3FC:
  lbz       r0, 0x170(r31)
  cmplwi    r0, 0
  beq-      .loc_0x434
  lwz       r29, 0x7C(r31)
  li        r3, 0x14
  bl        -0x104774
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x428
  mr        r4, r29
  bl        -0x1D648

.loc_0x428:
  lwz       r3, 0x3C(r31)
  lwz       r3, 0x4(r3)
  stw       r30, 0x30(r3)

.loc_0x434:
  addi      r3, r31, 0x171
  lbz       r0, 0x171(r31)
  cmplwi    r0, 0
  bne-      .loc_0x450
  lbz       r0, 0x16E(r31)
  cmplwi    r0, 0
  beq-      .loc_0x4A4

.loc_0x450:
  li        r0, 0x1
  stb       r0, 0x0(r3)
  li        r3, 0x14
  lwz       r29, 0x80(r31)
  bl        -0x1047C4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x478
  mr        r4, r29
  bl        -0x84FC

.loc_0x478:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x34(r4)
  bl        -0x1047EC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x49C
  bl        -0x8838

.loc_0x49C:
  lwz       r3, 0x44(r31)
  stw       r30, 0x34(r3)

.loc_0x4A4:
  addi      r3, r31, 0x172
  lbz       r0, 0x172(r31)
  cmplwi    r0, 0
  bne-      .loc_0x4C0
  lbz       r0, 0x16E(r31)
  cmplwi    r0, 0
  beq-      .loc_0x514

.loc_0x4C0:
  li        r0, 0x1
  stb       r0, 0x0(r3)
  li        r3, 0x14
  lwz       r29, 0x84(r31)
  bl        -0x104834
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x4E8
  mr        r4, r29
  bl        -0x856C

.loc_0x4E8:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x38(r4)
  bl        -0x10485C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x50C
  bl        -0x88A8

.loc_0x50C:
  lwz       r3, 0x44(r31)
  stw       r30, 0x38(r3)

.loc_0x514:
  lbz       r0, 0x183(r31)
  cmplwi    r0, 0
  beq-      .loc_0x56C
  lwz       r29, 0xC8(r31)
  li        r3, 0x14
  bl        -0x10488C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x540
  mr        r4, r29
  bl        -0x2279C

.loc_0x540:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x7C(r4)
  bl        -0x1048B4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x564
  bl        -0x233A8

.loc_0x564:
  lwz       r3, 0x44(r31)
  stw       r30, 0x7C(r3)

.loc_0x56C:
  lbz       r0, 0x184(r31)
  cmplwi    r0, 0
  beq-      .loc_0x5C4
  lwz       r29, 0xCC(r31)
  li        r3, 0x14
  bl        -0x1048E4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x598
  mr        r4, r29
  bl        -0xBCF0

.loc_0x598:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x80(r4)
  bl        -0x10490C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x5BC
  bl        -0xC61C

.loc_0x5BC:
  lwz       r3, 0x44(r31)
  stw       r30, 0x80(r3)

.loc_0x5C4:
  lbz       r0, 0x185(r31)
  cmplwi    r0, 0
  beq-      .loc_0x61C
  lwz       r29, 0xD0(r31)
  li        r3, 0x14
  bl        -0x10493C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x5F0
  mr        r4, r29
  bl        -0x108D0

.loc_0x5F0:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x84(r4)
  bl        -0x104964
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x614
  bl        -0x10EB4

.loc_0x614:
  lwz       r3, 0x44(r31)
  stw       r30, 0x84(r3)

.loc_0x61C:
  lbz       r0, 0x182(r31)
  cmplwi    r0, 0
  beq-      .loc_0x674
  lwz       r29, 0xC4(r31)
  li        r3, 0x14
  bl        -0x104994
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x648
  mr        r4, r29
  bl        -0x228A4

.loc_0x648:
  lwz       r4, 0x3C(r31)
  li        r3, 0x8
  lwz       r4, 0x4(r4)
  stw       r30, 0x78(r4)
  bl        -0x1049BC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x66C
  bl        -0x22CE8

.loc_0x66C:
  lwz       r3, 0x44(r31)
  stw       r30, 0x78(r3)

.loc_0x674:
  lwz       r0, 0x74(r1)
  lwz       r31, 0x6C(r1)
  lwz       r30, 0x68(r1)
  lwz       r29, 0x64(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}