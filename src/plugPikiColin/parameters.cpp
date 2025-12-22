#include "Parameters.h"
#include "Age.h"
#include "Ayu.h"
#include "Colour.h"
#include "CoreNode.h"
#include "DebugLog.h"
#include "Stream.h"
#include "String.h"
#include "Vector.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

BaseParm::BaseParm(Parameters* parm, ayuID id)
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

	mID   = id;
	mNext = nullptr;
}

void Parameters::write(RandomAccessStream& output)
{
	STACK_PAD_VAR(1);

	FOREACH_NODE(BaseParm, mHead, node)
	{
		output.writeInt(node->mID.Num() & 0xFFFFFF00 | node->size());
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

void Parameters::read(RandomAccessStream& input)
{
	u8 bloat[256];
	STACK_PAD_VAR(1);
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
			if (id == node->mID.Num()) {
				added = true;
				node->read(input);
				break;
			}
		}

		if (!added) {
			input.read(bloat, len);
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

void Parm<f32>::read(RandomAccessStream& input)
{
	mValue = input.readFloat();
}

void Parm<f32>::write(RandomAccessStream& output)
{
	output.writeFloat(mValue);
}

void Parm<int>::read(RandomAccessStream& input)
{
	mValue = input.readInt();
}

void Parm<int>::write(RandomAccessStream& output)
{
	output.writeInt(mValue);
}

void Parm<String>::read(RandomAccessStream& input)
{
	mValue = String(input.readString(), 0);
}

void Parm<String>::write(RandomAccessStream& output)
{
	output.writeString(mValue);
}

#ifdef WIN32

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
