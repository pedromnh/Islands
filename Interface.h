//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_INTERFACE_H
#define ISLANDSCLION_INTERFACE_H

#include "Island.h"
#include "Resources.h"
#include "Montanha.h"
#include <sstream>

class Interface {
private:
    int currentPhase;
    int day;
    bool loaded = false;
public:
    Interface() {
        currentPhase = 1;
        day = 0;
        chooseLoadOrStart();
    }

    bool getLoadStatus();

    static void firstMessage();

    bool chooseLoadOrStart();

    void load();

    void morningMessage() const;

    void afternoonMessage() const;

    void nightMessage() const;

    int getCurrentPhase() const;

    void setMorning();

    void setAfternoon();

    void setNight();

    void endGame();

    int getDay();
};


#endif //ISLANDSCLION_INTERFACE_H
