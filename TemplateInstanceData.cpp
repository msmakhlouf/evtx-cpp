#include "TemplateInstanceData.h"

namespace Bxml {

TemplateInstanceData::TemplateInstanceData(char* data, size_t length)
{
	size = 0;
}

TemplateInstanceData::~TemplateInstanceData(void)
{
}

size_t TemplateInstanceData::getSize() {
	return size;
}

}
