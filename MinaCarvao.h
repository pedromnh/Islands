//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_MINACARVAO_H
#define ISLANDSCLION_MINACARVAO_H

#include "Interface.h"

class MinaCarvao {
private:
    std::string name;
public:
    MinaCarvao(int amountOfMnC) {
        name = "mnC";
        std::string amount = std::to_string(amountOfMnC + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_MINACARVAO_H
