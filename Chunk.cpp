#include "Chunk.h"
#include "Header.h"

#include <cstring>

namespace Evtx {

const char Chunk::MAGIC[Chunk::MAGIC_LENGTH] = "ElfChnk";

Chunk::Chunk(void)
{
	StringTable = new uint32[StringTableSize];
	TemplateTable = new uint32[TemplateTableSize];
	currentRecord = NULL;
}

Chunk::Chunk(FILE* stream, uint16 count = 0) {
	Chunk();
	this->stream = stream;
	fseek(stream, count * Chunk::SIZE + Header::SIZE, SEEK_SET);// pass to the chunk start 
	fseek(stream, Chunk::MAGIC_LENGTH, SEEK_CUR);				// TODO: check whether chunk signature is correct
	fread(&NumLogRecFirst, sizeof int64, 1, stream);
	fread(&NumLogRecLast, sizeof int64, 1, stream);
	fread(&NumFileRecFirst, sizeof int64, 1, stream);
	fread(&NumFileRecLast, sizeof int64, 1, stream);
	fseek(stream, sizeof uint32, SEEK_CUR);						// pass OfsTables
	fread(&OfsRecLast, sizeof uint32, 1, stream);
	fread(&OfsRecNext, sizeof uint32, 1, stream);
	fread(&DataCRC, sizeof uint32, 1, stream);
	fseek(stream, (sizeof (char)) * UnknownBlockSize, SEEK_CUR);// pass unknown block
	fread(&HeaderCRC, sizeof uint32, 1, stream);
	fread(&StringTable, sizeof uint32, StringTableSize, stream);
	fread(&TemplateTable, sizeof uint32, TemplateTableSize, stream);
}

Chunk::~Chunk(void)
{
	delete []StringTable;
	delete []TemplateTable;
}

bool Chunk::hasValidDataCRC(void) {
	// TODO: calculate chunk data CRC
	// and compare it to the value given in the file
	return true;
}

bool Chunk::hasValidHeaderCRC(void) {
	// TODO: calculate chunk header CRC
	// and compare it to the value given in the file
	return true;
}

bool Chunk::loadNextRecord(void) {
	// TODO: add end of records condition
	if (currentRecord != NULL) {
		delete currentRecord;
	}
	currentRecord = new Record(stream);
	return true;
}

bool Chunk::getNextRecordXml(wchar_t* buffer, size_t buf_size) {
	bool recordRead = loadNextRecord();
	if (recordRead) {
		wcsncpy(buffer, currentRecord->toXml(), buf_size);
	}
	return recordRead;
}

}
