#ifndef _AGE_H
#define _AGE_H

#include "ANode.h"
#include "AtxStream.h"
#include "Common/String.h"
#include "Delegate.h"
#include "types.h"
#include <string.h>

// ---- AgeServer protocol constants ----
// Only name the ones we can be confident about; keep others numeric.
// Client -> server
#define AGE_CMD_END_OPTION        (0)
#define AGE_CMD_NEW_OPTION        (1)
#define AGE_CMD_DONE              (200)
#define AGE_CMD_NEW_NODE_WINDOW   (100)
#define AGE_CMD_NEW_NODE          (101)
#define AGE_CMD_NEW_EDITOR        (102)
#define AGE_CMD_NEW_PROP_WINDOW   (104)
#define AGE_CMD_NEW_VIEWER        (107)
#define AGE_CMD_NEW_LABEL         (108)
#define AGE_CMD_START_SECTION     (300)
#define AGE_CMD_END_SECTION       (301)
#define AGE_CMD_START_GROUP       (302)
#define AGE_CMD_END_GROUP         (303)
#define AGE_CMD_SET_ON_CHANGE     (207)
#define AGE_CMD_208               (208)
#define AGE_CMD_REFRESH_NODE      (402)
#define AGE_CMD_REFRESH_SECTION   (403)
#define AGE_CMD_GET_OPEN_FILENAME (404)

