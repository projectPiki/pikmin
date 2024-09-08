#ifndef _MOVIEPLAYER_H
#define _MOVIEPLAYER_H

#include "types.h"
#include "CoreNode.h"

struct Creature;
struct Graphics;
struct Vector3f;

/**
 * @brief TODO
 */
struct MovieInfo : public CoreNode {

	// unused/inlined:
	void update();
	void setCamera(Graphics&);
	void refresh(Graphics&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
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
	void setCamera(Graphics&);
	void addLights(Graphics&);
	void refresh(Graphics&);

	// unused/inlined:
	void findMovie(int);
	void translateIndex(int, int);
	void sndFrameMovie(MovieInfo*);
	void nextFrame();
	void backFrame();

	// TODO: members
};

#endif
