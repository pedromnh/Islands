//
// Created by Pedro Henriques on 22/11/2021.
//

#include <fstream>
#include "Island.h"

Zones zone;
Buildings building;
Workers worker;
Resources resources;


void Island::list() {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            cout << island[i][j] << "\t\t";
        }
        cout << endl << endl << endl << endl;
    }
    cout << "Total de trabalhadores: " << worker.getTotalWorkerCount() << endl <<
    "Numero de lenhadores: " << worker.getAmountOfLenhadores() << endl <<
    "Numero de mineiros: " << worker.getAmountOfMineiros() << endl <<
    "Numero de operarios: " << worker.getAmountOfOperarios() << endl;
}


void Island::inicializeIsland(){
    string auxIsland[lines][cols];
    vector<vector<string>> vec;
    vector< vector<string> > v(lines, vector<string> (cols, "___"));
    island = v;
}



void Island::cons(string type, int line, int col){
    if (island.at(line - 1).at(col - 1).find("mnF") != string::npos
    || island.at(line - 1).at(col - 1).find("mnC") != string::npos
    || island.at(line - 1).at(col - 1).find("elec") != string::npos
    || island.at(line - 1).at(col - 1).find("bat") != string::npos
    || island.at(line - 1).at(col - 1).find("fun") != string::npos
    || island.at(line - 1).at(col - 1).find("znX") != string::npos) {
        cout << "Can't overwrite in that position." << endl;
    } else {
        island.at(line - 1).at(col - 1) = type;
        if (type.find("mnF") != string::npos) {
            building.incrementMnF();
            roundOver = true;
        } else if (type.find("mnC") != string::npos) {
            building.incrementMnC();
            roundOver = true;
        } else if (type.find("elec") != string::npos) {
            building.incrementElec();
            roundOver = true;
        } else if (type.find("bat") != string::npos) {
            building.incrementBat();
            roundOver = true;
        } else if (type.find("fun") != string::npos) {
            building.incrementFun();
            roundOver = true;
        } else if (type.find("znX") != string::npos) {
            building.incrementBuildingX();
            roundOver = true;
        }
    }
}


//void Island::cons(string type, int line, int col){
//    for (auto & edificio : building.edificios) {
//        if (edificio->getCoordinateX() == (line - 1) && edificio->getCoordinateY() == (col - 1)) {
//            cout << "Can't overwrite in that position." << endl;
//        } else {
//            island.at(line - 1).at(col - 1) = edificio->getName();
//            if (edificio->getType() == "minaFerro") {
//                building.incrementMnF();
//                roundOver = true;
//            } else if (edificio->getType() == "minaCarvao") {
//                building.incrementMnC();
//                roundOver = true;
//            } else if (edificio->getType() == "centralEletrica") {
//                building.incrementElec();
//                roundOver = true;
//            } else if (edificio->getType() == "bateria") {
//                building.incrementBat();
//                roundOver = true;
//            } else if (edificio->getType() == "fundicao") {
//                building.incrementFun();
//                roundOver = true;
//            }
//        }
//    }
//}


void Island::liga(int line, int col) {
    //island.at(line - 1).at(col - 1);
    cout << "[PLACEHOLDER]: ligado" << endl;
}


void Island::des(int line, int col) {
    //island.at(line - 1).at(col - 1);
    cout << "[PLACEHOLDER]: des" << endl;
}


void Island::move(int id, int line, int col) {
    //island.at(line - 1).at(col - 1);
    cout << "[PLACEHOLDER]: moveID" << endl;
}


void Island::vende(string type, int amount) {
    //island.at(line - 1).at(col - 1);
    cout << "[PLACEHOLDER]: vende (recursos)" << endl;
}

void Island::cont(string type) {
    if (type.find("lenhador") != string::npos) {
        worker.incrementLenhadores();
        roundOver = true;
    } else if (type.find("operario") != string::npos) {
        worker.incrementOperarios();
        roundOver = true;
    } else if (type.find("mineiro") != string::npos) {
        worker.incrementMineiros();
        roundOver = true;
    }
}


void Island::next() {
    //island.at(line - 1).at(col - 1);
    cout << "Skipping..." << endl;
    changeRoundStatus();
}

void Island::save(string saveName) {
    //island.at(line - 1).at(col - 1);
    cout << "[PLACEHOLDER]: save" << endl;
}

void Island::morningEffects(int day) {
    cout << "Occurring zone events..." << endl;
    updateChanceOfQuitting(day);
    updateChanceOfDestroyingBuilding(day);
}

