//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_MINEIRO_H
#define ISLANDSCLION_MINEIRO_H

#include "Workers.h"

class Mineiro : public Workers {
private:
    std::string name;
    std::string type = "mineiro";
public:
    Mineiro(int totalWorkerCount, int day) {
        setType(type);
        name = type;
        setCostOfContract(10);
        std::string amount = std::to_string(getAmountOfMineiros() + 1);
        name.append(amount);
        incrementMineiros();
        setDayHired(day);
        setId(totalWorkerCount);
        moveWorker();
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_MINEIRO_H
