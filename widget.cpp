#include "widget.h"
#include "ui_widget.h"
#include <QTextOption>

Widget::Widget(SCHexEditorLogicInterface *logic, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , logic(logic)
{
    ui->setupUi(this);
    configUI();
    configConnect();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::configUI()
{
    setWindowTitle("HexEditor");

    ui->addressPlainTextEdit->setReadOnly(true);
    ui->hexPlainTextEdit->setReadOnly(true);
    ui->asciiPlainTextEdit->setReadOnly(true);

    ui->addressPlainTextEdit->setFrameShape(QFrame::NoFrame);
    ui->hexPlainTextEdit->setFrameShape(QFrame::NoFrame);
    ui->asciiPlainTextEdit->setFrameShape(QFrame::NoFrame);

    QFontDatabase::addApplicationFont(":/fonts/Recursive_VF_1.085.ttf");

    ui->addressPlainTextEdit->setFont(font);
    ui->hexPlainTextEdit->setFont(font);
    ui->asciiPlainTextEdit->setFont(font);
    ui->label_address->setFont(font);
    ui->label_ascii->setFont(font);
    ui->label_byte->setFont(font);

    ui->verticalScrollBar->setMaximum(logic->GetVerticalBarMaxmium());
    ui->addressPlainTextEdit->setPlainText(logic->GetAdressText());
    ui->hexPlainTextEdit->setPlainText(logic->GetHexText());
    ui->asciiPlainTextEdit->setPlainText(logic->GetAsciiText());

    ui->addressPlainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);
    ui->asciiPlainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);

    ui->hexPlainTextEdit->setContextMenuPolicy(Qt::CustomContextMenu); // QPlainTextEdit 鼠标右击菜单

    byteEdit = new SCLineEdit(this);
    byteEdit->setFont(font);
    byteEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
    byteEdit->setStyleSheet("color:white;background-color:black");
    byteEdit->hide();
}

void Widget::configConnect()
{
    connect(ui->verticalScrollBar, &QScrollBar::valueChanged, this, &Widget::vertivalScrollBarValueChanged);
    connect(ui->hexPlainTextEdit, &SCPlainTextEdit::wheelEventHandle, this, &Widget::hexPlainTextEditWheelEvent);
    connect(ui->addressPlainTextEdit, &SCPlainTextEdit::wheelEventHandle, this, &Widget::addressPlainTextEditWheelEvent);
    connect(ui->asciiPlainTextEdit, &SCPlainTextEdit::wheelEventHandle, this, &Widget::asciiPlainTextEditWheelEvent);
    connect(ui->hexPlainTextEdit, &SCPlainTextEdit::selectionChanged, this, &Widget::hexPlainTextEditSelectionChanged);
    connect(ui->hexPlainTextEdit, &SCPlainTextEdit::mouseMoveEventHandle, this, &Widget::hexPlainTextEditMouseMoveEvent);
    connect(ui->hexPlainTextEdit, &SCPlainTextEdit::copyFinish, this, &Widget::hexPlainTextEditCopyFinish);
    connect(ui->hexPlainTextEdit, &SCPlainTextEdit::readyPaste, this, &Widget::hexPlainTextEditPaste);
    connect(ui->hexPlainTextEdit, &SCPlainTextEdit::mouseDoubleClickEventHandle, this, &Widget::hexPlainTextEditDoubleClick);
    connect(byteEdit, &QLineEdit::returnPressed, this, &Widget::byteEditReturnPressed);
    connect(byteEdit, &SCLineEdit::focusOutEventHandle, this, &Widget::byteEditFocusOut);
    connect(byteEdit, &QLineEdit::textEdited, this, &Widget::byteEditTextEdited); //一定得是textEdited，不能时textChanged
}

