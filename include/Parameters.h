#ifndef _PARAMETERS_H
#define _PARAMETERS_H

#include "types.h"

struct AgeServer;
struct Parameters;
struct RandomAccessStream;

/**
 * @brief Wrapper class for packing and unpacking fourcc-style identifiers.
 *
 * IDs are stored as s32s, with helper functions for setting it from a string.
 *
 * @warning This allows for 4-byte character constants, but parameter reading/writing assumes this will be packed into 3 bytes.
 * Any strings provided should only be 3 characters to ensure no data loss.
 * @note Size: 0x4.
 */
struct ayuID {

	/// Constructs a blank ID.
	ayuID() { mID = 0; }

	/**
	 * @brief Construct a new ID from an input string.
	 * @param id String to convert to a fourcc ID.
	 */
	ayuID(immut char* id) { Set(id); }

	/**
	 * @brief Converts a string to a fourcc ID and sets it as the ID.
	 * @param id String ID to convert and store.
	 */
	void Set(immut char* id) { mID = *(s32*)id; }

	/**
	 * @brief Gets the fourcc ID.
	 * @return A reference to the packed integer ID.
	 */
	s32& Num() { return mID; };

	s32 mID; // _00, fourcc-style (32-bit) packed identifier.
};

/**
 * @brief Abstract base class for individual parameters to be read from file.
 *
 * Implemented in a singly-linked list, with serialisation support.
 *
 * @note Size: 0xC.
 */
struct BaseParm {
	BaseParm(Parameters*, ayuID);

	// _08    = VTBL
	ayuID mID;       ///< _00, fourcc-style identifier for the parameter.
	BaseParm* mNext; ///< _04, next parameter in the (singly-linked) list.

	virtual int size() = 0; // _08
#ifdef WIN32
	virtual void genAge(AgeServer&) { }
#endif

	/**
	 * @brief Writes parameter to file stream - trivial in base class.
	 * @param output File stream to write to - unused in base class.
	 */
	virtual void write(RandomAccessStream& output) { } // _0C

	/**
	 * @brief Reads parameter from file stream - trivial in base class.
	 * @param input File stream to read from - unused in base class.
	 */
	virtual void read(RandomAccessStream& input) { } // _10
};

/**
 * @brief Container for a singly-linked list of `BaseParm` parameters, representing a block from a parameter file.
 *
 * @note Constructor and members differ slightly between the DLL and DOL - the name is removed in the DOL.
 * @note Size: 0x4 (0x8 in DLL).
 */
struct Parameters {

#ifdef WIN32
	/**
	 * @brief Constructs an empty (named) parameters list (DLL only).
	 * @param name Name for this collection of parameters.
	 */
	Parameters(immut char* name)
	    : mFirstParm(nullptr)
	{
		mName = name;
	}
#else
	/// Constructs an empty parameters list (DOL only).
	Parameters()
	    : mFirstParm(nullptr)
	{
	}
#endif

	void write(RandomAccessStream&);
	void read(RandomAccessStream&);

#ifdef WIN32
	void genAge(AgeServer&, int);
	void genAgeParms(AgeServer&, int);
#endif

	// unused/inlined:

	int sizeInFile();

#ifdef WIN32
	immut char* mName;    ///< _00, name for this collection of parameters.
#endif                    //
	BaseParm* mFirstParm; ///< _00, pointer to first parameter node in the list.
};

/**
 * @brief TODO
 *
 * @note Size: 0xC + sizeof(T) (so usually 0x10).
 */
template <typename T>
struct Parm : public BaseParm {
	Parm(Parameters* owner, T value, T min, T max, ayuID id, immut char* name)
	    : BaseParm(owner, id)
	{
		mValue = value;
#ifdef WIN32
		mDefaultValue = value;
		mMinValue     = min;
		mMaxValue     = max;
		mName         = name;
#endif
	}

	virtual int size() { return sizeof(T); } // _08
	virtual void write(RandomAccessStream&); // _0C
	virtual void read(RandomAccessStream&);  // _10

	T& operator()() { return mValue; }
	void operator()(T val) { mValue = val; }

#ifdef WIN32
	virtual void genAge(AgeServer&);
#endif

	// _08     = VTBL
	// _00-_0C = BaseParm
	T mValue;          // _0C
#ifdef WIN32           //
	T mDefaultValue;   // _10
	T mMinValue;       // _14
	T mMaxValue;       // _18
	immut char* mName; // _1C
#endif
};

// For some reason, giving `CreatureProp::Parms` its parameter strings messes up matching.
#define MATCHING_PARM_NAME(name) TERNARY_BUILD_MATCHING(nullptr, name)

#endif
