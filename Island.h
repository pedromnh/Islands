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


    vector<vector<string>> island;
//    vector<Territorio> territorios;
    int recursos;

public:

    void changeRoundStatus();

//    void addTerritorio(Territorio t) {territorios.push_back(t);}

    Island(bool loadedFile, int line, int col) {
        if (loadedFile == true) {
            loading(0);
        } else {
            inicializeIsland();
            randomizeNaturalZones();
        }
        recursos = 0;
//        list();
    }


    void randomizeNaturalZones();
    static void listNaturalZones();
    static void listBuildings();
    static void listWorkers();

    int getLine(){
        return lines;
    }

    int getCols(){
        return cols;
    }


    void loading(int day);

    void morningEffects(int day);

    void inicializeIsland();

    void afternoonPhase(int day);

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



    void collectResources(int currentDay);
    static void collectNaturalResources(int currentDay);
    void collectBuildingResources();
    void printTree(int day);
    static void printAtCoordinates(int x, int y);
    static void printZoneAtCoordinates(int x, int y);
    static void printBuildingAtCoordinates(int x, int y);
    static void printWorkersAtCoordinates(int x, int y);
    static void printHelp();
    void disableBuildingAtCoordinates(int x, int y);
    void enableBuildingAtCoordinates(int x, int y);
    void updateBuildingStatuses();
    void updateChanceOfQuitting(int currentDay);
    static void workerQuits(int x, int y, bool pantano);
    void updateChanceOfDestroyingBuilding(int currentDay);
    void buildingIsDestroyed(int x, int y);
    bool checkForAdjacentForest(int x, int y);
    bool checkForAdjacentBuilding(string type, int x, int y);
    void levelUpBuilding(string nameOfBuilding);
    static void moveID(std::string id);
};

#endif //ISLANDSCLION_ISLAND_H