void Widget::vertivalScrollBarValueChanged()
{
    int value = ui->verticalScrollBar->value();
    ui->addressPlainTextEdit->verticalScrollBar()->setValue(value);
    ui->hexPlainTextEdit->verticalScrollBar()->setValue(value);
    ui->asciiPlainTextEdit->verticalScrollBar()->setValue(value);

    byteEdit->hide();
}

void Widget::plainTextEditWheelEvent(QWheelEvent* event, SCPlainTextEdit* plainTextEdit)
{
    // 实现三个QPlainTextEdit及QScrollBar联动
    int value = plainTextEdit->verticalScrollBar()->value();
    ui->addressPlainTextEdit->verticalScrollBar()->setValue(value);
    ui->hexPlainTextEdit->verticalScrollBar()->setValue(value);
    ui->asciiPlainTextEdit->verticalScrollBar()->setValue(value);
    ui->verticalScrollBar->setValue(value);

    byteEdit->hide();
}

void Widget::hexPlainTextEditWheelEvent(QWheelEvent* event)
{
    plainTextEditWheelEvent(event, ui->hexPlainTextEdit);
}

void Widget::addressPlainTextEditWheelEvent(QWheelEvent* event)
{
    plainTextEditWheelEvent(event, ui->addressPlainTextEdit);
}

void Widget::asciiPlainTextEditWheelEvent(QWheelEvent* event)
{
    plainTextEditWheelEvent(event, ui->asciiPlainTextEdit);
}

void Widget::hexPlainTextEditSelectionChanged()
{
//    qDebug() << ui->hexPlainTextEdit->textCursor().position();
//    qDebug() << ui->hexPlainTextEdit->textCursor().positionInBlock();
//    qDebug() << ui->hexPlainTextEdit->textCursor().blockNumber();
//    qDebug() << ui->hexPlainTextEdit->textCursor().block().text();
//    qDebug() << ui->hexPlainTextEdit->textCursor().selectionStart();
//    qDebug() << ui->hexPlainTextEdit->textCursor().selectionEnd();
//    qDebug() << ui->hexPlainTextEdit->textCursor().currentList();
}

void Widget::hexPlainTextEditMouseMoveEvent(QMouseEvent* event)
{
//    qDebug() << "mouse move";
}

void Widget::hexPlainTextEditCopyFinish()
{
    QString originalText = QGuiApplication::clipboard()->text();
//    int startBlockNumber = logic->GetBlockNumber(originalText, ui->hexPlainTextEdit->textCursor().blockNumber());
//    int selectionStart = ui->hexPlainTextEdit->textCursor().selectionStart();
//    //复制文本中第一个有效字节的地址
//    qint64 firstByteAddress = logic->GetAdress(startBlockNumber, selectionStart);
    //复制文本中的字节组成的数组
    copiedByteArray = logic->GetByteArrayWithText(originalText);
}

void Widget::hexPlainTextEditPaste()
{
    qDebug() << "paste";
    QString selectedText = ui->hexPlainTextEdit->textCursor().selectedText();
    if (selectedText == "")
        return;
    QString newText = logic->replaceTextWithBytes(selectedText, copiedByteArray);
    ui->hexPlainTextEdit->textCursor().removeSelectedText();
    ui->hexPlainTextEdit->textCursor().insertText(newText);
}

void Widget::hexPlainTextEditDoubleClick(QMouseEvent* event)
{
    const QRect rect = GetRectForByteEditWhenDoubleClick();
    QString selectedText = ui->hexPlainTextEdit->textCursor().selectedText();
    int selectionStartInBlock = ui->hexPlainTextEdit->textCursor().positionInBlock()-2;
    byteEditPositionInBlock = logic->byteEditPostionInBlockWithSelectionStart(selectionStartInBlock);
    // 双击后会选中两个字节，执行这个操作可以取消选中，而且光标到达选中区域的开始处
    ui->hexPlainTextEdit->moveCursor(QTextCursor::Left);

    byteEdit->hide();
    byteEdit->setText(selectedText);
    byteEdit->setGeometry(rect);
    byteEdit->setFocus();
    byteEdit->show();
}

