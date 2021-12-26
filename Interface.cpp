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
    cout << "Night phase of day #" << day << endl;
}

void Interface::load() {
    loaded = true;
}

bool Interface::chooseLoadOrStart() {
    string userInput;

    while (userInput != "new_game" && userInput != "load_game") {
        cout << "Insert one of the following commands..." <<  endl << "New Game: new_game" << endl <<"Load game: load_game" << endl << "Your input: ";
        cin >> userInput;

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

