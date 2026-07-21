#ifndef _NAVIMGR_H
#define _NAVIMGR_H

#include "CreatureProp.h"
#include "Navi.h"
#include "ObjectMgr.h"
#include "Piki.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x43C.
 */
struct NaviProp : public CreatureProp {

	/**
	 * @brief Fabricated. Offsets relative to NaviProp for convenience.
	 */
	struct Parms : public Parameters {
		inline Parms()
		    : mActionRadius(this, 120.0f, 0.0f, 500.0f, "p00", "アクション半径")
		    , mContinuousPluckDistance(this, 200.0f, 0.0f, 1000.0f, "p60", "連続抜き距離")
		    , mPluckDistanceOutsideOnyon(this, 15.0f, 0.0f, 500.0f, "p62", "抜き距離(onyon外)")
		    , mWhistleMaxRadius(this, 100.0f, 0.0f, 500.0f, "p01", "ピキ呼び最大半径")
		    , mWhistleMinRadius(this, 5.0f, 0.0f, 500.0f, "p53", "ピキ呼び最小半径")
		    , mWhistleExpandTime(this, 0.2f, 0.0f, 500.0f, "p02", "ピキ呼び最大時間")
		    , mWhistleHoldTime(this, 0.15f, 0.0f, 500.0f, "p03", "サークル消え時間")
		    , mMoveSpeed(this, 170.0f, 0.0f, 500.0f, "p04", "移動速度")
		    , mRunSpeed(this, 210.0f, 0.0f, 500.0f, "p56", "走る速さ（好調時）")
		    , mDisplayScale(this, 1.0f, 0.0f, 10.0f, "p38", "表示スケール")
		    , _FC(this, 0.001f, 0.0f, 1.0f, "p05", "Stick 0")
		    , _10C(this, 0.1f, 0.0f, 1.0f, "p20", "Stick 01")
		    , _11C(this, 0.8f, 0.0f, 1.0f, "p06", "Stick 1")
		    , _12C(this, 1.0f, 0.0f, 1.0f, "p07", "Stick 2")
		    , _13C(this, 120.0f, 90.0f, 180.0f, "p08", "すべり角度")
		    , mThrowHoldMaxTime(this, 2.5f, 0.0f, 10.0f, "p09", "投げため限界時間")
		    , mThrowMaxDistance(this, 600.0f, 0.0f, 1000.0f, "p10", "投げ距離(Max)")
		    , mThrowMinDistance(this, 150.0f, 0.0f, 500.0f, "p11", "投げ距離(Min)")
		    , mThrowMaxHeight(this, 100.0f, 0.0f, 1000.0f, "p24", "投げ高さ(Max)")
		    , mThrowMinHeight(this, 80.0f, 0.0f, 1000.0f, "p25", "投げ高さ(min)")
		    , mYellowThrowHeight(this, 200.0f, 0.0f, 1000.0f, "p54", "投げ高さ(黄色)")
		    , mThrowFlightTime(this, 1.0f, 0.0f, 100.0f, "p26", "着地時間")
		    , mPluckGrabRange(this, 80.0f, 0.0f, 200.0f, "p37", "ピキをつかむ有効範囲")
		    , mPluckLoopCount(this, 1, 0, 10, "p42", "抜くループ回数")
		    , mPikiWaitRange(this, 30.0f, 0.0f, 200.0f, "p39", "ピキが待つ範囲")
		    , mPikiFormationChangeRange(this, 60.0f, 0.0f, 200.0f, "p40", "ピキがフォーメーションを変える範囲")
		    , mBodyCollisionRadius(this, 15.0f, 0.0f, 100.0f, "p21", "当たりサイズ")
		    , mGroundCollisionRadius(this, 16.0f, 0.0f, 100.0f, "p41", "地面当たりサイズ")
		    , mInverseMass(this, 4.0f, 0.0f, 2000.0f, "p22", "重さの逆数")
		    , _22C(this, 0.04f, 0.0f, 1.0f, "p23", "エイミング回転スピード")
		    , mAsibumiStartSpeed(this, 5.0f, 0.0f, 500.0f, "p14", "ASIBUMI 開始スピード")
		    , mWalkStartSpeed(this, 35.0f, 0.0f, 500.0f, "p15", "WALK 開始スピード")
		    , mRunStartSpeed(this, 70.0f, 0.0f, 500.0f, "p16", "RUN 開始スピード")
		    , mEscapeStartSpeed(this, 160.0f, 0.0f, 500.0f, "p17", "ESCAPE 開始スピード")
		    , mWalkAnimMinFrames(this, 30.0f, 0.0f, 300.0f, "p18", "WALK 再生フレーム数(min)")
		    , mWalkAnimMaxFrames(this, 60.0f, 0.0f, 300.0f, "p19", "WALK 再生フレーム数(max)")
		    , mRunAnimMinFrames(this, 30.0f, 0.0f, 300.0f, "p27", "RUN 再生フレーム数(min)")
		    , mRunAnimMaxFrames(this, 60.0f, 0.0f, 300.0f, "p28", "RUN 再生フレーム数(max)")
		    , mEscapeAnimMinFrames(this, 30.0f, 0.0f, 300.0f, "p29", "ESCAPE 再生フレーム数(min)")
		    , _2CC(this, 60.0f, 0.0f, 300.0f, "p30", "ESCAPE 再生フレーム数(max)")
		    , mPressedTotalTime(this, 3.0f, 0.0f, 10.0f, "p31", "つぶれ総時間")
		    , mPressedFlatTime(this, 1.0f, 0.0f, 10.0f, "p32", "ぺったんこ時間")
		    , _2FC(this, 0.5f, 0.0f, 10.0f, "p33", "押し開始時間")
		    , _30C(this, 0.3f, 0.0f, 1.0f, "p34", "押し開始スティック量")
		    , mShakePreventionAngle(this, 10.0f, 0.0f, 180.0f, "p35", "手ぶれ防止角度")
		    , _32C(this, 0.1f, 0.0f, 1.0f, "p36", "手ぶれ防止大きさ")
		    , mCursorMoveDelayTime(this, 2.0f, 0.0f, 60.0f, "p48", "カーソル移動スピード")
		    , mPikiImpatienceTime(this, 8.0f, 0.0f, 60.0f, "p49", "ピキがしびれを切らす時間")
		    , mNeutralStickThreshold(this, 0.1f, 0.0f, 1.0f, "p43", "ニュートラルスティック")
		    , mCursorMoveStickThreshold(this, 0.75f, 0.0f, 1.0f, "p44", "カーソル移動スティック")
		    , mClampStickToMaxThreshold(this, 0.85f, 0.0f, 1.0f, "p48", "クランプスティック")
		    , mCursorMinRadius(this, 50.0f, 0.0f, 1000.0f, "p45", "カーソル移動最小半径")
		    , mCursorMaxRadius(this, 300.0f, 0.0f, 2000.0f, "p46", "カーソル移動最大半径")
		    , mCursorMoveSpeed(this, 200.0f, 0.0f, 1000.0f, "p47", "カーソル移動スピード")
		    , mHealth(this, 100.0f, 0.0f, 1000.0f, "p50", "ライフ")
		    , mPunchDamage(this, 1.0f, 0.0f, 1000.0f, "p51", "攻撃力")
		    , mPunchRadius(this, 10.0f, 0.0f, 100.0f, "p52", "攻撃範囲")
		    , mPluckCursorCount(this, 1, 0, 10, "p55", "カーソルカウント")
		    , mMinKinokoFlickActions(this, 4, 0, 16, "p57", "kinoko Flick Count")
		    , mBuryEscapeKeyCount(this, 3, 0, 16, "p58", "bury Key Count")
		    , mBuryEscapeSuccessCount(this, 3, 0, 16, "p59", "bury Exit Count")
		    , mPostPluckZoomOutTime(this, 100, 0, 1000, "p61", "寄りカメラズームアウト(frame)")
		{
		}

