//
// Created by Pedro Henriques on 22/11/2021.
//

#include "Resources.h"

void Resources::acquireWood(double naturalMultiplier) {
    madeira += madeira * naturalMultiplier;
}

void Resources::acquireIron(double naturalMultiplier) {
    ferro += ferro * naturalMultiplier;
}

void Resources::acquireBarra(double naturalMultiplier) {
    barra += barra * naturalMultiplier;
}

void Resources::acquireCoal(double naturalMultiplier) {
    carvao += carvao * naturalMultiplier;
}

void Resources::acquireVigas(double naturalMultiplier) {
    vigas += vigas * naturalMultiplier;
}

void Resources::acquireEletricidade(double naturalMultiplier) {
    eletricidade += eletricidade * naturalMultiplier;
}

void Resources::listResources() {
    cout << "Madeira: " << madeira << endl <<
    "Ferro: " << ferro << endl <<
    "Barra: " << barra << endl <<
    "Carvao: " << carvao << endl <<
    "Vigas: " << vigas << endl <<
    "Eletricidade: " << eletricidade << endl;
}
