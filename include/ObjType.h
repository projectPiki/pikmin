#ifndef _OBJTYPE_H
#define _OBJTYPE_H
struct ObjType {
	// members
	int obj_index;  // _00
	char* obj_name; // _04

	// functions
	static char* getName(int);
	static int getIndex(char*);
};

#endif
