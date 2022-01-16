//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_BATERIA_H
#define ISLANDSCLION_BATERIA_H

#include "Buildings.h"

class Bateria :public Buildings {
private:
    std::string name;
    std::string type = "bateria";
public:
    Bateria(int amountOfBat, int x, int y, int currentDay) {
        setType(type);
        setChanceOfBreaking(0);
        setDayBuilt(currentDay);
        setMaxLevel(5);
        setCostOfLevelUp(5);
        name = "bat";
        std::string amount = std::to_string(amountOfBat + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
        setStatus("Disabled");
    }

    ~Bateria() {
        decrementBat();
    }


    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_BATERIA_H
