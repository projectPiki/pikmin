#ifndef _GENOBJECTACTOR_H
#define _GENOBJECTACTOR_H

/**
 * .obj __vt__14GenObjectActor, global
 * .4byte __RTTI__14GenObjectActor
 * .4byte 0
 * .4byte doWrite__7GenBaseFR18RandomAccessStream
 * .4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
 * .4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
 * .4byte doRead__14GenObjectActorFR18RandomAccessStream
 * .4byte update__7GenBaseFv
 * .4byte render__7GenBaseFR8Graphics
 * .4byte getLatestVersion__9GenObjectFv
 * .4byte updateUseList__9GenObjectFP9Generatori
 * .4byte init__9GenObjectFP9Generator
 * .4byte update__9GenObjectFP9Generator
 * .4byte render__9GenObjectFR8GraphicsP9Generator
 * .4byte birth__14GenObjectActorFR9BirthInfo
*/

struct GenBase {
	virtual void doWrite(RandomAccessStream &);            // _08
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void doRead(RandomAccessStream &);             // _14
	virtual void update();                                 // _18
	virtual void render(Graphics &);                       // _1C
};

struct GenObject {
	virtual void _08() = 0;                        // _08
	virtual void _0C() = 0;                        // _0C
	virtual void _10() = 0;                        // _10
	virtual void doRead(RandomAccessStream &);     // _14
	virtual void _18() = 0;                        // _18
	virtual void _1C() = 0;                        // _1C
	virtual void getLatestVersion();               // _20
	virtual void updateUseList(Generator *, int);  // _24
	virtual void init(Generator *);                // _28
	virtual void update(Generator *);              // _2C
	virtual void render(Graphics &, Generator *);  // _30
};

/**
 * @brief TODO
 */
struct GenObjectActor : public GenBase, public GenObject {
	virtual void doRead(RandomAccessStream &);  // _14
	virtual void birth(BirthInfo &);            // _34

};

#endif
