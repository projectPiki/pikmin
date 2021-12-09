#include "types.h"
#include "Vector3f.h"

namespace zen {
	struct particleGenerator {
		u32 _00;
		u8 filler[20];
		Vector3f* m_vector_ptr; // _18
		u8 filler2[100];
		u32 m_pgen_flags; // _80

		void forceFinish();
	};
	class PtclGenPack {
		u32 m_limit; // _00
		particleGenerator** m_ptcl_gen_list; // _04

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
		m_ptcl_gen_list[param_1] = param_2;
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
		particleGenerator** particle_gen_list;

		particle_gen_list = m_ptcl_gen_list;
		for (i = 0; i < m_limit; i++, particle_gen_list++) {
			if (particle_gen_list[0] != nullptr) {
				(*particle_gen_list)->m_vector_ptr = param_1;
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
		particleGenerator** particle_gen_list;

		particle_gen_list = m_ptcl_gen_list;
		for (i = 0; i < m_limit; i++, particle_gen_list++) {
			pgen_ptr = particle_gen_list[0];
			if (pgen_ptr != nullptr) {
				pgen_ptr->m_pgen_flags &= 0xFFFFFFF7;
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
		particleGenerator** particle_gen_list;

		particle_gen_list = m_ptcl_gen_list;
		for (i = 0; i < m_limit; i++, particle_gen_list++) {
			pgen_ptr = particle_gen_list[0];
			if (pgen_ptr != nullptr) {
				pgen_ptr->m_pgen_flags |= 8;
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
		particleGenerator** particle_gen_list;

		particle_gen_list = m_ptcl_gen_list;
		for (i = 0; i < m_limit; i++, particle_gen_list++) {
			pgen_ptr = particle_gen_list[0];
			if (pgen_ptr != nullptr) {
				pgen_ptr->m_pgen_flags |= 2;
				particle_gen_list[0] = nullptr;
			}
		}
		return;
	}

	/*
	 * --INFO--
	 * Address:	801DA194
	 * Size:	000078
	 */
	void PtclGenPack::forceFinish() // matches
	{
		u32 i;
		particleGenerator** ptcl_list = &m_ptcl_gen_list[0];

		for (i = 0; i < m_limit; i++, ptcl_list++)
		{
			if (!ptcl_list[0])
				continue;

			ptcl_list[0]->forceFinish();
			ptcl_list[0] = nullptr;
		}
	}

	/*
	 * --INFO--
	 * Address:	801DA20C
	 * Size:	000044
	 */
	bool PtclGenPack::checkStopGen() // matching
	{
		particleGenerator* pgen_ptr;
		u32 i;
		particleGenerator** particle_gen_list;

		particle_gen_list = m_ptcl_gen_list;
		for (i = 0; i < m_limit; i++, particle_gen_list++) {
			pgen_ptr = particle_gen_list[0];
			if ((particle_gen_list[0] != nullptr) && (((*particle_gen_list)->m_pgen_flags & 8) == 0))
				return false;
		}
		return true;
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
