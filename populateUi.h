#ifndef POPULATEUI_H
#define POPULATEUI_H
#include <QComboBox>
class MainWindow;
class populateUi
{
public:

    populateUi();
    static void initializeUi(MainWindow* mainWindow);

    static void renderChannel(QComboBox* comboBox, int index, int x) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems;
        if (x == 0){
            menuItems.append("(default)");
        }
        for (int i = 1; i <= 16; ++i) {
            menuItems.append("Channel "+ QString::number(i));
        }
        if (x == 0){
            menuItems.append("(OMNI)");
        }

        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);

    }

    static void renderTrig(QComboBox* comboBox, int index, int x) {      //comboboxname, default value, 0 = gate + retrig + trigger, 1= default trigger
        QStringList menuItems;
        if (x == 1){
            menuItems.append("(gate)");
            menuItems.append("(retrig)");
            menuItems.append("(trigger)");
        }

        for (int i = 1; i <= 15; ++i) {            //First 15 ms
            menuItems.append(QString::number(i) + " ms");
        }

        for (int i = 20; i <= 120; i=i+5) {             //+5 until 120
            menuItems.append(QString::number(i) + " ms");
        }

        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);
    }

    static void renderEnabled(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems ={"(disabled)","ENABLED"};

        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);
    }

    static void renderCC(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems;

        menuItems.append("Mod Wheel");

        for (int i = 2; i <= 5; ++i) {
            menuItems.append("CC# "+ QString::number(i));
        }
        menuItems.append("Data Entry MSB");
        for (int i = 7; i <= 37; ++i) {
            menuItems.append("CC# "+ QString::number(i));
        }
        menuItems.append("Data Entry LSB");
        for (int i = 39; i <= 97; ++i) {
            menuItems.append("CC# "+ QString::number(i));
        }
        menuItems.append("NRPN LSB");
        menuItems.append("NRPN MSB");

        for (int i = 100; i <= 127; ++i) {
            menuItems.append("CC# "+ QString::number(i));
        }


        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);

        comboBox->setItemData(5,0, Qt::UserRole - 1);
        comboBox->setItemData(37,0, Qt::UserRole - 1);
        comboBox->setItemData(97,0, Qt::UserRole - 1);
        comboBox->setItemData(98,0, Qt::UserRole - 1);

    }

    //NOTE INPUTS//

    static void renderInputMode(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems ={"Last note priority","Lowest note priority","Highest note priority","2 note cycle","3 note cycle","4 note cycle","2 note chord","3 note chord","4 note chord"};

        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);
    }

    static void renderNote(QComboBox* comboBox, int index,int x) {      //comboboxname, default value, starting index
        const QStringList notes = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
        QStringList menuItems;

        for (int i = x; i <= 127; ++i) {
            menuItems.append(QString::number(i) + " " + notes[i % 12] + QString::number(i / 12 - 1));
        }

        comboBox->addItems(menuItems);
        if (x ==0){
        index--;
        } else {
            index = 126;
        }
        comboBox->setCurrentIndex(index);
    }

    static void renderMinVel(QComboBox* comboBox, int index,int x) {    //comboboxname, default value, starting index
        QStringList menuItems;
        menuItems.append("(Any)");
        for (int i = x; i <= 127; ++i) {
            menuItems.append(QString::number(i));
        }

        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);
    }

    static void renderPitchBend(QComboBox* comboBox, int index) {    //comboboxname, default value, starting index
        QStringList menuItems;
        for (int i = 0; i <= 24; ++i) {
            menuItems.append("+/- " + QString::number(i));
        }
        comboBox->addItems(menuItems);
        comboBox->setCurrentIndex(index);
    }

    //CV OUTPUTS//

    static void renderCVOutputSource(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems ={"(disabled)","Note input #1","Note input #2","Note input #3","Note input #4","MIDI CC","Pitch Bend","Channel Aftertouch","BPM to CV","Fixed Voltage"};

        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);
    }

    static void renderCVOutputNoteInput(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems ={"First note pitch","Second note pitch","Third note pitch","Fourth note pitch","Most recent note velocity"};

        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);
    }

    static void renderCVOutputTranspose(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems;
        menuItems.append("+3 Oct");
        menuItems.append("+2 Oct");
        menuItems.append("+1 Oct");
        for (int i = 11; i >= 1; --i) {
            menuItems.append("+" + QString::number(i));
        }
        menuItems.append("(none)");
        for (int i = 1; i <= 11; ++i) {
            menuItems.append("-" + QString::number(i));
        }
        menuItems.append("-1 Oct");
        menuItems.append("-2 Oct");
        menuItems.append("-3 Oct");

        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);
    }

    static void renderCVOutputScheme(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems ={"V/Oct","Hz/V *","1.2V/Oct *"};

        comboBox->addItems(menuItems);
        index--;
        comboBox->setCurrentIndex(index);
    }

    static void renderCVOutputRange(QComboBox* comboBox, int index) {    //comboboxname, default value, starting index
        QStringList menuItems;
        for (int i = 1; i <= 5; ++i) {
            menuItems.append(QString::number(i)+"V");
        }
        comboBox->addItems(menuItems);
        comboBox->setCurrentIndex(index);
    }

    //GATE OUTPUTS//

    static void renderGateOutputSource(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems ={"(disabled)","Note input #1","Note input #2","Note input #3","Note input #4","MIDI note","CC above threshold","CC below threshold","Clock Tick","Clock Tick + Run","Transport Run","Transport Restart","Transport Stop","Transport Start/Stop"};

        comboBox->addItems(menuItems);
        comboBox->setCurrentIndex(index);
    }

    static void renderGateOutputNoteInputEvent(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems ={"First note on","Second note on","Third note on","Fourth note on","Any note on","Any note off"};

        comboBox->addItems(menuItems);
        comboBox->setCurrentIndex(index);
    }

    static void renderCCpure(QComboBox* comboBox, int index,int x) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems;
        if (x==1){
            menuItems.append("(none)");
            for (int i = 1; i <= 127; i++) {
                menuItems.append("+"+QString::number(i));
            }
        }else{
            for (int i = 1; i <= 127; i++) {
                menuItems.append(QString::number(i));
            }
        }
        comboBox->addItems(menuItems);
        comboBox->setCurrentIndex(index);
    }

    static void renderGateOutputClockRate(QComboBox* comboBox, int index) {      //comboboxname, default value, 0 = default + omni 1 = channels only
        QStringList menuItems ={"1/32","1/16T","1/16","1/8T","1/16D","1/8","1/4T","1/8D","1/4","1/2T","1/4D","1/2","1/2D","1","24ppqn"};

        comboBox->addItems(menuItems);
        comboBox->setCurrentIndex(index);
    }

};

#endif // POPULATEUI_H
