#ifndef _BXML_TOKENS_
#define _BXML_TOKENS_

namespace Bxml {

	enum Tokens {
		EndOfFile = 0x00,
		OpenStartElement = 0x01,
		OpenStartElementAttr = 0x41,
		CloseStartElement = 0x02,
		CloseEmptyElement = 0x03,
		EndElement = 0x04,
		ValueTextLast = 0x05,
		ValueText = 0x45,
		AttributeLast = 0x06,
		Attribute = 0x46,
		CDATASectionLast = 0x07,
		CDATASection = 0x47,
		CharRefLast = 0x08,
		CharRef = 0x48,
		EntityRefLast = 0x09,
		EntityRef = 0x49,
		PITarget = 0x0a,
		PIData = 0x0b,
		TemplateInstance = 0x0c,
		NormalSubstitution = 0x0d,
		OptionalSubstitution = 0x0e,
		FragmentHeader = 0x0f
	};

}

#endif
