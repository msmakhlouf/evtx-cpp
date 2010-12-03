#ifndef _BXML_ENDELEMENTNODE_
#define _BXML_ENDELEMENTNODE_

#include "Node.h"
#include "ElementNode.h"

namespace Bxml {

class EndElementNode :
	public Node
{
public:
	EndElementNode(char* data, size_t length, Node* parent);
	~EndElementNode(void);

public:
	std::wstring* toXml();
	bool isLast();

private:
	ElementNode* parent;
};

}

#endif
