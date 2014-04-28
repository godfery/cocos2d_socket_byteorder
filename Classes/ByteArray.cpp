//#include "ByteArray.h"

/*
 * ByteArray.cpp
 *
 *  Created on: 2012-11-12
 *      Author: RockyF
 */

#include "ByteArray.h"

ByteArray::ByteArray(int maxSize) {
	writePosition = 0;
	readPosintion = 0;
	
	_bytes =new byte[maxSize];
	//_bytes = tb;
	
	Endian cpuEndian = getCPUEndian();
	setEndian(cpuEndian, cpuEndian);
}

ByteArray::~ByteArray() {
	free(_bytes);
}

long ByteArray::getAvailable() {
	return writePosition - readEndian;
}

void ByteArray::writeByte(byte val) {
	writeBytes(&val, 1);
}
byte ByteArray::getData() {

	return *_bytes;


}
void ByteArray::writeInt(int i) {
	//memset(bytes,0,sizeof(byte) *  size);
    _bytes[writePosition++] = (byte) (0xff & i);
    _bytes[writePosition++] = (byte) ((0xff00 & i) >> 8);
    _bytes[writePosition++] = (byte) ((0xff0000 & i) >> 16);
    _bytes[writePosition++] = (byte) ((0xff000000 & i) >> 24);

	 /*_bytes[writePosition++] = (byte) ( i);
    _bytes[writePosition++] = (byte) (( i) >> 8);
    _bytes[writePosition++] = (byte) (( i) >> 16);
    _bytes[writePosition++] = (byte) (( i) >> 24);
		*/
}
void ByteArray::writeBytes(byte *val, long size, long offset) {
	byte * srcByte = val + offset;
	byte * desByte = _bytes + writePosition;
	memcpy(desByte, srcByte, size);

	writePosition += size;
}

void ByteArray::writeString(string * val){
	write4BChars((char *)val->c_str());
}

void ByteArray::writeChars(char * val){
	writeBytes((byte *)val, (int)strlen(val), 0);
}

void ByteArray::write4BChars(char * val){
	int size = strlen(val);
	writeNumber(size);
	writeBytes((byte *)val, size, 0);
}

void ByteArray::writeBool(bool val){
	writeBytes((byte *)&val, 1, 0);
}

byte ByteArray::readByte() {
	byte *val;
	readBytes(val, 1);
	return *val;
}

void ByteArray::readBytes(byte *val, long size, long offset) {
	byte * desByte = val + offset;
	byte * srcByte = _bytes + readPosintion;
	memcpy(desByte, srcByte, size);
	readPosintion += size;
}

void ByteArray::readChars(char *val, long size, long offset) {
	readBytes((byte*)val, size, offset);
}

string ByteArray::readString() {
	int size;
	readNumber(&size);
	char *chars=new char[size + 1];
	readBytes((byte*)chars, size, 0);
	string str(chars);
	return str;
	
	//return "";
}

void ByteArray::read4BChars(char *val) {
	int size;
	readNumber(&size);
	readBytes((byte*)val, size, 0);
}

void ByteArray::readBool(bool * val){
	readBytes((byte*)val, 1, 0);
}

void ByteArray::setEndian(Endian writeEndian, Endian readEndian) {
	this->writeEndian = writeEndian;
	this->readEndian = readEndian;
}

Endian ByteArray::getCPUEndian() {
	union {
		short s;
		char c[sizeof(short)];
	} un;
	un.s = 0x0102;
	if (un.c[0] == 0x2) {
		return LIT_ENDIAN;
	} else {
		return BIG_ENDIAN;
	}
}

void ByteArray::reversalArray(byte * bytes, long size) {
	for (int i = 0; i < size / 2; i++) {
		byte tb;
		tb = *(bytes + i);
		*(bytes + i) = *(bytes + size - i - 1);
		*(bytes + size - i - 1) = tb;
	}
}


