#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class StartWidget;
}

class StartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartWidget(QWidget *parent = nullptr);
    ~StartWidget();

signals:
    void openFile(const QString filename);
    void createFile();

private slots:
    void on_openFileButton_clicked();
    void on_createFileButton_clicked();
    void openRecentFile(QListWidgetItem *item);

private:
    Ui::StartWidget *ui;

    void saveFilePath(QString filename);
    QVector<QString> getFilePaths();
};

#endif // STARTWIDGET_H
