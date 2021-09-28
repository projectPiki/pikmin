

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void DCFlashInvalidate(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6BA4
 * Size:	000014
 */
void DCEnable(void)
{
/*
.loc_0x0:
  sync      
  mfspr     r3, 0x3F0
  ori       r3, r3, 0x4000
  mtspr     1008, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void DCDisable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void DCFreeze(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void DCUnfreeze(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCTouchLoad(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCBlockZero(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCBlockStore(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCBlockFlush(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void DCBlockInvalidate(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6BB8
 * Size:	000030
 */
void DCInvalidateRange(void)
{
/*
.loc_0x0:
  cmplwi    r4, 0
  blelr-    
  rlwinm.   r5,r3,0,27,31
  beq-      .loc_0x14
  addi      r4, r4, 0x20

.loc_0x14:
  addi      r4, r4, 0x1F
  rlwinm    r4,r4,27,5,31
  mtctr     r4

.loc_0x20:
  dcbi      r0, r3
  addi      r3, r3, 0x20
  bdnz+     .loc_0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6BE8
 * Size:	000034
 */
void DCFlushRange(void)
{
/*
.loc_0x0:
  cmplwi    r4, 0
  blelr-    
  rlwinm.   r5,r3,0,27,31
  beq-      .loc_0x14
  addi      r4, r4, 0x20

.loc_0x14:
  addi      r4, r4, 0x1F
  rlwinm    r4,r4,27,5,31
  mtctr     r4

.loc_0x20:
  dcbf      r0, r3
  addi      r3, r3, 0x20
  bdnz+     .loc_0x20
  sc        
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6C1C
 * Size:	000034
 */
void DCStoreRange(void)
{
/*
.loc_0x0:
  cmplwi    r4, 0
  blelr-    
  rlwinm.   r5,r3,0,27,31
  beq-      .loc_0x14
  addi      r4, r4, 0x20

.loc_0x14:
  addi      r4, r4, 0x1F
  rlwinm    r4,r4,27,5,31
  mtctr     r4

.loc_0x20:
  dcbst     r0, r3
  addi      r3, r3, 0x20
  bdnz+     .loc_0x20
  sc        
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6C50
 * Size:	000030
 */
void DCFlushRangeNoSync(void)
{
/*
.loc_0x0:
  cmplwi    r4, 0
  blelr-    
  rlwinm.   r5,r3,0,27,31
  beq-      .loc_0x14
  addi      r4, r4, 0x20

.loc_0x14:
  addi      r4, r4, 0x1F
  rlwinm    r4,r4,27,5,31
  mtctr     r4

.loc_0x20:
  dcbf      r0, r3
  addi      r3, r3, 0x20
  bdnz+     .loc_0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6C80
 * Size:	000030
 */
void DCStoreRangeNoSync(void)
{
/*
.loc_0x0:
  cmplwi    r4, 0
  blelr-    
  rlwinm.   r5,r3,0,27,31
  beq-      .loc_0x14
  addi      r4, r4, 0x20

.loc_0x14:
  addi      r4, r4, 0x1F
  rlwinm    r4,r4,27,5,31
  mtctr     r4

.loc_0x20:
  dcbst     r0, r3
  addi      r3, r3, 0x20
  bdnz+     .loc_0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6CB0
 * Size:	000030
 */
void DCZeroRange(void)
{
/*
.loc_0x0:
  cmplwi    r4, 0
  blelr-    
  rlwinm.   r5,r3,0,27,31
  beq-      .loc_0x14
  addi      r4, r4, 0x20

.loc_0x14:
  addi      r4, r4, 0x1F
  rlwinm    r4,r4,27,5,31
  mtctr     r4

.loc_0x20:
  dcbz      r0, r3
  addi      r3, r3, 0x20
  bdnz+     .loc_0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void DCTouchRange(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6CE0
 * Size:	000038
 */
void ICInvalidateRange(void)
{
/*
.loc_0x0:
  cmplwi    r4, 0
  blelr-    
  rlwinm.   r5,r3,0,27,31
  beq-      .loc_0x14
  addi      r4, r4, 0x20

.loc_0x14:
  addi      r4, r4, 0x1F
  rlwinm    r4,r4,27,5,31
  mtctr     r4

.loc_0x20:
  icbi      r0, r3
  addi      r3, r3, 0x20
  bdnz+     .loc_0x20
  sync      
  isync     
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6D18
 * Size:	000010
 */
void ICFlashInvalidate(void)
{
/*
.loc_0x0:
  mfspr     r3, 0x3F0
  ori       r3, r3, 0x800
  mtspr     1008, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6D28
 * Size:	000014
 */
void ICEnable(void)
{
/*
.loc_0x0:
  isync     
  mfspr     r3, 0x3F0
  ori       r3, r3, 0x8000
  mtspr     1008, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void ICDisable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void ICFreeze(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void ICUnfreeze(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ICBlockInvalidate(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ICSync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void __LCEnable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void LCEnable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void LCDisable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void LCAllocOneTag(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void LCAllocTags(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void LCLoadBlocks(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void LCStoreBlocks(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void LCAlloc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void LCAllocNoInvalidate(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void LCLoadData(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void LCStoreData(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void LCQueueLength(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void LCQueueWait(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void LCFlushQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void L2Init(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void L2Enable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void L2Disable(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6D3C
 * Size:	000098
 */
void L2GlobalInvalidate(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  sync      
  bl        -0x13F4
  rlwinm    r3,r3,0,1,31
  bl        -0x13F4
  sync      
  bl        -0x1404
  oris      r3, r3, 0x20
  bl        -0x1404
  b         .loc_0x34

.loc_0x34:
  b         .loc_0x38

.loc_0x38:
  bl        -0x1418
  rlwinm    r0,r3,0,31,31
  cmplwi    r0, 0
  bne+      .loc_0x38
  bl        -0x1428
  rlwinm    r3,r3,0,11,9
  bl        -0x1428
  b         .loc_0x58

.loc_0x58:
  lis       r3, 0x802E
  addi      r31, r3, 0x74E8
  b         .loc_0x64

.loc_0x64:
  b         .loc_0x74

.loc_0x68:
  mr        r3, r31
  crclr     6, 0x6
  bl        0x6D98

.loc_0x74:
  bl        -0x1454
  rlwinm    r0,r3,0,31,31
  cmplwi    r0, 0
  bne+      .loc_0x68
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void L2SetDataOnly(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void L2SetWriteThrough(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6DD4
 * Size:	000160
 */
void DMAErrorHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stw       r31, 0x7C(r1)
  stw       r30, 0x78(r1)
  stw       r29, 0x74(r1)
  bne-      cr1, .loc_0x3C
  stfd      f1, 0x28(r1)
  stfd      f2, 0x30(r1)
  stfd      f3, 0x38(r1)
  stfd      f4, 0x40(r1)
  stfd      f5, 0x48(r1)
  stfd      f6, 0x50(r1)
  stfd      f7, 0x58(r1)
  stfd      f8, 0x60(r1)

.loc_0x3C:
  stw       r3, 0x8(r1)
  stw       r4, 0xC(r1)
  stw       r5, 0x10(r1)
  stw       r6, 0x14(r1)
  stw       r7, 0x18(r1)
  stw       r8, 0x1C(r1)
  stw       r9, 0x20(r1)
  stw       r10, 0x24(r1)
  mr        r29, r4
  lis       r3, 0x802E
  addi      r31, r3, 0x74E8
  bl        -0x14AC
  mr        r30, r3
  crclr     6, 0x6
  addi      r3, r31, 0x2C
  bl        0xA44
  lwz       r5, 0x19C(r29)
  mr        r4, r30
  addi      r3, r31, 0x44
  crclr     6, 0x6
  bl        0xA30
  rlwinm    r0,r30,0,8,11
  cmplwi    r0, 0
  beq-      .loc_0xAC
  lwz       r0, 0x19C(r29)
  rlwinm    r0,r0,0,10,10
  cmplwi    r0, 0
  bne-      .loc_0xC4

.loc_0xAC:
  addi      r3, r31, 0x60
  crclr     6, 0x6
  bl        0xA08
  mr        r3, r29
  bl        0x68C
  bl        -0x1518

.loc_0xC4:
  addi      r3, r31, 0x90
  crclr     6, 0x6
  bl        0x9F0
  addi      r3, r31, 0xCC
  crclr     6, 0x6
  bl        0x9E4
  rlwinm    r0,r30,0,8,8
  cmplwi    r0, 0
  beq-      .loc_0xF4
  addi      r3, r31, 0x104
  crclr     6, 0x6
  bl        0x9CC

.loc_0xF4:
  rlwinm    r0,r30,0,9,9
  cmplwi    r0, 0
  beq-      .loc_0x10C
  addi      r3, r31, 0x144
  crclr     6, 0x6
  bl        0x9B4

.loc_0x10C:
  rlwinm    r0,r30,0,10,10
  cmplwi    r0, 0
  beq-      .loc_0x124
  addi      r3, r31, 0x170
  crclr     6, 0x6
  bl        0x99C

.loc_0x124:
  rlwinm    r0,r30,0,11,11
  cmplwi    r0, 0
  beq-      .loc_0x13C
  addi      r3, r31, 0x190
  crclr     6, 0x6
  bl        0x984

.loc_0x13C:
  mr        r3, r30
  bl        -0x157C
  lwz       r0, 0x84(r1)
  lwz       r31, 0x7C(r1)
  lwz       r30, 0x78(r1)
  mtlr      r0
  lwz       r29, 0x74(r1)
  addi      r1, r1, 0x80
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6F34
 * Size:	0000F4
 */
void __OSCacheInit(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  stw       r30, 0x8(r1)
  lis       r3, 0x802E
  addi      r31, r3, 0x74E8
  bl        -0x15FC
  rlwinm    r0,r3,0,16,16
  cmplwi    r0, 0
  bne-      .loc_0x3C
  bl        -0x238
  addi      r3, r31, 0x1AC
  crclr     6, 0x6
  bl        0x6BD8

.loc_0x3C:
  bl        -0x161C
  rlwinm    r0,r3,0,17,17
  cmplwi    r0, 0
  bne-      .loc_0x5C
  bl        -0x3DC
  addi      r3, r31, 0x1C8
  crclr     6, 0x6
  bl        0x6BB8

.loc_0x5C:
  bl        -0x1634
  rlwinm    r0,r3,0,0,0
  cmplwi    r0, 0
  bne-      .loc_0xC0
  bl        -0x165C
  mr        r30, r3
  sync      
  li        r3, 0x30
  bl        -0x1664
  sync      
  sync      
  bl        -0x1660
  rlwinm    r3,r3,0,1,31
  bl        -0x1660
  sync      
  bl        -0x290
  mr        r3, r30
  bl        -0x1688
  bl        -0x167C
  oris      r0, r3, 0x8000
  rlwinm    r3,r0,0,11,9
  bl        -0x1680
  addi      r3, r31, 0x1E4
  crclr     6, 0x6
  bl        0x6B54

.loc_0xC0:
  lis       r3, 0x801F
  addi      r4, r3, 0x6DD4
  li        r3, 0x1
  bl        0xA3C
  addi      r3, r31, 0x1FC
  crclr     6, 0x6
  bl        0x6B38
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  lwz       r30, 0x8(r1)
  mtlr      r0
  addi      r1, r1, 0x10
  blr
*/
}