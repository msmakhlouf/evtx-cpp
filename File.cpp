#include "File.h"

#define BXML_BUFFER_SIZE	65536

namespace Evtx {

File::File(char* filename)
{
	stream = fopen(filename, "rb");
	header = new Header(stream);
	nextChunkIndex = 0;
	currentChunk = NULL;
}

File::~File(void)
{
	fclose(stream);
	delete header;
	if (currentChunk != NULL) {
		delete currentChunk;
	}
}

bool File::isDirty(void) {
	return header->isDirty();
}

bool File::isFull(void) {
	return header->isFull();
}

uint16 File::getChunkCount(void) {
	return header->ChunkCount;
}

bool File::CRCPass(void) {
	return header->hasValidCRC();
}

uint16 File::getMajorVersion(void) {
	return header->MajorVersion;
}

uint16 File::getMinorVersion(void) {
	return header->MinorVersion;
}

int64 File::getCurrentChunkNum(void) {
	return header->CurrentChunkNum;
}

int64 File::getNextRecordNum(void) {
	return header->NextRecordNum;
}

void File::dumpTo(char* filename, uint32 mode) {
	// TODO: write dump code
	FILE* dumpStream = fopen(filename, "w");
	nextChunkIndex = 0;
	wchar_t* buffer = new wchar_t[BXML_BUFFER_SIZE];
	while (loadNextChunk()) {
		while (currentChunk->getNextRecordXml(buffer, BXML_BUFFER_SIZE)) {
			fprintf(dumpStream, "%s", buffer);
		}
	}
}

bool File::loadNextChunk(void) {
	if (nextChunkIndex < getChunkCount()) {
		if (currentChunk != NULL) {
			delete currentChunk;
		}
		currentChunk = new Chunk(stream, nextChunkIndex);
		nextChunkIndex++;
		return true;
	}
	return false;
}

}
