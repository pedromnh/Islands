//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_CENTRALELETRICA_H
#define ISLANDSCLION_CENTRALELETRICA_H

#include "Buildings.h"

class CentralEletrica : public Buildings {
private:
    std::string name;
    std::string type = "centralEletrica";
public:
    CentralEletrica(int amountOfElec, int x, int y) {
        setType(type);
        name = "elec";
        std::string amount = std::to_string(amountOfElec + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
        setStatus("Disabled");
    }

    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_CENTRALELETRICA_H
