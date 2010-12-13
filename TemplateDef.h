#ifndef _BXML_TEMPLATEDEFINITION_
#define _BXML_TEMPLATEDEFINITION_

#include "Node.h"

namespace Bxml {

class TemplateDef
{
public:
	TemplateDef(char* data, size_t length, Node::Context context, bool hasAttributes = ATTR_NO_ATTRIBUTES);
	~TemplateDef(void);

public:
	size_t getSize();

private:
	size_t size;
};

}

#endif
