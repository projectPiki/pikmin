#include "zen/ogMessage.h"
#include "DebugLog.h"
#include "Font.h"
#include "P2D/Graph.h"
#include "P2D/Picture.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
#include "VersionGroups.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "zen/DrawCommon.h"
#include "zen/ogSub.h"

#if defined(VERSION_PIKIDEMO) // these tables aren't here in demo
#else
static s16 sjis_convert_table[0x258] ATTRIBUTE_ALIGN(32) = {
	0,     0x118, 0x119, 0xC,   0xE,   0x60,  0x1A,  0x1B,  0x1F,  0x1,   0x2,   0,     0,     0,     0,     0x3E,  0,     0,     0,
	0,     0,     0,     0,     0,     0x123, 0,     0,     0xD,   0xD,   0xD,   0xF,   0x3C,  0x11A, 0,     0,     0x117, 0,     0x7,
	0x7,   0x2,   0x2,   0x8,   0x9,   0x0,   0,     0x3B,  0x3D,  0,     0,     0,     0,     0,     0,     0x11F, 0x120, 0,     0,
	0,     0,     0xB,   0xD,   0,     0,     0,     0,     0x1D,  0,     0x1C,  0x1E,  0,     0,     0,     0,     0,     0,     0,
	0x7,   0x2,   0,     0,     0x4,   0,     0,     0x5,   0x3,   6,     0xA,   0x20,  0,     0,     0x122, 0,     0x121, 0,     0,
	0,     0,     0x5C,  0,     0,     0,     0,     0,     0,     0x11C, 0x11B, 0x11E, 0x11D, 0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     3,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0x10,  0x11,  0x12,  0x13,  0x14,  0x15,  0x16,  0x17,  0x18,  0x19,  0,     0,     0,     0,
	0,     0,     0,     0x21,  0x22,  0x23,  0x24,  0x25,  0x26,  0x27,  0x28,  0x29,  0x2A,  0x2B,  0x2C,  0x2D,  0x2E,  0x2F,  0x30,
	0x31,  0x32,  0x33,  0x34,  0x35,  0x36,  0x37,  0x38,  0x39,  0x3A,  0,     0,     0,     0,     0,     0,     0,     0x41,  0x42,
	0x43,  0x44,  0x45,  0x46,  0x47,  0x48,  0x49,  0x4A,  0x4B,  0x4C,  0x4D,  0x4E,  0x4F,  0x50,  0x51,  0x52,  0x53,  0x54,  0x55,
	0x56,  0x57,  0x58,  0x59,  0x5A,  0,     0,     0,     0,     0x61,  0x62,  0x63,  0x64,  0x65,  0x66,  0x67,  0x68,  0x69,  0x6A,
	0x6B,  0x6C,  0x6D,  0x6E,  0x6F,  0x70,  0x71,  0x72,  0x73,  0x74,  0x75,  0x76,  0x77,  0x78,  0x79,  0x7A,  0x7B,  0x7C,  0x7D,
	0x7E,  0x7F,  0x80,  0x81,  0x82,  0x83,  0x84,  0x85,  0x86,  0x87,  0x88,  0x89,  0x8A,  0x8B,  0x8C,  0x8D,  0x8E,  0x8F,  0x90,
	0x91,  0x92,  0x93,  0x94,  0x95,  0x96,  0x97,  0x98,  0x99,  0x9A,  0x9B,  0x9C,  0x9D,  0x9E,  0x9F,  0xA0,  0xA1,  0xA2,  0xA3,
	0xA4,  0xA5,  0xA6,  0xA7,  0xA8,  0xA9,  0xAA,  0xAB,  0xAC,  0xAD,  0xAE,  0xAF,  0xB0,  0xB1,  0xB2,  0xB3,  0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0xC1,
	0xC2,  0xC3,  0xC4,  0xC5,  0xC6,  0xC7,  0xC8,  0xC9,  0xCA,  0xCB,  0xCC,  0xCD,  0xCE,  0xCF,  0xD0,  0xD1,  0xD2,  0xD3,  0xD4,
	0xD5,  0xD6,  0xD7,  0xD8,  0xD9,  0xDA,  0xDB,  0xDC,  0xDD,  0xDE,  0xDF,  0xE0,  0xE1,  0xE2,  0xE3,  0xE4,  0xE5,  0xE6,  0xE7,
	0xE8,  0xE9,  0xEA,  0xEB,  0xEC,  0xED,  0xEE,  0xEF,  0xF0,  0xF1,  0xF2,  0xF3,  0xF4,  0xF5,  0xF6,  0xF7,  0xF8,  0xF9,  0xFA,
	0xFB,  0xFC,  0xFD,  0xFE,  0xFF,  0,     0x100, 0x101, 0x102, 0x103, 0x104, 0x105, 0x106, 0x107, 0x108, 0x109, 0x10A, 0x10B, 0x10C,
	0x10D, 0x10E, 0x10F, 0x110, 0x111, 0x112, 0x113, 0x114, 0x115, 0x116, 0x0,
};
#endif

