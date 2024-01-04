#ifndef _TIMERS_H
#define _TIMERS_H

/*
 * @brief TODO
 */
struct Timers {
	void reset();
	void newFrame();
	void _start(char*, bool);
	void _stop(char*);
	void draw(Graphics&, Font*);
};

#endif
