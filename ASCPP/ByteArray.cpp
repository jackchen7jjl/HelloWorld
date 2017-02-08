#include "ByteArray.h"
#include "Endian.h"

ByteArray::ByteArray()
{
	length = 1024;
	data = new unsigned char[1024];
	setPosition(0);
	endian = Endian::LITTLE_ENDIAN;
}

ByteArray::ByteArray(unsigned char *data,int length)
{
	this->length = length;
	this->data = new unsigned char[length];
	memcpy(this->data, data, length);
	setPosition(0);
	endian = Endian::LITTLE_ENDIAN;
}

ByteArray::~ByteArray()
{
	delete []data;
}

char ByteArray::readByte()
{
	if (isOutofSize(1))
		return 0;
	else
	{
		char result = data[position];
		setPosition(position+1);
		return result;
	}		
}

short ByteArray::readShort()
{
	if (isOutofSize(2))
		return 0;
	else
	{
		short result;
		if(endian == Endian::BIG_ENDIAN)
			result = (data[position]<<8) + data[position+1];
		else
			result = (data[position + 1] << 8) + data[position];
		setPosition(position + 2);
		return result;
	}		
}

int ByteArray::readInt()
{
	if (isOutofSize(4))
		return 0;
	else
	{
		int result;
		if (endian == Endian::BIG_ENDIAN)
			result = (data[position]<<24) + (data[position + 1]<<16) + (data[position + 2]<<8) + data[position + 3];
		else
			result = (data[position + 3]<< 24) + (data[position + 2] << 16) + (data[position + 1] << 8) + data[position];
		setPosition(position + 4);
		return result;
	}
}

unsigned char ByteArray::readUnsignedByte()
{
	if (isOutofSize(1))
		return 0;
	else
	{
		unsigned char result = data[position];
		setPosition(position + 1);
		return result;
	}
}

unsigned short ByteArray::readUnsignedShort()
{
	if (isOutofSize(2))
		return 0;
	else
	{
		unsigned short result;
		if (endian == Endian::BIG_ENDIAN)
			result = (data[position] << 8) + data[position + 1];
		else
			result = (data[position + 1] << 8) + data[position];
		setPosition(position + 2);
		return result;
	}
}

unsigned int ByteArray::readUnsignedInt()
{
	if (isOutofSize(4))
		return 0;
	else
	{
		unsigned int result;
		if (endian == Endian::BIG_ENDIAN)
			result = (data[position] << 24) + (data[position + 1] << 16) + (data[position + 2] << 8) + data[position + 3];
		else
			result = (data[position + 3] << 24) + (data[position + 2] << 16) + (data[position + 1] << 8) + data[position];
		setPosition(position + 4);
		return result;
	}
}

float ByteArray::readFloat()
{
	if (isOutofSize(4))
		return 0;
	else
	{ 
		float result = 0.0;
		memcpy(&result, data + position, sizeof(float));
		setPosition(position + 4);
		return result;
	}
}

void ByteArray::writeByte(char value)
{
	writeUnsignedByte(value);
}

void ByteArray::writeUnsignedByte(unsigned char value)
{
	if (!isOutofSize(1))
	{
		data[position++] = value;
		bytesAvailable--;
	}
}

void ByteArray::writeShort(short value)
{
	writeUnsignedShort(value);
}

void ByteArray::writeUnsignedShort(unsigned short value)
{
	if (!isOutofSize(2))
	{
		char ch0 = (value & 0xff00) >> 8;
		char ch1 = value & 0xff;

		if (endian == Endian::BIG_ENDIAN)
		{
			data[position++] = ch0;
			data[position ++] = ch1;
		}
		else
		{
			data[position++] = ch1;
			data[position++] = ch0;
		}
		bytesAvailable -= 2;
	}
}

void ByteArray::writeInt(int value)
{
	writeUnsignedInt(value);
}

void ByteArray::writeUnsignedInt(unsigned int value)
{
	if (!isOutofSize(4))
	{
		char ch0 = (value & 0xff000000) >> 24;
		char ch1 = (value & 0xff0000) >> 16;
		char ch2 = (value & 0xff00) >> 8;
		char ch3 = value & 0xff;

		if (endian == Endian::BIG_ENDIAN)
		{
			data[position++] = ch0;
			data[position++] = ch1;
			data[position++] = ch2;
			data[position++] = ch3;
		}
		else
		{
			data[position++] = ch3;
			data[position++] = ch2;
			data[position++] = ch1;
			data[position++] = ch0;
		}
		bytesAvailable -= 4;
	}
}

void ByteArray::writeFloat(float value)
{
	if (!isOutofSize(4))
	{
		memcpy(data + position, &value, sizeof(float));
		setPosition(position + 4);
	}
}

unsigned int ByteArray::getPosition()
{
	return position;
}

void ByteArray::setPosition(unsigned int value)
{
	if(value > length)
		position = length;
	else
		position = value;
	bytesAvailable = length - position;
}

unsigned int ByteArray::getLength()
{
	return length;
}

void ByteArray::setLength(unsigned int value)
{
	if (length != value)
	{
		delete[]data;
		length = value;
		data = new unsigned char[length];
		setPosition(0);		
	}
}

unsigned int ByteArray::getBytesAvailable()
{
	return bytesAvailable;
}

char ByteArray::getEndian()
{
	return endian;
}

void ByteArray::setEndian(char value)
{
	endian = value;
}

bool ByteArray::isOutofSize(int trySize)
{
	if (trySize + position >= length)
		return true;
	else
		return false;
}