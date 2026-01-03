#include "Parameters.h"

#include "Colour.h"
#include "Common/String.h"
#include "CoreNode.h"
#include "DebugLog.h"
#include "Stream.h"
#include "Vector.h"

// macros for packing and unpacking parameter IDs and sizes, to be read/written together.

/// Packs 3-byte ID and parameter length (in bytes) into single 4-byte entry.
#define PACK_ID_SIZE(id, size) ((id) & 0xFFFFFF00 | (size))

/// Unpacks 3-byte ID from combined entry.
#define UNPACK_ID(flag) ((flag) & 0xFFFFFF00)

/// Unpacks parameter size (length in bytes) from combined entry.
#define UNPACK_SIZE(flag) ((flag) & 0xFF)

/// Terminator for parameter list file.
#define FILE_TERMINATOR (-1)

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr);

/**
 * @brief Constructs a new base parameter and adds it to the end of the parent list.
 *
 * @param parentParms Parameters whose list we should add this parameter to.
 * @param id Fourcc-style ID to assign to this parameter. ID should only ever use 3 bytes however.
 */
BaseParm::BaseParm(Parameters* parentParms, ayuID id)
{
	BaseParm* currParm;
	BaseParm* debugNode;
	BaseParm* lastParm;

	debugNode = currParm = parentParms->mFirstParm;
	for (debugNode; debugNode; debugNode = debugNode->mNext) {
		// probably some debug text, not present in DLL or DOL.
		;
	}

	// search through parent list until we find the end
	lastParm = nullptr;
	for (currParm; currParm; currParm = currParm->mNext) {
		lastParm = currParm;
	}

	if (lastParm) {
		// make this the new end of the list
		lastParm->mNext = this;
	} else {
		// no list yet, so make it the start
		parentParms->mFirstParm = this;
	}

	mID   = id;
	mNext = nullptr;
}

/**
 * @brief Writes all parameters in list to file stream, including each parameter's ID, size, and data.
 *
 * Each parameter's entry is preceded by its 4-byte-packed ID/size. File is terminated with 4-byte 0xFFFFFFFF.
 *
 * @param output File stream to write parameter list to.
 */
void Parameters::write(RandomAccessStream& output)
{
	STACK_PAD_VAR(1);

	FOREACH_NODE(BaseParm, mFirstParm, node)
	{
		// each parm's entry starts with its 3-byte ID, plus a 1-byte size.
		output.writeInt(PACK_ID_SIZE(node->mID.Num(), node->size()));
		node->write(output);
	}

	// end of parameter list is marked by -1 (0xFFFFFFFF).
	output.writeInt(FILE_TERMINATOR);
}

/**
 * @brief Calculates the total size (in bytes) needed to serialise all parameters, including headers and terminator.
 *
 * @return Total size (in bytes).
 * @note UNUSED Size: 000064
 */
int Parameters::sizeInFile()
{
	int size = 0;
	FOREACH_NODE(BaseParm, mFirstParm, node)
	{
		// each entry has its ID/size packed flag preceding it, which takes up an additional 4 bytes
		size += node->size() + 4;
	}

	// parameter file contains a final -1 (0xFFFFFFFF) indicating end-of-file (4 bytes)
	return size + 4;
}

/**
 * @brief Reads parameters from file stream, matching 3-byte IDs to known parameters, and skipping unknown ones.
 *
 * Individual parameter entries should not exceed 256 bytes, or unknown ones will risk overflowing the skip buffer.
 *
 * @param input File stream to read from.
 */
void Parameters::read(RandomAccessStream& input)
{
	u8 skipBuffer[256]; // buffer to use when skipping an entry with unknown ID
	STACK_PAD_VAR(1);

	while (true) {
		int entryHeader = input.readInt();
		if (entryHeader == FILE_TERMINATOR) {
			// end of file reached
			break;
		}

		int entrySize = UNPACK_SIZE(entryHeader);
		int id        = UNPACK_ID(entryHeader);

		// check if ID currently being read is in the list - if so, read it in
		bool inList = false;
		FOREACH_NODE(BaseParm, mFirstParm, node)
		{
			if (id == node->mID.Num()) {
				inList = true;
				node->read(input);
				break;
			}
		}

		// if not, skip it using its stored size
		if (!inList) {
			input.read(skipBuffer, entrySize);
		}
	}
}

