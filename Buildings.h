//
// Created by Pedro Henriques on 08/01/2022.
//

#ifndef ISLANDSCLION_BUILDINGS_H
#define ISLANDSCLION_BUILDINGS_H
#include <iostream>
#include <vector>

class Buildings {
private:
    std::string name;
    std::string status; //Enabled, Disabled, Destroyed
    std::string userStatus = "Enabled";
    std::string requirement;
    std::string type;
    std::string saveName;

    double cost;
    double costOfLevelUp;
    double storage;
    int dayBuilt;
    int maxLevel = 5;
    int chanceOfBreaking;
    int level = 1;

    int numOfMnF = 0;
    int numOfMnC = 0;
    int numOfElec = 0;
    int numOfBat = 0;
    int numOfFun = 0;
    int numOfBuildingX = 0;

    int coordinateX;
    int coordinateY;
public:
    std::vector<Buildings*> edificios;

    Buildings() {}
    Buildings (const Buildings &game, std::string save);

    Buildings& operator=(const Buildings& element) {
        edificios.clear();
        for (auto & edificio : edificios) {
            for (auto & elemento : element.edificios) {
                if (this->coordinateX == elemento->coordinateX && this->coordinateY == elemento->coordinateY) {
                    std::cout << "Updating info" << std::endl;
                    edificio->setCost(elemento->cost);
                    edificio->setCostOfLevelUp(elemento->costOfLevelUp);
                    edificio->setMaxLevel(elemento->maxLevel);
                    edificio->setDayBuilt(elemento->dayBuilt);
                    edificio->setChanceOfBreaking(elemento->chanceOfBreaking);
                    edificio->setStatus(elemento->status);
                    edificio->setType(elemento->type);
                    edificio->setMaxStorage(elemento->storage);
                }
            }
        }
        return *this;
    }
    ~Buildings(){}

//    Buildings& operator= (const Buildings& Building);

//    Incrementers
    void incrementMnF();
    void incrementMnC();
    void incrementElec();
    void incrementBat();
    void incrementFun();
    void incrementBuildingX();

//    Decrementers
    void decrementMnF();
    void decrementMnC();
    void decrementElec();
    void decrementBat();
    void decrementFun();
    void decrementBuildingX();



//    Getters
    virtual std::string getName() {return name;}
    virtual std::string getStatus() {return status;}
    virtual std::string getUserStatus() {return userStatus;}
    virtual std::string getRequirement() {return requirement;}
    virtual std::string getType() {return type;}
    virtual std::string getSaveName() {return saveName;}

    int getTotalBuildingCount() const;
    int getLevel() const;
    int getAmountOfMnF() const;
    int getAmountOfMnC() const;
    int getAmountOfElec() const;
    int getAmountOfBat() const;
    int getAmountOfFun() const;
    int getAmountOfBuildingX() const;
    int getDayBuilt() const;

    double getCost() const {return cost;}
    double getCostOfLevelUp() const {return  costOfLevelUp;}
    double getStorage() const {return storage;}
    int getMaxLevel() const {return maxLevel;}
    int getChanceOfBreaking() const {return chanceOfBreaking;}

    int getCoordinateX() const {return coordinateX;}
    int getCoordinateY() const {return coordinateY;}


//    Setters
    void setCost(double custo) {cost = custo;}
    void setCostOfLevelUp(double custo) {costOfLevelUp = custo;}
    void setMaxStorage(double storageLimit) {storage = storageLimit;}
    void setChanceOfBreaking(int chance) {chanceOfBreaking = chance;}
    void setType(std::string tipo) {type = tipo;}
    void setStatus(std::string state) {status = state;}
    void setDayBuilt(int currentDay) {dayBuilt = currentDay;}
    void setMaxLevel(int nivel);
    void levelUp();

    int setCoordinateX(int x) {return coordinateX = x;}
    int setCoordinateY(int y) {return coordinateY = y;}
    void setSaveName(std::string save) {saveName = save;}


    void disableUserStatus() {userStatus = "Disabled";}
    void enableUserStatus() {userStatus = "Enabled";}
};


#endif //ISLANDSCLION_BUILDINGS_H
