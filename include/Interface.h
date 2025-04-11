#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "types.h"

struct Creature;
struct Vector3f;
struct NewPikiGameSetupSection;

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
		int _00;
		int _04;
	};

	/**
	 * @brief TODO
	 */
	struct ComplexMessage {
		ComplexMessage();

		int _00;       // _00
		int _04;       // _04
		Creature* _08; // _08
		Vector3f _0C;  // _0C
		Vector3f _18;  // _18
		int _24;       // _24
		bool _28;      // _28
	};

	virtual void message(int, int);                                           // _08
	virtual void movie(int, int, Creature*, Vector3f*, Vector3f*, u32, bool); // _0C
	virtual void parseMessages();                                             // _10
	virtual void parse(SimpleMessage&);                                       // _18
	virtual void parse(ComplexMessage&);                                      // _1C

	// _00 = VTBL?
	// TODO: members?
	NewPikiGameSetupSection* mSection; //_04
	int _08;                           // _08
	SimpleMessage mMesg[32];           // _00
	int mMesgCount;                    // _10C
	ComplexMessage mCompMesg[32];      // _110
	int mComplexMesgCount;             //_690
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
