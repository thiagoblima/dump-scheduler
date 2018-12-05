#include <cstdio>
#include <cctype>

void hexDump(void *pAddressIn, long  lSize)
{
    char szBuf[100];
    long lIndent = 1;
    long lOutLen, lIndex, lIndex2, lOutLen2;
    long lRelPos;
    struct { char *pData; unsigned long lSize; } buf{};
    unsigned char *pTmp,ucTmp;
    auto *pAddress = (unsigned char *)pAddressIn;

    buf.pData   = (char *)pAddress;
    buf.lSize   = static_cast<unsigned long>(lSize);

    while (buf.lSize > 0)
    {
        pTmp     = (unsigned char *)buf.pData;
        lOutLen  = (int)buf.lSize;
        if (lOutLen > 16)
            lOutLen = 16;

        // create a 64-character formatted output line:
        sprintf(szBuf, " >                            "
                       "                      "
                       "    %08lX", pTmp-pAddress);
        lOutLen2 = lOutLen;

        for(lIndex = 1+lIndent, lIndex2 = 53-15+lIndent, lRelPos = 0;
            lOutLen2;
            lOutLen2--, lIndex += 2, lIndex2++
                )
        {
            ucTmp = *pTmp++;

            sprintf(szBuf + lIndex, "%02X ", (unsigned short)ucTmp);
            if(!isprint(ucTmp))  ucTmp = '.'; // nonburnable char
            szBuf[lIndex2] = ucTmp;

            if (!(++lRelPos & 3))     // extra blank after 4 bytes
            {  lIndex++; szBuf[lIndex+2] = ' '; }
        }

        if (!(lRelPos & 3)) lIndex--;

        szBuf[lIndex  ]   = '<';
        szBuf[lIndex+1]   = ' ';

        printf("%s\n", szBuf);

        buf.pData   += lOutLen;
        buf.lSize   -= lOutLen;
    }
}

int main()
{
    char abStack[100];

    printf("Dump of abStack:\n");
    hexDump(abStack, 100);
}
