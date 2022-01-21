#ifndef _TAIANIMATION_H
#define _TAIANIMATION_H
typedef class TAIanimation;
typedef class AnimMgr;
typedef class AnimInfo;

class AnimInfo {
	AnimInfo();
};
class AnimMgr {
	AnimMgr();

public:
	AnimInfo* addAnimation(char*, bool);
};

class TAIanimation {
	unsigned int _00;     // _00
	AnimMgr* m_animmgr;   // _04
	AnimInfo* m_animinfo; // _08

	AnimInfo* addAnimation(char*);
};
#endif
