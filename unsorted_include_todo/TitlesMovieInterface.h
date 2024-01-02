#ifndef _TITLESMOVIEINTERFACE_H
#define _TITLESMOVIEINTERFACE_H

/**
 * .obj __vt__20TitlesMovieInterface, global
 * .4byte __RTTI__20TitlesMovieInterface
 * .4byte 0
 * .4byte message__20TitlesMovieInterfaceFii
 * .4byte movie__13GameInterfaceFiiP8CreatureP8Vector3fP8Vector3fUlb
 * .4byte parseMessages__13GameInterfaceFv
 * .4byte parse__13GameInterfaceFii
 */

struct GameInterface {
	virtual void message(int, int);                                           // _08
	virtual void movie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool); // _0C
	virtual void parseMessages();                                             // _10
	virtual void parse(int, int);                                             // _14
};

/**
 * @brief TODO
 */
struct TitlesMovieInterface : public GameInterface {
	virtual void message(int, int); // _08
};

#endif
