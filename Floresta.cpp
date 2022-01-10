//
// Created by Pedro Henriques on 22/11/2021.
//

#include "Floresta.h"

int Floresta::generateRandomTrees() {
    amountOfTrees = rand() % 40 + 20;
    return amountOfTrees;
}

int Floresta::getTreeCount() {
    return amountOfTrees;
}

int Floresta::growTree(int day) {
    if ((day % 2) == 0 && amountOfTrees <= 100) {
        amountOfTrees++;
    }
    return amountOfTrees;
}

void Floresta::killTree() {
    amountOfTrees--;
}
