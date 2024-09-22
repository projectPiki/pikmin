#ifndef _AICONSTANT_H
#define _AICONSTANT_H

#include "types.h"
#include "Node.h"
#include "Parameters.h"
#include "Ayu.h"

/**
 * @brief TODO
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
		    : _24(this, 550.0f, 0.0f, 0.0f, "p00", nullptr)
		    , _34(this, 1, 0, 0, "p01", nullptr)
		    , _44(this, 1, 0, 0, "p02", nullptr)
		    , _54(this, 0, 0, 0, "p03", nullptr)
		    , _64(this, 1, 0, 0, "p04", nullptr)
		    , _74(this, 1, 0, 0, "p05", nullptr)
		    , _84(this, 1, 0, 0, "p07", nullptr)
		    , _94(this, 1, 0, 0, "p06", nullptr)
		    , _A4(this, 1, 0, 0, "p08", nullptr)
		    , _B4(this, 1, 0, 0, "p09", nullptr)
		    , _C4(this, 1, 0, 0, "p10", nullptr)
		    , _D4(this, 90.0f, 0.0f, 0.0f, "p11", nullptr)
		    , _E4(this, 1, 0, 0, "p12", nullptr)
		    , _F4(this, 1, 0, 0, "p13", nullptr)
		    , _104(this, 1, 0, 0, "p14", nullptr)
		    , _114(this, 100, 0, 0, "p15", nullptr)
		    , _124(this, 1, 0, 0, "p16", nullptr)
		    , _134(this, 1.0f, 0.0f, 0.0f, "p17", nullptr)
		    , _144(this, 2.5f, 0.0f, 0.0f, "p18", nullptr)
		    , _154(this, 6, 0, 0, "p19", nullptr)
		    , _164(this, 12, 0, 0, "p20", nullptr)
		    , _174(this, 29, 0, 0, "p21", nullptr)
		    , _184(this, 30, 0, 0, "p22", nullptr)
		{
		}

		// _20-_24 = Parameters
		Parm<f32> _24;  // _24, p00, meeo: gravity?
		Parm<int> _34;  // _34, p01
		Parm<int> _44;  // _44, p02
		Parm<int> _54;  // _54, p03
		Parm<int> _64;  // _64, p04
		Parm<int> _74;  // _74, p05, meeo: cstick aggression toggle?
		Parm<int> _84;  // _84, p07
		Parm<int> _94;  // _94, p06
		Parm<int> _A4;  // _A4, p08
		Parm<int> _B4;  // _B4, p09
		Parm<int> _C4;  // _C4, p10, meeo: single attack only toggle?
		Parm<f32> _D4;  // _D4, p11
		Parm<int> _E4;  // _E4, p12, meeo: throw toggle (vs rolling pikis lol)?
		Parm<int> _F4;  // _F4, p13, meeo: pluckaphone toggle?
		Parm<int> _104; // _104, p14, meeo: flower pikis walk fast toggle?
		Parm<int> _114; // _114, p15, meeo: pikmin in field limit?
		Parm<int> _124; // _124, p16, meeo: drop bomb type (immediately vs whistled)?
		Parm<f32> _134; // _134, p17
		Parm<f32> _144; // _144, p18
		Parm<int> _154; // _154, p19, meeo: UFO level 2 (forest navel)?
		Parm<int> _164; // _164, p20, meeo: UFO level 3 (distant spring)?
		Parm<int> _174; // _174, p21, meeo: UFO level 4 (final trial)?
		Parm<int> _184; // _174, p22, meeo: UFO level 5 (NOT perfect ending trigger)?
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
