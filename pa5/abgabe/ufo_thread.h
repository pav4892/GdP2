#pragma once

#include <thread>
#include <QObject>
#include <vector>
#include "ufo.h"

#include <QMetaType>
Q_DECLARE_METATYPE(std::vector<float>) // I need this because else the connect signal that sends the coords to the window to display in the label at the bottom won't work;

class UfoThread : public QObject {
  Q_OBJECT

private:
  std::thread* flyThread;
  Ufo* ufo;
  bool isFlying;

  void runner(const float x, const float y, const float height, const int speed) {
    ufo->flyToDest(x, y, height, speed);
    isFlying = false;
    emit stopped(ufo->getPosition());  // send signal with final position
  }

public:
  UfoThread(Ufo* pUfo, QObject* parent = nullptr): QObject(parent), flyThread(nullptr), ufo(pUfo), isFlying(false) {}

  ~UfoThread() {
    if (flyThread != nullptr) {
      flyThread->join();
      delete flyThread;
      flyThread = nullptr;
    }
    isFlying = false;
  }

  void startUfo(const float x, const float y, const float height, const int speed) {
    if (flyThread != nullptr) {
      flyThread->join();
      delete flyThread;
      flyThread = nullptr;
    };

    isFlying = true;
    flyThread = new std::thread(&UfoThread::runner, this, x, y, height, speed);
  }

  bool getIsFlying() const {
    return isFlying;
  }

signals:
  void stopped(std::vector<float>);
};

