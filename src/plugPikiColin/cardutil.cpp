#include "CardUtil.h"

#include "DebugLog.h"
#include "Dolphin/card.h"
#include "gameflow.h"

CardUtilThread CardThread;
CardUtilControl CardControl;

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

/**
 * @TODO: Documentation
 */
static int DoMount(s32 channel, void* a2)
{
	OSLockMutex(&CardControl.mMutex2);
	CardControl.mDirentCount = 0;
	OSUnlockMutex(&CardControl.mMutex2);
	CardControl.mFilesNotUsed  = 0;
	CardControl.mByteNotUsed   = 0;
	CardControl.mOperationSize = 0xA000;
	s32 res                    = CARDMount(channel, (CARDMemoryCard*)a2, 0);
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
	CardControl.mDirentCount = 0;
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
	CardControl.mDirentCount = 0;
	OSUnlockMutex(&CardControl.mMutex2);
	CardControl.mOperationSize = 0xA000;
	int res                    = CARDFormat(channel);
	if (res == CARD_RESULT_READY) {
		res = CARDFreeBlocks(channel, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
	}
	return res;
}

/**
 * @TODO: Documentation
 */
static int DoErase(s32 chan, s32 fileNo)
{
	CardControl.mOperationSize = 0x4000;
	int resDel                 = CARDFastDelete(chan, fileNo);
	if (resDel >= 0) {

	} else {
		return resDel;
	}

	if (CardControl.mDirentList) {
		u8* card = (u8*)CardControl.mDirentList;
		for (card; card < &((u8*)CardControl.mDirentList)[CardControl.mDirentCount * sizeof(CardUtilDirent)];
		     card += sizeof(CardUtilDirent)) {
			int a = *(int*)(card + 0x5A40);
			if (a != fileNo) {
				continue;
			}

			OSLockMutex(&CardControl.mMutex2);
			memmove(card, card + sizeof(CardUtilDirent),
			        &((u8*)CardControl.mDirentList)[CardControl.mDirentCount * sizeof(CardUtilDirent)] - (card + sizeof(CardUtilDirent)));
			CardControl.mDirentCount--;
			DCStoreRange(card, &((u8*)CardControl.mDirentList)[CardControl.mDirentCount * sizeof(CardUtilDirent)] - card);
			OSUnlockMutex(&CardControl.mMutex2);
		}
	}

	return CARDFreeBlocks(chan, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
}

/**
 * @TODO: Documentation
 */
static int DoList(s32 chan, CardUtilDirent* dirent)
{

	DVDDiskID* diskID = DVDGetCurrentDiskID();
	int res           = CARD_RESULT_READY;
	CardUtilLockDirectory();
	CardControl.mDirentList  = dirent;
	CardControl.mDirentCount = 0;
	CardUtilUnlockDirectory();
	if (!dirent) {
		return CARD_RESULT_READY;
	}

	memset(dirent, 0, 127 * sizeof(CardUtilDirent));

	CARDFileInfo info;
	char buf2[36];
	char buf[36];
	for (int i = 0; i < 127; i++) {
		CardUtilDirent& entry = dirent[CardControl.mDirentCount];
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

		memset(&entry.mFileData[0x5A00], 0, 0x40);
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
			void* dst = &entry.mFileData[0x5A00];
			void* src = &entry.mFileData[OFFSET(entry.mState.commentAddr, 0x200)];
			memmove(dst, src, 0x40);
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

				memmove(&entry, &entry.mFileData[OFFSET(entry.mState.iconAddr, 0x200)], entry.mState.offsetData - entry.mState.iconAddr);

				DCFlushRange(&entry, entry.mState.offsetData - entry.mState.iconAddr);

				entry.mAnimTotalFrames = 0;
				int iconCnt;
				int j;
				int count;
				for (j = 0, count = 0, iconCnt = 0; count < 8; count++, j++) {
					int speed = CARDGetIconSpeed(&entry.mState, count);
					if (speed == CARD_STAT_SPEED_END) {
						break;
					}

					entry.mAnimFrameOffsets[j] = entry.mAnimTotalFrames;
					entry.mAnimIconIndices[j]  = iconCnt;
					entry.mAnimTotalFrames += speed << 2;

					if (CARDGetIconFormat(&entry.mState, iconCnt) != CARD_STAT_ICON_NONE) {
						iconCnt++;
					}
				}

				if (CARDGetIconAnim(&entry.mState) == CARD_STAT_ANIM_BOUNCE && count > 2) {
					for (int k = count - 2; k > 0; k--) {
						int speed                  = CARDGetIconSpeed(&entry.mState, k);
						entry.mAnimFrameOffsets[j] = entry.mAnimTotalFrames;
						entry.mAnimIconIndices[j]  = entry.mAnimIconIndices[k];
						entry.mAnimTotalFrames += speed << 2;
						j++;
					}
				}
			}
		}
		entry.mFileNo = i;
		CardUtilLockDirectory();
		CardControl.mDirentCount++;
		CardUtilUnlockDirectory();
	}

	return res;
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
	CardControl.mOperationSize = state.length;
	int res3                   = CARDRead(&info, addr, state.length, 0);
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

/**
 * @TODO: Documentation
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

	CardControl.mOperationSize = state->length + 0x8000;
	if (fileNo >= 0 && fileNo < 127) {
		CardControl.mOperationSize += 0x4000;
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

	if (!CardControl.mDirentList) {
		return CARDFreeBlocks(chan, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
	}

	OSLockMutex(&CardControl.mMutex2);
	CardUtilDirent* entry;
	if (fileNo == -1) {
		entry = &CardControl.mDirentList[CardControl.mDirentCount];
		CardControl.mDirentCount++;
	} else {
		entry                    = CardControl.mDirentList;
		CardUtilDirent* altEntry = &CardControl.mDirentList[CardControl.mDirentCount];
		for (entry; entry < altEntry; entry++) {
			if (entry->mFileNo == fileNo) {
				break;
			}
		}
		if (entry == altEntry) {
			CardControl.mDirentCount++;
		}
	}

	memset(&entry->mFileData[0x5A00], 0, 0x40);

	if (state->commentAddr <= state->length - 0x40) {
		memmove(&entry->mFileData[0x5A00], (void*)((u32)addr + state->commentAddr), 0x40);
	}

	entry->mAnimTotalFrames = 0;
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

			entry->mAnimFrameOffsets[i] = entry->mAnimTotalFrames;
			entry->mAnimIconIndices[i]  = iconCnt;
			entry->mAnimTotalFrames += speed << 2;

			if (CARDGetIconFormat(state, iconCnt) != CARD_STAT_ICON_NONE) {
				iconCnt++;
			}
		}

		if (CARDGetIconAnim(state) == CARD_STAT_ANIM_BOUNCE && count > 2) {
			for (int j = count - 2; j > 0; j--) {
				int speed                   = CARDGetIconSpeed(state, j);
				entry->mAnimFrameOffsets[i] = entry->mAnimTotalFrames;
				entry->mAnimIconIndices[i]  = entry->mAnimIconIndices[j];
				entry->mAnimTotalFrames += speed << 2;
				i++;
			}
		}
	}

	memcpy(&entry->mState, state, sizeof(CARDStat));
	entry->mFileNo = newFileNo;
	OSUnlockMutex(&CardControl.mMutex2);
	return CARDFreeBlocks(chan, &CardControl.mByteNotUsed, &CardControl.mFilesNotUsed);
}

/**
 * @TODO: Documentation
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
			CardControl.mTransferredBytes = CARDGetXferredBytes(chan);
		}
		res = CARD_RESULT_READY;
		OSSignalCond(&CardControl.mCondition);
	}
	OSUnlockMutex(&CardControl.mMutex);
	return res;
}

/**
 * @TODO: Documentation
 */
int CardUtilResultCode()
{
	return CardControl.mResultCode;
}

/**
 * @TODO: Documentation
 */
void CardUtilMount(s32 channel, void* addr)
{
	CardUtilCommand(channel, CARDCMD_Mount, 0, addr, 0, 0);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
bool CardUtilIsCardBusy()
{
	return CardControl.mChannel != -1;
}

/**
 * @TODO: Documentation
 */
void CardUtilIdleWhileBusy()
{
	while (CardControl.mChannel != -1) {
		OSYieldThread();
	}
}

/**
 * @TODO: Documentation
 */
void CardUtilErase(s32 channel, s32 file)
{
	CardUtilCommand(channel, CARDCMD_Erase, file, nullptr, 0, 0);
}

/**
 * @TODO: Documentation
 */
void CardUtilOpen(s32 channel, s32 file, void* addr)
{
	CardUtilCommand(channel, CARDCMD_Open, file, addr, 0, 0);
}

/**
 * @TODO: Documentation
 */
void CardUtilSave(s32 channel, CARDStat* stat, void* addr)
{
	CardUtilCommand(channel, CARDCMD_Save, (int)stat, addr, 0, 0);
}

/**
 * @TODO: Documentation
 */
void CardUtilWrite(s32 channel, s32 fileNo, void* data, u32 offset, u32 size)
{
	CardUtilCommand(channel, CARDCMD_Write, fileNo, data, offset, size);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void CardUtilInit(void* stack, u32 stackSize, s32 prio)
{
	OSInitMutex(&CardControl.mMutex);
	OSInitMutex(&CardControl.mMutex2);
	OSInitCond(&CardControl.mCondition);
	OSCreateThread(&CardThread.mThread, CardUtilMain, nullptr, stack, stackSize, prio, OS_THREAD_ATTR_DETACH);
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
