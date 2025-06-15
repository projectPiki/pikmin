#ifndef _AGE_H
#define _AGE_H

#include "types.h"
#include "AtxStream.h"
#include "String.h"
#include "Delegate.h"
#include "ANode.h"
#include "stl/string.h"

enum PROP_TYPE {
	CHAR_PROP = 0,
	SHORT_PROP,    // 1
	INT_PROP,      // 2
	FLOAT_PROP,    // 3
	COLOUR_PROP,   // 4
	IMAGE_PROP,    // 5
	STRING_PROP,   // 6
	UNK7,          // 7
	CHAR_PTR_PROP, // 8
	UNK9           // 9
};

struct Colour;

struct AgeServer : public AtxStream {
	AgeServer() { }

// TODO: All of this should be moved to a dedicated ageServer.cpp, I just don't want to yet because of the hacky way you have to add it in
// configure.py
// Note that all of these functions work by sending a specific command id to the server, plugAtxServer.dll has the important stuff
#ifdef DEVELOP
	void Done() { writeInt(200); }

	void EndBitGroup() { writeInt(0); }

	void EndGroup() { writeInt(303); }

	void EndNode() { writeInt(200); }

	void EndOptionBox() { writeInt(0); }

	void EndSection()
	{
		writeInt(301);
		mIsActive = false;
	}

	void NewBit(char* name, u32 a1, u32 a2)
	{
		writeInt(1);
		writeString(name);
		writeInt(a1);
		writeInt(a2);
	}

	void NewButton(char* name, IDelegate* cmd, int a)
	{
		writeInt(302);
		writeString(name);
		writeInt(a);
		writeInt(0);
		writeInt((int)cmd);
	}

	void NewButton(char* name, IDelegate1<AgeServer&>* cmd, int a)
	{
		writeInt(302);
		writeString(name);
		writeInt(a);
		writeInt(1);
		writeInt((int)cmd);
	}

	void NewEditor(char* name, class AyuImage* img, bool a)
	{
		writeInt(102);
		writeString(name);
		if (a) {
			writeProp(IMAGE_PROP, img);
		} else {
			writeProp(STRING_PROP, img);
		}
	}

	void NewEditor(char* name, Colour* col)
	{
		writeInt(102);
		writeString(name);
		writeProp(COLOUR_PROP, col);
	}

	void NewEditor(char* name, char* val, int a)
	{
		writeInt(102);
		writeString(name);
		writeProp(CHAR_PTR_PROP, val);
		writeInt(a - 1);
	}

	void NewEditor(char* name, char* val, int min, int max, int step)
	{
		writeInt(102);
		writeString(name);
		writeProp(CHAR_PROP, val);
		writeInt(1);
		writeFloat(min);
		writeFloat(max);
		writeInt(step);
	}

	void NewEditor(char* name, f32* val, f32 min, f32 max, int step)
	{
		writeInt(102);
		writeString(name);
		writeProp(FLOAT_PROP, val);
		writeFloat(min);
		writeFloat(max);
		writeInt(step);
	}

	void NewEditor(char* name, int* val, int min, int max, int step)
	{
		writeInt(102);
		writeString(name);
		writeProp(INT_PROP, val);
		writeFloat(min);
		writeFloat(max);
		writeInt(step);
	}

	void NewEditor(char* name, short* val, int min, int max, int step)
	{
		writeInt(102);
		writeString(name);
		writeProp(SHORT_PROP, val);
		writeFloat(min);
		writeFloat(max);
		writeInt(step);
	}

	void NewLabel(char* lbl)
	{
		writeInt(108);
		writeString(lbl);
	}

	void NewNode(char* name, ANode* node)
	{
		writeInt(101);
		writeInt((int)node);
		writeString(name);
		writeInt(node->getAgeNodeType());
	}

	void NewNodeWindow(char* name)
	{
		writeInt(100);
		writeString(name);
	}

	void NewOption(char* name, int a)
	{
		writeInt(1);
		writeString(name);
		writeInt(a);
	}

	void NewPropWindow(char* name, u32 a)
	{
		writeInt(104);
		writeString(name);
		writeInt(a);
	}

	void NewViewer(char* name, f32* val)
	{
		writeInt(107);
		writeString(name);
		writeProp(FLOAT_PROP, val);
	}

	void NewViewer(char* name, int* val)
	{
		writeInt(107);
		writeString(name);
		writeProp(INT_PROP, val);
	}

	bool Open()
	{
		//PRINT("!!!!! Opening Age server\n");
		if (AtxStream::open("age", 3)) {
			mIsActive = false;
			return true;
		}

		//ERROR("cant open AgeServer\n");
		return false;
	}

	void RefreshNode() { writeInt(402); }

	void RefreshSection() { writeInt(403); }

	void StartBitGroup(char* name, u32* val, int a)
	{
		writeInt(102);
		writeString(name);
		writeProp(UNK7, nullptr);
		writeProp(INT_PROP, val);
		writeInt(a);
	}

	void StartBitGroup(char* name, u8* val, int a)
	{
		writeInt(102);
		writeString(name);
		writeProp(UNK7, nullptr);
		writeProp(CHAR_PROP, val);
		writeInt(a);
	}

	void StartGroup(char* name)
	{
		writeInt(302);
		writeString(name);
	}

