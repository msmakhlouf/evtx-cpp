#ifndef _EVTX_DATATYPES_
#define _EVTX_DATATYPES_

#include "CustomTypes.h"

namespace Evtx {

	enum DataTypes {
		Null = 0x00,		// suppresses optional substitution
		String = 0x01,		// UCS2-LE string
		AnsiString = 0x02,	// ANSI string
		SByte = 0x03,		// signed 8bit integer
		Byte = 0x04,		// unsigned 8bit integer
		Int16 = 0x05,		// signed 16bit integer
		UInt16 = 0x06,		// unsigned 16bit integer
		Int32 = 0x07,		// signed 32bit integer
		UInt32 = 0x08,		// unsigned 32bit integer
		Int64 = 0x09,		// signed 64bit integer
		UInt64 = 0x0a,		// unsigned 64bit integer
		Single = 0x0b,		// single precision floating point number
		Double = 0x0c,		// double precision floating point number
		Boolean = 0x0d,		// true/false, occupies 4 bytes
		Binary = 0x0e,		// stream of binary data
		Guid = 0x0f,		// global unique identifier, 16 bytes
		SizeT = 0x10,		// size_t, either 32 or 64bit wide
		FileTime = 0x11,	// 64 bit, 100ns since 1601-01-01 00:00:00
		SysTime = 0x12,		// 32bit, seconds since 1970-01-01 00:00:00
		Sid = 0x13,			// security identifier (variable length)
		HexInt32 = 0x14,	// 32bit integer in hex notation
		HexInt64 = 0x15,	// 64bit integer in hex notation

		EvtHandle = 0x20,	// event log object
		EvtBXml = 0x21,		// binary XML for an event

		EvtXml = 0x23,		// XML for an event

		StringArray = 0x81,		// array of UCS2-LE strings
		HexInt32Array = 0x94,	// array of HexInt32
		HexInt64Array = 0x95	// array of HexInt64
	};
}

#endif
