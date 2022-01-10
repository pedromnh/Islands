//
// Created by Pedro Henriques on 22/11/2021.
//

#include "Floresta.h"

int Floresta::generateRandomTrees() {
    return rand() % 40 + 20;
}

int Floresta::getTreeCount() {
    return amountOfTrees;
}

void Floresta::growTree(int day) {
    if ((day % 2) == 0) {
        amountOfTrees++;
    }
}

void Floresta::killTree() {
    amountOfTrees--;
}
