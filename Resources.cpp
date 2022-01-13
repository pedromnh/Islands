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
    if (ferro >= 1.5 && carvao >= 0.5) {
        barra += acquiredResource * naturalMultiplier;
        ferro -= 1.5;
        carvao -= 0.5;
    }
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
    cout << fixed << setprecision(2) << "Dinheiro: " << money << "€" << endl << setprecision(1) <<
    "---------------------" << endl <<
    "Madeira: " << madeira << endl <<
    "Ferro: " << ferro << endl <<
    "Barra: " << barra << endl <<
    "Carvao: " << carvao << endl <<
    "Vigas: " << vigas << endl <<
    "Eletricidade: " << eletricidade << endl;
}

void Resources::sellWood() {
    if (madeira >= 1) {
        money++;
        madeira--;
    }
}

double Resources::getWood() {return madeira;}

void Resources::sellIron() {
    if (ferro >= 1) {
        ferro--;
        money++;
    }
}

void Resources::sellCoal() {
    if (carvao >= 1) {
        carvao--;
        money++;
    }
}

void Resources::sellBarra() {
    if (barra >= 1) {
        barra--;
        money += 2;
    }
}

void Resources::sellViga() {
    if (vigas >= 1) {
        vigas--;
        money += 2;
    }
}

void Resources::sellEletricidade() {
    if (eletricidade >= 1) {
        eletricidade--;
        money += 1.5;
    }
}

double Resources::getMoney() {
    return money;
}

void Resources::chooseResourceToSell(string type, int amount) {
    double startingMoney = getMoney();
    for (int i = 0; i < amount; ++i) {
        if (type == "madeira") {
            sellWood();
        } else if (type == "ferro") {
            sellIron();
        } else if (type == "barra") {
            sellBarra();
        } else if (type == "carvao") {
            sellCoal();
        } else if (type == "viga") {
            sellViga();
        } else if (type == "eletricidade") {
            sellEletricidade();
        }
    }
    cout << fixed << setprecision(2) << "You've earned +" << getMoney() - startingMoney << "€!" << endl;
}

void Resources::setMoney(double euro) {
    money = euro;
}

void Resources::chooseResourceToBuy(std::string type, int amount) {
    double startingMoney = getMoney();
    for (int i = 0; i < amount; ++i) {
        if (type == "viga") {
            buyViga();
        }
    }
    cout << fixed << setprecision(2) << "You've spent -" << startingMoney - getMoney() << "€!" << endl;
}

void Resources::buyViga() {
    if (money >= 10) {
        vigas++;
        money-=10;
    }
}

double Resources::getVigas() {
    return vigas;
}

void Resources::setVigas(double viga) {
    vigas = viga;
}
