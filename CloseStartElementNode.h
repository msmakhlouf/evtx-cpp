#pragma once

#include "Node.h"
#include <string>

namespace Bxml {

class CloseStartElementNode :
	public Node
{
public:
	CloseStartElementNode(char* data, size_t length);
	~CloseStartElementNode(void);

public:
	std::wstring* toXml();
	bool isLast();
};

}
