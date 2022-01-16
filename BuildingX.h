//
// Created by Pedro Henriques on 16/01/2022.
//

#ifndef ISLANDSCLION_BUILDINGX_H
#define ISLANDSCLION_BUILDINGX_H

#include "Buildings.h"

class BuildingX : public Buildings {
private:
    std::string name;
    std::string type = "serracao";

public:
    BuildingX(int amountOfBuildingX, int x, int y, int currentDay) {
        setType(type);
        setChanceOfBreaking(-1);
        setDayBuilt(currentDay);
        setMaxLevel(1);
        name = "znX";
        std::string amount = std::to_string(amountOfBuildingX + 1);
        name.append(amount);
        setCoordinateX(x);
        setCoordinateY(y);
        setStatus("Enabled");
    }

    ~BuildingX() {
        decrementBuildingX();
    }


    std::string getName() override {
        return name;
    }

};


#endif //ISLANDSCLION_BUILDINGX_H
