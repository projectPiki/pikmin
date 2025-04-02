#ifndef _MOVIEPLAYER_H
#define _MOVIEPLAYER_H

#include "types.h"
#include "CoreNode.h"
#include "CinematicPlayer.h"

struct Creature;
struct Graphics;
struct Vector3f;

/**
 * @brief TODO
 */
struct MovieListInfo {
	// TODO: this - only returned by MoviePlayer::findMovie, sigh
};

/**
 * @brief TODO
 */
struct MovieInfo : public CoreNode {
	MovieInfo()
	    : CoreNode("")
	{
		mCin = nullptr;
	}

	// unused/inlined:
	bool update();
	bool setCamera(Graphics&);
	void refresh(Graphics&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 mMovieIndex;       // _14
	CinematicPlayer* mCin; // _18
	u8 _1C[0x44];          // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x174.
 */
struct MoviePlayer {
	MoviePlayer();

	void resetMovieList();
	void fixMovieList();
	void initMovie(MovieInfo*, int);
	void startMovie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool);
	void sndStartMovie(MovieInfo*);
	void initMovieFlags(MovieInfo*);
	void sndStopMovie(MovieInfo*);
	void update();
	void skipScene(int);
	void getLookAtPos(Vector3f&);
	bool setCamera(Graphics&);
	void addLights(Graphics&);
	void refresh(Graphics&);

	// unused/inlined:
	MovieListInfo* findMovie(int);
	int translateIndex(int, int);
	void sndFrameMovie(MovieInfo*);
	void nextFrame();
	void backFrame();

	void setGameCamInfo(bool flag, f32 a1, Vector3f& a2, Vector3f& a3)
	{
		_16C = flag;
		_160 = a1;
		_148 = a2;
		_154 = a3;
	}

	MovieInfo mInfoRoot;  // _00
	MovieInfo mInfoRoot2; // _60
	MovieInfo mInfoRoot3; // _C0
	int mCurrentFrame;    // _120
	u8 mIsActive;         // _124
	u8 _125;              // _125
	f32 _128;             // _128
	Vector3f _12C;        // _12C
	Vector3f mLookAtPos;  // _138
	f32 _144;             // _144
	Vector3f _148;        // _148
	Vector3f _154;        // _154
	f32 _160;             // _160
	f32 _164;             // _164
	f32 _168;             // _168
	bool _16C;            // _16C
};

#endif
