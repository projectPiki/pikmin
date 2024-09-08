#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "types.h"

struct Creature;
struct Vector3f;

/**
 * @brief TODO
 */
struct GameInterface {
	virtual void message(int, int);                                           // _08
	virtual void movie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool); // _0C
	virtual void parseMessages();                                             // _10
	virtual void parse(int, int);                                             // _14

	// _00 = VTBL?
	// TODO: members?
};

/**
 * @brief TODO
 */
struct GameMovieInterface : public GameInterface {

	/**
	 * @brief TODO
	 */
	struct SimpleMessage {
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	struct ComplexMessage {
		ComplexMessage();

		// TODO: members
	};

	virtual void message(int, int);                                           // _08
	virtual void movie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool); // _0C
	virtual void parseMessages();                                             // _10
	virtual void parse(SimpleMessage&);                                       // _18
	virtual void parse(ComplexMessage&);                                      // _1C

	// _00 = VTBL?
	// TODO: members?
};

/**
 * @brief TODO
 */
struct TitlesMovieInterface : public GameInterface {
	virtual void message(int, int); // _08

	// _00 = VTBL?
	// TODO: members?
};

#endif