void Island::randomizeNaturalZones() {
    int randomizer;
    for (int y = 1; y <= lines; y++) {
        for (int x = 1; x <= cols; x++) {
            randomizer = rand()% 6 + 0;
            if (zone.getAmountOfZnZ() > 0) {
                while (randomizer == 5) {
                    randomizer = rand()% 6 + 0;
                }
            }
            switch (randomizer) {
                case 0:
                    zone.zonasNaturais.emplace_back(new Montanha(zone.getAmountOfMnt(), x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    zone.incrementMnt();
                    break;
                case 1:
                    zone.zonasNaturais.emplace_back(new Deserto(zone.getAmountOfDsr(), x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    zone.incrementDsr();
                    break;
                case 2:
                    zone.zonasNaturais.emplace_back(new Pastagem(zone.getAmountOfPas(), x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    zone.incrementPas();
                    break;
                case 3:
                    zone.zonasNaturais.emplace_back(new Floresta(zone.getAmountOfFlr(), x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    zone.incrementFlr();
                    break;
                case 4:
                    zone.zonasNaturais.emplace_back(new Pantano(zone.getAmountOfPnt(), x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    zone.incrementPnt();
                    break;
                case 5:
                    zone.zonasNaturais.emplace_back(new ZonaX(zone.getAmountOfZnZ(), x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    zone.incrementZnZ();
                    break;
                default:
                    cout << "How did you get here?" << endl;
            }

        }
    }
}

void Island::afternoonPhase(int day) {
    string cmd, type;
    int line, col, amount;

    do {
        roundOver = false;
        cout << "Insert a command: " << endl;
        cin >> cmd;
        if (cmd == "cons") {
            cin >> type >> line >> col;
            if (type == "mnF") {
                if (resources.getVigas() >= 10 && !checkIfBuildingExistsAtLocation(line, col)) {
                    building.edificios.emplace_back(new MinaFerro(building.getAmountOfMnF(), line, col, day));
                    cons(building.edificios.back()->getName(),
                         building.edificios.back()->getCoordinateY(),
                         building.edificios.back()->getCoordinateX()
                    );
                    resources.setVigas(resources.getVigas() - 10);
                }
            } else if (type == "mnC") {
                if (resources.getVigas() >= 10 && !checkIfBuildingExistsAtLocation(line, col)) {
                    building.edificios.emplace_back(new MinaCarvao(building.getAmountOfMnC(), line, col, day));
                    cons(building.edificios.back()->getName(),
                         building.edificios.back()->getCoordinateY(),
                         building.edificios.back()->getCoordinateX()
                    );
                    resources.setVigas(resources.getVigas() - 10);
                }
            } else if (type == "elec") {
                if (checkForAdjacentForest(line, col)) {
                    if (resources.getMoney() >= 15 && !checkIfBuildingExistsAtLocation(line, col)) {
                        building.edificios.emplace_back(new CentralEletrica(building.getAmountOfElec(), line, col, day));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                        resources.setMoney(resources.getMoney() - 15);
                    }
                } else {
                    cout << "Didn't find an adjacent forest" << endl;
                }
            } else if (type == "bat") {
                if (checkForAdjacentBuilding("bateria", line, col)) {
                    if (resources.getMoney() >= 10 && resources.getVigas() >= 10 && !checkIfBuildingExistsAtLocation(line, col)) {
                        building.edificios.emplace_back(new Bateria(building.getAmountOfBat(), line, col, day));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                        resources.setMoney(resources.getMoney() - 10);
                        resources.setVigas(resources.getVigas() - 10);
                    }
                } else {
                    cout << "Didn't find any adjacent electrical centers." << endl;
                }
            } else if (type == "fun") {
                if (checkForAdjacentBuilding("fundicao", line, col)) {
                    if (resources.getMoney() >= 10 && !checkIfBuildingExistsAtLocation(line, col)) {
                        building.edificios.emplace_back(new Fundicao(building.getAmountOfFun(), line, col, day));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                        resources.setMoney(resources.getMoney() - 10);
                    }
                } else {
                    cout << "Didn't find any adjacent mines or electrical centers." << endl;
                }
            } else if (type == "znX") {
                if (checkIfOnForest(line, col)) {
                    if (resources.getMoney() >= 25 && !checkIfBuildingExistsAtLocation(line, col)) {
                        building.edificios.emplace_back(new BuildingX(building.getAmountOfBuildingX(), line, col, day));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                        resources.setMoney(resources.getMoney() - 25);
                        roundOver = true;
                    }
                }
            }
        } else if (cmd == "cont") {
            cin >> type;
            if (type == "lenhador") {
                if (resources.getMoney() >= 20) {
                    worker.trabalhadores.emplace_back(new Lenhador(worker.getTotalWorkerCount(), day));
                    cont(worker.trabalhadores.back()->getType());
                    resources.setMoney(resources.getMoney() - 20);
                    roundOver = true;
                }
            } else if (type == "mineiro") {
                if (resources.getMoney() >= 10) {
                    worker.trabalhadores.emplace_back(new Mineiro(worker.getTotalWorkerCount(), day));
                    cont(worker.trabalhadores.back()->getType());
                    resources.setMoney(resources.getMoney() - 10);
                    roundOver = true;
                }
            } else if (type == "operario") {
                if (resources.getMoney() >= 15) {
                    worker.trabalhadores.emplace_back(new Operario(worker.getTotalWorkerCount(), day));
                    cont(worker.trabalhadores.back()->getType());
                    resources.setMoney(resources.getMoney() - 15);
                    roundOver = true;
                }
            }
        } else if (cmd == "list") {
            list();
        } else if (cmd == "liga") {
            cin >> line >> col;
            enableBuildingAtCoordinates(line, col);
        } else if (cmd == "des") {
            cin >> line >> col;
            disableBuildingAtCoordinates(line, col);
        } else if (cmd == "move") {
            cin >> type;
            moveID(type);
        } else if (cmd == "next") {
            next();
        } else if (cmd == "save") {
            save("saveName");
        } else if (cmd == "vende") {
            vende("Ferro", 3);
        } else if (cmd == "listNat") {
            listNaturalZones();
        } else if (cmd == "printTree") {
            printTree(day);
        } else if (cmd == "listBuildings") {
            listBuildings();
        } else if (cmd == "listWorkers") {
            listWorkers();
        } else if (cmd == "atCoords") {
            cin >> line >> col;
            printAtCoordinates(line, col);
        } else if (cmd == "listResources") {
            resources.listResources();
        } else if (cmd == "sell") {
            cin >> type >> amount;
            resources.chooseResourceToSell(type, amount);
        } else if (cmd == "skip") {
            cout << "Skipping turn..." << endl;
            roundOver = true;
        } else if (cmd == "help") {
            printHelp();
        } else if (cmd == "buy") {
            cin >> type >> amount;
            resources.chooseResourceToBuy(type, amount);
        } else if (cmd == "levelUp") {
            cin >> type;
            levelUpBuilding(type);
        } else if (cmd == "transform") {
            cin >> type >> amount;
            transform(type, amount);
        } else {
                cout << "Invalid command." << endl;
        }
        } while (!roundOver);

}

void Island::changeRoundStatus() {
    if (roundOver) {
        roundOver = false;
    } else {
        roundOver = true;
    }
}

void Island::loading(int day) {
    string linesAndCols, commands, cmd, type;
    ifstream configFile("Islands.txt");
    int amountOfWords;
    int linePosition, colPosition;

    if (configFile.is_open()) {
        getline(configFile, linesAndCols);
        istringstream is (linesAndCols);
        is >> lines >> cols;
        inicializeIsland();
        randomizeNaturalZones();
//        cout << lines << " + " << cols << endl;
        while (configFile) {
            getline(configFile, commands);
            istringstream cs (commands);
            string sentence = cs.str();
            amountOfWords = count(sentence.cbegin(), sentence.cend(), ' ') + 1;

            if (amountOfWords == 4) {
                cs >> cmd >> type >> linePosition >> colPosition;
//                cout << cmd << " + " << type << " + " << linePosition << " + " << colPosition << endl;
                if (cmd == "cons") {
                    if (type == "mnF") {
                        building.edificios.emplace_back(new MinaFerro(building.getAmountOfMnF(), linePosition, colPosition, day));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "mnC") {
                        building.edificios.emplace_back(new MinaCarvao(building.getAmountOfMnC(), linePosition, colPosition, day));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "elec") {
                        building.edificios.emplace_back(new CentralEletrica(building.getAmountOfElec(), linePosition, colPosition, day));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "bat") {
                        building.edificios.emplace_back(new Bateria(building.getAmountOfBat(), linePosition, colPosition, day));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "fun") {
                        building.edificios.emplace_back(new Fundicao(building.getAmountOfFun(), linePosition, colPosition, day));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    }
                }
            } else if (amountOfWords == 2) {
                cs >> cmd >> type;
//                cout << cmd << " + " << type;
                if (cmd == "cont") {
                    if (type == "lenhador") {
                        worker.trabalhadores.emplace_back(new Lenhador(worker.getTotalWorkerCount(), day));
                        cont(worker.trabalhadores.back()->getType());
                    } else if (type == "mineiro") {
                        worker.trabalhadores.emplace_back(new Mineiro(worker.getTotalWorkerCount(), day));
                        cont(worker.trabalhadores.back()->getType());
                    } else if (type == "operario") {
                        worker.trabalhadores.emplace_back(new Operario(worker.getTotalWorkerCount(), day));
                        cont(worker.trabalhadores.back()->getType());
                    }
                }
            } else if (amountOfWords == 1) {
                cs >> cmd;
//                cout << cmd;
                if (cmd == "list") {
                    list();
                } else if (cmd == "liga") {
                    liga(linePosition, colPosition);
                } else if (cmd == "des") {
                    des(linePosition, colPosition);
                } else if (cmd == "moveID") {
                    move(1, linePosition, colPosition);
                } else if (cmd == "next") {
                    next();
                } else if (cmd == "save") {
                    save("saveName");
                } else if (cmd == "vende") {
                    vende("Ferro", 3);
                }

            }
        }
    } else
        cout << "Could not open the file." << endl;

    configFile.close();
    cout << endl;
}

void Island::listNaturalZones() {
    cout << "There are " << zone.zonasNaturais.size() << " natural zones." << endl;
    for (auto & zonasNatural : zone.zonasNaturais) {
        cout << zonasNatural->getName()<< ": "
             << "x="
             << zonasNatural->getCoordinateX()
             << " ; y="
             << zonasNatural->getCoordinateY() << endl;
    }
}

void Island::collectResources(int currentDay) {
    collectNaturalResources(currentDay);
    collectBuildingResources(currentDay);
    resources.listResources();
}

void Island::collectNaturalResources(int currentDay) {
    int naturalX, naturalY, workerX, workerY;
    for (auto & zonaNat : zone.zonasNaturais) {
        if (zonaNat->getType() == "floresta" && zonaNat->getTreeCount() > 0) {
            naturalX = zonaNat->getCoordinateX();
            naturalY = zonaNat->getCoordinateY();


            for (auto & trabalhador : worker.trabalhadores) {
                if (trabalhador->getType() == "lenhador") {
                    workerX = trabalhador->getCoordinateX();
                    workerY = trabalhador->getCoordinateY();


                    if (naturalX == workerX && naturalY == workerY && (trabalhador->getDaysWorking(currentDay)) % 5 != 0) {
                        resources.acquireWood(1, 1);
                    }
                }
            }
        }
    }
}

void Island::collectBuildingResources(int currentDay) {
    int workerX, workerY, buildingX, buildingY;
    string status;
    for (int i = 0; i < building.edificios.size(); ++i) {
        if (building.edificios.at(i)->getType() == "minaCarvao") {
            buildingX = building.edificios.at(i)->getCoordinateX();
            buildingY = building.edificios.at(i)->getCoordinateY();
            status = building.edificios.at(i)->getStatus();


            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "mineiro") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }
                if (buildingX == workerX && buildingY == workerY && status == "Enabled"
                && findTypeOfNaturalZone(buildingX, buildingY) == "deserto") {
//                    cout << "Half coal." << endl;
                    resources.acquireCoal(1, 0.5, building.edificios.at(i)->getLevel());
                } else if (buildingX == workerX && buildingY == workerY && status == "Enabled"
                && findTypeOfNaturalZone(buildingX, buildingY) == "montanha") {
                    resources.acquireCoal(1, 2, building.edificios.at(i)->getLevel());
//                    cout << "Double coal." << endl;
                } else if (buildingX == workerX && buildingY == workerY && status == "Enabled"
                && findTypeOfNaturalZone(buildingX, buildingY) == "floresta") {
                    resources.acquireCoal(1, 1, building.edificios.at(i)->getLevel());
                    killTreeFromForestAtCoords(buildingX, buildingY);
//                    cout << "Normal coal but tree died." << endl;
                } else if (buildingX == workerX && buildingY == workerY && status == "Enabled") {
                    resources.acquireCoal(1, 1, building.edificios.at(i)->getLevel());
                }
            }
        } else if (building.edificios.at(i)->getType() == "minaFerro") {
            buildingX = building.edificios.at(i)->getCoordinateX();
            buildingY = building.edificios.at(i)->getCoordinateY();
            status = building.edificios.at(i)->getStatus();


            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "mineiro") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }
                if (buildingX == workerX && buildingY == workerY && status == "Enabled"
                    && findTypeOfNaturalZone(buildingX, buildingY) == "deserto") {
//                    cout << "Half iron." << endl;
                    resources.acquireIron(1, 0.5, building.edificios.at(i)->getLevel());
                } else if (buildingX == workerX && buildingY == workerY && status == "Enabled"
                           && findTypeOfNaturalZone(buildingX, buildingY) == "montanha") {
                    resources.acquireIron(1, 2, building.edificios.at(i)->getLevel());
//                    cout << "Double Iron." << endl;
                } else if (buildingX == workerX && buildingY == workerY && status == "Enabled"
                           && findTypeOfNaturalZone(buildingX, buildingY) == "floresta") {
                    resources.acquireIron(1, 1, building.edificios.at(i)->getLevel());
                    killTreeFromForestAtCoords(buildingX, buildingY);
//                    cout << "Normal iron but tree died." << endl;
                } else if (buildingX == workerX && buildingY == workerY && status == "Enabled") {
                    resources.acquireIron(1, 1, building.edificios.at(i)->getLevel());
                }
            }
        } else if (building.edificios.at(i)->getType() == "fundicao") {
            buildingX = building.edificios.at(i)->getCoordinateX();
            buildingY = building.edificios.at(i)->getCoordinateY();
            status = building.edificios.at(i)->getStatus();


            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "operario") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }
                if (buildingX == workerX && buildingY == workerY && status == "Enabled") {
                    resources.acquireBarra(1, 1);
                }
            }
        } else if (building.edificios.at(i)->getType() == "centralEletrica") {
            buildingX = building.edificios.at(i)->getCoordinateX();
            buildingY = building.edificios.at(i)->getCoordinateY();
            status = building.edificios.at(i)->getStatus();


            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "operario") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }
                if (buildingX == workerX && buildingY == workerY && status == "Enabled") {
                    resources.acquireCoal(1, 1, building.edificios.at(i)->getLevel());
                }
            }
        } else if (building.edificios.at(i)->getType() == "bateria") {
            resources.acquireEletricidade(1, 1);
        } else if (building.edificios.at(i)->getType() == "serracao") {
            buildingX = building.edificios.at(i)->getCoordinateX();
            buildingY = building.edificios.at(i)->getCoordinateY();
            status = building.edificios.at(i)->getStatus();


            for (auto & trabalhador : worker.trabalhadores) {
                if (trabalhador->getType() == "lenhador") {
                    workerX = trabalhador->getCoordinateX();
                    workerY = trabalhador->getCoordinateY();
                }
                if (buildingX == workerX && buildingY == workerY && status == "Enabled" && (trabalhador->getDaysWorking(currentDay)) % 5 != 0) {
                    resources.acquireVigas(1, 1);
                }
            }
        }
    }
}

