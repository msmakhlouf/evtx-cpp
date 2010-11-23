#pragma once

#include "DataTypes.h"
#include "Record.h"

#include <cstdio>

namespace Evtx {

class Chunk
{
/* public constructors */
public:
	Chunk(void);
	Chunk(FILE* stream, uint16 count);
	~Chunk(void);

/* public methods */
public:
	bool hasValidDataCRC(void);
	bool hasValidHeaderCRC(void);
	bool getNextRecordXml(wchar_t* buffer, size_t buf_size);

/* protected methods */
protected:
	bool loadNextRecord();

/* public members */
public:
	int64 NumLogRecFirst;
	int64 NumLogRecLast;
	int64 NumFileRecFirst;
	int64 NumFileRecLast;
	uint32 OfsRecLast;
	uint32 OfsRecNext;
	uint32 DataCRC;
	uint32 HeaderCRC;
	uint32* StringTable;
	uint32* TemplateTable;

/* protected members */
protected:
	FILE* stream;
	Record* currentRecord;

/* protected static members */
protected:
	static const int MAGIC_LENGTH = 8;
	static const int UnknownBlockSize = 68;
	static const int StringTableSize = 64;
	static const int TemplateTableSize = 32;

/* public static members */
public:
	static const char MAGIC[MAGIC_LENGTH];

	static const int SIZE = 65536;

	static const uint32 OfsTables = 0x80;

	static const int NumLogRecFirstOffset = 0x008;
	static const int NumLogRecLastOffset = 0x010;
	static const int NumFileRecFirstOffset = 0x018;
	static const int NumFileRecLastOffset = 0x020;
	static const int OfsRecLastOffset = 0x02c;
	static const int OfsRecNextOffset = 0x030;
	static const int DataCRCOffset = 0x034;
	static const int HeaderCRCOffset = 0x07c;
	static const int StringTableOffset = 0x080;
	static const int TemplateTableOffset = 0x180;
};

}
