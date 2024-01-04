#ifndef _ID32_H
#define _ID32_H

/*
 * @brief TODO
 */
struct ID32 {
	ID32();
	ID32(unsigned long);
	void setID(unsigned long);
	void match(unsigned long, char);
	void updateID();
	void updateString();
	void operator==(unsigned long);
	void operator!=(unsigned long);
	void write(RandomAccessStream&);
	void read(RandomAccessStream&);
	void print();
	void sprint(char*);
};

#endif
