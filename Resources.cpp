//
// Created by Pedro Henriques on 22/11/2021.
//

#include "Resources.h"

void Resources::acquireWood(double acquiredResource, double naturalMultiplier) {
    madeira += acquiredResource * naturalMultiplier;
}

void Resources::acquireIron(double acquiredResource, double naturalMultiplier, int level) {
    auto levelDouble = static_cast<double>(level) - 1;
    ferro += (levelDouble + acquiredResource * 2) * naturalMultiplier;
}

void Resources::acquireBarra(double acquiredResource, double naturalMultiplier) {
    if (ferro >= 1.5 && carvao >= 0.5) {
        barra += acquiredResource * naturalMultiplier;
        ferro -= 1.5;
        carvao -= 0.5;
    }
}

void Resources::acquireCoal(double acquiredResource, double naturalMultiplier, int level) {
    auto levelDouble = static_cast<double>(level);
    carvao += (levelDouble * acquiredResource) * naturalMultiplier;
}

void Resources::acquireVigas(double acquiredResource, double naturalMultiplier) {
    if (madeira >= 2) {
        vigas += acquiredResource * naturalMultiplier;
        madeira -= 2;
    }
}

void Resources::acquireEletricidade(double acquiredResource, double naturalMultiplier) {
    if (carvao >= 1) {
        eletricidade += acquiredResource * naturalMultiplier;
        carvao --;
    }
}

void Resources::listResources() {
    cout << fixed << setprecision(2) << "Dinheiro: " << money << "€" << endl << setprecision(1) <<
    "---------------------" << endl <<
    "Madeira: " << madeira << "/" << maxMadeira << endl <<
    "Ferro: " << ferro << "/" << maxFerro << endl <<
    "Barra: " << barra << "/" << maxBarra << endl <<
    "Carvao: " << carvao << "/" << maxCarvao << endl <<
    "Vigas: " << vigas << "/" << maxVigas << endl <<
    "Eletricidade: " << eletricidade << "/" << maxEletricidade << endl;
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

void Resources::setWood(double wood) {
    madeira = wood;
}

void Resources::setCoal(double coal) {
    carvao = coal;
}

double Resources::getCoal() {
    return carvao;
}

double Resources::getMaxFerro() const {
    return maxFerro;
}

double Resources::getMaxBarra() const {
    return maxBarra;
}

double Resources::getMaxCarvao() const {
    return maxCarvao;
}

double Resources::getMaxMadeira() const {
    return maxMadeira;
}

double Resources::getMaxVigas() const {
    return maxVigas;
}

double Resources::getMaxEletricidade() const {
    return maxEletricidade;
}

double Resources::getIron() {
    return ferro;
}

void Resources::setIron(double iron) {
    ferro = iron;
}

double Resources::getBarra() const {
    return barra;
}

void Resources::setBarra(double steel) {
    barra = steel;
}

double Resources::getEletricidade() {
    return eletricidade;
}

void Resources::setEletricidade(double electro) {
    eletricidade = electro;
}

void Resources::setMaxWood(double wood) {
    maxMadeira = wood;
}

void Resources::setMaxIron(double iron) {
    maxFerro = iron;
}

void Resources::setMaxVigas(double viga) {
    maxVigas = viga;
}

void Resources::setMaxEletricidade(double electro) {
    maxEletricidade = electro;
}

void Resources::setMaxBarra(double steel) {
    maxBarra = steel;
}

void Resources::setMaxCoal(double coal) {
    maxCarvao = coal;
}