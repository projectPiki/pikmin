#ifndef _MIZU_H
#define _MIZU_H

#include "types.h"
#include "Boss.h"
#include "zen/Callback.h"
#include "zen/Particle.h"

/**
 * @brief TODO.
 */
struct MizuProp : public BossProp, public CoreNode {

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to MizuProp for ease of use.
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
 */
struct Mizu : public Boss {
	Mizu(CreatureProp*);

	virtual f32 getiMass();              // _38
	virtual bool isVisible();            // _74
	virtual void update();               // _E0
	virtual void refresh(Graphics&);     // _EC
	virtual void doAI();                 // _104
	virtual void doAnimation();          // _108
	virtual void doKill();               // _10C
	virtual void exitCourse();           // _110
	virtual bool attackDefaultPortion(); // _118
	virtual void drawShape(Graphics&);   // _120

	void initMizu(Vector3f&);
	void initGeyzer(Vector3f&);

	inline MizuProp* getMizuProp() { return static_cast<MizuProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss?
	// TODO: members
};

/**
 * @brief TODO.
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
	void readyTransit();
	void jetTransit();
	void waitTransit();
	void waitState();
	void readyState();
	void jetState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct MizuGenSpringPuffCallBack : public zen::CallBack1<zen::particleGenerator*> {
	MizuGenSpringPuffCallBack();

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

#endif