/**
 * @brief Reads value from file stream.
 *
 * @param input File stream to read from.
 * @note UNUSED Size: 000094
 */
void Parm<Colour>::read(RandomAccessStream& input)
{
	mValue.read(input);
}

/**
 * @brief Writes value to file stream.
 *
 * @param output File stream to write to.
 * @note UNUSED Size: 000024
 */
void Parm<Colour>::write(RandomAccessStream& output)
{
	mValue.write(output);
}

#ifdef WIN32
void Parm<Colour>::genAge(AgeServer& server)
{
	mValue.genAge(server, mName);
}
#endif

/**
 * @brief Reads value from file stream.
 *
 * @param input File stream to read from.
 * @note UNUSED Size: 00007C
 */
void Parm<Vector3f>::read(RandomAccessStream& input)
{
	mValue.read(input);
}

/**
 * @brief Writes value to file stream.
 *
 * @param output File stream to write to.
 * @note UNUSED Size: 00007C
 */
void Parm<Vector3f>::write(RandomAccessStream& output)
{
	mValue.write(output);
}

#ifdef WIN32
void Parm<Vector3f>::genAge(AgeServer& server)
{
	mValue.genAge(server, mName, mMinValue, mMaxValue);
}
#endif

/**
 * @brief Reads value from file stream.
 *
 * @param input File stream to read from.
 */
void Parm<f32>::read(RandomAccessStream& input)
{
	mValue = input.readFloat();
}

/**
 * @brief Writes value to file stream.
 *
 * @param output File stream to write to.
 */
void Parm<f32>::write(RandomAccessStream& output)
{
	output.writeFloat(mValue);
}

#ifdef WIN32
void Parm<f32>::genAge(AgeServer& server)
{
	server.NewEditor(mName, &mValue, mMinValue, mMaxValue, 320);
}
#endif

/**
 * @brief Reads value from file stream.
 *
 * @param input File stream to read from.
 */
void Parm<int>::read(RandomAccessStream& input)
{
	mValue = input.readInt();
}

/**
 * @brief Writes value to file stream.
 *
 * @param output File stream to write to.
 */
void Parm<int>::write(RandomAccessStream& output)
{
	output.writeInt(mValue);
}

#ifdef WIN32
void Parm<int>::genAge(AgeServer& server)
{
	server.NewEditor(mName, &mValue, mMinValue, mMaxValue, 320);
}
#endif

/**
 * @brief Reads value from file stream.
 *
 * @param input File stream to read from.
 */
void Parm<String>::read(RandomAccessStream& input)
{
	mValue = String(input.readString(), 0);
}

/**
 * @brief Writes value to file stream.
 *
 * @param output File stream to write to.
 */
void Parm<String>::write(RandomAccessStream& output)
{
	output.writeString(mValue);
}

#ifdef WIN32

void Parm<String>::genAge(AgeServer& server)
{
	if (mValue.mLength == 0) {
		mValue.mLength = 0x800;
		char* str      = mValue.mString;
		mValue.mString = new char[0x800];
		memcpy(mValue.mString, str, strlen(str));
		mValue.mString[strlen(str)] = 0;
	}
	server.NewEditor(mName, mValue.mString, mValue.mLength);
}

void Parameters::genAgeParms(AgeServer& server, int)
{
	FOREACH_NODE(BaseParm, mFirstParm, node)
	{
		node->genAge(server);
	}
}

void Parameters::genAge(AgeServer& server, int a)
{
	char path[PATH_MAX];
	if (a) {
		sprintf(path, "%s1", mFirstParm);
	} else {
		sprintf(path, "%s", mFirstParm);
	}
	server.StartGroup(path);
	genAgeParms(server, a);
	server.EndGroup();
}

#endif
