#ifndef SCHEXEDITORLOGIC_H
#define SCHEXEDITORLOGIC_H

#include <schexeditorlogicinterface.h>
#include <QFile>
#include <scaddressgenerator.h>
#include <scbyteoperator.h>

class SCHexEditorLogic : public SCHexEditorLogicInterface
{
private:
    QFile* file;
    QString addressText;
    QString hexText;
    QString asciiText;
    qint64 verticalBarMaxmium;
public:
    SCHexEditorLogic(QString filename);
    ~SCHexEditorLogic();
    virtual QString GetAdressText() ;
    virtual QString GetHexText();
    virtual QString GetAsciiText();
    virtual qint64 GetVerticalBarMaxmium();
    virtual QVector<QString> GetByteArrayWithText(QString text);
    virtual qint64 GetAdress(int blockNumber, int position);
    virtual qint64 GetAdressWithPositionInBlock(int blockNumber, int positionInBlock);
    virtual int GetBlockNumber(QString text, int lastBlockNumber);
    virtual QString replaceTextWithBytes(QString text, QVector<QString>& bytes);
    virtual int byteEditPostionInBlockWithSelectionStart(int positionInBlock);
};

#endif // SCHEXEDITORLOGIC_H
