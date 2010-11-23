#pragma once

#include "Node.h"

namespace Bxml {

class EndElementNode :
	public Node
{
public:
	EndElementNode(char* data, size_t length);
	~EndElementNode(void);

public:
	std::wstring* toXml();
	bool isLast();
};

}
