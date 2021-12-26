//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_MONTANHA_H
#define ISLANDSCLION_MONTANHA_H

#include "Interface.h"

class Montanha {
private:
    std::string name;
public:
    Montanha(int amountOfMnt) {
        name = "mnt";
        std::string amount = std::to_string(amountOfMnt + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_MONTANHA_H
