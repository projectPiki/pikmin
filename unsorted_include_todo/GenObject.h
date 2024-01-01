#ifndef _GENOBJECT_H
#define _GENOBJECT_H

/**
 * .obj __vt__9GenObject, global
 * .4byte __RTTI__9GenObject
 * .4byte 0
 * .4byte doWrite__7GenBaseFR18RandomAccessStream
 * .4byte ramSaveParameters__7GenBaseFR18RandomAccessStream
 * .4byte ramLoadParameters__7GenBaseFR18RandomAccessStream
 * .4byte doRead__7GenBaseFR18RandomAccessStream
 * .4byte update__7GenBaseFv
 * .4byte render__7GenBaseFR8Graphics
 * .4byte getLatestVersion__9GenObjectFv
 * .4byte updateUseList__9GenObjectFP9Generatori
 * .4byte init__9GenObjectFP9Generator
 * .4byte update__9GenObjectFP9Generator
 * .4byte render__9GenObjectFR8GraphicsP9Generator
 * .4byte 0
*/

struct GenBase {
	virtual void doWrite(RandomAccessStream &);            // _08
	virtual void ramSaveParameters(RandomAccessStream &);  // _0C
	virtual void ramLoadParameters(RandomAccessStream &);  // _10
	virtual void doRead(RandomAccessStream &);             // _14
	virtual void update();                                 // _18
	virtual void render(Graphics &);                       // _1C
};

/**
 * @brief TODO
 */
struct GenObject : public GenBase {
	virtual void getLatestVersion();               // _20
	virtual void updateUseList(Generator *, int);  // _24
	virtual void init(Generator *);                // _28
	virtual void update(Generator *);              // _2C
	virtual void render(Graphics &, Generator *);  // _30
	virtual void _34() = 0;                        // _34

};

#endif
