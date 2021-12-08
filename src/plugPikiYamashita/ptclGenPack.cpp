#include "types.h"
#include "Vector3f.h"

namespace zen {
	struct particleGenerator {
		u32 _00;
	};
	class PtclGenPack {
		u32 m_limit; // _00
		particleGenerator** m_pgen_ptr_ptr; // _04

		void setPtclGenPtr(u32, particleGenerator*);
	};
}

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
 * Address:	801DA088
 * Size:	00001C
 */
namespace zen {
	void PtclGenPack::setPtclGenPtr(u32 param_1, particleGenerator* param_2) { // matching
		if (param_1 >= m_limit)
		{
			return;
		}
		m_pgen_ptr_ptr[param_1] = param_2;
		return;
	};


	/*
	 * --INFO--
	 * Address:	........
	 * Size:	000010
	 */
	void PtclGenPack::getPtclGenPtr(unsigned long)
	{
		// UNUSED FUNCTION
	}

	/*
	 * --INFO--
	 * Address:	........
	 * Size:	000048
	 */
	void PtclGenPack::setEmitPos(Vector3f&)
	{
		// UNUSED FUNCTION
	}

	/*
	 * --INFO--
	 * Address:	801DA0A4
	 * Size:	000034
	 */
	void PtclGenPack::setEmitPosPtr(Vector3f* param_1)
	{
		u32 i;
		particleGenerator** pgen_ptr_ptr;

		pgen_ptr_ptr = this->m_pgen_ptr_ptr;
		for (i = 0; i < this->m_limit; i = i + 1) {
			if (*pgen_ptr_ptr != nullptr) {
				(*pgen_ptr_ptr)->m_vector_ptr = param_1;
			}
			pgen_ptr_ptr = pgen_ptr_ptr + 1;
		}
		return;
		/*
		.loc_0x0:
		  lwz       r7, 0x4(r3)
		  li        r6, 0
		  b         .loc_0x24

		.loc_0xC:
		  lwz       r5, 0x0(r7)
		  cmplwi    r5, 0
		  beq-      .loc_0x1C
		  stw       r4, 0x18(r5)

		.loc_0x1C:
		  addi      r6, r6, 0x1
		  addi      r7, r7, 0x4

		.loc_0x24:
		  lwz       r0, 0x0(r3)
		  cmplw     r6, r0
		  blt+      .loc_0xC
		  blr
		*/
	}

	/*
	 * --INFO--
	 * Address:	........
	 * Size:	000048
	 */
	void PtclGenPack::setEmitDir(Vector3f&)
	{
		// UNUSED FUNCTION
	}

