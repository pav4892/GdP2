#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QtWidgets>
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

        infoLabel = new QLabel("\nStarted at\nPosition:\n0.00 | 0.00 | 0.00 meter\n");
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
    void startUfo() {
        QString xStr = inputX->text();
        QString yStr = inputY->text();
        QString heightStr = inputHeight->text();
        QString speedStr = inputSpeed->text();

        double xDouble = xStr.toDouble();
        double yDouble = yStr.toDouble();
        double heightDouble = heightStr.toDouble();
        double speedDouble = speedStr.toDouble();

        float x = static_cast<float>(xDouble);
        float y = static_cast<float>(yDouble);
        float height = static_cast<float>(heightDouble);
        int speed = static_cast<int>(speedDouble);

        startButton->setText("Flying");
        startButton->setEnabled(false);

        uthread->startUfo(x, y, height, speed);
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

