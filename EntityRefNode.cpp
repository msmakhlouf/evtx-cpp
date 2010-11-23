#include "EntityRefNode.h"

#include "Tokens.h"

#include <sstream>

namespace Bxml {

EntityRefNode::EntityRefNode(char* data, size_t length) :
	Node(data, length)
{
	last = (*(data+size)) == EntityRefLast;
	size += sizeof byte;

	name = new Name(data+size, length-size);
	size += name->getSize();
}

EntityRefNode::~EntityRefNode(void)
{
	delete name;
}

std::wstring* EntityRefNode::toXml() {
	if (Xml != NULL) {
		std::wstringstream xmlStream;
		std::wstring* nameXml = name->toXml();
		xmlStream << L"&" << (*nameXml) << L";";
		Xml = new std::wstring(xmlStream.str());
	}
	return Xml;
}

bool EntityRefNode::isLast() {
	return last;
}

}