void Island::printTree(int day) {
    for (int i = 0; i < zone.zonasNaturais.size(); ++i) {
        if (zone.zonasNaturais.at(i)->getType() == "floresta") {
            cout << zone.zonasNaturais.at(i)->getName() <<
            " has " <<
            zone.zonasNaturais.at(i)->getTreeCount() <<
            " trees." << endl;
//            zone.zonasNaturais.at(i)->growTree(day);
        }
    }
}

void Island::listBuildings() {
    cout << "There are " << building.edificios.size() << " buildings." << endl;
    for (auto & edificio : building.edificios) {
        cout << edificio->getName()<< "(" << edificio->getLevel() << "): "
             << "x="
             << edificio->getCoordinateX()
             << " ; y="
             << edificio->getCoordinateY()
             << " -> " << edificio->getStatus() <<endl;
    }
}

void Island::listWorkers() {
    if (worker.trabalhadores.size() == 1) {
        cout << "There is " << worker.trabalhadores.size() << " worker." << endl;
    } else {
        cout << "There are " << worker.trabalhadores.size() << " workers." << endl;
    }
    for (auto & trabalhador : worker.trabalhadores) {
        cout << trabalhador->getType()
             << ", "
             << trabalhador->getWorkerId()
             << ": x="
             << trabalhador->getCoordinateX()
             << " ; y="
             << trabalhador->getCoordinateY() << endl;
    }
}

