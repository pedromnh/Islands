//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_PASTAGEM_H
#define ISLANDSCLION_PASTAGEM_H

#include "Interface.h"

class Pastagem {
private:
    std::string name;
public:
    Pastagem(int amountOfPas) {
        name = "pas";
        std::string amount = std::to_string(amountOfPas + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_PASTAGEM_H
