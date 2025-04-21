#ifndef _ZEN_OGMEMCHK_H
#define _ZEN_OGMEMCHK_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

struct ogNitakuMgr;
struct TypingTextMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x10C.
 */
struct ogScrMemChkMgr {

	/**
	 * @brief TODO
	 */
	enum MemChkStatus {
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

	u8 _00[0x10C]; // _00, unknown
};

} // namespace zen

#endif
