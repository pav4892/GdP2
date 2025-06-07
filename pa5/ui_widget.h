#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QtWidgets>
#include <iomanip> // gives setprecision interface for float limit to 2 digits after komma
#include "ufosim.h"
#include "vertical.h"
#include "ufo_thread.h"

class MainWidget : public QWidget
{
    Q_OBJECT

    public:
        MainWidget(QMainWindow *parent = nullptr): QWidget(parent)
        {

            ufo = new Vertical("r2d2");
            uthread = new UfoThread(ufo);

            label1 = new QLabel("x: ");
            label2 = new QLabel("y: ");
            label3 = new QLabel("height: ");
            label4 = new QLabel("speed: ");

            inputX = new QLineEdit();
            inputY = new QLineEdit();
            inputHeight = new QLineEdit();
            inputSpeed = new QLineEdit();

            inputX->setFixedSize(150, 30);
            inputY->setFixedSize(150, 30);
            inputHeight->setFixedSize(150, 30);
            inputSpeed->setFixedSize(150, 30);

            startButton = new QPushButton("Start");
            startButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            startButton->setFixedHeight(40);
            
            connect(startButton, SIGNAL(clicked()), this, SLOT(startUfo()));
            connect(uthread, SIGNAL(stopped(std::vector<float>)), this, SLOT(updateWindow(std::vector<float>)));

            infoLabel = new QLabel("\n\n\n\n");
            infoLabel->setWordWrap(true);
            infoLabel->setAlignment(Qt::AlignCenter);
            infoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

            // Do the frame around it (is from moodle)
            infoLabel->setFrameShape(QFrame::Box);
            infoLabel->setFrameShadow(QFrame::Plain);

            QGridLayout *formLayout = new QGridLayout();
            formLayout->addWidget(label1, 0, 0);
            formLayout->addWidget(inputX, 0, 1);
            formLayout->addWidget(label2, 1, 0);
            formLayout->addWidget(inputY, 1, 1);
            formLayout->addWidget(label3, 2, 0);
            formLayout->addWidget(inputHeight, 2, 1);
            formLayout->addWidget(label4, 3, 0);
            formLayout->addWidget(inputSpeed, 3, 1);
            formLayout->setSpacing(10);

            QVBoxLayout *mainLayout = new QVBoxLayout();
            mainLayout->addLayout(formLayout);
            mainLayout->addStretch();
            mainLayout->addWidget(startButton);
            mainLayout->addWidget(infoLabel);

            setLayout(mainLayout);
        }

        ~MainWidget()
        {
            //delete ufo;
            //delete uthread;

            delete label1;
            delete label2;
            delete label3;
            delete label4;

            delete inputX;
            delete inputY;
            delete inputHeight;
            delete inputSpeed;

            delete startButton;
            delete infoLabel;
        }

    private slots:

        void updateWindow(std::vector<float> posStruct) {
            ostringstream pos1, pos2, pos3;

            pos1 << fixed << setprecision(2) << posStruct[0];
            pos2 << fixed << setprecision(2) << posStruct[1];
            pos3 << fixed << setprecision(2) << posStruct[2];
            string infoLabelString = "\nFlight completed at\nPosition:\n" + pos1.str() + " | " +  pos2.str() + " | " + pos3.str() + " meter\n";
            infoLabel->setText(QString::fromStdString(infoLabelString));

            startButton->setText("Start");
            startButton->setEnabled(true);
        };

        void startUfo() {

            ostringstream pos1, pos2, pos3;

            pos1 << fixed << setprecision(2) << ufo->getPosition()[0];
            pos2 << fixed << setprecision(2) << ufo->getPosition()[1];
            pos3 << fixed << setprecision(2) << ufo->getPosition()[2];

            string infoLabelString = "\nStarted at\nPosition:\n" + pos1.str() + " | " +  pos2.str() + " | " + pos3.str() + " meter\n";
            infoLabel->setText(QString::fromStdString(infoLabelString));


            // Get and Cast the QStrings to the appropriate datatypes for use in uthread's startUfo() function later
            
            // We pass a declared but uninitialised boolean to the toFloat function as error detection because it will set it to false if there is a problem with the conversion and dont have to deal with try catch. Source: google

            bool okX;
            QString xStr = inputX->text();
            float x = xStr.toFloat(&okX);
            if(!okX) {
                inputX->setText("error: must be float");
                infoLabel->setText("\n\n\n\n");
            };

            bool okY;
            QString yStr = inputY->text();
            float y = yStr.toFloat(&okY);
            if(!okY) {
                inputY->setText("error: must be float");
                infoLabel->setText("\n\n\n\n");
            };

            bool okHeight;
            QString heightStr = inputHeight->text();
            float height = heightStr.toFloat(&okHeight);
            if(!okHeight) {
                inputHeight->setText("error: must be float");
                infoLabel->setText("\n\n\n\n");
            };

            bool okSpeed;
            QString speedStr = inputSpeed->text();
            int speed = speedStr.toInt(&okSpeed);
            if(!okSpeed) {
                inputSpeed->setText("error: must be int");
                infoLabel->setText("\n\n\n\n");
            };

            if(okX && okY && okHeight && okSpeed) {

                startButton->setText("Flying");
                startButton->setEnabled(false);
                QApplication::processEvents(); // Forces the UI to update now

                uthread->startUfo(x, y, height, speed);

                
            
                while(1) {
                    if(uthread->getIsFlying() == false) {
                        //startButton->setText("Start");
                        //startButton->setEnabled(true);
                        break;
                    }
                }
            };
        };

    private:

        Ufo * ufo;
        UfoThread * uthread;

        QLabel *label1;
        QLabel *label2;
        QLabel *label3;
        QLabel *label4;

        QLineEdit *inputX;
        QLineEdit *inputY;
        QLineEdit *inputHeight;
        QLineEdit *inputSpeed;

        QPushButton *startButton;
        QLabel *infoLabel;
};

#endif // MAINWIDGET_H

