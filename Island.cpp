//
// Created by Pedro Henriques on 22/11/2021.
//

#include <fstream>
#include "Island.h"

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
    if (island.at(line - 1).at(col - 1).find("mnF") != string::npos || island.at(line - 1).at(col - 1).find("mnC") != string::npos || island.at(line - 1).at(col - 1).find("elec") != string::npos || island.at(line - 1).at(col - 1).find("bat") != string::npos || island.at(line - 1).at(col - 1).find("fun") != string::npos) {
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
    for (int i = 1; i <= lines; i++) {
        for (int j = 1; j <= cols; j++) {
            randomizer = rand()% 6 + 0;
            switch (randomizer) {
                case 0:
                    cons((new Montanha(numOfMnt))->getName(), i, j);
                    numOfMnt++;
                    break;
                case 1:
                    cons((new Deserto(numOfDsr))->getName(), i, j);
                    numOfDsr++;
                    break;
                case 2:
                    cons((new Pastagem(numOfPas))->getName(), i, j);
                    numOfPas++;
                    break;
                case 3:
                    cons((new Floresta(numOfFlr))->getName(), i, j);
                    numOfFlr++;
                    break;
                case 4:
                    cons((new Pantano(numOfPnt))->getName(), i, j);
                    numOfPnt++;
                    break;
                case 5:
                    cons((new ZonaX(numOfZnZ))->getName(), i, j);
                    numOfZnZ++;
                    break;
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
                cons((new MinaFerro(numOfMnF))->getName(), line, col);
            } else if (type == "mnC") {
                cons((new MinaCarvao(numOfMnC))->getName(), line, col);
            } else if (type == "elec") {
                cons((new CentralEletrica(numOfElec))->getName(), line, col);
            } else if (type == "bat") {
                cons((new Bateria(numOfBat))->getName(), line, col);
            } else if (type == "fun") {
                cons((new Fundicao(numOfFun))->getName(), line, col);
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
                        cons((new MinaFerro(numOfMnF))->getName(), linePosition, colPosition);
                    } else if (type == "mnC") {
                        cons((new MinaCarvao(numOfMnC))->getName(), linePosition, colPosition);
                    } else if (type == "elec") {
                        cons((new CentralEletrica(numOfElec))->getName(), linePosition, colPosition);
                    } else if (type == "bat") {
                        cons((new Bateria(numOfBat))->getName(), linePosition, colPosition);
                    } else if (type == "fun") {
                        cons((new Fundicao(numOfFun))->getName(), linePosition, colPosition);
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


#include "Island.h"