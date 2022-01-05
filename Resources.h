//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_RESOURCES_H
#define ISLANDSCLION_RESOURCES_H
#include "Island.h"

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
        money = 0.0;
        madeira = 0.0;
        ferro = 0.0;
        barra = 0.0;
        carvao = 0.0;
        vigas = 0.0;
        eletricidade = 0.0;
    }

    double getWood();


    void acquireWood(double acquiredResource, double naturalMultiplier);
    void acquireIron(double acquiredResource, double naturalMultiplier);
    void acquireBarra(double acquiredResource, double naturalMultiplier);
    void acquireCoal(double acquiredResource, double naturalMultiplier);
    void acquireVigas(double acquiredResource, double naturalMultiplier);
    void acquireEletricidade(double acquiredResource, double naturalMultiplier);

    void sellWood();
    void sellIron();
    void sellCoal();
    void sellBarra();
    void sellViga();
    void sellEletricidade();

    void updateResources();

    void listResources();
};


#endif //ISLANDSCLION_RESOURCES_H
