#ifndef _AGE_H
#define _AGE_H

#include "types.h"

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

struct IDelegate;
template <typename T>
struct IDelegate1;
struct AgeServer;

struct AgeServer : public AtxStream {
	AgeServer() { }

#ifndef __MWERKS__
	void Done();
	void EndBitGroup();
	void EndGroup();
	void EndNode();
	void EndOptionBox();
	void EndSection();

	// NEW SECTION
	void NewBit(char*, u32, u32);

	void NewButton(char*, IDelegate*, int);
	void NewButton(char*, IDelegate1<AgeServer&>*, int);

	void NewEditor(char*, class AyuImage*, bool);
	void NewEditor(char*, Colour*);
	void NewEditor(char*, char*, int);
	void NewEditor(char*, char*, int, int, int);
	void NewEditor(char*, float*, float, float, int);
	void NewEditor(char*, int*, int, int, int);
	void NewEditor(char*, short*, int, int, int);
	void NewLabel(char*);
	void NewNode(char*, ANode*);
	void NewNodeWindow(char*);
	void NewOption(char*, int);
	void NewPropWindow(char*, u32);
	void NewViewer(char*, float*);
	void NewViewer(char*, int*);

	bool Open();
	void RefreshNode();
	void RefreshSection();

	void StartBitGroup(char*, u32*, int);
	void StartBitGroup(char*, u8*, int);
	void StartGroup(char* name);
	void StartOptionBox(char* name, int*, int);
	void StartOptionBox(char* name, u16*, int);
	void StartOptionBox(char* name, u8*, int);
	void StartSection(char* name, bool unk);

	virtual void close();

	bool getOpenFilename(String&, char*);
	bool getSaveFilename(String&, char*);

	void readPropValue(PROP_TYPE, void*);

	void setOnChange(IDelegate*);
	void setOnChange(IDelegate1<AgeServer&>*);
	void setSectionRefresh(IDelegate1<AgeServer&>*);

	bool update();

	void writeProp(PROP_TYPE, void*);
	void writePropValue(PROP_TYPE, void*);
#endif

	bool mIsActive; // _10
};

#endif // _AGE_H
