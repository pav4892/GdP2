#include <thread>
#include "ufo_thread.h"

using namespace std;

UfoThread::UfoThread(Ufo * pUfo) {
  ufo = pUfo;
  flyThread = nullptr; //Check if flyThread != nullptr to check if a nullptr exists
  isFlying = false;
};

UfoThread::~UfoThread(){
  if(flyThread != nullptr) {
    (*flyThread).join();
    delete flyThread;
    flyThread = nullptr;
  };
  
  isFlying = false;
};

void UfoThread::runner(const float x, const float y, const float height, const int speed) {
  ufo->flyToDest(x, y, height, speed);
  isFlying = false;
};

void UfoThread::startUfo(const float x, const float y, const float height, const int speed) {

  if(flyThread != nullptr) { // In case another thread still exists and we call startufoo twice and the other one hasnt been killeld 5yet because the destructor wasn't called
    (*flyThread).join();
    delete flyThread;
    flyThread = nullptr;
  };

  isFlying = true;
  flyThread = new thread(&UfoThread::runner, this, x, y, height, speed); // create thread, call function and pass trhouh params to it. 'this' has to be passed through aswell but does NOT count as param of runner function
  
};

bool UfoThread::getIsFlying() const {
  return isFlying;
};
