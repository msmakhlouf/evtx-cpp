#pragma once

#include "Node.h"

namespace Bxml {

class FragmentNode :
	public Node
{
public:
	FragmentNode(char* data, size_t length, Context context);
	~FragmentNode(void);

public:
	std::wstring* toXml();

private:
	char MajorVersion;
	char MinorVersion;
	char Flags;
};

}
