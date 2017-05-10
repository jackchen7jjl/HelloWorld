#include <iostream>
#include <windows.h>

using namespace std;

char * UnicodeToAnsi(const wchar_t* buf)
{
	int len = WideCharToMultiByte(CP_ACP, 0, buf, -1, NULL, 0, NULL, NULL);
	if (len == 0) return "";

	char *utf8 = new char[len];
	WideCharToMultiByte(CP_ACP, 0, buf, -1, utf8, len, NULL, NULL);

	return utf8;
}

char *  UnicodeToUtf8(const wchar_t* buf)
{
	int len = WideCharToMultiByte(CP_UTF8, 0, buf, -1, NULL, 0, NULL, NULL);
	if (len == 0) return "";

	char *utf8 = new char[len];
	WideCharToMultiByte(CP_UTF8, 0, buf, -1, utf8, len, NULL, NULL);

	return utf8;
}

wchar_t * AnsiToUnicode(const char* buf)
{
	int len = ::MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);
	if (len == 0) return L"";

	wchar_t * unicode = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, buf, -1, &unicode[0], len);

	return unicode;
}

wchar_t *  Utf8ToUnicode(const char* buf)
{
	int len = ::MultiByteToWideChar(CP_UTF8, 0, buf, -1, NULL, 0);
	if (len == 0) return L"";

	wchar_t * unicode = new wchar_t[len];
	MultiByteToWideChar(CP_UTF8, 0, buf, -1, &unicode[0], len);

	return unicode;
}

template <typename T>
void printChar(T *ch)
{
	while (*ch != 0)
	{
		if(*ch > 255)
			cout << dec << (int(*ch)&65535) << " ";
		else
			cout << hex << (int(*ch) & 255) << " ";
		ch++;
	}
	cout << endl;
}


int main()
{
	wchar_t *ch0 = L"ÖÐ¹úabc";
	wcout << ch0 << endl;

	char *ch1 = UnicodeToAnsi(ch0);

	char *ch2 = UnicodeToUtf8(ch0);

	printChar(ch0);
	printChar(ch1);
	printChar(ch2);

	cout << ch1 << endl;

	char *ch = new char[100];


	cin >> ch; 
	 
	printChar(ch);

	wchar_t *ch4 = AnsiToUnicode(ch);
	printChar(ch4);

	cout << ch << endl;

	cin.get();
	cin.get();
	return 0;
}