void Island::printZoneAtCoordinates(int x, int y) {
    for (auto & zonasNatural : zone.zonasNaturais) {
        if (zonasNatural->getCoordinateX() == x && zonasNatural->getCoordinateY() == y) {
            cout << zonasNatural->getName() << endl;
        }
    }
}

void Island::printBuildingAtCoordinates(int x, int y) {
    int numOfBuildings = 0;
    for (auto & edificio : building.edificios) {
        if (edificio->getCoordinateX() == x && edificio->getCoordinateY() == y) {
            cout << edificio->getName() << " -> " << edificio->getStatus() << endl;
            numOfBuildings++;
        }
    }
    if (numOfBuildings == 0) {
        cout << "There are no buildings built at that position." << endl;
    }
}

void Island::printWorkersAtCoordinates(int x, int y) {
    int numOfWorkers = 0;
    for (auto & trabalhador : worker.trabalhadores) {
        if (trabalhador->getCoordinateX() == x && trabalhador->getCoordinateY() == y) {
            cout << trabalhador->getType() << ", "<< trabalhador->getWorkerId() << endl;
            numOfWorkers++;
        }
    }
    if (numOfWorkers == 0) {
        cout << "There are no workers at that position." << endl;
    }
}

void Island::printAtCoordinates(int x, int y) {
    cout << "Printing zones..." << endl;
    printZoneAtCoordinates(x, y);
    cout <<  endl << "Printing buildings..." << endl;
    printBuildingAtCoordinates(x, y);
    cout << endl << "Printing workers..." << endl;
    printWorkersAtCoordinates(x, y);
}

