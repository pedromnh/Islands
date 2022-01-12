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
    || island.at(line - 1).at(col - 1).find("fun") != string::npos) {
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
        }
    }
}


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
    cout << "[PLACEHOLDER]: move" << endl;
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
    cout << "[PLACEHOLDER]: next" << endl;
}

void Island::save(string saveName) {
    //island.at(line - 1).at(col - 1);
    cout << "[PLACEHOLDER]: save" << endl;
}

void Island::morningEffects(int day) {
    cout << "[PLACEHOLDER]: Random zone events" << endl;
    printTree(day);
}

void Island::randomizeNaturalZones() {
    int randomizer;
    for (int y = 1; y <= lines; y++) {
        for (int x = 1; x <= cols; x++) {
            randomizer = rand()% 6 + 0;
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
                    cout << "How did you get here?";
            }

        }
    }
}

void Island::afternoonPhase(int day) {
    string cmd, type;
    int line, col;

    do {
        roundOver = false;
        cout << "Insert a command: " << endl;
        cin >> cmd;
        if (cmd == "cons") {
            cin >> type >> line >> col;
            if (type == "mnF") {
                building.edificios.emplace_back(new MinaFerro(building.getAmountOfMnF(), line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                     );
            } else if (type == "mnC") {
                building.edificios.emplace_back(new MinaCarvao(building.getAmountOfMnC(), line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                     );
            } else if (type == "elec") {
                building.edificios.emplace_back(new CentralEletrica(building.getAmountOfElec(), line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                );
            } else if (type == "bat") {
                building.edificios.emplace_back(new Bateria(building.getAmountOfBat(), line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                );
            } else if (type == "fun") {
                building.edificios.emplace_back(new Fundicao(building.getAmountOfFun(), line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                );
            }
        } else if (cmd == "cont") {
            cin >> type;
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
            roundOver = true;
        } else if (cmd == "list") {
            list();
        } else if (cmd == "liga") {
            liga(line, col);
        } else if (cmd == "des") {
            des(line, col);
        } else if (cmd == "move") {
            move(1, line, col);
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
        } else if (cmd == "printAtCoordinates") {
            cin >> line >> col;
            printAtCoordinates(line, col);
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
                        building.edificios.emplace_back(new MinaFerro(building.getAmountOfMnF(), linePosition, colPosition));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "mnC") {
                        building.edificios.emplace_back(new MinaCarvao(building.getAmountOfMnC(), linePosition, colPosition));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "elec") {
                        building.edificios.emplace_back(new CentralEletrica(building.getAmountOfElec(), linePosition, colPosition));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "bat") {
                        building.edificios.emplace_back(new Bateria(building.getAmountOfBat(), linePosition, colPosition));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "fun") {
                        building.edificios.emplace_back(new Fundicao(building.getAmountOfFun(), linePosition, colPosition));
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
                } else if (cmd == "move") {
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

void Island::collectResources() {
    collectNaturalResources();
//    collectBuildingResources();
}

void Island::collectNaturalResources() {
    int naturalX, naturalY, workerX, workerY;
    for (int i = 0; i < zone.zonasNaturais.size(); ++i) {
        if (zone.zonasNaturais.at(i)->getType() == "floresta") {
            naturalY = zone.zonasNaturais.at(i)->getCoordinateX();
            naturalX = zone.zonasNaturais.at(i)->getCoordinateY();


            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "lenhador") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }
                if (naturalX == workerX && naturalY == workerY) {
//                    cout << "I currently have " << resources.getWood() << endl;
                    resources.acquireWood(1, 1);
//                    cout << "I'm rich! I now have " << resources.getWood() << " wood!" << endl;
                }
            }
        }
    }
}

void Island::collectBuildingResources() {
    int naturalX, naturalY, buildingX, buildingY;
    for (int i = 0; i < zone.zonasNaturais.size(); ++i) {
        if (zone.zonasNaturais.at(i)->getType() == "deserto") {
            naturalX = zone.zonasNaturais.at(i)->getCoordinateX();
            naturalY = zone.zonasNaturais.at(i)->getCoordinateY();
            if (building.edificios.at(i)->getType() == "deserto") {
                naturalX = zone.zonasNaturais.at(i)->getCoordinateX();
                naturalY = zone.zonasNaturais.at(i)->getCoordinateY();
            }
        }
        cout << zone.zonasNaturais.at(i)->getName() << endl;
    }
}

void Island::printTree(int day) {
    for (int i = 0; i < zone.zonasNaturais.size(); ++i) {
        if (zone.zonasNaturais.at(i)->getType() == "floresta") {
            cout << zone.zonasNaturais.at(i)->getName() <<
            " has " <<
            zone.zonasNaturais.at(i)->getTreeCount() <<
            " trees." << endl;
            zone.zonasNaturais.at(i)->growTree(day);
        }
    }
}

void Island::listBuildings() {
    cout << "There are " << building.edificios.size() << " buildings." << endl;
    for (auto & edificio : building.edificios) {
        cout << edificio->getName()<< ": "
             << "x="
             << edificio->getCoordinateX()
             << " ; y="
             << edificio->getCoordinateY() << endl;
    }
}

void Island::listWorkers() {
    cout << "There are " << worker.trabalhadores.size() << " workers." << endl;
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
            cout << edificio->getName() << endl;
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


#include "Island.h"