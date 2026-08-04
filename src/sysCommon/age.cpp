#include "Age.h"

#include "DebugLog.h"

DEFINE_ERROR(7) // Why is this one suddenly capitalized?
DEFINE_PRINT("Age")

/**
 * @todo Documentation
 */
void AgeServer::close()
{
	AtxStream::close();
}

/**
 * @todo Documentation
 */
bool AgeServer::Open()
{
	PRINT("!!!!! Opening Age server\n");
	if (AtxStream::open(ATX_SERVICE_AGE, ATX_SERVICE_NAME_SIZE)) {
		mIsActive = false;
		return true;
	}

	PRINT("cant open AgeServer\n");
	return false;
}

/**
 * @todo Documentation
 */
void AgeServer::readPropValue(PROP_TYPE type, void* val)
{
	switch (type) {
	case CHAR_PROP:
	{
		*static_cast<u8*>(val) = readInt();
		break;
	}
	case SHORT_PROP:
	{
		*static_cast<u16*>(val) = readInt();
		break;
	}
	case INT_PROP:
	{
		*static_cast<int*>(val) = readInt();
		break;
	}
	case FLOAT_PROP:
	{
		*static_cast<float*>(val) = readFloat();
		break;
	}
	case COLOUR_PROP:
	{
		static_cast<u8*>(val)[0] = readInt();
		static_cast<u8*>(val)[1] = readInt();
		static_cast<u8*>(val)[2] = readInt();
		static_cast<u8*>(val)[3] = readInt();
		break;
	}
	case CHAR_PTR_PROP:
	{
		readString(static_cast<char*>(val), 10000);
		break;
	}
	default:
	{
		ERROR("Unsupported PropType");
		break;
	}
	}
}

/**
 * @todo Documentation
 */
void AgeServer::writeProp(PROP_TYPE type, void* data)
{
	writeInt(type);
	writeInt(reinterpret_cast<int>(data));
	writePropValue(type, data);
}

/**
 * @todo Documentation
 */
void AgeServer::writePropValue(PROP_TYPE type, void* data)
{
	switch (type) {
	case CHAR_PROP:
	{
		writeInt(*static_cast<u8*>(data));
		break;
	}
	case SHORT_PROP:
	{
		writeInt(*static_cast<u16*>(data));
		break;
	}
	case INT_PROP:
	{
		writeInt(*static_cast<int*>(data));
		break;
	}
	case FLOAT_PROP:
	{
		writeFloat(*static_cast<f32*>(data));
		break;
	}
	case COLOUR_PROP:
	{
		writeInt(static_cast<u8*>(data)[0]);
		writeInt(static_cast<u8*>(data)[1]);
		writeInt(static_cast<u8*>(data)[2]);
		writeInt(static_cast<u8*>(data)[3]);
		break;
	}
	case UNK7:
	case UNK9:
	{
		break;
	}
	case CHAR_PTR_PROP:
	{
		writeString(static_cast<char*>(data));
		break;
	}
	default:
	{
		ERROR("Unsupported PropType");
		break;
	}
	}
}

/**
 * @todo Documentation
 */
