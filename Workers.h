//
// Created by Pedro Henriques on 09/01/2022.
//

#ifndef ISLANDSCLION_WORKERS_H
#define ISLANDSCLION_WORKERS_H
#include <iostream>
#include <vector>

class Workers {
private:
    std::string workerId;
    std::string type;

    int daysSinceHired;
    int dayHired;

    int amountOfLenhadores;
    int amountOfMineiros;
    int amountOfOperarios;

    int chanceOfQuitting = 0;
    bool mayQuit = false;
    double costOfContract;

    int coordinateX;
    int coordinateY;
public:
    std::vector<Workers*> trabalhadores;
    virtual void enableChanceOfQuitting() { mayQuit = true; }
    void setId(int totalWorkerCount);

//    Incrementers
    void incrementLenhadores();
    void incrementOperarios();
    void incrementMineiros();
    virtual void incrementDaysSinceHired() { daysSinceHired++; }

//    Decrementers
    void decrementLenhadores();
    void decrementOperarios();
    void decrementMineiros();

//    Getters
    int getTotalWorkerCount() const;
    int getAmountOfOperarios() const;
    int getAmountOfMineiros() const;
    int getAmountOfLenhadores() const;
    std::string getWorkerId() const;
    virtual int getCoordinateX() const {return coordinateX;}
    virtual int getCoordinateY() const {return coordinateY;}
    virtual std::string getType() const {return  type;}
    int getCostOfContract() const;


//    Setters
    int setCoordinateX(int x) {return coordinateX = x;}
    int setCoordinateY(int y) {return coordinateY = y;}
    void setType(std::string tipo);
    void setDayHired(int day);
    void setCostOfContract(double custo);

    void moveWorker();
    virtual bool isValidMoveLocation();
};


#endif //ISLANDSCLION_WORKERS_H
