#ifndef _VIEWPIKI_H
#define _VIEWPIKI_H

#include "types.h"
#include "Piki.h"

struct Shape;
struct MapMgr;

/**
 * @brief TODO
 */
struct ViewPiki : public Piki {
	ViewPiki(CreatureProp*);

	virtual void update();                       // _E0
	virtual void postUpdate(int, f32);           // _E4
	virtual void refresh(Graphics&);             // _EC
	virtual void demoDraw(Graphics&, Matrix4f*); // _FC
	virtual bool isKinoko();                     // _120
	virtual void initBirth();                    // _128
	virtual void changeShape(int);               // _12C
	virtual void setFlower(int);                 // _130
	virtual void setLeaves(int);                 // _134

	void init(Shape*, MapMgr*, Navi*);

	// unused/inlined:
	void refresh2d(Graphics&, int);

	// _00      = VTBL
	// _00-_588 = Piki
	PikiShapeObject* mPikiShape; // _588
	Vector3f _58C;               // _58C
	Shape* mHappaModel;          // _598
};

#endif
