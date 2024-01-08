#include "Ayu.h"
#include "Colour.h"
#include "CoreNode.h"
#include "Parameters.h"
#include "Stream.h"
#include "String.h"
#include "Vector3f.h"

static char filename[] = __FILE__;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005EA80
 * Size:	00006C
 */
BaseParm::BaseParm(Parameters* parm, ayuID id)
    : mID(nullptr)
{
	BaseParm* head = parm->mHead;
	FOREACH_NODE(BaseParm, head, node) { }

	BaseParm* lastNode = nullptr;
	FOREACH_NODE(BaseParm, head, node) { lastNode = node; }

	if (lastNode) {
		lastNode->mNext = this;
	} else {
		parm->mHead = this;
	}

	mID   = id.mID;
	mNext = nullptr;
	/*
	.loc_0x0:
	  lis       r6, 0x802B
	  subi      r0, r6, 0x7964
	  stw       r0, 0x8(r3)
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  lwz       r6, 0x0(r4)
	  mr        r7, r6
	  b         .loc_0x24

	.loc_0x20:
	  lwz       r7, 0x4(r7)

	.loc_0x24:
	  cmplwi    r7, 0
	  bne+      .loc_0x20
	  li        r7, 0
	  b         .loc_0x3C

	.loc_0x34:
	  mr        r7, r6
	  lwz       r6, 0x4(r6)

	.loc_0x3C:
	  cmplwi    r6, 0
	  bne+      .loc_0x34
	  cmplwi    r7, 0
	  beq-      .loc_0x54
	  stw       r3, 0x4(r7)
	  b         .loc_0x58

	.loc_0x54:
	  stw       r3, 0x0(r4)

	.loc_0x58:
	  lwz       r4, 0x0(r5)
	  li        r0, 0
	  stw       r4, 0x0(r3)
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005EAEC
 * Size:	0000A8
 */
void Parameters::write(RandomAccessStream& output)
{
	BaseParm* parm; // for stack

	FOREACH_NODE(BaseParm, mHead, node)
	{
		output.writeInt((int)node->mID & 0xFFFFFF00 | node->size());
		node->write(output);
	}

	output.writeInt(-1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Parameters::sizeInFile()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005EB98
 * Size:	0000D4
 */
void Parameters::read(RandomAccessStream& input)
{
	u8 bloat[256];
	u8 why[0x8]; // just for stack smh
	while (true) {
		int val = input.readInt();
		if (val == -1) {
			break;
		}
		int len    = val & 0xFF;
		int id     = val & 0xFFFFFF00;
		bool added = false;

		FOREACH_NODE(BaseParm, mHead, node)
		{
			if (id == (int)node->mID) {
				added = true;
				node->read(input);
				break;
			}
		}

		if (!added) {
			input.read((void*)bloat, len);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void Parm<Colour>::read(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void Parm<Colour>::write(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Parm<Vector3f>::read(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Parm<Vector3f>::write(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005EC70
 * Size:	000040
 */
void Parm<f32>::read(RandomAccessStream& input) { mValue = input.readFloat(); }

/*
 * --INFO--
 * Address:	8005ECB0
 * Size:	000038
 */
void Parm<f32>::write(RandomAccessStream& output) { output.writeFloat(mValue); }

/*
 * --INFO--
 * Address:	8005ECE8
 * Size:	000040
 */
void Parm<int>::read(RandomAccessStream& input) { mValue = input.readInt(); }

/*
 * --INFO--
 * Address:	8005ED28
 * Size:	000038
 */
void Parm<int>::write(RandomAccessStream& output) { output.writeInt(mValue); }

/*
 * --INFO--
 * Address:	8005ED60
 * Size:	000058
 */
void Parm<String>::read(RandomAccessStream& input)
{
	String str;
	String str2; // just for stack - probably some consequence of an inline?

	str.mStr    = input.readString();
	str.mLength = 0;
	mValue      = str;
}

/*
 * --INFO--
 * Address:	8005EDB8
 * Size:	000038
 */
void Parm<String>::write(RandomAccessStream& output) { output.writeString(mValue); }
