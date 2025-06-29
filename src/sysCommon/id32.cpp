#include "ID32.h"

#include "Stream.h"
#include "Age.h"
#include "sysNew.h"
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
DEFINE_PRINT("id32");

/*
 * --INFO--
 * Address:	80043E5C
 * Size:	000038
 */
ID32::ID32(void)
{
	setID('none');
}

/*
 * --INFO--
 * Address:	80043E94
 * Size:	000030
 */
ID32::ID32(u32 id)
{
	setID(id);
}

/**
 * @brief Sets the ID value for the ID32 object.
 *
 * @param _id The ID value to be set.
 *
 * --INFO--
 * Address:	80043EC4
 * Size:	000024
 */
void ID32::setID(u32 _id)
{
	mId = _id;
	updateString();
}

/**
 * @brief Checks if the given ID matches the ID stored in the ID32 object.
 *
 * @param pId The ID to be checked.
 * @param exception The exception value that will be ignored during the matching process.
 * @return true if the ID matches the stored ID, false otherwise.
 *
 * --INFO--
 * Address:	80043EE8
 * Size:	0000A8
 */
bool ID32::match(u32 pId, char exception)
{
	u8* paramId = reinterpret_cast<u8*>(&pId);
	u8* id      = reinterpret_cast<u8*>(&mId);

	for (int i = 0; i < 4; i++) {
		if (paramId[i] != (u8)exception && paramId[i] != id[i]) {
			return false;
		}
	}

	return true;
}

/**
 * @brief Updates the ID of the ID32 object based on the string ID.
 *
 * This function copies the first 4 bytes of the string ID to the ID32 object's ID.
 *
 * --INFO--
 * Address:	80043F90
 * Size:	000024
 */
void ID32::updateID()
{
	u8* id = reinterpret_cast<u8*>(&mId);

	for (int i = 0; i < 4; i++) {
		id[i] = this->mStringID[i];
	}
}

/**
 * @brief Updates the string of the ID32 object.
 *
 * This function converts the internal ID value to a string and stores it
 * in the mStringID member variable. The string is a null-terminated character array.
 *
 * --INFO--
 * Address:	80043FB4
 * Size:	00002C
 */
void ID32::updateString()
{
	u8* id = reinterpret_cast<u8*>(&mId);

	for (int i = 0; i < 4; i++) {
		mStringID[i] = id[i];
	}

	mStringID[4] = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void ID32::operator=(u32 other)
{
	setID(other);
}

/*
 * --INFO--
 * Address:	80043FE0
 * Size:	000014
 */
bool ID32::operator==(u32 other)
{
	return mId == other;
}

/*
 * --INFO--
 * Address:	80043FF4
 * Size:	000014
 */
bool ID32::operator!=(u32 other)
{
	return mId != other;
}

/**
 * Writes the ID32 value to the given RandomAccessStream.
 *
 * @param stream The RandomAccessStream to write the ID32 value to.
 *
 * --INFO--
 * Address:	80044008
 * Size:	000094
 */
void ID32::write(RandomAccessStream& stream)
{
	u8* id = reinterpret_cast<u8*>(&mId);

	stream.writeByte(id[3]);
	stream.writeByte(id[2]);
	stream.writeByte(id[1]);
	stream.writeByte(id[0]);
}

/**
 * @brief Reads the ID32 value from the given RandomAccessStream.
 *
 * @param stream The RandomAccessStream to read from.
 *
 * --INFO--
 * Address:	8004409C
 * Size:	0000BC
 */
void ID32::read(RandomAccessStream& stream)
{
	u8* id = reinterpret_cast<u8*>(&mId);
	id[3]  = stream.readByte();
	id[2]  = stream.readByte();
	id[1]  = stream.readByte();
	id[0]  = stream.readByte();

	updateString();
}

/*
 * --INFO--
 * Address:	80044158
 * Size:	000004
 */
void ID32::print()
{
	PRINT("id (%x) is %s\n", mId, mStringID);
}

/**
 * @brief Converts the ID32 value to a string representation and stores it in the provided buffer.
 *
 * The ID32 value is converted to a string by extracting the individual bytes of the ID and
 * storing them in the buffer. The bytes are stored in big-endian order, with the most significant
 * byte at the beginning of the buffer. A null terminator is added at the end of the string.
 *
 * @param buffer The buffer to store the string representation of the ID32 value.
 *
 * --INFO--
 * Address:	8004415C
 * Size:	000038
 */
void ID32::sprint(char* buffer)
{
	buffer[0] = (u8)((this->mId & 0xFF000000) >> 24);
	buffer[1] = (u8)((this->mId & 0xFF0000) >> 16);
	buffer[2] = (u8)((this->mId & 0xFF00) >> 8);
	buffer[3] = (u8)(this->mId & 0xFF);
	buffer[4] = 0;
}

#ifdef DEVELOP

// .dll exclusive function

void ID32::genAge(AgeServer& server, char* name)
{
	server.setOnChange(new Delegate<ID32>(this, ageChangeID));
	server.NewEditor(name, mStringID, 5);
	server.setOnChange((Delegate<ID32>*)nullptr);
}

#endif
