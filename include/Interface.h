#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "types.h"

struct Creature;
struct Vector3f;
struct NewPikiGameSetupSection;
struct TitleSetupSection;

/**
 * @brief Game movie interface message commands.
 */
enum GameMovieCommand {
	MOVIECMD_StartTutorial     = 0,  // Start tutorial window based on context
	MOVIECMD_Unused            = 1,  // Unused/error command
	MOVIECMD_ForceDayEnd       = 2,  // Force day to end
	MOVIECMD_HideHUD           = 3,  // Hide game HUD frames
	MOVIECMD_ShowHUD           = 4,  // Show game HUD frames
	MOVIECMD_GameEndCondition  = 5,  // Handle extinction or Olimar down
	MOVIECMD_ForceResults      = 6,  // Force results screen
	MOVIECMD_StartMovie        = 7,  // Start movie with navi visibility control
	MOVIECMD_EndMovie          = 8,  // End current movie
	MOVIECMD_FadeOut           = 9,  // Fade screen to black
	MOVIECMD_FadeIn            = 10, // Fade screen from black
	MOVIECMD_CleanupDayEnd     = 11, // Clean up day end state
	MOVIECMD_StartTotalResults = 12, // Start final score screen
	MOVIECMD_SpecialDayEnd     = 13, // Special day end trigger
	MOVIECMD_SetInputEnabled   = 14, // Enable/disable gameplay input
	// 15 is missing
	MOVIECMD_StageFinish        = 16, // Challenge mode stage complete
	MOVIECMD_CreateSettingsMenu = 17, // Create settings menu
};

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
		mMessageLimit = 32;
		mMessageCount = 0;
		mSection      = section;
	}

	/**
	 * @brief TODO
	 */
	struct SimpleMessage {
		int mMessageId; // _00
		int mData;      // _04
	};

	/**
	 * @brief TODO
	 */
	struct ComplexMessage {
		ComplexMessage() { }

		int mMovieIdx;      // _00
		int _UNUSED04;      // _04
		Creature* mTarget;  // _08
		Vector3f mPosition; // _0C
		Vector3f mRotation; // _18
		int mFlags;         // _24
		bool mIsPlaying;    // _28
	};

	virtual void message(int msgId, int data) // _08
	{
		if (mMessageCount >= mMessageLimit) {
			return;
		}

		mMesg[mMessageCount].mMessageId = msgId;
		mMesg[mMessageCount].mData      = data;

		mMessageCount++;
	}
	virtual void movie(int id, int a1, Creature* obj, Vector3f* pos, Vector3f* dir, u32 flags, bool a2) // _0C
	{
		if (mComplexMesgCount >= mMessageLimit) {
			return;
		}
		mCompMesg[mComplexMesgCount].mMovieIdx = id;
		mCompMesg[mComplexMesgCount]._UNUSED04 = a1;
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
	int mMessageLimit;                 // _08
	SimpleMessage mMesg[32];           // _0C
	int mMessageCount;                 // _10C
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
