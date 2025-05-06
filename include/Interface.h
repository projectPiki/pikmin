#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "types.h"

struct Creature;
struct Vector3f;
struct NewPikiGameSetupSection;
struct TitleSetupSection;

/**
 * @brief TODO
 */
struct GameInterface {
	virtual void message(int, int) { }                                           // _08
	virtual void movie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool) { } // _0C
	virtual void parseMessages() { }                                             // _10
	virtual void parse(int, int) { }                                             // _14

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct GameMovieInterface : public GameInterface {
	GameMovieInterface(NewPikiGameSetupSection* section)
	{
		_08        = 32;
		mMesgCount = 0;
		mSection   = section;
	}

	/**
	 * @brief TODO
	 */
	struct SimpleMessage {
		int mCommand; // _00
		int _04;      // _04
	};

	/**
	 * @brief TODO
	 */
	struct ComplexMessage {
		ComplexMessage() { }

		int mMovieIdx;      // _00
		int _04;            // _04
		Creature* mTarget;  // _08
		Vector3f mPosition; // _0C
		Vector3f mRotation; // _18
		int mFlags;         // _24
		bool mIsPlaying;    // _28
	};

	virtual void message(int a1, int a2) // _08
	{
		if (mMesgCount >= _08) {
			return;
		}
		mMesg[mMesgCount].mCommand = a1;
		mMesg[mMesgCount]._04      = a2;

		mMesgCount++;
	}
	virtual void movie(int id, int a1, Creature* obj, Vector3f* pos, Vector3f* dir, u32 flags, bool a2) // _0C
	{
		if (mComplexMesgCount >= _08) {
			return;
		}
		mCompMesg[mComplexMesgCount].mMovieIdx = id;
		mCompMesg[mComplexMesgCount]._04       = a1;
		mCompMesg[mComplexMesgCount].mTarget   = obj;
		if (!pos) {
			mCompMesg[mComplexMesgCount].mPosition.set(0.0f, 0.0f, 0.0f);
		} else {
			mCompMesg[mComplexMesgCount].mPosition = *pos;
		}
		if (!dir) {
			mCompMesg[mComplexMesgCount].mRotation.set(0.0f, 0.0f, 0.0f);
		} else {
			mCompMesg[mComplexMesgCount].mRotation = *dir;
		}
		mCompMesg[mComplexMesgCount].mFlags     = flags;
		mCompMesg[mComplexMesgCount].mIsPlaying = a2;

		mComplexMesgCount++;
	}
	virtual void parseMessages();        // _10
	virtual void parse(SimpleMessage&);  // _18
	virtual void parse(ComplexMessage&); // _1C

	// _00 = VTBL
	NewPikiGameSetupSection* mSection; //_04
	int _08;                           // _08
	SimpleMessage mMesg[32];           // _0C
	int mMesgCount;                    // _10C
	ComplexMessage mCompMesg[32];      // _110
	int mComplexMesgCount;             // _690
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct TitlesMovieInterface : public GameInterface {
	TitlesMovieInterface(TitleSetupSection* section) { mSection = section; }

	virtual void message(int, int); // _08

	// _00 = VTBL
	TitleSetupSection* mSection; // _04
};

#endif
