//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_PANTANO_H
#define ISLANDSCLION_PANTANO_H

#include "Interface.h"

class Pantano {
private:
    std::string name;
public:
    Pantano(int amountOfPnt) {
        name = "pnt";
        std::string amount = std::to_string(amountOfPnt + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_PANTANO_H
