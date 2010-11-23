#include "EndElementNode.h"

#include "CustomTypes.h"

namespace Bxml {

EndElementNode::EndElementNode(char* data, size_t length) :
	Node(data, length)
{
	size += sizeof byte;
}

EndElementNode::~EndElementNode(void)
{
}

std::wstring* EndElementNode::toXml() {
	if (Xml == NULL) {
		Xml = new std::wstring();
	}
	return Xml;
}

bool EndElementNode::isLast() {
	return true;
}

}
