//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_DESERTO_H
#define ISLANDSCLION_DESERTO_H

#include "Interface.h"

class Deserto {
private:
    std::string name;
public:
    Deserto(int amountOfDsr) {
        name = "dsr";
        std::string amount = std::to_string(amountOfDsr + 1);
        name.append(amount);
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_DESERTO_H
