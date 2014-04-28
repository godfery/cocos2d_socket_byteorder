#pragma once
/*
 * ByteArray.h
 *
 *  Created on: 2012-11-12
 *      Author: RockyF
 */

#ifndef BYTEARRAY_H_
#define BYTEARRAY_H_

#include <windows.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

enum Endian{
	SYS_ENDIAN,
	BIG_ENDIAN,
	LIT_ENDIAN
};

class ByteArray {
private:
	//byte *_bytes;
public:
	byte *_bytes;
	long writePosition;
	long readPosintion;

	ByteArray(int maxSize);
	virtual ~ByteArray();

	Endian writeEndian;
	Endian readEndian;

	//-----Write-------------
	byte getData();
	void writeInt(int i);

	void writeByte(byte val);
	void writeBytes(byte *val, long size, long offset = 0);
	template <class Number>
	int writeNumber(Number val){
		byte bytes[sizeof(val)];
		int size = numberToBytes(val, bytes, writeEndian);

		writeBytes(bytes, size);
		return size;
	}

	void writeString(string *val);
	void writeChars(char * val);
	void write4BChars(char * val);
	void writeBool(bool val);

	//-----Read-------------
	int readInt();
	byte readByte();
	void readBytes(byte *val, long size, long offset = 0);
	template <class Number>
	int readNumber(Number *val){
		int size = sizeof(*val);
		byte *bytes=new byte[size];
		readBytes(bytes, size);

		bytesToNumber(val, bytes, readEndian);

		return size;
		//return 4;
	}

	void readChars(char * val, long size, long offset = 0);
	void read4BChars(char * val);
	string readString();
	void readBool(bool * val);

	//-----Utils-------------
	long getAvailable();

	void setEndian(Endian writeEndian, Endian readEndian);

	template <class T>
	int numberToBytes(T val, byte *bytes, Endian endian){
		int size = sizeof(val);

		*(T*) bytes = val;

		if (endian == SYS_ENDIAN || endian == getCPUEndian()) {
			return size;
		} else {
			reversalArray(bytes, size);
			return size;
		}
	}
	template <class T>
	int bytesToNumber(T val, byte *bytes, Endian endian){
		int size = sizeof(*val);

		if (endian == SYS_ENDIAN || endian == getCPUEndian()) {
		} else {
			reversalArray(bytes, size);
		}

		*val = *(T)bytes;

		return size;
	}

	//-----Static-------------
	static Endian getCPUEndian();
	static void reversalArray(byte * bytes, long size);
};

#endif /* BYTEARRAY_H_ */

