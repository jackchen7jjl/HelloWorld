#pragma once
#include "ByteArray.h"
#include <string>
using namespace std;

class BytesLoader
{
public:
	void load(string url, void (*loadCompleteCallBack));

};