// PAL changed exactly ONE character in this table and its an extremely specific instance of "・" that
// doesn't want to match  when copy-pasted from anywhere in the actual code (there seems to be dozens
// of "・"s in the shift-jis table and its using the wrong one  if you dont manually specify it)
static char kanji_convert_table[] ATTRIBUTE_ALIGN(32) = {
#if defined(VERSION_GPIP01_00)
	"日目時私未知星大地\x85\x20名前宇宙旅途中流墜落愛機号多失無残姿動一重迎教気猛毒酸素含生命維持装置限度修復考船探検奇妙物体待立上何械観察"
	"芽光放"
#else
	"日目時私未知星大地横名前宇宙旅途中流墜落愛機号多失無残姿動一重迎教気猛毒酸素含生命維持装置限度修復考船探検奇妙物体待立上何械観察芽光放"
#endif
	"思試引抜植見害好野菜呼投反応操作回転今来倒取増殖母彼態不議少能力調必要興味集団合行習性利用繰希望灯近押解散隊列記録画面安心幸運事離陸可"
	"飛明捜索後入森昨出下全滅種掴切色同赤注意深口部分他違黄帰特穴掘石割内高収個範囲没太陽仕暗去食発荷伝質超科学結晶除汚移永久燃料電済位確認"
	"間叩当最激本妻子供顔浮射線遠外音鳴役息座娘元空欠嵐強噴脱速加費良家計衝撃吸亜複通雑場所父親人美咲別感続金属品買理遊泳腰晩庫以状実組異常"
	"聞快配乗約束尾現念故終巻頭土製値打夜楽身向算果焼便成功驚緒暮付借戻昇窓広満帯始惑遭難協者郷長眠油断服界達非送闘左表示族存在徴耳奥開洞窟"
	"青会視手足小水自助消原周辺映十字効率眼定降樹海備早就湿源朝進完練寝指正直勇初恐景員険話情報数変化与方整奮新道恵単判葉花仲然獲冒破壊敵圏"
	"平歩炎天卵軟接触至死攻駆繁栄巨丸呑弾半折胞吐連錯乱振払堅夢追昼怖揺丈先止胴弱点簡甲羅岩量込捕透核法怒奴等構厄介橋苦労系貝真珠価罠禁巣風"
	"造勢戦襲言遮和厳密頂着休年昔想像響返白敏再還我懸草誰工月司髪毛細番予殊影過関係誇育腹次矢窒寸覚覗屋忘血航誌亡泉夕使期敗容制挿読扱説書閉"
	"績匹累替角更包獰吹遇悪似謎守有軽様告武器危崩順形養境届両衛貫渦砕淵裂凡義務貴毎賊突測庭円翔魅夫秩低爆住笑"
};

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void searchKanjiCode(u16 id)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("OgMessageSection")

/*
 * --INFO--
 * Address:	8018BB50
 * Size:	000048
 */
