#include "CloseStartElementNode.h"

#include "CustomTypes.h"

namespace Bxml {

CloseStartElementNode::CloseStartElementNode(char* data, size_t length) :
	Node(data, length)
{
	size += sizeof byte;
}

CloseStartElementNode::~CloseStartElementNode(void)
{
}

std::wstring* CloseStartElementNode::toXml() {
	if (Xml == NULL) {
		Xml = new std::wstring(L">");
	}
	return Xml;
}

bool CloseStartElementNode::isLast() {
	return false;
}

}
