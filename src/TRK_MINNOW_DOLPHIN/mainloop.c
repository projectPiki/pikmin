#include "PowerPC_EABI_Support/MetroTRK/trk.h"

extern TRKEventQueue gTRKEventQueue;
extern TRKState gTRKState;

/*
 * --INFO--
 * Address:	8021BF4C
 * Size:	000028
 */
void TRKHandleRequestEvent(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x8(r3)
	  bl        0x68C
	  bl        0xF94
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021BF74
 * Size:	000020
 */
void TRKHandleSupportEvent(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x3A4C
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021BF94
 * Size:	00002C
 */
void TRKIdle(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x3B58
	  cmpwi     r3, 0
	  bne-      .loc_0x1C
	  bl        0x480C

	.loc_0x1C:
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021BFC0
 * Size:	0000F4
 */
void TRKNubMainLoop(void)
{
	void* msg;
	TRKEvent event;
	BOOL isShutdownRequested;
	BOOL isNewInput;

	isShutdownRequested = FALSE;
	isNewInput          = FALSE;
	while (isShutdownRequested == FALSE) {
		if (TRKGetNextEvent(&event) != FALSE) {
			isNewInput = FALSE;

			switch (event.eventType) {
			case NUBEVENT_Null:
				break;

			case NUBEVENT_Request:
				msg = TRKGetBuffer(event.msgBufID);
				TRKDispatchMessage(msg);
				break;

			case NUBEVENT_Shutdown:
				isShutdownRequested = TRUE;
				break;

			case NUBEVENT_Breakpoint:
			case NUBEVENT_Exception:
				TRKTargetInterrupt(&event);
				break;

			case NUBEVENT_Support:
				TRKTargetSupportRequest();
				break;
			}

			TRKDestructEvent(&event);
			continue;
		}

		if ((isNewInput == FALSE) || (*(u8*)gTRKInputPendingPtr != '\0')) {
			isNewInput = TRUE;
			TRKGetInput();
			continue;
		}

		if (TRKTargetStopped() == FALSE) {
			TRKTargetContinue();
		}
		isNewInput = FALSE;
	}
}
