#ifndef _STREAM_H
#define _STREAM_H

/**
 * .obj __vt__6Stream, global
 * .4byte __RTTI__6Stream
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
 * .4byte read__6StreamFPvi
 * .4byte write__6StreamFPvi
 * .4byte getPending__6StreamFv
 * .4byte getAvailable__6StreamFv
 * .4byte close__6StreamFv
 * .4byte getClosing__6StreamFv
 * .4byte flush__6StreamFv
 */

/**
 * @brief TODO
 */
struct Stream {
	virtual void readInt();                // _08
	virtual void readByte();               // _0C
	virtual void readShort();              // _10
	virtual void readFloat();              // _14
	virtual void readString(char*, int);   // _18
	virtual void readString(String&);      // _1C
	virtual void readString();             // _20
	virtual void writeInt(int);            // _24
	virtual void writeByte(unsigned char); // _28
	virtual void writeShort(short);        // _2C
	virtual void writeFloat(float);        // _30
	virtual void writeString(char*);       // _34
	virtual void writeString(String&);     // _38
	virtual void read(void*, int);         // _3C
	virtual void write(void*, int);        // _40
	virtual void getPending();             // _44
	virtual void getAvailable();           // _48
	virtual void close();                  // _4C
	virtual void getClosing();             // _50 (weak)
	virtual void flush();                  // _54 (weak)
};

#endif
