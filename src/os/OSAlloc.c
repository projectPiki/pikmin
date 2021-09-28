

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void DLAddFront(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void DLLookup(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void DLExtract(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void DLInsert(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void DLOverlap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void DLSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F67AC
 * Size:	0000FC
 */
void OSAllocFromHeap(void)
{
/*
.loc_0x0:
  mulli     r0, r3, 0xC
  lwz       r3, 0x31E0(r13)
  add       r5, r3, r0
  addi      r0, r4, 0x3F
  lwz       r6, 0x4(r5)
  rlwinm    r3,r0,0,0,26
  b         .loc_0x2C

.loc_0x1C:
  lwz       r0, 0x8(r6)
  cmpw      r3, r0
  ble-      .loc_0x34
  lwz       r6, 0x4(r6)

.loc_0x2C:
  cmplwi    r6, 0
  bne+      .loc_0x1C

.loc_0x34:
  cmplwi    r6, 0
  bne-      .loc_0x44
  li        r3, 0
  blr       

.loc_0x44:
  lwz       r0, 0x8(r6)
  sub       r0, r0, r3
  cmplwi    r0, 0x40
  bge-      .loc_0x90
  lwz       r4, 0x4(r6)
  lwz       r3, 0x4(r5)
  cmplwi    r4, 0
  beq-      .loc_0x6C
  lwz       r0, 0x0(r6)
  stw       r0, 0x0(r4)

.loc_0x6C:
  lwz       r4, 0x0(r6)
  cmplwi    r4, 0
  bne-      .loc_0x80
  lwz       r3, 0x4(r6)
  b         .loc_0x88

.loc_0x80:
  lwz       r0, 0x4(r6)
  stw       r0, 0x4(r4)

.loc_0x88:
  stw       r3, 0x4(r5)
  b         .loc_0xD4

.loc_0x90:
  stw       r3, 0x8(r6)
  add       r4, r6, r3
  stw       r0, 0x8(r4)
  lwz       r0, 0x0(r6)
  stw       r0, 0x0(r4)
  lwz       r0, 0x4(r6)
  stw       r0, 0x4(r4)
  lwz       r3, 0x4(r4)
  cmplwi    r3, 0
  beq-      .loc_0xBC
  stw       r4, 0x0(r3)

.loc_0xBC:
  lwz       r3, 0x0(r4)
  cmplwi    r3, 0
  beq-      .loc_0xD0
  stw       r4, 0x4(r3)
  b         .loc_0xD4

.loc_0xD0:
  stw       r4, 0x4(r5)

.loc_0xD4:
  lwz       r3, 0x8(r5)
  li        r0, 0
  stw       r3, 0x4(r6)
  cmplwi    r3, 0
  stw       r0, 0x0(r6)
  beq-      .loc_0xF0
  stw       r6, 0x0(r3)

.loc_0xF0:
  stw       r6, 0x8(r5)
  addi      r3, r6, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000284
 */
void OSAllocFixed(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void OSFreeToHeap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void OSSetCurrentHeap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F68A8
 * Size:	000070
 */
void OSInitAlloc(void)
{
/*
.loc_0x0:
  mulli     r7, r5, 0xC
  stw       r3, 0x31E0(r13)
  stw       r5, 0x31E4(r13)
  li        r6, 0
  addi      r3, r6, 0
  li        r8, 0
  li        r5, -0x1
  b         .loc_0x3C

.loc_0x20:
  lwz       r0, 0x31E0(r13)
  addi      r8, r8, 0x1
  add       r9, r0, r6
  stw       r5, 0x0(r9)
  addi      r6, r6, 0xC
  stw       r3, 0x8(r9)
  stw       r3, 0x4(r9)

.loc_0x3C:
  lwz       r0, 0x31E4(r13)
  cmpw      r8, r0
  blt+      .loc_0x20
  lwz       r3, 0x31E0(r13)
  rlwinm    r0,r4,0,0,26
  li        r4, -0x1
  stw       r0, 0x31EC(r13)
  add       r3, r3, r7
  addi      r0, r3, 0x1F
  stw       r4, 0x29D8(r13)
  rlwinm    r3,r0,0,0,26
  stw       r3, 0x31E8(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void OSCreateHeap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void OSDestroyHeap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void OSAddToHeap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000360
 */
void OSCheckHeap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void OSReferentSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000104
 */
void OSDumpHeap(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void OSVisitAllocated(void)
{
	// UNUSED FUNCTION
}