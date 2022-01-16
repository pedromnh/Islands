//
// Created by Pedro Henriques on 22/11/2021.
//

#include "Interface.h"

void Interface::firstMessage() {
    cout << "Starting the game..." << endl;
}


int Interface::getCurrentPhase() const {
    return currentPhase;
}

void Interface::setMorning() {
    day++;
    currentPhase = 1;
}

void Interface::setAfternoon() {
    currentPhase = 2;
}

void Interface::setNight() {
    currentPhase = 3;
}

void Interface::endGame() {
    currentPhase = 0;
}

void Interface::morningMessage() const {
    cout << "Morning phase of day #" << day << endl;
}

void Interface::afternoonMessage() const {
    cout << "Afternoon phase of day #" << day << endl;
}

void Interface::nightMessage() const {
    cout << "Night phase of day #" << day << endl <<
    "Collecting resources... " << endl;
}

void Interface::load() {
    loaded = true;
}

bool Interface::chooseLoadOrStart() {
    string userInput;

    while (userInput != "new_game" && userInput != "load_game") {
        cout << "Insert one of the following commands..." <<  endl <<
        "New Game: new_game" << endl <<
        "Load game: load_game" << endl <<
        "Your input: ";
//        cin >> userInput;
        userInput = "new_game";
        cout << userInput << endl;

        if (userInput == "load_game") {
            loaded = true;
            load();
        }
    }
}

bool Interface::getLoadStatus() {
    return loaded;
}

int Interface::getDay() {
   return day;
}

void Interface::mainGame() {
    srand(time(NULL));
    Island island(getLoadStatus(), island.getLine(), island.getCols());

    firstMessage();
    setMorning();
    do {
        switch (getCurrentPhase()) {
            case 1: // Morning Phase
                spacePhasesOut();
                if (day != 1) {
                    startOfNextDayMsg();
                }
                morningMessage();
                island.morningEffects(getDay());
                setAfternoon();
                break;
            case 2: //Afternoon Phase
                spacePhasesOut();
                afternoonMessage();
                island.afternoonPhase(getDay());
                setNight();
                break;
            case 3: //Night Phase
                spacePhasesOut();
                nightMessage();
                island.collectResources(getDay());

                island.updateBuildingStatuses();
                if (getDay() == 31)
                    endGame();
                else {
                    setMorning();
                }
                break;
            case 0: //End of game
                endGame();
                break;
        }
    } while (getCurrentPhase() != 0);
    island.list();
}

void Interface::startOfNextDayMsg() const {
    cout << "<------ NEXT DAY ------>" << endl;
}

void Interface::spacePhasesOut() const {
    cout << "\n\n\n";
}

