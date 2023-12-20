#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
//Vars
// Note pad:
/*
    To disable drop down menu f.ex.: ui->globalsChannelComboBox->setDisabled(true);
    To change drop down menu index: ui->globalsChannelComboBox->setCurrentIndex(15);
    Hex to int : hexToInt = static_cast<unsigned char>(bytes.at(0));
*/
//Reading Funcions

void MainWindow::readToUi(){
    QFile file(fileName);

    file.open(QIODevice::ReadOnly);
    file.seek(0);
    bytes = file.read(16);

    qDebug() << "16 bytes: " << bytes;

    //file.seek(352);         //debugging reading file past its length
    file.seek(0);
    bytes = file.read(1);
    //Globals

    //Read global settings

    //Read note input settings

    if (bytes.size() == 1) {
        // Convert the single byte to an unsigned short (16-bit integer)
        hexToInt = static_cast<unsigned char>(bytes.at(0));
        //hexString = QString::number(hexToInt, 10);
        //qDebug() << "Converted Hex to String: " << hexString;
        qDebug() << "Converted Hex to Int:" << hexToInt;
        ui->globalsChannelComboBox->setCurrentIndex(15);
        ui->globalsChannelComboBox->setDisabled(true);
    } else {
        qDebug() << "Invalid byte size for conversion!";
        qDebug() << bytes.size(); //0 use this or the stop byte
    }
    file.close();
}
//End of Reading Functions

//Writing functions
void MainWindow::writeSysEx(){
    QFile file(fileName);
    if (file.open(QIODevice::Append)) {
        file.resize(0);
        file.write(startBytes);     // Write the startBytes to the file
        qDebug() << startBytes;
        // Close the file

        //Write Global

        // Write note in / out

        // Write gate outputs

        file.write(stopByte);
        file.close();
    } else {
        qDebug() << "Error opening the file for writing.";
    }
}

void MainWindow::writeGlobal(){     // Write Global configuration

}

//End of Writing functions

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseBtn_clicked()     //Open file, repaint UI with the loaded filename, and call populateUi() Function.
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open SysEx File"), "", tr("SysEx Files (*.syx)"));
    std::cout << fileName.toStdString() << std::endl;

    if (QString::compare(fileName,"",Qt::CaseInsensitive) == 0){
        std::cout << "no file selected" <<std::endl;
    }
    else{
        QFile file(fileName);           //open SysEx for validation check
        file.open(QIODevice::ReadOnly);
        file.seek(0);
        bytes = file.read(4);
        file.close();
        if(bytes == startBytes){        //validate sysex here with start bytes
            selectedSysEx = QFileInfo(fileName).fileName();
            ui->textFileSelected->setText (selectedSysEx);
            QWidget::repaint();
            readToUi();
        }else{
            ui->textFileSelected->setText ("Invalid SysEx!");
        }
    }
}

void MainWindow::on_createSyxEx_clicked()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Save SysEx File"), "", tr("SysEx Files (*.syx)"));    //Choose filename or overwrite
    if (QString::compare(fileName,"",Qt::CaseInsensitive) == 0){
        std::cout << "no file selected" <<std::endl;
    }
    else{
        selectedSysEx = QFileInfo(fileName).fileName();
        ui->textFileSelected->setText (selectedSysEx);
        QWidget::repaint();
    }
    writeSysEx();
}

void MainWindow::on_globalsChannelComboBox_currentIndexChanged(int index)
{
    index++;
  //  qDebug() << index;
    qDebug()<<"default channel changed to index: "<< index;
}

void MainWindow::on_globalsTriggerLenComboBox_currentIndexChanged(int index)
{
    index++;
    qDebug()<<"default trigger changed to index: "<< index;
}




