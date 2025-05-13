#ifndef _ZEN_OGFILESELECT_H
#define _ZEN_OGFILESELECT_H

#include "types.h"
#include "zen/SpectrumCursorMgr.h"
#include "MemoryCard.h"
#include "P2D/TextBox.h"
#include "zen/ogSub.h"
#include "stl/string.h"
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
 * @note Size: 0x108.
 */
struct ogCnvStringMgr {
	ogCnvStringMgr(P2DTextBox* tbox)
	{
		mTextBox = tbox;
		mTextPtr = tbox->getString();
	}

	// DLL inlines:
	void convert()
	{
		strcpy(mTextBuffer, mTextPtr);
		cnvSpecialNumber(mTextBuffer);
		mTextBox->setString(mTextBuffer);
	}

	P2DTextBox* mTextBox;    // _00
	char* mTextPtr;          // _04
	char mTextBuffer[0x100]; // _08
};

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
		OPMODE_Normal = 0,
		OPMODE_Copy   = 1,
		OPMODE_Delete = 2,
	};

	/**
	 * @brief TODO
	 */
	enum titleMessageFlag {
		titleMsg_0  = 0,
		titleMsg_1  = 1,
		titleMsg_2  = 2,
		titleMsg_3  = 3,
		titleMsg_4  = 4,
		titleMsg_5  = 5,
		titleMsg_6  = 6,
		titleMsg_7  = 7,
		titleMsg_8  = 8,
		titleMsg_9  = 9,
		titleMsg_10 = 10,
		titleMsg_11 = 11,
		titleMsg_12 = 12,
		titleMsg_13 = 13,
	};

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		STATE_NULL  = -1,
		STATE_Unk0  = 0,
		STATE_Unk1  = 1,
		STATE_Unk2  = 2,
		STATE_Unk3  = 3,
		STATE_Unk6  = 6,
		STATE_Unk7  = 7,
		STATE_Unk8  = 8,
		STATE_Unk9  = 9,
		STATE_Unk10 = 10,
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

	EffectMgr2D* mEfxMgr;         // _00
	particleGenerator* mEfx;      // _04
	particleGenerator* mEfx2;     // _08
	particleGenerator* _0C;       // _0C
	particleGenerator* _10;       // _10
	particleGenerator* _14;       // _14
	particleGenerator* _18;       // _18
	u8 _1C[0x4];                  // _1C, unknown
	returnStatusFlag mState;      // _20
	FileOperateMode mOperateMode; // _24
	bool mSaveMode;               // _28
	CardQuickInfo _2C[3];         // _2C
	SpectrumCursorMgr _A4;        // _A4
	SpectrumCursorMgr _D4;        // _D4
	f32 _104[3];                  // _104
	f32 _110[3];                  // _110
	f32 _11C[3];                  // _11C
	f32 _128[3];                  // _128
	s16 _134;                     // _134
	f32 _138[3];                  // _138
	f32 _144[3];                  // _144
	f32 _150;                     // _150
	int mMaxPartsNum;             // _154
	int _158[3];                  // _158
	int _164[3];                  // _164
	int _170[3];                  // _170
	int _17C[3];                  // _17C
	Vector3f _188[3];             // _188
	Vector3f _1AC[3];             // _1AC
	int _1D0[3];                  // _1D0
	int _1DC[3];                  // _1DC
	int _1E8[3];                  // _1E8
	int _1F4[3];                  // _1F4
	int _200[3];                  // _200
	int _20C[3];                  // _20C
	int _218[3];                  // _218
	int _224[3];                  // _224
	int _230[3];                  // _230
	int _23C[3];                  // _23C
	int _248[3];                  // _248
	int _254[3];                  // _254
	ogCnvStringMgr* _260;         // _260
	ogCnvStringMgr* _264;         // _264
	ogCnvStringMgr* _268;         // _268
	ogNitakuMgr* mNitaku;         // _26C
	int _270;                     // _270
	int _274;                     // _274
	bool _278;                    // _278
	titleMessageFlag mTitleMsg;   // _27C
	f32 _280;                     // _280
	u8 _284;                      // _284
	f32 _288;                     // _288
	u8 _28C;                      // _28C
	u8 _28D;                      // _28D
	f32 _290;                     // _290
	int _294;                     // _294
	int _298;                     // _298
	P2DScreen* _29C[3];           // _29C
	P2DScreen* _2A8[3];           // _2A8
	P2DScreen* _2B4;              // _2B4
	P2DScreen* _2B8;              // _2B8
	P2DScreen* _2BC;              // _2BC
	P2DScreen* _2C0;              // _2C0
	P2DPane* _2C4;                // _2C4
	P2DPane* _2C8;                // _2C8
	P2DPicture* _2CC;             // _2CC
	P2DPicture* _2D0;             // _2D0
	P2DTextBox* _2D4;             // _2D4
	P2DPane* _2D8;                // _2D8
	P2DPane* _2DC;                // _2DC
	P2DTextBox* _2E0;             // _2E0
	P2DTextBox* _2E4;             // _2E4
	P2DPane* _2E8;                // _2E8
	P2DPane* _2EC;                // _2EC
	P2DPane* _2F0;                // _2F0
	P2DPane* _2F4;                // _2F4
	P2DPane* _2F8;                // _2F8
	P2DPane* _2FC;                // _2FC
	P2DPane* _300;                // _300
	P2DPane* _304;                // _304
	P2DPane* _308;                // _308
	P2DPane* _30C;                // _30C
	P2DTextBox* _310;             // _310
	P2DTextBox* _314;             // _314
	P2DTextBox* _318;             // _318
	P2DTextBox* _31C;             // _31C
	P2DTextBox* _320;             // _320
	P2DTextBox* _324;             // _324
	P2DPane* _328;                // _328
	P2DPane* _32C;                // _32C
	P2DPane* _330;                // _330
	P2DPane* _334;                // _334
	P2DPane* _338;                // _338
	P2DPane* _33C;                // _33C
	P2DPane* _340;                // _340
	P2DPane* _344;                // _344
	P2DPane* _348;                // _348
	P2DPane* _34C;                // _34C
	P2DPane* _350;                // _350
	P2DPane* _354;                // _354
	P2DPane* _358;                // _358
	P2DPane* _35C;                // _35C
	P2DPane* _360;                // _360
	P2DPane* _364;                // _364
	P2DPane* _368;                // _368
	P2DPane* _36C;                // _36C
	P2DPane* _370;                // _370
	P2DPane* _374;                // _374
	P2DPane* _378;                // _378
	P2DPane* _37C;                // _37C
	P2DPane* _380[3];             // _380
	P2DPane* _38C[3];             // _38C
	P2DPane* _398[3];             // _398
	P2DPane* _3A4[3];             // _3A4
	P2DPane* _3B0[3];             // _3B0
	P2DPane* _3BC[3];             // _3BC
	P2DPane* _3C8[3];             // _3C8
	P2DPane* _3D4[3];             // _3D4
	P2DPane* _3E0[3];             // _3E0
	P2DPane* _3EC[3];             // _3E0
	P2DPicture* _3F8[3];          // _3F8
	P2DPane* _404[3];             // _404
	P2DPane* _410[3];             // _410
	P2DPicture* _41C[3];          // _41C
	P2DPicture* _428[3];          // _428
	P2DPicture* _434[3];          // _434
	P2DPane* _440;                // _440
	P2DPane* _444;                // _444
	P2DPane* _448;                // _448
	P2DPicture* _44C;             // _44C
	u8 _450[0x4BC - 0x450];       // _450, unknown
	SpectrumCursorMgr _4BC;       // _4BC
	u8 _4EC[0x10];                // _4EC, unknown
	SpectrumCursorMgr _4FC;       // _4FC
	u8 _52C[0x53C - 0x52C];       // _52C, unknown
	f32 _53C;                     // _53C
	u8 _540[0xC];                 // _540
	f32 _54C;                     // _54C
	Colour _550;                  // _550
	Colour _554;                  // _554
	Colour _558;                  // _558
	Colour _55C;                  // _55C
	u8 _560[0x1180 - 0x560];      // _560, unknown
	u8 _1180;                     // _1180
	f32 _1184;                    // _1184
	f32 _1188;                    // _1188
	f32 _118C;                    // _118C
	u8 _1190[3];                  // _1190
	u8 _1193;                     // _1193
	u8 _1194;                     // _1194
	u8 _1195;                     // _1195
	u8 _1196;                     // _1196
	u8 _1197;                     // _1197
	u8 _1198;                     // _1198
	u8 _1199;                     // _1199
	int _119C;                    // _119C
	u8 _11A0;                     // _11A0
};

} // namespace zen

#endif
