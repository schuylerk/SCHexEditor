#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <scaddressgenerator.h>
#include <scbyteoperator.h>
#include <QWheelEvent>
#include <scplaintextedit.h>
#include <QMouseEvent>
#include <schexeditorlogicinterface.h>
#include <QTextBlock>
#include <QTextDocumentFragment>
#include <QGuiApplication>
#include <QClipboard>
#include <sclineedit.h>
#include <QFont>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(SCHexEditorLogicInterface *logic, QWidget *parent = nullptr);
    ~Widget();

    void configUI();
    void configConnect();

private:
    Ui::Widget *ui;
    SCHexEditorLogicInterface *logic;
    QVector<QString> copiedByteArray;
    SCLineEdit *byteEdit;
    int byteEditPositionInBlock = -1;
    QFont font = QFont("Recursive", 14);

private:
    const QRect GetRectForByteEditWhenDoubleClick();
    void byteEditMoveToNext();

private slots:
    void vertivalScrollBarValueChanged();
    void plainTextEditWheelEvent(QWheelEvent* event, SCPlainTextEdit* plainTextEdit);
    void hexPlainTextEditWheelEvent(QWheelEvent* event);
    void addressPlainTextEditWheelEvent(QWheelEvent* event);
    void asciiPlainTextEditWheelEvent(QWheelEvent* event);
    void hexPlainTextEditSelectionChanged();
    void hexPlainTextEditMouseMoveEvent(QMouseEvent* event);
    void hexPlainTextEditCopyFinish();
    void hexPlainTextEditPaste();
    void hexPlainTextEditDoubleClick(QMouseEvent* event);
    void byteEditReturnPressed();
    void byteEditFocusOut();
    void byteEditTextEdited(const QString& text);
};
#endif // WIDGET_H
