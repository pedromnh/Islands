//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_FUNDICAO_H
#define ISLANDSCLION_FUNDICAO_H

#include "Interface.h"

class Fundicao {
private:
    std::string name;
public:
    Fundicao(int amountOfFun) {
        name = "fun";
        std::string amount = std::to_string(amountOfFun + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_FUNDICAO_H
