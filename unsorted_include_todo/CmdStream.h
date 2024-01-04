#ifndef _CMDSTREAM_H
#define _CMDSTREAM_H

/*
 * @brief TODO
 */
struct CmdStream {
	CmdStream(Stream*);
	void fillBuffer(bool);
	void whiteSpace(char);
	void endOfCmds();
	void copyToToken(int);
	void skipLine();
	void getToken(bool);
	void isToken(char*);
	void endOfSection();
};

#endif
