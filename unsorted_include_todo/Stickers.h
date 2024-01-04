#ifndef _STICKERS_H
#define _STICKERS_H

/**
 * .obj __vt__8Stickers, global
 * .4byte __RTTI__8Stickers
 * .4byte 0
 * .4byte getCreature__8StickersFi
 * .4byte getFirst__8StickersFv
 * .4byte getNext__8StickersFi
 * .4byte isDone__8StickersFi
 */

/**
 * @brief TODO
 */
struct Stickers {
	virtual void getCreature(int); // _08
	virtual void getFirst();       // _0C
	virtual void getNext(int);     // _10
	virtual void isDone(int);      // _14
};

#endif
