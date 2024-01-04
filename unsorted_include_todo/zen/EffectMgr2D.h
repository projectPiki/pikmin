#ifndef _ZEN_EFFECTMGR2D_H
#define _ZEN_EFFECTMGR2D_H

/*
 * @brief TODO
 */
namespace zen {
struct EffectMgr2D {
	EffectMgr2D(int, int, int);
	void create(unsigned long, Vector3f&, zen::CallBack1<zen::particleGenerator*>*,
	            zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*);
	void update();
	void draw(Graphics&);
	void killAll(bool);
};
} // namespace zen

#endif
