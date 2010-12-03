#include "EndElementNode.h"

#include "CustomTypes.h"

#include <sstream>

namespace Bxml {

EndElementNode::EndElementNode(char* data, size_t length, Node* parent) :
	Node(data, length)
{
	size += sizeof byte;
	this->parent = (ElementNode*) parent;
}

EndElementNode::~EndElementNode(void)
{
}

std::wstring* EndElementNode::toXml() {
	if (Xml == NULL) {
		std::wstringstream xmlStream;
		
		std::wstring* elementName = parent->getName();
		xmlStream << L"</" << (*elementName) << L">";

		Xml = new std::wstring(xmlStream.str());
	}
	return Xml;
}

bool EndElementNode::isLast() {
	return true;
}

}
