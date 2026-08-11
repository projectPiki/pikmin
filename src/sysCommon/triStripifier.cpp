#include "triStripifier.h"

#include "DebugLog.h"
#include "sysNew.h"

#include <Dolphin/GX/GXEnum.h>

DEFINE_ERROR(__LINE__)
DEFINE_PRINT("TriStripifier")

/**
 * @todo Documentation
 */
void TriStripifier::findStrips()
{
	for (int infoA = 0; infoA < mInfos.num; ++infoA) {
		for (int vertA = 0; vertA < 3; ++vertA) {
			for (int infoB = 0; infoB < mInfos.num; ++infoB) {
				if (infoA != infoB) {
					for (int vertB = 0; vertB < 3; ++vertB) {
						if (mInfos[infoA]->mVertices[(vertA) % 3] == mInfos[infoB]->mVertices[(vertB) % 3]
						    && mInfos[infoA]->mVertices[(vertA + 1) % 3] == mInfos[infoB]->mVertices[(vertB + 1) % 3]) {
							mInfos[infoA]->mLinks.AddUnique(new TriLink(mInfos[infoA], mInfos[infoB], vertA));
							break;
						}
						if (mInfos[infoA]->mVertices[(vertA) % 3] == mInfos[infoB]->mVertices[(vertB + 1) % 3]
						    && mInfos[infoA]->mVertices[(vertA + 1) % 3] == mInfos[infoB]->mVertices[(vertB) % 3]) {
							mInfos[infoA]->mLinks.AddUnique(new TriLink(mInfos[infoA], mInfos[infoB], vertA));
							break;
						}
					}
				}
			}
		}
	}

	while (mInfos.num != 0) {
		TriStrip* newStrip = new TriStrip;

		int startingIdx = -1;
		int minLinkNum  = 4;

		for (int i = 0; i < mInfos.num; ++i) {
			if (mInfos[i]->mLinks.num < minLinkNum) {
				startingIdx = i;
				minLinkNum  = mInfos[i]->mLinks.num;
			}
		}
		if (startingIdx == -1) {
			PRINT("ERROR: could not find starting tri\n");
			return;
		}

		TriInfo* currInfo = mInfos[startingIdx];
		TriInfo* prevInfo = nullptr;
		TriLink* prevLink = nullptr;

		mInfos.Remove(currInfo);
		for (int local_44 = 0; local_44 < currInfo->mLinks.num; ++local_44) {
			currInfo->mLinks[local_44]->mInfoB->unlink(currInfo);
		}
		newStrip->mInfos.Add(currInfo);

		BOOL isOddIteration = TRUE;
		while (currInfo && currInfo->mLinks.num != 0) {
			TriLink* currLink = currInfo->mLinks[0];

			// `prevInfo` and `prevLink` might not be initialized yet.
			if (prevLink) {
				TriLink* foundLink = nullptr;

				for (int tryLinkIdx = 0; tryLinkIdx < currInfo->mLinks.num; ++tryLinkIdx) {
					TriLink* tryLink = currInfo->mLinks[tryLinkIdx];

					if (isOddIteration == FALSE) {
						if (prevInfo->mVertices[(prevLink->mOnVtx + 1) % 3] == currInfo->mVertices[(tryLink->mOnVtx + 1) % 3]) {
							foundLink = tryLink;
							break;
						}
					}
					if (isOddIteration == TRUE) {
						if (prevInfo->mVertices[(prevLink->mOnVtx) % 3] == currInfo->mVertices[(tryLink->mOnVtx) % 3]) {
							foundLink = tryLink;
							break;
						}
					}
				}

				currLink = foundLink;
			}

			// If the prior loop failed and set `currLink` to `nullptr`, bail.
			if (!currLink) {
				currInfo = nullptr;
				break;
			}

			newStrip->mLinks.Add(currLink);
			currInfo->mLinks.Remove(currLink);

			for (int local_5c = 0; local_5c < currLink->mInfoB->mLinks.num; ++local_5c) {
				if (currLink->mInfoB->mLinks[local_5c]->mInfoB == currInfo) {
					// Either someone forgot that `List::DelIndex` exists, or it
					// is important that the removed link be unique in its list.
					currLink->mInfoB->mLinks.Remove(currLink->mInfoB->mLinks[local_5c]);
					break;
				}
			}

			prevLink = currLink;
			prevInfo = currInfo;
			currInfo = currLink->mInfoB;
			isOddIteration ^= TRUE;

			mInfos.Remove(currInfo);
			for (int local_60 = 0; local_60 < currInfo->mLinks.num; ++local_60) {
				currInfo->mLinks[local_60]->mInfoB->unlink(currInfo);
			}
			newStrip->mInfos.Add(currLink->mInfoB);
		}

		mStrips.Add(newStrip);
	}
}

