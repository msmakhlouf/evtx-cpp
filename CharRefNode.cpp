#include "CharRefNode.h"

#include "Tokens.h"

#include <sstream>

namespace Bxml {

CharRefNode::CharRefNode(char* data, size_t length) :
	Node(data, length)
{
	last = (*(data+size)) == CharRefLast;
	size += sizeof byte;

	uint16* valuePtr = reinterpret_cast<uint16*>(data+size);
	value = *valuePtr;
	size += sizeof uint16;
}

CharRefNode::~CharRefNode(void)
{
}

std::wstring* CharRefNode::toXml() {
	if (Xml != NULL) {
		std::wstringstream xmlStream;
		xmlStream << L"&#" << value << L";";
		Xml = new std::wstring(xmlStream.str());
	}
	return Xml;
}

bool CharRefNode::isLast() {
	return last;
}

}
