#ifndef SCLINEEDIT_H
#define SCLINEEDIT_H

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

#endif // SCLINEEDIT_H
