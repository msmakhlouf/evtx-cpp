#include "Node.h"
#include "Tokens.h"
#include "ValueTextNode.h"
#include "CDATASectionNode.h"
#include "CharRefNode.h"
#include "EntityRefNode.h"
#include "CloseStartElementNode.h"
#include "CloseEmptyElementNode.h"
#include "EndElementNode.h"
#include "ElementNode.h"
#include "FragmentNode.h"

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
	for (size_t i=0, _size=childNodes->size(); i<_size; ++i) {
		delete (*childNodes)[i];
	}
	delete childNodes;
}

Node* Node::createNode(char *data, size_t length, Context context, Node* parent) {
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
			node = new EndElementNode(data, length, parent);
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

Node* Node::getFirstChild() {
	currentChild = childNodes->begin();
	return *currentChild;
}

Node* Node::getNextChild() {
	currentChild++;
	return *currentChild;
}

bool Node::nextChildExists() {
	return currentChild != childNodes->end();
}

}
