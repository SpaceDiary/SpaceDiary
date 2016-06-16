#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QtCore>
#include <QtGui>

#include "unit.h"

class SpaceSector;
class Planet;
class Unit;

class SpaceShip
{
public:
    SpaceShip();
    SpaceShip(QString, SpaceSector*);
    SpaceShip(QString, Planet*);
    QString getName() {return name;}
    QList<Unit*> getUnits() {return units;}
    int getLifeSupport() {return lifeSupport;}
    int getArmor() {return armor;}
    int getWeapon() {return weapon;}
    void save();
    void period();
    SpaceSector* getSpaceSector() {return spaceSector;}
    Planet* getPlanet() {return planet;}
    void breed(int);
    bool checkUnitName(QString);
private:
    QList<Unit*> units;
    int lifeSupport;
    int weapon;
    int armor;
    QString name;
    SpaceSector* spaceSector;
    Planet* planet;
public slots:

};

#endif // SPACESHIP_H
