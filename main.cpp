#include "Interface.h"

int main() {
//    Interface interface;
//    interface.mainGame();
    Resources resources;
    cout << "Wood: " << resources.getWood() << endl;
    resources.acquireWood(2, 1);
    cout << "Wood2: " << resources.getWood() << endl;
    return 0;
}
