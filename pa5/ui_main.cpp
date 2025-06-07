#include <QtWidgets/QApplication>
#include "ui_window.h"

#include <QMetaType>
#include <vector>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  // Register std::vector<float> so Qt can use it wenn sending the signal with the coords to the main window after flight in ufo_thread.h
  qRegisterMetaType<std::vector<float>>("std::vector<float>");

  MainWindow w;
  w.show();
  return app.exec();
}
