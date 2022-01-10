//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_MONTANHA_H
#define ISLANDSCLION_MONTANHA_H

#include "Zones.h"

class Montanha : public Zones {
private:
    std::string name;
    std::string type = "montanha";
public:
    Montanha(int amountOfMnt, int x, int y) {
        setType(type);
        name = "mnt";
        std::string amount = std::to_string(amountOfMnt + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
//        std::cout << "Built: " << name << std::endl;
    }

    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_MONTANHA_H
