#ifndef SCHEXEDITORLOGICINTERFACE_H
#define SCHEXEDITORLOGICINTERFACE_H

#include <QString>

class SCHexEditorLogicInterface
{
public:
    virtual QString GetAdressText() = 0;
    virtual QString GetHexText() = 0;
    virtual QString GetAsciiText() = 0;
    virtual qint64 GetVerticalBarMaxmium() = 0;
    virtual qint64 GetAdress(int blockNumber, int position) = 0;
    virtual qint64 GetAdressWithPositionInBlock(int blockNumber, int positionInBlock) = 0;
    virtual int GetBlockNumber(QString text, int lastBlockNumber) = 0;
    virtual QVector<QString> GetByteArrayWithText(QString text) = 0;
    virtual QString replaceTextWithBytes(QString text, QVector<QString>& bytes) = 0;
    virtual int byteEditPostionInBlockWithSelectionStart(int positionInBlock) = 0;
};

#endif // SCHEXEDITORLOGICINTERFACE_H
