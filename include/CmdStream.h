#ifndef _CMDSTREAM_H
#define _CMDSTREAM_H

#include "Stream.h"

/*
 * @brief TODO
 */
struct CmdStream {
	CmdStream(Stream*);
	void fillBuffer(bool);
	void whiteSpace(char);
	bool endOfCmds();
	void copyToToken(int);
	void skipLine();
	char* getToken(bool);
	bool isToken(char*);
	bool endOfSection();
};

#endif
