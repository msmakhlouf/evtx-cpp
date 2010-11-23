#include "CDATASectionNode.h"

#include "Tokens.h"

#include <sstream>

namespace Bxml {

CDATASectionNode::CDATASectionNode(char* data, size_t length) :
	Node(data, length)
{
	last = (*(data+size)) == CDATASectionLast;
	size += sizeof byte;

	uint16* lengthPtr = reinterpret_cast<uint16*>(data+size);
	this->length = *lengthPtr;
	size += sizeof uint16;

	string = new wchar_t[this->length+1];
	memset(string, 0, sizeof (wchar_t) * (this->length+1));

	wchar_t* stringSrc = reinterpret_cast<wchar_t*>(data+size);
	wcsncpy(string, stringSrc, this->length);

	size += this->length * sizeof (wchar_t);
}

CDATASectionNode::~CDATASectionNode(void)
{
	delete []string;
}

size_t CDATASectionNode::getLength() {
	return length;
}

std::wstring* CDATASectionNode::toXml() {
	if (Xml == NULL) {
		std::wstringstream xmlStream;
		xmlStream << L"<[CDATA[" << string << L"]]";
		Xml = new std::wstring(xmlStream.str());
	}
	return Xml;
}

bool CDATASectionNode::isLast() {
	return last;
}

}
