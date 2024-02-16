#ifndef LAUNCHWIDGET_H
#define LAUNCHWIDGET_H

#include <QWidget>

namespace Ui {
class LaunchWidget;
}

class LaunchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LaunchWidget(QWidget *parent = nullptr);
    ~LaunchWidget();

private:
    void showVirtualProcess();

signals:
    void launchCompletion();

private:
    Ui::LaunchWidget *ui;
};

#endif // LAUNCHWIDGET_H