#define HI16(x) ((x) >> 8)   // High byte of a 16-bit value
#define LO16(x) ((x) & 0xFF) // Low byte of a 16-bit value

/**
 * @todo Documentation
 */
void TriStripifier::outputTriStrips(RandomAccessStream& stream)
{
	// This function counts how many tris save memory by being on a strip, but does nothing with that information.
	int optimizedTriCount = 0;

	for (int stripIdx = 0; stripIdx < mStrips.num; ++stripIdx) {
		TriInfo* currInfo = mStrips[stripIdx]->mInfos[0];

		if (mStrips[stripIdx]->mLinks.num != 0) {
			int local_1c[2] = {
				currInfo->mVertices[(mStrips[stripIdx]->mLinks[0]->mOnVtx)],
				currInfo->mVertices[(mStrips[stripIdx]->mLinks[0]->mOnVtx + 1) % 3],
			};

			int stripVertCount = mStrips[stripIdx]->mInfos.num + 2;
			int local_24       = 0; // TODO: Give this a name even though it's ultimately unused.
			mTriCount += stripVertCount;

			stream.writeByte(GX_TRIANGLESTRIP);
			stream.writeByte(HI16(stripVertCount));
			stream.writeByte(LO16(stripVertCount));

			for (int i1 = 0; i1 < 3; ++i1) {
				if (currInfo->mVertices[i1] != local_1c[0] && currInfo->mVertices[i1] != local_1c[1]) {
					for (int j1 = 0; j1 < 3; ++j1) {
						++local_24;

						if ((_30 & Mode::Unk0)) {
							stream.writeByte(mVerts[currInfo->mVertices[(i1 + j1) % 3]]->mMeshVtxIdx);
						}
						if ((_30 & Mode::Unk1)) {
							stream.writeByte(mVerts[currInfo->mVertices[(i1 + j1) % 3]]->mMeshVtxIdx + 30);
						}

						stream.writeByte(HI16(mVerts[currInfo->mVertices[(i1 + j1) % 3]][1].mMeshVtxIdx));
						stream.writeByte(LO16(mVerts[currInfo->mVertices[(i1 + j1) % 3]][1].mMeshVtxIdx));

						stream.writeByte(HI16(mVerts[currInfo->mVertices[(i1 + j1) % 3]][2].mMeshVtxIdx));
						stream.writeByte(LO16(mVerts[currInfo->mVertices[(i1 + j1) % 3]][2].mMeshVtxIdx));

						stream.writeByte(HI16(mVerts[currInfo->mVertices[(i1 + j1) % 3]][2].mMeshVtxIdx));
						stream.writeByte(LO16(mVerts[currInfo->mVertices[(i1 + j1) % 3]][2].mMeshVtxIdx));

						stream.writeByte(HI16(mVerts[currInfo->mVertices[(i1 + j1) % 3]][3].mMeshVtxIdx));
						stream.writeByte(LO16(mVerts[currInfo->mVertices[(i1 + j1) % 3]][3].mMeshVtxIdx));
					}
					break;
				}
			}

			for (int i2 = 0; i2 < mStrips[stripIdx]->mLinks.num; ++i2) {
				TriLink* local_34 = mStrips[stripIdx]->mLinks[i2];
				if (i2 != 0) {
					int local_3c[2] = {
						currInfo->mVertices[(local_34->mOnVtx)],
						currInfo->mVertices[(local_34->mOnVtx + 1) % 3],
					};

					for (int j2 = 0; j2 < 2; ++j2) {
						if (local_3c[j2] != local_1c[0] && local_3c[j2] != local_1c[1]) {
							++local_24;

							if ((_30 & Mode::Unk0)) {
								stream.writeByte(mVerts[local_3c[j2]]->mMeshVtxIdx);
							}
							if ((_30 & Mode::Unk1)) {
								stream.writeByte(mVerts[local_3c[j2]]->mMeshVtxIdx + 30);
							}

							stream.writeByte(HI16(mVerts[local_3c[j2]][1].mMeshVtxIdx));
							stream.writeByte(LO16(mVerts[local_3c[j2]][1].mMeshVtxIdx));

							stream.writeByte(HI16(mVerts[local_3c[j2]][2].mMeshVtxIdx));
							stream.writeByte(LO16(mVerts[local_3c[j2]][2].mMeshVtxIdx));

							stream.writeByte(HI16(mVerts[local_3c[j2]][3].mMeshVtxIdx));
							stream.writeByte(LO16(mVerts[local_3c[j2]][3].mMeshVtxIdx));

							if (local_3c[j2 ^ 1] == local_1c[0]) {
								local_1c[1] = local_3c[j2];
							} else {
								local_1c[0] = local_3c[j2];
							}
							break;
						}
					}
				}
				currInfo = local_34->mInfoB;
			}

			for (int i3 = 0; i3 < 3; ++i3) {
				if (currInfo->mVertices[i3] != local_1c[0] && currInfo->mVertices[i3] != local_1c[1]) {
					++local_24;

					if ((_30 & Mode::Unk0)) {
						stream.writeByte(mVerts[currInfo->mVertices[i3]]->mMeshVtxIdx);
					}
					if ((_30 & Mode::Unk1)) {
						stream.writeByte(mVerts[currInfo->mVertices[i3]]->mMeshVtxIdx + 30);
					}
					stream.writeByte(HI16(mVerts[currInfo->mVertices[i3]][1].mMeshVtxIdx));
					stream.writeByte(LO16(mVerts[currInfo->mVertices[i3]][1].mMeshVtxIdx));

					stream.writeByte(HI16(mVerts[currInfo->mVertices[i3]][2].mMeshVtxIdx));
					stream.writeByte(LO16(mVerts[currInfo->mVertices[i3]][2].mMeshVtxIdx));

					stream.writeByte(HI16(mVerts[currInfo->mVertices[i3]][3].mMeshVtxIdx));
					stream.writeByte(LO16(mVerts[currInfo->mVertices[i3]][3].mMeshVtxIdx));

					break;
				}
			}
		} else {
			stream.writeByte(GX_TRIANGLEFAN);
			stream.writeByte(0);
			stream.writeByte(3);
			mTriCount += 3;

			for (int i1 = 0; i1 < 3; ++i1) {
				if ((_30 & Mode::Unk0)) {
					stream.writeByte(mVerts[currInfo->mVertices[i1]]->mMeshVtxIdx);
				}
				if ((_30 & Mode::Unk1)) {
					stream.writeByte(mVerts[currInfo->mVertices[i1]]->mMeshVtxIdx + 30);
				}

				stream.writeByte(HI16(mVerts[currInfo->mVertices[i1]][1].mMeshVtxIdx));
				stream.writeByte(LO16(mVerts[currInfo->mVertices[i1]][1].mMeshVtxIdx));

				stream.writeByte(HI16(mVerts[currInfo->mVertices[i1]][2].mMeshVtxIdx));
				stream.writeByte(LO16(mVerts[currInfo->mVertices[i1]][2].mMeshVtxIdx));

				stream.writeByte(HI16(mVerts[currInfo->mVertices[i1]][3].mMeshVtxIdx));
				stream.writeByte(LO16(mVerts[currInfo->mVertices[i1]][3].mMeshVtxIdx));
			}
		}

		optimizedTriCount += mStrips[stripIdx]->mInfos.num;
	}

	PRINT("strip loads = %d\n", mTriCount);
}
