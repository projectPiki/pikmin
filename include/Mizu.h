#ifndef _MIZU_H
#define _MIZU_H

#include "Boss.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

struct MizuAi;

/**
 * @brief TODO.
 *
 * @note Size: 0x204.
 */
struct MizuProp : public BossProp, public CoreNode {
public:
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
		mCreatureProps.read(input);
		mBossProps.read(input);
		mMizuProps.read(input);
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
	friend struct MizuAi;

	friend struct MizuGenSpringPuffCallBack; // Not actually required, but other bosses do similar.

public:
	Mizu(CreatureProp*);

	virtual f32 getiMass();                         // _38
	virtual bool isVisible() { return mIsVisible; } // _74
	virtual void update();                          // _E0
	virtual void refresh(Graphics&);                // _EC
	virtual void doAI();                            // _104
	virtual void doAnimation();                     // _108
	virtual void doKill();                          // _10C
	virtual void exitCourse();                      // _110
	virtual bool attackDefaultPortion();            // _118
	virtual void drawShape(Graphics&);              // _120

	void initMizu(immut Vector3f&);
	void initGeyzer(immut Vector3f&);

private:
	// _00      = VTBL
	// _00-_3B8 = Boss
	bool _3B8;       // _3B8
	bool mIsVisible; // _3B9
	MizuAi* mMizuAi; // _3BC
};

/**
 * @brief TODO
 */
struct MizuGenSpringPuffCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		if (mPtcl) {
			if (mPtcl->checkActive()) {
				Vector3f pos(mPtcl->getGPos());
				zen::zenListManager& mdlMgr = mPtcl->getPtclMdlListManager();

				zen::zenList* listStart = mdlMgr.getOrigin();
				zen::zenList* list      = mdlMgr.getTopList();
				while (list != listStart) {
					zen::zenList* next        = list->mNext;
					zen::particleMdlBase* mdl = (zen::particleMdlBase*)list;
					f32 mdlY                  = mdl->mLocalPosition.y + mdl->mGlobalPosition.y;
					if (mdlY > pos.y) {
						pos.y = mdlY;
					}
					list = next;
				}
				ptclGen->setEmitPos(pos);

			} else {
				mPtcl = nullptr;
			}
		}

		return true;
	}

	void set(zen::particleGenerator* ptcl) { mPtcl = ptcl; }

private:
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
public:
	MizuAi(Mizu*);

	void initMizu(Mizu*);
	void initGeyzer(Mizu*);
	void killCallBackEffect(bool);
	void update();

private:
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _08

	void setEveryFrame();
	void naviGeyzerJump();
	bool readyTransit();
	bool jetTransit();
	bool waitTransit();
	void initWait(int);
	void initReady(int);
	void initJet(int);
	void waitState();
	void readyState();
	void jetState();

public:
	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	Mizu* mMizu;                              // _04
	zen::particleGenerator* _08;              // _08
	zen::particleGenerator* _0C;              // _0C
	MizuGenSpringPuffCallBack* mPuffCallBack; // _10
};

#endif
