#include <thread>
#include "ufo.h"

using namespace std;

class UfoThread {

  private:
    thread * flyThread;
    Ufo * ufo;
    bool isFlying;
    void runner(const float x, const float y, const float height, const int speed) {
      ufo->flyToDest(x, y, height, speed);
      isFlying = false;
    };
  
  public:
    UfoThread(Ufo * pUfo) {
      ufo = pUfo;
      flyThread = nullptr; //Check if flyThread != nullptr to check if a nullptr exists
      isFlying = false;
    };

    ~UfoThread() {
      
      if(flyThread != nullptr) {
        (*flyThread).join();
        delete flyThread;
        flyThread = nullptr;
      };
  
      isFlying = false;
    };

    void startUfo(const float x, const float y, const float height, const int speed) {
  
      if(flyThread != nullptr) { // In case another thread still exists and we call startufoo twice and the other one hasnt been killeld 5yet because the destructor wasn't called
        (*flyThread).join();
        delete flyThread;
        flyThread = nullptr;
      };

      isFlying = true;
      flyThread = new thread(&UfoThread::runner, this, x, y, height, speed); // create thread, call function and pass trhouh params to it. 'this' has to be passed through aswell but does NOT count as param of runner function
    }; // Erst hier startet der Thread
  
    bool getIsFlying() const {
      return isFlying;
    };
    
};

/*
Lay fylthrad and ufo on heap thats why we use pointers
irgendwas mit this weitere paramter geben
Thread soll nach erfolgreichem Flug noch immer aufrufbar sein oder so
Nach landen wird thread gekillt und startufo startet immer wieder einen neuen thread pro flug aber immer mit dem selben flyThread
*/
