#include "CardUtil.h"

#include "Dolphin/card.h"
#include "gameflow.h"
#include "DebugLog.h"

CardUtilThread CardThread;
CardUtilControl CardControl;

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
DEFINE_PRINT("CardUtil")

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void CardUtilNumFiles()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void CardUtilLockDirectory()
{
	OSLockMutex(&CardControl.mMutex2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void CardUtilUnlockDirectory()
{
	OSUnlockMutex(&CardControl.mMutex2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
s32 CardUtilByteNotUsed()
{
	return CardControl.mByteNotUsed;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
s32 CardUtilBlocksNotUsed()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
s32 CardUtilFilesNotUsed()
{
	return CardControl.mFilesNotUsed;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
s32 CardUtilSectorSize()
{
	return CardControl.mSectorSize;
}

/*
 * --INFO--
 * Address:	8004C93C
 * Size:	000104
 */
static int DoMount(s32 channel, void* a2)
{
	OSLockMutex(&CardControl.mMutex2);
	CardControl._6C = 0;
	OSUnlockMutex(&CardControl.mMutex2);
	CardControl.mFilesNotUsed = 0;
	CardControl.mByteNotUsed  = 0;
	CardControl._4C           = 0xA000;
	s32 res                   = CARDMount(channel, (CARDMemoryCard*)a2, 0);
	switch (res) {
	case CARD_RESULT_READY:
	case CARD_RESULT_BROKEN:
		int res2 = CARDGetSectorSize(channel, &CardControl.mSectorSize);
		if (res2 >= 0) {
		} else {
			return res2;
		}
		res = CARDCheck(channel);
		break;

	case CARD_RESULT_ENCODING:
		int res3 = CARDGetSectorSize(channel, &CardControl.mSectorSize);
		if (res3 >= 0) {
		} else {
			return res3;
		}
		break;
	}

	if (res == CARD_RESULT_READY) {
		res = CARDFreeBlocks(channel, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
	}
	return res;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
static int DoUnmount(s32 channel)
{
	OSLockMutex(&CardControl.mMutex2);
	CardControl._6C = 0;
	OSUnlockMutex(&CardControl.mMutex2);
	return CARDUnmount(channel);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
static int DoFormat(s32 channel)
{
	OSLockMutex(&CardControl.mMutex2);
	CardControl._6C = 0;
	OSUnlockMutex(&CardControl.mMutex2);
	CardControl._4C = 0xA000;
	int res         = CARDFormat(channel);
	if (res == CARD_RESULT_READY) {
		res = CARDFreeBlocks(channel, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
	}
	return res;
}

/*
 * --INFO--
 * Address:	8004CA40
 * Size:	0000FC
 */
static int DoErase(s32 chan, s32 fileNo)
{
	CardControl._4C = 0x4000;
	int resDel      = CARDFastDelete(chan, fileNo);
	if (resDel >= 0) {

	} else {
		return resDel;
	}

	if (CardControl._68) {
		u8* card = (u8*)CardControl._68;
		for (card; card < &((u8*)CardControl._68)[CardControl._6C * 0x5B40]; card += 0x5B40) {
			int a = *(int*)(card + 0x5A40);
			if (a != fileNo) {
				continue;
			}

			OSLockMutex(&CardControl.mMutex2);
			memmove(card, card + 0x5B40, &((u8*)CardControl._68)[CardControl._6C * 0x5B40] - (card + 0x5B40));
			CardControl._6C--;
			DCStoreRange(card, &((u8*)CardControl._68)[CardControl._6C * 0x5B40] - card);
			OSUnlockMutex(&CardControl.mMutex2);
		}
	}

	return CARDFreeBlocks(chan, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
}

/*
 * --INFO--
 * Address:	8004CB3C
 * Size:	0005CC
 */
static int DoList(s32 chan, CardUtilDirent* dirent)
{

	DVDDiskID* diskID = DVDGetCurrentDiskID();
	int res           = CARD_RESULT_READY;
	CardUtilLockDirectory();
	CardControl._68 = dirent;
	CardControl._6C = 0;
	CardUtilUnlockDirectory();
	if (!dirent) {
		return CARD_RESULT_READY;
	}

	memset(dirent, 0, 127 * sizeof(CardUtilDirent));

	CARDFileInfo info;
	char buf2[36];
	char buf[36];
	for (int i = 0; i < 127; i++) {
		CardUtilDirent& entry = dirent[CardControl._6C];
		if (CARDGetStatus(chan, i, &entry.mState) < 0) {
			continue;
		}

		if (memcmp(entry.mState.gameName, diskID->gameName, 4) != 0) {
			continue;
		}

		if (memcmp(entry.mState.company, diskID->company, 2) != 0) {
			continue;
		}

		if (entry.mState.fileName[0] == '~') {
			strncpy(buf, entry.mState.fileName, CARD_FILENAME_MAX);
			buf[CARD_FILENAME_MAX] = 0;
			strncpy(buf2, &buf[1], CARD_FILENAME_MAX);
			buf2[CARD_FILENAME_MAX] = 0;

			if (entry.mState.commentAddr <= entry.mState.length - 0x40) {
				if (CARDRename(chan, buf, buf2) == 0) {
					// renamed! redo this entry with the new name
					i--;
					continue;
				}
			}

			res = CARDFastDelete(chan, i);
			if (res >= 0) {
				res = CARDFreeBlocks(chan, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
				if (res >= 0) {
					continue;
				}
			}
			return res;
		}

		memset(&entry._00[0x5A00], 0, 0x40);
		if (entry.mState.commentAddr <= entry.mState.length - 0x40) {
			res = CARDFastOpen(chan, i, &info);
			if (res >= 0) {

			} else {
				return res;
			}

			s32 offset = TRUNC(entry.mState.commentAddr, 0x200);
			s32 addr   = entry.mState.commentAddr + 0x40;
			res        = CARDRead(&info, &entry, ALIGN_NEXT(addr - offset, 0x200), offset);
			CARDClose(&info);
			if (res < 0) {
				return res;
			}
			memmove(&entry._00[0x5A00], &entry._00[OFFSET(entry.mState.commentAddr, 0x200)], 0x40);
		}

		if (entry.mState.bannerFormat || entry.mState.iconFormat) {
			if (entry.mState.offsetData <= entry.mState.length && entry.mState.iconAddr < entry.mState.offsetData) {
				int resOpen = CARDFastOpen(chan, i, &info);
				if (resOpen >= 0) {

				} else {
					return resOpen;
				}

				s32 offset = TRUNC(entry.mState.iconAddr, 0x200);
				res        = CARDRead(&info, &entry, ALIGN_NEXT(entry.mState.offsetData - offset, 0x200), offset);
				CARDClose(&info);
				if (res < 0) {
					return res;
				}

				memmove(&entry, &entry._00[OFFSET(entry.mState.iconAddr, 0x200)], entry.mState.offsetData - entry.mState.iconAddr);

				DCFlushRange(&entry, entry.mState.offsetData - entry.mState.iconAddr);

				entry._5AB0 = 0;
				int iconCnt;
				int j;
				int count;
				for (j = 0, count = 0, iconCnt = 0; count < 8; count++, j++) {
					int speed = CARDGetIconSpeed(&entry.mState, count);
					if (speed == CARD_STAT_SPEED_END) {
						break;
					}

					entry._5AB4[j] = entry._5AB0;
					entry._5AEC[j] = iconCnt;
					entry._5AB0 += speed << 2;

					if (CARDGetIconFormat(&entry.mState, iconCnt) != CARD_STAT_ICON_NONE) {
						iconCnt++;
					}
				}

				if (CARDGetIconAnim(&entry.mState) == CARD_STAT_ANIM_BOUNCE && count > 2) {
					for (int k = count - 2; k > 0; k--) {
						int speed      = CARDGetIconSpeed(&entry.mState, k);
						entry._5AB4[j] = entry._5AB0;
						entry._5AEC[j] = entry._5AEC[k];
						entry._5AB0 += speed << 2;
						j++;
					}
				}
			}
		}
		entry.mFileNo = i;
		CardUtilLockDirectory();
		CardControl._6C++;
		CardUtilUnlockDirectory();
	}

	return res;
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stmw      r20, 0x70(r1)
	  addi      r31, r3, 0
	  addi      r25, r4, 0
	  subi      r20, r5, 0x2BC8
	  bl        0x1B51A0
	  addi      r28, r20, 0x360
	  addi      r26, r3, 0
	  addi      r3, r28, 0
	  li        r21, 0
	  bl        0x1ACE80
	  stw       r25, 0x378(r20)
	  addi      r30, r20, 0x37C
	  addi      r3, r28, 0
	  stw       r21, 0x37C(r20)
	  bl        0x1ACF48
	  cmplwi    r25, 0
	  bne-      .loc_0x5C
	  li        r3, 0
	  b         .loc_0x5B8

	.loc_0x5C:
	  lis       r4, 0x2D
	  addi      r3, r25, 0
	  addi      r5, r4, 0x44C0
	  li        r4, 0
	  bl        -0x49888
	  addi      r22, r1, 0x11
	  addi      r23, r20, 0x350
	  addi      r24, r20, 0x34C
	  li        r29, 0
	  b         .loc_0x5AC

	.loc_0x84:
	  lwz       r0, 0x0(r30)
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  mulli     r0, r0, 0x5B40
	  add       r27, r25, r0
	  addi      r5, r27, 0x5A44
	  bl        0x1C0298
	  cmpwi     r3, 0
	  blt-      .loc_0x5A8
	  addi      r4, r26, 0
	  addi      r3, r27, 0x5A6C
	  li        r5, 0x4
	  bl        0x1C957C
	  cmpwi     r3, 0
	  bne-      .loc_0x5A8
	  addi      r3, r27, 0x5A70
	  addi      r4, r26, 0x4
	  li        r5, 0x2
	  bl        0x1C9564
	  cmpwi     r3, 0
	  bne-      .loc_0x5A8
	  lbz       r0, 0x5A44(r27)
	  cmplwi    r0, 0x7E
	  bne-      .loc_0x178
	  addi      r3, r1, 0x10
	  addi      r4, r27, 0x5A44
	  li        r5, 0x20
	  bl        0x1CC6E8
	  li        r20, 0
	  stb       r20, 0x30(r1)
	  addi      r4, r22, 0
	  addi      r3, r1, 0x34
	  li        r5, 0x20
	  bl        0x1CC6D0
	  stb       r20, 0x54(r1)
	  lwz       r3, 0x5A64(r27)
	  lwz       r4, 0x5A7C(r27)
	  subi      r0, r3, 0x40
	  cmplw     r4, r0
	  bgt-      .loc_0x144
	  addi      r3, r31, 0
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x34
	  bl        0x1C06D4
	  cmpwi     r3, 0
	  bne-      .loc_0x144
	  subi      r29, r29, 0x1
	  b         .loc_0x5A8

	.loc_0x144:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        0x1BFFA8
	  mr.       r21, r3
	  blt-      .loc_0x170
	  addi      r3, r31, 0
	  addi      r4, r24, 0
	  addi      r5, r23, 0
	  bl        0x1BC300
	  mr.       r21, r3
	  bge-      .loc_0x5A8

	.loc_0x170:
	  mr        r3, r21
	  b         .loc_0x5B8

	.loc_0x178:
	  addi      r3, r27, 0x5A00
	  li        r4, 0
	  li        r5, 0x40
	  bl        -0x499A0
	  lwz       r3, 0x5A64(r27)
	  lwz       r4, 0x5A7C(r27)
	  subi      r0, r3, 0x40
	  cmplw     r4, r0
	  bgt-      .loc_0x210
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r1, 0x58
	  bl        0x1BEEC0
	  cmpwi     r3, 0
	  bge-      .loc_0x1B8
	  b         .loc_0x5B8

	.loc_0x1B8:
	  lwz       r5, 0x5A7C(r27)
	  addi      r4, r27, 0
	  addi      r3, r1, 0x58
	  rlwinm    r6,r5,0,0,22
	  addi      r0, r5, 0x40
	  sub       r5, r0, r6
	  addi      r0, r5, 0x1FF
	  rlwinm    r5,r0,0,0,22
	  bl        0x1BF990
	  addi      r21, r3, 0
	  addi      r3, r1, 0x58
	  bl        0x1BF16C
	  cmpwi     r21, 0
	  bge-      .loc_0x1F8
	  mr        r3, r21
	  b         .loc_0x5B8

	.loc_0x1F8:
	  lwz       r0, 0x5A7C(r27)
	  addi      r3, r27, 0x5A00
	  li        r5, 0x40
	  rlwinm    r0,r0,0,23,31
	  add       r4, r27, r0
	  bl        0x1C9494

	.loc_0x210:
	  lbz       r0, 0x5A72(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x228
	  lhz       r0, 0x5A78(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x588

	.loc_0x228:
	  lwz       r3, 0x5AAC(r27)
	  lwz       r0, 0x5A64(r27)
	  cmplw     r3, r0
	  bgt-      .loc_0x588
	  lwz       r0, 0x5A74(r27)
	  cmplw     r0, r3
	  bge-      .loc_0x588
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r1, 0x58
	  bl        0x1BEE18
	  cmpwi     r3, 0
	  bge-      .loc_0x260
	  b         .loc_0x5B8

	.loc_0x260:
	  lwz       r5, 0x5A74(r27)
	  mr        r4, r27
	  lwz       r0, 0x5AAC(r27)
	  addi      r3, r1, 0x58
	  rlwinm    r6,r5,0,0,22
	  sub       r5, r0, r6
	  addi      r0, r5, 0x1FF
	  rlwinm    r5,r0,0,0,22
	  bl        0x1BF8E8
	  addi      r21, r3, 0
	  addi      r3, r1, 0x58
	  bl        0x1BF0C4
	  cmpwi     r21, 0
	  bge-      .loc_0x2A0
	  mr        r3, r21
	  b         .loc_0x5B8

	.loc_0x2A0:
	  lwz       r5, 0x5A74(r27)
	  mr        r3, r27
	  lwz       r0, 0x5AAC(r27)
	  rlwinm    r4,r5,0,23,31
	  add       r4, r27, r4
	  sub       r5, r0, r5
	  bl        0x1C93E8
	  lwz       r4, 0x5A74(r27)
	  mr        r3, r27
	  lwz       r0, 0x5AAC(r27)
	  sub       r4, r0, r4
	  bl        0x1A9DE0
	  li        r7, 0
	  li        r0, 0x2
	  stw       r7, 0x5AB0(r27)
	  mtctr     r0
	  addi      r8, r27, 0
	  addi      r9, r7, 0
	  li        r4, 0
	  li        r5, 0
	  li        r3, 0

	.loc_0x2F4:
	  lhz       r0, 0x5A7A(r27)
	  sraw      r0, r0, r7
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x448
	  lwz       r6, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r6, 0x5AB4(r8)
	  stw       r3, 0x5AEC(r8)
	  lwz       r6, 0x5AB0(r27)
	  add       r0, r6, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x5A78(r27)
	  sraw      r0, r0, r9
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x338
	  addi      r9, r9, 0x2
	  addi      r3, r3, 0x1

	.loc_0x338:
	  lhz       r0, 0x5A7A(r27)
	  addi      r7, r7, 0x2
	  addi      r8, r8, 0x4
	  sraw      r0, r0, r7
	  rlwinm.   r0,r0,0,30,31
	  addi      r4, r4, 0x1
	  addi      r5, r5, 0x1
	  beq-      .loc_0x448
	  lwz       r6, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r6, 0x5AB4(r8)
	  stw       r3, 0x5AEC(r8)
	  lwz       r6, 0x5AB0(r27)
	  add       r0, r6, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x5A78(r27)
	  sraw      r0, r0, r9
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x38C
	  addi      r9, r9, 0x2
	  addi      r3, r3, 0x1

	.loc_0x38C:
	  lhz       r0, 0x5A7A(r27)
	  addi      r7, r7, 0x2
	  addi      r8, r8, 0x4
	  sraw      r0, r0, r7
	  rlwinm.   r0,r0,0,30,31
	  addi      r4, r4, 0x1
	  addi      r5, r5, 0x1
	  beq-      .loc_0x448
	  lwz       r6, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r6, 0x5AB4(r8)
	  stw       r3, 0x5AEC(r8)
	  lwz       r6, 0x5AB0(r27)
	  add       r0, r6, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x5A78(r27)
	  sraw      r0, r0, r9
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x3E0
	  addi      r9, r9, 0x2
	  addi      r3, r3, 0x1

	.loc_0x3E0:
	  lhz       r0, 0x5A7A(r27)
	  addi      r7, r7, 0x2
	  addi      r8, r8, 0x4
	  sraw      r0, r0, r7
	  rlwinm.   r0,r0,0,30,31
	  addi      r4, r4, 0x1
	  addi      r5, r5, 0x1
	  beq-      .loc_0x448
	  lwz       r6, 0x5AB0(r27)
	  rlwinm    r0,r0,2,0,29
	  stw       r6, 0x5AB4(r8)
	  stw       r3, 0x5AEC(r8)
	  lwz       r6, 0x5AB0(r27)
	  add       r0, r6, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r0, 0x5A78(r27)
	  sraw      r0, r0, r9
	  rlwinm.   r0,r0,0,30,31
	  beq-      .loc_0x434
	  addi      r9, r9, 0x2
	  addi      r3, r3, 0x1

	.loc_0x434:
	  addi      r7, r7, 0x2
	  addi      r5, r5, 0x1
	  addi      r8, r8, 0x4
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x2F4

	.loc_0x448:
	  lbz       r0, 0x5A72(r27)
	  rlwinm    r0,r0,0,29,29
	  cmpwi     r0, 0x4
	  bne-      .loc_0x588
	  cmpwi     r5, 0x2
	  ble-      .loc_0x588
	  subic.    r3, r5, 0x2
	  rlwinm    r4,r4,2,0,29
	  add       r6, r27, r4
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r5,r3,1,0,30
	  add       r7, r27, r0
	  ble-      .loc_0x588
	  rlwinm.   r0,r3,30,2,31
	  mtctr     r0
	  beq-      .loc_0x54C

	.loc_0x488:
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AB4(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AEC(r7)
	  stw       r4, 0x5AEC(r6)
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AB8(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AE8(r7)
	  stw       r4, 0x5AF0(r6)
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5ABC(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AE4(r7)
	  stw       r4, 0x5AF4(r6)
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AC0(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AE0(r7)
	  subi      r7, r7, 0x10
	  stw       r4, 0x5AF8(r6)
	  addi      r6, r6, 0x10
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  bdnz+     .loc_0x488
	  andi.     r3, r3, 0x3
	  beq-      .loc_0x588

	.loc_0x54C:
	  mtctr     r3

	.loc_0x550:
	  lhz       r4, 0x5A7A(r27)
	  lwz       r0, 0x5AB0(r27)
	  sraw      r4, r4, r5
	  stw       r0, 0x5AB4(r6)
	  rlwinm    r0,r4,2,28,29
	  subi      r5, r5, 0x2
	  lwz       r4, 0x5AEC(r7)
	  subi      r7, r7, 0x4
	  stw       r4, 0x5AEC(r6)
	  addi      r6, r6, 0x4
	  lwz       r4, 0x5AB0(r27)
	  add       r0, r4, r0
	  stw       r0, 0x5AB0(r27)
	  bdnz+     .loc_0x550

	.loc_0x588:
	  stw       r29, 0x5A40(r27)
	  mr        r3, r28
	  bl        0x1AC924
	  lwz       r4, 0x0(r30)
	  addi      r3, r28, 0
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r30)
	  bl        0x1AC9EC

	.loc_0x5A8:
	  addi      r29, r29, 0x1

	.loc_0x5AC:
	  cmpwi     r29, 0x7F
	  blt+      .loc_0x84
	  mr        r3, r21

	.loc_0x5B8:
	  lmw       r20, 0x70(r1)
	  lwz       r0, 0xA4(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
static int DoOpen(s32 chan, s32 fileNo, void* addr)
{
	CARDStat state;
	CARDFileInfo info;
	int res1 = CARDGetStatus(chan, fileNo, &state);
	if (res1 >= 0) {
	} else {
		return res1;
	}
	int res2 = CARDFastOpen(chan, fileNo, &info);
	if (res2 >= 0) {
	} else {
		return res2;
	}
	CardControl._4C = state.length;
	int res3        = CARDRead(&info, addr, state.length, 0);
	CARDClose(&info);
	return res3;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
static int DoWrite(s32 chan, s32 fileNo, void* addr, u32 length, u32 offset)
{
	CARDStat state;
	CARDFileInfo info;
	int res1 = CARDGetStatus(chan, fileNo, &state);
	if (res1 >= 0) {
	} else {
		return res1;
	}
	int res2 = CARDFastOpen(chan, fileNo, &info);
	if (res2 >= 0) {
	} else {
		return res2;
	}
	int res3 = CARDWrite(&info, addr, length, offset);
	CARDClose(&info);
	return res3;
}

/*
 * --INFO--
 * Address:	8004D108
 * Size:	0005AC
 */
static int DoSave(s32 chan, CARDStat* state, void* addr)
{
	CARDFileInfo info;
	char buf[36];
	strncpy(buf, state->fileName, CARD_FILENAME_MAX);
	buf[CARD_FILENAME_MAX] = 0;
	if (strlen(buf) >= CARD_FILENAME_MAX) {
		return CARD_RESULT_NAMETOOLONG;
	}

	if (buf[0] == '~') {
		// dramatic
		return CARD_RESULT_FATAL_ERROR;
	}

	char buf2[36];
	buf2[0] = '~';
	strncpy(&buf2[1], state->fileName, CARD_FILENAME_MAX - 1);
	buf2[CARD_FILENAME_MAX] = 0;

	int newFileNo;
	int fileNo = -1;
	if (CARDOpen(chan, buf, &info) == CARD_RESULT_READY) {
		fileNo = info.fileNo;
		CARDClose(&info);
	}

	CardControl._4C = state->length + 0x8000;
	if (fileNo >= 0 && fileNo < 127) {
		CardControl._4C += 0x4000;
	}

	int resCreate = CARDCreate(chan, buf2, state->length, &info);
	if (resCreate >= 0) {

	} else {
		return resCreate;
	}

	newFileNo    = info.fileNo;
	int resWrite = CARDWrite(&info, addr, state->length, 0);
	CARDClose(&info);
	if (resWrite < 0 || (resWrite = CARDSetStatus(chan, newFileNo, state)) < 0) {
		return resWrite;
	}

	if (fileNo >= 0 && fileNo < 127) {
		int resDel = CARDFastDelete(chan, fileNo);
		if (resDel >= 0) {

		} else {
			return resDel;
		}
	}
	int resRename = CARDRename(chan, buf2, buf);
	if (resRename >= 0) {

	} else {
		return resRename;
	}

	if (!CardControl._68) {
		return CARDFreeBlocks(chan, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
	}

	OSLockMutex(&CardControl.mMutex2);
	CardUtilDirent* entry;
	if (fileNo == -1) {
		entry = &CardControl._68[CardControl._6C];
		CardControl._6C++;
	} else {
		entry                    = CardControl._68;
		CardUtilDirent* altEntry = &CardControl._68[CardControl._6C];
		for (entry; entry < altEntry; entry++) {
			if (entry->mFileNo == fileNo) {
				break;
			}
		}
		if (entry == altEntry) {
			CardControl._6C++;
		}
	}

	memset(&entry->_00[0x5A00], 0, 0x40);

	if (state->commentAddr <= state->length - 0x40) {
		memmove(&entry->_00[0x5A00], (void*)((u32)addr + state->commentAddr), 0x40);
	}

	entry->_5AB0 = 0;
	if (state->bannerFormat || state->iconFormat) {
		memmove(entry, (void*)((u32)addr + state->iconAddr), state->offsetData - state->iconAddr);
		DCFlushRange(entry, state->offsetData - state->iconAddr);

		int iconCnt;
		int i;
		int count;
		for (i = 0, count = 0, iconCnt = 0; count < 8; count++, i++) {
			int speed = CARDGetIconSpeed(state, count);
			if (speed == CARD_STAT_SPEED_END) {
				break;
			}

			entry->_5AB4[i] = entry->_5AB0;
			entry->_5AEC[i] = iconCnt;
			entry->_5AB0 += speed << 2;

			if (CARDGetIconFormat(state, iconCnt) != CARD_STAT_ICON_NONE) {
				iconCnt++;
			}
		}

		if (CARDGetIconAnim(state) == CARD_STAT_ANIM_BOUNCE && count > 2) {
			for (int j = count - 2; j > 0; j--) {
				int speed       = CARDGetIconSpeed(state, j);
				entry->_5AB4[i] = entry->_5AB0;
				entry->_5AEC[i] = entry->_5AEC[j];
				entry->_5AB0 += speed << 2;
				i++;
			}
		}
	}

	memcpy(&entry->mState, state, sizeof(CARDStat));
	entry->mFileNo = newFileNo;
	OSUnlockMutex(&CardControl.mMutex2);
	return CARDFreeBlocks(chan, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
}

/*
 * --INFO--
 * Address:	8004D6B4
 * Size:	0000B0
 */
static int CardUtilCommand(s32 chan, s32 command, s32 file, void* addr, u32 offset, u32 length)
{
	OSLockMutex(&CardControl.mMutex);
	int res;
	if (CardControl.mChannel != -1) {
		res = CardControl.mResultCode;
	} else {

		CardControl.mChannel    = CardControl.mChannel;
		CardControl.mChannel    = chan;
		CardControl.mCommand    = command;
		CardControl.mFileNo     = file;
		CardControl.mAddr       = addr;
		CardControl.mOffset     = offset;
		CardControl.mLength     = length;
		CardControl.mResultCode = CARD_RESULT_BUSY;

		if (command != CARDCMD_List) {
			CardControl._48 = CARDGetXferredBytes(chan);
		}
		res = CARD_RESULT_READY;
		OSSignalCond(&CardControl.mCondition);
	}
	OSUnlockMutex(&CardControl.mMutex);
	return res;
}

/*
 * --INFO--
 * Address:	8004D764
 * Size:	000010
 */
int CardUtilResultCode()
{
	return CardControl.mResultCode;
}

/*
 * --INFO--
 * Address:	8004D774
 * Size:	000034
 */
void CardUtilMount(s32 channel, void* addr)
{
	CardUtilCommand(channel, CARDCMD_Mount, 0, addr, 0, 0);
}

/*
 * --INFO--
 * Address:	8004D7A8
 * Size:	000034
 */
void CardUtilUnmount(s32 channel)
{
	CardUtilCommand(channel, CARDCMD_Unmount, 0, nullptr, 0, 0);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void CardUtilList(s32, CardUtilDirent*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void CardUtilFormat(s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8004D7DC
 * Size:	00001C
 */
bool CardUtilIsCardBusy()
{
	return CardControl.mChannel != -1;
}

/*
 * --INFO--
 * Address:	8004D7F8
 * Size:	000040
 */
void CardUtilIdleWhileBusy()
{
	while (CardControl.mChannel != -1) {
		OSYieldThread();
	}
}

/*
 * --INFO--
 * Address:	8004D838
 * Size:	000034
 */
void CardUtilErase(s32 channel, s32 file)
{
	CardUtilCommand(channel, CARDCMD_Erase, file, nullptr, 0, 0);
}

/*
 * --INFO--
 * Address:	8004D86C
 * Size:	000034
 */
void CardUtilOpen(s32 channel, s32 file, void* addr)
{
	CardUtilCommand(channel, CARDCMD_Open, file, addr, 0, 0);
}

/*
 * --INFO--
 * Address:	8004D8A0
 * Size:	000034
 */
void CardUtilSave(s32 channel, CARDStat* stat, void* addr)
{
	CardUtilCommand(channel, CARDCMD_Save, (int)stat, addr, 0, 0);
}

/*
 * --INFO--
 * Address:	8004D8D4
 * Size:	00003C
 */
void CardUtilWrite(s32 channel, s32 fileNo, void* data, u32 offset, u32 size)
{
	CardUtilCommand(channel, CARDCMD_Write, fileNo, data, offset, size);
}

/*
 * --INFO--
 * Address:	8004D910
 * Size:	00025C
 */
static void* CardUtilMain(void*)
{
	s32 res;
	s32 length;
	s32 cmd;
	s32 chan;
	u32 offset;
	s32 fileNo;
	void* addr;
	while (true) {
		OSLockMutex(&CardControl.mMutex);
		while (CardControl.mChannel == -1) {
			OSWaitCond(&CardControl.mCondition, &CardControl.mMutex);
		}

		cmd    = CardControl.mCommand;
		chan   = CardControl.mChannel;
		fileNo = CardControl.mFileNo;
		addr   = CardControl.mAddr;
		offset = CardControl.mOffset;
		length = CardControl.mLength;
		OSUnlockMutex(&CardControl.mMutex);

		switch (cmd) {
		case CARDCMD_Mount:
			res = DoMount(chan, (void*)addr);
			break;

		case CARDCMD_Unmount:
			res = DoUnmount(chan);
			break;

		case CARDCMD_Format:
			res = DoFormat(chan);
			break;

		case CARDCMD_List:
			res = DoList(chan, (CardUtilDirent*)addr);
			break;

		case CARDCMD_Erase:
			res = DoErase(chan, fileNo);
			break;

		case CARDCMD_Open:
			res = DoOpen(chan, fileNo, (void*)addr);
			break;

		case CARDCMD_Save:
			res = DoSave(chan, (CARDStat*)fileNo, (void*)addr);
			break;

		case CARDCMD_Write:
			u32 v = length;
			res   = DoWrite(chan, fileNo, (void*)addr, (u32)v, offset);
			break;
		}

		OSLockMutex(&CardControl.mMutex);
		if (res == CARD_RESULT_IOERROR) {
			gameflow.mMemoryCard.mDidSaveFail = true;
		}
		CardControl.mResultCode = res;
		CardControl.mChannel    = -1;
		OSUnlockMutex(&CardControl.mMutex);
		STACK_PAD_TERNARY(CardControl.mChannel, 1);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  lis       r4, 0x1
	  lis       r5, 0x802A
	  stwu      r1, -0x158(r1)
	  stmw      r16, 0x118(r1)
	  subi      r31, r3, 0x2BC8
	  lis       r3, 0x803A
	  addi      r29, r31, 0x328
	  addi      r28, r31, 0x360
	  addi      r26, r31, 0x350
	  addi      r27, r31, 0x34C
	  addi      r30, r31, 0x330
	  subi      r24, r4, 0x6000
	  addi      r25, r5, 0x5EB0
	  subi      r18, r3, 0x2848

	.loc_0x44:
	  addi      r3, r31, 0x310
	  bl        0x1AC098
	  b         .loc_0x5C

	.loc_0x50:
	  addi      r3, r29, 0
	  addi      r4, r31, 0x310
	  bl        0x1AC2BC

	.loc_0x5C:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, -0x1
	  beq+      .loc_0x50
	  lwz       r16, 0x334(r31)
	  mr        r23, r0
	  lwz       r19, 0x338(r31)
	  addi      r3, r31, 0x310
	  lwz       r22, 0x33C(r31)
	  lwz       r21, 0x340(r31)
	  lwz       r17, 0x344(r31)
	  bl        0x1AC138
	  cmplwi    r16, 0x9
	  bgt-      .loc_0x22C
	  rlwinm    r0,r16,2,0,29
	  lwzx      r0, r25, r0
	  mtctr     r0
	  bctr
	  addi      r3, r23, 0
	  addi      r4, r22, 0
	  bl        -0x107C
	  mr        r20, r3
	  b         .loc_0x22C
	  mr        r3, r28
	  bl        0x1AC028
	  li        r0, 0
	  stw       r0, 0x37C(r31)
	  mr        r3, r28
	  bl        0x1AC0F4
	  mr        r3, r23
	  bl        0x1BD810
	  mr        r20, r3
	  b         .loc_0x22C
	  mr        r3, r28
	  bl        0x1AC000
	  li        r0, 0
	  stw       r0, 0x37C(r31)
	  mr        r3, r28
	  bl        0x1AC0CC
	  stw       r24, 0x35C(r31)
	  mr        r3, r23
	  bl        0x1BE02C
	  cmpwi     r3, 0
	  bne-      .loc_0x118
	  addi      r3, r23, 0
	  addi      r4, r27, 0
	  addi      r5, r26, 0
	  bl        0x1BB57C

	.loc_0x118:
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r3, r23, 0
	  addi      r4, r22, 0
	  bl        -0xEFC
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  bl        -0x100C
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r1, 0x94
	  bl        0x1BF40C
	  cmpwi     r3, 0
	  bge-      .loc_0x164
	  b         .loc_0x1A8

	.loc_0x164:
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r1, 0x100
	  bl        0x1BE124
	  cmpwi     r3, 0
	  bge-      .loc_0x180
	  b         .loc_0x1A8

	.loc_0x180:
	  lwz       r5, 0xB4(r1)
	  addi      r4, r22, 0
	  addi      r3, r1, 0x100
	  stw       r5, 0x35C(r31)
	  li        r6, 0
	  bl        0x1BEC00
	  addi      r17, r3, 0
	  addi      r3, r1, 0x100
	  bl        0x1BE3DC
	  mr        r3, r17

	.loc_0x1A8:
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r22, 0
	  bl        -0x9C4
	  mr        r20, r3
	  b         .loc_0x22C
	  addi      r20, r17, 0
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r1, 0x14
	  bl        0x1BF388
	  cmpwi     r3, 0
	  bge-      .loc_0x1E8
	  b         .loc_0x228

	.loc_0x1E8:
	  addi      r3, r23, 0
	  addi      r4, r19, 0
	  addi      r5, r1, 0x80
	  bl        0x1BE0A0
	  cmpwi     r3, 0
	  bge-      .loc_0x204
	  b         .loc_0x228

	.loc_0x204:
	  addi      r4, r22, 0
	  addi      r5, r20, 0
	  addi      r6, r21, 0
	  addi      r3, r1, 0x80
	  bl        0x1BEEF8
	  addi      r17, r3, 0
	  addi      r3, r1, 0x80
	  bl        0x1BE35C
	  mr        r3, r17

	.loc_0x228:
	  mr        r20, r3

	.loc_0x22C:
	  addi      r3, r31, 0x310
	  bl        0x1ABEB0
	  cmpwi     r20, -0x5
	  bne-      .loc_0x244
	  li        r0, 0x1
	  stb       r0, 0x8C(r18)

	.loc_0x244:
	  stw       r20, 0x348(r31)
	  li        r0, -0x1
	  addi      r3, r31, 0x310
	  stw       r0, 0x0(r30)
	  bl        0x1ABF68
	  b         .loc_0x44
	*/
}

/*
 * --INFO--
 * Address:	8004DB6C
 * Size:	000094
 */
void CardUtilInit(void* stack, u32 stackSize, s32 prio)
{
	OSInitMutex(&CardControl.mMutex);
	OSInitMutex(&CardControl.mMutex2);
	OSInitCond(&CardControl.mCondition);
	OSCreateThread(&CardThread.mThread, CardUtilMain, nullptr, stack, stackSize, prio, 1);
	OSResumeThread(&CardThread.mThread);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000238
 */
void CardUtilDrawIcon(int, int, int, void*, void*, u16, u16, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000168
 */
void CardUtilDrawAnimatedIcon(CardUtilDirent*, int, int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void CardUtilGetProgress(s32)
{
	// UNUSED FUNCTION
}
