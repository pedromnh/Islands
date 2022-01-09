//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_OPERARIO_H
#define ISLANDSCLION_OPERARIO_H

#include "Workers.h"

class Operario : public Workers {
private:
    std::string name;
    std::string type = "operario";
public:
    Operario(int totalWorkerCount, int day) {
        setType(type);
        name = type;
        std::string amount = std::to_string(getAmountOfOperarios() + 1);
        name.append(amount);
        incrementOperarios();
        setDayHired(day);
        setId(totalWorkerCount);
        moveWorker();
    }

    std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_OPERARIO_H
