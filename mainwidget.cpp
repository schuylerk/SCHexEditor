#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QTimer>
#include "sc_hex_editor_logic.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);

    launchWidget = new LaunchWidget();
    connect(launchWidget, &LaunchWidget::launchCompletion, this, &MainWidget::launchCompletion);
    launchWidget->show();
}

MainWidget::~MainWidget()
{
    delete ui;
    delete launchWidget;
    delete startWidget;
}

void MainWidget::launchCompletion()
{
    launchWidget->hide();

    startWidget = new StartWidget();
    connect(startWidget, &StartWidget::openFile, this, &MainWidget::openFile);
    startWidget->show();
}

void MainWidget::openFile(const QString filename)
{
    widget = new Widget(new SCHexEditorLogic(filename));
    startWidget->hide();
    widget->show();
}
