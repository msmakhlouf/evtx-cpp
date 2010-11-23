#include "ValueTextNode.h"

#include "Tokens.h"

#include <cstring>

namespace Bxml {

ValueTextNode::ValueTextNode(char* data, size_t length) :
	Node(data, length)
{
	last = (*(data+size)) == ValueTextLast;
	// skipping StringType byte
	size += 2 * (sizeof byte);

	uint16* lengthPtr = reinterpret_cast<uint16*>(data+size);
	this->length = *lengthPtr;
	size += sizeof uint16;

	string = new wchar_t[this->length+1];
	memset(string, 0, sizeof (wchar_t) * (this->length+1));

	wchar_t* stringSrc = reinterpret_cast<wchar_t*>(data+size);
	wcsncpy(string, stringSrc, this->length);

	size += this->length * sizeof (wchar_t);
}

ValueTextNode::~ValueTextNode(void)
{
	delete []string;
}

size_t ValueTextNode::getLength() {
	return length;
}

std::wstring* ValueTextNode::toXml() {
	if (Xml != NULL) {
		Xml = new std::wstring(string);
	}
	return Xml;
}

bool ValueTextNode::isLast() {
	return last;
}

}
