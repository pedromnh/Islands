//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_OPERARIO_H
#define ISLANDSCLION_OPERARIO_H

#include "Interface.h"

class Operario {
private:
    std::string name;
public:
    Operario(int amountOfOperarios) {
        name = "operario";
        std::string amount = std::to_string(amountOfOperarios + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_OPERARIO_H
