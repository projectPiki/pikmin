#ifndef _ZEN_OGDRAWDIARY_H
#define _ZEN_OGDRAWDIARY_H

/*
 * @brief TODO
 */
namespace zen {
struct ogDrawDiary {
	ogDrawDiary();
	void open(float, float, short);
	void update(Controller*);
};
} // namespace zen

#endif
