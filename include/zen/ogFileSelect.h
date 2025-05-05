#ifndef _ZEN_OGFILESELECT_H
#define _ZEN_OGFILESELECT_H

#include "types.h"
#include "zen/SpectrumCursorMgr.h"
#include "MemoryCard.h"

struct Controller;
struct CardQuickInfo;
struct Graphics;
struct P2DPicture;
struct P2DTextBox;

namespace zen {

struct EffectMgr2D;
struct ogNitakuMgr;
struct particleGenerator;

/**
 * @brief TODO
 *
 * @note Size: 0x11A4.
 */
struct ogScrFileSelectMgr {

	/**
	 * @brief TODO
	 */
	enum FileOperateMode {
		fileOp_0 = 0,
		fileOp_2 = 2,
		// TODO: this
	};

	/**
	 * @brief TODO
	 */
	enum titleMessageFlag {
		titleMsg_2 = 2,
		titleMsg_3 = 3,
		titleMsg_4 = 4,
		titleMsg_5 = 5,
		titleMsg_6 = 6,
		// TODO: this
	};

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	ogScrFileSelectMgr();

	void copyCardInfosSub();
	bool getCardFileInfos();
	void paneOnOffXY(bool);
	void MovePaneXY();
	void OpenYesNoWindow();
	void CloseYesNoWindow();
	void setOperateMode(FileOperateMode);
	void getPane_FileTop1();
	void getPane_FileTop2();
	void setFileData(int);
	void getPane_FileIcon();
	void OnOffKetaNissuu(int);
	void getPane_CpyCurScreen();
	void SetTitleMsg(titleMessageFlag);
	void setDataNumber(int);
	void chaseDataScale();
	void OnOffNewPane(int);
	void ChkOnyonOnOff();
	void ChkNewData();
	void start(bool, int);
	void OperateSelect(Controller*);
	void KetteiEffectStart();
	void TailEffectStart();
	returnStatusFlag update(Controller*, CardQuickInfo&);
	void draw(Graphics&);

	// unused/inlined:
	void UpDateYesNoWindow();
	void setOperateMode_Normal();
	void set_SM_C();
	void ScaleAnimeTitle();
	void ScaleAnimeData();
	void init();
	void setDataScale();
	void setOperateMode_Copy();
	void CopyEffectStart();
	void OperateCopy(Controller*);
	void setOperateMode_Delete();
	void OperateDelete(Controller*);
	void BeginFadeOut();
	int CanToCopy(int);
	void TailEffectMove(int, int);
	void TailEffectMoveM(int, int);
	void quit();
	void MoveCpyCursor(int, f32);
	void DeleteEffectStart();

	EffectMgr2D* mEfxMgr;     // _00
	particleGenerator* mEfx;  // _04
	particleGenerator* mEfx2; // _08
	u8 _0C[0x20];             // _0C
	CardQuickInfo _24[3];     // _24
	SpectrumCursorMgr _A4;    // _A4
	SpectrumCursorMgr _D4;    // _D4
	f32 _104[3];              // _104
	f32 _110[3];              // _110
	f32 _11C[3];              // _11C
	f32 _128[3];              // _128
	s16 _134;                 // _134
	u8 _138[0x134];           // _138
	ogNitakuMgr* mNitaku;     // _26C
	u8 _270[0x4C];            // _270
	P2DScreen* _2BC;          // _2BC
	int _2C0[3];              // _2C0
	P2DPicture* _2CC;         // _2CC
	P2DPicture* _2D0;         // _2D0
	P2DTextBox* _2D4;         // _2D4
	P2DPane* _2D8;            // _2D8
	int _2DC[7];              // _2DC
	P2DPane* _2F8;            // _2F8
	P2DPane* _2FC;            // _2FC
	P2DPane* _300;            // _300
	int _304[4];              // _304
	P2DPane* _314;            // _314
	int _318[38];             // _318
	P2DPane* mPanes[3];       // _3B0
	int _3BC[35];             // _3BC
	P2DPane* _448;            // _448
	u8 _44C[0xd3C];           // _44C
	f32 _1188;                // _1188
	f32 _118C;                // _118C
	u32 _1190;                // _1190
	u8 _1194;                 // _1194
	u8 _1195;                 // _1195
	u8 _1196;                 // _1196
	u8 _1197;                 // _1197
	u8 _1198;                 // _1198
	u8 _1199;                 // _1199
	int _119C;                // _119C
	u8 _11A0;                 // _11A0
};

} // namespace zen

#endif
