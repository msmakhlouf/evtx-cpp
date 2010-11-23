#pragma once

#include "Attribute.h"
#include "CustomTypes.h"

#include <vector>
#include <string>

namespace Bxml {

class AttributeList
{
public:
	AttributeList(char* data, size_t length);
	~AttributeList(void);

public:
	// returns real size of entity in bytes
	size_t getSize();
	// returns declared entity length
	size_t getByteLength();
	std::wstring* toXml();

protected:
	size_t appendAttribute(Attribute* attr);

protected:
	std::wstring* Xml;
	size_t size;
	size_t byteLength;

private:
	std::vector<Attribute*>* attributes;
};

}
