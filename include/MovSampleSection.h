#ifndef _MOVSAMPLESECTION_H
#define _MOVSAMPLESECTION_H

#include "types.h"
#include "Section.h"
#include "Controller.h"
#include "jaudio/app_inter.h"
#include "system.h"
#include "gameflow.h"

u16 ImgW;
u16 ImgH;
OSThread playbackThread;
bool finishPlayback;

static void* playbackFunc(void*);

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct MovSampleSection : public Section {
	MovSampleSection() { }

	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

/**
 * @brief TODO
 */
struct MovSampleSetupSection : public Node {
	MovSampleSetupSection()
	{
		mName    = "MovSample section";
		mControl = new Controller;
		_28      = 0xa0;
		_30      = 0;
		gsys->setFade(1.0f, 3.0f);

		static char* movieNames[6] = { "../MovieData/cntA_S.h4m", "../MovieData/cntB_S.h4m", "../MovieData/cntC_S.h4m",
			                           "../MovieData/cntD_S.h4m", "../MovieData/sr_S.h4m",   "../MovieData/srhp_S.h4m" };
		int size                   = 0xe00000;
		u8* store                  = new u8[size];
		Jac_StreamMovieInit(movieNames[gameflow._2B0], store, size);
		ImgW   = 640;
		ImgH   = 480;
		_48[0] = new u8[0x70800];
		_48[1] = new u8[0x70800];
		for (int i = 0; i < 2; i++) {
			memset(_48[i], 0x10, ImgW * ImgH);
			memset(_48[i + ImgW * ImgH], 0x10, (ImgW * 2) * (ImgH * 2) * 2);
		}
		OSCreateThread(&playbackThread, playbackFunc, 0, 0, 0x1000, 0x14, 1);
		finishPlayback = false;
		OSResumeThread(&playbackThread);
	}

	virtual void update();        // _10 (weak)
	virtual void draw(Graphics&); // _14 (weak)

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
	int _20;              // _20
	int _24;              // _24
	int _28;              // _28
	Controller* mControl; // _2C
	int _30;              // _30
	int _34;              // _34
	int _38;              // _38
	int _3C;              // _3C
	int _40;              // _40
	int _44;              // _44
	u8* _48[2];           // _48
};

// Global functions:
void convHVQM4TexY8UV8(int, int, u8*, u8*);

#endif
