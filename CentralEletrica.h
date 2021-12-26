//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_CENTRALELETRICA_H
#define ISLANDSCLION_CENTRALELETRICA_H

#include "Interface.h"

class CentralEletrica {
private:
    std::string name;
public:
    CentralEletrica(int amountOfElec) {
        name = "elec";
        std::string amount = std::to_string(amountOfElec + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_CENTRALELETRICA_H
