//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_ISLAND_H
#define ISLANDSCLION_ISLAND_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string.h>
#include <initializer_list>
#include "Interface.h"

#include "Montanha.h"
#include "Deserto.h"
#include "Pastagem.h"
#include "Floresta.h"
#include "Pantano.h"
#include "ZonaX.h"

#include "MinaFerro.h"
#include "MinaCarvao.h"
#include "CentralEletrica.h"
#include "Bateria.h"
#include "Fundicao.h"

#include "Lenhador.h"
#include "Operario.h"
#include "Mineiro.h"

using namespace std;

class Island {
    int lines = rand()%(8-3 + 1) + 3;
    int cols = rand()%(16-3 + 1) + 3;
    bool roundOver = false;

//    Natural Zones
    int numOfMnt = 0;
    int numOfDsr = 0;
    int numOfPas = 0;
    int numOfFlr = 0;
    int numOfPnt = 0;
    int numOfZnZ = 0;


//    Buildings
    int numOfMnF = 0;
    int numOfMnC = 0;
    int numOfElec = 0;
    int numOfBat = 0;
    int numOfFun = 0;


//    Workers
    int numOfLenhadores = 0;
    int numOfOperarios = 0;
    int numOfMineiros = 0;


    vector<vector<string>> island;
//    vector<Territorio> territorios;
    int recursos;

public:

    void changeRoundStatus();

//    void addTerritorio(Territorio t) {territorios.push_back(t);}

    Island(bool loadedFile, int line, int col) {
        if (loadedFile == true) {
            loading();
        } else {
            inicializeIsland();
            randomizeNaturalZones();
        }
        recursos = 0;
//        list();
    }


    void randomizeNaturalZones();

    int getLine(){
        return lines;
    }

    int getCols(){
        return cols;
    }


    void loading();

    void morningEffects();


    void inicializeIsland();

    void afternoonPhase();

    void list();

    void cons(string type, int line, int col);

    void liga(int line, int col);

    void des(int line, int col);

    void move(int id, int line, int col);

    void vende(string type, int amount);

    void cont(string type);

    void next();

    void save(string saveName);

    void load(string saveName);

    void apagado(string saveName);

    void config(FILE *f1);

    void debcash(int dollaDollaBillzYo);

    void debed(string type, int line, int col);

    void debkill(int id);
};

#endif //ISLANDSCLION_ISLAND_H