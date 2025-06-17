#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QMainWindow>
#include <QtWidgets>
#include <iomanip>  // gives setprecision interface for float limit to 2 digits after komma
#include <unistd.h> // needed for _exit
#include "ufosim.h"
#include "vertical.h"
#include "ufo_thread.h"

class MainWidget : public QWidget
{
    Q_OBJECT;

    public:
        MainWidget(QMainWindow *parent = nullptr): QWidget(parent) { // take optional parent param and pass it to the constructor of QWidget. This will receive a pointer to the ui_window.h class-instance and pass it to
                                                                     // QT's-QWidget for building the UI

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
            startButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Found online: Will make the button expand to the full width available to it
            startButton->setFixedHeight(40);
            
            connect(startButton, SIGNAL(clicked()), this, SLOT(startUfo()));
            connect(uthread, SIGNAL(stopped(std::vector<float>)), this, SLOT(updateWindow(std::vector<float>)));

            infoLabel = new QLabel("\n\n\n\n");
            infoLabel->setWordWrap(true);
            infoLabel->setAlignment(Qt::AlignCenter); //text-align equivalent to css
            infoLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

            // Do the frame around it (is from moodle)
            infoLabel->setFrameShape(QFrame::Box);
            infoLabel->setFrameShadow(QFrame::Plain);

            formLayout = new QGridLayout(); // layout for the inputs
            formLayout->addWidget(label1, 0, 0); //coords are in format y, x
            formLayout->addWidget(inputX, 0, 1);
            formLayout->addWidget(label2, 1, 0);
            formLayout->addWidget(inputY, 1, 1);
            formLayout->addWidget(label3, 2, 0);
            formLayout->addWidget(inputHeight, 2, 1);
            formLayout->addWidget(label4, 3, 0);
            formLayout->addWidget(inputSpeed, 3, 1);
            formLayout->setSpacing(10);

            mainLayout = new QVBoxLayout(); // main layout that stacks the boxes of the input-layout and the button and output QLables correctly on top of each other from top to bottom on a y-axis.
            mainLayout->addLayout(formLayout);
            mainLayout->addStretch(); // Push elements in the direction of the the lower end of the window
            mainLayout->addWidget(startButton);
            mainLayout->addWidget(infoLabel);

            setLayout(mainLayout);
        }

        ~MainWidget() {

            // Free all the memory by deleting all instances of QT Objects created prior
        
            delete uthread;

            delete ufo;

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

            delete formLayout;
            delete mainLayout;

        };

    private slots:

        void updateWindow(std::vector<float> posStruct) {
            ostringstream pos1, pos2, pos3; // Found online: ostringstream can be used kinda like 'cout' but for building strings in this case and not outputting anything to console. We save the floats in there and then
                                            // We can use the simple .str() interface to cast them to a string while building the Output that should be displayed next

            pos1 << fixed << setprecision(2) << posStruct[0]; // fixed is from the std library and here it is used to set the float to a FIXED 2 digit limit. setpricision wants to be redirected into fixed before it can be stored
            pos2 << fixed << setprecision(2) << posStruct[1]; 
            pos3 << fixed << setprecision(2) << posStruct[2];
            string infoLabelString = "\nFlight completed at\nPosition:\n" + pos1.str() + " | " +  pos2.str() + " | " + pos3.str() + " meter\n";
            infoLabel->setText(QString::fromStdString(infoLabelString)); // Has to be cast to a QString so it can be used by QT, in this case: in order to set the output text of the QLabel(infoLabel), Source: Google

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
            
            // We pass a declared but uninitialised boolean to the toFloat function as error detection because it will set it to false if there is a problem with the conversion and dont have to deal with try catch. idea Source: google

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
                QApplication::processEvents(); // Forces the UI to update NOW, for some reason I need this or else in some cases it can lead to delays in the diplay of the changes in code in the UI

                uthread->startUfo(x, y, height, speed);

                
            
                /*
                while(1) {
                    if(uthread->getIsFlying() == false) {
                        //startButton->setText("Start");
                        //startButton->setEnabled(true);
                        break;
                    }
                }
                */
                 
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
    
        QGridLayout *formLayout;
        QVBoxLayout *mainLayout;

};

#endif // UI_WIDGET_H
