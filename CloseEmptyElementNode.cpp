#include "CloseEmptyElementNode.h"

#include "CustomTypes.h"

namespace Bxml {

CloseEmptyElementNode::CloseEmptyElementNode(char* data, size_t length) :
	Node(data, length)
{
	size += sizeof byte;
}

CloseEmptyElementNode::~CloseEmptyElementNode(void)
{
}

std::wstring* CloseEmptyElementNode::toXml() {
	if (Xml == NULL) {
		Xml = new std::wstring(L"/>");
	}
	return Xml;
}

bool CloseEmptyElementNode::isLast() {
	return true;
}

}
