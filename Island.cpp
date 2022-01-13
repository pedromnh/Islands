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
    if (day % 2 == 0) {
//        printTree(day);
    }
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
    int line, col, amount;

    do {
        roundOver = false;
        cout << "Insert a command: " << endl;
        cin >> cmd;
        if (cmd == "cons") {
            cin >> type >> line >> col;
            if (type == "mnF") {
                if (resources.getVigas() >= 10) {
                    building.edificios.emplace_back(new MinaFerro(building.getAmountOfMnF(), line, col));
                    cons(building.edificios.back()->getName(),
                         building.edificios.back()->getCoordinateY(),
                         building.edificios.back()->getCoordinateX()
                    );
                    resources.setVigas(resources.getVigas() - 10);
                }
            } else if (type == "mnC") {
                if (resources.getVigas() >= 10) {
                    building.edificios.emplace_back(new MinaCarvao(building.getAmountOfMnC(), line, col));
                    cons(building.edificios.back()->getName(),
                         building.edificios.back()->getCoordinateY(),
                         building.edificios.back()->getCoordinateX()
                    );
                    resources.setVigas(resources.getVigas() - 10);
                }
            } else if (type == "elec") {
                if (resources.getMoney() >= 15) {
                    building.edificios.emplace_back(new CentralEletrica(building.getAmountOfElec(), line, col));
                    cons(building.edificios.back()->getName(),
                         building.edificios.back()->getCoordinateY(),
                         building.edificios.back()->getCoordinateX()
                    );
                    resources.setMoney(resources.getMoney() - 15);
                }
            } else if (type == "bat") {
                if (resources.getMoney() >= 10 && resources.getVigas() >= 10) {
                    building.edificios.emplace_back(new Bateria(building.getAmountOfBat(), line, col));
                    cons(building.edificios.back()->getName(),
                         building.edificios.back()->getCoordinateY(),
                         building.edificios.back()->getCoordinateX()
                    );
                    resources.setMoney(resources.getMoney() - 10);
                    resources.setVigas(resources.getVigas() - 10);
                }
            } else if (type == "fun") {
                if (resources.getMoney() >= 10) {
                    building.edificios.emplace_back(new Fundicao(building.getAmountOfFun(), line, col));
                    cons(building.edificios.back()->getName(),
                         building.edificios.back()->getCoordinateY(),
                         building.edificios.back()->getCoordinateX()
                    );
                    resources.setMoney(resources.getMoney() - 10);
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
    collectBuildingResources();
}

void Island::collectNaturalResources() {
    int naturalX, naturalY, workerX, workerY;
    for (int i = 0; i < zone.zonasNaturais.size(); ++i) {
        if (zone.zonasNaturais.at(i)->getType() == "floresta") {
            naturalX = zone.zonasNaturais.at(i)->getCoordinateX();
            naturalY = zone.zonasNaturais.at(i)->getCoordinateY();


            for (int j = 0; j < worker.trabalhadores.size(); ++j) {
                if (worker.trabalhadores.at(j)->getType() == "lenhador") {
                    workerX = worker.trabalhadores.at(j)->getCoordinateX();
                    workerY = worker.trabalhadores.at(j)->getCoordinateY();
                }
                if (naturalX == workerX && naturalY == workerY) {
                    resources.acquireWood(1, 1);
                }
            }
        }
    }
}

void Island::collectBuildingResources() {
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
                if (buildingX == workerX && buildingY == workerY && status == "Enabled") {
                    resources.acquireCoal(1, 1);
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
                if (buildingX == workerX && buildingY == workerY && status == "Enabled") {
                    resources.acquireIron(1, 1);
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
            "buy <type> <amount>\n"<< endl;
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
                } else {
                    building.edificios.at(i)->setStatus("Disabled");
                }
            }
        }
    }
}

#include "Island.h"