#pragma once

#include "DataTypes.h"
#include <windows.h>
#include <cstdio>

namespace Evtx {

class Record
{
/* public constructors */
public:
	Record(void);
	Record(FILE* stream);
	~Record(void);

/* public methods */
public:
	uint32 getLength();
	const wchar_t* toXml();

/* protected methods */
protected:

/* public members */
public:
	int64 NumLogRecord;
	FILETIME TimeCreated;

/* protected members */
protected:
	uint32 Length1;
	char* BinXmlStream;
	wchar_t* Xml;
	uint32 Length2;

/* protected static members */
protected:
	static const int MAGIC_LENGTH = 4;

/* public static members */
public:
	static const char MAGIC[MAGIC_LENGTH];
};

}
