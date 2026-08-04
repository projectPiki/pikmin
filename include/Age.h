#ifndef _AGE_H
#define _AGE_H

#include "ANode.h"
#include "AtxStream.h"
#include "Common/String.h"
#include "Delegate.h"
#include "types.h"
#include <string.h>

class AyuImage;
class Colour;

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
#define AGE_CMD_END_NODE          (200) // The same value as AGE_CMD_DONE?
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

/**
 * @brief Note that all of these functions work by sending a specific command id to the server, plugAtxServer.dll has the important stuff
 */
class SYSCORE_API AgeServer : public AtxStream {
public:
	AgeServer() { }

	virtual void close();
	bool Open();

	void readPropValue(PROP_TYPE type, void* val);
	void writeProp(PROP_TYPE type, void* data);
	void writePropValue(PROP_TYPE type, void* data);

	int update();

	void setSectionRefresh(IDelegate1<AgeServer&>* cmd);
	void setOnChange(IDelegate1<AgeServer&>* cmd);
	void setOnChange(IDelegate* cmd);

	void NewNodeWindow(char* name);
	void NewPropWindow(char* name, u32 a);

	void RefreshSection();
	void RefreshNode();

	bool getOpenFilename(String& path, char* option);
	bool getSaveFilename(String& path, char* option);

	void NewNode(char* name, ANode* node);
	void EndNode();
	void Done();

	void StartSection(char* name, bool unk);
	void EndSection();

	void StartGroup(char* name);
	void EndGroup();

	void NewEditor(char* name, int* val, int min, int max, int step);
	void NewEditor(char* name, short* val, int min, int max, int step);
	void NewEditor(char* name, char* val, int min, int max, int step);
	void NewEditor(char* name, float* val, float min, float max, int step);
	void NewEditor(char* name, Colour* col);
	void NewEditor(char* name, char* val, int len);
	void NewEditor(char* name, AyuImage* img, bool a);

	void NewViewer(char* name, int* val);
	void NewViewer(char* name, float* val);

	void StartBitGroup(char* name, u32* val, int a);
	void StartBitGroup(char* name, u8* val, int a);
	void NewBit(char* name, u32 a1, u32 a2);
	void EndBitGroup();

	void StartOptionBox(char* name, int* val, int a);
	void StartOptionBox(char* name, u8* val, int a);
	void StartOptionBox(char* name, u16* val, int a);
	void NewOption(char* name, int a);
	void NewLabel(char* lbl);
	void EndOptionBox();

	void NewButton(char* name, IDelegate1<AgeServer&>* cmd, int a);
	void NewButton(char* name, IDelegate* cmd, int a);

private:
	bool mIsActive; // _10
};

#endif // _AGE_H
