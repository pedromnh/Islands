//
// Created by Pedro Henriques on 08/01/2022.
//

#include "Buildings.h"

void Buildings::incrementMnF() {
    numOfMnF++;
}

void Buildings::incrementMnC() {
    numOfMnC++;
}

void Buildings::incrementElec() {
    numOfElec++;
}

void Buildings::incrementBat() {
    numOfBat++;
}

void Buildings::incrementFun() {
    numOfFun++;
}

int Buildings::getTotalBuildingCount() const {
    return getAmountOfBat() + getAmountOfElec() + getAmountOfFun() + getAmountOfMnC() + getAmountOfMnF();
}

int Buildings::getAmountOfMnC() const {
    return numOfMnC;
}

int Buildings::getAmountOfMnF() const {
    return numOfMnF;
}

int Buildings::getAmountOfElec() const {
    return numOfElec;
}

int Buildings::getAmountOfBat() const {
    return numOfBat;
}

int Buildings::getAmountOfFun() const {
    return numOfFun;
}
