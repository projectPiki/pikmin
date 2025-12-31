#ifndef _SECTION_H
#define _SECTION_H

#include "Node.h"
#include "types.h"

struct Controller;
struct ModeState;
struct Menu;

/**
 * @brief Game section identifiers to segment game flow.
 * These may have sub-sections within them, which have their own enums (such as for OnePlayerSection).
 */
enum GameSectionID {
	SECTION_NinLogo   = 0, ///< 0, Nintendo logo - `NinLogoSection`.
	SECTION_Titles    = 1, ///< 1, title screen - `TitlesSection`.
	SECTION_MovSample = 2, ///< 2, player for h4m cutscenes - `MovSampleSection`.
	SECTION_PaniTest  = 3, ///< 3, test section for enemies, not accessible in retail - `PaniTestSection`.
	SECTION_OnePlayer = 4, ///< 4, section for story and challenge mode - `OnePlayerSection`.
	SECTION_OgTest    = 5, ///< 5, test section for screens, not accessible in retail - `OgTestSection`.
};

/**
 * @brief Sub-sections of OnePlayerSection, for controlling different areas of story and challenge mode.
 *
 * Most of these sections have an associated Setup section, for initialising and fine control.
 *
 * @note A lot of these are inaccessible in retail, and are holdovers from demos and testing.
 */
enum OnePlayerSectionID {
	ONEPLAYER_GameSetup       = 0,  ///< 0, load-in section when entering story/challenge mode from title - `GameSetupSection`.
	ONEPLAYER_CardSelect      = 1,  ///< 1, section for reading data from memory card/file select for story mode - `CardSelectSection`.
	ONEPLAYER_E3Tutorial      = 2,  ///< 2, unused E3 demo of Impact Site - redirects to a NewPikiGameSection with set parameters.
	ONEPLAYER_E3ForestDay1    = 3,  ///< 3, unused E3 demo of Forest of Hope (Day 1) - redirects to NewPikiGameSection with set parameters.
	ONEPLAYER_E3ForestDay2    = 4,  ///< 4, unused E3 demo of Forest of Hope (Day 2) - redirects to NewPikiGameSection with set parameters.
	ONEPLAYER_IntroGame       = 5,  ///< 5, section for new story files, with the crash landing cutscene playing - `IntroGameSection`.
	ONEPLAYER_MapSelect       = 6,  ///< 6, section for selecting a stage, both for world map and challenge mode - `MapSelectSection`.
	ONEPLAYER_NewPikiGame     = 7,  ///< 7, regular gameplay, both story and challenge mode - `NewPikiGameSection`, with subsections.
	ONEPLAYER_GameCourseClear = 8,  ///< 8, unused section for toggling through different sections for testing - `GameCourseClearSection`.
	ONEPLAYER_GameStageClear  = 9,  ///< 9, unused section, likely for "clearing" a stage - `GameStageClearSection`.
	ONEPLAYER_GameCredits     = 10, ///< 10, unused credits section from the E3 demo - `GameCreditsSection`.
	ONEPLAYER_GameExit        = 11, ///< 11, cleanup section when exiting from OnePlayerSection back to title - `GameExitSection`.

	// E3 demo-related bounds.
	ONEPLAYER_E3_MIN          = ONEPLAYER_E3Tutorial,
	ONEPLAYER_E3_MAX          = ONEPLAYER_E3ForestDay2,
	ONEPLAYER_E3_STAGE_OFFSET = ONEPLAYER_E3Tutorial,
};

/**
 * @brief Flags controlling which game components are updated in a given frame.
 *
 * This enum is used for the 'result' parameter in `ModeState::update`
 * and for the `mUpdateFlags` member in `BaseGameSection`.
 */
enum ModeUpdateFlags {
	UPDATE_NONE        = 0,      ///< 0x0, no updates.
	UPDATE_AI          = 1 << 0, ///< 0x1, update (almost) all AI logic.
	UPDATE_WORLD_CLOCK = 1 << 1, ///< 0x2, update the world clock and time-of-day.
	UPDATE_COUNTDOWN   = 1 << 2, ///< 0x4, update the end-of-day countdown.

