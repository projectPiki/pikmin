#ifndef _ZEN_OGMEMCHK_H
#define _ZEN_OGMEMCHK_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DScreen;
struct P2DPane;
struct P2DPicture;
struct P2DTextBox;

namespace zen {

struct ogNitakuMgr;
struct TypingTextMgr;
struct EffectMgr2D;
struct setTenmetuAlpha;
struct ogScrMakeDefaultMgr;
struct particleGenerator;

/**
 *
 * @note Size: 0x10C.
 */
struct ogScrMemChkMgr {

	/**
	 * @brief TODO
	 */
	enum MemChkStatus {
		STATE_NULL  = -1,
		STATE_Unk0  = 0,
		STATE_Unk1  = 1,
		STATE_Unk2  = 2,
		STATE_Unk3  = 3,
		STATE_Unk4  = 4,
		STATE_Unk5  = 5,
		STATE_Unk6  = 6,
		STATE_Unk7  = 7,
		STATE_Unk8  = 8,
		STATE_Unk9  = 9,
		STATE_Unk10 = 10,
		STATE_Unk11 = 11,
		STATE_Unk12 = 12,
		STATE_Unk13 = 13,
		STATE_Unk14 = 14,
		STATE_Unk15 = 15,
		STATE_Unk16 = 16,
		STATE_Unk17 = 17,
		STATE_Unk18 = 18,
		STATE_Unk19 = 19,
		STATE_Unk20 = 20,
		STATE_Unk21 = 21,
	};

	ogScrMemChkMgr();

	void StatusCheck();
	void setPCtex(TypingTextMgr*);
	void DispYesNo(bool);
	void DispAcup(bool);
	void start();
	void DebugStart(int);
	MemChkStatus update(Controller*);
	void draw(Graphics&);
	void setErrorMessage();

	// unused/inlined:
	void SetNitaku_Y_N();
	void SetNitaku_W_R();
	void SetNitaku_F_N();
	void StartSub();
	void MakeDefFileStart();
	void RepairFileStart();
	void FormatEffectStart();
	bool checkTypingAll();
	void checkErrNitaku(zen::ogNitakuMgr*, Controller*);
	void setNoCard();

	u8 _00;                   // _00
	int _04;                  // _04
	s16 _08;                  // _08
	EffectMgr2D* _0C;         // _0C
	particleGenerator* _10;   // _10
	particleGenerator* _14;   // _14
	ogScrMakeDefaultMgr* _18; // _18
	MemChkStatus mState;      // _1C
	int _20;                  // _20
	P2DScreen* _24;           // _24
	P2DPicture* _28;          // _28
	P2DScreen* _2C;           // _2C
	TypingTextMgr* _30;       // _30
	TypingTextMgr* _34;       // _34
	TypingTextMgr* _38;       // _38
	TypingTextMgr* _3C;       // _3C
	TypingTextMgr* _40;       // _40
	TypingTextMgr* _44;       // _44
	TypingTextMgr* _48;       // _48
	TypingTextMgr* _4C;       // _4C
	TypingTextMgr* _50;       // _50
	TypingTextMgr* _54;       // _54
	TypingTextMgr* _58;       // _58
	TypingTextMgr* _5C;       // _5C
	TypingTextMgr* _60;       // _60
	TypingTextMgr* _64;       // _64
	TypingTextMgr* _68;       // _68
	TypingTextMgr* _6C;       // _6C
	TypingTextMgr* _70;       // _70
	P2DTextBox* _74;          // _74
	P2DTextBox* _78;          // _78
	P2DTextBox* _7C;          // _7C
	P2DTextBox* _80;          // _80
	P2DTextBox* _84;          // _84
	P2DTextBox* _88;          // _88
	P2DTextBox* _8C;          // _8C
	P2DTextBox* _90;          // _90
	P2DTextBox* _94;          // _94
	P2DPane* _98;             // _98
	P2DPane* _9C;             // _9C
	setTenmetuAlpha* _A0;     // _A0
	P2DPicture* _A4;          // _A4
	P2DPane* _A8;             // _A8
	P2DTextBox* _AC;          // _AC
	P2DTextBox* _B0;          // _B0
	P2DTextBox* _B4;          // _B4
	P2DTextBox* _B8;          // _B8
	setTenmetuAlpha* _BC;     // _BC
	P2DPicture* _C0;          // _C0
	f32 _C4;                  // _C4
	f32 _C8;                  // _C8
	P2DPane* _CC;             // _CC
	P2DPane* _D0;             // _D0
	ogNitakuMgr* _D4;         // _D4
	char* _D8;                // _D8
	char* _DC;                // _DC
	char* _E0;                // _E0
	char* _E4;                // _E4
	char* _E8;                // _E8
	P2DTextBox* _EC;          // _EC
	P2DTextBox* _F0;          // _F0
	P2DTextBox* _F4;          // _F4
	P2DTextBox* _F8;          // _F8
	P2DTextBox* _FC;          // _FC
	P2DTextBox* _100;         // _100
	P2DTextBox* _104;         // _104
	int _108;                 // _108
};

} // namespace zen

#endif
