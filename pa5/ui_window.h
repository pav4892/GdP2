#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
        mainwidget = new MainWidget(this);
        setCentralWidget(mainwidget);
    }

    ~MainWindow()
    {
        delete mainwidget;
    }

private:
    MainWidget *mainwidget;
};

#endif // MAINWINDOW_H

