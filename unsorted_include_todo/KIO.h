#ifndef _KIO_H
#define _KIO_H

/*
 * @brief TODO
 */
struct KIO {
	KIO();
	void initialise();
	void readMailbox();
	void startWrite(int, unsigned char*, int);
	void writeHeader();
};

#endif
