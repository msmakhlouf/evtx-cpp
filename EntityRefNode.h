#ifndef _BXML_ENTITYREFNODE_
#define _BXML_ENTITYREFNODE_

#include "CustomTypes.h"
#include "Node.h"
#include "Name.h"

namespace Bxml {

class EntityRefNode :
	public Node
{
public:
	EntityRefNode(char* data, size_t length);
	~EntityRefNode(void);

public:
	// returns content string length
	size_t getLength();
	std::wstring* toXml();
	bool isLast();

protected:
	Name* name;
};

}

#endif
