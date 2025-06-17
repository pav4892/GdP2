#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QMainWindow>
#include "ui_widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
    MainWindow()
    {
        QIcon icon("thi_icon.png");
        setWindowTitle("Ufo");
        setWindowIcon(icon);
        resize(50, 250);
        mainwidget = new MainWidget(this); //from ui_widget.h and we pass a this class-instance-pointer to it
        setCentralWidget(mainwidget);
    }

    ~MainWindow()
    {
        delete mainwidget;
    }

private:
    MainWidget *mainwidget;
};

#endif // UI_WINDOW_H

