//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_RESOURCES_H
#define ISLANDSCLION_RESOURCES_H
#include "Island.h"
#include <iomanip>

class Resources {
private:
    double money;
    double ferro;
    double barra;
    double carvao;
    double madeira;
    double vigas;
    double eletricidade;

public:
    Resources() {
        money = 20.0;
        madeira = 5.0;
        ferro = 10.0;
        barra = 20.0;
        carvao = 30.0;
        vigas = 40.0;
        eletricidade = 50.0;
    }

    double getWood();


    void acquireWood(double acquiredResource, double naturalMultiplier);
    void acquireIron(double acquiredResource, double naturalMultiplier);
    void acquireBarra(double acquiredResource, double naturalMultiplier);
    void acquireCoal(double acquiredResource, double naturalMultiplier);
    void acquireVigas(double acquiredResource, double naturalMultiplier);
    void acquireEletricidade(double acquiredResource, double naturalMultiplier);

    void chooseResourceToSell(std::string type, int amount);
    void sellWood();
    void sellIron();
    void sellCoal();
    void sellBarra();
    void sellViga();
    void sellEletricidade();

    double getMoney();


    void listResources();
};


#endif //ISLANDSCLION_RESOURCES_H
