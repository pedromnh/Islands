//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_MINEIRO_H
#define ISLANDSCLION_MINEIRO_H

#include "Interface.h"

class Mineiro {
private:
    std::string name;
public:
    Mineiro(int amountOfMineiros) {
        name = "mineiro";
        std::string amount = std::to_string(amountOfMineiros + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_MINEIRO_H