		// _58-_5C = Parameters
		Parm<f32> mActionRadius;              // _5C, p00, action radius?
		Parm<f32> mContinuousPluckDistance;   // _6C, p60, continuous withdrawal distance?
		Parm<f32> mPluckDistanceOutsideOnyon; // _7C, p62, extraction distance (outside onyon)?
		Parm<f32> mWhistleMaxRadius;          // _8C, p01, max whistle radius?
		Parm<f32> mWhistleMinRadius;          // _9C, p53, min whistle radius?
		Parm<f32> mWhistleExpandTime;         // _AC, p02, whistle transition timer?
		Parm<f32> mWhistleHoldTime;           // _BC, p03, whistle holding timer?
		Parm<f32> mMoveSpeed;                 // _CC, p04, speed?
		Parm<f32> mRunSpeed;                  // _DC, p56, running speed (good condition)?
		Parm<f32> mDisplayScale;             // _EC, p38, Olimar size
		Parm<f32> _FC;                       // _FC, p05, stick 0?
		Parm<f32> _10C;                      // _10C, p20, stick 01?
		Parm<f32> _11C;                      // _11C, p06, stick 1?
		Parm<f32> _12C;                      // _12C, p07, stick 2?
		Parm<f32> _13C;                      // _13C, p08, slip angle?
		Parm<f32> mThrowHoldMaxTime;         // _14C, p09, limit time for throwing?
		Parm<f32> mThrowMaxDistance;         // _15C, p10, throwing dist (max)?
		Parm<f32> mThrowMinDistance;         // _16C, p11, throwing dist (min)?
		Parm<f32> mThrowMaxHeight;           // _17C, p24, throwing height (max)?
		Parm<f32> mThrowMinHeight;           // _18C, p25, throwing height (min)?
		Parm<f32> mYellowThrowHeight;        // _19C, p54, throwing height (yellow)?
		Parm<f32> mThrowFlightTime;          // _1AC, p26, landing time?
		Parm<f32> mPluckGrabRange;           // _1BC, p37, eff range to grasp piki?
		Parm<int> mPluckLoopCount;           // _1CC, p42, num loops pulled out?
		Parm<f32> mPikiWaitRange;            // _1DC, p39, range where piki waits?
		Parm<f32> mPikiFormationChangeRange; // _1EC, p40, range where piki change formation?
		Parm<f32> mBodyCollisionRadius;      // _1FC, p21, per size?
		Parm<f32> mGroundCollisionRadius;    // _20C, p41, ground per size?
		Parm<f32> mInverseMass;              // _21C, p22, recip of weight?
		Parm<f32> _22C;                      // _22C, p23, aiming rotation speed?
		Parm<f32> mAsibumiStartSpeed;        // _23C, p14, asibumi start speed?
		Parm<f32> mWalkStartSpeed;           // _24C, p15, walk start speed?
		Parm<f32> mRunStartSpeed;            // _25C, p16, run start speed?
		Parm<f32> mEscapeStartSpeed;         // _26C, p17, escape start speed?
		Parm<f32> mWalkAnimMinFrames;        // _27C, p18, walk frames (min)?
		Parm<f32> mWalkAnimMaxFrames;        // _28C, p19, walk frames (max)?
		Parm<f32> mRunAnimMinFrames;         // _29C, p27, run frames (min)?
		Parm<f32> mRunAnimMaxFrames;         // _2AC, p28, run frames (max)?
		Parm<f32> mEscapeAnimMinFrames;      // _2BC, p29, escape frames (min)?
		Parm<f32> _2CC;                      // _2CC, p30, escape frames (max)?
		Parm<f32> mPressedTotalTime;         // _2DC, p31, collapse total time?
		Parm<f32> mPressedFlatTime;          // _2EC, p32, completely flat time?
		Parm<f32> _2FC;                      // _2FC, p33, push start time?
		Parm<f32> _30C;                      // _30C, p34, push start stick amount?
		Parm<f32> mShakePreventionAngle;     // _31C, p35, shake prevention angle?
		Parm<f32> _32C;                      // _32C, p36, anti-shake size?
		Parm<f32> mCursorMoveDelayTime;      // _33C, p48, cursor moving stick?
		Parm<f32> mPikiImpatienceTime;       // _34C, p49, time for piki to get numb?
		Parm<f32> mNeutralStickThreshold;    // _35C, p43, neutral stick?
		Parm<f32> mCursorMoveStickThreshold; // _36C, p44, cursor moving stick?
		Parm<f32> mClampStickToMaxThreshold; // _37C, p48, clamp stick?
		Parm<f32> mCursorMinRadius;          // _38C, p45, cursor movement min radius?
		Parm<f32> mCursorMaxRadius;          // _39C, p46, cursor movement max radius?
		Parm<f32> mCursorMoveSpeed;          // _3AC, p47, cursor movement speed?
		Parm<f32> mHealth;                   // _3BC, p50, Olimar's health
		Parm<f32> mPunchDamage;              // _3CC, p51, punch damage?
		Parm<f32> mPunchRadius;              // _3DC, p52, punch radius?
		Parm<int> mPluckCursorCount;         // _3EC, p55, cursor count?
		Parm<int> mMinKinokoFlickActions;    // _3FC, p57, need to put in (this + 1) "actions" to flick a puffmin
		Parm<int> mBuryEscapeKeyCount;       // _40C, p58, bury key count?
		Parm<int> mBuryEscapeSuccessCount;   // _41C, p59, bury exit count?
		Parm<int> mPostPluckZoomOutTime;     // _42C, p61, #frames after we stop plucking to release focus cam
	};

	NaviProp();

	virtual void read(RandomAccessStream& input) // _08 (weak)
	{
		mCreatureProps.read(input);
		mNaviProps.read(input);
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
	Parms mNaviProps; // _58
};

/**
 * @brief TODO
 */
class NaviMgr : public MonoObjectMgr {
public:
	NaviMgr();

	virtual ~NaviMgr() { }                  // _48
	virtual void update();                  // _4C
	virtual Creature* createObject();       // _80
	virtual void read(RandomAccessStream&); // _84

	Navi* getNavi();
	Navi* getNavi(int);
	void refresh2d(Graphics&);
	void renderCircle(Graphics&);
	void drawShadow(Graphics&);

	// unused/inlined:
	void init();

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
	u8 _3C[0x4];                          // _3C, unknown
	Shape* mNaviShape;                    // _40
	u8 _44[0x4];                          // _44, unknown
	PikiShapeObject* mNaviShapeObject[2]; // _48
	PaniMotionTable* mMotionTable;        // _50
	int mNaviID;                          // _54
	NaviProp* mNaviParms;                 // _58
};

extern NaviMgr* naviMgr;

#endif
