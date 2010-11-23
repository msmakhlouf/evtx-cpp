#pragma once

#include "Name.h"
#include "Node.h"

namespace Bxml {

class Attribute
{
public:
	Attribute(char* data, size_t length);
	~Attribute(void);

public:
	std::wstring* toXml();
	size_t getSize();
	bool isLast();

protected:
	size_t appendData(Node* node);

protected:
	Name* name;
	std::vector<Node*>* attributeData;
	bool last;
	size_t size;
	std::wstring* Xml;
};

}
