#ifndef _PELLETANIMATOR_H
#define _PELLETANIMATOR_H

#include "CoreNode.h"
#include "PaniAnimator.h"
#include "Parameters.h"
#include "String.h"
#include "types.h"

struct PaniAnimKeyListener;
struct PaniMotionInfo;
struct PaniMotionTable;
struct PelletShapeObject;

/**
 * @brief Enum for pellet types.
 *
 * These are used to determine how pellets are loaded and displayed in the game.
 */
enum PelletCreationType {
	PCT_Resident     = 0, ///< 0, AKA always create the pellet.
	PCT_LoadIfExists = 1, ///< 1, load if exists.
	PCT_LoadOnTeki   = 2, ///< 2, load on teki.
	PCT_LoadOnBoss   = 3, ///< 3, load on boss (isn't actually implemented lol, never creates)
};

/**
 * @brief TODO
 *
 * @note Size: 0x60.
 */
struct PelletAnimInfo : public Parameters, public CoreNode {
	PelletAnimInfo();

	PelletShapeObject* createShapeObject();
	void changeType(AgeServer&);
	void newShapeObject(AgeServer&);
	void removeSelf(AgeServer&);

	// _04     = VTBL 1
	// _58     = VTBL 2
	// _00-_04 = Parameters
	// _04-_18 = CoreNode
	ID32 mID;                 // _18
	int mCreationType;        // _24, uses the PCT_* enum
	int mTekiType;            // _28, uses the TekiTypes_* enum
	Parm<String> mFolderPath; // _2C
	Parm<String> mFileName;   // _40
	int mOverrideJoint;         // _54

	// why is this split like this.
	virtual void read(RandomAccessStream&); // _18
#ifdef WIN32
	virtual void write(RandomAccessStream&);
	virtual void genAge(AgeServer&);
#endif

	PelletShapeObject* mPelletShapeObject; // _5C
};

/**
 * @brief TODO
 */
struct PelletAnimator {
	PelletAnimator();

	void init(AnimContext*, AnimContext*, AnimMgr*, PaniMotionTable*);
	void finishMotion(immut PaniMotionInfo*, immut PaniMotionInfo*);
	void startMotion(immut PaniMotionInfo&, immut PaniMotionInfo&);
	void startMotion(immut PaniMotionInfo&);
	void updateAnimation(f32, f32);
	void updateContext();

	// unused/inlined:
	void startMotion(immut PaniMotionInfo*, immut PaniMotionInfo*);
	void finishMotion(immut PaniAnimKeyListener*);

	PaniPelletAnimator& getLowerAnimator() { return mLowerAnimator; }
	PaniPelletAnimator& getUpperAnimator() { return mUpperAnimator; }

	// DLL inlines:
	int getMainMotionIndex();

	PaniPelletAnimator mLowerAnimator; // _00
	PaniPelletAnimator mUpperAnimator; // _54
};

#endif
