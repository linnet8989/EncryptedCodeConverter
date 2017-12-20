#pragma once
#include "EncodingConverter.h"

class Base64Converter : public EncodingConverter
{
public:
    static int Encode(const char* pchCode, int size,
        char* pzsBuffer, int bufferSize);
    static int Decode(const char* pchCode, int size,
        char* pszBuffer, int bufferSize);

    static string Encode(string& strCode);
    static string Decode(string& strCode);

public:
    Base64Converter()
    {
        // Test
        string strBuf("ManMa");
        char szBuf[100] = { '\0' };
        char szBuf2[100] = { '\0' };
        int cnt = Encode(strBuf.c_str(), 5, szBuf, 100);
        int cnt2 = Decode(szBuf, strlen(szBuf), szBuf2, 100);
        string str = Encode(strBuf);
        string str2 = Decode(str);
    }

private:
    static char CodeTable[];
    static int DecodeTable[];

};
