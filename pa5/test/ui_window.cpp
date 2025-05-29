#include "ui_window.h"

MainWindow::MainWindow()
{
    QIcon icon("/home/n0ne/wamser.png");
    setWindowTitle("Hello");
    setWindowIcon(icon);
    button = new QPushButton("Hello world");
    setCentralWidget(button);
}

MainWindow::~MainWindow()
{
    delete button;
}
