#ifndef _BXML_ELEMENTNODE_
#define _BXML_ELEMENTNODE_

#include "Node.h"
#include "CustomTypes.h"
#include "Name.h"
#include "AttributeList.h"

namespace Bxml {

class ElementNode :
	public Node
{
public:
	ElementNode(char* data, size_t length, Context context, bool hasAttributes = ATTR_NO_ATTRIBUTES);
	~ElementNode(void);

public:
	std::wstring* toXml();
	std::wstring* getName();

protected:
	uint16 DependencyId;
	uint32 Length;
	Name* name;
	AttributeList* attributeList;
};

}

#endif
