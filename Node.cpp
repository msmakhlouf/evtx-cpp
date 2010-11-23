#include "Tokens.h"
#include "Node.h"
#include "FragmentNode.h"
#include "ElementNode.h"
#include "ValueTextNode.h"
#include "CDATASectionNode.h"
#include "CharRefNode.h"
#include "EntityRefNode.h"
#include "CloseStartElementNode.h"
#include "CloseEmptyElementNode.h"
#include "EndElementNode.h"

namespace Bxml {

Node::Node(char* data, size_t length, Context context)
{
	Xml = NULL;
	childNodes = new std::vector<Node*>;
	size = 0;
	last = false;
}

Node::~Node(void)
{
	if (Xml != NULL) {
		delete Xml;
	}
	for (size_t i=0, size=childNodes->size(); i<size; ++i) {
		delete (*childNodes)[i];
	}
	delete childNodes;
}

Node* Node::createNode(char *data, size_t length, Context context) {
	if (length == 0) {
		return NULL;
	}
	Node* node;
	switch (*data) {
		case FragmentHeader:
			node = new FragmentNode(data, length, context);
			break;
		case OpenStartElement:
			node = new ElementNode(data, length, context);
			break;
		case OpenStartElementAttr:
			node = new ElementNode(data, length, context, ATTR_HAS_ATTRIBUTES);
			break;
		case CloseStartElement:
			node = new CloseStartElementNode(data, length);
			break;
		case CloseEmptyElement:
			node = new CloseEmptyElementNode(data, length);
			break;
		case EndElement:
			node = new EndElementNode(data, length);
			break;
		case ValueText:
		case ValueTextLast:
			node = new ValueTextNode(data, length);
			break;
		case CDATASection:
		case CDATASectionLast:
			node = new CDATASectionNode(data, length);
			break;
		case CharRef:
		case CharRefLast:
			node = new CharRefNode(data, length);
			break;
		case EntityRef:
		case EntityRefLast:
			node = new EntityRefNode(data, length);
			break;
		// TODO: add TemplateInstance and substitutions
		default:
			node = NULL;
			break;
	}
	return node;
}

size_t Node::appendChild(Node *node) {
	childNodes->push_back(node);
	return node->getSize();
}

std::wstring* Node::toXml() {
	return NULL;
}

size_t Node::getSize() {
	return size;
}

bool Node::isLast() {
	return last;
}

}
