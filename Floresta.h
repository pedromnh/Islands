//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_FLORESTA_H
#define ISLANDSCLION_FLORESTA_H

#include "Zones.h"

class Floresta : public Zones {
private:
    std::string name;
public:
    Floresta(int amountOfFlr, int x, int y) {
        name = "flr";
        std::string amount = std::to_string(amountOfFlr + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
    }

    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_FLORESTA_H
