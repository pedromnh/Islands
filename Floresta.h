//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_FLORESTA_H
#define ISLANDSCLION_FLORESTA_H

#include "Zones.h"

class Floresta : public Zones {
private:
    std::string name;
    std::string type = "floresta";
    int amountOfTrees;
public:
    Floresta(int amountOfFlr, int x, int y) {
        setType(type);
        name = "flr";
        std::string amount = std::to_string(amountOfFlr + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
        amountOfTrees = generateRandomTrees();
    }

    std::string getName() override {
        return name;
    }

    int getTreeCount();
    int generateRandomTrees();
    int growTree(int day);
    void killTree();
};


#endif //ISLANDSCLION_FLORESTA_H
