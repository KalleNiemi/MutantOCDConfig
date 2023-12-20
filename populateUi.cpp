#include "populateUi.h"
#include "mainwindow.h"

populateUi::populateUi() {}

void populateUi::initializeUi(MainWindow* mainWindow){
    //GLOBALS//

    //Default Channel
    renderChannel(mainWindow->findChild<QComboBox*>("globalsChannelComboBox"), 1,1); // Adjust the default value and if (default) and (OMNI) is included
    renderTrig(mainWindow->findChild<QComboBox*>("globalsTriggerLenComboBox"), 15,0);

    //NOTE INPUTS//

    //Note Input Enabled
    for (int i = 1; i <= 4; ++i) {
        //  renderChannel(mainWindow->inputChannelComboBox[i], 1,0);


        QString comboBoxName = "inputEnableComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        //QComboBox* comboBox = mainWindow->comboBoxName;

        if (comboBox) {
            renderEnabled(comboBox, 1);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Note Input Channels
    for (int i = 1; i <= 4; ++i) {
      //  renderChannel(mainWindow->inputChannelComboBox[i], 1,0);


        QString comboBoxName = "inputChannelComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        //QComboBox* comboBox = mainWindow->comboBoxName;

        if (comboBox) {
            renderChannel(comboBox, 1,0);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Mode
    for (int i = 1; i <= 4; ++i) {
        //  renderChannel(mainWindow->inputChannelComboBox[i], 1,0);


        QString comboBoxName = "inputModeComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        //QComboBox* comboBox = mainWindow->comboBoxName;

        if (comboBox) {
            renderInputMode(comboBox, 3);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Note Input Min Notes x4
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "inputMinNoteComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);

        if (comboBox) {
            renderNote(comboBox, 1, 0);  // Adjust the default value and starting MIDI for min and max (and default max)
        }
    }
    //Note Input Max Notes x4
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "inputMaxNoteComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);

        if (comboBox) {
            renderNote(comboBox, 1, 1);  // Adjust the default value and starting MIDI for min and max (and default max)
        }
    }

    //Note Input Min Vel
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "inputMinVelComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);

        if (comboBox) {
            renderMinVel(comboBox, 1, 2);  // Adjust the default value and starting MIDI value as needed
        }
    }

    //Pitch Bend range
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "inputPitchBendComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);

        if (comboBox) {
            renderPitchBend(comboBox, 2);  // Adjust the default value and starting MIDI value as needed
        }
    }

    //CV OUTPUTS//

    //CV Source

    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "outputCVSourceComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderCVOutputSource(comboBox, 1);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Note input
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "outputCVNoteInputComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderCVOutputNoteInput(comboBox, 1);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Transpose
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "outputCVTransposeComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderCVOutputTranspose(comboBox, 15);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Scheme
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "outputCVSchemeComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderCVOutputScheme(comboBox, 1);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Channel
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "outputCVChannelComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderChannel(comboBox,1, 0);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //CC
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "outputCVCCComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderCC(comboBox, 1);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Range
    for (int i = 1; i <= 4; ++i) {
        QString comboBoxName = "outputCVRangeComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderCVOutputRange(comboBox, 4);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //GATE OUTPUTS//

    //Source
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateSourceComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderGateOutputSource(comboBox, 0);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Note input event
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateNoteEventComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderGateOutputNoteInputEvent(comboBox, 0);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Channel
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateChannelComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderChannel(comboBox, 1,0);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }
    //Min Note
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateMinNoteComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);

        if (comboBox) {
            renderNote(comboBox, 1, 0);  // Adjust the default value and starting MIDI for min and max (and default max)
        }
    }

    //Max Note
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateMaxNoteComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);

        if (comboBox) {
            renderNote(comboBox, 1, 1);  // Adjust the default value and starting MIDI for min and max (and default max)
        }
    }

    //Min Vel
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateMinVelComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);

        if (comboBox) {
            renderMinVel(comboBox, 1, 2);  // Adjust the default value and starting MIDI value as needed
        }
    }

    //CC
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateCCComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderCC(comboBox, 1);  // Adjust the default value and if (default) and (OMNI) is included
        }
    }

    //Switch at
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateSwitchAtComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderCCpure(comboBox, 63,0);  // Adjust the default value and turn extra feature off
        }
    }

    //Clock Rate
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateClockRateComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderGateOutputClockRate(comboBox, 2);  // Adjust the default value
        }
    }

    //Tick Offset
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateTickOffsetComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderCCpure(comboBox, 0,1);  // Adjust the default value and extra feature on
        }
    }

    //Trigger
    for (int i = 1; i <= 12; ++i) {
        QString comboBoxName = "outputGateTriggerComboBox" + QString::number(i);
        QComboBox* comboBox = mainWindow->findChild<QComboBox*>(comboBoxName);
        if (comboBox) {
            renderTrig(comboBox, 3,1);  // Adjust the default value and turn extra features on
        }
    }

}
