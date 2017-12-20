#pragma once
#include "EncodingConverter.h"

class Md5Converter : EncodingConverter
{
public:
    static int Encode(const char* pchCode, int size,
        char* pszBuffer, int bufferSize = 32 + 1);
    static string Encode(string& strCode);

public:
    Md5Converter()
    {
        // Test
        string strBuf("abc");
        string str = Encode(strBuf);
    }

private:
    static int Decode(const char* pchCode, int size,
        char* pszBuffer, int bufferSize) { return -1; }
    static string Decode(string& strCode) { }
};
