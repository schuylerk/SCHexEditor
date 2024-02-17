#include "startwidget.h"
#include "ui_startwidget.h"
#include <QFileDialog>
#include <userdefaults.h>
#include <algorithm>
#include <QListWidgetItem>

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartWidget)
{
    ui->setupUi(this);
    setWindowTitle("开始");

    QVector<QString> recentOpenFiles = getFilePaths();
    int size = recentOpenFiles.size();
    for (int i = 0; i < size; i++)
    {
        QListWidgetItem *item = new QListWidgetItem(recentOpenFiles[i]);
        item->setForeground(QBrush(QColor(Qt::white)));
        ui->recentOpenList->addItem(item);
    }
    connect(ui->recentOpenList, &QListWidget::itemDoubleClicked, this, &StartWidget::openRecentFile);
}

StartWidget::~StartWidget()
{
    delete ui;
}

void StartWidget::on_openFileButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("打开文件"), "./", "*.*", 0);
    if (filename.isEmpty())
        return;
    emit openFile(filename);
    saveFilePath(filename);
}

void StartWidget::on_createFileButton_clicked()
{
    emit createFile();
}

void StartWidget::saveFilePath(QString filename)
{
    QString path = filename + "_" + QString::number(QDateTime::currentDateTime().toSecsSinceEpoch()); // 路径后添加时间戳
    QVector<QString> recentOpenFiles = UserDefaults::shared().getStringArray("recentOpenFiles");
    QVector<QString> files;
    int size = recentOpenFiles.size();
    for (int i = 0; i < size; i++)
    {
        files.push_back(recentOpenFiles[i].split('_')[0]);
    }
    int index = files.indexOf(filename);
    if (index == -1)
        recentOpenFiles.push_back(path);
    else
        recentOpenFiles[index] = path;
    UserDefaults::shared().setStringArray(recentOpenFiles, "recentOpenFiles");
}

QVector<QString> StartWidget::getFilePaths()
{
    QVector<QString> recentOpenFiles = UserDefaults::shared().getStringArray("recentOpenFiles");
    std::sort(recentOpenFiles.begin(), recentOpenFiles.end(), [](QString s1, QString s2){
        QStringList stringList1 = s1.split('_');
        QStringList stringList2 = s2.split('_');
        if (stringList2.size() < 2 || stringList1.size() < 2)
            return s1 > s2;
        return stringList1[1] > stringList2[1];
    });
    int size = recentOpenFiles.size();
    for (int i = 0; i < size; i++)
    {
        recentOpenFiles[i] = recentOpenFiles[i].split('_')[0];
    }
    return recentOpenFiles;
}

void StartWidget::openRecentFile(QListWidgetItem *item)
{
    item->setSelected(false);
    QString path = item->text();
    emit openFile(path);
    saveFilePath(path);
}
