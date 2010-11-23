#include "Header.h"

namespace Evtx {

const char Header::MAGIC[Header::MAGIC_LENGTH] = "ElfFile";

Header::Header(void)
{
}

Header::Header(FILE* stream) {
	Header();

	fseek(stream, 0, SEEK_SET);
	// TODO: check whether file signature is correct
	fseek(stream, CurrentChunkNumOffset, SEEK_SET);
	fread(&CurrentChunkNum, sizeof int64, 1, stream);
	fread(&NextRecordNum, sizeof int64, 1, stream);
	fseek(stream, sizeof uint32, SEEK_CUR);						// pass HeaderPart1Len
	fread(&MinorVersion, sizeof uint16, 1, stream);
	fread(&MajorVersion, sizeof uint16, 1, stream);
	fseek(stream, sizeof uint16, SEEK_CUR);						// pass HeaderSize
	fread(&ChunkCount, sizeof uint16, 1, stream);
	fseek(stream, (sizeof (char)) * UnknownBlock2Size, SEEK_CUR);	// pass unknown block #2
	fread(&Flags, sizeof uint32, 1, stream);
	fread(&Checksum, sizeof uint32, 1, stream);
}

Header::~Header(void)
{
}

bool Header::isDirty(void) {
	return (Flags & DIRTY) != 0;
}

bool Header::isFull(void) {
	return (Flags & FULL) != 0;
}

bool Header::hasValidCRC(void) {
	// TODO: calculate header CRC
	// and compare it to the value given in the file
	return true;
}

}
