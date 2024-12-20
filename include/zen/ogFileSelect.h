#ifndef _ZEN_OGFILESELECT_H
#define _ZEN_OGFILESELECT_H

#include "types.h"

struct Controller;
struct CardQuickInfo;
struct Graphics;

namespace zen {

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
		// TODO: this
	};

	/**
	 * @brief TODO
	 */
	enum titleMessageFlag {
		// TODO: this
	};

	ogScrFileSelectMgr();

	void copyCardInfosSub();
	void getCardFileInfos();
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
	int update(Controller*, CardQuickInfo&);
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
	void CanToCopy(int);
	void TailEffectMove(int, int);
	void TailEffectMoveM(int, int);
	void quit();
	void MoveCpyCursor(int, f32);
	void DeleteEffectStart();

	u8 _00[0x11A4]; // _00, unknown
};

} // namespace zen

#endif
