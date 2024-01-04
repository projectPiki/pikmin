#ifndef _POMAI_H
#define _POMAI_H

/**
 * .obj __vt__5PomAi, global
 * .4byte __RTTI__5PomAi
 * .4byte 0
 * .4byte animationKeyUpdated__5PomAiFR16PaniAnimKeyEvent
 */

/**
 * @brief TODO
 */
struct PomAi {
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	PomAi(Pom*);
	void initAI(Pom*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void killCallBackEffect(bool);
	void collidePetal(Creature*);
	void setCollideSound(Creature*);
	void killStickPiki();
	void createPikiHead();
	void calcPetalStickers();
	void initWait(int);
	void initDischarge(int);
	void update();
};

#endif
