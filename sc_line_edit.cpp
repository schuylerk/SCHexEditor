#include "sc_line_edit.h"

SCLineEdit::SCLineEdit(QWidget* parent)
    : QLineEdit(parent)
{

}

void SCLineEdit::focusOutEvent(QFocusEvent* event)
{
    emit focusOutEventHandle();
    QLineEdit::focusOutEvent(event);
}
