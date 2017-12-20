#pragma once
#include <afx.h>
#include<string>
using namespace std;

class EncodingConverter
{
public:
    static int Encode(char* pchCode, int size,
        char* pszBuffer, int bufferSize)
    {
        return -1;
    };
    static int Decode(char* pchCode, int size,
        char* pszBuffer, int bufferSize)
    {
        return -1;
    };
    static string Encode(string& strCode)
    {
        return string();
    }
    static string Decode(string& strCode)
    {
        return string();
    }

public:
    EncodingConverter();
    ~EncodingConverter();
};

