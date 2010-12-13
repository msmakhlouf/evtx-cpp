#include "TemplateInstanceNode.h"

#include "CustomTypes.h"

namespace Bxml {

TemplateInstanceNode::TemplateInstanceNode(char* data, size_t length, Context context, bool hasAttributes) :
	Node(data, length, context)
{
	size += sizeof byte;
	tdef = new TemplateDef(data+size, length-size, context, hasAttributes);
	size += tdef->getSize();

	tdata = new TemplateInstanceData(data+size, length-size);
	size += tdata->getSize();
}

TemplateInstanceNode::~TemplateInstanceNode(void)
{
}

std::wstring* TemplateInstanceNode::toXml() {
	// TODO: remove this stub
	return NULL;
}

}
