#include "AttributeList.h"

#include <sstream>

namespace Bxml {

AttributeList::AttributeList(char* data, size_t length)
{
	Xml = NULL;
	size = 0;

	size_t* byteLengthPtr = reinterpret_cast<size_t*>(data);
	byteLength = *byteLengthPtr;
	size += sizeof size_t;

	Attribute* attr = NULL;
	do {
		attr = new Attribute(data+size, length-size);
		size += appendAttribute(attr);
	} while (!attr->isLast());
}

AttributeList::~AttributeList(void)
{
	if (Xml != NULL) {
		delete Xml;
	}
}

size_t AttributeList::appendAttribute(Attribute *attr) {
	attributes->push_back(attr);
	return attr->getSize();
}

std::wstring* AttributeList::toXml() {
	if (Xml == NULL) {
		std::wstringstream xmlStream;
		for (size_t i=0; i<attributes->size(); ++i) {
			std::wstring* attrXml = (*attributes)[i]->toXml();
			xmlStream << L" " << (*attrXml);
		}
		Xml = new std::wstring(xmlStream.str());
	}
	return Xml;
}

size_t AttributeList::getSize() {
	return size;
}

size_t AttributeList::getByteLength() {
	return byteLength;
}

}
