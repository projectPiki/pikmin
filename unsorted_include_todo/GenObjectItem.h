#ifndef _GENOBJECTITEM_H
#define _GENOBJECTITEM_H

/**
 * .obj __vt__13GenObjectItem, global
 * .4byte __RTTI__13GenObjectItem
 * .4byte 0
 * .4byte doWrite__13GenObjectItemFR18RandomAccessStream
 * .4byte ramSaveParameters__13GenObjectItemFR18RandomAccessStream
 * .4byte ramLoadParameters__13GenObjectItemFR18RandomAccessStream
 * .4byte doRead__13GenObjectItemFR18RandomAccessStream
 * .4byte update__7GenBaseFv
 * .4byte render__7GenBaseFR8Graphics
 * .4byte getLatestVersion__9GenObjectFv
 * .4byte updateUseList__13GenObjectItemFP9Generatori
 * .4byte init__9GenObjectFP9Generator
 * .4byte update__9GenObjectFP9Generator
 * .4byte render__9GenObjectFR8GraphicsP9Generator
 * .4byte birth__13GenObjectItemFR9BirthInfo
 */

struct GenBase {
	virtual void doWrite(RandomAccessStream&);           // _08
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void doRead(RandomAccessStream&);            // _14
	virtual void update();                               // _18
	virtual void render(Graphics&);                      // _1C
};

struct GenObject {
	virtual void doWrite(RandomAccessStream&);           // _08
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void doRead(RandomAccessStream&);            // _14
	virtual void _18() = 0;                              // _18
	virtual void _1C() = 0;                              // _1C
	virtual void getLatestVersion();                     // _20
	virtual void updateUseList(Generator*, int);         // _24
	virtual void init(Generator*);                       // _28
	virtual void update(Generator*);                     // _2C
	virtual void render(Graphics&, Generator*);          // _30
};

/**
 * @brief TODO
 */
struct GenObjectItem : public GenBase, public GenObject {
	virtual void doWrite(RandomAccessStream&);           // _08
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void doRead(RandomAccessStream&);            // _14
	virtual void updateUseList(Generator*, int);         // _24
	virtual void birth(BirthInfo&);                      // _34
};

#endif