	void StartOptionBox(char* name, int* val, int a)
	{
		writeInt(102);
		writeString(name);
		//PRINT("new optionbox : %08x\n", val);
		writeProp(UNK9, nullptr);
		writeProp(INT_PROP, val);
		writeInt(a);
	}

	void StartOptionBox(char* name, u16* val, int a)
	{
		writeInt(102);
		writeString(name);
		writeProp(UNK9, nullptr);
		writeProp(SHORT_PROP, val);
		writeInt(a);
	}

	void StartOptionBox(char* name, u8* val, int a)
	{
		writeInt(102);
		writeString(name);
		writeProp(UNK9, nullptr);
		writeProp(CHAR_PROP, val);
		writeInt(a);
	}

	void StartSection(char* name, bool unk)
	{
		writeInt(300);
		writeInt(unk);
		writeString(name);
	}

	virtual void close() { AtxStream::close(); }

	bool getOpenFilename(String& path, char* option)
	{
		writeInt(404);
		if (option) {
			//PRINT("filter length = %d\n", strlen(option));
			writeString(option);
		} else {
			writeString("All (*.*)|*.*");
		}
		readString(path);
		return path.getLength() != 0;
	}

	bool getSaveFilename(String& path, char* option)
	{
		writeInt(208);
		if (option) {
			writeString(option);
		} else {
			writeString("All (*.*)|*.*");
		}
		readString(path);
		return path.getLength() != 0;
	}

	void readPropValue(PROP_TYPE type, void* val)
	{
		switch (type) {
		case CHAR_PROP:
			*((u8*)val) = readInt();
			break;
		case SHORT_PROP:
			*((u16*)val) = readInt();
			break;
		case INT_PROP:
			*((int*)val) = readInt();
			break;
		case FLOAT_PROP:
			*((f32*)val) = readFloat();
			break;
		case COLOUR_PROP:
			*((u8*)val + 0) = readInt();
			*((u8*)val + 1) = readInt();
			*((u8*)val + 2) = readInt();
			*((u8*)val + 3) = readInt();
			break;
		case CHAR_PTR_PROP:
			readString((char*)val, 10000);
			break;
		default:
			//ERROR("Unsupported PropType");
			break;
		}
	}

	void setOnChange(IDelegate* cmd)
	{
		writeInt(207);
		writeInt(0);
		writeInt((int)cmd);
	}

	void setOnChange(IDelegate1<AgeServer&>* cmd)
	{
		writeInt(207);
		writeInt(1);
		writeInt((int)cmd);
	}

	void setSectionRefresh(IDelegate1<AgeServer&>* cmd)
	{
		writeInt(208);
		writeInt((int)cmd);
	}

	int update()
	{
		bool stop = false;
		while (true) {
			int cmd;
			while (true) {
				if (getPending() == 0) {
					if (getPending()) {
						//PRINT("still data on stream !!\n");
					}
					return stop;
				}
				stop = true;
				cmd  = readInt();
				if (cmd > 501) {
					break;
				}
			}

			if (cmd == 500) {
				//PRINT("wants to close age\n");
				writeInt(0xffff);
				return -1;
			}

			switch (cmd) {
			default:
				//ERROR("Age cmd unknown %d", cmd);
				break;
			case 0xca: {
				u32 win = readInt();
				//PRINT("got genage command : %08x\n", win);
				NewPropWindow("Props", win);
				writeInt(win);
				Done();
			} break;
			case 0xcb: {
				PROP_TYPE type = (PROP_TYPE)readInt();
				void* data     = (void*)readInt();
				readPropValue(type, data);
			} break;
			case 0xcc: {
				u32 win = readInt();
				writeInt(win); // this might be wrong, if win is supposed to be a struct with a virtual func then idk what it is
				Done();
			case 0xcd: {
				u32 win = readInt();
				writeInt(win);
				Done();
			} break;
			case 0xce: {
				PROP_TYPE type = (PROP_TYPE)readInt();
				void* data     = (void*)readInt();
				writePropValue(type, data);
			} break;
			case 0xd1: {
				u32 win = readInt();
				writeInt(win);
				Done();
			} break;
			case 0xd2: {
				//PRINT("got update genage command\n");
				u32 win = readInt();
				writeInt(win);
				Done();
			} break;
			}
			}
		}
	}

	void writeProp(PROP_TYPE type, void* data)
	{
		writeInt(type);
		writeInt((int)data);
		writePropValue(type, data);
	}

	void writePropValue(PROP_TYPE type, void* data)
	{
		switch (type) {
		case CHAR_PROP:
			writeInt(*(u8*)data);
			break;
		case SHORT_PROP:
			writeInt(*(u16*)data);
			break;
		case INT_PROP:
			writeInt(*(int*)data);
			break;
		case FLOAT_PROP:
			writeFloat(*(f32*)data);
			break;
		case COLOUR_PROP:
			writeInt(*((u8*)data));
			writeInt(*((u8*)data + 1));
			writeInt(*((u8*)data + 2));
			writeInt(*((u8*)data + 3));
			break;
		case UNK7:
		case UNK9:
			break;
		case CHAR_PTR_PROP:
			writeString((char*)data);
			break;
		default:
			//ERROR("Unsupported PropType");
			break;
		}
	}

#endif

	bool mIsActive; // _10
};

#endif // _AGE_H
