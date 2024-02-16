#include "schexeditorlogic.h"

SCHexEditorLogic::SCHexEditorLogic(QString filename)
{
    file = new QFile(filename);
    file->open(QIODeviceBase::ReadOnly);

    QString addressText;
    qint64 scrollBarMaximum = 0;
    SCAddressGenerator g(file->size());
    while(!g.end())
    {
        std::string address = g.nextAddress(16);
        addressText += address + "\n";
        scrollBarMaximum += 1;
    }
    this->addressText = addressText;
    this->verticalBarMaxmium = scrollBarMaximum;

    QString hexText;
    QString asciiText;
    char c;
    qint64 count = 0;
    while(file->getChar(&c))
    {
        const char* hex = SCByteOperator::byteToHex(c);
        hexText += hex;
        asciiText += SCByteOperator::GetAscii(c);
        count++;
        if (count == 16)
        {
            count = 0;
            hexText += '\n';
            asciiText += '\n';
        }
        else
        {
            int spaceCount = (count == 8 ? 4 : 2);
            for (int i = 0; i < spaceCount; i++)
            {
                hexText += ' ';
            }
        }
    }
    this->hexText = hexText;
    this->asciiText = asciiText;
}

SCHexEditorLogic::~SCHexEditorLogic()
{
    file->close();
    delete file;
}

QString SCHexEditorLogic::GetAdressText()
{
    return addressText;
}

QString SCHexEditorLogic::GetHexText()
{
    return hexText;
}

QString SCHexEditorLogic::GetAsciiText()
{
    return asciiText;
}

qint64 SCHexEditorLogic::GetVerticalBarMaxmium()
{
    return verticalBarMaxmium;
}

QVector<QString> SCHexEditorLogic::GetByteArrayWithText(QString text)
{
    QVector<QString> res;
    QString item = "";
    int size = text.size();
    for (int i = 0; i < size; i++)
    {
        if (text[i] == ' ' || text[i] == '\n')
        {
            if (item == "")
                continue;
            if (item.size() == 2)
                res.append(item);
            item = "";
            continue;
        }
        else
        {
            item += text[i];
        }
        if (i == size-1 && item.size() == 2)
        {
            res.append(item);
        }
    }
    return res;
}

qint64 SCHexEditorLogic::GetAdressWithPositionInBlock(int blockNumber, int positionInBlock)
{
    //00  00  00  00  00  00  00  00    00  00  00  00  00  00  00  00
    int a[] = {0, 4, 8, 12, 16, 20, 24, 28, 34, 38, 42, 46, 50, 54, 58, 62, -1};
    int res = blockNumber*16-1;
    for (int i = 0; a[i] != -1; i++)
    {
        if (positionInBlock <= a[i])
        {
            res += i+1;
            break;
        }
    }
    return res;
}

qint64 SCHexEditorLogic::GetAdress(int blockNumber, int position)
{
    int positionInBlock = position % 65;
    int res = GetAdressWithPositionInBlock(blockNumber, positionInBlock);
    return res;
}

/*
 * text是文档中一段连续的数据,
 * blockNumber代表text在文档中的最后一行序号,
 * 返回text在文档中第一行序号
 */
int SCHexEditorLogic::GetBlockNumber(QString text, int lastBlockNumber)
{
    int lineCount = 1;
    int size = text.size();
    for (int i = 0; i < size; i++)
    {
        if (text[i] == '\n')
            lineCount++;
    }
    return lastBlockNumber - lineCount + 1;
}

QString SCHexEditorLogic::replaceTextWithBytes(QString text, QVector<QString>& bytes)
{
    QString res = text;
    int size = res.size();
    int count = 0;
    int p = 0;
    for (int i = 0; i < size; i++)
    {
        if (res[i] == ' ' || res[i] == '\n')
        {
            count = 0;
            continue;
        }
        count++;
        if (count == 2)
        {
            if (p >= bytes.size())
                break;
            res[i-1] = bytes[p][0];
            res[i] = bytes[p][1];
            p++;
            count = 0;
        }
    }
    return res;
}

int SCHexEditorLogic::byteEditPostionInBlockWithSelectionStart(int positionInBlock)
{
    int res = GetAdressWithPositionInBlock(0, positionInBlock);
    return res;
}
