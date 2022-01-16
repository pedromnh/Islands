//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_MINAFERRO_H
#define ISLANDSCLION_MINAFERRO_H

#include "Buildings.h"

class MinaFerro : public Buildings{
private:
    std::string name;
    std::string type = "minaFerro";
public:
    MinaFerro(int amountOfMnf, int x, int y, int currentDay) {
        setType(type);
        setCost(10);
        setChanceOfBreaking(15);
        setDayBuilt(currentDay);
        setMaxLevel(5);
        setCostOfLevelUp(15);
        name = "mnF";
        std::string amount = std::to_string(amountOfMnf + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
        setStatus("Disabled");
    }

    ~MinaFerro() {
        decrementMnF();
    }

    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_MINAFERRO_H
