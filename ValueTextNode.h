#ifndef _BXML_VALUETEXTNODE_
#define _BXML_VALUETEXTNODE_

#include "Node.h"
#include "CustomTypes.h"

namespace Bxml {

class ValueTextNode :
	public Node
{
public:
	ValueTextNode(char* data, size_t length);
	~ValueTextNode(void);

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

#endif
