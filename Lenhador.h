//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_LENHADOR_H
#define ISLANDSCLION_LENHADOR_H

#include "Interface.h"

class Lenhador {
private:
    std::string name;
public:
    Lenhador(int amountOfLenhadores) {
        name = "lenhador";
        std::string amount = std::to_string(amountOfLenhadores + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_LENHADOR_H
