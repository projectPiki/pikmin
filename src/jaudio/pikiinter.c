#include "jaudio/pikiinter.h"

#include "jaudio/jammain_2.h"
#include "jaudio/cmdqueue.h"
#include "jaudio/cmdstack.h"
#include "jaudio/interface.h"
#include "jaudio/piki_player.h"
#include "jaudio/pikidemo.h"
#include "jaudio/verysimple.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/filter3d.h"

// rename better later
typedef struct SEvent_UnkC {
	u32 _00; // _00, unknown
	u8 _04;  // _04
	u32 _08; // _08, unknown
} SEvent_UnkC;

/**
 * @brief TODO
 *
 * @note Size: 0x1B4.
 */
typedef struct SEvent_ {
	SVector_ position;      // _00
	SEvent_UnkC _0C[16];    // _0C
	u32 eventType;          // _CC
	seqp_* track;           // _D0
	CmdQueue cmdQueue;      // _D4
	SEvent_* _140;          // _140
	int _144;               // _144
	u8 _148[0x160 - 0x148]; // _148, unknown
	f32 volume;             // _160
	f32 pan;                // _164
	u8 _168[0x170 - 0x168]; // _168, unknown
	int frameTimer;         // _170
	OuterParam_ outerParam; // _174
} SEvent_;

// fabricated name, need something for the CAMERA .comm entry
// size 0x24.
typedef struct SCamera_ {
	u8 pad[0x24]; // _00
} SCamera_;

typedef struct Portargs_ {
	SEvent_* mEvent; // _00
} Portargs_;

int CURRENT_TIME;
SEvent_ EVENT[16];
SCamera_ CAMERA;

