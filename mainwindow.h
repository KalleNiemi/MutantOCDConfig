#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfo>
#include <QByteArray>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //QComboBox* inputChannelComboBox[4];

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void readToUi();                           //populate Ui and write variables
    void writeSysEx();
    void writeGlobal();

    QByteArray startBytes=QByteArray("\xF0\x00\x7F\x15",4);
    QByteArray stopByte=QByteArray("\xF7",1);
    //QByteArray startBytes=QByteArray("\xF0\x00\x7F\x14",4);   //Validation test!
    //PopulateUi variables
    QByteArray bytes;
    QByteArray data;
    QString fileName ="";
    QString selectedSysEx ="";
    QString hexString;
    unsigned char hexToInt;


    Ui::MainWindow *ui;
//public slots:


 private slots:
    void on_createSyxEx_clicked();
    void on_browseBtn_clicked();

    void on_globalsChannelComboBox_currentIndexChanged(int index);
    void on_globalsTriggerLenComboBox_currentIndexChanged(int index);


private:


};
extern const QByteArray startBytes;
#endif // MAINWINDOW_H
