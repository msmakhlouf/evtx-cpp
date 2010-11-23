#pragma once

#include "Node.h"
#include "CustomTypes.h"
#include "Name.h"
#include "AttributeList.h"

#define DEP_NO_DEPENDENCY	0xffff

#define ATTR_NO_ATTRIBUTES	false
#define ATTR_HAS_ATTRIBUTES	true

namespace Bxml {

class ElementNode :
	public Node
{
public:
	ElementNode(char* data, size_t length, Context context, bool hasAttributes = ATTR_NO_ATTRIBUTES);
	~ElementNode(void);

public:
	std::wstring* toXml();

protected:
	uint16 DependencyId;
	uint32 Length;
	Name* name;
	AttributeList* attributeList;
};

}
