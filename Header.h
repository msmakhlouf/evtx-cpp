#ifndef _EVTX_HEADER_
#define _EVTX_HEADER_

#include "DataTypes.h"

#include <cstdio>

namespace Evtx {

class Header
{
/* public constructors */
public:
	Header(void);
	Header(FILE* stream);
	~Header(void);

/* public methods */
public:
	bool isDirty(void);
	bool isFull(void);
	bool hasValidCRC(void);

/* public members */
public:
	int64 CurrentChunkNum;
	int64 NextRecordNum;
	uint16 MinorVersion;
	uint16 MajorVersion;
	uint16 ChunkCount;
	uint32 Flags;
	uint32 Checksum;

/* protected static members */
protected:
	static const int MAGIC_LENGTH = 8;
	static const int UnknownBlock1Size = 8;
	static const int UnknownBlock2Size = 76;

/* public static members */
public:
	static const char MAGIC[MAGIC_LENGTH];

	static const uint16 VERSION_NT5 = 1;
	static const uint16 VERSION_CRIMSON = 2;
	static const uint16 VERSION_NT6 = 3;

	static const uint32 DIRTY = 0x01;
	static const uint32 FULL = 0x02;

	static const int SIZE = 4096;

	static const int CurrentChunkNumOffset = 0x10;
	static const int NextRecordNumOffset = 0x18;
	static const int MinorVersionOffset = 0x24;
	static const int MajorVersionOffset = 0x26;
	static const int ChunkCountOffset = 0x2a;
	static const int FlagsOffset = 0x78;
	static const int ChecksumOffset = 0x7c;
};

}

#endif
