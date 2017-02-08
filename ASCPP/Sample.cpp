#include <iostream>
#include <stdio.h>
#include "ByteArray.h"

using namespace std;

void printBytesByte(ByteArray &bytes,int len)
{
	for (int i = 0; i < len; i++)
	{
		char val = bytes.readByte();
		printf("val = %d ", val);
	}
	printf("\n");
}

void printBytesShort(ByteArray &bytes, int len)
{
	for (int i = 0; i < len; i++)
	{
		unsigned short val = bytes.readUnsignedShort();
		printf("val = %d ", val);
	}
	printf("\n");
}

void printBytesInt(ByteArray &bytes, int len)
{
	for (int i = 0; i < len; i++)
	{
		int val = bytes.readInt();
		printf("val = %d ", val);
	}
	printf("\n");
}

void printBytesFloat(ByteArray &bytes, int len)
{
	for (int i = 0; i < len; i++)
	{
		float val = bytes.readFloat();
		printf("val = %f ", val);
	}
	printf("\n");
}


int main()
{
	unsigned char data[1024];
	for (int i = 0; i < 1024; i++)
	{
		data[i] = (char)(i%255);
	}

	ByteArray bytes(data,1024);

	printBytesByte(bytes, 7);

	bytes.setPosition(0);
	printBytesShort(bytes, 7);

	bytes.setPosition(0);
	for (int i = 0; i < 7; i++)
	{
		bytes.writeByte(i + 10);
	}

	bytes.setPosition(0);
	printBytesByte(bytes, 7);


	bytes.setPosition(0);
	for (int i = 0; i < 7; i++)
	{
		bytes.writeUnsignedShort(50000 + i);
	}
	bytes.setPosition(0);
	printBytesShort(bytes, 5);



	bytes.setPosition(0);
	for (int i = 0; i < 3; i++)
	{
		bytes.writeInt(-100000 + i);
	}
	bytes.setPosition(0);
	printBytesInt(bytes, 3);


	bytes.setPosition(0);
	for (int i = 0; i < 3; i++)
	{
		bytes.writeFloat(0.562 + i);
	}
	bytes.setPosition(0);
	printBytesFloat(bytes, 3);



	cin.get();
	cin.get();
	return 0;
}