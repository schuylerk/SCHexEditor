#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <scaddressgenerator.h>
#include <scbyteoperator.h>
#include <QWheelEvent>
#include <customwidget/scplaintextedit.h>
#include <QMouseEvent>
#include <schexeditorlogicinterface.h>
#include <QTextBlock>
#include <QTextDocumentFragment>
#include <QGuiApplication>
#include <QClipboard>
#include <customwidget/sclineedit.h>
#include <QFont>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class EditorMainWidget : public QWidget
{
    Q_OBJECT

public:
    EditorMainWidget(SCHexEditorLogicInterface *logic, QWidget *parent = nullptr);
    ~EditorMainWidget();

    void configUI();
    void configConnect();

private:
    Ui::Widget *ui;
    SCHexEditorLogicInterface *logic;
    QVector<QString> copiedByteArray;
    SCLineEdit *byteEdit;
    int byteEditPositionInBlock = -1;
    QFont font = QFont("Fixedsys", 12);

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
