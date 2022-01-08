//
// Created by Pedro Henriques on 22/11/2021.
//

#include <fstream>
#include "Island.h"

Zones zone;
Buildings building;

void Island::list() {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            cout << island[i][j] << "\t\t";
        }
        cout << endl << endl << endl << endl;
    }
    cout << "Total de trabalhadores: " << numOfLenhadores + numOfOperarios + numOfMineiros << endl <<
    "Numero de lenhadores: " << numOfLenhadores << endl <<
    "Numero de mineiros: " << numOfMineiros << endl <<
    "Numero de operarios: " << numOfOperarios << endl;
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
            numOfMnF++;
            roundOver = true;
        } else if (type.find("mnC") != string::npos) {
            numOfMnC++;
            roundOver = true;
        } else if (type.find("elec") != string::npos) {
            numOfElec++;
            roundOver = true;
        } else if (type.find("bat") != string::npos) {
            numOfBat++;
            roundOver = true;
        } else if (type.find("fun") != string::npos) {
            numOfFun++;
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
        numOfLenhadores++;
        roundOver = true;
    } else if (type.find("operario") != string::npos) {
        numOfOperarios++;
        roundOver = true;
    } else if (type.find("mineiro") != string::npos) {
        numOfMineiros++;
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

void Island::morningEffects() {
    cout << "[PLACEHOLDER]: Random zone events" << endl;
}

void Island::randomizeNaturalZones() {
    int randomizer;
    for (int y = 1; y <= lines; y++) {
        for (int x = 1; x <= cols; x++) {
            randomizer = rand()% 6 + 0;
            switch (randomizer) {
                case 0:
                    zone.zonasNaturais.emplace_back(new Montanha(numOfMnt, x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    numOfMnt++;
                    updateNaturalZoneCount();
                    break;
                case 1:
                    zone.zonasNaturais.emplace_back(new Deserto(numOfDsr, x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    numOfDsr++;
                    updateNaturalZoneCount();
                    break;
                case 2:
                    zone.zonasNaturais.emplace_back(new Pastagem(numOfPas, x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    numOfPas++;
                    updateNaturalZoneCount();
                    break;
                case 3:
                    zone.zonasNaturais.emplace_back(new Floresta(numOfFlr, x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    numOfFlr++;
                    updateNaturalZoneCount();
                    break;
                case 4:
                    zone.zonasNaturais.emplace_back(new Pantano(numOfPnt, x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    numOfPnt++;
                    updateNaturalZoneCount();
                    break;
                case 5:
                    zone.zonasNaturais.emplace_back(new ZonaX(numOfZnZ, x, y));
                    cons(zone.zonasNaturais.back()->getName(),
                         zone.zonasNaturais.back()->getCoordinateY(),
                         zone.zonasNaturais.back()->getCoordinateX()
                         );
                    numOfZnZ++;
                    updateNaturalZoneCount();
                    break;
                default:
                    cout << "How did you get here?";
            }

        }
    }
}

void Island::afternoonPhase() {
    string cmd, type;
    int line, col;

    do {
        roundOver = false;
        cout << "Insert a command: " << endl;
        cin >> cmd;
        if (cmd == "cons") {
            cin >> type >> line >> col;
            if (type == "mnF") {
                building.edificios.emplace_back(new MinaFerro(numOfMnF, line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                     );
            } else if (type == "mnC") {
                building.edificios.emplace_back(new MinaCarvao(numOfMnC, line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                     );
            } else if (type == "elec") {
                building.edificios.emplace_back(new CentralEletrica(numOfElec, line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                );
            } else if (type == "bat") {
                building.edificios.emplace_back(new Bateria(numOfBat, line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                );
            } else if (type == "fun") {
                building.edificios.emplace_back(new Fundicao(numOfFun, line, col));
                cons(building.edificios.back()->getName(),
                     building.edificios.back()->getCoordinateY(),
                     building.edificios.back()->getCoordinateX()
                );
            }
        } else if (cmd == "cont") {
            cin >> type;
            if (type == "lenhador") {
                cont((new Lenhador(numOfLenhadores))->getName());
            } else if (type == "mineiro") {
                cont((new Mineiro(numOfMineiros))->getName());
            } else if (type == "operario") {
                cont((new Operario(numOfOperarios))->getName());
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

void Island::loading() {
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
                        building.edificios.emplace_back(new MinaFerro(numOfMnF, linePosition, colPosition));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "mnC") {
                        building.edificios.emplace_back(new MinaCarvao(numOfMnC, linePosition, colPosition));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "elec") {
                        building.edificios.emplace_back(new CentralEletrica(numOfElec, linePosition, colPosition));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "bat") {
                        building.edificios.emplace_back(new Bateria(numOfBat, linePosition, colPosition));
                        cons(building.edificios.back()->getName(),
                             building.edificios.back()->getCoordinateY(),
                             building.edificios.back()->getCoordinateX()
                        );
                    } else if (type == "fun") {
                        building.edificios.emplace_back(new Fundicao(numOfFun, linePosition, colPosition));
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
                        cont((new Lenhador(numOfLenhadores))->getName());
                    } else if (type == "mineiro") {
                        cont((new Mineiro(numOfMineiros))->getName());
                    } else if (type == "operario") {
                        cont((new Operario(numOfOperarios))->getName());
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
    for (int i = 0; i < zone.zonasNaturais.size(); ++i) {
        cout << zone.zonasNaturais.at(i)->getName() << endl;
    }
    cout << "There are " << zone.zonasNaturais.size() << " natural zones." << endl;
}

void Island::updateNaturalZoneCount() {
    numOfNaturalZones = numOfMnt + numOfDsr + numOfPas + numOfFlr + numOfPnt+ numOfZnZ;
}


#include "Island.h"