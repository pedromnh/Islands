//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_DESERTO_H
#define ISLANDSCLION_DESERTO_H

#include "Zones.h"

class Deserto : public Zones {
private:
    std::string name;
    std::string type = "deserto";
public:
    Deserto(int amountOfDsr, int x, int y) {
        setType(type);
        name = "dsr";
        std::string amount = std::to_string(amountOfDsr + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
    }

    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_DESERTO_H
