//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_ZONAX_H
#define ISLANDSCLION_ZONAX_H

#include "Interface.h"

class ZonaX {
private:
    std::string name;
public:
    ZonaX(int amountOfZnZ) {
        name = "znZ";
        std::string amount = std::to_string(amountOfZnZ + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_ZONAX_H
