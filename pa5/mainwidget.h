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
        label1 = new QLabel("x:");
        label2 = new QLabel("y:");
        label3 = new QLabel("height:");
        label4 = new QLabel("speed:");

        inputX = new QLineEdit();
        inputY = new QLineEdit();
        inputHeight = new QLineEdit();
        inputSpeed = new QLineEdit();

/*        label1->setStyleSheet("border: 1px solid black");
        label2->setStyleSheet("border: 1px solid black");
        label3->setStyleSheet("border: 1px solid black");
        label4->setStyleSheet("border: 1px solid black");
        label5->setStyleSheet("border: 1px solid black");
        label6->setStyleSheet("border: 1px solid black");
        */

        // First variant: GridLayout
        layout = new QGridLayout();
        layout->addWidget(label1, 0, 0);
        layout->addWidget(inputX, 0, 8);
        layout->addWidget(label2, 2, 0);
        layout->addWidget(inputY, 2, 8);
        layout->addWidget(label3, 4, 0);
        layout->addWidget(inputHeight, 4, 8);
        layout->addWidget(label4, 6, 0);
        layout->addWidget(inputSpeed, 6, 8);
        layout->setSpacing(2);
        setLayout(layout);

        // Second variant: HBoxLayout
        /*layout = new QHBoxLayout();
        layout->addWidget(label1);
        layout->addWidget(label2);
        layout->addWidget(label3);
        layout->addWidget(label4);
        layout->addWidget(label5);
        layout->addWidget(label6);
        layout->setSpacing(0);
        setLayout(layout);*/

        // Third variant: Nested Layouts
        /*layout1 = new QHBoxLayout();
        layout1->addWidget(label1);
        layout1->addWidget(label2);
        layout1->addWidget(label3);
        layout1->setSpacing(0);
        widget1 = new QWidget();
        widget1->setLayout(layout1);

        layout2 = new QHBoxLayout();
        layout2->addWidget(label4);
        layout2->addWidget(label5);
        layout2->addWidget(label6);
        layout2->setSpacing(0);
        widget2 = new QWidget();
        widget2->setLayout(layout2);

        layout = new QGridLayout();
        layout->addWidget(widget1, 0, 0);
        layout->addWidget(widget2, 1, 0);
        layout->setSpacing(0);
        setLayout(layout);*/
    }

    ~MainWidget()
    {
        delete label1;
        delete label2;
        delete label3;
        delete label4;

        // First variant: GridLayout
        delete layout;

        // Second variant: HBoxLayout
        //delete layout;

        // Third variant: Nested Layouts
        /*delete layout1;
        delete widget1;
        delete layout2;
        delete widget2;
        delete layout;*/
    }

private:
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;

    QLineEdit * inputX;
    QLineEdit * inputY;
    QLineEdit * inputHeight;
    QLineEdit * inputSpeed;

    // First variant: GridLayout
    QGridLayout *layout;

    // Second variant: HBoxLayout
    //QHBoxLayout *layout;

    // Third variant: Nested Layouts
    /*QHBoxLayout *layout1;
    QWidget *widget1;
    QHBoxLayout *layout2;
    QWidget *widget2;
    QGridLayout *layout;*/
};

#endif // MAINWIDGET_H

