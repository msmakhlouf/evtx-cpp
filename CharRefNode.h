#pragma once

#include "CustomTypes.h"
#include "Node.h"

namespace Bxml {

class CharRefNode :
	public Node
{
public:
	CharRefNode(char* data, size_t length);
	~CharRefNode(void);

public:
	std::wstring* toXml();
	bool isLast();

protected:
	uint16 value;
};

}