	UPDATE_ALL = UPDATE_AI | UPDATE_WORLD_CLOCK | UPDATE_COUNTDOWN, ///< 0x7, update all components.
};

/**
 * @brief Abstract base class for game sections, to control game flow.
 *
 * There is a hierarchy to the sections:
 *
 * - top-level sections (see `GameSectionID` enum) control the broad categories, and inherit from this class.
 *
 * - `OnePlayerSection` has subsections (see `OnePlayerSectionID` enum) to give finer control over gameplay - these inherit from this class.
 *
 *     - sections and subsections usually have a "setup" (initialise/control) section as a helper, which is a node in that section's child
 * list. These usually do not inherit from this, but from `Node` directly.
 *
 *         - some `OnePlayerSection` types (`NewPikiGameSection` and `IntroGameSection`) have `BaseGameSection` setup sections, which
 * themselves manage `ModeState` lists.
 *
 *             - states inheriting from `ModeState` serve as a state machine under their parent setup section, for even finer control.
 *
 *         - `NewPikiGameSetupSection` also initialises a `GameCoreSection` outside of the section hierarchy, to manage the most fine-grain
 * tasks during gameplay.
 *
 * @note Size: 0x20.
 */
struct Section : public Node {

	/// Constructs a blank section.
	Section() { }

	virtual void init() = 0; // _30

	// _00     = VTBL
	// _00-_20 = Node
};

/**
 * @brief Base class for intro cutscene and gameplay "setup" (control) subsections.
 *
 * Has underlying modes/substates (`ModeState`) which help with finer control over the game flow.
 *
 * @note Does not inherit from Section, despite the name - instead, it acts as a list element (Node) *under* a section.
 * @note Size: 0x44.
 */
struct BaseGameSection : public Node {
	BaseGameSection();

	virtual void draw(Graphics& gfx); // _14

	/// Trivial in base class.
	virtual void openMenu() { } // _30

	// _00     = VTBL
	// _00-_20 = Node
	Menu* mActiveMenu;              ///< _20
	Controller* mController;        ///< _24, active controller.
	f32 mCurrentFade;               ///< _28, current fade-in/fade-out value.
	f32 mTargetFade;                ///< _2C, target fade-in/fade-out value.
	f32 mFadeSpeed;                 ///< _30, how fast to fade in/out.
	ModeState* mCurrentModeState;   ///< _34, current control substate.
	ModeState* mNextModeState;      ///< _38, next control substate to transit to.
	u32 mUpdateFlags;               ///< _3C, update flags passed from the current control substate - see `ModeUpdateFlags` enum.
	int mPendingOnePlayerSectionID; ///< _40, one player section to load into on next "reset" (load) - see `OnePlayerSectionID` enum.
};

/**
 * @brief State machine states under `BaseGameSection`-type classes, to give finer game flow control during gameplay.
 *
 * Only used in reality within `IntroGameSetupSection` and `NewPikiGameSetupSection`, and always an inheriting class, never the base.
 *
 * @note Size: 0x8.
 */
struct ModeState {

	/**
	 * @brief Construct a new base-class control substate.
	 *
	 * @param game Parent setup section.
	 */
	ModeState(BaseGameSection* game)
	    : mParentSection(game)
	{
	}

	BaseGameSection* mParentSection; ///< _00, parent setup section.

	/**
	 * @brief Updates the current state. Base class passes back AI and clock updates, but no countdown.
	 * @param result Update flags to pass back, and be handled by the rest of the game engine.
	 * @return Pointer to active state. If not `this`, results in an immediate transit to the new state.
	 */
	virtual ModeState* update(u32& result) // _08
	{
		result = UPDATE_AI | UPDATE_WORLD_CLOCK;
		return this;
	}

	/// Trivial in base class.
	virtual void postRender(Graphics&) { } // _0C

	/// Trivial in base class.
	virtual void postUpdate() { } // _10

	// _04 = VTBL
};

#endif
