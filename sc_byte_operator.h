#ifndef SC_BYTE_OPERATOR_H
#define SC_BYTE_OPERATOR_H

class SCByteOperator
{
private:
#define isprintc(c) (c >= 0x20 && c <= 0x7E)
public:
    SCByteOperator();

    static const char* byteToBinary(unsigned char value);

    static const char* byteToHex(unsigned char value);

    static char GetAscii(unsigned char c)
    {
        return isprintc(c) ? c : '.';
    }
};

#endif // SC_BYTE_OPERATOR_H