static int EVENT_OFFSET[] = { 0, 1, 0xad, 0xbe, 0xcd, 0xd7, 0xdb, 0x105 };
static struct ActionStatus {
	u8 _00;
	u8 _01;
	u16 _02;
	u16 _04;
} ACTION_STATUS[]              = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
static f32 EVENT_DIST_SCALE[8] = { 1.0f, 1.0f, 2.0f, 0.8f, 1.2f, 1.0f, 1.2f, 2.0f };

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Jac_Debug_ActionEntry(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800175E0
 * Size:	000048
 */
void __SetVolandPan(Portargs_* arg)
{
	SEvent_* evt;
	seqp_* track;

	evt   = arg->mEvent;
	track = evt->track;
	Jam_SetExtParam(evt->volume, track, 1);
	track = evt->track;
	Jam_SetExtParam(evt->pan, track, 8);
}

/*
 * --INFO--
 * Address:	80017640
 * Size:	000048
 */
void SendToStack(SEvent_* evt)
{
	evt->_140 = evt;
	Set_Portcmd(&evt->_144, (int)__SetVolandPan, (int)&evt->_140);
	Add_PortcmdOnce((u32*)&evt->_144);
}

/*
 * --INFO--
 * Address:	800176A0
 * Size:	0000EC
 */
void Jac_InitEventSystem(void)
{
	seqp_* handle;
	u32 i;
	u32 j;

	Jac_SetProcessStatus(10);
	CURRENT_TIME = 0;

	do {
		handle = Jam_GetTrackHandle(0x20000);
	} while (handle == NULL);

	for (i = 0; i < 16; i++) {
		EVENT[i].eventType = 0;
		EVENT[i].track     = handle->children[i];

		Jam_InitExtBuffer(&EVENT[i].outerParam);
		Jam_AssignExtBuffer(handle->children[i], &EVENT[i].outerParam);
		Jam_OnExtSwitch(handle->children[i], 9);

		Jal_AddCmdQueue(&EVENT[i].cmdQueue, EVENT[i].track, 0);

		for (j = 0; j < 16; j++) {
			EVENT[i]._0C[j]._00 = 0;
			EVENT[i]._0C[j]._04 = 0;
			EVENT[i]._0C[j]._08 = 0;
		}
	}

	Jac_SetProcessStatus(11);
}

/*
 * --INFO--
 * Address:	800177A0
 * Size:	0000BC
 */
void Jac_EventFrameCheck(void)
{
	u32 i, j;
	if (Jac_DemoCheck()) {
		return;
	}
	if (Jac_PauseCheck()) {
		return;
	}

	for (i = 0; i < 16; i++) {
		if (!EVENT[i].eventType) {
			continue;
		}
		if (!EVENT[i].frameTimer) {
			continue;
		}
		EVENT[i].frameTimer--;
		if (EVENT[i].frameTimer) {
			continue;
		}
		for (j = 0; j < 16; j++) {
			EVENT[i]._0C[i]._00 = 0;
		}

		Jal_SendCmdQueue_Force(&EVENT[i].cmdQueue, 0xFFFF);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r27, 0xC(r1)
	  bl        0x29D0
	  cmpwi     r3, 0
	  bne-      .loc_0xA8
	  bl        -0xCBC
	  cmpwi     r3, 0
	  bne-      .loc_0xA8
	  lis       r3, 0x803E
	  li        r27, 0
	  subi      r28, r3, 0x5034
	  li        r31, 0
	  li        r30, 0
	  lis       r29, 0x1

	.loc_0x40:
	  add       r5, r28, r30
	  lwz       r0, 0xCC(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x94
	  lwz       r3, 0x170(r5)
	  cmpwi     r3, 0
	  beq-      .loc_0x94
	  subi      r0, r3, 0x1
	  stw       r0, 0x170(r5)
	  lwz       r0, 0x170(r5)
	  cmpwi     r0, 0
	  bne-      .loc_0x94
	  li        r0, 0x10
	  add       r4, r5, r31
	  li        r3, 0
	  mtctr     r0

	.loc_0x80:
	  stw       r3, 0xC(r4)
	  bdnz+     .loc_0x80
	  addi      r3, r5, 0xD4
	  subi      r4, r29, 0x1
	  bl        0x4210

	.loc_0x94:
	  addi      r27, r27, 0x1
	  addi      r30, r30, 0x1B4
	  cmplwi    r27, 0x10
	  addi      r31, r31, 0xC
	  blt+      .loc_0x40

	.loc_0xA8:
	  lmw       r27, 0xC(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017860
 * Size:	00013C
 */
void Jac_UpdateCamera(struct SVector_* p1, struct SVector_* p2)
{
	u8 set = FALSE;
	u32 i;

	CURRENT_TIME++;

	for (i = 0; i < 16; i++) {
		if (EVENT[i].eventType) {
			f32 dist  = EVENT_DIST_SCALE[EVENT[i].eventType];
			f32 dist2 = dist * V3D_Abs((Vector3D_*)&EVENT[i].position);
			if (dist2 > 1.0f) {
				dist2 = 1.0f;
			}
			dist  = 1.0f - dist2;
			dist2 = V3D_GetAngle((Vector3D_*)&EVENT[i].position);
			if (dist2 >= 3.1416f) {
				dist2 += -6.2832f;
			}
			dist2 = 0.5f + (-dist2 / 3.1416f);
			if (dist2 > 1.0f) {
				dist2 -= 2.0f;
			}
			if (dist2 < 0.0f) {
				dist2 = -dist2;
			}
			EVENT[i].volume = dist;
			EVENT[i].pan    = dist2;
			if (dist >= 0.8f && EVENT[i].eventType == 1) {
				set = TRUE;
			}
			SendToStack(&EVENT[i]);
		}
	}

	Jac_SetBgmModeFlag(0, 1, set);
	Jac_UpdatePikiGaya();

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  addi      r11, r1, 0x68
	  bl        0x1FD5DC
	  stmw      r26, 0x10(r1)
	  lwz       r5, 0x2C80(r13)
	  lis       r3, 0x8022
	  lis       r4, 0x803E
	  lfs       f25, -0x7E68(r2)
	  addi      r0, r5, 0x1
	  lfs       f26, -0x7E64(r2)
	  stw       r0, 0x2C80(r13)
	  addi      r30, r3, 0x610C
	  lfs       f27, -0x7E60(r2)
	  subi      r29, r4, 0x5034
	  lfs       f28, -0x7E5C(r2)
	  li        r26, 0
	  lfs       f29, -0x7E58(r2)
	  li        r27, 0
	  lfs       f30, -0x7E54(r2)
	  li        r31, 0
	  lfs       f31, -0x7E50(r2)

	.loc_0x5C:
	  add       r28, r29, r31
	  lwz       r0, 0xCC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0xFC
	  rlwinm    r0,r0,2,0,29
	  addi      r3, r28, 0
	  add       r4, r30, r0
	  lfs       f24, 0x0(r4)
	  bl        0x42C4
	  fmuls     f0, f1, f24
	  fcmpo     cr0, f0, f25
	  ble-      .loc_0x90
	  fmr       f0, f25

	.loc_0x90:
	  fsubs     f24, f25, f0
	  mr        r3, r28
	  bl        0x4268
	  fcmpo     cr0, f1, f26
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xAC
	  fadds     f1, f27, f1

	.loc_0xAC:
	  fneg      f0, f1
	  fdivs     f0, f0, f26
	  fadds     f0, f28, f0
	  fcmpo     cr0, f0, f25
	  ble-      .loc_0xC4
	  fsubs     f0, f29, f0

	.loc_0xC4:
	  fcmpo     cr0, f0, f30
	  bge-      .loc_0xD0
	  fneg      f0, f0

	.loc_0xD0:
	  stfs      f24, 0x160(r28)
	  fcmpo     cr0, f24, f31
	  stfs      f0, 0x164(r28)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xF4
	  lwz       r0, 0xCC(r28)
	  cmplwi    r0, 0x1
	  bne-      .loc_0xF4
	  li        r26, 0x1

	.loc_0xF4:
	  mr        r3, r28
	  bl        -0x318

	.loc_0xFC:
	  addi      r27, r27, 0x1
	  addi      r31, r31, 0x1B4
	  cmplwi    r27, 0x10
	  blt+      .loc_0x5C
	  addi      r5, r26, 0
	  li        r3, 0
	  li        r4, 0x1
	  bl        0x15C8
	  bl        0xE44
	  lwz       r0, 0x6C(r1)
	  addi      r11, r1, 0x68
	  bl        0x1FD510
	  lmw       r26, 0x10(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800179A0
 * Size:	000118
 */
int Jac_CreateEvent(u32 eventType, struct SVector_* p2)
{
	u32 i, j;
	u32 idx;
	u32* REF_p1 = &eventType;
	if (!eventType) {
		return -1;
	}

	if (!Jac_DemoCheckEvent(eventType)) {
		return -1;
	}

	for (i = 0; i < 16; i++) {
		if (!EVENT[i].eventType) {
			break;
		}
	}

	if (i == 16) {
		return -1;
	}

	idx = i;

	EVENT[idx].eventType = eventType;

	EVENT[idx].position.x = p2->x;
	EVENT[idx].position.y = p2->z;
	EVENT[idx].position.z = p2->y;

	for (i = 0; i < 16; i++) {
		EVENT[idx]._0C[i]._00 = 0;
		EVENT[idx]._0C[i]._04 = 0;
		EVENT[idx]._0C[i]._08 = 0;
	}

	EVENT[idx].frameTimer = 100;

	switch (eventType) {
	case 7:
		Jac_PlayEventAction(idx, 4);
		break;
	}

	return idx;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  mr        r29, r4
	  stw       r3, 0x8(r1)
	  lwz       r31, 0x8(r1)
	  cmplwi    r31, 0
	  bne-      .loc_0x2C
	  li        r3, -0x1
	  b         .loc_0x104

	.loc_0x2C:
	  rlwinm    r3,r31,0,24,31
	  bl        0x2890
	  cmpwi     r3, 0
	  bne-      .loc_0x44
	  li        r3, -0x1
	  b         .loc_0x104

	.loc_0x44:
	  lis       r3, 0x803E
	  li        r0, 0x10
	  subi      r5, r3, 0x5034
	  li        r6, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0x5C:
	  add       r4, r5, r3
	  lwz       r0, 0xCC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x78
	  addi      r6, r6, 0x1
	  addi      r3, r3, 0x1B4
	  bdnz+     .loc_0x5C

	.loc_0x78:
	  cmplwi    r6, 0x10
	  bne-      .loc_0x88
	  li        r3, -0x1
	  b         .loc_0x104

	.loc_0x88:
	  mulli     r4, r6, 0x1B4
	  lis       r3, 0x803E
	  subi      r3, r3, 0x5034
	  li        r0, 0x10
	  add       r7, r3, r4
	  addi      r30, r6, 0
	  stw       r31, 0xCC(r7)
	  li        r3, 0
	  li        r4, 0
	  lfs       f0, 0x0(r29)
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x8(r29)
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x4(r29)
	  stfs      f0, 0x8(r7)
	  mtctr     r0

	.loc_0xC8:
	  add       r5, r7, r3
	  addi      r3, r3, 0xC
	  stw       r4, 0xC(r5)
	  stb       r4, 0x10(r5)
	  stw       r4, 0x14(r5)
	  bdnz+     .loc_0xC8
	  li        r0, 0x64
	  cmpwi     r31, 0x7
	  stw       r0, 0x170(r7)
	  beq-      .loc_0xF4
	  b         .loc_0x100

	.loc_0xF4:
	  addi      r3, r30, 0
	  li        r4, 0x4
	  bl        0x84

	.loc_0x100:
	  mr        r3, r30

	.loc_0x104:
	  lmw       r29, 0x1C(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017AC0
 * Size:	00005C
 */
BOOL Jac_UpdateEventPosition(int idx, struct SVector_* p2)
{
	if (idx == -1) {
		return FALSE;
	}

	if (!EVENT[idx].eventType) {
		return FALSE;
	}

	EVENT[idx].position   = *p2;
	EVENT[idx].frameTimer = 100;
	return TRUE;
}

/*
 * --INFO--
 * Address:	80017B20
 * Size:	0002E0
 */
BOOL Jac_PlayEventAction(int a1, int a2)
{
	if (a1 == -1) {
		return FALSE;
	}
	if (EVENT[a1].eventType == 0) {
		return FALSE;
	}

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  cmpwi     r3, -0x1
	  addi      r5, r5, 0x5A68
	  stwu      r1, -0x38(r1)
	  stmw      r25, 0x1C(r1)
	  bne-      .loc_0x28
	  li        r3, 0
	  b         .loc_0x2CC

	.loc_0x28:
	  mulli     r6, r3, 0x1B4
	  lis       r3, 0x803E
	  subi      r0, r3, 0x5034
	  add       r31, r0, r6
	  lwz       r0, 0xCC(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x2CC

	.loc_0x4C:
	  rlwinm    r3,r0,2,0,29
	  li        r0, 0x10
	  lwzx      r6, r5, r3
	  li        r7, 0
	  li        r3, 0
	  add       r28, r4, r6
	  mtctr     r0

	.loc_0x68:
	  addi      r0, r3, 0xC
	  lwzx      r0, r31, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  addi      r7, r7, 0x1
	  addi      r3, r3, 0xC
	  bdnz+     .loc_0x68

	.loc_0x84:
	  mulli     r0, r28, 0x6
	  addi      r30, r7, 0
	  add       r3, r5, r0
	  lbz       r7, 0x20(r3)
	  lbz       r29, 0x22(r3)
	  rlwinm.   r3,r7,0,27,27
	  beq-      .loc_0x180
	  rlwinm.   r3,r7,0,28,31
	  addi      r11, r3, 0
	  bne-      .loc_0xB0
	  li        r11, 0x10

	.loc_0xB0:
	  add       r4, r5, r0
	  li        r3, 0x10
	  lbz       r25, 0x21(r4)
	  li        r12, 0
	  lwz       r6, 0x2C80(r13)
	  li        r27, 0
	  li        r26, 0
	  li        r10, 0
	  li        r4, 0
	  mtctr     r3

	.loc_0xD8:
	  add       r8, r31, r4
	  lwz       r9, 0xC(r8)
	  cmplwi    r9, 0
	  beq-      .loc_0x140
	  lbz       r3, 0x10(r8)
	  cmplw     r3, r29
	  bne-      .loc_0xF8
	  addi      r12, r12, 0x1

	.loc_0xF8:
	  mulli     r3, r9, 0x6
	  add       r3, r5, r3
	  lbz       r3, 0x21(r3)
	  cmplw     r25, r3
	  addi      r9, r3, 0
	  ble-      .loc_0x120
	  lwz       r3, 0x14(r8)
	  addi      r26, r10, 0
	  addi      r25, r9, 0
	  sub       r27, r6, r3

	.loc_0x120:
	  cmplw     r25, r9
	  bne-      .loc_0x140
	  lwz       r3, 0x14(r8)
	  sub       r3, r6, r3
	  cmplw     r3, r27
	  ble-      .loc_0x140
	  addi      r27, r3, 0
	  addi      r26, r10, 0

	.loc_0x140:
	  addi      r10, r10, 0x1
	  addi      r4, r4, 0xC
	  bdnz+     .loc_0xD8
	  cmplw     r12, r11
	  bge-      .loc_0x15C
	  cmplwi    r30, 0x10
	  bne-      .loc_0x214

	.loc_0x15C:
	  rlwinm.   r3,r7,0,26,26
	  beq-      .loc_0x178
	  lwz       r4, 0x2C88(r13)
	  li        r3, 0
	  addi      r0, r4, 0x1
	  stw       r0, 0x2C88(r13)
	  b         .loc_0x2CC

	.loc_0x178:
	  mr        r30, r26
	  b         .loc_0x214

	.loc_0x180:
	  li        r3, 0x10
	  li        r9, 0x10
	  li        r8, 0
	  li        r4, 0
	  mtctr     r3

	.loc_0x194:
	  add       r3, r31, r4
	  lwz       r6, 0xC(r3)
	  cmplwi    r6, 0
	  bne-      .loc_0x1AC
	  mr        r9, r8
	  b         .loc_0x1FC

	.loc_0x1AC:
	  lbz       r3, 0x10(r3)
	  cmplw     r3, r29
	  bne-      .loc_0x1FC
	  rlwinm.   r3,r7,0,26,26
	  beq-      .loc_0x1F4
	  mulli     r3, r6, 0x6
	  addi      r6, r5, 0x21
	  lbzx      r4, r6, r0
	  lbzx      r3, r6, r3
	  cmplw     r4, r3
	  ble-      .loc_0x1E0
	  mr        r30, r8
	  b         .loc_0x208

	.loc_0x1E0:
	  lwz       r4, 0x2C88(r13)
	  li        r3, 0
	  addi      r0, r4, 0x1
	  stw       r0, 0x2C88(r13)
	  b         .loc_0x2CC

	.loc_0x1F4:
	  mr        r30, r8
	  b         .loc_0x208

	.loc_0x1FC:
	  addi      r8, r8, 0x1
	  addi      r4, r4, 0xC
	  bdnz+     .loc_0x194

	.loc_0x208:
	  cmplwi    r8, 0x10
	  bne-      .loc_0x214
	  mr        r30, r9

	.loc_0x214:
	  cmplwi    r30, 0x10
	  bne-      .loc_0x28C
	  add       r4, r5, r0
	  li        r3, 0x10
	  lbz       r6, 0x21(r4)
	  li        r7, 0
	  li        r4, 0
	  addi      r8, r6, 0x1
	  mtctr     r3

	.loc_0x238:
	  addi      r6, r4, 0xC
	  rlwinm    r3,r8,0,24,31
	  lwzx      r6, r31, r6
	  mulli     r6, r6, 0x6
	  add       r6, r5, r6
	  lbz       r6, 0x21(r6)
	  cmplw     r6, r3
	  addi      r3, r6, 0
	  bge-      .loc_0x264
	  addi      r8, r3, 0
	  addi      r30, r7, 0

	.loc_0x264:
	  addi      r7, r7, 0x1
	  addi      r4, r4, 0xC
	  bdnz+     .loc_0x238
	  cmplwi    r30, 0x10
	  bne-      .loc_0x28C
	  lwz       r4, 0x2C88(r13)
	  li        r3, 0
	  addi      r0, r4, 0x1
	  stw       r0, 0x2C88(r13)
	  b         .loc_0x2CC

	.loc_0x28C:
	  lwz       r6, 0x2C84(r13)
	  add       r4, r5, r0
	  rlwinm    r5,r30,12,0,19
	  addi      r3, r31, 0xD4
	  addi      r0, r6, 0x1
	  stw       r0, 0x2C84(r13)
	  lhz       r0, 0x24(r4)
	  or        r4, r5, r0
	  bl        0x3C74
	  mulli     r0, r30, 0xC
	  li        r3, 0x1
	  add       r4, r31, r0
	  stw       r28, 0xC(r4)
	  stb       r29, 0x10(r4)
	  lwz       r0, 0x2C80(r13)
	  stw       r0, 0x14(r4)

	.loc_0x2CC:
	  lmw       r25, 0x1C(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017E00
 * Size:	0000BC
 */
BOOL Jac_StopEventAction(int a1, int a2)
{
	if (a1 == -1) {
		return FALSE;
	}
	if (EVENT[a1].eventType == 0) {
		return FALSE;
	}

	int msg    = 0;
	int offset = a2 + EVENT_OFFSET[EVENT[a1].eventType];
	for (u32 i = 0; i < 0x10; i++) {
		SEvent_UnkC* c = &EVENT[a1]._0C[i];
		if (c->_00 == offset) {
			Jal_SendCmdQueue_Force(&EVENT[a1].cmdQueue, msg);
			c->_00 = 0;
		}
		msg += 0x1000;
	}
	return TRUE;
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r3, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r25, 0x14(r1)
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0x20:
	  mulli     r5, r3, 0x1B4
	  lis       r3, 0x803E
	  subi      r0, r3, 0x5034
	  add       r28, r0, r5
	  lwz       r0, 0xCC(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0x44:
	  lis       r3, 0x8022
	  li        r30, 0
	  rlwinm    r5,r0,2,0,29
	  addi      r0, r3, 0x5A68
	  add       r3, r0, r5
	  addi      r29, r30, 0
	  lwz       r0, 0x0(r3)
	  li        r26, 0
	  li        r31, 0
	  add       r25, r4, r0

	.loc_0x6C:
	  addi      r27, r30, 0xC
	  add       r27, r28, r27
	  lwz       r0, 0x0(r27)
	  cmplw     r0, r25
	  bne-      .loc_0x90
	  addi      r3, r28, 0xD4
	  rlwinm    r4,r31,0,16,31
	  bl        0x3BB8
	  stw       r29, 0x0(r27)

	.loc_0x90:
	  addi      r26, r26, 0x1
	  addi      r30, r30, 0xC
	  cmplwi    r26, 0x10
	  addi      r31, r31, 0x1000
	  blt+      .loc_0x6C
	  li        r3, 0x1

	.loc_0xA8:
	  lmw       r25, 0x14(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017EC0
 * Size:	000070
 */
BOOL MML_StopEventAction(u8 idx, u8 a2, u16 a3)
{
	if (EVENT[idx].eventType == 0) {
		return FALSE;
	}
	if (ACTION_STATUS[EVENT[idx]._0C[a2]._00]._04 != a3) {
		return FALSE;
	}
	EVENT[idx].eventType = 0;
	return TRUE;
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,24,31
	  lis       r3, 0x803E
	  mulli     r6, r0, 0x1B4
	  subi      r0, r3, 0x5034
	  add       r6, r0, r6
	  lwz       r0, 0xCC(r6)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  rlwinm    r0,r4,0,24,31
	  lis       r3, 0x8022
	  mulli     r0, r0, 0xC
	  rlwinm    r4,r5,0,16,31
	  addi      r3, r3, 0x5A88
	  add       r5, r6, r0
	  lwzu      r0, 0xC(r5)
	  mulli     r0, r0, 0x6
	  add       r3, r3, r0
	  lhz       r0, 0x4(r3)
	  cmplw     r4, r0
	  beq-      .loc_0x60
	  li        r3, 0
	  blr

	.loc_0x60:
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0x0(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017F40
 * Size:	00005C
 */
void MML_StopEventAll(u8 idx, u16 p2)
{
	u32 i;
	u16 flag = 1;
	if (EVENT[idx].eventType == 0) {
		return;
	}

	for (i = 0; i < 16; i++) {
		if ((p2 & flag) == 0) {
			EVENT[idx]._0C[i]._00 = 0;
		}
		flag = (flag << 1) & 0xFFFE;
	}
}

/*
 * --INFO--
 * Address:	80017FA0
 * Size:	000094
 */
BOOL Jac_DestroyEvent(s32 idx)
{
	u32 i;
	if (idx == -1) {
		return FALSE;
	}

	if (EVENT[idx].eventType == 0) {
		return FALSE;
	}

	for (i = 0; i < 16; i++) {
		EVENT[idx]._0C[i]._00 = 0;
	}

	Jal_SendCmdQueue_Force(&EVENT[idx].cmdQueue, 0xFFFF);
	EVENT[idx].eventType = 0;
	return TRUE;

	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r3, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x80

	.loc_0x20:
	  mulli     r4, r3, 0x1B4
	  lis       r3, 0x803E
	  subi      r0, r3, 0x5034
	  add       r31, r0, r4
	  lwz       r0, 0xCC(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x80

	.loc_0x44:
	  li        r3, 0
	  li        r0, 0x10
	  addi      r4, r3, 0
	  mtctr     r0

	.loc_0x54:
	  addi      r0, r3, 0xC
	  addi      r3, r3, 0xC
	  stwx      r4, r31, r0
	  bdnz+     .loc_0x54
	  lis       r4, 0x1
	  addi      r3, r31, 0xD4
	  subi      r4, r4, 0x1
	  bl        0x3A30
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0xCC(r31)

	.loc_0x80:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80018040
 * Size:	00003C
 */
void Jac_InitAllEvent(void)
{
	u32 i;
	for (i = 0; i < 16; i++) {
		Jac_DestroyEvent(i);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void Jac_DestroyNotThisEvent(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80018080
 * Size:	000038
 */
int Jac_CheckFreeEvents(void)
{
	u32 i;
	int count = 0;
	for (i = 0; i < 16; i++) {
		if (!EVENT[i].eventType) {
			count++;
		}
	}

	return count;
}

/*
 * --INFO--
 * Address:	800180C0
 * Size:	000050
 */
int Jac_GetActiveEvents(u32* eventIDs)
{
	u32 count = 0;
	u32 i;
	for (i = 0; i < 16; i++) {
		if (EVENT[i].eventType != 0) {
			eventIDs[count] = i;
			count++;
		}
	}

	return count;
}
