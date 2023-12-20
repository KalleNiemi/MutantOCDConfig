#include "mainwindow.h"
#include "populateUi.h"
#include <QApplication>
#include <QComboBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    populateUi u;
    populateUi::initializeUi(&w);

    w.show();

    return a.exec();
}
