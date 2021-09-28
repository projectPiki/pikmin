

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
 * Address:	........
 * Size:	0000E8
 */
void SplineInterpolator::SplineInterpolator(int, NPool<SplineSegment> *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011DE60
 * Size:	00000C
 */
void SplineInterpolator::reset()
{
/*
.loc_0x0:
  li        r0, 0
  stb       r0, 0x10(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void SplineInterpolator::makeSpline()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NArray<SplineKeyFrame>::get(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void SplineInterpolator::interpolate(float, NPosture3D &, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011DE6C
 * Size:	0000E0
 */
void SplineInterpolator::interpolateNext(float, NPosture3D &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stfd      f31, 0x40(r1)
  fmr       f31, f1
  stw       r31, 0x3C(r1)
  mr        r31, r3
  stw       r30, 0x38(r1)
  mr        r30, r4
  lwz       r3, 0x0(r3)
  lwz       r0, 0x8(r3)
  cmpwi     r0, 0
  bne-      .loc_0x3C
  li        r3, 0
  b         .loc_0xC4

.loc_0x3C:
  cmpwi     r0, 0x1
  bne-      .loc_0x8C
  lwz       r12, 0x0(r3)
  li        r4, 0
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  addi      r31, r3, 0x4
  addi      r4, r31, 0x4
  addi      r3, r30, 0x4
  addi      r5, r4, 0x4
  addi      r6, r4, 0x8
  bl        -0xC084C
  addi      r4, r31, 0x10
  addi      r3, r30, 0x10
  addi      r5, r4, 0x4
  addi      r6, r4, 0x8
  bl        -0xC0860
  li        r3, 0x1
  b         .loc_0xC4

.loc_0x8C:
  fmr       f1, f31
  lbz       r4, 0x10(r31)
  mr        r3, r31
  bl        0x138
  cmpwi     r3, 0
  bge-      .loc_0xAC
  li        r3, 0
  b         .loc_0xC4

.loc_0xAC:
  fmr       f1, f31
  stb       r3, 0x10(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0
  bl        .loc_0xE0
  li        r3, 0x1

.loc_0xC4:
  lwz       r0, 0x4C(r1)
  lfd       f31, 0x40(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr       

.loc_0xE0:
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void SplineInterpolator::interpolateDirect(float, NPosture3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011DF4C
 * Size:	0000F0
 */
void SplineInterpolator::outputPosture(float, NPosture3D &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stfd      f31, 0x50(r1)
  stfd      f30, 0x48(r1)
  fmr       f30, f1
  stw       r31, 0x44(r1)
  stw       r30, 0x40(r1)
  mr        r30, r4
  stw       r29, 0x3C(r1)
  mr        r29, r3
  lwz       r3, 0x0(r3)
  lbz       r4, 0x10(r29)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lfs       f31, 0x20(r3)
  lwz       r3, 0x0(r29)
  lbz       r4, 0x10(r29)
  lwz       r12, 0x0(r3)
  addi      r4, r4, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lfs       f0, 0x20(r3)
  fsubs     f1, f30, f31
  lwz       r3, 0x8(r29)
  addi      r31, r30, 0x4
  fsubs     f0, f0, f31
  lwz       r3, 0x0(r3)
  lbz       r4, 0x10(r29)
  fdivs     f31, f1, f0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  fmr       f1, f31
  mr        r4, r31
  bl        -0x2410
  lwz       r3, 0xC(r29)
  addi      r31, r30, 0x10
  lbz       r4, 0x10(r29)
  lwz       r3, 0x0(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  fmr       f1, f31
  mr        r4, r31
  bl        -0x243C
  lwz       r0, 0x5C(r1)
  lfd       f31, 0x50(r1)
  lfd       f30, 0x48(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NArray<SplineSegment>::get(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011E03C
 * Size:	0000BC
 */
void SplineInterpolator::searchSegmentIndex(float, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stfd      f31, 0x50(r1)
  fmr       f31, f1
  stw       r31, 0x4C(r1)
  stw       r30, 0x48(r1)
  mr        r30, r3
  lwz       r3, 0x0(r3)
  lwz       r0, 0x8(r3)
  cmpwi     r0, 0x2
  bge-      .loc_0x38
  li        r3, 0
  b         .loc_0xA0

.loc_0x38:
  mr        r31, r4
  b         .loc_0x70

.loc_0x40:
  lwz       r12, 0x0(r3)
  addi      r4, r31, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lfs       f0, 0x20(r3)
  fcmpo     cr0, f31, f0
  cror      2, 0, 0x2
  bne-      .loc_0x6C
  mr        r3, r31
  b         .loc_0xA0

.loc_0x6C:
  addi      r31, r31, 0x1

.loc_0x70:
  lwz       r3, 0x0(r30)
  lwz       r4, 0x8(r3)
  subi      r4, r4, 0x1
  cmpw      r31, r4
  blt+      .loc_0x40
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x0(r30)
  lwz       r3, 0x8(r3)
  subi      r3, r3, 0x2

.loc_0xA0:
  lwz       r0, 0x5C(r1)
  lfd       f31, 0x50(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void SplineInterpolator::addFrame(SplineKeyFrame *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void NArray<SplineKeyFrame>::add(SplineKeyFrame *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SplineInterpolator::addSegment()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void NArray<SplineSegment>::add(SplineSegment *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void NPool<SplineSegment>::newObject()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void SplineInterpolator::removeAllFrames()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NArray<SplineSegment>::removeAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void NArray<SplineSegment>::remove(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NPool<SplineSegment>::deleteObject(SplineSegment *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void NPool<SplineSegment>::deleteObject(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NPool<SplineSegment>::indexOf(SplineSegment *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NPool<SplineSegment>::indexOf(SplineSegment *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NArray<SplineKeyFrame>::removeAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void NArray<SplineKeyFrame>::remove(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void SplineKeyFrame::SplineKeyFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SplineKeyFrame::transform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void SplineKeyFrame::inputPosture(NPosture3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void SplineKeyFrame::outputPosture(NPosture3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void SplineKeyFrame::interpolate(SplineKeyFrame &, float, NPosture3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void SplineKeyFrame::readData(Stream &, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void SplineSegment::SplineSegment()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001EC
 */
void SplineSegment::calcDistance(NVector3f &, float *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void SplineCurve::SplineCurve(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003E8
 */
void SplineCurve::makeCurve(float *, NVector3f **, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000334
 */
void SplineCurve::makeFunctions(int, float *, float *, NPolynomialFunction **)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NArray<SplineKeyFrame>::indexOf(SplineKeyFrame *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NArray<SplineKeyFrame>::set(int, SplineKeyFrame *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineKeyFrame>::remove(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void NArray<SplineKeyFrame>::insert(int, SplineKeyFrame *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NArray<SplineKeyFrame>::firstElement()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NArray<SplineKeyFrame>::lastElement()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NArray<SplineSegment>::indexOf(SplineSegment *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NArray<SplineSegment>::set(int, SplineSegment *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineSegment>::remove(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void NArray<SplineSegment>::insert(int, SplineSegment *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NArray<SplineSegment>::firstElement()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NArray<SplineSegment>::lastElement()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineSegment>::remove(SplineSegment *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineSegment>::add(int, SplineSegment *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NArray<SplineSegment>::indexOf(SplineSegment *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NArray<SplineSegment>::contains(SplineSegment *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineKeyFrame>::remove(SplineKeyFrame *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineKeyFrame>::add(int, SplineKeyFrame *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NArray<SplineKeyFrame>::indexOf(SplineKeyFrame *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NArray<SplineKeyFrame>::contains(SplineKeyFrame *)
{
	// UNUSED FUNCTION
}