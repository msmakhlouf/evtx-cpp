#pragma once

#include "CustomTypes.h"

#include <string>

namespace Bxml {

class Name
{
public:
	Name(char* data, size_t length);
	~Name(void);

public:
	size_t getSize(void);
	size_t getLength(void);
	std::wstring* toXml();

protected:
	uint16 nameHash;
	uint16 length;
	wchar_t *string;
	std::wstring* Xml;
};

}
