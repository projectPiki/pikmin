#ifndef _ZEN_OGFILESELECT_H
#define _ZEN_OGFILESELECT_H

#include "types.h"
#include "zen/SpectrumCursorMgr.h"
#include "MemoryCard.h"
#include "Vector.h"
#include "Colour.h"

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

	void setOperateMode_Copy();
	void CopyEffectStart();
	void OperateCopy(Controller*);

	void setOperateMode_Delete();
	void OperateDelete(Controller*);

	// unused/inlined:
	void UpDateYesNoWindow();
	void setOperateMode_Normal();
	void set_SM_C();
	void ScaleAnimeTitle();
	void ScaleAnimeData();
	void init();
	void setDataScale();
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
	u8 _138[0x188 - 0x138];   // _138, unknown
	Vector3f _188[3];         // _188
	Vector3f _1AC[3];         // _1AC
	u8 _1D0[0x26C - 0x1D0];   // _1D0, unknown
	ogNitakuMgr* mNitaku;     // _26C
	u8 _270[0x2C];            // _270
	P2DScreen* _29C[3];       // _29C
	P2DScreen* _2A8[3];       // _2A8
	P2DScreen* _2B4;          // _2B4
	P2DScreen* _2B8;          // _2B8
	P2DScreen* _2BC;          // _2BC
	P2DScreen* _2C0;          // _2C0
	u8 _2C4[0x8];             // _2C4, unknown
	P2DPicture* _2CC;         // _2CC
	P2DPicture* _2D0;         // _2D0
	P2DTextBox* _2D4;         // _2D4
	P2DPane* _2D8;            // _2D8
	u8 _2DC[0x2F8 - 0x2DC];   // _2DC, unknown
	P2DPane* _2F8;            // _2F8
	P2DPane* _2FC;            // _2FC
	P2DPane* _300;            // _300
	u8 _304[0x10];            // _304, unknown
	P2DPane* _314;            // _314
	u8 _318[0x380 - 0x318];   // _318, unknown
	P2DPane* _380[3];         // _380
	u8 _38C[0x3B0 - 0x38C];   // _38C, unknown
	P2DPane* _3B0[3];         // _3B0
	P2DPane* _3BC[3];         // _3BC
	u8 _3C8[0x3D4 - 0x3C8];   // _3C8, unknown
	P2DPane* _3D4[3];         // _3D4
	P2DPane* _3E0[3];         // _3E0
	u8 _3EC[0x448 - 0x3EC];   // _3EC, unknown
	P2DPane* _448;            // _448
	P2DPicture* _44C;         // _44C
	u8 _450[0x4BC - 0x450];   // _450, unknown
	SpectrumCursorMgr _4BC;   // _4BC
	u8 _4EC[0x10];            // _4EC, unknown
	SpectrumCursorMgr _4FC;   // _4FC
	u8 _52C[0x550 - 0x52C];   // _52C, unknown
	Colour _550;              // _550
	Colour _554;              // _554
	Colour _558;              // _558
	Colour _55C;              // _55C
	u8 _560[0x1188 - 0x560];  // _560, unknown
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
