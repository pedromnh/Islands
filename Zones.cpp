//
// Created by Pedro Henriques on 05/01/2022.
//

#include "Zones.h"

double Zones::getProductionMultipler() {
    return productionMultiplier;
}

std::string Zones::getType() {
    return type;
}

void Zones::setType(std::string tipo) {
    type = tipo;
}

int Zones::getTreeCount() {
    return treeCount;
}

int Zones::growTree(int day) {
    return treeCount;
}