	/*
	 * --INFO--
	 * Address:	........
	 * Size:	000084
	 */
	void PtclGenPack::setCallBack(zen::CallBack1<zen::particleGenerator*>*, zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
	{
		// UNUSED FUNCTION
	}

	/*
	 * --INFO--
	 * Address:	801DA0D8
	 * Size:	00003C
	 */
	void PtclGenPack::startGen()
	{
		particleGenerator* pgen_ptr;
		u32 i;
		particleGenerator** pgen_ptr_ptr;

		pgen_ptr_ptr = this->m_pgen_ptr_ptr;
		for (i = 0; i < this->m_limit; i = i + 1) {
			pgen_ptr = *pgen_ptr_ptr;
			if (pgen_ptr != nullptr) {
				pgen_ptr->m_pgen_thingy = pgen_ptr->m_pgen_thingy & 0xfffffff7;
			}
			pgen_ptr_ptr = pgen_ptr_ptr + 1;
		}
		return;
		/*
		.loc_0x0:
		  lwz       r6, 0x4(r3)
		  li        r5, 0
		  b         .loc_0x2C

		.loc_0xC:
		  lwz       r4, 0x0(r6)
		  cmplwi    r4, 0
		  beq-      .loc_0x24
		  lwz       r0, 0x80(r4)
		  rlwinm    r0,r0,0,29,27
		  stw       r0, 0x80(r4)

		.loc_0x24:
		  addi      r5, r5, 0x1
		  addi      r6, r6, 0x4

		.loc_0x2C:
		  lwz       r0, 0x0(r3)
		  cmplw     r5, r0
		  blt+      .loc_0xC
		  blr
		*/
	}

	/*
	 * --INFO--
	 * Address:	801DA114
	 * Size:	00003C
	 */
	void PtclGenPack::stopGen()
	{
		particleGenerator* ppVar1;
		u32 uVar2;
		particleGenerator** pppVar3;

		pppVar3 = this->m_pgen_ptr_ptr;
		for (uVar2 = 0; uVar2 < this->m_limit; uVar2 = uVar2 + 1) {
			ppVar1 = *pppVar3;
			if (ppVar1 != nullptr) {
				ppVar1->m_pgen_thingy = ppVar1->m_pgen_thingy | 8;
			}
			pppVar3 = pppVar3 + 1;
		}
		return;
		/*
		.loc_0x0:
		  lwz       r6, 0x4(r3)
		  li        r5, 0
		  b         .loc_0x2C

		.loc_0xC:
		  lwz       r4, 0x0(r6)
		  cmplwi    r4, 0
		  beq-      .loc_0x24
		  lwz       r0, 0x80(r4)
		  ori       r0, r0, 0x8
		  stw       r0, 0x80(r4)

		.loc_0x24:
		  addi      r5, r5, 0x1
		  addi      r6, r6, 0x4

		.loc_0x2C:
		  lwz       r0, 0x0(r3)
		  cmplw     r5, r0
		  blt+      .loc_0xC
		  blr
		*/
	}

	/*
	 * --INFO--
	 * Address:	........
	 * Size:	00003C
	 */
	void PtclGenPack::start()
	{
		// UNUSED FUNCTION
	}

	/*
	 * --INFO--
	 * Address:	........
	 * Size:	00003C
	 */
	void PtclGenPack::stop()
	{
		// UNUSED FUNCTION
	}

	/*
	 * --INFO--
	 * Address:	801DA150
	 * Size:	000044
	 */
	void PtclGenPack::finish()
	{
		particleGenerator* pgen_ptr;
		u32 i;
		particleGenerator** pgen_ptr_ptr;

		pgen_ptr_ptr = this->m_pgen_ptr_ptr;
		for (i = 0; i < this->m_limit; i = i + 1) {
			pgen_ptr = *pgen_ptr_ptr;
			if (pgen_ptr != nullptr) {
				pgen_ptr->m_pgen_thingy = pgen_ptr->m_pgen_thingy | 2;
				*pgen_ptr_ptr = nullptr;
			}
			pgen_ptr_ptr = pgen_ptr_ptr + 1;
		}
		return;
		/*
		.loc_0x0:
		  lwz       r7, 0x4(r3)
		  li        r6, 0
		  li        r4, 0
		  b         .loc_0x34

		.loc_0x10:
		  lwz       r5, 0x0(r7)
		  cmplwi    r5, 0
		  beq-      .loc_0x2C
		  lwz       r0, 0x80(r5)
		  ori       r0, r0, 0x2
		  stw       r0, 0x80(r5)
		  stw       r4, 0x0(r7)

		.loc_0x2C:
		  addi      r6, r6, 0x1
		  addi      r7, r7, 0x4

		.loc_0x34:
		  lwz       r0, 0x0(r3)
		  cmplw     r6, r0
		  blt+      .loc_0x10
		  blr
		*/
	}

	/*
	 * --INFO--
	 * Address:	801DA194
	 * Size:	000078
	 */
	void PtclGenPack::forceFinish()
	{
		particleGenerator** pgen_ptr_ptr;
		u32 i;

		pgen_ptr_ptr = this->m_pgen_ptr_ptr;
		for (i = 0; i < this->m_limit; i = i + 1) {
			if (*pgen_ptr_ptr != nullptr) {
				particleGenerator::forceFinish(*pgen_ptr_ptr);
				*pgen_ptr_ptr = nullptr;
			}
			pgen_ptr_ptr = pgen_ptr_ptr + 1;
		}
		return;
		/*
		.loc_0x0:
		  mflr      r0
		  stw       r0, 0x4(r1)
		  stwu      r1, -0x20(r1)
		  stw       r31, 0x1C(r1)
		  li        r31, 0
		  stw       r30, 0x18(r1)
		  li        r30, 0
		  stw       r29, 0x14(r1)
		  stw       r28, 0x10(r1)
		  mr        r28, r3
		  lwz       r29, 0x4(r3)
		  b         .loc_0x4C

		.loc_0x30:
		  lwz       r3, 0x0(r29)
		  cmplwi    r3, 0
		  beq-      .loc_0x44
		  bl        -0x395D4
		  stw       r31, 0x0(r29)

		.loc_0x44:
		  addi      r30, r30, 0x1
		  addi      r29, r29, 0x4

		.loc_0x4C:
		  lwz       r0, 0x0(r28)
		  cmplw     r30, r0
		  blt+      .loc_0x30
		  lwz       r0, 0x24(r1)
		  lwz       r31, 0x1C(r1)
		  lwz       r30, 0x18(r1)
		  lwz       r29, 0x14(r1)
		  lwz       r28, 0x10(r1)
		  addi      r1, r1, 0x20
		  mtlr      r0
		  blr
		*/
	}

	/*
	 * --INFO--
	 * Address:	801DA20C
	 * Size:	000044
	 */
	bool PtclGenPack::checkStopGen()
	{
		u32 counter;
		particleGenerator** pgen_ptr_ptr;

		counter = this->m_limit;
		pgen_ptr_ptr = this->m_pgen_ptr_ptr;
		while (true) {
			if (counter == 0) {
				return true;
			}
			if ((*pgen_ptr_ptr != (particleGenerator*)0x0) && (((*pgen_ptr_ptr)->m_pgen_thingy & 8) == 0)) break;
			pgen_ptr_ptr = pgen_ptr_ptr + 1;
			counter = counter - 1;
		}
		return false;
		/*
		.loc_0x0:
		  lwz       r0, 0x0(r3)
		  lwz       r4, 0x4(r3)
		  cmplwi    r0, 0
		  mtctr     r0
		  ble-      .loc_0x3C

		.loc_0x14:
		  lwz       r3, 0x0(r4)
		  cmplwi    r3, 0
		  beq-      .loc_0x34
		  lwz       r0, 0x80(r3)
		  rlwinm.   r0,r0,0,28,28
		  bne-      .loc_0x34
		  li        r3, 0
		  blr

		.loc_0x34:
		  addi      r4, r4, 0x4
		  bdnz+     .loc_0x14

		.loc_0x3C:
		  li        r3, 0x1
		  blr
		*/
	}

	/*
	 * --INFO--
	 * Address:	........
	 * Size:	000044
	 */
	void PtclGenPack::checkStop()
	{
		// UNUSED FUNCTION
	}

	/*
	 * --INFO--
	 * Address:	........
	 * Size:	000044
	 */
	void PtclGenPack::checkEmit()
	{
		// UNUSED FUNCTION
	}

	/*
	 * --INFO--
	 * Address:	........
	 * Size:	000044
	 */
	void PtclGenPack::checkActive()
	{
		// UNUSED FUNCTION
	}
}