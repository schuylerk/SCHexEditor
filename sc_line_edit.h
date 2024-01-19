#ifndef SC_LINE_EDIT_H
#define SC_LINE_EDIT_H

#include <QLineEdit>
#include <QFocusEvent>

class SCLineEdit : public QLineEdit
{
    Q_OBJECT
signals:
    void focusOutEventHandle();

public:
    SCLineEdit(QWidget *parent);

    virtual void focusOutEvent(QFocusEvent* event);
};

#endif // SC_LINE_EDIT_H
