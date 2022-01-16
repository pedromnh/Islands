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

void Zones::incrementMnt() {
    numOfMnt++;
}

void Zones::incrementDsr() {
    numOfDsr++;
}

void Zones::incrementPas() {
    numOfPas++;
}

void Zones::incrementFlr() {
    numOfFlr++;
}

void Zones::incrementPnt() {
    numOfPnt++;
}

void Zones::incrementZnZ() {
    numOfZnZ++;
}

int Zones::getAmountOfMnt() const {
    return numOfMnt;
}

int Zones::getAmountOfDsr() const {
    return numOfDsr;
}

int Zones::getAmountOfPas() const {
    return numOfPas;
}

int Zones::getAmountOfFlr() const {
    return numOfFlr;
}

int Zones::getAmountOfPnt() const {
    return numOfPnt;
}

int Zones::getAmountOfZnZ() const {
    return numOfZnZ;
}

void Zones::killTree() {
    std::cout << "Killed tree" << std::endl;
}
