#include "ElementNode.h"

#include <sstream>

namespace Bxml {

ElementNode::ElementNode(char* data, size_t length, Context context, bool hasAttributes) :
	Node(data, length, context)
{
	name = NULL;
	// TODO: use length to prevent data overrun
	DependencyId = DEP_NO_DEPENDENCY;
	size++;										// pass ElementNode start token
	if (context == TemplateDefinition) {
		uint16* DependencyIdPtr = reinterpret_cast<uint16*>(data+size);
		DependencyId = *DependencyIdPtr;
		size += sizeof uint16;
	}
	uint32* LengthPtr = reinterpret_cast<uint32*>(data+size);
	Length = *LengthPtr;
	size += sizeof uint32;
	name = new Name(data+size, length-size);
	size += name->getSize();

	if (hasAttributes) {
		attributeList = new AttributeList(data+size, length-size);
		size += attributeList->getSize();
	}
	else {
		attributeList = NULL;
	}

	Node* node;
	do {
		node = Node::createNode(data+size, length-size, context);
		size += appendChild(node);
	} while (!node->isLast());
}

ElementNode::~ElementNode(void)
{
	if (name != NULL) {
		delete name;
	}
}

std::wstring* ElementNode::toXml() {
	if (Xml == NULL) {
		std::wstringstream xmlStream;

		// TODO: add some code here :)
		if (DependencyId != DEP_NO_DEPENDENCY /* && NULL optional substitution exists */) {
			// TODO: do not emit anything
		}
		else {
			xmlStream << L'<';
			std::wstring* nameXml = name->toXml();
			xmlStream << (*nameXml);

			if (attributeList != NULL) {
				std::wstring* attrListXml = attributeList->toXml();
				xmlStream << (*attrListXml);
			}

			for (Node* node = getFirstChild(); nextChildExists(); node = getNextChild()) {
				std::wstring* nodeXml = node->toXml();
				xmlStream << (*nodeXml);
			}
		}

		Xml = new std::wstring(xmlStream.str());
	}
	return Xml;
}

std::wstring* ElementNode::getName() {
	return name->toXml();
}


}
