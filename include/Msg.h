#ifndef _MSG_H
#define _MSG_H

#include "types.h"

/**
 * @brief TODO
 */
struct Msg {
	u32 _00; // _00, maybe msg type?
};

/**
 * @brief TODO
 *
 * @note will need to fix saiEvents.cpp when this gets worked out
 */
struct MsgAnim : public Msg {
	// _00-_04 = Msg
	u32* _04; // _04, probably a pointer to a struct with a u32 or int at _00
};

/**
 * @brief TODO
 */
struct MsgBounce : public Msg {
};

/**
 * @brief TODO
 */
struct MsgCollide : public Msg {
};

/**
 * @brief TODO
 */
struct MsgDamage : public Msg {
};

/**
 * @brief TODO
 */
struct MsgGround : public Msg {
};

/**
 * @brief TODO
 */
struct MsgHang : public Msg {
};

/**
 * @brief TODO
 */
struct MsgOffWall : public Msg {
};

/**
 * @brief TODO
 */
struct MsgStick : public Msg {
};

/**
 * @brief TODO
 */
struct MsgTarget : public Msg {
};

/**
 * @brief TODO
 */
struct MsgUser : public Msg {
	// _00-_04 = Msg
	u32 _04; // _04, could be int
};

/**
 * @brief TODO
 */
struct MsgWall : public Msg {
};

#endif
