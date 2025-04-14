#include "zen/DrawWorldMap.h"
#include "zen/EffectMgr2D.h"
#include "zen/DrawCommon.h"
#include "P2D/Pane.h"
#include "P2D/TextBox.h"
#include "DebugLog.h"
#include "sysNew.h"

#define MAX_PARTS_PRACTICE  (2)
#define MAX_PARTS_FOREST    (8)
#define MAX_PARTS_CAVE      (9)
#define MAX_PARTS_YAKUSHIMA (10)
#define MAX_PARTS_LAST      (1)

namespace {
zen::EffectMgr2D* WMeffMgr;

// idk what's going on with these. mapNoScr2Game has to spit out WorldMapName values, which have to equal StageID values
u8 mapNoScr2Game[5] = { WM_Yakushima, WM_Forest, WM_Practice, WM_Cave, WM_Last };
u8 mapNoGame2Scr[5] = { WMSCR_Practice, WMSCR_Forest, WMSCR_Cave, WMSCR_Yakushima, WMSCR_Last };
} // namespace

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
DEFINE_PRINT("drawWorldMap")

namespace zen {
/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct WorldMapWipe {
	WorldMapWipe() { mWipePane = nullptr; }

	// weak
	void init(P2DScreen* wipeScreen, u32 tag)
	{
		P2DPane* pane = wipeScreen->search(tag, true);
		if (pane->getTypeID() == PANETYPE_Picture) {
			mWipePane = (P2DPicture*)pane;
			_00.set(mWipePane->getPosH() + (mWipePane->getWidth() >> 1), mWipePane->getPosV() + (mWipePane->getHeight() >> 1), 0.0f);
			move(mWipePane->getPosH(), mWipePane->getPosV());

		} else {
			// these are load bearing, take these out and this inlines :')
			PRINT("not picture pane.\n");
			ERROR("not picture pane.\n");
		}
	}

	void move(int x, int y)
	{
		x -= (mWipePane->getWidth() >> 1);
		y -= (mWipePane->getHeight() >> 1);

		_0C.set(mWipePane->getPosH(), mWipePane->getPosV(), 0.0f);
		_18.set(x, y, 0.0f);
	}

	void set(int x, int y)
	{
		x -= (mWipePane->getWidth() >> 1);
		y -= (mWipePane->getHeight() >> 1);
		mWipePane->move(x, y);
		_0C.set(x, y, 0.0f);
		_18.set(x, y, 0.0f);
	}

	void moveDefaultPos() { move(zen::RoundOff(_00.x), zen::RoundOff(_00.y)); }
	void update(f32 t, u8 alpha)
	{
		f32 tComp = 1.0f - t;
		mWipePane->move(zen::RoundOff(_0C.x * tComp + _18.x * t), zen::RoundOff(_0C.y * tComp + _18.y * t));
		mWipePane->setAlpha(alpha);
	}

	void setDefault() { set(zen::RoundOff(_00.x), zen::RoundOff(_00.y)); }

	Vector3f _00;          // _00
	Vector3f _0C;          // _0C
	Vector3f _18;          // _18
	P2DPicture* mWipePane; // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0xB0.
 */
struct WorldMapWipeMgr {
	WorldMapWipeMgr()
	{
		_04       = 0.0f;
		_08       = 1.0f;
		mIsActive = false;
	}

	void init(P2DScreen* wipeScreen)
	{
		mWipes[0].init(wipeScreen, 'wp00');
		mWipes[1].init(wipeScreen, 'wp01');
		mWipes[2].init(wipeScreen, 'wp02');
		mWipes[3].init(wipeScreen, 'wp03');
		init();
	}

	void init()
	{
		_04       = 0.0f;
		_08       = 0.8f;
		mIsActive = false;
	}

	void set(int x, int y)
	{
		for (int i = 0; i < 4; i++) {
			mWipes[i].set(x, y);
		}
		_00 = 0;
	}

	void open(f32 p1)
	{
		_04 = 0.0f;
		_08 = p1;
		for (int i = 0; i < 4; i++) {
			mWipes[i].moveDefaultPos();
		}
		_00       = 2;
		mIsActive = true;
	}

	bool isActive() { return mIsActive; }

	bool update()
	{
		mIsActive = false;
		int state = _00;
		switch (state) {
		case 0:
			break;
		case 1:
		case 2:
			_04 += gsys->getFrameTime();
			if (_04 > _08) {
				_04   = _08;
				state = 0;
			}
			f32 blendFactor;
			u8 alpha;
			if (_00 == 2) {
				f32 t       = (1.0f - cosf(_04 / _08 * PI)) * 0.5f;
				blendFactor = t;
				alpha       = zen::RoundOff(255.0f * (1.0f - t));
			} else {
				f32 t       = sinf(_04 / _08 * HALF_PI);
				blendFactor = t;
				alpha       = zen::RoundOff(255.0f * t);
			}

			for (int i = 0; i < 4; i++) {
				mWipes[i].update(blendFactor, alpha);
			}

			_00       = state;
			mIsActive = true;
			break;
		}

		return mIsActive;
	}

	void close(f32 p1, int p2, int p3)
	{
		_04 = 0.0f;
		_08 = p1;
		for (int i = 0; i < 4; i++) {
			mWipes[i].move(p2, p3);
		}
		_00       = 1;
		mIsActive = true;
	}

	void setDefault()
	{
		for (int i = 0; i < 4; i++) {
			mWipes[i].setDefault();
		}
		_00 = 0;
	}

	int _00;                // _00
	f32 _04;                // _04
	f32 _08;                // _08
	WorldMapWipe mWipes[4]; // _0C
	bool mIsActive;         // _AC
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C.
 */
struct WorldMapCursorOnyon {
	WorldMapCursorOnyon()
	{
		mOnyonIcon = nullptr;
		_04.set(0.0f, 0.0f, 0.0f);
		_1C.set(0.0f, 0.0f, 0.0f);
		_34 = zen::Rand(scaleFrameMax);
		mBottomPos.set(0.0f, bottomLengthDefault, 0.0f);
	}

	// weak:
	void init()
	{
		if (mOnyonIcon) {
			mOnyonIcon->setOffset(mOnyonIcon->getWidth() >> 1, mOnyonIcon->getHeight() >> 2);
		} else {
			PRINT("Illegal init WorldMapCursorOnyon Class.\n");
			ERROR("Illegal initialize.");
		}

		_34 = zen::Rand(scaleFrameMax);

		_04.set(0.0f, 0.0f, 0.0f);
		_1C.set(0.0f, 0.0f, 0.0f);
		mBottomPos.set(0.0f, bottomLengthDefault, 0.0f);

		_38 = WMeffMgr->create(50, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	}
	void update(Vector3f&);

	// DLL:
	void init(P2DScreen* iconScreen, u32 tag, bool hideIcon)
	{
		P2DPane* icon = iconScreen->search(tag, true);
		if (icon->getTypeID() == PANETYPE_Picture) {
			mOnyonIcon = (P2DPicture*)icon;
			if (hideIcon) {
				mOnyonIcon->hide();
			}
		}

		init();
	}
	void show()
	{
		mOnyonIcon->show();
		if (_38) {
			_38->startGen();
		}
	}
	void hide()
	{
		mOnyonIcon->hide();
		if (_38) {
			_38->stopGen();
		}
	}
	void move(f32 x, f32 y) { _10.set(x, y, 0.0f); }
	void set(f32 x, f32 y, f32 scale)
	{
		_04.set(x, y, 0.0f);
		_10.set(x, y, 0.0f);
		mBottomPos.set(x, y + bottomLengthDefault, 0.0f);
		mOnyonIcon->move(_04.x, _04.y);
		mOnyonIcon->setScale(Vector3f(scale, scale, 1.0f));
	}

	// DLL inlines:
	void updateBottomPos();

	static f32 scaleFrameMax;
	static f32 bottomLengthMin;
	static f32 bottomLengthMax;
	static f32 bottomLengthDefault;

	P2DPicture* mOnyonIcon; // _00
	Vector3f _04;           // _04
	Vector3f _10;           // _10
	Vector3f _1C;           // _1C
	Vector3f mBottomPos;    // _28
	f32 _34;                // _34
	particleGenerator* _38; // _38
};

/**
 * @brief TODO
 *
 * @note Size: 0x12C.
 */
struct WorldMapCursorMgr {

	/**
	 * @brief TODO
	 */
	enum ufoStatusFlag {
		UFO_Unk0 = 0,
		UFO_Unk1 = 1,
		UFO_Unk2 = 2,
	};

	WorldMapCursorMgr()
	{
		mRocketIcon = nullptr;
		for (int i = 0; i < 2; i++) {
			_110[i] = 0;
		}

		initParams();
	}

	// weak functions:
	void initParams()
	{
		setLandingFlag(false);
		_35 = 0;
		_38.set(0.0f, 0.0f, 0.0f);
		_00 = 0.0f;
		_0C.set(0.0f, 0.0f, 0.0f);
		_24.set(0.0f, 0.0f, 0.0f);
		mRocketPos.set(0.0f, 0.0f, 0.0f);
		_30 = 0.0f;
		mBlueOnyonPos.set(0.0f, 0.0f, 0.0f);
		mOnyonVelocity.set(0.0f, 0.0f, 0.0f);
		setUfoStatus(UFO_Unk0);
		_128 = 1.0f;
	}

	void setLandingFlag(bool doSet)
	{
		if (doSet) {
			_34 = 1;
			SeSystem::playSysSe(SYSSE_SELECT_DECIDE);

			if (_110[0]) {
				_110[0]->setInitVel(4.0f * _118);
			}
			if (_110[1]) {
				_110[1]->setInitVel(5.0f * _11C);
			}
		} else {
			_34 = 0;
			if (_110[0]) {
				_110[0]->setInitVel(_118);
			}
			if (_110[1]) {
				_110[1]->setInitVel(_11C);
			}
		}
	}
	void init()
	{
		int i;
		if (mRocketIcon) {
			mRocketPos.set(mRocketIcon->getPosH(), mRocketIcon->getPosV(), 0.0f);
			mRocketIcon->setOffset(mRocketIcon->getWidth() >> 1, mRocketIcon->getHeight() >> 1);
			mRocketIcon->setScale(1.0f);
		} else {
			PRINT("Illegal initilize.\n");
			ERROR("Illegal initilize.\n");
		}

		initParams();
		mCursorOnyons[Blue].init();
		mCursorOnyons[Red].init();
		mCursorOnyons[Yellow].init();

		for (i = 0; i < 2; i++) {
			if (_110[i]) {
				_110[0]->forceFinish(); // oops
			}
		}

		_110[0] = WMeffMgr->create(48, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
		_110[0]->invisible();
		_118 = _110[0]->getInitVel();
		_120 = _110[0]->getFreqFrm();

		_110[1] = WMeffMgr->create(49, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
		_110[1]->invisible();
		_11C = _110[1]->getInitVel();
		_124 = _110[0]->getFreqFrm(); // maybe typo?

		if (playerState) {
			for (i = 0; i < PikiColorCount; i++) {
				if (playerState->displayPikiCount(i)) {
					mCursorOnyons[i].show();
				} else {
					mCursorOnyons[i].hide();
				}
			}
		} else {
			mCursorOnyons[Blue].show();
			mCursorOnyons[Red].show();
			mCursorOnyons[Yellow].show();
		}
	}
	void moveOnyon()
	{
		Vector3f onyonPos[PikiColorCount];
		updateOnyonPos(&onyonPos[Blue], &onyonPos[Red], &onyonPos[Yellow]);
		mCursorOnyons[Blue].move(onyonPos[Blue].x, onyonPos[Blue].y);
		mCursorOnyons[Red].move(onyonPos[Red].x, onyonPos[Red].y);
		mCursorOnyons[Yellow].move(onyonPos[Yellow].x, onyonPos[Yellow].y);
	}
	void updateOnyonPos(Vector3f* bluePos, Vector3f* redPos, Vector3f* yellowPos)
	{
		Vector3f orbitCenter;
		Vector3f newBlueTargetPos;
		Vector3f orbitVec;

		f32 time        = 60.0f * gsys->getFrameTime();
		f32 rocketScale = mRocketIcon->getScale().x;
		orbitCenter.set(mRocketPos.x + ONYON_OFFSET_X, mRocketPos.y + ONYON_OFFSET_Y, mRocketPos.z + ONYON_OFFSET_Z);

		mBlueOnyonPos.add(Vector3f(mOnyonVelocity * time));
		orbitVec.set(mBlueOnyonPos - orbitCenter);
		f32 norm = orbitVec.length();
		if (norm < 0.000001f) {
			orbitVec.set(0.0f, 0.0f, 0.0f);
		} else {
			orbitVec.multiply(ONYON_POS_RADIUS * rocketScale / norm);
		}

		newBlueTargetPos.set(orbitCenter + orbitVec);
		mOnyonVelocity.add(Vector3f(newBlueTargetPos - mBlueOnyonPos));
		mBlueOnyonPos.set(newBlueTargetPos);

		// set blue onyon position (just calculated, reference for others)
		bluePos->set(mBlueOnyonPos.x, mBlueOnyonPos.y, 0.0f);

		// calculate red onyon position (120 degrees rotated from blue)
		f32 cosR = cosf(TAU / 3.0f);
		f32 sinR = sinf(TAU / 3.0f);
		redPos->set(orbitVec.x * cosR + orbitCenter.x - orbitVec.y * sinR, orbitVec.x * sinR + orbitCenter.y + orbitVec.y * cosR, 0.0f);

		// calculate yellow onyon position (240 degrees rotated from blue)
		f32 cosY = cosf(2.0f * TAU / 3.0f);
		f32 sinY = sinf(2.0f * TAU / 3.0f);
		yellowPos->set(orbitVec.x * cosY + orbitCenter.x - orbitVec.y * sinY, orbitVec.x * sinY + orbitCenter.y + orbitVec.y * cosY, 0.0f);
	}
	void stayUfo()
	{
		Vector3f vec1;
		f32 sec = 60.0f * gsys->getFrameTime();
		vec1.set(_0C.x - mRocketPos.x, _0C.y - mRocketPos.y, 0.0f);
		vec1.multiply(0.8f * gsys->getFrameTime());
		_24.add(vec1);
		_24.multiply(0.92f);
		f32 len = _24.length();
		if (len < 0.000001f) {
			_24.set(0.0f, 0.5f, 0.0f);
		} else {
			if (len > 1.0f) {
				_24.multiply(1.0f / len);
			}
			if (len < 0.5f) {
				_24.multiply(0.5f / len);
			}
		}

		mRocketPos.add(_24);

		mRocketIcon->move(zen::RoundOff(mRocketPos.x), zen::RoundOff(mRocketPos.y));
		_30 += calcAddAngle(mRocketIcon->getRotate(), 0.0f, 0.017453292f, sec);
		_30 *= 0.9999f;
		if (_30 > (5.0f * PI / 180.0f)) {
			_30 = (5.0f * PI / 180.0f);
		}
		if (_30 < -(5.0f * PI / 180.0f)) {
			_30 = -(5.0f * PI / 180.0f);
		}

		rotateUfo(zen::correctRad(_30 + mRocketIcon->getRotate()));

		u32 badCompiler;

		PRINT("fake", mRocketIcon ? "fake" : "fake");
		PRINT("fake", mRocketIcon ? "fake" : "fake");
		PRINT("fake", mRocketIcon ? "fake" : "fake");
	}

	bool moveUfo()
	{
		bool res = false;
		Vector3f vec1;
		f32 sec   = 60.0f * gsys->getFrameTime();
		f32 scale = mRocketIcon->getScale().x;
		f32 a     = 1.0f;

		vec1.set(_0C.x - mRocketPos.x, _0C.y - mRocketPos.y, 0.0f);
	}
	void forceMove();
	void effect();

	// DLL:
	void setUfoStatus(ufoStatusFlag status)
	{
		mUfoStatus = status;
		switch (mUfoStatus) {
		case UFO_Unk0:
			_30 = 0.0f;
			break;
		case UFO_Unk1:
			break;
		}
	}

	void init(P2DScreen* iconScreen)
	{
		P2DPane* rocket = iconScreen->search('ri', true);
		if (rocket->getTypeID() == PANETYPE_Picture) {
			mRocketIcon = (P2DPicture*)rocket;
		}

		mCursorOnyons[Blue].init(iconScreen, 'ci_b', false);
		mCursorOnyons[Red].init(iconScreen, 'ci_r', false);
		mCursorOnyons[Yellow].init(iconScreen, 'ci_y', false);
		init();
	}
	void updateOnyons()
	{
		moveOnyon();
		for (int i = 0; i < PikiColorCount; i++) {
			mCursorOnyons[i].update(mRocketIcon->getScale());
		}
	}
	void update()
	{
		switch (mUfoStatus) {
		case UFO_Unk0:
			stayUfo();
			break;

		case UFO_Unk1:
			if (moveUfo()) {
				if (_35) {
					forceMove();
				} else if (_34) {
					setUfoStatus(UFO_Unk2);
				} else {
					setUfoStatus(UFO_Unk0);
				}
			}
			break;
		case UFO_Unk2:
			break;
		}

		updateOnyons();
		effect();
	}

	ufoStatusFlag getStatusFlag() { return mUfoStatus; }

	bool isLanding() { return _34; }
	bool isMoveOK() { return !_35 && !_34; }

	f32 calcAddAngle(f32 p1, f32 p2, f32 p3, f32 p4)
	{
		f32 diff = p2 - p1;
		if (zen::Abs(diff) > p3) {
			f32 x = p3;
			if (zen::Abs(diff) < PI) {
				if (diff < 0.0f) {
					x *= -1.0f;
				}
			} else if (diff > 0.0f) {
				x *= -1.0f;
			}

			return x * p4;
		}

		return diff;
	}

	void rotateUfo(f32 angle) { mRocketIcon->rotateZ(mRocketIcon->getWidth() >> 1, mRocketIcon->getHeight() >> 1, angle); }

	void set(int x, int y, f32 scale)
	{
		mRocketPos.set(x, y, 0.0f);
		_0C.set(x, y, 0.0f);
		mRocketIcon->move(x, y);
		mRocketIcon->setScale(Vector3f(scale, scale, 1.0f));
		setOnyonPos(scale);
	}
	void setOnyonPos(f32 scale)
	{
		Vector3f onyonPos[PikiColorCount];
		updateOnyonPos(&onyonPos[Blue], &onyonPos[Red], &onyonPos[Yellow]);
		mCursorOnyons[Blue].set(onyonPos[Blue].x, onyonPos[Blue].y, scale);
		mCursorOnyons[Red].set(onyonPos[Red].x, onyonPos[Red].y, scale);
		mCursorOnyons[Yellow].set(onyonPos[Yellow].x, onyonPos[Yellow].y, scale);
	}
	void move(int x, int y, bool p3)
	{
		bool check = false;
		if (_35) {
			return;
		}

		if (p3) {
			switch (mUfoStatus) {
			case UFO_Unk0:
				_00   = 0.0f;
				check = true;
				setLandingFlag(true);
				break;
			case UFO_Unk1:
				if (!_34) {
					_35 = true;
					_38.set(x, y, 0.0f);
				}
				break;
			}
		} else if (!_34) {
			check = true;
		}

		if (check) {
			if (!_34 && !_35) {
				SeSystem::playSysSe(SYSSE_SELECT_MOVE);
			}
			setUfoStatus(UFO_Unk1);
			_0C.set(x, y, 0.0f);
		}
	}

	// DLL inlines to do:
	void moveCancel(int, int);

	static const f32 ONYON_POS_RADIUS;
	static const f32 ONYON_OFFSET_X;
	static const f32 ONYON_OFFSET_Y;
	static const f32 ONYON_OFFSET_Z;

	f32 _00;                                           // _00
	ufoStatusFlag mUfoStatus;                          // _04
	P2DPicture* mRocketIcon;                           // _08
	Vector3f _0C;                                      // _0C
	Vector3f mRocketPos;                               // _18
	Vector3f _24;                                      // _24
	f32 _30;                                           // _30
	bool _34;                                          // _34
	bool _35;                                          // _35
	Vector3f _38;                                      // _38
	WorldMapCursorOnyon mCursorOnyons[PikiColorCount]; // _44, indexed by PikiColor
	Vector3f mBlueOnyonPos;                            // _F8
	Vector3f mOnyonVelocity;                           // _104
	zen::particleGenerator* _110[2];                   // _110
	f32 _118;                                          // _118
	f32 _11C;                                          // _11C
	f32 _120;                                          // _120
	f32 _124;                                          // _124
	f32 _128;                                          // _128
};

/**
 * @brief TODO
 */
struct WorldMapPartsInfoMgr {
	WorldMapPartsInfoMgr()
	{
		mMaxPartCount   = 0;
		mFadedStarIcons = nullptr;
	}

	void setDisplayParts(int max, int curr)
	{
		for (int i = 0; i < mMaxPartCount; i++) {
			if (i < max) {
				if (i < curr) {
					mGlowingStarIcons[i]->show();
					mFadedStarIcons[i]->hide();
				} else {
					mGlowingStarIcons[i]->hide();
					mFadedStarIcons[i]->show();
				}
			} else {
				mGlowingStarIcons[i]->hide();
				mFadedStarIcons[i]->hide();
			}
		}
	}
	void setActiveMapNo(WorldMapName id)
	{
		int curr, max;
		if (id == WM_NULL) {
			max = curr = 0;
		} else if (playerState) {
			switch (id) {
			case WM_Practice:
				max  = MAX_PARTS_PRACTICE;
				curr = playerState->getPartsGetCount(WM_Practice);
				break;
			case WM_Forest:
				max  = MAX_PARTS_FOREST;
				curr = playerState->getPartsGetCount(WM_Forest);
				break;
			case WM_Cave:
				max  = MAX_PARTS_CAVE;
				curr = playerState->getPartsGetCount(WM_Cave);
				break;
			case WM_Yakushima:
				max  = MAX_PARTS_YAKUSHIMA;
				curr = playerState->getPartsGetCount(WM_Yakushima);
				break;
			case WM_Last:
				max  = MAX_PARTS_LAST;
				curr = playerState->getPartsGetCount(WM_Last);
				break;
			default:
				max  = 0;
				curr = 0;
				break;
			}
		} else {
			switch (id) {
			case WM_Practice:
				max  = MAX_PARTS_PRACTICE;
				curr = 1;
				break;
			case WM_Forest:
				max  = MAX_PARTS_FOREST;
				curr = 2;
				break;
			case WM_Cave:
				max  = MAX_PARTS_CAVE;
				curr = 3;
				break;
			case WM_Yakushima:
				max  = MAX_PARTS_YAKUSHIMA;
				curr = 4;
				break;
			case WM_Last:
				max  = MAX_PARTS_LAST;
				curr = 0;
				break;
			default:
				max  = 0;
				curr = 0;
				break;
			}
		}

		setDisplayParts(max, curr);
	}

	// DLL:
	void init(P2DScreen* dataScreen)
	{
		char partStr[8];
		int partCount = 0;
		sprintf(partStr, "pa%02d", 0);
		while (dataScreen->search(P2DPaneLibrary::makeTag(partStr), false)) {
			sprintf(partStr, "pa%02d", ++partCount);
		}

		mMaxPartCount     = partCount;
		mFadedStarIcons   = new P2DPicture*[mMaxPartCount];
		mGlowingStarIcons = new P2DPicture*[mMaxPartCount];

		for (int i = 0; i < mMaxPartCount; i++) {
			sprintf(partStr, "pn%02d", i);
			P2DPane* pane = dataScreen->search(P2DPaneLibrary::makeTag(partStr), true);
			if (pane->getTypeID() == PANETYPE_Picture) {
				mFadedStarIcons[i] = (P2DPicture*)pane;
				mFadedStarIcons[i]->show();
				P2DPaneLibrary::changeParent(mFadedStarIcons[i], P2DPaneLibrary::getParentPane(mFadedStarIcons[i]));
			} else {
				PRINT("not picture pane.\n");
				ERROR("not picture pane.\n");
			}

			sprintf(partStr, "pa%02d", i);
			pane = dataScreen->search(P2DPaneLibrary::makeTag(partStr), true);
			if (pane->getTypeID() == PANETYPE_Picture) {
				mGlowingStarIcons[i] = (P2DPicture*)pane;
				mGlowingStarIcons[i]->show();
				P2DPaneLibrary::changeParent(mGlowingStarIcons[i], P2DPaneLibrary::getParentPane(mGlowingStarIcons[i]));
			} else {
				PRINT("not picture pane.\n");
				ERROR("not picture pane.\n");
			}
		}

		init();
	}
	void init() { }
	void update() { }

	// DLL inlines to do:
	void close();

	int mMaxPartCount;              // _00
	P2DPicture** mFadedStarIcons;   // _04
	P2DPicture** mGlowingStarIcons; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x88.
 */
struct WorldMapConfirmMgr {
	/**
	 * @brief TODO
	 */
	enum statusFlag {
		STATUS_Unk0 = 0,
	};

	/**
	 * @brief TODO
	 */
	enum selectFlag {
		SELECT_Unk0 = 0,
		SELECT_Unk1 = 1,
		SELECT_COUNT, // 2
	};

	WorldMapConfirmMgr()
	{
		mConfirmScreen = new DrawScreen("screen/blo/w_ok.blo", nullptr, true, true);

		P2DScreen* confScreen = mConfirmScreen->getScreenPtr();
		confScreen->setOffset(mConfirmScreen->getScreenPtr()->getWidth() >> 1, mConfirmScreen->getScreenPtr()->getHeight() >> 1);
		P2DPane* parent = confScreen->search('pall', true);
		P2DPane* pane   = confScreen->search('se_c', true);
		if (pane->getTypeID() == PANETYPE_TextBox) {
			static_cast<P2DTextBox*>(pane)->getFontColor(_68, _6C);
		} else {
			ERROR("tag<se_c> pane is not text box.\n");
		}

		mMenuItems = new DrawMenuItem[SELECT_COUNT];

		for (int i = 0; i < SELECT_COUNT; i++) {
			char str[8];
			sprintf(str, "he%02d", i);
			pane = confScreen->search(P2DPaneLibrary::makeTag(str), true);
			P2DPaneLibrary::changeParent(pane, parent);
			mMenuItems[i].setTextPane(pane, nullptr);

			sprintf(str, "i%02dl", i);
			pane = confScreen->search(P2DPaneLibrary::makeTag(str), true);
			if (mMenuItems[i].setIconLPane(pane, parent)) {
				ERROR("pane [%s] is not picture.\n", str);
			}

			sprintf(str, "i%02dr", i);
			pane = confScreen->search(P2DPaneLibrary::makeTag(str), true);
			if (mMenuItems[i].setIconRPane(pane, parent)) {
				ERROR("pane [%s] is not picture.\n", str);
			}
		}

		mLeftSpecCursor.init(confScreen, parent, 'z**l', 10.0f, 100.0f);
		mRightSpecCursor.init(confScreen, parent, 'z**r', 50.0f, 100.0f);
		init();
	}

	void init(statusFlag status)
	{
		mStatus = status;
		mConfirmScreen->getScreenPtr()->move(640, 0);
		mConfirmScreen->getScreenPtr()->setScale(1.0f);
		mConfirmScreen->getScreenPtr()->show();
		_70               = 0.0f;
		mCurrentSelection = SELECT_Unk0;
		mLeftSpecCursor.initPos(mMenuItems[mCurrentSelection].getIconLPosH(), mMenuItems[mCurrentSelection].getIconLPosV());
		mRightSpecCursor.initPos(mMenuItems[mCurrentSelection].getIconRPosH(), mMenuItems[mCurrentSelection].getIconRPosV());

		for (int i = 0; i < SELECT_COUNT; i++) {
			mMenuItems[i].init(i == mCurrentSelection, _68, _6C);
		}
	}

	bool modeOperation(Controller*);

	// DLL:
	void init() { init(STATUS_Unk0); }

	void draw(Graphics&) { mConfirmScreen->draw(); }

	// DLL inlines to do:
	bool update(Controller*);
	selectFlag getSelectFlag();
	void start();

	DrawScreen* mConfirmScreen;         // _00
	SpectrumCursorMgr mLeftSpecCursor;  // _04
	SpectrumCursorMgr mRightSpecCursor; // _34
	DrawMenuItem* mMenuItems;           // _64
	Colour _68;                         // _68
	Colour _6C;                         // _6C
	f32 _70;                            // _70
	statusFlag mStatus;                 // _74
	selectFlag mCurrentSelection;       // _78
	Vector3f _7C;                       // _7C
};

} // namespace zen

const int zen::WorldMapTitleMgr::OBJ_NUM = 5;

// probably need to move these around later for ordering
f32 zen::WorldMapCursorOnyon::bottomLengthMin     = 10.0f;
f32 zen::WorldMapCursorOnyon::bottomLengthDefault = 15.0f;
f32 zen::WorldMapCursorOnyon::bottomLengthMax     = 20.0f;
f32 zen::WorldMapCursorOnyon::scaleFrameMax       = 0.8f;

const f32 zen::WorldMapCursorMgr::ONYON_POS_RADIUS = 60.0f;
const f32 zen::WorldMapCursorMgr::ONYON_OFFSET_X   = 0.0f;
const f32 zen::WorldMapCursorMgr::ONYON_OFFSET_Y   = 20.0f;
const f32 zen::WorldMapCursorMgr::ONYON_OFFSET_Z   = 0.0f;

const int WorldMapCoursePoint::EVENT_NONE          = 0;
const int WorldMapCoursePoint::EVENT_APPEAR_FINISH = 1;

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
zen::DrawWorldMap::~DrawWorldMap()
{
}

/*
 * --INFO--
 * Address:	801DB14C
 * Size:	00246C
 */
zen::DrawWorldMap::DrawWorldMap()
{
	// SET UP EFFECTS MGR
	mEffectMgr2D = new EffectMgr2D(96, 500, 650);
	WMeffMgr     = mEffectMgr2D;

	// SET UP SCREENS
	mWipeScreen  = new DrawScreen("screen/blo/w_wipe.blo", nullptr, true, true);
	mIconScreen  = new DrawScreen("screen/blo/w_icon.blo", nullptr, true, true);
	mTitleScreen = new DrawScreen("screen/blo/w_title.blo", nullptr, true, true);
	mMoniScreen  = new DrawScreen("screen/blo/w_moni.blo", nullptr, true, true);
	mData1Screen = new DrawScreen("screen/blo/w_data1.blo", nullptr, true, true);
	mData2Screen = new DrawScreen("screen/blo/w_data2.blo", nullptr, true, true);
	mPointScreen = new DrawScreen("screen/blo/w_point.blo", nullptr, true, true);
	mLineScreen  = new DrawScreen("screen/blo/w_line.blo", nullptr, true, true);
	mBackScreen  = new DrawScreen("screen/blo/w_back.blo", nullptr, true, true);

	_0C = 0.0f;
	_04 = -1;
	_08 = -1;

	// SET UP COURSE POINTS
	mCoursePointMgr = new WorldMapCoursePointMgr();
	mCoursePointMgr->init(mPointScreen->getScreenPtr(), mLineScreen->getScreenPtr(), WM_START);

	// SET UP WIPES
	mWipeMgr = new WorldMapWipeMgr();
	mWipeMgr->init(mWipeScreen->getScreenPtr());

	// SET UP MAP IMAGES
	mMapImageMgr = new WorldMapMapImageMgr();
	mMapImageMgr->init(mMoniScreen->getScreenPtr());

	// SET UP COUNTERS
	if (playerState) {
		mTotalPartsNum           = playerState->getTotalParts();
		mCurrentPartsNum         = playerState->getCurrParts();
		mTotalPikiCounts[Blue]   = playerState->getTotalPikiCount(Blue);
		mTotalPikiCounts[Red]    = playerState->getTotalPikiCount(Red);
		mTotalPikiCounts[Yellow] = playerState->getTotalPikiCount(Yellow);

	} else {
		PRINT("WARNING! playerState ptr is NULL.\n");
		mTotalPartsNum           = 30;
		mCurrentPartsNum         = 29;
		mTotalPikiCounts[Blue]   = 999;
		mTotalPikiCounts[Red]    = 999;
		mTotalPikiCounts[Yellow] = 999;
	}

	P2DPane* dateCentrePane = mData1Screen->getScreenPtr()->search('dc_c', true);
	P2DPane* dateLeftPane   = mData1Screen->getScreenPtr()->search('dc_l', true);
	P2DPane* dateRightPane  = mData1Screen->getScreenPtr()->search('dc_r', true);

	dateCentrePane->setCallBack(new DrawWorldMapDateCallBack(dateCentrePane, dateLeftPane, dateRightPane));

	// CURRENT PARTS
	P2DPane* currPartsLeftPane = mData1Screen->getScreenPtr()->search('ro_l', true);
	currPartsLeftPane->setCallBack(new NumberPicCallBack<int>(currPartsLeftPane, &mCurrentPartsNum, 10, false));

	P2DPane* currPartsRightPane = mData1Screen->getScreenPtr()->search('ro_r', true);
	currPartsRightPane->setCallBack(new NumberPicCallBack<int>(currPartsRightPane, &mCurrentPartsNum, 1, false));

	// TOTAL PARTS
	P2DPane* totalPartsLeftPane = mData1Screen->getScreenPtr()->search('rt_l', true);
	totalPartsLeftPane->setCallBack(new NumberPicCallBack<int>(totalPartsLeftPane, &mTotalPartsNum, 10, false));

	P2DPane* totalPartsRightPane = mData1Screen->getScreenPtr()->search('rt_r', true);
	totalPartsRightPane->setCallBack(new NumberPicCallBack<int>(totalPartsRightPane, &mTotalPartsNum, 1, false));

	// BLUE PIKIS
	P2DPane* bluePikiLeftPane = mData1Screen->getScreenPtr()->search('bp_l', true);
	bluePikiLeftPane->setCallBack(new NumberPicCallBack<int>(bluePikiLeftPane, &mTotalPikiCounts[Blue], 100, false));

	P2DPane* bluePikiCentrePane = mData1Screen->getScreenPtr()->search('bp_c', true);
	bluePikiCentrePane->setCallBack(new NumberPicCallBack<int>(bluePikiCentrePane, &mTotalPikiCounts[Blue], 10, false));

	P2DPane* bluePikiRightPane = mData1Screen->getScreenPtr()->search('bp_r', true);
	bluePikiRightPane->setCallBack(new NumberPicCallBack<int>(bluePikiRightPane, &mTotalPikiCounts[Blue], 1, false));

	// RED PIKIS
	P2DPane* redPikiLeftPane = mData1Screen->getScreenPtr()->search('rp_l', true);
	redPikiLeftPane->setCallBack(new NumberPicCallBack<int>(redPikiLeftPane, &mTotalPikiCounts[Red], 100, false));

	P2DPane* redPikiCentrePane = mData1Screen->getScreenPtr()->search('rp_c', true);
	redPikiCentrePane->setCallBack(new NumberPicCallBack<int>(redPikiCentrePane, &mTotalPikiCounts[Red], 10, false));

	P2DPane* redPikiRightPane = mData1Screen->getScreenPtr()->search('rp_r', true);
	redPikiRightPane->setCallBack(new NumberPicCallBack<int>(redPikiRightPane, &mTotalPikiCounts[Red], 1, false));

	// YELLOW PIKIS
	P2DPane* yellowPikiLeftPane = mData1Screen->getScreenPtr()->search('yp_l', true);
	yellowPikiLeftPane->setCallBack(new NumberPicCallBack<int>(yellowPikiLeftPane, &mTotalPikiCounts[Yellow], 100, false));

	P2DPane* yellowPikiCentrePane = mData1Screen->getScreenPtr()->search('yp_c', true);
	yellowPikiCentrePane->setCallBack(new NumberPicCallBack<int>(yellowPikiCentrePane, &mTotalPikiCounts[Yellow], 10, false));

	P2DPane* yellowPikiRightPane = mData1Screen->getScreenPtr()->search('yp_r', true);
	yellowPikiRightPane->setCallBack(new NumberPicCallBack<int>(yellowPikiRightPane, &mTotalPikiCounts[Yellow], 1, false));

	mCursorMgr = new WorldMapCursorMgr();
	mCursorMgr->init(mIconScreen->getScreenPtr());

	mTitleMgr = new WorldMapTitleMgr();
	mTitleMgr->init(mTitleScreen->getScreenPtr());

	mPartsInfoMgr = new WorldMapPartsInfoMgr();
	mPartsInfoMgr->init(mData2Screen->getScreenPtr());

	mConfirmMgr = new WorldMapConfirmMgr();

	mShootingStarMgr = new WorldMapShootingStarMgr();

	// I think this has to come from inlines *somehow* but i have so many. so. many.
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	PRINT("fake", mShootingStarMgr ? "fake" : "fake");
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x4B0(r1)
	  stmw      r17, 0x474(r1)
	  addi      r26, r3, 0
	  lis       r3, 0x802E
	  addi      r17, r3, 0x57B0
	  addi      r3, r26, 0x64
	  bl        0xEB8C
	  addi      r3, r26, 0x74
	  bl        -0x4B058
	  li        r3, 0x4C4
	  bl        -0x194178
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x50
	  li        r4, 0x60
	  li        r5, 0x1F4
	  li        r6, 0x28A
	  bl        0xE728

	.loc_0x50:
	  stw       r18, 0x50(r26)
	  li        r3, 0x100
	  lwz       r0, 0x50(r26)
	  stw       r0, 0x31C0(r13)
	  bl        -0x1941A8
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x84
	  addi      r4, r17, 0x24
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BC58

	.loc_0x84:
	  stw       r18, 0x10(r26)
	  li        r3, 0x100
	  bl        -0x1941D4
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0xB0
	  addi      r4, r17, 0x3C
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BC84

	.loc_0xB0:
	  stw       r18, 0x14(r26)
	  li        r3, 0x100
	  bl        -0x194200
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0xDC
	  addi      r4, r17, 0x54
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BCB0

	.loc_0xDC:
	  stw       r18, 0x18(r26)
	  li        r3, 0x100
	  bl        -0x19422C
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x108
	  addi      r4, r17, 0x6C
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BCDC

	.loc_0x108:
	  stw       r18, 0x1C(r26)
	  li        r3, 0x100
	  bl        -0x194258
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x134
	  addi      r4, r17, 0x84
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BD08

	.loc_0x134:
	  stw       r18, 0x20(r26)
	  li        r3, 0x100
	  bl        -0x194284
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x160
	  addi      r4, r17, 0x9C
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BD34

	.loc_0x160:
	  stw       r18, 0x24(r26)
	  li        r3, 0x100
	  bl        -0x1942B0
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x18C
	  addi      r4, r17, 0xB4
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BD60

	.loc_0x18C:
	  stw       r18, 0x28(r26)
	  li        r3, 0x100
	  bl        -0x1942DC
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x1B8
	  addi      r4, r17, 0xCC
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BD8C

	.loc_0x1B8:
	  stw       r18, 0x2C(r26)
	  li        r3, 0x100
	  bl        -0x194308
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x1E4
	  addi      r4, r17, 0xE4
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BDB8

	.loc_0x1E4:
	  stw       r18, 0x30(r26)
	  li        r0, -0x1
	  li        r3, 0x138
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r26)
	  stw       r0, 0x4(r26)
	  stw       r0, 0x8(r26)
	  bl        -0x194348
	  addi      r18, r3, 0
	  mr.       r5, r18
	  beq-      .loc_0x23C
	  lis       r3, 0x801E
	  subi      r4, r3, 0x1924
	  addi      r3, r5, 0x8
	  li        r5, 0
	  li        r6, 0x3C
	  li        r7, 0x5
	  bl        0x396FC
	  li        r0, 0
	  stw       r0, 0x4(r18)
	  stw       r0, 0x134(r18)
	  stw       r0, 0x0(r18)

	.loc_0x23C:
	  stw       r18, 0x38(r26)
	  li        r23, 0
	  lwz       r4, 0x2C(r26)
	  lwz       r3, 0x28(r26)
	  lwz       r27, 0x38(r26)
	  addi      r28, r4, 0x4
	  addi      r25, r3, 0x4
	  stw       r23, 0x134(r27)
	  lwz       r0, 0x2F6C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  addi      r24, r27, 0x8
	  lis       r22, 0x78
	  lis       r21, 0x785F
	  lis       r20, 0x706F
	  lis       r19, 0x736C
	  addi      r3, r24, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r22, 0x5F31
	  addi      r6, r21, 0x3173
	  addi      r7, r20, 0x3031
	  addi      r9, r19, 0x6931
	  bl        0x3170
	  addi      r0, r27, 0xF8
	  stw       r0, 0x2C(r24)
	  addi      r29, r27, 0x44
	  addi      r18, r27, 0xBC
	  stw       r29, 0x30(r24)
	  li        r4, 0x3
	  stw       r23, 0x34(r24)
	  stw       r18, 0x38(r24)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15B8C8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x304
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r22, 0x5F32
	  addi      r6, r21, 0x3273
	  addi      r7, r20, 0x3032
	  addi      r9, r19, 0x6932
	  bl        0x3120
	  stw       r24, 0x2C(r29)
	  addi      r0, r27, 0x80
	  stw       r23, 0x30(r29)
	  stw       r23, 0x34(r29)
	  stw       r0, 0x38(r29)
	  b         .loc_0x338

	.loc_0x304:
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r22, 0x5F32
	  addi      r6, r21, 0x3273
	  addi      r7, r20, 0x3032
	  addi      r9, r19, 0x6932
	  bl        0x30E8
	  stw       r18, 0x2C(r29)
	  addi      r0, r27, 0x80
	  stw       r23, 0x30(r29)
	  stw       r23, 0x34(r29)
	  stw       r0, 0x38(r29)

	.loc_0x338:
	  addi      r19, r27, 0x80
	  lis       r29, 0x78
	  lis       r24, 0x785F
	  lis       r23, 0x706F
	  lis       r22, 0x736C
	  addi      r3, r19, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r29, 0x5F33
	  addi      r6, r24, 0x3373
	  addi      r7, r23, 0x3033
	  addi      r9, r22, 0x6933
	  bl        0x30A0
	  addi      r18, r27, 0xBC
	  stw       r18, 0x2C(r19)
	  li        r21, 0
	  addi      r20, r27, 0x44
	  stw       r21, 0x30(r19)
	  li        r4, 0x3
	  stw       r20, 0x34(r19)
	  stw       r21, 0x38(r19)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15B998
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3D8
	  addi      r3, r18, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r29, 0x5F34
	  addi      r6, r24, 0x3473
	  addi      r7, r23, 0x3034
	  addi      r9, r22, 0x6934
	  bl        0x3050
	  addi      r0, r27, 0xF8
	  stw       r0, 0x2C(r18)
	  addi      r0, r27, 0x8
	  stw       r19, 0x30(r18)
	  stw       r0, 0x34(r18)
	  stw       r21, 0x38(r18)
	  b         .loc_0x40C

	.loc_0x3D8:
	  addi      r3, r18, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r29, 0x5F34
	  addi      r6, r24, 0x3473
	  addi      r7, r23, 0x3034
	  addi      r9, r22, 0x6934
	  bl        0x3014
	  addi      r0, r27, 0xF8
	  stw       r0, 0x2C(r18)
	  stw       r19, 0x30(r18)
	  stw       r20, 0x34(r18)
	  stw       r21, 0x38(r18)

	.loc_0x40C:
	  addi      r18, r27, 0xF8
	  lis       r5, 0x78
	  lis       r6, 0x785F
	  lis       r7, 0x706F
	  lis       r9, 0x736C
	  addi      r3, r18, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r5, 0x5F35
	  addi      r6, r6, 0x3573
	  addi      r7, r7, 0x3035
	  addi      r9, r9, 0x6935
	  bl        0x2FCC
	  li        r4, 0
	  stw       r4, 0x2C(r18)
	  addi      r3, r27, 0xBC
	  addi      r0, r27, 0x8
	  stw       r3, 0x30(r18)
	  stw       r0, 0x34(r18)
	  stw       r4, 0x38(r18)
	  b         .loc_0x574

	.loc_0x460:
	  addi      r29, r27, 0x8
	  lis       r24, 0x78
	  lis       r31, 0x785F
	  lis       r30, 0x706F
	  lis       r18, 0x736C
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r24, 0x5F31
	  addi      r6, r31, 0x3173
	  addi      r7, r30, 0x3031
	  addi      r9, r18, 0x6931
	  bl        0x2F78
	  addi      r22, r27, 0xF8
	  stw       r22, 0x2C(r29)
	  addi      r19, r27, 0x44
	  addi      r21, r27, 0xBC
	  stw       r19, 0x30(r29)
	  addi      r3, r19, 0
	  addi      r4, r25, 0
	  stw       r23, 0x34(r29)
	  addi      r8, r28, 0
	  addi      r5, r24, 0x5F32
	  stw       r21, 0x38(r29)
	  addi      r6, r31, 0x3273
	  addi      r7, r30, 0x3032
	  addi      r9, r18, 0x6932
	  bl        0x2F3C
	  stw       r29, 0x2C(r19)
	  addi      r20, r27, 0x80
	  addi      r3, r20, 0
	  stw       r23, 0x30(r19)
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  stw       r23, 0x34(r19)
	  addi      r5, r24, 0x5F33
	  addi      r6, r31, 0x3373
	  stw       r20, 0x38(r19)
	  addi      r7, r30, 0x3033
	  addi      r9, r18, 0x6933
	  bl        0x2F08
	  stw       r21, 0x2C(r20)
	  mr        r3, r21
	  addi      r4, r25, 0
	  stw       r23, 0x30(r20)
	  addi      r8, r28, 0
	  addi      r5, r24, 0x5F34
	  stw       r19, 0x34(r20)
	  addi      r6, r31, 0x3473
	  addi      r7, r30, 0x3034
	  stw       r23, 0x38(r20)
	  addi      r9, r18, 0x6934
	  bl        0x2ED8
	  stw       r22, 0x2C(r21)
	  mr        r3, r22
	  addi      r4, r25, 0
	  stw       r20, 0x30(r21)
	  addi      r8, r28, 0
	  addi      r5, r24, 0x5F35
	  stw       r29, 0x34(r21)
	  addi      r6, r31, 0x3573
	  addi      r7, r30, 0x3035
	  stw       r23, 0x38(r21)
	  addi      r9, r18, 0x6935
	  bl        0x2EA8
	  stw       r23, 0x2C(r22)
	  stw       r21, 0x30(r22)
	  stw       r29, 0x34(r22)
	  stw       r23, 0x38(r22)

	.loc_0x574:
	  addi      r28, r13, 0x2470
	  addi      r18, r28, 0
	  addi      r19, r27, 0
	  li        r22, 0

	.loc_0x584:
	  lbz       r21, 0x0(r18)
	  addi      r3, r1, 0x45C
	  addi      r5, r22, 0x1
	  crclr     6, 0x6
	  addi      r4, r13, 0x2610
	  bl        0x3AEB4
	  addi      r3, r1, 0x464
	  crclr     6, 0x6
	  addi      r5, r22, 0x1
	  addi      r4, r13, 0x2618
	  bl        0x3AEA0
	  lwz       r12, 0x0(r25)
	  mr        r3, r25
	  lbz       r6, 0x465(r1)
	  addi      r20, r19, 0x8
	  lbz       r0, 0x45D(r1)
	  lwz       r12, 0x34(r12)
	  rlwinm    r7,r6,16,0,15
	  lbz       r8, 0x464(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r4, 0x45C(r1)
	  lbz       r5, 0x45E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r9, 0x466(r1)
	  rlwimi    r0,r5,8,16,23
	  lbz       r6, 0x45F(r1)
	  rlwimi    r7,r8,24,0,7
	  lbz       r10, 0x467(r1)
	  rlwimi    r7,r9,8,16,23
	  or        r4, r6, r0
	  or        r23, r10, r7
	  li        r5, 0x1
	  blrl
	  stw       r3, 0x24(r20)
	  addi      r3, r25, 0
	  addi      r4, r23, 0
	  lwz       r12, 0x0(r25)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x28(r20)
	  stw       r21, 0x18(r19)
	  lbz       r0, 0x14(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x678
	  lwz       r3, 0x14(r20)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r20)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r20)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x678:
	  addi      r23, r19, 0x8
	  li        r4, 0x1
	  stb       r4, 0x14(r19)
	  li        r20, 0
	  lwz       r3, 0x1C(r19)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r19)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x24(r19)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x28(r19)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x728
	  mr        r4, r21
	  bl        -0x15BCE0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x728
	  stb       r20, 0xC(r23)
	  lwz       r3, 0x14(r23)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r23)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x1C(r23)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r23)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x728:
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x5
	  addi      r18, r18, 0x1
	  addi      r19, r19, 0x3C
	  blt+      .loc_0x584
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r27, r0
	  stw       r0, 0x4(r27)
	  lwz       r6, 0x4(r27)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x798
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x798:
	  li        r3, 0xB0
	  bl        -0x1948E4
	  addi      r18, r3, 0
	  mr.       r5, r18
	  beq-      .loc_0x7E0
	  lis       r3, 0x801E
	  subi      r4, r3, 0x1AE0
	  addi      r3, r5, 0xC
	  li        r5, 0
	  li        r6, 0x28
	  li        r7, 0x4
	  bl        0x39160
	  lfs       f0, -0x4188(r2)
	  li        r0, 0
	  stfs      f0, 0x4(r18)
	  lfs       f0, -0x4184(r2)
	  stfs      f0, 0x8(r18)
	  stb       r0, 0xAC(r18)

	.loc_0x7E0:
	  stw       r18, 0x58(r26)
	  lis       r18, 0x7770
	  addi      r5, r18, 0x3030
	  lwz       r3, 0x10(r26)
	  lwz       r19, 0x58(r26)
	  addi      r20, r3, 0x4
	  addi      r4, r20, 0
	  addi      r3, r19, 0xC
	  bl        0x2A70
	  addi      r4, r20, 0
	  addi      r3, r19, 0x34
	  addi      r5, r18, 0x3031
	  bl        0x2A60
	  addi      r4, r20, 0
	  addi      r3, r19, 0x5C
	  addi      r5, r18, 0x3032
	  bl        0x2A50
	  addi      r4, r20, 0
	  addi      r3, r19, 0x84
	  addi      r5, r18, 0x3033
	  bl        0x2A40
	  lfs       f0, -0x4188(r2)
	  li        r18, 0
	  li        r3, 0x24
	  stfs      f0, 0x4(r19)
	  lfs       f0, -0x4180(r2)
	  stfs      f0, 0x8(r19)
	  stb       r18, 0xAC(r19)
	  bl        -0x194998
	  cmplwi    r3, 0
	  beq-      .loc_0x88C
	  li        r0, 0x2
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  stw       r0, 0x8(r3)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x0(r3)
	  stb       r18, 0x20(r3)
	  stw       r18, 0xC(r3)
	  stw       r18, 0x10(r3)
	  stw       r18, 0x14(r3)
	  stw       r18, 0x18(r3)
	  stw       r18, 0x1C(r3)

	.loc_0x88C:
	  stw       r3, 0x54(r26)
	  lis       r3, 0x6D69
	  addi      r4, r3, 0x5F31
	  lwz       r3, 0x1C(r26)
	  li        r5, 0x1
	  lwz       r18, 0x54(r26)
	  addi      r19, r3, 0x4
	  addi      r3, r19, 0
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x8CC
	  stw       r3, 0xC(r18)

	.loc_0x8CC:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6D69
	  addi      r4, r4, 0x5F32
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x8FC
	  stw       r3, 0x10(r18)

	.loc_0x8FC:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6D69
	  addi      r4, r4, 0x5F33
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x92C
	  stw       r3, 0x14(r18)

	.loc_0x92C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6D69
	  addi      r4, r4, 0x5F34
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x95C
	  stw       r3, 0x18(r18)

	.loc_0x95C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6D69
	  addi      r4, r4, 0x5F35
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x98C
	  stw       r3, 0x1C(r18)

	.loc_0x98C:
	  mr        r3, r18
	  bl        0x2828
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x9E8
	  bl        -0x15AE84
	  stw       r3, 0x3C(r26)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15AE88
	  stw       r3, 0x40(r26)
	  li        r4, 0
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15BEE0
	  stw       r3, 0x44(r26)
	  li        r4, 0x1
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15BEF0
	  stw       r3, 0x48(r26)
	  li        r4, 0x2
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15BF00
	  stw       r3, 0x4C(r26)
	  b         .loc_0xA08

	.loc_0x9E8:
	  li        r0, 0x1E
	  stw       r0, 0x3C(r26)
	  li        r3, 0x1D
	  li        r0, 0x3E7
	  stw       r3, 0x40(r26)
	  stw       r0, 0x44(r26)
	  stw       r0, 0x48(r26)
	  stw       r0, 0x4C(r26)

	.loc_0xA08:
	  lwz       r3, 0x20(r26)
	  lis       r19, 0x6463
	  lwzu      r12, 0x4(r3)
	  addi      r4, r19, 0x5F63
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x20(r26)
	  addi      r18, r3, 0
	  li        r5, 0x1
	  lwz       r12, 0x4(r4)
	  addi      r3, r4, 0x4
	  addi      r4, r19, 0x5F6C
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x20(r26)
	  addi      r20, r3, 0
	  li        r5, 0x1
	  lwz       r12, 0x4(r4)
	  addi      r3, r4, 0x4
	  addi      r4, r19, 0x5F72
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r21, r3, 0
	  li        r3, 0x10
	  bl        -0x194BC0
	  mr.       r19, r3
	  beq-      .loc_0xB04
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  li        r4, 0
	  li        r5, 0x10
	  bl        -0x2B4E8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C50C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x5A08
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B4E8
	  addi      r4, r20, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B4F8
	  addi      r4, r21, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B508
	  stw       r18, 0x4(r19)
	  mr        r3, r19
	  stw       r20, 0x8(r19)
	  stw       r21, 0xC(r19)
	  bl        0x2554

	.loc_0xB04:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2B5BC
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x726F
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x194C84
	  mr.       r19, r3
	  beq-      .loc_0xC4C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B5AC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C5D0
	  addi      r0, r26, 0x40
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0xBF0
	  addi      r3, r19, 0x4
	  bl        -0x5D2B8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xC1C
	  stw       r0, 0xEC(r18)
	  b         .loc_0xC1C

	.loc_0xBF0:
	  addi      r3, r19, 0x4
	  bl        -0x5D2E8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xC1C
	  stw       r0, 0xEC(r18)

	.loc_0xC1C:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0xC4C:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2B704
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x726F
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x194DCC
	  mr.       r19, r3
	  beq-      .loc_0xD94
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B6F4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C718
	  addi      r0, r26, 0x40
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0xD38
	  addi      r3, r19, 0x4
	  bl        -0x5D400
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xD64
	  stw       r0, 0xEC(r18)
	  b         .loc_0xD64

	.loc_0xD38:
	  addi      r3, r19, 0x4
	  bl        -0x5D430
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xD64
	  stw       r0, 0xEC(r18)

	.loc_0xD64:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0xD94:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2B84C
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7274
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x194F14
	  mr.       r19, r3
	  beq-      .loc_0xEDC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B83C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C860
	  addi      r0, r26, 0x3C
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0xE80
	  addi      r3, r19, 0x4
	  bl        -0x5D548
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xEAC
	  stw       r0, 0xEC(r18)
	  b         .loc_0xEAC

	.loc_0xE80:
	  addi      r3, r19, 0x4
	  bl        -0x5D578
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xEAC
	  stw       r0, 0xEC(r18)

	.loc_0xEAC:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0xEDC:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2B994
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7274
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x19505C
	  mr.       r19, r3
	  beq-      .loc_0x1024
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B984
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C9A8
	  addi      r0, r26, 0x3C
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0xFC8
	  addi      r3, r19, 0x4
	  bl        -0x5D690
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xFF4
	  stw       r0, 0xEC(r18)
	  b         .loc_0xFF4

	.loc_0xFC8:
	  addi      r3, r19, 0x4
	  bl        -0x5D6C0
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xFF4
	  stw       r0, 0xEC(r18)

	.loc_0xFF4:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x1024:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BADC
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x6270
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x1951A4
	  mr.       r19, r3
	  beq-      .loc_0x116C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BACC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1CAF0
	  addi      r0, r26, 0x44
	  stw       r0, 0x4(r19)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1110
	  addi      r3, r19, 0x4
	  bl        -0x5D7D8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x113C
	  stw       r0, 0xEC(r18)
	  b         .loc_0x113C

	.loc_0x1110:
	  addi      r3, r19, 0x4
	  bl        -0x5D808
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x113C
	  stw       r0, 0xEC(r18)

	.loc_0x113C:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x116C:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BC24
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x6270
	  addi      r4, r3, 0x5F63
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x1952EC
	  mr.       r19, r3
	  beq-      .loc_0x12B4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BC14
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1CC38
	  addi      r0, r26, 0x44
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1258
	  addi      r3, r19, 0x4
	  bl        -0x5D920
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1284
	  stw       r0, 0xEC(r18)
	  b         .loc_0x1284

	.loc_0x1258:
	  addi      r3, r19, 0x4
	  bl        -0x5D950
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1284
	  stw       r0, 0xEC(r18)

	.loc_0x1284:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x12B4:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BD6C
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x6270
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x195434
	  mr.       r19, r3
	  beq-      .loc_0x13FC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BD5C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1CD80
	  addi      r0, r26, 0x44
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x13A0
	  addi      r3, r19, 0x4
	  bl        -0x5DA68
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x13CC
	  stw       r0, 0xEC(r18)
	  b         .loc_0x13CC

	.loc_0x13A0:
	  addi      r3, r19, 0x4
	  bl        -0x5DA98
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x13CC
	  stw       r0, 0xEC(r18)

	.loc_0x13CC:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x13FC:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BEB4
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7270
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x19557C
	  mr.       r19, r3
	  beq-      .loc_0x1544
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BEA4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1CEC8
	  addi      r0, r26, 0x48
	  stw       r0, 0x4(r19)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x14E8
	  addi      r3, r19, 0x4
	  bl        -0x5DBB0
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1514
	  stw       r0, 0xEC(r18)
	  b         .loc_0x1514

	.loc_0x14E8:
	  addi      r3, r19, 0x4
	  bl        -0x5DBE0
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1514
	  stw       r0, 0xEC(r18)

	.loc_0x1514:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x1544:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BFFC
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7270
	  addi      r4, r3, 0x5F63
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x1956C4
	  mr.       r19, r3
	  beq-      .loc_0x168C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BFEC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D010
	  addi      r0, r26, 0x48
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1630
	  addi      r3, r19, 0x4
	  bl        -0x5DCF8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x165C
	  stw       r0, 0xEC(r18)
	  b         .loc_0x165C

	.loc_0x1630:
	  addi      r3, r19, 0x4
	  bl        -0x5DD28
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x165C
	  stw       r0, 0xEC(r18)

	.loc_0x165C:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x168C:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C144
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7270
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x19580C
	  mr.       r19, r3
	  beq-      .loc_0x17D4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2C134
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D158
	  addi      r0, r26, 0x48
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1778
	  addi      r3, r19, 0x4
	  bl        -0x5DE40
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x17A4
	  stw       r0, 0xEC(r18)
	  b         .loc_0x17A4

	.loc_0x1778:
	  addi      r3, r19, 0x4
	  bl        -0x5DE70
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x17A4
	  stw       r0, 0xEC(r18)

	.loc_0x17A4:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x17D4:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C28C
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7970
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x195954
	  mr.       r19, r3
	  beq-      .loc_0x191C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2C27C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D2A0
	  addi      r0, r26, 0x4C
	  stw       r0, 0x4(r19)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x18C0
	  addi      r3, r19, 0x4
	  bl        -0x5DF88
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x18EC
	  stw       r0, 0xEC(r18)
	  b         .loc_0x18EC

	.loc_0x18C0:
	  addi      r3, r19, 0x4
	  bl        -0x5DFB8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x18EC
	  stw       r0, 0xEC(r18)

	.loc_0x18EC:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x191C:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C3D4
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7970
	  addi      r4, r3, 0x5F63
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x195A9C
	  mr.       r19, r3
	  beq-      .loc_0x1A64
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2C3C4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D3E8
	  addi      r0, r26, 0x4C
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A08
	  addi      r3, r19, 0x4
	  bl        -0x5E0D0
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1A34
	  stw       r0, 0xEC(r18)
	  b         .loc_0x1A34

	.loc_0x1A08:
	  addi      r3, r19, 0x4
	  bl        -0x5E100
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1A34
	  stw       r0, 0xEC(r18)

	.loc_0x1A34:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x1A64:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C51C
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7970
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x195BE4
	  mr.       r19, r3
	  beq-      .loc_0x1BAC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2C50C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D530
	  addi      r0, r26, 0x4C
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1B50
	  addi      r3, r19, 0x4
	  bl        -0x5E218
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1B7C
	  stw       r0, 0xEC(r18)
	  b         .loc_0x1B7C

	.loc_0x1B50:
	  addi      r3, r19, 0x4
	  bl        -0x5E248
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1B7C
	  stw       r0, 0xEC(r18)

	.loc_0x1B7C:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x1BAC:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C664
	  li        r3, 0x12C
	  bl        -0x195D04
	  mr.       r18, r3
	  beq-      .loc_0x1C54
	  lfs       f2, -0x4188(r2)
	  lis       r3, 0x801E
	  subi      r4, r3, 0x1F4C
	  stfs      f2, 0x14(r18)
	  fmr       f1, f2
	  fmr       f0, f2
	  addi      r3, r18, 0x44
	  stfs      f2, 0x10(r18)
	  li        r5, 0
	  stfs      f2, 0xC(r18)
	  li        r6, 0x3C
	  stfs      f2, 0x20(r18)
	  li        r7, 0x3
	  stfs      f2, 0x1C(r18)
	  stfs      f2, 0x18(r18)
	  stfs      f1, 0x2C(r18)
	  stfs      f1, 0x28(r18)
	  stfs      f1, 0x24(r18)
	  stfs      f0, 0x40(r18)
	  stfs      f0, 0x3C(r18)
	  stfs      f0, 0x38(r18)
	  bl        0x37D08
	  lfs       f0, -0x4188(r2)
	  li        r0, 0
	  addi      r3, r18, 0
	  stfs      f0, 0x100(r18)
	  stfs      f0, 0xFC(r18)
	  stfs      f0, 0xF8(r18)
	  stfs      f0, 0x10C(r18)
	  stfs      f0, 0x108(r18)
	  stfs      f0, 0x104(r18)
	  stw       r0, 0x8(r18)
	  stw       r0, 0x110(r18)
	  stw       r0, 0x114(r18)
	  bl        0x1214

	.loc_0x1C54:
	  stw       r18, 0x34(r26)
	  li        r4, 0x7269
	  li        r5, 0x1
	  lwz       r3, 0x14(r26)
	  lwz       r18, 0x34(r26)
	  addi      r19, r3, 0x4
	  addi      r3, r19, 0
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x1C90
	  stw       r3, 0x8(r18)

	.loc_0x1C90:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6369
	  addi      r4, r4, 0x5F62
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x1CC0
	  stw       r3, 0x44(r18)

	.loc_0x1CC0:
	  addi      r3, r18, 0x44
	  bl        0x1084
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6369
	  addi      r4, r4, 0x5F72
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x1CF8
	  stw       r3, 0x80(r18)

	.loc_0x1CF8:
	  addi      r3, r18, 0x80
	  bl        0x104C
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6369
	  addi      r4, r4, 0x5F79
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x1D30
	  stw       r3, 0xBC(r18)

	.loc_0x1D30:
	  addi      r3, r18, 0xBC
	  bl        0x1014
	  mr        r3, r18
	  bl        0x8E4
	  li        r3, 0x8
	  bl        -0x195E8C
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x1D88
	  lwz       r18, 0x249C(r13)
	  mulli     r3, r18, 0x28
	  addi      r3, r3, 0x8
	  bl        -0x195EA8
	  lis       r4, 0x801E
	  subi      r4, r4, 0x28C0
	  addi      r7, r18, 0
	  li        r5, 0
	  li        r6, 0x28
	  bl        0x37D64
	  stw       r3, 0x0(r19)
	  li        r0, -0x1
	  stw       r0, 0x4(r19)

	.loc_0x1D88:
	  stw       r19, 0x5C(r26)
	  li        r18, 0
	  mr        r21, r18
	  lwz       r3, 0x18(r26)
	  lwz       r19, 0x5C(r26)
	  lwz       r22, 0x249C(r13)
	  addi      r20, r3, 0x4
	  b         .loc_0x1E50

	.loc_0x1DA8:
	  lbz       r5, 0x0(r28)
	  addi      r3, r1, 0x40C
	  crclr     6, 0x6
	  addi      r4, r13, 0x2620
	  addi      r5, r5, 0x1
	  bl        0x39690
	  lwz       r12, 0x0(r20)
	  mr        r3, r20
	  lbz       r0, 0x40D(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x40C(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x40E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x40F(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lwz       r0, 0x0(r19)
	  add       r24, r0, r21
	  stw       r3, 0x4(r24)
	  lwz       r3, 0x4(r24)
	  addi      r3, r3, 0x18
	  bl        -0x24A24
	  lwz       r4, 0x4(r24)
	  addi      r23, r3, 0
	  addi      r3, r4, 0x18
	  bl        -0x24A44
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x4(r24)
	  extsh     r3, r0
	  srawi     r0, r23, 0x1
	  sth       r3, 0xB8(r4)
	  extsh     r0, r0
	  sth       r0, 0xBA(r4)
	  li        r0, 0
	  addi      r21, r21, 0x28
	  stw       r0, 0x0(r24)
	  addi      r18, r18, 0x1
	  addi      r28, r28, 0x1

	.loc_0x1E50:
	  cmpw      r18, r22
	  blt+      .loc_0x1DA8
	  li        r21, 0
	  lwz       r18, 0x249C(r13)
	  addi      r23, r21, 0
	  addi      r20, r21, 0
	  b         .loc_0x1EA4

	.loc_0x1E6C:
	  lwz       r0, 0x0(r19)
	  li        r4, 0x280
	  li        r5, 0x1E0
	  add       r22, r0, r23
	  lwz       r3, 0x4(r22)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stw       r20, 0x0(r22)
	  lwz       r3, 0x4(r22)
	  bl        0x748
	  addi      r23, r23, 0x28
	  addi      r21, r21, 0x1

	.loc_0x1EA4:
	  cmpw      r21, r18
	  blt+      .loc_0x1E6C
	  li        r0, -0x1
	  stw       r0, 0x4(r19)
	  li        r3, 0xC
	  bl        -0x196000
	  cmplwi    r3, 0
	  beq-      .loc_0x1ED0
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  stw       r0, 0x4(r3)

	.loc_0x1ED0:
	  stw       r3, 0x60(r26)
	  addi      r3, r1, 0x404
	  crclr     6, 0x6
	  li        r18, 0
	  lwz       r5, 0x24(r26)
	  lwz       r29, 0x60(r26)
	  addi      r4, r13, 0x2628
	  addi      r30, r5, 0x4
	  li        r5, 0
	  bl        0x39558
	  b         .loc_0x1F14

	.loc_0x1EFC:
	  addi      r18, r18, 0x1
	  crclr     6, 0x6
	  addi      r5, r18, 0
	  addi      r3, r1, 0x404
	  addi      r4, r13, 0x2628
	  bl        0x3953C

	.loc_0x1F14:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x405(r1)
	  li        r5, 0
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x404(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x406(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x407(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  cmplwi    r3, 0
	  bne+      .loc_0x1EFC
	  stw       r18, 0x0(r29)
	  lwz       r0, 0x0(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1960A8
	  stw       r3, 0x4(r29)
	  lwz       r0, 0x0(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1960B8
	  li        r18, 0
	  stw       r3, 0x8(r29)
	  mr        r19, r18
	  b         .loc_0x20B4

	.loc_0x1F84:
	  addi      r5, r18, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x404
	  addi      r4, r13, 0x2630
	  bl        0x394B8
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x405(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x404(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x406(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x407(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x2018
	  lwz       r5, 0x4(r29)
	  li        r4, 0x1
	  stwx      r3, r5, r19
	  lwz       r3, 0x4(r29)
	  lwzx      r3, r3, r19
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x4(r29)
	  lwzx      r3, r3, r19
	  bl        -0x1D63C
	  lwz       r5, 0x4(r29)
	  mr        r4, r3
	  lwzx      r3, r5, r19
	  bl        -0x1D5C0

	.loc_0x2018:
	  addi      r5, r18, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x404
	  addi      r4, r13, 0x2628
	  bl        0x39424
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x405(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x404(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x406(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x407(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x20AC
	  lwz       r5, 0x8(r29)
	  li        r4, 0x1
	  stwx      r3, r5, r19
	  lwz       r3, 0x8(r29)
	  lwzx      r3, r3, r19
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8(r29)
	  lwzx      r3, r3, r19
	  bl        -0x1D6D0
	  lwz       r5, 0x8(r29)
	  mr        r4, r3
	  lwzx      r3, r5, r19
	  bl        -0x1D654

	.loc_0x20AC:
	  addi      r19, r19, 0x4
	  addi      r18, r18, 0x1

	.loc_0x20B4:
	  lwz       r0, 0x0(r29)
	  cmpw      r18, r0
	  blt+      .loc_0x1F84
	  li        r3, 0x88
	  bl        -0x19620C
	  addi      r31, r3, 0
	  mr.       r18, r31
	  beq-      .loc_0x242C
	  li        r0, 0
	  stw       r0, 0x4(r31)
	  li        r3, 0x100
	  stw       r0, 0x8(r31)
	  lfs       f6, -0x4184(r2)
	  stfs      f6, 0x10(r31)
	  fmr       f4, f6
	  fmr       f3, f6
	  stfs      f6, 0xC(r31)
	  fmr       f2, f6
	  fmr       f1, f6
	  lfs       f5, -0x4188(r2)
	  stfs      f5, 0x20(r31)
	  fmr       f0, f5
	  stfs      f5, 0x1C(r31)
	  stfs      f5, 0x18(r31)
	  stfs      f5, 0x14(r31)
	  stfs      f6, 0x28(r31)
	  stfs      f6, 0x24(r31)
	  stfs      f4, 0x30(r31)
	  stfs      f4, 0x2C(r31)
	  stw       r0, 0x34(r31)
	  stw       r0, 0x38(r31)
	  stfs      f3, 0x40(r31)
	  stfs      f3, 0x3C(r31)
	  stfs      f5, 0x50(r31)
	  stfs      f5, 0x4C(r31)
	  stfs      f5, 0x48(r31)
	  stfs      f5, 0x44(r31)
	  stfs      f2, 0x58(r31)
	  stfs      f2, 0x54(r31)
	  stfs      f1, 0x60(r31)
	  stfs      f1, 0x5C(r31)
	  stfs      f0, 0x84(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x7C(r31)
	  bl        -0x1962AC
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x2188
	  addi      r4, r17, 0xFC
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1DD5C

	.loc_0x2188:
	  stw       r19, 0x0(r31)
	  lis       r3, 0x7061
	  addi      r4, r3, 0x6C6C
	  lwz       r3, 0x0(r31)
	  li        r5, 0x1
	  addi      r7, r3, 0x4
	  lha       r3, 0x1C(r3)
	  lha       r0, 0x1C(r7)
	  mr        r30, r7
	  lha       r6, 0x1A(r7)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r7)
	  srawi     r0, r0, 0x1
	  sub       r6, r3, r6
	  extsh     r3, r0
	  srawi     r0, r6, 0x1
	  sth       r3, 0xB8(r7)
	  extsh     r0, r0
	  sth       r0, 0xBA(r7)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r30)
	  lis       r4, 0x7365
	  addi      r29, r3, 0
	  lwz       r12, 0x34(r12)
	  addi      r3, r30, 0
	  addi      r4, r4, 0x5F63
	  mtlr      r12
	  li        r5, 0x1
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x13
	  bne-      .loc_0x2228
	  lwz       r0, 0xF4(r3)
	  stw       r0, 0x68(r31)
	  lwz       r0, 0xF8(r3)
	  stw       r0, 0x6C(r31)

	.loc_0x2228:
	  li        r3, 0x20
	  bl        -0x196374
	  lis       r4, 0x801C
	  lis       r5, 0x801C
	  addi      r4, r4, 0x3C4C
	  addi      r5, r5, 0x3BF8
	  li        r6, 0xC
	  li        r7, 0x2
	  bl        0x37894
	  li        r28, 0
	  stw       r3, 0x64(r31)
	  addi      r27, r28, 0
	  addi      r25, r29, 0

	.loc_0x225C:
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x3FC
	  addi      r4, r13, 0x2638
	  bl        0x391E0
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x3FD(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x3FC(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x3FE(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x3FF(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  addi      r17, r3, 0
	  addi      r4, r29, 0
	  bl        -0x1D85C
	  lwz       r0, 0x64(r31)
	  addi      r4, r17, 0
	  li        r5, 0
	  add       r3, r0, r27
	  lwz       r3, 0x0(r3)
	  bl        -0x1ABEC
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x3FC
	  addi      r4, r13, 0x2640
	  bl        0x39170
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x3FD(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x3FC(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x3FE(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x3FF(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  lwz       r4, 0x64(r31)
	  cmplwi    r0, 0x12
	  add       r6, r4, r27
	  bne-      .loc_0x2350
	  stw       r3, 0x4(r6)
	  li        r5, 0
	  addi      r4, r29, 0
	  lwz       r3, 0x4(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x4(r6)
	  bl        -0x1D8F8

	.loc_0x2350:
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x3FC
	  addi      r4, r13, 0x2648
	  bl        0x390EC
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x3FD(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x3FC(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x3FE(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x3FF(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  lwz       r4, 0x64(r31)
	  cmplwi    r0, 0x12
	  add       r6, r4, r27
	  bne-      .loc_0x23D4
	  stw       r3, 0x8(r6)
	  li        r5, 0
	  addi      r4, r25, 0
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8(r6)
	  bl        -0x1D97C

	.loc_0x23D4:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x2
	  addi      r27, r27, 0xC
	  blt+      .loc_0x225C
	  lis       r17, 0x7A2A
	  lfs       f1, -0x417C(r2)
	  lfs       f2, -0x4178(r2)
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  addi      r3, r18, 0x4
	  addi      r6, r17, 0x2A6C
	  bl        -0x2910
	  lfs       f1, -0x4174(r2)
	  mr        r4, r30
	  lfs       f2, -0x4178(r2)
	  addi      r5, r29, 0
	  addi      r3, r18, 0x34
	  addi      r6, r17, 0x2A72
	  bl        -0x292C
	  addi      r3, r18, 0
	  li        r4, 0
	  bl        .loc_0x246C

	.loc_0x242C:
	  stw       r31, 0x70(r26)
	  li        r3, 0x8
	  bl        -0x19657C
	  cmplwi    r3, 0
	  beq-      .loc_0x2450
	  lfs       f0, -0x4170(r2)
	  li        r0, 0
	  stfs      f0, 0x0(r3)
	  stb       r0, 0x4(r3)

	.loc_0x2450:
	  stw       r3, 0x364(r26)
	  mr        r3, r26
	  lmw       r17, 0x474(r1)
	  lwz       r0, 0x4B4(r1)
	  addi      r1, r1, 0x4B0
	  mtlr      r0
	  blr

	.loc_0x246C:
	*/
}

/*
 * --INFO--
 * Address:	801DE714
 * Size:	000C14
 */
bool zen::DrawWorldMap::update(Controller* controller)
{
	bool res = false;
	if (_04 != -1) {
		if (_04 == 3) {
			DrawWMPause::returnStatusFlag pauseState = mPause.update(controller);
			if (pauseState != DrawWMPause::RETURN_Unk0) {
				if (pauseState == DrawWMPause::RETURN_Unk2) {
					_04 = -1;
					res = true;
					_08 = 6;
				} else {
					_04 = 2;
				}
			}
		} else if (_04 == 6) {
			if (mSelectDiary.update(controller) == ogDrawSelectDiary::SELECT_NULL) {
				_04 = 7;
				mWipeMgr->set(320, 240);
				mWipeMgr->open(0.5f);
				SeSystem::playSysSe(YMENU_SELECT2);
			}
		} else {
			switch (_04) {
			case 5:
				if (!mWipeMgr->isActive()) {
					_04 = 6;
					mSelectDiary.start();
				}
				mCursorMgr->update();
				updateScreens();
				break;
			case 7:
				if (!mWipeMgr->isActive()) {
					_04 = 2;
				}
				mCursorMgr->update();
				updateScreens();
				break;
			case 0:
				if (modeStart(controller)) {
					if (mStartMode) {
						_04 = 1;
					} else {
						_04 = 2;
					}
				}
				break;
			case 1:
				if (modeAppear(controller)) {
					_04 = 2;
				}
				break;
			case 4:
				if (modeConfirm(controller)) {
					_04 = 2;
				}
				break;
			case 2:
				if (controller->keyClick(KBBTN_START)) {
					mPause.start();
					_04 = 3;
				} else if (controller->keyClick(KBBTN_Y)) {
					if (mCursorMgr->isMoveOK()) {
						mWipeMgr->setDefault();
						mWipeMgr->close(0.5f, 320, 240);
						_04 = 5;
						SeSystem::playSysSe(YMENU_SELECT2);
					}
				} else if (modeOperation(controller)) {
					_04 = 8;
				}
				break;
			case 8:
				if (modeEnd(controller)) {
					_04 = -1;
					res = true;
				}
				break;
			}

			if (mCursorMgr->getStatusFlag() == WorldMapCursorMgr::UFO_Unk0 || mCursorMgr->isLanding()) {
				openMapInfo();
			}

			mEffectMgr2D->update();
			mMapImageMgr->update();
			mWipeMgr->update();
			mTitleMgr->update();
			mPartsInfoMgr->update();
		}
	}

	return res;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1D0(r1)
	  stfd      f31, 0x1C8(r1)
	  stfd      f30, 0x1C0(r1)
	  stfd      f29, 0x1B8(r1)
	  stfd      f28, 0x1B0(r1)
	  stmw      r19, 0x17C(r1)
	  mr        r30, r3
	  li        r31, 0
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xBEC
	  cmpwi     r0, 0x3
	  bne-      .loc_0x78
	  addi      r3, r30, 0x64
	  bl        0xB6AC
	  cmpwi     r3, 0
	  beq-      .loc_0xBEC
	  cmpwi     r3, 0x2
	  bne-      .loc_0x6C
	  li        r0, -0x1
	  stw       r0, 0x4(r30)
	  li        r0, 0x6
	  li        r31, 0x1
	  stw       r0, 0x8(r30)
	  b         .loc_0xBEC

	.loc_0x6C:
	  li        r0, 0x2
	  stw       r0, 0x4(r30)
	  b         .loc_0xBEC

	.loc_0x78:
	  cmpwi     r0, 0x6
	  bne-      .loc_0x2E4
	  addi      r3, r30, 0x74
	  bl        -0x4DE74
	  cmpwi     r3, -0x1
	  bne-      .loc_0xBEC
	  li        r0, 0x7
	  stw       r0, 0x4(r30)
	  li        r29, 0
	  lis       r20, 0x4330
	  lwz       r21, 0x58(r30)
	  lfd       f29, -0x4168(r2)
	  mr        r22, r21

	.loc_0xAC:
	  lwz       r3, 0x30(r22)
	  addi      r28, r22, 0xC
	  lha       r4, 0x18(r3)
	  lha       r0, 0x1C(r3)
	  lwz       r12, 0x0(r3)
	  sub       r5, r0, r4
	  lha       r4, 0x1A(r3)
	  lha       r0, 0x1E(r3)
	  srawi     r5, r5, 0x1
	  lwz       r12, 0x14(r12)
	  subfic    r23, r5, 0x140
	  sub       r0, r0, r4
	  srawi     r0, r0, 0x1
	  mtlr      r12
	  subfic    r24, r0, 0xF0
	  addi      r4, r23, 0
	  addi      r5, r24, 0
	  blrl
	  xoris     r3, r23, 0x8000
	  stw       r3, 0x174(r1)
	  xoris     r0, r24, 0x8000
	  addi      r29, r29, 0x1
	  stw       r20, 0x170(r1)
	  cmpwi     r29, 0x4
	  addi      r22, r22, 0x28
	  stw       r0, 0x16C(r1)
	  lfd       f0, 0x170(r1)
	  stw       r20, 0x168(r1)
	  fsubs     f2, f0, f29
	  lfd       f0, 0x168(r1)
	  stw       r3, 0x164(r1)
	  fsubs     f1, f0, f29
	  stfs      f2, 0xC(r28)
	  stw       r20, 0x160(r1)
	  stw       r0, 0x15C(r1)
	  lfd       f0, 0x160(r1)
	  stfs      f1, 0x10(r28)
	  fsubs     f1, f0, f29
	  stw       r20, 0x158(r1)
	  lfs       f2, 0x25EC(r13)
	  lfd       f0, 0x158(r1)
	  stfs      f2, 0x14(r28)
	  fsubs     f0, f0, f29
	  stfs      f1, 0x18(r28)
	  stfs      f0, 0x1C(r28)
	  lfs       f0, 0x25F0(r13)
	  stfs      f0, 0x20(r28)
	  blt+      .loc_0xAC
	  li        r29, 0
	  stw       r29, 0x0(r21)
	  addi      r25, r1, 0xF8
	  addi      r24, r1, 0xF4
	  lwz       r30, 0x58(r30)
	  addi      r23, r1, 0x100
	  lfs       f31, -0x4188(r2)
	  addi      r22, r1, 0xFC
	  addi      r21, r30, 0
	  stfs      f31, 0x4(r30)
	  lis       r20, 0x4330
	  lfs       f30, -0x4154(r2)
	  stfs      f30, 0x8(r30)
	  lfd       f29, -0x4168(r2)

	.loc_0x1A4:
	  lfs       f0, 0x10(r21)
	  addi      r28, r21, 0xC
	  fcmpo     cr0, f0, f31
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1C0
	  fadds     f0, f30, f0
	  b         .loc_0x1C4

	.loc_0x1C0:
	  fsubs     f0, f0, f30

	.loc_0x1C4:
	  lfs       f1, 0x0(r28)
	  fctiwz    f0, f0
	  fcmpo     cr0, f1, f31
	  stfd      f0, 0x158(r1)
	  lwz       r26, 0x15C(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1E8
	  fadds     f0, f30, f1
	  b         .loc_0x1EC

	.loc_0x1E8:
	  fsubs     f0, f1, f30

	.loc_0x1EC:
	  fctiwz    f0, f0
	  lwz       r3, 0x24(r28)
	  addi      r3, r3, 0x18
	  stfd      f0, 0x158(r1)
	  lwz       r27, 0x15C(r1)
	  bl        -0x263F0
	  lwz       r4, 0x24(r28)
	  srawi     r0, r3, 0x1
	  sub       r27, r27, r0
	  addi      r3, r4, 0x18
	  bl        -0x263F4
	  lwz       r5, 0x24(r28)
	  srawi     r3, r3, 0x1
	  addi      r4, r24, 0
	  lha       r0, 0x1A(r5)
	  addi      r5, r25, 0
	  sub       r26, r26, r3
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  addi      r3, r28, 0xC
	  addi      r6, r13, 0x25F4
	  stw       r20, 0x160(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f0, f0, f29
	  stfs      f0, 0xF8(r1)
	  lwz       r7, 0x24(r28)
	  lha       r0, 0x18(r7)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x16C(r1)
	  stw       r20, 0x168(r1)
	  lfd       f0, 0x168(r1)
	  fsubs     f0, f0, f29
	  stfs      f0, 0xF4(r1)
	  bl        -0x1812F8
	  xoris     r3, r26, 0x8000
	  xoris     r0, r27, 0x8000
	  stw       r3, 0x174(r1)
	  mr        r4, r22
	  stw       r0, 0x154(r1)
	  addi      r5, r23, 0
	  addi      r3, r28, 0x18
	  stw       r20, 0x170(r1)
	  addi      r6, r13, 0x25F8
	  stw       r20, 0x150(r1)
	  lfd       f1, 0x170(r1)
	  lfd       f0, 0x150(r1)
	  fsubs     f1, f1, f29
	  fsubs     f0, f0, f29
	  stfs      f1, 0x100(r1)
	  stfs      f0, 0xFC(r1)
	  bl        -0x18133C
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x4
	  addi      r21, r21, 0x28
	  blt+      .loc_0x1A4
	  li        r0, 0x2
	  stw       r0, 0x0(r30)
	  li        r0, 0x1
	  li        r3, 0x134
	  stb       r0, 0xAC(r30)
	  bl        -0x13967C
	  b         .loc_0xBEC

	.loc_0x2E4:
	  cmplwi    r0, 0x8
	  bgt-      .loc_0x930
	  lis       r3, 0x802E
	  addi      r3, r3, 0x58C0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x58(r30)
	  lbz       r0, 0xAC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x324
	  li        r0, 0x6
	  stw       r0, 0x4(r30)
	  addi      r3, r30, 0x74
	  bl        -0x4E4E8

	.loc_0x324:
	  lwz       r21, 0x34(r30)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x354
	  bge-      .loc_0x3E4
	  cmpwi     r0, 0
	  bge-      .loc_0x348
	  b         .loc_0x3E4
	  b         .loc_0x3E4

	.loc_0x348:
	  mr        r3, r21
	  bl        0x1F24
	  b         .loc_0x3E4

	.loc_0x354:
	  mr        r3, r21
	  bl        0x1A84
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3E4
	  lbz       r0, 0x35(r21)
	  cmplwi    r0, 0
	  beq-      .loc_0x37C
	  mr        r3, r21
	  bl        0x1998
	  b         .loc_0x3E4

	.loc_0x37C:
	  lbz       r0, 0x34(r21)
	  cmplwi    r0, 0
	  beq-      .loc_0x3B8
	  li        r0, 0x2
	  stw       r0, 0x4(r21)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3E4
	  bge-      .loc_0x3E4
	  cmpwi     r0, 0
	  bge-      .loc_0x3AC
	  b         .loc_0x3E4

	.loc_0x3AC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r21)
	  b         .loc_0x3E4

	.loc_0x3B8:
	  li        r0, 0
	  stw       r0, 0x4(r21)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3E4
	  bge-      .loc_0x3E4
	  cmpwi     r0, 0
	  bge-      .loc_0x3DC
	  b         .loc_0x3E4

	.loc_0x3DC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r21)

	.loc_0x3E4:
	  mr        r3, r21
	  bl        0x15D4
	  li        r20, 0
	  mulli     r0, r20, 0x3C
	  add       r19, r21, r0

	.loc_0x3F8:
	  lwz       r4, 0x8(r21)
	  addi      r3, r19, 0x44
	  addi      r4, r4, 0xC0
	  bl        0xF90
	  addi      r20, r20, 0x1
	  cmpwi     r20, 0x3
	  addi      r19, r19, 0x3C
	  blt+      .loc_0x3F8
	  mr        r3, r21
	  bl        0xC20
	  mr        r3, r30
	  bl        0x87E4
	  b         .loc_0x930
	  lwz       r3, 0x58(r30)
	  lbz       r0, 0xAC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x444
	  li        r0, 0x2
	  stw       r0, 0x4(r30)

	.loc_0x444:
	  lwz       r21, 0x34(r30)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x474
	  bge-      .loc_0x504
	  cmpwi     r0, 0
	  bge-      .loc_0x468
	  b         .loc_0x504
	  b         .loc_0x504

	.loc_0x468:
	  mr        r3, r21
	  bl        0x1E04
	  b         .loc_0x504

	.loc_0x474:
	  mr        r3, r21
	  bl        0x1964
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x504
	  lbz       r0, 0x35(r21)
	  cmplwi    r0, 0
	  beq-      .loc_0x49C
	  mr        r3, r21
	  bl        0x1878
	  b         .loc_0x504

	.loc_0x49C:
	  lbz       r0, 0x34(r21)
	  cmplwi    r0, 0
	  beq-      .loc_0x4D8
	  li        r0, 0x2
	  stw       r0, 0x4(r21)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x504
	  bge-      .loc_0x504
	  cmpwi     r0, 0
	  bge-      .loc_0x4CC
	  b         .loc_0x504

	.loc_0x4CC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r21)
	  b         .loc_0x504

	.loc_0x4D8:
	  li        r0, 0
	  stw       r0, 0x4(r21)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x504
	  bge-      .loc_0x504
	  cmpwi     r0, 0
	  bge-      .loc_0x4FC
	  b         .loc_0x504

	.loc_0x4FC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r21)

	.loc_0x504:
	  mr        r3, r21
	  bl        0x14B4
	  li        r20, 0
	  mulli     r0, r20, 0x3C
	  add       r19, r21, r0

	.loc_0x518:
	  lwz       r4, 0x8(r21)
	  addi      r3, r19, 0x44
	  addi      r4, r4, 0xC0
	  bl        0xE70
	  addi      r20, r20, 0x1
	  cmpwi     r20, 0x3
	  addi      r19, r19, 0x3C
	  blt+      .loc_0x518
	  mr        r3, r21
	  bl        0xB00
	  mr        r3, r30
	  bl        0x86C4
	  b         .loc_0x930
	  mr        r3, r30
	  bl        0x41A8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x574
	  li        r0, 0x1
	  stw       r0, 0x4(r30)
	  b         .loc_0x930

	.loc_0x574:
	  li        r0, 0x2
	  stw       r0, 0x4(r30)
	  b         .loc_0x930
	  mr        r3, r30
	  bl        0x45F0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  li        r0, 0x2
	  stw       r0, 0x4(r30)
	  b         .loc_0x930
	  mr        r3, r30
	  bl        0x7D38
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  li        r0, 0x2
	  stw       r0, 0x4(r30)
	  b         .loc_0x930
	  lwz       r3, 0x28(r4)
	  rlwinm.   r0,r3,0,7,7
	  beq-      .loc_0x5D8
	  addi      r3, r30, 0x64
	  bl        0xB0C4
	  li        r0, 0x3
	  stw       r0, 0x4(r30)
	  b         .loc_0x930

	.loc_0x5D8:
	  rlwinm.   r0,r3,0,16,16
	  beq-      .loc_0x8F8
	  lwz       r4, 0x34(r30)
	  li        r3, 0
	  lbz       r0, 0x35(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x604
	  lbz       r0, 0x34(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x604
	  li        r3, 0x1

	.loc_0x604:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  lwz       r26, 0x58(r30)
	  addi      r22, r1, 0xE0
	  lfs       f31, -0x4188(r2)
	  addi      r23, r1, 0xDC
	  lfs       f30, -0x4154(r2)
	  lfd       f29, -0x4168(r2)
	  addi      r21, r26, 0
	  addi      r24, r1, 0xE8
	  addi      r25, r1, 0xE4
	  li        r20, 0
	  lis       r28, 0x4330

	.loc_0x638:
	  lfs       f0, 0x10(r21)
	  addi      r19, r21, 0xC
	  fcmpo     cr0, f0, f31
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x654
	  fadds     f0, f30, f0
	  b         .loc_0x658

	.loc_0x654:
	  fsubs     f0, f0, f30

	.loc_0x658:
	  lfs       f1, 0x0(r19)
	  fctiwz    f0, f0
	  fcmpo     cr0, f1, f31
	  stfd      f0, 0x150(r1)
	  lwz       r29, 0x154(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x67C
	  fadds     f0, f30, f1
	  b         .loc_0x680

	.loc_0x67C:
	  fsubs     f0, f1, f30

	.loc_0x680:
	  fctiwz    f0, f0
	  lwz       r3, 0x24(r19)
	  addi      r3, r3, 0x18
	  stfd      f0, 0x150(r1)
	  lwz       r27, 0x154(r1)
	  bl        -0x26884
	  lwz       r4, 0x24(r19)
	  srawi     r0, r3, 0x1
	  sub       r27, r27, r0
	  addi      r3, r4, 0x18
	  bl        -0x26888
	  srawi     r0, r3, 0x1
	  lwz       r3, 0x24(r19)
	  sub       r29, r29, r0
	  lwz       r12, 0x0(r3)
	  addi      r4, r27, 0
	  addi      r5, r29, 0
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  xoris     r29, r29, 0x8000
	  xoris     r27, r27, 0x8000
	  stw       r29, 0x15C(r1)
	  mr        r4, r23
	  stw       r27, 0x164(r1)
	  addi      r5, r22, 0
	  addi      r3, r19, 0xC
	  stw       r28, 0x158(r1)
	  addi      r6, r13, 0x25EC
	  stw       r28, 0x160(r1)
	  lfd       f1, 0x158(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f1, f1, f29
	  fsubs     f0, f0, f29
	  stfs      f1, 0xE0(r1)
	  stfs      f0, 0xDC(r1)
	  bl        -0x181798
	  stw       r29, 0x16C(r1)
	  addi      r4, r25, 0
	  addi      r5, r24, 0
	  stw       r27, 0x174(r1)
	  addi      r3, r19, 0x18
	  addi      r6, r13, 0x25F0
	  stw       r28, 0x168(r1)
	  stw       r28, 0x170(r1)
	  lfd       f1, 0x168(r1)
	  lfd       f0, 0x170(r1)
	  fsubs     f1, f1, f29
	  fsubs     f0, f0, f29
	  stfs      f1, 0xE8(r1)
	  stfs      f0, 0xE4(r1)
	  bl        -0x1817D4
	  addi      r20, r20, 0x1
	  cmpwi     r20, 0x4
	  addi      r21, r21, 0x28
	  blt+      .loc_0x638
	  li        r0, 0
	  stw       r0, 0x0(r26)
	  li        r0, 0x2
	  mtctr     r0
	  lis       r3, 0x4330
	  lwz       r7, 0x58(r30)
	  lfs       f0, -0x4188(r2)
	  mr        r9, r7
	  stfs      f0, 0x4(r7)
	  lfs       f0, -0x4154(r2)
	  stfs      f0, 0x8(r7)
	  lfd       f3, -0x4168(r2)

	.loc_0x790:
	  lwz       r5, 0x30(r9)
	  lha       r0, 0x18(r5)
	  lha       r10, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  lha       r4, 0x1E(r5)
	  stw       r0, 0x154(r1)
	  xoris     r0, r10, 0x8000
	  lha       r6, 0x18(r5)
	  sub       r4, r4, r10
	  stw       r3, 0x150(r1)
	  lha       r5, 0x1C(r5)
	  stw       r0, 0x15C(r1)
	  sub       r0, r5, r6
	  lfd       f0, 0x150(r1)
	  srawi     r0, r0, 0x1
	  stw       r3, 0x158(r1)
	  subfic    r0, r0, 0x140
	  fsubs     f2, f0, f3
	  lfd       f0, 0x158(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  srawi     r4, r4, 0x1
	  subfic    r0, r4, 0xF0
	  fsubs     f1, f0, f3
	  xoris     r0, r0, 0x8000
	  stfs      f2, 0x18(r9)
	  stw       r3, 0x160(r1)
	  stw       r0, 0x16C(r1)
	  lfd       f0, 0x160(r1)
	  stfs      f1, 0x1C(r9)
	  fsubs     f1, f0, f3
	  stw       r3, 0x168(r1)
	  lfs       f2, 0x25F4(r13)
	  lfd       f0, 0x168(r1)
	  stfs      f2, 0x20(r9)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x24(r9)
	  stfs      f0, 0x28(r9)
	  lfs       f0, 0x25F8(r13)
	  stfs      f0, 0x2C(r9)
	  lwz       r5, 0x58(r9)
	  lha       r0, 0x18(r5)
	  lha       r10, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  lha       r4, 0x1E(r5)
	  stw       r0, 0x154(r1)
	  xoris     r0, r10, 0x8000
	  lha       r6, 0x18(r5)
	  sub       r4, r4, r10
	  stw       r3, 0x150(r1)
	  lha       r5, 0x1C(r5)
	  stw       r0, 0x15C(r1)
	  sub       r0, r5, r6
	  lfd       f0, 0x150(r1)
	  srawi     r0, r0, 0x1
	  stw       r3, 0x158(r1)
	  subfic    r0, r0, 0x140
	  fsubs     f2, f0, f3
	  lfd       f0, 0x158(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  srawi     r4, r4, 0x1
	  subfic    r0, r4, 0xF0
	  fsubs     f1, f0, f3
	  xoris     r0, r0, 0x8000
	  stfs      f2, 0x40(r9)
	  stw       r3, 0x160(r1)
	  stw       r0, 0x16C(r1)
	  lfd       f0, 0x160(r1)
	  stfs      f1, 0x44(r9)
	  fsubs     f1, f0, f3
	  stw       r3, 0x168(r1)
	  lfs       f2, 0x25F4(r13)
	  lfd       f0, 0x168(r1)
	  stfs      f2, 0x48(r9)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x4C(r9)
	  stfs      f0, 0x50(r9)
	  lfs       f0, 0x25F8(r13)
	  stfs      f0, 0x54(r9)
	  addi      r9, r9, 0x50
	  bdnz+     .loc_0x790
	  li        r4, 0x1
	  stw       r4, 0x0(r7)
	  li        r0, 0x5
	  li        r3, 0x134
	  stb       r4, 0xAC(r7)
	  stw       r0, 0x4(r30)
	  bl        -0x139C90
	  b         .loc_0x930

	.loc_0x8F8:
	  mr        r3, r30
	  bl        0x7174
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  li        r0, 0x8
	  stw       r0, 0x4(r30)
	  b         .loc_0x930
	  mr        r3, r30
	  bl        0x819C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  li        r0, -0x1
	  stw       r0, 0x4(r30)
	  li        r31, 0x1

	.loc_0x930:
	  lwz       r3, 0x34(r30)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x94C
	  lbz       r0, 0x34(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x954

	.loc_0x94C:
	  mr        r3, r30
	  bl        0x86C4

	.loc_0x954:
	  lwz       r3, 0x50(r30)
	  bl        0xAB1C
	  lwz       r3, 0x54(r30)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x9D4
	  bge-      .loc_0x97C
	  cmpwi     r0, 0
	  bge-      .loc_0x988
	  b         .loc_0x9E0

	.loc_0x97C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x9E0
	  b         .loc_0x9DC

	.loc_0x988:
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x9E0
	  rlwinm    r0,r0,2,0,29
	  add       r4, r3, r0
	  lwz       r4, 0xC(r4)
	  li        r5, 0x1
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r0, 0x8(r3)
	  lfs       f0, -0x4184(r2)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0xC(r3)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x9E0

	.loc_0x9D4:
	  bl        0x588
	  b         .loc_0x9E0

	.loc_0x9DC:
	  bl        0x494

	.loc_0x9E0:
	  lwz       r23, 0x58(r30)
	  li        r0, 0
	  stb       r0, 0xAC(r23)
	  lwz       r20, 0x0(r23)
	  cmpwi     r20, 0
	  beq-      .loc_0xBBC
	  blt-      .loc_0xBBC
	  cmpwi     r20, 0x3
	  bge-      .loc_0xBBC
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r23)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r23)
	  lfs       f0, 0x4(r23)
	  lfs       f1, 0x8(r23)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0xA30
	  stfs      f1, 0x4(r23)
	  mr        r20, r0

	.loc_0xA30:
	  lwz       r0, 0x0(r23)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xAA0
	  lfs       f1, 0x4(r23)
	  lfs       f0, 0x8(r23)
	  lfs       f2, -0x4150(r2)
	  fdivs     f0, f1, f0
	  fmuls     f1, f2, f0
	  bl        0x3C9F0
	  lfs       f3, -0x4184(r2)
	  lfs       f4, -0x4154(r2)
	  fsubs     f1, f3, f1
	  lfs       f2, -0x414C(r2)
	  lfs       f0, -0x4188(r2)
	  fmuls     f31, f4, f1
	  fsubs     f1, f3, f31
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xA88
	  fadds     f0, f4, f1
	  b         .loc_0xA8C

	.loc_0xA88:
	  fsubs     f0, f1, f4

	.loc_0xA8C:
	  fctiwz    f0, f0
	  stfd      f0, 0x150(r1)
	  lwz       r0, 0x154(r1)
	  rlwinm    r21,r0,0,24,31
	  b         .loc_0xAF8

	.loc_0xAA0:
	  lfs       f1, 0x4(r23)
	  lfs       f0, 0x8(r23)
	  lfs       f2, -0x4148(r2)
	  fdivs     f0, f1, f0
	  fmuls     f1, f2, f0
	  bl        0x3CB20
	  lfs       f2, -0x414C(r2)
	  fmr       f31, f1
	  lfs       f0, -0x4188(r2)
	  fmuls     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xAE0
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f2
	  b         .loc_0xAE8

	.loc_0xAE0:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f2, f0

	.loc_0xAE8:
	  fctiwz    f0, f0
	  stfd      f0, 0x150(r1)
	  lwz       r0, 0x154(r1)
	  rlwinm    r21,r0,0,24,31

	.loc_0xAF8:
	  lfs       f0, -0x4184(r2)
	  mr        r24, r23
	  lfs       f29, -0x4188(r2)
	  li        r22, 0
	  fsubs     f28, f0, f31
	  lfs       f30, -0x4154(r2)

	.loc_0xB10:
	  addi      r19, r24, 0xC
	  lfs       f1, 0x1C(r24)
	  lfs       f0, 0x28(r24)
	  fmuls     f1, f1, f28
	  fmuls     f0, f0, f31
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB3C
	  fadds     f0, f30, f0
	  b         .loc_0xB40

	.loc_0xB3C:
	  fsubs     f0, f0, f30

	.loc_0xB40:
	  lfs       f1, 0xC(r19)
	  fctiwz    f2, f0
	  lfs       f0, 0x18(r19)
	  fmuls     f1, f1, f28
	  fmuls     f0, f0, f31
	  stfd      f2, 0x150(r1)
	  lwz       r5, 0x154(r1)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB74
	  fadds     f0, f30, f0
	  b         .loc_0xB78

	.loc_0xB74:
	  fsubs     f0, f0, f30

	.loc_0xB78:
	  lwz       r3, 0x24(r19)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x150(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x154(r1)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24(r19)
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x4
	  stb       r21, 0xF0(r3)
	  addi      r24, r24, 0x28
	  blt+      .loc_0xB10
	  stw       r20, 0x0(r23)
	  li        r0, 0x1
	  stb       r0, 0xAC(r23)

	.loc_0xBBC:
	  li        r20, 0
	  lwz       r22, 0x5C(r30)
	  mulli     r19, r20, 0x28
	  lwz       r21, 0x249C(r13)
	  b         .loc_0xBE4

	.loc_0xBD0:
	  lwz       r0, 0x0(r22)
	  add       r3, r0, r19
	  bl        .loc_0xC14
	  addi      r19, r19, 0x28
	  addi      r20, r20, 0x1

	.loc_0xBE4:
	  cmpw      r20, r21
	  blt+      .loc_0xBD0

	.loc_0xBEC:
	  mr        r3, r31
	  lmw       r19, 0x17C(r1)
	  lwz       r0, 0x1D4(r1)
	  lfd       f31, 0x1C8(r1)
	  lfd       f30, 0x1C0(r1)
	  lfd       f29, 0x1B8(r1)
	  lfd       f28, 0x1B0(r1)
	  addi      r1, r1, 0x1D0
	  mtlr      r0
	  blr

	.loc_0xC14:
	*/
}

/*
 * --INFO--
 * Address:	801E0D38
 * Size:	000134
 */
void zen::DrawWorldMap::draw(Graphics& gfx)
{
	if (_04 != 6) {
		mBackScreen->draw();
		mLineScreen->draw();
		mPointScreen->draw();
		mData1Screen->draw();
		mData2Screen->draw();
		mMoniScreen->draw();
		mIconScreen->draw();
		mTitleScreen->draw();
		mEffectMgr2D->draw(gfx);
		mConfirmMgr->draw(gfx);
		mWipeScreen->draw();
	} else {
		mSelectDiary.draw(gfx);
	}

	mPause.draw(gfx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000AA4
 */
void zen::DrawWorldMap::setCoursePoint(zen::DrawWorldMap::startPlaceFlag placeFlag)
{
	switch (placeFlag) {
	case PLACE_Unk0:
		mCoursePointMgr->start(WM_Practice);
		break;
	case PLACE_Unk1:
		mCoursePointMgr->start(WM_Forest);
		break;
	case PLACE_Unk2:
		mCoursePointMgr->start(WM_Cave);
		break;
	case PLACE_Unk3:
		mCoursePointMgr->start(WM_Yakushima);
		break;
	case PLACE_Unk4:
		mCoursePointMgr->start(WM_Last);
		break;
	default:
		PRINT("unknown place no : %d \n", placeFlag);
		mCoursePointMgr->start(WM_Practice);
		break;
	}
}

/*
 * --INFO--
 * Address:	801E0E6C
 * Size:	001B78
 */
void zen::DrawWorldMap::start(zen::DrawWorldMap::startModeFlag modeFlag, zen::DrawWorldMap::startPlaceFlag placeFlag)
{
	mStartMode = modeFlag;
	_04        = 0;
	_0C        = 0.0f;
	mEffectMgr2D->killAll(true);
	_08 = 5;

	P2DPaneLibrary::makeResident(mWipeScreen->getScreenPtr());
	P2DPaneLibrary::makeResident(mMoniScreen->getScreenPtr());
	P2DPaneLibrary::makeResident(mIconScreen->getScreenPtr());
	P2DPaneLibrary::makeResident(mTitleScreen->getScreenPtr());
	P2DPaneLibrary::makeResident(mData1Screen->getScreenPtr());
	P2DPaneLibrary::makeResident(mData2Screen->getScreenPtr());
	P2DPaneLibrary::makeResident(mPointScreen->getScreenPtr());
	P2DPaneLibrary::makeResident(mLineScreen->getScreenPtr());
	P2DPaneLibrary::makeResident(mBackScreen->getScreenPtr());

	mCursorMgr->init();
	setCoursePoint(placeFlag);

	int x;
	int y;
	mCoursePointMgr->getLandPos(&x, &y);
	mCursorMgr->set(x, y, 0.0f);

	mCoursePointMgr->getStayPos(&x, &y);
	mCursorMgr->move(x, y, false);

	if (mStartMode != START_Unk0) {
		switch (mStartMode) {
		case START_Unk1:
			mCoursePointMgr->appear(WM_Forest);
			break;
		case START_Unk2:
			mCoursePointMgr->appear(WM_Cave);
			break;
		case START_Unk3:
			mCoursePointMgr->appear(WM_Yakushima);
			break;
		case START_Unk4:
			mCoursePointMgr->appear(WM_Last);
			mShootingStarMgr->rapidFire();
			break;
		default:
			PRINT("unknown startMode %d \n", mStartMode);
			ERROR("unknown startMode %d \n", mStartMode);
			break;
		}
	}

	mMapImageMgr->init();

	if (playerState) {
		P2DPane* blueCount = mData1Screen->getScreenPtr()->search('p_bc', true);
		if (!playerState->displayPikiCount(Blue)) {
			blueCount->hide();
		}
		P2DPane* redCount = mData1Screen->getScreenPtr()->search('p_rc', true);
		if (!playerState->displayPikiCount(Red)) {
			redCount->hide();
		}
		P2DPane* yellowCount = mData1Screen->getScreenPtr()->search('p_yc', true);
		if (!playerState->displayPikiCount(Yellow)) {
			yellowCount->hide();
		}
	}

	mTitleMgr->init();
	mPartsInfoMgr->init();
	mPartsInfoMgr->setActiveMapNo(mCoursePointMgr->getSelectCourseNumber());
	mWipeMgr->init();
	mWipeMgr->set(320, 240);
	mWipeMgr->open(1.0f);
}

/*
 * --INFO--
 * Address:	801E2E0C
 * Size:	00047C
 */
bool zen::DrawWorldMap::modeStart(Controller* controller)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  li        r31, 0
	  stw       r30, 0xD0(r1)
	  mr        r30, r3
	  stw       r29, 0xCC(r1)
	  stw       r28, 0xC8(r1)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f1, f1, f0
	  stfs      f1, 0xC(r3)
	  lfs       f0, -0x4184(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x50
	  stfs      f0, 0xC(r30)

	.loc_0x50:
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4184(r2)
	  lwz       r3, 0x28(r30)
	  fdivs     f30, f1, f0
	  lfs       f0, -0x4148(r2)
	  lha       r28, 0x1E(r3)
	  addi      r29, r3, 0x4
	  fmuls     f31, f0, f30
	  fmr       f1, f31
	  bl        0x38E68
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xD0
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xD8

	.loc_0xD0:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0xD8:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xC0(r1)
	  mtlr      r12
	  lwz       r4, 0xC4(r1)
	  blrl
	  lwz       r3, 0x2C(r30)
	  fmr       f1, f31
	  lha       r28, 0x1E(r3)
	  addi      r29, r3, 0x4
	  bl        0x38DD0
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xBC(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xB8(r1)
	  lfd       f2, 0xB8(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x168
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x170

	.loc_0x168:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x170:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xB8(r1)
	  mtlr      r12
	  lwz       r4, 0xBC(r1)
	  blrl
	  lwz       r3, 0x18(r30)
	  fmr       f1, f31
	  addi      r29, r3, 0x4
	  bl        0x38D3C
	  lha       r4, 0x1A(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1E(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1FC
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x204

	.loc_0x1FC:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x204:
	  fctiwz    f0, f0
	  fmr       f1, f31
	  stfd      f0, 0xB8(r1)
	  lwz       r28, 0xBC(r1)
	  bl        0x38CC8
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x270
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x278

	.loc_0x270:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x278:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xB8(r1)
	  mtlr      r12
	  lwz       r4, 0xBC(r1)
	  blrl
	  lwz       r3, 0x1C(r30)
	  fmr       f1, f31
	  lha       r28, 0x1E(r3)
	  addi      r29, r3, 0x4
	  bl        0x38C30
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x308
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x310

	.loc_0x308:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x310:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xB8(r1)
	  mtlr      r12
	  lwz       r4, 0xBC(r1)
	  blrl
	  fmr       f1, f31
	  bl        0x38BA4
	  lwz       r3, 0x20(r30)
	  lfs       f3, -0x4184(r2)
	  addi      r6, r3, 0x4
	  lha       r5, 0x1E(r3)
	  lha       r4, 0x22(r3)
	  fsubs     f0, f3, f1
	  lfs       f2, -0x417C(r2)
	  fmr       f1, f31
	  sub       r4, r4, r5
	  fmuls     f0, f2, f0
	  lha       r3, 0x1C(r3)
	  srawi     r4, r4, 0x1
	  lha       r0, 0x1C(r6)
	  fadds     f0, f3, f0
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r6)
	  extsh     r0, r4
	  sth       r0, 0xBA(r6)
	  stfs      f0, 0xC0(r6)
	  stfs      f0, 0xC4(r6)
	  stfs      f0, 0xC8(r6)
	  lwz       r3, 0x24(r30)
	  lha       r28, 0x1E(r3)
	  addi      r29, r3, 0x4
	  bl        0x38B38
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x4138(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x400
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x408

	.loc_0x400:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x408:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xB8(r1)
	  mtlr      r12
	  lwz       r4, 0xBC(r1)
	  blrl
	  lwz       r3, 0x70(r30)
	  li        r4, 0
	  bl        -0x5C88
	  lfs       f0, -0x4184(r2)
	  fcmpu     cr0, f0, f30
	  bne-      .loc_0x448
	  li        r31, 0x1

	.loc_0x448:
	  mr        r3, r30
	  bl        0x40C4
	  mr        r3, r31
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  lwz       r29, 0xCC(r1)
	  lwz       r28, 0xC8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E3288
 * Size:	002744
 */
bool zen::DrawWorldMap::modeAppear(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1C0(r1)
	  stmw      r27, 0x1AC(r1)
	  li        r29, 0
	  mr        r30, r3
	  li        r31, 0
	  lwz       r28, 0x38(r3)
	  stw       r29, 0x134(r28)
	  lwz       r0, 0x0(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x50
	  bge-      .loc_0x70
	  cmpwi     r0, 0
	  bge-      .loc_0x40
	  b         .loc_0x70

	.loc_0x40:
	  addi      r3, r28, 0
	  li        r5, 0
	  bl        0x2910
	  b         .loc_0x70

	.loc_0x50:
	  mr        r3, r28
	  bl        .loc_0x2744
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x70
	  stw       r29, 0x0(r28)
	  li        r0, 0x40
	  stw       r0, 0x134(r28)

	.loc_0x70:
	  lwz       r3, 0x38(r30)
	  lwz       r0, 0x134(r3)
	  rlwinm.   r0,r0,0,25,25
	  beq-      .loc_0x2628
	  lwz       r4, 0x4(r3)
	  li        r3, -0x1
	  cmplwi    r4, 0
	  beq-      .loc_0x94
	  lwz       r3, 0x10(r4)

	.loc_0x94:
	  lwz       r0, 0x0(r30)
	  cmpw      r0, r3
	  beq-      .loc_0xA8
	  mr        r3, r30
	  bl        0x40CC

	.loc_0xA8:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x1310
	  bge-      .loc_0xC8
	  cmpwi     r0, 0x1
	  beq-      .loc_0xD4
	  bge-      .loc_0x9E8
	  b         .loc_0x255C

	.loc_0xC8:
	  cmpwi     r0, 0x5
	  bge-      .loc_0x255C
	  b         .loc_0x1C38

	.loc_0xD4:
	  li        r0, 0x1
	  cmpwi     r0, 0x2
	  beq-      .loc_0x3F8
	  bge-      .loc_0xF4
	  cmpwi     r0, 0
	  beq-      .loc_0x104
	  bge-      .loc_0x27C
	  b         .loc_0x86C

	.loc_0xF4:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x6F0
	  bge-      .loc_0x86C
	  b         .loc_0x574

	.loc_0x104:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x150
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x150:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x194
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x194:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x1D8
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x1D8:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x21C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x21C:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x25C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x25C:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x738
	  b         .loc_0x255C

	.loc_0x27C:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C8
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x2C8:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x30C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x30C:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x350
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x350:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x394
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x394:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x3D4
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x3D4:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x1(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x8B4
	  b         .loc_0x255C

	.loc_0x3F8:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x444
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x444:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x488
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x488:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x4CC
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x4CC:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x510
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x510:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x550
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x550:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x2(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0xA30
	  b         .loc_0x255C

	.loc_0x574:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C0
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x5C0:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x604
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x604:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x648
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x648:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x68C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x68C:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x6CC
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x6CC:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x3(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0xBAC
	  b         .loc_0x255C

	.loc_0x6F0:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x73C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x73C:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x780
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x780:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x7C4
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x7C4:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x808
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x808:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x848
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x848:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x4(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0xD28
	  b         .loc_0x255C

	.loc_0x86C:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x8BC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x8BC:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x900
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x900:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x944
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x944:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x988
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x988:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x9C8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x9C8:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0xEA4
	  b         .loc_0x255C

	.loc_0x9E8:
	  li        r0, 0x2
	  cmpwi     r0, 0x2
	  b         .loc_0xD14
	  bge-      .loc_0xA08
	  cmpwi     r0, 0
	  beq-      .loc_0xA18
	  bge-      .loc_0xB94
	  b         .loc_0x1194

	.loc_0xA08:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x1014
	  bge-      .loc_0x1194
	  b         .loc_0xE94

	.loc_0xA18:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0xA68
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xA68:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xAAC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xAAC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xAF0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xAF0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xB34
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xB34:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xB74
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xB74:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1050
	  b         .loc_0x255C

	.loc_0xB94:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0xBE4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xBE4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xC28
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xC28:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xC6C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xC6C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xCB0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xCB0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xCF0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xCF0:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x1(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x11D0
	  b         .loc_0x255C

	.loc_0xD14:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0xD64
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xD64:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xDA8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xDA8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xDEC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xDEC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xE30
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xE30:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xE70
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xE70:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x2(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1350
	  b         .loc_0x255C

	.loc_0xE94:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0xEE4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xEE4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xF28
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xF28:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xF6C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xF6C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xFB0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xFB0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xFF0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xFF0:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x3(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x14D0
	  b         .loc_0x255C

	.loc_0x1014:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1064
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1064:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x10A8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x10A8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x10EC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x10EC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1130
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1130:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1170
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1170:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x4(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1650
	  b         .loc_0x255C

	.loc_0x1194:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x11E4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x11E4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1228
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1228:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x126C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x126C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x12B0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x12B0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x12F0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x12F0:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x17CC
	  b         .loc_0x255C

	.loc_0x1310:
	  li        r0, 0x3
	  cmpwi     r0, 0x2
	  beq-      .loc_0x163C
	  bge-      .loc_0x1330
	  cmpwi     r0, 0
	  beq-      .loc_0x1340
	  bge-      .loc_0x14BC
	  b         .loc_0x1ABC

	.loc_0x1330:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x193C
	  bge-      .loc_0x1ABC
	  b         .loc_0x17BC

	.loc_0x1340:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1390
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1390:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x13D4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x13D4:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1418
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1418:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x145C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x145C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x149C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x149C:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1978
	  b         .loc_0x255C

	.loc_0x14BC:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x150C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x150C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1550
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1550:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1594
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1594:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x15D8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x15D8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1618
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1618:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x1(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1AF8
	  b         .loc_0x255C

	.loc_0x163C:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x168C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x168C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x16D0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x16D0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1714
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1714:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1758
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1758:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1798
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1798:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x2(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1C78
	  b         .loc_0x255C

	.loc_0x17BC:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x180C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x180C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1850
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1850:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1894
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1894:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x18D8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x18D8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1918
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1918:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x3(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1DF8
	  b         .loc_0x255C

	.loc_0x193C:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x198C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x198C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x19D0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x19D0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1A14
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1A14:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1A58
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1A58:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1A98
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1A98:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x4(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1F78
	  b         .loc_0x255C

	.loc_0x1ABC:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1B0C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1B0C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1B50
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1B50:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1B94
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1B94:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1BD8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1BD8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1C18
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1C18:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x20F4
	  b         .loc_0x255C

	.loc_0x1C38:
	  li        r0, 0x4
	  cmpwi     r0, 0x2
	  beq-      .loc_0x1F64
	  bge-      .loc_0x1C58
	  cmpwi     r0, 0
	  beq-      .loc_0x1C68
	  bge-      .loc_0x1DE4
	  b         .loc_0x23E4

	.loc_0x1C58:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x2264
	  bge-      .loc_0x23E4
	  b         .loc_0x20E4

	.loc_0x1C68:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1CB8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1CB8:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1CFC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1CFC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1D40
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1D40:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1D84
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1D84:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1DC4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1DC4:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x22A0
	  b         .loc_0x255C

	.loc_0x1DE4:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1E34
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1E34:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1E78
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1E78:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1EBC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1EBC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1F00
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1F00:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1F40
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1F40:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x1(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x2420
	  b         .loc_0x255C

	.loc_0x1F64:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1FB4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1FB4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1FF8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1FF8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x203C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x203C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x2080
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2080:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x20C0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x20C0:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x2(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x25A0
	  b         .loc_0x255C

	.loc_0x20E4:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x2134
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2134:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x2178
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2178:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x21BC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x21BC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x2200
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2200:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x2240
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2240:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x3(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x2720
	  b         .loc_0x255C

	.loc_0x2264:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x22B4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x22B4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x22F8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x22F8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x233C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x233C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x2380
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2380:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x23C0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x23C0:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x4(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x28A0
	  b         .loc_0x255C

	.loc_0x23E4:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x2434
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2434:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x2478
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2478:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x24BC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x24BC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x2500
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2500:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x2540
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2540:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x2A1C

	.loc_0x255C:
	  lwz       r3, 0x38(r30)
	  li        r4, 0
	  lwz       r31, 0x34(r30)
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x35(r31)
	  lwz       r3, 0x24(r3)
	  cmplwi    r0, 0
	  lha       r28, 0x18(r3)
	  lha       r29, 0x1A(r3)
	  bne-      .loc_0x2624
	  lbz       r3, 0x34(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x2594
	  li        r4, 0x1

	.loc_0x2594:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x2624
	  cmplwi    r3, 0
	  bne-      .loc_0x25B8
	  lbz       r0, 0x35(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x25B8
	  li        r3, 0x123
	  bl        -0x1404C8

	.loc_0x25B8:
	  li        r0, 0x1
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x25E4
	  bge-      .loc_0x25E4
	  cmpwi     r0, 0
	  bge-      .loc_0x25DC
	  b         .loc_0x25E4

	.loc_0x25DC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r31)

	.loc_0x25E4:
	  xoris     r0, r28, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x1A4(r1)
	  xoris     r0, r29, 0x8000
	  lis       r3, 0x4330
	  stw       r3, 0x1A0(r1)
	  stw       r0, 0x19C(r1)
	  lfd       f0, 0x1A0(r1)
	  stw       r3, 0x198(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x198(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r31)
	  stfs      f0, 0x10(r31)
	  lfs       f0, 0x2564(r13)
	  stfs      f0, 0x14(r31)

	.loc_0x2624:
	  li        r31, 0x1

	.loc_0x2628:
	  lwz       r27, 0x34(r30)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2658
	  bge-      .loc_0x26E8
	  cmpwi     r0, 0
	  bge-      .loc_0x264C
	  b         .loc_0x26E8
	  b         .loc_0x26E8

	.loc_0x264C:
	  mr        r3, r27
	  bl        -0x4F54
	  b         .loc_0x26E8

	.loc_0x2658:
	  mr        r3, r27
	  bl        -0x53F4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x26E8
	  lbz       r0, 0x35(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x2680
	  mr        r3, r27
	  bl        -0x54E0
	  b         .loc_0x26E8

	.loc_0x2680:
	  lbz       r0, 0x34(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x26BC
	  li        r0, 0x2
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x26E8
	  bge-      .loc_0x26E8
	  cmpwi     r0, 0
	  bge-      .loc_0x26B0
	  b         .loc_0x26E8

	.loc_0x26B0:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)
	  b         .loc_0x26E8

	.loc_0x26BC:
	  li        r0, 0
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x26E8
	  bge-      .loc_0x26E8
	  cmpwi     r0, 0
	  bge-      .loc_0x26E0
	  b         .loc_0x26E8

	.loc_0x26E0:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)

	.loc_0x26E8:
	  mr        r3, r27
	  bl        -0x58A4
	  li        r28, 0
	  mulli     r0, r28, 0x3C
	  add       r29, r27, r0

	.loc_0x26FC:
	  lwz       r4, 0x8(r27)
	  addi      r3, r29, 0x44
	  addi      r4, r4, 0xC0
	  bl        -0x5EE8
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  addi      r29, r29, 0x3C
	  blt+      .loc_0x26FC
	  mr        r3, r27
	  bl        -0x6258
	  mr        r3, r30
	  bl        0x196C
	  mr        r3, r31
	  lmw       r27, 0x1AC(r1)
	  lwz       r0, 0x1C4(r1)
	  addi      r1, r1, 0x1C0
	  mtlr      r0
	  blr

	.loc_0x2744:
	*/
}

/*
 * --INFO--
 * Address:	801E59CC
 * Size:	000214
 */
bool zen::WorldMapCoursePointMgr::modeAppear()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stfd      f30, 0xC0(r1)
	  stfd      f29, 0xB8(r1)
	  stfd      f28, 0xB0(r1)
	  stmw      r25, 0x94(r1)
	  mr        r26, r3
	  addi      r28, r26, 0x8
	  li        r29, 0
	  li        r27, 0
	  lis       r31, 0x4330
	  lfs       f29, -0x4188(r2)
	  lfd       f30, -0x4168(r2)
	  lwz       r30, 0x2608(r13)
	  lfs       f28, -0x4154(r2)
	  lfs       f31, -0x4184(r2)
	  lwz       r25, 0x260C(r13)

	.loc_0x4C:
	  stw       r30, 0x0(r28)
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x158
	  bge-      .loc_0x70
	  cmpwi     r0, 0
	  beq-      .loc_0x1CC
	  bge-      .loc_0x7C
	  b         .loc_0x1CC

	.loc_0x70:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x1CC
	  b         .loc_0x198

	.loc_0x7C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f28
	  stfs      f0, 0x8(r28)
	  ble-      .loc_0x1CC
	  stfs      f29, 0x70(r1)
	  addi      r5, r1, 0x68
	  li        r4, 0x2E
	  stfs      f29, 0x6C(r1)
	  li        r6, 0
	  li        r7, 0
	  stfs      f29, 0x68(r1)
	  lwz       r9, 0x14(r28)
	  lha       r10, 0x18(r9)
	  lha       r0, 0x1C(r9)
	  lha       r8, 0x1A(r9)
	  lha       r3, 0x1E(r9)
	  sub       r0, r0, r10
	  srawi     r0, r0, 0x1
	  lha       r9, 0x1A(r9)
	  sub       r8, r3, r8
	  add       r3, r10, r0
	  srawi     r0, r8, 0x1
	  xoris     r3, r3, 0x8000
	  add       r0, r9, r0
	  stw       r3, 0x8C(r1)
	  subfic    r0, r0, 0x1E0
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x88(r1)
	  stw       r0, 0x84(r1)
	  lfd       f0, 0x88(r1)
	  stw       r31, 0x80(r1)
	  fsubs     f1, f0, f30
	  lfd       f0, 0x80(r1)
	  fsubs     f0, f0, f30
	  stfs      f1, 0x68(r1)
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x2604(r13)
	  stfs      f0, 0x70(r1)
	  lwz       r3, 0x31C0(r13)
	  bl        0x404C
	  lwz       r3, 0x31C0(r13)
	  addi      r5, r1, 0x68
	  li        r4, 0x2F
	  li        r6, 0
	  li        r7, 0
	  bl        0x4034
	  li        r3, 0x126
	  bl        -0x14079C
	  li        r0, 0x2
	  stw       r0, 0x4(r28)
	  stfs      f29, 0x8(r28)
	  b         .loc_0x1CC

	.loc_0x158:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  stfs      f0, 0x8(r28)
	  ble-      .loc_0x1CC
	  stfs      f29, 0x8(r28)
	  li        r0, 0x3
	  li        r4, 0x1
	  stw       r0, 0x4(r28)
	  lwz       r3, 0x1C(r28)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x1CC

	.loc_0x198:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  stfs      f0, 0x8(r28)
	  ble-      .loc_0x1CC
	  stfs      f29, 0x8(r28)
	  li        r0, 0
	  stw       r0, 0x4(r28)
	  lwz       r0, 0x0(r28)
	  or        r0, r0, r25
	  stw       r0, 0x0(r28)

	.loc_0x1CC:
	  lwz       r0, 0x0(r28)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x1DC
	  li        r29, 0x1

	.loc_0x1DC:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x5
	  addi      r28, r28, 0x3C
	  blt+      .loc_0x4C
	  mr        r3, r29
	  lmw       r25, 0x94(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lfd       f29, 0xB8(r1)
	  lfd       f28, 0xB0(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E5BE0
 * Size:	0005A4
 */
bool zen::WorldMapCoursePointMgr::modeOperation(Controller*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x178(r1)
	  stfd      f31, 0x170(r1)
	  stfd      f30, 0x168(r1)
	  stfd      f29, 0x160(r1)
	  stfd      f28, 0x158(r1)
	  stmw      r24, 0x138(r1)
	  mr        r25, r3
	  mr        r26, r4
	  mr        r27, r5
	  addi      r29, r25, 0x8
	  li        r28, 0
	  lis       r31, 0x4330
	  lfs       f29, -0x4188(r2)
	  lfd       f30, -0x4168(r2)
	  lwz       r30, 0x2608(r13)
	  lfs       f28, -0x4154(r2)
	  lfs       f31, -0x4184(r2)
	  lwz       r24, 0x260C(r13)

	.loc_0x50:
	  stw       r30, 0x0(r29)
	  lwz       r0, 0x4(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x15C
	  bge-      .loc_0x74
	  cmpwi     r0, 0
	  beq-      .loc_0x1D0
	  bge-      .loc_0x80
	  b         .loc_0x1D0

	.loc_0x74:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x1D0
	  b         .loc_0x19C

	.loc_0x80:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f28
	  stfs      f0, 0x8(r29)
	  ble-      .loc_0x1D0
	  stfs      f29, 0x114(r1)
	  addi      r5, r1, 0x10C
	  li        r4, 0x2E
	  stfs      f29, 0x110(r1)
	  li        r6, 0
	  li        r7, 0
	  stfs      f29, 0x10C(r1)
	  lwz       r9, 0x14(r29)
	  lha       r10, 0x18(r9)
	  lha       r0, 0x1C(r9)
	  lha       r8, 0x1A(r9)
	  lha       r3, 0x1E(r9)
	  sub       r0, r0, r10
	  srawi     r0, r0, 0x1
	  lha       r9, 0x1A(r9)
	  sub       r8, r3, r8
	  add       r3, r10, r0
	  srawi     r0, r8, 0x1
	  xoris     r3, r3, 0x8000
	  add       r0, r9, r0
	  stw       r3, 0x134(r1)
	  subfic    r0, r0, 0x1E0
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x130(r1)
	  stw       r0, 0x12C(r1)
	  lfd       f0, 0x130(r1)
	  stw       r31, 0x128(r1)
	  fsubs     f1, f0, f30
	  lfd       f0, 0x128(r1)
	  fsubs     f0, f0, f30
	  stfs      f1, 0x10C(r1)
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x2604(r13)
	  stfs      f0, 0x114(r1)
	  lwz       r3, 0x31C0(r13)
	  bl        0x3E34
	  lwz       r3, 0x31C0(r13)
	  addi      r5, r1, 0x10C
	  li        r4, 0x2F
	  li        r6, 0
	  li        r7, 0
	  bl        0x3E1C
	  li        r3, 0x126
	  bl        -0x1409B4
	  li        r0, 0x2
	  stw       r0, 0x4(r29)
	  stfs      f29, 0x8(r29)
	  b         .loc_0x1D0

	.loc_0x15C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  stfs      f0, 0x8(r29)
	  ble-      .loc_0x1D0
	  stfs      f29, 0x8(r29)
	  li        r0, 0x3
	  li        r4, 0x1
	  stw       r0, 0x4(r29)
	  lwz       r3, 0x1C(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x1D0

	.loc_0x19C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  stfs      f0, 0x8(r29)
	  ble-      .loc_0x1D0
	  stfs      f29, 0x8(r29)
	  li        r0, 0
	  stw       r0, 0x4(r29)
	  lwz       r0, 0x0(r29)
	  or        r0, r0, r24
	  stw       r0, 0x0(r29)

	.loc_0x1D0:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x5
	  addi      r29, r29, 0x3C
	  blt+      .loc_0x50
	  cmplwi    r26, 0
	  beq-      .loc_0x57C
	  rlwinm.   r0,r27,0,24,31
	  beq-      .loc_0x55C
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x2C0
	  lwz       r3, 0x4(r25)
	  lwz       r24, 0x2C(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x2C0
	  lbz       r0, 0xC(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C0
	  li        r3, 0x112
	  bl        -0x140A88
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x268
	  lwz       r3, 0x14(r6)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x268:
	  stw       r24, 0x4(r25)
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x2B4
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2B4:
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x1
	  stw       r0, 0x134(r25)

	.loc_0x2C0:
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,10,10
	  beq-      .loc_0x390
	  lwz       r3, 0x4(r25)
	  lwz       r24, 0x30(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x390
	  lbz       r0, 0xC(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x390
	  li        r3, 0x112
	  bl        -0x140B58
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x338
	  lwz       r3, 0x14(r6)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x338:
	  stw       r24, 0x4(r25)
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x384
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x384:
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x1
	  stw       r0, 0x134(r25)

	.loc_0x390:
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0x460
	  lwz       r3, 0x4(r25)
	  lwz       r24, 0x34(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x460
	  lbz       r0, 0xC(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  li        r3, 0x112
	  bl        -0x140C28
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x408
	  lwz       r3, 0x14(r6)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x408:
	  stw       r24, 0x4(r25)
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x454
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x454:
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x1
	  stw       r0, 0x134(r25)

	.loc_0x460:
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,11,11
	  beq-      .loc_0x530
	  lwz       r3, 0x4(r25)
	  lwz       r24, 0x38(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x530
	  lbz       r0, 0xC(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x530
	  li        r3, 0x112
	  bl        -0x140CF8
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x4D8
	  lwz       r3, 0x14(r6)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x4D8:
	  stw       r24, 0x4(r25)
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x524
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x524:
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x1
	  stw       r0, 0x134(r25)

	.loc_0x530:
	  lis       r3, 0x100
	  lwz       r4, 0x28(r26)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x57C
	  li        r3, 0x111
	  bl        -0x140DB4
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x10
	  stw       r0, 0x134(r25)
	  b         .loc_0x57C

	.loc_0x55C:
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x57C
	  li        r3, 0x11D
	  bl        -0x140DD8
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x20
	  stw       r0, 0x134(r25)

	.loc_0x57C:
	  lmw       r24, 0x138(r1)
	  li        r3, 0
	  lwz       r0, 0x17C(r1)
	  lfd       f31, 0x170(r1)
	  lfd       f30, 0x168(r1)
	  lfd       f29, 0x160(r1)
	  lfd       f28, 0x158(r1)
	  addi      r1, r1, 0x178
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E6184
 * Size:	000868
 */
bool zen::DrawWorldMap::modeOperation(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x208(r1)
	  stfd      f31, 0x200(r1)
	  stfd      f30, 0x1F8(r1)
	  stfd      f29, 0x1F0(r1)
	  stmw      r20, 0x1C0(r1)
	  mr        r31, r3
	  addi      r26, r4, 0
	  li        r25, 0
	  lwz       r23, 0x364(r3)
	  bl        0x31EC0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4168(r2)
	  stw       r0, 0x1BC(r1)
	  lis       r22, 0x4330
	  lfs       f2, -0x4160(r2)
	  stw       r22, 0x1B8(r1)
	  lfs       f1, -0x4178(r2)
	  lfd       f3, 0x1B8(r1)
	  lfs       f0, 0x0(r23)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x11C
	  bl        0x31E84
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4168(r2)
	  stw       r0, 0x1BC(r1)
	  lfs       f1, -0x4160(r2)
	  stw       r22, 0x1B8(r1)
	  lfs       f0, -0x40B8(r2)
	  lfd       f2, 0x1B8(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f29, f0, f1
	  bl        0x31E58
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4168(r2)
	  stw       r0, 0x1B4(r1)
	  lfs       f1, -0x4160(r2)
	  stw       r22, 0x1B0(r1)
	  lfs       f0, -0x4174(r2)
	  lfd       f2, 0x1B0(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f30, f0, f1
	  bl        0x31E2C
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x40B0(r2)
	  stw       r0, 0x1AC(r1)
	  addi      r5, r1, 0x170
	  fsubs     f1, f0, f30
	  lfd       f5, -0x4168(r2)
	  stw       r22, 0x1A8(r1)
	  lfs       f3, -0x4160(r2)
	  fneg      f0, f29
	  lfd       f4, 0x1A8(r1)
	  li        r4, 0x33
	  lfs       f2, -0x40B4(r2)
	  li        r6, 0
	  fsubs     f4, f4, f5
	  lwz       r3, 0x31C0(r13)
	  li        r7, 0
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  stfs      f2, 0x170(r1)
	  stfs      f1, 0x174(r1)
	  stfs      f0, 0x178(r1)
	  bl        0x38A0

	.loc_0x11C:
	  lbz       r0, 0x4(r23)
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  lfs       f1, 0x0(r23)
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x14C
	  li        r0, 0
	  stb       r0, 0x4(r23)
	  lfs       f0, -0x4170(r2)
	  stfs      f0, 0x0(r23)
	  b         .loc_0x158

	.loc_0x14C:
	  lfs       f0, -0x4144(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r23)

	.loc_0x158:
	  lwz       r3, 0x34(r31)
	  li        r5, 0
	  lbz       r0, 0x35(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x17C
	  lbz       r0, 0x34(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x17C
	  li        r5, 0x1

	.loc_0x17C:
	  lwz       r23, 0x38(r31)
	  li        r22, 0
	  stw       r22, 0x134(r23)
	  lwz       r0, 0x0(r23)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1B4
	  bge-      .loc_0x1D4
	  cmpwi     r0, 0
	  bge-      .loc_0x1A4
	  b         .loc_0x1D4

	.loc_0x1A4:
	  addi      r3, r23, 0
	  addi      r4, r26, 0
	  bl        -0x750
	  b         .loc_0x1D4

	.loc_0x1B4:
	  mr        r3, r23
	  bl        -0x970
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x1D4
	  stw       r22, 0x0(r23)
	  li        r0, 0x40
	  stw       r0, 0x134(r23)

	.loc_0x1D4:
	  lwz       r3, 0x38(r31)
	  lwz       r30, 0x134(r3)
	  rlwinm.   r0,r30,0,31,31
	  beq-      .loc_0x2B0
	  lwz       r26, 0x34(r31)
	  li        r4, 0
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x35(r26)
	  lwz       r3, 0x24(r3)
	  cmplwi    r0, 0
	  lha       r20, 0x18(r3)
	  lha       r21, 0x1A(r3)
	  bne-      .loc_0x2A8
	  lbz       r3, 0x34(r26)
	  cmplwi    r3, 0
	  bne-      .loc_0x218
	  li        r4, 0x1

	.loc_0x218:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x2A8
	  cmplwi    r3, 0
	  bne-      .loc_0x23C
	  lbz       r0, 0x35(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x23C
	  li        r3, 0x123
	  bl        -0x141048

	.loc_0x23C:
	  li        r0, 0x1
	  stw       r0, 0x4(r26)
	  lwz       r0, 0x4(r26)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x268
	  bge-      .loc_0x268
	  cmpwi     r0, 0
	  bge-      .loc_0x260
	  b         .loc_0x268

	.loc_0x260:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r26)

	.loc_0x268:
	  xoris     r0, r20, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x1AC(r1)
	  xoris     r0, r21, 0x8000
	  lis       r3, 0x4330
	  stw       r3, 0x1A8(r1)
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1A8(r1)
	  stw       r3, 0x1B0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1B0(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r26)
	  stfs      f0, 0x10(r26)
	  lfs       f0, 0x2564(r13)
	  stfs      f0, 0x14(r26)

	.loc_0x2A8:
	  mr        r3, r31
	  bl        0xFC8

	.loc_0x2B0:
	  rlwinm.   r0,r30,0,27,27
	  beq-      .loc_0x2CC
	  lwz       r3, 0x70(r31)
	  li        r4, 0x1
	  bl        -0x8E8C
	  li        r0, 0x4
	  stw       r0, 0x4(r31)

	.loc_0x2CC:
	  rlwinm.   r0,r30,0,26,26
	  beq-      .loc_0x38C
	  lwz       r3, 0x38(r31)
	  lwz       r22, 0x34(r31)
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x35(r22)
	  lwz       r3, 0x24(r3)
	  cmplwi    r0, 0
	  lha       r20, 0x18(r3)
	  lha       r21, 0x1A(r3)
	  bne-      .loc_0x304
	  lbz       r0, 0x34(r22)
	  cmplwi    r0, 0
	  beq-      .loc_0x38C

	.loc_0x304:
	  li        r0, 0
	  stb       r0, 0x35(r22)
	  addi      r3, r22, 0
	  li        r4, 0
	  bl        -0x86B0
	  li        r0, 0x1
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x4(r22)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x344
	  bge-      .loc_0x344
	  cmpwi     r0, 0
	  bge-      .loc_0x33C
	  b         .loc_0x344

	.loc_0x33C:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r22)

	.loc_0x344:
	  xoris     r0, r20, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x1AC(r1)
	  xoris     r0, r21, 0x8000
	  lis       r4, 0x4330
	  stw       r4, 0x1A8(r1)
	  li        r3, 0x11D
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1A8(r1)
	  stw       r4, 0x1B0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1B0(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r22)
	  stfs      f0, 0x10(r22)
	  lfs       f0, 0x2568(r13)
	  stfs      f0, 0x14(r22)
	  bl        -0x141198

	.loc_0x38C:
	  lwz       r3, 0x34(r31)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x740
	  lwz       r3, 0x38(r31)
	  li        r0, -0x1
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x3B4
	  lwz       r0, 0x10(r3)

	.loc_0x3B4:
	  stw       r0, 0x8(r31)
	  li        r4, 0
	  lwz       r3, 0x50(r31)
	  bl        0x3790
	  lwz       r3, 0x38(r31)
	  lfs       f0, -0x4188(r2)
	  lwz       r3, 0x4(r3)
	  lwz       r21, 0x14(r3)
	  stfs      f0, 0x100(r1)
	  addi      r3, r21, 0x18
	  stfs      f0, 0xFC(r1)
	  stfs      f0, 0xF8(r1)
	  bl        -0x2E034
	  lha       r20, 0x1A(r21)
	  addi      r22, r3, 0
	  addi      r3, r21, 0x18
	  bl        -0x2E054
	  lha       r4, 0x18(r21)
	  srawi     r3, r3, 0x1
	  srawi     r0, r22, 0x1
	  lfd       f2, -0x4168(r2)
	  add       r3, r4, r3
	  xoris     r3, r3, 0x8000
	  add       r0, r20, r0
	  stw       r3, 0x1AC(r1)
	  subfic    r0, r0, 0x1E0
	  xoris     r0, r0, 0x8000
	  lis       r22, 0x4330
	  stw       r0, 0x1B4(r1)
	  addi      r5, r1, 0xF8
	  stw       r22, 0x1A8(r1)
	  li        r4, 0x2D
	  li        r6, 0
	  stw       r22, 0x1B0(r1)
	  li        r7, 0
	  lfd       f1, 0x1A8(r1)
	  lfd       f0, 0x1B0(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  stfs      f1, 0xF8(r1)
	  stfs      f0, 0xFC(r1)
	  lfs       f0, 0x2600(r13)
	  stfs      f0, 0x100(r1)
	  lwz       r3, 0x31C0(r13)
	  bl        0x3554
	  lwz       r25, 0x58(r31)
	  addi      r30, r1, 0xD8
	  lfs       f29, -0x4188(r2)
	  addi      r29, r1, 0xD4
	  lfs       f30, -0x4154(r2)
	  lfd       f31, -0x4168(r2)
	  addi      r26, r25, 0
	  addi      r28, r1, 0xE0
	  addi      r27, r1, 0xDC
	  li        r21, 0

	.loc_0x490:
	  lfs       f0, 0x10(r26)
	  addi      r20, r26, 0xC
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4AC
	  fadds     f0, f30, f0
	  b         .loc_0x4B0

	.loc_0x4AC:
	  fsubs     f0, f0, f30

	.loc_0x4B0:
	  lfs       f1, 0x0(r20)
	  fctiwz    f0, f0
	  fcmpo     cr0, f1, f29
	  stfd      f0, 0x1A8(r1)
	  lwz       r23, 0x1AC(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4D4
	  fadds     f0, f30, f1
	  b         .loc_0x4D8

	.loc_0x4D4:
	  fsubs     f0, f1, f30

	.loc_0x4D8:
	  fctiwz    f0, f0
	  lwz       r3, 0x24(r20)
	  addi      r3, r3, 0x18
	  stfd      f0, 0x1A8(r1)
	  lwz       r24, 0x1AC(r1)
	  bl        -0x2E14C
	  lwz       r4, 0x24(r20)
	  srawi     r0, r3, 0x1
	  sub       r24, r24, r0
	  addi      r3, r4, 0x18
	  bl        -0x2E150
	  srawi     r0, r3, 0x1
	  lwz       r3, 0x24(r20)
	  sub       r23, r23, r0
	  lwz       r12, 0x0(r3)
	  addi      r4, r24, 0
	  addi      r5, r23, 0
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  xoris     r23, r23, 0x8000
	  xoris     r24, r24, 0x8000
	  stw       r23, 0x1B4(r1)
	  mr        r4, r29
	  stw       r24, 0x1BC(r1)
	  addi      r5, r30, 0
	  addi      r3, r20, 0xC
	  stw       r22, 0x1B0(r1)
	  addi      r6, r13, 0x25EC
	  stw       r22, 0x1B8(r1)
	  lfd       f1, 0x1B0(r1)
	  lfd       f0, 0x1B8(r1)
	  fsubs     f1, f1, f31
	  fsubs     f0, f0, f31
	  stfs      f1, 0xD8(r1)
	  stfs      f0, 0xD4(r1)
	  bl        -0x189060
	  stw       r23, 0x1A4(r1)
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  stw       r24, 0x19C(r1)
	  addi      r3, r20, 0x18
	  addi      r6, r13, 0x25F0
	  stw       r22, 0x1A0(r1)
	  stw       r22, 0x198(r1)
	  lfd       f1, 0x1A0(r1)
	  lfd       f0, 0x198(r1)
	  fsubs     f1, f1, f31
	  fsubs     f0, f0, f31
	  stfs      f1, 0xE0(r1)
	  stfs      f0, 0xDC(r1)
	  bl        -0x18909C
	  addi      r21, r21, 0x1
	  cmpwi     r21, 0x4
	  addi      r26, r26, 0x28
	  blt+      .loc_0x490
	  li        r0, 0
	  stw       r0, 0x0(r25)
	  li        r0, 0x2
	  mtctr     r0
	  lis       r3, 0x4330
	  lwz       r7, 0x58(r31)
	  lfs       f0, -0x4188(r2)
	  mr        r9, r7
	  stfs      f0, 0x4(r7)
	  lfs       f0, -0x4154(r2)
	  stfs      f0, 0x8(r7)
	  lfd       f3, -0x4168(r2)

	.loc_0x5E8:
	  lwz       r5, 0x30(r9)
	  lha       r0, 0x18(r5)
	  lha       r10, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  lha       r4, 0x1E(r5)
	  stw       r0, 0x19C(r1)
	  xoris     r0, r10, 0x8000
	  lha       r6, 0x18(r5)
	  sub       r4, r4, r10
	  stw       r3, 0x198(r1)
	  lha       r5, 0x1C(r5)
	  stw       r0, 0x1A4(r1)
	  sub       r0, r5, r6
	  lfd       f0, 0x198(r1)
	  srawi     r0, r0, 0x1
	  stw       r3, 0x1A0(r1)
	  subfic    r0, r0, 0x140
	  fsubs     f2, f0, f3
	  lfd       f0, 0x1A0(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1AC(r1)
	  srawi     r4, r4, 0x1
	  subfic    r0, r4, 0xF0
	  fsubs     f1, f0, f3
	  xoris     r0, r0, 0x8000
	  stfs      f2, 0x18(r9)
	  stw       r3, 0x1A8(r1)
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1A8(r1)
	  stfs      f1, 0x1C(r9)
	  fsubs     f1, f0, f3
	  stw       r3, 0x1B0(r1)
	  lfs       f2, 0x25F4(r13)
	  lfd       f0, 0x1B0(r1)
	  stfs      f2, 0x20(r9)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x24(r9)
	  stfs      f0, 0x28(r9)
	  lfs       f0, 0x25F8(r13)
	  stfs      f0, 0x2C(r9)
	  lwz       r5, 0x58(r9)
	  lha       r0, 0x18(r5)
	  lha       r10, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  lha       r4, 0x1E(r5)
	  stw       r0, 0x19C(r1)
	  xoris     r0, r10, 0x8000
	  lha       r6, 0x18(r5)
	  sub       r4, r4, r10
	  stw       r3, 0x198(r1)
	  lha       r5, 0x1C(r5)
	  stw       r0, 0x1A4(r1)
	  sub       r0, r5, r6
	  lfd       f0, 0x198(r1)
	  srawi     r0, r0, 0x1
	  stw       r3, 0x1A0(r1)
	  subfic    r0, r0, 0x140
	  fsubs     f2, f0, f3
	  lfd       f0, 0x1A0(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1AC(r1)
	  srawi     r4, r4, 0x1
	  subfic    r0, r4, 0xF0
	  fsubs     f1, f0, f3
	  xoris     r0, r0, 0x8000
	  stfs      f2, 0x40(r9)
	  stw       r3, 0x1A8(r1)
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1A8(r1)
	  stfs      f1, 0x44(r9)
	  fsubs     f1, f0, f3
	  stw       r3, 0x1B0(r1)
	  lfs       f2, 0x25F4(r13)
	  lfd       f0, 0x1B0(r1)
	  stfs      f2, 0x48(r9)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x4C(r9)
	  stfs      f0, 0x50(r9)
	  lfs       f0, 0x25F8(r13)
	  stfs      f0, 0x54(r9)
	  addi      r9, r9, 0x50
	  bdnz+     .loc_0x5E8
	  li        r0, 0x1
	  stw       r0, 0x0(r7)
	  li        r25, 0x1
	  stb       r0, 0xAC(r7)

	.loc_0x740:
	  lwz       r22, 0x34(r31)
	  lwz       r0, 0x4(r22)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x770
	  bge-      .loc_0x800
	  cmpwi     r0, 0
	  bge-      .loc_0x764
	  b         .loc_0x800
	  b         .loc_0x800

	.loc_0x764:
	  mr        r3, r22
	  bl        -0x5F68
	  b         .loc_0x800

	.loc_0x770:
	  mr        r3, r22
	  bl        -0x6408
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x800
	  lbz       r0, 0x35(r22)
	  cmplwi    r0, 0
	  beq-      .loc_0x798
	  mr        r3, r22
	  bl        -0x64F4
	  b         .loc_0x800

	.loc_0x798:
	  lbz       r0, 0x34(r22)
	  cmplwi    r0, 0
	  beq-      .loc_0x7D4
	  li        r0, 0x2
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x4(r22)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x800
	  bge-      .loc_0x800
	  cmpwi     r0, 0
	  bge-      .loc_0x7C8
	  b         .loc_0x800

	.loc_0x7C8:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r22)
	  b         .loc_0x800

	.loc_0x7D4:
	  li        r0, 0
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x4(r22)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x800
	  bge-      .loc_0x800
	  cmpwi     r0, 0
	  bge-      .loc_0x7F8
	  b         .loc_0x800

	.loc_0x7F8:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r22)

	.loc_0x800:
	  mr        r3, r22
	  bl        -0x68B8
	  li        r20, 0
	  mulli     r0, r20, 0x3C
	  add       r21, r22, r0

	.loc_0x814:
	  lwz       r4, 0x8(r22)
	  addi      r3, r21, 0x44
	  addi      r4, r4, 0xC0
	  bl        -0x6EFC
	  addi      r20, r20, 0x1
	  cmpwi     r20, 0x3
	  addi      r21, r21, 0x3C
	  blt+      .loc_0x814
	  mr        r3, r22
	  bl        -0x726C
	  mr        r3, r31
	  bl        0x958
	  mr        r3, r25
	  lmw       r20, 0x1C0(r1)
	  lwz       r0, 0x20C(r1)
	  lfd       f31, 0x200(r1)
	  lfd       f30, 0x1F8(r1)
	  lfd       f29, 0x1F0(r1)
	  addi      r1, r1, 0x208
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E69EC
 * Size:	000614
 */
bool zen::DrawWorldMap::modeConfirm(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x128(r1)
	  stfd      f31, 0x120(r1)
	  stmw      r26, 0x108(r1)
	  mr        r31, r3
	  lwz       r28, 0x70(r3)
	  lwz       r0, 0x74(r28)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x184
	  bge-      .loc_0x38
	  cmpwi     r0, 0x1
	  bge-      .loc_0x44
	  b         .loc_0x360

	.loc_0x38:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x360
	  b         .loc_0x1A8

	.loc_0x44:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x70(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r28)
	  lfs       f1, 0x70(r28)
	  lfs       f0, -0x4144(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x80
	  lfs       f0, -0x4188(r2)
	  li        r0, 0x2
	  stfs      f0, 0x70(r28)
	  lfs       f1, -0x4184(r2)
	  stw       r0, 0x74(r28)
	  b         .loc_0x90

	.loc_0x80:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x4148(r2)
	  fmuls     f1, f1, f0
	  bl        0x35270

	.loc_0x90:
	  lfs       f0, -0x4148(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f31
	  bl        0x350CC
	  lfs       f0, -0x4178(r2)
	  fmuls     f0, f0, f1
	  fmr       f1, f31
	  stfs      f0, 0x7C(r28)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x80(r28)
	  bl        0x35244
	  lfs       f2, -0x4178(r2)
	  fmuls     f0, f2, f1
	  fsubs     f0, f0, f2
	  stfs      f0, 0x84(r28)
	  lfs       f1, 0x80(r28)
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xEC
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xF4

	.loc_0xEC:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0xF4:
	  lfs       f2, 0x7C(r28)
	  fctiwz    f1, f0
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0x100(r1)
	  lwz       r5, 0x104(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x120
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x128

	.loc_0x120:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f2, f0

	.loc_0x128:
	  fctiwz    f0, f0
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  stfd      f0, 0x100(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x104(r1)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  lfs       f1, 0x84(r28)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x4148(r2)
	  li        r4, 0x1
	  lwz       r3, 0x0(r28)
	  fsubs     f0, f31, f0
	  lfs       f1, -0x4108(r2)
	  addi      r3, r3, 0x4
	  fsubs     f1, f1, f0
	  bl        -0x6035C
	  b         .loc_0x360

	.loc_0x184:
	  mr        r3, r28
	  bl        .loc_0x614
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x360
	  li        r0, 0x3
	  stw       r0, 0x74(r28)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x70(r28)
	  b         .loc_0x360

	.loc_0x1A8:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x70(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r28)
	  lfs       f1, 0x70(r28)
	  lfs       f0, -0x4144(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1F4
	  lfs       f0, -0x4188(r2)
	  li        r4, 0
	  stfs      f0, 0x70(r28)
	  lfs       f2, -0x4184(r2)
	  stw       r4, 0x74(r28)
	  lwz       r3, 0x0(r28)
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x10(r3)
	  b         .loc_0x20C

	.loc_0x1F4:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x4148(r2)
	  fmuls     f1, f1, f0
	  bl        0x34F68
	  lfs       f0, -0x4184(r2)
	  fsubs     f2, f0, f1

	.loc_0x20C:
	  lwz       r0, 0x78(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x26C
	  lfs       f1, -0x40AC(r2)
	  lfs       f0, -0x4188(r2)
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x23C
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x244

	.loc_0x23C:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x244:
	  fctiwz    f0, f0
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  li        r4, 0
	  stfd      f0, 0x100(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r5, 0x104(r1)
	  mtlr      r12
	  blrl
	  b         .loc_0x360

	.loc_0x26C:
	  lfs       f1, -0x4148(r2)
	  fmuls     f0, f1, f2
	  fadds     f31, f1, f0
	  fmr       f1, f31
	  bl        0x34EEC
	  lfs       f0, -0x4178(r2)
	  fmuls     f0, f0, f1
	  fmr       f1, f31
	  stfs      f0, 0x7C(r28)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x80(r28)
	  bl        0x35064
	  lfs       f2, -0x4178(r2)
	  fmuls     f0, f2, f1
	  fsubs     f0, f0, f2
	  stfs      f0, 0x84(r28)
	  lfs       f1, 0x80(r28)
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2CC
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x2D4

	.loc_0x2CC:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x2D4:
	  lfs       f2, 0x7C(r28)
	  fctiwz    f1, f0
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0x100(r1)
	  lwz       r5, 0x104(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x300
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x308

	.loc_0x300:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f2, f0

	.loc_0x308:
	  fctiwz    f0, f0
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  stfd      f0, 0x100(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x104(r1)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  lfs       f1, 0x84(r28)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x4148(r2)
	  li        r4, 0x1
	  lwz       r3, 0x0(r28)
	  fsubs     f0, f31, f0
	  lfs       f1, -0x4108(r2)
	  addi      r3, r3, 0x4
	  fsubs     f1, f1, f0
	  bl        -0x6053C

	.loc_0x360:
	  lwz       r3, 0x0(r28)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r28, 0x4
	  bl        -0xC550
	  addi      r3, r28, 0x34
	  bl        -0xC558
	  lwz       r3, 0x74(r28)
	  neg       r0, r3
	  cntlzw    r0, r0
	  cmpwi     r3, 0
	  rlwinm    r30,r0,27,5,31
	  bne-      .loc_0x4F4
	  lwz       r3, 0x70(r31)
	  lwz       r0, 0x78(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x4F4
	  lwz       r3, 0x38(r31)
	  li        r26, 0
	  lwz       r27, 0x34(r31)
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x35(r27)
	  lwz       r3, 0x28(r3)
	  cmplwi    r0, 0
	  lha       r29, 0x18(r3)
	  lha       r28, 0x1A(r3)
	  bne-      .loc_0x4F4
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x40C
	  bge-      .loc_0x460
	  cmpwi     r0, 0
	  bge-      .loc_0x3F0
	  b         .loc_0x460

	.loc_0x3F0:
	  lfs       f0, -0x4188(r2)
	  addi      r3, r27, 0
	  li        r26, 0x1
	  stfs      f0, 0x0(r27)
	  li        r4, 0x1
	  bl        -0x9008
	  b         .loc_0x460

	.loc_0x40C:
	  lbz       r0, 0x34(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x460
	  xoris     r0, r29, 0x8000
	  stw       r0, 0x104(r1)
	  xoris     r0, r28, 0x8000
	  li        r4, 0x1
	  lis       r3, 0x4330
	  stb       r4, 0x35(r27)
	  stw       r3, 0x100(r1)
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0xFC(r1)
	  lfd       f0, 0x100(r1)
	  stw       r3, 0xF8(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0xF8(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x38(r27)
	  stfs      f0, 0x3C(r27)
	  lfs       f0, 0x2560(r13)
	  stfs      f0, 0x40(r27)

	.loc_0x460:
	  rlwinm.   r0,r26,0,24,31
	  beq-      .loc_0x4F4
	  lbz       r0, 0x34(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x488
	  lbz       r0, 0x35(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x488
	  li        r3, 0x123
	  bl        -0x141AFC

	.loc_0x488:
	  li        r0, 0x1
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x4B4
	  bge-      .loc_0x4B4
	  cmpwi     r0, 0
	  bge-      .loc_0x4AC
	  b         .loc_0x4B4

	.loc_0x4AC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)

	.loc_0x4B4:
	  xoris     r0, r29, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0xFC(r1)
	  xoris     r0, r28, 0x8000
	  lis       r3, 0x4330
	  stw       r3, 0xF8(r1)
	  stw       r0, 0x104(r1)
	  lfd       f0, 0xF8(r1)
	  stw       r3, 0x100(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x100(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r27)
	  stfs      f0, 0x10(r27)
	  lfs       f0, 0x2564(r13)
	  stfs      f0, 0x14(r27)

	.loc_0x4F4:
	  lwz       r28, 0x34(r31)
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x524
	  bge-      .loc_0x5B4
	  cmpwi     r0, 0
	  bge-      .loc_0x518
	  b         .loc_0x5B4
	  b         .loc_0x5B4

	.loc_0x518:
	  mr        r3, r28
	  bl        -0x6584
	  b         .loc_0x5B4

	.loc_0x524:
	  mr        r3, r28
	  bl        -0x6A24
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5B4
	  lbz       r0, 0x35(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x54C
	  mr        r3, r28
	  bl        -0x6B10
	  b         .loc_0x5B4

	.loc_0x54C:
	  lbz       r0, 0x34(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x588
	  li        r0, 0x2
	  stw       r0, 0x4(r28)
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5B4
	  bge-      .loc_0x5B4
	  cmpwi     r0, 0
	  bge-      .loc_0x57C
	  b         .loc_0x5B4

	.loc_0x57C:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r28)
	  b         .loc_0x5B4

	.loc_0x588:
	  li        r0, 0
	  stw       r0, 0x4(r28)
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5B4
	  bge-      .loc_0x5B4
	  cmpwi     r0, 0
	  bge-      .loc_0x5AC
	  b         .loc_0x5B4

	.loc_0x5AC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r28)

	.loc_0x5B4:
	  mr        r3, r28
	  bl        -0x6ED4
	  li        r26, 0
	  mulli     r0, r26, 0x3C
	  add       r27, r28, r0

	.loc_0x5C8:
	  lwz       r4, 0x8(r28)
	  addi      r3, r27, 0x44
	  addi      r4, r4, 0xC0
	  bl        -0x7518
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  addi      r27, r27, 0x3C
	  blt+      .loc_0x5C8
	  mr        r3, r28
	  bl        -0x7888
	  mr        r3, r31
	  bl        0x33C
	  mr        r3, r30
	  lmw       r26, 0x108(r1)
	  lwz       r0, 0x12C(r1)
	  lfd       f31, 0x120(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr

	.loc_0x614:
	*/
}

/*
 * --INFO--
 * Address:	801E7000
 * Size:	0001C8
 */
bool zen::WorldMapConfirmMgr::modeOperation(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stmw      r25, 0x64(r1)
	  mr        r28, r4
	  mr        r27, r3
	  li        r30, 0
	  lwz       r5, 0x28(r4)
	  lwz       r29, 0x78(r3)
	  rlwinm    r0,r5,0,12,12
	  neg       r4, r0
	  subic     r3, r4, 0x1
	  rlwinm    r0,r5,0,10,10
	  subfe     r4, r3, r4
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r3,r4,0,24,31
	  rlwinm    r0,r0,0,24,31
	  sub       r0, r0, r3
	  add       r0, r29, r0
	  stw       r0, 0x78(r27)
	  lwz       r0, 0x78(r27)
	  cmpwi     r0, 0
	  bge-      .loc_0x6C
	  li        r0, 0x1
	  stw       r0, 0x78(r27)

	.loc_0x6C:
	  lwz       r0, 0x78(r27)
	  cmpwi     r0, 0x1
	  ble-      .loc_0x80
	  li        r0, 0
	  stw       r0, 0x78(r27)

	.loc_0x80:
	  lwz       r0, 0x78(r27)
	  li        r25, 0
	  lwz       r3, 0x64(r27)
	  li        r26, 0
	  mulli     r0, r0, 0xC
	  add       r31, r3, r0

	.loc_0x98:
	  lwz       r3, 0x78(r27)
	  addi      r5, r27, 0x68
	  lwz       r0, 0x64(r27)
	  addi      r6, r27, 0x6C
	  sub       r3, r3, r25
	  cntlzw    r3, r3
	  add       r7, r0, r26
	  rlwinm    r4,r3,27,5,31
	  lwz       r3, 0x0(r7)
	  bl        -0x247A0
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x2
	  addi      r26, r26, 0xC
	  blt+      .loc_0x98
	  lwz       r0, 0x78(r27)
	  cmpw      r29, r0
	  beq-      .loc_0x170
	  li        r3, 0x112
	  bl        -0x141D6C
	  lwz       r4, 0x4(r31)
	  lis       r29, 0x4330
	  lfd       f2, -0x4168(r2)
	  addi      r3, r27, 0x4
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  lfs       f3, -0x4154(r2)
	  xoris     r4, r4, 0x8000
	  stw       r0, 0x54(r1)
	  stw       r4, 0x5C(r1)
	  stw       r29, 0x58(r1)
	  stw       r29, 0x50(r1)
	  lfd       f1, 0x58(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        -0xC580
	  lwz       r4, 0x8(r31)
	  addi      r3, r27, 0x34
	  lfd       f2, -0x4168(r2)
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  lfs       f3, -0x4154(r2)
	  xoris     r4, r4, 0x8000
	  stw       r0, 0x44(r1)
	  stw       r4, 0x4C(r1)
	  stw       r29, 0x48(r1)
	  stw       r29, 0x40(r1)
	  lfd       f1, 0x48(r1)
	  lfd       f0, 0x40(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        -0xC5C4

	.loc_0x170:
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x190
	  li        r3, 0x111
	  bl        -0x141E14
	  li        r30, 0x1

	.loc_0x190:
	  lwz       r0, 0x28(r28)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x1B0
	  li        r3, 0x11D
	  bl        -0x141E2C
	  li        r0, 0x1
	  stw       r0, 0x78(r27)
	  li        r30, 0x1

	.loc_0x1B0:
	  mr        r3, r30
	  lmw       r25, 0x64(r1)
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E71C8
 * Size:	000154
 */
bool zen::DrawWorldMap::modeEnd(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  mr        r30, r3
	  li        r31, 0
	  lwz       r3, 0x58(r3)
	  lbz       r0, 0xAC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x38
	  lwz       r3, 0x50(r30)
	  li        r4, 0x1
	  bl        0x2ADC
	  li        r31, 0x1

	.loc_0x38:
	  lwz       r27, 0x34(r30)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x68
	  bge-      .loc_0xF8
	  cmpwi     r0, 0
	  bge-      .loc_0x5C
	  b         .loc_0xF8
	  b         .loc_0xF8

	.loc_0x5C:
	  mr        r3, r27
	  bl        -0x68A4
	  b         .loc_0xF8

	.loc_0x68:
	  mr        r3, r27
	  bl        -0x6D44
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF8
	  lbz       r0, 0x35(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x90
	  mr        r3, r27
	  bl        -0x6E30
	  b         .loc_0xF8

	.loc_0x90:
	  lbz       r0, 0x34(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0xCC
	  li        r0, 0x2
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xF8
	  bge-      .loc_0xF8
	  cmpwi     r0, 0
	  bge-      .loc_0xC0
	  b         .loc_0xF8

	.loc_0xC0:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)
	  b         .loc_0xF8

	.loc_0xCC:
	  li        r0, 0
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xF8
	  bge-      .loc_0xF8
	  cmpwi     r0, 0
	  bge-      .loc_0xF0
	  b         .loc_0xF8

	.loc_0xF0:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)

	.loc_0xF8:
	  mr        r3, r27
	  bl        -0x71F4
	  li        r29, 0
	  mulli     r0, r29, 0x3C
	  add       r28, r27, r0

	.loc_0x10C:
	  lwz       r4, 0x8(r27)
	  addi      r3, r28, 0x44
	  addi      r4, r4, 0xC0
	  bl        -0x7838
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r28, r28, 0x3C
	  blt+      .loc_0x10C
	  mr        r3, r27
	  bl        -0x7BA8
	  mr        r3, r30
	  bl        .loc_0x154
	  mr        r3, r31
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0x154:
	*/
}

/*
 * --INFO--
 * Address:	801E731C
 * Size:	0000DC
 */
void zen::DrawWorldMap::updateScreens()
{
	mWipeScreen->update();
	mMoniScreen->update();
	mIconScreen->update();
	mTitleScreen->update();
	mData1Screen->update();
	mData2Screen->update();
	mPointScreen->update();
	mLineScreen->update();
	mBackScreen->update();
}

/*
 * --INFO--
 * Address:	801E73F8
 * Size:	000124
 */
void zen::DrawWorldMap::closeMapInfo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  lwz       r4, 0x54(r3)
	  lwz       r0, 0x4(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x54
	  bge-      .loc_0x2C
	  cmpwi     r0, 0
	  bge-      .loc_0x38
	  b         .loc_0x54

	.loc_0x2C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x54
	  b         .loc_0x4C

	.loc_0x38:
	  lfs       f0, -0x4188(r2)
	  li        r0, 0x1
	  stfs      f0, 0x0(r4)
	  stw       r0, 0x4(r4)
	  b         .loc_0x54

	.loc_0x4C:
	  li        r0, 0x1
	  stb       r0, 0x20(r4)

	.loc_0x54:
	  lwz       r10, 0x5C(r3)
	  lwz       r0, 0x4(r10)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x108
	  mulli     r0, r0, 0x28
	  lwz       r4, 0x0(r10)
	  lfd       f2, -0x4168(r2)
	  add       r8, r4, r0
	  lwz       r9, 0x4(r8)
	  lis       r7, 0x4330
	  li        r4, 0x2
	  lha       r5, 0x18(r9)
	  li        r6, 0x1
	  lha       r9, 0x1A(r9)
	  li        r0, -0x1
	  xoris     r5, r5, 0x8000
	  stw       r5, 0x3C(r1)
	  xoris     r5, r9, 0x8000
	  stw       r7, 0x38(r1)
	  stw       r5, 0x34(r1)
	  lfd       f0, 0x38(r1)
	  stw       r7, 0x30(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x30(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x10(r8)
	  stfs      f0, 0x14(r8)
	  lfs       f0, 0x2480(r13)
	  stfs      f0, 0x18(r8)
	  lfs       f2, 0x14(r8)
	  lfs       f1, -0x40A8(r2)
	  lfs       f0, 0x10(r8)
	  fsubs     f1, f2, f1
	  stfs      f0, 0x1C(r8)
	  stfs      f1, 0x20(r8)
	  lfs       f0, 0x18(r8)
	  stfs      f0, 0x24(r8)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x8(r8)
	  stw       r4, 0x0(r8)
	  lwz       r5, 0x4(r8)
	  lbz       r4, 0xC(r5)
	  rlwimi    r4,r6,7,24,24
	  stb       r4, 0xC(r5)
	  stw       r0, 0x4(r10)

	.loc_0x108:
	  lwz       r3, 0x60(r3)
	  li        r4, -0x1
	  bl        .loc_0x124
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0x124:
	*/
}

/*
 * --INFO--
 * Address:	801E7728
 * Size:	000220
 */
void zen::DrawWorldMap::openMapInfo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  lwz       r4, 0x38(r3)
	  lwz       r4, 0x4(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x2C
	  lwz       r6, 0x10(r4)

	.loc_0x2C:
	  lwz       r4, 0x54(r3)
	  lwz       r0, 0x4(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x50
	  lfs       f0, -0x4188(r2)
	  li        r0, 0x2
	  stfs      f0, 0x0(r4)
	  stw       r6, 0x8(r4)
	  stw       r0, 0x4(r4)

	.loc_0x50:
	  lwz       r7, 0x5C(r3)
	  addi      r4, r13, 0x2470
	  lbzx      r4, r4, r6
	  lwz       r0, 0x4(r7)
	  cmpw      r0, r4
	  beq-      .loc_0xCC
	  stw       r4, 0x4(r7)
	  li        r5, 0x1
	  lwz       r0, 0x4(r7)
	  lwz       r4, 0x0(r7)
	  mulli     r0, r0, 0x28
	  lfs       f0, 0x2484(r13)
	  add       r4, r4, r0
	  stfs      f0, 0x10(r4)
	  lfs       f0, 0x2488(r13)
	  stfs      f0, 0x14(r4)
	  lfs       f0, 0x248C(r13)
	  stfs      f0, 0x18(r4)
	  lfs       f0, 0x2490(r13)
	  stfs      f0, 0x1C(r4)
	  lfs       f0, 0x2494(r13)
	  stfs      f0, 0x20(r4)
	  lfs       f0, 0x2498(r13)
	  stfs      f0, 0x24(r4)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x8(r4)
	  stw       r5, 0x0(r4)
	  lwz       r4, 0x4(r4)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)

	.loc_0xCC:
	  cmpwi     r6, -0x1
	  lwz       r30, 0x60(r3)
	  bne-      .loc_0xE4
	  li        r5, 0
	  li        r31, 0
	  b         .loc_0x1FC

	.loc_0xE4:
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x18C
	  cmpwi     r6, 0x2
	  beq-      .loc_0x144
	  bge-      .loc_0x10C
	  cmpwi     r6, 0
	  beq-      .loc_0x11C
	  bge-      .loc_0x130
	  b         .loc_0x180

	.loc_0x10C:
	  cmpwi     r6, 0x4
	  beq-      .loc_0x16C
	  bge-      .loc_0x180
	  b         .loc_0x158

	.loc_0x11C:
	  li        r31, 0x2
	  li        r4, 0
	  bl        -0x167C38
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x130:
	  li        r31, 0x8
	  li        r4, 0x1
	  bl        -0x167C4C
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x144:
	  li        r31, 0x9
	  li        r4, 0x2
	  bl        -0x167C60
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x158:
	  li        r31, 0xA
	  li        r4, 0x3
	  bl        -0x167C74
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x16C:
	  li        r31, 0x1
	  li        r4, 0x4
	  bl        -0x167C88
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x180:
	  li        r31, 0
	  addi      r5, r31, 0
	  b         .loc_0x1FC

	.loc_0x18C:
	  cmpwi     r6, 0x2
	  beq-      .loc_0x1D0
	  bge-      .loc_0x1A8
	  cmpwi     r6, 0
	  beq-      .loc_0x1B8
	  bge-      .loc_0x1C4
	  b         .loc_0x1F4

	.loc_0x1A8:
	  cmpwi     r6, 0x4
	  beq-      .loc_0x1E8
	  bge-      .loc_0x1F4
	  b         .loc_0x1DC

	.loc_0x1B8:
	  li        r31, 0x2
	  li        r5, 0x1
	  b         .loc_0x1FC

	.loc_0x1C4:
	  li        r31, 0x8
	  li        r5, 0x2
	  b         .loc_0x1FC

	.loc_0x1D0:
	  li        r31, 0x9
	  li        r5, 0x3
	  b         .loc_0x1FC

	.loc_0x1DC:
	  li        r31, 0xA
	  li        r5, 0x4
	  b         .loc_0x1FC

	.loc_0x1E8:
	  li        r31, 0x1
	  li        r5, 0
	  b         .loc_0x1FC

	.loc_0x1F4:
	  li        r31, 0
	  addi      r5, r31, 0

	.loc_0x1FC:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x4F48
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E7948
 * Size:	000168
 */
bool DrawWorldMapDateCallBack::invoke(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x166DB0
	  addi      r0, r3, 0x1
	  cmpwi     r0, 0x9
	  ble-      .loc_0xF0
	  lwz       r5, 0x4(r31)
	  lis       r3, 0x6666
	  addi      r3, r3, 0x6667
	  lbz       r4, 0xC(r5)
	  li        r6, 0
	  rlwimi    r4,r6,7,24,24
	  stb       r4, 0xC(r5)
	  mulhw     r3, r3, r0
	  lwz       r5, 0x8(r31)
	  lbz       r4, 0xC(r5)
	  li        r6, 0x1
	  rlwimi    r4,r6,7,24,24
	  stb       r4, 0xC(r5)
	  srawi     r3, r3, 0x2
	  rlwinm    r4,r3,1,31,31
	  lwz       r6, 0x8(r31)
	  add       r5, r3, r4
	  lis       r4, 0x803D
	  lbz       r3, 0xF1(r6)
	  rlwinm    r5,r5,2,0,29
	  addi      r4, r4, 0x2360
	  add       r4, r4, r5
	  cmplwi    r3, 0
	  lwz       r3, 0x0(r4)
	  ble-      .loc_0x90
	  stw       r3, 0xEC(r6)

	.loc_0x90:
	  lis       r3, 0x6666
	  lwz       r6, 0xC(r31)
	  addi      r3, r3, 0x6667
	  mulhw     r3, r3, r0
	  lbz       r5, 0xC(r6)
	  srawi     r3, r3, 0x2
	  li        r4, 0x1
	  rlwimi    r5,r4,7,24,24
	  rlwinm    r4,r3,1,31,31
	  stb       r5, 0xC(r6)
	  add       r3, r3, r4
	  mulli     r4, r3, 0xA
	  lwz       r6, 0xC(r31)
	  lbz       r3, 0xF1(r6)
	  sub       r0, r0, r4
	  lis       r4, 0x803D
	  rlwinm    r5,r0,2,0,29
	  addi      r0, r4, 0x2360
	  add       r4, r0, r5
	  cmplwi    r3, 0
	  lwz       r0, 0x0(r4)
	  ble-      .loc_0x150
	  stw       r0, 0xEC(r6)
	  b         .loc_0x150

	.loc_0xF0:
	  lwz       r6, 0x4(r31)
	  lis       r3, 0x803D
	  li        r4, 0x1
	  lbz       r5, 0xC(r6)
	  rlwimi    r5,r4,7,24,24
	  rlwinm    r4,r0,2,0,29
	  stb       r5, 0xC(r6)
	  addi      r0, r3, 0x2360
	  add       r3, r0, r4
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x0(r3)
	  lbz       r0, 0xF1(r4)
	  cmplwi    r0, 0
	  ble-      .loc_0x12C
	  stw       r3, 0xEC(r4)

	.loc_0x12C:
	  lwz       r3, 0x8(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xC(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x150:
	  lwz       r0, 0x34(r1)
	  li        r3, 0x1
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
