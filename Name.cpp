#include "Name.h"

#include <cstring>

namespace Bxml {

Name::Name(char* data, size_t length)
{
	uint16* nameHashPtr = reinterpret_cast<uint16*>(data);
	nameHash = *nameHashPtr;
	uint16* lengthPtr = reinterpret_cast<uint16*>(data + sizeof uint16);
	this->length = *lengthPtr;
	string = new wchar_t[this->length+1];
	wchar_t* stringSrc = reinterpret_cast<wchar_t*>(data + 2*(sizeof uint16));
	wcsncpy(string, stringSrc, this->length+1);
}

Name::~Name(void)
{
	delete []string;
	if (Xml != NULL) {
		delete Xml;
	}
}

size_t Name::getSize(void) {
	return ((size_t) this->length) + 2*(sizeof uint16) + sizeof (wchar_t);
}

size_t Name::getLength(void) {
	return (size_t) this->length;
}

std::wstring* Name::toXml() {
	if (Xml == NULL) {
		Xml = new std::wstring(string);
	}
	return Xml;
}

}
