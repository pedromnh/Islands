//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_PASTAGEM_H
#define ISLANDSCLION_PASTAGEM_H

#include "Zones.h"

class Pastagem : public Zones {
private:
    std::string name;
public:
    Pastagem(int amountOfPas, int x, int y) {
        name = "pas";
        std::string amount = std::to_string(amountOfPas + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
    }

    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_PASTAGEM_H