int AgeServer::update()
{
	bool stop = false;
	while (true) {
		int cmd;
		while (true) {
			if (getPending() == 0) {
				if (getPending()) {
					PRINT("still data on stream !!\n");
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
			PRINT("wants to close age\n");
			writeInt(0xffff);
			return -1;
		}

		switch (cmd) {
		default:
		{
			ERROR("Age cmd unknown %d", cmd);
			break;
		}
		case AGE_SRV_CMD_0xCA:
		{
			u32 win = readInt();
			PRINT("got genage command : %08x\n", win);
			NewPropWindow("Props", win);
			writeInt(win);
			Done();
			break;
		}
		case AGE_SRV_CMD_APPLY_PROP_VALUE_TO_PTR:
		{
			PROP_TYPE type = static_cast<PROP_TYPE>(readInt());
			void* data     = reinterpret_cast<void*>(readInt());
			readPropValue(type, data);
			break;
		}
		case AGE_SRV_CMD_0xCC:
		{
			u32 win = readInt();
			writeInt(win); // this might be wrong, if win is supposed to be a struct with a virtual func then idk what it is
			Done();
			break;
		}
		case AGE_SRV_CMD_0xCD:
		{
			u32 win = readInt();
			writeInt(win);
			Done();
			break;
		}
		case AGE_SRV_CMD_REQUEST_PROP_VALUE_FROM_PTR:
		{
			PROP_TYPE type = static_cast<PROP_TYPE>(readInt());
			void* data     = reinterpret_cast<void*>(readInt());
			writePropValue(type, data);
			break;
		}
		case AGE_SRV_CMD_0xD1:
		{
			u32 win = readInt();
			writeInt(win);
			Done();
			break;
		}
		case AGE_SRV_CMD_0xD2:
		{
			PRINT("got update genage command\n");
			u32 win = readInt();
			writeInt(win);
			Done();
			break;
		}
		}
	}
}

/**
 * @todo Documentation
 */
void AgeServer::setSectionRefresh(IDelegate1<AgeServer&>* cmd)
{
	writeInt(AGE_CMD_208);
	writeInt(reinterpret_cast<int>(cmd));
}

/**
 * @todo Documentation
 */
void AgeServer::setOnChange(IDelegate1<AgeServer&>* cmd)
{
	writeInt(AGE_CMD_SET_ON_CHANGE);
	writeInt(1);
	writeInt(reinterpret_cast<int>(cmd));
}

/**
 * @todo Documentation
 */
void AgeServer::setOnChange(IDelegate* cmd)
{
	writeInt(AGE_CMD_SET_ON_CHANGE);
	writeInt(0);
	writeInt(reinterpret_cast<int>(cmd));
}

/**
 * @todo Documentation
 */
void AgeServer::NewNodeWindow(char* name)
{
	writeInt(AGE_CMD_NEW_NODE_WINDOW);
	writeString(name);
}

/**
 * @todo Documentation
 */
void AgeServer::NewPropWindow(char* name, u32 a)
{
	writeInt(AGE_CMD_NEW_PROP_WINDOW);
	writeString(name);
	writeInt(a);
}

/**
 * @todo Documentation
 */
void AgeServer::RefreshSection()
{
	writeInt(AGE_CMD_REFRESH_SECTION);
}

/**
 * @todo Documentation
 */
void AgeServer::RefreshNode()
{
	writeInt(AGE_CMD_REFRESH_NODE);
}

/**
 * @todo Documentation
 */
bool AgeServer::getOpenFilename(String& path, char* option)
{
	writeInt(AGE_CMD_GET_OPEN_FILENAME);
	if (option) {
		PRINT("filter length = %d\n", strlen(option));
		writeString(option);
	} else {
		writeString("All (*.*)|*.*");
	}
	readString(path);
	return path.getLength() != 0;
}

/**
 * @todo Documentation
 */
bool AgeServer::getSaveFilename(String& path, char* option)
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

/**
 * @todo Documentation
 */
void AgeServer::NewNode(char* name, ANode* node)
{
	writeInt(AGE_CMD_NEW_NODE);
	writeInt(reinterpret_cast<int>(node));
	writeString(name);
	writeInt(node->getAgeNodeType());
}

/**
 * @todo Documentation
 */
void AgeServer::EndNode()
{
	writeInt(AGE_CMD_END_NODE);
}

/**
 * @todo Documentation
 */
void AgeServer::Done()
{
	writeInt(AGE_CMD_DONE);
}

/**
 * @todo Documentation
 */
void AgeServer::StartSection(char* name, bool unk)
{
	writeInt(AGE_CMD_START_SECTION);
	writeInt(unk);
	writeString(name);
}

/**
 * @todo Documentation
 */
void AgeServer::EndSection()
{
	writeInt(AGE_CMD_END_SECTION);
	mIsActive = false;
}

/**
 * @todo Documentation
 */
void AgeServer::StartGroup(char* name)
{
	writeInt(AGE_CMD_START_GROUP);
	writeString(name);
}

/**
 * @todo Documentation
 */
void AgeServer::EndGroup()
{
	writeInt(AGE_CMD_END_GROUP);
}

/**
 * @todo Documentation
 */
void AgeServer::NewEditor(char* name, int* val, int min, int max, int step)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(INT_PROP, val);
	writeFloat(min);
	writeFloat(max);
	writeInt(step);
}

/**
 * @todo Documentation
 */
void AgeServer::NewEditor(char* name, short* val, int min, int max, int step)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(SHORT_PROP, val);
	writeFloat(min);
	writeFloat(max);
	writeInt(step);
}

