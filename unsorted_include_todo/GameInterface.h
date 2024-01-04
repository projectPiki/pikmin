#ifndef _GAMEINTERFACE_H
#define _GAMEINTERFACE_H

/**
 * .obj __vt__13GameInterface, weak
 * .4byte __RTTI__13GameInterface
 * .4byte 0
 * .4byte message__13GameInterfaceFii
 * .4byte movie__13GameInterfaceFiiP8CreatureP8Vector3fP8Vector3fUlb
 * .4byte parseMessages__13GameInterfaceFv
 * .4byte parse__13GameInterfaceFii
 */

/**
 * @brief TODO
 */
struct GameInterface {
	virtual void message(int, int);                                                     // _08
	virtual void movie(int, int, Creature*, Vector3f*, Vector3f*, unsigned long, bool); // _0C
	virtual void parseMessages();                                                       // _10
	virtual void parse(int, int);                                                       // _14
};

#endif
