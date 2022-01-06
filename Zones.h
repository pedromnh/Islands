//
// Created by Pedro Henriques on 05/01/2022.
//

#ifndef ISLANDSCLION_ZONES_H
#define ISLANDSCLION_ZONES_H
#include <iostream>
#include <vector>

class Zones {
private:
    std::string name;
    double productionMultiplier = 1;

    void testingFunction();
public:
    double getProductionMultipler();
//    std::vector<std::unique_ptr<Zones>> zonasNaturais;
    std::vector<Zones*> zonasNaturais;

    virtual std::string getName() {
        return name;
    }
};


#endif //ISLANDSCLION_ZONES_H