void Island::printHelp() {
    cout << "cons <building> <line> <col>\n"
            "cont <type> <line> <col>\n"
            "list\n"
            "liga <line> <col>\n"
            "des <line> <col>\n"
            "next\n"
            "save <saveName>\n"
            "listNat\n"
            "printTree\n"
            "listBuildings\n"
            "listWorkers\n"
            "atCoords <line> <col>\n"
            "listResources\n"
            "sell <type> <amount>\n"
            "skip\n"
            "buy <type> <amount>\n"
            "levelUp\n"
            "moveID <id> <line> <col>\n"
            "transform <type> <amount>\n"<< endl;
}


void Island::disableBuildingAtCoordinates(int x, int y) {
    int numOfBuildings = 0;
    for (auto & edificio : building.edificios) {
        if (edificio->getCoordinateX() == x && edificio->getCoordinateY() == y) {
            if (edificio->getStatus() == "Disabled") {
                cout << "That building is already disabled." << endl;
            } else {
                edificio->setStatus("Disabled");
                edificio->disableUserStatus();
                cout << "Disabled the building" << endl;
            }
            numOfBuildings++;
        }
    }
    if (numOfBuildings == 0) {
        cout << "There are no buildings built at that position." << endl;
    }
}

void Island::enableBuildingAtCoordinates(int x, int y) {
    int numOfBuildings = 0;
    for (auto & edificio : building.edificios) {
        if (edificio->getCoordinateX() == x && edificio->getCoordinateY() == y) {
            if (edificio->getStatus() == "Enabled") {
                cout << "That building is already enabled." << endl;
            } else {
                edificio->setStatus("Enabled");
                edificio->enableUserStatus();
                cout << "Enabled the building" << endl;
            }
            numOfBuildings++;
        }
    }
    if (numOfBuildings == 0) {
        cout << "There are no buildings built at that position." << endl;
    }
}

