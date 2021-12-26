//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_MINAFERRO_H
#define ISLANDSCLION_MINAFERRO_H

#include "Interface.h"

class MinaFerro {
private:
    std::string name;
public:
    MinaFerro(int amountOfMnf) {
        name = "mnF";
        std::string amount = std::to_string(amountOfMnf + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_MINAFERRO_H
