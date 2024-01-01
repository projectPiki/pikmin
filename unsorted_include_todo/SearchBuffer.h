#ifndef _SEARCHBUFFER_H
#define _SEARCHBUFFER_H

/**
 * .obj __vt__12SearchBuffer, global
 * .4byte __RTTI__12SearchBuffer
 * .4byte 0
 * .4byte getCreature__12SearchBufferFi
 * .4byte getFirst__12SearchBufferFv
 * .4byte getNext__12SearchBufferFi
 * .4byte isDone__12SearchBufferFi
*/

/**
 * @brief TODO
 */
struct SearchBuffer {
	virtual void getCreature(int);  // _08
	virtual void getFirst();        // _0C
	virtual void getNext(int);      // _10
	virtual void isDone(int);       // _14

};

#endif
