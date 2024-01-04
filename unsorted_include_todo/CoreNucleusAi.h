#ifndef _CORENUCLEUSAI_H
#define _CORENUCLEUSAI_H

/**
 * .obj __vt__13CoreNucleusAi, global
 * .4byte __RTTI__13CoreNucleusAi
 * .4byte 0
 * .4byte animationKeyUpdated__13CoreNucleusAiFR16PaniAnimKeyEvent
 */

/**
 * @brief TODO
 */
struct CoreNucleusAi {
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	CoreNucleusAi(CoreNucleus*);
	void initAI(CoreNucleus*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void setHitMotionStart();
	void update();
};

#endif
