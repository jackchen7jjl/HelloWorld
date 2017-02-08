#pragma once
using namespace std;

class ByteArray
{
public:
	ByteArray();
	ByteArray(unsigned char *data, int length);
	~ByteArray();

	char readByte();
	short readShort();
	int readInt();

	unsigned char readUnsignedByte();
	unsigned short readUnsignedShort();
	unsigned int readUnsignedInt();

	float readFloat();

	void writeByte(char value);
	void writeShort(short value);
	void writeInt(int value);

	void writeUnsignedByte(unsigned char value);
	void writeUnsignedShort(unsigned short value);
	void writeUnsignedInt(unsigned int value);

	void writeFloat(float value);

	unsigned int getPosition();
	void setPosition(unsigned int value);

	unsigned int getLength();
	void setLength(unsigned int value);

	unsigned int getBytesAvailable();

	char getEndian();
	void setEndian(char value);

private:
	unsigned char *data;
	unsigned int position;
	unsigned int length;
	unsigned int bytesAvailable;
	char endian;

	bool isOutofSize(int trySize);
};