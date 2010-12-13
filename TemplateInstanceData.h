#ifndef _BXML_TEMPLATEDATA_
#define _BXML_TEMPLATEDATA_

namespace Bxml {

class TemplateInstanceData
{
public:
	TemplateInstanceData(char* data, size_t length);
	~TemplateInstanceData(void);

public:
	size_t getSize();

private:
	size_t size;
};

}

#endif
