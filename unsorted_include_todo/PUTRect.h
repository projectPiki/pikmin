#ifndef _PUTRECT_H
#define _PUTRECT_H

/*
 * @brief TODO
 */
struct PUTRect {
	void set(int, int, int, int);
	void copy(const PUTRect&);
	void add(int, int);
	void intersect(const PUTRect&);
	void move(int, int);
	void resize(int, int);
	void normalize();
	void isEmpty() const;
};

#endif
