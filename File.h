#pragma once

#include "DataTypes.h"
#include "Header.h"
#include "Chunk.h"

namespace Evtx {

class File
{
/* public constructors */
public:
	File(char* filename);
	~File(void);

/* public methods */
public:
	bool isDirty(void);
	bool isFull(void);
	uint16 getChunkCount(void);
	bool CRCPass(void);
	uint16 getMajorVersion(void);
	uint16 getMinorVersion(void);
	int64 getCurrentChunkNum(void);
	int64 getNextRecordNum(void);
	void dumpTo(char* filename, uint32 mode);

/* protected methods */
protected:
	bool loadNextChunk();

/* protected members */
protected:
	FILE* stream;
	Header* header;
	uint16 nextChunkIndex;
	Chunk* currentChunk;
};

}
