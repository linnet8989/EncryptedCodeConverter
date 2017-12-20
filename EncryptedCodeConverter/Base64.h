#pragma once
#include "EncodingConverter.h"
class Base64Converter : public EncodingConverter
{
public:
    static int Encode(char* pchCode, int size,
        char* pzsBuffer, int bufferSize)
    {
        int val = 0;
        //int index = 0;
        int count = 0; 
        int i = 0;

        for (i = 0; i * 3 < size; i++)
        {
            val = 0;
            //index = 0;
            for (count = 0; count < 3; count++)
            {
                if (i * 3 + count >= size)
                {
                    if (count == 1)
                    {
                        //index = (val >> (6 * (3 - count) + 4)) << 4;
                        //index &= 0x3F;
                        pzsBuffer[i * 4 + count] = CodeTable[
                            ((val >> (6 * (3 - count) + 4)) << 4) & 0x3F];
                        pzsBuffer[i * 4 + count + 1] = CodeTable[64];
                        pzsBuffer[i * 4 + count + 2] = CodeTable[64];
                    }
                    else if (count == 2)
                    {
                        //index = (val >> (6 * (3 - count) + 2)) << 2;
                        //index &= 0x3F;
                        pzsBuffer[i * 4 + count] = CodeTable[
                            ((val >> (6 * (3 - count) + 2)) << 2) & 0x3F];
                        pzsBuffer[i * 4 + count + 1] = CodeTable[64];
                    }
                    break;
                }
                val |= (int)pchCode[i * 3 + count] << (8 * (2 - count));
            }

            if (count == 3)
            {
                count++;
            }
            for (size_t j = 0; j < count; j++)
            {
                //index = val >> (6 * (3 - j));
                //index &= 0x3F;
                pzsBuffer[i * 4 + j] = CodeTable[
                    (val >> (6 * (3 - j))) & 0x3F];
            }
        }

        return i * 4;
    };
    static int Decode(char* pchCode, int size, 
        char* pszBuffer, int bufferSize) 
    {
        char c1, c2, c3, c4;
        int i = 0;
        int count = 0;

        while (i < size)
        {
            /* c1 */
            do
            {
                c1 = DecodeTable[pchCode[i++] & 0xff];
            } while (i < size && c1 == -1);
            if (c1 == -1)
                break;

            /* c2 */
            do
            {
                c2 = DecodeTable[pchCode[i++] & 0xff];
            } while (i < size && c2 == -1);
            if (c2 == -1)
                break;

            pszBuffer[count++] = (c1 << 2) | ((c2 & 0x30) >> 4);

            /* c3 */
            do
            {
                c3 = pchCode[i++] & 0xff;
                if (c3 == 61)
                {
                    pszBuffer[count] = '\0';
                    return count;
                }
                c3 = DecodeTable[c3];
            } while (i < size && c3 == -1);
            if (c3 == -1)
                break;

            pszBuffer[count++] = ((c2 & 0XF) << 4) | ((c3 & 0x3C) >> 2);

            /* c4 */
            do
            {
                c4 = pchCode[i++] & 0xff;
                if (c4 == 61)
                {
                    pszBuffer[count] = '\0';
                    return count;
                }
                c4 = DecodeTable[c4];
            } while (i < size && c4 == -1);
            if (c4 == -1)
                break;
            pszBuffer[count++] = ((c3 & 0x03) << 6) | c4;
        }
        pszBuffer[count] = '\0';
        return count;
    };

    static CString Encode(CString& originalCode) {};
    static CString Decode(CString& code) {};

public:
    Base64Converter()
    {
        char szBuf[100] = { '\0' };
        char szBuf2[100] = { '\0' };
        int cnt = Encode("ManMa", 5, szBuf, 100);
        int cnt2 = Decode(szBuf, strlen(szBuf), szBuf2, 100);
    }

private:
    static char CodeTable[];
    static int DecodeTable[];

};
