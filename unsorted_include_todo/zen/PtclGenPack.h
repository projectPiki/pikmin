#ifndef _ZEN_PTCLGENPACK_H
#define _ZEN_PTCLGENPACK_H

/*
 * @brief TODO
 */
namespace zen {
struct PtclGenPack {
	void setPtclGenPtr(unsigned long, zen::particleGenerator*);
	void setEmitPosPtr(Vector3f*);
	void startGen();
	void stopGen();
	void finish();
	void forceFinish();
	void checkStopGen();
};
} // namespace zen

#endif
