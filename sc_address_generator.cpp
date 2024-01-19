#include "sc_address_generator.h"

std::string SCAddressGenerator::nextAddress(size_t gap)
{
    std::string hexData = "0123456789ABCDEF";
    std::string res = "";
    size_t value = cursor;
    cursor += gap;
    while (value)
    {
        res += hexData[value % 16];
        value /= 16;
    }
    while (res.size() < 8)
    {
        res += '0';
    }
    int l = 0, r = res.size() - 1;
    while (l < r)
    {
        int tmp = res[l];
        res[l] = res[r];
        res[r] = tmp;
        l++, r--;
    }
    return res;
}
