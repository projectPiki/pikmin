#ifndef _BUFFEREDINPUTSTREAM_H
#define _BUFFEREDINPUTSTREAM_H

/**
 * .obj __vt__19BufferedInputStream, global
 * .4byte __RTTI__19BufferedInputStream
 * .4byte 0
 * .4byte readInt__6StreamFv
 * .4byte readByte__6StreamFv
 * .4byte readShort__6StreamFv
 * .4byte readFloat__6StreamFv
 * .4byte readString__6StreamFPci
 * .4byte readString__6StreamFR6String
 * .4byte readString__6StreamFv
 * .4byte writeInt__6StreamFi
 * .4byte writeByte__6StreamFUc
 * .4byte writeShort__6StreamFs
 * .4byte writeFloat__6StreamFf
 * .4byte writeString__6StreamFPc
 * .4byte writeString__6StreamFR6String
 * .4byte read__19BufferedInputStreamFPvi
 * .4byte write__6StreamFPvi
 * .4byte getPending__19BufferedInputStreamFv
 * .4byte getAvailable__6StreamFv
 * .4byte close__19BufferedInputStreamFv
 * .4byte getClosing__6StreamFv
 * .4byte flush__6StreamFv
 * .4byte getPosition__19BufferedInputStreamFv
 * .4byte setPosition__18RandomAccessStreamFi
 * .4byte getLength__18RandomAccessStreamFv
*/

struct Stream {
	virtual void readInt();                // _08
	virtual void readByte();               // _0C
	virtual void readShort();              // _10
	virtual void readFloat();              // _14
	virtual void readString(char *, int);  // _18
	virtual void readString(String &);     // _1C
	virtual void readString();             // _20
	virtual void writeInt(int);            // _24
	virtual void writeByte(unsigned char); // _28
	virtual void writeShort(short);        // _2C
	virtual void writeFloat(float);        // _30
	virtual void writeString(char *);      // _34
	virtual void writeString(String &);    // _38
	virtual void read(void *, int);        // _3C
	virtual void write(void *, int);       // _40
	virtual void getPending();             // _44 (weak)
	virtual void getAvailable();           // _48
	virtual void close();                  // _4C (weak)
	virtual void getClosing();             // _50 (weak)
	virtual void flush();                  // _54 (weak)
};

struct RandomAccessStream {
	virtual void _08() = 0;          // _08
	virtual void _0C() = 0;          // _0C
	virtual void _10() = 0;          // _10
	virtual void _14() = 0;          // _14
	virtual void _18() = 0;          // _18
	virtual void _1C() = 0;          // _1C
	virtual void _20() = 0;          // _20
	virtual void _24() = 0;          // _24
	virtual void _28() = 0;          // _28
	virtual void _2C() = 0;          // _2C
	virtual void _30() = 0;          // _30
	virtual void _34() = 0;          // _34
	virtual void _38() = 0;          // _38
	virtual void read(void *, int);  // _3C
	virtual void _40() = 0;          // _40
	virtual void getPending();       // _44 (weak)
	virtual void _48() = 0;          // _48
	virtual void close();            // _4C (weak)
	virtual void _50() = 0;          // _50
	virtual void _54() = 0;          // _54
	virtual void getPosition();      // _58 (weak)
	virtual void setPosition(int);   // _5C (weak)
	virtual void getLength();        // _60 (weak)
};

/**
 * @brief TODO
 */
struct BufferedInputStream : public Stream, public RandomAccessStream {
	virtual void read(void *, int);  // _3C
	virtual void getPending();       // _44 (weak)
	virtual void close();            // _4C (weak)
	virtual void getPosition();      // _58 (weak)

};

#endif
