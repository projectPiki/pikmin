#ifndef _RESULTFLAGS_H
#define _RESULTFLAGS_H

/*
 * @brief TODO
 */
struct ResultFlags {
	ResultFlags();
	void initGame();
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
	void setOn(int);
	void setSeen(int);
	void getDayDocument(int, int&);
	void getDocument(int&);
	void dump();
	void getFlag(int);
	void setFlag(int, unsigned char);
};

#endif
