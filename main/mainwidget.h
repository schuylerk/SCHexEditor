#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "launch/launchwidget.h"
#include "start/startwidget.h"
#include "editormain/editormainwidget.h"

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
    EditorMainWidget *editorMainWidget;
};

#endif // MAINWIDGET_H