void Island::updateBuildingStatuses() {
    int buildingX, buildingY, workerX, workerY;
    string status, userStatus;
    for (int i = 0; i < building.edificios.size(); ++i) {
        if (building.edificios.at(i)->getType() == "minaCarvao") {
            buildingX = building.edificios.at(i)->getCoordinateX();
            buildingY = building.edificios.at(i)->getCoordinateY();
            status = building.edificios.at(i)->getStatus();
            userStatus = building.edificios.at(i)->getUserStatus();

            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "mineiro") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }

                if (buildingX == workerX && buildingY == workerY && status == "Disabled" && userStatus == "Enabled") {
                    building.edificios.at(i)->setStatus("Enabled");
                } else if (userStatus == "Disabled"){
                    building.edificios.at(i)->setStatus("Disabled");
                }
            }
        }

        else if (building.edificios.at(i)->getType() == "minaFerro") {
            buildingX = building.edificios.at(i)->getCoordinateX();
            buildingY = building.edificios.at(i)->getCoordinateY();
            status = building.edificios.at(i)->getStatus();
            userStatus = building.edificios.at(i)->getUserStatus();

            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "mineiro") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }

                if (buildingX == workerX && buildingY == workerY && status == "Disabled" && userStatus == "Enabled") {
                    building.edificios.at(i)->setStatus("Enabled");
                } else if (userStatus == "Disabled"){
                    building.edificios.at(i)->setStatus("Disabled");
                }
            }
        }

        else if (building.edificios.at(i)->getType() == "fundicao") {
            buildingX = building.edificios.at(i)->getCoordinateX();
            buildingY = building.edificios.at(i)->getCoordinateY();
            status = building.edificios.at(i)->getStatus();
            userStatus = building.edificios.at(i)->getUserStatus();

            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "operario") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }

                if (buildingX == workerX && buildingY == workerY && status == "Disabled" && userStatus == "Enabled") {
                    building.edificios.at(i)->setStatus("Enabled");
                } else if (userStatus == "Disabled"){
                    building.edificios.at(i)->setStatus("Disabled");
                }
            }
        }

        else if (building.edificios.at(i)->getType() == "centralEletrica") {
            buildingX = building.edificios.at(i)->getCoordinateX();
            buildingY = building.edificios.at(i)->getCoordinateY();
            status = building.edificios.at(i)->getStatus();
            userStatus = building.edificios.at(i)->getUserStatus();

            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "operario") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }

                if (buildingX == workerX && buildingY == workerY && status == "Disabled" && userStatus == "Enabled") {
                    building.edificios.at(i)->setStatus("Enabled");
                } else if (userStatus == "Disabled"){
                    building.edificios.at(i)->setStatus("Disabled");
                }
            }
        }
    }
}


void Island::updateChanceOfQuitting(int currentDay) {
    int chanceOfQuitting;
    int naturalX, naturalY, workerX, workerY;
    for (auto & zonaNatural : zone.zonasNaturais) {
        if (zonaNatural->getType() == "pastagem") {  //Chance of quitting in "Pastagem"
            naturalX = zonaNatural->getCoordinateX();
            naturalY = zonaNatural->getCoordinateY();
            for (auto & trabalhador : worker.trabalhadores) {
                workerX = trabalhador->getCoordinateX();
                workerY = trabalhador->getCoordinateY();

                if (naturalX == workerX && naturalY == workerY) {
                    trabalhador->setChanceOfQuitting(0);
                }
            }
        } else if (zonaNatural->getType() == "montanha") { //Chance of quitting in "Montanha"
            naturalX = zonaNatural->getCoordinateX();
            naturalY = zonaNatural->getCoordinateY();
            for (auto & trabalhador : worker.trabalhadores) {
                workerX = trabalhador->getCoordinateX();
                workerY = trabalhador->getCoordinateY();

                if (trabalhador->getType() == "mineiro" && trabalhador->getDaysWorking(currentDay) > 2) {
                    if (naturalX == workerX && naturalY == workerY) {
                        trabalhador->setChanceOfQuitting(15);
                        chanceOfQuitting = rand() % (101) + 0;
                        if (trabalhador->getChanceOfQuitting() >= chanceOfQuitting) {
                            workerQuits(workerX, workerY, false);
                        }
                    }
                } else if (trabalhador->getType() == "operario" && trabalhador->getDaysWorking(currentDay) > 10) {
                    if (naturalX == workerX && naturalY == workerY) {
                        trabalhador->setChanceOfQuitting(10);
                        chanceOfQuitting = rand() % (101) + 0;

                        if (trabalhador->getChanceOfQuitting() >= chanceOfQuitting) {
                            workerQuits(workerX, workerY, false);
                        }
                    }
                }
            }
        } else { //Chance of quitting in all other zones
            naturalX = zonaNatural->getCoordinateX();
            naturalY = zonaNatural->getCoordinateY();
            for (auto & trabalhador : worker.trabalhadores) {
                workerX = trabalhador->getCoordinateX();
                workerY = trabalhador->getCoordinateY();

                if (trabalhador->getType() == "mineiro" && trabalhador->getDaysWorking(currentDay) >= 2) {
                    if (naturalX == workerX && naturalY == workerY) {
                        trabalhador->setChanceOfQuitting(10);
                        chanceOfQuitting = rand() % (101) + 0;
                    }
                    if (trabalhador->getChanceOfQuitting() >= chanceOfQuitting) {
                        workerQuits(workerX, workerY, false);
                    }
                } else if (trabalhador->getType() == "operario" && trabalhador->getDaysWorking(currentDay) >= 10) {
                    if (naturalX == workerX && naturalY == workerY) {
                        trabalhador->setChanceOfQuitting(5);
                        chanceOfQuitting = rand() % (101) + 0;
                    }
                    if (trabalhador->getChanceOfQuitting() >= chanceOfQuitting) {
                        workerQuits(workerX, workerY, false);
                    }
                }
            }
        }
    }
}