const QRect Widget::GetRectForByteEditWhenDoubleClick()
{
    int firstBlockNumber = ui->hexPlainTextEdit->verticalScrollBar()->value();
    int currentBlockNumber = ui->hexPlainTextEdit->textCursor().blockNumber();
    QTextBlock block = ui->hexPlainTextEdit->textCursor().block();
    int positionInBlock = ui->hexPlainTextEdit->textCursor().positionInBlock();
    int lineHeight = ui->hexPlainTextEdit->document()->documentLayout()->blockBoundingRect(block).height();
    qDebug() << "line height = " << lineHeight;
    int y = (currentBlockNumber - firstBlockNumber) * lineHeight;
    int yy = ui->hexPlainTextEdit->geometry().y() + ui->hexFrame->geometry().y() + y + (firstBlockNumber != 0 ? 0 : 4);
    int xx = ui->hexPlainTextEdit->geometry().x() + 4 + (positionInBlock-2)*8 - 4;
    int width = 16 + 8;
    int height = lineHeight; // 15 + 4;
    return QRect(xx, yy, width, height);
}

void Widget::byteEditMoveToNext()
{
    QRect rect = byteEdit->geometry();
    if (byteEditPositionInBlock < 15) {
        int x = rect.x() + 8*4;
        if (byteEditPositionInBlock == 7)
        {
            x += 8*2;
        }
        byteEdit->setGeometry(QRect(x, rect.y(), rect.width(), rect.height()));
    }
    else
    {
        int x = ui->hexPlainTextEdit->geometry().x();
        int y = rect.y() + 8 + 7;
        byteEdit->setGeometry(QRect(x, y, rect.width(), rect.height()));
    }
    byteEditPositionInBlock = (byteEditPositionInBlock + 1) % 16;
}

void Widget::byteEditReturnPressed()
{
    byteEdit->hide();
}

void Widget::byteEditFocusOut()
{
    byteEdit->hide();
}

void Widget::byteEditTextEdited(const QString& text)
{
    QString newText = "";
    qDebug() << text;

    // 过滤输入的无效字符及多余的字符
    for (int i = 0; i < text.size(); i++)
    {
        if (i >= 2) break;
        if ((text[i] >= '0' && text[i] <= '9') || (text[i] >= 'A' && text[i] <= 'F') || (text[i] >= 'a' && text[i] <= 'f'))
            newText += text[i];
        else
            break;
    }
    // 此时newText中的所有字符都是有效字符且长度小于等于2
    byteEdit->setText(newText);

    if (newText.size() == 2)
    {

        // 当前光标所在位置的后面的第一个有效字节为正在修改的字节、需要将其替换为newText
        ui->hexPlainTextEdit->moveCursor(QTextCursor::Right, QTextCursor::KeepAnchor);
        ui->hexPlainTextEdit->moveCursor(QTextCursor::Right, QTextCursor::KeepAnchor);
        ui->hexPlainTextEdit->textCursor().removeSelectedText();
        ui->hexPlainTextEdit->textCursor().insertText(newText);

        int moveCount;
        if (byteEditPositionInBlock == 7)
            moveCount = 4;
        else if (byteEditPositionInBlock == 15)
            moveCount = 1;
        else
            moveCount = 2;
        while(moveCount--)
        {
            ui->hexPlainTextEdit->moveCursor(QTextCursor::Right);
        }
        ui->hexPlainTextEdit->moveCursor(QTextCursor::Right, QTextCursor::KeepAnchor);
        ui->hexPlainTextEdit->moveCursor(QTextCursor::Right, QTextCursor::KeepAnchor);
        byteEdit->setText(ui->hexPlainTextEdit->textCursor().selectedText());
        ui->hexPlainTextEdit->moveCursor(QTextCursor::Left);

        byteEditMoveToNext();
    }
}
