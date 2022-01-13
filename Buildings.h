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

    double cost;
    double costOfLevelUp;
    double storage;
    int maxLevel;
    int chanceOfBreaking;

    int numOfMnF = 0;
    int numOfMnC = 0;
    int numOfElec = 0;
    int numOfBat = 0;
    int numOfFun = 0;

    int coordinateX;
    int coordinateY;
public:
    std::vector<Buildings*> edificios;

//    Incrementers
    void incrementMnF();
    void incrementMnC();
    void incrementElec();
    void incrementBat();
    void incrementFun();

//    Decrementers
    void decrementMnF();
    void decrementMnC();
    void decrementElec();
    void decrementBat();
    void decrementFun();



//    Getters
    virtual std::string getName() {return name;}
    virtual std::string getStatus() {return status;}
    virtual std::string getUserStatus() {return userStatus;}
    virtual std::string getRequirement() {return requirement;}
    virtual std::string getType() {return type;}

    int getTotalBuildingCount() const;
    int getAmountOfMnF() const;
    int getAmountOfMnC() const;
    int getAmountOfElec() const;
    int getAmountOfBat() const;
    int getAmountOfFun() const;

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
    void setMaxLevel(int levelCap) {maxLevel = levelCap;}
    void setChanceOfBreaking(int chance) {chanceOfBreaking = chance;}
    void setType(std::string tipo) {type = tipo;}
    void setStatus(std::string state) {status = state;}

    int setCoordinateX(int x) {return coordinateX = x;}
    int setCoordinateY(int y) {return coordinateY = y;}


    void disableUserStatus() {userStatus = "Disabled";}
    void enableUserStatus() {userStatus = "Enabled";}
};


#endif //ISLANDSCLION_BUILDINGS_H
