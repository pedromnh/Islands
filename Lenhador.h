//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_LENHADOR_H
#define ISLANDSCLION_LENHADOR_H

#include "Workers.h"

class Lenhador : public Workers {
private:
    std::string name;
    std::string type = "lenhador";
public:
    Lenhador(int totalWorkerCount, int day) {
        setType(type);
        name = type;
        setCostOfContract(20);
        setChanceOfQuitting(0);
        std::string amount = std::to_string(getAmountOfLenhadores() + 1);
        name.append(amount);
        incrementLenhadores();
        setDayHired(day);
        setId(totalWorkerCount);
        moveWorker();
    }

    ~Lenhador() {
        decrementLenhadores();
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_LENHADOR_H
