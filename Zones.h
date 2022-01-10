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

    int coordinateX;
    int coordinateY;
public:
    std::vector<Zones*> zonasNaturais;

//    Getters
    virtual std::string getName() {return name;}
    std::string getType();
    double getProductionMultipler();

    int getCoordinateX() const {return coordinateX;}
    int getCoordinateY() const {return coordinateY;}

//    Setters
    int setCoordinateX(int x) {return coordinateX = x;}
    int setCoordinateY(int y) {return coordinateY = y;}
    void setType(std::string tipo);
};


#endif //ISLANDSCLION_ZONES_H