/**
 * @todo Documentation
 */
void AgeServer::NewEditor(char* name, char* val, int min, int max, int step)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(CHAR_PROP, val);
	writeInt(1);
	writeFloat(min);
	writeFloat(max);
	writeInt(step);
}

/**
 * @todo Documentation
 */
void AgeServer::NewEditor(char* name, float* val, float min, float max, int step)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(FLOAT_PROP, val);
	writeFloat(min);
	writeFloat(max);
	writeInt(step);
}

/**
 * @todo Documentation
 */
void AgeServer::NewEditor(char* name, Colour* col)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(COLOUR_PROP, col);
}

/**
 * @todo Documentation
 */
void AgeServer::NewEditor(char* name, char* val, int len)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(CHAR_PTR_PROP, val);
	writeInt(len - 1);
}

/**
 * @todo Documentation
 */
void AgeServer::NewEditor(char* name, AyuImage* img, bool a)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	if (a) {
		writeProp(IMAGE_PROP, img);
	} else {
		writeProp(STRING_PROP, img);
	}
}

/**
 * @todo Documentation
 */
void AgeServer::NewViewer(char* name, int* val)
{
	writeInt(AGE_CMD_NEW_VIEWER);
	writeString(name);
	writeProp(INT_PROP, val);
}

/**
 * @todo Documentation
 */
void AgeServer::NewViewer(char* name, float* val)
{
	writeInt(AGE_CMD_NEW_VIEWER);
	writeString(name);
	writeProp(FLOAT_PROP, val);
}

/**
 * @todo Documentation
 */
void AgeServer::StartBitGroup(char* name, u32* val, int a)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(UNK7, nullptr);
	writeProp(INT_PROP, val);
	writeInt(a);
}

/**
 * @todo Documentation
 */
void AgeServer::StartBitGroup(char* name, u8* val, int a)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(UNK7, nullptr);
	writeProp(CHAR_PROP, val);
	writeInt(a);
}

/**
 * @todo Documentation
 */
void AgeServer::NewBit(char* name, u32 a1, u32 a2)
{
	writeInt(AGE_CMD_NEW_OPTION);
	writeString(name);
	writeInt(a1);
	writeInt(a2);
}

/**
 * @todo Documentation
 */
void AgeServer::EndBitGroup()
{
	writeInt(AGE_CMD_END_OPTION);
}

/**
 * @todo Documentation
 */
void AgeServer::StartOptionBox(char* name, int* val, int a)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	PRINT("new optionbox : %08x\n", val);
	writeProp(UNK9, nullptr);
	writeProp(INT_PROP, val);
	writeInt(a);
}

/**
 * @todo Documentation
 */
void AgeServer::StartOptionBox(char* name, u8* val, int a)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(UNK9, nullptr);
	writeProp(CHAR_PROP, val);
	writeInt(a);
}

/**
 * @todo Documentation
 */
void AgeServer::StartOptionBox(char* name, u16* val, int a)
{
	writeInt(AGE_CMD_NEW_EDITOR);
	writeString(name);
	writeProp(UNK9, nullptr);
	writeProp(SHORT_PROP, val);
	writeInt(a);
}

/**
 * @todo Documentation
 */
void AgeServer::NewOption(char* name, int a)
{
	writeInt(AGE_CMD_NEW_OPTION);
	writeString(name);
	writeInt(a);
}

/**
 * @todo Documentation
 */
void AgeServer::NewLabel(char* lbl)
{
	writeInt(AGE_CMD_NEW_LABEL);
	writeString(lbl);
}

/**
 * @todo Documentation
 */
void AgeServer::EndOptionBox()
{
	writeInt(AGE_CMD_END_OPTION);
}

/**
 * @todo Documentation
 */
void AgeServer::NewButton(char* name, IDelegate1<AgeServer&>* cmd, int a)
{
	writeInt(AGE_CMD_START_GROUP);
	writeString(name);
	writeInt(a);
	writeInt(1);
	writeInt(reinterpret_cast<int>(cmd));
}

/**
 * @todo Documentation
 */
void AgeServer::NewButton(char* name, IDelegate* cmd, int a)
{
	writeInt(AGE_CMD_START_GROUP);
	writeString(name);
	writeInt(a);
	writeInt(0);
	writeInt(reinterpret_cast<int>(cmd));
}