void Island::workerQuits(int x, int y, bool pantano) {
    int amountOfRemoved = 0;
    for (auto it = worker.trabalhadores.begin(); it != worker.trabalhadores.end();) {
        if ((*it)->getCoordinateX() == x && (*it)->getCoordinateY() == y && pantano) {
            delete * it;
            it = worker.trabalhadores.erase(it);
        } else {
            ++it;
        }
    }

    for (auto it = worker.trabalhadores.begin(); it != worker.trabalhadores.end();) {
        if ((*it)->getCoordinateX() == x && (*it)->getCoordinateY() == y && !pantano && (*it)->getType() != "lenhador" && amountOfRemoved == 0) {
            cout << "A \"" << (*it)->getType() <<
                 "\", id: \"" << (*it)->getWorkerId() <<
                 "\" has quit!" << endl;
            delete * it;
            it = worker.trabalhadores.erase(it);
            amountOfRemoved++;
        } else {
            ++it;
        }
    }

}

void Island::buildingIsDestroyed(int x, int y) {
    for (auto it = building.edificios.begin(); it != building.edificios.end();) {
        if ((*it)->getCoordinateX() == x && (*it)->getCoordinateY() == y) {
            for (auto & zonaNatural : zone.zonasNaturais) {
                if (zonaNatural->getCoordinateX() == x && zonaNatural->getCoordinateY() == y) {
                    island.at(y - 1).at(x - 1) = zonaNatural->getName();
                }
            }
            delete * it;
            it = building.edificios.erase(it);
        } else {
            ++it;
        }
    }
}

void Island::updateChanceOfDestroyingBuilding(int currentDay) {
    int chanceOfDestroying;
    int naturalX, naturalY, buildingX, buildingY, workerX, workerY;

    for (auto & zonaNatural : zone.zonasNaturais) {
        if (zonaNatural->getType() == "pantano") {
            naturalX = zonaNatural->getCoordinateX();
            naturalY = zonaNatural->getCoordinateY();

            for (auto & edificio : building.edificios) {
                buildingX = edificio->getCoordinateX();
                buildingY = edificio->getCoordinateY();


                if (buildingX == naturalX && buildingY == naturalY && (currentDay - edificio->getDayBuilt()) == 10) {
                    cout << "A \"" << edificio->getType() <<
                         "\", \"" <<  edificio->getName() << "\" has been destroyed!!" << endl;
                    cout << "Firing everyone who was working at that location..." << endl;
                    workerQuits(buildingX, buildingY, true);
                    buildingIsDestroyed(buildingX, buildingY);
                }
            }
        } else {
            naturalX = zonaNatural->getCoordinateX();
            naturalY = zonaNatural->getCoordinateY();

            for (auto & edificio : building.edificios) {
                buildingX = edificio->getCoordinateX();
                buildingY = edificio->getCoordinateY();

                chanceOfDestroying = rand() % (101) + 0;
//                cout << edificio->getChanceOfBreaking() << " >= " << chanceOfDestroying << endl;
                if (edificio->getChanceOfBreaking() >= chanceOfDestroying && naturalX == buildingX && naturalY == buildingY) {
                    cout << "A \"" << edificio->getType() <<
                    "\", \"" <<  edificio->getName() << "\" has been destroyed!!" << endl;
                    buildingIsDestroyed(buildingX, buildingY);
                }
            }
        }
    }
}

bool Island::checkForAdjacentForest(int x, int y) {
    for (auto & zonaNatural : zone.zonasNaturais) {
        if (zonaNatural->getCoordinateX() == (x - 1) && zonaNatural->getCoordinateY() == (y - 1)
        || zonaNatural->getCoordinateX() == (x - 1) && zonaNatural->getCoordinateY() == y
        || zonaNatural->getCoordinateX() == (x - 1) && zonaNatural->getCoordinateY() == (y + 1)
        || zonaNatural->getCoordinateX() == (x) && zonaNatural->getCoordinateY() == (y - 1)
        || zonaNatural->getCoordinateX() == (x) && zonaNatural->getCoordinateY() == (y + 1)
        || zonaNatural->getCoordinateX() == (x + 1) && zonaNatural->getCoordinateY() == (y - 1)
        || zonaNatural->getCoordinateX() == (x + 1) && zonaNatural->getCoordinateY() == y
        || zonaNatural->getCoordinateX() == (x +1) && zonaNatural->getCoordinateY() == (y + 1)) {
            if (zonaNatural->getType() == "floresta") {
                cout << "Found an adjacent forest! \n";
                return true;
            }
        }
    }
    return false;
}

