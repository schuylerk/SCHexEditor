#include <QApplication>
#include <main/mainwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget w;

    return a.exec();
}
