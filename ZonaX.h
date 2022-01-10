//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_ZONAX_H
#define ISLANDSCLION_ZONAX_H

#include "Zones.h"

class ZonaX : public Zones {
private:
    std::string name;
    std::string type = "zonaX";
public:
    ZonaX(int amountOfZnZ, int x, int y) {
        setType(type);
        name = "znZ";
        std::string amount = std::to_string(amountOfZnZ + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
    }

    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_ZONAX_H
