#pragma once
#include <windows.h>
#include <vector>
#include <iostream>
#include <string>
#include "../ByteArray.h"
class MessageBase
{
public:
	ByteArray * byteArray;

public:
	MessageBase(void);
	~MessageBase(void);
	void write();

	


};

