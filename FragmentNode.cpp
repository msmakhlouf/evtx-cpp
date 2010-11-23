#include "FragmentNode.h"

namespace Bxml {

FragmentNode::FragmentNode(char* data, size_t length, Context context) : Node(data, length, context)
{
	if (length < 4) {
		// TODO: throw an exception
	}
	MajorVersion = data[1];
	MinorVersion = data[2];
	Flags = data[3];

	size += 4;
	while (size < length) {
		size += appendChild(Node::createNode(data+size, length-size, context));
	}
}

FragmentNode::~FragmentNode(void)
{
}

std::wstring* FragmentNode::toXml() {
	return NULL;
}

}
