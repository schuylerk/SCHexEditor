#include "sclineedit.h"

SCLineEdit::SCLineEdit(QWidget* parent)
    : QLineEdit(parent)
{

}

void SCLineEdit::focusOutEvent(QFocusEvent* event)
{
    emit focusOutEventHandle();
    QLineEdit::focusOutEvent(event);
}
