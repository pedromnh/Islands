//
// Created by Pedro Henriques on 08/01/2022.
//

#ifndef ISLANDSCLION_BUILDINGS_H
#define ISLANDSCLION_BUILDINGS_H
#include <iostream>
#include <vector>

class Buildings {
private:
    std::string name;
    std::string status;
    double productionMultiplier = 1;

public:
    double getProductionMultipler();
//    std::vector<std::unique_ptr<Zones>> zonasNaturais;
    std::vector<Buildings*> edificios;

    virtual std::string getName() {
        return name;
    }

    virtual std::string getStatus() {
        return status;
    }

};


#endif //ISLANDSCLION_BUILDINGS_H
