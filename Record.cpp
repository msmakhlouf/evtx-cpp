#include "Record.h"

namespace Evtx {

const char Record::MAGIC[Record::MAGIC_LENGTH] = { 0x42, 0x42, 0x00, 0x00 };

Record::Record(void)
{
	BinXmlStream = NULL;
	Xml = NULL;
}

Record::Record(FILE* stream) {
	Record();
	// We suppose that stream pointer is set correctly.
	fseek(stream, Record::MAGIC_LENGTH, SEEK_CUR);	// TODO: check whether record signature is correct
	fread(&Length1, sizeof uint32, 1, stream);
	fread(&NumLogRecord, sizeof int64, 1, stream);
	fread(&TimeCreated, sizeof FILETIME, 1, stream);

	uint32 binXmlStreamSize = Length1 - Record::MAGIC_LENGTH - 2*(sizeof uint32) - sizeof FILETIME;
	BinXmlStream = new char[binXmlStreamSize];
	fread(BinXmlStream, sizeof (char), binXmlStreamSize, stream);

	fread(&Length2, sizeof uint32, 1, stream);
}

Record::~Record(void)
{
	delete []BinXmlStream;
	if (Xml != NULL) {
		delete []Xml;
	}
}

uint32 Record::getLength(void) {
	return Length1;
}

const wchar_t* Record::toXml() {
	if (Xml == NULL) {
		// TODO: create Bxml::Parser and parse Bxml
		// TODO: get XML and save it to the Xml
	}
	return (const wchar_t*) Xml;
}

}
