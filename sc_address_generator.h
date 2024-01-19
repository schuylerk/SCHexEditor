#ifndef SCADDRESSGENERATORH_H
#define SCADDRESSGENERATORH_H

#include <string>

class SCAddressGenerator
{
private:
    size_t capacity;
    size_t cursor;
public:
    SCAddressGenerator(size_t capacity) : capacity(capacity), cursor(0) {}

    std::string nextAddress(size_t gap = 1);

    bool end()
    {
        return cursor >= capacity;
    }
};

#endif // SCADDRESSGENERATORH_H