bool Island::checkForAdjacentBuilding(string type, int x, int y) {
    for (auto & edificio : building.edificios) {
        if (edificio->getCoordinateX() == (x - 1) && edificio->getCoordinateY() == (y - 1)
            || edificio->getCoordinateX() == (x - 1) && edificio->getCoordinateY() == y
            || edificio->getCoordinateX() == (x - 1) && edificio->getCoordinateY() == (y + 1)
            || edificio->getCoordinateX() == (x) && edificio->getCoordinateY() == (y - 1)
            || edificio->getCoordinateX() == (x) && edificio->getCoordinateY() == (y + 1)
            || edificio->getCoordinateX() == (x + 1) && edificio->getCoordinateY() == (y - 1)
            || edificio->getCoordinateX() == (x + 1) && edificio->getCoordinateY() == y
            || edificio->getCoordinateX() == (x + 1) && edificio->getCoordinateY() == (y + 1)) {
            if (type == "bateria") {
                if (edificio->getType() == "centralEletrica") {
                    return true;
                }
            } else if (type == "fundicao") {
                if (edificio->getType() == "minaCarvao" || edificio->getType() == "minaFerro" || edificio->getType() == "centralEletrica") {
                    return true;
                }
            }
        }
    }
    return false;
}

void Island::levelUpBuilding(string nameOfBuilding) {
    int foundOne = 0;
    for (auto & edificio : building.edificios) {
        if (edificio->getName() == nameOfBuilding) {
            foundOne++;
            if (edificio->getLevel() >= edificio->getMaxLevel()) {
                cout << "This building's already level cap." << endl;
            } else {
                if (edificio->getType() == "bateria") {
                    if (resources.getMoney() >= edificio->getCostOfLevelUp()) {
                        edificio->levelUp();
                        resources.setMoney(resources.getMoney() - edificio->getCostOfLevelUp());
                    } else {
                        cout << "Not enough money to purchase this upgrade." << endl;
                    }
                } else if (edificio->getType() == "minaCarvao") {
                    if (resources.getMoney() >= edificio->getCostOfLevelUp() && resources.getVigas() >= 1) {
                        edificio->levelUp();
                        resources.setMoney(resources.getMoney() - edificio->getCostOfLevelUp());
                        resources.setVigas(resources.getVigas() - 1);
                    } else {
                        cout << "Not enough resources to purchase this upgrade." << endl;
                    }
                } else if (edificio->getType() == "minaFerro") {
                    if (resources.getMoney() >= edificio->getCostOfLevelUp() && resources.getVigas() >= 1) {
                        edificio->levelUp();
                        resources.setMoney(resources.getMoney() - edificio->getCostOfLevelUp());
                        resources.setVigas(resources.getVigas() - 1);
                    } else {
                        cout << "Not enough resources to purchase this upgrade." << endl;
                    }
                }

            }
        }
    }
    if (foundOne == 0) {
        cout << "Didn't find any building by that name." << endl;
    }
}

void Island::moveID(std::string id) {
    bool foundWorker = false;
    for (auto & trabalhador : worker.trabalhadores) {
        if (trabalhador->getWorkerId() == id) {
            foundWorker = true;
            trabalhador->moveWorker();
        }
    }
    if (!foundWorker) {
        cout << "Couldn't find a worker with the id: " << id << endl;
    }
}

void Island::transform(std::string type, int amount) {
    if (type == "madeira") {
        if (resources.getWood() >= amount) {
            resources.setWood(resources.getWood() - amount);
            resources.setCoal(resources.getCoal() + amount);
            cout << "Transformation was successful! You now have " << resources.getCoal() << " coal." << endl;
        } else {
            cout << "You don't own that much wood to transform." << endl;
        }
    } else {
        cout << type << " is not a valid type to transform." << endl;
    }
}

bool Island::checkIfOnForest(int x, int y) {
    for (auto & zonaNatural : zone.zonasNaturais) {
        if (zonaNatural->getCoordinateX() == x && zonaNatural->getCoordinateY() == y) {
            if (zonaNatural->getType() == "floresta") {
                return true;
            }
        }
    }
    cout << "You must build it on a forest!" << endl;
    return false;
}

std::string Island::findTypeOfNaturalZone(int x, int y) {
    for (auto & zonaNatural : zone.zonasNaturais) {
        if (zonaNatural->getCoordinateX() == x && zonaNatural->getCoordinateY() == y) {
            return zonaNatural->getType();
        }
    }
    return "Couldn't find any natural zone at that location.";
}

void Island::killTreeFromForestAtCoords(int x, int y) {
    for (auto & zonaNatural : zone.zonasNaturais) {
        if (zonaNatural->getCoordinateX() == x && zonaNatural->getCoordinateY() == y) {
            if (zonaNatural->getType() == "floresta") {
                if (zonaNatural->getTreeCount() > 0) {
                    zonaNatural->killTree();
                } else {
                    cout << "There's not enough trees!" << endl;
                }
            } else {
                cout << "That's not a forest!" << endl;
            }
        }
    }
}

bool Island::checkIfBuildingExistsAtLocation(int x, int y) {
    for (auto & edificio : building.edificios) {
        if (edificio->getCoordinateX() == x && edificio->getCoordinateY() == y) {
            cout << "Can't overwrite at that location!" << endl;
            return true;
        }
    }
    return false;
}
