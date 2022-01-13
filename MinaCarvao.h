//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_MINACARVAO_H
#define ISLANDSCLION_MINACARVAO_H

#include "Buildings.h"

class MinaCarvao : public Buildings{
private:
    std::string name;
    std::string type = "minaCarvao";
public:
    MinaCarvao(int amountOfMnC, int x, int y) {
        setType(type);
        name = "mnC";
        std::string amount = std::to_string(amountOfMnC + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
    }

    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_MINACARVAO_H
