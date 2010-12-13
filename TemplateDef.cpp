#include "TemplateDef.h"

namespace Bxml {

TemplateDef::TemplateDef(char* data, size_t length, Node::Context context, bool hasAttributes)
{
	size = 0;
}

TemplateDef::~TemplateDef(void)
{
}

size_t TemplateDef::getSize() {
	return size;
}

}
