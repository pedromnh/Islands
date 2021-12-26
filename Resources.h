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
        ferro = 0.0;
        barra = 0.0;
        carvao = 0.0;
        madeira = 0.0;
        vigas = 0.0;
        eletricidade = 0.0;
    }

    void acquireResources();
};


#endif //ISLANDSCLION_RESOURCES_H
