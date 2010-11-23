#pragma once

#include "Node.h"
#include "CustomTypes.h"

namespace Bxml {

class CDATASectionNode :
	public Node
{
public:
	CDATASectionNode(char* data, size_t length);
	~CDATASectionNode(void);

public:
	// returns content string length
	size_t getLength();
	std::wstring* toXml();
	bool isLast();

protected:
	wchar_t* string;
	uint16 length;
};

}
