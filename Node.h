#pragma once

#include <vector>
#include <string>

namespace Bxml {

class Node
{
public:
	enum Context {
		Regular = 0x00,
		TemplateDefinition = 0x01
	};

/* public constructors */
public:
	Node(char* data, size_t length, Context context = Regular);
	virtual ~Node(void);

/* public methods */
public:
	virtual std::wstring* toXml();
	virtual size_t getSize();
	virtual bool isLast();

/* public static methods */
public:
	static Node* createNode(char* data, size_t length, Context context = Regular);

/* protected methods */
protected:
	void init();
	size_t appendChild(Node* node);

/* public members */
public:

/* protected members */
protected:
	std::wstring* Xml;
	size_t size;
	bool last;

/* private members */
private:
	std::vector<Node*>* childNodes;
	// TODO: add vector of attributes

/* protected static members */
protected:

/* public static members */
public:
};

}
