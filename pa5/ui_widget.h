#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QtWidgets>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QMainWindow *parent = nullptr): QWidget(parent)
    {
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

        infoLabel = new QLabel("\n\n\n");
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

private:
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

