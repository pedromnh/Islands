//
// Created by Pedro Henriques on 22/11/2021.
//

#ifndef ISLANDSCLION_RESOURCES_H
#define ISLANDSCLION_RESOURCES_H
#include "Island.h"
#include <iomanip>

class Resources {
private:
    std::string saveName;
    double money;
    double ferro;
    double barra;
    double carvao;
    double madeira;
    double vigas;
    double eletricidade;

    double maxFerro;
    double maxBarra;
    double maxCarvao;
    double maxMadeira;
    double maxVigas;
    double maxEletricidade;

public:
    Resources(const Resources &game, std::string save);
    Resources() {
        money = 100.0;
        madeira = 0.0;
        ferro = 55.0;
        barra = 55.0;
        carvao = 55.0;
        vigas = 55.0;
        eletricidade = 55.0;

        maxMadeira = 100.0;
        maxFerro = 0;
        maxBarra = 0;
        maxMadeira = 0;
        maxVigas = 0;
        maxEletricidade = 0;
    }


    double getWood();
    double getVigas();
    double getCoal();
    double getIron();
    double getBarra() const;
    double getEletricidade();
    double getMaxFerro() const;
    double getMaxBarra() const;
    double getMaxCarvao() const;
    double getMaxMadeira() const;
    double getMaxVigas() const;
    double getMaxEletricidade() const;
    virtual std::string getSaveName() {return saveName;}




    void acquireWood(double acquiredResource, double naturalMultiplier);
    void acquireIron(double acquiredResource, double naturalMultiplier, int level);
    void acquireBarra(double acquiredResource, double naturalMultiplier);
    void acquireCoal(double acquiredResource, double naturalMultiplier, int level);
    void acquireVigas(double acquiredResource, double naturalMultiplier);
    void acquireEletricidade(double acquiredResource, double naturalMultiplier);

    void chooseResourceToSell(std::string type, int amount);
    void sellWood();
    void sellIron();
    void sellCoal();
    void sellBarra();
    void sellViga();
    void sellEletricidade();

    void chooseResourceToBuy(std::string type, int amount);
    void buyViga();


    double getMoney();
    void setMoney(double euro);
    void setVigas(double viga);
    void setWood(double wood);
    void setIron(double iron);
    void setEletricidade(double electro);
    void setBarra(double steel);
    void setCoal(double coal);

    void setMaxWood(double wood);
    void setMaxIron(double iron);
    void setMaxVigas(double viga);
    void setMaxEletricidade(double electro);
    void setMaxBarra(double steel);
    void setMaxCoal(double coal);

    void debcash(double amount);


    void listResources();
};


#endif //ISLANDSCLION_RESOURCES_H
