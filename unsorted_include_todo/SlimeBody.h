#ifndef _SLIMEBODY_H
#define _SLIMEBODY_H

/*
 * @brief TODO
 */
struct SlimeBody {
	SlimeBody(Slime*);
	void init(Slime*);
	void sortPosition(Vector3f*, Vector3f*, Vector3f*);
	void update();
	void refresh(BossShapeObject*, Graphics&);
};

#endif
