#include "launchwidget.h"
#include "ui_launchwidget.h"
#include <QTimer>

LaunchWidget::LaunchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LaunchWidget)
{
    ui->setupUi(this);

    // 隐藏顶部栏
    setWindowFlag(Qt::FramelessWindowHint);

    // 显示加载条，并非真的在加载
    showVirtualProcess();
}

LaunchWidget::~LaunchWidget()
{
    delete ui;
}

void LaunchWidget::showVirtualProcess()
{
    ui->progressBar->setValue(0);

    QTimer *timer = new QTimer(this);
    timer->start(20);
    connect(timer, &QTimer::timeout, [=] {
        int value = ui->progressBar->value();
        ui->progressBar->setValue(value + 1);
        if (value == 99) {
            emit launchCompletion();
            timer->stop();
            delete timer;
        }
    });
}
