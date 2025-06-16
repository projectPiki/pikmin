#include "Ayu.h"
#include "Colour.h"
#include "CoreNode.h"
#include "Parameters.h"
#include "Stream.h"
#include "String.h"
#include "Vector.h"
#include "Age.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	8005EA80
 * Size:	00006C
 */
BaseParm::BaseParm(Parameters* parm, ayuID id)
    : mID(nullptr)
{
	BaseParm* node2;
	BaseParm* node1;
	BaseParm* last;

	node1 = node2 = parm->mHead;
	for (node1; node1; node1 = node1->mNext) {
		;
	}
	last = nullptr;
	for (node2; node2; node2 = node2->mNext) {
		last = node2;
	}

	if (last) {
		last->mNext = this;
	} else {
		parm->mHead = this;
	}

	mID   = (char*)id.mID;
	mNext = nullptr;
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
int Parameters::sizeInFile()
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
void Parm<f32>::read(RandomAccessStream& input)
{
	mValue = input.readFloat();
}

/*
 * --INFO--
 * Address:	8005ECB0
 * Size:	000038
 */
void Parm<f32>::write(RandomAccessStream& output)
{
	output.writeFloat(mValue);
}

/*
 * --INFO--
 * Address:	8005ECE8
 * Size:	000040
 */
void Parm<int>::read(RandomAccessStream& input)
{
	mValue = input.readInt();
}

/*
 * --INFO--
 * Address:	8005ED28
 * Size:	000038
 */
void Parm<int>::write(RandomAccessStream& output)
{
	output.writeInt(mValue);
}

/*
 * --INFO--
 * Address:	8005ED60
 * Size:	000058
 */
void Parm<String>::read(RandomAccessStream& input)
{
	mValue = String(input.readString(), 0);
}

/*
 * --INFO--
 * Address:	8005EDB8
 * Size:	000038
 */
void Parm<String>::write(RandomAccessStream& output)
{
	output.writeString(mValue);
}

#ifdef DEVELOP

void BaseParm::genAge(AgeServer& server)
{
	// todo, find this, if it even does anything
}

void Parameters::genAge(AgeServer& server, int)
{
	FOREACH_NODE(BaseParm, mHead, node)
	{
		node->genAge(server);
	}
}

void Parameters::genAgeParms(AgeServer& server, int a)
{
	char path[PATH_MAX];
	if (a) {
		sprintf(path, "%s1", mHead);
	} else {
		sprintf(path, "%s", mHead);
	}
	server.StartGroup(path);
	genAge(server, a);
	server.EndGroup();
}

#endif