// Server -> client
#define AGE_SRV_CMD_REQUEST_CLOSE               (500)
#define AGE_SRV_CMD_0xCA                        (0xCA)
#define AGE_SRV_CMD_APPLY_PROP_VALUE_TO_PTR     (0xCB)
#define AGE_SRV_CMD_0xCC                        (0xCC)
#define AGE_SRV_CMD_0xCD                        (0xCD)
#define AGE_SRV_CMD_REQUEST_PROP_VALUE_FROM_PTR (0xCE)
#define AGE_SRV_CMD_0xD1                        (0xD1)
#define AGE_SRV_CMD_0xD2                        (0xD2)

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
#ifdef WIN32
	void Done() { writeInt(AGE_CMD_DONE); }

	void EndBitGroup() { writeInt(AGE_CMD_END_OPTION); }

	void EndGroup() { writeInt(AGE_CMD_END_GROUP); }

	void EndNode() { writeInt(AGE_CMD_END_NODE); }

	void EndOptionBox() { writeInt(AGE_CMD_END_OPTION); }

	void EndSection()
	{
		writeInt(AGE_CMD_END_SECTION);
		mIsActive = false;
	}

	void NewBit(char* name, u32 a1, u32 a2)
	{
		writeInt(AGE_CMD_NEW_OPTION);
		writeString(name);
		writeInt(a1);
		writeInt(a2);
	}

	void NewButton(char* name, IDelegate* cmd, int a)
	{
		writeInt(AGE_CMD_START_GROUP);
		writeString(name);
		writeInt(a);
		writeInt(0);
		writeInt((int)cmd);
	}

	void NewButton(char* name, IDelegate1<AgeServer&>* cmd, int a)
	{
		writeInt(AGE_CMD_START_GROUP);
		writeString(name);
		writeInt(a);
		writeInt(1);
		writeInt((int)cmd);
	}

	void NewEditor(char* name, class AyuImage* img, bool a)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		if (a) {
			writeProp(IMAGE_PROP, img);
		} else {
			writeProp(STRING_PROP, img);
		}
	}

	void NewEditor(char* name, Colour* col)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(COLOUR_PROP, col);
	}

	void NewEditor(char* name, char* val, int len)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(CHAR_PTR_PROP, val);
		writeInt(len - 1);
	}

	void NewEditor(char* name, char* val, int min, int max, int step)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(CHAR_PROP, val);
		writeInt(1);
		writeFloat(min);
		writeFloat(max);
		writeInt(step);
	}

	void NewEditor(char* name, f32* val, f32 min, f32 max, int step)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(FLOAT_PROP, val);
		writeFloat(min);
		writeFloat(max);
		writeInt(step);
	}

	void NewEditor(char* name, int* val, int min, int max, int step)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(INT_PROP, val);
		writeFloat(min);
		writeFloat(max);
		writeInt(step);
	}

	void NewEditor(char* name, short* val, int min, int max, int step)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(SHORT_PROP, val);
		writeFloat(min);
		writeFloat(max);
		writeInt(step);
	}

	void NewLabel(char* lbl)
	{
		writeInt(AGE_CMD_NEW_LABEL);
		writeString(lbl);
	}

	void NewNode(char* name, ANode* node)
	{
		writeInt(AGE_CMD_NEW_NODE);
		writeInt((int)node);
		writeString(name);
		writeInt(node->getAgeNodeType());
	}

	void NewNodeWindow(char* name)
	{
		writeInt(AGE_CMD_NEW_NODE_WINDOW);
		writeString(name);
	}

	void NewOption(char* name, int a)
	{
		writeInt(AGE_CMD_NEW_OPTION);
		writeString(name);
		writeInt(a);
	}

	void NewPropWindow(char* name, u32 a)
	{
		writeInt(AGE_CMD_NEW_PROP_WINDOW);
		writeString(name);
		writeInt(a);
	}

	void NewViewer(char* name, f32* val)
	{
		writeInt(AGE_CMD_NEW_VIEWER);
		writeString(name);
		writeProp(FLOAT_PROP, val);
	}

	void NewViewer(char* name, int* val)
	{
		writeInt(AGE_CMD_NEW_VIEWER);
		writeString(name);
		writeProp(INT_PROP, val);
	}

	bool Open()
	{
		// PRINT("!!!!! Opening Age server\n");
		if (AtxStream::open(ATX_SERVICE_AGE, ATX_SERVICE_NAME_SIZE)) {
			mIsActive = false;
			return true;
		}

		// ERROR("cant open AgeServer\n");
		return false;
	}

	void RefreshNode() { writeInt(AGE_CMD_REFRESH_NODE); }

	void RefreshSection() { writeInt(AGE_CMD_REFRESH_SECTION); }

	void StartBitGroup(char* name, u32* val, int a)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(UNK7, nullptr);
		writeProp(INT_PROP, val);
		writeInt(a);
	}

	void StartBitGroup(char* name, u8* val, int a)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(UNK7, nullptr);
		writeProp(CHAR_PROP, val);
		writeInt(a);
	}

	void StartGroup(char* name)
	{
		writeInt(AGE_CMD_START_GROUP);
		writeString(name);
	}

	void StartOptionBox(char* name, int* val, int a)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		// PRINT("new optionbox : %08x\n", val);
		writeProp(UNK9, nullptr);
		writeProp(INT_PROP, val);
		writeInt(a);
	}

	void StartOptionBox(char* name, u16* val, int a)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(UNK9, nullptr);
		writeProp(SHORT_PROP, val);
		writeInt(a);
	}

	void StartOptionBox(char* name, u8* val, int a)
	{
		writeInt(AGE_CMD_NEW_EDITOR);
		writeString(name);
		writeProp(UNK9, nullptr);
		writeProp(CHAR_PROP, val);
		writeInt(a);
	}

	void StartSection(char* name, bool unk)
	{
		writeInt(AGE_CMD_START_SECTION);
		writeInt(unk);
		writeString(name);
	}

	virtual void close() { AtxStream::close(); }

	bool getOpenFilename(String& path, char* option)
	{
		writeInt(AGE_CMD_GET_OPEN_FILENAME);
		if (option) {
			// PRINT("filter length = %d\n", strlen(option));
			writeString(option);
		} else {
			writeString("All (*.*)|*.*");
		}
		readString(path);
		return path.getLength() != 0;
	}

	bool getSaveFilename(String& path, char* option)
	{
		writeInt(AGE_CMD_208);
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
			// ERROR("Unsupported PropType");
			break;
		}
	}

	void setOnChange(IDelegate* cmd)
	{
		writeInt(AGE_CMD_SET_ON_CHANGE);
		writeInt(0);
		writeInt((int)cmd);
	}

	void setOnChange(IDelegate1<AgeServer&>* cmd)
	{
		writeInt(AGE_CMD_SET_ON_CHANGE);
		writeInt(1);
		writeInt((int)cmd);
	}

	void setSectionRefresh(IDelegate1<AgeServer&>* cmd)
	{
		writeInt(AGE_CMD_208);
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
						// PRINT("still data on stream !!\n");
					}
					return stop;
				}
				stop = true;
				cmd  = readInt();
				if (cmd > 501) {
					break;
				}
			}

			if (cmd == AGE_SRV_CMD_REQUEST_CLOSE) {
				// PRINT("wants to close age\n");
				writeInt(0xffff);
				return -1;
			}

			switch (cmd) {
			default:
				// ERROR("Age cmd unknown %d", cmd);
				break;
			case AGE_SRV_CMD_0xCA:
			{
				u32 win = readInt();
				// PRINT("got genage command : %08x\n", win);
				NewPropWindow("Props", win);
				writeInt(win);
				Done();
			} break;
			case AGE_SRV_CMD_APPLY_PROP_VALUE_TO_PTR:
			{
				PROP_TYPE type = (PROP_TYPE)readInt();
				void* data     = (void*)readInt();
				readPropValue(type, data);
			} break;
			case AGE_SRV_CMD_0xCC:
			{
				u32 win = readInt();
				writeInt(win); // this might be wrong, if win is supposed to be a struct with a virtual func then idk what it is
				Done();
			} break;
			case AGE_SRV_CMD_0xCD:
			{
				u32 win = readInt();
				writeInt(win);
				Done();
			} break;
			case AGE_SRV_CMD_REQUEST_PROP_VALUE_FROM_PTR:
			{
				PROP_TYPE type = (PROP_TYPE)readInt();
				void* data     = (void*)readInt();
				writePropValue(type, data);
			} break;
			case AGE_SRV_CMD_0xD1:
			{
				u32 win = readInt();
				writeInt(win);
				Done();
			} break;
			case AGE_SRV_CMD_0xD2:
			{
				// PRINT("got update genage command\n");
				u32 win = readInt();
				writeInt(win);
				Done();
			} break;
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
			// ERROR("Unsupported PropType");
			break;
		}
	}

#endif

	bool mIsActive; // _10
};

#endif // _AGE_H
