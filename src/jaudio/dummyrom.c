

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GetNeosRomTop()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void mesg_finishcall(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void ARAMStartDMAmesg(unsigned long, unsigned long, unsigned long, unsigned long, long, OSMesgQueue_s *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void ARAMStartDMA(unsigned long, unsigned long, unsigned long, unsigned long, long, unsigned long *, void (*) ())
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800061A0
 * Size:	000008
 */
void Jac_SetAudioARAMSize(unsigned long)
{
/*
.loc_0x0:
  stw       r3, 0x2B3C(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void ARAlloc2(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800061C0
 * Size:	000058
 */
void ARAllocFull(unsigned long *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  addi      r6, r4, 0x6298
  stwu      r1, -0x18(r1)
  stmw      r30, 0x10(r1)
  addi      r30, r3, 0
  mr        r3, r6
  lwz       r5, 0x0(r6)
  lwz       r4, 0x4(r6)
  lwz       r0, 0x8(r6)
  sub       r4, r4, r5
  sub       r31, r0, r4
  subi      r4, r31, 0x20
  bl        -0xBB8
  subi      r0, r31, 0x20
  stw       r0, 0x0(r30)
  lmw       r30, 0x10(r1)
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80006220
 * Size:	000098
 */
void Jac_InitARAM(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  lwz       r0, 0x2B3C(r13)
  cmplwi    r0, 0
  beq-      .loc_0x24
  mr        r31, r0
  b         .loc_0x28

.loc_0x24:
  lis       r31, 0x40

.loc_0x28:
  bl        0x2008EC
  li        r0, 0
  stw       r3, 0x2B34(r13)
  li        r5, 0x40
  lis       r3, 0x803D
  stw       r0, 0x24(r1)
  addi      r3, r3, 0x6298
  lwz       r0, 0x2B34(r13)
  lwz       r4, 0x24(r1)
  stw       r5, 0x2B38(r13)
  add       r0, r4, r0
  stw       r0, 0x24(r1)
  lwz       r0, 0x24(r1)
  lwz       r4, 0x24(r1)
  stw       r0, 0x2B30(r13)
  addis     r4, r4, 0x1
  subi      r0, r4, 0x4000
  stw       r0, 0x24(r1)
  lwz       r4, 0x24(r1)
  lwz       r0, 0x24(r1)
  sub       r5, r31, r0
  bl        -0xBDC
  lwz       r0, 0x24(r1)
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}