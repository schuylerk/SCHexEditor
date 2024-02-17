#include "scplaintextedit.h"

SCPlainTextEdit::SCPlainTextEdit(QWidget* parent)
    :QPlainTextEdit(parent)
{
}

void SCPlainTextEdit::wheelEvent(QWheelEvent* event)
{
    emit wheelEventHandle(event);
    QPlainTextEdit::wheelEvent(event);
}

void SCPlainTextEdit::mousePressEvent(QMouseEvent* event)
{
    emit mousePressEventHandle(event);
    QPlainTextEdit::mousePressEvent(event);
}

void SCPlainTextEdit::mouseMoveEvent(QMouseEvent* event)
{
    emit mouseMoveEventHandle(event);
    QPlainTextEdit::mouseMoveEvent(event);
}

void SCPlainTextEdit::keyPressEvent(QKeyEvent* event)
{
    bool isCopy = event->matches(QKeySequence::Copy);
    bool isPaste = event->matches(QKeySequence::Paste);
    if (isCopy && QGuiApplication::clipboard()->text() != "")
    {
        QPlainTextEdit::keyPressEvent(event);
        emit copyFinish();
    }
    if (isPaste)
    {
        emit readyPaste();
    }
}

void SCPlainTextEdit::mouseDoubleClickEvent(QMouseEvent* event)
{
    QPlainTextEdit::mouseDoubleClickEvent(event);
    emit mouseDoubleClickEventHandle(event);
}
