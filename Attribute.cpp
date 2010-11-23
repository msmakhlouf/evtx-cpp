#include "Attribute.h"

#include "Tokens.h"

#include <sstream>

namespace Bxml {

Attribute::Attribute(char* data, size_t length)
{
	Xml = NULL;
	size = 0;

	last = (*(data+size)) == AttributeLast;
	size += sizeof byte;

	name = new Name(data+size, length-size);
	size += name->getSize();

	Node *value = NULL;
	do {
		value = Node::createNode(data+size, length-size);
		size += appendData(value);
	} while (!value->isLast());
}

Attribute::~Attribute(void)
{
	delete name;

	for (size_t i=0, size=attributeData->size(); i<size; ++i) {
		delete (*attributeData)[i];
	}

	delete attributeData;

	if (Xml != NULL) {
		delete Xml;
	}
}

size_t Attribute::appendData(Node *node) {
	attributeData->push_back(node);
	return node->getSize();
}

std::wstring* Attribute::toXml() {
	if (Xml == NULL) {
		if (attributeData->size() == 0) {
			Xml = new std::wstring();
		}
		else {
			std::wstringstream xmlStream;

			std::wstring* nameXml = name->toXml();
			xmlStream << (*nameXml) << L"='";

			for (size_t i=0, size=attributeData->size(); i<size; ++i) {
				std::wstring* dataPartXml = (*attributeData)[i]->toXml();
				xmlStream << (*dataPartXml);
			}

			xmlStream << L"'";

			Xml = new std::wstring(xmlStream.str());
		}
	}

	return Xml;
}

bool Attribute::isLast() {
	return last;
}

size_t Attribute::getSize() {
	return size;
}

}
