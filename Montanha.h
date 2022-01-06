//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_MONTANHA_H
#define ISLANDSCLION_MONTANHA_H

#include "Zones.h"

class Montanha : public Zones {
private:
    std::string name;
public:
    Montanha(int amountOfMnt) {
        name = "mnt";
        std::string amount = std::to_string(amountOfMnt + 1);
        name.append(amount);
//        std::cout << "Built: " << name << std::endl;
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_MONTANHA_H
