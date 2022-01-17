//
// Created by Pedro Henriques on 09/01/2022.
//

#include "Workers.h"

void Workers::setId(int totalWorkerCount) {
    workerId.append(std::to_string(totalWorkerCount + 1));
    workerId.append(".");
    workerId.append(std::to_string(dayHired));
}

int Workers::getAmountOfLenhadores() const {
    return amountOfLenhadores;
}


void Workers::incrementLenhadores() {
    amountOfLenhadores++;
}

void Workers::incrementOperarios() {
    amountOfOperarios++;
}

void Workers::incrementMineiros() {
    amountOfMineiros++;
}


void Workers::decrementLenhadores() {
    amountOfLenhadores--;
}

void Workers::decrementOperarios() {
    amountOfOperarios--;
}

void Workers::decrementMineiros() {
    amountOfMineiros--;
}

int Workers::getAmountOfOperarios() const {
    return amountOfOperarios;
}

int Workers::getAmountOfMineiros() const {
    return amountOfMineiros;
}

void Workers::moveWorker() {
    int x, y;
    do {
//        std::cout << "Choose coordinates to moveID \"" << getType() << ", "<< getWorkerId() << "\" to: ";
        std::cin >> x >> y;
    } while (!isValidMoveLocation());
    setCoordinateX(x);
    setCoordinateY(y);
}

bool Workers::isValidMoveLocation() {
    return true;
}

void Workers::setType(std::string tipo) {
    type = tipo;
}

std::string Workers::getWorkerId() const {
    return workerId;
}

int Workers::getTotalWorkerCount() const {
    return getAmountOfLenhadores() + getAmountOfMineiros() + getAmountOfOperarios();
}

void Workers::setDayHired(int day) {
    dayHired = day;
}

double Workers::getCostOfContract() const {
    return costOfContract;
}

void Workers::setCostOfContract(double custo) {
    costOfContract = custo;
}

Workers::Workers(const Workers &game, std::string save) {
    saveName = save;
    std::cout << "Created" << std::endl;
}


