#ifndef _BXML_TEMPLATEINSTANCE_
#define _BXML_TEMPLATEINSTANCE_

#include "Node.h"
#include "TemplateDef.h"
#include "TemplateInstanceData.h"

namespace Bxml {

class TemplateInstanceNode :
	public Node
{
public:
	TemplateInstanceNode(char* data, size_t length, Context context, bool hasAttributes = ATTR_NO_ATTRIBUTES);
	~TemplateInstanceNode(void);

public:
	std::wstring* toXml();

protected:
	// TODO: merge this class with TemplateDef
	TemplateDef* tdef;
	TemplateInstanceData* tdata;
};

}

#endif
