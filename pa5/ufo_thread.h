#include <thread>
#include "ufo.h"

using namespace std;

class UfoThread {

  private:
    thread * flyThread;
    Ufo * ufo;
    bool isFlying;
    void runner(const float x, const float y, const float height, const int speed);
  public:
    UfoThread(Ufo * pUfo);
    ~UfoThread();
    void startUfo(const float x, const float y, const float height, const int speed); // Erst hier startet der Thread
    bool getIsFlying() const;
    
};

/*
Lay fylthrad and ufo on heap thats why we use pointers
irgendwas mit this weitere paramter geben
Thread soll nach erfolgreichem Flug noch immer aufrufbar sein oder so
Nach landen wird thread gekillt und startufo startet immer wieder einen neuen thread pro flug aber immer mit dem selben flyThread
*/
