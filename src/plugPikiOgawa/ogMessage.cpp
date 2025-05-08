#include "zen/ogMessage.h"
#include "zen/DrawCommon.h"
#include "zen/ogSub.h"
#include "P2D/Picture.h"
#include "P2D/Graph.h"
#include "P2D/TextBox.h"
#include "sysNew.h"
#include "Font.h"
#include "DebugLog.h"

char kanji_convert_table[] = {
	"日目時私未知星大地横名前宇宙旅途中流墜落愛機号多失無残姿動一重迎教気猛毒酸素含生命維持装置限度修復考船探検奇妙物体待立上何械観察芽光放"
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
DEFINE_ERROR()

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
	int page = 0;
	while (_4F0 < page) {
		if (mPageInfos[page] && mPageInfos[page]->_04 == a) {
			return page;
		}
		page++;
	}
	return 0;

	FORCE_DONT_INLINE;
	/*
	.loc_0x0:
	  lha       r5, 0x4F0(r3)
	  li        r7, 0
	  b         .loc_0x34

	.loc_0xC:
	  lwz       r6, 0x1C(r3)
	  cmplwi    r6, 0
	  beq-      .loc_0x2C
	  lha       r0, 0x4(r6)
	  cmpw      r0, r4
	  bne-      .loc_0x2C
	  mr        r3, r7
	  blr

	.loc_0x2C:
	  addi      r3, r3, 0x4
	  addi      r7, r7, 0x1

	.loc_0x34:
	  extsh     r0, r7
	  cmpw      r0, r5
	  blt+      .loc_0xC
	  li        r3, 0
	  blr
	*/
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
	if (_54F4) {
		_4D4  = -0.25f;
		_54F4 = false;
	} else {
		_4D4 = -0.5f;
	}
	_54F2 = 5;
	_4EA  = 0;
	_4E8  = 0;
	_4EC  = -1;
	if (_54FC[0] == 0) {
		_4E4 = 0;
		_4E6 = 0;
	} else {
		_4E4 = _54FC[0]->getPosH();
		_4E6 = _54FC[0]->getPosV();
	}
	_0C->move(_4E4, _4E6);
	_4DD = false;
	_4DC = false;

	for (int i = 0; i < _A59C; i++) {
		switch (_54FC[i]->getTypeID()) {
		case PANETYPE_TextBox:
			((P2DTextBox*)_54FC[i])->setString("");
			break;
		case PANETYPE_Picture:
			_54FC[i]->hide();
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
	_4CC = 1;
	_4E2 = 3;
	_4D8 = 0.0f;
	_10->hide();
	_54F4 = 1;
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
	if (page >= _4F0) {
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
	if (id >= _4F0) {
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
		id = _4F0 - 1;
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
	for (int i = 0; i < 0x99; i++) { }
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r22, 0x18(r1)
	  addi      r26, r3, 0
	  addi      r31, r4, 0
	  addi      r30, r26, 0
	  li        r29, 0
	  li        r28, 0

	.loc_0x24:
	  lwz       r0, 0x0(r31)
	  li        r27, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x1C4
	  addi      r23, r30, 0
	  extsh     r25, r28
	  li        r24, 0

	.loc_0x40:
	  lwz       r3, 0x0(r31)
	  addi      r4, r13, 0xD24
	  lwzx      r22, r3, r24
	  mr        r3, r22
	  bl        0x8D338
	  cmpwi     r3, 0
	  beq-      .loc_0x8C
	  li        r3, 0x8
	  bl        -0x144E98
	  stw       r3, 0x1C(r23)
	  addi      r24, r24, 0x4
	  addi      r27, r27, 0x1
	  lwz       r3, 0x1C(r23)
	  addi      r23, r23, 0x4
	  addi      r30, r30, 0x4
	  sth       r25, 0x4(r3)
	  addi      r29, r29, 0x1
	  stw       r22, 0x0(r3)
	  b         .loc_0x40

	.loc_0x8C:
	  cmpwi     r27, 0x1
	  li        r3, 0x1
	  blt-      .loc_0x1B4
	  cmpwi     r27, 0x8
	  subi      r4, r27, 0x8
	  ble-      .loc_0x180
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0x1
	  mtctr     r0
	  extsh     r0, r27
	  blt-      .loc_0x180

	.loc_0xBC:
	  sub       r4, r29, r3
	  rlwinm    r4,r4,2,0,29
	  addi      r5, r4, 0x1C
	  addi      r4, r3, 0x1
	  lwzx      r5, r26, r5
	  sub       r4, r29, r4
	  rlwinm    r4,r4,2,0,29
	  sth       r0, 0x6(r5)
	  addi      r5, r4, 0x1C
	  addi      r4, r3, 0x2
	  lwzx      r5, r26, r5
	  sub       r4, r29, r4
	  rlwinm    r4,r4,2,0,29
	  sth       r0, 0x6(r5)
	  addi      r5, r4, 0x1C
	  addi      r4, r3, 0x3
	  lwzx      r5, r26, r5
	  sub       r4, r29, r4
	  rlwinm    r4,r4,2,0,29
	  sth       r0, 0x6(r5)
	  addi      r5, r4, 0x1C
	  addi      r4, r3, 0x4
	  lwzx      r5, r26, r5
	  sub       r4, r29, r4
	  rlwinm    r4,r4,2,0,29
	  sth       r0, 0x6(r5)
	  addi      r5, r4, 0x1C
	  addi      r4, r3, 0x5
	  lwzx      r5, r26, r5
	  sub       r4, r29, r4
	  rlwinm    r4,r4,2,0,29
	  sth       r0, 0x6(r5)
	  addi      r5, r4, 0x1C
	  addi      r4, r3, 0x6
	  lwzx      r5, r26, r5
	  sub       r4, r29, r4
	  rlwinm    r4,r4,2,0,29
	  sth       r0, 0x6(r5)
	  addi      r5, r4, 0x1C
	  addi      r4, r3, 0x7
	  lwzx      r5, r26, r5
	  sub       r4, r29, r4
	  rlwinm    r4,r4,2,0,29
	  sth       r0, 0x6(r5)
	  addi      r4, r4, 0x1C
	  lwzx      r4, r26, r4
	  addi      r3, r3, 0x8
	  sth       r0, 0x6(r4)
	  bdnz+     .loc_0xBC

	.loc_0x180:
	  addi      r0, r27, 0x1
	  sub       r0, r0, r3
	  cmpw      r3, r27
	  mtctr     r0
	  extsh     r5, r27
	  bgt-      .loc_0x1B4

	.loc_0x198:
	  sub       r0, r29, r3
	  rlwinm    r4,r0,2,0,29
	  addi      r0, r4, 0x1C
	  lwzx      r4, r26, r0
	  addi      r3, r3, 0x1
	  sth       r5, 0x6(r4)
	  bdnz+     .loc_0x198

	.loc_0x1B4:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x99
	  addi      r31, r31, 0x4
	  blt+      .loc_0x24

	.loc_0x1C4:
	  extsh     r3, r29
	  lmw       r22, 0x18(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018C018
 * Size:	00018C
 */
void zen::ogScrMessageMgr::cnvSingleMulti(char* str)
{
	FORCE_DONT_INLINE;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x530(r1)
	  stmw      r27, 0x51C(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  li        r4, 0x1B
	  bl        0x8D11C
	  li        r28, 0
	  mr.       r29, r3
	  stb       r28, 0x14(r1)
	  beq-      .loc_0x178
	  sub.      r0, r29, r31
	  mr        r27, r0
	  ble-      .loc_0x58
	  addi      r4, r31, 0
	  addi      r5, r27, 0
	  addi      r3, r1, 0x14
	  bl        0x8D2B0
	  addi      r3, r1, 0x14
	  stbx      r28, r3, r27

	.loc_0x58:
	  lbzu      r0, 0x1(r29)
	  cmplwi    r0, 0x44
	  bne-      .loc_0x16C
	  lbz       r3, 0x1(r29)
	  subi      r0, r3, 0x30
	  rlwinm    r0,r0,0,24,31
	  mr.       r3, r0
	  beq-      .loc_0x178
	  cmplwi    r3, 0x5
	  ble-      .loc_0x84
	  b         .loc_0x178

	.loc_0x84:
	  bl        -0xBF80
	  lbz       r0, 0x2(r29)
	  cmplwi    r0, 0x5B
	  bne-      .loc_0x178
	  cmpwi     r3, 0x1
	  bne-      .loc_0xF8
	  addi      r3, r29, 0x3
	  addi      r4, r13, 0xD28
	  bl        0x8D02C
	  addi      r28, r3, 0
	  addi      r4, r29, 0x3
	  sub.      r29, r28, r4
	  ble-      .loc_0x178
	  cmpwi     r29, 0xFF
	  ble-      .loc_0xC4
	  b         .loc_0x178

	.loc_0xC4:
	  addi      r5, r29, 0
	  addi      r3, r1, 0x414
	  bl        0x8D230
	  addi      r4, r1, 0x414
	  li        r0, 0
	  stbx      r0, r4, r29
	  addi      r3, r1, 0x14
	  bl        0x8D1F0
	  addi      r3, r28, 0x1
	  addi      r4, r13, 0xD28
	  bl        0x8CFE4
	  addi      r4, r3, 0x1
	  b         .loc_0x154

	.loc_0xF8:
	  addi      r3, r29, 0x3
	  addi      r4, r13, 0xD2C
	  bl        0x8CFD0
	  addi      r28, r3, 0
	  addi      r3, r28, 0x1
	  addi      r4, r13, 0xD28
	  bl        0x8CFC0
	  addi      r29, r3, 0
	  addi      r4, r28, 0x1
	  sub.      r28, r29, r4
	  ble-      .loc_0x178
	  cmpwi     r28, 0xFF
	  ble-      .loc_0x130
	  b         .loc_0x178

	.loc_0x130:
	  addi      r5, r28, 0
	  addi      r3, r1, 0x414
	  bl        0x8D1C4
	  addi      r4, r1, 0x414
	  li        r0, 0
	  stbx      r0, r4, r28
	  addi      r3, r1, 0x14
	  bl        0x8D184
	  addi      r4, r29, 0x1

	.loc_0x154:
	  addi      r3, r1, 0x14
	  bl        0x8D178
	  addi      r3, r31, 0
	  addi      r4, r1, 0x14
	  bl        0x8D1DC
	  mr        r29, r31

	.loc_0x16C:
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  bl        .loc_0x0

	.loc_0x178:
	  lmw       r27, 0x51C(r1)
	  lwz       r0, 0x534(r1)
	  addi      r1, r1, 0x530
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018C1A4
 * Size:	000184
 */
void zen::ogScrMessageMgr::cnvButtonIcon(char* str)
{
	PRINT("-------------- cnvButtonIcon ----------------\n");
	if (str[0] && strchr(str, 0x1b)) {
		char c = str[1];
		if (c) {
			PRINT("tc1 = \'%s\' \n", str);
			char* data = strchr(&_A59E[0], c);
			int len    = 2;
			if (data) {
				int offset = (int)data - (int)&_A59E;
				if (offset < 8) {
					char buf[256];
					char buf2[1024];
					int a = 0x1b;
					sprintf(buf, "%sFX[32]%sFY[28]%sCC[%s]%s%sCC[%s]%sFX[24]%sFY[24]", &a, &a, &a, _A5D0[offset]);
					len = strlen(buf);
					sprintf(buf2, "%s%s", buf, str + 2);
					sprintf(str, "%s", buf2);
					PRINT("Button \'%s\'\n", str);
				}
			} else {
				if (c == 0x6d) {
					str[0] = 146;
					str[1] = 'n';
				}
			}
			cnvButtonIcon(str + len);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x548(r1)
	  stw       r31, 0x544(r1)
	  stw       r30, 0x540(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x53C(r1)
	  stw       r28, 0x538(r1)
	  lbz       r0, 0x0(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x164
	  addi      r3, r4, 0
	  li        r4, 0x1B
	  bl        0x8CF7C
	  mr.       r31, r3
	  beq-      .loc_0x164
	  lbz       r29, 0x1(r31)
	  cmplwi    r29, 0
	  beq-      .loc_0x164
	  addis     r3, r30, 0x1
	  addi      r4, r29, 0
	  subi      r3, r3, 0x5A62
	  bl        0x8CF58
	  cmplwi    r3, 0
	  li        r28, 0x2
	  beq-      .loc_0x130
	  addis     r11, r30, 0x1
	  subi      r0, r11, 0x5A62
	  sub       r0, r3, r0
	  cmpwi     r0, 0x8
	  bge-      .loc_0x158
	  rlwinm    r3,r0,1,0,30
	  crclr     6, 0x6
	  addis     r6, r3, 0x1
	  subi      r6, r6, 0x5A56
	  add       r6, r30, r6
	  lbz       r3, 0x0(r6)
	  addi      r5, r1, 0x528
	  rlwinm    r0,r0,2,0,29
	  stb       r3, 0x52C(r1)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x5C60
	  lbz       r6, 0x1(r6)
	  li        r3, 0x1B
	  li        r9, 0
	  stb       r6, 0x52D(r1)
	  add       r8, r11, r0
	  mr        r6, r5
	  stb       r3, 0x528(r1)
	  addi      r7, r5, 0
	  addi      r10, r5, 0
	  stb       r9, 0x52E(r1)
	  addi      r3, r1, 0x428
	  stb       r9, 0x529(r1)
	  addi      r9, r1, 0x52C
	  lwz       r0, -0x5A34(r11)
	  stw       r0, 0x8(r1)
	  stw       r5, 0xC(r1)
	  stw       r5, 0x10(r1)
	  lwz       r8, -0x5A30(r8)
	  bl        0x8A304
	  addi      r3, r1, 0x428
	  bl        0x8D170
	  addi      r28, r3, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x28
	  addi      r5, r1, 0x428
	  addi      r6, r31, 0x2
	  addi      r4, r13, 0xD30
	  bl        0x8A2E0
	  addi      r3, r31, 0
	  crclr     6, 0x6
	  addi      r5, r1, 0x28
	  addi      r4, r13, 0xD38
	  bl        0x8A2CC
	  b         .loc_0x158

	.loc_0x130:
	  cmplwi    r29, 0x6D
	  bne-      .loc_0x158
	  lhz       r3, -0x4F3C(r2)
	  lbz       r0, -0x4F3A(r2)
	  sth       r3, 0x24(r1)
	  stb       r0, 0x26(r1)
	  lbz       r0, 0x24(r1)
	  stb       r0, 0x0(r31)
	  lbz       r0, 0x25(r1)
	  stb       r0, 0x1(r31)

	.loc_0x158:
	  addi      r3, r30, 0
	  add       r4, r31, r28
	  bl        .loc_0x0

	.loc_0x164:
	  lwz       r0, 0x54C(r1)
	  lwz       r31, 0x544(r1)
	  lwz       r30, 0x540(r1)
	  lwz       r29, 0x53C(r1)
	  lwz       r28, 0x538(r1)
	  addi      r1, r1, 0x548
	  mtlr      r0
	  blr
	*/
}

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
	_54F8 = new P2DScreen;
	_54F8->set(info->_00, true, true, true);
	P2DPaneLibrary::makeResident(_54F8);
	_54F2 = 5;
	PRINT("*********************************\n");
	PRINT("*                               *\n");
	PRINT("*   makeResident OGAWA          *\n");
	PRINT("*                               *\n");
	PRINT("*********************************\n");
	_A59C = 0;

	for (int i = 0; i < 20; i++) {
		char name[4];
		sprintf(name, "tx%02d", i);

		int id    = _A59C;
		_54FC[id] = _54F8->search(P2DPaneLibrary::makeTag(name), false);

		if (_54FC[id]) {
			switch (_54FC[id]->getTypeID()) {
			case PANETYPE_TextBox:
				sprintf(_554C[id], "%s", ((P2DTextBox*)_54FC[id])->getString());
				_A54C[id] = _554C[id];
				cnvSingleMulti(_A54C[id]);
				cnvButtonIcon(_A54C[id]);
				id++;
				((P2DTextBox*)_54FC[id])->setString("");
				break;

			case PANETYPE_Picture:
				_54FC[id]->hide();
				id++;
				break;
			}
		}
		_A59C = id;
	}

	gsys->setHeap(old);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r24, 0x40(r1)
	  mr        r27, r3
	  lha       r0, 0x4D0(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r27, r0
	  lwz       r29, 0x1C(r3)
	  cmplwi    r29, 0
	  bne-      .loc_0x30
	  b         .loc_0x220

	.loc_0x30:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x6
	  lwz       r30, 0x194(r3)
	  bl        -0x14D344
	  lbz       r0, 0x1D(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x68
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x6
	  bl        -0x14D314
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x6
	  li        r5, 0x2
	  bl        -0x14D358

	.loc_0x68:
	  li        r3, 0xF8
	  bl        -0x145390
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xD4
	  addi      r24, r28, 0
	  addi      r3, r1, 0x28
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x2726C
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x28
	  addi      r3, r24, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x245F0
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r28)
	  li        r0, 0
	  stb       r0, 0xEC(r28)
	  stw       r0, 0xF0(r28)
	  stw       r0, 0xF4(r28)

	.loc_0xD4:
	  stw       r28, 0x54F8(r27)
	  li        r5, 0x1
	  li        r6, 0x1
	  lwz       r3, 0x54F8(r27)
	  li        r7, 0x1
	  lwz       r4, 0x0(r29)
	  bl        0x267EC
	  lwz       r3, 0x54F8(r27)
	  bl        0x33388
	  li        r0, 0x5
	  sth       r0, 0x54F2(r27)
	  addis     r31, r27, 0x1
	  li        r0, 0
	  sth       r0, -0x5A64(r31)
	  li        r29, 0

	.loc_0x110:
	  addi      r5, r29, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x38
	  addi      r4, r13, 0xD3C
	  bl        0x8A150
	  lwz       r3, 0x54F8(r27)
	  li        r5, 0
	  lbz       r0, 0x39(r1)
	  lwz       r12, 0x0(r3)
	  lbz       r4, 0x38(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x3A(r1)
	  lbz       r4, 0x3B(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  lha       r28, -0x5A64(r31)
	  or        r4, r4, r0
	  blrl
	  rlwinm    r0,r28,2,0,29
	  add       r24, r27, r0
	  addi      r26, r24, 0x54FC
	  stw       r3, 0x54FC(r24)
	  lwz       r4, 0x54FC(r24)
	  cmplwi    r4, 0
	  beq-      .loc_0x200
	  lhz       r0, 0x8(r4)
	  cmpwi     r0, 0x13
	  beq-      .loc_0x198
	  bge-      .loc_0x200
	  cmpwi     r0, 0x12
	  bge-      .loc_0x1EC
	  b         .loc_0x200

	.loc_0x198:
	  rlwinm    r3,r28,10,0,21
	  lwz       r5, 0x10C(r4)
	  addi      r25, r3, 0x554C
	  crclr     6, 0x6
	  add       r25, r27, r25
	  addi      r3, r25, 0
	  addi      r4, r13, 0xD38
	  bl        0x8A0BC
	  addis     r24, r24, 0x1
	  stw       r25, -0x5AB4(r24)
	  mr        r3, r27
	  lwzu      r4, -0x5AB4(r24)
	  bl        -0x4D8
	  mr        r3, r27
	  lwz       r4, 0x0(r24)
	  bl        -0x358
	  lwz       r3, 0x0(r26)
	  addi      r0, r13, 0xD20
	  addi      r28, r28, 0x1
	  stw       r0, 0x10C(r3)
	  b         .loc_0x200

	.loc_0x1EC:
	  lbz       r0, 0xC(r4)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r4)
	  addi      r28, r28, 0x1

	.loc_0x200:
	  addi      r29, r29, 0x1
	  extsh     r0, r28
	  cmpwi     r29, 0x14
	  sth       r0, -0x5A64(r31)
	  blt+      .loc_0x110
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r30
	  bl        -0x14D4DC

	.loc_0x220:
	  lmw       r24, 0x40(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void zen::ogScrMessageMgr::ReadAllScreen()
{
	PRINT("ReadAllScreen() start\n");
	for (int i = 0; i < _4F0; i++) {
		mCurrPageNum = i;
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
	_4F0         = makePageInfo(data);
	mCurrPageNum = 0;
	setPageInfoSub();
	resetPage();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  bl        -0x734
	  sth       r3, 0x4F0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  sth       r0, 0x4D0(r31)
	  bl        -0x25C
	  mr        r3, r31
	  bl        -0x9F4
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018C5A4
 * Size:	0002A4
 */
zen::ogScrMessageMgr::ogScrMessageMgr(char* path)
{
	mScreen = new P2DScreen;
	mScreen->set(path, true, true, true);
	P2DPaneLibrary::makeResident(mScreen);
	_4E0         = 0;
	mCtrlTagMgr  = new ogMsgCtrlTagMgr;
	_54F2        = 5;
	Texture* tex = gsys->loadTexture("bigFont.bti", true);
	mFont        = new Font;
	mFont->setTexture(tex, 21, 42);
	_54F8        = nullptr;
	_4CC         = -1;
	_4DE         = false;
	_4DF         = false;
	mCurrPageNum = 0;
	_4EE         = 0;
	_0C          = (P2DPicture*)mScreen->search('curs', true);
	_10          = (P2DPicture*)mScreen->search('a_bt', true);
	_14          = new setTenmetuAlpha(_0C, 0.5f);
	_18          = new setTenmetuAlpha(_10, 1.0f);
	_14->start();
	_18->start();
	_10->hide();
	_4DD = false;
	_4DC = false;
	_4D4 = 0.0f;
	_4E8 = 0;
	_4EA = 0;
	_4EC = -1;
	sprintf(_A59E, "abcxyzlr");
	sprintf(_A5AA, "日目時私未知星大地横名");
	_A5CC = "b4ffff";
	_A5D0 = "00ff00";
	_A5D4 = "ff0000";
	_A5D8 = "ffff00";
	_A5DC = "808080";
	_A5E0 = "808080";
	_A5E4 = "4040ff";
	_A5E8 = "808080";
	_A5EC = "808080";
	P2DPaneLibrary::setFamilyAlpha(mScreen, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void zen::ogScrMessageMgr::setScreenAlpha(u8 alpha)
{
	P2DPaneLibrary::setFamilyAlpha(_54F8, alpha);
	P2DPaneLibrary::setFamilyAlpha(mScreen, alpha);
}

/*
 * --INFO--
 * Address:	8018C848
 * Size:	000170
 */
void zen::ogScrMessageMgr::dispAll()
{
	_4EC = -1;

	for (int i = 0; i < _A59C; i++) {
		switch (_54FC[i]->getTypeID()) {
		case PANETYPE_Picture:
			P2DPicture* pic = (P2DPicture*)_54FC[i];
			pic->show();
			P2DPaneLibrary::setFamilyAlpha(pic, 255);
			pic->initWhite();
			pic->initBlack();
			break;
		case PANETYPE_TextBox:
			strcpy(_4F2[i], _A54C[i]);
			cnvSpecialNumber(_4F2[i]);
			((P2DTextBox*)_54FC[i])->setString(_4F2[i]);
			_4EC = i;
			break;
		}
	}

	_4EA = _A59C - 1;
	_4DD = true;
	_4DC = true;
	_4D4 = 100.0f;
	if (_4DE) {
		_0C->hide();
	}
	if (_4EC >= 0) {
		setCursorXY((P2DTextBox*)_54FC[_4EC]);
	}
}

/*
 * --INFO--
 * Address:	8018C9B8
 * Size:	000014
 */
void zen::ogScrMessageMgr::fadeOut()
{
	_4D8 = 0.0f;
	_4CC = 3;
}

/*
 * --INFO--
 * Address:	8018C9CC
 * Size:	00057C
 */
zen::ogScrMessageMgr::MessageStatus zen::ogScrMessageMgr::update(Controller* input)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x74(r1)
	  mr        r29, r3
	  lwz       r3, 0x4CC(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x30
	  b         .loc_0x560

	.loc_0x30:
	  cmpwi     r3, 0x4
	  bne-      .loc_0x48
	  li        r0, -0x1
	  stw       r0, 0x4CC(r29)
	  lwz       r3, 0x4CC(r29)
	  b         .loc_0x560

	.loc_0x48:
	  cmpwi     r3, 0x1
	  bne-      .loc_0x80
	  lha       r3, 0x4E2(r29)
	  subi      r0, r3, 0x1
	  sth       r0, 0x4E2(r29)
	  lha       r0, 0x4E2(r29)
	  cmpwi     r0, 0
	  bgt-      .loc_0x78
	  lfs       f0, -0x4F40(r2)
	  li        r0, 0x2
	  stfs      f0, 0x4D8(r29)
	  stw       r0, 0x4CC(r29)

	.loc_0x78:
	  lwz       r3, 0x4CC(r29)
	  b         .loc_0x560

	.loc_0x80:
	  lha       r0, 0x4D0(r29)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r29, r0
	  lwz       r31, 0x1C(r4)
	  cmplwi    r31, 0
	  bne-      .loc_0x9C
	  b         .loc_0x560

	.loc_0x9C:
	  lwz       r3, 0x0(r29)
	  bl        0x260E4
	  lbz       r0, 0x4DE(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xB8
	  lwz       r3, 0x14(r29)
	  bl        -0xD338

	.loc_0xB8:
	  lwz       r3, 0x54F8(r29)
	  bl        0x260C8
	  lwz       r0, 0x4CC(r29)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x138
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4D8(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4D8(r29)
	  lfs       f2, 0x4D8(r29)
	  lfs       f1, -0x4F2C(r2)
	  fcmpo     cr0, f2, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x100
	  li        r0, 0
	  stw       r0, 0x4CC(r29)
	  b         .loc_0x130

	.loc_0x100:
	  lfs       f0, -0x4F28(r2)
	  lwz       r3, 0x54F8(r29)
	  fmuls     f0, f0, f2
	  fdivs     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x68(r1)
	  lwz       r30, 0x6C(r1)
	  mr        r4, r30
	  bl        0x32DEC
	  lwz       r3, 0x0(r29)
	  mr        r4, r30
	  bl        0x32DE0

	.loc_0x130:
	  lwz       r3, 0x4CC(r29)
	  b         .loc_0x560

	.loc_0x138:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x1B0
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4D8(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4D8(r29)
	  lfs       f0, 0x4D8(r29)
	  lfs       f2, -0x4F2C(r2)
	  fcmpo     cr0, f0, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x174
	  li        r0, 0x4
	  stw       r0, 0x4CC(r29)
	  b         .loc_0x1A8

	.loc_0x174:
	  fsubs     f0, f2, f0
	  lfs       f1, -0x4F28(r2)
	  lwz       r3, 0x54F8(r29)
	  fmuls     f0, f1, f0
	  fdivs     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x68(r1)
	  lwz       r30, 0x6C(r1)
	  mr        r4, r30
	  bl        0x32D74
	  lwz       r3, 0x0(r29)
	  mr        r4, r30
	  bl        0x32D68

	.loc_0x1A8:
	  lwz       r3, 0x4CC(r29)
	  b         .loc_0x560

	.loc_0x1B0:
	  lbz       r0, 0x4DC(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x210
	  lbz       r0, 0x4DD(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x210
	  lfs       f0, -0x4F24(r2)
	  li        r0, 0
	  addis     r3, r29, 0x1
	  stfs      f0, 0x4D4(r29)
	  sth       r0, 0x4E8(r29)
	  lha       r4, 0x4EA(r29)
	  addi      r0, r4, 0x1
	  sth       r0, 0x4EA(r29)
	  lha       r0, 0x4EA(r29)
	  lha       r3, -0x5A64(r3)
	  cmpw      r0, r3
	  blt-      .loc_0x208
	  subi      r0, r3, 0x1
	  sth       r0, 0x4EA(r29)
	  li        r0, 0x1
	  stb       r0, 0x4DC(r29)

	.loc_0x208:
	  li        r0, 0
	  stb       r0, 0x4DD(r29)

	.loc_0x210:
	  lha       r3, 0x4EC(r29)
	  extsh.    r0, r3
	  blt-      .loc_0x268
	  rlwinm    r0,r3,2,0,29
	  add       r3, r29, r0
	  lwz       r4, 0x54FC(r3)
	  lha       r3, 0x18(r4)
	  lha       r0, 0x114(r4)
	  add       r0, r3, r0
	  sth       r0, 0x4E4(r29)
	  lha       r3, 0x116(r4)
	  lha       r4, 0x1A(r4)
	  subi      r0, r3, 0x18
	  add       r0, r4, r0
	  sth       r0, 0x4E6(r29)
	  lwz       r3, 0xC(r29)
	  lha       r4, 0x4E4(r29)
	  lwz       r12, 0x0(r3)
	  lha       r5, 0x4E6(r29)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x268:
	  lbz       r3, 0x4DC(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x33C
	  lha       r0, 0x6(r31)
	  cmpwi     r0, 0x1
	  bgt-      .loc_0x28C
	  lbz       r0, 0x4E0(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x2A8

	.loc_0x28C:
	  lwz       r3, 0x10(r29)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r29)
	  bl        -0xD528

	.loc_0x2A8:
	  lbz       r0, 0x4DE(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x334
	  lwz       r0, 0x28(r30)
	  rlwinm.   r0,r0,0,18,19
	  beq-      .loc_0x334
	  lha       r3, 0x4EE(r29)
	  addi      r0, r3, 0x1
	  sth       r0, 0x4EE(r29)
	  lha       r3, 0x4EE(r29)
	  lha       r0, 0x6(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x304
	  li        r0, 0
	  sth       r0, 0x4EE(r29)
	  li        r0, 0x3
	  li        r3, 0x127
	  lfs       f0, -0x4F40(r2)
	  stfs      f0, 0x4D8(r29)
	  stw       r0, 0x4CC(r29)
	  bl        -0xE7950
	  lwz       r3, 0x4CC(r29)
	  b         .loc_0x560

	.loc_0x304:
	  lha       r3, 0x4D0(r29)
	  lha       r0, 0x4F0(r29)
	  addi      r3, r3, 0x1
	  cmpw      r3, r0
	  blt-      .loc_0x31C
	  li        r3, 0

	.loc_0x31C:
	  extsh     r0, r3
	  sth       r0, 0x4D0(r29)
	  mr        r3, r29
	  bl        -0x9CC
	  mr        r3, r29
	  bl        -0x1164

	.loc_0x334:
	  lwz       r3, 0x4CC(r29)
	  b         .loc_0x560

	.loc_0x33C:
	  lbz       r0, 0x4DE(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x364
	  lwz       r0, 0x28(r30)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x364
	  mr        r3, r29
	  bl        -0x4DC
	  lwz       r3, 0x4CC(r29)
	  b         .loc_0x560

	.loc_0x364:
	  cmplwi    r3, 0
	  bne-      .loc_0x540
	  addis     r3, r29, 0x1
	  lha       r4, 0x4EA(r29)
	  lha       r0, -0x5A64(r3)
	  cmpw      r4, r0
	  bge-      .loc_0x540
	  lwz       r0, 0x20(r30)
	  lfs       f2, -0x4F34(r2)
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x394
	  lfs       f2, -0x4F20(r2)

	.loc_0x394:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4D4(r29)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x4D4(r29)
	  lha       r5, 0x4EA(r29)
	  rlwinm    r0,r5,2,0,29
	  add       r3, r29, r0
	  lwz       r4, 0x54FC(r3)
	  lhz       r0, 0x8(r4)
	  cmpwi     r0, 0x13
	  beq-      .loc_0x448
	  bge-      .loc_0x540
	  cmpwi     r0, 0x12
	  bge-      .loc_0x3D8
	  b         .loc_0x540

	.loc_0x3D8:
	  lbz       r0, 0xC(r4)
	  li        r3, 0x1
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r4)
	  mr        r3, r4
	  lfs       f1, 0x4D4(r29)
	  lfs       f0, -0x4F34(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x428
	  lfs       f0, -0x4F40(r2)
	  li        r4, 0
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x420
	  lfs       f0, -0x4F28(r2)
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x68(r1)
	  lwz       r4, 0x6C(r1)

	.loc_0x420:
	  bl        0x32AEC
	  b         .loc_0x540

	.loc_0x428:
	  lfs       f0, -0x4F1C(r2)
	  li        r0, 0
	  stfs      f0, 0x4D4(r29)
	  sth       r0, 0x4E8(r29)
	  lha       r3, 0x4EA(r29)
	  addi      r0, r3, 0x1
	  sth       r0, 0x4EA(r29)
	  b         .loc_0x540

	.loc_0x448:
	  lfs       f1, 0x4D4(r29)
	  lfs       f0, -0x4F18(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x52C
	  sth       r5, 0x4EC(r29)
	  addis     r4, r29, 0x1
	  addi      r5, r29, 0x4E8
	  lfs       f0, -0x4F40(r2)
	  addi      r6, r1, 0x60
	  stfs      f0, 0x4D4(r29)
	  lha       r0, 0x4EA(r29)
	  lwz       r3, 0x4(r29)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r4, r0
	  lwz       r4, -0x5AB4(r4)
	  bl        -0xC860
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x49C
	  li        r0, 0x1
	  stb       r0, 0x4DD(r29)

	.loc_0x49C:
	  lfs       f1, 0x60(r1)
	  lfs       f0, -0x4F40(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x4B4
	  fneg      f0, f1
	  stfs      f0, 0x4D4(r29)

	.loc_0x4B4:
	  lha       r4, 0x4EA(r29)
	  addis     r3, r29, 0x1
	  lha       r5, 0x4E8(r29)
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r6,r4,10,0,21
	  add       r4, r3, r0
	  addi      r3, r6, 0x4F2
	  lwz       r4, -0x5AB4(r4)
	  add       r3, r29, r3
	  bl        0x8C470
	  lha       r3, 0x4EA(r29)
	  li        r4, 0
	  lha       r0, 0x4E8(r29)
	  rlwinm    r3,r3,10,0,21
	  add       r3, r29, r3
	  add       r3, r3, r0
	  stb       r4, 0x4F2(r3)
	  lha       r0, 0x4EA(r29)
	  rlwinm    r3,r0,10,0,21
	  addi      r3, r3, 0x4F2
	  add       r3, r29, r3
	  bl        -0xCD5C
	  lha       r3, 0x4EA(r29)
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r4,r3,10,0,21
	  add       r3, r29, r0
	  addi      r0, r4, 0x4F2
	  lwz       r3, 0x54FC(r3)
	  add       r0, r29, r0
	  stw       r0, 0x10C(r3)

	.loc_0x52C:
	  lwz       r3, 0x10(r29)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x540:
	  addis     r3, r29, 0x1
	  lha       r4, 0x4EA(r29)
	  lha       r0, -0x5A64(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x55C
	  li        r0, 0x1
	  stb       r0, 0x4DC(r29)

	.loc_0x55C:
	  lwz       r3, 0x4CC(r29)

	.loc_0x560:
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018CF48
 * Size:	000104
 */
void zen::ogScrMessageMgr::draw(Graphics& gfx)
{
	if (_4CC != -1 && _4CC != 1) {
		GXColor color = { 0, 0, 0, 0 };
		GXSetFog(GX_FOG_NONE, 0.0f, 1.0f, 0.1f, 1.0f, color);
		GXSetFogRangeAdj(GX_FALSE, 0, nullptr);
		P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
		graf.setPort();
		mScreen->draw(0, 0, &graf);
		if (_54F2 > 0) {
			_54F2--;
			_4DF = false;
		} else {
			_54F8->draw(0, 0, &graf);
			_4DF = true;
		}
	}
}
