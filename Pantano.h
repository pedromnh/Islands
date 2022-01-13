//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_PANTANO_H
#define ISLANDSCLION_PANTANO_H

#include "Zones.h"

class Pantano : public Zones {
private:
    std::string name;
    std::string type = "pantano";
public:
    Pantano(int amountOfPnt, int x, int y) {
        setType(type);
        name = "pnt";
        std::string amount = std::to_string(amountOfPnt + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
    }

    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_PANTANO_H
