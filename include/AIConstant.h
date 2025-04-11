#ifndef _AICONSTANT_H
#define _AICONSTANT_H

#include "types.h"
#include "Node.h"
#include "Parameters.h"
#include "Ayu.h"

/**
 * @brief A node that contains AI constants.
 *
 * @note Size: 0x194.
 */
struct AIConstant : public Node {

	/**
	 * @brief TODO
	 *
	 * @note Offset comments are relative to AIConstant for ease of use.
	 */
	struct Constants : public Parameters {
		inline Constants()
		    : mGravity(this, 550.0f, 0.0f, 0.0f, "p00", nullptr)
		    , _34(this, 1, 0, 0, "p01", nullptr)
		    , _44(this, 1, 0, 0, "p02", nullptr)
		    , _54(this, 0, 0, 0, "p03", nullptr)
		    , _64(this, 1, 0, 0, "p04", nullptr)
		    , mDoCStickAttack(this, 1, 0, 0, "p05", nullptr)
		    , _84(this, 1, 0, 0, "p07", nullptr)
		    , _94(this, 1, 0, 0, "p06", nullptr)
		    , _A4(this, 1, 0, 0, "p08", nullptr)
		    , _B4(this, 1, 0, 0, "p09", nullptr)
		    , _C4(this, 1, 0, 0, "p10", nullptr)
		    , mJumpTriangleAngleThreshold(this, 90.0f, 0.0f, 0.0f, "p11", nullptr)
		    , _E4(this, 1, 0, 0, "p12", nullptr)
		    , mDoPluckWithCursor(this, 1, 0, 0, "p13", nullptr)
		    , mDoScaleHappaMoveSpeed(this, 1, 0, 0, "p14", nullptr)
		    , mMaxPikisOnField(this, 100, 0, 0, "p15", nullptr)
		    , _124(this, 1, 0, 0, "p16", nullptr)
		    , mWeakSlipFactor(this, 1.0f, 0.0f, 0.0f, "p17", nullptr)
		    , mStrongSlipFactor(this, 2.5f, 0.0f, 0.0f, "p18", nullptr)
		    , _154(this, 6, 0, 0, "p19", nullptr)
		    , _164(this, 12, 0, 0, "p20", nullptr)
		    , _174(this, 29, 0, 0, "p21", nullptr)
		    , _184(this, 30, 0, 0, "p22", nullptr)
		{
		}

		// _20-_24 = Parameters
		Parm<f32> mGravity;                    // _24, p00
		Parm<int> _34;                         // _34, p01
		Parm<int> _44;                         // _44, p02
		Parm<int> _54;                         // _54, p03
		Parm<int> _64;                         // _64, p04
		Parm<int> mDoCStickAttack;             // _74, p05, will csticking pikis into enemies cause the pikis to attack?
		Parm<int> _84;                         // _84, p07
		Parm<int> _94;                         // _94, p06
		Parm<int> _A4;                         // _A4, p08
		Parm<int> _B4;                         // _B4, p09
		Parm<int> _C4;                         // _C4, p10, meeo: single attack only toggle?
		Parm<f32> mJumpTriangleAngleThreshold; // _D4, p11
		Parm<int> _E4;                         // _E4, p12, meeo: throw toggle (vs rolling pikis lol)?
		Parm<int> mDoPluckWithCursor;          // _F4, p13, i.e. pluckaphone toggle
		Parm<int> mDoScaleHappaMoveSpeed;      // _104, p14, bud and flower pikis walk faster than leaves
		Parm<int> mMaxPikisOnField;            // _114, p15, THE field limit (100 by default)
		Parm<int> _124;                        // _124, p16, meeo: drop bomb type (immediately vs whistled)?
		Parm<f32> mWeakSlipFactor;             // _134, p17
		Parm<f32> mStrongSlipFactor;           // _144, p18
		Parm<int> _154;                        // _154, p19, meeo: UFO level 2 (forest navel)?
		Parm<int> _164;                        // _164, p20, meeo: UFO level 3 (distant spring)?
		Parm<int> _174;                        // _174, p21, meeo: UFO level 4 (final trial)?
		Parm<int> _184;                        // _184, p22, meeo: UFO level 5 (NOT perfect ending trigger)?
	};

	AIConstant();

	virtual void read(RandomAccessStream& input) // _0C (weak)
	{
		mConstants.read(input);
	}

	static void createInstance();

	static AIConstant* _instance;

	// _00     = VTBL
	// _00-_20 = Node
	Constants mConstants; // _20
};

#endif
