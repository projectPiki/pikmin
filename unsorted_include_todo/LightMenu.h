#ifndef _LIGHTMENU_H
#define _LIGHTMENU_H

/**
 * .obj __vt__9LightMenu, weak
 * .4byte __RTTI__9LightMenu
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte update__4NodeFv
 * .4byte draw__4NodeFR8Graphics
 * .4byte render__4NodeFR8Graphics
 * .4byte concat__4NodeFv
 * .4byte concat__4NodeFR3VQS
 * .4byte concat__4NodeFR3SRT
 * .4byte concat__4NodeFR8Matrix4f
 * .4byte getModelMatrix__4NodeFv
 * .4byte checkSelectKey__4MenuFv
 * .4byte checkCancelKey__4MenuFv
 * .4byte checkNewOption__4MenuFv
 * .4byte enterOption__4MenuFv
 * .4byte enterMenu__4MenuFP4Menu
 * .4byte exitMenu__4MenuFP4Menu
 * .4byte open__4MenuFb
 * .4byte close__4MenuFv
 * .4byte doUpdate__4MenuFb
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

struct Node {
	virtual void _08() = 0;           // _08
	virtual void _0C() = 0;           // _0C
	virtual void update();            // _10
	virtual void draw(Graphics &);    // _14
	virtual void render(Graphics &);  // _18
	virtual void concat();            // _1C (weak)
	virtual void concat(VQS &);       // _20 (weak)
	virtual void concat(SRT &);       // _24 (weak)
	virtual void concat(Matrix4f &);  // _28 (weak)
	virtual void getModelMatrix();    // _2C (weak)
};

struct Menu {
	virtual void _08() = 0;         // _08
	virtual void _0C() = 0;         // _0C
	virtual void _10() = 0;         // _10
	virtual void _14() = 0;         // _14
	virtual void _18() = 0;         // _18
	virtual void _1C() = 0;         // _1C
	virtual void _20() = 0;         // _20
	virtual void _24() = 0;         // _24
	virtual void _28() = 0;         // _28
	virtual void _2C() = 0;         // _2C
	virtual void checkSelectKey();  // _30
	virtual void checkCancelKey();  // _34
	virtual void checkNewOption();  // _38
	virtual void enterOption();     // _3C
	virtual void enterMenu(Menu *); // _40
	virtual void exitMenu(Menu *);  // _44
	virtual void open(bool);        // _48
	virtual void close();           // _4C
	virtual void doUpdate(bool);    // _50
};

/**
 * @brief TODO
 */
struct LightMenu : public ANode, public CoreNode, public Node, public Menu {

};

#endif
