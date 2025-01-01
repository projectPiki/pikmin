#ifndef _MIZU_H
#define _MIZU_H

#include "types.h"
#include "Boss.h"
#include "zen/Callback.h"
#include "zen/Particle.h"

struct MizuAi;

/**
 * @brief TODO.
 *
 * @note Size: 0x204.
 */
struct MizuProp : public BossProp, public CoreNode {

	/**
	 * @brief Mizu genuinely doesn't have any specific properties, but still needs this. Go figure.
	 */
	struct MizuProperties : public Parameters {
		inline MizuProperties() // TODO
		{
		}

		// _200-_204 = Parameters
	};

	MizuProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mMizuProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	MizuProperties mMizuProps; // _200
};

/**
 * @brief TODO.
 *
 * @note Size: 0x3C0.
 */
struct Mizu : public Boss {
	Mizu(CreatureProp*);

	virtual f32 getiMass();                   // _38
	virtual bool isVisible() { return _3B9; } // _74
	virtual void update();                    // _E0
	virtual void refresh(Graphics&);          // _EC
	virtual void doAI();                      // _104
	virtual void doAnimation();               // _108
	virtual void doKill();                    // _10C
	virtual void exitCourse();                // _110
	virtual bool attackDefaultPortion();      // _118
	virtual void drawShape(Graphics&);        // _120

	void initMizu(Vector3f&);
	void initGeyzer(Vector3f&);

	inline MizuProp* getMizuProp() { return static_cast<MizuProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss
	u8 _3B8;         // _3B8
	bool _3B9;       // _3B9
	MizuAi* mMizuAi; // _3BC
};

/**
 * @brief TODO
 */
struct MizuGenSpringPuffCallBack : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator* ptcl) // _08
	{
		if (mPtcl) {
			if (mPtcl->checkActive()) {
				Vector3f pos(mPtcl->getGPos());
				zen::zenListManager& mdlMgr = mPtcl->getPtclMdlListManager();

				// these should be zenListManager inlines but that breaks stack. Maybe fix later.
				zen::zenList* listStart = mdlMgr._00;
				zen::zenList* list      = listStart->mNext;
				while (list != listStart) {
					zen::zenList* next = list->mNext;
					f32 mdlY           = static_cast<zen::particleMdlBase*>(list)->_0C.y + static_cast<zen::particleMdlBase*>(list)->_18.y;
					if (mdlY > pos.y) {
						pos.y = mdlY;
					}
					list = next;
				}
				ptcl->setEmitPos(pos);

			} else {
				mPtcl = nullptr;
			}
		}

		return true;
	}

	void set(zen::particleGenerator* ptcl) { mPtcl = ptcl; }

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	zen::particleGenerator* mPtcl; // _04
};

/**
 * @brief TODO.
 *
 * @note Size: 0x14.
 */
struct MizuAi : public PaniAnimKeyListener {
	MizuAi(Mizu*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void initMizu(Mizu*);
	void initGeyzer(Mizu*);
	void killCallBackEffect(bool);
	void initWait(int);
	void initReady(int);
	void initJet(int);
	void update();

	// unused/inlined:
	void setEveryFrame();
	void naviGeyzerJump();
	bool readyTransit();
	bool jetTransit();
	bool waitTransit();
	void waitState();
	void readyState();
	void jetState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	Mizu* mMizu;                              // _04
	zen::particleGenerator* _08;              // _08
	zen::particleGenerator* _0C;              // _0C
	MizuGenSpringPuffCallBack* mPuffCallBack; // _10
};

#endif
