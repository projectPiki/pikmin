#ifndef _WEEDSITEM_H
#define _WEEDSITEM_H

#include "types.h"
#include "ItemMgr.h"

/*
 * @brief TODO
 */
struct Grass {
	Grass();

	// TODO: members
};

/*
 * @brief TODO
 */
struct Pebble {
	Pebble();

	// TODO: members
};

/*
 * @brief TODO
 */
struct GrassGen : public ItemCreature {
	GrassGen(Shape*, CreatureProp*);

	virtual void startAI(int);         // _34
	virtual f32 getSize();             // _3C
	virtual bool isVisible();          // _74
	virtual bool isAlive();            // _88
	virtual bool needFlick(Creature*); // _94
	virtual void update();             // _E0
	virtual void refresh(Graphics&);   // _EC

	void workable();
	void startWork();
	void finishWork();
	void resolve();
	void create(int, f32, int);
	void setSizeAndNum(f32, int);
	void getRandomGrass();

	// _00      = VTBL
	// _00-_304 = ItemCreature?
	// TODO: members
};

/*
 * @brief TODO
 */
struct RockGen : public ItemCreature {
	RockGen(Shape*, CreatureProp*);

	virtual void startAI(int);                // _34
	virtual f32 getSize();                    // _3C
	virtual void doSave(RandomAccessStream&); // _50
	virtual void doLoad(RandomAccessStream&); // _54
	virtual bool isVisible();                 // _74
	virtual bool isAlive();                   // _88
	virtual bool needFlick(Creature*);        // _94
	virtual void update();                    // _E0
	virtual void refresh(Graphics&);          // _EC

	void workable();
	void startWork();
	void finishWork();
	void resolve();
	void create(int, f32, int);
	void setSizeAndNum(f32, int);
	void killPebble();
	Pebble* getRandomPebble();

	// _00      = VTBL
	// _00-_304 = ItemCreature?
	// TODO: members
};

/*
 * @brief TODO
 */
struct WeedsGen : public ItemCreature {
	WeedsGen(Shape*, CreatureProp*);

	virtual void startAI(int);       // _34
	virtual void update();           // _E0
	virtual void refresh(Graphics&); // _EC

	// _00      = VTBL
	// _00-_304 = ItemCreature?
	// TODO: members
};

/*
 * @brief TODO
 */
struct Weed : public ItemCreature {
	Weed();

	virtual void startAI(int);         // _34
	virtual bool isVisible();          // _74
	virtual bool isAtari();            // _84
	virtual bool isAlive();            // _88
	virtual bool needFlick(Creature*); // _94
	virtual void update();             // _E0
	virtual void refresh(Graphics&);   // _EC

	void interactPullout(Creature*);

	// _00      = VTBL
	// _00-_304 = ItemCreature?
	// TODO: members
};

#endif
