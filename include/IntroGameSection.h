#ifndef _INTROGAMESECTION_H
#define _INTROGAMESECTION_H

#include "types.h"
#include "Section.h"
#include "Camera.h"
#include "DayMgr.h"
#include "system.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct IntroGameSection : public Section {
	IntroGameSection();

	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

/**
 * @brief TODO
 */
struct IntroGameSetupSection : public BaseGameSection {
	IntroGameSetupSection()
	{
		_34  = new IntroModeState(mController);
		_39C = new DayMgr(nullptr, mController);

		// TODO

		void* memory = System::alloc(0x500000);
		gsys->mHeaps[SYSHEAP_Movie].init("movie", 2, memory, 0x500000);
	}

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	// _00     = VTBL
	// _00-_44 = BaseGameSection
	u32 _44;      // _44
	u32 _48;      // _48
	u32 _4C;      // _4C
	Camera _50;   // _50
	f32 _398;     // _398
	DayMgr* _39C; // _39C
	u32 _3A0;     // _3A0
	u8 _3A4;      // _3A4
};

#endif
