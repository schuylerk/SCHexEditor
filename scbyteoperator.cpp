#include "scbyteoperator.h"

const char* SCByteOperator::byteToBinary(unsigned char value)
{
    char* res = new char[9];
    for (int i = 0; i < 7; i++)
    {
        res[i] = '0';
    }
    res[8] = '\0';

    int p = 7;
    while (value)
    {
        res[p--] = (value % 2) + 48;
        value /= 2;
    }
    return res;
}

const char* SCByteOperator::byteToHex(unsigned char value)
{
    const char* hexData = "0123456789ABCDEF";
    char* res = new char[3];
    res[0] = '0';
    res[1] = '0';
    res[2] = '\0';
    int index = 1;
    unsigned char a = value;
    while (a)
    {
        res[index--] = hexData[a % 16];
        a /= 16;
    }
    return res;
}
