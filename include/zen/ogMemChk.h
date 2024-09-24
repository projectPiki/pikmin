#ifndef _ZEN_OGMESSAGE_H
#define _ZEN_OGMESSAGE_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

struct ogNitakuMgr;
struct TypingTextMgr;

/**
 * @brief TODO
 */
struct ogScrMemChkMgr {
	ogScrMemChkMgr();

	void StatusCheck();
	void setPCtex(TypingTextMgr*);
	void DispYesNo(bool);
	void DispAcup(bool);
	void start();
	void DebugStart(int);
	void update(Controller*);
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
	void checkTypingAll();
	void checkErrNitaku(zen::ogNitakuMgr*, Controller*);
	void setNoCard();

	// TODO: members
};

} // namespace zen

#endif
