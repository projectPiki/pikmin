#ifndef _CPLATE_H
#define _CPLATE_H

/**
 * .obj __vt__6CPlate, global
 * .4byte __RTTI__6CPlate
 * .4byte 0
 * .4byte getCreature__6CPlateFi
 * .4byte getFirst__6CPlateFv
 * .4byte getNext__6CPlateFi
 * .4byte isDone__6CPlateFi
 * .4byte __RTTI__6CPlate
 * .4byte 0xFFFFFFF8
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@8@read__6CPlateFR18RandomAccessStream"
 * .4byte "@8@update__6CPlateFv"
 * .4byte draw__4NodeFR8Graphics
 * .4byte "@8@render__6CPlateFR8Graphics"
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte read__6CPlateFR18RandomAccessStream
 * .4byte update__6CPlateFv
 * .4byte render__6CPlateFR8Graphics
*/

struct ANode {
	virtual void getCreature(int);  // _08
	virtual void getFirst();        // _0C
	virtual void getNext(int);      // _10
	virtual void isDone(int);       // _14
	virtual void _18() = 0;         // _18
	virtual void _1C() = 0;         // _1C
	virtual void getAgeNodeType();  // _20 (weak)
};

struct Node {
	virtual void getCreature(int);    // _08
	virtual void getFirst();          // _0C
	virtual void getNext(int);        // _10
	virtual void isDone(int);         // _14
	virtual void _18() = 0;           // _18
	virtual void _1C() = 0;           // _1C
	virtual void _20() = 0;           // _20
	virtual void _24() = 0;           // _24
	virtual void _28() = 0;           // _28
	virtual void draw(Graphics &);    // _2C
	virtual void _30() = 0;           // _30
	virtual void concat();            // _34 (weak)
	virtual void concat(VQS &);       // _38 (weak)
	virtual void concat(SRT &);       // _3C (weak)
	virtual void concat(Matrix4f &);  // _40 (weak)
	virtual void getModelMatrix();    // _44 (weak)
};

/**
 * @brief TODO
 */
struct CPlate : public ANode, public Node {
	virtual void getCreature(int);            // _08
	virtual void getFirst();                  // _0C
	virtual void getNext(int);                // _10
	virtual void isDone(int);                 // _14
	virtual void read(RandomAccessStream &);  // _48
	virtual void update();                    // _4C
	virtual void render(Graphics &);          // _50

};

#endif
