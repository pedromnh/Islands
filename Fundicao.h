//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_FUNDICAO_H
#define ISLANDSCLION_FUNDICAO_H

#include "Bateria.h"

class Fundicao : public Buildings {
private:
    std::string name;
    std::string type = "fundicao";
public:
    Fundicao(int amountOfFun, int x, int y, int currentDay) {
        setType(type);
        setCost(10);
        setChanceOfBreaking(-1);
        setDayBuilt(currentDay);
        name = "fun";
        std::string amount = std::to_string(amountOfFun + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
        setStatus("Disabled");
    }

    ~Fundicao(){
        decrementFun();
    }


    std::string getName() override {
        return name;
    }
};


#endif //ISLANDSCLION_FUNDICAO_H
