

/*
 * --INFO--
 * Address:	8021E884
 * Size:	000008
 */
void __TRK_get_MSR(void)
{
/*
.loc_0x0:
  mfmsr     r3
  blr
*/
}

/*
 * --INFO--
 * Address:	8021E88C
 * Size:	000008
 */
void __TRK_set_MSR(void)
{
/*
.loc_0x0:
  mtmsr     r3
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_PVR(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_IBAT0U(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_IBAT0L(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_IBAT1U(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_IBAT1L(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_IBAT2U(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_IBAT2L(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_IBAT3U(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_IBAT3L(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_DBAT0U(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_DBAT0L(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_DBAT1U(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_DBAT1L(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_DBAT2U(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_DBAT2L(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_DBAT3U(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __TRK_get_DBAT3L(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021E894
 * Size:	000138
 */
void TRKValidMemory32(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r29, 0xC(r1)
  mr        r30, r5
  add       r31, r4, r3
  subi      r31, r31, 0x1
  cmplw     r31, r3
  li        r5, 0x700
  bge-      .loc_0x38
  li        r3, 0x700
  b         .loc_0x11C

.loc_0x38:
  lis       r4, 0x8022
  addi      r4, r4, 0x2D70
  li        r6, 0
  b         .loc_0x48

.loc_0x48:
  b         .loc_0x4C

.loc_0x4C:
  lwz       r0, 0x4(r4)
  cmplw     r3, r0
  bgt-      .loc_0x118
  lwz       r0, 0x0(r4)
  cmplw     r31, r0
  blt-      .loc_0x118
  rlwinm    r0,r30,0,24,31
  cmplwi    r0, 0
  bne-      .loc_0x84
  rlwinm    r0,r6,4,0,27
  add       r4, r4, r0
  lwz       r0, 0x8(r4)
  cmpwi     r0, 0
  beq-      .loc_0xAC

.loc_0x84:
  rlwinm    r0,r30,0,24,31
  cmplwi    r0, 0x1
  bne-      .loc_0xB4
  lis       r4, 0x8022
  addi      r4, r4, 0x2D70
  rlwinm    r0,r6,4,0,27
  add       r4, r4, r0
  lwz       r0, 0xC(r4)
  cmpwi     r0, 0
  bne-      .loc_0xB4

.loc_0xAC:
  li        r5, 0x700
  b         .loc_0x118

.loc_0xB4:
  lis       r4, 0x8022
  rlwinm    r29,r6,4,0,27
  addi      r0, r4, 0x2D70
  add       r4, r0, r29
  lwz       r0, 0x0(r4)
  li        r5, 0
  cmplw     r3, r0
  bge-      .loc_0xE4
  mr        r5, r30
  sub       r4, r0, r3
  bl        .loc_0x0
  mr        r5, r3

.loc_0xE4:
  cmpwi     r5, 0
  bne-      .loc_0x118
  lis       r3, 0x8022
  addi      r0, r3, 0x2D70
  add       r3, r0, r29
  lwz       r3, 0x4(r3)
  cmplw     r31, r3
  ble-      .loc_0x118
  mr        r5, r30
  sub       r4, r31, r3
  bl        .loc_0x0
  mr        r5, r3
  b         .loc_0x118

.loc_0x118:
  mr        r3, r5

.loc_0x11C:
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  lwz       r29, 0xC(r1)
  addi      r1, r1, 0x18
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021E9CC
 * Size:	00003C
 */
void TRK_ppc_memcpy(void)
{
/*
.loc_0x0:
  mfmsr     r8
  li        r10, 0

.loc_0x8:
  cmpw      r10, r5
  beq-      .loc_0x30
  mtmsr     r7
  sync      
  lbzx      r9, r10, r4
  mtmsr     r6
  sync      
  stbx      r9, r10, r3
  addi      r10, r10, 0x1
  b         .loc_0x8

.loc_0x30:
  mtmsr     r8
  sync      
  blr
*/
}

/*
 * --INFO--
 * Address:	8021EA08
 * Size:	000164
 */
void TRKTargetAccessMemory(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r25, 0x1C(r1)
  mr        r26, r3
  mr        r27, r4
  mr        r28, r5
  mr        r29, r7
  lis       r3, 0x802F
  subi      r5, r3, 0x6A74
  lwz       r4, 0x0(r5)
  addi      r31, r5, 0xD
  lwz       r0, 0x4(r5)
  li        r30, 0
  mr        r3, r27
  stw       r4, 0x8(r1)
  stw       r0, 0xC(r1)
  lwz       r4, 0x8(r5)
  lwz       r0, 0xC(r5)
  stw       r4, 0x10(r1)
  stw       r0, 0x14(r1)
  stb       r30, 0x0(r31)
  bl        0x14B4
  cmpwi     r29, 0
  mr        r25, r3
  beq-      .loc_0x6C
  b         .loc_0x70

.loc_0x6C:
  li        r30, 0x1

.loc_0x70:
  lwz       r4, 0x0(r28)
  mr        r3, r25
  mr        r5, r30
  bl        -0x1F0
  mr        r30, r3
  cmpwi     r30, 0
  beq-      .loc_0x98
  li        r0, 0
  stw       r0, 0x0(r28)
  b         .loc_0x10C

.loc_0x98:
  bl        -0x21C
  lis       r4, 0x803D
  cmpwi     r29, 0
  addi      r4, r4, 0x5E40
  lwz       r0, 0x1F8(r4)
  mr        r8, r3
  rlwinm    r0,r0,0,27,27
  or        r7, r8, r0
  beq-      .loc_0xD4
  lwz       r5, 0x0(r28)
  mr        r3, r26
  mr        r4, r25
  mr        r6, r8
  bl        -0x108
  b         .loc_0x10C

.loc_0xD4:
  lwz       r5, 0x0(r28)
  mr        r3, r25
  mr        r4, r26
  mr        r6, r7
  mr        r7, r8
  bl        -0x124
  mr        r3, r25
  lwz       r4, 0x0(r28)
  bl        -0x374
  cmplw     r27, r25
  beq-      .loc_0x10C
  mr        r3, r27
  lwz       r4, 0x0(r28)
  bl        -0x388

.loc_0x10C:
  lbz       r0, 0x0(r31)
  cmplwi    r0, 0
  beq-      .loc_0x124
  li        r0, 0
  stw       r0, 0x0(r28)
  li        r30, 0x702

.loc_0x124:
  lis       r3, 0x802F
  lwz       r4, 0x8(r1)
  lwz       r0, 0xC(r1)
  subi      r5, r3, 0x6A74
  mr        r3, r30
  stw       r4, 0x0(r5)
  stw       r0, 0x4(r5)
  lwz       r4, 0x10(r1)
  lwz       r0, 0x14(r1)
  stw       r4, 0x8(r5)
  stw       r0, 0xC(r5)
  lmw       r25, 0x1C(r1)
  addi      r1, r1, 0x38
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021EB6C
 * Size:	00004C
 */
void TRKTargetReadInstruction(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  li        r0, 0x4
  addi      r5, r1, 0x8
  stw       r0, 0x8(r1)
  li        r6, 0
  li        r7, 0x1
  bl        -0x184
  cmpwi     r3, 0
  bne-      .loc_0x3C
  lwz       r0, 0x8(r1)
  cmplwi    r0, 0x4
  beq-      .loc_0x3C
  li        r3, 0x700

.loc_0x3C:
  addi      r1, r1, 0x10
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021EBB8
 * Size:	0000FC
 */
void TRKTargetAccessDefault(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r31, r6
  cmplwi    r4, 0x24
  ble-      .loc_0x28
  li        r3, 0x701
  b         .loc_0xE4

.loc_0x28:
  lis       r6, 0x802F
  cmpwi     r7, 0
  subi      r8, r6, 0x6A74
  lwz       r0, 0x0(r8)
  sub       r4, r4, r3
  lwz       r7, 0x4(r8)
  addi      r9, r4, 0x1
  lis       r4, 0x803D
  stw       r0, 0x8(r1)
  addi      r0, r4, 0x5E40
  rlwinm    r3,r3,2,0,29
  addi      r30, r8, 0xD
  stw       r7, 0xC(r1)
  add       r4, r0, r3
  lwz       r7, 0x8(r8)
  li        r6, 0
  lwz       r3, 0xC(r8)
  rlwinm    r0,r9,2,0,29
  stw       r7, 0x10(r1)
  mr        r7, r9
  stw       r3, 0x14(r1)
  stb       r6, 0x0(r30)
  stw       r0, 0x0(r31)
  beq-      .loc_0x98
  mr        r3, r5
  mr        r5, r7
  bl        -0x2284
  b         .loc_0xA4

.loc_0x98:
  mr        r3, r5
  mr        r5, r7
  bl        -0x1FC0

.loc_0xA4:
  lbz       r0, 0x0(r30)
  cmplwi    r0, 0
  beq-      .loc_0xBC
  li        r0, 0
  stw       r0, 0x0(r31)
  li        r3, 0x702

.loc_0xBC:
  lis       r5, 0x802F
  lwz       r4, 0x8(r1)
  lwz       r0, 0xC(r1)
  subi      r5, r5, 0x6A74
  stw       r4, 0x0(r5)
  stw       r0, 0x4(r5)
  lwz       r4, 0x10(r1)
  lwz       r0, 0x14(r1)
  stw       r4, 0x8(r5)
  stw       r0, 0xC(r5)

.loc_0xE4:
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x20
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021ECB4
 * Size:	000148
 */
void TRKTargetAccessFP(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r25, 0x24(r1)
  mr        r25, r3
  mr        r28, r4
  mr        r29, r5
  mr        r30, r6
  mr        r31, r7
  cmplwi    r28, 0x21
  ble-      .loc_0x34
  li        r3, 0x701
  b         .loc_0x134

.loc_0x34:
  lis       r3, 0x802F
  subi      r4, r3, 0x6A74
  lwz       r3, 0x0(r4)
  addi      r26, r4, 0xD
  lwz       r0, 0x4(r4)
  li        r27, 0
  stw       r3, 0x8(r1)
  stw       r0, 0xC(r1)
  lwz       r3, 0x8(r4)
  lwz       r0, 0xC(r4)
  stw       r3, 0x10(r1)
  stw       r0, 0x14(r1)
  stb       r27, 0x0(r26)
  bl        -0x498
  ori       r3, r3, 0x2000
  bl        -0x498
  stw       r27, 0x0(r30)
  mr        r27, r25
  li        r3, 0
  b         .loc_0x84

.loc_0x84:
  b         .loc_0x88

.loc_0x88:
  b         .loc_0xE4

.loc_0x8C:
  cmpwi     r31, 0
  beq-      .loc_0xB8
  mr        r4, r27
  addi      r3, r1, 0x18
  mr        r5, r31
  bl        0xF14
  lwz       r5, 0x18(r1)
  mr        r3, r29
  lwz       r6, 0x1C(r1)
  bl        -0x2490
  b         .loc_0xD4

.loc_0xB8:
  mr        r3, r29
  addi      r4, r1, 0x18
  bl        -0x2200
  mr        r4, r27
  addi      r3, r1, 0x18
  mr        r5, r31
  bl        0xEE4

.loc_0xD4:
  lwz       r4, 0x0(r30)
  addi      r27, r27, 0x1
  addi      r0, r4, 0x8
  stw       r0, 0x0(r30)

.loc_0xE4:
  cmplw     r27, r28
  bgt-      .loc_0xF4
  cmpwi     r3, 0
  beq+      .loc_0x8C

.loc_0xF4:
  lbz       r0, 0x0(r26)
  cmplwi    r0, 0
  beq-      .loc_0x10C
  li        r0, 0
  stw       r0, 0x0(r30)
  li        r3, 0x702

.loc_0x10C:
  lis       r5, 0x802F
  lwz       r4, 0x8(r1)
  lwz       r0, 0xC(r1)
  subi      r5, r5, 0x6A74
  stw       r4, 0x0(r5)
  stw       r0, 0x4(r5)
  lwz       r4, 0x10(r1)
  lwz       r0, 0x14(r1)
  stw       r4, 0x8(r5)
  stw       r0, 0xC(r5)

.loc_0x134:
  lmw       r25, 0x24(r1)
  addi      r1, r1, 0x40
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021EDFC
 * Size:	000178
 */
void TRKTargetAccessExtended1(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r6
  cmplwi    r4, 0x60
  ble-      .loc_0x28
  li        r3, 0x701
  b         .loc_0x160

.loc_0x28:
  lis       r6, 0x802F
  cmplw     r3, r4
  subi      r9, r6, 0x6A74
  lwz       r8, 0x0(r9)
  addi      r31, r9, 0xD
  lwz       r6, 0x4(r9)
  li        r0, 0
  stw       r8, 0x8(r1)
  stw       r6, 0xC(r1)
  lwz       r8, 0x8(r9)
  lwz       r6, 0xC(r9)
  stw       r8, 0x10(r1)
  stw       r6, 0x14(r1)
  stb       r0, 0x0(r31)
  stw       r0, 0x0(r30)
  bgt-      .loc_0x120
  sub       r4, r4, r3
  lwz       r0, 0x0(r30)
  addi      r8, r4, 0x1
  cmpwi     r7, 0
  rlwinm    r6,r8,2,0,29
  lis       r4, 0x803D
  add       r0, r0, r6
  stw       r0, 0x0(r30)
  addi      r7, r4, 0x5E40
  rlwinm    r0,r3,2,0,29
  add       r4, r7, r0
  addi      r4, r4, 0x1A8
  beq-      .loc_0xAC
  mr        r3, r5
  mr        r5, r8
  bl        -0x24DC
  b         .loc_0x120

.loc_0xAC:
  addi      r0, r7, 0x1EC
  cmplw     r4, r0
  bgt-      .loc_0xDC
  subi      r3, r6, 0x4
  addi      r0, r7, 0x1E8
  add       r3, r4, r3
  cmplw     r3, r0
  blt-      .loc_0xDC
  lis       r3, 0x802F
  subi      r3, r3, 0x6A80
  li        r0, 0x1
  stb       r0, 0x0(r3)

.loc_0xDC:
  lis       r3, 0x803D
  addi      r3, r3, 0x5E40
  addi      r6, r3, 0x278
  cmplw     r4, r6
  bgt-      .loc_0x114
  rlwinm    r3,r8,2,0,29
  subi      r0, r3, 0x4
  add       r0, r4, r0
  cmplw     r0, r6
  blt-      .loc_0x114
  lis       r3, 0x802F
  subi      r3, r3, 0x6A80
  li        r0, 0x1
  stb       r0, 0x1(r3)

.loc_0x114:
  mr        r3, r5
  mr        r5, r8
  bl        -0x2280

.loc_0x120:
  lbz       r0, 0x0(r31)
  cmplwi    r0, 0
  beq-      .loc_0x138
  li        r0, 0
  stw       r0, 0x0(r30)
  li        r3, 0x702

.loc_0x138:
  lis       r5, 0x802F
  lwz       r4, 0x8(r1)
  lwz       r0, 0xC(r1)
  subi      r5, r5, 0x6A74
  stw       r4, 0x0(r5)
  stw       r0, 0x4(r5)
  lwz       r4, 0x10(r1)
  lwz       r0, 0x14(r1)
  stw       r4, 0x8(r5)
  stw       r0, 0xC(r5)

.loc_0x160:
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x20
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021EF74
 * Size:	00017C
 */
void TRKTargetAccessExtended2(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r25, 0x24(r1)
  mr        r25, r3
  mr        r27, r4
  mr        r28, r5
  mr        r29, r6
  mr        r30, r7
  cmplwi    r27, 0x1F
  ble-      .loc_0x34
  li        r3, 0x701
  b         .loc_0x168

.loc_0x34:
  lis       r4, 0x802F
  addi      r3, r1, 0x8
  subi      r7, r4, 0x6A74
  lwz       r5, 0x0(r7)
  addi      r31, r7, 0xD
  lwz       r0, 0x4(r7)
  li        r26, 0
  li        r4, 0x398
  stw       r5, 0xC(r1)
  li        r5, 0x1
  stw       r0, 0x10(r1)
  lwz       r6, 0x8(r7)
  lwz       r0, 0xC(r7)
  stw       r6, 0x14(r1)
  stw       r0, 0x18(r1)
  stb       r26, 0x0(r31)
  bl        0xB58
  lwz       r0, 0x8(r1)
  addi      r3, r1, 0x8
  li        r4, 0x398
  oris      r0, r0, 0xA000
  stw       r0, 0x8(r1)
  li        r5, 0
  bl        0xB3C
  stw       r26, 0x8(r1)
  addi      r3, r1, 0x8
  li        r4, 0x390
  li        r5, 0
  bl        0xB28
  stw       r26, 0x0(r29)
  mr        r26, r25
  li        r3, 0
  b         .loc_0xB8

.loc_0xB8:
  b         .loc_0xBC

.loc_0xBC:
  b         .loc_0x118

.loc_0xC0:
  cmpwi     r30, 0
  beq-      .loc_0xEC
  mr        r4, r26
  addi      r3, r1, 0x1C
  mr        r5, r30
  bl        0xBA8
  lwz       r5, 0x1C(r1)
  mr        r3, r28
  lwz       r6, 0x20(r1)
  bl        -0x2784
  b         .loc_0x108

.loc_0xEC:
  mr        r3, r28
  addi      r4, r1, 0x1C
  bl        -0x24F4
  mr        r4, r26
  addi      r3, r1, 0x1C
  mr        r5, r30
  bl        0xB78

.loc_0x108:
  lwz       r4, 0x0(r29)
  addi      r26, r26, 0x1
  addi      r0, r4, 0x8
  stw       r0, 0x0(r29)

.loc_0x118:
  cmplw     r26, r27
  bgt-      .loc_0x128
  cmpwi     r3, 0
  beq+      .loc_0xC0

.loc_0x128:
  lbz       r0, 0x0(r31)
  cmplwi    r0, 0
  beq-      .loc_0x140
  li        r0, 0
  stw       r0, 0x0(r29)
  li        r3, 0x702

.loc_0x140:
  lis       r5, 0x802F
  lwz       r4, 0xC(r1)
  lwz       r0, 0x10(r1)
  subi      r5, r5, 0x6A74
  stw       r4, 0x0(r5)
  stw       r0, 0x4(r5)
  lwz       r4, 0x14(r1)
  lwz       r0, 0x18(r1)
  stw       r4, 0x8(r5)
  stw       r0, 0xC(r5)

.loc_0x168:
  lmw       r25, 0x24(r1)
  addi      r1, r1, 0x40
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F0F0
 * Size:	000028
 */
void TRKTargetVersions(void)
{
/*
.loc_0x0:
  li        r0, 0
  stb       r0, 0x0(r3)
  li        r0, 0x8
  li        r4, 0x1
  stb       r0, 0x1(r3)
  li        r0, 0xA
  stb       r4, 0x2(r3)
  stb       r0, 0x3(r3)
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F118
 * Size:	0000A4
 */
void TRKTargetSupportMask(void)
{
/*
.loc_0x0:
  li        r0, 0x7A
  stb       r0, 0x0(r3)
  li        r7, 0
  li        r0, 0x4F
  stb       r7, 0x1(r3)
  li        r6, 0x7
  li        r5, 0x1
  stb       r0, 0x2(r3)
  li        r4, 0x3
  li        r0, 0x80
  stb       r6, 0x3(r3)
  stb       r7, 0x4(r3)
  stb       r7, 0x5(r3)
  stb       r7, 0x6(r3)
  stb       r7, 0x7(r3)
  stb       r7, 0x8(r3)
  stb       r7, 0x9(r3)
  stb       r7, 0xA(r3)
  stb       r7, 0xB(r3)
  stb       r7, 0xC(r3)
  stb       r7, 0xD(r3)
  stb       r7, 0xE(r3)
  stb       r7, 0xF(r3)
  stb       r5, 0x10(r3)
  stb       r7, 0x11(r3)
  stb       r4, 0x12(r3)
  stb       r7, 0x13(r3)
  stb       r7, 0x14(r3)
  stb       r7, 0x15(r3)
  stb       r7, 0x16(r3)
  stb       r7, 0x17(r3)
  stb       r7, 0x18(r3)
  stb       r7, 0x19(r3)
  stb       r4, 0x1A(r3)
  stb       r7, 0x1B(r3)
  stb       r7, 0x1C(r3)
  stb       r7, 0x1D(r3)
  stb       r7, 0x1E(r3)
  stb       r0, 0x1F(r3)
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F1BC
 * Size:	000068
 */
void TRKTargetCPUType(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  mr        r31, r3
  li        r0, 0
  stb       r0, 0x0(r31)
  bl        0x1238
  stb       r3, 0x1(r31)
  lis       r3, 0x803D
  addi      r3, r3, 0x4318
  lwz       r3, 0x0(r3)
  li        r4, 0x4
  li        r0, 0x8
  rlwinm    r3,r3,0,24,31
  stb       r3, 0x2(r31)
  li        r3, 0
  stb       r4, 0x3(r31)
  stb       r0, 0x4(r31)
  stb       r4, 0x5(r31)
  stb       r0, 0x6(r31)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void TRKTargetCheckException(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021F224
 * Size:	000194
 */
void TRKInterruptHandler(void)
{
/*
.loc_0x0:
  mtsrr0    r2
  mtsrr1    r4
  mfsprg    r4, 0x3
  mfcr      r2
  mtsprg    3, r2
  lis       r2, 0x803D
  ori       r2, r2, 0x5D98
  lwz       r2, 0x8C(r2)
  ori       r2, r2, 0x8002
  xori      r2, r2, 0x8002
  sync      
  mtmsr     r2
  sync      
  lis       r2, 0x803D
  ori       r2, r2, 0x5CF0
  sth       r3, 0x0(r2)
  cmpwi     r3, 0x500
  bne-      .loc_0xC8
  lis       r2, 0x803D
  ori       r2, r2, 0x5E40
  mflr      r3
  stw       r3, 0x42C(r2)
  bl        0x138C
  lis       r2, 0x803D
  ori       r2, r2, 0x5E40
  lwz       r3, 0x42C(r2)
  mtlr      r3
  lis       r2, 0x803D
  ori       r2, r2, 0x5D98
  lwz       r2, 0xA0(r2)
  lbz       r2, 0x0(r2)
  cmpwi     r2, 0
  beq-      .loc_0xAC
  lis       r2, 0x802E
  ori       r2, r2, 0x958C
  lbz       r2, 0xC(r2)
  cmpwi     r2, 0x1
  beq-      .loc_0xAC
  lis       r2, 0x803D
  ori       r2, r2, 0x5D98
  li        r3, 0x1
  stb       r3, 0x9C(r2)
  b         .loc_0xC8

.loc_0xAC:
  lis       r2, 0x803D
  ori       r2, r2, 0x5CF4
  lwz       r3, 0x88(r2)
  mtcr      r3
  lwz       r3, 0xC(r2)
  lwz       r2, 0x8(r2)
  rfi       

.loc_0xC8:
  lis       r2, 0x803D
  ori       r2, r2, 0x5CF0
  lhz       r3, 0x0(r2)
  lis       r2, 0x802E
  ori       r2, r2, 0x958C
  lbz       r2, 0xC(r2)
  cmpwi     r2, 0
  bne-      .loc_0x194
  lis       r2, 0x803D
  ori       r2, r2, 0x5E40
  stw       r0, 0x0(r2)
  stw       r1, 0x4(r2)
  mfsprg    r0, 0x1
  stw       r0, 0x8(r2)
  sth       r3, 0x2F8(r2)
  sth       r3, 0x2FA(r2)
  mfsprg    r0, 0x2
  stw       r0, 0xC(r2)
  stmw      r4, 0x10(r2)
  mfsrr0    r27
  mflr      r28
  mfsprg    r29, 0x3
  mfctr     r30
  mfxer     r31
  stmw      r27, 0x80(r2)
  bl        0xD50
  lis       r2, 0x802E
  ori       r2, r2, 0x958C
  li        r3, 0x1
  stb       r3, 0xC(r2)
  lis       r2, 0x803D
  ori       r2, r2, 0x5D98
  lwz       r0, 0x8C(r2)
  sync      
  mtmsr     r0
  sync      
  lwz       r0, 0x80(r2)
  mtlr      r0
  lwz       r0, 0x84(r2)
  mtctr     r0
  lwz       r0, 0x88(r2)
  mtxer     r0
  lwz       r0, 0x94(r2)
  mtdsisr   r0
  lwz       r0, 0x90(r2)
  mtdar     r0
  lmw       r3, 0xC(r2)
  lwz       r0, 0x0(r2)
  lwz       r1, 0x4(r2)
  lwz       r2, 0x8(r2)
  b         0xA0

.loc_0x194:
*/
}

/*
 * --INFO--
 * Address:	8021F3B8
 * Size:	00009C
 */
void TRKExceptionHandler(void)
{
/*
.loc_0x0:
  lis       r2, 0x802E
  ori       r2, r2, 0x958C
  sth       r3, 0x8(r2)
  mfsrr0    r3
  stw       r3, 0x0(r2)
  lhz       r3, 0x8(r2)
  cmpwi     r3, 0x200
  beq-      .loc_0x6C
  cmpwi     r3, 0x300
  beq-      .loc_0x6C
  cmpwi     r3, 0x400
  beq-      .loc_0x6C
  cmpwi     r3, 0x600
  beq-      .loc_0x6C
  cmpwi     r3, 0x700
  beq-      .loc_0x6C
  cmpwi     r3, 0x800
  beq-      .loc_0x6C
  cmpwi     r3, 0x1000
  beq-      .loc_0x6C
  cmpwi     r3, 0x1100
  beq-      .loc_0x6C
  cmpwi     r3, 0x1200
  beq-      .loc_0x6C
  cmpwi     r3, 0x1300
  beq-      .loc_0x6C
  b         .loc_0x78

.loc_0x6C:
  mfsrr0    r3
  addi      r3, r3, 0x4
  mtsrr0    r3

.loc_0x78:
  lis       r2, 0x802E
  ori       r2, r2, 0x958C
  li        r3, 0x1
  stb       r3, 0xD(r2)
  mfsprg    r3, 0x3
  mtcr      r3
  mfsprg    r2, 0x1
  mfsprg    r3, 0x2
  rfi
*/
}

/*
 * --INFO--
 * Address:	8021F454
 * Size:	0000B0
 */
void TRKPostInterruptEvent(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  lis       r3, 0x803D
  addi      r3, r3, 0x5D98
  addi      r3, r3, 0x9C
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0
  beq-      .loc_0x30
  li        r0, 0
  stw       r0, 0x0(r3)
  b         .loc_0xA0

.loc_0x30:
  lis       r3, 0x803D
  addi      r3, r3, 0x5E40
  lwz       r0, 0x2F8(r3)
  rlwinm    r0,r0,0,16,31
  cmpwi     r0, 0xD00
  beq-      .loc_0x58
  bge-      .loc_0x8C
  cmpwi     r0, 0x700
  beq-      .loc_0x58
  b         .loc_0x8C

.loc_0x58:
  lis       r4, 0x803D
  addi      r3, r1, 0x8
  addi      r4, r4, 0x5E40
  lwz       r4, 0x80(r4)
  bl        -0x950
  lwz       r3, 0x8(r1)
  subis     r0, r3, 0xFE0
  cmplwi    r0, 0
  bne-      .loc_0x84
  li        r4, 0x5
  b         .loc_0x90

.loc_0x84:
  li        r4, 0x3
  b         .loc_0x90

.loc_0x8C:
  li        r4, 0x4

.loc_0x90:
  addi      r3, r1, 0xC
  bl        -0x3214
  addi      r3, r1, 0xC
  bl        -0x32FC

.loc_0xA0:
  addi      r1, r1, 0x18
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F504
 * Size:	0000C4
 */
void TRKSwapAndGo(void)
{
/*
.loc_0x0:
  lis       r3, 0x803D
  ori       r3, r3, 0x5D98
  stmw      r0, 0x0(r3)
  mfmsr     r0
  stw       r0, 0x8C(r3)
  mflr      r0
  stw       r0, 0x80(r3)
  mfctr     r0
  stw       r0, 0x84(r3)
  mfxer     r0
  stw       r0, 0x88(r3)
  mfdsisr   r0
  stw       r0, 0x94(r3)
  mfdar     r0
  stw       r0, 0x90(r3)
  li        r1, -0x7FFE
  not       r1, r1
  mfmsr     r3
  and       r3, r3, r1
  mtmsr     r3
  lis       r2, 0x803D
  ori       r2, r2, 0x5D98
  lwz       r2, 0xA0(r2)
  lbz       r2, 0x0(r2)
  cmpwi     r2, 0
  beq-      .loc_0x7C
  lis       r2, 0x803D
  ori       r2, r2, 0x5D98
  li        r3, 0x1
  stb       r3, 0x9C(r2)
  b         .loc_0xC4

.loc_0x7C:
  lis       r2, 0x802E
  ori       r2, r2, 0x958C
  li        r3, 0
  stb       r3, 0xC(r2)
  bl        0xCC8
  lis       r2, 0x803D
  ori       r2, r2, 0x5E40
  lmw       r27, 0x80(r2)
  mtsrr0    r27
  mtlr      r28
  mtcr      r29
  mtctr     r30
  mtxer     r31
  lmw       r3, 0xC(r2)
  lwz       r0, 0x0(r2)
  lwz       r1, 0x4(r2)
  lwz       r2, 0x8(r2)
  rfi       

.loc_0xC4:
*/
}

/*
 * --INFO--
 * Address:	8021F5C8
 * Size:	000054
 */
void TRKInterruptHandlerEnableInterrupts(void)
{
/*
.loc_0x0:
  lis       r2, 0x803D
  ori       r2, r2, 0x5D98
  lwz       r0, 0x8C(r2)
  sync      
  mtmsr     r0
  sync      
  lwz       r0, 0x80(r2)
  mtlr      r0
  lwz       r0, 0x84(r2)
  mtctr     r0
  lwz       r0, 0x88(r2)
  mtxer     r0
  lwz       r0, 0x94(r2)
  mtdsisr   r0
  lwz       r0, 0x90(r2)
  mtdar     r0
  lmw       r3, 0xC(r2)
  lwz       r0, 0x0(r2)
  lwz       r1, 0x4(r2)
  lwz       r2, 0x8(r2)
  b         -0x1C4
*/
}

/*
 * --INFO--
 * Address:	8021F61C
 * Size:	000064
 */
void TRKTargetInterrupt(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  lbz       r0, 0x0(r3)
  li        r31, 0
  cmpwi     r0, 0x5
  bge-      .loc_0x4C
  cmpwi     r0, 0x3
  bge-      .loc_0x2C
  b         .loc_0x4C

.loc_0x2C:
  bl        0x280
  cmpwi     r3, 0
  bne-      .loc_0x4C
  li        r3, 0x1
  bl        0x4B0
  li        r3, 0x90
  bl        -0xFB0
  mr        r31, r3

.loc_0x4C:
  mr        r3, r31
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F680
 * Size:	000090
 */
void TRKTargetAddStopInfo(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lis       r3, 0x803D
  addi      r3, r3, 0x5E40
  addi      r31, r3, 0x80
  lwz       r4, 0x0(r31)
  mr        r3, r30
  bl        -0x2E3C
  cmpwi     r3, 0
  bne-      .loc_0x44
  addi      r3, r1, 0x8
  lwz       r4, 0x0(r31)
  bl        -0xB54

.loc_0x44:
  cmpwi     r3, 0
  bne-      .loc_0x58
  mr        r3, r30
  lwz       r4, 0x8(r1)
  bl        -0x2E64

.loc_0x58:
  cmpwi     r3, 0
  bne-      .loc_0x78
  lis       r3, 0x803D
  addi      r3, r3, 0x5E40
  lwz       r0, 0x2F8(r3)
  mr        r3, r30
  rlwinm    r4,r0,0,16,31
  bl        -0x2ED8

.loc_0x78:
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F710
 * Size:	000088
 */
void TRKTargetAddExceptionInfo(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lis       r3, 0x802F
  subi      r31, r3, 0x6A74
  lwz       r4, 0x0(r31)
  mr        r3, r30
  bl        -0x2EC8
  cmpwi     r3, 0
  bne-      .loc_0x40
  addi      r3, r1, 0x8
  lwz       r4, 0x0(r31)
  bl        -0xBE0

.loc_0x40:
  cmpwi     r3, 0
  bne-      .loc_0x54
  mr        r3, r30
  lwz       r4, 0x8(r1)
  bl        -0x2EF0

.loc_0x54:
  cmpwi     r3, 0
  bne-      .loc_0x70
  lis       r3, 0x802F
  subi      r3, r3, 0x6A74
  lhz       r4, 0x8(r3)
  mr        r3, r30
  bl        -0x2F60

.loc_0x70:
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F798
 * Size:	00003C
 */
void TRKTargetEnableTrace(void)
{
/*
.loc_0x0:
  cmpwi     r3, 0
  beq-      .loc_0x20
  lis       r3, 0x803D
  addi      r3, r3, 0x5E40
  lwz       r0, 0x1F8(r3)
  ori       r0, r0, 0x400
  stw       r0, 0x1F8(r3)
  b         .loc_0x34

.loc_0x20:
  lis       r3, 0x803D
  addi      r3, r3, 0x5E40
  lwz       r0, 0x1F8(r3)
  rlwinm    r0,r0,0,22,20
  stw       r0, 0x1F8(r3)

.loc_0x34:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F7D4
 * Size:	000084
 */
void TRKTargetStepDone(void)
{
/*
.loc_0x0:
  lis       r3, 0x802F
  subi      r5, r3, 0x6A64
  lwz       r0, 0x0(r5)
  li        r3, 0x1
  cmpwi     r0, 0
  beq-      .loc_0x80
  lis       r4, 0x803D
  addi      r4, r4, 0x5E40
  lwz       r0, 0x2F8(r4)
  rlwinm    r0,r0,0,16,31
  cmplwi    r0, 0xD00
  bne-      .loc_0x80
  lbz       r0, 0x4(r5)
  cmpwi     r0, 0x1
  beq-      .loc_0x60
  bge-      .loc_0x80
  cmpwi     r0, 0
  bge-      .loc_0x4C
  b         .loc_0x80

.loc_0x4C:
  lwz       r0, 0x8(r5)
  cmplwi    r0, 0
  beq-      .loc_0x80
  li        r3, 0
  b         .loc_0x80

.loc_0x60:
  lwz       r4, 0x80(r4)
  lwz       r0, 0xC(r5)
  cmplw     r4, r0
  blt-      .loc_0x80
  lwz       r0, 0x10(r5)
  cmplw     r4, r0
  bgt-      .loc_0x80
  li        r3, 0

.loc_0x80:
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F858
 * Size:	000070
 */
void TRKTargetDoStep(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  lis       r3, 0x802F
  subi      r31, r3, 0x6A64
  li        r0, 0x1
  stw       r0, 0x0(r31)
  li        r3, 0x1
  bl        -0xE4
  lbz       r0, 0x4(r31)
  cmplwi    r0, 0
  beq-      .loc_0x3C
  cmplwi    r0, 0x10
  bne-      .loc_0x50

.loc_0x3C:
  lis       r3, 0x802F
  subi      r4, r3, 0x6A64
  lwz       r3, 0x8(r4)
  subi      r0, r3, 0x1
  stw       r0, 0x8(r4)

.loc_0x50:
  li        r3, 0
  bl        0x25C
  li        r3, 0
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F8C8
 * Size:	000068
 */
void TRKTargetCheckStep(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  lis       r3, 0x802F
  subi      r31, r3, 0x6A64
  lwz       r0, 0x0(r31)
  cmpwi     r0, 0
  beq-      .loc_0x48
  li        r3, 0
  bl        -0x158
  bl        -0x120
  cmpwi     r3, 0
  beq-      .loc_0x44
  li        r0, 0
  stw       r0, 0x0(r31)
  b         .loc_0x48

.loc_0x44:
  bl        -0xB4

.loc_0x48:
  lis       r3, 0x802F
  subi      r3, r3, 0x6A64
  lwz       r3, 0x0(r3)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F930
 * Size:	000044
 */
void TRKTargetSingleStep(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  cmpwi     r4, 0
  beq-      .loc_0x1C
  li        r3, 0x703
  b         .loc_0x34

.loc_0x1C:
  lis       r4, 0x802F
  subi      r4, r4, 0x6A64
  li        r0, 0
  stb       r0, 0x4(r4)
  stw       r3, 0x8(r4)
  bl        -0x108

.loc_0x34:
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F974
 * Size:	000048
 */
void TRKTargetStepOutOfRange(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  cmpwi     r5, 0
  beq-      .loc_0x1C
  li        r3, 0x703
  b         .loc_0x38

.loc_0x1C:
  lis       r5, 0x802F
  subi      r5, r5, 0x6A64
  li        r0, 0x1
  stb       r0, 0x4(r5)
  stw       r3, 0xC(r5)
  stw       r4, 0x10(r5)
  bl        -0x150

.loc_0x38:
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F9BC
 * Size:	000010
 */
void TRKTargetGetPC(void)
{
/*
.loc_0x0:
  lis       r3, 0x803D
  addi      r3, r3, 0x5E40
  lwz       r3, 0x80(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8021F9CC
 * Size:	0000F0
 */
void TRKTargetSupportRequest(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  lis       r3, 0x803D
  addi      r3, r3, 0x5E40
  addi      r31, r3, 0xC
  lwz       r0, 0x0(r31)
  rlwinm    r27,r0,0,24,31
  cmplwi    r27, 0xD1
  beq-      .loc_0x50
  cmplwi    r27, 0xD0
  beq-      .loc_0x50
  addi      r3, r1, 0xC
  li        r4, 0x4
  bl        -0x3734
  addi      r3, r1, 0xC
  bl        -0x381C
  li        r3, 0
  b         .loc_0xDC

.loc_0x50:
  lis       r3, 0x803D
  addi      r6, r1, 0x8
  addi      r4, r3, 0x5E40
  lwz       r3, 0x10(r4)
  subfic    r0, r27, 0xD1
  lwz       r28, 0x14(r4)
  addi      r30, r4, 0x18
  cntlzw    r0, r0
  lwz       r4, 0x0(r30)
  rlwinm    r3,r3,0,24,31
  mr        r5, r28
  rlwinm    r8,r0,27,5,31
  li        r7, 0x1
  bl        -0x1834
  lbz       r0, 0x8(r1)
  mr        r29, r3
  cmplwi    r0, 0
  bne-      .loc_0xA8
  cmpwi     r29, 0
  beq-      .loc_0xA8
  li        r0, 0x1
  stb       r0, 0x8(r1)

.loc_0xA8:
  lbz       r0, 0x8(r1)
  cmplwi    r27, 0xD1
  stw       r0, 0x0(r31)
  bne-      .loc_0xC4
  lwz       r3, 0x0(r30)
  lwz       r4, 0x0(r28)
  bl        -0x1304

.loc_0xC4:
  lis       r3, 0x803D
  addi      r5, r3, 0x5E40
  lwz       r4, 0x80(r5)
  mr        r3, r29
  addi      r0, r4, 0x4
  stw       r0, 0x80(r5)

.loc_0xDC:
  lmw       r27, 0x1C(r1)
  addi      r1, r1, 0x30
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021FABC
 * Size:	00003C
 */
void TRKTargetFlushCache(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  cmplw     r4, r5
  bge-      .loc_0x28
  mr        r3, r4
  sub       r4, r5, r4
  bl        -0x1350
  li        r3, 0
  b         .loc_0x2C

.loc_0x28:
  li        r3, 0x700

.loc_0x2C:
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021FAF8
 * Size:	000010
 */
void TRKTargetStopped(void)
{
/*
.loc_0x0:
  lis       r3, 0x803D
  addi      r3, r3, 0x5D98
  lwz       r3, 0x98(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8021FB08
 * Size:	000010
 */
void TRKTargetSetStopped(void)
{
/*
.loc_0x0:
  lis       r4, 0x803D
  addi      r4, r4, 0x5D98
  stw       r3, 0x98(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	8021FB18
 * Size:	000028
 */
void TRKTargetStop(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  li        r3, 0x1
  bl        -0x20
  li        r3, 0
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021FB40
 * Size:	0000B0
 */
void TRKPPCAccessSPR(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  lis       r6, 0x8022
  cmpwi     r5, 0
  addi      r7, r6, 0x2D80
  lwz       r6, 0x0(r7)
  lwz       r0, 0x4(r7)
  stw       r6, 0x8(r1)
  stw       r0, 0xC(r1)
  lwz       r6, 0x8(r7)
  lwz       r0, 0xC(r7)
  stw       r6, 0x10(r1)
  stw       r0, 0x14(r1)
  lwz       r0, 0x10(r7)
  stw       r0, 0x18(r1)
  beq-      .loc_0x70
  rlwinm    r0,r4,0,20,26
  rlwinm    r6,r0,6,0,25
  rlwinm    r0,r4,0,27,31
  oris      r4, r6, 0x7C80
  rlwinm    r0,r0,16,0,15
  or        r0, r4, r0
  ori       r0, r0, 0x2A6
  stw       r0, 0x8(r1)
  lis       r0, 0x9083
  stw       r0, 0xC(r1)
  b         .loc_0x98

.loc_0x70:
  rlwinm    r0,r4,0,20,26
  rlwinm    r6,r0,6,0,25
  rlwinm    r0,r4,0,27,31
  lis       r7, 0x8083
  oris      r4, r6, 0x7C80
  stw       r7, 0x8(r1)
  rlwinm    r0,r0,16,0,15
  or        r0, r4, r0
  ori       r0, r0, 0x3A6
  stw       r0, 0xC(r1)

.loc_0x98:
  addi      r4, r1, 0x8
  bl        0x20C
  addi      r1, r1, 0x20
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021FBF0
 * Size:	000078
 */
void TRKPPCAccessPairedSingleRegister(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  lis       r6, 0x8022
  cmpwi     r5, 0
  addi      r7, r6, 0x2D94
  lwz       r6, 0x0(r7)
  lwz       r0, 0x4(r7)
  stw       r6, 0x8(r1)
  stw       r0, 0xC(r1)
  lwz       r6, 0x8(r7)
  lwz       r0, 0xC(r7)
  stw       r6, 0x10(r1)
  stw       r0, 0x14(r1)
  lwz       r0, 0x10(r7)
  stw       r0, 0x18(r1)
  beq-      .loc_0x54
  rlwinm    r0,r4,21,0,10
  oris      r0, r0, 0xF003
  stw       r0, 0x8(r1)
  b         .loc_0x60

.loc_0x54:
  rlwinm    r0,r4,21,0,10
  oris      r0, r0, 0xE003
  stw       r0, 0x8(r1)

.loc_0x60:
  addi      r4, r1, 0x8
  bl        0x194
  addi      r1, r1, 0x20
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021FC68
 * Size:	000180
 */
void TRKPPCAccessFPRegister(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  mr        r30, r3
  mr        r31, r5
  lis       r3, 0x8022
  cmplwi    r4, 0x20
  addi      r6, r3, 0x2DA8
  lwz       r5, 0x0(r6)
  li        r3, 0
  lwz       r0, 0x4(r6)
  stw       r5, 0x8(r1)
  stw       r0, 0xC(r1)
  lwz       r5, 0x8(r6)
  lwz       r0, 0xC(r6)
  stw       r5, 0x10(r1)
  stw       r0, 0x14(r1)
  lwz       r0, 0x10(r6)
  stw       r0, 0x18(r1)
  bge-      .loc_0x90
  cmpwi     r31, 0
  beq-      .loc_0x70
  rlwinm    r0,r4,21,0,10
  oris      r0, r0, 0xD803
  stw       r0, 0x8(r1)
  b         .loc_0x7C

.loc_0x70:
  rlwinm    r0,r4,21,0,10
  oris      r0, r0, 0xC803
  stw       r0, 0x8(r1)

.loc_0x7C:
  mr        r3, r30
  addi      r4, r1, 0x8
  mr        r5, r31
  bl        .loc_0x180
  b         .loc_0x168

.loc_0x90:
  bne-      .loc_0x11C
  cmpwi     r31, 0
  beq-      .loc_0xC4
  lis       r0, 0xD824
  lis       r3, 0xFC20
  stw       r0, 0x8(r1)
  addi      r0, r3, 0x48E
  stw       r0, 0xC(r1)
  lis       r3, 0xD823
  lis       r0, 0xC824
  stw       r3, 0x10(r1)
  stw       r0, 0x14(r1)
  b         .loc_0xE8

.loc_0xC4:
  lis       r0, 0xD824
  stw       r0, 0x8(r1)
  lis       r0, 0xC823
  lis       r3, 0xFDFE
  stw       r0, 0xC(r1)
  addi      r3, r3, 0xD8E
  lis       r0, 0xC824
  stw       r3, 0x10(r1)
  stw       r0, 0x14(r1)

.loc_0xE8:
  mr        r3, r30
  addi      r4, r1, 0x8
  mr        r5, r31
  bl        .loc_0x180
  lwz       r6, 0x4(r30)
  li        r0, -0x1
  lwz       r5, 0x0(r30)
  li        r4, 0
  and       r0, r6, r0
  stw       r0, 0x4(r30)
  and       r0, r5, r4
  stw       r0, 0x0(r30)
  b         .loc_0x168

.loc_0x11C:
  cmplwi    r4, 0x21
  bne-      .loc_0x168
  cmpwi     r31, 0
  bne-      .loc_0x134
  lwz       r0, 0x4(r30)
  stw       r0, 0x0(r30)

.loc_0x134:
  mr        r3, r30
  mr        r5, r31
  li        r4, 0x3FE
  bl        -0x268
  cmpwi     r31, 0
  beq-      .loc_0x168
  lwz       r5, 0x0(r30)
  li        r0, -0x1
  li        r4, 0
  and       r0, r5, r0
  stw       r0, 0x4(r30)
  and       r0, r4, r4
  stw       r0, 0x0(r30)

.loc_0x168:
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  addi      r1, r1, 0x28
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr       

.loc_0x180:
*/
}

/*
 * --INFO--
 * Address:	8021FDE8
 * Size:	000068
 */
void TRKPPCAccessSpecialReg(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  stw       r30, 0x8(r1)
  mr        r30, r3
  mr        r31, r4
  lis       r3, 0x4E80
  addi      r0, r3, 0x20
  stw       r0, 0x10(r31)
  mr        r3, r31
  li        r4, 0x14
  bl        -0x1690
  lis       r3, 0x803D
  addi      r4, r3, 0x5D88
  mr        r3, r30
  mr        r12, r31
  mtlr      r12
  blrl      
  li        r3, 0
  lwz       r31, 0xC(r1)
  lwz       r30, 0x8(r1)
  addi      r1, r1, 0x10
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021FE50
 * Size:	000010
 */
void TRKTargetSetInputPendingPtr(void)
{
/*
.loc_0x0:
  lis       r4, 0x803D
  addi      r4, r4, 0x5D98
  stw       r3, 0xA0(r4)
  blr
*/
}