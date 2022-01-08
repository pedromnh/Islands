//
// Created by Pedro Henriques on 22/11/2021.
//

#include "Resources.h"

void Resources::acquireWood(double acquiredResource, double naturalMultiplier) {
    madeira += acquiredResource * naturalMultiplier;
}

void Resources::acquireIron(double acquiredResource, double naturalMultiplier) {
    ferro += acquiredResource * naturalMultiplier;
}

void Resources::acquireBarra(double acquiredResource, double naturalMultiplier) {
    barra += acquiredResource * naturalMultiplier;
}

void Resources::acquireCoal(double acquiredResource, double naturalMultiplier) {
    carvao += acquiredResource * naturalMultiplier;
}

void Resources::acquireVigas(double acquiredResource, double naturalMultiplier) {
    vigas += acquiredResource * naturalMultiplier;
}

void Resources::acquireEletricidade(double acquiredResource, double naturalMultiplier) {
    eletricidade += acquiredResource * naturalMultiplier;
}

void Resources::listResources() {
    cout << "Madeira: " << madeira << endl <<
    "Ferro: " << ferro << endl <<
    "Barra: " << barra << endl <<
    "Carvao: " << carvao << endl <<
    "Vigas: " << vigas << endl <<
    "Eletricidade: " << eletricidade << endl;
}

void Resources::sellWood() {
    if (money >= 1) {
        madeira++;
        money--;
    } else { cout << money << " is not enough money." << endl; }
}

double Resources::getWood() {return madeira;}

void Resources::sellIron() {
    if (money >= 1) {
        ferro--;
        money++;
    } else { cout << money << " is not enough money." << endl; }
}

void Resources::sellCoal() {
    if (money >= 1) {
        carvao--;
        money++;
    } else { cout << money << " is not enough money." << endl; }
}

void Resources::sellBarra() {
    if (money >= 2) {
        barra--;
        money += 2;
    } else { cout << money << " is not enough money." << endl; }
}

void Resources::sellViga() {
    if (money >= 2) {
        vigas--;
        money += 2;
    } else { cout << money << " is not enough money." << endl; }
}

void Resources::sellEletricidade() {
    if (money >= 1.5) {
        eletricidade--;
        money += 1.5;
    } else { cout << money << " is not enough money." << endl; }
}
