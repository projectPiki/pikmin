#include "types.h"
#include "Vector3f.h"

namespace zen {
	struct particleGenerator {
		u32 _00;
		u8 filler[20];
		Vector3f* m_vector_ptr; // _18
		u8 filler2[100];
		u32 m_pgen_thingy; // _80

		void forceFinish();
	};
	class PtclGenPack {
		u32 m_limit; // _00
		particleGenerator** m_pgen_ptr_ptr; // _04

		void setPtclGenPtr(u32, particleGenerator*);
		void getPtclGenPtr(u32);
		void setEmitPos(Vector3f&);
		void setEmitPosPtr(Vector3f*);
		void setEmitDir(Vector3f&);
		void startGen();
		void stopGen();
		void start();
		void stop();
		void finish();
		void forceFinish();
		bool checkStopGen();
		void checkStop();
		void checkEmit();
		void checkActive();
	};
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
	void PtclGenPack::getPtclGenPtr(u32)
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
	void PtclGenPack::setEmitPosPtr(Vector3f* param_1) // matching
	{
		u32 i;
		particleGenerator** pgen_ptr_ptr;

		pgen_ptr_ptr = m_pgen_ptr_ptr;
		for (i = 0; i < m_limit; i++, pgen_ptr_ptr++) {
			if (*pgen_ptr_ptr != nullptr) {
				(*pgen_ptr_ptr)->m_vector_ptr = param_1;
			}
		}
		return;
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
	//void PtclGenPack::setCallBack(zen::CallBack1<zen::particleGenerator*>*, zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
	//{
	//	// UNUSED FUNCTION
	//}

	/*
	 * --INFO--
	 * Address:	801DA0D8
	 * Size:	00003C
	 */
	void PtclGenPack::startGen() // matching
	{
		particleGenerator* pgen_ptr;
		u32 i;
		particleGenerator** pgen_ptr_ptr;

		pgen_ptr_ptr = m_pgen_ptr_ptr;
		for (i = 0; i < m_limit; i++, pgen_ptr_ptr++) {
			pgen_ptr = *pgen_ptr_ptr;
			if (pgen_ptr != nullptr) {
				pgen_ptr->m_pgen_thingy = pgen_ptr->m_pgen_thingy & 0xfffffff7;
			}
		}
		return;
	}

	/*
	 * --INFO--
	 * Address:	801DA114
	 * Size:	00003C
	 */
	void PtclGenPack::stopGen() // matching
	{
		particleGenerator* pgen_ptr;
		u32 i;
		particleGenerator** pgen_ptr_ptr;

		pgen_ptr_ptr = m_pgen_ptr_ptr;
		for (i = 0; i < m_limit; i++, pgen_ptr_ptr++) {
			pgen_ptr = *pgen_ptr_ptr;
			if (pgen_ptr != nullptr) {
				pgen_ptr->m_pgen_thingy = pgen_ptr->m_pgen_thingy | 8;
			}
		}
		return;
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
	void PtclGenPack::finish() // matching
	{
		particleGenerator* pgen_ptr;
		u32 i;
		particleGenerator** pgen_ptr_ptr;

		pgen_ptr_ptr = m_pgen_ptr_ptr;
		for (i = 0; i < m_limit; i++, pgen_ptr_ptr++) {
			pgen_ptr = *pgen_ptr_ptr;
			if (pgen_ptr != nullptr) {
				pgen_ptr->m_pgen_thingy = pgen_ptr->m_pgen_thingy | 2;
				*pgen_ptr_ptr = nullptr;
			}
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
	void PtclGenPack::forceFinish() // matches
	{
			u32 i;
			particleGenerator** pgen_ptr_ptr = m_pgen_ptr_ptr;

			for (i = 0; i < m_limit; i++, pgen_ptr_ptr++)
			{
				if (!*pgen_ptr_ptr)
					continue;

				(*pgen_ptr_ptr)->forceFinish();
				*pgen_ptr_ptr = nullptr;
			}

			return;
	}

	/*
	 * --INFO--
	 * Address:	801DA20C
	 * Size:	000044
	 */
	//bool PtclGenPack::checkStopGen()
	//{
	//	u32 counter;
	//	particleGenerator** pgen_ptr_ptr;

	//	counter = m_limit;
	//	pgen_ptr_ptr = m_pgen_ptr_ptr;
	//	while (true) {
	//		if (counter == 0) {
	//			return true;
	//		}
	//		if ((*pgen_ptr_ptr != nullptr) && (((*pgen_ptr_ptr)->m_pgen_thingy & 8) == 0)) break;
	//		pgen_ptr_ptr = pgen_ptr_ptr + 1;
	//		counter = counter - 1;
	//	}
	//	return false;
	//	/*
	//	.loc_0x0:
	//	  lwz       r0, 0x0(r3)
	//	  lwz       r4, 0x4(r3)
	//	  cmplwi    r0, 0
	//	  mtctr     r0
	//	  ble-      .loc_0x3C

	//	.loc_0x14:
	//	  lwz       r3, 0x0(r4)
	//	  cmplwi    r3, 0
	//	  beq-      .loc_0x34
	//	  lwz       r0, 0x80(r3)
	//	  rlwinm.   r0,r0,0,28,28
	//	  bne-      .loc_0x34
	//	  li        r3, 0
	//	  blr

	//	.loc_0x34:
	//	  addi      r4, r4, 0x4
	//	  bdnz+     .loc_0x14

	//	.loc_0x3C:
	//	  li        r3, 0x1
	//	  blr
	//	*/
	//}

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
