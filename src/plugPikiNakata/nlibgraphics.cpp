#include "nlib/Graphics.h"
#include "nlib/Math.h"
#include "Camera.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D95C
 * Size:	000084
 */
NCamera::NCamera(Camera* cam)
{
	mCamera = cam;
	_08.set(0.0f, 0.0f, 0.0f);
	_14.set(0.0f, 0.0f, 1.0f);
	_00 = 0.0f;
}

/*
 * --INFO--
 * Address:	8011D9E0
 * Size:	0000D0
 */
void NCamera::makeMatrix()
{
	NVector3f& v3 = _14;
	NVector3f& v2 = _08;
	NVector3f vec(v2, v3);
	vec.normalize();

	NOrientation orient(vec);
	orient.normalize();

	NVector3f v1(orient._0C);

	NAxisAngle4f angle(vec, _00);
	NTransform3D transform;
	transform.inputAxisAngle(angle);
	transform.transform(v1);
	v1.normalize();
	mCamera->calcLookAt(v2, v3, &v1);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  stw       r30, 0x98(r1)
	  stw       r29, 0x94(r1)
	  addi      r29, r3, 0
	  addi      r31, r29, 0x14
	  addi      r30, r29, 0x8
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x80
	  bl        -0xAE4
	  addi      r3, r1, 0x80
	  bl        -0x918
	  addi      r3, r1, 0x68
	  addi      r4, r1, 0x80
	  bl        -0x1AD8
	  addi      r3, r1, 0x68
	  bl        -0x1A18
	  lfs       f0, 0x74(r1)
	  addi      r3, r1, 0x4C
	  addi      r4, r1, 0x80
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x0(r29)
	  bl        -0x1DD4
	  addi      r3, r1, 0xC
	  bl        -0x105C
	  addi      r3, r1, 0xC
	  addi      r4, r1, 0x4C
	  bl        -0xD98
	  addi      r3, r1, 0xC
	  addi      r4, r1, 0x5C
	  bl        -0xDD0
	  addi      r3, r1, 0x5C
	  bl        -0x97C
	  lwz       r3, 0x4(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  addi      r6, r1, 0x5C
	  bl        -0xDAA84
	  lwz       r0, 0xA4(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011DAB0
 * Size:	000098
 */
void NCamera::makeCamera()
{
	mCamera->_164.set(_08);
	NVector3f vec(_14, _08);
	NPolar3f polar(vec);
	mCamera->_320.x = polar._04 - NMathF::pi / 2;
	mCamera->_320.y = polar._08;
	mCamera->_320.z = 0.0f;
}
