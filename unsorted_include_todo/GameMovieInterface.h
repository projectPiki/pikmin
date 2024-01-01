#ifndef _GAMEMOVIEINTERFACE_H
#define _GAMEMOVIEINTERFACE_H

/**
 * .obj __vt__18GameMovieInterface, global
 * .4byte __RTTI__18GameMovieInterface
 * .4byte 0
 * .4byte message__18GameMovieInterfaceFii
 * .4byte movie__18GameMovieInterfaceFiiP8CreatureP8Vector3fP8Vector3fUlb
 * .4byte parseMessages__18GameMovieInterfaceFv
 * .4byte parse__13GameInterfaceFii
 * .4byte parse__18GameMovieInterfaceFRQ218GameMovieInterface13SimpleMessage
 * .4byte parse__18GameMovieInterfaceFRQ218GameMovieInterface14ComplexMessage
*/

struct GameInterface {
	virtual void message(int, int);                                                         // _08
	virtual void movie(int, int, Creature *, Vector3f *, Vector3f *, unsigned long, bool);  // _0C
	virtual void parseMessages();                                                           // _10
	virtual void parse(int, int);                                                           // _14
};

/**
 * @brief TODO
 */
struct GameMovieInterface : public GameInterface {
	virtual void message(int, int);                                                         // _08
	virtual void movie(int, int, Creature *, Vector3f *, Vector3f *, unsigned long, bool);  // _0C
	virtual void parseMessages();                                                           // _10
	virtual void parse(SimpleMessage &);                                                    // _18
	virtual void parse(ComplexMessage &);                                                   // _1C

};

#endif
