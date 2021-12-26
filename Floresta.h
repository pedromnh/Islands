//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_FLORESTA_H
#define ISLANDSCLION_FLORESTA_H

#include "Interface.h"

class Floresta {
private:
    std::string name;
public:
    Floresta(int amountOfFlr) {
        name = "flr";
        std::string amount = std::to_string(amountOfFlr + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_FLORESTA_H