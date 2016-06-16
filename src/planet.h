#ifndef PLANET_H
#define PLANET_H

#include <QtCore>
#include <QtGui>

#include "unit.h"
#include "spaceship.h"

class Sector;
class Unit;
class SpaceShip;

enum
{

};
class Planet
{
public:
    Planet();
    Planet(QString, Sector*);
    QString getName() {return name;}
    QList<Unit*> getUnits() {return units;}
    QList<SpaceShip*> getSpaceShips() {return spaceShips;}
    int getResource() {return resource;}
    void save();
    void period();
    Sector* getSector() {return sector;}
    void breed(int);
    bool checkUnitName(QString);
private:
    QList<Unit*> units;
    QList<SpaceShip*> spaceShips;
    int resource;
    QString name;
    Sector* sector;
};

#endif // PLANET_H
