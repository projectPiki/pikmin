#ifndef _CREATURECOLLPART_H
#define _CREATURECOLLPART_H

#include "DynColl.h"
#include "types.h"

struct CollPart;

/**
 * @brief Dedicated collision for having individual joints of a creature's model interacting independently with the map, ground or other
 * platforms.
 *
 * @note Size: 0x148.
 */
struct CreatureCollPart : public DynCollShape {

	/// Constructs a part with no dedicated collision or owner.
	CreatureCollPart()
	    : DynCollShape(nullptr)
	{
		mJointIndex     = 0;
		mParentCreature = nullptr;
	}

	/**
	 * @brief Construct a part with its own dedicated collision model.
	 * @param model Collision model to use for this joint.
	 */
	CreatureCollPart(Shape* model)
	    : DynCollShape(model)
	{
		mJointIndex     = 0;
		mParentCreature = nullptr;
	}

	/// Overridden to be trivial, since the CreaturePlatMgr will update all parts' transformations together with the creature's animation.
	virtual void update() { } // _10 (weak)

	virtual void touchCallback(immut Plane&, immut Vector3f&, immut Vector3f&); // _38

	/// Overridden to be trivial, since the creature's model will handle drawing anything that should be visible.
	virtual void refresh(Graphics&) { } // _44 (weak)

	// _00      = VTBL
	// _00-_140 = DynCollShape
	Creature* mParentCreature; ///< _140, parent creature this is a part of.
	int mJointIndex;           ///< _144, joint index within parent creature's model.
};

/**
 * @brief Manager for an individual creature's independent collision parts.
 *
 * @note Size: 0x48.
 */
struct CreaturePlatMgr {

	/// Constructs a blank manager with no sub-parts.
	CreaturePlatMgr()
	    : mPartCount(0)
	{
	}

	void init(Creature*, MapMgr*, Shape*);
	void release();
	void update(Graphics&);

	Shape* mParentCreatureModel;      ///< _00, model of the parent creature this is managing platforms for.
	CreatureCollPart* mPlatParts[16]; ///< _04, platform collision for any joints that should act independently.
	int mPartCount;                   ///< _44, number of used/initialised platform collisions/joints in mPlatParts array.
};

#endif
