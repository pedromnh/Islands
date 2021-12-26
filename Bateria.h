//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_BATERIA_H
#define ISLANDSCLION_BATERIA_H

#include "Interface.h"

class Bateria {
private:
    std::string name;
public:
    Bateria(int amountOfBat) {
        name = "bat";
        std::string amount = std::to_string(amountOfBat + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_BATERIA_H
