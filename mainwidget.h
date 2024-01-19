#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "launchwidget.h"
#include "startwidget.h"
#include "widget.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void launchCompletion();
    void openFile(const QString filename);

private:
    Ui::MainWidget *ui;

    LaunchWidget *launchWidget; // 启动界面
    StartWidget *startWidget;
    Widget *widget;
};

#endif // MAINWIDGET_H