s16 zen::ogScrMessageMgr::SearchTopPage(int a)
{
	for (s16 i = 0; i < mPageInfoEntryCount; i++) {
		if (mPageInfos[i] && mPageInfos[i]->mMsgUniqueId == a) {
			return i;
		}
	}
	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void zen::ogScrMessageMgr::setMessagePage(int page)
{
	mCurrPageNum = page;
	setPageInfoSub();
	PRINT("setMessagePage(%d)\n", page);
	resetPage();
}

/*
 * --INFO--
 * Address:	8018BB98
 * Size:	00011C
 */
void zen::ogScrMessageMgr::resetPage()
{
	if (mIsInitialPageLoad) {
		mTextAnimationProgress = -0.25f;
		mIsInitialPageLoad     = false;
	} else {
		mTextAnimationProgress = -0.5f;
	}
	mPageDrawDelayTimer    = 5;
	mNextPaneId            = 0;
	mCurrentTextCharOffset = 0;
	mActivePaneId          = -1;
	if (mPagePaneList[0] == 0) {
		mCursorTargetX = 0;
		mCursorTargetY = 0;
	} else {
		mCursorTargetX = mPagePaneList[0]->getPosH();
		mCursorTargetY = mPagePaneList[0]->getPosV();
	}
	mCursorPane->move(mCursorTargetX, mCursorTargetY);
	mIsTextPausedByTag   = false;
	mIsPageFullyRevealed = false;

	for (int i = 0; i < mActivePaneCount; i++) {
		switch (mPagePaneList[i]->getTypeID()) {
		case PANETYPE_TextBox:
			((P2DTextBox*)mPagePaneList[i])->setString("");
			break;
		case PANETYPE_Picture:
			mPagePaneList[i]->hide();
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	8018BCB4
 * Size:	000080
 */
void zen::ogScrMessageMgr::start(int page)
{
	mState           = STATE_StartDelay;
	mStateEntryDelay = 3;
	mScreenFadeTimer = 0.0f;
	mButtonPromptPane->hide();
	mIsInitialPageLoad = true;
	if (page >= 0) {
		setMessagePage(SearchTopPage(page));
	}
}

/*
 * --INFO--
 * Address:	8018BD34
 * Size:	00005C
 */
void zen::ogScrMessageMgr::setPage(int page)
{
	if (page < 0) {
		page = 0;
	}
	if (page >= mPageInfoEntryCount) {
		page = 0;
	}
	setMessagePage(page);
}

/*
 * --INFO--
 * Address:	8018BD90
 * Size:	000058
 */
void zen::ogScrMessageMgr::nextPage()
{
	int id = mCurrPageNum;
	id++;
	if (id >= mPageInfoEntryCount) {
		id = 0;
	}
	setMessagePage(id);
}

/*
 * --INFO--
 * Address:	8018BDE8
 * Size:	000054
 */
void zen::ogScrMessageMgr::backPage()
{
	int id = mCurrPageNum;
	id--;
	if (id < 0) {
		id = mPageInfoEntryCount - 1;
	}
	setMessagePage(id);
}

/*
 * --INFO--
 * Address:	8018BE3C
 * Size:	0001DC
 */
s16 zen::ogScrMessageMgr::makePageInfo(char*** data)
{
	int idx = 0;
	for (int i = 0; i < 0x99; i++) {
		int a = 0;
		if (!data[i]) {
			break;
		}
		while (true) {
			char* str = data[i][a];
			if (strcmp(str, "END") == 0) {
				break;
			}

			mPageInfos[idx]           = new TextInfoType;
			TextInfoType* info        = mPageInfos[idx];
			info->mMsgUniqueId        = i;
			info->mScreenResourcePath = str;
			a++;
			idx++;
		}

		for (int j = 1; j <= a; j++) {
			mPageInfos[idx - j]->mMsgSegmentCount = a;
		}
	}

	return idx;
}

#if defined(VERSION_PIKIDEMO) // these two functions are straight up not in demo
#else
/*
 * --INFO--
 * Address:	8018C018
 * Size:	00018C
 */
void zen::ogScrMessageMgr::cnvSingleMulti(char* str)
{
	char tag[PATH_MAX];
	char strTmp[1024];
	char* strAfterEsc = strchr(str, 0x1B); // esc character
	strTmp[0]         = 0;
	if (!strAfterEsc) {
		return;
	}

	int len = strAfterEsc - str;
	if (len > 0) {
		strncpy(strTmp, str, len);
		strTmp[len] = 0;
	}

	strAfterEsc++;
	if (strAfterEsc[0] == 'D') {
		strAfterEsc++;
		u8 digit = strAfterEsc[0] - '0';
		if (digit == 0 || digit > 5) {
			return;
		}

		int num = getSpecialNumber(digit);
		strAfterEsc++;
		if (strAfterEsc[0] != '[') {
			return;
		}

		strAfterEsc++;
		char* tmp;
		if (num == 1) {
			char* closeBracket = strstr(strAfterEsc, "]");
			len                = closeBracket - strAfterEsc;
			if (len <= 0 || len > 255) {
				return;
			}

			strncpy(tag, strAfterEsc, len);
			tag[len] = 0;
			strcat(strTmp, tag);
			tmp = strstr(closeBracket + 1, "]") + 1;

		} else {
			char* tagStart = strstr(strAfterEsc, "[");
			char* tagEnd   = strstr(tagStart + 1, "]");
			len            = tagEnd - (tagStart + 1);
			if (len <= 0 || len > 255) {
				return;
			}
			strncpy(tag, tagStart + 1, len);
			tag[len] = 0;
			strcat(strTmp, tag);
			tmp = tagEnd + 1;
		}
		strcat(strTmp, tmp);
		strcpy(str, strTmp);
		strAfterEsc = str;
	}

	cnvSingleMulti(strAfterEsc);
	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	8018C1A4
 * Size:	000184
 */
void zen::ogScrMessageMgr::cnvButtonIcon(char* str)
{

	PRINT("-------------- cnvButtonIcon ----------------\n");
	if (str[0] == 0) {
		return;
	}

	char* tmp = strchr(str, 0x1B); // pointer to esc character
	if (!tmp) {
		return;
	}
	char c = tmp[1];
	if (c == 0) {
		return;
	}
	char tc1[4];
	tc1[0]     = c;
	tc1[1]     = 0;
	char* data = strchr(&mButtonTagChars[0], c);
	PRINT("tc1 = \'%s\' \n", tc1);
	int len = 2;
	if (data) {
		int offset = data - mButtonTagChars;
		if (offset < 8) {
			char* a = &mButtonTagIconStrings[2 * offset];
			char tmp1[4];
			tmp1[0] = a[0];
			tmp1[1] = a[1];
			tmp1[2] = 0;
			char tmp2[4];
			tmp2[0] = 0x1B; // esc character
			tmp2[1] = 0;

			char buf1[PATH_MAX];
#if defined(VERSION_GPIP01_00)
			sprintf(buf1, "%sCC[%s]%s%sCC[%s]", tmp2, mButtonMarkupColours[offset], tmp1, tmp2, mDefaultButtonMarkupColour);
#else
			sprintf(buf1, "%sFX[32]%sFY[28]%sCC[%s]%s%sCC[%s]%sFX[24]%sFY[24]", tmp2, tmp2, tmp2, mButtonMarkupColours[offset], tmp1, tmp2,
			        mDefaultButtonMarkupColour, tmp2, tmp2);
#endif
			len = strlen(buf1);
			char buf2[1024];
			sprintf(buf2, "%s%s", buf1, tmp + 2);
			sprintf(tmp, "%s", buf2);
			PRINT("Button \'%s\'\n", tmp);
		}
	} else if (c == 'm') {
		// i assume this is a shift-jis character
		char terminator[3] = { 0x92, 0x6E, 0x00 };
		tmp[0]             = terminator[0];
		tmp[1]             = terminator[1];
	}
	cnvButtonIcon(tmp + len);
}
#endif

/*
 * --INFO--
 * Address:	8018C328
 * Size:	000234
 */
void zen::ogScrMessageMgr::setPageInfoSub()
{
	TextInfoType* info = mPageInfos[mCurrPageNum];
	if (!info) {
		PRINT("========== ERR!!! PageInfo[%d] is NULL !!! ==========\n", mCurrPageNum);
		return;
	}
	int old = gsys->getHeapNum();
	if (gsys->getHeap(SYSHEAP_Message)->mIsActive) {
		gsys->setHeap(SYSHEAP_Message);
		gsys->resetHeap(SYSHEAP_Message, 2);
	}
	mCurrentScreen = new P2DScreen;
	mCurrentScreen->set(info->mScreenResourcePath, true, true, true);
	P2DPaneLibrary::makeResident(mCurrentScreen);
	mPageDrawDelayTimer = 5;
	PRINT("*********************************\n");
	PRINT("*                               *\n");
	PRINT("*   makeResident OGAWA          *\n");
	PRINT("*                               *\n");
	PRINT("*********************************\n");
	mActivePaneCount = 0;

	char name[8];
	STACK_PAD_VAR(1);
	for (int i = 0; i < 20; i++) {
		sprintf(name, "tx%02d", i);

		int id            = mActivePaneCount;
		mPagePaneList[id] = mCurrentScreen->search(P2DPaneLibrary::makeTag(name), false);

		if (mPagePaneList[id]) {
			switch (mPagePaneList[id]->getTypeID()) {
			case PANETYPE_TextBox:
#if defined(VERSION_PIKIDEMO)
				mProcessedTextBoxStrings[id] = ((P2DTextBox*)mPagePaneList[id])->getString();
#else
				sprintf(mRawPageTextBoxStrings[id], "%s", ((P2DTextBox*)mPagePaneList[id])->getString());
				mProcessedTextBoxStrings[id] = mRawPageTextBoxStrings[id];
				cnvSingleMulti(mProcessedTextBoxStrings[id]);
				cnvButtonIcon(mProcessedTextBoxStrings[id]);
#endif
				((P2DTextBox*)mPagePaneList[id])->setString("");
				id++;
				break;

			case PANETYPE_Picture:
				mPagePaneList[id]->hide();
				id++;
				break;
			}
		}
		mActivePaneCount = id;
	}

	gsys->setHeap(old);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void zen::ogScrMessageMgr::ReadAllScreen()
{
	PRINT("ReadAllScreen() start\n");
	for (int i = 0; i < mPageInfoEntryCount; i++) {
		mCurrPageNum = i;
		setPageInfoSub();
	}
	PRINT("ReadAllScreen() end\n");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018C55C
 * Size:	000048
 */
void zen::ogScrMessageMgr::MakeAndSetPageInfo(char*** data)
{
	mPageInfoEntryCount = makePageInfo(data);
	setMessagePage(0);
}

/*
 * --INFO--
 * Address:	8018C5A4
 * Size:	0002A4
 */
zen::ogScrMessageMgr::ogScrMessageMgr(char* path)
{
	mBaseScreen = new P2DScreen;
	mBaseScreen->set(path, true, true, true);
	P2DPaneLibrary::makeResident(mBaseScreen);
	mAlwaysShowNextPrompt = false;
	mCtrlTagMgr           = new ogMsgCtrlTagMgr;
	mPageDrawDelayTimer   = 5;
	Texture* tex          = gsys->loadTexture("bigFont.bti", true);
	mFont                 = new Font;
	mFont->setTexture(tex, 21, 42);
	mCurrentScreen            = nullptr;
	mState                    = STATE_Inactive;
	mIsUiInputDisabled        = false;
	mHasDrawOccurredThisFrame = false;
	mCurrPageNum              = 0;
	mCurrentMessageId         = 0;
	mCursorPane               = (P2DPicture*)mBaseScreen->search('curs', true);
	mButtonPromptPane         = (P2DPicture*)mBaseScreen->search('a_bt', true);
	mCursorBlinker            = new setTenmetuAlpha(mCursorPane, 0.5f);
	mButtonPromptBlinker      = new setTenmetuAlpha(mButtonPromptPane, 1.0f);
	mCursorBlinker->start();
	mButtonPromptBlinker->start();
	mButtonPromptPane->hide();
	mIsTextPausedByTag     = false;
	mIsPageFullyRevealed   = false;
	mTextAnimationProgress = 0.0f;
	mCurrentTextCharOffset = 0;
	mNextPaneId            = 0;
	mActivePaneId          = -1;
#if defined(VERSION_PIKIDEMO)
#else
	sprintf(mButtonTagChars, "abcxyzlr");
	sprintf(mButtonTagIconStrings, "日目時私未知星大地横名");
	mDefaultButtonMarkupColour = "b4ffff";
	mButtonMarkupColours[0]    = "00ff00";
	mButtonMarkupColours[1]    = "ff0000";
	mButtonMarkupColours[2]    = "ffff00";
	mButtonMarkupColours[3]    = "808080";
	mButtonMarkupColours[4]    = "808080";
	mButtonMarkupColours[5]    = "4040ff";
	mButtonMarkupColours[6]    = "808080";
	mButtonMarkupColours[7]    = "808080";
#endif
	P2DPaneLibrary::setFamilyAlpha(mBaseScreen, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void zen::ogScrMessageMgr::setScreenAlpha(u8 alpha)
{
	P2DPaneLibrary::setFamilyAlpha(mCurrentScreen, alpha);
	P2DPaneLibrary::setFamilyAlpha(mBaseScreen, alpha);
}

/*
 * --INFO--
 * Address:	8018C848
 * Size:	000170
 */
void zen::ogScrMessageMgr::dispAll()
{
	mActivePaneId = -1;

	for (int i = 0; i < mActivePaneCount; i++) {
		switch (mPagePaneList[i]->getTypeID()) {
		case PANETYPE_Picture:
			P2DPicture* pic = (P2DPicture*)mPagePaneList[i];
			pic->show();
			P2DPaneLibrary::setFamilyAlpha(pic, 255);
			pic->initWhite();
			pic->initBlack();
			break;
		case PANETYPE_TextBox:
			strcpy(mFormattedDisplayStrings[i], mProcessedTextBoxStrings[i]);
			cnvSpecialNumber(mFormattedDisplayStrings[i]);
			((P2DTextBox*)mPagePaneList[i])->setString(mFormattedDisplayStrings[i]);
			mActivePaneId = i;
			break;
		}
	}

	mNextPaneId            = mActivePaneCount - 1;
	mIsTextPausedByTag     = true;
	mIsPageFullyRevealed   = true;
	mTextAnimationProgress = 100.0f;
	if (mIsUiInputDisabled) {
		mCursorPane->hide();
	}
	if (mActivePaneId >= 0) {
		setCursorXY((P2DTextBox*)mPagePaneList[mActivePaneId]);
	}
}

/*
 * --INFO--
 * Address:	8018C9B8
 * Size:	000014
 */
void zen::ogScrMessageMgr::fadeOut()
{
	mScreenFadeTimer = 0.0f;
	mState           = STATE_FadingOut;
}

/*
 * --INFO--
 * Address:	8018C9CC
 * Size:	00057C
 */
zen::ogScrMessageMgr::MessageStatus zen::ogScrMessageMgr::update(Controller* input)
{
	if (mState == STATE_Inactive) {
		return mState;
	}

	if (mState == STATE_TransitionToInactive) {
		mState = STATE_Inactive;
		return mState;
	}

	if (mState == STATE_StartDelay) {
		mStateEntryDelay--;
		if (mStateEntryDelay <= 0) {
			mScreenFadeTimer = 0.0f;
			mState           = STATE_FadingIn;
		}
		return mState;
	}

	TextInfoType* info = mPageInfos[mCurrPageNum];
	if (!info) {
		PRINT("ogScrMessageMgr::update() ERROR !!!  tutorial_num = %d\n", mCurrPageNum);
		return mState;
	}

	mBaseScreen->update();

	if (!mIsUiInputDisabled) {
		mCursorBlinker->update();
	}

	mCurrentScreen->update();

	if (mState == STATE_FadingIn) {
		mScreenFadeTimer += gsys->getFrameTime();
		if (mScreenFadeTimer >= 0.25f) {
			mState = STATE_ActiveDisplay;
		} else {
			setScreenAlpha((u8)(255.0f * mScreenFadeTimer / 0.25f));
		}
		return mState;
	}

	if (mState == STATE_FadingOut) {
		mScreenFadeTimer += gsys->getFrameTime();
		if (mScreenFadeTimer >= 0.25f) {
			mState = STATE_TransitionToInactive;
		} else {
			setScreenAlpha((u8)((0.25f - mScreenFadeTimer) * 255.0f / 0.25f));
		}
		return mState;
	}

	if (!mIsPageFullyRevealed && mIsTextPausedByTag) {
		mTextAnimationProgress = -0.6864f;
		mCurrentTextCharOffset = 0;
		mNextPaneId++;
		if (mNextPaneId >= mActivePaneCount) {
			mNextPaneId          = mActivePaneCount - 1;
			mIsPageFullyRevealed = true;
		}
		mIsTextPausedByTag = false;
	}

	if (mActivePaneId >= 0) {
		setCursorXY((P2DTextBox*)mPagePaneList[mActivePaneId]);
		mCursorPane->move(mCursorTargetX, mCursorTargetY);
	}

	if (mIsPageFullyRevealed) {
		if (info->mMsgSegmentCount > 1 || mAlwaysShowNextPrompt) {
			mButtonPromptPane->show();
			mButtonPromptBlinker->update();
		}

		if (!mIsUiInputDisabled && input->keyClick(KBBTN_A | KBBTN_B)) {
			mCurrentMessageId++;
			if (mCurrentMessageId >= info->mMsgSegmentCount) {
				mCurrentMessageId = 0;
				mScreenFadeTimer  = 0.0f;
				mState            = STATE_FadingOut;
#if defined(VERSION_PIKIDEMO)
				SeSystem::playSysSe(JACSYS_MessageClose); // this is the wrong enum, devs.
#else
				SeSystem::playSysSe(SYSSE_MESSAGE_CLOSE);
#endif
				PRINT("END MESSAGE!\n");
				return mState;
			}
			nextPage();
		}
		return mState;
	}

	if (!mIsUiInputDisabled && input->keyClick(KBBTN_B)) {
		dispAll();
		return mState;
	}

	if (!mIsPageFullyRevealed && mNextPaneId < mActivePaneCount) {
		f32 speed = 1.0f;
		if (input->keyDown(KBBTN_A)) {
			speed = 5.0f;
		}
		mTextAnimationProgress += gsys->getFrameTime() * speed;

		switch (mPagePaneList[mNextPaneId]->getTypeID()) {
		case PANETYPE_Picture:
			P2DPicture* pic = (P2DPicture*)mPagePaneList[mNextPaneId];
			pic->show();
			if (mTextAnimationProgress < 1.0f) {
				u8 alpha = 0;
				if (mTextAnimationProgress > 0.0f) {
					alpha = 255.0f * mTextAnimationProgress;
				}
				P2DPaneLibrary::setFamilyAlpha(pic, alpha);
			} else {
				mTextAnimationProgress = -0.0f; // ? guess we're making minus zeros now
				mCurrentTextCharOffset = 0;
				mNextPaneId++;
			}
			break;

		case PANETYPE_TextBox:
#if defined(VERSION_PIKIDEMO)
			if (mTextAnimationProgress >= 0.04f) {
#else
			if (mTextAnimationProgress >= 0.029639998f) {
#endif
				mActivePaneId          = mNextPaneId;
				mTextAnimationProgress = 0.0f;

				f32 a;
				if (mCtrlTagMgr->CheckCtrlTag(mProcessedTextBoxStrings[mNextPaneId], &mCurrentTextCharOffset, &a)) {
					mIsTextPausedByTag = true;
				}

				if (a > 0.0f) {
					mTextAnimationProgress = -a;
				}
				strncpy(mFormattedDisplayStrings[mNextPaneId], mProcessedTextBoxStrings[mNextPaneId], mCurrentTextCharOffset);
				mFormattedDisplayStrings[mNextPaneId][mCurrentTextCharOffset] = 0;
				cnvSpecialNumber(mFormattedDisplayStrings[mNextPaneId]);
				static_cast<P2DTextBox*>(mPagePaneList[mNextPaneId])->setString(mFormattedDisplayStrings[mNextPaneId]);
			}
			mButtonPromptPane->hide();
			break;
		}
	}

	if (mNextPaneId >= mActivePaneCount) {
		mIsPageFullyRevealed = true;
	}

	return mState;
}

/*
 * --INFO--
 * Address:	8018CF48
 * Size:	000104
 */
void zen::ogScrMessageMgr::draw(Graphics& gfx)
{
	if (mState != STATE_Inactive && mState != STATE_StartDelay) {
		GXColor color = { 0, 0, 0, 0 };
		GXSetFog(GX_FOG_NONE, 0.0f, 1.0f, 0.1f, 1.0f, color);
		GXSetFogRangeAdj(GX_FALSE, 0, nullptr);
		P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
		graf.setPort();
		mBaseScreen->draw(0, 0, &graf);
		if (mPageDrawDelayTimer > 0) {
			mPageDrawDelayTimer--;
			mHasDrawOccurredThisFrame = false;
		} else {
			mCurrentScreen->draw(0, 0, &graf);
			mHasDrawOccurredThisFrame = true;
		}
	}
}
