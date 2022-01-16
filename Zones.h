//
// Created by Pedro Henriques on 05/01/2022.
//

#ifndef ISLANDSCLION_ZONES_H
#define ISLANDSCLION_ZONES_H
#include <iostream>
#include <vector>

class Zones {
private:
    std::string name;
    std::string type;
    double productionMultiplier = 1;

    int numOfMnt = 0;
    int numOfDsr = 0;
    int numOfPas = 0;
    int numOfFlr = 0;
    int numOfPnt = 0;
    int numOfZnZ = 0;

    int coordinateX;
    int coordinateY;
public:
    std::vector<Zones*> zonasNaturais;


    //    Incrementers
    void incrementMnt();
    void incrementDsr();
    void incrementPas();
    void incrementFlr();
    void incrementPnt();
    void incrementZnZ();

//    Decrementers
    void decrementMnt();
    void decrementDsr();
    void decrementPas();
    void decrementFlr();
    void decrementPnt();
    void decrementZnZ();

//    Getters
    virtual std::string getName() {return name;}
    std::string getType();
    double getProductionMultipler();

    int getCoordinateX() const {return coordinateX;}
    int getCoordinateY() const {return coordinateY;}
    int getAmountOfMnt() const;
    int getAmountOfDsr() const;
    int getAmountOfPas() const;
    int getAmountOfFlr() const;
    int getAmountOfPnt() const;
    int getAmountOfZnZ() const;

//    Setters
    int setCoordinateX(int x) {return coordinateX = x;}
    int setCoordinateY(int y) {return coordinateY = y;}
    void setType(std::string tipo);




//    Forest Functions
    int treeCount;
    virtual int getTreeCount();
    virtual int growTree(int day);
    virtual void killTree();
};


#endif //ISLANDSCLION_ZONES_H
