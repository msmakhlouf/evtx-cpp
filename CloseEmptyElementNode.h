#pragma once

#include "Node.h"

namespace Bxml {

class CloseEmptyElementNode :
	public Node
{
public:
	CloseEmptyElementNode(char* data, size_t length);
	~CloseEmptyElementNode(void);

public:
	std::wstring* toXml();
	bool isLast();
};

}
