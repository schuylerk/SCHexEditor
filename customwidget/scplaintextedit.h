#ifndef SCPLAINTEXTEDIT_H
#define SCPLAINTEXTEDIT_H

#include <QPlainTextEdit>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QClipboard>
#include <QGuiApplication>

class SCPlainTextEdit : public QPlainTextEdit
{
    Q_OBJECT
signals:
    void wheelEventHandle(QWheelEvent* event);
    void mousePressEventHandle(QMouseEvent* event);
    void mouseMoveEventHandle(QMouseEvent* event);
    void copyFinish();
    void readyPaste();
    void mouseDoubleClickEventHandle(QMouseEvent* event);

public:
    int contentOffsetY = 0;

public:
    SCPlainTextEdit(QWidget* parent);
    virtual void wheelEvent(QWheelEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
};

#endif // SCPLAINTEXTEDIT_H
