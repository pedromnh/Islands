//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_RESOURCES_H
#define ISLANDSCLION_RESOURCES_H
#include "Island.h"

class Resources {
private:
    double ferro;
    double barra;
    double carvao;
    double madeira;
    double vigas;
    double eletricidade;

public:
    Resources() {
        madeira = 0.0;
        ferro = 0.0;
        barra = 0.0;
        carvao = 0.0;
        vigas = 0.0;
        eletricidade = 0.0;
    }


    void acquireWood(double naturalMultiplier);
    void acquireIron(double naturalMultiplier);
    void acquireBarra(double naturalMultiplier);
    void acquireCoal(double naturalMultiplier);
    void acquireVigas(double naturalMultiplier);
    void acquireEletricidade(double naturalMultiplier);


    void updateResources();

    void listResources();
};


#endif //ISLANDSCLION_RESOURCES_H
