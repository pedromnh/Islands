#include <fstream>
#include "Interface.h"
#include "time.h"

int main() {
    srand(time(NULL));
    Interface interface;
//        Island island(true, 4, 5);
    Island island(interface.getLoadStatus(), island.getLine(), island.getCols());
    Resources resources;
//        int numOfMnt = 0;



    interface.firstMessage();





        interface.setMorning();
    do {
        switch (interface.getCurrentPhase()) {
            case 1: // Morning Phase
                cout << endl << endl << endl << endl;
                interface.morningMessage();
                island.morningEffects();
                interface.setAfternoon();
                break;
            case 2: //Afternoon Phase
                interface.afternoonMessage();
                island.afternoonPhase();
                interface.setNight();
                break;
            case 3: //Night Phase
                interface.nightMessage();
                resources.acquireResources();
                if (interface.getDay() == 5)
                    interface.endGame();
                else
                    interface.setMorning();
                break;
            case 0: //End of game
                interface.endGame();
                break;
        }
    } while (interface.getCurrentPhase() != 0);


    island.list();
    return 0;
}
